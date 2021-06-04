/* LARGES.f -- translated by f2c (version 20100827).
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
    integer srctbl[502];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer cfsize[205];
} cfsize_;

#define cfsize_1 cfsize_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* Table of constant values */

static integer c__12 = 12;
static integer c_n6 = -6;
static integer c__3 = 3;
static integer c_n3 = -3;
static integer c__1 = 1;
static integer c__50 = 50;
static integer c__4 = 4;
static integer c__1025 = 1025;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006647.W01   *** */


/*              FORTRAN SUBROUTINE LARGES */

/* LINKAGE      SUBROUTINE  LARGES (ACTNO,BIGCNT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          INTEGER FCT.  GETTMP          SUBROUTINE    RECOG */
/*          SUBROUTINE    HELP */
/*          SUBROUTINE    ARGCVT */
/*          INTEGER FCT.  MODE */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    SETMOD */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int larges_(integer *actno, integer *bigcnt)
{
    /* Initialized data */

    static char normal[6] = "NORMAL";

    /* Format strings */
    static char fmt_10[] = "";
    static char fmt_110[] = "";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n, i1, i2, ii, ep, lk, kl, kk;
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
#define two ((integer *)&numptr_1 + 4)
    static integer xyz, iarg;
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define meta ((integer *)&srctbl_1 + 2)
    extern /* Subroutine */ int help_(void);
#define repl ((integer *)&il_1 + 16)
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define four ((integer *)&numptr_1 + 6)
#define zero ((integer *)&numptr_1)
    static integer save1, save2;
#define blank ((integer *)&code_1 + 24)
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
    static integer index;
#define nestg ((logical *)&macxx1_1 + 44)
    static integer vectr, first;
#define point ((integer *)&modx_1 + 18)
    static integer matrx, errpt;
    extern integer search_(integer *, integer *, integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *);
    static integer second;
    extern /* Subroutine */ int onearg_(integer *);
#define permid ((integer *)&code_1 + 38)
#define dottab ((integer *)&bcdptr_1 + 6)
#define number ((integer *)&code_1 + 26)
#define tabcys ((logical *)&cfsize_1 + 2)
#define cansiz ((integer *)&cfsize_1 + 5)
#define cantop ((integer *)&cfsize_1)
#define tabcyl ((integer *)&modx_1 + 10)
#define subscr ((integer *)&modx_1 + 23)
#define intmed ((integer *)&macxx1_1 + 21)
#define nought ((integer *)&opmod_1)
#define quidlr ((integer *)&opmod_1 + 5)
#define trpdlr ((integer *)&opmod_1 + 3)
#define maxsiz ((integer *)&cfsize_1 + 3)
#define modulo ((integer *)&moduli_1)
    static logical foulup, nomore;
    static integer bigstk[12], pntcnt, slopct, trform;
    extern /* Subroutine */ int setmod_(integer *, integer *);
    static integer bigtop;
    extern /* Subroutine */ int twoarg_(integer *, integer *), argcvt_(
	    integer *), rlslin_(void);
#define aptxxx ((integer *)&sublst_1)
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int puttmp_(integer *);
    static integer result;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);
    static integer ierror, nowrds;
    extern /* Subroutine */ int callzz_(integer *);

    /* Assigned format variables */
    static char *n_fmt;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* BLANK:       (1)=CODE CLASS 13000,(2)=NAMTBL INDEX OF '      ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* TABCYS:      TRUE WHEM PART PROGRAM CONTAINS TABCYLS */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* TABCYL:      MODE CODE (11) FOR TABULATED CYLINDER */
/* POINT:       MODE CODE (19) FOR POINT */
/* REAL:        MODE CODE (24) FOR A SCALAR */
/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* NESTG:       TRUE WHEN A NESTED GEOMETRIC EXPRESSION ENCOUNTERED */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* DLR:         CONTAINS OPERAND TYPE CODE 1 */
/* TRPDLR:      CONTAINS OPERAND TYPE CODE 3 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* PURPOSE      TO VALIDATE THE FORMAT OF LARGE DATA ARRAY DEFINITION */
/*              STATEMENTS AND TO GENERATE THE APPROPRIATE INTERMEDIATE */
/*              LANGUAGE. */

