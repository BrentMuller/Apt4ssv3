/* RECOG.f -- translated by f2c (version 20100827).
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
    integer srctbl[1482];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[13];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer seqno;
} seqcom_;

#define seqcom_1 seqcom_

struct {
    char seqnum[6];
} cseqcm_;

#define cseqcm_1 cseqcm_

struct {
    integer nonept;
} negptr_;

#define negptr_1 negptr_

struct {
    integer prt[7];
} prt_;

#define prt_1 prt_

struct {
    integer sbscpt[101];
} sbscpt_;

#define sbscpt_1 sbscpt_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    char chr[400];
} chrx_;

#define chrx_1 chrx_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer sublst[136];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    integer isscom[9];
} isscom_;

#define isscom_1 isscom_

struct {
    integer icallf;
} calflg_;

#define calflg_1 calflg_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

struct {
    integer canstr[18];
} canstr_;

#define canstr_1 canstr_

struct {
    integer doloop[9];
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

struct {
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__1009 = 1009;
static integer c__4 = 4;
static integer c__2 = 2;
static integer c__1111 = 1111;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__1003 = 1003;
static integer c__1004 = 1004;
static integer c__1008 = 1008;
static integer c__1005 = 1005;
static integer c__12 = 12;
static integer c__2025 = 2025;
static integer c__1029 = 1029;
static integer c__1007 = 1007;
static integer c__2052 = 2052;
static integer c__16 = 16;

/* *** SOURCE FILE : M0006672.W05   *** */


/*              FORTRAN SUBROUTINE RECOG */

/* LINKAGE      SUBROUTINE  RECOG */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    LARGES          SUBROUTINE    START */
/*          SUBROUTINE    LCANON */
/*          SUBROUTINE    BINBCD */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    MACREC */
/*          LOGICAL FCT.  IFTMP */
/*          SUBROUTINE    MATCH */
/*          SUBROUTINE    MCXTRN */
/*          SUBROUTINE    INPUT */
/*          SUBROUTINE    ISSCOD */
/*          INTEGER FCT.  NAME */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    PATH */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    PRO020 */
/*          SUBROUTINE    PRO026 */
/*          SUBROUTINE    PRO027 */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    RECOGN */
/*          SUBROUTINE    REPLAC */
/*          SUBROUTINE    RESRED */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    LABELZ */
/*          SUBROUTINE    SETCHR */
/*          SUBROUTINE    SETMOD */
/*          SUBROUTINE    INPAT */
/*          SUBROUTINE    ARGGEN */
/*          SUBROUTINE    SSDEF */
/*          SUBROUTINE    SUBCOD */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    CONCAT */
/*          SUBROUTINE    BCDBIN */
/*          SUBROUTINE    LABCON */
/*          SUBROUTINE    LOOP */
/*          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    KONAST */
/*          SUBROUTINE    VCTPRD */
/*          INTEGER FCT.  BCDF */
/*          SUBROUTINE    HOLFRM */

/* Subroutine */ int recog_(void)
{
    /* Initialized data */

    static integer lbkpnt = 1;
    static char blk[6] = "      ";
    static integer cldata = 69;
    static char iseq1[6] = " 1    ";
    static char true__[6] = ".TRUE.";
    static char false__[6] = ".FALSE";
    static integer strcnt = 0;
    static char on[6] = "ON    ";
    static char off[6] = "OFF   ";
    static char icd21[6] = "$21T$1";
    static char zero[3] = "  0";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3, i__4;
    static integer equiv_105[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n3, m5, n5, ii, kk, op, kt2;
#define fcn ((integer *)&code_1 + 34)
    static integer arg, iii, ibr;
#define vbl ((integer *)&code_1 + 60)
    static integer atp;
#define dot ((integer *)&code_1 + 48)
    static integer nwd;
#define not ((integer *)&code_1 + 54)
#define way ((integer *)&macxx1_1 + 25)
#define top ((integer *)&stklst_1)
#define arg1 (equiv_105)
#define arg2 (equiv_105 + 1)
#define fadd ((integer *)&il_1)
    extern integer bcdf_(char *, ftnlen), name_(char *, ftnlen);
    static integer iarg;
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define meta ((integer *)&srctbl_1 + 2)
#define geom ((integer *)&code_1 + 30)
#define fdiv ((integer *)&il_1 + 3)
    static integer nchr;
#define bool ((integer *)&modx_1 + 22)
    extern /* Subroutine */ int path_(void);
#define fsub ((integer *)&il_1 + 1)
#define issa ((integer *)&isscom_1)
#define issb ((integer *)&isscom_1 + 1)
#define fexp ((integer *)&il_1 + 4)
#define issc ((integer *)&isscom_1 + 2)
#define temp ((integer *)&code_1 + 32)
#define argx (equiv_105)
    extern /* Subroutine */ int loop_(void);
    static integer bkpt;
#define fmpy ((integer *)&il_1 + 2)
    static integer errp;
    extern integer numb_(char *, ftnlen);
#define plus ((integer *)&code_1 + 12)
    static integer rslt;
    extern /* Subroutine */ int pro020_(integer *), pro026_(void), pro027_(
	    integer *);
    static integer topt2;
#define label ((integer *)&code_1 + 42)
#define dotac ((integer *)&bcdptr_1)
#define comma ((integer *)&code_1)
#define canon ((integer *)&code_1 + 82)
#define range ((integer *)&sbscpt_1 + 1)
#define undef ((integer *)&sublst_1 + 73)
    static char iichr[20];
#define ident ((integer *)&code_1 + 68)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define stack ((integer *)&stklst_1 + 3)
#define reldo ((integer *)&doloop_1 + 2)
#define relat ((integer *)&code_1 + 52)
#define major ((integer *)&macxx1_1 + 43)
    extern /* Subroutine */ int match_(void);
#define slash ((integer *)&code_1 + 8)
    static integer icnum[3];
#define ilhlt ((logical *)&macxx1_1 + 13)
#define aster ((integer *)&code_1 + 16)
    extern logical iftmp_(integer *);
#define issfl ((logical *)&isscom_1 + 5)
#define nlast ((integer *)&ntbl_1 + 3)
#define lterm ((integer *)&code_1 + 46)
    extern /* Subroutine */ int inpat_(integer *, integer *);
#define onept ((integer *)&numptr_1 + 3)
    extern /* Subroutine */ int ssdef_(integer *, integer *);
#define rterm ((integer *)&code_1 + 6)
#define tenpt ((integer *)&numptr_1 + 12)
#define minus ((integer *)&code_1 + 10)
#define rngpt ((integer *)&sbscpt_1)
#define quote ((integer *)&code_1 + 22)
#define point ((integer *)&modx_1 + 18)
    extern /* Subroutine */ int input_(void);
#define kreuz ((integer *)&code_1 + 50)
#define entry__ ((logical *)&macxx1_1 + 39)
#define ssurf ((integer *)&modx_1 + 28)
#define scurv ((integer *)&modx_1 + 29)
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen),
	     bcdbin_(char *, integer *, integer *, ftnlen);
#define macldd ((logical *)&macxx1_1 + 6)
#define decmal ((integer *)&code_1 + 40)
#define ifflag ((logical *)&doloop_1 + 8)
#define macred ((logical *)&macxx1_1 + 17)
#define biggeo ((integer *)&code_1 + 86)
#define finmac ((logical *)&macxx1_1 + 23)
#define doflag ((logical *)&doloop_1 + 6)
#define endflg ((logical *)&flags_1)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define implab ((integer *)&code_1 + 44)
#define object ((integer *)&modx_1 + 27)
#define dblast ((integer *)&code_1 + 62)
#define congeo ((integer *)&code_1 + 76)
#define holdat ((integer *)&il_1 + 20)
#define proced ((integer *)&code_1 + 36)
#define dollar ((integer *)&code_1 + 28)
#define permid ((integer *)&code_1 + 38)
#define lparen ((integer *)&code_1 + 2)
#define number ((integer *)&code_1 + 26)
#define rparen ((integer *)&code_1 + 4)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define mcltrm ((integer *)&code_1 + 74)
#define letter ((integer *)&code_1 + 20)
#define conast ((integer *)&code_1 + 88)
#define conpro ((integer *)&code_1 + 78)
#define prodtb ((integer *)&srctbl_1 + 52)
#define brkpnt ((integer *)&srctbl_1)
#define mbkpnt ((integer *)&srctbl_1 + 1)
#define interp ((logical *)&prt_1 + 2)
#define newstm ((logical *)&flags_1 + 1)
#define seqnce ((integer *)&il_1 + 8)
#define conjmp ((integer *)&il_1 + 10)
#define tabcyl ((integer *)&modx_1 + 10)
#define vector ((integer *)&modx_1 + 19)
#define zeropt ((integer *)&numptr_1 + 1)
#define subscr ((integer *)&modx_1 + 23)
#define string ((integer *)&modx_1 + 24)
#define patern ((integer *)&modx_1 + 25)
#define bounds ((integer *)&modx_1 + 26)
#define should ((logical *)&macxx1_1 + 69)
#define textst ((integer *)&macxx1_1 + 14)
#define intmed ((integer *)&macxx1_1 + 21)
#define majwrd ((integer *)&macxx1_1 + 22)
#define whchmn ((integer *)&macxx1_1 + 62)
#define modulo ((integer *)&moduli_1)
#define modhlf ((integer *)&moduli_1 + 1)
#define lmrend ((logical *)&macseg_1 + 5)
#define issend ((logical *)&isscom_1 + 6)
#define isstrm ((integer *)&isscom_1 + 7)
#define issvbl ((integer *)&isscom_1 + 3)
#define canptr ((integer *)&canstr_1)
#define jumpto ((integer *)&doloop_1)
#define dojump ((integer *)&doloop_1 + 5)
#define estack ((integer *)&errpos_1 + 102)
#define ergstk ((integer *)&errpos_1 + 202)
#define nowarn ((logical *)&errpos_1)
    static logical opdflg;
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *), opcode_(integer *), argcvt_(integer *), rlslin_(void);
    static integer bigcnt;
    extern /* Subroutine */ int boolif_(integer *), onearg_(integer *);
    extern integer search_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int setmod_(integer *, integer *), concat_(char *,
	     char *, ftnlen, ftnlen), twoarg_(integer *, integer *), mcxtrn_(
	    integer *, integer *, integer *);
    static integer idummy, icount;
    extern /* Subroutine */ int labelz_(integer *), labcon_(integer *), 
	    puttmp_(integer *), resred_(void), subcod_(integer *);
    static integer ierror;
    extern /* Subroutine */ int holfrm_(integer *, char *, integer *, integer 
	    *, integer *, ftnlen), setchr_(integer *, integer *), callzz_(
	    integer *), arggen_(void), vctprd_(integer *), isscod_(void), 
	    replac_(void), macrec_(integer *), konast_(integer *), lcanon_(
	    integer *, integer *), larges_(integer *, integer *), recogn_(
	    integer *, integer *);
    static integer iasnrt;

    /* Fortran I/O blocks */
    static icilist io___128 = { 0, chrx_1.chr, 0, "(I3)", 400, 1 };
    static icilist io___148 = { 0, chrx_1.chr, 0, "(I3)", 400, 1 };




