/* PUTTMP.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__24 = 24;

/* *** SOURCE FILE : M0006670.V03   *** */


/*              FORTRAN SUBROUTINE PUTTMP */

/* LINKAGE      SUBROUTINE PUTTMP(MODE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    BINBCD          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    FOUTXX          SUBROUTINE    INPAT */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */

/* Subroutine */ int puttmp_(integer *mode)
{
    /* Initialized data */

    static char inam[24] = " PUTTMP ERROR           ";

    static integer i__;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen),
	     foutxx_(integer *, char *, integer *, ftnlen);



/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* ELFIL1:      OUTPUT OF PACKING FACTOR FOR CREATING PAGES (INTERPRETER) */
/* * */
/* ARGUMENT     MODE      MODE OF TEMPORARY STORAGE NAME TO BE RELEASED */


/* ...                SYSTEM I/O FILES */



/* ** */
    if (tmp_1.txxxx[(0 + (0 + (2 + (*mode << 1) - 3 << 2))) / 4] == 0) {
	goto L999;
    }
    --tmp_1.txxxx[(*mode << 1) - 1];
    return 0;

/*     ERROR */
L999:
    binbcd_(mode, inam + 16, &i__, (ftnlen)8);
    foutxx_(&symfil_1.elfil1, inam, &c__24, (ftnlen)24);
    return 0;
} /* puttmp_ */

