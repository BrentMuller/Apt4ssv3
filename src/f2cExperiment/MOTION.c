/* MOTION.f -- translated by f2c (version 20100827).
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
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

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
    integer comp26[16];
} comp26_;

#define comp26_1 comp26_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2020 = 2020;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__2022 = 2022;
static integer c__14 = 14;
static integer c__4 = 4;
static integer c__2023 = 2023;
static integer c__83 = 83;
static integer c__2024 = 2024;

/* *** SOURCE FILE : M0006657.V06   *** */


/*              FORTRAN SUBROUTINE MOTION */

/* LINKAGE       SUBROUTINE MOTION */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CALLZZ          SUBROUTINE    PRO026 */
/*          SUBROUTINE    BCDBIN */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    MCXTRN */
/*          INTEGER FCT.  MODE */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    ALARM */

/* Subroutine */ int motion_(void)
{
    /* Initialized data */

    static char itanto[6] = "TANTO ";

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__;
#define k ((integer *)&comp26_1 + 11)
    static integer l, kk;
#define to ((integer *)&bcdptr_1 + 2)
#define vbl ((integer *)&code_1 + 60)
    extern integer name_(char *, ftnlen);
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define lerr ((integer *)&comp26_1 + 12)
#define temp ((integer *)&code_1 + 32)
#define test ((integer *)&comp26_1 + 5)
#define apt200 ((integer *)&sublst_1 + 126)
#define apt201 ((integer *)&sublst_1 + 127)
#define apt299 ((integer *)&sublst_1 + 130)
#define test1 ((integer *)&comp26_1 + 6)
#define label ((integer *)&code_1 + 42)
#define dotac ((integer *)&bcdptr_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define jmpcs ((integer *)&comp26_1 + 3)
#define intof ((integer *)&comp26_1)
#define nlast ((integer *)&ntbl_1 + 3)
#define onept ((integer *)&numptr_1 + 3)
#define error ((integer *)&sublst_1 + 131)
    static integer errpt;
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen),
	     maclbl_(integer *, integer *, integer *);
#define dbldlr ((integer *)&opmod_1 + 2)
#define implab ((integer *)&code_1 + 44)
#define fedrat ((integer *)&bcdptr_1 + 1)
#define fedsav ((logical *)&comp26_1 + 7)
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define tagtbl ((integer *)&comp26_1 + 13)
#define permid ((integer *)&code_1 + 38)
#define whchmn ((integer *)&macxx1_1 + 62)
#define jmping ((logical *)&comp26_1 + 10)
#define vbljmp ((integer *)&il_1 + 19)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define mcsjmp ((logical *)&comp26_1 + 9)
#define modulo ((integer *)&moduli_1)
#define quidlr ((integer *)&opmod_1 + 5)
#define fmterr ((logical *)&comp26_1 + 8)
#define argcnt ((integer *)&comp26_1 + 1)
#define numbcs ((integer *)&comp26_1 + 4)
    extern /* Subroutine */ int callzz_(integer *);
#define cspntr ((integer *)&comp26_1 + 2)
    extern /* Subroutine */ int twoarg_(integer *, integer *), argcvt_(
	    integer *), rlslin_(void), mcxtrn_(integer *, integer *, integer *
	    );
    static integer idummy, icount;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTAC:       NAMTBL POINTER TO ALPHAMERIC LITERAL '.AC.' */
/* FEDRAT:      NAMTBL POINTER TO ALPHAMERIC LITERAL 'FEDRAT' */
/* TO:          NAMTBL POINTER TO ALPHAMERIC LITERAL 'TO' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ONEPT:       NAMTBL POINTER TO '1.    ' */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* VBLJMP:      CONTAINS COMMAND CODE (20) FOR VBLJMP COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (24) FOR A SCALAR */

/*       22.    MACRO PROCESSING VARIABLES */

/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */

/*       27.    OPERAND MODIFIERS */

/* DBLDLR:      CONTAINS OPERAND TYPE CODE 2 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APT200:      NAMTBL POINTER FOR APT200 */
/* APT201:      NAMTBL POINTER FOR APT201 */
/* APT299:      NAMTBL POINTER FOR APT299 */
/* ERROR:       NAMTBL POINTER TO EXECUTION SUBROUTINE ERROR */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       31.    COMMON BLOCK FOR PRO026 AND MOTION */

