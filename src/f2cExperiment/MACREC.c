/* MACREC.f -- translated by f2c (version 20100827).
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
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer seqcom[3];
} seqcom_;

#define seqcom_1 seqcom_

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
    integer macxx3[2630];
} macxx3_;

#define macxx3_1 macxx3_

struct {
    integer macxx4[100];
} macxx4_;

#define macxx4_1 macxx4_

struct {
    integer macxx6[1300];
} macxx6_;

#define macxx6_1 macxx6_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

struct {
    integer icallf;
} calflg_;

#define calflg_1 calflg_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

struct {
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* Table of constant values */

static integer c__1 = 1;
static integer c__32 = 32;
static integer c__8 = 8;
static integer c__3002 = 3002;
static integer c__1016 = 1016;
static integer c__21 = 21;
static integer c__0 = 0;
static integer c__27 = 27;
static integer c__1017 = 1017;
static integer c__22 = 22;
static integer c__1018 = 1018;
static integer c__1019 = 1019;
static integer c__28 = 28;
static integer c__2055 = 2055;
static integer c__29 = 29;
static integer c__1020 = 1020;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__24 = 24;
static integer c__37 = 37;

/* *** SOURCE FILE : M0006651.W03   *** */


/*              FORTRAN SUBROUTINE MACREC */

/* LINKAGE      SUBROUTINE MACREC(IPROD) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    HELP            SUBROUTINE    RECOG */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  BCDF */
/*          SUBROUTINE    BINBCD */
/*          LOGICAL FCT.  IFTMP */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    LABELZ */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    CALMCX */
/*          SUBROUTINE    MACTAB */
/*          SUBROUTINE    COMSTR */
/*          SUBROUTINE    MCXTRN */
/*          SUBROUTINE    MNPROC */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    ASNADZ */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    EPILOG */

/* Subroutine */ int macrec_(integer *iprod)
{
    /* Initialized data */

    static char hcall[6] = "CALL  ";
    static integer mrgtop = 0;
    static integer imrgdm = 150;
    static char i296[6] = "APT296";
    static integer j296 = 19205;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n, j1, j2, m1, n1, n2, n3, ii, jj, kk;
#define fcn ((integer *)&code_1 + 34)
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
    extern integer bcdf_(char *, ftnlen), name_(char *, ftnlen), mode_(
	    integer *);
#define geom ((integer *)&code_1 + 30)
    extern /* Subroutine */ int help_(void);
    static integer save, iseq[3];
#define repl ((integer *)&il_1 + 16)
#define temp ((integer *)&code_1 + 32)
    static integer save1;
#define temp1 ((integer *)&macxx1_1 + 7)
#define label ((integer *)&code_1 + 42)
#define mcnmb ((integer *)&macxx1_1 + 1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define digit ((integer *)&code_1 + 18)
#define ident ((integer *)&code_1 + 68)
#define mvmac ((logical *)&macxx1_1 + 16)
#define stack ((integer *)&stklst_1 + 3)
    static integer icnum;
#define ilhlt ((logical *)&macxx1_1 + 13)
    static logical jlhlt;
    extern logical iftmp_(integer *);
#define mnmvb ((integer *)&macxx4_1)
#define mvseg ((integer *)&macxx1_1 + 11)
#define mnmvc ((integer *)&macxx4_1 + 25)
#define seqno ((integer *)&seqcom_1)
#define rterm ((integer *)&code_1 + 6)
#define macdf1 ((integer *)&macxx3_1)
#define macdf2 ((integer *)&macxx3_1 + 400)
#define nxtln ((integer *)&macxx1_1 + 68)
#define mvpnt ((integer *)&macxx1_1 + 15)
#define macsv1 ((integer *)&macxx3_1 + 2600)
#define macsv2 ((integer *)&macxx3_1 + 2610)
#define macsv3 ((integer *)&macxx3_1 + 2620)
    extern /* Subroutine */ int binbcd_(integer *, integer *, integer *);
#define macldd ((logical *)&macxx1_1 + 6)
#define macend ((logical *)&macxx1_1 + 61)
    extern /* Subroutine */ int mactab_(integer *, integer *);
#define macred ((logical *)&macxx1_1 + 17)
#define macnam ((integer *)&code_1 + 66)
#define finmac ((logical *)&macxx1_1 + 23)
#define macdfp ((integer *)&macxx1_1)
#define mchdng ((logical *)&prt_1 + 6)
#define branch ((integer *)&macxx1_1 + 19)
#define mcdfdm ((integer *)&macxx1_1 + 31)
#define mactbl ((integer *)&macxx6_1)
#define implab ((integer *)&code_1 + 44)
#define macvbl ((integer *)&code_1 + 70)
#define callon ((logical *)&macxx1_1 + 9)
#define pathch ((integer *)&macxx1_1 + 70)
#define congeo ((integer *)&code_1 + 76)
#define macseq ((integer *)&macxx4_1 + 50)
#define proced ((integer *)&code_1 + 36)
#define callmv ((logical *)&macxx1_1 + 10)
#define callpt ((integer *)&macxx1_1 + 12)
#define permid ((integer *)&code_1 + 38)
#define intmed ((integer *)&macxx1_1 + 21)
#define mseqdm ((integer *)&macxx1_1 + 35)
#define mcsavp ((integer *)&macxx1_1 + 4)
#define mhstdm ((integer *)&macxx1_1 + 32)
#define mcsvdm ((integer *)&macxx1_1 + 33)
#define mchstp ((integer *)&macxx1_1 + 2)
#define mnmvbp ((integer *)&macxx1_1 + 5)
#define conpro ((integer *)&code_1 + 78)
#define subscr ((integer *)&modx_1 + 23)
#define mnmvdm ((integer *)&macxx1_1 + 34)
#define mcsrch ((integer *)&macxx1_1 + 58)
#define numarg ((integer *)&macxx1_1 + 60)
#define whchmn ((integer *)&macxx1_1 + 62)
#define pathln ((integer *)&macxx1_1 + 67)
#define seqnum ((integer *)&seqcom_1 + 1)
#define ivsvdm ((integer *)&macxx1_1 + 66)
#define machst ((integer *)&macxx3_1 + 800)
#define vblsvp ((integer *)&macxx1_1 + 65)
#define newstm ((logical *)&flags_1 + 1)
#define vblsav ((integer *)&macxx6_1 + 400)
#define mctxtp ((integer *)&macxx1_1 + 3)
#define modulo ((integer *)&moduli_1)
#define mvtrue ((logical *)&macxx1_1 + 18)
#define modhlf ((integer *)&moduli_1 + 1)
#define itmpct ((integer *)&macseg_1 + 4)
#define estack ((integer *)&errpos_1 + 102)
#define textst ((integer *)&macxx1_1 + 14)
    static integer mrgstk[150];
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *), 
	    resrvz_(integer *, integer *, integer *, integer *), opcode_(
	    integer *), onearg_(integer *), argcvt_(integer *), rlslin_(void),
	     asnadz_(integer *, integer *), puttmp_(integer *), mcxtrn_(
	    integer *, integer *, integer *), calmcx_(integer *, integer *, 
	    integer *);
    static integer switch__, mctxwd;
    extern /* Subroutine */ int labelz_(integer *), callzz_(integer *), 
	    comstr_(void), mnproc_(void), epilog_(void);



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* NUMBST:      NAMTBL INDEX OF BEGINNING OF NUMBER SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM ' */
/* DIGIT:       (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT ' */
/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* FCN:         (1)=CODE CLASS 18000,(2)=NAMTBL INDEX OF 'FCN   ' */
/* PROCED:      (1)=CODE CLASS 19000,(2)=NAMTBL INDEX OF 'PROCED' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* MACNAM:      (1)=CODE CLASS 34000,(2)=NAMTBL INDEX OF 'MACNAM' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/* MACVBL:      (1)=CODE CLASS 36000,(2)=NAMTBL INDEX OF 'MACVBL' */
/* CONGEO:      (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO' */
/* CONPRO:      (1)=CODE CLASS 40000,(2)=NAMTBL INDEX OF 'CONPRO' */

