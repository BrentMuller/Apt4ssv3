/* APT302.f -- translated by f2c (version 20100827).
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
    doublereal editor[1500];
} editor_;

#define editor_1 editor_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__2 = 2;
static integer c__5 = 5;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__20 = 20;
static integer c__22 = 22;
static integer c__28 = 28;
static integer c__29 = 29;
static integer c__11 = 11;
static integer c__17 = 17;
static integer c__24 = 24;
static integer c__41 = 41;
static integer c__58 = 58;
static integer c__75 = 75;
static integer c__92 = 92;
static integer c__109 = 109;
static integer c__16 = 16;
static integer c__10 = 10;
static integer c__30027 = 30027;

/* *** SOURCE FILE : M0011535.W02   *** */


/* ......     FORTRAN SUBROUTINE APT302             1/71   R.N. */
/*  PURPOSE     TO WRITE OUT ON THE VERIFICATION LISTING THE DATA */
/*              BEING PLACED ON CLFILE AND TO OUTPUT ERROR MESSAGES */
/*              OR OTHER INFORMATION HELPFUL TO THE PART PROGRAMMER. */
/*  LINKAGE     CALL APT302 */
/*  ARGUMENTS   NONE - APT302 WRITES ON THE VERIFICATION LISTING */
/*                     THE INFORMATION STORED IN RECORD. */
/*  SUBSIDIARIES  APT309,APT331,APT332,FCONV,ICONV,CFORM,CPRINT */

/* Subroutine */ int apt302_(void)
{
    /* Initialized data */

    static logical goflg = TRUE_;
    static char hcirc[12] = " = CIRCLE/  ";
    static char contr[6] = "CONT. ";
    static integer ixyz = 0;
    static integer kcont = 0;
    static char cut[6] = "CUT   ";
    static char blank[6] = "      ";
    static char hfini[6] = "FINI  ";
    static char godlta[6] = "GODLTA";
    static char start[6] = "START ";
    static char jblk[2] = "  ";
    static char jsbk[2] = "S ";
    static char atapno[8] = "0     / ";
    static char parnt[6] = "(    )";
    static struct {
	char e_1[12];
	} equiv_8 = { "0     /     " };


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n, i1, nwd, nadd, incr;
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt331_(void), apt332_(void), apt336_(integer 
	    *, char *, ftnlen), apt309_(void), cform_(char *, char *, integer 
	    *, integer *, ftnlen, ftnlen);
    static integer lsave;
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), iconv_(integer *, char *, integer *
	    , integer *, ftnlen);
    static integer nplus;
#define branch ((integer *)&editor_1 + 1076)
#define jrecrd ((integer *)&editor_1)
#define record ((doublereal *)&editor_1)
#define srecrd ((real *)&editor_1)
#define numcld ((integer *)&editor_1 + 1186)
#define tapeno ((char *)&equiv_8)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), cprint_(char *, ftnlen);
#define rtapno ((char *)&equiv_8)
    static char rectyp[6];
#define multax ((integer *)&editor_1 + 1936)
    static char testwd[6];
#define numwds ((integer *)&editor_1 + 5)


/*     CLPRINT PRINTS THE RECORDS RECEIVED FROM EXFILE */

/*     *****   COMMON-EQUIVALENCE BLOCK VARIABLES  ***** */






/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





/* .    TAPENO SEQUENCE NO. */

    s_copy(rtapno, atapno, (ftnlen)8, (ftnlen)8);
    i__ = jrecrd[3];
    i1 = i__ / 10000;
    if (i1 != 0) {
	iconv_(&i1, tapeno, &c__2, &c__5, (ftnlen)12);
    }
    i__1 = i__ - i1 * 10000;
    iconv_(&i__1, tapeno, &c__8, &c__4, (ftnlen)12);
    s_copy(darray_1.darray, tapeno, (ftnlen)12, (ftnlen)12);
    holfrm_(record, rectyp, &c__1, &c__6, &nwd, (ftnlen)6);
    holfrm_(&record[4], testwd, &c__1, &c__6, &nwd, (ftnlen)6);

/* .    BRANCH */

    if (*branch >= 22) {
	goto L4000;
    }
    if (*branch == 2) {
	goto L2000;
    }
    if (*branch == 6) {
	goto L1000;
    }
    if (*branch == 3) {
	goto L5000;
    }
    if (*branch == 5) {
	goto L6000;
    }
    if (*branch <= 16) {
	goto L4000;
    }
    if (*branch == 17) {
	goto L7000;
    }
    if (*branch == 19) {
	goto L1500;
    }
    if (*branch == 21) {
	goto L3000;
    }
    goto L4000;

/* .    PRINT LIST */

L100:
    cprint_(darray_1.darray, (ftnlen)120);
L200:
    return 0;

/* .    FINI */

L1000:
    s_copy(darray_1.darray + 13, hfini, (ftnlen)6, (ftnlen)6);
    goto L100;

/* .    ARLEM */

L1500:
    s_copy(darray_1.darray + 13, rectyp, (ftnlen)6, (ftnlen)6);
    goto L100;


