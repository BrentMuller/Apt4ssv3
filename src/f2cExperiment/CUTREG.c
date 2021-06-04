/* CUTREG.f -- translated by f2c (version 20100827).
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
    integer ibug, i1, i2;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal dgeom[4], dlim[4], tldir[3], dofset;
    integer itldir, idtool, nds;
} xds_;

#define xds_1 xds_

struct {
    doublereal pgeom[4], pside, pthick;
    integer iptool, nps;
} xps_;

#define xps_1 xps_

struct {
    doublereal clrpln[4], fed[4];
    integer nclrpl, nfeed;
} xfeed_;

#define xfeed_1 xfeed_

struct {
    doublereal sstep[4];
    integer nstepo;
} xstepo_;

#define xstepo_1 xstepo_

struct {
    doublereal axis[3];
    integer iaxis, naxis;
} xaxis_;

#define xaxis_1 xaxis_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n2 = -2;
static integer c__2 = 2;
static integer c_n4 = -4;

/* *** SOURCE FILE : M0001062.V06   *** */

/* Subroutine */ int cutreg_(doublereal *word, doublereal *cdir, doublereal *
	ust, doublereal *vst, doublereal *pdir, integer *idtype, integer *
	iqual, doublereal *tul, doublereal *ptoli, doublereal *ptolo, 
	doublereal *dtol, doublereal *amaxdp, doublereal *elmax, integer *
	maxcl, integer *iskp, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-14;
    static doublereal apickf = 166.;
    static doublereal azigza = 61.;

    /* Local variables */
    static integer i__;
    static doublereal ta[3], td[3], te[3];
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ilc, icr;
    static doublereal par[2], adir[2], alim[4];
    extern /* Subroutine */ int pchg_(doublereal *, doublereal *, doublereal *
	    );
    static integer ifin;
    static doublereal plim[4], svta[3], svtd[3], svte[3];
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int clift_(doublereal *, doublereal *, doublereal 
	    *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer ibugt;
    static doublereal psave[2];
    static integer ipass, ipart, idriv;
    static doublereal dstep, tpdir;
    extern /* Subroutine */ int clput_(doublereal *, doublereal *, integer *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal scalht, tscalh;
    static integer ipathk, mmaxcl, miclsk, iclskp;
    extern /* Subroutine */ int fedput_(doublereal *);
    static doublereal tpthic;
    static integer mxpath;
    extern /* Subroutine */ int sspath_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer midtyp;
    static doublereal tstepm, tstepo, stepmx, stepov;

/* ---PURPOSE IS TO CALL PATH ROUTINE, SSPATH, TO GENERATE THE NECESSARY */
/* ---CLRECORDS IN RESPONSE TO AN AREA CLEARANCE COMMAND */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --tul;

    /* Function Body */

/* ---      COUNT OF MAXIMUM CALLS TO SSPATH */
    ipathk = 0;
/* ---      MAXIMUM NUMBER OF CALLS ALLOWED TO SSPATH */
    mxpath = (integer) xstepo_1.sstep[3];
/* ---      MXPATH=0, MEANS ESSENTIALLY  NO LIMIT */
    if (mxpath <= 0) {
	mxpath = 1000000;
    }
    if (*word == apickf) {
	goto L500;
    }
    if (*word == azigza) {
	goto L100;
    }
    goto L999;

/* ---ZIGZAG PATTERN MACHINING */
L100:
    ipass = 1;
    ifin = 0;
    iclskp = 0;
    if (*iskp == 1) {
	iclskp = 1;
    }
    ipart = (integer) xps_1.pgeom[3];
    idriv = (integer) xds_1.dgeom[3];
    par[0] = *ust;
    par[1] = *vst;
    dstep = one;
    scalht = xstepo_1.sstep[0];
    stepmx = xstepo_1.sstep[1];
    stepov = zero;

L120:
/* ---COMMON ENTRY POINT FOR ALL PASSES IN MAIN DIRECTION */
    if (ibugg_1.ibug != 11) {
	goto L105;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c__1, &c__0, "PASS", &ipass, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", par, (ftnlen)4);
L105:

    for (i__ = 1; i__ <= 4; ++i__) {
/* L110: */
	plim[i__ - 1] = xds_1.dlim[i__ - 1];
    }
    tpdir = *pdir;
    if (ipass % 2 == 0) {
	tpdir = -(*pdir);
    }
    *irr = 0;
    clput_(te, ta, &c_n1);

    *ust = par[0];
    *vst = par[1];
    sspath_(&_BLNK__1.com[idriv - 1], idtype, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &xps_1.pthick, ptoli, ptolo, &xps_1.iptool, &tul[1], ust, vst, &
	    scalht, &stepov, &stepmx, amaxdp, elmax, maxcl, &iclskp, iqual, 
	    te, ta, td, par, irr);
    if (*irr != 0) {
	goto L999;
    }

/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }
/* ---IF FINAL FLAG HAS BEEN SET THEN QUIT NOW */
    if (ifin == 1) {
	goto L999;
    }
/* ---NOW CALCULATE PARAMETERS NECESSARY FOR A SIDE STEP */
    tpdir = *cdir;
    midtyp = 3 - *idtype;
    icr = 2;
    if (*idtype == 2) {
	icr = 1;
    }
    ilc = (icr << 1) - 1;
    for (i__ = 1; i__ <= 2; ++i__) {
/* L210: */
	psave[i__ - 1] = par[i__ - 1];
    }
    pchg_(&par[icr - 1], cdir, &stepov);
    par[icr - 1] += *cdir * stepov;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L220: */
	plim[i__ - 1] = xds_1.dlim[i__ - 1];
    }
    if (par[icr - 1] < xds_1.dlim[ilc - 1] + smal && *cdir < zero) {
	ifin = 1;
    }
    if (par[icr - 1] < xds_1.dlim[ilc - 1] + smal && *cdir < zero) {
	par[icr - 1] = xds_1.dlim[ilc - 1];
    }
    if (par[icr - 1] > xds_1.dlim[ilc] - smal && *cdir > zero) {
	ifin = 1;
    }
    if (par[icr - 1] > xds_1.dlim[ilc] - smal && *cdir > zero) {
	par[icr - 1] = xds_1.dlim[ilc];
    }
/* ---NOW TEMPORARILY LOAD NEW LIMITS FOR SIDE STEPPING */
    if (*cdir < zero) {
	goto L230;
    }
    plim[ilc - 1] = psave[icr - 1];
    plim[ilc] = par[icr - 1];
    goto L240;

L230:
    plim[ilc - 1] = par[icr - 1];
    plim[ilc] = psave[icr - 1];
L240:

    tscalh = zero;
    tstepo = zero;
    tstepm = zero;
/* ---WHEN LIFTUP HAS NOT BEEN SPECIFIED, SKIP THE FIRST CUT VECTOR */
    tpthic = xstepo_1.sstep[2] + xps_1.pthick;
    miclsk = 1;
    if (xstepo_1.sstep[2] > smal) {
	miclsk = 0;
    }

    if (xfeed_1.fed[1] > smal) {
	fedput_(&xfeed_1.fed[1]);
    }
    clput_(te, ta, &c_n1);

    if (ibugg_1.ibug != 11) {
	goto L250;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c__1, &c__0, "STEP", &ipass, (ftnlen)4);
    bad_(&c__2, &c__1, "PSAV", psave, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", par, (ftnlen)4);
L250:
/* ---GENERATE THE SIDE MOTION TO THE NEXT POSITION */

    sspath_(&_BLNK__1.com[idriv - 1], &midtyp, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &tpthic, ptoli, ptolo, &xps_1.iptool, &tul[1], psave, &psave[1], 
	    &tscalh, &tstepo, &tstepm, amaxdp, elmax, maxcl, &miclsk, iqual, 
	    te, ta, td, par, irr);
    if (*irr != 0) {
	goto L999;
    }

/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }
/* ---IF THE THIRD FEED RATE IS AVAILABLE AND LIFTUP SPECIFIED */
/* ---THEN USE THE PLUNGE PROCEDURE */
    if (xstepo_1.sstep[2] < smal) {
	goto L260;
    }
    if (xfeed_1.fed[2] > smal) {
	fedput_(&xfeed_1.fed[2]);
    }
    mmaxcl = 1;
    miclsk = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L270: */
	plim[i__ - 1] = xds_1.dlim[i__ - 1];
    }
    clput_(te, ta, &c_n1);
/* ---DROP BACK TO THE SURFACE AT THE PLUNGE FEED RATE */

    *ust = par[0];
    *vst = par[1];
    sspath_(&_BLNK__1.com[idriv - 1], &midtyp, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &xps_1.pthick, ptoli, ptolo, &xps_1.iptool, &tul[1], ust, vst, &
	    tscalh, &tstepo, &tstepm, amaxdp, elmax, &mmaxcl, &miclsk, iqual, 
	    te, ta, td, par, irr);
    if (*irr != 0) {
	goto L999;
    }

/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }
L260:

