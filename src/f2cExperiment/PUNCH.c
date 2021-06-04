/* PUNCH.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__14 = 14;
static integer c__6 = 6;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c__85 = 85;
static integer c__3 = 3;
static integer c__80 = 80;
static integer c__20 = 20;
static integer c__4 = 4;
static integer c__28 = 28;
static integer c__29 = 29;
static integer c__35 = 35;
static integer c__23 = 23;
static integer c__43 = 43;
static integer c__0 = 0;
static integer c__42 = 42;
static integer c__48 = 48;
static integer c__86 = 86;
static integer c__2 = 2;
static integer c__15 = 15;
static integer c__64 = 64;
static integer c__19 = 19;
static integer c_n19 = -19;
static integer c__10 = 10;

/* *** SOURCE FILE : M0001210.W01   *** */

/* .....FORTRAN SUBROUTINE   ...PUNCH         8/68           SR,KH */

/*                                                10/70     RW */

/* PURPOSE          TO WRITE A SPECIFIED NUMBER OF CONTIGUOUS CANONICAL */
/*                  FORMS,STARTING WITH A GIVEN CANONICAL FORM,ON THE */
/*                  SYSTEM PUNCH OUTPUT FILE AS APT DEFINITION */
/*                  STSTEMENTS WHICH CAN BE INCLUDED IN SUBSEQUENT PART */
/*                  PROGRAMS. SCALARS ARE WRITTEN INTHE FORM--- */
/*                      VSCALAR VARIABLE = NUMBER. */
/*                  SURFACE DATA IS WRITTEN IN THE FORM--- */
/*                       SURFACE VARIABLE = SURFACE TYPE/CANON,ELEMENT1, */
/*                       ELEMENT2,...,ELEMENTN. */

/* CALLING SEQUENCE CALL PUNCH(BLOCK,FORM,NUMBER) */

/* ARGUMENTS        BLOCK            NUMBER OF THE CANONICAL FORM BLOCK */
/*                                   CONTAINING THE FORMS TO BE PUNCHED. */
/*                                   (BLOCK 1 CONTAINS UNSUBSCRIPTED */
/*                                    SCALARS,BLOCK 2 CONTAINS */
/*                                    SUBSCRIPTED SCALARS,BLOCK 3 */
/*                                    CONTAINS SURFACE CANONICAL FORMS) */
/*                  FORM             FIRST CANONICAL FORM TO BE PUNCHED. */
/*                  NUMBER           NUMBER OF CONTIGUOUS FORMS TO BE */
/*                                   PUNCHED. */

/* CALLED BY        NONE */

/* SUBSIDIARIES     TYPE             ENTRY */
/*                  ----             ----- */

/*                  INTEGER FUNCTION ADDRSS */
/*                  SUBROUTINE       APT094 */
/*                  SUBROUTINE       INCAN */
/*                  SUBROUTINE       TRANSF */
/*                  SUBROUTINE       UNPACK */
/*                  INTEGER FUNCTION XCANON */

/* RESTRICTIONS     IF THERE IS MORE THAN ONE FORM TO BE PUNCHED,ALL */
/*                  FORMS MUST LIE IN THE SAME BLOCK AND BE CONTIGUOUS. */
/*                  THE PUNCHING OF TEMPORIES IS SUPPRESSED. */

/* DIAGNOSTICS      ERROR CODE       COMMENT */
/*                  ----------       ------- */

/*                  NONE             X WAS INCORRECTLY DEFINED AND */
/*                                   WAS NOT PUNCHED. */


/* METHOD           A COMPUTED GO TO ON BLOCK IS EXECUTED TO BRANCH TO */
/*                  THE PROCESSING APPROPRIATE TO THE BLOCK CONTAINING */
/*                  THE CANONICAL FORMS TO BE PUNCHED.THE VALUE OF NUMBER */
/*                  SPECIFIES HOW MANY FORMS ARE TO BE PUNCHED.EACH FORM */
/*                  IS CHECKED TO DETERMINE IF IT IS UNDEFINED OR A */
/*                  TEMPORARY. IF IT IS UNDEFINED,A DIAGNOSTIC IS ISSUED. */
/*                  IF IT IS UNDEFINED OR A TEMPORARY,PUNCHING IS */
/*                  SUPPRESSED.IN THE CASE OF BLOCK 3 AN ADDITIONAL */
/*                  CHECK IS MADE TO SEE IF THE FORM IS A LARGE DATA */
/*                  ARRAY. IF SO,APT094 IS CALLED TO RETRIEVE THE */
/*                  EXTERNAL FORM. */
/*                       THE FORMS ARE OUTPUT TO THE SYSTEM PUNCH FILE AS */
/*                  APT PART PROGRAMMING DEFINITIONS IN THE FORMATS */
/*                  DESCRIBED UNDER PURPOSE.EACH CARD IMAGE IS SERIALIZED */
/*                  STARTING WITH SERIALIZATION 00000001 AND INCREASING */
/*                  BY 1 FOR SUBSEQUENT CARD IMAGES. */

