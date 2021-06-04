/* APT301.f -- translated by f2c (version 20100827).
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
    integer newsys, istand, imachn, ifirst, num, konsys[2];
} verson_;

#define verson_1 verson_

struct {
    integer nrecc[21];
} nrecc_;

#define nrecc_1 nrecc_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, vcuter, test,
	     cradus;
} r5axis_;

#define r5axis_1 r5axis_

struct {
    integer ivtflg, is, ir, il, ie, jsuber, iabove, nrecex, nreccl, ncflsv;
} i5axis_;

#define i5axis_1 i5axis_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__45 = 45;
static integer c__20 = 20;
static integer c__48 = 48;
static integer c__4 = 4;
static integer c__30032 = 30032;
static integer c__11 = 11;
static integer c__36 = 36;
static integer c_n1 = -1;
static integer c__30024 = 30024;
static integer c__8 = 8;
static integer c_n3 = -3;
static integer c__30039 = 30039;
static integer c__30031 = 30031;
static integer c__30037 = 30037;
static integer c__30036 = 30036;
static integer c__30018 = 30018;
static integer c__30040 = 30040;
static integer c__30025 = 30025;
static integer c__30026 = 30026;
static integer c__30020 = 30020;
static integer c__30021 = 30021;
static integer c__30006 = 30006;
static integer c__30012 = 30012;
static integer c__30011 = 30011;
static integer c__30035 = 30035;
static integer c__2 = 2;
static integer c__10 = 10;
static integer c__14 = 14;
static integer c__16 = 16;
static integer c__31 = 31;
static integer c__6 = 6;

/* *** SOURCE FILE : M0011533.W02   *** */


