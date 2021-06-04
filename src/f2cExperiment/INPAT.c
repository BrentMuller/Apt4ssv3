/* INPAT.f -- translated by f2c (version 20100827).
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

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__20 = 20;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__50 = 50;
static integer c__4 = 4;
static integer c_n1 = -1;
static integer c__5 = 5;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006639.W01   *** */


/*              FORTRAN SUBROUTINE INPAT */

/* LINKAGE      SUBROUTINE INPAT(IACT,BIGCNT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    RECOG */
/*          SUBROUTINE    CALLZZ */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    BCDBIN */
/*          LOGICAL FCT.  IFTMP */
/*          SUBROUTINE    MCXTRN */
/*          SUBROUTINE    ARGCVT */
/*          INTEGER FCT.  NAME */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    BINBCD */

/* Subroutine */ int inpat_(integer *iact, integer *bigcnt)
{
    /* Initialized data */

    static integer ktypes[12] = { 101,102,103,201,202,301,302,303,401,501,502,
	    503 };
    static char hperi[4] = "PERI";
    static char hdolsc[6] = "$SCRTH";
    static char xlank[4] = "    ";
    static char decpt[1] = ".";

    /* Format strings */
    static char fmt_100[] = "";
    static char fmt_110[] = "";
    static char fmt_3015[] = "";
    static char fmt_3042[] = "";
    static char fmt_3044[] = "";
    static char fmt_3052[] = "";
    static char fmt_3062[] = "";
    static char fmt_147[] = "";
    static char fmt_197[] = "";
    static char fmt_311[] = "";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k;
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
    static integer ept;
#define top ((integer *)&stklst_1)
#define two ((integer *)&numptr_1 + 4)
    extern integer name_(char *, ftnlen);
    static char buff[12];
#define real__ ((integer *)&modx_1 + 20)
    static integer iarg;
    extern integer mode_(integer *);
#define meta ((integer *)&srctbl_1 + 2)
    static integer args[5], icnt, idum;
    extern integer numb_(char *, ftnlen);
    static integer iret;
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define four ((integer *)&numptr_1 + 6)
    static integer nwds;
#define zero ((integer *)&numptr_1)
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
    static integer imode, icanx;
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
    static integer inumb;
    extern logical iftmp_(integer *);
#define nlast ((integer *)&ntbl_1 + 3)
    static integer ipush;
#define point ((integer *)&modx_1 + 18)
    static integer errpt, ktype;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen),
	     bcdbin_(char *, integer *, integer *, ftnlen);
    extern integer search_(integer *, integer *, integer *, integer *);
    static integer irandg, inamtb;
    extern /* Subroutine */ int opcode_(integer *);
#define dottab ((integer *)&bcdptr_1 + 6)
#define permid ((integer *)&code_1 + 38)
#define number ((integer *)&code_1 + 26)
#define cansiz ((integer *)&cfsize_1 + 5)
#define cantop ((integer *)&cfsize_1)
#define patern ((integer *)&modx_1 + 25)
#define intmed ((integer *)&macxx1_1 + 21)
#define modulo ((integer *)&moduli_1)
    static integer bigstk[20];
    static logical inclst;
    static integer bignxt, elment;
    static logical foulup;
#define maxsiz ((integer *)&cfsize_1 + 3)
    static integer kserch, ifirst;
    extern /* Subroutine */ int callzz_(integer *), twoarg_(integer *, 
	    integer *), rlslin_(void);
#define zeropt ((integer *)&numptr_1 + 1)
    extern /* Subroutine */ int argcvt_(integer *);
    static integer kscrth, inccnt;
    extern /* Subroutine */ int puttmp_(integer *);
    static integer ierror;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);
#define aptxxx ((integer *)&sublst_1)
    static integer result;
    extern integer gettmp_(integer *);
    static integer iclass;
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *);
    static integer idummy;

    /* Assigned format variables */
    static char *ipush_fmt, *iret_fmt;



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* POINT:       MODE CODE (19) FOR POINT */
/* REAL:        MODE CODE (24) FOR A SCALAR */
/* PATERN:      MODE CODE (26) FOR PATTERN */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */

/*       27.    OPERAND MODIFIERS */

