/* TOPGEN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000680.V02   *** */

/* Subroutine */ int topgen_(doublereal *ss)
{
    /* Initialized data */

    static integer nsz[4] = { 1,4,12,16 };
    static integer nboun[8] = { 1,2,1,3,2,4,3,4 };
    static doublereal zero = 0.;
    static doublereal smal = 1e-10;
    static integer izero = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal d__;
    static integer i__, j, k, l, m;
    static doublereal p[12]	/* was [3][4] */;
    static integer ja, jb, ma, mb, kk, nn, np, kt, ns;
    static doublereal pt[12]	/* was [3][4] */;
    static integer ncur, itop, ntot, itop1, iprel, ktemp, ntype, itopij, 
	    iprelt, nlower, nupper;

/* ---     ROUTINE TO GENERATE A TOPOLOGY TABLE FOR AN OTHERWISE COMPLETE */
/* ---      SS DATA STRUCTURE */
    /* Parameter adjustments */
    --ss;

    /* Function Body */

/* ---     NTOT IS THE TOTAL NUMBER OF PATCHES IN THE SS ARRAY */
    ntot = (integer) ss[4];
/* ---    SPECIAL HANDLING FOR A GENCUR SURFACE */
    if (ss[6] < 5.999f || ss[6] > 6.001f) {
	goto L10;
    }
    itop1 = (integer) (ntot * 6 + 11 + ss[2]);
    goto L25;

L10:
/* ---   TOPOLOGY TABLE IS ASSUMED REGULAR(CONTACT AT CORNER POINTS ONLY) */
/* ---     FILL IN POINTERS FROM EACH PATCH HEADER TO TOPOLOGY TABLE */
/* ---     ALSO ZERO OUT THE TOPOLOGY TABLE ENTRIES */
    itop1 = (ntot - 1) * 6 + 15;
    itop1 = (integer) ss[itop1];
/* ---     ITOP1 IS THE LOCATION OF THE LAST PATCH COEFFICIENT ARRAY */
    for (k = 1; k <= 4; ++k) {
	i__ = (integer) ss[ntot * 6 + 4 + k];
	itop1 += nsz[i__ - 1];
/* L20: */
    }
L25:
/* ---     ITOP1 IS THE SS LOCATION OF THE FIRST TOPOLOGY TABLE ENTRY */
/* ---      FILL POINTERS TO THE TOPOLOGY TABLE FOR EACH PATCH */
    i__1 = ntot;
    for (k = 1; k <= i__1; ++k) {
	ss[k * 6 + 10] = (doublereal) (itop1 + (k - 1 << 2));
	kt = (integer) (ss[k * 6 + 10] - 1);
/* ---     ZERO OUT THE TOPOLOGY TABLE ENTRIES */
	for (kk = 1; kk <= 4; ++kk) {
	    ss[kt + kk] = 0.f;
/* L30: */
	}
    }
/* ---  NOW SEPARATE THE CASE OF A MESH SURFACE FROM PNTSON,PNTVEC,POLYGN */
    ntype = (integer) ss[5];
    if (ntype != 2) {
	goto L200;
    }
/* ---     SURFACE IS A MESH TYPE */
/* ------NUMBER OF PATCHES IN A STRIP ALONG THE MAJOR SPLINE DIRECTION */
    np = (integer) (ss[10] - 1);
/* ---     NUMBER OF PATCHES IN A STRIP ALONG THE CROSS SPLINE DIRECTION */
    ns = (integer) (ss[9] - 1);
/* ---     PATCHES ARE STORED LINEARLY AS I,J WHERE I=1 TO NP AND THEN */
/* ---     J = 1 TO NS */
/* ---     GENERATE TOPOLOGY TABLE FOR EACH PATCH IN SUCCESSION */
    i__1 = ns;
    for (j = 1; j <= i__1; ++j) {
	i__2 = np;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    itop = ((j - 1) * np + i__) * 6 + 10;
	    itop = (integer) ss[itop];
	    ncur = i__ + (j - 1) * np;
	    nlower = (j - 1) * np + 1;
	    nupper = j * np;
/* ---     FIRST BOUNDARY ( U= 0 TO 1= 1 WHILE V=0) */
/* Computing MAX */
	    i__3 = izero, i__4 = ncur - np;
	    ss[itop] = (doublereal) max(i__3,i__4);
	    ++itop;
/* ---     SECOND BOUNDARY ( U=0 WHILE V= 0 TO 1 ) */
	    ktemp = ncur - 1;
	    if (ktemp < nlower) {
		ktemp = 0;
	    }
	    ss[itop] = (doublereal) ktemp;
	    ++itop;
/* ---     THIRD BOUNDARY ( U=1 WHILE V= 0 TO 1) */
	    ktemp = ncur + 1;
	    if (ktemp > nupper) {
		ktemp = 0;
	    }
	    ss[itop] = (doublereal) ktemp;
	    ++itop;
/* ---     FOURTH BOUNDARY (U=0 TO 1 WHILE V=1) */
	    ktemp = ncur + np;
	    if (ktemp > ntot) {
		ktemp = 0;
	    }
	    ss[itop] = (doublereal) ktemp;
/* ---     THIS COMPLETES THE TOPOLOGY TABLE FOR THE MESH DEFINITION */
/* L40: */
	}
    }
    goto L9999;


