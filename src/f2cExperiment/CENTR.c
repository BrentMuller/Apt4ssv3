/* CENTR.f -- translated by f2c (version 20100827).
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
    doublereal a, b, c__, cendis, cmove[3], com1, com4, dir[3], dp, dpe, 
	    dpcnt, dpi, dpl, dp1, d1, d2a, flipck, fwd[3], ogle[3], p1[3], p2[
	    3], rdrn, refpnt[3], tangl, tes[3], tew[3], uvec[3], u2[3], v[3], 
	    vl, zl, zlnorm[3], zlpnt[3], zl1, param[6], r__[6], savpar[4], 
	    seg[9], slope, sqroot, unn, upp, vint, vnn, vpp;
} dshar4_;

#define dshar4_1 dshar4_

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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    integer jteneu;
} chang_;

#define chang_1 chang_

/* Table of constant values */

static integer c__25009 = 25009;
static integer c__25008 = 25008;
static integer c__25007 = 25007;
static integer c__25004 = 25004;
static integer c__25003 = 25003;
static integer c__25005 = 25005;
static integer c__25002 = 25002;

/* *** SOURCE FILE : M0002742.W07   *** */

/* .....FORTRAN SUBROUTINE  ....CENTR          8/68                    HG */
/* ...  FORTRAN SUBROUTINE               CENTR */
/* Subroutine */ int centr_(void)
{
    /* Format strings */
    static char fmt_210[] = "";
    static char fmt_600[] = "";
    static char fmt_1000[] = "";
    static char fmt_302[] = "";
    static char fmt_310[] = "";
    static char fmt_900[] = "";
    static char fmt_320[] = "";
    static char fmt_410[] = "";
    static char fmt_1400[] = "";
    static char fmt_420[] = "";
    static char fmt_471[] = "";
    static char fmt_482[] = "";
    static char fmt_510[] = "";
    static char fmt_520[] = "";
    static char fmt_531[] = "";
    static char fmt_532[] = "";
    static char fmt_550[] = "";
    static char fmt_570[] = "";
    static char fmt_605[] = "";
    static char fmt_922[] = "";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, im, ik;
    static doublereal acc;
    static integer iii, jfpd;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal teza[3];
    static logical lret;
    static integer jtrc;
    static doublereal ptol;
    static integer jtol;
    extern /* Subroutine */ int apt238_(integer *), amind_(void), cplan_(void)
	    ;
    static integer itink;
    static doublereal smove, saves;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *), gauss_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal simax, bcmov;
    static integer issto;
    extern /* Subroutine */ int tinkr_(void);
    static integer j2surf, jfndck;
    static doublereal tanang;
    static integer jcplan;
    static doublereal saveta[3];
#define kdynfl ((integer *)&addcom_1 + 48)
    static doublereal savete[3];
    static integer itolfl, jcmove, jtstck;
    extern /* Subroutine */ int altcmv_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, logical *);
    static integer jtstpd;

    /* Assigned format variables */
    static char *j2surf_fmt, *jfpd_fmt, *jfndck_fmt, *jtstpd_fmt, *jtstck_fmt,
	     *jcplan_fmt, *jcmove_fmt;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  4.  DSHARE BLOCK 4  *** */





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




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/* ...  21. ADDCOM BLOCK */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/* ---- FLAG INTRODUCED BY VW - USED TO INDICATE IF TE HAS CHANGED */
/*                             JTENEU = 1 NO CHANGE FOR TE */
/*                                    = 0 TE HAS CHANGED */





/*                   ACC       FUDGE TERM FOR DISTANCE MEASUREMENTS, SET */
/*                             AT 5.E-6 */
/*                  IM       FLAG USED IN ORIENTING TANGENT CS NORMAL */
/*                           WITH OTHER SURFACE NORMAL. */
/*                   PTOL      FRACTION OF TOTAL TOLERANCE BAND ABOUT */
/*                             PLANES WITHIN WHICH TOOL IS CONSTRAINED */
/*                             TO LIE. INITIALLY .2, ENLARGED TO 1.0 AS */
/*                             ITERATION COUNT INCREASES. */
/*                   SAVETA(3) SAVES TOOL AXIS DURING NOTAN STEP. */
/*                   SAVETE(3) SAVES TOOL END POSITION DURING NOTAN STEP. */
/*                   SAVES     SAVES DISTANCE TO ALL 3 SURFACES ON ENTRY */
/*                             TO NOTAN STEP.  USED AS A CRITERION FOR */
/*                             POSSIBLE RESTART FROM ENTRY TO NOTAN. */
/*                   SMOVE     MAGNITUDE OF SMALLEST VECTOR WHICH CAN BE */
/*                             ADDED TO TOOL END WITHIN SINGLE PRECISION. */
/*                             SET ON ENTRY TO CENTR.   ALL MOVE VECTORS */
/*                             ARE ENLARGED TO THIS SIZE IF NECESSARY */
/*                   TANANG    CRITERION FOR ESTABLISHING PSEUDO-TANGENCY */
/*                             IS DOT(CHECK SURF NORMAL, OTHER SURF */
/*                             NORMAL) .GT. TANANG.  SET AT 1-.5*TAU. */

