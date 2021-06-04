/* CONCAT.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : CONCAT00.ORG   *** */

/* Subroutine */ int concat_(char *chr, char *bcd, ftnlen chr_len, ftnlen 
	bcd_len)
{
    /* System generated locals */
    icilist ici__1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    , s_wsfi(icilist *), e_wsfi(void);

    /* Local variables */
    static integer k, nchr;


/* .....INSERT A SINGLE CHARACTER, BCD, INTO NEXT AVAILABLE POSITION */
/* .....IN STRING OF CHARACTERS, CHR */

/* .....THE NUMBER OF CHARACTERS IN THE STRING IS HELD IN THE FIRST 3 CHAR */
/* .....LOCATIONS OF CHR */


    ici__1.icierr = 0;
    ici__1.iciend = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = chr_len;
    ici__1.iciunit = chr;
    ici__1.icifmt = "(I3)";
    s_rsfi(&ici__1);
    do_fio(&c__1, (char *)&nchr, (ftnlen)sizeof(integer));
    e_rsfi();
    ++nchr;
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 3;
    ici__1.iciunit = chr;
    ici__1.icifmt = "(I3)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&nchr, (ftnlen)sizeof(integer));
    e_wsfi();
    k = nchr + 3;
    *(unsigned char *)&chr[k - 1] = *(unsigned char *)bcd;

    return 0;
} /* concat_ */

