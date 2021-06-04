/* APT054.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000804.V02   *** */

/* .....FORTRAN SUBROUTINE             APT054...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT054 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CYLINDER */
/*              DEFINED AS HAVING A GIVEN POINT ON ITS AXIS, */
/*              THREE GIVEN COMPONENTS OF ITS AXIS VECTOR, AND */
/*              A GIVEN RADIUS, BY THE FOLLOWING APT STATEMENT */
/*              RESULT = CYLNDR/PN, AX, AY, AZ, R */

/* LINKAGE      CALL APT054 (RESULT, PN, AX, AY, AZ, RAD) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING CYLINDER */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT POINT */
/*              AX      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF X COMPONENT OF THE AXIS VECTOR */
/*              AY      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF Y COMPONENT OF THE AXIS VECTOR */
/*              AZ      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF Z COMPONENT OF THE AXIS VECTOR */
/*              RAD     REAL VARIABLE CONTAINING THE VALUE */
/*                      OF THE DESIRED RADIUS */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT055 */
/*              SUBROUTINE          APT081 */

/* Subroutine */ int apt054_(doublereal *result, doublereal *pn, doublereal *
	ax, doublereal *ay, doublereal *az, doublereal *rad)
{
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt055_(
	    doublereal *, doublereal *, doublereal *, doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pn;
    --result;

    /* Function Body */
    def_1.r__[0] = *ax;
    def_1.r__[1] = *ay;
    def_1.r__[2] = *az;
    apt081_(def_1.r__, &knumbr_1.km1);
    apt055_(&result[1], &pn[1], def_1.r__, rad);
    return 0;
} /* apt054_ */

