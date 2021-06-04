/* APT309.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__8 = 8;
static integer c__10 = 10;
static integer c__34 = 34;
static integer c__4 = 4;
static integer c__51 = 51;
static integer c__43 = 43;
static integer c__7 = 7;
static integer c__56 = 56;
static integer c__16 = 16;
static integer c__72 = 72;
static integer c__14 = 14;
static integer c__20 = 20;

/* *** SOURCE FILE : M0011537.V07   *** */


/* .....FORTRAN SUBROUTINE                   APT309 */
/* PURPOSE      TO WRITE ON THE VERIFICATION LISTING THE GEOMETRIC */
/*              DEFINITION ERROR MESSAGES PRODUCED BY THE */
/*              DEFINITION REDUCTION SUBROUTINES. */
/* LINKAGE      CALL APT309 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt309_(void)
{
    /* Initialized data */

    static char ifmt4[20] = " DEFINITION WARNING ";
    static integer ierrn = 20;
    static integer nerrlv[20] = { 2,3,8,9,30,40,45,49,50,71,84,92,94,5129,0,0,
	    0,0,0,0 };
    static char ifmt1[20] = " DEFINITION ERROR   ";
    static char fmt2[8] = "ISN NO. ";
    static char ifmt3[20] = " INVALID ERROR CODE ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, ii, jj, iii, nwd;
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
#define irecrd ((doublereal *)&editor_1)
#define jrecrd ((integer *)&editor_1)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), cleror_(integer *), cprint_(char *,
	     ftnlen);

/* THIS ROUTINE WRITES THE GEOMETRIC DEFINITION ERROR DIAGNOSTIC MESSAGE */
/* ASSOCIATED WITH THE ERROR CODE IN IRECRD(4) ON THE VERIFICATION */
/* LISTING TAPE. A CHECK IS MADE TO SEE THAT THE ERROR CODE DOES NOT */
/* EXCEED 88. */






/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



/*      DIMENSION NERRLV(20) */

    j = jrecrd[3];
    ii = j / 10000;
    iii = j - ii * 10000;
    i__ = jrecrd[7];
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    iconv_(&j, darray_1.darray, &c__2, &c__8, (ftnlen)120);
    cform_(".", darray_1.darray, &c__10, &c__1, (ftnlen)1, (ftnlen)120);
    iconv_(&i__, darray_1.darray, &c__34, &c__4, (ftnlen)120);
    iconv_(&iii, darray_1.darray, &c__51, &c__4, (ftnlen)120);
    cform_(fmt2, darray_1.darray, &c__43, &c__7, (ftnlen)8, (ftnlen)120);
    cform_("FROM SUBROUTINE ", darray_1.darray, &c__56, &c__16, (ftnlen)16, (
	    ftnlen)120);
    holfrm_(&irecrd[4], darray_1.darray, &c__72, &c__8, &nwd, (ftnlen)120);
    if (jrecrd[7] >= 5000 && jrecrd[7] <= 5999) {
	goto L700;
    }
    if (jrecrd[7] > 98) {
	goto L100;
    }
    i__1 = ierrn;
    for (jj = 1; jj <= i__1; ++jj) {
	if (i__ == nerrlv[jj - 1]) {
	    goto L810;
	}
/* L800: */
    }
L700:
    if (jrecrd[7] == 5129) {
	goto L810;
    }
    cform_(ifmt1, darray_1.darray, &c__14, &c__20, (ftnlen)20, (ftnlen)120);

    goto L915;
L810:
    cform_(ifmt4, darray_1.darray, &c__14, &c__20, (ftnlen)20, (ftnlen)120);

L915:
    cprint_(darray_1.darray, (ftnlen)120);
L950:
    cleror_(&i__);

    return 0;
L100:
    cform_(ifmt3, darray_1.darray, &c__14, &c__20, (ftnlen)20, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    goto L950;
} /* apt309_ */

#undef jrecrd
#undef irecrd
#undef area3


