/* PRO028.f -- translated by f2c (version 20100827).
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
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

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
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* Table of constant values */

static integer c__3 = 3;
static integer c__2052 = 2052;
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c_n6 = -6;
static integer c__8 = 8;
static integer c__2021 = 2021;
static integer c__2001 = 2001;

/* *** SOURCE FILE : M0012108.V03   *** */


/*              FORTRAN SUBROUTINE PRO028 */

/* LINKAGE      SUBROUTINE PRO028(ERAS) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    PRO026 */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    ARGGEN */
/*          SUBROUTINE    CALLZZ */
/*          INTEGER FCT.  GETTMP */
/*          INTEGER FCT.  MODE */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    REFGEN */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int pro028_(logical *eras)
{
    /* Initialized data */

    static char hcs[6] = "CS    ";
    static char hps[2] = "PS";
    static integer length[22] = { 7,5,5,3,2,1,1,1,1,4,2,6,4,4,2,4,3,4,3,3,2,2 
	    };

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, ii, jj, kk, ll, mm, nn, tp, tp2;
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define repl ((integer *)&il_1 + 16)
    static integer prod;
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define erasb ((integer *)&bcdptr_1 + 4)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define stack ((integer *)&stklst_1 + 3)
    static integer class__, lprod;
#define onept ((integer *)&numptr_1 + 3)
    static integer errpt;
    extern /* Subroutine */ int arggen_(void);
    extern integer search_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int refgen_(integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define permid ((integer *)&code_1 + 38)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
    extern /* Subroutine */ int argcvt_(integer *);
#define modulo ((integer *)&moduli_1)
#define quidlr ((integer *)&opmod_1 + 5)
    extern integer gettmp_(integer *);
#define vector ((integer *)&modx_1 + 19)
    extern /* Subroutine */ int twoarg_(integer *, integer *);
#define nought ((integer *)&opmod_1)
#define tlaxis ((integer *)&sublst_1 + 134)
    extern /* Subroutine */ int rlslin_(void), callzz_(integer *);
#define zeropt ((integer *)&numptr_1 + 1)
    extern /* Subroutine */ int puttmp_(integer *), resrvz_(integer *, 
	    integer *, integer *, integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */

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

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */




/* ERASB:       NAMTBL POINTER TO ALPHAMERIC LITERAL 'APTER' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* REAL:        MODE CODE (24) FOR A SCALAR */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* TLAXIS:      NAMTBL POINTER FOR XECUTION SUBROUTINE TLAXIS */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* ** */
/*     PREPARE MODES AND PERMANENT IDENTIFIERS OF THE ARGSTK ARGUMENTS */
/*          AND MOVE THEM TO STACK(2,TOP+1) AND HIGHER ADDR. */

    if (*argtop < 1) {
	goto L4100;
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
	if (class__ != permid[0]) {
	    goto L10;
	}
	nn = 50;
	mm += nn;
	goto L30;
L10:
	if (class__ == vbl[0] || class__ == temp[0]) {
	    goto L30;
	}
	if (class__ != number[0]) {
	    goto L4300;
	}
L20:
	mm = *real__;
L30:
	++tp;
	stack[(tp << 1) - 2] = mm - nn;
/* L40: */
	stack[(tp << 1) - 1] = gmty_1.pmidtb[mm - 1];
    }


/*     SEARCH FOR THE PRODUCTION NUMBER AND BRANCH */

    mm = *argtop;
    ll = mm;
    nn = gmty_1.geoloc[48];
    lprod = 0;
    ii = 0;
L50:
    errpt = ll;
    tp2 = tp << 1;
    prod = search_(stack, &tp2, &gmty_1.geomtb[nn - 1], &errpt);

/*                   ERROR DIAGNOSTICS */

    if (prod == 200) {
	goto L4400;
    }
    if (ll - errpt > length[prod - 1]) {
	goto L4500;
    }
    if (prod < 6) {
	goto L90;
    }
    if (errpt != 0) {
	goto L4200;
    }

/*                   PRODUCTION NUMBERS */
/*             1    2    3    4    5    6    7    8    9   10   11 */
L90:
    switch (prod) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L200;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L800;
	case 10:  goto L1000;
	case 11:  goto L1000;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1300;
	case 15:  goto L1500;
	case 16:  goto L2200;
	case 17:  goto L2200;
	case 18:  goto L2200;
	case 19:  goto L2200;
	case 20:  goto L2000;
	case 21:  goto L2100;
	case 22:  goto L2200;
    }
/*            12   13   14   15   16   17   18   19   20   21   22 */
/*                                                          PS */
/*                PRODUCTION 1, 2, 3, 4  -->  TLAXIS/ATANGL,DS,....... */

L100:
    argstk[*argtop - 6] = argstk[*argtop - 7];
    argstk[*argtop - 7] = argstk[*argtop - 3];
    argstk[*argtop - 4] = argstk[*argtop - 2];
    argstk[*argtop - 3] = argstk[*argtop - 1];
    *argtop += -2;
    mm = *argtop;
    goto L410;

L200:
    jj = argstk[*argtop - 3];
    argstk[*argtop - 3] = argstk[*argtop - 5];
    argstk[*argtop - 4] = argstk[*argtop - 5];
    argstk[*argtop - 5] = jj;
    goto L410;

L400:
    *argtop += 2;
    argstk[*argtop - 1] = argstk[*argtop - 3];
    argstk[*argtop - 2] = argstk[*argtop - 4];
    argstk[*argtop - 3] = *zeropt;
    argstk[*argtop - 4] = *zeropt;
L410:
    mm = *argtop;
    if (s_cmp(cnamtb_1.cnamtb + (argstk[mm - 2] - 1) * 6, hcs, (ftnlen)6, (
	    ftnlen)6) == 0) {
	goto L4600;
    }
    lprod = prod;
    if (errpt == 0) {
	goto L3000;
    }
    jj = length[prod - 1] - 1;
    stack[(tp - jj << 1) - 1] = stack[(tp << 1) - 1];
    tp -= jj;
    ll -= jj;
    goto L50;

/*            PRODUCTION 5    TLAXIS/<REAL>,<REAL>,.......,<REAL> */

L500:
    if ((i__1 = *argtop - 3) < 0) {
	goto L3000;
    } else if (i__1 == 0) {
	goto L510;
    } else {
	goto L530;
    }
L510:
    errpt = 1;
    if (mode_(&argstk[errpt - 1]) != *real__) {
	goto L4300;
    }
    kk = gettmp_(vector);
    opcode_(move);
    twoarg_(nought, &kk);
    i__1 = mm;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L520: */
	argcvt_(&argstk[mm + 1 - i__ - 1]);
    }
    rlslin_();
    refgen_(&c__3, &kk);
    puttmp_(vector);
    prod = 7;
    goto L3900;

L530:
    if (*argtop < 10) {
	goto L540;
    }
    i__1 = 9 - *argtop;
    alarm_(&c__2052, &i__1, &c__4, "PRO028  ", (ftnlen)8);
    mm = 9;
L540:
    i__1 = mm;
    for (errpt = 4; errpt <= i__1; ++errpt) {
	if (mode_(&argstk[errpt - 1]) != *real__) {
	    goto L4300;
	}
/* L550: */
    }
    goto L3000;
/*                 PRODUCTION 6  -->  TLAXIS/ LAST */
/*                 PRODUCTION 7  -->  TLAXIS/<VECTOR> */
/*                 PRODUCTION 8  -->  TLAXIS/NORMDS ; TLAXIS/NORMPS */
/*                 PRODUCTION 9  -->  TLAXIS/ 1. */
L600:
    kk = *onept;
    prod = 9;
    goto L3900;
L700:
    mm = 3;
L800:
    kk = argstk[*argtop - 1];
    if (s_cmp(cnamtb_1.cnamtb + ((kk - 1) * 6 + 4), hps, (ftnlen)2, (ftnlen)2)
	     == 0) {
	prod = 6;
    }
    goto L3900;

/*                 PRODUCTION 10 -->  TLAXIS/PARLEL,<REAL>,<REAL>,<REAL> */
/*                 PRODUCTION 11 -->  TLAXIS/PARLEL,<REAL> */

L1000:
    goto L3000;
/*                                                          PS */
/*                PRODUCTION 12,13,14,15  ->  TLAXIS/PARLEL,DS,....... */

L1200:
    argstk[*argtop - 5] = argstk[*argtop - 4];
    argstk[*argtop - 4] = argstk[*argtop - 2];
    argstk[*argtop - 3] = argstk[*argtop - 1];
    *argtop += -2;
    goto L1520;

L1300:
    argstk[*argtop - 3] = argstk[*argtop - 4];
    goto L1520;

L1500:
    *argtop += 2;
    argstk[*argtop - 1] = argstk[*argtop - 3];
    argstk[*argtop - 2] = argstk[*argtop - 4];
    argstk[*argtop - 3] = *zeropt;
    argstk[*argtop - 4] = *zeropt;
L1520:
    mm = *argtop;
    if (s_cmp(cnamtb_1.cnamtb + (argstk[mm - 2] - 1) * 6, hcs, (ftnlen)6, (
	    ftnlen)6) == 0) {
	goto L4600;
    }
    goto L3000;
/*                                                          ..,MOTDIR,.. */
/*                PRODUCTION 16 BIS 22  -->  TLAXIS/ATANGL,...,CUTANG,.. */
/*                                                          ..,PERPTO,.. */
L2000:
    ii = argstk[0];
    i__ = 3;
    i__1 = *argtop;
    for (jj = i__; jj <= i__1; ++jj) {
/* L2010: */
	argstk[jj - 3] = argstk[jj - 1];
    }
    *argtop += -2;
    goto L2200;

L2100:
    ii = argstk[0];
    i__ = 2;
/* L2110: */
    i__1 = *argtop;
    for (jj = i__; jj <= i__1; ++jj) {
/* L2120: */
	argstk[jj - 2] = argstk[jj - 1];
    }
    --(*argtop);

L2200:
    mm = *argtop;
    if (lprod == 0) {
	goto L4600;
    }
    prod = lprod * 100 + prod;

/*      I. L. OUTPUT */

L3000:
    if (*eras) {
	goto L3100;
    }
    resrvz_(erasb, &c__0, &c__9, &c__1);
    *eras = TRUE_;

L3100:
    opcode_(move);
    twoarg_(nought, erasb);
    arggen_();
    rlslin_();
    if (ii == 0) {
	goto L3800;
    }

/*          REPLACE FOR PLANE, LINE OR VECTOR DEFINITION */

    opcode_(repl);
    onearg_(&c__3);
    twoarg_(&c_n6, erasb);
    argcvt_(&ii);
    rlslin_();
    mm += 3;

L3800:
    kk = *erasb;
L3900:
    callzz_(tlaxis);
    twoarg_(quidlr, &mm);
    twoarg_(quidlr, &prod);
    argcvt_(&kk);
    rlslin_();

L4000:
    return 0;

L4100:
    errpt = 1 - *top;
L4200:
    i__1 = -errpt;
    alarm_(&c__2052, &i__1, &c__8, "PRO028  ", (ftnlen)8);
    goto L4000;
L4300:
    i__1 = -errpt;
    alarm_(&c__2021, &i__1, &c__8, "PRO028  ", (ftnlen)8);
    goto L4000;
L4400:
    if (errpt <= 0) {
	errpt = 1;
    }
    i__1 = -errpt;
    alarm_(&c__2001, &i__1, &c__8, "PRO028  ", (ftnlen)8);
    goto L4000;
L4500:
    ++errpt;
    goto L4200;
L4600:
    errpt = *argtop - 1;
    goto L4300;

} /* pro028_ */

#undef zeropt
#undef tlaxis
#undef nought
#undef vector
#undef quidlr
#undef modulo
#undef argtop
#undef argstk
#undef number
#undef permid
#undef modhlf
#undef onept
#undef stack
#undef erasb
#undef move
#undef temp
#undef repl
#undef real__
#undef top
#undef vbl


