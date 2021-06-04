/* PARAL.f -- translated by f2c (version 20100827).
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

static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0000644.V04   *** */

/* Subroutine */ int paral_(doublereal *veca, doublereal *dist, doublereal *
	vecb, doublereal *avdist, integer *nspl, integer *npts, integer *
	ipara)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, k, j1, j2, jj;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
    static doublereal bot;
    static integer ipt;
    static doublereal top, sum;
    static integer ivec, jseg, kvec, nseg, iptb, ispl;
    static doublereal alen1, alen2;
    static integer ivecb, kvecb;
    static doublereal anspl;

/* ---      PURPOSE OF PARAL IS TO DETERMINE LENGTHS OF TANGENT */
/* ---      VECTORS IN ONE PARAMETRIC DIRECTION ACROSS A MESH SURFACE */
/* ---      VECA IS THE ARRAY OF UNITIZED INPUT TANGENTS AND */
/* ---      ON OUTPUT IS THE ENTERING VECTOR FOR A PATCH AT EACH POINT */
/* ---      DIST IS THE ARRAY OF POLYGONAL DISTANCES BETWEEN POINTS */
/* ---      VECB IS AN OUTPUT ARRAY OF EXITING VECTORS FOR EACH PAOINT */
/* ---      AVDIST IS AN INPUT ARRAY USED TO TEMPORARILY HOLD THE */
/* ---      AVERAGE WIDTH OF CHORDAL BANDS ACROSS THE SURFACE */
/* ---      NSPL IS THE TOTAL NUMBER OF SPLINE CURVES AND */
/* ---      NPTS IS THE NUMBER OF POINTS PER SPLINE(BOTH INPUT) */
/* ---      IPARA IS SET TO 1 IF ROUGHLY PARALLEL CHORDAL BANDS */
/* ---      ARE DETECTED ACROSS THE SURFACE, AND 0 OTHERWISE */
/* ---      IPARA IS SET TO 1 ON OUTPUT. */

/* ---      NUMBER OF CHORDS PER SPLINE */
    /* Parameter adjustments */
    --avdist;
    --vecb;
    --dist;
    --veca;

    /* Function Body */
    nseg = *npts - 1;
    anspl = (doublereal) (*nspl);
/* ---      CHECK FOR ROUGH EQUALITY OF CHORDS ACROSS SURFACE */
    i__1 = nseg;
    for (jseg = 1; jseg <= i__1; ++jseg) {
/* ---      COMPUTE THE AVERAGE BAND WIDTH OF THE JTH CHORDS. */
	sum = 0.f;
	i__2 = *nspl;
	for (ispl = 1; ispl <= i__2; ++ispl) {
	    jj = nseg * (ispl - 1) + jseg;
	    sum += dist[jj];
/* L20: */
	}
/* ---      AVERAGE BANDWIDTH */
	avdist[jseg] = sum / anspl;
/* ---      IF IPARA IS 1 ON INPUT, THEN ASSUME PARALLELISM */
	if (*ipara == 1) {
	    goto L10;
	}

/* ---      SET TOLERANCE FOR EQUALITY OF CHORDS */
	bot = avdist[jseg] * .95f;
	top = avdist[jseg] * 1.06f;
/* ---      CHECK ALL CHORDS IN THIS BAND. */
	i__2 = *nspl;
	for (ispl = 1; ispl <= i__2; ++ispl) {
	    jj = nseg * (ispl - 1) + jseg;
	    if (bot <= dist[jj] && dist[jj] <= top) {
		goto L30;
	    }
/* ---      PARALLELISM CHECK FAILED */
	    *ipara = 0;
	    goto L90;
L30:
	    ;
	}

L10:
	;
    }

/* ---      SURFACE WILL BE TREATED AS PARALLEL. */
    *ipara = 1;
L90:
/* ---      IF SURFACE HAS ONLY A SINGLE CROSS BAND, USE NON-PARALLEL */
    if (nseg <= 1) {
	*ipara = 0;
    }

/* ---      SECOND PHASE, ASSIGN LENGTHS TO INCOMING AND OUTGOING */
/* ---      VECTORS AT EACH POINT */

    i__1 = *nspl;
    for (ispl = 1; ispl <= i__1; ++ispl) {
	i__2 = *npts;
	for (ipt = 1; ipt <= i__2; ++ipt) {
	    ivec = (ipt - 1 + (ispl - 1) * *npts) * 3;
/* ---      A SEPARATE POINTER IS SET UP FOR THE ARRAY OF */
/* ---      EXITING VECTORS VECB. THIS ARRAY IS OF DIMENSION */
/* ---      NSEG X NSPL COMPARED WITH NPTS X NSPL FOR VECA AND */
/* ---      POINTERS FOR VECB ARE SET UP SO THAT THE FIRST ENTRY */
/* ---      IS OVERWRITTEN IN NPT PASSES THRU THIS LOOP */
/* Computing MAX */
	    i__3 = ipt - 1;
	    iptb = max(i__3,1);
	    ivecb = (iptb - 1 + (ispl - 1) * nseg) * 3;
/* ---      COMPUTE REFERENCE CHORD FOR VECTOR LENGTHS */
/* Computing MAX */
	    i__3 = ipt - 1;
	    j1 = max(i__3,1);
	    j2 = min(ipt,nseg);

	    if (*ipara == 1) {
		goto L110;
	    }
/* ---      SHARED VECTOR CASE */
	    j1 += (ispl - 1) * nseg;
	    j2 += (ispl - 1) * nseg;
/* ---      CHOOSE THE MINIMUM OF THE TWO SURROUNDING CHORDS */
	    alen1 = dist[j1];
	    if (alen1 > dist[j2]) {
		alen1 = dist[j2];
	    }
	    alen2 = alen1;
	    goto L120;
/* ---      PARALLEL CASE, CHOOSE SEPARATE LENGTHS */
L110:
	    alen1 = avdist[j2];
	    alen2 = avdist[j1];
L120:
/* ---      VECB IS SET TO THE LENGTH OF THE EXITING VECTOR */
	    for (k = 1; k <= 3; ++k) {
		kvec = ivec + k;
		kvecb = ivecb + k;
		vecb[kvecb] = alen2 * veca[kvec];
		veca[kvec] = alen1 * veca[kvec];
/* L130: */
	    }

/* L100: */
	}
    }

/* ---      END OF LOOP, CHANGE IPARA TO 1 */
    if (ibugg_1.ibug == 11) {
	bad_(&c_n1, &c__0, "IPAR", ipara, (ftnlen)4);
    }
    *ipara = 1;
/* ---      CLEAN UP AVDIST ARRAY */
    i__2 = nseg;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L200: */
	avdist[i__] = 0.f;
    }

/* L999: */
    return 0;
} /* paral_ */

