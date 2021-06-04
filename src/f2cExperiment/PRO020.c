/* PRO020.f -- translated by f2c (version 20100827).
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
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer cfsize[205];
} cfsize_;

#define cfsize_1 cfsize_

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
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__1 = 1;
static integer c__1001 = 1001;
static integer c__8 = 8;
static integer c__50 = 50;
static integer c__4 = 4;
static integer c__2001 = 2001;
static integer c__1026 = 1026;

/* *** SOURCE FILE : M0006665.W01   *** */


/*              FORTRAN SUBROUTINE PRO020 */

/* LINKAGE      SUBROUTINE PRO020(TIP) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    MATCH           SUBROUTINE    RECOG */
/*          SUBROUTINE    ARGCVT */
/*          INTEGER FCT.  MODE */
/*          LOGICAL FCT.  IFTMP */
/*          SUBROUTINE    ARGGEN */
/*          SUBROUTINE    PATH */
/*          SUBROUTINE    PRO021 */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  SEARCH */
/*          SUBROUTINE    SETMOD */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  GETTMP */

/* Subroutine */ int pro020_(integer *tip)
{
    /* Initialized data */

    static char noder[6] = "NODER ";
    static char deriv[6] = "DERIV ";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, kk, kt2;
#define one ((integer *)&numptr_1 + 2)
#define vbl ((integer *)&code_1 + 60)
#define way ((integer *)&macxx1_1 + 25)
#define top ((integer *)&stklst_1)
    static integer iarg;
#define real__ ((integer *)&modx_1 + 20)
    extern integer mode_(integer *);
    static integer karg;
#define meta ((integer *)&srctbl_1 + 2)
#define geom ((integer *)&code_1 + 30)
    extern /* Subroutine */ int path_(void);
    static integer ierr;
#define temp ((integer *)&code_1 + 32)
    static integer errp;
#define zero ((integer *)&numptr_1)
    extern /* Subroutine */ int pro021_(integer *, integer *, integer *), 
	    alarm_(integer *, integer *, integer *, char *, ftnlen), match_(
	    void);
    static integer kmode;
#define undef ((integer *)&sublst_1 + 73)
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
    extern logical iftmp_(integer *);
#define nestg ((logical *)&macxx1_1 + 44)
    static integer jlist[11], errpt;
#define entry__ ((logical *)&macxx1_1 + 39)
#define finmac ((logical *)&macxx1_1 + 23)
#define pardef ((logical *)&cfsize_1 + 1)
#define dbldlr ((integer *)&opmod_1 + 2)
    extern integer search_(integer *, integer *, integer *, integer *);
#define object ((integer *)&modx_1 + 27)
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int arggen_(void);
#define permid ((integer *)&code_1 + 38)
#define cantop ((integer *)&cfsize_1)
#define number ((integer *)&code_1 + 26)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define cansiz ((integer *)&cfsize_1 + 5)
#define parsrf ((integer *)&modx_1 + 14)
#define bounds ((integer *)&modx_1 + 26)
#define should ((logical *)&macxx1_1 + 69)
#define intmed ((integer *)&macxx1_1 + 21)
#define majwrd ((integer *)&macxx1_1 + 22)
#define quidlr ((integer *)&opmod_1 + 5)
#define modulo ((integer *)&moduli_1)
#define maxsiz ((integer *)&cfsize_1 + 3)
#define newstm ((logical *)&flags_1 + 1)
#define ergstk ((integer *)&errpos_1 + 202)
    extern /* Subroutine */ int setmod_(integer *, integer *);
    static integer result;
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int callzz_(integer *), argcvt_(integer *), 
	    rlslin_(void), twoarg_(integer *, integer *), puttmp_(integer *);
    static integer length;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);
#define aptxxx ((integer *)&sublst_1)
    static integer nowrds;



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

