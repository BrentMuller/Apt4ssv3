/* CLED.f -- translated by f2c (version 20100827).
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
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* *** SOURCE FILE : M0000444.V04   *** */


/* ....FORTRAN SUBROUTINE  ...CLED...       11/69                  HG */
/* Subroutine */ int cled_(void)
{
    /* Local variables */
    extern /* Subroutine */ int apt301_(void);
#define cflags ((logical *)&super_1)
#define lxtras ((logical *)&super_1 + 9)


/*         PURPOSE           ...TO CALL APT301 */

/*         CALLING SEQUENCE  ...THIS IS THE MAIN PROGRAM OF THE CLEDITOR */

/*         ARGUMENTS         ...NONE */

/*         CALLED BY         ...NONE */

/*         SUBSIDIARIES      ...TYPE...      ...ENTRY... */

/*                           SUBROUTINE         APT301 */

/*         RESTRICTIONS      ...NONE */

/*         DIAGNOSTICS       ...NONE */
/* .... */



/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */








/* ...                SYSTEM I/O FILES */



    apt301_();
/* ....    INDICATE NORMAL ENDING */
    super_1.abend = FALSE_;

    return 0;
} /* cled_ */

#undef lxtras
#undef cflags


