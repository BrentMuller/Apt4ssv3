/* PUT.f -- translated by f2c (version 20100827).
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
    integer ntb, fpb, ppb, comn;
} stor_;

#define stor_1 stor_

struct {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp;
} work_;

#define work_1 work_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

/* *** SOURCE FILE : M0000952.V04   *** */

/* .....FORTRAN SUBROUTINE  ....PUT            8/68                 HG */
/* .....FORTRAN FUNCTION             ..PUT..     HL GRAY 3/68         *ID* */
/* Subroutine */ int put_(doublereal *arg, integer *od)
{
    /* Local variables */
    static integer k, l;
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
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer xcanon_(integer *);


/* FORTRAN SUBROUTINE 'PUT (ARG, OD)'--PUT ARGUMENT INTO OPERAND */

/* PURPOSE      TO PUT THE VALUE OF AN ARGUMENT INTO THE PART PROGRAM */
/*              OPERAND, OD */

/* LINKAGE      CALL PUT(ARG, OD) */

/* ARGUMENTS    ARG    IS THE VALUE TO BE STORED */
/*              OD     IS THE ORDINAL NUMBER OF THE OPERAND */

/* METHOD       THE OPERAND CONSISTS OF THE ORDERED PAIR (TYPE, VALUE) */
/*              WHERE-- */

/*              TYPE     VALUE */
/*               0        INDEX TO NAME TABLE WHICH CONTAINS POINTER */
/*                        TO STORAGE FOR VARIABLE */
/*               1,2      ERROR CONDITION */
/*               3        INDEX TO NAME TABLE */
/*              -N        INDEX TO NAME TABLE WHICH CONTAINS BASE ADDR. */

/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* STOR--COMMON CONTAINING STORAGE PARAMETERS */


/*     ------------------- */



/* WORK--COMMON CONTAINING WORKING VARIABLES */






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/* --------------------------------------------------------------------- */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*        EXTRACT TYPE AND ADD ONE FOR 'GO TO' (L) */

    k = work_1.ilc + *od;
    l = pp[k - 1] + 1;

/*        EXTRACT VALUE OF OPERAND (K) */

    k = pp[k];

/*        PUT OPERAND ACCORDING TO TYPE */

    if (l <= 0) {
	goto L50;
    }


/*        COMPUTE NAME TABLE POINTER, STORE ARG AND EXIT */

/* L10: */
    work_1.ntp = stor_1.ntb + k;
    k = nt[(work_1.ntp << 1) - 2];
    if (ldef_1.canflg) {
	k = xcanon_(&k);
    }
    cf[k - 1] = *arg;
    return 0;


/*        TYPE -N */

/*        COMPUTE EFFECTIVE ADDRESS = BASE ADDRESS + INDEX, */
/*        STORE ARGUMENT AND EXIT */

L50:
    work_1.ntp = stor_1.ntb + k;
    k = nt[(work_1.ntp << 1) - 2] - l;
    if (ldef_1.canflg) {
	k = xcanon_(&k);
    }
    ia[k - 1] = *arg;
    return 0;

} /* put_ */

#undef bcanon
#undef sscan
#undef canon
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


