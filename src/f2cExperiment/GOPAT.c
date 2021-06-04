/* GOPAT.f -- translated by f2c (version 20100827).
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
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

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

static integer c__10 = 10;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__1 = 1;
static integer c__98 = 98;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006635.W01   *** */


/*              FORTRAN SUBROUTINE GOPAT */

/* LINKAGE      SUBROUTINE GOPAT */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CALLZZ          SUBROUTINE    PRO026 */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    TWOARG */

/* Subroutine */ int gopat_(void)
{
    /* Initialized data */

    static integer numrec[5] = { 1,5,4,3,2 };
    static integer komit = 64;
    static integer kretai = 65;
    static integer kinver = 35;
    static integer kzigza = 61;
    static char hdolsc[6] = "$SCRTH";
    static char hdolpc[6] = "$PCRTH";

    /* Format strings */
    static char fmt_15[] = "";
    static char fmt_40[] = "";
    static char fmt_10[] = "";
    static char fmt_35[] = "";
    static char fmt_20[] = "";

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, ia, io, iin;
#define one ((integer *)&numptr_1 + 2)
#define vbl ((integer *)&code_1 + 60)
    static integer ibig, iend;
    extern integer name_(char *, ftnlen);
    static integer iarg;
#define real__ ((integer *)&modx_1 + 20)
    static integer iget, namx;
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
#define zero ((integer *)&numptr_1)
    static integer iarg1, iarg2, iarg3, iarg4;
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
    static integer kmode;
#define ident ((integer *)&code_1 + 68)
    static integer kmova;
    static logical lomit;
    static integer iiout, kmovo, errpt;
    extern integer search_(integer *, integer *, integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *);
#define permid ((integer *)&code_1 + 38)
    static integer bigstk[10];
    static logical lretai;
#define number ((integer *)&code_1 + 26)
#define patern ((integer *)&modx_1 + 25)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)
#define quidlr ((integer *)&opmod_1 + 5)
    static integer avdlst[18], kscrth, kpcrth, isetup, kserch, avdsav;
    extern /* Subroutine */ int twoarg_(integer *, integer *), argcvt_(
	    integer *), rlslin_(void);
    static integer omtlst[18];
#define zeropt ((integer *)&numptr_1 + 1)
    static integer kclass;
    extern /* Subroutine */ int callzz_(integer *);
    static integer ierror;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);
#define aptxxx ((integer *)&sublst_1)

    /* Assigned format variables */
    static char *iend_fmt, *isetup_fmt;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:         NAMTBL POINTER TO '1     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       16.    LITERALS FOR I. L. OPERATION CODES */




/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (24) FOR A SCALAR */
/* PATERN:      MODE CODE (26) FOR PATTERN */

/*       27.    OPERAND MODIFIERS */

/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* PURPOSE      TO VALIDATE GO/PATERN STATEMENTS AND GENERATE */
/*              APPROPRIATE INTERMEDIATE LANGUAGE. */

/*      external alarm */
/* ** */
/* ......             INITIALIZE */

    iarg1 = zero[0];
    iarg2 = zero[0];
    io = 0;
    ia = 0;
    kmovo = -1;
    kmova = -1;
    kscrth = name_(hdolsc, (ftnlen)6);
    kpcrth = name_(hdolpc, (ftnlen)6);
    iend = 0;
    iend_fmt = fmt_15;
/*                             POINTER FOR ARGSTK, 1 BELOW PATERN */
    iarg = *argtop - 1;
/*                             POINTER FOR BIGSTK */
    ibig = 5;
/*                             FLAGS FOR OMIT AND RETAIN */
    lomit = FALSE_;
    lretai = FALSE_;
/*                             NUMBER OF ARGS TO DELETE FROM BIGSTK */
    iget = 5;
    if (iarg == 0) {
	goto L40;
    }

/* ......             SETUP BIGSTK CORRESPONDING TO TOP 5 ARGUMENTS OF */
/* ......             ARGSTK, IN FORMAT TO BE RECOGNIZED BY PATERN */
/* ......             GEOMETRIC PRODUCTIONS */

    isetup = 0;
    isetup_fmt = fmt_10;
    goto L1000;

/* ......             LOOK FOR PATERN */

L10:
    j = gmty_1.geoloc[*patern - 1];
    errpt = ibig;
    kserch = search_(bigstk, &c__10, &gmty_1.geomtb[j - 1], &errpt);
/* ......             ERROR IF NO MATCH ON CORRECT TYPE */

    if (kserch <= 12 || kserch >= 18) {
	goto L1258;
    }

/* ......             DETERMINE NUMBER OF ELEMENTS RECOGNIZED */

    i__ = kserch - 12;
    iget = numrec[i__ - 1];

    namx = bigstk[8];
    if (namx > nametb_1.nammax) {
	goto L12;
    }
    kmode = nametb_1.namtbl[namx - 1] % *modulo;

/*                   BRANCH TO PROCESS RECOGNIZED ELEMENTS */

