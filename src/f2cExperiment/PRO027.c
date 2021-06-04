/* PRO027.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer seqcom[3];
} seqcom_;

#define seqcom_1 seqcom_

struct {
    integer cfsize[1106];
} cfsize_;

#define cfsize_1 cfsize_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer macxx5[135];
} macxx5_;

#define macxx5_1 macxx5_

struct {
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer first[6]	/* was [2][3] */;
} blkcfs_;

#define blkcfs_1 blkcfs_

struct {
    integer comp26[16];
} comp26_;

#define comp26_1 comp26_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer bgeom[4];
} bgeom_;

#define bgeom_1 bgeom_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    logical libprt;
} libprt_;

#define libprt_1 libprt_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

/* Table of constant values */

static integer c__2018 = 2018;
static integer c__8 = 8;
static integer c_n1 = -1;
static integer c__1 = 1;
static integer c__2019 = 2019;
static integer c__2035 = 2035;
static integer c__4 = 4;
static integer c__2030 = 2030;
static integer c__2031 = 2031;
static integer c__5 = 5;
static integer c__2052 = 2052;
static integer c__0 = 0;
static integer c__98 = 98;
static integer c__3 = 3;
static integer c__2034 = 2034;
static integer c__2010 = 2010;
static integer c__2011 = 2011;
static integer c__1001 = 1001;
static integer c__34 = 34;
static integer c__53 = 53;

/* *** SOURCE FILE : M0006668.W05   *** */


/*              FORTRAN SUBROUTINE PRO027 */

/* LINKAGE      SUBROUTINE PRO027(IGOTO) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    PRO026 */
/*          SUBROUTINE    FOUTXX          SUBROUTINE    RECOG */
/*          SUBROUTINE    LIBOPC */
/*          SUBROUTINE    LIBRD */
/*          SUBROUTINE    LIBSCH */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    MCXTRN */
/*          INTEGER FCT.  MODE */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    BCDBIN */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    REFGEN */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int pro027_(integer *igoto)
{
    /* Initialized data */

    static char srprnt[6] = "PRINT ";
    static char hon[6] = "ON    ";
    static char hoff[6] = "OFF   ";
    static char hall[6] = "ALL   ";
    static integer syntop = 10;
    static char synlst[6*10] = "APTRAN" "APTREN" "CLOCK " "CLPRNT" "CONTRL" 
	    "FINI  " "MACRO " "PRINT " "SYN   " "TERMAC";
    static char ieject[6] = "1     ";
    static char eject[6] = "EJECT ";
    static char srfnam[6*3] = "DS    " "PS    " "CS    ";
    static char htabp[6] = "TABPRT";
    static char hsspr[6] = "SSPRT ";
    static char hsstt[6] = "SSTEST";
    static char havpr[6] = "AVPRT ";
    static integer itbprt = 20130;
    static integer ilbprt = 20160;
    static char hdolpc[6] = "$PCRTH";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
#define j ((integer *)&bgeom_1 + 2)
#define k ((integer *)&comp26_1 + 11)
#define l ((integer *)&bgeom_1 + 3)
    static integer m, n, i1, i2, k1, l1, k5, ii, jj, ll, ipc, jjj;
#define isc ((integer *)&cfsize_1 + 205)
#define ksc ((integer *)&cfsize_1 + 206)
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
    static integer lpc, inp[20];
#define top ((integer *)&stklst_1)
    extern integer name_(char *, ftnlen);
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
    static integer jarg;
#define meta ((integer *)&srctbl_1 + 2)
#define bool ((integer *)&modx_1 + 22)
#define repl ((integer *)&il_1 + 16)
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
    static integer itop;
#define test ((integer *)&comp26_1 + 5)
    static char surf[6];
    static integer idum1, idum2, iflag, idect;
#define nmmac ((integer *)&macseg_1 + 2)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
#define three ((integer *)&numptr_1 + 5)
    static char lrarg[6];
#define alopn ((logical *)&macseg_1)
#define slash ((integer *)&code_1 + 8)
#define nmseg ((integer *)&macseg_1 + 1)
    static integer iparm;
#define nlast ((integer *)&ntbl_1 + 3)
#define onept ((integer *)&numptr_1 + 3)
#define seqno ((integer *)&seqcom_1)
#define point ((integer *)&modx_1 + 18)
    static integer errpt;
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen),
	     maclbl_(integer *, integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
#define argcnt ((integer *)&comp26_1 + 1)
#define permid ((integer *)&code_1 + 38)
#define cantop ((integer *)&cfsize_1)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define cansiz ((integer *)&cfsize_1 + 5)
#define quidlr ((integer *)&opmod_1 + 5)
#define vector ((integer *)&modx_1 + 19)
#define modulo ((integer *)&moduli_1)
#define nought ((integer *)&opmod_1)
#define maxsiz ((integer *)&cfsize_1 + 3)
#define itmpct ((integer *)&macseg_1 + 4)
#define jumpto ((integer *)&doloop_1)
#define itmpsv ((integer *)&macxx5_1)
#define zeropt ((integer *)&numptr_1 + 1)
#define lmrstr ((logical *)&macseg_1 + 3)
    static logical pointx;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *), opcode_(integer *), onearg_(integer *), argcvt_(
	    integer *), rlslin_(void), foutxx_(integer *, char *, integer *, 
	    ftnlen), mcxtrn_(integer *, integer *, integer *);
    static integer idummy;
    extern /* Subroutine */ int callzz_(integer *), twoarg_(integer *, 
	    integer *);
    static integer kpcrth;
    extern /* Subroutine */ int libopc_(integer *, integer *), libsch_(char *,
	     integer *, ftnlen), puttmp_(integer *);
    static integer ierror;
    extern integer gettmp_(integer *);
    static integer newtop;
    extern /* Subroutine */ int refgen_(integer *, integer *), findme_(
	    integer *, char *, integer *, ftnlen), rdsatz_(integer *, integer 
	    *, integer *, integer *, integer *), clospe_(integer *, integer *)
	    ;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */
/* THREE:       NAMTBL POINTER TO '3     ' */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */

/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */
/* ISC:         POINTER TO LAST KSC ENTRY */
/* KSC:         CONTAINS SYMBOL,SIZE AND NUMBER OF SEQMENTS OF SS-DEFIN. */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* POINT:       MODE CODE (19) FOR POINT */
/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* REAL:        MODE CODE (21) FOR A SCALAR */
/* BOOL:        MODE CODE (23) FOR BOOLEAN TYPE */

/*      25A.    MACRO PROCESSING ARRAY */

/* ITMPSV:      TEMPORARY STORAGE DURING FINAL MACRO PROCESSING */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* DLR:         CONTAINS OPERAND TYPE CODE 1 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       30.    NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK */


/*       31.    COMMON BLOCK FOR PRO026 AND MOTION */

/* ARGCNT:      POINTER FOR CURRENT ARGSTK ELEMENT */
/* TEST:        NAMTBL INDEX OF CURRENT ARGUMENT */
/* K:           NAMTBL POINTER TO MAJOR WORD */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* ELFIL1:      OUTPUT OF PACKING FACTOR FOR CREATING PAGES (INTERPRETER) */

/*       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE */


/* ...                SYSTEM I/O FILES */



/* J:           PASSES PUNCH/ARGUMENT FROM PRO026 TO PRO027 */
/* L:           PASSES PUNCH/LISTON OR NOLIST FROM PRO026 TO PRO027 */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* ALOPN:       TRUE AFTER MACRO OR PART PROGRAM SEGMENT LIBRARY OPENED */
/* NMSEG:       NAMTBL POINTER TO THE NAME OF THE PART PROGRAM SEGMENT */
/* NMMAC:       NAMTBL POINTER TO SYSTEM MACRO NAME */
/* LMRSTR:      FLAG ON STARTS READING IN A SYSTEM MACRO */
/* ITMPCT:      NUMBER OF INTERNAL SYMBOLS GENERATED IN TRANSLATION */

/*       39.    COMMON BLOCK LIBRARY PRINTING FLAG */
/*              FLAG ON CAUSE PRINTING OF INPUT LIBRARIES */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/*       43.    DO LOOP CONTROL VALUES */

/* JUMPTO:      MARKER SET AFTER JUMPTO OR IF FOR LABEL CONTROL */
/* * */
/* ARGUMENTS    IGOTO   INTEGER USED BY PRO027 TO BRANCH */
/*                      TO APPROPRIATE CODING */



/* ********************************************************************* */
/*              SYN  PRINT POCKET  PUNCH   CALL   READ */
    switch (*igoto) {
	case 1:  goto L2800;
	case 2:  goto L1942;
	case 3:  goto L1968;
	case 4:  goto L8110;
	case 5:  goto L5700;
	case 6:  goto L5700;
	case 7:  goto L4000;
	case 8:  goto L3800;
    }

/* ...     **** SYNONYM PROCESSING **** */

/* ... CALL ALARM IF THE SYN STATEMENT HAS NO ARGUMENTS OR AN ODD NUMBER */
/* ... OF ARGUMENTS */

