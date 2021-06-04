/* SSPLIN.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__21 = 21;
static integer c__3 = 3;
static integer c__13 = 13;

/* *** SOURCE FILE : M0004143.V04   *** */

/* Subroutine */ int ssplin_(doublereal *s, integer *irr)
{
    /* Initialized data */

    static doublereal smal1 = 1e-8;
    static doublereal smal2 = 1e-12;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__[30];
    static integer i__, j, k, l;
    static doublereal p[90]	/* was [3][30] */, t[3], v[90]	/* was [3][30]
	     */, w[30];
    static logical id[93]	/* was [3][31] */;
    static doublereal ta[3], tb[3];
    static integer kk, np;
    static doublereal tv[6]	/* was [3][2] */;
    static integer idc, nhd, nhi;
    static doublereal val;
    static integer nph;
    static doublereal dum;
    static integer nlo, npl, inx;
    static doublereal sum;
    static integer ibeg, ndif;
    static doublereal vala;
    static logical ilim, itan;
    static integer idum;
    static logical icrs;
    static integer iorg, nphm, icur, nrel;
    static logical inor;
    static integer ncur, nplp;
    static logical iwgt;
    static integer irrr, ntot;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), snorm_(doublereal *, doublereal *, integer *), parint_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), smooth_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *);

/* ------ S IS AN INPUT ARRAY CONTAINING ALL POINTS AND CONSTRAINTS */
/* ------ FOR A SPLINE FIT */
/* ------ UPON RETURN S CONTAINS ALL OF THE PROCESSED OUTPUT DATA */
/* ------ IRR IS AN ERROR INDICATOR.  ON  RETURN IRR IS ZERO IF */
/* ------ NO ERRORS OCCURRED DURING PROCESSING WHILE IF AN */
/* ------ ERROR DID OCCUR IRR GIVES THE APPROPRIATE ERROR NUMBER */
/* ------ THE STRUCTURE OF S( IC, IL, IB ) IS AS FOLLOWS */
/* ------ IB IS THE BLOCK OR POINT NUMBER( THE FIRST BLOCK IS A */
/* ------ HEADER) */
/* ------ IL  IS THE LINE NUMBER OF THE BLOCK */
/* ------ IC IS THE COORDINATE NUMBER OF THE LINE */
/* ------ ON INPUT S IS STRUCTURED AS FOLLOWS */
/*      S(1-3,1,2) = X,Y,Z OF THE INPUT POINT */
/*      S(1-4,2,2) = I,J,K OF TANSPL CONSTRAINT AND INDICATOR(0 OR 1) */
/*      S(1-4,3,2) = I,J,K OF CRSSPL CONSTRAINT AND INDICATOR(0 OR 1) */
/*      S(1-4,4,2) = I,J,K OF NORMAL CONSTRAINT AND INDICATOR(0 OR 1) */
/*      S(1,5,2) = WEIGHT FACTOR FOR SMOOTHING */
/*      S(2,5,2) = LIMIT FACTOR TO LIMIT MOVEMENT IN SMOOTHING */
/*      S(1-4,6,2) ,S(4,1,2) AND S(3-4,5,2) ARE NOT INITIATED INPUT */
/* ------ OUTPUT CONTAINS THE FOLLOWING ADDITIONAL INFORMATION */
/*      S(1-3,1,2) = X,Y,Z OF THE SMOOTHED INPUT POINT */
/*      S(4,1,2)   = DISTANCE FROM THIS POINT TO THE NEXT */
/*      S(1-3,2,2) = I,J,K OF UNIT TANGENT VECTOR GENERATED AT THE PT */
/*      S(1,5,2) = WEIGHT WHICH GIVES CERTITUDE(1.0) */
/*      S(2,5,2) = INPUT LIMIT */
/*      S(3,5,2) = ORIGINAL INPUT WEIGHT */
/*      S(4,5,2) =  MEASUREMENT OF WILDNESS RELATIVE TO ADJACENT POINTS */
/*      S(1-3,6,2) = X,Y,Z OF THE ORIGINAL INPUT POINT */
/*      S(4,6,2)   = DISTANCE OF OUTPUT POINT FROM INPUT */
/* ------ THE HEADER CONTAINS THE FOLLOWING INFORMATION */
/*      S(2,1,1) = LENGTH OF THE HEADER TABLE IN BLOCKS(=1) */
/*      S(3,1,1) = ORIGIN OF CALL  SSURF/MESH = 1, SCURV/SPLINE=2 */
/*                 SCURV/CURSEG =3 */
/*      S(4,1,1) = NUMBER OF POINT BLOCKS USED(GE.2) */
/* ------ LOGICAL FLAGS ARE TRUE WHEN NO CONSTRAINT IS PRESENT */
/* ------ ID(1,I) TRUE MEANS THERE IS NO TANSPL CONSTRAINT AT ITH PT */
/* ------ ID(2,I) TRUE MEANS THERE IS NO CRSSPL CONSTRAINT AT ITH PT */
/* ------ ID(3,I) TRUE MEANS THERE IS NO NORMAL CONSTRAINT AT ITH PT */
    /* Parameter adjustments */
    s -= 29;

    /* Function Body */
    np = (integer) s[32];
    iorg = (integer) s[31];
    nhd = (integer) s[30];
    ntot = np + nhd;
    npl = nhd + 1;
    nplp = npl + 1;
    nph = ntot;
    nphm = nph - 1;
