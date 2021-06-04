/* DISTF.f -- translated by f2c (version 20100827).
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

static integer c__55 = 55;
static integer c__61 = 61;
static integer c__62 = 62;

/* *** SOURCE FILE : M0002884.V03   *** */

/* .....FORTRAN SUBROUTINE              DISTF                16.10.78 EC */

/*              FORTRAN SUBROUTINE DISTF */
/* PURPOSE      DISTANCE-COMPUTATION: */
/*               MOD=1 PLANE/PLANE */
/*               MOD=2 POINT/PLANE */
/*               MOD=2 POINT/POINT */

/* CALL         CALL DISTF(RES,ARG1,ARG2) */

/* ARGUMENTS    RES     ARRAY FOR THE RESULT */
/*              ARG1    ARRAY OF FIRST ELEMENT */
/*              ARG2    ARRAY OF SECOND ELEMENT */

/* SUBPROGRAM   TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNPACK */
/*              DOUBLE PRECISION FUNCTION     DABS */
/*              SUBROUTINE          UNDEF */
/* Subroutine */ int distf_(doublereal *res, doublereal *arg1, doublereal *
	arg2)
{
    /* Initialized data */

    static integer ient[20] = { 1,1,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0 };

    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal ab;
    static integer mod, mode, isub;
    static doublereal cosw;
    static integer iarg1, iarg2;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int undef_(doublereal *);
    static integer isize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), unpack_(
	    doublereal *, integer *, integer *, integer *);

    /* Parameter adjustments */
    --arg2;
    --arg1;
    --res;

    /* Function Body */
    if (ckdef_(&arg1[1]) || ckdef_(&arg2[1])) {
	goto L50;
    }
    unpack_(&arg1[1], &mode, &isize, &isub);
    if (mode < 1 || mode > 20) {
	goto L51;
    }
    iarg1 = ient[mode - 1];
    if (iarg1 == 0) {
	goto L51;
    }
    unpack_(&arg2[1], &mode, &isize, &isub);
    if (mode < 1 || mode > 20) {
	goto L51;
    }
    iarg2 = ient[mode - 1];
    if (iarg2 == 0) {
	goto L51;
    }
    mod = iarg1 + iarg2 - 1;
    switch (mod) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
    }
/*    DISTANCE OF TWO PLANES */
L10:
    cosw = arg1[1] * arg2[1] + arg1[2] * arg2[2] + arg1[3] * arg2[3];
    if ((d__1 = abs(cosw) - 1., abs(d__1)) > 1e-6) {
	goto L52;
    }
    res[1] = (d__1 = arg1[4] - cosw * arg2[4], abs(d__1));
    return 0;
/*    DISTANCE OF POINT AND PLANE */
L20:
    ab = arg1[4];
    if (iarg1 == 2) {
	ab = arg2[4];
    }
    res[1] = arg1[1] * arg2[1] + arg1[2] * arg2[2] + arg1[3] * arg2[3] - ab;
    return 0;
/*     DISTANCE OF TWO POINTS */
L30:
/* Computing 2nd power */
    d__1 = arg1[1] - arg2[1];
/* Computing 2nd power */
    d__2 = arg1[2] - arg2[2];
/* Computing 2nd power */
    d__3 = arg1[3] - arg2[3];
    res[1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    return 0;
/*     'ONE ELEMENT OR BOTH ARE UNDEFINED' */
L50:
    error_(&c__55, "DISTF   ", (ftnlen)8);
    goto L53;
/*     'WRONG INPUT' */
L51:
    error_(&c__61, "DISTF   ", (ftnlen)8);
    goto L53;
/*     'PLANES NOT PARALLEL' */
L52:
    error_(&c__62, "DISTF   ", (ftnlen)8);
L53:
    undef_(&res[1]);
    return 0;
} /* distf_ */

