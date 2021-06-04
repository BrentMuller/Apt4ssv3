/* GENCRV.f -- translated by f2c (version 20100827).
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
    integer nscnmx, iscan;
    doublereal scan[20000];
} sspad_;

#define sspad_1 sspad_

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__650 = 650;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0001505.V08   *** */

/* Subroutine */ int gencrv_(doublereal *a, doublereal *conchk, doublereal *
	averg, doublereal *type__, integer *ierror)
{
    /* Initialized data */

    static doublereal smal = 1e-6;
    static integer nloc[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer ncmax = 100;
    static char crass[8] = "CROSS   ";
    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal u, w;
    static integer i1, ia, ib, ic, id, nc, ii, jj;
    static logical cr;
    static integer kk, nj;
    static doublereal cv[32];
    static integer nl, nk, nn, nm;
    static doublereal pp[3];
    extern /* Subroutine */ int bad_();
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer loc;
    static doublereal flo;
    static integer nwd, nks, irr, nsp, isx, jsc1, jsc2, ican, iseg, iloc, 
	    nseg, nlen, icrs, junc, ispl, njst;
    static char test[8];
    static integer nloc1, nseg1, nloc2;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    extern logical ckdef_(doublereal *);
    static integer nbase;
    extern /* Subroutine */ int diseg_(integer *, doublereal *, doublereal *, 
	    integer *, integer *);
#define canon ((doublereal *)&_BLNK__1)
    static integer jmode;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer njflo, ilast, nsegr, isize, nsize, icurv, nsplr;
    extern /* Subroutine */ int scurv_(doublereal *, integer *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer ibadsz, icanmx, junchi, icansv;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), curflo_(doublereal *, doublereal *,
	     doublereal *, integer *, integer *), scdump_(integer *, 
	    doublereal *);
    static integer junclo;
    extern /* Subroutine */ int floinv_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer numjnc;
    extern /* Subroutine */ int crsfit_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), cncurv_(doublereal *, 
	    doublereal *, doublereal *, integer *);
    static integer numpat, numcrs, nflowr, isxsav, numspl;

/* ---     MAIN SUBROUTINE FOR CREATING GENCUR SURFACE */
/* ---     INPUT CANONICAL FORM A(2) FOR SURFACE TO BE DEFINED */
/* ---     CONCHK,AVERG,TYPE ARE 3 ARGUMENTS PASSED TO APT107 */
/* ---     PART PROGRAMMER INPUT STREAM IS IN CANON(41 ON) */
/* ---     SURFACE UP TO BUT NOT INCLUDING TOPOLOGY TABLE IS */
/* ---     DEFINED IN CANON(41) ON.  SSPAD IS USED AS A SCRATCH */
/* ---     AREA FOR READING CURVES AND MANIPULATING THEM. */
/* ---     OUTPUT IERROR IS NOT ZERO FOR AN ERROR */
/* ---     MAIN OUTPUT IS IN CANON(41 ON) */

/* ---     BLANK COMMON CAN CONTAINS THE PART PROGRAMMERS INPUT */
/* ---     THIS IS TRANSFERRED TO THE ARRAY SCAN AND THEN CAN IS */
/* ---     USED TO BUILD UP THE CANON FORM OF THE GENCUR SURFACE */
/* ---     THE AVAILABLE SIZE OF CAN IS HELD IN MAXLDA */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ---     THE SCAN ARRAY IS USED AS A WORKING BUFFER OF TEMPORARY */
/* ---     DATA.  IT HOLDS THE PP INPUT AND VARIOUS INPUT CURVES. */
/* ---     NSCNMX IS THE MAXIMUM SPACE IN SCAN AND ISCAN POINTS */
/* ---     TO THE LAST USED LOCATION IN SCAN. */


/* .... SCULPTURED SURFACES SCRATCH PAD AREA */




/* ---     NLOC HOLDS POINTERS TO THE LOCATIONS OF SPLINE AND */
/* ---     CROSS CURVES HELD IN THE SCAN ARRAY. NC IS THE LAST */
/* ---     USED LOCATION IN NLOC AND NCMAX IS THE SIZE OF NLOC */



/* ---     INITIALIZE VARIOUS POINTERS AND COUNTERS */
/* ---     CR IS TRUE IF CROSS SPLINE CURVES ARE ENTERED */
    cr = FALSE_;
/* ---     NUMSPL IS THE TOTAL NUMBER OF INPUT SPLINE CURVES */
    numspl = 0;
/* ---     NUMCRS IS THE TOTAL NUMBER OF INPUT CROSS CURVES */
    numcrs = 0;
/* ---     ISCAN IS THE POINTER TO THE LAST USED SPACE IN SCAN ARRAY */
    sspad_1.iscan = 0;
/* ---     NSEG IS THE TOTAL NUMBER OF SEGMENTS PER INPUT CURVE */
    nseg = 0;
/* ---     NC IS THE POINTER TO THE LAST USED SPACE IN NLOC */
    nc = 0;
/* ---     NLEN IS THE TOTAL LENGTH OF PART PROGRAMMER INPUT DATA */
    nlen = (integer) can[4];
/* ---     TRANSFER PART PROGRAMMERS INPUT TO THE SCAN ARRAY */
    i__1 = nlen;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sspad_1.scan[i__ - 1] = can[i__ - 1];
	can[i__ - 1] = zero;
/* L10: */
    }
    sspad_1.iscan = nlen;