/* ------ MOVE INPUT POINTS INTO SIXTH LINE FOR SAVING */
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	s[(i__ * 6 + 6 << 2) + 4] = 0.f;
	for (l = 1; l <= 3; ++l) {
/* L20: */
	    s[l + (i__ * 6 + 6 << 2)] = s[l + (i__ * 6 + 1 << 2)];
	}
/* L30: */
    }
/* ------ THERE SHOULD BE AT LEAST TWO POINTS IN A SPLINE */
    *irr = 5901;
    if (np < 2) {
	goto L998;
    }
/* ------ CHECK FOR IDENTICAL POINTS */
    if (iorg == 3) {
	goto L200;
    }
L10:
    *irr = 5902;
    i__1 = nphm;
    for (i__ = npl; i__ <= i__1; ++i__) {
	inx = i__ + 1;
	sum = 0.f;
	for (l = 1; l <= 3; ++l) {
/* Computing 2nd power */
	    d__1 = s[l + (inx * 6 + 1 << 2)] - s[l + (i__ * 6 + 1 << 2)];
	    sum += d__1 * d__1;
/* L110: */
	}
	if (sum < smal1) {
	    goto L998;
	}
/* L100: */
    }
    goto L300;
L200:
/* ------ CHECK FOR ANY TWO POINTS IDENTICAL IN CURSEG CASE */
    *irr = 5903;
    i__1 = nphm;
    for (i__ = npl; i__ <= i__1; ++i__) {
	inx = i__ + 1;
	i__2 = nph;
	for (j = inx; j <= i__2; ++j) {
	    sum = 0.f;
	    for (l = 1; l <= 3; ++l) {
/* Computing 2nd power */
		d__1 = s[l + (j * 6 + 1 << 2)] - s[l + (i__ * 6 + 1 << 2)];
		sum += d__1 * d__1;
/* L220: */
	    }
	    if (sum < smal1) {
		goto L998;
	    }
/* L210: */
	}
    }
L300:
/* ------ DETERMINE THE PRESENCE OF CONSTRAINTS OF DIFFERENT TYPES */
/* 1----- IF A FLAG IS TRUE THEN THERE IS NO CONSTRAINT OF THIS TYPE */
    inor = TRUE_;
    itan = TRUE_;
    icrs = TRUE_;
    iwgt = TRUE_;
    ilim = TRUE_;
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	for (k = 1; k <= 3; ++k) {
	    kk = k + 1;
	    dum = s[(kk + i__ * 6 << 2) + 4] - 1.f;
	    dum = abs(dum);
	    id[k + i__ * 3 - 4] = TRUE_;
	    if (dum > smal1) {
		goto L340;
	    }
	    id[k + i__ * 3 - 4] = FALSE_;
L340:
	    ;
	}
    }
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	if (! id[i__ * 3 - 3]) {
	    itan = FALSE_;
	}
	if (! id[i__ * 3 - 2]) {
	    icrs = FALSE_;
	}
	if (! id[i__ * 3 - 1]) {
	    inor = FALSE_;
	}
/* ---  CII UPDATE TO INITIALIZE WT AND LIM. NIU-APR/75E */
	if ((d__1 = s[(i__ * 6 + 5 << 2) + 1] - 1.f, abs(d__1)) > smal1) {
	    iwgt = FALSE_;
	}
	if ((d__1 = s[(i__ * 6 + 5 << 2) + 2], abs(d__1)) > smal1) {
	    ilim = FALSE_;
	}
/* L310: */
    }
