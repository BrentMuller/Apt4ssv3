/* AVMSG.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__36 = 36;
static integer c__5 = 5;
static integer c__11 = 11;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__3 = 3;
static integer c__14 = 14;
static integer c__10 = 10;
static integer c__4 = 4;
static integer c__12 = 12;

/* *** SOURCE FILE : AVMSG.ORG   *** */

/* Subroutine */ int avmsg_(doublereal *te, doublereal *ta, logical *lanps, 
	doublereal *b, char *type__, doublereal *d__, ftnlen type_len)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static char msg[120];
    static real bdeg;
    static integer ipos;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(), cprint_(char *, ftnlen);


/*     PURPOSE: PRINT MESSAGE WHEN INTERFERENCE SUCCESSFULLY AVOIDED */

/*     ARGUMENTS: */

/*     TE    - TOOL END COORDINATES */
/*     TA    - TOOL AXIS VECTOR */
/*     LANPS - LIFT OFF DIRECTION VECTOR */
/*     B     - TILT ANGLE (IF ANY) */
/*     TYPE  - TYPE OF TILT (ROLL OR PITCH) */
/*     D     - LIFT OFF DISTANCE */


/*     GLOBAL VARIABLES: */


/*     LOCAL VARIABLES: */

/*       MSG   - PRINT BUFFER */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




    /* Parameter adjustments */
    --ta;
    --te;

    /* Function Body */
    s_copy(msg, " ", (ftnlen)120, (ftnlen)1);
    cform_("INTERFERENCE SUCCESSFULLY AVOIDED BY", msg, &c__2, &c__36, (
	    ftnlen)36, (ftnlen)120);
    ipos = 39;
    if ((d__1 = *b - znumbr_1.z0, abs(d__1)) > znumbr_1.z1em6) {
	cform_(type__, msg, &ipos, &c__5, (ftnlen)5, (ftnlen)120);
	ipos += 4;
	if (s_cmp(type__, "PITCH", (ftnlen)5, (ftnlen)5) == 0) {
	    ++ipos;
	}
	cform_("ING THROUGH", msg, &ipos, &c__11, (ftnlen)11, (ftnlen)120);
	ipos += 12;
	bdeg = *b / znumbr_1.degrad;
	fconv_(&bdeg, msg, &ipos, &c__6, &c__2, (ftnlen)120);
	ipos += 7;
	cform_("DEGREES", msg, &ipos, &c__7, (ftnlen)7, (ftnlen)120);
	ipos += 8;
	if ((d__1 = *d__ - znumbr_1.z0, abs(d__1)) > znumbr_1.z1em6) {
	    cform_("AND", msg, &ipos, &c__3, (ftnlen)3, (ftnlen)120);
	    ipos += 4;
	}
    }
    if ((d__1 = *d__ - znumbr_1.z0, abs(d__1)) > znumbr_1.z1em6) {
	cform_("LIFTING OFF BY", msg, &ipos, &c__14, (ftnlen)14, (ftnlen)120);
	ipos += 15;
	fconv_(d__, msg, &ipos, &c__10, &c__4, (ftnlen)120);
	ipos += 11;

	if (*lanps) {
	    cform_("NORMAL TO PS", msg, &ipos, &c__12, (ftnlen)12, (ftnlen)
		    120);
	} else {
	    cform_("PARALLEL TO TA", msg, &ipos, &c__14, (ftnlen)14, (ftnlen)
		    120);
	}

    }

    cprint_(msg, (ftnlen)120);

    return 0;
} /* avmsg_ */