/* .....FORTRAN SUBROUTINE                   APT301 */
/* ********************************************************* */
/* ******                                            ******* */
/* ******               CLTAPE EDITOR                ******* */
/* ******                                            ******* */
/* ********************************************************* */
/* IBFTC A301    FULIST,REF */
/* PURPOSE      TO CONTROL OPERATION OF THE GROUP OF SUBROUTINES */
/*              COMPRISING THE CLTAPE EDITOR FUNCTION. */
/* LINKAGE      CALL APT301 */
/* ARGUMENTS    NONE - ALL THE DATA REQUIRED BY APT301 IS ON */
/*              EXFILE. */
/* SUBSIDIARIES APT302, APT303, APT304, APT305, APT306, APT307, */
/*              APT308, APT309, APT310, APT311, APT312, APT313, */
/*              APT314, APT315, APT318, APT319, APT320, APT321, */
/*              APT322, APT325, APT326, APT327, APT328, APT329, */
/*              ALT330, APT331, APT332 */
/* ...NOTE   THIS ROUTINE HAS BEEN MODIFIED SO THAT IT NO LONGER */
/*          USES MIXED ARITHMETIC (DOUBLE PRECISION NORMALIZED, */
/*          DOUBLE PRECISION UNNORMALIZED,AND INTEGER ) */
/* Subroutine */ int apt301_(void)
{
    /* Initialized data */

    static char ifmt1[20] = "** START CLEDITOR **";
    static char ifmt3[20] = "** END   CLEDITOR **";
    static char endind[8] = "NOMORE  ";
    static char cpflid[4] = "CPFL";
    static char iblk2[2] = "  ";
    static char enorm[8] = "NORMAL  ";
    static char vtlaxs[8] = "VTLAXS  ";
    static char cldata[8] = "CLDATA  ";
    static char clock[8] = " CLOCK  ";
    static char hmacr[16] = "MACRO PROCESSING";
    static char hends[4] = "ENDS";
    static char hbigin[6] = "BEGINS";
    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_123 = { 1308622848, 0, 0. };


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    static doublereal equiv_120[450], equiv_124[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, m, j1;
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
    static integer knt, icp3;
    extern integer bcdf_(char *, ftnlen);
    static integer jbck;
#define ncfl ((integer *)&editor_1 + 764)
#define cmat ((doublereal *)&editor_1 + 539)
#define ntab ((integer *)&editor_1 + 1940)
#define indn ((integer *)&editor_1 + 1190)
    static integer cpfl[48];
    extern /* Subroutine */ int help_(void);
#define delx ((doublereal *)&editor_1 + 1257)
#define dely ((doublereal *)&editor_1 + 1258)
#define cntm ((doublereal *)&editor_1 + 551)
#define ierr ((integer *)&editor_1 + 2518)
#define amtr ((doublereal *)&editor_1 + 500)
#define cont ((doublereal *)&editor_1 + 587)
    static integer icut;
#define zero ((doublereal *)&equiv_123)
#define xnew ((doublereal *)&editor_1 + 1334)
#define tntm ((doublereal *)&editor_1 + 984)
#define ynew ((doublereal *)&editor_1 + 1339)
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt310_(integer *, doublereal *), apt312_(
	    void), apt302_(void), apt314_(integer *, integer *), apt313_(void)
	    , apt303_(doublereal *, doublereal *, doublereal *), apt304_(
	    doublereal *, doublereal *, doublereal *), apt336_(integer *, 
	    char *, ftnlen), apt315_(doublereal *, doublereal *), apt311_(
	    void), apt335_(void), apt305_(void), aread_(integer *, integer *, 
	    integer *, integer *, integer *);
#define mcode ((integer *)&editor_1 + 2524)
    static integer i34flg;
#define nread ((integer *)&editor_1 + 750)
#define nrecf ((integer *)&editor_1 + 760)
#define param ((doublereal *)&editor_1 + 1273)
#define pname ((doublereal *)&editor_1 + 1324)
#define nrecl ((integer *)&editor_1 + 762)
#define nptab ((integer *)&editor_1 + 768)
    static integer jtape;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define ntape ((integer *)&editor_1 + 776)
#define dtemp (equiv_124)
#define itemp ((integer *)equiv_124)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
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
#define izero ((integer *)&equiv_123)
    static integer iclsv, ivcut, ncssv;
    extern /* Subroutine */ int tapop_(integer *, integer *);
    static integer nlast;
#define nrecn1 ((integer *)&editor_1 + 774)
#define ntape1 ((integer *)&editor_1 + 782)
    extern /* Subroutine */ int cnvrt3_(integer *);
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
#define clplot ((integer *)&kflags_1 + 2)
#define nletrs ((integer *)&editor_1 + 1938)
#define lprint ((integer *)&editor_1 + 1932)
#define lvlcpy ((integer *)&editor_1 + 2068)
#define multax ((integer *)&editor_1 + 1936)
#define pprint ((doublereal *)&editor_1 + 972)
#define currnt ((integer *)&editor_1 + 512)
#define icpysw ((integer *)&editor_1 + 950)
#define iplotx ((integer *)&editor_1 + 1522)
#define tmatrx ((doublereal *)&editor_1 + 984)
#define kkstak (equiv_120)
    static integer ppflag;
#define ppstak (equiv_120)
#define jrecrd ((integer *)&editor_1)
#define numwds ((integer *)&editor_1 + 5)
    extern /* Subroutine */ int cprint_(char *, ftnlen), holfrm_();
    static integer iplflg, icrdef, itrcpy;
    static doublereal tscale, seqsto;
    static integer icldwr;


/*     THE FOLLOWING PROGRAM IS THE EXECUTIVE ROUTINE FOR THE CLTAPE */
/*     EDITOR.IT HAS THREE FUNCTIONS */
/*     TO PROVIDE A VERIFICATION LISTING OF THE CLFILE,INCLUDING ERROR */
/*     DIAGNOSTICS */
/*     TO PROCESS COPY AND VTLAXS COMMANDS */
/*     TO PROVIDE THE BASE STRUCTURE FOR ANY FUTURE PLOTTING PROGRAMS */

/*     THE EXECUTION OF A PART PROGRAM RESULTS IN THE PREPARATION OF */
/*     EXFILE.  THE CLEDITOR USES EXFILE  AS INPUT TO PREPARE THE */
/*     CLFILE.  THE FORMAT OF EXFILE IS NOT IDENTICAL TO THE CLFILE. */


/*     ***** COMMON-EQUIVALENCE BLOCK VARIABLES ***** */










/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







/* ...CL EDITOR ALPHA-NUMERIC LITERAL CONSTANTS. */








/* ...     TYPE DECLARATIONS AND MISCELLANEOUS EQUIVALENCES */






/* ...            SYSTEM I/O FILE NAMES */


/* ...                SYSTEM I/O FILES */








/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/*     PRINT WHAT SECTION THIS IS */

/* L10: */
    cform_("1", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(ifmt1, darray_1.darray, &c__45, &c__20, (ftnlen)20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

/* ... READ CPFILE TO OBTAIN CLPRNT AND APTIII CONVERSION REQUIREMENTS */

    aread_(&symfil_1.cpfile, &c__1, cpfl, &c__48, &i5axis_1.ir);
    holfrm_(cpfl, ctest, &c__1, &c__4, &nwd, (ftnlen)8);
    if (s_cmp(ctest, cpflid, (ftnlen)4, (ftnlen)4) == 0 && cpfl[1] == 1) {
	goto L6;
    }

    apt336_(&c__30032, "APT301  ", (ftnlen)8);
    return 0;

/* ... INITIALIZE ALL VARIABLES */

L6:
    *clprt = cpfl[3];
    iclsv = 1;
    *clwrt = 1;
    *iplwas = 0;
    *clplot = 0;
/* ...     CHECK CLPRNT REQUIREMENTS */
    if (*clprt == 0) {
	goto L35;
    }
    cform_("0TAPENO/ISN", darray_1.darray, &c__1, &c__11, (ftnlen)11, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L45;
L35:
    cform_("*** NO CLPRNT HAS BEEN REQUESTED ***", darray_1.darray, &c__11, &
	    c__36, (ftnlen)36, (ftnlen)120);
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
/* ...     CLEAR INDEX NUMBERS FROM TABLE */
L45:
    for (i__ = 1; i__ <= 80; ++i__) {
/* L80: */
	tabind[i__ - 1] = (doublereal) knumbr_1.k0;
    }
/* L90: */
    count[0] = (doublereal) knumbr_1.k0;
    ivcut = 0;
    icut = 0;
    iplflg = 0;
    i5axis_1.ivtflg = 1;
    i5axis_1.nrecex = 0;
    i5axis_1.nreccl = 0;
    i5axis_1.ncflsv = 1;
    *istflg = 3;
    *mltflg = 1;
    *nread = 1;
    *indxs = 0;
    *nrecf = 0;
    *nrecl = 0;
    *ncfl = 1;
    *npwds = 0;
    *ntab = 1;
    *nptab = 0;
    *maxcop = 3;
    *ncamra = 1;
    *multax = 0;
    *iclwas = 0;
    idplot[0] = 0;
    *iploti = 0;
    *lvlcpy = 0;
    *nocpy = 0;
    *icopy = 0;
    *ncsmax = 60000;
    ncssv = *ncsmax;
    icrdef = 0;
    itrcpy = 0;
    *currnt = 0;
    *itrafl = 0;
    icp3 = -1;
    ncfsto_1.cscale = 1.f;
    tscale = 1.f;
    ppflag = knumbr_1.k0;
    j1 = knumbr_1.k1;
    apt314_(&c_n1, &c_n1);
    i__ = 1;
    apt314_(&symfil_1.exfile, &i__);
    *ntape = symfil_1.exfile;
    *ntape1 = knumbr_1.k1;
    symfil_1.nfil12 = 12;
    symfil_1.nfil13 = 13;

/* **   SET = 1 IF NEW SYSTEM CLTAPE RECS. TO BE WRITTEN */
    verson_1.newsys = knumbr_1.k0;

/* **   SET = 1 IF APT III STANDARD CLTAPE TO BE WRITTEN */
    verson_1.istand = knumbr_1.k0;

/* **   SET = 1 IF A MACHINE P. P. COMMAND DETECTED IN A-301 */
    verson_1.imachn = knumbr_1.k0;

/* **   FLAG FOR LMCT */
    verson_1.ifirst = knumbr_1.k1;

/* **   INDEX INTO TABLE OF AVAILABLE POST PROCESSORS */
    verson_1.num = knumbr_1.k1;

/* **   CONTROL SYSTEM NAME FROM W(5), MACHIN P.P.C. RECORD. */
    verson_1.konsys[0] = 1308622848;
    verson_1.konsys[1] = knumbr_1.k0;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L110: */
	nrecc_1.nrecc[i__ - 1] = knumbr_1.k0;
    }
    *nrecn1 = 1;

/*     READ EXFILE OR OLD CLFILE OR NCFSTO */

L190:
    icrdef = knumbr_1.k0;
    if (i5axis_1.ivtflg == 6) {
	goto L8025;
    }
    switch (*nread) {
	case 1:  goto L210;
	case 2:  goto L200;
	case 3:  goto L220;
	case 4:  goto L240;
    }
L200:
    --nrecc_1.nrecc[*ntape1 - 1];
    goto L211;
L210:
    ++nrecc_1.nrecc[*ntape1 - 1];
L211:
    apt314_(ntape, &nrecc_1.nrecc[*ntape1 - 1]);
    goto L270;
L220:
    if (*ncfl >= ncssv - 1) {
	goto L229;
    }
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] / 1000);
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] + 3 - k * 1000);
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	irecrd[i__ - 1] = ncfsto_1.ncfsto[*ncfl - 1];
/* L222: */
	++(*ncfl);
    }
    irecrd[2] = *zero;
    *numwds = k - 3;
    goto L270;
