/* SCON.f -- translated by f2c (version 20100827).
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
    doublereal alpha, beta, cosa, cosb, sina, sinb;
    integer itac;
} tac_;

#define tac_1 tac_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__0 = 0;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0002902.W03   *** */

/* Subroutine */ int scon_(void)
{
    /* Initialized data */

    static doublereal acrssp = 137.;
    static doublereal ads = 1.;
    static char wds[6] = "DS    ";
    static doublereal afeed = 163.;
    static doublereal ainit = 161.;
    static doublereal aminus = 41.;
    static doublereal anorma = 13.;
    static doublereal anormd = 151.;
    static char won[6] = "ON    ";
    static doublereal aparam = 144.;
    static doublereal aplane = 2.;
    static doublereal aall = 50.;
    static doublereal aplus = 42.;
    static char wps[6] = "PS    ";
    static doublereal ascala = 21.;
    static doublereal ascurv = 30.;
    static doublereal assurf = 29.;
    static doublereal astepo = 162.;
    static doublereal aat = 66.;
    static char wto[6] = "TO    ";
    static doublereal avecto = 20.;
    static doublereal aatang = 10.;
    static doublereal acutan = 71.;
    static doublereal alead = 74.;
    static doublereal alag = 75.;
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-38;
    static integer ibegin = 42;
    static integer nogood = -121;
    static integer nlast = 0;
    static integer nbig = 50;
    static doublereal aaxis = 146.;
    static integer iok = 121;
    static integer irbase = 3520;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, irr, isq, now;
    static doublereal vsq;
    static integer iall, iflg, icur, nlen;
    static doublereal word;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer jcur;
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static char ctest[6];
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int record_(integer *), holfrm_(doublereal *, 
	    char *, integer *, integer *, integer *, ftnlen);

/* ---PURPOSE IS TO PICK UP THE DATA STREAM FROM AN SCON/ COMMAND */
/* --- AND DEVELOP THE RELATED DATA INTO LABELLED COMMON. */
/* --- THE TRANSLATED DATA IS AVAILABLE IN BLANK COMMON STARTING */
/* ---AT LOCATION ISTART(=42) .  THE FIRST VALUE IS A FLOATING */
/* ---WORD WHICH GIVES THE NUMBER OF PERTINENT DATA ITEMS WHICH */
/* ---FOLLOW.  EACH APT WORD OR VARIABLE IS PRECEEDED BY ITS */
/* ---WORD WORD IDENTIFICATION */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */








/*     ALPHA  TOOL AXIS SLEW ANGLE WRT SN */
/*            IN GUIDE SURFACE CRSSPL DIRN. IF PATH IN TANSPL DIRN. */
/*            AND VICE VERSA */
/*     BETA   TOOL AXIS TILT ANGLE (CUTANG) WRT SN */
/*            IN PATH DIRECTION */
/*     COSA   COS(ALPHA) */
/*     COSB   COS(BETA) */
/*     SINA   SIN(ALPHA) */
/*     SINB   SIN(BETA) */
/*     ITAC   FLAG INDICATING THAT ATANGL TYPE TOOL AXIS CONTROL */
/*            IS REQUIRED =1, =0 FOR FIXED OR NORMDS */



/* --WORD MODE VALUES IN REAL FORM AND HOLLERITH FORM. */
/* --THESE ARE WORDS USED IN SMIL AND SCON COMMANDS */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */





    if (xfeed_1.nclrpl != iok) {
	xfeed_1.nclrpl = nogood;
    }
    icur = ibegin;
    nlen = (integer) _BLNK__1.com[icur - 1];
    nlast = ibegin + nlen - 2;
    _BLNK__1.com[nlast - 1] = zero;
    ++icur;
/* ****    INPUT FIELD MUST BE OF REASONABLE LENGTH */
    if (nlen < 3 || nlen > nbig) {
	goto L995;
    }

/* L10: */
    if (icur >= nlast) {
	goto L998;
    }

    word = _BLNK__1.com[icur - 1];
    if (word == ainit) {
	goto L100;
    }
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) == 0) {
	goto L200;
    }
    if (s_cmp(ctest, wps, (ftnlen)6, (ftnlen)6) == 0) {
	goto L300;
    }
    if (word == afeed) {
	goto L400;
    }
    if (word == astepo) {
	goto L500;
    }
    if (word == aaxis) {
	goto L600;
    }