/* ------ SKIP THE NEXT SECTION IF WEIGHTS ARE NOT EFFECTED */
    if (iwgt) {
	goto L500;
    }
/* ------ WEIGHTS ARE PRESENT, MAKE A SMOOTHING PASS TO OBTAIN NEW */
/* ------ POINT POSITIONS */
/* L400: */
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	for (l = 1; l <= 3; ++l) {
	    for (j = 1; j <= 2; ++j) {
/* L410: */
		tv[l + j * 3 - 4] = 0.f;
	    }
	}
	j = i__ - nhd;
	w[j - 1] = s[(i__ * 6 + 5 << 2) + 1];
	s[(i__ * 6 + 5 << 2) + 3] = w[j - 1];
	for (l = 1; l <= 3; ++l) {
/* L420: */
	    p[l + j * 3 - 4] = s[l + (i__ * 6 + 1 << 2)];
	}
    }
    idc = 5;
    smooth_(p, w, d__, tv, v, &np, &idc);
    *irr = 5904;
    if (idc < 0) {
	goto L998;
    }
/* ------ RELOAD NEW POINTS INTO THE S ARRAY */
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	j = i__ - nhd;
	s[(i__ * 6 + 5 << 2) + 1] = 1.f;
	if (ilim) {
	    goto L450;
	}
/* ------ VAL IS THE DISTANCE BETWEEN THE OLD POINT AND NEW POINT */
/* Computing 2nd power */
	d__1 = p[j * 3 - 3] - s[(i__ * 6 + 1 << 2) + 1];
/* Computing 2nd power */
	d__2 = p[j * 3 - 2] - s[(i__ * 6 + 1 << 2) + 2];
/* Computing 2nd power */
	d__3 = p[j * 3 - 1] - s[(i__ * 6 + 1 << 2) + 3];
	val = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	if (val <= (d__1 = s[(i__ * 6 + 5 << 2) + 2], abs(d__1))) {
	    goto L450;
	}
/* ------ BRING THE POINT BACK INTO THE LIMITED SPHERE AROUND THE OLD */
	val = (d__1 = s[(i__ * 6 + 5 << 2) + 2], abs(d__1)) / val;
	for (l = 1; l <= 3; ++l) {
/* L440: */
	    p[l + j * 3 - 4] = s[l + (i__ * 6 + 1 << 2)] + val * (p[l + j * 3 
		    - 4] - s[l + (i__ * 6 + 1 << 2)]);
	}
	val = (d__1 = s[(i__ * 6 + 5 << 2) + 2], abs(d__1));
L450:
	for (l = 1; l <= 3; ++l) {
	    s[l + (i__ * 6 + 6 << 2)] = s[l + (i__ * 6 + 1 << 2)];
	    s[l + (i__ * 6 + 1 << 2)] = p[l + j * 3 - 4];
/* L460: */
	}
	s[(i__ * 6 + 6 << 2) + 4] = val;
/* L430: */
    }
/* ------ NOW RECYCLE THRU PRIOR LOGIC WITH NEW POINTS AND NO WEIGHTS */
    goto L10;
L500:
    if (inor && icrs && itan) {
	goto L700;
    }
/* ------ CHECK FOR NULL CONSTRAINT VECTORS AND UNITIZE ALL */
    *irr = 5905;
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	for (k = 2; k <= 4; ++k) {
	    if (id[k - 1 + i__ * 3 - 4]) {
		goto L630;
	    }
/* Computing 2nd power */
	    d__1 = s[(k + i__ * 6 << 2) + 1];
/* Computing 2nd power */
	    d__2 = s[(k + i__ * 6 << 2) + 2];
/* Computing 2nd power */
	    d__3 = s[(k + i__ * 6 << 2) + 3];
	    sum = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	    if (sum < smal1) {
		goto L998;
	    }
	    sum = sqrt(sum);
	    for (l = 1; l <= 3; ++l) {
/* L620: */
		s[l + (k + i__ * 6 << 2)] /= sum;
	    }
L630:
	    ;
	}
/* L600: */
    }
L700:
/* ------ REORIENT TANSPL VECTORS BASED ON THE DIRECTION INDICATED BY PTS */
    if (itan) {
	goto L790;
    }
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	if (id[i__ * 3 - 3]) {
	    goto L710;
	}
/* Computing MAX */
	i__1 = i__ - 1;
	nlo = max(i__1,npl);
