/* LIB.f -- translated by f2c (version 20100827).
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
    integer ntb, fpb, ppb, comn, cfb, nblk, nrecrd[10], ntparm[10];
} stor_;

#define stor_1 stor_

struct {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp;
    real xxx[1];
    integer avt[32], iwrit;
} work_;

#define work_1 work_

struct {
    integer ktempb, kcomf;
} const_;

#define const_1 const_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer sqno;
} sqnc_;

#define sqnc_1 sqnc_

/* Table of constant values */

static integer c__1 = 1;
static integer c__41 = 41;
static integer c__42 = 42;
static integer c__4 = 4;

/* *** SOURCE FILE : M0002658.W03   *** */

/* .....FORTRAN SUBROUTINE  ....LIB            8/68                 HG */
/* .....FORTRAN ROUTINE              ..LIB..     HL GRAY 3/68         *ID* */
/* Subroutine */ int lib_(void)
{
    /* Initialized data */

    static integer term = -999;
    static integer ispecl = 319951634;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, m, n;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
    static integer kk;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer iii;
#define fpp ((integer *)&work_1 + 10)
    extern /* Subroutine */ int help_(void);
#define ipage ((integer *)&stor_1 + 20)
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int xcall_(integer *), cform_(char *, char *, 
	    integer *, integer *, ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer jtemp;
#define numod ((integer *)&stor_1 + 17)
    static integer ipntr;
#define ndaflg ((integer *)&stor_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer ptable[50];
    extern integer xcanon_(integer *);
#define nrecst ((integer *)&stor_1 + 19)
    extern /* Subroutine */ int cprint_(char *, ftnlen);
#define numbst ((integer *)&stor_1 + 16)
    static integer kztemp;
    extern /* Subroutine */ int xnumbr_(integer *);

/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* STOR--COMMON CONTAINING STORAGE PARAMETERS */


/*     ------------------- */


/*   ADDITIONAL STOR PARAMETERS USED FOR NUMBER TABLE DIRECT ACCESS */



/* WORK--COMMON CONTAINING WORKING VARIABLES */






/* CONST--COMMON CONTAINING CONSTANTS */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* --------------------------------------------------------------------- */

    n = pp[(0 + (0 + (work_1.ilc + 1 - 1 << 2))) / 4];
    k = 1;
    kk = work_1.iwrit;
    jtemp = const_1.ktempb;

/* .....ENTER MODE OF SUBROUTINE TO BE CALLED,INTO PARM. TABLE */
    if (pp[work_1.ilc + 1] < 1000) {
	goto L80;
    }
    work_1.ntp = pp[work_1.ilc + 1] - 1000 + stor_1.ntb;
    ptable[0] = -nt[(work_1.ntp << 1) - 2];
    goto L90;
L80:
    ptable[0] = -pp[work_1.ilc + 1];

/* .....IF NO PARAMETERS, TERMINATE. */
L90:
    if (n == 1) {
	goto L20;
    }


/* .....GENERATE INDEX TO COM FOR EACH PARAMETER.  PARAMETERS CONSIST OF */
/*     TWO PARTS(TYPE AND A POINTER). */
    n = work_1.ilc + n + 1;
    iii = work_1.ilc + 3;
    i__ = iii;
    i__1 = n;
    for (m = iii; m <= i__1; m += 2) {
	j = pp[i__ - 1] + 1;

/* .....CHECK PARM. TYPE. */
	if (j <= 0) {
	    goto L160;
	}
	switch (j) {
	    case 1:  goto L100;
	    case 2:  goto L110;
	    case 3:  goto L120;
	    case 4:  goto L130;
	    case 5:  goto L140;
	    case 6:  goto L150;
	    case 7:  goto L180;
	    case 8:  goto L190;
	}

/* .....  TYPE 0,3  NAME TABLE HOLDS INDEX TO COM FOR PARAMETER */
L130:
	work_1.ntp = stor_1.ntb + pp[i__];
	if (nt[(work_1.ntp << 1) - 1] != ispecl) {
	    goto L131;
	}
/* ---    INDIRECT REFERENCE IS TO A LITERAL NUMBER, MODIFY */
/* ---    NUMBER TABLE INDEX BY PAGING IF NECESSARY */
	kztemp = nt[(work_1.ntp << 1) - 2];
	if (*ndaflg != 0) {
	    xnumbr_(&kztemp);
	}
	work_1.comp = stor_1.fpb + kztemp;
	goto L165;
L131:
	work_1.comp = nt[(work_1.ntp << 1) - 2];
	goto L165;
L100:
	work_1.ntp = stor_1.ntb + pp[i__];
	work_1.comp = nt[(work_1.ntp << 1) - 2];
	goto L165;

/* .....TYPE 1 - FLOATING POINT NUMBERS STORED IN NUMBER TABLE */
/* .....STORE EACH VALUE IN TEMPORARY UNTIL THIS CALL IS COMPLETED */
L110:
	ipntr = pp[i__];
	if (*ndaflg != 0) {
	    xnumbr_(&ipntr);
	}
	ipntr = stor_1.ntb + ipntr;
	_BLNK__1.com[jtemp - 1] = _BLNK__1.com[ipntr - 1];
	goto L155;
/* .....TYPE 2 - NAMETABLE HAS ACTUAL VALUE. CALCULATE INDEX TO COM. */
L120:
	work_1.comp = stor_1.ntb + pp[i__];
	goto L170;

/* .....TYPE 4 PARM. IS THE MODE NO. OF A ROUTINE */
L140:
	work_1.comp = -pp[i__];
	goto L170;

/* .....TYPE 5, PARM IS AN INTEGER LITERAL. */
L150:
	cm[(jtemp << 1) - 2] = pp[i__];
L155:
	work_1.comp = jtemp;
	++jtemp;
	if (jtemp <= const_1.ktempb + 16) {
	    goto L170;
	}
	goto L25;

/* .....TYPE 6, PARM IS AN UNFRACTIONAL NUMBER */
L180:
	_BLNK__1.com[jtemp - 1] = (doublereal) pp[i__];
	goto L155;

/* .....TYPE 7, PARM IS A FRACTIONAL NUMBER */
L190:
	cm[(jtemp << 1) - 2] = pp[i__];
	cm[(jtemp << 1) - 1] = pp[i__ + 1];
	++i__;
	goto L155;

/* .....NAMETABLE CONTAINS INDEX TO INTERNAL ARRAY.  J POINTS TO ELEMENT */
/*     OF THAT ARRAY */
L160:
	work_1.ntp = stor_1.ntb + pp[i__];
	work_1.comp = nt[(work_1.ntp << 1) - 2] - j;
L165:
	if (ldef_1.canflg) {
	    work_1.comp = xcanon_(&work_1.comp);
	}
L170:
	++k;

/* .....FILL PARAMETER TABLE. */
	ptable[k - 1] = work_1.comp;
	i__ += 2;
/* L10: */
    }


/*        ARE MORE BLOCKS OF CANNON REQUIRED THAN SPACE ALLOWS */
L20:
    if (work_1.iwrit - kk < stor_1.nblk || ! ldef_1.canflg) {
	goto L30;
    }
L25:
    cform_("029006 SYSTEM ERR-ILLEGAL I.L. CALL. ISN= ", darray_1.darray, &
	    c__1, &c__41, (ftnlen)42, (ftnlen)120);
    iconv_(&sqnc_1.sqno, darray_1.darray, &c__42, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    help_();
/* ..... TERMINATE PARM.  TABLE */
L30:
    ptable[k] = term;

/* .....CALL ROUTINE WHICH CHANGES INDICES TO ADDRESSES AND PREFORMS THE */
/*     ACTUAL CALL TO SUBROUTINE INDICATED BY THE I.L.. */
    xcall_(ptable);
    return 0;
} /* lib_ */

#undef numbst
#undef nrecst
#undef bcanon
#undef ndaflg
#undef numod
#undef sscan
#undef canon
#undef ipage
#undef fpp
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


