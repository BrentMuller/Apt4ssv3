/* BDSDP.f -- translated by f2c (version 20100827).
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

struct sdp_1_ {
    integer nbchar, nbwrd, iwrd, ifac;
};

#define sdp_1 (*(struct sdp_1_ *) &sdp_)

/* Initialized data */

struct {
    integer e_1[4];
    } sdp_ = { 8, 32, 4, 256 };


/* *** SOURCE FILE : BDSDP000.ORG   *** */

/* Subroutine */ int bdsdp_(void)
{
    return 0;
} /* bdsdp_ */


/*  PURPOSE TO INITIALIZE SYSTEM DEPENDENT PARAMETERS */


/*     NBCHAR:  NO. OF BITS PER BYTE */
/*     DATA NBCHAR/8/ */
/*     NBWRD:   NO OF BITS PER WORD */
/*     DATA NBWRD/32/ */
/*     IWRD:    NO OF BYTES PER WORD */
/*     DATA IWRD/4/ */
/*     IFAC:    BYTE LEFT SHIFT MULTIPLICATION FACTOR */
/*     DATA IFAC/256/ */



