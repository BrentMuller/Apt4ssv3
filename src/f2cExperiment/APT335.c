/* APT335.f -- translated by f2c (version 20100827).
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

struct {
    integer kflags[5];
} kflags_;

#define kflags_1 kflags_

struct {
    char all[8], circle[8], fini[8], from[8], godlta[8], goto__[8], indirp[8],
	     indirv[8], modify[8], mirror[8], same[8], transl[8], xyrot[8], 
	    yzplan[8], zxplan[8], xyplan[8], cut[8], dntcnt[8], intol[8], 
	    outtol[8], kutter[8], ovplot[8], copy[8], on[8], off[8], dummy5[8]
	    , dummy6[8], dummy7[8], dummy8[8], dummy9[8];
} holrth_;

#define holrth_1 holrth_

struct {
    doublereal ncfsto[60000], cscale;
} ncfsto_;

#define ncfsto_1 ncfsto_

struct {
    integer nrecc[21];
} nrecc_;

#define nrecc_1 nrecc_

/* Table of constant values */

static integer c__30034 = 30034;
static integer c__30014 = 30014;
static integer c__1 = 1;
static integer c__8 = 8;
static integer c__30013 = 30013;
static integer c__30017 = 30017;
static integer c__30015 = 30015;
static integer c__30016 = 30016;
static integer c__30018 = 30018;
static integer c__2 = 2;
static integer c__10 = 10;
static integer c__14 = 14;
static integer c__6 = 6;
static integer c__20 = 20;
static integer c__5 = 5;
static integer c__25 = 25;
static integer c__30019 = 30019;
static integer c__12 = 12;
static integer c__26 = 26;
static integer c__4 = 4;
static integer c__30 = 30;

/* *** SOURCE FILE : M0004202.V09   *** */

/* ......    FORTRAN SUBROUTINE APT335    11/69    RC */
/*  PURPOSE     TO PERFORM THE LOGIC NECESSARY TO IMPLEMENT COPY */
/*              AND SET UP THE TRANSFORMATION MATRIX, TMATRX */

/*  CALLING SEQUENCE  CALL APT335 */

/*  CALLED BY   APT301 */

/*  SUBSIDIARIES   APT302, APT305, APT306, APT307, APT308, APT315 */


