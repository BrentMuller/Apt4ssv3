/* REPLAC.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

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
static integer c__1012 = 1012;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006676.V03   *** */


/*              FORTRAN SUBROUTINE REPLAC */

/* LINKAGE      SUBROUTINE  REPLAC */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ARGCVT          SUBROUTINE    RECOG */
/*          SUBROUTINE    MATCH           SUBROUTINE    LOOP */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PATH */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    SETMOD */
/*          LOGICAL FCT.  IFTMP */

/* Subroutine */ int replac_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k;
#define vbl ((integer *)&code_1 + 60)
#define way ((integer *)&macxx1_1 + 25)
#define top ((integer *)&stklst_1)
    extern integer mode_(integer *);
    extern /* Subroutine */ int path_(void);
#define repl ((integer *)&il_1 + 16)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen), match_(void);
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
#define relat ((integer *)&code_1 + 52)
    extern logical iftmp_(integer *);
    static integer modxx;
#define entry__ ((logical *)&macxx1_1 + 39)
#define finmac ((logical *)&macxx1_1 + 23)
    extern /* Subroutine */ int opcode_(integer *);
#define congeo ((integer *)&code_1 + 76)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int onearg_(integer *);
#define intmed ((integer *)&macxx1_1 + 21)
#define majwrd ((integer *)&macxx1_1 + 22)
    extern /* Subroutine */ int argcvt_(integer *);
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define should ((logical *)&macxx1_1 + 69)
#define modulo ((integer *)&moduli_1)
#define conpro ((integer *)&code_1 + 78)
#define ergstk ((integer *)&errpos_1 + 202)
    extern /* Subroutine */ int setmod_(integer *, integer *), rlslin_(void), 
	    puttmp_(integer *), resrvz_(integer *, integer *, integer *, 
	    integer *);



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* RELAT:       (1)=CODE CLASS 27000,(2)=NAMTBL INDEX OF 'RELAT ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/* CONGEO:      (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO' */
/* CONPRO:      (1)=CODE CLASS 40000,(2)=NAMTBL INDEX OF 'CONPRO' */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */
/* MAJWRD:      CONTAINS ACTUAL MAJOR WORD */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* ** */
    k = stack[(*top - 1 << 1) - 2];
    *majwrd = stack[(*top - 3 << 1) - 2];
    ergstk[99] = *top - 3;
    if (*intmed != 1) {
	goto L30;
    }
    *way = 4;
    if (*finmac) {
	goto L20;
    }
    *argtop = 1;
    argstk[0] = k;
L10:
    match_();
    k = argstk[0];
    if (! (*entry__)) {
	goto L210;
    }
    goto L30;
L20:
    path_();
    if (! (*should)) {
	goto L210;
    }
L30:
    modxx = mode_(&k);
/*          CHANGE CLASS IF IDENTIFIER */
    j = *modulo * (nametb_1.namtbl[*majwrd - 1] / *modulo);
    if (j != ident[0] && j != conpro[0] && j != congeo[0] && j != relat[0]) {
	goto L100;
    }
/* L150: */
    resrvz_(majwrd, &modxx, &tmp_1.txxxx[(modxx << 1) - 2], &c__1);
    i__1 = *top - 3;
    setmod_(&i__1, vbl);
    nametb_1.namtbl[*majwrd - 1] += modxx;
    goto L200;
L100:
    if (mode_(majwrd) == modxx) {
	goto L200;
    }
    i__1 = *top - 1;
    alarm_(&c__1012, &i__1, &c__8, "REPLAC  ", (ftnlen)8);

L200:
    opcode_(repl);
    onearg_(&tmp_1.txxxx[(modxx << 1) - 2]);
    argcvt_(majwrd);
    argcvt_(&k);
    rlslin_();
    if (*entry__) {
	goto L10;
    }
L210:
    *argtop = 0;
    if (iftmp_(&k)) {
	i__1 = mode_(&k);
	puttmp_(&i__1);
    }
/* L300: */
    return 0;
} /* replac_ */

#undef ergstk
#undef conpro
#undef modulo
#undef should
#undef argtop
#undef argstk
#undef majwrd
#undef intmed
#undef estack
#undef congeo
#undef finmac
#undef entry__
#undef relat
#undef stack
#undef ident
#undef repl
#undef top
#undef way
#undef vbl


