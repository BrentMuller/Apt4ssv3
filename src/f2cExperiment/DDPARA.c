/* DDPARA.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__27004 = 27004;
static integer c__27005 = 27005;

/* *** SOURCE FILE : M0002828.V04   *** */



/* Subroutine */ int ddpara_(doublereal *u, doublereal *v)
{
    /* Initialized data */

    static integer ifstt[4] = { 0,0,0,0 };

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_5[25];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer l;
    static doublereal p[3], t1[3], t2[3];
#define uu (equiv_5 + 18)
#define vv (equiv_5 + 19)
    static doublereal us[25], vs[25];
    static integer ip, ll;
    static doublereal tu, tv, px;
    static integer is2;
    static doublereal py, sa;
#define dif (equiv_5 + 10)
    static doublereal ang, den;
    static integer lct;
    static doublereal dot;
    static integer mode;
    static doublereal sdif[3];
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static doublereal ddum;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define disp (equiv_5 + 12)
    static doublereal deru[12]	/* was [3][4] */, derv[12]	/* was [3][4] 
	    */, spll[3], pdum[3], z1em4;
    extern /* Subroutine */ int lcls_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, integer *);
    static doublereal zang, xang;
#define temp1 (equiv_5)
    static doublereal pdum1[3];
    extern logical ckdef_(doublereal *);
    static integer ifail, mmode;
    static doublereal dtemp;
    static integer inorm;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), cross_(
	    doublereal *, doublereal *, doublereal *);
    static doublereal pcurv;
    static integer jentl, idebug;
    extern /* Subroutine */ int parlnd_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *);




/* ...  ALL REFERENCES TO TEMP HAVE BEEN CHANGED TO TEMP1, AS */
/* ...  TEMP OCCURS IN FXCOR.INC */

/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/*  --------------------------------------------------------------~ */

    z1em4 = 3e-5f;
    idebug = 0;
    *uu = *u;
    *vv = *v;
    is2 = ifxcor_1.is + 2;
    ip = ifxcor_1.is / 80;
    if (isv_1.jent[ifxcor_1.is - 1] == 0) {
	ifstt[ip - 1] = 0;
    }
    if (isv_1.jent[ifxcor_1.is - 1] == 1 && ifstt[ip - 1] == 0) {
	goto L4040;
    }
    mmode = 2;
L4039:
    mode = 2;
    goto L4090;
L4040:
    mmode = 1;
    if (ckdef_(u)) {
	aerr_(&c__27004, "DDPARA  ", (ftnlen)8);
    }
    if (ckdef_(v)) {
	aerr_(&c__27005, "DDPARA  ", (ftnlen)8);
    }
    ifstt[ip - 1] = 1;
    if (ifxcor_1.istrup == 1 && isv_1.indir__[ifxcor_1.is - 1] == 1) {
	goto L4039;
    }
/* ------MODE=1 MEANS AN SNXP COMPUTATION IS BEING REQUESTED */
/* ------ COMPUTE THE CLOSEST POINT ON THE TANGENT PLANE TO THE TOOL POINT */
    mode = 1;
L4090:
    fxcor_1.tem[0] = sv_1.sn[ifxcor_1.is * 3 - 3];
    fxcor_1.tem[1] = sv_1.sn[ifxcor_1.is * 3 - 2];
    fxcor_1.tem[2] = sv_1.sn[ifxcor_1.is * 3 - 1];
    fxcor_1.tem[3] = sv_1.sp[ifxcor_1.is * 3 - 3];
    fxcor_1.tem[4] = sv_1.sp[ifxcor_1.is * 3 - 2];
    fxcor_1.tem[5] = sv_1.sp[ifxcor_1.is * 3 - 1];
/* ------THE FOLLOWING LOOP ATTEMPTS BY AN ITERATIVE TECHNIQUE, TO */
/* ------FIND THE SURFACE POINT SP AND SURFACE NORMAL SN WHERE THE */
/* ------TOOL RAY TP,TN INTERSECTS THE SURFACE */
    lct = 0;
