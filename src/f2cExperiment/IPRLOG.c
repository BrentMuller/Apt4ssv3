/* IPRLOG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0006642.V03   *** */


/*              FORTRAN SUBROUTINE IPRLOG */

/* LINKAGE      SUBROUTINE IPRLOG */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ICMPRS          SUBROUTINE    PROLOG */
/*          INTEGER FCT.  NAME */

/* Subroutine */ int iprlog_(void)
{
    /* Initialized data */

    static char s21ts1[6] = "$21T$1";

    /* Local variables */
    extern integer name_(char *, ftnlen);
    extern /* Subroutine */ int icmprs_(void);
#define textin ((integer *)&iltext_1 + 4)
#define optext ((integer *)&iltext_1 + 3)
#define tpntrx ((integer *)&iltext_1 + 2)



/*       19.    INTERMEDIATE LANGUAGE TEXT */

/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */
/* ** */

    icmprs_();
    *optext = 12;
    *tpntrx = 4;
    textin[0] = name_(s21ts1, (ftnlen)6);
    textin[1] = 21;
    textin[2] = 1;
    textin[3] = 1;
    return 0;
} /* iprlog_ */

#undef tpntrx
#undef optext
#undef textin


