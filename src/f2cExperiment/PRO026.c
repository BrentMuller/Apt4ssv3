/* PRO026.f -- translated by f2c (version 20100827).
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
    integer srctbl[501];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer seqcom[3];
} seqcom_;

#define seqcom_1 seqcom_

struct {
    integer cfsize[205];
} cfsize_;

#define cfsize_1 cfsize_

struct {
    integer nonept;
} negptr_;

#define negptr_1 negptr_

struct {
    integer prt[7];
} prt_;

#define prt_1 prt_

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
    integer opmod[8];
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
    integer comp26[16];
} comp26_;

#define comp26_1 comp26_

struct {
    integer bgeom[4];
} bgeom_;

#define bgeom_1 bgeom_

struct {
    integer super[36];
} super_;

#define super_1 super_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

struct {
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* Table of constant values */

static integer c__2002 = 2002;
static integer c__4 = 4;
static integer c__2028 = 2028;
static integer c__2029 = 2029;
static integer c_n1 = -1;
static integer c__8 = 8;
static integer c__2001 = 2001;
static integer c__2042 = 2042;
static integer c__2030 = 2030;
static integer c__2039 = 2039;
static integer c__2021 = 2021;
static integer c__2052 = 2052;
static integer c__3 = 3;
static integer c__2003 = 2003;
static integer c__1 = 1;
static integer c__2011 = 2011;
static integer c__2004 = 2004;
static integer c__2005 = 2005;
static integer c__2006 = 2006;
static integer c__2008 = 2008;
static integer c__2007 = 2007;
static integer c__2009 = 2009;
static integer c__0 = 0;
static integer c__9 = 9;
static integer c__7 = 7;
static integer c__2012 = 2012;
static integer c__83 = 83;
static integer c__12 = 12;
static integer c__2013 = 2013;
static integer c__2046 = 2046;
static integer c__2055 = 2055;
static integer c__2056 = 2056;
static integer c__2057 = 2057;
static integer c__13 = 13;
static integer c__2015 = 2015;
static integer c__5 = 5;
static integer c__2017 = 2017;
static integer c__1008 = 1008;
static integer c__2045 = 2045;
static integer c__2031 = 2031;

/* *** SOURCE FILE : M0007341.W06   *** */


/*              FORTRAN SUBROUTINE PRO026 */

/* LINKAGE      SUBROUTINE PRO026 */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    JUMPZZ          SUBROUTINE    RECOG */
/*          SUBROUTINE    LABCON */
/*          SUBROUTINE    ARGGEN */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    MATCH */
/*          INTEGER FCT.  CLMODE */
/*          SUBROUTINE    MCXTRN */
/*          SUBROUTINE    MNPROC */
/*          INTEGER FCT.  MODE */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    MOTION */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  NAME */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    GOPAT */
/*          SUBROUTINE    PATH */
/*          SUBROUTINE    PRO027 */
/*          SUBROUTINE    PRO028 */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    EPILOG */
/*          SUBROUTINE    READ */
/*          SUBROUTINE    REFGEN */
/*          SUBROUTINE    REFREF */
/*          SUBROUTINE    RESERV */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    TSSMIL */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    BCDBIN */

/* Subroutine */ int pro026_(void)
{
    /* Initialized data */

    static char icntrl[6*4] = "ERR   " "TR    " "XC    " "CL    ";
    static char ippopt[6*5] = "INTLNG" "PRTER " "REFMOT" "ALTMLT" "CILPRT";
    static char hall[6] = "ALL   ";
    static char hon[6] = "ON    ";
    static char hoff[6] = "OFF   ";
    static char hat[6] = "AT    ";
    static char hps[6] = "PS    ";
    static char hout[6] = "OUT   ";
    static char hin[6] = "IN    ";
    static char golo[6] = "GOLOFT";
    static char plot[6] = "PLOTFT";
    static char don[6] = "ON    ";
    static char srprnt[6] = "PRINT ";
    static char start[6] = "START ";
    static char nomore[6] = "NOMORE";
    static logical eras = FALSE_;
    static logical odd = TRUE_;
    static logical odd1 = TRUE_;
    static logical odd2 = TRUE_;
    static char normal[6] = "NORMAL";
    static char finit[6] = "FINI  ";
    static char contin[6] = "CONT  ";

    /* Format strings */
    static char fmt_22[] = "";
    static char fmt_725[] = "";
    static char fmt_815[] = "";
    static char fmt_848[] = "";
    static char fmt_850[] = "";
    static char fmt_9999[] = "";
    static char fmt_415[] = "";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
#define j ((integer *)&bgeom_1 + 2)
#define k ((integer *)&comp26_1 + 11)
#define l ((integer *)&bgeom_1 + 3)
    static integer m, n, kk;
#define to ((integer *)&bcdptr_1 + 2)
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
    static integer hop, sub;
#define way ((integer *)&macxx1_1 + 25)
#define top ((integer *)&stklst_1)
#define six ((integer *)&numptr_1 + 8)
#define two ((integer *)&numptr_1 + 4)
    extern integer name_(char *, ftnlen);
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define fini ((logical *)&super_1 + 6)
#define meta ((integer *)&srctbl_1 + 2)
    static integer hmod;
#define five ((integer *)&numptr_1 + 7)
#define nine ((integer *)&numptr_1 + 11)
    extern /* Subroutine */ int path_(void);
    static integer jmod;
    extern integer numb_(char *, ftnlen);
#define repl ((integer *)&il_1 + 16)
    static integer iret;
#define lerr ((integer *)&comp26_1 + 12)
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
    extern /* Subroutine */ int loop_(void);
#define four ((integer *)&numptr_1 + 6)
#define psis ((integer *)&sublst_1 + 132)
#define zero ((integer *)&numptr_1)
#define test ((integer *)&comp26_1 + 5)
#define apt001 ((integer *)&sublst_1 + 48)
#define apt200 ((integer *)&sublst_1 + 126)
#define apt298 ((integer *)&sublst_1 + 129)
#define apt299 ((integer *)&sublst_1 + 130)
    extern /* Subroutine */ int pro028_(logical *), pro027_(integer *);
#define test1 ((integer *)&comp26_1 + 6)
#define label ((integer *)&code_1 + 42)
#define dotac ((integer *)&bcdptr_1)
#define erasb ((integer *)&bcdptr_1 + 4)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define plane ((integer *)&modx_1 + 1)
    extern /* Subroutine */ int match_(void);
#define stack ((integer *)&stklst_1 + 3)
#define three ((integer *)&numptr_1 + 5)
#define major ((integer *)&macxx1_1 + 43)
    extern /* Subroutine */ int gopat_(void);
#define ilhlt ((logical *)&macxx1_1 + 13)
#define nlast ((integer *)&ntbl_1 + 3)
    static logical ltemp;
    static integer igoto;
#define onept ((integer *)&numptr_1 + 3)
#define seqno ((integer *)&seqcom_1)
    static integer ilist;
#define point ((integer *)&modx_1 + 18)
#define ilprt ((logical *)&prt_1 + 1)
#define error ((integer *)&sublst_1 + 131)
    static integer errpt;
#define entry__ ((logical *)&macxx1_1 + 39)
#define ssurf ((integer *)&modx_1 + 28)
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen);
#define macend ((logical *)&macxx1_1 + 61)
#define macdfp ((integer *)&macxx1_1)
#define macred ((logical *)&macxx1_1 + 17)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define finmac ((logical *)&macxx1_1 + 23)
    extern /* Subroutine */ int labcon_(integer *);
