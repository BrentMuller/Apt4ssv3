/* GOTOPN.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__2 = 2;
static integer c__45 = 45;
static integer c__46 = 46;

/* *** SOURCE FILE : M0002775.V06   *** */


/* ...  FORTRAN SUBROUTINE               GOTOPN    3/69      SR */

/* PURPOSE      TO POSITION THE TOOL AS INDICATED BY A */
/*              PATERN MOTION STATEMENT */

/* LINKAGE      CALL GOTOPN(PAT,IARG1,IARG2,IARG3,IARG4,OMTLST,AVDLST) */

/* ARGUMENTS    PAT     ARRAY CONTAINING THE I.C.F. OF THE PATERN */
/*              IARG1   INTEGER 1 IF INVERS APPLIES, OTHERWISE 0 */
/*              IARG2   INTEGER 1 IF ZIGZAG APPLIES, OTHERWISE 0 */
/*              IARG3   INTEGER INDICATING TYPE (OMIT, RETAIN) AND */
/*                      NUMBER OF 2-ELEMENT ENTRIES IN OMTLST */
/*                      IARG3=0       NEITHER OMIT NOR RETAIN MODIFIER */
/*                                    USED */
/*                      0)IARG3)1000  OMTLST CONTAINS POINTS TO BE */
/*                                    OMITTED AND */
/*                                    IARG3=NUMBER OF ENTRIES */
/*                      1000)IARG3    OMTLST CONTAINS POINTS TO BE */
/*                                    RETAINED AND */
/*                                    1000-IARG3=NUMBER OF ENTRIES */
/*              IARG4   INTEGER INDICATING NUMBER OF 3-ELEMENT */
/*                      ENTRIES IN AVDLST */
/*              OMTLST  ARRAY CONTAINING FIRST AND LAST POINT OF */
/*                      EACH OMIT OR RETAIN SEQUENCE */
/*              AVDLST  ARRAY CONTAINING THE OFFSET AND THE FIRST */
/*                      AND LAST POINT OF EACH AVOID SEQUENCE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          APT094 */
/*              SUBROUTINE          APT202 */
/*              SUBROUTINE          APT233 */
/*              SUBROUTINE          APT299 */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          NPAT */

/* Subroutine */ int gotopn_(doublereal *pat, integer *iarg1, integer *iarg2, 
	integer *iarg3, integer *iarg4, doublereal *omtlst, doublereal *
	avdlst)
{
    /* Initialized data */

    static char hnomor[6] = "NOMORE";
    static char hgoto[4] = "GOTO";
    static char hcycle[5] = "CYCLE";
    static char hon[2] = "ON";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, n;
    static doublereal pt;
    static integer no;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal res[3];
    static integer ncol;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer jsav;
    extern /* Subroutine */ int npat_(doublereal *, integer *), apt202_(
	    doublereal *, integer *), apt233_(void), apt094_(integer *, 
	    doublereal *, doublereal *);
    static integer npat1, isva2, isva3;
    extern /* Subroutine */ int apt299_(integer *, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical ckdef_(doublereal *);
    static doublereal avddn;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal avdup;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer iparg3;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal avdend;
    static integer ncolmd;
    static doublereal tmpsav;
    static integer iavtyp;




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    avdlst -= 4;
    omtlst -= 3;
    --pat;

    /* Function Body */

/*          MOVE THE EXTERNAL CANONICAL FORM TO BCANON */

    if (ckdef_(&pat[1])) {
	goto L999;
    }
    apt094_(&c__2, &pat[1], bcanon);
    if (ckdef_(&pat[1])) {
	goto L999;
    }

/*          DETERMINE NUMBER OF POINTS IN PATERN */

    n = (integer) (bcanon[3] + znumbr_1.z1em5);

/*          IF ZIGZAG IS TO APPLY, PATERN MUST BE GRID */

    isva2 = *iarg2;
    if (isva2 == knumbr_1.k0) {
	goto L10;
    }
    if (bcanon[1] == znumbr_1.z3) {
	goto L5;
    }
    error_(&c__45, "GOTOPN  ", (ftnlen)8);
    isva2 = knumbr_1.k0;
    goto L10;

/*          DETERMINE NUMBER OF POINTS IN FIRST SIDE OF GRID PATERN */

L5:
    npat1 = (integer) (bcanon[6] + znumbr_1.z1em5);

/*          IF OMTLST HAS ENTRIES, PUT THEM IN ORDER */

L10:
    isva3 = *iarg3;
    if (isva3 < 1000) {
	goto L11;
    }
    isva3 = -(isva3 - 1000);
L11:
    if (isva3 < 0) {
	goto L12;
    } else if (isva3 == 0) {
	goto L20;
    } else {
	goto L14;
    }
L12:
    iparg3 = -isva3;
    goto L16;
L14:
    iparg3 = isva3;
L16:
    i__1 = iparg3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (omtlst[(i__ << 1) + 1] <= omtlst[(i__ << 1) + 2]) {
	    goto L18;
	}
	tmpsav = omtlst[(i__ << 1) + 1];
	omtlst[(i__ << 1) + 1] = omtlst[(i__ << 1) + 2];
	omtlst[(i__ << 1) + 2] = tmpsav;
L18:
	;
    }

/*          CHECK FOR AVOID */

L20:
    if (*iarg4 == knumbr_1.k0) {
	goto L70;
    }

/*          PUT AVDLST ENTRIES IN ORDER */

    i__1 = *iarg4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (avdlst[i__ * 3 + 2] < avdlst[i__ * 3 + 3]) {
	    goto L40;
	}
	if (avdlst[i__ * 3 + 3] == znumbr_1.z0) {
	    goto L22;
	}

/*          REVERSE ORDER */

	tmpsav = avdlst[i__ * 3 + 2];
	avdlst[i__ * 3 + 2] = avdlst[i__ * 3 + 3];
	avdlst[i__ * 3 + 3] = tmpsav;
	goto L40;

/*          INSERT AS END POINT THE NEXT NON-OMITTED POINT */

L22:
	avdlst[i__ * 3 + 3] = avdlst[i__ * 3 + 2] + znumbr_1.z1;
	pt = (doublereal) n;
	if (isva3 < 0) {
	    goto L24;
	} else if (isva3 == 0) {
	    goto L60;
	} else {
	    goto L32;
	}
L24:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 3] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 3] <= omtlst[(j << 1) + 2]) {
		goto L46;
	    }
