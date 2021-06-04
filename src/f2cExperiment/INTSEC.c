/* INTSEC.f -- translated by f2c (version 20100827).
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
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    integer ikeep[255];
} intcom_;

#define intcom_1 intcom_

struct {
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer nscnmx, iscan;
    doublereal pt[9000]	/* was [9][1000] */;
} sspad_;

#define sspad_1 sspad_

/* Table of constant values */

static integer c__22830 = 22830;
static integer c__4 = 4;
static integer c_n1 = -1;
static integer c_b19 = -22832;
static integer c_b23 = -22833;
static integer c__22834 = 22834;
static integer c__1 = 1;
static integer c__8 = 8;
static integer c__22831 = 22831;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__5 = 5;

/* *** SOURCE FILE : M0011516.V03   *** */

/* Subroutine */ int intsec_(void)
{
    /* Initialized data */

    static doublereal stp[3] = { 0.,0.,0. };
    static char with[8] = "WITH    ";
    static char dcanon[8] = "CANON   ";
    static char hex[8] = "HEX     ";
    static logical first = TRUE_;
    static struct {
	doublereal e_1[6];
	} equiv_2 = { 1.03e6, 0., 0., 0., 0., 0. };


    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_0[76], equiv_1[76], equiv_9[1];

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal d1, d2;
    static integer j1, j2, j3, j4, n1, n2, n4;
    static doublereal d12;
    static integer j11, j12, j33;
#define pl ((doublereal *)&equiv_2 + 1)
    static integer ip1, ip2;
#define pl1 ((doublereal *)&equiv_2)
    static integer j2s, j4s;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal sec;
    static integer irc, nwd, ipt, mpt, npt;
    static doublereal tol;
    static integer lpt;
    extern integer bcdf_(char *, ftnlen);
    static integer mode, icon, jcon[100]	/* was [2][50] */;
    static doublereal hmod;
    static integer ncon;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static integer idir;
    static doublereal told;
#define ipnr ((integer *)&intcom_1 + 253)
    static integer isix, jsix[800]	/* was [4][200] */, nsix;
    static char test[8];
#define word (equiv_9)
    static doublereal tolp;
    static integer iout, jend1, jend2;
#define poed1 (equiv_0)
#define poed2 (equiv_1)
    extern /* Subroutine */ int apt234_(doublereal *, doublereal *), apt094_()
	    ;
    static integer jsix1, jsix2;
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define thick ((doublereal *)&intcom_1 + 100)
    static integer mscan;
    static doublereal sname;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer iwhat, intds[901];
#define iword ((integer *)equiv_9)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer intps[901], isize, inext;
#define dummy1 (equiv_0 + 74)
#define dummy2 (equiv_1 + 74)
    static integer ldaflg;
    static doublereal canind;
    static integer indcan;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer isecnd[50], jsecnd;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);
    static integer nsecnd;
    static doublereal thdold;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static integer isbsct;
    static doublereal thpold, sindex;
    extern /* Subroutine */ int plapol_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *, doublereal *, integer *);
    static integer ifirst[50], jfirst;
    extern /* Subroutine */ int inttrc_(integer *, integer *, doublereal *, 
	    integer *, integer *);
    static integer nfirst;
    extern /* Subroutine */ int transm_(doublereal *, doublereal *, integer *,
	     integer *, integer *), polmtn_(integer *, doublereal *, integer *
	    , integer *);
    static doublereal toltol;
    extern /* Subroutine */ int polpol_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *), intsrf_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *), intout_(integer *, doublereal *, integer *,
	     integer *, integer *, integer *, doublereal *, doublereal *);


/* ROUTINE TO INTERSEC A PLANE WITH SSURF'S  OR */
/*                       SSURF'S WITH SSURF'S */



/*  INTERSECTION START POINT */

/*  POLYEDER STORAGE */

/*   PLANE STORAGE FOR TRANSFORMATION PURPOSE */

/* SS - ARELEM - COMMON */

/*   SECTION INDICATORS */

/*   CONTOUR POINTER FIELD */
/*    JCON(1,X) : POINTER TO FIRST SEGMENT */
/*    JCON(2,X) : POINTER TO LAST SEGMENT */
/*    ICON : CURRENT CONTOUR */
/*    NCON : NEW CONTOUR */

