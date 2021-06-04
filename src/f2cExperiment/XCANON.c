/* XCANON.f -- translated by f2c (version 20100827).
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
    integer ntb, fpb, ppb, comn, cfb;
} stor_;

#define stor_1 stor_

struct {
    integer kcomt, kcomf;
    logical cilprt;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer iiiiii[53], ipage[32], iwrit;
} work_;

#define work_1 work_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__1 = 1;
static integer c__44 = 44;
static integer c__33 = 33;
static integer c__35 = 35;
static integer c__8 = 8;
static integer c__0 = 0;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0002657.V09   *** */

/* ---    IMPLEMENTATION DEPENDENT ROUTINES XCANON & INCAN */


integer xcanon_(integer *v)
{
    /* Initialized data */

    static integer incor[256] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0 };
    static integer locrec[256] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0 };
    static integer nfor[33] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0 };
    static integer nback[33] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0 };
    static integer maxpag = 0;
    static integer maxcor = 32;
    static integer maxfil = 256;
    static integer npgcnt = 0;
    static integer nzero = 0;
    static integer navail = 2;

    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer l;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
    static integer ip, ir, nn;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
    static integer nr, in1;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer loc;
    extern /* Subroutine */ int help_(void);
    static integer lnpg;
    extern /* Subroutine */ int aread_(integer *, integer *, doublereal *, 
	    integer *, integer *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer lenpag, ivpage, nfsave;
    extern /* Subroutine */ int awrite_(integer *, integer *, doublereal *, 
	    integer *, integer *);
    static integer nbsave;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer nowtop, nxslot;


/* ---    PURPOSE IS TO PROVIDE ACCESS TO CANON FILE ON DISK */
/* ---   INPUT V = VIRTUAL ADDRESS OF A CANONICAL FORM */
/*      OUTPUT XCANON = ACTUAL ADDRESS OF A CANONICAL FORM */
/* ---   (A CANONICAL FORM PAGE IS BROUGHT IN IF NECESSARY) */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*     ------------------- */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* ---      NFOR REPRESENT FORWARD POINTERS SHOWING PROGRESSIVELY */
/* ---      OLDER PAGES.   NFOR(1) IS NOT A CORE SLOT POINTER, BUT */
/* ---      AN INITIALIZING LOCATION FOR THE LIST POINTERS. */
/* ---      NBACK REPRESENTS BACKWARD POINTERS TO PROGESSIVELY */
/* ---      MORE RECENTLY USED CORE SLOTS */
/* ---      IPAGE GIVES THE CURRENT PAGE LOADED INTO A CORE SLOT */
/* ---      INCOR GIVES THE SLOT IN CORE NOW OCCUPIED BY EACH PAGE */
/* ---      LOCREC GIVES THE RECORD LOCATION OF EACH PAGE ON EXTERNAL FILE */


/* ...                SYSTEM I/O FILES */




/* ---      MAXPAG IS THE MAXIMUM NUMBER OF PAGES IN CORE NOW */
/* ---      MAXCOR IS THE ABSOLUTE MAXIMUM NUMBER OF PAGES IN CORE */
/* ---      MAXFIL IS THE MAXIMUM NUMBER OF PAGES ALLOWED ON EXTERNAL FILE */
/* ---      NPGCNT IS THE MAXIMUM PAGE ENCOUNTERED TO DATE */


/*     CALL BAD(-1,-6,'ENTR','XCANON') */
    if (*v - stor_1.cfb >= 0) {
	goto L10;
    }
/* ---     THE REFERENCED CANON FORM IS BELOW THE CANON AREA. */
    ret_val = *v;
    goto L999;

L10:
    if (maxpag != 0) {
	goto L50;
    }
/* ---     INITIAL CALL, SET UP */
    lenpag = const_1.kcbn << 1;
/* ---     LENPAG IS THE LENGTH OF A CANON PAGE IN SINGLE PRECISION WORDS */
/* ---     MAXPAG IS THE MAXIMUM NUMBER OF PAGES THAT FIT IN CORE */
    maxpag = ((stor_1.ppb + 3) / 4 - stor_1.cfb) / const_1.kcbn;
    maxpag = min(maxcor,maxpag);
/* ---     SET UP THE INITIAL DOUBLY LINKED LIST POINTERS */
    nfor[0] = 1;
    nback[0] = 1;
    i__1 = maxcor;
    for (l = 1; l <= i__1; ++l) {
/* L20: */
	work_1.ipage[l - 1] = 0;
    }
/*     CALL BAD(1,0,'PPB ',PPB) */
/*     CALL BAD(1,0,'CFB ',CFB) */
/*     CALL BAD(-1,0,'MXPG',MAXPAG) */

/* ---     NORMAL CONTINUING POINT OF CALCULATION */
L50:
/* ---     COMPUTE THE IDEAL PAGE NUMBER AND INCREMENT INTO PAGE */
    ivpage = (*v - stor_1.cfb) / const_1.kcbn + 1;
/*     CALL BAD(1,0,'V   ',V) */
/*     CALL BAD(-1,0,'IVPG',IVPAGE) */
    if (ivpage < maxfil + 1) {
	goto L60;
    }
/* ---     PAGE EXCEEDS THE ABSOLUTE MAXIMUM FOR EXTERNAL PAGES */
    cform_("0 TOO MANY PAGES OF CANONICAL DATA IN XCANON", darray_1.darray, &
	    c__1, &c__44, (ftnlen)44, (ftnlen)120);
    goto L995;

L60:
/* ---     IF PAGE IS NOW IN CORE, SKIP LOAD/UNLOAD LOGIC */
    if (incor[ivpage - 1] > nzero) {
	goto L400;
    }
/* ---     THE PAGE IS NOT NOW IN CORE - LOAD IT IF NECESSARY */
    if (navail < maxpag + 2) {
	goto L100;
    }
/* ---     ALL AVAILABLE CORE SLOTS ARE IN USE.  THE OLDEST */
/* ---     PAGE(LEAST RECENTLY USED) SHOULD FIRST BE REMOVED. */
    nxslot = nback[0] - 1;
/* ---     PAGE NUMBER OF THIS OLDEST PAGE */
    ip = work_1.ipage[nxslot - 1];
/* ---     LOCATION OF THIS OLD PAGE IN CORE */
    loc = stor_1.cfb + (incor[ip - 1] - 1) * const_1.kcbn;
/* ---     SET FLAGS FOR WRITING AT END OF FILE */
/*     CALL BAD(1,0,'WRIT',IP) */
/*     CALL BAD(-1,0,'SLOT',NXSLOT) */
    nr = 0;
    ir = 0;
/* ---      NOW WRITE PAGE OUT TO XCAN FILE */
    lnpg = lenpag;
    awrite_(&symfil_1.xcan, &nr, &cf[loc - 1], &lnpg, &ir);
/* ***     TERMINATE IF AN ERROR OCCURRED. */
    if (ir != 0) {
	goto L997;
    }
/* ---      INCREMENT WRITE COUNT  *** IWRIT USED IN LIB *** */
    ++work_1.iwrit;

/* ---     UPDATE THE STATUS OF PAGE IP */
    work_1.ipage[nxslot - 1] = ivpage;
    incor[ivpage - 1] = incor[ip - 1];
    incor[ip - 1] = -incor[ip - 1];
    locrec[ip - 1] = nr;
    goto L200;

L100:
/* ---     A SLOT IS STILL OPEN IN CORE, SO NO PAGE NEED BE REMOVED */
    nxslot = navail - 1;
    ++navail;
/* ---     EXPAND THE LIST LINKAGES. */
    nn = nback[0];
    nfor[nn - 1] = nxslot + 1;
    nback[0] = nxslot + 1;
    nfor[nxslot] = 1;
    nback[nxslot] = nn;
    incor[ivpage - 1] = nxslot;
L200:

/* ---      NEXT CHECK WHETHER THE SOUGHT-AFTER PAGE HAS BEEN WRITTEN */
/* ---      TO THE DISK FILE EARLIER. */
    if (locrec[ivpage - 1] == nzero) {
	goto L300;
    }
/* ---      SINCE THAT PAGE IS ON DISK, IT SHOULD BE RETRIEVED. */
/* ---      SELECT THE DISK RECORD NUMBER */
    nr = locrec[ivpage - 1];
/* ---      SELECT LOCATION INTO WHICH DATA IS READ */
    loc = stor_1.cfb + (incor[ivpage - 1] - 1) * const_1.kcbn;
/*     CALL BAD(1,0,'READ',IVPAGE) */
/*     CALL BAD(-1,0,'SLOT',NXSLOT) */
    ir = 0;
/* ---      FETCH THE DATA FROM DISK INTO CORE */
    lnpg = lenpag;
    aread_(&symfil_1.xcan, &nr, &cf[loc - 1], &lnpg, &ir);
/* ***      BRANCH IF READ CAUSED AND ERROR */
    if (ir != 0) {
	goto L998;
    }

L300:
    work_1.ipage[nxslot - 1] = ivpage;

L400:
/* ---     DESIRED PAGE IS NOW IN CORE */
    in1 = incor[ivpage - 1] + 1;
    nn = nfor[0];
    if (in1 == nn || navail == 2) {
	goto L500;
    }
/* ---      DESIRED PAGE IS NOT NOW THE MOST RECENTLY USED */
/* ---      ALTER THE LINKED LIST SO THAT IT IS THE MOST RECENT */
/* ---      FIRST REMOVE IN1 FROM THE LINKED LIST TEMPORARILY */
    nfsave = nfor[in1 - 1];
    nbsave = nback[in1 - 1];
    nfor[nbsave - 1] = nfsave;
    nback[nfsave - 1] = nbsave;
/* ---      NOW RESET IN1 INTO THE TOP OF THE USAGE HISTORY LIST */
    nowtop = nfor[0];
    nfor[0] = in1;
    nfor[in1 - 1] = nowtop;
    nback[nowtop - 1] = in1;
    nback[in1 - 1] = 1;

L500:
/* ---      COMPUTE THE ACTUAL ADDRESS OF THIS CANON FORM */
    ret_val = stor_1.cfb + (incor[ivpage - 1] - 1) * const_1.kcbn + (*v - 
	    stor_1.cfb) % const_1.kcbn;
    goto L999;


L997:
    cform_(" CANON PAGE WRITE ERROR IN XCANON", darray_1.darray, &c__1, &
	    c__33, (ftnlen)33, (ftnlen)120);
    goto L996;
L998:
    cform_(" CANON PAGE READ ERROR IN XCANON ", darray_1.darray, &c__1, &
	    c__33, (ftnlen)33, (ftnlen)120);
L996:
    iconv_(&ir, darray_1.darray, &c__35, &c__8, (ftnlen)120);
L995:
    cprint_(darray_1.darray, (ftnlen)120);
    bad_(&c__1, &c__0, "V   ", v, (ftnlen)4);
    bad_(&c__1, &c__0, "IVPG", &ivpage, (ftnlen)4);
    bad_(&c__1, &c__0, "LENP", &lenpag, (ftnlen)4);
    bad_(&c__1, &c__0, "LNPG", &lnpg, (ftnlen)4);
    bad_(&c__1, &c__0, "MXPG", &maxpag, (ftnlen)4);
    bad_(&c__1, &c__0, "NR  ", &nr, (ftnlen)4);
    bad_(&c__1, &c__0, "NAVL", &navail, (ftnlen)4);
    bad_(&c__1, &c__0, "NSLT", &nxslot, (ftnlen)4);
    bad_(&c_n1, &c__0, "NPCN", &npgcnt, (ftnlen)4);

/*     NPGCNT=MAX0(IVPAGE,NPGCNT) */
/*     CALL SBAD(-MAXPAG,0,'IPAG',IPAGE) */
/*     NN=MAXPAG+1 */
/*     CALL SBAD(-NN,0,'NFOR',NFOR) */
/*     CALL SBAD(-NN,0,'NBAC',NBACK) */
/*     CALL SBAD(-NPGCNT,0,'LOCR',LOCREC) */
/*     CALL SBAD(-NPGCNT,0,'INCO',INCOR) */
    help_();
L999:

/*     NPGCNT=MAX0(IVPAGE,NPGCNT) */
/*     CALL SBAD(-MAXPAG,0,'IPAG',IPAGE) */
/*     NN=MAXPAG+1 */
/*     CALL SBAD(-NN,0,'NFOR',NFOR) */
/*     CALL SBAD(-NN,0,'NBAC',NBACK) */
/*     CALL SBAD(-NPGCNT,0,'LOCR',LOCREC) */
/*     CALL SBAD(-NPGCNT,0,'INCO',INCOR) */
    return ret_val;
/*     END */
/*     SUBROUTINE SBAD(N1,N2,N3,N4) */
/*     DIMENSION N4(1),NN(100) */
/*     INTEGER N4 */
/*     N=IABS(N1) */
/*     N=MIN0(N,100) */
/*     DO 10 I=1,N */
/*     NN(I)=N4(I) */
/*  10 CONTINUE */
/*     IF(N1.LT.0) N=-N */
/*     CALL BAD(N,0,N3,NN) */
/*     RETURN */
} /* xcanon_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf






/* ---    IMPLEMENTATION DEPENDENT ROUTINE */

