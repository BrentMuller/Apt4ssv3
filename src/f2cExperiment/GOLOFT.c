/* GOLOFT.f -- translated by f2c (version 20100827).
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
static integer c__2052 = 2052;
static integer c__8 = 8;
static integer c__2021 = 2021;
static integer c__2001 = 2001;

/* *** SOURCE FILE : M0012104.V05   *** */


/*              FORTRAN SUBROUTINE GOLOFT */

/* LINKAGE      SUBROUTINE GOLOFT */

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

/* Subroutine */ int goloft_(void)
{
    /* Initialized data */

    static char plft[6] = "PLOTFT";
    static char uc[6] = "UCONST";
    static char vc[6] = "VCONST";
    static char flw[6] = "FLOW  ";
    static char blank[8] = "        ";
    static integer length[42] = { 3,7,6,6,5,3,4,7,5,6,3,5,4,2,3,2,8,6,6,6,4,4,
	    4,1,7,5,5,5,3,8,6,7,5,7,5,6,4,6,4,5,3,2 };

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, j, jj, kk, mm, nn, tp, tp2, nch;
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
    static integer fmt;
#define top ((integer *)&stklst_1)
#define real__ ((integer *)&modx_1 + 20)
    extern integer numb_(char *, ftnlen);
#define repl ((integer *)&il_1 + 16)
    static integer prod;
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
    static char ibuff[15];
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
    static integer class__, index, lprod, errpt;
#define scurv ((integer *)&modx_1 + 29)
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
    extern /* Subroutine */ int argcvt_(integer *), twoarg_(integer *, 
	    integer *), rlslin_(void), callzz_(integer *);
#define maxsiz ((integer *)&cfsize_1 + 3)
    static integer nowrds;
#define aptxxx ((integer *)&sublst_1)

    /* Fortran I/O blocks */
    static icilist io___42 = { 0, ibuff, 0, "(I3)", 3, 1 };
    static icilist io___43 = { 0, ibuff, 0, "(I3)", 3, 1 };





/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMMAX:      NAMTBL INDEX OF THE PART PROGRAM NAME SECTION */
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
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR A SCALAR */
/* SCURV:       MODE CODE (30) FOR SCULPTURED CURVE */

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


/*     SEARCH FOR THE PRODUCTION NUMBER AND BRANCH */

    kk = *argtop;
    lprod = 0;
    fmt = 1;
    nn = gmty_1.geoloc[47];
L50:
    errpt = kk;
    tp2 = tp << 1;
    prod = search_(stack, &tp2, &gmty_1.geomtb[nn - 1], &errpt);

    if (prod == 200) {
	goto L4050;
    }
    if (kk - errpt != length[prod - 1]) {
	goto L4090;
    }

/*                   PRODUCTION NUMBERS */
/*             1    2    3    4    5    6    7    8    9   10   11   12 */
    switch (prod) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L200;
	case 4:  goto L200;
	case 5:  goto L200;
	case 6:  goto L200;
	case 7:  goto L200;
	case 8:  goto L300;
	case 9:  goto L300;
	case 10:  goto L300;
	case 11:  goto L300;
	case 12:  goto L300;
	case 13:  goto L300;
	case 14:  goto L300;
	case 15:  goto L300;
	case 16:  goto L400;
	case 17:  goto L500;
	case 18:  goto L400;
	case 19:  goto L500;
	case 20:  goto L500;
	case 21:  goto L400;
	case 22:  goto L400;
	case 23:  goto L500;
	case 24:  goto L600;
	case 25:  goto L600;
	case 26:  goto L600;
	case 27:  goto L600;
	case 28:  goto L600;
	case 29:  goto L600;
	case 30:  goto L700;
	case 31:  goto L700;
	case 32:  goto L800;
	case 33:  goto L800;
	case 34:  goto L700;
	case 35:  goto L700;
	case 36:  goto L800;
	case 37:  goto L800;
	case 38:  goto L900;
	case 39:  goto L900;
	case 40:  goto L900;
	case 41:  goto L900;
	case 42:  goto L900;
    }
/*            13   14   15   16   17   18   19   20   21   22   23   24 */
/*            25   26   27   28   29   30   31   32   33   34   35   36 */
/*            37   38   39   40   41   42 */

/*     GOLOFT/SSURF,UCONST,U,............. */

L100:
    fmt = 6;
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, plft, (
	    ftnlen)6, (ftnlen)6) != 0) {
	goto L110;
    }
    fmt = 3;
    stack[(tp << 1) - 1] = gmty_1.pmidtb[*scurv - 1];
L110:
    if (s_cmp(cnamtb_1.cnamtb + (argstk[*argtop - 2] - 1) * 6, vc, (ftnlen)6, 
	    (ftnlen)6) == 0) {
	++fmt;
    }
    lprod = 1;
    goto L2900;

