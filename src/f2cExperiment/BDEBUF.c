/* BDEBUF.f -- translated by f2c (version 20100827).
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

struct ebuf_1_ {
    integer ebuff[516], k, n, keb, krf;
};

#define ebuf_1 (*(struct ebuf_1_ *) &ebuf_)

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

/* Initialized data */

struct {
    integer fill_1[516];
    integer e_2[4];
    } ebuf_ = { {0}, 2, 0, 1, 0 };


/* *** SOURCE FILE : M0011449.W02   *** */

/* Subroutine */ int bdebuf_(void)
{
    return 0;
} /* bdebuf_ */




/*      FORTRAN SUBROUTINE  EWRITE */
/*  PURPOSE   TO BLOCK CL RECORDS */

/*  LINKAGE     CALL EWRITE(EXFILE,MR,ICLDAT,J,IR) */

/*  ARGUMENTS   EXFILE  FILE NUMBER OF EXFILE */
/*              MR      INTEGER TO CONTAIN RECORD NUMBER */
/*              ICLDAT  ARRAY CONTAINING THE RECORD TO BE WRITTEN ON */
/*                      EXFILE. */
/*              J       NUMBER OF WORD (4 BYTE) IN RECORD */
/*              IR      ERROR RETURN FLAG, =0 NOERROR , =1 ERROR. */

/*  IMPORTANT VARIABLES */
/*              KEB     NUMBER OF 1ST RECORD IN A BLOCK */
/*              N       NUMBER OF LAST RECORD IN A BLOCK */
/*              EBUFF   THE BUFFER TO CONTAIN THE RECORDS. */

/* Subroutine */ int ewrite_(integer *exfile, integer *mr, integer *icldat, 
	integer *j, integer *ir)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, nr;
    extern integer bcdf_(char *, ftnlen);
    static integer kfini;
    extern /* Subroutine */ int awrite_(integer *, integer *, integer *, 
	    integer *, integer *);









    /* Parameter adjustments */
    --icldat;

    /* Function Body */

    if (first) {
	kfini = bcdf_("FINI", (ftnlen)4);
	first = FALSE_;
    }

    if (ebuf_1.k + *j > 514) {
	goto L1;
    }
L10:
    ++ebuf_1.n;
    cldt_1.iclrcd = ebuf_1.n;
/* L15: */
    ebuf_1.ebuff[0] = ebuf_1.keb;
    ebuf_1.ebuff[1] = ebuf_1.n;
    ebuf_1.ebuff[ebuf_1.k] = ebuf_1.n;
    ebuf_1.ebuff[ebuf_1.k + 1] = *j;
    ebuf_1.k += 2;
    i__1 = *j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++ebuf_1.k;
/* L20: */
	ebuf_1.ebuff[ebuf_1.k - 1] = icldat[i__];
    }
/*     IF THE RECORD IS FINI,  TRUNCATE THE BLOCK */
/*       AND WRITE OUT TO EXFILE. */
    if (icldat[1] == kfini) {
	goto L30;
    }
    *mr = ebuf_1.n;
    return 0;

/*     BUFFER IS FULL, WRITE THE BLOCK ON EXFILE */

L1:
    nr = 0;
    awrite_(exfile, &nr, ebuf_1.ebuff, &ebuf_1.k, ir);
    cldt_1.iclblk = nr;
    ebuf_1.k = 2;
    ebuf_1.keb = ebuf_1.n + 1;
    goto L10;

L30:
    ebuf_1.ebuff[1] = ebuf_1.n;
    nr = 0;
    awrite_(exfile, &nr, ebuf_1.ebuff, &ebuf_1.k, ir);
    return 0;
} /* ewrite_ */


/*    ..  SUBROUTINE EREAD  .... */

/*  PURPOSE   TO GET 1 CL RECORD */

/*  LINKAGE     CALL EREAD(EXFILE,IBUFF,NN,NBF,NRF,NRP,ISZ,IR) */

/*  ARGUMENT    EXFILE  FILE NUMBER OF EXFILE */
/*              IBUFF   INTEGER ARRAY TO CONTAIN THE READ RECORD. */
/*              NN      INTEGER SEARCHED POSITON. */
/*              NBF     INTEGER FIRST BLOCK  NUMBER TO BE READ. */
/*              NRF     INTEGER FIRST RECORD NUMBER TO BE READ. */
/*              NRP     INTEGER POSITION OF DESIRED DATA. */
/*              ISZ     INTEGER TO CONTAIN THE SIZE OF RECORD. */
/*              IR      RETURN ERROR FLAG. =0 NO ERROR  ,  =1 ERROR. */

/*  IMPORTANT VARIABLES */
/*              KK      POINTER TO FIND THE POSITION OF RECORD IN THE */
/*                      BLOCK. */

