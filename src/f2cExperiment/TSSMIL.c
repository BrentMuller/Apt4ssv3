/* TSSMIL.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer cfsize[205];
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
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer sublst[135];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* Table of constant values */

static integer c__1 = 1;
static integer c_n2 = -2;
static integer c__2052 = 2052;
static integer c__8 = 8;
static integer c__2021 = 2021;
static integer c__2001 = 2001;

/* *** SOURCE FILE : M0006690.W06   *** */


/*              FORTRAN SUBROUTINE TSSMIL */

/* LINKAGE      SUBROUTINE TSSMIL */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    PRO026 */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    BINBCD */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    CONCAT */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int tssmil_(void)
{
    /* Initialized data */

    static char dps[6*2] = "DS    " "PS    ";
    static char blank[4] = "    ";
    static integer offset = 25;
    static char smil[6*6] = "SCON  " "SMIL  " "GOMILL" "GCLEAR" "INTSEC" 
	    "AVCTRL";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, j, k, l, gl, kk, mm, nn, tp, nch, arg[5], loc[4];
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
    static integer sub;
#define top ((integer *)&stklst_1)
    static integer typ, tpt2, iend;
    extern integer name_(char *, ftnlen);
#define real__ ((integer *)&modx_1 + 20)
#define line ((integer *)&modx_1)
    extern integer numb_(char *, ftnlen);
#define repl ((integer *)&il_1 + 16)
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
    static integer prod;
    static char ibuff[15];
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define canon ((integer *)&code_1 + 82)
#define plane ((integer *)&modx_1 + 1)
#define ident ((integer *)&code_1 + 68)
    static integer sname;
#define stack ((integer *)&stklst_1 + 3)
    static integer class__, index, lprod, jnull;
#define onept ((integer *)&numptr_1 + 3)
#define point ((integer *)&modx_1 + 18)
    static integer errpt;
#define ssurf ((integer *)&modx_1 + 28)
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
    extern integer search_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int concat_(char *, char *, ftnlen, ftnlen);
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define dottab ((integer *)&bcdptr_1 + 6)
#define permid ((integer *)&code_1 + 38)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)
    extern /* Subroutine */ int callzz_(integer *), argcvt_(integer *), 
	    twoarg_(integer *, integer *), rlslin_(void);
#define maxsiz ((integer *)&cfsize_1 + 3)
    static integer nowrds;
#define zeropt ((integer *)&numptr_1 + 1)
#define aptxxx ((integer *)&sublst_1)

    /* Fortran I/O blocks */
    static icilist io___54 = { 0, ibuff, 0, "(I3)", 3, 1 };
    static icilist io___55 = { 0, ibuff, 0, "(I3)", 3, 1 };





/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/* CANON:       (1)=CODE CLASS 42000,(2)=NAMTBL INDEX OF 'CANON ' */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC ,PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* LINE:        MODE CODE ( 1) FOR LINE */
/* PLANE:       MODE CODE ( 2) FOR PLANE */
/* POINT:       MODE CODE (19) FOR POINT */
/* REAL:        MODE CODE (21) FOR A SCALAR */
/* SSURF:       MODE CODE (29) FOR SCULPTURED SURFACE */

/*       27.    OPERAND MODIFIERS */

/* DLR:         CONTAINS OPERAND TYPE CODE 1 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* ** */
/*     PREPARE MODES AND PERMANENT IDENTIFIERS OF THE ARGSTK ARGUMENTS */
/*          AND MOVE THEM TO STACK(2,TOP+1) AND HIGHER ADDR. */

    if (*argtop < 1) {
	goto L4000;
    }
    tp = *top + 1;
    stack[(tp << 1) - 1] = -1;
    i__1 = *argtop;
    for (errpt = 1; errpt <= i__1; ++errpt) {
	nn = 0;
	j = argstk[errpt - 1];
	if (j > nametb_1.nammax) {
	    goto L20;
	}
	class__ = nametb_1.namtbl[j - 1] / *modulo * *modulo;
	mm = nametb_1.namtbl[j - 1] - class__;
	if (mm > *modhlf) {
	    mm -= *modhlf;
	}
	if (class__ != permid[0] && class__ != canon[0]) {
	    goto L10;
	}
	nn = 50;
	mm += nn;
	goto L30;
L10:
	if (class__ == vbl[0] || class__ == temp[0] || mm == offset) {
	    goto L30;
	}
	if (class__ != number[0]) {
	    goto L4030;
	}
L20:
	mm = *real__;
L30:
	++tp;
	stack[(tp << 1) - 2] = mm - nn;
/* L40: */
	stack[(tp << 1) - 1] = gmty_1.pmidtb[mm - 1];
    }


/*     BRANCH IF INTSEC STATEMENT OR DEFINE START OF SEARCHING */

    sname = stack[(*top - 1 << 1) - 2];
    for (typ = 1; typ <= 6; ++typ) {
	if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, 
		smil + (typ - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L50;
	}
	switch (typ) {
	    case 1:  goto L60;
	    case 2:  goto L60;
	    case 3:  goto L70;
	    case 4:  goto L65;
	    case 5:  goto L2000;
	    case 6:  goto L72;
	}
L50:
	;
    }
    errpt = 1 - *top;
    goto L4060;

/*                   START OF SCON/, SMIL/ PRODUCTIONS */
L60:
    gl = gmty_1.geoloc[49];
    goto L75;
/*                   START OF GCLEAR/ PRODUCTIONS */
L65:
    gl = gmty_1.geoloc[45];
    lprod = 1;
    for (i__ = 1; i__ <= 4; ++i__) {
	arg[i__ - 1] = 1;
/* L66: */
	loc[i__ - 1] = 0;
    }
    arg[4] = 1;
    goto L76;
/*                  START OF GOMILL/ PRODUCTIONS */
L70:
    gl = gmty_1.geoloc[46];
    goto L75;
/*                  START OF AVCTRL/ PRODUCTIONS */
L72:
    gl = gmty_1.geoloc[44];

/*     SEARCH FOR THE PRODUCTION NUMBER AND BRANCH */

L75:
    lprod = 0;
L76:
    kk = *argtop;
    iend = 0;
L80:
    errpt = kk;
    tpt2 = tp << 1;
    prod = search_(stack, &tpt2, &gmty_1.geomtb[gl - 1], &errpt);
    if (prod == 200) {
	goto L4050;
    }
    if (lprod > 0) {
	goto L90;
    }
    j = prod / 5 + 1;
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, smil + (
	    j - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	goto L4020;
    }
/*                   PRODUCTION NUMBERS */
/*             1    2    3    4    5    6    7    8    9   10 */
L90:
    switch (prod) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L3000;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L600;
	case 8:  goto L4050;
	case 9:  goto L4050;
	case 10:  goto L1000;
	case 11:  goto L1000;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1600;
	case 16:  goto L1600;
	case 17:  goto L1600;
	case 18:  goto L1600;
	case 19:  goto L1600;
	case 20:  goto L1700;
	case 21:  goto L1700;
	case 22:  goto L1700;
	case 23:  goto L1700;
	case 24:  goto L1650;
	case 25:  goto L1800;
	case 26:  goto L3000;
	case 27:  goto L2700;
	case 28:  goto L2800;
	case 29:  goto L2900;
	case 30:  goto L2950;
    }
