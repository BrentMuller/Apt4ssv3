/* GETAPT.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n7 = -7;
static integer c__1 = 1;

/* *** SOURCE FILE : M0001070.W02   *** */

/* Subroutine */ int getapt_(doublereal *tul, doublereal *ptoli, doublereal *
	ptolo, doublereal *dtol, doublereal *amaxdp, doublereal *zelmax, 
	integer *inum, integer *irr)
{
    /* Initialized data */

    static doublereal smal = 1e-14;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define elmax ((doublereal *)&addcom_1)

/* --PURPOSE IS TO FETCH ADDITIONAL APT VARIABLES REQUIRED FOR */
/* --SMIL TOOL PATH GENERATION. */


/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */







/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




    /* Parameter adjustments */
    --tul;

    /* Function Body */

/* --FETCH TOOL AND VERIFY THAT IT IS ACCEPTABLE */
    tul[1] = fxcor_1.cutdat[1];
    tul[2] = fxcor_1.cutdat[0];
    tul[3] = fxcor_1.cutdat[2];
/* Computing 2nd power */
    d__1 = tul[1];
/* Computing 2nd power */
    d__2 = tul[3];
    if (d__1 * d__1 + d__2 * d__2 < smal) {
	tul[3] = tul[2];
    }
    tul[4] = fxcor_1.cutdat[3] - fxcor_1.cutdat[1];
    tul[5] = fxcor_1.cutdat[4];
    tul[6] = fxcor_1.cutdat[5];
    tul[7] = fxcor_1.cutdat[6];
    if (ibugg_1.ibug == 11) {
	bad_(&c_n7, &c__1, "CUTD", fxcor_1.cutdat, (ftnlen)4);
    }

    *ptolo = (d__1 = sv_1.tau1[ifxcor_1.ips - 1], abs(d__1));
    *ptoli = (d__1 = sv_1.tau2[ifxcor_1.ips - 1], abs(d__1));
    *dtol = (d__1 = sv_1.tau1[ifxcor_1.ids - 1], abs(d__1));
    if (*dtol < smal) {
	*dtol = (d__1 = sv_1.tau2[ifxcor_1.ids - 1], abs(d__1));
    }
    *amaxdp = fxcor_1.dpmax;
    *zelmax = *elmax;
    *inum = ifxcor_1.nmpnts;
    *irr = 0;
    goto L999;
/* L998: */
    if (ibugg_1.ibug == 11) {
	bad_(&c_n7, &c__1, "CUTD", fxcor_1.cutdat, (ftnlen)4);
    }

L999:
    return 0;
} /* getapt_ */

#undef elmax
#undef sinl
#undef cosl


