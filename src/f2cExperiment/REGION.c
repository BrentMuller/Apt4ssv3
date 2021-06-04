/* REGION.f -- translated by f2c (version 20100827).
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
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
} glflgs_;

#define glflgs_1 glflgs_

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
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4];
} cclear_;

#define cclear_1 cclear_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;
static doublereal c_b12 = 1.;
static integer c__9 = 9;
static integer c__22806 = 22806;
static integer c__22801 = 22801;
static integer c__22802 = 22802;
static integer c__22803 = 22803;
static integer c__22804 = 22804;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__22805 = 22805;

/* *** SOURCE FILE : M0012301.V02   *** */

/* Subroutine */ int region_(doublereal *arg1, doublereal *arg2)
{
    /* Initialized data */

    static char in[4] = "IN  ";
    static char out[4] = "OUT ";
    static char off[4] = "OFF ";
    static integer numreg = 0;
    static integer numre1 = 0;
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    static doublereal equiv_0[1], equiv_3[6];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
#define p (equiv_3 + 2)
    static doublereal r__, u, v, w[2];
    static integer i1, j1, j2;
#define u1 (equiv_3)
#define v1 (equiv_3 + 1)
    static integer ia, j11, j12, ie, j13, j14;
    static doublereal du, dv;
    static integer iq, np, iu, iv;
    static doublereal ww;
    static integer ia1, j111;
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer iee, npa;
#define pat (equiv_0)
    static integer nwd;
    static doublereal wcv;
    extern integer bcdf_(char *, ftnlen);
#define ipat ((integer *)equiv_0)
    static integer ires, numd, nseq;
    static doublereal umin, vmin, umax;
    static integer ipps;
    static doublereal vmax;
    static char test[4];
    static integer nump, iarg1;
    extern /* Subroutine */ int apt094_(), numf2_(doublereal *, doublereal *, 
	    doublereal *);
    static integer nump1;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer itaus, iuvsc;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static doublereal outin;
    static integer inout;
    static doublereal vcurr[2], vprev[2];
    static integer numpm2, ldaflg;
    static doublereal canind;
    static char badmsg[20];
    extern /* Subroutine */ int cldatf_(doublereal *, doublereal *, integer *,
	     doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer loccan;
    static doublereal arylda[2];
    static integer iregio[200]	/* was [4][50] */;
    extern /* Subroutine */ int ataper_(doublereal *, integer *, integer *, 
	    integer *, integer *), record_(integer *), holfrm_(doublereal *, 
	    char *, integer *, integer *, integer *, ftnlen), getver_(
	    doublereal *, doublereal *, integer *), cprint_(char *, ftnlen);
    static integer numcrs, numpat;
    extern /* Subroutine */ int setver_(doublereal *);
#define result (equiv_3)
    static integer numspl;


/* PROCESSES THE REGION/ ... STATEMENT */

/*       ARG1 : REAL NUMBER OF THE CLDAT-SECTION */
/*       ARG2 : IN, OUT OR OFF */



/* ---     REGION FLAG */


/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */



/* SCULPTURED SURFACES CANONICAL FORM IN BLANK COMMON */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* REGION STORAGE */

/* SCULPTURED SURFACES INTERMEDIATE STORAGE */


/* .... SCULPTURED SURFACES SCRATCH PAD AREA */





/* COMMON FOR REGIONAL STARTUP AND RETRACT VALUES */
/*              (1) : START */
/*              (2) : AWAY */
/*              (3) : BACK */
/*              (4) : THRU */
/* DIRMOT(3,4): ARRAY FOR MOTDIR, NORMAL OR VECTOR VALUES */
/*              (1,I) : VALUES OF MOTDIR AND/OR NORMAL */
/*              (2,I) */
/*           OR (1,I) : VALUES OF VECTOR */
/*              (2,I) */
/*              (3,I) */
/* GOFEED(4)  : ARRAY FOR MOTION FEEDRAT */
/*              (1)   : FEDRAT OF START-MOTION (START AT FIRST POINT) */
/*              (2)   : FEDRAT OF AWAY-MOTION */
/*              (3)   : FEDRAT OF BACK-MOTION */
/*              (4)   : FEDRAT OF THRU-MOTION (RETRACT AT LAST POINT) */
/* GLFEED     : VARIABLE FOR NORMAL FEDRAT BEFORE GOMILL OR GOLOFT */
/* IRETRO(4)  : ARRAY FOR START, AWAY, BACK, THRU */
/*              (1) : START */
/*              (2) : AWAY */
/*              (3) : BACK */
/*              (4) : THRU */
/*                    0 : NOT USED */
/*                    1 : CONDITION SET */
/* IDIRMO(4)  : ARRAY FOR START ON AND END CONDITION */
/*                    0 : NOT SET */
/*                    1 : MOTDIR AND/OR NORMAL */
/*                    2 : VECTOR */
/* ICANIN(4)  : ARRAY FOR THE CANONICAL FORM INDEX OF THE SURFACE */
/*                    0 : NOT SET */
/*                    IC: INDEX */

/* CONTROL OF TEST-OUTPUT */



/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* .... INITIALIZE CHARACTER ITEMS */
    if (first) {
	ipat[0] = bcdf_("CLDA", (ftnlen)4);
	ipat[1] = bcdf_("TA  ", (ftnlen)4);
	ipps = bcdf_("PPS ", (ftnlen)4);
	first = FALSE_;
    }
    holfrm_(arg2, test, &c__1, &c__4, &nwd, (ftnlen)4);

/*    SWITCH OFF REGION FLAG IF >REGION/...,OFF< */
    if (s_cmp(test, off, (ftnlen)4, (ftnlen)4) != 0) {
	goto L1;
    }
    glflgs_1.regflg = 0;
    goto L999;

/* SEARCH FOR ALREADY PROCESSED REGION */
L1:
    iarg1 = (integer) (*arg1);
    if (s_cmp(test, in, (ftnlen)4, (ftnlen)4) == 0) {
	outin = 0.;
    }
    if (s_cmp(test, out, (ftnlen)4, (ftnlen)4) == 0) {
	outin = 1.;
    }
    if (numreg == 0) {
	goto L3;
    }
    inout = (integer) outin;
    i__1 = numreg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (iregio[(i__ << 2) - 4] != iarg1) {
	    goto L2;
	}
	if (iregio[(i__ << 2) - 3] != inout) {
	    goto L2;
	}
	cclear_1.reglda[0] = (doublereal) iregio[(i__ << 2) - 2];
	cclear_1.reglda[1] = (doublereal) iregio[(i__ << 2) - 1];
	glflgs_1.regflg = 1;
	goto L700;
L2:
	;
    }

/* FETCH THE NUMBER OF POINTS IN THE ID-AREA OUT OF EXFILE */
L3:
    numf2_(&r__, pat, arg1);
    nump = (integer) r__;

/* COMPUTE RECORD NUMBER OF ASSOCIATED SSURF */
    cldatf_(p, arg1, &ipps, &c_b12);
    npa = (integer) (*p);
    npa /= 1000;
    arylda[0] = (doublereal) npa;

/* GET BLANK COMMON STORAGE INDEX OF SSURF CANONICAL FORM */
    ldaflg = 7;
    apt094_(&ldaflg, arylda, &canind);

/* GET LENGTH OF SURFACE FROM ORIGINAL CANONICAL FORM */
    arylda[1] = canon[(integer) (canind + 1.) - 1];

/* GET STORAGE LOCATION OF SSURF DATA */
    ldaflg = 3;
    apt094_(&ldaflg, arylda, &loccan);
    loccan += -41;

/* GET NUMBER OF PATCHES IN U- AND V-DIRECTION */
    numspl = (integer) (sscan[loccan + 8] - 1.);
    numcrs = (integer) (sscan[loccan + 9] - 1.);

/* FETCH THE U/V VALUES OF THE CLDAT-SECTION, BELONGING TO A PATCH */
    iuvsc = sspad_1.iscan;
    i__1 = nump;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*  GET U,V,P DATA */
	ataper_(result, &i__, &iarg1, &c__9, &iee);
	if (iee == 0) {
	    goto L4;
	}

/*  ERROR : REGION DATA CAN NOT BE FETCHED */
	error_(&c__22806, "REGION  ", (ftnlen)8);
	goto L999;
L4:
	np = (integer) (*p);
	itaus = np / 1000;
	if (itaus == npa) {
	    goto L5;
	}

/* ERROR: REGION DATA BELONGS TO MORE THAN ONE SURFACE */
	error_(&c__22801, "REGION  ", (ftnlen)8);
	goto L999;
L5:
	numpat = np - itaus * 1000;

/* TRANSFORM U1/V1 VALUES TO BASIC U/V VALUES */
	iu = (numpat - 1) % numcrs + 1;
	iv = (numpat - 1) / numcrs + 1;
	u = *u1 + iu - 1;
	v = *v1 + iv - 1;
	sspad_1.scan[sspad_1.iscan] = u;
	sspad_1.scan[sspad_1.iscan + 1] = v;

/* NO CHECK AT FIRST POINT */
	if (i__ == 1) {
	    goto L90;
	}

/* CHECK, CLOSE POINT TO LAST POINT */
	du = u - sspad_1.scan[sspad_1.iscan - 2];
	dv = v - sspad_1.scan[sspad_1.iscan - 1];
	if (du * du + dv * dv < 1e-12) {
	    goto L100;
	}

/* NO CHECK AT 2ND POINT */
	if (i__ <= 2) {
	    goto L90;
	}

/* CHECK, IF LINEAR EXTENSION */
	if ((d__1 = du * (v - sspad_1.scan[sspad_1.iscan - 3]) - dv * (u - 
		sspad_1.scan[sspad_1.iscan - 4]), abs(d__1)) > 1e-5) {
	    goto L90;
	}

/* REPLACE PREVIOUS POINT */
	sspad_1.scan[sspad_1.iscan - 2] = u;
	sspad_1.scan[sspad_1.iscan - 1] = v;
	goto L100;

L90:
	sspad_1.iscan += 2;
	if (sspad_1.iscan > sspad_1.nscnmx) {
	    goto L992;
	}
L100:
	;
    }

