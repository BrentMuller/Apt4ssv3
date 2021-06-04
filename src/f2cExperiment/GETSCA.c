/* GETSCA.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002771.V04   *** */


/* Subroutine */ int getsca_(doublereal *scan, doublereal *spl, doublereal *
	pnts, doublereal *ptans, doublereal *pcrs, doublereal *tan__, 
	doublereal *ctan, integer *ipara, integer *ilin, integer *itw)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, ia, ib, ic, id, ie, ja, ig, jb, jc, jd, je, jf, 
	    jg, jh, ji, jj, jk, jl, jw, jx, jy, jz, iaa, ibb;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nph;
    static doublereal tema, temb;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer idebug;
#define bcanon ((doublereal *)&_BLNK__1 + 40)

/* ----------SCULPTURED SURFACE ROUTINE ------- JULY 1971  *LPK* */
/* ----------GET SSCAN ARRAY */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --ipara;
    --ctan;
    --tan__;
    --scan;

    /* Function Body */
    idebug = 0;
/* ---------- XYZ */
    ia = (integer) (*spl);
    ib = (integer) (*pnts);
    ic = (integer) (*ptans - 1);
    id = (integer) (*pcrs - 1);
    nph = (integer) sscan[3];
    ie = nph * 6 + 10;
    ig = ie;
    iaa = ia - 1;
    ibb = ib - 1;
    if (*ilin == 1) {
	goto L2000;
    }
    i__1 = iaa;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ibb;
	for (j = 1; j <= i__2; ++j) {
	    ja = (i__ - 1) * ib * 3 + (j - 1) * 3;
	    jb = (i__ - 1) * ib * 3 + j * 3;
	    jc = ic + ja;
	    jd = ic + jb;
	    je = i__ * ib * 3 + (j - 1) * 3;
	    jf = i__ * ib * 3 + j * 3;
	    jg = je + ic;
	    jh = jf + ic;
	    ji = id + (j - 1) * ia * 3 + (i__ - 1) * 3;
	    jj = id + i__ * 3 + (j - 1) * ia * 3;
	    jk = id + j * ia * 3 + (i__ - 1) * 3;
	    jl = id + j * ia * 3 + i__ * 3;
	    jx = (j - 1) * 3 + (i__ - 1) * 3 * ibb;
	    jy = (j - 1) * 3 + i__ * 3 * ibb;
	    jz = (i__ - 1) * 3 + (j - 1) * 3 * iaa;
	    jw = (i__ - 1) * 3 + j * 3 * iaa;
	    for (k = 1; k <= 3; ++k) {
		sscan[ig] = scan[ja + k];
		sscan[ig + 1] = scan[jb + k];
		sscan[ig + 2] = scan[jc + k];
		if (ipara[1] == 1) {
		    goto L1002;
		}
		sscan[ig + 3] = scan[jd + k];
L1012:
		sscan[ig + 4] = scan[je + k];
		sscan[ig + 5] = scan[jf + k];
		sscan[ig + 6] = scan[jg + k];
		if (ipara[1] == 1) {
		    goto L1003;
		}
		sscan[ig + 7] = scan[jh + k];
L1013:
		sscan[ig + 8] = scan[ji + k];
		sscan[ig + 9] = scan[jk + k];
		if (ipara[2] == 1) {
		    goto L1031;
		}
		sscan[ig + 10] = scan[jj + k];
		sscan[ig + 11] = scan[jl + k];
		goto L1005;
/* ----------PARALLEL CASE */
L1002:
		sscan[ig + 3] = tan__[jx + k];
		goto L1012;
L1003:
		sscan[ig + 7] = tan__[jy + k];
		goto L1013;
L1031:
		sscan[ig + 10] = ctan[jz + k];
		sscan[ig + 11] = ctan[jw + k];
L1005:
		if (*itw == 0) {
		    goto L1101;
		}
/* ---------- INSERT TWIST VECTOR,IF SPL=2 OR PNTS=2 */
		tema = sscan[ig + 10];
		temb = sscan[ig + 11];
		if (*itw == 2) {
		    goto L1110;
		}
		sscan[ig + 10] = sscan[ig + 6] - sscan[ig + 2];
		sscan[ig + 11] = sscan[ig + 7] - sscan[ig + 3];
		goto L1111;
L1110:
		sscan[ig + 10] = sscan[ig + 9] - sscan[ig + 8];
		sscan[ig + 11] = temb - tema;
L1111:
		sscan[ig + 12] = tema;
		sscan[ig + 13] = temb;
		sscan[ig + 14] = sscan[ig + 10];
		sscan[ig + 15] = sscan[ig + 11];
L1101:
		ig += 12;
		if (*itw != 0) {
		    ig += 4;
		}
/* L1100: */
	    }
	    sscan[ig] = 1.f;
	    ++ig;
/* L1000: */
	}
    }
    goto L9999;
