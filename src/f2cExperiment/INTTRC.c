/* INTTRC.f -- translated by f2c (version 20100827).
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
    integer ikeep[255];
} intcom_;

#define intcom_1 intcom_

struct {
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0005847.V01   *** */

/* Subroutine */ int inttrc_(integer *j12, integer *j11, doublereal *pt, 
	integer *idir, integer *irc)
{
    /* Initialized data */

    static integer ibo1[9]	/* was [3][3] */ = { 2,1,1,2,0,3,4,4,3 };
    static integer ibo2[9]	/* was [3][3] */ = { 1,0,3,0,0,0,2,0,4 };

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer m, np, ju, jv, nb1, nb2;
#define can ((doublereal *)&_BLNK__1 + 40)
#define ipnr ((integer *)&intcom_1 + 253)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);


/*   J12 : I: SURFACE INDEX OF PS */
/*   J11 : I: SURFACE INDEX OF DS */
/*   PT  : I: POINT STORAGE OF SEGMENT END */
/*   IDIR: I: FIRST (=1) OR LAST (=-1) SEGMENT POINT */
/*   IRC : O: =0: NO CONNECTING PAIR OF PATCHES FOUND ; =1: FOUND */


/* BLANK COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*   PATCH NUMBER FOR PS AND DS (SURFACE RECNO*1000 + PATCH NO) */

/* SS - ARELEM - COMMON */

/*   FIRST BORDER NUMBER FIELD */

/*   SECOND BORDER NUMBER FIELD */

    /* Parameter adjustments */
    pt -= 10;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/*   RETURN CODE */
    *irc = 0;

/*  PS SEARCH */
    ju = 2;
    if (abs(pt[16]) < 1e-5) {
	ju = 1;
    }
    if ((d__1 = pt[16] - 1., abs(d__1)) < 1e-5) {
	ju = 3;
    }
    jv = 2;
    if (abs(pt[17]) < 1e-5) {
	jv = 1;
    }
    if ((d__1 = pt[17] - 1., abs(d__1)) < 1e-5) {
	jv = 3;
    }

/*  BOUNDARY NUMBER */
    nb1 = ibo1[ju + jv * 3 - 4];
    if (nb1 == 0) {
	goto L50;
    }

/*  NEXT PATCH */
    np = ssarlm_1.iitop[(nb1 + 4) * 6 - 29];
    if (np == 0) {
	goto L50;
    }

/*  LOAD PATCH */
    m = 0;
    nb2 = ibo2[ju + jv * 3 - 4];
    if (nb2 != 0) {
	m = 2;
    }
    lodpch_(&sscan[*j12], ssarlm_1.bb, ssarlm_1.iiflag, ssarlm_1.iitop, &np, &
	    m);
    ipnr[0] = ipnr[0] / 1000 * 1000 + np;
    ssarlm_1.ipnum[0] = np;

/*   CORNER PATCH ? */
    if (nb2 != 0) {
	goto L20;
    }
    *irc = 1;
    goto L50;
/*  NEXT PATCH AT CORNER */
L20:
    np = ssarlm_1.iitop[(nb2 + 4) * 6 - 29];
    if (np == 0) {
	goto L50;
    }

/*  LOAD PATCH */
    lodpch_(&sscan[*j12], ssarlm_1.bb, ssarlm_1.iiflag, ssarlm_1.iitop, &np, &
	    c__0);
    ipnr[0] = ipnr[0] / 1000 * 1000 + np;
    ssarlm_1.ipnum[0] = np;
    *irc = 1;

/*  DS SEARCH */
L50:
    if (ssarlm_1.iiflag[4] <= 0) {
	goto L99;
    }
    ju = 2;
    if (abs(pt[13]) < 1e-5) {
	ju = 1;
    }
    if ((d__1 = pt[13] - 1., abs(d__1)) < 1e-5) {
	ju = 3;
    }
    jv = 2;
    if (abs(pt[14]) < 1e-5) {
	jv = 1;
    }
    if ((d__1 = pt[14] - 1., abs(d__1)) < 1e-5) {
	jv = 3;
    }

/*  BOUNDARY NUMBER */
    nb1 = ibo1[ju + jv * 3 - 4];
    if (nb1 == 0) {
	goto L99;
    }
    nb2 = ibo2[ju + jv * 3 - 4];

/*  NEXT PATCH */
    np = ssarlm_1.iitop[(nb1 + 8) * 6 - 29];
    if (np == 0) {
	goto L99;
    }

/*  LOAD PATCH */
    m = 0;
    nb2 = ibo2[ju + jv * 3 - 4];
    if (nb2 != 0) {
	m = 2;
    }
    lodpch_(&sscan[*j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4], &
	    ssarlm_1.iitop[24], &np, &m);
    ipnr[1] = ipnr[1] / 1000 * 1000 + np;
    ssarlm_1.ipnum[1] = np;

/*   CORNER PATCH ? */
    if (nb2 != 0) {
	goto L70;
    }
    *irc = 1;
    goto L99;
/*  NEXT PATCH AT CORNER */
L70:
    np = ssarlm_1.iitop[(nb2 + 8) * 6 - 29];
    if (np == 0) {
	goto L99;
    }

/*  LOAD PATCH */
    lodpch_(&sscan[*j11], &ssarlm_1.bb[64], &ssarlm_1.iiflag[4], &
	    ssarlm_1.iitop[24], &np, &c__0);
    ipnr[1] = ipnr[1] / 1000 * 1000 + np;
    ssarlm_1.ipnum[1] = np;
    *irc = 1;

L99:
    return 0;
} /* inttrc_ */

#undef bcanon
#undef sscan
#undef canon
#undef ipnr
#undef can


