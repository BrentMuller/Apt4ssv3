/* CLEROR.f -- translated by f2c (version 20100827).
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
    integer errad1[389], errad2[389];
} exerrw_;

#define exerrw_1 exerrw_

struct {
    char errtxt[25152];
} exerrt_;

#define exerrt_1 exerrt_

/* Table of constant values */

static integer c__14 = 14;
static integer c__54 = 54;

/* *** SOURCE FILE : M0004176.V02   *** */



/* .....FORTRAN SUBROUTINE             CLEROR... */

/* PURPOSE      TO PRINT DIAGNOSTICS */

/* LINKAGE      CALL CLEROR(NERR) */

/* ARGUMENTS    NERR       INTEGER ERROR NUMBER */


/* Subroutine */ int cleror_(integer *nerr)
{
    /* Initialized data */

    static char b[120] = "                                                  "
	    "                                                                "
	    "      ";
    static char notext[54] = "THERE IS NO DIAGNOSTIC MESSAGE FOR THIS ERROR "
	    "NUMBER  ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, ii, kk, numb;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer number;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer nummin, nummer, nummax;


/* ...                ...ERROR DIAGNOSTICS */










/* ...     POSITION OF THE CURRENT ERROR NUMBER */

    i__ = 0;
    nummin = 1;
    nummax = 6288;
    number = abs(*nerr);
L10:
    nummer = (nummin + nummax) / 2;
    numb = exerrw_1.errad1[nummer - 1];
    if (i__ > 389) {
	goto L40;
    }
    ++i__;
    if ((i__1 = number - numb) < 0) {
	goto L30;
    } else if (i__1 == 0) {
	goto L60;
    } else {
	goto L20;
    }
L20:
    nummin = nummer + 1;
    goto L10;
L30:
    nummax = nummer - 1;
    goto L10;
L40:
    cform_(notext, b, &c__14, &c__54, (ftnlen)54, (ftnlen)120);
    cprint_(b, (ftnlen)120);
    goto L150;

L60:
    kk = exerrw_1.errad2[nummer - 1];
    if (nummer == 1) {
	ii = 1;
    } else {
	ii = exerrw_1.errad2[nummer - 2] + 1;
    }

    k = 10;
    i__1 = kk;
    for (i__ = ii; i__ <= i__1; ++i__) {
	if (k >= 113) {
	    cprint_(b, (ftnlen)120);
	    k = 10;
	}
	k += 4;
	s_copy(b + (k - 1), exerrt_1.errtxt + (i__ - 1 << 2), (ftnlen)4, (
		ftnlen)4);
/* L70: */
    }
    cprint_(b, (ftnlen)120);

L150:
    return 0;

} /* cleror_ */

