/* ATAPWT.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__2 = 2;
static integer c__63 = 63;
static integer c__1 = 1;

/* *** SOURCE FILE : ATAPWT.ORG   *** */


/*  *  ATAPWT  *  FORTRAN 77 VERSION   1-MAR-1988 E.MCLELLAN */

/*  PURPOSE     TO WRITE AN APT 111 FORMATTED CLFILE */
/*              RESTRICTED TO TWO INPUT ARRAYS MAXIMUM */

/*  CALLING SEQUENCE */
/*              CALL ATAPWT(NO,IRET,N,A1,N1,A2,N2) */
/*  ARGUMENTS */
/*              NO         FILE NUMBER */
/*                         FOR NC 360 HELD IN SECOND HALF */
/*                         OF DOUBLE PRECISION WORD */
/*              IRET.LT.0  NORMAL RETURN */
/*                  .GT.0  ABNORMAL CONDITION */
/*              N          NO OF ARRAYS AI SPECIFIED IN CALLING SEQUENCE */
/*              AI         ARRAY CONTAINING DATA TO BE WRITTEN TO FILE */
/*              NI         NO OF ITEMS IN ARRAY AI TO BE WRITTEN TO FILE */

/* Subroutine */ int atapwt_(integer *no, integer *iret, integer *num, 
	integer *a1, integer *n1, doublereal *a2, integer *n2)
{
    /* System generated locals */
    integer i__1;
    static doublereal equiv_1[256];

    /* Builtin functions */
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void);

    /* Local variables */
    static integer i__, id;
#define rec ((real *)equiv_1)
#define drec (equiv_1 + 2)
#define irec ((integer *)equiv_1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer nwrds;
    extern /* Subroutine */ int cprint_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___7 = { 1, 0, 0, 0, 0 };



/* .... ARGUMENTS */

/* .... LOCAL VARIABLES */

/* .... COMMON BLOCKS */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --no;
    --a1;
    --a2;

    /* Function Body */
    id = no[1];
    if (no[1] == 0) {
	id = no[2];
    }

    if (*num == 1) {
	nwrds = *n1;
    } else if (*num == 2) {
	nwrds = (*n2 << 1) + 3;
    } else {
	cform_(" *** ERROR IN CALL TO ATAPWT, MAXIMUM OF TWO ARRAYS ALLOWED "
		"***", darray_1.darray, &c__2, &c__63, (ftnlen)63, (ftnlen)120)
		;
	cprint_(darray_1.darray, (ftnlen)120);
	*iret = 1;
	return 0;
    }

    irec[0] = nwrds;
    for (i__ = 2; i__ <= 4; ++i__) {
	irec[i__ - 1] = 0;
/* L10: */
    }

    i__1 = *n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	irec[i__] = a1[i__];
/* L20: */
    }

    if (*num == 2) {
	i__1 = *n2;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    drec[i__ - 1] = a2[i__];
/* L30: */
	}
    }

    io___7.ciunit = id;
    *iret = s_wsue(&io___7);
    if (*iret != 0) {
	goto L100001;
    }
    i__1 = nwrds + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*iret = do_uio(&c__1, (char *)&rec[i__ - 1], (ftnlen)sizeof(real));
	if (*iret != 0) {
	    goto L100001;
	}
    }
    *iret = e_wsue();
L100001:

    return 0;
} /* atapwt_ */

#undef irec
#undef drec
#undef rec


