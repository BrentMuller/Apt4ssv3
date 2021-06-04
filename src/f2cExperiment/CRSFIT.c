/* CRSFIT.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__6 = 6;

/* *** SOURCE FILE : M0000621.V02   *** */

/* Subroutine */ int crsfit_(doublereal *sa, doublereal *sb, doublereal *sc, 
	doublereal *sd, integer *ierror)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-10;
    static integer ict = 0;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer j, k, l;
    static doublereal u;
    static integer n1, n2;
    static doublereal va[3], vb[3], cv[16], wa, wb, vec[3];
    static integer nhi, nlo;
    static doublereal sum;
    static integer ient;
    static doublereal temp, proj;
    static integer nrow, ipass;
    extern /* Subroutine */ int blendf_(doublereal *, doublereal *);
    static doublereal floval;
    extern /* Subroutine */ int scdump_(integer *, doublereal *), curflo_(
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
    static integer narcrw, nsegrw;

/* ---     PURPOSE IS TO FILL OUT ALL CROSS SLOPE VECTORS IN */
/* ---     THE CURVES SA,SB GIVEN THAT SA,SB  AND SC,SD FORM */
/* ---     OPPOSITE PAIRS OF A FOUR SIDED PATCH.  ALL CURVES */
/* ---     ARE SINGLE SEGMENT FLOW CURVES. */
/* ---     IF AN ERROR IS ENCOUNTERED, IERROR IS NOT ZERO ON RETURN */
    /* Parameter adjustments */
    --sd;
    --sc;
    --sb;
    --sa;

    /* Function Body */

/* ---     MAKE TWO PASSES, ONE FOR THE CURVE SA, THE OTHER FOR SB */


    ient = *ierror;
    *ierror = 0;

    ict += 10;
    if (ibugg_1.ibug == 11) {
	scdump_(&ict, &sa[1]);
    }
    if (ibugg_1.ibug == 11) {
	scdump_(&c__2, &sb[1]);
    }
    if (ibugg_1.ibug == 11) {
	scdump_(&c__3, &sc[1]);
    }
    if (ibugg_1.ibug == 11) {
	scdump_(&c__4, &sd[1]);
    }
    for (ipass = 1; ipass <= 2; ++ipass) {
	u = (doublereal) (ipass - 1);
/* ---     PICK UP CROSS VECTORS AT ENDS FROM SC AND SD */
	curflo_(&u, &sc[1], cv, &c__1, &c__1);
	for (l = 1; l <= 3; ++l) {
/* L20: */
	    va[l - 1] = cv[l + 3];
	}
	curflo_(&u, &sd[1], cv, &c__1, &c__1);
	for (l = 1; l <= 3; ++l) {
/* L30: */
	    vb[l - 1] = cv[l + 3];
	}

/* ---     STORE THESE VECTORS INTO THE ENDS OF CURVE SA OR SB */
	if (ipass == 2) {
	    goto L350;
	}

	n1 = 16;
	n2 = (integer) ((sa[2] + sa[4] - one) * 24.f + 16.f);
	for (l = 1; l <= 3; ++l) {
	    sa[n1 + l] = va[l - 1];
/* L310: */
	    sa[n2 + l] = vb[l - 1];
	}
	sa[n1 + 4] = one;
	sa[n2 + 4] = one;
	goto L390;

L350:
	n1 = 16;
	n2 = (integer) ((sb[2] + sb[4] - one) * 24.f + 16.f);
	for (l = 1; l <= 3; ++l) {
	    sb[n1 + l] = va[l - 1];
/* L320: */
	    sb[n2 + l] = vb[l - 1];
	}
	sb[n1 + 4] = one;
	sb[n2 + 4] = one;
L390:

/* ---      SKIP OTHER CALCULATIONS IF IENT IS -11 */
	if (ient == -11) {
	    goto L10;
	}

/* ---     DETERMINE N1,N2 THE STARTING AND ENDING ARC JUNCTIONS */
	n1 = 0;
	if (ipass == 2) {
	    goto L40;
	}
	narcrw = (integer) sa[7];
	nsegrw = (integer) sa[9];
	n2 = (integer) (sa[nsegrw + 1] + n1);
	goto L50;
L40:
	narcrw = (integer) sb[7];
	nsegrw = (integer) sb[9];
	n2 = (integer) (sb[nsegrw + 1] + n1);
L50:

/* ---     NLO,NHI REPRESENT JUNCTION PT LIMITS TO BE TESTED AND */
/* ---     IF NECESSARY TO RECEIVE CROSS SLOPE VECTORS */
	nlo = n1 + 1;
	nhi = n2 - 1;
	if (nhi < nlo) {
	    goto L10;
	}

	i__1 = nhi;
	for (k = nlo; k <= i__1; ++k) {
	    nrow = narcrw + (k << 2);

/* ---     DETERMINE FLOW VALUE OF THIS JUNCTION POINT */
	    if (ipass == 2) {
		goto L70;
	    }
	    nrow = (integer) sa[nrow];
	    floval = sa[nrow];
	    goto L80;
L70:
	    nrow = (integer) sb[nrow];
	    floval = sb[nrow];
L80:
/* ---     DETERMINE THE BLEND OF END VECTORS BASED ON FLOVAL */
	    blendf_(&floval, cv);
	    for (l = 1; l <= 3; ++l) {
/* L90: */
		vec[l - 1] = cv[0] * va[l - 1] + cv[1] * vb[l - 1];
	    }
	    wa = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);

/* ---     NOW CHECK THIS JUNCTION FOR CONSTRAINT DATA ALREADY THERE */
	    j = k * 24 + 16;
	    if (ipass == 1) {
		temp = sa[j + 4];
	    }
	    if (ipass == 2) {
		temp = sb[j + 4];
	    }
	    if ((d__1 = temp - one, abs(d__1)) > smal) {
		goto L100;
	    }

/* ---     A CROSS VECTOR IS ALREADY PRESENT, MODIFY ITS LENGTH TO WA */
	    if (ipass == 2) {
		goto L110;
	    }
/* Computing 2nd power */
	    d__1 = sa[j + 1];
/* Computing 2nd power */
	    d__2 = sa[j + 2];
/* Computing 2nd power */
	    d__3 = sa[j + 3];
	    wb = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    if (wb < smal) {
		goto L140;
	    }
	    wb = wa / wb;
	    for (l = 1; l <= 3; ++l) {
/* L120: */
		sa[j + l] = wb * sa[j + l];
	    }
	    goto L60;
L110:
/* Computing 2nd power */
	    d__1 = sb[j + 1];
/* Computing 2nd power */
	    d__2 = sb[j + 2];
/* Computing 2nd power */
	    d__3 = sb[j + 3];
	    wb = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    if (wb < smal) {
		goto L140;
	    }
	    wb = wa / wb;
	    for (l = 1; l <= 3; ++l) {
/* L130: */
		sb[j + l] = wb * sb[j + l];
	    }
	    goto L60;

L100:
	    if (ipass == 1) {
		temp = sa[j + 8];
	    }
	    if (ipass == 2) {
		temp = sb[j + 8];
	    }
	    if ((d__1 = temp - one, abs(d__1)) > smal) {
		goto L140;
	    }

/* ---     A SURFACE NORMAL CONSTRAINT IS PRESENT, PROJECT VEC */
/* ---     INTO THE PLANE OF THIS NORMAL AND ASSIGN WA AS LENGTH */
	    if (ipass == 2) {
		goto L150;
	    }
/* Computing 2nd power */
	    d__1 = sa[j + 5];
/* Computing 2nd power */
	    d__2 = sa[j + 6];
/* Computing 2nd power */
	    d__3 = sa[j + 7];
	    wb = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    if (wb < smal) {
		goto L140;
	    }
	    proj = (vec[0] * sa[j + 5] + vec[1] * sa[j + 6] + vec[2] * sa[j + 
		    7]) / wb;
	    sum = zero;
	    for (l = 1; l <= 3; ++l) {
		vec[l - 1] -= proj * sa[j + 4 + l] / wb;
/* L160: */
/* Computing 2nd power */
		d__1 = vec[l - 1];
		sum += d__1 * d__1;
	    }
	    sum = sqrt(sum);
	    if (sum < smal) {
		goto L140;
	    }
	    wb = wa / sum;
	    for (l = 1; l <= 3; ++l) {
/* L170: */
		sa[j + l] = wb * vec[l - 1];
	    }
	    goto L60;

L150:
/* Computing 2nd power */
	    d__1 = sb[j + 5];
/* Computing 2nd power */
	    d__2 = sb[j + 6];
/* Computing 2nd power */
	    d__3 = sb[j + 7];
	    wb = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    if (wb < smal) {
		goto L140;
	    }
	    proj = (vec[0] * sb[j + 5] + vec[1] * sb[j + 6] + vec[2] * sb[j + 
		    7]) / wb;
	    sum = zero;
	    for (l = 1; l <= 3; ++l) {
		vec[l - 1] -= proj * sb[j + 4 + l] / wb;
/* L180: */
/* Computing 2nd power */
		d__1 = vec[l - 1];
		sum += d__1 * d__1;
	    }
	    sum = sqrt(sum);
	    if (sum < smal) {
		goto L140;
	    }
	    wb = wa / sum;
	    for (l = 1; l <= 3; ++l) {
/* L190: */
		sb[j + l] = wb * vec[l - 1];
	    }
	    goto L60;

L140:
/* ---     USE VEC TO DETERMINE THE CROSS CONSTRAINT AT JUNCTION J */
	    if (ipass == 2) {
		goto L200;
	    }
	    for (l = 1; l <= 3; ++l) {
/* L210: */
		sa[j + l] = vec[l - 1];
	    }
	    sa[j + 4] = one;
	    goto L60;
L200:
	    for (l = 1; l <= 3; ++l) {
/* L220: */
		sb[j + l] = vec[l - 1];
	    }
	    sb[j + 4] = one;

L60:
	    ;
	}

L10:
	;
    }

    if (ibugg_1.ibug == 11) {
	scdump_(&c__5, &sa[1]);
    }
    if (ibugg_1.ibug == 11) {
	scdump_(&c__6, &sb[1]);
    }

    *ierror = 0;
    return 0;
} /* crsfit_ */