/* Subroutine */ int eread_(integer *exfile, integer *ibuff, integer *nn, 
	integer *nbf, integer *nrf, integer *nrp, integer *isz, integer *ir)
{
    /* Initialized data */

    static logical goflg = FALSE_;
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, nb, jj, kk, mm, ks, nr, ncl[2];
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int help_(void);
    static integer minn, maxn;
    extern /* Subroutine */ int aread_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer godlt;
    extern /* Subroutine */ int awrite_(integer *, integer *, integer *, 
	    integer *, integer *);








    /* Parameter adjustments */
    --ibuff;

    /* Function Body */

    if (first) {
	ncl[0] = bcdf_("CLDA", (ftnlen)4);
	ncl[1] = bcdf_("TA  ", (ftnlen)4);
	godlt = bcdf_("GODL", (ftnlen)4);
	first = FALSE_;
    }

/*     WRITE THE CURRENT BLOCK */

    if (ebuf_1.k == 2) {
	goto L100;
    }
    nr = 0;
    awrite_(exfile, &nr, ebuf_1.ebuff, &ebuf_1.k, ir);
    cldt_1.iclblk = nr;
    ebuf_1.keb = ebuf_1.n + 1;
    ebuf_1.k = 2;

/*     RETRIEVE A DEFINED BLOCK CONTAINING THE LAST MOTION COMMAND. */

L100:
    if (*isz > 0) {
	goto L130;
    }
    if (nb == *nbf) {
	goto L110;
    }
    ks = 516;
    nb = *nbf;
    aread_(exfile, &nb, ebuf_1.ebuff, &ks, ir);

/*     STANDARD EXFILE RECORD FORMAT */
L110:
    jj = ks + 3 + (*isz << 1) * (*nrp - *nn + 1);
    mm = jj - 3 - (*isz << 1);
    i__1 = mm;
    for (i__ = jj; i__ <= i__1; ++i__) {
/* L120: */
	ibuff[i__ - jj + 1] = ebuf_1.ebuff[i__ - 1];
    }
    return 0;

/*     EXFILE RECORD EXTENDED FORMAT. MORE THAN ONE MOTION COMMAND. */
L130:
    if (ebuf_1.krf != *nrf) {
	goto L150;
    }
    if (*nn > maxn) {
	goto L205;
    }
    if (*nn > minn) {
	goto L230;
    }
L150:
    nb = *nbf - 1;
    minn = 0;
    ebuf_1.krf = *nrf;

/*     READ FIRST BLOCK OF THE CLDAT SECTION. */
L160:
    ++nb;
    if (nb > cldt_1.iclblk) {
	help_();
    }
    ks = 516;
    aread_(exfile, &nb, ebuf_1.ebuff, &ks, ir);
    if (*nrf > ebuf_1.ebuff[1]) {
	goto L160;
    }

/*     START OF THE CLDAT SECTION FOUND. */
/* L170: */
    kk = 3;
    goto L185;
L180:
    kk = kk + ebuf_1.ebuff[kk] + 2;
    if (kk >= ks) {
	help_();
    }
L185:
    if (ebuf_1.ebuff[kk - 1] < *nrf) {
	goto L180;
    }

/*     IS IT A MOTION COMMAND ? */
L190:
    if (ebuf_1.ebuff[kk + 1] == ncl[0]) {
	goto L220;
    }
L200:
    kk = kk + ebuf_1.ebuff[kk] + 2;
    if (kk >= ks - 1) {
	goto L160;
    }
    goto L190;
L205:
    minn = maxn;
L210:
    goflg = FALSE_;
    goto L200;

/*     IS IT A CLDATA RECORD GIVING POSITIONS ? */
L220:
    if (ebuf_1.ebuff[kk + 2] != ncl[1]) {
	goto L200;
    }
    if (ebuf_1.ebuff[kk + 9] == godlt) {
	goflg = TRUE_;
    }
    if (ebuf_1.ebuff[kk + 8] == 1) {
	goto L200;
    }
    if (goflg) {
	goto L210;
    }

/*     IS DEMANDED POSITION WITHIN THAT RECORD ? */
    maxn = minn + ebuf_1.ebuff[kk + 6] / *isz;
    if (maxn >= *nn) {
	goto L230;
    }
    minn = maxn;
    goto L200;

/*     POSITION FOUND */
L230:
    jj = kk + (*isz << 1) * (*nn - minn - 1);
    if (*nrp == 0) {
	goto L240;
    }
/*     EXFILE RECORD EXTENDED FORMAT. */
    jj = jj + (*nrp << 3) + 4;
    mm = jj + 5;
    goto L250;
/*     EXFILE RECORD STANDARD FORMAT. */
L240:
    jj += 10;
    mm = jj + (*isz << 1) - 3;
L250:
    i__ = 0;
    i__1 = mm;
    for (j = jj; j <= i__1; ++j) {
	++i__;
	if (*nrp > 0) {
	    ibuff[i__ + 6] = ebuf_1.ebuff[j - 1];
	}
/* L260: */
	ibuff[i__] = ebuf_1.ebuff[j - 1];
    }

    return 0;
} /* eread_ */