L229:
    *nread = knumbr_1.k1;
L230:
    if (*ntape1 == knumbr_1.k1) {
	goto L235;
    }
    i__ = *ncfl - *npwds + 1;
    k = (integer) (ncfsto_1.ncfsto[i__ - 1] / 1000);
    nrecc_1.nrecc[*ntape1 - 1] = k;
    apt314_(ntape, &k);
    if (irecrd[0] - ncfsto_1.ncfsto[i__ - 2] == 0. && irecrd[1] - 
	    ncfsto_1.ncfsto[i__ - 1] == 0.) {
	goto L235;
    }

L232:
    i__ = (integer) amttab[((*icopy << 2) + 4 << 2) - 20];
    apt336_(&c__30024, "APT301  ", (ftnlen)8);
    help_();
    goto L341;

L235:
    nrecc_1.nrecc[0] = *nrecl;
    apt314_(ntape, nrecl);
    if (irecrd[0] - ncfsto_1.ncfsto[*nrecls - 1] == 0. && irecrd[1] - 
	    ncfsto_1.ncfsto[*nrecls] == 0.) {
	goto L190;
    }
    goto L232;
L240:
    if (*ncfl > knumbr_1.k0) {
	goto L245;
    }
    *nread = knumbr_1.k2;
    goto L230;
L245:
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] / 1000);
    k = (integer) (ncfsto_1.ncfsto[*ncfl + 1] + 3 - k * 1000);
    j = (integer) (ncfsto_1.ncfsto[*ncfl + 1] / 1000);
    m = *ncfl;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	irecrd[i__ - 1] = ncfsto_1.ncfsto[m - 1];
/* L246: */
	++m;
    }
    irecrd[2] = *zero;
    *numwds = k - knumbr_1.k3;
    *ncfl -= j;

L270:
    apt310_(branch, record);

/*     BRANCH ACCORDING TO RECORD NAME */

    switch (*branch) {
	case 1:  goto L300;
	case 2:  goto L2000;
	case 3:  goto L1400;
	case 4:  goto L3000;
	case 5:  goto L1450;
	case 6:  goto L300;
	case 7:  goto L6000;
	case 8:  goto L1300;
	case 9:  goto L300;
	case 10:  goto L1200;
	case 11:  goto L7000;
	case 12:  goto L1100;
	case 13:  goto L7000;
	case 14:  goto L1600;
	case 15:  goto L8100;
	case 16:  goto L8000;
	case 17:  goto L5000;
	case 18:  goto L9100;
	case 19:  goto L5500;
	case 20:  goto L9500;
	case 21:  goto L4000;
	case 22:  goto L9600;
	case 23:  goto L8200;
	case 24:  goto L9800;
	case 25:  goto L9810;
	case 26:  goto L9000;
    }

/*     THIS IS THE COMMON RETURN POINT FOR ALL SECTIONS OF THE CL EDITOR */
/*     AND THE POINT AT WHICH THE RECORDS ARE WRITTEN ON CLFILE IF CLWRT */
/*     =1 AND PRINTED IF CLPRT=1 */


