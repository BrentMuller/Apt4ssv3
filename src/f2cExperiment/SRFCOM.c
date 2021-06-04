/* SRFCOM.f -- translated by f2c (version 20100827).
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

struct {
    integer maxlda;
} maxlda_;

#define maxlda_1 maxlda_

struct {
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c_n10 = -10;
static integer c__2 = 2;
static integer c_n2 = -2;
static integer c_n4 = -4;
static integer c__40 = 40;
static integer c__43 = 43;
static integer c__6 = 6;

/* *** SOURCE FILE : M0002769.W01   *** */

/* Subroutine */ int srfcom_(integer *isprnt, integer *irr)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal smal = 1e-14;
    static doublereal u[4] = { 0.,1.,0.,1. };
    static doublereal v[4] = { 0.,0.,1.,1. };
    static integer ibpt[8]	/* was [4][2] */ = { 1,1,2,3,2,3,4,4 };
    static integer icurv[8]	/* was [4][2] */ = { 3,6,6,3,6,3,3,6 };
    static doublereal smalp = 1e-4;
    static doublereal smalv = 1e-5;
    static doublereal fdummy[2] = { 0.,0. };
    static char weight[8] = "WEIGHT  ";
    static char alimit[8] = "LIMIT   ";
    static doublereal zero = 0.;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal b[64];
    static integer i__, j, k, l;
    static doublereal w;
    static integer ii, jj, ik, kk, lk, ll, nk, np[2], nu, nv, nk1, nu1, nv1;
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ich, ibn, jbn, icp[2], jcp[2];
    static doublereal sch[4];
    static integer ipn, nwd, ipt;
    static doublereal spv[32];
    static integer n1tt;
    static doublereal snu2;
    static integer kend, mode, kloc, lcon, kpat, nval, kval, npat;
    static doublereal disp;
    static integer nlen, icur, klim, jcur, itop[24]	/* was [6][4] */;
#define ktop ((integer *)&sspad_1 + 2)
    static integer know;
    static char test[8];
    static integer ntot, nlim1;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static integer nlim2;
    extern logical ckdef_(doublereal *);
    static integer nhead, iflag[4];
#define canon ((doublereal *)&_BLNK__1)
    static doublereal acomp;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer icorn, jcorn;
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer ihtop, nsize;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), holfrm_(doublereal *, char *, 
	    integer *, integer *, integer *, ftnlen);
    static integer nocomp;
    extern /* Subroutine */ int cprint_(char *, ftnlen), cnsurf_(doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *);
    static integer lconsv, kstart, nvalsv, nexsur, numsur;

/* ---     ISPRNT  IS INPUT AND CONTROLS PRINT VERIFICATION */
/* ---     IRR IS OUTPUT AND IF NON ZERO INDICATES AN ERROR */
/* ---     PURPOSE IS TO COMBINE A STRING OF SEPARATELY DEFINED SSURFS */
/* ---     INTO A SINGLE NEW SSURF */
/* ---     PART PROGRAM DATA ARRIVES IN BLANK COMMON(LOC 41 ON) */
/* ---     IT IS FIRST TRANSFERRED TO LABELED COMMON. */
/* ---     SURFACES ARE THEN LOADED ONE BY ONE INTO BLANK COMMON */
/* ---     STRIPPED OF THEIR TOPOLOGY TABLES, AND CONSOLIDATED INTO */
/* ---     A SINGLE SURFACE IN BLANK COMMON.  THEN A PROCESS OF */
/* ---     COMPARING EACH PATCH TO EVERY OTHER PATCH IS INVOKED TO */
/* ---     BUILD A NEW TOPOLOGY TABLE FOR THE CONSOLIDATED */
/* ---     SURFACE IN LABELED COMMON.  PRINT VERIFICATION FOLLOWS */
/* ---     IF THE PRINT FLAG HAS BEEN TURNED ON AND AS A FINAL */
/* ---     STEP THIS TOPOLOGY DATA IS CONSOLIDATED WITH THE */
/* ---     NEW SURFACE. */



/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/* .... SCULPTURED SURFACES SCRATCH PAD AREA */






/*     DUMMY ARRAY FOR BLANK-COMMON RESERVATION, MESH-TEST */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */








/* ---     INTEGER ARRAY KTOP USED FOR QUICK MANIPULATION OF TOPOLOGY DATA */






/* ---     TRANSFER PART PROGRAM INPUT */
    nsize = (integer) sscan[4];
    i__1 = nsize;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sspad_1.scan[i__ - 1] = sscan[i__ - 1];
/* L10: */
    }
/* ---     NEXT AVAILABLE SLOT IN SCAN */
    sspad_1.iscan = nsize;
/* ---     NPAT IS TOTAL NUMBER OF PATCHES IN NEW SURFACE */
/* ---     NTOT IS TOTAL SIZE OF ALL SURFACES */
/* ---     NUMSUR IS TOTAL NUMBER OF INPUT SURFACES */
    npat = 0;
    ntot = 0;
    numsur = 0;
/* ---     LOAD IN ALL SURFACES TO OBTAIN NPAT,NTOT,NUMSUR */
    i__ = 9;
L100:
    holfrm_(&sspad_1.scan[i__], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, weight, (ftnlen)8, (ftnlen)8) != 0 && s_cmp(test, alimit, 
	    (ftnlen)8, (ftnlen)8) != 0) {
	goto L110;
    }
    i__ += 2;
    goto L120;

L110:
/* ****    INPUT SURFACE WAS NOT DEFINED OR INCORRECT INPUT */
    *irr = 1;
    if (ckdef_(&sspad_1.scan[i__ - 1])) {
	goto L998;
    }
    mode = 2;
    apt094_(&mode, &sspad_1.scan[i__ - 1], sscan);
    *irr = 2;
/* ****    INPUT SURFACE COULD NOT BE FETCHED FROM EXTERNAL STORAGE */
    if (mode != 2) {
	goto L998;
    }
/* ---     SURFACE HAS BEEN LOADED, EXTRACT NEEDED INFORMATION. */
    npat = (integer) (npat + sscan[3]);
    ntot = (integer) (ntot + sscan[7]);
    ++numsur;
L120:
    i__ += 2;
    if (i__ < nsize) {
	goto L100;
    }

    if (ibugg_1.ibug != 11) {
	goto L130;
    }
    bad_(&c__1, &c__0, "NPAT", &npat, (ftnlen)4);
    bad_(&c__1, &c__0, "NTOT", &ntot, (ftnlen)4);
    bad_(&c_n1, &c__0, "NMSR", &numsur, (ftnlen)4);
L130:
/* ****    ERROR IF THIS COMBINATION OF SURFACES IS TOO LARGE */
    *irr = 3;
    if (ntot - numsur * 10 > maxlda_1.maxlda) {
	goto L998;
    }
/* ---      IF ONLY ONE SURFACE IS INPUT, THEN LEAVE IT UNALTERED */
    if (numsur == 1) {
	goto L999;
    }

/* ---     NOW RE-READ ALL SURFACES AND CONSOLIDATE THEM INTO A */
/* ---     A SINGLE SURFACE AFTER EACH SURFACE LOAD */
/* ---     ALSO, STRIP OUT ALL TOPOLOGY TABLES, AS THEY WILL BE RESET. */
/* ---     FIRST SET POINTER FOR SCANNING THRU PART PROGRAM INPUT */
    i__ = 9;
/* ---     CURRENT AVAILABLE SLOT IN PATCH HEADER TABLE */
    nhead = 11;
/* ---     SET CURRENT AVAILABLE SLOT IN VALUE TABLE */
    nval = npat * 6 + 11;
/* ---     SET CURRENT AVAILABLE SLOT TO LOAD THE NEXT  SURFACE. */
    nexsur = nval;

L200:
    holfrm_(&sspad_1.scan[i__], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, weight, (ftnlen)8, (ftnlen)8) != 0 && s_cmp(test, alimit, 
	    (ftnlen)8, (ftnlen)8) != 0) {
	goto L210;
    }
    i__ += 2;
    goto L299;

L210:
/* ****    INPUT SURFACE NOT CORRECTLY DEFINED */
    *irr = 4;
    if (ckdef_(&sspad_1.scan[i__ - 1])) {
	goto L998;
    }
    mode = 2;
    apt094_(&mode, &sspad_1.scan[i__ - 1], &sscan[nexsur - 1]);
/* ****    INPUT SURFACE COULD NOT BE FETCHED */
    *irr = 5;
    if (mode != 2) {
	goto L998;
    }