/* ---     ISX WILL BE AN INDEX FOR SEARCHING THE SCAN ARRAY */
    isx = 9;
L100:
    if (isx >= nlen) {
	goto L199;
    }
/* ---     DATA SHOULD REPRESENT EITHER AN SCURV OR THE WORD CROSS */
    holfrm_(&sspad_1.scan[isx], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, crass, (ftnlen)8, (ftnlen)8) != 0) {
	goto L110;
    }
/* ---     THE WORD CROSS HAS BEEN ENCOUNTERED */
/* ****    THE WORD CROSS WAS ENCOUNTERED TWICE */
    *ierror = 5;
    if (cr) {
	goto L9998;
    }
/* ****    LESS THAN TWO SPLINE CURVES WERE INPUT BEFORE CROSS */
    *ierror = 6;
    if (numspl < 2) {
	goto L9998;
    }
/* ---     SAVE THE STARTING INDEX TO CROSS CURVE DATA */
    isxsav = isx + 2;
    cr = TRUE_;
    goto L198;

/* ---     A CURVE HAS BEEN ENCOUNTERED */
L110:
    if (! ckdef_(&sspad_1.scan[isx - 1])) {
	goto L120;
    }
/* ****    INPUT CURVE HAS NOT BEEN DEFINED CORRECTLY */
    *ierror = 7;
    goto L9998;
L120:
    if (numspl > 0) {
	goto L130;
    }
/* ---     LOAD THE FIRST CURVE ONLY */
    jmode = 2;
    apt094_(&jmode, &sspad_1.scan[isx - 1], &sspad_1.scan[sspad_1.iscan]);
/* ****    CURVE COULD NOT BE SUCCESSFULLY RETRIEVED */
    *ierror = 8;
    if (jmode != 2) {
	goto L9998;
    }
/* ---     ENTER CURVE LOCATION INTO DIRECTORY TABLE */
    ++nc;
    nloc[nc - 1] = sspad_1.iscan + 1;
/* ---     OBTAIN SEGMENT COUNT FROM THIS CURVE */
    nseg = (integer) sspad_1.scan[sspad_1.iscan + 7];
    sspad_1.iscan = (integer) (sspad_1.iscan + sspad_1.scan[sspad_1.iscan + 
	    11]);
/* ****    FIRST INPUT CURVE WAS NOT OF THE FLOW TYPE */
    *ierror = 9;
    if (nseg < 1) {
	goto L9998;
    }
L130:
    if (! cr) {
	++numspl;
    }
    if (cr) {
	++numcrs;
    }
L198:
    isx += 2;
    goto L100;
L199:

/* ---     NOW BEGIN PREPARATION OF THE SURFACE CANON FORM IN CAN */
/* ---     ALL INPUT CURVES MUST BE LOADED INTO THE SCAN ARRAY */
    numpat = (numspl - 1) * nseg;
    j = numpat * 6 + 10;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L210: */
	can[i__ - 1] = zero;
    }
    can[2] = (doublereal) (numpat << 2);
    can[3] = (doublereal) numpat;
    can[4] = 2.f;
    can[5] = 5.f;
    can[6] = one;
    can[8] = (doublereal) numspl;
    can[9] = (doublereal) (nseg + 1);

/* ---     THIRD PHASE, LOAD ALL OF THE SPLINE CURVES INTO THE SCAN ARRAY */
/* ---     SKIP THE FIRST CURVE, SINCE IT HAS ALREADY BEEN LOADED */
    isx = 11;
L300:
    holfrm_(&sspad_1.scan[isx], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, crass, (ftnlen)8, (ftnlen)8) == 0 || isx >= nlen) {
	goto L399;
    }
/* ****    THE CURVE DIRECTORY TABLE SIZE HAS BEEN EXCEEDED */
    *ierror = 10;
    if (nc + 1 > ncmax) {
	goto L9998;
    }
/* ---     CONSIDER THE ANTICIPATED SIZE OF THIS CURVE */
    isize = (integer) sspad_1.scan[isx];
/* ****    THERE IS NOT ENOUGH BUFFER SPACE TO HOLD THIS SPLINE CURVE */
    *ierror = 11;
    if (isize + sspad_1.iscan > sspad_1.nscnmx) {
	goto L9998;
    }
    jmode = 2;
    apt094_(&jmode, &sspad_1.scan[isx - 1], &sspad_1.scan[sspad_1.iscan]);
/* ****    INPUT SPLINE CURVE COULD NOT BE FETCHED */
    *ierror = 12;
    if (jmode != 2) {
	goto L9998;
    }
    iseg = (integer) sspad_1.scan[sspad_1.iscan + 7];
/* ****    THE NUMBER OF SEGMENTS IN TWO INPUT SPLINE CURVES WAS UNEQUAL */
    *ierror = 13;
    if (iseg != nseg) {
	goto L9998;
    }
/* ---     UPDATE DIRECTORY TABLE OF CURVE LOCATION */
    ++nc;
    nloc[nc - 1] = sspad_1.iscan + 1;
    sspad_1.iscan = (integer) (sspad_1.iscan + sspad_1.scan[sspad_1.iscan + 
	    11]);
