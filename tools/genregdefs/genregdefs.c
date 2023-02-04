// genregdefs.c 
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>

#include "mslist.h"
#include "getopt_win.h"

/* debug stuff */
#if 0

	#define TP() do { \
		fprintf(stderr, "%s/%d\n", __FILE__, __LINE__); \
		fflush(stderr); \
		} while (0)

#else

#define TP() do { \
		} while (0)

#endif

struct regdfn {
	LIST_ENTRY item;
	char *fldname;
	char *typname;
	unsigned fldsize; /* 0 - need align to offset (end paddings) */
	unsigned fldoffs; /* offset inside block */
	char *comment;
	unsigned fldrept;   // 0 - plain field, 1..n - array
};

enum {
	BASE_MAX = 32
};
enum {
	VNAME_MAX = 96
};

struct parsedfile {
	LIST_ENTRY item;
	LIST_ENTRY regslist;
	//   size_t nregs;
	//   struct regdfn * regs;
	char bname[VNAME_MAX];
	int base_count;
	unsigned base_array[BASE_MAX];
	char base_names[BASE_MAX][VNAME_MAX];

	int irq_count;
	int irq_array[BASE_MAX];
	char irq_names[BASE_MAX][VNAME_MAX];

	int irqrv_count;
	int irqrv_array[BASE_MAX];
	char irqrv_names[BASE_MAX][VNAME_MAX];
};

#define INDENT 4
#define COMMENTPOS 80

void emitline(int pos, const char *format, ...) {
	static int emitpos;
	va_list ap;
	int n;
	FILE *fp = stdout;

	if (emitpos < pos) {
		const int pad = pos - emitpos;
		n = fprintf(fp, "%*.*s", pad, pad, "");
		if (n >= 0) {
			emitpos += pad;
		}
	}

	va_start(ap, format);
	n = vfprintf(fp, format, ap);
	va_end(ap);
	if (n >= 0) {
		emitpos += n;
	}
	if (strchr(format, '\n') != NULL)
		emitpos = 0;
}

/* Generate list of registers. Return last offset */
unsigned genreglist(int indent, const LIST_ENTRY *regslist) {
	unsigned offs;
	PLIST_ENTRY t;

	offs = 0;
	for (t = regslist->Flink; t != regslist; t = t->Flink) {
		const struct regdfn *regp = CONTAINING_RECORD(t, struct regdfn, item);
		static const char *fldtypes[] = { "uint32_t", "uint8_t ", "uint16_t",
				"uint24_t", "uint32_t", "uint40_t", "uint48_t", "uint56_t",
				"uint64_t", };

		char fldtype[VNAME_MAX];

		//fprintf(stderr, "$generate field: fldsize=%u fldoffs=%04X fldrept=%u fldname=%s\n", regp->fldsize, regp->fldoffs,regp->fldrept,regp->fldname);

		if (regp->fldsize >= sizeof fldtypes / sizeof fldtypes[0]) {
			_snprintf(fldtype, sizeof fldtype / sizeof fldtype[0], "typesize%u",
					regp->fldsize);
		} else {
			_snprintf(fldtype, sizeof fldtype / sizeof fldtype[0], "%s",
					fldtypes[regp->fldsize]);
		}

		if (regp->fldoffs > offs || regp->fldsize == 0) {
			// reserving
			const unsigned sz = regp->fldoffs - offs;

			if (sz == 4) {
				emitline(indent + INDENT + 9, "uint32_t reserved_0x%03X;\n",
						offs);
			} else if (sz != 0 && (sz % 4) == 0) {
				emitline(indent + INDENT + 9,
						"uint32_t reserved_0x%03X [0x%04X];\n", offs, sz / 4);
			} else if (sz != 0) {
				emitline(indent + INDENT + 9,
						"uint8_t reserved_0x%03X [0x%04X];\n", offs, sz);
			}
			offs = regp->fldoffs;
		}
		if (regp->fldoffs == offs) {
			if (regp->fldsize != 0) {
				if (regp->fldrept) {
					// Array forming
					if (regp->typname != NULL) {
						emitline(indent + INDENT, "%s %s [0x%03X];",
								regp->typname, regp->fldname, regp->fldrept);
					} else {
						emitline(indent + INDENT, "volatile %s %s [0x%03X];",
								fldtype, regp->fldname, regp->fldrept);
					}

					offs += regp->fldsize * regp->fldrept;
				} else {
					// Plain field
					if (regp->typname != NULL) {
						emitline(indent + INDENT, "%s %s;", regp->typname,
								regp->fldname);
					} else {
						emitline(indent + INDENT, "volatile %s %s;", fldtype,
								regp->fldname);
					}
					offs += regp->fldsize;
				}
				emitline(COMMENTPOS, "/*!< Offset 0x%03X %s */\n",
						regp->fldoffs, regp->comment);
			}
		} else {
			emitline(0,
					"#error WRONG offset of field '%s' type '%s' at (0x%03X)\n",
					regp->fldname, fldtype, regp->fldoffs);
			break;
		}
	}
	return offs;
}

