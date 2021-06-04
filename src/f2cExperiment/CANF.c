/* CANF.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__0 = 0;
static integer c__39 = 39;
static integer c__40 = 40;
static integer c__41 = 41;

/* *** SOURCE FILE : M0002880.V03   *** */

/* .....FORTRAN SUBROUTINE             CANF....             16.10.78  EC */

/*              FORTRAN SUBROUTINE CANF */

/* ZWECK        EXTRAKTION VON KANONISCHEN ELEMENTEN */

/* VERKNUEPFUNG CALL CANF (RES, ORT, ARG) */

/* ARGUMENTE    RES     REAL VARIABLE FUER RESULTAT */
/*              ORT     STELLENANGABE IN DER KANONISCHEN FORM */
/*              ARG     FELD MIT DER KANONISCHEN FORM */

/* UNTEPROGR.:  TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNPACK */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          TRANSF */
/* Subroutine */ int canf_(doublereal *res, doublereal *ort, doublereal *arg)
{
    /* Initialized data */

    static integer ir[20] = { 4,4,5,5,2,1,1,1,5,1,0,0,0,1,0,0,0,0,2,3 };

    static doublereal a[12];
    static integer i__, mode, isub;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int undef_(doublereal *);
    static integer isize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), unpack_(
	    doublereal *, integer *, integer *, integer *), transf_(
	    doublereal *, doublereal *, integer *, integer *, integer *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
/* ...     CHECK OB KANONISCHE FORM DEFINIERT */
    if (ckdef_(&arg[1])) {
	goto L20;
    }
/* ...     KONTROLLE OB KANONISCHE FORM LANG GENUG */
    i__ = (integer) (*ort);
    unpack_(&arg[1], &mode, &isize, &isub);
    if (i__ <= 0) {
	goto L22;
    }
    if (i__ > isize) {
	goto L21;
    }
/* ...     KONTROLLE OB TRANSFORMIERT WERDEN KANN UND TRANSFORMATION */
    if (mode == 18) {
	goto L10;
    }
    if (mode <= 0 || mode > 20 || ir[mode - 1] == 0) {
	goto L20;
    }
    transf_(a, &arg[1], &ir[mode - 1], &isize, &c__0);
    res[1] = a[i__ - 1];
    return 0;
/*   MATRIX-ABGRIFF */
L10:
    res[1] = arg[i__];
    return 0;

/* ...   'GEOMETRIE NICHT DEFINIERT' */
L20:
    error_(&c__39, "CANF    ", (ftnlen)8);
    goto L23;
/* ...   'KANONISCHE FORM ZU KURZ FUER INDEX ODER INDEX NICHT DEFINIERT' */
L21:
    error_(&c__40, "CANF    ", (ftnlen)8);
    goto L23;
/* ...   'INDEX KLEINER ODER GLEICH NULL' */
L22:
    error_(&c__41, "CANF    ", (ftnlen)8);
L23:
    undef_(&res[1]);
    return 0;
} /* canf_ */