/* ARGUMENTS    ACTNO          MATCHING BASIC PRODUCTION ACTION NUMBER. */
/*              BIGCNT         DEFINITION ARGUMENT NUMBER + 1 */

/* NOTES        DESCRIPTION OF THE CANSIZ ARRAY IN CDE PACKAGE NO. 12 */
/*                  CANSIZ(1,I) = NUMBER OF WORDS IN THE EXTERNAL */
/*                                CANONICAL FORM OF A LARGE DATA ARRAY. */
/*                  CANSIZ(2,I) = THE NAME TABLE POINTER OF THE RESULT. */
/*              ALSO SEE NOTES FOR PRO020. */



/* *********************************************************************** */

/* ... IF THIS IS THE FIRST TIME THRU FOR A GEOMETRIC DEFINITION, */
/* ... INITIALIZE BIGSTK AND DO OTHER HOUSEKEEPING. */

    if (*bigcnt != 1) {
	goto L100;
    }
    foulup = FALSE_;
    pntcnt = 0;
    slopct = 0;
    ep = 0;
    matrx = blank[1];
    vectr = blank[1];
    nomore = FALSE_;
    index = -18;
    first = zero[0];
    second = zero[0];
    trform = zero[0];

    bigstk[1] = -1;
    errpt = *top - 3;
    l = stack[(errpt << 1) - 2];
    xyz = nametb_1.namtbl[l - 1] % *modhlf;
    if (l > nametb_1.nammax) {
	goto L5;
    }
    if (nametb_1.namtbl[l - 1] / *modulo == ident[0] / *modulo) {
	i__1 = *top - 3;
	setmod_(&i__1, permid);
    }
L5:
    m = 6;
    n = 0;
    n_fmt = fmt_10;
    goto L1000;
L10:
    bigtop = 6;

/* ... CHECK IF THIS IS FINAL PROCESSING FOR THIS DEFINITION. */

L100:
    if (*actno != 102) {
	goto L500;
    }

/* ********************************************************************** */
/* ... PRODUCTION 102  *************************************************** */

/* ... IF AN ERROR WAS PREVIOUSLY ENCOUNTERED,SUPPRESS I.L. GENERATION */

    if (! foulup) {
	goto L102;
    }
    lk = stack[(*top - 1 << 1) - 2];
    kl = 2;
    goto L3000;
/* ...  IF NOMORE = .TRUE.,SLOPE OR NORMAL IN WRONG PLACE--TAKE ERROR PATH */

L102:
    if (nomore) {
	goto L1030;
    }

/* ... IF STACK(1,TOP-1) IS CLASS IDENT, CHANGE IT TO CLASS PERMID. */

    errpt = *top - 1;
    l = stack[(errpt << 1) - 2];
/* L103: */
    if (l > nametb_1.nammax) {
	goto L105;
    }
    if (nametb_1.namtbl[l - 1] / *modulo == ident[0] / *modulo) {
	i__1 = *top - 1;
	setmod_(&i__1, permid);
    }

/* ... PLACE STACK(1,TOP-1) IN BIGSTK */

L105:
    m = 4;
    n = 1;
    n_fmt = fmt_110;
    goto L1000;

/* ... SEARCH GEOMETRIC PRODUCTIONS */

L110:
    j = gmty_1.geoloc[*tabcyl - 1];
    ep = *actno;
    k = search_(bigstk, &bigtop, &gmty_1.geomtb[j - 1], &ep);

/* ... IF ACTION NUMBER = 200, NO MATCHING PRODUCTION WAS FOUND. */

    if (k >= 200) {
	goto L1030;
    }

/* ... EXAMINE, WHETHER SPLINE AND VECTOR APPEAR IN VALID POSITION */

    if (*bigcnt > 4) {
	goto L200;
    }
    switch (*bigcnt) {
	case 1:  goto L150;
	case 2:  goto L160;
	case 3:  goto L200;
	case 4:  goto L170;
    }
L150:
    if (k != 1) {
	goto L1030;
    }
    goto L210;
L160:
    if (xyz != 28) {
	goto L200;
    }
    if (k != 3 && k != 4) {
	goto L1030;
    }
    goto L200;
