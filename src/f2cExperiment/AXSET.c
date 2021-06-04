/* AXSET.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal alpha, beta, cosa, cosb, sina, sinb;
    integer itac;
} tac_;

#define tac_1 tac_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001038.X02   *** */

/* Subroutine */ int axset_(integer *mode, doublereal *fax, doublereal *vax, 
	doublereal *ax)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal smal = 1e-38;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int bad_();
    static doublereal fac, siz, faxn[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

/* --PURPOSE IS TO SET AXIS AX TO FAX IF MODE IS 0 OR VAX IF */
/* --MODE IS NOT ZERO.  IF VAX IS ZERO, AX WILL BE SET TO FAX */
/* .... IF MODE=2 THEN VAX WILL BE VARIED BY APPLYING ANGLE ALPHA */
/*                    IN DIRECTION INDICATED BY FAX */


/*     ALPHA  TOOL AXIS SLEW ANGLE WRT SN */
/*            IN GUIDE SURFACE CRSSPL DIRN. IF PATH IN TANSPL DIRN. */
/*            AND VICE VERSA */
/*     BETA   TOOL AXIS TILT ANGLE (CUTANG) WRT SN */
/*            IN PATH DIRECTION */
/*     COSA   COS(ALPHA) */
/*     COSB   COS(BETA) */
/*     SINA   SIN(ALPHA) */
/*     SINB   SIN(BETA) */
/*     ITAC   FLAG INDICATING THAT ATANGL TYPE TOOL AXIS CONTROL */
/*            IS REQUIRED =1, =0 FOR FIXED OR NORMDS */

    /* Parameter adjustments */
    --ax;
    --vax;
    --fax;

    /* Function Body */

    if (*mode != 0) {
	goto L50;
    }
/* --FIXED AXIS CASE */
L10:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	ax[i__] = fax[i__];
    }
    ax[4] = one;
    goto L100;

L50:
/* ---VARIABLE AXIS CASE */
    dotf_(&siz, &vax[1], &vax[1]);
    if (siz < smal) {
	goto L10;
    }
    fac = one / sqrt(siz);
/* --ADJUST SIGN OF AXIS ACCORDING TO SIGN OF MODE */
    if (*mode < 0) {
	fac = -fac;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L60: */
	ax[i__] = vax[i__] * fac;
    }
/* ...NOW APPLY ALPHA IF REQUIRED */
    if (abs(*mode) == 2) {
/* ... NORMALIZE FAX */
	vnorm_(&fax[1], faxn);
	for (i__ = 1; i__ <= 3; ++i__) {
	    ax[i__] = tac_1.cosa * ax[i__] + tac_1.sina * faxn[i__ - 1];
/* L70: */
	}
    }

L100:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER AXSET", (ftnlen)20, (ftnlen)12);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__0, "MODE", mode, (ftnlen)4);
    bad_(&c_n3, &c__1, "AX  ", &ax[1], (ftnlen)4);
L1999:
    return 0;
} /* axset_ */