#define cflags ((logical *)&super_1)
#define dbldlr ((integer *)&opmod_1 + 2)
#define implab ((integer *)&code_1 + 44)
#define fedrat ((integer *)&bcdptr_1 + 1)
#define object ((integer *)&modx_1 + 27)
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
#define proced ((integer *)&code_1 + 36)
#define dottab ((integer *)&bcdptr_1 + 6)
#define permid ((integer *)&code_1 + 38)
#define aptran ((logical *)&flags_1 + 2)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define cilprt ((logical *)&prt_1)
#define vbljmp ((integer *)&il_1 + 19)
#define patern ((integer *)&modx_1 + 25)
#define should ((logical *)&macxx1_1 + 69)
#define vector ((integer *)&modx_1 + 19)
#define intmed ((integer *)&macxx1_1 + 21)
#define majwrd ((integer *)&macxx1_1 + 22)
#define whchmn ((integer *)&macxx1_1 + 62)
#define nought ((integer *)&opmod_1)
#define quidlr ((integer *)&opmod_1 + 5)
#define maxsiz ((integer *)&cfsize_1 + 3)
#define newstm ((logical *)&flags_1 + 1)
#define prterr ((logical *)&prt_1 + 5)
#define tlaxis ((integer *)&sublst_1 + 134)
#define modulo ((integer *)&moduli_1)
#define fmterr ((logical *)&comp26_1 + 8)
#define zeropt ((integer *)&numptr_1 + 1)
#define argcnt ((integer *)&comp26_1 + 1)
#define cspntr ((integer *)&comp26_1 + 2)
#define numbcs ((integer *)&comp26_1 + 4)
#define ifdump ((integer *)&bgeom_1 + 1)
#define jumpto ((integer *)&doloop_1)
#define aptxxx ((integer *)&sublst_1)
#define dojump ((integer *)&doloop_1 + 5)
#define ergstk ((integer *)&errpos_1 + 202)
    static logical dsfind, psfind;
    extern /* Subroutine */ int goloft_(void), tssmil_(void), callzz_(integer 
	    *), twoarg_(integer *, integer *), argcvt_(integer *);
    extern integer clmode_(integer *);
    extern /* Subroutine */ int rlslin_(void), arggen_(void);
    static integer asnvar;
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int opcode_(integer *), refgen_(integer *, 
	    integer *);
    static integer dstype;
    extern /* Subroutine */ int puttmp_(integer *), motion_(void);
    static integer idrect, ierror;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *), refref_(void);
    static integer maxtwo;
    extern /* Subroutine */ int mnproc_(void), epilog_(void);
    static integer cstype;
    extern /* Subroutine */ int onearg_(integer *), mcxtrn_(integer *, 
	    integer *, integer *);
    static integer idummy, icount;
    extern /* Subroutine */ int jumpzz_(integer *), reserv_(void);

    /* Assigned format variables */
    static char *iret_fmt, *asnvar_fmt;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* IFIXST:      NAMTBL INDEX OF BEGINNING OF FIXED POINT NUMBER SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PROCED:      (1)=CODE CLASS 19000,(2)=NAMTBL INDEX OF 'PROCED' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */
/* APTRAN:      TRUE IF APTRAN CARD READ AND IN EFFECT */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTAC:       NAMTBL POINTER TO ALPHAMERIC LITERAL '.AC.  ' */
/* FEDRAT:      NAMTBL POINTER TO ALPHAMERIC LITERAL 'FEDRAT' */
/* TO:          NAMTBL POINTER TO ALPHAMERIC LITERAL 'TO' */
/* ERASB:       NAMTBL POINTER TO ALPHAMERIC LITERAL 'APTER' */
/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* THREE:       NAMTBL POINTER TO '3     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */
/* FIVE:        NAMTBL POINTER TO '5     ' */
/* SIX:         NAMTBL POINTER TO '6     ' */
/* NINE:        NAMTBL POINTER TO '9     ' */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */

/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */

/*       13.    NAMTBL POINTERS TO NEGATIVE NUMBERS */
/*              NAMTBL POINTER TO -1. */

/*       14.    I. L. LIST OPTION FLAGS */

/* CILPRT:      TRUE WHEN COMPRESSED I.L. PRINTING REQUESTED */
/* ILPRT:       TRUE INDICATES I.L. PRINTING (PPOPTN/INTLNG,ON) */
/* PRTERR:      TRUE IF PPOPTN/PRTER,ON. PRINTOUT OF STACK OR ARGSTK */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */
/* VBLJMP:      CONTAINS COMMAND CODE (20) FOR VBLJMP COMMAND */

/*       17.    MODE CODES */

/* PLANE:       MODE CODE ( 2) FOR PLANE SURFACE */
/* POINT:       MODE CODE (19) FOR POINT */
/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* REAL:        MODE CODE (24) FOR A SCALAR */
/* PATERN:      MODE CODE (26) FOR PATTERN */
/* OBJECT:      MODE CODE (28) FOR OBJECT */
/* SSURF:       MODE CODE (29) FOR SSURF */

/*       22.    MACRO PROCESSING VARIABLES */

/* MACDFP:      POINTER TO LAST ENTRY IN MACDF1 AND MACDF2 ARRAYS */
/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* MACRED:      SET TRUE TO INDICATE INPUT FROM MCBUFF TABLE */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* MAJWRD:      CONTAINS ACTUAL MAJOR WORD */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* MAJOR:       CURRENT CALL ASSIGNED VALUE IF MAYWRD IS MACRO VARIABLE */
/* MACEND:      TRUE WHEN ALL MACRO PROCESSING IS FINISHED */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* DLR:         CONTAINS OPERAND TYPE CODE 1 */
/* DBLDLR:      CONTAINS OPERAND TYPE CODE 2 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APT200:      NAMTBL POINTER FOR APT200 */
/* APT298:      NAMTBL POINTER FOR APT298 */
/* APT299:      NAMTBL POINTER FOR APT299 */
/* ERROR:       NAMTBL POINTER TO EXECUTION SUBROUTINE ERROR */
/* PSIS:        NAMTBL POINTER FOR XECUTION SUBROUTINE PSIS */
/* TLAXIS:      NAMTBL POINTER FOR XECUTION SUBROUTINE TLAXIS */
/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */
/* APT001:      NAMTBL POINTER FOR APT001 */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       31.    COMMON BLOCK FOR PRO026 AND MOTION */

/* ARGCNT:      POINTER FOR CURRENT ARGSTK ELEMENT */
/* CSPNTR:      CONTAINS NAMTBL POINTER TO CS */
/* NUMBCS:      NUMBER OF CHECK SURFACES */
/* TEST:        NAMTBL INDEX OF CURRENT ARGUMENT */
/* TEST1:       CLASS OF CURRENT ARGUMENT */
/* FMTERR:      ERROR FLAG FOR CERTAIN MOTION STATEMENTS */
/* K:           NAMTBL POINTER TO MAJOR WORD */
/* LERR:        ERROR TYPE INDICATOR */

/*       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE */

/* IFDUMP:      VALUE 0=NO CFSAVE COMMAND,1=ALL,2=SCALAR,3=GEOM PROGRAM */
/* J:           PASSES PUNCH/ARGUMENT FROM PRO026 TO PRO027 */
/* L:           PASSES PUNCH/LISTON OR NOLIST FROM PRO026 TO PRO027 */

/*       40.    PARAMETERS REQUIRED BY SUPERVISOR */

/* CFLAGS:      CONDITION OF TERMINATION OF THE PHASES */
/* FINI:        FLAG ON INDICATES A FINI CARD HAS BEEN READ */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/*       43.    DO LOOP CONTROL VALUES */

/* JUMPTO:      MARKER SET AFTER JUMPTO OR IF FOR LABEL CONTROL */
/* DOJUMP:      VBL FOR COMPUTED GOTO AT LOOP PROCESSING */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */

/*       45.    NUMBER TABLE INDICES */

/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* * */
/* ...           PROGRAM VARIABLES */


/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

/* ********************************************************************* */
    *k = stack[(12 + (0 + (1 + (*top - 1 << 1) - 3 << 2)) - 12) / 4];
    if (*intmed != 1) {
	goto L6052;
    }
    *way = 2;
    if (*finmac) {
	goto L6051;
    }
    ergstk[99] = *top - 1;
    *majwrd = *k;
L6002:
    match_();
    if (! (*entry__)) {
	goto L6053;
    }
    *k = *major;
    goto L6052;
L6051:
    path_();
    if (! (*should)) {
	goto L6053;
    }
L6052:
    hop = nametb_1.namtbl[*k - 1] - proced[0];
    if (hop >= *modhlf) {
	hop -= *modhlf;
    }
    if (hop == 0) {
	goto L30;
    }
/* ... TLLFT, TLRGT, TLON, TLONPS, TLOFPS, MULTAX, NOPS, AUTOPS, CUT, */
/*    DNTCUT, NDTEST, COMP3D, GOUGCK */
    if (hop <= 13) {
	goto L10;
    }
    hop += -13;
