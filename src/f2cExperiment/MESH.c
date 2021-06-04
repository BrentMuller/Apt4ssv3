/* MESH.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n4 = -4;
static integer c__8 = 8;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__11 = 11;
static integer c__18 = 18;
static integer c__26 = 26;
static integer c__15 = 15;
static integer c__41 = 41;
static integer c__5 = 5;
static integer c_n1 = -1;
static integer c__33 = 33;

/* *** SOURCE FILE : M0004288.W02   *** */

/* Subroutine */ int mesh_(integer *ierror, integer *irr, integer *itw, 
	doublereal *ssname, doublereal *asav)
{
    /* Initialized data */

    static char iwgt[8] = "WEIGHT  ";
    static char ilim[8] = "LIMIT   ";
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-14;
    static char isplin[8] = "SPLINE  ";
    static char itans[8] = "TANSPL  ";
    static char icrs[8] = "CRSSPL  ";
    static char normal[8] = "NORMAL  ";

    /* Format strings */
    static char fmt_777[] = "";
    static char fmt_1065[] = "";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n;
#define s ((doublereal *)&sspad_1 + 1)
    static integer ia, ib, ma, ig, im, in, mm, ko;
    static doublereal wj;
    static integer ib0, ib1, ib2, ig1, ig2, ig3, nk3, it1;
    extern /* Subroutine */ int bad_();
    static integer icd;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ind, ita, ics, ijk, itd, nkk, iit, jnn, jrl, inr, nwd, jpt,
	     jwl;
    static doublereal spl;
    static integer itt, kwl, inx, kwl1, nend, jtan, klim, ktfl, iret, jrlm, 
	    jiwl, ilin;
    static doublereal pcrs;
    static char test[8];
    static integer irrt;
    static doublereal pnts;
    static integer isxx, jflag, ipala[2], ipara;
#define canon ((doublereal *)&_BLNK__1)
    static integer jctan;
    extern /* Subroutine */ int paral_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, integer *, integer *, integer *), cform_(char *, 
	    char *, integer *, integer *, ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer jptan, jdist;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer irule, jrule, jnrml, ntemp, inorm;
    static doublereal ptans;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer iglobe;
    extern /* Subroutine */ int getsca_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *), linear_(
	    doublereal *, doublereal *, doublereal *, integer *), record_(
	    integer *);
    static integer jpctan, jcdist;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer nscamx;
    extern /* Subroutine */ int scdump_(integer *, doublereal *);
    static integer iseqno;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer nmesmx;
    extern /* Subroutine */ int ssplin_(doublereal *, integer *);
    static integer nsplmx, numpts;

    /* Assigned format variables */
    static char *iret_fmt;

/* ----------SCULPTURED SURFACE ROUTINE ------- JULY 1971  *LPK* */
/* ---------- MESH DEFINITION */
/* ---------THIS ROUTINE ACCEPTS THE TRANSLATED MESH DEFINITION */
/* ---------AND PREPARES THE NECESSARY VALUE TABLE FOR THE MESH */
/* ---------DATA STRUCTURE. UPON ENTRANCE IT IS ASSUMED THAT THE HEADER */
/* ---------OF THE DATA STRUCTURE -SSCAN ARRAY, WAS SET. THE ROUTINE */
/* ---------CHECKS IF THE DEFINED SURFACE EXCEEDS THE SIZE LIMITATIONS */
/* ---------(NMESX TOTAL NO. OF POINTS AND NSPLMX POINTS PER SPLINE). */
/* ---------IT THEN CHECKS THE TRANSLATED DEFINITION IN SSCAN ARRY AND */
/* ---------AND GENERATES AN INTERMEDIATE ARRAY-SCAN, CONSISTING OF */
/* ---------FOUR BLOCKS(POINTS,TANGENT CONSTRAINTS, CROSS TANGENT */
/* ---------CONSTRAINTS AND NORMALS), A WEIGHT ARRAY-RL,AND A LIMIT */
/* ---------ARRAY-RLM.THE ROUTINE THEN CALLS SSPLIN ROUTINE FOR EACH S */
/* ---------SPLINE AND CROSS SPLINE (WEIGHTS ARE RESOLVED UPON SPLINING */
/* ---------IN THE MAIN DIRECTION). THE TANGENT VECTOR ARE MOVED BACK INTO */
/* ---------SCAN ARRAYAND THE DISTANCES BETWEEN POINTS ARE STORED IN */
/* ---------DIST ARRY (FOR TANSPLINES) AND CDIST ARRAY(FOR CROSSSPLINES) */
/* ---------FURTHER PARAL OR LINEAR ROUTINES ARE CALLED TO ASSIGN */
/* ---------LENGTHS TO THE VECTORS. A RULED SURFACE FLAG IS SET */
/* ---------ACCORDING TO THE FOLLOWING LOGIC:IF THERE ARE TWO SPLINES */
/* ---------AND NO NORMAL CONSTRAINTS AND NO CROSS TANGENCY CONSTRAINTS */
/* ---------A RULED SURFACE WITH RULLINGS IN CROSSPLINE DIRECTION IS */
/* ---------INDICATED(ITW=1). IF THERE ARE TWO POINTS PER SPLINE AND */
/* ---------NO NORMAL AND NO TANSPLINE CONSTRAINTS A RULED SURFACE */
/* ---------WITH  RULLINGS IN THE MAIN DIRECTION IS INDICATED (ITW=2). */
/* ---------FINALLY GETSCA ROUTINE IS CALLED TO LOAD THE DATA FROM SCAN */
/* ---------ARRAY TO SSCAN ARRAY. */
/* ---     BUFFER ARRAY FOR PRINTING */
/* -------- IF N IS THE MAX NO. OF POINTS IN THE MESH , DIMENSIONS OF */
/* -------- RL,RLM,DIST,CDIST =N.DIMENSION OF TAN AND CTAN=3*N,AND */
/* -------- DIMENSION OF SCAN =12*N */
/* ---     NSCNMX IS THE MAXIMUM SPACE AVAILABLE IN SCAN */
/* ---     ISCAN IS THE LAST USED LOCATION IN SCAN */
/* ---     SCAN IS A SCRATCH PAD WORK AREA FOR SS CALCULATIONS */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* .... SCULPTURED SURFACES SCRATCH PAD AREA */




