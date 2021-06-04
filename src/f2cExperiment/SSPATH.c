/* SSPATH.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    logical lgchk, lintck, lavctl, lvaxis;
} rmflgs_;

#define rmflgs_1 rmflgs_

struct {
    doublereal alpha, beta, cosa, cosb, sina, sinb;
    integer itac;
} tac_;

#define tac_1 tac_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;
static integer c__33 = 33;
static integer c__42 = 42;
static integer c_n3555 = -3555;
static integer c_n2 = -2;
static integer c__11 = 11;
static integer c__14 = 14;
static integer c__19 = 19;
static integer c__15 = 15;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__10 = 10;
static integer c__13 = 13;
static integer c__7 = 7;
static integer c_n6 = -6;
static integer c_n4 = -4;
static integer c__2 = 2;

/* *** SOURCE FILE : M0001081.W07   *** */

/* Subroutine */ int sspath_(doublereal *dsurf, integer *idtype, doublereal *
	pdir, doublereal *dtol, doublereal *dstep, doublereal *dofset, 
	doublereal *plim, integer *idtool, integer *idaxis, doublereal *daxis,
	 integer *itldir, doublereal *tldir, doublereal *psurf, doublereal *
	pside, doublereal *pthick, doublereal *ptoli, doublereal *ptolo, 
	integer *iptool, doublereal *tul, doublereal *ust, doublereal *vst, 
	doublereal *scalht, doublereal *stepov, doublereal *stepmx, 
	doublereal *amaxdp, doublereal *elmax, integer *maxcl, integer *
	iclskp, integer *iqual, doublereal *te, doublereal *ta, doublereal *
	td, doublereal *par, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-38;
    static doublereal big = 1e10;
    static doublereal half = .5;
    static doublereal zem5 = 1e-5;
    static integer iseqls = 0;
    static integer kpath = 0;

    /* Format strings */
    static char fmt_1997[] = "";
    static char fmt_1998[] = "";

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_dnnt(doublereal *);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal r__[32], w, w1, w2, dr[36], tc[3];
    static integer ir;
    static doublereal rk, rl[32], up, vp, rx[32], ww;
    extern /* Subroutine */ int bad_();
    static doublereal fac, dif, ang, rad;
    static integer mod;
    static doublereal fwd[3], tal[3], tel[3], phi, rkl, plo, tax[3], tol, tex[
	    3], upl, vpl, rxl[32], upx, vpx, gfac, drad;
    extern /* Subroutine */ int gchk_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal tbef[3];
    extern /* Subroutine */ int pchg_(doublereal *, doublereal *, doublereal *
	    );
    static integer ifin, irej;
    static doublereal emax, rvec[3], plen;
    static integer iret;
    static doublereal dist;
    static integer npat;
    static logical lret;
    static doublereal srad;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal pcur, step;
    static integer icol;
    static doublereal ptol, efrad;
    extern /* Subroutine */ int dgeom_(doublereal *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *);
    static doublereal tbefl[3];
    static integer iclct;
    extern /* Subroutine */ int avoid_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, integer *, 
	    logical *);
    static doublereal akdrv[4]	/* was [2][2] */, tbefx[3];
    static logical laret;
    static integer index, ipass;
    static doublereal akprt[6]	/* was [3][2] */, estep;
    static integer npatl;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), reset_(void);
    static doublereal stepm, stepl;
    static integer npatx;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static doublereal temov, sstep, tstep, pstep, xstep;
    extern /* Subroutine */ int clput_(doublereal *, doublereal *, integer *);
    static doublereal sdist;
    static integer jcomp;
    static doublereal pnext;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen), fconv_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static doublereal balrad;
    static char badmsg[20];
    static integer iskbal;
    extern /* Subroutine */ int balsrf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , integer *), vscale_(doublereal *, doublereal *, doublereal *), 
	    record_(integer *), intchk_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *);
    static doublereal akmxmn[2];
    static integer intloc;
    extern /* Subroutine */ int chkset_(integer *, doublereal *, doublereal *,
	     integer *), cprint_(char *, ftnlen);
    static integer iseqno, istepk;
    static doublereal tolmid, tolrng;
    static integer ipsize;
    static doublereal parnsv;
    extern /* Subroutine */ int srfdir_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), stepck_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    static doublereal tolcom;
    extern /* Subroutine */ int intmsg_(doublereal *, doublereal *, integer *)
	    , outmsg_(char *, ftnlen);
    static doublereal tbemax;
    static integer mxstep;
    extern /* Subroutine */ int srftol_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), tulpos_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);

    /* Assigned format variables */
    static char *iret_fmt;

