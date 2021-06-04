/* INIT.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

struct {
    integer ntb, fpb, ppb, comn, cfb, nblk, nrecrd[10], ntparm[10];
} stor_;

#define stor_1 stor_

struct {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp;
} work_;

#define work_1 work_

struct {
    integer kcomt, kcomf;
    logical cilprt;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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

struct {
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

/* Table of constant values */

static integer c__23 = 23;
static integer c__1 = 1;
static integer c__46 = 46;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__41 = 41;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__3 = 3;
static integer c__20 = 20;
static integer c__16 = 16;
static integer c_n23 = -23;
static integer c__42 = 42;
static integer c__28 = 28;
static integer c__21 = 21;
static integer c__25 = 25;
static integer c__5 = 5;
static integer c__14 = 14;
static integer c__22 = 22;
static integer c__35 = 35;
static integer c__57 = 57;
static integer c__17 = 17;

/* *** SOURCE FILE : M0001190.V14   *** */

/* .....FORTRAN ROUTINE              ..INIT..    HL GRAY 3/68, 8/68 */
/* Subroutine */ int init_(void)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static integer kpgn = 256;
    static char blank[8] = "        ";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    char ch__1[14];
    static integer equiv_22[23];

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, j0, j1, j2, k0;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
#define in (equiv_22)
    static integer jn, ll, kn, ir;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
    static integer nr, kk1, kk2;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
#define ian (equiv_22 + 4)
#define san (equiv_22 + 2)
#define scn (equiv_22 + 1)
#define lpg (equiv_22 + 11)
#define fpn (equiv_22 + 12)
    static integer kll;
#define nsn (equiv_22 + 3)
#define ntn (equiv_22 + 13)
    extern integer bcdf_(char *, ftnlen);
    static integer ncfb, jcol;
    extern /* Subroutine */ int help_(void);
    static integer isan, iscn;
#define coms (equiv_22 + 5)
#define pppg (equiv_22 + 14)
#define mtpg (equiv_22 + 15)
    static integer insn, jtop;
    extern /* Subroutine */ int aread_(integer *, integer *, integer *, 
	    integer *, integer *), fread_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *);
#define ipage ((integer *)&stor_1 + 20)
#define canon ((doublereal *)&_BLNK__1)
    static integer kkrec;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer kkmin;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer irisk;
#define numod ((integer *)&stor_1 + 17)
    extern /* Subroutine */ int tapop_(integer *, integer *);
    static integer isurp;
#define numst ((integer *)&stor_1 + 16)
#define maxsz1 (equiv_22 + 21)
#define maxsz2 (equiv_22 + 22)
    extern /* Subroutine */ int chread_(integer *, integer *, char *, integer 
	    *, integer *, ftnlen);
#define ndaflg ((integer *)&stor_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define logcal ((logical *)equiv_22 + 17)
#define nrecst ((integer *)&stor_1 + 19)
    static integer mcanpg;
    extern /* Subroutine */ int cprint_(char *, ftnlen);

/* --------------------------------------------------------------CDE PAK */
/* UNLABELED COMMON */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/* NAME TABLE */
/*     ------------------- */

/* SYSTEM DEPENDENT PARAMETERS */







/* STOR--COMMON CONTAINING STORAGE PARAMETERS */


/*   ADDITIONAL STOR PARAMETERS USED FOR NUMBER TABLE DIRECT ACCESS */


/* WORK--COMMON CONTAINING WORKING VARIABLES */

/* CONST--COMMON CONTAINING CONSTANTS */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */

/*               SYSTEM I/O FILE NAMES */

/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/* ...                SYSTEM I/O FILES */





/* ---     MAXLDA CONTAINS THE MAXIMUM SPACE AVAILABLE FOR LDA'S */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/* --------------------------------------------------------------------- */


/* ---     COMN REFLECTS THE TOTAL SPACE AVAILABLE IN BLANK COMMON (COM) */
/* ---     IF DIMENSION OF COM IS CHANGED, THEN VALUE OF COMN IS CHANGED */
/* ---     HERE AUTOMATICALLY */
    stor_1.comn = 36000;
    irisk = 1;