L2000:
    i__2 = iaa;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = ibb;
	for (j = 1; j <= i__1; ++j) {
	    ja = (i__ - 1) * ib * 3 + (j - 1) * 3;
	    jb = (i__ - 1) * ib * 3 + j * 3;
	    jc = ic + ja;
	    jd = ic + jb;
	    je = i__ * ib * 3 + (j - 1) * 3;
	    jf = i__ * ib * 3 + j * 3;
	    jg = je + ic;
	    jh = jf + ic;
	    ji = id + (j - 1) * ia * 3 + (i__ - 1) * 3;
	    jj = id + i__ * 3 + (j - 1) * ia * 3;
	    jk = id + j * ia * 3 + (i__ - 1) * 3;
	    jl = id + j * ia * 3 + i__ * 3;
	    jx = (j - 1) * 3 + (i__ - 1) * 3 * ibb;
	    jy = (j - 1) * 3 + i__ * 3 * ibb;
	    jz = (i__ - 1) * 3 + (j - 1) * 3 * iaa;
	    jw = (i__ - 1) * 3 + j * 3 * iaa;
	    if ((d__1 = sscan[5] - 2.f) < 0.) {
		goto L2100;
	    } else if (d__1 == 0) {
		goto L2200;
	    } else {
		goto L2300;
	    }
/* ----------XYPLAN */
L2100:
	    sscan[ig] = scan[ja + 1];
	    sscan[ig + 1] = scan[jb + 1];
	    sscan[ig + 2] = scan[je + 1];
	    sscan[ig + 3] = scan[jf + 1];
	    sscan[ig + 4] = scan[ja + 2];
	    sscan[ig + 5] = scan[jb + 2];
	    sscan[ig + 6] = scan[je + 2];
	    sscan[ig + 7] = scan[jf + 2];
	    sscan[ig + 8] = scan[ja + 3];
	    sscan[ig + 9] = scan[jb + 3];
	    sscan[ig + 10] = scan[jc + 3];
	    if (ipara[1] == 1) {
		goto L2102;
	    }
	    sscan[ig + 11] = scan[jd + 3];
L2112:
	    sscan[ig + 12] = scan[je + 3];
	    sscan[ig + 13] = scan[jf + 3];
	    sscan[ig + 14] = scan[jg + 3];
	    if (ipara[1] == 1) {
		goto L2103;
	    }
	    sscan[ig + 15] = scan[jh + 3];
L2113:
	    sscan[ig + 16] = scan[ji + 3];
	    sscan[ig + 17] = scan[jk + 3];
	    if (ipara[2] == 1) {
		goto L2131;
	    }
	    sscan[ig + 18] = scan[jj + 3];
	    sscan[ig + 19] = scan[jl + 3];
	    goto L2107;
/* ----------PARALLEL CASE */
L2102:
	    sscan[ig + 11] = tan__[jx + 3];
	    goto L2112;
L2103:
	    sscan[ig + 15] = tan__[jy + 3];
	    goto L2113;
L2131:
	    sscan[ig + 18] = ctan[jz + 3];
	    sscan[ig + 19] = ctan[jw + 3];
L2107:
	    if (*itw == 0) {
		goto L2105;
	    }
/* ---------- INSERT TWIST VECTOR,IF SPL=2 OR PNTS=2 */
	    tema = sscan[ig + 18];
	    temb = sscan[ig + 19];
	    if (*itw == 2) {
		goto L2110;
	    }
	    sscan[ig + 18] = sscan[ig + 14] - sscan[ig + 10];
	    sscan[ig + 19] = sscan[ig + 15] - sscan[ig + 11];
	    goto L2111;
L2110:
	    sscan[ig + 18] = sscan[ig + 17] - sscan[ig + 16];
	    sscan[ig + 19] = temb - tema;
L2111:
	    sscan[ig + 20] = tema;
	    sscan[ig + 21] = temb;
	    sscan[ig + 22] = sscan[ig + 18];
	    sscan[ig + 23] = sscan[ig + 19];
	    goto L2106;
/* ---------- YZPLAN */
L2200:
	    sscan[ig] = scan[ja + 1];
	    sscan[ig + 1] = scan[jb + 1];
	    sscan[ig + 2] = scan[jc + 1];
	    if (ipara[1] == 1) {
		goto L2202;
	    }
	    sscan[ig + 3] = scan[jd + 1];
L2212:
	    sscan[ig + 4] = scan[je + 1];
	    sscan[ig + 5] = scan[jf + 1];
	    sscan[ig + 6] = scan[jg + 1];
	    if (ipara[1] == 1) {
		goto L2203;
	    }
	    sscan[ig + 7] = scan[jh + 1];
L2213:
	    sscan[ig + 8] = scan[ji + 1];
	    sscan[ig + 9] = scan[jk + 1];
	    if (ipara[2] == 1) {
		goto L2231;
	    }
	    sscan[ig + 10] = scan[jj + 1];
	    sscan[ig + 11] = scan[jl + 1];
L2215:
	    sscan[ig + 12] = scan[ja + 2];
	    sscan[ig + 13] = scan[jb + 2];
	    sscan[ig + 14] = scan[je + 2];
	    sscan[ig + 15] = scan[jf + 2];
	    sscan[ig + 16] = scan[ja + 3];
	    sscan[ig + 17] = scan[jb + 3];
	    sscan[ig + 18] = scan[je + 3];
	    sscan[ig + 19] = scan[jf + 3];
	    if (*itw == 0) {
		goto L2105;
	    }
/* ---------- INSERT TWIST VECTOR,IF SPL=2 OR PNTS=2 */
	    tema = sscan[ig + 10];
	    temb = sscan[ig + 11];
	    sscan[ig + 16] = sscan[ig + 12];
	    sscan[ig + 17] = sscan[ig + 13];
	    sscan[ig + 18] = sscan[ig + 14];
	    sscan[ig + 19] = sscan[ig + 15];
	    sscan[ig + 20] = sscan[ig + 16];
	    sscan[ig + 21] = sscan[ig + 17];
	    sscan[ig + 22] = sscan[ig + 18];
	    sscan[ig + 23] = sscan[ig + 19];
	    if (*itw == 2) {
		goto L2210;
	    }
	    sscan[ig + 10] = sscan[ig + 6] - sscan[ig + 2];
	    sscan[ig + 11] = sscan[ig + 7] - sscan[ig + 3];
	    goto L2211;
L2210:
	    sscan[ig + 10] = sscan[ig + 9] - sscan[ig + 8];
	    sscan[ig + 11] = temb - tema;
L2211:
	    sscan[ig + 12] = tema;
	    sscan[ig + 13] = temb;
	    sscan[ig + 14] = sscan[ig + 10];
	    sscan[ig + 15] = sscan[ig + 11];
	    goto L2106;
/* ----------PARALLEL CASE */
L2202:
	    sscan[ig + 3] = tan__[jx + 1];
	    goto L2212;
L2203:
	    sscan[ig + 7] = tan__[jy + 1];
	    goto L2213;
L2231:
	    sscan[ig + 10] = ctan[jz + 1];
	    sscan[ig + 11] = ctan[jw + 1];
	    goto L2215;
/* ----------ZXPLAN */
L2300:
	    sscan[ig] = scan[ja + 1];
	    sscan[ig + 1] = scan[jb + 1];
	    sscan[ig + 2] = scan[je + 1];
	    sscan[ig + 3] = scan[jf + 1];
	    sscan[ig + 4] = scan[ja + 2];
	    sscan[ig + 5] = scan[jb + 2];
	    sscan[ig + 6] = scan[jc + 2];
	    if (ipara[1] == 1) {
		goto L2302;
	    }
	    sscan[ig + 7] = scan[jd + 2];
L2312:
	    sscan[ig + 8] = scan[je + 2];
	    sscan[ig + 9] = scan[jf + 2];
	    sscan[ig + 10] = scan[jg + 2];
	    if (ipara[1] == 1) {
		goto L2303;
	    }
	    sscan[ig + 11] = scan[jh + 2];
L2313:
	    sscan[ig + 12] = scan[ji + 2];
	    sscan[ig + 13] = scan[jk + 2];
	    if (ipara[2] == 1) {
		goto L2331;
	    }
	    sscan[ig + 14] = scan[jj + 2];
	    sscan[ig + 15] = scan[jl + 2];
L2315:
	    sscan[ig + 16] = scan[ja + 3];
	    sscan[ig + 17] = scan[jb + 3];
	    sscan[ig + 18] = scan[je + 3];
	    sscan[ig + 19] = scan[jf + 3];
	    if (*itw == 0) {
		goto L2105;
	    }
/* ---------- INSERT TWIST VECTOR,IF SPL=2 OR PNTS=2 */
	    tema = sscan[ig + 14];
	    temb = sscan[ig + 15];
	    sscan[ig + 20] = sscan[ig + 16];
	    sscan[ig + 21] = sscan[ig + 17];
	    sscan[ig + 22] = sscan[ig + 18];
	    sscan[ig + 23] = sscan[ig + 19];
	    if (*itw == 2) {
		goto L2310;
	    }
	    sscan[ig + 14] = sscan[ig + 10] - sscan[ig + 6];
	    sscan[ig + 15] = sscan[ig + 11] - sscan[ig + 7];
	    goto L2311;
L2310:
	    sscan[ig + 14] = sscan[ig + 13] - sscan[ig + 12];
	    sscan[ig + 15] = temb - tema;
L2311:
	    sscan[ig + 16] = tema;
	    sscan[ig + 17] = temb;
	    sscan[ig + 18] = sscan[ig + 14];
	    sscan[ig + 19] = sscan[ig + 15];
	    goto L2106;
/* ----------PARALLEL CASE */
L2302:
	    sscan[ig + 7] = tan__[jx + 2];
	    goto L2312;
L2303:
	    sscan[ig + 11] = tan__[jy + 2];
	    goto L2313;
L2331:
	    sscan[ig + 14] = ctan[jz + 2];
	    sscan[ig + 15] = ctan[jw + 2];
	    goto L2315;
L2105:
	    sscan[ig + 20] = 1.f;
	    ig += 21;
	    goto L2001;
L2106:
	    sscan[ig + 24] = 1.f;
	    ig += 25;
L2001:
	    ;
	}
    }
L9999:
    return 0;
} /* getsca_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


