/* APT100.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__2 = 2;
static integer c__82 = 82;

/* *** SOURCE FILE : M0002807.V05   *** */

/* .....FORTRAN SUBROUTINE               APT100    3/69      SR,DE */
/* Subroutine */ int apt100_(integer *iflag, doublereal *arg)
{
    /* System generated locals */
    static doublereal equiv_4[1];

    /* Local variables */
    static integer i__, j;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer int__;
    extern integer bcdf_(char *, ftnlen);
    static doublereal real__;
#define temp (equiv_4)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define itemp ((integer *)equiv_4)
    static integer inext;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)


/*     PURPOSE       TO MOVE POINTS AND PATERNS USED AS ARGUMENTS */
/*                   IN THE DEFINITION OF A RANDOM PATERN TO THE LDA */
/*                   STAGING AREA, AND PERFORM ERROR CHECKS */

/*     CALLING SEQ   CALL APT100(IFLAG,ARG) */

/*     ARGUMENTS     FLAG  INDICATOR SHOWING TYPE OF PROCESSING DESIRED */
/*                   ARG   A POINT OR PATTERN WHOSE CANONICAL FORM IS TO */
/*                   BE MOVED TO THE LDA STAGING AREA */

/*     RESTRICTIONS  CURRENT VERSION CANNOT HANDLE */
/*                   NESTED PATTERN DEFINITIONS */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ...                BRANCH IF NOT INITIALIZATION CALL */
    /* Parameter adjustments */
    --arg;

    /* Function Body */
    if (*iflag != 0) {
	goto L100;
    }
/*                             INITIALIZE COMMON STORAGE INDEX */
    inext = 5;
/*                             INITIALIZE FIRST WORD OF COMMON STORAGE */
/*                             AREA TO NO ERROR CONDITION */
    bcanon[0] = 0.f;
    goto L900;
/* ...                IF ERROR HAS ALREADY OCCURRED IN THIS DEFINITION, */
/* ...                RETURN */
L100:
    if (bcanon[0] < 0.f) {
	goto L900;
    }
    if (ckdef_(&arg[1])) {
	goto L800;
    }
/* ...                BRANCH IF PATERN TYPE ARG */
    if (*iflag == 2) {
	goto L200;
    }
/* ...                PROCESS POINT TYPE ARG */
/*                             INSERT ALPHANUMERIC IDENTIFIER */
    itemp[0] = bcdf_("ZPOI", (ftnlen)4);
    itemp[1] = bcdf_("NT  ", (ftnlen)4);
    bcanon[inext - 1] = *temp;
/*                             INSERT CANONICAL FORM */
    for (i__ = 1; i__ <= 3; ++i__) {
	j = inext + i__;
	bcanon[j - 1] = arg[i__];
/* L110: */
    }
/*                             UPDATE STORAGE INDEX */
    inext += 4;
    goto L900;

/* ...                PROCESS PATERN ARG */
L200:
    apt094_(&c__2, &arg[1], &bcanon[inext - 1]);
    if (ckdef_(&arg[1])) {
	goto L800;
    }
/*                             INSERT ALPHANUMERIC IDENTIFIER */
    itemp[0] = bcdf_("ZPAT", (ftnlen)4);
    itemp[1] = bcdf_("RN  ", (ftnlen)4);
    bcanon[inext - 1] = *temp;
/*                             IF ARGUMENT PATERN IS ALSO RANDOM, ISSUE */
/*                             DIAGNOSTIC AND STORE ERROR FLAGS */
    real__ = bcanon[inext];
    if (real__ != 4.f) {
	goto L220;
    }
    error_(&c__82, "APT100  ", (ftnlen)8);
L800:
    bcanon[0] = -1.f;
    goto L900;
/*                             UPDATE STORAGE INDEX */
L220:
    int__ = (integer) (bcanon[inext + 1] + 1.00001f);
    inext += int__;
L900:
    return 0;
} /* apt100_ */

#undef bcanon
#undef itemp
#undef sscan
#undef canon
#undef temp
#undef can