/* DLR:         CONTAINS OPERAND TYPE CODE 1 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */
/* * */
/*     PURPOSE       TO VALIDATE THE FORMAT OF PATTERN DEFINITION */
/*                   STATEMENTS AND GENERATE APPROPRIATE INTER- */
/*                   MEDIATE LANGUAGE */

/*     RESTRICTIONS  CURRENTLY CANNOT HANDLE NESTED DEFINITIONS */
/*                   OR SUBSTITUTION OF MACRO VARIABLES FOR */
/*                   MINOR WORDS. */

/*                   LINEAR    LINEAR    LINEAR    ARC       ARC */
/*                   POINT     POINT     POINT     CIRCLE    CIRCLE */
/*                   POINT     VECTOR    VECTOR    REAL      REAL */
/*                   REAL      REAL      INCR      REAL      CLW,CCLW */
/*                                                 CLW,CCLW  INCR */
/*                                                 REAL */

/*                   GRID      GRID      GRID      RANDOM    PERIM */
/*                   PATERN    PATERN    PATERN    POINT,    PATERN */
/*                   PATERN    VECTOR    VECTOR      PATERN  PATERN */
/*                             REAL      INCR */

/*                   PERIM     PERIM */
/*                   PATERN    PATERN */
/*                   VECTOR    VECTOR */
/*                   REAL      INCR */

/* ** */

/* .......                      IF FIRST TIME THROUGH FOR THIS DEFINITION, */
/* .......                      DO INITIALIZATIONS */

    if (*bigcnt != 1) {
	goto L100;
    }
/*                             INITIALIZE INDEX FOR NEXT BIGSTK ENTRY */
    bignxt = 20;
/*                             SET LOCAL FLAG - NO FORMAT ERRORS YET */
    foulup = FALSE_;
/*                             INITIALIZE WORD COUNT FOR EXTERNAL FORM */
    nwds = 4;
/*                             SET LOCAL FLAG - NOT PROCESSING INCR LIST */
/*                             YET */
    inclst = FALSE_;
/*                             MOVE FIRST ARGUMENT INTO BIGSTK */
    ipush = 0;
    ipush_fmt = fmt_100;
    errpt = *top - 3;
    elment = stack[(errpt << 1) - 2];
    goto L1000;

/* .......            BRANCH IF END OF DEFINITION */

L100:
    if (*iact >= 103) {
	goto L200;
    }
/*                             IF ERROR HAS ALREADY OCCURRED, SKIP */
/*                             PROCESSING */
    if (foulup) {
	goto L2020;
    }

/* .......            PROCESS ELEMENT OF ARGUMENT LIST */

/*                             MOVE LATEST ARGUMENT INTO BIGSTK */
    ipush = 1;
    ipush_fmt = fmt_110;
    errpt = *top - 1;
    elment = stack[(errpt << 1) - 2];
    goto L1000;
/*                             SEARCH FOR MATCHING PATERN GEOMETRIC */
/*                             PRODUCTION IN BIGSTK. */
L110:
    j = gmty_1.geoloc[*patern - 1];
    ept = 10;
    kserch = search_(bigstk, &c__20, &gmty_1.geomtb[j - 1], &ept);
/*                             IF ACTION NUMBER=200, NO MATCHING PRODUC- */
/*                             TION WAS FOUND.  RETURN FOR MORE OF ARG */
/*                             LIST, UNLES 6 ELEMENTS ARE ACCUMULATED. */
    if (kserch <= 11) {
	goto L120;
    }
    if (bignxt < ept << 1) {
	goto L1990;
    }
    if (bignxt > 8) {
	goto L2020;
    }
    goto L1990;
/*                             BRANCH IF PROCESSING INCREMENT LIST */
L120:
    if (inclst) {
	goto L170;
    }
/*                             DETERMINE TYPE CODE FROM ACTION NUMBER */
/*                             AND FIRST WORD FOLLOWING SLASH */
    ifirst = bigstk[18];
    k = kserch;
    if (s_cmp(cnamtb_1.cnamtb + (ifirst - 1) * 6, hperi, (ftnlen)4, (ftnlen)4)
	     == 0) {
	goto L1980;
    }
    ktype = ktypes[k - 1];
