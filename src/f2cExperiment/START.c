/* START.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer bgeom[4];
} bgeom_;

#define bgeom_1 bgeom_

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__12 = 12;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0006688.V09   *** */


/*              FORTRAN SUBROUTINE START */

/* LINKAGE      SUBROUTINE  START */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           MAIN */
/*          SUBROUTINE    FOUTXX */
/*          SUBROUTINE    RECOG */
/*          SUBROUTINE    TAPOP */

/* Subroutine */ int start_(void)
{
    /* Initialized data */

    static char b[12] = "0       ISN ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
#define nmod ((integer *)&ntbl_1)
#define nndx ((integer *)&ntbl_1 + 2)
    extern /* Subroutine */ int recog_(void), tapop_(integer *, integer *);
#define cflags ((logical *)&super_1)
#define ifbnds ((integer *)&bgeom_1)
#define ifdump ((integer *)&bgeom_1 + 1)
#define lxtras ((logical *)&super_1 + 9)
    extern /* Subroutine */ int foutxx_(integer *, char *, integer *, ftnlen);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NUMBST:      NAMTBL INDEX OF BEGINNING OF NUMBER SECTION */
/* NUMBND:      NAMTBL INDEX OF END OF NUMBER SECTION */

/*       33.    SYMBOLIC FILE DEFINITIONS */







/* VLFILE:      VERIFICATION LISTING FILE */

/*       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE */


/* ...                SYSTEM I/O FILES */



/* IFBNDS:      VALUE 1 IF BOUNDED GEOMETRY IS INCLUDED IN PART PROGRAM */
/* IFDUMP:      VALUE 0=NO CFSAVE COMMAND,1=ALL,2=SCALAR,3=GEOM PROGRAM */

/*       40.    PARAMETERS REQUIRED BY SUPERVISOR */


/*       41.    NUMBER TABLE OVERFLOW VARIABLES */





/* NMOD:        NUMBER OF ENTRIES PERMITTED IN INTERNAL NUMBER TABLE */
/* NNDX:        CONVERSION BETWEEN ABS. AND VIRTUAL NUMBER TABLE POINTER */
/* * */
/* ** */

    i__1 = nametb_1.numbnd;
    for (i__ = nametb_1.numbst; i__ <= i__1; ++i__) {
/* L10: */
	s_copy(cnamtb_1.cnumtb + (i__ - 1) * 12, " ", (ftnlen)12, (ftnlen)1);
    }
    *nmod = nametb_1.numbnd - nametb_1.numbst + 1;
    *nndx = 0;
    *ifdump = 0;
    *ifbnds = 0;
/* ...     PUT APPROPRIATE HEADINGS ON VLFILE AND DIAGNOSTIC FILE */
    foutxx_(&symfil_1.vlfile, b, &c__12, (ftnlen)12);

    tapop_(&symfil_1.elfil1, &c_n1);
    tapop_(&symfil_1.elfil2, &c_n1);
    recog_();

/* ....    INDICATE NORMAL ENDING */
    super_1.abend = FALSE_;

    return 0;
} /* start_ */

#undef lxtras
#undef ifdump
#undef ifbnds
#undef cflags
#undef nndx
#undef nmod


