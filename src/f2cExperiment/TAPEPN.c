/* TAPEPN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : TAPEPN00.ORG   *** */

/* Subroutine */ int tapepn_(integer1 *char__, integer *n)
{
    /* System generated locals */
    integer i__1;
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), f_open(olist *), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    static logical od;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), abnend_(void), cprint_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 7, 0, "(80A1)", 0 };



/*  * TAPEPN *  VAX-11 FORTRAN 77 VERSION  26.10.82  E.MCLELLAN */

/*  PURPOSE     TO WRITE COLUMN BINARY DATA TO PAPER TAPE PUNCH FILE */

/*  CALLING SEQUENCE */
/*              CALL TAPEPN(CHAR,N) */
/*  ARGUMENTS */
/*              CHAR  BYTE ARRAY CONTAINING COLUMN BINARY CODES */
/*              N     NO OF COLUMNS (CHARACTERS) TO BE PUNCHED */


/* ...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA */
/* ...ON OTHER SYSTEMS */




/* .....WRITE IN A FORMAT TO FILE PUNTAP.DAT */

/* .....IS PUNTAP.DAT OPEN */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --char__;

    /* Function Body */
    ioin__1.inerr = 0;
    ioin__1.infilen = 10;
    ioin__1.infile = "PUNTAP.DAT";
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
	o__1.ofnmlen = 10;
	o__1.ofnm = "PUNTAP.DAT";
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

/* .....WRITE TO PUNTAP.DAT */

    s_wsfe(&io___2);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&char__[i__], (ftnlen)sizeof(integer1));
    }
    e_wsfe();
    return 0;

L90:
    cform_("**** ERROR OPENING PUNTAP.DAT ****", darray_1.darray, &c__2, &
	    c__34, (ftnlen)34, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    abnend_();
    return 0;
} /* tapepn_ */