/* Computing MIN */
	i__1 = i__ + 1;
	nhi = min(i__1,nph);
	sum = 0.f;
	for (l = 1; l <= 3; ++l) {
	    t[l - 1] = s[l + (nhi * 6 + 1 << 2)] - s[l + (nlo * 6 + 1 << 2)];
	    sum += t[l - 1] * s[l + (i__ * 6 + 2 << 2)];
/* L720: */
	}
	if (sum >= 0.f) {
	    goto L710;
	}
/* ------ REORIENT THIS TANGENT CONSTRAINT */
	for (l = 1; l <= 3; ++l) {
/* L730: */
	    s[l + (i__ * 6 + 2 << 2)] = -s[l + (i__ * 6 + 2 << 2)];
	}
L710:
	;
    }
L790:
    *irr = 5909;
/* ------ GENERATE A TANSPL CONSTRAINT WHEREEVER A NORMAL IS PRESENT */
    if (inor) {
	goto L980;
    }
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
/* ------ IF THERE ALREADY IS A TANSPL CONTRAINT OR NO NORMAL, SKIP */
	if (! id[i__ * 3 - 3] || id[i__ * 3 - 1]) {
	    goto L910;
	}
/* Computing MAX */
	i__1 = i__ - 1;
	nlo = max(i__1,npl);
/* Computing MIN */
	i__1 = i__ + 1;
	nhi = min(i__1,nph);
	if (nhi - nlo > 1) {
	    goto L920;
	}
	for (l = 1; l <= 3; ++l) {
/* L930: */
	    t[l - 1] = s[l + (nhi * 6 + 1 << 2)] - s[l + (nlo * 6 + 1 << 2)];
	}
	goto L950;
L920:
	parint_(&s[(nlo * 6 + 1 << 2) + 1], &s[(i__ * 6 + 1 << 2) + 1], &s[(
		nhi * 6 + 1 << 2) + 1], t, &dum, &c__2, &irrr);
	if (irrr != 0) {
	    goto L998;
	}
L950:
	val = t[0] * s[(i__ * 6 + 4 << 2) + 1] + t[1] * s[(i__ * 6 + 4 << 2) 
		+ 2] + t[2] * s[(i__ * 6 + 4 << 2) + 3];
	for (l = 1; l <= 3; ++l) {
/* L960: */
	    t[l - 1] -= val * s[l + (i__ * 6 + 4 << 2)];
	}
	snorm_(t, &s[(i__ * 6 + 2 << 2) + 1], &irrr);
	if (irrr != 0) {
	    goto L998;
	}
	id[i__ * 3 - 3] = FALSE_;
	s[(i__ * 6 + 2 << 2) + 4] = -1.f;
L910:
	;
    }
L980:
    if (iorg == 3) {
	goto L900;
    }
/* END TANGENTS ARE NOT GENERATED IN CURSEG CASE */
/* ------ GENERATE TANGENTS AT THE ENDS */
    *irr = 5909;
    ndif = nph - npl;
    i__2 = nph;
    i__1 = ndif;
    for (i__ = npl; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
	if (! id[i__ * 3 - 3]) {
	    goto L800;
	}
	if (i__ == npl) {
	    goto L830;
	}
	if (i__ == nph) {
	    goto L860;
	}
L830:
	if (np == 2 && ! id[(i__ + 1) * 3 - 3]) {
	    goto L840;
	}
	if (np > 2 && s[((i__ + 1) * 6 + 2 << 2) + 4] == 1.f) {
	    goto L840;
	}
	if (np > 2) {
	    goto L836;
	}
	for (l = 1; l <= 3; ++l) {
/* L835: */
	    t[l - 1] = s[l + ((i__ + 1) * 6 + 1 << 2)] - s[l + (i__ * 6 + 1 <<
		     2)];
	}
	snorm_(t, t, &idum);
	goto L880;
L836:
	parint_(&s[(i__ * 6 + 1 << 2) + 1], &s[((i__ + 1) * 6 + 1 << 2) + 1], 
		&s[((i__ + 2) * 6 + 1 << 2) + 1], t, &dum, &c__1, &irrr);
	goto L880;
L840:
	parint_(&s[(i__ * 6 + 1 << 2) + 1], &s[((i__ + 1) * 6 + 2 << 2) + 1], 
		&s[((i__ + 1) * 6 + 1 << 2) + 1], t, &dum, &c__21, &irrr);
	if (irrr != 0) {
	    goto L998;
	}
	goto L880;
L860:
	if (np == 2 && ! id[(i__ - 1) * 3 - 3]) {
	    goto L870;
	}
	if (np > 2 && s[((i__ - 1) * 6 + 2 << 2) + 4] == 1.f) {
	    goto L870;
	}
	if (np > 2) {
	    goto L866;
	}
	for (l = 1; l <= 3; ++l) {
/* L865: */
	    t[l - 1] = s[l + (i__ * 6 + 1 << 2)] - s[l + ((i__ - 1) * 6 + 1 <<
		     2)];
	}
	snorm_(t, t, &idum);
	goto L880;
L866:
	parint_(&s[((i__ - 2) * 6 + 1 << 2) + 1], &s[((i__ - 1) * 6 + 1 << 2) 
		+ 1], &s[(i__ * 6 + 1 << 2) + 1], t, &dum, &c__3, &irrr);
	goto L880;
L870:
	parint_(&s[((i__ - 1) * 6 + 1 << 2) + 1], &s[((i__ - 1) * 6 + 2 << 2) 
		+ 1], &s[(i__ * 6 + 1 << 2) + 1], t, &dum, &c__13, &irrr);
	if (irrr != 0) {
	    goto L998;
	}
L880:
	for (l = 1; l <= 3; ++l) {
/* L890: */
	    s[l + (i__ * 6 + 2 << 2)] = t[l - 1];
	}
	s[(i__ * 6 + 2 << 2) + 4] = -1.f;
	id[i__ * 3 - 3] = FALSE_;
L800:
	;
    }
