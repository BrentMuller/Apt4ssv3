/* BDIPL.f -- translated by f2c (version 20100827).
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

struct outbuf_1_ {
    integer pagpak, isc, iscarr, icform, ifloat, icom, macwds, ppwrds;
    logical macflg, labflg, rsvflg;
    integer lpage, buffer[256], labbuf[256], ibuf, ilbuf, pppage, mcpage;
};

#define outbuf_1 (*(struct outbuf_1_ *) &outbuf_)

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Initialized data */

struct {
    integer e_1[8];
    logical e_2[3];
    integer e_3;
    integer fill_4[512];
    integer e_5[4];
    } outbuf_ = { 65536, 0, 0, 0, 0, 0, 0, 0, FALSE_, FALSE_, FALSE_, 0, {0}, 
	    0, 0, 0, 0 };


/* *** SOURCE FILE : M0006641.V06   *** */


/* ...  FORTRAN BLOCK DATA ROUTINE       IPL       8/81      FE353 */

/* Subroutine */ int bdipl_(void)
{
    return 0;
} /* bdipl_ */



/* ...        34.    COMMON BLOCK FOR INTERPRETIVE C.I.L. OUTPUT */


/* ...        20.    IO - ARRAY */





/* ...        34.    COMMON BLOCK FOR INTERPRETIVE C.I.L. OUTPUT */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* ...        20.    IO - ARRAY */

/*      DATA DARRAY/' '/ */

