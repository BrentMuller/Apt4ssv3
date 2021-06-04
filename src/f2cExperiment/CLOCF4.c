/* CLOCF4.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : CLOCF400.ORG   *** */


/*  * CLOCF4 *  FORTRAN 77 SUBROUTINE  4-DEC-85  E.MCLELLAN */

/*  PURPOSE:  USE SYSTEM DEPENDENT FUNCTION 'CPUTIM' */
/*            TO OBTAIN CPU TIME IN 1/100THS OF A SECOND */

/*  CALLING SEQUENCE: */
/*                   CALL CLOCF4(TIME) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*       TIME        INTEGER    CPU TIME IN 1/100THS OF A SECOND */

/*  GLOBAL VARIABLES:  NONE */

/*  LOCAL VARIABLES:  NONE */

/*  FILES:  NONE */

/*  SUBSIDIARIES: */
/*               CPUTIM */

/* Subroutine */ int clocf4_(integer *time)
{
    extern integer cputim_(void);




    *time = cputim_();
    return 0;
} /* clocf4_ */