/* ****    ERROR, WORD COMMAND WORD NOT RECOGNIZED */
    goto L998;

/* ---INIT COMMAND, FOR INTIALIZING DATA AREAS */
L100:
    icur += 2;
    word = _BLNK__1.com[icur - 1];
    if (word == ads) {
	word = _BLNK__1.com[icur];
    }
    iall = 0;
    if (word == aall) {
	iall = 1;
    }

L110:
    holfrm_(&word, ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) == 0 || iall == 1) {
	goto L120;
    }
    if (s_cmp(ctest, wps, (ftnlen)6, (ftnlen)6) == 0 || iall == 2) {
	goto L130;
    }
    if (word == afeed || iall == 3) {
	goto L140;
    }
    if (word == astepo || iall == 4) {
	goto L150;
    }
    if (word == aaxis || iall == 5) {
	goto L160;
    }
    goto L998;
L120:
    xds_1.nds = nogood;
    goto L190;
L130:
    xps_1.nps = nogood;
    goto L190;
L140:
    xfeed_1.nfeed = nogood;
    goto L190;
L150:
    xstepo_1.nstepo = nogood;
    goto L190;
L160:
    xaxis_1.naxis = nogood;
    goto L190;

L190:
    if (iall != 0) {
	++iall;
    }
    if (iall == 0) {
	icur += 2;
    }
    word = _BLNK__1.com[icur - 1];
    if (iall < 5 && icur < nlast) {
	goto L110;
    }
    if (iall > 0) {
	icur += 2;
    }
    if (icur != nlast) {
	goto L995;
    }
/* ---PROCESSING FINISHED FOR INIT COMMAND */
    goto L999;

/* ---ENTRY POINT FOR DRIVE GEOMETRY INPUT */
L200:
    xds_1.nds = nogood;
/* ---CHECK FOR NUMBER OF INPUT SCALARS TO DISTINGUISH CURV AND SURF */
    icur += 2;
    if (_BLNK__1.com[icur - 1] == ascurv) {
	goto L220;
    }
    if (_BLNK__1.com[icur - 1] == assurf) {
	goto L260;
    }
    goto L998;

/* ---CURVE DRIVE GEOMETRY */
/* -- SCON/DS,CURV,PARAM,UST,UEND,AT OR ON,CRSSPL OR VECTOR */
L220:
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xds_1.dgeom[0] = _BLNK__1.com[icur];
    xds_1.dgeom[1] = _BLNK__1.com[icur + 1];
    xds_1.dgeom[3] = zero;
    xds_1.dgeom[2] = ascurv;
    icur += 3;
    if (_BLNK__1.com[icur - 1] != aparam) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala || _BLNK__1.com[icur + 1] != ascala) 
	    {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    if (ckdef_(&_BLNK__1.com[icur + 2])) {
	goto L997;
    }
    if (_BLNK__1.com[icur] > _BLNK__1.com[icur + 2]) {
	goto L996;
    }
    xds_1.dlim[0] = _BLNK__1.com[icur];
    xds_1.dlim[1] = _BLNK__1.com[icur + 2];
    xds_1.dlim[2] = zero;
    xds_1.dlim[3] = one;
    icur += 4;
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (_BLNK__1.com[icur - 1] != aat && s_cmp(ctest, won, (ftnlen)6, (ftnlen)
	    6) != 0) {
	goto L998;
    }
    xds_1.idtool = 0;
    if (_BLNK__1.com[icur - 1] == aat) {
	xds_1.idtool = 1;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != avecto && _BLNK__1.com[icur - 1] != acrssp) 
	    {
	goto L998;
    }
    if (_BLNK__1.com[icur - 1] == avecto) {
	goto L230;
    }
    xds_1.itldir = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L240: */
	xds_1.tldir[i__ - 1] = zero;
    }
    icur += 2;
    goto L290;
