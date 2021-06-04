/* LABCON.f -- translated by f2c (version 20100827).
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
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer seqcom[3];
} seqcom_;

#define seqcom_1 seqcom_

struct {
    integer prt[7];
} prt_;

#define prt_1 prt_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer doloop[8];
} doloop_;

#define doloop_1 doloop_

/* Table of constant values */

static integer c__1002 = 1002;
static integer c__0 = 0;
static integer c__4 = 4;
static integer c__1009 = 1009;
static integer c__40 = 40;

/* *** SOURCE FILE : M0006645.W01   *** */


/*              FORTRAN SUBROUTINE LABCON */

/* LINKAGE      SUBROUTINE LABCON(K) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    BINBCD          SUBROUTINE    PRO026 */
/*          SUBROUTINE    ALARM           SUBROUTINE    RECOG */

/* Subroutine */ int labcon_(integer *k)
{
    /* Initialized data */

    static integer labary[300]	/* was [2][150] */ = { 0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer labdm = 151;
    static integer iseq = 0;
    static integer labcnt = 0;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, l, m, n;
#define label ((integer *)&code_1 + 42)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ilhlt ((logical *)&macxx1_1 + 13)
#define seqno ((integer *)&seqcom_1)
    static logical prter;
    extern /* Subroutine */ int binbcd_(integer *, integer *, integer *);
#define modulo ((integer *)&moduli_1)
#define seqnum ((integer *)&seqcom_1 + 1)
#define prterr ((logical *)&prt_1 + 5)
#define jumpto ((integer *)&doloop_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */
/* SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRRENT STATEMENT NUMBER */

/*       14.    I. L. LIST OPTION FLAGS */

/* PRTERR:      TRUE IF PPOPTN/PRTER,ON. PRINTOUT OF STACK OR ARGSTK */

/*       22.    MACRO PROCESSING VARIABLES */

/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       43.    DO LOOP CONTROL VALUES */

/* JUMPTO:      MARKER SET AFTER JUMPTO OR IF FOR LABEL CONTROL */
/* * */
/* ** */
    if (*ilhlt) {
	goto L150;
    }
    l = abs(*k);
    if (l > 0) {
	m = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
    }
    if (*k < 0) {
	goto L50;
    } else if (*k == 0) {
	goto L100;
    } else {
	goto L10;
    }

/*     JUMPTO STATEMENT,SEARCH FOR FORMER LABEL */

L10:
    if (m == label[0]) {
	goto L40;
    }

/*     NO FORMER LABEL, SEARCH FOR FORMER JUMPTO */

    i__1 = labcnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (labary[(i__ << 1) - 2] != *k) {
	    goto L20;
	}
	if (labary[(i__ << 1) - 1] == 0) {
	    goto L40;
	}
L20:
	;
    }
    ++labcnt;
    if ((i__1 = labcnt - labdm) < 0) {
	goto L30;
    } else if (i__1 == 0) {
	goto L160;
    } else {
	goto L40;
    }
L30:
    labary[(labcnt << 1) - 2] = *k;
    labary[(labcnt << 1) - 1] = *seqno;
L40:
    if (iseq == *seqno) {
	goto L150;
    }
    iseq = *seqno;
    goto L130;

/*     LABEL STATEMENT, SEARCH FOR FORMER JUMPTO */

L50:
    i__1 = labcnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (labary[(i__ << 1) - 2] == l) {
	    labary[(i__ << 1) - 1] = 0;
	}
/* L60: */
    }
    goto L140;

/*     FINI OR TERMAC HAS COME */

L100:
    if (labcnt == 0) {
	goto L130;
    }
    if (labcnt >= labdm) {
	labcnt = labdm - 1;
    }
    l = seqnum[0];
    m = seqnum[1];
    prter = *prterr;
    *prterr = FALSE_;
    i__1 = labcnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (labary[(i__ << 1) - 1] == 0) {
	    goto L110;
	}
	binbcd_(&labary[(i__ << 1) - 1], seqnum, &n);
	labary[(i__ << 1) - 1] = 0;
	alarm_(&c__1002, &c__0, &c__4, "LABCON  ", (ftnlen)8);
L110:
	;
    }
    labcnt = 0;
    seqnum[0] = l;
    seqnum[1] = m;
    *prterr = prter;
L130:
    if (*jumpto != 0) {
	alarm_(&c__1009, &c__0, &c__4, "LABCON  ", (ftnlen)8);
    }
L140:
    *jumpto = 0;
    if (*k > 0) {
	*jumpto = *seqno + 2;
    }

L150:
    return 0;
L160:
    alarm_(&c__40, &c__0, &c__4, "LABCON  ", (ftnlen)8);
    goto L130;
} /* labcon_ */

#undef jumpto
#undef prterr
#undef seqnum
#undef modulo
#undef seqno
#undef ilhlt
#undef label


