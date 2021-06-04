/* APT107.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

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
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__8 = 8;
static integer c__10 = 10;
static integer c__4 = 4;

/* *** SOURCE FILE : M0001869.W01   *** */

/* Subroutine */ int apt107_(doublereal *a, doublereal *arg1, doublereal *
	arg2, doublereal *arg3)
{
    /* Initialized data */

    static doublereal vpoint = 19.;
    static doublereal vvecto = 20.;
    static doublereal vscala = 21.;
    static doublereal vclw = 58.;
    static doublereal vcclw = 59.;
    static doublereal vminus = 41.;
    static doublereal vplus = 42.;
    static char ruled[6] = "RULED ";
    static char revol[6] = "REVOLV";
    static char imesh[6] = "SMESH ";
    static char iplus[6] = "PLUS  ";
    static char iminus[6] = "MINUS ";
    static char ixyz[6] = "XYZ   ";
    static char ixy[6] = "XYPLAN";
    static char iyz[6] = "YZPLAN";
    static char izx[6] = "ZXPLAN";
    static char isplin[6] = "SPLINE";
    static char ipnve[6] = "PNTVEC";
    static char iplgn[6] = "POLYGN";
    static char ipnson[6] = "PNTSON";
    static char gencur[6] = "GENCUR";
    static char combin[6] = "COMBIN";
    static char traf[6] = "TRFORM";
    static doublereal smal = 1e-10;
    static doublereal zero = 0.;
    static char ctran[6*5] = "TRANSL" "XYROT " "YZROT " "ZXROT " "SCALE ";
    static integer nctran = 5;
    static char cros[6] = "CROSS ";
    static char ssname[16] = "                ";
    static char rnam1[8] = "APT107  ";
    static char rnam2[8] = "PNTSON  ";
    static char rnam3[8] = "CTRANS  ";
    static char rnam4[8] = "MESH    ";
    static char rnam5[8] = "REVOLV  ";
    static char rnam6[8] = "SRFCOM  ";
    static char rnam7[8] = "GENCRV  ";
    static char rnam8[8] = "DISEG   ";
    static char rnam9[8] = "COMPTW  ";
    static char rna10[8] = "SSPLIN  ";
    static char rna11[8] = "SMOOTH  ";
    static char rnama[8] = "APT107??";
    static char rname[8] = "        ";
    static integer imax1 = 12;
    static integer izal1[12] = { 5001,5002,5003,5004,5005,5006,5007,5371,5373,
	    5374,5375,5376 };
    static integer imax2 = 3;
    static integer izal2[3] = { 5391,5392,5393 };
    static integer imax3 = 3;
    static integer izal3[3] = { 5377,5378,5379 };
    static integer imax4 = 13;
    static integer izal4[13] = { 5210,5211,5212,5213,5214,5215,5216,5217,5218,
	    5219,5220,5222,5300 };
    static integer imax5 = 4;
    static integer izal5[4] = { 5352,5354,5355,5356 };
    static integer imax6 = 8;
    static integer izal6[8] = { 5011,5012,5013,5014,5015,5016,5017,-5019 };
    static integer imax7 = 20;
    static integer izal7[20] = { 5025,5026,5027,5028,5029,5030,5031,5032,5033,
	    5034,5035,5036,5037,5038,5039,5040,5041,5043,5044,5045 };
    static integer imax8 = 4;
    static integer izal8[4] = { 5021,5022,5023,5024 };
    static integer imax9 = 1;
    static integer izal9[1] = { 5396 };
    static integer ima10 = 10;
    static integer iza10[10] = { 5901,5902,5903,5904,5905,5906,5907,5908,5909,
	    5910 };
    static integer ima11 = 6;
    static integer iza11[6] = { 5921,5922,5923,5924,5925,5934 };
    static doublereal vaxis = 146.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n, i1, j1, ia, ja;
    static doublereal ak;
    static integer ib, i10, i11;
    static doublereal pa[3], pb[3];
    static integer ii, jj, nn;
    static doublereal vl, ty[3];
    static integer il1, il2, il3, il4, il5, il6, il7, il8, il9;
    static doublereal ss2;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ier, nph;
    static doublereal dum;
    static integer nwd, irr;
#define snn ((doublereal *)&sspad_1 + 1)
    static integer itw, ktw[5], kty[5];
    static doublereal anga, angb;
    static integer locc, mode;
    static doublereal asav[10];
    extern /* Subroutine */ int mesh_(integer *, integer *, integer *, char *,
	     doublereal *, ftnlen);
    static integer isub;
    static doublereal temp;
    static integer ncur;
    static char test[6];
    static integer ntot;
#define sout ((doublereal *)&sspad_1 + 50)
    static char test1[6], test2[6], test3[6];
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static integer nbase;
#define canon ((doublereal *)&_BLNK__1)
    static integer jmode, icclw;
    extern /* Subroutine */ int undef_(doublereal *);
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer lngth;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer irule, isize, nsize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer kctrx;
    extern /* Subroutine */ int sstra_(doublereal *, doublereal *, doublereal 
	    *, integer *);
    static integer kbegin;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer lbegin;
    extern /* Subroutine */ int bezier_(doublereal *, doublereal *, integer *)
	    , unpack_(doublereal *, integer *, integer *, integer *), gencrv_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
#define kdynfl ((integer *)&addcom_1 + 48)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer klngth;
    extern /* Subroutine */ int ctrans_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *, integer *), srfcom_(integer *, integer *
	    ), topgen_(doublereal *);
    static integer ierror;
    extern /* Subroutine */ int sspict_(doublereal *, char *, integer *, 
	    ftnlen), revolv_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *);
    static integer isprnt;
    static doublereal xmatrx[12];
    extern /* Subroutine */ int pntson_(doublereal *, doublereal *, integer *,
	     integer *, integer *);