/*   CONTOUR SEGMENT FIELD */
/*    JSIX(1,X) : POINTER TO FIRST POINT IN PT ARRAY */
/*    JSIX(2,X) : POINTER TO LAST POINT IN PT ARRAY */
/*    JSIX(3,X) : POINTER TO PREVIOUS CONTOUR SEGMENT */
/*    JSIX(4,X) : POINTER TO FOLLOWING CONTOUR SEGMENT */
/*    ISIX : CURRENT CONTOUR SEGMENT */
/*    NSIX : NEW CREATET CONTOUR SEGMENT */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/*   THICKNESS ON PS AND DS */
/*   SUBROUTINE TRACE */
/* CCCC EQUIVALENCE (IKEEP(249),ITRACE) */
/*   PATCH NUMBER FOR PS AND DS (SURFACE RECNO*1000 + PATCH NO) */

/*       TOTAL-LIBRARY. */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */







/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* BLANK COMMON */

/* SCRATCH AREA TO STORE THE RESULTING POINTS */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* SWITCH FOR PLANE/SSURF (=1) OR SSURF/SSURF (=2) INTERSECTION */

/* CHECK DEFINITION FUNCTION */

/* STORAGE FOR FIRST AND SECOND SET OF SSURF'S */

/* CONTROL WORDS */




/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* .... INITIALISE CHARACTER ITEM FOR OUTPUT TO EXFILE */

    if (first) {
	iword[0] = bcdf_("SYSP", (ftnlen)4);
	iword[1] = bcdf_("L   ", (ftnlen)4);
	pl1[5] = *word;
	first = FALSE_;
    }

/* SET THICKNESS FOR DRIVE-SURFACE */
    thdold = sv_1.th[ifxcor_1.ids - 1];
    told = (sv_1.tau1[ifxcor_1.ids - 1] - sv_1.tau2[ifxcor_1.ids - 1]) * .8;
    sv_1.th[ifxcor_1.ids - 1] = sv_1.th[ifxcor_1.ids - 1] + sv_1.tau2[
	    ifxcor_1.ids - 1] + told / 8.;
    thick[0] = sv_1.th[ifxcor_1.ids - 1];

/* SET THICKNESS FOR PART-SURFACE */
    thpold = sv_1.th[ifxcor_1.ips - 1];
    tolp = (sv_1.tau1[ifxcor_1.ips - 1] - sv_1.tau2[ifxcor_1.ips - 1]) * .8;
    sv_1.th[ifxcor_1.ips - 1] = sv_1.th[ifxcor_1.ips - 1] + sv_1.tau2[
	    ifxcor_1.ips - 1] + tolp / 8.;
    thick[1] = sv_1.th[ifxcor_1.ips - 1];

/* READ THE INTERSECTION ARGUMENT AND STORE THEM */
    nfirst = 0;
    nsecnd = 0;
    iwhat = 1;
    iout = 0;
    mscan = (integer) sscan[1];
    sspad_1.iscan = 3;
L1:
    if (sspad_1.iscan >= mscan) {
	goto L20;
    }

/* GEOMETRY ?  (PLANE/LINE OR SSURF) */
    if (sscan[sspad_1.iscan - 1] != 1. && sscan[sspad_1.iscan - 1] != 2. && 
	    sscan[sspad_1.iscan - 1] != 29.) {
	goto L10;
    }

/* CHECK, IF GEOMETRY IS VALID */
    if (! ckdef_(&sscan[sspad_1.iscan - 1])) {
	goto L2;
    }

/* GEOMETRY ELEMENT IS NOT DEFINED: RETURN WITHOUT RESULT */
    error_(&c__22830, "INTSEC  ", (ftnlen)8);
    goto L999;

/* LINE / PLANE ? */
L2:
    if (sscan[sspad_1.iscan - 1] != 1. && sscan[sspad_1.iscan - 1] != 2.) {
	goto L5;
    }

/*  NORMALIZE AND STORE THE PLANE */
/* Computing 2nd power */
    d__1 = sscan[sspad_1.iscan];
/* Computing 2nd power */
    d__2 = sscan[sspad_1.iscan + 1];
