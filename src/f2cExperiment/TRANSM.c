/* TRANSM.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000736.V04   *** */

/* .....FORTRAN SUBROUTINE  ....TRANSM        3/72                     RN */
/* .... SUBROUTINE                     TRANSM              3/72 */

/*              FORTRAN SUBROUTINE TRANSM */

/* PURPOSE      TO TRANSFORM THE CANONICAL FORMS OF POINTS, */
/*              SPHERES, VECTORS, LINES, PLANES, CIRCLES, */
/*              CYLINDERS, CONES AND QUADRIC SURFACES WHEN A */
/*              REFSYS STATEMENT IS IN EFFECT. */

/* LINKAGE      CALL TRANSM (SO, SI, IR, IN, IE) */

/* ARGUMENTS    SO      ARRAY TO CONTAIN THE RESULTING CANONICAL */
/*                      FORM */
/*              SI      ARRAY CONTAINING THE INPUT CANONICAL FORM */
/*              IN      INTEGER CONTAINING THE NUMBER OF WORDS */
/*                      IN THE CANONICAL FORM */
/*              IR      INTEGER CONTAINING THE SURFACE INDICATOR */
/*                      IR=1 QUADRICS (IN=10) */
/*                        =2 POINTS AND SPHERES (IN=3) */
/*                        =3 VECTORS (IN=3) */
/*                        =4 LINES AND PLANES (IN=4) */
/*                        =5 CIRCLES, CONES AND CYLINDERS (IN=7) */
/*              IE      INTEGER WHICH INDICATES TRANSFORMATION */
/*                      DIRECTION AND ERROR CODE NUMBER WHEN A */
/*                      LINE OR CIRCLE IS TO BE CHECKED TO BE */
/*                      SURE IT IS A VERTICAL PLANE OR CYLINDER */
/*                      RESPECTIVELY. */
/*                      IE =-1 TRANSFORM LOCAL TO BASE COORDINATE */
/*                           SYSTEM */
/*                      IE = O TRANSFORM BASE TO LOCAL COORDINATE */
/*                           SYSTEM */

/* SUBSIDIARIES TYPE                ENTRY */

/* Subroutine */ int transm_(doublereal *so, doublereal *si, integer *ir, 
	integer *in, integer *ie)
{
    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[16], equiv_1[16], equiv_2[16], equiv_3[16];

    /* Local variables */
    static integer i__, j, m;
#define t (equiv_0)
#define t1 (equiv_1)
#define t2 (equiv_2)
#define t3 (equiv_3)
#define xt (equiv_0)
    static integer m11;
#define xt1 (equiv_1)
#define xt2 (equiv_2)
#define xt3 (equiv_3)
    static integer mode, isub, isize;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */



/* ...  ISHR16.INC HAS BEEN OMITTED, AS USEAGE OF I,J, */
/* ...  M & M11 SEEMS TO BE LOCAL. */

/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...     DETERMINE WHETHER INPUT SURFACE HAS BEEN DEFINED */

    /* Parameter adjustments */
    --si;
    --so;

    /* Function Body */
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	t[i__ - 1] = si[i__];
    }

/* ...     IF REFSYS NOT IN EFFECT MOVE ARRAY TO OUTPUT ARRAY */


    if (! ldef_1.refmot) {
	goto L20;
    }
    if (! ldef_1.refflg) {
	goto L20;
    }
    j = 0;
    if (si[j] >= 2.1e7f || si[j] < 999999.f) {
	goto L20;
    }
    unpack_(&si[1], &mode, &isize, &isub);
    if (mode <= 0 || mode > 20) {
	goto L20;
    }
    if (*ir == 3 && mode != 20) {
	goto L20;
    }
    goto L90;
L20:
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	so[i__] = t[i__ - 1];
    }
/* L999: */
    return 0;

/* ...     SET M=1 FOR BASE TO LOCAL OR M=2 FOR LOCAL TO BASE AND */
/* ...     TRANSFORM CANONICAL FORMS */

