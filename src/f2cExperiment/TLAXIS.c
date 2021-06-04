/* TLAXIS.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer iamdct, ipdpl, ipt, iws, jckr, jcnt1, jcnt2, jcnt3, jcpr, jcr, 
	    jdr, jfind, jgr, jmin, jminr, jpr, jpxr, jtkf, jtr, j10, j12, j13,
	     j54, mdic;
} ishr18_;

#define ishr18_1 ishr18_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
} glflgs_;

#define glflgs_1 glflgs_

struct {
    integer iaerfg;
} aercom_;

#define aercom_1 aercom_

struct {
    integer iplgo[26], jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10], vta[3];
} plgol_;

#define plgol_1 plgol_

/* Table of constant values */

static integer c_b2 = -22300;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__22301 = 22301;
static integer c__22219 = 22219;
static integer c__1 = 1;
static integer c__6 = 6;

/* *** SOURCE FILE : M0002872.W01   *** */

/* .....FORTRAN SUBROUTINE  ....TLAXIS         8/68                    PH */

/* Subroutine */ int tlaxis_(integer *number, integer *nprd, doublereal *
	param)
{
    /* Initialized data */

    static char ds[6] = "DS    ";
    static char hlag[6] = "LAG   ";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, ii, ip2, nwd;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static doublereal sera;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static char test[6];
    static integer iprd;
    static doublereal sehi;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static integer iautag;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), transm_(doublereal *, doublereal *,
	     integer *, integer *, integer *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...   COMMON BLOCK FOR AERR INFORMATION */


/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */


/* ...  COMMON FOR >PLOTFT/GOLOFT< */



    /* Parameter adjustments */
    --param;

    /* Function Body */

/* ...     IF MULTAX HAS NOT BEEN SPECIFIED ISSUE WARNING DIAGNOSTIC */
    if (ifxcor_1.mulout != 1) {
	aerr_(&c_b2, "TLAXIS  ", (ftnlen)8);
    }

    isv_1.jtlflg[ifxcor_1.ips - 1] = 0;
    isv_1.jtlflg[ifxcor_1.ids - 1] = 0;
    iprd = *nprd / 100;
    *nprd -= iprd * 100;
    iautag = 0;
    glflgs_1.motdir = 0;
    if (*nprd != 9) {
	glflgs_1.ringfg = FALSE_;
    }
    ip2 = 2;
L1:
    if (*nprd < 5) {
	--ip2;
    }
/*            1   2   3   4  5  6  7  8  9 10 11  12  13  14  15 */
    switch (*nprd) {
	case 1:  goto L201;
	case 2:  goto L202;
	case 3:  goto L203;
	case 4:  goto L204;
	case 5:  goto L72;
	case 6:  goto L15;
	case 7:  goto L50;
	case 8:  goto L20;
	case 9:  goto L10;
	case 10:  goto L75;
	case 11:  goto L30;
	case 12:  goto L212;
	case 13:  goto L213;
	case 14:  goto L214;
	case 15:  goto L215;
	case 16:  goto L216;
	case 17:  goto L217;
	case 18:  goto L218;
	case 19:  goto L218;
	case 20:  goto L220;
	case 21:  goto L220;
	case 22:  goto L222;
    }
/*           16  17  18  19  20  21  22 */

/*     **TLAXIS/1** */

L10:
    if (param[1] != znumbr_1.z1) {
	goto L150;
    }
    ifxcor_1.mantax = knumbr_1.k1;
    goto L140;

/*     **TLAXIS/NORMPS** */

L15:
    ifxcor_1.mantax = knumbr_1.k2;
    fxcor_1.gamma = (doublereal) knumbr_1.k0;
    goto L28;

/*     **TLAXIS/NORMDS** */

L20:
    ifxcor_1.mantax = knumbr_1.k3;
    fxcor_1.gamma = znumbr_1.pi;
/*     **SET VALUES FOR NUMAX,RA & HI FOR TLAXIS/NORMPS & TLAXIS/NORMDS** */
L28:
    ifxcor_1.numax = knumbr_1.k1;
    fxcor_1.alp = znumbr_1.z0;
    fxcor_1.ra = znumbr_1.z0;
    fxcor_1.hi = znumbr_1.z0;
    goto L110;

/*     **TLAXIS/PARLEL,1 OR TLAXIS/PARLEL,2 ** */

L30:
    if (param[2] <= znumbr_1.z0 || param[2] > znumbr_1.z2) {
	goto L150;
    }
    fxcor_1.gamma = znumbr_1.z0;
L31:
    ii = 7;
/*     **IF BETA IS GREATER THAN 0,SET RA&HI AT UPPER LINE SEGMENT** */
    if (fxcor_1.cutdat[5] > znumbr_1.z1em7) {
	goto L40;
    }
/*     **SET RA&HI AT INTERSECTION OF UPPER&LOWER LINE SEGMENTS** */
    ii = 6;
/*     **IF CORNER RADIUS IS GREATER THAN 0,RA=XH&HI=YH** */
    if (fxcor_1.cutdat[1] > znumbr_1.z0) {
	ii = 5;
    }
/*     **IF BETA IS NEGATIVE,SET RA&HI AT EXTREMITY OF CORNER CIRCLE** */
    if (fxcor_1.cutdat[5] < znumbr_1.z0) {
	goto L45;
    }
L40:
    fxcor_1.ra = tlldat_1.ri[ii - 1];
    fxcor_1.hi = tlldat_1.tlhite[ii - 1];
    goto L48;
L45:
    fxcor_1.ra = fxcor_1.cutdat[2] + fxcor_1.cutdat[1];
    fxcor_1.hi = fxcor_1.cutdat[3];
L48:
    ifxcor_1.mantax = knumbr_1.k3;
    if (param[2] == znumbr_1.z1) {
	ifxcor_1.mantax = knumbr_1.k2;
    }
    ifxcor_1.numax = ip2;
    if (*number == 9) {
	goto L96;
    }
    fxcor_1.alp = znumbr_1.z0;
    fxcor_1.ax4[0] = znumbr_1.z0;
    fxcor_1.ax4[1] = znumbr_1.z0;
    fxcor_1.ax4[2] = znumbr_1.z0;
    goto L110;

/*     **TLAXIS/V OR TLAXIS/I,J,K** */

L50:
    ifxcor_1.mantax = knumbr_1.k1;
    transm_(fxcor_1.ta, &param[1], &c__3, &c__3, &c__0);
    vnorm_(fxcor_1.ta, fxcor_1.ta);
    goto L140;

/*     **TLAXIS/A,B,RA,HI ** */
/*     **TLAXIS/PARLEL,1,RA,HI OR TLAXIS/PARLEL,2,RA,HI** */
/*     **TLAXIS/A,B,RA,HI,GAMMA,I,J,K** */
/*     **TLAXIS/A,B,RA,HI,GAMMA,I,J,K,ALPHA** */

L72:
    if (param[1] == znumbr_1.z0 || param[1] >= 4.f) {
	goto L150;
    }
    if (param[2] > (doublereal) knumbr_1.k4) {
	goto L150;
    }
    goto L80;
L75:
    if (param[2] >= znumbr_1.z3) {
	goto L150;
    }
L76:
    param[1] = param[2] + znumbr_1.z1;
/* ... */
L80:
    if (*number >= 9) {
	goto L95;
    }
    for (i__ = *number; i__ <= 8; ++i__) {
/* L90: */
	param[i__ + 1] = znumbr_1.z0;
    }
L95:
/* L100: */
    ifxcor_1.mantax = (integer) param[1];
    ifxcor_1.numax = ip2;
    fxcor_1.ra = param[3];
    fxcor_1.hi = param[4];
    fxcor_1.gamma = znumbr_1.degrad * param[5];
L96:
    fxcor_1.alp = -znumbr_1.degrad * param[9];
    fxcor_1.ax4[0] = param[6];
    fxcor_1.ax4[1] = param[7];
    fxcor_1.ax4[2] = param[8];
    glflgs_1.ringfg = TRUE_;
    if (sqrt(fxcor_1.ax4[0] * fxcor_1.ax4[0] + fxcor_1.ax4[1] * fxcor_1.ax4[1]
	     + fxcor_1.ax4[2] * fxcor_1.ax4[2]) > 1e-10) {
	vnorm_(fxcor_1.ax4, fxcor_1.ax4);
    }

/*     **EXIT ROUTES** */

L110:
    tlldat_1.tlhite[7] = fxcor_1.hi;
    tlldat_1.ri[7] = fxcor_1.ra;
    fxcor_1.sagl = sin(fxcor_1.gamma);
    fxcor_1.cagl = cos(fxcor_1.gamma);
    if ((i__1 = ifxcor_1.mantax - knumbr_1.k2) < 0) {
	goto L140;
    } else if (i__1 == 0) {
	goto L120;
    } else {
	goto L130;
    }
L120:
    isv_1.jtlflg[ifxcor_1.ips - 1] = knumbr_1.k1;
    goto L140;
L130:
    isv_1.jtlflg[ifxcor_1.ids - 1] = knumbr_1.k1;
L140:
    return 0;

/*     **ERROR-INVALID TLAXIS FORMAT** */

L150:
    aercom_1.iaerfg = 1;
    aerr_(&c__22301, "TLAXIS  ", (ftnlen)8);
    return 0;
/*       NO CUTTER DEFINED TO COMPUTE DISC RADIUS RA OR DISC HIGHT HI. */
L160:
    aercom_1.iaerfg = 1;
    aerr_(&c__22219, "TLAXIS  ", (ftnlen)8);
    return 0;

/*      NEW TLAXIS FORMATS INSTALLED AT 10.12.84 */

/* 201 **TLAXIS/ATANGL,PS,GAMMA,RADIUS,RA,HIGHT,HI** */
/* 212 **TLAXIS/PARLEL,DS,RADIUS,RA,HIGHT,HI** */

L201:
    param[5] = 180. - param[5];
L212:
    param[1] = znumbr_1.z1;
    holfrm_(&param[2], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, ds, (ftnlen)6, (ftnlen)6) == 0) {
	param[1] = znumbr_1.z2;
    }
    param[2] = param[1];
    goto L76;

