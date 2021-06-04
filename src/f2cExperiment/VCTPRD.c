/* VCTPRD.f -- translated by f2c (version 20100827).
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
    integer nametb[3007];
} nametb_;

#define nametb_1 nametb_

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
    integer flags[4];
} flags_;

#define flags_1 flags_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006692.V01   *** */


/*              FORTRAN SUBROUTINE VCTPRD */

/* LINKAGE      SUBROUTINE  VCTPRD(JMP) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          INTEGER FCT.  NAME            SUBROUTINE    RECOG */
/*          SUBROUTINE    SETCHR */

/* Subroutine */ int vctprd_(integer *jmp)
{
    /* Initialized data */

    static integer nmtb = 0;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
#define dot ((integer *)&code_1 + 48)
#define top ((integer *)&stklst_1)
    extern integer name_(char *, ftnlen);
#define meta ((integer *)&srctbl_1 + 2)
#define stack ((integer *)&stklst_1 + 3)
#define slash ((integer *)&code_1 + 8)
#define macred ((logical *)&macxx1_1 + 17)
#define endflg ((logical *)&flags_1)
#define namtbl ((integer *)&nametb_1 + 10)
#define permid ((integer *)&code_1 + 38)
#define lparen ((integer *)&code_1 + 2)
#define rparen ((integer *)&code_1 + 4)
    extern /* Subroutine */ int setchr_(integer *, integer *);
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define modulo ((integer *)&moduli_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */

/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* LPAREN:      (1)=CODE CLASS  2000,(2)=NAMTBL INDEX OF '(     ' */
/* RPAREN:      (1)=CODE CLASS  3000,(2)=NAMTBL INDEX OF ')     ' */
/* SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* DOT:         (1)=CODE CLASS 25000,(2)=NAMTBL INDEX OF 'DOT   ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        5.    PROGRAM CONTROL FLAGS */

/* ENDFLG:      TRUE WHEN SOURCE STATEMENT TOTALLY IN STACK */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*       22.    MACRO PROCESSING VARIABLES */

/* MACRED:      SET TRUE TO INDICATE INPUT FROM MCBUFF TABLE */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* ** */

    if (*jmp < 0) {
	goto L10;
    }
    *jmp = 1;
    if (nmtb == 0) {
	goto L50;
    }
    *jmp = 2;
    ++(*top);
    stack[(*top << 1) - 2] = nmtb;
    stack[(*top << 1) - 1] = meta[namtbl[nmtb * 3 - 3] / *modulo - 1];
    goto L40;

/*     VECTOR AND SCALAR PRODUCT */

L10:
    if (namtbl[stack[(*top - 2 << 1) - 2] * 3 - 3] == dot[0]) {
	goto L30;
    }

    *argtop = 2;
    argstk[0] = stack[(*top - 1 << 1) - 2];
    i__ = name_("$CROSS   ", (ftnlen)9);
    if (*modulo * (namtbl[i__ * 3 - 3] / *modulo) == permid[0]) {
	goto L20;
    }
    namtbl[i__ * 3 - 3] = permid[0] + 40;
L20:
    argstk[1] = i__;
    stack[(*top - 1 << 1) - 2] = stack[(*top - 3 << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top - 3 << 1) - 1];
    i__1 = *top - 2;
    setchr_(&i__1, slash);
    stack[(*top - 3 << 1) - 2] = name_("VECTOR  ", (ftnlen)8);
    stack[(*top - 3 << 1) - 1] = meta[namtbl[stack[(*top - 3 << 1) - 2] * 3 - 
	    3] / *modulo - 1];

    goto L40;

L30:
    *argtop = 1;
    nmtb = stack[(*top << 1) - 2];
    argstk[0] = stack[(*top - 1 << 1) - 2];
    setchr_(top, rparen);
    stack[(*top - 1 << 1) - 2] = stack[(*top - 3 << 1) - 2];
    stack[(*top - 1 << 1) - 1] = stack[(*top - 3 << 1) - 1];
    i__1 = *top - 2;
    setchr_(&i__1, lparen);
    stack[(*top - 3 << 1) - 2] = name_("DOTF    ", (ftnlen)8);
    stack[(*top - 3 << 1) - 1] = meta[namtbl[stack[(*top - 3 << 1) - 2] * 3 - 
	    3] / *modulo - 1];
    if (*macred) {
	goto L50;
    }
    *endflg = FALSE_;
    --inptr_1.cnt;

L40:
    nmtb = 0;
L50:
    return 0;

} /* vctprd_ */

#undef modulo
#undef argtop
#undef argstk
#undef rparen
#undef lparen
#undef permid
#undef namtbl
#undef endflg
#undef macred
#undef slash
#undef stack
#undef meta
#undef top
#undef dot


