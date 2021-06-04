/* FLOSEG.f -- translated by f2c (version 20100827).
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
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c_n54 = -54;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__24 = 24;
static integer c_n4 = -4;
static integer c__48 = 48;
static integer c__4 = 4;

/* *** SOURCE FILE : M0004340.V09   *** */

/* Subroutine */ int floseg_(integer *nsize, integer *nszsav, integer *mode, 
	integer *iflseg, integer *irr)
{
    /* Initialized data */

    static doublereal areal = 21.;
    static doublereal aflow = 149.;
    static doublereal aseg = 150.;
    static integer maxsc = 96;
    static integer lstemx = 100;
    static char seg[8] = "SEG     ";
    static char arc[8] = "ARC     ";
    static char param[8] = "PARAM   ";
    static char chord[8] = "CHORD   ";
    static char flow[8] = "FLOW    ";
    static char length[8] = "LENGTH  ";
    static char angle[8] = "ANGLE   ";
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-7;
    static doublereal tolr = .005;
    static char rnam1[8] = "FLOSEG  ";
    static char rnam2[8] = "ANGSEG  ";
    static char rnam3[8] = "CHDSEG  ";
    static char rnam4[8] = "ARCSEG  ";
    static char rnam5[8] = "ANGDER  ";
    static char rnama[8] = "FLOSEG??";
    static char rname[8] = "        ";
    static integer imax2 = 3;
    static integer izal2[3] = { 5508,5509,5510 };
    static integer imax3 = 6;
    static integer izal3[6] = { 5502,5503,5504,5505,5506,5507 };
    static integer imax4 = 3;
    static integer izal4[3] = { 5501,5522,5523 };
    static integer imax5 = 3;
    static integer izal5[3] = { 5519,5511,5512 };
    static integer nhd = 1;
    static doublereal point = 19.;
    static doublereal vector = 20.;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal t;
    static integer i1, i2, ii, jj, nh, mm, ir, nn, np;
    static doublereal pp[12]	/* was [4][3] */;
    static integer ns;
#define st ((doublereal *)&sspad_1 + 1)
    static doublereal sz, an1, an2;
    static integer jj1, il2, il3, il4, il5;
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal anh;
    static integer kkk, nct, nwd;
    static doublereal tol;
    static integer ist, num;
    static doublereal sum;
    static integer nhd1, ndif;
    static logical iseg;
    static integer nloc, irct;
    static doublereal span;
    static integer mmmm;
    static doublereal anst;
    static integer ispl, nnnn, jtop;
    static char test[8];
    static integer npts;
    static doublereal tsum;
    static integer nloc1;
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal asize;
    static logical iflow;
    static integer istem;
    static doublereal anpts, bpnts;
    static integer msize;
    static doublereal stemp[400]	/* was [4][100] */;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer ncurv, ispmx;
    extern /* Subroutine */ int chdseg_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int arcseg_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *), angseg_(
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, doublereal *, doublereal *);
    static doublereal factor;
    static integer inctem;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer numseg, isegst, iflost;
    extern /* Subroutine */ int cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer nflost, nsegst, lstemp, ierror, istmax;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static doublereal totlen;
    static integer isplst;




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* .... SCULPTURED SURFACES SCRATCH PAD AREA */





/* ---     THE FOLLOWING ARRAY, DARRAY, IS SHARED FOR PRINTING */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* ---      LSTEMX IS THE MAXIMUM NUMBER OF ROWS IN STEMP */


    np = 0;
    nh = 41;
    anh = (doublereal) nh;
    nhd1 = nhd + 1;
    ns = nh + 8;
/* --- MODE=2 MEANS PROCESS FLOW COMMANDS PREVIOUSLY STORED */
/* ---      IN STEMP */
/* --- MODE=1 MEANS PERFORM PRELIMINARY SCAN OF SCURV INPUT-STREAM */
/* ---      AND STORE FLOW DATA, IF ANY, IN STEMP. */
    if (*mode == 2) {
	goto L2000;
    }

/* ---     PERFORM A PRELIMINARY SCAN OF DATA TO LOCATE FLOW */
/* ---     AND SEGMENT INFORMATION IN THE DEFINITION */
/* ---     LSTEMP IS THE POINTER TO THE LAST USED ROW IN STEMP */
/* ---     IFLOW IS TRUE ONLY WHILE PROCESSING FLOW BLOCKS */
/* ---     ISEG IS TRUE ONLY WHILE PROCESSING SEGMENT BLOCKS */
/* ---     NSEGST POINTS TO THE STARTING ROW FOR SEGMENT INFORMATION */
/* ---     NFLOST POINTS TO THE STARTING ROW FOR FLOW INFORMATION */
    iflow = FALSE_;
    iseg = FALSE_;
    nflost = 0;
    nsegst = 0;
    lstemp = 0;
    numseg = 0;
    *iflseg = 0;

