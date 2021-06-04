/* BOOLIF.f -- translated by f2c (version 20100827).
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
    integer doloop[9];
} doloop_;

#define doloop_1 doloop_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__1008 = 1008;
static integer c__8 = 8;
static integer c__7 = 7;
static integer c__9 = 9;
static integer c__1007 = 1007;

/* *** SOURCE FILE : M0006624.W03   *** */


/*              FORTRAN SUBROUTINE BOOLIF */

/* LINKAGE      SUBROUTINE  BOOLIF(PROD) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    RECOG */
/*          SUBROUTINE    MACLBL          SUBROUTINE    INPUT */
/*          LOGICAL FCT.  IFTMP */
/*          INTEGER FCT.  MODE */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    LABELZ */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int boolif_(integer *prod)
{
    /* Initialized data */

    static integer kk = 20000;
    static integer lastmn = -1;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, l, jj, tp;
#define and ((integer *)&code_1 + 56)
    static integer lbl, art;
#define top ((integer *)&stklst_1)
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define meta ((integer *)&srctbl_1 + 2)
#define bool ((integer *)&modx_1 + 22)
    static integer rslt;
#define label ((integer *)&code_1 + 42)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define logif ((integer *)&sublst_1 + 103)
#define stack ((integer *)&stklst_1 + 3)
#define relat ((integer *)&code_1 + 52)
    extern logical iftmp_(integer *);
    static integer lgstk[50];
#define ifflag ((logical *)&doloop_1 + 8)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define finmac ((logical *)&macxx1_1 + 23)
#define implab ((integer *)&code_1 + 44)
    static logical bolflg;
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int labelz_(integer *), opcode_(integer *), 
	    onearg_(integer *);
#define whchmn ((integer *)&macxx1_1 + 62)
#define conjmp ((integer *)&il_1 + 10)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)
#define quidlr ((integer *)&opmod_1 + 5)
#define ergstk ((integer *)&errpos_1 + 202)
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int callzz_(integer *), argcvt_(integer *), 
	    twoarg_(integer *, integer *), rlslin_(void);
    static integer mseqdm;
#define jumpto ((integer *)&doloop_1)



/*              FUNCTION DECLARATION */

/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* RELAT:       (1)=CODE CLASS 27000,(2)=NAMTBL INDEX OF 'RELAT ' */
/* AND:         (1)=CODE CLASS 29000,(2)=NAMTBL INDEX OF 'AND   ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* CONJMP:      CONTAINS COMMAND CODE (11) FOR CONJMP COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR A SCALAR */
/* BOOL:        MODE CODE (23) FOR BOOLEAN */

/*       22.    MACRO PROCESSING VARIABLES */

/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */

/*       27.    OPERAND MODIFIERS */

/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* LOGIF:       NAMTBL POINTER TO EXECUTION SUBROUTINE RELAT */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       43.    DO LOOP CONTROL VALUES */

/* JUMPTO:      MARKER SET AFTER JUMPTO OR IF FOR LABEL CONTROL */
/* IFFLAG:      FLAG ON WHEN LOGICAL IF OCCURS */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* ** */
    if (*prod > 0) {
	goto L5;
    }
    if (lastmn != *whchmn) {
	goto L300;
    }
    *ifflag = FALSE_;
    lastmn = -1;
    labelz_(&lbl);
    *jumpto = 0;
    goto L300;

L5:
    if (*argtop == 0) {
	bolflg = FALSE_;
    }
    switch (*prod) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L50;
	case 4:  goto L70;
	case 5:  goto L70;
    }

/*     PRODUKTION 34:  ALL $ VBL $ NOT */

