/* PNTSON.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0004286.V02   *** */


/* Subroutine */ int pntson_(doublereal *bin, doublereal *out, integer *ktyp, 
	integer *ktws, integer *irr)
{
    /* Initialized data */

    static integer nexch[16] = { 1,2,3,4,13,14,15,16,5,9,8,12,6,7,10,11 };
    static integer ip[4] = { 1,5,1,4 };
    static integer jp[4] = { 4,8,5,8 };

    static integer i__, j, k, n;
    static doublereal u[4], v[4], w;
    static integer ie;
    static doublereal dp;
    static integer in, ll, is;
    static doublereal dx, dy, dz, px, py, pz, one, bou[48]	/* was [3][16]
	     */, bxs, duv[4], bys, bzs, crit, temp[12]	/* was [4][3] */;
    static integer idiag;
    extern /* Subroutine */ int curfit_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *), comptw_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer numtws;

    /* Parameter adjustments */
    --ktws;
    --ktyp;
    --out;
    bin -= 4;

    /* Function Body */
/* ------INPUT SIXTEEN POINTS ON A PATCH STORED IN THE ARRAY BIN. */
/* ------OUTPUT  SIXTEEN COONS VECTORS OF A COONS PATCH WHICH PASSES */
/* ------ THRU THE INPUT POINTS */
/* ------ IN ADDITION, KTYP() CONTAINS INFORMATION ON SURFACE TYPE AND */
/* ------KTYP=1=NULL CURVE, =2=STRAIGHT SEG, =3=3 PT CURVE, */
/* ------KTYP=4= 4 PT CURVE, =10=ERROR ON CURVE */
/* ------ SOURCES OF TROUBLE IN THE INPUT */
/* ------ IRR .NE. 0 MEANS THE PROCESSING WAS UNSUCESSFUL */
/* ------INITIALIZE VARIOUS VALUES */
    idiag = 5390;
    *irr = 0;
/* ------ BEGIN BY ALTERING THE ORDER OF INPUT FROM SSX2 FORMAT TO THE */
/* ------ OLD SSX1 FORMAT( THIS IS DONE TO SAVE REWORKING PNTSON) */
    for (j = 1; j <= 16; ++j) {
	n = nexch[j - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
	    bou[i__ + j * 3 - 4] = bin[i__ + n * 3];
/* L5: */
	}
    }
    for (j = 1; j <= 16; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L6: */
	    bin[i__ + j * 3] = bou[i__ + j * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	ktws[i__] = 0;
/* L1: */
	ktyp[i__] = 0;
    }
    for (i__ = 1; i__ <= 16; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    ktyp[3] = 2;
	    ktyp[4] = 2;
/* L2: */
	    bou[j + i__ * 3 - 4] = 0.f;
	}
    }
    for (j = 1; j <= 3; ++j) {
	bou[j - 1] = bin[j + 3];
	bou[j + 2] = bin[j + 12];
	bou[j + 11] = bin[j + 15];
/* L3: */
	bou[j + 14] = bin[j + 24];
    }
    crit = 1e-5f;
/* ------NEXT FIT THE FIRST TWO BOUNDARIES */
    curfit_(&bin[4], &bin[7], &bin[10], &bin[13], &bou[6], &bou[9], &ktyp[1], 
	    irr);
    if (*irr != 0) {
	ktyp[1] = 10;
    }
    curfit_(&bin[16], &bin[19], &bin[22], &bin[25], &bou[18], &bou[21], &ktyp[
	    2], irr);
    if (*irr != 0) {
	ktyp[2] = 10;
    }
/* ------NEXT, CHECK FOR TOTAL EQUALITY AMONG THE EIGHT CENTRAL VECTORS */
/* ------ SUCH EQUALITY IMPLIES THE SURFACE IS RULED */
    for (i__ = 9; i__ <= 15; ++i__) {
	n = i__ + 1;
	for (j = n; j <= 16; ++j) {
	    for (k = 1; k <= 3; ++k) {
		w = bin[k + j * 3] - bin[k + i__ * 3];
		if (abs(w) > crit) {
		    goto L300;
		}
/* L20: */
	    }
/* L10: */
	}
    }
/* ------ ALL EQUALITY CHECKS HAVE BEEN MET -- A RULED SURFACE FOLLOWS */
/* ------DETERMINE THE REMAINING TANGENTS AND TWISTS */
    ktyp[5] = 1;
    for (j = 1; j <= 3; ++j) {
/* ------SET UP THE CROSS TANGENTS FIRST */
	bou[j + 23] = bin[j + 15] - bin[j + 3];
	bou[j + 35] = bou[j + 23];
	bou[j + 26] = bin[j + 24] - bin[j + 12];
	bou[j + 38] = bou[j + 26];
/* ------NOW SET UP TWIST VECTORS */
	bou[j + 29] = bou[j + 17] - bou[j + 5];
	bou[j + 41] = bou[j + 29];
	bou[j + 32] = bou[j + 20] - bou[j + 8];
	bou[j + 44] = bou[j + 32];
/* L210: */
    }
