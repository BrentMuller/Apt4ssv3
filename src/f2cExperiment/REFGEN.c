/* REFGEN.f -- translated by f2c (version 20100827).
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
    integer nonept;
} negptr_;

#define negptr_1 negptr_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

/* *** SOURCE FILE : M0006674.V01   *** */


/*              FORTRAN SUBROUTINE REFGEN */

/* LINKAGE      SUBROUTINE REFGEN (IREF,NAMPTR) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    PRO021 */
/*          SUBROUTINE    CALLZZ          SUBROUTINE    PRO026 */
/*          SUBROUTINE    RLSLIN          SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOGN */

/* Subroutine */ int refgen_(integer *iref, integer *namptr)
{
    /* Local variables */
#define defext ((integer *)&sublst_1 + 81)
    extern /* Subroutine */ int argcvt_(integer *), callzz_(integer *), 
	    rlslin_(void);
#define aptyyy ((integer *)&sublst_1 + 120)



/*       13.    NAMTBL POINTERS TO NEGATIVE NUMBERS */
/*              NAMTBL POINTER TO -1. */

/*       28.    OPERAND MODIFIERS */

/* APTYYY:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */
/* DEFEXT:      NAMTBL POINTER FOR XECUTION SUBROUTINE DEFEXT */
/* * */
/* ARGUMENTS    IREF       APTYYY INDEX CONTAINING NAME TABLE */
/*                         (NAMTBL) INDEX OF TRANSFORMATION ROUTINE. */
/*              NAMPTR    NAME TABLE (NAMTBL) INDEX OF VARIABLE */
/*                        TO BE TRANSFORMED. */
/* NOTES        FOLLOWING IS A LIST OF EACH IREF VALUE WITH */
/*              ITS ASSOCIATED SURFACE AND TRANSFORMATION ROUTINE NAME. */
/*              IREF       VARIABLE MODE         TRANSFORMATION */
/*              1             POINT, SPHERE         APT081 */
/*              2             CIRCLE                APT083 */
/*              3             VECTOR                ATP078 */
/*              4             LINE, PLANE           APT077 */
/*              5             QUADRIC SURFACE       APT079 */
/* ** */
/* L380: */
    callzz_(&aptyyy[*iref - 1]);
    argcvt_(namptr);
    argcvt_(&negptr_1.nonept);
    rlslin_();
    callzz_(defext);
    argcvt_(namptr);
    rlslin_();
    return 0;
} /* refgen_ */

#undef aptyyy
#undef defext