/*           CLPRNT APTRAN */
    switch (hop) {
	case 1:  goto L80;
	case 2:  goto L1918;
	case 3:  goto L22;
	case 4:  goto L1923;
	case 5:  goto L1924;
	case 6:  goto L1926;
	case 7:  goto L500;
	case 8:  goto L2800;
	case 9:  goto L180;
	case 10:  goto L1;
	case 11:  goto L1925;
	case 12:  goto L1904;
	case 13:  goto L700;
	case 14:  goto L1909;
	case 15:  goto L1909;
	case 16:  goto L1909;
	case 17:  goto L1912;
	case 18:  goto L200;
	case 19:  goto L190;
	case 20:  goto L1909;
	case 21:  goto L1901;
	case 22:  goto L800;
	case 23:  goto L801;
	case 24:  goto L1922;
	case 25:  goto L1922;
	case 26:  goto L1913;
	case 27:  goto L1921;
	case 28:  goto L1914;
	case 29:  goto L1942;
	case 30:  goto L4300;
	case 31:  goto L22;
	case 32:  goto L23;
	case 33:  goto L100;
	case 34:  goto L110;
	case 35:  goto L1968;
	case 36:  goto L8200;
	case 37:  goto L8100;
	case 38:  goto L11;
	case 39:  goto L12;
	case 40:  goto L3;
	case 41:  goto L8100;
	case 42:  goto L600;
	case 43:  goto L22;
	case 44:  goto L5700;
	case 45:  goto L5800;
	case 46:  goto L9100;
	case 47:  goto L9100;
	case 48:  goto L1;
	case 49:  goto L2100;
	case 50:  goto L2000;
	case 51:  goto L2200;
	case 52:  goto L9100;
	case 53:  goto L2100;
    }

/*           APTREN REFSYS   FINI RESERV CONTRL    SYN DYNDMP  ZSURF */

/*           JUMPTO */
/*           TRANTO     GO GODLTA  TOLER  INTOL OUTTOL CUTTER  MAXDP */

/*                         GOBACK */
/*                         GODOWN */
/*                          GOFWD */
/*                          GOLFT */
/*                          GORGT */
/*           NUMPTS  THICK   GOUP   GOTO   FROM INDIRV SRFVCT TLAXIS */

/*           INDIRP   PSIS  PRINT   CALL LOOPST LOOPND MACHIN NOPOST */

/*           POCKET TITLES  PUNCH 2DCALC 3DCALC TLNDON CFSAVE PPOPTN */
/*                                         GOLOFT */
/*           PTONLY                 INTSEC PLOTFT */
/*           REMARK                 GCLEAR GOMILL */
/*           TUNEUP   READ  UNITS   SCON   SMIL  UNUSED TLPROJ CLDAT */
/*           CHKSRF AVCTRL REGION */

/* ... PICK UP NAMTBL POINTER TO TLON */
L3:
    *k = aptxxx[97];
L10:
    if (hop != 6 && hop != 13) {
	goto L9;
    }
    if (*argtop > 1) {
	i__1 = 1 - *argtop;
	alarm_(&c__2002, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    if (*argtop != 0) {
	goto L8;
    }
    *argtop = 1;
    argstk[0] = name_(don, (ftnlen)6);
L8:
    if (s_cmp(cnamtb_1.cnamtb + (argstk[*argtop - 1] - 1) * 6, hon, (ftnlen)6,
	     (ftnlen)6) != 0 && s_cmp(cnamtb_1.cnamtb + (argstk[*argtop - 1] 
	    - 1) * 6, hoff, (ftnlen)6, (ftnlen)6) != 0) {
	i__1 = -(*argtop);
	alarm_(&c__2002, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    goto L3000;
L9:
    if (*argtop != 0) {
	i__1 = -(*argtop);
	alarm_(&c__2028, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    goto L3000;
/* ... PICK UP NAMTBL POINTER TO NDTEST */
L11:
    *k = aptxxx[95];
    goto L10;
/* ... PICK UP NAMTBL POINTER TO COMP3D */
L12:
    *k = aptxxx[96];
    goto L10;
L1:
    iret = 0;
    iret_fmt = fmt_22;
    if ((i__1 = *argtop - 1) < 0) {
	goto L9991;
    } else if (i__1 == 0) {
	goto L2;
    } else {
	goto L9989;
    }
L2:
    if (mode_(argstk) == *plane) {
	goto L3000;
    }
    alarm_(&c__2029, &c_n1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L9100:
    if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, golo, (ftnlen)6, (ftnlen)6) == 
	    0 || s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, plot, (ftnlen)6, (
	    ftnlen)6) == 0) {
	goloft_();
    } else {
	tssmil_();
    }
    goto L7080;

/*     *************** PROCESS POST PROCESSOR STATEMENT ***************** */


/* ... SET L = NUMBER OF CALLS TO APT299 TO BE GENERATED. */

L30:
    sub = *apt299;
L35:
    *l = *argtop / 2 + 1;

/* ... GENERATE CALLS. */

    i__1 = *l;
    for (i__ = 1; i__ <= i__1; ++i__) {
	callzz_(&sub);

/* ... INSERT TWO PAIRS OF ARGUMENTS IN ARGUMENT LIST. */

	for (*j = 1; *j <= 2; ++(*j)) {

/* ... THE FIRST PAIR IN THE FIRST CALL CONSISTS OF THE TOTAL NUMBER OF */
/* ... ARGUMENT PAIRS EXCLUSIVE OF THE FIRST PAIR AND THE MAJOR WORD IN */
/* ... PART PROGRAM STATEMENT. */

	    if (i__ + *j > 2) {
		goto L40;
	    }
	    twoarg_(quidlr, argtop);
	    argcvt_(k);
	    goto L60;

/* ... IF ARGSTK HAS BEEN EXHAUSTED,FILL OUT ARGUMENT LIST WITH ZEROS. */

L40:
	    if (*argtop > 0) {
		goto L50;
	    }
	    twoarg_(dlr, zero);
	    twoarg_(dlr, zero);
	    goto L60;

/* ... DETERMINE THE CLASS AND MODE OF THE NEXT ARGSTK ELEMENT AND SET */
/* ... N = THE CORRESPONDING CLMODE. IF THE ELEMENT IS INVALID,ISSUE A */
/* ... WARNING MESSAGE AND TREAT IT AS A PERMANENT IDENTIFIER. */

L50:
	    n = clmode_(&argstk[*argtop - 1]);
	    if (n != 2) {
		goto L52;
	    }
	    if (nametb_1.namtbl[argstk[*argtop - 1] - 1] % *modhlf == 0) {
		goto L53;
	    }
L52:
	    if (n != 0) {
		goto L55;
	    }
L53:
	    if (hop != 61 && hop != 33) {
		i__2 = -(*argtop);
		alarm_(&c__2002, &i__2, &c__8, "PRO026  ", (ftnlen)8);
	    }
	    n = 2;

/* ... INSERT CLMODE AND ARGSTK ELEMENT AS THE NEXT PAIR IN THE */
/* ... ARGUMENT LIST. */

L55:
	    twoarg_(quidlr, &n);
	    argcvt_(&argstk[*argtop - 1]);
	    --(*argtop);
L60:
	    ;
	}

/* ... RELEASE GENERATED I.L. */

	rlslin_();
/* L70: */
    }
    goto L22;

/* *********** SPECIAL PATH FOR CLPRNT,MACHIN AND NOPOST COMANDS ******** */

/* ... CLPRNT COMMAND */
/* ... IF THERE ARE NO ARGUMENTS,CALL APT298, IF THERE IS A SINGLE */
/* ... ARGUMENT WHICH IS EITHER ON OR OFF,PROCESS LIKE A POSTPROCESSOR */
/* ... COMMAND. OTHERWISE CALL ALARM. */

L80:
    if (*argtop == 0) {
	goto L90;
    }
    errpt = 1 - *argtop;
    if (*argtop > 1) {
	goto L85;
    }
    *l = argstk[0];
    if (*l > nametb_1.nammax) {
	goto L84;
    }
    if (s_cmp(cnamtb_1.cnamtb + (*l - 1) * 6, hon, (ftnlen)6, (ftnlen)6) == 0 
	    || s_cmp(cnamtb_1.cnamtb + (*l - 1) * 6, hoff, (ftnlen)6, (ftnlen)
	    6) == 0) {
	goto L30;
    }
L84:
    errpt = -1;
L85:
    alarm_(&c__2001, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L90:
    n = *one;
    goto L120;

/* ... MACHIN COMMAND */
/* ... IF THERE ARE NO ARGUMENTS,CALL ALARM. OTHERWISE CALL APT298 */

L100:
    errpt = *top - 1;
    if (*argtop == 0) {
	goto L85;
    }
    n = *three;
    if (*argtop > 1) {
	goto L130;
    }
    *argtop = 2;
    argstk[1] = argstk[0];
    argstk[0] = 0;
    goto L130;
/* ... NOPOST COMMAND */
L110:
    if (*argtop > 0) {
	i__1 = -(*argtop);
	alarm_(&c__2002, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    n = *two;
L120:
    argstk[0] = *zeropt;
    argstk[1] = *zeropt;
    *argtop = 2;
L130:
    callzz_(apt298);
    twoarg_(dlr, &n);
    argcvt_(&argstk[*argtop - 1]);
    argcvt_(&argstk[*argtop - 2]);
    rlslin_();
/* ... IF COMMAND IS MACHIN, GO TO POSTPROCESSOR PROCESSING NEXT. */
/* ... OTHERWISE TAKE NORMAL EXIT. */

    if (hop == 33) {
	goto L30;
    }
    goto L22;

/* ... CONTRL STATEMENT */

L500:
    if (*jumpto != 0) {
	*jumpto = *seqno + 2;
    }
    if (*argtop == 0) {
	goto L550;
    }
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*k = argstk[i__ - 1];
	if (*k > nametb_1.nammax) {
	    goto L530;
	}
	for (*j = 1; *j <= 4; ++(*j)) {
	    if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, icntrl + (*j - 1) * 6, (
		    ftnlen)6, (ftnlen)6) != 0) {
		goto L520;
	    }
	    cflags[*j - 1] = TRUE_;
	    goto L540;
L520:
	    ;
	}
L530:
	i__2 = -i__;
	alarm_(&c__2042, &i__2, &c__4, "PRO026  ", (ftnlen)8);
L540:
	;
    }
    goto L22;
L550:
    i__1 = *top - 1;
    alarm_(&c__2030, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    goto L22;

/* ... PPOPTN STATEMENT */

L600:
    if (*jumpto != 0) {
	*jumpto = *seqno + 2;
    }
    if (*argtop == 0) {
	goto L550;
    }
    errpt = -1;
    if (*argtop / 2 << 1 != *argtop) {
	goto L690;
    }
/*        CHECK EACH ARGUMENT PAIR */
    i__1 = *argtop;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	*k = argstk[i__ - 2];
	errpt = 1 - i__;
	if (*k > nametb_1.nammax) {
	    goto L690;
	}
	if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, hon, (ftnlen)6, (ftnlen)6) 
		!= 0) {
	    goto L605;
	}
	ltemp = TRUE_;
	goto L610;
L605:
	if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, hoff, (ftnlen)6, (ftnlen)6) 
		!= 0) {
	    goto L690;
	}
	ltemp = FALSE_;
L610:
	*k = argstk[i__ - 1];
	errpt = -i__;

	for (*j = 1; *j <= 5; ++(*j)) {
	    if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, ippopt + (*j - 1) * 6, (
		    ftnlen)6, (ftnlen)6) != 0) {
		goto L620;
	    }
	    hop = *j;
	    goto L625;
