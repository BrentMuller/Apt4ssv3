/* ACNTRL.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c_n4 = -4;
static integer c__1 = 1;
static integer c__48 = 48;
static integer c_n3 = -3;
static integer c__6 = 6;
static integer c__3 = 3;

/* *** SOURCE FILE : M0000398.W01   *** */


/* ...  FORTRAN SUBROUTINE           ACNTRL...         RC,AR */
/*     MODIFIED FOR SSV3  E.MCLELLAN */

/* Subroutine */ int acntrl_(doublereal *array, doublereal *filea)
{
    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    char ch__1[32];
    static doublereal equiv_4[24];

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__;
#define n ((integer *)equiv_4 + 2)
    static integer ir;
#define nnn ((integer *)equiv_4)
    static integer nwd;
#define nop ((integer *)equiv_4 + 5)
#define pps (equiv_4 + 4)
    extern /* Subroutine */ int aread_(integer *, integer *, integer *, 
	    integer *, integer *), tapop_(integer *, integer *);
#define cflags ((logical *)&super_1)
    static char ppname[6];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
#define lxtras ((logical *)&super_1 + 9)
    extern /* Subroutine */ int outmsg_(char *, ftnlen);
    static integer numpst;


/* ...  THIS SUBROUTINE RECEIVES CONTROL FOR THE POSTEXEC LOAD MODULE. */
/*     IT READS CPFILE AND AND LISTS THE NAMES OF THE NECESSARY */
/*     POSTPROCESSORS. */
/*     CLFILE(S) ARE ALSO SAVED FOR FUTURE POST PROCESSING */


/* ...                SYSTEM I/O FILES */




/*     ****         ****      ****      ****      ****      **** */


/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */




/*     adding this line because the tape has data, but is at the end */
/*     of the file */
    tapop_(&symfil_1.cpfile, &c_n4);
    aread_(&symfil_1.cpfile, &c__1, nnn, &c__48, &ir);

/* ... IS POST PROCESSING REQUIRED */

    if (*n != 0) {

/* ...CLOSE CLFILES AND KEEP */

	tapop_(&symfil_1.clfilp, &c_n3);
	if (*nop == 1) {
	    tapop_(&symfil_1.clfile, &c_n3);
	}
	tapop_(&symfil_1.clfil3, &c_n3);

/* ....WRITE CURRENT POST PROCESSOR NAMES TO FILE - PPFILE.DAT */

	numpst = *n / 2;

	i__1 = numpst;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    holfrm_(&pps[(i__ << 1) - 2], ppname, &c__1, &c__6, &nwd, (ftnlen)
		    6);
/* Writing concatenation */
	    i__2[0] = 16, a__1[0] = " POST PROCESSOR ";
	    i__2[1] = 6, a__1[1] = ppname;
	    i__2[2] = 10, a__1[2] = " REQUESTED";
	    s_cat(ch__1, a__1, i__2, &c__3, (ftnlen)32);
	    outmsg_(ch__1, (ftnlen)32);
/* L50: */
	}

    }

    super_1.abend = FALSE_;

    return 0;
} /* acntrl_ */

#undef lxtras
#undef cflags
#undef pps
#undef nop
#undef nnn
#undef n


