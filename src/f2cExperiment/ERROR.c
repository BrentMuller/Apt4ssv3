/* ERROR.f -- translated by f2c (version 20100827).
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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__18 = 18;
static integer c__19 = 19;
static integer c__8 = 8;
static integer c__27 = 27;
static integer c__5 = 5;
static integer c__36 = 36;
static integer c__3 = 3;
static integer c__39 = 39;
static integer c__44 = 44;
static integer c__17 = 17;
static integer c__61 = 61;
static integer c__69 = 69;
static integer c__10 = 10;

/* *** SOURCE FILE : M0011447.V10   *** */

/* .....FORTRAN SUBROUTINE  ....ERROR          8/68                    HG */
/* ...  FORTRAN SUBROUTINE               ERROR */

/*              FORTRAN SUBROUTINE ERROR */

/* PURPOSE      TO PRINT THE ERROR CODE OF A GEOMETRIC DIAGNOSTIC. */

/* LINKAGE      CALL ERROR (I,SUBNAM) */

/* ARGUMENTS    I       INTEGER ERROR CODE OF DIAGNOSTIC */

/* SUBSIDIARIES NONE */

/* Subroutine */ int error_(integer *iarg, char *subnam, ftnlen subnam_len)
{
    /* Initialized data */

    static integer ierrn = 20;
    static integer errlev[20] = { 2,3,8,9,30,40,45,49,50,71,84,92,94,5129,0,0,
	    0,0,0,0 };
    static char warn[8] = " WARNING";
    static char erro[8] = "  ERROR ";
    static integer kgerr[10] = { 0,0,1308622848,0,1308622848,1,1308622848,0,0,
	    0 };
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer ir, nr;
    extern integer bcdf_(char *, ftnlen);
    static integer larg, ierr;
    static char errr[8];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
    static integer kerrx;
#define cflags ((logical *)&super_1)
    extern /* Subroutine */ int record_(integer *), cprint_(char *, ftnlen), 
	    ewrite_(integer *, integer *, integer *, integer *, integer *);
#define lxtras ((logical *)&super_1 + 9)
    extern /* Subroutine */ int errout_(integer *);



/* ...            SYSTEM I/O FILE NAMES */


/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* ...                SYSTEM I/O FILES */





/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* ... INITILIZE ARRAY INDICATING WHICH ERRORS ARE OF SEVERITY LEVEL FOUR. */
    if (first) {
	kgerr[0] = bcdf_("GERR", (ftnlen)4);
	kgerr[1] = bcdf_("    ", (ftnlen)4);
	first = FALSE_;
    }

    larg = *iarg;
/* ... SET ERROR LEVEL INDICATOR FOR THE SUPERVISOR. */
    kerrx = 4;
    i__1 = ierrn;
    for (ierr = 1; ierr <= i__1; ++ierr) {
	if (larg == errlev[ierr - 1]) {
	    goto L8;
	}
/* L5: */
    }
    kerrx = 8;
L8:
    ++super_1.xtras[8 / kerrx - 1];
    kgerr[7] = larg;
    cprint_(darray_1.darray, (ftnlen)120);
    record_(&kgerr[3]);
    s_copy(errr, warn, (ftnlen)8, (ftnlen)8);
    if (kerrx > 4) {
	s_copy(errr, erro, (ftnlen)8, (ftnlen)8);
    }
    if (kerrx == 4 && super_1.errx < 4) {
	super_1.errx = 4;
    }
    if (kerrx == 8 && super_1.errx < 8) {
	super_1.errx = 8;
    }
    nr = 0;
    kgerr[8] = bcdf_(subnam, (ftnlen)4);
    kgerr[9] = bcdf_(subnam + 4, (ftnlen)4);
    cform_(" ***** DEFINITION ", darray_1.darray, &c__1, &c__18, (ftnlen)18, (
	    ftnlen)120);
    cform_(errr, darray_1.darray, &c__19, &c__8, (ftnlen)8, (ftnlen)120);
    iconv_(&larg, darray_1.darray, &c__27, &c__5, (ftnlen)120);
    cform_("ISN", darray_1.darray, &c__36, &c__3, (ftnlen)3, (ftnlen)120);
    iconv_(&kgerr[3], darray_1.darray, &c__39, &c__5, (ftnlen)120);
    cform_(" FROM SUBROUTINE ", darray_1.darray, &c__44, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(subnam, darray_1.darray, &c__61, &c__8, (ftnlen)8, (ftnlen)120);
    cform_("*****", darray_1.darray, &c__69, &c__5, (ftnlen)5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    errout_(&larg);
    kgerr[5] = 2;
    ewrite_(&symfil_1.exfile, &nr, kgerr, &c__10, &ir);
    return 0;
} /* error_ */

#undef lxtras
#undef cflags


