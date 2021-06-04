/* SSDAT3.f -- translated by f2c (version 20100827).
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

struct rmflgs_1_ {
    logical lgchk, lintck, lavctl, lvaxis;
};

#define rmflgs_1 (*(struct rmflgs_1_ *) &rmflgs_)

struct tac_1_ {
    doublereal alpha, beta, cosa, cosb, sina, sinb;
    integer itac;
};

#define tac_1 (*(struct tac_1_ *) &tac_)

/* Initialized data */

struct {
    logical e_1[4];
    } rmflgs_ = { FALSE_, FALSE_, FALSE_, FALSE_ };

struct {
    doublereal e_1[6];
    integer e_2;
    } tac_ = { 0., 0., 1., 1., 0., 0., 0 };


/* *** SOURCE FILE : SSDAT3.ORG   *** */

/* Subroutine */ int ssdat3_(void)
{
    return 0;
} /* ssdat3_ */



/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */




/*     ALPHA  TOOL AXIS SLEW ANGLE WRT SN */
/*            IN GUIDE SURFACE CRSSPL DIRN. IF PATH IN TANSPL DIRN. */
/*            AND VICE VERSA */
/*     BETA   TOOL AXIS TILT ANGLE (CUTANG) WRT SN */
/*            IN PATH DIRECTION */
/*     COSA   COS(ALPHA) */
/*     COSB   COS(BETA) */
/*     SINA   SIN(ALPHA) */
/*     SINB   SIN(BETA) */
/*     ITAC   FLAG INDICATING THAT ATANGL TYPE TOOL AXIS CONTROL */
/*            IS REQUIRED =1, =0 FOR FIXED OR NORMDS */




