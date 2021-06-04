/* GQUAD.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000919.V01   *** */

/* ...  FORTRAN SUBROUTINE GQUAD                   7/70      RW */
/*        CANONICAL FORM OF QUADRATIC */
/*        1. COEFFICIENT OF X**2 (A) */
/*        2. COEFFICIENT OF Y**2 (B) */
/*        3. COEFFICIENT OF Z**2 (C) */
/*        4. CONSTANT TERM       (D) */
/*        5. COEFFICIENT OF 2YZ  (F) */
/*        6. COEFFICIENT OF 2XZ  (G) */
/*        7. COEFFICIENT OF 2XY  (H) */
/*        8. COEFFICIENT OF 2X   (P) */
/*        9. COEFFICIENT OF 2Y   (Q) */
/*       10. COEFFICIENT OF 2Z   (R) */

/*        EQUATION */

/*        A*X**2+B*Y**2+C*Z**2+2*F*Y*Z+ */
/*        2*G*X*Z+2*H*X*Y+2*P*X+2*Q*Y+ */
/*        2*R*Z+D=0 */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gquad_(doublereal *canon, doublereal *quadbf)
{
    static integer i__;


    /* Parameter adjustments */
    --quadbf;
    --canon;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2: */
	quadbf[i__] = canon[i__];
    }
    for (i__ = 4; i__ <= 9; ++i__) {
/* L5: */
	quadbf[i__] = canon[i__ + 1] * 2.f;
    }
    quadbf[10] = canon[4];

    return 0;
} /* gquad_ */