/* Computing 2nd power */
    d__3 = sscan[sspad_1.iscan + 2];
    sec = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L3: */
	pl[i__ - 1] = sscan[sspad_1.iscan + i__ - 1] / sec;
    }
    pl[3] = sscan[sspad_1.iscan + 3] / sec + sv_1.th[ifxcor_1.ids - 1];

/* INITIALIZE SYSTEM DS PLANE */
    ifxcor_1.is = ifxcor_1.ids;
    apt234_(&hmod, pl);

/*   TRANSFORM PLANE FROM LOCAL TO BASIC COORDINATE SYSTEM */
    transm_(&ssarlm_1.bb[64], pl, &c__4, &c__4, &c_n1);
/*   SIGNAL THE PLANE */
    ssarlm_1.iiflag[4] = -1;
    ipnr[1] = 0;
/*   CONTINUE WITH SCANNING */
    sspad_1.iscan += 5;
    iwhat = 2;
    goto L1;

/* GET COMMON INDEX OF SSURF */
L5:
    ldaflg = 7;
    apt094_(&ldaflg, &sscan[sspad_1.iscan], &canind);
    indcan = (integer) canind;
    sspad_1.iscan += 3;
    switch (iwhat) {
	case 1:  goto L7;
	case 2:  goto L8;
    }

/* A FIRST SURFACE IS FOUND */
L7:
    ++nfirst;
    ifirst[nfirst - 1] = indcan;
    if (nfirst == 1) {
	goto L1;
    }

    jfirst = nfirst - 1;
    i__1 = jfirst;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ifirst[i__ - 1] != indcan) {
	    goto L17;
	}
	--nfirst;

/* SAME SSURF FOUND TWICE BEFORE WITH, ONLY FIRST FOUND SSURF */
/*  IN FIRST PART OF THE STATEMENT WILL BE USED */
	aerr_(&c_b19, "INTSEC  ", (ftnlen)8);
	goto L1;
L17:
	;
    }
    goto L1;

/* A SECOND SURFACE IS FOUND */
L8:
    ++nsecnd;
    isecnd[nsecnd - 1] = indcan;
    if (nsecnd == 1) {
	goto L118;
    }

    jsecnd = nsecnd - 1;
    i__1 = jsecnd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (isecnd[i__ - 1] != indcan) {
	    goto L18;
	}
	--nsecnd;

/* SAME SSURF FOUND TWICE AFTER WITH, ONLY FIRST FOUND SSURF */
/*  IN SECOND PART OF THE STATEMENT WILL BE USED */
	aerr_(&c_b23, "INTSEC  ", (ftnlen)8);
	goto L118;
L18:
	;
    }

/* CHECK, IF SAME SSURF SHOULD BE INTERSECTED */
L118:
    if (nsecnd == 0) {
	goto L1;
    }
    if (nfirst == 0) {
	goto L1;
    }
    i__1 = nfirst;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ifirst[i__ - 1] != isecnd[nsecnd - 1]) {
	    goto L19;
	}

/* SAME SSURF WILL BE INTERSECTED BY ITSELF, THIS IS NOT POSSIBLE */
	error_(&c__22834, "INTSEC  ", (ftnlen)8);
	--nsecnd;
	goto L1;
L19:
	;
    }
    goto L1;

/* CONTROL WORDS */
L10:
    holfrm_(&sscan[sspad_1.iscan], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, with, (ftnlen)8, (ftnlen)8) != 0) {
	goto L11;
    }
    iwhat = 2;
    sspad_1.iscan += 2;
    goto L1;

/* CANON POINT TO OUTPUT ? */
L11:
    if (s_cmp(test, dcanon, (ftnlen)8, (ftnlen)8) != 0) {
	goto L12;
    }
    iout = 1;
    sspad_1.iscan += 2;
    goto L1;

/* HEX OUTPUT ? */
L12:
    if (s_cmp(test, hex, (ftnlen)8, (ftnlen)8) != 0) {
	goto L13;
    }
    iout = 2;
L13:
    sspad_1.iscan += 2;
    goto L1;

/* PREPARATION OF INTERSECTIONS */
L20:
    if (nsecnd != 0) {
	goto L21;
    }