/*        5.    PROGRAM CONTROL FLAGS */

/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */
/* SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRENT STATEMENT NUMBER */

/*       14.    I. L. LIST OPTION FLAGS */

/* MCHDNG:      TRUE IF START OF NEW MACRO PROCESSING */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */

/*       17.    MODE CODES */

/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */

/*       22.    MACRO PROCESSING VARIABLES */

/* MACDFP:      POINTER TO LAST ENTRY IN MACDF1 AND MACDF2 ARRAYS */
/* MCNMB:       NUMBER OF DEFINED MACROS */
/* MCHSTP:      POINTER TO LAST MACHST ENTRY */
/* MCTXTP:      POINTER TO LAST MACTXT TABLE ENTRY */
/* MCSAVP:      PRESENT NEST LEVEL DURING MACRO PROCESSING */
/* MNMVBP:      POINTER TO LAST MNMVB AND MNMVC TABLE ENTRY */
/* MACLDD:      TRUE WHEN MACRO TEXT IS TO BE LOAD INTO MCBUFF TABLE */
/* TEMP1:       MACRO TEMPORARY STORAGE */
/* CALLON:      TRUE AT A NESTED CALL DURING INTERMED. MACRO PROCESSING */
/* CALLMV:      TRUE IF A CALL/MACRO VARIABLE STATEMENT IS ENCOUNTERED */
/* MVSEG:       CONTAINS POSITION NUMBER OF MACRO VBL IF CALLMV IS TRUE */
/* CALLPT:      MACTXT INDEX OF CURRENT CALL STATEMENT */
/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* TEXTST:      POINTER TO MCBUFF OF MACRO TEXT WORD BEING PROCESSED */
/* MVPNT:       CONTAINS POINTER-1 OF FIRST MACRO VARIABLE VBLSAV */
/* MVMAC:       TRUE IF IN NESTED CALL LIST MACROVBL = MACRO VBL */
/* MACRED:      SET TRUE TO INDICATE INPUT FROM MCBUFF TABLE */
/* MVTRUE:      TRUE IF SOME ASSIGNED VALUE IS A MACRO NAME */
/* BRANCH:      SET 2 IF MACRO IS TO UNDERGO INTERMEDIATE PROCESSING. */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* MCDFDM:      DIMENSION OF ARRAYS MACDF1,MACDF2 AND MACTBL */
/* MHSTDM:      CONTAINS DIMENSION OF ARRAY MACHST */
/* MCSVDM:      DIMENSION OF ARRAYS MACSV1,MACSV2 AND MACSV3 */
/* MNMVDM:      CONTAINS DIMENSION OF MNMVB AND MNMVC */
/* MSEQDM:      CONTAINS DIMENSION OF THE ARRAY MACSEQ */
/* MCSRCH:      AT FINAL MACRO PRECESSING MACDF1 POINTER */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* MACEND:      TRUE WHEN ALL MACRO PROCESSING IS FINISHED */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */
/* VBLSVP:      POINTER TO LAST VBLSAV ENTRY */
/* IVSVDM:      DIMENSION OF ARRAY VBLSAV */
/* PATHLN:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */
/* NXTLN:       POINTER TO NEXT LINUSD POSITION TO BE EXAMINED */
/* PATHCH:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */

/*       24.    MACRO PROCESSING ARRAYS */

/* MACDF1:      STORES MACRO NAME AND ALL MACRO VBL NAMTBL POINTERS */
/* MACDF2:      STORES NORMAL VALUES FOR ALL MACRO VARIABLES */
/* MACHST:      MACRO CALL HISTORY TABLE */
/* MACSV1:      CONTAINS MACRO NEST LEVEL INFORMATIONS */
/* MACSV2:      CONTAINS MACRO NEST LEVEL INFORMATIONS */
/* MACSV3:      CONTAINS MACRO NEST LEVEL INFORMATIONS */

/*       25.    MACRO PROCESSING ARRAYS */

/* MNMVB:       INDICATES MACROS IN WHICH ARE ASSIGNED VALUES */
/* MNMVC:       CALLED MACRO FOR WHICH CORRESPONDING MNMVB ENTRY IS MADE */
/* MACSEQ:      PRESERVES INITIAL SEQUENCE NUMBERS OF THE MACROS */

/*       26.    MACRO PROCESSING ARRAYS */

/* MACTBL:      NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */
/* VBLSAV:      SAVES MACRO VBL ASSIGNED VALUES DURING INTERMED. PROCESS */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* ITMPCT:      NUMBER OF INTERNAL SYMBOLS GENERATED IN TRANSLATION */

/*       38.    COMMON BLOCK MACRO CALL STATEMENT */
/*              INDICATES A MACRO CALL BEING PROCESSED */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */

/*       45.    NUMBER TABLE INDICES */

/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/* MASGND:      NAMTBL INDEX OF SECTION END FOR NUMBERS ASSIGNED TO MACRO */
/* * */
/* PURPOSE    EXECUTIVE ROUTINE FOR ALL PRODUCTIONS RELATED TO */
/*            APT MACRO PROCESSING */

/* ARGUMENT   IPROD  NUMBER ASSOCIATED WITH CURRENTLY MATCHED PRODUCTION */
/* NOTES      IPROD IS 50 LESS THAN ORIGINAL PRODUCTION NUMBER */

/*   MACRO-SPEZIAL-STACK FUER 50 MACROVARIABLE */

/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

/* ** */
    k = *top;
    switch (*iprod) {
	case 1:  goto L4100;
	case 2:  goto L4200;
	case 3:  goto L4300;
	case 4:  goto L4400;
	case 5:  goto L4500;
	case 6:  goto L4600;
	case 7:  goto L4700;
	case 8:  goto L4800;
	case 9:  goto L4900;
	case 10:  goto L5000;
	case 11:  goto L4300;
	case 12:  goto L4420;
    }
L4100:
    i__ = stack[(*top - 1 << 1) - 2];
    if (i__ > nametb_1.nammax) {
	goto L4102;
    }
    j = nametb_1.namtbl[i__ - 1];
    if (j / *modulo != temp[0] / *modulo) {
	goto L4101;
    }
    m = j - temp[0];
    ++(*itmpct);
    i__1 = -(*itmpct);
    maclbl_(&i__, &i__1, &ii);
    if (m > *modhlf) {
	m = *subscr;
    }
    nametb_1.namtbl[ii - 1] = vbl[0] + m;
    resrvz_(&ii, &m, &tmp_1.txxxx[(m << 1) - 2], &c__1);
    stack[(*top - 1 << 1) - 2] = ii;
    if (m == *subscr) {
	goto L4120;
    }
    opcode_(repl);
    onearg_(&tmp_1.txxxx[(m << 1) - 2]);
    argcvt_(&ii);
    argcvt_(&i__);
    rlslin_();
    goto L4125;
L4120:
    m = j - temp[0];
    asnadz_(&ii, &i__);
L4125:
    if (iftmp_(&i__)) {
	i__1 = mode_(&i__);
	puttmp_(&i__1);
    }
    nametb_1.namtbl[ii - 1] = vbl[0] + m;
L4101:
    if (mrgtop + 3 <= imrgdm) {
	goto L4103;
    }
