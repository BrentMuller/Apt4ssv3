/* KONAST.f -- translated by f2c (version 20100827).
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

struct {
    integer code[150];
} code_;

#define code_1 code_

/* *** SOURCE FILE : M0006629.V01   *** */


/*              FORTRAN SUBROUTINE KONAST */

/* LINKAGE      SUBROUTINE  KONAST(TENPT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    SETCHR          SUBROUTINE    RECOG */

/* Subroutine */ int konast_(integer *tenpt)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
#define top ((integer *)&stklst_1)
#define stack ((integer *)&stklst_1 + 3)
#define aster ((integer *)&code_1 + 16)
#define dblast ((integer *)&code_1 + 62)
#define number ((integer *)&code_1 + 26)
    extern /* Subroutine */ int setchr_(integer *, integer *);



/*        2.    STACK AND POINTER STORAGE */

/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* ASTER:       (1)=CODE CLASS  9000,(2)=NAMTBL INDEX OF '*     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* DBLAST:      (1)=CODE CLASS 32000,(2)=NAMTBL INDEX OF 'DBLAST' */
/* ** */
    *top += 2;
    stack[(*top << 1) - 2] = stack[(*top - 2 << 1) - 2];
    stack[(*top << 1) - 1] = stack[(*top - 2 << 1) - 1];
    stack[(*top - 1 << 1) - 2] = stack[(*top - 3 << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top - 3 << 1) - 1];
    i__1 = *top - 2;
    setchr_(&i__1, dblast);
    i__1 = *top - 3;
    setchr_(&i__1, number);
    stack[(*top - 3 << 1) - 2] = *tenpt;
    i__1 = *top - 4;
    setchr_(&i__1, aster);

    return 0;
} /* konast_ */

#undef number
#undef dblast
#undef aster
#undef stack
#undef top


