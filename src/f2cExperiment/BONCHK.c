/* BONCHK.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__3 = 3;

/* *** SOURCE FILE : M0001047.V02   *** */

/* Subroutine */ int bonchk_(doublereal *ss, doublereal *b, doublereal *u, 
	doublereal *v, integer *iflag, integer *itop, integer *inum, integer *
	ickbn, integer *idebug)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal zero = 0.;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k, l;
    static doublereal t;
    static integer jj;
    static doublereal bt[64];
    static integer kk, np, npt, ncur, nmesh, itopt[24]	/* was [6][4] */, 
	    iflagt[4];
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);

/* ------ THIS PROGRAM CHECKS FOR A VALID BOUNDARY TRANSITION */
/* ------ IF THE TRANSITION IS VALID, THE ROUTINE REPLACES THE */
/* ------ CURRENT PATCH WITH A NEW ONE */
/* ------ SS IS THE SCULPTURE SURFACE CANON ARRAY */
/* ------ B,IFLAG,ITOP IS THE DEFINING DATA FOR THE CURRENT PATCH */
/* ------ INUM IS THE NUMBER OF THE CURRENT PATCH RELATIVE TO SS */
/* ------ ICKBN IS THE NUMBER OF THE BOUNDARY TO BE CHECKED */
/* ------ U,V SHOULD BE PARAMETRIC COORDINATES ON THIS BOUNDARY */
/* ------ IF THE TRANSITION IS VALID, ALL DATA EXCEPT SS SHOULD */
/* ------ BE REPLACED ON TERMINATION OF THIS PROGRAM. */
/* ------      FIRST CHECK TO SEE IF ANY PATCH AT ALL LIES ACROSS */
/* ------      THIS BOUNDARY. */
    /* Parameter adjustments */
    itop -= 7;
    --iflag;
    --b;
    --ss;

    /* Function Body */

    np = itop[(0 + (0 + (1 + *ickbn * 6 << 2))) / 4];
    if (itop[*ickbn * 6 + 2] == 0) {
	return 0;
    }
/* ------ OTHERWISE CHECK EACH PATCH IN THE LIST */
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ncur = itop[i__ + 1 + *ickbn * 6];
	lodpch_(&ss[1], bt, iflagt, itopt, &ncur, &c__3);
/* ------ CHECK THE TOPOLOGY TABLE OF NCUR FOR A MATCH WITH INUM */
	for (l = 1; l <= 4; ++l) {
	    npt = itopt[l * 6 - 6];
	    if (npt == 0) {
		goto L20;
	    }
	    i__2 = npt;
	    for (k = 1; k <= i__2; ++k) {
		if (itopt[k + 1 + l * 6 - 7] == *inum) {
		    goto L40;
		}
/* L30: */
	    }
	    goto L20;
/* ------ IT IS CLEAR THAT PATCH NCUR S LTH BOUNDARY DOES LIE ON */
/* ------ PATCH INUM S ICKBN-TH BOUNDARY.  THEREFORE, MAY A DETAILED */
/* ------ COMPUTATION IF A CROSSOVER OCCURS AT U,V */
/* ------ SPV IS COMPUTED AS THE CROSSOVER SPACE POINT */
/* ------ IN CASE OF A MESH SURFACE, SKIP MOST OF THE TRANSFER LOGIC */
L40:
	    nmesh = (integer) ss[5];
	    t = *u;
	    if ((*ickbn - 1) * (*ickbn - 4) != 0) {
		t = *v;
	    }
/* ------ THEREFORE GENERATE THE NEW ACTIVE PATCH DATA */
	    *inum = ncur;
	    for (kk = 1; kk <= 64; ++kk) {
		b[kk] = bt[kk - 1];
/* L200: */
	    }
	    for (kk = 1; kk <= 4; ++kk) {
		iflag[kk] = iflagt[kk - 1];
		itop[kk * 6 + 1] = itopt[kk * 6 - 6];
		npt = itop[kk * 6 + 1];
		for (jj = 2; jj <= 6; ++jj) {
		    itop[jj + kk * 6] = itopt[jj + kk * 6 - 7];
/* L210: */
		}
	    }
	    *ickbn = l;
	    if ((*ickbn - 1) * (4 - *ickbn) > 0) {
		goto L220;
	    }
	    *v = zero;
	    if (*ickbn == 4) {
		*v = one;
	    }
	    *u = t;
	    goto L230;
L220:
	    *u = zero;
	    if (*ickbn == 3) {
		*u = one;
	    }
	    *v = t;
L230:
	    return 0;
L20:
	    ;
	}
/* L10: */
    }
    return 0;
} /* bonchk_ */

