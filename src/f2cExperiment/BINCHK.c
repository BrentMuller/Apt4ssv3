/* BINCHK.f -- translated by f2c (version 20100827).
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
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* *** SOURCE FILE : M0006621.W02   *** */


/*              FORTRAN SUBROUTINE BINCHK */

/* LINKAGE      SUBROUTINE BINCHK(I) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    BCDBIN          SUBROUTINE    ICMPRS */

/* Subroutine */ int binchk_(integer *i__)
{
    /* Local variables */
    static integer j, k, kk;
    extern /* Subroutine */ int bcdbin_(char *, integer *, integer *, ftnlen);
#define textin ((integer *)&iltext_1 + 4)
#define optext ((integer *)&iltext_1 + 3)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* IFIXST:      NAMTBL INDEX OF BEGINNING OF FIXED POINT NUMBER SECTION */

/*       19.    INTERMEDIATE LANGUAGE TEXT */







/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */


/* ** */
/* ...     IS ARGUMENT MODIFIER 1 OR 6 */


/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

    if (textin[*i__ - 1] == 6) {
	goto L5;
    }
    if (textin[*i__ - 1] != 1) {
	return 0;
    }

/* ...     YES. IS INDEX A POINTER TO AN INTEGER */

    if (textin[*i__] > nametb_1.ifixst + 9) {
	return 0;
    }

/* ...     YES. STORE MODIFIER OF 5 AND BINARY INTEGER */

    textin[*i__ - 1] = 5;
L5:
    j = textin[*i__] - nametb_1.nammax;
    bcdbin_(cnamtb_1.cnumtb + (j - 1) * 12, &kk, &k, (ftnlen)12);
    if (kk > 32767) {
	textin[*i__ - 1] = 7;
	++numblk_1.nmbrs;
    } else {
	textin[*i__] = kk;
    }
    return 0;
} /* binchk_ */

#undef optext
#undef textin