/* --PURPOSE IS TO MOVE CUTTER IN CONTACT WITH DRIVE CURVE */
/* --DSURF WHILE SIMULTANEOUSLY MOVING IN CONTACT WITH PART */
/* --SURFACE PSURF.  THE WEALTH OF INPUT PARAMETERS ARE FOR */
/* --CONTROLLING THE RANGE , STEPOUT AND AXIS OF THE CUTTER */
/* --INPUT PARAMETERS ARE DESCRIBED BELOW */
/* --DSURF CANONICAL FORM DEFINING THE DRIVE GEOMETRY(CURVE OR SURF) */
/* --IDTYPE TYPE OF DSURF  =0 SCURV, =1 MESH SURF U LINE CONTROL */
/* --       =2 MESH SURFACE CRSSPL CONTROL */
/* --PDIR   =1 OR -1 SETS THE DIRECTION OF PATH MOTION AS INCREASING */
/* --       PARAMETER DIRECTION OR OPPOSITE */
/* --DTOL   TOLERANCE TO BE MAINTAINED OF DRIVE CURVE */
/* --DSTEP  IF=0. IT IS IGNORED */
/* --       IF POSITIVE DPARAM STEP IS THE MAXIMUM PARAM STEP LENGTH ON CU */
/* --       IF NEGATIVE, DSTEP IS A FIXED PARAMETER INCREMENT ALONG */
/* --       DRIVE CURVE.  ITT OVERIDES ALL TOL AND STEP SPECS. */
/* --DOFSET IS A FIXED DISTANCE TO DROP THE CUTTER TIP PAST THE */
/* --       DRIVE POINT ALONG THE TOOL AXIS PRIOR TO A PROJECTION */
/* --       THE PART SURFACE.  IT IS APPICABLE IN MULTI AXIS WORK. */
/* --PLIM  1 AND 2 ARE THE LOWER AND UPPER LIMITS OF THE U PARAMETER */
/* --      OF THE DRIVE GEOMETRY.  3 AND 4 ARE THE LIMITS OF THE */
/* --      V PARAMETER(CRSSPL) OF THE DRIVE GEOMETRY( IF IT IS A */
/* --      MESH STRUCTURED SCULPTURED SURFACE) */
/* --IDTOOL IS 0 FOR ON TOOL CONTROL(CUTTER AXIS THRU CURVE) */
/* --       IS 1 FOR AT TOOL CONTROL(CUTTER OFFSET FROM POINT */
/* --       WHERE TOOL AXIS PIERCES SURFACE. */
/* --IDAXIS IS 0 FOR FIXED TOOL AXIS, TOOL AXIS IN DAXIS ARRAY */
/* --       IS 1 FOR VARIABLE AXIS.  AXIS COMES FROM SURFACE NORMAL */
/* --       OR FROM SCURV CRSSPL. SIGN OF IDAXIS ORIENTS THIS VECTOR */
/* --       PROPERLY. */
/* --DAXIS CONTAINS FIXED PERMANENT AXIS FOR TOOL IF FIXED */
/* --ITLDIR 0 IF TOOL IS PROJECTED IN FIXED DIRECTION TO PART SURF */
/* --       1 OR -1 IF TOOL IS PROJECTEDACCORDING TO VARIABLE */
/* --       VECTOR FROM DRIVE GEOMETRY. */
/* --TLDIR  IS THE VECTOR WHICH HOLDS THE FIXED TOOL DIRECTION */
/* --       WHEN ITLDIR IS 0. */
/* --PSURF  CANON FORM OF PART SURFACE. */
/* --       THIS IS A SLOPE CONTINUOUS SCULPTURED SURFACE */
/* --PSIDE  1 OR -1 TO ADJUST SURFACE NORMAL( RU X RV ) TO POINT */
/* --       TOWARD TOOL OPERATING SIDE OF SURFACE. */
/* --PTHICK THICKNESS OFFSET FROM SURFACE */
/* --PTOLI,PTOLO INSIDE/OUTSIDE TOLERANCE(TOOL SIDE IS INSIDE) */
/* --IPTOOL =0 TOOL IS TO PART SURFACE */
/* --       =1 TOOL TIP IS ON SURFACE */
/* --TUL  TOOL DESCRIPTION.  PRESENTLY TUL(1)=RADIUS OF BALL CUTTER. */
/* --SCALHT IF NOT ZERO, IS THE MAXIMUM ALLOWABLE SCALLOP HEIGHT */
/* --STEPOV IS THE MAXIMUM PARAMETRIC STEPOVER(OUTPUT) TO ACHIEVE */
/* --THE SCALLOP HEIGHT SPECIFIED. */
/* --STEPMX IS THE MAXIMUM STEPOVER DISTANCE ALLOWED.  IF NEGATIVE */
/* --     IT IS THE ACTUAL PARAMETRIC STEPOVER VALUE */
/* --AMAXDP IS THE MAXIMUM TOOL STEPOUT ALLOWED */
/* --ELMAX IS THE MAXIMUM PATH LENGTH WHICH CAN BE GENERATED BY */
/* --      A SINGLE CALL TO THE SSPATH ROUTINE */
/* --MAXCL IS THE MAXIMUM NUMBER OF CL POINTS TO BE GENERATED IN PATH */
/* --ICLSKP NEGATIVE MEANS GENERATE NO CL DATA THRU CLPUT */
/* --       ZERO MEANS GENERATE ALL CLDATA */
/* --       POSITIVE MEANS GENERATE ALL CLDATA EXCEPT THE FIRST POINT */
/* --IQUAL IS A QUALITY CONTROL OPTION TO EXACTLY TOUCH THE SURFACE */
/* --       AS OPPOSED TO PLACING WITHIN TOLERANCE SHELL OF LEAST */
/* --       CURVATURE */
/* --OUTPUT */
/* --TE,TA,TD LAST GOOD TOOL END,AXIS AND DIRECTION OF PROJECTION */
/* --PAR  LAST PARAMETRIC VALUES ON THE DRIVE GEOMETRY */
/* --IRR  ERROR FLAG. NON ZERO ON RETURN FROM SSPATH IF ERROR OCCURS */


