/* BDGLFL.f -- translated by f2c (version 20100827).
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

struct glflgs_1_ {
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
};

#define glflgs_1 (*(struct glflgs_1_ *) &glflgs_)

/* Initialized data */

struct {
    integer e_1;
    logical e_2;
    integer e_3[2];
    } glflgs_ = { 0, FALSE_, 0, 0 };


/* *** SOURCE FILE : BDGLFL.ORG   *** */

/* Subroutine */ int bdglfl_(void)
{
    return 0;
} /* bdglfl_ */


/* .... INITIALIZE COMMON/GLFLGS/ */



/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */


