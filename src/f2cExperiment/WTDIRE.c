/* WTDIRE.f -- translated by f2c (version 20100827).
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
    integer ieof;
} libcom_;

#define libcom_1 libcom_

struct {
    char aptlib[11], filenm[40], memnam[8];
} libfil_;

#define libfil_1 libfil_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__3 = 3;

/* *** SOURCE FILE : WTDIRE00.V01   *** */

/* Subroutine */ int wtdire_(integer *iu, doublereal *member, doublereal *
	userd, integer *nch, integer *iret)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3], i__2;
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_inqu(inlist *), f_open(olist *);

    /* Local variables */
    static integer j, id;
    static logical ex;
    static integer nwd;
    static char cmem[8];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);








    id = *iu;

/* .... SET UP FILENAME */

    holfrm_(member, cmem, &c__1, &c__8, &nwd, (ftnlen)8);
    j = i_indx(cmem, " ", (ftnlen)8, (ftnlen)1);

    if (j == 0) {
/* Writing concatenation */
	i__1[0] = 11, a__1[0] = libfil_1.aptlib;
	i__1[1] = 8, a__1[1] = cmem;
	i__1[2] = 4, a__1[2] = ".LDA";
	s_cat(libfil_1.filenm, a__1, i__1, &c__3, (ftnlen)40);
    } else {
/* Writing concatenation */
	i__1[0] = 11, a__1[0] = libfil_1.aptlib;
	i__1[1] = j - 1, a__1[1] = cmem;
	i__1[2] = 4, a__1[2] = ".LDA";
	s_cat(libfil_1.filenm, a__1, i__1, &c__3, (ftnlen)40);
    }

/* .... INQUIRE IF FILE EXISTS */

    ioin__1.inerr = 0;
    ioin__1.infilen = 40;
    ioin__1.infile = libfil_1.filenm;
    ioin__1.inex = &ex;
    ioin__1.inopen = 0;
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
    if (ex) {
/* .... FILE ALREADY EXISTS - SHOULD A NEW VERSION BE WRITTEN */
	if (id < 0) {
/* .... YES - OPEN ATTACHED TO UNIT ID */
	    id = abs(id);
	    o__1.oerr = 1;
	    o__1.ounit = id;
	    o__1.ofnmlen = 40;
	    o__1.ofnm = libfil_1.filenm;
	    o__1.orl = 0;
	    o__1.osta = "NEW";
	    o__1.oacc = "SEQUENTIAL";
	    o__1.ofm = "UNFORMATTED";
	    o__1.oblnk = 0;
	    i__2 = f_open(&o__1);
	    if (i__2 != 0) {
		goto L20;
	    }
	    *iret = 0;
	} else {
	    *iret = 9;
	}
    } else {
/* .... FILE DOES NOT EXIST - OPEN ATTACHED TO UNIT ID */
	o__1.oerr = 1;
	o__1.ounit = id;
	o__1.ofnmlen = 40;
	o__1.ofnm = libfil_1.filenm;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = "SEQUENTIAL";
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	i__2 = f_open(&o__1);
	if (i__2 != 0) {
	    goto L20;
	}
	*iret = 0;
    }
    return 0;
/* .... ERROR OPENING FILE */
L20:
    *iret = 5;
    return 0;
} /* wtdire_ */

