/* VDOTF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001127.V02   *** */

doublereal vdotf_(doublereal *b, doublereal *c__)
{
    /* System generated locals */
    doublereal ret_val;

    /* Parameter adjustments */
    --c__;
    --b;

    /* Function Body */
    ret_val = b[1] * c__[1] + b[2] * c__[2] + b[3] * c__[3];
    return ret_val;
} /* vdotf_ */

