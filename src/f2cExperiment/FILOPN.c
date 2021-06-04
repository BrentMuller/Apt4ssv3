/* FILOPN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : FILOPN00.ORG   *** */


/*  * FILOPN *    VAX11 FORTRAN SUBROUTINE  10.5.82 E.MCLELLAN */
/*                MODIFIED                  18.07.85 E.MCLELLAN */

/*  PURPOSE     TO OPEN A FILE WITH REQUIRED ATTRIBUTES */

/*  CALLING SEQUENCE */
/*              CALL FILOPN(NO) */
/*  ARGUMENTS */
/*              NO    FILE NUMBER */

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
/*        DARRAY     CHARACTER  PRINT BUFFER */
/*        POSN       INTEGER    START POSITION IN PRINT BUFFER */
/*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN BUFFER */

/*  FILES:  FILE REFERENCED BY FILE NUMBER */

/*  SUBSIDIARIES: */
/*               CFORM */
/*               ICONV */
/*               CPRINT */

/* Subroutine */ int filopn_(integer *no)
{
    /* Initialized data */

    static char darray[80] = "                                              "
	    "                                  ";

    /* System generated locals */
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *);

    /* Local variables */
    static integer slen, iret, posn;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), abnend_(void), cprint_(char *, ftnlen);




/*  *  FILE ATTRIBUTES  * */






/* c   fortran 77 disallows a named scratch file */
/*       if(opstat(no).eq.'SCRATCH')then */
/*            write(*,*)'opstat is scratch' */
/*            write(*,*)'opstat is: ',opstat(no) */
/* c    no file name- */
/*      open (unit=u(no),iostat=iret,err=90, */
/*     1      status=opstat(no),access=filacc(no), */
/*     2      form=filfmt(no),recl=rl(no)) */
/*      else */
/* c    file name- */
    o__1.oerr = 1;
    o__1.ounit = ifiltb_1.u[(0 + (0 + (*no - 1 << 2))) / 4];
    o__1.ofnmlen = 16;
    o__1.ofnm = filtab_1.filnam + (0 + (0 + (*no - 1 << 4)));
    o__1.orl = ifiltb_1.rl[(120 + (0 + (*no - 1 << 2)) - 120) / 4];
    o__1.osta = filtab_1.opstat + (1110 + (0 + (*no - 1) * 7) - 1110);
    o__1.oacc = filtab_1.filacc + (480 + (0 + (*no - 1) * 10) - 480);
    o__1.ofm = filtab_1.filfmt + (780 + (0 + (*no - 1) * 11) - 780);
    o__1.oblnk = 0;
    iret = f_open(&o__1);
    if (iret != 0) {
	goto L90;
    }
/*            write(*,*)'opstat is: ',opstat(no) */
/*      endif */

/*      gfortran doesn't like an option in this open statement */
/*     OPEN (UNIT=U(NO),FILE=FILNAM(NO),IOSTAT=IRET,ERR=90, */
/*    1      STATUS=OPSTAT(NO),ACCESS=FILACC(NO), */
/*    2      FORM=FILFMT(NO),RECL=RL(NO)) */
/*     open (unit=u(no),file=filnam(no),iostat=iret,err=90, */
/*      open (unit=u(no),iostat=iret,err=90, */
/*     1      status=opstat(no),access=filacc(no), */
/*     1      access=filacc(no), */
/*     2      form=filfmt(no),recl=rl(no)) */

    return 0;

L90:
    slen = 0;
    cform_(" **** ERROR OPENING FILE :", darray, &c__2, &slen, (ftnlen)26, (
	    ftnlen)80);
    posn = slen + 3;
    slen = 0;
    cform_(filtab_1.filnam + (*no - 1 << 4), darray, &posn, &slen, (ftnlen)16,
	     (ftnlen)80);
    posn = posn + slen + 1;
    slen = 0;
    cform_("; UNIT NO :", darray, &posn, &slen, (ftnlen)11, (ftnlen)80);
    posn = posn + slen + 1;
    iconv_(&ifiltb_1.u[*no - 1], darray, &posn, &c__2, (ftnlen)80);
    posn += 4;
    slen = 0;
    cform_("****", darray, &posn, &slen, (ftnlen)4, (ftnlen)80);
    cprint_(darray, (ftnlen)80);
    abnend_();
    return 0;
} /* filopn_ */

