/* APT104.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal darray[15];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__13 = 13;
static integer c__68 = 68;
static integer c__114 = 114;
static integer c__85 = 85;
static integer c__5 = 5;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c__3 = 3;
static integer c__8 = 8;
static integer c__30 = 30;
static integer c__89 = 89;
static integer c__90 = 90;

/* *** SOURCE FILE : M0002815.V09   *** */


/* ...  FORTRAN SUBROUTINE APT104                  5/70      RW */

/*                         FORTRAN SUBROUTINE APT104 */


/* PURPOSE      TO GENERATE THE CFSFIL FILE FOR THE SUBSEQUENT PREP- */
/*              ARATION OF OBJECT PLOTS AND/OR ENGINEERING COMPUTATIONS */
/*              AS EFFECTED BY THE FOLLOWING APT STATEMENT */

/*              CFSAVE/PART */

/* CALLING SEQUENCE    CALL APT104(PART) */

/* ARGUMENTS    PART          ARRAY CONTAINING THE CANONICAL FORM FOR */
/*                            THE OBJECT OF INTEREST. */

/* CALLED BY    NONE */

/* SUBSIDIARIES TYPE              ENTRY */
/*              INTEGER FUNCTION  ADDRSS */
/*              SUBROUTINE        ERROR */
/*              SUBROUTINE        GSURF */
/*              SUBROUTINE        INCAN */
/*              INTEGER FUNCTION  XCANON */
/*              SUBROUTINE        UNPACK */

/* RESTRICTIONS NONE */

/* DIAGNOSTICS  ERROR CODE    COMMENT */

/*              85            REFERENCED ELEMENT NOT PROPERLY DEFINED. */

/*              89            INVALID OR ERRONEOUS CANONICAL FORM */
/*                            ENCOUNTERED.  BOUNDED GEOMETRY PROCESSING */
/*                            TERMINATED. */

/*              90            TOO MUCH EMBEDDEDNESS IN BOUNDS AND */
/*                            OBJECT STATEMENTS.  BOUNDED GEOMETRY */
/*                            PROCESSING TERMINATED. */



