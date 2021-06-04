/* APT021.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** SOURCE FILE : M0000771.V02   *** */

/* .....FORTRAN SUBROUTINE              APT021               3/26/68 */

/*              FORTRAN SUBROUTINE APT021 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS HAVING A GIVEN SLOPE (OR FORMING A GIVEN ANGLE WITH */
/*              THE POSITIVE XAXIS) AND A GIVEN X OR Y - INTERCEPT */
/*              BY THE FOLLOWING APT STATEMENTS */
/*              RESULT = LINE/MN,PSI,INTERC,IAX,YIN */

/* LINKAGE      CALL APT021 (RESULT,MN,PSI,IAX,YIN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING LINE */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = ATANGL  2 = SLOPE */
/*              PSI     REAL VARIABLE CONTAINING THE VALUE OF THE */
/*                      ANGLE (IN DEGREES) OR SLOPE */
/*              IAX     INTEGER EQUIVALENT OF THE AXIS */
/*                      1 = XAXIS  2 = YAXIS */
/*              YIN     REAL VARIABLE CONTAINING THE VALUE OF THE */
/*                      X OR Y - INTERCEPT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT012 */
/*              REAL FUNCTION       TAN */

/* Subroutine */ int apt021_(doublereal *result, integer *mn, doublereal *psi,
	 integer *iax, doublereal *yin)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double tan(doublereal);

    /* Local variables */
    static doublereal ps;
    extern /* Subroutine */ int apt012_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */






/* ...     USE APT012 TO FIND LINE THRU TWO POINTS */



/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --result;

    /* Function Body */
    ps = *psi;
    if (*mn == 2) {
	goto L10;
    }
    ps *= znumbr_1.degrad;
    ps = tan(ps);
L10:
    if (*iax == 2) {
	goto L20;
    }
    d__1 = *yin + znumbr_1.z1 / ps;
    apt012_(&result[1], yin, &znumbr_1.z0, &d__1, &znumbr_1.z1);
    goto L30;
L20:
    d__1 = ps + *yin;
    apt012_(&result[1], &znumbr_1.z0, yin, &znumbr_1.z1, &d__1);
L30:
    return 0;
} /* apt021_ */

