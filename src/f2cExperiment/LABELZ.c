/* LABELZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006646.V01   *** */


/*              FORTRAN SUBROUTINE LABELZ */

/* LINKAGE      SUBROUTINE LABELZ(INDEX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ONEARG          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    OPCODE          SUBROUTINE    COMSTR */
/*          SUBROUTINE    RLSLIN          SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MATCH */
/*                                        SUBROUTINE    RECOG */

/* Subroutine */ int labelz_(integer *index)
{
    /* Local variables */
#define labelx ((integer *)&il_1 + 5)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *), 
	    rlslin_(void);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* LABELX:      CONTAINS COMMAND CODE ( 6) FOR LABEL COMMAND */
/* * */
/* PURPOSE      TO GENERATE AND OUTPUT TO THE I.L. RECORD IMAGE */
/*              (ILFILE) THE LABEL I.L. COMMAND. */

/* ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF LABEL. */
/* ** */
    opcode_(labelx);
    onearg_(index);
    rlslin_();
    return 0;
} /* labelz_ */

#undef labelx


