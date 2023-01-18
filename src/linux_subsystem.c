/*
 * By RA4ASN
 */

#include "hardware.h"	/* зависящие от процессора функции работы с портами */
#include "formats.h"	// for debug prints
#include "audio.h"

#if LINUX_SUBSYSTEM

#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>
#include <sys/time.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <linux/gpio.h>

void * get_highmem_ptr (uint32_t addr, uint8_t size)
{
	int fd;
	if((fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0)
	{
		printf("open /dev/mem failure\n");
		return NULL;
	}

	void *map_base, *virt_addr;
	unsigned page_size, mapped_size, offset_in_page;
	mapped_size = page_size = 4096 * size;
	offset_in_page = (unsigned)addr & (page_size - 1);

	map_base = (unsigned*) mmap(0, mapped_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, addr & ~(off_t)(page_size - 1));
	close(fd);

	if (map_base == NULL)
	{
		printf("mmap %x failure\n", addr);
		return NULL;
	}

	virt_addr = (char*) map_base + offset_in_page;
	return virt_addr;
}

void process_linux_timer_spool(void)
{
	while(1)
	{
		spool_systimerbundle1();
		spool_systimerbundle2();
		usleep(5000);
	}
}

void linux_encoder_spool(void)
{
	while(1)
	{
		spool_encinterrupt();
		usleep(100);
	}
}

/************************ Framebuffer *****************************/

static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;
volatile uint32_t * fbp = 0;
static uint32_t screensize = 0;

uint32_t * linux_get_fb(uint32_t * size)
{
	* size = screensize;
	return (uint32_t *)fbp;
}

uint32_t * fbmem_at(uint_fast16_t x, uint_fast16_t y)
{
	uint32_t location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 32) +
	                   (y + vinfo.yoffset) * finfo.line_length / 4;
	return (uint32_t *) (fbp + location);
}

int linux_framebuffer_init(void)
{
	int fbfd, ttyd;

	// Open the file for reading and writing
	fbfd = open("/dev/fb0", O_RDWR);
	if (fbfd == -1) {
		PRINTF("Error: cannot open framebuffer device");
		exit(1);
	}

	ttyd = open("/dev/tty0", O_RDWR);
	if (ttyd)
		ioctl(ttyd, KDSETMODE, KD_GRAPHICS);
	else
	{
		PRINTF("Error: cannot open tty device");
		exit(1);
	}

	// Get fixed screen information
	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
		PRINTF("Error reading fixed information");
		exit(2);
	}

	// Get variable screen information
	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
		PRINTF("Error reading variable information");
		exit(3);
	}

	// Figure out the size of the screen in bytes
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	// Map the device to memory
	fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	if (* fbp == -1) {
		PRINTF("Error: failed to map framebuffer device to memory");
		exit(4);
	}

	PRINTF("linux drm fb: %dx%d, %dbpp, %d bytes\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel, screensize);

	close(fbfd);
	close(ttyd);
	return 0;
}

void framebuffer_close(void)
{
	int ttyd = open("/dev/tty0", O_RDWR);
    ioctl(ttyd, KDSETMODE, KD_TEXT);
    munmap((uint32_t *) fbp, screensize);
    close(ttyd);
}

/********************** EMIO ************************/

volatile uint32_t * xgpo, * xgpi;

void linux_xgpio_init(void)
{
	xgpo = get_highmem_ptr(AXI_XGPO_ADDR, 1);
	xgpi = get_highmem_ptr(AXI_XGPI_ADDR, 1);
}

uint8_t linux_xgpi_read_pin(uint8_t pin)
{
	uint32_t v = * xgpi;
	return (v >> pin) & 1;
}

void linux_xgpo_write_pin(uint8_t pin, uint8_t val)
{
	uint32_t mask = 1 << pin;
	uint32_t rw = * xgpo;

	if (val)
		rw |= mask;
	else
		rw &= ~mask;

	* xgpo = rw;
}

