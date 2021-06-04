/* APT094.f -- translated by f2c (version 20100827).
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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* Table of constant values */

static integer c__5061 = 5061;
static integer c__5062 = 5062;
static integer c__5060 = 5060;

/* *** SOURCE FILE : M0001865.W01   *** */

/* Subroutine */ int apt094_(integer *ldaflg, doublereal *ldaary, doublereal *
	canloc)
{
    /* Initialized data */

    static integer maxldc = 40;
    static integer recnum = 0;
    static integer noldas = 0;
    static integer ldacor[80]	/* was [2][40] */ = { 0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0 };

    /* System generated locals */
    integer i__1;
    doublereal d__1;
    static doublereal equiv_4[1];

    /* Local variables */
    static integer i__, j, k, n, ir, nn, nr;
#define aaa (equiv_4)
    static integer lda[2];
#define can ((doublereal *)&_BLNK__1 + 40)
#define jjj ((integer *)equiv_4)
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int aread_(integer *, integer *, doublereal *, 
	    integer *, integer *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int undef_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int tapop_(integer *, integer *), error_(integer *
	    , char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer kanind;
    extern integer addrss_(doublereal *);
    static integer ldatop;
    extern /* Subroutine */ int awrite_(integer *, integer *, doublereal *, 
	    integer *, integer *);
    static integer cortop;


/* PURPOSE      THE PURPOSE OF THIS SUBROUTINE IS TO READ OR WRITE LARGE */
/*              DATA ARRAY CANONICAL FORMS IN OR OUT OF UNLABELED COMMON */
/*              AND TO UNDEFINE ERRONEOUS L.D.A. CANONICAL FORMS. */
/* ARGUMENTS    LDAFLG        =1, IF WRITE */
/*                            =2, IF READ INTO A SPECIFIC LOCATION.(USED */
/*                                  TO INCORPORATE PREVIOUSLY DEFINED */
/*                                  CANONICAL FORMS INTO A NEWLY CREATED */
/*                                  CANONICAL FORM) */
/*                            =3, IF READ INTO NEXT AVAILABLE UNLABELED */
/*                                COMMON AREA.(USED TO RETRIEVE CANONICAL */
/*                                  FORMS FOR USE IN ARLEM MOTION */
/*                                  STATEMENT PROCESSSING) */
/*                            =4, IF DEFINITION ERROR. */
/*                            =5, LIKE =1 WITHOUT WRITING:FOR SPACE- */
/*                                RESERVATION IN BLANK COMMON FOR NEW */
/*                                GEOMETRY OR OTHER USE OF SPACE BEGINN- */
/*                                ING AT >BCANON(1)< . */
/*                            =6, UPDATE IN PLACE (ON FILE) */
/*                            =7, READ THE FIRST TWO WORDS OF DATA */
/*              LDAARY        SURFACE */
/*              CANLOC        THE LOCATION IN UNLABELED COMMON FROM WHICH */
/*                            TO READ OR WRITE. IF LDAFLG = 3, THEN THE */
/*                            CANONICAL FORM IS READ INTO THE NEXT */
/*                            AVAILABLE LOCATION AND ITS CANON INDEX IS */
/*                            RETURNED IN CANLOC. */
/* SUBSIDIARIES MACHINE LANGUAGE SUBROUTINE        UNDEF */
/*              FORTRAN SUBROUTINE                 ERROR */

/* LOCAL VARIABLES */
/*              LDATOP        BCANON INDEX INDICATING THE STARTING */
/*                            POSITION FOR THE NEXT CANONICAL FORM TO */
/*                            BE READ INTO CORE. */
/*              LDACOR        ARRAY CONTAINING THE RECORD NUMBER AND */
/*                            BCANON INDEX OF EACH CANONICAL FORM */
/*                            CURRENTLY IN CORE. THE ORDER OF LDACOR */
/*                            ENTRIES CORRESPONDS TO THE RELATIVE */
/*                            POSITION OF THEIR ASSOCIATED FORMS IN */
/*                            BCANON. */
/*              CORTOP        LDACOR INDEX INDICATING RELATIVE POSITION */
/*                            OF FORM BEGINNING AT LDATOP IN BCANON. */
/*              NOLDAS        TOTAL NUMBER OF FORMS CURRENTLY IN CORE. */

/*              RECNUM        LAST RECORD NUMBER ASSIGNED TO A FORM. */
/*              KANIND        CANONICAL FORM INDEX IN BLANK COMMON */
/* NOTES        THE FIRST 40 POSITIONS OF UNLABELED COMMON ARE RESERVED */
/*              FOR NON LARGE DATA ARRAY CANONICAL FORMS OF SURFACES */
/*              USED IN A MOTION STATEMENT AND ARE REFERED TO BY */
/*              REFERENCING THE CANON ARRAY. THE REMAINING SPACE IS USED */
/*              FOR LARGE DATA ARRAY CANONICAL FORM STORAGE AND IS */
/*              REFERENCED BY REFERING TO THE BCANON ARRAY. MAXLDA */
/*              CONTAINS THE SIZE OF BCANON. */
/* IMPLIED ASSUMPTION.  IF LDAFLG=1 FOR WRITE, IT IS ASSUMED THAT */
/*         THE CANON FORM IS LOCATED IN CANON(41) ON, EVEN THOUGH */
/*         LARGE DATA IS PASSED AS AN ADDRESS. */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ...                SYSTEM I/O FILES */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   STORAGE ADDRESS FUNCTION */

/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */



/* ---       LOCAL VARIABLES */

/* ... SAVE LOCAL VARIABLES */

    /* Parameter adjustments */
    --canloc;
    --ldaary;

    /* Function Body */

/* ---      DETERMINE IF A READ, WRITE, OR AN UNDEFINITION. */
    lda[1] = (integer) ldaary[2];
    if (! ckdef_(&ldaary[1])) {
	lda[0] = (integer) ldaary[1];
    }
    switch (*ldaflg) {
	case 1:  goto L10;
	case 2:  goto L200;
	case 3:  goto L220;
	case 4:  goto L500;
	case 5:  goto L10;
	case 6:  goto L700;
	case 7:  goto L800;
    }
/* RETURN, WHEN WRONG LDAFLG */
    return 0;
/* ---      WRITE NEWLY CREATED CANONICAL FORM. */
/* ---      ASSIGN THE C.F. A RECORD NUMBER. */
L10:
    recnum = -5;
    tapop_(&symfil_1.axfile, &recnum);
    canloc[1] = (doublereal) recnum;
    lda[0] = recnum;
/* ---      WRITE THE CANONICAL FORM AND UPDATE THE DICTIONARY OF CANONICA */
/* ---      FORMS CURRENTLY IN MEMORY. */
    nr = 0;
/* ---      BRANCH TO ERROR IF LDA EXCEEDED SPACE AVAILABLE */
    if (lda[1] >= maxlda_1.maxlda) {
	goto L410;
    }
    if (*ldaflg == 5) {
	goto L12;
    }
    j = lda[1] << 1;
/* ---      COMPUTE R*8 FIELD INDEX OF CANONICAL FORM IN BLANK COMMON */
    kanind = (addrss_(&ldaary[1]) - addrss_(canon)) / 8 + 1;
/* ---      REPLACE ON EXTERNAL STORAGE RECORD NUMBER BY STORAGE INDEX */
    canloc[1] = (doublereal) kanind;
    awrite_(&symfil_1.axfile, &nr, &canloc[1], &j, &ir);
/* ---      RESTORE RECORD NUMBER */
    canloc[1] = (doublereal) lda[0];
    if (ir != 0) {
	goto L409;
    }
L12:
    ldatop = 1;
    cortop = 1;
/*  KONTROLLE OB DIE OBERFLAECHE AN DER VERMUTETEN STELLE LIEGT */
    for (i__ = 1; i__ <= 10; ++i__) {
	if (canloc[i__] != bcanon[i__ - 1]) {
	    goto L235;
	}
/* L11: */
    }
    goto L250;
/* ---      READ A CANONICAL FORM INTO A SPECIFIC LOCATION. */
/* ---      READ THE CANONICAL FORM AND RETURN TO CALLER. */
L200:
    j = lda[1] << 1;
    aread_(&symfil_1.axfile, lda, &canloc[1], &j, &ir);
    kanind = (integer) canloc[1];
    if ((d__1 = canon[kanind - 1] - ldaary[1], abs(d__1)) > .5f) {
	goto L1100;
    }
    canloc[1] = (doublereal) lda[0];
    goto L9999;

/* ---      READ A CANONICAL FORM INTO THE NEXT AVAILABLE AREA. */
/* ---      CHECK TO SEE IF CANONICAL FORM IS ALREADY IN CORE. */
L220:
    *aaa = canloc[1];
    if (noldas == 0) {
	goto L231;
    }
    i__1 = noldas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ldacor[(i__ << 1) - 2] != lda[0]) {
	    goto L230;
	}
	*jjj = ldacor[(i__ << 1) - 1] + 40;
	canloc[1] = *aaa;
	goto L9999;
L230:
	;
    }
L231:

/* ---      CANONICAL FORM IS NOT IN CORE,POSITION TAPE TO FORM RECORD */
/* ---      READ FORM INTO NEXT AVAILABLE LOCATION IN UNLABELED COMMON */
/* ---      CHECK IF FORM WILL FIT ABOVE LDATOP */
L235:
    if (maxlda_1.maxlda - ldatop < lda[1]) {
	goto L400;
    }

/* ---      FORM WILL FIT */
/* L240: */
    *jjj = ldatop + 40;
    canloc[1] = *aaa;
/*   LDACOR(2,MAXLDC) KANN UEBERSPEICHERT WERDEN */
    if (cortop >= maxldc) {
	goto L400;
    }
    j = lda[1] << 1;
    aread_(&symfil_1.axfile, lda, &bcanon[ldatop - 1], &j, &ir);
    kanind = (integer) bcanon[ldatop - 1];
    if ((d__1 = canon[kanind - 1] - ldaary[1], abs(d__1)) > .5f) {
	goto L1100;
    }
    bcanon[ldatop - 1] = (doublereal) lda[0];
    ++cortop;
L250:
    k = 0;

/* ---      CHECK IF NEW CORTOP LESS THAN NOLDAS */
    if (noldas - cortop >= 0) {
	goto L260;
    } else {
	goto L320;
    }
/* ---      DETERMINE THE NUMBER OF FORMS ABOVE LDATOP THAT WERE OVERLAID */
L260:
    i__1 = noldas;
    for (n = cortop; n <= i__1; ++n) {
	if (ldacor[(n << 1) - 1] >= ldatop + lda[1]) {
	    goto L280;
	}
/* L270: */
	++k;
    }
    goto L320;

/* ---      DETERMINE WHETHER LDACOR ENTRIES HAVE TO BE REPOSITIONED */
L280:
    if ((i__1 = k - 1) < 0) {
	goto L290;
    } else if (i__1 == 0) {
	goto L320;
    } else {
	goto L310;
    }

/* ---      SLIDE ENTRIES STARTING WITH CORTOP UP ONE POSITION */
L290:
    if (noldas < maxldc) {
	goto L291;
    }
    k = 1;
    goto L320;
L291:
    i__1 = noldas;
    for (i__ = cortop; i__ <= i__1; ++i__) {
	j = noldas + cortop - i__;
	ldacor[(j + 1 << 1) - 2] = ldacor[(j << 1) - 2];
/* L300: */
	ldacor[(j + 1 << 1) - 1] = ldacor[(j << 1) - 1];
    }
    goto L320;

/* ---      SLIDE GOOD ENTRIES ABOVE CORTOP + 1 DOWN SO THAT THE FIRST GOO */
/* ---      ENTRY COINCIDES WITH CORTOP + 1 */
L310:
    i__1 = noldas;
    for (i__ = n; i__ <= i__1; ++i__) {
	j = cortop + 1 - n + i__;
	ldacor[(j << 1) - 2] = ldacor[(i__ << 1) - 2];
/* L315: */
	ldacor[(j << 1) - 1] = ldacor[(i__ << 1) - 1];
    }

/* ---      INSERT NEW ENTRY IN LDACOR, ADJUST LDATOP AND NOLDAS */
L320:
    ldacor[(cortop << 1) - 2] = lda[0];
    ldacor[(cortop << 1) - 1] = ldatop;
    ldatop += lda[1];
    noldas = noldas - k + 1;
    goto L9999;
/* ---      FORM WILL NOT FIT ABOVE LDATOP. READ IT IN STARTING AT BCANON( */

L400:
    if (maxlda_1.maxlda >= lda[1]) {
	goto L401;
    }

/* NOT ENOUGH ROOM IN >LDA< */
L410:
    error_(&c__5061, "APT094  ", (ftnlen)8);
    goto L500;
/* NOT ENOUGH ROOM ON FILE 9(EXTERNAL LDA) */
L409:
    error_(&c__5062, "APT094  ", (ftnlen)8);
    ldatop = 1;
    cortop = 1;
    noldas = 0;
    goto L510;
L401:
    *jjj = 41;
    canloc[1] = *aaa;
/* L402: */
    j = lda[1] << 1;
    aread_(&symfil_1.axfile, lda, bcanon, &j, &ir);
    kanind = (integer) bcanon[0];
    if ((d__1 = canon[kanind - 1] - ldaary[1], abs(d__1)) > .5f) {
	goto L1100;
    }
    bcanon[0] = (doublereal) lda[0];
    ldatop = 1;
    cortop = 1;
    goto L250;

/* ---      DEFINITION ERROR : ELIMINATE LDA FROM LIST */

L500:
    if (noldas == 0) {
	goto L510;
    }
    i__1 = noldas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ldacor[(i__ << 1) - 2] == lda[0]) {
	    goto L506;
	}