/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZERO:        NAMTBL POINTER TO '0     ' */
/* ONE:         NAMTBL POINTER TO '1     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* ARGMXY:      CONTAINS THE NAMTBL INDICES THAT REPLACE MINOR WORDS */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* CANTOP:      POINTER TO THE LAST CANSIZ ENTRY */
/* PARDEF:      TRUE WHEN PART PROGRAM CONTAINS PARAMETRIC SURFACES */
/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* CANSIZ:      NUMBER OF ITEMS A. NAMTBL INDEX OF EACH LARGE DATA ARRAY */

/*       17.    MODE CODES */

/* PARSRF:      MODE CODE (15) FOR PARAMETRIC SURFACE */
/* REAL:        MODE CODE (24) FOR A SCALAR */
/* BOUNDS:      MODE CODE (27) FOR BOUNDS */
/* OBJECT:      MODE CODE (28) FOR OBJECT */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* MAJWRD:      CONTAINS ACTUAL MAJOR WORD */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* NESTG:       TRUE WHEN A NESTED GEOMETRIC EXPRESSION ENCOUNTERED */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */

/*       27.    OPERAND MODIFIERS */

/* DBLDLR:      CONTAINS OPERAND TYPE CODE 2 */
/* QUIDLR:      CONTAINS OPERAND TYPE CODE 5 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */
/* UNDEF:       NAMTBL POINTER TO EXECUTION SUBROUTINE UNDEF */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* ARGUMENTS    TIP      CURRENT PRODUCTION NUMBER */

/* ** */
    k = stack[(12 + (0 + (1 + (*top - 1 << 1) - 3 << 2)) - 12) / 4];
    if (k > nametb_1.nammax) {
	goto L50;
    }
    if (iftmp_(&k)) {
	i__1 = nametb_1.namtbl[k - 1] % *modulo;
	puttmp_(&i__1);
    }
    i__ = nametb_1.namtbl[k - 1] / *modulo;
    l = nametb_1.namtbl[k - 1] - i__ * *modulo;
    if (i__ == ident[0] / *modulo && l != 0) {
	i__1 = *top - 1;
	setmod_(&i__1, permid);
    }
/*     PLACE FIRST ARGUMENT IN ARGSTK */
L50:
    argstk[*argtop] = k;
    ergstk[*argtop] = estack[*top - 2];
    *majwrd = stack[(*top - 3 << 1) - 2];
    kmode = nametb_1.namtbl[*majwrd - 1] - geom[0];
    if (kmode > *modhlf) {
	kmode -= *modhlf;
    }
/* ... DETERMINE SIZE OF BOUNDS OR OBJECT CANONICAL FORM */
    if (kmode == *bounds) {
	tmp_1.txxxx[(kmode << 1) - 2] = *argtop + 2;
    }
    if (kmode == *object) {
	tmp_1.txxxx[(kmode << 1) - 2] = (*argtop << 1) + 2;
    }
    if (*tip == 37) {
	goto L201;
    }
    result = stack[(*top - 5 << 1) - 2];
    k = *modulo * (nametb_1.namtbl[result - 1] / *modulo);
    if (k == vbl[0] || k == temp[0]) {
	goto L202;
    }
    nametb_1.namtbl[result - 1] = vbl[0] + kmode;
    resrvz_(&result, &kmode, &tmp_1.txxxx[(kmode << 1) - 2], &c__1);
    goto L202;
L201:
    result = gettmp_(&kmode);
    *nestg = TRUE_;
L202:
    argstk[*argtop + 1] = result;
    *argtop += 2;
    if (*intmed != 1) {
	goto L206;
    }
    *way = 1;
    if (*finmac) {
	goto L204;
    }
    ergstk[99] = *top - 3;
    match_();
    if (! (*entry__) && *tip == 38) {
	goto L998;
    }
L228:
    kmode = nametb_1.namtbl[*majwrd - 1] - geom[0];
    if (kmode > *modhlf) {
	kmode -= *modhlf;
    }
    goto L206;
L204:
    path_();
    if (! (*should)) {
	goto L998;
    }
L206:
    l = mode_(&result);
    if (l == kmode) {
	goto L207;
    }

/* ... IF THIS VARIABLE HAS BEEN PREVIOUSLY DEFINED WITH ANOTHER MODE, */
/* ... ISSUE ERROR AND TERMINATE PROCESSING. */
    i__1 = *top - 5;
    alarm_(&c__1001, &i__1, &c__8, "PRO020  ", (ftnlen)8);
    goto L998;