/* 204 **TLAXIS/ATANGL,DS,GAMMA** */
/* 215 **TLAXIS/PARLEL,PS OR TLAXIS/PARLEL,DS ** */

L204:
    fxcor_1.gamma = (180. - param[5]) * znumbr_1.degrad;
L215:
    param[1] = znumbr_1.z1;
    holfrm_(&param[2], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, ds, (ftnlen)6, (ftnlen)6) == 0) {
	param[1] = znumbr_1.z2;
    }
    param[2] = param[1];
    goto L31;

/* 202 **TLAXIS/ATANGL,DS,GAMMA,RADIUS,RA** */
/* 213 **TLAXIS/PARLEL,PS,RADIUS,RA** */

L202:
    param[5] = 180. - param[5];
L213:
    param[4] = znumbr_1.z0;
    if (plgol_1.ncseg == 0) {
	goto L160;
    }
    i__1 = plgol_1.ncseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (plgol_1.nlioci[i__ - 1] == 1) {
	    goto L311;
	}
	if (plgol_1.cutl[i__ - 1] == 0.) {
	    goto L313;
	}
/*           COMPUTATION OF SEGMENT AND RADIUS ON CIRCLE */
	sera = plgol_1.cutx[i__ - 1] + plgol_1.cutl[i__ - 1] * plgol_1.sinal[
		i__ - 1];
	if (sera < param[3]) {
	    goto L313;
	}