L2800:
    n = *argtop / 2;
    if (*argtop != 0) {
	goto L2805;
    }
    i__1 = *top - 1;
    alarm_(&c__2018, &i__1, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
L2805:
    if (*argtop == n << 1) {
	goto L2810;
    }
    alarm_(&c__2018, &c_n1, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
/*   ENTSCHEIDUNG WIE DIE SYN/-PAARE ZU INTERPRETIREN SIND */
/*   ANNAHME: SYN/SYNONYM,SPRACHWORT */
L2810:
    i1 = 0;
    i2 = -1;
/*   ANDERNFALLS:WERTE VON I1 UND I2 VERTAUSCHEN */
    if (nametb_1.namtbl[argstk[*argtop - 1] - 1] == permid[0]) {
	goto L2812;
    }
    i1 = -1;
    i2 = 0;

/* ... PROCESS EACH PAIR OF ARGUMENTS */

L2812:
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k1 = (i__ << 1) + i1;
	*k = argstk[k1 - 1];
	l1 = (i__ << 1) + i2;
	*l = argstk[l1 - 1];
	if (*k == *l) {
	    goto L2850;
	}
	if (nametb_1.namtbl[*l - 1] / *modulo != temp[0] / *modulo) {
	    goto L2815;
	}
	++(*itmpct);
	i__2 = -(*itmpct);
	maclbl_(l, &i__2, j);
	nametb_1.namtbl[*j - 1] = vbl[0] + *real__;
	resrvz_(j, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1);
	opcode_(repl);
	onearg_(&c__1);
	argcvt_(j);
	argcvt_(l);
	rlslin_();
	*l = *j;

/* ... IF THE SYNONYM IS A NUMBER,A SYNONYM FOR ITSELF, OR A SYNONYM FOR */
/* ... A SPECIAL APT WORD FOR WHICH SYNONYMS ARE NOT ALLOWED,CALL ALARM */

L2815:
	jj = *l;
	ll = l1;
L2825:
	if (jj > nametb_1.nammax) {
	    goto L2836;
	}
	i__2 = syntop;
	for (*j = 1; *j <= i__2; ++(*j)) {
	    if (s_cmp(cnamtb_1.cnamtb + (jj - 1) * 6, synlst + (*j - 1) * 6, (
		    ftnlen)6, (ftnlen)6) == 0) {
		goto L2830;
	    }
/* L2820: */
	}
L2836:
	if (jj == *k) {
	    goto L2840;
	}
	jj = *k;
	ll = k1;
	goto L2825;
L2830:
	i__2 = -ll;
	alarm_(&c__2019, &i__2, &c__8, "PRO027  ", (ftnlen)8);
	goto L2850;

/* ... IF THE SYNONYM IS NOT A PERMANENT IDENTIFIER,ISSUE A WARNING */

L2840:
	if (nametb_1.namtbl[*k - 1] == permid[0]) {
	    goto L2845;
	}
	if (*k > nametb_1.nammax && *l > nametb_1.nammax) {
	    goto L2830;
	}
	*k = argstk[l1 - 1];
	*l = argstk[k1 - 1];
	k1 = l1;
	if (nametb_1.namtbl[*k - 1] != permid[0]) {
	    goto L2846;
	}
	goto L2849;
L2845:
	if (nametb_1.namtbl[*l - 1] != permid[0]) {
	    goto L2849;
	}
L2846:
	i__2 = -k1;
	alarm_(&c__2035, &i__2, &c__4, "PRO027  ", (ftnlen)8);

/* ... SET THE FIRST ITEM OF THE SYNONYMS NAMTBL ENTRY = MINUS THE NAMTBL */
/* ... INDEX OF THE ASSOCIATED WORDS ENTRY */

L2849:
	nametb_1.namtbl[*k - 1] = -(*l);
L2850:
	;
    }
    goto L22;

/* ...       PRINT STATEMENT */

L1942:
    if (*argtop > 0) {
	goto L8010;
    }
    errpt = *top - 1;
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, eject, (
	    ftnlen)6, (ftnlen)6) != 0) {
	goto L8015;
    }
    foutxx_(&symfil_1.elfil1, ieject, &c__1, (ftnlen)6);
    if (*jumpto != 0) {
	*jumpto = *seqno + 2;
    }
    goto L22;
L8015:
    alarm_(&c__2030, &errpt, &c__4, "PRO027  ", (ftnlen)8);
    goto L22;
L8008:
    errpt = 1 - *argtop;
L8009:
    alarm_(&c__2031, &errpt, &c__4, "PRO027  ", (ftnlen)8);
    goto L22;
L8010:
    *j = argstk[*argtop - 1];
    errpt = -(*argtop);
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, eject, (
	    ftnlen)6, (ftnlen)6) == 0) {
	goto L8009;
    }
    ii = 1;
    if (*j <= nametb_1.nammax) {
	goto L8011;
    }
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    *j -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, j, &idummy);
    }
    i__ = 7;
    if (s_cmp(cnamtb_1.cnumtb + (*j - 1) * 12, cnamtb_1.cnumtb + (*zeropt - 
	    nametb_1.nammax - 1) * 12, (ftnlen)12, (ftnlen)12) == 0) {
	goto L8020;
    }
    if (s_cmp(cnamtb_1.cnumtb + (*j - 1) * 12, cnamtb_1.cnumtb + (*onept - 
	    nametb_1.nammax - 1) * 12, (ftnlen)12, (ftnlen)12) == 0) {
	goto L8020;
    }
    goto L8030;
