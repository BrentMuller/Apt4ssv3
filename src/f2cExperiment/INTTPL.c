/* INTTPL.f -- translated by f2c (version 20100827).
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
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    integer ikeep[255];
} intcom_;

#define intcom_1 intcom_

/* *** SOURCE FILE : M0012369.V02   *** */

/* Subroutine */ int inttpl_(integer *ns, doublereal *pt, doublereal *pl, 
	integer *irc)
{
    /* Initialized data */

    static integer ipknt[2] = { 0,0 };

    /* Local variables */
    static integer i__;
    static doublereal u, v, hn[6]	/* was [3][2] */, cs;
#define uv ((doublereal *)&intcom_1 + 64)
#define ptt ((doublereal *)&intcom_1 + 76)
#define spv ((doublereal *)&intcom_1)
#define npts ((integer *)&intcom_1 + 250)
#define thick ((doublereal *)&intcom_1 + 100)
    extern /* Subroutine */ int intnrm_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *);
#define iptknt ((integer *)&intcom_1 + 249)


/*     COMPUTES THE NORMALIZED COEFFICIENTS OF A PLANE TANGENT TO SURFACE */
/*     "NS" WHOSE NORMAL PASSES THROUGH POINT "PT". */
/*     INTTPL IS CALLED BY INTERSECTION ROUTINES INTCON & INTBND. */


/* SS - ARELEM - COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/*   EVALUATION VECTOR FOR PS AND DS */
/*   LAST THREE U,V PAIRS OF PS AND DS */
/*   POINT OF TANGENCY ON PS AND DS */
/*   THICKNESS ON PS AND DS */
/*  TRACE */
/* CCCC EQUIVALENCE (IKEEP(249),ITRACE) */
/*   INTERNAL POINT COUNT */
/*   MAXIMUM NUMBER OF POINTS */

    /* Parameter adjustments */
    --pl;
    --pt;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* CCCC IF(ITRACE.EQ.1) */
/* CCCC*WRITE(6,1000) */
/* 1000 FORMAT(' ***TRACE***INTTPL') */

/* IS SURFACE NOT A PLANE ? */
    if (ssarlm_1.iiflag[(2496 + (0 + (1 + (*ns << 2) - 5 << 2)) - 2496) / 4] 
	    > 0) {
	goto L30;
    }

/* LOAD THE PLANE */
    for (i__ = 1; i__ <= 4; ++i__) {
/* L20: */
	pl[i__] = ssarlm_1.bb[i__ + (*ns << 6) - 65];
    }
    *irc = 0;
    goto L999;

/* SURFACE IS NOT A PLANE; FIND TANGENT PLANE. */
L30:
    *irc = 1;
    if (*ns != 1 && *ns != 2) {
	goto L100;
    }
    *irc = 0;
    u = uv[(*ns * 3 + 1 << 1) - 8];
    v = uv[(*ns * 3 + 1 << 1) - 7];

/* EXTRAPOLATE NEXT UV IF 2 POINTS HAVE BEEN CALCULATED. */
    if (*npts <= *iptknt + 2 || *iptknt == ipknt[*ns - 1]) {
	goto L50;
    }
    u = u + (u - uv[(*ns * 3 + 2 << 1) - 8]) * 2. - (uv[(*ns * 3 + 2 << 1) - 
	    8] - uv[(*ns * 3 + 3 << 1) - 8]);
    v = v + (v - uv[(*ns * 3 + 2 << 1) - 7]) * 2. - (uv[(*ns * 3 + 2 << 1) - 
	    7] - uv[(*ns * 3 + 3 << 1) - 7]);
L50:

/* CALL NORMAL DISTANCE ROUTINE */
    intnrm_(ns, &u, &v, &pt[1], &spv[((*ns << 3) + 1 << 2) - 36], irc);

/* SAVE SURFACE POINT */
    ptt[*ns * 3 - 3] = spv[((*ns << 3) + 1 << 2) - 36];
    ptt[*ns * 3 - 2] = spv[((*ns << 3) + 1 << 2) - 35];
    ptt[*ns * 3 - 1] = spv[((*ns << 3) + 1 << 2) - 34];

/* SAVE UV POSITION (NOTE: RECALCULATED IN SUB INTNRM) */
    uv[(*ns * 3 + 1 << 1) - 8] = u;
    uv[(*ns * 3 + 1 << 1) - 7] = v;
    ipknt[*ns - 1] = *iptknt;

/* LOAD SURFACE NORMAL */
    pl[1] = spv[((*ns << 3) + 8 << 2) - 36];
    pl[2] = spv[((*ns << 3) + 8 << 2) - 35];
    pl[3] = spv[((*ns << 3) + 8 << 2) - 34];

/* HECK DIR. OF THIS NORMAL */
    if (*iptknt >= *npts - 1) {
	goto L80;
    }
    cs = hn[*ns * 3 - 3] * pl[1] + hn[*ns * 3 - 2] * pl[2] + hn[*ns * 3 - 1] *
	     pl[3];
/* IS THE NORMAL ORIENTED THE SAME AS LAST TIME? */
    if (cs >= 0.) {
	goto L70;
    }

/* NO; FLIP DIR. */
    pl[1] = -pl[1];
    pl[2] = -pl[2];
    pl[3] = -pl[3];
L70:
L80:

/* SAVE THIS NORMAL FOR NEXT SOL. & CAL. CONSTANT */
    hn[*ns * 3 - 3] = pl[1];
    hn[*ns * 3 - 2] = pl[2];
    hn[*ns * 3 - 1] = pl[3];
    pl[4] = pl[1] * spv[((*ns << 3) + 1 << 2) - 36] + pl[2] * spv[((*ns << 3) 
	    + 1 << 2) - 35] + pl[3] * spv[((*ns << 3) + 1 << 2) - 34];
L100:
    pl[4] += thick[*ns - 1];

L999:
    return 0;
} /* inttpl_ */

#undef iptknt
#undef thick
#undef npts
#undef spv
#undef ptt
#undef uv