L230:
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    dotf_(&vsq, &_BLNK__1.com[icur], &_BLNK__1.com[icur]);
    if (vsq < smal) {
	goto L998;
    }
    vsq = sqrt(vsq);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L250: */
	xds_1.tldir[i__ - 1] = _BLNK__1.com[icur + i__ - 1] / vsq;
    }
    xds_1.itldir = 0;
    icur += 4;
    goto L290;

/* --- SCON/DS,SURF,PARAM,ULO,UHI,VLO,VHI,AT OR ON, NORMAL OR VECTOR */
L260:
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xds_1.dgeom[0] = _BLNK__1.com[icur];
    xds_1.dgeom[1] = _BLNK__1.com[icur + 1];
    xds_1.dgeom[2] = assurf;
    xds_1.dgeom[3] = zero;
    icur += 3;
    if (_BLNK__1.com[icur - 1] != aparam) {
	goto L998;
    }
    icur += 2;
    for (i__ = 1; i__ <= 4; ++i__) {
	jcur = icur + (i__ << 1) - 2;
	if (_BLNK__1.com[jcur - 1] != ascala) {
	    goto L998;
	}
	if (ckdef_(&_BLNK__1.com[jcur])) {
	    goto L997;
	}
	xds_1.dlim[i__ - 1] = _BLNK__1.com[jcur];
/* L265: */
    }
    if (xds_1.dlim[0] > xds_1.dlim[1] || xds_1.dlim[2] > xds_1.dlim[3]) {
	goto L996;
    }
    icur += 8;

    xds_1.idtool = -1;
    if (_BLNK__1.com[icur - 1] == aat) {
	xds_1.idtool = 1;
    }
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, won, (ftnlen)6, (ftnlen)6) == 0) {
	xds_1.idtool = 0;
    }
    if (xds_1.idtool < 0) {
	goto L998;
    }

    icur += 2;
    if (_BLNK__1.com[icur - 1] == anorma) {
	goto L280;
    }
    if (_BLNK__1.com[icur - 1] != avecto) {
	goto L998;
    }
/* -- VECTOR */
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xds_1.itldir = 0;
    dotf_(&vsq, &_BLNK__1.com[icur], &_BLNK__1.com[icur]);
    if (vsq < smal) {
	goto L996;
    }
    vsq = sqrt(vsq);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L270: */
	xds_1.tldir[i__ - 1] = _BLNK__1.com[icur + i__ - 1] / vsq;
    }
    icur += 4;
    goto L290;

L280:
    icur += 2;
/* --NORMAL CASE */
    xds_1.itldir = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L285: */
	xds_1.tldir[i__ - 1] = zero;
    }
    goto L290;

L290:
/* ---      OPTIONAL DRIVE POINT OFFSET INSERTED HERE */
    xds_1.dofset = zero;
    if (icur == nlast) {
	goto L295;
    }
/* ---      LOOK FOR A SCALAR */
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xds_1.dofset = _BLNK__1.com[icur];
    icur += 2;
    if (icur != nlast) {
	goto L995;
    }
L295:
    xds_1.nds = iok;
    goto L999;

L300:
    xps_1.nps = nogood;