/* ---     MAIN ROUTINE FOR DEFINITION OF SCULPTURED SURFACES */
/* ---     INPUT CONSISTS OF THREE ARGUMENTS ARG1,ARG2,ARG3 */
/* ---     ARG1 CONTAINS THE FIRST MINOR WORD IN THE SSURF DEFINITION */
/* ---     THAT IS, ARG1 CONTAINS HOLLERITH SMESH IN SSURF/SMESH STATEMENT */
/* ---     ARG2 IS CURRENTLY UNUSED */
/* ---     ARG3 CONTAINS THE SURFACE SUB-TYPE. FOR EXAMPLE, */
/* ---     FOR SSURF/SMESH,XYPLAN, ARG3 CONTAINS HOLLERITH FOR XYPLAN. */
/* ---     THE REMAINING ARGUMENTS ARE PASSED IN BLANK COMMON BEGINNING */
/* ---     FROM LOCATION 41 ON.  THE FIRST 8 WORDS CONTAIN SUMMARY */
/* ---     DATA AND LOCATIONS 49 ON CONTAIN A CODED STREAM OF NUMBERS */
/* ---     REPRESENTING THE PART PROGRAMMERS INPUT.  MOST DATA IS */
/* ---     IN COUPLET FORM - PRECEEDED BY ITS APT4 CODE VALUE AND */
/* ---     THEN ITS NUMBERICAL CANON FORM.  FOR EXAMPLE, THE MINOR */
/* ---     WORD CLW IS REPRESENTED BY THE INTEGER CODE 58. AND THEN */
/* ---     BY ITS HOLLERITH FORM.  A POINT WOULD BE REPRESENTED BY */
/* ---     ITS GEOMETRIC CLASS CODE (19.) AND THEN BY ITS THREE NUMERICAL */
/* ---     VALUES.  ONE EXCEPTION IS THE WORD SPLINE WHICH IS CURRENTLY */
/* ---     PASSED IN A SINGLE WORD AS HOLLERITH DATA. */
/* ---     WITH THE HELP OF THE AUXILIARY BUFFER ARRAY SSPAD, THIS */
/* ---     INPUT DATA IS REPLACED BY A PROCESSED SSURF CANON FORM IN */
/* ---     BLANK COMMON FROM LOCATION 41 ON.  THIS FORM IS SAVED */
/* ---     ON AN EXTERNAL FILE BY MEANS OF A CALL TO APT094 */
/* ---     AN INTERNAL TWO-WORD CANON FORM CONTAINING THE SURFACE */
/* ---     SEQUENTIAL IDENTIFICATION NUMBER AND SIZE IS INSERTED */
/* ---     IN THE ARRAY A WHICH IS THE FIRST INPUT ARGUMENT. */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/* .... SCULPTURED SURFACES SCRATCH PAD AREA */





