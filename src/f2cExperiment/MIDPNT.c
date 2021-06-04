/* MIDPNT.f -- translated by f2c (version 20100827).
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

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c_n3 = -3;

/* *** SOURCE FILE : MIDPNT.V01   *** */

/* Subroutine */ int midpnt_(doublereal *surf, integer *npat, doublereal *up, 
	doublereal *vp, integer *npatl, doublereal *upl, doublereal *vpl, 
	doublereal *rm)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal b[64], u, v, u1, v1, u2, v2, um, vm;
    extern /* Subroutine */ int bad_();
    static integer itop[24]	/* was [6][4] */, iflag[6], npatm;
    static char badmsg[20];
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), mescon_(doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *), cprint_(char *, ftnlen), cnsurf_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);





/* .... COMPUTE GLOBAL PARAMETERS FOR CURRENT AND PREVIOUS POINTS */


/* .... DEBUG FLAGS */


    /* Parameter adjustments */
    --rm;
    --surf;

    /* Function Body */
    mescon_(&surf[1], &u1, &v1, npat, up, vp, &c__2);
    mescon_(&surf[1], &u2, &v2, npatl, upl, vpl, &c__2);

/* .... COMPUTE GLOBAL PARAMETERS OF MIDPOINT */

    u = (u1 + u2) / 2.f;
    v = (v1 + v2) / 2.f;

/* .... COMPUTE PATCH NUMBER AND LOCAL PARAMETERS FOR MIDPOINT */

    mescon_(&surf[1], &u, &v, &npatm, &um, &vm, &c__1);

/* .... LOAD PATCH COEFFICIENTS */

    lodpch_(&surf[1], b, iflag, itop, &npatm, &c__0);

/* .... EVALUATE COORDINATES OF MIDPOINT */

    cnsurf_(&um, &vm, b, &rm[1], iflag, &c__1);

    if (ibugg_1.ibug == 11) {
	s_copy(badmsg, " AFTER MIDPNT", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c__1, &c__0, "NPAT", npat, (ftnlen)4);
	bad_(&c__1, &c__1, "UP  ", up, (ftnlen)4);
	bad_(&c_n1, &c__1, "VP  ", vp, (ftnlen)4);
	bad_(&c__1, &c__0, "NPTL", npatl, (ftnlen)4);
	bad_(&c__1, &c__1, "UPL ", upl, (ftnlen)4);
	bad_(&c_n1, &c__1, "VPL ", vpl, (ftnlen)4);
	bad_(&c__1, &c__0, "NPTM", &npatm, (ftnlen)4);
	bad_(&c__1, &c__1, "UM  ", &um, (ftnlen)4);
	bad_(&c_n1, &c__1, "VM  ", &vm, (ftnlen)4);
	bad_(&c_n3, &c__1, "RM  ", &rm[1], (ftnlen)4);
    }

    return 0;
} /* midpnt_ */

