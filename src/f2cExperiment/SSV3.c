/* SSV3.f -- translated by f2c (version 20100827).
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
    integer kcon[14];
} a0con_;

#define a0con_1 a0con_

struct {
    integer i__[23];
} ataptb_;

#define ataptb_1 ataptb_

struct {
    integer j[22];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal p[40];
} apostp_;

#define apostp_1 apostp_

struct {
    doublereal t[4];
} atime_;

#define atime_1 atime_

struct {
    integer jflag;
} aoutfg_;

#define aoutfg_1 aoutfg_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer jpar[20];
} parlst_;

#define parlst_1 parlst_

struct {
    integer kentry;
} aent_;

#define aent_1 aent_

struct {
    integer icmtes;
} cmptst_;

#define cmptst_1 cmptst_

struct {
    integer stklst[3], stack[198]	/* was [2][99] */, argstk[99];
} stklst_;

#define stklst_1 stklst_

struct {
    logical flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    real cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer nonept;
} negptr_;

#define negptr_1 negptr_

struct {
    integer seqno;
} seqcom_;

#define seqcom_1 seqcom_

struct {
    char seqnum[6];
} cseqcm_;

#define cseqcm_1 cseqcm_

struct {
    integer cfsize[3], maxsiz[2], cansiz[200]	/* was [2][100] */, iisc, ksc[
	    900]	/* was [3][300] */;
} cfsize_;

#define cfsize_1 cfsize_

struct {
    logical cilprt, ilprt, interp, assemb, tracfl, prterr, mchdng;
} prt_;

#define prt_1 prt_

struct {
    integer rngpt, range[100];
} sbscpt_;

#define sbscpt_1 sbscpt_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    char chr[400];
} chrx_;

#define chrx_1 chrx_

struct {
    integer iltext[4], textin[90];
} iltext_;

#define iltext_1 iltext_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx2[902];
} macxx2_;

#define macxx2_1 macxx2_

struct {
    integer macxx3[1430];
} macxx3_;

#define macxx3_1 macxx3_

struct {
    integer macxx4[100];
} macxx4_;

#define macxx4_1 macxx4_

struct {
    integer itmpsv[135];
} macxx5_;

#define macxx5_1 macxx5_

struct {
    integer macxx6[1300];
} macxx6_;

#define macxx6_1 macxx6_

struct {
    integer macxx7[182];
} macxx7_;

#define macxx7_1 macxx7_

struct {
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer modulo, modhlf;
} moduli_;

#define moduli_1 moduli_

struct {
    integer first[6]	/* was [2][3] */;
} blkcfs_;

#define blkcfs_1 blkcfs_

struct {
    integer comp26[13], tagtbl[3];
} comp26_;

#define comp26_1 comp26_

struct {
    integer bit[32];
} bitcom_;

#define bitcom_1 bitcom_

struct {
    integer bgeom[4];
} bgeom_;

#define bgeom_1 bgeom_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    integer isscom[7], isstrm[2];
} isscom_;

#define isscom_1 isscom_

struct {
    integer icallf;
} calflg_;

#define calflg_1 calflg_

struct {
    logical libprt;
} libprt_;

#define libprt_1 libprt_

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

struct {
    integer canstr[2], canstk[16];
} canstr_;

#define canstr_1 canstr_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

struct {
    integer pagpak, isc, iscarr, icform, ifloat, icom, macwds, ppwrds;
    logical macflg, labflg, rsvflg;
    integer lpage, buffer[256], labbuf[256], ibuf, ilbuf, pppage, mcpage;
} outbuf_;

#define outbuf_1 outbuf_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

