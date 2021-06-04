/* GODLTA.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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
    integer iaerfg;
} aercom_;

#define aercom_1 aercom_

struct {
    doublereal dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

/* Table of constant values */

static integer c__0 = 0;
static integer c__21301 = 21301;
static integer c__3 = 3;

/* *** SOURCE FILE : M0002750.V06   *** */


/* .....FORTRAN SUBROUTINE             GODLTA...              3/1/68   GK */
/* Subroutine */ int godlta_(doublereal *vector, doublereal *decmal)
{
    /* Initialized data */

    static char hgdlta[6] = "GODLTA";
    static char hgoto[4] = "GOTO";

    /* System generated locals */
    static doublereal equiv_2[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j;
    static doublereal vec[3];
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt201_(integer *, char *, ftnlen), apt233_(
	    void);
#define atemp (equiv_2)
    static doublereal tasav[3];
#define itemp ((integer *)equiv_2)
    extern /* Subroutine */ int transm_(doublereal *, doublereal *, integer *,
	     integer *, integer *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*     25.   COMMON FOR AERR INFORMATION */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/*     23. DSNAME BLOCK */



/* ...  CUTTER POSITION IS ADVANCED BY THE VECTOR, OR IS MOVED */
/* ...  (DECMAL) INCHES ALONG THE TOOL AXIS */
    /* Parameter adjustments */
    --vector;

    /* Function Body */
    if (ifxcor_1.iaerr != 0) {
	goto L1000;
    }
    if (ldef_1.jds) {
	apt201_(&c__0, "NOCS    ", (ftnlen)8);
    }
    if (ifxcor_1.igoto <= 0) {
	goto L1;
    } else {
	goto L2;
    }
L2:
    if (ifxcor_1.isrch <= 0) {
	goto L3;
    } else {
	goto L1000;
    }
L3:
    aercom_1.iaerfg = 1;
    aerr_(&c__21301, "GODLTA  ", (ftnlen)8);
    ifxcor_1.iaerr = 0;
    goto L1000;
L1:
    transm_(vec, &vector[1], &c__3, &c__3, &c__0);
    for (j = 1; j <= 3; ++j) {
	fxcor_1.tek[j - 1] = fxcor_1.te[j - 1];
/* ...  EITHER DECMAL OR THE VECTOR COMPONENTS WILL BE ZERO */
/* L10: */
	fxcor_1.te[j - 1] = vec[j - 1] + *decmal * fxcor_1.ta[j - 1];
    }
/* ...  SET RECORD TYPE CODE FOR CLTAPE WRITER */
/* L50: */
    s_copy(charct_1.modfer, hgdlta, (ftnlen)6, (ftnlen)6);
    for (j = 1; j <= 3; ++j) {
	tasav[j - 1] = fxcor_1.ta[j - 1];
/* L55: */
	fxcor_1.ta[j - 1] = 0.f;
    }
    apt233_();
    for (j = 1; j <= 3; ++j) {
	fxcor_1.ta[j - 1] = tasav[j - 1];
/* L60: */
	fxcor_1.te[j - 1] = fxcor_1.tek[j - 1] + fxcor_1.te[j - 1];
    }
    s_copy(charct_1.modfer, hgoto, (ftnlen)6, (ftnlen)4);
    itemp[0] = bcdf_("NONA", (ftnlen)4);
    itemp[1] = bcdf_("ME  ", (ftnlen)4);
    dsname_1.dsname = *atemp;
    apt233_();
L1000:
    return 0;
} /* godlta_ */

#undef itemp
#undef atemp
#undef sinl
#undef cosl


