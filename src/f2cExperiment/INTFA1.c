/* INTFA1.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0012393.V01   *** */

/* Subroutine */ int intfa1_(doublereal *face, doublereal *pl, doublereal *pf,
	 integer *irc1)
{
    static integer i__;
    static doublereal v2[3], v3[3];
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);



    /* Parameter adjustments */
    --pf;
    --pl;
    face -= 7;

    /* Function Body */
    *irc1 = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	v2[0] = pf[1] - face[i__ * 6 + 1];
	v2[1] = pf[2] - face[i__ * 6 + 2];
	v2[2] = pf[3] - face[i__ * 6 + 3];
	cross_(v2, &face[i__ * 6 + 4], v3);
	if (pl[1] * v3[0] + pl[2] * v3[1] + pl[3] * v3[2] < 0.) {
	    goto L20;
	}
/* L10: */
    }
    *irc1 = 1;
L20:

    return 0;
} /* intfa1_ */