/* ******************************************************************** */

/* Subroutine */ int punch_(integer *block, doublereal *form, integer *number)
{
    /* Initialized data */

    static logical ldasrf = FALSE_;
    static integer modtop = 5;
    static integer ldamod[5] = { 11,12,26,29,30 };
    static integer cnt = 0;
    static char lparen[1] = "(";
    static char rparen[1] = ")";
    static char inout[4*2] = "  IN" " OUT";
    static char buck[1] = "$";
    static char cma[1] = ",";
    static char z__[1] = "Z";
    static char type__[6*30] = "LINE  " "PLANE " "CYLNDR" "CIRCLE" "SPHERE" 
	    "HYPERB" "LCONIC" "ELLIPS" "CONE  " "GCONIC" "TABCYL" "RLDSRF" 
	    "POLCON" "QADRIC" "PARSRF" "      " "      " "MATRIX" "POINT " 
	    "VECTOR" "      " "      " "      " "      " "      " "PATERN" 
	    "BOUNDS" "OBJECT" "SSURF " "SCURV ";
    static struct {
	char e_1[8];
	} equiv_8 = { "        " };


    /* System generated locals */
    integer i__1, i__2;
    static char equiv_6[4], equiv_7[16];
    static doublereal equiv_9[1];
    static char equiv_10[8];
    static doublereal equiv_11[1], equiv_12[10];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define a (equiv_9)
    static integer d__, i__, j, k, l, m, n;
#define x ((doublereal *)&_BLNK__1)
    static integer i1;
#define ia ((integer *)equiv_9)
    static integer iu[8];
#define no (equiv_6)
#define ii ((integer *)equiv_11)
    static integer jj, kk, ir, ik, mm, jk;
    static doublereal xx;
    static integer bcd;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ila;
#define blk ((char *)&equiv_8)
#define buf (equiv_7)
    static integer jjj, nwd, sub;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int date_(doublereal *);
    static integer iabs;
    static doublereal name__;
    static integer mode, ilen;
    static char lmem[8];
    static integer incr;
#define numb (equiv_6 + 3)
    static integer isub, iret, size;
    static doublereal rsub;
    static integer ipos, iuvw;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
#define blank ((char *)&equiv_8)
    extern /* Subroutine */ int incan_(integer *);
    static char lname[8];
#define canon ((doublereal *)&_BLNK__1)
    static integer iblnk[2];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern logical ckdtr_(doublereal *);
    static doublereal datum;
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
#define array (equiv_12)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define dtest (equiv_10)
    extern logical ckstr_(doublereal *);
#define ltest (equiv_10)
    static logical bndpch;
#define canloc (equiv_11)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static logical namflg;
    static doublereal member;
#define buffer (equiv_7)
    extern integer addrss_(doublereal *);
    extern /* Subroutine */ int cpunch_(char *, logical *, ftnlen);
    extern integer xcanon_(integer *);
    static doublereal refsrf[12];
#define iarray ((integer *)equiv_12)
    extern /* Subroutine */ int holfrm_(), cprint_(char *, ftnlen);
#define twochr (equiv_10)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), transf_(doublereal *, doublereal *, integer *, 
	    integer *, integer *);
    static integer ihsmod, intcds;
    extern /* Subroutine */ int wtdire_(integer *, doublereal *, doublereal *,
	     integer *, integer *), clospe_(integer *, integer *);
    static char outlst[8*16];
    extern /* Subroutine */ int wtsatz_(integer *, doublereal *, integer *, 
	    integer *);


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */








/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...  LOCAL VARIABLES */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --form;

    /* Function Body */

/* ...  CNVRT IS AN ARITHMETIC FUNCTION THAT CONVERTS AN INTEGER TO A */
/*     LEFT-JUSTIFIED 2-DIGIT REPRESENTATION WITH LEADING ZEROS. */

