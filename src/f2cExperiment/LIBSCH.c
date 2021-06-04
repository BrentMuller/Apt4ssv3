/* LIBSCH.f -- translated by f2c (version 20100827).
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
    char filnam[480], filacc[300], filfmt[330], opstat[210], clstat[180];
} filtab_;

#define filtab_1 filtab_

struct {
    integer u[30], rl[30], nxtrec[30], lstrec[30];
} ifiltb_;

#define ifiltb_1 ifiltb_

struct {
    integer ieof;
} libcom_;

#define libcom_1 libcom_

struct {
    char aptlib[11], filenm[40], memnam[8];
} libfil_;

#define libfil_1 libfil_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;

/* *** SOURCE FILE : LIBSCH00.V01   *** */

/* Subroutine */ int libsch_(char *member, integer *flag__, ftnlen member_len)
{
    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1[2], i__2[3], i__3;
    char ch__1[16];
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_inqu(inlist *), i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *);

    /* Local variables */
    static integer j, id;
    static logical ex;


/*  * LIBSCH *  VAX-11 FORTRAN 77 VERSION  27.09.82  E.MCLELLAN */
/*                               MODIFIED  30.10.86  E.MCLELLAN */

/*  PURPOSE     TO SEARCH APTLIB FOR A GIVEN */
/*              MEMBER FILE AND TO OPEN SAID FILE */
/*  CALLING SEQUENCE */
/*              CALL LIBSCH(MEMBER,FLAG) */
/*  ARGUMENTS */
/*              MEMBER    CHARACTER STRING CONTAINING THE */
/*                        MEMBER NAME (BCD LEFT JUSTIFIED) */
/*              FLAG      0 = MEMBER FOUND */
/*                        1 = MEMBER NOT FOUND IN APTLIB */
/*                        2 = ERROR OPENING FILE */
/*                        3 = APTLIB DOES NOT EXIST */
/*                        4 = LIBSCH IS CALLED BEFORE COMPLETING THE */
/*                            PROCESSING OF PREVIOUS MEMBER */




/*  *  FILE ATTRIBUTES  * */












/* ..... DOES APTLIB EXIST */
    id = ifiltb_1.u[23];
    ioin__1.inerr = 0;
    ioin__1.infilen = 16;
/* Writing concatenation */
    i__1[0] = 11, a__1[0] = libfil_1.aptlib;
    i__1[1] = 5, a__1[1] = "INDEX";
    s_cat(ch__1, a__1, i__1, &c__2, (ftnlen)16);
    ioin__1.infile = ch__1;
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

/* .....YES - HAS PROCESSING OF PREVIOUS MEMBER BEEN COMPLETED */
	if (libcom_1.ieof == 0) {
/* .....NO */
	    *flag__ = 4;
	    return 0;
/* .....YES - SET UP FILE NAME FOR MEMBER */
	} else {
	    j = i_indx(member, " ", member_len, (ftnlen)1);
	    if (j == 0) {
/* Writing concatenation */
		i__2[0] = 11, a__2[0] = libfil_1.aptlib;
		i__2[1] = member_len, a__2[1] = member;
		i__2[2] = 4, a__2[2] = ".TXT";
		s_cat(libfil_1.filenm, a__2, i__2, &c__3, (ftnlen)40);
	    } else {
/* Writing concatenation */
		i__2[0] = 11, a__2[0] = libfil_1.aptlib;
		i__2[1] = j - 1, a__2[1] = member;
		i__2[2] = 4, a__2[2] = ".TXT";
		s_cat(libfil_1.filenm, a__2, i__2, &c__3, (ftnlen)40);
	    }

/* .....STORE MEMBER NAME AND RESET EOF FLAG */
	    s_copy(libfil_1.memnam, member, (ftnlen)8, member_len);
	    libcom_1.ieof = 0;
/* .....DOES FILE EXIST */
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
/* .....YES */
		o__1.oerr = 1;
		o__1.ounit = id;
		o__1.ofnmlen = 40;
		o__1.ofnm = libfil_1.filenm;
		o__1.orl = 0;
		o__1.osta = "OLD";
		o__1.oacc = filtab_1.filacc + 230;
		o__1.ofm = filtab_1.filfmt + 253;
		o__1.oblnk = 0;
		i__3 = f_open(&o__1);
		if (i__3 != 0) {
		    goto L90;
		}
		*flag__ = 0;
		return 0;
L90:
		*flag__ = 2;
		return 0;
	    } else {
/* .....NO */
		*flag__ = 1;
		return 0;
	    }

	}

    } else {
/* .....APTLIB DOES NOT EXIST */
	*flag__ = 3;
    }
    return 0;
} /* libsch_ */