/* ---      AKMXMN THE LARGEST POSITIVE AND NEGATIVE CURVATURES */
/* ---      IN THIS CALL TO SSPATH */
/* ---      AKDRV(2,2) THE DRIVE SURFACE PARAMETERS WHERE THEY OCCURRED */
/* ---      AKPRT(2,2) THE PART SURFACE PARAMETERS WHERE THEY OCCURRED */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */

/* .... LRET - INTERFERENCE FLAG = .TRUE. IF TOOL PENETRATES PS */
/* .... LARET - AVOIDANCE FLAG = .TRUE. IF INTEFERENCE AVOIDED */


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

/* .... INTLOC - LOCATION IN INTERFERENCE TABLE OF WORST PENETRATION */

    /* Parameter adjustments */
    --par;
    --td;
    --ta;
    --te;
    --tul;
    --psurf;
    --tldir;
    --daxis;
    --plim;
    --dsurf;

    /* Function Body */

    if (ibugg_1.ibug == 11) {
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(badmsg, " ENTRY TO SSPATH ", (ftnlen)20, (ftnlen)17);
	cprint_(badmsg, (ftnlen)20);
    } else {
	goto L1997;
    }
    iret = 0;
    iret_fmt = fmt_1997;
    goto L1999;
L1997:
/* ---      COUNT OF PATH CALLS */
    record_(&iseqno);
    if (iseqno != iseqls) {
	kpath = 0;
    }
    ++kpath;
    ipass = 1;
/* ---TE,TA,TD ARE THE CURRENT TOOL END ,AXIS, AND DIRECTION */
/* ---IF PATH IS SUCCESSFUL THEY RECORD THE LAST GOOD CL VALUES */
/* ---ON RETURN TO THE CALLING ROUTINE. */
/* ---NOTE THAT TBEF(TOOL-BALL END-EFFECTIVE) IS A SIMULATED BALL */
/* ---CUTTER AT THE CORNER EDGE OF A GENERAL CUTTER.  THIS PROVIDES */
/* ---THE CAPABILITY FOR A GENERAL APT CUTTER ALTHOUGH SSPATH HAS */
/* ---BEEN IMPLEMENTED ONLY AS A BALL CUTTER ALGORITHM. */
    for (i__ = 1; i__ <= 3; ++i__) {
	te[i__] = zero;
	ta[i__] = zero;
	td[i__] = zero;
	tbef[i__ - 1] = zero;
/* L5: */
    }
/* --SET INITIAL PARAMETER VALUES */
    par[1] = *ust;
    par[2] = *vst;
    mod = -121;
    chkset_(idtype, pdir, &plim[1], &mod);
/* --RADIUS OF BALL CUTTER */
    balrad = tul[1];
/* --EFFECTIVE RADIUS FOR OFFSET OF TOOL CENTER */
    efrad = balrad + *pthick;
/* --EFFECTIVE RADIUS FOR PROJECTING DRIVE POINT TO PART SURFACE */
    drad = efrad;
    if (*iptool == 1 || *idtool == 1) {
	drad = *pthick;
    }
/* --TOOL AND PART SURFACE CONTACT PARAMETERS */
    dist = zero;
    up = half;
    vp = half;
    npat = 1;
    mxstep = 20;
/* --STEPOUT RETRY COUNT AND TOTAL CL POINTS */
    istepk = 0;
    iclct = 0;
/* --CURRENT PATH LENGTH(NOT TO EXCEED ELMAX) */
    plen = zero;
/* --STEP OUT REDUCTION FACTORS FOR RETRIES */
    stepm = one;
    fac = .75f;
/* --SUGGESTED PARAMETRIC STEPOVER */
    *stepov = big;
/* --TOLERANCE BAND PREPARATION */
    tolmid = zero;
    tolrng = zero;
    if (*iqual != 0) {
	goto L10;
    }
/* --MID TOLERANCE BAND FROM SURFACE AND TOLERANCE RANGE */
    tolmid = (*ptolo - *ptoli) * half;
    tolrng = (*ptoli + *ptolo) * .45f;
    ptol = (*ptoli + *ptolo) * .9f;
    goto L20;
L10:
/* --FOR INSPECTION PURPOSES, TOOL MAY REST ON OR TOUCH SURFACE */
    tolmid = zero;
    tolrng = zero;
    ptol = min(*ptoli,*ptolo) * 1.8f;
L20:
/* --TOLERANCE FOR SURFACE CALCULATION */
/* --IFIN IS SET TO NON ZERO WHEN PROCESSING THE LAST POINT */
    ifin = 0;
    tol = ptol * .2f;
/* --EMAX IS MAXIMUM STEP SIZE BASED ON THE PREVIOUS CUT VECTOR */
    emax = big;
/* ---    INITIAL STEPOUT VALUES */
    sstep = big;
    tstep = big;
    xstep = big;
/* --SET INDEX FOR MOVING PARAMETRIC VALUES */
    index = 1;
    if (*idtype == 2) {
	index = 2;
    }
    parnsv = smal;
/* ---      INITIALIZE VALUES FOR WORST CURVATURE ACCOUNTING */
    for (i__ = 1; i__ <= 2; ++i__) {
	for (j = 1; j <= 2; ++j) {
	    akdrv[i__ + (j << 1) - 3] = zero;
	    akprt[i__ + j * 3 - 4] = zero;
/* L51: */
	}
	akprt[i__ * 3 - 1] = zero;
/* L50: */
    }
    akmxmn[0] = zem5;
    akmxmn[1] = -akmxmn[0];