/* ---      IF IRISK IS 1, THEN SYSTEM WILL NOT TERMINATE FOR */
/* ---      LACK OF SPACE BUT WILL PROCEED AT RISK */
/*     --------- */
    _BLNK__1.com[0] = zero;
    nr = 0;
    aread_(&symfil_1.elfil4, &nr, in, &c__23, &ir);
    const_1.cilprt = *logcal;
    *numst = in[18];
    *ndaflg = in[19];
    *nrecst = in[20];

/* ---     PRELIMINARY CALCULATION TO SET ASIDE SPACE FOR LARGE DDATA */
/* ---     FIXED ALLOCATIONS ARE MADE FOR ARELEM PART,DRIVE AND */
/* ---     AND CHECK SURFACES,TEMPORARY MATRIX, NAME TABLE */
/* ---     AND NUMBER TABLE */
    ncfb = const_1.kcomf + *ntn + const_1.kcomt + *fpn;
/* ---     MINIMUM SPACE FOR CANON DATA AND PART PROGRAM DATA */
    mcanpg = *scn + *san + *nsn + *ian;
    kk1 = const_1.kcbn * 9;
    kk2 = (kpgn / 4 << 2) + 1;
    if (mcanpg > kk1) {
	mcanpg = kk1 + kk2;
    }
    if (mcanpg <= kk1) {
	mcanpg += kk2;
    }

/* ---      FIRST ATTEMPT, SPACE FOR THE LARGEST PLUS NEXT LARGEST */
/* ---      ALLOCATE SPACE (COMS) FOR LARGE DATA ARRAYS */
    *coms = *maxsz1 + *maxsz2 + 90;
    isurp = stor_1.comn - *coms - mcanpg - ncfb;
    if (isurp < 0) {
	goto L5;
    }
    *coms += isurp / 2;
    goto L6;
L5:
/* ---      TRY SPACE FOR ONLY ONE LDA IN MEMORY */
    *coms -= *maxsz2;
    isurp += *maxsz2;
/* ---      QUIT NOW IF THERE IS NOT SPACE FOR EVEN ONE LDA. */
    if (isurp < 0 && irisk == 0) {
	goto L80;
    }
