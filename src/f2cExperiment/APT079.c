/* APT079.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000829.V02   *** */

/* .....FORTRAN SUBROUTINE             APT079...              5/1/68   GK */

/*              FORTRAN SUBROUTINE APT079 */

/* PURPOSE      TO SET UP THE COMPLETE PARAMETER LIST FOR THE */
/*              TRANSFORMATION OF THE CANONICAL FORM OF A QUADRIC */
/*              SURFACE WHEN A REFSYS STATEMENT IS IN EFFECT. */

/* LINKAGE      CALL APT079 (SI, IE) */

/* ARGUMENTS    SI      ARRAY CONTAINING THE CANONICAL FORM TO BE */
/*                      TRANSFORMED. */
/*              IE      INTEGER INDICATING TRANSFORMATION DIRECTION. */
/*                      IE + O TRANSFORM LOCAL TO BASE */
/*                      IE = O TRANSFORM BASE TO LOCAL */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          TRANSF */

/* Subroutine */ int apt079_(doublereal *si, integer *ie)
{
    extern /* Subroutine */ int transf_(doublereal *, doublereal *, integer *,
	     integer *, integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */







/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --si;

    /* Function Body */
    transf_(dshar3_1.g, &si[1], &knumbr_1.k1, &knumbr_1.k10, ie);
    return 0;
} /* apt079_ */