L90:
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L95: */
	t1[i__ - 1] = t[i__ - 1];
    }
    m = knumbr_1.k1;
    if (*ie < 0) {
	m = knumbr_1.k2;
    }
    m11 = knumbr_1.k3 - m;
    switch (*ir) {
	case 1:  goto L100;
	case 2:  goto L300;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L300;
    }

/* ...     QUADRIC CANONICAL FORM TRANSFORMATION */

L100:
    t[1] = t1[6];
    t[2] = t1[5];
    t[3] = t1[7];
    t[4] = t1[6];
    t[5] = t1[1];
    t[6] = t1[4];
    t[7] = t1[8];
    t[8] = t1[5];
    t[9] = t1[4];
    t[10] = t1[2];
    t[11] = t1[9];
    t[12] = t1[7];
    t[13] = t1[8];
    t[14] = t1[9];
    t[15] = t1[3];
    for (i__ = 1; i__ <= 12; ++i__) {
/* L200: */
	t3[i__ - 1] = def_1.a[i__ + m11 * 12 - 13];
    }
    t3[12] = 0.f;
    t3[13] = 0.f;
    t3[14] = 0.f;
    t3[15] = 1.f;


    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    xt1[i__ + (j << 2) - 5] = 0.f;
	    for (m = 1; m <= 4; ++m) {
/* L250: */
		xt1[i__ + (j << 2) - 5] += xt[m + (j << 2) - 5] * xt3[i__ + (
			m << 2) - 5];
	    }
	}
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L260: */
	    xt2[j + (i__ << 2) - 5] = xt3[i__ + (j << 2) - 5];
	}
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    xt[i__ + (j << 2) - 5] = 0.f;
	    for (m = 1; m <= 4; ++m) {
/* L270: */
		xt[i__ + (j << 2) - 5] += xt2[m + (j << 2) - 5] * xt1[i__ + (
			m << 2) - 5];
	    }
	}
    }
/* L271: */
    t[4] = t[6];
    t[6] = t[1];
    t[1] = t[5];
    t[5] = t[2];
    t[2] = t[10];
    t[8] = t[7];
    t[7] = t[3];
    t[3] = t[15];
    t[9] = t[11];
    goto L20;

/* ...     VECTOR CANONICAL FORM TRANSFORMATION */

L300:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L310: */
	t[i__ - 1] = def_1.a[(i__ << 2) - 3 + m * 12 - 13] * t1[0] + def_1.a[(
		i__ << 2) - 2 + m * 12 - 13] * t1[1] + def_1.a[(i__ << 2) - 1 
		+ m * 12 - 13] * t1[2];
    }
    switch (*ir) {
	case 1:  goto L20;
	case 2:  goto L320;
	case 3:  goto L20;
	case 4:  goto L20;
	case 5:  goto L320;
    }

/* ...     FINISH TRANSFORMATION FOR POINTS */

L320:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L330: */
	t[i__ - 1] += def_1.a[(i__ << 2) + m * 12 - 13];
    }
    if (*ir != knumbr_1.k5) {
	goto L20;
    }

/* ...     FINISH TRANSFORMATION FOR CIRCLES */

    for (i__ = 4; i__ <= 6; ++i__) {
/* L340: */
	t[i__ - 1] = def_1.a[(i__ << 2) - 15 + m * 12 - 13] * t1[3] + def_1.a[
		(i__ << 2) - 14 + m * 12 - 13] * t1[4] + def_1.a[(i__ << 2) - 
		13 + m * 12 - 13] * t1[5];
    }
    goto L20;

/* ...     TRANSFORM NORMAL DISTANCE FOR LINES */

L400:
    t[3] = t1[3] - t1[0] * def_1.a[m11 * 12 - 9] - t1[1] * def_1.a[m11 * 12 - 
	    5] - t1[2] * def_1.a[m11 * 12 - 1];
    goto L300;
} /* transm_ */

#undef xt3
#undef xt2
#undef xt1
#undef xt
#undef t3
#undef t2
#undef t1
#undef t



