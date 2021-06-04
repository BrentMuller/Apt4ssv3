/* SMOOTH.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000659.V02   *** */


/* Subroutine */ int smooth_(doublereal *q, doublereal *rl, doublereal *a, 
	doublereal *tv, doublereal *cb, integer *nin, integer *idc)
{
    /* Initialized data */

    static doublereal smal1 = 1e-7;
    static doublereal smal2 = 1e-6;
    static doublereal smal3 = 1e-14;
    static doublereal one = 1.;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, n;
    static doublereal w;
    static integer j1, k1, l1, l2, n2, n3;
    static doublereal aa, ca[90]	/* was [3][30] */;
    static integer ia, ib, ic, id;
    static doublereal cm[900];
    static integer jg, ii, ij, jj;
    static doublereal ct[90], cv[90]	/* was [3][30] */;
    static integer jo, nn, nr;
    static doublereal tl;
    static integer ier;
    static doublereal eps;
    extern /* Subroutine */ int gelg_(doublereal *, doublereal *, doublereal *
	    , integer *, integer *, integer *);
    static integer idxx;

/* ----************* SMTH1 *********************************'71/4/23  N.K. */
/* ---- THIS ROUTINE CALCULATES SMOOTHED POINTS AND TANGENT VECTORS AT */
/* ---- THOSE POINTS , AND INPUT IS AN ARRAY OF POINT VECTORS. */
/* ---- INPUT --- N = NUMBER OF POINTS */
/* ----           Q = AN ARRAY OF INPUT POINT VECTORS */
/* ----           RL = AN ARRAY OF RELAXATION FACTORS ASSOCIATED TO EACH */
/* ----                INPUT POINTS   ( RL(I)=0. MEANS NO SMOOTHING */
/* ----                                 TO THE I-TH POINT.) */
/* ----           IDC = BOUNDARY CONDITION IDENTIFIER */
/* ----               =1   CLOSED CURVE */
/* ----                =2   1-ST DERIVATIVE --- 1-ST DERIVATIVE */
/* ----               =3   1-ST DERIVATIVE --- 2-ND DERIVATIVE */
/* ----               =4   2-ND DERIVATIVE --- 1-ST DERIVATIVE */
/* ----               =5   2-ND DERIVATIVE --- 2-ND DERIVATIVE */
/* ----           TV = END CONDITION VECTORS INTERPRETED AS SPECIFIED BY */
/* ----                IDC. */
/* ---- OUTPUT--- A = AN ARRAY OF DISTANCE BETWEEN CONSECUTIVE OUTPUT */
/* ----               POINTS  ( A(J)=DISTANCE BTW. J-TH AND (J-1)-TH PNT.) */
/* ----           CB = AN ARRAY OF 1-ST DERIVATIVES (NORMALIZED) */
/* ----           IDC = ERROR INDICATOR */
/* ----               =0   NO ERROR */
/* ----               =-1   A DISTANCE BTW. TWO CONSECUTIVE INPUT POINTS */
/* ----                     IS VANISHING */
/* ----               = -2   IDC IS NOT SIGNIFICANT. */
/* ----               =-3   ERROR IN SOLVING SIMULTANEOUS EQUATION */
/* ----               =-4   NUMBER OF INPUT POINTS IS LESS THAN 3. */
/* ----               =-5   A DISTANCE BTW. TWO CONSECUTIVE OUTPUT POINTS */
/* ----                     IS VANISHING. */
/* ----               =-6   AN OUTPUT 1-ST DERIVATIVE IS VANISHING. */
/* ----********* SUBSIDIARY --- GELG */
/* ----******************************************************************* */
    /* Parameter adjustments */
    cb -= 4;
    tv -= 4;
    --a;
    --rl;
    q -= 4;

    /* Function Body */
/* ------ JG CONTROLS OUTPUT. JO IS OUTPUT FILE NUMBER. */
    jg = 0;
    jo = 6;
/* ------ INITIAL EXAMINATION TO DETERMINE IF CURVE IS CLOSED */
    n = *nin;
/* Computing 2nd power */
    d__1 = q[4] - q[n * 3 + 1];
/* Computing 2nd power */
    d__2 = q[5] - q[n * 3 + 2];
/* Computing 2nd power */
    d__3 = q[6] - q[n * 3 + 3];
    w = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if (w > smal2) {
	goto L3;
    }
/* --- CLOSED CURVE CASE   END POINTS ASSUMED EQUAL */
    n = *nin - 1;
    *idc = 1;
L3:
/* ------ CONVERT FROM A PART PROGRAMMER WEIGHT FACTOR(0.0 TO 1.0 WHERE */
/* ------ 1.0 MEANS CERTAINTY FOR A POINT) TO A RELAXATION FACTOR ( INF */
/* ------ TO 0.0 WHERE 0.0 IS CERTITUDE AND INFINITY IS COMPLETE RELAXA) */
    i__1 = *nin;
    for (i__ = 1; i__ <= i__1; ++i__) {
	aa = rl[i__];
	if (aa < smal1) {
	    aa = smal1;
	}
	if (aa > one) {
	    aa = one;
	}
	rl[i__] = one / aa - one;
/* L1517: */
    }
    nn = n * n;
    n3 = n * 3;

/*    ***DISTANCE BTW,CONSECUTIVE INPUT POINTS*** */
/*    ***NORMALIZED INCREMENTAL VECTORS*** */
/*    ***SINGULARITY IS CHECKED*** */

    if (n < 3) {
	goto L1300;
    }
/* L1: */
    i__1 = n;
    for (j = 2; j <= i__1; ++j) {
	jj = j - 1;
	for (i__ = 1; i__ <= 3; ++i__) {
	    cv[i__ + j * 3 - 4] = q[i__ + j * 3] - q[i__ + jj * 3];
/* L11: */
	}
/* Computing 2nd power */
	d__1 = cv[j * 3 - 3];
/* Computing 2nd power */
	d__2 = cv[j * 3 - 2];
/* Computing 2nd power */
	d__3 = cv[j * 3 - 1];
	a[j] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	if (a[j] < smal1) {
	    goto L1000;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    cv[i__ + j * 3 - 4] /= a[j];
/* L12: */
	}
/* L10: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L13: */
	cv[i__ - 1] = q[i__ + 3] - q[i__ + n * 3];
    }
/* Computing 2nd power */
    d__1 = cv[0];
/* Computing 2nd power */
    d__2 = cv[1];
/* Computing 2nd power */
    d__3 = cv[2];
    a[1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if (a[1] < smal1) {
	goto L1000;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L14: */
	cv[i__ - 1] /= a[1];
    }

/*    ***CONSTANT VECTORS FOR THE EQUATION OF CURVATURE*** */

    l1 = n + 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = i__ * n - l1;
	i__1 = n;
	for (j = 2; j <= i__1; ++j) {
	    ct[ii + j - 1] = (cv[i__ + j * 3 - 4] - cv[i__ + (j - 1) * 3 - 4])
		     * 6.f;
/* L21: */
	}
	ct[ii + l1 - 1] = (cv[i__ - 1] - cv[i__ + n * 3 - 4]) * 6.f;
/* L20: */
    }

/*    ***CLEAR THE MATRIX*** */

    i__1 = nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	cm[i__ - 1] = 0.f;
/* L30: */
    }