/* CHECK, CLOSE POINT TO FIRST POINT */
    du = sspad_1.scan[iuvsc] - sspad_1.scan[sspad_1.iscan - 2];
    dv = sspad_1.scan[iuvsc + 1] - sspad_1.scan[sspad_1.iscan - 1];
    if (du * du + dv + dv >= 1e-12) {
	goto L110;
    }
    sspad_1.iscan += -2;

/* CHECK, IF LINEAR EXTENSION */
L110:
    if ((d__1 = (sspad_1.scan[iuvsc] - sspad_1.scan[sspad_1.iscan - 2]) * (
	    sspad_1.scan[iuvsc + 3] - sspad_1.scan[sspad_1.iscan - 1]) - (
	    sspad_1.scan[iuvsc + 1] - sspad_1.scan[sspad_1.iscan - 1]) * (
	    sspad_1.scan[iuvsc + 2] - sspad_1.scan[sspad_1.iscan - 2]), abs(
	    d__1)) > 1e-5) {
	goto L120;
    }
    sspad_1.scan[iuvsc] = sspad_1.scan[sspad_1.iscan - 2];
    sspad_1.scan[iuvsc + 1] = sspad_1.scan[sspad_1.iscan - 1];
    sspad_1.iscan += -2;

/* RECALCULATE THE NUMBER OF POINTS */
L120:
    nump = (sspad_1.iscan - iuvsc) / 2;
    if (nump >= 3) {
	goto L130;
    }