L8011:
    i__ = 8;
    if (nametb_1.namtbl[*j - 1] == ilbprt || nametb_1.namtbl[*j - 1] - *
	    modhlf == ilbprt) {
	goto L6000;
    }
    if (nametb_1.namtbl[*j - 1] == itbprt || nametb_1.namtbl[*j - 1] - *
	    modhlf == itbprt) {
	goto L8025;
    }
    i__ = 11;
L8019:
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hon, (ftnlen)6, (ftnlen)6) == 0)
	     {
	goto L8020;
    }
    ++i__;
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hoff, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8020;
    }
    switch (ii) {
	case 1:  goto L8030;
	case 2:  goto L8008;
    }
L8020:
    callzz_(k);
    twoarg_(quidlr, &i__);
    argcvt_(j);
    twoarg_(quidlr, &c__1);
    rlslin_();
    errpt = ii - *argtop;
    if (*argtop > ii) {
	goto L8009;
    }
    goto L22;
L8025:
    jj = *j;
    ii = 2;
    *j = argstk[*argtop - 2];
    i__ = 16;
/*     PRINT/TABPRT,ON/OFF */
    if (s_cmp(cnamtb_1.cnamtb + (jj - 1) * 6, htabp, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8019;
    }
    i__ = 18;
/*     PRINT/SSPRT ,ON/OFF */
    if (s_cmp(cnamtb_1.cnamtb + (jj - 1) * 6, hsspr, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8019;
    }
    i__ = 20;
/*     PRINT/SSTEST,ON/OFF */
    if (s_cmp(cnamtb_1.cnamtb + (jj - 1) * 6, hsstt, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8019;
    }
    i__ = 22;
/*     PRINT/AVPRT,ON/OFF */
    if (s_cmp(cnamtb_1.cnamtb + (jj - 1) * 6, havpr, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8019;
    }
    if (*argtop == 1) {
	goto L8035;
    }
    goto L8009;
L8030:
    bcdbin_(cnamtb_1.cnumtb + (*j - 1) * 12, &m, &n, (ftnlen)12);
    if (m == 2 || m == 3) {
	goto L8032;
    }
    goto L8009;
L6000:
    *j = argstk[*argtop - 2];
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hon, (ftnlen)6, (ftnlen)6) != 0)
	     {
	goto L6010;
    }
    libprt_1.libprt = TRUE_;
    goto L6020;
L6010:
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hoff, (ftnlen)6, (ftnlen)6) != 
	    0) {
	goto L8008;
    }
    libprt_1.libprt = FALSE_;
L6020:
    errpt = 2 - *argtop;
    if (*argtop > 2) {
	goto L8009;
    }
    goto L22;
L8032:
    if (*argtop > 1) {
	goto L8033;
    }
L8035:
    alarm_(&c__2052, &errpt, &c__4, "PRO027  ", (ftnlen)8);
    goto L22;
L8033:
    --(*argtop);
    *j = argstk[*argtop - 1];
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hall, (ftnlen)6, (ftnlen)6) != 
	    0) {
	goto L8036;
    }
    *j = 0;
    if (m == 2) {
	*j = 3;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	++(*j);
	if (blkcfs_1.first[(i__ << 1) - 1] == 0) {
	    goto L8034;
	}
	callzz_(k);
	twoarg_(quidlr, j);
	argcvt_(&blkcfs_1.first[(i__ << 1) - 2]);
	twoarg_(quidlr, &blkcfs_1.first[(i__ << 1) - 1]);
	rlslin_();
L8034:
	;
    }
    if (*argtop > 1) {
	goto L8008;
    }
    goto L6020;
L8036:
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*l = *argtop + 1 - i__;
	*j = argstk[*l - 1];
	n = 10;
	if (*j > nametb_1.nammax) {
	    goto L8050;
	}
	*l = nametb_1.namtbl[*j - 1] % *modulo;
	jj = nametb_1.namtbl[*j - 1] / *modulo * *modulo;
	if (jj != vbl[0]) {
	    goto L8038;
	}
	if (*l > *modhlf) {
	    *l -= *modhlf;
	}
	goto L8040;
L8038:
	if (jj == temp[0]) {
	    goto L8040;
	}
	if (jj == number[0] && *l == *modhlf) {
	    goto L8050;
	}
	i__2 = i__ - 1 - *argtop;
	alarm_(&c__2031, &i__2, &c__4, "PRO027  ", (ftnlen)8);
	goto L8060;
