/* DISEG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000626.V02   *** */

/* Subroutine */ int diseg_(integer *iseg, doublereal *cin, doublereal *cout, 
	integer *mxout, integer *ierror)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal zero = 0.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, n1, n2, ki, ko, nn, kix, kox, iarc, narc, nseg, 
	    narc1, narc2;
    static doublereal abias;
    static integer nbasi, nbaso, nflow, nsize, nflow1, nflow2, nsegrw;

/* ---     PURPOSE IS TO EXTRACT A SINGLE SEGMENT FROM AN S-CURV */
/* ---     AND TO CONVERT IT INTO A COMPLETE SYNTHETIC CURVE WITH */
/* ---     A SINGLE FLOW SEGMENT */
/* ---     INPUT ISEG REFERS TO A VALID CURVE SEGMENT FOR A FLOW */
/* ---     TYPE ARC.  IF THE ARC IS A SIMPLE NON FLOW TYPE ISEG */
/* ---     DEFAULTS TO AN ARC REFERENCE.  FINALLY A NEGATIVE ISEG */
/* ---     ALWAYS REFERS TO AN ARC. */
/* ---     CIN IS THE INPUT CURVE STRUCTURE */
/* ---     COUT IS THE OUTPUT SINGLE SEGMENT STRUCTURE */
/* ---     MXOUT IS THE MAXIMUM SPACE AVAILABLE FOR AN OUTPUT CURVE */
/* ---     IERROR NOT ZERO ON RETURN INDICATES AN ERROR */

    /* Parameter adjustments */
    --cout;
    --cin;

    /* Function Body */

/* ---     BRANCH TO ARC CALCULATION IF ISEG IS NEGATIVE */
    if (*iseg < 0) {
	goto L300;
    }
    nseg = (integer) cin[8];
    if (nseg == 0) {
	goto L300;
    }
/* ****    INPUT SEGMENT NUMBER IS INVALID */
/* ---    DETERMINE ARCS WHICH MAKE UP THIS SEGMENT REFERENCE */
    *ierror = 1;
    if (*iseg < 1 || *iseg > nseg) {
	goto L9998;
    }
    nsegrw = (integer) (cin[9] + (*iseg - 1 << 2));
    narc1 = (integer) (cin[nsegrw] * 4.f + cin[7]);
    narc2 = (integer) (narc1 + (cin[nsegrw + 1] - one) * 4.f);
    nflow1 = (integer) cin[narc1];
    nflow2 = (integer) (cin[narc2] + cin[narc2 + 1] * 4.f - one);
/* ---     ARC NUMBERS */
    n1 = (integer) (cin[nsegrw] + one);
    n2 = (integer) (n1 + cin[nsegrw + 1] - one);
/* ---     SET UP HEADER TABLE FIRST */
    cout[1] = zero;
    cout[2] = one;
    cout[3] = 10.f;
    cout[4] = (doublereal) ((narc2 - narc1) / 4 + 1);
    cout[5] = cout[2] * 24.f + one;
    cout[6] = cout[4];
    cout[7] = cout[5] + cout[4] * 24.f;
    cout[8] = one;
    cout[9] = cout[7] + cout[6] * 4.f;
    cout[10] = (doublereal) ((nflow2 - nflow1 + 1) / 4);
    cout[11] = cout[9] + cout[8] * 4.f;
    cout[12] = cout[11] + cout[10] * 4.f - one;
    cout[13] = one;
    narc = (integer) cout[4];
    nsize = (integer) cout[12];
/* ****    CURVE TOO LARGE FOR BUFFER AREA */
    *ierror = 2;
    if (nsize > *mxout) {
	goto L9998;
    }
/* ---     ZERO OUT REMAINDER OF CANON AREA */
    i__1 = nsize;
    for (i__ = 14; i__ <= i__1; ++i__) {
/* L100: */
	cout[i__] = zero;
    }
    narc = (integer) cout[4];
/* ---     NOW MOVE CUBIC ARC DATA */
    ko = (integer) (cout[5] - 9.f);
    ki = (integer) (cin[5] - 8.f + (n1 - 1) * 24);
    nn = (integer) (ki + cout[4] * 24.f + 7);
    i__1 = nn;
    for (i__ = ki; i__ <= i__1; ++i__) {
	++ko;
	cout[ko] = cin[i__];
/* L110: */
    }

/* ---     NOW MOVE ARC FLOW SUMMARY BLOCKS */
    ko = (integer) (cout[7] - one);
    ki = narc1 - 1;
    abias = cin[ki + 1] - cout[11];
    i__1 = narc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	kox = ko + (i__ - 1 << 2);
	kix = ki + (i__ - 1 << 2);
	for (j = 2; j <= 4; ++j) {
/* L150: */
	    cout[kox + j] = cin[kix + j];
	}
	cout[kox + 1] = cin[kix + 1] - abias;
/* L140: */
    }
/* ---     MOVE SEGMENT DATA */
    ki = (integer) (cin[9] - one + (*iseg - 1 << 2));
    ko = (integer) (cout[9] - one);
    cout[ko + 1] = zero;
    cout[ko + 2] = cin[ki + 2];
    cout[ko + 3] = cin[ki + 3];
    cout[ko + 4] = cin[ki + 4];
/* ---    FINALLY TRANSFER ALL PERTINENT FLOW BLOCKS */
    ki = (integer) (cin[nsegrw] * 4.f + cin[7]);
    ki = (integer) (cin[ki] - one);
    ko = (integer) (cout[11] - one);
    nflow = (integer) (cout[10] * 4.f);
    i__1 = nflow;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L160: */
	cout[ko + i__] = cin[ki + i__];
    }
/* --- */
    goto L9997;


/* ---     SURFACE IS OF SIMPLE NON-FLOW TYPE. ISEG IS THEN AN */
/* ---     ARC-TYPE REFERENCE */
L300:
    iarc = abs(*iseg);
    nsize = 48;
/* ****    THERE IS NOT ENOUGH ROOM TO DECOMPOSE ARC */
    *ierror = 3;
    if (nsize > *mxout) {
	goto L9998;
    }
    for (i__ = 1; i__ <= 48; ++i__) {
/* L310: */
	cout[i__] = zero;
    }
    cout[2] = one;
    cout[3] = 2.f;
    cout[4] = one;
    cout[12] = 48.f;
    nseg = (integer) cin[4];
/* ****    ARC REFERENCE IS OUT OF RANGE */
    *ierror = 4;
    if (iarc < 1 || iarc > nseg) {
	goto L9998;
    }
    nbasi = (integer) (cin[2] * 24.f + (iarc - 1) * 24 - 8.f);
    nbaso = (integer) (cout[2] * 24.f - 8.f);
    for (i__ = 1; i__ <= 32; ++i__) {
/* L320: */
	cout[i__ + nbaso] = cin[i__ + nbasi];
    }
    goto L9997;

L9997:
    *ierror = 0;
    goto L9999;
L9998:
/* ---    ERROR EXIT PATH */
    goto L9999;

L9999:
    return 0;
} /* diseg_ */