/* ---     THE BUFFER ARRAY FOR CURVES IS EQUIVALENCED TO SCAN */
/* ---     ISXX WILL BE STARTING POSITION FOR THE CURVE DATA */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --asav;

    /* Function Body */

/* ---     MAX NUMBER OF POINTS IN A MESH IS LIMITED BY SPACE IN SCAN. */
    nmesmx = sspad_1.nscnmx / 20;
    nscamx = nmesmx * 20;
/* ---     COMPUTE THE ACTUAL NUMBER OF MESH POINTS */
    numpts = (integer) (sscan[8] * sscan[9]);
    nk3 = numpts * 3;
    if (numpts <= nmesmx) {
	goto L71;
    }
/* ---     TOO MANY POINTS FOR SPACE AVAILABLE IN SSPAD */
    *ierror = 213;
    goto L9000;
L71:
    nscamx = min(nscamx,sspad_1.nscnmx);
/* ---     MAX NUMBER OF POINTS IN A SINGLE SPLINE OR CROSS SPLINE */
    nsplmx = 30;
/* ---     SET UP BASE INDICES FOR VARIOUS TYPES OF DATA IN SCAN */
/* ---     INPUT POINT DATA */
    jpt = 0;
/* ---     INPUT TANSPL DATA */
    jptan = numpts * 3;
/* ---     INPUT CRSSPL DATA */
    jpctan = numpts * 6;
/* ---     INPUT NORMAL DATA */
    jnrml = numpts * 9;
/* ---     PROCESSED TANGENT DATA */
    jtan = numpts * 12;
/* ---     SHARED LOCATION, WEIGHT DATA FOR SMOOTHING */
    jrl = jtan;
/* ---     SHARED LOCATION, WILD POINT DATA */
    jiwl = jtan + numpts;
/* ---      PROCESSED CROSS TANGENT DATA */
    jctan = numpts * 15;
/* ---     SHARED LOCATION , LIMIT DATA */
    jrlm = jctan;
/* ---     SHARED LOCATION, WILD POINT DATA */
    jwl = jctan + numpts;
/* ---     TANGENT SPACING */
    jdist = numpts * 18;
/* ---     CROSS TANGENT SPACING */
    jcdist = numpts * 19;
/* ---     DETERMINE WHERE THE CURVE DATA BUFFER SHOULD START AND */
/* ---     WHETHER THERE IS ENOUGH ROOM FOR SPLINING. */
    ntemp = (integer) sscan[8];
    if (sscan[8] < sscan[9]) {
	ntemp = (integer) sscan[9];
    }
    isxx = numpts * 20 / 24;
    ++isxx;
    if ((isxx + 1 + ntemp) * 24 <= sspad_1.nscnmx) {
	goto L72;
    }
/* ****    NOT ENOUGH SPACE FOR THE CURVE DATA */
    *ierror = 210;
    goto L9000;
L72:

    i__1 = nscamx;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	sspad_1.scan[i__ - 1] = zero;
    }
    i__1 = numpts;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sspad_1.scan[jrlm + i__ - 1] = zero;
/* L101: */
	sspad_1.scan[jrl + i__ - 1] = one;
    }
    *ierror = 0;
    *irr = 0;
    inorm = 0;
    *itw = 0;
    irule = 0;
    jrule = 0;
    spl = sscan[8];
    pnts = sscan[9];
    sscan[9] = asav[10];
    nend = (integer) asav[5];
    if (spl == 2.f) {
	irule = 1;
    }
    if (pnts == 2.f) {
	jrule = 1;
    }
    itt = (integer) (spl * pnts);
    ia = (integer) pnts;
    if (itt <= nmesmx) {
	goto L110;
    }
    *ierror = 210;
    goto L9000;