L10:
    k = stack[(*top - 1 << 1) - 2];
    if (iftmp_(&k)) {
	goto L310;
    }
    if (nametb_1.namtbl[k - 1] % *modhlf != *bool) {
	i__1 = *top - 1;
	alarm_(&c__1008, &i__1, &c__8, "BOOLIF  ", (ftnlen)8);
    }
    rslt = gettmp_(bool);
    callzz_(logif);
    argcvt_(&rslt);
    twoarg_(quidlr, &c__7);
    argcvt_(&k);
    argcvt_(&k);
    ++(*argtop);
    argstk[*argtop - 1] = rslt;
    bolflg = TRUE_;
    stack[(*top - 2 << 1) - 2] = rslt;
    stack[(*top - 2 << 1) - 1] = meta[nametb_1.namtbl[rslt - 1] / *modulo - 1]
	    ;
    stack[(*top - 1 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top << 1) - 1];
    ergstk[*argtop - 1] = estack[*top - 2];
    --(*top);
    goto L40;

/*     PRODUKTION 35: ALL $ VBL,TEMP,NUMBER $ RELAT $ VBL,TEMP,NUMBER */

L20:
    for (i__ = 1; i__ <= 3; i__ += 2) {
	j = mode_(&stack[(*top - i__ << 1) - 2]);
/* L30: */
	if (j != *real__) {
	    i__1 = *top - i__;
	    alarm_(&c__1008, &i__1, &c__8, "BOOLIF  ", (ftnlen)8);
	}
    }
    art = nametb_1.namtbl[stack[(*top - 2 << 1) - 2] - 1] - relat[0];
    rslt = gettmp_(bool);
    callzz_(logif);
    argcvt_(&rslt);
    twoarg_(quidlr, &art);
    argcvt_(&stack[(*top - 3 << 1) - 2]);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    ++(*argtop);
    argstk[*argtop - 1] = rslt;
    bolflg = TRUE_;
    stack[(*top - 3 << 1) - 2] = rslt;
    stack[(*top - 3 << 1) - 1] = meta[nametb_1.namtbl[rslt - 1] / *modulo - 1]
	    ;
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    ergstk[*argtop - 1] = estack[*top - 3];
    *top += -2;
L40:
    rlslin_();
    goto L300;

/*     PRODUKTION 36:  ALL $ VBL,TEMP $ AND,OR $ VBL,TEMP */

L50:
    if (bolflg) {
	goto L60;
    }
    k = stack[(*top - 1 << 1) - 2];
    if (nametb_1.namtbl[k - 1] % *modhlf != *bool) {
	i__1 = *top - 1;
	alarm_(&c__1008, &i__1, &c__8, "BOOLIF  ", (ftnlen)8);
    }
    ++(*argtop);
    argstk[*argtop - 1] = stack[(*top - 1 << 1) - 2];
    ergstk[*argtop - 1] = estack[*top - 2];
L60:
    bolflg = FALSE_;
    ++(*argtop);
    argstk[*argtop - 1] = stack[(*top - 2 << 1) - 2];
    ergstk[*argtop - 1] = estack[*top - 3];
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    goto L300;

/*     PRODUKTION 32:    ( $ VBL,TEMP,NUMBER $ ) $ IF $ LTERM */
/*     PRODUKTION 23,24: RTERM $ VBL,TEMP,NUMBER  $ = ....... */

L70:
    if (bolflg) {
	goto L80;
    }
    ++(*argtop);
    argstk[*argtop - 1] = stack[(*top - 1 << 1) - 2];
    ergstk[*argtop - 1] = estack[*top - 2];
    bolflg = TRUE_;
L80:
    rslt = stack[(*top - 1 << 1) - 2];
    if (*argtop <= 1) {
	goto L200;
    }
    art = and[0] / *modulo;
    tp = 0;
    i__ = 0;
L100:
    rslt = 0;
/* L110: */
    i__ += 2;
    if (i__ >= *argtop) {
	goto L170;
    }
    k = argstk[i__ - 1];
    l = argstk[i__ - 2];
    if (nametb_1.namtbl[k - 1] / *modulo == art) {
	goto L130;
    }
    if (! bolflg) {
	goto L120;
    }
    ++tp;
    lgstk[tp - 1] = l;
L120:
    bolflg = TRUE_;
    goto L100;