/* ---      SET FLAG FOR MODE TO SKIP SURFACE CALCULATION */
    iskbal = 0;
    if (psurf[1] != dsurf[1]) {
	goto L60;
    }
    if (abs(*dofset) > smal) {
	goto L60;
    }
    if (*idtool != 1) {
	goto L60;
    }
    iskbal = 1;
L60:

/* .... SIZE OF PART SURFACE CANONICAL FORM */
    ipsize = i_dnnt(&psurf[8]);

/* --SURFACE CONTACT BLOCK.  DROP SURFACE FROM POINT ON DRIVE GEOMETRY */
/* --TO PART SURFACE */
L100:
/* --IF IFIN IS SET TO NON ZERO THEN THIS IS THE LAST POINT */
    parnsv = par[index];
    chkset_(idtype, pdir, &par[1], &ifin);

/* --COMPUTE POINT AND VECTOR DATA FROM DRIVE GEOMETRY */
    dgeom_(&dsurf[1], idtype, &par[1], &par[2], idaxis, &daxis[1], itldir, &
	    tldir[1], dtol, dr, &upx, &vpx, &npatx, r__);

/* --COMPUTE THE TOOL CENTER AND DIRECTION AT THIS POINT */
    for (i__ = 1; i__ <= 3; ++i__) {
	td[i__] = dr[i__ + 19];
	tc[i__ - 1] = dr[i__ - 1] + (drad - *dofset) * dr[i__ + 15] + dist * 
		td[i__];
/* L110: */
    }
    if (ibugg_1.ibug != 11) {
	goto L8804;
    }
    bad_(&c__3, &c__1, "TC  ", tc, (ftnlen)4);
    bad_(&c_n3, &c__1, "TD  ", &td[1], (ftnlen)4);
L8804:
    if (iskbal == 0) {
	goto L120;
    }
/* ---      ISKBAL=1 MEANS SKIP BALSRF CALC - USE DRIVE SURFACE */
    up = upx;
    vp = vpx;
    npat = npatx;
    dist = zero;
    ir = 0;
    goto L125;
L120:

/* --FROM THIS POSITION, DROP THE TOOL TO THE SURFACE */
    balsrf_(&psurf[1], pside, tc, &drad, &td[1], &npat, &up, &vp, &dist, r__, 
	    &tol, &ipass, &ir);

L125:
    if (ibugg_1.ibug != 11) {
	goto L8805;
    }
    bad_(&c__1, &c__0, "BLSR", &ir, (ftnlen)4);
    bad_(&c__1, &c__0, "NPAT", &npat, (ftnlen)4);
    bad_(&c__1, &c__1, "UP  ", &up, (ftnlen)4);
    bad_(&c__1, &c__1, "VP  ", &vp, (ftnlen)4);
    bad_(&c_n1, &c__1, "DIST", &dist, (ftnlen)4);
    bad_(&c__3, &c__1, "R   ", r__, (ftnlen)4);
    bad_(&c_n3, &c__1, "RN  ", &r__[28], (ftnlen)4);
L8805:
/* ****    ERROR */
    *irr = 1;
    if (ipass == 1 && ir != 0) {
	goto L999;
    }
/* --AFTER THE FIRST CUT VECTOR, MOVE TO REDUCED STEPOUT LOGIC */
    if (ipass == 0 && ir != 0) {
	goto L230;
    }

/* --COMPUTE WHETHER CUTTER DOES FIT THE SURFACE AT THIS POINT */
    srfdir_(dr, r__, pside, pdir, rx, rvec, &rk, &ir);
/* ---      REJECT POINT BASED ON CURVATURE FIT SOMETIMES */
    irej = 0;
/* --TOOL MUST NOT VIOLATE EITHER OF TWO PRINCIPAL CURVATURES */
    for (i__ = 1; i__ <= 2; ++i__) {

/* ---      SAVE WORST CURVATURE VALUES AS ENCOUNTERED */
	for (j = 1; j <= 2; ++j) {
/* ---      RX AND AKMXMN SHOULD HAVE THE SAME SIGN */
	    if (rx[i__ - 1] * akmxmn[j - 1] <= zero) {
		goto L145;
	    }
/* ---      SAVE RX IF IT IS LARGER */
	    if ((d__1 = rx[i__ - 1], abs(d__1)) < (d__2 = akmxmn[j - 1], abs(
		    d__2))) {
		goto L145;
	    }

	    akmxmn[j - 1] = rx[i__ - 1];
	    if (rx[i__ - 1] > zero) {
		akdrv[(j << 1) - 2] = par[1];
	    }
	    if (rx[i__ - 1] > zero) {
		akdrv[(j << 1) - 1] = par[2];
	    }
	    akprt[j * 3 - 3] = (doublereal) npat;
	    akprt[j * 3 - 2] = up;
	    akprt[j * 3 - 1] = vp;
L145:
	    ;
	}

/* ---      SKIP CURVATURE CHECK IF ISKBAL IS 1. */
	if (iskbal == 1) {
	    goto L140;
	}
/* ---      IF TOOL IS ON PS, THEN SKIP CURVATURE CALCULATION */
	if (*iptool == 1) {
	    goto L140;
	}
	if (rx[i__ - 1] <= smal) {
	    goto L140;
	}
	srad = 1 / rx[i__ - 1];
	if (srad < efrad) {
	    irej = 1;
	}
L140:
	;
    }
