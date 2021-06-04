/* MODE.f -- translated by f2c (version 20100827).
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
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006656.V03   *** */


/*              FORTRAN SUBROUTINE MODE */

/* LINKAGE      INTEGER FUNCTION MODE(INDEX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MATCH */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */

integer mode_(integer *index)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k;
#define vbl ((integer *)&code_1 + 60)
#define real__ ((integer *)&modx_1 + 20)
#define temp ((integer *)&code_1 + 32)
#define modhlf ((integer *)&moduli_1 + 1)
#define number ((integer *)&code_1 + 26)
#define modulo ((integer *)&moduli_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR REAL */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* ARGUMENTS    INDEX     NAME TABLE (NAMTBL) INDEX OF THE VARIABLE. */
/* ** */
/* ...     IS INDEX THAT OF A NUMBER */

    if (*index <= nametb_1.nammax) {
	goto L100;
    }

/* ...     YES - MODE = REAL. */

L10:
    ret_val = *real__;
    return ret_val;

/* ...     SET K TO CLASS OF ITEM. */

L100:
    k = *modulo * (nametb_1.namtbl[*index - 1] / *modulo);

/* ...     IS IT OF CLASS NUMBER */

    if (k == number[0]) {
	goto L10;
    }

/* ...     NO. IS IT OF CLASS VBL OR TEMP. IF SO RETURN CORRECT MODE. */

    if (k != vbl[0] && k != temp[0]) {
	goto L25;
    }
    ret_val = nametb_1.namtbl[*index - 1] - k;

/* ...     IS IT A SUBSCRIPT. IF SO RETURN DERIVATIVE MODE. */

    if (ret_val >= *modhlf) {
	ret_val -= *modhlf;
    }
    return ret_val;

/* ...     NOT NUMBER, VBL, OR TEMP - SO RETURN ZERO MODE. */

L25:
    ret_val = 0;
    return ret_val;
} /* mode_ */

#undef modulo
#undef number
#undef modhlf
#undef temp
#undef real__
#undef vbl


