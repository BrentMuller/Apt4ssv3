/* INPUT.f -- translated by f2c (version 20100827).
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
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx3[2630];
} macxx3_;

#define macxx3_1 macxx3_

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
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__1028 = 1028;
static integer c__99 = 99;
static integer c__2 = 2;
static integer c__22 = 22;
static integer c__0 = 0;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0006640.W01   *** */


/*              FORTRAN SUBROUTINE INPUT */

/* LINKAGE      SUBROUTINE INPUT */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    RECOG */
/*          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    CALMCX */
/*          SUBROUTINE    HELP */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    MACTAB */
/*          SUBROUTINE    MATCH */
/*          SUBROUTINE    MCXTRN */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    PATH */
/*          SUBROUTINE    READ */

/* Subroutine */ int input_(void)
{
    /* Initialized data */

    static char ncall[6] = "CALL  ";
    static logical errflg = FALSE_;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, m, ii;
#define way ((integer *)&macxx1_1 + 25)
#define top ((integer *)&stklst_1)
    extern /* Subroutine */ int read_(integer *);
    extern integer name_(char *, ftnlen);
#define meta ((integer *)&srctbl_1 + 2)
    extern /* Subroutine */ int help_(void), path_(void);
#define label ((integer *)&code_1 + 42)
    static integer icrad;
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen), match_(void);
    static integer icrod;
#define stack ((integer *)&stklst_1 + 3)
#define slash ((integer *)&code_1 + 8)
#define mvseg ((integer *)&macxx1_1 + 11)
#define rterm ((integer *)&code_1 + 6)
#define macdf1 ((integer *)&macxx3_1)
#define macdf2 ((integer *)&macxx3_1 + 400)
#define entry__ ((logical *)&macxx1_1 + 39)
#define mvpnt ((integer *)&macxx1_1 + 15)
#define macsv1 ((integer *)&macxx3_1 + 2600)
    extern /* Subroutine */ int mactab_(integer *, integer *), maclbl_(
	    integer *, integer *, integer *);
#define macred ((logical *)&macxx1_1 + 17)
#define macnam ((integer *)&code_1 + 66)
#define finmac ((logical *)&macxx1_1 + 23)
#define endflg ((logical *)&flags_1)
#define mactbl ((integer *)&macxx6_1)
#define implab ((integer *)&code_1 + 44)
#define macspd ((integer *)&macxx6_1)
#define callon ((logical *)&macxx1_1 + 9)
    static integer inchar[80];
#define dlrflg ((logical *)&doloop_1 + 7)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int calmcx_(integer *, integer *, integer *);
#define callmv ((logical *)&macxx1_1 + 10)
#define callpt ((integer *)&macxx1_1 + 12)
#define intmed ((integer *)&macxx1_1 + 21)
#define mcsrch ((integer *)&macxx1_1 + 58)
#define machst ((integer *)&macxx3_1 + 800)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define mcltrm ((integer *)&code_1 + 74)
#define should ((logical *)&macxx1_1 + 69)
#define mchstp ((integer *)&macxx1_1 + 2)
#define mcsavp ((integer *)&macxx1_1 + 4)
#define mhstdm ((integer *)&macxx1_1 + 32)
#define numarg ((integer *)&macxx1_1 + 60)
#define vblsav ((integer *)&macxx6_1 + 400)
#define modulo ((integer *)&moduli_1)
#define errpnt ((integer *)&errpos_1 + 2)
#define mcstrt ((integer *)&macxx1_1 + 42)
#define newstm ((logical *)&flags_1 + 1)
#define ergstk ((integer *)&errpos_1 + 202)
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *);
    static integer mctxwd;
#define lmrstr ((logical *)&macseg_1 + 3)
#define textst ((integer *)&macxx1_1 + 14)




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM ' */
/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* MACNAM:      (1)=CODE CLASS 34000,(2)=NAMTBL INDEX OF 'MACNAM' */
/* MCLTRM:      (1)=CODE CLASS 38000,(2)=NAMTBL INDEX OF 'MCLTRM' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* ENDFLG:      TRUE WHEN  SOURCE STATEMENT TOTALLY IN STACK */
/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*       22.    MACRO PROCESSING VARIABLES */

