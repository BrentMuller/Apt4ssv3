/* SSPICT.f -- translated by f2c (version 20100827).
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
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

/* Table of constant values */

static integer c__1 = 1;
static integer c__29 = 29;
static integer c__37 = 37;
static integer c__16 = 16;
static integer c__3 = 3;
static integer c__20 = 20;
static integer c__52 = 52;
static integer c__2 = 2;
static integer c__24 = 24;
static integer c__27 = 27;
static integer c__6 = 6;
static integer c__12 = 12;
static integer c__14 = 14;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__8 = 8;
static integer c__7 = 7;
static integer c__10 = 10;
static integer c__32 = 32;
static integer c__15 = 15;
static integer c__36 = 36;
static integer c__18 = 18;
static integer c__34 = 34;
static integer c__30 = 30;
static integer c__40 = 40;
static integer c__43 = 43;
static integer c__46 = 46;
static integer c__49 = 49;

/* *** SOURCE FILE : M0004128.V08   *** */

/* Subroutine */ int sspict_(doublereal *ss, char *ssname, integer *isprnt, 
	ftnlen ssname_len)
{
    /* Initialized data */

    static char nb[4*8*2] = "PT01" "PT11" "TN01" "TN11" "CR01" "CR11" "TW01" 
	    "TW11" "CR00" "CR50" "CR10" "CR01" "CR51" "CR11" "CR05" "CR15";
    static char nc[4*8] = "NR00" "NR50" "NR10" "NR01" "NR51" "NR11" "NR05" 
	    "NR15";
    static doublereal uz[4] = { 0.,1.,0.,1. };
    static doublereal vz[4] = { 0.,0.,1.,1. };
    static doublereal u[9] = { 0.,.5,1.,0.,.5,1.,0.,1.,.5 };
    static doublereal v[9] = { 0.,0.,0.,1.,1.,1.,.5,.5,.5 };
    static integer ia[8] = { 1,2,3,4,9,10,11,12 };
    static integer ib[8] = { 5,6,7,8,13,14,15,16 };
    static integer iar[12] = { 3,9,4,10,7,13,8,14,11,12,15,16 };
    static integer loc[4] = { 1,3,4,6 };
    static char ib1234[3*4] = "B1=" "B2=" "B3=" "B4=";
    static doublereal zero = 0.;
    static doublereal smal1 = 1e-11;
    static char blank[8] = "        ";
    static char headr1[120] = " PT=SURFACE POINT,TN=FIRST(SPLINE) DIRECTION,"
	    "CS =SECOND(CROSS SPLINE) DIRECTION, NR=SURFACE NORMAL           "
	    "           ";
    static char headr2[120] = " EACH PATCH HAS FOUR CORNERS PT00,PT10,PT01,P"
	    "T11. BOUNDARY B1=PT00-PT10, B2=PT00-PT01, B3=PT10-PT11, B4=PT01-"
	    "PT11       ";
    static char headr3[120] = " NR50,NR05, ETC REPRESENT SURFACE NORMALS AT "
	    "INTERIM PTS. NR05 REPRESENTS A NORMAL AT U=0,V=0.5 MIDWAY BETWEE"
	    "N PT00-PT01";
    static char headr4[120] = " POSITIVE RADII AND CURVATURES ARE CUPPED IN "
	    "THE DIRECTION OF THE SURFACE NORMALS NRI,NRJ,NRK                "
	    "           ";
    static char headr5[120] = " PATCH     X        Y        Z        W      "
	    "          X        Y        Z        W              NRI     NRJ "
	    "    NRK    ";
    static char sshd[24*9] = "VALUE TABLE SIZE        " "TOPOLOGY TABLE SIZE"
	    "     " "NUMBER OF PATCHES       " "SURFACE TYPE(MESH=2)    " 
	    "PNTVEC,POLYGN,PNTSON    " "SIGN OF NORMAL(TN X CR) " "TOTAL SIZ"
	    "E OF SURF      " "NUMBER OF SPLINES       " "NUMBER OF CROSS SPL"
	    "INES ";
    static char na[4*8*2] = "PT00" "PT10" "TN00" "TN10" "CR00" "CR10" "TW00" 
	    "TW10" "PT00" "PT50" "PT10" "PT01" "PT51" "PT11" "PT05" "PT15";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a, b[64], c__, d__, e;
    static integer i__, j, k, l, m;
    static doublereal w;
    static integer i8;
    static doublereal a11, a12, a22, ca, cb, dd, g11;
    static integer ic;
    static doublereal g12;
    static integer ma, ii, mc, jj, mb, kk, im, ll, il, mm, lk, lj, mp[4], np, 
	    iv, ms[4], ns, iw, iy;
    static doublereal pt[12]	/* was [3][4] */, sq, wp;
    static integer iz;
    static doublereal sv[32], pz[6]	/* was [3][2] */;
    static integer jl;
    static doublereal g22, hm, gk, ra, rb;
    static integer ln, iic, llc, iil, kkk, iip, imm, lll, nct;
    static doublereal dot;
    static integer mmp, niu;
    static doublereal snm[3], snt[12]	/* was [3][4] */, cbig, area;
    static integer mdif;
    static doublereal cmin, pare[9], cmax;
    static integer lloc;
    static doublereal smal, dsnm, rmin, rmax;
    static integer inun, itop[24]	/* was [6][4] */, ntot, ntyp, iflag[4]
	    ;
    static doublereal parea;
    static integer ibrel;
    static doublereal csmal;
    static integer icmin, icmax;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer icomp, nmesh;
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer ncomp;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer nqmax, mcurr, ncurr, inunq;
    extern /* Subroutine */ int cprin1_(char *, ftnlen);
#define iiscan ((integer *)&sspad_1 + 2)
    static integer igencr;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);
    static integer icompc;
    static char darray[120];
    static integer ipmesh, ncompm, isnmes;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *), vorsch_(
	    integer *, char *, ftnlen);
    static integer nptmax;

