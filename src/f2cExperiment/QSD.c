/* QSD.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002772.V02   *** */


/* ....    FORTRAN SUBROUTINE            QSD            4/1/69     RC */

/* Subroutine */ int qsd_(doublereal *canfrm, integer *iq, doublereal *coeff, 
	doublereal *trans)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal c__;
    static integer i__, j, k, l, n;
    static doublereal p, q, r__, s;
    static integer i1;
    static doublereal cc;
    static integer il;
    static doublereal sc;
    static integer kk, ll;
    static doublereal ql[16]	/* was [4][4] */, ss, akk, akl, all, one;
    static integer iit;
    static doublereal amin, amax;
    extern doublereal psign_(doublereal *, doublereal *);


/*  PURPOSE         TO IDENTIFY QUADRIC, LCONIC, AND GCONIC SURFACES */

/*  CALLING SEQNCE  CALL  QSD(CANFRM,IQ,COEFF,TRANS) */

/*  ARGUMENTS       CANFRM....ARRAY CONTAINING ORIGINAL CANONICAL FORM */
/*                  IQ .......FLAG SET TO INDICATE TYPE OF QUADRIC */
/*                            SURFACE FOUND BY THIS ROUTINE */
/*                  COEFF.....ARRAY CONTAINING NEW VALUES CALCULATED */
/*                            FOR THE QUADRIC EQUATION */
/*                  TRANS.....TRANSFORMATION MATRIX FROM THE ORIGINAL */
/*                            TO THE LOCAL COORDINATE SYSTEM */

/*  CALLED BY       AERR */

/*  SUBSIDIARIES    REAL FUNCTION SUBPROGRAM - PSIGN */

/*  DIAGNOSTICS     NONE */

/*     ----------------------------------------------------------- */

/*              ** INITIALIZE ** */

    /* Parameter adjustments */
    trans -= 4;
    --coeff;
    --canfrm;

    /* Function Body */
    one = 1.f;
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L20: */
	    ql[i__ + (j << 2) - 5] = 0.;
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L30: */
	    trans[i__ + j * 3] = 0.;
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	trans[i__ + i__ * 3] = 1.;
    }

/*        ** SET UP INITIAL CANONICAL VALUES */

    ql[0] = canfrm[1];
    ql[5] = canfrm[2];
    ql[10] = canfrm[3];
    ql[15] = canfrm[4];
    ql[9] = canfrm[5];
    ql[6] = canfrm[5];
    ql[8] = canfrm[6];
    ql[2] = canfrm[6];
    ql[4] = canfrm[7];
    ql[1] = canfrm[7];
    p = canfrm[8];
    q = canfrm[9];
    r__ = canfrm[10];

/*               * FIND ROTATION MATRIX AND LOCAL QL */

L100:
    amax = 0.;
    amin = abs(ql[10]);
    for (i__ = 1; i__ <= 2; ++i__) {
	if ((d__1 = ql[i__ + (i__ << 2) - 5], abs(d__1)) - amin >= 0.) {
	    goto L103;
	} else {
	    goto L102;
	}
L102:
	amin = (d__1 = ql[i__ + (i__ << 2) - 5], abs(d__1));
L103:
	i1 = i__ + 1;
	for (j = i1; j <= 3; ++j) {
	    if ((d__1 = ql[i__ + (j << 2) - 5], abs(d__1)) - amax <= 0.) {
		goto L120;
	    } else {
		goto L110;
	    }
L110:
	    amax = (d__1 = ql[i__ + (j << 2) - 5], abs(d__1));
	    k = i__;
	    l = j;
L120:
	    ;
	}
    }
/*               * SET SMALL TERMS TO ZERO */

    if (amin != 0.) {
	goto L130;
    } else {
	goto L140;
    }
L130:
    if (amax / amin - 1e-15f >= 0.) {
	goto L140;
    } else {
	goto L160;
    }
L140:
    if (amax - 1e-25f >= 0.) {
	goto L200;
    } else {
	goto L160;
    }
L160:
    for (i__ = 1; i__ <= 2; ++i__) {
	i1 = i__ + 1;
	for (j = i1; j <= 3; ++j) {
	    ql[i__ + (j << 2) - 5] = 0.;
	    ql[j + (i__ << 2) - 5] = 0.;
/* L170: */
	}
    }
    goto L250;

/*               * JACOBI CALCULATION */
L200:
    akk = ql[k + (k << 2) - 5];
    akl = ql[k + (l << 2) - 5];
    all = ql[l + (l << 2) - 5];
    if (all - akk != 0.) {
	goto L205;
    } else {
	goto L208;
    }
