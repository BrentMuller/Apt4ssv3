/* REFREF.f -- translated by f2c (version 20100827).
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
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

/* Table of constant values */

static integer c__2052 = 2052;
static integer c__8 = 8;
static integer c__1010 = 1010;
static integer c__1011 = 1011;

/* *** SOURCE FILE : M0006675.V03   *** */


/*              FORTRAN SUBROUTINE REFREF */

/* LINKAGE      SUBROUTINE REFREF */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CALLZZ          SUBROUTINE    PRO026 */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    RLSLIN */

/* Subroutine */ int refref_(void)
{
    /* Initialized data */

    static char cnmore[6] = "NOMORE";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, ep, top;
    extern integer mode_(integer *);
#define apt085 ((integer *)&sublst_1 + 125)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define refflg ((logical *)&flags_1 + 3)
    extern /* Subroutine */ int argcvt_(integer *);
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
    extern /* Subroutine */ int callzz_(integer *), rlslin_(void);
#define matrix ((integer *)&modx_1 + 17)
#define refsys ((integer *)&sublst_1 + 133)




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */

/*        5.    PROGRAM CONTROL FLAGS */

/* REFFLG:      TRUE WHEN A REFSYS COMMAND ENCOUNTERED */

/*       17.    MODE CODES */

/* MATRIX:      MODE CODE (18) FOR MATRIX */

/*       28.    OPERAND MODIFIERS */

/* APT085:      NAMTBL POINTER FOR APT085 */
/* REFSYS:      NAMTBL POINTER FOR XECUTION SUBROUTINE REFSYS */
/* ** */
    ep = -1;
    if ((i__1 = *argtop - 1) < 0) {
	goto L20;
    } else if (i__1 == 0) {
	goto L40;
    } else {
	goto L30;
    }
L20:
    ep = top;
    goto L35;
L30:
    ep = 1 - *argtop;
L35:
    alarm_(&c__2052, &ep, &c__8, "REFREF  ", (ftnlen)8);
L40:
    if (*refflg) {
	goto L1000;
    }
/*     REFSYS NOT IN EFFECT */
/*     ARE PARAMETERS CORRECT */
    if (mode_(&argstk[*argtop - 1]) != *matrix) {
	i__1 = -(*argtop);
	alarm_(&c__1010, &i__1, &c__8, "REFREF  ", (ftnlen)8);
    }
    *refflg = TRUE_;
L5:
    callzz_(refsys);
    argcvt_(&argstk[*argtop - 1]);
L10:
    rlslin_();
/* L50: */
    return 0;
/*     REFSYS IN EFFECT */
L1000:
    i__ = argstk[*argtop - 1];
    if (mode_(&argstk[*argtop - 1]) == *matrix) {
	goto L5;
    }
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, cnmore, (ftnlen)6, (ftnlen)6) 
	    != 0) {
	i__1 = -(*argtop);
	alarm_(&c__1011, &i__1, &c__8, "REFREF  ", (ftnlen)8);
    }
    *refflg = FALSE_;
    callzz_(apt085);
    goto L10;
} /* refref_ */

#undef refsys
#undef matrix
#undef argtop
#undef argstk
#undef refflg
#undef apt085