/* ---     THE NEXT SURFACE IS PNTSON,POLYGN OR PNTVEC */
/* ---     ASSUMPTIONS:  THE PATCHES HAVE FLAGS 4,4,4,1 */
/* ---     ASSUMPTIONS:  TWO ADJACENT PATCHES HAVE CONTACT IN TWO CORNER */
/* ---     POINTS */
L200:
/* ---     RESOLVE TOPOLOGY RELATIONS ONE PATCH AT A TIME */
    i__2 = ntot;
    for (i__ = 1; i__ <= i__2; ++i__) {
	itop = (integer) ss[i__ * 6 + 10];
	iprel = (integer) (ss[i__ * 6 + 9] - 1);
/* ---     LOAD THE CORNER POINTS(USING THE MATRIX ASSUMPTION) */
	for (k = 1; k <= 3; ++k) {
	    kk = k - 1 << 4;
	    p[k - 1] = ss[iprel + kk + 1];
	    p[k + 2] = ss[iprel + kk + 2];
	    p[k + 5] = ss[iprel + kk + 5];
/* L220: */
	    p[k + 8] = ss[iprel + kk + 6];
	}
/* ---     COMPARE EACH BOUNDARY OF THE I TH PATCH TO OTHER PATCHES */
	for (j = 1; j <= 4; ++j) {
/* ---     BOUNDARY 1  POINTS P(,1) TO P(,2) */
/* ---     BOUNDARY 2  POINTS P(,1) TO P(,3) */
/* ---     BOUNDARY 3  POINTS P(,2) TO P(,4) */
/* ---     BOUNDARY 4  POINTS P(,3) TO P(,4) */
	    ja = nboun[(j << 1) - 2];
	    jb = nboun[(j << 1) - 1];
/* ---     CHECK EACH PATCH AGAINST BOUNDARY J OF PATCH I */
	    i__1 = ntot;
	    for (l = 1; l <= i__1; ++l) {
		if (l == i__) {
		    goto L240;
		}
		iprelt = (integer) (ss[l * 6 + 9] - 1);
/* ---     LOAD CORNER POINTS OF PATCH L */
		for (k = 1; k <= 3; ++k) {
		    kk = k - 1 << 4;
		    pt[k - 1] = ss[iprelt + kk + 1];
		    pt[k + 2] = ss[iprelt + kk + 2];
		    pt[k + 5] = ss[iprelt + kk + 5];
/* L250: */
		    pt[k + 8] = ss[iprelt + kk + 6];
		}
		for (m = 1; m <= 4; ++m) {
		    ma = nboun[(m << 1) - 2];
		    mb = nboun[(m << 1) - 1];
		    d__ = zero;
		    for (nn = 1; nn <= 3; ++nn) {
/* L280: */
/* Computing 2nd power */
			d__1 = p[nn + ja * 3 - 4] - pt[nn + ma * 3 - 4];
/* Computing 2nd power */
			d__2 = p[nn + jb * 3 - 4] - pt[nn + mb * 3 - 4];
			d__ = d__ + d__1 * d__1 + d__2 * d__2;
		    }
		    if (d__ > smal) {
			goto L290;
		    }
		    goto L300;
L290:
		    d__ = zero;
		    for (nn = 1; nn <= 3; ++nn) {
/* L310: */
/* Computing 2nd power */
			d__1 = p[nn + ja * 3 - 4] - pt[nn + mb * 3 - 4];
/* Computing 2nd power */
			d__2 = p[nn + jb * 3 - 4] - pt[nn + ma * 3 - 4];
			d__ = d__ + d__1 * d__1 + d__2 * d__2;
		    }
		    if (d__ > smal) {
			goto L260;
		    }
/* ---     BOUNDARY CHECK IS POSITIVE LTH PATCH LIES ACROSS J TH BOUNDARY */
/* ---     OF THE I TH PATCH */
L300:
		    itopij = i__ * 6 + 10;
		    itopij = (integer) ss[itopij];
		    ss[itopij - 1 + j] = (doublereal) l;
L260:
		    ;
		}
L240:
		;
	    }
/* L230: */
	}
/* L210: */
    }


L9999:
    return 0;
} /* topgen_ */