L12:
    switch (i__) {
	case 1:  goto L100;
	case 2:  goto L210;
	case 3:  goto L300;
	case 4:  goto L200;
	case 5:  goto L300;
    }

/*                   INVERS OR ZIGZAG */

L100:
    if (kmode == kinver) {
	iarg1 = *one;
    }
    if (kmode == kzigza) {
	iarg2 = *one;
    }
    goto L15;

/*                   AVOID */

L200:
    avdsav = bigstk[6];
L210:
    avdlst[ia] = bigstk[6];
    avdlst[ia + 1] = bigstk[4];
    if (kserch != 14) {
	goto L215;
    }
    avdlst[ia + 2] = bigstk[0];
    goto L220;
L215:
    avdlst[ia + 2] = *zeropt;
L220:
    ia += 3;
    if (ia < 18) {
	goto L15;
    }
/*                   IF NOT ALREADY DONE,DECLARE ARRAY OF SCRATCH */
/*                   STORAGE IN PART PROGRAM.  MOVE AVOID INFORMATION */
/*                   INTO LOCATIONS 1 THRU 102 OF THIS ARRAY. */
L250:
    if (nametb_1.namtbl[kscrth - 1] != 0) {
	goto L255;
    }
    nametb_1.namtbl[kscrth - 1] = vbl[0];
    resrvz_(&kscrth, &c__0, &c__102, &c__1);
L255:
    if (kmova - ia < -102) {
	goto L2010;
    }
    opcode_(move);
    twoarg_(&kmova, &kscrth);
    i__1 = ia;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L260: */
	argcvt_(&avdlst[i__ - 1]);
    }
    rlslin_();
    kmova -= ia;
    ia = 0;
    switch (iend) {
	case 0: goto L15;
	case 1: goto L35;
	case 2: goto L40;
    }

/*                   OMIT OR RETAIN */

L300:
    lomit = kmode == komit || lomit;
    lretai = kmode == kretai || lretai;
    if (lomit && lretai) {
	goto L2000;
    }
    omtlst[io] = bigstk[6];
    if (kserch != 15) {
	goto L315;
    }
    omtlst[io + 1] = bigstk[2];
    goto L320;
L315:
    omtlst[io + 1] = omtlst[io];
L320:
    io += 2;
    if (io < 18) {
	goto L15;
    }
/*                   IF NOT ALREADY DONE, DECLARE ARRAY OF SCRATCH */
/*                   STORAGE IN PART PROGRAM.  MOVE OMIT OR RETAIN */
/*                   INFORMATION INTO LOCATIONS 1 THRU 98 OF THIS ARRAY. */
L350:
    if (nametb_1.namtbl[kpcrth - 1] != 0) {
	goto L355;
    }
    nametb_1.namtbl[kpcrth - 1] = vbl[0];
    resrvz_(&kpcrth, &c__0, &c__98, &c__1);
L355:
    if (kmovo - io < -98) {
	goto L2010;
    }
    opcode_(move);
    twoarg_(&kmovo, &kpcrth);
    i__1 = io;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L360: */
	argcvt_(&omtlst[i__ - 1]);
    }
    rlslin_();
    kmovo -= io;
    io = 0;
    switch (iend) {
	case 0: goto L15;
	case 1: goto L35;
	case 2: goto L40;
    }

/*                   BRANCH IF ARGSTK ALL EXAMINED */

L15:
    if (iarg + ibig - iget == 0) {
	goto L30;
    }

/*                   RESET BIGSTK */

    isetup = 1;
    isetup_fmt = fmt_20;
    goto L1000;

/*                   LOOP IF REAL LIST CANNOT FOLLOW */

L20:
    if (kserch <= 15) {
	goto L10;
    }

/*                   PROCESS ELEMENT OF REAL LIST IF PRESENT */

    namx = bigstk[8];
    iget = 1;
    if (namx > nametb_1.nammax) {
	goto L17;
    }
    kclass = nametb_1.namtbl[namx - 1] / *modulo;
    if (kclass == number[0]) {
	goto L17;
    }
    kmode = nametb_1.namtbl[namx - 1] % *modhlf;
    if (kmode != *real__) {
	goto L10;
    }
L17:
    if (kserch == 17) {
	goto L18;
    }
/*                   ELEMENT OF AVOID LIST */
    avdlst[ia] = avdsav;
    avdlst[ia + 1] = bigstk[8];
    goto L215;
/*                   ELEMENT OF OMIT OR RETAIN LIST */
L18:
    omtlst[io] = bigstk[8];
    goto L315;

/*                   MOVE ANY ELEMENTS REMAINING IN OMTLST OR */
/*                   AVDLST TO $SCRTH */

L30:
    if (io == 0) {
	goto L35;
    }
    iend = 1;
    iend_fmt = fmt_35;
    goto L350;
L35:
    if (ia == 0) {
	goto L40;
    }
    iend = 2;
    iend_fmt = fmt_40;
    goto L250;
/*                   DETERMINE NUMBER OF TWO-ELEMENT ENTRIES IN */
/*                   OMIT/RETAIN TABLE, OMTLST. */
/*                   IF RETAIN, SET NUMBER NEGATIVE. */
L40:
    iarg3 = -(kmovo + 1) / 2;
    if (lretai) {
	iarg3 += 1000;
    }
