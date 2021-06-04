/* SPRINT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : SPRINT00.V02   *** */


/*  * SPRINT *  FORTRAN 77 SUBROUTINE  3.12.85  E.MCLELLAN */

/*  PURPOSE:  PRINT CHARACTER STRING ON (VLFILE) SYSTEM OUTPUT DEVICE */

/*  CALLING SEQUENCE: */
/*                   CALL SPRINT(BUFFER) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*      BUFFER       CHARACTER  CHARACTER STRING TO BE PRINTED */

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

/* Subroutine */ int sprint_(char *buffer, ftnlen buffer_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    cllist cl__1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), f_clos(cllist *), s_wsfi(icilist *), 
	    do_fio(integer *, char *, ftnlen), e_wsfi(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static char f1[3];
    static integer slen;
    static char form[6];

    /* Fortran I/O blocks */
    static icilist io___4 = { 0, f1, 0, "(I3)", 3, 1 };
    static cilist io___6 = { 0, 0, 0, form, 0 };






/* ...                SYSTEM I/O FILES */



    slen = i_len(buffer, buffer_len);
/* .....OMIT TRAILING BLANKS */
    for (i__ = slen; i__ >= 1; --i__) {
	if (*(unsigned char *)&buffer[i__ - 1] != ' ') {
	    slen = i__;
	    goto L20;
	}
/* L10: */
    }
    slen = 1;
L20:
    if (*(unsigned char *)buffer == 'C') {
	cl__1.cerr = 0;
	cl__1.cunit = symfil_1.vlfile;
	cl__1.csta = "KEEP";
	f_clos(&cl__1);
    } else {
	s_wsfi(&io___4);
	do_fio(&c__1, (char *)&slen, (ftnlen)sizeof(integer));
	e_wsfi();
/* Writing concatenation */
	i__1[0] = 2, a__1[0] = "(A";
	i__1[1] = 3, a__1[1] = f1;
	i__1[2] = 1, a__1[2] = ")";
	s_cat(form, a__1, i__1, &c__3, (ftnlen)6);
	io___6.ciunit = symfil_1.vlfile;
	s_wsfe(&io___6);
	do_fio(&c__1, buffer, buffer_len);
	e_wsfe();
    }

    s_copy(buffer, " ", buffer_len, (ftnlen)1);

    return 0;
} /* sprint_ */