/*              FUNCTION DECLARATION */

/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* NUMBST:      NAMTBL INDEX OF BEGINNING OF NUMBER SECTION */
/* NUMBND:      NAMTBL INDEX OF END OF NUMBER SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* LPAREN:      (1)=CODE CLASS  2000,(2)=NAMTBL INDEX OF '(     ' */
/* RPAREN:      (1)=CODE CLASS  3000,(2)=NAMTBL INDEX OF ')     ' */
/* RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM ' */
/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* MINUS:       (1)=CODE CLASS  6000,(2)=NAMTBL INDEX OF '-     ' */
/* PLUS:        (1)=CODE CLASS  7000,(2)=NAMTBL INDEX OF '+     ' */
/* ASTER:       (1)=CODE CLASS  9000,(2)=NAMTBL INDEX OF '*     ' */
/* LETTER:      (1)=CODE CLASS 11000,(2)=NAMTBL INDEX OF 'LETTER' */
/* QUOTE:       (1)=CODE CLASS 12000,(2)=NAMTBL INDEX OF ''     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* DOLLAR:      (1)=CODE CLASS 15000,(2)=NAMTBL INDEX OF '$     ' */
/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* FCN:         (1)=CODE CLASS 18000,(2)=NAMTBL INDEX OF 'FCN   ' */
/* PROCED:      (1)=CODE CLASS 19000,(2)=NAMTBL INDEX OF 'PROCED' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* DECMAL:      (1)=CODE CLASS 21000,(2)=NAMTBL INDEX OF '.     ' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* LTERM:       (1)=CODE CLASS 24000,(2)=NAMTBL INDEX OF 'LTERM ' */
/* DOT:         (1)=CODE CLASS 25000,(2)=NAMTBL INDEX OF 'DOT   ' */
/* KREUZ:       (1)=CODE CLASS 26000,(2)=NAMTBL INDEX OF 'KREUZ ' */
/* RELAT:       (1)=CODE CLASS 27000,(2)=NAMTBL INDEX OF 'RELAT ' */
/* NOT:         (1)=CODE CLASS 28000,(2)=NAMTBL INDEX OF 'NOT   ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* DBLAST:      (1)=CODE CLASS 32000,(2)=NAMTBL INDEX OF 'DBLAST' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/* MCLTRM:      (1)=CODE CLASS 38000,(2)=NAMTBL INDEX OF 'MCLTRM' */
/* CONGEO:      (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO' */
/* CONPRO:      (1)=CODE CLASS 40000,(2)=NAMTBL INDEX OF 'CONPRO' */
/* CANON:       (1)=CODE CLASS 42000,(2)=NAMTBL INDEX OF 'CANON ' */
/* BIGGEO:      (1)=CODE CLASS 44000,(2)=DNAMTBL INDEX OF 'BIGGEO' */
/* CONAST:      (1)=CODE CLASS 45000,(2)=NAMTBL INDEX OF 'CONAST' */

/*        4.    PRODUCTION TABLE */

/* BRKPNT:      END OF MACRO TEXT TRANSFER PRODUCTION IN PRODTB */
/* MBKPNT:      END OF CHARACTER CONCATENATION AND STRING PRODUCTION */
/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */
/* PRODTB:      CONTAINS BASIC PRODUCTIONS */

/*        5.    PROGRAM CONTROL FLAGS */

/* ENDFLG:      TRUE WHEN SOURCE STATEMENT TOTALLY IN STACK */
/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTAC:       NAMTBL POINTER TO ALPHAMERIC LITERAL '.AC.' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONEPT:       NAMTBL POINTER TO '1.    ' */
/* TENPT:       NAMTBL POINTER TO '10.   ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       11.    SEQUENCE NUMBER STORAGE */




/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */
/* SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRRENT STATEMENT NUMBER */

/*       13.    NAMTBL POINTERS TO NEGATIVE NUMBERS */
/*              NAMTBL POINTER TO -1. */




/*       14.    I. L. LIST OPTION FLAGS */

/* INTERP:      NORMALLY TRUE,INDICATING INTERPRETIVE APPROACH DEFAULT */

/*       15.    ARRAY LIMIT STORAGE */

/* RNGPT:       POINTER TO NEXT RANGE ENTRY */
/* RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* FADD:        CONTAINS COMMAND CODE ( 1) FOR FADD COMMAND */
/* FSUB:        CONTAINS COMMAND CODE ( 2) FOR FSUB COMMAND */
/* FMPY:        CONTAINS COMMAND CODE ( 3) FOR FMPY COMMAND */
/* FDIV:        CONTAINS COMMAND CODE ( 4) FOR FDIV COMMAND */
/* FEXP:        CONTAINS COMMAND CODE ( 5) FOR FEXP COMMAND */
/* SEQNCE:      CONTAINS COMMAND CODE ( 9) FOR SEQNCE COMMAND */
/* CONJMP:      CONTAINS COMMAND CODE (11) FOR CONJMP COMMAND */
/* HOLDAT:      CONTAINS COMMAND CODE (21) FOR HOLDAT COMMAND */

/*       17.    MODE CODES */