/*                   DETERMINE NUMBER OF THREE-ELEMENT ENTRIES */
/*                   IN AVOID TABLE, AVDLST. */
    iarg4 = -(kmova + 1) / 3;
/*                   GENERATE CALL TO XECUTION SUBROUTINE GOTOPN */
/* L50: */
    callzz_(&aptxxx[98]);
    argcvt_(&argstk[*argtop - 1]);
    argcvt_(&iarg1);
    argcvt_(&iarg2);
    twoarg_(quidlr, &iarg3);
    twoarg_(quidlr, &iarg4);
    if (nametb_1.namtbl[kpcrth - 1] == 0) {
	goto L52;
    }
    twoarg_(&c__0, &kpcrth);
    goto L53;
L52:
    argcvt_(zeropt);
L53:
    if (nametb_1.namtbl[kscrth - 1] == 0) {
	goto L54;
    }
    twoarg_(&c__0, &kscrth);
    goto L60;
L54:
    argcvt_(zeropt);
L60:
    rlslin_();

    return 0;
/* ----------------------------------------------------------------------- */

/*     PURPOSE       TO MOVE INTERNAL BIT CONFIGURATIONS CORRESPONDING TO */
/*                   ELEMENTS OF ARGSTK INTO BIGSTK, FOR RECOGNITION BY */
/*                   PATERN GEOMETRIC PRODUCTIONS */

/*     ARGUMENTS     IARG      INDEX OF NEXT ELEMENT OF ARGSTK. */
/*                   IGET      NUMBER OF RECOGNIZED ELEMENTS TO BE POPPED */
/*                             FROM BIGSTK. */
/*                   ISETUP    RETURN INDEX. */

/*                             POP RECOGNIZED ELEMENTS */
L1000:
    iin = 10;
    iiout = 10 - (iget << 1);
    ibig -= iget;
L1005:
    if (iiout == 0) {
	goto L1010;
    }
    bigstk[iin - 1] = bigstk[iiout - 1];
    bigstk[iin - 2] = bigstk[iiout - 2];
    iin += -2;
    iiout += -2;
    goto L1005;
/*                             CONVERT STACK ELEMENTS */
L1010:
    i__1 = iget;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (iarg != 0) {
	    goto L1200;
	}
	j = 10 - (ibig << 1);
	bigstk[j - 1] = -1;
	goto L1255;
L1200:
	namx = argstk[iarg - 1];
	errpt = iarg;
	if (namx > nametb_1.nammax) {
	    goto L1205;
	}
	kclass = *modulo * (nametb_1.namtbl[namx - 1] / *modulo);
	kmode = nametb_1.namtbl[namx - 1] - kclass;
	if (kmode >= *modhlf) {
	    kmode -= *modhlf;
	}
	if (kmode == 0) {
	    goto L1260;
	}
	if (kclass == vbl[0] || kclass == temp[0]) {
	    goto L1220;
	}
	if (kclass == ident[0]) {
	    nametb_1.namtbl[namx - 1] = nametb_1.namtbl[namx - 1] - ident[0] 
		    + permid[0];
	}
	if (kclass == ident[0] || kclass == permid[0]) {
	    goto L1210;
	}
	if (kclass != number[0]) {
	    goto L1260;
	}
L1205:
	kmode = *real__;
	goto L1220;
L1210:
	kmode += 50;
L1220:
	j = 10 - (ibig << 1);
	bigstk[j - 1] = gmty_1.pmidtb[kmode - 1];
	bigstk[j - 2] = namx;
	--iarg;
	++ibig;
/* L1250: */
    }
/*                             RETURN */
L1255:
    switch (isetup) {
	case 0: goto L10;
	case 1: goto L20;
    }
/*                             IMPROPER ARGUMENT IN GOTO/PATERN STATEMENT */
L1258:
/* Computing MAX */
    i__1 = iarg + 1, i__2 = iarg + errpt;
    errpt = max(i__1,i__2);
L1260:
    ierror = 2036;
    goto L3000;
/*                             BOTH OMIT AND RETAIN SPECIFIED IN GOTO/ */
/*                             PATERN STATEMENT */
L2000:
    ierror = 2037;
    errpt = iarg + ibig;
    goto L3000;
/*                   TOO MANY OMIT, RETAIN OR AVOID POINTS IN GOTO/ */
/*                             PATERN STATEMENT */
L2010:
    ierror = 2038;
    errpt = iarg + 1;
L3000:
    i__1 = -errpt;
    alarm_(&ierror, &i__1, &c__8, "GOPAT   ", (ftnlen)8);
    return 0;


} /* gopat_ */

#undef aptxxx
#undef zeropt
#undef quidlr
#undef modulo
#undef argtop
#undef argstk
#undef patern
#undef number
#undef permid
#undef modhlf
#undef ident
#undef zero
#undef move
#undef temp
#undef real__
#undef vbl
#undef one