/*            11   12   13   14   15   16   17   18   19   20 */
/*            21   22   23   24   25   26   27   28   29   30 */
    goto L4050;

/*     CONTROL OF SCON/INIT,DS,PS,FEED,.... */
/*     NO CONTROL OF MULTIPLE DEFINITIONS */

L100:
    if (kk == 2) {
	goto L3000;
    }
    --tp;
    --kk;
    stack[(tp << 1) - 1] = stack[(tp + 1 << 1) - 1];
    goto L80;

/*     CONTROL OF OPTIONAL 'OFFSET' IN SCON/DS,...... */

L200:
    mm = *argtop;
    nn = 1;
    if (errpt <= 0) {
	goto L610;
    }
    if (stack[(*top + 1 + errpt << 1) - 2] != offset) {
	goto L4030;
    }
    --errpt;
    goto L610;

/*     CONTROL SCON/PS,.... */

L300:
    mm = *argtop;
    nn = 2;
    if (errpt <= 0) {
	goto L610;
    }
    goto L510;

/*     CONTROL SMIL/PATH,..  SMIL/ZIGZAG,... SMIL/PICKFD,.... */

L500:
    mm = *argtop - 1;
    nn = 1;
    if (errpt <= 0) {
	goto L610;
    }

/*     CONTROL OF OPTIONAL 'REAL' */

