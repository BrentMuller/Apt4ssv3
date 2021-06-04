/* GETTMP.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : M0006633.V05   *** */


/*              FORTRAN SUBROUTINE GETTMP */

/* LINKAGE      INTEGER FUNCTION GETTMP(MODE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          INTEGER FCT.  NAME            SUBROUTINE    BOOLIF */
/*          SUBROUTINE    RESRVZ          SUBROUTINE    INPAT */
/*          SUBROUTINE    SHIFT           SUBROUTINE    ISSCOD */
/*          SUBROUTINE    BINBCD          SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */

integer gettmp_(integer *mode)
{
    /* Initialized data */

    static char blk[1] = " ";

    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern integer name_(char *, ftnlen);
#define temp ((integer *)&code_1 + 32)
    static char symi[8];
    extern /* Subroutine */ int shift_(char *, char *, ftnlen, ftnlen);
    static integer count;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
    static char symbol[6];
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */
/* * */
/* PURPOSE      THIS ROUTINE RETURNS THE NAME TABLE (NAMTBL) */
/*              INDEX FOR THE CURRENT TEMPORARY NAME OF THIS */
/*              MODE. */

/* ARGUMENTS    MODE    THE MODE OF THE SURFACE REQUIRING */
/*                      TEMPORARY STORAGE. */

/* ARGUMENTS    MODE    THE MODE OF THE SURFACE REQUIRING */
/*                      TEMPORARY STORAGE. */

/* ** */
/* ...     INCREMENT COUNTER FOR THIS MODE */

    ++tmp_1.txxxx[(0 + (0 + (2 + (*mode << 1) - 3 << 2))) / 4];

/* ...     GENERATE NAME OF TEMPORARY LOCATION */

    s_copy(symbol, blk, (ftnlen)6, (ftnlen)1);

/* ...           START SYMBOL WITH A $ */

    shift_(symbol, "$", (ftnlen)6, (ftnlen)1);

/* ...     IS MODE .GT. 9 */

    if (*mode / 10 == 0) {
	goto L10;
    }

/* ...     YES. CONVERT TENS DIGIT OF MODE TO BCD AND SHIFT INTO SYMBOL */

    i__1 = *mode / 10;
    binbcd_(&i__1, symi, &count, (ftnlen)8);
    shift_(symbol, symi, (ftnlen)6, (ftnlen)8);

/* ...     CONVERT UNITS DIGIT TO BCD AND SHIFT INTO SYMBOL */

L10:
    i__1 = *mode % 10;
    binbcd_(&i__1, symi, &count, (ftnlen)8);
    shift_(symbol, symi, (ftnlen)6, (ftnlen)8);

/* ...           SHIFT T$ INTO SYMBOL */

    shift_(symbol, "T", (ftnlen)6, (ftnlen)1);
    shift_(symbol, "$", (ftnlen)6, (ftnlen)1);

/* ...     IS COUNTER FOR THIS MODE .GT. 9 */

    if (tmp_1.txxxx[(*mode << 1) - 1] / 10 == 0) {
	goto L20;
    }

/* ...     YES. CONVERT TENS DIGIT TO BCD AND SHIFT INTO SYMBOL */

    i__1 = tmp_1.txxxx[(*mode << 1) - 1] / 10;
    binbcd_(&i__1, symi, &count, (ftnlen)8);
    shift_(symbol, symi, (ftnlen)6, (ftnlen)8);

/* ...     CONVERT UNITS DIGIT OF POINTER TO BCD AND SHIFT INTO SYMBOL */

L20:
    i__1 = tmp_1.txxxx[(*mode << 1) - 1] % 10;
    binbcd_(&i__1, symi, &count, (ftnlen)8);
    shift_(symbol, symi, (ftnlen)6, (ftnlen)8);

/* ...     FIND NAMTBL INDEX OF NAME JUST CREATED AND STORE AS GETTMP */

    ret_val = name_(symbol, (ftnlen)6);

/* ...     IS FIRST COLUMN OF NAMTBL ZERO. */
/* ...     IF SO, THEN THIS IS THE FIRST APPEARENCE OF THIS NAME. */
/* ...     IF NOT, IT HAS BEEN USED BEFORE, SO RETURN. */

    if (nametb_1.namtbl[ret_val - 1] != 0) {
	return ret_val;
    }

/* ...     FIRST APPEARENCE - GENERATE RESRV CODE AND SET CORRECT CLASS */
/* ...     AND MODE IN COLUMN 1 OF NAMTBL. THEN RETURN. */

    resrvz_(&ret_val, mode, &tmp_1.txxxx[(*mode << 1) - 2], &c__1);
    nametb_1.namtbl[ret_val - 1] = temp[0] + *mode;
    return ret_val;
} /* gettmp_ */

#undef temp


