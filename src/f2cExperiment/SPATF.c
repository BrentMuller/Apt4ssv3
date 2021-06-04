/* SPATF.f -- translated by f2c (version 20100827).
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

static integer c__54 = 54;

/* *** SOURCE FILE : M0002891.V03   *** */

/* .....FORTRAN SUBROUTINE              SPATF                16.10.78 EC */

/*              FORTRAN SUBROUTINE SPATF */
/* PURPOSE      COMPUTATION OF THE SPAT-PRODUCT OF 3 VECTORS */

/* CALLING SEQ.: CALL SPATF(RES,ARG1,ARG2,ARG3) */

/* ARGUMENTS    RES     FIELD FOR RESULT */
/*              ARG1    FIELD OF 1ST VECTOR */
/*              ARG2    FIELD OF 2ND VECTOR */
/*              ARG3    FIELD OF 3RD VECTOR */

/* SUBPROGRAMS  TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNPACK */
/*              SUBROUTINE          UNDEF */
/* Subroutine */ int spatf_(doublereal *res, doublereal *arg1, doublereal *
	arg2, doublereal *arg3)
{
    /* Initialized data */

    static integer is[20] = { 1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1 };

    static integer isi, isu, mode;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int undef_(doublereal *), error_(integer *, char *
	    , ftnlen), unpack_(doublereal *, integer *, integer *, integer *);

    /* Parameter adjustments */
    --arg3;
    --arg2;
    --arg1;
    --res;

    /* Function Body */
    if (ckdef_(&arg1[1]) || ckdef_(&arg2[1]) || ckdef_(&arg3[1])) {
	goto L30;
    }
    unpack_(&arg1[1], &mode, &isi, &isu);
    if (mode < 1 || mode > 20 || is[mode - 1] != 1) {
	goto L30;
    }
    unpack_(&arg2[1], &mode, &isi, &isu);
    if (mode < 1 || mode > 20 || is[mode - 1] != 1) {
	goto L30;
    }
    unpack_(&arg3[1], &mode, &isi, &isu);
    if (mode < 1 || mode > 20 || is[mode - 1] != 1) {
	goto L30;
    }
    res[1] = arg1[1] * (arg2[2] * arg3[3] - arg2[3] * arg3[2]) + arg1[2] * (
	    arg2[3] * arg3[1] - arg2[1] * arg3[3]) + arg1[3] * (arg2[1] * 
	    arg3[2] - arg2[2] * arg3[1]);
    return 0;
/*     'AT LEAST ONE OF THE VECTORS UNDEFINED OR WRONG INPUT' */
L30:
    error_(&c__54, "SPATF   ", (ftnlen)8);
    undef_(&res[1]);
    return 0;
} /* spatf_ */

