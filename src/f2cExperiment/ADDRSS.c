/* ADDRSS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ADDRSS00.ORG   *** */

integer addrss_(doublereal *x)
{
    /* System generated locals */
    integer ret_val;


/*  * ADDRSS *   VAX11 FORTRAN VERSION    18.2.82  E.MCLELLAN */

/*  PURPOSE     ADDRSS RETURNS AN INTEGER WHICH IS THE */
/*              ACTUAL MACHINE ADDRESS OF THE ARGUMENT */

/*  CALLING SEQUENCE */
/*              VALUE=ADDRSS(X) */
/*  ARGUMENTS */
/*              X  VARIABLE WHOSE ADDRESS IS TO BE RETURNED */

/*      ADDRSS=%LOC(X) */
/*      addrss=loc(x) */

    return ret_val;
} /* addrss_ */

