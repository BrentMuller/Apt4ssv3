/* ONEARG.f -- translated by f2c (version 20100827).
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

static integer c__0 = 0;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006660.V01   *** */


/*              FORTRAN SUBROUTINE ONEARG */

/* LINKAGE      SUBROUTINE ONEARG(I) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    ASNADZ */
/*                                        SUBROUTINE    BOOLIF */
/*                                        SUBROUTINE    CALLZZ */
/*                                        SUBROUTINE    CALMCX */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    JUMPZZ */
/*                                        SUBROUTINE    LABELZ */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MNPROC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    RETMCX */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int onearg_(integer *i__)
{
    /* Local variables */
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define comfin ((logical *)&iltext_1)
    static integer ierror;
#define textin ((integer *)&iltext_1 + 4)
#define tpntrx ((integer *)&iltext_1 + 2)



/*       19.    INTERMEDIATE LANGUAGE TEXT */

/* COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN */
/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */
/* * */
/* ARGUMENTS    I       NAME TABLE (NAMTBL) INDEX OF ARGUMENT */
/* ** */
    if (*comfin) {
	goto L10;
    }
    ierror = 3;
    goto L90;
L10:
    if (*tpntrx < 90) {
	goto L20;
    }
    ierror = 2;
L90:
    alarm_(&ierror, &c__0, &c__8, "ONEARG  ", (ftnlen)8);
    goto L100;
L20:
    textin[*tpntrx] = *i__;
    ++(*tpntrx);
L100:
    return 0;
} /* onearg_ */

#undef tpntrx
#undef textin
#undef comfin