/* L26: */
	}
	if (avdlst[i__ * 3 + 3] >= pt) {
	    goto L1000;
	}
	avdlst[i__ * 3 + 3] += znumbr_1.z1;
	goto L24;
L32:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 3] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 3] <= omtlst[(j << 1) + 2]) {
		goto L38;
	    }
/* L36: */
	}
	goto L54;
L38:
	if (avdlst[i__ * 3 + 3] >= pt) {
	    goto L1000;
	}
	avdlst[i__ * 3 + 3] += znumbr_1.z1;
	goto L32;

/*          CHECK FOR OMITTED FIRST OR END POINT IN AVOID STRING */

L40:
	if (isva3 < 0) {
	    goto L42;
	} else if (isva3 == 0) {
	    goto L60;
	} else {
	    goto L50;
	}
L42:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 3] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 3] <= omtlst[(j << 1) + 2]) {
		goto L46;
	    }
/* L44: */
	}
	goto L1000;
L46:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 2] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 2] <= omtlst[(j << 1) + 2]) {
		goto L60;
	    }
/* L48: */
	}
	goto L1000;
L50:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 3] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 3] <= omtlst[(j << 1) + 2]) {
		goto L1000;
	    }
/* L52: */
	}
L54:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (avdlst[i__ * 3 + 2] >= omtlst[(j << 1) + 1] && avdlst[i__ * 3 
		    + 2] <= omtlst[(j << 1) + 2]) {
		goto L1000;
	    }
/* L58: */
	}
L60:
	;
    }

L70:
    ifxcor_1.iaerr = 0;
    apt202_(&pat[1], &c__2);
    s_copy(charct_1.modfer, hgoto, (ftnlen)6, (ftnlen)4);

/*          INITIALIZE FOR AVOID */

    iavtyp = knumbr_1.k1;
    avdend = znumbr_1.z0;
    jsav = knumbr_1.k0;


/* L100: */
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	no = i__;

/*          CHECK FOR INVERSE */

	if (*iarg1 == knumbr_1.k0) {
	    goto L105;
	}
	no = n - i__ + knumbr_1.k1;

/*          CHECK FOR ZIGZAG */

L105:
	if (isva2 == knumbr_1.k0) {
	    goto L110;
	}
	ncol = (no - knumbr_1.k1) / npat1;
	ncolmd = ncol % knumbr_1.k2;
	if (ncolmd == knumbr_1.k1 && *iarg1 == knumbr_1.k0 || ncolmd == 
		knumbr_1.k0 && *iarg1 == knumbr_1.k1) {
	    no = npat1 * (knumbr_1.k2 * ncol + knumbr_1.k1) - no + 
		    knumbr_1.k1;
	}
L110:
	pt = (doublereal) no;

/*          CHECK FOR OMIT OR RETAIN */

	if (isva3 < 0) {
	    goto L140;
	} else if (isva3 == 0) {
	    goto L160;
	} else {
	    goto L120;
	}