/* ---PART SURFACE SCON/PS,TO OR ON, SURF, PLUS OR MINUS, THICK */
    icur += 2;
    xps_1.iptool = -1;
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, won, (ftnlen)6, (ftnlen)6) == 0) {
	xps_1.iptool = 1;
    }
    if (s_cmp(ctest, wto, (ftnlen)6, (ftnlen)6) == 0) {
	xps_1.iptool = 0;
    }
    if (xps_1.iptool < 0) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != assurf) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xps_1.pgeom[0] = _BLNK__1.com[icur];
    xps_1.pgeom[1] = _BLNK__1.com[icur + 1];
    xps_1.pgeom[2] = assurf;
    xps_1.pgeom[3] = zero;
    icur += 3;
    xps_1.pside = zero;
    if (_BLNK__1.com[icur - 1] == aplus) {
	xps_1.pside = one;
    }
    if (_BLNK__1.com[icur - 1] == aminus) {
	xps_1.pside = -one;
    }
    if (xps_1.pside == zero) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    xps_1.pthick = _BLNK__1.com[icur];
    icur += 2;
    goto L390;

L390:
    if (icur != nlast) {
	goto L995;
    }
    xps_1.nps = iok;
    goto L999;

L400:
/* --- FEED RATE PROCESSING */
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aplane) {
	goto L430;
    }
/* ---SPECIAL ROUTE FOR PROCESSING PICKFD CLEARANCE PLANE */
    xfeed_1.nclrpl = nogood;
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L410: */
	xfeed_1.clrpln[i__ - 1] = _BLNK__1.com[icur + i__ - 1];
    }
    icur += 5;
    if (icur != nlast) {
	goto L995;
    }
    xfeed_1.nclrpl = iok;
    goto L999;

L430:
    xfeed_1.nfeed = nogood;
    for (i__ = 1; i__ <= 4; ++i__) {
	now = icur + (i__ << 1) - 2;
	if (_BLNK__1.com[now - 1] != ascala) {
	    goto L998;
	}
	if (ckdef_(&_BLNK__1.com[now])) {
	    goto L997;
	}
	xfeed_1.fed[i__ - 1] = _BLNK__1.com[now];
/* L420: */
    }
    icur += 8;
    goto L490;

L490:
    if (icur != nlast) {
	goto L995;
    }
    xfeed_1.nfeed = iok;
    goto L999;

L500:
    xstepo_1.nstepo = nogood;
/* ---STEPOVER PROCESSING */
    icur += 2;
    for (i__ = 1; i__ <= 4; ++i__) {
	now = icur + (i__ << 1) - 2;
	if (_BLNK__1.com[now - 1] != ascala) {
	    goto L998;
	}
	if (ckdef_(&_BLNK__1.com[now])) {
	    goto L997;
	}
	xstepo_1.sstep[i__ - 1] = _BLNK__1.com[now];
/* L510: */
    }
    icur += 8;
    goto L590;

L590:
    if (icur != nlast) {
	goto L995;
    }
    xstepo_1.nstepo = iok;
    goto L999;

L600:
/* ---AXIS PROCESSING FOLLOWS */
    xaxis_1.naxis = nogood;
    icur += 2;
    if (_BLNK__1.com[icur - 1] == anormd) {
	goto L650;
    }
    if (_BLNK__1.com[icur - 1] == avecto) {
	goto L610;
    }
    if (_BLNK__1.com[icur - 1] == aatang) {
	goto L680;
    }
    goto L998;
L610:
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    dotf_(&vsq, &_BLNK__1.com[icur], &_BLNK__1.com[icur]);
    if (vsq < smal) {
	goto L996;
    }
    vsq = sqrt(vsq);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L620: */
	xaxis_1.axis[i__ - 1] = _BLNK__1.com[icur + i__ - 1] / vsq;
    }
    xaxis_1.iaxis = 0;
    tac_1.itac = 0;
    icur += 4;
    if (_BLNK__1.com[icur - 1] != aplus && _BLNK__1.com[icur - 1] != aminus) {
	goto L690;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 3] != aminus) {
	goto L690;
    }
/* ---REVERSE THE VECTOR DIRECTION. */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L670: */
	xaxis_1.axis[i__ - 1] = -xaxis_1.axis[i__ - 1];
    }
    goto L690;

