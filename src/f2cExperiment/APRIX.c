/* APRIX.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001032.W01   *** */

/* Subroutine */ int aprix_(doublereal *du, doublereal *dv, doublereal *dt, 
	doublereal *spv, doublereal *tp, doublereal *tn, integer *mode, 
	integer *ilev, integer *irr, integer *idebug)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal big0 = 1e13;
    static doublereal big = 1e19;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal vsmal = 1e-20;
    static doublereal ergood = .8;
    static integer mxct = 15;
    static doublereal erchk = .05;
    static doublereal disck = 8e-4;
    static doublereal erchk2 = .15;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal ac[3], at[3], au[3], av[3], eu, ev, et, fu, fv, ft;
    extern /* Subroutine */ int bad_();
    static doublereal dif[3], vec[3];
    static integer ict;
    static doublereal euv;
    extern doublereal det3_(doublereal *, doublereal *, doublereal *);
    static doublereal disc, vecu[3], vecv[3], temp, wval;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal eusq, evsq, errat;
    static char badmsg[20];
    static doublereal errlas;
    extern /* Subroutine */ int cprint_(char *, ftnlen);

/* ---      PURPOSE IS TO COMPUTE INTERSECTION BETWEEN SURFACE */
/* ---      DIFFERENTIAL FORM AND EXTERNAL TOOL RAY. */
/* --- INPUT U,V   FOR REFERENCE ONLY, CURRENT SURFACE PARAMETRIC COORDS. */
/* --- INPUT SPV   SURFACE POINT SPV 1-3, SPV-U 5-7, SPV-V 9-11, */
/* ---             SPV-UU 13-15, SPV-UV 17-19, SPV-VV 21-23, */
/* ---             SPV- SPU-U X SPV-V 25-27, SPV UNIT NORMAL 29-31 */
/* --- INPUT TP    CURRENT EXTERIOR (TOOL) POINT */
/* --- INPUT TN    IF MODE.NE.0, TN IS THE TOOL RAY VECTOR */
/* --- INPUT MODE  IF MODE.EQ.0, COMPUTE CLOSEST POINT TO TP. */
/* ---       MODE  IF MODE.NE.0 COMPUTE CLOSEST POINT(INTERSECTION) WITH */
/* --              TOOL RAY FROM POINT TP IN DIRECTION TN. */
/* --- INPUT ILEV  CONTROLS WHICH PHASES OF APRIX ARE USED */
/* ---       ILEV.LE.1 MEANS QUIT AFTER PHASE 1. */
/* ---       ILEV.EQ.2 MEANS DO BOTH PHASE 1 AND PHASE 2 */
/* ---       ILEV.GE.3 MEANS USE DU,DV AS INPUT AND GO TO PHASE 2. */
/* --- OUTPUT DU,DV SUGGESTED CHANGE IN U,V TO PROVIDE ANSWER */
/* --- OUTPUT DT    IF MODE.NE.0, DT IS THE SCALAR TP+DT*TN FOR RAY INTERS */
/* --- OUTPUT IRR  ERROR CODE.  IF IRR.EQ.0, THEN NO ERROR OCCURRED. */
/* --- OUTPUT IDEBUG IF NOT ZERO, THEN PRINT DEBUGGING OUTPUT */


    /* Parameter adjustments */
    --tn;
    --tp;
    --spv;

    /* Function Body */
/* ---      ERGOOD IS THE FACTOR FOR IMPROVEMENT IN ERROR WHICH IS */
/* ---      NECESSARY TO CONTINUE WITH THE SECOND ORDER ITERATION. */
/* ---      MAXIMUM NUMBER OF SECOND ORDER ITERATIONS ALLOWED */
/* ---      ERCHK2 IS A MORE LIBERAL ACCEPTANCE CRITERIA FOR */
/* ---      SECOND ORDER ITERATION ERROR THAN ERCHK. */


    if (*idebug == 0) {
	goto L5;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " ENTRY TO APRIX", (ftnlen)20, (ftnlen)15);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__0, "ILEV", ilev, (ftnlen)4);
    bad_(&c__1, &c__0, "MODE", mode, (ftnlen)4);
    bad_(&c__1, &c__1, "DU  ", du, (ftnlen)4);
    bad_(&c_n1, &c__1, "DV  ", dv, (ftnlen)4);
