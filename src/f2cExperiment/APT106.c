/* APT106.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : M0000845.V03   *** */

/* ...  FORTRAN SUBROUTINE     APT106    6/69      SR */

/* PURPOSE      TO COMPUTE AND STORE THE CANONICAL FORM */
/*              OF THE NTH POINT OF A PATERN */

/* LINKAGE      CALL APT106(RESULT,PAT,RN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE POINT */
/*              PAT     ARRAY CONTAINING THE I.C.F. OF THE PATERN */
/*              RN      NUMBER OF THE DESIRED POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT094 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          NPAT */

/* Subroutine */ int apt106_(doublereal *result, doublereal *pat, doublereal *
	rn)
{
    /* Local variables */
    static integer n;
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int npat_(doublereal *, integer *), apt094_(
	    integer *, doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int defext_(doublereal *);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */






/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --pat;
    --result;

    /* Function Body */
    if (ckdef_(&pat[1])) {
	goto L90;
    }

/*              MOVE THE EXTERNAL CANONICAL FORM TO BCANON */

    apt094_(&c__2, &pat[1], bcanon);
    if (ckdef_(&pat[1])) {
	goto L90;
    }

/*              CHECK TO SEE THAT N IS LESS THAN OR EQUAL TO */
/*              THE NUMBER OF POINTS IN THIS PATERN */

    if (*rn > bcanon[3]) {
	goto L95;
    }
    n = (integer) (*rn + znumbr_1.z1em5);

/*          DETERMINE AND STORE THE COORDINATES OF THE POINT */

    npat_(def_1.r__, &n);
L10:
    defext_(&result[1]);

    return 0;

/*          REFERENCED PATERN HAS NOT BEEN PREVIOUSLY CORRECTLY DEFINED */

L90:
    idef_1.ierror = 37;
    goto L10;

/*          THE NUMBER OF THE REQUESTED POINT IS GREATER THAN THE */
/*          NUMBER OF POINTS IN THE PATERN */

L95:
    idef_1.ierror = 38;
    goto L10;
} /* apt106_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


