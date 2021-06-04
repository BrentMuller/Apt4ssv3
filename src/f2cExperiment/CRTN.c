/* CRTN.f -- translated by f2c (version 20100827).
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


/* Subroutine */ int crtn_(integer *cond)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);


/*  *  CRTN  *   TEMPORARY VAX11 VERSION   13.5.81    E.MCLELLAN */

    if (*cond == 0) {
	s_stop("PROCESSING COMPLETED OK", (ftnlen)23);
    } else if (*cond == 4) {
	s_stop("PROCESSING COMPLETED - WARNINGS HAVE OCCURRED", (ftnlen)45);
    } else {
	s_stop("ABNORMAL END - ERRORS HAVE OCCURRED", (ftnlen)35);
    }
    return 0;
} /* crtn_ */