/*    ***MATRIX ELEMENTS*** */

/* Computing 2nd power */
    d__1 = a[2];
    ca[0] = (rl[1] + rl[2]) * 6.f / (d__1 * d__1);
    cb[4] = rl[1] / a[2] * 6.f / a[1];
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = i__ + 1 - i__ / n * n;
	j1 = i__ + 2 - (i__ + 1) / n * n;
/* Computing 2nd power */
	d__1 = a[j1];
	ca[ii * 3 - 3] = (rl[ii] + rl[j1]) * 6.f / (d__1 * d__1);
	cb[ii * 3 + 1] = rl[ii] / a[j1] * 6.f / a[ii];
	cb[i__ * 3 + 2] = a[ii] - (cb[ii * 3 + 1] + ca[i__ * 3 - 3] + cb[i__ *
		 3 + 1]);
	cb[ii * 3 + 3] = (a[j1] + a[ii]) * 2.f + (ca[ii * 3 - 3] + ca[i__ * 3 
		- 3] + cb[ii * 3 + 1] * 2.f);
/* L31: */
    }

/*    ***SET PRIMARY MATRIX*** */

    l2 = n + 2;
    n2 = n << 1;
    i__1 = n2;
    for (ij = l1; ij <= i__1; ++ij) {
	j = ij - 1 - (ij - 2) / n * n;
	jj = j + 1 - j / n * n;
	i__ = j * l1 - n;
	ia = i__ + n - (i__ + n - 1) / nn * nn;
	ib = i__ + (n << 1) - (i__ + (n << 1)) / nn * nn;
	ic = i__ + 1 - j / n * n;
	id = i__ + 2 - (j + 1) / n * n;
	cm[i__ - 1] = cb[j * 3 + 3] + cm[i__ - 1];
	cm[ia - 1] = cb[j * 3 + 2] + cm[ia - 1];
	cm[ib - 1] = cb[jj * 3 + 1] + cm[ib - 1];
	cm[ic - 1] = cb[j * 3 + 2] + cm[ic - 1];
	cm[id - 1] = cb[jj * 3 + 1] + cm[id - 1];
/* L41: */
    }

