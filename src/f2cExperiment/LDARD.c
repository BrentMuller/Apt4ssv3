/* LDARD.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__16 = 16;
static integer c__9 = 9;
static integer c__11 = 11;
static integer c__4 = 4;
static integer c__19 = 19;
static integer c__31 = 31;
static integer c__22 = 22;
static integer c__42 = 42;
static integer c__10 = 10;
static integer c__5000 = 5000;

/* *** SOURCE FILE : M0002890.V10   *** */

/*     READ ROUTINE (LDARD) FOR LARGE DATA ARRAYS */

/* Subroutine */ int ldard_(integer *mod, doublereal *a, integer *number)
{
    /* Initialized data */

    static char bla[1] = " ";
    static char bla8[8] = "        ";

    /* System generated locals */
    integer i__1;
    static doublereal equiv_4[10], equiv_5[1];

    /* Local variables */
#define b (equiv_4)
    static integer i__, j, k;
#define ib ((integer *)equiv_4)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd;
    extern integer bcdf_(char *, ftnlen);
    static integer iend, mode;
    static char lmem[8];
    static integer ianz, isub, iret;
#define temp (equiv_5)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static char lname[16];
#define canon ((doublereal *)&_BLNK__1)
    static integer jmode;
    extern /* Subroutine */ int undef_(doublereal *);
    static doublereal sname[2];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define itemp ((integer *)equiv_5)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    static integer isize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int findme_(integer *, char *, integer *, ftnlen);
    static doublereal member;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), scpict_(doublereal *, char *, integer *, ftnlen), 
	    holfrm_(doublereal *, char *, integer *, integer *, integer *, 
	    ftnlen), cprint_(char *, ftnlen), sspict_(doublereal *, char *, 
	    integer *, ftnlen), rdsatz_(integer *, doublereal *, integer *, 
	    integer *, integer *);
    static integer isprnt, nrsatz;





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --a;

    /* Function Body */

    unpack_(&a[1], &mode, &isize, &isub);
    member = a[isize + 1];
    holfrm_(&member, lmem, &c__1, &c__8, &nwd, (ftnlen)8);
    sname[0] = member;
    itemp[0] = bcdf_(bla8, (ftnlen)4);
    itemp[1] = bcdf_(bla8 + 4, (ftnlen)4);
    sname[1] = *temp;
    holfrm_(sname, lname, &c__1, &c__16, &nwd, (ftnlen)16);
    if (isub == 0) {
	goto L8;
    }
    i__1 = isub + 10000000;
    iconv_(&i__1, lmem, &c__1, &c__8, (ftnlen)8);
    sname[0] = a[isub * isize + isub];
    holfrm_(sname, lname, &c__1, &c__8, &nwd, (ftnlen)16);
    for (k = 1; k <= 8; ++k) {
	if (*(unsigned char *)&lname[k - 1] == *(unsigned char *)&bla[0]) {
	    goto L5;
	}
	*(unsigned char *)&lmem[k - 1] = *(unsigned char *)&lname[k - 1];
L5:
	;
    }
    cform_(" (     )", lname, &c__9, &c__8, (ftnlen)8, (ftnlen)16);
    iconv_(&isub, lname, &c__11, &c__4, (ftnlen)16);
/*   OPEN READING FROM PDS */
L8:
    findme_(&c__19, lmem, &iret, (ftnlen)8);
    if (iret == 0) {
	goto L10;
    }
    cform_("0 CANNOT FIND FILE :          :", darray_1.darray, &c__1, &c__31, 
	    (ftnlen)31, (ftnlen)120);
    cform_(lmem, darray_1.darray, &c__22, &c__8, (ftnlen)8, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
L10:
    rdsatz_(&c__19, b, &ianz, &nrsatz, &iret);
    if (b[0] == sname[0]) {
	goto L20;
    }
    cform_("0 FILE :          : CONTAINS WRONG SURFACE", darray_1.darray, &
	    c__1, &c__42, (ftnlen)42, (ftnlen)120);
    cform_(lmem, darray_1.darray, &c__10, &c__8, (ftnlen)8, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
/*      READ SURFACE */
/*   RESTORE LENGTH */
L20:
    a[2] = (doublereal) ib[7];
/*   RESTORE SURFACE-TYPE */
    mode = ib[4];
/*   PREPARE RESTORAGE */
    iend = ib[7] + 40;
    j = 6;
    i__1 = iend;
    for (i__ = 42; i__ <= i__1; ++i__) {
	_BLNK__1.com[i__ - 1] = b[j - 1];
	++j;
	if (j <= 9) {
	    goto L30;
	}
	rdsatz_(&c__19, b, &ianz, &nrsatz, &iret);
	j = 1;
L30:
	;
    }
/*   STORE SURFACE */
    jmode = 1;
    apt094_(&jmode, &a[1], &_BLNK__1.com[40]);
    if (jmode != 1) {
	goto L99;
    }
    isprnt = 2;
    if (ssprt_1.sstest) {
	isprnt = 1;
    }
    if (! ssprt_1.ssprt) {
	return 0;
    }
/*    ONLY SSURF: OUTPUT VERIFICATION-LISTING */
    if (mode == 29) {
	sspict_(&_BLNK__1.com[40], lname, &isprnt, (ftnlen)16);
    }
    if (mode != 30) {
	return 0;
    }
    isprnt = 2;
    if (ssprt_1.sstest) {
	isprnt = 3;
    }
    scpict_(&_BLNK__1.com[40], lname, &isprnt, (ftnlen)16);
    return 0;
L99:
    error_(&c__5000, "READ    ", (ftnlen)8);
    undef_(&a[1]);
    return 0;
} /* ldard_ */

#undef bcanon
#undef itemp
#undef sscan
#undef canon
#undef temp
#undef can
#undef ib
#undef b