L10:
    lcls_(uu, vv, &sv_1.sp[ifxcor_1.is * 3 - 3], &deru[ip * 3 - 3], &derv[ip *
	     3 - 3], &mmode);
/* ------THE ABOVE CALL INITIATES A LINKAGE OF A PROGRAMMER SUPPLIED */
/* ------FORTRAN SUBROUTINE WHICH DEFINES THE CURRENT PARAMETRIC */
/* ------SURFACE.  THE PARAMETER VALUES U,V,W ARE INITIALLY SUPPLIED */
/* ------FROM THE PART PROGRAM TO GIVE THIS ALGORITHM A GOOD STARTUP */
/* ------POINT  THE SURFACE PT AND NORMAL CORRESPONDING TO THESE */
/* ------PARAMETER VALUES ARE RETURNED.  THEREAFTER, THE ROUTINE */
/* ------MODIFIES THE U V PARAMETER VALUES UNTIL THEY GENERATE A GOOD */
/* ------SURFACE POINT */
    temp1[0] = sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.tp[ifxcor_1.is * 3 - 3];
    temp1[1] = sv_1.sp[ifxcor_1.is * 3 - 2] - sv_1.tp[ifxcor_1.is * 3 - 2];
    temp1[2] = sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.tp[ifxcor_1.is * 3 - 1];
/* L22: */
    sv_1.s[ifxcor_1.is - 1] = temp1[0] * sv_1.sn[ifxcor_1.is * 3 - 3] + temp1[
	    1] * sv_1.sn[ifxcor_1.is * 3 - 2] + temp1[2] * sv_1.sn[
	    ifxcor_1.is * 3 - 1];
/* ------IF TOOL POINT AND SURF PT ARE CLOSE THEN MAKE NORMAL EXIT */
/* Computing 2nd power */
    d__1 = temp1[0];
/* Computing 2nd power */
    d__2 = temp1[1];
/* Computing 2nd power */
    d__3 = temp1[2];
    dtemp = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    inorm = 1;
    if (dtemp < z1em4) {
	goto L40;
    }
/* ------ IF IMODE=1 CHECK FOR SUFACE NORMAL ALLIGNMENT WITH TOOL POINT */
    zang = sv_1.sn[ifxcor_1.is * 3 - 3] * temp1[0] + sv_1.sn[ifxcor_1.is * 3 
	    - 2] * temp1[1] + sv_1.sn[ifxcor_1.is * 3 - 1] * temp1[2];
    xang = abs(zang) / dtemp;
    if (mode == 1 && (d__1 = xang - 1.f, abs(d__1)) < z1em4) {
	goto L40;
    }
    ang = 1.f - (d__1 = sv_1.s[ifxcor_1.is - 1] / dtemp, abs(d__1));
    den = sv_1.tn[ifxcor_1.is * 3 - 3] * sv_1.sn[ifxcor_1.is * 3 - 3] + 
	    sv_1.tn[ifxcor_1.is * 3 - 2] * sv_1.sn[ifxcor_1.is * 3 - 2] + 
	    sv_1.tn[ifxcor_1.is * 3 - 1] * sv_1.sn[ifxcor_1.is * 3 - 1];
/* ------IF THE TOOL NORMAL AND SURFACE NORMAL ARE NEARLY PERPENDICULAR */
/* ------THEN TAKE AN ABNORMAL EXIT */
    inorm = 2;
    if (mode == 2 && abs(den) < z1em4) {
	goto L70;
    }
/* ------THE FIRST TIME THROUGH, COMPUTE THE INTERSECTION OF THE */
/* ------TOOL RAY TP,TN AND THE STARTUP SURFACE PLANE */
    if (abs(den) > 1e-6) {
	sv_1.s[ifxcor_1.is - 1] /= den;
    }
/* ------IF THE SURFACE POINT IS CLOSE TO THE TOOL RAY, THEN EXIT NORMALLY */
    dot = temp1[0] * sv_1.tn[ifxcor_1.is * 3 - 3] + temp1[1] * sv_1.tn[
	    ifxcor_1.is * 3 - 2] + temp1[2] * sv_1.tn[ifxcor_1.is * 3 - 1];
    for (ll = 1; ll <= 3; ++ll) {
/* L6031: */
	pdum[ll - 1] = temp1[ll - 1] - dot * sv_1.tn[ll + ifxcor_1.is * 3 - 4]
		;
    }
