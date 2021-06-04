/* ALTCMV.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : ALTCMV.ORG   *** */

/* Subroutine */ int altcmv_(integer *jc, doublereal *tn, doublereal *s, 
	integer *ip, integer *id, doublereal *vcs, doublereal *dcs, 
	doublereal *eps1cs, doublereal *cmove, logical *lret)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_sign(integer *, integer *);
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal c1, c2;
    static integer ii, ivz;
    extern /* Subroutine */ int setmov_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);


/* .... COMPUTE CMOVE BY ALTERNATIVE METHODS */

/* ARGUMENTS: */
/*           JC      FLAG INDICATING GAUSS FAILURE CONDITION USED */
/*                   TO SELECT ALTERNATIVE METHOD FOR COMPUTING CMOVE */
/*           TN      TOOL NORMAL DIRECTIONS */
/*           S       DIRECTED DISTANCES */
/*           IP      INDEX FOR PS */
/*           ID      INDEX FOR DS */
/*           VCS     CHECK SURFACE DIRECTION */
/*           SCS     CHECK SURFACE DIRECTED DISTANCE */
/*           EPS1CS  TOLERANCE EQ .1*TAU FOR CHECK SURFACE */
/*           CMOVE   MOVE REQUIRED TO BRING TOOL INTO CONTACT WITH */
/*                   3 SURFACES */
/*           LRET    RETURN FLAG = .TRUE. IF WITHIN TOLERANCE WHEN */
/*                                        PS PARALLEL TO CS */
/*                               = .FALSE. OTHERWISE */



/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




    /* Parameter adjustments */
    --cmove;
    --vcs;
    --s;
    tn -= 4;

    /* Function Body */
    *lret = FALSE_;
    ivz = i_sign(&c__1, jc);
    j = abs(*jc);

    if (j == 1) {
/* .... SELECT LARGER OF PS AND DS MOVES */
	if ((d__1 = s[*ip], abs(d__1)) > (d__2 = s[*id], abs(d__2))) {
	    i__ = *ip;
	} else {
	    i__ = *id;
	}
/* .... SET MOVE TO .9*LARGER S(I) + CHECK SURF MOVE */
	c1 = znumbr_1.z9em1 * s[i__];
	c2 = *dcs;
	setmov_(&cmove[1], &c1, &tn[i__ * 3 + 1], &c2, &vcs[1]);

    } else if (j == 12) {

/* .... PS PARALLEL TO DS */

/* .... SELECT LARGER OF PS AND DS MOVES */
	if ((d__1 = s[*ip], abs(d__1)) > (d__2 = s[*id], abs(d__2))) {
	    i__ = *ip;
	    ii = *id;
	} else {
	    i__ = *id;
	    ii = *ip;
	}

	if (s[i__] * s[ii] * ivz > 0.) {
/* .... SET MOVE TO .9*LARGER + .9*CHECK SURF MOVE */
	    c1 = znumbr_1.z9em1 * s[i__];
	} else {
/* .... SET MOVE TO .9*(MEAN S(I) IN DIRECTION OF LARGER) */
/*                           + .9*CHECK SURF MOVE */
	    c1 = znumbr_1.z9em1 * d_sign(&znumbr_1.z1, &s[i__]) * 
		    znumbr_1.z5em1 * (s[i__] + s[ii]);
	}
	c2 = znumbr_1.z9em1 * *dcs;
	setmov_(&cmove[1], &c1, &tn[i__ * 3 + 1], &c2, &vcs[1]);

    } else if (j == 13) {

/* .... PS PARALLEL TO CS */

/* .... COMPUTE .9* MEAN (PS AND CS DISTANCES) */
	c1 = znumbr_1.z9em1 * znumbr_1.z5em1 * (s[*ip] + ivz * *dcs);
	if (abs(c1) < znumbr_1.z1em2 * *eps1cs) {
/* .... CONSIDER AS SUCCESSFUL MOVE */
	    *lret = TRUE_;
	} else {
/* .... SET MOVE TO .9* MEAN (PS AND CS DISTANCES) IN PS DIRECTION */
/*               + .9* DS MOVE */
	    c2 = znumbr_1.z9em1 * s[ii];
	    setmov_(&cmove[1], &c1, &tn[*ip * 3 + 1], &c2, &tn[*id * 3 + 1]);
	}

    } else {

/* .... DS PARALLEL TO CS */

/* .... SELECT LARGER OF DS AND CS MOVES */
	if ((d__1 = s[*id], abs(d__1)) > abs(*dcs)) {
/* .... DS LARGER */
/* .... SET MOVE TO .9*IN DIRECTION OF DS + .9*PS MOVE */
	    c1 = znumbr_1.z9em1;
	    c2 = znumbr_1.z9em1 * s[*ip];
	    setmov_(&cmove[1], &c1, &tn[*id * 3 + 1], &c2, &tn[*ip * 3 + 1]);
	} else {
/* .... CS LARGER */
	    if (s[*ip] * s[*id] * ivz > 0.) {
/* .... SET MOVE TO .9*PS MOVE + .9* CHECK SURF MOVE */
		c1 = znumbr_1.z9em1 * s[*ip];
	    } else {
/* .... SET MOVE TO .9* MEAN (PS AND DS DISTANCES) IN PS DIRECTION */
/*               + .9* CHECK SURF MOVE */
		c1 = znumbr_1.z9em1 * d_sign(&znumbr_1.z1, &s[i__]) * 
			znumbr_1.z5em1 * (s[*ip] + s[*id]);
	    }
	    c2 = znumbr_1.z9em1 * *dcs;
	    setmov_(&cmove[1], &c1, &tn[*ip * 3 + 1], &c2, &vcs[1]);
	}
    }

    return 0;
} /* altcmv_ */

/* Subroutine */ int setmov_(doublereal *cm, doublereal *a, doublereal *v1, 
	doublereal *b, doublereal *v2)
{
    static integer i__;


/* .... CALCULATE VECTOR MOVE = A*V1 + B*V2 */


    /* Parameter adjustments */
    --v2;
    --v1;
    --cm;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	cm[i__] = *a * v1[i__] + *b * v2[i__];
/* L10: */
    }

    return 0;
} /* setmov_ */