L620:
	    ;
	}
	goto L690;

L625:
	switch (hop) {
	    case 1:  goto L630;
	    case 2:  goto L640;
	    case 3:  goto L650;
	    case 4:  goto L660;
	    case 5:  goto L670;
	}
/*        INTLNG */
L630:
	*ilprt = ltemp;
	goto L680;
/*        PRTER */
L640:
	*prterr = ltemp;
	goto L680;
/*        REFMOT */
L650:
	*j = *two;
	if (ltemp) {
	    *j = *one;
	}
	goto L665;
/*        ALTMLT */
L660:
	*j = *four;
	if (ltemp) {
	    *j = *three;
	}
	goto L665;
/*         CILPRT */
L670:
	*j = *six;
	if (ltemp) {
	    *j = *five;
	}
/* ---     COMPRESSED IL PRINT IS TURNED ON FROM -ON- INPUT. */
	if (ltemp) {
	    *cilprt = TRUE_;
	}
L665:
	callzz_(&aptxxx[17]);
	twoarg_(dlr, j);
	rlslin_();
L680:
	;
    }
    goto L22;

/*        ERROR IN PPOPTN STATEMENT */
L690:
    alarm_(&c__2039, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

/* ... CALLED MACRO HAS NOT BEEN DEFINED.  CHECK FOR SYSTEM MACRO. */

L4300:
    igoto = 5;
    goto L99;

/* ...  DYNDMP , NUMPTS OR MAXDP STATEMENT */

L180:
    *j = 3;
    goto L201;
L200:
    *j = 2;
    if (*argtop != 1) {
	goto L201;
    }
    argstk[1] = argstk[0];
    argstk[0] = *zeropt;
    *argtop = 2;
    goto L202;
L190:
    *j = 1;
L201:
    if (*argtop == 0) {
	goto L209;
    }
    if (*argtop <= *j) {
	goto L202;
    }
    errpt = *j - *argtop;
    goto L210;
L202:
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	errpt = -i__;
	if (mode_(&argstk[i__ - 1]) != *real__) {
	    goto L205;
	}
/* L203: */
    }
    goto L3000;
L205:
    alarm_(&c__2021, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L209:
    errpt = *top - 1;
L210:
    alarm_(&c__2052, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

L3000:
    callzz_(k);
    if (*argtop != 0) {
	arggen_();
    }
L7080:
    rlslin_();
    if (s_cmp(cnamtb_1.cnamtb + (*k - 1) * 6, finit, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L151;
    }
L22:
    if (*entry__) {
	goto L6002;
    }
L6053:
    *newstm = TRUE_;
    *argtop = 0;
    return 0;
L23:
    if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, contin, 
	    (ftnlen)6, (ftnlen)6) != 0) {
	goto L22;
    }
    *dojump = 3;
    loop_();
    goto L22;

/* ... GODLTA STATEMENT */

L700:
    iret = 0;
    if (*argtop < 1) {
	goto L9991;
    }
    errpt = 4 - *argtop;
    if (*argtop > 4) {
	goto L9990;
    }
    switch (*argtop) {
	case 1:  goto L750;
	case 2:  goto L720;
	case 3:  goto L730;
	case 4:  goto L720;
    }
L720:
    *test = argstk[0];
    ilist = 1;
    if (mode_(test) != *real__) {
	goto L9992;
    }
    asnvar = 0;
    asnvar_fmt = fmt_725;
    goto L7002;

L725:
    --(*argtop);
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ergstk[i__ - 1] = ergstk[i__];
/* L728: */
	argstk[i__ - 1] = argstk[i__];
    }
    if (*argtop == 1) {
	goto L750;
    }

L730:
    *l = *zeropt;
L732:
    *j = gettmp_(vector);
    opcode_(move);
    argcvt_(j);
    for (i__ = 1; i__ <= 3; ++i__) {
	if (*argtop == 0) {
	    goto L735;
	}
	*test = argstk[*argtop - 1];
	ilist = *argtop;
	if (mode_(test) != *real__) {
	    goto L9992;
	}
	--(*argtop);
	goto L736;
L735:
	*test = *zeropt;
L736:
	argcvt_(test);
/* L740: */
    }
    rlslin_();
    if (*l == *zeropt) {
	refgen_(&c__3, j);
    }
    goto L760;

L750:
    *j = argstk[*argtop - 1];
    --(*argtop);
    ilist = *argtop;
    *l = mode_(j);
    if (*l != *real__) {
	goto L755;
    }
    *l = *j;
    goto L732;

L755:
    if (*l != *vector) {
	goto L790;
    }
    *l = *zeropt;
L760:
    callzz_(k);
    argcvt_(j);
    argcvt_(l);
    rlslin_();
    goto L22;