L205:
    s = akl / (all - akk);
    goto L210;
L208:
    s = psign_(&one, &akl);
L210:
    if (abs(s) - .5f >= 0.) {
	goto L212;
    } else {
	goto L214;
    }
L212:
    d__1 = one * .5f;
    s = psign_(&d__1, &s);
L214:
    ss = s * s;
    cc = 1 - ss;
    c__ = sqrt(cc);
    sc = s * c__;
    ql[k + (k << 2) - 5] = cc * akk - sc * 2 * akl + ss * all;
    ql[l + (l << 2) - 5] = ss * akk + sc * 2 * akl + cc * all;
    ql[l + (k << 2) - 5] = (cc - ss) * akl + sc * (akk - all);
    ql[k + (l << 2) - 5] = ql[l + (k << 2) - 5];
    j = 6 - k - l;
    akk = ql[j + (k << 2) - 5];
    all = ql[j + (l << 2) - 5];
    ql[j + (k << 2) - 5] = c__ * akk - s * all;
    ql[k + (j << 2) - 5] = ql[j + (k << 2) - 5];
    ql[j + (l << 2) - 5] = s * akk + c__ * all;
    ql[l + (j << 2) - 5] = ql[j + (l << 2) - 5];
    for (i__ = 1; i__ <= 3; ++i__) {
	akk = trans[k + i__ * 3];
	all = trans[l + i__ * 3];
	trans[k + i__ * 3] = c__ * akk - s * all;
	trans[l + i__ * 3] = s * akk + c__ * all;
/* L230: */
    }
    goto L100;

/*               * ROTATION COMPLETE */
L250:
    all = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	ql[i__ + 11] = p * .5f * trans[i__ + 3] + q * .5f * trans[i__ + 6] + 
		r__ * .5f * trans[i__ + 9];
	ql[(i__ << 2) - 1] = ql[i__ + 11];
/* L280: */
	all += (d__1 = ql[i__ + (i__ << 2) - 5], abs(d__1));
    }
    all /= 3e10f;

/*               * COMPUTE TRANSLATION */
    for (k = 1; k <= 3; ++k) {
	akk = ql[k + (k << 2) - 5];
	if (abs(akk) - all <= 0.) {
	    goto L290;
	} else {
	    goto L285;
	}
L285:
	trans[k + 12] = ql[k + 11] / akk;
	akl = trans[k + 12];
	ql[15] -= akl * ql[k + 11];
	ql[k + 11] = 0.;
	ql[(k << 2) - 1] = 0.;
	goto L300;
L290:
	ql[k + (k << 2) - 5] = 0.;
L300:
	;
    }
    if (abs(ql[15]) - all <= 0.) {
	goto L305;
    } else {
	goto L310;
    }
L305:
    ql[15] = 0.;
L310:
    akk = 0.;
    for (j = 1; j <= 4; ++j) {
	if ((d__1 = ql[j + (j << 2) - 5], abs(d__1)) - akk <= 0.) {
	    goto L320;
	} else {
	    goto L315;
	}
L315:
	akk = (d__1 = ql[j + (j << 2) - 5], abs(d__1));
L320:
	;
    }
    if (akk != 0.) {
	goto L325;
    } else {
	goto L330;
    }
L325:
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L328: */
	    ql[i__ + (j << 2) - 5] /= akk;
	}
    }
L330:

/*               * CLASSIFY SURFACE TYPE */

    i__ = 0;
    j = 0;
    l = 0;
    n = 0;
    for (k = 1; k <= 3; ++k) {
	kk = (integer) psign_(&one, &ql[k + (k << 2) - 5]);
/* L340: */
	d__2 = (d__1 = ql[k + (k << 2) - 5], abs(d__1));
	i__ = (integer) (i__ + psign_(&one, &d__2));
	j += kk;
	d__2 = (d__1 = ql[k + 11], abs(d__1));
	l = (integer) (l + psign_(&one, &d__2));
/* L400: */
	n = (integer) (n + psign_(&one, &ql[k + (k << 2) - 5]));
    }
    k = (d__1 = j + psign_(&one, &ql[15]), (integer) abs(d__1));
    j = abs(j);

/*        ** SURFACE TYPE MARKER IS IIT ** */
    iit = i__ * 10 + j + k + l * 3 + 1;

    if (n < 0) {
	goto L404;
    } else if (n == 0) {
	goto L402;
    } else {
	goto L410;
    }
