/* APT108.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__10 = 10;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c_n1 = -1;
static integer c_n4 = -4;

/* *** SOURCE FILE : M0004345.V14   *** */

/* Subroutine */ int apt108_(doublereal *a, doublereal *a1, doublereal *a2, 
	doublereal *a3)
{
    /* Initialized data */

    static integer maxnop = 30;
    static integer nhd = 1;
    static doublereal point = 19.;
    static doublereal vector = 20.;
    static doublereal areal = 21.;
    static doublereal tanspl = 136.;
    static doublereal crsspl = 137.;
    static doublereal normal = 13.;
    static doublereal weight = 138.;
    static doublereal limit = 139.;
    static char curseg[6] = "CURSEG";
    static char spline[6] = "SPLINE";
    static char combin[6] = "COMBIN";
    static char end[6] = "END   ";
    static char traf[6] = "TRFORM";
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-7;
    static doublereal big = 99999999.;
    static doublereal smal1 = 1e-5;
    static doublereal smal2 = .001;
    static char subsc[8] = " (     )";
    static char bla[8] = "        ";
    static char rnam1[8] = "APT108  ";
    static char rnam2[8] = "SCURV   ";
    static char rnam3[8] = "SSPLIN  ";
    static char rnam4[8] = "SMOOTH  ";
    static char rnama[8] = "APT108??";
    static char rname[8] = "        ";
    static integer imax1 = 9;
    static integer izal1[9] = { 5121,5122,5123,5124,5125,5126,5127,5128,5129 }
	    ;
    static integer imax2 = 5;
    static integer izal2[5] = { 5751,5752,5760,5770,5771 };
    static integer imax3 = 10;
    static integer izal3[10] = { 5901,5902,5903,5904,5905,5906,5907,5908,5909,
	    5910 };
    static integer imax4 = 6;
    static integer izal4[6] = { 5921,5922,5923,5924,5925,5926 };

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal t;
    static integer m1;
    static doublereal al;
    static integer ii;
#define sc ((doublereal *)&sspad_1 + 1)
    static integer nh, nn, np, ns;
    static doublereal wt;
    static integer il1, il2, il3, il4, ns1, ns2;
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
#define scb ((doublereal *)&sspad_1 + 73)
    static integer kkc;
#define sci ((doublereal *)&sspad_1 + 1)
    static integer nwd, irr, nhd1;
#define scv0 ((doublereal *)&sspad_1 + 97)
#define scv1 ((doublereal *)&sspad_1 + 121)
#define scv2 ((doublereal *)&sspad_1 + 145)
    static integer irec, mode, nblk, isub, nbot;
    static char test[6];
    static integer ntop, nblk1;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static char test1[6], test2[6];
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
    static integer jmode;
    static doublereal ddmax;
    extern /* Subroutine */ int undef_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int sctra_(doublereal *, doublereal *, doublereal 
	    *, integer *), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
    static integer isize;
    extern /* Subroutine */ int tapop_(integer *, integer *);
    static integer nsize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), scurv_(
	    doublereal *, integer *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static char scname[16];
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), floseg_(integer *, integer *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static integer iflseg;
    extern /* Subroutine */ int scpict_(doublereal *, char *, integer *, 
	    ftnlen);
    static integer kkmode, ierror;
    extern /* Subroutine */ int cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer isprnt, npplus;
    static doublereal xmatrx[12];
    static integer nszsav;

/* ---  PURPOSE  IS TO ACCEPT PART PROGRAMMERS INPUT FOR THE DEFINITION */
/* ---  OF A SYNTHETIC CURVE AND PROCESS THIS  INTO  COONS RATIONAL */
/* ---   PARAMETRIC CUBIC SEGMENTS.  THE PROCESSED DATA BASE IS THEN */
/* ---   DISPLAYED ON THE VLFILE(SPRINT) AND SAVED(APT094) AS A LARGE DATA */
/* ---  DATA ARRAY. */
/* ---   A(3) INPUT  CONTAINS 1 AND 2 THE INTERNAL CANON FORM OF THE */
/* ---               SYNTHETIC CURVE .  A(3) IS THE PP NAME */
/* ---   BLANK COMMON CANON(41 THRU ... ) CONTAINS THE PART PROGRAMMERS */
/* ---           INPUT STREAM */
/* ---  SC IS THE WORK ARRAY WHICH IS USED TO BUILD UP THE ANALYTIC DEFIN */
/* ---               ITION OF THE CURVE */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/* ---     SC(4,6,31) HOLDS BASIC CURVE, REST HOLDS FLOW EDITED INPUT */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* .... SCULPTURED SURFACES SCRATCH PAD AREA */








/* ...                SYSTEM I/O FILES */





/* ---     THE FOLLOWING ARRAY IS SHARED FOR PRINTING */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --a;

    /* Function Body */



    holfrm_(&a[3], scname, &c__1, &c__8, &nwd, (ftnlen)16);
    s_copy(scname + 8, bla, (ftnlen)8, (ftnlen)8);
/* ---     IF SUBSCRIPT IS BIGGER  THAN ONE, ONLY SUBCRIPT IS SHOWN */
    unpack_(&a[1], &mode, &isize, &isub);
    if (isub < 1) {
	goto L8;
    }
    s_copy(scname + 8, subsc, (ftnlen)8, (ftnlen)8);
    iconv_(&isub, scname, &c__10, &c__4, (ftnlen)16);
    holfrm_(&a[isub * isize + isub], scname, &c__1, &c__8, &nwd, (ftnlen)16);
L8:
    np = 0;
    nh = 41;
    nhd1 = nhd + 1;
    nsize = (integer) (canon[nh + 3] + 39);
    nszsav = nsize;
    m1 = maxnop + nhd;
    ns = nh + 8;

/* ...SET TEST1 & TEST2 TO BE CHARACTER EQUIVALENTS OF A1 & A2. */
    holfrm_(a1, test1, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(a2, test2, &c__1, &c__6, &nwd, (ftnlen)6);

/* ---      FETCH THE TRFORM MATRIX IF PRESENT AND THEN TRUNCATE */
/* ---      THE LENGTH OF INPUT DATA TO IGNORE THE TRAILING MATRIX */
    if (s_cmp(test2, traf, (ftnlen)6, (ftnlen)6) != 0) {
	goto L9;
    }
    l = (integer) (canon[44] + 27);
    for (i__ = 1; i__ <= 12; ++i__) {
	xmatrx[i__ - 1] = canon[l + i__ - 1];
/* L7: */
    }
    nsize += -14;
    nszsav = nsize;
L9:

/* ---      SCAN INPUT STREAM FOR FLOW/SEG DATA.  IF FOUND IFLSEG=1 ELSE 0 */
    floseg_(&nsize, &nszsav, &c__1, &iflseg, &irr);
    if (irr != 0) {
	goto L995;
    }


/* ---    NOW REDUCE SIZE PARAMETER SINCE ALL FLOW/SEGMENT */
/* ---     INFORMATION HAS BEEN STORED IN THE STEMP BUFFER */
    nsize = nszsav;


/* ---     NORMAL PHYSICAL SHAPE OF CURVE IS PROCESSED NOW */
/* -------------------------------------------------------- */
/* ---     BRANCH TO SPECIAL PROCESSING FOR MODE COMBINE. */
    if (s_cmp(test1, combin, (ftnlen)6, (ftnlen)6) == 0) {
	goto L3000;
    }

/* ----     SCAN AND ORGANIZE INPUT DATA FOR SPLINE OR CURSEG DEFN. */
/* --- INITIALIZE THE SCRATCH PAD AREA FOR A CURVE */
    i__1 = m1;
    for (l = 1; l <= i__1; ++l) {
	for (k = 1; k <= 6; ++k) {
	    for (j = 1; j <= 4; ++j) {
/* L2: */
		sc[j + (k + l * 6 << 2) - 29] = zero;
	    }
	}
	if (l > nhd) {
	    sc[(l * 6 + 5 << 2) - 28] = one;
	}
	if (l > nhd) {
	    sc[(l * 6 + 5 << 2) - 27] = zero;
	}
/* L1: */
    }
/* ****  FIRST WORD MUST BE SPLINE OR CURSEG */
    sc[1] = (doublereal) nhd;
    irr = 1;
    holfrm_(&canon[ns - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, spline, (ftnlen)6, (ftnlen)6) != 0 && s_cmp(test, curseg, 
	    (ftnlen)6, (ftnlen)6) != 0) {
	goto L998;
    }
    if (s_cmp(test, spline, (ftnlen)6, (ftnlen)6) == 0) {
	sc[2] = 2.f;
    }
    if (s_cmp(test, curseg, (ftnlen)6, (ftnlen)6) == 0) {
	sc[2] = 3.f;
    }
    ++ns;

L10:
    t = canon[ns - 1];
    holfrm_(&t, test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, end, (ftnlen)6, (ftnlen)6) == 0 || ns > nsize) {
	goto L1000;
    }
    if (t == point) {
	goto L100;
    }
    if (t == tanspl || t == crsspl || t == normal) {
	goto L200;
    }
    if (t == weight) {
	goto L300;
    }
    if (t == limit) {
	goto L400;
    }
/* ****  ILLEGAL TERM IN INPUT STREAM */
    irr = 2;
    goto L998;
/* ---   PROCESS AN INPUT POINT */
L100:
    ++np;
    irr = 3;
    if (np > maxnop) {
	goto L998;
    }
    for (l = 1; l <= 3; ++l) {
/* L110: */
	sc[l + ((np + nhd) * 6 + 1 << 2) - 29] = canon[ns + l - 1];
    }
    ns += 4;

    goto L10;
/* ---  PROCESS VECTOR CONSTRAINTS */
L200:
/* ****  IF NO POINTS HAVE BEEN ENTERED, QUIT */
    irr = 4;
    if (np == 0) {
	goto L998;
    }
    k = 2;
    if (t == crsspl) {
	k = 3;
    }
    if (t == normal) {
	k = 4;
    }
/* ***   GEOMETRIC ENTRY SHOULD BE A VECTOR */
    irr = 5;
    if (canon[ns + 1] != vector) {
	goto L998;
    }
    for (l = 1; l <= 3; ++l) {
/* L210: */
	sc[l + (k + (np + nhd) * 6 << 2) - 29] = canon[ns + l + 1];
    }
    sc[(k + (np + nhd) * 6 << 2) - 25] = one;
    ns += 6;

    goto L10;
L300:
/* ****  GEOMETRIC ARGUMENT MUST BE REAL */
    irr = 6;
    if (canon[ns + 1] != areal) {
	goto L998;
    }
/* Computing MAX */
    d__1 = smal, d__2 = canon[ns + 2];
    wt = max(d__1,d__2);
    wt = min(one,wt);
    sc[((np + nhd) * 6 + 5 << 2) - 28] = wt;
    ns += 4;

    if (np > 0) {
	goto L10;
    }
/* ---   IF WEIGHT COMES BEFORE THE FIRST POINT, THIS WEIGHT IS APPLIED */
/* ---  TO ALL POINTS */
    i__1 = m1;
    for (i__ = nhd1; i__ <= i__1; ++i__) {
/* L350: */
	sc[(i__ * 6 + 5 << 2) - 28] = wt;
    }

    goto L10;
/* ---  PROCESS INPUT LIMIT CONSTRAINT */
L400:
/* ****  GEOMETRIC ARGUMENT MUST BE REAL */
    irr = 6;
    if (canon[ns + 1] != areal) {
	goto L998;
    }
/* Computing MAX */
    d__1 = zero, d__2 = canon[ns + 2];
    al = max(d__1,d__2);
    al = min(big,al);
    sc[((nhd + np) * 6 + 5 << 2) - 27] = al;
    ns += 4;

    if (np > 0) {
	goto L10;
    }
    i__1 = m1;
    for (i__ = nhd1; i__ <= i__1; ++i__) {
/* L450: */
	sc[(i__ * 6 + 5 << 2) - 27] = al;
    }

    goto L10;
/* ---   INPUT HAS BEEN FORMALLY LOADED INTO THE SC ARRAY */
/* ---  NOW CALL FOR ANALYTIC PROCESSING */
L1000:
    sc[3] = (doublereal) np;

    if (ssprt_1.ssprt && ssprt_1.sstest) {
	scpict_(sc, scname, &c__0, (ftnlen)16);
    }

    scurv_(sc, &irr);
    if (irr != 0) {
	ierror = irr;
    }
    if (irr != 0) {
	goto L996;
    }

/* ---   MOVE THE CURVE DATA FROM THE SCRATCH AREA TO BLANK COMMON */
    kkc = 40;
    npplus = (integer) (np + sc[1]);
    i__1 = npplus;
    for (k = 1; k <= i__1; ++k) {
	for (j = 1; j <= 6; ++j) {
	    for (i__ = 1; i__ <= 4; ++i__) {
		++kkc;
/* L9020: */
		canon[kkc - 1] = sc[i__ + (j + k * 6 << 2) - 29];
	    }
	}
    }

    goto L9000;

/* ---      FETCH ALL CURVES FROM A SCURV/COMBIN COMMAND */
/* ---      NOTE LOGIC FOR TREATMENT OF CONFLICTING CRSSPL AND NORMAL */
/* ---      CONSTRAINT VECTORS AT CURVE JUNCTIONS. */
L3000:
    np = (integer) canon[nh + 2];
    k = 0;
    i__1 = nsize;
    for (i__ = ns; i__ <= i__1; ++i__) {
	++k;
/* L3100: */
	sci[k - 1] = canon[i__ - 1];
    }
    ns = nh;
    i__ = 1;
    nblk = 0;
L4000:
    ii = (i__ << 1) - 1;
    jmode = 2;
    irr = 7;
    if (ckdef_(&sci[ii - 1])) {
	goto L998;
    }

/* ---     READ IN THE NEXT CURVE FROM THE INPUT STREAM. */

    apt094_(&jmode, &sci[ii - 1], &canon[ns - 1]);
/* **** */
/* ****    CURVES WITH A FLOW RATE CANNOT BE COMBINED YET */
/* ***      AT MOST ONE FLOW CURVE CAN BE COMBINED AT PRESENT */
    if (i__ > 1 && canon[ns + 1] > 9.f) {
	goto L998;
    }
    ns1 = ns;
    ns2 = ns + 24;
    nblk1 = (integer) canon[ns + 2];
    nblk += nblk1;
    ns = nblk1 * 24 + ns;
    if (i__ == 1) {
	goto L3200;
    }

    cncurv_(&zero, &canon[ns2 - 1], scv1, &c__1);
    scv2[0] = (d__1 = scv1[0] - scv0[0], abs(d__1));
    scv2[1] = (d__1 = scv1[1] - scv0[1], abs(d__1));
    scv2[2] = (d__1 = scv1[2] - scv0[2], abs(d__1));
/* Computing MAX */
    d__1 = max(scv2[0],scv2[1]);
    ddmax = max(d__1,scv2[2]);
/* **** */
    irr = 8;
    if (ddmax > smal1) {
	goto L998;
    }
    if (ddmax < smal) {
	goto L3300;
    }
    ddmax = canon[ns2 + 11];
    canon[ns2 - 1] = scv0[0] * ddmax;
    canon[ns2 + 3] = scv0[1] * ddmax;
    canon[ns2 + 7] = scv0[2] * ddmax;
L3300:
    ddmax = (d__1 = scv0[12] * scv1[12] + scv0[13] * scv1[13] + scv0[14] * 
	    scv1[14] - one, abs(d__1));
/* **** */
    irr = 9;
    if (ddmax > smal2) {
	goto L998;
    }

L3400:
    for (j = 20; j <= 24; j += 4) {
	if ((d__1 = scb[j - 1], abs(d__1)) > smal) {
	    goto L3600;
	}
	if ((d__1 = canon[ns1 + j - 2], abs(d__1)) < smal) {
	    goto L3600;
	}
	for (k = 1; k <= 4; ++k) {
/* L3500: */
	    scb[j + k - 5] = canon[ns1 + j + k - 6];
	}
L3600:
	;
    }
    for (k = 1; k <= 24; ++k) {
/* L3700: */
	canon[ns1 + k - 2] = scb[k - 1];
    }
L3200:
    ++i__;
    if (i__ > np) {
	goto L3800;
    }
    for (k = 1; k <= 24; ++k) {
/* L3900: */
	scb[k - 1] = canon[ns + k - 2];
    }
    cncurv_(&one, scb, scv0, &c__1);
    goto L4000;

L3800:
    canon[nh + 2] = (doublereal) nblk;
    canon[nh + 1] = 4.f;

/* ---     NORMAL PHYSICAL SHAPE OF CURVE HAS NOW BEEN GENERATED */
/* ---     FLOW/SEGMENTATION PROCESSING NOW FOLLOWS. */

L9000:
    canon[nh + 3] = canon[nh] * 24.f + one;
/* ---     NOW ZERO OUT PART OF THE HEADER TABLE CAREFULLY */
    nn = 10;
    i__1 = nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	canon[nh + i__ + 4] = zero;
/* L1005: */
    }

