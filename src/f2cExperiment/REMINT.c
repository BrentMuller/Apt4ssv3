/* REMINT.f -- translated by f2c (version 20100827).
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
    doublereal cxhull[24000]	/* was [4][6][1000] */, dulim[1000], dvlim[
	    1000], curmax[1000], curmin[1000];
    integer ncxhul[1000], ngp, icursf;
} inidat_;

#define inidat_1 inidat_

struct {
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;

/* *** SOURCE FILE : REMINT.ORG   *** */

/* Subroutine */ int remint_(doublereal *te, doublereal *ta, doublereal *tul, 
	doublereal *psurf, integer *ipsize, doublereal *pside, doublereal *
	pthick, doublereal *tolin, integer *lsusp, integer *nsusp)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
    static integer ipen, npat;
    static doublereal upen, vpen;
    static integer iedge, iflag;
    extern /* Subroutine */ int mixal_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *);
    static doublereal pnorm[3];
    static integer nitera;
    static doublereal toolce[3], penmax, ppoint[3], tpoint[3], ustart, vstart;


/*     PURPOSE : TO CHECK OUT SUSPECT REMOTE PATCHES AND IF ANY */
/*               PENETRATION DETECTED STORE THE WORST PENETRATION */
/*               FOR EACH PATCH IN THE INTERFERENCE TABLE */

/*     ARGUMENTS: */

/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     TUL     -  TOOL GEOMETRY */
/*     PSURF   -  CANONICAL FORM OF PART SURFACE (SSURF) */
/*     IPSIZE  -  SIZE OF CANONICAL FORM */
/*     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV) */
/*     PTHICK  -  THICKNESS OFFSET FROM SURFACE */
/*     TOLIN   -  TOLERANCE (PS INTOL) */
/*     LSUSP   -  LIST OF SUSPECT PATCHES */
/*     NSUSP   -  NUMBER OF SUSPECT PATCHES */






/* .... INTERFERENCE CHECKING INITIAL DATA */



/* .... SPHERICAL SURFACE ENCLOSURES (HULLS) */
/* .... NUMBER OF HULLS */
/* .... DU ITERATION LIMIT FOR PATCHES */
/* .... DV ITERATION LIMIT FOR PATCHES */
/* .... MAXIMUM AND MINIMUM CURVATURE OF PATCHES */

/*     MXNP   -  MAXIMUM NUMBER OF PATCHES PER SURFACE */
/*     NGP    -  NUMBER OF PATCHES IN CURRENT SURFACE */
/*     ICURSF -  EXTERNAL LDA FILE RECORD NUMBER FOR CURRENT SURFACE */



/*    INTERFERENCE TABLE */






/*     LOCAL VARIABLES */


/* .... DEBUG FLAGS */



/* .... CALCULATE 'TOOL CENTER' FOR SIMPLE BE AND CRC CUTTERS */

    /* Parameter adjustments */
    --te;
    --ta;
    --tul;
    --psurf;
    --lsusp;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	toolce[i__ - 1] = te[i__] + (tul[4] + tul[1]) * ta[i__];
/* L50: */
    }

    interf_1.npintr = 0;

/* .... FOR EACH SUSPECT PATCH */

    i__1 = *nsusp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	npat = lsusp[i__];
	if (interf_1.lnpint != 0) {

/* .... THERE WAS AT LEAST ONE INTERFERENCE DETECTED AT PREVIOUS TOOL */
/*     POSITION - CHECK IF ANY PENETRATION WITH THIS PATCH */

	    i__2 = interf_1.lnpint;
	    for (j = 1; j <= i__2; ++j) {
		if (npat == interf_1.lpintr[j - 1]) {
/* .... TAKE U,V OF PREVIOUS INTERSECTION AS START VALUES */
		    ustart = interf_1.luintr[j - 1];
		    vstart = interf_1.lvintr[j - 1];
		    goto L200;
		}
/* L100: */
	    }
	}
/* .... OTHERWISE TAKE PARAMETRIC MID POINT AS START */
	ustart = .5f;
	vstart = .5f;
L200:

/* .... SEARCH THIS PATCH FOR INTERFERENCE */

	mixal_(&npat, ipsize, &psurf[1], pside, pthick, &tul[1], toolce, &ta[
		1], &ustart, &vstart, &inidat_1.dulim[npat - 1], &
		inidat_1.dvlim[npat - 1], &upen, &vpen, ppoint, tpoint, pnorm,
		 &penmax, &ipen, &iflag, &iedge, &nitera);

/* .... DEBUG PRINT */

	if (ibugg_1.ibug == 11) {
	    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	    bad_(&c__1, &c__0, "NPAT", &npat, (ftnlen)4);
	    bad_(&c__1, &c__0, "ITER", &nitera, (ftnlen)4);
	}

	if (iflag == 0) {
	    if (penmax > *tolin) {
/* .... STORE IN INTERFERENCE TABLE */
		++interf_1.npintr;
		interf_1.dintr[interf_1.npintr - 1] = penmax;
		interf_1.uintr[interf_1.npintr - 1] = upen;
		interf_1.vintr[interf_1.npintr - 1] = vpen;
		interf_1.pintr[interf_1.npintr - 1] = npat;
		for (j = 1; j <= 3; ++j) {
		    interf_1.spintr[j + interf_1.npintr * 3 - 4] = ppoint[j - 
			    1];
		    interf_1.tpintr[j + interf_1.npintr * 3 - 4] = tpoint[j - 
			    1];
		    interf_1.snintr[j + interf_1.npintr * 3 - 4] = pnorm[j - 
			    1];
/* L300: */
		}
		interf_1.iseg[interf_1.npintr - 1] = ipen;

	    }

	}
/* L400: */
    }

    return 0;
} /* remint_ */

