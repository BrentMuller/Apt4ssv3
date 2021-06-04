/* REVOLV.f -- translated by f2c (version 20100827).
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
    doublereal tabext, ssext;
    integer iold;
} xunits_;

#define xunits_1 xunits_

struct {
    char oldmod[6];
} xunitc_;

#define xunitc_1 xunitc_

/* Table of constant values */

static integer c__0 = 0;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;

/* *** SOURCE FILE : M0004289.W01   *** */

/* Subroutine */ int revolv_(doublereal *sc, doublereal *pa, doublereal *pb, 
	doublereal *da, doublereal *db, integer *icclw, integer *irr, 
	doublereal *s)
{
    /* Initialized data */

    static doublereal z__ = 0.;
    static doublereal u = 1.;
    static doublereal smal = 1e-4;
    static doublereal pi = 3.141592654;
    static doublereal cdr = .01745329252;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double d_mod(doublereal *, doublereal *), cos(doublereal), sin(doublereal)
	    ;

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l;
    static doublereal p[4], t[16]	/* was [4][4] */, v, a1, a2, cc[16]	
	    /* was [4][4] */, bm[64]	/* was [4][4][4] */;
    static integer ii, jj;
    static doublereal bt[16]	/* was [4][4] */, bu[64]	/* was [4][4][
	    4] */;
    static integer ll;
    static doublereal cx[744]	/* was [4][6][31] */;
    static integer kp, is, ir;
    static doublereal ax;
    static integer kz;
    static doublereal ww;
    static integer is3;
    static doublereal fac, dif;
    static integer ncb, nhd, ncm, nhi, ncs, nlo;
    static doublereal tpi;
    static integer nsm, iloc, npch, kseg, nloo, nspl;
    static doublereal wsave;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), snorm_(doublereal *, doublereal *, integer *), scurv_(
	    doublereal *, integer *), cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *), smmult_(integer *, integer *, integer *,
	     integer *, doublereal *, doublereal *, doublereal *);

/* ***** INSERT 2510 UND 4310 : REVOLV FUER 360 GRAD WINKEL */
/* --- SCULPTURED SURFACE ROUTINE TO GENERATE A SCULPTURED SURFACE WHICH */
/* --- REPRESENTS  A SURFACE FORM BY REVOLVING THE SYNTHETIC CURVE SC */
/* --- AROUND AN AXIS THRU PA AND PB FROM ANGLE A TO B.  THE SSURF IS */
/* --- PACKED INTO THE S ARRAY WITHOUT A TOPOLOGY TABLE( CALL TOPGEN) */
/* --- LATER)  IF A PROBLEM OCCURS IRR WILL BE NONZERO ON RETURN */
/* --- ICCLW SHOULD BE 1 IF ANGLE DB IS CLOCKWISE ROTATED FROM DB AND -1 */
/* --- OTHERWISE */
/* --- SECONDARILY, A CYLINDER WITH ARBITRARY AXIS CAN BE GENERATED THRU */
/* --- THE S CURVE SC,  IN ORDER TO ACHIEVE THIS THE INPUT IS AS FOLLOWS */
/* ---  PA AND PB ARE TWO POINTS WHICH DESCRIBE THE AXIS VECTOR OF THE */
/* --- CYLINDER. SET DA=0., DB=90. AND ICCLW=0 */
/*      DIMENSION CX(4,6,4) */





    /* Parameter adjustments */
    --s;
    --pb;
    --pa;
    sc -= 29;

    /* Function Body */
    tpi = 2.f * pi;
/* ---  PROCESS ANGLES FIRST */
    a = *da * cdr;
    b = *db * cdr;
    c__ = (d__1 = a - b, abs(d__1)) - tpi;
    if (*icclw == 0) {
	goto L6;
    }
/* --- NORMALIZE THE ANGLES BETWEEN ZERO AND TPI */
    a = d_mod(&a, &tpi);
    b = d_mod(&b, &tpi);
    if (abs(a) < smal) {
	a = z__;
    }
    if (abs(b) < smal) {
	b = z__;
    }
    if (a < z__) {
	a += tpi;
    }
    if (b < z__) {
	b += tpi;
    }
/* ---  ADJUST THE NUMERICAL VALUE OF B IF NECESSARY */
    if (*icclw * (b - a) >= -smal) {
	b -= *icclw * tpi;
    }