/* ... IF THIS VARIABLE HAS BEEN PREVIOUSLY DEFINED WITH THE SAME MODE, */
/* ... ISSUE WARNING AND CONTINUE PROCESSING */
L207:
    if (k == vbl[0] && *intmed == 0) {
	i__1 = *top - 5;
	alarm_(&c__50, &i__1, &c__4, "PRO020  ", (ftnlen)8);
    }
/* ....    BYPASS IDENTIFIER PROCESSING IF PARAMETRIC SURFACE DEFINITION */
    if (kmode == *parsrf) {
	goto L1000;
    }
    k = *top + 1;
    stack[(k << 1) - 1] = -1;
    i__1 = *argtop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	++k;
	l = argstk[i__ - 2];
	errpt = 1 - i__;
	if (l <= nametb_1.nammax) {
	    goto L205;
	}
	iarg = *real__;
	goto L208;
L205:
	m = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
	iarg = nametb_1.namtbl[l - 1] - m;
	if (iarg >= *modhlf) {
	    iarg -= *modhlf;
	}
/* L210: */
	if (m == vbl[0] || m == temp[0]) {
	    goto L208;
	}
	if (m == permid[0]) {
	    goto L209;
	}
	if (m != number[0]) {
	    goto L999;
	}
	iarg = *real__;
	goto L208;

/* ...     PLACE NAMTBL POINTER OF INTEGER EQUIVALENT OF THE IDENTIFIER */
/* ...         (POSX,XLARGE,ETC.) IN ARGSTK. IF ARGMXY CONTAINS 0 FOR */
/* ...         THIS IDENTIFIER LEAVE ORIGINAL POINTER IN ARGSTK. */

L209:
	if (iarg == 0) {
	    goto L999;
	}
	if (gmty_1.argmxy[iarg - 1] != 0) {
	    argstk[i__ - 2] = gmty_1.argmxy[iarg - 1] + nametb_1.nammax;
	}
	iarg += 50;
L208:
	stack[(k << 1) - 1] = gmty_1.pmidtb[iarg - 1];
/* L211: */
    }
/* L90: */
    l = gmty_1.geoloc[kmode - 1];
    errpt = *argtop - 1;
    kt2 = k << 1;
    i__ = search_(stack, &kt2, &gmty_1.geomtb[l - 1], &errpt);

/* ... BRANCH ON HUNDREDS POSITION OF GEOMETRIC ACTION NUMBER. */

    j = i__ / 100 + 1;
    errp = errpt;
    switch (j) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L1000;
	case 5:  goto L2000;
    }
L100:
    pro021_(&result, &i__, &errp);
L998:
    if (! (*entry__)) {
	goto L20;
    }
    ergstk[99] = 0;
    match_();
    if (*entry__) {
	goto L228;
    }

/* ... ADJUST STACK AND EXIT  .......................................... */

L20:
    if ((i__1 = *tip - 38) < 0) {
	goto L225;
    } else if (i__1 == 0) {
	goto L226;
    } else {
	goto L227;
    }
L225:
    *top += -4;
    *nestg = FALSE_;