/*                             SAVE ARGUMENTS FOR CALL TO DEFINITION */
/*                             REDUCTION ROUTINE */
    for (i__ = 1; i__ <= 5; ++i__) {
	j = 19 - (i__ << 1);
	args[i__ - 1] = bigstk[j - 1];
	if (j <= bignxt) {
	    args[i__ - 1] = *zeropt;
	}
/* L130: */
    }

/* .......            TAKE APPROPRIATE BRANCH- */
/* .......                 FOR RANDOM TYPE, GO PROCESS ARG. */
/* .......                 FOR INCR TYPE, GO SET UP INCR. */
/* .......                 FOR OTHERS, GO DETERMINE SIZE OF EXTERNAL */
/* .......                 CANONICAL FORM. */
/*       KTYPE 101  102  103  201  202  301  302  303  401  501  502  503 */
    switch (k) {
	case 1:  goto L3010;
	case 2:  goto L3010;
	case 3:  goto L3020;
	case 4:  goto L3030;
	case 5:  goto L3025;
	case 6:  goto L3040;
	case 7:  goto L3050;
	case 8:  goto L3060;
	case 9:  goto L140;
	case 10:  goto L3040;
	case 11:  goto L3050;
	case 12:  goto L3060;
    }
/*                             LINEAR PATERN-INITIAL BLOCK */
/*                                            POINT AND VECTOR */
L3010:
    nwds += 6;
/*                             INCREMENTS */
L3012:
    inamtb = bigstk[bignxt];
    iret = 0;
    iret_fmt = fmt_3015;
    goto L4000;
/*                             RETURN, EXPECT END OF DEFINITION */
L3015:
    bignxt = 18;
    goto L2020;
/*                             LINEAR PATERNS- ADD STORAGE FOR INITIAL */
/*                                    BLOCK AND BRANCH TO PROCESS INCR */
/*                                    LIST */
L3020:
    nwds += 6;
    goto L150;
/*                             ARC PATERNS- ADD STORAGE FOR INITIAL BLOCK */
/*                                    AND BRANCH TO PROCESS INCR LIST */
L3025:
    nwds += 6;
    goto L150;
/*                             ARC PATERNS-INITIAL BLOCK */
L3030:
    nwds += 6;
/*                             BRANCH TO ADD INCREMENTS */
    goto L3012;
/*                             GRID/PERIM PATERNS-ADD STORAGE FOR TWO */
/*                                                COMPONENT PATERNS */
L3040:
    inamtb = bigstk[14];
    iret = 1;
    iret_fmt = fmt_3042;
    goto L5000;
L3042:
    nwds += cansiz[(icanx << 1) - 2];
L3043:
    inamtb = bigstk[16];
    iret = 2;
    iret_fmt = fmt_3044;
    goto L5000;
L3044:
    nwds = nwds + cansiz[(icanx << 1) - 2] + 1;
    goto L3015;
/*                             GRID/PERIM PATERNS- ADD STORAGE FOR ONE */
/*                                    COMPONENT PATERN AND ONE INCREMENT */
L3050:
    inamtb = bigstk[12];
    iret = 3;
    iret_fmt = fmt_3052;
    goto L4000;
L3052:
    goto L3043;
/*                             GRID/PERIM PATERNS- ADD STORAGE FOR ONE */
/*                                    COMPONENT PATERN AND BRANCH TO */
/*                                    PROCESS INCREMENT LIST */
L3060:
    inamtb = bigstk[16];
    iret = 4;
    iret_fmt = fmt_3062;
    goto L5000;
L3062:
    nwds = nwds + 12 + cansiz[(icanx << 1) - 2];
    goto L150;

/* ...                PROCESS RANDOM TYPE ARGUMENT */

/*                             IF FIRST TIME THROUGH FOR THIS DEFINITION, */
/*                             GENERATE INITIALIZATION CALL TO APT100 */
L140:
    if (*bigcnt != 1) {
	goto L145;
    }
    callzz_(&aptxxx[72]);
    twoarg_(&c__1, zero);
    twoarg_(&c__1, zero);
    rlslin_();
/*                             INITIALIZE ARGUMENT COUNTER */
    irandg = 0;