/* ...  WRITE CLFILE,VLFILE AND CLFIL3 IF THE APPROPRIATE FLAGS ARE SET */

L300:
    seqsto = record[1];
    if (*branch != 3) {
	*savseq = record[1];
    }
    if (*clwrt == 1 && cpfl[5] == 1) {
	apt312_();
    }
    goto L335;
L330:
    seqsto = record[1];
L335:
    if (*clwrt == 1 && cpfl[4] == 1) {
	cnvrt3_(&cpfl[6]);
    }
    goto L337;
L336:
    seqsto = record[1];
    *savseq = record[1];
L337:
    if (*clprt == 1 && *branch != 21) {
	apt302_();
    }
    record[1] = seqsto;
    if (i5axis_1.ivtflg == 6 && *istflg != knumbr_1.k1) {
	goto L8025;
    }


/*     IF FINI START OVER FOR NEXT PART PROGRAM */

L340:
    holfrm_(record, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.fini, (ftnlen)8, (ftnlen)8) != 0) {
	goto L350;
    }
L341:
    if (*nrecn1 != 1 && *clwrt == 1 && cpfl[5] == 0) {
	apt312_();
    }
    if (*nrecn1 != 1 && *clwrt == 1) {
	apt313_();
    }
    if (*clwrt == 1 && cpfl[4] == 0) {
	cnvrt3_(&cpfl[6]);
    }
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(ifmt3, darray_1.darray, &c__45, &c__20, (ftnlen)20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    tapop_(&symfil_1.exfile, &c_n3);
    tapop_(&symfil_1.nfil12, &c_n3);
    tapop_(&symfil_1.nfil13, &c_n3);
    return 0;

/*     CHECK RECORD FOR LAST ONE FROM AN OLD CLFILE */

L350:
    if (*ntape1 == knumbr_1.k1) {
	goto L380;
    }
    if ((i__1 = *nclend - jrecrd[3]) < 0) {
	goto L400;
    } else if (i__1 == 0) {
	goto L360;
    } else {
	goto L380;
    }
L360:
    apt314_(&c_n1, &c_n1);
    *ntape = symfil_1.exfile;
    *ntape1 = knumbr_1.k1;

/* ...     IF WE ARE IN COPY LOOP, STORE RECORD IN NCFSTO */
L380:
    if (*istflg != knumbr_1.k1) {
	goto L190;
    }

/* IF WE ARE IN CLDAT/OFF-ON PART, NO COPY STORAGE */
    if (cpfl[4] == knumbr_1.k0) {
	goto L190;
    }

/* ...     IF FIRST PASS INSIDE VTLAXS LOOP, NO COPY STORAGE */
    holfrm_(record, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (i5axis_1.ivtflg == 2 || s_cmp(ctest, vtlaxs, (ftnlen)8, (ftnlen)8) == 
	    0) {
	goto L190;
    }

/* ...     IF THIS IS CLDATA RECORD, CHECK FOR TRACUT TRANSFORMATION */
    if (itrcpy != knumbr_1.k1) {
	goto L387;
    }
    itrcpy = 0;
    goto L190;

L385:
    holfrm_(record, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (i5axis_1.ivtflg == 2 || s_cmp(ctest, vtlaxs, (ftnlen)8, (ftnlen)8) == 
	    0) {
	goto L190;
    }
    itrcpy = 1;
L387:
    if (*ncfl + (*numwds + 3) < *ncsmax) {
	goto L390;
    }
    if (*ncfl + (*numwds + 3) >= *ncsmax) {
	apt336_(&c__30039, "APT301  ", (ftnlen)8);
    }
    *istflg = knumbr_1.k2;
    ncssv = *ncfl;
    goto L397;

/*     MOVE RECORD TO STORAGE (NCFSTO) */

L390:
    *nrecls = *ncfl;
    *nrecl = nrecc_1.nrecc[0];
    k = *numwds + 3;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ncfsto_1.ncfsto[*ncfl - 1] = irecrd[i__ - 1];
/* L395: */
	++(*ncfl);
    }
    if (*ncfl >= *ncsmax) {
	apt336_(&c__30039, "APT301  ", (ftnlen)8);
    }
    ncfsto_1.ncfsto[*nrecls + 1] = (doublereal) (jrecrd[5] + *npwds * 1000);
    *npwds = *numwds + 3;

/* ..      CHECK FOR A TRACUT TRANSFORMATION OF THIS CLDATA RECORD */
L397:
    if (itrcpy != knumbr_1.k1) {
	goto L190;
    }
    if (icrdef == knumbr_1.k1) {
	goto L2039;
    }
    goto L2100;

/*     THE LAST RECORD FROM THE OLD CLFILE WAS NOT FOUND */

L400:
    apt336_(&c__30031, "APT301  ", (ftnlen)8);
    goto L360;

/*     SAVE THE PARTNO BCD TEXT-TO BE PLOTTED IN THE SETUPP SUBROUTINE */

L1100:
    k = jrecrd[9] - 1;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1110: */
	partno[i__ - 1] = record[i__ + 5];
    }
    goto L300;
/*     SET THE MULTAX FLAG */
L1200:
    *multax = knumbr_1.k1;
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	*multax = 0;
    }
    goto L300;
/*     INSERT COMMAND */
L1300:
    goto L300;

/* ...     **** AERR PROCESSING **** */

L1400:
    *clwrt = knumbr_1.k1;
    if (jrecrd[7] < 0) {
	goto L1402;
    }
    if (i5axis_1.ivtflg == 2) {
	goto L1430;
    }
