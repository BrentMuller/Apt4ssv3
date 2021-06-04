/* XTPCAL.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;
static integer c_n1 = -1;

/* *** SOURCE FILE : XTPCAL.V01   *** */

/* Subroutine */ int xtpcal_(doublereal *tp, doublereal *te, doublereal *ta, 
	doublereal *tpl, doublereal *tel, doublereal *tal, doublereal *xtp, 
	doublereal *xtpl)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal x, y, z__, tf[3], vn[3], xl, yl, zl;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
    static doublereal fwd[3], tfl[3], vnl[3], tpv[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal tpvl[3];
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen), crossv_(doublereal *,
	     doublereal *, doublereal *);





/* .... COMPUTE UNIT FORWARD VECTOR FROM TEL TO TE */


/* .... DEBUG FLAGS */


    /* Parameter adjustments */
    --xtpl;
    --xtp;
    --tal;
    --tel;
    --tpl;
    --ta;
    --te;
    --tp;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	fwd[i__ - 1] = te[i__] - tel[i__];
/* L10: */
    }
    vnorm_(fwd, fwd);

/* .... COMPUTE TWO VECTORS NORMAL TO FWD AND EACH TA */

    crossv_(&ta[1], fwd, vn);
    crossv_(&tal[1], fwd, vnl);

/* .... COMPUTE ORTHOGONAL VECTORS TF AND TFL */

    crossv_(vn, &ta[1], tf);
    crossv_(vnl, &tal[1], tfl);

/* .... COMPUTE VECTORS FROM TOOL TIP TO SURFACE CONTACT POINT FOR */
/*     EACH CASE */

    for (i__ = 1; i__ <= 3; ++i__) {
	tpv[i__ - 1] = tp[i__] - te[i__];
	tpvl[i__ - 1] = tpl[i__] - tel[i__];
/* L20: */
    }

/* .... PROJECT INTO LOCAL TOOL AXIS SYSTEM */

    dotf_(&x, tpv, tf);
    dotf_(&y, tpv, vn);
    dotf_(&z__, tpv, &ta[1]);

    dotf_(&xl, tpvl, tfl);
    dotf_(&yl, tpvl, vnl);
    dotf_(&zl, tpvl, &tal[1]);

/* .... COMPUTE CORRESPONDING POINTS ON TOOL */

    for (i__ = 1; i__ <= 3; ++i__) {
	xtp[i__] = te[i__] + xl * tf[i__ - 1] + yl * vn[i__ - 1] + zl * ta[
		i__];
	xtpl[i__] = tel[i__] + x * tfl[i__ - 1] + y * vnl[i__ - 1] + z__ * 
		tal[i__];
/* L30: */
    }

    if (ibugg_1.ibug == 11) {
	s_copy(badmsg, " AFTER XTPCAL", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c__3, &c__1, "TP  ", &tp[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "TPL ", &tpl[1], (ftnlen)4);
	bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "TEL ", &tel[1], (ftnlen)4);
	bad_(&c__3, &c__1, "TA  ", &ta[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "TAL ", &tal[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "FWD ", fwd, (ftnlen)4);
	bad_(&c__3, &c__1, "VN  ", vn, (ftnlen)4);
	bad_(&c_n3, &c__1, "VNL ", vnl, (ftnlen)4);
	bad_(&c__3, &c__1, "TF  ", tf, (ftnlen)4);
	bad_(&c_n3, &c__1, "TFL ", tfl, (ftnlen)4);
	bad_(&c__3, &c__1, "TPV ", tpv, (ftnlen)4);
	bad_(&c_n3, &c__1, "TPVL", tpvl, (ftnlen)4);
	bad_(&c__1, &c__1, "X   ", &x, (ftnlen)4);
	bad_(&c__1, &c__1, "Y   ", &y, (ftnlen)4);
	bad_(&c__1, &c__1, "Z   ", &z__, (ftnlen)4);
	bad_(&c__1, &c__1, "XL  ", &xl, (ftnlen)4);
	bad_(&c__1, &c__1, "YL  ", &yl, (ftnlen)4);
	bad_(&c_n1, &c__1, "ZL  ", &zl, (ftnlen)4);
	bad_(&c__3, &c__1, "XTP ", &xtp[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "XTPL", &xtpl[1], (ftnlen)4);
    }

    return 0;
} /* xtpcal_ */

