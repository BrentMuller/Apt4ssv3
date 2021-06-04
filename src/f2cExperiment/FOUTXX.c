/* FOUTXX.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* *** SOURCE FILE : M0006632.V02   *** */


/*              FORTRAN SUBROUTINE FOUTXX */

/* LINKAGE      SUBROUTINE FOUTXX (IFILE,ARRAY,COUNT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CPRINT          SUBROUTINE    ALARM */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    PRTIL */
/*                                        SUBROUTINE    PUTTMP */
/*                                        SUBROUTINE    RLSLIN */
/*                                        SUBROUTINE    START */

/* Subroutine */ int foutxx_(integer *ifile, char *array, integer *count, 
	ftnlen array_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int cprint_(char *, ftnlen);



/*       20.    IO - ARRAY */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* ** */
    s_copy(darray_1.darray, array, (*count), (*count));
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
} /* foutxx_ */