/* L390: */
    isx += 2;
    goto L300;

L399:

/* ---     PHASE 4.  ONE-BY-ONE LOAD CROSS CURVES INTO SCAN ARRAY */
/* ---     AND COMPARE THEM TO SPLINE JUNCTIONS TO DETERMINE */
/* ---     THEIR RELATIVE LOCATION. */
/* ---     FIRST, ZERO OUT THIS PART OF THE DIRECTORY TABLE */
/* ****    THERE IS NOT ENOUGH ROOM IN THE DIRECTORY FOR CROSS CURVES */
    *ierror = 14;
    if (nc + nseg + 1 > ncmax) {
	goto L9998;
    }
/* ---     ZERO OUT THE CROSS PORTION OF THE DIRECTORY TABLE */
    nseg1 = nseg + 1;
    i__1 = nseg1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nloc[i__ + numspl - 1] = 0;
/* L401: */
    }
/* ---     THE NEXT SECTION IS TO READ IN CROSS CURVES */
/* ---     IF THERE ARE NO CROSS CURVES, SKIP THIS SECTION */
    if (! cr || numcrs < 1) {
	goto L500;
    }

/* ---     BEGIN LOADING CROSS CURVES (FROM THE PREVIOUS SAVE POINT) */
    isx = isxsav;

L420:
    if (isx >= nlen) {
	goto L499;
    }
    isize = (integer) sspad_1.scan[isx];
/* ****    THERE IS NOT ENOUGH BUFFER SPACE TO LOAD A CROSS CURVE */
    *ierror = 15;
    if (isize + sspad_1.iscan > sspad_1.nscnmx) {
	goto L9998;
    }
    jmode = 2;
    apt094_(&jmode, &sspad_1.scan[isx - 1], &sspad_1.scan[sspad_1.iscan]);
/* ****    CROSS CURVE COULD NOT BE FETCHED */
    *ierror = 16;
    if (jmode != 2) {
	goto L9998;
    }
    iseg = (integer) sspad_1.scan[sspad_1.iscan + 7];
/* ****    NUMBER OF SEGMENTS IN CROSS CURVE DID NOT MATCH NO. SPLINES */
    *ierror = 17;
    if (iseg + 1 != numspl) {
	goto L9998;
    }

/* ---     A MAJOR TASK- IDENTIFY WHICH CROSS CURVE THIS IS. */
/* ---     ISPL IS THE PREVIOUS SPLINE POINT WHICH MATCHED A */
/* ---     CROSS CURVE POINT */
    ispl = 1;
L429:
/* ---     ICRS IS THE PRESENT POINT ON THE CROSS CURVE BEING EXAMINED */
    icrs = 1;
L430:
    if (icrs > numspl) {
	goto L469;
    }
/* ---     CALCULATE THE CURVE POINT */
    u = (doublereal) (icrs - 1);
    curflo_(&u, &sspad_1.scan[sspad_1.iscan], cv, &c__0, &c__0);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L431: */
	pp[i__ - 1] = cv[i__ - 1];
    }
/* ---     NOW SCAN THRU THE ICR-TH SPLINE FOR A MATCH ON PP */
    nl = nloc[icrs - 1];
    nsp = ispl;
L440:
    if (nsp > nseg1) {
	goto L459;
    }
    u = (doublereal) (nsp - 1);
    curflo_(&u, &sspad_1.scan[nl - 1], cv, &c__0, &c__0);
    w = (d__1 = cv[0] - pp[0], abs(d__1)) + (d__2 = cv[1] - pp[1], abs(d__2)) 
	    + (d__3 = cv[2] - pp[2], abs(d__3));
    if (w > 1e-4f) {
	goto L458;
    }
/* ---     JUNCTION POINTS OF CROSS CURVE AND SPLINE MATCH HERE */
    if (nsp == ispl) {
	goto L468;
    }
/* ---     UPDATE ISPL AND RESTART */
    ispl = nsp;
    goto L429;

L458:
    ++nsp;
    goto L440;

L459:
/* ****    THERE IS NO MATCH AT A JUNCTION PT BETWEEN A SPLINE AND CROSS */
    *ierror = 18;
    goto L9998;

L468:
    ++icrs;
    goto L430;
L469:
/* ---     MATCH HAS BEEN ACHIEVED, CROSS CURVE IS NUMBER ICRS */
/* ****    ERROR, ANOTHER CROSS CURVE WAS ENTERED THRU SAME POINTS */
    *ierror = 19;
    if (nloc[numspl + ispl - 1] != 0) {
	goto L9998;
    }
    nloc[numspl + ispl - 1] = sspad_1.iscan + 1;
    sspad_1.iscan = (integer) (sspad_1.iscan + sspad_1.scan[sspad_1.iscan + 
	    11]);
    isx += 2;
    goto L420;

L499:

L500:
/* ---     ALL CROSS CURVES HAVE BEEN SAVED , NOW GENERATE */
/* ---     ALL  CROSS CURVES NOT INPUT BY USER */

/* ---     FIRST CHECK WHETHER A RULED SURFACE IS INDICATED */
    if (numspl != 2 || numcrs > 0) {
	goto L600;
    }

