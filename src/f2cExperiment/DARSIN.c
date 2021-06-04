/* DARSIN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : DARSIN00.ORG   *** */

doublereal darsin_(doublereal *x)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double asin(doublereal);

/* DOUBLE PRECISION ARC SINE FUNCTION USING STANDARD FUNCTION */


    ret_val = asin(*x);
    return ret_val;
} /* darsin_ */




doublereal darcos_(doublereal *x)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double acos(doublereal);

/* DOUBLE PRECISION ARC COS FUNCTION USING STANDARD FUNCTION */


    ret_val = acos(*x);
    return ret_val;
} /* darcos_ */




doublereal dcotan_(doublereal *x)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double tan(doublereal);

    /* Local variables */
    static doublereal t;

/* DOUBLE PECISION COTANGENT USING DTAN FUNCTION */


    t = tan(*x);
    if (t != 0.f) {
	goto L10;
    }
    ret_val = 1e38;
    return ret_val;
L10:
    ret_val = 1.f / t;
    return ret_val;
} /* dcotan_ */