/* TABCYL:      MODE CODE (11) FOR TABULATED CYLINDER */
/* POINT:       MODE CODE (19) FOR POINT */
/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* REAL:        MODE CODE (21) FOR A SCALAR */
/* BOOL:        MODE CODE (23) FOR BOOLEAN TYPE */
/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */
/* STRING:      MODE CODE (25) FOR STRING */
/* PATERN:      MODE CODE (26) FOR PATTERN */
/* BOUNDS:      MODE CODE (27) FOR BOUNDS */
/* OBJECT:      MODE CODE (28) FOR OBJECT */
/* SSURF:       MODE CODE (29) FOR SCULPTURED SURFACE */
/* SCURV:       MODE CODE (30) FOR SCULPTURED CURVE */

/*       18.    STRING STORAGE AREA */
/*              STORAGE OF INTERNAL REPRESENTATION OF STRING OR SYMBOL */
/* FIRST 3 BYTES CONTAIN CHARACTER REPRESENTATION OF NUMBER OF */
/* CHARACTERS IN STRING, REMAINING BYTES CONTAIN STRING */

/*       22.    MACRO PROCESSING VARIABLES */

/* MACLDD:      TRUE WHEN MACRO TEXT IS TO BE LOAD INTO MCBUFF TABLE */
/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* TEXTST:      POINTER TP MCBUFF OF MACRO TEXT WORD BEING PROCESSED */
/* MACRED:      SET TRUE TO INDICATE INPUT FROM MCBUFF TABLE */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* MAJWRD:      CONTAINS ACTUAL MAJOR WORD */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* MAJOR:       CURRENT CALL ASSIGNED VALUE IF MAYWRD IS MACRO VARIABLE */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */

/*       28.    OPERAND MODIFIERS */

/* UNDEF:       NAMTBL POINTER TO EXECUTION SUBROUTINE UNDEF */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* LMREND:      FLAG ON AFTER COMPLETION READING A SYSTEM MACRO */

/*       37.    INCLUSIVE SUBSCRIPT VARIABLES */

/* ISSA:        LOWEST SUBSCRIPT OF AN INCLUSIVE SUBSCRIPT STRING */
/* ISSB:        HIGHEST SUBSCRIPT OF AN INCLUSIVE SUBSCRIPT STRING */
/* ISSC:        INCREMENT OR DECREMENT FOR INCLUSIVE SUBSCRIPT STRING */
/* ISSVBL:      NAMTBL POINTER TO THE INCLUSIVE SUBSCRIPTED VARIABLE */
/* ISSFL:       TRUE DURING INCLUSIVE SUBSCRIPT PROCESSING */
/* ISSEND:      END OF INCLUSIVE SUBSCRIPT PROCESSING */
/* ISSTRM:      SAVES THE STACK TOP ITEMS DURING SUBSCRIPT PROCESSING */

/*       38.    COMMON BLOCK MACRO CALL STATEMENT */
/*              INDICATES A MACRO CALL BEING PROCESSED */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/*       42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE */

/* CANPTR:      POINTER TO LAST CANSTK ENTRY */

/*       43.    DO LOOP CONTROL VALUES */

/* JUMPTO:      MARKER SET AFTER JUMPTO OR IF FOR LABEL CONTROL */
/* RELDO:       CURRENTLY NESTED DO LOOPS */
/* DOJUMP:      VBL FOR COMPUTED GOTO AT LOOP PROCESSING */
/* DOFLAG:      FLAG IS ON DURING OPENED LOOP */
/* IFFLAG:      FLAG ON WHEN LOGICAL IF OCCURS */

/*       44.    ERROR POSITION TABLE */

/* NOWARN:      FLAG TRUE IS SUPPRESSING OUTPUT OF WARNING NR. 50 */
/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */

/*       45.    NUMBER TABLE INDICES */

/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* * */

/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

/*      IMPLEMENTATION DEPENDENT  NAME $21T$1                       ..CD. */

/* ** */
    s_copy(cseqcm_1.seqnum, iseq1, (ftnlen)6, (ftnlen)6);
    numblk_1.mnmbnd = nametb_1.numbst;
    numblk_1.numidx = nametb_1.numbst;
/*      PUT IMPLEMENTATION DEPENDENT NAME INTO NAMTBL              ..CD. */
    i__ = name_(icd21, (ftnlen)6);
    nametb_1.namtbl[i__ - 1] = temp[0] + *real__;
/*      PUT FIRST ITEM IN CANONICAL FORM BLOCK 3. */
    i__ = gettmp_(point);
/*      GENERATE I.L. TO STORE -1.0 IN PERMANENT LOCATION. */
/*        (USE OF TEMPORARY CAN CAUSE INCORRECT I.L.) */
/*        STORE NAMTBL POINTER TO LOCATION OF -1.0 IN NONEPT. */
    maclbl_(onept, &c__0, &negptr_1.nonept);
    nametb_1.namtbl[negptr_1.nonept - 1] = vbl[0] + *real__;
    resrvz_(&negptr_1.nonept, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1)
	    ;
    opcode_(fsub);
    argcvt_(&negptr_1.nonept);
    argcvt_(zeropt);
    argcvt_(onept);
    rlslin_();
/*  GENERATE IL TO RESERVE LOCATION FOR .AC. IN CANONICAL FORM BLOCK */
/*  TO OVERCOME IMPEMENTATION DEPENDENCY OF USE OF AC */
    resrvz_(dotac, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1);
    goto L11;

L1:
    if (! (*newstm)) {
	goto L20;
    }
/* ...  IF INTERP FALSE, TRANSLATION IS COMPLETE */
    if (! (*interp)) {
	return 0;
    }

/* ... SET LARGE SURFACE ARGUMENT COUNT = 0 */

L3:
    bigcnt = 0;
    ibr = 0;
    if (stack[(*top << 1) - 2] != rterm[1]) {
	goto L11;
    }
L5:
    if (*ifflag) {
	boolif_(&c__0);
    }
    opdflg = FALSE_;
    numblk_1.numidx = numblk_1.mnmbnd;
    numblk_1.nmbrs = 0;
    if (! (*doflag)) {
	goto L6;
    }
    *dojump = 3;
    loop_();
L6:
    if (! (*ilhlt)) {
	goto L10;
    }
    if (*intmed != 1) {
	goto L11;
    }
L10:
    ++seqcom_1.seqno;
    binbcd_(&seqcom_1.seqno, cseqcm_1.seqnum, top, (ftnlen)6);
    if (*macldd || *ilhlt) {
	goto L11;
    }
    opcode_(seqnce);
    onearg_(&seqcom_1.seqno);
    rlslin_();
    if (*jumpto != seqcom_1.seqno) {
	goto L11;
    }
    i__1 = seqcom_1.seqno - 1;
    binbcd_(&i__1, cseqcm_1.seqnum, top, (ftnlen)6);
    alarm_(&c__1009, &c__0, &c__4, "RECOG   ", (ftnlen)8);
    binbcd_(&seqcom_1.seqno, cseqcm_1.seqnum, top, (ftnlen)6);
    *jumpto = 0;
/* ...  NEW STATEMENT */

L11:
    *newstm = FALSE_;
    *top = 1;
    if (! (*macldd)) {
	goto L12;
    }
    stack[0] = mcltrm[1];
    l = mcltrm[0] / *modulo;
    bkpt = *mbkpnt;
    goto L13;
L12:
    stack[0] = lterm[1];
    l = lterm[0] / *modulo;
    bkpt = *brkpnt;

    for (i__ = 1; i__ <= 30; ++i__) {
/* L15: */
	tmp_1.txxxx[(i__ << 1) - 1] = 0;
    }
    *argtop = 0;
    *canptr = 0;
L13:
    stack[1] = meta[l - 1];
    goto L2900;
/* ...  FIND MATCHING PRODUCTION */
L20:
    if (! (*lmrend) && ! (*issfl) && ! (*issend)) {
	goto L21;
    }
    lbkpnt = bkpt;
    *issend = FALSE_;
    *lmrend = FALSE_;
L21:
    if (*macred) {
	lbkpnt = bkpt;
    }
