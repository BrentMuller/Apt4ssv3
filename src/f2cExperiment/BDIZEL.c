/* BDIZEL.f -- translated by f2c (version 20100827).
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

struct izeill_1_ {
    integer izeil;
};

#define izeill_1 (*(struct izeill_1_ *) &izeill_)

/* Initialized data */

struct {
    integer e_1;
    } izeill_ = { 1 };


/* *** SOURCE FILE : M0001014.W01   *** */

/* Subroutine */ int bdizel_(void)
{
    return 0;
} /* bdizel_ */


/*   ROUTINES FOR ASA CARRIAGE CONTROLLED OUTPUT OF VERIFICATION LISTINGS */
/*    FROM ZSCPICT AND ZSSPICT */
/* Subroutine */ int cprin1_(char *a, ftnlen a_len)
{
    /* Initialized data */

    static char sv[1] = "1";
    static char ez[1] = " ";
    static char zz[1] = "0";

    extern /* Subroutine */ int cprint_(char *, ftnlen);


    if (*(unsigned char *)a != *(unsigned char *)&sv[0]) {
	goto L1;
    }
    izeill_1.izeil = 1;
    goto L5;
L1:
    if (*(unsigned char *)a != *(unsigned char *)&ez[0]) {
	goto L2;
    }
    ++izeill_1.izeil;
    goto L5;
L2:
    if (*(unsigned char *)a != *(unsigned char *)&zz[0]) {
	goto L5;
    }
    izeill_1.izeil += 2;
L5:
    cprint_(a, (ftnlen)120);
    return 0;
} /* cprin1_ */



/* Subroutine */ int vorsch_(integer *i__, char *a, ftnlen a_len)
{
    /* Initialized data */

    static char sv[1] = "1";

    static char b[120];
    static integer j;
    extern /* Subroutine */ int cprint_(char *, ftnlen);


    if (izeill_1.izeil + *i__ < 67) {
	return 0;
    }
    for (j = 1; j <= 120; ++j) {
/* L6: */
	*(unsigned char *)&b[j - 1] = *(unsigned char *)&a[j - 1];
    }
    *(unsigned char *)b = *(unsigned char *)&sv[0];
    izeill_1.izeil = 1;
    cprint_(b, (ftnlen)120);
    return 0;
} /* vorsch_ */