/*                   PURPOSE   TO ITERATE CUTTER TO DESIRED POSITION */
/*                             RELATIVE TO 2 OR 3 SURFACES */

/* ----------------------------------------------------------------------- */

/*     MAIN ROUTINE */
/* ...                INITIALIZATIONS */

    itink = 0;
    itolfl = 0;
    ishr18_1.jtkf = 0;

    for (i__ = 1; i__ <= 3; ++i__) {
	teza[i__ - 1] = fxcor_1.te[i__ - 1];
/* L1: */
    }
/*                                       TINKR FAILURE COUNTER */
    jtrc = 10;
/*                                       PLANE TOLERANCE LIMIT FACTOR */
    ptol = .2f;
/*                                       PARALLEL SURFACE TOLERANCE */
    tanang = 1.f - sv_1.tau[ifxcor_1.is - 1] * .5f;
    if (tanang < znumbr_1.z9em1) {
	tanang = znumbr_1.z9em1;
    }
/*                                       EPSILON FOR DISTANCES */
    acc = 5e-6;
/*                                       MAGNITUDE OF SMALLEST MOVE WHICH */
/*                                       CAN BE MADE IN SINGLE PRECISION */
/* Computing MAX */
    d__1 = abs(fxcor_1.te[0]), d__2 = abs(fxcor_1.te[1]), d__1 = max(d__1,
	    d__2), d__2 = abs(fxcor_1.te[2]);
    smove = max(d__1,d__2) * 1e-7;
/*                                       CPLAN FLAGS */
    sv1_1.cplfl[ifxcor_1.is - 1] = 0.f;
    sv1_1.cptst[ifxcor_1.is - 1] = 0.f;




/* ...                SET ITERATION COUNTERS */

/*                                       5-AXIS RESTART COUNTER */
    ishr18_1.jcnt3 = 25;
/*                                       NOTAN CPLAN COUNTER */
L100:
    ishr18_1.jcnt2 = 25;
/*                                       BASIC CMOVE ITERATION COUNTER */
    ishr18_1.jcnt1 = 25;

/* ...                CALL 2 SURF IF 2 SURFACE ITERATION */

L105:
    if (isv1_1.j51[ifxcor_1.is - 1] <= 0) {
	goto L200;
    } else {
	goto L120;
    }

/* ...                CALL TANTO FOR TANGENT CS, OTHERWISE 3 SURF */

L120:
    if (isv_1.isftyp[ifxcor_1.is - 1] - 4 != 0) {
	goto L300;
    } else {
	goto L400;
    }

/*                                       GO TO EXIT */
L130:
    goto L1100;





/* ----------------------------------------------------------------------- */
/*     2 SURF - ITERATE TOOL INTO PART AND DRIVE ONLY */



/* ...                CALL 2 SURF ITERAT */

L200:
    j2surf = 0;
    j2surf_fmt = fmt_210;
    goto L600;

/* ...                SET FLAG, 2 SURFACE ITERATION SUCCESSFUL */

L210:
    ishr18_1.jcr = 0;

/* ...                RETURN TO MAIN PROGRAM */

    goto L130;





/* ----------------------------------------------------------------------- */
/*     3 SURF - ITERATE TOOL TO PART, DRIVE, AND CHECK SURFACES */



/* ...                FIND PART AND DRIVE SURFACES */

L300:
    jfpd = 0;
    jfpd_fmt = fmt_1000;

/* ...                FIND CHECK SURFACE */

    jfndck = 0;
    jfndck_fmt = fmt_302;
    goto L800;

/* ...                FETCH CHECK DATA */

/*                                       NORMAL */
L302:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.plnv[i__ + ifxcor_1.is * 3 - 4] = sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4];
/* L305: */
    }
/*                                       DISTANCE */
    sv_1.plnd[ifxcor_1.is - 1] = sv_1.s[ifxcor_1.is - 1];

/* ...                TEST PART AND DRIVE SURFACES */

    jtstpd = 0;
    jtstpd_fmt = fmt_310;
    goto L900;
L310:
    if (jtol <= 0) {
	goto L330;
    } else {
	goto L315;
    }

/* ...                BOTH WITHIN LIMIT, CALL TEST CHECK SURF */

L315:
    jtstck = 0;
    jtstck_fmt = fmt_320;
    goto L1300;
L320:
    if (jtol <= 0) {
	goto L330;
    } else {
	goto L380;
    }

/* ...                TEST IF PSEUDO-TANGENCY ALREADY HANDLED */

