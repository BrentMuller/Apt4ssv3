/* BDLIBC.f -- translated by f2c (version 20100827).
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

struct libcom_1_ {
    integer ieof;
};

#define libcom_1 (*(struct libcom_1_ *) &libcom_)

struct libfil_1_ {
    char aptlib[11], filenm[40], memnam[8];
};

#define libfil_1 (*(struct libfil_1_ *) &libfil_)

/* Initialized data */

struct {
    integer e_1;
    } libcom_ = { 1 };

struct {
    char e_1[59];
    } libfil_ = { "SYS$APTLIB:                                              "
	    "  " };


/* *** SOURCE FILE : BDLIBCOM.V01   *** */

/* Subroutine */ int bdlibc_(void)
{
    return 0;
} /* bdlibc_ */








