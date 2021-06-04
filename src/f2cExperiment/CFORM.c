/* CFORM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : CFORM000.ORG   *** */


/*  * CFORM *  FORTRAN 77 SUBROUTINE  26.10.84  E.MCLELLAN */

/*  PURPOSE:  TO INSERT A CHARACTER STRING IN A CHARACTER BUFFER */
/*            AT LOCATION POSN. */
/*            THE LENGTH OF THE STRING IS RETURNED IF THE ARGUMENT */
/*            LENGTH IS ZERO ON INPUT. */

/*  CALLING SEQUENCE: */
/*                   CALL CFORM(STRING,BUFFER,POSN,LENGTH) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*       STRING      CHARACTER  CHARACTER STRING TO BE INSERTED */
/*       BUFFER      CHARACTER  CHARACTER BUFFER INTO WHICH */
/*                              STRING IS TO BE INSERTED */
/*       POSN        INTEGER    LOCATION IN CHARACTER BUFFER */
/*                              AT WHICH STRING IS TO BE INSERTED */
/*       LENGTH      INTEGER    LENGTH OF STRING */
/*                              IF = 0 ON INPUT, ACTUAL LENGTH */
/*                              IS RETURNED TO CALLING ROUTINE */

/*  GLOBAL VARIABLES:  NONE */

/*  LOCAL VARIABLES:  NONE */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */

/* Subroutine */ int cform_(char *string, char *buffer, integer *posn, 
	integer *length, ftnlen string_len, ftnlen buffer_len)
{
    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);



/* .....IF LENGTH IS ZERO ON INPUT RETURN ACTUAL LENGTH OF STRING */

    if (*length == 0) {
	*length = i_len(string, string_len);
    }

/* .....INSERT CHARACTER STRING IN PRINT BUFFER */

    s_copy(buffer + (*posn - 1), string, *posn + *length - 1 - (*posn - 1), (*
	    length));

    return 0;
} /* cform_ */