L5:

    *irr = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	dif[i__ - 1] = tp[i__] - spv[i__];
/* L10: */
    }

    if (*ilev >= 3) {
	goto L200;
    }
/* ---      DETERMINE DU,DV,DT SO THAT */
/* ---  (SPV+DU*SPV-U +DV*SPV-V - TP -DT*TN) **2 = MINIMUM. */

    dotv_(au, &spv[5], &spv[5]);
    dotv_(&au[1], &spv[5], &spv[9]);
    av[0] = au[1];
    dotv_(&av[1], &spv[9], &spv[9]);
    dotv_(ac, dif, &spv[5]);
    dotv_(&ac[1], dif, &spv[9]);
/* ---      CONTINUE WITH FURTHER COEFFICIENT CALCULATION IF MODE.NE.0 */
    if (*mode != 0) {
	goto L50;
    }
/* ---       FIRST COMPLETE 3X3 COEFFICIENTS */
    au[2] = zero;
    av[2] = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	at[i__ - 1] = zero;
    }
    ac[2] = zero;
/* ---      FIND CLOSEST POINT BETWEEN TP AND SPV+DU*SPU+DV*SPV. */
/* Computing 2nd power */
    d__1 = au[1];
    disc = au[0] * av[1] - d__1 * d__1;
    *irr = 1;
    if (abs(disc) < vsmal) {
	goto L1000;
    }
    *du = (ac[0] * av[1] - ac[1] * av[0]) / disc;
    *dv = (au[0] * ac[1] - au[1] * ac[0]) / disc;
    *dt = zero;
    goto L100;

L50:
/* ---      CALCULATE 3 X 3 COEFFICIENTS FOR SPV+DU*SPU+DV*SPV-TP-DT*TN=MI */
    dotv_(&au[2], &spv[5], &tn[1]);
    dotv_(&av[2], &spv[9], &tn[1]);
    at[0] = -au[2];
    at[1] = -av[2];
    dotv_(&at[2], &tn[1], &tn[1]);
    at[2] = -at[2];
    dotv_(&ac[2], dif, &tn[1]);

    disc = det3_(au, av, at);
    *irr = 2;
    if (abs(disc) < vsmal) {
	goto L1000;
    }

    *du = det3_(ac, av, at) / disc;
    *dv = det3_(au, ac, at) / disc;
    *dt = det3_(au, av, ac) / disc;

L100:

    if (*idebug == 0) {
	goto L110;
    }
    bad_(&c__1, &c__1, "DU  ", du, (ftnlen)4);
    bad_(&c__1, &c__1, "DV  ", dv, (ftnlen)4);
    bad_(&c__1, &c__1, "DT  ", dt, (ftnlen)4);
    bad_(&c__1, &c__1, "DISC", &disc, (ftnlen)4);
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " EXIT FROM APRIX", (ftnlen)20, (ftnlen)16);
    cprint_(badmsg, (ftnlen)20);
L110:
/* ---      IF DU,DV, OR DT ARE TOO LARGE, TEHN AVOID 2ND ORDER CALCULATIO */
/* ---      AVOID A POSSIBLE OVERFLOW CONDITION */
    if (abs(*du) + abs(*dv) + abs(*dt) > big0) {
	goto L2000;
    }


    if (*ilev <= 1) {
	goto L2000;
    }

L200:
/* ---      BEGIN SECOND PHASE OF APRIX ALGORITHM */

/* ---      FOLLOW 1ST ORDER SOLN WITH 2ND ORDER NEWTON RAPHSON ITERATION */
/* ---   (SP+DU*SPU+DV*SPV+DU**2*SPUU/2+DU*DV*SPUV+DV**2*SPVV-TP-DT*TN)**2 */
/* ---    SHOULD BE REPETITIVELY EVALUATED TO REACH A MINIMUM. */
/* ---    ABOVE EXPRESSION IS CALLED W(DU,DV,DT)=VEC(DU,DV,DT)**2 */

    eu = *du;
    ev = *dv;
    et = *dt;
    ict = 0;

