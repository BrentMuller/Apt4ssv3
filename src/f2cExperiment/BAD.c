/* BAD.f -- translated by f2c (version 20100827).
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
static integer c__4 = 4;
static integer c__10 = 10;
static integer c__3 = 3;
static integer c__13 = 13;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__2 = 2;

/* *** SOURCE FILE : M0001039.V08   *** */

/* Subroutine */ int bad_(integer *icntrl, integer *itype, char *id, integer *
	value, ftnlen id_len)
{
    /* Initialized data */

    static char blank[3] = "   ";
    static char star[2] = "**";
    static integer ncol = 4;
    static char equal[1] = "=";

    /* System generated locals */
    static doublereal equiv_0[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define aa (equiv_0)
    static integer ic;
#define ii ((integer *)equiv_0)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen);
    static integer irlse;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer input;
    static logical bufful;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer icntrx;

/* ---  ROUTINE TO FORMAT AND PRINT LINES OF PRINT FOR DEBUGGING */
/* ---  EACH LINE CONTAINS UP TO SIX VALUES WITH IDENTIFIERS FOR EACH */
/* ---  ICNTRL=-1  MEANS RELEASE THE BUFFER (DARRAY) FOR PRINTING AND BLNK */
/* ---  ICNTRL=0 MEANS BLANK THE BUFFER AND SET COLUMN POINTER NCOL TO 4 */
/* ---  ICNTRL GT 0 MEANS  TO PLACE ICNTRL ITEMS INTO THE BUFFER AND */
/* ---  ICNTRL=-N MEANS PRINT N ITEMS AND THEN RELEASE BUFFER TO PRINT. */
/* ---  AUTOMATICALLY PRINT THE BUFFER AS ROOM IS EXHAUSTED */
/* ---  ITYPE =0 MEANS PRINT THE INTEGER AT VALUE */
/* ---    AND =1 MEANS PRINT THE DOUBLE PRECISION */
/* ---  ID IS THE 4 CHARACTER IDENTIFYING NAME FOR VALUE AND VALUE */
/* ---     IS THE DATA TO BE FORMATTED INTO THE PRINT LINE. */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */






/* ---     BUFFUL IS A FLAG TO SIGNAL THAT A BUFFER IS NOW FULL */
/* ---     SO THAT IT SHOULD NOW BE EMPTIED BEFORE INSERTING MORE DATA */

    /* Parameter adjustments */
    --value;

    /* Function Body */
/* --- */
/* ---  IC IS A COUNT DOWN VARIABLE FOR CASES WHEN ICNTRL GT 1 */
    ic = 0;
    bufful = FALSE_;
/* ---     TRANSFER ICNTRL TO ICNTRX SO ICNTRL IS NOT ALTERED */
    icntrx = *icntrl;
/* ---     THIS IS A PATCH TO ENABLE DUMPING OF DATA AT END OF CALL */
/* ---     IF ICNTRX IS NEGATIVE, THEN DATA SHOULD BE DUMPED AT */
/* ---     AT THE END OF THE CURRENT CALL */
    irlse = 1;
    if (icntrx < 0) {
	irlse = -1;
    }
/* ---     IF ID IS ZERO AND ICNTRX IS NEGATIVE THEN RELEASE NOW */
    if (*(unsigned char *)id == ' ' && icntrx < 0) {
	goto L300;
    }
/* ---     SET ICNTRX POSITIVE, SINCE IRLSE HOLDS THE NEGATIVE INDICATION */
    icntrx = abs(icntrx);
    if (icntrx < 0) {
	goto L300;
    } else if (icntrx == 0) {
	goto L100;
    } else {
	goto L200;
    }

/* ---  INITIALIZE THE BUFFER BY BLANK FILLING AND COLUMN SETTING */
L100:
    s_copy(darray_1.darray, blank, (ftnlen)120, (ftnlen)3);
    ncol = 4;
    if (! bufful) {
	goto L999;
    }
/* ---  BUFFER HAS JUST BEEN AUTOMATICALLY EMPTIED.  NOW INSERT DATA */
    bufful = FALSE_;
    goto L210;

/* ---   ADD A NEW DATA ELEMENT INTO THE BUFFER LINE */
L200:
    bufful = TRUE_;
    if (ncol + 18 > 120) {
	goto L300;
    }
L210:
    cform_(blank, darray_1.darray, &ncol, &c__1, (ftnlen)3, (ftnlen)120);
    ++ncol;
    ++ic;
/* ---   PLACE AN ID FOR THE FIRST ARRAY EL, COUNTERS THEREAFTER */
    if (ic == 1) {
	cform_(id, darray_1.darray, &ncol, &c__4, (ftnlen)4, (ftnlen)120);
    }
    if (ic > 1) {
	iconv_(&ic, darray_1.darray, &ncol, &c__4, (ftnlen)120);
    }
    ncol += 4;
    cform_(equal, darray_1.darray, &ncol, &c__1, (ftnlen)1, (ftnlen)120);
    ++ncol;
/* ---   BRANCH BASED ON TYPE OF DATA -- INTEGER OR REAL */
    if (*itype == 0) {
/* ---   ADD AN INTEGER TO THE LINE BUFFER */
/* ---  THE INTEGER JJ IS SETUP BY THE MOVEMENT OF VALUE INTO AA */
	iconv_(&value[ic], darray_1.darray, &ncol, &c__10, (ftnlen)120);
	ncol += 10;
	cform_(blank, darray_1.darray, &ncol, &c__3, (ftnlen)3, (ftnlen)120);
	ncol += 3;
    } else if (*itype == 1) {
/* ---   ADD A REAL TO THE LINE BUFFER */
/* ---  CARE MUST BE TAKEN TO TRANSFER DATA TO A DOUBLE WORD  BOUNDARY */
	ii[0] = value[(ic << 1) - 1];
	ii[1] = value[ic * 2];
/* ---  THE DOUBLE VALUE IS NOW AVAILABLE IN AA THRU EQUIVALENCE */
	input = value[(ic << 1) - 1];
	fconv_(aa, darray_1.darray, &ncol, &c__13, &c__5, (ftnlen)120);
	ncol += 13;
    } else {
	cform_("******", darray_1.darray, &ncol, &c__6, (ftnlen)6, (ftnlen)
		120);
	ncol += 13;
    }
    goto L999;


/* ---   PRINT THE BUFFER AND BLANK THE LINE */
L300:
/* ---  IF THE BUFFER IS EMPTIED AUTOMATICALLY, MARK IT WITH STARS */
    if (! bufful) {
	goto L310;
    }
    if (irlse > 0) {
	cform_(star, darray_1.darray, &c__2, &c__2, (ftnlen)2, (ftnlen)120);
    }
L310:
    cprint_(darray_1.darray, (ftnlen)120);
    goto L100;
/* --- */
L999:
/* ---  CHECK TO SEE IF AN ARRAY HAS BEEN EXHAUSTED */
    if (icntrx > 0 && ic < icntrx) {
	goto L200;
    }
/* ---     IF IRLSE IS NEGATIVE THEN THE BUFFER SHOULD BE */
/* ---     RELEASED NOW */
    if (irlse > 0) {
	goto L9999;
    }
    if (ncol == 4) {
	goto L9999;
    }
/* ---     DATA IS PRESENT SO RELEASE THE BUFFER */
    cprint_(darray_1.darray, (ftnlen)120);
    ncol = 4;

L9999:
    return 0;
} /* bad_ */

#undef ii
#undef aa