/* INTOF:       DESIRED DS AND CS INTERSECTION IN MULTIPLE INTERS. CASE */
/* ARGCNT:      POINTER FOR CURRENT ARGSTK ELEMENT */
/* CSPNTR:      CONTAINS NAMTBL POINTER TO CS */
/* JMPCS:       TAGTBL POINTER */
/* NUMBCS:      NUMBER OF CHECK SURFACES */
/* TEST:        NAMTBL INDEX OF CURRENT ARGUMENT */
/* TEST1:       CLASS OF CURRENT ARGUMENT */
/* FEDSAV:      INDICATES FINAL ARGUMENT MAY BE A FEEDRATE SPECIFICATION */
/* FMTERR:      ERROR FLAG FOR CERTAIN MOTION STATEMENTS */
/* MCSJMP:      MULTIBLE CHECK SUBTRACT INDICATOR */
/* JMPING:      INDICATES LABEL POINTER ADDED TO TAGTBL */
/* K:           NAMTBL POINTER TO MAJOR WORD */
/* LERR:        ERROR TYPE INDICATOR */
/* TAGTBL:      NAMTBL POINTERS TO LABELS USED AT MULTIBLE CHECK SURFACE */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/* ** */
/* ...     GOFWD, GOBACK, GOUP, GODOWN, GOLFT, OR GORGT / ...... */
/* ...     INITIALISE CHECK SURFACE COUNT. */

/* L1901: */
    *numbcs = 0;

/* ...     INITIALIZE MULTIPLE CHECK SURFACE EXISTENCE FLAG. */

    *mcsjmp = FALSE_;
    *fmterr = FALSE_;
    *intof = 0;
    *lerr = 0;
    if (mode_(argstk) != *real__) {
	goto L13;
    }
    *test = argstk[0];
    if (*test <= nametb_1.nammax) {
	goto L11;
    }
/* ...  MAY BE A FEDRAT SPECIFICATION */
    *test = argstk[1];
    if (*test > nametb_1.nammax) {
	goto L11;
    }
    i__ = nametb_1.namtbl[*test - 1] / *modulo;
    if (i__ != vbl[0] / *modulo && i__ != temp[0] / *modulo) {
	goto L11;
    }
/* ...  RESERVE JUDGEMENT */
    *fedsav = TRUE_;
    *argcnt = 2;
    *jmpcs = 1;
    goto L16;
/* ...  NO FEDRAT SPECIFICATION IN THIS STATEMENT */
L13:
    *argcnt = 1;
    goto L15;
/* ...  FEDRAT SPECIFICATION */
L11:
    *argcnt = 2;
L14:
    callzz_(apt299);
    twoarg_(quidlr, &c__1);
    twoarg_(dbldlr, fedrat);
    twoarg_(quidlr, &c__1);
    argcvt_(argstk);
    rlslin_();
L15:
    *fedsav = FALSE_;
    *jmpcs = 1;
L16:
    if ((i__1 = *argtop - *argcnt) < 0) {
	goto L17;
    } else if (i__1 == 0) {
	goto L18;
    } else {
	goto L68;
    }
L17:
    i__1 = -(*argtop);
    alarm_(&c__2020, &i__1, &c__8, "MOTION  ", (ftnlen)8);
    *lerr = -1;
    goto L900;
L18:
    if (! (*fedsav)) {
	goto L19;
    }
    if (*numbcs <= 1) {
	goto L14;
    }
/* ...  TWO OR MORE CHECK SURFACES HAVE BEEN COUNTED */
    tagtbl[0] = argstk[0];
    *jmpcs = 1;
/* ...  CHECK MODE OF DRIVE SURFACE FOR ACCEPTABILITY */
L19:
    *test = mode_(&argstk[*argcnt - 1]);
    errpt = -(*argcnt);
    if ((*test < 1 || *test > 17) && (*test < 29 || *test > 30)) {
	goto L17;
    }
/* ...  RELEASE DRIVE SURFACE CALL TO ARELEM STACK */
/* L20: */
    callzz_(apt201);
    argcvt_(&argstk[*argtop - 1]);
    argcvt_(k);
    if (*mcsjmp) {
	goto L21;
    }