/* ---      IF CONDITION IS REJECT, REATTEMPT STEPOUT */
    if (irej == 1) {
	goto L230;
    }

/* --VERIFY STEPOUT VS TOLERANCE.  CUT BACK STEPOUT AND RETRY */
/* --IF NECESSARY */
/* L200: */
/* --FOR FIRST POINT OR FIXED PARAMETER STEP, SKIP THIS */
    if (ipass == 1 || *dstep < zero) {
	goto L400;
    }

    tulpos_(r__, pside, dr, &tul[1], pthick, &zero, iptool, idtool, tex, tax, 
	    tbefx, pdir);
/* --NEW CANDIDATE TOOL END TOOL AXIS IS TEX,TAX */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L220: */
	tex[i__ - 1] = tbefx[i__ - 1] - tbef[i__ - 1];
    }
    dotf_(&estep, tex, tex);
    estep = sqrt(estep);
/* --CHECK WHETHER THIS TOOL STEP IS ACCEPTABLE */
    stepck_(pside, r__, rx, &rk, rl, rxl, &rkl, &efrad, &ptol, &sstep, &tstep)
	    ;
    if (estep < tstep && estep < *amaxdp) {
	goto L400;
    }
L230:
    stepl = step;
    step *= fac;
/* --CUT DOWN STEPOUT AND TRY AGAIN */
L240:
    ifin = 0;
    ++istepk;
/* ****    ERROR */
    *irr = 2;
    if (istepk > mxstep) {
	goto L999;
    }
    goto L610;

/* --ACCEPT THE CURRENT TOOL POSITION, TERMINATE IF IFIN NOT ZERO */
L400:
/* --PLACE CUTTER NEAR PROPER SHELL OF TOLERANCE BAND */
    tolcom = tolmid;
    if (rk < zero) {
	tolcom = tolmid + tolrng;
    }
    if (rk > zero) {
	tolcom = tolmid - tolrng;
    }
    if (abs(rk) < smal) {
	tolcom = tolmid;
    }
    if (*iqual == 1) {
	tolcom = zero;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	tbefl[i__ - 1] = tbef[i__ - 1];
	tel[i__ - 1] = te[i__];
/* L410: */
	tal[i__ - 1] = ta[i__];
    }
/* --FIND NEW TE,TA */
    tulpos_(r__, pside, dr, &tul[1], pthick, &tolcom, iptool, idtool, &te[1], 
	    &ta[1], tbef, pdir);
/* --CARRYOUT GOUGE CHECKING IF REQUIRED */
    if (rmflgs_1.lgchk && ipass != 1 && *iqual != 1) {
	gchk_(&psurf[1], pside, r__, &te[1], &ta[1], &npat, &up, &vp, rl, tel,
		 tal, &npatl, &upl, &vpl, &tolcom, ptoli, ptolo, &gfac, &iret)
		;
	if (iret != 0) {
/* --EITHER GOUGING OCCURS OR MATERIAL IS LEFT ON */
/*  REDUCE STEPOUT UNLESS FIXED PARAMETRIC STEP */
	    if (*dstep < zero) {
		if (iret > 0) {
		    cform_(" *** WARNING - GOUGING OCCURS ***", 
			    darray_1.darray, &c__1, &c__33, (ftnlen)33, (
			    ftnlen)120);
		} else {
		    cform_(" *** WARNING - EXCESS MATERIAL LEFT ON ***", 
			    darray_1.darray, &c__1, &c__42, (ftnlen)42, (
			    ftnlen)120);
		}
		cprint_(darray_1.darray, (ftnlen)120);
		bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
		bad_(&c_n3, &c__1, "TEL ", tel, (ftnlen)4);
	    } else {
		stepl = step;
		step *= gfac;
/* .... RESTORE PREVIOUS VALUES OF TE,TA AND TBEF */
		for (i__ = 1; i__ <= 3; ++i__) {
		    te[i__] = tel[i__ - 1];
		    ta[i__] = tal[i__ - 1];
		    tbef[i__ - 1] = tbefl[i__ - 1];
/* L415: */
		}
		goto L240;
	    }
	}
    }

/* .... CARRY OUT INTERFERENCE CHECKING IF REQUIRED */

    if (rmflgs_1.lintck) {
	intchk_(&psurf[1], &ipsize, pside, pthick, ptoli, &tul[1], &te[1], &
		ta[1], r__, &npat, &up, &vp, &lret, &intloc);
	if (lret) {
/* .... INTEFERENCE HAS BEEN DETECTED - PRINT DETAILS OF INTEFERENCE */
	    intmsg_(&te[1], &ta[1], &intloc);
	    if (rmflgs_1.lavctl) {
/* .... AVOIDANCE CONTROL REQUESTED */
/*     COMPUTE GUIDE SURFACE FORWARD DIRECTION */
		vscale_(pdir, &dr[12], fwd);
		avoid_(&psurf[1], &ipsize, pside, pthick, ptoli, ptolo, &
			tolcom, fwd, &tul[1], &te[1], &ta[1], r__, &npat, &up,
			 &vp, &intloc, &laret);
		if (laret) {
		    outmsg_("INTERFERENCE AVOIDED", (ftnlen)20);
		} else {
		    error_(&c_n3555, "SSPATH  ", (ftnlen)8);
		}
	    }
	}
/* .... RESET INTEFERENCE TABLE */
	reset_();
    }
