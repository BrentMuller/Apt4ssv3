/* OPPAIR.f -- translated by f2c (version 20100827).
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
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__5 = 5;

/* *** SOURCE FILE : M0006662.W01   *** */


/*              FORTRAN SUBROUTINE OPPAIR */

/* LINKAGE      SUBROUTINE OPPAIR(BCDPR,OPERND) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    MCXTRN          SUBROUTINE    PRTIL */
/*          SUBROUTINE    BINBCD */

/* Subroutine */ int oppair_(char *bcdpr, integer *opernd, ftnlen bcdpr_len)
{
    /* Initialized data */

    static char modify[8*8] = "0       " "$       " "$$      " "$$$     " 
	    "$$$$    " "$$$$$   " "$$$$$$  " "$$$$$$$ ";
    static char blk[4] = "    ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define nlast ((integer *)&ntbl_1 + 3)
    static integer count;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
    static integer modfer, argmnt, idummy;
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NUMBST:      NAMTBL INDEX OF BEGINNING OF NUMBER SECTION */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */







/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */
/* * */
/* ARGUMENTS    BCDPR     OUTPUT STRING. BCD OF TYPE */
/*                        DESIGNATION PLACED IN (1:8) */
/*                        BCD OF SYMBOL (NAME OR NUMBER) */
/*                        PLACED IN (9:20) */
/*              OPERND    2 ELEMENT INPUT ARRAY.  TYPE */
/*                        DESIGNATION CODE IN 1ST ELEMENT. */
/*                        NAME TABLE (NAMTBL) INDEX OF SYMBOL */
/*                        IN 2ND ELEMENT. */
/* ** */
    /* Parameter adjustments */
    --opernd;

    /* Function Body */
    modfer = opernd[1];
    argmnt = opernd[2];
    if (modfer < 0) {
	goto L100;
    } else if (modfer == 0) {
	goto L200;
    } else {
	goto L300;
    }

/* ...  MODIFIER IS NEGATIVE (SUBSCRIPT) */

L100:
    i__1 = -modfer;
    binbcd_(&i__1, bcdpr, &count, (ftnlen)8);
    goto L400;

/* ...  MODIFIER IS ZERO */

L200:
    s_copy(bcdpr, modify, (ftnlen)8, (ftnlen)8);
    goto L400;

/* ...  MODIFIER IS POSITIVE (NO. OF DOLLAR SIGNS) */

L300:
    s_copy(bcdpr, modify + (modfer << 3), (ftnlen)8, (ftnlen)8);
    switch (modfer) {
	case 1:  goto L500;
	case 2:  goto L400;
	case 3:  goto L400;
	case 4:  goto L400;
	case 5:  goto L600;
	case 6:  goto L500;
	case 7:  goto L500;
    }

/* ...  ARGUMENT IS VARIABLE OR PROCEDURE INDEX */

L400:
    s_copy(bcdpr + 8, cnamtb_1.cnamtb + (argmnt - 1) * 6, (ftnlen)12, (ftnlen)
	    6);
    return 0;

/* ...  ARGUMENT IS REAL OR INTEGER CONSTANT INDEX */

/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
L500:
    argmnt -= nametb_1.nammax;
    if (*nlast > 0 && argmnt >= nametb_1.numbst) {
	mcxtrn_(&c__5, &argmnt, &idummy);
    }
    s_copy(bcdpr + 8, cnamtb_1.cnumtb + (argmnt - 1) * 12, (ftnlen)12, (
	    ftnlen)12);
    return 0;

/* ...  ARGUMENT IS INTEGER CONSTANT */

L600:
    binbcd_(&argmnt, bcdpr + 8, &count, (ftnlen)8);
    s_copy(bcdpr + 16, blk, (ftnlen)4, (ftnlen)4);
    return 0;
} /* oppair_ */

#undef nlast