/*           COMPUTATION OF HI */
/* Computing 2nd power */
	d__1 = param[3] - plgol_1.cutx[i__ - 1];
	param[4] = plgol_1.cuty[i__ - 1] - sqrt(plgol_1.cutl[i__ - 1] * 
		plgol_1.cutl[i__ - 1] - d__1 * d__1);
	goto L212;
/*           COMPUTATION OF SEGMENT AND RADIUS ON LINE */
L311:
	sera = plgol_1.cutx[i__ - 1] + plgol_1.cutl[i__ - 1] * plgol_1.cosal[
		i__ - 1];
	if (sera < param[3]) {
	    goto L313;
	}
/*           COMPUTATION OF HI */
	if ((d__1 = plgol_1.cosal[i__ - 1], abs(d__1)) < 1e-8) {
	    goto L312;
	}
	param[4] = plgol_1.cuty[i__ - 1] + (param[3] - plgol_1.cutx[i__ - 1]) 
		* plgol_1.sinal[i__ - 1] / plgol_1.cosal[i__ - 1];
	goto L212;
L312:
	param[4] = plgol_1.cuty[i__ - 1] + plgol_1.cutl[i__ - 1];
	goto L212;
L313:
	;
    }
    param[4] = plgol_1.cuty[plgol_1.ncseg - 1];
    goto L212;

