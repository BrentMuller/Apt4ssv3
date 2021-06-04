/* ATAPOP.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__36 = 36;
static integer c__37 = 37;
static integer c__42 = 42;
static integer c_n2 = -2;
static integer c_n3 = -3;
static integer c__2 = 2;
static integer c__51 = 51;

/* *** SOURCE FILE : ATAPOP00.ORG   *** */

/* Subroutine */ int atapop_0_(int n__, integer *no, integer *n, integer *
	iret)
{
    /* System generated locals */
    alist al__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_cmp(char *, char *, ftnlen, ftnlen), f_back(
	    alist *);

    /* Local variables */
    static integer id;
    static char iacc[12];
    static integer ifil;
    extern /* Subroutine */ int cform_(), tapop_(integer *, integer *), 
	    cprint_(char *, ftnlen);


/*  *  ATAPOP  *  VAX-11 VERSION   13.07.82  E.MCLELLAN */

/*  PURPOSE     TO PROVIDE FILE POSITIONING CAPABILITY */
/*              COMPATABLE WITH APT 111 POST PROCESSOR USAGE */

/*  CALLING SEQUENCE */
/*              CALL ATAPOP(NO,N,IRET) */
/*  ARGUMENTS */
/*              NO         FILE NUMBER */
/*                         FOR NC 360 HELD IN SECOND HALF */
/*                         OF DOUBLE PRECISION WORD */
/*              N=1        REWIND FILE */
/*               =2        WRITE END OF FILE (CLOSE FILE) */
/*               =3        BACKSPACE RECORD */
/*              IRET.GT.0  ABNORMAL ERROR CONDITION */
/*                  .LT.0  OPERATION SUCCESSFUL */

/*  ALTERNATE ENTRY */
/*              CALL TAPEOP(NO,N,IRET) */




/*  *  FILE ATTRIBUTES  * */










/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




    /* Parameter adjustments */
    --no;

    /* Function Body */
    switch(n__) {
	case 1: goto L_tapeop;
	}


L_tapeop:
    *iret = -1;

    ifil = no[1];
    if (no[1] == 0) {
	ifil = no[2];
    }
    if (ifil < 1 || ifil > 50) {
	cform_("0 *** FILE NUMBER OUTSIDE RANGE 1-50", darray_1.darray, &c__1,
		 &c__36, (ftnlen)36, (ftnlen)120);
	cform_(" REQUESTED IN CALL TO ATAPOP OR TAPEOP ***", darray_1.darray, 
		&c__37, &c__42, (ftnlen)42, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	*iret = 1;
    } else {

	if (*n == 1) {
/* .....REWIND */
	    tapop_(&ifil, &c_n2);
	} else if (*n == 2) {
/* .....CLOSE FILE */
	    tapop_(&ifil, &c_n3);
	} else if (*n == 3) {
/* .....BACKSPACE ONE RECORD */
	    id = ifiltb_1.u[ifil - 1];
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
/* .....DECREASE NO OF NEXT RECORD TO BE READ BY 1 */
		--ifiltb_1.nxtrec[ifil - 1];
	    } else {
		al__1.aerr = 0;
		al__1.aunit = id;
		f_back(&al__1);
	    }

	} else {
	    cform_(" *** INVALID ARGUMENT IN CALL TO ATAPOP(TAPEOP) ***", &
		    c__2, &c__51, (ftnlen)51);
	    cprint_(darray_1.darray, (ftnlen)120);
	}
	*iret = 1;
    }
    return 0;
} /* atapop_ */

/* Subroutine */ int atapop_(integer *no, integer *n, integer *iret)
{
    return atapop_0_(0, no, n, iret);
    }

/* Subroutine */ int tapeop_(integer *no, integer *n, integer *iret)
{
    return atapop_0_(1, no, n, iret);
    }

