/*
 * network.c
 *
 *  Created on: Dec 10, 2020
 *      Author: gena
 */

/* $Id$ */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//

#include "hardware.h"	/* зависящие от процессора функции работы с портами */
#include "formats.h"	/* зависящие от процессора функции работы с портами */

#if 0 //WITHLWIP
#include "sdcard.h"

#include <stdbool.h>
#include "lwip/opt.h"

#include "lwip/init.h"
#include "lwip/ip.h"
#include "lwip/udp.h"
#include "lwip/dhcp.h"
#include "netif/etharp.h"
#include "lwip/ip_addr.h"

#include "../lib/dhcp-server/dhserver.h"
#include "../lib/dns-server/dnserver.h"
#include "lwip/apps/httpd.h"

#define DHCP_SERVER 1
/*
 *  В конфигурации описано имя и размер
 *
 *  #define LWIP_RAM_HEAP_POINTER		lwipBuffer
 *  #define MEM_SIZE                        32768
 */

#if defined (LWIP_RAM_HEAP_POINTER)
	ALIGNX_BEGIN RAMFRAMEBUFF uint8_t LWIP_RAM_HEAP_POINTER [MEM_SIZE] ALIGNX_END;
#endif /* defined (LWIP_RAM_HEAP_POINTER) */


//#define TX_ZLP_TEST
static void init_lwip(void);
static void init_htserv(void);
static void init_dhserv(void);
static void init_dnserv(void);

#if DHCP_SERVER
static void init_dhserv(void)
{
	PRINTF("network_initialize: init_dhserv\n");
	static dhcp_entry_t dhcpentries [] =
	{
		{ {0}, {192, 168, 7, 2}, {255, 255, 255, 0}, 24 * 60 * 60 },
		{ {0}, {192, 168, 7, 3}, {255, 255, 255, 0}, 24 * 60 * 60 },
		{ {0}, {192, 168, 7, 4}, {255, 255, 255, 0}, 24 * 60 * 60 }
	};

	static dhcp_config_t dhcp_config =
	{
		{192, 168, 7, 1}, 67,
		{192, 168, 7, 1},
		"stm",
		ARRAY_SIZE(dhcpentries),
		dhcpentries
	};

	for (int i = 0; i < ARRAY_SIZE(dhcpentries); ++ i)
	{
		memcpy(dhcpentries [i].addr, myIP, 4);
		memcpy(dhcpentries [i].subnet, myNETMASK, 4);
		dhcpentries [i].addr [3] += i + 10;
	}
	memcpy(dhcp_config.addr, myIP, 4);
	memcpy(dhcp_config.dns, myIP, 4);
//	IP4_ADDR(& dhcp_config.addr, myIP [0], myIP [1], myIP [2], myIP [3] );
//	IP4_ADDR(& dhcp_config.dns, myIP [0], myIP [1], myIP [2], myIP [3]);

	while (dhserv_init(& dhcp_config) != ERR_OK)
		;
}
#endif /* DHCP_SERVER */


static bool dns_query_proc(const char *name, ip4_addr_t *addr)
{
  if (
		  strcmp(name, "run.stm") == 0 ||
		  strcmp(name, "www.run.stm") == 0
		  )
  {
	IP4_ADDR(addr, myIP [0], myIP [1], myIP [2], myIP [3]);
    return true;
  }
  return false;
}


#if 1
static void init_dnserv(void)
{
	ip4_addr_t ipaddr;
	IP4_ADDR(& ipaddr, myIP [0], myIP [1], myIP [2], myIP [3]);

	while (dnserv_init(& ipaddr, 53, dns_query_proc) != ERR_OK)
		;
}
#endif

static void init_lwip()
{
	//	PRINTF("init_lwip start\n");


	lwip_init();
	//stmr_add(&tcp_timer);
	//	PRINTF("init_lwip done\n");
}

#if LWIP_HTTPD_CGI


static uint8_t PORTC[8];

const char *state_cgi_handler(int index, int n_params, char *params[], char *values[])
{
  return "/state.shtml";
}

