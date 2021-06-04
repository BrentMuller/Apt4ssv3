/* SCPICT.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__32 = 32;
static integer c__36 = 36;
static integer c__16 = 16;
static integer c__28 = 28;
static integer c__3 = 3;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__15 = 15;
static integer c__26 = 26;
static integer c__31 = 31;
static integer c__30 = 30;
static integer c__24 = 24;
static integer c__37 = 37;
static integer c__33 = 33;
static integer c__27 = 27;
static integer c__12 = 12;
static integer c__35 = 35;
static integer c__6 = 6;
static integer c__17 = 17;
static integer c__10 = 10;
static integer c__5 = 5;
static integer c__25 = 25;
static integer c__44 = 44;
static integer c__7 = 7;
static integer c__54 = 54;
static integer c__61 = 61;
static integer c__70 = 70;
static integer c__81 = 81;
static integer c__23 = 23;
static integer c__106 = 106;
static integer c__13 = 13;
static integer c__18 = 18;
static integer c__14 = 14;
static integer c__59 = 59;
static integer c__66 = 66;
static integer c__79 = 79;
static integer c__49 = 49;

/* *** SOURCE FILE : M0004124.V05   *** */

/* Subroutine */ int scpict_(doublereal *sc, char *scname, integer *mode, 
	ftnlen scname_len)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal smal = 1e-9;
    static char typflo[6*2] = "PARAM " "LENGTH";
    static char arctyp[6*5] = "ARC   " "ANGLE " "CHORD " "PARAM " "TRASH ";
    static integer mxarc = 4;
    static char array[120] = "0   PARAM     XCOORD    YCOORD    ZCOORD    UT"
	    "AN-I    UTAN-J    UTAN-K    UNORMI    UNORMJ    UNORMK    CURVAT"
	    "URE RADIUS";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__, j, k, l, n;
    static doublereal r__, u, x;
    static integer j1, j2;
    static doublereal dd;
    static integer ia, ja, jb, ii, kk, ll;
    static doublereal cv[16], rr, tt[3];
    static integer nhd, nhi, ict, nct;
    static doublereal dum;
    static integer nlo;
    static doublereal tol;
    static integer num, nmx;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen), iconv_(integer *, char *, integer *, 
	    integer *, ftnlen), cross_(doublereal *, doublereal *, doublereal 
	    *);
    static integer itype;
    extern /* Subroutine */ int snorm_(doublereal *, doublereal *, integer *),
	     cprin1_(char *, ftnlen);
    static integer locarc, locseg;
    extern /* Subroutine */ int curflo_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), cncurv_(doublereal *, 
	    doublereal *, doublereal *, integer *);
    static integer nsegst;
    extern /* Subroutine */ int vorsch_(integer *, char *, ftnlen);

/* --- INPUT- A SYNTHETIC CURVE S WITH NAME SCNAME */
/* --- OUTPUT - A PRINTED ANALYSIS AND DISPLAY OF THE CURVE S ON VLFILE */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    sc -= 29;

    /* Function Body */
/* ---     ALPHA EQUIVALENT OF SEGMENT FLOW TYPE */


    cform_("1 VERIFICATION LISTING FOR SCURV", darray_1.darray, &c__1, &c__32,
	     (ftnlen)32, (ftnlen)120);
    cform_(scname, darray_1.darray, &c__36, &c__16, (ftnlen)16, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
/* ---     PRINT HEADER TABLE VALUES FOR SYNTHETIC CURVE */
    cform_("0 INTERIM SCURV HEADER TABLE", darray_1.darray, &c__1, &c__28, (
	    ftnlen)28, (ftnlen)120);
    if (*mode > 0) {
	cform_("  FINAL ", darray_1.darray, &c__3, &c__8, (ftnlen)8, (ftnlen)
		120);
    }
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[29], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 1.APT FILE RECORD NUMBER", darray_1.darray, &c__15, &c__26, (
	    ftnlen)26, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[30], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 2.NUMBER OF BLOCKS FOR HEADER", darray_1.darray, &c__15, &c__31,
	     (ftnlen)31, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[31], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 3.1=COMBIN,2=SPLINE,3=CURSEG", darray_1.darray, &c__15, &c__30, 
	    (ftnlen)30, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[32], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 4.NUMBER OF CUBIC ARCS", darray_1.darray, &c__15, &c__24, (
	    ftnlen)24, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
