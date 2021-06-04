/* PUNIDS.f -- translated by f2c (version 20100827).
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
    real pnid, pno;
} pun_;

#define pun_1 pun_

/* *** SOURCE FILE : PUNIDS00.ORG   *** */

doublereal punids_0_(int n__)
{
    /* System generated locals */
    real ret_val;


/*  * PUNIDS *  VAX-11 FORTRAN 77 VERSION  21.10.82  E.MCLELLAN */

/*  PURPOSE     TO RETREIVE CARD IDENTIFICATION AND SEQUENCE NUMBER */

/*  CALLING SEQUENCE */
/*              VALUE = PUNIDS() */
/*  ARGUMENT */
/*              NONE    NOTE: PARENTHESIS MUST APPEAR */
/*              VALUE   WILL CONTAIN 4 BCD CHARACTERS BEING IDENT */
/*  ALTERNATE ENTRY */
/*              VALUE = PUNNOM() */

/*              VALUE   WILL CONTAIN REAL*4 VALUE BEING CURRENT */
/*                      SEQUENCE NUMBER */


    switch(n__) {
	case 1: goto L_punnom;
	}

    ret_val = pun_1.pnid;
    return ret_val;


L_punnom:
    ret_val = pun_1.pno;
    return ret_val;
} /* punids_ */

doublereal punids_(void)
{
    return punids_0_(0);
    }

doublereal punnom_(void)
{
    return punids_0_(1);
    }

