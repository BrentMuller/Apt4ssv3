/* PAGE.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer ntb, fpb, ppb, comn;
} stor_;

#define stor_1 stor_

struct {
    integer pgc;
} work_;

#define work_1 work_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__256 = 256;
static integer c__1 = 1;
static integer c__47 = 47;

/* *** SOURCE FILE : M0004101.V11   *** */


/* .....IMPLEMENTATION DEPENDENT FUNCTION     .....PAGE...    8/68     HG */
/* .....FORTRAN FUNCTION              ..PAGE..     HG   6/68 */

integer page_(integer *m)
{
    /* Initialized data */

    static integer pgp = 2000000;
    static integer pgc1 = 0;
    static integer pag[1200]	/* was [600][2] */ = { 0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0 };
    static integer pgl[2] = { 0,0 };

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__, j, k, n;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
    static integer jn, ir;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int help_(void);
    static integer ipgp;
    extern /* Subroutine */ int aread_(integer *, integer *, integer *, 
	    integer *, integer *);
#define elfil ((integer *)&symfil_1 + 11)
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static logical pagflg;
    extern /* Subroutine */ int cprint_(char *, ftnlen);



/* PG.C1        LOAD POINT OF CURRENT PAGE */
/* PG.P         LOAD POINT FOR LAST PAGE LOADED */
/* PG.L         LAST PAGE TO BE LOADED. =0 DURING LOADING OF LABEL,RESERV */
/*              TEXT */
/* PAG          TABLE GIVING LOCATION OF A PAGE.  IF PAGE NOT */
/*              IN CORE,TABLE ENTRY = 0. */
/* I.PG.P       PAGE INITIAL LOAD POINT */
/* N            NUMBER OF REQUIRED PAGE */
/* I            = 1 FOR PART PROGRAM TEXT,=2 FOR MACRO TEXT */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*     ------------------- */


/* ...            SYSTEM I/O FILE NAMES */



/* ...                SYSTEM I/O FILES */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */







    n = *m;
/* CHECK IF N WITHIN LIMITS */
    if (abs(n) > 600) {
	goto L9998;
    }

/* SET PAGE TYPE INDICATOR I. */
    i__ = 1;
    if (n < 0) {
	goto L110;
    } else if (n == 0) {
	goto L9998;
    } else {
	goto L120;
    }
L110:
    n = -n;
    i__ = 2;

/* IS PAGE IN CORE */
L120:
    if (pag[n + i__ * 600 - 601] != 0) {
	goto L140;
    }

/* NO */
/* IS PAGE TO BE LOADED LABEL,RESERV TEXT */
    if (pgl[0] != 0) {
	goto L200;
    }

/* YES */
/* LOAD LABEL,RESERV TEXT */
    jn = 0;
    aread_(&symfil_1.elfil1, &jn, &pp[stor_1.ppb - 1], &c__256, &ir);
    if (ir == 1) {
	goto L400;
    }
/* INDICATE BEGINNING OF PAGE */
    ret_val = stor_1.ppb;

/* KEEP CURRENT PAGE NUMBER AT 0 */
    work_1.pgc = -1;
    return ret_val;


/* NO.  MACRO OR PART PROGRAM TEXT */
/* BEGIN CYCLIC SEARCH */
L200:
    pagflg = TRUE_;

/* HOLD STARTING POINT */
    ipgp = pgp;

/* OBTAIN NEW LOAD POINT */
L210:
    pgp += 256;

/* WILL PAGE BE OUTSIDE LIMITS OF STORAGE */
    if (pgp + 255 <= stor_1.comn << 1) {
	goto L220;
    }

/* YES */
/* RETURN POINTER TO INITIAL LOAD POINT */
    pgp = stor_1.ppb;

/* HAS COMPLETE CYCLE BEEN MADE */
L220:
    if (ipgp != pgp) {
	goto L230;
    }

/* YES,A MACRO TEXT PAGE MAY NOW BE SCRATCHED */
    pagflg = FALSE_;
    goto L210;

/* NO,CYCLE NOT COMPLETE */
/* IS LOAD POINT AT CURRENT PAGE */
/* IF YES, CONTINUE SEARCH, CURRENT PAGE IS NOT TO BE SCRATCHED */
L230:
    if (pgp == pgc1) {
	goto L210;
    }

/* NO */
/* CAN MACRO TEXT BE SCRATCHED */
    if (! pagflg) {
	goto L300;
    }

/* NO,IS PAGE MACRO TEXT.  IF YES CONTINUE SEARCH. */
    if (pp[pgp - 1] < 0) {
	goto L210;
    }

/* PAGE CAN BE SCRATCHED */
/*  REMOVE REFERENCE TO DELETED PAGE */
L300:
    k = 1;
    j = pp[pgp - 1];
    if (j == 0) {
	goto L306;
    }
    if (j > 0) {
	goto L303;
    }
    j = -j;
    k = 2;
L303:
    pag[j + k * 600 - 601] = 0;

/* NEXT */
/* LOAD DESIRED PAGE */
L306:
    aread_(&elfil[i__ - 1], &n, &pp[pgp - 1], &c__256, &ir);
    if (ir == 1) {
	goto L9998;
    }

/* SAVE NUMBER OF LAST PAGE TO BE LOADED */
/* L130: */
    pgl[i__ - 1] = n;

/* SET POINTER TO PAGE */
/* ---    STORE A COMPACT VERSION OF THE PAGE LOCATION IN PAG */
    pag[n + i__ * 600 - 601] = (pgp - 1) / 2;

/* INDICATE STARTING LOCATION OF PAGE */
/* ---    RETRIEVE THE CURRENT PAGE LOCATION */
L140:
    ret_val = (pag[n + i__ * 600 - 601] << 1) + 1;

/* SAVE CURRENT PAGE LOAD POINT */
    pgc1 = ret_val;
    return ret_val;

/* ERROR TOO MANY PAGES-N TOO LARGE. */
L9998:
    cform_("029001 TOO MANY STATEMENTS IN THIS PART PROGRAM ", 
	    darray_1.darray, &c__1, &c__47, (ftnlen)48, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    help_();
    return ret_val;

/* CLEAR PAGE AREA */
L400:
    pgp = stor_1.ppb;
L410:
    pp[pgp - 1] = 0;
    pgp += 256;
    if (pgp >= stor_1.comn << 1) {
	goto L200;
    }
    goto L410;
} /* page_ */

#undef bcanon
#undef sscan
#undef canon
#undef elfil
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