/* ------ THIS ROUTINE GENERATES A VERIFICATION LISTING REPORT FOR A */
/* ------ SCULPTURED SURFACE CANONICAL ARRAY */
/* ------ IN ADDITION THE ROUTINE CONDUCTS AVERAGING FOR PNTSON CASE */


/* ------ SETUP VARIABLES TO SAVE MESH POINTS DURING DEFINITION */
/* ---     NSCNMX IS THE MAXIMUM SPACE AVAILABLE IN SCAN */
/* ---     ISCAN IS THE LAST USED LOCATION IN SCAN */
/* ---     SCAN IS A SCRATCH PAD WORK AREA FOR SS CALCULATIONS */
/* ---     ARRAY IISCAN IS USED  TO STORE INTEGERS IN SCAN */

/* .... SCULPTURED SURFACES SCRATCH PAD AREA */




/* ---     ASSUMPTION ONE INTEGER IS ONE HALF THE LENGTH OF A REAL. */

    /* Parameter adjustments */
    --ss;

    /* Function Body */


    ntot = (integer) ss[4];
    np = (integer) ss[10];
    ns = (integer) ss[9];
    nmesh = (integer) ss[5];
    ntyp = (integer) ss[6];
    cmax = -1e5;
    cmin = 1e5;
    if (nmesh != 2) {
	ss[9] = 0.f;
    }
    if (nmesh != 2) {
	ss[10] = 0.f;
    }
/* ------ AT THIS POINT PATCH AVERAGING IS DONE FOR THE */
/* ------ POINTS ON CASE */
/* ---     COMPUTE LOCATIONS FOR DATA STORAGE IN SCAN */
/* ---     ALSO DETERMINE WHETHER SCAN HAS ENOUGH ROOM */
/* ---     IF THE DATA IS TOO VOLUMINOUS THE DISPLAY IS SKIPPED */
    nptmax = (integer) (ss[4] * 4.f);
    if (nmesh == 2) {
	nptmax = np * ns;
    }
    ++nptmax;
/* ---     INDEX TO CORNER POINT STORAGE */
    ipmesh = 0;
/* ---     INDEX TO SCAN FOR CORNER SURFACE NORMALS */
    isnmes = nptmax * 3 - 1;
/* ---     AREAS FOR STORAGE OF INTEGER ARRAYS */
    inun = nptmax * 12 - 1;
    inunq = inun + nptmax;
    icomp = inunq + nptmax;

    nqmax = nptmax * 15 / 2 + 2;
    if (nqmax <= sspad_1.nscnmx) {
	goto L773;
    }