/*     HANDLING OF OTHER TEMPORARY RESULTS IN STACK */

L130:
    j = argstk[i__];
    if (rslt > 0) {
	goto L150;
    }
    if (iftmp_(&l)) {
	rslt = l;
    }
    if (rslt > 0) {
	goto L140;
    }
    if (iftmp_(&j)) {
	rslt = j;
    }
    if (rslt > 0) {
	goto L140;
    }
    rslt = gettmp_(bool);
L140:
    ++tp;
    lgstk[tp - 1] = rslt;
    callzz_(logif);
    argcvt_(&rslt);
    twoarg_(quidlr, &c__9);
    argcvt_(&j);
    argcvt_(&l);
    goto L160;
L150:
    callzz_(logif);
    argcvt_(&rslt);
    twoarg_(quidlr, &c__9);
    argcvt_(&rslt);
    argcvt_(&j);
L160:
    rlslin_();
    bolflg = FALSE_;
    goto L100;

L170:
    if (! bolflg) {
	goto L180;
    }
    ++tp;
    lgstk[tp - 1] = argstk[*argtop - 1];

/*    PROCESSING OF OR */

L180:
    rslt = lgstk[0];
    if (tp == 2) {
	goto L200;
    }
    k = rslt;
    if (iftmp_(&rslt)) {
	goto L185;
    }
    rslt = gettmp_(bool);
L185:
    i__1 = tp;
    for (i__ = 2; i__ <= i__1; ++i__) {
	callzz_(logif);
	argcvt_(&rslt);
	twoarg_(quidlr, &c__8);
	argcvt_(&k);
	argcvt_(&lgstk[i__ - 1]);
	rlslin_();
/* L190: */
	k = rslt;
    }

/*     WORKING UP OF IF(BOOL) LAB1,LAB1,LAB2 */

L200:
    if (*prod != 5) {
	goto L210;
    }
    stack[(*top - 1 << 1) - 2] = rslt;
    stack[(*top - 1 << 1) - 1] = meta[nametb_1.namtbl[rslt - 1] / *modulo - 1]
	    ;
    goto L300;
L210:
    opcode_(conjmp);
    argcvt_(&rslt);
    l = *whchmn;
    if (l == 0) {
	l = mseqdm + 3;
    }
    kk += 50000;
    i__1 = -l;
    maclbl_(&kk, &i__1, &jj);
    nametb_1.namtbl[jj - 1] = jj;
    kk += 50000;
    i__1 = -l;
    maclbl_(&kk, &i__1, &k);
    if (! (*finmac) && *whchmn != 0) {
	goto L220;
    }
    nametb_1.namtbl[jj - 1] = label[0] + *whchmn;
    nametb_1.namtbl[k - 1] = label[0] + *whchmn;
    goto L230;

/*     WORKING UP OF IF-LABELS */

L220:
    nametb_1.namtbl[jj - 1] = implab[0] + *whchmn;
    nametb_1.namtbl[k - 1] = implab[0] + *whchmn;
L230:
    onearg_(&jj);
    onearg_(&jj);
    onearg_(&k);
    rlslin_();
    labelz_(&k);
    if (*ifflag) {
	goto L290;
    }
    lbl = jj;
    lastmn = *whchmn;
    *ifflag = TRUE_;
L290:
    bolflg = FALSE_;
    *top = 0;
L300:
    return 0;

L310:
    i__1 = *top - 1;
    alarm_(&c__1007, &i__1, &c__8, "BOOLIF  ", (ftnlen)8);
    *top = -1;
    goto L300;

} /* boolif_ */

#undef jumpto
#undef ergstk
#undef quidlr
#undef modulo
#undef argtop
#undef argstk
#undef number
#undef conjmp
#undef whchmn
#undef estack
#undef modhlf
#undef implab
#undef finmac
#undef ifflag
#undef relat
#undef stack
#undef logif
#undef label
#undef bool
#undef meta
#undef real__
#undef top
#undef and