/* ---     NEXT  SURFACE IS NOW AVAILABLE.  CONSOLIDATE IT WITH */
/* ---     THE CONSOLIDATED SURFACE. */
/* ---     PATCH HEADER DATA MUST BE MODIFIED TO REFLECT NEW DISPLACEMENTS */
/* ---      OF VALUE AND TOPOLOGY DATA. */

/* ---     NUMBER OF PATCHES IN CURRENT INPUT SURFACE */
    kpat = (integer) sscan[nexsur + 2];
/* ---     LENGTH OF VALUE TABLE FOR CURRENT INPUT SURFACE */
    kval = (integer) sscan[nexsur];
/* ---     POINTER TO CURRENT PATCH HEADER DATA */
    kloc = nexsur + 10;
/* ---     COMPUTE NEW DISPLACEMENT FOR HEADER DATA */
    disp = nval - sscan[kloc + 3];
/* ---     RULE FOR DISPLACEMENT IS DIFFERENT FOR A GENCUR TYPE */
    if (sscan[kloc - 1] > 9.f) {
	disp = nval - sscan[kloc - 1];
    }
    if (ibugg_1.ibug != 0) {
	bad_(&c_n1, &c__1, "DISP", &disp, (ftnlen)4);
    }

    i__1 = kpat;
    for (l = 1; l <= i__1; ++l) {
	if (sscan[kloc - 1] > 9.f) {
	    goto L230;
	}
/* ---     CONVENTIONAL COONS BICUBIC PATCH */
	sscan[kloc + 3] += disp;
	goto L240;

L230:
/* ---     GENCUR TYPE PATCH */
	for (ll = 1; ll <= 4; ++ll) {
	    lk = kloc + ll - 1;
	    if (sscan[lk - 1] > smal) {
		sscan[lk - 1] += disp;
	    }
/* L250: */
	}

L240:
/* ---     NOW TRANSFER SIX HEADER LOCATIONS */
	for (ll = 1; ll <= 6; ++ll) {
	    sscan[nhead - 1] = sscan[kloc - 1];
	    ++nhead;
	    ++kloc;
/* L260: */
	}
/* ---      ZERO OUT THE TOPOLOGY TABLE REFERENCE */
	sscan[nhead - 2] = zero;

/* L220: */
    }

/* ---     NOW TRANSFER PATCH VALUE DATA IN ONE BLOCK */
    kloc = nexsur + 9 + kpat * 6;
    i__1 = kval;
    for (ll = 1; ll <= i__1; ++ll) {
	sscan[nval - 1] = sscan[kloc + ll - 1];
	++nval;
/* L270: */
    }

L299:
    nexsur = nval;
    i__ += 2;
    if (i__ < nsize) {
	goto L200;
    }

/* ---     SURFACES HAVE ALL BEEN FETCHED AND HEADER AND VALUE DATA */
/* ---     CONSOLIDATED INTO ONE SURFACE. */

/* ---     NOW A PORTION OF THE SURFACE HEADER TABLE CAN BE FILLED */
    for (l = 1; l <= 10; ++l) {
/* L292: */
	sscan[l - 1] = zero;
    }
/* ---     VALUE TABLE SIZE */
    sscan[1] = (doublereal) (nval - 11 - npat * 6);
/* ---     NUMBER OF PATCHES */
    sscan[3] = (doublereal) npat;
/* ---     TYPE OF SURFACE - NON-MESH */
    sscan[4] = one;
/* ---     SURFACE TYPE -- ASSEMBLAGE OF ALL TYPES */
    sscan[5] = 7.f;
/* ---     SIGN OF SURFACE NORMAL */
    sscan[6] = one;
/* ---     TOTAL SIZE - NOT YET KNOWN BUT SET TO CURRENT SIZE */
    sscan[7] = (doublereal) (nval - 1);

    if (ibugg_1.ibug != 11) {
	goto L291;
    }
    bad_(&c_n10, &c__1, "SSHD", sscan, (ftnlen)4);
    nk = npat * 6;
    i__1 = -nk;
    bad_(&i__1, &c__1, "PCHD", &sscan[10], (ftnlen)4);
    nk1 = nval - 11 - nk;
    nk += 11;
    i__1 = -nk1;
    bad_(&i__1, &c__1, "VALD", &sscan[nk - 1], (ftnlen)4);
