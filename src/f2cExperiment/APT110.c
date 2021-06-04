/* APT110.f -- translated by f2c (version 20100827).
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

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__6 = 6;
static integer c__3 = 3;

/* *** SOURCE FILE : M0011443.W01   *** */

/* Subroutine */ int apt110_(doublereal *arg1, doublereal *arg2)
{
    /* Initialized data */

    static char xsmil[6*7] = "SCON  " "SMIL  " "GCLEAR" "GOMILL" "INTSEC" 
	    "GOLOFT" "PLOTFT";
    static doublereal zero = 0.;

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, nt;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd;
    static doublereal zwi;
    static integer mode;
    extern /* Subroutine */ int scon_(void), smil_(void);
    static char test[6];
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static char badmsg[66];
    extern /* Subroutine */ int gclear_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int gomill_(void), intsec_(void), holfrm_(
	    doublereal *, char *, integer *, integer *, integer *, ftnlen), 
	    cprint_(char *, ftnlen);
    static doublereal fdummy[2];
    extern /* Subroutine */ int golovo_(doublereal *);

/* -- MAIN PROGRAM FOR REGIONAL MILLING(SMIL OR SCON) */
/* -- PART PROGRAMMER INPUT LANGUAGE IS RESIDENT IN BLANK COMMON. */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    nt = (integer) sscan[1];
    nt <<= 1;
    if (ibugg_1.ibug == 11) {
	i__1 = -nt;
	bad_(&i__1, &c__2, "CANN", sscan, (ftnlen)4);
    }
    holfrm_(arg1, test, &c__1, &c__6, &nwd, (ftnlen)6);
    for (i__ = 1; i__ <= 7; ++i__) {
	if (s_cmp(test, xsmil + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L8;
	}
	mode = 5;
	fdummy[0] = zero;
	fdummy[1] = sscan[1] - 1.;
	zwi = sscan[0];
	apt094_(&mode, fdummy, sscan);
	sscan[0] = zwi;
	switch (i__) {
	    case 1:  goto L1;
	    case 2:  goto L2;
	    case 3:  goto L3;
	    case 4:  goto L4;
	    case 5:  goto L5;
	    case 6:  goto L6;
	    case 7:  goto L6;
	}
L1:
	scon_();
	goto L30;
L2:
	smil_();
	goto L30;
L3:
	gclear_(arg2);
	goto L30;
L4:
	gomill_();
	goto L30;
L5:
	intsec_();
	goto L30;
L6:
	golovo_(arg2);
	goto L30;
L8:
	;
    }
/* L10: */
/* Writing concatenation */
    i__2[0] = 10, a__1[0] = " ARGUMENT ";
    i__2[1] = 6, a__1[1] = test;
    i__2[2] = 28, a__1[2] = " NOT VALID IN CALL TO APT110";
    s_cat(badmsg, a__1, i__2, &c__3, (ftnlen)66);
    cprint_(badmsg, (ftnlen)66);
L30:
    return 0;
} /* apt110_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