L900:
    return 0;
/* ...  THE JUMP TABLE (TAGTBL) MUST BE DUMPED FOR PROPER RETURN */
L21:
    rlslin_();
/* L23: */
    opcode_(vbljmp);
    argcvt_(dotac);
    i__1 = *numbcs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*test = tagtbl[*jmpcs - 1];
/* L6003: */
	if (*test > nametb_1.nammax) {
	    goto L6005;
	}
	if (*whchmn != 0) {
	    goto L6002;
	}
	goto L6006;
/*     DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L6005:
	*test -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, test, &idummy);
	}
	bcdbin_(cnamtb_1.cnumtb + (*test - 1) * 12, &kk, &icount, (ftnlen)12);
	*test = kk + 10000;
L6002:
	i__2 = -(*whchmn);
	maclbl_(test, &i__2, test);
	if (nametb_1.namtbl[*test - 1] == 0) {
	    nametb_1.namtbl[*test - 1] = implab[0] + *whchmn;
	}
L6006:
	onearg_(test);
	++(*jmpcs);
/* L24: */
    }
    goto L900;
/* ...  EVALUATE CHECK SURFACE EXPRESSSION */
/*     IS THE LAST ITEM A SURFACE NAME */
L68:
    *test = mode_(&argstk[*argcnt - 1]);
    if ((*test < 1 || *test > 17) && (*test < 29 || *test > 30)) {
	goto L78;
    }
/* ...  THE LAST ITEM IS THE NAME OF A SURFACE */
    *cspntr = argstk[*argcnt - 1];
/* ...  ADVANCE ARGUMENT STACK POINTER */
L50:
    ++(*argcnt);
/* ...  COMPUTE NAMTBL INDEX OF NEXT ITEM */
L69:
    *test = argstk[*argcnt - 1];
/* ...  WHAT ARE THE MODIFIERS FOR THIS CHACK SURFACE */
/*     IS THE NEXT ITEM A PERMANENT IDENTIFIER */
    if (*test > nametb_1.nammax) {
	goto L71;
    }
    if (nametb_1.namtbl[*test - 1] / *modulo != permid[0] / *modulo) {
	goto L71;
    }
/* ...  YES, IS IT DEFINED FOR THIS FORMAT */
    l = nametb_1.namtbl[*test - 1] - permid[0];
    if (l >= *modhlf) {
	l -= *modhlf;
    }
    if (l == 6) {
	goto L73;
    }
    if (l == 3 || l == 4 || l == 147) {
	goto L6004;
    }
/* ...  NO MATCH FOR THIS ITEM IN DEFINED LIST */
/*     SET CHECK SURFACE MODIFIER FOR TO STOPPING POSSITION */
L71:
    *test = 0;
    goto L74;
/* ...  TEST FOR MULTIPLE CHECK SURFACE TAG, SINCE LAST ITM IS NOT SFC */
L78:
    *test = argstk[*argcnt - 1];
/* ...  IS IT A NUMBER */
/* ...  IF IT IS DO NOT CHANGE MODE */
    if (*test > nametb_1.nammax) {
	goto L81;
    }
    *test1 = *modulo * (nametb_1.namtbl[*test - 1] / *modulo);
/* ...  IS THE LAST ITEM A LABEL OR IMPLIED LABEL */
    if (*test1 == label[0] || *test1 == implab[0]) {
	goto L81;
    }
/* ...  IS IT A PERMANENT IDENTIFIER */
    if (*test1 == permid[0]) {
	goto L80;
    }
/* )..  FORMAT IS NOT-SFC,ID OR SFC. */
    i__1 = -(*argcnt);
    alarm_(&c__2022, &i__1, &c__8, "MOTION  ", (ftnlen)8);
    *fmterr = TRUE_;
/* ...  IGNORE THE UNACCEPTABLE ITEM */
    goto L50;
/* ...  CHANGE THE MODE ASSIGNMENT */
L80:
    if (*jmping) {
	goto L88;
    }
    nametb_1.namtbl[*test - 1] = implab[0];
