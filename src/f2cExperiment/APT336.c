/* APT336.f -- translated by f2c (version 20100827).
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
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer cerdm, cercnt, cerad1[34], cerad2[34];
} clerrw_;

#define clerrw_1 clerrw_

struct {
    char certxt[2280];
} clerrt_;

#define clerrt_1 clerrt_

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
static integer c__34 = 34;
static integer c__36 = 36;
static integer c__5 = 5;
static integer c__42 = 42;
static integer c__17 = 17;
static integer c__59 = 59;
static integer c__8 = 8;
static integer c__67 = 67;
static integer c__4 = 4;
static integer c__15 = 15;
static integer c__54 = 54;

/* *** SOURCE FILE : M0001851.V08   *** */


/* .....FORTRAN SUBROUTINE              APT336                 8/1/68  AR */
/* PURPOSE      TO WRITE ON THE VERIFICATION LISTING THE CLEDITOR */
/*              ERROR MESSAGES. */
/* LINKAGE      CALL APT336(IERROR,SUBNAM) */
/* ARGUMENTS    IERROR    INTEGER VARIABLE CONTAING THE ERROR NUMBER */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt336_(integer *ierror, char *subnam, ftnlen subnam_len)
{
    /* Initialized data */

    static integer ierrn = 0;
    static integer errlev[4] = { 0,0,0,0 };
    static char notext[54] = " THERE IS NO DIAGNOSTIC MESSAGE FOR THIS ERROR"
	    " NUMBER ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l1;
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen);
#define cflags ((logical *)&super_1)
    extern /* Subroutine */ int cprint_(char *, ftnlen);
#define lxtras ((logical *)&super_1 + 9)


/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */









/* ...COMMON/CLERR/ SPLIT INTO /CLERRW/ FOR INTEGERS & /CLERRT/ FOR TEXT */












/* ... INITILIZE ARRAY INDICATING WHICH ERRORS ARE OF SEVERITY LEVEL FOUR. */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




    cform_("0       ****  CL EDITING ERROR NO.", darray_1.darray, &c__1, &
	    c__34, (ftnlen)34, (ftnlen)120);
    iconv_(ierror, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cform_(" FROM SUBROUTINE ", darray_1.darray, &c__42, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(subnam, darray_1.darray, &c__59, &c__8, (ftnlen)8, (ftnlen)120);
    cform_("****", darray_1.darray, &c__67, &c__4, (ftnlen)4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    i__1 = clerrw_1.cerdm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*ierror == clerrw_1.cerad1[i__ - 1]) {
	    goto L40;
	}
/* L10: */
    }
    cform_(notext, darray_1.darray, &c__15, &c__54, (ftnlen)54, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L60;
L40:
    k = clerrw_1.cerad2[i__ - 1];
    if (i__ == 1) {
	j = 1;
    } else {
	j = clerrw_1.cerad2[i__ - 2] + 1;
    }
    l1 = 11;
    i__1 = k;
    for (i__ = j; i__ <= i__1; ++i__) {
	if (l1 >= 113) {
	    cprint_(darray_1.darray, (ftnlen)120);
	    l1 = 11;
	}
	l1 += 4;
	s_copy(darray_1.darray + (l1 - 1), clerrt_1.certxt + (i__ - 1 << 2), (
		ftnlen)4, (ftnlen)4);
/* L50: */
    }
    cprint_(darray_1.darray, (ftnlen)120);
/* ... SET ERROR LEVEL INDICATOR FOR SUPERVISOR. */
L60:
    ++super_1.xtras[0];
    if (super_1.errx > 4) {
	goto L320;
    }
    super_1.errx = 4;
    i__1 = ierrn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*ierror == errlev[i__ - 1]) {
	    goto L320;
	}
/* L310: */
    }
    super_1.errx = 8;
L320:
    return 0;
} /* apt336_ */

#undef lxtras
#undef cflags
#undef area3