L330:
    if (isv1_1.notan[ifxcor_1.is - 1] >= 0) {
	goto L340;
    } else {
	goto L365;
    }

/* ...                TEST IF PSEUDO-TANGENCY HAS DEVELOPED */

/*                                       TEST CHECK SURF BEYOND STEP */
L340:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - dshar4_1.dp <= 0.) {
	goto L350;
    } else {
	goto L365;
    }
/*                                       TEST SURFACE TANGENCY */
L350:
    i__1 = ifxcor_1.ids;
    i__2 = ifxcor_1.lsv;
    for (i__ = ifxcor_1.ips; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += 
	    i__2) {
	if (tanang - (d__1 = sv_1.sn[ifxcor_1.is * 3 - 3] * sv_1.sn[i__ * 3 - 
		3] + sv_1.sn[ifxcor_1.is * 3 - 2] * sv_1.sn[i__ * 3 - 2] + 
		sv_1.sn[ifxcor_1.is * 3 - 1] * sv_1.sn[i__ * 3 - 1], abs(d__1)
		) >= 0.) {
	    goto L360;
	} else {
	    goto L370;
	}
L360:
	;
    }
/*                                       NO PSEUDO-TAN */

/* ...                CALL CMOVE AND LOOP */

L365:
    jcmove = 0;
    goto L700;

/* ...                PSEUDO TANGENCY CASE */

/*                                       SET FLAG FOR TANGENT SURF */
L370:
    isv1_1.ifl4[ifxcor_1.is - 1] = (ifxcor_1.ids - i__) / ifxcor_1.lsv;
/*                                       CALL NOTAN AND LOOP */
    goto L500;

/* ...                SET FLAG, SUCCESSFUL 3-SURF ITERATION */

L380:
    ishr18_1.jcr = 1;
    goto L1100;




/* ----------------------------------------------------------------------- */
/*     TANTO -  3 SURFACE ITERATION IN TANTO OR PSTAN CASE */



/* ...                CALL FIND PART AND DRIVE */

L400:
    if (isv1_1.ifl4[ifxcor_1.is - 1] == 0 && (isv_1.isfidn[ifxcor_1.ids - 1] 
	    > 2 || isv_1.isfidn[ifxcor_1.ics - 1] > 2)) {
	goto L402;
    }
    if (isv1_1.ifl4[ifxcor_1.is - 1] == 1 && (isv_1.isfidn[ifxcor_1.ips - 1] 
	    > 2 || isv_1.isfidn[ifxcor_1.ics - 1] > 2)) {
	goto L402;
    }
    if (isv_1.isfidn[ifxcor_1.ips - 1] <= 2) {
	aerr_(&c__25009, "CENTR   ", (ftnlen)8);
    }
L402:
    im = -1;
    jfpd = 1;
    jfpd_fmt = fmt_410;
    goto L800;

/* ...                CALL FIND CHECK */

L410:
    jfndck = 1;
    jfndck_fmt = fmt_1400;

/* ...                CALL CPLAN SURF */

    jcplan = 0;
    jcplan_fmt = fmt_420;
    goto L1000;

/* ...                TEST WHETHER NORMALS HAVE SAME ORIENTATION */

L420:
    if (sv1_1.plncs[ifxcor_1.is - 1] >= 0.) {
	goto L460;
    } else {
	goto L430;
    }

/* ...                OPPOSITE, TEST WHETHER TOOL NORMAL ALREADY REVERSED */

L430:
    if (im >= 0) {
	goto L450;
    } else {
	goto L440;
    }

/* ...                NOT REVERSED, REVERSE AND SET FLAG */

L440:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L445: */
    }
    im = 0;
    goto L410;

/* ...                NORMAL REVERSED, TEST WHETHER NORMALS NEAR ORTHOG */

L450:
    if ((d__1 = sv1_1.plncs[ifxcor_1.is - 1], abs(d__1)) - .01f >= 0.) {
	goto L452;
    } else {
	goto L455;
    }

/* ...                NEAR ORTHOGONAL, ERROR EXIT */

L452:
    aerr_(&c__25008, "CENTR   ", (ftnlen)8);

/* ...                RESET TOOL NORM REVERSAL FLAG */

L455:
    im = -1;

/* ...                TEST WHETHER WITHIN 2*TAU OF CPLAN */

L460:
    if ((d__1 = sv_1.plnd[ifxcor_1.is - 1], abs(d__1)) - sv_1.eps4[
	    ifxcor_1.is - 1] <= 0.) {
	goto L462;
    } else {
	goto L464;
    }

/* ...                WITHIN 2*TAU, TEST WHETHER NORMALS PARALLEL */

L462:
    if (tanang - (d__1 = sv_1.sn[ifxcor_1.is * 3 - 3] * sv_1.sn[ifxcor_1.it * 
	    3 - 3] + sv_1.sn[ifxcor_1.is * 3 - 2] * sv_1.sn[ifxcor_1.it * 3 - 
	    2] + sv_1.sn[ifxcor_1.is * 3 - 1] * sv_1.sn[ifxcor_1.it * 3 - 1], 
	    abs(d__1)) <= 0.) {
	goto L480;
    } else {
	goto L464;
    }

