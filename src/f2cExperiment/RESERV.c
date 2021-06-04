/* RESERV.f -- translated by f2c (version 20100827).
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
    integer sbscpt[401];
} sbscpt_;

#define sbscpt_1 sbscpt_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__5 = 5;
static integer c__2026 = 2026;
static integer c__8 = 8;
static integer c__2027 = 2027;
static integer c__2044 = 2044;
static integer c__2018 = 2018;

/* *** SOURCE FILE : M0006677.W02   *** */


/*              FORTRAN SUBROUTINE RESERV */

/* LINKAGE      SUBROUTINE RESERV */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    MCXTRN          SUBROUTINE    PRO026 */
/*          SUBROUTINE    BCDBIN */
/*          SUBROUTINE    ALARM */

/* Subroutine */ int reserv_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ii, ep, iii;
#define vbl ((integer *)&code_1 + 60)
    static integer cnt;
#define top ((integer *)&stklst_1)
#define range ((integer *)&sbscpt_1 + 1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define nlast ((integer *)&ntbl_1 + 3)
#define rngpt ((integer *)&sbscpt_1)
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen);
#define permid ((integer *)&code_1 + 38)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)
    static integer idummy;
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*       15.    ARRAY LIMIT STORAGE */

/* RNGPT:       POINTER TO NEXT RANGE ENTRY */
/* RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */
/* * */
/* PURPOSE      TO RECORD DATA FROM RESERV SOURCE STATEMENT. */


/* NOTES        RANGE TABLE IS DIMENSIONED 100 AND HAS ROOM */
/*              FOR 25 ENTRIES (4 WORDS PER ENTRY). */

/* ...       CHECK FOR END OF TABLE */
/* ** */
    if (*argtop % 2 != 0) {
	goto L98;
    }
    ii = argstk[*argtop - 1];
L10:
    if (*rngpt >= 401) {
	goto L90;
    }

/* ...       SET UP RANGE TABLE */

    if ((i__1 = *argtop - 1) < 0) {
	goto L96;
    } else if (i__1 == 0) {
	goto L92;
    } else {
	goto L40;
    }
L40:
    ii = argstk[*argtop - 1];
    iii = argstk[*argtop - 2];
    if (ii > nametb_1.nammax) {
	goto L92;
    }
    if (iii <= nametb_1.nammax) {
	goto L91;
    }
    if (nametb_1.namtbl[ii - 1] / *modulo != permid[0] / *modulo) {
	goto L94;
    }
    nametb_1.namtbl[ii - 1] = vbl[0];
    range[*rngpt - 1] = ii;
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
    iii -= nametb_1.nammax;
    if (*nlast > 0) {
	mcxtrn_(&c__5, &iii, &idummy);
    }
    bcdbin_(cnamtb_1.cnumtb + (iii - 1) * 12, &range[*rngpt], &cnt, (ftnlen)
	    12);
    if (range[*rngpt] == 1) {
	range[*rngpt] = 2;
    }
    *rngpt += 2;
    *argtop += -2;
    if (*argtop > 0) {
	goto L10;
    }

L99:
    return 0;

/* ...       TOO MANY SUBSCRIPTED VARIABLES IN PART PROGRAM */
/* ...       RANGE TABLE FILLED */

L90:
    i__1 = -(*argtop);
    alarm_(&c__2026, &i__1, &c__8, "RESERV  ", (ftnlen)8);
    goto L99;

/* ...       INCORRECT FORMAT FOR RESERV STATEMENT */
/* ...       MUST BE SYMBOL, NUMBER */

L91:
    --(*argtop);
L92:
    i__1 = -(*argtop);
    alarm_(&c__2027, &i__1, &c__8, "RESERV  ", (ftnlen)8);
    goto L99;

/* ...       DUPLICATE NAME OF DIMENSIONED VARIABLE */

L94:
    i__1 = -(*argtop);
    alarm_(&c__2044, &i__1, &c__8, "RESERV  ", (ftnlen)8);
    goto L99;

/* ...       NO ARGUMENTS OR ODD NUMBER OF ARGUMENTS */

L96:
    ep = 1 - *top;
    goto L100;
L98:
    ep = 1;
L100:
    i__1 = -ep;
    alarm_(&c__2018, &i__1, &c__8, "RESERV  ", (ftnlen)8);
    goto L99;

} /* reserv_ */

#undef modulo
#undef argtop
#undef argstk
#undef permid
#undef rngpt
#undef nlast
#undef range
#undef top
#undef vbl


