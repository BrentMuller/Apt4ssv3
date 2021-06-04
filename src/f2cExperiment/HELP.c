/* HELP.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000449.ORG   *** */

/* .....COMPUTER DEPENDENT ROUTINE      HELP.......HL GRAY    12/67  *CD* */

/* PURPOSE      TO PROVIDE A TRACE-BACK IN THE CASE OF A */
/*              CASTASTROPHIC FAILURE. */

/* LINKAGE      CALL HELP */

/* ARGUMENTS    NONE */

/* NOTES        THE METHOD USED TO OBTAIN THE TRACE-BACK */
/*              MIGHT NEED TO BE CHANGED ON SOME COMPUTERS. */

/* SUBSIDIARIES NONE */

/* Subroutine */ int help_(void)
{
    static integer i__;
    static real x, y[1];


/* ...     CATASTROPHIC FAILURE */
/* ...     PRODUCE EXECUTION FAILURE SO AS TO OBTAIN AUTOMATIC TRACE-BACK */

    for (i__ = 100000; i__ <= 1000000; i__ += 10) {
	x = y[i__ - 1];
/* L10: */
	y[i__ - 1] = x;
    }
/* L1: */
    return 0;
} /* help_ */