/* ------ PROJECT ALL TANSPL AND CRRSPL CONSTRAINTS INTO THE PLANE OF THE */
/* ------ NORMAL CONSTRAINT AND UNITIZE THEM */
L900:
    if (inor) {
	goto L1100;
    }
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	if (id[i__ * 3 - 1]) {
	    goto L1000;
	}
	for (k = 2; k <= 3; ++k) {
	    *irr = k + 5904;
	    if (id[k - 1 + i__ * 3 - 4]) {
		goto L1010;
	    }
	    val = s[(k + i__ * 6 << 2) + 1] * s[(i__ * 6 + 4 << 2) + 1] + s[(
		    k + i__ * 6 << 2) + 2] * s[(i__ * 6 + 4 << 2) + 2] + s[(k 
		    + i__ * 6 << 2) + 3] * s[(i__ * 6 + 4 << 2) + 3];
	    for (l = 1; l <= 3; ++l) {
/* L1015: */
		s[l + (k + i__ * 6 << 2)] -= val * s[l + (i__ * 6 + 4 << 2)];
	    }
	    snorm_(&s[(k + i__ * 6 << 2) + 1], &s[(k + i__ * 6 << 2) + 1], &
		    irrr);
	    if (irrr != 0) {
		goto L998;
	    }
L1010:
	    ;
	}
L1000:
	;
    }
L1100:
/* ------ CHECK FOR THE COLLINEARITY OF CONSTRAINTS */
    if (inor || icrs) {
	goto L1300;
    }
    *irr = 5908;
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	if (id[i__ * 3 - 3] || id[i__ * 3 - 2] || id[i__ * 3 - 1]) {
	    goto L1200;
	}
	cross_(&s[(i__ * 6 + 2 << 2) + 1], &s[(i__ * 6 + 3 << 2) + 1], t);
	val = t[0] * s[(i__ * 6 + 4 << 2) + 1] + t[1] * s[(i__ * 6 + 4 << 2) 
		+ 2] + t[2] * s[(i__ * 6 + 4 << 2) + 3];
	if (abs(val) < smal2) {
	    goto L998;
	}
L1200:
	;
    }
L1300:
/* ------ CHECK FOR WILD POINTS */
    if (np == 2) {
	goto L1500;
    }
    *irr = 5910;
    i__1 = nphm;
    for (i__ = nplp; i__ <= i__1; ++i__) {
	for (l = 1; l <= 3; ++l) {
/* L1410: */
	    t[l - 1] = s[l + ((i__ + 1) * 6 + 1 << 2)] - s[l + ((i__ - 1) * 6 
		    + 1 << 2)];
	}
	for (l = 1; l <= 3; ++l) {
/* L1420: */
	    ta[l - 1] = s[l + (i__ * 6 + 1 << 2)] - s[l + ((i__ - 1) * 6 + 1 
		    << 2)];
	}
	val = t[0] * ta[0] + t[1] * ta[1] + t[2] * ta[2];
	if (val <= 0.f) {
	    goto L998;
	}
	for (l = 1; l <= 3; ++l) {
/* L1430: */
	    tb[l - 1] = s[l + ((i__ + 1) * 6 + 1 << 2)] - s[l + (i__ * 6 + 1 
		    << 2)];
	}
	val = t[0] * tb[0] + t[1] * tb[1] + t[2] * tb[2];
	if (val <= 0.f) {
	    goto L998;
	}
	cross_(t, ta, tb);
	val = tb[0] * tb[0] + tb[1] * tb[1] + tb[2] * tb[2];
	vala = t[0] * t[0] + t[1] * t[1] + t[2] * t[2];
/* ------ WILD POINT MEASURE -- RATIO OF THE HEIGHT TO BASE */
	s[(i__ * 6 + 5 << 2) + 4] = sqrt(val) / vala;
/* L1400: */
    }