/* ...  ITEM QUALIFIES AS A LABEL OF SOME KIND */
/*     COMPUTE JMPTBL INDEX,ALLOWING FOR FEDSAV ACTION */
L81:
    i__ = *numbcs + *jmpcs;
    if (i__ > 3) {
	i__1 = -(*argcnt);
	alarm_(&c__14, &i__1, &c__4, "MOTION  ", (ftnlen)8);
    }
/* ...  VERIFY WE CAN WRITE INTO TAG TABLE FOR THIS CHECK SURFACE */
    if (*jmping) {
	goto L88;
    }
    tagtbl[i__ - 1] = *test;
    *mcsjmp = TRUE_;
/* ...  INDICATE TAG ADDED TO TAGTBL */
    *jmping = TRUE_;
    ++(*argcnt);
/* ...  GO BACK TO FIND THE ASSOCIATED CHECK SURFACE */
    goto L68;
/* ...  PERMID DEFINED FOR THIS FORMAT, IS IT INTOF */
/* ...  NO, PICK UP MODIFIER AS HMOD */
L6004:
    ++(*argcnt);
/* ...  HAVE WE PASSED THROUGH WITHOUT ERROR */
L74:
    if (*fmterr) {
	goto L75;
    }
/* ...  YES, FORMAT SEEMS OK */
    ++(*numbcs);
/* ...  SET UP INTERMEDIATE LANGUAGE CALL FOR THIS CHECK SURFACE */
    callzz_(apt200);
    if (*test <= 0) {
	goto L6007;
    } else {
	goto L6008;
    }
L6007:
    i__ = *to;
    goto L6016;
L6008:
    if (l != 147) {
	goto L6015;
    }
    i__ = name_(itanto, (ftnlen)6);
L6016:
    twoarg_(dbldlr, &i__);
    goto L6009;
L6015:
    argcvt_(test);
L6009:
    argcvt_(cspntr);
    if (*intof <= 0) {
	goto L6010;
    } else {
	goto L6011;
    }
L6010:
    argcvt_(onept);
    goto L77;
L6011:
    argcvt_(intof);
/* ...  RESTORE NORMAL SEETTING FOR INTOF */
L77:
    *intof = 0;
/* ...  ENTER IN ARELEM STACK */
    rlslin_();
/* ...  SHOW TAG MATCHED WITH CHECK SURFACE */
    *jmping = FALSE_;
/* ,..  CHECK TO SEE IF THERE ARE ANY MORE CHECK SURFACES */
    goto L16;
L88:
    i__1 = 1 - *argcnt;
    alarm_(&c__2023, &i__1, &c__8, "MOTION  ", (ftnlen)8);
    *lerr = -1;
    *jmping = FALSE_;
    goto L900;
/* ...  A FORMAT ERROR WAS DETECTED, REQUIRING ARELEM RESTART. */
L75:
    *fmterr = FALSE_;
    callzz_(error);
    twoarg_(quidlr, &c__83);
    goto L77;
/* ...  INTOF MODIFIER DETECTED */
L73:
    *test = argstk[*argcnt];
    if (mode_(test) != *real__) {
	goto L76;
    }
/* ...  SPECIFICATION NOT A NUMBER OR SCALAR */
/* L85: */
    *intof = *test;
    *argcnt += 2;
/* ...  CHECK FOR OTHER MODIFIERS */
    goto L69;
/* ...  ERROR IN INTOF FORMAT, WARNING ONLY */
L76:
    i__1 = -(*argcnt) - 1;
    alarm_(&c__2024, &i__1, &c__4, "MOTION  ", (ftnlen)8);
/* ...  FMTERR WOULD BE SET HERE IF ARELEM RESTART WERE DESIRED. */
    goto L50;
} /* motion_ */

#undef cspntr
#undef numbcs
#undef argcnt
#undef fmterr
#undef quidlr
#undef modulo
#undef mcsjmp
#undef argtop
#undef argstk
#undef vbljmp
#undef jmping
#undef whchmn
#undef permid
#undef tagtbl
#undef modhlf
#undef fedsav
#undef fedrat
#undef implab
#undef dbldlr
#undef error
#undef onept
#undef nlast
#undef intof
#undef jmpcs
#undef dotac
#undef label
#undef test1
#undef apt299
#undef apt201
#undef apt200
#undef test
#undef temp
#undef lerr
#undef real__
#undef vbl
#undef to
#undef k


