/* INTOUT.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

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
    integer ikeep[255];
} intcom_;

#define intcom_1 intcom_

struct {
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__7 = 7;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__12 = 12;
static integer c__20 = 20;
static integer c__16 = 16;
static integer c__6 = 6;
static integer c__36 = 36;
static integer c__37 = 37;
static integer c__53 = 53;
static integer c__54 = 54;
static integer c__70 = 70;
static integer c__79 = 79;

/* *** SOURCE FILE : M0012405.V03   *** */

/* Subroutine */ int intout_(integer *iout, doublereal *ptt, integer *np, 
	integer *iord, integer *j11, integer *j12, doublereal *sname, 
	doublereal *sindex)
{
    /* Initialized data */

    static logical first = TRUE_;
    static struct {
	doublereal e_1[4];
	} equiv_10 = { 2.003e7, 0., 0., 0. };

    static struct {
	integer e_1[18];
	doublereal e_2;
	} equiv_4 = { 0, 0, 1308622848, 0, 1308622848, 6, 1308622848, 1, 0, 0,
		 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0. };

    static struct {
	doublereal e_1[4];
	} equiv_9 = { 1.903e7, 0., 0., 0. };


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, n;
    static doublereal dm[3];
    static char of[80];
    static integer ip;
#define pt ((doublereal *)&equiv_9 + 1)
#define vn ((doublereal *)&equiv_10 + 1)
    static integer nr, ir;
#define pt1 ((doublereal *)&equiv_9)
#define vt1 ((doublereal *)&equiv_10)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ipa;
#define spv ((doublereal *)&intcom_1)
    static integer ipd;
    static doublereal vll;
    extern integer bcdf_(char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define leit ((doublereal *)&equiv_4)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define ipnr ((integer *)&intcom_1 + 253)
    extern /* Subroutine */ int atape_(void);
#define canon ((doublereal *)&_BLNK__1)
#define ileit ((integer *)&equiv_4)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), fconv_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static integer itype;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static integer index;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int record_(integer *);
    static integer ipatch;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), ewrite_(integer *, integer *, 
	    doublereal *, integer *, integer *), cnsurf_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *), 
	    cprint_(char *, ftnlen), transm_(doublereal *, doublereal *, 
	    integer *, integer *, integer *), holfrm_(doublereal *, char *, 
	    integer *, integer *, integer *, ftnlen), cpunch_(char *, integer 
	    *, ftnlen);


/*   OUTPUT OF INTERSECTION ROUTINES */



/*   OUTPUT FIELD FOR CANON */


/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */






/*   COMMON FOR 2 SURFACE INTERSECTION */

/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */





/*   EVALUATION VECTOR FOR PS AND DS */
/*   PATCH NUMBER FOR PS AND DS (SURFACE RECNO*1000 + PATCH NO) */

/* SS - ARELEM - COMMON */

/*  EXFILE INTRODUCTION */

/*     BLANK-COMMON */

/* SYSTEM - I/O NAMES */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*   POINT STORAGE FOR TRANSFORMATION PURPOSE */

/* ...                SYSTEM I/O FILES */



/*   VECTOR STORAGE FOR TRANSFORMATION PURPOSE */

/*  MOTION DIRECTION */

    /* Parameter adjustments */
    ptt -= 10;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/*     INITIALISE CHARACTER ITEMS FOR OUTPUT TO EXFILE */

    if (first) {
	ileit[0] = bcdf_("CLDA", (ftnlen)4);
	ileit[1] = bcdf_("TA  ", (ftnlen)4);
	ileit[8] = bcdf_("INTS", (ftnlen)4);
	ileit[9] = bcdf_("EC  ", (ftnlen)4);
	ileit[12] = bcdf_("    ", (ftnlen)4);
	ileit[13] = ileit[12];
	first = FALSE_;
    }
/*  TYPE OF OPERATION */
    itype = *iout + 1;

/*  START AND INCREMENTS FOR OUTPUT */
    ip = 1;
    if (*iord < 0) {
	ip = *np;
    }
    ipd = 1;
    if (*iord < 0) {
	ipd = -1;
    }

/*  PREPARATION FOR EXFILE OUTPUT */
    if (itype != 1) {
	goto L10;
    }
    nr = 0;
    j = 18;
    record_(&ifxcor_1.iseqno);
    ileit[3] = ifxcor_1.iseqno;
/*  NAME */
    leit[6] = *sname;
    ileit[15] = (integer) (*sindex);
    ileit[17] = 29;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);

