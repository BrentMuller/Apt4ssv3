/* BDPLGL.f -- translated by f2c (version 20100827).
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

struct plgol_1_ {
    integer iplgo[26], jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10], vta[3];
};

#define plgol_1 (*(struct plgol_1_ *) &plgol_)

/* Initialized data */

struct {
    integer e_1[48];
    doublereal e_2[53];
    } plgol_ = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0. };


/* *** SOURCE FILE : M0012242.V01   *** */

/* Subroutine */ int bdplgl_(void)
{
    return 0;
} /* bdplgl_ */


/*  INITIALISE COMMON FOR  >GOLOFT/PLOTFT< */


/*  VALUES FOR  >GOLOFT/PLOTFT< */

/*  USED CUTTER SEGMENT */

/*  NUMBER OF VALID CUTTER SEGMENTS */

/*  CUTTER SEGMENT IN TLLDAT ARRAYS */

/*  NATURE OF SEGMENT */

/*  COMPONENTS OF SEGMENT AND UNIT NORMAL POINTING INTO THE CUTTER */

/*  DISTANCE PARALLEL TO THE CUTTER AXIS */

/*  DISTANCE TO THE CUTTER AXIS */

/*  ELEMENT LENGTH */

/*  VECTOR-COMPONENTS OF THE TOOL-AXIS-VECTOR */




