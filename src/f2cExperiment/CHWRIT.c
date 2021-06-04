/* CHWRIT.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : CHWRIT00.ORG   *** */


/*  *  CHWRIT  *                    18.06.86   E.MCLELLAN */

/*  PURPOSE     TO WRITE ONE CHARACTER RECORD ON A SPECIFIED FILE */

/*  CALLING SEQUENCE */
/*              CALL CHWRIT (NO,IRECNO,CDATA,ISIZE,IRET) */
/*  ARGUMENTS */
/*              NO        FILE NUMBER */
/*              IRECNO    RECORD NO. IF SET TO ZERO WILL WRITE */
/*                        NEXT RECORD. CONTAINS ACTUAL RECORD */
/*                        NUMBER ON RETURNING */
/*              CDATA     CHARACTER ARRAY CONTAINING RECORD TO */
/*                        BE WRITTEN ON THE FILE */
/*              ISIZE     SIZE OF RECORD (IN BYTES) */
/*              IRET      RETURN FLAG =0  NO ERROR */
/*                                    =1  ERROR */

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
/*                                         (DIRECT ACCESS) */

/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*        OD         LOGICAL    FLAG TO INDICATE IF FILE IS OPENED */
/*        IACC       CHARACTER  FILE ACCESS TYPE RETURNED BY INQUIRE */
/*        DARRAY     CHARACTER  PRINT BUFFER */
/*        CDUM       CHARACTER  DUMMY ARRAY FOR FILLING OUT A PHYSICAL */
/*                              RECORD */
/*        NUM        INTEGER    NUMBER OF FULL PHYSICAL RECORDS TO */
/*                              WRITTEN FOR LOGICAL RECORD */
/*        POSN       INTEGER    START POSITION IN PRINT BUFFER */
/*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN PRINT BUFFER */

/*  FILES:  FILE REFERENCED BY FILE NUMBER */

/*  SUBSIDIARIES: */
/*               FILOPN */
/*               CFORM */
/*               ICONV */
/*               CPRINT */

/* Subroutine */ int chwrit_(integer *no, integer *irecno, char *cdata, 
	integer *isize, integer *iret, ftnlen cdata_len)
{
    /* Initialized data */

    static char darray[80] = "                                              "
	    "                                  ";
    static char cdum[1] = " ";

    /* System generated locals */
    integer i__1, i__2;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_cmp(char *, char *, ftnlen, ftnlen), s_wdue(
	    cilist *), do_uio(integer *, char *, ftnlen), e_wdue(void), 
	    s_wsue(cilist *), e_wsue(void);

    /* Local variables */
    static integer i__, j, i1, i2, id;
    static logical od;
    static integer num;
    static char iacc[12];
    static integer irec, slen, posn, irecl;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), filopn_(integer *), cprint_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___8 = { 1, 0, 0, 0, 0 };
    static cilist io___14 = { 1, 0, 0, 0, 0 };
    static cilist io___15 = { 1, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };




/*  *  FILE ATTRIBUTES  * */







    /* Parameter adjustments */
    --cdata;

    /* Function Body */

    id = ifiltb_1.u[(0 + (0 + (*no - 1 << 2))) / 4];

/* ---- IS FILE OPENED, IF NOT OPEN */
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
	goto L10;
    }
/* ---- OPEN UNIT */
    filopn_(no);
/* ---- CHECK FILE ACCESS */
L10:
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
/* ---- DIRECT ACCESS FILE */
	irecl = ifiltb_1.rl[*no - 1];
	if (*irecno == 0) {
	    *irecno = ifiltb_1.lstrec[*no - 1] + 1;
	}
	irec = *irecno;
	if (*isize <= irecl) {
	    io___8.ciunit = id;
	    io___8.cirec = irec;
	    *iret = s_wdue(&io___8);
	    if (*iret != 0) {
		goto L90;
	    }
	    i__1 = *isize;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		*iret = do_uio(&c__1, cdata + i__, (ftnlen)1);
		if (*iret != 0) {
		    goto L90;
		}
	    }
	    *iret = e_wdue();
	    if (*iret != 0) {
		goto L90;
	    }
	} else {
	    num = *isize / irecl;
	    i__1 = num;
	    for (j = 1; j <= i__1; ++j) {
		i1 = (j - 1) * irecl + 1;
		i2 = j * irecl;
		io___14.ciunit = id;
		io___14.cirec = irec;
		*iret = s_wdue(&io___14);
		if (*iret != 0) {
		    goto L90;
		}
		i__2 = i2;
		for (i__ = i1; i__ <= i__2; ++i__) {
		    *iret = do_uio(&c__1, cdata + i__, (ftnlen)1);
		    if (*iret != 0) {
			goto L90;
		    }
		}
		*iret = e_wdue();
		if (*iret != 0) {
		    goto L90;
		}
		++irec;
/* L20: */
	    }
	    if (*isize - num * irecl > 0) {
		i1 = num * irecl + 1;
		i2 = (num + 1) * irecl - *isize;
		io___15.ciunit = id;
		io___15.cirec = irec;
		*iret = s_wdue(&io___15);
		if (*iret != 0) {
		    goto L90;
		}
		i__1 = *isize;
		for (i__ = i1; i__ <= i__1; ++i__) {
		    *iret = do_uio(&c__1, cdata + i__, (ftnlen)1);
		    if (*iret != 0) {
			goto L90;
		    }
		}
		i__2 = i2;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    *iret = do_uio(&c__1, cdum, (ftnlen)1);
		    if (*iret != 0) {
			goto L90;
		    }
		}
		*iret = e_wdue();
		if (*iret != 0) {
		    goto L90;
		}
	    } else {
		--irec;
	    }
	}
	if (irec > ifiltb_1.lstrec[*no - 1]) {
	    ifiltb_1.lstrec[*no - 1] = irec;
	}
	ifiltb_1.nxtrec[*no - 1] = irec + 1;
    } else {
/* ---- SEQUENTIAL ACCESS FILE */
	io___16.ciunit = id;
	s_wsue(&io___16);
	i__1 = *isize;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, cdata + i__, (ftnlen)1);
	}
	e_wsue();
    }
    return 0;
L90:
    slen = 0;
    cform_(" *** ERROR WRITING BY CHWRIT ON FILE :", darray, &c__2, &slen, (
	    ftnlen)38, (ftnlen)80);
    posn = slen + 3;
    slen = 0;
    cform_(filtab_1.filnam + (*no - 1 << 4), darray, &posn, &slen, (ftnlen)16,
	     (ftnlen)80);
    posn = posn + slen + 2;
    slen = 0;
    cform_("RECNO :", darray, &posn, &slen, (ftnlen)7, (ftnlen)80);
    posn = posn + slen + 1;
    slen = 6;
    iconv_(irecno, darray, &posn, &slen, (ftnlen)80);
    cprint_(darray, (ftnlen)80);
    *iret = 1;
    return 0;
} /* chwrit_ */

