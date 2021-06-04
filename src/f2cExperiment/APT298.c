/* APT298.f -- translated by f2c (version 20100827).
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
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7], irdsav[20];
} super_;

#define super_1 super_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c_n1 = -1;
static integer c__48 = 48;
static integer c_n2 = -2;

/* *** SOURCE FILE : M0004117.V11   *** */


/* ...  FORTRAN SUBROUTINE                    APT298 */
/* Subroutine */ int apt298_(integer *code, doublereal *pproc1, doublereal *
	pproc2)
{
    /* Initialized data */

    static integer libtop = 10;
    static integer ppflag = 0;
    static char pplibr[8*10] = "APT4PP  " "CLCMP4  " "        " "        " 
	    "        " "        " "        " "        " "        " "        ";
    static struct {
	integer fill_1[1];
	integer e_2[5];
	doublereal fill_3[1];
	doublereal e_4[2];
	doublereal fill_5[18];
	} equiv_7 = { {0}, 1, 0, 0, 0, 0, {0}, 0., 0. };


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, ir, nr;
#define one ((integer *)&equiv_7 + 1)
    static integer nwd;
#define pps ((doublereal *)&equiv_7 + 4)
    extern integer bcdf_(char *, ftnlen);
#define a4ary ((doublereal *)&equiv_7)
    static char proc1[8];
#define i4ary ((integer *)&equiv_7)
#define ppflg ((integer *)&equiv_7 + 5)
    extern /* Subroutine */ int tapop_(integer *, integer *);
#define nopps ((integer *)&equiv_7 + 2)
    static doublereal ppname;
#define mltflg ((integer *)&equiv_7 + 6)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), awrite_(integer *, integer *, 
	    integer *, integer *, integer *);
#define cnvert ((integer *)&equiv_7 + 4)
#define clprnt ((integer *)&equiv_7 + 3)



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* ... LOCAL VARIABLES */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */







/*          SYMFIL I/O FILES NAME */


/* ...                SYSTEM I/O FILES */






/* ...     APT4 POSTPROCESSOR LIBRARY */

/* ******************************************************************** */

    switch (*code) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L100;
    }
L10:
    *clprnt = 1;
    return 0;
L20:
    ppflag = 1;
    super_1.px = TRUE_;
    *cnvert = 0;
    *ppflg = 0;
    *nopps = 0;
    return 0;
L30:
    ppname = *pproc1;
    holfrm_(&ppname, proc1, &c__1, &c__8, &nwd, (ftnlen)8);

/* ...     CHECK FOR APT4 POSTPROCESSOR */
/* L38: */
    i__1 = libtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s_cmp(pplibr + (i__ - 1 << 3), proc1, (ftnlen)8, (ftnlen)8) == 0) 
		{
	    goto L70;
	}
/* L40: */
    }

    if (ppflag == 0) {
	*cnvert = 1;
    }
    goto L90;

L70:
    if (ppflag == 0) {
	*ppflg = 1;
    }

/*     STORE POSTPROCESSOR NAME */

L90:
    ++(*nopps);
    pps[(*nopps << 1) - 2] = ppname;
    pps[(*nopps << 1) - 1] = *pproc2;
    return 0;

L100:
    *mltflg = ifxcor_1.mulout;
    tapop_(&symfil_1.cpfile, &c_n1);
/* L110: */
    nr = 0;
    *nopps <<= 1;
    i4ary[0] = bcdf_("CPFL", (ftnlen)4);
    awrite_(&symfil_1.cpfile, &nr, i4ary, &c__48, &ir);

    tapop_(&symfil_1.cpfile, &c_n2);

    return 0;
} /* apt298_ */

#undef clprnt
#undef cnvert
#undef mltflg
#undef nopps
#undef ppflg
#undef i4ary
#undef a4ary
#undef pps
#undef one


