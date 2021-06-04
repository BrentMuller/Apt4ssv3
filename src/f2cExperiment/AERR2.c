/* AERR2.f -- translated by f2c (version 20100827).
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
    doublereal a, b, c__, cendis, cmove[3], com1, com4, dir[3], dp, dpe, 
	    dpcnt, dpi, dpl, dp1, d1, d2a, flipck, fwd[3], ogle[3], p1[3], p2[
	    3], rdrn, refpnt[3], tangl, tes[3], tew[3], uvec[3], u2[3], v[3], 
	    vl, zl, zlnorm[3], zlpnt[3], zl1, param[6], r__[6], savpar[4], 
	    seg[9], slope, sqroot, unn, upp, vint, vnn, vpp;
} dshar4_;

#define dshar4_1 dshar4_

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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

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

struct {
    integer iaerfg, npctpt;
    doublereal pctpts[60]	/* was [3][20] */, pctpln[4], errpts[9]	/* 
	    was [3][3] */;
} aercom_;

#define aercom_1 aercom_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

/* Table of constant values */

static integer c__1 = 1;
static integer c__26 = 26;
static integer c__27 = 27;
static integer c__5 = 5;
static integer c__36 = 36;
static integer c__3 = 3;
static integer c__39 = 39;
static integer c__44 = 44;
static integer c__17 = 17;
static integer c__61 = 61;
static integer c__8 = 8;
static integer c__69 = 69;
static integer c__10 = 10;
static integer c__7 = 7;
static integer c__24 = 24;
static integer c__4 = 4;
static integer c__12 = 12;
static integer c__54 = 54;
static integer c__9 = 9;
static integer c__2 = 2;
static integer c__46 = 46;

/* *** SOURCE FILE : M0001934.V11   *** */

/* ....    FORTRAN SUBROUTINE                 AERR2 */

/* ... THIS ROUTINE WRITES ONTO THE EXFILE TAPE ALL THE INFORMATION */
/*       REQUIRED BY THE CLTAPE EDITOR TO PROCESS ARELEM DIAGNOSTICS */

/*   SUBSIDIARIES   ATAPE, APT242, CUTTER, QSD */