L200:
    if (fmt < 6) {
	goto L4100;
    }
    if (lprod == 0 || lprod >= prod) {
	goto L4070;
    }
    lprod = 7;
    goto L2900;

L300:
    if (fmt < 6) {
	goto L4100;
    }
    if (lprod == 0 || lprod >= prod) {
	goto L4070;
    }
    goto L3000;
/*                                  FLOW */
/*     PLOTFT/SCURV,START,S,.......,PARAM,..... */

L400:
    jj = 1;
    goto L510;

L500:
    jj = 3;
L510:
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, plft, (
	    ftnlen)6, (ftnlen)6) != 0) {
	goto L4100;
    }
    if (s_cmp(cnamtb_1.cnamtb + (argstk[jj - 1] - 1) * 6, flw, (ftnlen)6, (
	    ftnlen)6) == 0) {
	fmt = 2;
    }
    goto L3000;

/*     PLOTFT/SSURF,UCONST,U,START,S,....... */
/*     PLOTFT/SCURV,START,S,................ */

L600:
    goto L3000;

/*     PLOTFT/SSURF,GRID,................... */

L700:
    jj = 4;
    goto L810;
L800:
    jj = 3;
L810:
    kk = *argtop - 2;
    if (s_cmp(cnamtb_1.cnamtb + (argstk[kk - 1] - 1) * 6, uc, (ftnlen)6, (
	    ftnlen)6) != 0) {
	goto L4080;
    }
    kk = *argtop - jj;
    if (s_cmp(cnamtb_1.cnamtb + (argstk[kk - 1] - 1) * 6, vc, (ftnlen)6, (
	    ftnlen)6) != 0) {
	goto L4080;
    }
L900:
    fmt = 5;
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, plft, (
	    ftnlen)6, (ftnlen)6) != 0) {
	goto L4100;
    }
    goto L3000;

/*     REDUCE STACK BY I */

L2900:
    if (errpt == 0) {
	goto L3010;
    }
    jj = length[prod - 1] - 1;
    stack[(tp - jj << 1) - 1] = stack[(tp << 1) - 1];
    tp -= jj;
    kk -= jj;
    goto L50;

/*     GENERATE I.L. OUTPUT */

L3000:
    if (errpt > 0) {
	goto L4010;
    }
L3010:
    tp = *argtop + *top + 1;
    index = -3;
    jj = argstk[*argtop - 1];
L3020:
    mm = stack[(tp << 1) - 2];
    nn = argstk[*argtop - 1];
    i__ = 1;
    s_copy(ibuff + 7, blank, (ftnlen)8, (ftnlen)8);
    binbcd_(&mm, ibuff + 3, &nch, (ftnlen)12);
    s_wsfi(&io___42);
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
	if (nametb_1.namtbl[nn - 1] / *modulo * *modulo != permid[0]) {
	    i__ = tmp_1.txxxx[(mm << 1) - 2];
	}
    }
    if (i__ == 12) {
	i__ = 1;
    }
    if (i__ > 1) {
	goto L3030;
    }
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
    if (*argtop > 0) {
	goto L3020;
    }
    for (kk = 1; kk <= 2; ++kk) {
	s_copy(ibuff + 7, blank, (ftnlen)8, (ftnlen)8);
	binbcd_(&fmt, ibuff + 3, &nch, (ftnlen)12);
	s_wsfi(&io___43);
	do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
	e_wsfi();
	concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
	j = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
	opcode_(move);
	i__1 = -kk;
	twoarg_(&i__1, dottab);
	twoarg_(dlr, &j);
	rlslin_();
/* L3050: */
	fmt = -index;
    }
    callzz_(&aptxxx[91]);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    argcvt_(&jj);

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
    return 0;

L4000:
    errpt = 1 - *top;
L4010:
    i__1 = -errpt;
    alarm_(&c__2052, &i__1, &c__8, "GOLOFT  ", (ftnlen)8);
    goto L3100;
L4030:
    i__1 = -errpt;
    alarm_(&c__2021, &i__1, &c__8, "GOLOFT  ", (ftnlen)8);
    goto L3100;
L4050:
    if (errpt <= 0) {
	errpt = 1;
    }
L4060:
    i__1 = -errpt;
    alarm_(&c__2001, &i__1, &c__8, "GOLOFT  ", (ftnlen)8);
    goto L3100;
L4070:
    errpt = kk - 1;
    goto L4060;
L4080:
    errpt = kk;
    goto L4060;
L4090:
    ++errpt;
    goto L4010;
L4100:
    errpt = 1 - *top;
    goto L4060;

} /* goloft_ */

#undef aptxxx
#undef maxsiz
#undef modulo
#undef argtop
#undef argstk
#undef number
#undef permid
#undef dottab
#undef modhlf
#undef scurv
#undef stack
#undef ident
#undef move
#undef temp
#undef repl
#undef real__
#undef top
#undef vbl
#undef dlr