/* ---     PHASE 5.  DEFINTION OF A RULED SURFACE. */
/* ---     THE SURFACE IS RULED PROVIDED THAT NO CROSS SPLINE */
/* ---     OR NORMAL CONSTRAINTS EXIST */
    i__1 = numspl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nl = nloc[i__ - 1] - 1;
	nloc1 = (integer) (sspad_1.scan[nl + 1] * 24.f - 4.f + nl);
	nloc2 = (integer) (nloc1 + sspad_1.scan[nl + 3] * 24.f);
	i__2 = nloc2;
	for (j = nloc1; j <= i__2; j += 24) {
	    w = (d__1 = sspad_1.scan[j - 1] - one, abs(d__1));
	    if (w < smal) {
		goto L600;
	    }
	    w = (d__1 = sspad_1.scan[j + 3] - one, abs(d__1));
	    if (w < smal) {
		goto L600;
	    }
/* L520: */
	}
/* L510: */
    }

/* ---     ALL CONDITIONS FOR A RULED SURFACE HAVE BEEN MET */
/* ---     FINISH THE DEFINITION OF THE RULED SURFACE NOW */
    numpat = nseg;
    ican = nseg * 6 + 10;

/* ---     DISSECT CURVES INTO SEGMENT CURVES AND SET UP RULED PATCHES */
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iloc = (i__ - 1) * 6 + 10;
	i__2 = numspl;
	for (j = 1; j <= i__2; ++j) {
	    nl = nloc[j - 1];
	    icanmx = maxlda_1.maxlda - ican;
	    diseg_(&i__, &sspad_1.scan[nl - 1], &can[ican], &icanmx, ierror);
/* ****    ERROR IN DISSEGMENTING CURVE */
	    if (*ierror != 0) {
		goto L9998;
	    }
	    ++iloc;
	    can[iloc - 1] = (doublereal) (ican + 1);
	    ican = (integer) (ican + can[ican + 11]);
/* L540: */
	}
/* ---     TYPE FLAG INDICATES A BLEND BETWEEN TWO SPLINES */
	can[iloc + 2] = -1.f;
	can[iloc + 3] = zero;
/* L530: */
    }
    can[1] = (doublereal) (ican - (nseg * 6 + 11));
    can[7] = can[1] + can[2] + (numpat * 6 + 10);


    goto L9997;

/* ---     CROSS FIT LIKE SEGMENT JUNCTION POINTS TO OBTAIN GOOD */
/* ---     CROSS SLOPE CONSTRAINTS */
L600:
    i__ = 1;
L610:
    if (i__ > nseg1) {
	goto L699;
    }
/* ---     IF A CROSS CURVE HAS ALREADY BEEN ENTERED, SKIP TO NEXT JNCT. */
    if (nloc[numspl + i__ - 1] != 0) {
	goto L690;
    }
/* ---     CHECK FOR AVAILABLE SPACE TO FIT CROSS CURVE */
    nsize = (numspl + 1) * 24;
/* ****    THERE IS NOT ENOUGH ROOM IN THE BUFFER TO FIT THIS CROSS CURVE */
    *ierror = 20;
    if (nsize + sspad_1.iscan > sspad_1.nscnmx) {
	goto L9998;
    }
    u = zero;
    iseg = i__;
    if (i__ > nseg) {
	u = one;
    }
    iseg = min(nseg,i__);
    j = 1;
/* ---     PREPARE THE INPUT CURVE HEADER TABLE */
    for (l = 1; l <= 24; ++l) {
/* L615: */
	sspad_1.scan[sspad_1.iscan + l - 1] = zero;
    }
    sspad_1.scan[sspad_1.iscan + 1] = one;
    sspad_1.scan[sspad_1.iscan + 2] = 2.f;
    sspad_1.scan[sspad_1.iscan + 3] = (doublereal) numspl;
L620:
/* ---     LOAD SPLINE CURVES ONE AT A  TIME TO OBTAIN POINT OR */
/* ---     VECTOR DATA AT JUNCTION POINTS I */
    if (j > numspl) {
	goto L650;
    }
/* ---     SET ADDRESS OF SPLINE J */
    nl = nloc[j - 1] - 1;
    curflo_(&u, &sspad_1.scan[nl], cv, &c__2, &iseg);
/* ---     MOVE RELEVANT POINTS AND VECTOR CONSTRAINTS INTO BUFFER */
    nbase = j * 24 + sspad_1.iscan;
/* ---     ZERO OUT THE J-TH POINT BLOCK FIRST */
    for (l = 1; l <= 24; ++l) {
/* L630: */
	sspad_1.scan[nbase + l - 1] = zero;
    }
    for (l = 1; l <= 3; ++l) {
	sspad_1.scan[nbase + l - 1] = cv[l - 1];
	if ((d__1 = cv[19] - one, abs(d__1)) < smal) {
	    sspad_1.scan[nbase + 4 + l - 1] = cv[l + 15];
	}
	if ((d__1 = cv[31] - one, abs(d__1)) < smal) {
	    sspad_1.scan[nbase + 12 + l - 1] = cv[l + 27];
	}
	sspad_1.scan[nbase + 8 + l - 1] = cv[l + 3];
/* L640: */
    }
    if ((d__1 = cv[19] - one, abs(d__1)) < smal) {
	sspad_1.scan[nbase + 7] = one;
    }
    if ((d__1 = cv[31] - one, abs(d__1)) < smal) {
	sspad_1.scan[nbase + 15] = one;
    }
    sspad_1.scan[nbase + 11] = one;
    sspad_1.scan[nbase + 16] = one;

    ++j;
    goto L620;