/*                             GENERATE CALL TO PRE-PATERN DEFINTION */
/*                             ROUTINE APT 100 */
L145:
    callzz_(&aptxxx[72]);
/*                             SET FLAG FOR POINT OR PATERN */
    if (bigstk[bignxt + 1] == gmty_1.pmidtb[*point - 1]) {
	k = *one;
    }
    if (bigstk[bignxt + 1] == gmty_1.pmidtb[*patern - 1]) {
	k = *two;
    }
    twoarg_(&c__1, &k);
    argcvt_(&elment);
    rlslin_();
    if (iftmp_(&elment)) {
	i__1 = nametb_1.namtbl[elment - 1] % *modulo;
	puttmp_(&i__1);
    }
/*                             UPDATE EXTERNAL CANONICAL FORM WORD COUNT */
    if (k == *one) {
	goto L148;
    }
    inamtb = bigstk[16];
    iret = 5;
    iret_fmt = fmt_147;
    goto L5000;
L147:
    nwds += cansiz[(icanx << 1) - 2];
    goto L149;

L148:
    nwds += 4;
L149:
/*                             INCREMENT ARGUMENT COUNTER */
    ++irandg;
/*                             COMPRESS LAST ARG OUT OF BIGSTK */
    bignxt += 2;
    bigstk[bignxt - 1] = -1;
/*                             RETURN */
    goto L2020;

/* ...                SET UP FOR INCR LIST PROCESSING */

/*                             SET FLAG */
L150:
    inclst = TRUE_;
/*                             IF NOT ALREADY DONE, DECLARE ARRAY OF */
/*                             SCRATCH STORAGE IN PART PROGRM, OF LENGTH */
/*                             102 AND NAME $SCRTH */
    kscrth = name_(hdolsc, (ftnlen)6);
    if (nametb_1.namtbl[kscrth - 1] != 0) {
	goto L160;
    }
    nametb_1.namtbl[kscrth - 1] = vbl[0];
    resrvz_(&kscrth, &c__0, &c__102, &c__1);
/*                             SET PROPER ARG TO SCRATCH STORAGE ARRAY */
L160:
    iarg = (20 - bignxt) / 2;
    args[iarg - 1] = kscrth;
/*                             INITIALIZE COUNTER FOR INCR LIST */
    inccnt = 0;
/*                             PUT INCR AT TOP OF BIGSTK */
    bigstk[19] = bigstk[bignxt + 1];
    bigstk[17] = -1;
    bignxt = 18;
/*                             RETURN */
    goto L2020;

/* ......             PROCESS TERM OF INCR LIST */

/*                             BRANCH IF REAL-AT-REAL TYPE */
L170:
    if (kserch == 11) {
	goto L180;
    }
/*                             BRANCH IF EXCESS INCR ARGS */
    if (inccnt + 1 >= 102) {
	goto L195;
    }
/*                             GENERATE CODE TO MOVE FIRST REAL ARG */
/*                               MOVE   HDOLSC(INCCNT+1),ARG */
    opcode_(move);
    i__1 = -(inccnt + 2);
    twoarg_(&i__1, &kscrth);
    argcvt_(&bigstk[16]);
    rlslin_();
/*                             COMPRESS BIGSTK */
    bigstk[17] = bigstk[15];
    bigstk[16] = bigstk[14];
    bignxt = 16;
/*                             UPDATE INCR TERM COUNTER */
    ++inccnt;
/*                             UPDATE EXTERNAL CANONICAL FORM WORD COUNT */
    ++nwds;
/*                             RETURN */
    goto L2020;
/*                             BRANCH IF EXCESS INCR ARGS */
L180:
    if (inccnt + 3 >= 102) {
	goto L195;
    }
/*                             GENERATE CODE TO MOVE ARGS */
    opcode_(move);
    i__1 = -(inccnt + 2);
    twoarg_(&i__1, &kscrth);
    for (i__ = 1; i__ <= 3; ++i__) {
	j = 19 - (i__ << 1);
	argcvt_(&bigstk[j - 1]);
/* L190: */
    }
    rlslin_();
/*                             UPDATE EXTERNAL CANONICAL FORM WORD COUNT */
    inamtb = bigstk[16];
    iret = 6;
    iret_fmt = fmt_197;
    goto L4000;