L650:
    icur += 2;
    xaxis_1.iaxis = 1;
    tac_1.itac = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L660: */
	xaxis_1.axis[i__ - 1] = zero;
    }
    if (_BLNK__1.com[icur - 1] != aplus && _BLNK__1.com[icur - 1] != aminus) {
	goto L690;
    }
    if (_BLNK__1.com[icur - 1] == aminus) {
	xaxis_1.iaxis = -1;
    }
    icur += 2;
    goto L690;
/*                 PS */
/* .... AXIS,ATANGL,DS,ALPHA,CUTANG,BETA */
L680:
    icur += 2;
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) == 0) {
	xaxis_1.iaxis = 2;
	tac_1.itac = 1;
	for (i__ = 1; i__ <= 3; ++i__) {
	    xaxis_1.axis[i__ - 1] = zero;
/* L682: */
	}
    } else if (s_cmp(ctest, wps, (ftnlen)6, (ftnlen)6) == 0) {
	xaxis_1.iaxis = 0;
	tac_1.itac = 2;
	xaxis_1.axis[0] = zero;
	xaxis_1.axis[1] = zero;
	xaxis_1.axis[2] = one;
    } else {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] == ascala) {
	if (ckdef_(&_BLNK__1.com[icur])) {
	    goto L997;
	} else {
	    tac_1.alpha = _BLNK__1.com[icur] * znumbr_1.degrad;
	    tac_1.cosa = cos(tac_1.alpha);
	    tac_1.sina = sin(tac_1.alpha);
	    if (tac_1.cosa < 0.) {
		xaxis_1.iaxis = -xaxis_1.iaxis;
	    }
	}
    } else {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] == acutan) {
	icur += 2;
	if (_BLNK__1.com[icur - 1] == alead) {
	    iflg = 1;
	    icur += 2;
	} else if (_BLNK__1.com[icur - 1] == alag) {
	    iflg = -1;
	    icur += 2;
	} else {
	    iflg = 1;
	}
	if (_BLNK__1.com[icur - 1] == ascala) {
	    if (ckdef_(&_BLNK__1.com[icur])) {
		goto L997;
	    } else {
		tac_1.beta = _BLNK__1.com[icur] * znumbr_1.degrad * (real) 
			iflg;
		tac_1.cosb = cos(tac_1.beta);
		tac_1.sinb = sin(tac_1.beta);
		icur += 2;
	    }
	} else {
	    goto L998;
	}
    } else {
	goto L998;
    }

L690:
    if (icur != nlast) {
	goto L995;
    }
    xaxis_1.naxis = iok;
    goto L999;

L995:
/* ---ERROR, INPUT DATA FIELD OF INCORRECT LENGTH */
    irr = 4;
    goto L990;

L996:
/* ---ERROR, INPUT PARAMETER VALUES ARE NOT LEGAL */
    irr = 3;
    goto L990;
L997:
/* ---ERROR, INPUT CANON FORM IS UNDEFINED */
    irr = 2;
    goto L990;
L998:
/* ---ERROR, ILLEGAL ARGUMENT IN INPUT STREAM */
    irr = 1;
    goto L990;

L990:
    irr = irbase + irr;
    error_(&irr, "SCON    ", (ftnlen)8);
    record_(&isq);
    bad_(&c__1, &c__0, "ISEQ", &isq, (ftnlen)4);
    bad_(&c__1, &c__0, "NLST", &nlast, (ftnlen)4);
    bad_(&c__1, &c__0, "NLEN", &nlen, (ftnlen)4);
    bad_(&c__1, &c__0, "IRR ", &irr, (ftnlen)4);
    bad_(&c__1, &c__0, "ICUR", &icur, (ftnlen)4);
    bad_(&c_n1, &c__0, "IRBS", &irbase, (ftnlen)4);

    goto L999;

L999:
    return 0;
} /* scon_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


