/* CREAD.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : CREAD000.ORG   *** */


/*  *  CREAD  *   FORTRAN 77 VERSION   4-DEC-85   E.MCLELLAN */

/*  PURPOSE     TO READ A RECORD FROM SYSTEM INPUT DEVICE */

/*  CALLING SEQUENCE */
/*              CALL CREAD(REC,FLAG) */
/*  ARGUMENTS */
/*              REC     CHARACTER STRING TO CONTAIN INPUT RECORD */
/*              FLAG    =0  NORMAL RETURN */
/*                      =1 END OF FILE DETECTED */

/* Subroutine */ int cread_(char *rec, integer *flag__, ftnlen rec_len)
{
    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);

    /* Fortran I/O blocks */
    static cilist io___1 = { 1, 0, 1, "(A80)", 0 };





/* ...                SYSTEM I/O FILES */




    io___1.ciunit = symfil_1.infile__;
    *flag__ = s_rsfe(&io___1);
    if (*flag__ != 0) {
	goto L100001;
    }
    *flag__ = do_fio(&c__1, rec, (ftnlen)80);
    if (*flag__ != 0) {
	goto L100001;
    }
    *flag__ = e_rsfe();
L100001:
    *flag__ = abs(*flag__);
    return 0;
} /* cread_ */

