/* DDPARS.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* *** SOURCE FILE : DDPARS00.ORG   *** */

/* Subroutine */ int ddpars_(doublereal *pcanon)
{
    /* Local variables */
    static doublereal u, v;
    static integer iu, iv;
#define can ((doublereal *)&_BLNK__1 + 40)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddpara_(doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer xcanon_(integer *);


/*  * DDPARS *  VAX-11 FORTRAN 77 VERSION  29.8.86  E.MCLELLAN */

/*  PURPOSE     TO SET THE ADDRESSES OF THE PARAMETERS U AND V */
/*              IN THE ARGUMENT LIST FOR A CALL TO DDPARA AND */
/*              TO SERVE AS A DISPATCHER BETWEEN DDST AND DDPARA */

/*  CALLING SEQUENCE */
/*              CALL DDPARS(PCANON) */
/*  ARGUMENTS */
/*              PCANON   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      A PARAMTRIC SURFACE */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* .....PICK UP VIRTUAL ADDRESSES OF U AND V FROM PCANON ARRAY */

    /* Parameter adjustments */
    --pcanon;

    /* Function Body */
    iu = (integer) pcanon[2];
    iv = (integer) pcanon[3];

/* .....CONVERT TO ACTUAL ADDRESSES */

    if (ldef_1.canflg) {
	iu = xcanon_(&iu);
    }
    u = _BLNK__1.com[iu - 1];
    if (ldef_1.canflg) {
	iv = xcanon_(&iv);
    }
    v = _BLNK__1.com[iv - 1];

/* .....CALL DDPARA(U,V) */

    ddpara_(&u, &v);

    return 0;
} /* ddpars_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


