/* CALLZZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006622.V01   *** */


/*              FORTRAN SUBROUTINE CALLZZ */

/* LINKAGE      SUBROUTINE CALLZZ(INDEX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ONEARG          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    OPCODE          SUBROUTINE    COMSTR */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REFGEN */
/*                                        SUBROUTINE    REFREF */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int callzz_(integer *index)
{
    /* Local variables */
#define call ((integer *)&il_1 + 17)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* CALL:        CONTAINS COMMAND CODE (18) FOR CALL COMMAND */
/* * */
/* PURPOSE      TO GENERATE THE I.L. FOR A CALL OPCODE AND */
/*              THE PROCEDURE INDEX. */

/* ARGUMENTS    INDEX  NAME TABLE (NAMTBL) INDEX OF THE PROCEDURE NAME. */
/* ** */
/* ...     GENERATE CALL OPCODE, AND FIRST ARGUMENT (PROCEDURE INDEX) */

    opcode_(call);
    onearg_(index);
    return 0;
} /* callzz_ */

#undef call