L790:
    i__1 = -ilist;
    alarm_(&c__2003, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

/* ...  ENTRY FOR*FROM* AND*GOTO* */
/*                             IF FIRST ELEMENT IS PATERN, PROCESS */
/*                             GOTO/PATERN STATEMENT. */
L800:
    if (mode_(&argstk[*argtop - 1]) != *patern) {
	goto L801;
    }
    gopat_();
    goto L22;

L801:
    iret = 0;
    if (*argtop < 1) {
	goto L9991;
    }
    errpt = 7 - *argtop;
    if (*argtop > 7) {
	goto L9990;
    }
    *test = argstk[0];
    n = mode_(test);
    ilist = 1;
    switch (*argtop) {
	case 1:  goto L860;
	case 2:  goto L830;
	case 3:  goto L825;
	case 4:  goto L820;
	case 5:  goto L805;
	case 6:  goto L845;
	case 7:  goto L805;
    }

/* ... FEEDRATE RECOGNITION */

L805:
    if (n != *real__) {
	goto L9992;
    }
L810:
    asnvar = 1;
    asnvar_fmt = fmt_815;
    goto L7002;
L815:
    --(*argtop);
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ergstk[i__ - 1] = ergstk[i__];
/* L818: */
	argstk[i__ - 1] = argstk[i__];
    }
    *test = argstk[0];
    n = mode_(test);
    switch (*argtop) {
	case 1:  goto L870;
	case 2:  goto L842;
	case 3:  goto L863;
	case 4:  goto L840;
	case 5:  goto L9997;
	case 6:  goto L845;
    }

L820:
    if (n != *real__) {
	goto L840;
    }
    if (mode_(&argstk[*argtop - 1]) != *real__) {
	goto L845;
    }
    goto L810;
L825:
    if (n != *real__) {
	goto L9992;
    }
    if (mode_(&argstk[1]) != *vector) {
	goto L863;
    }
    goto L810;
L830:
    if (n == *vector) {
	goto L842;
    }
    if (n != *real__) {
	goto L9992;
    }
    if (mode_(&argstk[*argtop - 1]) != *point) {
	goto L863;
    }
    goto L810;

/* ... TLAXIS RECOGNITION */

L840:
    if (n != *vector) {
	goto L845;
    }
L842:
    kk = *k;
    *k = *tlaxis;
    dstype = 3;
    asnvar = 2;
    asnvar_fmt = fmt_848;
    goto L1988;
L845:
    kk = *k;
    *k = *tlaxis;
    dstype = 3;
    asnvar = 3;
    asnvar_fmt = fmt_850;
    goto L1952;
L848:
    dstype = 1;
L850:
    *k = kk;
    *argtop -= dstype;
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*l = i__ + dstype;
	ergstk[i__ - 1] = ergstk[*l - 1];
/* L855: */
	argstk[i__ - 1] = argstk[*l - 1];
    }

/* ... GENERATE CALL TO FROM OR GOTO */

    if (*argtop != 1) {
	goto L862;
    }
    *test = argstk[0];
    n = mode_(test);
L860:
    errpt = -1;
    if (n != *point) {
	goto L890;
    }
    goto L870;
L862:
    ilist = *argtop;
    if (*argtop != 3) {
	goto L9997;
    }
L863:
    *l = gettmp_(point);
    opcode_(move);
    argcvt_(l);
    puttmp_(point);
    *j = 3;
    if (*argtop == 2) {
	*j = 2;
    }
    i__1 = *j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*test = argstk[*argtop - 1];
	ilist = *argtop;
	if (mode_(test) != *real__) {
	    goto L9992;
	}
	argcvt_(test);
/* L865: */
	--(*argtop);
    }
    rlslin_();
    *test = *l;
    if (*j != 2) {
	goto L867;
    }
    callzz_(apt001);
    argcvt_(l);
    rlslin_();
    goto L870;
L867:
    refgen_(&c__1, test);
L870:
    callzz_(k);
    argcvt_(test);
    rlslin_();
    *argtop = 0;
    goto L22;