L4104:
    i__1 = *top - 1;
    alarm_(&c__32, &i__1, &c__8, "MACREC  ", (ftnlen)8);
    *iprod = 4;
    goto L4420;
L4102:
    ++numblk_1.mnmbnd;
    if (numblk_1.mnmbnd < numblk_1.masgnd) {
	goto L4106;
    }
    if (numblk_1.mnmbnd == numblk_1.masgnd) {
	i__1 = *top - 1;
	alarm_(&c__3002, &i__1, &c__8, "MACREC  ", (ftnlen)8);
    }
    numblk_1.mnmbnd = numblk_1.masgnd + 1;
L4106:
    stack[(*top - 1 << 1) - 2] = numblk_1.mnmbnd + nametb_1.nammax;
    s_copy(cnamtb_1.cnumtb + (numblk_1.mnmbnd - 1) * 12, cnamtb_1.cnumtb + (
	    i__ - nametb_1.nammax - 1) * 12, (ftnlen)12, (ftnlen)12);
    goto L4101;
L4103:
    mrgstk[mrgtop + 2] = stack[(*top - 1 << 1) - 2];
    *top += -2;
L4110:
    i__ = stack[(*top - 1 << 1) - 2];
    mrgstk[mrgtop] = i__;
    mrgstk[mrgtop + 1] = nametb_1.namtbl[i__ - 1];
    mrgtop += 3;
    calflg_1.icallf = 1;
    nametb_1.namtbl[i__ - 1] = macvbl[0] + mrgtop / 3;
    *top += -2;
    stack[(*top << 1) - 2] = stack[(k << 1) - 2];
    stack[(*top << 1) - 1] = stack[(k << 1) - 1];
    goto L1;
L4200:
    if (mrgtop + 3 > imrgdm) {
	goto L4104;
    }
    mrgstk[mrgtop + 2] = 0;
    goto L4110;
L4300:
    if (*mcsavp != 0) {
	goto L4310;
    } else {
	goto L4320;
    }
L4310:
    i__1 = *top - 3;
    alarm_(&c__1016, &i__1, &c__8, "MACREC  ", (ftnlen)8);
    goto L4360;
L4320:
    if (*macdfp + 3 + mrgtop / 3 <= *mcdfdm) {
	goto L4325;
    }
    alarm_(&c__21, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4325:
    if (mrgtop <= 0) {
	goto L4350;
    } else {
	goto L4330;
    }
L4330:
    i__1 = mrgtop;
    for (i__ = 3; i__ <= i__1; i__ += 3) {
	j = *macdfp + i__ / 3;
	macdf1[j + 2] = mrgstk[i__ - 3];
/* L4340: */
	macdf2[j + 2] = mrgstk[i__ - 1];
    }
    macdf1[*macdfp + 2] = j + 3;
L4350:
    l = stack[(*top - 3 << 1) - 2];
    if (*iprod == 11) {
	l = stack[(*top - 4 << 1) - 2];
    }
    macdf1[*macdfp] = l;
    ++(*mcnmb);
    macdf2[*macdfp + 1] = *mcnmb;

/* ...     PRESERVE INITIAL SEQUENCE NO. FOR THIS MACRO */

    if (*mcnmb <= *mseqdm) {
	goto L4355;
    }
    alarm_(&c__27, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4355:
    macseq[*mcnmb - 1] = *seqno;
    nametb_1.namtbl[l - 1] = macnam[0] + *mcnmb;
    macdf1[*macdfp + 1] = *mctxtp;
L4360:
    *macldd = TRUE_;
L600:
    *newstm = TRUE_;
L1:
    return 0;
L4400:
    *macldd = FALSE_;
/* L4410: */
    *macdfp += 3;
    if (mrgtop != 0) {
	*macdfp = macdf1[*macdfp - 1];
    }
    i__1 = *mctxtp + 1;
    mcxtrn_(&c__1, &i__1, &stack[(*top - 1 << 1) - 2]);
    i__1 = *mctxtp + 2;
    mcxtrn_(&c__1, &i__1, &rterm[1]);
    *mctxtp += 2;
L4415:
    if (mrgtop <= 0) {
	goto L600;
    } else {
	goto L4420;
    }
L4420:
    i__1 = mrgtop;
    for (i__ = 3; i__ <= i__1; i__ += 3) {
	j = mrgstk[i__ - 3];
/* L4430: */
	nametb_1.namtbl[j - 1] = mrgstk[i__ - 2];
    }
    mrgtop = 0;
    calflg_1.icallf = 0;
    goto L600;
L4500:
    i__ = stack[(*top - 1 << 1) - 2];
    ++(*mctxtp);
    if (i__ > nametb_1.nammax) {
	goto L1410;
    }
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, hcall, (ftnlen)6, (ftnlen)6) ==
	     0) {
	i__ = 0;
    }
    if (nametb_1.namtbl[i__ - 1] / *modulo == macvbl[0] / *modulo) {
	i__ = macvbl[0] - nametb_1.namtbl[i__ - 1];
    }
    mcxtrn_(&c__1, mctxtp, &i__);
    goto L1420;