/* ERROR: LESS THAN 3 POINTS AS REGION BOUNDARY */
    error_(&c__22802, "REGION  ", (ftnlen)8);
    goto L999;
L130:

/* TEST OF RIGHT (CLOCWISE) OR LEFT SENSE OF CONTOUR */

/*  DIRECTION SENSE VECTOR */
    w[0] = sspad_1.scan[iuvsc + 2] - sspad_1.scan[iuvsc];
    w[1] = sspad_1.scan[iuvsc + 3] - sspad_1.scan[iuvsc + 1];

/* NUMBER OF 90 DEGREE TURNS */
    iq = 0;

/* PRESET OF PREVIOUS CENTER DIRECTION */
    vprev[0] = w[0];
    vprev[1] = w[1];

/* START-INDEX */
    ia = iuvsc + 2;
    nump1 = nump + 1;

/* SENSE LOOP */
    i__1 = nump1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	ia1 = ia + 2;
	if (i__ == nump) {
	    ia1 = iuvsc;
	}

/* CURRENT CONTOUR DIRECTION */
	vcurr[0] = sspad_1.scan[ia1] - sspad_1.scan[ia];
	vcurr[1] = sspad_1.scan[ia1 + 1] - sspad_1.scan[ia + 1];

/* IS THE DIRECTION SENSE VECTOR TO BE CHANGED */
	if (w[0] * vcurr[0] + w[1] * vcurr[1] > 0.) {
	    goto L610;
	}

/* CROSS PRUDUCT BETWEEN SENSE VECTOR AND CONTOUR DIRECTION */
	wcv = w[0] * vcurr[1] - w[1] * vcurr[0];

/* LEFT/RIGHT CORNER */
	if (vprev[0] * vcurr[1] - vprev[1] * vcurr[0] > 0.) {
	    goto L605;
	}

