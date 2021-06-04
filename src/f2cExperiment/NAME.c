/* NAME.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__3001 = 3001;
static integer c__0 = 0;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006658.W01   *** */


/*              FORTRAN SUBROUTINE NAME */

/* LINKAGE      INTEGER  FUNCTION  NAME  (STR) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    COMSTR */
/*          INTEGER FCT.  BCDF            INTEGER FCT.  GETTMP */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    INPUT */
/*                                        SUBROUTINE    IPRLOG */
/*                                        SUBROUTINE    MACLBL */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    RESRVZ */
/*                                        SUBROUTINE    VCTPRD */

integer name_(char *str, ftnlen str_len)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMEST:      NAMTBL INDEX OF BEGIN OF THE PART PROGRAM NAME SECTION */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */
/* * */
/* ARGUMENTS    STR     A CHARACTER STRING CONTAINING THE ALPHA */
/*                      NUMERIC CHARACTERS OF THE SYMBOL. */







/* ** */
/* L10: */
    j = bcdf_(str, (ftnlen)6) % (nametb_1.nammax - nametb_1.namest);
    if (j < 0) {
	j += nametb_1.nammax;
    } else {
	j += nametb_1.namest;
    }
    i__1 = nametb_1.nammax;
    for (i__ = j; i__ <= i__1; ++i__) {
	if (nametb_1.namtbl[i__ - 1] == 0) {
	    goto L40;
	}
	if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, str, (ftnlen)6, (ftnlen)6) 
		== 0) {
	    goto L100;
	}
/* L20: */
    }

/* ...       SCAN TABLE FROM BOTTOM UP */

    i__1 = j;
    for (i__ = nametb_1.namest; i__ <= i__1; ++i__) {
	if (nametb_1.namtbl[i__ - 1] == 0) {
	    goto L40;
	}
	if (s_cmp(cnamtb_1.cnamtb + (i__ - 1) * 6, str, (ftnlen)6, (ftnlen)6) 
		== 0) {
	    goto L100;
	}
/* L30: */
    }
/* ...       TABLE FULL */
    alarm_(&c__3001, &c__0, &c__8, "NAME    ", (ftnlen)8);
    return ret_val;

/* ...       NOT IN TABLE */

L40:
    s_copy(cnamtb_1.cnamtb + (i__ - 1) * 6, str, (ftnlen)6, (ftnlen)6);
/* ...       ENTRY IF NAME FOUND */
L100:
    ret_val = i__;
    if (nametb_1.namtbl[i__ - 1] >= 0 || i__ > nametb_1.nammax) {
	return ret_val;
    }
    i__ = -nametb_1.namtbl[i__ - 1];
    goto L100;

} /* name_ */

