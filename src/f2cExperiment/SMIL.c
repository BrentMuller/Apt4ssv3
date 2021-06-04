/* SMIL.f -- translated by f2c (version 20100827).
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

struct {
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

struct {
    integer ibug, i1, i2;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal dgeom[4], dlim[4], tldir[3], dofset;
    integer itldir, idtool, nds;
} xds_;

#define xds_1 xds_

struct {
    doublereal pgeom[4], pside, pthick;
    integer iptool, nps;
} xps_;

#define xps_1 xps_

struct {
    doublereal clrpln[4], fed[4];
    integer nclrpl, nfeed;
} xfeed_;

#define xfeed_1 xfeed_

struct {
    doublereal sstep[4];
    integer nstepo;
} xstepo_;

#define xstepo_1 xstepo_

struct {
    doublereal axis[3];
    integer iaxis, naxis;
} xaxis_;

#define xaxis_1 xaxis_

struct {
    logical lgchk, lintck, lavctl, lvaxis;
} rmflgs_;

#define rmflgs_1 rmflgs_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__6 = 6;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0001913.W04   *** */

/* Subroutine */ int smil_(void)
{
    /* Initialized data */

    static integer imax1 = 7;
    static integer izal1[7] = { 3561,3562,3563,3564,3565,3566,3567 };
    static integer imax2 = 4;
    static integer izal2[4] = { 3551,3552,3553,3554 };
    static doublereal acrssp = 137.;
    static char wds[6] = "DS    ";
    static doublereal aincr = 57.;
    static doublereal aminus = 41.;
    static char rnam1[8] = "SMIL    ";
    static doublereal aparam = 144.;
    static doublereal apath = 165.;
    static doublereal apickf = 166.;
    static doublereal aplane = 2.;
    static char rnam2[8] = "SSPATH  ";
    static doublereal aplus = 42.;
    static doublereal aposn = 164.;
    static doublereal ascala = 21.;
    static doublereal ascurv = 30.;
    static doublereal astepo = 162.;
    static doublereal atansp = 136.;
    static char rnama[8] = "SMIL  ??";
    static doublereal avecto = 20.;
    static doublereal azigza = 61.;
    static char wdispl[6] = "DISPLY";
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-14;
    static integer ibegin = 42;
    static char rname[8] = "        ";
    static integer nogood = -121;
    static integer nlast = 0;
    static integer nbig = 50;
    static integer irbase = 3550;
    static char hpockt[8] = "POCKET  ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal ta[3], td[3], te[3];
    static integer ir, il1, il2;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, irr, isq;
    static doublereal tul[7], ust, vst;
    extern integer bcdf_(char *, ftnlen);
    static doublereal cdir;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static integer nlen;
    static doublereal pdir, vinc[4];
    static integer icur;
    static doublereal dtol, ptem[2];
    extern /* Subroutine */ int inex_(doublereal *, doublereal *, doublereal *
	    , doublereal *);
    static integer iskp;
    static doublereal word;
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int clift_(doublereal *, doublereal *, doublereal 
	    *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal elmax;
    static integer maxcl, iqual;
    static doublereal dstep;
    static char ctest[6];
    extern /* Subroutine */ int clput_(doublereal *, doublereal *, integer *);
    static doublereal ptoli;
    static integer ipart, idriv;
    static doublereal ptolo;
    static char badmsg[20];
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int gfetch_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal backup, amaxdp, scalht;
    static integer ipockt[2];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer inctyp;
    extern /* Subroutine */ int getapt_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *);
    static integer idtype;
    static doublereal stepov;
    static integer iclskp;
    static doublereal stepmx;
    extern /* Subroutine */ int sspath_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), cutreg_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    record_(integer *), cprint_(char *, ftnlen);

/* ---   PURPOSE OF THE ROUTINE IS TO DECODE SMIL/ COMMANDS */
/* ---   AND CALL THE PATH ROUTINE, SSPATH, TO GENERATE CLDATA */
/* ---   ERRORS FROM SSPATH OR UNINITIALIZED DATA AREAS ARE */
/* ---   DETECTED HERE AND CALLS ARE MADE TO AERR. */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */









/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */



/* --WORD MODE VALUES IN REAL FORM AND HOLLERITH FORM. */
/* --THESE ARE WORDS USED IN SMIL AND SCON COMMANDS */



    ipockt[0] = bcdf_(hpockt, (ftnlen)4);
    ipockt[1] = bcdf_(hpockt + 4, (ftnlen)4);
    apt299_(&c__0, ipockt, &c__0, &c__0);
    for (i__ = 1; i__ <= 3; ++i__) {
	te[i__ - 1] = zero;
/* L10: */
	ta[i__ - 1] = zero;
    }
    icur = ibegin;
    nlen = (integer) _BLNK__1.com[icur - 1];
    nlast = ibegin + nlen - 2;
    _BLNK__1.com[nlast - 1] = zero;
    ++icur;
    if (nlen < 3 || nlen > nbig) {
	goto L995;
    }

    word = _BLNK__1.com[icur - 1];
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wdispl, (ftnlen)6, (ftnlen)6) == 0) {
	word = _BLNK__1.com[icur];
    }
    icur += 2;
    if (word == aposn) {
	goto L100;
    }
    if (word == apath) {
	goto L200;
    }
    if (word == azigza) {
	goto L300;
    }
    if (word == apickf) {
	goto L300;
    }
    holfrm_(&word, ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wdispl, (ftnlen)6, (ftnlen)6) == 0) {
	goto L300;
    }
    goto L998;

/* --PROCESS THE SMIL/POSN COMMAND */
L100:
    clput_(te, ta, &c_n1);
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) != 0) {
	goto L998;
    }
    if (_BLNK__1.com[icur - 1] != aparam) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    ust = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    vst = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aincr) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] == ascala) {
	goto L110;
    }
    if (_BLNK__1.com[icur - 1] == avecto) {
	goto L130;
    }
    if (_BLNK__1.com[icur - 1] == aplane) {
	goto L150;
    }
    goto L998;
/* --SCALAR LIFT BACK PARAMETER */
L110:
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    vinc[0] = _BLNK__1.com[icur];
    icur += 2;
    inctyp = 21;
    goto L190;
L130:
/* --VECTOR LIFTBACK PARAMETER */
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L140: */
	vinc[i__ - 1] = _BLNK__1.com[icur + i__ - 1];
    }
    icur += 4;
    inctyp = 20;
    goto L190;
L150:
/* --CLEARANCE PLANE LIFTBACK */
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L160: */
	vinc[i__ - 1] = _BLNK__1.com[icur + i__ - 1];
    }
    inctyp = 2;
    icur += 5;
    goto L190;

L190:
    if (icur != nlast) {
	goto L996;
    }
/* --CHECK IF PROPER BLOCKS ARE INITIALIZED */
    if (xds_1.nds == nogood) {
	goto L994;
    }
    if (xps_1.nps == nogood) {
	goto L994;
    }
    if (xaxis_1.naxis == nogood) {
	goto L994;
    }

/* --GET OTHER NEEDED APT VARIABLES */
    getapt_(tul, &ptoli, &ptolo, &dtol, &amaxdp, &elmax, &maxcl, &ir);
    if (ir != 0) {
	goto L993;
    }
/* --FETCH PART AND DRIVE SURFACES */
    gfetch_(&nbig, &maxlda_1.maxlda, _BLNK__1.com, xds_1.dgeom, xps_1.pgeom, &
	    ir);
    if (ir != 0) {
	goto L992;
    }
/* --SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH */
/* --ICLSKP NEGATIVE GUARANTEES NO CL OUTPUT UNTIL TE IS */
/* --COMPENSATED */
    if (ust < xds_1.dlim[0] - smal || ust > xds_1.dlim[1] + smal) {
	goto L996;
    }
    if (vst < xds_1.dlim[2] - smal || vst > xds_1.dlim[3] + smal) {
	goto L996;
    }
    pdir = one;
    idtype = 1;
    if (xds_1.dgeom[2] == ascurv) {
	idtype = 0;
    }
    scalht = zero;
    stepov = zero;
    maxcl = 1;
    iclskp = -1;
    iqual = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	te[i__ - 1] = zero;
	ta[i__ - 1] = zero;
	td[i__ - 1] = zero;