/* --- */
L650:
    if (ibugg_1.ibug == 11) {
	scdump_(&c__650, &sspad_1.scan[sspad_1.iscan]);
    }
/* ---     NOW DEFINE A SYNTHETIC CURVE IN THE CROSS DIRECTION */
    irr = 0;
    scurv_(&sspad_1.scan[sspad_1.iscan], &irr);
/* ****    ERROR IN TRYING TO DEFINE A CROSS CURVE */
    *ierror = 21;
    if (irr != 0) {
	goto L9998;
    }

    sspad_1.scan[sspad_1.iscan + 4] = sspad_1.scan[sspad_1.iscan + 1] * 24.f 
	    + one;
    sspad_1.scan[sspad_1.iscan + 11] = numspl * 24.f;
/* ---     IF CROSS CURVES HAVE BEEN INPUT BY THE USER, THEN INTERNALLY */
/* ---     GENERATED CROSS CURVES MUST HAVE A FLOW STRUCTURE APPENDED */

    if (numcrs < 1) {
	goto L680;
    }

/* ---     NOW APPEND AN IDENTITY-TYPE FLOW STRUCTURE */
    nsize = sspad_1.iscan + numspl * 40;
/* ****    THERE IS NOT ENOUGH ROOM FOR FLOW STRUCTURE OF A CROSS CURVE */
    *ierror = 23;
    if (nsize > icanmx) {
	goto L9998;
    }

/* ---     NOW SETUP THE COMPLETE HEADER TABLE FOR A FLOW CURVE */
    sspad_1.scan[sspad_1.iscan + 4] = (doublereal) (sspad_1.iscan + 25);
    sspad_1.scan[sspad_1.iscan + 5] = (doublereal) (numspl - 1);
    sspad_1.scan[sspad_1.iscan + 6] = (doublereal) (numspl * 24 + 1);
    sspad_1.scan[sspad_1.iscan + 7] = sspad_1.scan[sspad_1.iscan + 5];
    sspad_1.scan[sspad_1.iscan + 8] = sspad_1.scan[sspad_1.iscan + 6] + (
	    numspl - 1 << 2);
    sspad_1.scan[sspad_1.iscan + 9] = (doublereal) (numspl - 1 << 1);
    sspad_1.scan[sspad_1.iscan + 10] = sspad_1.scan[sspad_1.iscan + 8] + (
	    numspl - 1 << 2);
    sspad_1.scan[sspad_1.iscan + 11] = sspad_1.scan[sspad_1.iscan + 10] + (
	    numspl - 1 << 3);
    sspad_1.scan[sspad_1.iscan + 12] = one;
/* ---     NOW FILL IN FLOW, SEGMENT, AND FLOW SPLINE DATA */
/* ---     KEEP TRACK OF EACH TYPE OF DATA WITH ITS OWN POINTER. */
    nflowr = (integer) (sspad_1.scan[sspad_1.iscan + 6] - 5.f);
    nsegr = (integer) (sspad_1.scan[sspad_1.iscan + 8] - 5.f);
    nsplr = (integer) (sspad_1.scan[sspad_1.iscan + 10] - 9.f);
/* ---     LOOP THRU SEGMENT BY SEGMENT AND FILL IN FLOW DATA */
    nn = numspl - 1;
    i__1 = nn;
    for (l = 1; l <= i__1; ++l) {
/* ---     INCREMENT SEGMENT POINTERS */
	nflowr += 4;
	nsegr += 4;
	nsplr += 8;
/* ---     FILL IN FLOW DATA FOR THE L-TH ARC */
	sspad_1.scan[nflowr] = (doublereal) nsplr;
	sspad_1.scan[nflowr + 1] = 2.f;
	sspad_1.scan[nflowr + 2] = 4.0001f;
	sspad_1.scan[nflowr + 3] = one;
/* ---     FILL IN SEGMENT SUMMARY DATA */
	sspad_1.scan[nsegr] = (doublereal) (l - 1);
	sspad_1.scan[nsegr + 1] = (doublereal) l;
	sspad_1.scan[nsegr + 2] = one;
	sspad_1.scan[nsegr + 3] = one;
/* ---     FIRST SET UP AN IDENTITY FLOW SPLINE */
	sspad_1.scan[nsplr] = zero;
	sspad_1.scan[nsplr + 1] = zero;
	sspad_1.scan[nsplr + 2] = one;
	sspad_1.scan[nsplr + 3] = zero;
	sspad_1.scan[nsplr + 4] = one;
	sspad_1.scan[nsplr + 5] = one;
	sspad_1.scan[nsplr + 6] = one;
	sspad_1.scan[nsplr + 7] = zero;
/* L660: */
    }

L680:

/* ---     CONSOLIDATE THIS CROSS CURVE INTO THE BUFFER AREA */
    nloc[numspl + i__ - 1] = sspad_1.iscan + 1;

    if (numcrs < 1) {
	sspad_1.iscan += numspl * 24;
    }
    if (numcrs > 0) {
	sspad_1.iscan = (integer) (sspad_1.iscan + sspad_1.scan[sspad_1.iscan 
		+ 11]);
    }