/* ...     SET FLAG IF COPY TRANSFORMATION SHOULD BE BYPASSED */
    if (*istflg < 3 || *icopy != 0) {
	*nocpy = 1;
    }
    if (*clprt == 0) {
	goto L1405;
    }
    if (jrecrd[3] != 2) {
	goto L300;
    }
    *clprt = iclsv;
L1402:
    if (*clprt == 0) {
	apt302_();
    }
    goto L300;
/* ...     TURN ON CLPRNT AND BACKSPACE TO LAST CLDATA RECORD */
L1405:
    for (jbck = 1; jbck <= 50; ++jbck) {
	--nrecc_1.nrecc[0];
	apt314_(ntape, nrecc_1.nrecc);
	holfrm_(record, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
	if (s_cmp(ctest, cldata, (ftnlen)8, (ftnlen)8) == 0 && jrecrd[7] != 1)
		 {
	    goto L1420;
	}
	if (s_cmp(ctest, clock, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L1425;
	}
/* L1410: */
    }

/* ...     START CLPRNT AT CL MOTION COMMAND AND ISSUE DIAGNOSTIC */
L1420:
    nrecc_1.nrecc[0] += -2;
L1425:
    apt336_(&c__30037, "APT301  ", (ftnlen)8);
    iclsv = 0;
    *clprt = 1;
    goto L190;

/* ...     IF VTLAXS LOOP, BACKSPACE TO VTLAXS/ON AND BYPASS TRANSFORMING */
L1430:
    i5axis_1.ivtflg = 1;
    apt336_(&c__30036, "APT301  ", (ftnlen)8);
    nrecc_1.nrecc[0] = i5axis_1.ir;
    apt314_(ntape, nrecc_1.nrecc);
    *clprt = 1;
    *branch = 16;
    goto L330;

/*        **** DYNDMP PROCESSING *** */

L1450:
    apt302_();
    goto L340;

/*     PPRINT-SAVE THE BCD TEXT */

L1600:
    if (idplot[0] == knumbr_1.k2) {
	goto L300;
    }
    i__1 = *numwds;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
/* L1620: */
	pprint[i__ - 1] = record[i__ + 3];
    }
    goto L300;
/*     FINI. PREPARE FOR END OF FILE EXIT FROM CLTAPE EDITOR */
/*     IF CLFILE WAS WRITTEN, PLACE AN EOF ON IT */
/*      RETURN TO BEGINNING OF CLTAPE EDITOR. */

/*     CLDATA.THIS SECTION WILL PROCESS THE CUTTER LOCATION POINTS.IT WIL */
/*     L TRANSFORM THE POINTS IF A COPY IS IN EFFECT.IT WILL ALSO PLOT TH */
/*     E TOOL PATH IF THE PLOTTING ROUTINES ARE IN THE SYSTEM. */

L2000:
    if (jrecrd[7] - knumbr_1.k1 != 0) {
	goto L2070;
    }
    if (icut != 0) {
	goto L190;
    }
/*     STORE THE ORIGIN NAME IF THIS IS AN INITIAL CLDATA RECORD */
    *origin = record[4];
    holfrm_(origin, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.godlta, (ftnlen)8, (ftnlen)8) == 0) {
	goto L336;
    }

/*     IF A CANONICAL FORM IS     INCLUDED CHECK FOR CIRCLE */

    if (jrecrd[5] == knumbr_1.k2) {
	goto L300;
    }
    if (jrecrd[17] != knumbr_1.k4) {
	goto L300;
    }

/* ...     CHECK FOR A COPY OR TRACUT TRANSFORMATION. IF BOTH ARE ON, */
/*        STORE THE ORIGINAL CANONICAL FORM BEFORE TRANSFORMING */

    if (*icopy > knumbr_1.k0) {
	goto L2040;
    }
    if (*itrafl != knumbr_1.k1) {
	goto L300;
    }
    if (*istflg == knumbr_1.k3) {
	goto L2040;
    }
    icrdef = knumbr_1.k1;
    goto L385;
L2039:
    icrdef = knumbr_1.k0;
L2040:
    apt303_(&record[9], tmatrx, &record[9]);
    apt304_(&record[12], tmatrx, &record[12]);
    apt315_(&record[12], &record[12]);
    record[15] = ncfsto_1.cscale * tscale * record[15];
    goto L300;
L2070:
    holfrm_(origin, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.godlta, (ftnlen)8, (ftnlen)8) != 0) {
	goto L2090;
    }
    if (icut != 0) {
	goto L190;
    }
    goto L336;
/* ...    SET VTLAXS FLAGS AND SAVE LAST SET OF COORDINATES */
L2090:
    if (ivcut != 1) {
	goto L2091;
    }
    ivcut = 2;
    goto L190;
L2091:
    i5axis_1.nrecex = 1;
    r5axis_1.xstart = record[*numwds - 3];
    r5axis_1.ystart = record[*numwds - 2];
    r5axis_1.zstart = record[*numwds - 1];
    if (icut != 0) {
	goto L190;
    }
/* ...    CHECK IF VTLAXS IS IN EFFECT */
    if (i5axis_1.ivtflg == knumbr_1.k1) {
	goto L2095;
    }
    apt311_();
L2095:
    itemp[0] = bcdf_(holrth_1.dummy9, (ftnlen)4);
    itemp[1] = bcdf_(holrth_1.dummy9 + 4, (ftnlen)4);
    *origin = *dtemp;

/* ...     CHECK FOR A COPY OR TRACUT TRANSFORMATION. IF BOTH ARE ON, */
/*        STORE THE ORIGINAL CUTTER POINTS BEFORE TRANSFORMING */