/* .....FORTRAN SUBROUTINE  ....TRANSF        3/72                     RN */
/* .... SUBROUTINE                    TRANSF               3/72 */

/*              FORTRAN SUBROUTINE TRANSF */

/* PURPOSE      TO TRANSFORM THE CANONICAL FORMS OF POINTS, */
/*              SPHERES, VECTORS, LINES, PLANES, CIRCLES, */
/*              CYLINDERS, CONES AND QUADRIC SURFACES WHEN A */
/*              REFSYS STATEMENT IS IN EFFECT. */

/* LINKAGE      CALL TRANSF (SO, SI, IR, IN, IE) */

/* ARGUMENTS    SO      ARRAY TO CONTAIN THE RESULTING CANONICAL */
/*                      FORM */
/*              SI      ARRAY CONTAINING THE INPUT CANONICAL FORM */
/*              IN      INTEGER CONTAINING THE NUMBER OF WORDS */
/*                      IN THE CANONICAL FORM */
/*              IR      INTEGER CONTAINING THE SURFACE INDICATOR */
/*                      IR=1 QUADRICS (IN=10) */
/*                        =2 POINTS AND SPHERES (IN=3) */
/*                        =3 VECTORS (IN=3) */
/*                        =4 LINES AND PLANES (IN=4) */
/*                        =5 CIRCLES, CONES AND CYLINDERS (IN=7) */
/*              IE      INTEGER WHICH INDICATES TRANSFORMATION */
/*                      DIRECTION AND ERROR CODE NUMBER WHEN A */
/*                      LINE OR CIRCLE IS TO BE CHECKED TO BE */
/*                      SURE IT IS A VERTICAL PLANE OR CYLINDER */
/*                      RESPECTIVELY. */
/*                      IE =-1 TRANSFORM LOCAL TO BASE COORDINATE */
/*                           SYSTEM */
/*                      IE = O TRANSFORM BASE TO LOCAL COORDINATE */
/*                           SYSTEM */

/* SUBSIDIARIES TYPE                ENTRY */

/* Subroutine */ int transf_(doublereal *so, doublereal *si, integer *ir, 
	integer *in, integer *ie)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m;
    static doublereal t[16], t1[16], t2[16], t3[16];
    static integer m11;
    extern /* Subroutine */ int apt076_(doublereal *, doublereal *, 
	    doublereal *, integer *), apt086_(doublereal *, doublereal *, 
	    integer *);
    extern logical ckdef_(doublereal *), cirdef_(doublereal *, integer *), 
	    lindef_(doublereal *, integer *);





/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */



/* ...  ISHR16.INC HAS BEEN OMITTED, AS USEAGE OF I,J, */
/* ...  M & M11 SEEMS TO BE LOCAL. */

/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --si;
    --so;

    /* Function Body */
    if (*ie < 0) {
	goto L5;
    }
    ldef_1.unflag = ckdef_(&si[1]);
    if (ldef_1.unflag) {
	goto L999;
    }

/* ...     DETERMINE WHETHER INPUT SURFACE HAS BEEN DEFINED */

L5:
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
	t[i__ - 1] = si[i__];
/* L10: */
    }

/* ...     IF REFSYS NOT IN EFFECT MOVE ARRAY TO OUTPUT ARRAY */

/* ---    GEOMETRIC MODE IS IN EFFECT */
    if (ldef_1.refflg) {
	goto L90;
    }
L20:
    if (*ie < 0) {
	goto L61;
    }
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
	so[i__] = t[i__ - 1];
/* L31: */
    }
    if (*ie == 0) {
	goto L999;
    }
    switch (*ir) {
	case 1:  goto L999;
	case 2:  goto L999;
	case 3:  goto L999;
	case 4:  goto L41;
	case 5:  goto L51;
    }
L41:
    ldef_1.unflag = lindef_(t, ie);
    goto L999;
L51:
    ldef_1.unflag = cirdef_(t, ie);
    goto L999;