L291:

/* ---     FETCH AND STORE ALL VECTORS FOR EACH PATCH CORNER */
/* ---     BASE POINTER FOR THIS STORAGE IS IPT+1 */
    ipt = sspad_1.iscan - 1;
    sspad_1.iscan = ipt;
    nlen = npat * 60;
/* ****    THERE IS NOT ENOUGH BUFFER SPACE TO HOLD CORNER DATA */
    *irr = 6;
    if (nlen + ipt > sspad_1.nscnmx) {
	goto L998;
    }

/* RESERV PRESENT NEW SURFACE */
    mode = 5;
    fdummy[1] = (doublereal) (nval - 1);
    apt094_(&mode, fdummy, sscan);

    i__1 = npat;
    for (icur = 1; icur <= i__1; ++icur) {
/* ---     FETCH THE ICUR-TH PATCH */
	lodpch_(sscan, b, iflag, itop, &icur, &c__1);
/* ---     OBTAIN DATA FROM EACH CORNER */
	for (j = 1; j <= 4; ++j) {
	    cnsurf_(&u[j - 1], &v[j - 1], b, spv, iflag, &c__1);
	    for (k = 1; k <= 3; ++k) {
/* ---     SAVE POINT,TANSPL,CRSSPL,TWIST,NORMAL */
		sspad_1.scan[sspad_1.iscan + k - 1] = spv[k - 1];
		sspad_1.scan[sspad_1.iscan + 3 + k - 1] = spv[k + 3];
		sspad_1.scan[sspad_1.iscan + 6 + k - 1] = spv[k + 7];
		sspad_1.scan[sspad_1.iscan + 9 + k - 1] = spv[k + 15];
		sspad_1.scan[sspad_1.iscan + 12 + k - 1] = spv[k + 27];
/* L320: */
	    }
	    sspad_1.iscan += 15;
/* L310: */
	}

/* L300: */
    }
/* ---     CORNER DATA HAS NOW BEEN LOADED */
    if (ibugg_1.ibug != 11) {
	goto L340;
    }
    i__1 = -nlen;
    bad_(&i__1, &c__1, "CORN", &sspad_1.scan[ipt], (ftnlen)4);
L340:

/* ---     PREPARE FOR SAVING TOPOLOGY CALCULATIONS */
    klim = sspad_1.nscnmx << 1;
    kstart = sspad_1.iscan + 1 << 1;
    know = kstart + 4;
    for (k = 1; k <= 4; ++k) {
/* L399: */
	ktop[k + kstart - 1] = 0;
    }