L890:
    alarm_(&c__2011, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

/* ...  GO UP/ */
/* ...  INITIALIZE CHECK SURFACE COUNT */
L1901:
    motion_();
    if (*lerr >= 0) {
	goto L7080;
    } else {
	goto L9999;
    }
/* ...  GO/ COMMAND */
/*     INITIALIZATION */
L1904:
    *argcnt = *argtop;
    dsfind = FALSE_;
    psfind = FALSE_;
    *fmterr = FALSE_;
    *numbcs = 0;
    idrect = 0;
/* ...  TEST FOR EXHAUSTION OF AGRUMENT LIST */
L400:
    if (*argtop >= 1) {
	goto L401;
    }
/* ...  THE ARGUMENT LIST IS EXHAUSTED. IF A DS WAS FOUND, TAKE NORMAL OUT */
    if (dsfind) {
	goto L415;
    }
/* ...  ARGUMENT LIST EXHAUSTED WITHOUT FINDING A DRIVE SURFACE. */
    i__1 = *top - 1;
    alarm_(&c__2004, &i__1, &c__8, "PRO026  ", (ftnlen)8);
/* ...  TAKE RESTART ERROR EXIT */
    *fmterr = TRUE_;
    ierror = 2001;
    goto L499;
L401:
    *test = argstk[*argtop - 1];
    *test1 = mode_(test);
    if (*test1 == *real__) {
	goto L5000;
    }
    if (nametb_1.namtbl[*test - 1] / *modulo == permid[0] / *modulo) {
	goto L402;
    }
/* ...  NOT PERMANENT IDENTIFIER (TO,ON,PAST). TRY FOR SURFACE. */
    if (*test1 >= 1 && *test1 <= 17 || *test1 >= 29 && *test1 <= 30) {
	goto L406;
    }
L5000:
    if (! dsfind) {
	goto L420;
    }
    if (*test1 != *real__) {
	goto L414;
    }
    asnvar = 4;
    asnvar_fmt = fmt_415;
    goto L7002;
L414:
    i__1 = -(*argtop);
    alarm_(&c__2005, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    if (*fmterr) {
	goto L415;
    }
    ierror = 2002;
    *fmterr = TRUE_;
    goto L415;
/* ...  ITEM IS PERMANENT IDENTIFIER MAY BE TO,ON OR PAST */
L402:
    if (nametb_1.namtbl[*test - 1] - permid[0] == 3 || nametb_1.namtbl[*test 
	    - 1] - permid[0] == 503) {
	goto L404;
    }
/* ...  NO MATCH,ILLEGAL FORMAT. TO ASSUMED */
    i__1 = -(*argtop);
    alarm_(&c__2006, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    if (*fmterr) {
	goto L405;
    }
    ierror = 2003;
    *fmterr = TRUE_;
    goto L405;
/* ...  TO,ON OR PAST. SET IDRECT TO INDICATE MODE OF THIS SURFACE. */
L404:
    idrect = *test;
/* ...  INCREMENT POINTER TO NEXT ITEM. THEN INSPECT REST OF STATEMENT */
L405:
    --(*argtop);
    goto L400;
/* ...  A SURFACE HAS BEEN DETECTED. IF THE FIRST, STORE DATA FOR LATER OU */
/*     TPUT. IF NOT, SEND OUT PART AND CHECK SURFACE CALLS */

/* ...  CONVERT SURFACE TYPE TO BCD */
/* ...  IF DRIVE SURFACE WAS FOUND ALREADY, THIS MAY BE A PART SURFACE. */
L406:
    if (dsfind) {
	goto L407;
    }
/* ...  FIRST SURFACE NOTED IS DRIVE SURFACE */
    dsfind = TRUE_;
    hmod = idrect;
    *cspntr = *test;
/* ...  GO BACK FOR REST OF STATEMENT */
    goto L6006;
/* ...  IF PART SURFACE WAS FOUND ALREADY, THIS IS A CHECK SURFACE */
L407:
    if (psfind) {
	goto L409;
    }
/* ...  SECOND SURFACE NOTED IS PART SURFACE */
    psfind = TRUE_;
    callzz_(psis);
    if (idrect <= 0) {
	goto L6012;
    } else {
	goto L6013;
    }
L6012:
    twoarg_(dbldlr, to);
    goto L6014;
L6013:
    argcvt_(&idrect);
L6014:
    argcvt_(test);
L408:
    rlslin_();
L6006:
    idrect = 0;
    goto L405;
/* ...  CHECK SURFACES */
L409:
    ++(*numbcs);
    if (*numbcs == 1) {
	goto L410;
    }
    i__1 = -(*argtop);
    alarm_(&c__2008, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L6006;
L410:
    callzz_(apt200);
    if (idrect <= 0) {
	goto L6015;
    } else {
	goto L6016;
    }
L6015:
    twoarg_(dbldlr, to);
    goto L6017;
L6016:
    argcvt_(&idrect);
L6017:
    argcvt_(test);
    argcvt_(onept);
    goto L408;
/* ...  NESTED FEDRAT */
L7002:
    callzz_(apt299);
    twoarg_(quidlr, &c__1);
    twoarg_(dbldlr, fedrat);
    twoarg_(quidlr, &c__1);
    argcvt_(test);
    rlslin_();
    switch (asnvar) {
	case 0: goto L725;
	case 1: goto L815;
	case 2: goto L848;
	case 3: goto L850;
	case 4: goto L415;
	case 5: goto L22;
    }
/* ...  STATEMENT SHOULD NOW BE COMPLETELY PROCESSED */
L415:
    if (*argtop > 1) {
	i__1 = 1 - *argtop;
	alarm_(&c__2007, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
/* ...  ANY FORMAT ERRORS ENCOUNTERED */
    if (*fmterr) {
	goto L499;
    }
/* ...  OUTPUT GO/ CALL */
L7007:
    callzz_(k);
    if (hmod <= 0) {
	goto L6018;
    } else {
	goto L6019;
    }
L6018:
    twoarg_(dbldlr, to);
    goto L6020;
L6019:
    argcvt_(&hmod);
L6020:
    argcvt_(cspntr);
    if (hmod >= 0) {
	goto L7080;
    }
    argcvt_(&argstk[1]);
    argcvt_(argstk);
    goto L7080;
L420:
    i__1 = -(*argtop);
    alarm_(&c__2009, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    if (*fmterr) {
	goto L405;
    }
    *fmterr = TRUE_;
    ierror = 2004;
    goto L405;
/* ...  ERROR IN GO/ COMMAND SIGNAL RESTART WITH FIRST UNRECOVERABLE ERROR */
L499:
    callzz_(error);
    twoarg_(quidlr, &ierror);
    goto L7080;

/* ...     TLAXIS */
L1913:
    pro028_(&eras);
    goto L22;

L1952:
    *test = gettmp_(vector);
    opcode_(move);
    twoarg_(nought, test);
    for (i__ = 1; i__ <= 3; ++i__) {
	ilist = 4 - i__;
	m = argstk[ilist - 1];
	if (mode_(&m) != *real__) {
	    goto L9992;
	}
/* L1954: */
	argcvt_(&m);
    }
    rlslin_();
    refgen_(&c__3, test);
    puttmp_(vector);
    goto L1988;

/* ...     CUTTER */
L1912:
    errpt = 7 - *argtop;
    iret = 1;
    iret_fmt = fmt_9999;
    if (*argtop > 7) {
	goto L9990;
    }
    if (*argtop < 1) {
	goto L9991;
    }
    goto L1970;

/* ...     INTOL, OUTTOL, THICK, TOLER */
L1909:
    errpt = 4 - *argtop;
    iret = 1;
    iret_fmt = fmt_9999;
    if (*argtop > 4) {
	goto L9990;
    }
    if (*argtop == 4) {
	goto L1970;
    }
    if (*argtop < 1) {
	goto L9991;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	n = *argtop + 1 - i__;
	if (n <= 0) {
	    n = 1;
	    if (argstk[0] > nametb_1.nammax) {
		numblk_1.lstchr = 0;
		argstk[0] = numb_(cnamtb_1.cnumtb + (argstk[0] - 
			nametb_1.nammax - 1) * 12, (ftnlen)12) + 
			nametb_1.nammax;
	    }
	}
	argstk[5 - i__ - 1] = argstk[n - 1];
/* L1911: */
    }
    *argtop = 4;
L1970:
    dstype = *argtop;
    n = *argtop;
/* ...     CHECK FOR SCALARS */
    i__1 = n;
    for (ilist = 1; ilist <= i__1; ++ilist) {
	*test = argstk[ilist - 1];
	if (mode_(test) != *real__) {
	    goto L9992;
	}
/* L1980: */
    }
/* ...     MOVE ARGUMENTS TO APTER ARRAY */
    if (eras) {
	goto L1982;
    }
    resrvz_(erasb, &c__0, &c__9, &c__1);
    eras = TRUE_;
L1982:
    opcode_(move);
    twoarg_(nought, erasb);
    arggen_();
    rlslin_();
    *test = *erasb;
    asnvar = 5;
/* ...     GENERATE CALL TO SUBROUTINE */
L1988:
    callzz_(k);
    twoarg_(quidlr, &dstype);
    if (*k == *tlaxis) {
	twoarg_(quidlr, &c__7);
    }
    argcvt_(test);
    rlslin_();
    switch (asnvar) {
	case 0: goto L725;
	case 1: goto L815;
	case 2: goto L848;
	case 3: goto L850;
	case 4: goto L415;
	case 5: goto L22;
    }
/* ...     PARAMETER LIST TOO LONG */
L9989:
    errpt = 1 - *argtop;
L9990:
    alarm_(&c__2012, &errpt, &c__8, "PRO026  ", (ftnlen)8);
L9999:
    callzz_(error);
    twoarg_(quidlr, &c__83);
    rlslin_();
    *argtop = 0;
    goto L22;
/* ...     NO PARAMETERS GIVEN */
L9991:
    i__1 = *top - 1;
    alarm_(&c__12, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L9200;
/* ...     ILLEGAL ARGUMENT */
L9992:
    i__1 = -ilist;
    alarm_(&c__2013, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L9200;
/* ...     WRONG CLDAT SEQUENCE */
L9995:
    i__1 = -(*argtop);
    alarm_(&c__2046, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L9200;
/* ...  TOOL TO SURFACE RELATIONSHIPS */
L1923:
    refref_();
    goto L22;
L9997:
    i__1 = -ilist;
    alarm_(&c__2052, &i__1, &c__8, "PRO026  ", (ftnlen)8);
L9200:
    switch (iret) {
	case 0: goto L22;
	case 1: goto L9999;
    }

/* ...     CLDAT/..................... */
L2000:
    iret = 0;
    if (*argtop == 0) {
	goto L9991;
    }
/* L2002: */
    *j = argstk[*argtop - 1];
    *l = argstk[0];
    if (mode_(j) != *real__) {
	goto L2004;
    }
/* ...     IT MUST BE CLDAT/0.,1.,3.,(ON-OFF) */
    errpt = -1;
    if (*argtop < 4) {
	goto L9997;
    }
    errpt = 4 - *argtop;
    if (*argtop > 4) {
	goto L9990;
    }
    ilist = 1;
    if (s_cmp(cnamtb_1.cnamtb + (*l - 1) * 6, hon, (ftnlen)6, (ftnlen)6) != 0 
	    && s_cmp(cnamtb_1.cnamtb + (*l - 1) * 6, hoff, (ftnlen)6, (ftnlen)
	    6) != 0) {
	goto L9992;
    }
    for (i__ = 2; i__ <= 3; ++i__) {
	ilist = *argtop - i__;
	if (mode_(&argstk[i__ - 1]) != *real__) {
	    goto L9992;
	}
/* L2003: */
    }
    goto L30;
/* ... */
L2004:
    sub = *k;
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, start, (ftnlen)6, (ftnlen)6) != 
	    0) {
	goto L2012;
    }
/* ...     IT MUST BE CLDAT/START,INDEX,......... */
    errpt = 11 - *argtop;
    if (*argtop > 11) {
	goto L9990;
    }
    if (! odd1 || ! odd2) {
	goto L9995;
    }
    odd = FALSE_;
L2005:
    ilist = *argtop;
    if (*argtop < 2) {
	goto L9997;
    }
    ilist = *argtop - 1;
    if (mode_(&argstk[ilist - 1]) != *real__) {
	goto L9992;
    }
    *j = *argtop - 2;
    if (*j < 1) {
	goto L2009;
    }
L2006:
    i__1 = *j;
    for (ilist = 1; ilist <= i__1; ++ilist) {
	n = nametb_1.namtbl[argstk[ilist - 1] - 1] - permid[0];
	if (n > *modhlf) {
	    n -= *modhlf;
	}
	if (n < 180 || n > 188) {
	    goto L9992;
	}
/* L2008: */
    }
L2009:
    if (*j == *argtop) {
	goto L2010;
    }
    odd1 = odd;
    goto L35;
L2010:
    odd2 = FALSE_;
    goto L35;
/* ... */
L2012:
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, nomore, (ftnlen)6, (ftnlen)6) !=
	     0) {
	goto L2014;
    }
/* ...     IT MUST BE CLDAT/NOMORE,INDEX,......... */
    if (odd1) {
	i__1 = -(*argtop);
	alarm_(&c__2046, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    odd = TRUE_;
    goto L2005;
/* ... */
L2014:
    if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, normal, (ftnlen)6, (ftnlen)6) !=
	     0) {
	goto L2016;
    }
/* ...     IT MUST BE CLDAT/NORMAL */
    if (odd2) {
	i__1 = -(*argtop);
	alarm_(&c__2046, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    }
    if (*argtop > 1) {
	goto L9989;
    }
    odd2 = TRUE_;
    goto L35;
/* ...     IT MUST BE CLDAT/TP,TA,TV,PDS,PPS,NDS,NPS,UVPDS,UVPPS */
L2016:
    ilist = *argtop;
    if (! odd1 || ! odd2) {
	goto L9995;
    }
    errpt = 9 - *argtop;
    if (*argtop > 9) {
	goto L9990;
    }
    *j = *argtop;
    goto L2006;

/* ...     TLPROJ/.................... */
/* ...     REGION/.................... */
L2100:
    if (*argtop == 0) {
	goto L9991;
    }
    errpt = 2 - *argtop;
    if ((i__1 = *argtop - 2) < 0) {
	goto L2110;
    } else if (i__1 == 0) {
	goto L2120;
    } else {
	goto L9990;
    }
L2110:
    *argtop = 2;
    argstk[*argtop - 1] = *zeropt;
    if (argstk[0] <= nametb_1.nammax) {
	if (s_cmp(cnamtb_1.cnamtb + (argstk[0] - 1) * 6, hoff, (ftnlen)6, (
		ftnlen)6) == 0) {
	    goto L3000;
	}
    }
    goto L2130;
L2120:
    ilist = *argtop;
    *j = argstk[*argtop - 1];
    if (*j <= nametb_1.nammax) {
	if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hon, (ftnlen)6, (ftnlen)6) 
		== 0 || s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hat, (ftnlen)6, 
		(ftnlen)6) == 0) {
	    goto L2130;
	}
    }
    if (mode_(j) != *real__) {
	goto L9992;
    }
    ilist = 1;
    *j = argstk[ilist - 1];
    if (*j <= nametb_1.nammax) {
	if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hin, (ftnlen)6, (ftnlen)6) 
		== 0 || s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hout, (ftnlen)6,
		 (ftnlen)6) == 0) {
	    goto L3000;
	}
    }
    goto L9992;
L2130:
    ilist = 1;
    *j = argstk[ilist - 1];
    if (mode_(j) == *vector) {
	goto L3000;
    }
    if (*j <= nametb_1.nammax) {
	if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, normal, (ftnlen)6, (ftnlen)
		6) == 0) {
	    goto L3000;
	}
    }
    goto L9992;

