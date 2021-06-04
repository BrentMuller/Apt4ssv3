/* RESRV.f -- translated by f2c (version 20100827).
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
    integer ntb, fpb, ppb, comn, cfb;
} stor_;

#define stor_1 stor_

struct {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp;
} work_;

#define work_1 work_

struct {
    integer kcomt, kcomf;
    real cilprt;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

/* *** SOURCE FILE : M0000959.W01   *** */

/* .....FORTRAN SUBROUTINE  ....RESRV          8/68                 HG */
/* .....FORTRAN ROUTINE              ..RESRV..   HL GRAY 3/68         *ID* */
/* Subroutine */ int resrv_(void)
{
    /* Initialized data */

    static integer r__[4] = { 128,128,128,128 };
    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_7 = { 0, 0, 0. };


    /* Local variables */
    static integer k, m, n;
#define p ((integer *)&work_1 + 4)
    static integer p0, p1, r0, r1;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
    static integer md;
#define fp ((doublereal *)&_BLNK__1)
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define rr ((integer *)&equiv_7)
#define rr1 ((doublereal *)&equiv_7)
#define can ((doublereal *)&_BLNK__1 + 40)
#define fpp ((integer *)&work_1 + 10)
    static integer siz;
    extern integer bcdf_(char *, ftnlen);
    static integer mode;
    static doublereal ndex;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int trash_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer xcanon_(integer *);


/* FORTRAN SUBROUTINE 'RESRV'--PROCESS INTERMEDIATE LANGUAGE RESRV */
/*              INSTRUCTION */

/* PURPOSE      TO ESTABLISH STORAGE FOR CANONICAL FORMS AND BLANK COMMON */
/*              TO PLACE POINTERS IN NAME TABLE */

/* LINKAGE      CALL RESRV */

/* ARGUMENTS    THROUGH COMMON */

/* METHOD       ALL ELEMENTS ARE STORED IN THE CANONICAL FORMS ARRAY   OR */
/*              BLANK COMMON.  SEPERATE POINTERS ARE MAINTAINED FOR--- */

/*                   SCALARS */
/*                   SCALAR ARRAYS */
/*                   NONSCALARS */
/*                   INTERNAL ARRAYS */
/*                   BLANK COMMON */

/*              MODE AND NUMBER ARE EXAMINED TO DETERMINE WHICH */
/*              TYPE OF PROCESSING IS REQUIRED. */

/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* STOR--COMMON CONTAINING STORAGE PARAMETERS */


/*     ------------------- */



/* WORK--COMMON CONTAINING WORKING VARIABLES */






/* CONST--COMMON CONTAINING CONSTANTS */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/* --------------------------------------------------------------------- */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





    n = pp[(0 + (0 + (work_1.ilc + 5 - 1 << 2))) / 4];

    siz = pp[work_1.ilc + 3] + 1;
    mode = pp[work_1.ilc + 2];
    md = mode;
    if (mode == 23) {
	mode = 21;
    }
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
/*        IF MODE IS ZERO, PROCESS AS AN INTERNAL ARRAY */
    if (mode != 0) {
	goto L5;
    }
    m = 4;
    --siz;
/*        IF MODE .GT. 0 AND .NE. 21, PROCESS AS NON-SCALAR */
L5:
    if (mode > 0 && mode != 21) {
	m = 3;
    }
/*        IF MODE .LT. 0, PROCESS AS BLANK COMMON */
    if (mode < 0) {
	goto L50;
    }
/*        IF MODE IS 21, PROCESS AS A NON- OR SUB- SCRIPTED SCALAR */
    if (mode == 21 && n > 1) {
	m = 2;
    }
    if (mode != 21 || n != 1) {
	goto L7;
    }
    m = 1;
    --siz;
/*        CALCULATE INDEX AND REMAINING SPACE IN BLOCK(R0). */
L7:
    ndex = (doublereal) ((md * 100 + siz - 1) * 10000);
    if (n == 1) {
	ndex += -1.f;
    }
    r0 = r__[m - 1];
    r1 = 0;
/*  OBTAIN CURRENT VERTUAL(P0) AND ACTUAL(P1) POINTERS TO BLOCK M. */
    p0 = p[m - 1];
    p1 = p0;
    if (! ldef_1.canflg) {
	goto L30;
    }
L10:
    p0 += r1;
/*        WILL CANNONICAL FORM FIT IN BLOCK */
    if (r0 - siz * n >= 2 - m / 4) {
	goto L25;
    }
/*        NO,SPLIT IF INDEXED */
/*        HOW MANY ELEMENTS OF ARRAY FIT */
    k = (r0 - 1) / siz;
/*        ENTIRE CANNONICAL FORM CAN NOT FIT */
    if (k == n) {
	--k;
    }
/*        IF NO ELEMENTS FIT, BEGIN NEW BLOCK */
    if (k != 0) {
	goto L15;
    }
    p0 += r0;
    r0 = const_1.kcbn;
    goto L10;
/*        DETERMINE SPACE NOT OCCUPIED */
L15:
    r1 = r0 - k * siz - 1;
/*        DETERMINE REMAINING SPACE WHICH CAN BE OCCUPPIED */
    r0 -= r1;
    p1 = xcanon_(&p0);
/*        FLAG SPACE THAT IS NOT OCCUPIED */
/* L20: */
    rr[0] = r1;
    rr[1] = (p0 - stor_1.cfb) / const_1.kcbn + 1 + bcdf_("BK", (ftnlen)2);
    cf[p1 - 1] = *rr1;
/*        ADVANCE POINTER */
    p0 += r1;
L25:
    p1 = xcanon_(&p0);
/*        INITIALIZE CANNONICAL FORM */
L30:
    switch (m) {
	case 1:  goto L31;
	case 2:  goto L32;
	case 3:  goto L33;
	case 4:  goto L34;
    }
/*        NON-SUBSCRIPTED SCALAR */
L31:
    trash_(&cf[p1 - 1]);
    goto L34;
/*        SUBSCRIPTED SCALAR */
L32:
    trash_(&cf[p1 - 1]);
    cf[p1] = (doublereal) n;
    goto L34;
/*        NON-SCALAR */
L33:
    cf[p1 - 1] = ndex + n;
    trash_(&cf[p1]);
/*        INTERNAL ARRAY REQUIRES NO INITIALIZATION */
L34:
    p1 += siz;
    p0 += siz;
    r0 -= siz;
    --n;
/*        IF NOT ENOUGH SPACE OR NO MORE FORMS OR NOT */
/*        ENOUGH SPACE FOR LAST FORM, START NEW BLOCK */
    if (ldef_1.canflg) {
	goto L38;
    }
    if (n >= 1) {
	goto L30;
    }
    goto L40;
L38:
    if (r0 - siz >= 1 && n > 1) {
	goto L30;
    }
    if (r0 - siz >= 2 - m / 4 && n == 1) {
	goto L30;
    }
/*        SAVE SPACE COUNT, INDICATE NEW BLOCK */
    r1 = r0;
    r0 = const_1.kcbn;
    rr[0] = r1;
    rr[1] = (p0 - stor_1.cfb) / const_1.kcbn + 1 + bcdf_("BK", (ftnlen)2);
    cf[p1 - 1] = *rr1;
/*        STILL MORE FORMS */
    if (n >= 1) {
	goto L10;
    }
/*        NO, STORE NAME IF REQUIRED */
L40:
    switch (m) {
	case 1:  goto L41;
	case 2:  goto L41;
	case 3:  goto L41;
	case 4:  goto L42;
    }
L41:
    cf[p1 - 1] = nb[work_1.ntp - 1];
    ++p1;
    ++p0;
    --r1;

L42:
    if (! ldef_1.canflg) {
	goto L43;
    }
    rr[0] = r1;
    rr[1] = (p0 - stor_1.cfb) / const_1.kcbn + 1 + bcdf_("BK", (ftnlen)2);
    cf[p1 - 1] = *rr1;
L43:
    p[m - 1] = p0;
    r__[m - 1] = r1;
/*         STORE POINTER TO FORM(S) */
    if (m <= 2) {
	++siz;
    }
/* L45: */
    nt[(work_1.ntp << 1) - 2] = p0 - siz;
    return 0;

/*        BLANK COMMON */

L50:
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
    nt[(work_1.ntp << 1) - 2] = work_1.comp;
    work_1.comp += pp[work_1.ilc + 4];
    return 0;
} /* resrv_ */

#undef bcanon
#undef sscan
#undef canon
#undef fpp
#undef can
#undef rr1
#undef rr
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf
#undef p