/* Subroutine */ int apt104_(doublereal *part)
{
    /* Initialized data */

    static integer kmax = 30;
    static integer ksmax = 24;

    /* Format strings */
    static char fmt_90[] = "";
    static char fmt_100[] = "";

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k, l, m, nn, ks, is;
#define can ((doublereal *)&_BLNK__1 + 40)
    extern integer bcdf_(char *, ftnlen);
    static integer iabs, mode, isub, mstk[30], isiz;
    extern /* Subroutine */ int incan_(integer *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_();
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern logical ckdtr_(doublereal *);
    static integer index;
    extern /* Subroutine */ int iconv_(integer *, doublereal *, integer *, 
	    integer *);
    static integer isize[31];
    extern logical ckstr_(doublereal *);
    extern /* Subroutine */ int gsurf_(doublereal *, doublereal *, integer *, 
	    integer *, logical *), error_(integer *, char *, ftnlen), badnam_(
	    doublereal *);
    static logical bndflg;
    static doublereal bndnam;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal coebuf[10];
    static integer iwhich[30], iarray[48]	/* was [2][24] */;
    static doublereal bndary[24];
    static logical errflg;
    extern integer addrss_(doublereal *), xcanon_(integer *);
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), cprint_(doublereal *);

    /* Assigned format variables */
    static char *m_fmt;





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/* ...            SYSTEM I/O FILE NAMES */

/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...                SYSTEM I/O FILES */





/* ...  LOCAL VARIABLES */

    /* Parameter adjustments */
    --part;

    /* Function Body */

/* ...  INITIALIZE. */

    k = 1;
    bndflg = FALSE_;

/* ...  DETERMINE VIRTUAL INDEX OF PART(1) IN COM-ARRAY. */

    iabs = (addrss_(&part[1]) - addrss_(_BLNK__1.com)) / idef_1.kwrdsz + 1;
    index = iabs;
    if (ldef_1.canflg) {
	incan_(&index);
    }
    index -= idef_1.iblk1;

/* ...  DETERMINE SIZE AND MODE OF CANONICAL FORM FOR PART. */

    unpack_(&_BLNK__1.com[iabs - 1], &mode, isize, &isub);

    if (mode != 28) {
	goto L900;
    }

/* ...  PRINT VERIFICATION LISTING. */

    nn = isize[0] + 1;
    bndnam = part[nn];
    cform_("0", darray_1.darray, &c__0, &c__1, (ftnlen)1);
    cform_("CFSAVE/", darray_1.darray, &c__6, &c__7, (ftnlen)7);
    cform_(&bndnam, darray_1.darray, &c__13, &c__6);
    cprint_(darray_1.darray);
    cform_("NAME PRI.  SUB      * * *  B O U N D I N G   S U R F   A C E S  "
	    " * * *", darray_1.darray, &c__1, &c__68, (ftnlen)70);
    cprint_(darray_1.darray);
    cform_("SURF       1ST   SUB MOD  2ND   SUB MOD  3RD   SUB    MOD  4TH  "
	    " SUB MOD  5TH   SUB MOD 6TH   SUB MOD  7TH   SUB MOD     ", 
	    darray_1.darray, &c__6, &c__114, (ftnlen)121);
    cprint_(darray_1.darray);
    goto L40;

/* ...  DETERMINE MODE, SIZE AND SUBSCRIPT OF NEXT FORM AND CHECK VALIDITY */

L20:
    nn = k + 1;
    unpack_(&_BLNK__1.com[iabs - 1], &mode, &isiz, &isub);
    if (isiz <= 0 || isiz > 48 || isub < 0 || isub > 999 || mode <= 0) {
	goto L900;
    }
    isize[nn - 1] = isiz;
    m = 0;
    m_fmt = fmt_90;

/* ...  DETERMINE IF FORM HAS BEEN DEFINED AND CHECK ITS MODE. */
/*     BYPASS WRITING OF BEVISION INPUT FILE IF PRIOR ERRORS HAVE OCCURED */

    if (mode - 28 >= 0) {
	goto L30;
    } else {
	goto L25;
    }
L25:
    if (ckdtr_(&_BLNK__1.com[iabs - 1])) {
	goto L28;
    }
    if (mode == 27) {
	goto L60;
    }

/* ...  BYPASS WRITING CFSAVE FILE IF PRIOR BOUNDED GEOM. ERR DETECTED. */

    if (ldef_1.bnderr) {
	goto L140;
    }
    gsurf_(coebuf, &_BLNK__1.com[iabs - 1], &mode, &isiz, &errflg);
    if (! errflg) {
	goto L110;
    }

/* ...  ERROR 85 - REFERENCED ELEMENT NOT PROPERLY DEFINED. */

L28:
    ldef_1.bnderr = TRUE_;
    error_(&c__85, "APT104  ", (ftnlen)8);
    goto L140;
/* ...  AN OBJECT. */

L30:
    ++k;
    if (k > kmax) {
	goto L910;
    }

/* ...  SET MAIN STACK. */

L40:
    mstk[k - 1] = index;
    iwhich[k - 1] = index + 1;
    if (mode != 28) {
	goto L70;
    }

/* ...  MAKE SURE CANONICAL FORM IN OBJECT ARGUMENT IS NOT ERRONEOUSLY DE- */
/*     FINED.  SAVE ITS VIRTUAL INDEX. */

L45:
    if (ckstr_(&_BLNK__1.com[iabs - 1])) {
	goto L900;
    }
    index = (integer) _BLNK__1.com[iabs];

/* ...  DETERMINE ABSOLUTE INDEX. */

L50:
    iabs = index + idef_1.iblk1;
    if (ldef_1.canflg) {
	i__1 = iabs - 1;
	iabs = xcanon_(&i__1) + 1;
    }
    goto L20;

/* ...  A BOUNDS. */
/*     IF NOT THE FIRST BOUND AFTER AN OBJECT GO GET PRIMARY SURFACE. */

L60:
    if (bndflg) {
	goto L65;
    }

/* ...  FOR FIRST BOUND AFTER ENCOUNTERING AN OBJECT STATEMENT, PUT ON STK */

    bndflg = TRUE_;
    goto L30;

/* ...  SET TO SAVE HALF-SPACE MODIFIER ASSOCIATED WITH BOUNDS ARGUMENT. */

L65:
    m = 1;
    m_fmt = fmt_100;
    goto L80;

/* ...  FIRST TIME THRU A BOUNDS STATEMENT.  SET TO PRINT ITS NAME. */

L70:
    ks = 1;
    nn = isize[k - 1];
    bndnam = _BLNK__1.com[iabs + nn - 1];

/* ...  DETERMINE VIRTUAL INDEX AND SUBSCRIPT FROM BOUNDS PACKED WORD. */
/*     SAVE ITS NAME IN BNDARY(KS), HALF-SPACE MODIFIER IN IARRAY(1,KS), */
/*     AND SUBSCRIPT IN IARRAY(2,KS). */

L80:
    bndary[ks - 1] = _BLNK__1.com[iabs - 1];
    nn = (integer) _BLNK__1.com[iabs];
    index = nn / knumbr_1.k1e4;
    iarray[(ks << 1) - 1] = (nn - index * knumbr_1.k1e4) / knumbr_1.k10;
    switch (m) {
	case 0: goto L90;
	case 1: goto L100;
    }

/* ...  SAVE OLD HALF-SPACE MODIFIER IF BOUNDS ARGUMENT IS A BOUNDS. */

L90:
    iarray[(ks << 1) - 2] = nn - index * knumbr_1.k1e4 - iarray[(ks << 1) - 1]
	     * knumbr_1.k10;

/* ...  IF CANONICAL FORM IN BOUNDS ARGUMENT IS ERRONEOUSLY DEFINED, */
/*     SKIP IT.  IF OKAY, DETERMINE ITS ABSOLUTE INDEX. */

L100:
    if (! ckstr_(&_BLNK__1.com[iabs - 1])) {
	goto L50;
    }
    badnam_(&bndary[ks - 1]);
    goto L140;

/* ...  WRITE BEVISION INPUT FILE. */

L110:
    if (ks == 1) {
	goto L120;
    }

/*     WRITE BOUNDING SURFACE COEFFICIENTS. */

/*     WRITE (CFSFIL,112) IARRAY(1,KS),(COEBUF(I), I=1,10) */
/* L112: */
    goto L140;

/*     WRITE NUMBER OF BOUNDS. */

L120:
    isiz = (isize[k - 1] - 2) / 2;
/*     WRITE (CFSFIL,125) ISIZ */
/* L125: */

/*     WRITE PRIMARY SURFACE COEFFICIENTS. */

/*     WRITE (CFSFIL,128) (COEBUF(I), I=1,10) */
/* L128: */

/* ...  LOOK AT NEXT BOUNDS ARGUMENT AND SAVE POINTER UNTIL ALL BOUNDS */
/*     ARE FOUND. */

L140:
    index = iwhich[k - 1] + 2;
    is = mstk[k - 1];

/* ...  TEST FOR END OF A BOUNDS STATEMENT. */

    if (index > is + isize[k - 1]) {
	goto L150;
    }
    ++ks;
    if (ks > ksmax) {
	goto L910;
    }

/* ...  MORE BOUNDING SURFACES. */

    iwhich[k - 1] = index;
    iabs = idef_1.iblk1 + index - 1;
    if (ldef_1.canflg) {
	iabs = xcanon_(&iabs);
    }
    goto L80;

/* ...  END OF A BOUNDS STATEMENT.  WRITE IT OUT ON VERIFICATION LISTING. */

L150:
    i__1 = ks;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((i__2 = iarray[(i__ << 1) - 2] - 2) < 0) {
	    goto L152;
	} else if (i__2 == 0) {
	    goto L154;
	} else {
	    goto L156;
	}
L152:
	iarray[(i__ << 1) - 2] = bcdf_("IN  ", (ftnlen)4);
	goto L160;
L154:
	iarray[(i__ << 1) - 2] = bcdf_("OUT ", (ftnlen)4);
	goto L160;
L156:
	iarray[(i__ << 1) - 2] = bcdf_("  * ", (ftnlen)4);
L160:
	;
    }
    cform_(&bndnam, darray_1.darray, &c__1, &c__6);
    cprint_(darray_1.darray);
    cform_(bndary, darray_1.darray, &c__5, &c__6);
    cform_("(   )", darray_1.darray, &c__11, &c__5, (ftnlen)5);
    iconv_(&iarray[1], darray_1.darray, &c__12, &c__3);
    l = 16;
    i__1 = ks;
    for (i__ = 2; i__ <= i__1; ++i__) {
	cform_(&bndary[i__ - 1], darray_1.darray, &l, &c__6);
	i__2 = l + 6;
	cform_("(   )", darray_1.darray, &i__2, &c__5, (ftnlen)5);
	i__2 = l + 7;
	iconv_(&iarray[(i__ << 1) - 1], darray_1.darray, &i__2, &c__3);
	i__2 = l + 11;
	cform_(&iarray[(i__ << 1) - 2], darray_1.darray, &i__2, &c__3);
	l += 15;
	if (i__ == ks) {
	    goto L164;
	}
	if (l < 110) {
	    goto L165;
	}
L164:
	cprint_(darray_1.darray);
	l = 16;
L165:
	;
    }
    bndflg = FALSE_;
