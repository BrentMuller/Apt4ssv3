/* RESRED.f -- translated by f2c (version 20100827).
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
    integer stklst[300];
} stklst_;

#define stklst_1 stklst_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer cfsize[205];
} cfsize_;

#define cfsize_1 cfsize_

struct {
    integer sbscpt[101];
} sbscpt_;

#define sbscpt_1 sbscpt_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__2054 = 2054;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0006678.W01   *** */


/*              FORTRAN SUBROUTINE RESRED */

/* LINKAGE      SUBROUTINE RESRED */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ICONV           SUBROUTINE    RECOG */
/*          SUBROUTINE    LIBOPC */
/*          SUBROUTINE    LIBRD */
/*          SUBROUTINE    LIBSCH */
/*          SUBROUTINE    BCDBIN */
/*          SUBROUTINE    MCXTRN */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    CFORM */
/*          SUBROUTINE    RESRVZ */

/* Subroutine */ int resred_(void)
{
    /* Initialized data */

    static char bla[1] = " ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, m, n, n1, jj, inp[20];
#define top ((integer *)&stklst_1)
    static char nam1[6], nam2[6];
    static integer ifla;
    extern integer mode_(integer *);
    static integer iflag;
#define range ((integer *)&sbscpt_1 + 1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen), librd_(char *, integer *, integer *, ftnlen);
#define stack ((integer *)&stklst_1 + 3)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define alopn ((logical *)&macseg_1)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define nlast ((integer *)&ntbl_1 + 3)
#define rngpt ((integer *)&sbscpt_1)
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen),
	     libsch_(char *, integer *, ftnlen), libopc_(integer *, integer *)
	    ;
#define cansiz ((integer *)&cfsize_1 + 5)
#define cantop ((integer *)&cfsize_1)
    static integer ierror, idummy;
#define maxsiz ((integer *)&cfsize_1 + 3)
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *), 
	    resrvz_(integer *, integer *, integer *, integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */

/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */

/*       15.    ARRAY LIMIT STORAGE */

/* RNGPT:       POINTER TO NEXT RANGE ENTRY */
/* RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* ALOPN:       TRUE AFTER MACRO OR PART PROGRAM SEGMENT LIBRARY OPENED */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */
/* ** */
/*    CREATION OF AN INDICATED NAME */
    i__ = stack[(12 + (0 + (1 + (*top - 2 << 1) - 3 << 2)) - 12) / 4];
    if (i__ > nametb_1.nammax) {
	goto L10;
    }
/*   ILLEGAL SYMBOLIC NUMBER-STATEMENT AS IDNEX ON READ-COMMAND */
    i__1 = *top - 2;
    alarm_(&c__2054, &i__1, &c__8, "RESRED  ", (ftnlen)8);
    return 0;
/*   CONSTRUCT STORAGE NAME */
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L10:
    i__ -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &i__, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (i__ - 1) * 12, &m, &n, (ftnlen)12);
    i__1 = m + 10000000;
    iconv_(&i__1, nam2, &c__0, &c__8, (ftnlen)6);
    cform_(cnamtb_1.cnamtb + (stack[(*top - 4 << 1) - 2] - 1) * 6, nam1, &
	    c__0, &c__8, (ftnlen)6, (ftnlen)6);
    for (j = 1; j <= 8; ++j) {
	if (*(unsigned char *)&nam1[j - 1] == *(unsigned char *)&bla[0]) {
	    goto L20;
	}
	*(unsigned char *)&nam2[j - 1] = *(unsigned char *)&nam1[j - 1];
L20:
	;
    }
/*   POSSIBLY OPEN THE PDS */
    if (*alopn) {
	goto L30;
    }
    libopc_(&c__1, &iflag);
    if (iflag == 0) {
	goto L25;
    }
    ierror = 72;
L24:
    alarm_(&ierror, &c__0, &c__8, "RESRED  ", (ftnlen)8);
    goto L41;
L25:
    *alopn = TRUE_;
L30:
    libsch_(nam2, &iflag, (ftnlen)6);
    if (iflag == 0) {
	goto L40;
    }
L32:
    ierror = 73;
    goto L24;
/*   READ FIRST CARD */
L40:
    librd_(nam2, &iflag, inp, (ftnlen)6);
    if (iflag != 0) {
	goto L32;
    }
L41:
    libopc_(&c__2, &ifla);
    *alopn = FALSE_;
    if (iflag != 0) {
	return 0;
    }
/*  TRANSFER MODE AND RESERVE VARIABLE, IF NECESSARY */
    j = stack[(*top - 4 << 1) - 2];
    if (mode_(&j) != 0) {
	goto L7000;
    }
    nametb_1.namtbl[j - 1] += inp[4];
/*  SEARCH VARIABLE IN RESERV STORAGE */
    n1 = *rngpt - 2;
    i__1 = n1;
    for (n = 1; n <= i__1; n += 2) {
	if (range[n - 1] == j) {
	    goto L60;
	}
/* L50: */
    }
/*   THE ERROR IS REPORTED BY THE FOLLOWING CALL SUBCOD */
    return 0;
/*  RESERVE STORAGE */
L60:
    resrvz_(&j, &inp[4], &tmp_1.txxxx[(inp[4] << 1) - 2], &range[n]);
/* THE LENGTH OF THE CANONICAL FORM IS STORED IN INP(8) */
/*  CHANGE MAXSIZ IF NECESSARY */
L7000:
    if (inp[7] <= abs(maxsiz[1])) {
	goto L7040;
    }
    if (inp[7] <= abs(maxsiz[0])) {
	goto L7030;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = inp[7];
    goto L7040;
L7030:
    maxsiz[1] = inp[7];
/* INTERROGATE FOR FREE SPACE */
L7040:
    jj = j % *cantop;
    i__1 = *cantop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = jj % *cantop + 1;
	if (cansiz[(jj << 1) - 1] == j) {
	    goto L7060;
	}
	if (cansiz[(jj << 1) - 2] != 0) {
	    goto L7050;
	}
	cansiz[(jj << 1) - 2] = inp[7];
	cansiz[(jj << 1) - 1] = j;
	return 0;
L7050:
	;
    }
    return 0;
L7060:
    cansiz[(jj << 1) - 2] = inp[7] + cansiz[(jj << 1) - 2];
    return 0;
} /* resred_ */

#undef maxsiz
#undef cantop
#undef cansiz
#undef rngpt
#undef nlast
#undef alopn
#undef stack
#undef range
#undef top


