/* APT313.f -- translated by f2c (version 20100827).
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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c_n2 = -2;

/* *** SOURCE FILE : M0000429.V03   *** */


/* .....FORTRAN SUBROUTINE              APT313                12/67 */
/* PURPOSE      TO TERMINATE WRITING OF CLFILE AT THE END OF */
/*              THE DATA ON CLFILE. */
/* LINKAGE      CALL APT313 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt313_(void)
{
    extern /* Subroutine */ int tapop_(integer *, integer *);


/* ...            SYSTEM I/O FILE NAMES */


/*       THIS ROUTINE TERMINATES WRITING OF CLFILE */


/* ...                SYSTEM I/O FILES */



    tapop_(&symfil_1.clfile, &c_n2);
/*     ENDFILE */
/*     REWIND CLFILE */
    return 0;
} /* apt313_ */