L110:
    if (ia <= nsplmx) {
	goto L120;
    }
    *ierror = 211;
    goto L9000;
L120:
    ptans = (doublereal) (jptan + 1);
    pcrs = (doublereal) (jpctan + 1);
    k = 0;
    ita = jptan - 2;
    ics = jpctan - 2;
    inr = jnrml - 2;
/* ---      TURN THE GLOBAL WEIGHT AND LIMIT FLAG OFF */
    iglobe = 0;
    m = 9;
    if (ibugg_1.ibug == 11) {
	i__1 = -nend;
	bad_(&i__1, &c__1, "SSCN", sscan, (ftnlen)4);
    }
/* ---     ASSUME THE FIRST INPUT FOLLOWS THE WORD SPLINE */
    goto L650;
/* ---     NOW SEARCH THRU THE INPUT STREAM AND STRUCTURE */
/* ---     THE MESH DATA INTO THE SCAN ARRAY FOR MESH PROCESSING */

L160:
    if (ibugg_1.ibug != 11) {
	goto L162;
    }
    bad_(&c__1, &c__0, "NEND", &nend, (ftnlen)4);
    bad_(&c__1, &c__0, "M   ", &m, (ftnlen)4);
    bad_(&c_n4, &c__1, "SNXT", &sscan[m - 1], (ftnlen)4);
L162:
    if (m >= nend) {
	goto L1000;
    }
    if (sscan[m - 1] == 19.f) {
	goto L610;
    }
    if (sscan[m - 1] == 13.f) {
	goto L200;
    }
    if (sscan[m - 1] == 136.f) {
	goto L300;
    }
    if (sscan[m - 1] == 137.f) {
	goto L400;
    }
    if (sscan[m - 1] == 138.f) {
	goto L500;
    }
    if (sscan[m - 1] == 139.f) {
	goto L550;
    }
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, isplin, (ftnlen)8, (ftnlen)8) == 0) {
	goto L650;
    }
    goto L1000;
/* ----------NORMAL */
L200:
    ++m;
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, normal, (ftnlen)8, (ftnlen)8) != 0) {
	*ierror = 214;
    }
    ++m;
    inorm = 1;
    if (sscan[m - 1] != 20.f) {
	*ierror = 215;
    }
    n = inr + 2;
    i__1 = n;
    for (i__ = inr; i__ <= i__1; ++i__) {
	++m;
	sspad_1.scan[i__ - 1] = sscan[m - 1];
/* L250: */
    }
    goto L600;
/* ----------TANSPL */
L300:
    ++m;
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, itans, (ftnlen)8, (ftnlen)8) != 0) {
	*ierror = 216;
    }
    ++m;
    if (sscan[m - 1] != 20.f) {
	*ierror = 215;
    }
    n = ita + 2;
    i__1 = n;
    for (i__ = ita; i__ <= i__1; ++i__) {
	++m;
	sspad_1.scan[i__ - 1] = sscan[m - 1];
/* L350: */
    }
    goto L600;
/* ----------CRSSPL */
L400:
    ++m;
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, icrs, (ftnlen)8, (ftnlen)8) != 0) {
	*ierror = 217;
    }
    ++m;
    if (sscan[m - 1] != 20.f) {
	*ierror = 215;
    }
    n = ics + 2;
    i__1 = n;
    for (i__ = ics; i__ <= i__1; ++i__) {
	++m;
	sspad_1.scan[i__ - 1] = sscan[m - 1];
/* L450: */
    }
    goto L600;
/* ----------WEIGHT */
L500:
    ++m;
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, iwgt, (ftnlen)8, (ftnlen)8) != 0) {
	*ierror = 218;
    }
    ++m;
    if (sscan[m - 1] != 21.f) {
	*ierror = 219;
    }
    ++m;
/* ---     IF THIS IS A GLOBAL WEIGHT, THEN SET REMAINING WEIGHTS */
/* ---     IN THIS PARTICULAR SPLINE DEFINITION */
    if (iglobe == 0) {
	goto L501;
    }
    klim = (integer) (pnts - one + k);
/* ---     IF THE LIMIT IS NEGATIVE, THEN IT IS GLOBAL FOR THE */
/* ---     REMAINING POINTS IN THE MESH. */
    if (sscan[m - 1] < -smal) {
	klim = numpts + k - 1;
    }
    klim = min(numpts,klim);
    i__1 = klim;
    for (l = k; l <= i__1; ++l) {
/* L502: */
	sspad_1.scan[jrl + l - 1] = (d__1 = sscan[m - 1], abs(d__1));
    }
    goto L650;
L501:

    sspad_1.scan[jrl + k - 1] = sscan[m - 1];
    goto L600;