L6:
    dif = b - a;
    if (abs(c__) < smal) {
	dif = -(*icclw) * tpi;
    }
    nspl = (integer) (abs(dif) * 3.f / tpi + 1.9999f);
/* *** NUMBER OF SPLINES MUST BE AT LEAST TWO */
    *irr = 2;
    if (nspl < 2) {
	goto L998;
    }
/* --- DIF BECOMES THE ANGULAR SPAN OF EACH SECTOR OF REVOLUTION */
    dif /= nspl - 1.f;
/* --- THE SURFACE TYPE IS CALLED A MESH (USUALLY) */
    s[5] = 2.f;
/* --- IF THE SURFACE IS CLOSED IT IS CALLED A NON-MESH */
    d__1 = b - a;
    ww = d_mod(&d__1, &tpi);
    if (abs(ww) > smal) {
	goto L10;
    }
    s[5] = 1.f;
L10:
    s[6] = 5.f;
/* ---  DETERMINE CRITICAL DATA FROM THE SCURV AND SET UP THE HEADER OF S */
    nhd = (integer) sc[30];
    ncs = (integer) (sc[32] + 1.f);
    nlo = nhd + 1;
    nhi = nhd + ncs - 1;
    npch = (ncs - 1) * (nspl - 1);
    s[2] = npch * 64.f;
    s[3] = (doublereal) (npch << 2);
    s[4] = (doublereal) npch;
    s[7] = 1.f;
    s[8] = (doublereal) (npch * 74 + 10);
    s[9] = (doublereal) nspl;
    s[10] = (doublereal) ncs;
/* --- FILL IN THE FLAG DATA FOR PATCHES */
    nsm = nspl - 1;
    ncm = ncs - 1;
    i__1 = nsm;
    for (j = 1; j <= i__1; ++j) {
	i__2 = ncm;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    kp = i__ + (j - 1) * ncm;
	    is = (kp - 1) * 6 + 11;
	    is3 = is + 3;
	    i__3 = is3;
	    for (l = is; l <= i__3; ++l) {
/* L30: */
		s[l] = 4.f;
	    }
/* --- COMPUTE THE LOCATION OF PATCH DATA FOR PATCH KP */
	    s[is + 4] = (doublereal) (npch * 6 + 11 + (kp - 1 << 6));
/* L20: */
	}
    }
/* ---   DETERMINE A LOCAL COORDINATE SYSTEM */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L100: */
	bt[i__ - 1] = pb[i__] - pa[i__];
    }
/* ***   PA AND PB SHOULD NOT BE EQUAL */
    *irr = 4;
    snorm_(bt, bt, &ir);
    if (ir != 0) {
	goto L998;
    }
    if (*icclw != 0) {
	goto L70;
    }
/* ---  FOR A CYLINDER SKIP THE COORDINATE TRANSFORMATION BUSINESS */
/* --- SET BT AND T EQUAL TO THE IDENTITY MATRIX */
/* ---  FOR A CYLINDER, LOAD THE AXIS INTO THE P ARRAY */
    for (jj = 1; jj <= 3; ++jj) {
/* L60: */
	p[jj - 1] = bt[jj - 1];
    }
    for (k = 1; k <= 4; ++k) {
	for (j = 1; j <= 4; ++j) {
	    bt[j + (k << 2) - 5] = z__;
	    if (j == k) {
		bt[j + (k << 2) - 5] = u;
	    }
	    t[j + (k << 2) - 5] = bt[j + (k << 2) - 5];
/* L50: */
	}
    }
    goto L150;
L70:
/* --- THE ORIGIN IS AT PA, X- AXIS IS PA,PB */
    i__2 = ncs;
    for (l = 1; l <= i__2; ++l) {
/* Computing MIN */
	i__1 = l + nhd;
	kseg = min(i__1,nhi);
	v = z__;
	if (l == ncs) {
	    v = u;
	}
	cncurv_(&v, &sc[(kseg * 6 + 1 << 2) + 1], p, &c__0);
/* ---  PROJECT THE END POINT OF THE CURVE ONTO PA,VX */
	for (ll = 1; ll <= 3; ++ll) {
/* L120: */
	    p[ll - 1] -= pa[ll];
	}
	cross_(bt, p, &bt[8]);
	snorm_(&bt[8], &bt[8], &ir);
	if (ir != 0) {
	    goto L110;
	}
	cross_(&bt[8], bt, &bt[4]);
	goto L130;
L110:
	;
    }