void genstruct(struct parsedfile *pfl) {
	unsigned offs;

	emitline(0, "/*\n");
	emitline(0, " * @brief %s\n", pfl->bname);
	emitline(0, " */\n");

	emitline(0, "/*!< %s Controller Interface */\n", pfl->bname);
	emitline(0, "typedef struct %s_Type\n", pfl->bname);
	emitline(0, "{\n");

	offs = genreglist(0, &pfl->regslist);

	emitline(0, "} %s_TypeDef; /* size of structure = 0x%03X */\n", pfl->bname,
			offs);
}

void genstructprint(struct parsedfile *pfl) {
	PLIST_ENTRY t;

	emitline(0, "/* Print %s */\n", pfl->bname);
	emitline(0,
			"static void %s_Type_print(const %s_TypeDef * p, const char * base)\n",
			pfl->bname, pfl->bname);
	emitline(0, "{\n");
	for (t = pfl->regslist.Flink; t != &pfl->regslist; t = t->Flink) {
		const struct regdfn *p = CONTAINING_RECORD(t, struct regdfn, item);

		if (p->fldsize != 0) {
			if (p->fldrept && p->typname == NULL) {
				// Array forming
				unsigned i;
				for (i = 0; i < 4 && i < p->fldrept; ++i) {
					emitline(INDENT,
							"PRINTF(\"%%s->%s [%u] = 0x%%08X; /* 0x%%08X */\\n\", base, (unsigned) p->%s [%u], (unsigned) p->%s [%u]);",
							p->fldname, i, p->fldname, i, p->fldname, i);
					emitline(COMMENTPOS, "/*!< Offset 0x%03X %s */\n",
							p->fldoffs + i * p->fldsize, p->comment);
				}
			} else if (p->fldrept == 0 && p->typname == NULL) {
				// Plain field
				emitline(INDENT,
						"PRINTF(\"%%s->%s = 0x%%08X; /* 0x%%08X */\\n\", base, (unsigned) p->%s, (unsigned) p->%s );",
						p->fldname, p->fldname, p->fldname);
				emitline(COMMENTPOS, "/*!< Offset 0x%03X %s */\n", p->fldoffs,
						p->comment);
			}
		}
	}
	emitline(0, "}\n");
}

LIST_ENTRY parsedfiles;

struct basemap {
	unsigned base;
	char name[VNAME_MAX];
};

struct irqmap {
	int irq;
	char name[VNAME_MAX];
};

struct irqmaprv {
	int irqrv;
	char name[VNAME_MAX];
};

/* qsort parameter */
int compare_base(const void *v1, const void *v2) {
	const struct basemap *p1 = v1;
	const struct basemap *p2 = v2;
	if (p1->base == p2->base) {
		return strcmp(p1->name, p2->name);
	}
	return p1->base - p2->base;
}

/* qsort parameter */
int compare_irq(const void *v1, const void *v2) {
	const struct irqmap *p1 = v1;
	const struct irqmap *p2 = v2;

	if (p1->irq == p2->irq) {
		return strcmp(p1->name, p2->name);
	}
	return p1->irq - p2->irq;
}

/* qsort parameter */
int compare_irqrv(const void *v1, const void *v2) {
	const struct irqmaprv *p1 = v1;
	const struct irqmaprv *p2 = v2;

	if (p1->irqrv == p2->irqrv) {
		return strcmp(p1->name, p2->name);
	}
	return p1->irqrv - p2->irqrv;
}

/* source line for parse */

static char token0[1024];
#define TKSZ (sizeof token0 / sizeof token0 [0])

int nextline(FILE *fp) {
	char *s = fgets(token0, TKSZ, fp);
	if (s != NULL) {
		//fprintf(stderr, "#input:  '%s", s);
	}
	return s != NULL;

}

