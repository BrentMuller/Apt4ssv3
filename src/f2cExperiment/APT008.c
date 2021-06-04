/* APT008.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002791.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT008         8/68                    SR */
/* .....FORTRAN SUBROUTINE             APT008...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT008 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT */
/*              DEFINED AS THE INTERSECTION OF A LINE AND A */
/*              CONIC BY THE FOLLOWING APT STATEMENT */
/*              RESULT = POINT/+***, INTOF, LINE1, G1 */
/*              **** = XLARGE, YLARGE, XSMALL OR YSMALL */

/* LINKAGE      CALL APT008 (RESULT, M, LINE1, G1) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING POINT */
/*              M       INTEGER EQUIVALENT OF THE MODIFIER; */
/*                      1 = XLARGE */
/*                      2 = YLARGE */
/*                      4 = XSMALL */
/*                      5 = YSMALL */
/*              LINE1   ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT LINE */
/*              G1      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT CONIC. */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT079 */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          APT001 */
/*              REAL FUNCTION       ABS */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt008_(doublereal *result, integer *mn, doublereal *
	line1, doublereal *g1)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer m;
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
#define s3 ((doublereal *)&dshar3_1 + 39)
#define s4 ((doublereal *)&dshar3_1 + 40)
#define s5 ((doublereal *)&dshar3_1 + 41)
#define s6 ((doublereal *)&dshar3_1 + 42)
#define s7 ((doublereal *)&dshar3_1 + 43)
#define s8 ((doublereal *)&dshar3_1 + 44)
    extern /* Subroutine */ int apt001_(doublereal *), apt077_(doublereal *, 
	    integer *), apt079_(doublereal *, integer *), error_(integer *, 
	    char *, ftnlen), defext_(doublereal *);






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





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     TRANSFORM CANONICAL FORMS AND CHECK INPUT VALIDITY */

    /* Parameter adjustments */
    --g1;
    --line1;
    --result;

    /* Function Body */
    m = *mn;
    apt077_(&line1[1], &knumbr_1.k5);
    apt079_(&g1[1], &c__0);
    if (abs(dshar3_1.g[2]) > znumbr_1.z1em5 || abs(dshar3_1.g[4]) > 
	    znumbr_1.z1em5 || abs(dshar3_1.g[5]) > znumbr_1.z1em5 || abs(
	    dshar3_1.g[9]) > znumbr_1.z1em5) {
	goto L60;
    }

/* ...     DETERMINE A POINT ON THE LINE */

    *s1 = dshar3_1.l[3] * dshar3_1.l[0];
    *s2 = dshar3_1.l[3] * dshar3_1.l[1];

/* ...     DETERMINE COEFFICIENTS S(3),S(4),S(5) OF QUADRATIC FORMULA */

    *s3 = dshar3_1.g[0] * dshar3_1.l[1] * dshar3_1.l[1] + dshar3_1.g[1] * 
	    dshar3_1.l[0] * dshar3_1.l[0] - znumbr_1.z2 * dshar3_1.g[6] * 
	    dshar3_1.l[1] * dshar3_1.l[0];
    *s4 = dshar3_1.g[0] * *s1 * dshar3_1.l[1] - dshar3_1.g[1] * dshar3_1.l[0] 
	    * *s2 - dshar3_1.g[6] * dshar3_1.l[0] * *s1 + dshar3_1.g[6] * 
	    dshar3_1.l[1] * *s2 + dshar3_1.g[7] * dshar3_1.l[1] - dshar3_1.g[
	    8] * dshar3_1.l[0];
    *s5 = dshar3_1.g[0] * *s1 * *s1 + dshar3_1.g[1] * *s2 * *s2 + dshar3_1.g[
	    3] + znumbr_1.z2 * (dshar3_1.g[6] * *s1 * *s2 + dshar3_1.g[7] * *
	    s1 + dshar3_1.g[8] * *s2);

/* ...     DETERMINE THE RADICAL OF THE QUADRATIC FORMULA */

    *s6 = *s4 * *s4 - *s3 * *s5;
    if (*s6 < -znumbr_1.z1em5) {
	goto L70;
    }
    if ((d__1 = znumbr_1.z1em5 - abs(*s6), abs(d__1)) < znumbr_1.z1em5) {
	*s6 = znumbr_1.z0;
    }
    *s6 = sqrt(*s6);
    if (abs(*s3) < znumbr_1.z1em7) {
	goto L80;
    }

/* ...     DETERMINE THE TWO ROOTS OF THE QUADRATIC FORMULA */

    *s7 = (-(*s4) + *s6) / *s3;
    *s8 = (-(*s4) - *s6) / *s3;

/* ...     SELECT THE CORRECT ROOT DEPENDING ON M */

    switch (m) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L20;
	case 4:  goto L10;
	case 5:  goto L20;
    }
L10:
    if ((d__1 = dshar3_1.l[1] / *s3) < 0.) {
	goto L140;
    } else if (d__1 == 0) {
	goto L30;
    } else {
	goto L100;
    }
L20:
    if ((d__1 = dshar3_1.l[0] / *s3) < 0.) {
	goto L100;
    } else if (d__1 == 0) {
	goto L40;
    } else {
	goto L140;
    }

/* ...     VERTICAL LINE WITH XLARGE OR XSMALL */

L30:
    error_(&knumbr_1.k8, "APT008  ", (ftnlen)8);
    goto L20;

/* ...     HORIZONTAL LINE WITH YLARGE OR YSMALL */

L40:
    error_(&knumbr_1.k9, "APT008  ", (ftnlen)8);
    goto L10;

/* ...     INPUT SURFACE UNDEFINED */

L50:
    ldef_1.unflag = TRUE_;
/* L55: */
    defext_(&result[1]);
    goto L500;

/* ...     CONIC SURFACE CONTAINS VALUES FOR Z COORDINATE */

L60:
    idef_1.ierror = knumbr_1.k16;
    goto L50;

/* ...     LINE AND CONIC DO NOT INTERSECT */

L70:
    idef_1.ierror = knumbr_1.k15;
    goto L50;

/* ...     S(3)=0 - QUAD IS X=-S(5)/S(4)  S(4) LT S(5)*Z1EM7-NO INTERSEC. */

L80:
    if (abs(*s4) < znumbr_1.z1em7 * *s5) {
	goto L70;
    }
    *s7 = -(*s5) / *s4;
    goto L110;

/* ...     DETERMINE LARGE OR SMALL */

L100:
    if (m - knumbr_1.k3 <= 0) {
	goto L110;
    } else {
	goto L130;
    }
L110:
    result[1] = *s1 + dshar3_1.l[1] * *s7;
    result[2] = *s2 - dshar3_1.l[0] * *s7;
L120:
    apt001_(&result[1]);
    goto L500;
L130:
    result[1] = *s1 + dshar3_1.l[1] * *s8;
    result[2] = *s2 - dshar3_1.l[0] * *s8;
    goto L120;
L140:
    if (m - knumbr_1.k3 <= 0) {
	goto L130;
    } else {
	goto L110;
    }
L500:
    return 0;
} /* apt008_ */

#undef s8
#undef s7
#undef s6
#undef s5
#undef s4
#undef s3
#undef s2
#undef s1