static const char *ssi_tags_table[] =
{
    "systick", /* 0 */
    "btn",     /* 1 */
    "acc",     /* 2 */
    "ledg",    /* 3 */
    "ledo",    /* 4 */
    "ledr"     /* 5 */
};


static int led_g = false;
static int led_o = false;
static int led_r = false;

const char *ctl_cgi_handler(int index, int n_params, char *params[], char *values[])
{
    int i;
    for (i = 0; i < n_params; i++)
    {
        if (strcmp(params[i], "g") == 0) led_g = *values[i] == '1';
        if (strcmp(params[i], "o") == 0) led_o = *values[i] == '1';
        if (strcmp(params[i], "r") == 0) led_r = *values[i] == '1';
    }


    return "/state.shtml";
}

static const tCGI cgi_uri_table[] =
{
    { "/state.cgi", state_cgi_handler },
    { "/ctl.cgi",   ctl_cgi_handler },
};



#ifdef TX_ZLP_TEST
static uint16_t ssi_handler(int index, char *insert, int ins_len)
{
  int res;
  static uint8_t i;
  static uint8_t c;

  if (ins_len < 32) return 0;

  if (c++ == 10)
  {
    i++;
    i &= 0x07;
    c = 0;
  }
  switch (index)
  {
  case 0: // systick
    res = local_snprintf_P(insert, ins_len, "%s", "1234");
    break;
  case 1: // PORTC
    {
      res = local_snprintf_P(insert, ins_len, "%u, %u, %u, %u, %u, %u, %u, %u", 10, 10, 10, 10, 10, 10, 10, 10);
      break;
    }
  case 2: // PA0
    *insert = '0' + (i == 0);
    res = 1;
    break;
  case 3: // PA1
    *insert = '0' + (i == 1);
    res = 1;
    break;
  case 4: // PA2
    *insert = '0' + (i == 2);
    res = 1;
    break;
  case 5: // PA3
    *insert = '0' + (i == 3);
    res = 1;
    break;
  case 6: // PA4
    *insert = '0' + (i == 4);
    res = 1;
    break;
  case 7: // PA5
    *insert = '0' + (i == 5);
    res = 1;
    break;
  case 8: // PA6
    *insert = '0' + (i == 6);
    res = 1;
    break;
  case 9: // PA7
    *insert = '0' + (i == 7);
    res = 1;
    break;
  }

  return res;
}
#else
static u16_t ssi_handler(int index, char *insert, int ins_len)
{
    int res = 0;

    if (ins_len < 32) return 0;
    static unsigned ttt;
    switch (index)
    {
    case 0: /* systick */
        res = local_snprintf_P(insert, ins_len, "%u", (unsigned)++ ttt);
        break;
    case 1: /* btn */
        res = local_snprintf_P(insert, ins_len, "%i", 1);
        break;
    case 2: /* acc */
    {
        int acc[3];
        acc[0] = 1;
        acc[1] = 2;
        acc[2] = 4;
        res = local_snprintf_P(insert, ins_len, "%i, %i, %i", acc[0], acc[1], acc[2]);
        break;
    }
    case 3: /* ledg */
        *insert = '0' + (1 & 1);
        res = 1;
        break;
    case 4: /* ledo */
        *insert = '0' + (1 & 1);
        res = 1;
        break;
    case 5: /* ledr */
        *insert = '0' + (1 & 1);
        res = 1;
        break;
    }

    return res;
}
#endif /* TX_ZLP_TEST */


void init_htserv(void)
{
  http_set_cgi_handlers(cgi_uri_table, sizeof(cgi_uri_table) / sizeof(tCGI));
  http_set_ssi_handler(ssi_handler, ssi_tags_table, sizeof(ssi_tags_table) / sizeof(char *));

  httpd_init();
}

#endif /* LWIP_HTTPD_CGI */


#if LWIP_HTTPD_SUPPORT_POST

static int writeok;
static unsigned bufoffset;
static ALIGNX_BEGIN RAMNOINIT_D1 uint8_t appbuff [4096uL * 1024] ALIGNX_END;