void xc7z_writepin(uint8_t pin, uint8_t val)
{
	linux_xgpo_write_pin(pin, val);
}

uint_fast8_t xc7z_readpin(uint8_t pin)
{
	return linux_xgpi_read_pin(pin);
}

void gpio_writepin(uint8_t pin, uint8_t val)
{
	linux_xgpo_write_pin(pin, val);
}

uint_fast8_t gpio_readpin(uint8_t pin)
{
	return linux_xgpi_read_pin(pin);
}

void reg_write(uint32_t addr, uint32_t val)
{
	void * ptr = get_highmem_ptr(addr, 1);

	* (uint32_t *)(ptr) = val;

	//reg_read(addr);
	//printf("reg_write: 0x%08x, 0x%08x\n", addr, val);
}

uint32_t reg_read(uint32_t addr)
{
	void * ptr = get_highmem_ptr(addr, 1);

	uint32_t res = * (uint32_t *) ptr;

	printf("reg_read: 0x%08X, 0x%08X\n", addr, res);
	return res;
}

/************** SPI *********************/

#if WITHSPISW && WITHPS7BOARD_MYC_Y7Z020 // sv9 only
uint32_t * readreg, * writereg;
SPINLOCK_t lock_sclk, lock_miso, lock_mosi;

void linux_spi_init(void)
{
	uint32_t gpiobase = 0xE000A000;

	uint32_t * dirreg = get_highmem_ptr(gpiobase + 0x244);
	uint32_t * oenreg = get_highmem_ptr(gpiobase + 0x248);
	readreg = get_highmem_ptr(gpiobase + 0x64);
	writereg = get_highmem_ptr(gpiobase + 0x8);

	* oenreg |= ((1 << (SPI_MOSI_MIO - 32)) | (1 << (SPI_SCLK_MIO - 32)));
	* dirreg |= ((1 << (SPI_MOSI_MIO - 32)) | (1 << (SPI_SCLK_MIO - 32)));
	* dirreg &= ~(1 << (SPI_MISO_MIO - 32));

	SPINLOCK_INITIALIZE(& lock_sclk);
	SPINLOCK_INITIALIZE(& lock_miso);
	SPINLOCK_INITIALIZE(& lock_mosi);
}


void spi_sclk_set(void)
{
	* writereg |= (1 << (SPI_SCLK_MIO - 32));
}

void spi_sclk_clear(void)
{
	* writereg &= ~(1 << (SPI_SCLK_MIO - 32));
}

void spi_mosi_set(void)
{
	* writereg |= (1 << (SPI_MOSI_MIO - 32));
}

void spi_mosi_clear(void)
{
	* writereg &= ~(1 << (SPI_MOSI_MIO - 32));
}

uint8_t spi_miso_get(void)
{
	uint8_t r = (* readreg >> (SPI_MISO_MIO - 32)) & 1;
	return r;
}
#endif /* WITHSPISW */

/************* I2C ************************/
static int fd_i2c = 0;

void i2c_initialize(void)
{
	const char *path = "/dev/i2c-0";

	fd_i2c = open(path, O_RDWR);
	if (fd_i2c < 0)
		PRINTF("%s open failed: %d\n", path, fd_i2c);
	else
		PRINTF("linux i2c started\n");
}

uint16_t i2chw_write(uint16_t slave_address, uint8_t * buf, uint32_t size)
{
	int rc;

	if (fd_i2c)
	{
		if (ioctl(fd_i2c, I2C_SLAVE, slave_address >> 1) < 0)
			PRINTF("Failed to set slave\n");

		rc = write(fd_i2c, buf, size);
		if (rc < 0)
			PRINTF("Tried to write to address '0x%02x'\n", slave_address);
	}

	return rc;
}

uint16_t i2chw_read(uint16_t slave_address, uint8_t * buf, uint32_t size)
{
	int rc;

	if (fd_i2c)
	{
		rc = read(fd_i2c, buf, size);
		if (rc < 0)
			PRINTF("Tried to read from address '0x%02x'\n", slave_address);
	}

	return rc;
}

