/* RECORD.f -- translated by f2c (version 20100827).
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
    integer sqno;
} sqnc_;

#define sqnc_1 sqnc_

/* *** SOURCE FILE : M0000957.V01   *** */

/* .....FORTRAN SUBROUTINE             RECORD...              3/1/68   GK */
/* Subroutine */ int record_(integer *iseqno)
{

    *iseqno = sqnc_1.sqno;
    return 0;
} /* record_ */

