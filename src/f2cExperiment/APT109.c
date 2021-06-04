/* APT109.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal ua, va, pnum, ut, us, fnam;
} parmfc_;

#define parmfc_1 parmfc_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__8 = 8;
static doublereal c_b66 = 0.;
static doublereal c_b75 = 1.;
static integer c_n1 = -1;
static logical c_true = TRUE_;

/* *** SOURCE FILE : M0004508.W01   *** */

/* Subroutine */ int apt109_(doublereal *a1, integer *ii, doublereal *a2, 
	doublereal *a3, doublereal *a4, doublereal *a5, doublereal *a6, 
	doublereal *a7)
{
    /* Initialized data */

    static char tanspl[8] = "TANSPL  ";
    static char crsspl[8] = "CRSSPL  ";
    static char binorm[8] = "BINORM  ";
    static char flow[8] = "FLOW    ";
    static char xnorm[8] = "NORMAL  ";
    static char unit[8] = "UNIT    ";
    static char param[8] = "PARAM   ";
    static integer ispvc[5] = { 1,5,17,29,0 };
    static integer ispvs[4] = { 1,5,9,25 };
    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_6 = { 2, 0, 0. };


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_5[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal u;
#define aa (equiv_5)
    static doublereal ab, ac, ea[3], fa[4], fb[4], dd;
    static integer ia, j11;
    static doublereal tp[3], tn[3], sn[3];
    static integer mo, ip, iu, kk, mm, mn, is;
    static doublereal uu, vv, a4i[3], a5i[4], a6i[3];
    static integer kk1;
    extern /* Subroutine */ int bad_();
    static doublereal ddd;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal pa01, pb01, pc01;
#define jjj ((integer *)equiv_5)
    static doublereal pu01, pv01;
    static integer nwd, irr;
    static doublereal tpp[3], slx[3], spv[32], ust, vst, xyz;
    static integer mod1, ipa01, ipb01, ipc01, iflg, mode, mblk, nblk, mesh, 
	    isub, itop[24]	/* was [6][4] */, nspl, nmax;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static char test[8];
    static integer npnt;
    static doublereal root[60]	/* was [2][30] */;
#define smal1 ((doublereal *)&znumbr_1 + 15)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *), 
	    apt078_(doublereal *, integer *);
    extern logical ckdef_(doublereal *);
    static integer iflag[4], ickbn, nblk01, imode;
#define canon ((doublereal *)&_BLNK__1)
    static doublereal patch[64];
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal ddist;
    static integer isize, ipnum;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal ssdum[3], ddist1;
#define xnorm1 ((doublereal *)&equiv_6)
    extern /* Subroutine */ int gcubic_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static integer idebug;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), defext_(doublereal *);
    static integer mpatch;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *);
    static integer npatch;
    extern /* Subroutine */ int pchprc_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, logical *), holfrm_(doublereal *, char *, integer *,
	     integer *, integer *, ftnlen), lodint_(doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, integer 
	    *, integer *, integer *, integer *), curflo_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
    static doublereal distan;
    extern /* Subroutine */ int transf_(doublereal *, doublereal *, integer *,
	     integer *, integer *), cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *), cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
#define ixnorm ((integer *)&equiv_6)
    extern /* Subroutine */ int sqrcut_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;

