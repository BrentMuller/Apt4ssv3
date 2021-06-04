/* ATAPE.f -- translated by f2c (version 20100827).
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
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
} fxcor_;

#define fxcor_1 fxcor_

struct {
    char modfer[6];
} charct_;

#define charct_1 charct_

struct {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
} hblock_;

#define hblock_1 hblock_

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
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal b[256]	/* was [64][4] */, u[4], v[4];
    integer itop[96]	/* was [6][4][4] */, iflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    logical cldfg;
    integer iclcod, iclcnt, icline, iclblk, iclrcd, icltab[500]	/* was [5][
	    100] */, iptvec[9];
} cldt_;

#define cldt_1 cldt_

struct {
    char pntvct[72];
} chcldt_;

#define chcldt_1 chcldt_

/* Table of constant values */

static integer c__98 = 98;

/* *** SOURCE FILE : M0011445.W02   *** */

/* .....FORTRAN SUBROUTINE  ....ATAPE          8/68                    HG */

/*  PURPOSE     TO FORM THE CL RECORD AND WRITE IT ON EXFILE. */

/*  LINKAGE     CALL  ATAPE */

/*  ARGUMENTS   NONE */

/*  IMPORTANT VARIABLES */
/*              ICL     INDICATOR */
/*                      =2  CONTINUATING CL POINT. */
/*                      =3  LAST CL POINT. */
/*              KCR     CONTAINING THE LAST ICL VALUE. */
/*              MAXNR   MAXIMUM NUMBER OF RECORD PRODUCED BY THIS */
/*                      MOTION STATEMENT. */
/*              NUMCNT  MAXIMUM NUMBER OF POINT PRODUCED BY THE LAST */
/*                      MOTION STATEMENT. */
/*              JAXNR   EQUAL TO MAXNR BUT SAVED UNTIL NEXT MOTION */
/*                      STATEMENT. */
/*              ISIZE   COUNTER OF THE BUFFER. */
/*              NR      RECORD NUMBER ASSIGNED BY EWRITE. */
/*              CLPONT  BUFFER TO CONTAIN CL DATA. */
/*              ILPONT  INTEGER BUFFER ARRAY EQUIVALENT TO CLPONT. */
/*              KB      MAXIMUM NUMBER OF CL DATA IN THE BUFFER. */
/*                      63 OR 36 ACCORDING TO THE MULTAX SPECIFICATION. */
/*              JB      THE RECORD NUMBER WHERE THE SPECIFIED POINT */
/*                      WILL EXIST. */
/*              IEE     ERROR RETURN INDICATOR. */