/* ***  ALL THE END POINTS OF THE CURVE LAY ON THE AXIS */
    *irr = 5;
    goto L998;
L130:
/* ---  SET UP THE TRANSFORMATION TO MOVE THIS COORDINATE SYSTEM INTO */
/* ---  STANDARD POSITION */
    for (i__ = 1; i__ <= 3; ++i__) {
	t[(i__ << 2) - 4] = bt[i__ - 1];
	t[(i__ << 2) - 3] = bt[i__ + 3];
	t[(i__ << 2) - 2] = bt[i__ + 7];
	t[i__ + 11] = z__;
	bt[i__ + 11] = z__;
	bt[(i__ << 2) - 1] = -(pa[1] * bt[(i__ << 2) - 4] + pa[2] * bt[(i__ <<
		 2) - 3] + pa[3] * bt[(i__ << 2) - 2]);
/* L140: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L145: */
	t[(i__ << 2) - 1] = -(bt[3] * t[(i__ << 2) - 4] + bt[7] * t[(i__ << 2)
		 - 3] + bt[11] * t[(i__ << 2) - 2]);
    }
    t[15] = u;
    bt[15] = u;
L150:
/* --- GENERATE PATCHES FOR EACH SECTOR AND EACH CUBIC SPLINE SEGMENT */
/* ---  LOAD THE PATCH VALUES ONE-BY-ONE INTO THE S ARRAY */
    i__2 = nsm;
    for (ii = 1; ii <= i__2; ++ii) {
/* --- SKIP TO SPECIAL AREA FOR A CYLINDER */
	if (*icclw == 0) {
	    goto L250;
	}
/* ---   DETERMINE ANGLES FOR THIS SECTOR */
	a1 = a + (ii - 1) * dif;
	a2 = a + ii * dif;
/* ---  DETERMINE THREE POINTS ON THE BOUNDED UNIT CIRCULAR ARC */
	cx[1] = 1.f;
	cx[2] = 3.f;
	cx[3] = 3.f;
	for (l = 1; l <= 4; ++l) {
	    for (j = 2; j <= 6; ++j) {
		for (k = 1; k <= 4; ++k) {
/* L220: */
		    cx[k + (j + l * 6 << 2) - 29] = z__;
		}
	    }
	}
	for (j = 1; j <= 3; ++j) {
	    ax = (j - 1.f) / 2.f * (a2 - a1) + a1;
	    cx[((j + 1) * 6 + 5 << 2) - 28] = 1.f;
	    cx[((j + 1) * 6 + 1 << 2) - 28] = u;
	    cx[((j + 1) * 6 + 1 << 2) - 27] = cos(ax);
	    cx[((j + 1) * 6 + 1 << 2) - 26] = sin(ax);
/* L210: */
	    cx[((j + 1) * 6 + 1 << 2) - 25] = u;
	}
/* ***   IF SCURV DEFINTION FAILS, THEN QUIT */
	*irr = 6;
	scurv_(cx, &ir);
	if (ir != 0) {
	    goto L998;
	}

	nloo = (integer) (cx[1] + 1);
/* ---  BM NOW CONTAINS A COONS CANON FORM OF THE UNIT CIRCLE REQUIRED */
/* ---  TO DRIVE A SURFACE OF REVOLUTION -- MOVE ITS TRANSPOSE INTO CC */
	for (l = 1; l <= 4; ++l) {
	    for (j = 1; j <= 4; ++j) {
/* L230: */
		cc[l + (j << 2) - 5] = cx[j + (l + nloo * 6 << 2) - 29];
	    }
	}
	goto L290;
/* --- SPECIAL PROCESSING FOR A CYLINDRICAL SURFACE */
/* --- THE DRIVING CURVE CC SHOULD BE A STRAIGHT LINE */
L250:
/* --- FOR A CYLINDER,THE DIRECTRIX SHOULD EXTEND 10 UNITS ON EACH SIDE */
	for (i__ = 1; i__ <= 3; ++i__) {
	    cc[i__ - 1] = -p[i__ - 1] * xunits_1.ssext;
	    cc[i__ + 3] = p[i__ - 1] * xunits_1.ssext;
	    cc[i__ + 7] = cc[i__ + 3] - cc[i__ - 1];
/* L260: */
	    cc[i__ + 11] = cc[i__ + 7];
	}
	cc[3] = u;
	cc[7] = u;
	cc[11] = z__;
	cc[15] = z__;
L290:
/* -- CC IS A TRANSPOSED COONS CURVE FOR A CIRCLE OR STRT LINE */
/* ---  SETUP THE FOUR LAYER MATRIX TO SWEEP THE CURVE ACROSS THE SECTOR */
	for (j = 1; j <= 4; ++j) {
	    for (k = 1; k <= 4; ++k) {
		for (l = 1; l <= 4; ++l) {
/* L310: */
		    bm[j + (k + (l << 2) << 2) - 21] = z__;
		}
	    }
	}
	if (*icclw == 0) {
	    goto L311;
	}
	bm[0] = u;
	bm[21] = u;
	bm[26] = -u;
	bm[41] = u;
	bm[38] = u;
	bm[63] = u;
	goto L312;
/* --- SET UP BM TO GENERATE A TRANSLATION IN SPACE FOR A CYLINDER */
L311:
	bm[12] = u;
	bm[3] = u;
	bm[29] = u;
	bm[23] = u;
	bm[46] = u;
	bm[43] = u;
	bm[63] = u;
L312:
/* ---  BM=BM*CC */
	for (kz = 1; kz <= 4; ++kz) {
	    k = kz;
	    smmult_(&c__4, &c__4, &c__4, &c__1, &bm[((k << 2) + 1 << 2) - 20],
		     cc, bu);
	    smmult_(&c__4, &c__4, &c__4, &c__2, bt, &bm[((k << 2) + 1 << 2) - 
		    20], bu);
/* L320: */
	}
/* ---  NOW SWEEP EACH CUBIC SEGMENT OF SC THRU THIS SECTOR */
	i__1 = ncm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ncb = (integer) (sc[30] + i__);
	    for (kz = 1; kz <= 4; ++kz) {
		k = kz;
		smmult_(&c__4, &c__4, &c__4, &c__3, &sc[(ncb * 6 + 1 << 2) + 
			1], &bm[((k << 2) + 1 << 2) - 20], &bu[((k << 2) + 1 
			<< 2) - 20]);
/* L410: */
	    }
/* ---  BU MUST NOW BE BACK TRANSFORMED TO BECOME A COONS MATRIX */
	    for (j = 1; j <= 4; ++j) {
		for (k = 1; k <= 4; ++k) {
		    for (l = 1; l <= 4; ++l) {
/* L430: */
			p[l - 1] = bu[j + (k + (l << 2) << 2) - 21];
		    }
		    smmult_(&c__1, &c__4, &c__4, &c__1, p, t, bu);
		    for (l = 1; l <= 4; ++l) {
/* L440: */
			bu[j + (k + (l << 2) << 2) - 21] = p[l - 1];
		    }
/* L420: */
		}
	    }
/* ---  NORMALIZE ALL MATRICES AFTER THE FIRST TO HAVE THE SAME W COORD */
	    if (ii + i__ != 2) {
		goto L460;
	    }
	    wsave = bu[48];
	    goto L480;
/* ------ NORMALIZE THE MATRIX BU WITH WSAVE */
L460:
	    fac = wsave / bu[48];
	    for (l = 1; l <= 4; ++l) {
		for (k = 1; k <= 4; ++k) {
		    for (j = 1; j <= 4; ++j) {
/* L470: */
			bu[l + (k + (j << 2) << 2) - 21] = fac * bu[l + (k + (
				j << 2) << 2) - 21];
		    }
		}
	    }
L480:
/* ---  BU SHOULD NOW BE THE COONS MATRIX, PLACE IT INTO THE S ARRAY */
	    iloc = npch * 6 + 10 + (i__ + (ii - 1) * ncm - 1) * 64.f;
	    for (j = 1; j <= 4; ++j) {
		for (k = 1; k <= 4; ++k) {
		    for (l = 1; l <= 4; ++l) {
			++iloc;
			s[iloc] = bu[l + (k + (j << 2) << 2) - 21];
/* L450: */
		    }
		}
	    }
/* L400: */
	}
/* L200: */
    }
    *irr = 0;
L998:
    return 0;
} /* revolv_ */