L1410:
    j = nametb_1.numbst + nametb_1.nammax;
    mcxtrn_(&c__1, mctxtp, &j);
    for (j = 1; j <= 9; j += 4) {
	++(*mctxtp);
	icnum = bcdf_(cnamtb_1.cnumtb + ((i__ - nametb_1.nammax - 1) * 12 + (
		j - 1)), (ftnlen)4);
	mcxtrn_(&c__1, mctxtp, &icnum);
/* L1415: */
    }
L1420:
    i__ = stack[(*top << 1) - 2];
    if (i__ > nametb_1.nammax) {
	goto L1450;
    }
    i__1 = *mctxtp + 1;
    mcxtrn_(&c__1, &i__1, &i__);
    if (i__ == rterm[1]) {
	goto L4501;
    }
L1430:
    *top += -2;
    numblk_1.numidx = numblk_1.mnmbnd;
    goto L5010;
L1440:
    ++(*top);
L1450:
    j = nametb_1.numbst + nametb_1.nammax;
    i__1 = *mctxtp + 1;
    mcxtrn_(&c__1, &i__1, &j);
    for (j = 1; j <= 9; j += 4) {
	++(*mctxtp);
	icnum = bcdf_(cnamtb_1.cnumtb + ((i__ - nametb_1.nammax - 1) * 12 + (
		j - 1)), (ftnlen)4);
	i__1 = *mctxtp + 1;
	mcxtrn_(&c__1, &i__1, &icnum);
/* L1425: */
    }
    goto L1430;
L4501:
    *iprod = 6;
    goto L4601;
L4600:
    i__1 = *mctxtp + 1;
    mcxtrn_(&c__1, &i__1, &rterm[1]);
L4601:
    ++(*mctxtp);
    goto L600;
L4700:
    i__ = stack[(*top - 3 << 1) - 2];
    calflg_1.icallf = 0;
    if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, hcall, (ftnlen)6, (ftnlen)6) ==
	     0) {
	goto L4701;
    }
    i__1 = *top - 3;
    alarm_(&c__1017, &i__1, &c__8, "MACREC  ", (ftnlen)8);
    goto L4415;
L4701:
    *branch = 1;
    j = stack[(*top - 1 << 1) - 2];
L4702:
    *mvmac = FALSE_;
    *mvtrue = FALSE_;
    *callon = FALSE_;
    if (*mchstp + 4 <= *mhstdm) {
	goto L4780;
    }
