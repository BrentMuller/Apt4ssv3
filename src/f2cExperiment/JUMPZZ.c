/* JUMPZZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006644.V01   *** */


/*              FORTRAN SUBROUTINE JUMPZZ */

/* LINKAGE      SUBROUTINE JUMPZZ(INDEX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ONEARG          SUBROUTINE    COMSTR */
/*          SUBROUTINE    OPCODE          SUBROUTINE    PRO026 */
/*          SUBROUTINE    RLSLIN */

/* Subroutine */ int jumpzz_(integer *index)
{
    /* Local variables */
#define jump ((integer *)&il_1 + 7)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *), 
	    rlslin_(void);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* JUMP:        CONTAINS COMMAND CODE ( 8) FOR JUMP COMMAND */
/* * */
/* PURPOSE      TO GENERATE  AND OUTPUT TO THE I.L. INTERNAL */
/*              RECORD IMAGE (ILFILE) THE JUMP I.L. COMMAND. */

/* ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF A LABEL. */
/* ** */
/* ...     GENERATE I.L. FOR JUMP COMMAND. */

    opcode_(jump);
    onearg_(index);
    rlslin_();
    return 0;
} /* jumpzz_ */

#undef jump