/* Subroutine */ int apt335_(void)
{
    /* Initialized data */

    static char ifmt13[6] = " COPY ";
    static char ifmt14[20] = " HAS BEEN COMPLETED ";
    static char ifmt17[12] = " BEGIN PASS ";
    static char ifmt18[12] = " THRU COPY  ";
    static char index[8] = "INDEX   ";
    static integer nocpsv = 0;
    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_123 = { 1308622848, 0, 0. };


    /* System generated locals */
    integer i__1;
    doublereal d__1;
    static doublereal equiv_120[450];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, j, k;
#define x0 ((doublereal *)&editor_1 + 1330)
#define x1 ((doublereal *)&editor_1 + 1331)
#define x2 ((doublereal *)&editor_1 + 1332)
#define x3 ((doublereal *)&editor_1 + 1333)
#define y0 ((doublereal *)&editor_1 + 1335)
#define y1 ((doublereal *)&editor_1 + 1336)
#define y2 ((doublereal *)&editor_1 + 1337)
#define y3 ((doublereal *)&editor_1 + 1338)
#define dc ((doublereal *)&editor_1 + 1254)
#define ax ((doublereal *)&editor_1 + 1251)
#define ay ((doublereal *)&editor_1 + 1253)
#define dx ((doublereal *)&editor_1 + 1255)
#define dy ((doublereal *)&editor_1 + 1256)
#define tl ((doublereal *)&editor_1 + 1329)
#define nx ((integer *)&editor_1 + 530)
#define ny ((integer *)&editor_1 + 532)
    static integer io;
#define an1 ((doublereal *)&editor_1 + 536)
#define an2 ((doublereal *)&editor_1 + 537)
#define ax0 ((doublereal *)&editor_1 + 1250)
#define ay0 ((doublereal *)&editor_1 + 1252)
#define pt0 ((doublereal *)&editor_1 + 279)
#define nx0 ((integer *)&editor_1 + 2526)
#define nx1 ((integer *)&editor_1 + 2528)
#define nx2 ((integer *)&editor_1 + 2530)
#define ny0 ((integer *)&editor_1 + 2536)
#define nx4 ((integer *)&editor_1 + 2532)
#define nx5 ((integer *)&editor_1 + 2534)
#define ny1 ((integer *)&editor_1 + 2538)
#define ny2 ((integer *)&editor_1 + 2540)
#define ny4 ((integer *)&editor_1 + 2542)
#define ny5 ((integer *)&editor_1 + 2544)
    static integer nwd;
#define ipx ((integer *)&editor_1 + 520)
#define ipy ((integer *)&editor_1 + 522)
#define ppt ((doublereal *)&editor_1 + 1325)
#define ptu ((doublereal *)&editor_1 + 282)
#define vun ((doublereal *)&editor_1 + 1020)
#define ncfl ((integer *)&editor_1 + 764)
#define cmat ((doublereal *)&editor_1 + 539)
#define ntab ((integer *)&editor_1 + 1940)
#define indn ((integer *)&editor_1 + 1190)
#define delx ((doublereal *)&editor_1 + 1257)
#define dely ((doublereal *)&editor_1 + 1258)
#define cntm ((doublereal *)&editor_1 + 551)
#define ierr ((integer *)&editor_1 + 2518)
#define amtr ((doublereal *)&editor_1 + 500)
#define cont ((doublereal *)&editor_1 + 587)
#define ipow ((integer *)&equiv_123)
#define zero ((doublereal *)&equiv_123)
#define xnew ((doublereal *)&editor_1 + 1334)
#define tntm ((doublereal *)&editor_1 + 984)
#define ynew ((doublereal *)&editor_1 + 1339)
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt302_(void), apt305_(void), apt306_(
	    doublereal *, doublereal *, doublereal *), apt314_(integer *, 
	    integer *), apt336_(integer *, char *, ftnlen), apt308_(
	    doublereal *, doublereal *);
#define mcode ((integer *)&editor_1 + 2524)
#define nread ((integer *)&editor_1 + 750)
#define nrecf ((integer *)&editor_1 + 760)
    static doublereal radin;
#define param ((doublereal *)&editor_1 + 1273)
#define pname ((doublereal *)&editor_1 + 1324)
#define nrecl ((integer *)&editor_1 + 762)
#define nptab ((integer *)&editor_1 + 768)
#define ntape ((integer *)&editor_1 + 776)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
#define indxn ((integer *)&editor_1 + 772)
    static char ctest[8];
#define icopy ((integer *)&editor_1 + 1188)
#define indxr ((integer *)&editor_1 + 770)
#define seqno ((doublereal *)&editor_1 + 264)
#define nnnnn ((integer *)&editor_1 + 752)
#define indxs ((integer *)&editor_1 + 944)
#define count ((doublereal *)&editor_1 + 590)
#define kplot ((integer *)&editor_1 + 570)
#define jcopy ((integer *)&editor_1 + 1928)
#define npwds ((integer *)&editor_1 + 766)
#define kcopy ((integer *)&editor_1 + 1930)
#define nocpy ((integer *)&editor_1 + 2070)
#define empty ((doublereal *)&editor_1 + 473)
#define clprt ((integer *)&kflags_1)
#define clwrt ((integer *)&kflags_1 + 1)
#define nrecn1 ((integer *)&editor_1 + 774)
#define ntape1 ((integer *)&editor_1 + 782)
#define empty2 ((doublereal *)&editor_1 + 1328)
#define empty3 ((doublereal *)&editor_1 + 1340)
#define branch ((integer *)&editor_1 + 1076)
#define ncamra ((integer *)&editor_1 + 524)
#define indtab ((integer *)&editor_1 + 1196)
#define nclend ((integer *)&editor_1 + 778)
#define tabind ((doublereal *)&editor_1 + 598)
#define irecrd ((doublereal *)&editor_1)
#define mattab ((doublereal *)&editor_1 + 286)
#define irecni ((integer *)&editor_1 + 1926)
#define ipltab ((integer *)&editor_1 + 668)
#define tapflg ((integer *)&kflags_1 + 3)
#define record ((doublereal *)&editor_1)
#define lokate ((integer *)&editor_1 + 2522)
#define amttab ((doublereal *)&editor_1 + 286)
#define itrafl ((integer *)&kflags_1 + 4)
#define iclwas ((integer *)&editor_1 + 1186)
#define indtbs ((integer *)&editor_1 + 784)
#define nrecno ((integer *)&editor_1 + 526)
#define mltflg ((integer *)&editor_1 + 748)
#define nrecls ((integer *)&editor_1 + 780)
#define istflg ((integer *)&editor_1 + 948)
#define cntmat ((doublereal *)&editor_1 + 551)
#define maxcop ((integer *)&editor_1 + 1934)
#define idplot ((integer *)&editor_1 + 514)
#define amatrx ((doublereal *)&editor_1 + 500)
#define origin ((doublereal *)&editor_1 + 971)
#define tramat ((doublereal *)&editor_1 + 1021)
#define indxno ((integer *)&editor_1 + 1516)
#define iploti ((integer *)&editor_1 + 518)
#define iplwas ((integer *)&editor_1 + 1924)
#define savseq ((doublereal *)&editor_1 + 476)
#define partno ((doublereal *)&editor_1 + 267)
#define ncsmax ((integer *)&editor_1 + 2066)
#define itrunc ((integer *)&editor_1 + 2520)
#define nletrs ((integer *)&editor_1 + 1938)
#define lprint ((integer *)&editor_1 + 1932)
#define lvlcpy ((integer *)&editor_1 + 2068)
#define multax ((integer *)&editor_1 + 1936)
#define clplot ((integer *)&kflags_1 + 2)
#define pprint ((doublereal *)&editor_1 + 972)
#define currnt ((integer *)&editor_1 + 512)
#define icpysw ((integer *)&editor_1 + 950)
#define iplotx ((integer *)&editor_1 + 1522)
#define tmatrx ((doublereal *)&editor_1 + 984)
#define kkstak (equiv_120)
#define ppstak (equiv_120)
#define jrecrd ((integer *)&editor_1)
#define numwds ((integer *)&editor_1 + 5)
    static integer cpyend[6]	/* was [2][3] */;
    static doublereal amatsv[36]	/* was [3][4][3] */;
    static integer lvltmp;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer icount;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer mattmp;


/*     THE FOLLOWING PROGRAM IS THE EXECUTIVE ROUTINE FOR THE CLTAPE */
/*     EDITOR.IT HAS THREE FUNCTIONS */
/*     TO PROVIDE A VERIFICATION LISTING OF THE CLFILE, INCLUDING ERROR */
/*     DIAGNOSTICS */
/*     TO PROCESS COPY AND VTLAXS COMMANDS */
/*     TO PROVIDE THE BASE STRUCTURE FOR ANY FUTURE PLOTTING PROGRAMS */

/*     THE EXECUTION OF A PART PROGRAM RESULTS IN THE PREPARATION OF */
/*     EXFILE. THE CLEDITOR USES EXFILE AS INPUT TO PREPARE THE */
/*     CLFILE. THE FORMAT OF EXFILE IS NOT IDENTICAL TO THE CLFILE. */


/*     ***** COMMON-EQUIVALENCE BLOCK VARIABLES ***** */









/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







/* ...CL EDITOR ALPHA-NUMERIC LITERAL CONSTANTS. */






/* ...     TYPE DECLARATIONS AND MISCELLANEOUS EQUIVALENCES */





/* ...     SYSTEM I/O FILE NAMES */







/* ...     ***** COPY COMMAND PROCESSING ROUTINE ***** */

/* ...     IF AN AERR RECORD HAS BEEN ENCOUNTERED DURING THIS COPY LOOP */
/*        THIS SECTION SETS FLAGS TO BYPASS COPY PROCESSING */

    if (*nocpy == 0 && nocpsv == 0) {
	goto L3005;
    }
    lvltmp = *lvlcpy - 1;
    if (lvltmp < 0) {
	goto L3002;
    }
    nocpsv = *nocpy;
    if (lvltmp == 0) {
	*nocpy = 0;
    }
    if (nocpsv == 0) {
	goto L3005;
    }
    *lvlcpy = lvltmp;
L3002:
    *istflg = 3;
    *ncfl = 1;
    *nrecl = 1;
    *icopy = 0;
    apt336_(&c__30034, "APT335  ", (ftnlen)8);
    *icpysw = 0;
    goto L3963;




/*     THIS SECTION PROCESSES THE COPY INSTRUCTION. THE PROGRAM IS SETUP */

/*     TO PERFORM THREE LEVELS OF NESTED COPIES.THE ONLY LIMITATION ON */

/*     THIS IS MAXCOP AND THE AMOUNT OF STORAGE PROVIDED FOR AMATRX, */

/*     CNTMAT,COUNT,INDXNO,AND IRECNI. */

/*     FOR EACH ADDITIONAL NEST AMATRX AND CNTMAT EACH MUST BE INCREASED */

/*     BY 12. COUNT,INDXNO,AND IRECNI EACH MUST BE INCREASED BY 1. */

/*     ALSO MAXCOP MUST BE INCREASED BY 1. */

/*     AMATRX IS THE MATRIX DEFINED BY EACH COPY AS IT IS SENSED AND IS */

/*     SET UP BY XYROT,SAME,OR MODIFY INSTRUCTIONS. */
/*     CNTMAT IS THE CURRENT RESULTANT COPY MATRIX. */
/*     COUNT IS THE NUMBER OF TIMES A COPY IS TO LOOP. */
/*     TMATRXIS THE COMBINATION OF ALL MATRICES PRESENTLY IN EFFECT. */
/*     INDXNO IS THE NUMBER OF THE COPY JUST SETUP. */
/*     IRECNI IS THE RECORD NUMBER OF THE CURRENT COPY. */
/*     CURRNT IS THE RECORD NUMBER OF THE INSTRUCTION JUST READ. */

/*     CHECK FOR VALID INDEX/N */
L3005:
    ncfsto_1.cscale = 1.f;
    *icpysw = 0;

    i__1 = *ntab;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	if ((integer) irecrd[4] - indtab[i__ - 1] == 0) {
	    goto L3029;
	}
/* L3010: */
    }

/*     INDEX NUMBER NOT FOUND IN INDEX TABLE */

    apt336_(&c__30014, "APT335  ", (ftnlen)8);
/* L3021: */
    goto L3963;

/*     SAVE INDEX POINTER */

L3029:
    *indxs = (i__ + 1) / 2;
    *indxn = i__;
    *indxr = i__ + 1;

/* ...  CHECK IF RECORD IS AN INDEX/N,NOMORE */
/* ...  COMMAND THAT TERMINATES A COPY LOOP */

    if (*branch == 7 && (*icopy == 0 || record[4] != amttab[((*icopy << 2) + 
	    4 << 2) - 20])) {
	return 0;
    }
    if (*branch == 7) {
	goto L3735;
    }

/*     DETERMINE WHAT COPY MODIFIER IS INVOLVED */

/* L3030: */
    holfrm_(&record[6], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.transl, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3131;
    }

    if (s_cmp(ctest, holrth_1.xyrot, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3361;
    }

    if (s_cmp(ctest, holrth_1.same, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3501;
    }

    holfrm_(&irecrd[6], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.modify, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3580;
    }

    if (s_cmp(ctest, holrth_1.mirror, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3670;
    }

/*     IN CORRECT MODIFIER IN A COPY COMMAND */
    apt336_(&c__30013, "APT335  ", (ftnlen)8);

/*     TURN OFF WRITING OF CLTAPE,PLOT-TURN ON CLPRNT */
L3100:
    *clwrt = knumbr_1.k0;
    *clplot = 0;
    *clprt = 1;
    *icopy = knumbr_1.k0;
    *istflg = 3;
    goto L3963;
/*     THIS SECTION SETS UP THE TRANSL PARAMETERS */
/*     CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L3131:
    if (jrecrd[5] - 12 < 0) {
	goto L3701;
    }
/*     CHECK IF THE PARAMETER N IS ZERO OR MINUS */
    if (record[14] < .5) {
	goto L3704;
    }
/*     SET UP THE TRANSL MATRIX */

    amatrx[9] = record[8];
    amatrx[10] = record[10];
    amatrx[11] = record[12];
    amatrx[0] = 1.;
    amatrx[3] = 0.;

    amatrx[6] = 0.;

    amatrx[1] = 0.;

    amatrx[4] = 1.;

    amatrx[7] = 0.;

    amatrx[2] = 0.;
    amatrx[5] = 0.;
    amatrx[8] = 1.;
    icount = (integer) record[14];
    goto L3710;
/*     THIS SECTION SETS UP THE XYROT PARAMETERS */
/*     CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L3361:
    if (jrecrd[5] - knumbr_1.k8 < 0) {
	goto L3701;
    }
/*     CHECK IF THE PARAMETER N IS ZERO OR MINUS */
    if (record[10] < .5) {
	goto L3704;
    }
/*     SET UP THE XYROT MATRIX */
    radin = record[8] * .0174532925;
    amatrx[0] = cos(radin);

    amatrx[3] = -sin(radin);

    amatrx[6] = 0.;

    amatrx[9] = 0.;

    amatrx[1] = sin(radin);

    amatrx[4] = cos(radin);

    amatrx[7] = 0.;

    amatrx[10] = 0.;
    amatrx[2] = 0.;
    amatrx[5] = 0.;
    amatrx[8] = 1.;
    amatrx[11] = 0.;
    icount = (integer) record[10];
    goto L3710;
/*     THIS SECTION SETS UP THE SAME PARAMETERS */
/*     CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L3501:
    if (jrecrd[5] - knumbr_1.k6 < 0) {
	goto L3701;
    }
/*     CHECK IF THE PARAMETER N IS ZERO OR MINUS */
    if (record[8] < .5) {
	goto L3704;
    }
/*     SET UP THE SAME MATRIX */


    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {

/* L3520: */
	    amatrx[i__ + j * 3 - 4] = 0.;
	}
    }

    amatrx[0] = 1.;

    amatrx[4] = 1.;

    amatrx[8] = 1.;

    icount = (integer) record[8];
    goto L3710;
/*     THIS SECTION SETS UP THE MODIFY PARAMETERS */
/*     CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L3580:
    if (jrecrd[5] != 20) {
	goto L3701;
    }
/*     CHECK IF THE PARAMETER N IS ZERO OR MINUS */
    if (record[22] < .5) {
	goto L3704;
    }
/*     SET UP MODIFY MATRIX */
    k = 9;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    k += knumbr_1.k1;

/* L3640: */
	    amatrx[i__ + j * 3 - 4] = record[k - 1];
	}
    }

    icount = (integer) record[22];
/*      CHECK FOR A SCALE MATRIX */
    for (i__ = 1; i__ <= 3; ++i__) {
	if ((d__1 = amatrx[i__ + 8], abs(d__1)) - 1e-6 <= 0.) {
	    goto L3653;
	} else {
	    goto L3659;
	}
L3653:
	;
    }
    for (i__ = 2; i__ <= 3; ++i__) {
	if (amatrx[0] - amatrx[i__ + i__ * 3 - 4] != 0.) {
	    goto L3659;
	} else {
	    goto L3656;
	}
L3656:
	;
    }
    if (ncfsto_1.cscale - 1. != 0.) {
	goto L3658;
    } else {
	goto L3657;
    }
L3657:
    ncfsto_1.cscale = amatrx[0];
    goto L3710;
L3658:
    ncfsto_1.cscale *= amatrx[0];
    goto L3710;
L3659:
    ncfsto_1.cscale = 1.;
    goto L3710;
/*     THIS SECTION SETS UP THE MIRROR PARAMETERS (NOT OPERATIVE) */
/*     PRINT DIAGNOSTIC FOR USING A MIRROR MODIFIER */

L3670:
    apt336_(&c__30017, "APT335  ", (ftnlen)8);
    *clprt = 1;
    goto L3963;

/* ....    ERROR - INCORRECT NUMBER OF PARAMETERS */
L3701:
    apt336_(&c__30015, "APT335  ", (ftnlen)8);
    goto L3100;

/* ....    ERROR - PARAMETER  N  IS ZERO OR MINUS */
L3704:
    apt336_(&c__30016, "APT335  ", (ftnlen)8);
    goto L3100;

/*     THE TRANSL,XYROT,SAME,MODIFY,OR MIRROR TYPE COPY HAS BEEN SET UP */
/*     SET RECORD NO. OF CURRENT COPY EQUAL TO RECORD NUMBER OF CURRENT */
/*     INSTRUCTION */

L3710:
    if (*icopy == 0) {
	goto L3770;
    }
    if (record[4] == amttab[((*icopy << 2) + 4 << 2) - 20]) {
	goto L3730;
    }
    if (indtab[*indxr - 1] < nrecc_1.nrecc[0]) {
	goto L3770;
    }

/*     ERROR - THIS COPY NOT CURRENT COPY OR INDEX NOT IN PROPER PLACE */

L3719:
    apt336_(&c__30018, "APT335  ", (ftnlen)8);
    goto L3100;

/*     THIS COPY HAS CURRENT INDEX NO. - CHECK RECORD NO IN CASE THERE */
/*     ARE MULTIPLE COPIES TO THE SAME INDEX */

L3730:
    if ((doublereal) nrecc_1.nrecc[0] != mattab[((*icopy << 2) + 4 << 2) - 19]
	    ) {
	goto L3770;
    }

/*     THIS IS THE CURRENT COPY - REDUCE COUNT */

L3735:
    amttab[((*icopy << 2) + 4 << 2) - 17] += -1.;
    if ((d__1 = amttab[((*icopy << 2) + 4 << 2) - 17]) < 0.) {
	goto L3719;
    } else if (d__1 == 0) {
	goto L3740;
    } else {
	goto L3760;
    }
L3740:
    i__ = (integer) amttab[((*icopy << 2) + 4 << 2) - 20];
    if (*clprt != 1) {
	goto L3743;
    }
    io = jrecrd[3];
    iconv_(&io, darray_1.darray, &c__2, &c__8, (ftnlen)120);
    cform_(".", darray_1.darray, &c__10, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(ifmt13, darray_1.darray, &c__14, &c__6, (ftnlen)6, (ftnlen)120);
    iconv_(&i__, darray_1.darray, &c__20, &c__5, (ftnlen)120);
    cform_(ifmt14, darray_1.darray, &c__25, &c__20, (ftnlen)20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L3743:
    --(*icopy);
    if (*icopy < 0) {
	goto L3719;
    } else if (*icopy == 0) {
	goto L3745;
    } else {
	goto L3750;
    }

/* ...     DECREASE COPY LEVEL MARKER AND RESET FLAGS PROPERLY */
L3745:
    *istflg = 1;
    *nread = 1;
    --(*lvlcpy);
/* ...     IF COPY LEVEL IS ZERO, RESET FLAGS FOR INITIAL COPY STORAGE */
L3750:
    if (*lvlcpy < 0) {
	goto L3751;
    } else if (*lvlcpy == 0) {
	goto L3752;
    } else {
	goto L3753;
    }
L3751:
    *lvlcpy = 0;
L3752:
    *nread = 1;
    *istflg = 3;
    *ncfl = 1;
    *nrecl = 1;
    goto L3757;
/* ...     RESET FLAGS FOR STORAGE STARTING AFTER THIS COPY COMMAND */
L3753:
    *ncfl = cpyend[(*icopy + 1 << 1) - 1];
L3757:
    apt305_();
    if (*nread < 3 && nrecc_1.nrecc[0] != cpyend[(*icopy + 1 << 1) - 2]) {
	nrecc_1.nrecc[0] = cpyend[(*icopy + 1 << 1) - 2];
    }
    nrecc_1.nrecc[0] = cpyend[(*icopy + 1 << 1) - 2];
    goto L3962;

/*     MAKE ANOTHER PASS THROUGH THIS COPY LOOP - UPDATE MATRIX IN MATTAB */

L3760:
    apt306_(&amttab[((*icopy << 2) + 1 << 2) - 20], &amttab[((*icopy << 2) + 
	    1 << 2) - 20], &amatsv[((*icopy << 2) + 1) * 3 - 15]);
    goto L3820;

/*     FIRST TIME FOR THIS COPY - STORE IN NCFSTO */

L3770:
    if (*istflg != 1) {
	goto L3800;
    }
    if (*ncfl + (*numwds + 3) >= *ncsmax) {
	goto L3800;
    }
/* L3775: */
    k = *numwds + 3;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ncfsto_1.ncfsto[*ncfl - 1] = irecrd[i__ - 1];
/* L3780: */
	++(*ncfl);
    }
    k = *ncfl - *numwds - 1;
    ncfsto_1.ncfsto[k - 1] = (doublereal) (jrecrd[5] + *npwds * 1000);
    *npwds = *numwds + 3;
    ++(*nrecl);

/*     ADVANCE COPY LEVEL INDICATOR (ICOPY) */

L3800:
    ++(*icopy);
    cpyend[(*icopy << 1) - 2] = nrecc_1.nrecc[0];
    cpyend[(*icopy << 1) - 1] = *ncfl;

    if (*maxcop - *icopy >= 0) {
	goto L3810;
    } else {
	goto L3801;
    }

/*     OVER 3 LEVES OF NESTED COPIES */

L3801:
    apt336_(&c__30019, "APT335  ", (ftnlen)8);
    goto L3100;

/*     STORE MATRIX FOR NEW COPY IN MATTAB */

L3810:
    if (*clwrt == 0) {
	goto L3100;
    }
    apt308_(&amttab[((*icopy << 2) + 1 << 2) - 20], amatrx);
    amttab[((*icopy << 2) + 4 << 2) - 17] = (doublereal) icount;
    mattab[((*icopy << 2) + 4 << 2) - 18] = (doublereal) indtab[*indxr - 1];
    mattab[((*icopy << 2) + 4 << 2) - 19] = (doublereal) nrecc_1.nrecc[0];
    mattab[((*icopy << 2) + 4 << 2) - 20] = (doublereal) indtab[*indxn - 1];
    apt308_(&amatsv[((*icopy << 2) + 1) * 3 - 15], amatrx);
    count[*icopy - 1] = (doublereal) icount;

/*     GENERATE PRODUCT TRANSFORMATION MATRIX FOR THIS COPY PASS --- */

L3820:
    apt305_();

/*     NOW WE SET UP THE POINTER TO THE CLFILE STORAGE AREA AND BACK UP */
/*      THE INPUT TAPE (IF NECESSARY) */

/*     NRECF = RECORD NUMBER OF FIRST RECORD IN CLFILE STORAGE (NCFSTO) */
/*     NRECL = RECORD NUMBER OF LAST RECORD IN CLFILE STORAGE */
/*     NRECC = RECORD NUMBER OF CURRENT RECORD */
/*     MATTAB(1,4,ICOPY) = INDEX NUMBER */
/*     MATTAB(2,4,ICOPY) = RECORD NUMBER OF COPY */
/*     MATTAB(3,4,ICOPY) = RECORD NUMBER OF INDEX */
/*     ICOPY =  COPY LEVEL */
/*     NCFL  =  CLFILE STORAGE AREA POINTER   NCFSTO(NCFL) */

/* L3900: */
    if (*clprt == 1) {
	apt302_();
    }
    if (mattab[((*icopy << 2) + 4 << 2) - 18] > (doublereal) (*nrecl)) {
	goto L3950;
    }
    *nread = knumbr_1.k3;
    *istflg = knumbr_1.k2;
    *ncfl = indtbs[*indxs - 1];
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] / 1000);
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] + 3 - k * 1000);
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	irecrd[i__ - 1] = ncfsto_1.ncfsto[*ncfl - 1];
/* L3905: */
	++(*ncfl);
    }
    irecrd[2] = *zero;
    *numwds = k - 3;
