/* ASERCH.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__1 = 1;

/* *** SOURCE FILE : ASERCH00.V01   *** */

/* Subroutine */ int aserch_(integer *no, integer *irecno, integer *iret)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, n;
    static doublereal rec[256];
    static integer irec[3], irew, nwds;
    extern /* Subroutine */ int ataprd_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *), 
	    atapop_(integer *, integer *, integer *);


/*  * ASERCH *  VAX-11 FORTRAN 77 VERSION   13.10.82  E.MCLELLAN */

/*  PURPOSE     TO POSITION A FILE TO START OF REQUIRED RECORD */

/*  CALLING SEQUENCE */
/*              CALL ASERCH(NO,IRECNO,IRET) */
/*  ARGUMENTS */
/*              NO         FILE NUMBER */
/*              IRECNO     REQUIRED RECORD */
/*              IRET.LT.0  NORMAL RETURN */
/*                  .EQ.0  ZERO OR NEGATIVE RECORD NUMBER */
/*                  .EQ.2  ABNORMAL CONDITION RETURNED BY ATAPRD */
/*                  .EQ.3  ERROR BACKSPACING FILE */
/*                  .EQ.4  ERROR REWINDING FILE */

/*  ALTERNATE ENTRY    ****    COMMENTED OUTT   **** */
/*              CALL SEARCH(NO,IRECNO,IRET) */



/*      ENTRY SEARCH(NO,IRECNO,IRET) */

/* .....CHECK VALUE IN IRECNO - MUST BE GT ZERO */
    /* Parameter adjustments */
    --no;

    /* Function Body */
    if (*irecno <= 0) {
	*iret = 0;
	return 0;
    } else {
	irew = 0;

/* .....READ NEXT RECORD FROM FILE */
L10:
	ataprd_(&no[1], iret, &nwds, &c__2, irec, &c__3, rec, &c__0);
	if (*iret < 0) {
/* .....IS THIS THE RECORD BEFORE THE REQUIRED RECORD */
	    if (irec[0] == *irecno - 1) {
/* .....YES SO NEXT RECORD WILL BE THE REQUIRED RECORD */
		return 0;
/* .....NO IS NEXT RECORD LT REQUIRED RECORD - READ NEXT RECORD */
	    } else if (irec[0] + 1 < *irecno) {
/* .....YES */
		goto L10;
/* .....N0  IS REQUIRED RECORD NEARER START OF FILE OR CURRENT RECORD */
	    } else if (*irecno > irec[0] / 2) {
/* .....NEARER CURRENT RECORD - BACKSPACE N TIMES BY CALLING ATAPOP */
		n = irec[0] - *irecno + 1;
		i__1 = n;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    atapop_(&no[1], &c__3, iret);
		    if (*iret > 0) {
			*iret = 3;
			return 0;
		    }
/* L20: */
		}
		return 0;
/* .....NEARER START - REWIND AND SEARCH */
	    } else {
		atapop_(&no[1], &c__1, iret);
		if (*iret > 0) {
		    *iret = 4;
		    return 0;
		} else {
		    goto L10;
		}
	    }
/* .....NON NORMAL RETURN FROM ATAPRD */
	} else if (*iret == 0) {
/* .....EOF ENCOUNTERED */
	    if (irew == 1) {
		*iret = 0;
		return 0;
	    } else {
/* .....REWIND FILE */
		atapop_(&no[1], &c__1, iret);
		if (*iret > 0) {
		    *iret = 4;
		    return 0;
		} else {
		    irew = 1;
		    goto L10;
		}
	    }
	} else {
/* .....ABNORMAL CONDITION RETURNED BY ATAPRD */
	    *iret = 2;
	    return 0;
	}
    }
    return 0;
} /* aserch_ */