/* --- NOW CONTINUE BY ZAGGING DOWN NEXT CUT PATH */
/* L300: */
    ++ipass;
/* ---      MOD(IBUG,100) IS THE PASS NUMBER WHEN IBUG SHOULD BE RESET */
    ibugt = ibugg_1.ibug % 100;
    if (ibugg_1.ibug / 100 == ipass) {
	ibugg_1.ibug = ibugt;
    }
    iclskp = 1;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L310: */
	plim[i__ - 1] = xds_1.dlim[i__ - 1];
    }
    dstep = one;
    scalht = xstepo_1.sstep[0];
    stepmx = xstepo_1.sstep[1];
    stepov = zero;

/* ---GENERATE FEED RATE FOR PATH MOTION */
    if (xfeed_1.fed[0] > smal) {
	fedput_(xfeed_1.fed);
    }
    goto L120;


L500:
/* ---PICKFD PATTERN MACHINING */
/* ---CUTTER ZIGS ALONG MAIN PATH COMPUTING SCALOP FOR NEXT PASS */
/* ---IT THEN RETRACTS AT RAPID TO THE CLEARANCE PLANE */
/* ---RETRACTS TO A POSITION OVER THE FIRST POINT */
/* ---AND PLUNGES TO THE FIRST PATH POINT AT A REDUCED FEEDRATE */
/* ---IT THEN STEPS OVER IN THE SAME MANNER AS THE ZIGZAG ROUTINE */
/* ---AND PROCEEDS IN THE SAME DIRECTION DOWN THE NEXT PATH */
    ipass = 1;
    ifin = 0;
    iclskp = 0;
    if (*iskp == 1) {
	iclskp = 1;
    }
    ipart = (integer) xps_1.pgeom[3];
    idriv = (integer) xds_1.dgeom[3];
    par[0] = *ust;
    par[1] = *vst;
    dstep = one;
    scalht = xstepo_1.sstep[0];
    stepmx = xstepo_1.sstep[1];
    stepov = zero;