/* Computing 2nd power */
    d__1 = pdum[0];
/* Computing 2nd power */
    d__2 = pdum[1];
/* Computing 2nd power */
    d__3 = pdum[2];
    ddum = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    inorm = 4;
    if (mode == 2 && ddum < z1em4) {
	goto L40;
    }
    if (mode == 1) {
	goto L501;
    }
/* ------P IS THE POINT OF INTERSECTION OF TANGENT PLANE AND TOOL RAY */
    p[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 3];
    p[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 2];
    p[2] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 1];
    goto L601;
L501:
    p[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + zang * sv_1.sn[ifxcor_1.is * 3 - 3];
    p[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + zang * sv_1.sn[ifxcor_1.is * 3 - 2];
    p[2] = sv_1.tp[ifxcor_1.is * 3 - 1] + zang * sv_1.sn[ifxcor_1.is * 3 - 1];
L601:
    disp[0] = p[0] - sv_1.sp[ifxcor_1.is * 3 - 3];
    disp[1] = p[1] - sv_1.sp[ifxcor_1.is * 3 - 2];
    disp[2] = p[2] - sv_1.sp[ifxcor_1.is * 3 - 1];
/* ------FIND A CHANGE DU,DV IN U,V SUCH THAT DU*DERU+DV*DERV=DISP */
    for (l = 1; l <= 6; ++l) {
/* L5014: */
	temp1[l - 1] = 0.;
    }
    for (l = 1; l <= 3; ++l) {
	temp1[0] += deru[l + ip * 3 - 4] * deru[l + ip * 3 - 4];
	temp1[1] += deru[l + ip * 3 - 4] * derv[l + ip * 3 - 4];
	temp1[2] += derv[l + ip * 3 - 4] * derv[l + ip * 3 - 4];
	temp1[4] += disp[l - 1] * deru[l + ip * 3 - 4];
/* L5015: */
	temp1[5] += disp[l - 1] * derv[l + ip * 3 - 4];
    }
    for (l = 1; l <= 6; ++l) {
	if ((d__1 = temp1[l - 1], abs(d__1)) < 1e-30) {
	    temp1[l - 1] = 0.f;
	}
/* L5016: */
    }
/* Computing 2nd power */
    d__1 = temp1[1];
    temp1[3] = temp1[0] * temp1[2] - d__1 * d__1;
    if (abs(temp1[3]) < 1e-30) {
	goto L40;
    }
    dif[0] = (temp1[2] * temp1[4] - temp1[1] * temp1[5]) / temp1[3];
    dif[1] = (temp1[0] * temp1[5] - temp1[1] * temp1[4]) / temp1[3];
    tu = *uu + dif[0];
    tv = *vv + dif[1];
    if (mode == 3) {
	goto L3041;
    }
/* ------SAVE THE CURRENT SURFACE NORMAL SINCE LCLS RESETS SN */
    for (l = 1; l <= 3; ++l) {
/* L6713: */
	t1[l - 1] = sv_1.sn[l + ifxcor_1.is * 3 - 4];
    }
    lcls_(&tu, &tv, spll, pdum, pdum1, &mmode);
/* ------RESTORE THE OLD SURFACE NORMAL */
    for (l = 1; l <= 3; ++l) {
/* L6714: */
	sv_1.sn[l + ifxcor_1.is * 3 - 4] = t1[l - 1];
    }
/* ------AFTER THE FIRST PASS, USE THE LAST SURFACE POINT AND PARA- */
/* ------BOLIC INTERPOLATION TO ESTIMATE BETTER U,V VALUES */
/* L3100: */
/* ------FIRST SETUP THE APPROXIMATING PARABOLA TO THE SURFACE */
    for (l = 1; l <= 3; ++l) {
/* L3040: */
	sdif[l - 1] = spll[l - 1] - sv_1.sp[l + ifxcor_1.is * 3 - 4];
    }
    vnorm_(sdif, sdif);
    if (fxcor_1.vtem > 1e-12) {
	goto L3042;
    }
    ifstt[ip - 1] = 3;
    mode = 3;
L3041:
    *uu = tu;
    *vv = tv;
    goto L10;
L3042:
    cross_(sdif, &sv_1.sn[ifxcor_1.is * 3 - 3], t1);
    cross_(t1, &sv_1.sn[ifxcor_1.is * 3 - 3], t2);
    vnorm_(t2, t2);
/* ------ T2 IS NOW THE PARABOLIC TANGENT VECTOR */
    px = sdif[0] * t2[0] + sdif[1] * t2[1] + sdif[2] * t2[2];
    py = sdif[0] * sv_1.sn[ifxcor_1.is * 3 - 3] + sdif[1] * sv_1.sn[
	    ifxcor_1.is * 3 - 2] + sdif[2] * sv_1.sn[ifxcor_1.is * 3 - 1];
    pcurv = py / (px * px);
/* ------ THE PARABOLA IS NOW R(S) = SP + S*T2 + S**2*PCURV*SN */
    for (l = 1; l <= 3; ++l) {
/* L3050: */
	t1[l - 1] = pcurv * sv_1.sn[l + ifxcor_1.is * 3 - 4];
    }
/* ------ NOW CALL FOR THE CLOSEST APPROACH BETWEEN THE PARABOLA AND */
/* ------AND THE TOOL RAY */
    parlnd_(&sv_1.tp[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3], &
	    sv_1.sp[ifxcor_1.is * 3 - 3], t2, t1, &sv_1.s[ifxcor_1.is - 1], 
	    pdum, &sa, pdum1, &ddum, &mode, &isv_1.iop[ifxcor_1.is - 1], &
	    ifail);
    if (ifail == 1) {
	goto L70;
    }
/* ------ IF THE TOOL RAY LIES CLOSE TO THE PARABOLA, THEN EXIT NORMALLY */
/* ------ON RETURN, S(IS) IS THE DISTANCE ALONG THE TOOL NORMAL FROM */
/* ------TP TO CLOSEST APPROACH TO THE PARABOLA.  SA IS THE PARAMETER */
/* ------VALUE WHICH DEFINES THE POINT ON THE PARABOLA.  OTHER */
/* ------VARIABLES RETURNED (PDUM,PDUM1,DDUM) ARE NOT NEEDED HERE */
/* ------ FROM THIS CONSTRUCT AN ESTIMATED DISPLACEMENT VECTOR */
    for (l = 1; l <= 3; ++l) {
	disp[l - 1] = sa * t2[l - 1];
	if ((d__1 = disp[l - 1], abs(d__1)) < 1e-30) {
	    disp[l - 1] = 0.f;
	}
/* L3060: */
    }
/* L4010: */
/* ------IF DISP IS VERY SMALL, MAKE A NORMAL EXIT */
/* Computing 2nd power */
    d__1 = disp[0];
/* Computing 2nd power */
    d__2 = disp[1];
/* Computing 2nd power */
    d__3 = disp[2];
    temp1[0] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    temp1[0] = sqrt(temp1[0]);
    inorm = 5;
    if (temp1[0] < 1e-6) {
	goto L40;
    }
/* ------TEST FOR LOOP COUNTER EXCEEDED */
    if (lct > 24) {
	goto L70;
    }
/* ------FIND A CHANGE DU,DV IN U,V SUCH THAT DU*DERU+DV*DERV=DISP */
/* L85: */
    for (l = 1; l <= 6; ++l) {
/* L3070: */
	temp1[l - 1] = 0.f;
    }
    for (l = 1; l <= 3; ++l) {
	temp1[0] += deru[l + ip * 3 - 4] * deru[l + ip * 3 - 4];
	temp1[1] += deru[l + ip * 3 - 4] * derv[l + ip * 3 - 4];
	temp1[2] += derv[l + ip * 3 - 4] * derv[l + ip * 3 - 4];
	temp1[4] += disp[l - 1] * deru[l + ip * 3 - 4];
/* L3080: */
	temp1[5] += disp[l - 1] * derv[l + ip * 3 - 4];
    }
    for (l = 1; l <= 6; ++l) {
	if ((d__1 = temp1[l - 1], abs(d__1)) < 1e-30) {
	    temp1[l - 1] = 0.f;
	}
/* L3085: */
    }
/* Computing 2nd power */
    d__1 = temp1[1];
    temp1[3] = temp1[0] * temp1[2] - d__1 * d__1;
    if (abs(temp1[3]) < 1e-30) {
	goto L40;
    }
    dif[0] = (temp1[2] * temp1[4] - temp1[1] * temp1[5]) / temp1[3];
    dif[1] = (temp1[0] * temp1[5] - temp1[1] * temp1[4]) / temp1[3];
    *uu += dif[0];
    *vv += dif[1];
    ++lct;
    us[lct - 1] = *uu;
    vs[lct - 1] = *vv;
/* ------INTRODUCE ARITHMETIC MEANS TO AVOID OSCILLATIONS */
    if (lct < 9) {
	goto L250;
    }
    *uu = 0.f;
    *vv = 0.f;
    i__1 = lct;
    for (ll = 9; ll <= i__1; ++ll) {
	*uu += us[ll - 1];
/* L260: */
	*vv += vs[ll - 1];
    }
    *uu /= lct - 8;
    *vv /= lct - 8;
L250:
    goto L10;
/* ------        END OF U,V ITERATIVE LOOP LOGIC */
L40:
    if (mode != 1) {
	goto L4050;
    }
    if (dtemp < z1em4) {
	goto L4050;
    }
    sv_1.tn[ifxcor_1.is * 3 - 3] = sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.tp[
	    ifxcor_1.is * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = sv_1.sp[ifxcor_1.is * 3 - 2] - sv_1.tp[
	    ifxcor_1.is * 3 - 2];
    sv_1.tn[ifxcor_1.is * 3 - 1] = sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.tp[
	    ifxcor_1.is * 3 - 1];
/* Computing 2nd power */
    d__1 = sv_1.tn[ifxcor_1.is * 3 - 3];
/* Computing 2nd power */
    d__2 = sv_1.tn[ifxcor_1.is * 3 - 2];
/* Computing 2nd power */
    d__3 = sv_1.tn[ifxcor_1.is * 3 - 1];
    sv_1.s[ifxcor_1.is - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
L4050:
/* L55: */
    sv_1.snl[ifxcor_1.is * 3 - 3] = fxcor_1.tem[0];
    sv_1.snl[ifxcor_1.is * 3 - 2] = fxcor_1.tem[1];
    sv_1.snl[ifxcor_1.is * 3 - 1] = fxcor_1.tem[2];
    sv_1.spl[ifxcor_1.is * 3 - 3] = fxcor_1.tem[3];
    sv_1.spl[ifxcor_1.is * 3 - 2] = fxcor_1.tem[4];
    sv_1.spl[ifxcor_1.is * 3 - 1] = fxcor_1.tem[5];
/* ------IF STARTUP IS FINISHED , LET U,V ASSUME THE LAST DEFINED */
/* ------UU,VV VALUES */
    *u = *uu;
    *v = *vv;
    if (isv_1.iop[ifxcor_1.is - 1] != 1 || sv_1.s[ifxcor_1.is - 1] >= 0.f) {
	goto L999;
    }
/* ------  ERROR EXIT FOLLOWS */
L70:
/* ------ IF TOOL NORMAL DIDNOT INTERSECT SURFACE, TRY TO FIND AN SRP */
    if (mode == 2) {
	goto L1740;
    }
    ifxcor_1.ier = 1;
L999:
    jentl = isv_1.jent[ifxcor_1.is - 1];
    return 0;
L1740:
    mode = 1;
    *uu = *u;
    *vv = *v;
    goto L4090;
} /* ddpara_ */

#undef temp1
#undef disp
#undef sinl
#undef cosl
#undef dif
#undef vv
#undef uu


