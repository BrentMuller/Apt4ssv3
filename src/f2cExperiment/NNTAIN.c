/* NNTAIN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : NNTAIN00.ORG   *** */

integer nntain_(doublereal *a, doublereal *b, doublereal *c__)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static doublereal low, high;


/*  * NNTAIN *  VAX11 FORTRAN 77 VERSION  27.8.82  E.MCLELLAN */

/*  PURPOSE     TO TEST IF A FLOATING POINT NUMBER LIES */
/*              WITHIN A CLOSED INTERVAL */

/*  CALLING SEQUENCE */
/*              IF (NNTAIN(A,B,C)) 1,2,3 */
/*  ARGUMENTS */
/*              A IS ONE LIMIT OF THE CLOSED INTERVAL */
/*              B IS FLOATING POINT NUMBER TO BE TESTED */
/*                TO SEE IF IT FALLS IN THE CLOSED INTERVAL */
/*              C IS THE OTHER LIMIT OF THE CLOSED INTERVAL */

/*              INTEGER RETURNED = 1  IF B LIES IN CLOSED INTERVAL */
/*                               =-1  IF B DOES NOT LIE IN CLOSED */
/*                                    INTERVAL */
/*                               = 0  IF ERROR CONDITION APPLIES */
/*                                    I.E. A=C */


    if (*a == *c__) {
/* .....ERROR CONDITION A=C */
	ret_val = 0;
	return ret_val;
    } else {
/* .....SET UP UPPER AND LOWER LIMITS TO CLOSED INTERVAL */
	if (*a > *c__) {
	    low = *c__;
	    high = *a;
	} else {
	    low = *a;
	    high = *c__;
	}
/* .....TEST IF B WITHIN CLOSED INTERVAL */
	if (*b >= low && *b <= high) {
/* .....YES */
	    ret_val = 1;
	    return ret_val;
	} else {
/* .....NO */
	    ret_val = -1;
	    return ret_val;
	}
    }
    return ret_val;
} /* nntain_ */

