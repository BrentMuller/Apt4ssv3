/* LOOP.f -- translated by f2c (version 20100827).
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
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer super[36];
} super_;

#define super_1 super_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

/* Table of constant values */

static integer c__1008 = 1008;
static integer c__8 = 8;
static integer c__1037 = 1037;
static integer c__0 = 0;
static integer c__1038 = 1038;
static integer c__2 = 2;
static integer c__1039 = 1039;
static integer c__1040 = 1040;
static integer c__1036 = 1036;
static integer c__2052 = 2052;

/* *** SOURCE FILE : M0006648.V03   *** */


/*              FORTRAN SUBROUTINE LOOP */

/* LINKAGE      SUBROUTINE  LOOP */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    INPUT */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    RECOG */
/*          SUBROUTINE    MACLBL          SUBROUTINE    PRO026 */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          INTEGER FCT.  GETTMP */
/*          INTEGER FCT.  MODE */
/*          SUBROUTINE    REPLAC */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    LABELZ */
/*          SUBROUTINE    SETCHR */

/* Subroutine */ int loop_(void)
{
    /* Initialized data */

    static integer istck[5] = { 7,5,3,1,9 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, k, l, m, kk, ll, mm, iii;
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
#define fadd ((integer *)&il_1)
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
#define fini ((logical *)&super_1 + 6)
#define meta ((integer *)&srctbl_1 + 2)
#define fsub ((integer *)&il_1 + 1)
#define temp ((integer *)&code_1 + 32)
#define fmpy ((integer *)&il_1 + 2)
    static integer rslt;
#define label ((integer *)&code_1 + 42)
#define absdo ((integer *)&doloop_1 + 1)
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
#define reldo ((integer *)&doloop_1 + 2)
#define domax ((integer *)&doloop_1 + 4)
#define onept ((integer *)&numptr_1 + 3)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define doflag ((logical *)&doloop_1 + 6)
#define finmac ((logical *)&macxx1_1 + 23)
#define implab ((integer *)&code_1 + 44)
    extern /* Subroutine */ int replac_(void);
    static integer labsav[70]	/* was [7][10] */;
    extern /* Subroutine */ int opcode_(integer *), labelz_(integer *), 
	    onearg_(integer *);
#define whchmn ((integer *)&macxx1_1 + 62)
#define conjmp ((integer *)&il_1 + 10)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)
#define donest ((integer *)&doloop_1 + 3)
#define dojump ((integer *)&doloop_1 + 5)
    extern /* Subroutine */ int setchr_(integer *, integer *);
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int argcvt_(integer *), rlslin_(void);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* NAMTBL:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        4.    PRODUCTION TABLE */

/* META:        END OF CHARACTER CONCATENATION AND STRING PRODUCTION */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ONEPT:       NAMTBL POINTER TO '1.    ' */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* FADD:        CONTAINS COMMAND CODE ( 1) FOR FADD COMMAND */
/* FSUB:        CONTAINS COMMAND CODE ( 2) FOR FSUB COMMAND */
/* FMPY:        CONTAINS COMMAND CODE ( 3) FOR FMPY COMMAND */
/* CONJMP:      CONTAINS COMMAND CODE (11) FOR CONJMP COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR REAL */

/*       22.    MACRO PROCESSING VARIABLES */

/* FINMAC:      TRUE DURING FINAL MACRO PROCESSING */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       40.    PARAMETERS REQUIRED BY SUPERVISOR */

/* FINI:        FLAG ON INDICATES A FINI CARD HAS BEEN READ */

/*       43.    DO LOOP CONTROL VALUES */

/* ABSDO:       LOOP NUMBER FOR LABEL CREATION */
/* RELDO:       CURRENTLY NESTED DO LOOPS */
/* DONEST:      CURRENTLY NESTED DO LOOPS */
/* DOMAX:       MAXIMAL NESTING OF LOOPS */
/* DOJUMP:      VBL FOR COMPUTED GOTO AT LOOP PROCESSING */
/* DOFLAG:      FLAG IS ON DURING OPENED LOOP */
/* * */
/* PURPOSE      DISSECTS AND PROCESSES FORTRAN-LIKE PROGRAMMED DO-LOOPS */
/*              FOR I.L.-OUTPUT BY SETTING THE START-VALUE, ADDING WITH */
/*              RETURN-POINTER AND IF-SCANNING ON LOOP-END-VALUE WITH */
/*              RETURN OR BRANCHING OUT OF THE LOOP RESPECTIVELY. */


/* INPUT                                DO / LABEL, I1 = I2, I3, I4 */
/*                              LABEL ) CONTIN */
/*                        OR    LABEL ) APT - STATEMENT */

/*              DOJUMP         1        DO STATEMENT PROGRAMMED */
/*                             2     LABEL STATEMENT PROGRAMMED */
/*                             3     PRODUCTION OF THE LOOP-END */
/*                             4     TERMAC STATEMENT */
/*                             5     FINI   STATEMENT */
/*              LABSAV(J,K)          NAMTBL ADDRESS */
/*                     J       1     I1 */
/*                             2     I2 */
/*                             3     I3 */
/*                             4     I4 */
/*                             5     PROGRAMMED LABEL */
/*                             6     PRODUCED LABEL */
/*                             7     VALUE FOR PRODUCING LABEL */


/* ** */
    switch (*dojump) {
	case 1:  goto L5;
	case 2:  goto L170;
	case 3:  goto L100;
	case 4:  goto L250;
	case 5:  goto L300;
    }
    goto L999;

/*     START OF DO-LOOP; INPUT STATEMENT DO / LAB , I1 = I2 , I3 (, I4) */

/*     ERROR-CONTROL */

L5:
    if (*argtop > 0) {
	goto L835;
    }
    if (*top == *domax) {
	goto L10;
    }
    *top = *domax;
    stack[(*top << 1) - 2] = stack[(*top - 2 << 1) - 2];
    stack[(*top << 1) - 1] = stack[(*top - 2 << 1) - 1];
    i__1 = *top - 2;
    setchr_(&i__1, comma);
    stack[(*top - 1 << 1) - 2] = *onept;
    l = number[0] / *modulo;
    stack[(*top - 1 << 1) - 1] = meta[l - 1];

/*     PROVIDING AN ADDRESS ON TEMPORARY INPUT */

L10:
    ll = *top;
    ++(*absdo);
    for (j = 2; j <= 4; ++j) {
	m = ll - istck[j - 1];
	if (stack[(m << 1) - 2] > nametb_1.nammax) {
	    goto L29;
	}
	kk = *modulo * (nametb_1.namtbl[stack[(m << 1) - 2] - 1] / *modulo);
	if (kk != temp[0]) {
	    goto L29;
	}
	k = stack[(m << 1) - 2];
	kk = *absdo * 998 + 20000 - j;
	l = *whchmn;
	if (l == 0) {
	    l = 51;
	}
	i__1 = -l;
	maclbl_(&kk, &i__1, &k);
	nametb_1.namtbl[k - 1] = ident[0];
	kk = stack[(m - 2 << 1) - 2];
	mm = stack[(m - 2 << 1) - 1];
	*top = m + 1;
	stack[(m - 2 << 1) - 2] = k;
	replac_();
	stack[(m << 1) - 2] = stack[(m - 2 << 1) - 2];
	stack[(m << 1) - 1] = meta[nametb_1.namtbl[stack[(m << 1) - 2] - 1] / 
		*modulo - 1];
	stack[(m - 2 << 1) - 2] = kk;
	stack[(m - 2 << 1) - 1] = mm;
L29:
	;
    }
    *top = ll;

/*     STORING THE DO-VALUES IN LABSAV; CONTROL ON MULTIPLY DEFINED */
/*     VARIABLES IN INTERLEAVINGS. */

    ++(*reldo);
    if (*reldo > *donest) {
	goto L820;
    }
    for (k = 1; k <= 5; ++k) {
/* L20: */
	labsav[k + *reldo * 7 - 8] = stack[(*top - istck[k - 1] << 1) - 2];
    }

    if (*reldo <= 1) {
	goto L23;
    }
    kk = *reldo - 1;
    i__1 = kk;
    for (k = 1; k <= i__1; ++k) {
	if (labsav[k * 7 - 7] == labsav[*reldo * 7 - 7]) {
	    goto L830;
	}
/* L22: */
    }

/*     WORKING UP OF I1=I2-I4 */

L23:
    for (k = 2; k <= 4; ++k) {
/* L25: */
	if (mode_(&labsav[k + *reldo * 7 - 8]) != *real__) {
	    i__1 = *top - 9 + (k << 1);
	    alarm_(&c__1008, &i__1, &c__8, "LOOP    ", (ftnlen)8);
	}
    }
    rslt = gettmp_(real__);
    opcode_(fsub);
    argcvt_(&rslt);
    argcvt_(&labsav[*reldo * 7 - 6]);
    argcvt_(&labsav[*reldo * 7 - 4]);
    rlslin_();
    stack[(*top - 3 << 1) - 2] = labsav[*reldo * 7 - 7];
    stack[(*top - 1 << 1) - 2] = rslt;
    replac_();

/*     WORKING UP OF LABEL) */

    kk = *absdo * 998 + 20000;
    labsav[*reldo * 7 - 1] = kk + 1;
    l = *whchmn;
    if (l == 0) {
	l = 51;
    }
    i__1 = -l;
    maclbl_(&kk, &i__1, &k);
    labsav[*reldo * 7 - 2] = k;
    if (! (*finmac) && *whchmn != 0) {
	goto L40;
    }
    nametb_1.namtbl[k - 1] = label[0] + *whchmn;
L30:
    labelz_(&k);
    goto L50;
L40:
    nametb_1.namtbl[k - 1] = implab[0] + *whchmn;
    goto L30;

/*     WORKING UP OF I1 = I1 + I4 */

L50:
    opcode_(fadd);
    argcvt_(&labsav[*reldo * 7 - 7]);
    argcvt_(&labsav[*reldo * 7 - 7]);
    argcvt_(&labsav[*reldo * 7 - 4]);
    rlslin_();
    goto L999;

/*     END OF A DO-LOOPS;  INPUT: LABEL)CONTIN  RESP. STATEMENT */

L100:
    if (! (*doflag)) {
	goto L999;
    }
    *doflag = FALSE_;

/*     WORKING UP OF TEMP = I3+I1 */

    rslt = gettmp_(real__);
    i__1 = iii;
    for (j = 1; j <= i__1; ++j) {
	opcode_(fsub);
	argcvt_(&rslt);
	argcvt_(&labsav[*reldo * 7 - 5]);
	argcvt_(&labsav[*reldo * 7 - 7]);
	rlslin_();

/*     WORKING UP OF TEMP = TEMP -I4 */

	opcode_(fsub);
	argcvt_(&rslt);
	argcvt_(&rslt);
	argcvt_(&labsav[*reldo * 7 - 4]);
	rlslin_();

/*     WORKING UP OF TEMP = I4 * TEMP */

	opcode_(fmpy);
	argcvt_(&rslt);
	argcvt_(&labsav[*reldo * 7 - 4]);
	argcvt_(&rslt);
	rlslin_();

/*     WORKING UP OF IF(TEMP) LAB1,LAB2,LAB2 */

	opcode_(conjmp);
	argcvt_(&rslt);
	kk = labsav[*reldo * 7 - 1];
	l = *whchmn;
	if (l == 0) {
	    l = 51;
	}
	i__2 = -l;
	maclbl_(&kk, &i__2, &k);
	if (! (*finmac) && *whchmn != 0) {
	    goto L140;
	}
	nametb_1.namtbl[k - 1] = label[0] + *whchmn;
	goto L150;

/*     WORKING UP OF IF-LABELS */

L140:
	nametb_1.namtbl[k - 1] = implab[0] + *whchmn;
L150:
	onearg_(&k);
	onearg_(&labsav[*reldo * 7 - 2]);
	onearg_(&labsav[*reldo * 7 - 2]);
	rlslin_();
	labelz_(&k);
/* L160: */
	--(*reldo);
    }
    goto L999;

/*     CHECK IF LABEL BELONGS TO A DO-LOOP */

L170:
    if (*reldo <= 0) {
	goto L999;
    }
/* L171: */
    iii = 0;
    i__1 = *reldo;
    for (l = 1; l <= i__1; ++l) {
	k = *reldo + 1 - l;
	if (labsav[k * 7 - 3] == stack[(*top - 1 << 1) - 2]) {
	    ++iii;
	}
/* L172: */
    }
    if (iii == 0) {
	goto L999;
    }
    i__1 = iii;
    for (l = 1; l <= i__1; ++l) {
	k = *reldo + 1 - l;
	if (labsav[k * 7 - 3] != stack[(*top - 1 << 1) - 2]) {
	    goto L805;
	}
/* L175: */
    }
L177:
    *doflag = TRUE_;
    goto L999;

/*     MACRO HAS BEEN COMPLETED */

L250:
    if (! (*fini)) {
	goto L999;
    }
    *absdo = 0;
    goto L310;

/*     FINI HAS BEEN READ IN */
L300:
    *absdo = 0;
L310:
    if (*reldo > 0) {
	goto L810;
    }

L999:
    return 0;

/*     ERROR-MESSAGES */

/*     ERROR 1037   ON FINI OR TERMAC OPEN LOOP */
L810:
    alarm_(&c__1037, &c__0, &c__8, "LOOP    ", (ftnlen)8);
    *reldo = 0;
    goto L999;
/*     ERROR 1038   TOO MANY DO'S NESTED (MORE THAN 10) */
L820:
    alarm_(&c__1038, &c__2, &c__8, "LOOP    ", (ftnlen)8);
L825:
    --(*reldo);
    goto L999;
/*     ERROR 1039   WRONGLY NESTED DO */
L805:
    i__1 = *top - 1;
    alarm_(&c__1039, &i__1, &c__8, "LOOP    ", (ftnlen)8);
    goto L177;
/*     ERROR 1040   DO-VARIABLE IDENTICAL */
L830:
    i__1 = *top - 7;
    alarm_(&c__1040, &i__1, &c__8, "LOOP    ", (ftnlen)8);
    goto L825;
/*     ERROR 1036   DO-ARGUMENT WITHOUT VALUE-ASSIGNEMENT */
L835:
    if (*top == *domax) {
	goto L840;
    }
    i__1 = -(*argtop);
    alarm_(&c__1036, &i__1, &c__8, "LOOP    ", (ftnlen)8);
    goto L999;
/*     ERROR 2052   TOO MANY DO-ARGUMENTS */
L840:
    i__1 = -(*argtop);
    alarm_(&c__2052, &i__1, &c__8, "LOOP    ", (ftnlen)8);
    goto L10;

} /* loop_ */

#undef dojump
#undef donest
#undef modulo
#undef argtop
#undef argstk
#undef number
#undef conjmp
#undef whchmn
#undef implab
#undef finmac
#undef doflag
#undef onept
#undef domax
#undef reldo
#undef stack
#undef ident
#undef comma
#undef absdo
#undef label
#undef fmpy
#undef temp
#undef fsub
#undef meta
#undef fini
#undef real__
#undef fadd
#undef top
#undef vbl