L25:
    errp = *top;
    topt2 = *top << 1;
    i__ = search_(stack, &topt2, &prodtb[lbkpnt - 1], &errp);
    lbkpnt = 1;

    if (i__ > 50) {
	goto L50;
    }
    switch (i__) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L2950;
	case 13:  goto L1300;
	case 14:  goto L1450;
	case 15:  goto L1500;
	case 16:  goto L1600;
	case 17:  goto L1700;
	case 18:  goto L1800;
	case 19:  goto L1900;
	case 20:  goto L2000;
	case 21:  goto L2100;
	case 22:  goto L2200;
	case 23:  goto L2300;
	case 24:  goto L2400;
	case 25:  goto L2500;
	case 26:  goto L2600;
	case 27:  goto L2700;
	case 28:  goto L2800;
	case 29:  goto L2900;
	case 30:  goto L3000;
	case 31:  goto L3100;
	case 32:  goto L3200;
	case 33:  goto L3300;
	case 34:  goto L3400;
	case 35:  goto L3500;
	case 36:  goto L3600;
	case 37:  goto L3700;
	case 38:  goto L3700;
	case 39:  goto L3700;
	case 40:  goto L4000;
	case 41:  goto L5000;
	case 42:  goto L5000;
	case 43:  goto L5000;
	case 44:  goto L5000;
	case 45:  goto L5000;
	case 46:  goto L5000;
	case 47:  goto L5000;
	case 48:  goto L5000;
	case 49:  goto L5000;
	case 50:  goto L1200;
    }
L50:
    if (i__ < 70) {
	goto L5100;
    }
    j = i__ - 70;
    switch (j) {
	case 1:  goto L7100;
	case 2:  goto L3500;
	case 3:  goto L2000;
	case 4:  goto L2000;
	case 5:  goto L7500;
	case 6:  goto L7500;
	case 7:  goto L7500;
	case 8:  goto L7800;
    }
    goto L5200;

/*          SET I TO G */
L100:
    i__1 = *top - 1;
    setmod_(&i__1, geom);
    goto L220;
/*     IDENTIFIER TO PROCEDURE */
L200:
    i__1 = *top - 1;
    setmod_(&i__1, proced);
L220:
    lbkpnt = bkpt;
    goto L25;
/* ...       GENERATE CODE FOR STRING */

L300:
/* Writing concatenation */
    i__2[0] = 3, a__1[0] = zero;
    i__2[1] = 6, a__1[1] = blk;
    s_cat(chrx_1.chr, a__1, i__2, &c__2, (ftnlen)400);
L310:
    input_();
    i__ = stack[(*top << 1) - 2];
    if (i__ == quote[1]) {
	goto L320;
    }
    i__ = -i__;
    concat_(chrx_1.chr, cnamtb_1.cnamtb + (i__ - 1) * 6, (ftnlen)400, (ftnlen)
	    6);
    --(*top);
    goto L310;
L320:
    ++strcnt;
    i__1 = -strcnt;
    maclbl_(&quote[1], &i__1, &i__);
/*              ENTER STRING NAME IN NAMTBL */

/*              ENTER STRING NAME IN STACK */

    stack[(*top - 1 << 1) - 2] = i__;
    nametb_1.namtbl[i__ - 1] = vbl[0] + *string;
    l = vbl[0] / *modulo;
    stack[(*top - 1 << 1) - 1] = meta[l - 1];

/*              WRITE DATA STATEMENT */

    opcode_(holdat);
/* ... NUMBER OF CHARACTERS */
    s_rsfi(&io___128);
    do_fio(&c__1, (char *)&nchr, (ftnlen)sizeof(integer));
    e_rsfi();
    twoarg_(&i__, &nchr);
/* ... WRITE CHARACTER STRING TO IL , BY CONVERTING */
/*    IWRD CHARACTERS AT A TIME TO INTEGER FOR TRANSFER */
    if (nchr % sdp_1.iwrd != 0) {
	nchr = (nchr / sdp_1.iwrd + 1) * sdp_1.iwrd;
    }
    i__1 = nchr;
    i__3 = sdp_1.iwrd;
    for (j = 4; i__3 < 0 ? j >= i__1 : j <= i__1; j += i__3) {
	i__4 = bcdf_(chrx_1.chr + (j - 1), j + sdp_1.iwrd - 1 - (j - 1));
	onearg_(&i__4);
/* L303: */
    }
    rlslin_();
    --(*top);
    goto L2900;
/*     CHECK FOR CLDATA(N), OTHERWISE ERROR */
L400:
    j = stack[(*top - 4 << 1) - 2];
    k = nametb_1.namtbl[j - 1];
    l = k / *modulo;
    if (k - l * *modulo != cldata) {
	goto L420;
    }
    if (l == ident[0] / *modulo) {
	i__3 = *top - 4;
	setmod_(&i__3, permid);
    }
    l = comma[0] / *modulo;
    stack[(*top - 1 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top << 1) - 1];
    estack[*top - 2] = estack[*top - 1];
    stack[(*top - 3 << 1) - 2] = comma[1];
    stack[(*top - 3 << 1) - 1] = meta[l - 1];
    --(*top);
    goto L220;
L420:
    i__3 = *top - 4;
    alarm_(&c__1111, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    goto L2810;
/*     IMPLIED LABEL OR IDENTIFIER TO LABEL */
L500:
    *dojump = 2;
    if (*reldo > 0) {
	loop_();
    }
    k = stack[(*top - 1 << 1) - 2];
    if (k <= nametb_1.nammax) {
	goto L530;
    }
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    k -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &k, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (k - 1) * 12, &kk, &icount, (ftnlen)12);
    k = kk + 10000;
L505:
    i__3 = -(*whchmn);
    maclbl_(&k, &i__3, &k);
    stack[(*top - 1 << 1) - 2] = k;
    if (nametb_1.namtbl[k - 1] / *modulo == label[0] / *modulo) {
	goto L710;
    }
L506:
    if (! (*finmac) && *whchmn != 0) {
	goto L510;
    }
    nametb_1.namtbl[k - 1] = label[0] + *whchmn;
    l = label[0] / *modulo;
L507:
    stack[(*top - 1 << 1) - 1] = meta[l - 1];
    labelz_(&k);
    i__3 = -k;
    labcon_(&i__3);
/*     ERASE FROM STACK */
L520:
    *top += -2;
    goto L2900;
L530:
    if (*whchmn == 0) {
	goto L506;
    }
    if (nametb_1.namtbl[k - 1] / *modulo != label[0] / *modulo) {
	nametb_1.namtbl[k - 1] = implab[0];
    }
    goto L505;
L510:
    nametb_1.namtbl[k - 1] = implab[0] + *whchmn;
    l = implab[0] / *modulo;
    goto L507;
L600:
    if (*jumpto != 0) {
	*jumpto = seqcom_1.seqno + 2;
    }
    goto L5;
L700:
    if (*whchmn != 0) {
	goto L500;
    }
