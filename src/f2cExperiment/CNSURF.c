/* CNSURF.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static doublereal c_b14 = 10.;

/* *** SOURCE FILE : M0001635.V04   *** */

/* Subroutine */ int cnsurf_(doublereal *u, doublereal *v, doublereal *b, 
	doublereal *spv, integer *iflag, integer *mmode)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal vsmal = 1e-9;
    static doublereal smal = 1e-6;
    static doublereal half = .499999;

    /* Builtin functions */
    double sqrt(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    static integer i__;
    static doublereal d1, d2, d3, u1, v1, du, dv, u1p, v1p, fac;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nct, nwd;
    static doublereal spw[32], ainc;
    static integer mode;
    extern /* Subroutine */ int eval_(char *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, ftnlen);
    static integer iext;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static char ename[8];
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal u1save, v1save;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), cnsurg_(doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *), cnsurh_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *);

/* ................................................................... */
/* ..PURPOSE   GIVEN PATCH AND PARAMETRIC COORDINATES COMPUTE THE PATCH */
/* ..          POINTS AND DERIVATIVES.  SEARCH LOGIC IS USED TO ATTEMPT */
/* ..          TO FIND A NON-ZERO SURFACE NORMAL WHEN THAT NORMAL IS TOO */
/* ..          SMALL.  WHEN PATCH COORDINATES ARE OUTSIDE THE UNIT SQUARE */
/* ..          DATA IS COMPUTED ON THE UNIT BORDER AND EXTRAPOLATED BY A */
/* ..          LINEAR BLEND FORMULA. */
/* ..ARGUMENTS */
/* ..   U,V -  INPUT  PARAMETRIC U,V COORDINATES OF PATCH. */
/* ..   B   -  INPUT PATCH COEFFICIENT ARRAY FOR BICUBIC PATCH AND PATCH */
/* ..          TYPE FLAG ( IN B(1) ) FOR GENCUR PATCH */
/* ..   SPV -  OUTPUT  POINT AND DERIVATIVES OF PATCH AT U,V POSITION */
/* ..          SPV(1-3)=POINT, SPV(5-8)=DP/DU, SPV(9-11)=DP/DV, */
/* ..          SPV(13-15)=DDP/DUU, SPV(17-19)=DDP/DUV, SPV(21-23)=DDP/DVV */
/* ..          SPV(25-27)= DP/DU X DP/DV,  SPV(29-31)=NORM OF SPV(25-27) */
/* ..          SPV(4,8,12,..)=1 IF ARRAY IS SET, =0 IF NOT SET. */
/* ..   IFLAG  INPUT MATRIX FLAGS FOR BICUBIC PATCH AND LOCAL POINTERS */
/* ..          FOR GENCUR PATCH CURVES. */
/* ..   MMODE  INPUT  =0 MEANS CALCULATE PATCH POINT ONLY. */
/* ..                 =1 MEANS CALCULATE POINT AND DERIVATIVES(SPV) */

/* ..CALLED BY APT109 BALLOC BALSRF DGEOM  PCHPRC PUVLOC SRFCOM SSPICT */
/* ..CALLS     CNSURG CNSURH CROSS  DMIN1  DMAX1  DOTV   DSQRT */
/* ..ERRORS    NO PROGRAMMED ERROR MODES. */
/* ..RESTRICTIONS */
/* ..          SEARCH LOGIC TO RETRIEVE A NON-ZERO NORMAL MAY NOT */
/* ..          SUCCEED.  IN THAT CASE NORMAL IS SET TO ZERO.  ALSO */
/* ..          SURFACE NORMAL ORIENTATION MAY BE REVERSED IN AREAS */
/* ..          OF COLLAPSING EXTENSIONS. */
/* ..LOCAL VARIABLES */
/* ..   AINC   VARIABLE TO CONTROL THE PARAMETRIC INCREMENT FOR SEARCHING */
/* ..   MODE   VARIABLE TO CONTROL NUMBER OF DERIVATIVES CALCULATED */
/* ..          =MMODE, BUT =1 ALWAYS ON LINEAR EXTENSIONS OF SURFACE */
/* ..   NCT    THE NUMBER OF SEARCH ATTEMPTS */
/* ..   SPW    A BUFFER TO HOLD CURRENT SURFACE PT AND DERIVATIVES WHILE */
/* ..          SEARCHING FOR A NON ZERO NORMAL OR EXTRAPOLATING DATA ON */
/* ..          EXTENSIONS */
/* ..   U1,V1  THE CLOSEST POINT IN THE UNIT SQUARE TO U,V */
/* ..   VSMAL  FIXED VARIABLE USED TO JUDGE WHEN A VECTOR LENGTH IS SMALL */
/* ................................................................... */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --iflag;
    --spv;
    --b;

    /* Function Body */

