/* PRO021.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer stklst[300];
} stklst_;

#define stklst_1 stklst_

struct {
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer first[6]	/* was [2][3] */;
} blkcfs_;

#define blkcfs_1 blkcfs_

struct {
    integer bgeom[4];
} bgeom_;

#define bgeom_1 bgeom_

/* Table of constant values */

static integer c__2001 = 2001;
static integer c__8 = 8;
static integer c__2052 = 2052;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__4 = 4;

/* *** SOURCE FILE : M0006666.W01   *** */


/*              FORTRAN SUBROUTINE PRO021 */

/* LINKAGE      SUBROUTINE PRO021(RESULT,I,ERRP) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CALLZZ          SUBROUTINE    PRO020 */
/*          INTEGER FCT.  MODE */
/*          INTEGER FCT.  NUMB */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    REFGEN */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    ARGGEN */

/* Subroutine */ int pro021_(integer *result, integer *i__, integer *errp)
{
    /* Initialized data */

    static char itwopt[12] = "2.          ";
    static integer narg[266]	/* was [7][38] */ = { -12,3,0,2,1,0,0,-12,4,0,
	    3,2,1,0,-14,3,0,2,1,0,0,-14,4,0,3,2,1,0,-14,5,0,3,2,1,0,-13,2,0,0,
	    3,1,0,-16,3,0,2,0,1,0,-16,4,0,2,0,1,0,-18,4,0,3,2,1,0,-18,5,0,3,2,
	    1,0,-17,3,0,2,1,0,0,-17,4,0,2,1,0,0,-15,2,0,1,0,0,0,-15,3,0,1,0,0,
	    0,-12,5,2,4,3,0,1,-12,6,2,5,4,3,1,-12,4,1,3,2,0,0,-12,5,1,4,3,2,0,
	    -14,5,2,4,3,0,1,-14,6,2,5,4,3,1,-14,7,2,5,4,3,1,-14,4,1,3,2,0,0,
	    -14,5,1,4,3,2,0,-14,6,1,4,3,2,0,-13,3,1,0,4,2,0,-13,4,2,0,5,3,1,
	    -15,3,1,2,0,0,0,-15,4,2,3,0,0,1,-15,4,1,2,0,0,0,-16,4,1,3,0,2,0,
	    -16,5,2,4,0,3,1,-16,5,1,3,0,2,0,-17,4,1,3,2,0,0,-17,5,2,4,3,0,1,
	    -17,5,1,3,2,0,0,-18,5,1,4,3,2,0,-18,6,2,5,4,3,1,-18,6,1,4,3,2,0 };
    static integer iargz[38] = { 4,5,4,5,6,4,4,5,5,6,4,5,3,4,6,7,5,6,6,7,8,5,
	    6,7,5,6,4,5,5,5,6,6,5,6,6,6,7,7 };
    static integer kgt = 0;
    static integer p[5] = { 1,1,1,1,1 };
    static integer icf[300] = { 4,4,3,5,5,5,3,4,4,-2,5,5,5,4,4,3,4,-1,-4,4,4,
	    4,3,5,4,4,3,5,-3,4,5,5,6,4,4,6,6,7,11,5,3,3,4,-1,3,5,5,5,-1,5,7,
	    -4,5,6,7,7,8,8,-1,4,6,5,3,4,5,-1,-1,-1,7,7,6,-1,-1,-1,6,5,5,4,5,3,
	    5,-1,7,9,-1,-5,-6,-1,7,-9,-1,-1,-1,-1,-1,-1,-1,-1,-1,7,4,3,5,4,7,
	    4,5,5,13,3,2,2,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,
	    5,4,4,6,9,8,7,7,5,8,7,6,6,4,7,6,5,5,4,7,6,5,5,4,3,4,8,12,11,10,6,
	    5,5,-7,-8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,6,5,6,7,5,5,
	    6,6,7,5,6,4,5,7,8,6,7,7,8,9,6,7,8,6,7,5,6,6,6,7,7,6,7,7,7,8,8,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, l, m, n, i1, j1, na, nb, i66, kk, kt2;
#define one ((integer *)&numptr_1 + 2)
#define top ((integer *)&stklst_1)
#define two ((integer *)&numptr_1 + 4)
#define iarg ((integer *)&numptr_1 + 3)
    extern integer mode_(integer *);
    static integer iref;
#define geom ((integer *)&code_1 + 30)
#define line ((integer *)&modx_1)
#define fsub ((integer *)&il_1 + 1)
    extern integer numb_(char *, ftnlen);
    static integer isav;
#define move ((integer *)&il_1 + 18)
#define zero ((integer *)&numptr_1)
    static integer narg1;
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
    static integer kmode;
#define undef ((integer *)&sublst_1 + 73)
#define stack ((integer *)&stklst_1 + 3)
#define three ((integer *)&numptr_1 + 5)
#define onept ((integer *)&numptr_1 + 3)
#define point ((integer *)&modx_1 + 18)
    static integer errpt, twopt, izres1, izres2;
    extern /* Subroutine */ int arggen_(void);
#define ifbnds ((integer *)&bgeom_1)
#define object ((integer *)&modx_1 + 27)
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), refgen_(integer *, 
	    integer *);
    extern integer search_(integer *, integer *, integer *, integer *);
#define defext ((integer *)&sublst_1 + 81)
    extern /* Subroutine */ int argcvt_(integer *);
#define bounds ((integer *)&modx_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
    extern /* Subroutine */ int callzz_(integer *);
    extern integer gettmp_(integer *);
#define vector ((integer *)&modx_1 + 19)
    extern /* Subroutine */ int rlslin_(void);
#define matrix ((integer *)&modx_1 + 17)
    extern /* Subroutine */ int twoarg_(integer *, integer *);
#define zeropt ((integer *)&numptr_1 + 1)
    extern /* Subroutine */ int puttmp_(integer *);
#define aptxxx ((integer *)&sublst_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* IFIXST:      NAMTBL INDEX OF BEGINNING OF FIXED POINT NUMBER SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* THREE:       NAMTBL POINTER TO '3     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       16.    LITERALS FOR I. L. OPERATION CODES */




/* FSUB:        CONTAINS COMMAND CODE ( 2) FOR FSUB COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* LINE:        MODE CODE ( 1) FOR LINE */
/* MATRIX:      MODE CODE (18) FOR MATRIX */
/* POINT:       MODE CODE (19) FOR POINT */
/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* BOUNDS:      MODE CODE (27) FOR BOUNDS */
/* OBJECT:      MODE CODE (28) FOR OBJECT */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */
/* UNDEF:       NAMTBL POINTER TO EXECUTION SUBROUTINE UNDEF */
/* DEFEXT:      NAMTBL POINTER TO EXECUTION SUBROUTINE DEFEXT */

/*       29.    CLASS CODE MODULI */

/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       30.    NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK */
/*              NAMTBL POINTER TO FIRST CANONICAL FORMS IN EACH BLOCK */

/*       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE */

/* IFBNDS:      VALUE 1 IF BOUNDED GEOMETRY IS INCLUDED IN PART PROGRAM */
/* * */
/* ARGUMENTS    RESULT  ARRAY TO CONTAIN CANONICAL FORM WHEN */
/*                      I.L. IS EXECUTED */
/*              I       CURRENT PRODUCTION NUMBER */
/* ** */

/*    STEUER DATEN FUER ERWEITERTE PUNKT/VECTOR-DEFINITIONEN */
/*   201: PT/IN, SC,P/F,  R       ;202:PT/IN, SC,P/F,  R,  R */
/*   203: PT/IN, SS,  R,  R       ;204:PT/IN, SS,  R,  R,  R */
/*   205: PT/IN, SS,P/F,  R,R,R   ;206:PT/IN,L/P, SC, PT */
/*   207: PT/IN, SS, PT, PT       ;208:PT/IN, SS,P/F, PT, PT */
/*   209: PT/IN, SS, PT, VT, PT   ;210:PT/IN, SS,P/F, PT, VT, PT */
/*   211: PT/IN, SS, PT, VT       ;212:PT/IN, SS,P/F, PT, VT */
/*   213: PT/IN, SS, PT           ;214:PT/IN, SS,P/F, PT */
/*   215: VT/IN, SC,P/F,  R,TA1, U;216:VT/IN, SC,P/F,  R,  R,TA1, U */
/*   217: VT/IN, SC,P/F,  R,TA1   ;218:VT/IN, SC,P/F,  R,  R,TA1 */
/*   219: VT/IN, SS,  R,  R,TA2, U;220:VT/IN, SS,  R,  R,  R,TA2, U */
/*   221: VT/IN,SS,P/F,R,R,R,TA2,U;222:VT/IN, SS,  R,  R,TA2 */
/*   223: VT/IN, SS,  R,  R, R,TA2;224:VT/IN, SS,P/F,  R,  R,  R,TA2 */
/*   225: VT/IN,L/P, SC, PT,TA1   ;226:VT/IN,L/P, SC, PT,TA1, U */
/*   227: VT/IN, SS, PT,TA2       ;228:VT/IN, SS, PT,TA2, U */
/*   229: VT/IN, SS,P/F, PT,TA2   ;230:VT/IN, SS, PT, PT,TA2 */
/*   231: VT/IN, SS, PT, PT,TA2, U;232:VT/IN, SS,P/F, PT, PT,TA2 */
/*   233: VT/IN, SS, PT, VT,TA2   ;234:VT/IN, SS, PT, VT,TA2, U */
/*   235: VT/IN, SS,P/F, PT,VT,TA2;236:VT/IN, SS, PT, VT, PT,TA2 */
/*   237: VT/IN,SS,PT,VT, PT,TA2,U;238:VT/IN, SS,P/F, PT, VT, PT,TA2 */
/*  BEDEUTUNG DER PARAMETER-KUERZEL: IN=INTOF , SC=SCURV , SS=SSURF , */
/*     P/F=PARAM/FLOW , R=REAL , PT=POINT , VT=VECTOR , L/P=LINE/PLANE , */
/*     TA1=TANSPL/CRSSPL/NORMAL/BINORM , TA2=TANSPL/CRSSPL/NORMAL */
/*   STEUER-ARGUMENT-ERZEUGUNG MITTELS ZEIGER AUS COMMON/NUMPTR/ */

/*     ANZAHL DER ARGUMENTE */
/* ICF                ( 5)           (10)           (15)           (20) */
/* ICF                (25)           (30)           (35)           (40) */
/* ICF                (45)           (50)           (55)           (60) */
/* ICF                (65)           (70)           (75)           (80) */
/* ICF                (85)           (90)                         (100) */
/* ICF               (105)          (110) */
/* ICF               (155)          (160)          (165)          (170) */
/* ICF               (175)          (180)          (185) */
/* ICF               (205)          (210)          (215)          (220) */
/* ICF               (225)          (230)          (235) */
/*     PRODUKTION NICHT GEFUNDEN */
    errpt = -(*errp);
    if (errpt >= 0) {
	errpt = -1;
    }
    if (*i__ == 200) {
	goto L999;
    }
/*     PRUEFEN DER ANZAHL DER ARGUMENTE */
    i1 = icf[*i__ - 1];
    if (i1 < 0) {
	goto L91;
    }
    if (i1 == *argtop) {
	goto L100;
    }
    errpt = i1 - *argtop;
    goto L998;
L91:
    i1 = -i1;
    switch (i1) {
	case 1:  goto L998;
	case 2:  goto L92;
	case 3:  goto L93;
	case 4:  goto L94;
	case 5:  goto L100;
	case 6:  goto L100;
	case 7:  goto L100;
	case 8:  goto L100;
	case 9:  goto L90;
    }
    goto L998;
L90:
    *i__ = 27;
    if (*argtop == 5) {
	goto L100;
    }
    goto L998;
L92:
    if (*argtop == 6) {
	goto L100;
    }
    goto L95;
L93:
    if (*argtop == 3) {
	goto L100;
    }
    goto L95;
L94:
    if (*argtop == 4) {
	goto L100;
    }
L95:
    errpt = 7 - i1 / 3 - *argtop;
    if (errpt > 0) {
	errpt = -1;
    }
    if (*argtop != 5) {
	goto L998;
    }

L100:
    if (*i__ >= 100) {
	goto L151;
    }
L101:
    callzz_(&aptxxx[*i__ - 1]);
    argcvt_(result);
    if (*i__ > 50) {
	goto L102;
    }
    switch (*i__) {
	case 1:  goto L2001;
	case 2:  goto L2002;
	case 3:  goto L2003;
	case 4:  goto L2004;
	case 5:  goto L2005;
	case 6:  goto L2006;
	case 7:  goto L2007;
	case 8:  goto L2008;
	case 9:  goto L2009;
	case 10:  goto L2010;
	case 11:  goto L2011;
	case 12:  goto L2012;
	case 13:  goto L2013;
	case 14:  goto L2014;
	case 15:  goto L2015;
	case 16:  goto L2016;
	case 17:  goto L2017;
	case 18:  goto L2018;
	case 19:  goto L2019;
	case 20:  goto L2020;
	case 21:  goto L2021;
	case 22:  goto L2022;
	case 23:  goto L2023;
	case 24:  goto L2024;
	case 25:  goto L2025;
	case 26:  goto L2026;
	case 27:  goto L2027;
	case 28:  goto L2028;
	case 29:  goto L2029;
	case 30:  goto L2030;
	case 31:  goto L2031;
	case 32:  goto L2032;
	case 33:  goto L2033;
	case 34:  goto L2034;
	case 35:  goto L2035;
	case 36:  goto L2036;
	case 37:  goto L2037;
	case 38:  goto L2038;
	case 39:  goto L2039;
	case 40:  goto L2040;
	case 41:  goto L2041;
	case 42:  goto L2042;
	case 43:  goto L2043;
	case 44:  goto L2044;
	case 45:  goto L2045;
	case 46:  goto L2046;
	case 47:  goto L2047;
	case 48:  goto L2048;
	case 49:  goto L2049;
	case 50:  goto L2050;
    }
L102:
    *i__ += -50;
    switch (*i__) {
	case 1:  goto L2051;
	case 2:  goto L2052;
	case 3:  goto L2053;
	case 4:  goto L2054;
	case 5:  goto L2055;
	case 6:  goto L2056;
	case 7:  goto L2057;
	case 8:  goto L2058;
	case 9:  goto L2059;
	case 10:  goto L2060;
	case 11:  goto L2061;
	case 12:  goto L2062;
	case 13:  goto L2063;
	case 14:  goto L2064;
	case 15:  goto L2065;
	case 16:  goto L2066;
	case 17:  goto L2067;
	case 18:  goto L2068;
	case 19:  goto L2069;
	case 20:  goto L2070;
	case 21:  goto L2071;
	case 22:  goto L2072;
	case 23:  goto L2073;
	case 24:  goto L2074;
	case 25:  goto L2075;
	case 26:  goto L2076;
	case 27:  goto L2077;
	case 28:  goto L2078;
	case 29:  goto L2079;
	case 30:  goto L2080;
	case 31:  goto L2081;
	case 32:  goto L2082;
	case 33:  goto L2083;
	case 34:  goto L2084;
	case 35:  goto L2085;
	case 36:  goto L2086;
	case 37:  goto L2087;
	case 38:  goto L2088;
	case 39:  goto L2089;
    }
/*    FEHLERAUSGANG FUER PRODUKTIONSNUMMERN 91 BIS 99 */
    goto L998;
/*   SONDERDEFINITIONEN */
L151:
    if (*i__ > 200) {
	goto L2201;
    }
    if (*i__ > 150) {
	goto L152;
    }

    *i__ += -99;
    switch (*i__) {
	case 1:  goto L2100;
	case 2:  goto L2101;
	case 3:  goto L2102;
	case 4:  goto L2103;
	case 5:  goto L2104;
	case 6:  goto L2105;
	case 7:  goto L2106;
	case 8:  goto L2107;
	case 9:  goto L2108;
	case 10:  goto L2109;
	case 11:  goto L2110;
	case 12:  goto L2111;
	case 13:  goto L2112;
	case 14:  goto L2113;
    }
    goto L999;
/* MACRO-DEFINITIONEN UND SONSTIGES */
L152:
    *i__ += -150;
    switch (*i__) {
	case 1:  goto L2151;
	case 2:  goto L2152;
	case 3:  goto L2153;
	case 4:  goto L2154;
	case 5:  goto L2155;
	case 6:  goto L2156;
	case 7:  goto L2157;
	case 8:  goto L2158;
	case 9:  goto L2159;
	case 10:  goto L2160;
	case 11:  goto L2161;
	case 12:  goto L2162;
	case 13:  goto L2163;
	case 14:  goto L2164;
	case 15:  goto L2165;
	case 16:  goto L2166;
	case 17:  goto L2167;
	case 18:  goto L2168;
	case 19:  goto L2169;
	case 20:  goto L2170;
	case 21:  goto L2171;
	case 22:  goto L2172;
	case 23:  goto L2173;
	case 24:  goto L2174;
	case 25:  goto L2175;
	case 26:  goto L2176;
	case 27:  goto L2177;
	case 28:  goto L2178;
	case 29:  goto L2179;
	case 30:  goto L2180;
	case 31:  goto L2181;
	case 32:  goto L2182;
	case 33:  goto L2183;
	case 34:  goto L2184;
	case 35:  goto L2185;
	case 36:  goto L2186;
    }
    goto L999;
/*  FEHLERAUSGANG */
L2018:
L2044:
L2049:
L2059:
L2066:
L2067:
L2068:
L2072:
L2073:
L2074:
L2082:
L2085:
L2088:
L999:
    alarm_(&c__2001, &errpt, &c__8, "PRO021  ", (ftnlen)8);
L997:
    callzz_(undef);
    argcvt_(result);
    rlslin_();
    *argtop = 0;
    return 0;

L998:
    alarm_(&c__2052, &errpt, &c__8, "PRO021  ", (ftnlen)8);
    goto L997;

/*   1.ARGUMENT AUSLASSEN,SONST ALLE AUSGEBEN --- VERARBEITUNGSART A */
L2001:
L2003:
L2004:
L2006:
L2014:
L2017:
L2023:
L2028:
L2030:
L2036:
L2037:
L2040:
L2042:
L2048:
L2053:
L2060:
L2062:
L2077:
L2080:
L2081:
L20011:
    *argtop += -2;
    arggen_();
    rlslin_();
    return 0;
/*  VORLETZTES ARGUMENT AUSLASSEN                  VERARBEITUNGSART B */
L2057:
L2058:
L2084:
    argcvt_(&argstk[6]);
L2056:
    argcvt_(&argstk[5]);
L2055:
L20551:
    argcvt_(&argstk[4]);
L2050:
L2054:
L20501:
    argcvt_(&argstk[3]);
L2002:
L2008:
L2009:
L2012:
L2013:
L2019:
L2020:
L2022:
L2026:
L2031:
L20571:
    argcvt_(&argstk[2]);
    argcvt_(argstk);
    *argtop = 0;
    rlslin_();
    return 0;
/*    ALLE ARGUMENTE AUSGEBEN                VERARBEITUNGSART C */
L2005:
L2007:
L2011:
L2015:
L2016:
L2024:
L2025:
L2032:
L2033:
L2034:
L2035:
L2038:
L2039:
L2043:
L2063:
L2064:
L2078:
L2079:
L2083:
L2089:
L20051:
    --(*argtop);
    arggen_();
    rlslin_();
    return 0;
/*  LINE/(ATA/SLO),R,INTERC,(XA/YA),R   VERARBEITUNGSART D */
L2010:
    if (*argtop == 5) {
	goto L20101;
    }
    argstk[2] = argstk[1];
    goto L20551;
L20101:
    argstk[1] = *two;
    --(*argtop);
    arggen_();
    rlslin_();
    return 0;
/*  2. ARGUMENT ELIMINIEREN             VERARBEITUNGSART E */
L2046:
L2047:
L2065:
L2076:
    argstk[2] = argstk[1];
    goto L20501;
/*  SPEZIAL: UMSPEICHERN DER ARGUMENTE  VERARBEITUNGSART F */
L2021:
    argstk[1] = argstk[0];
    argstk[0] = argstk[2];
    goto L20011;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART G */
L2029:
    if (*argtop > 3) {
	goto L20571;
    }
    goto L20051;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART H */
L2041:
    argstk[2] = argstk[1];
    argstk[1] = argstk[0];
    argstk[0] = *one;
    arggen_();
    rlslin_();
    return 0;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART I */
L2051:
    argcvt_(&argstk[5]);
    goto L20501;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART J */
L2052:
    if (*argtop == 4) {
	goto L20051;
    }
    argstk[0] = argstk[1];
    goto L20501;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART K */
L2061:
    argcvt_(argstk);
    argcvt_(&argstk[3]);
    argcvt_(&argstk[1]);
    *argtop = 0;
    rlslin_();
    return 0;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART L */
L2069:
    for (j = 1; j <= 5; ++j) {
/* L20691: */
	argstk[j - 1] = argstk[j];
    }
    *argtop = 5;
    arggen_();
    argcvt_(two);
    rlslin_();
    return 0;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART M */
L2071:
    *argtop = 5;
    arggen_();
    argcvt_(one);
    rlslin_();
    return 0;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART N */
L2070:
    argcvt_(&argstk[5]);
    argcvt_(&argstk[4]);
    argcvt_(&argstk[2]);
    argcvt_(&argstk[1]);
    *argtop = 0;
    rlslin_();
    return 0;
/*  SPEZIALVERARBEITUNG                 VERARBEITUNGSART O */
L2075:
    *argtop += -3;
    arggen_();
    rlslin_();
    return 0;
/*  POINT/CLDATA,N  = PR. 27 ; POINT/CLDATA,N1,TP,N1  = PR. 90 */
/*  VECTOR/CLDATA,N = PR. 27 ; VECTOR/CLDATA,N1,TV,N2= PR. 90 */
L20271:
    argstk[*argtop - 2] = *zero;
/*   UNTERSUCHUNG OB VECTOR */
    kmode = nametb_1.namtbl[stack[(*top - 3 << 1) - 2] - 1] - geom[0];
    if (kmode > *modhlf) {
	kmode -= *modhlf;
    }
    if (kmode == *vector) {
	argstk[*argtop - 2] = *one;
    }
    goto L20051;
L2027:
    if (*argtop == 3) {
	goto L20272;
    }
    l = argstk[1];
    argstk[1] = *zero + nametb_1.namtbl[l - 1] % 10;
    goto L20271;
L20272:
    *argtop = 5;
    argstk[4] = argstk[2];
    argstk[3] = argstk[1];
    argstk[2] = *zero;
    argstk[1] = *zero;
    goto L20271;
/*   POINT/PATERN,N   PATERNPUNKT */
L2045:
    goto L20051;
/*   VECTOR/R,R,R,R,R,R */
L2100:
    j = *result;
    iref = 6;
    for (l = 1; l <= 3; ++l) {
	opcode_(fsub);
	i__1 = -l;
	twoarg_(&i__1, &j);
	m = 4 - l;
	for (n = 1; n <= 2; ++n) {
	    argcvt_(&argstk[m - 1]);
/* L21001: */
	    m += 3;
	}
/* L21002: */
	rlslin_();
    }
    *argtop = 0;
    refgen_(&c__3, result);
    return 0;
/*    POINT/R,R,R */
L2101:
    opcode_(move);
    arggen_();
    rlslin_();
    *argtop = 0;
    refgen_(&c__1, result);
    return 0;
/*    POINT/R,R */
L2102:
    opcode_(move);
    arggen_();
    rlslin_();
    *argtop = 0;
    callzz_(&aptxxx[48]);
    argcvt_(result);
    rlslin_();
    return 0;
/*   CIRCLE/R,R,R,R */
L2103:
    j = 4;
L21031:
    opcode_(move);
    argcvt_(result);
    argcvt_(&argstk[j - 1]);
    argcvt_(&argstk[j - 2]);
    argcvt_(&argstk[j - 3]);
L21032:
    argcvt_(zeropt);
    argcvt_(zeropt);
    argcvt_(onept);
    argcvt_(argstk);
    rlslin_();
    *argtop = 0;
    refgen_(&c__2, result);
    return 0;
/*   CIRCLE/CENTER,R,R,R,RADIUS,R */
L2104:
    opcode_(move);
    argcvt_(result);
    argcvt_(&argstk[2]);
    argcvt_(&argstk[1]);
    argcvt_(zeropt);
    goto L21032;
/*   CIRCLE/R,R,R */
L2105:
    j = 5;
    goto L21031;
/*   VECTOR/R,R,R    /   VECTOR/UNIT,R,R,R */
L2106:
L2107:
    opcode_(move);
    argcvt_(result);
    argcvt_(&argstk[2]);
    argcvt_(&argstk[1]);
    argcvt_(argstk);
    rlslin_();
    refgen_(&c__3, result);
    if (*argtop == 4) {
	goto L21071;
    }
    callzz_(&aptxxx[22]);
    argcvt_(result);
    argcvt_(result);
    rlslin_();
L21071:
    *argtop = 0;
    return 0;
/*    SPHERE/R,R,R,R */
L2108:
    opcode_(move);
    arggen_();
    rlslin_();
    refgen_(&c__1, result);
    return 0;
/*    MATRIX/R,R,R,R,R,R,R,R,R,R,R,R */
L2109:
    opcode_(move);
    arggen_();
    rlslin_();
L21091:
    callzz_(defext);
    argcvt_(result);
    rlslin_();
    return 0;
/*    MATRIX/SCALE,R */
L2110:
    opcode_(move);
    argcvt_(result);
    argcvt_(argstk);
    for (j = 1; j <= 2; ++j) {
	for (l = 1; l <= 4; ++l) {
/* L21101: */
	    argcvt_(zeropt);
	}
/* L21102: */
	argcvt_(argstk);
    }
    argcvt_(zeropt);
    rlslin_();
    *argtop = 0;
    goto L21091;
/*    LINE/XAXIS */
L2111:
    opcode_(move);
    argcvt_(result);
    argcvt_(zeropt);
    argcvt_(onept);
L21111:
    argcvt_(zeropt);
    argcvt_(zeropt);
    rlslin_();
    refgen_(&c__4, result);
    *argtop = 0;
    return 0;
/*    LINE/YAXIS */
L2112:
    opcode_(move);
    argcvt_(result);
    argcvt_(onept);
    argcvt_(zeropt);
    goto L21111;
/*    LINE/PT,ATANGL/SLOPE,R,YAXIS */
L2113:
    argstk[0] = gettmp_(line);
    opcode_(move);
    argcvt_(argstk);
    argcvt_(onept);
    argcvt_(zeropt);
    argcvt_(zeropt);
    argcvt_(zeropt);
    rlslin_();
    refgen_(&c__4, argstk);
    puttmp_(line);
    *i__ = 11;
    goto L100;
/* ********************************************************************** */
/*   MEHRFACHTRANSFORMATION */
/* ... BEHANDLUNG DER 2. MATRIX: */

/*  2.MATRIX SCHON DEFINIERT */
L2155:
L2160:
L2165:
L2170:
    izres2 = argstk[0];
/*  MULTIPLIKATIONSSCHALTER AUF NORMAL STELLEN */
    i66 = *one;
    goto L701;
/*  2.MATRIX : TRANSL,X,Y,Z */
L2151:
L2156:
L2161:
L2166:
L2171:
    izres2 = gettmp_(matrix);
/*   MATRIXMULTIPLIKATIONSSCHALTER VORLAEUFIG AUF SONDERBEHANDLUNG STELLE */
    i66 = *zero;
    callzz_(&aptxxx[39]);
    argcvt_(&izres2);
    argcvt_(&argstk[2]);
    argcvt_(&argstk[1]);
    argcvt_(argstk);
    goto L702;
/*  2.MATRIX : TRANSL,X,Y */
L2152:
L2157:
L2162:
L2167:
L2172:
    izres2 = gettmp_(matrix);
/*   MATRIXMULTIPLIKATIONSSCHALTER VORLAEUFIG AUF SONDERBEHANDLUNG STELLE */
    i66 = *zero;
    callzz_(&aptxxx[39]);
    argcvt_(&izres2);
    argcvt_(&argstk[1]);
    argcvt_(argstk);
    argcvt_(zeropt);
    goto L702;
/*  2.MATRIX : XYROT/YZROT/ZXROT,ALPH */
L2153:
L2158:
L2163:
L2168:
L2173:
    izres2 = gettmp_(matrix);
/*   MATRIXMULTIPLIKATIONSSCHALTER VORLAEUFIG AUF SONDERBEHANDLUNG STELLE */
    i66 = *zero;
    callzz_(&aptxxx[62]);
    argcvt_(&izres2);
    argcvt_(&argstk[1]);
    argcvt_(argstk);
    goto L702;
/*  2.MATRIX : SCALE,F */
L2154:
L2159:
L2164:
L2169:
L2174:
    izres2 = gettmp_(matrix);
    opcode_(move);
    argcvt_(&izres2);
    argcvt_(argstk);
    for (j = 1; j <= 2; ++j) {
	for (l = 1; l <= 4; ++l) {
/* L21541: */
	    argcvt_(zeropt);
	}
/* L21542: */
	argcvt_(argstk);
    }
    argcvt_(zeropt);
    rlslin_();
    callzz_(defext);
    argcvt_(&izres2);
/*    MULTIPLIKATION AUF NORMAL STELLEN */
    i66 = *one;
/*   SETZEN DES ZAEHLERS FUER MATRIX-ZWISCHENSPEICHER */
L702:
    kgt = 1;
/*  ABSCHLUSS DER BEFEHLSFOLGE FUER 2. MATRIX */
    rlslin_();
/*  BEHANDLUNG DER 1. MATRIX */
L701:
    switch (*i__) {
	case 1:  goto L4151;
	case 2:  goto L4152;
	case 3:  goto L4153;
	case 4:  goto L4154;
	case 5:  goto L4155;
	case 6:  goto L4156;
	case 7:  goto L4157;
	case 8:  goto L4158;
	case 9:  goto L4159;
	case 10:  goto L4160;
	case 11:  goto L4161;
	case 12:  goto L4162;
	case 13:  goto L4163;
	case 14:  goto L4164;
	case 15:  goto L4165;
	case 16:  goto L4166;
	case 17:  goto L4167;
	case 18:  goto L4168;
	case 19:  goto L4169;
	case 20:  goto L4170;
	case 21:  goto L4171;
	case 22:  goto L4172;
	case 23:  goto L4173;
	case 24:  goto L4174;
    }
/*  1.MATRIX SCHON DEFINIERT */
L4151:
L4152:
L4153:
L4154:
    izres1 = argstk[*argtop - 2];
/*  MULTIPLIKATIONSSCHALTER AUF NORMAL STELLEN */
    i66 = *one;
    goto L711;
/*  1.MATRIX : TRANSL,X,Y,Z */
L4155:
L4156:
L4157:
L4158:
L4159:
    izres1 = gettmp_(matrix);
    callzz_(&aptxxx[39]);
    argcvt_(&izres1);
    argcvt_(&argstk[*argtop - 3]);
    argcvt_(&argstk[*argtop - 4]);
    argcvt_(&argstk[*argtop - 5]);
    goto L712;
/*  1.MATRIX : TRANSL,X,Y */
L4160:
L4161:
L4162:
L4163:
L4164:
    izres1 = gettmp_(matrix);
    callzz_(&aptxxx[39]);
    argcvt_(&izres1);
    argcvt_(&argstk[*argtop - 3]);
    argcvt_(&argstk[*argtop - 4]);
    argcvt_(zeropt);
    goto L712;
/*  1.MATRIX : XYROT/YZROT/ZXROT,ALPH */
L4165:
L4166:
L4167:
L4168:
L4169:
    izres1 = gettmp_(matrix);
    callzz_(&aptxxx[62]);
    argcvt_(&izres1);
    argcvt_(&argstk[*argtop - 2]);
    argcvt_(&argstk[*argtop - 3]);
    goto L712;
/*  1.MATRIX : SCALE,F */
L4170:
L4171:
L4172:
L4173:
L4174:
    izres1 = gettmp_(matrix);
    opcode_(move);
    argcvt_(&izres1);
    argcvt_(&argstk[*argtop - 3]);
    for (j = 1; j <= 2; ++j) {
	for (l = 1; l <= 4; ++l) {
/* L41701: */
	    argcvt_(zeropt);
	}
/* L41702: */
	argcvt_(&argstk[*argtop - 3]);
    }
    argcvt_(zeropt);
    rlslin_();
    callzz_(defext);
    argcvt_(&izres1);
/*    MULTIPLIKATION AUF NORMAL STELLEN */
    i66 = *one;
/*   LOSLASSEN DES EBEN BENUTZTEN MATRIX-ZWISCHENSPEICHERS */
L712:
    puttmp_(matrix);
/*  ABSCHLUSS DER BEFEHLSFOLGE FUER 1. MATRIX */
    rlslin_();
/*  GGF ZWISCHENSPEICHER FUER 2.MATRIX LOSLASSEN */
L711:
    if (kgt == 0) {
	goto L720;
    }
    kgt = 0;
    puttmp_(matrix);
/*   MATRIX-ENDVERARBEITUNG */
L720:
    callzz_(&aptxxx[40]);
    argcvt_(result);
    argcvt_(&izres1);
    argcvt_(&izres2);
    argcvt_(&i66);
    rlslin_();
    *argtop = 0;
    return 0;
/* ********************************************************************** */
/*   MATRIX/TRANSL,R,R */
L2175:
    argstk[4] = argstk[3];
    argstk[3] = argstk[2];
    argstk[2] = argstk[1];
    argstk[1] = argstk[0];
    argstk[0] = *zeropt;
    *argtop = 5;
    *i__ = 40;
    goto L100;
/*    MATRIX/MIRROR,XYPLAN/YZPLAN/ZXPLAN */
L2176:
    argstk[4] = argstk[2];
    argstk[3] = argstk[1];
    argstk[2] = argstk[0];
    argstk[1] = *zero;
    argstk[0] = *zero;
    *argtop = 5;
    *i__ = 81;
    goto L100;
/*    MATRIX/MIRROR,XYPLAN/YZPLAN/ZXPLAN,XYPLAN/YZPLAN/ZXPLAN */
L2177:
    argstk[4] = argstk[3];
    argstk[3] = argstk[2];
    argstk[2] = argstk[1];
    argstk[1] = argstk[0];
    argstk[0] = *zero;
    *argtop = 5;
    *i__ = 81;
    goto L100;
/* ********************************************************************** */
/*    LOFT-CONIC-VERARBEITUNG */
/*   LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5 */
/*  ARGSTK (11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1) */
L2179:
    goto L801;
/*   LCONIC/4PT1SL,X1,Y1,SL,X2,Y2,X3,Y3,X4,Y4 */
/*  ARGSTK ( 10   , 9, 8, 7, 6, 5, 4, 3, 2, 1) */
L2180:
    p[3] = -1;
    goto L801;
/*   LCONIC/3PT2SL,X1,Y1,SL,X2,Y2,SL,X3,Y3 */
/*  ARGSTK (  9   , 8, 7, 6, 5, 4, 3, 2, 1) */
L2181:
    p[1] = -1;
    p[3] = -1;
    goto L801;
/*  LCONIC-BERECHNUNG */
L801:
    j1 = 1;
    for (j = 1; j <= 5; ++j) {
/*  PUNKTBERECHNUNG: Z=0 ERGAENZEN,RUECKTRANSFORMATION */
	if (p[j - 1] < 0) {
	    goto L803;
	}
	p[j - 1] = gettmp_(point);
	opcode_(move);
	argcvt_(&p[j - 1]);
	argcvt_(&argstk[j1]);
	argcvt_(&argstk[j1 - 1]);
	argcvt_(zeropt);
	rlslin_();
	refgen_(&c__1, &p[j - 1]);
	argstk[j - 1] = p[j - 1];
	j1 += 2;
	goto L802;
/*   STEIGUNG UMSPEICHERN */
L803:
	argstk[j - 1] = argstk[j1 - 1];
	++j1;
L802:
	;
    }
/*   DEFINITIONSART UND RESULTATZEIGER UMSPEICHERN */
    argstk[5] = argstk[j1 - 1];
    argstk[6] = argstk[j1];
    *argtop = 7;
/*   HILFSZEIGER LOSLASSEN */
    for (j = 1; j <= 5; ++j) {
	if (p[j - 1] != -1) {
	    puttmp_(point);
	}
/* L804: */
	p[j - 1] = 1;
    }
/* NORMALE VERARBEITUNG */
    *i__ = 83;
    goto L100;
/* ********************************************************************** */
/* ... CYLNDR/X,Y,Z,V1,RADIUS */
L2182:
    *i__ = 34;
    isav = *result;
    *result = gettmp_(point);
    opcode_(move);
    argcvt_(result);
    argcvt_(&argstk[4]);
    argcvt_(&argstk[3]);
    argcvt_(&argstk[2]);
    rlslin_();
    puttmp_(point);
    refgen_(&c__1, result);
    argstk[2] = *result;
    *result = isav;
    *argtop += -2;
    goto L100;
/* ... CYLNDR/X,Y,Z,I,J,K,RADIUS */
L2178:
    *i__ = 33;
    isav = *result;
    *result = gettmp_(point);
    opcode_(move);
    argcvt_(result);
    argcvt_(&argstk[6]);
    argcvt_(&argstk[5]);
    argcvt_(&argstk[4]);
    rlslin_();
    puttmp_(point);
    refgen_(&c__1, result);
    argstk[4] = *result;
    *result = isav;
    *argtop += -2;
    goto L100;
/* ... PLANE/P1,P2,PERPTO,PL1 */
L2183:
    *i__ = 28;
    argstk[1] = argstk[3];
    isav = argstk[2];
    argstk[2] = argstk[0];
    argstk[0] = isav;
    goto L101;
/* ... POINT/THETAR,**,ANGLE,RADIUS */
L2184:
    *i__ = 48;
    isav = argstk[0];
    argstk[0] = argstk[1];
    argstk[1] = isav;
    goto L101;
/* ...  PROCESS BOUNDS STATEMENT */

/*     CALL GENERATED TO APT102        (I=86) */

/*     TEST IF THIS IS FIRST CALL TO APT102.  IF SO GENERATE EXTRA CALL */
/*     TO ALLOW INITIALIZATION OF BLOCK 1 POINTER. */

L2086:
    if (*ifbnds != 0) {
	goto L1305;
    }
    twopt = numb_(itwopt, (ftnlen)12);
    *ifbnds = 1;
    for (*i__ = 1; *i__ <= 3; ++(*i__)) {
	if (blkcfs_1.first[(*i__ << 1) - 1] != 0) {
	    goto L1303;
	}
/* L1302: */
    }
L1303:
    argcvt_(&blkcfs_1.first[(*i__ << 1) - 2]);
    argcvt_(zeropt);
    argcvt_(one);
    rlslin_();
    callzz_(&aptxxx[85]);
    argcvt_(result);

L1305:
    argcvt_(&argstk[*argtop - 2]);
    argcvt_(zeropt);
    argcvt_(one);
    rlslin_();
    l = gmty_1.geoloc[*bounds - 1];
    k = *top + *argtop - 1;
    errpt = *argtop - 1;
L1306:
    *argtop += -2;
    j = 0;
    kt2 = k << 1;
    *i__ = search_(stack, &kt2, &gmty_1.geomtb[l - 1], &errpt);
    errpt = -errpt;
    if (errpt >= 0) {
	errpt = -1;
    }
    if (*i__ == 185) {
	goto L1308;
    }
    if (*i__ != 186) {
	goto L999;
    }

/*     BOUNDN/...,SURF,POINT OR POSX OR NEGX OR POSY OR NEGY OR POSZ ETC. */

    callzz_(&aptxxx[85]);
    argcvt_(result);
    argcvt_(&argstk[*argtop - 1]);
    *i__ = argstk[*argtop - 2];
    if (*i__ < nametb_1.ifixst) {
	goto L1319;
    }
    m = *i__ - *one + 1;
    *i__ = *onept;
    switch (m) {
	case 1:  goto L1307;
	case 2:  goto L1307;
	case 3:  goto L1307;
	case 4:  goto L1310;
	case 5:  goto L1310;
	case 6:  goto L1310;
    }
L1307:
    *i__ = twopt;
    goto L1310;

/*     BOUNDS/...,SURF,IN OR OUT OR REAL,... */

L1308:
    callzz_(&aptxxx[85]);
    argcvt_(result);
    argcvt_(&argstk[*argtop - 1]);
    *i__ = argstk[*argtop - 2];
    if (*i__ == *one) {
	*i__ = *onept;
    }
    if (*i__ == *two) {
	*i__ = twopt;
    }
L1310:
    argcvt_(i__);
    if (*argtop == 2) {
	goto L1315;
    }
    i__1 = *two + j;
    argcvt_(&i__1);
    rlslin_();
    k += -2;
    goto L1306;
L1315:
    i__1 = *three + j;
    argcvt_(&i__1);
L1318:
    rlslin_();
    *argtop = 0;
    return 0;

/*     EMBEDDED POINT. */

L1319:
    j = 2;
    goto L1310;

/*     ERROR EXIT WHEN PRIMARY SURFACE NOT SPECIFIED. */

L2185:
L2186:
    goto L999;

/* ... PROCESS OBJECT STATEMENT */

/*     CALL GENERATED TO APT103               (I=87) */
L2087:
    argcvt_(&argstk[*argtop - 2]);
    j = 0;
    kk = *argtop - 2;
    if (kk < 1) {
	goto L1330;
    }
    argcvt_(one);
    rlslin_();
    i__1 = kk;
    for (k = 1; k <= i__1; ++k) {
	callzz_(&aptxxx[86]);
	argcvt_(result);
	l = kk - k + 1;
	m = mode_(&argstk[l - 1]);
	errpt = -l;
	if (m != *bounds && m != *object) {
	    goto L999;
	}
	argcvt_(&argstk[l - 1]);
	if (k == kk) {
	    goto L1315;
	}
	argcvt_(two);
/* L1325: */
	rlslin_();
    }
L1330:
    argcvt_(zero);
    goto L1318;
/*  PUNKT UND VECTOR-ABGRIFF VUN SSURF UND SCURV */
L2201:
    *i__ += -200;
    if (*i__ > 38) {
	goto L999;
    }
    na = *i__;
    errpt = 1 - *argtop;
    if (*argtop - 1 != iargz[na - 1]) {
	goto L999;
    }
    callzz_(&aptxxx[90]);
    argcvt_(result);
    for (nb = 1; nb <= 7; ++nb) {
	narg1 = narg[nb + na * 7 - 8];
	if (narg1 < 0) {
	    goto L3310;
	} else if (narg1 == 0) {
	    goto L3320;
	} else {
	    goto L3330;
	}
/* STEUERVARIABLE 'II' FUER ROUTINE APT109 WIRD AUSGEGEBEN */
L3310:
	argcvt_(&iarg[-10 - narg1 - 1]);
	goto L3300;
/* AUSGABE EINER REAL-ZAHL 0.0D0 */
L3320:
	argcvt_(zeropt);
	goto L3300;
/* AUSGABE EINER ARGSTK-ANGABE (ARGUMENT DER GEOMETRIE-DEFINITION) */
L3330:
	argcvt_(&argstk[narg1 - 1]);
L3300:
	;
    }
    *argtop = 0;
    rlslin_();
    return 0;
} /* pro021_ */

#undef aptxxx
#undef zeropt
#undef matrix
#undef vector
#undef argtop
#undef argstk
#undef bounds
#undef defext
#undef modhlf
#undef object
#undef ifbnds
#undef point
#undef onept
#undef three
#undef stack
#undef undef
#undef zero
#undef move
#undef fsub
#undef line
#undef geom
#undef iarg
#undef two
#undef top
#undef one


