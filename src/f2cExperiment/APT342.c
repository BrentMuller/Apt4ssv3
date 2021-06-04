/* APT342.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000443.V01   *** */

/* .....FORTRAN SUBROUTINE                APT342...            8/1/68  AR */
/* PURPOSE      TO CALCULATE A VECTOR THAT IS THE CROSS PRODUCT */
/*              OF TWO SPECIFIED VECTORS. */
/* LINKAGE      CALL APT342(V1,V2,V3) */
/* ARGUMENTS    V1,V2 ARE VECTORS WHOSE CROSS PRODUCT IS V3. */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt342_(doublereal *cra, doublereal *crb, doublereal *
	crc)
{
    static doublereal crtem1, crtem2;

    /* Parameter adjustments */
    --crc;
    --crb;
    --cra;

    /* Function Body */
    crtem1 = cra[2] * crb[3] - cra[3] * crb[2];
    crtem2 = cra[3] * crb[1] - cra[1] * crb[3];
    crc[3] = cra[1] * crb[2] - cra[2] * crb[1];
    crc[1] = crtem1;
    crc[2] = crtem2;
    return 0;
} /* apt342_ */

