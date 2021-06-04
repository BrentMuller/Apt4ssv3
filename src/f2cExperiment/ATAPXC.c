/* ATAPXC.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ATAPXC00.ORG   *** */

/* Subroutine */ int atapxc_0_(int n__, integer *file1, integer *file2)
{
    static integer i__;


/*  * ATAPXC *  VAX11 FORTRAN 77 VERSION  27.8.82 E.MCLELLAN */

/*  PURPOSE     TO INTERCHANGE TWO FILES */

/*  CALLING SEQUENCE */
/*              CALL ATAPXC(FILE1,FILE2) */

/*  ARGUMENTS */
/*              FILE1  FILE NUMBER OF FIRST FILE */
/*              FILE2  FILE NUMBER OF SECOND FILE */
/*  ALTERNATE ENTRY */
/*              CALL TAPECH(FILE1,FILE2) */


    switch(n__) {
	case 1: goto L_tapech;
	}


L_tapech:
    i__ = *file1;
    *file1 = *file2;
    *file2 = i__;
    return 0;
} /* atapxc_ */

/* Subroutine */ int atapxc_(integer *file1, integer *file2)
{
    return atapxc_0_(0, file1, file2);
    }

/* Subroutine */ int tapech_(integer *file1, integer *file2)
{
    return atapxc_0_(1, file1, file2);
    }

