/* SETCHR.f -- translated by f2c (version 20100827).
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
    integer srctbl[502];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006685.V01   *** */


/*              FORTRAN SUBROUTINE SETCHR */

/* LINKAGE      SUBROUTINE SETCHR(PNTR,CLASS) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    KONAST */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    VCTPRD */

/* Subroutine */ int setchr_(integer *pntr, integer *class__)
{
    /* Local variables */
    static integer i__;
#define meta ((integer *)&srctbl_1 + 2)
#define stack ((integer *)&stklst_1 + 3)
#define modulo ((integer *)&moduli_1)



/*        2.    STACK AND POINTER STORAGE */

/* STACK:       WORKING STACK */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* * */
/* ARGUMENTS    PNTR      STACK INDEX OF ENTRY */
/*              CLASS     TWO ELEMENT ARRAY WHERE CLASS(2) */
/*                        CONTAINS NAME TABLE (NAMTBL) INDEX OF */
/*                        DESIRED META-CHARACTER. */
/*     CHANGE A CHARACTER */
/* ** */
    /* Parameter adjustments */
    --class__;

    /* Function Body */
    stack[(*pntr << 1) - 2] = class__[2];
    i__ = class__[1] / *modulo;
    stack[(*pntr << 1) - 1] = meta[i__ - 1];
    return 0;
} /* setchr_ */

#undef modulo
#undef stack
#undef meta