L2097:
    if (*itrafl == knumbr_1.k1 && *istflg == knumbr_1.k1) {
	goto L385;
    }
    if (*itrafl == knumbr_1.k1) {
	goto L2100;
    }
    if (*icopy < 0) {
	goto L3719;
    } else if (*icopy == 0) {
	goto L300;
    } else {
	goto L2100;
    }

/*        CHECK FOR NO TOOL AXIS VECTOR TRANSFORMING */
L2100:
    if (*multax != knumbr_1.k1) {
	goto L2120;
    }
    i__1 = *numwds;
    for (i__ = 5; i__ <= i__1; i__ += 7) {
	apt303_(&record[i__ - 1], tmatrx, &record[i__ - 1]);
/*     TRANSFORM TOOL AXIS VECTOR */
	apt304_(&record[i__ + 2], tmatrx, &record[i__ + 2]);
/*     NORMALIZE VECTOR OUTPUT */
	apt315_(&record[i__ + 2], &record[i__ + 2]);
/* L2110: */
    }
    goto L300;


L2120:
    nlast = *numwds + 3;
    i__1 = nlast;
    for (i__ = 5; i__ <= i__1; i__ += 4) {
	apt303_(&record[i__ - 1], tmatrx, &record[i__ - 1]);
/* L2125: */
    }
    goto L300;

/* ...     *** COPY COMMAND PROCESSING *** */

/* ...     IF VTLAXS IS IN EFFECT ISSUE DIAGNOSTIC */
L3000:
    if (icp3 >= 0) {
	goto L4011;
    }
    if (i5axis_1.ivtflg == knumbr_1.k4) {
	goto L8010;
    }
    if (i5axis_1.ivtflg == knumbr_1.k2) {
	goto L330;
    }
    apt335_();
    if (*icpysw == 0) {
	goto L330;
    }
    if (*icpysw > 0) {
	goto L190;
    }
    goto L232;

/* ...     COPY LOGIC ERROR */
L3719:
    apt336_(&c__30018, "APT301  ", (ftnlen)8);
    goto L330;


/*     THIS SECTION PROCESSES THE CLFILE RECORD - CHECKS PARAMETERS FOR */
/*     VALIDITY AND POSITIONS THE OLD CLFILE IF NECESSARY */

L4000:
    apt302_();
/* ...     CHECK FOR A CLDAT/2 COMMAND - SET FLAG TO START SAVING CLFILE */
/* ...     WRITE IF XECUTION COMMAND CLDAT/START-NOMORE */
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest + 6, iblk2, (ftnlen)2, (ftnlen)2) != 0) {
	goto L4006;
    }
    if (s_cmp(ctest, endind, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(ctest, enorm,
	     (ftnlen)8, (ftnlen)8) == 0) {
	goto L4008;
    }
    icp3 = cpfl[4];
    cpfl[4] = 0;
    goto L4009;
L4008:
    cpfl[4] = icp3;
    icp3 = -1;
L4009:
    if (*icopy == 0 && *itrafl == 0) {
	goto L9000;
    }
L4011:
    apt336_(&c__30040, "APT301  ", (ftnlen)8);
    *itrafl = 0;
    tscale = 1.f;
    *icopy = 0;
    *icpysw = 0;
    *ncfl = 0;
    *nrecl = 0;
    goto L330;

L4006:
    icldwr = jrecrd[13];
    i34flg = jrecrd[17];
    if (icldwr == 1) {
	goto L4002;
    }
    if (icldwr == 2) {
	goto L4005;
    }
L4001:
    apt336_(&c__30025, "APT301  ", (ftnlen)8);
    goto L350;
/*     WRITE */
L4002:
    holfrm_(&irecrd[10], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	goto L4003;
    }
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	goto L4004;
    }
    goto L4001;
/*     ON */
L4003:
    if (i34flg == 3) {
	cpfl[4] = 1;
    }
    if (i34flg == 4) {
	cpfl[5] = 1;
    }
    goto L9000;
/*     OFF */
L4004:
    if (i34flg == 3) {
	goto L4007;
    }
    jrecrd[12] = 1308622848;
    jrecrd[13] = 2;
    cpfl[5] = 0;
    goto L190;
L4007:
    cpfl[4] = 0;
    goto L9000;
/*     READ */
L4005:
    if (i34flg != 4) {
	goto L4001;
    }
    if (jrecrd[19] == 1) {
	k = jrecrd[21];
    }
    holfrm_(&irecrd[10], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	k = 10000;
    }
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	goto L360;
    }
    *nclend = jrecrd[25];
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	*nclend = 99990000;
    }
    j = k;
    k /= 10000;
    jtape = jrecrd[9];
    if (jtape != 12 && jtape != 13) {
	goto L4001;
    }
    *ntape1 = jtape - 10;
    if (jtape == 12) {
	*ntape = symfil_1.nfil12;
    }
    if (jtape == 13) {
	*ntape = symfil_1.nfil13;
    }
    apt314_(&c_n1, &c_n1);
    switch (*nread) {
	case 1:  goto L4110;
	case 2:  goto L4110;
	case 3:  goto L4130;
	case 4:  goto L4130;
    }

/*     POSITION OLD CLFILE AND CHECK RECORD NUMBER */

L4110:
    nrecc_1.nrecc[*ntape1 - 1] = k;
    if (*istflg != knumbr_1.k1) {
	goto L4120;
    }
    if (*ncfl + (*numwds + 3) >= *ncsmax) {
	goto L4120;
    }
    *nrecls = *ncfl;
    *nrecl = nrecc_1.nrecc[0];
    k = *numwds + 3;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ncfsto_1.ncfsto[*ncfl - 1] = irecrd[i__ - 1];