/* ---     FIND TOPOLOGICAL RELATIONS BY COMPARING ALL BOUNDARIES */
/* ---     IBN OF THE  ICUR-TH PATCH TO ALL BOUNDARIES JBN OF THE */
/* ---     PATCHES JCUR=ICUR+1,ICUR+2,... NPAT */

    if (npat <= 1) {
	goto L600;
    }
    nlim1 = npat - 1;
    i__1 = nlim1;
    for (icur = 1; icur <= i__1; ++icur) {

	nlim2 = icur + 1;
/* ---     POINTER TO STORAGE OF CORNER DATA FOR PATCH ICUR. */
	icorn = (icur - 1) * 60 + ipt;
/* ---     DEVELOP DATA FOR EACH BOUNDARY OF THE ICUR TH PATCH. */
	for (ibn = 1; ibn <= 4; ++ibn) {
/* ---      INSERT INDICES TO CORNERS OF IBN-TH BOUNDARY */
	    icp[0] = ibpt[ibn - 1];
	    icp[1] = ibpt[ibn + 3];
	    i__2 = npat;
	    for (jcur = nlim2; jcur <= i__2; ++jcur) {
		jcorn = (jcur - 1) * 60 + ipt;
/* ---     COMPARE EACH BOUNDARY OF THIS PATCH TO OTHERS */
		for (jbn = 1; jbn <= 4; ++jbn) {
		    jcp[0] = ibpt[jbn - 1];
		    jcp[1] = ibpt[jbn + 3];
/* ---     FIRST CHECK FOR IDENTICAL CORNER POINTS */
		    np[0] = 1;
		    np[1] = 2;
/* ---      NOCOMP=0 IF A BOUNDARY MATCH EXISTS, 1 IF IT DOES NOT. */
		    nocomp = 0;

		    k = 1;
L438:
		    if (k > 2) {
			goto L443;
		    }

		    ii = icorn + (icp[k - 1] - 1) * 15;
/* L439: */
		    kk = np[k - 1];
		    jj = jcorn + (jcp[kk - 1] - 1) * 15;
		    w = zero;
		    for (l = 1; l <= 3; ++l) {
/* L441: */
			w += (d__1 = sspad_1.scan[ii + l - 1] - sspad_1.scan[
				jj + l - 1], abs(d__1));
		    }
		    if (w < smalp) {
			goto L440;
		    }
/* ---      MATCH FAILED, SWITCH POINTS AND RETRY */
		    if (np[0] == 1) {
			goto L442;
		    }
/* ---      MATCH FAILED BETWEEN POINTS BOTH WAYS - NO BOUNDARY MATCH */
		    nocomp = 1;
		    goto L443;

L442:
/* ---      SWITCH POINTS AND COMPARE AGAIN */
		    k = 1;
		    np[0] = 2;
		    np[1] = 1;
		    goto L438;

L440:
		    ++k;
		    goto L438;

L443:

/* ---      IF CORNER POINTS DO NOT MATCH, TERMINATE SEARCH BETWEEN */
/* ---      THESE TWO BOUNDARIES, ASSUME NO RELATION. */
		    if (nocomp != 0) {
			goto L430;
		    }

		    if (ibugg_1.ibug != 11) {
			goto L446;
		    }
		    bad_(&c__1, &c__0, "ICUR", &icur, (ftnlen)4);
		    bad_(&c__1, &c__0, "JCUR", &jcur, (ftnlen)4);
		    bad_(&c__1, &c__0, "IBN ", &ibn, (ftnlen)4);
		    bad_(&c_n1, &c__0, "JBN ", &jbn, (ftnlen)4);
		    bad_(&c__2, &c__0, "NP  ", np, (ftnlen)4);
		    bad_(&c__2, &c__0, "ICP ", icp, (ftnlen)4);
		    bad_(&c_n2, &c__0, "JCP ", jcp, (ftnlen)4);
L446:
		    acomp = one;
		    if (np[0] != 1) {
			acomp = -one;
		    }
/* ---     NEXT CHECK FOR IDENTICAL BOUNDARIES */
		    nocomp = 0;
		    for (k = 1; k <= 2; ++k) {
			ii = icorn + (icp[k - 1] - 1) * 15 + icurv[ibn - 1];
			kk = np[k - 1];
			jj = jcorn + (jcp[kk - 1] - 1) * 15 + icurv[jbn - 1];
			for (l = 1; l <= 3; ++l) {
			    w = sspad_1.scan[ii + l - 1] - acomp * 
				    sspad_1.scan[jj + l - 1];
			    if (abs(w) > smalv) {
				nocomp = 1;
			    }
/* L451: */
			}
/* L450: */
		    }
		    if (nocomp != 0) {
			goto L430;
		    }

/* ---     ALL CONDITIONS FOR A CONNECTION HAVE BEEN MET */
/* ---     STORE THE RESULTS */
		    ktop[know - 1] = icur;
		    ktop[know] = ibn;
		    ktop[know + 1] = jcur;
		    ktop[know + 2] = jbn;
		    know += 4;
/* ****    NOT ENOUGH SPACE TO STORE TOPOLOGY RESULTS */
		    *irr = 7;
		    if (know > klim) {
			goto L998;
		    }

L430:
		    ;
		}

/* L420: */
	    }

/* L410: */
	}

/* L400: */
    }

L600:

/* ---     TOPOLOGY RELATIONS HAVE ALL BEEN DETERMINED, NOW CONSOLIDATE */
/* ---     THESE INTO THE SURFACE CANON FORM */
    if (ibugg_1.ibug != 11) {
	goto L499;
    }
    ik = kstart;
L498:
    bad_(&c_n4, &c__0, "TOPO", &ktop[ik - 1], (ftnlen)4);
    ik += 4;
    if (ik < know) {
	goto L498;
    }
