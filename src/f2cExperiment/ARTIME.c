/* ARTIME.f -- translated by f2c (version 20100827).
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
    char ctime[8], cdate[9];
} atime_;

#define atime_1 atime_

/* *** SOURCE FILE : ARTIME00.ORG   *** */


/*  * ARTIME *  FORTRAN 77 SUBROUTINE  9-DEC-1985  E.MCLELLAN */

/*  PURPOSE:  EXTRACT CURRENT DATE AND TIME AND STORE IN ATIME BLOCK */

/*  CALLING SEQUENCE: */
/*                   CALL ARTIME */

/*  ARGUMENTS:  NONE */

/*  GLOBAL VARIABLES: */

/* --------------------------------------------------- */
/*   VARIABLE        BLOCK     TYPE       DESCRIPTION */
/* --------------------------------------------------- */
/*   CTIME           ATIME     CHARACTER  CURRENT TIME */
/*   CDATE           ATIME     CHARACTER  CURRENT DATE */

/*  LOCAL VARIABLES:  NONE */
/*                   TYPE       DESCRIPTION */

/*  FILES:  NONE */

/*  SUBSIDIARIES: */
/*              DATE */
/*              TIME */

/* Subroutine */ int artime_(void)
{
    extern /* Subroutine */ int date_(char *, ftnlen), time_(char *, ftnlen);




    time_(atime_1.ctime, (ftnlen)8);
    date_(atime_1.cdate, (ftnlen)9);

    return 0;
} /* artime_ */

