/* MESCON.f -- translated by f2c (version 20100827).
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
static integer c__0 = 0;
static integer c__1 = 1;

/* *** SOURCE FILE : M0001079.W01   *** */

/* Subroutine */ int mescon_(doublereal *surf, doublereal *u, doublereal *v, 
	integer *npat, doublereal *u1, doublereal *v1, integer *mode)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal two = 2.;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer iu, iv;
    extern /* Subroutine */ int bad_();
    static doublereal base, acrs, aspl;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer numcrs, numspl;

/* --PURPOSE IS TO CONVERT GLOBAL MESH COORDINATES U,V */
/* --INTO LOCAL PATCH NUMBER(NPAT) AND LOCAL PATCH COORDINATES */
/* --U1,V1 IF MODE IS 1.  OTHERWISE THE REVERSE IF MODE IS 2 */
    /* Parameter adjustments */
    --surf;

    /* Function Body */

    numspl = (integer) surf[9];
    numcrs = (integer) surf[10];
    acrs = surf[10] - two;
    aspl = surf[9] - two;

    if (*mode > 1) {
	goto L100;
    }
/* --CONVERT GLOBAL U,V TO LOCAL PATCH NUMBER NPAT AND LOCAL U1,V1 */
    iu = 1;
    if (*u < one) {
	goto L10;
    }
    iu = numcrs - 1;
    if (*u >= acrs) {
	goto L10;
    }
    iu = (integer) (*u) + 1;
L10:
    base = (doublereal) (iu - 1);
    *u1 = *u - base;

    iv = 1;
    if (*v < one) {
	goto L20;
    }
    iv = numspl - 1;
    if (*v >= aspl) {
	goto L20;
    }
    iv = (integer) (*v) + 1;
L20:
    base = (doublereal) (iv - 1);
    *v1 = *v - base;

    *npat = iu + (iv - 1) * (numcrs - 1);
    goto L999;

L100:
/* --CONVERT NPAT,U1,V1 TO GLOBAL U,V */
    iu = (*npat - 1) % (numcrs - 1) + 1;
    iv = (*npat - 1) / (numcrs - 1) + 1;
    *u = *u1 + iu - 1;
    *v = *v1 + iv - 1;

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER MESCON", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "U   ", u, (ftnlen)4);
    bad_(&c__1, &c__1, "V   ", v, (ftnlen)4);
    bad_(&c__1, &c__0, "NPAT", npat, (ftnlen)4);
    bad_(&c__1, &c__1, "U1  ", u1, (ftnlen)4);
    bad_(&c_n1, &c__1, "V1  ", v1, (ftnlen)4);
    bad_(&c_n1, &c__0, "MODE", mode, (ftnlen)4);
L1999:
    return 0;
} /* mescon_ */

