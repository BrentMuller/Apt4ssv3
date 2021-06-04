/* BALTWO.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c_n3 = -3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0001045.W01   *** */

/* Subroutine */ int baltwo_(doublereal *r__, doublereal *side, doublereal *
	tc, doublereal *rad, doublereal *td, doublereal *u, doublereal *v, 
	doublereal *a, integer *maxrep, doublereal *tol, integer *irr)
{
    /* Initialized data */

    static doublereal smal = .001;
    static doublereal smal1 = 1e-4;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal w, ca[3], da, cu[3], cv[3], du, dv, ps[3], su[3], sv[3],
	     uv;
    extern /* Subroutine */ int bad_();
    static doublereal psq, suv;
    extern doublereal det3_(doublereal *, doublereal *, doublereal *);
    static doublereal coef[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer nits;
    static doublereal husq, hvsq, susq, svsq, discr;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

    /* Parameter adjustments */
    --td;
    --tc;
    --r__;

    /* Function Body */
/*           /-PURPOSE OF ROUTINE IS TO USE NEWTON RHAPSON METHOD */
/*           /-TO MOVE BALL CUTTER INTO CONTACT WITH 2ND ORDER EXPANSION */
/*           /-SURFACE ABOUT A POINT. */
/*           /-INPUT */
/*           /-R SURFACE POINT, FIRST AND SECOND DERIVATIVES */
/*           /-TC,TD BALL CENTER, DIRECTION OF MOVEMENT */
/*           /-RAD IS  RADIUS OF BALL */
/*           /- SIDE IS 1 IF RU X RV GIVES CUTTER SIDE OF SURF, -1 OTHERW */
/*           /- MAXREP IS MAXIMUM NUMBER OF REPETITIIONS OF NEWNTON METHO */
/*           /- TOL IS THE TOLERANCE SPECIFICATION FOR STOPPING ITERATION */

/*           /- INPUT-OUTPUT */
/*           /-A IS DISTANCE CUTTER SHOULD MOVE IN TD DIRECTION */
/*           /-U,V ARE SURFACE COORDINATES DESCRIBING CONTACT */

    nits = 0;
L10:
    ++nits;
    if (nits > *maxrep) {
	goto L999;
    }
/*           /-EVALUATE QUANTITIES WHICH DEPEND ON CURRENT A,U,V */
    husq = *u * *u / 2.f;
    uv = *u * *v;
    hvsq = *v * *v / 2.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	ps[i__ - 1] = tc[i__] + *a * td[i__] - (r__[i__] + *u * r__[i__ + 4] 
		+ *v * r__[i__ + 8] + husq * r__[i__ + 12] + uv * r__[i__ + 
		16] + hvsq * r__[i__ + 20]);
	su[i__ - 1] = r__[i__ + 4] + *u * r__[i__ + 12] + *v * r__[i__ + 16];
	sv[i__ - 1] = r__[i__ + 8] + *u * r__[i__ + 16] + *v * r__[i__ + 20];
/* L20: */
    }

/*           /-USE SURFACE REPRESENTATION BY TAYLOR 2ND ORDER METHOD */
/*           /-S(U,V)=R+U*RU+V*RV+HUSQ*RUU+UV*RUV+HVSQ*RVV */
/*           /-NEWTON RHAPSON ITERATION IS USED TO SOLVE 3 EQNS IN 3 UNKN */
/*           /-F(A,U,V)=(TC+A*TD-S(U,V))**2-RAD**2=0 */
/*           /-G(A,U,V)=(TC+A*TD-S(U,V),SU)=0 */
/*           /-H(A,U,V)=(TC+A*TD-S(U,V),SV)=0 */
/*           /-CHANGES IN A,U,V NAMELY DA,DU,DV ARE FOUND BY THE FOLLOWIN */
/*           /- 0-F=DA*FA+DU*FU+DV*FV */
/*           /- 0-G=DA*GA+DU*GU+DV*GV */
/*           /- 0-H=DA*HA+DU*HU+DV*HV */
/*           /- CA(1)=FA, CA(2)=GA, CA(3)=HA, CU(1)=FU ETC. */
/*           /- COEF(1)=-F, COEF(2)=-G, COEF(3)=-H */

    dotf_(ca, ps, &td[1]);
    ca[0] *= 2.f;
    dotf_(cu, ps, su);
    cu[0] *= -2.f;
    dotf_(cv, ps, sv);
    cv[0] *= -2.f;

    dotf_(&ca[1], &td[1], su);
    dotf_(&susq, su, su);
    dotf_(&cu[1], ps, &r__[13]);
    cu[1] = -susq + cu[1];
    dotf_(&suv, su, sv);
    dotf_(&cv[1], ps, &r__[17]);
    cv[1] = -suv + cv[1];

    dotf_(&ca[2], &td[1], sv);
    cu[2] = cv[1];
    dotf_(&svsq, sv, sv);
    dotf_(&cv[2], ps, &r__[21]);
    cv[2] -= svsq;

    dotf_(&psq, ps, ps);
/* Computing 2nd power */
    d__1 = *rad;
    coef[0] = -(psq - d__1 * d__1);
/* ----     CALL DOTF(COEF(2),PS,SU) */
    coef[1] = cu[0] / 2.f;
/* ----     CALL DOTF(COEF(3),PS,SV) */
    coef[2] = cv[0] / 2.f;
/*           /-3X3 EQN IS READY, FIRST CHECK DISCRIMINANT */
    discr = det3_(ca, cu, cv);
    if (abs(discr) > smal) {
	goto L50;
    }
/*           /-DISCRIMINANT TOO SMALL, CHANGE A,U,V AND TRY AGAIN */
    *a = *a * .9f + smal1;
    *u = *u * .9f + smal1;
    *v = *v * .9f + smal1;
    goto L10;

L50:
/*           /-SOLVE FOR DA,DU,DV */
    da = det3_(coef, cu, cv) / discr;
    du = det3_(ca, coef, cv) / discr;
    dv = det3_(ca, cu, coef) / discr;
    if (ibugg_1.ibug != 11) {
	goto L9991;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER BALTWO", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c_n3, &c__1, "COEF", coef, (ftnlen)4);
L9991:
    *a += da;
    *u += du;
    *v += dv;
    w = abs(coef[0]);
    w = sqrt(w);
    w = w + abs(coef[1]) + abs(coef[2]);
    if (w > *tol) {
	goto L10;
    }
/* L100: */

L999:
    return 0;
} /* baltwo_ */

