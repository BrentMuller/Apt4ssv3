/* DISPAT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : DISPAT00.ORG   *** */

/* Subroutine */ int dispat_(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);


/*  * DISPAT *  VAX 11 FORTRAN 77 VERSION  20.09.82  E.MCLELLAN */

/*  PURPOSE     TO TERMINATE A POSTPROCESSOR */

    s_stop(" CURRENT POSTPROCESSOR COMPLETE", (ftnlen)31);
    return 0;
} /* dispat_ */