L3910:
    holfrm_(record, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, index, (ftnlen)8, (ftnlen)8) == 0 && (d__1 = irecrd[4] - 
	    mattab[((*icopy << 2) + 4 << 2) - 20], abs(d__1)) < .1f) {
	goto L3960;
    }
    *icpysw = -1;
    goto L3963;
L3950:
    mattmp = (integer) mattab[((*icopy << 2) + 4 << 2) - 18];
    nrecc_1.nrecc[0] = mattmp;
    apt314_(ntape, nrecc_1.nrecc);
    goto L3910;
L3960:
    i__ = (integer) (count[*icopy - 1] - amttab[((*icopy << 2) + 4 << 2) - 17]
	     + 1.);
    k = (integer) amttab[((*icopy << 2) + 4 << 2) - 20];
    if (*clprt != 1) {
	goto L3962;
    }
    io = jrecrd[3];
    iconv_(&io, darray_1.darray, &c__2, &c__8, (ftnlen)120);
    cform_(".", darray_1.darray, &c__10, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(ifmt17, darray_1.darray, &c__14, &c__12, (ftnlen)12, (ftnlen)120);
    iconv_(&i__, darray_1.darray, &c__26, &c__4, (ftnlen)120);
    cform_(ifmt18, darray_1.darray, &c__30, &c__12, (ftnlen)12, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L3962:
    *icpysw = 1;
L3963:
    return 0;
} /* apt335_ */

#undef numwds
#undef jrecrd
#undef ppstak
#undef kkstak
#undef tmatrx
#undef iplotx
#undef icpysw
#undef currnt
#undef pprint
#undef clplot
#undef multax
#undef lvlcpy
#undef lprint
#undef nletrs
#undef itrunc
#undef ncsmax
#undef partno
#undef savseq
#undef iplwas
#undef iploti
#undef indxno
#undef tramat
#undef origin
#undef amatrx
#undef idplot
#undef maxcop
#undef cntmat
#undef istflg
#undef nrecls
#undef mltflg
#undef nrecno
#undef indtbs
#undef iclwas
#undef itrafl
#undef amttab
#undef lokate
#undef record
#undef tapflg
#undef ipltab
#undef irecni
#undef mattab
#undef irecrd
#undef tabind
#undef nclend
#undef indtab
#undef ncamra
#undef branch
#undef empty3
#undef empty2
#undef ntape1
#undef nrecn1
#undef clwrt
#undef clprt
#undef empty
#undef nocpy
#undef kcopy
#undef npwds
#undef jcopy
#undef kplot
#undef count
#undef indxs
#undef nnnnn
#undef seqno
#undef indxr
#undef icopy
#undef indxn
#undef ntape
#undef nptab
#undef nrecl
#undef pname
#undef param
#undef nrecf
#undef nread
#undef mcode
#undef area3
#undef area2
#undef area1
#undef ynew
#undef tntm
#undef xnew
#undef zero
#undef ipow
#undef cont
#undef amtr
#undef ierr
#undef cntm
#undef dely
#undef delx
#undef indn
#undef ntab
#undef cmat
#undef ncfl
#undef vun
#undef ptu
#undef ppt
#undef ipy
#undef ipx
#undef ny5
#undef ny4
#undef ny2
#undef ny1
#undef nx5
#undef nx4
#undef ny0
#undef nx2
#undef nx1
#undef nx0
#undef pt0
#undef ay0
#undef ax0
#undef an2
#undef an1
#undef ny
#undef nx
#undef tl
#undef dy
#undef dx
#undef ay
#undef ax
#undef dc
#undef y3
#undef y2
#undef y1
#undef y0
#undef x3
#undef x2
#undef x1
#undef x0