/* ---GENERATE LIMITS BASED ON A SECTOR OF THE BOUNDED REGION */
    i__ = 1;
    if (*idtype == 2) {
	i__ = 2;
    }
    adir[i__ - 1] = *pdir;
    adir[3 - i__ - 1] = *cdir;
    for (i__ = 1; i__ <= 2; ++i__) {
	if (adir[i__ - 1] < zero) {
	    goto L720;
	}
	alim[(i__ << 1) - 2] = par[i__ - 1];
	alim[(i__ << 1) - 1] = xds_1.dlim[(i__ << 1) - 1];
	goto L750;
L720:
	alim[(i__ << 1) - 2] = xds_1.dlim[(i__ << 1) - 2];
	alim[(i__ << 1) - 1] = par[i__ - 1];
L750:
	;
    }
    if (ibugg_1.ibug == 11) {
	bad_(&c_n4, &c__1, "ALIM", alim, (ftnlen)4);
    }
    if (ibugg_1.ibug == 11) {
	bad_(&c_n2, &c__1, "ADIR", adir, (ftnlen)4);
    }

L520:
/* ---COMMON ENTRY POINT FOR CONSECUTIVE PASSES IN MAIN DIRECTION. */
    if (ibugg_1.ibug != 11) {
	goto L505;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c__1, &c__0, "PASS", &ipass, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", par, (ftnlen)4);
L505:

    for (i__ = 1; i__ <= 4; ++i__) {
/* L510: */
	plim[i__ - 1] = alim[i__ - 1];
    }
    tpdir = *pdir;
    *irr = 0;
    clput_(te, ta, &c_n1);

/* ---FIRST DO A STARTUP TO SAVE THE FIRST PATH POINT */
    miclsk = -1;
    mmaxcl = 1;

    sspath_(&_BLNK__1.com[idriv - 1], idtype, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &xps_1.pthick, ptoli, ptolo, &xps_1.iptool, &tul[1], par, &par[1]
	    , &scalht, &stepov, &stepmx, amaxdp, elmax, &mmaxcl, &miclsk, 
	    iqual, svte, svta, svtd, par, irr);
    if (*irr != 0) {
	goto L999;
    }
/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }

/* ---NOW PROCEED DOWN PATH IN NORMAL FASHION */
    iclskp = 0;
    if (ipass == 1 && *iskp > 0) {
	iclskp = 1;
    }

    *ust = par[0];
    *vst = par[1];
    sspath_(&_BLNK__1.com[idriv - 1], idtype, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &xps_1.pthick, ptoli, ptolo, &xps_1.iptool, &tul[1], ust, vst, &
	    scalht, &stepov, &stepmx, amaxdp, elmax, maxcl, &iclskp, iqual, 
	    te, ta, td, par, irr);

    if (*irr != 0) {
	goto L999;
    }
/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }
/* ---TERMINATE PROCESS WHEN IFIN IS NOT ZERO. */
    if (ifin == 1) {
	goto L999;
    }
/* ---RESTORE THE PARAMETERS TO THEIR INITIAL VALUES */
    par[0] = *ust;
    par[1] = *vst;
/* ---NOW RETRACT TO CLEARANCE PLANE AT RAPID */
    if (xfeed_1.fed[3] > smal) {
	fedput_(&xfeed_1.fed[3]);
    }

    clput_(te, ta, &c_n1);
    clift_(te, xfeed_1.clrpln, te);
    clput_(te, ta, &c__0);
/* ---POSITION OVER BEGINNING CL POINT OF THIS PATH */
    clift_(svte, xfeed_1.clrpln, te);
    clput_(te, svta, &c__1);
/* ---NOW ACTIVATE THE PLUNGE FEED RATE */
    if (xfeed_1.fed[2] > smal) {
	fedput_(&xfeed_1.fed[2]);
    }
    clput_(te, ta, &c_n1);
    clput_(svte, svta, &c__1);
/* ---NOW MAKE SIDE STEP MOVE FOR NEXT TOOL PASS */
    tpdir = *cdir;
    midtyp = 3 - *idtype;
    icr = 2;
    if (*idtype == 2) {
	icr = 1;
    }
    ilc = (icr << 1) - 1;
    for (i__ = 1; i__ <= 2; ++i__) {
/* L610: */
	psave[i__ - 1] = par[i__ - 1];
    }
    pchg_(&par[icr - 1], cdir, &stepov);
    par[icr - 1] += *cdir * stepov;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L620: */
	plim[i__ - 1] = alim[i__ - 1];
    }
    if (par[icr - 1] < alim[ilc - 1] + smal && *cdir < zero) {
	ifin = 1;
    }
    if (par[icr - 1] < alim[ilc - 1] + smal && *cdir < zero) {
	par[icr - 1] = alim[ilc - 1];
    }
    if (par[icr - 1] > alim[ilc] - smal && *cdir > zero) {
	ifin = 1;
    }
    if (par[icr - 1] > alim[ilc] - smal && *cdir > zero) {
	par[icr - 1] = alim[ilc];
    }
