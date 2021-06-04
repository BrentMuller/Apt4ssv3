/* OPCODE.f -- translated by f2c (version 20100827).
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
    integer iltext[94];
} iltext_;

#define iltext_1 iltext_

/* Table of constant values */

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006661.V01   *** */


/*              FORTRAN SUBROUTINE OPCODE */

/* LINKAGE      SUBROUTINE OPCODE(I) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    ASNADZ */
/*                                        SUBROUTINE    ASNJPZ */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    CALLZZ */
/*                                        SUBROUTINE    CALMCX */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    JUMPZZ */
/*                                        SUBROUTINE    LABELZ */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MNPROC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    RESRVZ */
/*                                        SUBROUTINE    RETMCX */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int opcode_(integer *i__)
{
    /* Local variables */
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define comfin ((logical *)&iltext_1)
#define length ((integer *)&iltext_1 + 1)
#define optext ((integer *)&iltext_1 + 3)
#define tpntrx ((integer *)&iltext_1 + 2)



/*       19.    INTERMEDIATE LANGUAGE TEXT */

/* COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN */
/* LENGTH:      NUMBER OF ITEMS IN CURRENT I.L. COMMAND ARGUMENT LIST */
/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */
/* * */
/* ARGUMENTS    I     INTEGER CODE FOR CURRENT I.L. COMMAND */
/* ** */
    if (*comfin) {
	alarm_(&c__4, &c__0, &c__8, "OPCODE  ", (ftnlen)8);
    }
    *optext = *i__;
    *length = 0;
    *tpntrx = 0;
    *comfin = TRUE_;
    return 0;
} /* opcode_ */

#undef tpntrx
#undef optext
#undef length
#undef comfin


