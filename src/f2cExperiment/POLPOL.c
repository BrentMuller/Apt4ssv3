/* POLPOL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0012381.V01   *** */

/* Subroutine */ int polpol_(doublereal *poed1, integer *m1, integer *n1, 
	doublereal *poed2, integer *m2, integer *n2, doublereal *tol, 
	doublereal *sp, integer *irc)
{
    /* System generated locals */
    integer poed1_dim2, poed1_offset, poed2_dim2, poed2_offset, i__1, i__2, 
	    i__3, i__4;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_5[18];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, m, n, k1, l1;
#define p1 (equiv_5)
#define p2 (equiv_5 + 6)
#define p3 (equiv_5 + 12)
    static integer l2, k3;
#define v1 (equiv_5 + 3)
#define v2 (equiv_5 + 9)
#define v3 (equiv_5 + 15)
    static integer k2, l3, ii, jj;
    static doublereal pf[3], pl[4], sec;
    static integer m1m1, n1m1, irc1;
#define face (equiv_5)
    static doublereal dist[5], disti;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), intfa1_(doublereal *, doublereal *, doublereal *, integer *), 
	    intfa2_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *);
    static doublereal distmi;


/*  TO CHECK THE INTERFERENCE BETWEEN A PLANE AND A POLYHEDRON */
/*      POED1: I : POLYHEDRAL DATA OF SURFACE 1 */
/*      POED2: I : POLYHEDRAL DATA OF SURFACE 2 */
/*      TOL  : I : INTERSECTION TOLERANCE */
/*      SP   : O : INTERSECTION NEAR POINT */
/*      IRC  : O : RETURNCODE : NO INTERSECTION: IRC=0 */



    /* Parameter adjustments */
    poed1_dim2 = *m1;
    poed1_offset = 1 + 3 * (1 + poed1_dim2);
    poed1 -= poed1_offset;
    poed2_dim2 = *m2;
    poed2_offset = 1 + 3 * (1 + poed2_dim2);
    poed2 -= poed2_offset;
    --sp;

    /* Function Body */
    *irc = 0;
    distmi = 1e20;
    n1m1 = *n1 - 1;
    m1m1 = *m1 - 1;
    i__1 = n1m1;
    for (l = 1; l <= i__1; ++l) {
	i__2 = m1m1;
	for (k = 1; k <= i__2; ++k) {

/*   COMPUTE INDICES OF TRIANGLE FACES ON DS PATCH */
	    k1 = k;
	    l1 = l;
	    l2 = l + 1;
	    k3 = k + 1;
	    for (m = 1; m <= 2; ++m) {
		k2 = k + m - 1;
		l3 = l + 2 - m;

/*  EXTRACT FACE CORNER POINTS */
		for (n = 1; n <= 3; ++n) {
		    p1[n - 1] = poed1[n + (k1 + l1 * poed1_dim2) * 3];
		    p2[n - 1] = poed1[n + (k2 + l2 * poed1_dim2) * 3];
		    p3[n - 1] = poed1[n + (k3 + l3 * poed1_dim2) * 3];
		    v1[n - 1] = p2[n - 1] - p1[n - 1];
		    v2[n - 1] = p3[n - 1] - p2[n - 1];
/* L40: */
		    v3[n - 1] = p1[n - 1] - p3[n - 1];
		}

/*  GENERATE PLANE COEFFICENTS */
		cross_(v2, v1, pl);
/* Computing 2nd power */
		d__1 = pl[0];
/* Computing 2nd power */
		d__2 = pl[1];
/* Computing 2nd power */
		d__3 = pl[2];
		sec = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
		pl[0] /= sec;
		pl[1] /= sec;
		pl[2] /= sec;
		pl[3] = pl[0] * p1[0] + pl[1] * p1[1] + pl[2] * p1[2];

/*  DISTANCE BETWEEN FACES ON DS PATCH AND POINTS OF PS PATCH */
		i__3 = *n2;
		for (j = 1; j <= i__3; ++j) {
		    i__4 = *m2;
		    for (i__ = 1; i__ <= i__4; ++i__) {
			disti = poed2[(i__ + j * poed2_dim2) * 3 + 1] * pl[0] 
				+ poed2[(i__ + j * poed2_dim2) * 3 + 2] * pl[
				1] + poed2[(i__ + j * poed2_dim2) * 3 + 3] * 
				pl[2] - pl[3];

/*   MINIMUM DISTANCE SELECTION */
			if (distmi < abs(disti)) {
			    goto L2;
			}

/*  CALCULATE FOOT POINT ON PLANE */
			pf[0] = poed2[(i__ + j * poed2_dim2) * 3 + 1] - disti 
				* pl[0];
			pf[1] = poed2[(i__ + j * poed2_dim2) * 3 + 2] - disti 
				* pl[1];
			pf[2] = poed2[(i__ + j * poed2_dim2) * 3 + 3] - disti 
				* pl[2];

/*   CALCULATE IF FOOT POINT IS IN PLANE */
			intfa1_(face, pl, pf, &irc1);
			if (irc1 == 0) {
			    goto L2;
			}

/*  DISTANCE TO PLANE */
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
			intfa2_(face, pl, &poed2[(i__ + (j - 1) * poed2_dim2) 
				* 3 + 1], &poed2[(i__ + j * poed2_dim2) * 3 + 
				1], &irc1);
			if (irc1 == 0) {
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
			intfa2_(face, pl, &poed2[(i__ - 1 + j * poed2_dim2) * 
				3 + 1], &poed2[(i__ + j * poed2_dim2) * 3 + 1]
				, &irc1);
			if (irc1 == 0) {
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
/* L50: */
	    }
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
	sp[k] = poed2[k + (ii + jj * poed2_dim2) * 3];
    }
    *irc = 1;

    return 0;
} /* polpol_ */

#undef face
#undef v3
#undef v2
#undef v1
#undef p3
#undef p2
#undef p1


