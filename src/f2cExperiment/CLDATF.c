/* CLDATF.f -- translated by f2c (version 20100827).
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

static integer c__93 = 93;

/* *** SOURCE FILE : M0011487.V03   *** */


/* .....FORTRAN SUBROUTINE     CLDATF */

/* PURPOSE      TO RETRIEVE THE U OR V COORDINATE OR THE PATCH NUMBER */
/*              OF THE PART OR DRIVE SURFACE OF A PREVIOUS CL DATA */
/*              FROM EXFILE AND STORE IT IN RESULT. */

/* LINKAGE      CALL CLDATF(RESULT,ARG1,ARG2,ARG3) */

/* ARGUMENTS    RESULT  REAL VARIABLE TO CONTAIN THE DESIRED SCALAR. */
/*              ARG1    REAL NUMBER OF CLDAT SECTION. */
/*              ARG2    INTEGER DESIRED SCALAR NAME. */
/*              ARG3    REAL NUMBER OF DESIRED POINT. */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          ATAPER */

/* Subroutine */ int cldatf_(doublereal *result, doublereal *arg1, integer *
	arg2, doublereal *arg3)
{
    /* Initialized data */

    static logical first = TRUE_;

    static doublereal p[6];
    static integer ii, iee;
    extern integer bcdf_(char *, ftnlen);
    static integer isct, ipnt, ityp, narg2[6];
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), ataper_(
	    doublereal *, integer *, integer *, integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




    if (first) {
	narg2[0] = bcdf_("UDS ", (ftnlen)4);
	narg2[1] = bcdf_("VDS ", (ftnlen)4);
	narg2[2] = bcdf_("PDS ", (ftnlen)4);
	narg2[3] = bcdf_("UPS ", (ftnlen)4);
	narg2[4] = bcdf_("VPS ", (ftnlen)4);
	narg2[5] = bcdf_("PPS ", (ftnlen)4);
	first = FALSE_;
    }

    for (ii = 1; ii <= 6; ++ii) {
	if (narg2[ii - 1] == *arg2) {
	    goto L20;
	}
/* L10: */
    }

L15:
    error_(&c__93, "CLDATF  ", (ftnlen)8);
    *result = 0.;

    return 0;
L20:
    ityp = ii / 4 + 8;
    isct = (integer) (*arg1);
    ipnt = (integer) (*arg3);
    ataper_(p, &ipnt, &isct, &ityp, &iee);
    if (iee == 0) {
	goto L30;
    }
    goto L15;
L30:
    if (ii > 3) {
	ii += -3;
    }
    *result = p[ii - 1];
/* L40: */
    return 0;
} /* cldatf_ */

