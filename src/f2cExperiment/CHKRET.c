/* CHKRET.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000873.V02   *** */

/* .....FORTRAN SUBROUTINE ....CHKRET              8/68               RN */

/*              FORTRAN SUBROUTINE CHKRET */

/* PURPOSE      THIS SUBROUTINE IS A TABCYL INTERVAL SCREENING TECHNIQUE */
/*              THAT CONSTRUCTS A RECTANGLE AROUND THE INTERVAL BEING */
/*              CONSIDERED. */

/* LINKAGE      CALL CHKRET(IHU,RAD,INTRCT,D,S) */

/* ARGUMENTS    IHU    INDEX OF CURRENT TABCYL SEGMENT */
/*              RAD    THE RADIUS OF THE CIRCLE */
/*              INTRCT */

/*              D      THE ARRAY CONTAINING THE TABCYL EXTERNAL */
/*                     CANONICAL FORM */
/*              S      THE ARRAY CONTAINING LINE CANONICAL FORM */
/* SUBSIDIARIES  NONE */

/* Subroutine */ int chkret_(integer *ihu, doublereal *rad, integer *intrct, 
	doublereal *d__, doublereal *s)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal rd, px[6], py[6], bo1, bo2, bo3, bo4, bo5, bo6, bo7, 
	    bo8, sl1x, sl1y, sl2y, sl2x, delx, dely, dihu4, bplin, value;
    static integer minus, iplus;
    static doublereal x1plin, y1plin, xpline, ypline, slplin;
    static integer ivertl;

    /* Parameter adjustments */
    --s;
    --d__;

    /* Function Body */
    ivertl = 0;
    minus = 0;
    iplus = 0;
/* L400: */
    dely = d__[*ihu + 8] - d__[*ihu + 1];
    delx = d__[*ihu + 7] - d__[*ihu];
    dihu4 = d__[*ihu + 4];
    if (abs(dihu4) < 1e-7) {
	dihu4 = 1e-7;
    }
    sl1y = dely / dihu4;
    sl1x = delx / dihu4;
    sl2y = sl1x;
    sl2x = -sl1y;
    rd = *rad + 1e-6;
    bo1 = rd * sl1x;
    bo2 = rd * sl1y;
    bo3 = (d__1 = d__[*ihu + 5], abs(d__1)) + rd;
    bo4 = bo3 * sl2x;
    bo5 = bo3 * sl2y;
    bo6 = (d__1 = d__[*ihu + 6], abs(d__1)) + rd;
    bo7 = bo6 * sl2x;
    bo8 = bo6 * sl2y;
    px[4] = d__[*ihu] - bo1;
    py[4] = d__[*ihu + 1] - bo2;
    px[0] = px[4] + bo4;
    py[0] = py[4] + bo5;
    px[3] = px[4] - bo7;
    py[3] = py[4] - bo8;
    px[5] = d__[*ihu + 7] + bo1;
    py[5] = d__[*ihu + 8] + bo2;
    px[1] = px[5] + bo4;
    py[1] = py[5] + bo5;
    px[2] = px[5] - bo7;
    py[2] = py[5] - bo8;
    xpline = s[1] * s[4];
    if (abs(s[2]) - 1e-7 <= 0.) {
	goto L1;
    } else {
	goto L2;
    }
L1:
    ivertl = 1;
    goto L3;
L2:
    slplin = -s[1] / s[2];
    x1plin = s[1] * s[4];
    y1plin = s[2] * s[4];
    bplin = y1plin - slplin * x1plin;
L3:
    for (i__ = 1; i__ <= 4; ++i__) {
	if (ivertl <= 0) {
	    goto L5;
	} else {
	    goto L6;
	}
L5:
	ypline = slplin * px[i__ - 1] + bplin;
	value = py[i__ - 1] - ypline;
	goto L4;
L6:
	value = px[i__ - 1] - xpline;
L4:
	if (value < 0.) {
	    goto L11;
	} else if (value == 0) {
	    goto L12;
	} else {
	    goto L13;
	}
L11:
	minus = 1;
	goto L10;
L13:
	iplus = 1;
L10:
	;
    }
/* L14: */
    if (minus - iplus != 0) {
	goto L15;
    } else {
	goto L12;
    }

/*     THE APPROPRIATE LINE, THAT IS,THE ACTUAL LINE FOR TABPNT OR THE */
/*     RADIUS PARALLEL LINE FOR TABCIR DOES NOT INTERSECT THE RECTANGLE */
/*     THUS THIS INTERVAL IS ELIMINATED FROM FURTHER CONSIDERATION. */

L15:
    *intrct = 0;
    goto L16;

/*     THE APPROPRIATE LINE DOES INTERSECT THE RECTANGLE SO THIS INTERVAL */
/*     MUST BE EXAMINED FURTHER */

L12:
    *intrct = 1;
L16:
    return 0;
} /* chkret_ */