uint16_t linux_i2c_read(uint16_t slave_address, uint16_t reg, uint8_t * buf, const uint8_t size)
{
	int rc;

	uint8_t regbuf[2] = { (reg >> 8), (reg & 0xFF), };

	if (fd_i2c)
	{
		if (ioctl(fd_i2c, I2C_SLAVE, slave_address >> 1) < 0)
			PRINTF("Failed to set slave\n");

		rc = write(fd_i2c, regbuf, 2);
		if (rc < 0)
			PRINTF("Tried to write to address '0x%02x'\n", slave_address);


		rc = read(fd_i2c, buf, size);
		if (rc < 0)
			PRINTF("Tried to read from address '0x%02x'\n", slave_address);
	}

	return rc;
}

/*************************************************************/

volatile uint32_t *ftw, *ftw_sub, *rts, *modem_ctrl,  *ph_fifo, *iq_count_rx, *iq_count_tx, *iq_fifo_rx, *iq_fifo_tx;
int32_t sinbuf[DMABUFFSIZE16TX];
static uint8_t rx_shift = 0, tx_shift = 0, tx_state = 0;

void linux_iq_init(void)
{
	ftw = 			get_highmem_ptr(AXI_IQ_FTW_ADDR, 1);
	ftw_sub = 		get_highmem_ptr(AXI_IQ_FTW_SUB_ADDR, 1);
	rts = 			get_highmem_ptr(AXI_IQ_RTS_ADDR, 1);
	ph_fifo = 		get_highmem_ptr(AXI_FIFO_PHONES_ADDR, 1);
	iq_fifo_rx = 	get_highmem_ptr(AXI_IQ_FIFO_RX_ADDR, 1);
	iq_fifo_tx = 	get_highmem_ptr(AXI_IQ_FIFO_TX_ADDR, 1);
	modem_ctrl = 	get_highmem_ptr(AXI_MODEM_CTRL_ADDR, 1);
	iq_count_rx = 	get_highmem_ptr(AXI_IQ_RX_COUNT_ADDR, 1);
	iq_count_tx = 	get_highmem_ptr(AXI_IQ_TX_COUNT_ADDR, 1);


	reg_write(AXI_ADI_ADDR + AUDIO_REG_I2S_CLK_CTRL, (64 / 2 - 1) << 16 | (4 / 2 - 1));
	reg_write(AXI_ADI_ADDR + AUDIO_REG_I2S_PERIOD, DMABUFFSIZE16TX);
	reg_write(AXI_ADI_ADDR + AUDIO_REG_I2S_CTRL, TX_ENABLE_MASK);

	xcz_rx_iq_shift(44);
	xcz_tx_shift(25);
}

void linux_iq_thread(void)
{
	enum { CNT16TX = DMABUFFSIZE16TX / DMABUFFSTEP16TX };
	enum { CNT32RX = DMABUFFSIZE32RX / DMABUFFSTEP32RX };
	static int rx_stage = 0, qq = 0;

	if (* iq_count_rx >= DMABUFFSIZE32RX)
	{
		uintptr_t addr32rx = allocate_dmabuffer32rx();
		uint32_t * r = (uint32_t *) addr32rx;

		for (int i = 0; i < DMABUFFSIZE32RX; i ++)
			r[i] = * iq_fifo_rx;

		processing_dmabuffer32rx(addr32rx);
		processing_dmabuffer32rts(addr32rx);
		release_dmabuffer32rx(addr32rx);

		rx_stage += CNT32RX;

		while (rx_stage >= CNT16TX)
		{
			const uintptr_t addr2 = getfilled_dmabuffer16txphones();
			uint32_t * b = (uint32_t *) addr2;

			for (int i = 0; i < DMABUFFSIZE16TX; i ++)
				* ph_fifo = b[i];


			release_dmabuffer16tx(addr2);
			rx_stage -= CNT16TX;
		}
	}

	if (* iq_count_tx < DMABUFFSIZE32TX / 2)
	{
		uintptr_t addr_mic = allocate_dmabuffer16rx();
		// todo: fill buffer from mic FIFO
		processing_dmabuffer16rx(addr_mic);

		const uintptr_t addr = getfilled_dmabuffer32tx_main();
		uint32_t * r = (uint32_t *) addr;

		for (uint16_t i = 0; i < DMABUFFSIZE32TX / 2; i ++)				// 16 bit
			* iq_fifo_tx = r[i];

		release_dmabuffer32tx(addr);
	}
}