/* L170: */
    }

    dstep = one;
    ipart = (integer) xps_1.pgeom[3];
    idriv = (integer) xds_1.dgeom[3];
    stepmx = zero;

/* .... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD */
    if (rmflgs_1.lintck) {
	inex_(&_BLNK__1.com[ipart - 1], &xps_1.pside, &ptoli, &ptolo);
    }

    sspath_(&_BLNK__1.com[idriv - 1], &idtype, &pdir, &dtol, &dstep, &
	    xds_1.dofset, xds_1.dlim, &xds_1.idtool, &xaxis_1.iaxis, 
	    xaxis_1.axis, &xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1]
	    , &xps_1.pside, &xps_1.pthick, &ptoli, &ptolo, &xps_1.iptool, tul,
	     &ust, &vst, &scalht, &stepov, &stepmx, &amaxdp, &elmax, &maxcl, &
	    iclskp, &iqual, te, ta, td, ptem, &irr);
    if (irr != 0) {
	goto L990;
    }
/* --POSN SUCESSFUL, NOW COMPENSATE TOOL END */
    if (inctyp == 20) {
	goto L172;
    }
    if (inctyp == 2) {
	goto L174;
    }
    backup = vinc[0];
    for (i__ = 1; i__ <= 3; ++i__) {
/* L181: */
	te[i__ - 1] -= backup * td[i__ - 1];
    }
    goto L185;

L174:
/* ---CLEARANCE PLANE CALCULATION */
    clift_(te, vinc, te);
    goto L185;

L172:
/* --VECTOR INCREMENT */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L183: */
	te[i__ - 1] += vinc[i__ - 1];
    }
    goto L185;

L185:
    clput_(te, ta, &c__1);
    goto L999;

/* --PROCESS PATH COMMAND */
L200:
    clput_(te, ta, &c_n1);
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) != 0) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aparam) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    ust = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    vst = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != atansp && _BLNK__1.com[icur - 1] != acrssp) 
	    {
	goto L998;
    }
    idtype = 1;
    if (_BLNK__1.com[icur - 1] == acrssp) {
	idtype = 2;
    }
    if (xds_1.dgeom[2] == ascurv) {
	idtype = 0;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aplus && _BLNK__1.com[icur - 1] != aminus) {
	goto L998;
    }
    pdir = one;
    if (_BLNK__1.com[icur - 1] == aminus) {
	pdir = -one;
    }
    icur += 2;
/* ---OPTIONAL PARAMETER TO INDICATE WHETHER TO SKIP FIRST RECORD */
    iskp = 0;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L210;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    if (_BLNK__1.com[icur] > smal) {
	iskp = 1;
    }
    icur += 2;
    goto L210;

L210:
    if (icur != nlast) {
	goto L995;
    }
    if (xds_1.nds == nogood) {
	goto L994;
    }
    if (xps_1.nps == nogood) {
	goto L994;
    }
    if (xaxis_1.naxis == nogood) {
	goto L994;
    }

/* --GET OTHER NEEDED APT VARIABLES */
    getapt_(tul, &ptoli, &ptolo, &dtol, &amaxdp, &elmax, &maxcl, &ir);
    if (ir != 0) {
	goto L993;
    }
/* --FETCH PART AND DRIVE SURFACES */
    gfetch_(&nbig, &maxlda_1.maxlda, _BLNK__1.com, xds_1.dgeom, xps_1.pgeom, &
	    ir);
    if (ir != 0) {
	goto L992;
    }