/* ---- THIS ROUTINE HANDLES THE GEOMETRIC CONSTRUCTION RELATED WITH */
/* ---- SCULPTURED SURFACE AND CURVE */
/* ---- ARGUMENTS LIST APT109(A1,II,A2,A3,A4,A5,A6,A7) */
/* ----    AUFRUFPARAMETER: */
/* ----   II    A2    A3    A4     A5     A6    A7 */
/* ===================================================== */
/* ----   PUNKT/VEKTOR MITTELS PARAMETER AUF SYNTHETISCHER KURVE */
/* ----             PNT */
/* ----             TANSPL   FLOW              NOUNIT */
/* ----   2, SCURV ,CRSSPL ,PARAM,  T   ,  S  , UNIT */
/* ----             NORMAL */
/* ----             BINORM */
/* ===================================================== */
/* ----   PUNKT/VECTOR ALS SCHNITTPUNKT ZWISCHEN EBENE UND KURVE */
/* ----             PNT */
/* ----             TANSPL        LINE         NOUNIT */
/* ----   3, SCURV ,CRSSPL ,-----,PLANE ,POINT, UNIT */
/* ----             NORMAL */
/* ----             BINORM */
/* ===================================================== */
/* ----   PUNKT/VECTOR MITTELS PARAMETER AUF SKULPTURIERTER FLAECHE */
/* ----             PNT */
/* ----             TANSPL                     NOUNIT */
/* ----   4, SSURF ,CRSSPL ,  U  ,  V   ,  P  , UNIT */
/* ----             NORMAL */
/* ===================================================== */
/* ----   PUNKT/VECTOR IN DER NAEHE EINES PUNKTES AUF S.-FLAECHE */
/* ----             PNT */
/* ----             TANSPL                     NOUNIT */
/* ----   5, SSURF ,CRSSPL ,POINT,------,-----, UNIT */
/* ----             NORMAL */
/* ===================================================== */
/* ----   PUNKT/VECTOR  AM SCHNITTP. ZWISCHEN DER GERADEN DURCH DIE BEIDEN */
/* ----   PUNKTE UND DER S.-FLAECHE,NAECHSTLIEGEND ZUM 1. PUNKT */
/* ----             PNT */
/* ----             TANSPL                     NOUNIT */
/* ----   6, SSURF ,CRSSPL ,POINT,------,POINT, UNIT */
/* ----             NORMAL */
/* ===================================================== */
/* ---- PUNKT/VECTOR  AM SCHNITTP. ZWISCHEN DER GERADEN DURCH PUNKT */
/* ---- ENTLANG VEKTOR UND DER S.-FLAECHE,NAECHSTLIEGEND ZUM PUNKT */
/* ----             PNT */
/* ----             TANSPL                     NOUNIT */
/* ----   7, SSURF ,CRSSPL ,POINT,VECTOR,-----, UNIT */
/* ----             NORMAL */
/* ===================================================== */
/* ---- PUNKT/VECTOR  AM SCHNITTP. ZWISCHEN DER GERADEN DURCH 1. PUNKT */
/* ---- ENTLANG VEKTOR UND DER S.-FLAECHE,NAECHSTLIEGEND ZUM PUNKT, */
/* ---- DER DURCH PROJEKTION DES 2. PUNKTES AUF DIEGERADE ENTSTEHT */
/* ----             PNT */
/* ----             TANSPL                     NOUNIT */
/* ----   8, SSURF ,CRSSPL ,POINT,VECTOR,POINT, UNIT */
/* ----             NORMAL */
/* ===================================================== */

/*  DIE AUFRUF-PARAMETER HABEN SOWEIT SIE SICH NICHT SELBST ERKLAEREN */
/*  FOLGENDE BEDEUTUNG: */


/*    PNT    : IST EQUIVALENT MIT 0.0D0 UND SOLL SIGNALISIEREN, */
/*              DASS DAS ERGEBNIS EIN PUNKT SEIN SOLL */
/*    NOUNIT : IST EQUIVALENT MIT 0.0D0 UND BEDEUTET, DASS DAS ERGEBNIS */
/*              NICHT NORMALISIERT WERDEN SOLL */
/*    T      : KURVENPARAMETER */
/*    S      : KURVENSEGMENTNUMMER */
/*    U,V    : FLAECHENPARAMETER */
/*    P      : FLAECHEN-BLATT-NUMMER */
/*    -------: PARAMETER OHNE RELEVANZ */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*    SPEICHERINDEX (KK) FUER ENTSPRECHENDEN ERGEBNISPLATZ */
/* IN SPV BEI SCURV UND SSURF */
/*  UEBERGABECOMMON FUER --PARMF-- */
    /* Parameter adjustments */
    --a7;
    --a6;
    --a5;
    --a4;
    --a3;
    --a2;
    --a1;

    /* Function Body */

    parmfc_1.fnam = 0.;
    switch (*ii) {
	case 1:  goto L400;
	case 2:  goto L400;
	case 3:  goto L401;
	case 4:  goto L400;
	case 5:  goto L401;
	case 6:  goto L401;
	case 7:  goto L401;
	case 8:  goto L401;
    }
    goto L400;
