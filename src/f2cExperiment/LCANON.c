/* LCANON.f -- translated by f2c (version 20100827).
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
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

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
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

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

struct {
    integer canstr[18];
} canstr_;

#define canstr_1 canstr_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__1 = 1;
static integer c_n2 = -2;
static integer c__0 = 0;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006649.V07   *** */


/*              FORTRAN SUBROUTINE LCANON */

/* LINKAGE      SUBROUTINE LCANON(ACTNO,BIGCNT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CONCAT          SUBROUTINE    RECOG */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    BINBCD */
/*          SUBROUTINE    ARGCVT */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    ALARM */

/* Subroutine */ int lcanon_(integer *actno, integer *bigcnt)
{
    /* Initialized data */

    static char ihblk[4] = "    ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, j, k, m, n, k5, m5, n5, ibr;
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define meta ((integer *)&srctbl_1 + 2)
    extern integer numb_(char *, ftnlen);
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define four ((integer *)&numptr_1 + 6)
    static integer icode;
    static char ibuff[15];
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define stack ((integer *)&stklst_1 + 3)
    static integer inumb, errpt;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
#define biggeo ((integer *)&code_1 + 86)
#define finmac ((logical *)&macxx1_1 + 23)
    extern /* Subroutine */ int concat_(char *, char *, ftnlen, ftnlen);
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int opcode_(integer *);
#define dottab ((integer *)&bcdptr_1 + 6)
#define cantop ((integer *)&cfsize_1)
#define cansiz ((integer *)&cfsize_1 + 5)
#define canstk ((integer *)&canstr_1 + 2)
#define modulo ((integer *)&moduli_1)
#define quidlr ((integer *)&opmod_1 + 5)
#define subscr ((integer *)&modx_1 + 23)
#define canptr ((integer *)&canstr_1)
#define ergstk ((integer *)&errpos_1 + 202)
    extern /* Subroutine */ int twoarg_(integer *, integer *), argcvt_(
	    integer *), rlslin_(void);
    extern integer gettmp_(integer *);
#define maxsiz ((integer *)&cfsize_1 + 3)
    extern /* Subroutine */ int callzz_(integer *);
    static integer ierror;
    extern /* Subroutine */ int puttmp_(integer *), resrvz_(integer *, 
	    integer *, integer *, integer *);
#define aptxxx ((integer *)&sublst_1)

    /* Fortran I/O blocks */
    static icilist io___38 = { 0, ibuff, 0, "(I3)", 3, 1 };





/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* BIGGEO:      (1)=CODE CLASS 44000,(2)=NAMTBL INDEX OF 'BIGGEO' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ONE:         NAMTBL POINTER TO '1     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */

/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (24) FOR A SCALAR */
/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */

/*       22.    MACRO PROCESSING VARIABLES */

/* FINMAC:      TRUE DURING FINAL MACRO PROCESSING */

/*       27.    OPERAND MODIFIERS */

/* DLR:         CONTAINS OPERAND TYPE CODE 1 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE */

/* CANPTR:      POINTER TO LAST CANSTK ENTRY */
/* CANSTK:      ARGUMENT STACK FOR CANON AND OBTAIN STATEMENTS */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* PURPOSE      TO GENERATE I.L. FOR LARGE DATA ARRAY CANON DEFINITIONS */

/* ARGUMENTS    ACTNO   BASIC PRODUCTION ACTION NUMBER */
/*              BIGCNT  NUMBER OF CALLS TO LCANON FOR THIS DEFINITION */

/* ** */
/* ...       IF FIRST CALL, INITIALIZE */

    if (*bigcnt != 1) {
	goto L100;
    }
    icode = 1;
    ibr = 1;

L100:
    if (*actno >= 103) {
	goto L500;
    }

/* ...       PICK UP ARG.  GENERATE I.L. FOR THREE ARGUMENTS AT A TIME. */

    ++(*canptr);
    canstk[*canptr - 1] = stack[(*top - 1 << 1) - 2];
    ergstk[101 - *canptr - 1] = estack[*top - 2];
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    if (*canptr != 3) {
	goto L900;
    }

L200:
    i__1 = *canptr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	n = canstk[i__ - 1];
	if (n > nametb_1.nammax) {
	    goto L210;
	}
	if (nametb_1.namtbl[n - 1] / *modulo != temp[0] / *modulo) {
	    goto L210;
	}
	m = nametb_1.namtbl[n - 1] - temp[0];
	if (m >= *modhlf) {
	    m = *subscr;
	}
	puttmp_(&m);
L210:
	if (icode == 4) {
	    goto L230;
	}
	if (mode_(&n) != *real__) {
	    goto L1010;
	}
L220:
L230:
	;
    }

    if (icode == 4) {
	goto L250;
    }
    opcode_(move);
    i__1 = -(*bigcnt) + 1;
    twoarg_(&i__1, dottab);
    i__1 = *canptr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	n = canstk[i__ - 1];
/* L240: */
	argcvt_(&n);
    }
    rlslin_();
L250:
    if (ibr == 2) {
	goto L510;
    }
    *canptr = 0;
    goto L900;

/* ...       PROCESS END OF DEFINITION. */
/*          FIRST CHECK FOR ARGUMENTS LEFT IN CANSTK. */

