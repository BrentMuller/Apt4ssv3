/* LODINT.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__3 = 3;

/* *** SOURCE FILE : M0000640.W01   *** */



/* Subroutine */ int lodint_(doublereal *ss, doublereal *b, doublereal *ust, 
	doublereal *vst, doublereal *tp, doublereal *tn, integer *iflag, 
	integer *itop, integer *ipnum, integer *mode)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal d__;
    static integer i__, j;
    static doublereal dt, ut, vt, half;
    static integer npchs, istep, jstep;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), puvloc_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);

/* --------PROGRAM PERFORMS GLOBAL SEARCH OF PATCH STRUCTURE */
/* --------AND LOADS AN INITIAL PATCH BASED ON DISTANCE */
/* --------AS RETURNED BY PUVLOC */
    /* Parameter adjustments */
    itop -= 7;
    --iflag;
    --tn;
    --tp;
    --b;
    --ss;

    /* Function Body */
    half = .5;
    d__ = 1e10;
    *ipnum = 1;
    npchs = (integer) ss[4];
    if (npchs != 1) {
	i__1 = npchs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], &i__, &c__1);
/* .... TAKE 'CENTRE POINT' OF PATCH FOR START OF SEARCH */
	    ut = half;
	    vt = half;
	    puvloc_(&b[1], &tp[1], &tn[1], &ut, &vt, &dt, mode, &iflag[1]);
	    if (dt > d__) {
		goto L20;
	    }
	    *ipnum = i__;
	    *ust = ut;
	    *vst = vt;
	    d__ = dt;
L20:
	    ;
	}
    } else {
/* .... SPECIAL TREATMENT FOR SINGLE PATCH SURFACES */
/* .... CONSIDER 9 START POINTS */
	lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], &c__1, &c__1);
	istep = 2;
	jstep = 2;
	i__1 = istep + 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = jstep + 1;
	    for (j = 1; j <= i__2; ++j) {
		ut = (doublereal) (i__ - 1);
		ut /= (doublereal) istep;
		vt = (doublereal) (j - 1);
		vt /= (doublereal) jstep;
		puvloc_(&b[1], &tp[1], &tn[1], &ut, &vt, &dt, mode, &iflag[1])
			;
		if (dt < d__) {
		    *ipnum = 1;
		    *ust = ut;
		    *vst = vt;
		    d__ = dt;
		}
/* L200: */
	    }
/* L210: */
	}
    }
    lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], ipnum, &c__3);
    return 0;
} /* lodint_ */