/* NO INTERSECTION POSSIBLE */
    error_(&c__22831, "INTSEC  ", (ftnlen)8);
    goto L999;
L21:

/*  INTERSECTIONS */
/* ********************************************************************* */

/*  OUTER LOOP FOR FIRST ARGUMENT SURFACES (DS) */
    n1 = max(1,nfirst);
    i__1 = n1;
    for (j1 = 1; j1 <= i__1; ++j1) {
	n2 = 1;
	if (nfirst == 0) {
	    goto L210;
	}

/*  LOCATE THE NON PLANE DRIVE SURFACE */
	ldaflg = 3;
	apt094_(&ldaflg, &_BLNK__1.com[ifirst[j1 - 1] - 1], &j11);
	j11 += -41;
/*  NUMBER OF PATCHES */
	n2 = (integer) sscan[j11 + 3];
/*  SURFACE RECORD NUMBER TIMES 1000 FOR PATCH IDENTIFICATION */
	ipnr[1] = (integer) (sscan[j11] * 1000);

/*  INITIALIZE DRIVE SURFACE */
	ifxcor_1.is = ifxcor_1.ids;
	apt234_(&hmod, &_BLNK__1.com[ifirst[j1 - 1] - 1]);
L210:

/*  PREPARATION OF PATCH REFERENCE OF FIRST ARGUMENT SURFACES */
	i__2 = n2;
	for (j2 = 1; j2 <= i__2; ++j2) {
/* L410: */
	    intds[j2] = 0;
	}
/* ********************************************************************* */

/*  OUTER LOOP FOR SECOND ARGUMENT SURFACES (PS) */
	i__2 = nsecnd;
	for (j3 = 1; j3 <= i__2; ++j3) {
	    for (j33 = 1; j33 <= 3; ++j33) {

/*  LOCATE THE PART SURFACE */
		ldaflg = 3;
		apt094_(&ldaflg, &_BLNK__1.com[isecnd[j3 - 1] - 1], &j12);
		j12 += -41;

/*  CHECK SURFACE LOCATION IF DS IS NOT A PLANE */
		if (ssarlm_1.iiflag[4] <= 0) {
		    goto L50;
		}

/*  CHECK SURFACE RECORD NUMBER AND LENGTH */
		if (_BLNK__1.com[ifirst[j1 - 1] - 1] == sscan[j11] && 
			_BLNK__1.com[ifirst[j1 - 1]] == sscan[j11 + 7]) {
		    goto L50;
		}

/*  LOCATE THE NON PLANE DRIVE SURFACE */
		ldaflg = 3;
		apt094_(&ldaflg, &_BLNK__1.com[ifirst[j1 - 1] - 1], &j11);
		j11 += -41;
/* L40: */
	    }
/* GET NAME AND INDEX OF SURFACE */
L50:
	    unpack_(&_BLNK__1.com[isecnd[j3 - 1] - 1], &mode, &isize, &isbsct)
		    ;
	    sname = _BLNK__1.com[isecnd[j3 - 1] + isize - 1];
	    if (isbsct > 1) {
		sname = _BLNK__1.com[isecnd[j3 - 1] + (isize + 1) * isbsct - 
			2];
	    }
	    sindex = (doublereal) isbsct;
/*  NUMBER OF PATCHES */
	    n4 = (integer) sscan[j12 + 3];
/*  SURFACE RECORD NUMBER TIMES 1000 FOR PATCH IDENTIFICATION */
	    ipnr[0] = (integer) (sscan[j12] * 1000);

/*  INITIALIZE PART SURFACE */
	    ifxcor_1.is = ifxcor_1.ips;
	    apt234_(&hmod, &_BLNK__1.com[isecnd[j3 - 1] - 1]);

/*  PREPARATION OF PATCH REFERENCE OF SECOND ARGUMENT SURFACES */
	    i__3 = n4;
	    for (j4 = 1; j4 <= i__3; ++j4) {
/* L420: */
		intps[j4] = 0;
	    }

/*   PREPARATION OF POINT STORAGE MANAGEMENT */
	    ipt = 1;
	    mpt = sspad_1.nscnmx / 9;
	    npt = 0;

/*   PREPARATION OF CONTOUR SEGMENT XREF AND CONTOUR TABLE */
	    nsix = 0;
	    ncon = 0;
/* ********************************************************************* */

/*  INNER LOOP FOR FIRST ARGUMENT SURFACES OVER THE PATCHES (DS) */
	    i__3 = n2;
	    for (j2 = 1; j2 <= i__3; ++j2) {
		if (nfirst == 0) {
		    goto L220;
		}
		if (intds[j2] == 1) {
		    goto L310;
		}
		lodpch_(&sscan[j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4], &
			ssarlm_1.iitop[24], &j2, &c__0);
		ssarlm_1.ipnum[1] = j2;
/*  SAVE PATCH POINTER */
		j2s = j2;
/*  COMPUTE THE INDIVIDUAL PATCH */
		ipnr[1] = ipnr[1] / 1000 * 1000 + j2;

/*   COMPUTE 5*5 POLYHEDRON */
		polmtn_(&c__2, poed2, &c__5, &c__5);
L220:
/* ********************************************************************* */

/*  INNER LOOP FOR SECOND ARGUMENT SURFACES OVER THE PATCHES (PS) */
		i__4 = n4;
		for (j4 = 1; j4 <= i__4; ++j4) {
		    if (intps[j4] == 1) {
			goto L300;
		    }
		    lodpch_(&sscan[j12], ssarlm_1.bb, ssarlm_1.iiflag, 
			    ssarlm_1.iitop, &j4, &c__0);
		    ssarlm_1.ipnum[0] = j4;
/*  SAVE PATCH POINTER */
		    j4s = j4;
/*  COMPUTE THE INDIVIDUAL PATCH */
		    ipnr[0] = ipnr[0] / 1000 * 1000 + j4;

/*   COMPUTE 5*5 POLYHEDRON */
		    polmtn_(&c__1, poed1, &c__5, &c__5);

/*  SEARCH FOR INTERSECTION */
		    tol = (told + tolp) / 2.;
		    toltol = tol * tol * 2.;
		    if (nfirst == 0) {
			plapol_(&ssarlm_1.bb[64], poed1, &c__5, &c__5, &tol, 
				stp, &irc);
		    }
		    if (nfirst != 0) {
			polpol_(poed2, &c__5, &c__5, poed1, &c__5, &c__5, &
				tol, stp, &irc);
		    }
		    if (irc == 0) {
			goto L300;
		    }

/*  CUT! */
/* L430: */
/*  SUBROUTINE TRACE SWITCH */
/* CCCC ITRACE=0 */
		    ipt += npt;
		    npt = mpt - ipt + 1;
		    intsrf_(stp, &tol, &sspad_1.pt[ipt * 9 - 9], &npt, &irc);
		    if (npt == 0) {
			goto L300;
		    }
		    lpt = ipt + npt - 1;

/*   MARK USED PATCHES */
		    intds[ssarlm_1.ipnum[1]] = 1;
		    intps[ssarlm_1.ipnum[0]] = 1;

/*   CREATE A CONTOUR SEGMENT ENTITY FOR A NEW SEGMENT FOUND */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    isix = nsix;
		    jsix[(isix << 2) - 4] = ipt;
		    jsix[(isix << 2) - 3] = lpt;
		    jsix[(isix << 2) - 2] = 0;
		    jsix[(isix << 2) - 1] = 0;

/*   CREATE A CONTOUR TABLE ENTRY */
		    if (ncon >= 50) {
			goto L999;
		    }
		    ++ncon;
		    jcon[(ncon << 1) - 2] = isix;
		    jcon[(ncon << 1) - 1] = isix;
		    icon = ncon;

/*   TEST FOR CLOSED SEGMENT */
/* Computing 2nd power */
		    d__1 = sspad_1.pt[ipt * 9 - 9] - sspad_1.pt[lpt * 9 - 9];
/* Computing 2nd power */
		    d__2 = sspad_1.pt[ipt * 9 - 8] - sspad_1.pt[lpt * 9 - 8];
/* Computing 2nd power */
		    d__3 = sspad_1.pt[ipt * 9 - 7] - sspad_1.pt[lpt * 9 - 7];
		    d12 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d12 <= toltol) {
			goto L470;
		    }

/*   SEARCH FOR PREVIOUS CONTOUR SEGMENT */
L435:
		    jsix[(isix << 2) - 2] = 0;
		    jsix1 = jsix[(isix << 2) - 4];
		    inttrc_(&j12, &j11, &sspad_1.pt[jsix1 * 9 - 9], &c__1, &
			    irc);
		    if (irc == 0) {
			goto L449;
		    }
/*  INTERSECTION */
		    stp[0] = sspad_1.pt[jsix1 * 9 - 9];
		    stp[1] = sspad_1.pt[jsix1 * 9 - 8];
		    stp[2] = sspad_1.pt[jsix1 * 9 - 7];
		    ipt += npt;
		    npt = mpt - ipt + 1;
		    intsrf_(stp, &tol, &sspad_1.pt[ipt * 9 - 9], &npt, &irc);
		    if (npt == 0) {
			goto L449;
		    }
		    lpt = ipt + npt - 1;

/*   MARK USED PATCHES */
		    intds[ssarlm_1.ipnum[1]] = 1;
		    intps[ssarlm_1.ipnum[0]] = 1;

/*  CHECK THE CONNECTION POINT */
/* Computing 2nd power */
		    d__1 = sspad_1.pt[ipt * 9 - 9] - sspad_1.pt[jsix1 * 9 - 9]
			    ;
/* Computing 2nd power */
		    d__2 = sspad_1.pt[ipt * 9 - 8] - sspad_1.pt[jsix1 * 9 - 8]
			    ;
/* Computing 2nd power */
		    d__3 = sspad_1.pt[ipt * 9 - 7] - sspad_1.pt[jsix1 * 9 - 7]
			    ;
		    d1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d1 > toltol) {
			goto L440;
		    }
/*  SAVE POINTERS FOR CLOSED CONTOUR CHECK */
		    jend1 = lpt;
		    jend2 = jsix[(jcon[(icon << 1) - 1] << 2) - 3];

/*  PREVIOUS SEGMENT, REVERSE ORDER */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = lpt;
		    jsix[(nsix << 2) - 3] = ipt;
		    goto L442;

/*  CHECK THE CONNECTION POINT */
L440:
/* Computing 2nd power */
		    d__1 = sspad_1.pt[lpt * 9 - 9] - sspad_1.pt[jsix1 * 9 - 9]
			    ;
/* Computing 2nd power */
		    d__2 = sspad_1.pt[lpt * 9 - 8] - sspad_1.pt[jsix1 * 9 - 8]
			    ;
/* Computing 2nd power */
		    d__3 = sspad_1.pt[lpt * 9 - 7] - sspad_1.pt[jsix1 * 9 - 7]
			    ;
		    d2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d2 <= toltol) {
			goto L441;
		    }

/*  NEW STAND ALLONE SEGMENT */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = ipt;
		    jsix[(nsix << 2) - 3] = lpt;
		    jsix[(nsix << 2) - 2] = 0;
		    jsix[(nsix << 2) - 1] = 0;

/*   CREATE A CONTOUR TABLE ENTRY */
		    if (ncon >= 50) {
			goto L999;
		    }
		    ++ncon;
		    jcon[(ncon << 1) - 2] = nsix;
		    jcon[(ncon << 1) - 1] = nsix;
		    goto L449;
/*  SAVE POINTERS FOR CLOSED CONTOUR CHECK */
L441:
		    jend1 = ipt;
		    jend2 = jsix[(jcon[(icon << 1) - 1] << 2) - 3];

/*  PREVIOUS SEGMENT, NORMAL ORDER */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = ipt;
		    jsix[(nsix << 2) - 3] = lpt;
L442:
		    jsix[(nsix << 2) - 2] = 0;
		    jsix[(isix << 2) - 2] = nsix;
		    jsix[(nsix << 2) - 1] = isix;
		    isix = nsix;
		    jcon[(icon << 1) - 2] = isix;
/*   TEST FOR CLOSED SEGMENT */
/* Computing 2nd power */
		    d__1 = sspad_1.pt[jend1 * 9 - 9] - sspad_1.pt[jend2 * 9 - 
			    9];
/* Computing 2nd power */
		    d__2 = sspad_1.pt[jend1 * 9 - 8] - sspad_1.pt[jend2 * 9 - 
			    8];
/* Computing 2nd power */
		    d__3 = sspad_1.pt[jend1 * 9 - 7] - sspad_1.pt[jend2 * 9 - 
			    7];
		    d12 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d12 <= toltol) {
			goto L470;
		    }
		    goto L435;

