/* APT311.f -- translated by f2c (version 20100827).
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
    doublereal ncfsto[3000], cscale;
} ncfsto_;

#define ncfsto_1 ncfsto_

struct {
    integer newsys, istand, imachn, ifirst, num, konsys[2];
} verson_;

#define verson_1 verson_

struct {
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, cutter, test,
	     cradus;
} r5axis_;

#define r5axis_1 r5axis_

struct {
    integer ivtflg, is, ir, il, ie, jsuber, iabove, nrecex, nreccl, ncflsv;
} i5axis_;

#define i5axis_1 i5axis_

struct {
    integer nrecc[21];
} nrecc_;

#define nrecc_1 nrecc_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;

/* *** SOURCE FILE : M0004201.V09   *** */


/* ......    FORTRAN SUBROUTINE APT311    11/69    RC */
/* PURPOSE      ALTERS EXFILE POINTS AND TOOL AXIS VECTORS */
/*              BY PRORATING THE DIFFERENCE BETWEEN THE */
/*              STARTING AND ENDING ANGLES ALONG THE SUM */
/*              OF CUT VECTORS FOR SWARF CUTTING. */
/* LINKAGE      CALL APT311 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES APT307,APT314,APT336,APT340,APT341 */

/* Subroutine */ int apt311_(void)
{
    /* Initialized data */

    static char left[8] = "LEFT    ";
    static char right[8] = "RIGHT   ";
    static char zsmall[8] = "ZSMALL  ";
    static char hcldat[8] = "CLDATA  ";
    static char hname[8] = "NONAME  ";
    static struct {
	integer e_1[8];
	doublereal e_2;
	} equiv_128 = { 1308622848, 1, 1308622848, 3, 1308622848, 6, 
		1308622848, 7, 0. };


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_121[450], equiv_124[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__;
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
    static doublereal xp3, yp3, zp3;
    static integer nwd;
#define ipx ((integer *)&editor_1 + 520)
#define ipy ((integer *)&editor_1 + 522)
#define ppt ((doublereal *)&editor_1 + 1325)
#define ptu ((doublereal *)&editor_1 + 282)
#define vun ((doublereal *)&editor_1 + 1020)
    static doublereal xlm, ylm, zlm;
#define pow1 ((doublereal *)&equiv_128)
#define pow3 ((doublereal *)&equiv_128 + 1)
#define pow6 ((doublereal *)&equiv_128 + 2)
#define pow7 ((doublereal *)&equiv_128 + 3)
    extern integer bcdf_(char *, ftnlen);
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
#define temp (equiv_124)
    static doublereal tcos, tsin;
#define ipow ((integer *)&equiv_128)
#define xnew ((doublereal *)&editor_1 + 1334)
#define tntm ((doublereal *)&editor_1 + 984)
#define ynew ((doublereal *)&editor_1 + 1339)
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt340_(void), apt341_(void), apt336_(integer 
	    *, char *, ftnlen);
    static doublereal tsin1;
    static integer jflag;
#define mcode ((integer *)&editor_1 + 2524)
#define nread ((integer *)&editor_1 + 750)
#define nrecf ((integer *)&editor_1 + 760)
#define param ((doublereal *)&editor_1 + 1273)
#define pname ((doublereal *)&editor_1 + 1324)
#define nrecl ((integer *)&editor_1 + 762)
#define nptab ((integer *)&editor_1 + 768)
#define ntape ((integer *)&editor_1 + 776)
    static integer isave;
#define itemp ((integer *)equiv_124)
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
    static doublereal xsave;
    static integer iflag1;
    static doublereal ysave, zsave;
#define nrecn1 ((integer *)&editor_1 + 774)
#define ntape1 ((integer *)&editor_1 + 782)
    static integer icorn1;
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
#define parray ((doublereal *)&editor_1 + 1274)
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
#define kkstak (equiv_121)
#define ppstak (equiv_121)
#define jrecrd ((integer *)&editor_1)
#define numwds ((integer *)&editor_1 + 5)
    static integer iclwrt;
    static doublereal recnos;
    static integer nreads, ntapes, nreccs, iclprt;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer irecsv;

/* ******************************************************************** */
/* *********************************************************************** */
/*     ***** COMMON-EQUIVALENCE BLOCK VARIABLES ***** */













/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







/* ...CL EDITOR ALPHA-NUMERIC LITERAL CONSTANTS. */







/* ...     TYPE DECLARATIONS AND MISCELLANEOUS EQUIVALENCES */




/* ...            SYSTEM I/O FILE NAMES */


/* *********************************************************************** */
/* ******************************************************************** */


/* ... */
/* ... */
    switch (i5axis_1.ivtflg) {
	case 1:  goto L10;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
    }
/* ...    PROCESS VTLAXS/ON AND INITIALIZE VARIABLES          ***** 1***** */
L10:
    iclwrt = *clwrt;
    icorn1 = 0;
    i5axis_1.jsuber = 0;
    iflag1 = 0;
    jflag = 0;
    recnos = record[1];
    nreads = *nread;
    ntapes = *ntape1;
    nreccs = nrecc_1.nrecc[*ntape1 - 1];
    isave = knumbr_1.k0;
    i5axis_1.ivtflg = knumbr_1.k2;
    iclprt = *clprt;
    *clwrt = knumbr_1.k0;
    *clprt = knumbr_1.k0;
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) == 0) {
	goto L40;
    }
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	goto L30;
    }