/* ---     IF NO FLOW INPUT IS AVAILABLE, SAVE THE CURVE DATA */
/* ---     ON AN EXTERNAL FILE */
    if (iflseg == 0) {
	goto L9010;
    }

    floseg_(&nsize, &nszsav, &c__2, &iflseg, &irr);
    if (irr != 0) {
	goto L995;
    }


L9010:
/* ---     SAVE SURFACE ON EXTERNAL FILE */
/* ---      FIRST SAVE THE SIZE OF THE ARRAY IN THE INTERNAL FORM */

    canon[nh + 3] = canon[nh] * 24.f + one;
    if (canon[nh + 6] < smal) {
	canon[nh + 10] = (canon[nh] + canon[nh + 2]) * 24.f;
    }
    if (canon[nh + 6] < smal) {
	canon[nh + 11] = one;
    }

    a[2] = canon[nh + 10];
/* L6100: */

/*   BESTIMMUNG DER APT-RECORD-NR. */
    irec = -5;
    tapop_(&symfil_1.axfile, &irec);
    canon[nh - 1] = (doublereal) irec;
    isprnt = 2;
    if (ssprt_1.sstest) {
	isprnt = 3;
    }
    if (ssprt_1.ssprt) {
	scpict_(&canon[nh - 1], scname, &isprnt, (ftnlen)16);
    }
    if (s_cmp(test2, traf, (ftnlen)6, (ftnlen)6) == 0) {
	sctra_(xmatrx, &a[1], &canon[nh - 1], &isprnt);
    }
    kkmode = 1;
    apt094_(&kkmode, &a[1], &canon[nh - 1]);
    irr = 0;