/* ---     SEARCH FOR FLOW AND SEGMENT BLOCKS AND TRANSFER */
/* ---     INFORMATION IN EDITED FORM INTO THE STEMP ARRAY */

    nloc = ns;
L34:
    if (nloc >= *nsize) {
	goto L1034;
    }

/* ---     NLOC POINTS TO THE STARTING LOCATION OF THE CURRENT */
/* ---     SUBSTRING BEING EXAMINED. IT IS UPDATED TO THE NEXT SUBSTRING */
/* ---     AT THE TERMINATION OF CODE FOR EACH SUBSTRING. */
    t = canon[nloc - 1];
    holfrm_(&t, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, flow, (ftnlen)8, (ftnlen)8) == 0) {
	goto L40;
    }
    if (s_cmp(test, seg, (ftnlen)8, (ftnlen)8) == 0) {
	goto L50;
    }
    holfrm_(&canon[nloc], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, seg, (ftnlen)8, (ftnlen)8) == 0) {
	goto L51;
    }
/* ---     IF FLOW OR SEG HAVE NOT BEEN FOUND, CONTINUE SEARCH */
    if (! iflow && ! iseg) {
	++nloc;
    }
    if (! iflow && ! iseg) {
	goto L31;
    }
    if (iflow) {
	goto L60;
    }
/* ---     ISEG MUST BE TRUE SO CHECK FOR SEGMENT BLOCKS */
    t = canon[nloc];
    holfrm_(&t, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, length, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(test, param, (
	    ftnlen)8, (ftnlen)8) == 0) {
	goto L35;
    }
/* ****    PROPER MINOR WORD DID NOT FOLLOW HERE. */
    *irr = 1;
    goto L30;
L35:
    ++lstemp;
    if (lstemp <= lstemx) {
	goto L36;
    }
/* ****    NO ROOM AVAILABLE IN BUFFER FOR FLOW/SEG DATA */
    *irr = 2;
    goto L30;
L36:
    stemp[(lstemp << 2) - 4] = t;
    if (canon[nloc + 1] == areal && canon[nloc + 3] == areal) {
	goto L38;
    }
/* ****    AT LEAST TWO SCALARS SHOULD FOLLOW */
    *irr = 3;
    goto L30;
L38:
    stemp[(lstemp << 2) - 3] = canon[nloc + 2];
    stemp[(lstemp << 2) - 2] = canon[nloc + 4];
    stemp[(lstemp << 2) - 1] = one;
    nloc += 6;
    ++numseg;
    goto L31;

/* ---     CHECK FOR PROPER WORDS FOR FLOW INFORMATION */
L60:
    t = canon[nloc];
    msize = 1;
    holfrm_(&t, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, arc, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(test, param, (
	    ftnlen)8, (ftnlen)8) == 0) {
	goto L65;
    }
    msize = 4;
    if (s_cmp(test, chord, (ftnlen)8, (ftnlen)8) == 0) {
	goto L65;
    }
    msize = 4;
    if (s_cmp(test, angle, (ftnlen)8, (ftnlen)8) == 0) {
	goto L65;
    }
/* ****   NONE OF THE REQUIRED KEYWORDS HAS FOLLOWED */
    msize = 0;
    *irr = 4;
    goto L30;

L65:
    asize = (doublereal) msize;
    if (canon[nloc + 1] == areal && canon[nloc + 3] == areal) {
	goto L70;
    }
/* ****    AT LEAST TWO SCALARS SHOULD FOLLOW */
    *irr = 5;
    goto L30;
L70:
    ++lstemp;
    if (lstemp + msize - 1 <= lstemx) {
	goto L75;
    }
/* ****    NO ROOM TO BUFFER ARC/FLOW DATA */
    *irr = 6;
    goto L30;
L75:
    stemp[(lstemp << 2) - 4] = t;
    stemp[(lstemp << 2) - 3] = canon[nloc + 2];
    stemp[(lstemp << 2) - 2] = canon[nloc + 4];
    stemp[(lstemp << 2) - 1] = asize + tolr;
    nloc += 6;
    if (canon[nloc - 1] != areal) {
	goto L76;
    }