static const uint8_t * findpattern(const uint8_t * buff, unsigned size, const void * pbuff, unsigned psize)
{
	while (size >= psize)
	{
		if (memcmp(buff, pbuff, psize) == 0)
			return buff + psize;		// found
		++ buff;
		-- size;
		const uint8_t * p = memchr(buff, * (const uint8_t *) pbuff, size);
		if (p != NULL)
		{
			ptrdiff_t skip = p - buff;
			size -= skip;
			buff += skip;
		}
		else
		{
			break;
		}
	}
	return NULL;
}

/* These functions must be implemented by the application */

/** Called when a POST request has been received. The application can decide
 * whether to accept it or not.
 *
 * @param connection Unique connection identifier, valid until httpd_post_end
 *        is called.
 * @param uri The HTTP header URI receiving the POST request.
 * @param http_request The raw HTTP request (the first packet, normally).
 * @param http_request_len Size of 'http_request'.
 * @param content_len Content-Length from HTTP header.
 * @param response_uri Filename of response file, to be filled when denying the
 *        request
 * @param response_uri_len Size of the 'response_uri' buffer.
 * @param post_auto_wnd Set this to 0 to let the callback code handle window
 *        updates by calling 'httpd_post_data_recved' (to throttle rx speed)
 *        default is 1 (httpd handles window updates automatically)
 * @return ERR_OK: Accept the POST request, data may be passed in
 *         another err_t: Deny the POST request, send back 'bad request'.
 */
err_t httpd_post_begin(void *connection, const char *uri, const char *http_request,
                       u16_t http_request_len, int content_len, char *response_uri,
                       u16_t response_uri_len, u8_t *post_auto_wnd)
{
	PRINTF("httpd_post_begin, url='%s', content_len=%u\n", uri, content_len);
	//printhex(0, http_request, http_request_len);

	writeok = 1;
	bufoffset = 0;
	//local_snprintf_P(response_uri, response_uri_len, "/error.html");
	return ERR_OK;
}

/** Called for each pbuf of data that has been received for a POST.
 * ATTENTION: The application is responsible for freeing the pbufs passed in!
 *
 * @param connection Unique connection identifier.
 * @param p Received data.
 * @return ERR_OK: Data accepted.
 *         another err_t: Data denied, http_post_get_response_uri will be called.
 */
err_t httpd_post_receive_data(void *connection, struct pbuf *p)
{
	//PRINTF("httpd_post_receive_data\n");
	struct pbuf *q;
	for (q = p; q != NULL; q = q->next)
	{
		//PRINTF("httpd_post_receive_data: @%p len=%u\n", q->payload, q->len);
		//printhex(bufoffset, q->payload, q->len);
		size_t part = ulmin(sizeof appbuff - bufoffset, q->len);
		memcpy(appbuff + bufoffset, q->payload, part);
		bufoffset += q->len;
	}
	return ERR_OK;
}


struct stm32_header {
	uint32_t magic_number;
	uint8_t image_signature[64];
	uint32_t image_checksum;
	uint8_t  header_version[4];
	uint32_t image_length;
	uint32_t image_entry_point;
	uint32_t reserved1;
	uint32_t load_address;
	uint32_t reserved2;
	uint32_t version_number;
	uint32_t option_flags;
	uint32_t ecdsa_algorithm;
	uint8_t ecdsa_public_key[64];
	uint8_t padding[83];
	uint8_t binary_type;
} ATTRPACKED;

#define HEADER_MAGIC	0x324d5453  //	__be32_to_cpu(0x53544D32)

uint_fast8_t zbootloader_vfycks(
		const uint8_t * apparea,	/* ������� ����� ��� �������� ������ - ����� ����� ��������� ����� */
		const uint8_t * body	/* ������� ����� ��� �������� ������ - ����� ����� ��������� ����� */
		)
{
	const volatile struct stm32_header * const hdr = (const volatile struct stm32_header *) apparea;
	uint_fast32_t checksum = hdr->image_checksum;
	uint_fast32_t length = hdr->image_length;
	const uint8_t * p = (const uint8_t *) body; //hdr->load_address;
	if (hdr->magic_number != HEADER_MAGIC)
		return 1;
	while (length --)
		checksum -= * p ++;
	return checksum != 0;	// ������� 0 ���� ����������� ����� �������
}

