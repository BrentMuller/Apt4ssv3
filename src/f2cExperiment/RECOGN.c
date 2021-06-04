/* RECOGN.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

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
    integer canstr[18];
} canstr_;

#define canstr_1 canstr_

/* Table of constant values */

static integer c__8 = 8;
static integer c__19 = 19;
static integer c__1024 = 1024;
static integer c__2032 = 2032;
static integer c__0 = 0;
static integer c__2013 = 2013;
static integer c__4 = 4;
static integer c__1001 = 1001;
static integer c__1 = 1;
static integer c__50 = 50;
static integer c__18 = 18;
static integer c__1050 = 1050;

/* *** SOURCE FILE : M0006673.V06   *** */


/*              FORTRAN SUBROUTINE RECOGN */

/* LINKAGE      SUBROUTINE RECOGN(I,IASNRT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    MACLBL          SUBROUTINE    RECOG */
/*          SUBROUTINE    ARGCVT */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    REFGEN */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    SETMOD */
/*          LOGICAL FCT.  IFTMP */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int recogn_(integer *i__, integer *iasnrt)
{
    /* Initialized data */

    static logical canflg = FALSE_;
    static integer stmtyp = 0;
    static integer candat = 0;
    static char ppoint[6] = "POINT ";

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, k, l, n, n5, ii, jj, kk, ir, tp, iii, kkk;
#define one ((integer *)&numptr_1 + 2)
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
#define two ((integer *)&numptr_1 + 4)
    extern integer name_(char *, ftnlen);
    static integer modc;
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
    static integer iref;
#define meta ((integer *)&srctbl_1 + 2)
#define geom ((integer *)&code_1 + 30)
#define five ((integer *)&numptr_1 + 7)
#define repl ((integer *)&il_1 + 16)
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define four ((integer *)&numptr_1 + 6)
#define zero ((integer *)&numptr_1)
    static integer canch;
#define range ((integer *)&sbscpt_1 + 1)
#define canon ((integer *)&code_1 + 82)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
#define three ((integer *)&numptr_1 + 5)
    static integer index;
#define slash ((integer *)&code_1 + 8)
    extern logical iftmp_(integer *);
#define point ((integer *)&modx_1 + 18)
#define rngpt ((integer *)&sbscpt_1)
#define canchk ((integer *)&canstr_1 + 1)
    static integer canend;
#define biggeo ((integer *)&code_1 + 86)
    static integer cannam;
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define conbig ((integer *)&code_1 + 84)
#define refflg ((logical *)&flags_1 + 3)
    static integer canmax;
    extern /* Subroutine */ int refgen_(integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
#define congeo ((integer *)&code_1 + 76)
    static integer canerr;
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define intmed ((integer *)&macxx1_1 + 21)
#define canstk ((integer *)&canstr_1 + 2)
    static logical errflg;
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define rldsrf ((integer *)&modx_1 + 11)
#define conpro ((integer *)&code_1 + 78)
#define quidlr ((integer *)&opmod_1 + 5)
#define modulo ((integer *)&moduli_1)
#define canptr ((integer *)&canstr_1)
#define trpdlr ((integer *)&opmod_1 + 3)
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int setmod_(integer *, integer *);
    static integer refsav;
    extern /* Subroutine */ int callzz_(integer *), argcvt_(integer *), 
	    twoarg_(integer *, integer *), rlslin_(void);
    static integer cantmp;
    extern /* Subroutine */ int puttmp_(integer *), resrvz_(integer *, 
	    integer *, integer *, integer *);
#define aptxxx ((integer *)&sublst_1)



/*              FUNCTION DECLARATION */


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

/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/* CONGEO:      (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO' */
/* CONPRO:      (1)=CODE CLASS 40000,(2)=NAMTBL INDEX OF 'CONPRO' */
/* CONBIG:      (1)=CODE CLASS 43000,(2)=NAMTBL INDEX OF 'CONBIG' */
/* CANON:       (1)=CODE CLASS 42000,(2)=NAMTBL INDEX OF 'CANON ' */
/* BIGGEO:      (1)=CODE CLASS 44000,(2)=NAMTBL INDEX OF 'BIGGEO' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* REFFLG:      TRUE WHEN A REFSYS COMMAND ENCOUNTERED */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ONE:         NAMTBL POINTER TO '1     ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* THREE:       NAMTBL POINTER TO '3     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */
/* FIVE:        NAMTBL POINTER TO '5     ' */

/*       15.    ARRAY LIMIT STORAGE */

/* RNGPT:       POINTER TO NEXT RANGE ENTRY */
/* RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* RLDSRF:      MODE CODE (12) FOR RULED SURFACE */
/* POINT:       MODE CODE (19) FOR POINT */
/* REAL:        MODE CODE (24) FOR A SCALAR */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */

/*       27.    OPERAND MODIFIERS */

/* TRPDLR:      CONTAINS OPERAND TYPE CODE 3 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE */

/* CANPTR:      POINTER TO LAST CANSTK ENTRY */
/* CANCHK:      CONTAINS DIMENSION OF ARRAY CANSTK */
/* CANSTK:      ARGUMENT STACK FOR CANON AND OBTAIN STATEMENTS */
/* * */
/* ARGUMENTS    I       CURRENT PRODUCTION NUMBER */
/*              IASNRT  INTEGER USED BY RECOG TO BRANCH TO THE */
/*              APPROPRIATE CODING AFTER RETURN FROM RECOGN */

/* ** */
    index = *i__ - 40;
    switch (index) {
	case 1:  goto L4100;
	case 2:  goto L4200;
	case 3:  goto L4300;
	case 4:  goto L4400;
	case 5:  goto L4500;
	case 6:  goto L4600;
	case 7:  goto L4700;
	case 8:  goto L4800;
	case 9:  goto L4900;
    }

/* ...  STORE NEXT ELEMENT */

L4100:
    n5 = stack[(*top - 5 << 1) - 2];
    if (*canptr != 0) {
	goto L4150;
    }
    j = nametb_1.namtbl[n5 - 1] - geom[0];
    if (j == *rldsrf) {
	goto L4110;
    }
    j -= *modhlf;
    if (j != *rldsrf) {
	goto L4150;
    }
L4110:
    n5 = gettmp_(rldsrf);
    nametb_1.namtbl[n5 - 1] = biggeo[0] + j;
    stack[(*top - 5 << 1) - 2] = n5;
    j = biggeo[0] / *modulo;
    stack[(*top - 5 << 1) - 1] = meta[j - 1];
    goto L220;
L4150:
    ++(*canptr);
    ++candat;
    if (*canptr == 1) {
	goto L4175;
    }
L4155:
    if (*canptr != canerr) {
	goto L4156;
    }
    i__1 = *top - 1;
    alarm_(&iii, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
    goto L4403;
L4156:
    if (*canptr <= *canchk) {
	goto L4160;
    }
    if (*canptr == canch) {
	i__1 = *top - 1;
	alarm_(&c__19, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
    }
    goto L4170;
L4160:
    j = stack[(*top - 1 << 1) - 2];
    kk = mode_(&j);
    if (stmtyp != 3) {
	goto L4161;
    }
    if (j > nametb_1.nammax) {
	goto L4172;
    }
    jj = nametb_1.namtbl[j - 1] / *modulo * *modulo;
    if (jj != vbl[0] && jj != temp[0]) {
	goto L4165;
    }
L4161:
    if (kk != *real__) {
	goto L4172;
    }
L4165:
    canstk[*canptr - 1] = stack[(*top - 1 << 1) - 2];
L4170:
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    goto L220;
L4172:
    i__1 = *top - 1;
    alarm_(&kkk, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
    errflg = TRUE_;
    switch (index) {
	case 1:  goto L4165;
	case 2:  goto L4212;
    }

/* ...  STORE NEGATIVE MODIFIER */

L4200:
    ++(*canptr);
    if (*canptr == 1) {
	goto L4175;
    }
L4205:
    if (*canptr != canmax) {
	goto L4206;
    }
L4207:
    alarm_(&iii, top, &c__8, "RECOGN  ", (ftnlen)8);
    goto L4403;
L4206:
    if (*canptr <= *canchk) {
	goto L4210;
    }
    if (*canptr == canch) {
	alarm_(&c__19, top, &c__8, "RECOGN  ", (ftnlen)8);
    }
    goto L4220;
L4210:
    if (stmtyp == 1) {
	goto L4230;
    }
L4212:
    canstk[*canptr - 1] = -(*canptr);
L4220:
    stack[(*top - 1 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top << 1) - 1];
    --(*top);
    goto L220;
L4230:
    iii = 1008;
    goto L4207;

L4175:
    tp = *top - 6 + index;
    errflg = FALSE_;
    if (stack[(tp + 1 << 1) - 2] == slash[1]) {
	goto L4180;
    }
    tp += -2;
    stmtyp = 2;
    goto L4185;
L4180:
    stmtyp = 3;
    if (nametb_1.namtbl[stack[(tp + 2 << 1) - 2] - 1] == canon[0]) {
	stmtyp = 1;
    }
L4185:
    modc = nametb_1.namtbl[stack[(tp << 1) - 2] - 1] % *modhlf;
    canmax = tmp_1.txxxx[(modc << 1) - 2];
    canerr = canmax + 1;
    canch = *canchk + 1;
    iii = 2032;
    kkk = 2033;
    if (stmtyp != 3) {
	goto L4190;
    }
    iii = 1035;
    kkk = 2051;
L4190:
    switch (index) {
	case 1:  goto L4155;
	case 2:  goto L4205;
    }

/* ...  REMOVE VARIABLE NAME FROM CANON DEFINITION */

L4300:
    cannam = stack[(*top - 3 << 1) - 2];
    j = stack[(*top - 5 << 1) - 2];
    jj = mode_(&cannam);
    modc = nametb_1.namtbl[j - 1] % *modulo;
    if (jj == modc) {
	goto L4301;
    }
    i__1 = *top - 3;
    alarm_(&c__1024, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
    goto L4403;
L4301:
    canflg = TRUE_;
    canmax = tmp_1.txxxx[(modc << 1) - 2];
    stack[(*top - 3 << 1) - 2] = stack[(*top - 1 << 1) - 2];
    stack[(*top - 3 << 1) - 1] = stack[(*top - 1 << 1) - 1];
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    *top += -2;
    goto L220;

/* ...  END OF CANON DEFINITION STATEMENT */

L4400:
    canend = 1;
L4401:
    if (errflg) {
	goto L4403;
    }
    if (*argtop > 0) {
	goto L4415;
    }
    if (stmtyp == 2 || candat == canmax) {
	goto L4411;
    }
    if (candat == 0) {
	goto L4416;
    }
/* L4402: */
    alarm_(&c__2032, &c__0, &c__8, "RECOGN  ", (ftnlen)8);
    goto L4403;
L4415:
    i__1 = -(*argtop);
    alarm_(&c__2013, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
    goto L4403;
L4416:
    alarm_(&c__2032, &c__0, &c__4, "RECOGN  ", (ftnlen)8);
L4411:
    j = stack[(*top - 5 << 1) - 2];
    jj = *modulo * (nametb_1.namtbl[j - 1] / *modulo);
    k = stack[(*top - 3 << 1) - 2];
    kk = nametb_1.namtbl[k - 1] - geom[0];
    if (kk >= *modhlf) {
	kk -= *modhlf;
    }
L4420:
    if (jj != vbl[0] && jj != temp[0]) {
	goto L4425;
    }
    if (mode_(&j) == kk) {
	goto L4404;
    }
    i__1 = *top - 5;
    alarm_(&c__1001, &i__1, &c__8, "RECOGN  ", (ftnlen)8);
L4403:
    canflg = FALSE_;
    goto L600;

L4425:
    resrvz_(&j, &kk, &canmax, &c__1);
    i__1 = *top - 5;
    setmod_(&i__1, vbl);
    nametb_1.namtbl[j - 1] += kk;

/* ...  CHECK FOR REFSYS */

L4404:
    if (jj == vbl[0] && *intmed == 0) {
	i__1 = *top - 5;
	alarm_(&c__50, &i__1, &c__4, "RECOGN  ", (ftnlen)8);
    }
    iref = 0;
    refsav = 0;
    if (! (*refflg)) {
	goto L4445;
    }
    if (kk < 1 || kk > 20) {
	goto L4445;
    }
    switch (kk) {
	case 1:  goto L4431;
	case 2:  goto L4431;
	case 3:  goto L4432;
	case 4:  goto L4432;
	case 5:  goto L4433;
	case 6:  goto L4434;
	case 7:  goto L4434;
	case 8:  goto L4434;
	case 9:  goto L4435;
	case 10:  goto L4434;
	case 11:  goto L4445;
	case 12:  goto L4445;
	case 13:  goto L4445;
	case 14:  goto L4434;
	case 15:  goto L4445;
	case 16:  goto L4445;
	case 17:  goto L4445;
	case 18:  goto L4445;
	case 19:  goto L4433;
	case 20:  goto L4436;
    }
L4431:
    ir = *four;
    iref = 4;
    goto L4440;
L4432:
    ir = *five;
    iref = 2;
    goto L4440;
L4433:
    ir = *two;
    iref = 1;
    goto L4440;
L4434:
    ir = *one;
    iref = 5;
    goto L4440;
L4435:
    ir = *five;
    iref = 2;
    goto L4440;
L4436:
    ir = *three;
    iref = 3;
L4440:
    if (! canflg) {
	goto L4445;
    }

/* ...  GENERATE CALL TO TRANSF TO MOVE REFERENCED C.F. TO LOCAL SYSTEM */

    refsav = cannam;
    cannam = gettmp_(&kk);
    callzz_(&aptxxx[102]);
    argcvt_(&cannam);
    argcvt_(&refsav);
    argcvt_(&ir);
    twoarg_(quidlr, &canmax);
    argcvt_(zero);
    rlslin_();
L4445:
    opcode_(move);
    argcvt_(&j);
    if (*canptr == 0) {
	goto L4414;
    }
    i__1 = *canptr;
    for (ii = 1; ii <= i__1; ++ii) {
	if (canstk[ii - 1] <= 0) {
	    goto L4406;
	} else {
	    goto L4407;
	}
L4406:
	if (canflg) {
	    goto L4408;
	}
	iii = 2033;
	goto L4403;
L4408:
	twoarg_(&canstk[ii - 1], &cannam);
	goto L4405;
L4407:
	argcvt_(&canstk[ii - 1]);
	if (iftmp_(&canstk[ii - 1])) {
	    i__2 = mode_(&canstk[ii - 1]);
	    puttmp_(&i__2);
	}
L4405:
	;
    }
    if (! canflg) {
	goto L4410;
    }
    if (*canptr == canmax) {
	goto L4480;
    }
L4414:
    jj = *canptr + 1;
    i__1 = canmax;
    for (ii = jj; ii <= i__1; ++ii) {
/* L4409: */
	i__2 = -ii;
	twoarg_(&i__2, &cannam);
    }
L4480:
    if (iftmp_(&cannam)) {
	i__2 = mode_(&cannam);
	puttmp_(&i__2);
    }
    if (refsav == 0) {
	goto L4410;
    }
    if (iftmp_(&refsav)) {
	i__2 = mode_(&refsav);
	puttmp_(&i__2);
    }
L4410:
    rlslin_();

/* ...  IF REFSYS APPLIES,GENERATE I.L. TO MOVE RESULT TO BASE SYSTEM */

    if (iref != 0) {
	refgen_(&iref, &j);
    }
    switch (canend) {
	case 1:  goto L600;
	case 2:  goto L4412;
	case 3:  goto L4413;
    }
L4412:
    stack[(*top - 6 << 1) - 2] = stack[(*top - 5 << 1) - 2];
    stack[(*top - 6 << 1) - 1] = stack[(*top - 5 << 1) - 1];
    *top += -6;
    goto L2900;
L4413:
    stack[(*top - 4 << 1) - 2] = cantmp;
    l = temp[0] / *modulo;
    stack[(*top - 4 << 1) - 1] = meta[l - 1];
    *top += -4;
    goto L2900;

/* ...  END OF NESTED NAMED CANON DEFINITION */

L4500:
    canend = 2;
    goto L4401;

/* ...  END OF NESTED UNNAMED CANON DEFINITION */


L4600:
    k = stack[(*top - 3 << 1) - 2];
    kk = nametb_1.namtbl[k - 1] - geom[0];
    if (kk >= *modhlf) {
	kk -= *modhlf;
    }
    j = gettmp_(&kk);
    jj = temp[0];
    cantmp = j;
    canend = 3;
    goto L4420;

/* **********   O B T A I N   P R O C E S S I N G   ********** */

L4700:
    j = stack[(*top - 1 << 1) - 2];
    if (*argtop > 0) {
	goto L7015;
    }
    if (candat > 0) {
	goto L7010;
    }
    alarm_(&c__18, &c__0, &c__8, "RECOGN  ", (ftnlen)8);
    goto L7080;
L7010:
    if (mode_(&j) == modc) {
	goto L7020;
    }

/* ... VARIABLE ASSIGNED WRONG MODE. */

    i__2 = *top - 1;
    alarm_(&c__1050, &i__2, &c__8, "RECOGN  ", (ftnlen)8);
    goto L7080;
L7015:
    i__2 = -(*argtop);
    alarm_(&c__2013, &i__2, &c__8, "RECOGN  ", (ftnlen)8);
    goto L7080;
L7020:
    if (errflg) {
	goto L7080;
    }
    if (nametb_1.namtbl[j - 1] % *modulo <= *modhlf) {
	goto L7030;
    }
    i__2 = mode_(&j);
    j = gettmp_(&i__2);
    opcode_(repl);
    onearg_(&tmp_1.txxxx[(modc << 1) - 2]);
    twoarg_(&c__0, &j);
    twoarg_(trpdlr, &stack[(*top - 1 << 1) - 2]);
    rlslin_();

/* ...  IF REFSYS APPLIES,MOVE C.F. TO LOCAL SYSTEM */

L7030:
    refsav = 0;
    if (! (*refflg)) {
	goto L7032;
    }
    jj = mode_(&j);
    if (jj < 1 || jj > 20) {
	goto L7032;
    }
    switch (jj) {
	case 1:  goto L7061;
	case 2:  goto L7061;
	case 3:  goto L7062;
	case 4:  goto L7062;
	case 5:  goto L7063;
	case 6:  goto L7064;
	case 7:  goto L7064;
	case 8:  goto L7064;
	case 9:  goto L7062;
	case 10:  goto L7064;
	case 11:  goto L7032;
	case 12:  goto L7032;
	case 13:  goto L7032;
	case 14:  goto L7064;
	case 15:  goto L7032;
	case 16:  goto L7032;
	case 17:  goto L7032;
	case 18:  goto L7032;
	case 19:  goto L7063;
	case 20:  goto L7066;
    }
L7061:
    ir = *four;
    goto L7070;
L7062:
    ir = *five;
    goto L7070;
L7063:
    ir = *two;
    goto L7070;
L7064:
    ir = *one;
    goto L7070;
L7066:
    ir = *three;
L7070:
    refsav = j;
    j = gettmp_(&jj);
    callzz_(&aptxxx[102]);
    argcvt_(&j);
    argcvt_(&refsav);
    argcvt_(&ir);
    twoarg_(quidlr, &tmp_1.txxxx[(jj << 1) - 2]);
    argcvt_(zero);
    rlslin_();

L7032:
    i__2 = *canptr;
    for (n = 1; n <= i__2; ++n) {
	k = canstk[n - 1];
	if (k < 0) {
	    goto L7050;
	}
	l = nametb_1.namtbl[k - 1] / *modulo * *modulo;
	if (l != ident[0] && l != congeo[0] && l != conbig[0] && l != conpro[
		0]) {
	    goto L7035;
	}
	resrvz_(&k, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1);
	nametb_1.namtbl[k - 1] = vbl[0] + *real__;
	goto L7040;
L7035:
	if (l == vbl[0] && mode_(&k) == *real__) {
	    goto L7040;
	}
	if (nametb_1.namtbl[k - 1] % *modulo > *modhlf && mode_(&k) == *
		real__) {
	    goto L7045;
	}
L7040:
	opcode_(move);
	twoarg_(&c__0, &k);
L7043:
	i__1 = -n;
	twoarg_(&i__1, &j);
	rlslin_();
	goto L7050;
L7045:
	opcode_(move);
	twoarg_(trpdlr, &k);
	goto L7043;
L7050:
	;
    }
    if (refsav == 0) {
	goto L7080;
    }
    if (iftmp_(&refsav)) {
	i__2 = mode_(&refsav);
	puttmp_(&i__2);
    }
L7080:
    if (iftmp_(&j)) {
	i__2 = mode_(&j);
	puttmp_(&i__2);
    }
    goto L600;


/* ... SUBSCRIPTED ARGUMENT IN OBTAIN STATEMENT */

L4800:
    *i__ = stack[(*top - 4 << 1) - 2];
    if (mode_(i__) != 0) {
	goto L1000;
    }
    nametb_1.namtbl[*i__ - 1] += *real__;
    iii = 1;
L7110:
    if (iii >= *rngpt) {
	goto L1000;
    }
    if (range[iii - 1] == *i__) {
	goto L7120;
    }
    iii += 2;
    goto L7110;
L7120:
    resrvz_(i__, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &range[iii]);
    goto L1000;

/* ... RETURN TO RECOG */

L220:
    *iasnrt = 2;
    goto L9000;
L600:
    *iasnrt = 3;
    goto L8900;
L1000:
    *iasnrt = 4;
    goto L9000;
L2900:
    *iasnrt = 5;
    canflg = FALSE_;
L8900:
    *canptr = 0;
    stmtyp = 0;
    candat = 0;
L9000:
    return 0;

/* ...  SPECIAL POINT DEFINITION */

L4900:
    k = stack[(*top - 1 << 1) - 2];
    ++(*argtop);
    argstk[*argtop - 1] = k;
    if (iftmp_(&k)) {
	i__2 = mode_(&k);
	puttmp_(&i__2);
    }
    stack[(*top - 1 << 1) - 2] = stack[(*top - 3 << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top - 3 << 1) - 1];
    k = name_(ppoint, (ftnlen)6);
    maclbl_(&k, &c__0, &k);
    nametb_1.namtbl[k - 1] = geom[0] + *point;
    stack[(*top - 3 << 1) - 2] = k;
    k = geom[0] / *modulo;
    stack[(*top - 3 << 1) - 1] = meta[k - 1];
    stack[(*top - 2 << 1) - 2] = slash[1];
    k = slash[0] / *modulo;
    stack[(*top - 2 << 1) - 1] = meta[k - 1];
    goto L220;

} /* recogn_ */

#undef aptxxx
#undef trpdlr
#undef canptr
#undef modulo
#undef quidlr
#undef conpro
#undef rldsrf
#undef argtop
#undef argstk
#undef canstk
#undef intmed
#undef congeo
#undef modhlf
#undef refflg
#undef conbig
#undef biggeo
#undef canchk
#undef rngpt
#undef point
#undef slash
#undef three
#undef stack
#undef ident
#undef canon
#undef range
#undef zero
#undef four
#undef move
#undef temp
#undef repl
#undef five
#undef geom
#undef meta
#undef real__
#undef two
#undef top
#undef vbl
#undef one