/* L503: */
    }
    goto L510;
L506:
    if (i__ <= cortop) {
	--cortop;
    }
    --noldas;
    if (noldas == 0) {
	goto L510;
    }
    if (noldas < i__) {
	goto L510;
    }
    i__1 = noldas;
    for (n = i__; n <= i__1; ++n) {
	ldacor[(n << 1) - 2] = ldacor[(n + 1 << 1) - 2];
/* L508: */
	ldacor[(n << 1) - 1] = ldacor[(n + 1 << 1) - 1];
    }
L510:
    undef_(&ldaary[1]);
    goto L9998;
/* ERROR DURING READ OF A LARGE DATA ARRAY >LDA< FROM FILE 9. */
/* ---      RECORD NUMBER ERROR */
/* ---      PRINT ERROR MESSAGE ON VLFILE AND UNDEFINE THE CANONICAL FORM. */
L1100:
    error_(&c__5060, "APT094  ", (ftnlen)8);
    goto L500;
L9999:
    ldaary[1] = (doublereal) lda[0];
/* . */
L9998:
    return 0;
/*  UPDATE IN PLACE */
L700:
    if (noldas == 0) {
	goto L730;
    }
    i__1 = noldas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ldacor[(i__ << 1) - 2] == lda[0]) {
	    goto L720;
	}