/* .... SET UP EQUIVALENT OF 8 BLANK CHARACTERS IN D.P.WORD */
    iblnk[0] = bcdf_("    ", (ftnlen)4);
    iblnk[1] = iblnk[0];

/* ... DETERMINE VIRTUAL INDEX OF FORM(1) IN X-ARRAY. */

    i__ = (addrss_(&form[1]) - addrss_(x)) / idef_1.kwrdsz + 1;
    iabs = i__;
    if (ldef_1.canflg) {
	incan_(&i__);
    }
    namflg = FALSE_;

/* ... BRANCH TO APPROPRIATE PROCESSING FOR SPECIFIED BLOCK. */


    switch (*block) {
	case 1:  goto L10;
	case 2:  goto L1000;
	case 3:  goto L2000;
	case 4:  goto L1999;
	case 5:  goto L1999;
    }

/*                  B L O C K   O N E */

L10:
    n = 1;
L50:
    cnt = 100;

/* ... DETERMINE ABSOLUTE INDEX. */

    goto L3150;

/* ... SET K = INDEX OF NEXT SCALAR NAME */

L15:
    k = iabs + 1;

/* ... CHECK IF FORM IS A TEMPORARY OR UNDEFINED */

    goto L3000;

/* ... WRITE SCALAR DEFINITION */

L20:
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("=", darray_1.darray, &c__21, &c__1, (ftnlen)1, (ftnlen)120);
    fconv_(&x[iabs - 1], darray_1.darray, &c__22, &c__14, &c__6, (ftnlen)120);
    iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }
L40:
    i__ += 2;
    iabs += 2;
    ++n;
    if (n <= *number) {
	goto L50;
    }
    return 0;

/*                  B L O C K   T W O */

L1000:
    size = 1;
    n = 1;
L1040:

/* ... DETERMINE ABSOLUTE INDEX. */

    goto L3150;

/* ... SET SUB = NEXT SUBSCRIPT. SET K = INDEX OF NEXT SCALAR NAME. */

L1005:
    sub = (integer) x[iabs];
    cnt = 0;

    goto L2007;

/* ... WRITE SCALAR DEFINITION */

L1010:
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("(    ) =", darray_1.darray, &c__20, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&sub, darray_1.darray, &c__21, &c__4, (ftnlen)120);
    fconv_(&x[iabs - 1], darray_1.darray, &c__28, &c__14, &c__6, (ftnlen)120);
    iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }

/* ... ADVANCE CURRENT CANONICAL FORM INDEX */

L1030:
/* Computing MIN */
    i__1 = 1, i__2 = sub - 1;
    d__ = 3 - min(i__1,i__2);
    i__ += d__;
    iabs += d__;
    ++n;
    if (n <= *number) {
	goto L1040;
    }
    return 0;

/*                  B L O C K   T H R E E */

/*     VORBEREITUNG FUER MEMBERAUSGABE */
L1999:
    date_(&datum);


L2000:
    bndpch = FALSE_;
    n = 1;
L2005:
    cnt = 100;

/* ... DETERMINE ABSOLUTE INDEX. */
    goto L3150;

/* ... GET MODE,SIZE AND SUBSCRIPT OF NEXT CANONICAL FORM */
/*     AND CHECK VALIDITY. */

L2006:
    unpack_(&x[iabs - 1], &mode, &size, &sub);
    if (mode <= 0 || mode > 30 || size <= 0 || size > 50) {
	goto L3200;
    }

/* ... BYPASS IF THIS FORM HAS ALREADY BEEN PUNCHED. */

    if (x[iabs - 2] > 0.) {
	goto L2007;
    }
    if (sub <= 1) {
	namflg = FALSE_;
    }
    goto L2110;

/* ... FIND ALPHANUMERIC NAME. */

L2007:
    if (sub < 0 || sub > 9999) {
	goto L3200;
    }
    if (sub > 1) {
	goto L3170;
    }
    namflg = FALSE_;
    k = iabs + size + 1 - *block / 3;
L2008:
    if (*block == 2) {
	goto L3000;
    }
    x[iabs - 2] = -x[iabs - 2];

/* ... SET II = INDEX OF FIRST ELEMENT IN CURRENT CANONICAL FORM */

    *ii = 1;

