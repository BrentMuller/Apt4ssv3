/* APT011.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__3 = 3;

/* *** SOURCE FILE : M0000693.V06   *** */

/* .....FORTRAN SUBROUTINE  ....APT011         8/68                    RN */


/*              FORTRAN SUBROUTINE APT011 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT DEFINED */
/*              AS THE INTERSECTION CLOSEST TO A GIVEN POINT OF */
/*              A TABCYL AND A LINE BY THE FOLLOWING APT */
/*              STATEMENT */
/*                RESULT = POINT/INTOF, LIN, TAB, PT */

/* LINKAGE      CALL APT011 (RESULT, LIN, TAB, PT) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING LINE */
/*              LIN     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT LINE */
/*              TAB     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT TABCYL */
/*              PT      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT001 */
/*              SUBROUTINE          APT092 */
/*              SUBROUTINE          APT093 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DDTABC */
/*              LOGICAL FUNCTION    LINDEF */
/*              SUBROUTINE          SCHTB */

/* Subroutine */ int apt011_(doublereal *result, doublereal *lin, doublereal *
	tab, doublereal *pt)
{
    /* Local variables */
    static integer i__, j11, m11, l11;
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int apt001_(doublereal *), apt094_(integer *, 
	    doublereal *, integer *);
    static integer iabcl;
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int schtb_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddtabc_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern logical lindef_(doublereal *, integer *);







/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */






/* ...     TRANSFER ARRAYS, CHECK INPUT */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pt;
    --tab;
    --lin;
    --result;

    /* Function Body */
    iabcl = 0;
    if (ldef_1.subflg) {
	iabcl = 1;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	dshar3_1.p[i__ - 1] = pt[i__];
	dshar3_1.l[i__ - 1] = lin[i__];
/* L10: */
	dshar3_1.v[i__ - 1] = tab[i__];
    }
    dshar3_1.l[2] = lin[3];
    dshar3_1.l[3] = lin[4];
    ldef_1.unflag = lindef_(dshar3_1.l, &knumbr_1.k5) || ckdef_(dshar3_1.p) ||
	     ckdef_(dshar3_1.v);
    if (ldef_1.unflag) {
	return 0;
    }

/* ... RETRIEVE TABCYL EXTERNAL CANONICAL FORM. STORE CANON INDEX IN J11. */

    apt094_(&c__3, &tab[1], &j11);
    if (ckdef_(&tab[1])) {
	goto L99;
    }

/* ...     FIND PART OF TABCYL CLOSEST TO INPUT POINT P, USING SCHTB */

    schtb_(&canon[j11 - 2]);

/* ...     CONSIDER TABCYL AS A CHECK SURFACE, LINE AS TOOL NORMAL, */
/* ...     DESIRED POINT AS SURFACE POINT -USE DDTABC TO FIND SP */
    m11 = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ics;
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar3_1.sc[i__ - 1] = sv_1.tn[i__ + ifxcor_1.ics * 3 - 4];
	dshar3_1.sc[i__ + 2] = sv_1.tp[i__ + ifxcor_1.ics * 3 - 4];
/* L30: */
	sv_1.tp[i__ + ifxcor_1.ics * 3 - 4] = dshar3_1.l[i__ - 1] * 
		dshar3_1.l[3];
    }
    sv_1.tn[ifxcor_1.ics * 3 - 3] = dshar3_1.l[1];
    sv_1.tn[ifxcor_1.ics * 3 - 2] = -dshar3_1.l[0];
    sv_1.tn[ifxcor_1.ics * 3 - 1] = znumbr_1.z0;
    l11 = isv_1.iop[ifxcor_1.ics - 1];
    isv_1.iop[ifxcor_1.ics - 1] = 0;
    ldef_1.subflg = TRUE_;
    ddtabc_(&canon[j11 - 2]);
    if (ifxcor_1.ier != knumbr_1.k0) {
	idef_1.ierror = 72;
    }
    result[1] = sv_1.sp[ifxcor_1.ics * 3 - 3];
    result[2] = sv_1.sp[ifxcor_1.ics * 3 - 2];

/* ...     GET THIRD COORDINATE */

    if (iabcl == 1) {
	goto L88;
    }
    apt001_(&result[1]);
L88:
    ifxcor_1.ier = 0;
    ifxcor_1.is = m11;
    isv_1.iop[ifxcor_1.ics - 1] = l11;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.ics * 3 - 4] = dshar3_1.sc[i__ - 1];
/* L40: */
	sv_1.tp[i__ + ifxcor_1.ics * 3 - 4] = dshar3_1.sc[i__ + 2];
    }
    ldef_1.subflg = FALSE_;
L99:
    return 0;
} /* apt011_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