L170:
    if (xyz != 28) {
	goto L200;
    }
    if (vectr != blank[1]) {
	goto L200;
    }
    if (k != 4) {
	goto L1030;
    }

/* ... BRANCH ON GEOMETRIC ACTION NUMBER. */

L200:
    switch (k) {
	case 1:  goto L210;
	case 2:  goto L220;
	case 3:  goto L230;
	case 4:  goto L240;
	case 5:  goto L250;
	case 6:  goto L260;
	case 7:  goto L270;
	case 8:  goto L280;
	case 9:  goto L290;
	case 10:  goto L300;
	case 11:  goto L310;
	case 12:  goto L320;
	case 13:  goto L330;
	case 14:  goto L310;
    }
/* ... GEO ACTION NUMBER 1   ********************************************* */

L210:
    if (*bigcnt != 1) {
	goto L1030;
    }
    goto L400;

/* ... GEO ACTION NUMBER 2   ********************************************* */
/* ... SAVE MATRIX AND COMPRESS BIGSTK */

L220:
    matrx = stack[(*top - 1 << 1) - 2];
    trform = *one;
    opcode_(repl);
    onearg_(&c__12);
    twoarg_(&c_n6, dottab);
    argcvt_(&matrx);
    rlslin_();
    lk = matrx;
    kl = 1;
    goto L3000;

/* ... GEO ACTION NUMBER 3   ********************************************* */
/* ... EXPAND BIGSTK TO ACCOMODATE TRFORM-MATRIX IF TRFORM IS ARGUMENT 3 */
/* ... OF THE DEFINITION. */

L230:
    if (*bigcnt != 2) {
	goto L1030;
    }
    goto L390;

/* ... GEO ACTION NUMBER 4   ********************************************* */
/* ... CHECK TO SEE THAT THE FORMAT IS CORRECT AND SAVE THE VECTOR */

L240:
    if (*bigcnt != 2 && (*bigcnt != 4 || matrx == blank[1])) {
	goto L1030;
    }
    vectr = stack[(*top - 1 << 1) - 2];
    opcode_(repl);
    onearg_(&c__3);
    twoarg_(&c_n3, dottab);
    argcvt_(&vectr);
    rlslin_();
    lk = vectr;
    kl = 2;
    goto L3000;

/* ... GEO ACTION NUMBER 5   ********************************************* */

L250:
    i__ = stack[(*top - 1 << 1) - 2];
    ++slopct;
    if (pntcnt == 0) {
	goto L1030;
    }

/* ... DETERMINE IF SLOPE OR NORMAL IS FOR FIRST OR LAST POINT AND */
/* ... COMPRESS BIGSTK. */

    opcode_(move);
    kl = -1;
    if (pntcnt > 1) {
	kl = -2;
    }
    twoarg_(&kl, dottab);
    argcvt_(&i__);
    rlslin_();
    lk = i__;
    kl = 3;

/* ... SET NOMORE =.TRUE. INDICATING THIS MUST BE THE LAST ARGUMENT. */

    if (pntcnt > 1) {
	nomore = TRUE_;
    }
    goto L3000;

/* ... GEO ACTION NUMBER 6   ********************************************* */

L260:
    i__ = stack[(*top - 1 << 1) - 2];

/* ... DETERMINE IF SLOPE OR NORMAL IS FOR THE FIRST OR LAST POINT. */

    if (pntcnt > 1) {
	goto L265;
    }

/* ... DETERMINE IF ARGUMENT = SLOPE OR NORMAL AND SET FIRST = ONE OR TWO. */
/* ... EXPAND BIGSTK. */

    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, normal, (ftnlen)6, (ftnlen)6) 
	    == 0) {
	goto L261;
    }
    first = *one;
    goto L390;
L261:
    first = *two;
    goto L390;

/* ... DETERMINE IF ARGUMENT = SLOPE OR NORMAL AND SET SECOND = ONE OR TWO */
/* ... EXPAND BIGSTK */

L265:
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, normal, (ftnlen)6, (ftnlen)6) 
	    == 0) {
	goto L266;
    }
    second = *one;
    goto L390;
L266:
    second = *two;
    goto L390;

/* ... GEO ACTION NUMBER 7   ********************************************* */
/* ... ADD 1 TO POINT COUNT, ADVANCE ..TAB INDEX BY 2, COMPRESS BIGSTK, */
/* ... ADD SECOND COORDINATE TO MOVE I.L. ARGUMENT LIST AND RELEASE THE IL */

