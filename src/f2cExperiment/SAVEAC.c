/* SAVEAC.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ntb, fpb, ppb, comn, cfb;
} stor_;

#define stor_1 stor_

/* *** SOURCE FILE : SAVEAC.V01   *** */

/* Subroutine */ int saveac_(integer *ac)
{
    /* Local variables */
    static integer j;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ntp;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer xcanon_(integer *);


/*   PURPOSE: SYSTEM INDEPENDENT ROUTINE TO SAVE VALUE REFERENCED BY .AC. */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*     ------------------- */



/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*    .AC. IS IN FIXED LOCATION OF NAMTBL */

    ntp = stor_1.ntb + 166;

    j = nt[(ntp << 1) - 2];
    if (ldef_1.canflg) {
	j = xcanon_(&j);
    }

    _BLNK__1.com[j - 1] = (doublereal) (*ac);

    return 0;
} /* saveac_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