/* L710: */
    }
    goto L730;
/*   GEOMETRIE IN CORE */
L720:
    n = lda[1];
    nn = ldacor[(i__ << 1) - 1];
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	bcanon[nn - 1] = canloc[i__];
/* L725: */
	++nn;
    }
/*  WRITE UPDATE */
L730:
    j = lda[1] << 1;
    nr = lda[0];
/* ---      COMPUTE R*8 FIELD INDEX OF CANONICAL FORM IN BLANK COMMON */
    kanind = (addrss_(&ldaary[1]) - addrss_(canon)) / 8 + 1;
/* ---      REPLACE ON EXTERNAL STORAGE RECORD NUMBER BY STORAGE INDEX */
    canloc[1] = (doublereal) kanind;
    awrite_(&symfil_1.axfile, &nr, &canloc[1], &j, &ir);
/* ---      RESTORE RECORD NUMBER */
    canloc[1] = (doublereal) lda[0];
    return 0;
/* ---      READ SHORT */
L800:
    j = 2;
    aread_(&symfil_1.axfile, lda, &canloc[1], &j, &ir);
    kanind = (integer) canloc[1];
    return 0;
} /* apt094_ */

#undef bcanon
#undef sscan
#undef canon
#undef jjj
#undef can
#undef aaa


