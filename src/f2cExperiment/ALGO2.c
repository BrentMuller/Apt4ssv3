/* ALGO2.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ALGO2.ORG   *** */

/* Subroutine */ int algo2_(doublereal *tn, doublereal *ru, doublereal *rv, 
	doublereal *ruu, doublereal *ruv, doublereal *rvv, doublereal *du, 
	doublereal *dv, logical *iok)
{
    static doublereal a, b, c__, d__, e, f;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );


/*     PURPOSE: CALCULATE DU,DV USING ALGORITHM 2 */

/*              GIVEN AN INITIAL SURFACE POINT, AND THE TOOL NORMAL TN */
/*              AT THE 'NEAREST' POINT ON THE TOOL, */
/*              USING  A LOCAL QUADRATIC APPROXIMATION TO THE SURFACE */
/*              DETERMINE DU,DV OF POINT S WITH SAME NORMAL TN */

/*     ARGUMENTS: */

/*            TN  - TOOL NORMAL AT 'NEAREST' POINT ON TOOL */
/*            RU,RV - FIRST DERIVATIVES AT R */
/*            RUU,RUV,RVV - SECOND DERIVATIVES AT R */
/*            DU,DV - ESTIMATED DU,DV USING ALGORITHM 2 */
/*            IOK   - FLAG INDICATING THAT DU,DV HAVE BEEN CALCULATED */


/*     LOCAL VARIABLES: */



/* .... COMPUTE DETERMINANT OF SECOND FUNDAMENTAL MATRIX OF SURFACE AT R */

    /* Parameter adjustments */
    --rvv;
    --ruv;
    --ruu;
    --rv;
    --ru;
    --tn;

    /* Function Body */
    dotf_(&a, &tn[1], &ruu[1]);
    dotf_(&b, &tn[1], &ruv[1]);
    dotf_(&c__, &tn[1], &rvv[1]);

    f = b * b - a * c__;

    if (abs(f) < 1e-6) {
/* .... AT LEAST ONE CURVATURE IS ZERO, SURFACE IS LCALLY A RULED SURFACE */
/*     THEREFORE UNABLE TO COMPUTE DU,DV USING ALGORITHM 2 */
	*iok = FALSE_;
    } else {
	*iok = TRUE_;

	dotf_(&d__, &tn[1], &ru[1]);
	dotf_(&e, &tn[1], &rv[1]);

	*du = (d__ * c__ - b * e) / f;
	*dv = (a * e - b * d__) / f;
    }

    return 0;
} /* algo2_ */