L710:
    i__3 = *top - 1;
    alarm_(&c__1003, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    goto L520;
/* ...       BINARY OPERATION GENERATIR */
L800:
    *arg1 = stack[(*top - 3 << 1) - 2];
    *arg2 = stack[(*top - 1 << 1) - 2];
    op = stack[(*top - 2 << 1) - 2];
    for (l = 1; l <= 2; ++l) {
	j = mode_(&argx[l - 1]);
	if (j == *real__) {
	    goto L810;
	}
	k = (l << 1) - 5;
	i__3 = *top + k;
	alarm_(&c__1004, &i__3, &c__8, "RECOG   ", (ftnlen)8);
L810:
	if (iftmp_(&argx[l - 1])) {
	    puttmp_(&j);
	}
    }
    rslt = gettmp_(real__);
    if (nametb_1.namtbl[op - 1] != slash[0]) {
	goto L801;
    }
    opcode_(fdiv);
    goto L850;
L801:
    if (nametb_1.namtbl[op - 1] != minus[0]) {
	goto L802;
    }
    opcode_(fsub);
    goto L850;
L802:
    if (nametb_1.namtbl[op - 1] != plus[0]) {
	goto L803;
    }
    opcode_(fadd);
    goto L850;
L803:
    if (nametb_1.namtbl[op - 1] != aster[0]) {
	goto L804;
    }
    opcode_(fmpy);
    goto L850;
L804:
    opcode_(fexp);
L850:
    argcvt_(&rslt);
    argcvt_(arg1);
    argcvt_(arg2);
    rlslin_();
    stack[(*top - 3 << 1) - 2] = rslt;
    l = nametb_1.namtbl[rslt - 1] / *modulo;
    stack[(*top - 3 << 1) - 1] = meta[l - 1];
L860:
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    estack[*top - 3] = estack[*top - 1];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    goto L220;
/* ...       INITIALIZE STRING, THEN READ */
L900:
    i__ = stack[(*top << 1) - 2];
/* Writing concatenation */
    i__2[0] = 3, a__1[0] = zero;
    i__2[1] = 6, a__1[1] = blk;
    s_cat(chrx_1.chr, a__1, i__2, &c__2, (ftnlen)400);
    concat_(chrx_1.chr, cnamtb_1.cnamtb + (i__ - 1) * 6, (ftnlen)400, (ftnlen)
	    6);
    goto L2900;

/* ...     SUBSCRIPT ON RIGHT */
L1000:
    if (*issfl) {
	goto L1030;
    }
    i__ = stack[(*top - 2 << 1) - 2];
    if (i__ > nametb_1.nammax) {
	j = number[0] / *modulo;
    } else {
	j = nametb_1.namtbl[i__ - 1] / *modulo;
    }
    if (*argtop > 0) {
	goto L1050;
    }
    if (i__ > nametb_1.nammax) {
	goto L1030;
    }
    if (j == ident[0] / *modulo || j == permid[0] / *modulo) {
	goto L1050;
    }
/*    LIEGT EIN   READ-BEFEHL VOR ? */
L1030:
    if (stack[2] <= nametb_1.nammax) {
	if (nametb_1.namtbl[stack[2] - 1] == 19057) {
	    resred_();
	}
    }
    i__3 = *top - 4;
    subcod_(&i__3);
/*        MODIFY STACK */
L1010:
    stack[(*top - 3 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 3 << 1) - 1] = stack[(*top << 1) - 1];
    estack[*top - 4] = estack[*top - 1];
    *top += -3;
    goto L220;

/* ...     CHECK FOR INCLUSIVE SUBSCRIPT FORMAT */

L1050:
    if (j == ident[0] / *modulo) {
	i__3 = *top - 2;
	setmod_(&i__3, permid);
    }
/*        PLACE BIT PATTERNS IN TOP OF STACK FOR SEARCH */
    ++(*argtop);
    argstk[*argtop - 1] = stack[(*top - 2 << 1) - 2];
    ergstk[*argtop - 1] = estack[*top - 3];
    k = *top + 1;
    n5 = *top;
    stack[(k << 1) - 1] = -1;
    atp = 1;
    if (*argtop > 5) {
	atp = *argtop - 4;
    }
    i__3 = *argtop;
    for (i__ = atp; i__ <= i__3; ++i__) {
	++k;
	l = argstk[i__ - 1];
	if (l <= nametb_1.nammax) {
	    goto L1052;
	}
	iarg = *real__;
	goto L1058;
L1052:
	m = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
	iarg = nametb_1.namtbl[l - 1] - m;
	if (iarg >= *modhlf) {
	    iarg -= *modhlf;
	}
	if (iarg == 0) {
	    goto L1092;
	}
	if (m == vbl[0] || m == temp[0]) {
	    goto L1058;
	}
	if (m == permid[0]) {
	    goto L1056;
	}
	if (m != number[0]) {
	    goto L1092;
	}
	iarg = *real__;
	goto L1058;
L1056:
	iarg += 50;
L1058:
	stack[(k << 1) - 1] = gmty_1.pmidtb[iarg - 1];
/* L1060: */
    }
/*        SEARCH SUBSCR PRODUCTIONS */
    l = gmty_1.geoloc[*subscr - 1];
    errp = *argtop;
    kt2 = k << 1;
    i__ = search_(stack, &kt2, &gmty_1.geomtb[l - 1], &errp);
    if (i__ == 200) {
	goto L1090;
    }
    if (errp >= atp) {
	goto L1091;
    }
    *issc = 1;
    j = 1;
    if (i__ < 6) {
	goto L1070;
    }
    ii = argstk[atp - 1];
    i__ += -5;
L1062:
    if (ii <= nametb_1.nammax) {
	goto L1094;
    }
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    ii -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &ii, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (ii - 1) * 12, &iii, &idummy, (ftnlen)12);
    switch (j) {
	case 1:  goto L1068;
	case 2:  goto L1080;
	case 3:  goto L1085;
    }

/*        PREPARE AND STORE ISSC */
L1068:
    *issc = iii;
L1070:
    k = argstk[atp];
    if (k <= nametb_1.nammax) {
	if (nametb_1.namtbl[k - 1] - nametb_1.namtbl[k - 1] / *modhlf * *
		modhlf == 60) {
	    *issc = -(*issc);
	}
    }
/*        PREPARE AND STORE ISSB */
    j = 2;
    if (i__ != 3 && i__ != 5) {
	goto L1072;
    }
    ii = argstk[*argtop - i__ / 2 - 1];
    goto L1062;
L1072:
    if (*rngpt == 1) {
	goto L1096;
    }
    ii = stack[(*top - 4 << 1) - 2];
    iii = *rngpt - 2;
    i__3 = iii;
    for (m = 1; m <= i__3; m += 2) {
	if (range[m - 1] == ii) {
	    goto L1076;
	}
/* L1075: */
    }
    goto L1096;
L1076:
    *issb = range[m];
    goto L1082;
L1080:
    *issb = iii;

/*        PREPARE AND STORE ISSA */
L1082:
    j = 3;
    *issa = 1;
    if (i__ < 4) {
	goto L1084;
    }
    ii = argstk[*argtop - 1];
    goto L1062;
L1085:
    *issa = iii;

L1084:
    if ((*issb - *issa) * *issc > 0) {
	goto L1086;
    }
    ii = *issb;
    *issb = *issa;
    *issa = ii;
/*        PLACE ISSA IN STACK AND SET FLAG, ETC. IF STRING CONTAINS */
/*          MORE THAN ONE ITEM */
L1086:
    if (*issa != 1) {
	goto L1088;
    }
    stack[(*top - 2 << 1) - 2] = *onept;
    goto L1089;
L1088:
    s_copy(iichr, blk, (ftnlen)20, (ftnlen)6);
    binbcd_(issa, iichr, &k, (ftnlen)20);
    i__3 = k;
    s_copy(iichr + i__3, ".", k + 1 - i__3, (ftnlen)1);

    i__ = numb_(iichr, k + 1);
/* ....ADD OFFSET OF NAMMAX TO CNUMTB ADDRESS FOR COMPATIBILITY */
/* ....WITH PREVIOUS METHOD OF STORING NUMBERS IN NAMTBL */
    stack[(*top - 2 << 1) - 2] = i__ + nametb_1.nammax;
L1089:
    ii = number[0] / *modulo;
    *argtop = atp - 1;
    stack[(*top - 2 << 1) - 1] = meta[ii - 1];
    *issa += *issc;
    if (*issc <= 0 && (*issa < *issb || *issc > -1)) {
	goto L1030;
    }
    if (*issc >= 0 && (*issa > *issb || *issc < 1)) {
	goto L1030;
    }
    *issvbl = stack[(*top - 4 << 1) - 2];
    isstrm[0] = stack[(*top << 1) - 2];
    isstrm[1] = stack[(*top << 1) - 1];
    stack[(*top << 1) - 2] = comma[1];
    ii = comma[0] / *modulo;
    stack[(*top << 1) - 1] = meta[ii - 1];
    *issfl = TRUE_;
    goto L1030;

/*     'FALSCHE INDIZIERUNGSANGABE' */
L1090:
    if (errp == atp) {
	errp = atp;
    }
    goto L1091;
L1092:
    errp = i__;
L1091:
    ierror = 2053;
    if (errp == *argtop) {
	goto L1097;
    }
    goto L1095;
/*     'UNZULAESSIGE SYMBOLISCHE ZAHLANGABE' */
L1094:
    ierror = 2054;
    if (j == 3) {
	goto L1097;
    }
    errp = atp;
    if (j == 2) {
	errp = *argtop - i__ / 2;
    }
L1095:
    *top += -2;
    --(*argtop);
    goto L1098;
L1097:
    errp = 2 - *top;
    goto L1098;
/*     'VARIABLE NICHT RESERVIERT' */
L1096:
    ierror = 1013;
    errp = 4 - *top;
