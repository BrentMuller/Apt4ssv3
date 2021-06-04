/* APT233.f -- translated by f2c (version 20100827).
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
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
} hblock_;

#define hblock_1 hblock_

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
    doublereal dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__10 = 10;
static integer c__18 = 18;

/* *** SOURCE FILE : M0000853.V08   *** */

/* .....FORTRAN SUBROUTINE  ....APT233         8/68                 HG,AR */
/* .....FORTRAN SUBROUTINE             APT233...              3/1/68   GK */
/* Subroutine */ int apt233_(void)
{
    /* Initialized data */

    static logical first = TRUE_;
    static char hgdlta[6] = "GODLTA";
    static doublereal zlit1 = .997;
    static struct {
	integer e_1[18];
	doublereal e_2;
	} equiv_3 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 1, 0, 0,
		 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0. };


    /* System generated locals */
    doublereal d__1;
    static doublereal equiv_2[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j, nr, ir;
    extern integer bcdf_(char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int atape_(void);
#define iferm ((integer *)equiv_2)
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
#define dcldat ((doublereal *)&equiv_3)
#define kcldat ((integer *)&equiv_3)
#define fermod (equiv_2)
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, integer *, integer *, integer *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







/* ...            SYSTEM I/O FILE NAMES */


/* ...                SYSTEM I/O FILES */




    if (first) {
	kcldat[0] = bcdf_("CLDA", (ftnlen)4);
	kcldat[1] = bcdf_("TA  ", (ftnlen)4);
	kcldat[8] = bcdf_("    ", (ftnlen)4);
	kcldat[9] = kcldat[8];
	kcldat[12] = kcldat[8];
	kcldat[13] = kcldat[8];
	first = FALSE_;
    }
/* ...  STORES THE CUTTER POSITION (TE) IN TCDAT */
/* ...  CALLED BY SUBROUTINES FROM,GODLTA,AND GOTO */
    record_(&ifxcor_1.iseqno);
    iferm[0] = bcdf_(charct_1.modfer, (ftnlen)4);
    iferm[1] = bcdf_(charct_1.modfer + 4, (ftnlen)2);
    if (s_cmp(charct_1.modfer, hgdlta, (ftnlen)6, (ftnlen)6) != 0) {
	goto L10;
    }
    nr = 0;
    kcldat[3] = ifxcor_1.iseqno;
    dcldat[4] = *fermod;
    ewrite_(&symfil_1.exfile, &nr, kcldat, &c__10, &ir);
    goto L70;
/* ...  TI IS THE NORMALIZED CUT VECTOR */
L10:
    for (j = 1; j <= 3; ++j) {
/* L20: */
	fxcor_1.temp[j - 1] = fxcor_1.te[j - 1] - fxcor_1.tek[j - 1];
    }
    vnorm_(fxcor_1.temp, fxcor_1.ti);
    if (ifxcor_1.ier <= 0) {
	goto L25;
    } else {
	goto L50;
    }
L25:
    if ((d__1 = fxcor_1.ti[0] * fxcor_1.ta[0] + fxcor_1.ti[1] * fxcor_1.ta[1] 
	    + fxcor_1.ti[2] * fxcor_1.ta[2], abs(d__1)) - zlit1 <= 0.) {
	goto L30;
    } else {
	goto L50;
    }
/* ...  IF TI IS NOT IN LINE WITH TA,SAVE IN PMOVE */
L30:
    for (j = 1; j <= 3; ++j) {
/* L40: */
	fxcor_1.pmove[j - 1] = fxcor_1.ti[j - 1];
    }
L50:
    nr = 0;
    kcldat[3] = ifxcor_1.iseqno;
    kcldat[5] = 6;
    dcldat[4] = *fermod;
    dcldat[6] = dsname_1.dsname;
    kcldat[15] = dsname_1.namsub;
    ewrite_(&symfil_1.exfile, &nr, kcldat, &c__18, &ir);
    kcldat[5] = 2;
L70:
    ifxcor_1.icl = knumbr_1.k3;
    atape_();
    return 0;
} /* apt233_ */

#undef fermod
#undef kcldat
#undef dcldat
#undef iferm
#undef sinl
#undef cosl


