/* IFTMP.f -- translated by f2c (version 20100827).
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
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006638.V03   *** */


/*              FORTRAN SUBROUTINE IFTMP */

/* LINKAGE      LOGICAL FUNCTION IFTMP(A) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */

logical iftmp_(integer *a)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
#define temp ((integer *)&code_1 + 32)
#define modhlf ((integer *)&moduli_1 + 1)
#define modulo ((integer *)&moduli_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* ** */

/* ...     IS A THE NAMTBL INDEX OF A TEMPORARY LOCATION */

    if (*a > nametb_1.nammax) {
	goto L5;
    }
    if (nametb_1.namtbl[*a - 1] / *modulo == temp[0] / *modulo && 
	    nametb_1.namtbl[*a - 1] - *modulo * (nametb_1.namtbl[*a - 1] / *
	    modulo) < *modhlf) {
	goto L10;
    }

/* ...     NO. RETURN IFTMP AS .FALSE. */

L5:
    ret_val = FALSE_;
    return ret_val;

/* ...     YES. RETURN IFTMP AS .TRUE. */

L10:
    ret_val = TRUE_;
    return ret_val;
} /* iftmp_ */

#undef modulo
#undef modhlf
#undef temp


