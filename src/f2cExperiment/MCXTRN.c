/* MCXTRN.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer prt[7];
} prt_;

#define prt_1 prt_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx2[902];
} macxx2_;

#define macxx2_1 macxx2_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__35 = 35;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c__350 = 350;
static integer c_n2 = -2;
static integer c__36 = 36;

/* *** SOURCE FILE : M0006654.V06   *** */


/*              FORTRAN SUBROUTINE MCXTRN */

/* LINKAGE      SUBROUTINE MCXTRN(IBR,INDEX,INFO) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    HELP            SUBROUTINE    ALARM */
/*          SUBROUTINE    ALARM           SUBROUTINE    IEPLOG */
/*          SUBROUTINE    AREAD           SUBROUTINE    INPAT */
/*          SUBROUTINE    AWRITE          SUBROUTINE    INPUT */
/*          SUBROUTINE    TAPOP           SUBROUTINE    MACREC */
/*          SUBROUTINE    CHREAD          SUBROUTINE    MOTION */
/*          SUBROUTINE    CHWRIT          INTEGER FCT.  NUMB */
/*                                        SUBROUTINE    OPPAIR */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RESERV */
/*                                        SUBROUTINE    RESRED */

/* Subroutine */ int mcxtrn_(integer *ibr, integer *index, integer *info)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, l, irec, nrec;
    extern /* Subroutine */ int help_(void);
#define nmod ((integer *)&ntbl_1)
    static integer iret, iwrd;
#define nndx ((integer *)&ntbl_1 + 2)
    static integer itmp;
    extern /* Subroutine */ int aread_();
#define mbrec ((integer *)&macxx2_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define mbuff ((integer *)&macxx2_1 + 2)
#define nlast ((integer *)&ntbl_1 + 3)
    extern /* Subroutine */ int tapop_(integer *, integer *);
#define mbptr ((integer *)&macxx1_1 + 29)
#define ncrnt ((integer *)&ntbl_1 + 1)
#define macrtb ((integer *)&macxx2_1 + 702)
#define assemb ((logical *)&prt_1 + 3)
    extern /* Subroutine */ int awrite_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer ibrtmp;
    extern /* Subroutine */ int chwrit_(integer *, integer *, char *, integer 
	    *, integer *, ftnlen);




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NUMBST:      NAMTBL INDEX OF BEGINNING OF NUMBER SECTION */

/*       14.    I. L. LIST OPTION FLAGS */







/* ASSEMB:      SET TRUE INDICATES ASSEMBLY APPROACH (CONTRL/ASMBLE) */

/*       22.    MACRO PROCESSING VARIABLES */

/* MBPTR:       POINTER TO LAST MBREC ENTRY */

/*       23.    MACRO PROCESSING ARRAYS */

/* MBREC:       IDENTIFIES THE RECORDS(350 WORD BLK) CURRENTLY IN MBUFF */
/* BUFF:        BUFFER ARRAY IN ORDER TO READ OR WRITE ON EXTERNAL FILE */
/* MACRTB:      BUFFER ARRAY OF THE EXTERNAL FILE */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* MACTXT:          EXTERNAL FILE  OF MACRO TEXT */
/* XNUM  :          OVERFLOW NUMBER TABLE */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */


/* ...                SYSTEM I/O FILES */



/* NMOD:        NUMBER OF ENTRIES PERMITTED IN INTERNAL NUMBER TABLE */
/* NCRNT:       ACTUAL NUMBER TABLE BLOCK - INITIALLY 1 */
/* NNDX:        CONVERSION BETWEEN ABS. AND VIRTUAL NUMBER TABLE POINTER */
/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */
/* * */
/* ARGUMENTS    IBR     SET TO 1 FOR STORE, 2 FOR RETRIEVE */
/*              INDEX   POINTER TO REFERENCED MACRO TEXT WORD */
/*              INFO    DATA TO BE STORED OR RETRIEVED */
/* ** */
    if (*ibr > 2) {
	goto L500;
    }

/* ...     DETERMINE RECORD NUMBER AND WORD NUMBER */

    itmp = (*index - 1) / 350;
    irec = itmp + 1;
    if (irec < 200) {
	goto L10;
    }
    alarm_(&c__35, &c__0, &c__8, "MCXTRN  ", (ftnlen)8);
    help_();
L10:
    iwrd = *index - itmp * 350;
/* ...  IS THIS RECORD IN THE BUFFERS */
    if (irec == mbrec[*mbptr - 1]) {
	goto L100;
    }
    *mbptr = 3 - *mbptr;
    if (irec == mbrec[*mbptr - 1]) {
	goto L100;
    }