/** Called when all data is received or when the connection is closed.
 * The application must return the filename/URI of a file to send in response
 * to this POST request. If the response_uri buffer is untouched, a 404
 * response is returned.
 *
 * @param connection Unique connection identifier.
 * @param response_uri Filename of response file, to be filled when denying the request
 * @param response_uri_len Size of the 'response_uri' buffer.
 */
void httpd_post_finished(void *connection, char *response_uri, u16_t response_uri_len)
{
	static uint8_t eofmarker [128];
	size_t eofmarkerlen = 0;
	unsigned startoffset = 0;
	unsigned endoffset = 0;

	PRINTF("httpd_post_finished, bufoffset=%u\n", bufoffset);

	if (writeok)
	{
		// ������ �����
		const uint8_t * eol = memchr(appbuff, 0x0D, bufoffset);
		if (eol != NULL)
		{
			size_t len = eol - appbuff;
			memcpy(eofmarker + 0, "\r\n", 2);
			memcpy(eofmarker + 2, appbuff, len);
			memcpy(eofmarker + len + 2, "--\r\n", 4);
			eofmarkerlen = len + 6;
		}
		else
		{
			writeok = 0;
		}
	}

	if (writeok)
	{
		const uint8_t * sob = findpattern(appbuff, bufoffset, "\r\n\r\n", 4);
		if (sob != NULL)
			startoffset = (sob - appbuff);
		else
			writeok = 0;

	}
	else
	{
		writeok = 0;
	}

	if (writeok)
	{
		const uint8_t * sob = findpattern(appbuff, bufoffset, eofmarker, eofmarkerlen);
		if (sob != NULL)
			endoffset = (sob - appbuff) - eofmarkerlen;
		else
			writeok = 0;

	}

	if (writeok)
	{
		writeok = ! zbootloader_vfycks(appbuff + startoffset, appbuff + startoffset + 256);
		if (writeok == 0)
		{
			PRINTF("image length=%u, wrong checksum\n", endoffset - startoffset);

		}
		else
		{
			PRINTF("image length=%u, right checksum\n", endoffset - startoffset);
		}
	}
#if 0
	if (writeok)
	{
		do
		{
			enum { SECTORSIZE = 512 };
			BYTE targetdrv = 0;
			DSTATUS st = disk_initialize (targetdrv);				/* Physical drive nmuber (0..) */
			//PRINTF(PSTR("disk_initialize code=%02X\n"), st);
			if (st != RES_OK)
			{
				PRINTF("BOOTLOADER: SD not ready\n");
				display_vtty_printf("BOOTLOADER: SD not ready\n");
				break;
			}
			display_vtty_printf("BOOTLOADER: size of image=%08lX\n", endoffset - startoffset);
			st = disk_write(targetdrv, appbuff + startoffset, SDCARDLOCATION, (endoffset - startoffset + SECTORSIZE - 1) / SECTORSIZE);
			if (st != RES_OK)
			{
				PRINTF("BOOTLOADER: Can not write image\n");
				display_vtty_printf("BOOTLOADER: Can not write image\n");
				writeok = 0;
			}
			else
			{
				PRINTF("BOOTLOADER: Done write image\n");

			}
		} while (0);

	}
#endif
	local_snprintf_P(response_uri, response_uri_len, writeok ? "/done.html" : "/error.html");
}

#ifndef LWIP_HTTPD_POST_MANUAL_WND
#define LWIP_HTTPD_POST_MANUAL_WND  0
#endif

#if LWIP_HTTPD_POST_MANUAL_WND
void httpd_post_data_recved(void *connection, u16_t recved_len);
#endif /* LWIP_HTTPD_POST_MANUAL_WND */

#endif /* LWIP_HTTPD_SUPPORT_POST */

#if SYS_LIGHTWEIGHT_PROT