/* --COMPUTE TOOL END DISTANCE */
    tbemax = zero;
    temov = zero;
    if (ipass == 1) {
	goto L430;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L420: */
	tex[i__ - 1] = te[i__] - tel[i__ - 1];
    }
    dotf_(&temov, tex, tex);
    for (i__ = 1; i__ <= 3; ++i__) {
	tex[i__ - 1] = tbef[i__ - 1] - tbefl[i__ - 1];
/* L425: */
    }
    dotf_(&tbemax, tex, tex);
    tbemax = sqrt(tbemax);

    temov = sqrt(temov);
L430:
/* --SAVE OLD SURFACE CONTACT DATA */
    for (i__ = 1; i__ <= 32; ++i__) {
	rl[i__ - 1] = r__[i__ - 1];
	rxl[i__ - 1] = rx[i__ - 1];
/* L440: */
    }
    rkl = rk;
/* --SAVE PATCH NO, U,V OF THIS SURFACE POINT */
    npatl = npat;
    upl = up;
    vpl = vp;
    if (ibugg_1.ibug != 11) {
	goto L8806;
    }
    bad_(&c__1, &c__0, "ICLT", &iclct, (ftnlen)4);
    bad_(&c__1, &c__0, "ISTK", &istepk, (ftnlen)4);
    bad_(&c__1, &c__1, "TEMV", &temov, (ftnlen)4);
    bad_(&c__1, &c__1, "ESTP", &estep, (ftnlen)4);
    bad_(&c_n1, &c__1, "PSTP", &pstep, (ftnlen)4);
L8806:
/* .... IF AXIS/ATANGL,PS,.. TOOL AXIS CONTROL - SAVE CURRENT TA */
/*     AS INITIAL TA FOR NEXT CUTTER LOCATION */
    if (tac_1.itac == 2) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    daxis[i__] = ta[i__];
/* L445: */
	}
    }
/* --RESET COUNTERS AND CHECK PATH LIMITS */
    istepk = 0;
    ++iclct;
/* ****    ERROR */
    *irr = 3;
    if (iclct > *maxcl) {
	goto L999;
    }
    plen += temov;
/* ****    ERROR */
    *irr = 4;
    if (plen > *elmax) {
	goto L999;
    }
/* ---IF ICLSKP IS NEGATIVE, THEN DO NOT RECORD CL VALUES */
    if (*iclskp < 0) {
	goto L450;
    }
    if (*maxcl == 1) {
	ifin = 1;
    }
    if (ipass != 1 || *iclskp != 1) {
	clput_(&te[1], &ta[1], &ifin);
    }
L450:
    ipass = 0;
    emax = tbemax * 5.;
    if (iclct == 1) {
	emax = *amaxdp;
    }

/* --SCALOP HEIGHT CALCULATION */
/* --SKIP SCALOP HEIGHT CALCULATION FOR CURVE DRIVE ELEMENT */
    if (*idtype == 0) {
	goto L510;
    }
/* --PROCEED TO NORMAL SCALOP CALC IF SCALHT IS NOT SMALL */
    if (*scalht > smal) {
	goto L530;
    }
/* --SCALLOP HEIGHT SMALL, USE STEPMX TO DETERMINE STEPOVER */
    sdist = *stepmx;
/* --IF STEPMX IS POSITIVE, THEN STEPOVER BY THIS DISTANCE */
    if (*stepmx > smal) {
	goto L540;
    }
/* --STEPMX NEGATIVE AND SIGNIFICANT MEANS A FIXED PARAMETRIC STEPOVER */
    sdist = abs(*stepmx);
    *stepov = sdist;
    if (sdist > smal) {
	goto L550;
    }
/* ****    ERROR IN SCALLOP HEIGHT CALCULATION */
    sdist = one;
    *stepov = sdist;
    goto L550;

L530:
/* --NORMAL SCALLOP HEIGHT CALCULATION */
/* --NEGATIVE STEPMX IS A LIMIT ON THE PARAMETRIC SIDE STEP. */
    if (*stepmx < zero) {
	*stepov = abs(*stepmx);
    }
/* Computing 2nd power */
    d__1 = balrad;
/* Computing 2nd power */
    d__2 = balrad - *scalht;
    sdist = d__1 * d__1 - d__2 * d__2;
    sdist = max(smal,sdist);
/* --SDIST IS THE PHYSICAL STEPOVER DISTANCE TO ACHIEVE SPECS. */
    sdist = sqrt(sdist) * 2.f;
L540:
    if (*stepmx > zero) {
	sdist = min(*stepmx,sdist);
    }
/* --CONVERT PHYSICAL SDIST INTO A PARAMETRIC SDIST FOR DRIVE SURFACE */
    jcomp = 9;
    if (*idtype == 2) {
	jcomp = 5;
    }
    dotf_(&ang, &dr[32], &r__[28]);
    ang = abs(ang);
    ang = max(smal,ang);
    sdist /= ang;
    dotf_(&w, &r__[jcomp - 1], &r__[jcomp - 1]);
    w = sqrt(w);
    w = max(smal,w);
    sdist /= w;
L550:
/* --STEPOV IS A LIMIT ON THE PARAMETRIC STEPOVER */
    *stepov = min(*stepov,sdist);
