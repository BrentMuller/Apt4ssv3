/* DEFEXT.f -- translated by f2c (version 20100827).
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
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0002832.V06   *** */


/* .....FORTRAN SUBROUTINE             DEFEXT...              3/1/68   GK */

/*              FORTRAN SUBROUTINE DEFEXT */

/* PURPOSE      TO PROVIDE A COMMON EXIT TO THE DEFINITION */
/*              REDUCTION SUBROUTINES, TO MOVE THE RESULTANT */
/*              CANONICAL FORM INTO THE RESULT CELLS, PRINT */
/*              ERROR MESSAGES, PRINT THE CANONICAL FORM */
/*              IF THE APPROPRIATE PRINT COMMAND IS IN */
/*              EFFECT AND TO RESTORE THE ARRAY R TO ITS */
/*              INITIAL VALUE. */

/* LINKAGE      CALL DEFEXT (RESULT) */

/* ARGUMENTS    RESULT  AN ARRAY TO CONTAIN THE RESULTANT */
/*                      CANONICAL FORM */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          PRINT */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          UNPACK */

/* Subroutine */ int defext_(doublereal *result)
{
    /* Initialized data */

    static integer inam[74]	/* was [37][2] */ = { 4,6,15,16,18,19,23,24,
	    25,27,29,37,38,43,44,47,48,51,57,58,59,69,70,73,74,75,76,77,79,93,
	    5153,5154,5155,5156,5157,5158,5159,1,2,3,3,4,5,6,6,6,7,8,9,9,10,
	    11,12,13,14,15,16,10,17,17,18,18,18,18,21,21,19,20,20,20,20,20,20,
	    20 };
    static char rnam[8*22] = "APT003  " "APT004  " "APT008  " "APT009  " 
	    "APT012  " "APT016  " "APT023  " "APT027  " "APT106  " "APT013  " 
	    "APT044  " "APT059  " "APT056  " "APT073  " "APT053  " "APT055  " 
	    "APT074  " "APT070  " "APT105  " "APT109  " "APT034  " "DEFEXT??";
    static integer imax = 37;
    static integer max__ = 22;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, in, is1, is2, is3;
    extern /* Subroutine */ int undef_(doublereal *);
    static char rname[8];
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), print_(
	    integer *, doublereal *, integer *), unpack_(doublereal *, 
	    integer *, integer *, integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */





/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --result;

    /* Function Body */
/* IMAX: ANZAHL FEHLERNUMMERN, MAX: ANZAHL ROUTINENEN-NAMEN + 1 '??' */


/* ...     CHECK FOR ERRORS */

    if (idef_1.ierror == 0) {
	goto L20;
    }
    i__1 = imax;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = max__;
	if (idef_1.ierror != inam[i__ - 1]) {
	    goto L810;
	}
	in = inam[i__ + 36];
	goto L820;
L810:
	;
    }
L820:
    s_copy(rname, rnam + (in - 1 << 3), (ftnlen)8, (ftnlen)8);
    error_(&idef_1.ierror, rname, (ftnlen)8);
L10:
    undef_(&result[1]);
    ldef_1.unflag = FALSE_;
    goto L40;

L20:
    if (ldef_1.unflag) {
	goto L10;
    }

/* ...     DEFINITION OK -- CHECK INTFLG, PRNTON AND MOVE R TO RESULT */

    unpack_(&result[1], &is1, &is2, &is3);
/*   MATRIX ? */
    if (is1 == 18) {
	goto L31;
    }
    i__1 = is2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	result[i__] = def_1.r__[i__ - 1];
    }
L31:
    if (! ldef_1.prnton) {
	goto L40;
    }
    if (is1 > 0 && is1 < 27) {
	print_(&c__3, &result[1], &c__1);
    }
L40:
    idef_1.ierror = 0;
    for (i__ = 1; i__ <= 10; ++i__) {
/* L41: */
	def_1.r__[i__ - 1] = 0.f;
    }
    def_1.r__[5] = 1.f;
    return 0;
} /* defext_ */

