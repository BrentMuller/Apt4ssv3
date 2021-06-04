/* AERR.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer iaerfg, npctpt;
    doublereal pctpts[60]	/* was [3][20] */, pctpln[4], errpts[9]	/* 
	    was [3][3] */;
} aercom_;

#define aercom_1 aercom_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

/* Table of constant values */

static integer c__10 = 10;
static integer c__1 = 1;
static integer c__26 = 26;
static integer c__27 = 27;
static integer c__5 = 5;
static integer c__36 = 36;
static integer c__3 = 3;
static integer c__39 = 39;
static integer c__44 = 44;
static integer c__17 = 17;
static integer c__61 = 61;
static integer c__8 = 8;
static integer c__69 = 69;

/* *** SOURCE FILE : M0011439.W02   *** */



/* Subroutine */ int aerr_(integer *number, char *sbnam, ftnlen sbnam_len)
{
    /* Initialized data */

    static integer kerr[10] = { 0,0,1308622848,1,1308622848,1,1308622848,1,0,
	    0 };
    static logical first = TRUE_;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer ir, nr, isn[2], num;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int aerr2_(integer *, char *, ftnlen), atape_(
	    void), cform_(char *, char *, integer *, integer *, ftnlen, 
	    ftnlen), iconv_(integer *, char *, integer *, integer *, ftnlen);
#define cflags ((logical *)&super_1)
    extern /* Subroutine */ int record_(integer *);
    static char subnam[8];
    extern /* Subroutine */ int ewrite_(integer *, integer *, integer *, 
	    integer *, integer *), cprint_(char *, ftnlen);
#define lxtras ((logical *)&super_1 + 9)
    extern /* Subroutine */ int errout_(integer *);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* ...  20. SYSTEM I/O FILE NAMES */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*     25. COMMON FOR AERR INFORMATION */


/* ...                SYSTEM I/O FILES */





/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */






/*     ------------------------------------------------------------ */

    if (first) {
	kerr[0] = bcdf_("AERR", (ftnlen)4);
	kerr[1] = bcdf_("    ", (ftnlen)4);
	first = FALSE_;
    }

    s_copy(subnam, sbnam, (ftnlen)8, sbnam_len);
    if (*number < 0) {
	goto L10;
    }
    aerr2_(number, subnam, (ftnlen)8);
    goto L20;

/*        WARNING DIAGNOSTIC - NO VARIABLE INFORMATION OUTPUT */

L10:
    ++super_1.xtras[1];
    ifxcor_1.iaerr = 1;
    atape_();
    nr = 0;
    kerr[3] = 1;
    kerr[5] = 2;
    kerr[7] = *number;
    kerr[8] = bcdf_(subnam, (ftnlen)4);
    kerr[9] = bcdf_(subnam + 4, (ftnlen)4);
    ewrite_(&symfil_1.exfile, &nr, kerr, &c__10, &ir);
    if (super_1.errx < 4) {
	super_1.errx = 4;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    num = abs(*number);
    ifxcor_1.iaerr = 0;
    aercom_1.iaerfg = 0;
    record_(isn);
    cform_(" ***** WARNING DIAGNOSTIC ", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&num, darray_1.darray, &c__27, &c__5, (ftnlen)120);
    cform_("ISN", darray_1.darray, &c__36, &c__3, (ftnlen)3, (ftnlen)120);
    iconv_(isn, darray_1.darray, &c__39, &c__5, (ftnlen)120);
    cform_(" FROM SUBROUTINE ", darray_1.darray, &c__44, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(subnam, darray_1.darray, &c__61, &c__8, (ftnlen)8, (ftnlen)120);
    cform_("*****", darray_1.darray, &c__69, &c__5, (ftnlen)5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    errout_(number);
L20:
    return 0;
} /* aerr_ */

#undef lxtras
#undef cflags


