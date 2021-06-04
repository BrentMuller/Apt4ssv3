/* EXEC.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001665.V04   *** */


/* ....FORTRAN SUBROUTINE  ...EXEC...       5/69                   HG */

/* Subroutine */ int exec_(void)
{
    /* Initialized data */

    static integer one = 1;

    /* Local variables */
    extern /* Subroutine */ int seq_(integer *), imain_(void), delall_(void);
#define cflags ((logical *)&super_1)
#define lxtras ((logical *)&super_1 + 9)



/* ...THIS IS THE MAIN ROUTINE FOR THE EXECUTION COMPLEX. */


/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */







/* ...     SET UP INITIAL SEQUENCE NUMBER */
    seq_(&one);

/* ... CALL THE MAIN ROUTINE FOR THE INTERPRETIVE APPROACH. */
    imain_();

/* ... INDICATE NORMAL ENDING. */
    super_1.abend = FALSE_;

/* ... FREEMAIN OF SECUDARY LOADED MODULS,IF NESSESARY */
    delall_();
    return 0;
} /* exec_ */

#undef lxtras
#undef cflags