/* 203 **TLAXIS/ATANGL,DS,GAMMA,HIGHT,HI** */
/* 214 **TLAXIS/PARLEL,PS,HIGHT,HI** */

L203:
    param[5] = 180. - param[5];
L214:
    param[3] = znumbr_1.z0;
    if (plgol_1.ncseg == 0) {
	goto L160;
    }
    i__1 = plgol_1.ncseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (plgol_1.nlioci[i__ - 1] == 1) {
	    goto L314;
	}
	if (plgol_1.cutl[i__ - 1] == 0.) {
	    goto L315;
	}
/*           COMPUTATION OF SEGMENT AND HEIGHT ON CIRCLE */
	sehi = plgol_1.cuty[i__ - 1] - plgol_1.cutl[i__ - 1] * plgol_1.cosal[
		i__ - 1];
	if (sehi < param[4]) {
	    goto L315;
	}
/*           COMPUTATION OF RA */
/* Computing 2nd power */
	d__1 = param[4] - plgol_1.cuty[i__ - 1];
	param[3] = sqrt(plgol_1.cutl[i__ - 1] * plgol_1.cutl[i__ - 1] - d__1 *
		 d__1) + plgol_1.cutx[i__ - 1];
	goto L212;
/*           COMPUTATION OF SEGMENT AND HEIGHT ON LINE */
L314:
	sehi = plgol_1.cuty[i__ - 1] + plgol_1.cutl[i__ - 1] * plgol_1.sinal[
		i__ - 1];
	if (sehi < param[4]) {
	    goto L315;
	}
/*           COMPUTATION OF RA */
	if ((d__1 = plgol_1.sinal[i__ - 1], abs(d__1)) < 1e-8) {
	    goto L316;
	}
	param[3] = plgol_1.cutx[i__ - 1] + (param[4] - plgol_1.cuty[i__ - 1]) 
		* plgol_1.cosal[i__ - 1] / plgol_1.sinal[i__ - 1];
	goto L212;
L316:
	param[3] = plgol_1.cutx[i__ - 1] + plgol_1.cutl[i__ - 1];
	goto L212;
L315:
	;
    }
    param[3] = plgol_1.cutx[plgol_1.ncseg - 1];
    goto L212;
/*                                     LAG */
/* 216 **TLAXIS/ATANGL,........,CUTANG,LEAD,ALPHA */
/* 217 **TLAXIS/ATANGL,........,CUTANG,ALPHA */

L216:
    holfrm_(&param[*number - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, hlag, (ftnlen)6, (ftnlen)6) == 0) {
	param[*number] = -param[*number];
    }
L217:
    param[9] = param[*number];
    for (i__ = 6; i__ <= 8; ++i__) {
/* L317: */
	param[i__] = znumbr_1.z0;
    }
    *number = 9;
    goto L331;
/*                                     LAG */
/* 218 **TLAXIS/ATANGL,........,CUTANG,LEAD,AUTO */
/* 219 **TLAXIS/ATANGL,........,CUTANG,AUTO */

L218:
    iautag = 1;
    holfrm_(&param[*number - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, hlag, (ftnlen)6, (ftnlen)6) == 0) {
	iautag = -1;
    }
    goto L330;
/*                                     LINE */
/* 220 **TLAXIS/ATANGL,........,PARLEL,PLANE */
/* 221 **TLAXIS/ATANGL,........,PERPTO,VECTOR */

L220:
    *number = 9;
    param[9] = znumbr_1.z0;
    --ip2;
    goto L331;

/* 222 **TLAXIS/ATANGL,........,MOTDIR */

L222:
    glflgs_1.motdir = 1;
    --ip2;

L330:
    *number = 5;
L331:
    *nprd = iprd;
    goto L1;

} /* tlaxis_ */

#undef sinl
#undef cosl