L401:
    unpack_(&a2[1], &mod1, &isize, &isub);
    parmfc_1.fnam = a2[isize + 1];
    if (isub >= 1) {
	parmfc_1.fnam = a2[isub * isize + isub];
    }
L400:

/*   KONTROLL OB GEOMETRIEDEFINITIONEN IN ORDNUNG */

    switch (*ii) {
	case 1:  goto L5158;
	case 2:  goto L510;
	case 3:  goto L510;
	case 4:  goto L510;
	case 5:  goto L501;
	case 6:  goto L501;
	case 7:  goto L501;
	case 8:  goto L501;
    }
    goto L5158;
L501:
    if (ckdef_(&a4[1])) {
	goto L5157;
    }
    transf_(a4i, &a4[1], &c__2, &c__3, &c__0);
L510:
    switch (*ii) {
	case 1:  goto L5158;
	case 2:  goto L520;
	case 3:  goto L511;
	case 4:  goto L520;
	case 5:  goto L520;
	case 6:  goto L520;
	case 7:  goto L511;
	case 8:  goto L511;
    }
L511:
    if (ckdef_(&a5[1])) {
	goto L5157;
    }
    mo = 3;
    if (*ii == 3) {
	mo = 4;
    }
    transf_(a5i, &a5[1], &mo, &mo, &c__0);
L520:
    switch (*ii) {
	case 1:  goto L5158;
	case 2:  goto L530;
	case 3:  goto L521;
	case 4:  goto L530;
	case 5:  goto L530;
	case 6:  goto L521;
	case 7:  goto L530;
	case 8:  goto L521;
    }
L521:
    if (ckdef_(&a6[1])) {
	goto L5157;
    }
    transf_(a6i, &a6[1], &c__2, &c__3, &c__0);
/*    KONTROLLE DER SYNTHETISCHEN OBERFLAECHE */
L530:
    if (ckdef_(&a2[1])) {
	goto L5157;
    }

/*    ABFRAGE DER ERGEBNISART (PUNKT/TANSPL/CRSSPL/NORMAL/BINORM) */

    ia = 1;
    if (a3[1] == 0.) {
	goto L540;
    }
    ia = 2;
    holfrm_(&a3[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, tanspl, (ftnlen)8, (ftnlen)8) == 0) {
	goto L540;
    }
    ia = 3;
    if (s_cmp(test, crsspl, (ftnlen)8, (ftnlen)8) == 0) {
	goto L540;
    }
    ia = 4;
    if (a3[1] == *xnorm1) {
	goto L540;
    }
    if ((d__1 = a3[1] - 2., abs(d__1)) <= znumbr_1.z1em6) {
	goto L540;
    }
    if (s_cmp(test, xnorm, (ftnlen)8, (ftnlen)8) == 0) {
	goto L540;
    }
    ia = 5;
    if (s_cmp(test, binorm, (ftnlen)8, (ftnlen)8) == 0) {
	goto L540;
    }
    goto L5158;

/*   ABFRAGE AUF PARAM ODER FLOW */

L540:
    ip = 0;
    if (*ii != 2) {
	goto L550;
    }
    ip = 1;
    holfrm_(&a4[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, param, (ftnlen)8, (ftnlen)8) == 0) {
	goto L550;
    }
    ip = 2;
    if (s_cmp(test, flow, (ftnlen)8, (ftnlen)8) == 0) {
	goto L550;
    }
    goto L5158;

/*    ABFRAGE AUF UNIT */

L550:
    iu = 0;
    if (a7[1] == 0.) {
	goto L560;
    }
    iu = 1;
    holfrm_(&a7[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, unit, (ftnlen)8, (ftnlen)8) == 0) {
	goto L560;
    }
    goto L5158;

/*     FEHLERAUSGAENGE */

/*     FEHLER 5153 : BLATTNUMMER DER SSURF IST FALSCH */
L5153:
    idef_1.ierror = 5153;
L5150:
    ldef_1.unflag = TRUE_;
    defext_(&a1[1]);
    return 0;
/*     FEHLER 5154 : PARAMETERANGABE IST NICHT KORREKT */
/* 5154 IERROR=5154 */
/*     GOTO 5150 */
/*     FEHLER 5155 : VEKTORLAENGE IST FUER DIE NORMALISIERUNG ZU KLEIN */
L5155:
    idef_1.ierror = 5155;
    goto L5150;
