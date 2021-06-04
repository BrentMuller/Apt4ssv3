/* APT310.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__6 = 6;

/* *** SOURCE FILE : M0000426.V02   *** */

/* .....FORTRAN SUBROUTINE                   APT310 */
/* PURPOSE      TO COMPARE A BCD WORD WITH THE CONTENTS OF A */
/*              HOLERITH ARRAY TO DETERMINE THE PROCESSING TO */
/*              BE PERFORMED. */
/* LINKAGE      CALL APT310  (RESULT, BCD) */
/* ARGUMENTS    RESULT    INTEGER VARIABLE TO CONTAIN THE */
/*                        SUBSCRIPT OF THE HOLERITH ARRAY */
/*                        INDICATING THE ELEMENT OF THE ARRAY */
/*                        THAT MATCHES THE INPUT WORD. */
/*              BCD       THE INPUT WORD TO BE COMPARED WITH */
/*                        THE HOLERITH ARRAY. */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt310_(integer *result, doublereal *bcd)
{
    /* Initialized data */

    static char holarr[6*25] = "CAMERA" "CLDATA" "AERR  " "COPY  " "DYNDMP" 
	    "FINI  " "INDEX " "INSERT" "LETTER" "MULTAX" "OVPLOT" "PARTNO" 
	    "PLOT  " "PPRINT" "TRANS " "VTLAXS" "GERR  " "TRACUT" "ARLEM " 
	    "HOLDPP" "CLDAT " "MACHIN" "CLPRNT" "CUT   " "DNTCUT";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, nwd, knt;
    static char test[6];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);

/*     THIS ROUTINE COMPARES A BCD WORD WITH THE CONTENTS OF A HOLERITH */
/*     ARRAY TO DETERMINE THE PROCESSING TO BE PERFORMED */
/*                            1         2      3         4        5 */
/*        6         7         8        9       10        11       12 */
/*        13        14       15       16       17        18       19 */
/*         20       21       22       23       24        25 */
    knt = 26;
    holfrm_(bcd, test, &c__1, &c__6, &nwd, (ftnlen)6);
    for (i__ = 1; i__ <= 25; ++i__) {
	if (s_cmp(test, holarr + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L50;
	}
/* L25: */
    }
    *result = knt;
    goto L100;
L50:
    *result = i__;
L100:
    return 0;
} /* apt310_ */