L230:
    stack[(*top << 1) - 2] = result;
    k = nametb_1.namtbl[result - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[k - 1];
L231:
    *argtop = 0;
/* L995: */
    return 0;
L226:
    *newstm = TRUE_;
    goto L231;
L227:
    *top += -6;
    goto L230;

L999:
    alarm_(&c__2001, &errpt, &c__8, "PRO020  ", (ftnlen)8);
L1001:
    callzz_(undef);
    argcvt_(&result);
    rlslin_();
    *argtop = 0;
    goto L998;

/*        *************************************************** */
/*        **** PARAMETRIC SURFACE DEFINITION PROCESSING  **** */
/*        *************************************************** */

L1000:
    if (*tip == 37) {
	goto L1057;
    }
/* ...     PROCESS EACH PARAMETER IN THE PARSRF DEFINITION. CHECK FOR A */
/* ...     VARIABLE OR IDENTIFIER-OTHERWISE ISSUE DIAGNOSTIC. */
/* L1010: */
    for (l = 2; l <= 11; ++l) {
	k = l;
	if (k >= *argtop) {
	    goto L1042;
	}
	karg = *argtop - k;
	j = argstk[karg - 1];
/* ...     SAVE NAME TABLE POINTER FOR FINAL CALL ARGUMENT LIST */
	jlist[k - 1] = j;
	if (k == 4) {
	    goto L1030;
	}
	if (j > nametb_1.nammax) {
	    goto L1059;
	}
	if (nametb_1.namtbl[j - 1] == vbl[0] + *real__) {
	    goto L1040;
	}
	if (nametb_1.namtbl[j - 1] != permid[0] && nametb_1.namtbl[j - 1] != 
		ident[0]) {
	    goto L1059;
	}
/* ...     SET MODE OF THIS PARAMETER TO REAL VARIABLE. */
	nametb_1.namtbl[j - 1] = vbl[0] + *real__;
	resrvz_(&j, real__, &tmp_1.txxxx[(*real__ << 1) - 2], &c__1);
	goto L1040;

/* ...     CHECK FOURTH ARGUMENT FOR DERIV OR NODER. */
/* ...     FOR DERIV-PASS ONE, FOR NODER-PASS ZERO. */
L1030:
	if (j > nametb_1.nammax) {
	    goto L1060;
	}
	if (s_cmp(cnamtb_1.cnamtb + (j - 1) * 6, deriv, (ftnlen)6, (ftnlen)6) 
		== 0) {
	    jlist[k - 1] = *one;
	}
	if (s_cmp(cnamtb_1.cnamtb + (j - 1) * 6, noder, (ftnlen)6, (ftnlen)6) 
		== 0) {
	    jlist[k - 1] = *zero;
	}
	if (jlist[k - 1] != *one && jlist[k - 1] != *zero) {
	    goto L1060;
	}

L1040:
	;
    }
/* ...     TOO MANY PARAMETERS IN THIS DEFINITION (LIMIT IS 10) */
    goto L1061;

/* ...     PASS A TEMPORARY FOR ALL UNUSED SURFACE PARAMETERS */
L1042:
    if (k == 11) {
	goto L1047;
    }
    if (k < 5) {
	goto L1061;
    }
    for (l = k; l <= 10; ++l) {
	karg = gettmp_(real__);
	jlist[l - 1] = karg;
/* L1045: */
    }

/* ...     GENERATE A CALL TO APT101 WITH APPROPRIATE ARGUMENTS */
L1047:
    callzz_(&aptxxx[94]);
    argcvt_(&argstk[*argtop - 1]);
    for (l = 2; l <= 10; ++l) {
	argcvt_(&jlist[l - 1]);
	if (l == 4) {
	    twoarg_(dbldlr, &argstk[*argtop - 2]);
	}
/* L1050: */
    }

/* ...     DEFINITION PROCESSING FINISHED */
    *argtop = 0;
    *pardef = TRUE_;
    rlslin_();
    goto L998;

/* ....    ERROR PROCESSING */

L1057:
    ierr = 7;
    errpt = *top - 3;
    goto L1070;
L1059:
    ierr = 9;
    goto L1062;
L1060:
    ierr = 10;
    goto L1062;
L1061:
    ierr = 11;
L1062:
    errpt = -karg;

L1070:
    alarm_(&ierr, &errpt, &c__8, "PRO020  ", (ftnlen)8);
/* ....    GENERATE A CALL TO UNDEF FOR THIS SURFACE */
    goto L1001;


/* ******************************************************************** */
/* ... RULED SURFACE DEFINITION STATEMENT PROCESSING */
/* ******************************************************************** */

/* ... COMPRESS ARGSTK TO REMOVE RESULT AND SET LENGTH = NUMBER OF */
/* ... ARGUMENTS IN PART PROGRAMMING STATEMENT */

L2000:
    --(*argtop);
    length = *argtop;

/* ... CHECK FOR VALID NUMBER OF ARGUMENTS */

    if (i__ == 401 && length == 5 || i__ == 402 && length == 8) {
	goto L2005;
    }
    errpt = i__ / 402 * 3 + 5 - *argtop;
    if (errpt > 0) {
	errpt = -1;
    }
    goto L999;

/* ... CALCULATE THE SIZE OF THE EXTERNAL CANONICAL FORM. */
/* ... */
/* ... SIZE OF FORM GENERATED FROM 5 ARGUMENT STATEMENT = SIZE OF */
/* ... SURFACE IN FIRST ARGUMENT + 39 */
/* ... */
/* ... SIZE OF FORM GENERATED FROM 8 ARGUMENT STATEMENT = SIZE OF */
/* ... SURFACE IN FIRST ARGUMENT + SIZE OF SURFACE IN FIFTH ARGUMENT + 48 */

L2005:
    nowrds = 42;
    if (length == 5) {
	nowrds = 46;
    }
    i__1 = *argtop;
    for (j = 4; j <= i__1; j += 4) {
	kk = argstk[j - 1];
	errpt = j;
	if (length != 5) {
	    goto L2006;
	}
	kk = argstk[j];
	errpt = j + 1;
L2006:
	k = mode_(&kk);
	if (k != 11) {
	    goto L2020;
	}

/* ... SURFACE IS A TABCYL. SEARCH FOR ITS SIZE IN CANSIZ. */

	l = kk - *cantop * (kk / *cantop);
	i__2 = *cantop;
	for (m = 1; m <= i__2; ++m) {
	    l = l + 1 - *cantop * (l / *cantop);
	    if (cansiz[(l << 1) - 1] != kk) {
		goto L2010;
	    }
	    nowrds = nowrds + cansiz[(l << 1) - 2] + 13;
	    goto L2030;
L2010:
	    ;
	}

/* ... TABCYL NOT FOUND. CALL ALARM. */

	i__2 = -errpt;
	alarm_(&c__1026, &i__2, &c__8, "PRO020  ", (ftnlen)8);
	goto L1001;

/* ... SURFACE IS NOT A TABCYL. GET ITS SIZE FROM TXXXX. */

L2020:
	nowrds = nowrds + tmp_1.txxxx[(k << 1) - 2] + 13;
L2030:
	;
    }

/* ... CHECK IF THIS RLDSRF IS ONE OF THE TWO LARGEST LARGE DATA ARRAY */
/* ... CANONICAL FORMS ENCOUNTERED AND IF SO, SAVE ITS SIZE IN MAXSIZ. */

    if (nowrds <= abs(maxsiz[0])) {
	goto L2050;
    }
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = nowrds;
    goto L2060;
L2050:
    if (nowrds > abs(maxsiz[1])) {
	maxsiz[1] = nowrds;
    }

/* ... GENERATE CALL TO APT033. */

L2060:
    callzz_(&aptxxx[58]);
    arggen_();
    if (length == 8) {
	goto L2080;
    }

/* ... 5 ARGUMENT FORMAT - ZERO ARGUMENTS 6-8 IN CALL TO APT033. */

    for (j = 1; j <= 3; ++j) {
/* L2070: */
	argcvt_(zero);
    }

/* ... INSERT LENGTH AND RESULT AS ARGUMENTS 9 AND 10 OF CALL. */

L2080:
    twoarg_(quidlr, &length);
    argcvt_(&result);
    rlslin_();
    goto L998;
} /* pro020_ */

#undef aptxxx
#undef ergstk
#undef newstm
#undef maxsiz
#undef modulo
#undef quidlr
#undef majwrd
#undef intmed
#undef should
#undef bounds
#undef parsrf
#undef cansiz
#undef argtop
#undef argstk
#undef number
#undef cantop
#undef permid
#undef estack
#undef modhlf
#undef object
#undef dbldlr
#undef pardef
#undef finmac
#undef entry__
#undef nestg
#undef stack
#undef ident
#undef undef
#undef zero
#undef temp
#undef geom
#undef meta
#undef real__
#undef top
#undef way
#undef vbl
#undef one


