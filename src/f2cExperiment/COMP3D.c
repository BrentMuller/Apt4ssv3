/* COMP3D.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    logical lgchk, lintck, lavctl, lvaxis;
} rmflgs_;

#define rmflgs_1 rmflgs_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0000712.W02   *** */

/* .....FORTRAN SUBROUTINE             COMP3D...              3/1/68   GK */
/* Subroutine */ int comp3d_(void)
{
    /* Initialized data */

    static char pp1[8] = "3DCALC  ";

    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    static integer ppword[2];




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    ifxcor_1.i3dflg = 1;
    ppword[0] = bcdf_(pp1, (ftnlen)4);
    ppword[1] = bcdf_(pp1 + 4, (ftnlen)4);

    apt299_(&c__0, ppword, &c__0, &c__0);
    return 0;
} /* comp3d_ */




/* Subroutine */ int ndtest_(void)
{
    /* Initialized data */

    static char pp2[8] = "2DCALC  ";

    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    static integer ppword[2];




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    ifxcor_1.i3dflg = 0;
    ppword[0] = bcdf_(pp2, (ftnlen)4);
    ppword[1] = bcdf_(pp2 + 4, (ftnlen)4);

    apt299_(&c__0, ppword, &c__0, &c__0);
    return 0;
} /* ndtest_ */




/* Subroutine */ int gougck_(doublereal *donoff)
{
    /* Initialized data */

    static char pp3[8] = "GOUGCK  ";
    static char don[2] = "ON";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer nwd;
    extern integer bcdf_(char *, ftnlen);
    static char test[2];
    extern /* Subroutine */ int apt299_(), holfrm_(doublereal *, char *, 
	    integer *, integer *, integer *, ftnlen);
    static integer ppword[2];




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */


    holfrm_(donoff, test, &c__1, &c__2, &nwd, (ftnlen)2);
    if (s_cmp(test, don, (ftnlen)2, (ftnlen)2) == 0) {
	ifxcor_1.igoug = 1;
	rmflgs_1.lgchk = TRUE_;
    } else {
	ifxcor_1.igoug = 0;
	rmflgs_1.lgchk = FALSE_;
    }
    ppword[0] = bcdf_(pp3, (ftnlen)4);
    ppword[1] = bcdf_(pp3 + 4, (ftnlen)4);

    apt299_(&c__1, ppword, &c__2, donoff);
    return 0;
} /* gougck_ */