struct {
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer srctbl[1482];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

struct {
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    char memnam[8];
} clibcm_;

#define clibcm_1 clibcm_

struct {
    integer ieof;
} libcom_;

#define libcom_1 libcom_

struct {
    real addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    logical cldfg;
    integer iclcod, iclcnt, icline, iclblk, iclrcd, icltab[500]	/* was [5][
	    100] */, iptvec[9];
} cldt_;

#define cldt_1 cldt_

struct {
    char pntvct[72];
} chcldt_;

#define chcldt_1 chcldt_

struct {
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    real dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

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
    integer ibrkpt[51];
} ibrkpt_;

#define ibrkpt_1 ibrkpt_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    real psname, cs1nam, cs2nam;
    integer ipssub, ics1sb, ics2sb;
} srfnam_;

#define srfnam_1 srfnam_

struct {
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

struct {
    integer ntb, fpb, ppb, comn, cfb, nblk, nrecrd[10], ntparm[10];
} stor_;

#define stor_1 stor_

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
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp, ac;
} work_;

#define work_1 work_

struct {
    doublereal tabext, ssext;
    integer iold;
} xunits_;

#define xunits_1 xunits_

struct {
    char oldmod[6];
} xunitc_;

#define xunitc_1 xunitc_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    real apt227;
} apt227_;

#define apt227_1 apt227_

struct {
    logical trcflg;
} tracfl_;

#define tracfl_1 tracfl_

struct {
    integer iaerfg, npctpt;
    real pctpts[60]	/* was [3][20] */, pctpln[4], errpts[9]	/* was [3][3] 
	    */;
} aercom_;

#define aercom_1 aercom_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

struct {
    integer kcomt, kcomf;
    logical cilpr;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    real b[256]	/* was [64][4] */, u[4], v[4];
    integer itop[96]	/* was [6][4][4] */, iflag[16]	/* was [4][4] */, 
	    ipnum[4], iseqls, nlast, mcat, jenlas[4], modlas[4], irrlas[4], 
	    ncalmx, ncmx;
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

struct {
    real dgeom[4], dlim[4], tldir[3], dofset;
    integer itldir, idtool, nds;
} xds_;

#define xds_1 xds_

struct {
    real pgeom[4], pside, pthick;
    integer iptool, nps;
} xps_;

#define xps_1 xps_

struct {
    real clrpln[4], fed[4];
    integer nclrpl, nfeed;
} xfeed_;

#define xfeed_1 xfeed_

struct {
    real sstep[4];
    integer nstepo;
} xstepo_;

#define xstepo_1 xstepo_

struct {
    real axis[3];
    integer iaxis, naxis;
} xaxis_;

#define xaxis_1 xaxis_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    real sbond0, sbond[9];
    integer mmode, icon;
    real pts[20];
    integer jag;
} ssbond_;

#define ssbond_1 ssbond_

struct {
    real saveh[50];
} hsave_;

#define hsave_1 hsave_

struct {
    integer lseqno;
} sqnc_;

#define sqnc_1 sqnc_

struct {
    integer iddst;
} iddst_;

#define iddst_1 iddst_

