/* ABUFTP.f -- translated by f2c (version 20100827).
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

static integer c__2 = 2;
static integer c__35 = 35;
static integer c__37 = 37;
static integer c__42 = 42;
static integer c_n4 = -4;
static integer c_n3 = -3;
static integer c__51 = 51;

/* *** SOURCE FILE : ABUFTP00.V01   *** */

/* Subroutine */ int abuftp_0_(int n__, integer *no, integer *n)
{
    /* System generated locals */
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *);

    /* Local variables */
    static integer id;
    static logical od;
    static integer ifil;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), tapop_(integer *, integer *), abnend_(void), 
	    filopn_(integer *), cprint_(char *, ftnlen);


/*  *  ABUFTP  *  VAX-11 VERSION   08.07.82  E.MCLELLAN */

/*  PURPOSE     TO PROVIDE FILE HANDLING  CAPABILITY */
/*              COMPATABLE  WITH APT 111 POST PROCESSOR USAGE */

/*  CALLING SEQUENCE */
/*              CALL ABUFTP(NO,N) */
/*  ARGUMENTS */
/*              NO    FILE NUMBER */
/*                    FOR NC 360 HELD IN SECOND HALF */
/*                    OF REAL*8 WORD */
/*              N=1   OPEN FILE IN WRITE MODE */
/*               =2   OPEN FILE IN READ MODE */
/*               =3   REWIND FILE */
/*               =9   CLOSE FILE */

/*  ALTERNATIVE ENTRY */
/*              CALL BUFFTP(NO,N) */



/*  *  FILE ATTRIBUTES  * */










/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





    /* Parameter adjustments */
    --no;

    /* Function Body */
    switch(n__) {
	case 1: goto L_bufftp;
	}


L_bufftp:
    ifil = no[1];
    if (no[1] == 0) {
	ifil = no[2];
    }

    if (ifil < 1 || ifil > 50) {
	cform_(" *** FILE NUMBER OUTSIDE RANGE 1-50", darray_1.darray, &c__2, 
		&c__35, (ftnlen)35, (ftnlen)120);
	cform_(" REQUESTED IN CALL TO ABUFTP OR BUFFTP ***", darray_1.darray, 
		&c__37, &c__42, (ftnlen)42, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	abnend_();
    } else {
	id = ifiltb_1.u[ifil - 1];

	if (*n == 1) {
/* ....    OPEN FILE IN WRITE MODE */

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
		return 0;
	    } else {
		filopn_(&ifil);
	    }

	} else if (*n == 2) {

/* .....   OPEN FILE IN READ MODE */

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
		return 0;
	    } else {
		filopn_(&ifil);
	    }

	} else if (*n == 3) {

/* .....   REWIND FILE */

	    tapop_(&ifil, &c_n4);

	} else if (*n == 9) {

/* .....   CLOSE FILE */

	    tapop_(&ifil, &c_n3);

	} else {

/* .....   INVALID ARGUMENT */

	    cform_(" *** INVALID ARGUMENT IN CALL TO ABUFTP(BUFFTP) ***", 
		    darray_1.darray, &c__2, &c__51, (ftnlen)51, (ftnlen)120);
	    cprint_(darray_1.darray, (ftnlen)120);
	    abnend_();

	}
    }
    return 0;
} /* abuftp_ */

/* Subroutine */ int abuftp_(integer *no, integer *n)
{
    return abuftp_0_(0, no, n);
    }

/* Subroutine */ int bufftp_(integer *no, integer *n)
{
    return abuftp_0_(1, no, n);
    }