/* Subroutine */ int aerr2_(integer *number, char *subnam, ftnlen subnam_len)
{
    /* Initialized data */

    static integer kerr[10] = { 0,0,1308622848,1,1308622848,1,1308622848,1,0,
	    0 };
    static integer icansz[30] = { 4,4,7,7,4,10,10,10,7,10,2,2,2,10,10,1,1,12,
	    3,3,1,1,1,1,12,2,1,1,2,2 };
    static integer ipow = 1308622848;
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;
    static doublereal equiv_10[4];

    /* Local variables */
    static integer i__, j, l, n, nr, ir, jl, icc;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer isn[2];
    extern /* Subroutine */ int qsd_(doublereal *, integer *, doublereal *, 
	    doublereal *);
    static integer jsz;
    extern integer bcdf_(char *, ftnlen);
    static integer mode;
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer nerr, isub;
    extern /* Subroutine */ int apt242_(void), apt236_(void);
    static doublereal coeff[10];
    extern /* Subroutine */ int atape_(void);
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal trans[12];
#define itemp ((integer *)equiv_10)
#define dtemp (equiv_10)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), aform_();
    static integer isize, jsize, npcpt;
#define clngth ((doublereal *)&addcom_1 + 1)
#define ibtflg ((integer *)&addcom_1 + 44)
    static doublereal dshare[100];
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal canfrm[10];
#define cflags ((logical *)&super_1)
#define lxtras ((logical *)&super_1 + 9)
    static integer numrtn;
    extern /* Subroutine */ int record_(integer *), cprint_(char *, ftnlen), 
	    errout_(integer *), ewrite_(), cutter_(integer *, doublereal *);
    static doublereal sfname;
    static integer iqsdfg;




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  4.  DSHARE BLOCK 4  *** */





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






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...  20. SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...  21. ADDCOM BLOCK */


/* ...                SYSTEM I/O FILES */





/*        COMMON BLOCKS FOR SURFACE NAME AND SUBSCRIPT STORAGE */

/*     23. DSNAME BLOCK */

/*     24. SRFNAM BLOCK */

/*     25. COMMON FOR AERR INFORMATION */



/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





/*        BLANK COMMON CONTAINING CANONICAL FORM OF SURFACES */


/*        CANONICAL SIZE ARRAY FOR VARIOUS MODES OF A SURFACE */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*        DIMENSION FOR ARGUMENTS IN CALL TO QSD AND CUTTER */


/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */


/*     ------------------------------------------------------------ */


    fxcor_1.tal[0] = dshar4_1.fwd[0];
    fxcor_1.tal[1] = dshar4_1.fwd[1];
    fxcor_1.tal[2] = dshar4_1.fwd[2];
    ++super_1.xtras[0];
    ifxcor_1.iaerr = knumbr_1.k1;
    if (first) {
	kerr[0] = bcdf_("AERR", (ftnlen)4);
	kerr[1] = bcdf_("    ", (ftnlen)4);
	first = FALSE_;
    }
    nerr = *number;
    kerr[8] = bcdf_(subnam, (ftnlen)4);
    kerr[9] = bcdf_(subnam + 4, (ftnlen)4);
    numrtn = nerr / 100;
    atape_();
    record_(isn);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_(" ***** RESTART DIAGNOSTIC ", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&nerr, darray_1.darray, &c__27, &c__5, (ftnlen)120);
    cform_("ISN", darray_1.darray, &c__36, &c__3, (ftnlen)3, (ftnlen)120);
    iconv_(isn, darray_1.darray, &c__39, &c__5, (ftnlen)120);
    cform_(" FROM SUBROUTINE ", darray_1.darray, &c__44, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(subnam, darray_1.darray, &c__61, &c__8, (ftnlen)8, (ftnlen)120);
    cform_("*****", darray_1.darray, &c__69, &c__5, (ftnlen)5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    errout_(&nerr);

/* ..   ***** RESTART DIAGNOSTIC - OUTPUT SURFACE VARIABLE DATA ***** */

/*        SET ERROR LEVEL FLAG TO VALUE 8 */
/* L20: */
    super_1.errx = knumbr_1.k8;

/*        CHECK FOR POCKET ERROR PROCESSING */
    if (numrtn - 35 != 0) {
	goto L22;
    } else {
	goto L90;
    }

/* ...     IF ERROR IS FOR MISSING CUTTER USE A POINT CUTTER */
L22:
    if (ifxcor_1.ictdef != knumbr_1.k1) {
	goto L23;
    }

    ifxcor_1.ictdef = 0;
    nr = 0;
    kerr[3] = 1;
    kerr[5] = 2;
    kerr[7] = nerr;
    ewrite_(&symfil_1.exfile, &nr, kerr, &c__10, &ir);
    ifxcor_1.iaerr = 0;
    nr = 7;
    for (i__ = 1; i__ <= 9; ++i__) {
	canfrm[i__ - 1] = 0.f;
/* L21: */
    }
    cutter_(&nr, canfrm);
    goto L100;

/*        OUTPUT ERROR NUMBER AND CUTTER PARAMETERS */

L23:
    kerr[3] = 1;
    kerr[5] = 9;
    kerr[7] = nerr;
    aform_(dshare, kerr, &c__5);
    aform_(&dshare[5], fxcor_1.cutdat, &c__7);
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, dshare, &c__24, &ir);

/*        CHECK FOR NO SURFACE VARIABLE OUTPUT */
/* L24: */
    if (aercom_1.iaerfg <= 0) {
	goto L25;
    } else {
	goto L99;
    }

/*        WRITE NECESSARY SV AND ISV VARIABLES FOR PS ON EXFILE */
L25:
    l = knumbr_1.k2;
    j = ifxcor_1.ips;
    sfname = srfnam_1.psname;
    isub = srfnam_1.ipssub;


/* .... *** PRIMARY OUTPUT LOOP FOR EACH SURFACE *** */

L30:
    l += knumbr_1.k1;
    ifxcor_1.ic = isv_1.icanon[j - 1];
    mode = isv_1.isfidn[j - 1];

/*        SAVE CANONICAL FORM */
    isize = icansz[mode - 1];
    icc = ifxcor_1.ic;
    i__1 = isize;
    for (i__ = 1; i__ <= i__1; ++i__) {
	canfrm[i__ - 1] = canon[icc - 1];
	++icc;
/* L32: */
    }

/*        CALCULATE VT VALUES FOR ERRORS FROM AMIND ASSOCIATED ROUTINES */
/*              (SINCE THEY MAY BE MISSING AT THIS TIME) */
    if (numrtn < 260 || numrtn > 272) {
	goto L34;
    }

/* L33: */
    sv_1.vt[j * 3 - 3] = sv_1.tp[j * 3 - 3] - sv_1.th[j - 1] * sv_1.tn[j * 3 
	    - 3] - fxcor_1.te[0];
    sv_1.vt[j * 3 - 2] = sv_1.tp[j * 3 - 2] - sv_1.th[j - 1] * sv_1.tn[j * 3 
	    - 2] - fxcor_1.te[1];
    sv_1.vt[j * 3 - 1] = sv_1.tp[j * 3 - 1] - sv_1.th[j - 1] * sv_1.tn[j * 3 
	    - 1] - fxcor_1.te[2];

/*        PRIMARY OUTPUT STATEMENT CONTAINING NECESSARY SV AND ISV */
/*        VARIABLES, SURFACE NAME AND TYPE, AND CANONICAL FORM */

L34:
    jsize = isize + 30;
    jl = j + knumbr_1.k2;
    kerr[3] = l;
    kerr[5] = jsize;
    kerr[7] = nerr;
    aform_(dshare, kerr, &c__5);
    itemp[0] = ipow;
    itemp[1] = isv_1.itlon[j - 1];
    itemp[2] = ipow;
    itemp[3] = isv_1.isftyp[j - 1];
    itemp[4] = ipow;
    itemp[5] = isv1_1.ifl4[j - 1];
    itemp[6] = ipow;
    itemp[7] = isv1_1.ifar[j - 1];
    aform_(&dshare[5], dtemp, &c__4);
    aform_(&dshare[9], &sv_1.tau1[j - 1], &c__1);
    aform_(&dshare[10], &sv_1.tau2[j - 1], &c__1);
    aform_(&dshare[11], &sv_1.th[j - 1], &c__1);
    aform_(&dshare[12], &sv_1.s[j - 1], &c__1);
    aform_(&dshare[13], &sv_1.rc[j - 1], &c__1);
    aform_(&dshare[14], &sv_1.sp[j * 3 - 3], &c__3);
    aform_(&dshare[17], &sv_1.sn[j * 3 - 3], &c__3);
    aform_(&dshare[20], &sv_1.tn[j * 3 - 3], &c__3);
    aform_(&dshare[23], &sv_1.cc[j * 3 - 3], &c__3);
    aform_(&dshare[26], &sv_1.vt[j * 3 - 3], &c__3);
    aform_(&dshare[29], &sfname, &c__1);
    itemp[1] = isub;
    itemp[3] = mode;
    itemp[5] = isize;
    aform_(&dshare[30], dtemp, &c__3);
    aform_(&dshare[33], canfrm, &isize);
    nr = 0;
    n = jsize + 3 << 1;
    ewrite_(&symfil_1.exfile, &nr, dshare, &n, &ir);

/*        CHECK FOR QUADRIC, LCONIC, OR GCONIC TYPE SURFACES, */
/*        IF FOUND, CALL QSD TO IDENTIFY AND SOLVE FOR PARAMETERS */

    switch (mode) {
	case 1:  goto L35;
	case 2:  goto L35;
	case 3:  goto L35;
	case 4:  goto L35;
	case 5:  goto L35;
	case 6:  goto L80;
	case 7:  goto L80;
	case 8:  goto L80;
	case 9:  goto L35;
	case 10:  goto L80;
	case 11:  goto L35;
	case 12:  goto L35;
	case 13:  goto L35;
	case 14:  goto L80;
	case 15:  goto L35;
	case 16:  goto L35;
	case 17:  goto L35;
	case 18:  goto L35;
	case 19:  goto L35;
	case 20:  goto L35;
	case 21:  goto L35;
	case 22:  goto L35;
	case 23:  goto L35;
	case 24:  goto L35;
	case 25:  goto L35;
	case 26:  goto L35;
	case 27:  goto L35;
	case 28:  goto L35;
	case 29:  goto L35;
	case 30:  goto L35;
    }

/*        CHECK FOR FURTHER SURFACE OUTPUT */
L35:
    if (ifxcor_1.numsur + knumbr_1.k2 == l || ifxcor_1.numsur <= knumbr_1.k0) 
	    {
	goto L95;
    }
    if ((i__1 = l - knumbr_1.k4) < 0) {
	goto L40;
    } else if (i__1 == 0) {
	goto L50;
    } else {
	goto L60;
    }

/*        WRITE NECESSARY SV AND ISV VARIABLES FOR DS ON EXFILE */
L40:
    j = ifxcor_1.ids;
    ifxcor_1.igoto = knumbr_1.k1;
    ifxcor_1.isrch = knumbr_1.k1;
    sfname = dsname_1.dsname;
    isub = dsname_1.namsub;
    goto L30;

/*        WRITE NECESSARY SV AND ISV VARIABLES FOR CS1 ON EXFILE */
L50:
    j = ifxcor_1.ics;
    sfname = srfnam_1.cs1nam;
    isub = srfnam_1.ics1sb;
    goto L30;

/*        WRITE NECESSARY SV AND ISV VARIABLES FOR CS2 ON EXFILE */
L60:
    j += ifxcor_1.lsv1;
    sfname = srfnam_1.cs2nam;
    isub = srfnam_1.ics2sb;
    goto L30;

/*        OUTPUT QUADRIC INFORMATION */

L80:
    qsd_(canfrm, &iqsdfg, coeff, trans);
    kerr[3] = 7;
    kerr[5] = 24;
    kerr[7] = iqsdfg;
    nr = 0;
    aform_(dshare, kerr, &c__5);
    aform_(&dshare[5], coeff, &c__10);
    aform_(&dshare[15], trans, &c__12);
    ewrite_(&symfil_1.exfile, &nr, dshare, &c__54, &ir);
    goto L35;

/*        OUTPUT POCKET INFORMATION AND RETURN */

L90:
    jsz = aercom_1.npctpt * 3;
    jsize = jsz + 16;
    kerr[3] = 8;
    kerr[5] = jsize;
    kerr[7] = nerr;
    nr = 0;
    n = jsize + 3 << 1;
    aform_(dshare, kerr, &c__5);
    itemp[1] = aercom_1.npctpt;
    aform_(&dshare[5], dtemp, &c__1);
    aform_(&dshare[6], aercom_1.errpts, &c__9);
    aform_(&dshare[15], aercom_1.pctpln, &c__4);
    i__1 = npcpt * 3;
    aform_(&dshare[19], aercom_1.pctpts, &i__1);
    ewrite_(&symfil_1.exfile, &nr, dshare, &n, &ir);
    goto L99;

/*        WRITE NECESSARY VARIABLES FOR IDENTIFICATION OF SURFACE */

L95:
    nr = 0;
    kerr[3] = 2;
    kerr[5] = 20;
    kerr[7] = ifxcor_1.icscnt;
    aform_(dshare, kerr, &c__5);
    itemp[1] = ifxcor_1.igo;
    itemp[3] = ifxcor_1.istrup;
    aform_(&dshare[5], dtemp, &c__2);
    aform_(&dshare[7], &fxcor_1.dpmax, &c__1);
    itemp[1] = ifxcor_1.nmpnts;
    aform_(&dshare[8], dtemp, &c__1);
    aform_(&dshare[9], elmax, &c__1);
    aform_(&dshare[10], fxcor_1.ti, &c__3);
    aform_(&dshare[13], fxcor_1.te, &c__3);
    itemp[1] = ifxcor_1.is;
    aform_(&dshare[16], dtemp, &c__1);
    aform_(&dshare[17], fxcor_1.tal, &c__3);
    aform_(&dshare[20], fxcor_1.ta, &c__3);
    ewrite_(&symfil_1.exfile, &nr, dshare, &c__46, &ir);

    apt236_();
    apt242_();
L99:
    aercom_1.iaerfg = 0;
L100:
    return 0;
} /* aerr2_ */

#undef lxtras
#undef cflags
#undef bcanon
#undef ibtflg
#undef clngth
#undef dtemp
#undef itemp
#undef sscan
#undef elmax
#undef canon
#undef sinl
#undef cosl
#undef jlin
#undef can