L210:
/* ---      COMPUTE COEFFICIENTS FOR EFFICIENCY */
/* Computing 2nd power */
    d__1 = eu;
    eusq = d__1 * d__1 / two;
    euv = eu * ev;
/* Computing 2nd power */
    d__1 = ev;
    evsq = d__1 * d__1 / two;

    ++ict;
    if (ict <= mxct) {
	goto L300;
    }
/* ---      MXCT EXCEEDED, ERROR IF ILEV IS GE 3 */
    *irr = 3;
    if (*ilev >= 3) {
	goto L1000;
    }
/* ---      MXCT EXCEEDED, ACCEPT LINEAR ESTIMATE */
    eu = *du;
    ev = *dv;
    et = *dt;
    goto L400;

L300:
/* ---      EVALUATE VEC-U,VEC-V, VEC-UU ETC. */
    for (i__ = 1; i__ <= 3; ++i__) {
	vec[i__ - 1] = -dif[i__ - 1] + eu * spv[i__ + 4] + ev * spv[i__ + 8] 
		+ eusq * spv[i__ + 12] + euv * spv[i__ + 16] + evsq * spv[i__ 
		+ 20] - et * tn[i__];
	vecu[i__ - 1] = spv[i__ + 4] + eu * spv[i__ + 12] + ev * spv[i__ + 16]
		;
	vecv[i__ - 1] = spv[i__ + 8] + eu * spv[i__ + 16] + ev * spv[i__ + 20]
		;
/* ---      VECUU=SPV(12+I)=SPUU */
/* ---      VECUV=SPV(16+I)=SPUV */
/* ---      VECVV=SPV(20+I)=SPVV */
/* ---      VECTU=VECTV=VECTT=0 */
/* L310: */
    }

/* ---      W(DU,DV,DT)=VEC(DU,DV,DT)**2 */
/* ---      COMPUTE ALL 2ND ORDER PARTIALS OF W FROM VEC AND VEC PARTIALS */

    for (i__ = 1; i__ <= 3; ++i__) {
	au[i__ - 1] = zero;
	av[i__ - 1] = zero;
	at[i__ - 1] = zero;
	ac[i__ - 1] = zero;
/* L320: */
    }

    dotv_(&wval, vec, vec);
    wval = sqrt(wval);
    if (*idebug == 0) {
	goto L322;
    }
    bad_(&c__1, &c__1, "DIST", &wval, (ftnlen)4);
    bad_(&c_n3, &c__1, "TPSP", vec, (ftnlen)4);
L322:
    dotv_(ac, vec, vecu);
    dotv_(&ac[1], vec, vecv);
    ac[0] = -ac[0];
    ac[1] = -ac[1];
    dotv_(&temp, vecu, vecu);
    dotv_(au, vec, &spv[13]);
    au[0] += temp;
    dotv_(&temp, vecu, vecv);
    dotv_(&au[1], vec, &spv[17]);
    au[1] += temp;
    av[0] = au[1];
    dotv_(&temp, vecv, vecv);
    dotv_(&av[1], vec, &spv[21]);
    av[1] += temp;
/* ---      TERMINATE 2ND ORDER ALGORITHM IF ANY COEFFICIENT IS LARGE */
    if (abs(ac[0]) > big) {
	goto L2000;
    }
    if (abs(ac[1]) > big) {
	goto L2000;
    }
/* ---      COEFFICIENTS ARE COMPLETE FOR 2X2 CASE, I.E. MODE.EQ.0 */
    if (*mode != 0) {
	goto L330;
    }

/* Computing 2nd power */
    d__1 = au[1];
    disc = au[0] * av[1] - d__1 * d__1;
/* ---      IF DISC IS TOO SMALL ACCEPT FIRST ORDER ANSWER */
    if (disc < disck) {
	goto L410;
    }
    fu = (ac[0] * av[1] - ac[1] * av[0]) / disc;
    fv = (au[0] * ac[1] - au[1] * ac[0]) / disc;
    ft = zero;
    goto L360;
/* ---      COMPLETE COEFFICIENT CALCULATION FOR 3X3 CASE */
L330:
    dotv_(&ac[2], vec, &tn[1]);
