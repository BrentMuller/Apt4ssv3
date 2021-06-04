/* ANGLFB.f -- translated by f2c (version 20100827).
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

static integer c__0 = 0;
static integer c__80 = 80;


/* .....FORTRAN SUBROUTINE              ANGLF/ANBLB          18.10.78 EC */

/*              FORTRAN SUBROUTINE ANGLF */
/* PURPOSE      TO COMPUTE THE ANGLE BETWEEN THE POSITIVE X-AXIS AND A */
/*              VECTOR FROM THE CENTER OF A CIRCLE TO A GIVEN POINT */

/* LINKAGE      CALL ANGLF(RES,ARG1,ARG2) */

/* ARGUMENTS    RES     ARRAY TO CONTAIN RESULT */
/*              ARG1    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT */
/*              ARG2    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          UNPACK */
/*              REAL FUNCTION       DATAN2 */
/*              REAL FUNCTION       DARCOS */
/*              REAL FUNCTION       DSQRT */
/*              REAL FUNCTION       DABS */
/*              REAL FUNCTION       DMIN1 */
/*              REAL FUNCTION       DMAX1 */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          TRANSF */

/* Subroutine */ int anglf_(doublereal *res, doublereal *arg1, doublereal *
	arg2)
{
    /* Initialized data */

    static integer ir[20] = { 4,4,5,5,2,1,1,1,5,1,0,0,0,1,0,0,0,0,2,3 };
    static integer iw[20] = { 1,1,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,2,1 };
    static doublereal fact = .0174532925;

    /* Builtin functions */
    double sqrt(doublereal), atan2(doublereal, doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__;
    static doublereal a1[12], a2[12], b1, b2, b3, sr[2];
    static integer iww, mode1, mode2, isub1, isub2;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer isize1, isize2;
    extern doublereal darcos_(doublereal *);
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), transf_(doublereal *, doublereal *, integer *, 
	    integer *, integer *);

/* SCHALTANGABE FUER TRANSFORMATIONSROUTINE TRANSF */
    /* Parameter adjustments */
    --arg2;
    --arg1;
    --res;

    /* Function Body */
/* SCHALTZIFFERN FUER ANGLF-AUFGABENERKENNUNG */


/* L1: */
    if (ckdef_(&arg1[1]) || ckdef_(&arg2[1])) {
	goto L30;
    }
    unpack_(&arg1[1], &mode1, &isize1, &isub1);
    if (mode1 <= 0 || mode1 > 20 || ir[mode1 - 1] == 0) {
	goto L30;
    }
    unpack_(&arg2[1], &mode2, &isize2, &isub2);
    if (mode2 <= 0 || mode2 > 20 || ir[mode2 - 1] == 0) {
	goto L30;
    }
    iww = iw[mode1 - 1] * iw[mode2 - 1];
    switch (iww) {
	case 1:  goto L10;
	case 2:  goto L9;
	case 3:  goto L9;
	case 4:  goto L20;
    }
L9:
    goto L30;
/*   WINKEL ZWISCHEN VEKTOREN (AUCH EBENEN-NORMALEN) */
L10:
    b1 = 0.;
    b2 = 0.;
    b3 = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	b1 = arg1[i__] * arg1[i__] + b1;
	b2 = arg2[i__] * arg2[i__] + b2;
/* L11: */
	b3 = arg1[i__] * arg2[i__] + b3;
    }
    if (b1 < 1e-12 || b2 < 1e-12) {
	goto L30;
    }
    res[1] = b3 / sqrt(b1) / sqrt(b2);
    res[1] = max(-1.,res[1]);
    res[1] = min(1.,res[1]);
    res[1] = darcos_(&res[1]);
    goto L25;
/*    2-D-VERARBEITUNG,WINKEL ZUR POSITIVEN X-ACHSE */
L20:
    transf_(a1, &arg1[1], &ir[mode1 - 1], &isize1, &c__0);
    transf_(a2, &arg2[1], &ir[mode2 - 1], &isize2, &c__0);
    sr[0] = a2[0] - a1[0];
    sr[1] = a2[1] - a1[1];
    if (abs(sr[0]) + abs(sr[1]) < d__ - 12) {
	goto L30;
    }
    res[1] = atan2(sr[1], sr[0]);
    if (res[1] < 0.) {
	res[1] += 6.283185306;
    }
L25:
    res[1] /= fact;
    return 0;