/* ...                CALL CMOVE, USING CPLAN DATA */

L464:
    jcmove = 1;
    jcmove_fmt = fmt_471;
    goto L700;

/* ...                CALL 2 SURFACE ITERATION AND LOOP */

L471:
    im = -1;
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&knumbr_1.k31);
    }
    j2surf = 1;
    goto L600;

/* ...                NORMALS PARALLEL, CALL TEST CHECK SURF */
/*                                       RETURN TO MAIN IF IN TOL */
L480:
    jtstck = 1;
    jtstck_fmt = fmt_482;
    goto L1300;
L482:
    if (jtol <= 0) {
	goto L486;
    } else {
	goto L483;
    }
L483:
    ishr18_1.jcr = 1;
    goto L130;

/* ...                NOT WITHIN TOL, TEST WHETHER WITHIN 8*TAU */

L486:
    if (sv_1.tau[ifxcor_1.is - 1] * 8.f - (d__1 = sv_1.s[ifxcor_1.is - 1], 
	    abs(d__1)) <= 0.) {
	goto L488;
    } else {
	goto L464;
    }

/* ...                NOT WITHIN 8*TAU, FALSE TANGENCY EXIT */

L488:
    ishr18_1.jcr = 2;
    goto L1100;




/* ----------------------------------------------------------------------- */
/*     NOTAN - PSEUDO-TANGENCY CALCULATION */


/*                                       FLAG- PSEUDO TANGENCY DONE */
L500:
    isv1_1.notan[ifxcor_1.is - 1] = -1;
/*                                       SAVE CUTTER POSITION FOR */
/*                                       RESET IF NECESSARY */
    for (i__ = 1; i__ <= 3; ++i__) {
	savete[i__ - 1] = fxcor_1.te[i__ - 1];
	saveta[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L502: */
    }
/*                                       CURRENT DISTANCE FROM SURFACES */
    saves = (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) + (d__2 = sv_1.s[
	    ifxcor_1.ids - 1], abs(d__2)) + (d__3 = sv_1.s[ifxcor_1.ips - 1], 
	    abs(d__3));

/* ...                CALL FIND PART AND DRIVE */

    jfpd = 2;
    jfpd_fmt = fmt_510;
    goto L800;

/* ...                CALL FIND CHECK */

L510:
    jfndck = 1;
    jfndck_fmt = fmt_1400;

/* ...                CALL CPLAN SURF */

    jcplan = 1;
    jcplan_fmt = fmt_520;
    goto L1000;

/* ...                TEST WHETHER WITHIN 2*TAU OF CPLAN */

L520:
    if ((d__1 = sv_1.plnd[ifxcor_1.is - 1], abs(d__1)) - sv_1.eps4[
	    ifxcor_1.is - 1] <= 0.) {
	goto L540;
    } else {
	goto L530;
    }

/* ...                                    CALL CMOVE */

L530:
    jcmove = 2;
    jcmove_fmt = fmt_600;

/* ...                                    CALL 2 SURF ITERAT */

    j2surf = 2;
    j2surf_fmt = fmt_531;
    goto L700;

/* ...                CALL FIND CHECK */

L531:
    jfndck = 2;
    jfndck_fmt = fmt_532;
    goto L1000;

/* ...                RESTORE IF MOVED AWAY FROM SURFACES */

L532:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - saves * 2.f <= 0.) {
	goto L510;
    } else {
	goto L535;
    }
L535:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] = savete[i__ - 1];
	fxcor_1.ta[i__ - 1] = saveta[i__ - 1];
/* L537: */
    }
/*                                       RETURN TO 3 SURF */
    goto L300;

/* ...                TEST WHETHER CHECK SURF WITHIN TOL */

L540:
    jtstck = 2;
    jtstck_fmt = fmt_550;
    goto L1300;
L550:
    if (jtol <= 0) {
	goto L555;
    } else {
	goto L565;
    }

/* ...                TEST WHETHER CHECK SURF WITHIN 8*TAU */
/*                                       RETURN TO 3 SURF IF SO */
L555:
    if (sv_1.tau[ifxcor_1.is - 1] * 8 - (d__1 = sv_1.s[ifxcor_1.is - 1], abs(
	    d__1)) <= 0.) {
	goto L560;
    } else {
	goto L535;
    }

/* ...                SET FALSE TANGENCY FLAG AND EXIT */

L560:
    ishr18_1.jcr = 2;
    goto L1100;

/* ...                CALL TEST PART AND DRIVE */

L565:
    jtstpd = 1;
    jtstpd_fmt = fmt_570;
    goto L900;

