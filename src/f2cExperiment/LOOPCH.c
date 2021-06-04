/* LOOPCH.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001897.V03   *** */

/* Subroutine */ int lodpch_(doublereal *ss, doublereal *b, integer *iflag, 
	integer *itop, integer *n, integer *mode)
{
    /* Initialized data */

    static integer ixyz[9]	/* was [3][3] */ = { 0,16,32,16,32,0,32,0,16 }
	    ;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;
    static doublereal equiv_0[1];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, k, l, m;
    static doublereal d1, d2, d3, d4;
    static integer ia, ib, ic, id, jl, im, ju;
#define aaa (equiv_0)
#define jjj ((integer *)equiv_0)
    static integer ict, ift;
    static doublereal temp[2];
    static integer isum;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    static integer ibrel, jmode, npchs, itemp, itrel;

/* ------INPUT A SCULPTURED SURFACE DATA PACK SS AND A PATCH */
/* ------ NUMBER N.  OUTPUT THE PATCH COEFFICIENTS INTO THE */
/* ------ ARRAY B, THE FOUR MATRIX FLAGS INTO IFLAG AND */
/* ------ THE TOPOLOGY ENTRIES INTO ITOP */
/* ---     TEMPORARY ARRAY TO HOLD INTERIM CANON FORM OF SURFACE */
/* ---     INTEGER JJJ IS EQUIVALENCED TO AAA BECAUSE THIRD ARGUMENT */
/* ---     OF APT094 IS SUPPOSED TO BE ON A DOUBLE WORD BOUNDARY */


    /* Parameter adjustments */
    itop -= 7;
    --iflag;
    --b;
    --ss;

    /* Function Body */

    npchs = (integer) ss[4];
    if (*n > npchs) {
	goto L998;
    }
    itemp = (*n - 1) * 6 + 11;
    iflag[1] = (integer) ss[itemp];
    iflag[2] = (integer) ss[itemp + 1];
    iflag[3] = (integer) ss[itemp + 2];
    iflag[4] = (integer) ss[itemp + 3];
    if (iflag[1] < 9) {
	ibrel = (integer) ss[itemp + 4];
	itrel = (integer) ss[itemp + 5];
    } else {
	itrel = (integer) ss[itemp + 5];
    }
/* ---     SPECIAL LOGIC IS FOLLOWED FOR A GENERAL CURVE TYPE PATCH */

    if (iflag[1] < 9) {
	goto L90;
    }

/* ---     GENERAL CURVE TYPE PATCH, OBTAIN INDEX TO SURFACE IN COMMON */
    jmode = 3;
    *jjj = 0;
/* ---     RETRIEVE THE LOCATION OF SS IN COMMON */
    temp[0] = ss[1];
    temp[1] = ss[8];
    apt094_(&jmode, temp, jjj);
/* ---     NOW JJJ SHOULD CONTAIN THE START OF SS IN COMMON */
/* ---     THE FOUR FLAGS WHICH CONTAIN RELATIVE ADDRESSES SHOULD */
/* ---     NOW BE CONVERTED TO ABSOLUTE ADDRESSES IN COMMON */
    for (i__ = 1; i__ <= 4; ++i__) {
	if (iflag[i__] > 0) {
	    iflag[i__] = iflag[i__] + *jjj - 1;
	}
/* L15: */
    }
    if (*mode == 2) {
	goto L501;
    }
/* ---     THE PARTICULAR TYPE OF GENCUR SURFACE IS STORED IN */
/* ---     THE B-ARRAY.  OTHERWISE, THIS ARRAY IS RESERVED FOR */
/* ---     THE COEFFICIENTS OF A COONS BICUBIC PATCH. */
    for (l = 2; l <= 64; ++l) {
/* L13: */
	b[l] = 0.f;
    }
    b[49] = 1.f;
    b[50] = 1.f;
    b[53] = 1.f;
    b[54] = 1.f;

    b[1] = ss[itemp + 4];
    if (*mode <= 1) {
	return 0;
    }
    goto L501;

L90:
/* ---     CASE OF A CONVENTIONAL COONS BICUBIC FOLLOWS */

    if (*mode == 2) {
	goto L501;
    }
    m = -15;
    for (l = 1; l <= 4; ++l) {
	m += 16;
	ift = iflag[l];
	if (ift > 4) {
	    ift = 3;
	}
	switch (ift) {
	    case 1:  goto L100;
	    case 2:  goto L200;
	    case 3:  goto L400;
	    case 4:  goto L400;
	}
L100:
	b[m] = 1.f;
	++ibrel;
	b[m + 1] = b[m];
	b[m + 2] = 0.f;
	b[m + 3] = 0.f;
	b[m + 4] = b[m];
	b[m + 5] = b[m];
	jl = m + 6;
	ju = m + 15;
	i__1 = ju;
	for (k = jl; k <= i__1; ++k) {
/* L120: */
	    b[k] = 0.f;
	}
	goto L10;
L200:
	b[m] = ss[ibrel];
	b[m + 1] = ss[ibrel + 1];
	b[m + 4] = ss[ibrel + 2];
	b[m + 5] = ss[ibrel + 3];
	ibrel += 4;
	b[m + 2] = b[m + 1] - b[m];
	b[m + 3] = b[m + 2];
	b[m + 6] = b[m + 5] - b[m + 4];
	b[m + 7] = b[m + 6];
	b[m + 8] = b[m + 4] - b[m];
	b[m + 12] = b[m + 8];
	b[m + 9] = b[m + 5] - b[m + 1];
	b[m + 13] = b[m + 9];
	b[m + 10] = b[m + 6] - b[m + 2];
	b[m + 14] = b[m + 10];
	b[m + 11] = b[m + 7] - b[m + 3];
	b[m + 15] = b[m + 11];
	goto L10;
L400:
	im = m - 1;
	ib = ibrel - 1;
	b[im + 1] = ss[ib + 1];
	b[im + 2] = ss[ib + 2];
	b[im + 3] = ss[ib + 3];
	b[im + 4] = ss[ib + 4];
	b[im + 5] = ss[ib + 5];
	b[im + 6] = ss[ib + 6];
	b[im + 7] = ss[ib + 7];
	b[im + 8] = ss[ib + 8];
	b[im + 9] = ss[ib + 9];
	b[im + 10] = ss[ib + 10];
	if (ift == 3) {
	    goto L300;
	}
	b[im + 11] = ss[ib + 11];
	b[im + 12] = ss[ib + 12];
	b[im + 13] = ss[ib + 13];
	b[im + 14] = ss[ib + 14];
	b[im + 15] = ss[ib + 15];
	b[im + 16] = ss[ib + 16];
	ibrel += 16;
	goto L10;
L300:
	b[im + 11] = 0.f;
	b[im + 12] = 0.f;
	b[im + 13] = ss[ib + 11];
	b[im + 14] = ss[ib + 12];
	b[im + 15] = 0.f;
	b[im + 16] = 0.f;
	ibrel += 12;
L10:
	;
    }
/* ------ FURTHER MODIFICATION IS REQUIRED FOR XY,YZ OR ZX CASE */
    isum = iflag[1] + iflag[2] + iflag[3];
    if (isum >= 9) {
	goto L20;
    }
    id = 1;
    if (iflag[1] >= 3) {
	id = 2;
    }
    if (iflag[2] >= 3) {
	id = 3;
    }
    ia = ixyz[id * 3 - 3];
    ib = ixyz[id * 3 - 2];
    ic = ixyz[id * 3 - 1];
/* Computing 2nd power */
    d__1 = b[ia + 2] - b[ia + 1];
/* Computing 2nd power */
    d__2 = b[ib + 2] - b[ib + 1];
    d1 = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = b[ia + 5] - b[ia + 1];
/* Computing 2nd power */
    d__2 = b[ib + 5] - b[ib + 1];
    d2 = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = b[ia + 6] - b[ia + 2];
/* Computing 2nd power */
    d__2 = b[ib + 6] - b[ib + 2];
    d3 = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = b[ia + 6] - b[ia + 5];
/* Computing 2nd power */
    d__2 = b[ib + 6] - b[ib + 5];
    d4 = d__1 * d__1 + d__2 * d__2;
    d1 = sqrt(d1);
    d2 = sqrt(d2);
    d3 = sqrt(d3);
    d4 = sqrt(d4);
    b[ic + 3] *= d1;
    b[ic + 4] *= d1;
    b[ic + 7] *= d4;
    b[ic + 8] *= d4;
    b[ic + 9] *= d2;
    b[ic + 13] *= d2;
    b[ic + 10] *= d3;
    b[ic + 14] *= d3;
L20:
    if (*mode == 1) {
	return 0;
    }
/* ------NOW LOAD THE TOPOLOGY DATA INTO ITOP */
L501:
    for (l = 1; l <= 4; ++l) {
	ict = 1;
L530:
	++ict;
	itop[ict + l * 6] = (integer) ss[itrel + ict - 2];
	if (itop[ict + l * 6] >= 0) {
	    goto L550;
	} else {
	    goto L540;
	}
L540:
	itop[ict + l * 6] = -itop[ict + l * 6];
	goto L530;
L550:
	itop[ict - 1 + l * 6] = ict - 1;
	itrel = itrel + ict - 1;
/* L500: */
    }
L998:
    return 0;
} /* lodpch_ */

#undef jjj
#undef aaa