L500:
    if (*canptr == 0 || icode == 4) {
	goto L520;
    }
    ibr = 2;
    *bigcnt = *bigcnt - *canptr + 2;
    goto L200;
L510:
    *bigcnt = *bigcnt + *canptr - 2;
    *canptr = 0;

L520:
    n = stack[(*top - 3 << 1) - 2];
    m = nametb_1.namtbl[n - 1] - biggeo[0];
    if (m > *modhlf) {
	m -= *modhlf;
    }
    if (*actno != 105) {
	goto L530;
    }

    n5 = gettmp_(&m);
    k5 = temp[0];
    goto L550;

L530:
    n5 = stack[(*top - 5 << 1) - 2];
    k5 = nametb_1.namtbl[n5 - 1] / *modulo * *modulo;
    if (k5 != vbl[0] && k5 != temp[0]) {
	goto L540;
    }
    m5 = nametb_1.namtbl[n5 - 1] - k5;
    if (m5 >= *modhlf) {
	m5 -= *modhlf;
    }
    if (m5 == m) {
	goto L550;
    }
    ibr = 3;
    goto L1020;
L540:
    nametb_1.namtbl[n5 - 1] = vbl[0] + m;
    resrvz_(&n5, &m, &tmp_1.txxxx[(m << 1) - 2], &c__1);

/* ...       UPDATE MAXSIZ IF NECESSARY.  ADD SIZE AND NAME TO CANSIZ. */

L550:
    if (*bigcnt <= abs(maxsiz[1])) {
	goto L560;
    }
    if (*bigcnt <= abs(maxsiz[0])) {
	goto L555;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = *bigcnt;
    goto L560;
L555:
    maxsiz[1] = *bigcnt;
L560:
    j = n5 % *cantop;
    i__1 = *cantop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = j % *cantop + 1;
	if (cansiz[(j << 1) - 2] != 0 && cansiz[(j << 1) - 1] != n5) {
	    goto L570;
	}
	cansiz[(j << 1) - 2] = *bigcnt;
	cansiz[(j << 1) - 1] = n5;
	goto L600;
L570:
	;
    }
    ibr = 4;
    goto L1030;

/* ...       GENERATE I.L. TO STORE SIZE IN INTERNAL CANONICAL FORM. */

L600:
    s_copy(ibuff + 11, ihblk, (ftnlen)4, (ftnlen)4);
    binbcd_(bigcnt, ibuff + 3, &i__, (ftnlen)12);
    s_wsfi(&io___38);
    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    e_wsfi();
    concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
    inumb = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
    opcode_(move);
    twoarg_(&c_n2, &n5);
    argcvt_(&inumb);
    rlslin_();

/* ...       GENERATE CALL TO APT094 */

L610:
    callzz_(&aptxxx[67]);
    if (icode == 1) {
	twoarg_(dlr, one);
    } else {
	twoarg_(dlr, four);
    }
    argcvt_(&n5);
    twoarg_(&c__0, dottab);
    rlslin_();
    if ((i__1 = *actno - 104) < 0) {
	goto L900;
    } else if (i__1 == 0) {
	goto L640;
    } else {
	goto L620;
    }

L620:
    *top += -4;
    goto L660;
L640:
    *top += -6;
L660:
    stack[(*top << 1) - 2] = n5;
    j = nametb_1.namtbl[n5 - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[j - 1];
    k = nametb_1.namtbl[n5 - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[k - 1];

L900:
    return 0;

/* ...       DIAGNOSTIC PROCESSING */

L1010:
    ierror = 1032;
    errpt = i__ - 101;
    if (! (*finmac)) {
	goto L1090;
    }
    n = *top;
    j = stack[(*top << 1) - 2];
    stack[(*top << 1) - 2] = comma[1];
    i__1 = i__;
    for (k = 1; k <= i__1; ++k) {
	stack[(*top + 1 << 1) - 2] = canstk[k - 1];
	stack[(*top + 2 << 1) - 2] = comma[1];
/* L1015: */
	*top += 2;
    }
    i__1 = *top - 1;
    alarm_(&ierror, &i__1, &c__8, "LCANON  ", (ftnlen)8);
    *top = n;
    stack[(*top << 1) - 2] = j;
    goto L1100;
L1020:
    ierror = 1001;
    goto L1080;
L1030:
    ierror = 53;
L1080:
    errpt = *top - 5;
L1090:
    alarm_(&ierror, &errpt, &c__8, "LCANON  ", (ftnlen)8);
L1100:
    icode = 4;
    switch (ibr) {
	case 1:  goto L220;
	case 2:  goto L220;
	case 3:  goto L550;
	case 4:  goto L610;
    }
    return 0;
} /* lcanon_ */

#undef aptxxx
#undef maxsiz
#undef ergstk
#undef canptr
#undef subscr
#undef quidlr
#undef modulo
#undef canstk
#undef cansiz
#undef cantop
#undef dottab
#undef estack
#undef modhlf
#undef finmac
#undef biggeo
#undef stack
#undef comma
#undef four
#undef move
#undef temp
#undef meta
#undef real__
#undef top
#undef vbl
#undef dlr
#undef one


