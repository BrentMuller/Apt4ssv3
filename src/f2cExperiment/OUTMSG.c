/* OUTMSG.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

/* *** SOURCE FILE : OUTMSG.ORG   *** */


/*  * OUTMSG *  FORTRAN 77 SUBROUTINE  1.12.88  E.MCLELLAN */

/*  PURPOSE:  TO PRINT MESSAGE ON THE VLFILE */

/*  CALLING SEQUENCE: */
/*                   CALL OUTMSG(STR) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*      STR          CHARACTER  CHARACTER STRING TO BE PRINTED */
/*                              MAY BE LITERAL OR A STRING VARIABLE */
/*  GLOBAL VARIABLES: */
/*           BLOCK   TYPE       DESCRIPTION */
/*   VLFILE  SYMFIL  INTEGER    UNIT NUMBER FOR SYSTEM OUTPUT DEVICE */

/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*        SLEN       INTEGER    LENGTH OF STRING TO BE PRINTED */
/*        F1         CHARACTER  INTERNAL FILE FOR INTEGER TO CHARACTER */
/*                              CONVERSION */
/*        FORM       CHARACTER  OUTPUT FORMAT */

/*  FILES: */
/*        VLFILE     SYSTEM OUTPUT DEVICE */

/*  SUBSIDIARIES:  NONE */

/* Subroutine */ int outmsg_(char *str, ftnlen str_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *
	    , ftnlen), e_wsfi(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static char f1[3];
    static integer slen;
    static char form[9];

    /* Fortran I/O blocks */
    static icilist io___3 = { 0, f1, 0, "(I3)", 3, 1 };
    static cilist io___5 = { 0, 0, 0, form, 0 };






/* ...                SYSTEM I/O FILES */



    slen = i_len(str, str_len);

/* .... SET UP FORMAT AND PRINT */

    s_wsfi(&io___3);
    do_fio(&c__1, (char *)&slen, (ftnlen)sizeof(integer));
    e_wsfi();
/* Writing concatenation */
    i__1[0] = 5, a__1[0] = "(1X,A";
    i__1[1] = 3, a__1[1] = f1;
    i__1[2] = 1, a__1[2] = ")";
    s_cat(form, a__1, i__1, &c__3, (ftnlen)9);
    io___5.ciunit = symfil_1.vlfile;
    s_wsfe(&io___5);
    do_fio(&c__1, str, str_len);
    e_wsfe();

    return 0;
} /* outmsg_ */

