/* DYNDMP.f -- translated by f2c (version 20100827).
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
    integer ibrkpt[51];
} ibrkpt_;

#define ibrkpt_1 ibrkpt_

struct {
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

/* *** SOURCE FILE : M0000897.V04   *** */


/* .....FORTRAN SUBROUTINE             DYNDMP...              4/1/68   GK */
/* IBFTC DYNDMP  XR6 */
/* Subroutine */ int dyndmp_(doublereal *brkpnt, doublereal *onoff, 
	doublereal *ptno)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, l, n;
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define elmax ((doublereal *)&addcom_1)
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
#define kdynfl ((integer *)&addcom_1 + 48)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...  21. ADDCOM BLOCK */


/*   *** IBRKPT *** */



/* ***    VALUES OF BRKPNT SET AS FOLLOWS */
/*                  1 ACTIVATES ALL BREAKPOINTS */
/*                  100 ACTIVATES ALL AJUNDD AND AMIND BREAKPOINTS */
/*                  200 ACTIVATES ALL ARLM3 BREAKPOINTS */
/*                  500 ACTIVATES ALL GO BREAKPOINTS */
/*                  IJK ACTIVATES THE JK BREAKPOINT IN THE I SERIES */
/* *** */


    *kdynfl = knumbr_1.k1;
    n = 51;
    l = (integer) (*brkpnt);
    if (l == knumbr_1.k1) {
	goto L30;
    }
    j = l / 100;
    k = l - j * 100;
    l = knumbr_1.k10 * (j - knumbr_1.k1) + k;
    n = l;
/* ...  IF K=0, ACTIVATE OR DEACTIVATE ALL BREAKPOINTS FOR THAT ROUTINE */
    if (k < 0) {
	goto L50;
    } else if (k == 0) {
	goto L10;
    } else {
	goto L30;
    }
L10:
    if (j != knumbr_1.k2) {
	goto L20;
    }
    n += knumbr_1.k10;
L20:
    n += knumbr_1.k10;
    l += knumbr_1.k1;
/* ...  EACH BREAKPOINT CORRESPONDS TO AN ELEMENT OF THE ARRAY BRAKPT(I) */
/*        THE BREAKPOINT IS ACTIVATED OR DEACTIVATED ACCORDING AS HOW */
/*        BRAKPT(J)=1 OR 0 */
L30:
    i__1 = n;
    for (j = l; j <= i__1; ++j) {
/* L40: */
	ibrkpt_1.ibrkpt[j - 1] = (integer) (*onoff);
    }
/* ...  STRTNO CONTAINS THE NUMBER OF THE FIRST CUTTER POINT TO OUTPUT */
/*     DYNDMP PRINTING FOR EACH CUT SEQUENCE */
    fxcor_1.strtno = *ptno;
L50:
    return 0;
} /* dyndmp_ */

#undef kdynfl
#undef clngth
#undef ibtflg
#undef elmax
#undef sinl
#undef cosl
#undef jlin