L270:
    ++pntcnt;
    if (pntcnt == 139) {
	goto L1030;
    }
    opcode_(move);
    twoarg_(&index, dottab);
    argcvt_(&save1);
    index += -2;
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    rlslin_();
    lk = save1;
    kl = 4;
    goto L3000;
L271:
    lk = stack[(*top - 1 << 1) - 2];
    kl = 5;
    goto L3000;

/* ... GEO ACTION NUMBER 8   ********************************************* */
/* ... ADD 1 TO POINT COUNT, ADVANCE ..TAB INDEX BY 3, COMPRESS BIGSTK, */
/* ... ADD THIRD COORDINATE TO MOVE I.L. ARGUMENT LIST AND RELEASE THE IL */

L280:
    ++pntcnt;
    if (pntcnt == 139) {
	goto L1030;
    }
    opcode_(move);
    twoarg_(&index, dottab);
    argcvt_(&save1);
    argcvt_(&save2);
    index += -3;
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    rlslin_();
    lk = save1;
    kl = 6;
    goto L3000;
L281:
    lk = save2;
    kl = 7;
    goto L3000;
L282:
    lk = stack[(*top - 1 << 1) - 2];
    kl = 8;
    goto L3000;

/* ... GEO ACTION NUMBER 9   ********************************************* */
/* ... ADD SECOND COORDINATE TO MOVE I.L. ARGUMENT LIST, EXPAND BIGSTK */

L290:
    save2 = stack[(*top - 1 << 1) - 2];
    goto L380;

/* ... GEO ACTION NUMBER 10  ********************************************* */
/* ... GENERATE MOVE I.L. COMMAND, PUT FIRST COORDINATE IN MOVE ARGUMENT */
/* ... LIST, AND EXPAND BIGSTK. */

L300:
    save1 = stack[(*top - 1 << 1) - 2];


    goto L390;

/* ... GEO ACTION NUMBERS 11,12,13, AND 14  ****************************** */
/* ... ADD 1 TO POINT COUNT, ADVANCE ..TAB INDEX, GENERATE MOVE I.L. */
/* ... COMMAND AND RELEASE THE I.L. */

L310:
    i1 = -1;
    i2 = -2;
    goto L335;

L320:
    i1 = -2;
    i2 = -3;
    goto L335;

L330:
    i1 = -3;
    i2 = -1;
    goto L335;

L335:
    ++pntcnt;
    if (pntcnt == 139) {
	goto L1030;
    }
    lk = stack[(*top - 1 << 1) - 2];
    if (nametb_1.namtbl[lk - 1] % *modulo < *modhlf) {
	goto L336;
    }
    j = gettmp_(point);
    opcode_(repl);
    onearg_(&c__3);
    twoarg_(nought, &j);
    twoarg_(trpdlr, &lk);
    rlslin_();
    stack[(*top - 1 << 1) - 2] = j;
    puttmp_(point);
L336:
    kl = 9;
    goto L3000;
L338:
    opcode_(move);
    twoarg_(&index, dottab);
    twoarg_(&i1, &stack[(*top - 1 << 1) - 2]);
    twoarg_(&i2, &stack[(*top - 1 << 1) - 2]);
    if (k != 14) {
	goto L340;
    }
    twoarg_(&c_n3, &stack[(*top - 1 << 1) - 2]);
    --index;
L340:
    rlslin_();
    index += -2;
    goto L400;

/* ... COMPRESS BIGSTK */

L350:
    bigstk[7] = bigstk[9];
L360:
    bigstk[5] = bigstk[7];
    bigtop = 6;
    goto L400;

/* ... SLIDE BIGSTK ARGUMENTS UP */

L380:
    bigtop = 10;
    bigstk[9] = bigstk[7];
    goto L395;
L390:
    bigtop = 8;
L395:
    bigstk[7] = bigstk[5];
    bigstk[5] = bigstk[3];

/* ... COMPRESS STACK AND EXIT */

L400:
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    return 0;

/* ********************************************************************** */
/* ... FINAL PROCESSING  ************************************************* */

