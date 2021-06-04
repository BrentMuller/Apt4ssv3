/* APT069.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000819.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT069         8/68                    RN */
/* .....FORTRAN SUBROUTINE              APT069 */

/*              FORTRAN SUBROUTINE APT069 */

/* PURPOSE      TO GENERATE A MATRIX OF ROTATION ABOUT */
/*              A POINT AND VECTOR BY THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/ PT1,VEC1, ANGLE */

/* LINKAGE      CALL APT069 (RESULT,PT,VT1,BETA) */

/* ARGUMENTS   RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              PT      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      INPUT POINT */
/*              VT1     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      INPUT VECTOR */
/*              BETA    REAL VARIABLE CONTAINING THE VALUE OF */
/*                      ROTATION ANGLE (DEGREES) */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          VNORM */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DOTF */
/*              REAL    FUNCTION    DCOS */
/*              REAL    FUNCTION    DSIN */

/* Subroutine */ int apt069_(doublereal *result, doublereal *pt, doublereal *
	vt1, doublereal *beta)
{
    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, j;
#define d1 ((doublereal *)&dshar3_1 + 37)
#define alp ((doublereal *)&dshar3_1 + 37)
#define omc ((doublereal *)&dshar3_1 + 40)
#define cosa ((doublereal *)&dshar3_1 + 38)
#define sina ((doublereal *)&dshar3_1 + 39)
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);





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



    /* Parameter adjustments */
    --vt1;
    --pt;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&pt[1]) || ckdef_(&vt1[1]);
    vnorm_(&vt1[1], dshar3_1.v);
    *alp = *beta * znumbr_1.degrad;
    *cosa = cos(*alp);
    *sina = sin(*alp);
    if (abs(*cosa) < znumbr_1.z1em9) {
	*cosa = znumbr_1.z0;
    }
    if (abs(*sina) < znumbr_1.z1em9) {
	*sina = znumbr_1.z0;
    }
    *omc = znumbr_1.z1 - *cosa;
    result[1] = *cosa;
    result[2] = -dshar3_1.v[2] * *sina;
    result[3] = dshar3_1.v[1] * *sina;
    result[5] = dshar3_1.v[2] * *sina;
    result[6] = *cosa;
    result[7] = -dshar3_1.v[0] * *sina;
    result[9] = -dshar3_1.v[1] * *sina;
    result[10] = dshar3_1.v[0] * *sina;
    result[11] = *cosa;
    for (j = 1; j <= 3; ++j) {
	*d1 = dshar3_1.v[j - 1];
	result[j] = dshar3_1.v[0] * *omc * *d1 + result[j];
	result[j + 4] = dshar3_1.v[1] * *omc * *d1 + result[j + 4];
/* L10: */
	result[j + 8] = dshar3_1.v[2] * *omc * *d1 + result[j + 8];
    }
    j = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	dotf_(&result[j + 4], &result[j + 1], &pt[1]);
	result[j + 4] = pt[i__] - result[j + 4];
/* L20: */
	j += 4;
    }
    return 0;
} /* apt069_ */

#undef sina
#undef cosa
#undef omc
#undef alp
#undef d1