L20:
    i5axis_1.jsuber = 30001;
    goto L990;
L30:
    i5axis_1.jsuber = 30002;
    goto L990;
/* ...    CHECK FOR FLOATING POINT NUMBERS */
L40:
    for (i__ = 8; i__ <= 12; i__ += 2) {
	if (irecrd[i__ - 1] != (doublereal) knumbr_1.k1) {
	    goto L20;
	}
/* L50: */
    }
/* ...    GET STARTING ANGLE */
    r5axis_1.stang = record[8] / 57.2957795131f;
/* ...    IS TILT RIGHT OR LEFT */
    holfrm_(&record[6], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, left, (ftnlen)8, (ftnlen)8) == 0) {
	goto L60;
    }
    if (s_cmp(ctest, right, (ftnlen)8, (ftnlen)8) != 0) {
	goto L20;
    }
    r5axis_1.stang = -r5axis_1.stang;
/* ...    STORE HALF CUTTER DIAMETER AND CORNER RADIUS */
L60:
    r5axis_1.cutter = abs(record[10]) * .5f;
    r5axis_1.cradus = record[12];
    if (r5axis_1.cutter >= r5axis_1.cradus) {
	goto L70;
    }
    i5axis_1.jsuber = 30008;
/* ...    ERROR 30008 - CORNER RADIUS IS GREATER THAN THE CUTTER RADIUS. */
    goto L990;
/* ...    IS CUTTER ORIENTATION RIGHT OR LEFT */
L70:
    r5axis_1.zun = 1.f;
    holfrm_(&record[14], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, right, (ftnlen)8, (ftnlen)8) == 0) {
	goto L80;
    }
    if (s_cmp(ctest, left, (ftnlen)8, (ftnlen)8) != 0) {
	goto L20;
    }
    r5axis_1.zun = -1.f;
L80:
    r5axis_1.yun = 0.f;
    r5axis_1.xun = 0.f;
    i5axis_1.iabove = 0;
/* ...    LOOK FOR ZSMALL */
    if ((i__1 = *numwds - 14) < 0) {
	goto L110;
    } else if (i__1 == 0) {
	goto L90;
    } else {
	goto L20;
    }
L90:
    holfrm_(&record[16], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, zsmall, (ftnlen)8, (ftnlen)8) != 0) {
	goto L20;
    }
    if (r5axis_1.cradus == 0.f) {
	goto L100;
    }
    i5axis_1.jsuber = 30009;
/* ...    ERROR 30009 - CORNER RADIUS MUST BE ZERO WHEN USING ZSMALL. */
    goto L990;
/* ...    SET IABOVE=1 FOR ZSMALL, =0 FOR NOT */
L100:
    i5axis_1.iabove = 1;
L110:
    r5axis_1.tlngth = 0.f;
    *x1 = r5axis_1.xstart;
    *y1 = r5axis_1.ystart;
    r5axis_1.z1 = r5axis_1.zstart;
    xlm = r5axis_1.xstart;
    ylm = r5axis_1.ystart;
    zlm = r5axis_1.zstart;
    xsave = r5axis_1.xstart;
    ysave = r5axis_1.ystart;
    zsave = r5axis_1.zstart;
