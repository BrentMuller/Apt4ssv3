/* HEX.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : HEX00000.ORG   *** */


/*  * HEX *  FORTRAN 77 CHARACTER FUNCTION   6.11.85  E.MCLELLAN */

/*  PURPOSE:  TO CONVERT AN INTEGER VALUE TO A CHARACTER STRING */
/*            REPRESENTING THE EQUIVALENT HEXADECIMAL NUMBER */

/*  CALLING SEQUENCE: */
/*                   STRING=HEX(VALUE) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*       VALUE       INTEGER    INTEGER VALUE TO BE CONVERTED */
/*                              TO HEX CHARACTER STRING */

/*  GLOBAL VARIABLES:  NONE */

/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*       DIV         INTEGER    DIVISORS FOR EACH HALF BYTE */
/*                              POSITION (POWERS OF 16) */
/*       J           INTEGER    INTEGRAL QUOTIENT */
/*       V           INTEGER    DIVIDEND */
/*       H           CHARACTER  HEX CHARACTERS (0-F) */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */

/* Character */ VOID hex_(char *ret_val, ftnlen ret_val_len, integer *value)
{
    /* Initialized data */

    static integer div[7] = { 268435456,16777216,1048576,65536,4096,256,16 };
    static char h__[1*16] = "0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "A" "B" 
	    "C" "D" "E" "F";

    static integer i__, j, v;





    v = *value;
    for (i__ = 1; i__ <= 7; ++i__) {
	j = v / div[i__ - 1];
	v -= j * div[i__ - 1];
	*(unsigned char *)&ret_val[i__ - 1] = *(unsigned char *)&h__[j];
/* L10: */
    }
    *(unsigned char *)&ret_val[7] = *(unsigned char *)&h__[v];

    return ;
} /* hex_ */

