/* APT004.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002787.V03   *** */


/* .... FORTRAN SUBROUTINE              APT004               4/17/68 */

/*              FORTRAN SUBROUTINE APT004 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT */
/*              DEFINED AS THE INTERSECTION OF A LINE AND A */
/*              CIRCLE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = POINT/+***, INTOF, LINE1, CIRC1 */
/*                 **** = XLARGE, YLARGE, XSMALL, OR YSMALL */

/* LINKAGE      CALL APT004 (RESULT, M, LINE1, CIRC1) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING POINT */
/*              M       INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XLARGE 2 = YLARGE */
/*                      4 = XSMALL 5 = YSMALL */
/*              LINE1   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT LINE */
/*              CIRC1   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT CIRCLE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT083 */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          APT001 */
/*              REAL FUNCTION       ABS */
/*              REAL FUNCTION       SQRT */
/*              REAL FUNCTION       SIGN */

/* Subroutine */ int apt004_(doublereal *result, integer *mn, doublereal *
	line1, doublereal *circ1)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer m;
    static doublereal s1, s2;
    extern /* Subroutine */ int apt001_(doublereal *), apt083_(doublereal *, 
	    integer *), apt077_(doublereal *, integer *), error_(integer *, 
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




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/* ...     TRANSFORM CANONICAL FORMS AND CHECK INPUT VALIDITY */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --circ1;
    --line1;
    --result;

    /* Function Body */
    apt077_(&line1[1], &knumbr_1.k5);
    apt083_(&circ1[1], &knumbr_1.k7);
    m = *mn;

/* ...     COMPUTE DISTANCE FROM CENTER TO LINE AND TEST FOR INTERSECTION */

    s1 = dshar3_1.l[3] - dshar3_1.l[0] * dshar3_1.c__[0] - dshar3_1.l[1] * 
	    dshar3_1.c__[1];
    if ((d__1 = abs(s1) - dshar3_1.c__[6], abs(d__1)) <= znumbr_1.z1em5) {
	goto L270;
    }
    if (abs(s1) - dshar3_1.c__[6] > znumbr_1.z1em5) {
	goto L330;
    }

/* ...     COMPUTE CHORD LENGTH AND CHECK MODIFIER FOR VALIDITY */

/* Computing 2nd power */
    d__1 = dshar3_1.c__[6];
/* Computing 2nd power */
    d__2 = s1;
    s2 = sqrt(d__1 * d__1 - d__2 * d__2);
    switch (m) {
	case 1:  goto L140;
	case 2:  goto L170;
	case 3:  goto L170;
	case 4:  goto L140;
	case 5:  goto L170;
    }
L140:
    if (dshar3_1.l[1] < 0.) {
	goto L400;
    } else if (dshar3_1.l[1] == 0) {
	goto L150;
    } else {
	goto L410;
    }
L150:
    error_(&knumbr_1.k8, "APT004  ", (ftnlen)8);
    if (m == knumbr_1.k2 || m == knumbr_1.k3 || m == knumbr_1.k5) {
	goto L330;
    }
L170:
    if (dshar3_1.l[0] < 0.) {
	goto L410;
    } else if (dshar3_1.l[0] == 0) {
	goto L180;
    } else {
	goto L400;
    }
L180:
    error_(&knumbr_1.k9, "APT004  ", (ftnlen)8);
    if (m == knumbr_1.k1 || m == knumbr_1.k4) {
	goto L330;
    }
    goto L140;

/* ...     S(1)=RADIUS,MAKE CHORD LENGTH 0 */

L270:
    s2 = znumbr_1.z0;
    s1 = d_sign(&dshar3_1.c__[6], &s1);
    goto L430;

/* ...     LINE AND CIRCLE DO NOT INTERSECT */

L330:
    idef_1.ierror = knumbr_1.k6;
    ldef_1.unflag = TRUE_;
/* L300: */
    defext_(&result[1]);
    goto L9999;

/* ...     COMPUTE X AND Y, STORE IN RESULT AND CALL APT001 TO GET Z */

L400:
    if (m > knumbr_1.k3) {
	goto L430;
    }
L420:
    s2 = -s2;
    goto L430;
L410:
    if (m > knumbr_1.k3) {
	goto L420;
    }
L430:
    result[1] = dshar3_1.c__[0] + s1 * dshar3_1.l[0] + s2 * dshar3_1.l[1];
    result[2] = dshar3_1.c__[1] + s1 * dshar3_1.l[1] - s2 * dshar3_1.l[0];
    apt001_(&result[1]);
L9999:
    return 0;
} /* apt004_ */

