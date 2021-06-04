/* APT227.f -- translated by f2c (version 20100827).
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
    doublereal apt227;
} apt227_;

#define apt227_1 apt227_

struct def_1_ {
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
};

#define def_1 (*(struct def_1_ *) &def_)

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct fxcor_1_ {
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
};

#define fxcor_1 (*(struct fxcor_1_ *) &fxcor_)

struct charct_1_ {
    char modfer[6];
};

#define charct_1 (*(struct charct_1_ *) &charct_)

struct tlldat_1_ {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
};

#define tlldat_1 (*(struct tlldat_1_ *) &tlldat_)

struct hblock_1_ {
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
};

#define hblock_1 (*(struct hblock_1_ *) &hblock_)

struct sv_1_ {
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
};

#define sv_1 (*(struct sv_1_ *) &sv_)

struct sv1_1_ {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
};

#define sv1_1 (*(struct sv1_1_ *) &sv1_)

struct znumbr_1_ {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
};

#define znumbr_1 (*(struct znumbr_1_ *) &znumbr_)

struct ldef_1_ {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
};

#define ldef_1 (*(struct ldef_1_ *) &ldef_)

struct isv_1_ {
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
};

#define isv_1 (*(struct isv_1_ *) &isv_)

struct isv1_1_ {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
};

#define isv1_1 (*(struct isv1_1_ *) &isv1_)

struct ibrkpt_1_ {
    integer ibrkpt[51];
};

#define ibrkpt_1 (*(struct ibrkpt_1_ *) &ibrkpt_)

struct idef_1_ {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
};

#define idef_1 (*(struct idef_1_ *) &idef_)

struct ifxcor_1_ {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
};

#define ifxcor_1 (*(struct ifxcor_1_ *) &ifxcor_)

struct knumbr_1_ {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
};

#define knumbr_1 (*(struct knumbr_1_ *) &knumbr_)

struct addcom_1_ {
    doublereal addcom[25];
};

#define addcom_1 (*(struct addcom_1_ *) &addcom_)

struct tracfl_1_ {
    logical tracfl;
};

#define tracfl_1 (*(struct tracfl_1_ *) &tracfl_)

struct {
    doublereal dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

struct {
    doublereal psname, cs1nam, cs2nam;
    integer ipssub, ics1sb, ics2sb;
} srfnam_;

#define srfnam_1 srfnam_

struct aercom_1_ {
    integer iaerfg, npctpt;
    doublereal pctpts[60]	/* was [3][20] */, pctpln[4], errpts[9]	/* 
	    was [3][3] */;
};

#define aercom_1 (*(struct aercom_1_ *) &aercom_)

struct hold_1_ {
    integer jhldfg, ithcnt, itabh[100];
};

#define hold_1 (*(struct hold_1_ *) &hold_)

struct darray_1_ {
    char darray[120];
};

#define darray_1 (*(struct darray_1_ *) &darray_)

struct xunits_1_ {
    doublereal tabext, ssext;
    integer iold;
};

#define xunits_1 (*(struct xunits_1_ *) &xunits_)

struct xunitc_1_ {
    char oldmod[6];
};

#define xunitc_1 (*(struct xunitc_1_ *) &xunitc_)

/* Initialized data */

struct {
    doublereal e_1[25];
    } znumbr_ = { 0., 1., 2., 3., 5., 10., 90., 1e6, 1e19, .5, .6, .9, 1.1, 
	    1.2, .01, .001, 1e-5, 5e-6, 1e-6, 1e-7, 1e-9, .1, -1., 
	    .0174532925, 3.14159265 };

struct {
    logical e_1[14];
    } ldef_ = { FALSE_, FALSE_, FALSE_, FALSE_, FALSE_, TRUE_, FALSE_, FALSE_,
	     FALSE_, FALSE_, FALSE_, FALSE_, FALSE_, FALSE_ };

struct {
    integer e_1[105];
    } isv_ = { 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

struct {
    integer e_1[50];
    } isv1_ = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	     0, 0, 0, 0, 0, 0, 0 };

struct {
    integer e_1[51];
    } ibrkpt_ = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0 };

struct {
    integer e_1[8];
    } idef_ = { 0, 0, 0, 0, 0, 0, 8, 0 };

struct {
    integer e_1[46];
    } ifxcor_ = { 0, 0, 0, 0, 0, 4, 0, 1, 0, 3, 0, 0, 1, 0, 1, 0, 1, 2, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 400, 0, 0, 0, 5, 0, 4, 0, 0, 
	    0, 0, 0, 0, 0 };

struct {
    integer e_1[40];
    } knumbr_ = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18, 19, 
	    23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 44, 45, 46, 47, 48, 
	    50, 51, 52, 1013, 10000, 1000000, -1 };

struct {
    doublereal e_1[22];
    integer e_2;
    integer fill_3[1];
    integer e_4;
    integer fill_5[1];
    integer e_6;
    integer fill_7[1];
    } addcom_ = { 200., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., -1, {0}, 0, {0}, 0 };

struct {
    logical e_1;
    } tracfl_ = { FALSE_ };

struct {
    doublereal e_1[63];
    } def_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
	     0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    7e4, 0., 0., 0., 0., 0., 0., 0., 4e4, 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 1., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. };

struct {
    integer e_1[2];
    doublereal e_2[73];
    } aercom_ = { 0, 0, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. };

struct {
    integer e_1[2];
    integer fill_2[100];
    } hold_ = { 0, 1 };