L510:
    if (stack[(*top + 1 + errpt << 1) - 2] != *real__) {
	goto L4030;
    }
    --errpt;
    goto L610;

/*     CONTROL SMIL/POSN,.. */

L600:
    mm = *argtop - 1;
    nn = 1;

/*     CONTROL OF 'PS' RSP. 'DS' ,BECAUSE BOTH ARE OF SAME MODE AND CLASS */

L610:
    if (s_cmp(cnamtb_1.cnamtb + (argstk[mm - 1] - 1) * 6, dps + (nn - 1) * 6, 
	    (ftnlen)6, (ftnlen)6) != 0) {
	goto L4040;
    }
    goto L3000;

/*     A P T  COMPATIBLE REGIONAL MILLING */

/*     FIRST (STANDARD) PART OF MULTI-CUT SEQUENCE COMMAND */
/*           PRODUCTION 13 MAY, 14 MUST FOLLOW */
/*                        - OR - */
/*     START UP RESP. SINGLE CUT SEQUENCE COMMAND */
/*           PRODUCTION 12 SHOULD , 13 MAY FOLLOW */
L1000:
    if (lprod != 0) {
	goto L4070;
    }
    if (errpt == 0) {
	goto L3000;
    }
L1010:
    tp = errpt + 4;
    kk = errpt;
    lprod = prod;
    goto L80;

/*     START UP COMMAND COMPLETE */
L1200:
    if (lprod != 11) {
	goto L4070;
    }
/* L1210: */
    if (*argtop % 2 == 0) {
	goto L4050;
    }
    goto L3000;

/*     PARAMETERS FOR FOR SINGLE OR MULTI CUT SEQUENCE MILLING */
L1300:
    if (lprod == 11) {
	goto L3000;
    }
    if (lprod != 10) {
	goto L4070;
    }
    goto L1010;

/*     MULTI CUT SEQUENCE COMMAND COMPLETE */
L1400:
    if (lprod == 0) {
	goto L3000;
    }
    if (lprod != 10 && lprod != 13) {
	goto L4070;
    }
    goto L3000;

/*     REGIONAL MILLING GCLEAR COMMAND */

L1600:
    iend = kk;
    if (kk != *argtop) {
	goto L3010;
    }
L1610:
    iend = 0;
    for (i__ = 1; i__ <= 5; ++i__) {
/* L1620: */
	arg[i__ - 1] = 0;
    }
    arg[prod - 15] = 1;
    j = 3;
    goto L1850;

L1650:
    sname = argstk[kk - 2];
L1700:
    nn = prod - 19;
    if (arg[nn - 1] != 0) {
	goto L4070;
    }
    arg[nn - 1] = 1;
    j = 2;
    goto L1860;

L1800:
    iend = kk;
    if (kk != *argtop) {
	goto L3010;
    }
L1810:
    iend = 0;
    for (i__ = 1; i__ <= 5; ++i__) {
/* L1820: */
	arg[i__ - 1] = 1;
    }
    j = 2;
/*   K FOR START=3 , FOR THRU=6 , FOR AWAY=11 , FOR BACK=12 */
L1850:
    k = stack[(tp << 1) - 2] % 10 + 3;
    k /= 3;
    if (loc[k - 1] != 0) {
	goto L4070;
    }
    loc[k - 1] = 1;
L1860:
    if (errpt == 0) {
	goto L3010;
    }
    tp -= j;
    kk -= j;
    goto L80;

/*     INTERSECTION OF PLANE AND SCULPTURED SURFACE */

