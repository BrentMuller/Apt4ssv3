/* CILOUT.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer pagpak, isc, iscarr, icform, ifloat, icom, macwds, ppwrds;
    logical macflg, labflg, rsvflg;
    integer lpage, buffer[256], labbuf[256], ibuf, ilbuf, pppage, mcpage;
} outbuf_;

#define outbuf_1 outbuf_

struct {
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__19 = 19;
static integer c__27 = 27;
static integer c__92 = 92;

/* *** SOURCE FILE : M0006626.W04   *** */


/*              FORTRAN SUBROUTINE CILOUT */

/* LINKAGE      SUBROUTINE CILOUT(COMAND,COUNT,CODE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    HOLFRM           SUBROUTINE    ICMPRS */
/*          SUBROUTINE    CPRINT */
/*          SUBROUTINE    ICONV */
/*          SUBROUTINE    RLSBUF */
/*          SUBROUTINE    ABCDBN */

/* Subroutine */ int cilout_(integer *comand, integer *count, integer *code)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, l, ibf, nwd;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
    static integer kount;
    extern /* Subroutine */ int abcdbn_(char *, integer *, integer *, ftnlen),
	     holfrm_(integer *, char *, integer *, integer *, integer *, 
	    ftnlen);
#define cilprt ((logical *)&prt_1)
    extern /* Subroutine */ int rlsbuf_(void), cprint_(char *, ftnlen);



/*        1.    NAME TABLE AND TABLE LIMITS */


/*       14.    I. L. LIST OPTION FLAGS */







/* CILPRT:      TRUE WHEN COMPRESSED I.L. PRINTING REQUESTED */

/*       20.    IO - ARRAY */


/*       34.    COMMON BLOCK FOR INTERPRETIVE C.I.L. OUTPUT */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* LABFLG:      INDICATES I.L. COMMAND IS LABEL (INTERPRETER) */
/* RSVFLG:      TRUE IF I.L. COMMAND IS A RESRV (INTERPRETER) */
/* IBUF:        NUMBER OF RECORDS IN BUFFER ARRAY */
/* ILBUF:       NUMBER OF ITEMS IN THE LABBUF ARRAY (INTERPRETER) */
/* BUFFER:      TEMPORARY STORAGE FOR INTERPRETER OUTPUT (PAGES) */
/* LABBUF:      TEMPORARY STORAGE FOR LABEL,HOLDAT ENTRY AND RESRV I.L. */

/*       45.    NUMBER TABLE INDICES */





/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* * */

/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

/* ** */
/* ...     IS THIS A HOLDAT STATEMENT */

    /* Parameter adjustments */
    --code;

    /* Function Body */
    if (*comand == 21) {
	goto L200;
    }
    ibf = *count;
    if (*comand != 9) {
	ibf = *count + numblk_1.nmbrs;
    }
    goto L20;

/* ...     IS THIS A LABEL OR RESRV STATEMENT */

L1:
    if (outbuf_1.labflg || outbuf_1.rsvflg) {
	goto L100;
    }

/* ...     NO */
/* ...     CODE TO GO INTO BUFFER. TEST IF THERE IS ROOM */

    if (outbuf_1.ibuf + ibf + 4 > 256) {
	rlsbuf_();
    }
    outbuf_1.buffer[outbuf_1.ibuf + 2] = *comand;
    outbuf_1.buffer[outbuf_1.ibuf + 3] = ibf;
    outbuf_1.ibuf += 2;
    if (*count == 0) {
	return 0;
    }
    i__1 = *count;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = code[i__];
	if (j <= nametb_1.nammax) {
	    goto L5;
	}
	if (code[i__ - 1] != 7) {
	    goto L5;
	}
	j -= nametb_1.nammax;
	abcdbn_(cnamtb_1.cnumtb + (j - 1) * 12, &outbuf_1.buffer[
		outbuf_1.ibuf + 2], &c__1, (ftnlen)12);
	++outbuf_1.ibuf;
	goto L10;