void parseregdef(struct regdfn *regp, char *s0, char *fldname, unsigned fldsize,
		char *typname, const char *file) {
	unsigned fldoffset;
	unsigned fldrept;

	static const char SEP[] = ";";
	//	#regdef; RISC_STA_ADD0_REG; 0x0004; RISC Start Address0 Register

	//fprintf(stderr, "Parsed regdef='%s' 0x%08X '%s'\n", fldname, fldoffset, comment);
	char *s = strtok(s0, SEP);
	char *s2 = strtok(NULL, SEP);

	/* trim field name */
	if (strchr(fldname, '\n') != NULL)
		*strchr(fldname, '\n') = '\0';
	if (strchr(fldname, '/') != NULL)
		*strchr(fldname, '/') = '_';
	if (strchr(fldname, '/') != NULL)
		*strchr(fldname, '/') = '_';

	if (s2 != NULL) {
		/* trim comments */
		while (isspace((unsigned char ) *s2))
			++s2;
		if (strchr(s2, '\n') != NULL)
			*strchr(s2, '\n') = '\0';
	}

	if (typname != NULL) {
		/* trim comments */
		if (strchr(typname, ';') != NULL)
			*strchr(typname, ';') = '\0';
		if (strlen(typname) == 0)
			typname = NULL;
	}

	//fprintf(stderr, "parse: '%s' '%s'\n", s, s2);

	if (2 == sscanf(s, "%i %i", &fldoffset, &fldrept)) {
		//fprintf(stderr, "fParsed 2 regdef='%s' offs=0x%08X rept=0x%08X\n", fldname, fldoffset, fldrept);
		regp->fldname = strdup(fldname);
		regp->fldoffs = fldoffset;
		regp->fldrept = fldrept;
		regp->fldsize = fldsize;
		regp->typname = typname ? strdup(typname) : NULL;
		regp->comment = strdup(s2);
	} else if (1 == sscanf(s, "%i", &fldoffset)) {
		//fprintf(stderr, "fParsed 1 regdef='%s' offs=0x%08X\n", fldname, fldoffset);
		regp->fldname = strdup(fldname);
		regp->fldoffs = fldoffset;
		regp->fldrept = 0;
		regp->fldsize = fldsize;
		regp->typname = typname ? strdup(typname) : NULL;
		regp->comment = strdup(s2);

		/* parsed */
	} else if (0 && 1 == sscanf(s, "%s", typname)) {
		//fprintf(stderr, "fParsed 4 regdef='%s' offs=0x%08X\n", fldname, fldoffset);
		regp->fldname = strdup(fldname);
		regp->fldoffs = fldoffset;
		regp->fldrept = 0;
		regp->fldsize = fldsize;
		regp->typname = typname ? strdup(typname) : NULL;
		regp->comment = strdup(s2);
	} else {
		regp->comment = strdup("no comment");

		fprintf(stderr, "fstrange '%s' token0='%s' regdef='%s'\n", file, token0,
				s);

		regp->fldname = strdup(fldname);
		regp->fldoffs = 0;
		regp->fldrept = 0;
		regp->fldsize = 4;

		/* parsed */
	}
}