L2000:
    k = 1;
    j = argstk[k - 1];
    if (nametb_1.namtbl[j - 1] == canon[0] || stack[(*top + 2 << 1) - 2] == 
	    72) {
	k = 2;
    }
    errpt = 1;
    if (stack[(tp << 1) - 2] == *line || stack[(tp << 1) - 2] == *plane) {
	goto L2500;
    }
    if (*argtop <= k) {
	goto L4060;
    }
    j = *top + k + 1;
    l = j + 20;
    errpt = k - 1;
    i__1 = l;
    for (i__ = j; i__ <= i__1; ++i__) {
	++errpt;
	if (stack[(i__ << 1) - 2] != *ssurf) {
	    goto L2020;
	}
/* L2010: */
    }
    goto L4010;
L2020:
    if (stack[(i__ << 1) - 2] != 73) {
	goto L4030;
    }
    j = i__ + 1;
    l = tp;
    if (l < j) {
	goto L4060;
    }
    goto L2520;

L2500:
    if (stack[(tp - 1 << 1) - 2] != 73) {
	goto L2510;
    }
    argstk[*argtop - 2] = argstk[*argtop - 1];
    --(*argtop);
    stack[(tp - 1 << 1) - 2] = stack[(tp << 1) - 2];
    --tp;
L2510:
    if (*argtop <= k) {
	goto L4060;
    }
    errpt = *argtop - 41;
    if (*argtop > k + 40) {
	goto L4010;
    }
    j = *top + k + 1;
    errpt = k - 1;
    l = tp - 1;
L2520:
    i__1 = l;
    for (i__ = j; i__ <= i__1; ++i__) {
	++errpt;
	if (stack[(i__ << 1) - 2] != *ssurf) {
	    goto L4030;
	}
/* L2530: */
    }
    errpt = 0;
    goto L3010;

/* .... AVOIDANCE CONTROL LANGUAGE */

/* .... AVCTRL/ON */
/*            OFF */
L2700:
    sub = stack[(*top - 1 << 1) - 2];
    errpt = 1 - *argtop;
    if (*argtop > 1) {
	goto L4060;
    }
    callzz_(&sub);
    argcvt_(&argstk[*argtop - 1]);
    jnull = name_("NULL  ", (ftnlen)6);
    argcvt_(&jnull);
    argcvt_(zeropt);
    argcvt_(zeropt);
    argcvt_(zeropt);
    argcvt_(&jnull);
    argcvt_(zeropt);
    goto L3200;

/* .... AVCTRL/CUTANG,CONST,GAMMA,RANGE,BLOW,BHIGH */

L2800:
    if (lprod != 0) {
	goto L4070;
    }
    sub = stack[(*top - 1 << 1) - 2];
    jnull = name_("NULL  ", (ftnlen)6);
    callzz_(&sub);
    j = name_("ON    ", (ftnlen)6);
    argcvt_(&j);
    argcvt_(&argstk[*argtop - 1]);
    argcvt_(&argstk[*argtop - 3]);
    argcvt_(&argstk[*argtop - 5]);
    argcvt_(&argstk[*argtop - 6]);
    if (errpt == 0) {
	argcvt_(&jnull);
	argcvt_(zeropt);
	goto L3200;
    } else {
	tp = errpt + 4;
	kk = errpt;
	lprod = prod;
	goto L80;
    }

/* .... AVCTRL/[CUTANG,....,] NORMPS */
/*                           AXIS */
L2900:
    if (lprod == 0) {
	sub = stack[(*top - 1 << 1) - 2];
	jnull = name_("NULL  ", (ftnlen)6);
	callzz_(&sub);
	j = name_("ON    ", (ftnlen)6);
	argcvt_(&j);
	argcvt_(&jnull);
	argcvt_(zeropt);
	argcvt_(zeropt);
	argcvt_(zeropt);
	argcvt_(&argstk[*argtop - 1]);
    } else if (lprod == 28) {
	argcvt_(&argstk[kk - 1]);
    } else {
	goto L4070;
    }
    if (errpt == 0) {
	argcvt_(zeropt);
	goto L3200;
    } else {
	tp = errpt + 4;
	kk = errpt;
	lprod = prod;
	goto L80;
    }