struct {
    char e_1[120];
    } darray_ = { "                                                         "
	    "                                                               " }
	    ;

struct {
    doublereal e_1[2];
    integer e_2;
    } xunits_ = { 10., 10., 3 };

struct {
    char e_1[6];
    } xunitc_ = { "INCHES" };

struct {
    doublereal e_1[89];
    } fxcor_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 4500., 0., 0., 0., 0., 1., 0., 0., 0., 0., 0., 0., 0., 0.,
	     0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 10., 0., 5. };

struct {
    char e_1[6];
    } charct_ = { "BLANK " };

struct {
    doublereal e_1[66];
    } tlldat_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    -1e38, -1e38, 0., 0., 0., 0., 0., 0., 1e38, 1e38, 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., -1., 1., -1., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0. };

struct {
    char e_1[144];
    } hblock_ = { "PS      DS      CS      GOLFT   GORGT   GOFWD   GOBACK  G"
	    "OUP    GODOWN  TO      PAST    ON      TANTO   PSTAN   DYNDMP  A"
	    "ERR    CLDATA  GERR    " };

struct {
    doublereal e_1[375];
    } sv_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    5e-5, 5e-5, 5e-5, 5e-5, 0., .99995, .99995, .99995, .99995, 0., 
	    1e-4, 1e-4, 1e-4, 1e-4, 0., .001, .001, .001, .001, 0., 1e-6, 
	    1e-6, 1e-6, 1e-6, 0., 5e-5, 5e-5, 5e-5, 5e-5, 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 4500., 4500., 4500., 4500., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 5e-4, 
	    5e-4, 5e-4, 5e-4, 0., 5e-4, 5e-4, 5e-4, 5e-4, 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., -1., 1., 0., 0., 1., 0., 
	    0., 0., 0., -1., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. };

struct {
    doublereal e_1[105];
    } sv1_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
	     0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0. };


/* *** SOURCE FILE : M0000702.W03   *** */


/* .....FORTRAN BLOCK DATA ROUTINE  ...APT227      2/69   RC,HG,RN,AR */



/* ...  THIS ROUTINE CONTAINS A LISTING OF ALL CDE PACKAGES */
/* ...      IN THE EXECUTION COMPLEX EXCEPT: */
/* ...  BLOCKS 4., 5., AND 17. ARE LISTED IN APT228 */
/* ...  BLOCKS 6.,16., AND 18. ARE LISTED IN APT229 */
/* ...  NOTE.APT228 AND APT229 ARE DUMMY ROUTINES AND */
/* ...  SHOULD NOT BE LINK EDITED */

/* Subroutine */ int bda227_(void)
{
    return 0;
} /* bda227_ */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





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




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*   *** IBRKPT *** */



/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/* ...  21. ADDCOM BLOCK */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...  22. TRACE BLOCK */

/* ...  23. DSNAME BLOCK */



/*     24.   SRFNAM BLOCK */


/*     25.   COMMON FOR AERR INFORMATION */



/*          29.  COMMON FOR HOLD INFORMATION */



/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* *****   DATA FOR DEF BLOCK   **************************************** */








/* *****   DATA FOR FXCOR BLOCK ******************************* */

/* ** B FXCOR. ARELEM REAL ENVIROMENTAL VARIABLES. */
/*     EVERY VARIABLE IN THIS BLOCK MUST RETAIN A MINIMUM OF */
/*     7 DECIMAL FIGURES OF RELATIVE SIGNIFICANCE. */







/*        TOOL HT. ALWAYS 5 INCH. */

/*  ***** DATA FOR NEW TLLDAT BLOCK ************ */





/*  ***** DATA FOR HOLRTH BLOCK ************************ */







/* *****  DATA FOR SV BLOCK ********************************* */

/*      EVERY VARIABLE IN THIS BLOCK MUST RETAIN A MINIMUM OF */
/*      7 DECIMAL FIGURES OF RELATIVE SIGNIFICANCE. */

/*      FOR ONE DIMENSIONAL ARRAYS - INDEX INDICATES SURFACE */
/*      FOR TWO DIMENSIONAL ARRAYS - 1ST INDEX INDICATES VECTOR COMPONENT */
/*                                   2ND INDES INDICATES SURFACE */
/*      ***** SURFACE *** INDEX ***** */
/*             GOUGE        1 */
/*             PART         2 */
/*             DRIVE        3 */
/*             CHECK1       4 */
/*             CHECK2       5 */





/*  ***** DATA FOR ZNUMBR BLOCK ************************ */



/*  ***** DATA FOR LDEF BLOCK ************************** */



/*  ***** DATA FOR ISV BLOCK *************************** */



/*    *** IBRKPT BLOCK DATA *** */


/*    *** KNUMBR BLOCK DATA--EACH VARIABLE NAME IS ITS VALUE (K0=0 ETC.) */



/*    *** IDEF BLOCK DATA *** */



/*    *** IFXCOR BLOCK DATA *** */


/*  ***** DATA FOR ADDCOM BLOCK ************** */




/*  ****  TRACFL BLOCK DATA ****************** */
/*     INITIALIZED FALSE SET TRUE BY FIRST ENTRY INTO APT024. */



/* ...  ***** DATA FOR AERR BLOCK ****** */

/*     ***** DATA FOR HOLD ********** */

/*     *****DATA FOR DARRAY *********** */

/* ---    INITIALIZATION FOR UNITS */

