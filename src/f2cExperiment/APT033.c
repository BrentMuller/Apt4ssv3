/* APT033.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__2 = 2;
static integer c__87 = 87;
static integer c__4 = 4;
static integer c__88 = 88;
static integer c__1 = 1;

/* *** SOURCE FILE : M0002799.V04   *** */

/* .....FORTRAN SUBROUTINE  ....APT033         8/68                 PH */
/* .....FORTRAN SUBROUTINE             APT033...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT033 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A RULED SURFACE */
/*              DEFINED BY EITHER OF THE APT STATEMENTS */
/*              RLDSRF/S1,P1,P2,P3 OR V1,S2,P4,P5,P6, OR V2 */
/*              RLDSRF/S1,P1,P2,P3 OR V1,P7 */
/*                IN THESE STATEMENTS S REFERS TO A SURFACE,P TO A POINT */
/*              AND V TO A VECTOR */

/* LINKAGE      CALL APT033(ARG1,ARG2,.....,ARG8,IARG9,IARG10) */

/* ARGUMENTS    THE FIRST EIGHT ARGUMENT CONTAIN RULED SURFACE PARAMETERS */
/*              THE NINTH ARG CONTAINS A 5 OR 8 TO DISTINGUISH AMOUNG */
/*              THE STATEMENT TYPES. THE LAST ARG HAS THE ADD. OF THE */
/*              RULED SURFACE CANONICAL FORM */

/* CALLS        UNPACK,APT094,ERROR,CROSS,VNORM,DOTF */


/* Subroutine */ int apt033_(doublereal *arg1, doublereal *arg2, doublereal *
	arg3, doublereal *arg4, doublereal *arg5, doublereal *arg6, 
	doublereal *arg7, doublereal *arg8, integer *iarg9, doublereal *
	iarg10)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__, k, l, n;
    static doublereal pt1[3], pt2[3];
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer mode;
    static doublereal temp[10], subs;
    static integer npts;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static integer lens1, lens2;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isize, lsize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), cross_(
	    doublereal *, doublereal *, doublereal *), vnorm_(doublereal *, 
	    doublereal *);
    static doublereal delchd[3];
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal delvec[3];
#define lcanon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    doublereal *);




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*     INITIALIZE */
    /* Parameter adjustments */
    --iarg10;
    --arg8;
    --arg7;
    --arg6;
    --arg5;
    --arg4;
    --arg3;
    --arg2;
    --arg1;

    /* Function Body */
    lens1 = 0;
    lens2 = 0;
    npts = 0;
    for (i__ = 42; i__ <= 82; ++i__) {
/* L10: */
	lcanon[i__ - 1] = 0.;
    }
    lcanon[42] = (doublereal) (*iarg9);
    lcanon[43] = 43.;
    if (*iarg9 == 5) {
	goto L20;
    }
    npts = 6;
    goto L30;
L20:
    npts = 4;
L30:
    unpack_(&arg1[1], &mode, &isize, &subs);
    lcanon[82] = (doublereal) mode;

/*     IS SI A TABCYL */

    if (mode == 11 || mode == 22) {
	goto L50;
    }
    lens1 = isize;
    i__1 = lens1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	canon[i__ + 82] = arg1[i__];
    }
    goto L60;
L50:
    lens1 = (integer) arg1[2];
    apt094_(&c__2, &arg1[1], &canon[83]);

/*     FULL INDEX TO FLAG SURFACE BEING FILLED IN CANON */

L60:
    k = lens1 + 44;
    lcanon[44] = (doublereal) k;
    lcanon[45] = (doublereal) (k + 4);
    lcanon[46] = (doublereal) (k + 8);
    lcanon[47] = (doublereal) (k + 12);
    k += 40;
    lcanon[k - 1] = 1.;
    lcanon[k + 3] = 1.;
    temp[0] = 0.f;

/*     PROCESS P1 AND P2 */

    for (i__ = 1; i__ <= 3; ++i__) {
	l = k + i__;
	canon[l - 1] = arg2[i__];
	pt1[i__ - 1] = arg2[i__];
	canon[l + 3] = arg3[i__];
	pt2[i__ - 1] = arg3[i__];
	delchd[i__ - 1] = pt2[i__ - 1] - pt1[i__ - 1];
/* L70: */
	temp[0] += delchd[i__ - 1] * delchd[i__ - 1];
    }

/*     IF P2-P1 LESS THAN .01 TAKE ERROR OUTLET */

    if (temp[0] > 1e-4f) {
	goto L80;
    }
    error_(&c__87, "APT033  ", (ftnlen)8);
    apt094_(&c__4, &iarg10[1], &canon[40]);
    goto L999;

L80:
    unpack_(&arg4[1], &mode, &isize, &subs);
    lcanon[lens1 + 91] = (doublereal) mode;

