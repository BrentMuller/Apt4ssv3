/* APT016.f -- translated by f2c (version 20100827).
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

static integer c__21 = 21;
static integer c__22 = 22;

/* *** SOURCE FILE : M0004296.V02   *** */

/* .....FORTRAN SUBROUTINE             APT016...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT016 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS TANGENT TO TWO CIRCLES BY THE FOLLOWING APT */
/*              STATEMENT */
/*              RESULT = LINE/+***, TANTO, CIRC1, ****, TANTO, */
/*                       CIRC2 */
/*                **** = LEFT OR RIGHT */

/* LINKAGE      CALL APT016 (RESULT, M, CIRC1, N, CIRC2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING LINE */
/*              M       INTEGER EQUIVALENT OF THE FIRST MODIFIER */
/*                             1 = RIGHT        2 = LEFT */
/*              CIRC1   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST CIRCLE */
/*              N       INTEGER EQUIVALENT OF THE SECOND MODIFIER */
/*                             1 = RIGHT       2 = LEFT */
/*              CIRC2   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND CIRCLE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT083 */
/*              REAL FUNCTION       ABS */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt016_(doublereal *result, integer *mn, doublereal *
	circ1, integer *nm, doublereal *circ2)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
#define s3 ((doublereal *)&dshar3_1 + 39)
#define s4 ((doublereal *)&dshar3_1 + 40)
#define s5 ((doublereal *)&dshar3_1 + 41)
    extern /* Subroutine */ int apt083_(doublereal *, integer *), apt077_(
	    doublereal *, integer *), vnorm_(doublereal *, doublereal *), 
	    defext_(doublereal *);





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




/* ...     TRANSFORM CANONICAL FORMS AND CHECK INPUT VALIDITY */

    /* Parameter adjustments */
    --circ2;
    --circ1;
    --result;

    /* Function Body */
    apt083_(&circ1[1], &c__21);
    for (i__ = 1; i__ <= 7; ++i__) {
/* L10: */
	dshar3_1.sc[i__ + 4] = dshar3_1.c__[i__ - 1];
    }
    apt083_(&circ2[1], &c__22);

/* ...     CALCULATE DISTANCE BETWEEN CENTERS CHECK FOR CONCENTRIC, */
/* ...        INTERSECTING CIRCLES OR CENTERS TOO CLOSE. */

/* Computing 2nd power */
    d__1 = dshar3_1.c__[0] - dshar3_1.sc[5];
/* Computing 2nd power */
    d__2 = dshar3_1.c__[1] - dshar3_1.sc[6];
    *s1 = sqrt(d__1 * d__1 + d__2 * d__2);
    if (*s1 <= znumbr_1.z1em5) {
	idef_1.ierror = knumbr_1.k23;
    }
    if (idef_1.ierror != 0) {
	goto L30;
    }
    if ((d__1 = dshar3_1.sc[11] - dshar3_1.c__[6], abs(d__1)) - *s1 > 
	    znumbr_1.z1em5) {
	idef_1.ierror = knumbr_1.k24;
    }
    if (idef_1.ierror != 0) {
	goto L30;
    }
    if (*s1 - (dshar3_1.sc[11] + dshar3_1.c__[6]) >= znumbr_1.z1em5) {
	goto L20;
    }
    if (*nm != *mn) {
	idef_1.ierror = knumbr_1.k25;
    }
L20:
    if (idef_1.ierror != 0) {
	goto L30;
    }
/* ...     CALCULATE SIN(ALPHA) AND COS(ALPHA) */

    *s2 = (dshar3_1.c__[1] - dshar3_1.sc[6]) / *s1;
    *s3 = (dshar3_1.c__[0] - dshar3_1.sc[5]) / *s1;
    if (*mn == *nm) {
	dshar3_1.sc[11] = -dshar3_1.sc[11];
    }

/* ...     CALCULATE SIN(GAMMA) AND COS(GAMMA) */

    *s4 = (dshar3_1.c__[6] + dshar3_1.sc[11]) / *s1;
    *s5 = sqrt(znumbr_1.z1 - *s4 * *s4);
    if (*nm == knumbr_1.k1) {
	*s5 = -(*s5);
    }

/* ...     SET UP CANONICAL FORM IN P AND TRANSFORM TO BASE COORDINATES */

    dshar3_1.p[0] = *s4 * *s3 + *s5 * *s2;
    dshar3_1.p[1] = *s4 * *s2 - *s5 * *s3;
    dshar3_1.p[2] = znumbr_1.z0;
    vnorm_(dshar3_1.p, dshar3_1.p);
    dshar3_1.p[3] = dshar3_1.p[0] * dshar3_1.c__[0] + dshar3_1.p[1] * 
	    dshar3_1.c__[1] - dshar3_1.c__[6];
    apt077_(dshar3_1.p, &knumbr_1.km1);
L30:
    defext_(&result[1]);
    return 0;
} /* apt016_ */

#undef s5
#undef s4
#undef s3
#undef s2
#undef s1