/* -------------  LIMIT */
L550:
    ++m;
    holfrm_(&sscan[m - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, ilim, (ftnlen)8, (ftnlen)8) != 0) {
	*ierror = 220;
    }
    ++m;
    if (sscan[m - 1] != 21.f) {
	*ierror = 219;
    }
    ++m;
/* ---     IF THIS IS A GLOBAL LIMIT, THEN SET LIMITS IN THIS */
/* ---     PARTICULAR SPLINE TO THE INDICATED LIMIT */
    if (iglobe == 0) {
	goto L551;
    }
    klim = (integer) (pnts - one + k);
/* ---     IF THE LIMIT IS NEGATIVE THEN IT IS GLOBAL FOR THE */
/* ---     REMAINING POINTS IN THE MESH */
    if (sscan[m - 1] < -smal) {
	klim = numpts + k - 1;
    }
    klim = min(numpts,klim);
    i__1 = klim;
    for (l = k; l <= i__1; ++l) {
/* L552: */
	sspad_1.scan[jrlm + l - 1] = (d__1 = sscan[m - 1], abs(d__1));
    }
    goto L650;
L551:

    sspad_1.scan[jrlm + k - 1] = sscan[m - 1];
    goto L600;
/* ----------SPLINE */
L600:
    ++m;
    goto L160;
L610:
    ita += 3;
    ics += 3;
    inr += 3;
    mm = k * 3 + 1;
    ma = mm + 2;
    ++k;
    i__1 = ma;
    for (i__ = mm; i__ <= i__1; ++i__) {
	++m;
	sspad_1.scan[i__ - 1] = sscan[m - 1];
/* L620: */
    }
    goto L600;

L650:
    ++m;
    iglobe = 0;
    if (sscan[m - 1] == 19.f) {
	goto L610;
    }
/* ---     IF A WEIGHT OR LIMIT FOLLOW, THEN THESE SPECIFY GLOBAL WEIGHTS */
    iglobe = 1;
    if (sscan[m - 1] == 138.f) {
	goto L500;
    }
    if (sscan[m - 1] == 139.f) {
	goto L550;
    }
    *ierror = 212;
    goto L9000;

/* --------USERS INPUT HAS NOW BEEN FORMATTED, BEGIN SPLINING PROCEDURE. */
/* ----------SMOOTHING ALONG SPLINE DIRECTION */
L1000:
/* ---     CHECK TO SEE IF ALL INPUT HAS BEEN PROCESSED */
    if (m == nend && k == itt) {
	goto L1001;
    }
/* ****    IMPROPER DATA IN SSURF INPUT STREAM */
    bad_(&c__1, &c__0, "NEND", &nend, (ftnlen)4);
    bad_(&c__1, &c__0, "M   ", &m, (ftnlen)4);
    bad_(&c_n4, &c__1, "SNXT", &sscan[m - 1], (ftnlen)4);
    *ierror = 222;
    goto L9000;
L1001:
    if (ibugg_1.ibug != 11) {
	goto L1003;
    }