/* ---/STEP 1/   PREPARATION */
/* ---      SET U1,V1 TO CLOSEST POINT IN UNIT SQUARE TO U,V */
/* ---      WHEN U,V IS OUTSIDE THE UNIT SQUARE THE SURFACE POINT */
/* ---      AND DERIVATIVES ARE EXTRAPOLATED FROM DATA ON THE BORDER. */
    u1 = *u;
    v1 = *v;
    u1 = min(one,u1);
    u1 = max(zero,u1);
    v1 = min(one,v1);
    v1 = max(zero,v1);
    mode = *mmode;
    iext = 0;
    if (*u == u1 && *v == v1) {
	goto L5;
    }
/* ---      U,V IS OUTSIDE THE UNIT SQUARE, EXTRAPOLATION REQUIRED. */
    iext = 1;
    mode = 1;
L5:

/* --- NCT IS THE COUNTER WHICH KEEPS TRACK OF THE NUMBER OF TRIALS */
/* --- WITHIN CNSURF WHENEVER TROUBLE IS ENCOUNTERED IN FINDING A NORMAL */
    nct = 0;
/* ---    AINC IS STARTING FACTOR FOR ALTERATION OF U-V VALUES */
/* ---    WHILE SEARCHING FOR A NON DEGENERATE SURFACE NORMAL */
    ainc = 1e-9f;
/* ---      SAVE U1,V1 VALUES, AS THEY MAY BE CHANGED BY A SEARCH */
    u1save = u1;
    v1save = v1;

L1:
/* ---/STEP 2/   PATCH DERIVATIVES */

/* ---    EXTRACT SURFACE POINT AND DERIVATIVES AT U,V VALUES */
/* ---     INTERPOLATE SURF PT AND DERIVS AS RATIONAL BICUBIC. */
    if (iflag[1] > 9) {
	goto L7;
    }
    cnsurg_(&u1, &v1, &b[1], spw, &iflag[1], &mode);
    goto L6;
/* ---     INTERPOLATE SURF PT AND DERIVS AS GENCUR PATCH */
L7:
    if (iflag[2] == 0) {
	goto L8;
    }
    cnsurh_(&u1, &v1, &b[1], spw, &iflag[1], &mode);
    goto L6;
/* ---     INTERPOLATE SURF PT AND DERIVS AS FOREIGN PATCH */
L8:
    holfrm_(&b[1], ename, &c__1, &c__8, &nwd, (ftnlen)8);
    eval_(ename, &u1, &v1, &canon[iflag[1] - 1], spw, &mode, (ftnlen)8);

/* ---      SAVE SURFACE POINT ON FIRST PASS */
L6:
    if (nct != 0) {
	goto L3;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2: */
	spv[i__] = spw[i__ - 1];
    }
    spv[4] = one;
L3:

/* ---      SKIP NORMAL CHECKING WHEN ONLY POINT IS DESIRED */
    if (*mmode == 0) {
	goto L400;
    }
/* ---/STEP 3/   SIGNIFICANCE OF DERIVATIVES */
/* ---    EXAMINE SURFACE NORMAL FOR NON DEGENERACY */
    cross_(&spw[4], &spw[8], &spw[24]);
    dotv_(&d3, &spw[24], &spw[24]);
    d3 = sqrt(d3);
    if (d3 > vsmal) {
	goto L310;
    }
/* ---    SURFACE NORMAL MAGNITUDE IS SMALL SO EXAMINE FURTHER */
/* ---    FIND MAGNITUDES OF TANSPL AND CRSSPL VECTORS */
    dotv_(&d1, &spw[4], &spw[4]);
    d1 = sqrt(d1);
    dotv_(&d2, &spw[8], &spw[8]);
    d2 = sqrt(d2);