/* .    CLDATA RECORDS */

L2000:
    if (jrecrd[7] >= 2) {
	goto L2500;
    }
    if (s_cmp(testwd, godlta, (ftnlen)6, (ftnlen)6) != 0) {
	goto L2020;
    }
    cform_("   $$", darray_1.darray, &c__7, &c__5, (ftnlen)5, (ftnlen)120);
    goflg = FALSE_;
L2020:
    s_copy(darray_1.darray + 13, testwd, (ftnlen)6, (ftnlen)6);
    if (jrecrd[5] == 2) {
	goto L100;
    }
    cform_("/", darray_1.darray, &c__20, &c__1, (ftnlen)1, (ftnlen)120);
    holfrm_(&record[6], darray_1.darray, &c__22, &c__8, &nwd, (ftnlen)120);
    cform_(parnt, darray_1.darray, &c__28, &c__6, (ftnlen)6, (ftnlen)120);
    iconv_(&jrecrd[15], darray_1.darray, &c__29, &c__4, (ftnlen)120);
    if (jrecrd[5] <= 6) {
	goto L100;
    }
    s_copy(darray_1.darray + 33, hcirc, (ftnlen)12, (ftnlen)12);
    k = 44;
    for (i__ = 10; i__ <= 16; ++i__) {
	fconv_(&record[i__ - 1], darray_1.darray, &k, &c__11, &c__4, (ftnlen)
		120);
/* L2010: */
	k += 11;
    }
    goto L100;

