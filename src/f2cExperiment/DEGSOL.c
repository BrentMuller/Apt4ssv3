/* DEGSOL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : DEGSOL.ORG   *** */

/* Subroutine */ int degsol_(doublereal *v, doublereal *v1, doublereal *v2, 
	doublereal *a, doublereal *b, integer *iflag)
{
    static integer j, k;
    static doublereal o;
    static integer ja, ka;

/*     SOLVES DEGENERATE EQN. SYSTEM  A.V1 + B.V2 = V */
/*     WHERE V, V1, V2, 3-D VECTORS AND A,B SCALARS */
/*     FOR NO SOLUTION, IFLAG SET TO 1, ELSE ZERO */




    /* Parameter adjustments */
    --v2;
    --v1;
    --v;

    /* Function Body */
    *iflag = 0;
    *a = 0.;
/* .... CHOOSE LARGEST ABS(DET) */
    for (j = 1; j <= 2; ++j) {
	for (k = j + 1; k <= 3; ++k) {
	    *b = v1[j] * v2[k] - v1[k] * v2[j];
	    if (abs(*b) > abs(*a)) {
		*a = *b;
		ja = j;
		ka = k;
	    }
/* L10: */
	}
    }

    if (abs(*a) < 1e-10 || (doublereal) ja == o) {
	*iflag = 1;
    } else {
	*b = (v1[ja] * v[ka] - v1[ka] * v[ja]) / *a;
	*a = (v[ja] * v2[ka] - v[ka] * v2[ja]) / *a;
    }

    return 0;
} /* degsol_ */

