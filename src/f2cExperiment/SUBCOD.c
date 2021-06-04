/* SUBCOD.f -- translated by f2c (version 20100827).
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
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer isscom[9];
} isscom_;

#define isscom_1 isscom_

/* Table of constant values */

static integer c__1013 = 1013;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006689.V03   *** */


/*              FORTRAN SUBROUTINE SUBCOD */

/* LINKAGE      SUBROUTINE SUBCOD (TPX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          LOGICAL FCT.  IFTMP           SUBROUTINE    RECOG */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    ALARM */
/*          INTEGER FCT.  MODE */
/*          SUBROUTINE    ARGCVT */

/* Subroutine */ int subcod_(integer *tpx)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, m, n, ii;
#define vbl ((integer *)&code_1 + 60)
#define top ((integer *)&stklst_1)
    extern integer mode_(integer *);
#define temp ((integer *)&code_1 + 32)
    static integer rslt;
#define range ((integer *)&sbscpt_1 + 1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define stack ((integer *)&stklst_1 + 3)
#define ilhlt ((logical *)&macxx1_1 + 13)
    extern logical iftmp_(integer *);
#define issfl ((logical *)&isscom_1 + 5)
#define rngpt ((integer *)&sbscpt_1)
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define intmed ((integer *)&macxx1_1 + 21)
    extern /* Subroutine */ int argcvt_(integer *);
#define modulo ((integer *)&moduli_1)
#define issmod ((integer *)&isscom_1 + 4)
#define subscr ((integer *)&modx_1 + 23)
    extern integer gettmp_(integer *);
    extern /* Subroutine */ int rlslin_(void);
    static integer ierror;
#define cvtsub ((integer *)&il_1 + 12)
#define isstrm ((integer *)&isscom_1 + 7)
    extern /* Subroutine */ int puttmp_(integer *);



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*       15.    ARRAY LIMIT STORAGE */

/* RNGPT:       POINTER TO NEXT RANGE ENTRY */
/* RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* CVTSUB:      CONTAINS COMMAND CODE (13) FOR CVTSUB COMMAND */

/*       17.    MODE CODES */

/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */

/*       22.    MACRO PROCESSING VARIABLES */

/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       37.    INCLUSIVE SUBSCRIPT VARIABLES */

/* ISSMOD:      MODE OF THE INCLUSIVE SUBSCRIPTED VARIABLE */
/* ISSFL:       TRUE DURING INCLUSIVE SUBSCRIPT PROCESSING */
/* ISSTRM:      SAVES THE STACK TOP ITEMS DURING SUBSCRIPT PROCESSING */
/* * */
/* ARGUMENTS    TPX       WORKING STACK (STACK) INDEX WHICH */
/*                        POINTS TO THE VARIABLE NAME OF A */
/* **                      SUBSCRIPTED VARIABLE. */

/*     GET RESULT CELL */
    rslt = gettmp_(subscr);
    nametb_1.namtbl[rslt - 1] = temp[0] + *subscr;

/*     FIND POSITION IN RANGE TABLE */
    if (*rngpt == 1) {
	goto L62;
    }
    j = *rngpt - 2;
    n = stack[(*tpx << 1) - 2];
    i__1 = j;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	if (range[i__ - 1] == n) {
	    goto L20;
	}
/* L10: */
    }
    goto L60;

/*     GENERATE CODE */
L20:
    ii = stack[(*tpx + 2 << 1) - 2];
    if (ii > nametb_1.nammax) {
	goto L30;
    }
    if (iftmp_(&ii)) {
	i__1 = nametb_1.namtbl[ii - 1] % *modulo;
	puttmp_(&i__1);
    }
L30:
    i__ = mode_(&n);
    if (i__ == 0) {
	goto L65;
    }
    if (*issfl) {
	*issmod = i__;
    }
    opcode_(cvtsub);
    argcvt_(&rslt);
    argcvt_(&n);
    argcvt_(&stack[(*tpx + 2 << 1) - 2]);
    onearg_(&tmp_1.txxxx[(i__ << 1) - 2]);
    rlslin_();

/* ...       MODIFY NAMTBL ENTRY TO MODE + 50 */

    nametb_1.namtbl[rslt - 1] = temp[0] + i__ + *modhlf;

/*     MODIFY STACK */
    stack[(*tpx << 1) - 2] = rslt;
L90:
    return 0;

/*     ERROR */
L60:
    if (*intmed < 0) {
	goto L61;
    } else if (*intmed == 0) {
	goto L62;
    } else {
	goto L63;
    }
L61:
    *ilhlt = FALSE_;
    alarm_(&c__1013, tpx, &c__8, "SUBCOD  ", (ftnlen)8);
    *ilhlt = TRUE_;
    goto L72;
L63:
    m = nametb_1.namtbl[n - 1];
    j = m / *modulo * *modulo;
    if (j == vbl[0] && m - j > *modhlf) {
	goto L20;
    }
L62:
    ierror = 1013;
    goto L70;
L65:
    ierror = 1014;
L70:
    alarm_(&ierror, tpx, &c__8, "SUBCOD  ", (ftnlen)8);
L72:
    if (! (*issfl)) {
	goto L90;
    }
    stack[(*top << 1) - 2] = isstrm[0];
    stack[(*top << 1) - 1] = isstrm[1];
    *issfl = FALSE_;
    goto L90;
} /* subcod_ */

#undef isstrm
#undef cvtsub
#undef subscr
#undef issmod
#undef modulo
#undef intmed
#undef modhlf
#undef rngpt
#undef issfl
#undef ilhlt
#undef stack
#undef range
#undef temp
#undef top
#undef vbl