/*   SET ISIX TO FORWARD SEARCH */
L449:
		    isix = jcon[(icon << 1) - 1];

/* REINSTAL THE PREVIOUS PATCHES */
		    if (ssarlm_1.iiflag[4] <= 0) {
			goto L448;
		    }
		    lodpch_(&sscan[j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4]
			    , &ssarlm_1.iitop[24], &j2s, &c__0);
		    ssarlm_1.ipnum[1] = j2s;
		    ipnr[1] = ipnr[1] / 1000 * 1000 + j2s;
L448:
		    lodpch_(&sscan[j12], ssarlm_1.bb, ssarlm_1.iiflag, 
			    ssarlm_1.iitop, &j4s, &c__0);
		    ssarlm_1.ipnum[0] = j4s;
		    ipnr[0] = ipnr[0] / 1000 * 1000 + j4s;

/*   SEARCH FOR FOLLOWING CONTOUR SEGMENTS */
L450:
		    jsix[(isix << 2) - 1] = 0;
		    jsix2 = jsix[(isix << 2) - 3];
		    inttrc_(&j12, &j11, &sspad_1.pt[jsix2 * 9 - 9], &c_n1, &
			    irc);
		    if (irc == 0) {
			goto L469;
		    }
/*  INTERSECTION */
		    stp[0] = sspad_1.pt[jsix2 * 9 - 9];
		    stp[1] = sspad_1.pt[jsix2 * 9 - 8];
		    stp[2] = sspad_1.pt[jsix2 * 9 - 7];
		    ipt += npt;
		    npt = mpt - ipt + 1;
		    intsrf_(stp, &tol, &sspad_1.pt[ipt * 9 - 9], &npt, &irc);
		    if (npt == 0) {
			goto L469;
		    }
		    lpt = ipt + npt - 1;