// 1 - end of file
// 0 - register definition ok
static int parseregfile(struct parsedfile *pfl, FILE *fp, const char *file) {
	char comment[TKSZ];
	char fldname[VNAME_MAX];
	char typname[VNAME_MAX];
	char irqname[VNAME_MAX];
	char fldtype[VNAME_MAX];
	int irq;
	int irqrv;
	unsigned base;
	unsigned fldsize;
	int pos; /* end of parsed field position */

	//fprintf(stderr, "token0=%s", token0);
	for (;;) {
		memset(comment, 0, sizeof comment);
		if (2 == sscanf(token0, "#irq; %s %i\n", irqname, &irq)) {
			//fprintf(stderr, "Parsed irq='%s' %d\n", irqname, irq);
			if (pfl->irq_count < BASE_MAX) {
				pfl->irq_array[pfl->irq_count] = irq;
				strcpy(pfl->irq_names[pfl->irq_count], irqname);
				//
				++pfl->irq_count;
			}

			/* parsed */
			if (nextline(fp) == 0)
				break;
		} else if (2 == sscanf(token0, "#irqrv; %s %i\n", irqname, &irqrv)) {
			//fprintf(stderr, "Parsed irqrv='%s' %d\n", irqname, irqrv);
			if (pfl->irqrv_count < BASE_MAX) {
				pfl->irqrv_array[pfl->irqrv_count] = irq;
				strcpy(pfl->irqrv_names[pfl->irqrv_count], irqname);
				//
				++pfl->irqrv_count;
			}

			/* parsed */
			if (nextline(fp) == 0)
				break;
		} else if (1 == sscanf(token0, "#type; %[a-zA-Z0-9_]s\n", typname)) {
			//fprintf(stderr, "Parsed typname='%s'\n", typname);
			strcpy(pfl->bname, typname);

			/* parsed */
			if (nextline(fp) == 0)
				break;
		} else if (2 == sscanf(token0, "#base; %s%i\n", typname, &base)) {
			//fprintf(stderr, "Parsed base='%s' 0x%08X\n", typname, base);
			if (pfl->base_count < BASE_MAX) {
				pfl->base_array[pfl->base_count] = base;
				strcpy(pfl->base_names[pfl->base_count], typname);
				++pfl->base_count;
			}

			/* parsed */
			if (nextline(fp) == 0)
				break;
		} else if (3
				== sscanf(token0, "#regdef; %[a-zA-Z_0-9/] %i %s%n", fldname,
						&fldsize, &fldtype, &pos)) {
			struct regdfn *regp;

			//fprintf(stderr, "Parsed 3 regdef fldname='%s' fldszie=%u fldtype='%s'\n", fldname, fldsize, fldtype);
			regp = calloc(1, sizeof *regp);
			parseregdef(regp, token0 + pos, fldname, fldsize, fldtype, file);

			/* parsed */
			InsertTailList(&pfl->regslist, &regp->item);
			if (nextline(fp) == 0)
				break;
		} else if (2
				== sscanf(token0, "#regdef; %[a-zA-Z_0-9/] %i %n", fldname,
						&fldsize, &pos)) {
			struct regdfn *regp;

			//fprintf(stderr, "Parsed 2 regdef fldname='%s' fldszie=%u\n", fldname, fldsize);
			regp = calloc(1, sizeof *regp);
			parseregdef(regp, token0 + pos, fldname, fldsize, NULL, file);

			/* parsed */
			InsertTailList(&pfl->regslist, &regp->item);
			if (nextline(fp) == 0)
				break;
		} else if (1
				== sscanf(token0, "#regdef; %[a-zA-Z_0-9/] %n", fldname,
						&pos)) {
			struct regdfn *regp;

			//fprintf(stderr, "Parsed 1 regdef fldname='%s' \n", fldname);
			regp = calloc(1, sizeof *regp);
			parseregdef(regp, token0 + pos, fldname, 4, NULL, file);

			/* parsed */
			InsertTailList(&pfl->regslist, &regp->item);
			if (nextline(fp) == 0)
				break;

		} else if (1 == sscanf(token0, "#comment; %1023[^\n]c\n", comment)) {
			//fprintf(stderr, "Parsed comment='%s'\n", comment);
			//regp->comment = strdup(comment);
			if (nextline(fp) == 0)
				break;
		} else {
			/* unrecognized input = next source line */
			fprintf(stderr, "unrecognized token0=%s", token0);
			/* parsed */
			if (nextline(fp) == 0)
				break;
		}
	}
	return 1; /* end of file */
}

static int loadregs(struct parsedfile *pfl, const char *file) {
	const size_t maxrows = 256;
	FILE *fp = fopen(file, "rt");
	//TP();
	strcpy(pfl->bname, "");
	pfl->base_count = 0;
	pfl->irq_count = 0;
	pfl->irqrv_count = 0;

	InitializeListHead(&pfl->regslist);
	//pfl->regs = NULL; 
	//pfl->nregs = 0; 

	//TP();
	if (fp == NULL) {
		fprintf(stderr, "#error Can not open file '%s'\n", file);
		return 1;
	}
	//fprintf(stderr, "#error Opened file '%s'\n", file);

	if (nextline(fp) == 0)
		return 1;

	parseregfile(pfl, fp, file);

	//pfl->regs = regs; 
	//pfl->nregs = nregs; 
	fclose(fp);
	return 0;
}

static void processfile_periphregs(struct parsedfile *pfl) {

	if (!IsListEmpty(&pfl->regslist)) {
		genstruct(pfl);
	} else {
		//fprintf(stderr, "#error No registers in '%s'\n", pfl->bname);
	}
}

static void processfile_periphregsdebug(struct parsedfile *pfl) {

	if (!IsListEmpty(&pfl->regslist)) {
		genstructprint(pfl);
	}
}