/* MCHSTP:      POINTER TO LAST MACHST ENTRY */
/* MCSAVP:      PRESENT NEST LEVEL DURING MACRO PROCESSING */
/* CALLON:      TRUE AT A NESTED CALL DURING INTERMED. MACRO PROCESSING */
/* CALLMV:      TRUE IF A CALL/MACRO VARIABLE STATEMENT IS ENCOUNTERED */
/* MVSEG:       CONTAINS POSITION NUMBER OF MACRO VBL IF CALLMV IS TRUE */
/* CALLPT:      MACTXT INDEX OF CURRENT CALL STATEMENT */
/* TEXTST:      POINTER TO MCBUFF OF MACRO TEXT WORD BEING PROCESSED */
/* MVPNT:       CONTAINS POINTER-1 OF FIRST MACRO VARIABLE VBLSAV */
/* MACRED:      SET TRUE TO INDICATE INPUT FROM MCBUFF TABLE */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* MHSTDM:      CONTAINS DIMENSION OF ARRAY MACHST */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* MCSTRT:      INDEX IN MACSPD OF CURRENT CALL BEING EXAMINED */
/* MCSRCH:      AT FINAL MACRO PRECESSING MACDF1 POINTER */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */

/*       24.    MACRO PROCESSING ARRAYS */

/* MACDF1:      STORES MACRO NAME AND ALL MACRO VBL NAMTBL POINTERS */
/* MACDF2:      STORES NORMAL VALUES FOR ALL MACRO VARIABLES */
/* MACHST:      MACRO CALL HISTORY TABLE */
/* MACSV1:      CONTAINS MACRO NEST LEVEL INFORMATIONS */

/*       25.    MACRO PROCESSING ARRAYS */

/* MACTBL:      NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */
/* MACSPD:      NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */
/* VBLSAV:      SAVES MACRO VBL ASSIGNED VALUES DURING INTERMED. PROCESS */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* LMRSTR:      FLAG ON STARTS READING IN A SYSTEM MACRO */

/*       43.    DO LOOP CONTROL VALUES */

/* DLRFLG:      FLAG IS ON WHEN CONTINUATION CARD EXPECTED */

/*       44.    ERROR POSITION TABLE */

/* ERRPNT:      CONTAINS POINTERS TO INPUT STATEMENT TEXT POSITIONS */
/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* PURPOSE      TO PLACE THE NEXT CHARACTER OR WORD FROM */
/*              THE INPUT STREAM INTO THE WORKING STACK */
/*              (STACK) AND TO HANDLE THE PROCESSING OF */
/*              CALL STATEMENTS IMBEDDED IN MACROS. */

/* NOTES        1.  MACRED=.FALSE. IF SINGLE CHARACTERS */
/*                  ARE SELECTED FROM THE SOURCE INPUT */
/*                  FILE. */
/*                  MACRED=.TRUE. IF SINGLE WORDS ARE */
/*                  SELECTED FROM THE MACTXT TABLE, AN */
/*                  INTERNAL FILE CONTAINING MACRO TEXT. */
/*              2.  IT IS ASSUMED THAT THE CHARACTER POR- */
/*                  TION OF THE NAME TABLE (NAMTBL) IS */
/*                  ARRANGED SO THAT THE VALUE OF EACH */
/*                  CHARACTER IS EQUAL TO ONE LESS THAN ITS */
/*                  INDEX IN THE NAME TABLE (NAMTBL). */

/* ** */

/* ...     BRANCH IF MACRO TEXT REQUIRED. */

/* L5: */
    if (*macred) {
	goto L400;
    }

    if (! (*endflg) && ! (*lmrstr)) {
	goto L100;
    }
L10:
    read_(inchar);

/* ...               FETCH CHARACTER CODE */

L100:
    ++inptr_1.cnt;
    ii = inchar[inptr_1.cnt - 1];
    estack[*top] = errpnt[inptr_1.cnt - 1];
L150:
    *endflg = FALSE_;
    if (ii > nametb_1.nammax) {
	goto L160;
    }
    if (ii != 0) {
	goto L170;
    }

/* ...               IGNORE INVALID CHARACTER */

    i__1 = *top + 1;
    alarm_(&c__1, &i__1, &c__8, "INPUT   ", (ftnlen)8);
    goto L100;

L160:
    icrod = number[0];
    goto L300;
L170:
    if (ii < 0) {
	goto L300;
    }
    icrod = nametb_1.namtbl[ii - 1];
    if (icrod != rterm[0]) {
	goto L300;
    }
    *endflg = TRUE_;
    estack[*top] = estack[*top - 1];

/* ...               PLACE CHARACTER IN STACK */

