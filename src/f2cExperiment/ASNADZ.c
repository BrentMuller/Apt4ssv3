/* ASNADZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006618.V01   *** */


/*              FORTRAN SUBROUTINE ASNADZ */

/* LINKAGE      SUBROUTINE ASNADZ(IADD,ITAKE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    COMSTR */
/*          SUBROUTINE    ONEARG          SUBROUTINE    MACREC */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    RLSLIN */

/* Subroutine */ int asnadz_(integer *iadd, integer *itake)
{
    /* Local variables */
#define asnadd ((integer *)&il_1 + 14)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *), 
	    argcvt_(integer *), rlslin_(void);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* ASNADD:      CONTAINS COMMAND CODE (15) FOR ASNADD COMMAND */
/* * */
/* PURPOSE      TO GENERATE AND OUTPUT TO THE I.L. INTERNAL */
/*              RECORD IMAGE (ILFILE) THE ASNADD I.L. COMMAND */
/*              THAT STORES THE ADDRESS OF AN ASSIGNED VALUE */
/*              AS THE VALUE OF A MACRO VARIABLE. */

/* ARGUMENTS    IADD     NAME TABLE (NAMTBL) INDEX OF MACRO VARIABLE */
/*              ITAKE    NAME TABLE INDEX OF ASSIGNED VALUE. */

/* NOTES        INDIRECT ADDRESSING EMPLOYED TO RETRIEVE */
/*              ASSIGNED VALUE. */
/* ** */
    opcode_(asnadd);
    onearg_(iadd);
    argcvt_(itake);
    rlslin_();
    return 0;
} /* asnadz_ */

#undef asnadd


