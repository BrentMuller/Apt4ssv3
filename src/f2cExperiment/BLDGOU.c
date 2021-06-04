/* BLDGOU.f -- translated by f2c (version 20100827).
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

struct cgoug_1_ {
    doublereal talt[3], svgl, shilf, gflg, tpg[3], spg[3];
};

#define cgoug_1 (*(struct cgoug_1_ *) &cgoug_)

/* Initialized data */

struct {
    doublereal e_1[12];
    } cgoug_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. };


/* *** SOURCE FILE : BLDGOU.ORG   *** */


/* .... BLOCK DATA PROGRAM TO INITIALIZE COMMON/CGOUG/ */

/* Subroutine */ int bldgou_(void)
{
    return 0;
} /* bldgou_ */








