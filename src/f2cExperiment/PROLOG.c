/* PROLOG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006664.V01   *** */


/*              FORTRAN SUBROUTINE PROLOG */

/* LINKAGE      SUBROUTINE PROLOG */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    IPRLOG          SUBROUTINE    COMPRS */

/* Subroutine */ int prolog_(void)
{
    /* Local variables */
    extern /* Subroutine */ int iprlog_(void);
#define interp ((logical *)&prt_1 + 2)



/*       14.    I. L. LIST OPTION FLAGS */

/* INTERP:      NORMALLY TRUE,INDICATING INTERPRETIVE APPROACH DEFAULT */
/* ** */
/*     IF(ASSEMB)CALL APRLOG */
    if (*interp) {
	iprlog_();
    }
    return 0;
} /* prolog_ */

#undef interp


