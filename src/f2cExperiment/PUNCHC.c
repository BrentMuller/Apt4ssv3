/* PUNCHC.f -- translated by f2c (version 20100827).
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
    integer1 puncod[128];
} puntab_;

#define puntab_1 puntab_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__2 = 2;
static integer c__48 = 48;

/* *** SOURCE FILE : PUNCHC00.ORG   *** */

/* Subroutine */ int punchc_0_(int n__, integer *n, char *a, integer *j, 
	integer *k, ftnlen a_len)
{
    /* Initialized data */

    static integer1 ilegal = 238;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, l, m, ic, jc;
    static char infil[512];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), tapepn_(integer1 *, integer *), cprint_(char *, 
	    ftnlen);
    static char outfil[512];
    static integer1 punout[512];


/*  * PUNCHC *   VAX-11 FORTRAN 77 VERSION 29.11.82 E.MCLELLAN */
/*               REVISED FOR CHARACTER HANDLING 5.9.85 E.MCL. */

/*  PURPOSE     TO GENERATE REQUIRED PAPER TAPE CODES FOR CHARACTERS */

/*  CALLING SEQUENCE */
/*              CALL PUNCHC(N,A,J,K) */
/*  ARGUMENTS */
/*              N NUMBER OF CHARACTERS IN A */
/*              A CHARACTER STRING TO BE PUNCHED */
/*              J NUMBER OF CHARACTERS PUNCHED */
/*              K -2  BLANKS AND PERIODS IGNORED */
/*                -1  PERIODS IGNORED */
/*                 0  BLANKS IGNORED */
/*                >0  BLANKS ARE PROCESSED */

/*  ALTERNATE ENTRY */
/*              CALL PUNCHD(N,A,J,K) */


/* ...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA */
/* ...ON OTHER SYSTEMS */




/*      DATA ILEGAL/ZEE/ */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    switch(n__) {
	case 1: goto L_punchd;
	}




L_punchd:

    s_copy(infil, a, (ftnlen)512, (ftnlen)512);

    m = *n;

    if (*k <= 0) {
	l = 1;
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (*(unsigned char *)&infil[i__ - 1] == ' ' && (*k == 0 || *k == 
		    -2)) {
		goto L10;
	    } else if (*(unsigned char *)&infil[i__ - 1] == '.' && *k < 0) {
		goto L10;
	    } else {
		*(unsigned char *)&outfil[l - 1] = *(unsigned char *)&infil[
			i__ - 1];
		++l;
	    }
L10:
	    ;
	}
	m = l - 1;
    } else {

	s_copy(outfil, infil, (ftnlen)512, (ftnlen)512);

    }

/* .....CONVERT TO REQUIRED TAPE CODE */

    jc = 0;
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ic = *(unsigned char *)&outfil[i__ - 1] + 1;
	if (puntab_1.puncod[ic - 1] == ilegal) {
	    cform_("**** ILLEGAL CHARACTER CONVERSION IN PUNCHC ****", 
		    darray_1.darray, &c__2, &c__48, (ftnlen)48, (ftnlen)120);
	    cprint_(darray_1.darray, (ftnlen)120);
	    goto L100;
	}

	++jc;
	punout[jc - 1] = puntab_1.puncod[ic - 1];
L100:
	;
    }

/* .....OUTPUT TO PUNCH FILE, JC IS NO OF BYTES */

    tapepn_(punout, &jc);
    *j = jc;
    return 0;
} /* punchc_ */

/* Subroutine */ int punchc_(integer *n, char *a, integer *j, integer *k, 
	ftnlen a_len)
{
    return punchc_0_(0, n, a, j, k, a_len);
    }

/* Subroutine */ int punchd_(integer *n, char *a, integer *j, integer *k, 
	ftnlen a_len)
{
    return punchc_0_(1, n, a, j, k, a_len);
    }

