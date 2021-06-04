/* COMPRS.f -- translated by f2c (version 20100827).
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
    integer prt[7];
} prt_;

#define prt_1 prt_

/* *** SOURCE FILE : M0006764.V01   *** */


/*              FORTRAN SUBROUTINE COMPRS */

/* LINKAGE      SUBROUTINE COMPRS */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ACMPRS          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    ICMPRS */

/* Subroutine */ int comprs_(void)
{
    /* Initialized data */

    static logical prosw = TRUE_;

    /* Local variables */
#define assemb ((logical *)&prt_1 + 3)
    extern /* Subroutine */ int icmprs_(void);
#define interp ((logical *)&prt_1 + 2)
    extern /* Subroutine */ int prolog_(void);



/*       14.    I. L. LIST OPTION FLAGS */

/* INTERP:      NORMALLY TRUE,INDICATING INTERPRETIVE APPROACH DEFAULT */
/* ASSEMB:      SET TRUE INDICATES ASSEMBLY APPROACH (CONTRL/ASMBLE) */
/* * */
/* ** */
    if (prosw) {
	goto L100;
    }
/*  10 IF(ASSEMB)CALL ACMPRS */
/*     IF(INTERP)CALL ICMPRS */
L10:
    icmprs_();
    return 0;
L100:
    prosw = FALSE_;
    prolog_();
    goto L10;
} /* comprs_ */

#undef interp
#undef assemb