L8040:
	n = 1;
	if (*l == *real__ || *l == *bool) {
	    goto L8045;
	}
	n = 2;
	if (*l == *real__ + *modhlf || *l == *bool + *modhlf) {
	    goto L8045;
	}
	n = 3;
L8045:
	if (m == 2) {
	    n += 3;
	}
L8050:
	callzz_(k);
	twoarg_(quidlr, &n);
	argcvt_(j);
	twoarg_(quidlr, &c__1);
	rlslin_();
L8060:
	;
    }
    goto L22;
/* ...       POCKET STATEMENT */

L1968:
    errpt = -1;
    if (*argtop < 1) {
	errpt = *top - 1;
    }
    if (*argtop < 11) {
	goto L1974;
    }
    errpt = 28 - *argtop;
    if (*argtop > 28) {
	goto L1974;
    }
    for (ipc = 1; ipc <= 8; ++ipc) {
	*argcnt = *argtop + 1 - ipc;
	errpt = -(*argcnt);
	*test = mode_(&argstk[*argcnt - 1]);
	if (*test != *real__) {
	    goto L1974;
	}
/* L1969: */
    }
    jarg = *argtop - 8;
    i__1 = jarg;
    for (ipc = 1; ipc <= i__1; ++ipc) {
	*argcnt = jarg + 1 - ipc;
	*test = mode_(&argstk[*argcnt - 1]);
	errpt = -(*argcnt);
	if (*test != *point) {
	    goto L1974;
	}
/* L1970: */
    }
    kpcrth = name_(hdolpc, (ftnlen)6);
    if (nametb_1.namtbl[kpcrth - 1] != 0) {
	goto L1972;
    }
    nametb_1.namtbl[kpcrth - 1] = vbl[0];
    resrvz_(&kpcrth, &c__0, &c__98, &c__1);
L1972:
    i__1 = jarg;
    for (ipc = 1; ipc <= i__1; ++ipc) {
	*argcnt = jarg + 1 - ipc;
	lpc = 2 - ipc * 3;
	opcode_(repl);
	onearg_(&c__3);
	twoarg_(&lpc, &kpcrth);
	argcvt_(&argstk[*argcnt - 1]);
/* L1973: */
	rlslin_();
    }
    callzz_(k);
    for (ipc = 1; ipc <= 8; ++ipc) {
/* L1971: */
	argcvt_(&argstk[*argtop + 1 - ipc - 1]);
    }
    twoarg_(quidlr, &jarg);
    twoarg_(nought, &kpcrth);
    rlslin_();
    goto L22;
L1974:
    alarm_(&c__2034, &errpt, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;


/* ***************** P U N C H   P R O C E S S I N G ****************** */

L8110:
    jj = *j;
    if (*j > 5) {
	goto L8112;
    }
    if (*argtop > 1) {
	i__1 = -(*argtop);
	alarm_(&c__2031, &i__1, &c__4, "PRO027  ", (ftnlen)8);
    }
L8112:
    switch (*j) {
	case 1:  goto L8160;
	case 2:  goto L8160;
	case 3:  goto L8180;
	case 4:  goto L8115;
	case 5:  goto L8115;
	case 6:  goto L8140;
	case 7:  goto L7100;
	case 8:  goto L7100;
    }
/*            1    2    3    4    5    6 */

/* ... J IS 4 OR 5 FOR LISTON OR NOLIST.  GENERATE CALL TOPRINT */
/*     WITH CODE=J+9. */

L8115:
    *k = name_(srprnt, (ftnlen)6);
    i__ = *j + 9;
    *j = *l;
    ii = *argtop;
    goto L8020;

/* ... INVALID ARGUMENT. */
L8120:
    alarm_(&c__2031, &errpt, &c__4, "PRO027  ", (ftnlen)8);
    goto L8150;

/* ...  VALIDATE LIST ITEMS AND GENERATE CALL I.L. */

L8140:
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*j = *argtop + 1 - i__;
	errpt = -(*j);
	*l = argstk[*j - 1];
	if (*l > nametb_1.nammax) {
	    goto L8120;
	}
	if (nametb_1.namtbl[*l - 1] / *modulo != vbl[0] / *modulo && (
		nametb_1.namtbl[*l - 1] / *modulo != temp[0] / *modulo || 
		nametb_1.namtbl[*l - 1] / *modulo == temp[0] / *modulo && 
		nametb_1.namtbl[*l - 1] - temp[0] <= *modhlf)) {
	    goto L8120;
	}

/* ... SET J = THE NUMBER OF THE BLOCK WHICH */
/* ... CONTAINS THE CANONICAL FORM. */

	*j = 3;
	if (nametb_1.namtbl[*l - 1] % *modulo == *real__) {
	    *j = 1;
	}
	if (nametb_1.namtbl[*l - 1] - temp[0] == *modhlf + *real__) {
	    *j = 2;
	}
	if (jj <= 6) {
	    goto L7200;
	}
	*j = jj - 3;
	jjj = nametb_1.namtbl[*l - 1] - vbl[0];
	if (nametb_1.namtbl[*l - 1] / *modulo == temp[0] / *modulo) {
	    jjj = nametb_1.namtbl[*l - 1] - temp[0] - *modhlf;
	}
	if (jjj == 11 || jjj == 12 || jjj == 26 || jjj == 29 || jjj == 30) {
	    goto L7200;
	}
	goto L8120;
L7200:
	callzz_(k);
	twoarg_(quidlr, j);
	argcvt_(l);
	twoarg_(quidlr, &c__1);
	rlslin_();
L8150:
	;
    }
    goto L22;

