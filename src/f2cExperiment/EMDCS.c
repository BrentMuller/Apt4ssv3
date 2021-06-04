/* EMDCS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0008175.V05   *** */

/* Subroutine */ int emdcs_(doublereal *u, doublereal *v, doublereal *data, 
	doublereal *spv, integer *mode)
{
    /* Initialized data */

    static struct {
	doublereal fill_1[6];
	doublereal e_2[6];
	} equiv_24 = { {0}, 2., -2., 2., 0., 0., 0. };

#define fv ((doublereal *)&equiv_24)

    static integer iw[4] = { 2,3,1,2 };

    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[32];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, i1, i2, id;
    static doublereal hi[3], qq, ws[12]	/* was [3][4] */;
#define yz (equiv_0)
    static doublereal qq1, qq2, qq3, qq4;
#define yz1 (equiv_0)
    static integer irn;
    static doublereal xhx, yzs[24]	/* was [3][2][4] */;
    static integer irn1, irn2, nres, imode;

/*  EVALUATION ROUTINE FOR */
/*   "MASTER DIMENSION CONTOUR SURFACE" - MCDS */

/*   PATCH DATA */
/*   OUTPUT: EVALUATION VECTOR */
/*  FUNCTIOS IN V, FV(I,2): 1.DERIVATIVE; FV(I,3): 2.DERIVATIVE; */
/*                                        FV(I,4): 3.DERIVATIVE */
/*  8 CONICS WITH DERIVATIVES (1.,2.,AND 3.) */
/*  6 CONIC DELTAS AND DERIVATIVE ((Y1,Y4,Y3),(Z1,Z4,Z3)) */
/*  3 WEIGHT FUNCTIONS UND DERIVATIVES (W1,W4,W3) */
/*  AUXILIARY ARRAY */
    /* Parameter adjustments */
    spv -= 5;
    --data;

    /* Function Body */

/*    SET OF INTERNAL MODE, IF NECESSARY */
    switch (*mode) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
    }
/*    POINT ONLY */
    imode = 1;
    nres = 1;
    goto L4;
/*    POINT AND TANGENTS */
L1:
    imode = 2;
    nres = 3;
    goto L4;
/*    POINT, TANGENTS AND 2. DERIVATIVE */
L2:
    imode = 3;
    nres = 8;
    goto L4;
/*    POINT, TANGENTS, 2. AND 3. DERIVATIVE */
L3:
    imode = 4;
    nres = 12;
    goto L4;
/*  ZERO SPV */
L4:
    for (i__ = 1; i__ <= 4; ++i__) {
	i__1 = nres;
	for (j = 1; j <= i__1; ++j) {
/* L5: */
	    spv[i__ + (j << 2)] = 0.;
	}
    }
/*  X(U) = XMIN+EXT*U */
    spv[5] = data[31] + data[32] * *u;
/*  DX/DU = EXT */
    spv[9] = data[32];
/*  FUNCTIONS IN V:  FV(1-3,1) = (1-V)**2, V*(1-V), V**2 */
/* L10: */
    fv[2] = *v * *v;
    fv[1] = *v - fv[2];
    fv[0] = 1. - *v - fv[1];
    if (imode == 1) {
	goto L20;
    }
/*  DERIVATIVES IN V:  FV(1-3,2) = 2V-2, 1-2V, 2V */
    fv[5] = *v + *v;
    fv[4] = 1. - fv[5];
    fv[3] = -1. - fv[4];
/*  2. DERIVATIVES OF V-FUNCTIONS  FV(1-3,3) = 2,-2, 2 (CONSTANT) */
/*  3. DERIVATIVES OF V-FUNCTIONS  FV(1-3,4) = 0, 0, 0  (CONSTANT) */