/* L520: */
    if (ibugg_1.ibug != 11) {
	goto L8811;
    }
    bad_(&c__1, &c__1, "STOV", stepov, (ftnlen)4);
    bad_(&c__1, &c__1, "SDST", &sdist, (ftnlen)4);
    bad_(&c__1, &c__1, "SCLH", scalht, (ftnlen)4);
    bad_(&c_n1, &c__1, "BRAD", &balrad, (ftnlen)4);
L8811:
L510:

    *irr = 0;
    if (*maxcl == 1) {
	goto L999;
    }
    if (ifin != 0) {
	goto L999;
    }

/* --IF IFIN IS ZERO, ESTIMATE NEXT STEPOUT DISTANCE AND THEN */
/* --OBTAIN PARAMETRIC STEP CHANGE TO ESTIMATE THIS. */
    srftol_(&rk, &efrad, &ptol, &xstep, &estep);

/* L600: */
/* --COMPUTE THE NEW PARAMETRIC STEPSIZE PAR(1-2) */
/* --PAR SHOULD GENERATE A NEW DRIVE POINT SO THAT THE DESIRED */
/* --TOOL END STEP ESTEP IS ACHIEVED */
/* --IF DTOL IS GT ZERO, DTOL IS TOLERANCE OF DRIVE GEOM */
/* --DSTEP GT ZERO LIMITS THE MAXIMUM PARAMETRIC STEP SIZE */
/* --IF DSTEP GT ZERO AND DTOL=0 THEN DSTEP IS THE STEP */
/* --FOR GENERAL TOLERANCE CALCULATIONS AN ATTEMPT IS MADE */
/* --TO APPROACH EACH ARC JUNCTION WITHOUT EXTREME MOVES */

    ifin = 0;
    if (istepk == 0) {
	step = xstep * .95f * tstep / sstep;
    }
    if (istepk > 0) {
	step = estep * .95f;
    }
    if (emax > .1) {
	step = min(step,emax);
    }
    step = min(*amaxdp,step);
L610:
/* --ADJUST PSTEP IF PAR HAD BEEN CUT BACK BY CHKSTEP */
    dif = parnsv - par[index];
    if (abs(dif) > smal) {
	pstep -= abs(dif);
    }
/* --CUT BACK PARAMETER VALUE IF THE LAST STEP SIZE WAS NG */
    if (istepk > 0) {
	par[index] -= *pdir * pstep;
    }
    pcur = par[index];
    plo = plim[(index << 1) - 1];
    phi = plim[index * 2];
    pstep = abs(*dstep);
    if (*dtol == zero && *dstep != zero) {
	goto L640;
    }

/* --STEP IS THE PHYSICAL SURFACE MOVE DESIRED ACROSS THE PART SURFACE */
/* --THIS MUST BE CONVERTED INTO PSTEP - THE CORRESPONDING PARAMETRIC */
/* --MOVE ALONG THE DRIVE CURVE. STEP IS LIMITED BY DSTEP(GT.0) AND */
/* --PSTEP IS LIMITED BY DR(27) AND DSTEP(LT.0). */
    dotf_(&w1, &dr[12], rvec);
    dotf_(&w2, &dr[4], &dr[4]);
    w2 = sqrt(w2);
    w1 = (d__1 = w1 * w2, abs(d__1));
    w1 = max(smal,w1);

    pstep = step / w1;
    if (dr[26] > smal) {
	pstep = min(pstep,dr[26]);
    }
    ww = abs(*dstep);
    if (*dstep > zero) {
	pstep = min(pstep,ww);
    }
    pnext = pcur + *pdir * pstep;
/* --CUT BACK THE SUGGESTED PARAMETER CHANGE SO THAT ALL CURVE */
/* --ARC JUNCTIONS ARE USED AND APPROACHED SMOOTHLY */
    pchg_(&pcur, pdir, &pstep);
