/* GSURF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000921.V02   *** */

/* ...  FORTRAN SUBROUTINE GSURF                   7/70      RW */

/* PURPOSE      CONTROL ROUTINE TO TRANSFORM APT SURFACE CANONICAL FORMS */
/*              INTO QUADRIC EQUATION COEFFICIENTS. */

/* CALLING SEQUENCE    CALL GSURF(COEBUF,CANON,MODE,ISIZ,ERRFLG) */

/* ARGUMENTS    COEBUF        ARRAY TO CONTAIN QUADRIC EQUATION COEF. */

/*              CANON         INPUT ARRAY CONTAINING CANONICAL FORM */

/*              MODE          MODE OF CANONICAL FORM */

/*              ISIZ          SIZE OF CANONICAL FORM */

/*              ERRFLG        LOGICAL FLAG WHICH IS RETURNED AS TRUE ONLY */
/*                            IF MODE IS NOT A QUADRIC SURFACE. */

/* CALLED BY    APT102 */
/*              APT104 */

/* SUBSIDIARIES TYPE              ENTRY */
/*              SUBROUTINE        GCIRCL */
/*              SUBROUTINE        GCONE */
/*              SUBROUTINE        GCYL */
/*              SUBROUTINE        GPLANE */
/*              SUBROUTINE        GQUAD */
/*              SUBROUTINE        GSPHER */
/*              SUBROUTINE        TRANSF */

/* RESTRICTIONS NONE */

/* DIAGNOSTICS  NONE */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gsurf_(doublereal *coebuf, doublereal *canon, integer *
	mode, integer *isiz, logical *errflg)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m, ir;
    extern /* Subroutine */ int gcyl_(doublereal *, doublereal *), gcone_(
	    doublereal *, doublereal *), gquad_(doublereal *, doublereal *), 
	    gcircl_(doublereal *, doublereal *), gplane_(doublereal *, 
	    doublereal *);
    static doublereal refsrf[10];
    extern /* Subroutine */ int gspher_(doublereal *, doublereal *), transf_(
	    doublereal *, doublereal *, integer *, integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --canon;
    --coebuf;

    /* Function Body */
    i__1 = *isiz;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	refsrf[i__ - 1] = canon[i__];
    }
    *errflg = FALSE_;

/*      MODE = 1   2   3   4   5   6   7   8   9 10  11  12  13  14  15 */
    switch (*mode) {
	case 1:  goto L101;
	case 2:  goto L101;
	case 3:  goto L103;
	case 4:  goto L104;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L106;
	case 8:  goto L106;
	case 9:  goto L109;
	case 10:  goto L106;
	case 11:  goto L130;
	case 12:  goto L130;
	case 13:  goto L130;
	case 14:  goto L106;
	case 15:  goto L130;
	case 16:  goto L130;
	case 17:  goto L130;
	case 18:  goto L130;
	case 19:  goto L130;
	case 20:  goto L130;
	case 21:  goto L130;
	case 22:  goto L130;
	case 23:  goto L130;
	case 24:  goto L130;
	case 25:  goto L130;
	case 26:  goto L130;
    }
/*      MODE = 16 17  18  19  20  21  22  23  24  25  26 */

/* ...  A LINE OR PLANE. */

L10:
    gplane_(refsrf, &coebuf[1]);
    goto L100;

/* ...  A CYLINDER. */

L30:
    gcyl_(refsrf, &coebuf[1]);
    goto L100;

/* ...  A CIRCLE. */

L40:
    gcircl_(refsrf, &coebuf[1]);
    goto L100;

/* ...  A SPHERE. */

L50:
    gspher_(refsrf, &coebuf[1]);
    goto L100;

/* ...  A HYPERBOLA, LCONIC, ELLIPSE, GCONIC, OR QUADRIC. */

L60:
    gquad_(refsrf, &coebuf[1]);
    goto L100;

/* ...  A CONE. */

L90:
    gcone_(refsrf, &coebuf[1]);
L100:
    return 0;

/* ...  TRANSFORM TO LOCAL COORDINATE SYSTEM IF REFSYS IN EFFECT. */

L101:
    ir = knumbr_1.k4;
    m = 0;
    goto L110;
L103:
    ir = knumbr_1.k5;
    m = 1;
    goto L110;
L104:
    ir = knumbr_1.k5;
    m = 2;
    goto L110;
L105:
    ir = knumbr_1.k2;
    m = 3;
    goto L110;
L106:
    ir = knumbr_1.k1;
    m = 4;
    goto L110;
L109:
    ir = knumbr_1.k5;
    m = 5;
L110:
    if (ldef_1.refflg) {
	transf_(refsrf, &canon[1], &ir, isiz, &knumbr_1.k0);
    }
    switch (m) {
	case 0: goto L10;
	case 1: goto L30;
	case 2: goto L40;
	case 3: goto L50;
	case 4: goto L60;
	case 5: goto L90;
    }

L130:
    *errflg = TRUE_;
    goto L100;
} /* gsurf_ */