/*   MARK USED PATCHES */
		    intds[ssarlm_1.ipnum[1]] = 1;
		    intps[ssarlm_1.ipnum[0]] = 1;

/*  CHECK THE CONNECTION POINT */
/* Computing 2nd power */
		    d__1 = sspad_1.pt[ipt * 9 - 9] - sspad_1.pt[jsix2 * 9 - 9]
			    ;
/* Computing 2nd power */
		    d__2 = sspad_1.pt[ipt * 9 - 8] - sspad_1.pt[jsix2 * 9 - 8]
			    ;
/* Computing 2nd power */
		    d__3 = sspad_1.pt[ipt * 9 - 7] - sspad_1.pt[jsix2 * 9 - 7]
			    ;
		    d1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d1 > toltol) {
			goto L460;
		    }
/*  SAVE POINTERS FOR CLOSED CONTOUR CHECK */
		    jend1 = lpt;
		    jend2 = jsix[(jcon[(icon << 1) - 2] << 2) - 4];

/*  FOLLOWING SEGMENT, NORMAL ORDER */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = ipt;
		    jsix[(nsix << 2) - 3] = lpt;
		    goto L462;

/*  CHECK THE CONNECTION POINT */
L460:
/* Computing 2nd power */
		    d__1 = sspad_1.pt[lpt * 9 - 9] - sspad_1.pt[jsix2 * 9 - 9]
			    ;
