/* AVOID.f -- translated by f2c (version 20100827).
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
    doublereal ctang, bmin, bmax, dmax__;
    logical latyp1, lanps, avlist;
} avcprm_;

#define avcprm_1 avcprm_

struct {
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__36 = 36;
static integer c__39 = 39;
static integer c__21 = 21;
static integer c__31 = 31;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__18 = 18;
static integer c__5 = 5;
static integer c__7 = 7;
static integer c__6 = 6;
static integer c__11 = 11;
static integer c__13 = 13;
static integer c__10 = 10;
static integer c__4 = 4;
static integer c__12 = 12;
static integer c__8 = 8;
static integer c__22 = 22;
static integer c__14 = 14;

/* *** SOURCE FILE : AVOID.V01   *** */

/* Subroutine */ int avoid_(doublereal *psurf, integer *ipsize, doublereal *
	pside, doublereal *pthick, doublereal *ptoli, doublereal *ptolo, real 
	*tolcom, doublereal *fwd, doublereal *tul, doublereal *te, doublereal 
	*ta, doublereal *r__, integer *npat, doublereal *up, doublereal *vp, 
	integer *intloc, logical *lret)
{
    /* Initialized data */

    static char msg1[52] = "UNABLE TO AVOID INTERFERENCE WITH CURRENT PARAME"
	    "TERS";
    static char msg2[64] = "INTERFERENCE DIRECTION PERPENDICULAR TO SELECTED"
	    " LIFT OFF VECTOR";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double d_sign(doublereal *, doublereal *), cos(doublereal), sin(
	    doublereal), sqrt(doublereal);

    /* Local variables */
    static doublereal b, d__, e;
    static integer i__;
    static doublereal s, d1, cx[24], ul[3], vl[3];
    extern /* Subroutine */ int bad_();
    static char msg[120];
    static doublereal nps[3], bdeg, maxk, temp;
    static integer ipos;
    static logical iret, jret;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static char type__[5];
    extern /* Subroutine */ int calcb_(doublereal *, doublereal *, doublereal 
	    *, integer *, doublereal *, char *, doublereal *, ftnlen);
    static doublereal tcrad, oldta[3];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static doublereal oldte[3], rcmin;
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), avmsg_(doublereal *, doublereal *, 
	    logical *, doublereal *, char *, doublereal *, ftnlen), reset_(
	    void), vnorm_(doublereal *, doublereal *), tecalc_(), calmxb_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, logical *), vscale_(doublereal *, 
	    doublereal *, doublereal *);
    static doublereal tccent[3];
    extern /* Subroutine */ int intchk_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *), cprint_(char *, ftnlen), intmsg_(
	    doublereal *, doublereal *, integer *), tcsphr_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), kursrf_(doublereal *, 
	    doublereal *, doublereal *), restor_(void), outmsg_(char *, 
	    ftnlen);


/*     PURPOSE:   TO CARRY OUT AVOIDANCE STRATEGIES WHEN INTERFERENCE */
/*                HAS BEEN DETECTED */

/*     ARGUMENTS: */

/*     PSURF   -  CANONICAL FORM OF PART SURFACE */
/*     IPSIZE  -  SIZE OF PS CANONICAL FORM */
/*     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV) */
/*     PTHICK  -  THICKNESS OFFSET FROM SURFACE */
/*     PTOLI, PTOLO - PS TOLERANCE */
/*     TOLCOM  -  TOLERANCE BAND COMPENSATION */
/*     FWD     -  DS FORWARD DIRECTION */
/*     TUL     -  TOOL GEOMETRY */
/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     R       -  SURFACE CONTACT POINT AND DERIVATIVES */
/*     NPAT    -  PATCH NUMBER FOR CONTACT POINT */
/*     UP,VP   -  U,V PARAMETERS OF CONTACT POINT */
/*     INTLOC  -  LOCATION INTERFERENCE TABLE OF WORST PENETRATION */
/*     LRET    -  RETURN FLAG */
/*                .TRUE.  IF INTERFERENCE AVOIDED */
/*                .FALSE. IF THERE IS STILL INTERFERENCE */



/*     GLOBAL VARIABLES */


/*       AVOIDANCE CONTROL PARAMETERS */



/*     CTANG    CONSTANT TECHNOLOGICAL ANGLE */
/*     BMIN     MINIMUM PITCH ANGLE */
/*     BMAX     MAXIMUM PITCH ANGLE */
/*     DMAX     MAXIMUM LINEAR LIFT OFF */
/*     LATYP1   FLAG INDICATING IF TYPE1 (TILT) AVOIDANCE REQUIRED */
/*     LANPS    FLAG INDICATING TYPE OF LINEAR LIFT OFF */
/*              .TRUE.  - LIFT OFF NORMAL TO PS */
/*              .FALSE. - LIFT OFF PARALLEL TO TOOL AXIS */
/*     AVLIST   FLAG INDICATING THAT AVOIDANCE DETAILS ARE TO BE PRINTED */