/* ...                RETURN TO 3-SURF IF BOTH WITHIN TOL, */
/* ...                FALSE TANGENCY IF NOT */

L570:
    if (jtol <= 0) {
	goto L560;
    } else {
	goto L300;
    }




/* ----------------------------------------------------------------------- */
/*     2 SURF ITERATE - ITERATE TOOL INTO PART AND DRIVE SURFACES */



/* ...                FIND PART AND DRIVE SURFACES */

L600:
    jfpd = 3;
    jfpd_fmt = fmt_900;

/* ...                TEST PART AND DRIVE SURFACES */

    jtstpd = 2;
    jtstpd_fmt = fmt_605;
    goto L800;

/* ...                RETURN IF BOTH WITHIN TOL */

L605:
    if (jtol <= 0) {
	goto L615;
    } else {
	goto L610;
    }
/*                                       RETURN */
L610:
    switch (j2surf) {
	case 0: goto L210;
	case 1: goto L410;
	case 2: goto L531;
    }

/* ...                CREATE PSEUDO CHECK SURFACE NORMAL TO */
/* ...                PART AND DRIVE */

L615:
    cross_(&sv_1.tn[ifxcor_1.ips * 3 - 3], &sv_1.tn[ifxcor_1.ids * 3 - 3], &
	    sv_1.plnv[ifxcor_1.is * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.is * 3 - 3], &sv_1.plnv[ifxcor_1.is * 3 - 3]);
    sv_1.plnd[ifxcor_1.is - 1] = 0.f;

/* ...                CALL CMOVE AND LOOP */

    jcmove = 2;
    goto L700;




/* ----------------------------------------------------------------------- */
/*     CMOVE - COMPUTE AND APPLY MOVE VECTOR */



/* ...                IN CASE OF PLANE PART AND DRIVE SURFACES, MODIFY */
/* ...                DISTANCES TO DIRECT TOOL TOWARD CENTER OF TOLERANCE */
/* ...                BAND AS ITERATION COUNT INCREASES */

L700:
    i__2 = ifxcor_1.ids;
    i__1 = ifxcor_1.lsv;
    for (i__ = ifxcor_1.ips; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += 
	    i__1) {
/*                                       SKIP IF SURF NOT A PLANE */
	if (isv_1.ipl[i__ - 1] != 0) {
	    goto L705;
	} else {
	    goto L701;
	}
/*                                       ADAUST DIST TOWARD CENTER */
L705:
	sv_1.s[i__ - 1] -= (sv_1.tau1[i__ - 1] + sv_1.tau2[i__ - 1]) / 2.f * (
		ptol - .2f) / .8f;

L701:
	;
    }
/* .... SPECIAL TREATMENT FOR 2 SURFACE APPROACH WHEN DIST TO */
/*     ONE SURFACE IS ZERO */
    if (isv1_1.j51[ifxcor_1.is - 1] == 0) {
	if (sv_1.s[ifxcor_1.ids - 1] != znumbr_1.z0) {
	} else {
	    for (iii = 1; iii <= 3; ++iii) {
		dshar4_1.cmove[iii - 1] = znumbr_1.z9em1 * sv_1.tn[iii + 
			ifxcor_1.ips * 3 - 4] * sv_1.s[ifxcor_1.ips - 1];
/* L702: */
	    }
	    goto L720;
	}
    }

/* ...                COMPUTE MOVE VECTOR */

    gauss_(&sv_1.tn[ifxcor_1.ips * 3 - 3], &sv_1.s[ifxcor_1.ips - 1], &
	    sv_1.tn[ifxcor_1.ids * 3 - 3], &sv_1.s[ifxcor_1.ids - 1], &
	    sv_1.plnv[ifxcor_1.is * 3 - 3], &sv_1.plnd[ifxcor_1.is - 1], 
	    dshar4_1.cmove, &ishr18_1.jpxr);

/* ....  DETERMINE MAXIMUM DIST TO SURFACES */

/* Computing MAX */
    d__4 = (d__1 = sv_1.s[ifxcor_1.ips - 1], abs(d__1)), d__5 = (d__2 = 
	    sv_1.s[ifxcor_1.ids - 1], abs(d__2)), d__4 = max(d__4,d__5), d__5 
	    = (d__3 = sv_1.plnd[ifxcor_1.is - 1], abs(d__3));
    simax = max(d__4,d__5);

    if (ishr18_1.jpxr != 0) {
/* .... GAUSS FAILED - COMPUTE CMOVE BY ALTERNATIVE METHODS */
	altcmv_(&ishr18_1.jpxr, sv_1.tn, sv_1.s, &ifxcor_1.ips, &ifxcor_1.ids,
		 &sv_1.plnd[ifxcor_1.is - 1], &sv_1.plnv[ifxcor_1.is * 3 - 3],
		 &sv_1.eps1[ifxcor_1.is - 1], dshar4_1.cmove, &lret);
	ishr18_1.jpxr = 1;
/* .... IS TOOL IN TOLERANCE OD CS WHEN PS PARALLEL TO CS */
	if (lret) {
	    goto L380;
	}
    }

