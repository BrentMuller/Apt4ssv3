/* NPAT.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;

/* *** SOURCE FILE : M0000938.V06   *** */


/* ...  FORTRAN SUBROUTINE               NPAT      3/69      SR */

/* PURPOSE      TO COMPUTE THE COORDINATES OF THE NTH POINT OF A PATERN */

/* LINKAGE      CALL NPAT(RES,NPT) */

/* ARGUMENTS    RES     ARRAY TO CONTAIN THE COORDINATES */
/*                      OF THE COMPUTED POINT */
/*              NPT     NUMBER OF THE POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              REAL FUNCTION       DCOS */
/*              REAL FUNCTION       DSIN */

/* Subroutine */ int npat_(doublereal *res, integer *npt)
{
    /* Initialized data */

    static char hpoint[6] = "ZPOINT";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, n, nn, ii;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal ang;
    static integer iii;
    static doublereal tnc;
    static integer nwd, ione;
    static doublereal ttnc;
    static char test[6];
    static integer itwo;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer index, isize, nopts;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer ipntct;



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...       INITIALIZE */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --res;

    /* Function Body */
    n = *npt;
    index = knumbr_1.k0;
    tnc = znumbr_1.z0;

/* ...       DETERMINE PATERN TYPE AND BRANCH */

    k = (integer) (bcanon[1] + znumbr_1.z1em5);
    switch (k) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
    }

/* ...       LINEAR PATERN */

L100:
    if (n == knumbr_1.k1) {
	goto L120;
    }
    nn = n + knumbr_1.k9;
    i__1 = nn;
    for (i__ = 11; i__ <= i__1; ++i__) {
	ii = index + i__;
/* L110: */
	tnc += bcanon[ii - 1];
    }
L120:
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = index + i__ + knumbr_1.k4;
/* L130: */
	res[i__] = bcanon[ii - 1] + tnc * bcanon[ii + 2];
    }
    goto L999;

/* ...       CIRCULAR PATERN */

L200:
    if (n == knumbr_1.k1) {
	goto L220;
    }
    nn = n + knumbr_1.k9;
    i__1 = nn;
    for (i__ = 11; i__ <= i__1; ++i__) {
	ii = index + i__;
/* L210: */
	tnc += bcanon[ii - 1];
    }
L220:
    ang = znumbr_1.degrad * (bcanon[index + 8] + bcanon[index + 9] * tnc);
    res[1] = bcanon[index + 4] + bcanon[index + 7] * cos(ang);
    res[2] = bcanon[index + 5] + bcanon[index + 7] * sin(ang);
    res[3] = bcanon[index + 6];
    goto L999;

/* ...       GRID PATERN */

L300:
    isize = (integer) (bcanon[index + 5] + znumbr_1.z1em5);
    nopts = (integer) (bcanon[index + 6] + znumbr_1.z1em5);
    ttnc = znumbr_1.z0;
    if (n == knumbr_1.k1) {
	goto L350;
    }
    nn = n - knumbr_1.k1;
    ione = nn % nopts;
    itwo = nn / nopts;
    if (itwo % knumbr_1.k2 == knumbr_1.k1) {
	ione = nopts - ione - knumbr_1.k1;
    }
    if (ione == knumbr_1.k0) {
	goto L320;
    }
    i__1 = ione;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = index + 13 + i__;
/* L310: */
	tnc += bcanon[ii - 1];
    }
L320:
    if (itwo == knumbr_1.k0) {
	goto L350;
    }
    i__1 = itwo;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = index + 13 + isize + i__;
/* L330: */
	ttnc += bcanon[ii - 1];
    }
L350:
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = index + 10 + i__;
	iii = isize + ii;
/* L360: */
	res[i__] = bcanon[ii - 4] + tnc * bcanon[ii - 1] + ttnc * bcanon[iii 
		- 1];
    }
    goto L999;

/* ...       RANDOM PATERN */

L400:
    ipntct = knumbr_1.k0;
    index = knumbr_1.k4;
L410:
    holfrm_(&bcanon[index], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, hpoint, (ftnlen)6, (ftnlen)6) != 0) {
	goto L450;
    }
    ipntct += knumbr_1.k1;
    if (ipntct != n) {
	goto L430;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = index + i__ + knumbr_1.k1;
/* L420: */
	res[i__] = bcanon[ii - 1];
    }
    goto L999;
L430:
    index += knumbr_1.k4;
    goto L410;
L450:
    nopts = (integer) (bcanon[index + 3] + znumbr_1.z1em5);
    ipntct += nopts;
    if (ipntct < n) {
	goto L460;
    }
    n = n + nopts - ipntct;
    k = (integer) (bcanon[index + 1] + znumbr_1.z1em5);
    switch (k) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }
L460:
    isize = (integer) bcanon[index + 2];
    index = index + isize + knumbr_1.k1;
    goto L410;

/* ...       PERIM PATERN */

L500:
    goto L999;

L999:
    return 0;
} /* npat_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


