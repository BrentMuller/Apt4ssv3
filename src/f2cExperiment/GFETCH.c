/* GFETCH.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n4 = -4;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001072.W01   *** */

/* Subroutine */ int gfetch_(integer *nbig, integer *maxlda, doublereal *com, 
	doublereal *dgeom, doublereal *pgeom, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal dumrec[3] = { 0.,0.,0. };

    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, n;
#define aa (equiv_0)
#define jj ((integer *)equiv_0)
    extern /* Subroutine */ int bad_();
    static integer nhi, nlo, iloc;
    extern /* Subroutine */ int apt094_();
    extern logical ckdef_(doublereal *);
    static integer jmode;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

    /* Parameter adjustments */
    --pgeom;
    --dgeom;
    --com;

    /* Function Body */
/* --PURPOSE IS TO LOAD PART AND DRIVE GEOMETRY BOTH INTO THE */
/* --ARRAY COM.  THE ADDRESS OF EACH IS THEN PLACED IN THE 4TH */
/* --LOCATIONS OF DGEOM AND PGEOM RESPECTIVELY */

    nlo = 41;
    nhi = nlo + *nbig - 1;
    iloc = nhi + 1;
    i__1 = nhi;
    for (i__ = nlo; i__ <= i__1; ++i__) {
/* L10: */
	com[i__] = zero;
    }
    *irr = 1;
    n = (integer) (pgeom[2] + dgeom[2]);
    if (pgeom[1] == dgeom[1]) {
	n = (integer) pgeom[2];
    }
    n += *nbig;
    if (n > *maxlda) {
	goto L998;
    }
/* ---      WRITE A NULL RECORD TO LET APT094 KNOW THAT BLANK COMMON */
/* ---      HAS BEEN ALTERED */
    dumrec[1] = 0.f;
    dumrec[2] = (doublereal) (*nbig);
    jmode = 1;
    apt094_(&jmode, &dumrec[1], &com[41]);
    *irr = 4;
    if (ckdef_(dumrec)) {
	goto L998;
    }
/* --LOAD PART GEOMETRY FIRST */
    jmode = 3;
    apt094_(&jmode, &pgeom[1], jj);
    *irr = 2;
    if (ckdef_(&pgeom[1])) {
	goto L998;
    }
    pgeom[4] = (doublereal) (*jj);
/* --CHECK WHETHER PART AND DRIVE GEOMETRY ARE THE SAME */
    if (dgeom[1] != pgeom[1]) {
	goto L110;
    }
    dgeom[4] = pgeom[4];
    goto L200;
/* --LOAD DRIVE GEOMETRY INTO CORE */
L110:
    jmode = 3;
    apt094_(&jmode, &dgeom[1], jj);
    *irr = 3;
    if (ckdef_(&dgeom[1])) {
	goto L998;
    }
    dgeom[4] = (doublereal) (*jj);
L200:
    *irr = 0;

L998:
    if (ibugg_1.ibug != 11) {
	goto L999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER  GFETCH", (ftnlen)20, (ftnlen)14);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__0, "IRR ", irr, (ftnlen)4);
    bad_(&c__1, &c__0, "JMOD", &jmode, (ftnlen)4);
    bad_(&c_n1, &c__0, "ILOC", &iloc, (ftnlen)4);
    bad_(&c_n4, &c__1, "PGEM", &pgeom[1], (ftnlen)4);
    bad_(&c_n4, &c__1, "DGEM", &dgeom[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "DREC", dumrec, (ftnlen)4);

L999:
    return 0;
} /* gfetch_ */

#undef jj
#undef aa


