/* CPUNCH.f -- translated by f2c (version 20100827).
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

struct {
    char filnam[480], filacc[300], filfmt[330], opstat[210], clstat[180];
} filtab_;

#define filtab_1 filtab_

struct {
    integer u[30], rl[30], nxtrec[30], lstrec[30];
} ifiltb_;

#define ifiltb_1 ifiltb_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : CPUNCH00.V01   *** */

/* Subroutine */ int cpunch_(char *array, integer *flagg, ftnlen array_len)
{
    /* System generated locals */
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer id;
    static logical od;
    extern /* Subroutine */ int filopn_(integer *);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 0, 0, "(A80)", 0 };



/*  *  CPUNCH  *   VAX11 FORTRAN VERSION  13.5.82  E.MCLELLAN */

/*  PURPOSE     TO FORMAT A RECORD FOR PUNCHING ON PNCHFL */
/*  CALLING SEQUENCE */
/*              CALL CPUNCH(ARRAY,FLAGG) */
/*  ARGUMENTS */
/*              ARRAY   80 BYTE ARRAY CONTAINING THE */
/*                      BCD CHARACTERS TO BE PUNCHED */
/*              FLAGG   .EQ.0 BLANK FILL ARRAY AFTER PUNCHING */
/*                      .NE.0 OMIT BLANKING */


/* ...                 SYSTEM I/O FILES */


/* ...     FILE ATTRIBUTES */


/* ...                SYSTEM I/O FILES */





/*  *  FILE ATTRIBUTES  * */







/* .... UNIT NO FOR PNCHFL */

    id = ifiltb_1.u[symfil_1.pnchfl - 1];

/* ---- IS PNCHFL OPEN, IF NOT, OPEN PNCHFL */
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

    if (! od) {
	filopn_(&symfil_1.pnchfl);
    }

    io___3.ciunit = id;
    s_wsfe(&io___3);
    do_fio(&c__1, array, (ftnlen)80);
    e_wsfe();
    if (*flagg == 0) {
/* ---- BLANK FILL ARRAY */
	s_copy(array, " ", (ftnlen)80, (ftnlen)1);
    }
    return 0;
} /* cpunch_ */


/* ---- CLOSE PNCHFL, IF OPEN */

/* Subroutine */ int cpuclo_(void)
{
    /* System generated locals */
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), f_clos(cllist *);

    /* Local variables */
    static integer id;
    static logical od;




/* ...                SYSTEM I/O FILES */





/*  *  FILE ATTRIBUTES  * */







    id = ifiltb_1.u[symfil_1.pnchfl - 1];
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
	cl__1.cerr = 0;
	cl__1.cunit = id;
	cl__1.csta = "KEEP";
	f_clos(&cl__1);
    }
    return 0;
} /* cpuclo_ */

