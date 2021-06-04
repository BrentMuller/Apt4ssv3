/* GCLEAR.f -- translated by f2c (version 20100827).
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
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4];
} cclear_;

#define cclear_1 cclear_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__5157 = 5157;

/* *** SOURCE FILE : M0011488.V01   *** */

/* Subroutine */ int gclear_(doublereal *cname)
{
    /* Initialized data */

    static char hpos[6*6] = "START " "AWAY  " "BACK  " "THRU  " "ON    " 
	    "OFF   ";
    static char harg[6*5] = "MOTDIR" "NORMAL" "PARLEL" "FEED  " "CLEARS";
    static integer lcnn[7] = { 7,7,10,10,7,4,10 };

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, ie, is, mp;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd;
    static char test[6];
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer addrss_(doublereal *);
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);



/* PROCESSES THE GCLEAR STATEMENT */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --cname;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* SET DEFAULT GLFEED */
    if (cclear_1.glfeed == 0.) {
	cclear_1.glfeed = 50.;
    }

    is = 4;
    ie = (integer) (sscan[1] - 1);

/*             DEFINE COLUMN, I.E. POSITION OF TOOL MOTION */
    k = 0;
    for (mp = 1; mp <= 6; ++mp) {
	holfrm_(&sscan[is - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
	if (s_cmp(test, hpos + (mp - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L10;
	}
	if ((i__1 = mp - 5) < 0) {
	    goto L20;
	} else if (i__1 == 0) {
	    goto L4;
	} else {
	    goto L6;
	}
L4:
	k = 1;
L6:
	for (i__ = 1; i__ <= 4; ++i__) {
/* L8: */
	    cclear_1.iretro[i__ - 1] = k;
	}
	goto L15;
L10:
	;
    }

/*             NO CONDITIONS CHANGED */
L15:
    goto L999;

/*             ZERO LOCATIONS MP IN THE /CCLEAR/ ARRAYS */
L20:
    is += 2;
    cclear_1.iretro[mp - 1] = 0;
    holfrm_(&sscan[is - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, hpos + 30, (ftnlen)6, (ftnlen)6) == 0) {
	goto L15;
    }
    cclear_1.iretro[mp - 1] = 1;
    if (s_cmp(test, hpos + 24, (ftnlen)6, (ftnlen)6) == 0) {
	goto L15;
    }

/* FEED PARAMETER */
    if (s_cmp(test, harg + 18, (ftnlen)6, (ftnlen)6) != 0) {
	goto L25;
    }
    cclear_1.gofeed[mp - 1] = sscan[is + 1];
    is += 4;
    if (is < ie) {
	goto L25;
    }
    goto L115;

L25:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	cclear_1.dirmot[i__ + mp * 3 - 4] = 0.;
    }
    cclear_1.idirmo[mp - 1] = 0;
    cclear_1.icanin[mp - 1] = 0;

/*             SET FLAGS AND VALUES FOR MOTION CONDITIONS */
L40:
    holfrm_(&sscan[is - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    for (i__ = 1; i__ <= 5; ++i__) {
	if (s_cmp(test, harg + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L50;
	}
	switch (i__) {
	    case 1:  goto L60;
	    case 2:  goto L60;
	    case 3:  goto L70;
	    case 4:  goto L80;
	    case 5:  goto L90;
	}
L50:
	;
    }

/*             NO FURTHER CONDITION CHANGE */
    goto L999;

/*             MOTION DIRECTION OR NORMAL DIRECTION (FLAG AND VALUE) */
L60:
    cclear_1.idirmo[mp - 1] = 1;
    cclear_1.dirmot[i__ + mp * 3 - 4] = sscan[is + 1];
    goto L100;

/*             MOTION DIRECTION OR NORMAL DIRECTION (FLAG AND VALUE) */
L70:
    is += 2;
    if (ckdef_(&sscan[is - 1])) {
	goto L130;
    }
    k = is - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L75: */
	cclear_1.dirmot[i__ + mp * 3 - 4] = sscan[k + i__ - 1];
    }
    cclear_1.idirmo[mp - 1] = 2;
    goto L100;

/*             SPECIAL FEEDRATES */
L80:
    cclear_1.gofeed[mp - 1] = sscan[is + 1];
    goto L100;

/*             CLEARANCE SURFACES */
L90:
    if (ckdef_(&sscan[is + 1])) {
	goto L130;
    }
    cclear_1.icanin[mp - 1] = (addrss_(&cname[1]) - addrss_(_BLNK__1.com)) / 
	    8 + 1;
    i__ = (integer) sscan[is];
    k = 5;
    if (i__ < 8) {
	k = lcnn[i__ - 1];
    }
    is += k;
    goto L110;

L100:
    is += 4;
L110:
    if (is < ie) {
	goto L40;
    }

/* IF NO MOTION, SET MOTION-DIRECTION ZERO */
L115:
    if (cclear_1.dirmot[mp * 3 - 3] == 0. && cclear_1.dirmot[mp * 3 - 2] == 
	    0. && cclear_1.dirmot[mp * 3 - 1] == 0.) {
	cclear_1.idirmo[mp - 1] = 0;
    }

/* SET DEFAULT FOR FEED, IF ZERO-FEDRAT GIVEN */
    if (cclear_1.gofeed[mp - 1] == 0.) {
	cclear_1.gofeed[mp - 1] = 50.;
    }

L120:
    goto L999;

L130:
    error_(&c__5157, "GCLEAR  ", (ftnlen)8);
    goto L120;

L999:
    return 0;
} /* gclear_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