L690:
    ++i__;
    goto L610;

L699:
/* ---     NOW ADD CROSS VECTORS AT ALL UNSPECIFIED POINTS */
/* ---    THIS IS ACCOMPLISHED BY CROSS SPLINING THE SURFACE FOR */
/* ---    FOR EACH AND EVERY USER INPUT POINT. */

/* ---    FIRST CHECK FOR STORAGE SPACE */
    nsize = sspad_1.iscan + (numspl + 1) * 24;
/* ****    THERE IS NOT ENOUGH ROOM TO DETERMINE CROSS VECTOR BY SPLINING */
    *ierror = 24;
    if (nsize > sspad_1.nscnmx) {
	goto L9998;
    }

/* ---     MAJOR LOOP, DETERMINE UNSPECIFIED POINTS ON EACH SPLINE */
/* ---     SKIP THIS LOOP IF THERE ARE ONLY TWO SPLINES */
    if (numspl <= 2) {
	goto L709;
    }

    i__1 = numspl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nl = nloc[i__ - 1] - 1;
/* ---     EXAMINE EACH JUNCTION POINT OF THE ITH SPLINE */
	nj = (integer) sspad_1.scan[nl + 3];
	if (nj == 1) {
	    goto L721;
	}

/* ---     SET UP PARAMETERS FOR DETECTING FLOW JUNCTIONS */
	njflo = (integer) (sspad_1.scan[nl + 5] * 4.f + one);
	njst = (integer) sspad_1.scan[nl + 6];

	i__2 = nj;
	for (nk = 1; nk <= i__2; ++nk) {
	    junc = nk;
/* ---     SKIP CROSS CALCULATIONS FOR SEGMENT JUNCTION POINTS */
	    i__3 = njflo;
	    for (ii = 1; ii <= i__3; ii += 4) {
		junclo = (integer) sspad_1.scan[nl + njst + ii - 2];
		junchi = (integer) (junclo + sspad_1.scan[nl + njst + ii - 1])
			;
/* ---     SKIP CALCULATION IF JUNC EQUALS ONE OF THESE */
		if (junc == junclo || junc == junchi) {
		    goto L720;
		}
/* ---     TERMINATE SEARCH AND CONTINUE WHEN JUNC IS BIG */
		if (junc > junchi) {
		    goto L723;
		}
/* L722: */
	    }

L723:

	    loc = junc * 24 + 16;
/* ---     SKIP IF A CROSS VECTOR IS ALREADY THERE */
	    if ((d__1 = sspad_1.scan[nl + loc + 3] - one, abs(d__1)) < smal) {
		goto L720;
	    }
/* ---     NOW PREPARE THE HEADER TABLE FOR SPLINING */
	    for (nn = 5; nn <= 24; ++nn) {
/* L730: */
		sspad_1.scan[sspad_1.iscan + nn - 1] = zero;
	    }
	    sspad_1.scan[sspad_1.iscan + 1] = one;
	    sspad_1.scan[sspad_1.iscan + 2] = 2.f;
	    sspad_1.scan[sspad_1.iscan + 3] = (doublereal) numspl;
/* ---     FIND THE SEGMENT NUMBER AND FLOW VALUE AT ARC JUNCTIONS */
	    u = (doublereal) junc;
	    floinv_(&u, &sspad_1.scan[nl], &flo, &iseg);
/* ---     PICK A POINT OFF OF EACH SPLINE CURVE WITH THIS FLOW */
/* ---     AND SEGMENT VALUE AND PLACE IT INTO A POINT BLOCK OF */
/* ---     THE BUFFERED SCAN ARRAY */

	    i__3 = numspl;
	    for (k = 1; k <= i__3; ++k) {
		jsc1 = k * 24 + 1;
		jsc2 = jsc1 + 23;
		i__4 = jsc2;
		for (j = jsc1; j <= i__4; ++j) {
		    sspad_1.scan[j + sspad_1.iscan - 1] = zero;
/* L750: */
		}
		sspad_1.scan[jsc1 + sspad_1.iscan + 15] = one;
/* ---     NOW RETRIEVE A POINT FROM THE K-TH SPLINE */
		nks = nloc[k - 1];
		curflo_(&flo, &sspad_1.scan[nks - 1], cv, &c__0, &iseg);
		for (j = 1; j <= 3; ++j) {
/* L760: */
		    sspad_1.scan[sspad_1.iscan + jsc1 + j - 2] = cv[j - 1];
		}
/* L740: */
	    }

/* ---     NOW FIT A SPLINE THRU THESE POINTS */
	    scurv_(&sspad_1.scan[sspad_1.iscan], &irr);
/* ****    CROSS FITTING FAILED AT A SEGMENT INTERIOR POINT */
	    *ierror = 25;
	    if (irr != 0) {
		goto L9998;
	    }
/* ---     RETRIEVE AND STORE BOTH THE ENTERING AND EXITING TANGENTS */
/* ---     FIRST STORE THE EXITING VECTOR */
	    nn = i__ * 24;
	    u = zero;
	    if (i__ == numspl) {
		nn += -24;
	    }
	    if (i__ == numspl) {
		u = one;
	    }
	    cncurv_(&u, &sspad_1.scan[sspad_1.iscan + 1 + nn - 1], cv, &c__1);
/* ---     STORE THIS VECTOR AS A CROSS CONSTRAINT OF THE SPLINE */
	    for (l = 1; l <= 3; ++l) {
/* L770: */
		sspad_1.scan[nl + loc + l - 1] = cv[l + 3];
	    }
	    sspad_1.scan[nl + loc + 3] = one;
/* ---     NEXT RETRIEVE AND STORE THE ENTERING VECTOR */
	    u = one;
	    nn = (i__ - 1) * 24;
	    if (i__ == 1) {
		u = zero;
	    }
	    if (i__ == 1) {
		nn += 24;
	    }
	    cncurv_(&u, &sspad_1.scan[sspad_1.iscan + 1 + nn - 1], cv, &c__1);
	    for (l = 1; l <= 3; ++l) {
/* L780: */
		sspad_1.scan[nl + loc + l + 3] = cv[l + 3];
	    }
	    sspad_1.scan[nl + loc + 7] = one;

L720:
	    ;
	}

