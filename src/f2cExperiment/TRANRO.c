/* TRANRO.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000978.V01   *** */

/* .....FORTRAN SUBROUTINE ....TRANRO              8/68               RN */

/*              FORTRAN SUBROUTINE TRANRO */

/* PURPOSE      ROTATE (X1,Y1) BY ANGLE RA IN DIRECTION DETERMINED */
/*              BY SIGN OF IZ. */
/*              PUT ROTATED COORDINATES IN (X11,Y11). */

/* Subroutine */ int tranro_(doublereal *x1, doublereal *y1, doublereal *x11, 
	doublereal *y11, doublereal *ra, integer *iz)
{
    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    static doublereal tc, ts;

    ts = sin(*ra);
    tc = cos(*ra);
    if (*iz < 0) {
	goto L1;
    }
    *x11 = *x1 * tc - *y1 * ts;
    *y11 = *x1 * ts + *y1 * tc;
    goto L2;
L1:
    *x11 = *x1 * tc + *y1 * ts;
    *y11 = -(*x1) * ts + *y1 * tc;
L2:
    return 0;
} /* tranro_ */

