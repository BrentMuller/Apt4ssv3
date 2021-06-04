/* GOLPLN.f -- translated by f2c (version 20100827).
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
    integer id[24];
    doublereal obnam1;
} plgol_;

#define plgol_1 plgol_

struct {
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__22220 = 22220;

/* *** SOURCE FILE : M0012238.V01   *** */

/* Subroutine */ int golpln_(integer *j11, integer *iret)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal u, v, di, du, ue, dv, ve, ou, ov, um, vm;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer iic;
#define iat ((integer *)&plgol_1 + 17)
    static integer ipl;
    extern /* Subroutine */ int gop_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
#define uva ((doublereal *)&plgol_1 + 1)
#define uve ((doublereal *)&plgol_1 + 2)
    static doublereal vll, spv[52];
#define ipl1 ((integer *)&plgol_1 + 20)
#define ipl2 ((integer *)&plgol_1 + 21)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define iart ((integer *)&plgol_1 + 12)
    static integer iwas;
    static doublereal dist;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal distm, odist;
#define ithru ((integer *)&plgol_1 + 19)
#define istrt ((integer *)&plgol_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cpldst_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *);
#define uvcons ((doublereal *)&plgol_1)


/*   ROUTINE TO TEST, IF A PLANE IS INVOLVED AND TO CALCULATE A UV VALUE */



/*  CONTROL OF TEST-OUTPUT */


/* UVCONS:    U-, V- CONSTANT, GIVEN AT  "UCONST,U" OR "VCONST,V" */

/* UVA:       START-PRAMETER, GIVEN BY "START,S" */

/* UVE:       END-PARAMETER, GIVEN BY "THRU,T" */

/* IART:      IART = 1   PLOTFT/SCURV,.........,PARAM,.... */
/*            IART = 2   PLOTFT/SCURV,.........,FLOW ,.... */
/*            IART = 3   PLOTFT/SSURF,UCONST,U,........... */
/*            IART = 4   PLOTFT/SSURF,VCONST,V,........... */
/*            IART = 5   PLOTFT/SSURF,GRID,............... */
/*            IART = 6   GOLOFT/SSURF,UCONST,U,........... */
/*            IART = 7   GOLOFT/SSURF,VCONST,V,........... */

/* IAT:       IAT   = 0 : AT NOT PROGRAMMED */
/*            IAT   = 1 : AT   "AT,A",        = 2 AT   "AT,TO,PL1" */
/*            IAT   = 3 : AT   "AT,ON,PL1,    = 4 AT   "AT,PAST,PL1 */

/* ISTRT:     ISTRT = 0 : START NOT PROGRAMMED */
/*            ISTRT = 1 : AT   "START,A",     = 2 AT   "START,TO,PL1" */
/*            ISTRT = 3 : AT   "START,ON,PL1, = 4 AT   "START,PAST,PL1 */

/* ITHRU:     ITHRU = 0 : THRU NOT PROGRAMMED */
/*            ITHRU = 1 : AT   "THRU,A",      = 2 AT   "THRU,TO,PL1" */
/*            ITHRU = 3 : AT   "THRU,ON,PL1,  = 4 AT   "THRU,PAST,PL1 */

/* IPL1:      CF-BEGIN OF THE "AT" OR "START" PLANE IN THE ARRAY SSCAN */

/* IPL2:      CF-BEGIN OF THE  "THRU" PLANE IN THE ARRAY SSCAN */

/*  COMMON TOTAL */

/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*  BLANK COMMON */

/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*  EVALUATION RESULTS */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* RETURN IF NOT >GOLOFT< */
    if (*iart != 6 && *iart != 7) {
	return 0;
    }