static int collect_base(struct parsedfile *pfl, int n, struct basemap *v) {
	/* collect base pointers */
	int i;
	int score = 0;
	for (i = 0; i < pfl->base_count && n--; ++i, ++v, ++score) {
		strcpy(v->name, pfl->base_names[i]);
		v->base = pfl->base_array[i];
	}
	return score;
}

static void processfile_access(struct parsedfile *pfl) {

	/* print acces pointers */
	int i;

	if (IsListEmpty(&pfl->regslist))
		return;
	for (i = 0; i < pfl->base_count; ++i) {
		emitline(0, "#define %s ((%s_TypeDef *) %s_BASE)", pfl->base_names[i],
				pfl->bname, pfl->base_names[i]);
		emitline(COMMENTPOS,
				"/*!< \\brief %s Interface register set access pointer */\n",
				pfl->base_names[i]);
	}
}

static int collect_irq(struct parsedfile *pfl, int n, struct irqmap *v) {
	/* collect irq vectors */
	int i;
	int score = 0;
	for (i = 0; i < pfl->irq_count && n--; ++i, ++v, ++score) {
		strcpy(v->name, pfl->irq_names[i]);
		v->irq = pfl->irq_array[i];
	}
	return score;
}

static int collect_irqrv(struct parsedfile *pfl, int n, struct irqmaprv *v) {
	/* collect irq vectors */
	int i;
	int score = 0;
	for (i = 0; i < pfl->irqrv_count && n--; ++i, ++v, ++score) {
		strcpy(v->name, pfl->irqrv_names[i]);
		v->irqrv = pfl->irqrv_array[i];
	}
	return score;
}

static void freeregs(struct parsedfile *pfl) {
	PLIST_ENTRY t;
	//fprintf(stderr, "Release memory\n");
	for (t = pfl->regslist.Flink; t != &pfl->regslist;) {
		struct regdfn *regp = CONTAINING_RECORD(t, struct regdfn, item);
		t = t->Flink;
		free(regp->fldname);
		free(regp->typname);
		free(regp->comment);
		free(regp);
	}
}