/* ---NOW TEMPORARILY LOAD NEW LIMITS FOR SIDE STEPPING */
    if (*cdir < zero) {
	goto L630;
    }
    plim[ilc - 1] = psave[icr - 1];
    plim[ilc] = par[icr - 1];
    goto L640;

L630:
    plim[ilc - 1] = par[icr - 1];
    plim[ilc] = psave[icr - 1];
L640:

    tscalh = zero;
    tstepo = zero;
    tstepm = zero;
    tpthic = xstepo_1.sstep[2] + xps_1.pthick;
    miclsk = 1;
    if (xstepo_1.sstep[2] > smal) {
	miclsk = 0;
    }

    if (xfeed_1.fed[1] > smal) {
	fedput_(&xfeed_1.fed[1]);
    }
    clput_(te, ta, &c_n1);

    if (ibugg_1.ibug != 11) {
	goto L650;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c__1, &c__0, "STEP", &ipass, (ftnlen)4);
    bad_(&c__2, &c__1, "PSAV", psave, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", par, (ftnlen)4);
L650:

    sspath_(&_BLNK__1.com[idriv - 1], &midtyp, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &tpthic, ptoli, ptolo, &xps_1.iptool, &tul[1], psave, &psave[1], 
	    &tscalh, &tstepo, &tstepm, amaxdp, elmax, maxcl, &miclsk, iqual, 
	    te, ta, td, par, irr);
    if (*irr != 0) {
	goto L999;
    }
/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }

/* ---IF THE THIRD FEED RATE IS AVAILABLE AND LIFTUP SPECIFIED */
/* ---THEN USE THE PLUNGE PROCEDURE */
    if (xstepo_1.sstep[2] < smal) {
	goto L660;
    }
    if (xfeed_1.fed[2] > smal) {
	fedput_(&xfeed_1.fed[2]);
    }
    mmaxcl = 1;
    miclsk = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L670: */
	plim[i__ - 1] = alim[i__ - 1];
    }
    clput_(te, ta, &c_n1);

    *ust = par[0];
    *vst = par[1];
    sspath_(&_BLNK__1.com[idriv - 1], &midtyp, &tpdir, dtol, &dstep, &
	    xds_1.dofset, plim, &xds_1.idtool, &xaxis_1.iaxis, xaxis_1.axis, &
	    xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1], &xps_1.pside,
	     &xps_1.pthick, ptoli, ptolo, &xps_1.iptool, &tul[1], ust, vst, &
	    tscalh, &tstepo, &tstepm, amaxdp, elmax, &mmaxcl, &miclsk, iqual, 
	    te, ta, td, par, irr);
    if (*irr != 0) {
	goto L999;
    }

/* ---      INCREMENT COUNT OF CALLS TO SSPATH, QUIT WHEN OVER LIMIT */
    ++ipathk;
    if (ipathk >= mxpath) {
	goto L999;
    }
L660:

/* ---NOW RESET PARAMETERS FOR MOVING DOWN NEXT CUT PATH */
/* L700: */
    ++ipass;
/* ---      MOD(IBUG,100) IS THE PASS NUMBER WHEN IBUG SHOULD BE RESET */
    ibugt = ibugg_1.ibug % 100;
    if (ibugg_1.ibug / 100 == ipass) {
	ibugg_1.ibug = ibugt;
    }
    iclskp = 1;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L710: */
	plim[i__ - 1] = alim[i__ - 1];
    }
    dstep = one;
    scalht = xstepo_1.sstep[0];
    stepmx = xstepo_1.sstep[1];
    stepov = zero;

    if (xfeed_1.fed[0] > smal) {
	fedput_(xfeed_1.fed);
    }
    goto L520;

L999:
    return 0;
} /* cutreg_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


