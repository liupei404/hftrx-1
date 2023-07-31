// egontool.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <string.h>


#if defined   (__GNUC__)        /* GNU Compiler */
	#include <stdint.h>
	#define ATTRPACKED __attribute__ ((packed))
#else
	#define ATTRPACKED
	typedef unsigned int uint32_t;
	typedef unsigned char uint8_t;

#endif /* __GNUC__ */


static int targetRV = 0;
static int targetAARCH64 = 0;

/* boot_file_head copied from mksunxiboot */
/* boot head definition from sun4i boot code */
typedef struct boot_file_head
{
	uint32_t  jump_instruction;   // +0000	one intruction jumping to real code
	uint8_t   magic[8];           // +0004	"eGON.BT0" or "eGON.BT1",  not C-style string.
	uint32_t  check_sum;          // +000C	generated by PC
	uint32_t  length;             // +0010	generated by PC	// Size of Boot0, it's must be 8-KiB aligned in NAND and 512-Bytes aligned in MMC
	uint32_t  pub_head_size;      // +0014	the size of boot_file_head_t
	uint32_t  pub_head_vsn;		  // +0018	the version of boot_file_head_t
	uint32_t  file_head_vsn;	  // +001C	the version of boot0_file_head_t or boot1_file_head_t
	uint32_t  Boot_vsn;			  // +0020	Boot version
	uint32_t  eGON_vsn;			  // +0024	eGON version
	uint8_t   platform[8];        // +0028	platform information
} ATTRPACKED boot_file_head_t;


static uint32_t alignup(uint32_t size, uint32_t page)
{
	return (size + page - 1) & ~ (page - 1);
}

static void fillpad(FILE * fp, long size)
{
	while (size --)
	{
		fputc(0x00, fp);
	}
}

static uint32_t cks(const void * buff, unsigned size, uint32_t sum)
{
	const uint32_t * p = (const uint32_t *) buff;
	size /= 4;
	while (size --)
		sum += * p ++;
	return sum;
}

static void place_uint32_le(void * buff, uint32_t v)
{
	uint8_t * const p = (uint8_t * const) buff;

	p [0] = (v >> 0);
	p [1] = (v >> 8);
	p [2] = (v >> 16);
	p [3] = (v >> 24);
}