/*  8 CONIC FUNCTIONS */
L20:
    xhx = spv[5] * spv[5];
    irn = 0;
    for (i__ = 1; i__ <= 8; ++i__) {
	irn1 = (integer) data[i__];
	if (irn1 <= irn) {
	    goto L25;
	}
/*  COMPUTE CONIC (1. TIME) */
	irn = irn1;
	id = (integer) data[irn + 9];
	if (data[id] != 1.) {
	    goto L23;
	}
/*  LINE CONIC: Y = YMIN+YEXT*U */
	yz[i__ - 1] = data[id + 1] + data[id + 2] * *u;
	yz[i__ + 7] = data[id + 2];
	yz[i__ + 15] = 0.;
	yz[i__ + 23] = 0.;
	goto L30;
/*  CONICS: Y1,Z1,Y2,Z2,Y3,Z3,Y4,Z4 */
L23:
	yz[i__ - 1] = (sqrt(data[id + 7] * xhx + data[id + 8] * spv[5] + data[
		id + 9]) * data[id + 10] - data[id + 2] * spv[5] - data[id + 
		5]) / data[id + 3];
	if (imode == 1) {
	    goto L30;
	}
/*  CONIC DERIVATIVES TO U:YS= -(A*X+B*Y+D)/(B*X+C*Y+E)*L */
	qq = data[id + 2] * spv[5] + data[id + 3] * yz[i__ - 1] + data[id + 5]
		;
	yz[i__ + 7] = -(data[id + 1] * spv[5] + data[id + 2] * yz[i__ - 1] + 
		data[id + 4]) / qq * spv[9];
	if (imode == 2) {
	    goto L30;
	}
/*  2. DERIVATIVES:YSS= -(A*L**2+2*B*L*YS+C*YS**2)/(B*X+C*Y+E) */
	yz[i__ + 15] = -(spv[9] * (data[id + 1] * spv[9] + data[id + 2] * 2. *
		 yz[i__ + 7]) + data[id + 3] * yz[i__ + 7] * yz[i__ + 7]) / 
		qq;
	if (imode == 3) {
	    goto L30;
	}
/*  3. DERIVATIVES:YSSS= -3*YSS*(B*L+C*YS)/(B*X+C*Y+E) */
	yz[i__ + 23] = yz[i__ + 15] * -3. * (data[id + 2] * spv[9] + data[id 
		+ 3] * yz[i__ + 7]) / qq;
	goto L30;
/*  CONIC ALREADY COMPUTED */
L25:
	i__1 = i__;
	for (i1 = 1; i1 <= i__1; ++i1) {
	    irn2 = (integer) data[i1];
	    if (irn2 != irn1) {
		goto L27;
	    }
	    yz[i__ - 1] = yz[i1 - 1];
	    yz[i__ + 7] = yz[i1 + 7];
	    yz[i__ + 15] = yz[i1 + 15];
	    yz[i__ + 23] = yz[i1 + 23];
	    goto L30;
L27:
	    ;
	}
L30:
	;
    }
/*  CONIC DIFFERENCES */
    i__1 = imode;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*  Y1S = Y1 - Y2 */
	yzs[((i__ << 1) + 1) * 3 - 9] = yz[(i__ << 3) - 8] - yz[(i__ << 3) - 
		6];
/*  Y4S = Y4 - Y2 */
	yzs[((i__ << 1) + 1) * 3 - 8] = yz[(i__ << 3) - 2] - yz[(i__ << 3) - 
		6];
/*  Y3S = Y3 - Y2 */
	yzs[((i__ << 1) + 1) * 3 - 7] = yz[(i__ << 3) - 4] - yz[(i__ << 3) - 
		6];
/*  Z1S = Z1 - Z2 */
	yzs[((i__ << 1) + 2) * 3 - 9] = yz[(i__ << 3) - 7] - yz[(i__ << 3) - 
		5];
/*  Z4S = Z4 - Z2 */
	yzs[((i__ << 1) + 2) * 3 - 8] = yz[(i__ << 3) - 1] - yz[(i__ << 3) - 
		5];
/*  Z3S = Z3 - Z2 */
	yzs[((i__ << 1) + 2) * 3 - 7] = yz[(i__ << 3) - 3] - yz[(i__ << 3) - 
		5];
/*  MOVE Y4, Z4 TO Y2, Z2 */
	yz[(i__ << 3) - 6] = yz[(i__ << 3) - 2];
	yz[(i__ << 3) - 5] = yz[(i__ << 3) - 1];
/* L40: */
    }
