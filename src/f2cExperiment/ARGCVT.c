/* ARGCVT.f -- translated by f2c (version 20100827).
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
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006616.V03   *** */


/*              FORTRAN SUBROUTINE ARGCVT */

/* LINKAGE      SUBROUTINE ARGCVT(INDEX) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    TWOARG          SUBROUTINE    ARGGEN */
/*                                        SUBROUTINE    ASNADZ */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REFGEN */
/*                                        SUBROUTINE    REFREF */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int argcvt_(integer *index)
{
    /* Local variables */
    static integer l;
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
#define temp ((integer *)&code_1 + 32)
#define label ((integer *)&code_1 + 42)
#define dbldlr ((integer *)&opmod_1 + 2)
#define implab ((integer *)&code_1 + 44)
#define modhlf ((integer *)&moduli_1 + 1)
#define modulo ((integer *)&moduli_1)
    extern /* Subroutine */ int twoarg_(integer *, integer *);
#define nought ((integer *)&opmod_1)
#define trpdlr ((integer *)&opmod_1 + 3)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* DLR:         CONTAINS OPERAND TYPE CODE 1 */
/* DBLDLR:      CONTAINS OPERAND TYPE CODE 2 */
/* TRPDLR:      CONTAINS OPERAND TYPE CODE 3 */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */
/* * */
/* PURPOSE      TO DETERMINE THE LITERAL DESIGNATION OF AN */
/*              ARGUMENT AND OUTPUT THE APPROPRIATE ARGUMENT- */
/*              PAIR TO THE I.L. INTERNAL RECORD IMAGE */
/*              (ILFILE) */

/* ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF ARGUMENT. */
/* ** */
/* ...     IS INDEX A POINTER TO A NUMBER */

    if (*index > nametb_1.nammax) {
	goto L20;
    }

/* ...     NO. CALCULATE CLASS OF THIS ITEM. */

    l = *modulo * (nametb_1.namtbl[*index - 1] / *modulo);

/* ...     IS MODE OF ITEM GREATER THAN MODHLF */
/* ...     I.E. IS IT AN INDIRECT ADDRESS */

    if (nametb_1.namtbl[*index - 1] - l < *modhlf) {
	goto L10;
    }

/* ...     YES. CALL TWOARG WITH MODIFIER OF 3 ($$$) */

    twoarg_(trpdlr, index);
    goto L100;

/* ...     NOT AN INDIRECT ADDRESS. */
/* ...     IS IT OF CLASS VBL, TEMP, LABEL, OR IMPLAB. */

L10:
    if (l != vbl[0] && l != temp[0] && l != label[0] && l != implab[0]) {
	goto L30;
    }

/* ...     YES. CALL TWOARG WITH MODIFIER OF 0 */

    twoarg_(nought, index);
    goto L100;

/* ...     NUMBER. CALL TWOARG WITH MODIFIER OF 1 ($) */

L20:
    twoarg_(dlr, index);
    goto L100;

/* ...     BCD CHARACTER INDEX. CALL TWOARG WITH MODIFIER OF 2 ($$) */

L30:
    twoarg_(dbldlr, index);
L100:
    return 0;
} /* argcvt_ */

#undef trpdlr
#undef nought
#undef modulo
#undef modhlf
#undef implab
#undef dbldlr
#undef label
#undef temp
#undef vbl
#undef dlr