L300:
    ++(*top);
    if ((i__1 = *top - 100) < 0) {
	goto L320;
    } else if (i__1 == 0) {
	goto L310;
    } else {
	goto L315;
    }
L310:
    if (! errflg) {
	alarm_(&c__1028, &c__99, &c__8, "INPUT   ", (ftnlen)8);
    }
    errflg = TRUE_;
L315:
    *top = 99;
    if (*endflg) {
	goto L318;
    }
    if (*dlrflg) {
	goto L10;
    }
    if (! (*macred)) {
	goto L317;
    }
L316:
    ++(*textst);
    mcxtrn_(&c__2, textst, &ii);
    if (ii != rterm[1]) {
	goto L316;
    }
L317:
    icrod = rterm[0];
    ii = rterm[1];
    *endflg = TRUE_;
L318:
    *top = 2;
L320:
    stack[(*top << 1) - 2] = ii;
    if (ii < 0) {
	goto L355;
    }
    icrod /= *modulo;
    stack[(*top << 1) - 1] = meta[icrod - 1];
L350:
    return 0;
L355:
    stack[(*top << 1) - 1] = 0;
    goto L350;
L400:
    ++(*textst);
    mcxtrn_(&c__2, textst, &mctxwd);
    if (mctxwd < 0) {
	goto L410;
    } else if (mctxwd == 0) {
	goto L460;
    } else {
	goto L440;
    }

/* ...     MACRO VARIABLE ENCOUNTERED. BRANCH IF NESTED CALL IS BEING */
/* ...     EXAMINED DURING INTERMEDIATE MACRO PROCESSING. */

L410:
    if (*callon) {
	goto L450;
    }
    if (*intmed <= 0) {
	goto L420;
    } else {
	goto L430;
    }

/* ...     SUBSTITUTE ASSIGNED VALUE FOR MACRO VARIABLE DURING */
/* ...     INTERMEDIATE MACRO PROCESSING. */

L420:
    ii = *mvpnt - mctxwd;
    ii = vblsav[ii - 1];
    goto L150;

/* ...     SUBSTITUTE SPECIAL MACRO VARIABLE NAME (BASED ON MACRO NAME AND */
/* ...     POSITION OF MACRO VARIABLE) FOR MACRO VARIABLE DURING FINAL */
/* ...     MACRO PROCESSING. */

L430:
    ii = -mctxwd;
    ii = macspd[ii - 1];
    goto L150;

/* ...     PICK UP NEXT WORD FROM MACTXT TABLE. */

L440:
    ii = mctxwd;
    goto L150;

/* ...     PICK UP MACRO VARIABLE NAME FROM MACDF1 TABLE. NESTED CALL IS */
/* ...     BEING EXAMINED DURING INTERMEDIATE MACRO PROCESSING. */

L450:
    ii = macsv1[*mcsavp - 1] - mctxwd;
    ii = (i__1 = macdf1[ii + 1], abs(i__1));
    goto L150;

/* ...     CALL ENCOUNTERED IN MACRO TEXT. */

L460:
    if (*intmed <= 0) {
	goto L470;
    } else {
	goto L570;
    }
L470:
    ii = macsv1[*mcsavp - 1];
    if (mactbl[ii - 1] <= 0) {
	goto L480;
    } else {
	goto L540;
    }

/* ...     CURRENT MACRO HAS NOT PREVIOUSLY UNDERGONE INTERMEDIATE MACRO */
/* ...     PROCESSING.PREPARE TO PERFORM SUCH PROCESSING ON NESTED CALL. */

L480:
    *callon = TRUE_;
    *callpt = *textst;
    stack[(*top + 1 << 1) - 2] = name_(ncall, (ftnlen)6);
    stack[(*top + 2 << 1) - 2] = slash[1];
    i__1 = *textst + 2;
    mcxtrn_(&c__2, &i__1, &mctxwd);
    if (mctxwd <= 0) {
	goto L490;
    } else {
	goto L500;
    }

/* ...     NAME FOLLOWING CALL/ IS A MACRO VARIABLE. */

L490:
    *mvseg = -mctxwd;
    *callmv = TRUE_;
    ii = *mvpnt + *mvseg;

/* ...     SUBSTITUTE ASSIGNED MACRO NAME FOR MACRO VARIABLE IN NESTED */
/* ...     CALL. */

    stack[(*top + 3 << 1) - 2] = vblsav[ii - 1];
    goto L510;