/* .... AVCTRL/[CUTANG,...,] NORMPS,LIMIT,DMAX */
/*                          AXIS */
L2950:
    if (lprod != 29) {
	goto L4070;
    }
    if (errpt > 0) {
	goto L4010;
    }
    argcvt_(argstk);
    goto L3200;

/*     GENERATE I.L. OUTPUT */

L3000:
    if (errpt > 0) {
	goto L4010;
    }
L3010:
    tp = *argtop + *top + 1;
    index = -3;
L3020:
    mm = stack[(tp << 1) - 2];
    nn = argstk[*argtop - 1];
    i__ = 1;
    s_copy(ibuff + 7, blank, (ftnlen)8, (ftnlen)4);
    binbcd_(&mm, ibuff + 3, &nch, (ftnlen)12);
    s_wsfi(&io___54);
    do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
    e_wsfi();
    concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
    j = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
    opcode_(move);
    twoarg_(&index, dottab);
    twoarg_(dlr, &j);
    rlslin_();
    --index;
    if (nn > nametb_1.nammax) {
	i__ = tmp_1.txxxx[(mm << 1) - 2];
    } else {
	class__ = nametb_1.namtbl[nn - 1] / *modulo * *modulo;
	if (class__ != permid[0] && class__ != canon[0]) {
	    i__ = tmp_1.txxxx[(mm << 1) - 2];
	}
    }
    if (i__ == 12) {
	i__ = 1;
    }
    if (i__ > 1) {
	goto L3030;
    }
    i__ = 1;
    opcode_(move);
    goto L3040;
L3030:
    opcode_(repl);
    onearg_(&i__);
L3040:
    twoarg_(&index, dottab);
    argcvt_(&nn);
    rlslin_();
    index -= i__;
    --(*argtop);
    --tp;
    if (*argtop > iend) {
	goto L3020;
    }
    s_copy(ibuff + 7, blank, (ftnlen)8, (ftnlen)4);
    i__1 = -index;
    binbcd_(&i__1, ibuff + 3, &nch, (ftnlen)12);
    s_wsfi(&io___55);
    do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
    e_wsfi();
    concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
    j = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
    opcode_(move);
    twoarg_(&c_n2, dottab);
    twoarg_(dlr, &j);
    rlslin_();
    callzz_(&aptxxx[91]);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    argcvt_(&sname);

    nowrds = index + 40;
    if (nowrds <= maxsiz[1]) {
	goto L3100;
    }
    if (nowrds >= maxsiz[0]) {
	goto L3090;
    }

/*     REPLACE MAXSIZ(2) */

    maxsiz[1] = nowrds;
    goto L3100;

/*     ADJUST BOTH MAXSIZ(1) AND (2) */

L3090:
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = nowrds;

L3100:
    if (iend == 0) {
	goto L3200;
    }
    rlslin_();
    *argtop = kk;
    tp = *argtop + *top + 1;
    if (prod == 25) {
	goto L1810;
    }
    goto L1610;
L3200:
    return 0;

L4000:
    errpt = 1 - *top;
L4010:
    i__1 = -errpt;
    alarm_(&c__2052, &i__1, &c__8, "TSSMIL  ", (ftnlen)8);
    goto L3100;
L4020:
    errpt = 1 - *top;
L4030:
    i__1 = -errpt;
    alarm_(&c__2021, &i__1, &c__8, "TSSMIL  ", (ftnlen)8);
    goto L3100;
L4040:
    errpt = mm;
    goto L4060;
L4050:
    if (errpt <= 0) {
	errpt = 1;
    }
L4060:
    i__1 = -errpt;
    alarm_(&c__2001, &i__1, &c__8, "TSSMIL  ", (ftnlen)8);
    goto L3100;
L4070:
    errpt = kk;
    goto L4060;

} /* tssmil_ */

#undef aptxxx
#undef zeropt
#undef maxsiz
#undef modulo
#undef argtop
#undef argstk
#undef number
#undef permid
#undef dottab
#undef modhlf
#undef ssurf
#undef point
#undef onept
#undef stack
#undef ident
#undef plane
#undef canon
#undef move
#undef temp
#undef repl
#undef line
#undef real__
#undef top
#undef vbl
#undef dlr


