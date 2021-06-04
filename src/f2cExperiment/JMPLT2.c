/* JMPLT2.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** SOURCE FILE : JMPLT2.ORG   *** */

/* Subroutine */ int jmplt2_(doublereal *u, doublereal *v, doublereal *du, 
	doublereal *dv, integer *iedge)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static doublereal c__;



/*     LIMITS JUMP DU,DV TO KEEP U,V IN RANGE 0-1 */
/*     DIRECTION OF LIMITED JUMP SAME AS ORIGINAL,UNLESS EITHER U OR V */
/*     ARE ALREADY AT LIMIT */
/*     U, V UNCHANGED */
/*     IEDGE = 0      NOT LIMITED */
/*             1      LIMITED */




/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    *iedge = 0;

/*     TEST DU, MODIFY DU,DV */

    if ((d__1 = *du - znumbr_1.z0, abs(d__1)) <= znumbr_1.z1em9 || (d__2 = *u 
	    - znumbr_1.z1, abs(d__2)) <= znumbr_1.z1em9 && *du > 0. || (d__3 =
	     *u - znumbr_1.z0, abs(d__3)) <= znumbr_1.z1em9 && *du < 0.) {
	*iedge = 1;
	*du = znumbr_1.z0;
    } else if (*u + *du > znumbr_1.z1) {
	*iedge = 1;
	c__ = znumbr_1.z1 - *u;
	*dv = *dv * c__ / *du;
	*du = c__;
    } else if (*u + *du < znumbr_1.z0) {
	*iedge = 1;
	*dv = -(*dv) * *u / *du;
	*du = -(*u);
    }

/*     TEST DV, MODIFY DU,DV */

    if ((d__1 = *dv - znumbr_1.z0, abs(d__1)) <= znumbr_1.z1em9 || (d__2 = *v 
	    - znumbr_1.z1, abs(d__2)) <= znumbr_1.z1em9 && *dv > 0. || (d__3 =
	     *v - znumbr_1.z0, abs(d__3)) <= znumbr_1.z1em9 && *dv < 0.) {
	*iedge = 1;
	*dv = znumbr_1.z0;
    } else if (*v + *dv > znumbr_1.z1) {
	*iedge = 1;
	c__ = znumbr_1.z1 - *v;
	*du = *du * c__ / *dv;
	*dv = c__;
    } else if (*v + *dv < znumbr_1.z0) {
	*iedge = 1;
	*du = -(*du) * *v / *dv;
	*dv = -(*v);
    }

    return 0;
} /* jmplt2_ */