/* L4115: */
	++(*ncfl);
    }
    ncfsto_1.ncfsto[*nrecls + 1] = (doublereal) (jrecrd[5] + *npwds * 1000);
    *npwds = k;
L4120:
    apt314_(ntape, &nrecc_1.nrecc[*ntape1 - 1]);
    if (jtape == 12) {
	symfil_1.nfil12 = *ntape;
    }
    if (jtape == 13) {
	symfil_1.nfil13 = *ntape;
    }
    if (j == 10000) {
	goto L270;
    }
    if (jrecrd[3] - j == 0) {
	goto L270;
    }

    apt336_(&c__30026, "APT301  ", (ftnlen)8);
    goto L360;
L4130:
    nrecc_1.nrecc[*ntape1 - 1] = k - 1;
    goto L190;

/*     THIS SECTION PROCESSES THE GEOMETRY ERROR RECORD */

L5000:
    *clwrt = 1;
    if (*clprt == 0) {
	apt302_();
    }
    goto L300;

/*     THIS SECTION PROCESSES THE ARLEM RECORD */

L5500:
    goto L300;

/*     THIS SECTION PROCESSES THE INDEX INSTRUCTION.IT ALSO SETS PLOT */
/*     FLAGS AND TESTS TO SEE IF THE PRESENT INDEX IS FOR A PLOT */

/*     CHECK FOR PLOT COMMANDS */

L6000:
    if (iplflg == 0) {
	goto L6020;
    }

/*     IS THIS INDEX NUMBER ASSOCIATED WITH A PLOT */

    i__1 = *nptab;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((integer) irecrd[4] - ipltab[i__ - 1] == 0) {
	    goto L300;
	}
/* L6010: */
    }

/*     NOW CHECK COPY COMMANDS INDEX TABLE */

L6020:
    if (*ntab > 160) {
	goto L6070;
    }
    holfrm_(&record[6], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (jrecrd[5] == 4 && s_cmp(ctest, endind, (ftnlen)8, (ftnlen)8) == 0) {
	goto L3000;
    }
    if (*ntab == 1) {
	goto L6031;
    }
    i__1 = *ntab;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	if ((integer) irecrd[4] == indtab[i__ - 1]) {
	    goto L6060;
	}
/* L6030: */
    }
L6031:
    indtab[*ntab - 1] = (integer) irecrd[4];
    indtab[*ntab] = nrecc_1.nrecc[0];
    i__ = (*ntab + 1) / 2;
    indtbs[i__ - 1] = *ncfl;
    *ntab += 2;
L6040:
    switch (*istflg) {
	case 1:  goto L6045;
	case 2:  goto L330;
	case 3:  goto L6050;
    }

/*        NESTED COPY ENCOUNTERED, INCREASE COPY LEVEL MARKER */
L6045:
    ++(*lvlcpy);
    goto L330;

/*     THIS IS THE FIRST INDEX/N COMMAND SET PARAMETERS TO STORE CLFILE */

L6050:
    if (*icopy != 0) {
	goto L330;
    }
    *istflg = 1;
    *lvlcpy = 1;
    goto L330;

/*     CHECK TO SEE IF A COPY IS IN EFFECT */

L6060:
    if (*icopy != 0) {
	goto L6040;
    }
    i__ = (integer) record[4];
    apt336_(&c__30020, "APT301  ", (ftnlen)8);
    goto L330;


/*     ERROR - INDEX TABLE FULL */

L6070:
    apt336_(&c__30021, "APT301  ", (ftnlen)8);
    goto L330;


/*     THIS SECTION SETS UP THE PLOT PARAMETERS */

L7000:
    if (jrecrd[7] == 2) {
	goto L300;
    }
    iplflg = 1;
    ++(*nptab);
    ipltab[*nptab - 1] = (integer) irecrd[4];
    goto L300;

/* ...     PROCESS THE VTLAXS COMMAND */

/*        CHECK FOR NO PREVIOUS MULTAX COMMAND */
L8000:
    if (*icopy != 0) {
	goto L300;
    }
    if (*multax == 1) {
	goto L8002;
    }
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	apt336_(&c__30006, "APT301  ", (ftnlen)8);
    }
    goto L330;

L8002:
    if (*clwrt == 0 && i5axis_1.ivtflg == 1 && *clprt == 0) {
	goto L300;
    }
    if (i5axis_1.ivtflg == knumbr_1.k2 || i5axis_1.ivtflg == knumbr_1.k4) {
	i5axis_1.ivtflg += knumbr_1.k1;
    }
    if (i5axis_1.ivtflg == 3 || i5axis_1.ivtflg == 5) {
	ivcut = 0;
    }
    apt311_();
    if (i5axis_1.ivtflg != 6) {
	goto L300;
    }
    goto L2000;
L8025:
    apt311_();
    goto L2097;
L8010:
    apt336_(&c__30012, "APT301  ", (ftnlen)8);
    goto L330;
L8020:
    apt336_(&c__30011, "APT301  ", (ftnlen)8);
    goto L330;
/*     PROCESS THE TRANS COMMAND */
L8100:
    goto L300;

/* ...  PROCESS CLPRNT/ON OR OFF RECORDS */

/* ...  CHECK VTLAXS FLAG */
L8200:
    if (i5axis_1.ivtflg == knumbr_1.k2) {
	goto L330;
    }
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	*clprt = knumbr_1.k1;
    }
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0 && cpfl[3] == 1)
	     {
	*clprt = 0;
    }
    goto L330;

