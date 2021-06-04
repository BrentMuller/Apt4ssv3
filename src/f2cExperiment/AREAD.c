/* AREAD.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : AREAD000.ORG   *** */


/*  *  AREAD  *   VAX11 VERSION   11.5.82   E.MCLELLAN */
/*                MODIFIED        16.7.85   E.MCLELLAN */


/*  PURPOSE     TO READ ONE RECORD FROM A SPECIFIED FILE */

/*  CALLING SEQUENCE */
/*              CALL AREAD (NO,IRECNO,DATA,ISIZE,IRET) */
/*  ARGUMENTS */
/*              NO        FILE NUMBER */
/*              IRECNO    RECORD NO. IF SET TO ZERO RETRIEVES */
/*                        THE NEXT RECORD. IF SET TO 'N' */
/*                        RETRIEVES N-TH RECORD DIRECTLY. */
/*              DATA      DATA ARRAY TO CONTAIN THE RETRIEVED */
/*                        RECORD */
/*              ISIZE     SIZE OF RECORD (IN 4 BYTE WORDS) */
/*              IRET      RETURN FLAG =0  NO ERROR */
/*                                    =1  E.O.F ENCOUNTERED */
/*                                    =2  ISIZE IS BIGGER THAN ACTUAL */
/*                                        RECORD SIZE. DATA ASSUMED TO */
/*                                        SPAN MORE THAN ONE RECORD */
/*                                        DATA TRANSFERRED TO ARRAY */
/*                                    =3  UNRECOVERABLE ERROR */


/*  GLOBAL VARIABLES:  NONE */

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
/*         OD        LOGICAL    FLAG TO INDICATE IF FILE IS OPEN */
/*         IACC      CHARACTER  ACCESS TYPE RETURN BY INQUIRE */
/*         DARRAY    CHARACTER  PRINT BUFFER */
/*         IRECL     INTEGER    RECORD LENGTH */
/*         NUM       INTEGER    NUMBER OF COMPLETE PHYSICAL RECORDS */
/*                              SPANNED BY LOGICAL RECORD BEING READ */
/*         POSN      INTEGER    START POSITION IN PRINT BUFFER */
/*         SLEN      INTEGER    LENGTH OF STRING ENTERED IN PRINT BUFFER */

/*  FILES:  FILE REFERENCED BY FILE NUMBER */

/*  SUBSIDIARIES: */
/*               FILOPN */
/*               CFORM */
/*               ICONV */
/*               CPRINT */

/* Subroutine */ int aread_(integer *no, integer *irecno, real *data, integer 
	*isize, integer *iret)
{
    /* Initialized data */

    static char darray[80] = "                                              "
	    "                                  ";

    /* System generated locals */
    integer i__1, i__2;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_cmp(char *, char *, ftnlen, ftnlen), s_rdue(
	    cilist *), do_uio(integer *, char *, ftnlen), e_rdue(void), 
	    s_rsue(cilist *), e_rsue(void);

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
    static cilist io___7 = { 1, 0, 1, 0, 0 };
    static cilist io___13 = { 1, 0, 1, 0, 0 };
    static cilist io___14 = { 1, 0, 1, 0, 0 };
    static cilist io___15 = { 0, 0, 1, 0, 0 };





/*  *  FILE ATTRIBUTES  * */






    /* Parameter adjustments */
    --data;

    /* Function Body */
    id = ifiltb_1.u[(0 + (0 + (*no - 1 << 2))) / 4];

/* ---- IS UNIT OPENED, IF NOT OPEN */
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
	    *irecno = ifiltb_1.nxtrec[*no - 1];
	}
/* .... IF LSTREC(NO).EQ.0 THEN READING AN EXTERNALLY WRITTEN */
/*     DIRECT ACCESS FILE FOR WHICH LENGTH IS NOT KNOWN */
	if (ifiltb_1.lstrec[*no - 1] != 0 && *irecno > ifiltb_1.lstrec[*no - 
		1]) {
	    *iret = 1;
	    return 0;
	}
	irec = *irecno;
	if (*isize <= irecl) {
	    io___7.ciunit = id;
	    io___7.cirec = irec;
	    *iret = s_rdue(&io___7);
	    if (*iret != 0) {
		goto L100001;
	    }
	    i__1 = *isize;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		*iret = do_uio(&c__1, (char *)&data[i__], (ftnlen)sizeof(real)
			);
		if (*iret != 0) {
		    goto L100001;
		}
	    }
	    *iret = e_rdue();
L100001:
	    if (*iret > 0) {
		goto L90;
	    }
	} else {
	    num = *isize / irecl;
	    i__1 = num;
	    for (j = 1; j <= i__1; ++j) {
		i1 = (j - 1) * irecl + 1;
		i2 = j * irecl;
		io___13.ciunit = id;
		io___13.cirec = irec;
		*iret = s_rdue(&io___13);
		if (*iret != 0) {
		    goto L100002;
		}
		i__2 = i2;
		for (i__ = i1; i__ <= i__2; ++i__) {
		    *iret = do_uio(&c__1, (char *)&data[i__], (ftnlen)sizeof(
			    real));
		    if (*iret != 0) {
			goto L100002;
		    }
		}
		*iret = e_rdue();
L100002:
		if (*iret > 0) {
		    goto L90;
		}
/* L20: */
		++irec;
	    }
	    if (*isize - num * irecl > 0) {
		i1 = num * irecl + 1;
		io___14.ciunit = id;
		io___14.cirec = irec;
		*iret = s_rdue(&io___14);
		if (*iret != 0) {
		    goto L100003;
		}
		i__1 = *isize;
		for (i__ = i1; i__ <= i__1; ++i__) {
		    *iret = do_uio(&c__1, (char *)&data[i__], (ftnlen)sizeof(
			    real));
		    if (*iret != 0) {
			goto L100003;
		    }
		}
		*iret = e_rdue();
L100003:
		if (*iret > 0) {
		    goto L90;
		}
	    } else {
		--irec;
	    }
	    *iret = 2;
	}
	ifiltb_1.nxtrec[*no - 1] = irec + 1;
    } else {
/* ---- SEQUENTIAL ACCESS FILE */
	io___15.ciunit = id;
	i__1 = s_rsue(&io___15);
	if (i__1 != 0) {
	    goto L80;
	}
	i__2 = *isize;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = do_uio(&c__1, (char *)&data[i__], (ftnlen)sizeof(real));
	    if (i__1 != 0) {
		goto L80;
	    }
	}
	i__1 = e_rsue();
	if (i__1 != 0) {
	    goto L80;
	}
    }
    return 0;
L80:
    *iret = 1;
    return 0;
L90:
    slen = 0;
    cform_(" *** ERROR READING BY AREAD FROM FILE :", darray, &c__2, &slen, (
	    ftnlen)39, (ftnlen)80);
    posn = slen + 3;
    slen = 0;
    cform_(filtab_1.filnam + (*no - 1 << 4), darray, &posn, &slen, (ftnlen)16,
	     (ftnlen)80);
    posn = posn + slen + 2;
    slen = 0;
    cform_("RECNO:", darray, &posn, &slen, (ftnlen)6, (ftnlen)80);
    posn = posn + slen + 1;
    slen = 6;
    iconv_(irecno, darray, &posn, &slen, (ftnlen)80);
    cprint_(darray, (ftnlen)80);
    *iret = 3;
    return 0;
} /* aread_ */