/* ...     PLACE MACRO NAME IN STACK FOR NESTED CALL. */

L500:
    stack[(*top + 3 << 1) - 2] = mctxwd;

/* ...     PREPARE STACK TO BEGIN INTERMEDIATE MACRO PROCESSING OF NESTED */
/* ...     CALL. */

L510:
    for (i__ = 1; i__ <= 3; ++i__) {
	++(*top);
	ii = stack[(*top << 1) - 2];
	ii = nametb_1.namtbl[ii - 1] / *modulo;
/* L520: */
	stack[(*top << 1) - 1] = meta[ii - 1];
    }
    ii = stack[(*top << 1) - 2];
    if (nametb_1.namtbl[ii - 1] / *modulo == macnam[0] / *modulo) {
	goto L530;
    }
    *callon = FALSE_;
    *callmv = FALSE_;
    mcxtrn_(&c__1, textst, &stack[(*top - 2 << 1) - 2]);
L530:
    *textst += 2;
    goto L350;

/* ...     CURRENT MACRO IS UNDERGOING INTERMEDIATE MACRO REPROCESSING. */
/* ...     DETERMINE WHETHER OR NOT MACRO NAMED IN NESTED CALL REQUIRES */
/* ...     INTERMEDIATE MACRO REPROCESSING. */

L540:
    i__1 = *textst + 1;
    mcxtrn_(&c__2, &i__1, &mctxwd);
    if (mctxwd != 0) {
	goto L550;
    } else {
	goto L560;
    }

/*  NO INTERMEDIATE MACRO PROCESSING OF CALLED MACRO REQUIRED. */
L550:
    i__1 = *textst + 3;
    mcxtrn_(&c__2, &i__1, textst);
L551:
    stack[(*top << 1) - 2] = rterm[1];
    *newstm = TRUE_;
    *argtop = 0;
/*  MODIFY STACK TO INDICATE INTERMEDIATE MACRO. REPROCESSING OF CALLED */
/*  MACRO REQUIRED. */
    goto L350;
L560:
    ii = mcltrm[0] / *modulo;
    *top = 2;
    stack[0] = mcltrm[1];
    stack[2] = mcltrm[1];
    stack[1] = meta[ii - 1];
    stack[3] = meta[ii - 1];
/*  CALL ENCOUNTERED DURING FINAL MACRO PROCESSING. */
    goto L350;
/*  CALLED MACRO A MACRO VARIABLE AND/OR MACRO VARIABLE =MACRO VARIABLE */
/*  IN ARGUMENT LIST. */
L570:
    i__1 = *textst + 1;
    mcxtrn_(&c__2, &i__1, &mctxwd);
    if (mctxwd <= 0) {
	goto L580;
    } else {
	goto L750;
    }
L580:
    i__1 = *textst + 2;
    mcxtrn_(&c__2, &i__1, &mctxwd);
    icrod = -mctxwd;
    *way = 5;
    ii = *textst + 3;
/*  FIRST PASS OF FINAL MACRO PROCESSING IN EFFECT. ALL ELEMENTS OF CALL */
/*  STATEMENT WHICH ARE CALL MACRO VARIABLES ARE PLACED IN ARGSTK FOR */
/*  ANALYSIS TO DETERMINE IF BRANCHING I.L. REQUIRED. */
    if (*finmac) {
	goto L740;
    }
    if (icrod < 0) {
	goto L600;
    }
    argstk[0] = macspd[icrod - 1];
    *argtop = 1;
L600:
    mcxtrn_(&c__2, &ii, &mctxwd);
    if ((i__1 = mctxwd / 100000) < 0) {
	goto L610;
    } else if (i__1 == 0) {
	goto L630;
    } else {
	goto L620;
    }
L610:
    j = -mctxwd + mctxwd / 100000 * 100000;
    ++(*argtop);
    argstk[*argtop - 1] = (i__1 = macspd[j - 1], abs(i__1));
L620:
    ++ii;
    goto L600;
L630:
    ergstk[99] = -(*argtop);
    match_();
/*  BRANCH IF ALL REQUIRED BRANCHING CODE FOR CALL STATEMENT HAS BEEN */
/*  GENERATED. */
    m = *mcstrt;
    if (! (*entry__)) {
	goto L735;
    }
L635:
    if (icrod < 0) {
	goto L640;
    }
    k = m + icrod;
    k = (i__1 = macspd[k - 1], abs(i__1));
    j = 1;
    mactab_(&k, &j);
    goto L650;