#if (__CORTEX_M != 0)

sys_prot_t sys_arch_protect(void)
{
	const uint32_t primask =__get_PRIMASK();
	__disable_irq();
	return primask & 0x01;
}

void sys_arch_unprotect(sys_prot_t c)
{
	if (c)
	{
		__enable_irq();
	}
	else
	{
		__disable_irq();
	}
}

#elif (__CORTEX_A != 0)

// Taken from https://github.com/kslemb/ARM-K/blob/master/vic/isr.c


#define IRQ_MASK	0x00000080
#define FIQ_MASK	0x00000040
#define INT_MASK	(IRQ_MASK | FIQ_MASK)

unsigned Restore_INT (unsigned oldCPSR)
{
	unsigned cpsr;

	cpsr = __get_CPSR();
	__set_CPSR((cpsr & ~INT_MASK) | (oldCPSR & INT_MASK));
	return cpsr;
}

unsigned Disable_IRQ (void)
{
	unsigned cpsr;

	cpsr = __get_CPSR();
	__set_CPSR(cpsr | IRQ_MASK);
	return cpsr;
}

unsigned Restore_IRQ (unsigned oldCPSR)
{
	unsigned cpsr;

	cpsr = __get_CPSR();
	__set_CPSR((cpsr & ~ IRQ_MASK) | (oldCPSR & IRQ_MASK));
	return cpsr;
}

unsigned Enable_IRQ (void)
{
	unsigned cpsr;

	cpsr = __get_CPSR();
	__set_CPSR(cpsr & ~ IRQ_MASK);
	return cpsr;
}

sys_prot_t sys_arch_protect(void)
{

	return Disable_IRQ();
}

void sys_arch_unprotect(sys_prot_t pval)
{
	Restore_IRQ(pval);
}
#endif

#endif /* SYS_LIGHTWEIGHT_PROT */

void network_initialize(void)
{
	  init_lwip();
	  init_netif();

#if 1//WITHUSBHW && (WITHUSBRNDIS || WITHUSBCDCEEM || WITHUSBCDCECM)
	  PRINTF("network_initialize: start DHCP & DNS\n");
	#if DHCP_SERVER
		  init_dhserv();
	#endif /* DHCP_SERVER */
	  init_dnserv();
#endif /* WITHUSBHW && (WITHUSBRNDIS || WITHUSBCDCEEM || WITHUSBCDCECM) */

#if LWIP_HTTPD_CGI
	  PRINTF("network_initialize: start HTTP server\n");
	  init_htserv();
#endif /* LWIP_HTTPD_CGI */
	  //echo_init();

}

#else /*  WITHLWIP */

#include <stdbool.h>
#include "lwip/opt.h"

#include "lwip/init.h"
#include "lwip/ip.h"
#include "lwip/udp.h"
#include "lwip/dhcp.h"
#include "netif/etharp.h"
#include "lwip/ip_addr.h"
#include "lwip/err.h"
#include "lwip/tcp.h"

extern volatile int TcpFastTmrFlag;
extern volatile int TcpSlowTmrFlag;
extern volatile int dhcp_timoutcntr;
err_t dhcp_start(struct netif *netif);
static struct netif server_netif;
struct netif *echo_netif;
unsigned char mac_ethernet_address[] =
	{ 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

void
print_ip(char *msg, ip_addr_t *ip)
{
	PRINTF(msg);
	PRINTF("%d.%d.%d.%d\n\r", ip4_addr1(ip), ip4_addr2(ip),
			ip4_addr3(ip), ip4_addr4(ip));
}

err_t recv_callback(void *arg, struct tcp_pcb *tpcb,
                               struct pbuf *p, err_t err)
{
	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p) {
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		return ERR_OK;
	}

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->len);

	/* echo back the payload */
	/* in this case, we assume that the payload is < TCP_SND_BUF */
	if (tcp_sndbuf(tpcb) > p->len) {
		err = tcp_write(tpcb, p->payload, p->len, 1);
	} else
		PRINTF("no space in tcp_sndbuf\n\r");

	/* free the received pbuf */
	pbuf_free(p);

	return ERR_OK;
}