/*    ***CLOSED CURVE*** */

    if (*idc == 1) {
	goto L200;
    }

/*    ***OPEN ENDS*** */

    k1 = n - 1;
    cm[nn - n] = 0.f;
    cm[nn - n + 1] = 0.f;
    cm[nn - n2] = 0.f;
    cm[n - 1] = 0.f;
    cm[n2 - 1] = 0.f;
    cm[k1 - 1] = 0.f;
    cm[1] = a[2] - ca[0] - cb[7];
    if (n != 3) {
	goto L60;
    }
    cm[7] = a[3] - (ca[3] + cb[7]);
    goto L61;
L60:
    cm[nn - 2] = a[n] - (ca[k1 * 3 - 3] + cb[k1 * 3 + 1]);

/*    *** FIRST END BY CURVATURE*** */

L61:
    if (*idc < 4) {
	goto L110;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ct[i__ * n - k1 - 1] = tv[i__ + 3];
/* L42: */
    }
    cm[0] = 1.f;
    cm[l1 - 1] = 0.f;
    cm[n2] = 0.f;

/*    ***LAST END BY TANGENT*** */

    if (*idc != 4) {
	goto L120;
    }
L130:
    for (i__ = 1; i__ <= 3; ++i__) {
	ct[i__ * n - 1] = (cv[i__ + n * 3 - 4] - tv[i__ + 6]) * 6.f;
/* L43: */
    }
    cm[nn - n - 1] = -a[n] + cb[k1 * 3 + 1] + ca[k1 * 3 - 3];
    cm[nn - 1] = a[n] * -2.f - ca[k1 * 3 - 3];
    cm[nn - n2 - 1] = -cb[k1 * 3 + 1];
    goto L200;

/*    ***LAST END BY CURVATURE*** */

L120:
    if (*idc != 5) {
	goto L1100;
    }
L140:
    for (i__ = 1; i__ <= 3; ++i__) {
	ct[i__ * n - 1] = tv[i__ + 6];
/* L44: */
    }
    cm[nn - 1] = 1.f;
    cm[nn - n - 1] = 0.f;
    cm[nn - n2 - 1] = 0.f;
    goto L200;

/*    ***FIRST END BY TANGENT*** */

L110:
    for (i__ = 1; i__ <= 3; ++i__) {
	ct[i__ * n - k1 - 1] = (cv[i__ + 2] - tv[i__ + 3]) * 6.f;
/* L45: */
    }
    cm[0] = a[2] * 2.f + ca[0];
    cm[l1 - 1] = a[2] - (ca[0] + cb[7]);
    cm[n2] = cb[7];
    if (*idc == 2) {
	goto L130;
    }
    goto L140;

/*    *** CALCULATION OF CURVATURE*** */

L200:
    eps = smal3;
    nr = 3;
    gelg_(ct, cm, &eps, &n, &nr, &ier);
    if (ier != 0) {
	goto L1200;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = i__ * n - n;
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    cv[i__ + j * 3 - 4] = ct[ii + j - 1];
/* L51: */
	}
/* L50: */
    }
