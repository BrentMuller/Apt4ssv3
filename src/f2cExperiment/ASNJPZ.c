/* ASNJPZ.f -- translated by f2c (version 20100827).
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
    integer il[21];
} il_;

#define il_1 il_

/* *** SOURCE FILE : M0006619.V01   *** */


/*              FORTRAN SUBROUTINE ASNJPZ */

/* LINKAGE      SUBROUTINE ASNJPZ(ILBL,ITAKE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    OPCODE          SUBROUTINE    COMSTR */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int asnjpz_(integer *ilbl, integer *itake)
{
    /* Local variables */
    extern /* Subroutine */ int opcode_(integer *);
#define asnjmp ((integer *)&il_1 + 15)
    extern /* Subroutine */ int twoarg_(integer *, integer *), rlslin_(void);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* ASNJMP:      CONTAINS COMMAND CODE (16) FOR ASNJMP COMMAND */
/* * */
/* PURPOSE      TO GENERATE AND OUTPUT TO THE I.L. INTERNAL */
/*              RECORD IMAGE (ILFILE) THE ASNJPZ I.L. */
/*              COMMAND THAT STORES THE ADDRESS OF A LABEL */
/*              AS THE VALUE OF A MACRO VARIABLE. */

/* ARGUMENTS    ILBL    NAME TABLE (NAMTBL) INDEX OF MACRO VARIABLE. */
/*              ITAKE   NAME TABLE (NAMTBL) INDEX OF LABEL. */
/* ** */
    opcode_(asnjmp);
    twoarg_(ilbl, itake);
    rlslin_();
    return 0;
} /* asnjpz_ */

#undef asnjmp


