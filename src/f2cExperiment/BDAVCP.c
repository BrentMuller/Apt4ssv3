/* BDAVCP.f -- translated by f2c (version 20100827).
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

struct avcprm_1_ {
    doublereal ctang, bmin, bmax, dmax__;
    logical latyp1, lanps, avlist;
};

#define avcprm_1 (*(struct avcprm_1_ *) &avcprm_)

/* Initialized data */

struct {
    doublereal e_1[4];
    logical e_2[3];
    } avcprm_ = { 0., 0., 0., 0., FALSE_, FALSE_, FALSE_ };


/* *** SOURCE FILE : BDAVCP.ORG   *** */

/* Subroutine */ int bdavcp_(void)
{
    return 0;
} /* bdavcp_ */


/*       INITIALIZATION OF AVOIDANCE CONTROL PARAMETERS */



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



