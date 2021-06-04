/* TTORUS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : TTORUS.ORG   *** */

/* Subroutine */ int ttorus_(doublereal *trm, doublereal *data)
{
    static doublereal a[3];
    static integer i__;


/* .... TRANSFORMATOR FOR NON-NATIVE TORUS */


/* .... AXIS, CENTER AND REF AXIS FOR TORUS REQUIRE ROTATION */

    /* Parameter adjustments */
    --data;
    trm -= 5;

    /* Function Body */
    for (i__ = 1; i__ <= 7; i__ += 3) {
	a[0] = trm[5] * data[i__] + trm[6] * data[i__ + 1] + trm[7] * data[
		i__ + 2];
	a[1] = trm[9] * data[i__] + trm[10] * data[i__ + 1] + trm[11] * data[
		i__ + 2];
	a[2] = trm[13] * data[i__] + trm[14] * data[i__ + 1] + trm[15] * data[
		i__ + 2];
	data[i__] = a[0];
	data[i__ + 1] = a[1];
	data[i__ + 2] = a[2];
/* L10: */
    }

/* .... CENTER ALSO NEEDS TRANSLATION */

    data[4] += trm[8];
    data[5] += trm[12];
    data[6] += trm[16];

    return 0;
} /* ttorus_ */

