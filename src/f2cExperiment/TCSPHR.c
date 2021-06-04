/* TCSPHR.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : TCSPHR.V01   *** */

/* Subroutine */ int tcsphr_(doublereal *te, doublereal *ta, doublereal *tul, 
	doublereal *r__, doublereal *pside, doublereal *pthick, doublereal *
	tccent, doublereal *tcrad)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal cosa, sina;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal offset;


/*     PURPOSE: COMPUTE THE CENTRE AND RADIUS OF THE TOOL CONTACT SPHERE */


/*     ARGUMENTS: */

/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     TUL     -  TOOL GEOMETRY */
/*     R       -  SURFACE CONTACT POINT AND DERIVATIVES */
/*     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV) */
/*     PTHICK  -  THICKNESS OFFSET FROM SURFACE */
/*     TCCENT  -  CENTRE OF TOOL CONTACT SPHERE */
/*     TCRAD   -  RADIUS OF TOOL CONTACT SPHERE */





/* .... LOCAL VARIABLES */

/*     COSA    -  COSINE OF ANGLE BETWEEN SURFACE NORMAL AND TOOL AXIS */
/*     SINA    -  SINE             (DITTO) */
/*     OFFSET  -  POSITION OF CENTRE ALONG TA FROM TE */


    /* Parameter adjustments */
    --tccent;
    --r__;
    --tul;
    --ta;
    --te;

    /* Function Body */
    dotf_(&cosa, &r__[29], &ta[1]);

    if ((d__1 = 1. - cosa, abs(d__1)) <= 1e-6) {

/* .... SN PARALLEL TO TA */

	for (i__ = 1; i__ <= 3; ++i__) {
	    tccent[i__] = te[i__] + ta[i__] * 1e5;
/* L10: */
	}
	*tcrad = 1e5;

    } else {
	sina = sqrt(1 - cosa * cosa);

/* .... RADIUS = E/SINA + R */

	*tcrad = tul[3] / sina + tul[1];

/* .... POSITION OF CENTRE ALONG TA FROM TE */

/*            = F + (TCRAD-R)*COSA */

	offset = tul[4] + tul[1] + (*tcrad - tul[1]) * cosa;
	for (i__ = 1; i__ <= 3; ++i__) {
	    tccent[i__] = te[i__] + offset * ta[i__];
/* L20: */
	}

    }

    return 0;
} /* tcsphr_ */