/* ... RESERVE SPACE FOR RESULT OF TABCYL DEFINITION IF NECESSARY. */

L500:
    if (*actno == 105) {
	goto L530;
    }
    result = stack[(*top - 5 << 1) - 2];
    j = *modulo * (nametb_1.namtbl[result - 1] / *modulo);
    if (j == vbl[0] || j == temp[0]) {
	goto L540;
    }
    nametb_1.namtbl[result - 1] = vbl[0] + *tabcyl;
    resrvz_(&result, tabcyl, &tmp_1.txxxx[(*tabcyl << 1) - 2], &c__1);
    goto L545;
L530:
    result = gettmp_(tabcyl);
    *nestg = TRUE_;
    goto L550;

/* ... IF THIS VARIABLE HAS BEEN PREVIOUSLY DEFINED WITH ANOTHER MODE, */
/* ... ISSUE ERROR AND TERMINATE PROCESSING. */
L540:
    k = mode_(&result);
    ierror = 1001;
    errpt = *top - 6;
    if (k != *tabcyl) {
	goto L1040;
    }

/* ... IF THIS VARIABLE HAS BEEN PREVIOUSLY DEFINED WITH THE SAME MODE, */
/* ... ISSUE WARNING AND CONTINUE PROCESSING */
    if (j == vbl[0] && *intmed == 0) {
	i__1 = *top - 5;
	alarm_(&c__50, &i__1, &c__4, "LARGES  ", (ftnlen)8);
    }

/* ... IF ERROR OCCURED PREVIOUSLY,GENERATE A CALL TO APT094. */

    if (foulup) {
	goto L1050;
    }

/* ... CHECK FOR INCOMPLETE ARGUMENT LIST AND CHECK THAT THE NUMBER OF */
/* ... POINTS IS WITHIN BOUNDS. */

L545:
    ierror = 1025;
    errpt = 0;
    if (pntcnt + slopct < 4 || bigtop != 6) {
	goto L1035;
    }

/* ... TRANSLATE FIRST MODIFIER TO AN I.L. NUMBER */

L550:
    l = stack[(*top - 1 << 1) - 2];
    j = nametb_1.namtbl[l - 1] - nametb_1.namtbl[l - 1] / *modulo * *modulo - 
	    19;
    if (j - 5 >= 0) {
	goto L554;
    } else {
	goto L552;
    }
L552:
    ii = *one;
    goto L556;
L554:
    ii = zero[j - 1];

/* ... CHECK TO SEE IF WE HAVE AN XYZ FORMAT WITH NO DIRECTRIX SPECIFIED. */

/* ... CHECK IF THIS TABCYL IS ONE OF THE TWO LARGEST LARGE DATA ARRAY */
/* ... CANONICAL FORMS ENCOUNTERED AND IF SO SAVE ITS SIZE IN MAXSIZ. */

L556:
    nowrds = pntcnt * 7 + 21;
    if (nowrds <= abs(maxsiz[1])) {
	goto L570;
    }
    if (nowrds <= abs(maxsiz[0])) {
	goto L560;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = nowrds;
    goto L570;
L560:
    maxsiz[1] = nowrds;

/* ... INSERT TABCYL SIZE IN CANSIZ ARRAY FOR FUTURE REFERENCE. */

L570:
    j = result - *cantop * (result / *cantop);
    i__1 = *cantop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = j + 1 - *cantop * (j / *cantop);
	if (cansiz[(j << 1) - 2] != 0 && cansiz[(j << 1) - 1] != result) {
	    goto L580;
	}
	cansiz[(j << 1) - 2] = nowrds;
	cansiz[(j << 1) - 1] = result;
	goto L600;
L580:
	;
    }

/* ... CANSIZ HAS OVERFLOWED--- TOO MANY LARGE DATA ARRAYS IN PART PROGRAM */

    ierror = 53;
    errpt = *top - 6;
    goto L1040;

/* ...  GENERATE CALL I.L. FOR APT088 (TABCYL DEFINITION REDUCTION RTN.) */

L600:
    *tabcys = TRUE_;
    callzz_(&aptxxx[66]);
    argcvt_(&result);
    argcvt_(&ii);
    twoarg_(quidlr, &pntcnt);
    argcvt_(&first);
    argcvt_(&second);
    argcvt_(&trform);
    twoarg_(nought, dottab);
    rlslin_();