/* ...    CHECK FOR PREVIOUS MOTION RECORD */
    if (i5axis_1.nrecex > knumbr_1.k0) {
	return 0;
    }
    i5axis_1.jsuber = 30005;
/* ...    ERROR 30005 - A VTLAXS COMMAND WAS GIVEN WITHOUT A */
/* ...               PREVIOUS MOTION OR FROM COMMAND. */
    goto L990;
/* ... */
/* ... */
/* ... */
/* ... */
L200:
    if (isave == knumbr_1.k1) {
	goto L210;
    }
    isave = knumbr_1.k1;
    jflag = knumbr_1.k1;
    *x2 = record[4];
    *y2 = record[5];
    r5axis_1.z2 = record[6];
/* ...    CALCULATE TOTAL LENGTH OF MOVES */
L210:
    i__1 = *numwds;
    for (i__ = 5; i__ <= i__1; i__ += 7) {
	r5axis_1.xd = record[i__ - 1] - *x1;
	r5axis_1.yd = record[i__] - *y1;
	r5axis_1.zd = record[i__ + 1] - r5axis_1.z1;
/* Computing 2nd power */
	d__1 = r5axis_1.xd;
/* Computing 2nd power */
	d__2 = r5axis_1.yd;
/* Computing 2nd power */
	d__3 = r5axis_1.zd;
	r5axis_1.tlngth += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	xlm = *x1;
	ylm = *y1;
	zlm = r5axis_1.z1;
	*x1 = record[i__ - 1];
	*y1 = record[i__];
	r5axis_1.z1 = record[i__ + 1];
	if (iflag1 == knumbr_1.k0) {
	    goto L220;
	}
	iflag1 = knumbr_1.k0;
	xp3 = *x1;
	yp3 = *y1;
	zp3 = r5axis_1.z1;
L220:
	;
    }
    return 0;
/* ... */
/* ... */
/* ... */
/* ...    IS THIS VTLAXS/OFF */
L300:
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	goto L310;
    }
    if (s_cmp(ctest, holrth_1.on, (ftnlen)8, (ftnlen)8) != 0) {
	goto L20;
    }
    i5axis_1.jsuber = 30003;
/* ...    ERROR 30003 - TWO VTLAXS/ON COMMANDS GIVEN WITHOUT A */
/*                     VTLAXS/OFF  BETWEEN THEM. */
    goto L990;
/* ...    VTLAXS/OFF. SAVE ENDING ANGLE */
L310:
    irecsv = nrecc_1.nrecc[0];
    if (irecrd[7] != (doublereal) knumbr_1.k1) {
	goto L20;
    }
    r5axis_1.endang = record[8] / 57.2957795131f;
    i5axis_1.ie = nrecc_1.nrecc[0] + knumbr_1.k1;
/* ...    IS TILT RIGHT OR LEFT */
    holfrm_(&record[6], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, left, (ftnlen)8, (ftnlen)8) == 0) {
	goto L320;
    }
    if (s_cmp(ctest, right, (ftnlen)8, (ftnlen)8) != 0) {
	goto L20;
    }
    r5axis_1.endang = -r5axis_1.endang;
L320:
    r5axis_1.dang = r5axis_1.endang - r5axis_1.stang;
    r5axis_1.dlngth = 0.f;
    if (jflag == knumbr_1.k1) {
	goto L330;
    }
    i5axis_1.jsuber = 30010;
/* ...    ERROR 30010 - NO MOTION BETWEEN A VTLAXS/ON AND VTLAXS/OFF */
    goto L990;
/* ... */
/* ... */
/* ... */
/* ... */
/* ...    CALCULATE VTLAXS REVISION OF POINT JUST PRIOR       ***** 5***** */
/* ...    TO VTLAXS/ON */
L330:
    *x1 = xsave;
    *y1 = ysave;
    r5axis_1.z1 = zsave;
    tsin = sin(r5axis_1.stang);
    tsin1 = abs(tsin);
    tcos = cos(r5axis_1.stang);
    r5axis_1.xcv = *x2 - *x1;
    r5axis_1.ycv = *y2 - *y1;
    r5axis_1.zcv = r5axis_1.z2 - r5axis_1.z1;
    *x2 = *x1;
    *y2 = *y1;
    r5axis_1.z2 = r5axis_1.z1;
    apt341_();
    if (i5axis_1.jsuber != knumbr_1.k0) {
	goto L990;
    }