/* ...  SKIP PUNCHING IF PARAMETRIC SURFACE OR NO SURFACE */

    if (mode == 15 || mode > 20 && mode < 26) {
	goto L2110;
    }

/* ...  CHECK IF FORM IS TEMPORARY OR UNDEFINED */

    goto L3000;

/* ... IF THE CANONICAL FORM IS A LARGE DATA ARRAY,RETRIEVE THE EXTERNAL */
/* ... FORMAND SET LDASRF = .TRUE.  RESET SIZE TO THE SIZE OF THE EXTERNAL */
/* ... FORM. RESET II TO THE RELATIVE POSITION IN BLANK COMMON OF THE */
/* ... FIRST ELEMENT OF THE EXTERNAL FORM */

L2020:
    ldasrf = FALSE_;
    i__1 = modtop;
    for (j = 1; j <= i__1; ++j) {
	if (mode != ldamod[j - 1]) {
	    goto L2010;
	}
	apt094_(&c__3, &x[iabs - 1], canloc);
	size = (integer) (x[iabs] + *ii - 2);
	ldasrf = TRUE_;
L2010:
	;
    }
    goto L2015;

/* ... WRITE FIRST DEFINITION CARD FOR SUBSCRIPTED SURFACE NAME. */

L2012:
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("(    ) =", darray_1.darray, &c__20, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&sub, darray_1.darray, &c__21, &c__4, (ftnlen)120);
    cform_(type__ + (mode - 1) * 6, darray_1.darray, &c__29, &c__6, (ftnlen)6,
	     (ftnlen)120);
    cform_("/CANON,$", darray_1.darray, &c__35, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }
    goto L2045;

/* ... SPECIAL PROCESSING IS REQUIRED FOR BOUNDS OR OBJECT CANON FORMS. */

L2015:
    if (*block >= 4) {
	goto L5000;
    }
    if (mode == 27 || mode == 28) {
	goto L4000;
    }

/* ... WRITE FIRST DEFINITION CARD */

    if (sub != 0) {
	goto L2012;
    }
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("=", darray_1.darray, &c__21, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(type__ + (mode - 1) * 6, darray_1.darray, &c__23, &c__6, (ftnlen)6,
	     (ftnlen)120);
    cform_("/CANON,$", darray_1.darray, &c__29, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }

/* ... IF LDASRF = FALSE, PUT C.F. INTO REFSRF AND CHK FOR REFSYS. */

L2045:
    if (! ldasrf) {
	goto L3050;
    }

L2050:
    ++cnt;
    l = 14;
    for (jj = 1; jj <= 4; ++jj) {
	if (ldasrf) {
	    xx = x[*ii];
	}
	if (! ldasrf) {
	    xx = refsrf[*ii - 1];
	}
	fconv_(&xx, darray_1.darray, &l, &c__14, &c__6, (ftnlen)120);
	l += 14;
	++(*ii);
	if (*ii > size) {
	    goto L2060;
	}
	cform_(",", darray_1.darray, &l, &c__1, (ftnlen)1, (ftnlen)120);
/* L2055: */
	++l;
    }
    cform_("$", darray_1.darray, &l, &c__1, (ftnlen)1, (ftnlen)120);
L2060:
    iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }
    if (*ii <= size) {
	goto L2050;
    }

/* ... IF SURFACE IS A LARGE DATA ARRAY, RESET SIZE = 2 */

L2110:
    if (! ldasrf) {
	goto L2115;
    }
    size = 2;
    ldasrf = FALSE_;

/* ...  IF IN SUBSIDIARY BOUNDS PUNCH MODE, RETURN TO BOUNDS PROCESSING. */

L2115:
    if (bndpch) {
	goto L4260;
    }

/* ... ADVANCE CURRENT CANONICAL FORM INDEX */

L2120:
/* Computing MIN */
    i__1 = sub / 2;
    d__ = size + 2 - min(i__1,1);
    i__ += d__;
    iabs += d__;
    ++n;
    if (n <= *number) {
	goto L2005;
    }
    return 0;

/* ... C H E C K   I F    T E M P   O R   U N D E F I N E D. */

L2970:
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    l = 21;
    if (sub == 0) {
	goto L2971;
    }
    cform_("(    )", darray_1.darray, &c__20, &c__6, (ftnlen)6, (ftnlen)120);
    iconv_(&sub, darray_1.darray, &c__21, &c__4, (ftnlen)120);
    l = 27;