L197:
/*                             COMPRESS BIGSTK */
    bignxt = 18;
    bigstk[17] = -1;
/*                             UPDATE INCR TERM COUNTER */
    inccnt += 3;
/*                             RETURN */
    goto L2020;
/*                             ERROR - EXCESS INCR ARGS */
L195:
    ierror = 2041;
    goto L2000;

/* ......             PROCESS END OF DEFINITION */

/*                             FIND NAME TABLE INDEX OF RESULT. */
/*                             IF AN UNNAMED NESTED DEF, SET UP TEMPORARY */
L200:
    if (*iact != 105) {
	goto L210;
    }
    result = gettmp_(patern);
    goto L222;
/*                             IF CLASS NOT PERMANENTLY SET, DEFINE NOW */
L210:
    result = stack[(*top - 5 << 1) - 2];
    iclass = *modulo * (nametb_1.namtbl[result - 1] / *modulo);
    if (iclass == vbl[0] || iclass == temp[0]) {
	goto L220;
    }
    nametb_1.namtbl[result - 1] = vbl[0] + *patern;
    resrvz_(&result, patern, &c__2, &c__1);
/* ...                          IF THIS VARIABLE HAS BEEN PREVIOUSLY */
/* ...                          DEFINED WITH ANOTHER MODE, ISSUE */
/* ...                          ERROR AND TERMINATE PROCESSING */
L220:
    if (mode_(&result) == *patern) {
	goto L221;
    }
    ierror = 1001;
    errpt = *top - 6;
    goto L2045;
/* ...                          IF THIS VARIABLE HAS BEEN PREVIOUSLY */
/* ...                          DEFINED WITH THE SAME MODE, ISSUE */
/* ...                          WARNING AND CONTINUE PROCESSING */
L221:
    if (iclass == vbl[0] && *intmed == 0) {
	i__1 = *top - 5;
	alarm_(&c__50, &i__1, &c__4, "INPAT   ", (ftnlen)8);
    }
/*                             IF WE WERE PROCESSING AN INCR LIST, CHECK */
/*                             FORMAT OF RESIDUE IN BIGSTK, AND MOVE */
/*                             FINAL ARG IF NECESSARY. */
L222:
    if (! inclst) {
	goto L230;
    }
    if (bignxt == 18) {
	goto L225;
    }
    if (bignxt != 16 || bigstk[17] != gmty_1.pmidtb[*real__ - 1]) {
	goto L2030;
    }
    opcode_(move);
    i__1 = -(inccnt + 2);
    twoarg_(&i__1, &kscrth);
    argcvt_(&bigstk[16]);
    rlslin_();
    ++inccnt;
/*                             UPDATE EXTERNAL CANONICAL FORM WORD COUNT */
    ++nwds;
    bignxt = 18;
/*                             GENERATE CODE TO STORE INCR LIST COUNT */
L225:
    s_copy(buff, xlank, (ftnlen)12, (ftnlen)4);
    binbcd_(&inccnt, buff, &icnt, (ftnlen)12);
    i__1 = icnt;
    s_copy(buff + i__1, decpt, icnt + 1 - i__1, (ftnlen)1);
    inumb = numb_(buff, (ftnlen)12) + nametb_1.nammax;
    opcode_(move);
    twoarg_(&c_n1, &kscrth);
    argcvt_(&inumb);
    rlslin_();
/*                             IF RANDOM TYPE, SET ARG1 TO THE NUMBER */
/*                             OF ARGUMENTS */
L230:
    if (ktype != 401) {
	goto L250;
    }
    s_copy(buff, xlank, (ftnlen)12, (ftnlen)4);
    binbcd_(&irandg, buff, &icnt, (ftnlen)12);
    i__1 = icnt;
    s_copy(buff + i__1, decpt, icnt + 1 - i__1, (ftnlen)1);
    inumb = numb_(buff, (ftnlen)12) + nametb_1.nammax;
    args[0] = inumb;
    for (i__ = 2; i__ <= 5; ++i__) {
	args[i__ - 1] = *zeropt;
/* L235: */
    }
