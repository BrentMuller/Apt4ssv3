/* PARMF.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal ua, va, pnum, ut, us, fnam;
} parmfc_;

#define parmfc_1 parmfc_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__8 = 8;

/* *** SOURCE FILE : M0004164.V08   *** */

/*   PARAMETER FETCH  ROUTINES */
/*   CALLABLE AFTER EXTRINSIC EXTRACTION OF POINT/VECTOR IN APT109 */


/*  ENTRY WITH 1 ARGUMENT */

/* Subroutine */ int parmf1_(doublereal *res, doublereal *arg1)
{
    /* Initialized data */

    static char uval[4] = "UVAL";
    static char vval[4] = "VVAL";
    static char pval[4] = "PVAL";
    static char tval[4] = "TVAL";
    static char sval[4] = "SVAL";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer is;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, mode, iloc, iart, isub;
    static char test[4];
    static doublereal fnam1;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --arg1;
    --res;

    /* Function Body */


    iart = 1;
    if (parmfc_1.fnam == 0.) {
	goto L20;
    }
    holfrm_(&arg1[1], test, &c__1, &c__4, &nwd, (ftnlen)4);
    if (s_cmp(test, uval, (ftnlen)4, (ftnlen)4) == 0) {
	goto L1;
    }
    if (s_cmp(test, vval, (ftnlen)4, (ftnlen)4) == 0) {
	goto L2;
    }
    if (s_cmp(test, pval, (ftnlen)4, (ftnlen)4) == 0) {
	goto L3;
    }
    if (s_cmp(test, tval, (ftnlen)4, (ftnlen)4) == 0) {
	goto L4;
    }
    if (s_cmp(test, sval, (ftnlen)4, (ftnlen)4) == 0) {
	goto L5;
    }
/*  LOOK FOR FUNCTION WITH GEOMETRY INPUT */
/* L30: */
    if (ckdef_(&arg1[1])) {
	goto L21;
    }
    unpack_(&arg1[1], &mode, &is, &isub);
    if (mode != 29 && mode != 30) {
	goto L21;
    }
/*          CHECK,IF RIGHT GEOMETRY */
    fnam1 = arg1[is + 1];
    if (isub >= 1) {
	fnam1 = arg1[isub * is + isub];
    }
    if (parmfc_1.fnam != fnam1) {
	goto L20;
    }

/*          MOVE THE EXTERNAL CANONICAL FORM TO  CANON */

    apt094_(&c__3, &arg1[1], &iloc);
    if (ckdef_(&arg1[1])) {
	goto L21;
    }
/*   SSURF ? */
    if (mode != 29) {
	goto L35;
    }
/*   SSURF GIVEN */
    goto L3;
/*    SCURV ? */
L35:
    if (mode != 30) {
	goto L21;
    }
/*   SCURV GIVEN */
/*  OUTPUT FOR >PARMF(C)< OR >PARMF(C,PARAM)< */
/* L36: */
    res[1] = parmfc_1.us + parmfc_1.ut - 1.;
    return 0;
/*  OUTPUT FOR >PARMF(UVAL)< OR >PARMF(S,UPARAM)< (NON MESH TYPE) */
L1:
    res[1] = parmfc_1.ua;
    return 0;
/*  OUTPUT FOR >PARMF(VVAL)< OR >PARMF(S,VPARAM)< (NON MESH TYPE) */
L2:
    res[1] = parmfc_1.va;
    return 0;
/*  OUTPUT FOR >PARMF(PVAL)< OR >PARMF(S,PATCH)< */
L3:
    res[1] = parmfc_1.pnum;
    return 0;
/*  OUTPUT FOR >PARMF(TVAL)< */
L4:
    res[1] = parmfc_1.ut;
    return 0;
/*  OUTPUT FOR >PARMF(SVAL)< */
L5:
    res[1] = parmfc_1.us;
    return 0;
/*    'NO PARAMETER EXISTING' */
L20:
    error_(&c__42, "PARMF   ", (ftnlen)8);
    goto L22;
/*    'WRONG PARMF CALL' */
L21:
    error_(&c__43, "PARMF   ", (ftnlen)8);
L22:
    res[1] = 0.;
    return 0;
} /* parmf1_ */