/* ... PUNCH ALL SCALARS */

L8160:
    for (i__ = 1; i__ <= 2; ++i__) {
	if (blkcfs_1.first[(i__ << 1) - 1] == 0) {
	    goto L8170;
	}
	callzz_(k);
	twoarg_(quidlr, &i__);
	argcvt_(&blkcfs_1.first[(i__ << 1) - 2]);
	twoarg_(quidlr, &blkcfs_1.first[(i__ << 1) - 1]);
	rlslin_();
L8170:
	;
    }
    if (*j == 2) {
	goto L22;
    }

/* ... PUNCH ALL SURFACES */

L8180:
    if (blkcfs_1.first[5] == 0) {
	goto L22;
    }
    callzz_(k);
    twoarg_(quidlr, &c__3);
    argcvt_(&blkcfs_1.first[4]);
    twoarg_(quidlr, &blkcfs_1.first[5]);
    rlslin_();
    goto L22;

/* ...     SYSTEM MACRO AND SEGMENT READ */

L5700:
    if (*nmseg != 0 || *nmmac != 0) {
	goto L5770;
    }
    if (*argtop == 0) {
	*j = 0;
    } else {
	*j = argstk[*argtop - 1];
    }
    errpt = -(*argtop);
    if (*top < 9) {
	goto L5705;
    }
    *j = stack[(*top - 5 << 1) - 2];
    errpt = *top - 5;
L5705:
    if (*j > nametb_1.nammax) {
	goto L7000;
    }
    if (*alopn) {
	goto L5710;
    }
    libopc_(&c__1, &iflag);
    if (iflag != 0) {
	goto L5760;
    }
    *alopn = TRUE_;
L5710:
    s_copy(lrarg, cnamtb_1.cnamtb + (*j - 1) * 6, (ftnlen)6, (ftnlen)6);
    libsch_(lrarg, &iflag, (ftnlen)6);
    if (*igoto == 5) {
	goto L5720;
    }
    if (iflag != 0) {
	goto L5780;
    }
    *nmseg = *j;
    if (nametb_1.namtbl[*nmseg - 1] / *modulo == permid[0] / *modulo) {
	nametb_1.namtbl[*nmseg - 1] = ident[0];
    }
    goto L22;
L5720:
    if (iflag != 0) {
	goto L5785;
    }
    *nmmac = *j;
    *lmrstr = TRUE_;
    itmpsv[1] = *top + 1;
    if (*top >= 9) {
	itmpsv[1] = *top - 1;
    }
    *k = *top - 1;
    i__1 = *k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	itmpsv[i__ * 2] = stack[(i__ << 1) - 2];
	itmpsv[(i__ << 1) + 1] = stack[(i__ << 1) - 1];
/* L5730: */
    }
    if (*top >= 9) {
	goto L5740;
    }
    itmpsv[6] = slash[1];
    i__ = slash[0] / *modulo;
    itmpsv[7] = meta[i__ - 1];
    itmpsv[8] = *nmmac;
L5735:
    if (nametb_1.namtbl[*nmmac - 1] / *modulo == permid[0] / *modulo) {
	nametb_1.namtbl[*nmmac - 1] = ident[0];
    }
    goto L22;
L5740:
    i__ = stack[(*top - 1 << 1) - 2];
    if (i__ > nametb_1.nammax) {
	goto L5735;
    }
    *j = nametb_1.namtbl[i__ - 1];
    if (*j / *modulo != temp[0] / *modulo) {
	goto L5735;
    }
    if (*j - temp[0] != *real__) {
	goto L5755;
    }
    ++(*itmpct);
    i__1 = -(*itmpct);
    maclbl_(&i__, &i__1, &ii);
    nametb_1.namtbl[ii - 1] = vbl[0] + *real__;
    resrvz_(&ii, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1);
    opcode_(repl);
    onearg_(&c__1);
    argcvt_(&ii);
    argcvt_(&i__);
    rlslin_();
    puttmp_(real__);
    itmpsv[16] = ii;
    i__ = vbl[0] / *modulo;
    itmpsv[17] = meta[i__ - 1];
    goto L5735;