/* Computing 2nd power */
		    d__2 = sspad_1.pt[lpt * 9 - 8] - sspad_1.pt[jsix2 * 9 - 8]
			    ;
/* Computing 2nd power */
		    d__3 = sspad_1.pt[lpt * 9 - 7] - sspad_1.pt[jsix2 * 9 - 7]
			    ;
		    d2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d2 <= toltol) {
			goto L461;
		    }

/*  NEW STAND ALLONE SEGMENT */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = ipt;
		    jsix[(nsix << 2) - 3] = lpt;
		    jsix[(nsix << 2) - 2] = 0;
		    jsix[(nsix << 2) - 1] = 0;

/*   CREATE A CONTOUR TABLE ENTRY */
		    if (ncon >= 50) {
			goto L999;
		    }
		    ++ncon;
		    jcon[(ncon << 1) - 2] = nsix;
		    jcon[(ncon << 1) - 1] = nsix;
		    goto L469;
/*  SAVE POINTERS FOR CLOSED CONTOUR CHECK */
L461:
		    jend1 = ipt;
		    jend2 = jsix[(jcon[(icon << 1) - 2] << 2) - 4];

/*  FOLLOWING SEGMENT, REVERSE ORDER */
		    if (nsix >= 200) {
			goto L999;
		    }
		    ++nsix;
		    jsix[(nsix << 2) - 4] = lpt;
		    jsix[(nsix << 2) - 3] = ipt;