/* ****    NOT ENOUGH SPACE FOR SSPICT CALCULATION.  BYPASS. */
    cform_("0 NOT ENOUGH SPACE TO DISPLAY ", darray, &c__1, &c__29, (ftnlen)
	    30, (ftnlen)120);
    cform_(ssname, darray, &c__37, &c__16, (ftnlen)16, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    goto L130;
L773:
    if (nmesh != 1 || ntyp != 3) {
	goto L1000;
    }
/* ------ COMMENCE PATCH AVERAGING BY CONSTRUCTING A TABLE OF */
/* ------ CORNER POINTS AND CORNER NORMALS */
    nct = 0;
    i__1 = ntot;
    for (i__ = 1; i__ <= i__1; ++i__) {
	lodpch_(&ss[1], b, iflag, itop, &i__, &c__3);
	for (l = 1; l <= 4; ++l) {
	    cnsurf_(&uz[l - 1], &vz[l - 1], b, sv, iflag, &c__1);
	    ++nct;
	    for (k = 1; k <= 3; ++k) {
		sspad_1.scan[ipmesh + nct * 3 - 3 + k - 1] = sv[k - 1];
		sspad_1.scan[isnmes + nct * 3 - 3 + k - 1] = sv[k + 27];
/* L1020: */
	    }
/* L1010: */
	}
    }
    ncomp = ntot << 2;
    i__1 = ncomp;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1030: */
	iiscan[icomp + i__ - 1] = i__;
    }
/* ------ SEARCH THRU THE TABLE OF POINTS TO FIND EQUALS */
/* ------ IF A LATER POINT EQUALS AN EARLIER, THEN REFERENCE */
/* ------ THE EARLIER POINT IN ICOMP */
    icompc = 0;
    ncompm = ncomp - 1;
/* ------ ICOMPC KEEPS TRACK OF THE TOTAL NUMBER OF UNIQUE POINTS */
    i__1 = ncompm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (iiscan[icomp + i__ - 1] != i__) {
	    goto L1040;
	}
	j = i__ + 1;
	i__2 = ncomp;
	for (k = j; k <= i__2; ++k) {
	    ii = ipmesh + i__ * 3 - 3;
	    kk = ipmesh + k * 3 - 3;
/* Computing 2nd power */
	    d__1 = sspad_1.scan[ii] - sspad_1.scan[kk];
/* Computing 2nd power */
	    d__2 = sspad_1.scan[ii + 1] - sspad_1.scan[kk + 1];
/* Computing 2nd power */
	    d__3 = sspad_1.scan[ii + 2] - sspad_1.scan[kk + 2];
	    d__ = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	    if (d__ < smal1) {
		iiscan[icomp + k - 1] = i__;
	    }
/* L1050: */
	}
	++icompc;
	iiscan[inun + icompc - 1] = i__;
/* ------ICOMPC CONTAINS THE NUMBER OF UNIQUE POINTS AND IISCAN(INUN+) */
/* ------ CONTAINS THE FIRST POINT IN EACH UNIQUE STRING. */
L1040:
	;
    }
    i__1 = icompc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = iiscan[inun + i__ - 1];
	nct = 0;
	for (k = 1; k <= 3; ++k) {
/* L1065: */
	    snm[k - 1] = 0.f;
	}
	i__2 = ncomp;
	for (k = j; k <= i__2; ++k) {
	    if (iiscan[icomp + k - 1] != j) {
		goto L1070;
	    }
	    jj = isnmes + j * 3 - 3;
	    kk = isnmes + k * 3 - 3;
	    w = sspad_1.scan[jj] * sspad_1.scan[kk] + sspad_1.scan[jj + 1] * 
		    sspad_1.scan[kk + 1] + sspad_1.scan[jj + 2] * 
		    sspad_1.scan[kk + 2];
	    sq = 1.f;
	    if (w < 0.) {
		sq = -1.f;
	    }
	    for (l = 1; l <= 3; ++l) {
/* L1080: */
		snm[l - 1] += sq * sspad_1.scan[isnmes + k * 3 - 3 + l - 1];
	    }
	    ++nct;
	    iiscan[inunq + nct - 1] = k;
L1070:
	    ;
	}
	dsnm = 0.f;
	for (k = 1; k <= 3; ++k) {
	    snm[k - 1] /= nct;
/* Computing 2nd power */
	    d__1 = snm[k - 1];
	    dsnm += d__1 * d__1;
/* L1090: */
	}
	dsnm = sqrt(dsnm);
	for (l = 1; l <= 3; ++l) {
/* L1100: */
	    snm[l - 1] /= dsnm;
	}
/* ------SNM IS AN AVERAGED SURFACE NORMAL AT THE CURRENT UNIQUE PT */
/* ------ REPLACE EACH NORMAL VECTOR IN THE LIST WITH ITS CORRES- */
/* ------ PONDING AVERAGED NORMAL. */
	i__2 = nct;
	for (l = 1; l <= i__2; ++l) {
	    for (k = 1; k <= 3; ++k) {
		m = iiscan[inunq + l - 1];
		sspad_1.scan[isnmes + m * 3 - 3 + k - 1] = snm[k - 1];
/* L1110: */
	    }
	}