/*  COMPRESSED CALL INFORMATION FOR THE CALLED MACRO INVOLVED IN THE */
/*  CURRENT BRANCH IS PLACED IN THE MACHST TABLE. */
L640:
    j = -icrod;
L650:
    *mchstp += 3;
    if (*mchstp <= *mhstdm) {
	goto L655;
    }
L652:
    alarm_(&c__22, &c__0, &c__8, "INPUT   ", (ftnlen)8);
    help_();
L655:
    machst[*mchstp - 3] = *mcsrch;
    machst[*mchstp - 2] = j;
    ++macdf2[j + 1];
    machst[*mchstp - 1] = macdf2[j + 1];
    ii = *textst + 3;
L660:
    mcxtrn_(&c__2, &ii, &mctxwd);
    icrad = mctxwd / 100000 * 100000;
    if (icrad < 0) {
	goto L670;
    } else if (icrad == 0) {
	goto L710;
    } else {
	goto L680;
    }
L670:
    i__ = -mctxwd + icrad + m;
    i__ = (i__1 = macspd[i__ - 1], abs(i__1));
    goto L690;
L680:
    i__ = mctxwd - icrad;
L690:
    k = j + (i__1 = icrad / 100000, abs(i__1));
    if (i__ == macdf2[k + 1]) {
	goto L700;
    }
    ++(*mchstp);
    if (*mchstp > *mhstdm) {
	goto L652;
    }
    machst[*mchstp - 1] = abs(icrad) + i__;
L700:
    ++ii;
    goto L660;
/*  BRANCH IF CALLED MACRO HAS NO MACRO VARIABLES. */
L710:
    k = macdf2[j + 1];
L720:
    if (macdf1[j + 1] == 0) {
	goto L800;
    }
    calmcx_(&macdf1[j - 1], &c__0, &c__2);
/*  GENERATE I.L. CODE WHICH PROVIDES LINKAGE WITH CALLED MACRO. */
    i__1 = -k;
    maclbl_(&macdf1[j - 1], &i__1, &i__);
    nametb_1.namtbl[i__ - 1] = implab[0];
    calmcx_(&i__, mcsavp, &c__1);
L810:
    i__1 = *textst + 1;
    mcxtrn_(&c__2, &i__1, &mctxwd);
    if (mctxwd <= 0) {
	goto L730;
    } else {
	goto L736;
    }
L730:
    if (! (*finmac)) {
	goto L630;
    }
L735:
    mcxtrn_(&c__2, &ii, textst);
/*  SECOND PASS OF FINAL MACRO PROCESSING. */
    goto L551;
L740:
    path_();
/*  BRANCH TO GENERATE CALL I.L. IF NO SUCH CODE WAS GENERATED DURING */
/*  FIRST PASS OF FINAL MACRO PROCESSING. */
    m = *numarg;
    if (*should) {
	goto L635;
    }
L736:
    mcxtrn_(&c__2, &ii, &mctxwd);
    if (mctxwd / 100000 == 0) {
	goto L735;
    }
    ++ii;
    goto L736;
L750:
    ii = *textst + 3;
    if (! (*finmac)) {
	goto L736;
    }
    k = mctxwd;
    i__1 = *textst + 2;
    mcxtrn_(&c__2, &i__1, &j);
/*  GENERATE CALL I.L. FOR MACRO EMPLOYING NO MACRO VARIABLES. */
    goto L720;
L800:
    maclbl_(&c_n1, &macdf1[j - 1], &i__);
    nametb_1.namtbl[i__ - 1] = label[0];
    calmcx_(&i__, mcsavp, &c__1);
    goto L810;
} /* input_ */

#undef textst
#undef lmrstr
#undef ergstk
#undef newstm
#undef mcstrt
#undef errpnt
#undef modulo
#undef vblsav
#undef numarg
#undef mhstdm
#undef mcsavp
#undef mchstp
#undef should
#undef mcltrm
#undef argtop
#undef argstk
#undef number
#undef machst
#undef mcsrch
#undef intmed
#undef callpt
#undef callmv
#undef estack
#undef dlrflg
#undef callon
#undef macspd
#undef implab
#undef mactbl
#undef endflg
#undef finmac
#undef macnam
#undef macred
#undef macsv1
#undef mvpnt
#undef entry__
#undef macdf2
#undef macdf1
#undef rterm
#undef mvseg
#undef slash
#undef stack
#undef label
#undef meta
#undef top
#undef way


