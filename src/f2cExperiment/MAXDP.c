/* MAXDP.f -- translated by f2c (version 20100827).
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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

struct {
    doublereal saveh[50];
} hsave_;

#define hsave_1 hsave_

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0001137.V05   *** */



/* .....FORTRAN SUBROUTINES          MAXDP & MAXDPH            4/1/68   GK */


/* Subroutine */ int maxdp_(doublereal *dcml, doublereal *elngth)
{
    /* Initialized data */

    static doublereal z2 = 2.;
    static doublereal z3 = 3.;
    static doublereal z4 = 4.;
    static doublereal smal = 1e-12;
    static char ppword[8] = "MAXDP   ";

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer kk;
    extern integer bcdf_(char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt299_();
#define elngh ((doublereal *)&hsave_1 + 26)
#define elmax ((doublereal *)&addcom_1)
#define decmal ((doublereal *)&hsave_1 + 25)
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
    static integer ippwrd[2];





/* ...  21. ADDCOM BLOCK */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */









    *decmal = *dcml;
    *elngh = *elngth;
    if (hold_1.jhldfg == 0) {
	goto L1;
    }
/*             /-IF JHLDFG IS NOT ZERO, ARELEM IS SEARCHING FOR A CHECK */
/*             /-SURFACE.  INTERVENING COMMANDS NOT TO BE EXECUTED YET. */
    hold_1.itabh[hold_1.ithcnt - 1] = 10;
    ++hold_1.ithcnt;
    return 0;
L1:

/*             /-SPECIAL FLAG FOR SS ARELEM MODE AND DEBUGGING LEVEL PRIN */
/*             /-MAXDP/-K,L WHERE -K IS -2 OR LESS AND IBUG=L */
    if (*decmal > -z2) {
	goto L200;
    }
/*             /-SET SWITCH FOR SS SPECIAL ARELEM(ON FOR-2, OFF FOR -3) */
    if ((d__1 = *decmal + z2, abs(d__1)) < smal) {
	modess_1.mssarl = 1;
    }
    if ((d__1 = *decmal + z3, abs(d__1)) < smal) {
	modess_1.mssarl = 0;
    }
/*             /-SET VALUE OF IBUG FROM SECOND ARGUMENT IF DECMAL=-4 */
    if ((d__1 = *decmal + z4, abs(d__1)) < smal) {
	ibugg_1.ibug = (integer) (*elngh);
    }
/*             /-OMIT WRITING A MAXDP RECORD FOR THESE CASES */
    goto L100;

L200:
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + 4, (ftnlen)4);
/* ...  USE THIS MAXIMUM STEP IN ALL ARITHMETIC CALCULATIONS */
    if (*elngh <= 0.) {
	goto L30;
    } else {
	goto L10;
    }
L10:
    *elmax = *elngh;
    kk = 2;
L20:
    fxcor_1.dpmax = *decmal;
    goto L70;

L30:
    kk = 1;
    if (*decmal < 0.) {
	goto L50;
    } else if (*decmal == 0) {
	goto L40;
    } else {
	goto L20;
    }
L40:
    *jlin = 0;
    goto L70;

/* ...     THE COMMAND MAXDP/-1 IS NOT IMPLEMENTED */
L50:
    if ((d__1 = *decmal + 1.f) < 0.) {
	goto L60;
    } else if (d__1 == 0) {
	goto L70;
    } else {
	goto L40;
    }
L60:
    if (*decmal + 1.1f > 0.f) {
	*jlin = 1;
    }

L70:
    apt299_(&kk, ippwrd, &c__1, decmal);
    if (kk == 1) {
	goto L100;
    }
    apt299_(&c__1, elngh, &c__0, &c__0);

L100:
    return 0;
} /* maxdp_ */

#undef clngth
#undef ibtflg
#undef decmal
#undef elmax
#undef elngh
#undef sinl
#undef cosl
#undef jlin








/* .....FORTRAN SUBROUTINE            MAXDPH...               4/1/68   GK */

/* Subroutine */ int maxdph_(doublereal *dcml, doublereal *elngth)
{
    /* Initialized data */

    static char ppword[8] = "MAXDP   ";
    static doublereal z2 = 2.;
    static doublereal z3 = 3.;
    static doublereal z4 = 4.;
    static doublereal smal = 1e-12;

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer kk;
    extern integer bcdf_(char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt299_();
#define elngh ((doublereal *)&hsave_1 + 26)
#define elmax ((doublereal *)&addcom_1)
#define decmal ((doublereal *)&hsave_1 + 25)
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
    static integer ippwrd[2];




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* ...  21. ADDCOM BLOCK */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */










/*             /-SPECIAL FLAG FOR SS ARELEM MODE AND DEBUGGING LEVEL PRIN */
/*             /-MAXDP/-K,L WHERE -K IS -2 OR LESS AND IBUG=L */
    if (*decmal > -z2) {
	goto L200;
    }
/*             /-SET SWITCH FOR SS SPECIAL ARELEM(ON FOR-2, OFF FOR -3) */
    if ((d__1 = *decmal + z2, abs(d__1)) < smal) {
	modess_1.mssarl = 1;
    }
    if ((d__1 = *decmal + z3, abs(d__1)) < smal) {
	modess_1.mssarl = 0;
    }
/*             /-SET VALUE OF IBUG FROM SECOND ARGUMENT IF DECMAL=-4 */
    if ((d__1 = *decmal + z4, abs(d__1)) < smal) {
	ibugg_1.ibug = (integer) (*elngh);
    }
/*             /-OMIT WRITING A MAXDP RECORD FOR THESE CASES */
    goto L100;

L200:
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + 4, (ftnlen)4);
/* ...  USE THIS MAXIMUM STEP IN ALL ARITHMETIC CALCULATIONS */
    if (*elngh <= 0.) {
	goto L30;
    } else {
	goto L10;
    }
L10:
    *elmax = *elngh;
    kk = 2;
L20:
    fxcor_1.dpmax = *decmal;
    goto L70;

L30:
    kk = 1;
    if (*decmal < 0.) {
	goto L50;
    } else if (*decmal == 0) {
	goto L40;
    } else {
	goto L20;
    }
L40:
    *jlin = 0;
    goto L70;

/* ...     THE COMMAND MAXDP/-1 IS NOT IMPLEMENTED */
L50:
    if ((d__1 = *decmal + 1.f) < 0.) {
	goto L60;
    } else if (d__1 == 0) {
	goto L70;
    } else {
	goto L40;
    }
L60:
    if (*decmal + 1.1f > 0.f) {
	*jlin = 1;
    }

L70:
    apt299_(&kk, ippwrd, &c__1, decmal);
    if (kk == 1) {
	goto L100;
    }
    apt299_(&c__1, elngh, &c__0, &c__0);

L100:
    return 0;
} /* maxdph_ */

#undef clngth
#undef ibtflg
#undef decmal
#undef elmax
#undef elngh
#undef sinl
#undef cosl
#undef jlin