/*     FEHLER 5156 : SCHNITTPUNKT KANN NICHT DEFINIERT WERDEN */
L5156:
    idef_1.ierror = 5156;
    goto L5150;
/*     FEHLER 5157 : EINGEGEBENE GEOMETRIE IST NICHT VORHER DEFINIERT */
L5157:
    idef_1.ierror = 5157;
    goto L5150;
/*     FEHLER 5158 : DEFINITIONSFEHLER */
L5158:
    idef_1.ierror = 5158;
    goto L5150;
/*     FEHLER 5159 : SPEZIFIZIERTER VEKTOR ODER PUNKT EXISTIERT NICHT */
L5159:
    idef_1.ierror = 5159;
    goto L5150;

L560:
/*    SCURV ODER SSURF  WIRD GEHOLT */

    ssdum[0] = a2[1];
    ssdum[1] = a2[2];
    ssdum[2] = a2[3];
    imode = 3;
    apt094_(&imode, ssdum, &j11);
    if (ckdef_(ssdum)) {
	goto L5157;
    }
    j11 += -41;

/*  PARAMETER-UEBERTRAGUNG IN ABHAENGIGKEIT VON DER AUFGABE */

    switch (*ii) {
	case 1:  goto L5158;
	case 2:  goto L572;
	case 3:  goto L573;
	case 4:  goto L574;
	case 5:  goto L575;
	case 6:  goto L576;
	case 7:  goto L577;
	case 8:  goto L578;
    }

/* PUNKT/VECTOR MITTELS PARAMETER AUS SCURV */

L572:
    u = a5[1];
    i__ = (integer) a6[1];
/*   UMSPEICHERINDEX FUER SPV */
L581:
    kk = ispvc[ia - 1];
/*   STEUERUNG FUER ROUTINE CURFLO */
    mm = 1;
    if (ia < 3) {
	goto L580;
    }
    mm = 2;
    goto L580;

/*  PUNKT/VEKTOR AM DURCHSTOSSPUNKT SCURV/EBENE */

L573:
    for (mn = 1; mn <= 3; ++mn) {
	ea[mn - 1] = a6i[mn - 1];
/* L301: */
	fa[mn - 1] = a5i[mn - 1];
    }
    fa[3] = -a5i[3];
    goto L581;

/*  PUNKT/VECTOR MITTELS PARAMETER AUS SSURF */

L574:
    pa01 = a4[1];
    pb01 = a5[1];
    pc01 = a6[1];
    mpatch = (integer) can[j11 + 3];
    mesh = (integer) can[j11 + 4];
    if (abs(pc01) > *smal1) {
	goto L2250;
    }
    nspl = (integer) (can[j11 + 8] - 1.f);
    npnt = (integer) (can[j11 + 9] - 1.f);
    ipa01 = (integer) pa01;
    ipb01 = (integer) pb01;
    if (ipa01 < npnt) {
	goto L2110;
    }
    ipa01 = npnt - 1;
L2130:
    pu01 = pa01 - ipa01;
L2140:
    if (ipb01 < nspl) {
	goto L2120;
    }
    ipb01 = nspl - 1;
L2150:
    pv01 = pb01 - ipb01;
L2160:
    npatch = ipb01 * npnt + ipa01 + 1;
    goto L2310;
L2110:
    if (ipa01 >= 0) {
	goto L2130;
    }
    ipa01 = 0;
    pu01 = pa01;
    goto L2140;
L2120:
    if (ipb01 >= 0) {
	goto L2150;
    }
    ipb01 = 0;
    pv01 = pb01;
    goto L2160;
L2250:
    if (pc01 < 0.) {
	goto L5153;
    }
    ipc01 = (integer) pc01;
    if (ipc01 > mpatch || ipc01 <= 0) {
	goto L5153;
    }
    pu01 = pa01;
    pv01 = pb01;
    npatch = ipc01;
L2310:
    lodpch_(&can[j11], patch, iflag, itop, &npatch, &c__1);

    kk = ispvs[ia - 1];
/*       STEUERUNG FUER ROUTINE CNSURF */
    mm = 0;
    if (ia == 1) {
	goto L580;
    }
    mm = 1;
    goto L580;

/*    PUNKT/VEKTOR IN DER NAEHE EINES PUNKTES AUF DER SSURF */