L61:
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
	def_1.r__[i__ - 1] = t[i__ - 1];
/* L71: */
    }
    goto L999;
L999:
    return 0;

/* ...     SET M=1 FOR BASE TO LOCAL OR M=2 FOR LOCAL TO BASE AND */
/* ...     TRANSFORM CANONICAL FORMS */

L90:
    i__1 = *in;
    for (i__ = 1; i__ <= i__1; ++i__) {
	t1[i__ - 1] = t[i__ - 1];
/* L95: */
    }
    m = knumbr_1.k1;
    if (*ie < 0) {
	m = knumbr_1.k2;
    }
    m11 = knumbr_1.k3 - m;
    switch (*ir) {
	case 1:  goto L100;
	case 2:  goto L300;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L300;
    }

/* ...     QUADRIC CANONICAL FORM TRANSFORMATION */

L100:
    t[1] = t1[6];
    t[2] = t1[5];
    t[3] = t1[7];
    t[4] = t1[6];
    t[5] = t1[1];
    t[6] = t1[4];
    t[7] = t1[8];
    t[8] = t1[5];
    t[9] = t1[4];
    t[10] = t1[2];
    t[11] = t1[9];
    t[12] = t1[7];
    t[13] = t1[8];
    t[14] = t1[9];
    t[15] = t1[3];
    for (i__ = 1; i__ <= 12; ++i__) {
	t3[i__ - 1] = def_1.a[i__ + m11 * 12 - 13];
/* L200: */
    }
    t3[12] = 0.f;
    t3[13] = 0.f;
    t3[14] = 0.f;
    t3[15] = 1.f;

/* ---    GEOMETRIC TRANSFORM CASE */
    apt076_(t1, t, t3, &knumbr_1.k4);
    apt086_(t2, t3, &knumbr_1.k4);
    apt076_(t, t2, t1, &knumbr_1.k4);

    t[4] = t[6];
    t[6] = t[1];
    t[1] = t[5];
    t[5] = t[2];
    t[2] = t[10];
    t[8] = t[7];
    t[7] = t[3];
    t[3] = t[15];
    t[9] = t[11];
    goto L20;

/* ...     VECTOR CANONICAL FORM TRANSFORMATION */

L300:
    for (i__ = 1; i__ <= 3; ++i__) {
	t[i__ - 1] = def_1.a[(i__ << 2) - 3 + m * 12 - 13] * t1[0] + def_1.a[(
		i__ << 2) - 2 + m * 12 - 13] * t1[1] + def_1.a[(i__ << 2) - 1 
		+ m * 12 - 13] * t1[2];
/* L310: */
    }
    switch (*ir) {
	case 1:  goto L20;
	case 2:  goto L320;
	case 3:  goto L20;
	case 4:  goto L20;
	case 5:  goto L320;
    }

/* ...     FINISH TRANSFORMATION FOR POINTS */

L320:
    for (i__ = 1; i__ <= 3; ++i__) {
	t[i__ - 1] += def_1.a[(i__ << 2) + m * 12 - 13];
/* L330: */
    }
    if (*ir != knumbr_1.k5) {
	goto L20;
    }

/* ...     FINISH TRANSFORMATION FOR CIRCLES */

    for (i__ = 4; i__ <= 6; ++i__) {
	t[i__ - 1] = def_1.a[(i__ << 2) - 15 + m * 12 - 13] * t1[3] + def_1.a[
		(i__ << 2) - 14 + m * 12 - 13] * t1[4] + def_1.a[(i__ << 2) - 
		13 + m * 12 - 13] * t1[5];
/* L340: */
    }
    goto L20;

/* ...     TRANSFORM NORMAL DISTANCE FOR LINES */

L400:
    t[3] = t1[3] - t1[0] * def_1.a[m11 * 12 - 9] - t1[1] * def_1.a[m11 * 12 - 
	    5] - t1[2] * def_1.a[m11 * 12 - 1];
    goto L300;
} /* transf_ */

