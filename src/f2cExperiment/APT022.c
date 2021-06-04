/* APT022.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0000772.V03   *** */


/* .....FORTRAN SUBROUTINE              APT022                3/5/68 */

/*              FORTRAN SUBROUTINE APT022 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS PASSING THROUGH A GIVEN POINT AND FORMING A */
/*              SPECIFIED ANGLE OR SLOPE WITH A GIVEN LINE BY THE */
/*              FOLLOWING APT STATEMENTS */
/*              RESULT = LINE/PN, ATANGL, PSI, LIN */
/*              RESULT = LINE/PN, SLOPE, PSI, LIN */

/* LINKAGE      CALL APT022 (RESULT,PN,MN,PSI,LIN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING LINE */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT POINT */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = ATANGL  2 = SLOPE */
/*              PSI     REAL VARIABLE CONTAINING THE VALUE OF */
/*                      THE ANGLE (IN DEGREES) OR SLOPE */
/*              LIN     ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT LINE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          VNORM */
/*              REAL FUNCTION       SIN */
/*              REAL FUNCTION       COS */
/*              REAL FUNCTION       ATAN */

/* Subroutine */ int apt022_(doublereal *result, doublereal *pn, integer *mn, 
	doublereal *psi, doublereal *lin)
{
    /* Builtin functions */
    double atan(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
#define s3 ((doublereal *)&dshar3_1 + 39)
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt077_(
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




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     TRANSFORM PN, LIN, CHECK VALIDITY */

    /* Parameter adjustments */
    --lin;
    --pn;
    --result;

    /* Function Body */
    apt081_(&pn[1], &c__0);
    apt077_(&lin[1], &knumbr_1.k26);
    if (*mn == knumbr_1.k1) {
	goto L10;
    }
    *s1 = atan(*psi);
    goto L20;
L10:
    *s1 = *psi * znumbr_1.degrad;
L20:
    *s2 = sin(*s1);
    *s3 = cos(*s1);

/* ...     CALCULATE UNIT NORMAL R(1),R(2) */

    def_1.r__[0] = dshar3_1.l[0] * *s3 - dshar3_1.l[1] * *s2;
    def_1.r__[1] = dshar3_1.l[0] * *s2 + dshar3_1.l[1] * *s3;
    def_1.r__[2] = 0.f;
    vnorm_(def_1.r__, def_1.r__);

    def_1.r__[3] = dshar3_1.p[0] * def_1.r__[0] + dshar3_1.p[1] * def_1.r__[1]
	    ;
    apt077_(def_1.r__, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt022_ */

#undef s3
#undef s2
#undef s1