L1098:
    i__3 = -errp;
    alarm_(&ierror, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    *top = n5;
    goto L2810;

/* ...     SUBSCRIPT ON LEFT */
/*          DOES LEFT SIDE HAVE MODE */

L1100:
    ii = mode_(&stack[(*top - 1 << 1) - 2]);
L1101:
    if (mode_(&stack[(*top - 6 << 1) - 2]) != 0) {
	goto L1130;
    }
    i__ = stack[(*top - 6 << 1) - 2];
    nametb_1.namtbl[i__ - 1] += ii;

/*     FIND ARRAY LENGTH IN RANGE */
    iii = 1;
L1110:
    if (iii >= *rngpt) {
	goto L1130;
    }
    if (range[iii - 1] == stack[(*top - 6 << 1) - 2]) {
	goto L1120;
    }
    iii += 2;
    goto L1110;

/*     RESERVE STORAGE */
L1120:
    resrvz_(&i__, &ii, &tmp_1.txxxx[(ii << 1) - 2], &range[iii]);


L1130:
    if (ii == *bounds || ii == *object) {
	goto L1805;
    }
    i__3 = *top - 6;
    subcod_(&i__3);

/*     MODIFY STACK */
    stack[(*top - 5 << 1) - 2] = stack[(*top - 2 << 1) - 2];
    stack[(*top - 5 << 1) - 1] = stack[(*top - 2 << 1) - 1];
    estack[*top - 6] = estack[*top - 3];
    stack[(*top - 4 << 1) - 2] = stack[(*top - 1 << 1) - 2];
    stack[(*top - 4 << 1) - 1] = stack[(*top - 1 << 1) - 1];
    estack[*top - 5] = estack[*top - 2];
    goto L1010;

L1200:
    k = stack[(*top - 1 << 1) - 2];
    if (s_cmp(cnamtb_1.cnamtb + (k - 1) * 6, on, (ftnlen)6, (ftnlen)6) != 0) {
	goto L1210;
    }
    *nowarn = TRUE_;
    goto L1220;
L1210:
    if (s_cmp(cnamtb_1.cnamtb + (k - 1) * 6, off, (ftnlen)6, (ftnlen)6) != 0) 
	    {
	goto L1230;
    }
    *nowarn = FALSE_;
L1220:
    if (k <= nametb_1.nammax) {
	if (nametb_1.namtbl[k - 1] / *modulo == ident[0] / *modulo) {
	    i__3 = *top - 1;
	    setmod_(&i__3, permid);
	}
    }
    goto L5;
L1230:
    i__3 = *top - 1;
    alarm_(&c__1008, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    goto L5;

L1300:
    if (stack[(*top - 2 << 1) - 2] <= nametb_1.nammax) {
	if (nametb_1.namtbl[stack[(*top - 2 << 1) - 2] - 1] == minus[0]) {
	    goto L1400;
	}
    }
/*     UNARY PLUS */
    stack[(*top - 2 << 1) - 2] = stack[(*top - 1 << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top - 1 << 1) - 1];
    estack[*top - 3] = estack[*top - 2];

    goto L1420;
/* ...       UNARY MINUS */
L1400:
    arg = stack[(*top - 1 << 1) - 2];
    j = mode_(&arg);
    if (j == *real__) {
	goto L1410;
    }
    i__3 = *top - 1;
    alarm_(&c__1005, &i__3, &c__8, "RECOG   ", (ftnlen)8);
L1410:
    if (iftmp_(&arg)) {
	puttmp_(&j);
    }
    rslt = gettmp_(real__);
    opcode_(fsub);
    argcvt_(&rslt);
    argcvt_(zeropt);
    argcvt_(&arg);
    rlslin_();
    stack[(*top - 2 << 1) - 2] = rslt;
    l = temp[0] / *modulo;
    stack[(*top - 2 << 1) - 1] = meta[l - 1];
L1420:
    stack[(*top - 1 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top << 1) - 1];
    estack[*top - 2] = estack[*top - 1];
    --(*top);
    goto L220;
/* ... */
L1450:
    if (stack[(*top << 1) - 2] != nametb_1.numbst + nametb_1.nammax) {
	goto L2900;
    }
    k = numblk_1.numidx + 1;
    if (k > nametb_1.numbnd) {
	goto L1480;
    }
    numblk_1.numidx = k;
L1460:
    for (j = 1; j <= 3; ++j) {
	++(*textst);
	mcxtrn_(&c__2, textst, &icnum[j - 1]);
/* L1470: */
    }
    holfrm_(icnum, cnamtb_1.cnumtb + (k - 1) * 12, &c__1, &c__12, &nwd, (
	    ftnlen)12);
/* ... INCREMENT FOR NUMBER TABLE ADDRESS */
    stack[(*top << 1) - 2] = k + nametb_1.nammax;
    goto L2900;
L1480:
    i__3 = nametb_1.numbnd;
    for (j = numblk_1.mnmbnd; j <= i__3; ++j) {
	--k;
	if (s_cmp(cnamtb_1.cnumtb + (k - 1) * 12, " ", (ftnlen)12, (ftnlen)1) 
		== 0) {
	    goto L1460;
	}
/* L1490: */
    }
    k = nametb_1.numbnd;
    goto L1460;
/* ...       VECTOR PRODUCTS */
L1500:
    input_();
    input_();
    if (*endflg && stack[(*top - 1 << 1) - 2] != dollar[1]) {
	goto L3;
    }
    if (stack[(*top << 1) - 2] == rparen[1]) {
	goto L1530;
    }
L1510:
    inptr_1.cnt += -2;
L1520:
    *top += -2;
    goto L3215;
L1530:
    if (stack[(*top - 1 << 1) - 2] != aster[1]) {
	goto L1550;
    }
    i__3 = *top - 2;
    setchr_(&i__3, kreuz);
    goto L1520;
L1550:
    if (stack[(*top - 1 << 1) - 2] != decmal[1]) {
	goto L1510;
    }
    i__3 = *top - 2;
    setchr_(&i__3, dot);
    goto L1520;
/* ...       ARGUMENT LIST */
L1600:
    k = stack[(*top - 1 << 1) - 2];
    ++(*argtop);
    argstk[*argtop - 1] = k;
    ergstk[*argtop - 1] = estack[*top - 2];
    if (k > nametb_1.nammax) {
	goto L860;
    }
    if (iftmp_(&k)) {
	i__3 = mode_(&k);
	puttmp_(&i__3);
    }
    j = nametb_1.namtbl[k - 1] / *modulo;
    if (j == ident[0] / *modulo) {
	i__3 = *top - 1;
	setmod_(&i__3, permid);
    }
    goto L860;
/* ...       FUNCTION CALL GENERATOR */
L1700:
    ++(*argtop);
    i__ = stack[(*top - 1 << 1) - 2];
    argstk[*argtop - 1] = i__;
    if (iftmp_(&i__)) {
	i__3 = mode_(&i__);
	puttmp_(&i__3);
    }
    j = gettmp_(real__);
    *major = stack[(*top - 3 << 1) - 2];
    if (*intmed != 1) {
	goto L1703;
    }
    *way = 3;
    if (*finmac) {
	goto L1702;
    }
    *majwrd = *major;
L1701:
    ergstk[99] = *top - 3;
    match_();
    if (! (*entry__)) {
	goto L1705;
    }
    if (*major <= nametb_1.nammax) {
	goto L1706;
    }
    i__3 = *top - 3;
    alarm_(&c__2025, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    goto L1703;
L1706:
    if (nametb_1.namtbl[*major - 1] / *modulo != fcn[0] / *modulo) {
	i__3 = *top - 3;
	alarm_(&c__2025, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    }
    goto L1703;
L1702:
    path_();
    if (! (*should)) {
	goto L1705;
    }
L1703:
    callzz_(major);
    argcvt_(&j);
    arggen_();
    rlslin_();
    if (*entry__) {
	goto L1701;
    }
L1705:
    stack[(*top - 3 << 1) - 2] = j;
    l = temp[0] / *modulo;
    stack[(*top - 3 << 1) - 1] = meta[l - 1];
    *argtop = 0;
    *top += -3;
    vctprd_(&l);
    if (l == 1) {
	goto L2900;
    }
    goto L220;
/*     STACK ARGUMENT */
L1800:
    ii = stack[(*top - 1 << 1) - 2];
    ii = nametb_1.namtbl[ii - 1] % *modulo;
    if (ii >= *modhlf) {
	ii -= *modhlf;
    }
    goto L1101;

/* ...  ERROR 1029:  'BOUNDED GEOMETRY MUST NOT BE SUBSCRIPTED.  STATE- */
/*                   MENT IGNORED.' */

L1805:
    i__3 = *top - 4;
    alarm_(&c__1029, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    callzz_(undef);
    argcvt_(&stack[(*top - 6 << 1) - 2]);
    rlslin_();
    goto L2810;
/* ...       SCAN PAST RIGHT TERMINATOR */
L1900:
    input_();
    if (stack[(*top << 1) - 2] == rterm[1]) {
	goto L520;
    }
    --(*top);
    goto L1900;
/*     REMOVE PARENTHESIS */

L2100:
    stack[(*top - 2 << 1) - 2] = stack[(*top - 1 << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top - 1 << 1) - 1];
    estack[*top - 3] = estack[*top - 2];
    *top += -2;
    goto L2900;

/* ...       CONCATINATE TOP TO STRING, SET STACK TO 'LTR' */
L2200:
    i__3 = *top - 1;
    setchr_(&i__3, letter);
L2500:
    k = stack[(*top << 1) - 2];
L2510:
    concat_(chrx_1.chr, cnamtb_1.cnamtb + (k - 1) * 6, (ftnlen)400, (ftnlen)6)
	    ;
    numblk_1.lstchr = stack[(*top << 1) - 2];
    --(*top);
    input_();
    goto L25;
L2900:
    input_();
    if (stack[(*top << 1) - 2] > nametb_1.nammax) {
	goto L1;
    }
    if (nametb_1.namtbl[stack[(*top << 1) - 2] - 1] != mcltrm[0]) {
	goto L1;
    }
    bkpt = *mbkpnt;
    goto L1;
L2950:
    if (! (*issfl)) {
	goto L2900;
    }
    isscod_();
    goto L20;
/* ...       NESTED ASSIGNMENT */
L2300:
    if (mode_(&stack[(*top - 1 << 1) - 2]) == *bool) {
	boolif_(&c__5);
    }
    replac_();
    goto L860;
/* ...       ASSIGNMENT STATEMENT */
L2400:
    if (mode_(&stack[(*top - 1 << 1) - 2]) == *bool) {
	boolif_(&c__5);
    }
    replac_();
    goto L5;
L2600:
    pro026_();
    goto L1;
L2700:
    *dojump = 1;
    loop_();
    goto L6;
/*     STACK ARGUMENT */
L2800:
    alarm_(&c__1007, &errp, &c__8, "RECOG   ", (ftnlen)8);
    if (calflg_1.icallf == 1) {
	macrec_(&c__12);
    }
L2810:
    bigcnt = 0;
    ibr = 0;
    if (stack[(*top << 1) - 2] == rterm[1]) {
	goto L5;
    }
    *top = 99;
    input_();
    goto L5;

/* ...       IS MODE OF JUMP VARIABLE 'REAL' */

L3000:
    if (*argtop > 0) {
	i__3 = -(*argtop);
	alarm_(&c__2052, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    }
    k = stack[(*top - 7 << 1) - 2];
    l = mode_(&k);
    if (l != *real__) {
	i__3 = *top - 7;
	alarm_(&c__1008, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    }
    if (iftmp_(&k)) {
	puttmp_(&l);
    }
    opcode_(conjmp);

/* ...       VARIABLE */

    argcvt_(&k);

/* ...   LABELS */

    for (i__ = 1; i__ <= 5; i__ += 2) {
	k = *top - 6 + i__;
	k = stack[(k << 1) - 2];
	if (k > nametb_1.nammax) {
	    goto L3004;
	}
	j = *modulo * (nametb_1.namtbl[k - 1] / *modulo);
	if (j != label[0] && j != implab[0]) {
	    nametb_1.namtbl[k - 1] = implab[0];
	}
	if (*whchmn == 0) {
	    goto L3002;
	}
	goto L3003;
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L3004:
	k -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, &k, &idummy);
	}
	bcdbin_(cnamtb_1.cnumtb + (k - 1) * 12, &kk, &icount, (ftnlen)12);
	k = kk + 10000;
L3003:
	i__3 = -(*whchmn);
	maclbl_(&k, &i__3, &k);
	if (nametb_1.namtbl[k - 1] == 0) {
	    nametb_1.namtbl[k - 1] = implab[0] + *whchmn;
	}
L3002:
	labcon_(&k);
/* L3001: */
	onearg_(&k);
    }
    rlslin_();
    goto L6;

L3200:
    input_();
    if (*endflg) {
	goto L3;
    }
    errp = *top - 1;
    if (stack[(*top << 1) - 2] != aster[1]) {
	goto L3210;
    }
/*                  **  TO  'DBLAST' */
    *top = errp;
    setchr_(top, dblast);
    goto L25;
L3210:
    *top = errp;
    --inptr_1.cnt;
L3215:
    lbkpnt = *mbkpnt - 6;
    goto L25;
/*           VECTOR PRODUCT (STACK PREPARATION) */
L3300:
    if (stack[(*top - 2 << 1) - 2] <= nametb_1.nammax) {
	if (nametb_1.namtbl[stack[(*top - 2 << 1) - 2] - 1] == dot[0]) {
	    goto L3320;
	}
    }
    for (j = 1; j <= 3; j += 2) {
	if (stack[(*top - j << 1) - 2] <= nametb_1.nammax) {
	    if (nametb_1.namtbl[stack[(*top - j << 1) - 2] - 1] % *modhlf != *
		    vector) {
		goto L3330;
	    }
	}
/* L3310: */
    }
L3320:
    i__ = -1;
    vctprd_(&i__);
    goto L220;
L3330:
    i__3 = *top - j;
    alarm_(&c__1008, &i__3, &c__8, "RECOG   ", (ftnlen)8);
    goto L2810;

/* ...       ENTER DIGIT STRING IN NAME TABLE */
L3400:
    concat_(chrx_1.chr, ".", (ftnlen)400, (ftnlen)1);
    numblk_1.lstchr = numblk_1.numidx;
L2000:
    s_copy(iichr, chrx_1.chr + 3, (ftnlen)20, (ftnlen)12);
    k = i__;
    i__ = numb_(iichr, (ftnlen)20);
/* L3405: */
    l = number[0] / *modulo;
/* ....ADD OFFSET OF NAMMAX TO CNUMTB ADDRESS FOR COMPATIBILITY */
/* ....WITH PREVIOUS METHOD OF STORING NUMBERS IN NAMTBL */
    i__ += nametb_1.nammax;
L3410:
    stack[(*top - 1 << 1) - 2] = i__;
    stack[(*top - 1 << 1) - 1] = meta[l - 1];
    errp = *top - 1;
    if (k < 70) {
	goto L220;
    }
    if ((i__3 = k - 73) < 0) {
	goto L7200;
    } else if (i__3 == 0) {
	goto L7300;
    } else {
	goto L7400;
    }
L3500:
    l = ident[0];
    k = i__;
    s_rsfi(&io___148);
    do_fio(&c__1, (char *)&nchr, (ftnlen)sizeof(integer));
    e_rsfi();
    if (nchr > 6) {
	i__3 = *top - 1;
	alarm_(&c__16, &i__3, &c__4, "RECOG   ", (ftnlen)8);
    }
    s_copy(iichr, chrx_1.chr + 3, (ftnlen)20, nchr);
    i__ = name_(iichr, (ftnlen)20);
    if (nametb_1.namtbl[i__ - 1] == 0) {
	nametb_1.namtbl[i__ - 1] = l;
    }
    l = nametb_1.namtbl[i__ - 1] / *modulo;
    goto L3410;
/* ...       SET PERIOD AND CONCATINATE TOP TO DIGIT STRING */
L3600:
    i__3 = *top - 1;
    setchr_(&i__3, number);
    goto L2500;
L3700:
    pro020_(&i__);
    if (i__ != 38) {
	goto L2900;
    }
    goto L1;

L4000:
    konast_(tenpt);
    goto L220;

/* ...  MACRO PROCESSING */

L5100:
    j = i__ - 50;
    if (j == 9) {
	labcon_(&c__0);
    }
    macrec_(&j);
    switch (j) {
	case 1:  goto L220;
	case 2:  goto L220;
	case 3:  goto L1;
	case 4:  goto L1;
	case 5:  goto L2900;
	case 6:  goto L1;
	case 7:  goto L5110;
	case 8:  goto L1;
	case 9:  goto L5110;
	case 10:  goto L2900;
	case 11:  goto L1;
    }
L5110:
    *dojump = j - 3;
    loop_();
    goto L1;

/* ... LARGE SURFACE PRODUCTIONS  **************************************** */
/* ... IF ACTION NUMBER EQUALS 101, CHANGE STACK FROM CONBIG / TO */
/* ... BIGGEO /. */
/* ... IF ACTION NUMBER IS NOT EQUAL TO 101, ADD 1 TO LARGE SURFACE */
/* ... ARGUMENT COUNT AND CALL LCANON, LARGES OR INPAT */

L5200:
    if (i__ != 101) {
	goto L5210;
    }
    i__3 = *top - 1;
    setmod_(&i__3, biggeo);
    goto L5205;

L5210:
    ++bigcnt;
    if (ibr != 0) {
	goto L5250;
    }

    n3 = stack[(*top - 3 << 1) - 2];
    if (n3 > nametb_1.nammax) {
	goto L5240;
    }
    if (nametb_1.namtbl[n3 - 1] != canon[0]) {
	goto L5240;
    }
    ibr = 1;
    goto L5250;
L5240:
    n5 = stack[(*top - 5 << 1) - 2];
    m5 = nametb_1.namtbl[n5 - 1] - biggeo[0];
    if (m5 >= *modhlf) {
	m5 -= *modhlf;
    }
    if (m5 != *tabcyl) {
	goto L5245;
    }
    ibr = 2;
    goto L5250;
L5245:
    if (m5 != *patern) {
	goto L5248;
    }
    ibr = 3;
    goto L5250;
L5248:
    errp = *top - 5;
    if (m5 != *ssurf && m5 != *scurv) {
	goto L2800;
    }
    ibr = 4;

L5250:
    switch (ibr) {
	case 1:  goto L5255;
	case 2:  goto L5270;
	case 3:  goto L5280;
	case 4:  goto L5290;
    }
L5255:
    lcanon_(&i__, &bigcnt);
    goto L5205;
L5270:
    larges_(&i__, &bigcnt);
    goto L5205;
L5280:
    inpat_(&i__, &bigcnt);
    goto L5205;
L5290:
    ssdef_(&i__, &bigcnt);

/* ... START PRODUCTION SEARCH AT BRKPNT IF CALLED FOR BY PREVIOUS */
/* ... PRODUCTION. IF PREVIOUS PRODUCTION RESULTED IN A NULL STACK, SET */
/* ... NEW STATEMENT FLAG EQUAL TO .TRUE.  IF PREVIOUS PRODUCTION CALLED */
/* ... FOR A NEW CHARACTER TO BE ADDED TO THE STACK, CALL INPUT. */


L5205:
    if (i__ <= 102) {
	lbkpnt = bkpt;
    }
    i__ += -100;
    switch (i__) {
	case 1:  goto L25;
	case 2:  goto L1;
	case 3:  goto L3;
	case 4:  goto L5220;
	case 5:  goto L5220;
    }
L5220:
    input_();
    goto L1;

L5000:
    recogn_(&i__, &iasnrt);
    switch (iasnrt) {
	case 1:  goto L25;
	case 2:  goto L220;
	case 3:  goto L600;
	case 4:  goto L1000;
	case 5:  goto L2900;
    }

L3100:
    pro027_(&c__5);
    goto L5;

L7100:
    stack[(*top - 1 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top << 1) - 1];
    estack[*top - 2] = estack[*top - 1];
    opdflg = TRUE_;
    goto L2500;

L7200:
    if (nametb_1.namtbl[i__ - 1] != relat[0]) {
	goto L7210;
    }
    *top += 2;
    stack[(*top - 1 << 1) - 2] = *zeropt;
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, true__, (ftnlen)6, (ftnlen)6) 
	    == 0) {
	stack[(*top - 1 << 1) - 2] = *onept;
    }
    nametb_1.namtbl[i__ - 1] = ident[0];
    replac_();
    nametb_1.namtbl[i__ - 1] = vbl[0] + *bool;
    *top += -3;
    goto L2900;
L7210:
    if (opdflg) {
	goto L7230;
    }
L7215:
    --inptr_1.cnt;
L7220:
    --(*top);
    goto L220;

L7230:
    opdflg = FALSE_;
    if (l > 26 && l < 31) {
	goto L7220;
    }
    if (stack[(*top << 1) - 2] <= nametb_1.nammax) {
	if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, true__, (ftnlen)6, (ftnlen)
		6) == 0 || s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, false__, (
		ftnlen)6, (ftnlen)6) == 0) {
	    goto L7220;
	}
    }
    if (*macldd) {
	goto L7215;
    }
    errp = *top;
    goto L2800;

