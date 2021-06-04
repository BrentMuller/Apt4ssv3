/* EPILOG.f -- translated by f2c (version 20100827).
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
    integer prt[7];
} prt_;

#define prt_1 prt_

struct {
    integer macseg[6];
} macseg_;

#define macseg_1 macseg_

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : M0006630.V01   *** */


/*              FORTRAN SUBROUTINE EPILOG */

/* LINKAGE      SUBROUTINE EPILOG */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    IEPLOG          SUBROUTINE    MACREC */
/*          SUBROUTINE    LIBOPC          SUBROUTINE    PRO026 */

/* Subroutine */ int epilog_(void)
{
    /* Local variables */
    static integer iflag;
#define alopn ((logical *)&macseg_1)
    extern /* Subroutine */ int libopc_(integer *, integer *);
#define assemb ((logical *)&prt_1 + 3)
    extern /* Subroutine */ int ieplog_(void);
#define interp ((logical *)&prt_1 + 2)



/*       14.    I. L. LIST OPTION FLAGS */

/* INTERP:      NORMALLY TRUE,INDICATING INTERPRETIVE APPROACH DEFAULT */
/* ASSEMB:      SET TRUE INDICATES ASSEMBLY APPROACH (CONTRL/ASMBLE) */

/*       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES */

/* ALOPN:       TRUE AFTER MACRO OR PART PROGRAM SEGMENT LIBRARY OPENED */
/* ** */
/*     IF(ASSEMB)CALL AEPLOG */
    if (*interp) {
	ieplog_();
    }
/* ...      TERMINATE TRANSLATION */
    *assemb = FALSE_;
    *interp = FALSE_;
    if (*alopn) {
	libopc_(&c__2, &iflag);
    }
    return 0;
} /* epilog_ */

#undef interp
#undef assemb
#undef alopn