/* LOOP OVER THE 3 POSSIBLE PLANE CONDITIONS: >AT<,>START<,>THRU< */
    for (i__ = 1; i__ <= 3; ++i__) {

/* >AT< CONDITION */
	iwas = *iat;
	ipl = *ipl1;
	iic = ifxcor_1.ics;
	if (i__ == 1) {
	    goto L1;
	}

/* >START< CONDITION */
	iwas = *istrt;
	if (i__ == 2) {
	    goto L1;
	}

/* >THRU< CONDITION */
	iwas = *ithru;
	ipl = *ipl2;
	iic = ifxcor_1.ics + ifxcor_1.lsv1;

/* WITH AT CONDITION,  SET THRU PARAMETER EQUAL START PARAMETER */
L1:
	if (i__ == 1 && iwas != 0) {
	    *uve = *uva;
	}

/* CHECK,  IF PLANE CONDITION */
	if (iwas < 2 || iwas > 4) {
	    goto L90;
	}

/* PROLOG FOR >UCONST< */
	if (*iart != 6) {
	    goto L10;
	}
	u = *uvcons;
	du = 0.;
	ue = u;
	v = 0.;
	dv = .5;
	ve = sscan[*j11 + 8] - 1.;
	goto L20;

/* PROLOG FOR >VCONST< */
L10:
	u = 0.;
	du = .5;
	ue = sscan[*j11 + 9] - 1.;
	v = *uvcons;
	dv = 0.;
	ve = v;

/* COMPUTE PLANE ORIENTATION AND SWITCH IF NECESSARY */
/*  FIRST TOOL TIP IS INVESTIGATED */
L20:
	gop_(&c__1, &u, &v, spv, j11, iret);

/* NORMALISATION OF INPUT PLANE */
/* Computing 2nd power */
	d__1 = sscan[ipl - 1];
/* Computing 2nd power */
	d__2 = sscan[ipl];
/* Computing 2nd power */
	d__3 = sscan[ipl + 1];
	vll = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	for (j = 1; j <= 4; ++j) {
/* L21: */
	    sscan[ipl + j - 2] /= vll;
	}

/* DISTANCE OF FIRST POINT TO PLANE (DIST=AX+BY+CZ-D) */
	di = sscan[ipl - 1] * spv[32] + sscan[ipl] * spv[33] + sscan[ipl + 1] 
		* spv[34] - sscan[ipl + 2];

/* INVERSION OF PLANE IF DISTANCE IS NEGETIVE */
	if (di > 0.) {
	    goto L25;
	}
	for (j = 1; j <= 4; ++j) {
/* L22: */
	    sscan[ipl + j - 2] = -sscan[ipl + j - 2];
	}

/* PRESET OLD DISTANCE */
L25:
	cpldst_(spv, &sscan[ipl - 1], &sv_1.th[iic - 1], &iwas, &odist, iret);
	dist = odist;
	ou = u;
	ov = v;
	goto L35;

/* FIND INTERSECTION (OUTER LOOP) */
/*  OLD DISTANCE AND OLD PARAMETERS */
L30:
	odist = dist;
	ou = u;
	ov = v;

/* NEW PARAMETERS */
	u += du;
	v += dv;
	if (u > ue || v > ve) {
	    goto L80;
	}
	gop_(&c__1, &u, &v, spv, j11, iret);
	cpldst_(spv, &sscan[ipl - 1], &sv_1.th[iic - 1], &iwas, &dist, iret);

/*  TOLERANCE INVESTIGATION (OUTTOL) */
L35:
	if (dist > sv_1.tau1[iic - 1]) {
	    goto L30;
	}

/*  INTOL: */
	if (dist >= sv_1.tau2[iic - 1]) {
	    goto L50;
	}

/* FIND INTERSECTION (INNER LOOP): NESTED INTERVALS */
L40:
	um = (ou + u) / 2.;
	vm = (ov + v) / 2.;
	gop_(&c__1, &um, &vm, spv, j11, iret);
	cpldst_(spv, &sscan[ipl - 1], &sv_1.th[iic - 1], &iwas, &distm, iret);

/* INSIDE OUTTOL TOLERANCE ? */
	if (distm <= sv_1.tau1[iic - 1]) {
	    goto L45;
	}
/* NO */
	ou = um;
	ov = vm;
	odist = distm;

/* BREAK FOR UNLIMITED LOOP */
	if (odist - dist < 1e-5) {
	    goto L50;
	}
	goto L40;

/* INSIDE INTOL TOLERANCE ? */
L45:
	if (dist >= sv_1.tau2[iic - 1]) {
	    goto L50;
	}
/* NO */
	u = um;
	v = vm;
	dist = distm;

/* BREAK FOR UNLIMITED LOOP */
	if (odist - dist < 1e-5) {
	    goto L50;
	}
	goto L40;

/*  ONE FINAL POINT FOUND */
L50:
	if (*iart == 6 && i__ != 3) {
	    *uva = v;
	}
	if (*iart == 6 && i__ == 3) {
	    *uve = v;
	}
	if (*iart == 7 && i__ != 3) {
	    *uva = u;
	}
	if (*iart == 7 && i__ == 3) {
	    *uve = u;
	}
	if (i__ == 1) {
	    *iat = 1;
	}

/* WITH AT CONDITION,  SET THRU PARAMETER EQUAL START PARAMETER */
	if (i__ == 1) {
	    *uve = *uva;
	}
	if (i__ == 2) {
	    *istrt = 1;
	}
	if (i__ == 3) {
	    *ithru = 1;
	}
	goto L90;

/* NO INTERSECTION BETWEEN GOLOFT CUTTER PATH AND PLANE FOUND */
L80:

/*  POINT OUTSIDE OF U/V PARAMETERS OF THE PATCH */

/*  POINT IS OUTSIDE OF THE U/V PARAMETERS OF THE PATCH. */
	if (ssprt_1.sstest) {
	    aerr_(&c__22220, "GOLPLN  ", (ftnlen)8);
	}
	ifxcor_1.iaerr = 1;
	*iret = max(*iret,3);
	goto L90;

L90:
	;
    }
    return 0;
} /* golpln_ */

#undef uvcons
#undef bcanon
#undef istrt
#undef ithru
#undef sscan
#undef canon
#undef iart
#undef ipl2
#undef ipl1
#undef uve
#undef uva
#undef iat
#undef can