/*  OUTPUT LOOP */
L10:
    i__1 = *np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	switch (itype) {
	    case 1:  goto L20;
	    case 2:  goto L30;
	    case 3:  goto L40;
	}
	return 0;

/*   EXFILE OUTPUT **************************************************** */

/*  STORING INTERSECTION POINT */
L20:
	for (j = 1; j <= 3; ++j) {
	    fxcor_1.tek[j - 1] = fxcor_1.te[j - 1];
/* L110: */
	    pt[j - 1] = ptt[j + ip * 9];
	}
	transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);

/* LOAD PS PATCH IF NECESSARY */
	ipatch = (integer) ptt[ip * 9 + 9];
	ipa = ipatch - ipatch / 1000 * 1000;
	if (ipnr[0] != ipatch) {
	    lodpch_(&sscan[*j12], ssarlm_1.bb, ssarlm_1.iiflag, 
		    ssarlm_1.iitop, &ipa, &c__0);
	}
	ipnr[0] = ipatch;

/* STORE (U,V,P)-VALUES OF PS FOR ATAPE */
	ssarlm_1.uu[0] = ptt[ip * 9 + 7];
	ssarlm_1.vv[0] = ptt[ip * 9 + 8];
	ssarlm_1.ipnum[0] = ipa;

/*  EVALUATE POINT */
	cnsurf_(ssarlm_1.uu, ssarlm_1.vv, ssarlm_1.bb, spv, ssarlm_1.iiflag, &
		c__2);

/* STORE SURFACE POINT WITH NORMAL FOR ATAPE */
	for (j = 1; j <= 3; ++j) {
	    pt[j - 1] = ptt[j + ip * 9];
	    vn[j - 1] = spv[j + 27];
/* L120: */
	}
	transm_(&sv_1.sp[ifxcor_1.ips * 3 - 3], pt, &c__2, &c__3, &c__0);
	transm_(&sv_1.sn[ifxcor_1.ips * 3 - 3], vn, &c__3, &c__3, &c__0);

/* LOAD DS PATCH IF NECESSARY */
	if (ssarlm_1.iiflag[4] <= 0) {
	    goto L124;
	}
	ipatch = (integer) ptt[ip * 9 + 6];
	ipa = ipatch - ipatch / 1000 * 1000;
	if (ipnr[1] != ipatch) {
	    lodpch_(&sscan[*j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4], &
		    ssarlm_1.iitop[24], &ipa, &c__0);
	}
	ipnr[1] = ipatch;

/* STORE (U,V,P)-VALUES OF PS FOR ATAPE */
	ssarlm_1.uu[1] = ptt[ip * 9 + 4];
	ssarlm_1.vv[1] = ptt[ip * 9 + 5];
	ssarlm_1.ipnum[1] = ipa;

/*  EVALUATE POINT */
	cnsurf_(&ssarlm_1.uu[1], &ssarlm_1.vv[1], &ssarlm_1.bb[64], &spv[32], 
		&ssarlm_1.iiflag[4], &c__2);
	goto L126;

/*  PLANE DS */
L124:
	ssarlm_1.uu[1] = 0.;
	ssarlm_1.vv[1] = 0.;
	ssarlm_1.ipnum[1] = 0;

/* STORE SURFACE POINT WITH NORMAL FOR ATAPE */
L126:
	for (j = 1; j <= 3; ++j) {
	    pt[j - 1] = ptt[j + ip * 9];
	    if (ssarlm_1.iiflag[4] <= 0) {
		spv[j + 59] = ssarlm_1.bb[j + 63];
	    }
	    vn[j - 1] = spv[j + 59];
/* L130: */
	}
	transm_(&sv_1.sp[ifxcor_1.ids * 3 - 3], pt, &c__2, &c__3, &c__0);
	transm_(&sv_1.sn[ifxcor_1.ids * 3 - 3], vn, &c__3, &c__3, &c__0);

/*  NORMALIZE MOTION DIRECTION */
	cross_(&spv[60], &spv[28], dm);
/* Computing 2nd power */
	d__1 = dm[0];
/* Computing 2nd power */
	d__2 = dm[1];
/* Computing 2nd power */
	d__3 = dm[2];
	vll = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	for (j = 1; j <= 3; ++j) {
	    dm[j - 1] /= vll;
/* L140: */
	    vn[j - 1] = dm[j - 1];
	}
	transm_(fxcor_1.ti, vn, &c__3, &c__3, &c__0);