L170:
    --k;

/* ...  ARE WE FINISHED. */

    if (k == 0) {
	goto L180;
    }
    index = iwhich[k - 1] + 2;
    is = mstk[k - 1];

/* ...  TEST FOR END OF OBJECT STATEMENT. */

    if (index > is + isize[k - 1]) {
	goto L170;
    }

/* ...  MORE OBJECT ARGUMENTS. */

    iwhich[k - 1] = index;
    iabs = idef_1.iblk1 + index - 1;
    if (ldef_1.canflg) {
	iabs = xcanon_(&iabs);
    }
    goto L45;

/* ...  WRITE MESSAGE IF PRIOR ERRORS DETECTED. */

L180:
    if (ldef_1.bnderr) {
	goto L998;
    }
    cform_("GEOMETRY GENERATION COMPLETED.", darray_1.darray, &c__8, &c__30, (
	    ftnlen)30);
    cprint_(darray_1.darray);
    goto L999;

/* ...  ERROR 89 - INVALID OR ERRONEOUS CANONICAL FORM ENCOUNTERED. */
/*     BOUNDED GEOMETRY PROCESSING TERMINATED. */

L900:
    error_(&c__89, "APT104  ", (ftnlen)8);
    goto L998;

/* ...  ERROR 90 - TOO MUCH EMBEDDEDNESS IN BOUNDS AND OBJECT STATEMENTS. */
/*     BOUNDED GEOMETRY PROCESSING TERMINATED. */
L910:
    error_(&c__90, "APT104  ", (ftnlen)8);
L998:
    cform_("***BOUNDED GEOMETRY ERRORS DETECTED. NO BEVISION INP  UT FILE WR"
	    "ITTEN.", darray_1.darray, &c__8, &c__68, (ftnlen)70);
    cprint_(darray_1.darray);
/*     REWIND CFSFIL */

/* ...  WRITE END OF FILE INDICATOR. */

L999:
/*     WRITE (CFSFIL,125) KM1 */
/*     END FILE CFSFIL */
/*     REWIND CFSFIL */
    return 0;
} /* apt104_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