/* ...                TEST FOR ITERATION 10, 5, OR 3 OF 3 SURF */

L720:
    if ((ishr18_1.jcnt1 - 18) * (ishr18_1.jcnt1 - 9) * (ishr18_1.jcnt1 - 3) + 
	    (ishr18_1.jcnt1 - 22) != 0) {
	goto L735;
    } else {
	goto L725;
    }

/* ...                IF SO, WIDEN TOLERANCE LIMIT AND HALVE MOVE */

L725:
    sv_1.eps8[ifxcor_1.ips - 1] *= 1.709976f;
    sv_1.eps8[ifxcor_1.ids - 1] *= 1.709976f;
    sv_1.eps8[ifxcor_1.is - 1] *= 1.709976f;
    ptol *= 1.709976f;
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.cmove[i__ - 1] *= .5f;
/* L730: */
    }

/* .... ENSURE CMOVE IS LESS THAN LARGEST ACTUAL DISTANCE TO SURFACES */
    bcmov = sqrt(dshar4_1.cmove[0] * dshar4_1.cmove[0] + dshar4_1.cmove[1] * 
	    dshar4_1.cmove[1] + dshar4_1.cmove[2] * dshar4_1.cmove[2]);
    if (bcmov > simax) {
	for (ik = 1; ik <= 3; ++ik) {
	    dshar4_1.cmove[ik - 1] = simax / bcmov * dshar4_1.cmove[ik - 1];
/* L731: */
	}
    }

/* ...                ADD MOVE TO TOOL END */

/*                                       FACTOR TO ENLARGE MOVE TO MINIM- */
/*                                       AL SIZE IF NECESSARY */
L735:
/* Computing MAX */
/* Computing MAX */
    d__3 = abs(dshar4_1.cmove[0]), d__4 = abs(dshar4_1.cmove[1]), d__3 = max(
	    d__3,d__4), d__4 = abs(dshar4_1.cmove[2]);
    d__1 = znumbr_1.z1, d__2 = smove / max(d__3,d__4);
    fxcor_1.temp[0] = max(d__1,d__2);
/*                                       ADD MOVE */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] += fxcor_1.temp[0] * dshar4_1.cmove[i__ - 1];
/* L740: */
    }

/* ...                 STEP COUNTER, AND RETURN */

    if (ishr18_1.jcnt1 <= 0) {
	goto L750;
    } else {
	goto L745;
    }
L745:
    --ishr18_1.jcnt1;
/*                                       RETURN */
    switch (jcmove) {
	case 0: goto L300;
	case 1: goto L471;
	case 2: goto L600;
    }


/* ...                IF COUNTER EXHAUSTED, ISSUE WARNING */

/*                                       BRANCH TO ERROR */
L750:
    goto L1600;



/* ----------------------------------------------------------------------- */
/*     FIND PART DRIVE - DETERMINE NORMALS AND DISTANCES FOR PART */
/*                       AND DRIVE SURFACES */


/*                                       SAVE INDEX */
L800:
    issto = ifxcor_1.is;
/*                                       CALL FOR PART SURFACE */
    ifxcor_1.is = ifxcor_1.ips;
    ishr18_1.jminr = 1;
    amind_();
    ifxcor_1.is = issto;
    if (ishr18_1.jmin == 1) {
	goto L1600;
    }
/*                                       CALL FOR DRIVE SURFACE */

    ifxcor_1.is = ifxcor_1.ids;
    ishr18_1.jminr = 1;
    amind_();
    ifxcor_1.is = issto;
    if (ishr18_1.jmin == 1) {
	goto L1600;
    }
/*                                       RESTORE INDEX */

/*                                       RETURN */
    switch (jfpd) {
	case 0: goto L1000;
	case 1: goto L410;
	case 2: goto L510;
	case 3: goto L900;
	case 4: goto L922;
    }




/* ----------------------------------------------------------------------- */
/*     TEST PART DRIVE - SET JTOL +1 IF BOTH PART AND DRIVE SURFACE */
/*                       DISTANCES ARE ACCEPTABLE */


/* ...                CALL TINKR FOR 5-AXIS CASE */

L900:
    if (ifxcor_1.mantax - 2 >= 0) {
	goto L910;
    } else {
	goto L925;
    }
L910:
    if (itink <= 0) {
	goto L925;
    }
    tinkr_();
/*                                       TEST IF TA MOVED */
    if (ishr18_1.jtr < 0) {
	goto L915;
    } else if (ishr18_1.jtr == 0) {
	goto L921;
    } else {
	goto L925;
    }
L915:
    --jtrc;
    if (jtrc >= 0) {
	goto L925;
    } else {
	goto L920;
    }