L5750:
    ierror = 2001;
    goto L5790;
L5755:
    ierror = 1023;
    errpt = *top - 1;
    *nmmac = 0;
    *lmrstr = FALSE_;
    goto L5790;
L5760:
    ierror = 72;
    goto L5790;
L5770:
    ierror = 71;
    goto L5790;
L5780:
    ierror = 73;
    goto L5790;
L5785:
    ierror = 17;
L5790:
    alarm_(&ierror, &errpt, &c__8, "PRO027  ", (ftnlen)8);

L22:
    return 0;

/* ...  INDIRP  ENTRY */
L4000:
    pointx = TRUE_;
    goto L4001;
/* ..................................... */
/* ...  INDIRV  ENTRY */
/* ...  SRFVCT  ENTRY */
L3800:
    pointx = FALSE_;
/* ...   SET UP IMPLIED SURFACES  DS,PS,CS. */
L4001:
    for (iparm = 1; iparm <= 3; ++iparm) {
	s_copy(surf, srfnam + (iparm - 1) * 6, (ftnlen)6, (ftnlen)6);
	idect = name_(surf, (ftnlen)6);
/* ...  IS FIRST ITEM PERMID */
	*test = argstk[*argtop - 1];
	if (*test > nametb_1.nammax) {
	    goto L4007;
	}
	if (nametb_1.namtbl[*test - 1] / *modulo != permid[0] / *modulo) {
	    goto L4007;
	}
/* ...  IS FIRST WORD PS,DS, OR CS */
	--(*argtop);
	if (nametb_1.namtbl[*test - 1] - permid[0] == 1 || nametb_1.namtbl[*
		test - 1] - permid[0] == 501) {
	    goto L3719;
	}
/* ...  IMPROPER PERMID */
	i__1 = -(*argtop) - 1;
	alarm_(&c__2010, &i__1, &c__4, "PRO027  ", (ftnlen)8);
	goto L4007;

L3719:
	idect = *test;
/* ...  SYMBOLIC OR NESTED DEFINITION OF VECTOR OR POINT YES,NO. */
L4007:
	*test = mode_(&argstk[*argtop - 1]);
	if (pointx && *test == *point || ! pointx && *test == *vector) {
	    goto L4008;
	}
/* ...  NO.    CHECK  FOR THREE SCALARS. */
	for (i__ = 1; i__ <= 3; ++i__) {
	    itop = *argtop - i__ + 1;
	    errpt = -itop;
	    if (mode_(&argstk[itop - 1]) != *real__) {
		goto L4017;
	    }
/* L4010: */
	}
/* ...  GET A TEMPORARY FOR A POINT OR VECTOR */
	if (! pointx) {
	    goto L3705;
	}
	*test = gettmp_(point);
	goto L3706;
L3705:
	*test = gettmp_(vector);
/* ...  ASSIGN TEMPORARY STORAGE */
L3706:
	opcode_(move);
	argcvt_(test);
	argcvt_(&argstk[*argtop - 1]);
	argcvt_(&argstk[*argtop - 2]);
	argcvt_(&argstk[*argtop - 3]);
	rlslin_();
	newtop = *argtop - 3;
	goto L3721;
L4008:
	*test = argstk[*argtop - 1];
	newtop = *argtop - 1;
/* ...  OUTPUT PROCEDURE CALL */
L3721:
	if (newtop != *argtop - 3) {
	    goto L4026;
	}
	if (pointx) {
	    goto L4022;
	}
	m = *vector;
	n = 3;
	goto L4024;
L4022:
	m = *point;
	n = 1;
L4024:
	refgen_(&n, test);
	puttmp_(&m);
L4026:
	callzz_(k);
	argcvt_(&idect);
	argcvt_(test);
	rlslin_();
/* L4028: */
	*argtop = newtop;
	if (*argtop == 0) {
	    goto L22;
	}
/* L4090: */
    }
    errpt = -(*argtop);
L4017:
    alarm_(&c__2011, &errpt, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
/*    TEST AUF READ/1,... */
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L7000:
    *j -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, j, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (*j - 1) * 12, &m, &n, (ftnlen)12);
    if (m != 1) {
	goto L5750;
    }
    --(*argtop);
    if (*argtop == 0) {
	goto L5750;
    }
L7001:
    *j = argstk[*argtop - 1];
    k5 = nametb_1.namtbl[*j - 1] / *modulo * *modulo;
    if (k5 != vbl[0] && k5 != temp[0]) {
	goto L7010;
    }
