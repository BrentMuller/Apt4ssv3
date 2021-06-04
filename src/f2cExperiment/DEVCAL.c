/* DEVCAL.f -- translated by f2c (version 20100827).
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

static doublereal c_b4 = 1.;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;
static integer c_n1 = -1;

/* *** SOURCE FILE : DEVCAL.V01   *** */

/* Subroutine */ int devcal_(doublereal *q, doublereal *tn, doublereal *p0, 
	doublereal *p1, doublereal *dev)
{
    /* Initialized data */

    static doublereal z1em10 = 1e-10;
    static doublereal z1em20 = 1e-20;
    static doublereal zero = 0.;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a, b, h__[3];
    static integer i__;
    static doublereal s, u, v[3], h2, vq[3];
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen), dotf_(doublereal *, doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);






/* .... DEBUG FLAGS */


    /* Parameter adjustments */
    --p1;
    --p0;
    --tn;
    --q;

    /* Function Body */

/* .... COMPUTE (P1-P0) AND (Q-P0) */

    for (i__ = 1; i__ <= 3; ++i__) {
	v[i__ - 1] = p1[i__] - p0[i__];
	vq[i__ - 1] = q[i__] - p0[i__];
/* L10: */
    }

/* .... COMPUTE LOCAL U WHERE MAX DEVIATION OCCURS */

    dotf_(&a, v, vq);
    dotf_(&b, v, v);
    if (b > z1em10) {
	u = a / b;
    } else {
	u = .5f;
    }

/* .... COMPUTE DEVIATION */

    for (i__ = 1; i__ <= 3; ++i__) {
	h__[i__ - 1] = q[i__] - p0[i__] - u * v[i__ - 1];
/* L20: */
    }

    dotf_(&h2, h__, h__);

/* .... ADD SIGN TO INDICATE WHETHER TOWARDS OR AWAY FROM TOOL */
/*     POSITIVE TOWARDS TOOL, NEGATIVE AWAY FROM TOOL */

    dotf_(&s, h__, &tn[1]);
    s = d_sign(&c_b4, &s);

    if (h2 > z1em20) {
	*dev = s * sqrt(h2);
    } else {
	*dev = zero;
    }

    if (ibugg_1.ibug == 11) {
	s_copy(badmsg, " AFTER DEVCAL", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c__3, &c__1, "P0  ", &p0[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "P1  ", &p1[1], (ftnlen)4);
	bad_(&c__3, &c__1, "Q   ", &q[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "TN  ", &tn[1], (ftnlen)4);
	bad_(&c__3, &c__1, "H   ", h__, (ftnlen)4);
	bad_(&c__1, &c__1, "S   ", &s, (ftnlen)4);
	bad_(&c_n1, &c__1, "DEV ", dev, (ftnlen)4);
    }

    return 0;
} /* devcal_ */

