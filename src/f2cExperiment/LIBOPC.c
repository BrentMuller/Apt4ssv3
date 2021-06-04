/* LIBOPC.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : LIBOPC00.W01   *** */

/* Subroutine */ int libopc_(integer *ind, integer *flag__)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    char ch__1[16];
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_inqu(inlist *), f_clos(cllist *);

    /* Local variables */
    static integer id;
    static logical od, ex;


/*  * LIBOPC *  VAX-11 FORTRAN VERSION  27.09.82  E.MCLELLAN */
/*              PORTABLE F77 VERSION REVISED  8-OCT-1987 E.MCLELLAN */

/*  PURPOSE     TO CHECK THE EXISTENCE OF APTLIB */
/*              OR CLOSE UNIT REFERENCING APTLIB */
/*  CALLING SEQUENCE */
/*              CALL LIBOPC(IND,FLAG) */
/*  ARGUMENTS */
/*              IND   =1 DOES APTLIB EXIST */
/*                    =2 CLOSE UNIT WHICH REFERENCES APTLIB */
/*              FLAG  =0 APTLIB EXISTS */
/*                    =1 APTLIB DOES NOT EXIST */
/*                    =2 NOT USED */
/*                    =3 ALREADY CLOSED (IND=2) */
/*                    =4 IND IS NOT 1 OR 2 */




/*  *  FILE ATTRIBUTES  * */







/* .....UNIT NUMBER FOR APTLIB */




    id = ifiltb_1.u[23];

    if (*ind == 1) {

/* .....DOES APTLIB EXIST */

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

/* .....APTLIB EXISTS */
	    *flag__ = 0;
	    return 0;
	} else {

/* .....APTLIB DOES NOT EXIST */
	    *flag__ = 1;
	    return 0;
	}

    } else if (*ind == 2) {

/* .....IS UNIT OPEN */
	ioin__1.inerr = 0;
	ioin__1.inunit = id;
	ioin__1.infile = 0;
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
	if (od) {

/* .....CLOSE UNIT */
	    cl__1.cerr = 0;
	    cl__1.cunit = id;
	    cl__1.csta = filtab_1.clstat + 138;
	    f_clos(&cl__1);
	    return 0;

	} else {
/* .....UNIT ALREADY CLOSED */
	    *flag__ = 3;
	    return 0;
	}

    } else {

/* .....IND NOT 1 OR 2 */
	*flag__ = 4;
    }
    return 0;
} /* libopc_ */