/* ---    IF EITHER TANGENT VECTOR IS SMALL, FIND NEW U,V */
    if (d1 < vsmal || d2 < vsmal) {
	goto L309;
    }
/* ---    FINALLY CHECK ANGULAR SPREAD BETWEEN TANSPL AND CRSSPL */
    if (d3 > smal * d1 * d2) {
	goto L310;
    }

L309:
/* ---/STEP 4/   ALTER COORDINATES */
/* ---    OBTAIN A NEW U,V AND TRY FOR A CLEARER SURFACE NORMAL */
    ++nct;
/* ---    QUIT AFTER 8 TRIALS */
    if (nct > 8) {
	goto L310;
    }
    fac = one - vsmal * pow_di(&c_b14, &nct);
    u1 = (u1save - half) * fac + half;
    v1 = (v1save - half) * fac + half;
/* ---    RECYCLE TO CHECK WHETHER NEW NORMAL IS DEFINED */
    goto L1;

/* ---/STEP 5/   CONSOLIDATE PATCH DERIVATIVES */
L310:
/* ---      RESTORE U1,V1 AND COMPUTE UNIT NORMAL */
    u1 = u1save;
    v1 = v1save;
    if (d3 == zero) {
	d3 = one;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	spw[i__ - 1] = spv[i__];
	spw[i__ + 27] = spw[i__ + 23] / d3;
/* L311: */
    }

/* ---      FINAL STEP, EXTRAPOLATE SURFACE PT AND DERIVS IF POINT */
/* ---      IS OUTSIDE THE UNIT SQUARE. */
L400:
    if (iext != 0) {
	goto L410;
    }
    if (*mmode == 0) {
	goto L490;
    }
/* ---      TRANSFER DERIVATIVES TO SPV ARRAY */
    for (i__ = 5; i__ <= 32; ++i__) {
/* L405: */
	spv[i__] = spw[i__ - 1];
    }
    goto L490;

L410:
/* ---/STEP 6/   DERIVATIVES EXTRAPOLATED TO PATCH EXTENSION. */
    du = *u - u1;
    dv = *v - v1;
/* ---      U1 IS A FUNCTION OF U.  U1P IS RATE OF CHANGE OF U1 WRT U. */
/* ---      SIMILARLY FOR V1 AND V1P. */
    u1p = zero;
    if (*u == u1) {
	u1p = one;
    }
    v1p = zero;
    if (*v == v1) {
	v1p = one;
    }
    spv[4] = one;
/* ---      EXTRAPOLATION FORMULA IS AS FOLLOWS */
/* ---      SPV = SPW + DU*SPW-U +DV*SPW-V + DU*DV*SPW-UV */
    for (i__ = 1; i__ <= 3; ++i__) {
	spv[i__] = spw[i__ - 1] + du * spw[i__ + 3] + dv * (spw[i__ + 7] + du 
		* spw[i__ + 15]);
	if (*mmode == 0) {
	    goto L430;
	}
	spv[i__ + 4] = spw[i__ + 3] + dv * spw[i__ + 15];
	spv[i__ + 8] = spw[i__ + 7] + du * spw[i__ + 15];
	spv[i__ + 12] = u1p * spw[i__ + 11];
	spv[i__ + 16] = spw[i__ + 15];
	spv[i__ + 20] = v1p * spw[i__ + 19];
L430:
	;
    }
    if (*mmode == 0) {
	goto L490;
    }
    cross_(&spv[5], &spv[9], &spv[25]);
    dotv_(&d1, &spv[25], &spv[25]);
    d1 = sqrt(d1);
    if (d1 == zero) {
	d1 = one;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L440: */
	spv[i__ + 28] = spv[i__ + 24] / d1;
    }
L490:
/* ---      SET FLAGS FOR DERIVATIVES */
    if (*mmode == 0) {
	goto L999;
    }
    for (i__ = 8; i__ <= 32; i__ += 4) {
/* L495: */
	spv[i__] = one;
    }

L999:
    return 0;
} /* cnsurf_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


