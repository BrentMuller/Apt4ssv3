/* APT047.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__0 = 0;
static doublereal c_b6 = 1.;

/* *** SOURCE FILE : M0000797.V03   *** */


/* .....FORTRAN SUBROUTINE             APT047...              6/10/68 EAN */

/*              FORTRAN SUBROUTINE APT047 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE DEFINED */
/*              AS PARALLEL TO A GIVEN PLANE AND OFFSET A GIVEN */
/*              DISTANCE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = PLANE/PARLEL, P1, ****, D, */
/*                **** = XLARGE, YLARGE, ZLARGE, XSMALL, YSMALL, */
/*                       OR ZSMALL */

/* LINKAGE      CALL APT047 (RESULT, PL, MN, D) */

/* ARGUMENT     RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING PLANE */
/*              PL      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT PLANE */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XLARGE, 2 = YLARGE, 3 = ZLARGE, */
/*                      4 = XSMALL, 5 = YSMALL, 6 = XSMALL */
/*              D       REAL VARIABLE CONTAINING THE VALUE OF */
/*                      OFFSET DISTANCE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       FLOAT */
/*              REMAINDERING FUNCTION MOD */
/*              REAL FUNCTION       SIGN */
/*              LOGICAL FUNCTION    XVECT */

/* Subroutine */ int apt047_(doublereal *result, doublereal *pl, integer *mn, 
	doublereal *d__)
{
    /* Initialized data */

    static doublereal zlit1 = 3.5;
    static integer k59 = 59;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, k;
#define s1 ((doublereal *)&dshar3_1 + 37)
    extern /* Subroutine */ int apt077_(doublereal *, integer *);
    extern logical zvect_(doublereal *);
    static doublereal dummy1;
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




/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     TRANSFORM CANONICAL FORM TO LOCAL COORDINATE SYSTEM */

    /* Parameter adjustments */
    --pl;
    --result;

    /* Function Body */
    apt077_(&pl[1], &c__0);
    if (ldef_1.unflag) {
	goto L50;
    }
    ldef_1.unflag = ! zvect_(dshar3_1.l);

/* ...     CHECK WHICH SIDE NEW PLANE IS ON */

    i__ = (*mn - knumbr_1.k1) % knumbr_1.k3;
    for (k = 1; k <= 3; ++k) {
	dummy1 = (doublereal) (*mn);
	*s1 = dshar3_1.l[i__] * (zlit1 - dummy1);
	if (*s1 != znumbr_1.z0) {
	    goto L30;
	}

/* ...     UNABLE TO DISTINGUISH PLANE, TRY NEXT DIMENSION */

	i__ = (i__ + knumbr_1.k1) % knumbr_1.k3;
/* L20: */
	idef_1.ierror = k59;
    }

/* ...     FORM DESIRED PLANE */

L30:
    dshar3_1.l[3] += *d__ * d_sign(&c_b6, s1);
    apt077_(dshar3_1.l, &knumbr_1.km1);
L40:
    defext_(&result[1]);
    return 0;
L50:
    idef_1.ierror = knumbr_1.k1;
    goto L40;
} /* apt047_ */

#undef s1