#undef bcanon
#undef sscan
#undef canon
#undef can






/*  ENTRY WITH TWO ARGUMENTS */
/* Subroutine */ int parmf2_(doublereal *res, doublereal *arg1, doublereal *
	arg2)
{
    /* Initialized data */

    static char flow[8] = "FLOW    ";
    static char param[8] = "PARAM   ";
    static char uparam[8] = "UPARAM  ";
    static char vparam[8] = "VPARAM  ";
    static char patch[8] = "PATCH   ";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal w1, w2, ub;
    static integer ip, mn, is, iu, iv, nu;
    static doublereal pu;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal uma, umb;
    static integer nwd;
    static doublereal usf, usn, rts[3];
    static integer mode, iloc, iseg, iart;
    static doublereal span;
    static integer isub;
    static char test[8];
    static doublereal fnam1;
    static integer iseg1, iseg2;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    extern logical ckdef_(doublereal *);
    static integer isega, ifseg;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer iflow;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer iflow1, iflow2;
    extern /* Subroutine */ int gcubic_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --arg2;
    --arg1;
    --res;

    /* Function Body */


    iart = 2;
    if (parmfc_1.fnam == 0.) {
	goto L20;
    }
    holfrm_(&arg2[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
/*  LOOK FOR FUNCTION WITH GEOMETRY INPUT */
/* L30: */
    if (ckdef_(&arg1[1])) {
	goto L21;
    }
    unpack_(&arg1[1], &mode, &is, &isub);
    if (mode != 29 && mode != 30) {
	goto L21;
    }
/*          CHECK,IF RIGHT GEOMETRY */
    fnam1 = arg1[is + 1];
    if (isub >= 1) {
	fnam1 = arg1[isub * is + isub];
    }
    if (parmfc_1.fnam != fnam1) {
	goto L20;
    }

/*          MOVE THE EXTERNAL CANONICAL FORM TO  CANON */

    apt094_(&c__3, &arg1[1], &iloc);
    if (ckdef_(&arg1[1])) {
	goto L21;
    }
/*   SSURF ? */
    if (mode != 29) {
	goto L35;
    }
/*   SSURF GIVEN */
    if (s_cmp(test, patch, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3;
    }
/*   MESH TYPE ? */
    if (canon[iloc + 3] == 2.) {
	goto L31;
    }
    if (s_cmp(test, uparam, (ftnlen)8, (ftnlen)8) == 0) {
	goto L1;
    }
    if (s_cmp(test, vparam, (ftnlen)8, (ftnlen)8) == 0) {
	goto L2;
    }
    goto L21;
/*  MESH TYPE */
L31:
    ip = (integer) parmfc_1.pnum;
    nu = (integer) (canon[iloc + 8] - 1.);
    iv = (ip - 1) / nu;
    if (s_cmp(test, uparam, (ftnlen)8, (ftnlen)8) == 0) {
	goto L32;
    }
    if (s_cmp(test, vparam, (ftnlen)8, (ftnlen)8) == 0) {
	goto L33;
    }
    goto L21;
/*  GLOBAL U-PARAMETER  >PARMF(S,UPARAM)< (MESH TYPE) */
L32:
    iu = ip - 1 - iv * nu;
    res[1] = iu + parmfc_1.ua;
    return 0;
/*  GLOBAL V-PARAMETER  >PARMF(S,VPARAM)< (MESH TYPE) */
L33:
    res[1] = iv + parmfc_1.va;
    return 0;
/*    SCURV ? */
L35:
    if (mode != 30) {
	goto L21;
    }
/*   SCURV GIVEN */
    if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	goto L36;
    }
    if (s_cmp(test, flow, (ftnlen)8, (ftnlen)8) == 0) {
	goto L37;
    }
/*  OUTPUT FOR >PARMF(C)< OR >PARMF(C,PARAM)< */
L36:
    res[1] = parmfc_1.us + parmfc_1.ut - 1.;
    return 0;
L37:
    if (canon[iloc + 6] == 0.) {
	goto L21;
    }
/*  OUTPUT FOR >PARMF(C,FLOW)< */
/*  SEARCH IN FLOW DESCRIPTION OF NATURAL SEGMENT */
    is = (integer) (parmfc_1.us - 1.);
    ifseg = (integer) canon[iloc + 5];
    iflow1 = (integer) canon[iloc + ifseg - 1 + (is << 2) - 1];
    iflow2 = (integer) (iflow1 + (canon[iloc + ifseg + (is << 2) - 1] - 1.) * 
	    4.);
    iflow1 = iflow1 + iloc - 1;
    iflow2 = iflow2 + iloc - 1;
    i__1 = iflow2;
    for (iflow = iflow1; iflow <= i__1; iflow += 4) {
	if (parmfc_1.ut >= canon[iflow] && parmfc_1.ut < canon[iflow + 4]) {
	    goto L50;
	}
/* L40: */
    }
    goto L21;
/*  COMPUTE FLOW-PARAMETER */
L50:
    span = canon[iflow + 3] - canon[iflow - 1];
    parmfc_1.ua = canon[iflow];
    ub = canon[iflow + 4];
    uma = canon[iflow + 1] * span;
    umb = canon[iflow + 5] * span;
    w1 = (ub - parmfc_1.ua) * 3. - uma - uma - umb;
    w2 = (parmfc_1.ua - ub) * 2. + uma + umb;
    d__1 = parmfc_1.ua - parmfc_1.ut;
    gcubic_(&w2, &w1, &uma, &d__1, rts, &mn);
    if (mn == 0) {
	goto L21;
    }
    i__1 = mn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pu = rts[i__ - 1];
	if (pu >= -1e-7 && pu < 1.0000001) {
	    goto L70;
	}
/* L60: */
    }
    goto L21;
/* COMPUTE GLOBAL FLOW PARAMETER */
L70:
    pu = canon[iflow - 1] + pu * span;
    iseg1 = (integer) (iloc - 1 + canon[iloc + 7]);
    isega = (integer) canon[iloc + 6];
    iseg2 = iseg1 + (isega - 1 << 2);
    usn = parmfc_1.us - 1.;
    usf = 0.;
    i__1 = iseg2;
    for (iseg = iseg1; iseg <= i__1; iseg += 4) {
	if (canon[iseg - 1] + canon[iseg] > usn) {
	    goto L90;
	}
	usf += 1.;
/* L80: */
    }
/* COMPUTE FINAL GLOBAL FLOW PARAMETER */
L90:
    res[1] = usf + pu;
    return 0;
/*  OUTPUT FOR >PARMF(UVAL)< OR >PARMF(S,UPARAM)< (NON MESH TYPE) */
L1:
    res[1] = parmfc_1.ua;
    return 0;
/*  OUTPUT FOR >PARMF(VVAL)< OR >PARMF(S,VPARAM)< (NON MESH TYPE) */
L2:
    res[1] = parmfc_1.va;
    return 0;
/*  OUTPUT FOR >PARMF(PVAL)< OR >PARMF(S,PATCH)< */
L3:
    res[1] = parmfc_1.pnum;
    return 0;
/*  OUTPUT FOR >PARMF(TVAL)< */
/* L4: */
    res[1] = parmfc_1.ut;
    return 0;
/*  OUTPUT FOR >PARMF(SVAL)< */
/* L5: */
    res[1] = parmfc_1.us;
    return 0;
/*    'NO PARAMETER EXISTING' */
L20:
    error_(&c__42, "PARMF   ", (ftnlen)8);
    goto L22;
/*    'WRONG PARMF CALL' */
L21:
    error_(&c__43, "PARMF   ", (ftnlen)8);
L22:
    res[1] = 0.;
    return 0;
} /* parmf2_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