L4782:
    alarm_(&c__22, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4780:
    *temp1 = *mchstp;
    i__ = 1;
    mactab_(&j, &i__);
/* L4704: */
    j2 = macdf1[i__ + 1];
    macsv2[*mcsavp] = *vblsvp + 1;
    macsv1[*mcsavp] = i__;
    if (j2 <= 0) {
	goto L4728;
    } else {
	goto L4705;
    }
L4705:
    j1 = i__ + 3;
    m1 = 0;
    kk = 0;
    i__1 = j2;
    for (j = j1; j <= i__1; ++j) {
	k = (i__2 = macdf1[j - 1], abs(i__2));
	m1 += 100000;
	++kk;
	switch (*branch) {
	    case 1:  goto L4790;
	    case 2:  goto L4802;
	}
L4790:
	if (k > nametb_1.nammax) {
	    goto L15;
	}
/*   MACRO-CALL OHNE ARGUMENTE */
	if (mrgtop == 0) {
	    goto L15;
	}
	if (nametb_1.namtbl[k - 1] / *modulo != macvbl[0] / *modulo) {
	    goto L15;
	}
/* L4706: */
	i__2 = mrgtop;
	for (l = 3; l <= i__2; l += 3) {
	    if (k == mrgstk[l - 3]) {
		goto L4708;
	    }
/* L4707: */
	}
L4708:
	if (*mcsavp <= 0) {
	    goto L4715;
	} else {
	    goto L4709;
	}
L4709:
	m = macsv1[*mcsavp - 1];
	n2 = macdf1[m + 1];
	if (n2 <= 0) {
	    goto L4715;
	} else {
	    goto L4710;
	}
L4710:
	n1 = m + 3;
	i__2 = n2;
	for (n = n1; n <= i__2; ++n) {
	    if (mrgstk[l - 1] == (i__3 = macdf1[n - 1], abs(i__3))) {
		goto L4712;
	    }
/* L4711: */
	}
	goto L4715;
L4712:
	n3 = n - n1 + macsv2[*mcsavp - 1];
	vblsav[*vblsvp] = vblsav[n3 - 1];
	machst[*mchstp + 3] = -(m1 + n - n1 + 1);
	*mvmac = TRUE_;
L4713:
	++(*mchstp);
	if (*mchstp + 4 > *mhstdm) {
	    goto L4782;
	}
L4714:
	mrgstk[l - 1] = -1;
	nametb_1.namtbl[k - 1] = mrgstk[l - 2];
	goto L4717;
L4715:
	if (macdf2[j - 1] == mrgstk[l - 1]) {
	    goto L4716;
	}
	vblsav[*vblsvp] = mrgstk[l - 1];
	machst[*mchstp + 3] = m1 + mrgstk[l - 1];
	goto L4713;
L4716:
	vblsav[*vblsvp] = macdf2[j - 1];
	goto L4714;
L15:
	vblsav[*vblsvp] = macdf2[j - 1];
L4717:
	n = vblsav[*vblsvp];
	if (n > nametb_1.nammax) {
	    goto L4718;
	}
	if (nametb_1.namtbl[n - 1] / *modulo == macnam[0] / *modulo) {
	    goto L4720;
	}
L4718:
	if (macdf1[j - 1] >= 0) {
	    goto L4727;
	} else {
	    goto L4719;
	}
L4719:
	alarm_(&c__1018, &c__0, &c__8, "MACREC  ", (ftnlen)8);
	goto L4720;
L4720:
	if ((i__2 = macdf1[j - 1] * macdf2[i__ - 1]) < 0) {
	    goto L4723;
	} else if (i__2 == 0) {
	    goto L4722;
	} else {
	    goto L4721;
	}
L4721:
	alarm_(&c__1019, &c__0, &c__8, "MACREC  ", (ftnlen)8);
	goto L4723;
L4722:
	macdf1[j - 1] = -macdf1[j - 1];
L4723:
	l = 1;
	mactab_(&n, &l);
	if (macdf2[l - 1] == 0) {
	    *mvtrue = TRUE_;
	}
	if (*mnmvbp <= 0) {
	    goto L4726;
	} else {
	    goto L4724;
	}
L4724:
	i__2 = *mnmvbp;
	for (k = 1; k <= i__2; ++k) {
	    if (mnmvb[k - 1] == n && mnmvc[k - 1] == i__) {
		goto L4727;
	    }
/* L4725: */
	}
L4726:
	++(*mnmvbp);
	if (*mnmvbp <= *mnmvdm) {
	    goto L4786;
	}
	alarm_(&c__28, &c__0, &c__8, "MACREC  ", (ftnlen)8);
	help_();
L4786:
	mnmvb[*mnmvbp - 1] = n;
	mnmvc[*mnmvbp - 1] = i__;
	if (macdf2[l - 1] != 0 && macdf2[l - 1] <= *mcsavp + 1) {
	    macdf2[l - 1] = *mcsavp + 2;
	}
L4727:
	if (macdf2[j - 1] != 0 || machst[*mchstp + 2] / 100000 == kk) {
	} else {
	    jlhlt = *ilhlt;
	    *ilhlt = FALSE_;
	    for (n3 = 1; n3 <= 3; ++n3) {
		iseq[n3 - 1] = seqcom_1.seqcom[n3 - 1];
/* L4744: */
	    }
	    n3 = macdf2[j1 - 3];
	    *seqno = macseq[n3 - 1];
	    binbcd_(seqno, seqnum, &n3);
	    stack[(*top + 1 << 1) - 2] = macdf1[j1 - 4];
	    stack[(*top + 2 << 1) - 2] = macdf1[j - 1];
	    alarm_(&c__2055, &c__0, &c__8, "MACREC  ", (ftnlen)8);
	    *ilhlt = jlhlt;
	    for (n3 = 1; n3 <= 3; ++n3) {
		seqcom_1.seqcom[n3 - 1] = iseq[n3 - 1];
/* L4745: */
	    }
	}
	++(*vblsvp);
/* L4731: */
    }
    if (*vblsvp < *ivsvdm) {
	goto L4728;
    }
L4788:
    alarm_(&c__29, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4728:
    switch (*branch) {
	case 1:  goto L4752;
	case 2:  goto L4739;
    }
L4752:
    if (mrgtop != 0) {
	goto L4729;
    } else {
	goto L4732;
    }
L4729:
    i__1 = mrgtop;
    for (l = 3; l <= i__1; l += 3) {
	if (mrgstk[l - 1] != -1) {
	    alarm_(&c__1020, &c__0, &c__8, "MACREC  ", (ftnlen)8);
	}
/* L4730: */
    }
L4732:
    if (*callmv) {
	goto L4735;
    }
    if (*mvmac) {
	goto L4736;
    }
    ++macdf2[i__ + 1];
    machst[*temp1 + 2] = macdf2[i__ + 1];
    *mchstp += 3;
    if (*mchstp + 4 > *mhstdm) {
	goto L4782;
    }
    if (*mcsavp <= 0) {
	goto L4733;
    } else {
	goto L4734;
    }
L4733:
    if (j2 != 0) {
	goto L1010;
    }
    maclbl_(&c_n1, &macdf1[i__ - 1], &j);
    nametb_1.namtbl[j - 1] = label[0];
    calmcx_(&j, &c__0, &c__1);
    goto L1020;
L1010:
    calmcx_(&macdf1[i__ - 1], &c__0, &c__2);
    i__1 = -macdf2[i__ + 1];
    maclbl_(&macdf1[i__ - 1], &i__1, &l);
    nametb_1.namtbl[l - 1] = implab[0];
    calmcx_(&l, &c__0, &c__1);
L1020:
    machst[*temp1] = 0;
    goto L4742;
L4734:
    i__1 = *callpt + 1;
    mcxtrn_(&c__1, &i__1, &macdf2[i__ + 1]);
    i__1 = *callpt + 2;
    mcxtrn_(&c__1, &i__1, &i__);
    goto L4703;
L4735:
    i__1 = *callpt + 2;
    i__2 = -(*mvseg);
    mcxtrn_(&c__1, &i__1, &i__2);
    *callmv = FALSE_;
    goto L4737;
L4736:
    i__1 = *callpt + 2;
    mcxtrn_(&c__1, &i__1, &i__);
L4737:
    i__1 = *callpt + 1;
    mcxtrn_(&c__1, &i__1, &c__0);
    if (*temp1 == *mchstp) {
	goto L4739;
    }
    m = *mchstp - 1;
    i__1 = m;
    for (l = *temp1; l <= i__1; ++l) {
	i__2 = *callpt + 3;
	mcxtrn_(&c__1, &i__2, &machst[l + 3]);
/* L4738: */
	++(*callpt);
    }
L4739:
    *mchstp = *temp1 + 3;
    machst[*mchstp - 1] = 0;
L4703:
    machst[*temp1] = macsv1[*mcsavp - 1];
    switch (*branch) {
	case 1:  goto L4740;
	case 2:  goto L4742;
    }
L4740:
    i__1 = *callpt + 3;
    mcxtrn_(&c__1, &i__1, textst);
/* L4741: */
    macsv3[*mcsavp - 1] = *textst;
L4742:
    machst[*temp1 + 1] = i__;
    if (macdf2[i__ - 1] != 0) {
	goto L4743;
    } else {
	goto L4760;
    }
L4743:
    if (macdf2[i__ - 1] > *mcsavp) {
	goto L4749;
    }
    macdf2[i__ - 1] = *mcsavp + 1;
L4749:
    if (*mvtrue) {
	goto L4757;
    }
    if (macdf1[i__ + 1] <= 0) {
	goto L4754;
    } else {
	goto L4767;
    }
L4767:
    switch__ = 2;
    goto L4762;
L4754:
    if (*mcsavp != 0) {
	goto L4759;
    } else {
	goto L4415;
    }
L4760:
    if (macdf1[i__ + 1] <= 0) {
	goto L4757;
    } else {
	goto L4761;
    }
L4761:
    switch__ = 1;
L4762:
    j = macsv2[*mcsavp];
    j1 = i__ + 3;
    j2 = macdf1[i__ + 1];
    i__1 = j2;
    for (k = j1; k <= i__1; ++k) {
	switch (switch__) {
	    case 1:  goto L4765;
	    case 2:  goto L4763;
	}
L4763:
	l = vblsav[j - 1];
	m = mactbl[k - 1];
	if (l > nametb_1.nammax) {
	    goto L4766;
	}
	n = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
	if (m > nametb_1.nammax) {
	    goto L4777;
	}
	m = *modulo * (nametb_1.namtbl[m - 1] / *modulo);
	if (n != congeo[0]) {
	    goto L4791;
	}
	if (m == geom[0]) {
	    goto L4798;
	}
	goto L4793;
L4791:
	if (n != conpro[0]) {
	    goto L4792;
	}
	if (m == proced[0]) {
	    goto L4798;
	}
	goto L4793;
L4777:
	m = vbl[0];
L4792:
	if (n != ident[0] && n != permid[0]) {
	    goto L4793;
	}
	if (m == permid[0]) {
	    goto L4798;
	}
	if (m != fcn[0]) {
	    goto L4793;
	}
L4798:
	nametb_1.namtbl[l - 1] = m + nametb_1.namtbl[l - 1] - n;
	goto L4766;
L4793:
	if (m != vbl[0]) {
	    goto L4766;
	}
	switch__ = 1;
	goto L4766;
L4765:
	mactbl[k - 1] = vblsav[j - 1];
L4766:
	++j;
    }
    switch (switch__) {
	case 1:  goto L4757;
	case 2:  goto L4754;
    }
L4757:
    *intmed = -1;
    *macred = TRUE_;
    *ilhlt = TRUE_;
    *mvpnt = macsv2[*mcsavp] - 1;
    ++(*mcsavp);
    if (*mcsavp < *mcsvdm) {
	goto L4784;
    }
    alarm_(&c__24, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4784:
    macdf2[i__ - 1] = *mcsavp;
    *whchmn = macdf2[i__];
    switch (*branch) {
	case 1:  goto L4758;
	case 2:  goto L4808;
    }
L4758:
    *textst = macdf1[i__];
L4759:
    switch (*branch) {
	case 1:  goto L4415;
	case 2:  goto L4812;
    }
L4800:
    i__1 = *textst + 2;
    mcxtrn_(&c__2, &i__1, &j);
    jj = *textst + 3;
L4820:
    mcxtrn_(&c__2, &jj, &mctxwd);
    if (mctxwd / 100000 == 0) {
	goto L4821;
    }
    ++jj;
    goto L4820;
L4821:
    *branch = 2;
    if (j <= 0) {
	goto L4801;
    } else {
	goto L4702;
    }
L4801:
    j = *mvpnt - j;
    j = vblsav[j - 1];
    goto L4702;
L4802:
    save = *textst + 3;
L4803:
    mcxtrn_(&c__2, &save, &mctxwd);
    save1 = mctxwd / 100000;
    if (save1 != 0) {
	goto L4804;
    } else {
	goto L4851;
    }
L4851:
    vblsav[*vblsvp] = macdf2[j - 1];
    goto L4717;
L4804:
    if (abs(save1) * 100000 == m1) {
	goto L4805;
    }
    ++save;
    goto L4803;
L4805:
    if (save1 >= 0) {
	goto L4807;
    } else {
	goto L4806;
    }
L4806:
    save1 = macsv2[*mcsavp - 1] - (m1 + mctxwd) - 1;
    vblsav[*vblsvp] = vblsav[save1 - 1];
    goto L4717;
L4807:
    vblsav[*vblsvp] = mctxwd - m1;
    goto L4717;
L4808:
    mcxtrn_(&c__2, &jj, &macsv3[*mcsavp - 2]);
    *textst = macdf1[i__];
L4811:
    stack[(*top << 1) - 2] = rterm[1];
    goto L4415;
L4812:
    mcxtrn_(&c__2, &jj, textst);
    goto L4811;
L4900:
    if (*intmed < 0) {
	goto L4901;
    } else if (*intmed == 0) {
	goto L4904;
    } else {
	goto L4905;
    }
L4901:
    --(*mcsavp);
    l = macsv1[*mcsavp];
    mactbl[l - 1] = 1;
    *vblsvp = macsv2[*mcsavp] - 1;
    if (*vblsvp >= *ivsvdm) {
	goto L4788;
    }
    if (*mcsavp < 0) {
	goto L4904;
    } else if (*mcsavp == 0) {
	goto L4902;
    } else {
	goto L4903;
    }
L4904:
    alarm_(&c__37, &c__0, &c__8, "MACREC  ", (ftnlen)8);
    help_();
L4902:
    *ilhlt = FALSE_;
    *macred = FALSE_;
    *intmed = 0;
    *whchmn = 0;
    goto L600;
L4903:
    *textst = macsv3[*mcsavp - 1];
    *mvpnt = macsv2[*mcsavp - 1] - 1;
    l = macsv1[*mcsavp - 1];
    *whchmn = macdf2[l];
    goto L600;
L4905:
    if (*finmac) {
	goto L4906;
    }
    *finmac = TRUE_;

/* ...  BEGIN FINAL MACRO PROCESSING FOR THIS MACRO */

    j = macdf2[*mcsrch];
    *seqno = macseq[j - 1];
    *ilhlt = FALSE_;
    *textst = macdf1[*mcsrch];
    *pathln = *numarg;
    *nxtln = 1;
    *pathch = *numarg;
    maclbl_(&c_n1, &macdf1[*mcsrch - 1], &j);
    nametb_1.namtbl[j - 1] = label[0];
    *mchdng = TRUE_;
    labelz_(&j);
    j = name_(i296, (ftnlen)6);
    nametb_1.namtbl[j - 1] = j296;
    callzz_(&j);
    rlslin_();
    goto L600;
L4906:
    comstr_();
    mnproc_();
    if (! (*macend)) {
	goto L600;
    }
    epilog_();
    *macred = FALSE_;
    goto L600;
L5000:
    i__ = stack[(*top << 1) - 2];
    if (i__ > nametb_1.nammax) {
	goto L1440;
    }
    if (nametb_1.namtbl[i__ - 1] / *modulo == macvbl[0] / *modulo) {
	i__ = macvbl[0] - nametb_1.namtbl[i__ - 1];
    }
    i__1 = *mctxtp + 1;
    mcxtrn_(&c__1, &i__1, &i__);
    --(*top);
L5010:
    ++(*mctxtp);
    goto L1;
} /* macrec_ */

#undef textst
#undef estack
#undef itmpct
#undef modhlf
#undef mvtrue
#undef modulo
#undef mctxtp
#undef vblsav
#undef newstm
#undef vblsvp
#undef machst
#undef ivsvdm
#undef seqnum
#undef pathln
#undef whchmn
#undef numarg
#undef mcsrch
#undef mnmvdm
#undef subscr
#undef conpro
#undef mnmvbp
#undef mchstp
#undef mcsvdm
#undef mhstdm
#undef mcsavp
#undef mseqdm
#undef intmed
#undef permid
#undef callpt
#undef callmv
#undef proced
#undef macseq
#undef congeo
#undef pathch
#undef callon
#undef macvbl
#undef implab
#undef mactbl
#undef mcdfdm
#undef branch
#undef mchdng
#undef macdfp
#undef finmac
#undef macnam
#undef macred
#undef macend
#undef macldd
#undef macsv3
#undef macsv2
#undef macsv1
#undef mvpnt
#undef nxtln
#undef macdf2
#undef macdf1
#undef rterm
#undef seqno
#undef mnmvc
#undef mvseg
#undef mnmvb
#undef ilhlt
#undef stack
#undef mvmac
#undef ident
#undef digit
#undef mcnmb
#undef label
#undef temp1
#undef temp
#undef repl
#undef geom
#undef top
#undef vbl
#undef fcn