L2500:
    if (ixyz == 0) {
	goto L2600;
    }
    cform_(" ", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
L2510:
    if (kcont == 0) {
	goto L2550;
    }
    s_copy(darray_1.darray + 13, contr, (ftnlen)6, (ftnlen)6);
    cprint_(darray_1.darray, (ftnlen)120);
L2550:
    if (*numcld > 0 && goflg) {
	goto L2800;
    }
    goflg = TRUE_;
    if (*multax != 1) {
	goto L2560;
    }
    nplus = *numwds;
    nadd = 5;
    incr = 7;
    goto L2570;
L2560:
    nplus = *numwds + 3;
    nadd = 2;
    incr = 4;
L2570:
    i__1 = nplus;
    i__2 = incr;
    for (i__ = 5; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	k = i__ + nadd;
	l = 15;
	i__3 = k;
	for (j = i__; j <= i__3; ++j) {
	    if ((d__1 = record[j - 1], abs(d__1)) < 100.f) {
		goto L2572;
	    }
	    fconv_(&record[j - 1], darray_1.darray, &l, &c__17, &c__7, (
		    ftnlen)120);
	    goto L2573;
L2572:
	    n = l + 6;
	    fconv_(&record[j - 1], darray_1.darray, &n, &c__11, &c__7, (
		    ftnlen)120);
L2573:
	    l += 17;
/* L2574: */
	}
	cprint_(darray_1.darray, (ftnlen)120);
/* L2580: */
    }
    l = 6;
L2590:
    kcont = 1;
    if (jrecrd[(nplus << 1) - l - 1] == 3) {
	kcont = 0;
    }
    goto L200;

/*     FIRST TIME */
L2600:
    cform_("X", darray_1.darray, &c__24, &c__1, (ftnlen)1, (ftnlen)120);
    cform_("Y", darray_1.darray, &c__41, &c__1, (ftnlen)1, (ftnlen)120);
    cform_("Z", darray_1.darray, &c__58, &c__1, (ftnlen)1, (ftnlen)120);
    if (*multax != 1) {
	goto L2650;
    }
    cform_("I", darray_1.darray, &c__75, &c__1, (ftnlen)1, (ftnlen)120);
    cform_("J", darray_1.darray, &c__92, &c__1, (ftnlen)1, (ftnlen)120);
    cform_("K", darray_1.darray, &c__109, &c__1, (ftnlen)1, (ftnlen)120);
L2650:
    cprint_(darray_1.darray, (ftnlen)120);
    ixyz = 1;
    goto L2510;

/*     CLDAT EXTENDED OUTPUT */
L2800:
    nplus = *numwds;
    incr = (*numcld << 2) + 1;
    i__2 = nplus;
    i__1 = incr;
    for (i__ = 3; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
	m = 6;
	i__3 = incr;
	for (j = 2; j <= i__3; j += 4) {
	    m += 3;
	    holfrm_(&record[i__ + j - 1], darray_1.darray, &m, &c__8, &nwd, (
		    ftnlen)120);
	    m += 5;
	    for (k = 1; k <= 3; ++k) {
		l = i__ + j + k;
		if ((d__1 = record[l - 1], abs(d__1)) < 100.f) {
		    goto L2810;
		}
		fconv_(&record[l - 1], darray_1.darray, &m, &c__16, &c__6, (
			ftnlen)120);
		goto L2820;
L2810:
		n = m + 5;
		fconv_(&record[l - 1], darray_1.darray, &n, &c__11, &c__6, (
			ftnlen)120);
L2820:
		m += 16;
	    }
	    if (m < 100) {
		goto L2830;
	    }
	    cprint_(darray_1.darray, (ftnlen)120);
	    m = 6;
L2830:
	    ;
	}
	if (m != 6) {
	    cprint_(darray_1.darray, (ftnlen)120);
	}
/* L2840: */
    }
    l = nplus + 4 - incr << 1;
    goto L2590;

/*     CLDAT/START,INDEX  ; CLDAT/NOMORE,INDEX */
L3000:
    *numcld = 0;
/* .    IS EXTENDED CLDATA FORMAT GIVEN ? */
    if (s_cmp(testwd, start, (ftnlen)6, (ftnlen)6) == 0) {
	*numcld = (*numwds - 4) / 2;
    }
    if (s_cmp(testwd + 4, jblk, (ftnlen)2, (ftnlen)2) == 0 || s_cmp(testwd + 
	    4, jsbk, (ftnlen)2, (ftnlen)2) == 0) {
	*numcld = *numwds / 2;
    }
/* .    POST PROCESSOR COMMAND */
L4000:
    s_copy(darray_1.darray + 13, rectyp, (ftnlen)6, (ftnlen)6);
    if (jrecrd[5] == 2 && s_cmp(testwd, blank, (ftnlen)6, (ftnlen)6) == 0) {
	goto L100;
    }
    cform_("/", darray_1.darray, &c__20, &c__1, (ftnlen)1, (ftnlen)120);
    j = 4;
    lsave = 0;
L4010:
    k = 21;
L4020:
    l = jrecrd[(j << 1) - 1];
    switch (l) {
	case 1:  goto L4100;
	case 2:  goto L4200;
	case 3:  goto L4300;
	case 4:  goto L4400;
	case 5:  goto L4500;
    }

/* .    FLOATING POINT DATA ITEM */

L4100:
    if (k > 109) {
	goto L4600;
    }
    m = 4;
    if (record[j] > 9999.9f) {
	m = 1;
    }
    fconv_(&record[j], darray_1.darray, &k, &c__10, &m, (ftnlen)120);
    k += 10;
    j += 2;
    goto L4700;

/* .    ALPHA NUMERIC DATA ITEM */
L4200:
    if (k > 111) {
	goto L4600;
    }
    i__1 = k + 1;
    holfrm_(&record[j], darray_1.darray, &i__1, &c__6, &nwd, (ftnlen)120);
    k += 8;
    j += 2;
    goto L4700;

/* .    ALPHA NUMERIC DATA ITEM STRING */

L4300:
    l = jrecrd[(j << 1) + 1] - 1 << 3;
    if (jrecrd[(j << 1) + 1] <= 1) {
	goto L4303;
    }
    if (k + l > 119) {
	goto L4600;
    }
    i__1 = k + 1;
    holfrm_(&record[j + 2], darray_1.darray, &i__1, &l, &nwd, (ftnlen)120);
L4303:
    k = k + l + 2;
    j = j + jrecrd[(j << 1) + 1] + 2;
    if (*branch == 8 || *branch == 12 || *branch == 14 || s_cmp(rectyp, cut, (
	    ftnlen)6, (ftnlen)6) == 0) {
	*(unsigned char *)&darray_1.darray[19] = ' ';
    }
    goto L4700;

/* .    GEOMETRIC DATA ITEM STRING */

L4400:
    l = jrecrd[(j << 1) + 1];
L4404:
    if (k + l * 11 > 119) {
	goto L4650;
    }
L4405:
    j += 2;
    i__1 = l;
    for (n = 1; n <= i__1; ++n) {
	fconv_(&record[j - 1], darray_1.darray, &k, &c__10, &c__4, (ftnlen)
		120);
	k += 10;
	++j;
	if (n == l) {
	    goto L4700;
	}
	cform_(",", darray_1.darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
/* L4410: */
	++k;
    }
    goto L4700;

/* .    ERROR */

L4500:
    apt336_(&c__30027, "APT302  ", (ftnlen)8);
    goto L100;

L4600:
    cprint_(darray_1.darray, (ftnlen)120);
    goto L4010;
L4650:
    if (k == 21) {
	goto L4660;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    goto L4010;
L4660:
    lsave = l - 9;
    l = 9;
    goto L4405;
L4700:
    if (j - 3 >= *numwds) {
	goto L100;
    }
    cform_(",", darray_1.darray, &k, &c__1, (ftnlen)1, (ftnlen)120);
    ++k;
    if (lsave > 0) {
	goto L4720;
    }
    goto L4020;
L4720:
    cprint_(darray_1.darray, (ftnlen)120);
    k = 21;
    l = lsave;
    lsave = 0;
    j += -2;
    goto L4404;
/* .    AERR */

L5000:
    apt331_();
    goto L200;

/* .    DYNDMP */

L6000:
    apt332_();
    goto L200;

/* .    GERR */

L7000:
    apt309_();
    goto L200;
} /* apt302_ */

#undef numwds
#undef multax
#undef rtapno
#undef tapeno
#undef numcld
#undef srecrd
#undef record
#undef jrecrd
#undef branch
#undef area3
#undef area2
#undef area1