/* ---     LOAD A USER SUPPLIED TOLERANCE , IF ACCEPTABLE */
    t = canon[nloc];
    if (t > smal && t < one) {
	stemp[(lstemp << 2) - 1] = asize + t;
    }
    nloc += 2;
L76:
    if (msize < 2) {
	goto L89;
    }
/* ---     SCAN FOR MODIFYING POINTS AND VECTORS FOR FLOW SPECIFICATION */
    mm = msize - 1;
    i__1 = mm;
    for (l = 1; l <= i__1; ++l) {
	for (k = 1; k <= 4; ++k) {
	    stemp[k + (l + lstemp << 2) - 5] = zero;
/* L80: */
	}
    }
    t = canon[nloc - 1];
    if (t != point || msize < 2) {
	goto L83;
    }
    for (l = 1; l <= 3; ++l) {
	stemp[l + (lstemp + 1 << 2) - 5] = canon[nloc + l - 1];
/* L81: */
    }
    stemp[(lstemp + 1 << 2) - 1] = one;
    nloc += 4;
    t = canon[nloc - 1];
L83:
    if (t != point || msize < 3) {
	goto L87;
    }
    for (l = 1; l <= 3; ++l) {
	stemp[l + (lstemp + 2 << 2) - 5] = canon[nloc + l - 1];
/* L86: */
    }
    stemp[(lstemp + 2 << 2) - 1] = one;
    nloc += 4;
    t = canon[nloc - 1];
L87:
    if (t != vector || msize < 4) {
	goto L89;
    }
    for (l = 1; l <= 3; ++l) {
	stemp[l + (lstemp + 3 << 2) - 5] = canon[nloc + l - 1];
/* L88: */
    }
    stemp[(lstemp + 3 << 2) - 1] = one;
    nloc += 4;
L89:
/* ---     UPDATE FLOW BLOCK POINTER TO NEXT AVAILABLE SPACE. */
/* ---     NSEGST FINALLY POINTS TO START OF SEGMENT INFORMATION */
    lstemp = lstemp + msize - 1;
    goto L31;

/* ---     INITIALIZE DATA FOR FLOW INFORMATION */
L40:
    *irr = 7;
/* ****    NEITHER FLOW NOR SEG SHOULD HAVE BEEN ENCOUNTERED */
    ++nloc;
    if (canon[nloc - 3] != aflow) {
	goto L31;
    }
    if (iflow || iseg) {
	goto L30;
    }
    if (nsegst > 0 || nflost > 0) {
	goto L30;
    }
    iflow = TRUE_;
    nflost = 1;
/* ---     STORE THE DATA SIZE OF INPUT UP TO THE FIRST FLOW COMMAND */
    *nszsav = nloc - 3;
    goto L31;
/* ---     INITIALIZE DATA FOR SEGMENT INFORMATION. */
L51:
    ++nloc;
L50:
    ++nloc;
    *irr = 8;
/* ****    FLOW SHOULD HAVE BEEN ENCOUNTERED BUT NOT SEG */
    if (canon[nloc - 3] != aseg) {
	goto L31;
    }
    if (! iflow || iseg) {
	goto L30;
    }
    if (nsegst > 0 || nflost <= 0) {
	goto L30;
    }
    iflow = FALSE_;
    iseg = TRUE_;
    nsegst = lstemp + 1;
    goto L31;

L31:

    *irr = 0;
/* L32: */
/* ---     END OF LOOP TO SCAN FOR SEGMENT/FLOW BLOCKS */
    goto L34;

L1034:


    if (ibugg_1.ibug != 11) {
	goto L33;
    }
    bad_(&c_n54, &c__1, "STEM", stemp, (ftnlen)4);
L33:

    if (*irr == 0) {
	goto L90;
    }

/* ---     ERROR PATH, UNDEFINE CANON FORM AND QUIT */
L30:
/* ---     WRITE OUT INFORMATION FOR DIAGNOSING PROBLEM */
    ndif = *nsize - ns + 1;
    i__1 = -ndif;
    bad_(&i__1, &c__1, "CAN ", &canon[ns - 1], (ftnlen)4);
    nloc = nloc - ns + 1;
    bad_(&c_n1, &c__0, "NLOC", &nloc, (ftnlen)4);
    bad_(&c__1, &c__0, "NSEG", &nsegst, (ftnlen)4);
    bad_(&c__1, &c__0, "I   ", &i__, (ftnlen)4);
    bad_(&c__1, &c__0, "M   ", &m, (ftnlen)4);
    bad_(&c__1, &c__1, "AN1 ", &an1, (ftnlen)4);
    bad_(&c__1, &c__1, "AN2 ", &an2, (ftnlen)4);
    bad_(&c_n1, &c__1, "BPNT", &bpnts, (ftnlen)4);

    ierror = abs(*irr) + 5500;
    error_(&ierror, rnam1, (ftnlen)8);