/* ------FINALLY RESET IRR */
    for (i__ = 1; i__ <= 2; ++i__) {
/* L220: */
	if (ktyp[i__] == 10) {
	    *irr = idiag + 1;
	}
    }
    goto L999;
/* -----------   END OF RULED SURFACE PROCESSING   ------------- */
L300:
/* ------NEXT COMPARE FOR TWO EQUAL CENTER POINTS */
    numtws = 4;
    for (i__ = 13; i__ <= 15; ++i__) {
	n = i__ + 1;
	for (j = n; j <= 16; ++j) {
	    for (k = 1; k <= 3; ++k) {
		w = bin[k + j * 3] - bin[k + i__ * 3];
		if (abs(w) > crit) {
		    goto L310;
		}
/* L320: */
	    }
	    numtws = 0;
L310:
	    ;
	}
    }
/* ------NUMTWS=0 MEANS ZERO TWISTS, .NE.0 MEANS NON ZERO TWISTS */
/* ------NEXT CALL FOR A FIT OF THE REMAINING TWO BOUNDARIES */
    curfit_(&bin[4], &bin[28], &bin[31], &bin[16], &bou[24], &bou[36], &ktyp[
	    3], irr);
    if (*irr != 0) {
	ktyp[3] = 10;
    }
    curfit_(&bin[13], &bin[34], &bin[37], &bin[25], &bou[27], &bou[39], &ktyp[
	    4], irr);
    if (*irr != 0) {
	ktyp[4] = 10;
    }
/* ------IF TWISTS HAVE YET TO BE DETERMINED GO TO 500 */
    if (numtws != 0) {
	goto L500;
    }
/* ------FINISH THE ZERO TWIST CASE BY RESETTING IRR */
    for (i__ = 1; i__ <= 4; ++i__) {
/* L410: */
	if (ktyp[i__] == 10) {
	    *irr = idiag + 2;
	}
    }
    ktyp[5] = 2;
    goto L999;
/* ------THE DETERMINATION OF FOUR TWISTS FOLLOWS */
L500:
/* ------FIRST PROJECT EACH OF THE POINTS BIN(,I), I = 13,14,15,16 */
/* ------IN SUCCESSION ONTO THE ZERO TWIST PATCH */
    one = 1.f;
    for (i__ = 13; i__ <= 16; ++i__) {
	for (ll = 1; ll <= 4; ++ll) {
	    is = ip[ll - 1];
	    ie = jp[ll - 1];
	    bxs = bin[is * 3 + 1];
	    bys = bin[is * 3 + 2];
	    bzs = bin[is * 3 + 3];
	    dx = bin[ie * 3 + 1] - bxs;
	    dy = bin[ie * 3 + 2] - bys;
	    dz = bin[ie * 3 + 3] - bzs;
	    px = bin[i__ * 3 + 1] - bxs;
	    py = bin[i__ * 3 + 2] - bys;
	    pz = bin[i__ * 3 + 3] - bzs;
	    dp = dx * dx + dy * dy + dz * dz + 1e-30;
	    duv[ll - 1] = (px * dx + py * dy + pz * dz) / dp;
/* L550: */
	}
	u[i__ - 13] = (duv[0] + duv[1]) / 2.f;
	v[i__ - 13] = (duv[2] + duv[3]) / 2.f;
/* L510: */
    }
/* ------NOW RESET IRR IF TROUBLE HAS OCCURRED AND RETURN */
/* ------KTWS HERE ALWAYS ZERO !!!!!!!!, WHY ???????????? */
    for (i__ = 1; i__ <= 4; ++i__) {
/* L520: */
	if (ktws[i__] != 0) {
	    *irr = idiag + 3;
	}
    }
    if (*irr != 0) {
	return 0;
    }
/* ------FINALLY COMPUTE TWISTS BASED ON PARAMETER VALUES WHICH HAVE */
/* ------ BEEN COMPUTED */
    for (i__ = 1; i__ <= 4; ++i__) {
	for (k = 1; k <= 3; ++k) {
	    n = i__ + 12;
/* L530: */
	    temp[i__ + (k << 2) - 5] = bin[k + n * 3];
	}
    }
/*     WRITE(6,571)(U(M),M=1,4),(V(MM),MM=1,4),TEMP */
/* 571 FORMAT(10X,4F15.4,/) */
    comptw_(bou, temp, u, v, irr);
    ktyp[5] = 3;
L999:
    for (i__ = 1; i__ <= 3; ++i__) {
	for (k = 1; k <= 4; ++k) {
	    for (j = 1; j <= 4; ++j) {
		in = (i__ - 1 << 4) + (k - 1 << 2) + j;
		out[in] = bou[i__ + ((k << 2) - 4 + j) * 3 - 4];
/* L560: */
	    }
	}
    }
    return 0;
} /* pntson_ */

