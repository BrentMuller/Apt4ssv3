/* TOLER.f -- translated by f2c (version 20100827).
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
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer iamdct, ipdpl, ipt, iws, jckr, jcnt1, jcnt2, jcnt3, jcpr, jcr, 
	    jdr, jfind, jgr, jmin, jminr, jpr, jpxr, jtkf, jtr, j10, j12, j13,
	     j54, mdic;
} ishr18_;

#define ishr18_1 ishr18_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

struct {
    doublereal saveh[50];
} hsave_;

#define hsave_1 hsave_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0000735.W01   *** */

/* .....FORTRAN SUBROUTINES  TOLER,INTOL,OUTTOL,TOLERH,INTOLH, & OUTTOH */


/* .....FORTRAN SUBROUTINE             TOLER....              3/1/68   GK */
/* Subroutine */ int toler_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";
    static integer ithval[3] = { 8,9,4 };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --tlrns;

    /* Function Body */

    icase = 3;

    for (i__ = 1; i__ <= 4; ++i__) {
/* L5: */
	tolrns[i__ - 1] = tlrns[i__];
    }
    *number = *nmbr;
    if (hold_1.jhldfg == 0) {
	goto L300;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = ithval[icase - 1];
    ++hold_1.ithcnt;
L999:
    return 0;


/* ---    OUTTOL, MAX DEVIATION ZERO ON SIDE AWAY FROM CUTTER */
L300:
    i__1 = ifxcor_1.numsfs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sv_1.tau2[i__ - 1] = znumbr_1.z0;
/* L350: */
    }

    apt232_(number, tolrns, sv_1.tau1, &znumbr_1.z1);

/* ---    OUTPUT PART PROGRAM COMMAND ON EXFILE */

    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
    goto L999;
} /* toler_ */

#undef tolrns
#undef number






/* .....FORTRAN SUBROUTINE  ....INTOL          8/68                    PH */
/* .....FORTRAN SUBROUTINE             INTOL....              3/1/68   GK */
/* Subroutine */ int intol_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";
    static integer ithval[3] = { 8,9,4 };

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__, j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase, ibtflg;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --tlrns;

    /* Function Body */


    icase = 1;

    for (i__ = 1; i__ <= 4; ++i__) {
/* L5: */
	tolrns[i__ - 1] = tlrns[i__];
    }
    *number = *nmbr;
    if (hold_1.jhldfg == 0) {
	goto L100;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = ithval[icase - 1];
    ++hold_1.ithcnt;
L999:
    return 0;


/* ---    INTOL, MAX DEVIATION SPECFD ON SIDE OF SURF AWAY FROM CUTTER */
L100:
    if (ibtflg >= 0) {
	goto L110;
    }
    ibtflg = 0;
    sv_1.tau1[0] = znumbr_1.z0;
L110:
    d__1 = -znumbr_1.z1;
    apt232_(number, tolrns, sv_1.tau2, &d__1);
/* ---    OUTPUT PART PROGRAM COMMAND ON EXFILE */

/* L400: */
    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
    goto L999;
} /* intol_ */

#undef tolrns
#undef number






/* .....FORTRAN SUBROUTINE  ....OUTTOL         8/68                    PH */
/* .....FORTRAN SUBROUTINE            OUTTOL....              3/1/68   GK */
/* Subroutine */ int outtol_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";
    static integer ithval[3] = { 8,9,4 };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase, ibtflg;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --tlrns;

    /* Function Body */



    icase = 2;

    for (i__ = 1; i__ <= 4; ++i__) {
/* L5: */
	tolrns[i__ - 1] = tlrns[i__];
    }
    *number = *nmbr;
    if (hold_1.jhldfg == 0) {
	goto L200;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = ithval[icase - 1];
    ++hold_1.ithcnt;
L999:
    return 0;


/* ---    OUTTOL, MAXDEVIATION SPECIFD ON CUTTER SIDE OF SURFACE */
L200:
    if (ibtflg < 0) {
	ibtflg = 0;
    }
/* L210: */
    apt232_(number, tolrns, sv_1.tau1, &znumbr_1.z1);

    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
    goto L999;
} /* outtol_ */

#undef tolrns
#undef number






/* .....FORTRAN SUBROUTINE  ....TOLERH         8/68                    PH */
/* .....FORTRAN SUBROUTINE             TOLERH....             3/1/68   GK */
/* Subroutine */ int tolerh_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







    icase = 3;



/* ---    OUTTOL, MAX DEVIATION ZERO ON SIDE AWAY FROM CUTTER */
    i__1 = ifxcor_1.numsfs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sv_1.tau2[i__ - 1] = znumbr_1.z0;
/* L350: */
    }

    apt232_(number, tolrns, sv_1.tau1, &znumbr_1.z1);

    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
L999:
    return 0;
} /* tolerh_ */

#undef tolrns
#undef number






/* .....FORTRAN SUBROUTINE  ....INTOLH         8/68                    PH */
/* .....FORTRAN SUBROUTINE             INTOLH...              3/1/68   GK */
/* Subroutine */ int intolh_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase, ibtflg;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







    icase = 1;


/* ---    INTOL, MAX DEVIATION SPECFD ON SIDE OF SURF AWAY FROM CUTTER */
/* L100: */
    if (ibtflg >= 0) {
	goto L110;
    }
    ibtflg = 0;
    sv_1.tau1[0] = znumbr_1.z0;
L110:
    d__1 = -znumbr_1.z1;
    apt232_(number, tolrns, sv_1.tau2, &d__1);
/* ---    OUTPUT PART PROGRAM COMMAND ON EXFILE */

/* L400: */
    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
L999:
    return 0;
} /* intolh_ */

#undef tolrns
#undef number






/* .....FORTRAN SUBROUTINE  ....OUTTOH         8/68                    PH */
/* .....FORTRAN SUBROUTINE            OUTTOH....              3/1/68   GK */
/* Subroutine */ int outtoh_(integer *nmbr, doublereal *tlrns)
{
    /* Initialized data */

    static char ppword[6*3] = "INTOL " "OUTTOL" "TOLER ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt232_(integer *, doublereal *, doublereal *,
	     doublereal *), apt299_();
    static integer icase, ibtflg;
#define number ((integer *)&hsave_1 + 8)
    static integer ippwrd[2];
#define tolrns ((doublereal *)&hsave_1)






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







    icase = 2;

/* ---    OUTTOL, MAXDEVIATION SPECIFD ON CUTTER SIDE OF SURFACE */
/* L200: */
    if (ibtflg < 0) {
	ibtflg = 0;
    }
/* L210: */
    apt232_(number, tolrns, sv_1.tau1, &znumbr_1.z1);

    ippwrd[0] = bcdf_(ppword + (icase - 1) * 6, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + ((icase - 1) * 6 + 4), (ftnlen)2);
    apt299_(number, ippwrd, &c__1, tolrns);
    if (*number <= 1) {
	goto L999;
    }
    i__1 = *number;
    for (j = 2; j <= i__1; j += 2) {
	if (j != *number) {
	    apt299_(&c__1, &tolrns[j - 1], &c__1, &tolrns[j]);
	} else {
	    apt299_(&c__1, &tolrns[j - 1], &c__0, &znumbr_1.z0);
	}
/* L30: */
    }
L999:
    return 0;
} /* outtoh_ */

#undef tolrns
#undef number


