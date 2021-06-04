/* UTILTY.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
} fxcor_;

#define fxcor_1 fxcor_

struct {
    char modfer[6];
} charct_;

#define charct_1 charct_

struct {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

/* Table of constant values */

static integer c__20 = 20;



/*  * UTILTY PACKAGE *  VAX11 VERSION  6.6.85  E.MCLELLAN */


/*  * ABSF * */


/* Subroutine */ int absf_(doublereal *res, doublereal *arg)
{


    *res = abs(*arg);
    return 0;
} /* absf_ */


/*  * ATANF * */

/* Subroutine */ int atanf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double atan(doublereal);



    *res = atan(*arg) / .0174532925f;
    return 0;
} /* atanf_ */


/*  * COSF * */

/* Subroutine */ int cosf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double cos(doublereal);



    *res = cos(*arg * .0174532925f);
    return 0;
} /* cosf_ */


/*  * SINF * */

/* Subroutine */ int sinf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double sin(doublereal);



    *res = sin(*arg * .0174532925f);
    return 0;
} /* sinf_ */


/*  EXPF * */

/* Subroutine */ int expf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double exp(doublereal);



    *res = exp(*arg);
    return 0;
} /* expf_ */


/*  * SQRTF * */

/* Subroutine */ int sqrtf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);



    if (*arg < 0.) {
	error_(&c__20, "SQRTF   ", (ftnlen)8);
	*arg = abs(*arg);
    }
    *res = sqrt(*arg);
    return 0;
} /* sqrtf_ */


/*  * VNORM * */

/*  PURPOSE    NORMALIZE A VECTOR   V3=NORM(VA) */

/*  CALLING SEQUENCE */

/*             CALL VNORM(VA,V3) */

/* Subroutine */ int vnorm_(doublereal *va, doublereal *v3)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





    /* Parameter adjustments */
    --v3;
    --va;

    /* Function Body */
    fxcor_1.vtem = sqrt(va[1] * va[1] + va[2] * va[2] + va[3] * va[3]);
    if (abs(fxcor_1.vtem) < 1e-24f) {
	ifxcor_1.ier = 1;
	for (i__ = 1; i__ <= 3; ++i__) {
	    v3[i__] = va[i__];
/* L25: */
	}

    } else {
	ifxcor_1.ier = 0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    v3[i__] = va[i__] / fxcor_1.vtem;
/* L26: */
	}

    }

    return 0;
} /* vnorm_ */

#undef sinl
#undef cosl



/*  * CROSS * */

/*  PURPOSE    EVALUATE V3=V1 X V2 */

/*  CALLING SEQUENCE */

/*             CALL CROSS(V1,V2,V3) */

/* Subroutine */ int cross_(doublereal *v1, doublereal *v2, doublereal *v3)
{
    static integer i__;
    static doublereal vt[3];



    /* Parameter adjustments */
    --v3;
    --v2;
    --v1;

    /* Function Body */
    vt[0] = v1[2] * v2[3] - v1[3] * v2[2];
    vt[1] = v1[3] * v2[1] - v1[1] * v2[3];
    vt[2] = v1[1] * v2[2] - v1[2] * v2[1];

    for (i__ = 1; i__ <= 3; ++i__) {
	v3[i__] = vt[i__ - 1];
/* L10: */
    }

    return 0;
} /* cross_ */


/*  * CROSSV * */

/*  PURPOSE    EVALUATE CROSS PRODUCT AND NORMALIZE */

/*  CALLING SEQUENCE */

/*             CALL CROSSV(V1,V2,V3) */

/* Subroutine */ int crossv_(doublereal *v1, doublereal *v2, doublereal *v3)
{
    static doublereal vt[3];
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);



    /* Parameter adjustments */
    --v3;
    --v2;
    --v1;

    /* Function Body */
    cross_(&v1[1], &v2[1], vt);

    vnorm_(vt, &v3[1]);

    return 0;
} /* crossv_ */



/*  * DOTV * */

/*  PURPOSE    EVALUATE DOT PRODUCT   RES=V1.V2 */

/*  CALLING SEQUENCE */

/*             CALL DOTV(RES,V1,V2) */

/* Subroutine */ int dotv_(doublereal *res, doublereal *v1, doublereal *v2)
{


    /* Parameter adjustments */
    --v2;
    --v1;

    /* Function Body */
    *res = v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3];

    return 0;
} /* dotv_ */