/*      DIMENSION A(*),SNN(49),SOUT(48),TY(3),KTY(5),KTW(5) */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* ---     SAVE AREA FOR HEADER OF INPUT CANON FORM */


/* ---  SOME MINOR WORD CODE NUMBERS FOLLOW */
    /* Parameter adjustments */
    --a;

    /* Function Body */

/* ---     FIRST PRESERVE THE INPUT HEADER TABLE */
    for (i__ = 1; i__ <= 10; ++i__) {
/* L1050: */
	asav[i__ - 1] = sscan[i__ - 1];
    }

/* ---     SET TEST1, TEST2 & TEST3 TO BE CHARACTER EQUIVALENTS OF ARG1, */
/* ---     ARG2 & ARG3 (WHICH DO NOT CHANGE) */
    holfrm_(arg1, test1, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(arg2, test2, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(arg3, test3, &c__1, &c__6, &nwd, (ftnlen)6);

/* ---     SET AUXILIARY FLAG FOR LEVEL OF PRINT */
    isprnt = 2;
    if (ssprt_1.sstest) {
	isprnt = 1;
    }
    if (! ssprt_1.ssprt) {
	isprnt = 0;
    }
    if (s_cmp(test2, traf, (ftnlen)6, (ftnlen)6) != 0) {
	goto L9;
    }
    l = (integer) (sscan[4] - 13);
    for (i__ = 1; i__ <= 12; ++i__) {
	xmatrx[i__ - 1] = sscan[l + i__ - 1];
/* L7: */
    }
    asav[4] += -14.f;
    sscan[4] += -14.f;
L9:
/* --- */
    ier = 0;
    irule = 0;
    ierror = 0;
/* ---     HEADER  * PATCH * */
    holfrm_(&a[3], ssname, &c__1, &c__8, &nwd, (ftnlen)16);
    cform_("        ", ssname, &c__8, &c__8, (ftnlen)8, (ftnlen)16);
    unpack_(&a[1], &mode, &isize, &isub);
    if (isub < 1) {
	goto L8;
    }
    holfrm_(&a[isub * isize + isub], ssname, &c__1, &c__8, &nwd, (ftnlen)16);
    cform_(" (     )", ssname, &c__8, &c__8, (ftnlen)8, (ftnlen)16);
    iconv_(&isub, ssname, &c__10, &c__4, (ftnlen)16);
L8:
/* ---     CHECK FOR SURFACE TYPE */
    if (s_cmp(test1, gencur, (ftnlen)6, (ftnlen)6) == 0) {
	goto L4000;
    }
    if (s_cmp(test1, combin, (ftnlen)6, (ftnlen)6) == 0) {
	goto L5000;
    }
    sscan[4] = 1.f;
    if (s_cmp(test1, ruled, (ftnlen)6, (ftnlen)6) == 0 || s_cmp(test1, revol, 
	    (ftnlen)6, (ftnlen)6) == 0) {
	goto L2500;
    }
/* ---     CHECK IF DEFN IS CURVE BY CURVE GENERAL TRANSFORM */
    i__1 = nctran;
    for (i__ = 1; i__ <= i__1; ++i__) {
	kctrx = i__;
	if (s_cmp(test1, ctran + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L2600;
	}
/* L6: */
    }
/* ---      KCTRX=0 MEANS TRANSFORM IS NOT CURVE BY CURVE TYPE. */
    kctrx = 0;
    if (s_cmp(test1, imesh, (ftnlen)6, (ftnlen)6) == 0) {
	goto L1000;
    }
    if (s_cmp(test3, ipnve, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[5] = 1.f;
    }
    if (s_cmp(test3, iplgn, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[5] = 2.f;
    }
    if (s_cmp(test3, ipnson, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[5] = 3.f;
    }
    if (s_cmp(test3, iplus, (ftnlen)6, (ftnlen)6) == 0 || s_cmp(test3, iminus,
	     (ftnlen)6, (ftnlen)6) == 0) {
	sscan[5] = 1.f;
    }
    sscan[6] = 1.f;
    holfrm_(&sscan[8], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, iminus, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[6] = -1.f;
    }
    if (s_cmp(test, iminus, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[8] = vminus;
    }
    if (s_cmp(test, iplus, (ftnlen)6, (ftnlen)6) == 0) {
	sscan[8] = vplus;
    }
    sscan[3] = sscan[2];
    nph = (integer) sscan[3];
    ss2 = sscan[3] * 49.f;
    sscan[2] = sscan[3] * 4.f;
    sscan[7] = ss2 + 10.f + sscan[2] + sscan[3] * 6.f;
    nn = nph * 6 + 10;
    if (sscan[5] != 1.f) {
	goto L200;
    }
    goto L100;

/* ---     POINTER TABLE   * PATCH * */
L10:
    nn = nph * 6 + 10;
    temp = nn + 1.f;
    ak = 0.f;
    i__1 = nn;
    for (i__ = 11; i__ <= i__1; i__ += 6) {
	sscan[i__ - 1] = 4.f;
	sscan[i__] = 4.f;
	sscan[i__ + 1] = 4.f;
	sscan[i__ + 2] = 1.f;
	sscan[i__ + 3] = temp + ak * 49.f;
	sscan[i__ + 4] = temp + ss2 + ak * 4.f;
	ak += 1.f;
/* L20: */
    }
    goto L3000;

/* ---      VALUE TABLE   * PATCH * */
/* ---      *  PNTVEC * */
L100:
    k = 0;
    m = 10;
    j1 = 9;
    i__1 = nph;
    for (l = 1; l <= i__1; ++l) {
	for (i__ = 1; i__ <= 16; ++i__) {
	    j = m + k * 3;
	    snn[i__ - 1] = sscan[j - 1];
	    snn[i__ + 15] = sscan[j];
	    snn[i__ + 31] = sscan[j + 1];
	    ++k;
/* L110: */
	}
	++m;
	for (ja = 1; ja <= 48; ++ja) {
	    jj = j1 + ja;
	    sscan[jj - 1] = snn[ja - 1];
/* L111: */
	}
	j1 += 49;
	sscan[j1 - 1] = 1.f;
/* L120: */
    }
L121:
    nn = nph * 6 + 10;
    lngth = nph * 49 + nn;
    klngth = nph * 49 + 9;
    i__1 = nph;
    for (l = 1; l <= i__1; ++l) {
	kbegin = klngth - l * 49;
	lbegin = lngth - l * 49;
	for (i__ = 1; i__ <= 49; ++i__) {
	    ib = kbegin + i__;
/* L123: */
	    snn[i__ - 1] = sscan[ib - 1];
	}
	for (i__ = 1; i__ <= 49; ++i__) {
	    ia = lbegin + i__;
	    ++nn;
	    sscan[ia - 1] = snn[i__ - 1];
/* L124: */
	}
/* L125: */
    }
    goto L10;
/* ---      * BEZIER POLYGN * PONTSON * */
L200:
    j = 0;
    ii = 9;
    i__1 = nph;
    for (n = 1; n <= i__1; ++n) {
	for (i__ = 1; i__ <= 48; ++i__) {
	    snn[i__ - 1] = sscan[ii + i__ - 1];
/* L210: */
	}
	if (sscan[5] == 2.f) {
	    bezier_(snn, sout, &ier);
	}
	if (sscan[5] == 3.f) {
	    pntson_(snn, sout, kty, ktw, &ier);
	}
	if (ier != 0) {
	    goto L9996;
	}
	for (j = 1; j <= 48; ++j) {
	    i1 = ii + j;
	    sscan[i1 - 1] = sout[j - 1];
/* L220: */
	}
	ii += 49;
	sscan[ii - 1] = 1.f;
/* L230: */
    }
    goto L121;
/* ---      HEADER  * MESH * */
L1000:
    sscan[4] = 2.f;
    sscan[6] = 1.f;
    sscan[8] = sscan[2];
    sscan[9] = sscan[3];
    if (sscan[8] == 2.f || sscan[9] == 2.f) {
	irule = 1;
    }
    sscan[3] = (sscan[8] - 1.f) * (sscan[9] - 1.f);
    nph = (integer) sscan[3];
    sscan[2] = sscan[3] * 4.f;
    if (s_cmp(test3, ixyz, (ftnlen)6, (ftnlen)6) == 0 || s_cmp(test3, isplin, 
	    (ftnlen)6, (ftnlen)6) == 0) {
	goto L1010;
    }
    vl = 21.f;
    if (irule == 1) {
	vl = 25.f;
    }
    ss2 = sscan[3] * vl;
    if (s_cmp(test3, ixy, (ftnlen)6, (ftnlen)6) == 0) {
	goto L1001;
    }
    if (s_cmp(test3, iyz, (ftnlen)6, (ftnlen)6) == 0) {
	goto L1002;
    }
    if (s_cmp(test3, izx, (ftnlen)6, (ftnlen)6) == 0) {
	goto L1003;
    }
    ierror = 5001;
    goto L9996;
L1001:
    sscan[5] = 1.f;
    ty[0] = 2.f;
    ty[1] = 2.f;
    ty[2] = 3.f;
    if (irule == 1) {
	ty[2] = 4.f;
    }
    goto L1020;
L1002:
    sscan[5] = 2.f;
    ty[0] = 3.f;
    if (irule == 1) {
	ty[0] = 4.f;
    }
    ty[1] = 2.f;
    ty[2] = 2.f;
    goto L1020;
L1003:
    sscan[5] = 3.f;
    ty[0] = 2.f;
    ty[1] = 3.f;
    if (irule == 1) {
	ty[1] = 4.f;
    }
    ty[2] = 2.f;
    goto L1020;
L1010:
    sscan[5] = 4.f;
    ty[0] = 3.f;
    ty[1] = 3.f;
    ty[2] = 3.f;
    vl = 37.f;
    if (irule == 1) {
	goto L1011;
    }
    ss2 = nph * vl;
    goto L1020;
L1011:
    ty[0] = 4.f;
    ty[1] = 4.f;
    ty[2] = 4.f;
    vl = 49.f;
    ss2 = sscan[3] * vl;
L1020:
    sscan[7] = ss2 + 10.f + sscan[2] + nph * 6.f;

    mesh_(&ierror, &ier, &itw, ssname, asav, (ftnlen)16);
    if (ierror > 0) {
	goto L9996;
    }
    if (itw != 0 || irule != 1) {
	goto L2200;
    }
    irule = 0;
    if (ty[0] == 4.f) {
	ty[0] = 3.f;
    }
    if (ty[1] == 4.f) {
	ty[1] = 3.f;
    }
    if (ty[2] == 4.f) {
	ty[2] = 3.f;
    }
    if (vl == 49.f) {
	vl = 37.f;
    }
    if (vl == 25.f) {
	vl = 21.f;
    }
    ss2 = sscan[3] * vl;
    sscan[7] = ss2 + 10.f + sscan[2] + sscan[3] * 6.f;
L2200:
/* ---      POINTER TABLE  *  MESH * */
    nn = nph * 6 + 10;
    ak = 0.f;
    temp = nn + 1.f;
    i__1 = nn;
    for (i__ = 11; i__ <= i__1; i__ += 6) {
	sscan[i__ - 1] = ty[0];
	sscan[i__] = ty[1];
	sscan[i__ + 1] = ty[2];
	sscan[i__ + 2] = 1.f;
	sscan[i__ + 3] = temp + vl * ak;
	sscan[i__ + 4] = temp + ss2 + ak * 4.f;
	ak += 1.f;
/* L1030: */
    }
    m = (integer) sscan[7];
    goto L3000;

/* ---  REVOLV AND RULED PROCESSING FOLLOWS */
L2500:
    nbase = 40;
    nsize = (integer) canon[nbase + 4];
    ncur = nbase + 10;
/* ---     CHECK FOR AVAILABLE SPACE FOR THIS SYNTHETIC CURVE */
    n = (integer) canon[ncur];
/* ****    NOT ENOUGH SPACE IN BUFFER TO LOAD THIS CURVE */
    irr = 1;
    if (n > sspad_1.nscnmx) {
	goto L9997;
    }

    jmode = 2;
    if (ckdef_(&canon[ncur - 1])) {
	goto L9997;
    }
    apt094_(&jmode, &canon[ncur - 1], sspad_1.scan);
/* ****     HAS THE CURVE BEEN SUCCESSFULLY RETRIEVED */
    irr = 2;
    if (ckdef_(&canon[ncur - 1])) {
	goto L9997;
    }
    ncur += 2;
/* ****     THE WORD AXIS MUST BE NEXT */
    irr = 3;
    if (canon[ncur - 1] != vaxis) {
	goto L9997;
    }
    ncur += 2;
    if (s_cmp(test1, ruled, (ftnlen)6, (ftnlen)6) == 0) {
	goto L2540;
    }
/* ****     CHECK FOR CORRECT GEOMETRIC DEFINITION OF AXIS */
    irr = 4;
    if (canon[ncur - 1] != vpoint) {
	goto L9997;
    }
    if (canon[ncur + 3] != vpoint && canon[ncur + 3] != vvecto) {
	goto L9997;
    }
    dum = 0.f;
    if (canon[ncur + 3] == vvecto) {
	dum = 1.f;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	pa[i__ - 1] = canon[ncur + i__ - 1];
/* L2510: */
	pb[i__ - 1] = dum * pa[i__ - 1] + canon[ncur + 4 + i__ - 1];
    }
    ncur += 8;
/* ****     THE NEXT INPUT SHOULD BE ANGULAR SPAN */
    irr = 5;
    if (canon[ncur - 1] != vclw && canon[ncur - 1] != vcclw) {
	goto L9997;
    }
    if (canon[ncur - 1] == vclw) {
	icclw = 1;
    }
    if (canon[ncur - 1] == vcclw) {
	icclw = -1;
    }
    ncur += 2;
/* ****     TWO ANGLES SHOULD FOLLOW */
    irr = 6;
    if (canon[ncur - 1] != vscala || canon[ncur + 1] != vscala) {
	goto L9997;
    }
    anga = canon[ncur];
    angb = canon[ncur + 2];
    goto L2550;
/* --- CYLINDRICAL PROCESSING */
L2540:
    if (canon[ncur - 1] == vvecto) {
	goto L2560;
    }
/* ****     ARGUMENTS MUST BE ONE VECTOR OR TWO POINTS */
    irr = 7;
    if (canon[ncur - 1] != vpoint || canon[ncur + 3] != vpoint) {
	goto L9997;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	pa[i__ - 1] = canon[ncur + i__ - 1];
/* L2570: */
	pb[i__ - 1] = canon[ncur + 4 + i__ - 1];
    }
    goto L2580;
L2560:
    for (i__ = 1; i__ <= 3; ++i__) {
	pa[i__ - 1] = 0.f;
/* L2590: */
	pb[i__ - 1] = canon[ncur + i__ - 1];
    }
/* ---    SET SPECIAL VALUES FOR CCLW INPUT */
L2580:
    icclw = 0;
    anga = 0.f;
    angb = 90.f;
L2550:

/* ---   CONDUCT MAIN ANALYTIC PROCESSING FOR SURFACE */
    revolv_(sspad_1.scan, pa, pb, &anga, &angb, &icclw, &irr, sscan);
    if (irr == 0) {
	goto L3000;
    }

    irr += 350;
    goto L9997;

/* ---      CURVE BY CURVE TRANSFORM TYPE */
L2600:
/* ---      FIRST FETCH BOTH CURVES AND LOAD INTO SCAN ARRAY */
    nbase = 40;
    ncur = nbase + 10;
    n = (integer) canon[ncur];
/* ****    NOT ENOUGH SPACE TO FETCH CURVE */
    irr = 1;
    if (n > sspad_1.nscnmx) {
	goto L2699;
    }
    jmode = 2;
/* ****    CURVE NOT DEFINED */
    if (ckdef_(&canon[ncur - 1])) {
	goto L2699;
    }
    jmode = 2;
    apt094_(&jmode, &canon[ncur - 1], sspad_1.scan);
/* ****    CURVE COULD NOT BE FETCHED */
    irr = 3;
    if (jmode != 2) {
	goto L2699;
    }
/* ****    THE WORD CROSS MUST BE NEXT */
    holfrm_(&canon[ncur + 2], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, cros, (ftnlen)6, (ftnlen)6) != 0) {
	goto L2699;
    }
/* ---     LOAD THE CROSS CURVE NEXT */
    locc = (integer) (sspad_1.scan[11] + 1.f);
/* ****    THERE IS NOT ENOUGH SPACE TO LOAD THE CROSS CURVE */
    n = (integer) canon[ncur + 4];
    irr = 4;
    if (n + locc > sspad_1.nscnmx) {
	goto L2699;
    }
/* ****    CURVE NOT DEFINED */
    irr = 5;
    if (ckdef_(&canon[ncur + 3])) {
	goto L2699;
    }
    jmode = 2;
    apt094_(&jmode, &canon[ncur + 3], &sspad_1.scan[locc - 1]);
/* ****    FAILURE IN ATTEMPT TO FETCH CROSS CURVE */
    irr = 6;
    if (jmode != 2) {
	goto L2699;
    }
/* ---      CURVES ARE READY, CALL TO GENERATE SURFACE */
    ctrans_(sspad_1.scan, &sspad_1.scan[locc - 1], &kctrx, &maxlda_1.maxlda, 
	    sscan, &irr);
    if (irr == 0) {
	goto L3000;
    }
    irr += 6;
/* ---     COMMON ERROR JUNCTION FOR CURVE BY CURVE TRANSFORMS */
L2699:
    irr += 370;
    goto L9997;


/* ---     PROCESSING FOR GENCUR TYPE SURFACE FOLLOWS. */

L4000:
    gencrv_(&a[1], arg1, arg2, arg3, &ierror);
/* ---     FILL IN UNDETERMINED HEADER ITEMS */
/* ---     SIZE OF THE TOPOLOGY TABLE IS 4*NUMBER OF PATCHES */
    sscan[2] = sscan[3] * 4.f;
/* ---     SET SUBCLASS TO GENCUR SURFACE */
    sscan[5] = 6.f;
/* ---     TOTAL SIZE OF SURFACE IS SUM OF HEADER, POINTERS, */
/* ---     VALUE TABLE AND TOPOLOGY TABLE */
    sscan[7] = sscan[1] + sscan[2] + 10.f + sscan[3] * 6.f;
    if (ierror != 0) {
	goto L9996;
    }
    goto L3000;

/* ---     PROCESS SSURF/COMBIN */
L5000:
    srfcom_(&isprnt, &irr);
    if (irr != 0) {
	goto L9995;
    }
    a[2] = sscan[7];
/* ---     BYPASS CALL TO TOPGEN, SINCE TOPOLOGY TABLE HAS BEEN GENERATED */
    goto L3002;

/* ---     FINAL PROCESSING FOR ALL SURFACE TYPES */
L3000:
    a[2] = sscan[7];
    ntot = (integer) sscan[7];
    i__1 = ntot;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = sscan[i__ - 1], abs(d__1)) < smal) {
	    sscan[i__ - 1] = zero;
	}
/* L3001: */
    }

    topgen_(sscan);
/* ---     ADJUST TYPE POINTER FOR GENCUR CASE */
/* --- IN THE REVOLV,RULED CASE THE SURFACE IS TREATED AS A PATCH TYPE */
/* --- FOR TOPOLOGY TABLE GENERATION AND SUBSEQUENTLY AS A SIMPLE MESH */
    if (s_cmp(test1, revol, (ftnlen)6, (ftnlen)6) != 0 && s_cmp(test1, ruled, 
	    (ftnlen)6, (ftnlen)6) != 0 && kctrx == 0) {
	goto L3006;
    }
    sscan[4] = 2.f;
    goto L3007;
L3006:
    if (s_cmp(test1, gencur, (ftnlen)6, (ftnlen)6) != 0) {
	sscan[1] = ss2;
    }
L3007:

    if (! ssprt_1.ssprt) {
	goto L3002;
    }
    if (s_cmp(test1, gencur, (ftnlen)6, (ftnlen)6) == 0) {
	goto L3002;
    }
    if (s_cmp(test2, traf, (ftnlen)6, (ftnlen)6) == 0) {
	goto L3002;
    }
    sspict_(sscan, ssname, &isprnt, (ftnlen)16);

L3002:
    if (s_cmp(test2, traf, (ftnlen)6, (ftnlen)6) == 0) {
	goto L3004;
    }
L3005:
    jmode = 1;
    apt094_(&jmode, &a[1], sscan);
    irr = 0;
    if (jmode != 1) {
	goto L9997;
    }

/* ---- */
    if (s_cmp(test1, gencur, (ftnlen)6, (ftnlen)6) != 0) {
	goto L3003;
    }
    if (! ssprt_1.ssprt) {
	goto L3003;
    }
    sspict_(sscan, ssname, &isprnt, (ftnlen)16);
    goto L3003;
L3004:
    sstra_(xmatrx, &a[1], sscan, &isprnt);
    if (s_cmp(test1, gencur, (ftnlen)6, (ftnlen)6) == 0) {
	goto L3003;
    }
    goto L3005;
L3003:

    if (ibugg_1.ibug != 11) {
	goto L5011;
    }
/* ---     LIST SURFACE CANON FORM FOR DEBUGGING PURPOSES */
    ntot = (integer) sscan[7];
    i__1 = -ntot;
    bad_(&i__1, &c__1, "CAN ", sscan, (ftnlen)4);
L5011:
    goto L9999;
/* ERROR JUNCTION OF SRFCOM, NO WARNING POSSIBLE !!!! */
L9995:
    irr = abs(irr) + 10;
L9997:
    ierror = irr + 5000;
L9996:
    s_copy(rname, rnama, (ftnlen)8, (ftnlen)8);
    i__1 = imax1;
    for (il1 = 1; il1 <= i__1; ++il1) {
/* L8001: */
	if (ierror == izal1[il1 - 1]) {
	    s_copy(rname, rnam1, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax2;
    for (il2 = 1; il2 <= i__1; ++il2) {
/* L8002: */
	if (ierror == izal2[il2 - 1]) {
	    s_copy(rname, rnam2, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax3;
    for (il3 = 1; il3 <= i__1; ++il3) {
/* L8003: */
	if (ierror == izal3[il3 - 1]) {
	    s_copy(rname, rnam3, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax4;
    for (il4 = 1; il4 <= i__1; ++il4) {
/* L8004: */
	if (ierror == izal4[il4 - 1]) {
	    s_copy(rname, rnam4, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax5;
    for (il5 = 1; il5 <= i__1; ++il5) {
/* L8005: */
	if (ierror == izal5[il5 - 1]) {
	    s_copy(rname, rnam5, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax6;
    for (il6 = 1; il6 <= i__1; ++il6) {
/* L8006: */
	if (ierror == izal6[il6 - 1]) {
	    s_copy(rname, rnam6, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax7;
    for (il7 = 1; il7 <= i__1; ++il7) {
/* L8007: */
	if (ierror == izal7[il7 - 1]) {
	    s_copy(rname, rnam7, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax8;
    for (il8 = 1; il8 <= i__1; ++il8) {
/* L8008: */
	if (ierror == izal8[il8 - 1]) {
	    s_copy(rname, rnam8, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax9;
    for (il9 = 1; il9 <= i__1; ++il9) {
/* L8009: */
	if (ierror == izal9[il9 - 1]) {
	    s_copy(rname, rnam9, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = ima10;
    for (i10 = 1; i10 <= i__1; ++i10) {
/* L8010: */
	if (ierror == iza10[i10 - 1]) {
	    s_copy(rname, rna10, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = ima11;
    for (i11 = 1; i11 <= i__1; ++i11) {
/* L8011: */
	if (ierror == iza11[i11 - 1]) {
	    s_copy(rname, rna11, (ftnlen)8, (ftnlen)8);
	}
    }
    error_(&ierror, rname, (ftnlen)8);
/* L9998: */
    undef_(&a[1]);

L9999:
    return 0;
} /* apt107_ */

#undef kdynfl
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef sout
#undef snn
#undef can