void linux_iq_interrupt_thread(void)
{
	uint32_t uio_key = 1;
	uint32_t uio_value = 0;

	int fd_int = open("/dev/uio0", O_RDWR);
    if (fd_int < 0) {
        PRINTF("/dev/uio0 open failed\n");
        return;
    }

    while(1)
    {
        //Acknowledge IRQ
        if (write(fd_int, &uio_key, sizeof(uio_key)) < 0) {
            PRINTF("Failed to acknowledge IRQ: %s\n", strerror(errno));
            return;
        }

        //Wait for next IRQ
        if (read(fd_int, &uio_value, sizeof(uio_value)) < 0) {
            PRINTF("Failed to wait for IRQ: %s\n", strerror(errno));
            return;
        }

        linux_iq_thread();
    }
}

/*************************************************************/

void linux_create_thread(void * process, int priority, int cpuid)
{
	pthread_attr_t attr;
	struct sched_param param;
	pthread_t thread;
	cpu_set_t mask;

	ASSERT(cpuid < sysconf(_SC_NPROCESSORS_ONLN));

	pthread_attr_init(& attr);
	pthread_attr_setinheritsched(& attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(& attr, SCHED_FIFO);
	param.sched_priority = priority;
	pthread_attr_setschedparam(& attr, & param);
	CPU_ZERO(& mask);
	CPU_SET(cpuid, & mask);
	pthread_attr_setaffinity_np(& attr, sizeof(mask), & mask);

    if(pthread_create(& thread, & attr, process, NULL) < 0)
    {
      perror("pthread_create");
    }

    pthread_detach(thread);
}

void linux_subsystem_init(void)
{
	linux_framebuffer_init();
	linux_xgpio_init();
	linux_iq_init();
}

void linux_user_init(void)
{
	linux_create_thread(process_linux_timer_spool, 50, 0);
	linux_create_thread(linux_encoder_spool, 50, 1);
	linux_create_thread(linux_iq_interrupt_thread, 90, 1);

	const float FS = powf(2, 32);
	uint32_t fan_pwm_period = 25000 * FS / 61440000;
	reg_write(0x80048000 + 0, fan_pwm_period);

	uint32_t fan_pwm_duty = FS * (1.0f - 0.7f) - 1;
	reg_write(0x80048000 + 4, fan_pwm_duty);
}

/****************************************************************/

pthread_mutex_t md = PTHREAD_MUTEX_INITIALIZER;

void spin_lock(spinlock_t * __restrict p, const char * file, int line)
{
	pthread_mutex_lock(p);
}

void spin_unlock(spinlock_t * __restrict p)
{
	pthread_mutex_unlock(p);
}


void system_disableIRQ(void)
{

}

void system_enableIRQ(void)
{

}

void xcz_rxtx_state(uint8_t tx)
{
	tx_state = tx != 0;

	uint32_t v = rx_shift | (tx_shift << 8) | (tx_state << 16);
	* modem_ctrl = v;
}

void xcz_dds_ftw(const uint_least64_t * val)
{
	uint32_t v = * val;
    * ftw = v;
}

void xcz_dds_rts(const uint_least64_t * val)
{
	uint32_t v = * val;
    * rts = v;
}

void xcz_rx_iq_shift(uint8_t val) // 52
{
	rx_shift = val & 0xFF;

	uint32_t v = rx_shift | (tx_shift << 8) | (tx_state << 16);
	* modem_ctrl = v;
}

void xcz_dds_ftw_sub(const uint_least64_t * val)
{

}

void xcz_rx_cic_shift(uint32_t val)
{

}

void xcz_tx_shift(uint32_t val)
{
	tx_shift = val & 0xFF;

	uint32_t v = rx_shift | (tx_shift << 8) | (tx_state << 16);
	* modem_ctrl = v;
}

#if WITHDSPEXTFIR
volatile uint32_t * fir_reload = NULL;
static adapter_t plfircoefsout;		/* параметры прербразования к PL */

void board_fpga_fir_initialize(void)
{
	adpt_initialize(& plfircoefsout, HARDWARE_COEFWIDTH, 0, "fpgafircoefsout");
	fir_reload = get_highmem_ptr(AXI_FIR_RELOAD_ADDR, 1);
}

void board_reload_fir(uint_fast8_t ifir, const int32_t * const k, const FLOAT_t * const kf, unsigned Ntap, unsigned CWidth)
{
	if (fir_reload)
	{
		const int iHalfLen = (Ntap - 1) / 2;
		int i = 0, m = 0, bits = 0;

		// int32_t coeff = adpt_output(& plfircoefsout, kf [i]);		/* вот так получать целочисленное значение требуемой разрядности */

		// Приведение разрядности значений коэффициентов к CWidth
		for (; i <= iHalfLen; ++ i)
			m = k[i] > m ? k[i] : m;

		while(m > 0)
		{
			m  = m >> 1;
			bits ++;
		}

		bits = CWidth - bits;

		for (i = 0; i <= iHalfLen; ++ i)
			* fir_reload = k[i] << bits;

		i -= 1;
		for (; -- i >= 0;)
			* fir_reload = k[i] << bits;
	}
}
#endif /* WITHDSPEXTFIR */

void board_rtc_getdate(
	uint_fast16_t * year,
	uint_fast8_t * month,
	uint_fast8_t * dayofmonth
	)
{
	struct tm * tm;

	time_t lt = time(NULL);
	tm = localtime (& lt);

	* dayofmonth = tm->tm_mday;
	* month = tm->tm_mon;
	* year = tm->tm_year;
}

void board_rtc_gettime(
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * secounds
	)
{
	struct tm * tm;

	time_t lt = time(NULL);
	tm = localtime (& lt);

	* secounds = tm->tm_sec;
	* minute = tm->tm_min;
	* hour = tm->tm_hour;
}

void board_rtc_getdatetime(
	uint_fast16_t * year,
	uint_fast8_t * month,	// 01-12
	uint_fast8_t * dayofmonth,
	uint_fast8_t * hour,
	uint_fast8_t * minute,
	uint_fast8_t * secounds
	)
{
	struct tm * tm;

	time_t lt = time(NULL);
	tm = localtime (& lt);

	* secounds = tm->tm_sec;
	* minute = tm->tm_min;
	* hour = tm->tm_hour;
	* dayofmonth = tm->tm_mday;
	* month = tm->tm_mon;
	* year = tm->tm_year;
}

void board_rtc_setdatetime(
	uint_fast16_t year,
	uint_fast8_t month,
	uint_fast8_t dayofmonth,
	uint_fast8_t hours,
	uint_fast8_t minutes,
	uint_fast8_t secounds
	)
{

}

uint_fast8_t board_rtc_chip_initialize(void)
{
	return 0;
}

uint_fast8_t dummy_putchar(uint_fast8_t c)
{
	printf("%c", c);
	return 1;
}

uint_fast8_t dummy_getchar(char * cp)
{
	* cp = 0;
	return 1;
}

void arm_hardware_set_handler_overrealtime(uint_fast16_t int_id, void (* handler)(void)) 	{}
void arm_hardware_set_handler_realtime(uint_fast16_t int_id, void (* handler)(void)) 		{}
void arm_hardware_set_handler_system(uint_fast16_t int_id, void (* handler)(void)) 			{}

#endif /* LINUX_SUBSYSTEM */