/*  COEFFICIENTS OF WEIGHT FUNCTIONS */
    for (i__ = 1; i__ <= 3; ++i__) {
	i1 = iw[i__ - 1];
	i2 = iw[i__];
	ws[i__ - 1] = yzs[i1 - 1] * yzs[i2 + 2] - yzs[i1 + 2] * yzs[i2 - 1];
	if (imode == 1) {
	    goto L50;
	}
/*  1. DERIVATIVE */
	ws[i__ + 2] = yzs[i1 + 5] * yzs[i2 + 2] - yzs[i1 + 8] * yzs[i2 - 1] + 
		yzs[i1 - 1] * yzs[i2 + 8] - yzs[i1 + 2] * yzs[i2 + 5];
	if (imode == 2) {
	    goto L50;
	}
/*  2. DERIVATIVE */
	ws[i__ + 5] = yzs[i1 + 11] * yzs[i2 + 2] - yzs[i1 + 14] * yzs[i2 - 1] 
		+ (yzs[i1 + 5] * yzs[i2 + 8] - yzs[i1 + 8] * yzs[i2 + 5]) * 
		2. + yzs[i1 - 1] * yzs[i2 + 14] - yzs[i1 + 2] * yzs[i2 + 11];
	if (imode == 3) {
	    goto L50;
	}
/*  2. DERIVATIVE */
	ws[i__ + 8] = yzs[i1 + 17] * yzs[i2 + 2] - yzs[i1 + 20] * yzs[i2 - 1] 
		+ (yzs[i1 + 11] * yzs[i2 + 8] - yzs[i1 + 14] * yzs[i2 + 5]) * 
		3. + (yzs[i1 + 5] * yzs[i2 + 14] - yzs[i1 + 8] * yzs[i2 + 11])
		 * 3. + yzs[i1 - 1] * yzs[i2 + 20] - yzs[i1 + 2] * yzs[i2 + 
		17];
L50:
	;
    }
/*  WEIGHTED COORDINATES */
    for (i__ = 1; i__ <= 2; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    qq1 = ws[j - 1] * yz1[i__ + (j + 4 << 1) - 11];
	    spv[i__ + 5] += qq1 * fv[j - 1];
	    if (imode == 1) {
		goto L60;
	    }

	    qq2 = ws[j + 2] * yz1[i__ + (j + 4 << 1) - 11] + ws[j - 1] * yz1[
		    i__ + (j + 8 << 1) - 11];
	    spv[i__ + 9] += qq2 * fv[j - 1];
	    spv[i__ + 13] += qq1 * fv[j + 2];
	    if (imode == 2) {
		goto L60;
	    }

	    qq3 = ws[j + 5] * yz1[i__ + (j + 4 << 1) - 11] + ws[j + 2] * yz1[
		    i__ + (j + 8 << 1) - 11] * 2. + ws[j - 1] * yz1[i__ + (j 
		    + 12 << 1) - 11];
	    spv[i__ + 17] += qq3 * fv[j - 1];
	    spv[i__ + 21] += qq2 * fv[j + 2];
	    spv[i__ + 25] += qq1 * fv[j + 5];
	    if (imode == 3) {
		goto L60;
	    }
	    qq4 = ws[j + 8] * yz1[i__ + (j + 4 << 1) - 11] + ws[j + 5] * yz1[
		    i__ + (j + 8 << 1) - 11] * 3. + ws[j + 2] * yz1[i__ + (j 
		    + 12 << 1) - 11] * 3. + ws[j - 1] * yz1[i__ + (j + 16 << 
		    1) - 11];
	    spv[i__ + 37] += qq4 * fv[j - 1];
	    spv[i__ + 41] += qq3 * fv[j + 2];
	    spv[i__ + 45] += qq2 * fv[j + 5];
	    spv[i__ + 49] += qq1 * fv[j + 8];
L60:
	    ;
	}
    }
/*  WEIGHT FUNCTION */
    for (j = 1; j <= 3; ++j) {
	spv[8] += ws[j - 1] * fv[j - 1];
	if (imode == 1) {
	    goto L65;
	}

	spv[12] += ws[j + 2] * fv[j - 1];
	spv[16] += ws[j - 1] * fv[j + 2];
	if (imode == 2) {
	    goto L65;
	}

	spv[20] += ws[j + 5] * fv[j - 1];
	spv[24] += ws[j + 2] * fv[j + 2];
	spv[28] += ws[j - 1] * fv[j + 5];
	if (imode == 3) {
	    goto L65;
	}

	spv[40] += ws[j + 8] * fv[j - 1];
	spv[44] += ws[j + 5] * fv[j + 2];
	spv[48] += ws[j + 2] * fv[j + 5];
	spv[52] += ws[j - 1] * fv[j + 8];
L65:
	;
    }