/* ---     DUMP PROCESSED POINT, TANSPL,CRSSPL,NORMAL, WT AND LIMITS */
    nk3 = numpts * 3;
    i__1 = -nk3;
    bad_(&i__1, &c__1, "PTS ", &sspad_1.scan[jpt], (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "TAN ", &sspad_1.scan[jptan], (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "CTAN", &sspad_1.scan[jpctan], (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "NRML", &sspad_1.scan[jnrml], (ftnlen)4);
    i__1 = -numpts;
    bad_(&i__1, &c__1, "WGT ", &sspad_1.scan[jrl], (ftnlen)4);
    i__1 = -numpts;
    bad_(&i__1, &c__1, "LIMT", &sspad_1.scan[jrlm], (ftnlen)4);
L1003:
/* ----------RESET POINTERS TO AREAS FOR TANGENTS, CROSS AND NORMALS */
    ita = jptan + 1;
    ics = jpctan + 1;
    inr = jnrml + 1;
/* --------------    INITIATE CROSS SPLINE  CONSTRAINT INDICATORS */
    ia = (integer) spl;
    ib = (integer) pnts;
    iit = itt * 12;
    im = ib + 1;
    if (ia > ib) {
	im = ia + 1;
    }
    i__1 = im;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1005: */
	s[((i__ + isxx) * 6 + 3 << 2) - 25] = zero;
    }
    ijk = 0;
/* -------------          PREPARE S ARRAY HEADER */
    s[((isxx + 1) * 6 + 1 << 2) - 27] = one;
    s[((isxx + 1) * 6 + 1 << 2) - 26] = one;
    s[((isxx + 1) * 6 + 1 << 2) - 25] = (doublereal) ib;
/* -------------          IND,ITD,ICD, INDICATE EXISTANCE OF NORMAL , */
/* -------------          TANSPL, CRSSPL, CONSTRAINT RESPECTIVELY */
/* -------------        AT ANY OF THE POINTS */
    ind = 0;
    itd = 0;
    icd = 0;
    kwl = 0;
    kwl1 = 0;
    ktfl = 0;
    sspad_1.scan[jiwl] = zero;
/* -------------          SPLINING ALONG MAIN DIRECTION (TANSPL) */
    ib1 = ib + 1;
    i__1 = ia;
    for (ig = 1; ig <= i__1; ++ig) {
	ib0 = (ig - 1) * ib * 3;
	i__2 = ib1;
	for (ig1 = 2; ig1 <= i__2; ++ig1) {
	    ib2 = (ig1 - 2) * 3 + ib0;
/* -------------          MOVE POINTS AND VECTORS INTO S ARRAY */
	    for (ig2 = 1; ig2 <= 3; ++ig2) {
		ig3 = ig2 + ib2;
		s[ig2 + ((ig1 + isxx) * 6 + 1 << 2) - 29] = sspad_1.scan[ig3 
			- 1];
		s[ig2 + ((ig1 + isxx) * 6 + 2 << 2) - 29] = sspad_1.scan[ig3 
			- 1 + ita - 1];
		s[ig2 + ((ig1 + isxx) * 6 + 4 << 2) - 29] = sspad_1.scan[ig3 
			- 1 + inr - 1];
/* L1030: */
	    }
/* -------------          SET S ARRAY CONSTRAINT INDICATORS */
	    s[((ig1 + isxx) * 6 + 2 << 2) - 25] = zero;
	    jnn = ita + ig3 - 3;
	    wj = (d__1 = sspad_1.scan[jnn - 1], abs(d__1)) + (d__2 = 
		    sspad_1.scan[jnn], abs(d__2)) + (d__3 = sspad_1.scan[jnn 
		    + 1], abs(d__3));
	    if (wj > smal) {
		s[((ig1 + isxx) * 6 + 2 << 2) - 25] = one;
	    }
	    if (s[((ig1 + isxx) * 6 + 2 << 2) - 25] == one) {
		itd = 1;
	    }
	    s[((ig1 + isxx) * 6 + 4 << 2) - 25] = zero;
	    jnn = inr + ig3 - 3;
	    wj = (d__1 = sspad_1.scan[jnn - 1], abs(d__1)) + (d__2 = 
		    sspad_1.scan[jnn], abs(d__2)) + (d__3 = sspad_1.scan[jnn 
		    + 1], abs(d__3));
	    if (wj > smal) {
		s[((ig1 + isxx) * 6 + 4 << 2) - 25] = one;
	    }
	    if (s[((ig1 + isxx) * 6 + 4 << 2) - 25] == one) {
		ind = 1;
	    }
/* -------------          MOVE WEIGHT TO S ARRAY */
	    s[((ig1 + isxx) * 6 + 5 << 2) - 28] = sspad_1.scan[jrl + (ig - 1) 
		    * ib + ig1 - 2];
/* -------------          MOVE LIMITS */
	    s[((ig1 + isxx) * 6 + 5 << 2) - 27] = sspad_1.scan[jrlm + (ig - 1)
		     * ib + ig1 - 2];
/* L1020: */
	}
	s[((isxx + 1) * 6 + 2 << 2) - 28] = zero;
/* -------------          BRANCH TO SSPLIN ROUTINE */
	jflag = ig + 1000;
	if (ibugg_1.ibug == 11) {
	    scdump_(&jflag, &s[((isxx + 1) * 6 + 1 << 2) - 28]);
	}

	ssplin_(&s[((isxx + 1) * 6 + 1 << 2) - 28], &irrt);
	jflag = ig + 2000;
	if (ibugg_1.ibug == 11) {
	    scdump_(&jflag, &s[((isxx + 1) * 6 + 1 << 2) - 28]);
	}
	if (*irr == 0 && irrt != 0) {
	    *irr = irrt;
	}
/* -------------          MOVE POINTS AND TANSPLINES TO SCAN */
	i__2 = ib1;
	for (ig1 = 2; ig1 <= i__2; ++ig1) {
	    ib2 = (ig1 - 2) * 3 + ib0;
	    for (ig2 = 1; ig2 <= 3; ++ig2) {
		ig3 = ig2 + ib2;
		sspad_1.scan[ig3 - 1] = s[ig2 + ((ig1 + isxx) * 6 + 1 << 2) - 
			29];
		sspad_1.scan[ita + ig3 - 2] = s[ig2 + ((ig1 + isxx) * 6 + 2 <<
			 2) - 29];
/* L1050: */
	    }
/* -------------          MOVE DISTANCE BETWEEN POINTS TO DIST */
	    sspad_1.scan[jdist + (ib - 1) * (ig - 1) + ig1 - 2] = s[((ig1 + 
		    isxx) * 6 + 1 << 2) - 25];
/* ------------- IF WILD POINT INDICATOR GT 1 STACK THE POINT LOCATION */
/* ------------- (SPLINE NUMBER AND POINT NUMBER) INTO IWL ARRAY AND */
/* ------------- THE WILDNESS FACTOR INTO WL ARRAY */
	    if (s[((ig1 + isxx) * 6 + 5 << 2) - 25] <= one) {
		goto L1040;
	    }
	    ++kwl1;
	    ++kwl;
	    sspad_1.scan[jwl + kwl1 - 1] = s[((ig1 + isxx) * 6 + 5 << 2) - 25]
		    ;
	    sspad_1.scan[jiwl + kwl - 1] = (doublereal) ig;
	    ++kwl;
	    sspad_1.scan[jiwl + kwl - 1] = (doublereal) (ig1 - 1);
L1040:
	    ;
	}
/* ---      PRINT ERROR NUMBER FOR EACH SPLINE, IF ANY. */
	if (irrt == 0) {
	    goto L1041;
	}
	record_(&iseqno);
	iconv_(&iseqno, darray_1.darray, &c__1, &c__6, (ftnlen)120);
	cform_(". ERROR NO.", darray_1.darray, &c__7, &c__11, (ftnlen)11, (
		ftnlen)120);
	iconv_(&irrt, darray_1.darray, &c__18, &c__7, (ftnlen)120);
	cform_("FOR  SPLINE NO.", darray_1.darray, &c__26, &c__15, (ftnlen)15,
		 (ftnlen)120);
	iconv_(&ig, darray_1.darray, &c__41, &c__5, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
L1041:
/* L1010: */
	;
    }

/* ------------- IF ANY WILD POINT DETECTED GO TO PRINT A MESSAGE */
    if ((d__1 = sspad_1.scan[jiwl], abs(d__1)) < smal) {
	goto L777;
    }
    ko = 0;
    iret = 0;
    iret_fmt = fmt_777;
    goto L3000;
/* ----------END OF SPLINE FITTING, BRANCH TO WILD POINT ANALYSIS */
L777:
    ijk = 1;
/* -------------          SPLINE ALONG CROSS SPLINE DIRECTION */
/* ------------           CHANGE S ARRAY HEADER (NO. OF POINTS) */
    s[((isxx + 1) * 6 + 1 << 2) - 25] = (doublereal) ia;
    ib1 = ia + 1;
    i__1 = ib;
    for (ig = 1; ig <= i__1; ++ig) {
	ib0 = (ig - 1) * 3;
	i__2 = ib1;
	for (ig1 = 2; ig1 <= i__2; ++ig1) {
	    ib2 = (ig1 - 2) * 3 * ib + ib0;
/* -------------          MOVE POINTS AND VECTORS INTO S ARRAY */
	    for (ig2 = 1; ig2 <= 3; ++ig2) {
		ig3 = ig2 + ib2;
		s[ig2 + ((ig1 + isxx) * 6 + 1 << 2) - 29] = sspad_1.scan[ig3 
			- 1];
		s[ig2 + ((ig1 + isxx) * 6 + 2 << 2) - 29] = sspad_1.scan[ig3 
			- 1 + ics - 1];
		s[ig2 + ((ig1 + isxx) * 6 + 4 << 2) - 29] = sspad_1.scan[ig3 
			- 1 + inr - 1];
/* L1075: */
	    }
/* -------------          SET CONSTRAINT INDICATORS */
	    s[((ig1 + isxx) * 6 + 2 << 2) - 25] = zero;
	    s[((ig1 + isxx) * 6 + 4 << 2) - 25] = zero;
	    jnn = ics + ig3 - 3;
	    wj = (d__1 = sspad_1.scan[jnn - 1], abs(d__1)) + (d__2 = 
		    sspad_1.scan[jnn], abs(d__2)) + (d__3 = sspad_1.scan[jnn 
		    + 1], abs(d__3));
	    if (wj > smal) {
		s[((ig1 + isxx) * 6 + 2 << 2) - 25] = one;
	    }
	    if (s[((ig1 + isxx) * 6 + 2 << 2) - 25] == one) {
		icd = 1;
	    }
	    jnn = inr + ig3 - 3;
	    wj = (d__1 = sspad_1.scan[jnn - 1], abs(d__1)) + (d__2 = 
		    sspad_1.scan[jnn], abs(d__2)) + (d__3 = sspad_1.scan[jnn 
		    + 1], abs(d__3));
	    if (wj > smal) {
		s[((ig1 + isxx) * 6 + 4 << 2) - 25] = one;
	    }
/* ---------- SET WEIGHT TO CERTITUDE, AND LIMIT TO ZERO */
	    s[((ig1 + isxx) * 6 + 5 << 2) - 28] = one;
	    s[((ig1 + isxx) * 6 + 5 << 2) - 27] = zero;
/* L1070: */
	}
	s[((isxx + 1) * 6 + 2 << 2) - 28] = zero;
/* -------------          BRANCH TO SPLINING ROUTINE */
	jflag = ig + 3000;
	if (ibugg_1.ibug == 11) {
	    scdump_(&jflag, &s[((isxx + 1) * 6 + 1 << 2) - 28]);
	}

	ssplin_(&s[((isxx + 1) * 6 + 1 << 2) - 28], &irrt);
	jflag = ig + 4000;
	if (ibugg_1.ibug == 11) {
	    scdump_(&jflag, &s[((isxx + 1) * 6 + 1 << 2) - 28]);
	}
	if (*irr == 0 && irrt != 0) {
	    *irr = irrt;
	}
/* -------------          MOVE CROSS SPLINE TANGENTS TO SCAN */
	i__2 = ib1;
	for (ig1 = 2; ig1 <= i__2; ++ig1) {
	    ib2 = (ig1 - 2) * 3 * ib + ib0;
	    for (ig2 = 1; ig2 <= 3; ++ig2) {
		ig3 = ig2 + ib2;
		sspad_1.scan[ics + ig3 - 2] = s[ig2 + ((ig1 + isxx) * 6 + 2 <<
			 2) - 29];
/* L1090: */
	    }
/* -------------          MOVE DISTANCES ALONG CROSSPLINES TO CDIST */
	    sspad_1.scan[jcdist + (ia - 1) * (ig - 1) + ig1 - 2] = s[((ig1 + 
		    isxx) * 6 + 1 << 2) - 25];
/* ------------- IF WILD POINT INDICATOR GT 1 STACK THE POINT LOCATION */
/* ------------- (SPLINE NUMBER AND POINT NUMBER) INTO IWL ARRAY AND */
/* ------------- THE WILDNESS FACTOR INTO WL ARRAY */
	    if (s[((ig1 + isxx) * 6 + 5 << 2) - 25] <= one) {
		goto L1080;
	    }
	    ++kwl1;
	    ++kwl;
	    sspad_1.scan[jwl + kwl1 - 1] = s[((ig1 + isxx) * 6 + 5 << 2) - 25]
		    ;
	    sspad_1.scan[jiwl + kwl - 1] = (doublereal) ig;
	    ++kwl;
	    sspad_1.scan[jiwl + kwl - 1] = (doublereal) (ig1 - 1);
L1080:
	    ;
	}
/* ---      PRINT ERROR NUMBER FOR EACH CROSS SPLINE, IF ANY. */
	if (irrt == 0) {
	    goto L1081;
	}
	record_(&iseqno);
	iconv_(&iseqno, darray_1.darray, &c__1, &c__6, (ftnlen)120);
	cform_(". ERROR NO.", darray_1.darray, &c__7, &c__11, (ftnlen)11, (
		ftnlen)120);
	iconv_(&irrt, darray_1.darray, &c__18, &c__7, (ftnlen)120);
	cform_("FOR CSPLINE NO.", darray_1.darray, &c__26, &c__15, (ftnlen)15,
		 (ftnlen)120);
	iconv_(&ig, darray_1.darray, &c__41, &c__5, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
L1081:
/* L1060: */
	;
    }

/* ------------- IF ANY WILD POINT DETECTED GO TO PRINT A MESSAGE */
    if ((d__1 = sspad_1.scan[jiwl], abs(d__1)) < smal) {
	goto L1065;
    }
    ko = 1;
    iret = 1;
    iret_fmt = fmt_1065;
    goto L3000;
/* ----------END OF CROSS SPLINE FITTING, BRANCH TO WILD POINT ANALYSIS */
L1065:
    if (*irr != 0) {
	goto L9000;
    }
/* ---------- PRINT OUT RESULTS OF SPLINING AND CROSS SPLINING */
    if (ibugg_1.ibug != 11) {
	goto L1068;
    }
    nkk = numpts * 12;
    i__1 = -nkk;
    bad_(&i__1, &c__1, "SCN2", sspad_1.scan, (ftnlen)4);
    i__1 = -numpts;
    bad_(&i__1, &c__1, "DIST", &sspad_1.scan[jdist], (ftnlen)4);
    i__1 = -numpts;
    bad_(&i__1, &c__1, "CDIS", &sspad_1.scan[jcdist], (ftnlen)4);
L1068:
    ++ijk;
/* --------- REARRANGE CROSS SPLINE TANGENTS TO APPEAR IN SCAN */
/* -------  ARRAY ACCORDING TO THEIR ORDER ALONG SPLINES. USES NORMALS */
/* -------- SECTION OF SCAN AS A WORK AREA */
    i__1 = itt;
    for (j = 1; j <= i__1; ++j) {
	inx = ((j - 1) / ia + (j - 1 - ia * ((j - 1) / ia)) * ib) * 3 + ics - 
		1;
	in = inr - 1 + (j - 1) * 3;
	for (k = 1; k <= 3; ++k) {
/* L2010: */
	    sspad_1.scan[in + k - 1] = sspad_1.scan[inx + k - 1];
	}
    }
    it1 = itt * 3;
    i__1 = it1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sspad_1.scan[ics - 1 + i__ - 1] = sspad_1.scan[inr - 1 + i__ - 1];
/* L2020: */
	sspad_1.scan[inr - 1 + i__ - 1] = zero;
    }
/* ---------              SET RULED SURFACE INDICATORS */
    if (ind == 0 && icd == 0 && irule == 1) {
	*itw = 1;
    }
    if (ind == 0 && itd == 0 && jrule == 1) {
	*itw = 2;
    }
/* ---------- PRINT OUT TWIST FACTOR AND REARRANGED CROSS VECTORS */
    if (ibugg_1.ibug != 11) {
	goto L2023;
    }
    bad_(&c_n1, &c__0, "ITW ", itw, (ftnlen)4);
    nkk = numpts * 3;
    i__1 = -nk3;
    bad_(&i__1, &c__1, "CRS ", &sspad_1.scan[jpctan], (ftnlen)4);
L2023:

/* ----------PARALLEL CHECK */
/* ----------LINEAR CHECK */
/* L4100: */
    i__1 = nk3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sspad_1.scan[jtan + i__ - 1] = zero;
	sspad_1.scan[jctan + i__ - 1] = zero;
/* L102: */
    }
    ++ijk;
    if (sscan[5] != 4.f) {
	goto L7000;
    }
    ia = (integer) spl;
    ib = (integer) pnts;
    ipara = 0;
    paral_(&sspad_1.scan[jptan], &sspad_1.scan[jdist], &sspad_1.scan[jtan], &
	    sspad_1.scan[jnrml], &ia, &ib, &ipara);
/* ---------- PRINT RESULTS OF PARAL LOGIC FOR TANGENT LENGTH SELECTION */
    if (ibugg_1.ibug != 11) {
	goto L2027;
    }
    bad_(&c_n1, &c__0, "IPAR", &ipara, (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "TANS", &sspad_1.scan[jptan], (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "TAN ", &sspad_1.scan[jtan], (ftnlen)4);
L2027:

    ipala[0] = ipara;
    ++ijk;
    ia = (integer) pnts;
    ib = (integer) spl;
    ipara = 0;
    paral_(&sspad_1.scan[jpctan], &sspad_1.scan[jcdist], &sspad_1.scan[jctan],
	     &sspad_1.scan[jnrml], &ia, &ib, &ipara);
/* ---------- PRINT RESULTS OF CROSS VECTOR LENGTH ANALYSIS */
    if (ibugg_1.ibug != 11) {
	goto L2028;
    }
    bad_(&c_n1, &c__0, "IPAR", &ipara, (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "CRS ", &sspad_1.scan[jpctan], (ftnlen)4);
    i__1 = -nk3;
    bad_(&i__1, &c__1, "CTAN", &sspad_1.scan[jctan], (ftnlen)4);
L2028:

    ipala[1] = ipara;
    ++ijk;
    ilin = 0;
    goto L8000;
L7000:
    linear_(sspad_1.scan, &spl, &pnts, &ilin);
    if (ibugg_1.ibug == 11) {
	bad_(&c_n1, &c__0, "ILIN", &ilin, (ftnlen)4);
    }
    ++ijk;
    if (ilin == 0) {
	*ierror = 300;
    }
    ipala[0] = 0;
    ipala[1] = 0;
/* ---------- SET UP DATA STRUCTURE READY TO RETURN */
L8000:
    sscan[9] = pnts;
    getsca_(sspad_1.scan, &spl, &pnts, &ptans, &pcrs, &sspad_1.scan[jtan], &
	    sspad_1.scan[jctan], ipala, &ilin, itw);
/* ---     PRINT OUT SCAN ON RETURN FOR DEBUGGING */

L9000:
    if (*ierror != 0) {
	*ierror += 5000;
    }
    if (*irr != 0) {
	*ierror = *irr;
    }
    return 0;

/* ------------- PRINT WILD POINTS MESSAGE */
L3000:
    --kwl;
    if (ktfl == 1) {
	goto L3010;
    }
    record_(&iseqno);
    iconv_(&iseqno, darray_1.darray, &c__1, &c__6, (ftnlen)120);
    cform_(". SOME  SPLINE POINTS MAY BE WILD", darray_1.darray, &c__7, &
	    c__33, (ftnlen)33, (ftnlen)120);
    if (ijk == 1) {
	cform_("CRSSPL", darray_1.darray, &c__15, &c__6, (ftnlen)6, (ftnlen)
		120);
    }
    cprint_(darray_1.darray, (ftnlen)120);
    --kwl;
    i__1 = kwl;
    for (l = 1; l <= i__1; ++l) {
	k = (l << 1) - 1;
	bad_(&c__1, &c__1, "PTNO", &sspad_1.scan[jiwl + k - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "SPL ", &sspad_1.scan[jiwl + k], (ftnlen)4);
	bad_(&c_n1, &c__1, "WILD", &sspad_1.scan[jwl + l - 1], (ftnlen)4);
/* L3011: */
    }
    ktfl = 1;
L3010:
    kwl = 0;
    kwl1 = 0;
    sspad_1.scan[jiwl] = zero;
    switch (iret) {
	case 0: goto L777;
	case 1: goto L1065;
    }
} /* mesh_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef s