L575:
    tp[0] = a4i[0];
    tp[1] = a4i[1];
    tp[2] = a4i[2];
    tn[0] = 0.f;
    tn[1] = 0.f;
    tn[2] = 1.f;
    mode = 0;
L585:
    kk = ispvs[ia - 1];
    goto L580;

/*   PUNKT/VEKTOR AUF GERADEN (DURCH 2 PUNKTE) UND SSURF */

L576:
    for (mn = 1; mn <= 3; ++mn) {
	tp[mn - 1] = a4i[mn - 1];
	tn[mn - 1] = a6i[mn - 1] - a4i[mn - 1];
/* L584: */
    }
    mode = -1;
    goto L585;

/*    PUNKT/VECTOR AUF GERADEN (DURCH PUNKT,ENTLANG VEKTOR) UND SSURF */

L577:
    for (mn = 1; mn <= 3; ++mn) {
	tp[mn - 1] = a4i[mn - 1];
	tn[mn - 1] = a5i[mn - 1];
/* L583: */
    }
    mode = -1;
    goto L585;

/*    PUNKT/VEKTOR AUF GERADEN (PUNKT,VECTOR),NAHE EINEM PUNKT,AUF SSURF */

L578:
    for (mn = 1; mn <= 3; ++mn) {
	tn[mn - 1] = a5i[mn - 1];
	tp[mn - 1] = a6i[mn - 1];
	tpp[mn - 1] = a4i[mn - 1];
	tp[mn - 1] -= tpp[mn - 1];
/* L582: */
    }
    dd = sqrt(tn[0] * tn[0] + tn[1] * tn[1] + tn[2] * tn[2]);
    if (dd < *smal1) {
	goto L5155;
    }
    ddd = tp[0] * tn[0] + tp[1] * tn[1] + tn[2] * tp[2];
    ddd /= dd;
    tp[0] = ddd * (tn[0] / dd) + tpp[0];
    tp[1] = ddd * (tn[1] / dd) + tpp[1];
    tp[2] = ddd * (tn[2] / dd) + tpp[2];
    mode = -1;
    goto L585;

/* =================================================================== */
/*    DURCHFUEHRUNG DER AUFGABEN */
/* =================================================================== */

L580:
    switch (*ii) {
	case 1:  goto L5158;
	case 2:  goto L2000;
	case 3:  goto L3000;
	case 4:  goto L4000;
	case 5:  goto L6000;
	case 6:  goto L6000;
	case 7:  goto L6000;
	case 8:  goto L6000;
    }

/*  PUNKT/VEKTOR MITTELS PARAMETER AUS SCURV */
L2000:
/*  AUF ALLE FAELLE AUSSPEICHERN DER 'ANZAHL FLOW-SEGMENTE' */
    nmax = (integer) can[j11 + 7];
    if (ip == 2) {
	goto L2100;
    }
/*  BEI PARAM-INTERPOLATION WIRD CAN(J11+8) VORUEBERGEHEND 0.0D0 */
    can[j11 + 7] = 0.;
L2100:
    curflo_(&u, &can[j11], spv, &mm, &i__);
/*  NMAX WIRD WIEDER EINGESETZT */
    can[j11 + 7] = (doublereal) nmax;
/*   VERZWEIGUN NACH ERGEBNISART */
    switch (ia) {
	case 1:  goto L2200;
	case 2:  goto L2200;
	case 3:  goto L2300;
	case 4:  goto L2300;
	case 5:  goto L2400;
    }
L2200:
    a1[1] = spv[kk - 1];
    a1[2] = spv[kk];
    a1[3] = spv[kk + 1];
    if (ia == 1) {
	goto L9100;
    }
    goto L9200;
/*   GUELTIGKEITS ABFRAGE BEI CRSSPL U. NORMAL */
L2300:
    if (spv[19] != 1.) {
	goto L5159;
    }
    goto L2200;
/*   BERECHNUNG DER BINORMALEN */
L2400:
    cross_(&spv[4], &spv[8], &a1[1]);
    goto L9200;

/*   PUNKT/VECTOR AUF EBENE UND SCURV  (DURCHSTOSSGEOMETRIE) */

L3000:
    mblk = (integer) can[j11 + 3];
    kk1 = 0;
    nblk = 1;
