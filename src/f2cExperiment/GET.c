/* GET.f -- translated by f2c (version 20100827).
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
} work_;

#define work_1 work_

struct {
    integer kcomt, kcomf;
} const_;

#define const_1 const_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ild;
} ild_;

#define ild_1 ild_

/* *** SOURCE FILE : M0000717.W02   *** */

/* .....FORTRAN SUBROUTINE  ....GET            8/68                 HG */
/* .....FORTRAN FUNCTION             ..GET..     HL GRAY 3/68         *ID* */
doublereal get_(integer *od)
{
    /* Initialized data */

    static integer ispecl = 319951634;

    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, l;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
#define fpp ((integer *)&work_1 + 10)
#define ipage ((integer *)&stor_1 + 20)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define numod ((integer *)&stor_1 + 17)
#define ndaflg ((integer *)&stor_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer xcanon_(integer *);
#define nrecst ((integer *)&stor_1 + 19)
#define numbst ((integer *)&stor_1 + 16)
    extern /* Subroutine */ int xnumbr_(integer *);


/* FORTRAN FUNCTION 'GET(OD)'--GET ARGUMENT FROM OPERAND, OD */

/* PURPOSE      TO GET THE VALUE OF AN ARGUMENT GIVEN THE */
/*              INTERMEDIATE LANGUAGE OPERAND POINTER, OD. */

/* LINKAGE      GET(OD) */

/*              WHERE */
/*              OD IS THE POINTER TO THE OPERAND IN THE PART */
/*                 PROGRAM */

/* METHOD       THE OPERAND IS EVALUATED ACCORDING TO TYPE */
/*              (SEE INTRODUCTORY DOCUMENTATION).  THE VALUE */
/*              OF THE ARGUMENT IS THEN TAKEN FROM THE APPRO- */
/*              PRIATE LOCATION. */

/*              TYPE     VALUE */
/*               0        INDEX TO NAME TABLE WHICH CONTAINS POINTER */
/*                        TO STORED VARIABLE */
/*               1        INDEX TO FLOATING POINT NUMBER TABLE */
/*               2        INDEX TO ALPHANUMERIC CONSTANTS */
/*               3        INDEX TO NAME TABLE(POINTS TO VARIABLE) */
/*               4        PROCEDURE NUMBER */
/*               5        INTEGER */
/*               6        UNFRACTIONAL NUMBER (I4-FORMAT) */
/*               7        FRACTIONAL NUMBER   (R8-FORMAT) */
/*              -N        INDEX TO NAME TABLE WHICH CONTAINS POINTER */
/*                        TO BASE ADDRESS.  EFFECTIVE ADDRESS IS-- */

/*                           BA + N-1 */

/*                        AND ALWAYS REFERS TO INTERNAL ARRAYS */

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




/* --------------------------------------------------------------------- */





/*        EXTRACT TYPE AND ADD ONE FOR 'GO TO' (L) */

    j = work_1.ilc + ild_1.ild + *od;
    l = pp[j - 1] + 1;

/*        EXTRACT VALUE OF OPERAND (K) */

    k = pp[j];

/*        GET OPERAND ACCORDING TO TYPE */

    if (l <= 0) {
	goto L70;
    }

/*             0   1   2   3   4   5   6   7  TYPE */

    switch (l) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L10;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L60;
	case 8:  goto L80;
    }





/*        TYPE 0.,3. */

/*        GET NAME TABLE POINTER */

L10:
    work_1.ntp = stor_1.ntb + k;
    k = nt[(work_1.ntp << 1) - 2];
/* ---     SPECIAL LOGIC FOR INDIRECT ADRS AND NUMBER REFERENCE */
    if (l != 4) {
	goto L11;
    }
    if (nt[(work_1.ntp << 1) - 1] != ispecl) {
	goto L11;
    }
/* ---     INVOKE NUMBER TABLE PAGE AN ADDRESS REASSIGNMENT, IF NECESSARY */
    if (*ndaflg != 0) {
	xnumbr_(&k);
    }
    work_1.comp = stor_1.fpb + k;
    ret_val = fp[work_1.comp - 1];
    return ret_val;
/* ---     NORMAL PATH FOR FETCHING CAN FORM OR NUMBER */
L11:
    work_1.comp = k;
    goto L100;




/*        TYPE 1. */

/*        COMPUTE FLOATING TABLE POINTER, EXTRACT VARIABLE AND EXIT */

L20:
    if (*ndaflg != 0) {
	xnumbr_(&k);
    }
    work_1.comp = stor_1.fpb + k;
    ret_val = fp[work_1.comp - 1];
    return ret_val;




/*        TYPE 2. */

/*        COMPUTE NAME TABLE POINTER, EXTRACT VARIABLE AND EXIT */

L30:
    work_1.comp = stor_1.ntb + k;
    ret_val = nb[work_1.comp - 1];
    return ret_val;




/*        TYPE 4. */



L50:
    work_1.comp = k;
    ret_val = 0.f;
    return ret_val;




/*        TYPE 5 AND TYPE 6. */

L60:
    work_1.comp = const_1.kcomt;
    _BLNK__1.com[work_1.comp - 1] = (doublereal) k;
    ret_val = _BLNK__1.com[work_1.comp - 1];
    return ret_val;

/*        TYPE 7. */
/*     RECEIVE FRACTIONAL NUMBER FROM INPUT FILE */

L80:
    work_1.comp = const_1.kcomt;
    cm[(work_1.comp << 1) - 2] = pp[j];
    cm[(work_1.comp << 1) - 1] = pp[j + 1];
    ++ild_1.ild;
    ret_val = _BLNK__1.com[work_1.comp - 1];
    return ret_val;



/*        TYPE (-N) */


/*        COMPUTE EFFECTIVE ADDRESS = BASE ADDRESS + INDEX, */
/*        STORE ARGUMENT AND EXIT */
L70:
    work_1.ntp = stor_1.ntb + k;
    work_1.comp = nt[(work_1.ntp << 1) - 2] - l;
L100:
    i__ = work_1.comp;
    if (ldef_1.canflg) {
	i__ = xcanon_(&i__);
    }
    ret_val = _BLNK__1.com[i__ - 1];

/* L110: */
    return ret_val;
} /* get_ */

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