/* CORNER TO RIGHT */
	if (wcv >= 0.) {
	    goto L603;
	}
	iq += 2;
	w[0] = -w[0];
	w[1] = -w[1];
	goto L610;

L603:
	++iq;
	ww = w[0];
	w[0] = w[1];
	w[1] = -ww;
	goto L610;

/* CORNER TO LEFT */
L605:
	if (wcv <= 0.) {
	    goto L608;
	}
	iq += -2;
	w[0] = -w[0];
	w[1] = -w[1];
	goto L610;

L608:
	--iq;
	ww = w[0];
	w[0] = -w[1];
	w[1] = ww;
	goto L610;

L610:
	ia += 2;
	if (i__ == nump) {
	    ia = iuvsc;
	}
	vprev[0] = vcurr[0];
	vprev[1] = vcurr[1];
/* L600: */
    }
    if (iq != 0 || abs(iq) <= 4) {
	goto L140;
    }

/* ERROR: REGION BOUNDARY IS INCORRECT */
    error_(&c__22803, "REGION  ", (ftnlen)8);
    goto L999;

/* RESERVE REGION DATA SPACE */
L140:
    ldaflg = 5;
    cclear_1.reglda[0] = 0.;
    cclear_1.reglda[1] = (doublereal) ((nump << 2) + 8);
    apt094_(&ldaflg, cclear_1.reglda, sscan);

/* PUT REGION-VALUES INTO SSCAN (BLANK COMMON) */
    j = 1;
    sscan[j - 1] = (doublereal) np;
    sscan[j] = canind;
    sscan[j + 1] = (doublereal) nump;
    sscan[j + 2] = outin;
    j += 3;

/* FIND THE MIN/MAX-VALUES OF U/V */
    umin = sspad_1.scan[iuvsc];
    umax = sspad_1.scan[iuvsc];
    vmin = sspad_1.scan[iuvsc + 1];
    vmax = sspad_1.scan[iuvsc + 1];

    ia = iuvsc + 2;
    ie = sspad_1.iscan - 2;
    i__1 = ie;
    for (i__ = ia; i__ <= i__1; i__ += 2) {
/* Computing MIN */
	d__1 = sspad_1.scan[i__];
	umin = min(d__1,umin);
/* Computing MAX */
	d__1 = sspad_1.scan[i__];
	umax = max(d__1,umax);
/* Computing MIN */
	d__1 = sspad_1.scan[i__ + 1];
	vmin = min(d__1,vmin);
/* Computing MAX */
	d__1 = sspad_1.scan[i__ + 1];
	vmax = max(d__1,vmax);
/* L800: */
    }

/* PUT THE MIN/MAX-VALUES INTO SSCAN */
    sscan[j] = umin;
    sscan[j + 1] = umax;
    sscan[j + 2] = vmin;
    sscan[j + 3] = vmax;
    j += 4;

/* PUT THE U/V-VALUES AND DISTANCES INTO SSCAN ( IN NORMAL ORDER) */
    if (iq > 0 && outin == 1. || iq < 0 && outin == 0.) {
	goto L810;
    }
    i__1 = ie;
    for (i__ = iuvsc; i__ <= i__1; i__ += 2) {
	i1 = i__ + 2;
	sscan[j] = sspad_1.scan[i__];
	sscan[j + 1] = sspad_1.scan[i__ + 1];
	if (i__ == ie) {
	    i1 = iuvsc;
	}
	sscan[j + 2] = sspad_1.scan[i1] - sspad_1.scan[i__];
	sscan[j + 3] = sspad_1.scan[i1 + 1] - sspad_1.scan[i__ + 1];
	j += 4;
/* L801: */
    }
    numd = j;
    goto L820;

/* PUT THE U/V-VALUES AND DISTANCES INTO SSCAN (REVERSE ORDER) */
L810:
    j += nump - 1 << 2;
    i__1 = ie;
    for (i__ = iuvsc; i__ <= i__1; i__ += 2) {
	i1 = i__ - 2;
	sscan[j] = sspad_1.scan[i__];
	sscan[j + 1] = sspad_1.scan[i__ + 1];
	if (i__ == iuvsc) {
	    i1 = ie;
	}
	sscan[j + 2] = sspad_1.scan[i1] - sspad_1.scan[i__];
	sscan[j + 3] = sspad_1.scan[i1 + 1] - sspad_1.scan[i__ + 1];
	j += -4;
/* L811: */
    }
    numd = j + (nump + 1 << 2);

