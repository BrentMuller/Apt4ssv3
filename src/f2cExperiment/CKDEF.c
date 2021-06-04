/* CKDEF.f -- translated by f2c (version 20100827).
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
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : CKDEF000.V01   *** */


/*  * CKDEF * */

/*  LOGICAL FUNCTION CKDEF */

/*  PURPOSE  TO DETERMINE THAT THE ARGUMENT IS PROPERLY DEFINED */
/*           THE VALUE .FALSE. IS RETURNED IF DEFINED,.TRUE. OTHERWISE */

logical ckdef_(integer *arg)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i2, i3, ash, dtr, str;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);





    /* Parameter adjustments */
    --arg;

    /* Function Body */

    if (first) {
	i3 = sdp_1.nbchar * 3;
	i2 = sdp_1.nbchar << 1;
	str = lbit_shift('*', i3) + lbit_shift('T', sdp_1.nbchar) + 'R';
	dtr = lbit_shift('$', i3) + lbit_shift('T', sdp_1.nbchar) + 'R';
	ash = lbit_shift('A', i3) + lbit_shift('S', i2) + lbit_shift('H', 
		sdp_1.nbchar);
	first = FALSE_;
    }

    if (arg[1] == str && arg[2] == ash) {
	ret_val = TRUE_;
	error_(&c__1, "CKDEF   ", (ftnlen)8);
    } else if (arg[1] == dtr && arg[2] == ash) {
	ret_val = TRUE_;
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* ckdef_ */


/*  * CKSTR * */

/*  LOGICAL FUNCTION CKSTR */

/*  PURPOSE  TO DETERMINE THAT THE ARGUMENT HAS BEEN SET TO '* TRASH' */
/*           THE VALUE .TRUE. IS RETURNED IF SET ,.FALSE. OTHERWISE */

logical ckstr_(integer *arg)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i2, i3, ash, str;





    /* Parameter adjustments */
    --arg;

    /* Function Body */

    if (first) {
	i3 = sdp_1.nbchar * 3;
	i2 = sdp_1.nbchar << 1;
	str = lbit_shift('*', i3) + lbit_shift('T', sdp_1.nbchar) + 'R';
	ash = lbit_shift('A', i3) + lbit_shift('S', i2) + lbit_shift('H', 
		sdp_1.nbchar);
	first = FALSE_;
    }
    if (arg[1] == str && arg[2] == ash) {
	ret_val = TRUE_;
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* ckstr_ */


/*  * CKDTR * */

/*  LOGICAL FUNCTION CKDTR */

/*  PURPOSE  TO DETERMINE THAT THE ARGUMENT IS SET TO '$ TRASH' */
/*           THE VALUE .TRUE. IS RETURNED IF SET, .FALSE. OTHERWISE */

logical ckdtr_(integer *arg)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i2, i3, ash, dtr;





    /* Parameter adjustments */
    --arg;

    /* Function Body */

    if (first) {
	i3 = sdp_1.nbchar * 3;
	i2 = sdp_1.nbchar << 1;
	dtr = lbit_shift('$', i3) + lbit_shift('T', sdp_1.nbchar) + 'R';
	ash = lbit_shift('A', i3) + lbit_shift('S', i2) + lbit_shift('H', 
		sdp_1.nbchar);
	first = FALSE_;
    }
    if (arg[1] == dtr && arg[2] == ash) {
	ret_val = TRUE_;
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* ckdtr_ */

