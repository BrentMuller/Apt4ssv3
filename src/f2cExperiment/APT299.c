/* APT299.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* *** SOURCE FILE : M0004142.V09   *** */

/* .....FORTRAN SUBROUTINE  ....APT299         8/68                 AR,HG */
/* .....FORTRAN SUBROUTINE      APT299                4/18/68    AR */

/* PURPOSE      TO CREATE AND WRITE EXFILE RECORDS FROM DATA SUPPLIED BY */
/*              THE PART PROGRAM. */

/* LINKAGE      CALL APT299(ARG1,ARG2,ARG3,ARG4) */

/* NOTE 1       APT299 IS CALLED REPEATEDLY BY THE PART PROGRAM UNTIL ALL */
/*              ARGUMENTS NECESSARY FOR THE CREATION OF THE EXFILE RECORD */
/*              HAVE BENN PASSED. */

/* ARGUMENTS    ARG1           IN THE FIRST CALL TO APT299 ARG1 = THE */
/*                             NUMBER OF DATA ITEM ARGUMENT PAIRS. */
/*                             THEREAFTER IT IS THE FIRST ELEMENT OF A */
/*                             DATA ITEM ARGUMENT PAIR. */
/*              ARG2           IN THE FIRST CALL TO APT299 ARG2 = THE */
/*                             MAJOR WORD OF THE PART PROGRAM STATEMENT */
/*                             THAT IS CAUSING AN EXFILE RECORD TO BE */
/*                             CREATED. THEREAFTER IT IS THE SECOND */
/*                             ITEM OF A DATA ITEM ARGUMENT PAIR. */
/*              ARGK (K=1,3)   THE FIRST ELEMENT OF A DATA ITEM ARGUMENT */
/*                             PAIR. IT IS USED AS AN INDEX ON THE CLSIZE */
/*                             ARRAY TO LOCATE THE SIZE OF AN ITEM. */
/*              ARGL (L=2,4)   THE SECOND ELEMENT OF A DATA ITEM ARGUMENT */
/*                             PAIR. IT IS EITHER A SINGLE DATA ITEM OR */
/*                             AN ARRAY CONTAINING A STRING OF DATA ITEMS */

/* NOTE 2       A DATA ITEM ARGUMENT PAIR OCCURS FOR EACH SINGLE ITEM OR */
/*              EACH STRING OF ITEMS TO BE INCLUDED IN THE EXFILE RECORD. */

/* SUBSIDARY    MACHINE LANGUAGE SUBROUTINE        RECORD */


