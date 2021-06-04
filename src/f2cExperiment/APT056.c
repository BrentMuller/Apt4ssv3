/* APT056.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000806.V02   *** */

/* .....FORTRAN SUBROUTINE             APT056...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT056 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CONE */
/*              DEFINED AS HAVING A GIVEN VERTEX POINT, A */
/*              GIVEN AXIS VECTOR, AND A GIVEN VALUE OF ITS */
/*              HALF ANGLE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = CONE/PN, VE, BETA */

/* LINKAGE      CALL APT056 (RESULT, PN, VE, BETA) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING CONE */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT POINT */
/*              VE      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT VECTOR */
/*              BETA    REAL VARIABLE CONTAINING THE VALUE */
/*                      OF THE DESIRED HALF ANGLE (DEGREES) */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT040 */
/*              LOGICAL FUNCTION    CKDEF */
/*              REAL FUNCTION       COS */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          ERROR */
/*              LOGICAL FUNCTION    ZVECT */

/* Subroutine */ int apt056_(doublereal *result, doublereal *pn, doublereal *
	ve, doublereal *beta)
{
    /* Builtin functions */
    double cos(doublereal);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int apt040_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *), zvect_(doublereal *);
    extern /* Subroutine */ int defext_(doublereal *);





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




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/* ...     CHECK INPUT VALIDITY, STORE ARGUMENTS */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --ve;
    --pn;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	def_1.r__[i__ - 1] = pn[i__];
/* L10: */
	def_1.r__[i__ + 2] = ve[i__];
    }
    ldef_1.unflag = ckdef_(def_1.r__);

/* ...     CHECK HALF-ANGLE .LE. 90 DEGREES, VECTOR NON-ZERO */

    if (*beta > znumbr_1.z90) {
	idef_1.ierror = knumbr_1.k48;
    }
    if (! zvect_(&def_1.r__[3])) {
	idef_1.ierror = knumbr_1.k47;
    }

/* ...     NORMALIZE VECTOR, TAKE COSINE OF BETA */

    apt040_(&def_1.r__[3], &def_1.r__[3]);
    def_1.r__[6] = cos(*beta * znumbr_1.degrad);
    defext_(&result[1]);
    return 0;
} /* apt056_ */