L7300:
    if (*macldd) {
	goto L7215;
    }
    goto L900;

L7400:
    input_();
    if (stack[(*top << 1) - 2] <= nametb_1.nammax) {
	if (nametb_1.namtbl[stack[(*top << 1) - 2] - 1] == letter[0]) {
	    goto L7420;
	}
	if (s_cmp(cnamtb_1.cnamtb + (stack[(*top - 1 << 1) - 2] - 1) * 6, 
		"E   ", (ftnlen)6, (ftnlen)4) != 0 && s_cmp(cnamtb_1.cnamtb + 
		(stack[(*top - 1 << 1) - 2] - 1) * 6, "D   ", (ftnlen)6, (
		ftnlen)4) != 0) {
	    goto L7420;
	}
    }
    i__3 = *top - 1;
    setchr_(&i__3, conast);
    goto L7215;
L7420:
/* Writing concatenation */
    i__2[0] = 3, a__1[0] = zero;
    i__2[1] = 6, a__1[1] = blk;
    s_cat(chrx_1.chr, a__1, i__2, &c__2, (ftnlen)400);
    concat_(chrx_1.chr, ".", (ftnlen)400, (ftnlen)1);
    --inptr_1.cnt;
    k = stack[(*top - 1 << 1) - 2];
    opdflg = TRUE_;
    goto L2510;