L90:
    if (iflow || iseg) {
	*iflseg = 1;
    }
    goto L999;

/* ---------------------------------------------------------- */
L2000:


/* ---     FLOW INFORMATION IS AVAILABLE, SO START FLOW PROCESSING */
/* ---     FIRST SCAN THE FLOW AND SEGMENT BLOCKS AND CHECK FOR */
/* ---     INPUT CONSISTENCY. */

    anpts = canon[nh + 2] + one;
    npts = (integer) anpts;
    bpnts = anpts - one;
/* ---     INCREMENT CURVE TYPE BY 10 TO INDICATE FLOW PRESENCE. */
    canon[nh + 1] += 10.f;

/* ---     I IS CURRENT ROW, M INCREMENT TO NEXT, N2 LAST POINT */
    i__ = 0;
    m = 1;
    an2 = zero;
L1010:
    i__ += m;
    if (i__ >= nsegst) {
	goto L1080;
    }
    an1 = stemp[(i__ << 2) - 3];
    if ((d__1 = an2 - an1, abs(d__1)) < smal) {
	goto L1020;
    }
/* ****    PREVIOUS POINT AND PRESENT SHOULD BE EQUAL */
    *irr = 13;
    goto L30;
L1020:
    an2 = stemp[(i__ << 2) - 2];
    m = (integer) stemp[(i__ << 2) - 1];
    if (an1 + smal < an2 && an2 < bpnts + smal) {
	goto L1010;
    }
/* ****    REFERENCES TO CURVE POINTS ARE INVALID. */
    *irr = 14;
    goto L30;
L1080:
    if ((d__1 = an2 - bpnts, abs(d__1)) < smal) {
	goto L1090;
    }
/* ****    LAST POINT REFERENCE SHOULD EQUAL LAST PT OF CURVE */
    *irr = 15;
    goto L30;
L1090:

/* ---    NOW SCAN SEGMENT DATA AND CHECK FOR CONSISTENCY */

    i__ = nsegst - 1;
    m = 1;
    an2 = zero;
L1110:
    i__ += m;
    if (i__ > lstemp) {
	goto L1180;
    }
    an1 = stemp[(i__ << 2) - 3];
    if ((d__1 = an1 - an2, abs(d__1)) < smal) {
	goto L1120;
    }
/* ****    AN1,AN2 HAVE INVALID RELATION */
    *irr = 16;
    goto L30;
L1120:
    an2 = stemp[(i__ << 2) - 2];
    if (an1 < an2 + smal && an2 < bpnts + smal) {
	goto L1110;
    }
/* ****    CURRENT TWO SCALARS HAVE INCONSISTENT RELATION */
    *irr = 17;
    goto L30;
L1180:
    if ((d__1 = an2 - bpnts, abs(d__1)) < smal) {
	goto L1190;
    }
/* ****    LAST SEGMENT MUST TERMINATE IN LAST POINT */
    *irr = 18;
    goto L30;
L1190:
/* ------------------------------------------------ */
/* ---     CONSISTENCY CHECKING COMPLETED ON FLOW/SEGMENT INPUT */

/* ---     MAJOR FLOW PROCESSING, ALL FLOW COMMAND INFORMATION */
/* ---     IS STORED IN THE STEMP ARRAY WHOSE ROWS WILL BE INDEXED */
/* ---     BY IST.  FLOW INFORMATION, INCLUDING ARC SUMMARY BLOCKS */
/* ---     AND FLOW RATE SPLINES ARE CONTAINED IN THE ARRAY ST */
/* ---     SUMMARY INFORMATION IS INDEXED BY IST AND SPLINE */
/* ---     FUNCTIONS ARE INDEXED BY IFLAVL */

/* ---     SAVE STARTING VALUES FOR  FLOW AND SEGMENT SUMMARY */
/* ---     BLOCKS */
    iflost = 1;
    isegst = npts;
    isplst = isegst + numseg;
/* ---     INITIALIZE INDICES TO AVAILABLE SPACE */
    ist = iflost;
    ispl = isplst;
    istmax = maxsc * 6;