/*                             VERIFY BIGSTK CLEANED UP AT THIS POINT */
L250:
    if (bignxt != 18) {
	goto L2030;
    }
/*                             IF NO ERRORS ENCOUNTERED PREVIOUSLY, */
/*                             GENERATE CALL TO PATERN DEFINITION ROUTINE */
    if (foulup) {
	goto L2050;
    }
    callzz_(&aptxxx[99]);
    twoarg_(&c__5, &c__1);
    argcvt_(&result);
    twoarg_(&c__5, &ktype);
    for (i__ = 1; i__ <= 5; ++i__) {
	argcvt_(&args[i__ - 1]);
	k = args[i__ - 1];
	if (iftmp_(&k)) {
	    i__1 = nametb_1.namtbl[k - 1] % *modulo;
	    puttmp_(&i__1);
	}
/* L310: */
    }
    rlslin_();
/*                             STORE THE NUMBER OF WORDS IN THE EXTERNAL */
/*                             CANONICAL FORM IN CANSIZ. */
    if (nwds <= 0) {
	nwds = 200;
    }
    inamtb = result;
    iret = 7;
    iret_fmt = fmt_311;
    goto L5000;
L311:
    cansiz[(icanx << 1) - 2] = nwds;
    cansiz[(icanx << 1) - 1] = result;