/* --SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH */
/* --ICLSKP NEGATIVE GUARANTEES NO CL OUTPUT UNTIL TE IS */
/* --COMPENSATED */
    if (ust < xds_1.dlim[0] - smal || ust > xds_1.dlim[1] + smal) {
	goto L996;
    }
    if (vst < xds_1.dlim[2] - smal || vst > xds_1.dlim[3] + smal) {
	goto L996;
    }
    scalht = zero;
    stepov = zero;
    iclskp = iskp;
    iqual = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	te[i__ - 1] = zero;
	ta[i__ - 1] = zero;
	td[i__ - 1] = zero;
/* L220: */
    }

    ipart = (integer) xps_1.pgeom[3];
    dstep = one;
    idriv = (integer) xds_1.dgeom[3];
    stepmx = zero;

/* .... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD */
    if (rmflgs_1.lintck) {
	inex_(&_BLNK__1.com[ipart - 1], &xps_1.pside, &ptoli, &ptolo);
    }

    sspath_(&_BLNK__1.com[idriv - 1], &idtype, &pdir, &dtol, &dstep, &
	    xds_1.dofset, xds_1.dlim, &xds_1.idtool, &xaxis_1.iaxis, 
	    xaxis_1.axis, &xds_1.itldir, xds_1.tldir, &_BLNK__1.com[ipart - 1]
	    , &xps_1.pside, &xps_1.pthick, &ptoli, &ptolo, &xps_1.iptool, tul,
	     &ust, &vst, &scalht, &stepov, &stepmx, &amaxdp, &elmax, &maxcl, &
	    iclskp, &iqual, te, ta, td, ptem, &irr);
    if (irr != 0) {
	goto L990;
    }
    goto L999;

/* --PROCESS INPUT FOR ZIGZAG AND PICKFD */
L300:
    holfrm_(&_BLNK__1.com[icur], ctest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(ctest, wds, (ftnlen)6, (ftnlen)6) != 0) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aparam) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    ust = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L998;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    vst = _BLNK__1.com[icur];
    icur += 2;
    if (_BLNK__1.com[icur - 1] != atansp && _BLNK__1.com[icur - 1] != acrssp) 
	    {
	goto L998;
    }
    idtype = 1;
    if (_BLNK__1.com[icur - 1] == acrssp) {
	idtype = 2;
    }
    if (xds_1.dgeom[2] == ascurv) {
	idtype = 0;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aplus && _BLNK__1.com[icur - 1] != aminus) {
	goto L998;
    }
    pdir = one;
    if (_BLNK__1.com[icur - 1] == aminus) {
	pdir = -one;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != astepo) {
	goto L998;
    }
    icur += 2;
    if (_BLNK__1.com[icur - 1] != aplus && _BLNK__1.com[icur - 1] != aminus) {
	goto L998;
    }
    cdir = one;
    if (_BLNK__1.com[icur - 1] == aminus) {
	cdir = -one;
    }
    icur += 2;
/* ---OPTIONAL PARAMETER TO INDICATE WHETHER TO SKIP FIRST RECORD */
    iskp = 0;
    if (_BLNK__1.com[icur - 1] != ascala) {
	goto L310;
    }
    if (ckdef_(&_BLNK__1.com[icur])) {
	goto L997;
    }
    if (_BLNK__1.com[icur] > smal) {
	iskp = 1;
    }
    icur += 2;
    goto L310;

L310:
    if (icur != nlast) {
	goto L995;
    }
    if (xds_1.nds == nogood) {
	goto L994;
    }
    if (xps_1.nps == nogood) {
	goto L994;
    }
    if (xaxis_1.naxis == nogood) {
	goto L994;
    }
    if (xfeed_1.nfeed == nogood) {
	goto L994;
    }
    if (xstepo_1.nstepo == nogood) {
	goto L994;
    }
    if (word == apickf && xfeed_1.nclrpl == nogood) {
	goto L994;
    }

/* --GET OTHER NEEDED APT VARIABLES */
    getapt_(tul, &ptoli, &ptolo, &dtol, &amaxdp, &elmax, &maxcl, &ir);
    if (ir != 0) {
	goto L993;
    }
