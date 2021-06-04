/* AVCTRL.f -- translated by f2c (version 20100827).
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
    logical lgchk, lintck, lavctl, lvaxis;
} rmflgs_;

#define rmflgs_1 rmflgs_

struct {
    doublereal ctang, bmin, bmax, dmax__;
    logical latyp1, lanps, avlist;
} avcprm_;

#define avcprm_1 avcprm_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : AVCTRL.ORG   *** */

/* Subroutine */ int avctrl_(doublereal *donoff, doublereal *davtp1, 
	doublereal *g, doublereal *bmn, doublereal *bmx, doublereal *davtp2, 
	doublereal *dmx)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int bad_();
    static char msg[30];
    static integer nwd;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static char onoff[6], avtyp1[6], avtyp2[6];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), cprint_(char *, ftnlen);


/*     PURPOSE: TO PROCESS THE AVCTRL STATEMENT */
/*              SET FLAGS AND STORE PARAMETERS */

/*     ARGUMENTS: */
/*               DONOFF   D.P.   ON OR OFF */
/*                               INVOKES OR CANCELS AVOIDANCE CONTROL */
/*               DAVTP1   D.P.   TYPE1 AVOIDANCE CONTROL */
/*                               (MODIFICATION OF TOOL AXIS) */
/*                                 CUTANG - MODIFY PITCH ANGLE */
/*                                 NULL   - NO MODIFICATION OF TOOL AXIS */
/*               G        D.P.   CONSTANT TECHNOLOGICAL ANGLE (DEGREES) */
/*               BMN      D.P.   MINIMUM PITCH ANGLE (DEGREES) */
/*               BMX      D.P.   MAXIMUM PITCH ANGLE (DEGREES) */
/*               DAVTP2   D.P.   TYPE2 AVOIDANCE CONTROL (LIFT OFF) */
/*                                 NORMPS - LIFT OFF NORMAL TO PS */
/*                                 AXIS   - LIFT OFF PARLLEL TO TOOL AXIS */
/*                                 NULL   - NONE SPECIFIED (AXIS ASSUMED) */
/*               DMX      D.P.   MAXIMUM LIFT OFF DISTANCE */

/*     LOCAL VARIABLES: */

/*               ONOFF    C*6    CHARACTER VERSION OF DONOFF */
/*               AVTYP1   C*6        "        "    "  DAVTP1 */
/*               AVTYP2   C*6        "        "    "  DAVTP2 */
/*               NWD      I      NO OF INTEGER WORDS OCCUPIED BY */
/*                               ENCODED CHARACTER STRING */
/*               MSG      C*30   DEBUG PRINT MESSAGE */



/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */


/*       AVOIDANCE CONTROL PARAMETERS */



/*     CTANG    CONSTANT TECHNOLOGICAL ANGLE */
/*     BMIN     MINIMUM PITCH ANGLE */
/*     BMAX     MAXIMUM PITCH ANGLE */
/*     DMAX     MAXIMUM LINEAR LIFT OFF */
/*     LATYP1   FLAG INDICATING IF TYPE1 (TILT) AVOIDANCE REQUIRED */
/*     LANPS    FLAG INDICATING TYPE OF LINEAR LIFT OFF */
/*              .TRUE.  - LIFT OFF NORMAL TO PS */
/*              .FALSE. - LIFT OFF PARALLEL TO TOOL AXIS */
/*     AVLIST   FLAG INDICATING THAT AVOIDANCE DETAILS ARE TO BE PRINTED */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */






/* .... DEBUG FLAGS */


    holfrm_(donoff, onoff, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(davtp1, avtyp1, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(davtp2, avtyp2, &c__1, &c__6, &nwd, (ftnlen)6);

/* .... SET AVOIDANCE CONTROL FLAG */

    if (s_cmp(onoff, "ON", (ftnlen)6, (ftnlen)2) == 0) {
	rmflgs_1.lavctl = TRUE_;
    } else {
	rmflgs_1.lavctl = FALSE_;
    }

/* .... STORE PARAMETERS */

    if (s_cmp(avtyp1, "NULL", (ftnlen)6, (ftnlen)4) == 0 && s_cmp(avtyp2, 
	    "NULL", (ftnlen)6, (ftnlen)4) == 0) {

/* .... DO NOT ALTER PARAMETERS SINCE AVCTRL/ON OR AVCTRL/OFF */

    } else {

/* .... TYPE 1 AVOIDANCE CONTROL */

	if (s_cmp(avtyp1, "CUTANG", (ftnlen)6, (ftnlen)6) == 0) {
	    avcprm_1.latyp1 = TRUE_;
/* .... CONVERT ANGLES TO RADIANS BEFORE STORING */
	    avcprm_1.ctang = *g * znumbr_1.degrad;
	    avcprm_1.bmin = *bmn * znumbr_1.degrad;
	    avcprm_1.bmax = *bmx * znumbr_1.degrad;
	} else {
	    avcprm_1.latyp1 = FALSE_;
	    avcprm_1.ctang = znumbr_1.z0;
	    avcprm_1.bmin = znumbr_1.z0;
	    avcprm_1.bmax = znumbr_1.z0;
	}

/* .... TYPE 2 AVOIDANCE CONTROL */

	if (s_cmp(avtyp2, "NORMPS", (ftnlen)6, (ftnlen)6) == 0) {
	    avcprm_1.lanps = TRUE_;
	} else {
	    avcprm_1.lanps = FALSE_;
	}

/* .... LIFT OFF LIMIT */

	if ((d__1 = *dmx - znumbr_1.z0, abs(d__1)) < znumbr_1.z1em6) {
/* .... NO LIMIT SPECIFIED - TAKE DPMAX AS DEFAULT */
	    avcprm_1.dmax__ = fxcor_1.dpmax;
	} else {
	    avcprm_1.dmax__ = *dmx;
	}
    }

/* .... DEBUG PRINT */

    if (ibugg_1.ibug == 11) {
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(msg, "0 AVOIDANCE CONTROL PARAMETERS", (ftnlen)30, (ftnlen)30);
	cprint_(msg, (ftnlen)30);
	bad_(&c__1, &c__1, "CANG", &avcprm_1.ctang, (ftnlen)4);
	bad_(&c__1, &c__1, "BMIN", &avcprm_1.bmin, (ftnlen)4);
	bad_(&c__1, &c__1, "BMAX", &avcprm_1.bmax, (ftnlen)4);
	bad_(&c_n1, &c__1, "DMAX", &avcprm_1.dmax__, (ftnlen)4);
	bad_(&c__1, &c__0, "LTYP", &avcprm_1.latyp1, (ftnlen)4);
	bad_(&c__1, &c__0, "LNPS", &avcprm_1.lanps, (ftnlen)4);
	bad_(&c_n1, &c__0, "ALST", &avcprm_1.avlist, (ftnlen)4);
    }

    return 0;
} /* avctrl_ */

#undef sinl
#undef cosl


