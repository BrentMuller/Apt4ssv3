/* SET.f -- translated by f2c (version 20100827).
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
    integer pgc, pgcn, ilc, ixc;
} work_;

#define work_1 work_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__39 = 39;
static integer c__40 = 40;
static integer c__4 = 4;

/* *** SOURCE FILE : M0000732.V07   *** */


/* .....FORTRAN ROUTINE              ..SET..     HL GRAY 3/68         *ID* */
/* Subroutine */ int set_(integer *ln)
{
    /* Local variables */
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
    static integer ln1;
#define can ((doublereal *)&_BLNK__1 + 40)
    extern integer page_(integer *);
    extern /* Subroutine */ int help_(void);
    static integer sqnc;
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int record_(integer *), cprint_(char *, ftnlen);


/* FORTRAN SUBROUTINE 'SET(LN)'  -- SET LOCATION COUNTER TO LINE */

/* PURPOSE      'SET'    SETS THE INTERPRETER PSEUDOLOCATION  COUNTER, */
/*              'ILC' AND OTHER DEPENDENT VARIABLES TO THE VALUES */
/*              CORRESPONDING TO THE INPUT LINE. */

/* LINKAGE      CALL SET(LN) */

/*              WHERE */
/*              LN IS ANY LINE */

/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */








/* WORK--COMMON CONTAINING WORKING VARIABLES */


/*     ------------------- */




/* --------------------------------------------------------------------- */



/*         LN IS ANY LINE(PAGE AND INDEX) */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




    /* Parameter adjustments */
    --ln;

    /* Function Body */
    ln1 = abs(ln[1]);
    if (ln1 > 0 && ln1 <= 400 && (ln[2] > 0 && ln[2] <= 256)) {
	goto L100;
    }
    record_(&sqnc);
    cform_("029007 UNDEFINED LABEL REFERENCED. ISN=", darray_1.darray, &c__1, 
	    &c__39, (ftnlen)39, (ftnlen)120);
    iconv_(&sqnc, darray_1.darray, &c__40, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    help_();

/*        SET LOCATION COUNTER TO BEGINNING OF PAGE */

L100:
    work_1.ilc = page_(&ln[1]);

/*        SET NEW PAGE NUMBER AND INDEX */

    work_1.pgc = ln[1];

    work_1.ixc = ln[2];


/*        SET NUMBER OF WORDS ON CURRENT PAGE */

    work_1.pgcn = pp[work_1.ilc] + 2;

/*        ADVANCE LOCATION COUNTER TO INSTRUCTION */

    work_1.ilc = work_1.ilc + work_1.ixc - 1;
    return 0;
} /* set_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


