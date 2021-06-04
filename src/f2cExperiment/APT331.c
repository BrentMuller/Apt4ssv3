/* APT331.f -- translated by f2c (version 20100827).
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
    doublereal editor[1500];
} editor_;

#define editor_1 editor_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__8 = 8;
static integer c__10 = 10;
static integer c__21 = 21;
static integer c__31 = 31;
static integer c__6 = 6;
static integer c__38 = 38;
static integer c__17 = 17;
static integer c__56 = 56;
static integer c__42 = 42;
static integer c__52 = 52;
static integer c__59 = 59;
static integer c__77 = 77;
static integer c__39 = 39;
static integer c__13 = 13;
static integer c__26 = 26;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__3 = 3;
static integer c__19 = 19;
static integer c__20 = 20;
static integer c__29 = 29;
static integer c__35 = 35;
static integer c__11 = 11;
static integer c__15 = 15;
static integer c__37 = 37;
static integer c__32 = 32;
static integer c__16 = 16;
static integer c__7 = 7;
static integer c__22 = 22;
static integer c__33 = 33;
static integer c__40 = 40;
static integer c__28 = 28;
static integer c__12 = 12;
static integer c__48 = 48;
static integer c__57 = 57;
static integer c__53 = 53;
static integer c__25 = 25;
static integer c__45 = 45;
static integer c__18 = 18;
static integer c__63 = 63;
static integer c__82 = 82;
static integer c__91 = 91;
static integer c__72 = 72;
static integer c__27 = 27;

/* *** SOURCE FILE : M0001850.V13   *** */


/* .....FORTRAN SUBROUTINE                   APT331 */