/*     IF P3 RATHER THAN V1 CONVERT TO VECTOR */

    if (mode == 20) {
	goto L100;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L90: */
	delvec[i__ - 1] = arg4[i__] - pt1[i__ - 1];
    }
    cross_(delvec, delchd, delvec);
    cross_(delchd, delvec, delvec);
    goto L120;
L100:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L110: */
	delvec[i__ - 1] = arg4[i__];
    }
L120:
    vnorm_(delchd, delchd);
    vnorm_(delvec, delvec);

/*     VECTOR AND CHORD CANNOT BE PARALLEL */

    cross_(delvec, delchd, temp);
/* Computing 2nd power */
    d__1 = temp[0];
/* Computing 2nd power */
    d__2 = temp[1];
/* Computing 2nd power */
    d__3 = temp[2];
    temp[0] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    if (temp[0] > .01f) {
	goto L130;
    }
    error_(&c__88, "APT033  ", (ftnlen)8);
    apt094_(&c__4, &iarg10[1], &canon[40]);
    return 0;
L130:
    k = lens1 + 92;
    for (i__ = 1; i__ <= 3; ++i__) {
	l = k + i__;
	canon[l - 1] = delvec[i__ - 1];
	if (*iarg9 != 5) {
	    goto L140;
	}
	canon[l + 3] = arg5[i__];
L140:
	;
    }
    if (*iarg9 != 5) {
	goto L145;
    }
    lcanon[k - 1] = 1.;
    lcanon[k + 3] = 1.f;
    goto L250;

/*     PROCESS S2 */

L145:
    unpack_(&arg5[1], &mode, &isize, &subs);
    k = lens1 + 96;
    if (mode == 11 || mode == 22) {
	goto L160;
    }
    lens2 = isize;
    i__1 = lens2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	l = k + i__;
/* L150: */
	canon[l - 1] = arg5[i__];
    }
    goto L165;
L160:
    lens2 = (integer) arg5[2];
    apt094_(&c__2, &arg5[1], &canon[k]);
L165:
    l = k + lens2 + 1;
    i__ = l - 40;
    lcanon[48] = (doublereal) i__;
    lcanon[49] = (doublereal) (i__ + 4);
    lcanon[50] = (doublereal) (i__ + 8);
    lcanon[k - 1] = (doublereal) mode;
    lcanon[l - 1] = 1.;
    lcanon[l + 3] = 1.;
    temp[0] = 0.f;
    k = l;
    for (i__ = 1; i__ <= 3; ++i__) {
	l = k + i__;
	canon[l - 1] = arg6[i__];
	pt1[i__ - 1] = arg6[i__];
	canon[l + 3] = arg7[i__];
	pt2[i__ - 1] = arg7[i__];
	delchd[i__ - 1] = pt2[i__ - 1] - pt1[i__ - 1];
/* L170: */
	temp[0] += delchd[i__ - 1] * delchd[i__ - 1];
    }
    if (temp[0] > 1e-4f) {
	goto L180;
    }
    error_(&c__87, "APT033  ", (ftnlen)8);
    apt094_(&c__4, &iarg10[1], &canon[40]);
    goto L999;
L180:
    unpack_(&arg8[1], &mode, &isize, &subs);
    n = lens1 + lens2 + 105;
    lcanon[n - 1] = (doublereal) mode;
    if (mode == 20) {
	goto L200;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L190: */
	delvec[i__ - 1] = arg8[i__] - pt1[i__ - 1];
    }
    cross_(delvec, delchd, delvec);
    cross_(delchd, delvec, delvec);
    goto L220;
L200:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L210: */
	delvec[i__ - 1] = arg8[i__];
    }
L220:
    vnorm_(delchd, delchd);
    vnorm_(delvec, delvec);
    cross_(delvec, delchd, temp);
/* Computing 2nd power */
    d__1 = temp[0];
/* Computing 2nd power */
    d__2 = temp[1];
/* Computing 2nd power */
    d__3 = temp[2];
    temp[0] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    if (temp[0] > .01f) {
	goto L230;
    }
    error_(&c__88, "APT033  ", (ftnlen)8);
    apt094_(&c__4, &iarg10[1], &canon[40]);
    goto L999;
L230:
    k = lens1 + 105 + lens2;
    for (i__ = 1; i__ <= 3; ++i__) {
	l = k + i__;
/* L240: */
	canon[l - 1] = delvec[i__ - 1];
    }
    if (*iarg9 == 5) {
	goto L250;
    }
    n = 2;
    goto L260;
L250:
    n = 1;
L260:
    lsize = lens1 + lens2 + n + (npts << 2) + 42;
    lcanon[41] = (doublereal) lsize;
    iarg10[2] = (doublereal) lsize;
    apt094_(&c__1, &iarg10[1], &canon[40]);
L999:
    return 0;
} /* apt033_ */

#undef lcanon
#undef bcanon
#undef sscan
#undef canon
#undef can