/* ... CHKSRF/.... */

L2200:
    if (*argtop == 0) {
	goto L9991;
    }
    errpt = -1;
    if (*argtop % 2 != 0) {
	alarm_(&c__2055, &errpt, &c__8, "PRO026", (ftnlen)6);
    } else {
/* ... CHECK ARGUMENT PAIRS */
	i__1 = *argtop;
	for (i__ = 2; i__ <= i__1; i__ += 2) {
/* ... 2ND ARGUMENT OF PAIR SHOULD BE 'ON' OR 'OFF' */
	    *j = argstk[i__ - 2];
	    errpt = 1 - i__;
	    if (*j > nametb_1.nammax) {
		alarm_(&c__2056, &errpt, &c__8, "PRO026", (ftnlen)6);
		goto L22;
	    } else if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hon, (ftnlen)6, (
		    ftnlen)6) == 0 || s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, 
		    hoff, (ftnlen)6, (ftnlen)6) == 0) {
		jmod = *j;
	    } else {
		alarm_(&c__2056, &errpt, &c__8, "PRO026", (ftnlen)6);
		goto L22;
	    }
/* ... 1ST ARGUMENT OF PAIR SHOULD BE 'PS' OR A SSURF */
	    *j = argstk[i__ - 1];
	    errpt = -i__;
	    if (*j > nametb_1.nammax) {
		alarm_(&c__2057, &errpt, &c__8, "PRO026", (ftnlen)6);
		goto L22;
	    } else {
		*test1 = mode_(j);
		if (s_cmp(cnamtb_1.cnamtb + (*j - 1) * 6, hps, (ftnlen)6, (
			ftnlen)6) == 0 || *test1 == *ssurf) {
		    callzz_(k);
		    argcvt_(j);
		    argcvt_(&jmod);
		    rlslin_();
		} else {
		    alarm_(&c__2057, &errpt, &c__8, "PRO026", (ftnlen)6);
		    goto L22;
		}
	    }
/* L2280: */
	}
    }
    goto L22;

/* ... RESERVE SPACE FOR THE TWO LARGEST LARGE DATA ARRAYS. */

L1924:
    labcon_(&c__0);
    *dojump = 5;
    loop_();
    if (maxsiz[0] == 0) {
	goto L1920;
    }

    maxtwo = abs(maxsiz[0]) + abs(maxsiz[1]);


    resrvz_(dottab, &c_n1, &maxtwo, &c__1);
L1920:
    if (*ifdump != 0) {
	goto L8300;
    }
    goto L3000;
/* ... INDICATE FINI STATEMENT HAS BEEN PROCESSED */
L151:
    *fini = TRUE_;

    if (*macdfp == 0) {
	goto L7777;
    }
    mnproc_();
    if (*macend) {
	goto L7777;
    }
    *macred = TRUE_;
    *intmed = 1;
    goto L6053;
L7777:
    epilog_();
    goto L6053;
L1918:
    *aptran = TRUE_;
/*     CALL READ         CAUSES ABNORMAL END */
    goto L22;
