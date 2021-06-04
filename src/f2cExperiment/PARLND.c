/* PARLND.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000647.V01   *** */


/* Subroutine */ int parlnd_(doublereal *p, doublereal *r__, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *t, doublereal *s, integer 
	*mode)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal z__[3], d1, d2, d3, x1, x2, x3, x4, bc, db, dc, br, cr, 
	    dr;
    static integer nz;
    static doublereal bsq, csq, dsq, dst, rsq, temp, scur, tcur;
    extern /* Subroutine */ int gcubic_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);

/* -- MODULAR   PURPOSE IS TO COMPUTE THE CLOSEST APPROACH BETWEEN A */
/* --  PARABOLA IN SPACE AND A SPACE POINT, LINE OR HALF RAY. */
/* --  INPUT' POINT P AND TOOL RAY R( BOTH VECTORS) */
/* --          VECTOR COEFFICIENTS OF PARABOLA A,B AND C (EQUATION IS */
/* --            ( A+ B*S +C*S**2 ) */
/* --          CONTROL VARIABLE  IS MODE.  =-1 MEANS SHORTEST */
/* --          DISTANCE FROM FULL LINE,  =0 MEANS SHORTEST DISTANCE */
/* --          FROM POINT AND =1 MEANS SHORTEST DISTANCE FROM HALF LINE. */
/* -- */
/* --  OUTPUT'  NUMBERS T(FOR LINE) AND S(FOR PARABOLA) WHICH GENERATE THE */
/* --           SOLUTION POINTS ON THE TOOL RAY(P+T*R) AND CURVE(A+ */
/* --           B*S+C*S**2) RESPECTIVELY. */
    /* Parameter adjustments */
    --c__;
    --b;
    --a;
    --r__;
    --p;

    /* Function Body */
    d1 = a[1] - p[1];
    d2 = a[2] - p[2];
    d3 = a[3] - p[3];
    db = d1 * b[1] + d2 * b[2] + d3 * b[3];
    bsq = b[1] * b[1] + b[2] * b[2] + b[3] * b[3];
    dc = d1 * c__[1] + d2 * c__[2] + d3 * c__[3];
    bc = b[1] * c__[1] + b[2] * c__[2] + b[3] * c__[3];
    csq = c__[1] * c__[1] + c__[2] * c__[2] + c__[3] * c__[3];
    dsq = d1 * d1 + d2 * d2 + d3 * d3;
    x1 = db;
    x2 = bsq + dc + dc;
    x3 = bc * 3.f;
    x4 = csq + csq;
    if (*mode != 0) {
	goto L20;
    } else {
	goto L30;
    }
L20:
    rsq = r__[1] * r__[1] + r__[2] * r__[2] + r__[3] * r__[3];
    br = b[1] * r__[1] + b[2] * r__[2] + b[3] * r__[3];
    cr = c__[1] * r__[1] + c__[2] * r__[2] + c__[3] * r__[3];
    dr = d1 * r__[1] + d2 * r__[2] + d3 * r__[3];
    x1 -= dr * br / rsq;
    x2 -= (br * br + dr * 2.f * cr) / rsq;
    x3 -= br * 3.f * cr / rsq;
    x4 -= cr * 2.f * cr / rsq;
L30:
    gcubic_(&x4, &x3, &x2, &x1, z__, &nz);
    if (nz > 1) {
	goto L40;
    }
    *s = z__[0];
    *t = 0.;
    if (*mode == 0) {
	return 0;
    }
    *t = (dr + *s * (br + *s * cr)) / rsq;
    return 0;
L40:
    if (*mode != 0) {
	goto L100;
    } else {
	goto L200;
    }
L100:
    dst = 99999999.f;
    i__1 = nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	scur = z__[i__ - 1];
	tcur = (dr + scur * (br + scur * cr)) / rsq;
	if (tcur < 0.f && *mode == 1) {
	    goto L110;
	}
/* -----X1=DSQ+SCUR*(DB+DB+SCUR*(DC+DC+BSQ+SCUR*(BC+BC+SCUR*CSQ))) */
/* -----X2=DR+SCUR*(BR+SCUR*CR) */
/* -----TEMP=X1-TCUR*(X2+X2-TCUR*RSQ) */
	temp = 1.f - scur;
	temp = abs(temp);
/* ------  DISRCIMINATE AGAINST A NEGATIVE SCUR */
	if (scur < 0.) {
	    temp *= 10;
	}
	if (temp > dst) {
	    goto L110;
	}
	dst = temp;
	*s = scur;
	*t = tcur;
L110:
	;
    }
    return 0;
L200:
    dst = 9999999.f;
    i__1 = nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	scur = z__[i__ - 1];
	temp = dsq + scur * (db + db + scur * (dc + dc + bsq + scur * (bc + 
		bc + scur * csq)));
	if (temp > dst) {
	    goto L210;
	}
	dst = temp;
	*s = scur;
L210:
	;
    }
    *t = 0.;
    return 0;
} /* parlnd_ */