int main(int argc, char *argv[], char *envp[]) {
	//struct parsedfile pfls [MAXPARSEDFILES];
	int i = 1;
	//int nperoiph;

	if (argc < 2)
		return 1;

	InitializeListHead(&parsedfiles);

	/* Load files */
	for (; i < argc;) {
		struct parsedfile *const pfl = calloc(1, sizeof(struct parsedfile));
		if (loadregs(pfl, argv[i]) != 0) {
			free(pfl);
			break;
		}
		InsertTailList(&parsedfiles, &pfl->item);
		++i;
	}

	{
		PLIST_ENTRY t;
		for (t = parsedfiles.Flink; t != &parsedfiles; t = t->Flink) {
			struct parsedfile *const pfl = CONTAINING_RECORD(t,
					struct parsedfile, item);
			//fprintf(stderr, "$");
		}
	}

	if (1) {
		/* CMSIS header forming */
		char headrname[128];
		_snprintf(headrname, sizeof headrname / sizeof headrname[0],
				"HEADER_%08X_INCLUDED", (unsigned) time(NULL));

		emitline(0, "#ifndef %s" "\n", headrname);
		emitline(0, "#define %s" "\n", headrname);

		emitline(0, "#include <stdint.h>" "\n");
		emitline(0, "\n");

		if (0) {
			/* collect ARM IRQ vectors */
			int nitems = 0;
			struct irqmap irqs[1024];

			{
				PLIST_ENTRY t;
				for (t = parsedfiles.Flink;
						t != &parsedfiles
								&& nitems < sizeof irqs / sizeof irqs[0];
						t = t->Flink) {
					struct parsedfile *const pfl = CONTAINING_RECORD(t,
							struct parsedfile, item);
					nitems += collect_irq(pfl,
							sizeof irqs / sizeof irqs[0] - nitems,
							irqs + nitems);
				}
			}

			qsort(irqs, nitems, sizeof irqs[0], compare_irq);

			emitline(0, "\n");
			emitline(0, "/* IRQs */\n");
			emitline(0, "\n");
			emitline(0, "typedef enum IRQn\n");
			emitline(0, "{\n");
			for (i = 0; i < nitems; ++i) {
				struct irqmap *const p = &irqs[i];

				emitline(0, "\t%s_IRQn\t= %d,\n", p->name, p->irq);
			}
			emitline(0, "\n");
			emitline(0, "\t%MAX_IRQ_n,\n");
			emitline(0,
					"\tForce_IRQn_enum_size\t= %d\t/* Dummy entry to ensure IRQn_Type is more than 8 bits. Otherwise GIC init loop would fail */\n",
					1048);
			emitline(0, "} IRQn_Type;\n");
			emitline(0, "\n");
		}

		if (0) {
			/* collect RISC-V IRQ vectors */
			int nitems = 0;
			struct irqmaprv irqs[1024];

			{
				PLIST_ENTRY t;
				for (t = parsedfiles.Flink;
						t != &parsedfiles
								&& nitems < sizeof irqs / sizeof irqs[0];
						t = t->Flink) {
					struct parsedfile *const pfl = CONTAINING_RECORD(t,
							struct parsedfile, item);
					nitems += collect_irqrv(pfl,
							sizeof irqs / sizeof irqs[0] - nitems,
							irqs + nitems);
				}
			}

			qsort(irqs, nitems, sizeof irqs[0], compare_irqrv);

			emitline(0, "\n");
			emitline(0, "/* IRQs */\n");
			emitline(0, "\n");
			emitline(0, "typedef enum IRQn\n");
			emitline(0, "{\n");
			for (i = 0; i < nitems; ++i) {
				struct irqmaprv *const p = &irqs[i];

				emitline(0, "\t%s_IRQn\t= %d,\n", p->name, p->irqrv);
			}
			emitline(0, "\n");
			emitline(0, "\t%MAX_IRQ_n,\n");
			emitline(0,
					"\tForce_IRQn_enum_size\t= %d\t/* Dummy entry to ensure IRQn_Type is more than 8 bits. Otherwise GIC init loop would fail */\n",
					1048);
			emitline(0, "} IRQn_Type;\n");
			emitline(0, "\n");
		}

		if (1) {

			/* collect base addresses */
			int nitems = 0;
			struct basemap maps[256];
			PLIST_ENTRY t;

			for (t = parsedfiles.Flink; t != &parsedfiles; t = t->Flink) {
				struct parsedfile *const pfl = CONTAINING_RECORD(t,
						struct parsedfile, item);
				nitems += collect_base(pfl, 1024 - nitems, maps + nitems);
			}

			qsort(maps, nitems, sizeof maps[0], compare_base);

			emitline(0, "\n");
			emitline(0, "/* Peripheral and RAM base address */\n");
			emitline(0, "\n");

			for (i = 0; i < nitems; ++i) {
				struct basemap *const p = &maps[i];

				emitline(0, "#define\t%s_BASE\t ((uintptr_t) 0x%08X)\n",
						p->name, p->base);
			}
		}

		if (1) {
			/* structures */
			PLIST_ENTRY t;

			for (t = parsedfiles.Flink; t != &parsedfiles; t = t->Flink) {
				struct parsedfile *const pfl = CONTAINING_RECORD(t,
						struct parsedfile, item);
				processfile_periphregs(pfl);
			}
		}

		if (1) {
			PLIST_ENTRY t;

			emitline(0, "\n");
			emitline(0, "/* Access pointers */\n");
			emitline(0, "\n");

			for (t = parsedfiles.Flink; t != &parsedfiles; t = t->Flink) {
				struct parsedfile *const pfl = CONTAINING_RECORD(t,
						struct parsedfile, item);
				processfile_access(pfl);
			}
		}

		emitline(0, "#endif /* %s */" "\n", headrname);
	} else {
		/* Debug header forming */
		char headrname[128];
		PLIST_ENTRY t;

		/* print structire debug */

		_snprintf(headrname, sizeof headrname / sizeof headrname[0],
				"HEADER_%08X_INCLUDED", (unsigned) time(NULL));

		emitline(0, "#ifndef %s" "\n", headrname);
		emitline(0, "#define %s" "\n", headrname);
		emitline(0, "#ifdef PRINTF\n");

		/* structures */

		for (t = parsedfiles.Flink; t != &parsedfiles; t = t->Flink) {
			struct parsedfile *const pfl = CONTAINING_RECORD(t,
					struct parsedfile, item);
			processfile_periphregsdebug(pfl);
		}
		emitline(0, "#endif /* PRINTF */\n");
		emitline(0, "#endif /* %s */" "\n", headrname);
	}

	{
		PLIST_ENTRY t;
		/* release memory */

		for (t = parsedfiles.Flink; t != &parsedfiles;) {
			struct parsedfile *const pfl = CONTAINING_RECORD(t,
					struct parsedfile, item);
			t = t->Flink;

			freeregs(pfl);
		}
	}

	return 0;
}

