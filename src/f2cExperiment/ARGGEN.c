/* ARGGEN.f -- translated by f2c (version 20100827).
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
    integer stklst[300];
} stklst_;

#define stklst_1 stklst_

/* *** SOURCE FILE : M0006617.V01   *** */


/*              FORTRAN SUBROUTINE ARGGEN */

/* LINKAGE      SUBROUTINE ARGGEN */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    RECOG */

/* Subroutine */ int arggen_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, ii;
    extern /* Subroutine */ int argcvt_(integer *);
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)



/*        2.    STACK AND POINTER STORAGE */

/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */
/* * */
/* PURPOSE      OUTPUTS ENTIRE CONTENTS OF THE ARGUMENT */
/*              STACK (ARGSTK) TO THE I.L. INTERNAL RECORD */
/*              IMAGE (ILFILE). */
/* NOTES        THE ARGUMENTS ARE PLACED IN ILFILE IN THE */
/*              REVERSE ORDER IN WHICH THEY ARE STORED IN */
/*              ARGSTK. */
/* ** */
/* ...     FETCH ITEMS FROM ARGSTK IN REVERSE ORDER TO THAT IN WHICH */
/* ...     THEY WERE INSERTED, AND OUTPUT TO ILFILE USING ARGCVT. */

    i__1 = *argtop;
    for (ii = 1; ii <= i__1; ++ii) {
	i__ = *argtop - ii + 1;
	k = argstk[i__ - 1];
/* L1: */
	argcvt_(&k);
    }

/* ...     SET ARGTOP TO ZERO (I.E. CLEAR ARGSTK) AND RETURN */

    *argtop = 0;
    return 0;
} /* arggen_ */

#undef argtop
#undef argstk


