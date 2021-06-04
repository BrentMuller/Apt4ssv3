/* KREUZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0008177.V01   *** */

/* Subroutine */ int kreuz_(doublereal *v1, doublereal *v2, doublereal *v3)
{

/*   COMPUTATION OF VECTOR CROSS PRODUCT */


    /* Parameter adjustments */
    --v3;
    --v2;
    --v1;

    /* Function Body */
    v3[1] = v1[2] * v2[3] - v1[3] * v2[2];
    v3[2] = v1[3] * v2[1] - v1[1] * v2[3];
    v3[3] = v1[1] * v2[2] - v1[2] * v2[1];

    return 0;
} /* kreuz_ */

