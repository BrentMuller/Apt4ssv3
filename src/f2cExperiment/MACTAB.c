/* MACTAB.f -- translated by f2c (version 20100827).
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
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx3[1430];
} macxx3_;

#define macxx3_1 macxx3_

/* *** SOURCE FILE : M0006652.V01   *** */


/*              FORTRAN SUBROUTINE MACTAB */

/* LINKAGE      SUBROUTINE MACTAB(PONTER,STAAT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    INPUT */
/*                                        SUBROUTINE    MACREC */

/* Subroutine */ int mactab_(integer *ponter, integer *staat)
{
    /* Local variables */
    static integer i__, j;
#define macdf1 ((integer *)&macxx3_1)
#define macdfp ((integer *)&macxx1_1)



/*       22.    MACRO PROCESSING VARIABLES */

/* MACDFP:      POINTER TO LAST ENTRY IN MACDF1 AND MACDF2 ARRAYS */

/*       24.    MACRO PROCESSING ARRAYS */

/* MACDF1:      STORES MACRO NAME AND ALL MACRO VBL NAMTBL POINTERS */
/* * */
/* PURPOSE      TO DETERMINE THE POSITION OF A PARTICULAR MACRO */
/*              NAME IN THE MACDF1 TABLE. */

/* ARGUMENTS    PONTER   NAME TABLE (NAMTBL) INDEX OF MACRO NAME */
/*              STAAT    FOUND MACDF1 INDEX OF MACRO NAME */
/* ** */
    j = *ponter;
    i__ = *staat;
L1:
    if (i__ >= *macdfp) {
	goto L4;
    }
    if (macdf1[i__ - 1] == j) {
	goto L6;
    }
    if (macdf1[i__ + 1] <= 0) {
	goto L2;
    } else {
	goto L3;
    }
L2:
    i__ += 3;
    goto L1;
L3:
    i__ = macdf1[i__ + 1] + 1;
    goto L1;
L4:
    *staat = 0;
L5:
    return 0;
L6:
    *staat = i__;
    goto L5;
} /* mactab_ */

#undef macdfp
#undef macdf1