/*  STORE POSITION ON EXFILE */
	ifxcor_1.icl = 2;
	if (i__ == *np) {
	    ifxcor_1.icl = 3;
	}
	atape_();
	goto L49;

/*   SSCAN OUTPUT ******************************************************* */
L30:
/*   PS PATCH INDEX FOR POINT NAME */
	ipa = (integer) ptt[ip * 9 + 9];
	s_copy(of, " ", (ftnlen)80, (ftnlen)1);
	i__2 = ipa + 10000;
	iconv_(&i__2, of, &c__1, &c__5, (ftnlen)80);
	cform_("PT", of, &c__1, &c__2, (ftnlen)2, (ftnlen)80);
	cform_("(", of, &c__7, &c__1, (ftnlen)1, (ftnlen)80);
/*  POINT INDEX */
	iconv_(&i__, of, &c__8, &c__4, (ftnlen)80);
	cform_(")=POINT/", of, &c__12, &c__8, (ftnlen)8, (ftnlen)80);
/*  X,Y,Z */
	fconv_(&ptt[ip * 9 + 1], of, &c__20, &c__16, &c__6, (ftnlen)80);
	cform_(",", of, &c__36, &c__1, (ftnlen)1, (ftnlen)80);
	fconv_(&ptt[ip * 9 + 2], of, &c__37, &c__16, &c__6, (ftnlen)80);
	cform_(",", of, &c__53, &c__1, (ftnlen)1, (ftnlen)80);
	fconv_(&ptt[ip * 9 + 3], of, &c__54, &c__16, &c__6, (ftnlen)80);
/*  FILLER */
	cform_("  ", of, &c__70, &c__2, (ftnlen)2, (ftnlen)80);
	goto L48;

/*   HEX OUTPUT ********************************************************* */
L40:
	s_copy(of, " HEX OUTPUT NOT SUPPORTED IN THIS VERSION", (ftnlen)80, (
		ftnlen)41);
	cprint_(of, (ftnlen)80);
	goto L30;
/*   PS PATCH INDEX FOR POINT NAME */
/*      IPA=PTT(9,IP) */
/*      CALL ICONV (IPA+10000,OF,1,5) */
/*      CALL CFORM ('PT',OF,0,2) */
/*      CALL CFORM ('  ',OF,6,2) */
/*  POINT INDEX */
/*      PP=I */
/*      CALL CFORM (PP,OF,8,8) */
/*  POINT TYPE AND LENGTH OF SSCANICAL FORM */
/*      CALL CFORM (1,OF,16,4) */
/*      CALL CFORM (6,OF,20,4) */
/*  FILLER */
/*      CALL CFORM (0.D0,OF,24,8) */
/*  X,Y,Z */
/*      CALL CFORM (PTT(1,IP),OF,32,8) */
/*      CALL CFORM (PTT(2,IP),OF,40,8) */
/*      CALL CFORM (PTT(3,IP),OF,48,8) */
/*  FILLER */
/*      CALL CFORM (0.D0,OF,56,8) */
/*      CALL CFORM (0.D0,OF,64,8) */
/*  COMMON OUTPUT OF SSCAN AND HEX */
L48:
	holfrm_(sname, of + 72, &c__1, &c__6, &n, (ftnlen)8);
	cform_("  ", of, &c__79, &c__2, (ftnlen)2, (ftnlen)80);
	index = (integer) (*sindex);
	if (index != 0) {
	    iconv_(&index, of, &c__79, &c__2, (ftnlen)80);
	}
	cpunch_(of, &c__1, (ftnlen)80);

/*  POINT INDEX INCREMENTING */
L49:
	ip += ipd;
/* L50: */
    }

/*  END PUNCH OUTPUT FOR HEX FORMAT */
/*      IF(ITYPE.NE.3)GOTO 99 */
/*      CALL CFORM ('(ENDPCH)',OF,1,8) */
/*      DO 60 I=8,65,8 */
/*      CALL CFORM ('        ',OF,I,8) */
/*   60 CONTINUE */
/*      CALL CFORM (-1,OF,73,4) */
/*      CALL CFORM (-1,OF,77,4) */
/*      CALL CPUNCH(OF,1) */

/* L99: */
    return 0;
} /* intout_ */

#undef bcanon
#undef sscan
#undef ileit
#undef canon
#undef ipnr
#undef sinl
#undef leit
#undef cosl
#undef spv
#undef can
#undef vt1
#undef pt1
#undef vn
#undef pt


