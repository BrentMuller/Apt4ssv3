/* TLCONV.f -- translated by f2c (version 20100827).
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
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
} glflgs_;

#define glflgs_1 glflgs_

struct {
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
} fxcor_;

#define fxcor_1 fxcor_

struct {
    char modfer[6];
} charct_;

#define charct_1 charct_

struct {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    integer iplgo[26], jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10], vta[3];
} plgol_;

#define plgol_1 plgol_

/* Table of constant values */

static integer c__22218 = 22218;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;

/* *** SOURCE FILE : M0012349.V02   *** */

/* Subroutine */ int tlconv_(void)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, n;
    extern /* Subroutine */ int bad_();
    static integer lioc;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer nseq;
    static char badmsg[12];
    extern /* Subroutine */ int record_(integer *), cprint_(char *, ftnlen);


/* ROUTINE WILL SET AND CONVERT TOOLDATA OF THE CUTTER */


/*  CONTROL OF TEST-OUTPUT */



/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */


/*  COMMON FOR  >PLOTFT/GOLOFT< */


/*  VALUES FOR  >PLOTFT/GOLOFT< */

/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*  USED CUTTER SEGMENT */

/*  NUMBER OF VALID CUTTER SEGMENTS */

/*  CUTTER SEGMENT IN TLLDAT ARRAYS */

/*  NATURE OF SEGMENT */

/*  COMPONENTS OF SEGMENT AND UNIT NORMAL POINTING INTO THE CUTTER */

/*  DISTANCE PARALLEL TO THE CUTTER AXIS */

/*  DISTANCE TO THE CUTTER AXIS */

/*  ELEMENT LENGTH */
/*  VECTOR COMPONENTS OF THE TOOL AXIS VECTOR */



/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/*  THE FOLLOWING DATA ARE SET, IF CUTDAT(1).GE. 0.001: */
    if (fxcor_1.cutdat[0] < .001) {
	goto L999;
    }
    plgol_1.ncseg = 0;
    plgol_1.jcseg = 0;

/* FIND THE NUMBER OF VALID SEGMENTS, ==> NCSEG */
    for (i__ = 0; i__ <= 7; ++i__) {
	if (tlldat_1.tcont[i__] != -1.) {
	    goto L801;
	}
	n = i__ + 1;
	goto L802;
L801:
	;
    }

L802:
    for (j = n; j <= 8; ++j) {
	if (tlldat_1.tcont[j] == 0.) {
	    goto L800;
	}
	++plgol_1.ncseg;

/* NUMBER OF RELATET SEGMENT IN TLLDAT */
	plgol_1.icseg[plgol_1.ncseg - 1] = j;

/* SEGMENT LINE OR CIRCLE */
	plgol_1.nlioci[plgol_1.ncseg - 1] = (integer) tlldat_1.tlinc[j];

	if (tlldat_1.tlinc[j] != 0.) {
	    goto L10;
	}

/* SEGMENT IS AN ARC (CIRCLE) */
	if (tlldat_1.tanhi[j - 1] > -1e38) {
	    goto L11;
	}
	plgol_1.sinal[plgol_1.ncseg - 1] = 0.;
	goto L12;
L11:
	plgol_1.sinal[plgol_1.ncseg - 1] = 1. / sqrt(tlldat_1.tanhi[j - 1] * 
		tlldat_1.tanhi[j - 1] + 1.);

L12:
	if (tlldat_1.tanhi[j - 1] > -1e38) {
	    goto L13;
	}
	plgol_1.cosal[plgol_1.ncseg - 1] = -1.;
	goto L14;
L13:
	plgol_1.cosal[plgol_1.ncseg - 1] = tlldat_1.tanhi[j - 1] * 
		plgol_1.sinal[plgol_1.ncseg - 1];

L14:
	plgol_1.cuty[plgol_1.ncseg - 1] = tlldat_1.tlhite[j - 1];
	plgol_1.cutx[plgol_1.ncseg - 1] = tlldat_1.ri[j - 1];
	plgol_1.cutl[plgol_1.ncseg - 1] = tlldat_1.corrad[j - 1];
	goto L800;

L10:
	if (tlldat_1.tlinc[j] != 1.) {
	    goto L20;
	}

/* SEGMENT IS A LINE */
	plgol_1.sinal[plgol_1.ncseg - 1] = sinl[j - 1];
	plgol_1.cosal[plgol_1.ncseg - 1] = cosl[j - 1];
	plgol_1.cuty[plgol_1.ncseg - 1] = tlldat_1.tlhite[j - 1];
	plgol_1.cutx[plgol_1.ncseg - 1] = tlldat_1.ri[j - 1];
	plgol_1.cutl[plgol_1.ncseg - 1] = tlldat_1.umax[j - 1];
	goto L800;

/* WRONG DATA IN TLINC, VALUE NOT LINE OR NOT CIRCLE */
L20:
	aerr_(&c__22218, "TLCONV  ", (ftnlen)8);
L800:
	;
    }

/* TEST PRINT-OUT OF THE CONVERTET AND CALCUALTED VALUES */
    if (! ssprt_1.sstest) {
	goto L999;
    }
    record_(&nseq);
    s_copy(badmsg, " NEW CUTTER:", (ftnlen)12, (ftnlen)12);
    cprint_(badmsg, (ftnlen)12);
    bad_(&c_n1, &c__0, "ISN ", &nseq, (ftnlen)4);

    i__1 = plgol_1.ncseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	lioc = plgol_1.nlioci[i__ - 1];
	bad_(&c__1, &c__0, "LIOC", &lioc, (ftnlen)4);
	bad_(&c__1, &c__1, "COAL", &plgol_1.cosal[i__ - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "SIAL", &plgol_1.sinal[i__ - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "CUTY", &plgol_1.cuty[i__ - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "CUTX", &plgol_1.cutx[i__ - 1], (ftnlen)4);
	bad_(&c_n1, &c__1, "CUTL", &plgol_1.cutl[i__ - 1], (ftnlen)4);
/* L808: */
    }

L999:
    return 0;
} /* tlconv_ */

#undef sinl
#undef cosl


