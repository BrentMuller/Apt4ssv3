/* APT202.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    doublereal dsname;
    integer namsub;
} dsname_;

#define dsname_1 dsname_

struct {
    doublereal psname, cs1nam, cs2nam;
    integer ipssub, ics1sb, ics2sb;
} srfnam_;

#define srfnam_1 srfnam_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;

/* *** SOURCE FILE : M0000848.V07   *** */


/* .....   FORTRAN SUBROUTINE                 APT202...    4/1/69  RC */

/* Subroutine */ int apt202_(doublereal *adress, integer *isrflg)
{
    /* Initialized data */

    static char dollar[1] = "$";
    static char hname[8] = "NONAME  ";

    /* System generated locals */
    integer i__1;
    static doublereal equiv_5[1], equiv_6[1];

    /* Local variables */
    static integer i__, j, k;
#define x ((doublereal *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd;
    extern integer bcdf_(char *, ftnlen);
    static integer mode;
#define cval (equiv_5)
    static char temp[4];
    extern /* Subroutine */ int incan_(integer *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define itemp ((integer *)equiv_6)
#define iskip ((integer *)equiv_5)
    static integer isize;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer addrss_(doublereal *), xcanon_(integer *);
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *);
    static integer isbsct;
    extern /* Subroutine */ int holfrm_(integer *, char *, integer *, integer 
	    *, integer *, ftnlen);
#define tmpnam (equiv_6)


/*  PURPOSE         TO STORE THE SURFACE NAMES AND SUBSCRIPTS */
/*                  INTO COMMON BLOCKS DSNAME AND SRFNAM */

/*  CALLING SEQNCE  CALL APT202(ADRESS,ISRFLG) */

/*  ARGUMENTS       ADRESS    INDEX TO SURFACE DATA */
/*                  ISRFLG    FLAG POINTER FOR SURFACE -- */
/*                                 1.  PART SURFACE */
/*                                 2.  DRIVE SURFACE */
/*                                 3.  CHECK SURFACE 1 */
/*                                 4.  CHECK SURFACE 2 */

/*  CALLED BY       APT234,  FROM,  GOTO */

/*  SUBSIDIARIES    UNPACK */
/*  DIAGNOSTICS     NONE */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*        COMMON BLOCKS FOR SURFACE NAME AND SUBSCRIPT STORAGE */

/*     23.   DSNAME BLOCK */

/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*     24.   SRFNAM BLOCK */

/* ...     INFORMATION ASSOCIATED WITH CANONICAL FORMS STORAGE */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






    /* Parameter adjustments */
    --adress;

    /* Function Body */

/*     ------------------------------------------------------------ */

    unpack_(&adress[1], &mode, &isize, &isbsct);
    if (isbsct > 1) {
	goto L200;
    }
    k = isize + 1;
    *tmpnam = adress[k];
    holfrm_(itemp, temp, &c__1, &c__4, &nwd, (ftnlen)4);
L5:
    if (*(unsigned char *)&dollar[0] == *(unsigned char *)temp) {
	itemp[0] = bcdf_(hname, (ftnlen)4);
	itemp[1] = bcdf_(hname + 4, (ftnlen)2);
    }

/*        BRANCH FOR PROPER SURFACE GIVEN BY ISRFLG */
    switch (*isrflg) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }

L10:
    srfnam_1.psname = *tmpnam;
    srfnam_1.ipssub = isbsct;
    goto L100;

L20:
    dsname_1.dsname = *tmpnam;
    dsname_1.namsub = isbsct;
    goto L100;

L30:
    srfnam_1.cs1nam = *tmpnam;
    srfnam_1.ics1sb = isbsct;
    goto L100;

L40:
    srfnam_1.cs2nam = *tmpnam;
    srfnam_1.ics2sb = isbsct;

L100:
    return 0;



/* ...     DETERMINE VIRTUAL INDEX OF ADRESS(1) IN X-ARRAY */

L200:
    i__ = (addrss_(&adress[1]) - addrss_(x)) / idef_1.kwrdsz + isize + 1;
    k = i__;
    if (ldef_1.canflg) {
	incan_(&i__);
    }

/* ...     FIND BCD NAME OF THIS SURFACE */

    i__1 = isbsct;
    for (j = 2; j <= i__1; ++j) {
L250:
	*cval = x[k - 1];
	if (*iskip <= 0 || *iskip > 1024) {
	    goto L300;
	}
	i__ += *iskip;
	k = i__;
	if (ldef_1.canflg) {
	    k = xcanon_(&i__);
	}
	goto L250;
L300:
	k = k + isize + 1;
	i__ = i__ + isize + 1;
/* L400: */
    }
    *tmpnam = x[k - 1];
    goto L5;
} /* apt202_ */

#undef tmpnam
#undef bcanon
#undef iskip
#undef itemp
#undef sscan
#undef canon
#undef cval
#undef can
#undef x


