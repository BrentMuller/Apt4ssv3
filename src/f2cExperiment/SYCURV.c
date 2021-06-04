/* SYCURV.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001226.V04   *** */

/* Subroutine */ int sycurv_(doublereal *aname, doublereal *pnts, doublereal *
	crl, integer *ity)
{
    /* System generated locals */
    static doublereal equiv_4[11], equiv_5[1];

    /* Local variables */
    static integer i__;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal vec[5];
    static integer kon;
    static doublereal arg1;
    extern integer bcdf_(char *, ftnlen);
#define cent (equiv_4 + 1)
#define temp (equiv_5)
#define cent0 (equiv_4)
    extern /* Subroutine */ int apt007_(doublereal *, doublereal *), apt108_(
	    doublereal *, doublereal *, doublereal *, doublereal *);
#define canon ((doublereal *)&_BLNK__1)
    static doublereal crseg;
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define itemp ((integer *)equiv_5)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int strtsh_(doublereal *);




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






    /* Parameter adjustments */
    --crl;
    --pnts;
    --aname;

    /* Function Body */
    for (i__ = 41; i__ <= 49; ++i__) {
/* L10: */
	canon[i__ - 1] = 0.;
    }
    canon[42] = 2.;
    canon[43] = 2.;
    canon[44] = 18.;
    itemp[0] = bcdf_("CURS", (ftnlen)4);
    itemp[1] = bcdf_("EG  ", (ftnlen)4);
    canon[48] = *temp;
    kon = 49;
    canon[kon] = 19.;
    canon[kon + 1] = pnts[1];
    canon[kon + 2] = pnts[2];
    canon[kon + 3] = pnts[3];
    if (*ity > 0) {
	goto L20;
    }
    cent0[0] = 1.903e7;
    apt007_(cent, &crl[1]);
    vec[0] = pnts[1] - cent[0];
    vec[1] = pnts[2] - cent[1];
    vec[2] = pnts[3] - cent[2];
    canon[kon + 4] = 136.;
    itemp[0] = bcdf_("TANS", (ftnlen)4);
    itemp[1] = bcdf_("PL  ", (ftnlen)4);
    canon[kon + 5] = *temp;
    canon[kon + 6] = 20.;
/*  LOESUNG FUER ZSURF SENKRECHTER ZYLINDER */
    cross_(vec, &crl[4], &canon[kon + 7]);
/*  ANDERE FAELLE NICHT ABGEFANGEN ! */
    canon[43] = 3.;
    canon[44] = 24.;
    kon += 6;
L20:
    canon[kon + 4] = 19.;
    canon[kon + 5] = pnts[4];
    canon[kon + 6] = pnts[5];
    canon[kon + 7] = pnts[6];
/* CODE GELOESCHT */
/* CODE GELOESCHT */
    strtsh_(&arg1);
    apt108_(&aname[1], &crseg, &arg1, &arg1);
    return 0;
} /* sycurv_ */

#undef bcanon
#undef itemp
#undef sscan
#undef canon
#undef cent0
#undef temp
#undef cent
#undef can


