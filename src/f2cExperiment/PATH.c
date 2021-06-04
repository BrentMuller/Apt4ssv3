/* PATH.f -- translated by f2c (version 20100827).
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
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx7[182];
} macxx7_;

#define macxx7_1 macxx7_

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : M0006663.V03   *** */


/*              FORTRAN SUBROUTINE PATH */

/* LINKAGE      SUBROUTINE PATH */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CALMCX          SUBROUTINE    INPUT */
/*          SUBROUTINE    MACLBL          SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    REPLAC */

/* Subroutine */ int path_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j;
#define way ((integer *)&macxx1_1 + 25)
#define nxtln ((integer *)&macxx1_1 + 68)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define pathch ((integer *)&macxx1_1 + 70)
    extern /* Subroutine */ int calmcx_(integer *, integer *, integer *);
#define pathln ((integer *)&macxx1_1 + 67)
#define mcsavp ((integer *)&macxx1_1 + 4)
#define numarg ((integer *)&macxx1_1 + 60)
#define should ((logical *)&macxx1_1 + 69)
#define linusd ((integer *)&macxx7_1)
#define lnusdp ((integer *)&macxx1_1 + 50)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*       22.    MACRO PROCESSING VARIABLES */







/* MCSAVP:      PRESENT NEST LEVEL DURING MACRO PROCESSING */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* LNUSDP:      INDEX OF LAST LINUSD ENTRY */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* PATHLN:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */
/* NXTLN:       POINTER TO NEXT LINUSD POSITION TO BE EXAMINED */
/* SHOULD:      MACRO INDICATOR. NORMALLY FALSE */
/* PATHCH:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */

/*      26A.    MACRO PROCESSING ARRAYS */

/* LINUSD:      NUMBERS OF EXPRESSIONS REQUIRING BRANCHING FOR MACROS */
/* ** */
    ++(*pathln);
    if (*numarg == 0) {
	goto L1;
    }
    if (*nxtln <= *lnusdp) {
	goto L3;
    }
L1:
    *should = TRUE_;
/* L2: */
    return 0;
L3:
    if (*pathln != linusd[*nxtln - 1]) {
	goto L1;
    }
    ++(*pathch);
    i__1 = -(*mcsavp);
    i__2 = -(*pathch);
    maclbl_(&i__1, &i__2, &i__);
    nametb_1.namtbl[i__ - 1] = 1;
    j = 0;
    if (*way == 5) {
	j = *mcsavp;
    }
    calmcx_(&i__, &j, &c__2);
    *should = FALSE_;
    ++(*nxtln);
    return 0;
} /* path_ */

#undef lnusdp
#undef linusd
#undef should
#undef numarg
#undef mcsavp
#undef pathln
#undef pathch
#undef nxtln
#undef way