L640:
    par[index] += *pdir * pstep;
    if (ibugg_1.ibug != 11) {
	goto L8807;
    }
    bad_(&c__1, &c__1, "STEP", &step, (ftnlen)4);
    bad_(&c__1, &c__1, "PSTP", &pstep, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", &par[1], (ftnlen)4);
L8807:
    goto L100;

/* --   END OF PROCESSING */

L999:
/* ---      WRITE OUT SUMMARY OF CURVATURE ETC FOR THIS PATH CALL */
    record_(&iseqno);
    if (iseqno == iseqls) {
	goto L1995;
    }
/* ---      WRITE HEADER FOR DATA */
    iseqls = iseqno;
    bad_(&c_n1, &c__0, "PATH", &iseqno, (ftnlen)4);
    icol = 1;
    cform_(" NO. ERRNO.", darray_1.darray, &icol, &c__11, (ftnlen)11, (ftnlen)
	    120);
    icol = 13;
    cform_("CLCT PATH LEN.", darray_1.darray, &icol, &c__14, (ftnlen)14, (
	    ftnlen)120);
    icol = 29;
    cform_("RADIUS/SURF   PATCH", darray_1.darray, &icol, &c__19, (ftnlen)19, 
	    (ftnlen)120);
    icol = 48;
    cform_("  U-SRF   V-SRF", darray_1.darray, &icol, &c__15, (ftnlen)15, (
	    ftnlen)120);
    icol = 64;
    cform_(" U-DRV   V-DRV", darray_1.darray, &icol, &c__14, (ftnlen)14, (
	    ftnlen)120);
    icol = 80;
    cform_("RADIUS/SURF   PATCH", darray_1.darray, &icol, &c__19, (ftnlen)19, 
	    (ftnlen)120);
    icol = 99;
    cform_("  U-SRF   V-SRF", darray_1.darray, &icol, &c__15, (ftnlen)15, (
	    ftnlen)120);

    cprint_(darray_1.darray, (ftnlen)120);
L1995:
    icol = 2;
    iconv_(&kpath, darray_1.darray, &icol, &c__4, (ftnlen)120);
    icol += 5;
    iconv_(irr, darray_1.darray, &icol, &c__5, (ftnlen)120);
    icol += 6;
    iconv_(&iclct, darray_1.darray, &icol, &c__4, (ftnlen)120);
    icol += 5;
    fconv_(&plen, darray_1.darray, &icol, &c__10, &c__3, (ftnlen)120);
    icol += 11;
    for (j = 1; j <= 2; ++j) {
	rad = (d__1 = akmxmn[j - 1], abs(d__1));
	rad = max(zem5,rad);
	rad = min(big,rad);
	if (akmxmn[j - 1] < zero) {
	    rad = -rad;
	}
	rad = 1 / rad;
	fconv_(&rad, darray_1.darray, &icol, &c__13, &c__4, (ftnlen)120);
	icol += 14;
	npat = (integer) akprt[j * 3 - 3];
	iconv_(&npat, darray_1.darray, &icol, &c__4, (ftnlen)120);
	icol += 5;
	fconv_(&akprt[j * 3 - 2], darray_1.darray, &icol, &c__7, &c__3, (
		ftnlen)120);
	icol += 8;
	fconv_(&akprt[j * 3 - 1], darray_1.darray, &icol, &c__7, &c__3, (
		ftnlen)120);
	icol += 8;
	if (j > 1) {
	    goto L1994;
	}
	fconv_(akdrv, darray_1.darray, &icol, &c__7, &c__3, (ftnlen)120);
	icol += 8;
	fconv_(&akdrv[1], darray_1.darray, &icol, &c__7, &c__3, (ftnlen)120);
	icol += 8;
L1994:
	;
    }

    cprint_(darray_1.darray, (ftnlen)120);
    if (ibugg_1.ibug != 11) {
	goto L1998;
    }
    iret = 1;
    iret_fmt = fmt_1998;
    goto L1999;
L1998:
    return 0;

/* --INPUT/OUTPUT PRINT AREA */
L1999:
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c_n6, &c__1, "DSRF", &dsurf[1], (ftnlen)4);
    bad_(&c__1, &c__0, "IDTY", idtype, (ftnlen)4);
    bad_(&c__1, &c__1, "PDIR", pdir, (ftnlen)4);
    bad_(&c__1, &c__1, "DTOL", dtol, (ftnlen)4);
    bad_(&c__1, &c__1, "DSTP", dstep, (ftnlen)4);
    bad_(&c_n1, &c__1, "DOFS", dofset, (ftnlen)4);
    bad_(&c_n4, &c__1, "PLIM", &plim[1], (ftnlen)4);
    bad_(&c__1, &c__0, "IDTL", idtool, (ftnlen)4);
    bad_(&c__1, &c__0, "IDAX", idaxis, (ftnlen)4);
    bad_(&c_n4, &c__1, "DAXI", &daxis[1], (ftnlen)4);
    bad_(&c__1, &c__0, "ITLD", itldir, (ftnlen)4);
    bad_(&c_n3, &c__1, "TLDR", &tldir[1], (ftnlen)4);
    bad_(&c_n6, &c__1, "PSRF", &psurf[1], (ftnlen)4);
    bad_(&c__1, &c__1, "SIDE", pside, (ftnlen)4);
    bad_(&c__1, &c__1, "THCK", pthick, (ftnlen)4);
    bad_(&c__1, &c__1, "PTLI", ptoli, (ftnlen)4);
    bad_(&c__1, &c__1, "PTLO", ptolo, (ftnlen)4);
    bad_(&c__1, &c__1, "TUL ", &tul[1], (ftnlen)4);
    bad_(&c_n1, &c__1, "UST ", ust, (ftnlen)4);
    bad_(&c__1, &c__1, "VST ", vst, (ftnlen)4);
    bad_(&c__1, &c__1, "SCHT", scalht, (ftnlen)4);
    bad_(&c__1, &c__1, "STOV", stepov, (ftnlen)4);
    bad_(&c__1, &c__1, "STMX", stepmx, (ftnlen)4);
    bad_(&c__1, &c__1, "MXDP", amaxdp, (ftnlen)4);
    bad_(&c_n1, &c__1, "ELMX", elmax, (ftnlen)4);
    bad_(&c__1, &c__0, "MXCL", maxcl, (ftnlen)4);
    bad_(&c__1, &c__0, "ISKP", iclskp, (ftnlen)4);
    bad_(&c__1, &c__0, "QUAL", iqual, (ftnlen)4);
    bad_(&c_n3, &c__1, "TD  ", &td[1], (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", &ta[1], (ftnlen)4);
    bad_(&c__1, &c__0, "IPTL", iptool, (ftnlen)4);
    bad_(&c__2, &c__1, "PAR ", &par[1], (ftnlen)4);
    bad_(&c_n1, &c__0, "IRR ", irr, (ftnlen)4);
    switch (iret) {
	case 0: goto L1997;
	case 1: goto L1998;
    }
} /* sspath_ */