/* ...    POSITION EXFILE TO THE MOTION RECORD PRIOR */
/* ...    TO THE VTLAXS/ON STATEMENT */
    *clwrt = iclwrt;
    *clprt = iclprt;
    i5axis_1.ivtflg = 6;
    itemp[0] = bcdf_(hcldat, (ftnlen)4);
    itemp[1] = bcdf_(hcldat + 4, (ftnlen)4);
    record[0] = *temp;
    record[1] = recnos;
    record[2] = *pow6;
    record[3] = *pow1;
    itemp[0] = bcdf_(holrth_1.goto__, (ftnlen)4);
    itemp[1] = bcdf_(holrth_1.goto__ + 4, (ftnlen)4);
    record[4] = *temp;
    record[5] = 0.f;
    itemp[0] = bcdf_(hname, (ftnlen)4);
    itemp[1] = bcdf_(hname + 4, (ftnlen)4);
    record[6] = *temp;
    record[7] = 0.f;
    record[8] = 0.f;
    *branch = 2;
    return 0;

/* ...   GENERATE FIRST POINT OF VTLAXIS */

L600:
    *nread = nreads;
    *ntape1 = ntapes;
    nrecc_1.nrecc[*ntape1 - 1] = nreccs - 1;
    record[2] = *pow7;
    record[3] = *pow3;
    record[4] = r5axis_1.xcc;
    record[5] = r5axis_1.ycc;
    record[6] = r5axis_1.zcc;
    record[7] = r5axis_1.xta;
    record[8] = r5axis_1.yta;
    record[9] = r5axis_1.zta;
    i5axis_1.ivtflg = 4;
    *branch = 2;
    return 0;
/* ... */
/* ...    PROCESS RECORDS AFTER VTLAXS/ON.                    ***** 6***** */
L400:
    holfrm_(origin, ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.from, (ftnlen)8, (ftnlen)8) != 0) {
	goto L410;
    }
/* ...    FROM */
    i5axis_1.jsuber = 30004;
/* ...    ERROR 30004 - A FROM COMMAND WAS GIVEN BETWEEN A VTLAXS/ON */
/* ...               COMMAND AND ITS CORRESPONDING VTLAXS/OFF COMMAND. */
    goto L990;
L410:
    i__1 = *numwds;
    for (i__ = 5; i__ <= i__1; i__ += 7) {
	*x2 = record[i__ - 1];
	*y2 = record[i__];
	r5axis_1.z2 = record[i__ + 1];
/* ...    CALCULATE NEW CUTTER LOCATION AND TLAXIS (GOTO) */
	apt340_();
	if (i5axis_1.jsuber != knumbr_1.k0) {
	    goto L990;
	}
	record[i__ - 1] = r5axis_1.xcc;
	record[i__] = r5axis_1.ycc;
	record[i__ + 1] = r5axis_1.zcc;
	record[i__ + 2] = r5axis_1.xta;
	record[i__ + 3] = r5axis_1.yta;
	record[i__ + 4] = r5axis_1.zta;
	*x1 = *x2;
	*y1 = *y2;
/* L420: */
	r5axis_1.z1 = r5axis_1.z2;
    }
    return 0;
/* ... */
/* ... */
/* ... */
L500:
    holfrm_(&record[4], ctest, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(ctest, holrth_1.off, (ftnlen)8, (ftnlen)8) == 0) {
	goto L510;
    }
    i5axis_1.ivtflg = knumbr_1.k4;
    return 0;
L510:
    i5axis_1.ivtflg = knumbr_1.k1;
    return 0;
L990:
    apt336_(&i5axis_1.jsuber, "APT311  ", (ftnlen)8);
/* ...    POSITION EXFILE TO THE RECORD FOLLOWING VTLAXS/ON */
    i5axis_1.ivtflg = knumbr_1.k1;
    *clwrt = iclwrt;
    *clprt = iclprt;
    return 0;
} /* apt311_ */

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
#undef parray
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
#undef itemp
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
#undef ipow
#undef temp
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
#undef pow7
#undef pow6
#undef pow3
#undef pow1
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


