/* NUMB.f -- translated by f2c (version 20100827).
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
    integer mnmbnd, numidx, nmbrs, lstchr, masgnd;
} numblk_;

#define numblk_1 numblk_

/* *** SOURCE FILE : M0006659.W02   *** */


/*              FORTRAN SUBROUTINE NUMB */

/* LINKAGE      INTEGER FUNCTION NUMB(STR) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*                                        SUBROUTINE    GOLO */
/*                                      SUBROUTINE    INPAT */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    TSSMIL */

integer numb_(char *str, ftnlen str_len)
{
    /* Initialized data */

    static char blk[12] = "            ";

    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k;



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* CNUMTB:      NUMBER TABLE */
/* NUMBST:      INDEX OF BEGINNING OF NUMBER SECTION IN CNUMTB */
/* NUMBND:      INDEX OF END OF NUMBER SECTION IN CNUMTB */








/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */
/* * */
/* ARGUMENTS    STR     A CHARACTER VARIABLE CONTAINING THE */
/*                      CHARACTERS OF THE NUMBER */

/*       45.    NUMBER TABLE INDICES */


/* MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION */
/* NUMIDX:      NAMTBL INDEX OF A NUMBER GIVEN IN THE CURRENT STATEMENT */
/*  NMBRS:      QUANTITY OF NUMBERS IN THE CURRENT STATEMENT */
/* LSTCHR:      LAST CHARACTER OF A NUMBER */
/* MASGND:      NAME TABLE INDEX OF SECTION END FOR NUMBERS ASSIGNMENT */

/* ** */
    k = numblk_1.numidx + 1;
    if (k <= nametb_1.numbnd) {
	numblk_1.numidx = k;
    } else {
	i__1 = nametb_1.numbnd;
	for (i__ = numblk_1.mnmbnd; i__ <= i__1; ++i__) {
	    --k;
	    if (s_cmp(cnamtb_1.cnumtb + (k - 1) * 12, blk, (ftnlen)12, (
		    ftnlen)12) == 0) {
		goto L40;
	    }
/* L20: */
	}
	k = nametb_1.numbnd;
    }
L40:
    s_copy(cnamtb_1.cnumtb + (k - 1) * 12, str, (ftnlen)12, (ftnlen)12);
    numblk_1.lstchr = numblk_1.numidx;
    ret_val = k;
    return ret_val;
} /* numb_ */