L402:
    if (ql[15] >= 0.) {
	goto L410;
    } else {
	goto L404;
    }
L404:
    for (il = 1; il <= 4; ++il) {
	for (ll = 1; ll <= 4; ++ll) {
/* L408: */
	    ql[il + (ll << 2) - 5] = -ql[il + (ll << 2) - 5];
	}
    }

/*        SET IQ TO 1 - NO RECOGNIZABLE SURFACE - AND BRANCH */
/*                  IF SURFACE TYPE SHOULD BE RESET ACCORDING */
/*                  TO SURFACE TYPE MARKER (IIT) */
L410:
    *iq = 1;

    switch (iit) {
	case 1:  goto L1000;
	case 2:  goto L1000;
	case 3:  goto L1000;
	case 4:  goto L520;
	case 5:  goto L520;
	case 6:  goto L1000;
	case 7:  goto L520;
	case 8:  goto L520;
	case 9:  goto L1000;
	case 10:  goto L520;
	case 11:  goto L520;
	case 12:  goto L530;
	case 13:  goto L530;
	case 14:  goto L530;
	case 15:  goto L540;
	case 16:  goto L540;
	case 17:  goto L540;
	case 18:  goto L540;
	case 19:  goto L540;
	case 20:  goto L1000;
	case 21:  goto L550;
	case 22:  goto L560;
	case 23:  goto L1000;
	case 24:  goto L570;
	case 25:  goto L550;
	case 26:  goto L580;
	case 27:  goto L590;
	case 28:  goto L590;
	case 29:  goto L590;
	case 30:  goto L1000;
	case 31:  goto L1000;
	case 32:  goto L610;
	case 33:  goto L620;
	case 34:  goto L630;
	case 35:  goto L1000;
	case 36:  goto L640;
	case 37:  goto L650;
	case 38:  goto L660;
    }

/*        PLANE SURFACE */
L520:
    *iq = 2;
/* Computing 2nd power */
    d__1 = ql[12];
/* Computing 2nd power */
    d__2 = ql[13];
/* Computing 2nd power */
    d__3 = ql[14];
    cc = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    for (il = 1; il <= 4; ++il) {
	ql[il + 11] /= cc;
	ql[(il << 2) - 1] = ql[il + 11];
/* L525: */
    }
    goto L1000;

/*        TWO PARALLEL OR COINCIDENT PLANES */
L530:
    *iq = 3;
    goto L1000;

/*        PARABOLIC CYLINDER */
L540:
    *iq = 4;
    goto L1000;

L550:
    if (l - 1 != 0) {
	goto L552;
    } else {
	goto L600;
    }

/*        TWO INTERSECTING PLANES */
L552:
    *iq = 5;
    goto L1000;

/*        HYPERBOLIC CYLINDER */
L560:
    *iq = 6;
    goto L1000;

L570:
    if (l - 1 != 0) {
	goto L572;
    } else {
	goto L600;
    }

/*        ELLIPTIC CYLINDER */
L572:
    *iq = 7;
    goto L1000;

/*        IMAGINARY ELLIPTIC CYLINDER */
L580:
    *iq = 9;
    goto L1000;

/*        ELLIPTIC PARABOLOID */
L590:
    *iq = 10;
    goto L1000;

/*        HYPERBOLIC PARABOLOID */
L600:
    *iq = 8;
    goto L1000;

/*        HYPERBOLOID OF ONE SHEET */
L610:
    *iq = 11;
    goto L1000;

/*        CONE */
L620:
    *iq = 12;
    goto L1000;

/*        HYPERBOLOID OF TWO SHEETS */
L630:
    *iq = 13;
    goto L1000;

/*        ELLIPSOID */
L640:
    *iq = 14;
    goto L1000;

/*        POINT ELLIPSOID */
L650:
    *iq = 15;
    goto L1000;

/*        IMAGINARY ELLIPSOID */
L660:
    *iq = 16;

/*            ** RESET COEFFICIENTS INTO PROPER ORDER ** */

L1000:
    coeff[1] = ql[0];
    coeff[2] = ql[5];
    coeff[3] = ql[10];
    coeff[4] = ql[15];
    coeff[5] = ql[9];
    coeff[6] = ql[8];
    coeff[7] = ql[4];
    coeff[8] = ql[12];
    coeff[9] = ql[13];
    coeff[10] = ql[14];

    return 0;
} /* qsd_ */