/*     PROCESS POST PROCESSOR LIKE COMMANDS */

L9000:
    if (ppflag != knumbr_1.k1) {
	goto L300;
    }

/*      STACK THE RECORD */

    knt = *numwds + knumbr_1.k3;
    ++j1;
    if (j1 > 15 || knt > 30) {
	goto L9055;
    }
    i__1 = knt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ppstak[j1 + i__ * 15 - 16] = record[i__ - 1];
/* L9050: */
    }
    goto L350;

L9055:
    apt336_(&c__30035, "APT301  ", (ftnlen)8);
    goto L350;

/*      THIS SECTION PROCESSES THE TRACUT INSTRUCTION */

L9100:
    if (icp3 >= 0) {
	goto L4011;
    }
    if (*clwrt != knumbr_1.k1) {
	goto L330;
    }
    if (jrecrd[5] - knumbr_1.k2 == 0) {
	goto L9290;
    }
/* ...    CHECK IF VTLAXS IS IN EFFECT */
    if (i5axis_1.ivtflg == knumbr_1.k4) {
	goto L8020;
    }
    *itrafl = knumbr_1.k1;

/*      STORE TRACUT MATRIX FROM TAPE AND STORE BY COLUMNS */

    k = knumbr_1.k5;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    k += knumbr_1.k1;
/* L9180: */
	    tramat[i__ + j * 3 - 4] = record[k - 1];
	}
    }

/* L9190: */
    for (i__ = 1; i__ <= 3; ++i__) {
	if ((d__1 = tramat[i__ + 8], abs(d__1)) - 1e-6 <= 0.) {
	    goto L9210;
	} else {
	    goto L9270;
	}
L9210:
	;
    }

    for (i__ = 2; i__ <= 3; ++i__) {
	if (tramat[0] - tramat[i__ + i__ * 3 - 4] != 0.) {
	    goto L9270;
	} else {
	    goto L9240;
	}
L9240:
	;
    }

    tscale = tramat[0];
    goto L9300;

L9270:
    tscale = 1.f;
    goto L9300;

L9290:
    *itrafl = knumbr_1.k0;
    tscale = 1.f;

L9300:
    apt305_();
    goto L330;

/*     PROCESS THE HOLDPP RECORD */

L9500:
    ppflag = jrecrd[7];
    switch (ppflag) {
	case 1:  goto L9525;
	case 2:  goto L9508;
	case 3:  goto L9502;
	case 4:  goto L9506;
    }
L9502:
    if (*clprt == 0) {
	goto L350;
    }
    i__ = jrecrd[3];
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    iconv_(&i__, darray_1.darray, &c__2, &c__8, (ftnlen)120);
    cform_(".", darray_1.darray, &c__10, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(hmacr, darray_1.darray, &c__14, &c__16, (ftnlen)16, (ftnlen)120);
    cform_(hbigin, darray_1.darray, &c__31, &c__6, (ftnlen)6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L350;
L9506:
    if (*clprt == 0) {
	goto L350;
    }
    cform_(hmacr, darray_1.darray, &c__14, &c__16, (ftnlen)16, (ftnlen)120);
    cform_(hends, darray_1.darray, &c__31, &c__4, (ftnlen)4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L350;
L9508:

/*     UNSTACK THE RECORD */

    if (j1 == 0) {
	goto L350;
    }
    i__1 = j1;
    for (k = 1; k <= i__1; ++k) {
	record[0] = ppstak[k - 1];
	record[1] = ppstak[k + 14];
	irecrd[2] = *zero;
	*dtemp = kkstak[k + 29];
	*numwds = itemp[1];
	i__2 = *numwds;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    record[i__ + 2] = ppstak[k + (i__ + 3) * 15 - 16];
/* L9510: */
	}
	if (*clwrt == 1 && cpfl[5] == 1) {
	    apt312_();
	}
/* ---     CALL TO OUTPUT FEDRAT TO CLFIL3 */
	if (*clwrt == 1 && cpfl[4] == 1) {
	    cnvrt3_(&cpfl[6]);
	}
	if (*clprt == 1) {
	    apt302_();
	}
/* L9520: */
    }
/* ---     UNLOAD PP WORDS TO CLFILE DURING INDEX AND COPY */
    if (*istflg == 1) {
	apt314_(ntape, &nrecc_1.nrecc[*ntape1 - 1]);
    }
L9525:
    j1 = 0;
    goto L350;
/* **   PROCESS THE MACHINE POST PROCESSOR RECORD */

/* **   FLAG USED BY LMCT */
L9600:
    verson_1.imachn = knumbr_1.k1;

/* **   CONTROL SYSTEM NAME IN W(5) .  USED BY A400. */

    verson_1.konsys[0] = jrecrd[8];
    verson_1.konsys[1] = jrecrd[9];
    goto L300;

L9800:
    icut = 0;
    if ((i5axis_1.ivtflg == 2 || i5axis_1.ivtflg == 4) && ivcut == 0) {
	ivcut = 1;
    }
    goto L9000;
L9810:
    icut = 1;
    goto L9000;
} /* apt301_ */

#undef numwds
#undef jrecrd
#undef ppstak
#undef kkstak
#undef tmatrx
#undef iplotx
#undef icpysw
#undef currnt
#undef pprint
#undef multax
#undef lvlcpy
#undef lprint
#undef nletrs
#undef clplot
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
#undef izero
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
#undef itemp
#undef dtemp
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