/* ---      TERMINATE SECOND ORDER PROCESS IF COEFFICIENT IS TOO LARGE */
    if (abs(ac[2]) > big) {
	goto L2000;
    }
    dotv_(&au[2], &tn[1], vecu);
    au[2] = -au[2];
    dotv_(&av[2], &tn[1], vecv);
    av[2] = -av[2];
    at[0] = au[2];
    at[1] = av[2];
    dotv_(&at[2], &tn[1], &tn[1]);
/* ---      NOW USE NEWTON RAPHSON FORMULA TO ALTER EU,EV,ET TO MIN W. */
/* ---      EQUATIONS TAKE THE FORM */
/* ---      WU(NXT)=0-WU(NOW)=FU*WUU+FV*WUV+FT*WUT */
/* ---      WV(NXT)=0-WV(NOW)=FU*WUV+FV*WVV+FT*WVT */
/* ---      WT(NXT)=0-WT(NOW)=FU*WUT+FV*WVT+FT*WTT */
/* ---      THEN EU=EU+FU, EV=EV+FV, ET=ET+FT. */

    disc = det3_(au, av, at);
/* ---      IF DISC IS SMALL, THEN ACCEPT LAST GOOD DU,DV,DT */
    if (disc < disck) {
	goto L410;
    }
    fu = det3_(ac, av, at) / disc;
    fv = det3_(au, ac, at) / disc;
    ft = det3_(au, av, ac) / disc;

L360:
/* ---      COMPARE CURRENT FU,FV,FT AND LAST EU,EV,ET */
/* ---      IF CHANGE IS SMALL, THEN QUIT */
    temp = abs(eu) + abs(ev) + abs(et);
    if (ict == 1 && *ilev >= 3) {
	temp = one;
    }
    if (temp < vsmal) {
	goto L400;
    }

    errat = (abs(fu) + abs(fv) + abs(ft)) / temp;
    eu += fu;
    ev += fv;
    et += ft;

    if (*idebug == 0) {
	goto L370;
    }
    bad_(&c__1, &c__1, "EU  ", &eu, (ftnlen)4);
    bad_(&c__1, &c__1, "EV  ", &ev, (ftnlen)4);
    bad_(&c__1, &c__1, "ET  ", &et, (ftnlen)4);
    bad_(&c__1, &c__1, "ERAT", &errat, (ftnlen)4);
    bad_(&c_n1, &c__0, "ICT ", &ict, (ftnlen)4);
    bad_(&c__1, &c__1, "DISC", &disc, (ftnlen)4);
    bad_(&c_n3, &c__1, "AC  ", ac, (ftnlen)4);
L370:
    if (*ilev > 3) {
	goto L400;
    }
    if (errat < erchk) {
	goto L400;
    }
/* ---      CHECK FOR DEFINITE REDUCTION OF ERROR, OTHERWISE QUIT */
    if (ict == 3) {
	errlas = errat;
    }
    if (ict < 4) {
	goto L210;
    }
    if (errat / errlas > ergood) {
	goto L2000;
    }
    errlas = errat;
/* ---      NOT CLOSE ENOUGH, SO SAVE FU,FV,FT AND REPEAT N-R ITERATION */
    goto L210;

L410:
/* ---      DECIDE WHETHER TO ACCEPT SECOND ORDER ITERATION */
    if (ict < 2 || errat > erchk2) {
	goto L2000;
    }
L400:
    *du = eu;
    *dv = ev;
    *dt = et;
L2000:
    *irr = 0;

    goto L9999;

L1000:
/* ---      ERROR EXIT */

L9999:

    if (*idebug == 0) {
	goto L2010;
    }
    bad_(&c__1, &c__0, "IRR ", irr, (ftnlen)4);
    bad_(&c__1, &c__1, "DU  ", du, (ftnlen)4);
    bad_(&c__1, &c__1, "DV  ", dv, (ftnlen)4);
    bad_(&c__1, &c__1, "DT  ", dt, (ftnlen)4);
    bad_(&c_n1, &c__1, "DISC", &disc, (ftnlen)4);
L2010:

    return 0;
} /* aprix_ */

