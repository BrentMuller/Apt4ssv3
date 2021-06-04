/* CLMODE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006627.V03   *** */


/*              FORTRAN SUBROUTINE CLMODE */

/* LINKAGE      INTEGER FUNCTION CLMODE (WHERE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    PRO026 */

integer clmode_(integer *where)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define vbl ((integer *)&code_1 + 60)
    static integer what;
#define temp ((integer *)&code_1 + 32)
#define modhlf ((integer *)&moduli_1 + 1)
#define permid ((integer *)&code_1 + 38)
#define number ((integer *)&code_1 + 26)
#define modulo ((integer *)&moduli_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* PURPOSE      TO FIND THE CLMODE OF AN ARGUMENT FOR USE BY */
/*              THE CLTAPE EDITOR IN PROCESSING POST-PRO- */
/*              CESSOR AND CLTAPE EDITOR COMMANDS. */

/* ARGUMENTS    WHERE    NAMTBL INDEX OF ARGUMENT */
/* ** */
    if (*where > nametb_1.nammax) {
	goto L50;
    }

/* ...     SET WHAT TO CLASS OF WHERE */

    what = *modulo * (nametb_1.namtbl[*where - 1] / *modulo);

/* ...     TEST FOR NUMBER */

    if (what != number[0]) {
	goto L100;
    }

/* ...     NUMBER - SET CLMODE TO 1 */

L50:
    ret_val = 1;
    return ret_val;

/* ...     TEST FOR CLASS PERMANENT IDENTIFIER */

L100:
    if (what != permid[0]) {
	goto L200;
    }

/* ...     PERMID - SET CLMODE TO 2 */

    ret_val = 2;
    return ret_val;

/* ...     TEST FOR CLASS VARIABLE OR TEMPORARY */

L200:
    if (what != vbl[0] && what != temp[0]) {
	goto L9999;
    }

/* ...     VBL OR TEMP - SET CLMODE TO (TRANSLATOR MODE + 2) */

    ret_val = nametb_1.namtbl[*where - 1] % *modhlf + 2;
    if (ret_val == 23) {
	ret_val = 1;
    }
    return ret_val;

/* ...     ILLEGAL META-LINGUISTIC CLASS - SET CLMODE TO ZERO. */

L9999:
    ret_val = 0;
    return ret_val;
} /* clmode_ */

#undef modulo
#undef number
#undef permid
#undef modhlf
#undef temp
#undef vbl


