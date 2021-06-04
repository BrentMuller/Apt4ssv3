/* APT013.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* Table of constant values */

static integer c__0 = 0;
static doublereal c_b28 = .5;

/* *** SOURCE FILE : M0000694.V03   *** */


/*     FORTRAN SUBROUTINE APT013 */
/*  PURPOSE     TO GENERATE THE CANONICAL FORM OF A CIRCLE OR A CYLNDER */
/*              DEFINED AS TANGENT TO EACH OF THREE GIVEN LINES */
/*              BY THE FOLLOWING APT STATEMENT. */
/*              RESULT=CYLNDR/+*,L1,**,L2,**,L3 */
/*                **=XLARGE,YLARGE,ZLARGE,XSMALL,YSMALL,ZSMALL */
/*                CYLNDR CAN BE REPLACED BY CIRCLE */
/*  LINKAGE     CALL APT013 (RESULT,M1,L1,M2,L2,M3,L3) */
/*  ARGUMENTS   RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CYLNDR OR CIRCLE. */
/*              M1-M3   INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1=XLARGE  2=YLARGE  3=ZLARGE */
/*                      4=XSMALL  5=YSMALL  6=ZSMALL */
/*              L1-L3   ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      PLANE OR LINE. */
/*  SUBSIDIARIES    TYPE      ENTRY */
/*                SUBROUTINE  APT077 */
/*                SUBROUTINE  DOTF */
/*                SUBROUTINE  CROSSV */
/*                SUBROUTINE  APT075 */
/*                SUBROUTINE  APT047 */
/*                SUBROUTINE  DEFEXT */
/* Subroutine */ int apt013_(doublereal *result, integer *m1, doublereal *l1, 
	integer *m2, doublereal *l2, integer *m3, doublereal *l3)
{
    /* Format strings */
    static char fmt_192[] = "";
    static char fmt_195[] = "";

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, m, n;
    static doublereal s1;
    static integer ji, jj, mn;
    static doublereal az, sl[12]	/* was [4][3] */, tl[12]	/* 
	    was [4][3] */;
    static integer ms[3], mt[3];
    static doublereal pt1[6]	/* was [3][2] */, pt2[6]	/* was [3][2] 
	    */, dot, ttl[12]	/* was [4][3] */;
    static integer mtt[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer irtn;
    extern /* Subroutine */ int apt075_(doublereal *, doublereal *), apt077_(
	    doublereal *, integer *), cross_(doublereal *, doublereal *, 
	    doublereal *), vnorm_(doublereal *, doublereal *);
    static doublereal dummy1;
    extern /* Subroutine */ int defext_(doublereal *);

    /* Assigned format variables */
    static char *irtn_fmt;




/* ...  ALL REFERENCES TO VARIABLE A HAVE BEEN CHANGED TO AZ, */
/* ...  BECAUSE A OCCURS IN DEF.INC. */

/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */







/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */



/* ...  TRANSFORM FROM BASE TO LOCAL */
    /* Parameter adjustments */
    --l3;
    --l2;
    --l1;
    --result;

    /* Function Body */
    apt077_(&l1[1], &c__0);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L10: */
	sl[i__ - 1] = dshar3_1.l[i__ - 1];
    }
    ms[0] = *m1;

    apt077_(&l2[1], &c__0);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L11: */
	sl[i__ + 3] = dshar3_1.l[i__ - 1];
    }
    ms[1] = *m2;

    apt077_(&l3[1], &c__0);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L12: */
	sl[i__ + 7] = dshar3_1.l[i__ - 1];
    }
    ms[2] = *m3;
/* ...  GET TWO UNPARALLEL PLANE */
    for (j = 1; j <= 3; ++j) {
	i__ = j + 1;
	if (j == 3) {
	    i__ = 1;
	}
	dotf_(&dot, &sl[(j << 2) - 4], &sl[(i__ << 2) - 4]);
	mt[j - 1] = 0;
	if (abs(dot) < .9999f) {
	    mt[j - 1] = 1;
	}
/* L13: */
    }
    if (mt[0] + mt[1] + mt[2] <= 1) {
	goto L98;
    }
    if (mt[0] == 0) {
	goto L14;
    }
    i__ = 1;
    j = 2;
    if (mt[1] == 0) {
	j = 3;
    }
    goto L15;
L14:
    i__ = 2;
    j = 3;