/* Subroutine */ int apt299_(integer *arg1, integer *arg2, integer *arg3, 
	integer *arg4)
{
    /* Initialized data */

    static logical first = TRUE_;
    static integer iunorm = 1308622848;
    static integer clsize[27] = { 1,1,4,4,7,7,4,10,10,10,7,10,0,0,79,10,0,0,0,
	    12,3,3,1,1,1,1,0 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, l, t, w[200], l1, nr, ir;
    static logical odd;
    static integer ido;
    extern integer bcdf_(char *, ftnlen);
    static integer size, blank, start;
    extern /* Subroutine */ int record_(integer *);
    static integer nopair;
    extern /* Subroutine */ int ewrite_(integer *, integer *, integer *, 
	    integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



/* ......  LOCAL VARIABLES */


/* ...                SYSTEM I/O FILES */






    /* Parameter adjustments */
    --arg4;
    --arg3;
    --arg2;
    --arg1;

    /* Function Body */

/* ******************************************************************** */


/* ... CHECK IF THIS IS THE FIRST CALL TO APT299 FOR THE CURRENT EXFILE */
/* ... RECORD BEING CREATED. IF NOT,CONTINUE INSERTING ITEMS IN THE */
/* ... RECORD. IF IT IS THE FIRST CALL,DO HOUSEKEEPING. */

    if (! first) {
	goto L15;
    }

/* ... SET FIRST CALL FLAG FALSE. */

    first = FALSE_;

/*    INITIALIZE BLANK */
    blank = bcdf_("    ", (ftnlen)4);

/* ... SET NOPAIR = THE NUMBER OF DATA ITEM ARGUMENT PAIRS. */

    nopair = arg1[1];

/* ... SET FIRST RECORD WORD = MAJOR WORD. */
/* ... SET SECOND RECORD WORD = PART PROGRAM STATEMENT INTERNAL SEQUENCE */
/* ... NUMBER */

    w[2] = iunorm;
    w[0] = arg2[1];
    w[1] = arg2[2];
    record_(&w[3]);

/* ... IF THERE ARE NO MORE ARGUMENTS,ADD ALPHANUMERIC DATA ITEM */
/* ... AND WRITE THE RECORD. */

    if (nopair > knumbr_1.k0) {
	goto L10;
    }
/* L5: */
    w[6] = iunorm;
    w[7] = knumbr_1.k2;
    w[8] = blank;
    w[9] = blank;
    j = 10;
    goto L80;

/* ... INITIALIZE RECORD INDEX */

L10:
    j = knumbr_1.k6;

/* ... INSERT DATA ITEMS IN RECORD. */
/* ... INITIALIZE DO LOOP INDEX */

    ido = knumbr_1.k1;
L15:
    start = ido;
    i__1 = nopair;
    for (i__ = start; i__ <= i__1; ++i__) {

/* ... IF I IS EVEN,SET ODD = .FALSE. INDICATING ARG1 AND ARG2 ARE TO BE */
/* ...    USED DURING THIS ITERATION. */
/* ... IF I IS ODD, SET ODD = .TRUE. INDICATING ARG3 AND ARG4 ARE TO BE */
/* ...    USED DURING THIS ITERATION. */

	odd = TRUE_;
	if (i__ - knumbr_1.k2 * (i__ / knumbr_1.k2) == knumbr_1.k0) {
	    odd = FALSE_;
	}

/* ... INSERT ITEM INDICATOR CODE IN RECORD. */

	j += knumbr_1.k2;
	w[j - 2] = iunorm;
	w[j - 1] = arg1[1];
	if (odd) {
	    w[j - 1] = arg3[1];
	}
	t = w[j - 1];
	if (t > knumbr_1.k2 && t < knumbr_1.k27) {
	    w[j - 1] = knumbr_1.k4;
	}
	if (t == knumbr_1.k27) {
	    w[j - 1] = knumbr_1.k3;
	}

/* ... SET SIZE = CLSIZE FOR THIS ITEM. FROM THE MAGNITUDE OF SIZE */
/* ... DETERMINE THE TYPE OF THE ITEM. */

	size = clsize[t - 1];
	if ((i__2 = size - knumbr_1.k1) < 0) {
	    goto L20;
	} else if (i__2 == 0) {
	    goto L40;
	} else {
	    goto L30;
	}

/* ... ALPHANUMERIC DATA ITEM STRING --- INSERT NUMBER OF ITEMS,TOTAL */
/* ... CHARACTER COUNT, AND DATA ITEMS IN THE RECORD. */
/* ... RESET SIZE = NUMBER OF ITEMS IN THE STRING. */

L20:
	j += knumbr_1.k4;
	w[j - 2] = iunorm;
	w[j - 4] = iunorm;
	size = arg4[1];
	w[j - 1] = arg4[2];
	if (odd) {
	    goto L22;
	}
	size = arg2[1];
	w[j - 1] = arg2[2];
	goto L25;
L22:
	if (w[j - 1] != knumbr_1.k0) {
	    goto L25;
	}
	w[j - 3] = knumbr_1.k2;
	j += knumbr_1.k2;
	w[j - 2] = blank;
	w[j - 1] = blank;
	goto L80;

/* ... SET STRING ARRAY SUBSCRIPT =3. */

L25:
	w[j - 3] = (size + knumbr_1.k1) / knumbr_1.k2;
	l = knumbr_1.k3;
	goto L50;

/* ... GEOMETRIC VARIABLE --- INSERT NUMBER OF ITEMS AND GEOMETRIC DATA. */

L30:
	j += knumbr_1.k2;
	w[j - 2] = iunorm;
	w[j - 1] = size;

/* ... FLOATING POINT OR ALPHANUMERIC DATA ITEM.--- SET ARRAY SUBSCRIPT */
/* ... =1. */

L40:
	l = knumbr_1.k1;

	size <<= 1;
/* ... ADD ARRAY ELEMENTS TO RECORD. */
L50:
	l1 = l;
	i__2 = size;
	for (l = l1; l <= i__2; ++l) {
	    j += knumbr_1.k1;
	    w[j - 1] = arg2[l];
	    if (odd) {
		w[j - 1] = arg4[l];
	    }
/* L60: */
	}

/* ... CHECK IF IT IS NECESSARY TO RETURN TO THE PART PROGRAM FOR MORE */
/* ... ARGUMENTS. */

	if (! odd || i__ == nopair) {
	    goto L70;
	}
	ido = i__ + 1;
	goto L99;
L70:
	;
    }

/* ... SET THIRD RECORD WORD = NUMBER OF DATA ITEMS, RESET FIRST CALL FLAG */
/* ... .TRUE., WRITE RECORD TO EXFILE ,AND RETURN TO CALLER. */

L80:
    w[4] = iunorm;
    if (j - knumbr_1.k2 * (j / knumbr_1.k2) == knumbr_1.k0) {
	goto L85;
    }
    ++j;
    w[j - 1] = blank;
L85:
    w[5] = j / 2 - knumbr_1.k3;
    first = TRUE_;
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, w, &j, &ir);
L99:
    return 0;
} /* apt299_ */

