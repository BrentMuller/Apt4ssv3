/* APT031.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000781.V03   *** */


/* .....FORTRAN SUBROUTINE             APT031...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT031 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED */
/*              AS TANGENT TO EACH OF TWO GIVEN CIRCLES AND HAVING */
/*              A GIVEN RADIUS BY THE APT STATEMENT */
/*              RESULT = CIRCLE/+****, ***, CIR1, ***, CIR2, RADIUS, */
/*                       RAD */
/*               ***** = XLARGE, YLARGE, XSMALL, OR YSMALL */
/*                 *** = IN OR OUT */

/* LINKAGE      CALL APT031 (RESULT, M1, M2, CIR1, M3, CIR2, RAD) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              M1      INTEGER EQUIVALENT OF THE FIRST MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              M2      INTEGER EQUIVALENT OF THE SECOND MODIFIER */
/*                             1 = IN           2 = OUT */
/*              CIR1    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT CIRCLE */
/*              M3      INTEGER EQUIVALENT OF THE THIRD MODIFIER */
/*                             1 = IN           2 = OUT */
/*              CIR2    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT CIRCLE */
/*              RAD     REAL VARIABLE CONTAINING THE VALUE OF THE */
/*                      DESIRED RADIUS */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT005 */
/*              SUBROUTINE          APT078 */
/*              REAL FUNCTION       ABS */

/* Subroutine */ int apt031_(doublereal *result, integer *m1, integer *m2, 
	doublereal *cir1, integer *m3, doublereal *cir2, doublereal *rad)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal carg[7];
    extern /* Subroutine */ int apt005_(doublereal *, integer *, doublereal *,
	     doublereal *), apt078_(doublereal *, integer *);
    static doublereal dummy1, dummy2;





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




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     ESTABLISH CIRCLE C31 WITH RADIUS RAD */

    /* Parameter adjustments */
    --cir2;
    --cir1;
    --result;

    /* Function Body */
    apt078_(&def_1.r__[3], &knumbr_1.km1);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	dshar3_1.sc[i__ + 9] = def_1.r__[i__ - 1];
    }
    dshar3_1.sc[13] = *rad;
    for (i__ = 1; i__ <= 7; ++i__) {
	dshar3_1.sc[i__ - 1] = cir1[i__];
/* L20: */
	dshar3_1.p[i__ - 1] = cir2[i__];
    }
    dummy1 = (doublereal) (*m2);
    dummy2 = (doublereal) (*m3);
    dshar3_1.sc[6] = (d__1 = dshar3_1.sc[6] + (znumbr_1.z2 * dummy1 - 
	    znumbr_1.z3) * dshar3_1.sc[13], abs(d__1));
    dshar3_1.p[6] = (d__1 = dshar3_1.p[6] + (znumbr_1.z2 * dummy2 - 
	    znumbr_1.z3) * dshar3_1.sc[13], abs(d__1));

/* ...     CENTER OF DESIRED CIRCLE - INTERSECTION OF CI31 AND CR31 */

    for (i__ = 4; i__ <= 7; ++i__) {
/* L50: */
	def_1.r__[i__ - 1] = dshar3_1.sc[i__ + 6];
    }
    for (i__ = 1; i__ <= 7; ++i__) {
/* L40: */
	carg[i__ - 1] = dshar3_1.sc[i__ - 1];
    }
    apt005_(&result[1], m1, carg, dshar3_1.p);
    for (i__ = 4; i__ <= 7; ++i__) {
/* L30: */
	result[i__] = dshar3_1.sc[i__ + 6];
    }
    return 0;
} /* apt031_ */