/* ...  WRITE OLD BUFFER TO EXTERNAL FILE */
    i__ = mbrec[*mbptr - 1];
    if (macrtb[i__ - 1] != 0) {
	goto L20;
    }
    nrec = 0;
    awrite_(&symfil_1.mactxt, &nrec, &mbuff[*mbptr * 350 - 350], &c__350, &
	    iret);
    macrtb[i__ - 1] = nrec;
/* ...  RECORD INDICATOR INDICATES NEW RECORD NUMBER */
L20:
    mbrec[*mbptr - 1] = irec;
    if (macrtb[irec - 1] > 0) {
	goto L30;
    }
    if (*ibr == 2) {
	alarm_(&c__35, &c__0, &c__8, "MCXTRN  ", (ftnlen)8);
    }
    goto L100;
/* ...  READ IN RECORD */
L30:
    aread_(&symfil_1.mactxt, &macrtb[irec - 1], &mbuff[*mbptr * 350 - 350], &
	    c__350, &iret);
L100:
    if (*ibr == 2) {
	goto L200;
    }
/* ...  STORE INFO */
    mbuff[iwrd + *mbptr * 350 - 351] = *info;
    if (macrtb[irec - 1] != 0) {
	macrtb[irec - 1] = 0;
    }
    goto L400;
/* ...  READ INFO */
L200:
    *info = mbuff[iwrd + *mbptr * 350 - 351];
    goto L400;


/* ...     NUMBER TABLE OVERFLOW PROCESSING */

L500:
    ibrtmp = *ibr - 2;
    switch (ibrtmp) {
	case 1:  goto L530;
	case 2:  goto L540;
	case 3:  goto L550;
	case 4:  goto L560;
    }

/* ...  WRITE FIRST PART OF TABLE */

L530:
    l = *nmod * 6;
    j = 0;
/* ... 4TH ARGUMENT OF CHWRIT IS NUMBER OF BYTES */
    chwrit_(&symfil_1.xnum, &j, cnamtb_1.cnumtb + (nametb_1.numbst - 1) * 12, 
	    &l, &iret, (ftnlen)12);
    ++(*nlast);
    *nndx += *nmod / 2;
    l = nametb_1.numbst + *nmod / 2 - 1;
    i__1 = l;
    for (i__ = nametb_1.numbst; i__ <= i__1; ++i__) {
	s_copy(cnamtb_1.cnumtb + (i__ - 1) * 12, " ", (ftnlen)12, (ftnlen)1);
/* L544: */
    }
    goto L400;

/* .... WRITE SECOND PART OF TABLE */

L540:
    if (*assemb) {
	goto L805;
    }
    j = 0;
    i__ = nametb_1.numbst + *nmod / 2;
    l = *nmod * 6;
/* ... 4TH ARGUMENT OF CHWRIT IS NUMBER OF BYTES */
    chwrit_(&symfil_1.xnum, &j, cnamtb_1.cnumtb + (i__ - 1) * 12, &l, &iret, (
	    ftnlen)12);
    ++(*nlast);
    *nndx += *nmod / 2;
    *ncrnt = 2;
    goto L400;

/* .... READ IN BLOCK CONTAINING INDEX */

L550:
    l = *nmod / 2;
    if (*index < nametb_1.numbst) {
	goto L400;
    }
    itmp = (*index - nametb_1.numbst) / l;
    *index -= itmp * l;
    if (itmp == *nlast) {
	goto L400;
    }
    *index += l;
    if (itmp + 1 == *ncrnt) {
	goto L400;
    }
    nrec = itmp + 1;
    i__ = nametb_1.numbst + l;
    l *= 12;
/* ... 4TH ARGUMENT OF CHREAD IS NUMBER OF BYTES */
    aread_(&symfil_1.xnum, &nrec, cnamtb_1.cnumtb + (i__ - 1) * 12, &l, &iret)
	    ;
    *ncrnt = nrec;
    goto L400;


/* .... WRITE OUT FINAL RECORD */

L560:
    tapop_(&symfil_1.xnum, &c_n2);
L400:
    return 0;
L805:
    alarm_(&c__36, &c__0, &c__8, "MCXTRN  ", (ftnlen)8);
    help_();
    return 0;
} /* mcxtrn_ */

#undef assemb
#undef macrtb
#undef ncrnt
#undef mbptr
#undef nlast
#undef mbuff
#undef mbrec
#undef nndx
#undef nmod


