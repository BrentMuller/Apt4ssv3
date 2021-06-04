/* MIDKUR.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c_n1 = -1;
static integer c__1 = 1;

/* *** SOURCE FILE : MIDKUR.V01   *** */

/* Subroutine */ int midkur_(doublereal *r__, doublereal *p0, doublereal *p1, 
	doublereal *side, doublereal *sk)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal ch[3], sx[24];
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
    static doublereal vec[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal xcos, xsin;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen), kursrf_(doublereal *,
	     doublereal *, doublereal *);





/* .... COMPUTE PRINCIPLE CURVATURES ETC. AT MIDPOINT, R */


/* .... DEBUG FLAGS */


    /* Parameter adjustments */
    --p1;
    --p0;
    --r__;

    /* Function Body */
    kursrf_(&r__[1], side, sx);

/* .... COMPUTE CHORD DIRECTION */

    for (i__ = 1; i__ <= 3; ++i__) {
	ch[i__ - 1] = p1[i__] - p0[i__];
/* L10: */
    }
    vnorm_(ch, ch);

/* .... PROJECT CHORD VECTOR INTO SURFACE TANGENT PLANE */

    cross_(&r__[29], ch, vec);
    for (i__ = 1; i__ <= 3; ++i__) {
	vec[i__ - 1] = *side * vec[i__ - 1];
/* L20: */
    }

    cross_(vec, &r__[29], vec);
    vnorm_(vec, vec);

/* .... COMPUTE CURVATURE OF SURFACE IN DIRECTION OF CHORD */

    dotf_(&xcos, vec, &sx[4]);
    dotf_(&xsin, vec, &sx[8]);
    *sk = sx[0] * xcos * xcos + sx[1] * xsin * xsin;

    if (ibugg_1.ibug == 11) {
	s_copy(badmsg, " AFTER MIDKUR", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c_n1, &c__1, "SK  ", sk, (ftnlen)4);
    }

    return 0;
} /* midkur_ */

