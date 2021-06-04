/* CALMCX.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006625.V01   *** */


/*              FORTRAN SUBROUTINE CALMCX */

/* LINKAGE      SUBROUTINE CALMCX(NPNTR,LEV,INDX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ONEARG          SUBROUTINE    INPUT */
/*          SUBROUTINE    OPCODE          SUBROUTINE    MACREC */
/*          SUBROUTINE    RLSLIN          SUBROUTINE    PATH */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int calmcx_(integer *npntr, integer *lev, integer *indx)
{
    /* Local variables */
#define calmc ((integer *)&il_1 + 13)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *), 
	    twoarg_(integer *, integer *), rlslin_(void);



/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* CALMC:       CONTAINS COMMAND CODE (14) FOR CALMC COMMAND */
/* * */
/* PURPOSE      TO GENERATE AND OUTPUT TO THE I.L. INTERNAL */
/*              RECORD IMAGE (ILFILE) THE CALMC I.L. COMMAND */
/*              THAT ESTABLISHES LINKAGE WITH REMOTE APT */
/*              MACRO I.L.. */

/* ARGUMENTS    NPNTR  NAME TABLE (NAMTBL) INDEX OF LABEL. */
/*              LEV    LEVEL OF CALL TO MACRO. */
/* **            INDX   INDEX REGISTER NUMBER. */

/* ...     GENERATE I.L. CALMC COMMAND */

    opcode_(calmc);
    onearg_(npntr);
    twoarg_(lev, indx);
    rlslin_();
    return 0;
} /* calmcx_ */

#undef calmc