/*    INTERFERENCE TABLE */






/*     LOCAL VARIABLES */

/*     B      - COMPUTED TILT ANGLE TO CLEAR INTERFERENCE */
/*     UL     - LOCAL AXIS IN FWD DIRECTION PERPTO TA */
/*     S      - SIGN OF TILT ANGLE  (+VE IN FWD DIRECTION) */
/*     TCCENT - CENTRE OF TOOL CONTACT SPHERE */
/*     TCRAD  - RADIUS OF TOOL CONTACT SPHERE */
/*     CX     - PRINCIPLE CURVATURES, DIRECTIONS AND COEFFICIENTS */
/*     RCMIN  - MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT */
/*     NPS    - PART SURFACE NORMAL AT POINT OF CONTACT */
/*     VL     - LIFT OFF DIRECTION */
/*     D1,TEMP- LOCAL WORK VARIABLES */
/*     D      - LIFT OFF DISTANCE */
/*     E      - CURVATURE COMPENSATION */
/*     MSG    - PRINT BUFFER */
/*     MSG1,MSG2 - MESSAGES */
/*     IPOS   - LOCATION IN PRINT BUFFER */
/*     IRET   - INTCHK RETURN FLAG - .TRUE. IF INTERFERENCE DETECTED */
/*     JRET   - CALMXB RETURN FLAG - .TRUE. IF BETA CALC. OK */
/*     BDEG   - B IN DEGREES */
/*     TYPE   - TYPE OF TILT (ROLL OR PITCH) */
/*     OLDTE  - ORIGINAL TE */
/*     OLDTA  - ORIGINAL TA */
/*     MAXK   - MAXIMUM CURVATURE */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




    /* Parameter adjustments */
    --psurf;
    --fwd;
    --tul;
    --te;
    --ta;
    --r__;

    /* Function Body */

    *lret = FALSE_;
    b = znumbr_1.z0;
    d__ = znumbr_1.z0;
    s_copy(msg, " ", (ftnlen)120, (ftnlen)1);

/* .... DETERMINE SURFACE NORMAL POINTING TOWARDS TOOL AT CONTACT POINT */

    vscale_(pside, &r__[29], nps);

/* .... COMPUTE PRINCIPLE CURVATURES OF SURFACE AT POINT OF CONTACT */

    kursrf_(&r__[1], pside, cx);

