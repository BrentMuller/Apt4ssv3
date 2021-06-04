/* TWOARG.f -- translated by f2c (version 20100827).
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
    integer iltext[94];
} iltext_;

#define iltext_1 iltext_

struct {
    integer opmod[8];
} opmod_;

#define opmod_1 opmod_

struct {
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* Table of constant values */

static integer c__0 = 0;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006691.W03   *** */


/*              FORTRAN SUBROUTINE TWOARG */

/* LINKAGE      SUBROUTINE TWOARG(I,J) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    ARGCVT */
/*                                        SUBROUTINE    ASNJPZ */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    CALMCX */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    RESRVZ */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int twoarg_(integer *i__, integer *j)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer k, idp;
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define comfin ((logical *)&iltext_1)
#define hexdlr ((integer *)&opmod_1 + 6)
    static integer ierror;
#define sptdlr ((integer *)&opmod_1 + 7)
#define textin ((integer *)&iltext_1 + 4)
#define tpntrx ((integer *)&iltext_1 + 2)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* CNUMTB:      NUMBER TABLE */


/*       19.    INTERMEDIATE LANGUAGE TEXT */







/* COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN */
/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */

/*       27.    OPERAND MODIFIERS */

/* HEXDLR:      CONTAINS OPERAND TYPE CODE 6 */
/* SPTDLR:      CONTAINS OPERAND TYPE CODE 7 */

/*       45.    NUMBER TABLE INDICES */

/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NMBRS:       QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* * */
/* ARGUMENTS    I         NORMALLY TYPE DESIGNATION OF */
/*                        ARGUMENT J.  COULD BE A NAME */
/*                        TABLE (NAMTBL) INDEX OF NUMBER. */
/*              J         NAME TABLE (NAMTBL) INDEX OF */
/* **                      ARGUMENT. */

/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

    if (*comfin) {
	goto L10;
    }
    ierror = 3;
    goto L90;
L10:
    if (*tpntrx < 89) {
	goto L20;
    }
    ierror = 2;
L90:
    alarm_(&ierror, &c__0, &c__8, "TWOARG  ", (ftnlen)8);
    goto L100;
L20:
    k = *i__;
    if (*j <= numblk_1.mnmbnd + nametb_1.nammax) {
	goto L30;
    }
/*     HEXDLR: INDICATES NON FRACTIONAL REAL LITERAL */
/*     SPTDLR: INDICATES FRACTIONAL REAL LITERAL */
    k = *hexdlr;
    idp = i_indx(cnamtb_1.cnumtb + (*j - nametb_1.nammax - 1) * 12, ".", (
	    ftnlen)12, (ftnlen)1);
    i__1 = idp;
    if (s_cmp(cnamtb_1.cnumtb + ((*j - nametb_1.nammax - 1) * 12 + i__1), 
	    " ", 12 - i__1, (ftnlen)1) == 0) {
	goto L30;
    }
    k = *sptdlr;
    ++numblk_1.nmbrs;
L30:
    textin[*tpntrx] = k;
    textin[*tpntrx + 1] = *j;
    *tpntrx += 2;
L100:
    return 0;
} /* twoarg_ */

#undef tpntrx
#undef textin
#undef sptdlr
#undef hexdlr
#undef comfin