/* ------ALTERNATE CODE TO CONTINUE AT RISK */
    *coms = stor_1.comn - mcanpg - ncfb;
    if (*coms < 0) {
	goto L80;
    }
    cform_(" PREDICTED LDA SIZE TOO LARGE, PROCEED AT RISK", darray_1.darray, 
	    &c__1, &c__46, (ftnlen)46, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    bad_(&c__1, &c__0, "COMN", &stor_1.comn, (ftnlen)4);
    bad_(&c__1, &c__0, "COMS", coms, (ftnlen)4);
    bad_(&c__1, &c__0, "MXS1", maxsz1, (ftnlen)4);
    bad_(&c_n1, &c__0, "MXS2", maxsz2, (ftnlen)4);
/* ---      NOW COMS IS THE TOTAL SPACE FOR LARGE DATA. */
L6:
    maxlda_1.maxlda = *coms;
    j0 = in[16];
    jn = *ntn;
    nr = 0;
/* ---     READ IN THE NAME TABLE ENTRIES */
    chread_(&symfil_1.elfil4, &nr, cnamtb_1.cnamtb + (j0 - 1) * 6, &jn, &ir, (
	    ftnlen)6);

/* ... LOAD BCD EQUIVALENT OF CNAMTB ENTRIES IN NT */

    j1 = const_1.kcomf + const_1.kcomt + *coms + 1;
    j2 = j0 + *ntn - 1;
    i__1 = j2;
    for (j = j0; j <= i__1; ++j) {
	nt[(j1 << 1) - 2] = bcdf_(cnamtb_1.cnamtb + (j - 1) * 6, sdp_1.iwrd);
	i__2 = sdp_1.iwrd;
/* Writing concatenation */
	i__3[0] = 6 - i__2, a__1[0] = cnamtb_1.cnamtb + ((j - 1) * 6 + i__2);
	i__3[1] = 8, a__1[1] = blank;
	s_cat(ch__1, a__1, i__3, &c__2, (ftnlen)14);
	nt[(j1 << 1) - 1] = bcdf_(ch__1, 6 - i__2 + 8);
	++j1;
/* L8: */
    }

/* ---     PRINT OUT THE COMPLETE NAME TABLE IF COMPRESSED PRINT IS ON */
    if (! const_1.cilprt) {
	goto L50;
    }
    cform_("0 LIST OF ALPHANUMERIC NAME TABLE ENTRIES", darray_1.darray, &
	    c__1, &c__41, (ftnlen)41, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    kll = in[16] - 1;
    jcol = 2;
    jtop = j0 + *ntn - 1;
    i__1 = jtop;
    for (ll = j0; ll <= i__1; ++ll) {
	++kll;
	if (s_cmp(cnamtb_1.cnamtb + (ll - 1) * 6, blank, (ftnlen)6, (ftnlen)8)
		 == 0) {
	    goto L60;
	}
	iconv_(&kll, darray_1.darray, &jcol, &c__4, (ftnlen)120);
	jcol += 5;
	cform_(cnamtb_1.cnamtb + (ll - 1) * 6, darray_1.darray, &jcol, &c__6, 
		(ftnlen)6, (ftnlen)120);
	jcol += 9;
	if (jcol + 14 <= 120) {
	    goto L60;
	}
	cprint_(darray_1.darray, (ftnlen)120);
	jcol = 2;
L60:
	;
    }
    cprint_(darray_1.darray, (ftnlen)120);
L50:

    k0 = j1;
    j0 = j1 - *ntn;

/*        IF NDAFLG IS NOT ZERO THEN DIRECT ACCESS IS USED TO STORE */
/*        NUMBER TABLE VALUES. ONLY FIXED NUMBERS ARE PASSED ON ELFIL4. */
    if (*ndaflg == 0) {
	goto L1003;
    }
    *numod = *fpn - *numst;
    kn = *fpn - *numod;
    goto L1004;

L1003:
    kn = *fpn;
L1004:
    nr = 0;
    if (j0 + *ntn + kn > stor_1.comn) {
	goto L80;
    }
    fread_(&symfil_1.elfil4, &nr, &fp[k0 - 1], &kn, &ir, &c__3);
    tapop_(&symfil_1.elfil4, &c_n1);

    stor_1.ntb = j0 - in[16];
    stor_1.fpb = stor_1.ntb;
    work_1.comp = const_1.kcomf + 1;
    work_1.scp = k0 + *fpn;
    stor_1.cfb = work_1.scp;
    work_1.sap = work_1.scp + *scn;
    work_1.nsp = work_1.sap + *san;
    work_1.iap = work_1.nsp + *nsn;
    stor_1.ppb = (work_1.iap + *ian << 1) - 1;
    const_1.kcomt = const_1.kcomf + *coms + 1;

    if (! const_1.cilprt) {
	goto L90;
    }
/* PRINT  INTERPRETER PARAMETERS */
    cform_("1   EXECUTION PHASE ", darray_1.darray, &c__1, &c__20, (ftnlen)20,
	     (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("ENTR=INIT TABLES", darray_1.darray, &c__4, &c__16, (ftnlen)16, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    bad_(&c_n23, &c__0, "IN  ", in, (ftnlen)4);
    bad_(&c__1, &c__0, "KCMF", &const_1.kcomf, (ftnlen)4);
    bad_(&c__1, &c__0, "COMS", coms, (ftnlen)4);
    bad_(&c__1, &c__0, "MXS1", maxsz1, (ftnlen)4);
    bad_(&c__1, &c__0, "MXS2", maxsz2, (ftnlen)4);
    bad_(&c_n1, &c__0, "KCMT", &const_1.kcomt, (ftnlen)4);
    bad_(&c__1, &c__0, "NTN ", ntn, (ftnlen)4);
    bad_(&c__1, &c__0, "FPN ", fpn, (ftnlen)4);
    bad_(&c__1, &c__0, "KCBN", &const_1.kcbn, (ftnlen)4);
    bad_(&c__1, &c__0, "KPGN", &kpgn, (ftnlen)4);
    bad_(&c_n1, &c__0, "COMN", &stor_1.comn, (ftnlen)4);
/*        CAN ALL CANNONICAL FORMS PLUS 4 PAGES OF I.L. FIT IN CORE */
L90:
    if (stor_1.ppb + (kpgn << 2) - 1 <= stor_1.comn << 1) {
	goto L20;
    }
/*        NO, STORE CANNONICAL FORMS ON EXTERNAL FILE. */
    ldef_1.canflg = TRUE_;
/*        AT LEAST 9 BLOCKS OF CANNON & 4 PAGES OF I.L. MUST FIT IN CORE */
    i__ = stor_1.comn - stor_1.cfb - const_1.kcbn * 9 - (kpgn << 1) + 1;
    if (i__ >= 0) {
	goto L10;
    }

/* ---     TERMINATE EXECUTION PHASE FOR LACK OF SPACE */
L80:
    cform_("029002 LARGEST CANONICAL FORM IS TOO LARGE", darray_1.darray, &
	    c__1, &c__42, (ftnlen)42, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("0TABLE SIZES FROM TRANSLATOR", darray_1.darray, &c__1, &c__28, (
	    ftnlen)28, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    bad_(&c__23, &c__0, "IN  ", in, (ftnlen)4);
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);

    kkmin = ncfb + mcanpg + *maxsz1 + 40;
    kkrec = kkmin + *maxsz2;
    cform_("0SPACE NOW ALLOCATED ", darray_1.darray, &c__1, &c__21, (ftnlen)
	    21, (ftnlen)120);
    iconv_(&stor_1.comn, darray_1.darray, &c__25, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("0MIN SPACE RQD", darray_1.darray, &c__1, &c__14, (ftnlen)14, (
	    ftnlen)120);
    iconv_(&kkmin, darray_1.darray, &c__22, &c__5, (ftnlen)120);
    cform_("RECOMMENDED SPACE IS", darray_1.darray, &c__35, &c__20, (ftnlen)
	    20, (ftnlen)120);
    iconv_(&kkrec, darray_1.darray, &c__57, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    help_();

/*        DIVIDE SPACE LEFT - A BLOCK OF CANNON FOR EACH PAGE OF I.L. */
L10:
    stor_1.nblk = i__ / (const_1.kcbn + kpgn / 2) + 9;
/*        ADJUST POINTERS */
    stor_1.ppb = (stor_1.cfb + stor_1.nblk * const_1.kcbn << 1) - 1;
/*        DETERMINE NUMBER OF ADDITIONAL WORDS REQUIRED FOR EACH TYPE OF */
/*        CANNONICAL FORM. */
    iscn = *scn / const_1.kcbn + 1 << 1;
    isan = *san / const_1.kcbn + 1 << 1;
    insn = (*nsn / const_1.kcbn + 1) * 11;
    work_1.sap = work_1.scp + ((*scn + iscn) / const_1.kcbn + 1) * 
	    const_1.kcbn;
    work_1.nsp = work_1.sap + ((*san + isan) / const_1.kcbn + 1) * 
	    const_1.kcbn;
    work_1.iap = work_1.nsp + ((*nsn + insn) / const_1.kcbn + 1) * 
	    const_1.kcbn;

    if (! const_1.cilprt) {
	goto L20;
    }
    cform_(" XCANON IN EFFECT ", darray_1.darray, &c__1, &c__17, (ftnlen)18, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L20:
    return 0;
} /* init_ */

#undef nrecst
#undef logcal
#undef bcanon
#undef ndaflg
#undef maxsz2
#undef maxsz1
#undef numst
#undef numod
#undef sscan
#undef canon
#undef ipage
#undef mtpg
#undef pppg
#undef coms
#undef ntn
#undef nsn
#undef fpn
#undef lpg
#undef scn
#undef san
#undef ian
#undef can
#undef nt
#undef mt
#undef pp
#undef in
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


