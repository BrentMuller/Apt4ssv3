/* TLLFT.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

/* *** SOURCE FILE : M0000971.V03   *** */


/* ...FORTRAN SUBROUTINES TLLFT,TLRGT,TLON,TLONPS,TLOFPS... 5/9/72 */


/* Subroutine */ int tllft_(void)
{
    static integer i__, j, k, l;







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/* .... TOOL IS LEFT OF DS */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



    i__ = 1;
    j = 1;
    k = 1;
    l = ifxcor_1.ids;


    ifxcor_1.motmod = i__;
    isv_1.isftyp[l - 1] = j;
    if (isv_1.itlon[l - 1] == k) {
	goto L10;
    }
    isv_1.itlon[l - 1] = k;
    isv_1.jent[l - 1] = 1;
L10:
    return 0;
} /* tllft_ */






/* Subroutine */ int tlrgt_(void)
{
    static integer i__, j, k, l;







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/* .... TOOL IS RIGHT OF DS */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



    i__ = 2;
    j = 1;
    k = 1;
    l = ifxcor_1.ids;


    ifxcor_1.motmod = i__;
    isv_1.isftyp[l - 1] = j;
    if (isv_1.itlon[l - 1] == k) {
	goto L10;
    }
    isv_1.itlon[l - 1] = k;
    isv_1.jent[l - 1] = 1;
L10:
    return 0;
} /* tlrgt_ */






/* Subroutine */ int tlon_(void)
{
    static integer i__, j, k, l;







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/* .... TOOL END IS ON DS */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



    i__ = 3;
    j = 3;
    k = 0;
    l = ifxcor_1.ids;


    ifxcor_1.motmod = i__;
    isv_1.isftyp[l - 1] = j;
    if (isv_1.itlon[l - 1] == k) {
	goto L10;
    }
    isv_1.itlon[l - 1] = k;
    isv_1.jent[l - 1] = 1;
L10:
    return 0;
} /* tlon_ */






/* Subroutine */ int tlonps_(void)
{
    static integer j, k, l;







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/* .... TOOL END IS ON PS */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



    j = 3;
    k = 0;
    l = ifxcor_1.ips;


    isv_1.isftyp[l - 1] = j;
    if (isv_1.itlon[l - 1] == k) {
	goto L10;
    }
    isv_1.itlon[l - 1] = k;
    isv_1.jent[l - 1] = 1;
L10:
    return 0;
} /* tlonps_ */






/* Subroutine */ int tlofps_(void)
{
    static integer j, k, l;







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/* .... TOOL IS TANGENT TO PS */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



    j = 1;
    k = 1;
    l = ifxcor_1.ips;


    isv_1.isftyp[l - 1] = j;
    if (isv_1.itlon[l - 1] == k) {
	goto L10;
    }
    isv_1.itlon[l - 1] = k;
    isv_1.jent[l - 1] = 1;
L10:
    return 0;
} /* tlofps_ */

