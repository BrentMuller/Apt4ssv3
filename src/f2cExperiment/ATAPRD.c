/* ATAPRD.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__64 = 64;

/* *** SOURCE FILE : ATAPRD.ORG   *** */


/*  *  ATAPRD  *  FORTRAN 77 VERSION  1-MAR-1988 E.MCLELLAN */

/*  PURPOSE      TO READ AN APT 111 FORMATTED CLFILE */
/*               RESTRICTED TO TWO OUTPUT ARRAYS ONLY */

/*  CALLING SEQUENCE */
/*               CALL ATAPRD(NO,IRET,NW,N,A1,N1,A2,N2) */
/*  ARGUMENTS */
/*               NO         FILE NUMBER */
/*                         FOR NC 360 HELD IN SECOND HALF */
/*                         OF DOUBLE PRECISION WORD */
/*               IRET.LT.0  NORMAL RETURN */
/*                   .EQ.0  END OF FILE ENCOUNTERED */
/*                   .GT.0  ABNORMAL CONDITION */
/*               NW         NO OF DATA ITEMS RETURNED IN A2 */
/*               N          NO OF ARRAYS SPECIFIED IN CALLING SEQUENCE */
/*               AI         ARRAY INTO WHICH DATA IS TO BE READ */
/*               NI         NO OF ITEMS IN ARRAY AI */
/*                          IF N2=0 ON ENTRY - ALL REMAINING ITEMS ARE */
/*                          TRANSFERRED TO ARRAY A2 AND NO RETURNED IN NW */
/*                          NOTE: FIRST 3 ITEMS TO BE TRANSFERRED */
/*                                ARE ASSUMED INTEGER THE REMAINDER */
/*                                REAL*8 */
/* Subroutine */ int ataprd_(integer *no, integer *iret, integer *nw, integer 
	*n, integer *a1, integer *n1, doublereal *a2, integer *n2)
{
    /* System generated locals */
    integer i__1;
    static doublereal equiv_1[256];

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__, i1, id, nn;
#define rec ((real *)equiv_1)
#define drec (equiv_1)
#define irec ((integer *)equiv_1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer nwrds;
    extern /* Subroutine */ int cprint_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___5 = { 1, 0, 1, 0, 0 };



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

    io___5.ciunit = id;
    *iret = s_rsue(&io___5);
    if (*iret != 0) {
	goto L100001;
    }
    *iret = do_uio(&c__1, (char *)&nwrds, (ftnlen)sizeof(integer));
    if (*iret != 0) {
	goto L100001;
    }
    i__1 = nwrds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*iret = do_uio(&c__1, (char *)&rec[i__], (ftnlen)sizeof(real));
	if (*iret != 0) {
	    goto L100001;
	}
    }
    *iret = e_rsue();
L100001:
    if (*iret < 0) {
	goto L90;
    }
    if (*iret > 0) {
	goto L99;
    }

    i__1 = *n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a1[i__] = irec[i__];
/* L10: */
    }

    if (*n == 1) {
	*iret = -1;
    } else if (*n == 2) {

	if (*n2 == 0) {
	    *nw = (nwrds - *n1) / 2;
	    nn = *nw;
	} else {
	    nn = *n2;
	}

	i1 = (*n1 + 2) / 2;
	i__1 = nn;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    a2[i__] = drec[i1 + i__ - 1];
/* L20: */
	}
	*iret = -1;
    } else {
	cform_(" *** ERROR IN CALL TO ATAPRD - MAXIMUM OF TWO ARRAYS ALLOWED"
		" ***", darray_1.darray, &c__1, &c__64, (ftnlen)64, (ftnlen)
		120);
	cprint_(darray_1.darray, (ftnlen)120);
	*iret = 1;
    }
    return 0;

L90:
    *iret = 0;
    return 0;
L99:
    *iret = 1;
    return 0;
} /* ataprd_ */

#undef irec
#undef drec
#undef rec