/*   BERECHNUNG BEI DER ANFANGSTANGENTE (AUSSERHALB LIEGENDER PUNKT) */
    cncurv_(&c_b66, &can[j11 + 24], spv, &c__1);
    ab = fa[0] * spv[0] + fa[1] * spv[1] + fa[2] * spv[2] + fa[3];
    ac = fa[0] * spv[4] + fa[1] * spv[5] + fa[2] * spv[6];
    if (abs(ac) < 1e-6) {
	goto L370;
    }
    xyz = -ab / ac;
    if (xyz > 1e-5) {
	goto L370;
    }
/*   PUNKT GEFUNDEN */
    ++kk1;
    root[(kk1 << 1) - 2] = (doublereal) (j11 + 25);
    root[(kk1 << 1) - 1] = xyz;
L370:
    nblk01 = nblk * 24 + j11 + 1;
    for (nspl = 1; nspl <= 4; ++nspl) {
/* L320: */
	spv[nspl - 1] = 0.f;
    }
    for (npnt = 1; npnt <= 4; ++npnt) {
	mn = npnt - 1 << 2;
	for (nspl = 1; nspl <= 4; ++nspl) {
/* L331: */
	    fb[nspl - 1] = can[nblk01 + mn + nspl - 2];
	}
	spv[0] += fa[npnt - 1] * (fb[0] * 2 - fb[1] * 2 + fb[2] + fb[3]);
	spv[1] += fa[npnt - 1] * (fb[0] * -3 + fb[1] * 3 - fb[2] * 2 - fb[3]);
	spv[2] += fa[npnt - 1] * fb[2];
/* L330: */
	spv[3] += fa[npnt - 1] * fb[0];
    }
    gcubic_(spv, &spv[1], &spv[2], &spv[3], fb, &mn);
    if (mn == 0) {
	goto L380;
    }
    i__1 = mn;
    for (nspl = 1; nspl <= i__1; ++nspl) {
	xyz = fb[nspl - 1];
	if (xyz >= -1e-5 && xyz < 1.00001) {
	    ++kk1;
	    root[(kk1 << 1) - 2] = (doublereal) nblk01;
	    root[(kk1 << 1) - 1] = fb[nspl - 1];
	}



/* L340: */
    }
L380:
    ++nblk;
    if (nblk > mblk) {
	goto L360;
    }
    goto L370;
/*   BERECHNUNG BEI DER ENDTANGENTE (AUSSERHALB LIEGENDER PUNKT) */
L360:
    cncurv_(&c_b75, &can[nblk01 - 1], spv, &c__1);
    ab = fa[0] * spv[0] + fa[1] * spv[1] + fa[2] * spv[2] + fa[3];
    ac = fa[0] * spv[4] + fa[1] * spv[5] + fa[2] * spv[6];
    if (abs(ac) < 1e-6) {
	goto L361;
    }
    xyz = -ab / ac + 1.;
    if (xyz < .99999) {
	goto L361;
    }
/*   PUNKT GEFUNDEN */
    ++kk1;
    root[(kk1 << 1) - 2] = (doublereal) nblk01;
    root[(kk1 << 1) - 1] = xyz;
L361:
    if (kk1 == 0) {
	goto L5156;
    }
    mn = 1;
L335:
    nblk01 = (integer) root[(mn << 1) - 2];
    cncurv_(&root[(mn << 1) - 1], &can[nblk01 - 1], spv, &c__1);
/* Computing 2nd power */
    d__1 = spv[0] - ea[0];
/* Computing 2nd power */
    d__2 = spv[1] - ea[1];
/* Computing 2nd power */
    d__3 = spv[2] - ea[2];
    ddist1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    if (mn != 1) {
	goto L315;
    }
L325:
    a1[1] = spv[0];
    a1[2] = spv[1];
    a1[3] = spv[2];
    parmfc_1.ut = root[(mn << 1) - 1];
    is = (integer) ((root[(mn << 1) - 2] - j11) / 24.);
    parmfc_1.us = (doublereal) is;
    ddist = ddist1;
L345:
    ++mn;
    if (mn > kk1) {
	goto L3100;
    }
    goto L335;
L315:
    if (ddist > ddist1) {
	goto L325;
    }
    goto L345;