/* ---     SKIP REST OF HEADER FOR MODE 0 */
    if (*mode < 1) {
	goto L11;
    }

    fconv_(&sc[33], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 5.LOCATION OF FIRST CUBIC ARC", darray_1.darray, &c__15, &c__31,
	     (ftnlen)31, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[34], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 6.NUMBER OF ROWS FOR FLOW DATA", darray_1.darray, &c__15, &
	    c__32, (ftnlen)32, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[35], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 7.LOCATION OF FIRST FLOW ROW", darray_1.darray, &c__15, &c__30, 
	    (ftnlen)30, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[36], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 8.NUMBER OF ROWS FOR SEGMENTS", darray_1.darray, &c__15, &c__31,
	     (ftnlen)31, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[37], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("= 9.LOCATION OF FIRST ROW OF SEGMENTS", darray_1.darray, &c__15, &
	    c__37, (ftnlen)37, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[38], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("=10.TOTAL NUMBER OF FLOW SPLINES", darray_1.darray, &c__15, &
	    c__32, (ftnlen)32, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[39], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("=11.LOCATION OF FIRST FLOW SPLINE", darray_1.darray, &c__15, &
	    c__33, (ftnlen)33, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[40], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("=12.TOTAL SIZE OF STRUCTURE", darray_1.darray, &c__15, &c__27, (
	    ftnlen)27, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    fconv_(&sc[41], darray_1.darray, &c__4, &c__9, &c__3, (ftnlen)120);
    cform_("=13.FIRST LOCATION OF STRUCTURE", darray_1.darray, &c__15, &c__31,
	     (ftnlen)31, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
L11:

/* ---     SET UP POINTERS FOR USING CURVE STRUCTURE */
    d__ = .25f;
    n = (integer) (1.f / d__ + 1.1f);
    nhd = (integer) sc[30];
    nlo = nhd + 1;
    nsegst = (integer) sc[32];
    nhi = nlo + nsegst - 1;

    ict = 0;
L13:
    if (*mode < 2) {
	goto L101;
    }
    vorsch_(&c__12, darray_1.darray, (ftnlen)120);
    if (ict == 0) {
	cform_("0CURVE SHAPE- DISPLAYED BY CUBIC ARCS", darray_1.darray, &
		c__1, &c__37, (ftnlen)37, (ftnlen)120);
    }
    if (ict == 1) {
	cform_("0FLOW RATE ACROSS CURVE BY SEGMENTS", darray_1.darray, &c__1, 
		&c__35, (ftnlen)35, (ftnlen)120);
    }
    cprin1_(darray_1.darray, (ftnlen)120);
    s_copy(darray_1.darray, array, (ftnlen)120, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    cform_(" ", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);

    i__1 = nhi;
    for (i__ = nlo; i__ <= i__1; ++i__) {
	kk = i__ - nhd;
	if (ict > 0) {
	    kk = i__ - nlo + 1;
	}
	vorsch_(&c__6, array, (ftnlen)120);
	if (ict == 1) {
	    cform_("0SEGMENT NUMBER", darray_1.darray, &c__1, &c__15, (ftnlen)
		    15, (ftnlen)120);
	}
	if (ict == 0) {
	    cform_("0    ARC NUMBER", darray_1.darray, &c__1, &c__15, (ftnlen)
		    15, (ftnlen)120);
	}
	iconv_(&kk, darray_1.darray, &c__17, &c__6, (ftnlen)120);
	cprin1_(darray_1.darray, (ftnlen)120);

	i__2 = n;
	for (l = 1; l <= i__2; ++l) {
	    u = (l - one) * d__;
	    if (ict == 0) {
		cncurv_(&u, &sc[(i__ * 6 + 1 << 2) + 1], cv, &c__1);
	    }
	    if (ict == 1) {
		curflo_(&u, &sc[29], cv, &c__1, &kk);
	    }
	    cross_(&cv[4], &cv[8], tt);
/* Computing 2nd power */
	    d__1 = tt[0];
/* Computing 2nd power */
	    d__2 = tt[1];
/* Computing 2nd power */
	    d__3 = tt[2];
	    x = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* Computing 2nd power */
	    d__1 = cv[4];
/* Computing 2nd power */
	    d__2 = cv[5];
/* Computing 2nd power */
	    d__3 = cv[6];
	    dd = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) + smal;
/* Computing 3rd power */
	    d__1 = dd;
	    r__ = x / (d__1 * (d__1 * d__1));
	    rr = one / (r__ + smal);
	    snorm_(tt, tt, &ii);
	    k = 1;
	    fconv_(&u, darray_1.darray, &k, &c__10, &c__4, (ftnlen)120);
	    k += 10;
	    for (ll = 1; ll <= 3; ++ll) {
		fconv_(&cv[ll - 1], darray_1.darray, &k, &c__9, &c__4, (
			ftnlen)120);
/* L41: */
		k += 10;
	    }
	    for (ll = 13; ll <= 15; ++ll) {
		fconv_(&cv[ll - 1], darray_1.darray, &k, &c__9, &c__4, (
			ftnlen)120);
/* L42: */
		k += 10;
	    }
	    for (ll = 1; ll <= 3; ++ll) {
		fconv_(&tt[ll - 1], darray_1.darray, &k, &c__9, &c__4, (
			ftnlen)120);
/* L43: */
		k += 10;
	    }
	    fconv_(&r__, darray_1.darray, &k, &c__9, &c__4, (ftnlen)120);
	    k += 10;
	    fconv_(&rr, darray_1.darray, &k, &c__9, &c__3, (ftnlen)120);
	    cprin1_(darray_1.darray, (ftnlen)120);
/* L50: */
	}

	if (sc[34] < smal) {
	    goto L55;
	}
/* ---     LIST SUMMARY FLOW INFORMATION FOR THIS ARC */
	if (ict != 0) {
	    goto L55;
	}

	locarc = (integer) (sc[35] + (kk - 1 << 2));
	k = (locarc - 1) / 24 + 1;
	j = locarc - (k - 1) * 24;
	j = (j - 1) / 4 + 1;
	itype = (integer) sc[(j + k * 6 << 2) + 3];
	if (itype < 1 || itype > mxarc) {
	    itype = mxarc + 1;
	}
	tol = sc[(j + k * 6 << 2) + 3] - itype;
	num = (integer) sc[(j + k * 6 << 2) + 2];
	cform_("FLOW TYPE=", darray_1.darray, &c__5, &c__10, (ftnlen)10, (
		ftnlen)120);
	cform_(arctyp + (itype - 1) * 6, darray_1.darray, &c__17, &c__6, (
		ftnlen)6, (ftnlen)120);
	cform_("TOLERANCE FACTOR=", darray_1.darray, &c__25, &c__17, (ftnlen)
		17, (ftnlen)120);
	fconv_(&tol, darray_1.darray, &c__44, &c__7, &c__4, (ftnlen)120);
	cform_(arctyp + (itype - 1) * 6, darray_1.darray, &c__54, &c__6, (
		ftnlen)6, (ftnlen)120);
	cform_("LENGTH=", darray_1.darray, &c__61, &c__7, (ftnlen)7, (ftnlen)
		120);
	fconv_(&sc[(j + k * 6 << 2) + 4], darray_1.darray, &c__70, &c__9, &
		c__4, (ftnlen)120);
	cform_("NUMBER OF FLOW SPLINES=", darray_1.darray, &c__81, &c__23, (
		ftnlen)23, (ftnlen)120);
	iconv_(&num, darray_1.darray, &c__106, &c__4, (ftnlen)120);
	cprin1_(darray_1.darray, (ftnlen)120);

L55:
	if (ict < 1) {
	    goto L30;
	}
/* ---     PRINT SPECIAL SUMMARY INFORMATION FOR A FLOW SEGMENT */
	locseg = (integer) (sc[37] + (kk - 1 << 2));
	ja = (locseg - 1) / 24 + 1;
	l = locseg - (ja - 1) * 24;
	ia = (l - 1) / 4 + 1;
/* ---     SUMMARY INFORMATION FOR SEGMENT IS IN SC(1,IA,JA) */
	cform_(" FIRST POINT=", darray_1.darray, &c__4, &c__13, (ftnlen)13, (
		ftnlen)120);
	fconv_(&sc[(ia + ja * 6 << 2) + 1], darray_1.darray, &c__18, &c__6, &
		c__1, (ftnlen)120);
	cform_(" LAST POINT=", darray_1.darray, &c__25, &c__12, (ftnlen)12, (
		ftnlen)120);
	dum = sc[(ia + ja * 6 << 2) + 1] + sc[(ia + ja * 6 << 2) + 2];
	fconv_(&dum, darray_1.darray, &c__37, &c__6, &c__1, (ftnlen)120);
	cform_(" TYPE OF FLOW=", darray_1.darray, &c__44, &c__14, (ftnlen)14, 
		(ftnlen)120);
	ii = (integer) sc[(ia + ja * 6 << 2) + 3];
	cform_(typflo + (ii - 1) * 6, darray_1.darray, &c__59, &c__6, (ftnlen)
		6, (ftnlen)120);
	cform_(" TOTAL SPAN=", darray_1.darray, &c__66, &c__12, (ftnlen)12, (
		ftnlen)120);
	fconv_(&sc[(ia + ja * 6 << 2) + 4], darray_1.darray, &c__79, &c__13, &
		c__4, (ftnlen)120);
	cprin1_(darray_1.darray, (ftnlen)120);

L30:
	;
    }

    if (sc[36] < smal) {
	goto L101;
    }
    if (ict >= 1) {
	goto L101;
    }
/* ---     FOR A CURVE WITH FLOW RATE, REDISPLAY ACCORDING TO FLOW. */
    nlo = 1;
    nhi = (integer) sc[36];
    ict = 1;
    goto L13;

L101:
    if (*mode == 0) {
	goto L102;
    }
/* ---     SUPRESS CANON FORM PRINTING IF MODE IS LT 3 */
    if (*mode < 3) {
	goto L111;
    }
/* ---     MODIFY THE EFFECTIVE SIZE FOR A FLOW CURVE */
    nhi = (integer) (sc[40] / 24.f + 1.f);
    nmx = (integer) sc[40];
L102:
    nct = 0;
    if (ict == 0) {
	nhi = (integer) (sc[32] + sc[30]);
    }
    nmx = 5000;
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    vorsch_(&c__3, darray_1.darray, (ftnlen)120);
    cform_(" CANONICAL ARRAY FOLLOWS", darray_1.darray, &c__1, &c__24, (
	    ftnlen)24, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
    j2 = 6;
    i__1 = nhi;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vorsch_(&c__3, darray_1.darray, (ftnlen)120);
	cform_("  INDEX=", darray_1.darray, &c__1, &c__8, (ftnlen)8, (ftnlen)
		120);
	ii = (i__ - 1) * 24 + 1;
	iconv_(&ii, darray_1.darray, &c__9, &c__4, (ftnlen)120);
	jb = 0;
L120:
	ja = jb + 1;
	jb = ja + 2;
	k = 14;
	if (ja > j2) {
	    goto L110;
	}
	if (jb > j2) {
	    jb = j2;
	}
	i__2 = jb;
	for (j1 = ja; j1 <= i__2; ++j1) {
	    k += 3;
	    for (l = 1; l <= 4; ++l) {
		++nct;
		if (nct > nmx) {
		    goto L141;
		}
		fconv_(&sc[l + (j1 + i__ * 6 << 2)], darray_1.darray, &k, &
			c__8, &c__3, (ftnlen)120);
		k += 8;
L141:
		;
	    }
	}
	cprin1_(darray_1.darray, (ftnlen)120);
	goto L120;
L110:
	;
    }
L111:
    if (*mode < 2) {
	goto L150;
    }
/* ---     PRINT END MESSAGE */
    cform_("0---- END OF SYNTHETIC CURVE VERIFICATION -------", 
	    darray_1.darray, &c__1, &c__49, (ftnlen)49, (ftnlen)120);
    cprin1_(darray_1.darray, (ftnlen)120);
L150:
    return 0;
} /* scpict_ */