L721:

/* L710: */
	;
    }

L709:
/* ---     END OF LOOP TO GENERATE CROSS CONSTRAINTS ON SPLINES */


/* L800: */
/* ---     CASE OF A GENCUR SURFACE WITH NO CROSS SPLINES */
/* ---     FETCH CURVES AND DECOMPOSE SURFACE DEFINITION INTO A */
/* ---     PATCH STRUCTURE */

    nm = numspl - 1;
/* ---     ICAN IS THE LAST USED LOCATION IN THE CAN ARRAY */
    ican = nseg * 6 * nm + 10;

/* ---     GENERATE SURFACE ON A PATCH-BY-PATCH BASIS */

    i__1 = nm;
    for (j = 1; j <= i__1; ++j) {
	i__2 = nseg;
	for (i__ = 1; i__ <= i__2; ++i__) {

	    numpat = i__ + (j - 1) * nseg;
/* ---     ILOC IS THE LAST USED LOCATION IN THE PATCH POINTER TABLE */
	    iloc = (numpat - 1) * 6 + 10;

/* ---     LOAD TWO SPLINE CURVE BOUNDARIES OF THIS PATCH */
	    for (k = 1; k <= 2; ++k) {

		icurv = nloc[j + k - 2];
		icanmx = maxlda_1.maxlda - ican;
		diseg_(&i__, &sspad_1.scan[icurv - 1], &can[ican], &icanmx, 
			ierror);
/* ****    DISSECTION OF A SPLINE CURVE FAILED */
		if (*ierror != 0) {
		    goto L9998;
		}
		++iloc;
		can[iloc - 1] = (doublereal) (ican + 1);
		ican = (integer) (ican + can[ican + 11]);
/* L820: */
	    }

/* ---     NOW LOAD THE CROSS CURVES IN A SIMILAR FASHION, BUT */
/* ---     DO NOT SAVE THEM UNLESS CROSS CURVES HAVE BEEN ENTERED */

	    icansv = ican;
	    for (k = 1; k <= 2; ++k) {

		icurv = nloc[numspl + i__ + k - 2];
		icanmx = maxlda_1.maxlda - ican;
		diseg_(&j, &sspad_1.scan[icurv - 1], &can[ican], &icanmx, 
			ierror);
/* ****    A CROSS CURVE COULD NOT BE DISSECTED */
		if (*ierror != 0) {
		    goto L9998;
		}
		++iloc;
		can[iloc - 1] = (doublereal) (ican + 1);
		ican = (integer) (ican + can[ican + 11]);
/* L830: */
	    }

/* ---     NOW COMPLETE ALL BOUNDARY CURVES BY FILLING IN */
/* ---     ALL CROSS VECTORS AT ARC JUNCTIONS */
	    ia = (integer) can[iloc - 4];
	    ib = (integer) can[iloc - 3];
	    ic = (integer) can[iloc - 2];
	    id = (integer) can[iloc - 1];

/* ---     SPECIAL LOGIC WHERE DUAL(INCOMING AND OUTGOING) TANGENTS */
/* ---     HAVE BEEN GENERATED EARLIER.  SKIP IF 2 OR FEWER SPLINES */
	    if (numspl < 3) {
		goto L839;
	    }

/* ---     RETAIN EXITING VECTORS FOR CAN(IA) AND ENTERING VECTORS FOR IB. */
	    numjnc = (integer) can[ia + 2];
	    if (numjnc < 2) {
		goto L834;
	    }
	    i__3 = numjnc;
	    for (ii = 2; ii <= i__3; ++ii) {
		kk = (ii - 1) * 24 + 15;
		for (jj = 1; jj <= 4; ++jj) {
		    can[ia + kk + 4 + jj - 1] = zero;
/* L833: */
		}
/* L832: */
	    }
L834:
/* ---     NEXT REARRANGE THE ENTERING VECTORS FOR CAN(IB) */
	    numjnc = (integer) can[ib + 2];
	    if (numjnc < 2) {
		goto L838;
	    }
	    i__3 = numjnc;
	    for (ii = 2; ii <= i__3; ++ii) {
		kk = (ii - 1) * 24 + 15;
		for (jj = 1; jj <= 4; ++jj) {
		    can[ib + kk + jj - 1] = can[ib + kk + jj + 3];
		    can[ib + kk + jj + 3] = zero;
/* L837: */
		}
/* L836: */
	    }
L838:

L839:

/* ---     NOW FIT ANY UNRESOLVED CROSS VECTORS */
/* ---     SINCE ALL TANGENTS HAVE ALREADY BEEN DETERMINED , SET BYPASS */
/* ---     FLAG FOR CRSFIT LOGIC  --  CRSFIT IS CALLED FOR DISPLAY */
	    *ierror = 0;
	    if (numspl > 2) {
		*ierror = -11;
	    }
	    crsfit_(&can[ia - 1], &can[ib - 1], &can[ic - 1], &can[id - 1], 
		    ierror);
/* ****    FILLING IN OF CROSS SLOPES ON SPLINE CURVES FAILED */
	    if (*ierror != 0) {
		goto L9998;
	    }

/* ---     FILL IN IC ID CURVES IF NUMCRS IS NOT ZERO. */
	    if (numcrs > 0) {
		crsfit_(&can[ic - 1], &can[id - 1], &can[ia - 1], &can[ib - 1]
			, ierror);
	    }
/* ****    FILLING IN OF CROSS SLOPES ON CROSS CURVES FAILED */
	    if (*ierror != 0) {
		goto L9998;
	    }

/* ---     NOW FILL IN REMAINDER OF PATCH HEADER TABLE */

	    if (numcrs > 0) {
		goto L840;
	    }
/* ---     FOR SPLINE CURVES ONLY, CUT BACK SPACE FROM CROSS CURVES */
	    ican = icansv;
	    can[iloc - 2] = zero;
	    can[iloc - 1] = zero;
	    ++iloc;
	    can[iloc - 1] = -2.f;
	    ++iloc;
	    can[iloc - 1] = zero;
	    goto L810;

L840:
	    ++iloc;
	    can[iloc - 1] = -22.f;
	    ++iloc;
	    can[iloc - 1] = zero;

L810:
	    ;
	}
    }