/* Subroutine */ int apt331_(void)
{
    /* Initialized data */

    static char quad[32*16] = " NO RECOGNIZABLE SURFACE        " " A PLANE  "
	    "                      " " TWO PARALLEL (COINCIDENT)PLANES" " A P"
	    "ARABOLIC CYLINDER           " " TWO INTERSECTING PLANES        " 
	    " A HYPERBOLIC CYLINDER          " " AN ELLIPTIC CYLINDER       "
	    "    " " A HYPERBOLIC PARABOLOID        " " AN IMAGINARY ELLIPTIC"
	    " CYLINDER " " AN ELLIPTIC PARABOLOID         " " A HYPERBOLOID O"
	    "F ONE SHEET     " " A CONE                         " " A HYPERBO"
	    "LOID OF TWO SHEETS    " " AN ELLIPSOID                   " " A P"
	    "OINT ELLIPSOID              " " AN IMAGINARY ELLIPSOID         ";
    static char jcode[28*5] = "    TOOL TO SURFACE RELATION" "    INTERSECTI"
	    "ON NUMBER     " "    TOLERANCES   OUTTOL     " "                "
	    "  INTOL     " "    THICK SETTINGS          ";
    static char kcode[28*16] = "    EFF. DIST. TO SURFACE   " "    EFF. SURF"
	    "ACE POINT     X" "                           Y" "               "
	    "            Z" "    TOOL POINT             R" "                 "
	    "          H" "    SURFACE NORMAL         X" "                   "
	    "        Y" "                           Z" "    TOOL NORMAL      "
	    "      X" "                           Y" "                       "
	    "    Z" "    RADIUS OF CURVATURE     " "    CENTER OF CURVATURE  "
	    "  X" "                           Y" "                           Z"
	    ;
    static char gotyp[6*7] = "GOLFT " "GORGT " "GOFWD " "GOBACK" "GOUP  " 
	    "GODOWN" "      ";
    static char typ[6*6] = "TO    " "PAST  " "ON    " "TANTO " "PSTAN " "OFF"
	    "SET";
    static char srftyp[4*4] = "PS  " "DS  " "CS1 " "CS2 ";
    static char blank[8] = "        ";
    static char lstrt[12] = "START OF CUT";
    static char blnk[12] = "            ";
    static char badtyp[8] = " UNKNOWN";
    static char aname[6*30] = "LINE  " "PLANE " "CYLNDR" "CIRCLE" "SPHERE" 
	    "HYPERB" "LCONIC" "ELLIPS" "CONE  " "GCONIC" "TABCYL" "RLDSRF" 
	    "POLCON" "QADRIC" "PARSRF" "      " "      " "MATRIX" "POINT " 
	    "VECTOR" "      " "      " "      " "UNKNOW" "      " "PATERN" 
	    "      " "      " "SSURF " "SCURV ";
    static char name__[6*100] = "APT200" "APT201" "  GO  " " PSIS " " TLLFT" 
	    " TLRGT" " TLON " "TLONPS" "TLOFPS" "INDIRP" "INDIRV" "SRFVCT" 
	    " FROM " "GODLTA" " GOTO " " CUT  " "DNTCUT" "NDTEST" "COMP3D" 
	    "OUTTOL" "INTOL " "TOLER " "CUTTER" "TLAXIS" "MULTAX" "MAXDP " 
	    "NUMPTS" "THICK " " NOPS " "AUTOPS" "GOUGCK" "NKNOWN" "APT232" 
	    "APT233" "APT234" "APT235" "APT236" "APT237" "APT238" "ARLM2 " 
	    "ARLM3 " "NKNOWN" "CHECK " "NKNOWN" "PLANE " "NKNOWN" "DELTA " 
	    "NKNOWN" "GOUGE " "NKNOWN" "CENTR " "NKNOWN" "CPLAN " "NKNOWN" 
	    "DDSSRF" "NKNOWN" "TINKER" "NKNOWN" "NKNOWN" "NKNOWN" "AMIND " 
	    "NKNOWN" "NKNOWN" "NKNOWN" "U1COMP" "NKNOWN" "TLNORM" "NKNOWN" 
	    "RADAR " "NKNOWN" "LCLS  " "DDPARA" "FCN   " "NKNOWN" "NKNOWN" 
	    "NKNOWN" "NKNOWN" "NKNOWN" "NKNOWN" "NKNOWN" "NKNOWN" "NKNOWN" 
	    " DDST " "DDPLAN" "DDCYLN" "DDSPHR" "DDQUAD" "DDCONE" "DDTABC" 
	    "NKNOWN" "NKNOWN" "NKNOWN" " QUAD " "VNORM " "CROSS " "ATAPE " 
	    "ASTOS " " AERR " "DYNDMP" "NKNOWN";
    static struct {
	integer e_1[100];
	} equiv_45 = { 0, 20001, 20101, 20102, 20103, 20104, 20105, 20106, 
		20107, 20108, 20201, 20202, 20203, 20204, 20205, 20206, 20207,
		 20208, 20901, 20902, -20903, 21001, 21002, -21003, 21101, 
		-21102, 21301, 22001, 22201, 22202, 22203, 22204, 22205, 
		22206, 22207, 22208, 22209, 22210, -22211, 22212, 22213, 
		22214, 22215, -22216, 22217, -22300, 22301, -22701, 23401, 
		23501, 23901, 23902, 23903, 23904, 23905, -22401, 24001, 
		24002, 24003, 24004, -24201, -24202, 24203, -24401, 24402, 
		24403, 24404, -25001, 25002, 25003, 25004, 25005, 25006, 
		25007, 25008, 0, 26002, 0, 26001, 26401, 26601, -26801, 26802,
		 26803, -28801, 20109, 23908, 24005, 24006, 26602, -27001, 
		27002, 27003, 27104, 27105, 25009, 20110, 27206, 0, 0 };


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_0[1], equiv_43[76];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
#define h__ (equiv_43 + 20)
    static integer i__, j, k, l, m, n;
#define r__ (equiv_43 + 16)
#define s ((doublereal *)&editor_1 + 12)
    static integer j2, i2;
#define cc ((doublereal *)&editor_1 + 23)
#define rc ((doublereal *)&editor_1 + 13)
#define ta ((doublereal *)&editor_1 + 20)
#define te ((doublereal *)&editor_1 + 13)
#define th ((doublereal *)&editor_1 + 11)
#define ti ((doublereal *)&editor_1 + 10)
#define is ((integer *)&editor_1 + 33)
#define sn ((doublereal *)&editor_1 + 17)
#define tn ((doublereal *)&editor_1 + 20)
#define sp ((doublereal *)&editor_1 + 14)
#define vt ((doublereal *)&editor_1 + 26)
    static integer it;
#define igo ((integer *)&editor_1 + 11)
#define fwd ((doublereal *)&editor_1 + 17)
    static integer igt;
    static doublereal dot;
    static integer nwd, niu, nsv;
#define ifl4 ((integer *)&editor_1 + 15)
    static integer jfl4[2];
#define tau1 ((doublereal *)&editor_1 + 9)
#define tau2 ((doublereal *)&editor_1 + 10)
    extern integer bcdf_(char *, ftnlen);
#define ifar ((integer *)&editor_1 + 17)
    static integer jfar[2];
#define mode ((integer *)&editor_1 + 63)
    static doublereal acos__, asin__;
    static integer kval;
#define isub ((integer *)&editor_1 + 61)
    static integer mout;
#define area3 ((doublereal *)&editor_1 + 1250)
#define coeff ((doublereal *)&editor_1 + 5)
#define elmax ((doublereal *)&editor_1 + 9)
#define index ((integer *)&equiv_45)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define dtemp (equiv_0)
#define dpmax ((doublereal *)&editor_1 + 7)
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
#define itemp ((integer *)equiv_0)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define isize ((integer *)&editor_1 + 65)
#define itlon ((integer *)&editor_1 + 11)
    static integer jtlon[2];
#define trans ((doublereal *)&editor_1 + 15)
    static char mstrt[12];
    static doublereal aprnt1[20];
#define aprnt2 (equiv_43)
#define canfrm ((doublereal *)&editor_1 + 33)
#define irecrd ((integer *)&editor_1)
#define indexa ((integer *)&equiv_45)
#define xcoeff ((doublereal *)&editor_1 + 10)
#define indexb ((integer *)&equiv_45 + 50)
#define iqsdfg ((integer *)&editor_1 + 9)
#define icscnt ((integer *)&editor_1 + 7)
#define cutdat ((doublereal *)&editor_1 + 5)
    static char qsdnam[32];
#define iedtor ((integer *)&editor_1)
    static integer numabs;
#define srfnme ((doublereal *)&editor_1 + 29)
    extern /* Subroutine */ int cleror_(integer *), holfrm_(doublereal *, 
	    char *, integer *, integer *, integer *, ftnlen);
    static doublereal fwdnrm;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
#define savseq ((doublereal *)&editor_1 + 476)
#define numerr ((integer *)&editor_1 + 6)
#define isbtyp ((integer *)&editor_1 + 3)
#define isftyp ((integer *)&editor_1 + 13)
#define nmpnts ((integer *)&editor_1 + 17)
    static integer jsftyp[2];
    static doublereal vtnorm;
#define istrup ((integer *)&editor_1 + 13)


/* PURPOSE      TO WRITE ONTO THE VERIFICATION LISTING TAPE-- */
/*      1) THE DIAGNOSTIC NUMBER AND THE NAME OF THE PROGRAM */
/*         WHICH ISSUED THE DIAGNOSTIC */
/*      2) THE DIAGNOSTIC MESSAGE */
/*      IF THE DIAGNOSTIC IS A RESTART ERROR IT ALSO WRITES - */
/*      3) USEFUL INFORMATION ABOUT THE CUTTER AND THE PART,DRIVE, */
/*         AND CHECK SURFACES AS WELL AS MANY INTERMEDIATE CUTTER */
/*         LOCATION PARAMETERS */

/* LINKAGE      CALL APT331 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */




/* ... *** EQUIVALENCE OF NECESSARY ARELEM VARIABLES*** */

/* ...     EQUIVALENCE FOR SV BLOCK VARIABLES */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* ...     EQUIVALENCE FOR ISV BLOCK VARIABLES */


/* ...     EQUIVALENCE FOR NECESSARY FXCOR AND IFXCOR VARIABLES */



/* ......EQUIVALENCE FOR PREVIOUS SEQ. NO. */

/* ....***** EQUIVALENCE OF PRINTOUT AND IDENTIFICATION VARIABLES *** */

/* ...     EQUIVALENCE FOR QUADRIC SURFACE IDENTIFICATION */



/* ....    LABEL PRINTOUT */



/* ....    EQUIVALENCE FOR SURFACE NAME AND TYPE VARIABLES */
/*        AND CANONICAL FORM ARRAY */


/* ....    EQUIVALENCE FOR IMPORTANT PRINTOUT VARIABLES */






/* ..      SURFACE NAME ARRAY */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/*        SUBROUTINE NAME INDEX ARRAY */


/* ...  SUBROUTINE NAMES */


/*        DATA FOR QUADRIC SURFACE TYPES */



/* ....    DATA FOR LABEL PRINTOUT */



/*     MOTION AND CONTROL SURFACE TYPES */


/*     SURFACE NAME ARRAY DATA */


/*     SUBROUTINE NAME INDEX ARRAY */


/*     SUBROUTINE NAMES */


/*                       ***************                  *************** */
/*                       ***** WARNING. VLFILE  IS  EQUIVALENCE TO CLLST* */
/*                       ***************                  *************** */

/*     ------------------------------------------------------------ */


/* .....   ISBTYP INDICATES TYPE OF ERROR RECORD AS FOLLOWS */

/*     ISBTYP=1 --  DIAGNOSTIC MESSAGE */
/*     ISBTYP=2 --  FXCOM VARIABLES */
/*     ISBTYP=3 --  SURFACE VARIABLES(PS) */
/*     ISBTYP=4 --  SURFACE VARIABLES(DS) */
/*     ISBTYP=5 --  SURFACE VARIABLES(CS1) */
/*     ISBTYP=6 --  SURFACE VARIABLES(CS2) */
/*     ISBTYP=7 --  QUADRIC SURFACE IDENTIFICATION */
/*     ISBTYP=8 --  POCKET */

    switch (*isbtyp) {
	case 1:  goto L10;
	case 2:  goto L180;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L40;
	case 6:  goto L40;
	case 7:  goto L110;
	case 8:  goto L800;
    }

/* ...***** SUB-TYPE 1 - PRINT DIAGNOSTIC MESSAGE AND CUTTER PARAMETERS* */

L10:
    numabs = abs(numerr[1]);
    j2 = (numabs - 20000) / 100 + 1;
    if (j2 <= 0 || j2 > 100) {
	goto L500;
    }

/* ...    FIND CORRECT DIAGN MESSAGE NUMBER FOR THIS ERROR */
    n = 1;
    for (m = 1; m <= 100; ++m) {
	mout = m;
	if (numabs == (i__1 = index[m - 1], abs(i__1))) {
	    goto L13;
	}
/* L12: */
    }
    n = 0;
L13:
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    i__ = (integer) (*savseq + .1f);
    iconv_(&i__, darray_1.darray, &c__2, &c__8, (ftnlen)120);
    if (numerr[1] >= 0) {
	goto L18;
    } else {
	goto L14;
    }

/* ..      WARNING DIAGNOSTIC */
L14:
    cform_(".    WARNING NUMBER (", darray_1.darray, &c__10, &c__21, (ftnlen)
	    21, (ftnlen)120);
    iconv_(&numerr[1], darray_1.darray, &c__31, &c__6, (ftnlen)120);
    cform_(") FROM SUBROUTINE", darray_1.darray, &c__38, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(name__ + (j2 - 1) * 6, darray_1.darray, &c__56, &c__6, (ftnlen)6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L15:
    if (n != knumbr_1.k0) {
	goto L16;
    }
    m = knumbr_1.k1;
    mout = knumbr_1.k1;
L16:
    cleror_(&numabs);

    if (numerr[1] >= 0) {
	goto L19;
    } else {
	goto L9000;
    }

/* ...     RESTART DIAGNOSTIC */
L18:
    cform_(".    ENTERING RESTART MODE. ERROR NUMBER (                  ", 
	    darray_1.darray, &c__10, &c__42, (ftnlen)60, (ftnlen)120);
    iconv_(&numerr[1], darray_1.darray, &c__52, &c__6, (ftnlen)120);
    cform_(") FROM SUBROUTINE", darray_1.darray, &c__59, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(name__ + (j2 - 1) * 6, darray_1.darray, &c__77, &c__6, (ftnlen)6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L15;

/*        CHECK FOR CUTTER DEFINITION ERROR */
L19:
    if (j2 == 23) {
	goto L20;
    }
    if (mout != 9 && mout != 11) {
	goto L25;
    }

L20:
    cform_("0RESTART USING A POINT CUTTER (PARAMETERS ALL ZERO).   ", 
	    darray_1.darray, &c__1, &c__52, (ftnlen)55, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    if (j2 != 23) {
	goto L9000;
    }
    cform_("0ORIGINAL (ERRONEOUS) PARAMETERS WERE--", darray_1.darray, &c__1, 
	    &c__39, (ftnlen)39, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    l = 6;
    for (i__ = 1; i__ <= 7; ++i__) {
	fconv_(&cutdat[i__ - 1], darray_1.darray, &l, &c__13, &c__6, (ftnlen)
		120);
/* L921: */
	l += 13;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    goto L9000;

/* ...     PRINTOUT CUTTER PARAMETERS */
L25:
    cform_("0CUTTER PARAMETERS --", darray_1.darray, &c__1, &c__21, (ftnlen)
	    21, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    l = 6;
    for (i2 = 1; i2 <= 7; ++i2) {
	fconv_(&cutdat[i2 - 1], darray_1.darray, &l, &c__13, &c__6, (ftnlen)
		120);
/* L925: */
	l += 13;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    goto L9000;

/* ...***** SUB-TYPE 3 - PART SURFACE VARIABLES ***** */

L30:
    cform_("0   SURFACE DATA..........", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

/* ...***** SUB-TYPES 3, 4, 5, 6 - ALL SURFACE CANONICAL FORMS ***** */

/*        IT INDEXES THE SURFACE */
L40:
    it = *isbtyp - 2;

/*     CHECK FOR INVALID SURFACE MODE */
    if (*mode <= 0 || *mode > 30) {
	*mode = 24;
    }

/*        PRINT OUT CANONICAL FORM */
    cform_(srftyp + (it - 1 << 2), darray_1.darray, &c__5, &c__4, (ftnlen)4, (
	    ftnlen)120);
    cform_("...", darray_1.darray, &c__9, &c__3, (ftnlen)3, (ftnlen)120);
    holfrm_(srfnme, darray_1.darray, &c__13, &c__6, &nwd, (ftnlen)120);
    cform_("(     ) =", darray_1.darray, &c__19, &c__9, (ftnlen)9, (ftnlen)
	    120);
    iconv_(isub, darray_1.darray, &c__20, &c__5, (ftnlen)120);
    cform_(aname + (*mode - 1) * 6, darray_1.darray, &c__29, &c__6, (ftnlen)6,
	     (ftnlen)120);
    cform_("/", darray_1.darray, &c__35, &c__1, (ftnlen)1, (ftnlen)120);
    if (*mode == 15) {
	goto L4720;
    }
    k = *isize;
    if (*isize > 7) {
	k = 7;
    }
    l = 37;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fconv_(&canfrm[i__ - 1], darray_1.darray, &l, &c__11, &c__4, (ftnlen)
		120);
/* L4718: */
	l += 11;
    }
    if (*isize <= 7) {
	goto L4720;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    l = 4;
    i__1 = *isize;
    for (i__ = 8; i__ <= i__1; ++i__) {
	fconv_(&canfrm[i__ - 1], darray_1.darray, &l, &c__11, &c__4, (ftnlen)
		120);
/* L4719: */
	l += 11;
    }
L4720:
    cprint_(darray_1.darray, (ftnlen)120);

/*        SAVE NECESSARY FLAGS FOR THIS SURFACE. */
    nsv = it - 2;
    if (nsv <= 0) {
	goto L58;
    } else {
	goto L59;
    }
L58:
    jtlon[it - 1] = *itlon;
    goto L61;
L59:
    jsftyp[nsv - 1] = *isftyp;
    jfl4[nsv - 1] = *ifl4;
    jfar[nsv - 1] = *ifar;

/*        SAVE NECESSARY VARIABLE VALUES FOR THIS SURFACE */
L61:
    aprnt1[it + 7] = *tau1;
    aprnt1[it + 11] = *tau2;
    aprnt1[it + 15] = *th;

/*        APRNT2 VALUES ARE FOR NON-ARLM2 DIAGNOSTICS */
    aprnt2[it - 1] = *s;
    aprnt2[it + 47] = *rc;
    for (i__ = 1; i__ <= 3; ++i__) {
	j = it + (i__ - 1 << 2);
	aprnt2[j + 3] = sp[i__ - 1];
	aprnt2[j + 23] = sn[i__ - 1];
	aprnt2[j + 35] = tn[i__ - 1];
	aprnt2[j + 51] = cc[i__ - 1];
/* L81: */
	aprnt2[j + 63] = vt[i__ - 1];
    }
    goto L9000;

/* ....*****  SUB-TYPE 7 - QUADRIC SURFACE IDENTIFICATION ***** */

L110:
    s_copy(qsdnam, quad + (*iqsdfg - 1 << 5), (ftnlen)32, (ftnlen)32);

/*        PRINTOUT FOR QUADRIC IDENTIFICATION */

    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(" THE SURFACE IS", darray_1.darray, &c__21, &c__15, (ftnlen)15, (
	    ftnlen)120);
    cform_(qsdnam, darray_1.darray, &c__37, &c__32, (ftnlen)32, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    cform_("ROTATION MATRIX", darray_1.darray, &c__31, &c__15, (ftnlen)15, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    for (i__ = 1; i__ <= 3; ++i__) {
	l = 16;
	for (j = 1; j <= 4; ++j) {
	    fconv_(&trans[i__ + j * 3 - 4], darray_1.darray, &l, &c__16, &
		    c__7, (ftnlen)120);
/* L135: */
	    l += 16;
	}
	cprint_(darray_1.darray, (ftnlen)120);
/* L136: */
    }

    cform_("THE TRANSFORMED COEFFICIENTS ARE- ", darray_1.darray, &c__22, &
	    c__33, (ftnlen)34, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    l = 16;
    for (i__ = 1; i__ <= 5; ++i__) {
	fconv_(&coeff[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)
		120);
/* L150: */
	l += 16;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    l = 16;
    for (i__ = 1; i__ <= 5; ++i__) {
	fconv_(&xcoeff[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)
		120);
/* L151: */
	l += 16;
    }
    cprint_(darray_1.darray, (ftnlen)120);

    goto L9000;

/* ...***** SUB-TYPE 2 - PRINT FXCOM AND SURFACE VARIABLE DATA ***** */

/*        CHECK FOR A STARTUP MOTION */
L180:
    if (*istrup == 1) {
	goto L181;
    }

/*        CHECK FOR A VALID MOTION COMMAND (IGO BETWEEN 1 AND 6) */
    if ((*igo + 5) / 6 - 1 != 0) {
	goto L181;
    } else {
	goto L182;
    }

/*        NO COMMANDED DIRECTION-PRINT BLANKS */
L181:
    *igo = 7;
    s_copy(gotyp + 36, blank, (ftnlen)6, (ftnlen)8);

/*        CHECK FOR A STARTUP */
L182:
    if (*istrup == 1) {
	s_copy(mstrt, lstrt, (ftnlen)12, (ftnlen)12);
    } else {
	s_copy(mstrt, blnk, (ftnlen)12, (ftnlen)12);
    }

/*        CHECK FOR VALID FWD MOTION VECTOR */
    for (i__ = 1; i__ <= 3; ++i__) {
	if (fwd[i__ - 1] < 1e-32 || fwd[i__ - 1] > 1e32) {
	    fwd[i__ - 1] = 0.f;
	}
/* L184: */
    }

/* Computing 2nd power */
    d__1 = fwd[0];
/* Computing 2nd power */
    d__2 = fwd[1];
/* Computing 2nd power */
    d__3 = fwd[2];
    fwdnrm = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if ((d__1 = fwdnrm - 1.f, abs(d__1)) <= .01f) {
	goto L185;
    }
    fwd[0] = 0.f;
    fwd[1] = 0.f;
    fwd[2] = 0.f;

/*        PRINT OUT MOTION INFORMATION */

L185:
    cform_("0MOTION AND TOOL POSITION DATA..........", darray_1.darray, &c__1,
	     &c__40, (ftnlen)40, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("COMMANDED MOTION DIRECTION -", darray_1.darray, &c__5, &c__28, (
	    ftnlen)28, (ftnlen)120);
    cform_(mstrt, darray_1.darray, &c__33, &c__12, (ftnlen)12, (ftnlen)120);
    cform_(gotyp + (*igo - 1) * 6, darray_1.darray, &c__48, &c__6, (ftnlen)6, 
	    (ftnlen)120);
    cform_("=", darray_1.darray, &c__57, &c__1, (ftnlen)1, (ftnlen)120);
    l = 59;
    for (i__ = 1; i__ <= 3; ++i__) {
	fconv_(&fwd[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)120)
		;
/* L187: */
	l += 19;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("CURRENT MOTION DIRECTION............................  =", 
	    darray_1.darray, &c__5, &c__53, (ftnlen)55, (ftnlen)120);
    l = 59;
    for (i__ = 1; i__ <= 3; ++i__) {
	fconv_(&ti[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)120);
/* L188: */
	l += 19;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("CURRENT TOOL POSITION(UNACCEPTED)...................  =", 
	    darray_1.darray, &c__5, &c__53, (ftnlen)55, (ftnlen)120);
    l = 59;
    for (i__ = 1; i__ <= 3; ++i__) {
	fconv_(&te[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)120);
/* L189: */
	l += 19;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("CURRENT TOOL AXIS VECTOR............................  =", 
	    darray_1.darray, &c__5, &c__53, (ftnlen)55, (ftnlen)120);
    l = 59;
    for (i__ = 1; i__ <= 3; ++i__) {
	fconv_(&ta[i__ - 1], darray_1.darray, &l, &c__16, &c__7, (ftnlen)120);
/* L190: */
	l += 19;
    }
    cprint_(darray_1.darray, (ftnlen)120);

/*        CHECK FOR A DIAGNOSTIC FROM AMIND ASSOCIATED ROUTINES */
    if ((j2 - 61) * (j2 - 73) <= 0) {
	goto L191;
    } else {
	goto L193;
    }

L191:
    --(*is);
    cform_("CURRENT SURFACE=", darray_1.darray, &c__5, &c__16, (ftnlen)16, (
	    ftnlen)120);
    cform_(srftyp + (*is - 1 << 2), darray_1.darray, &c__21, &c__4, (ftnlen)4,
	     (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

/* ..      IF AN ARLM2 DIAGNOSTIC SET KVAL TO 2 */
L193:
    kval = 2;
    if (j2 == 40) {
	goto L196;
    }

/*        GIVE ADDITIONAL INFORMATION IF NOT ARLM2 ERROR */
    kval = 3;
    cform_("0   MAXIMUM STEP (MAXDP)= ", darray_1.darray, &c__1, &c__25, (
	    ftnlen)26, (ftnlen)120);
    fconv_(dpmax, darray_1.darray, &c__26, &c__11, &c__4, (ftnlen)120);
    cform_("MAXIMUM LENGTH(L)= ", darray_1.darray, &c__45, &c__18, (ftnlen)19,
	     (ftnlen)120);
    fconv_(elmax, darray_1.darray, &c__63, &c__11, &c__4, (ftnlen)120);
    cform_("NUMPTS=", darray_1.darray, &c__82, &c__7, (ftnlen)7, (ftnlen)120);
    iconv_(nmpnts, darray_1.darray, &c__91, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

L196:
    cform_("0   GENERAL DATA - THIS CUT -", darray_1.darray, &c__1, &c__29, (
	    ftnlen)29, (ftnlen)120);
    cform_("PART SURF.       DRIVE SURF.", darray_1.darray, &c__39, &c__28, (
	    ftnlen)28, (ftnlen)120);
    cform_("CHECK SURF. 1      CHECK SURF. 2", darray_1.darray, &c__72, &
	    c__32, (ftnlen)32, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

/*        FIND CORRECT TOOL TO SURFACE TYPE FOR PART AND DRIVE SURFACES */

    for (i__ = 1; i__ <= 2; ++i__) {
	if (jtlon[i__ - 1] != 0) {
	    goto L204;
	}
	itemp[0] = bcdf_(typ + 12, (ftnlen)4);
	itemp[1] = bcdf_(typ + 16, (ftnlen)2);
	aprnt1[i__ - 1] = *dtemp;
	goto L205;
L204:
	itemp[0] = bcdf_(typ + 30, (ftnlen)4);
	itemp[1] = bcdf_(typ + 34, (ftnlen)2);
	aprnt1[i__ - 1] = *dtemp;
L205:
	;
    }

/*        FIND CORRECT TOOL TO SURFACE TYPE FOR CHECK SURFACES */

    if (nsv <= 0) {
	goto L230;
    }
    i__1 = nsv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	igt = jsftyp[i__ - 1];

/*      TEST IF IGT MARKER GIVES VALID TOOL TO SURFACE RELATION */
	if ((igt + 3) / 4 != 1 && igt != 8) {
	    goto L221;
	}
	if ((i__2 = igt - 4) < 0) {
	    goto L217;
	} else if (i__2 == 0) {
	    goto L218;
	} else {
	    goto L219;
	}

L217:
	itemp[0] = bcdf_(typ + (igt - 1) * 6, (ftnlen)4);
	itemp[1] = bcdf_(typ + ((igt - 1) * 6 + 4), (ftnlen)2);
	aprnt1[i__ + 1] = *dtemp;
	goto L222;
L218:
	if (jfl4[i__ - 1] == 1) {
	    goto L219;
	}
	itemp[0] = bcdf_(typ + 18, (ftnlen)4);
	itemp[1] = bcdf_(typ + 22, (ftnlen)2);
	aprnt1[i__ + 1] = *dtemp;
	goto L222;
L219:
	itemp[0] = bcdf_(typ + 24, (ftnlen)4);
	itemp[1] = bcdf_(typ + 28, (ftnlen)2);
	aprnt1[i__ + 1] = *dtemp;
	goto L222;
L221:
	itemp[0] = bcdf_(badtyp, (ftnlen)4);
	itemp[1] = bcdf_(badtyp + 4, (ftnlen)4);
	aprnt1[i__ + 1] = *dtemp;
L222:
	;
    }

/*        PRINT OUT TOOL INFORMATION */

L230:
    cform_(jcode, darray_1.darray, &c__6, &c__28, (ftnlen)28, (ftnlen)120);
    l = 42;
    i__1 = it;
    for (i__ = 1; i__ <= i__1; ++i__) {
	holfrm_(&aprnt1[i__ - 1], darray_1.darray, &l, &c__8, &nwd, (ftnlen)
		120);
/* L231: */
	l += 18;
    }
    cprint_(darray_1.darray, (ftnlen)120);

    if (it <= 2) {
	goto L233;
    }
    cform_(jcode + 28, darray_1.darray, &c__6, &c__28, (ftnlen)28, (ftnlen)
	    120);
    l = 77;
    i__1 = nsv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iconv_(&jfar[i__ - 1], darray_1.darray, &l, &c__2, (ftnlen)120);
/* L232: */
	l += 16;
    }
    cprint_(darray_1.darray, (ftnlen)120);

/*        MORE PRINTOUT-TOLERANCES */
L233:
    i__1 = kval;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k = i__ + 2;
	m = (i__ - 1 << 2) + 9;
	n = m + it - 1;
	cform_(jcode + (k - 1) * 28, darray_1.darray, &c__6, &c__28, (ftnlen)
		28, (ftnlen)120);
	l = 36;
	i__2 = n;
	for (j = m; j <= i__2; ++j) {
	    fconv_(&aprnt1[j - 1], darray_1.darray, &l, &c__15, &c__7, (
		    ftnlen)120);
/* L234: */
	    l += 18;
	}
	cprint_(darray_1.darray, (ftnlen)120);
/* L235: */
    }

/*        IS IT AN ARLM2 DIAGNOSTIC, IF SO RETURN */

    if (kval == 2) {
	goto L9000;
    }
    cform_("0   CONDITIONS AT FAILURE", darray_1.darray, &c__1, &c__25, (
	    ftnlen)25, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

/*        COMPUTE R AND H. */

    i__1 = it;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dot = ta[0] * aprnt2[i__ + 63] + ta[1] * aprnt2[i__ + 67] + ta[2] * 
		aprnt2[i__ + 71];
/* Computing 2nd power */
	d__1 = aprnt2[i__ + 63];
/* Computing 2nd power */
	d__2 = aprnt2[i__ + 67];
/* Computing 2nd power */
	d__3 = aprnt2[i__ + 71];
	vtnorm = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	if (vtnorm != 0.) {
	    goto L244;
	} else {
	    goto L243;
	}
L243:
	acos__ = 0.f;
	goto L245;
L244:
	acos__ = dot / vtnorm;
L245:
/* Computing 2nd power */
	d__1 = acos__;
	asin__ = sqrt(1.f - d__1 * d__1);
	r__[i__ - 1] = vtnorm * asin__;
/* L246: */
	h__[i__ - 1] = vtnorm * acos__;
    }

/*        PRINT OUT SURFACE VARIABLES. */

    for (i__ = 1; i__ <= 16; ++i__) {
	k = i__;
	m = (i__ - 1 << 2) + 1;
	n = m + it - 1;
	cform_(kcode + (k - 1) * 28, darray_1.darray, &c__6, &c__28, (ftnlen)
		28, (ftnlen)120);
	l = 36;
	i__1 = n;
	for (j = m; j <= i__1; ++j) {
	    fconv_(&aprnt2[j - 1], darray_1.darray, &l, &c__15, &c__7, (
		    ftnlen)120);
/* L298: */
	    l += 18;
	}
	cprint_(darray_1.darray, (ftnlen)120);
/* L299: */
    }
    goto L9000;

/* ...***** INVALID DIAGNOSTIC NUMBER ***** */

L500:
    niu = numerr[1];
    if (niu >= 3511 && niu <= 3599) {
	goto L810;
    }
    if (niu >= 5001 && niu <= 5999) {
	goto L820;
    }
    cform_("0       ****  ARELEM ERROR", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&numabs, darray_1.darray, &c__29, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L8000;

/* ...***** POCKET ERRORS(NUMBERS 3501-3510)  ***** */

L800:
    cform_("0       ****  ERROR NUMBER", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&numerr[1], darray_1.darray, &c__27, &c__5, (ftnlen)120);
    cform_("FROM SUBROUTINE POCKET ***", darray_1.darray, &c__33, &c__26, (
	    ftnlen)26, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L8000;
L810:
    cform_("0       ****  ERROR NUMBER", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&niu, darray_1.darray, &c__28, &c__5, (ftnlen)120);
    cform_("FROM SMIL OR SCON **", darray_1.darray, &c__35, &c__20, (ftnlen)
	    20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L8000;
L820:
    cform_("0       ****  ERROR NUMBER", darray_1.darray, &c__1, &c__26, (
	    ftnlen)26, (ftnlen)120);
    iconv_(&niu, darray_1.darray, &c__28, &c__5, (ftnlen)120);
    cform_("FROM SS - SYSTEM  **", darray_1.darray, &c__35, &c__20, (ftnlen)
	    20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L8000:
    i__1 = abs(numerr[1]);
    cleror_(&i__1);
L9000:
    return 0;
} /* apt331_ */

#undef istrup
#undef nmpnts
#undef isftyp
#undef isbtyp
#undef numerr
#undef savseq
#undef srfnme
#undef iedtor
#undef cutdat
#undef icscnt
#undef iqsdfg
#undef indexb
#undef xcoeff
#undef indexa
#undef irecrd
#undef canfrm
#undef aprnt2
#undef trans
#undef itlon
#undef isize
#undef itemp
#undef dpmax
#undef dtemp
#undef index
#undef elmax
#undef coeff
#undef area3
#undef isub
#undef mode
#undef ifar
#undef tau2
#undef tau1
#undef ifl4
#undef fwd
#undef igo
#undef vt
#undef sp
#undef tn
#undef sn
#undef is
#undef ti
#undef th
#undef te
#undef ta
#undef rc
#undef cc
#undef s
#undef r__
#undef h__