/*                             UPDATE SIZES OF TWO LARGEST EXTERNAL FORMS */
    if (nwds <= abs(maxsiz[1])) {
	goto L315;
    }
    if (nwds <= abs(maxsiz[0])) {
	goto L312;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = nwds;
    goto L315;
L312:
    maxsiz[1] = nwds;

/*                             ADJUST THE STACK AND RETURN */
L315:
    if ((i__1 = *iact - 104) < 0) {
	goto L335;
    } else if (i__1 == 0) {
	goto L320;
    } else {
	goto L340;
    }
L320:
    *top += -6;
L330:
    stack[(*top << 1) - 2] = result;
    k = nametb_1.namtbl[result - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[k - 1];
L335:
    return 0;
L340:
    *top += -4;
    goto L330;



/* ----------------------------------------------------------------------- */

/*              PURPOSE   TO ADD ELEMENT TO BIGSTK */
/*                                       FIND CORRECT INDEX TO USE WHEN */
/*                                       ACCESSING TABLE OF INTERNAL BIT */
/*                                       REPRESENTATIONS FOR GEOMETRIC */
/*                                       PRODUCTIONS. */
/*                                       IF NOT IN NAME PORTION, INDEX IS */
/*                                       MODE REAL */

L1000:
    if (elment > nametb_1.nammax) {
	goto L1030;
    }
    ierror = 1008;
/*                                       CLASS */
    iclass = *modulo * (nametb_1.namtbl[elment - 1] / *modulo);
/*                                       MODE */
    imode = nametb_1.namtbl[elment - 1] - iclass;
/*                                       STRIP OFF INDIRECT ADDRESS */
/*                                       INCREMENT IF PRESENT */
    if (imode >= 500) {
	imode += -500;
    }
    if (imode == 0) {
	goto L2010;
    }
    if (iclass != ident[0]) {
	goto L1025;
    }
    iclass = permid[0];
    nametb_1.namtbl[elment - 1] = nametb_1.namtbl[elment - 1] - ident[0] + 
	    permid[0];
/*                                       ADD PERMANENT IDENTIFIER INCRE- */
/*                                       MENT IF APPROPRIATE */
L1025:
    if (iclass == permid[0]) {
	imode += 50;
    }
    if (iclass == vbl[0] || iclass == permid[0] || iclass == temp[0]) {
	goto L1050;
    }
    if (iclass != number[0]) {
	goto L2010;
    }
L1030:
    imode = *real__;

/* ...                          STORE INTERNAL REPRESENTATION IN BIGSTK */

L1050:
    bigstk[bignxt - 1] = gmty_1.pmidtb[imode - 1];
/*                             STORE NAMTABL INDEX */
    bigstk[bignxt - 2] = elment;
/*                                       RESET STACK POINTER */
    bignxt += -2;
/*                                       STORE DUMMY VALUE TO TERMINATE */
/*                                       SCANS */
    bigstk[bignxt - 1] = -1;
/*                                       RETURN */
    switch (ipush) {
	case 0: goto L100;
	case 1: goto L110;
    }

/* ...                          INVALID FORMAT- ISSUE DIAGNOSTIC AND SET */
/* ...                          LOCAL FLAG */

L1980:
    errpt = *top - 3;
L1990:
    ierror = 1041;

/* ......             ERROR- ISSUE DIAGNOSTIC, SET LOCAL FLAG, AND RETURN */

L2000:
    if (foulup) {
	goto L2020;
    }
    foulup = TRUE_;
L2010:
    alarm_(&ierror, &errpt, &c__8, "INPAT   ", (ftnlen)8);
/*                             COMPRESS LAST ARGUMENT AND PRECEEDING */
/*                             DELIMITER FROM STACK. */
L2020:
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    return 0;

/* ...                FINAL ERROR PROCESSING, GENERATE CALL TO APT094 */
/* ...                TO UNDEFINE THE SUFACE */

L2030:
    errpt = *top + 1;
    stack[(*top << 1) - 2] = comma[1];
/* L2040: */
    if (foulup) {
	goto L2050;
    }
    ierror = 1041;
L2045:
    ++(*top);
    alarm_(&ierror, &errpt, &c__8, "INPAT   ", (ftnlen)8);
    --(*top);
L2050:
    callzz_(&aptxxx[67]);
    twoarg_(dlr, four);
    argcvt_(&result);
    twoarg_(&c__0, dottab);
    rlslin_();
    goto L315;
/* ----------------------------------------------------------------------- */

/*     PURPOSE  TO COMPUTE NUMBER OF INCREMENTS STORED WITH CANONICAL */
/*              FORM OF A PATERN, ARC OR LINEAR, AND ADD TO NWDS */

/*     ARGUMENTS     INAMTB    NAMTBL INDEX OF FINAL ARGUMENT OF PATERN */
/*                             DEFINITION */

/*                             IF LAST ARG NOT A NUMERIC, FLAG BY SETTING */
/*                                NWDS-10000. LATER A STANDARD MAX INSERT */
L4000:
    if (inamtb <= nametb_1.nammax) {
	goto L4010;
    }
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    inamtb -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &inamtb, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (inamtb - 1) * 12, &i__, &idum, (ftnlen)12);
    goto L4020;

L4010:
    i__ = -10000 - nwds;
L4020:
    nwds += i__;
    switch (iret) {
	case 0: goto L3015;
	case 1: goto L3042;
	case 2: goto L3044;
	case 3: goto L3052;
	case 4: goto L3062;
	case 5: goto L147;
	case 6: goto L197;
	case 7: goto L311;
    }
/* ----------------------------------------------------------------------- */

/*     PURPOSE  TO LOOK UP A PATERN IN THE CANSIZ TABLE, RETURN THE INDEX */
/*              OF THE LOCATION WHERE IT IS FOUND (OR WILL BE PLACED). */

/*     ARGUMENTS     INAMTB    NAMTBL INDEX OF THE PATERN */

L5000:
    icanx = inamtb % *cantop + 1;
    i__1 = *cantop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (cansiz[(icanx << 1) - 2] == 0 || cansiz[(icanx << 1) - 1] == 
		inamtb) {
	    goto L5020;
	}
	icanx = icanx % *cantop + 1;
/* L5010: */
    }
/*                             TABLE FULL, ISSUE DIAGNOSTIC */
    ierror = 53;
    errpt = *top - 5;
    goto L2010;
L5020:
    switch (iret) {
	case 0: goto L3015;
	case 1: goto L3042;
	case 2: goto L3044;
	case 3: goto L3052;
	case 4: goto L3062;
	case 5: goto L147;
	case 6: goto L197;
	case 7: goto L311;
    }
} /* inpat_ */

#undef aptxxx
#undef zeropt
#undef maxsiz
#undef modulo
#undef intmed
#undef patern
#undef cantop
#undef cansiz
#undef number
#undef permid
#undef dottab
#undef point
#undef nlast
#undef stack
#undef ident
#undef comma
#undef zero
#undef four
#undef move
#undef temp
#undef meta
#undef real__
#undef two
#undef top
#undef vbl
#undef dlr
#undef one