L7800:
    if (stack[(*top - 1 << 1) - 2] <= nametb_1.nammax) {
	if (nametb_1.namtbl[stack[(*top - 1 << 1) - 2] - 1] % *modhlf != *
		bool) {
	    goto L2900;
	}
    }
L7500:
    j = i__ - 74;
    boolif_(&j);
    if (*top < 0) {
	goto L2810;
    } else if (*top == 0) {
	goto L11;
    } else {
	goto L220;
    }

} /* recog_ */

#undef nowarn
#undef ergstk
#undef estack
#undef dojump
#undef jumpto
#undef canptr
#undef issvbl
#undef isstrm
#undef issend
#undef lmrend
#undef modhlf
#undef modulo
#undef whchmn
#undef majwrd
#undef intmed
#undef textst
#undef should
#undef bounds
#undef patern
#undef string
#undef subscr
#undef zeropt
#undef vector
#undef tabcyl
#undef conjmp
#undef seqnce
#undef newstm
#undef interp
#undef mbkpnt
#undef brkpnt
#undef prodtb
#undef conpro
#undef conast
#undef letter
#undef mcltrm
#undef argtop
#undef argstk
#undef rparen
#undef number
#undef lparen
#undef permid
#undef dollar
#undef proced
#undef holdat
#undef congeo
#undef dblast
#undef object
#undef implab
#undef endflg
#undef doflag
#undef finmac
#undef biggeo
#undef macred
#undef ifflag
#undef decmal
#undef macldd
#undef scurv
#undef ssurf
#undef entry__
#undef kreuz
#undef point
#undef quote
#undef rngpt
#undef minus
#undef tenpt
#undef rterm
#undef onept
#undef lterm
#undef nlast
#undef issfl
#undef aster
#undef ilhlt
#undef slash
#undef major
#undef relat
#undef reldo
#undef stack
#undef ident
#undef undef
#undef range
#undef canon
#undef comma
#undef dotac
#undef label
#undef plus
#undef fmpy
#undef argx
#undef temp
#undef issc
#undef fexp
#undef issb
#undef issa
#undef fsub
#undef bool
#undef fdiv
#undef geom
#undef meta
#undef real__
#undef fadd
#undef arg2
#undef arg1
#undef top
#undef way
#undef not
#undef dot
#undef vbl
#undef fcn