/*  DURCHSTOSSPUNKT GEFUNDEN */
L3100:
    if (ia == 1) {
	goto L9100;
    }
/* VEKTOR WIRD GEWUENSCHT:INTERPOLATION DES VEKTORS WIRD VORBEREITET */
    ip = 1;
    u = parmfc_1.ut;
    nblk01 = (integer) (parmfc_1.us * 24. + 1. + j11);
    i__ = (integer) parmfc_1.us;
    goto L2000;

/*  PUNKT/VEKTOR MITTELS PARAMETER AUS SSURF */

L4000:
    cnsurf_(&pu01, &pv01, patch, spv, iflag, &mm);
    goto L2200;

/*   PUNKT/VEKTOR AM ANNAEHERUNGS- O. DURCHSTOSS-PUNKT AUF SSURF */

L6000:
    dd = sqrt(tn[0] * tn[0] + tn[1] * tn[1] + tn[2] * tn[2]);
    if (dd < *smal1) {
	goto L5155;
    }
    tn[0] /= dd;
    tn[1] /= dd;
    tn[2] /= dd;
    iflg = 0;
L5489:
    idebug = ibugg_1.ibug;
    lodint_(&can[j11], patch, &ust, &vst, tp, tn, iflag, itop, &ipnum, &mode);
    if (idebug <= 0) {
	goto L5487;
    }
    bad_(&c__1, &c__0, "A109", &ipnum, (ftnlen)4);
    bad_(&c__1, &c__1, "UST ", &ust, (ftnlen)4);
    bad_(&c_n1, &c__1, "VST ", &vst, (ftnlen)4);
L5487:
    sqrcut_(&znumbr_1.z5em1, &znumbr_1.z5em1, &ust, &vst, &uu, &vv, &ickbn);
    ust = znumbr_1.z5em1 + (uu - znumbr_1.z5em1) * .9999;
    vst = znumbr_1.z5em1 + (vv - znumbr_1.z5em1) * .9999;
/* ...CALL PCHPRC WITH LAST PARAMETER .TRUE. FOR GEOMETRIC CONSTRUCTION */
    pchprc_(&can[j11], patch, &ust, &vst, tp, tn, &parmfc_1.ua, &parmfc_1.va, 
	    spv, sn, slx, iflag, itop, &ipnum, &mode, &idebug, &irr, &c_true);
    parmfc_1.pnum = (doublereal) ipnum;
    if (spv[kk + 2] == 0.) {
	goto L5159;
    }
    if (iflg != 0) {
	goto L5494;
    }
    iflg = 1;
    for (mn = 1; mn <= 3; ++mn) {
/* L5490: */
	tpp[mn - 1] = spv[mn - 1] - tp[mn - 1];
    }
    dotv_(&ddd, tpp, tpp);
    ddd += -.1;
    dotv_(&dd, tpp, tn);
    if (dd < 0.f) {
	goto L5492;
    }
/* ---      POINT IS SAME DIRECTION AS VECTOR */
    for (mn = 1; mn <= 3; ++mn) {
/* L5491: */
	tp[mn - 1] += ddd * tn[mn - 1];
    }
    goto L5489;
L5492:
    for (mn = 1; mn <= 3; ++mn) {
/* L5493: */
	tp[mn - 1] -= ddd * tn[mn - 1];
    }
    goto L5489;
L5494:
    goto L2200;

/* ======================================================================= */

/*    ABGESANG */
L9100:
    transf_(dshar3_1.p, &a1[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.km1);
    defext_(&a1[1]);
    return 0;
L9200:
    if (iu == 0) {
	goto L9250;
    }
    distan = sqrt(a1[1] * a1[1] + a1[2] * a1[2] + a1[3] * a1[3]);
    if (distan < *smal1) {
	goto L5155;
    }
    a1[1] /= distan;
    a1[2] /= distan;
    a1[3] /= distan;
/*    FALLS NOTWENDIG TRANSFORMIEREN UND ZURUECK */
L9250:
    apt078_(&a1[1], &knumbr_1.km1);
    defext_(&a1[1]);
    return 0;
} /* apt109_ */

#undef ixnorm
#undef bcanon
#undef xnorm1
#undef sscan
#undef canon
#undef smal1
#undef jjj
#undef can
#undef aa