L5:
	outbuf_1.buffer[outbuf_1.ibuf + 2] = j;
L10:
	++outbuf_1.ibuf;
    }
    if (*comand != 9) {
	numblk_1.nmbrs = 0;
    }
    return 0;

/* ...     IS CILPRT MARKER SET */

L20:
    if (! (*cilprt)) {
	goto L1;
    }

    iconv_(comand, darray_1.darray, &c__1, &c__6, (ftnlen)120);
    iconv_(&ibf, darray_1.darray, &c__7, &c__6, (ftnlen)120);
    l = 13;
    i__1 = *count;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (code[i__] > nametb_1.nammax) {
	    if (code[i__ - 1] == 7) {
		i__2 = l + 2;
		cform_(cnamtb_1.cnumtb + (code[i__] - nametb_1.nammax - 1) * 
			12, darray_1.darray, &i__2, &c__12, (ftnlen)12, (
			ftnlen)120);
		l += 14;
	    } else {
		iconv_(&code[i__], darray_1.darray, &l, &c__6, (ftnlen)120);
		l += 6;
	    }
	} else {
	    iconv_(&code[i__], darray_1.darray, &l, &c__6, (ftnlen)120);
	    l += 6;
	}
	if (l <= 106) {
	    goto L1000;
	}
	l = 13;
	cprint_(darray_1.darray, (ftnlen)120);
L1000:
	;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    goto L1;

/* ...     LABEL OR RESRV STATEMENT. */
/*        CODE TO GO INTO LABBUF. TEST IF THERE IS ROOM */

L100:
    if (outbuf_1.ilbuf + *count + 4 > 254) {
	rlsbuf_();
    }
    outbuf_1.labbuf[outbuf_1.ilbuf + 2] = *comand;
    outbuf_1.labbuf[outbuf_1.ilbuf + 3] = *count;
    outbuf_1.ilbuf += 2;
    i__1 = *count;
    for (i__ = 1; i__ <= i__1; ++i__) {
	outbuf_1.labbuf[outbuf_1.ilbuf + 2] = code[i__];
/* L110: */
	++outbuf_1.ilbuf;
    }
    return 0;

/* ...     HOLDAT STATEMENT */

L200:
    outbuf_1.labflg = TRUE_;
    if (outbuf_1.ilbuf + (*count << 1) > 256) {
	rlsbuf_();
    }
    outbuf_1.labflg = FALSE_;
    outbuf_1.labbuf[outbuf_1.ilbuf + 2] = *comand;
    outbuf_1.labbuf[outbuf_1.ilbuf + 4] = code[1];
    outbuf_1.labbuf[outbuf_1.ilbuf + 5] = code[2];


    outbuf_1.labbuf[outbuf_1.ilbuf + 3] = *count;
    outbuf_1.ilbuf += 4;
    i__1 = *count;
    for (i__ = 3; i__ <= i__1; ++i__) {
	outbuf_1.labbuf[outbuf_1.ilbuf + 2] = code[i__];
/* L210: */
	++outbuf_1.ilbuf;
    }

/* ...     IS CILPRT MARKER SET */

    if (! (*cilprt)) {
	return 0;
    }

    kount = code[2];
    iconv_(comand, darray_1.darray, &c__1, &c__6, (ftnlen)120);
    iconv_(count, darray_1.darray, &c__7, &c__6, (ftnlen)120);
    iconv_(&code[1], darray_1.darray, &c__13, &c__6, (ftnlen)120);
    iconv_(&code[2], darray_1.darray, &c__19, &c__6, (ftnlen)120);
    l = 3;
L1001:
    if (kount <= 93) {
	goto L1002;
    }
    holfrm_(&code[l], darray_1.darray, &c__27, &c__92, &nwd, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    kount += -92;
    l += 23;
    goto L1001;
L1002:
    holfrm_(&code[l], darray_1.darray, &c__27, &kount, &nwd, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
} /* cilout_ */

#undef cilprt


