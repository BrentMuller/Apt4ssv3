/* PLAPOL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0012375.V01   *** */

/* Subroutine */ int plapol_(doublereal *pl, doublereal *poed, integer *m, 
	integer *n, doublereal *tol, doublereal *sp, integer *irc)
{
    /* System generated locals */
    integer poed_dim2, poed_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, k, ii, jj;
    static doublereal dist[5], disti, distmi;


/*  TO CHECK THE INTERFERENCE BETWEEN A PLANE AND A POLYHEDRON */
/*      PL  : I : PLANE */
/*      POED: I : POLYHEDRAL DATA OF SURFACE 2 */
/*      TOL : I : INTERSECTION TOLERANCE */
/*      SP  : O : INTERSECTION NEAR POINT */
/*      IRC : O : RETURNCODE : NO INTERSECTION: IRC=0 */


    /* Parameter adjustments */
    --pl;
    poed_dim2 = *m;
    poed_offset = 1 + 3 * (1 + poed_dim2);
    poed -= poed_offset;
    --sp;

    /* Function Body */
    *irc = 0;
    distmi = 1e20;

/*  DISTANCE TO PLANE */
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    disti = poed[(i__ + j * poed_dim2) * 3 + 1] * pl[1] + poed[(i__ + 
		    j * poed_dim2) * 3 + 2] * pl[2] + poed[(i__ + j * 
		    poed_dim2) * 3 + 3] * pl[3] - pl[4];

/*   MINIMUM DISTANCE SELECTION */
	    if (distmi < abs(disti)) {
		goto L2;
	    }
	    distmi = abs(disti);
	    ii = i__;
	    jj = j;

/*   CROSS OF PLANE IN V-DIRECTION ? */
L2:
	    if (j == 1) {
		goto L5;
	    }
	    if (disti * dist[i__ - 1] > 0.) {
		goto L5;
	    }

/*   CROSS OR TUCH POINT FOUND */
	    ii = i__;
	    jj = j;
	    goto L20;

/*   CROSS OF PLANE IN U-DIRECTION ? */
L5:
	    if (i__ == 1) {
		goto L7;
	    }
	    if (disti * dist[i__ - 2] > 0.) {
		goto L7;
	    }

/*   CROSS OR TUCH POINT FOUND */
	    ii = i__;
	    jj = j;
	    goto L20;

/*   STORE DISTANCE */
L7:
	    dist[i__ - 1] = disti;
/* L10: */
	}
    }

/*   RETURN IF THE SURFACES ARE NOT CLOSE ENOUGH */
    if (*tol * 100. < distmi) {
	return 0;
    }

/*  STORE NEAR POINT */
L20:
    for (k = 1; k <= 3; ++k) {
/* L30: */
	sp[k] = poed[k + (ii + jj * poed_dim2) * 3];
    }
    *irc = 1;

    return 0;
} /* plapol_ */

