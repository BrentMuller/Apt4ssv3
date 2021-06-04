/* PUNCHA.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__48 = 48;

/* *** SOURCE FILE : PUNCHA00.ORG   *** */

/* Subroutine */ int puncha_0_(int n__, integer *n, doublereal *a, integer *j,
	 integer *k)
{
    /* Initialized data */

    static integer1 ilegal = 238;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, l, m, ic, jc;
    static char infil[512];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), tapepn_(integer1 *, integer *), cprint_(char *, 
	    ftnlen);
    static char outfil[512];
    static integer1 punout[512];

    /* Fortran I/O blocks */
    static icilist io___3 = { 0, infil, 0, "(64A8)", 512, 1 };



/*  * PUNCHA *   VAX-11 FORTRAN 77 VERSION 29.11.82 E.MCLELLAN */

/*  PURPOSE     TO GENERATE REQUIRED PAPER TAPE CODES FOR BCD CHARACTERS */

/*  CALLING SEQUENCE */
/*              CALL PUNCHA(N,A,J,K) */
/*  ARGUMENTS */
/*              N NUMBER OF BCD CHARACTERS IN ARRAY A */
/*              A ARRAY CONTAINING BCD CHARACTERS */
/*              J IGNORED */
/*              K -2  BLANKS AND PERIODS IGNORED */
/*                -1  PERIODS IGNORED */
/*                 0  BLANKS IGNORED */
/*                >0  BLANKS ARE PROCESSED */

/*  ALTERNATE ENTRY */
/*              CALL PUNCHB(N,A,J,K) */


/* ...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA */
/* ...ON OTHER SYSTEMS */




/*      DATA ILEGAL/ZEE/ */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --a;

    /* Function Body */
    switch(n__) {
	case 1: goto L_punchb;
	}




L_punchb:

    s_wsfi(&io___3);
    for (i__ = 1; i__ <= 64; ++i__) {
	do_fio(&c__1, (char *)&a[(0 + (0 + (i__ << 3))) / 8], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfi();

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
	    cform_("**** ILLEGAL CHARACTER CONVERSION IN PUNCHA ****", 
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
    return 0;
} /* puncha_ */

/* Subroutine */ int puncha_(integer *n, doublereal *a, integer *j, integer *
	k)
{
    return puncha_0_(0, n, a, j, k);
    }

/* Subroutine */ int punchb_(integer *n, doublereal *a, integer *j, integer *
	k)
{
    return puncha_0_(1, n, a, j, k);
    }

