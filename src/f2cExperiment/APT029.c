/* APT029.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000779.V03   *** */


/* .....FORTRAN SUBROUTINE             APT029...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT029 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED */
/*              AS TANGENT TO A GIVEN LINE, PASSING THROUGH A */
/*              GIVEN POINT AND HAVING A GIVEN RADIUS BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = CIRCLE/TANTO, LN, ****, PN, RADIUS, R */
/*                **** = XLARGE, YLARGE, XSMALL, YSMALL */

/* LINKAGE      CALL APT029 (RESULT, LN, MN, PN, RAD) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              LN      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT LINE */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */
/*              RAD     REAL VARIABLE CONTAINING THE VALUE OF */
/*                      THE DESIRED RADIUS */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT004 */
/*              SUBROUTINE          APT020 */
/*              SUBROUTINE          APT078 */
/*              REAL FUNCTION       ABS */
/*              LOGICAL FUNCTION    CKDEF */
/*              REAL FUNCTION       SIGN */

/* Subroutine */ int apt029_(doublereal *result, doublereal *ln, integer *mn, 
	doublereal *pn, doublereal *rad)
{
    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
#define s1 ((doublereal *)&dshar3_1 + 37)
    extern /* Subroutine */ int apt020_(doublereal *, doublereal *, integer *,
	     doublereal *), apt004_(doublereal *, integer *, doublereal *, 
	    doublereal *), apt078_(doublereal *, integer *);
    extern logical ckdef_(doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...     TEST VALIDITY OF PN */

    /* Parameter adjustments */
    --pn;
    --ln;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&pn[1]);

/* ...     DEFINE CIRCLE C1 WITH CENTER PN, LINE LN1 PARLEL TO LN */
    apt078_(&def_1.r__[3], &knumbr_1.km1);
    def_1.c1[7] = *rad;
    def_1.ln1[4] = ln[4];
    *s1 = -def_1.ln1[4];
    for (i__ = 1; i__ <= 3; ++i__) {
	def_1.c1[i__] = pn[i__];
	def_1.c1[i__ + 3] = def_1.r__[i__ - 1];
	def_1.ln1[i__] = ln[i__];
/* L10: */
	*s1 += def_1.ln1[i__] * def_1.c1[i__];
    }

/* ...     TEST FOR PN ON LINE LN */

    if (abs(*s1) <= znumbr_1.z1em5) {
	goto L40;
    }
    def_1.ln1[4] += d_sign(&def_1.c1[7], s1);

/* ...     CENTER OF DESIRED CIRCLE IS INTERSECTION OF LN1 AND C1 */

L20:
    for (i__ = 4; i__ <= 7; ++i__) {
/* L50: */
	def_1.r__[i__ - 1] = def_1.c1[i__];
    }
    apt004_(&result[1], mn, &def_1.ln1[1], &def_1.c1[1]);
    for (i__ = 4; i__ <= 7; ++i__) {
/* L30: */
	result[i__] = def_1.c1[i__];
    }
    return 0;
L40:
    apt020_(&def_1.ln1[1], &def_1.ln1[1], mn, rad);
    goto L20;
} /* apt029_ */

#undef s1


