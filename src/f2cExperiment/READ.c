/* READ.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer stklst[300];
} stklst_;

#define stklst_1 stklst_

struct {
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer srctbl[502];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer seqno;
} seqcom_;

#define seqcom_1 seqcom_

struct {
    char seqnum[6];
} cseqcm_;

#define cseqcm_1 cseqcm_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx5[135];
} macxx5_;

#define macxx5_1 macxx5_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    logical libprt;
} libprt_;

#define libprt_1 libprt_

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__74 = 74;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__85 = 85;

/* *** SOURCE FILE : M0006671.W01   *** */


/*              FORTRAN SUBROUTINE READ */

/* LINKAGE      SUBROUTINE READ (INCHAR) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ICONV           SUBROUTINE    INPUT */
/*          SUBROUTINE    CREAD           SUBROUTINE    PRO026 */
/*          SUBROUTINE    LIBRD */
/*          SUBROUTINE    CPRINT */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    CFORM */

/* Subroutine */ int read_(integer *inchar)
{
    /* Initialized data */

    static logical readfg = TRUE_;
    static integer ii = 0;
    static char iblk[4] = "    ";
    static char cfini[4] = "FINI";
    static integer linest = 13;
    static char ia[6*5] = "PARTNO" "TITLES" "PPRINT" "INSERT" "REMARK";
    static char validc[80] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ +-*/=.,'("
	    ")$%<&#@;abcdefghijklmnopqrstuvwxyz";
    static integer conv[80] = { 2,3,4,5,6,7,8,9,10,11,15,16,17,18,19,20,21,22,
	    23,27,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47,38,14,26,37,
	    39,12,24,48,13,49,25,36,49,25,26,12,13,0,15,16,17,18,19,20,21,22,
	    23,27,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47 };

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
#define top ((integer *)&stklst_1)
    static integer iend;
#define meta ((integer *)&srctbl_1 + 2)
    static integer numi;
    extern /* Subroutine */ int cread_(char *, integer *, ftnlen);
    static integer iflag;
#define nmmac ((integer *)&macseg_1 + 2)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen), librd_(char *, integer *, char *, ftnlen, ftnlen);
#define stack ((integer *)&stklst_1 + 3)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static char lrarg[6];
#define nmseg ((integer *)&macseg_1 + 1)
#define slash ((integer *)&code_1 + 8)
    static integer inlin;
    static logical qtflg;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define rterm ((integer *)&code_1 + 6)
#define quote ((integer *)&code_1 + 22)
#define macldd ((logical *)&macxx1_1 + 6)
#define cflags ((logical *)&super_1)
    static char rdchar[80];
    static logical libflg;
#define dlrflg ((logical *)&doloop_1 + 7)
#define lmrend ((logical *)&macseg_1 + 5)
#define modulo ((integer *)&moduli_1)
    static integer numchr;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
#define errpnt ((integer *)&errpos_1 + 2)
#define newstm ((logical *)&flags_1 + 1)
#define lxtras ((logical *)&super_1 + 9)
#define itmpsv ((integer *)&macxx5_1)
#define lmrstr ((logical *)&macseg_1 + 3)




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM ' */
/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* QUOTE:       (1)=CODE CLASS 12000,(2)=NAMTBL INDEX OF ''     ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */

/*       20.    IO - ARRAY */
/*              I/O ARRAY */




/*       22.    MACRO PROCESSING VARIABLES */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* MACLDD:      TRUE WHEN MACRO TEXT IS TO BE LOAD INTO MCBUFF TABLE */

/*      25A.    MACRO PROCESSING ARRAY */

/* ITMPSV:      TEMPORARY STORAGE DURING FINAL MACRO PROCESSING */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* NMSEG:       NAMTBL POINTER TO THE NAME OF THE PART PROGRAM SEGMENT */
/* NMMAC:       NAMTBL POINTER TO SYSTEM MACRO NAME */
/* LMRSTR:      FLAG ON STARTS READING IN A SYSTEM MACRO */
/* LMREND:      FLAG ON AFTER COMPLETION READING A SYSTEM MACRO */

/*       39.    COMMON BLOCK LIBRARY PRINTING FLAG */
/*              FLAG ON CAUSE PRINTING OF INPUT LIBRARIES */

/*       40.    PARAMETERS REQUIRED BY SUPERVISOR */

/* END:         FLAG TO INDICATE LAST PART PROGRAM */
/* IRDSAV:      SAVE AREA FOR FIRST CARD IN PART PROGRAM */

/*       43.    DO LOOP CONTROL VALUES */





/* DLRFLG:      FLAG IS ON WHEN CONTINUATION CARD EXPECTED */

/*       44.    ERROR POSITION TABLE */

/* ERRPNT:      CONTAINS POINTERS TO INPUT STATEMENT TEXT POSITIONS */
/* * */
    /* Parameter adjustments */
    --inchar;

    /* Function Body */

/*     LIST OF VALID CHARACTERS */

/*  ASCII/EBCDIC REPRESENTATION OF BCDIC CHARACTERS ()+=' */
/*  SEMI-COLON */
/*  LOWER CASE CHARACTERS */

/*                   CONV TABLE */

/*                 0   1   2   3   4   5   6   7   8   9 */
/*                 A   B   C   D   E   F   G   H   I */
/*                 J   K   L   M   N   O   P   Q   R */
/*                 S   T   U   V   W   X   Y   Z */
/*                SP   +   -   *   /   =   .   ,   '   (   )   $ */
/*                 %   <   &   #   @   ; */
/*                 a   b   c   d   e   f   g   h   i */
/*                 j   k   l   m   n   o   p   q   r */
/*                 s   t   u   v   w   x   y   z */
/* ** */
    if (! (*dlrflg)) {
	inlin = 0;
    }
    if (! readfg) {
	goto L110;
    }
    numchr = 72;
    numi = 0;

/* ...   IF END IS FALSE, FIRST CARD FOR THIS PROGRAM IS IN IRDSAV */

    libflg = TRUE_;
    if (super_1.end) {
	goto L15;
    }
    s_copy(rdchar, csuper_1.irdsav, (ftnlen)80, (ftnlen)80);
    super_1.end = TRUE_;
    goto L25;

/*                   READ CARD IMAGE */

L15:
    if (*nmseg == 0) {
	goto L16;
    }
    s_copy(lrarg, cnamtb_1.cnamtb + (*nmseg - 1) * 6, (ftnlen)6, (ftnlen)6);
    librd_(lrarg, &iflag, rdchar, (ftnlen)6, (ftnlen)80);
    if (iflag == 0) {
	goto L27;
    }
    if (iflag != 1) {
	alarm_(&c__74, &c__0, &c__8, "READ    ", (ftnlen)8);
    }
    *nmseg = 0;
    goto L19;
L16:
    if (*nmmac != 0) {
	goto L32;
    }
L19:
    cread_(rdchar, &iend, (ftnlen)80);
    if (iend == 1) {
	goto L50;
    }
L25:
    libflg = FALSE_;
L26:
    inptr_1.cnt = 0;
    goto L34;
L27:
    if (libprt_1.libprt) {
	goto L25;
    }
    goto L26;
L32:
    if (! (*lmrstr)) {
	goto L38;
    }
    s_copy(csuper_1.irdsav, rdchar, (ftnlen)80, (ftnlen)80);
    itmpsv[0] = inptr_1.cnt - 1;
    *lmrstr = FALSE_;
L38:
    s_copy(lrarg, cnamtb_1.cnamtb + (*nmmac - 1) * 6, (ftnlen)6, (ftnlen)6);
    librd_(lrarg, &iflag, rdchar, (ftnlen)6, (ftnlen)80);
    if (iflag == 0) {
	goto L27;
    }
    if (iflag != 1) {
	alarm_(&c__74, &c__0, &c__8, "READ    ", (ftnlen)8);
    }
    s_copy(rdchar, csuper_1.irdsav, (ftnlen)80, (ftnlen)80);
    inptr_1.cnt = itmpsv[0];
    *top = itmpsv[1];
    i__1 = *top;
    for (i__ = 1; i__ <= i__1; ++i__) {
	stack[(i__ << 1) - 2] = itmpsv[i__ * 2];
	stack[(i__ << 1) - 1] = itmpsv[(i__ << 1) + 1];
/* L37: */
    }
    i__ = nametb_1.namtbl[*nmmac - 1] / *modulo;
    stack[7] = meta[i__ - 1];
    *nmmac = 0;
    *lmrend = TRUE_;

L34:
    qtflg = FALSE_;
/*        CHECK FOR PARTNO, TITLES, PPRINT, INSERT, REMARK */
    for (i__ = 1; i__ <= 5; ++i__) {
	if (s_cmp(rdchar, ia + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L90;
	}
	j = 0;
	if (i__ == 5) {
	    goto L80;
	}
	goto L98;
L90:
	;
    }
L40:
    j = 0;
    *dlrflg = FALSE_;
    readfg = TRUE_;
    l = numi + 1;
    for (i__ = l; i__ <= 72; ++i__) {
/* ...FOR EACH CHARACTER INPUT CHECK IF A VALID CHARACTER */
/*   INCHAR(I)=0 INVALID CHARACTER */
/*   OTHERWISE LOCATION OF CHARACTER IN NAME TABLE */
	ii = i_indx(validc, rdchar + (i__ - 1), (ftnlen)80, (ftnlen)1);
	if (ii == 0) {
	    inchar[i__] = 0;
	} else {
	    inchar[i__] = conv[ii - 1];
	}
/*   DOLLAR GESETZT? */
	if (*dlrflg) {
	    goto L75;
	}
/*   HOCHKOMMA? */
	if (ii != 45) {
	    goto L43;
	}
	if (qtflg) {
	    goto L42;
	}
	if (j == 0) {
	    goto L41;
	}
/*  VORHERGEHENDES ZEICHEN HOCHKOMMA? :FORTSETZUNG EINER ZEICHENKETTE */
	if (inchar[j] != 13) {
	    goto L41;
	}
	qtflg = TRUE_;
	--j;
	goto L61;
/*  NEUER START EINER ZEICHENKETTE */
L41:
	qtflg = TRUE_;
	goto L60;
L42:
	qtflg = FALSE_;
	goto L60;
L43:
	if (! qtflg) {
	    goto L45;
	}
/* AUSGABE EINES NEGATIVEN BUCHSTABEN-WERTES,DA ZEICHENKETTE */
L61:
	++j;
	inchar[j] = -conv[ii - 1];
	goto L70;
/*     AUF BLANK PRUEFEN */
L45:
	if (ii == 37) {
	    goto L70;
	}

/*     STRICHPUNKT  = ENDE EINES APT-SATZES */

	if (ii == 54) {
	    goto L105;
	}

/*        AUF DOLLAR PRUEFEN */
	if (ii == 48) {
	    *dlrflg = TRUE_;
	}
/*    AUSGABE DES NAMENSTAFEL-INDEX */
L60:
	++j;
	inchar[j] = conv[ii - 1];
	errpnt[j - 1] = i__ + inlin;
L70:
	;
    }
    if (numi != 0) {
	numchr = 85 - linest;
    }
/*  VERHINDERUNG VON UEBER KARTENGRENZE REICHENDER ZEICHENKETTE */
    if (! qtflg) {
	goto L80;
    }
    ++j;
    inchar[j] = quote[1];

/*        END OF CARD - SET POINTER TO RTERM */
L80:
    inchar[j + 1] = rterm[1];
L82:
    if (libflg) {
	goto L100;
    }
    iconv_(&seqcom_1.seqno, darray_1.darray, &c__5, &c__4, (ftnlen)120);
    cform_(".", darray_1.darray, &c__9, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(rdchar, darray_1.darray, &linest, &numchr, (ftnlen)80, (ftnlen)120)
	    ;
    cform_(rdchar + 72, darray_1.darray, &c__85, &c__8, (ftnlen)8, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
L100:
    return 0;
L105:
    readfg = FALSE_;
    numchr = i__;
    numi = i__;
    goto L80;
L110:
    s_copy(rdchar, iblk, numi, (ftnlen)4);
    goto L26;
/*        IS THIS $$ */
L75:
    numchr = 72;
    inlin += 100;
    if (ii == 48) {
	goto L78;
    }
    goto L80;
L78:
    --j;
    *dlrflg = FALSE_;
    goto L80;
/*        MISSING FINI - INSERT FINI AND COMPLETE PROCESSING */
L50:
    iflag = 55;
    if (*macldd) {
	iflag = 56;
    }
    alarm_(&iflag, &c__0, &c__4, "READ    ", (ftnlen)8);
    super_1.end = FALSE_;
    if (*macldd) {
	goto L56;
    }
    s_copy(rdchar, cfini, (ftnlen)80, (ftnlen)4);
    goto L25;
L56:
    s_copy(csuper_1.irdsav, cfini, (ftnlen)80, (ftnlen)4);
    *macldd = FALSE_;
    *newstm = TRUE_;
    inchar[1] = rterm[1];
    inptr_1.cnt = 0;
    goto L100;
/*        CHANGE PARTNO, TITLES, PPRINT, INSERT TO NEW FORMAT */
L98:
    for (i__ = 7; i__ <= 72; ++i__) {
	ii = i_indx(validc, rdchar + (i__ - 1), (ftnlen)80, (ftnlen)1);
	if (ii == 0) {
	    inchar[i__] = 0;
	} else {
	    inchar[i__] = conv[ii - 1];
	}
	if (inchar[i__] == slash[1]) {
	    goto L40;
	}
	if (ii != 37) {
	    goto L92;
	}
/* L91: */
    }
L92:
    qtflg = FALSE_;
    for (k = 1; k <= 72; ++k) {
	i__ = 73 - k;
	ii = i_indx(validc, rdchar + (i__ - 1), (ftnlen)80, (ftnlen)1);
	if (ii == 0) {
	    inchar[i__] = 0;
	} else {
	    inchar[i__] = conv[ii - 1];
	}
	if (qtflg) {
	    goto L94;
	}
/* L93: */
	if (ii == 37 && i__ != 7) {
	    goto L96;
	}
	qtflg = TRUE_;
	inchar[i__ + 4] = rterm[1];
	inchar[i__ + 3] = quote[1];
L94:
	if (ii == 0) {
	    if (i__ >= 7) {
		inchar[i__ + 2] = 0;
	    }
	    if (i__ <= 7) {
		inchar[i__] = 0;
	    }
	} else {
	    if (i__ >= 7) {
		inchar[i__ + 2] = -conv[ii - 1];
	    }
	    if (i__ <= 7) {
		inchar[i__] = conv[ii - 1];
	    }
	}
L96:
	;
    }
    qtflg = FALSE_;
    inchar[7] = slash[1];
    inchar[8] = quote[1];
    goto L82;
} /* read_ */

#undef lmrstr
#undef itmpsv
#undef lxtras
#undef newstm
#undef errpnt
#undef modulo
#undef lmrend
#undef dlrflg
#undef cflags
#undef macldd
#undef quote
#undef rterm
#undef slash
#undef nmseg
#undef stack
#undef nmmac
#undef meta
#undef top


