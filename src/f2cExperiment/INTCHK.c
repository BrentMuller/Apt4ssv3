/* INTCHK.f -- translated by f2c (version 20100827).
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
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;

/* *** SOURCE FILE : INTCHK.ORG   *** */

/* Subroutine */ int intchk_(doublereal *psurf, integer *ipsize, doublereal *
	pside, doublereal *pthick, doublereal *tolin, doublereal *tul, 
	doublereal *te, doublereal *ta, doublereal *r__, integer *npat, 
	doublereal *up, doublereal *vp, logical *lret, integer *intloc)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, n;
    extern /* Subroutine */ int bad_();
    static char msg[120];
    static integer lsusp[1000], nsusp;
    extern /* Subroutine */ int remscn_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *), remint_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *), 
	    cprint_(char *, ftnlen), curint_(doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *);


/*     PURPOSE : TO PERFORM INTERFERENCE CHECKING */

/*     ARGUMENTS: */

/*     PSURF   -  CANONICAL FORM OF PART SURFACE (SSURF) */
/*     IPSIZE  -  SIZE OF CANONICAL FORM */
/*     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV) */
/*     PTHICK  -  THICKNESS OFFSET FROM SURFACE */
/*     TOLIN   -  TOLERANCE (PS INTOL) */
/*     TUL     -  TOOL GEOMETRY */
/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     R       -  SURFACE CONTACT POINT AND DERIVATIVES */
/*     NPAT    -  PATCH NUMBER FOR CONTACT POINT */
/*     UP,VP   -  U AND V PARAMETERS FOR CONTACT POINT */
/*     LRET    -  RETURN FLAG = .TRUE.  IF INTERFERENCE OCCURS */
/*                            = .FALSE. IF NO INTERFERENCE */
/*     INTLOC  -  LOCATION IN INTERFERENCE TABLE OF LARGEST INTERFERENCE */



/* .... LOCAL VARIABLES */

/*     LSUSP   -  LIST OF SUSPECT PATCHES */
/*     NSUSP   -  NUMBER OF SUSPECT PATCHES */




/*    INTERFERENCE TABLE */







/* .... DEBUG FLAGS */



    /* Parameter adjustments */
    --psurf;
    --tul;
    --te;
    --ta;
    --r__;

    /* Function Body */
    *lret = FALSE_;
    *intloc = 0;

/* .... DEBUG PRINT */

    if (ibugg_1.ibug == 11) {
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(msg, "0ENTER INTCHK", (ftnlen)120, (ftnlen)13);
	cprint_(msg, (ftnlen)120);
	bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
	bad_(&c_n3, &c__1, "TA  ", &ta[1], (ftnlen)4);
    }

/* .... TEST REMOTE (NON-CURRENT) PATCHES FOR POSSIBLE INTERFERENCE */

    remscn_(&te[1], &ta[1], &tul[1], &r__[1], pside, pthick, tolin, npat, 
	    lsusp, &nsusp);

    if (nsusp > 0) {
/* .... DEBUG PRINT */
	if (ibugg_1.ibug == 11) {
	    s_copy(msg, " POSSIBLE REMOTE INTERFERENCE", (ftnlen)120, (ftnlen)
		    29);
	    cprint_(msg, (ftnlen)120);
	    n = -nsusp;
	    bad_(&n, &c__0, "SUSP", lsusp, (ftnlen)4);
	}

/* .... CHECK OUT SUSPECT REMOTE PATCHES AND STORE ANY PENETRATION DATA */
/*     IN INTERFERENCE TABLE */

	remint_(&te[1], &ta[1], &tul[1], &psurf[1], ipsize, pside, pthick, 
		tolin, lsusp, &nsusp);
    }

/* .... CHECK CURRENT PATCH AND STORE ANY PENETRATION DATA */
/*     IN INTERFERENCE TABLE */

    curint_(&psurf[1], ipsize, pside, pthick, tolin, &tul[1], &te[1], &ta[1], 
	    &r__[1], npat, up, vp);

/* .... HAS ANY INTERFERENCE BEEN DETECTED */

    if (interf_1.npintr > 0) {

	*lret = TRUE_;
	*intloc = 1;
	i__1 = interf_1.npintr;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* .... FIND AND SAVE LOCATION OF LARGEST PENETRATION */
	    if (interf_1.dintr[i__ - 1] > interf_1.dintr[*intloc - 1]) {
		*intloc = i__;
	    }

/* .... DEBUG PRINT OF INTERFERENCE TABLE */

	    if (ibugg_1.ibug == 11) {
		bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
		bad_(&c__1, &c__0, "PAT ", &interf_1.pintr[i__ - 1], (ftnlen)
			4);
		bad_(&c__1, &c__1, "U   ", &interf_1.uintr[i__ - 1], (ftnlen)
			4);
		bad_(&c__1, &c__1, "V   ", &interf_1.vintr[i__ - 1], (ftnlen)
			4);
		bad_(&c__1, &c__1, "PEN ", &interf_1.dintr[i__ - 1], (ftnlen)
			4);
		bad_(&c_n1, &c__1, "ISEG", &interf_1.iseg[i__ - 1], (ftnlen)4)
			;
		bad_(&c__3, &c__1, "TP  ", &interf_1.tpintr[i__ * 3 - 3], (
			ftnlen)4);
		bad_(&c__3, &c__1, "SP  ", &interf_1.spintr[i__ * 3 - 3], (
			ftnlen)4);
		bad_(&c_n3, &c__1, "SN  ", &interf_1.snintr[i__ * 3 - 3], (
			ftnlen)4);
	    }
/* L100: */
	}

    }

    return 0;
} /* intchk_ */