/*                                       ERROR IF COUNTER EXHAUSTED */
L920:
    aerr_(&c__25007, "CENTR   ", (ftnlen)8);
/*                                       IF SO,REESTABLISH */
/*                                       FIND PART AND DRIVE */
L921:
    jfpd = 4;
    jfpd_fmt = fmt_922;
    goto L800;
/*                                       RE-ADJUST AXIS */
L922:
    if (itink <= 0) {
	goto L925;
    }
    tinkr_();


/* ...                TEST PART AND DRIVE SURFACES */

L925:
    i__1 = ifxcor_1.ids;
    i__2 = ifxcor_1.lsv;
    for (i__ = ifxcor_1.ips; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += 
	    i__2) {
/*                                       TEST WHETHER SURFACE A PLANE */
	if (isv_1.ipl[i__ - 1] <= 0) {
	    goto L930;
	} else {
	    goto L935;
	}
/*                                       NON-PLANAR */
L930:
	if ((d__1 = sv_1.s[i__ - 1], abs(d__1)) - sv_1.eps8[i__ - 1] <= 0.) {
	    goto L950;
	} else {
	    goto L965;
	}
/*                                       PLANE, TEST WHICH SIDE */
L935:
	if ((d__1 = sv_1.s[i__ - 1]) < 0.) {
	    goto L940;
	} else if (d__1 == 0) {
	    goto L950;
	} else {
	    goto L945;
	}
L940:
	if (sv_1.s[i__ - 1] - ptol * sv_1.tau2[i__ - 1] + 1e-6f >= 0.) {
	    goto L950;
	} else {
	    goto L965;
	}
L945:
	if (sv_1.s[i__ - 1] - ptol * sv_1.tau1[i__ - 1] - 1e-6f <= 0.) {
	    goto L950;
	} else {
	    goto L965;
	}
L950:
	;
    }

/* ...                BOTH WITHIN TOLERANCE */

/* L960: */
    jtol = 1;
    goto L970;

/* ...                NOT BOTH WITHIN TOL */

L965:
    jtol = -1;

/* ...                RETURN */

L970:
    switch (jtstpd) {
	case 0: goto L310;
	case 1: goto L570;
	case 2: goto L605;
    }




/* ----------------------------------------------------------------------- */
/*     FIND CHECK - DETERMINE NORMAL AND DISTANCE TO CHECK SURFACE */



/* ...                CALL AMIND FOR CHECK SURFACE */

/*                                       RETURN IF AMIND ERROR */
L1000:
    ishr18_1.jminr = 1;
    amind_();
/*                                       RESET RETURN FLAG */
    ishr18_1.jminr = 0;
/*                                       BRANCH IF ERROR */
    if (ishr18_1.jmin <= 0) {
	goto L1010;
    } else {
	goto L1600;
    }
/*                                       RETURN */
L1010:
    switch (jfndck) {
	case 0: goto L302;
	case 1: goto L1400;
	case 2: goto L532;
    }




/* ----------------------------------------------------------------------- */
/*     EXIT - RESET QUANTITIES AND RETURN */


/* ...                IF 5-AXIS CASE, VERIFY TOOL AXIS SATISFACTORY */

L1100:
    if (2 - ifxcor_1.mantax <= 0) {
	goto L1102;
    } else {
	goto L1108;
    }

L1102:
    if (itink == 0) {
	itink = 1;
	goto L105;
    } else if (itink == -1) {
	goto L1108;
    } else {
/*                                       RESET AXIS IF NECESSARY */
	tinkr_();
    }
/*                                       TEST WHETHER AXIS MOVED */
    if (ishr18_1.jtr < 0) {
	goto L1103;
    } else if (ishr18_1.jtr == 0) {
	goto L1104;
    } else {
	goto L1108;
    }
/*                                       TINKR ERROR */
L1103:
    aerr_(&c__25004, "CENTR   ", (ftnlen)8);
/*                                       AXIS MOVED, INDEX COUNTER */
/*                                       AND RESTART */
L1104:
    if (ishr18_1.jcnt3 >= 0) {
	goto L1106;
    } else {
	goto L1105;
    }
/*                                       COUNTER EXHAUSTED */
L1105:
    aerr_(&c__25003, "CENTR   ", (ftnlen)8);

L1106:
    --ishr18_1.jcnt3;
    goto L100;

/* ...                RESET   3-SURFACE FLAGS AND TOLERANCE BAND LIMITS */

L1108:
    if (isv1_1.j51[ifxcor_1.is - 1] <= 0) {
	goto L1120;
    } else {
	goto L1110;
    }
L1110:
    isv1_1.j50[ifxcor_1.is - 1] = 0;
    isv1_1.j51[ifxcor_1.is - 1] = 0;
    sv_1.eps8[ifxcor_1.ips - 1] = sv_1.eps1[ifxcor_1.ips - 1];
    sv_1.eps8[ifxcor_1.ids - 1] = sv_1.eps1[ifxcor_1.ids - 1];
    sv_1.eps8[ifxcor_1.is - 1] = sv_1.eps1[ifxcor_1.is - 1];
    isv1_1.notan[ifxcor_1.is - 1] = 0;