/*   EINLESEUEBERPRUEFUNG FUER INDIZIERTE VARIABLE IN RESRED */
    if (k5 == temp[0] && nametb_1.namtbl[*j - 1] - k5 > *modhlf) {
	goto L7060;
    }
    i__1 = -(*argtop);
    alarm_(&c__1001, &i__1, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
/*  LESEN VON 'APTLIB' */
L7010:
    if (*alopn) {
	goto L7020;
    }
    libopc_(&c__1, &iflag);
    if (iflag != 0) {
	goto L5760;
    }
    *alopn = TRUE_;
L7020:
    s_copy(lrarg, cnamtb_1.cnamtb + (*j - 1) * 6, (ftnlen)6, (ftnlen)6);
    findme_(&symfil_1.ldafil, lrarg, &iflag, (ftnlen)6);
    if (iflag != 0) {
	goto L5780;
    }
/*    READ THE FIRST RECORD */
    rdsatz_(&symfil_1.ldafil, inp, &idum1, &idum2, &iflag);
    if (iflag != 0) {
	goto L5780;
    }
/* FLAECHEN-ART */
    m = inp[4];
/*  GEOMETRIE QUALIFIZIEREN */
    nametb_1.namtbl[*j - 1] = vbl[0] + m;
/*   SPEICHER RESERVIEREN */
    resrvz_(j, &m, &tmp_1.txxxx[(m << 1) - 2], &c__1);
/* IN INP(8) IST DIE LAENGE DER KANONISCHEN FORM GESPEICHERT */
/*  MAXSIZ,WENN NOETIG AENDERN */
    if (inp[7] <= abs(maxsiz[1])) {
	goto L7040;
    }
    if (inp[7] <= abs(maxsiz[0])) {
	goto L7030;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = inp[7];
    goto L7040;
L7030:
    maxsiz[1] = inp[7];
/* NACH FREIEM PLATZ ABFRAGEN */
L7040:
    i__1 = *isc;
    for (i__ = 4; i__ <= i__1; ++i__) {
	if (*j == ksc[i__ * 3 - 3]) {
	    goto L7048;
	}
/* L7045: */
    }
    ++(*isc);
    if (*isc <= 300) {
	goto L7047;
    }
    i__1 = -(*argtop);
    alarm_(&c__34, &i__1, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
L7047:
    ksc[*isc * 3 - 3] = *j;
    ksc[*isc * 3 - 2] = inp[7];
L7048:
    jj = *j % *cantop;
    i__1 = *cantop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = jj % *cantop + 1;
	if (cansiz[(jj << 1) - 2] != 0 && cansiz[(jj << 1) - 1] != *j) {
	    goto L7050;
	}
	cansiz[(jj << 1) - 2] = inp[7];
	cansiz[(jj << 1) - 1] = *j;
	goto L7060;
L7050:
	;
    }
    i__1 = -(*argtop);
    alarm_(&c__53, &i__1, &c__8, "PRO027  ", (ftnlen)8);
    goto L22;
/*  AUSGABE DES BEFEHLES 'READ/1,NAME' */
L7060:
    callzz_(k);
    twoarg_(quidlr, &c__1);
    argcvt_(j);
    twoarg_(dlr, one);
    rlslin_();
/* SCHLIESSEN DES PDS-LESENS */
    if (*alopn) {
	clospe_(&symfil_1.ldafil, &iflag);
    }
    *alopn = FALSE_;
    --(*argtop);
    errpt = -(*argtop);
    if (*argtop > 0) {
	goto L7001;
    }
    goto L22;
/*     VERARBEITUNG DER SONDER-PUNCH-ANWEISUNG */
L7100:
    *j = 6;
    --(*argtop);
    if (*argtop != 0) {
	goto L8140;
    }
    i__1 = *top - 1;
    alarm_(&c__2030, &i__1, &c__4, "PRO027  ", (ftnlen)8);
    goto L22;
} /* pro027_ */

#undef lmrstr
#undef zeropt
#undef itmpsv
#undef jumpto
#undef itmpct
#undef maxsiz
#undef nought
#undef modulo
#undef vector
#undef quidlr
#undef cansiz
#undef argtop
#undef argstk
#undef number
#undef cantop
#undef permid
#undef argcnt
#undef modhlf
#undef point
#undef seqno
#undef onept
#undef nlast
#undef nmseg
#undef slash
#undef alopn
#undef three
#undef stack
#undef ident
#undef nmmac
#undef test
#undef move
#undef temp
#undef repl
#undef bool
#undef meta
#undef real__
#undef top
#undef vbl
#undef dlr
#undef one
#undef ksc
#undef isc
#undef l
#undef k
#undef j