/* .... DETERMINE MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT */

    maxk = max(cx[0],cx[1]);
    if (abs(maxk) > znumbr_1.z1em6) {
	rcmin = znumbr_1.z1 / maxk;
    } else {
	rcmin = znumbr_1.z1e6;
    }

    if (avcprm_1.latyp1) {

/* .... FIRST TRY AVOIDING INTERFERENCE BY TILTING TOOL */
/*     IN THE MOST APPROPRIATE DIRECTION INDICATED BY TYPE AND UL */

	calcb_(&ta[1], &fwd[1], &r__[1], intloc, &b, type__, ul, (ftnlen)5);

/* .... ADD CONSTANT TECHNOLOGICAL ANGLE (TO CLEAR SURFACE) */

	s = d_sign(&znumbr_1.z1, &b);
	b += s * avcprm_1.ctang;

/* .... IS B WITHIN PERMITTED RANGE */

	if (b < avcprm_1.bmin) {
	    b = avcprm_1.bmin;
	} else if (b > avcprm_1.bmax) {
	    b = avcprm_1.bmax;
	}

/* .... COMPUTE NEW TA TILTED THROUGH B IN UL DIRECTION */
/*     SAVE OLD TE AND TA */

	for (i__ = 1; i__ <= 3; ++i__) {
	    oldte[i__ - 1] = te[i__];
	    oldta[i__ - 1] = ta[i__];
	    ta[i__] = cos(b) * ta[i__] + sin(b) * ul[i__ - 1];
/* L10: */
	}

/* .... COMPUTE NEW TE */

	tecalc_(&r__[1], &ta[1], &fwd[1], pside, pthick, tolcom, &tul[1], &te[
		1]);

/* .... COMPUTE CENTRE AND RADIUS OF TOOL CONTACT SPHERE */

	tcsphr_(&te[1], &ta[1], &tul[1], &r__[1], pside, pthick, tccent, &
		tcrad);

/* .... IS THERE LOCAL INTERFERENCE */

	if (tcrad > rcmin) {
/* .... YES */
	    if ((d__1 = tcrad - tul[1], abs(d__1)) > znumbr_1.z1em6 && tul[1] 
		    + tul[3] < rcmin) {
/* .... COMPUTE MAXIMUM TILT ANGLE TO FIT SURFACE */
		calmxb_(&rcmin, &tul[1], oldta, ul, nps, &b, &jret);
/* .... HAS ANGLE BEEN COMPUTED SATISFACTORILY */
/*     AND IS ANGLE WITHIN PERMITTED RANGE */
		if (jret && b >= avcprm_1.bmin && b <= avcprm_1.bmax) {

/* .... YES - COMPUTE NEW TA TILTED THROUGH B IN FWD (UL) DIRECTION */

		    for (i__ = 1; i__ <= 3; ++i__) {
			ta[i__] = cos(b) * oldta[i__ - 1] + sin(b) * ul[i__ - 
				1];
/* L20: */
		    }

/* .... COMPUTE NEW TE */

		    tecalc_(&r__[1], &ta[1], pside, pthick, ptoli, ptolo, &
			    tul[1], &te[1]);

		} else {

/* .... NO - LIFTOFF */

		    b = znumbr_1.z0;

		    if (avcprm_1.avlist) {
			cform_("UNABLE TO FIND TOOL AXIS ORIENTATION", msg, &
				c__2, &c__36, (ftnlen)36, (ftnlen)120);
			cform_("WITHIN SELECTED RANGE", msg, &c__39, &c__21, (
				ftnlen)21, (ftnlen)120);
			cprint_(msg, (ftnlen)120);
			cform_("WHERE TOOL CAN BE POSITIONED IN", msg, &c__2, 
				&c__31, (ftnlen)31, (ftnlen)120);
			cform_("NON-INTERFERING CONTACT WITH SURFACE", msg, &
				c__36, &c__36, (ftnlen)36, (ftnlen)120);
			cprint_(msg, (ftnlen)120);
			bad_(&c__3, &c__1, "R   ", &r__[1], (ftnlen)4);
			bad_(&c__1, &c__0, "NPAT", npat, (ftnlen)4);
			bad_(&c__1, &c__1, "U   ", up, (ftnlen)4);
			bad_(&c_n1, &c__1, "V   ", vp, (ftnlen)4);
		    }

/* .... RESTORE OLD TE AND TA */

		    for (i__ = 1; i__ <= 3; ++i__) {
			te[i__] = oldte[i__ - 1];
			ta[i__] = oldta[i__ - 1];
/* L25: */
		    }

		    goto L100;
		}
	    } else {

/* .... RADIUS OF TOOL CONTACT SPHERE = TOOL CORNER RADIUS - LIFT OFF */

		b = znumbr_1.z0;
		if (avcprm_1.avlist) {
		    s_copy(msg, "TOOL RADIUS GT RADIUS OF CURVATURE AT", (
			    ftnlen)120, (ftnlen)37);
		    cprint_(msg, (ftnlen)120);
		    bad_(&c__3, &c__1, "R   ", &r__[1], (ftnlen)4);
		    bad_(&c__1, &c__0, "NPAT", npat, (ftnlen)4);
		    bad_(&c__1, &c__1, "U   ", up, (ftnlen)4);
		    bad_(&c_n1, &c__1, "V   ", vp, (ftnlen)4);
		}

/* .... RESTORE OLD TE AND TA */

		for (i__ = 1; i__ <= 3; ++i__) {
		    te[i__] = oldte[i__ - 1];
		    ta[i__] = oldta[i__ - 1];
/* L26: */
		}

		goto L100;
	    }
	}

/* .... CHECK NEW POSTION (TE,TA) FOR INTERFERENCE */

/* .... SAVE ORIGINAL INTERFERENCE DATA TO USE FOR START POINTS */

	reset_();
	intchk_(&psurf[1], ipsize, pside, pthick, ptoli, &tul[1], &te[1], &ta[
		1], &r__[1], npat, up, vp, &iret, intloc);

	if (! iret) {
/* .... AVOIDANCE SUCCESSFUL - RESTORE ORIGINAL INTERFERENCE DATA */
	    restor_();
	    if (avcprm_1.avlist) {
		avmsg_(&te[1], &ta[1], &avcprm_1.lanps, &b, type__, &
			znumbr_1.z0, (ftnlen)5);
	    }
	    *lret = TRUE_;
	    goto L999;
	}
    }

/* .... IF TILTING UNSUCCESSFUL OR LIFT OFF ONLY SELECTED */

/* .... TRY AVOIDING INTERFERENCE BY LIFTING THE TOOL OFF THE SURFACE */
/*     IN THE SPECIFIED DIRECTION */

L100:

/* .... COMPUTE LIFT OFF DISTANCE */

