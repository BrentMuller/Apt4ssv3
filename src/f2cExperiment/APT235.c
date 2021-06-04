/* APT235.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

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
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__18 = 18;
static integer c__32 = 32;
static integer c__23501 = 23501;

/* *** SOURCE FILE : M0002730.V08   *** */


/* .....FORTRAN SUBROUTINE                APT235...            8/1/68  AR */
/* Subroutine */ int apt235_(void)
{
    /* Initialized data */

    static char hgo[8] = "GO      ";
    static logical first = TRUE_;
    static struct {
	integer e_1[32];
	doublereal e_2;
	} equiv_2 = { 0, 0, 1308622848, 0, 1308622848, 6, 1308622848, 1, 0, 0,
		 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0. };


    /* System generated locals */
    integer i__1, i__2;
    static doublereal equiv_3[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, l, m, nr, ir;
#define can ((doublereal *)&_BLNK__1 + 40)
#define hcl ((doublereal *)&equiv_2)
    extern integer bcdf_(char *, ftnlen);
    static logical flag__;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define iferm ((integer *)equiv_3)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define hcldta ((integer *)&equiv_2)
#define fermod (equiv_3)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, integer *, integer *, integer *), autops_(void);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */








/* ...            SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...                SYSTEM I/O FILES */







/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







    if (first) {
	hcldta[0] = bcdf_("CLDA", (ftnlen)4);
	hcldta[1] = bcdf_("TA  ", (ftnlen)4);
	hcldta[8] = bcdf_("    ", (ftnlen)4);
	hcldta[9] = hcldta[8];
	hcldta[12] = hcldta[8];
	hcldta[13] = hcldta[8];
	first = FALSE_;
    }
    flag__ = FALSE_;
    ifxcor_1.numsur = ifxcor_1.icscnt + knumbr_1.k2;
/* ...  PRINT  IDENTIYING FIRST CUT SEQUENCE RECORD ON EXFILE */
    record_(&ifxcor_1.iseqno);
    hcldta[3] = ifxcor_1.iseqno;
    iferm[0] = bcdf_(charct_1.modfer, (ftnlen)4);
    iferm[1] = bcdf_(charct_1.modfer + 4, (ftnlen)2);
    hcl[4] = *fermod;
    hcldta[11] = isv_1.isftyp[ifxcor_1.ids - 1];
    hcl[6] = dsname_1.dsname;
    hcldta[15] = dsname_1.namsub;
    hcldta[17] = isv_1.isfidn[ifxcor_1.ids - 1];
    if (isv_1.isfidn[ifxcor_1.ids - 1] == knumbr_1.k4 && s_cmp(
	    charct_1.modfer, hgo, (ftnlen)6, (ftnlen)8) != 0) {
	goto L10;
    }
    hcldta[5] = knumbr_1.k6;
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, hcldta, &c__18, &ir);
    goto L15;
L10:
    hcldta[5] = knumbr_1.k13;
    j = isv_1.icanon[ifxcor_1.ids - 1];
    for (i__ = 10; i__ <= 16; ++i__) {
	hcl[i__ - 1] = canon[j - 1];
/* L11: */
	++j;
    }
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, hcldta, &c__32, &ir);
L15:
    if (ifxcor_1.ipsdef <= 0) {
	goto L9;
    } else {
	goto L8;
    }
L8:
    fxcor_1.temp[0] = fxcor_1.te[2];
    fxcor_1.te[2] = znumbr_1.z0;
    autops_();
    fxcor_1.te[2] = fxcor_1.temp[0];
L9:
    j = ifxcor_1.ips;
    l = ifxcor_1.lsv;
    i__1 = ifxcor_1.numsur;
    for (i__ = 1; i__ <= i__1; ++i__) {
	m = isv_1.icanon[j - 1];
	if (ckdef_(&canon[m - 1])) {
	    flag__ = TRUE_;
	}
	if ((i__2 = j - ifxcor_1.ics) < 0) {
	    goto L2;
	} else if (i__2 == 0) {
	    goto L3;
	} else {
	    goto L4;
	}
L2:
	isv_1.itlon[j - 1] = isv_1.isftyp[j - 1] - knumbr_1.k3;
	goto L5;
L3:
	l = ifxcor_1.lsv1;
L4:
	if ((i__2 = isv_1.isftyp[j - 1] - knumbr_1.k4) < 0) {
	    goto L2;
	} else if (i__2 == 0) {
	    goto L6;
	} else {
	    goto L7;
	}
L6:
	isv_1.itlon[j - 1] = isv_1.itlon[ifxcor_1.ids - 1];
	if (isv_1.itlon[j - 1] != 0) {
	    isv_1.itlon[j - 1] = 2;
	}
	goto L5;
L7:
	isv_1.itlon[j - 1] = isv_1.itlon[ifxcor_1.ips - 1];
	if (isv_1.itlon[j - 1] != 0) {
	    isv_1.itlon[j - 1] = 3;
	}
	isv_1.isftyp[j - 1] = knumbr_1.k4;
L5:
	isv_1.iafl[j - 1] = -knumbr_1.k1;
/* L1: */
	j += l;
    }
    if (flag__) {
	aerr_(&c__23501, "APT235  ", (ftnlen)8);
    }
    return 0;
} /* apt235_ */

#undef bcanon
#undef fermod
#undef hcldta
#undef sscan
#undef iferm
#undef canon
#undef sinl
#undef cosl
#undef hcl
#undef can