/*  'MINDESTENS EINE EINGABE IST UNDEFINIERT ODER ERGEBNIS NICHT */
/*                                                   BERECHENBAR' */
L30:
    error_(&c__80, "ANGLF   ", (ftnlen)8);
    res[1] = 0.;
    return 0;
} /* anglf_ */


/*              FORTRAN SUBROUTINE ANGLB */
/* PURPOSE      TO COMPUTE THE ANGLE BETWEEN THE POSITIVE X-AXIS AND A */
/*              VECTOR FROM THE CENTER OF A CIRCLE TO A GIVEN POINT */

/* LINKAGE      CALL ANGLB(RES,ARG1,ARG2) */

/* ARGUMENTS    RES     ARRAY TO CONTAIN RESULT */
/*              ARG1    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT */
/*              ARG2    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          UNPACK */
/*              REAL FUNCTION       DATAN2 */
/*              REAL FUNCTION       DARCOS */
/*              REAL FUNCTION       DSQRT */
/*              REAL FUNCTION       DABS */
/*              REAL FUNCTION       DMIN1 */
/*              REAL FUNCTION       DMAX1 */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          TRANSF */

/* Subroutine */ int anglb_(doublereal *res, doublereal *arg1, doublereal *
	arg2)
{
    /* Initialized data */

    static integer ir[20] = { 4,4,5,5,2,1,1,1,5,1,0,0,0,1,0,0,0,0,2,3 };
    static integer iw[20] = { 1,1,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,2,1 };

    /* Builtin functions */
    double sqrt(doublereal), atan2(doublereal, doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__;
    static doublereal a1[12], a2[12], b1, b2, b3, sr[2];
    static integer iww, mode1, mode2, isub1, isub2;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer isize1, isize2;
    extern doublereal darcos_(doublereal *);
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), transf_(doublereal *, doublereal *, integer *, 
	    integer *, integer *);

/* SCHALTANGABE FUER TRANSFORMATIONSROUTINE TRANSF */
    /* Parameter adjustments */
    --arg2;
    --arg1;
    --res;

    /* Function Body */
/* SCHALTZIFFERN FUER ANGLB-AUFGABENERKENNUNG */


/* L1: */
    if (ckdef_(&arg1[1]) || ckdef_(&arg2[1])) {
	goto L30;
    }
    unpack_(&arg1[1], &mode1, &isize1, &isub1);
    if (mode1 <= 0 || mode1 > 20 || ir[mode1 - 1] == 0) {
	goto L30;
    }
    unpack_(&arg2[1], &mode2, &isize2, &isub2);
    if (mode2 <= 0 || mode2 > 20 || ir[mode2 - 1] == 0) {
	goto L30;
    }
    iww = iw[mode1 - 1] * iw[mode2 - 1];
    switch (iww) {
	case 1:  goto L10;
	case 2:  goto L9;
	case 3:  goto L9;
	case 4:  goto L20;
    }
L9:
    goto L30;
/*   WINKEL ZWISCHEN VEKTOREN (AUCH EBENEN-NORMALEN) */
L10:
    b1 = 0.;
    b2 = 0.;
    b3 = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	b1 = arg1[i__] * arg1[i__] + b1;
	b2 = arg2[i__] * arg2[i__] + b2;
/* L11: */
	b3 = arg1[i__] * arg2[i__] + b3;
    }
    if (b1 < 1e-12 || b2 < 1e-12) {
	goto L30;
    }
    res[1] = b3 / sqrt(b1) / sqrt(b2);
    res[1] = max(-1.,res[1]);
    res[1] = min(1.,res[1]);
    res[1] = darcos_(&res[1]);
    goto L25;
/*    2-D-VERARBEITUNG,WINKEL ZUR POSITIVEN X-ACHSE */
L20:
    transf_(a1, &arg1[1], &ir[mode1 - 1], &isize1, &c__0);
    transf_(a2, &arg2[1], &ir[mode2 - 1], &isize2, &c__0);
    sr[0] = a2[0] - a1[0];
    sr[1] = a2[1] - a1[1];
    if (abs(sr[0]) + abs(sr[1]) < d__ - 12) {
	goto L30;
    }
    res[1] = atan2(sr[1], sr[0]);
    if (res[1] < 0.) {
	res[1] += 6.283185306;
    }
L25:
    return 0;
/*  'MINDESTENS EINE EINGABE IST UNDEFINIERT ODER ERGEBNIS NICHT */
/*                                                   BERECHENBAR' */
L30:
    error_(&c__80, "ANGLB   ", (ftnlen)8);
    res[1] = 0.;
    return 0;
} /* anglb_ */