/* ---     SET THE MODE FOR LEVEL OF VERIFICATION PRINT */
    goto L9999;

/* ****    AREA OF CODE TO HANDLE MOST ERROR MESSAGES AND TERMINATIONS */
L998:
    ierror = irr + 5120;
L996:
    s_copy(rname, rnama, (ftnlen)8, (ftnlen)8);
    i__1 = imax1;
    for (il1 = 1; il1 <= i__1; ++il1) {
/* L7001: */
	if (ierror == izal1[il1 - 1]) {
	    s_copy(rname, rnam1, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax2;
    for (il2 = 1; il2 <= i__1; ++il2) {
/* L7002: */
	if (ierror == izal2[il2 - 1]) {
	    s_copy(rname, rnam2, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax3;
    for (il3 = 1; il3 <= i__1; ++il3) {
/* L7003: */
	if (ierror == izal3[il3 - 1]) {
	    s_copy(rname, rnam3, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax4;
    for (il4 = 1; il4 <= i__1; ++il4) {
/* L7004: */
	if (ierror == izal4[il4 - 1]) {
	    s_copy(rname, rnam4, (ftnlen)8, (ftnlen)8);
	}
    }
    error_(&ierror, rname, (ftnlen)8);
    if (irr == 9) {
	goto L3400;
    }
    if (s_cmp(test1, combin, (ftnlen)6, (ftnlen)6) == 0) {
	goto L995;
    }

    if (ssprt_1.ssprt && ssprt_1.sstest) {
	scpict_(sc, scname, &c__1, (ftnlen)16);
    }
L995:
    undef_(&a[1]);

/* ****    TERMINATION OF ERROR HANDLING CODE */

/* ---    QUIT PROCESSING HERE */
L9999:

    if (ibugg_1.ibug != 11) {
	goto L9711;
    }
/* ---      DUMP THE ENTIRE SCURV ARRAY */
    ntop = (integer) (canon[nh + 10] + nh - 1);
    nbot = nh;
    i__1 = ntop;
    for (i__ = nbot; i__ <= i__1; i__ += 4) {
	if ((i__ - nbot) % 24 == 0) {
	    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	}
	bad_(&c_n4, &c__1, "CANN", &canon[i__ - 1], (ftnlen)4);
/* L9712: */
    }
L9711:

    return 0;
} /* apt108_ */

#undef bcanon
#undef sscan
#undef canon
#undef scv2
#undef scv1
#undef scv0
#undef sci
#undef scb
#undef can
#undef sc