/*          OMIT */

L120:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (pt >= omtlst[(j << 1) + 1] && pt <= omtlst[(j << 1) + 2]) {
		goto L900;
	    }
/* L124: */
	}
	goto L160;

/*          RETAIN */

L140:
	i__2 = iparg3;
	for (j = 1; j <= i__2; ++j) {
	    if (pt >= omtlst[(j << 1) + 1] && pt <= omtlst[(j << 1) + 2]) {
		goto L160;
	    }
/* L144: */
	}
	goto L900;

/*          CHECK FOR AVOID */

L160:
	if (*iarg4 == knumbr_1.k0) {
	    goto L200;
	}

/*          AVOID */

	if (avdend != znumbr_1.z0) {
	    goto L170;
	}

/*          LOOK FOR FIRST POINT */

	i__2 = *iarg4;
	for (j = 1; j <= i__2; ++j) {
	    if (pt != avdlst[j * 3 + 2]) {
		goto L163;
	    }
	    avdend = avdlst[j * 3 + 3];
L162:
	    jsav = j;
	    avdup = avdlst[j * 3 + 1];
	    avddn = avdlst[j * 3 + 1];
	    iavtyp = knumbr_1.k2;
	    goto L200;
L163:
	    if (pt != avdlst[j * 3 + 3]) {
		goto L164;
	    }
	    avdend = avdlst[j * 3 + 2];
	    goto L162;
L164:
	    ;
	}
	goto L200;

/*          LOOK FOR END POINT */

L170:
	if (pt == avdend) {
	    goto L180;
	}
	iavtyp = knumbr_1.k3;
	goto L200;

/*          IS THIS END POINT A FIRST POINT OF NEXT STRING */

L180:
	i__2 = *iarg4;
	for (j = 1; j <= i__2; ++j) {
	    if (pt != avdlst[j * 3 + 2]) {
		goto L183;
	    }
	    if (j == jsav) {
		goto L184;
	    }
	    avdend = avdlst[j * 3 + 3];
L182:
	    avdup = avdlst[j * 3 + 1];
	    iavtyp = knumbr_1.k3;
	    goto L200;
L183:
	    if (pt != avdlst[j * 3 + 3] || j == jsav) {
		goto L184;
	    }
	    avdend = avdlst[j * 3 + 2];
	    goto L182;
L184:
	    ;
	}
	jsav = knumbr_1.k0;
	avdend = znumbr_1.z0;
	iavtyp = knumbr_1.k4;

/*          CALL NPAT TO DETERMINE COORDINATES OF POINT */

L200:
	npat_(res, &no);

/*          BRANCH ON IAVTYP */
/*             1-AVOID DOES NOT APPLY     2-FIRST POINT IN AVOID STRING */
/*             3-INTERMEDIATE POINT       4-END POINT */

	switch (iavtyp) {
	    case 1:  goto L240;
	    case 2:  goto L240;
	    case 3:  goto L220;
	    case 4:  goto L210;
	}
L210:
	iavtyp = knumbr_1.k1;
L220:
	for (j = 1; j <= 3; ++j) {
	    fxcor_1.tek[j - 1] = fxcor_1.te[j - 1];
/* L224: */
	    fxcor_1.te[j - 1] = res[j - 1];
	}
	fxcor_1.te[2] += avddn;
	apt233_();
	apt299_(&knumbr_1.k1, hcycle, &knumbr_1.k2, hon, (ftnlen)5, (ftnlen)2)
		;
	avddn = avdup;
L240:
	for (j = 1; j <= 3; ++j) {
	    fxcor_1.tek[j - 1] = fxcor_1.te[j - 1];
/* L244: */
	    fxcor_1.te[j - 1] = res[j - 1];
	}
	apt233_();
	if (iavtyp == knumbr_1.k1) {
	    goto L900;
	}
	apt299_(&knumbr_1.k1, hcycle, &knumbr_1.k2, hnomor, (ftnlen)5, (
		ftnlen)6);
	for (j = 1; j <= 3; ++j) {
	    fxcor_1.tek[j - 1] = fxcor_1.te[j - 1];
/* L250: */
	    fxcor_1.te[j - 1] = res[j - 1];
	}
	fxcor_1.te[2] += avdup;
	apt233_();
L900:
	;
    }

    ifxcor_1.igoto = 0;

L999:
    return 0;

/*          OMIT HAS BEEN APPLIED (OR RETAIN HAS NOT BEEN APPLIED) */
/*             TO A FIRST OR AN END POINT OF AN AVOID STRING */

L1000:
    error_(&c__46, "GOTOPN  ", (ftnlen)8);
    goto L999;

} /* gotopn_ */

#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


