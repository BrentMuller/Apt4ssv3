/* TAPOP.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__2 = 2;
static integer c__35 = 35;
static integer c__37 = 37;
static integer c__40 = 40;
static integer c__23 = 23;

/* *** SOURCE FILE : TAPOP000.ORG   *** */


/*  *  TAPOP  *   VAX11 VERSION    11.5.82   E.MCLELLAN */
/*                MODIFIED         18.07.85  E.MCLELLAN */

/*  PURPOSE     TO PERFORM I/O FILE HANDLING OPERATIONS */

/*  CALLING SEQUENCE */
/*              CALL TAPOP (NO,N) */
/*  ARGUMENTS */
/*              NO        FORTRAN NUMBER */
/*              N  =-1    REWIND FILE BEFORE WRITING NEW FILE */
/*                 =-2    REWIND FILE BEFORE READING OLD FILE */
/*                 =-3    CLOSE FILE */
/*                 =-4    REWIND FILE */
/*                 =-5    GET THE NO. OF THE NEXT RECORD */


/*  GLOBAL VARIABLES: */

/* --------------------------------------------------- */
/*   VARIABLE        BLOCK     TYPE       DESCRIPTION */
/* --------------------------------------------------- */
/*   FILNAM          FILTAB    CHARACTER  FILE NAME */
/*   FILACC          FILTAB    CHARACTER  FILE ACCESS */
/*                                         (DIRECT OR SEQUENTIAL) */
/*   FILFMT          FILTAB    CHARACTER  FILE FORMAT */
/*                                         (FORMATTED OR UNFORMATTED) */
/*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS */
/*                                         (UNKNOWN,SCRATCH,NEW,OLD) */
/*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE) */
/*   U               IFILTB    INTEGER    UNIT NUMBER */
/*   RL              IFILTB    INTEGER    RECORD LENGTH */
/*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE */
/*                                        READ OR WRITTEN (DIRECT ACCESS) */
/*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE */
/*                                         (DIERECT ACCESS) */
/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*        IACC       CHARACTER  FILE ACCESS RETURNED BY INQUIRE */
/*        DARRAY     CHARACTER  PRINT BUFFER */
/*        POSN       INTEGER    START POSTION IN PRINT BUFFER */
/*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN BUFFER */

/*  FILES:  FILE REFERENCED BY FILE NUMBER */

/*  SUBSIDIARIES: */
/*               FILOPN */
/*               CFORM */
/*               CPRINT */

/* Subroutine */ int tapop_(integer *no, integer *n)
{
    /* Initialized data */

    static char darray[80] = "                                              "
	    "                                  ";

    /* System generated locals */
    integer i__1;
    cllist cl__1;
    alist al__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_clos(cllist *), f_inqu(inlist *), s_cmp(char *, char *, ftnlen, 
	    ftnlen), f_rew(alist *);

    /* Local variables */
    static integer id;
    static char iacc[12];
    static integer slen, posn;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), abnend_(void), filopn_(integer *), cprint_(char *, 
	    ftnlen);



/*  *  FILE ATTRIBUTES  * */






    id = ifiltb_1.u[(0 + (0 + (*no - 1 << 2))) / 4];

    if (*n == -1) {
/* ---- CLOSE FILE */
	cl__1.cerr = 1;
	cl__1.cunit = id;
	cl__1.csta = filtab_1.clstat + (*no - 1) * 6;
	i__1 = f_clos(&cl__1);
	if (i__1 != 0) {
	    goto L91;
	}
/* ---- OPEN FILE */
	filopn_(no);
	ifiltb_1.nxtrec[*no - 1] = 1;
	ifiltb_1.lstrec[*no - 1] = 0;

    } else if (*n == -2) {
	ioin__1.inerr = 0;
	ioin__1.inunit = id;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = 0;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.inname = 0;
	ioin__1.inacclen = 12;
	ioin__1.inacc = iacc;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	f_inqu(&ioin__1);
	if (s_cmp(iacc, "DIRECT", (ftnlen)12, (ftnlen)6) == 0) {
	    ifiltb_1.nxtrec[*no - 1] = 1;
	} else {
	    al__1.aerr = 0;
	    al__1.aunit = id;
	    f_rew(&al__1);
	}
    } else if (*n == -3) {
/* ---- CLOSE FILE */
	cl__1.cerr = 1;
	cl__1.cunit = id;
	cl__1.csta = filtab_1.clstat + (*no - 1) * 6;
	i__1 = f_clos(&cl__1);
	if (i__1 != 0) {
	    goto L91;
	}
    } else if (*n == -4) {
	ioin__1.inerr = 0;
	ioin__1.inunit = id;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = 0;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.inname = 0;
	ioin__1.inacclen = 12;
	ioin__1.inacc = iacc;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	f_inqu(&ioin__1);
	if (s_cmp(iacc, "DIRECT", (ftnlen)12, (ftnlen)6) == 0) {
	    ifiltb_1.nxtrec[*no - 1] = 1;
	} else {
	    al__1.aerr = 0;
	    al__1.aunit = id;
	    f_rew(&al__1);
	}
    } else if (*n == -5) {
	*n = ifiltb_1.lstrec[*no - 1] + 1;
    }
    return 0;
/* L90: */
    slen = 0;
    cform_(" *** ERROR OPENING FILE :", darray, &c__2, &slen, (ftnlen)25, (
	    ftnlen)80);
    posn = slen + 3;
    slen = 0;
    cform_(filtab_1.filnam + (*no - 1 << 4), darray, &posn, &slen, (ftnlen)16,
	     (ftnlen)80);
    posn = posn + slen + 4;
    slen = 0;
    cform_("*** FROM ROUTINE: TAPOP", darray, &posn, &slen, (ftnlen)23, (
	    ftnlen)80);
    cprint_(darray, (ftnlen)80);
    abnend_();
L91:
    cform_(" *** ERROR CLOSING FORTRAN UNIT NO:", darray, &c__2, &c__35, (
	    ftnlen)35, (ftnlen)80);
    iconv_(&ifiltb_1.u[*no - 1], darray, &c__37, &c__2, (ftnlen)80);
    cform_("*** FROM ROUTINE: TAPOP", darray, &c__40, &c__23, (ftnlen)23, (
	    ftnlen)80);
    cprint_(darray, (ftnlen)80);
    return 0;
} /* tapop_ */

