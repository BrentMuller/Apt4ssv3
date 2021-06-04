/* GPLANE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000918.V01   *** */

/* ...  FORTRAN SUBROUTINE GPLANE                  6/70      RW */

/*  PURPOSE */
/*        THIS SUBROUTINE TRANSLATES THE CANONICAL FORMS */
/*        OF THE APT GEOMETRY (PLANE) INTO THE COEFFICIENTS OF */
/*        THE QUADRATIC. COEFFICIENTS ARE STORED */
/*        IN "QUADBF". */
/*        SUBROUTINE IS CALLED. */

/*        THE CANONICAL FORM OF PLANE IS C*X + C*Y + C*Z + D = 0 */
/*        QUADRATIC EQUATION IS C*X + C*Y + C*Z - D = 0 */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gplane_(doublereal *canon, doublereal *quadbf)
{
    static integer j, m;
    static doublereal s;



/*        ZERO COEFFICIENTS */

    /* Parameter adjustments */
    --quadbf;
    --canon;

    /* Function Body */
    for (j = 1; j <= 6; ++j) {
/* L5: */
	quadbf[j] = 0.f;
    }

/*        TEST FOR NEGATIVE COEFFICIENTS */

    m = 0;
    for (j = 1; j <= 3; ++j) {
	if (canon[j] < 0.f) {
	    --m;
	}
	if (canon[j] > 0.f) {
	    ++m;
	}
/* L6: */
    }

/*        IF A MAJORITY OF COEFFICIENTS ARE NEGATIVE, MULTIPLY BY -1 */
    s = 1.f;
    if (m < 0) {
	s = -1.f;
    }
    quadbf[7] = s * canon[1];
    quadbf[8] = s * canon[2];
    quadbf[9] = s * canon[3];
    quadbf[10] = -s * canon[4];


/*     RETURN TO CALLING PROGRAM */

/* L8: */
    return 0;
} /* gplane_ */