/* ---     ARRAY ST (=SC) WILL BE USED TO BUFFER AND ACCUMULATE */
/* ---     FLOW AND SEGMENT SUMMARY INFORMATION.  THIS DATA */
/* ---     WILL THEN BE EXAMINED FOR ERRORS AND LATER BE */
/* ---     CONSOLIDATED WITH THE REMAINING DEFINED CURVE CANON */
/* ---     FORM, PROVIDED NO ERRORS HAVE OCCURRED. */

    istem = 0;
    inctem = 1;
    irct = 0;

L1200:
    istem += inctem;
    if (istem >= nsegst) {
	goto L1300;
    }
    i1 = (integer) (stemp[(istem << 2) - 3] + one);
    i2 = (integer) stemp[(istem << 2) - 2];
    inctem = (integer) stemp[(istem << 2) - 1];
    tol = stemp[(istem << 2) - 1] - inctem;
/* ---     EXECUTE THIS FLOW PROCESSING FOR EACH CURVE FROM I1 TO I2 */

    i__1 = i2;
    for (j = i1; j <= i__1; ++j) {
	st[(ist << 2) - 4] = (doublereal) ispl;
	ispmx = istmax - ispl;
	st[(ist << 2) - 2] = stemp[(ist << 2) - 4];
/* ---     COMPUTE INDEX TO CURRENT CURVE */
	ncurv = (integer) ((canon[nh] + j - 1) * 24 + nh);

	if (ibugg_1.ibug != 11) {
	    goto L1219;
	}
	bad_(&c__1, &c__0, "NCUR", &ncurv, (ftnlen)4);
	bad_(&c_n1, &c__0, "J   ", &j, (ftnlen)4);
	bad_(&c__24, &c__1, "CAN ", &canon[ncurv - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "TOL ", &tol, (ftnlen)4);
	bad_(&c_n1, &c__0, "ISPM", &ispmx, (ftnlen)4);
L1219:

/* ---     BRANCH TO AREA FOR INDIVIDUAL FLOW PROCESSING */
	holfrm_(&stemp[(istem << 2) - 4], test, &c__1, &c__8, &nwd, (ftnlen)8)
		;
	if (s_cmp(test, arc, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L1320;
	}
	if (s_cmp(test, angle, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L1340;
	}
	if (s_cmp(test, chord, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L1360;
	}
	if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L1380;
	}
/* ****    INVALID SPECIFICATION FOR FLOW */
	ir = 20;
	goto L1290;

/* ---     FLOW PROCESSING FOR ONE CUBIC ARC BY ARC LENGTH. */
L1320:
	arcseg_(&canon[ncurv - 1], &st[(ispl << 2) - 4], &tol, &num, &ispmx, &
		ir);
	goto L1290;
/* ---     FLOW PROCESSING FOR ONE CUBIC ARC BY ANGLE. */
L1340:
	angseg_(&canon[ncurv - 1], &st[(ispl << 2) - 4], &tol, &num, &ispmx, &
		ir, &stemp[(istem + 1 << 2) - 4], &stemp[(istem + 3 << 2) - 4]
		);
	goto L1290;
/* ---     FLOW PROCESSING FOR ONE CUBIC ARC BY CHORD PROJECTION */
L1360:

/* ---     THE SET UP OF CHORDAL PARAMETERS MAY BE IMPLIED */
/* ---     SO BEGIN BY SETTING THEM UP FIRST. */
	for (ii = 1; ii <= 3; ++ii) {
	    for (jj = 1; jj <= 3; ++jj) {
		pp[ii + (jj << 2) - 5] = stemp[ii + (istem + jj << 2) - 5];
/* L1361: */
	    }
	}
/* ---     DEFAULT, CHORD IS DEFINED BY END POINTS OF COMBINED SEGMENT */
	if (stemp[(istem + 1 << 2) - 1] > smal) {
	    goto L1362;
	}

	nn = (integer) ((canon[nh] + i1 - 1) * 24 + nh);
	cncurv_(&zero, &canon[nn - 1], pp, &c__0);
L1362:
	if (stemp[(istem + 2 << 2) - 1] > smal) {
	    goto L1363;
	}
	nn = (integer) ((canon[nh] + i2 - 1) * 24 + nh);
	cncurv_(&one, &canon[nn - 1], &pp[4], &c__0);
L1363:
	sz = zero;
	for (jj = 1; jj <= 3; ++jj) {
	    pp[jj + 3] -= pp[jj - 1];
/* Computing 2nd power */
	    d__1 = pp[jj + 3];
	    sz += d__1 * d__1;
/* L1364: */
	}
	sz = sqrt(sz);
/* ****    TWO POINTS TOO CLOSE FOR PROPER CHORD */
	ir = 21;
	if (sz < smal) {
	    goto L1290;
	}
	ir = 0;
	for (jj = 1; jj <= 3; ++jj) {
	    pp[jj + 3] /= sz;
/* L1365: */
	}
	if (stemp[(istem + 3 << 2) - 1] > smal) {
	    goto L1366;
	}
/* L1370: */
/* ---     IF A VECTOR NORMAL TO THE PROJECTION PLANES HAS NOT BENN */
/* ---     SUPPLIED BY THE USER, THEN THE AXIS OF THE CHORD IS CHOSEN */
/* ---     AS A DEFAULT NORMAL VECTOR TO THESE PLANES */
	pp[8] = pp[4];
	pp[9] = pp[5];
	pp[10] = pp[6];
L1366:
	chdseg_(&canon[ncurv - 1], &st[(ispl << 2) - 4], &tol, &num, &ispmx, &
		ir, pp, &pp[4], &pp[8]);
	goto L1290;
/* ---     DIRECT IDENTITY PARAMETERIZATION */
L1380:
	ir = 22;
	num = 2;
	if (ispl + num > ispmx) {
	    goto L1290;
	}
	ir = 0;
/* ---     SET UP A SPLINE IDENTITY FUNCTION */
	st[(ispl << 2) - 4] = zero;
	st[(ispl << 2) - 3] = zero;
	st[(ispl << 2) - 2] = one;
	st[(ispl << 2) - 1] = zero;
	st[(ispl + 1 << 2) - 4] = one;
	st[(ispl + 1 << 2) - 3] = one;
	st[(ispl + 1 << 2) - 2] = one;
	st[(ispl + 1 << 2) - 1] = zero;
	goto L1290;

L1290:
	if (ir == 0) {
	    goto L1220;
	}
/* ****    ERROR PATH, INCREMENT ERROR COUNT AND RESET VALUES */
	++irct;
	st[(ist << 2) - 4] = (doublereal) (-ir);
	st[(ist << 2) - 3] = (doublereal) num;
	st[(ist << 2) - 1] = zero;
	ir = 0;
	num = 0;
	if (ibugg_1.ibug == 11) {
	    bad_(&c_n4, &c__1, "ERR=", &st[(ist << 2) - 4], (ftnlen)4);
	}
	++ist;
	goto L1210;
/* ---     NORMAL COMPLETION OF FLOW RATE FOR ONE ARC. */
L1220:
/* ---     STORE SUMMARY DATA FOR FLOW SPLINES LOCATION,NUMBER, */
/* ---     TYPE OF FLOW AND TOTAL SPAN */
	st[(ist << 2) - 4] = (doublereal) ispl;
	st[(ist << 2) - 3] = (doublereal) num;
/* ---     SAVE TYPE FLOW AND TOLERANCE IN 3RD LOCATION */
	holfrm_(&stemp[(istem << 2) - 4], test, &c__1, &c__8, &nwd, (ftnlen)8)
		;
	if (s_cmp(test, arc, (ftnlen)8, (ftnlen)8) == 0) {
	    st[(ist << 2) - 2] = tol + 1.f;
	}
	if (s_cmp(test, angle, (ftnlen)8, (ftnlen)8) == 0) {
	    st[(ist << 2) - 2] = tol + 2.f;
	}
	if (s_cmp(test, chord, (ftnlen)8, (ftnlen)8) == 0) {
	    st[(ist << 2) - 2] = tol + 3.f;
	}
	if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	    st[(ist << 2) - 2] = tol + 4.f;
	}
	st[(ist << 2) - 1] = st[(ispl + num - 1 << 2) - 4] - st[(ispl << 2) - 
		4];
	ispl += num;
	++ist;
	num = 0;
L1210:
	;
    }

    goto L1200;
L1300:

    if (irct == 0 && ibugg_1.ibug != 11) {
	goto L1401;
    }
/* ****    DUMP CURV INFORMATION TO DOCUMENT FAILURES */
    cform_("0 ***ERRORS WHILE PROCESSING FLOW DATA FOR CURVE", 
	    darray_1.darray, &c__1, &c__48, (ftnlen)48, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    jtop = ispl - 1;
    i__1 = jtop;
    for (jj = 1; jj <= i__1; ++jj) {
	jj1 = iflost + jj - 1;
	if (jj1 >= ist) {
	    goto L1305;
	}
	if (st[(jj1 << 2) - 4] >= 0.) {
	    goto L1305;
	}
	ir = (integer) (-st[(jj1 << 2) - 4]);
	i__2 = ir + 5500;
	bad_(&c_n1, &c__0, "IRR ", &i__2, (ftnlen)4);
L1305:
	bad_(&c_n4, &c__1, "CURV", &st[(iflost + jj - 1 << 2) - 4], (ftnlen)4)
		;
/* L1310: */
    }
    if (irct == 0) {
	goto L1401;
    }
/* ****    ERROR IN FLOW PROCESSING */
    *irr = ir + 5500;
    s_copy(rname, rnama, (ftnlen)8, (ftnlen)8);
    i__1 = imax2;
    for (il2 = 1; il2 <= i__1; ++il2) {
/* L8002: */
	if (*irr == izal2[il2 - 1]) {
	    s_copy(rname, rnam2, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax3;
    for (il3 = 1; il3 <= i__1; ++il3) {
/* L8003: */
	if (*irr == izal3[il3 - 1]) {
	    s_copy(rname, rnam3, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax4;
    for (il4 = 1; il4 <= i__1; ++il4) {
/* L8004: */
	if (*irr == izal4[il4 - 1]) {
	    s_copy(rname, rnam4, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax5;
    for (il5 = 1; il5 <= i__1; ++il5) {
/* L8005: */
	if (*irr == izal5[il5 - 1]) {
	    s_copy(rname, rnam5, (ftnlen)8, (ftnlen)8);
	}
    }
    error_(irr, rname, (ftnlen)8);
    goto L999;

/* --------------------------------------------------------- */
/* ---    FLOW SPLINES HAVE BEEN CREATED FOR EACH ARC, NOW */
/* ---     SET UP SEGMENT DATA. */
L1401:
/* ---    NOW PROCESS CURVE SEGMENT INFORMATION */
    istem = nsegst - 1;
    inctem = 1;
L1400:
    istem += inctem;
    if (istem > lstemp) {
	goto L1490;
    }
/* ---    PROCESS CURVE SEGMENTS, ONE AT A TIME */
    st[(ist << 2) - 2] = stemp[(istem << 2) - 4];
    st[(ist << 2) - 4] = stemp[(istem << 2) - 3];
    st[(ist << 2) - 3] = stemp[(istem << 2) - 2];
    st[(ist << 2) - 1] = zero;
    if ((d__1 = st[(ist << 2) - 4] - st[(ist << 2) - 3], abs(d__1)) < smal) {
	goto L1410;
    }
/* ---    IN CASE OF LENGTH TOTAL SPAN IS BASED ON TOTAL FLOW LENGTH */
    i1 = (integer) (st[(ist << 2) - 4] + one);
    i2 = (integer) st[(ist << 2) - 3];
    totlen = zero;
    i__1 = i2;
    for (ii = i1; ii <= i__1; ++ii) {
	totlen += st[(ii << 2) - 1];
/* L1440: */
    }
/* ---    STORE TOTAL LENGTH IN SEGMENT BLOCK */
    st[(ist << 2) - 1] = totlen;
/* ---     TOTLEN=NUMBER OF ARCS IN SEGMENT IN CASE OF PARAM */
    holfrm_(&st[(ist << 2) - 2], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	totlen = st[(ist << 2) - 3] - st[(ist << 2) - 4];
    }
/* ---     NOW CHANGE PARAMETER FLOW ON EACH SEGMENT, ARC BY ARC, */
/* ---     SO THAT THE TOTAL FLOW IS FROM ZERO TO ONE FOR THE */
/* ---     COMPLETE SEGMENT */
    sum = zero;
    i__1 = i2;
    for (j = i1; j <= i__1; ++j) {
/* ---     DETERMINE THE FACTOR FOR RESETTING FLOW FOR ARC J */
	span = st[(j << 2) - 1];
	factor = one / totlen;
	holfrm_(&st[(ist << 2) - 2], test, &c__1, &c__8, &nwd, (ftnlen)8);
	if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	    factor = one / (totlen * span);
	}
/* ---     NOW MODIFY ALL FLOW SPLINE FUNCTIONS FOR ARC J TO */
/* ---     CHANGE THE FLOW SCALE */
	nloc = (integer) st[(j << 2) - 4];
	nn = (integer) (st[(j << 2) - 4] + st[(j << 2) - 3] - one);
	i__2 = nn;
	for (jj = nloc; jj <= i__2; ++jj) {
	    st[(jj << 2) - 4] = st[(jj << 2) - 4] * factor + sum;
	    st[(jj << 2) - 2] /= factor;
/* L1460: */
	}

	st[(nloc << 2) - 1] = sum;
	tsum = sum + sum;
	nloc1 = nloc + 1;
	i__2 = nn;
	for (jj = nloc1; jj <= i__2; ++jj) {
	    st[(jj << 2) - 1] = st[(jj << 2) - 4] - st[(jj - 1 << 2) - 4] + 
		    tsum;
/* L1465: */
	}

	holfrm_(&st[(ist << 2) - 2], test, &c__1, &c__8, &nwd, (ftnlen)8);
	if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	    sum += one / totlen;
	}
	if (s_cmp(test, length, (ftnlen)8, (ftnlen)8) == 0) {
	    sum += span * factor;
	}
/* L1450: */
    }

    st[(ist << 2) - 3] -= st[(ist << 2) - 4];
/* ---     CONVERT ALPHANUMERIC DATA TO NUMBER CODE */
    holfrm_(&st[(ist << 2) - 2], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	st[(ist << 2) - 2] = 1.f;
    }
    if (s_cmp(test, length, (ftnlen)8, (ftnlen)8) == 0) {
	st[(ist << 2) - 2] = 2.f;
    }
L1410:

    if (ibugg_1.ibug != 11) {
	goto L1413;
    }
    bad_(&c__1, &c__0, "IST ", &ist, (ftnlen)4);
    bad_(&c__4, &c__1, "ST  ", &st[(ist << 2) - 4], (ftnlen)4);
L1413:

    ++ist;
    goto L1400;
/* ---     PROCESSING OF SEGMENT DATA FINISHED */
L1490:

/* ----------------------------------------------------------- */
/* ---     NOW MERGE THE ST ARRAY AND FLOW/SEGMENT INFORMATION */
/* ---     AND RECORD REQUIRED POINTERS IN THE SCURV HEADER */
/* ---     TABLE */
/* ---     NLOC POINTS JUST TO THE END OF THE CUBIC CURVE BLOCKS */
    anst = (canon[nh] + anpts - one) * 24.f + one;
    nct = (integer) (anst - one + anh - one);
    i__1 = ispl;
    for (ii = 1; ii <= i__1; ++ii) {
	for (jj = 1; jj <= 4; ++jj) {
	    ++nct;
/* ---     CONVERT ADDRESSES FROM ROW NOTATION TO SEQUENTIAL NOTATION */
	    if (ii < npts) {
		st[(ii << 2) - 4] = (st[(ii << 2) - 4] - one) * 4.f + anst;
	    }
	    canon[nct - 1] = st[jj + (ii << 2) - 5];
/* L1500: */
	}
    }
/* ---     NOW PLACE LOCATION POINTERS IN TO HEADER TABLE */
/* ---     LOCATION OF POINT BLOCKS */
    canon[nh + 3] = canon[nh] * 24.f + one;
/* ---     NUMBER OF FLOW BLOCKS (IF ANY) AND LOCATION */
    canon[nh + 4] = canon[nh + 2];
    canon[nh + 5] = canon[nh + 3] + (anpts - one) * 24.f;
/* ---     NUMBER OF SEGMENT BLOCKS AND STARTING LOCATION */
    canon[nh + 6] = (doublereal) numseg;
    canon[nh + 7] = canon[nh + 5] + canon[nh + 4] * 4.f;
/* ---     NUMBER OF FLOW BLOCKS AND STARTING LOCATION */
    canon[nh + 8] = (doublereal) (ispl - numseg - npts);
    canon[nh + 9] = canon[nh + 7] + canon[nh + 6] * 4.f;
/* ---     FINALLY SETUP THE TOTAL SIZE OF THE STRUCTURE */
    canon[nh + 10] = canon[nh + 9] + canon[nh + 8] * 4.f - one;
    canon[nh + 11] = one;

    if (ibugg_1.ibug != 11) {
	goto L4322;
    }
    nnnn = (integer) (canon[nh + 10] / 4.f + .1f);
    mmmm = -3;
    i__1 = nnnn;
    for (kkk = 1; kkk <= i__1; ++kkk) {
	mmmm += 4;
	bad_(&c__4, &c__1, "FCAN", &canon[nh - 1 + mmmm - 1], (ftnlen)4);
	bad_(&c_n1, &c__0, "INDX", &mmmm, (ftnlen)4);
/* L4321: */
    }
L4322:
    *irr = 0;

/* ------------------------------------------------- */
/* ---     THE PROCESSING OF FLOW FUNCTIONS ACROSS THE CURVE IS COMPLETE. */

L999:

    return 0;
} /* floseg_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef st


