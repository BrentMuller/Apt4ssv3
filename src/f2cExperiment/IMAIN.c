/* IMAIN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000743.V01   *** */

/* .....FORTRAN ROUTINE          ..AIMAIN..      6/69       HLG       *ID* */
/* Subroutine */ int imain_(void)
{
    extern /* Subroutine */ int init_(void), intrp_(void);


/* PURPOSE      THIS IS THE MAIN ROUTINE FOR THE INTERPRETIVE APPROACH. */
/* NOTE THE MAIN ROUTINE FOR THE ASSEMBLY APPROACH */
/* WILL BE CALLED AMAIN, WHEN IMPLEMENTED, & WHICH ROUTINE */
/* IS USED DEPENDS ON THE APPROACH  REQUESTED BY THE PART PROGRAM. */

/* CALLED BY    THE ROUTINE MAIN */


/* ...  INITALIZE STORAGE */
    init_();

/* ...  GO TO INTERPRETER */
    intrp_();

    return 0;
} /* imain_ */

