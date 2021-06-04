/* APT232.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000852.V02   *** */

/* .....FORTRAN SUBROUTINE             APT232...              4/1/68   GK */
/* Subroutine */ int apt232_(integer *number, doublereal *tolrns, doublereal *
	taus, doublereal *one)
{
    /* Initialized data */

    static doublereal zlit1 = .02;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


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





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --taus;
    --tolrns;

    /* Function Body */



/*      DIMENSION TOLRNS(4),TAUS(1) */
    ifxcor_1.is = ifxcor_1.ips;
    i__1 = ifxcor_1.numsfs;
    for (i__ = 1; i__ <= i__1; ++i__) {
L10:
	taus[ifxcor_1.is] = *one * tolrns[i__];
	sv_1.tau[ifxcor_1.is - 1] = sv_1.tau1[ifxcor_1.is - 1] - sv_1.tau2[
		ifxcor_1.is - 1];
	sv_1.eps1[ifxcor_1.is - 1] = znumbr_1.z1em1 * sv_1.tau[ifxcor_1.is - 
		1];
	sv_1.eps2[ifxcor_1.is - 1] = znumbr_1.z1 - sv_1.eps1[ifxcor_1.is - 1];
	sv_1.eps3[ifxcor_1.is - 1] = znumbr_1.z2 * sv_1.eps1[ifxcor_1.is - 1];
	sv_1.eps4[ifxcor_1.is - 1] = znumbr_1.z2 * sv_1.tau[ifxcor_1.is - 1];
	sv_1.eps6[ifxcor_1.is - 1] = zlit1 * sv_1.eps1[ifxcor_1.is - 1];
	sv_1.eps8[ifxcor_1.is - 1] = sv_1.eps1[ifxcor_1.is - 1];
	if (ifxcor_1.is - ifxcor_1.ics >= 0) {
	    goto L30;
	} else {
	    goto L20;
	}
L20:
	ifxcor_1.is += ifxcor_1.lsv;
	if (*number - i__ <= 0) {
	    goto L10;
	} else {
	    goto L50;
	}
L30:
	if (i__ - *number >= 0) {
	    goto L60;
	} else {
	    goto L40;
	}
L40:
	ifxcor_1.is += ifxcor_1.lsv1;
L50:
	;
    }
L60:
    isv_1.jent[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.jent[ifxcor_1.ids - 1] = knumbr_1.k1;


    return 0;
} /* apt232_ */