/* ...                RETURN TO CALLING PROGRAM */

L1120:
/* ... HAS TE CHANGED */
    if (teza[0] != fxcor_1.te[0] || teza[1] != fxcor_1.te[1] || teza[2] != 
	    fxcor_1.te[2]) {
	chang_1.jteneu = 1;
    } else {
	chang_1.jteneu = 0;
    }
    return 0;




/* ----------------------------------------------------------------------- */
/*     TEST CHECK SURFACE */



/*                                       BRANCH IF SURF A PLANE */
L1300:
    if (isv_1.ipl[ifxcor_1.is - 1] <= 0) {
	goto L1310;
    } else {
	goto L1330;
    }
/*                                       TEST FOR INNER OR OUTER SIDE */
L1310:
    if ((d__1 = (doublereal) ((isv_1.jtn[ifxcor_1.is - 1] << 1) - 1) * 
	    sv_1.rc[ifxcor_1.is - 1] * sv_1.s[ifxcor_1.is - 1]) < 0.) {
	goto L1315;
    } else if (d__1 == 0) {
	goto L1350;
    } else {
	goto L1320;
    }
/*                                       INNER SIDE */
L1315:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - sv_1.eps8[ifxcor_1.is - 
	    1] - 5e-6 <= 0.) {
	goto L1350;
    } else {
	goto L1360;
    }
/*                                       OUTER SIDE */
L1320:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - (sv_1.tau[ifxcor_1.is - 
	    1] - sv_1.eps8[ifxcor_1.is - 1] + znumbr_1.z5em6) <= 0.) {
	goto L1350;
    } else {
	goto L1360;
    }
/*                                       PLANE SURFACE */
/*                                       TEST INNER OR OUTER */
L1330:
    if (sv_1.s[ifxcor_1.is - 1] <= 0.) {
	goto L1340;
    } else {
	goto L1335;
    }
/*                                       INNER */
L1335:
    if (sv_1.s[ifxcor_1.is - 1] - acc - sv_1.tau1[ifxcor_1.is - 1] <= 0.) {
	goto L1350;
    } else {
	goto L1360;
    }
/*                                       OUTER */
L1340:
    if (sv_1.s[ifxcor_1.is - 1] + acc - sv_1.tau2[ifxcor_1.is - 1] >= 0.) {
	goto L1350;
    } else {
	goto L1360;
    }

/* ...                WITHIN TOLERANCE BAND */

L1350:
    jtol = 1;
    goto L1370;

/* ...                NOT WITHIN TOLERANCE BAND */

L1360:
    jtol = -1;
/*                                       RETURN */
L1370:
    switch (jtstck) {
	case 0: goto L320;
	case 1: goto L482;
	case 2: goto L550;
    }




/* ----------------------------------------------------------------------- */
/*     CPLAN SURF - OBTAIN PSEUDO CHECK SURFACE DATA FROM CPLAN */
/*                  ROUTINE */




L1400:
    cplan_();
    ifxcor_1.it = ifxcor_1.it;

/* ...                BRANCH IF CPLAN FAILURE */

    if (ishr18_1.jcpr != 0) {
	goto L1420;
    } else {
	goto L1410;
    }

/* ...                RETURN */

L1410:
    switch (jcplan) {
	case 0: goto L420;
	case 1: goto L520;
    }

/* ...                CPLAN ERROR */

L1420:
    aerr_(&c__25005, "CENTR   ", (ftnlen)8);




/* ----------------------------------------------------------------------- */
/*     ERROR -                REDUCE STEPSIZE IF POSSIBLE, AND SET */
/*                            FLAG FOR RESTART */



/*                                       BRANCH IF 3 SURFACE CALL */
L1600:
    if (isv1_1.j51[ifxcor_1.is - 1] <= 0) {
	goto L1610;
    } else {
	goto L1630;
    }
/*                                       REDUCE STEPSIZE */
L1610:
    dshar4_1.dp *= .6f;
/*                                       ERROR IF STEPSIZE .LT. TOLERANCE */
    if (dshar4_1.dp - (d__1 = sv_1.tau[ifxcor_1.is - 1], abs(d__1)) <= 0.) {
	goto L1620;
    } else {
	goto L1630;
    }
/*                                       ERROR ROUTINE */
L1620:
    aerr_(&c__25002, "CENTR   ", (ftnlen)8);
/*                                       SET FLAG FOR RESTART */
L1630:
    ishr18_1.jcr = -1;
/*                                       BRANCH TO EXIT */
    goto L1100;





} /* centr_ */

#undef kdynfl
#undef sinl
#undef cosl