L2971:
    cform_("IS INCORRECTLY DEFINED AND WAS NOT PUNCHED.               ", 
	    darray_1.darray, &l, &c__43, (ftnlen)58, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L2980:
    switch (*block) {
	case 1:  goto L40;
	case 2:  goto L1030;
	case 3:  goto L2110;
	case 4:  goto L2110;
	case 5:  goto L2110;
    }

/* ... IF THE FORM IS UNDEFINED OR A TEMPORARY,SUPPRESS PUNCHING IT */

L3000:
    if (ckdtr_(&x[iabs - 1])) {
	goto L2980;
    }
    holfrm_(&x[k - 1], dtest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (*(unsigned char *)&ltest[0] == *(unsigned char *)&buck[0] || *(
	    unsigned char *)&ltest[1] == *(unsigned char *)&buck[0] && *(
	    unsigned char *)&ltest[0] == *(unsigned char *)&z__[0]) {
	goto L2980;
    }

/* ... IF FORM INCORRECTLY DEFINED, WRITE A DIAGNOSTIC. */

    if (ckstr_(&x[iabs - 1])) {
	goto L2970;
    }


/* ... ADVANCE CARD SERIALIZATION */

    ++cnt;
    switch (*block) {
	case 1:  goto L20;
	case 2:  goto L1010;
	case 3:  goto L2020;
	case 4:  goto L2020;
	case 5:  goto L2020;
    }

/* ... REFSYS TEST. */

L3050:
    i__1 = size;
    for (j = 1; j <= i__1; ++j) {
	kk = iabs + j - 1;
/* L3060: */
	refsrf[j - 1] = x[kk - 1];
    }
    if (! ldef_1.refflg || mode <= 0 || mode > 20) {
	goto L2050;
    }
    switch (mode) {
	case 1:  goto L3070;
	case 2:  goto L3070;
	case 3:  goto L3080;
	case 4:  goto L3080;
	case 5:  goto L3090;
	case 6:  goto L3100;
	case 7:  goto L3100;
	case 8:  goto L3100;
	case 9:  goto L3080;
	case 10:  goto L3100;
	case 11:  goto L2050;
	case 12:  goto L2050;
	case 13:  goto L2050;
	case 14:  goto L3100;
	case 15:  goto L2050;
	case 16:  goto L2050;
	case 17:  goto L2050;
	case 18:  goto L2050;
	case 19:  goto L3090;
	case 20:  goto L3110;
    }
L3070:
    ir = 4;
    goto L3120;
L3080:
    ir = 5;
    goto L3120;
L3090:
    ir = 2;
    goto L3120;
L3100:
    ir = 1;
    goto L3120;
L3110:
    ir = 3;
L3120:
    transf_(refsrf, &x[iabs - 1], &ir, &size, &c__0);
    goto L2050;

/* ... DETERMINE ABSOLUTE INDEX. */

L3150:
    *a = x[iabs - *block / 3 - 1];
    if (*ia <= 0 || *ia > 1024) {
	goto L3160;
    }
    i__ += *ia;
    iabs = i__;
    if (ldef_1.canflg) {
	iabs = xcanon_(&i__);
    }
    goto L3150;
L3160:
    switch (*block) {
	case 1:  goto L15;
	case 2:  goto L1005;
	case 3:  goto L2006;
	case 4:  goto L2006;
	case 5:  goto L2006;
    }

/* ... DETERMINE ABSOLUTE LOCATION OF FORM NAME. */

L3170:
    if (! namflg) {
	goto L3175;
    }
    if (ldef_1.canflg) {
	k = xcanon_(&ik);
    }
    goto L3195;

L3175:
    namflg = TRUE_;
    incr = size + 1 - *block / 3;
    k = iabs + incr;
    ik = i__ + incr;
    i__1 = sub;
    for (mm = 2; mm <= i__1; ++mm) {
L3178:
	*a = x[k - 1];
	if (*ia <= 0 || *ia > 1024) {
	    goto L3180;
	}
	ik += *ia;
	k = ik;
	if (ldef_1.canflg) {
	    k = xcanon_(&ik);
	}
	goto L3178;
L3180:
	k = k + size + 1;
	ik = ik + size + 1;
/* L3190: */
    }
L3195:
    if (ldef_1.canflg) {
	iabs = xcanon_(&i__);
    }
    goto L2008;

/* ... IF CANONICAL FORM IS INVALID, PRINT DIAGNOSTIC AND RETURN. */

L3200:
    cform_("INVALID CANONICAL FORM PUNCHING SUPPRESSED                  ", 
	    darray_1.darray, &c__14, &c__42, (ftnlen)60, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;

/* ...  PROCESSING FOR BOUNDS AND OBJECTS */

L4000:
    if (bndpch) {
	goto L4260;
    }
    jk = size + 16;
    if (mode == 27) {
	goto L4050;
    }

/* ... P U N C H   O B J E C T   C A R D */

    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("=OBJECT/", darray_1.darray, &c__20, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    m = 101;
    j = -2;
L4004:
    l = 28;
L4005:
    j += 2;
    holfrm_(&x[iabs + j - 1], dtest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (*(unsigned char *)&ltest[0] == *(unsigned char *)&buck[0] || ckstr_(&
	    x[iabs + j - 1])) {
	goto L2970;
    }
    cform_(dtest, darray_1.darray, &l, &c__6, (ftnlen)8, (ftnlen)120);
    i__1 = l + 6;
    cform_(",", darray_1.darray, &i__1, &c__1, (ftnlen)1, (ftnlen)120);
    if (j == size - 2) {
	goto L4010;
    }
    l += 7;
    if (l < 73) {
	goto L4005;
    }
    cform_("$", darray_1.darray, &l, &c__1, (ftnlen)1, (ftnlen)120);
L4006:
    iconv_(&m, darray_1.darray, &c__85, &c__3, (ftnlen)120);
    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    ++m;
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }
    if (j == size - 2) {
	goto L4011;
    }
    goto L4004;
L4010:
    i__1 = l + 6;
    cform_(" ", darray_1.darray, &i__1, &c__1, (ftnlen)1, (ftnlen)120);
    goto L4006;
L4011:
    goto L2120;

/* ... P U N C H   B O U N D S   C A R D S */

L4050:
    for (jj = 1; jj <= 66; ++jj) {
/* L4051: */
	s_copy(outlst + (jj - 1 << 3), blank, (ftnlen)8, (ftnlen)8);
    }
    i__1 = size;
    for (jj = 2; jj <= i__1; jj += 2) {

/* ... CHECK FOR INVALID OR UNASSIGNED NESTED ARGUMENTS. */

	holfrm_(&x[iabs + jj - 3], buffer, &c__1, &c__8, &nwd, (ftnlen)8);
	if (*(unsigned char *)&buf[0] == *(unsigned char *)&buck[0] || ckstr_(
		&x[iabs + jj - 3])) {
	    goto L2970;
	}

/* ... DETERMINE INDEX,SUBSCRIPT, AND HALF-SPACE MODIFIER FOR EA. OPERAND. */

	j = jj / 2;
	s_copy(buffer + 8, blank, (ftnlen)8, (ftnlen)8);
	iuvw = (integer) x[iabs + jj - 2];
	iu[j - 1] = iuvw / knumbr_1.k1e4;
	isub = (iuvw - iu[j - 1] * knumbr_1.k1e4) / knumbr_1.k10;
	ihsmod = iuvw - iu[j - 1] * knumbr_1.k1e4 - isub * knumbr_1.k10;

/* ...  IF REFERENCED SURFACE IS SUBSCRIPTED, CONVERT SUBSCRIPT TO ALPHA- */
/*     NUMERIC FORM AND LEFT-JUSTIFY IT NEXT TO THE NAME. */

	for (m = 3; m <= 8; ++m) {
	    if (*(unsigned char *)&buf[m - 2] == *(unsigned char *)blk) {
		goto L4070;
	    }
/* L4060: */
	}
L4070:
	if (isub == 0) {
	    goto L4110;
	}
	*(unsigned char *)&buf[m - 2] = *(unsigned char *)&lparen[0];
	for (kk = 1; kk <= 3; ++kk) {
	    l = 4 - kk;
	    bcd = isub % 10;
	    holfrm_(&bcd, no, &c__1, &c__4, &nwd, (ftnlen)4);
	    *(unsigned char *)&ltest[l - 1] = *(unsigned char *)numb;
	    isub /= knumbr_1.k10;
	    if (isub == 0) {
		goto L4090;
	    }
/* L4080: */
	}
L4090:
	for (kk = l; kk <= 4; ++kk) {
	    *(unsigned char *)&buf[m - 1] = *(unsigned char *)&ltest[kk - 1];
/* L4100: */
	    ++m;
	}
	*(unsigned char *)&buf[m - 2] = *(unsigned char *)&rparen[0];
L4110:
	*(unsigned char *)&buf[m - 1] = *(unsigned char *)&cma[0];

/* ...  SUPPRESS HSMOD AND COMMA IF PRIMARY SURFACE. */

	if (j == 1) {
	    goto L4125;
	}
	if (ihsmod == 1 || ihsmod == 2) {
	    goto L4112;
	}
	bcd = ihsmod;
	holfrm_(&bcd, no, &c__1, &c__4, &nwd, (ftnlen)4);
	goto L4116;
L4112:
	s_copy(no, inout + (ihsmod - 1 << 2), (ftnlen)4, (ftnlen)4);
	*(unsigned char *)&buf[m] = *(unsigned char *)&no[1];
	*(unsigned char *)&buf[m + 1] = *(unsigned char *)&no[2];
L4116:
	*(unsigned char *)&buf[m + 2] = *(unsigned char *)numb;

/* ...  SUPPRESS FINAL COMMA IF LAST BOUNDING SURFACE. */

	if (jj == size) {
	    goto L4125;
	}
	*(unsigned char *)&buf[m + 3] = *(unsigned char *)&cma[0];

/* ...  WILL NEED SECOND CARD IF MORE THAN TWO BOUNDING SURFACES, AND */
/*     THIRD CARD IF MORE THAN SIX SURFACES, ETC. */
	jk = jj - 6;
	if (jk - (jk / 8 << 3) == 0) {
	    *(unsigned char *)&buf[m + 3] = *(unsigned char *)&buck[0];
	}

L4125:
	s_copy(outlst + (jj - 2 << 3), buffer, (ftnlen)8, (ftnlen)8);
/* L4130: */
	s_copy(outlst + (jj - 1 << 3), buffer + 8, (ftnlen)8, (ftnlen)8);
    }

/* ...  PUNCH FIRST CARD. */

    holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
    cform_(lname, darray_1.darray, &c__14, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("=BOUNDS/", darray_1.darray, &c__20, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    cform_(outlst, darray_1.darray, &c__28, &c__48, (ftnlen)8, (ftnlen)120);
    cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
    cform_("01", darray_1.darray, &c__86, &c__2, (ftnlen)2, (ftnlen)120);
    cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
    if (ldef_1.pchlst) {
	cprint_(darray_1.darray, (ftnlen)120);
    }
    if (size <= 6) {
	goto L4250;
    }

/* ...  PUNCH INTERMEDIATE CARDS. */

    intcds = size / 8;
    cnt = 101;
    jk = -1;
    i__1 = intcds;
    for (jj = 1; jj <= i__1; ++jj) {
	jk += 8;
	++cnt;
	cform_(",", darray_1.darray, &c__14, &c__1, (ftnlen)1, (ftnlen)120);
	cform_(outlst + (jk - 1 << 3), darray_1.darray, &c__15, &c__64, (
		ftnlen)8, (ftnlen)120);
	iconv_(&cnt, darray_1.darray, &c__85, &c__3, (ftnlen)120);
	holfrm_(&x[k - 1], lname, &c__1, &c__8, &nwd, (ftnlen)8);
	cform_(lname, darray_1.darray, &c__80, &c__6, (ftnlen)8, (ftnlen)120);
	cpunch_(darray_1.darray + 8, &ldef_1.pchlst, (ftnlen)80);
	if (ldef_1.pchlst) {
	    cprint_(darray_1.darray, (ftnlen)120);
	}
/* L4170: */
    }

/* ...  P U N C H   C A R D S   F O R   B O U N D I N G   S U R F A C E S */

/* ... BYPASS IF PUNCH/ALL OR PUNCH/GEOM IS SPECIFIED. */

L4250:
    if (*number > 1) {
	goto L2120;
    }

/* ...  SET FLAG FOR SUBSIDIARY BOUNDS PUNCHING MODE AND PUNCH CARD(S). */

    bndpch = TRUE_;

    jjj = size / 2;
    i__1 = jjj;
    for (jk = 1; jk <= i__1; ++jk) {
	i__ = iu[jk - 1] + idef_1.iblk1;
	iabs = i__;
	if (ldef_1.canflg) {
	    i__2 = i__ - 1;
	    iabs = xcanon_(&i__2) + 1;
	}
	namflg = FALSE_;
	goto L2005;
L4260:
	;
    }
    return 0;
/*    MEMBER-AUSGABE AUF PDS */
L5000:
    array[0] = x[k - 1];
    member = x[k - 1];
    holfrm_(&member, lmem, &c__1, &c__8, &nwd, (ftnlen)8);
    rsub = 0.;
    if (sub == 0) {
	goto L5004;
    }
    rsub = (doublereal) sub;
    name__ = x[k - 1];
    holfrm_(&name__, lname, &c__1, &c__8, &nwd, (ftnlen)8);
    i__1 = sub + 10000000;
    iconv_(&i__1, lmem, &c__1, &c__8, (ftnlen)8);
    for (i1 = 1; i1 <= 8; ++i1) {
	if (*(unsigned char *)&lname[i1 - 1] == *(unsigned char *)blk) {
	    goto L5004;
	}
/* L5001: */
	*(unsigned char *)&lmem[i1 - 1] = *(unsigned char *)&lname[i1 - 1];
    }
/* INDEX */
L5004:
    array[1] = rsub;
/* OBERFLAECHENART */
    iarray[4] = mode;
/* KENNUNG FUER GROSSFLAECHEN */
    iarray[5] = 5;
/* ANZAHL DER CANON-ELEMENTE */
    iarray[6] = 0;
    ila = (integer) x[iabs];
    iarray[7] = ila;
    array[4] = 0.;
/* *** VAX VERSION - OPEN FILE ON APTLIB BEFORE WRITE   *** */
/* *** PUNCH/RANDOM (BLOCK=5) GEOMETRY ALWAYS STORED    *** */
/* *** PUNCH/RETAIN (BLOCK=4) ONLY NEW GEOMETRY STORED  *** */
    wtdire_(&c__19, &member, &datum, &c__8, &iret);
    if (iret == 9 && *block == 4) {
	wtdire_(&c_n19, &member, &datum, &c__8, &iret);
    }
    if (iret != 0) {
	goto L5020;
    }
    jj = 6;
    i__1 = size;
    for (jjj = *ii; jjj <= i__1; ++jjj) {
	array[jj - 1] = x[jjj];
	if (jjj == size) {
	    goto L5005;
	}
	++jj;
	if (jj <= 9) {
	    goto L5010;
	}
L5005:
	++cnt;
	array[9] = (doublereal) cnt;
	wtsatz_(&c__19, array, &c__10, &iret);
	for (i__ = 1; i__ <= 10; ++i__) {
	    array[i__ - 1] = 0.;
/* L5006: */
	}
	jj = 1;
	if (iret != 0) {
	    goto L5020;
	}
L5010:
	;
    }
/*    ABSCHLUSS */
/*  *** VAX VERSION - WTDIRE OPENS FILE IN APTLIB    *** */
/*  ***               NEEDS TO BE DONE BEFORE WRITE  *** */
/*      CALL WTDIRE(19,MEMBER,DATUM,8,IRET) */
/*      IF(IRET.EQ.9.AND.BLOCK.EQ.4) */
/*     /CALL WTDIRE(-19,MEMBER,DATUM,8,IRET) */
    if (iret == 0) {
	goto L5040;
    }
L5020:
    ilen = 0;
    if (iret == 3) {
	cform_("0 ERROR WRITING TO FILE :", darray_1.darray, &c__1, &ilen, (
		ftnlen)25, (ftnlen)120);
    } else if (iret == 5) {
	cform_("0 ERROR OPENING FILE :", darray_1.darray, &c__1, &ilen, (
		ftnlen)22, (ftnlen)120);
    } else {
	cform_("0 I/O ERROR FILE :", darray_1.darray, &c__1, &ilen, (ftnlen)
		18, (ftnlen)120);
    }
    ipos = ilen + 2;
    cform_(lmem, darray_1.darray, &ipos, &c__8, (ftnlen)8, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L5040:
    clospe_(&c__19, &iret);
    return 0;
} /* punch_ */

#undef twochr
#undef iarray
#undef buffer
#undef bcanon
#undef canloc
#undef ltest
#undef dtest
#undef array
#undef sscan
#undef canon
#undef blank
#undef numb
#undef buf
#undef blk
#undef can
#undef ii
#undef no
#undef ia
#undef x
#undef a