/* Subroutine */ int incan_(integer *av)
{

    static integer ip;




/* ---      NFOR REPRESENT FORWARD POINTERS SHOWING PROGRESSIVELY */
/* ---      OLDER PAGES.   NFOR(1) IS NOT A CORE SLOT POINTER, BUT */
/* ---      AN INITIALIZING LOCATION FOR THE LIST POINTERS. */
/* ---      NBACK REPRESENTS BACKWARD POINTERS TO PROGESSIVELY */
/* ---      MORE RECENTLY USED CORE SLOTS */
/* ---      IPAGE GIVES THE CURRENT PAGE LOADED INTO A CORE SLOT */
/* ---      INCOR GIVES THE SLOT IN CORE NOW OCCUPIED BY EACH PAGE */
/* ---      LOCREC GIVES THE RECORD LOCATION OF EACH PAGE ON EXTERNAL FILE */


/* ---      MAXPAG IS THE MAXIMUM NUMBER OF PAGES IN CORE NOW */
/* ---      MAXCOR IS THE ABSOLUTE MAXIMUM NUMBER OF PAGES IN CORE */
/* ---      MAXFIL IS THE MAXIMUM NUMBER OF PAGES ALLOWED ON EXTERNAL FILE */
/* ---      NPGCNT IS THE MAXIMUM PAGE ENCOUNTERED TO DATE */




/* ---      ROUTINE TO CALCULATE A VIRTUAL ADDRESS GIVEN */
/* ---      A CURRENT ACTUAL ADDRESS. */
    ip = (*av - stor_1.cfb) / const_1.kcbn + 1;
    *av = stor_1.cfb + (work_1.ipage[ip - 1] - 1) * const_1.kcbn + (*av - 
	    stor_1.cfb) % const_1.kcbn;

/*     NPGCNT=MAX0(IVPAGE,NPGCNT) */
/*     CALL SBAD(-MAXPAG,0,'IPAG',IPAGE) */
/*     NN=MAXPAG+1 */
/*     CALL SBAD(-NN,0,'NFOR',NFOR) */
/*     CALL SBAD(-NN,0,'NBAC',NBACK) */
/*     CALL SBAD(-NPGCNT,0,'LOCR',LOCREC) */
/*     CALL SBAD(-NPGCNT,0,'INCO',INCOR) */
    return 0;
/*     END */
/*     SUBROUTINE SBAD(N1,N2,N3,N4) */
/*     DIMENSION N4(1),NN(100) */
/*     INTEGER N4 */
/*     N=IABS(N1) */
/*     N=MIN0(N,100) */
/*     DO 10 I=1,N */
/*     NN(I)=N4(I) */
/*  10 CONTINUE */
/*     IF(N1.LT.0) N=-N */
/*     CALL BAD(N,0,N3,NN) */
/*     RETURN */
} /* incan_ */