/* ...  PSIS/SURFACE */
L1914:
    if (*argtop > 0) {
	goto L1400;
    }
    i__1 = *top - 1;
    alarm_(&c__13, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L1400:
    ilist = *argtop - 3;
    if (*argtop > 3) {
	goto L9997;
    }
/* ...  COMPUTE POINTER AND MODE */
    *cspntr = argstk[*argtop - 1];
    cstype = mode_(cspntr);
/* ...  IS THE FIRST ITEM A LEGITIMATE SURFACE */
    if (cstype >= 1 && cstype <= 17 || cstype >= 29 && cstype <= 30) {
	goto L1401;
    }
    i__1 = -(*argtop);
    alarm_(&c__2015, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L1401:
    hmod = -1;
    if (*argtop > 1) {
	goto L1402;
    }
/* ...  FORMAT OK */
    argstk[1] = zero[0];
L1404:
    argstk[0] = zero[0];
    argstk[2] = *cspntr;
    goto L7007;
/*     MORE THAN ONE ITEM FOLLOW THE SLASH */
L1402:
    ilist = *argtop - 1;
    *j = argstk[ilist - 1];
    if (*argtop == 3) {
	goto L1405;
    }
    if (nametb_1.namtbl[*j - 1] != 20029) {
	goto L9992;
    }
    argstk[1] = argstk[0];
    goto L1404;
/*     LIMIT AND SCALAR SHOULD FOLLOW */
L1405:
    if (nametb_1.namtbl[*j - 1] != 20139) {
	goto L9992;
    }
    ilist = *argtop - 2;
    if (mode_(argstk) != *real__) {
	goto L9992;
    }
    goto L7007;

L1925:
    errpt = *top - 1;
    if (*argtop < 1) {
	goto L2411;
    }
    errpt = 1 - *argtop;
    m = 1;
    if ((i__1 = *argtop - 2) < 0) {
	goto L6040;
    } else if (i__1 == 0) {
	goto L2411;
    } else {
	goto L6038;
    }
L6038:
    *j = argstk[0];
    m = 2;
    if (*j <= nametb_1.nammax) {
	if (nametb_1.namtbl[*j - 1] / *modulo * *modulo == temp[0]) {
	    goto L6039;
	}
    }
    if (mode_(j) != *real__) {
	goto L1928;
    }
L6039:
    resrvz_(dotac, real__, &c__1, &c__1);
    opcode_(repl);
    onearg_(&c__1);
    argcvt_(dotac);
    argcvt_(j);
    rlslin_();
    opcode_(vbljmp);
    argcvt_(dotac);
L6040:
    i__1 = *argtop;
    for (i__ = m; i__ <= i__1; ++i__) {
	errpt = *argtop + m - i__;
	*cspntr = argstk[errpt - 1];
	if (*cspntr > nametb_1.nammax) {
	    goto L5001;
	}
	*test1 = *modulo * (nametb_1.namtbl[*cspntr - 1] / *modulo);
	if (*test1 == temp[0] || *test1 == vbl[0]) {
	    goto L2410;
	}
	if (*test1 != label[0] && *test1 != implab[0]) {
	    nametb_1.namtbl[*cspntr - 1] = implab[0];
	}
	if (*whchmn == 0) {
	    goto L6044;
	}
	goto L6046;
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L5001:
	*cspntr -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, cspntr, &idummy);
	}
	bcdbin_(cnamtb_1.cnumtb + (*cspntr - 1) * 12, &kk, &icount, (ftnlen)
		12);
	*cspntr = kk + 10000;
L6046:
	i__2 = -(*whchmn);
	maclbl_(cspntr, &i__2, cspntr);
	if (nametb_1.namtbl[*cspntr - 1] == 0) {
	    nametb_1.namtbl[*cspntr - 1] = implab[0] + *whchmn;
	}
L6044:
	if (*argtop > 1) {
	    goto L6041;
	}
	jumpzz_(cspntr);
	goto L6042;
L6041:
	onearg_(cspntr);
L6042:
	labcon_(cspntr);
/* L6045: */
    }
    if (*argtop > 1) {
	rlslin_();
    }
    goto L22;
L2410:
    if (*argtop > 1) {
	rlslin_();
    }
L2411:
    i__1 = -errpt;
    alarm_(&c__2017, &i__1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L1928:
    alarm_(&c__1008, &c_n1, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

/* ...     UNITS STATEMENT */
L5800:
    errpt = 1 - *argtop;
    if ((i__1 = *argtop - 1) < 0) {
	goto L5801;
    } else if (i__1 == 0) {
	goto L3000;
    } else {
	goto L5802;
    }
L5801:
    errpt = *top - 1;
L5802:
    alarm_(&c__2052, &errpt, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;

L8100:
    if (*argtop > 0) {
	goto L8120;
    }
    i__1 = *top - 1;
    alarm_(&c__2030, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    goto L22;
L8200:
    *k = name_(srprnt, (ftnlen)6);
    callzz_(k);
    twoarg_(quidlr, &c__9);
    argcvt_(&argstk[*argtop - 1]);
    twoarg_(quidlr, &c__1);
    rlslin_();
    goto L22;
L1926:
    if (*finmac) {
	goto L1927;
    }
    if (! (*ilhlt)) {
	reserv_();
    }
    goto L22;
L1927:
    alarm_(&c__2045, &c__0, &c__8, "PRO026  ", (ftnlen)8);
    goto L22;
L2800:
    igoto = 1;
    goto L99;
L1942:
    igoto = 2;
    goto L99;
L1968:
    igoto = 3;
    goto L99;

/*     PUNCH */

L8110:
    igoto = 4;
    goto L99;
L1921:
    igoto = 7;
    goto L99;
L1922:
    igoto = 8;
    goto L99;
L5700:
    igoto = 6;
L99:
    pro027_(&igoto);
    goto L22;

/* ...  P R O C E S S I N G   F O R   C F S A V E   A N D   P U N C H */

L8120:
    i__ = argstk[*argtop - 1];

/*     CHECK IF FIRST ARGUMENT IS A DIGIT. */

    *l = i__;
    if (i__ <= nametb_1.nammax) {
	goto L8150;
    }
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    i__ -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &i__, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (i__ - 1) * 12, j, l, (ftnlen)12);

/*     FIRST ARGUMENT IS A DIGIT.  CHECK IF IT IS LEGAL. */

    if (*j <= 3) {
	goto L8140;
    }
L8130:
    i__1 = -(*argtop);
    alarm_(&c__2031, &i__1, &c__4, "PRO026  ", (ftnlen)8);
    goto L22;

L8140:
    if (*argtop == 1) {
	goto L8130;
    }
    --(*argtop);
    i__ = argstk[*argtop - 1];

/*     CHECK IF SECOND ARGUMENT IS 'ALL'. */

    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, hall, (ftnlen)6, (ftnlen)6) != 
	    0) {
	goto L8130;
    }
    goto L8180;

/*     DETERMINE THE FIRST ARGUMENT */
/*  PUNCH/ALL */
L8150:
    *j = 1;
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, hall, (ftnlen)6, (ftnlen)6) == 
	    0) {
	goto L8180;
    }
/*  PUNCH/SCALAR , PUNCH/GEOM  ,  PUNCH/LISTON  , PUNCH/NOLIST */
    m = nametb_1.namtbl[i__ - 1] % *modhlf;
    *j = m - 124;
    if (*j > 1 && *j < 6) {
	goto L8180;
    }
/*  PUNCH/RANDOM,... */
    *j = 7;
    if (m == 56) {
	goto L8180;
    }
/*  PUNCH/RETAIN,... */
    *j = 8;
    if (m == 65) {
	goto L8180;
    }
/*  MUST BE A LIST OF VARIABLE NAMES. */
    *j = 6;

/*     CHECK IF PUNCH WAS SPECIFIED. */

L8180:
    if (hop == 37) {
	goto L8110;
    }

/*     CFSAVE */

    switch (*j) {
	case 1:  goto L8240;
	case 2:  goto L8240;
	case 3:  goto L8240;
	case 4:  goto L8130;
	case 5:  goto L8130;
	case 6:  goto L8220;
    }
L8220:
    if (mode_(&i__) != *object) {
	goto L8130;
    }
    *j = i__;

L8240:
    *ifdump = *j;
    goto L22;

/* ...  GENERATE CALL TO APT104 IF IFDUMP IS INDEX TO OBJECT. */

L8300:
    if (*ifdump <= 3) {
	goto L3000;
    }
    callzz_(&aptxxx[84]);
    argcvt_(ifdump);
    rlslin_();
    goto L3000;
} /* pro026_ */

#undef ergstk
#undef dojump
#undef aptxxx
#undef jumpto
#undef ifdump
#undef numbcs
#undef cspntr
#undef argcnt
#undef zeropt
#undef fmterr
#undef modulo
#undef tlaxis
#undef prterr
#undef newstm
#undef maxsiz
#undef quidlr
#undef nought
#undef whchmn
#undef majwrd
#undef intmed
#undef vector
#undef should
#undef patern
#undef vbljmp
#undef cilprt
#undef argtop
#undef argstk
#undef aptran
#undef permid
#undef dottab
#undef proced
#undef estack
#undef modhlf
#undef object
#undef fedrat
#undef implab
#undef dbldlr
#undef cflags
#undef finmac
#undef macred
#undef macdfp
#undef macend
#undef ssurf
#undef entry__
#undef error
#undef ilprt
#undef point
#undef seqno
#undef onept
#undef nlast
#undef ilhlt
#undef major
#undef three
#undef stack
#undef plane
#undef erasb
#undef dotac
#undef label
#undef test1
#undef apt299
#undef apt298
#undef apt200
#undef apt001
#undef test
#undef zero
#undef psis
#undef four
#undef move
#undef temp
#undef lerr
#undef repl
#undef nine
#undef five
#undef meta
#undef fini
#undef real__
#undef two
#undef six
#undef top
#undef way
#undef vbl
#undef dlr
#undef one
#undef to
#undef l
#undef k
#undef j