L499:
/* ---      SET END OF LIST OF TOPOLOGY TABLE POINTERS */
    kend = know - 4;

/* ---      SAVE CURRENT NVAL FOR TOPOLOGY SIZE CALCULATION */
    nvalsv = nval;

    i__1 = npat;
    for (icur = 1; icur <= i__1; ++icur) {
/* ---      LCON IS NUMBER OF SIDES OF PATCH CONNECTED TO SURFACE */
	lcon = 0;
/* ---     TOPOLOGY POINTER LOCATION IN CURRENT PATCH HEADER */
	ihtop = icur * 6 + 10;
	sscan[ihtop - 1] = (doublereal) nval;
/* ---      SEARCH EACH BOUNDARY IPN OF THE ICUR-TH PATCH */
	for (ipn = 1; ipn <= 4; ++ipn) {
	    lconsv = lcon;
	    sscan[nval - 1] = zero;
/* ---      SEARCH THROUGH THE ENTIRE TOPOLOGY TABLE FOR A MATCH */
	    i__2 = kend;
	    for (k = kstart; k <= i__2; k += 4) {
		if (ktop[k - 1] != icur || ktop[k] != ipn) {
		    goto L525;
		}
		sscan[nval - 1] = (doublereal) (-ktop[k + 1]);
		++lcon;
		++nval;
		goto L520;
L525:
		if (ktop[k + 1] != icur || ktop[k + 2] != ipn) {
		    goto L520;
		}
		sscan[nval - 1] = (doublereal) (-ktop[k - 1]);
		++lcon;
		++nval;
L520:
		;
	    }
	    if (lconsv == lcon) {
		++nval;
	    }
	    sscan[nval - 2] = -sscan[nval - 2];
/* L510: */
	}

	if (lcon > 0) {
	    goto L501;
	}
	cform_(" WARNING. PATCH NOT CONNECTED TO SURFACE", darray_1.darray, &
		c__1, &c__40, (ftnlen)40, (ftnlen)120);
	iconv_(&icur, darray_1.darray, &c__43, &c__6, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	*irr = -9;
L501:
/* L500: */
	;
    }

/* ---      UPDATE SURFACE SIZE AND SIZE OF TOPOLOGY TABLE */
    sscan[7] = (doublereal) (nval - 1);
    sscan[2] = (doublereal) (nval - nvalsv);
    goto L999;

L999:
    *irr = 0;

/* MESH TEST, 1. TOPOLOGY-POINTER */
    n1tt = (integer) sscan[15];
/* LOWER LEFT CORNER AT 1. PATCH ? */
    if (sscan[n1tt - 1] != 0. || sscan[n1tt] != 0.) {
	goto L997;
    }
    if (sscan[n1tt + 1] == 0. && sscan[n1tt + 2] == 0.) {
	goto L997;
    }
/* SPLINE AND CROSS-SPLINE NUMBER */
    nu = (integer) sscan[n1tt + 2];
    if (nu == 0) {
	nu = 2;
    }
    nu1 = nu - 1;
    nv1 = (integer) (sscan[3] / nu1);
    nv = nv1 + 1;
    snu2 = (doublereal) (nu1 - 1);
    ich = 1 - nu1;
/* TEST LOOP */
    i__1 = nv1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = nu1;
	for (j = 1; j <= i__2; ++j) {
	    sch[0] = (doublereal) ich;
	    sch[1] = sch[0] + snu2;
	    sch[2] = sch[1] + 2.;
	    sch[3] = sch[2] + snu2;
	    ++ich;
	    for (k = 1; k <= 4; ++k) {
		if (i__ != 1 && i__ != nv1 && j != 1 && j != nu1) {
		    goto L996;
		}
		if (sscan[n1tt - 1] == 0.) {
		    goto L1000;
		}
		goto L997;
L996:
		if (sscan[n1tt - 1] != sch[k - 1]) {
		    goto L997;
		}
L1000:
		++n1tt;
	    }
	}
    }
    sscan[4] = 2.;
    sscan[8] = (doublereal) nv;
    sscan[9] = (doublereal) nu;

    goto L997;

L998:
    bad_(&c_n1, &c__1, "ERR ", irr, (ftnlen)4);

L997:
    return 0;
} /* srfcom_ */

#undef bcanon
#undef sscan
#undef canon
#undef ktop
#undef can


