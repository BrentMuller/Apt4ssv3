/* APT023.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0000773.V03   *** */


/* .....FORTRAN SUBROUTINE             APT023...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT023 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS THE INTERSECTION OF TWO PLANES BY THE FOLLOWING */
/*              APT STATEMENT */
/*              RESULT = LINE/INTOF, PL1, PL2 */

/* LINKAGE      CALL APT023 (RESULT, PL1, PL2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING LINE */
/*              PL1     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT PLANE */
/*              PL2     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT PLANE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt023_(doublereal *result, doublereal *pl1, doublereal *
	pl2)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
#define s3 ((doublereal *)&dshar3_1 + 39)
#define s4 ((doublereal *)&dshar3_1 + 40)
    extern /* Subroutine */ int apt077_(doublereal *, integer *), defext_(
	    doublereal *);






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




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     TRANSFORM PL1,PL2,CHECK VALIDITY */

    /* Parameter adjustments */
    --pl2;
    --pl1;
    --result;

    /* Function Body */
    apt077_(&pl1[1], &c__0);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L10: */
	dshar3_1.sc[i__ + 3] = dshar3_1.l[i__ - 1];
    }
    apt077_(&pl2[1], &c__0);

/* ...     SOLVE FOR VERTICAL PLANE AT INTERSECTION OF PL1,PL2 */

    *s1 = dshar3_1.sc[4] * dshar3_1.l[2] - dshar3_1.l[0] * dshar3_1.sc[6];
    *s2 = dshar3_1.sc[5] * dshar3_1.l[2] - dshar3_1.l[1] * dshar3_1.sc[6];
    *s3 = dshar3_1.sc[7] * dshar3_1.l[2] - dshar3_1.l[3] * dshar3_1.sc[6];
    *s4 = sqrt(*s1 * *s1 + *s2 * *s2);

/* ...     TEST FOR PARALLEL PLANES - LINE UNDEFINED */

    if (*s4 < znumbr_1.z1em5) {
	goto L30;
    }
    def_1.r__[0] = *s1 / *s4;
    def_1.r__[1] = *s2 / *s4;
    def_1.r__[3] = *s3 / *s4;
    apt077_(def_1.r__, &knumbr_1.km1);
L20:
    defext_(&result[1]);
    return 0;
L30:
    idef_1.ierror = knumbr_1.k27;
    goto L20;
} /* apt023_ */

#undef s4
#undef s3
#undef s2
#undef s1