/* --FETCH PART AND DRIVE SURFACES */
    gfetch_(&nbig, &maxlda_1.maxlda, _BLNK__1.com, xds_1.dgeom, xps_1.pgeom, &
	    ir);
    if (ir != 0) {
	goto L992;
    }
/* --SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH */
    if (ust < xds_1.dlim[0] - smal || ust > xds_1.dlim[1] + smal) {
	goto L996;
    }
    if (vst < xds_1.dlim[2] - smal || vst > xds_1.dlim[3] + smal) {
	goto L996;
    }
/* --CUTREG ROUTINE SEPARATED TO REDUCE SUBROUTINE SIZE */
    iqual = 0;

/* .... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD */
    ipart = (integer) xps_1.pgeom[3];
    if (rmflgs_1.lintck) {
	inex_(&_BLNK__1.com[ipart - 1], &xps_1.pside, &ptoli, &ptolo);
    }

    cutreg_(&word, &cdir, &ust, &vst, &pdir, &idtype, &iqual, tul, &ptoli, &
	    ptolo, &dtol, &amaxdp, &elmax, &maxcl, &iskp, &irr);
    if (irr != 0) {
	goto L990;
    }
    goto L999;

L992:
/* ---ERROR, PART OR DRIVE GEOMETRY COULD NOT BE FETCHED */
    irr = 17;
    goto L990;
L993:
/* ---ERROR, GENERAL APT ARELEM VARIABLES INVALID */
    irr = 16;
    goto L990;
L994:
/* ---ERROR,  SCON DATA AREA IS UNINITIALIZED */
    irr = 15;
    goto L990;
L995:
/* ---ERROR, LENGTH OF SMIL INPUT FIELD INVALID */
    irr = 14;
    goto L990;
L996:
/* ---ERROR, INPUT VALUES ARE INVALID */
    irr = 13;
    goto L990;
L997:
/* ---ERROR, INPUT CANON FORM NOT DEFINED */
    irr = 12;
    goto L990;
L998:
/* ---ERROR, INPUT VARIABLE WAS UNRECOGNIZED IN POSITION */
    irr = 11;
    goto L990;

L990:
    irr = irbase + irr;
    record_(&isq);
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " END OF SMIL", (ftnlen)20, (ftnlen)12);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__0, "ISEQ", &isq, (ftnlen)4);
    bad_(&c__1, &c__0, "NLST", &nlast, (ftnlen)4);
    bad_(&c__1, &c__0, "NLEN", &nlen, (ftnlen)4);
    bad_(&c__1, &c__0, "IRR ", &irr, (ftnlen)4);
    bad_(&c__1, &c__0, "ICUR", &icur, (ftnlen)4);
    bad_(&c_n1, &c__0, "IRBS", &irbase, (ftnlen)4);
    bad_(&c__1, &c__0, "DS  ", &xds_1.nds, (ftnlen)4);
    bad_(&c__1, &c__0, "PS  ", &xps_1.nps, (ftnlen)4);
    bad_(&c__1, &c__0, "FEED", &xfeed_1.nfeed, (ftnlen)4);
    bad_(&c__1, &c__0, "STOV", &xstepo_1.nstepo, (ftnlen)4);
    bad_(&c__1, &c__0, "AXIS", &xaxis_1.naxis, (ftnlen)4);
    bad_(&c_n1, &c__0, "CPLN", &xfeed_1.nclrpl, (ftnlen)4);

    s_copy(rname, rnama, (ftnlen)8, (ftnlen)8);
    i__1 = imax1;
    for (il1 = 1; il1 <= i__1; ++il1) {
/* L8001: */
	if (irr == izal1[il1 - 1]) {
	    s_copy(rname, rnam1, (ftnlen)8, (ftnlen)8);
	}
    }
    i__1 = imax2;
    for (il2 = 1; il2 <= i__1; ++il2) {
/* L8002: */
	if (irr == izal2[il2 - 1]) {
	    s_copy(rname, rnam2, (ftnlen)8, (ftnlen)8);
	}
    }
    aerr_(&irr, rname, (ftnlen)8);

    goto L999;

L999:

    return 0;
} /* smil_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