/* L1060: */
    }
/* ------ FINALLY ALTER THE TANGENTS AND ZERO THE TWISTS */
    i__1 = ntot;
    for (l = 1; l <= i__1; ++l) {
	for (k = 1; k <= 4; ++k) {
	    ic = k + (l - 1 << 2);
	    ibrel = (l - 1) * 6 + 15;
	    ibrel = (integer) (ss[ibrel] - 1.f);
	    for (m = 1; m <= 2; ++m) {
		mc = (k - 1 << 1) + m;
		iv = ibrel + iar[mc - 1];
		iic = isnmes + ic * 3 - 3;
		dot = ss[iv] * sspad_1.scan[iic] + ss[iv + 16] * sspad_1.scan[
			iic + 1] + ss[iv + 32] * sspad_1.scan[iic + 2];
		for (ll = 1; ll <= 3; ++ll) {
/* L1140: */
		    ss[iv + (ll << 4) - 16] -= dot * sspad_1.scan[isnmes + ic 
			    * 3 - 3 + ll - 1];
		}
/* L1130: */
	    }
/* ------ ZERO OUT TWIST VECTORS */
	    for (m = 9; m <= 12; ++m) {
		iv = iar[m - 1] + ibrel;
		for (ll = 1; ll <= 3; ++ll) {
		    ss[iv + (ll << 4) - 16] = zero;
/* L1150: */
		}
	    }
/* L1120: */
	}
    }