L462:
		    jsix[(nsix << 2) - 1] = 0;
		    jsix[(isix << 2) - 1] = nsix;
		    jsix[(nsix << 2) - 2] = isix;
		    isix = nsix;
		    jcon[(icon << 1) - 1] = isix;
/*   TEST FOR CLOSED SEGMENT */
/* Computing 2nd power */
		    d__1 = sspad_1.pt[jend1 * 9 - 9] - sspad_1.pt[jend2 * 9 - 
			    9];
/* Computing 2nd power */
		    d__2 = sspad_1.pt[jend1 * 9 - 8] - sspad_1.pt[jend2 * 9 - 
			    8];
/* Computing 2nd power */
		    d__3 = sspad_1.pt[jend1 * 9 - 7] - sspad_1.pt[jend2 * 9 - 
			    7];
		    d12 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (d12 <= toltol) {
			goto L470;
		    }
		    goto L450;
L469:

/* REINSTAL THE PREVIOUS PATCHES */
L470:
		    if (ssarlm_1.iiflag[4] <= 0) {
			goto L471;
		    }
		    lodpch_(&sscan[j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4]
			    , &ssarlm_1.iitop[24], &j2s, &c__0);
		    ssarlm_1.ipnum[1] = j2s;
		    ipnr[1] = ipnr[1] / 1000 * 1000 + j2s;
L471:
		    lodpch_(&sscan[j12], ssarlm_1.bb, ssarlm_1.iiflag, 
			    ssarlm_1.iitop, &j4s, &c__0);
		    ssarlm_1.ipnum[0] = j4s;
		    ipnr[0] = ipnr[0] / 1000 * 1000 + j4s;
L300:
		    ;
		}
/* ********************************************************************** */
L310:
		;
	    }

/*  OUTPUT OF A SINGLE SURFACE/SURFACE INTERSECTION */
	    if (ncon == 0) {
		goto L560;
	    }
	    i__3 = ncon;
	    for (icon = 1; icon <= i__3; ++icon) {
		isix = jcon[(icon << 1) - 2];
L520:
		ip1 = jsix[(isix << 2) - 4];
		ip2 = jsix[(isix << 2) - 3];
		inext = jsix[(isix << 2) - 1];
		if (ip2 < ip1) {
		    goto L530;
		}
		npt = ip2 - ip1 + 1;
		ipt = ip1;
		idir = 1;
		goto L540;
L530:
		npt = ip1 - ip2 + 1;
		ipt = ip2;
		idir = -1;
L540:
		intout_(&iout, &sspad_1.pt[ipt * 9 - 9], &npt, &idir, &j11, &
			j12, &sname, &sindex);
		if (inext == 0) {
		    goto L550;
		}
		isix = inext;
		goto L520;
L550:
		;
	    }
L560:
/* ********************************************************************** */
/* L320: */
	    ;
	}
/* ********************************************************************** */
/* L330: */
    }
/* ********************************************************************** */

/* SET THICKNESS BACK TO OLD VALUES */
L999:
    sv_1.th[ifxcor_1.ids - 1] = thdold;
    sv_1.th[ifxcor_1.ips - 1] = thpold;

    return 0;
} /* intsec_ */

#undef bcanon
#undef dummy2
#undef dummy1
#undef iword
#undef sscan
#undef thick
#undef canon
#undef poed2
#undef poed1
#undef word
#undef ipnr
#undef can
#undef pl1
#undef pl


