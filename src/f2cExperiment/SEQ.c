/* SEQ.f -- translated by f2c (version 20100827).
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
    integer sqnc;
} sqnc_;

#define sqnc_1 sqnc_

/* *** SOURCE FILE : M0000962.V03   *** */

/* .....IMPLEMENTATION DEPENDENT SUBROUTINE ...SEQ           8/68      HG */
/* .....FORTRAN ROUTINE              ..SEQ..     HL GRAY 3/68         *ID* */
/* Subroutine */ int seq_(integer *n)
{
/*        THIS ROUTINE EXISTS ONLY BECAUSE     SQNC MAY ONLY APPEAR IN */
/*        A PROGRAM COMPILED IN EBCDIC. */
    sqnc_1.sqnc = *n;
    return 0;
} /* seq_ */