struct {
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

struct {
    real ua, va, pnum, ut, us, fnam;
} parmfc_;

#define parmfc_1 parmfc_

struct {
    integer izeil;
} izeill_;

#define izeill_1 izeill_

struct {
    real editor[1500];
} editor_;

#define editor_1 editor_

struct {
    integer kflags[5];
} kflags_;

#define kflags_1 kflags_

struct {
    integer ncfsto[60000];
    real cscale;
} ncfsto_;

#define ncfsto_1 ncfsto_

struct {
    integer newsys, istand, imachn, ifirst, num, konsys[2];
} verson_;

#define verson_1 verson_

struct {
    integer nrecc[21];
} nrecc_;

#define nrecc_1 nrecc_


/* Main program */ int MAIN__(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int sprvis_(void);
#define can ((doublereal *)&_BLNK__1 + 40)
#define jlin ((integer *)&addcom_1 + 23)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((real *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define cflags ((logical *)&super_1)
#define lxtras ((logical *)&super_1 + 9)
#define clngth ((real *)&addcom_1 + 1)
#define ibtflg ((integer *)&addcom_1 + 22)
#define kdynfl ((integer *)&addcom_1 + 24)
#define bcanon ((doublereal *)&_BLNK__1 + 40)


/* ...     COMMON AREAS FROM SYSTEM 360 APT */




/* ...                SYSTEM I/O FILES */




/* ...         2.    STACK AND POINTER STORAGE */


/* ...         5.    PROGRAM CONTROL FLAGS */



/* ...         6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */


/* ...     7.   STRING STORAGE AREA */



/* ...      13.      NAMTBL POINTERS TO NEGATIVE NUMBERS */


/* ...        11.    SEQUENCE NUMBER STORAGE */

/*                  COMMENT OF  SEQNO AND SEQNUM */


/* ...        12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */






/* ...      14.      I. L. LIST OPTION FLAGS */



/* ...        15.    ARRAY LIMIT STORAGE */


/* ...        16.    LITERALS FOR I. L. OPERATION CODES */



/* ...        17.    MODE CODES */



/* ...        18.    STRING STORAGE AREA */


/* ...      19.      INTERMEDIATE LANGUAGE TEXT */



/*         22.      MACRO PROCESSING VARIABLES */


/*         23.      MACRO PROCESSING ARRAYS */


/*         24.      MACRO PROCESSING ARRAYS */


/*         25.      MACRO PROCESSING ARRAYS */


/*         25A.     MACRO PROCESSING ARRAYS */


/*         26.      MACRO PROCESSING ARRAYS */


/*         26A.     MACRO PROCESSING ARRAYS */


/* ...        27.    OPERAND MODIFIERS */




/* ...        29.    CLASS CODE MODULI */


/* ...        30.   NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK */

/* .... */
/*           31.   COMMON BLOCK FOR PRO026 AND MOTION */
/* .... */


/*           32.   COMMON BLOCK FOR SETBIT AND BITMCH */

/* ... */
/* ...       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE */



/*           36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */


/* ...        37.    INCLUSIVE SUBSCRIPT VARIABLES */



/* ...     38.  COMMON BLOCK MACRO CALL STATEMENT */
/*             INDICATES A MACRO CALL BEING PROCESSED */


/* ...        39.    COMMON BLOCK LIBRARY PRINTING FLAG */




/* ...        41.    NUMBER TABLE OVERFLOW VARIABLES */







/*           42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE */


/*           43.    COMMON BLOCK FOR LOOP */



/*           44.    COMMON BLOCK FOR ERROR POSITIONS */






/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





















/* ...  21. ADDCOM BLOCK */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */











/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */



/*        COMMON BLOCKS FOR SURFACE NAME AND SUBSCRIPT STORAGE */

/*     23. DSNAME BLOCK */



/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** IBRKPT *** */



/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */



/*     24. SRFNAM BLOCK */





/* .... SCULPTURED SURFACES SCRATCH PAD AREA */







/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/* MODULE:       WORK.INC */
/* PURPOSE:      TO DECLARE THE WORKING VARIABLES USED BY THE SSR1 */
/*               INTERPRETOR. */

/* DATE:         05-MAR-85 */
/* AUTHOR:       C. LASHER */











/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/* ...  22. TRACE BLOCK */

/*     25.   COMMON FOR AERR INFORMATION */



/*          29.  COMMON FOR HOLD INFORMATION */



/* CONST--COMMON CONTAINING CONSTANTS */








/*    MAXLDA CONTAINS THE MAXIMUM SPACE AVAILABLE FOR LDA'S */

/*  UEBERGABECOMMON FUER --PARMF-- */







    sprvis_();
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

#undef bcanon
#undef kdynfl
#undef ibtflg
#undef clngth
#undef lxtras
#undef cflags
#undef sscan
#undef elmax
#undef canon
#undef sinl
#undef cosl
#undef jlin
#undef can


/* Main program alias */ int ssv3_ () { MAIN__ (); return 0; }