/*    ***CALCULATION OF CURVE SEGMENT COEFFICIENTS*** */

    for (i__ = 1; i__ <= 3; ++i__) {
	i__1 = n;
	for (j = 2; j <= i__1; ++j) {
	    ca[i__ + j * 3 - 4] = (cv[i__ + j * 3 - 4] - cv[i__ + (j - 1) * 3 
		    - 4]) / a[j];
/* L56: */
	}
	ca[i__ - 1] = (cv[i__ - 1] - cv[i__ + n * 3 - 4]) / a[1];
	k1 = n - 1;
	i__1 = k1;
	for (j = 2; j <= i__1; ++j) {
	    q[i__ + j * 3] -= rl[j] * (ca[i__ + (j + 1) * 3 - 4] - ca[i__ + j 
		    * 3 - 4]);
/* L57: */
	}
	if (*idc == 1) {
	    goto L250;
	}
	q[i__ + 3] -= rl[1] * (cv[i__ + 2] - cv[i__ - 1]) / a[2];
	q[i__ + n * 3] += rl[n] * (cv[i__ + n * 3 - 4] - cv[i__ + (n - 1) * 3 
		- 4]) / a[n];
	goto L55;
L250:
	q[i__ + 3] -= rl[1] * (ca[i__ + 2] - ca[i__ - 1]);
	q[i__ + n * 3] -= rl[n] * (ca[i__ - 1] - ca[i__ + n * 3 - 4]);
L55:
	;
    }
    idxx = 0;
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	if (rl[j] > smal2) {
	    ++idxx;
	}
	if (rl[j] > smal2) {
	    rl[j] = 0.f;
	}
/* L400: */
    }
    if (idxx == 0) {
	goto L590;
    }
    goto L500;
L590:
    i__1 = n;
    for (j = 2; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    ca[i__ + j * 3 - 4] = q[i__ + j * 3] - q[i__ + (j - 1) * 3];
/* L510: */
	}
    }
    if (*idc != 1) {
	goto L260;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L520: */
	ca[i__ - 1] = q[i__ + 3] - q[i__ + n * 3];
    }
L260:
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	j1 = j + 1 - j / n * n;
	for (i__ = 1; i__ <= 3; ++i__) {
	    cb[i__ + j * 3] = ca[i__ + j1 * 3 - 4] / a[j1] - a[j1] * (cv[i__ 
		    + j * 3 - 4] * 2.f + cv[i__ + j1 * 3 - 4]) / 6.f;
/* L93: */
	}
	a[j1] = 0.f;
	for (i__ = 1; i__ <= 3; ++i__) {
/* Computing 2nd power */
	    d__1 = ca[i__ + j1 * 3 - 4];
	    a[j1] = d__1 * d__1 + a[j1];
/* L92: */
	}
	a[j1] = sqrt(a[j1]);
	if (a[j1] >= smal3) {
	    goto L91;
	}
	if (j != n) {
	    goto L1400;
	}
	if (*idc == 1) {
	    goto L1400;
	}
	a[1] = 99999.f;
L91:
	;
    }
    if (*idc == 1) {
	goto L511;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L94: */
	cb[i__ + n * 3] = ca[i__ + n * 3 - 4] / a[n] + a[n] * (cv[i__ + (n - 
		1) * 3 - 4] + cv[i__ + n * 3 - 4] * 2.f) / 6.f;
    }
L511:
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	tl = sqrt(cb[j * 3 + 1] * cb[j * 3 + 1] + cb[j * 3 + 2] * cb[j * 3 + 
		2] + cb[j * 3 + 3] * cb[j * 3 + 3]);
	if (tl <= smal2) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* L310: */
	    cb[i__ + j * 3] /= tl;
	}
/* L300: */
    }
    goto L500;
L1000:
    *idc = -1;
    goto L500;
L1100:
    *idc = -2;
    goto L500;
L1200:
    *idc = -3;
    goto L500;
L1300:
    *idc = -4;
    goto L500;
L1400:
    *idc = -5;
    goto L500;
L1500:
    *idc = -6;
L500:
    if (*idc != 1) {
	return 0;
    }
/* ------ FINAL ADJUSTMENT FOR CLOSED CURVE */
    for (i__ = 1; i__ <= 3; ++i__) {
	q[i__ + *nin * 3] = q[i__ + 3];
	cb[i__ + *nin * 3] = cb[i__ + 3];
/* L502: */
    }
    a[*nin] = a[1];
    *idc = 2;
    return 0;
} /* smooth_ */