/*     VL - LIFT OFF DIRECTION */

    for (i__ = 1; i__ <= 3; ++i__) {
	if (avcprm_1.lanps) {
	    vl[i__ - 1] = nps[i__ - 1];
	} else {
	    vl[i__ - 1] = ta[i__];
	}
/* L30: */
    }

    vnorm_(vl, vl);

    dotv_(&d1, &interf_1.snintr[*intloc * 3 - 3], vl);
    if (abs(d1) < znumbr_1.z1em6) {
	if (avcprm_1.avlist) {
	    outmsg_(msg1, (ftnlen)52);
	    outmsg_(msg2, (ftnlen)64);
	}
    } else {

/* .... LIFT OFF IN DIRECTION VL */

	d__ = interf_1.dintr[*intloc - 1] / d1;

/* .... COMPUTE CURVATURE COMPENSATION FOR CONCAVE SURFACE */

	if (rcmin > znumbr_1.z0) {
	    temp = rcmin * rcmin - interf_1.dintr[i__ - 1] * interf_1.dintr[
		    i__ - 1] + d__ * d__;
	    if (temp > znumbr_1.z0) {
		e = sqrt(temp) - rcmin;
	    } else {
		e = znumbr_1.z0;
	    }
	} else {
	    e = znumbr_1.z0;
	}

/* .... LIFT OFF - COMPENSATED FOR CURVATURE, AND INCREASED BY OUTTOL */

	d__ = d__ + e + *ptolo;

	if (abs(d__) <= avcprm_1.dmax__) {

/* .... LIFTOFF WITHIN SPECIFIED LIMIT - COMPUTE NEW TE (TA UNCHANGED) */

	    for (i__ = 1; i__ <= 3; ++i__) {
		te[i__] += d__ * vl[i__ - 1];
/* L40: */
	    }

	    if (avcprm_1.lanps) {
/* .... IF LIFT OFF NORMAL TO PS CHECK FOR INTERFERENCE */
		reset_();
		intchk_(&psurf[1], ipsize, pside, pthick, ptoli, &tul[1], &te[
			1], &ta[1], &r__[1], npat, up, vp, &iret, intloc);
		if (iret) {
/* ... STILL INTERFERENCE */
		    if (avcprm_1.avlist) {
			outmsg_(msg1, (ftnlen)52);
			intmsg_(&te[1], &ta[1], intloc);
			cform_("ACTION ATTEMPTED -", msg, &c__1, &c__18, (
				ftnlen)18, (ftnlen)120);
			ipos = 21;
			if ((d__1 = b - znumbr_1.z0, abs(d__1)) > 
				znumbr_1.z1em6) {
			    cform_(type__, msg, &ipos, &c__5, (ftnlen)5, (
				    ftnlen)120);
			    ipos += 6;
			    cform_("THROUGH", msg, &ipos, &c__7, (ftnlen)7, (
				    ftnlen)120);
			    ipos += 8;
			    bdeg = b / znumbr_1.degrad;
			    fconv_(&bdeg, msg, &ipos, &c__6, &c__2, (ftnlen)
				    120);
			    ipos += 7;
			    cform_("DEGREES AND", msg, &ipos, &c__11, (ftnlen)
				    11, (ftnlen)120);
			    ipos += 12;
			}
			cform_("LIFTED OFF BY", msg, &ipos, &c__13, (ftnlen)
				13, (ftnlen)120);
			ipos += 14;
			fconv_(&d__, msg, &ipos, &c__10, &c__4, (ftnlen)120);
			ipos += 11;
			cform_("NORMAL TO PS", msg, &ipos, &c__12, (ftnlen)12,
				 (ftnlen)120);
			cprint_(msg, (ftnlen)120);
		    }
		    goto L999;
		}

/* .... RESTORE INTEFERENCE DATA FOR USE AS NEXT START VALUES */

		restor_();
	    }

/* .... AVOIDANCE SUCCESSFUL */

	    if (avcprm_1.avlist) {
		avmsg_(&te[1], &ta[1], &avcprm_1.lanps, &b, type__, &d__, (
			ftnlen)5);
	    }
	    *lret = TRUE_;

	} else {

/* .... COMPUTED LIFT OFF GREATER THAN LIMIT */

	    if (avcprm_1.avlist) {
		outmsg_(msg1, (ftnlen)52);
		cform_("LIFT OFF", msg, &c__2, &c__8, (ftnlen)8, (ftnlen)120);
		fconv_(&d__, msg, &c__11, &c__10, &c__4, (ftnlen)120);
		if (avcprm_1.lanps) {
		    cform_("NORMAL TO PS", msg, &c__22, &c__12, (ftnlen)12, (
			    ftnlen)120);
		} else {
		    cform_("PARALLEL TO TA", msg, &c__22, &c__14, (ftnlen)14, 
			    (ftnlen)120);
		}
		cprint_(msg, (ftnlen)120);
	    }

	}

    }

L999:

    return 0;
} /* avoid_ */