L1500:
    s[(npl * 6 + 5 << 2) + 4] = 0.;
    s[(nph * 6 + 5 << 2) + 4] = 0.;
/* ------ BRANCH TO SPLINE OR CURSEG PROCESSING */
    switch (iorg) {
	case 1:  goto L2000;
	case 2:  goto L2000;
	case 3:  goto L3000;
    }
/* ------ COLLECT SUBSPLINES ONE BY ONE AND CONDUCT SMOOTHING */
L2000:
    ibeg = npl;
    icur = npl;
L2010:
    ncur = 1;
    ibeg = icur;
    if (ibeg == ntot) {
	goto L2160;
    }
    for (l = 1; l <= 3; ++l) {
/* L2040: */
	p[l + ncur * 3 - 4] = s[l + (icur * 6 + 1 << 2)];
    }
    w[ncur - 1] = 1.f;
L2020:
    ++ncur;
    ++icur;
    if (! id[icur * 3 - 3]) {
	goto L2100;
    }
    for (l = 1; l <= 3; ++l) {
/* L2030: */
	p[l + ncur * 3 - 4] = s[l + (icur * 6 + 1 << 2)];
    }
    w[ncur - 1] = 1.f;
    goto L2020;
L2100:
    if (ncur == 2) {
	goto L2010;
    }
    for (l = 1; l <= 3; ++l) {
	p[l + ncur * 3 - 4] = s[l + (icur * 6 + 1 << 2)];
	tv[l - 1] = s[l + (ibeg * 6 + 2 << 2)];
/* L2110: */
	tv[l + 2] = s[l + (icur * 6 + 2 << 2)];
    }
    idc = 2;
    w[ncur - 1] = 1.f;
    nrel = icur - ibeg + 1;
    smooth_(p, w, d__, tv, v, &nrel, &idc);
    *irr = abs(idc) + 5920;
    if (idc < 0) {
	goto L998;
    }
    i__1 = icur;
    for (j = ibeg; j <= i__1; ++j) {
	k = j - ibeg + 1;
	s[(j * 6 + 2 << 2) + 4] = 1.f;
	if ((j - ibeg) * (j - icur) != 0) {
	    s[(j * 6 + 2 << 2) + 4] = -1.f;
	}
	id[icur * 3 - 3] = FALSE_;
	for (l = 1; l <= 3; ++l) {
	    s[l + (j * 6 + 1 << 2)] = p[l + k * 3 - 4];
/* L2130: */
	    s[l + (j * 6 + 2 << 2)] = v[l + k * 3 - 4];
	}
	s[(j * 6 + 1 << 2) + 4] = d__[k - 1];
/* L2120: */
    }
    if (icur < ntot) {
	goto L2010;
    }
L2160:
    i__1 = nphm;
    for (i__ = npl; i__ <= i__1; ++i__) {
	j = i__ + 1;
/* Computing 2nd power */
	d__1 = s[(j * 6 + 1 << 2) + 1] - s[(i__ * 6 + 1 << 2) + 1];
/* Computing 2nd power */
	d__2 = s[(j * 6 + 1 << 2) + 2] - s[(i__ * 6 + 1 << 2) + 2];
/* Computing 2nd power */
	d__3 = s[(j * 6 + 1 << 2) + 3] - s[(i__ * 6 + 1 << 2) + 3];
	s[(i__ * 6 + 1 << 2) + 4] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * 
		d__3);
/* L2150: */
    }
    goto L999;
/* ------ CURSEG PROCESSING */
L3000:
L999:
    *irr = 0;
    return 0;
/* ------ ERROR RETURN.  IRR IS NOT ZERO. */
L998:
    s[33] = (doublereal) (*irr);
    return 0;
} /* ssplin_ */