/*  COMPUTATION OF (X,Y,Z)-COORDINATES */
    if (imode == 1) {
	goto L71;
    }
    i__1 = nres;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L70: */
	spv[(i__ << 2) + 4] /= spv[8];
    }
L71:
    for (i__ = 2; i__ <= 3; ++i__) {
	spv[i__ + 4] /= spv[8];
	if (imode == 1) {
	    goto L72;
	}
	spv[i__ + 8] = spv[i__ + 8] / spv[8] - spv[i__ + 4] * spv[12];
	spv[i__ + 12] = spv[i__ + 12] / spv[8] - spv[i__ + 4] * spv[16];
	if (imode == 2) {
	    goto L72;
	}
	spv[i__ + 16] = spv[i__ + 16] / spv[8] - spv[i__ + 8] * 2. * spv[12] 
		- spv[i__ + 4] * spv[20];
	spv[i__ + 20] = spv[i__ + 20] / spv[8] - spv[i__ + 8] * spv[16] - spv[
		i__ + 12] * spv[12] - spv[i__ + 4] * spv[24];
	spv[i__ + 24] = spv[i__ + 24] / spv[8] - spv[i__ + 12] * 2. * spv[16] 
		- spv[i__ + 4] * spv[28];
	if (imode == 3) {
	    goto L72;
	}
	spv[i__ + 36] = spv[i__ + 36] / spv[8] - spv[i__ + 16] * 3. * spv[12] 
		- spv[i__ + 8] * 3. * spv[20] - spv[i__ + 4] * spv[40];
	spv[i__ + 40] = spv[i__ + 40] / spv[8] - spv[i__ + 20] * 2. * spv[12] 
		- spv[i__ + 16] * spv[16] - spv[i__ + 12] * spv[20] - spv[i__ 
		+ 8] * 2. * spv[24] - spv[i__ + 4] * spv[44];
	spv[i__ + 44] = spv[i__ + 44] / spv[8] - spv[i__ + 24] * spv[12] - 
		spv[i__ + 20] * 2. * spv[16] - spv[i__ + 12] * 2. * spv[24] - 
		spv[i__ + 8] * spv[28] - spv[i__ + 4] * spv[48];
	spv[i__ + 48] = spv[i__ + 48] / spv[8] - spv[i__ + 24] * 3. * spv[16] 
		- spv[i__ + 12] * 3. * spv[28] - spv[i__ + 4] * spv[52];
L72:
	;
    }

/*  TRANSFORMATION NECESSARY ? */
    if (data[18] == 0.) {
	goto L80;
    }
    i__1 = nres;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == 7) {
	    goto L76;
	}
	if (i__ == 8) {
	    goto L76;
	}
	for (j = 1; j <= 3; ++j) {
/* L74: */
	    hi[j - 1] = spv[j + (i__ << 2)];
	}
	for (j = 1; j <= 3; ++j) {
/* L75: */
	    spv[j + (i__ << 2)] = data[(j << 2) + 15] * hi[0] + data[(j << 2) 
		    + 16] * hi[1] + data[(j << 2) + 17] * hi[2];
	}
L76:
	;
    }

/*  TRANSLATION OF SURFACE POINT COORDINATES */
/* L77: */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L78: */
	spv[i__ + 4] += data[(i__ << 2) + 18];
    }

/*  SURFACE NORMAL NECESSARY ? */
L80:
    if (imode < 2) {
	goto L89;
    }

/*  SURFACE NORMAL */
    spv[29] = spv[10] * spv[15] - spv[11] * spv[14];
    spv[30] = spv[11] * spv[13] - spv[9] * spv[15];
    spv[31] = spv[9] * spv[14] - spv[10] * spv[13];

/*  NORMALIZING OF SURFACE NORMAL */
    qq = sqrt(spv[29] * spv[29] + spv[30] * spv[30] + spv[31] * spv[31]);
    if (qq < 1e-12) {
	goto L89;
    }
    spv[33] = spv[29] / qq;
    spv[34] = spv[30] / qq;
    spv[35] = spv[31] / qq;
    spv[32] = 1.;
    spv[36] = 1.;

/*  SET THE COMPUTATION SIGNAL */
L89:
    i__1 = nres;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == 7) {
	    goto L90;
	}
	if (i__ == 8) {
	    goto L90;
	}
	spv[(i__ << 2) + 4] = 1.;
L90:
	;
    }
    return 0;
} /* emdcs_ */

#undef yz1
#undef yz
#undef fv