L1000:
/* ------ THE PNTSON  SURFACE HAS NOW BEEN AVERAGED */

    for (i__ = 1; i__ <= 15; ++i__) {
	i8 = i__ << 3;
/* L3000: */
	i__1 = i8 - 8;
	s_copy(darray + i__1, blank, i8 - i__1, (ftnlen)8);
    }
    cform_("1", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_(" SCULPTURED SURFACE ", darray, &c__20, &c__20, (ftnlen)20, (
	    ftnlen)120);
    cform_(ssname, darray, &c__52, &c__16, (ftnlen)16, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    if (*isprnt == 2) {
	goto L3020;
    }
    s_copy(darray, headr1, (ftnlen)120, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    s_copy(darray, headr2, (ftnlen)120, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    s_copy(darray, headr3, (ftnlen)120, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    s_copy(darray, headr4, (ftnlen)120, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
L3020:
    cform_("0SS HEADER TABLE", darray, &c__1, &c__16, (ftnlen)16, (ftnlen)120)
	    ;
    cprin1_(darray, (ftnlen)120);
/* ---     WRITE OUT SS HEADER INFORMATION */
    for (j = 1; j <= 9; ++j) {
	cform_(sshd + (j - 1) * 24, darray, &c__2, &c__24, (ftnlen)24, (
		ftnlen)120);
	niu = (integer) ss[j + 1];
	iconv_(&niu, darray, &c__27, &c__6, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);
/* L3008: */
    }

    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    if (*isprnt == 2) {
	goto L3121;
    }
    s_copy(darray, headr5, (ftnlen)120, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);

L3121:
    area = 0.f;
    i__1 = ntot;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*isprnt == 2) {
	    goto L3021;
	}
	vorsch_(&c__12, headr5, (ftnlen)120);
	cform_(" PATCH NUMBER ", darray, &c__1, &c__14, (ftnlen)14, (ftnlen)
		120);
	iconv_(&i__, darray, &c__16, &c__5, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);
L3021:
	lodpch_(&ss[1], b, iflag, itop, &i__, &c__3);
	for (l = 1; l <= 8; ++l) {
	    cnsurf_(&u[l - 1], &v[l - 1], b, sv, iflag, &c__1);
/* Computing 2nd power */
	    d__1 = sv[24];
/* Computing 2nd power */
	    d__2 = sv[25];
/* Computing 2nd power */
	    d__3 = sv[26];
	    d__ = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    pare[l - 1] = d__;
	    ma = ia[l - 1];
	    mb = ib[l - 1];
/* --- COMPUTE THE EUCLIDEAN X,Y,Z COORDINATES FOR DISPLAY */
	    mdif = mb - ma;
/* ---     SET INDEX TO NA TO NON-GENCUR TYPE */
	    igencr = 1;
/* ---     SPECIAL TEMPORARY PATH FOR GENCUR SURFACE */
	    if (iflag[0] < 9) {
		goto L47;
	    }
/* ---     SET INDEX TO NA TO GENCUR TYPE */
	    igencr = 2;

	    for (iil = 1; iil <= 3; ++iil) {
		pz[iil - 1] = sv[iil - 1];
		pz[iil + 2] = sv[iil + 7];
/* L46: */
	    }
	    goto L61;
L47:
	    if (l < 3) {
		goto L41;
	    }
	    if (l < 7) {
		goto L51;
	    }
/* --- LEAVE TWIST VECTORS AS IS */
	    for (im = 1; im <= 2; ++im) {
		mm = ma + mdif * (im - 1);
		for (il = 1; il <= 3; ++il) {
/* L62: */
		    pz[il + im * 3 - 4] = b[mm + (il << 4) - 17];
		}
	    }
	    goto L61;
/* --- DIVIDE X,Y, AND Z COORDINATES BY W */
L41:
	    for (im = 1; im <= 2; ++im) {
		mm = ma + mdif * (im - 1);
		w = b[mm + 47] + smal1;
		for (il = 1; il <= 3; ++il) {
/* L42: */
		    pz[il + im * 3 - 4] = b[mm + (il << 4) - 17] / w;
		}
	    }
	    goto L61;
L51:
/* --- DERIVATIVES ARE MODIFIED BY (DX*W-DW*X)/W**2 */
	    for (im = 1; im <= 2; ++im) {
		mm = ma + mdif * (im - 1);
		mmp = (l + 1) % 2 + 1 + (im - 1 << 2);
		w = b[mmp + 47];
		wp = b[mm + 47];
		for (il = 1; il <= 3; ++il) {
/* Computing 2nd power */
		    d__1 = w + smal1;
		    pz[il + im * 3 - 4] = (w * b[mm + (il << 4) - 17] - wp * 
			    b[mmp + (il << 4) - 17]) / (d__1 * d__1);
/* L52: */
		}
	    }
L61:
	    if (*isprnt == 2) {
		goto L3022;
	    }

	    cform_(na + (l + (igencr << 3) - 9 << 2), darray, &c__2, &c__4, (
		    ftnlen)4, (ftnlen)120);
	    k = 7;
	    for (iw = 1; iw <= 3; ++iw) {
		fconv_(&pz[iw - 1], darray, &k, &c__9, &c__3, (ftnlen)120);
		k += 9;
/* L3031: */
	    }
	    fconv_(&b[ma + 47], darray, &k, &c__9, &c__3, (ftnlen)120);
	    k += 12;
	    cform_(nb + (l + (igencr << 3) - 9 << 2), darray, &k, &c__4, (
		    ftnlen)4, (ftnlen)120);
	    k += 5;
	    for (iy = 1; iy <= 3; ++iy) {
		fconv_(&pz[iy + 2], darray, &k, &c__9, &c__3, (ftnlen)120);
		k += 9;
/* L3032: */
	    }
	    fconv_(&b[mb + 47], darray, &k, &c__9, &c__3, (ftnlen)120);
	    k += 12;
	    cform_(nc + (l - 1 << 2), darray, &k, &c__4, (ftnlen)4, (ftnlen)
		    120);
	    k += 6;
	    for (iz = 29; iz <= 31; ++iz) {
		fconv_(&sv[iz - 1], darray, &k, &c__8, &c__5, (ftnlen)120);
		k += 8;
/* L3033: */
	    }
	    cprin1_(darray, (ftnlen)120);

/* ------SAVE CORNER POINTS AND NORMALS AS THEY ARE GENERATED */
L3022:
	    if (nmesh != 2) {
		goto L330;
	    }
	    for (lloc = 1; lloc <= 4; ++lloc) {
		llc = loc[lloc - 1];
		if (llc != l) {
		    goto L310;
		}
/* ------ CASE L HAS GENERATED THE LLOC TH CORNER.  SAVE POINT AND NORMAL */
		for (lk = 1; lk <= 3; ++lk) {
		    pt[lk + lloc * 3 - 4] = sv[lk - 1];
		    snt[lk + lloc * 3 - 4] = sv[lk + 27];
/* L320: */
		}
L310:
		;
	    }
L330:
/* L80: */
	    ;
	}
	cnsurf_(&u[8], &v[8], b, sv, iflag, &c__1);

	if (*isprnt == 2) {
	    goto L3023;
	}
	if (igencr != 2) {
	    goto L3045;
	}
/*    GENCUR-OBERFLAECHE HAT KEINE RELEVANTEN FLAGS */
	k = 8;
	goto L3046;
L3045:
	cform_(" FLAGS=", darray, &c__1, &c__7, (ftnlen)7, (ftnlen)120);
	k = 8;
	for (jj = 1; jj <= 4; ++jj) {
	    iconv_(&iflag[jj - 1], darray, &k, &c__1, (ftnlen)120);
	    ++k;
	    cform_(",", darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
	    ++k;
/* L3040: */
	}
L3046:
	++k;
	for (ll = 1; ll <= 4; ++ll) {
	    cform_(ib1234 + (ll - 1) * 3, darray, &k, &c__3, (ftnlen)3, (
		    ftnlen)120);
	    k += 3;
	    iconv_(&itop[ll * 6 - 5], darray, &k, &c__3, (ftnlen)120);
	    k += 4;
/* L3041: */
	}
	cform_(" PT55 ", darray, &k, &c__6, (ftnlen)6, (ftnlen)120);
	k += 6;
	for (lj = 1; lj <= 3; ++lj) {
	    fconv_(&sv[lj - 1], darray, &k, &c__9, &c__3, (ftnlen)120);
/* L3042: */
	    k += 12;
	}
	cform_("NR55 ", darray, &k, &c__5, (ftnlen)5, (ftnlen)120);
	k += 5;
	for (jl = 29; jl <= 31; ++jl) {
	    fconv_(&sv[jl - 1], darray, &k, &c__8, &c__4, (ftnlen)120);
/* L3043: */
	    k += 8;
	}
	cprin1_(darray, (ftnlen)120);

L3023:
/* Computing 2nd power */
	d__1 = sv[24];
/* Computing 2nd power */
	d__2 = sv[25];
/* Computing 2nd power */
	d__3 = sv[26];
	d__ = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	pare[l - 1] = d__;
	parea = (pare[0] + pare[2] + pare[3] + pare[5] + (pare[1] + pare[4] + 
		pare[6] + pare[7]) * 2.f + pare[8] * 4.f) / 16.f;
/* Computing 2nd power */
	d__1 = sv[4];
/* Computing 2nd power */
	d__2 = sv[5];
/* Computing 2nd power */
	d__3 = sv[6];
	g11 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	g12 = sv[4] * sv[8] + sv[5] * sv[9] + sv[6] * sv[10];
/* Computing 2nd power */
	d__1 = sv[8];
/* Computing 2nd power */
	d__2 = sv[9];
/* Computing 2nd power */
	d__3 = sv[10];
	g22 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	a11 = sv[12] * sv[28] + sv[13] * sv[29] + sv[14] * sv[30];
	a12 = sv[16] * sv[28] + sv[17] * sv[29] + sv[18] * sv[30];
	a22 = sv[20] * sv[28] + sv[21] * sv[29] + sv[22] * sv[30];
	c__ = a11 * a22 - a12 * a12;
	e = -g11 * a22 + g12 * 2.f * a12 - g22 * a11;
	a = g11 * g22 - g12 * g12;
	dd = e * e - a * 4.f * c__;
	if (dd < zero) {
	    goto L170;
	}
	dd = sqrt(dd);
	ca = (-e + dd) / (a + a);
	cb = (-e - dd) / (a + a);
	hm = (ca + cb) / 2.;
	gk = ca * cb;
	smal = 1e-5;
	ra = 1.f / (ca + smal);
	rb = 1.f / (cb + smal);
/* ------ SAVE THE CRITICAL CURVATURES */
	cbig = ca;
	csmal = ca;
	if (cbig < cb) {
	    cbig = cb;
	}
	if (csmal > cb) {
	    csmal = cb;
	}
	if (cbig < cmax) {
	    goto L210;
	}
	cmax = cbig;
	icmax = i__;
L210:
	if (csmal > cmin) {
	    goto L220;
	}
	cmin = csmal;
	icmin = i__;
L220:

	if (*isprnt == 2) {
	    goto L170;
	}
	cform_(" PATCH AREA=", darray, &c__1, &c__12, (ftnlen)12, (ftnlen)120)
		;
	k = 13;
	fconv_(&parea, darray, &k, &c__12, &c__5, (ftnlen)120);
	k += 12;
	cform_(" CURVATURES=", darray, &k, &c__12, (ftnlen)12, (ftnlen)120);
	k += 12;
	fconv_(&ca, darray, &k, &c__10, &c__4, (ftnlen)120);
	k += 10;
	fconv_(&cb, darray, &k, &c__10, &c__4, (ftnlen)120);
	k += 10;
	cform_(" MEAN & GAUSS=", darray, &k, &c__14, (ftnlen)14, (ftnlen)120);
	k += 14;
	fconv_(&hm, darray, &k, &c__10, &c__4, (ftnlen)120);
	k += 10;
	fconv_(&gk, darray, &k, &c__10, &c__4, (ftnlen)120);
	k += 10;
	cform_(" RADII=", darray, &k, &c__7, (ftnlen)7, (ftnlen)120);
	k += 7;
	fconv_(&ra, darray, &k, &c__12, &c__3, (ftnlen)120);
	k += 12;
	fconv_(&rb, darray, &k, &c__10, &c__3, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);

L170:
	if (nmesh != 2) {
	    goto L350;
	}
/* ------ PACK THE FOUR CORNER POINTS AND NORMALS INTO THE MESH ARRAY */
/* ------ MP IS THE POINT LOCATION ON A SPLINE */
/* ------ MS IS THE SPLINE NUMBER */
	mp[0] = (i__ - 1) % (np - 1) + 1;
	ms[0] = (i__ - 1) / (np - 1) + 1;
	mp[1] = mp[0] + 1;
	ms[1] = ms[0];
	mp[2] = mp[0];
	ms[2] = ms[0] + 1;
	mp[3] = mp[0] + 1;
	ms[3] = ms[2];
	for (kk = 1; kk <= 4; ++kk) {
	    ncurr = (ms[kk - 1] - 1) * np + mp[kk - 1];
	    for (kkk = 1; kkk <= 3; ++kkk) {
		sspad_1.scan[ipmesh + ncurr * 3 - 3 + kkk - 1] = pt[kkk + kk *
			 3 - 4];
		sspad_1.scan[isnmes + ncurr * 3 - 3 + kkk - 1] = snt[kkk + kk 
			* 3 - 4];
/* L380: */
	    }
	}
L350:
	area += parea;
/* L90: */
    }

    vorsch_(&c__7, darray, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_(" APPROXIMATE TOTAL SURFACE AREA=", darray, &c__1, &c__32, (ftnlen)
	    32, (ftnlen)120);
    k = 35;
    fconv_(&area, darray, &k, &c__15, &c__6, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);

    rmax = 1.f / (cmax + smal);
    rmin = 1.f / (cmin + smal);


    cform_("0  CRITICAL CURVATURES ON THE SURFACE", darray, &c__1, &c__37, (
	    ftnlen)37, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("MAXIMUM SIGNED CURVATURE AND RADIUS=", darray, &c__10, &c__36, (
	    ftnlen)36, (ftnlen)120);
    k = 46;
    fconv_(&cmax, darray, &k, &c__15, &c__5, (ftnlen)120);
    k += 17;
    fconv_(&rmax, darray, &k, &c__15, &c__5, (ftnlen)120);
    k += 15;
    cform_("   AT PATCH NUMBER", darray, &k, &c__18, (ftnlen)18, (ftnlen)120);
    k += 18;
    iconv_(&icmax, darray, &k, &c__5, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("MINIMUM SIGNED CURVATURE AND RADIUS=", darray, &c__10, &c__36, (
	    ftnlen)36, (ftnlen)120);
    k = 46;
    fconv_(&cmin, darray, &k, &c__15, &c__5, (ftnlen)120);
    k += 17;
    fconv_(&rmin, darray, &k, &c__15, &c__5, (ftnlen)120);
    k += 15;
    cform_("   AT PATCH NUMBER", darray, &k, &c__18, (ftnlen)18, (ftnlen)120);
    k += 18;
    iconv_(&icmin, darray, &k, &c__5, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);


    if (nmesh != 2) {
	goto L480;
    }
    vorsch_(&c__15, darray, (ftnlen)120);
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("MESH PATTERN OF POINTS AND NORMALS", darray, &c__10, &c__34, (
	    ftnlen)34, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);
    cform_("0  POINT", darray, &c__1, &c__8, (ftnlen)8, (ftnlen)120);
    k = 17;
    cform_("X", darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
    k += 13;
    cform_("Y", darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
    k += 13;
    cform_("Z", darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
    k += 26;
    cform_("SNI", darray, &k, &c__3, (ftnlen)3, (ftnlen)120);
    k += 13;
    cform_("SNJ", darray, &k, &c__3, (ftnlen)3, (ftnlen)120);
    k += 13;
    cform_("SNK", darray, &k, &c__3, (ftnlen)3, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);

    i__1 = ns;
    for (imm = 1; imm <= i__1; ++imm) {

	vorsch_(&c__5, darray, (ftnlen)120);
	cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
	cform_("SPLINE NUMBER=", darray, &c__15, &c__14, (ftnlen)14, (ftnlen)
		120);
	iconv_(&imm, darray, &c__30, &c__6, (ftnlen)120);
	cform_("(V=....)", darray, &c__40, &c__8, (ftnlen)8, (ftnlen)120);
	i__2 = imm - 1;
	iconv_(&i__2, darray, &c__43, &c__4, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);

	i__2 = np;
	for (iip = 1; iip <= i__2; ++iip) {
	    ncurr = (imm - 1) * np + iip;

	    vorsch_(&c__1, darray, (ftnlen)120);
	    iconv_(&iip, darray, &c__4, &c__4, (ftnlen)120);
	    cform_("*", darray, &c__8, &c__1, (ftnlen)1, (ftnlen)120);
	    k = 12;
	    for (lll = 1; lll <= 3; ++lll) {
		fconv_(&sspad_1.scan[ipmesh + ncurr * 3 - 3 + lll - 1], 
			darray, &k, &c__12, &c__5, (ftnlen)120);
		i__3 = k + 12;
		cform_(",", darray, &i__3, &c__1, (ftnlen)1, (ftnlen)120);
		k += 13;
/* L3050: */
	    }
	    k += 10;
	    for (ln = 1; ln <= 3; ++ln) {
		fconv_(&sspad_1.scan[isnmes + ncurr * 3 - 3 + ln - 1], darray,
			 &k, &c__12, &c__5, (ftnlen)120);
		if (ln < 3) {
		    i__3 = k + 12;
		    cform_(",", darray, &i__3, &c__1, (ftnlen)1, (ftnlen)120);
		}
		k += 13;
/* L3051: */
	    }
	    i__3 = k + 6;
	    cform_("(U=....)", darray, &i__3, &c__8, (ftnlen)8, (ftnlen)120);
	    i__3 = iip - 1;
	    i__4 = k + 9;
	    iconv_(&i__3, darray, &i__4, &c__4, (ftnlen)120);
	    cprin1_(darray, (ftnlen)120);

/* L440: */
	}
    }

/*        PRINT OUT CROSS SPLINE INFORMATION */

    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprin1_(darray, (ftnlen)120);

    i__2 = np;
    for (iip = 1; iip <= i__2; ++iip) {
	vorsch_(&c__5, darray, (ftnlen)120);
	cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
	cform_("CROSS SPLINE NUMBER=", darray, &c__15, &c__20, (ftnlen)20, (
		ftnlen)120);
	iconv_(&iip, darray, &c__36, &c__6, (ftnlen)120);
	cform_("(U=....)", darray, &c__46, &c__8, (ftnlen)8, (ftnlen)120);
	i__1 = iip - 1;
	iconv_(&i__1, darray, &c__49, &c__4, (ftnlen)120);
	cprin1_(darray, (ftnlen)120);

	i__1 = ns;
	for (imm = 1; imm <= i__1; ++imm) {
	    mcurr = imm * np - (np - iip);
	    vorsch_(&c__1, darray, (ftnlen)120);
	    iconv_(&imm, darray, &c__4, &c__4, (ftnlen)120);
	    cform_("*", darray, &c__8, &c__1, (ftnlen)1, (ftnlen)120);
	    k = 12;
	    for (lll = 1; lll <= 3; ++lll) {
		fconv_(&sspad_1.scan[ipmesh + mcurr * 3 - 3 + lll - 1], 
			darray, &k, &c__12, &c__5, (ftnlen)120);
		i__3 = k + 12;
		cform_(",", darray, &i__3, &c__1, (ftnlen)1, (ftnlen)120);
		k += 13;
/* L460: */
	    }
	    k += 10;
	    for (ln = 1; ln <= 3; ++ln) {
		fconv_(&sspad_1.scan[isnmes + mcurr * 3 - 3 + ln - 1], darray,
			 &k, &c__12, &c__5, (ftnlen)120);
		if (ln < 3) {
		    i__3 = k + 12;
		    cform_(",", darray, &i__3, &c__1, (ftnlen)1, (ftnlen)120);
		}
		k += 13;
/* L470: */
	    }
	    i__3 = k + 6;
	    cform_("(V=....)", darray, &i__3, &c__8, (ftnlen)8, (ftnlen)120);
	    i__3 = imm - 1;
	    i__4 = k + 9;
	    iconv_(&i__3, darray, &i__4, &c__4, (ftnlen)120);
	    cprin1_(darray, (ftnlen)120);
/* L450: */
	}
    }

L480:
L130:
    return 0;
} /* sspict_ */

#undef iiscan


