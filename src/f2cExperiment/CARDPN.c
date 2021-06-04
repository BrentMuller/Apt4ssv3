/* CARDPN.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__34 = 34;

/* *** SOURCE FILE : CARDPN00.V01   *** */

/* Subroutine */ int cardpn_(real *a, integer *n, integer *m, integer *i__, 
	real *d__)
{
    /* System generated locals */
    integer i__1;
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), f_open(olist *), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static logical od;
    static integer iseq;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), abnend_(void), cprint_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 7, 0, "(18A4)", 0 };
    static cilist io___4 = { 0, 7, 0, "(19A4,I4)", 0 };



/*  * CARDPN *   VAX-11 FORTRAN 77 VERSION   15.10.82  E.MCLELLAN */

/*  PURPOSE      WRITE AN ASCII FILE , PNCHFL */

/*  CALLING SEQUENCE */
/*               CALL CARDPN(A,N,M,I,D) */
/*  ARGUMENTS */
/*              A   LOCATION OF FIRST WORD TO BE PUNCHED */
/*              N   NO OF 4 BYTE WORDS TO BE PUNCHED,NORMALLY 18, */
/*                  IF GREATER NO, ID AND SEQUENCE NO WILL BE PUNCHED */
/*              M   MODE IGNORED BY THIS VERSION OF ROUTINE */
/*             I   4 BYTE SEQUENCE NO TO BE PUNCHED IN COL 77-80 */
/*                 TREATED AS MODULO 10,000 */
/*             D   LOCATION OF A 4 BYTE IDENTIFICATION WORD TO BE */
/*                 PUNCHED IN COLUMNS 73-76 (ALPHA ONLY) */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --a;

    /* Function Body */
    ioin__1.inerr = 0;
    ioin__1.infilen = 7;
    ioin__1.infile = "PNCHFL.";
    ioin__1.inex = 0;
    ioin__1.inopen = &od;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (! od) {
	o__1.oerr = 1;
	o__1.ounit = 7;
	o__1.ofnmlen = 6;
	o__1.ofnm = "PNCHFL";
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = "SEQUENTIAL";
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L90;
	}
    }

    if (*n <= 18) {
	s_wsfe(&io___2);
	i__1 = *n;
	for (*i__ = 1; *i__ <= i__1; ++(*i__)) {
	    do_fio(&c__1, (char *)&a[*i__], (ftnlen)sizeof(real));
	}
	e_wsfe();
    } else {
	iseq = *i__ % 10000;
	s_wsfe(&io___4);
	for (*i__ = 1; *i__ <= 18; ++(*i__)) {
	    do_fio(&c__1, (char *)&a[*i__], (ftnlen)sizeof(real));
	}
	do_fio(&c__1, (char *)&(*d__), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&iseq, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    return 0;

L90:
    cform_("**** ERROR OPENING PNCHFL.DAT ****", darray_1.darray, &c__2, &
	    c__34, (ftnlen)34, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    abnend_();
    return 0;
} /* cardpn_ */