static void process(
	FILE * infile,
	FILE * outfile)
{
	boot_file_head_t head;
	static const uint8_t magic_eGON_BT0 [8] = { 'e', 'G', 'O', 'N', '.', 'B', 'T', '0' };	/* eGON.BT0 */
	static const uint8_t pub_head_vsn [8] = { '3', '0', '0', '0' };	/* 3000 */
	static const uint8_t platform [8] = {  '\0',  '\0',  '\0',  '\0', '4', '.', '0', '\0' };	/* 4.0 */
	const unsigned execoffset = 0x100;
	long binsize;
	long silesizealigned;
	uint32_t check_sum;

	fseek(infile, 0, SEEK_END);
	binsize = ftell(infile);
	silesizealigned = alignup(binsize + execoffset, 16 * 1024);

	fprintf(stderr, "Okay open file: original:%ld aligned:%ld\n", binsize, silesizealigned);

	{
		long i;
		/* checksum calculate */
		check_sum = 0;
		rewind(infile);
		for (i = 0; i < binsize;)
		{
			enum { CHUNKSIZE = 256 };
			uint8_t buff [CHUNKSIZE];
			unsigned chunk = CHUNKSIZE > (binsize - i) ? (binsize - i) : CHUNKSIZE;
			memset(buff + chunk, 0x00, CHUNKSIZE - chunk);
			fread(buff, chunk, 1, infile);
			check_sum = cks(buff, CHUNKSIZE, check_sum);
			i += chunk;
		}

	}


	/* Fill head */
	if (targetRV)
		place_uint32_le(& head.jump_instruction, 0x6F | (execoffset << 20));	/// Jump to $ + 0x0100
	else if (targetAARCH64)
		place_uint32_le(& head.jump_instruction, 0x14000000 | ((execoffset / 4)));	/// Jump to $ + 0x0100
	else
		place_uint32_le(& head.jump_instruction, 0xEA000000 | (execoffset - 8) / 4);	/// Jump to $ + 0x0100

	memcpy(& head.magic, magic_eGON_BT0, 8);
	place_uint32_le(& head.check_sum, 0x5F0A6C39);//check_sum;
	place_uint32_le(& head.length, silesizealigned);//binsize;
	place_uint32_le(& head.pub_head_size, sizeof head);
	memcpy(& head.pub_head_vsn, pub_head_vsn, sizeof head.pub_head_vsn);
	place_uint32_le(& head.file_head_vsn, 0x00020000 * 0);	// ignored by Allwinner T113-S3 ?
	place_uint32_le(& head.Boot_vsn, 0x00020000 * 0);		// ignored by Allwinner T113-S3 ?
	memset(& head.eGON_vsn, 0x00, sizeof head.eGON_vsn);
	memcpy(& head.platform, platform, sizeof head.platform);

	check_sum = cks((const uint8_t *) & head, sizeof head, check_sum);

	place_uint32_le(& head.check_sum, check_sum);


	fwrite(& head, 1, sizeof head, outfile);
	fillpad(outfile, execoffset - sizeof head);

	{
		long i;
		/* copy file */
		rewind(infile);
		for (i = 0; i < binsize; )
		{
			enum { CHUNKSIZE = 256 };
			uint8_t buff [CHUNKSIZE];
			unsigned chunk = CHUNKSIZE > (binsize - i) ? (binsize - i) : CHUNKSIZE;
			fread(buff, chunk, 1, infile);
			fwrite(buff, chunk, 1, outfile);
			i += chunk;
		}
	}

	fillpad(outfile, silesizealigned - binsize - execoffset);
}

static void printfile(FILE * fp)
{
	boot_file_head_t head;
	size_t n;

	n = fread(& head, 1, sizeof head, fp);
	if (n < 1)
	{
		fprintf(stderr, "Not enough data\n");
		return;
	}
	printf("magic: '%8.8s'\n", head.magic);
	printf("length: %u (0x%x) bytes\n", (unsigned) head.length, (unsigned) head.length);
}

static int printFLAG;

int main(int argc, char* argv[])
{
	if (argc > 1 && strcmp(argv [1], "-rv") == 0)
	{
		++ argv;
		-- argc;
		targetRV = 1;
		//fprintf(stderr, "RISC-V header generate\n");
	}
	if (argc > 1 && strcmp(argv [1], "-print") == 0)
	{
		++ argv;
		-- argc;
		printFLAG = 1;
		//fprintf(stderr, "RISC-V header generate\n");
	}
	if (argc > 1 && strcmp(argv [1], "-aarch64") == 0)
	{
		++ argv;
		-- argc;
		targetAARCH64 = 1;
		//fprintf(stderr, "RISC-V header generate\n");
	}

	if (printFLAG && argc >= 2)
	{
		const char * const infilename = argv [1];
		FILE * infile = fopen(infilename,"rb");
		if (infile == NULL)
		{
			fprintf(stderr, "Can not open file '%s'...\n", infilename);
			return 1;
		}
		printfile(infile);
		fclose(infile);
		return 0;
	}

	if (argc < 3)
		return 1;
	else
	{
		const char * const infilename = argv [1]; //"../../build/allwinner_t113_s3/tc1_t113s3_boot.bin";
		const char * const outfilename = argv [2]; //"../../build/allwinner_t113_s3/fsbl.alw32";

		FILE * infile = fopen(infilename,"rb");
		FILE * outfile = fopen(outfilename,"wb");

		if (infile == NULL || outfile == NULL)
		{
			fprintf(stderr, "Can not open files...\n");
			return 1;
		}
		
		process(infile, outfile);

		//fprintf(stderr, "Okay processing... %ld %ld\n", binsize, silesizealigned);
	}

	return 0;
}
