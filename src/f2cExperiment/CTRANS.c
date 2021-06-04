/* CTRANS.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n4 = -4;
static integer c__1 = 1;
static integer c_n16 = -16;
static integer c__4 = 4;
static integer c__3 = 3;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0001059.V06   *** */

/* Subroutine */ int ctrans_(doublereal *profil, doublereal *cros, integer *
	kcase, integer *maxsrf, doublereal *surf, integer *irr)
{
    /* Initialized data */

    static integer ib[89] = { 101,4,1,13,1,102,8,1,14,1,103,12,1,15,1,104,16,
	    1,9999,201,1,1,6,2,202,2,1,5,1,203,12,1,15,1,204,16,1,9999,301,4,
	    1,13,1,302,6,1,11,1,303,7,1,10,1,304,16,1,9999,401,3,2,9,1,402,8,
	    1,14,1,403,1,1,11,1,404,16,1,9999,501,1,1,502,6,1,503,11,1,504,16,
	    1,9999 };
    static integer ibmax = 89;
    static integer iend = 9999;
    static integer nbx = 2;
    static doublereal bx[2] = { 1.,-1. };
    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k, l, ic, jj, kk, ll, ip, nn;
    extern /* Subroutine */ int bad_();
    static integer loc;
    static doublereal afx, trn[16];
    static integer locc;
    static doublereal bmat[64]	/* was [16][4] */, bsel[64]	/* was [16][4]
	     */, apat;
    static integer iloc, jmat, jval, ival, locp, ipat, npat, narcc, narcp, 
	    nhdcrs, nhdpro;
    extern /* Subroutine */ int transp_(doublereal *, doublereal *, integer *)
	    , smmult_(integer *, integer *, integer *, integer *, doublereal *
	    , doublereal *, doublereal *);

/* ---      PROFIL =INPUT SYNTHETIC PROFILE CURVE */
/* ---      CROS = INPUT SYNTHETIC CROSS COMMAND CURVE */
/* ---      KCASE =INPUT  TYPE OF CROSS TRANSFORMATION TO USE */
/* ---         =1 GIVES TRANSL, =2 GIVES XYROT, =3 GIVES YZROT */
/* ---         =4 GIVES ZXROT, =5 GIVES SCALE */
/* ---      MAXSRF =INPUT IS THE MAXIMUM SPACE AVAILABLE FOR SURF */
/* ---      SURF IS THE OUTPUT ARRAY WHICH CONTAINS THE SURFACE */
/* ---      (LESS TOPOLOGY TABLE) */
/* ---      IRR =OUTPUT, IF NON ZERO ON RETURN INDICATES ERROR. */
/* ---      THIS SUBROUTINE ACCEPTS AN INPUT OF A PROFILE CURVE */
/* ---      PROFIL OF N ARCS AND A CROSS CURVE CROS OF K ARCS. */
/* ---      A MESH-LIKE SURFACE OF N*K RATIONAL BICUBIC PATCHES */
/* ---      IS CONSTRUCTED BY TRANSFORMING EACH OF THE PROFILE ARCS */
/* ---      BY THE CROSS COMMAND CURVE ARCS.  THE IMPLIED SPLINE */
/* ---      DIRECTION IS DETERMINED BY THE PROFILE CURVE AND */
/* ---      THE CROSS DIRECTION BY THE CROSS COMMAND CURVE. */



/* ---      THE FOLLOWING ARRAYS ARE USED TO HOLD THE SELECTOR */
/* ---      MATRIX BSEL AND BOTH INTERIM AND FINAL RATIONAL BICUBIC */
/* ---      PATCH MATRICES BMAT. */
/* --- */
/* ---      THE FOLLOWING ARRAYS HOLD INFORMATION NECESSARY TO */
/* ---      GENERATE SELECTOR MATRICES BASED ON THE CASE(KCASE) */
    /* Parameter adjustments */
    --surf;
    --cros;
    --profil;

    /* Function Body */
/* ---     THE FOLLOWING ARRAY HOLDS REAL VALUES WHICH IB POINTS TO. */

/* ---     THE SIZE OF THE HEADER TABLE AND NUMBER OF ARCS FOR BOTH CURVES */
    nhdpro = (integer) profil[2];
    narcp = (integer) profil[4];
    nhdcrs = (integer) cros[2];
    narcc = (integer) cros[4];
/* ***      CHECK FOR ENOUGH ROOM FOR SURFACE */
    *irr = 1;
    npat = narcp * narcc;
    if (npat * 74 + 10 > *maxsrf) {
	goto L990;
    }
/* ---     SET UP THE BSEL MATRIX FOR THIS KCASE(LOGIC IS USED */
/* ---     TO PREVENT STORING MANY COMPLETE BSEL-S) */
    for (l = 1; l <= 4; ++l) {
	for (k = 1; k <= 16; ++k) {
/* L101: */
	    bsel[k + (l << 4) - 17] = zero;
	}
    }
/* ---      NOW SKIM THRU THE IB ARRAY TO PICK UP NONZERO BSEL VALUES */
    i__ = 1;
L201:
/* ***     ERROR IN IB SET-UP */
    *irr = 2;
    if (i__ > ibmax) {
	goto L990;
    }
    if (ib[i__ - 1] / 100 == *kcase) {
	goto L203;
    }
    ++i__;
    goto L201;
L203:
    if (ib[i__ - 1] == iend) {
	goto L210;
    }
    if (ib[i__ - 1] < 100) {
	goto L205;
    }
    jmat = ib[i__ - 1] % 100;
    ++i__;
    goto L203;
L205:
    jval = ib[i__];
    ival = ib[i__ - 1];
/* ***     INVALID INDEX, SYSTEM ERROR */
    *irr = 3;
    if (ival < 1 || ival > 16) {
	goto L990;
    }
    if (jmat < 1 || jmat > 4) {
	goto L990;
    }
    if (jval < 1 || jval > nbx) {
	goto L990;
    }

    bsel[ival + (jmat << 4) - 17] = bx[jval - 1];
    i__ += 2;
    goto L203;
L210:

    if (ibugg_1.ibug != 11) {
	goto L212;
    }
    for (l = 1; l <= 4; ++l) {
	for (k = 1; k <= 4; ++k) {
	    kk = (k - 1 << 2) + 1;
	    bad_(&c_n4, &c__1, "BSEL", &bsel[kk + (l << 4) - 17], (ftnlen)4);
/* L213: */
	}
    }
L212:

/* ---      FIRST INITIALIZE SURFACE HEADER DATA */
    surf[1] = zero;
    apat = (doublereal) npat;
    surf[2] = apat * 64.f;
    surf[3] = apat * 4.f;
    surf[4] = apat;
    surf[5] = 2.f;
    surf[6] = 5.f;
    surf[7] = one;
    surf[8] = apat * 74.f + 10.f;
    surf[9] = (doublereal) (narcc + 1);
    surf[10] = (doublereal) (narcp + 1);
/* ---     SET UP PATCH HEADER TABLE */
    afx = apat * 6.f + 10.f + 1.f;
    iloc = 10;
    i__1 = npat;
    for (l = 1; l <= i__1; ++l) {
	for (k = 1; k <= 4; ++k) {
/* L320: */
	    surf[iloc + k] = 4.f;
	}
	surf[iloc + 5] = afx;
	surf[iloc + 6] = zero;
	iloc += 6;
	afx += 64.f;
/* L310: */
    }

/* ---     MAIN LOOP  COMPUTE EACH RATIONAL PATCH AND PLACE IN SURF */
    i__1 = narcc;
    for (ic = 1; ic <= i__1; ++ic) {
	locc = (nhdcrs + ic - 1) * 24 + 1;
	if (ibugg_1.ibug == 11) {
	    bad_(&c_n16, &c__1, "CROS", &cros[locc], (ftnlen)4);
	}
	i__2 = narcp;
	for (ip = 1; ip <= i__2; ++ip) {
	    locp = (nhdpro + ip - 1) * 24 + 1;

/* ---     TRANSPOSE THE PROFILE MATRIX */
	    if (ibugg_1.ibug == 11) {
		bad_(&c_n16, &c__1, "PROF", &profil[locp], (ftnlen)4);
	    }
	    transp_(&profil[locp], trn, &c__4);
	    if (ibugg_1.ibug == 11) {
		bad_(&c_n16, &c__1, "TRN ", trn, (ftnlen)4);
	    }

	    for (j = 1; j <= 4; ++j) {
/* ---     NOTE THAT SMMULT(A,B,C) GIVES C=B*A */
		smmult_(&c__4, &c__4, &c__4, &c__3, &cros[locc], &bsel[(j << 
			4) - 16], &bmat[(j << 4) - 16]);
/* ---      BMAT=BSEL*CROS, THEN BMAT=BMAT*TRN */
		smmult_(&c__4, &c__4, &c__4, &c__3, &bmat[(j << 4) - 16], trn,
			 &bmat[(j << 4) - 16]);
/* ---     NOW BACK TRANSPOSE THE BMAT RESULT */
		transp_(&bmat[(j << 4) - 16], &bmat[(j << 4) - 16], &c__4);
		if (ibugg_1.ibug != 11) {
		    goto L314;
		}
		for (l = 1; l <= 4; ++l) {
		    ll = (l - 1 << 2) + 1;
		    bad_(&c_n4, &c__1, "BMAT", &bmat[ll + (j << 4) - 17], (
			    ftnlen)4);
/* L315: */
		}
L314:
/* L302: */
		;
	    }
/* ---      NOW TRANSFER THE RATIONAL MATRIX BMAT TO SURF */
	    ipat = (ic - 1) * narcp + ip;
	    loc = ipat * 6 + 9;
	    loc = (integer) surf[loc];
	    for (jj = 1; jj <= 4; ++jj) {
		for (kk = 1; kk <= 16; ++kk) {
		    surf[loc] = bmat[kk + (jj << 4) - 17];
		    ++loc;
/* L303: */
		}
	    }

/* L301: */
	}
    }

/* L980: */
    *irr = 0;
    goto L999;

L990:
    bad_(&c_n1, &c__0, "CTRN", irr, (ftnlen)4);
    goto L999;

L999:

    if (ibugg_1.ibug != 11) {
	goto L998;
    }
    nn = npat * 74 + 10;
    i__2 = -nn;
    bad_(&i__2, &c__1, "SURF", &surf[1], (ftnlen)4);
L998:

    return 0;
} /* ctrans_ */