/* ... ADJUST THE STACK AND RETURN */

L610:
    if ((i__1 = *actno - 104) < 0) {
	goto L635;
    } else if (i__1 == 0) {
	goto L620;
    } else {
	goto L640;
    }
L620:
    *top += -6;
L630:
    stack[(*top << 1) - 2] = result;
    k = nametb_1.namtbl[result - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[k - 1];
L635:
    return 0;
L640:
    *top += -4;
    *nestg = FALSE_;
    goto L630;

/* ******************************************************************** */
/* ... CONVERT AN ELEMENT OF THE STACK TO MACHINE DEPENDENT REPRESENTATION */
/* ... AND INSERT IT IN BIGSTK SO IT CAN BE MATCHED WITH THE GEOMETRIC */
/* ... PRODUCTIONS. */

/* ... LINKAGE --- SET L = STACK ELEMENT (NAMTBL POINTER) */
/* ...             SET M = BIGSTK INDEX */
/* ...             ASSIGN N TO RETURN STATEMENT NUMBER */

L1000:
    if (l > nametb_1.nammax) {
	goto L1005;
    }
    kk = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
    iarg = nametb_1.namtbl[l - 1] - kk;
    if (iarg >= 500) {
	iarg += -500;
    }
    if (kk == vbl[0] || kk == temp[0]) {
	goto L1020;
    }
    if (kk == permid[0]) {
	goto L1010;
    }
    if (kk != number[0]) {
	goto L1030;
    }
L1005:
    iarg = *real__;
    goto L1020;
/* ---     CHECK FOR UNDEFINED SLOPE VALUE */
L1010:
    if (iarg == 0) {
	goto L1030;
    }
    iarg += 50;
L1020:
    bigstk[m - 1] = gmty_1.pmidtb[iarg - 1];
    switch (n) {
	case 0: goto L10;
	case 1: goto L110;
    }

/* ******************************************************************** */
/* ... INVALID TABCYL DEFINITION */

L1030:
    alarm_(&c__1025, &errpt, &c__8, "LARGES  ", (ftnlen)8);
    foulup = TRUE_;
    goto L400;

/* ... FINAL PROCESSING CANNOT BE COMPLETED */

L1035:
    if (foulup) {
	goto L1050;
    }
    if (ep == 0) {
	goto L1040;
    }
    stack[(*top << 1) - 2] = comma[1];
    errpt = *top + 1;
L1040:
    ++(*top);
    alarm_(&ierror, &errpt, &c__8, "LARGES  ", (ftnlen)8);
    --(*top);
L1050:
    callzz_(&aptxxx[67]);
    twoarg_(dlr, four);
    argcvt_(&result);
    twoarg_(nought, dottab);
    rlslin_();
    goto L610;

/* ...  IF INDIRECT ADRESS TEMPORARY,RELEASE IT. */
/* . */
L3000:
    if (lk > nametb_1.nammax) {
	goto L4000;
    }
    i__ = nametb_1.namtbl[lk - 1];
    if (i__ / *modulo != temp[0] / *modulo) {
	goto L4000;
    }
    j = i__ - temp[0];
    if (j >= *modhlf) {
	j = *subscr;
    }
    puttmp_(&j);
L4000:
    switch (kl) {
	case 1:  goto L360;
	case 2:  goto L400;
	case 3:  goto L360;
	case 4:  goto L271;
	case 5:  goto L360;
	case 6:  goto L281;
	case 7:  goto L282;
	case 8:  goto L350;
	case 9:  goto L338;
    }
    help_();
    return 0;
} /* larges_ */

#undef aptxxx
#undef modulo
#undef maxsiz
#undef trpdlr
#undef quidlr
#undef nought
#undef intmed
#undef subscr
#undef tabcyl
#undef cantop
#undef cansiz
#undef tabcys
#undef number
#undef dottab
#undef permid
#undef modhlf
#undef point
#undef nestg
#undef stack
#undef ident
#undef comma
#undef blank
#undef zero
#undef four
#undef move
#undef temp
#undef repl
#undef meta
#undef real__
#undef two
#undef top
#undef vbl
#undef dlr
#undef one