err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
	static int connection = 1;

	/* set the receive callback for this connection */
	tcp_recv(newpcb, recv_callback);

	/* just use an integer number indicating the connection id as the
	   callback argument */
	tcp_arg(newpcb, (void*)(uintptr_t)connection);

	/* increment for subsequent accepted connections */
	connection++;

	return ERR_OK;
}


int start_echo_server(void)
{
	struct tcp_pcb *pcb;
	err_t err;
	unsigned port = 7;

	/* create new TCP PCB structure */
	pcb = tcp_new_ip_type(IPADDR_TYPE_ANY);
	if (!pcb) {
		PRINTF("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* bind to specified @port */
	err = tcp_bind(pcb, IP_ANY_TYPE, port);
	if (err != ERR_OK) {
		PRINTF("Unable to bind to port %d: err = %d\n\r", port, err);
		return -2;
	}

	/* we do not need any arguments to callback functions */
	tcp_arg(pcb, NULL);

	/* listen for connections */
	pcb = tcp_listen(pcb);
	if (!pcb) {
		PRINTF("Out of memory while tcp_listen\n\r");
		return -3;
	}

	/* specify callback to use for incoming connections */
	tcp_accept(pcb, accept_callback);

	PRINTF("TCP echo server started @ port %d\n\r", port);

	return 0;
}

void network_initialize(void)
{
	ip_addr_t ipaddr, netmask, gw;
	echo_netif = &server_netif;
    ipaddr.addr = 0;
	gw.addr = 0;
	netmask.addr = 0;

	lwip_init();

	if (!xemac_add(echo_netif, &ipaddr, &netmask,
						&gw, mac_ethernet_address,
						XPAR_XEMACPS_0_BASEADDR)) {
		PRINTF("Error adding N/W interface\n\r");
		ASSERT(0);
	}

	netif_set_default(echo_netif);
	netif_set_up(echo_netif);

	dhcp_start(echo_netif);
	dhcp_timoutcntr = 24;

	while(((echo_netif->ip_addr.addr) == 0) && (dhcp_timoutcntr > 0))
		xemacif_input(echo_netif);

	if (dhcp_timoutcntr <= 0) {
		if ((echo_netif->ip_addr.addr) == 0) {
			PRINTF("DHCP Timeout\r\n");
			PRINTF("Configuring default IP of 192.168.1.10\r\n");
			IP4_ADDR(&(echo_netif->ip_addr),  192, 168,   1, 10);
			IP4_ADDR(&(echo_netif->netmask), 255, 255, 255,  0);
			IP4_ADDR(&(echo_netif->gw),      192, 168,   1,  1);
		}
	}

	ipaddr.addr = echo_netif->ip_addr.addr;
	gw.addr = echo_netif->gw.addr;
	netmask.addr = echo_netif->netmask.addr;

	print_ip("Board IP: ", & ipaddr);
	print_ip("Netmask : ", & netmask);
	print_ip("Gateway : ", & gw);

	start_echo_server();

}

#endif /*  WITHLWIP */

void network_spool(void)
{
	if (TcpFastTmrFlag) {
		tcp_fasttmr();
		TcpFastTmrFlag = 0;
	}
	if (TcpSlowTmrFlag) {
		tcp_slowtmr();
		TcpSlowTmrFlag = 0;
	}
	xemacif_input(echo_netif);
}

#if 1

uint8_t myIP [4] = { 192, 168, 17, 33 };
uint8_t myNETMASK [4] = {255, 255, 255, 0};
uint8_t myGATEWAY [4] = { 0, 0, 0, 0 };

#else

uint8_t myIP [4] = { 172, 210, 72, 198 };		// ��� �������� ������ � ���������� �� �������� ��������� �������
//uint8_t myIP [4] = { 192, 168, 7, 1 };		// ������ � ����
uint8_t myNETMASK [4] = {255, 0, 0, 0};
uint8_t myGATEWAY [4] = { 172, 171, 242, 248 };

#endif