L15:
    jj = j + 1;
    if (j == 3) {
	jj = 1;
    }
    for (k = 1; k <= 4; ++k) {
	tl[k - 1] = sl[k + (i__ << 2) - 5];
	tl[k + 3] = sl[k + (i__ + 1 << 2) - 5];
	ttl[k - 1] = sl[k + (j << 2) - 5];
/* L16: */
	ttl[k + 3] = sl[k + (jj << 2) - 5];
    }
    mt[0] = ms[i__ - 1];
    mt[1] = ms[i__];
    mtt[0] = ms[j - 1];
    mtt[1] = ms[jj - 1];
    tl[11] = 0.f;
    cross_(tl, &tl[4], &tl[8]);
    vnorm_(&tl[8], &tl[8]);
    for (k = 1; k <= 4; ++k) {
/* L17: */
	ttl[k + 7] = tl[k + 7];
    }
/* ...  CHECK PERPENDICULARITY */
    for (j = 1; j <= 3; ++j) {
	dotf_(&dot, &sl[(j << 2) - 4], &tl[8]);
	if (abs(dot) > 1e-6f) {
	    goto L98;
	}
/* L18: */
    }
/* ..   GET INTERSECTION POINT */
    apt075_(pt1, tl);
    apt075_(&pt1[3], ttl);
/* ...  OFFSET THE PLANE */
    for (i__ = 1; i__ <= 2; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L191: */
	    dshar3_1.l[j - 1] = tl[j + (i__ << 2) - 5];
	}
	mn = mt[i__ - 1];
	irtn = 0;
	irtn_fmt = fmt_192;
	goto L70;
L192:
	for (j = 1; j <= 4; ++j) {
/* L193: */
	    tl[j + (i__ << 2) - 5] = dshar3_1.l[j - 1];
	}
	for (j = 1; j <= 4; ++j) {
/* L194: */
	    dshar3_1.l[j - 1] = ttl[j + (i__ << 2) - 5];
	}
	mn = mtt[i__ - 1];
	irtn = 1;
	irtn_fmt = fmt_195;
	goto L70;
L195:
	for (j = 1; j <= 4; ++j) {
/* L196: */
	    ttl[j + (i__ << 2) - 5] = dshar3_1.l[j - 1];
	}
/* L19: */
    }
/* ...  GET INTERSECTION POINT */
    apt075_(pt2, tl);
    apt075_(&pt2[3], ttl);
/* ...  GET PLANE THRU TWO POINTS */
    for (j = 1; j <= 2; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	    tl[i__ + (j << 2) - 5] = pt2[i__ + j * 3 - 4] - pt1[i__ + j * 3 - 
		    4];
	}
	cross_(&tl[8], &tl[(j << 2) - 4], &tl[(j << 2) - 4]);
	vnorm_(&tl[(j << 2) - 4], &tl[(j << 2) - 4]);
/* L21: */
	dotf_(&tl[(j << 2) - 1], &tl[(j << 2) - 4], &pt1[j * 3 - 3]);
    }
/* ...  GET INTERSECTION OF TWO PLANES */
    apt075_(def_1.r__, tl);
/* --- CII UPDATE TO CHECK FOR INCONSISTENCY  NIU-APR/75 */
    for (m = 1; m <= 3; ++m) {
	dotf_(&az, def_1.r__, &sl[(m << 2) - 4]);
	n = ms[m - 1];
	if (n > 3) {
	    n += -3;
	}
	if ((sl[(m << 2) - 1] - az) * sl[n + (m << 2) - 5] * (ms[m - 1] - 
		3.5f) < 0.) {
	    goto L98;
	}
/* L200: */
    }
    vnorm_(&tl[8], &tl[8]);
    def_1.r__[3] = tl[8];
    def_1.r__[4] = tl[9];
    def_1.r__[5] = tl[10];
    def_1.r__[6] = sl[3] - sl[0] * def_1.r__[0] - sl[1] * def_1.r__[1] - sl[2]
	     * def_1.r__[2];
    def_1.r__[6] = abs(def_1.r__[6]);
    goto L99;
L98:
    idef_1.ierror = 43;
L99:
    defext_(&result[1]);
    return 0;
/* .... GET PARALLEL PLANE. */
L70:
    ji = (mn - 1) % 3;
    dummy1 = (doublereal) mn;
    s1 = dshar3_1.l[ji] * (3.5 - dummy1);
    if (s1 != 0.) {
	goto L80;
    }
    idef_1.ierror = 59;
    goto L99;
L80:
    dshar3_1.l[3] += d_sign(&c_b28, &s1);
    switch (irtn) {
	case 0: goto L192;
	case 1: goto L195;
    }
} /* apt013_ */

