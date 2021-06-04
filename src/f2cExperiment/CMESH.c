/* CMESH.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : M0011517.V05   *** */

/* Subroutine */ int cmesh_(doublereal *spv, doublereal *ust, doublereal *vst,
	 integer *j11)
{
    /* Local variables */
    static integer mm;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal pa01, pb01, pc01, pu01, pv01;
    static integer ipa01, ipb01, mesh, itop[24]	/* was [6][4] */, nspl, npnt, 
	    iflag[4];
#define canon ((doublereal *)&_BLNK__1)
    static doublereal patch[64];
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);
    static integer mpatch, npatch;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);

/* ---- THIS ROUTINE GIVES A POINT WITH ITS DERIVATIVES,WHEN UST AND VST */
/* ---- IS GIVEN. */
/* ---- THE SURFACE IS LOADED BEFORE BY APT094 IN CAN */
/* ---- LODPCH AND CNSURF ARE CALLED */


/*    NPATCH : IST DIE ZURUECKGEGEBENE PATCH-NUMMER */
/*    UST    : FLAECHEN-PARAMETER IN U-RICHTUNG */
/*    VST    : FLAECHENPARAMETER IN V-RICHTUNG */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*  PUNKT/VECTOR MITTELS PARAMETER AUS SSURF */

    /* Parameter adjustments */
    --spv;

    /* Function Body */
    pa01 = *ust;
    pb01 = *vst;
    pc01 = 0.;
/*   MAXIMALE PATCH-ANZAHL */
    mpatch = (integer) can[*j11 + 3];
/*   FLAECHENART (2 FUER MESH-TYP) */
    mesh = (integer) can[*j11 + 4];
/*   ANZAHL DER KURVENSEGMENTE IN U-RICHTUNG */
    nspl = (integer) (can[*j11 + 8] - 1.f);
/*   ANZAHL DER KURVENSEGMENTE IN V-RICHTUNG */
    npnt = (integer) (can[*j11 + 9] - 1.f);
    ipa01 = (integer) pa01;
    ipb01 = (integer) pb01;
    if (ipa01 < npnt) {
	goto L10;
    }
    ipa01 = npnt - 1;
L30:
    pu01 = pa01 - ipa01;
L40:
    if (ipb01 < nspl) {
	goto L20;
    }
    ipb01 = nspl - 1;
L50:
    pv01 = pb01 - ipb01;
L60:
    npatch = ipb01 * npnt + ipa01 + 1;
    goto L70;
L10:
    if (ipa01 >= 0) {
	goto L30;
    }
    ipa01 = 0;
    pu01 = pa01;
    goto L40;
L20:
    if (ipb01 >= 0) {
	goto L50;
    }
    ipb01 = 0;
    pv01 = pb01;
    goto L60;
L70:
    lodpch_(&can[*j11], patch, iflag, itop, &npatch, &c__1);

/*    MMODE=1 MEANS CALCULATE POINT AND DERIVATIVES(SPV) */
    mm = 1;



    cnsurf_(&pu01, &pv01, patch, &spv[1], iflag, &mm);

    return 0;
} /* cmesh_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