/* ---     FILL IN SURFACE HEADER TABLE */

/* ---     LAST PATCH,LAST BOUNDARY LOCATION */
    ilast = (integer) can[numpat * 6 + 5];
    if (numcrs > 0) {
	ilast = (integer) can[numpat * 6 + 7];
    }
/* ---     VALUE TABLE SIZE */
    can[1] = can[ilast + 10] + (ilast - 10 - numpat * 6 - 1);
/* ---     TOPOLOGY TABLE SIZE */
    can[2] = (doublereal) (numpat << 2);
/* ---     NUMBER OF PATCHES IN SURFACE */
    can[3] = (doublereal) numpat;
/* ---     SURFACE TYPE, MESH TYPE */
    can[4] = 2.f;
/* ---     SURFACE SUBTYPE, GENCUR */
    can[5] = 5.f;
/* ---     SIGN OF SURFACE NORMAL */
    can[6] = one;
/* ---     TOTAL SIZE OF THIS SURFACE */
    can[7] = numpat * 6 + 10 + can[1] + can[2];
/* ---     NUMBER OF SPLINES */
    can[8] = (doublereal) numspl;
/* ---     NUMBER OF CROSS SPLINES OR SEGMENT JUNCTION POINTS PER SPLINE */
    can[9] = (doublereal) nseg1;

    ibadsz = (integer) can[7];
    if (ibugg_1.ibug == 11) {
	bad_(&ibadsz, &c__1, "CAN ", can, (ftnlen)4);
    }

/* ---     END OF PATCH GENERATING LOOP */

    goto L9997;

/* 900 CONTINUE */
/*     GO TO 9997 */

L9997:
    *ierror = 0;
    goto L9999;

L9998:
/* ---     GENERATE DEBUG PRINTOUT IF IBUG FLAG IS SET */
    if (ibugg_1.ibug != 11) {
	goto L9996;
    }
    bad_(&c__1, &c__0, "IRR ", &irr, (ftnlen)4);
    bad_(&c__1, &c__0, "IERR", ierror, (ftnlen)4);
    bad_(&c__1, &c__0, "NUMS", &numspl, (ftnlen)4);
    bad_(&c__1, &c__0, "ISCN", &sspad_1.iscan, (ftnlen)4);
    bad_(&c__1, &c__0, "NSEG", &nseg, (ftnlen)4);
    bad_(&c_n1, &c__0, "NLEN", &nlen, (ftnlen)4);
    i__2 = -nc;
    bad_(&i__2, &c__0, "NLOC", nloc, (ftnlen)4);
    i1 = min(maxlda_1.maxlda,ican);
    i__2 = -i1;
    bad_(&i__2, &c__1, "CAN ", can, (ftnlen)4);
    i1 = sspad_1.iscan + 200;
    i1 = min(sspad_1.iscan,sspad_1.nscnmx);
    i__2 = -i1;
    bad_(&i__2, &c__1, "SCAN", sspad_1.scan, (ftnlen)4);
L9996:
    *ierror += 5020;
    goto L9999;

L9999:
    return 0;
} /* gencrv_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