/* TEST OF SELF-INTERSECTION OF REGION BOUNDARY */
L820:
    if (nump == 3) {
	goto L920;
    }
    numpm2 = nump - 2;
    i__1 = numpm2;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* PREPARE INTERSECTION TEST */
	setver_(&sscan[(i__ << 2) + 4]);

/* LOOP INDICES FOR INNNER LOOP */
	j1 = i__ + 2;
	j2 = nump;
	if (i__ == 1) {
	    j2 = nump - 1;
	}

/* INNER LOOP */
	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    getver_(&sscan[(j << 2) + 4], result, &ires);
	    if (ires == 0) {
		goto L900;
	    }

/* ERROR: REGION BOUNDARY CONTAINS INTERSECTIONS */
	    error_(&c__22804, "REGION  ", (ftnlen)8);
	    goto L999;
L900:
	    ;
	}
    }
L920:

/* WRITE ALL REGION-DATA TO LDA */
    ldaflg = 1;
    cclear_1.reglda[0] = 0.;
    cclear_1.reglda[1] = (doublereal) numd;
    apt094_(&ldaflg, cclear_1.reglda, sscan);

/* COMPUTE THE REGION STORAGE INDEX AND STORE THE REGION */
    ++numre1;
    if (numre1 > 50) {
	numre1 = 1;
    }
    iregio[(numre1 << 2) - 4] = iarg1;
    iregio[(numre1 << 2) - 3] = (integer) outin;
    iregio[(numre1 << 2) - 2] = (integer) cclear_1.reglda[0];
    iregio[(numre1 << 2) - 1] = (integer) cclear_1.reglda[1];

/* INCREASE NUMBER OF STORED REGIONS */
    if (numreg < 50) {
	++numreg;
    }
    glflgs_1.regflg = 1;
L700:

/* TEST-OUTPUT, IF PRINT/SSTEST,ON */
    if (! ssprt_1.sstest) {
	goto L999;
    }
    record_(&nseq);
    ldaflg = 3;
    apt094_(&ldaflg, cclear_1.reglda, &j11);
    j11 += -41;
    j111 = j11 + 1;
    j12 = j11 + 8;
    s_copy(badmsg, " REGION DATA:", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c_n1, &c__0, "ISN ", &nseq, (ftnlen)4);

    bad_(&c__1, &c__1, "REG1", cclear_1.reglda, (ftnlen)4);
    bad_(&c__1, &c__1, "REG2", &cclear_1.reglda[1], (ftnlen)4);
    bad_(&c_n1, &c__0, "J11 ", &j11, (ftnlen)4);
    i__2 = j12;
    for (i1 = j111; i1 <= i__2; i1 += 8) {
	bad_(&c__1, &c__1, "S  1", &sscan[i1 - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "S  2", &sscan[i1], (ftnlen)4);
	bad_(&c__1, &c__1, "S  3", &sscan[i1 + 1], (ftnlen)4);
	bad_(&c_n1, &c__1, "S  4", &sscan[i1 + 2], (ftnlen)4);
	bad_(&c__1, &c__1, "S  5", &sscan[i1 + 3], (ftnlen)4);
	bad_(&c__1, &c__1, "S  6", &sscan[i1 + 4], (ftnlen)4);
	bad_(&c__1, &c__1, "S  7", &sscan[i1 + 5], (ftnlen)4);
/* L807: */
	bad_(&c_n1, &c__1, "S  8", &sscan[i1 + 6], (ftnlen)4);
    }
    j13 = j12 + 1;
    j14 = (integer) (sscan[j11 + 2] * 4 + j13 - 1);
    i__2 = j14;
    for (i__ = j13; i__ <= i__2; i__ += 4) {
	bad_(&c__1, &c__1, "    ", &sscan[i__ - 1], (ftnlen)4);
	bad_(&c__1, &c__1, "    ", &sscan[i__], (ftnlen)4);
	bad_(&c__1, &c__1, "    ", &sscan[i__ + 1], (ftnlen)4);
	bad_(&c__1, &c__1, "    ", &sscan[i__ + 2], (ftnlen)4);
/* L808: */
	bad_(&c_n1, &c__1, "    ", &c__0, (ftnlen)4);
    }
    goto L999;

/* ERROR: TOO MANY REGION POINTS TO PROCESS */
L992:
    error_(&c__22805, "REGION  ", (ftnlen)8);

L999:
    return 0;
} /* region_ */

#undef result
#undef bcanon
#undef sscan
#undef canon
#undef ipat
#undef pat
#undef can
#undef v1
#undef u1
#undef p