/* Subroutine */ int atape_(void)
{
    /* Initialized data */

    static integer isize = 3;
    static integer kcr = 3;
    static integer ipow = 1308622848;
    static integer jmp = 1;
    static char godlta[6] = "GODLTA";
    static logical first = TRUE_;
    static struct {
	doublereal fill_1[1];
	integer e_2;
	integer fill_3[1];
	integer e_4;
	integer fill_5[507];
	} equiv_6 = { {0}, 1308622848, {0}, 1308622848 };


    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, nr, ir, ll, jj;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer knb, knr;
    extern integer bcdf_(char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer isiz2;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer nsize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static logical errctr;
    static integer modsrf[2];
#define clpont ((doublereal *)&equiv_6)
#define ilpont ((integer *)&equiv_6)
    extern /* Subroutine */ int ewrite_(integer *, integer *, doublereal *, 
	    integer *, integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...            SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...                SYSTEM I/O FILES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */













/* ... INITIALIZE CLDAT BUFFER */
    if (first) {
	ilpont[0] = bcdf_("CLDA", (ftnlen)4);
	ilpont[1] = bcdf_("TA  ", (ftnlen)4);
	first = FALSE_;
    }

/* ...     TEST FOR AN ARELEM ERROR OR FOR DNTCUT */
/* L185: */
    if (ifxcor_1.iaerr != 0 || ifxcor_1.icut != 0) {
	goto L3;
    }
    if (kcr != 3) {
	goto L7;
    }
    if (cldt_1.cldfg) {
	cldt_1.icltab[cldt_1.icline * 5 - 4] += ifxcor_1.numcnt;
    }
    ifxcor_1.numcnt = 0;
    nsize = 0;
    errctr = FALSE_;
L7:
    kcr = ifxcor_1.icl;
    if (s_cmp(charct_1.modfer, godlta, (ftnlen)6, (ftnlen)6) == 0) {
	goto L5;
    }
    ++ifxcor_1.numcnt;
L5:
    ilpont[isize * 2] = ipow;
    ilpont[(isize << 1) + 1] = ifxcor_1.icl;
    jmp = 1;
    if (cldt_1.iclcod > 1) {
	goto L100;
    }
L6:
    for (i__ = 1; i__ <= 3; ++i__) {
	clpont[isize + 1] = fxcor_1.te[i__ - 1];

/* ...CHECK IF THERE SHOULD BE NO TOOL AXIS PRINTOUT */
	if (ifxcor_1.mulout == knumbr_1.k0) {
	    goto L1;
	}

	clpont[isize + 4] = fxcor_1.ta[i__ - 1];
L1:
	isize += knumbr_1.k1;
    }
    isize += knumbr_1.k4;
    if (ifxcor_1.mulout == knumbr_1.k0) {
	isize -= knumbr_1.k3;
    }
L4:
    if (ifxcor_1.icl == knumbr_1.k2 && isize < 255) {
	goto L190;
    }
L2:
    nr = 0;
    j = isize << 1;
    ilpont[3] = ifxcor_1.iseqno;
    ilpont[5] = isize - 3;
    ewrite_(&symfil_1.exfile, &nr, clpont, &j, &ir);
    knr = nr;
    knb = cldt_1.iclblk;
    isize = 3;
    switch (jmp) {
	case 1:  goto L190;
	case 2:  goto L5;
    }
L3:
    if (isize > 3) {
	goto L2;
    }
L190:
    return 0;

L200:
    isize = nsize;
    jmp = 2;
    goto L2;

/* ...SPECIAL CLDAT - PRINTOUT REQUESTED */

L100:
    if (errctr) {
	goto L119;
    }
    errctr = TRUE_;
    modsrf[0] = isv_1.isfidn[ifxcor_1.ips - 1];
    modsrf[1] = isv_1.isfidn[ifxcor_1.ids - 1];

    for (i__ = 1; i__ <= 6; ++i__) {
	if (cldt_1.iclcod % cldt_1.iptvec[i__ + 2] != 0) {
	    goto L120;
	}
/*          PDS NDS PPS NPS UVPDS UVPPS */
	switch (i__) {
	    case 1:  goto L111;
	    case 2:  goto L111;
	    case 3:  goto L115;
	    case 4:  goto L115;
	    case 5:  goto L113;
	    case 6:  goto L117;
	}
L111:
	if (modsrf[1] > 0 && modsrf[1] < 18) {
	    goto L120;
	}
L113:
	if (modsrf[1] == 29) {
	    goto L120;
	}
	goto L118;
L115:
	if (modsrf[0] > 0 && modsrf[0] < 18) {
	    goto L120;
	}
L117:
	if (modsrf[0] == 29) {
	    goto L120;
	}
L118:
	error_(&c__98, "ATAPE   ", (ftnlen)8);
	goto L119;
L120:
	;
    }

L119:
    nsize = isize;
    if (s_cmp(charct_1.modfer, godlta, (ftnlen)6, (ftnlen)6) == 0) {
	goto L6;
    }
    isize += knumbr_1.k1;
    for (i__ = 1; i__ <= 9; ++i__) {
	if (cldt_1.iclcod % cldt_1.iptvec[i__ - 1] != 0) {
	    goto L140;
	}
	isize += knumbr_1.k1;
	if (isize > 253) {
	    goto L200;
	}
	isiz2 = isize << 1;
	ilpont[isiz2 - 2] = bcdf_(chcldt_1.pntvct + (i__ - 1 << 3), (ftnlen)4)
		;
	ilpont[isiz2 - 1] = bcdf_(chcldt_1.pntvct + ((i__ - 1 << 3) + 4), (
		ftnlen)4);
	for (j = 1; j <= 3; ++j) {
	    isize += knumbr_1.k1;
	    switch (i__) {
		case 1:  goto L121;
		case 2:  goto L122;
		case 3:  goto L123;
		case 4:  goto L124;
		case 5:  goto L125;
		case 6:  goto L126;
		case 7:  goto L127;
		case 8:  goto L128;
		case 9:  goto L129;
	    }
L121:
	    clpont[isize - 1] = fxcor_1.te[j - 1];
	    goto L130;
L122:
	    clpont[isize - 1] = fxcor_1.ta[j - 1];
	    goto L130;
L123:
	    clpont[isize - 1] = fxcor_1.ti[j - 1];
	    goto L130;
L124:
	    clpont[isize - 1] = sv_1.sp[j + ifxcor_1.ids * 3 - 4];
	    goto L130;
L125:
	    clpont[isize - 1] = sv_1.sn[j + ifxcor_1.ids * 3 - 4];
	    goto L130;
L126:
	    clpont[isize - 1] = sv_1.sp[j + ifxcor_1.ips * 3 - 4];
	    goto L130;
L128:
	    ll = ifxcor_1.ids - 1;
	    goto L131;
L129:
	    ll = ifxcor_1.ips - 1;
L131:
	    clpont[isize - 1] = 0.f;
	    isize += 2;
	    clpont[isize - 1] = 0.f;
	    clpont[isize - 2] = 0.f;
	    if (modsrf[ll - 1] != 29) {
		goto L140;
	    }
	    clpont[isize - 3] = ssarlm_1.u[ll - 1];
	    clpont[isize - 2] = ssarlm_1.v[ll - 1];
	    jj = (integer) canon[(ll - 1) * 10];
	    clpont[isize - 1] = (doublereal) (jj * 1000 + ssarlm_1.ipnum[ll - 
		    1]);
	    goto L140;
L127:
	    clpont[isize - 1] = sv_1.sn[j + ifxcor_1.ips * 3 - 4];
L130:
	    ;
	}
L140:
	;
    }
    goto L4;
} /* atape_ */

#undef ilpont
#undef clpont
#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can



/* ....  ATAPER */

/* Subroutine */ int ataper_(doublereal *r__, integer *nn, integer *jj, 
	integer *kk, integer *iee)
{
    /* Initialized data */

    static integer ipow = 1308622848;

    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[256];

    /* Local variables */
    static integer i__, j, k, l, i1, i2, i3, i33, ir, nr, nbf, knb, kkf, nrf, 
	    nrp, nrs, isz, line, ksct;
    extern /* Subroutine */ int eread_(integer *, doublereal *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#define clpont (equiv_0)
#define ilpont ((integer *)equiv_0)

/*  PURPOSE  TO RETRIEVE CL POINT FROM CLTAPE. */

/*  LINKAGE  CALL ATAPER (R,NN,JJ,KK,IEE) */

/*  ARGUMENTS   R   ARRAY TO CONTAIN THE CL DATA. */
/*              NN  INTEGER INDICATING CL POINT NUMBER */
/*              JJ  INTEGER CLDAT SECTION NUMBER */
/*              KK  INTEGER DATA TYPE */

/*     CHECK IF THE SPECIFIED POINT NUMBER IN THE SPECIFIED SECTION. */





/* ...            SYSTEM I/O FILE NAMES */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/* ...                SYSTEM I/O FILES */










    /* Parameter adjustments */
    --r__;

    /* Function Body */
    nr = *nn;
    if (*jj > 0) {
	goto L480;
    }
    if (nr <= 0 || nr > ifxcor_1.numcnt) {
	goto L610;
    }
/*      IF(NSIZE.GT.0)GOTO 610 */

/*     RETRIEVE A POINT OR A VECTOR OF THE LAST MOTION COMMAND */
/*     STORE 0,0,1 AS I,J,K */
/* L440: */
    r__[4] = 0.f;
    r__[5] = 0.f;
    r__[6] = 1.f;
    isz = ifxcor_1.mulout * 3 + 4;
    i__ = 252 / isz;
    i1 = (ifxcor_1.numcnt - 1) / i__;
    i2 = (nr - 1) / i__;
    if (i1 != i2) {
	goto L460;
    }

/*     DESIRED POSITION OF MOTION COMMAND IS IN CLPONT */
    j = ilpont[5] + 5 - isz * (ifxcor_1.numcnt - nr + 1);
    k = j - 2 + isz;
    l = 0;
    i__1 = k;
    for (i__ = j; i__ <= i__1; ++i__) {
	++l;
/* L450: */
	r__[l] = clpont[i__ - 1];
    }
    goto L600;

/*     FETCH EXFILE BLOCK CONTAINING DESIRED POSITION */
L460:
    nbf = knb - i1 + i2 + 1;
    nrp = i__ * (i2 + 1);
    i__1 = -isz;
    eread_(&symfil_1.exfile, &r__[1], &nr, &nbf, &nrf, &nrp, &i__1, &ir);
    goto L600;

/*     SEQUENTIAL SEARCH FROM BEGIN OF  'CLDAT/START,..'  REGION */
L480:
    if (*jj == ksct) {
	goto L510;
    }
    i__1 = cldt_1.iclcnt;
    for (line = 1; line <= i__1; ++line) {
	if (cldt_1.icltab[line * 5 - 5] == *jj) {
	    goto L500;
	}
/* L490: */
    }
    goto L610;

L500:
    kkf = ipow;
    i33 = ipow;
L510:
    i3 = cldt_1.icltab[line * 5 - 3];
    if (cldt_1.cldfg || nr <= 0 || nr > cldt_1.icltab[line * 5 - 4]) {
	goto L610;
    }
    if (i3 > 1) {
	goto L520;
    }
    if (*kk > 2) {
	goto L610;
    }
    isz = ifxcor_1.mulout * 3 + 4;
    nrp = 0;
    goto L540;

L520:
    if (i3 % cldt_1.iptvec[*kk - 1] != 0) {
	goto L610;
    }
    if (*kk == kkf && i33 == i3) {
	goto L550;
    }
    nrs = 0;
    for (i__ = 1; i__ <= 9; ++i__) {
	if (i3 % cldt_1.iptvec[i__ - 1] == 0) {
	    ++nrs;
	}
	if (*kk == i__) {
	    nrp = nrs;
	}
/* L530: */
    }
    isz = (nrs << 2) + 1;
L540:
    ksct = *jj;
    kkf = *kk;
    i33 = i3;
    nbf = cldt_1.icltab[line * 5 - 2];
    nrf = cldt_1.icltab[line * 5 - 1];

/*  NR             RECORD NUMBER IN THE DESIRED CLDAT SECTION. */
/*  NBF            FISRT EXFILE BLOCK  NUMBER OF THE CLDAT SECTION. */
/*  NRF            FISRT EXFILE RECORD NUMBER OF THE CLDAT SECTION. */
/*  ISZ            CLDAT RECORD SIZE.(DATA OF ONE POSITION = POINT) */
/*  NRP            POSITION OF THE DATA WANTED. */

L550:
    eread_(&symfil_1.exfile, &r__[1], &nr, &nbf, &nrf, &nrp, &isz, &ir);

L600:
    *iee = 0;
    return 0;
L610:
    *iee = 1;
    ksct = ipow;
    return 0;
} /* ataper_ */

#undef ilpont
#undef clpont


