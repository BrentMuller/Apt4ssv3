/* ERRLOD.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__15 = 15;
static integer c__16 = 16;
static integer c__8 = 8;
static integer c__24 = 24;
static integer c__5 = 5;
static integer c__36 = 36;
static integer c__3 = 3;
static integer c__44 = 44;
static integer c__17 = 17;
static integer c__61 = 61;
static integer c__69 = 69;
static integer c__6 = 6;
static integer c__10 = 10;
static integer c__11 = 11;
static integer c__22 = 22;
static integer c__23 = 23;
static integer c__14 = 14;
static integer c__19 = 19;
static integer c__20 = 20;

/* *** SOURCE FILE : M0008144.V03   *** */

/* Subroutine */ int errlod_(integer *iret, char *name__, ftnlen name_len)
{
    /* Initialized data */

    static char erro[8] = "  ERROR ";
    static char subnam[8] = " LOADMO ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), iconv_(integer *, char *, integer *, integer *, 
	    ftnlen), cprint_(char *, ftnlen), errout_(integer *);


/* CALLS APT IV ERROR ROUTINE FOR ERROR MESSAGES */
/*  FURTHER EXPLAINING ERROR TEXTS ARE OUTPUT THRU DARRAY */




/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





    cform_(" ***** DYNLOAD ", darray_1.darray, &c__1, &c__15, (ftnlen)15, (
	    ftnlen)120);
    cform_(erro, darray_1.darray, &c__16, &c__8, (ftnlen)8, (ftnlen)120);
    iconv_(iret, darray_1.darray, &c__24, &c__5, (ftnlen)120);
    cform_("ISN", darray_1.darray, &c__36, &c__3, (ftnlen)3, (ftnlen)120);
    cform_(" FROM SUBROUTINE ", darray_1.darray, &c__44, &c__17, (ftnlen)17, (
	    ftnlen)120);
    cform_(subnam, darray_1.darray, &c__61, &c__8, (ftnlen)8, (ftnlen)120);
    cform_(" *****", darray_1.darray, &c__69, &c__6, (ftnlen)6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    switch (*iret) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
    }
    goto L90;

/* WANTED MODULE CANNOT BE FOUND */
L10:
    cform_(" MODULE = ", darray_1.darray, &c__1, &c__10, (ftnlen)10, (ftnlen)
	    120);
    cform_(name__, darray_1.darray, &c__11, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* EXTERNAL REFERENCE IS NOT SOLVED */
L20:
    cform_(" EXTERNAL REFERENCE = ", darray_1.darray, &c__1, &c__22, (ftnlen)
	    22, (ftnlen)120);
    cform_(name__, darray_1.darray, &c__23, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* NOT ENOUGH CORE AVAILABLE */
L30:
    cform_(" FOR MODULE = ", darray_1.darray, &c__1, &c__14, (ftnlen)14, (
	    ftnlen)120);
    cform_(name__, darray_1.darray, &c__15, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* MODULE NOT IN LIBRARY */
L40:
    cform_(" MODULE = ", darray_1.darray, &c__1, &c__10, (ftnlen)10, (ftnlen)
	    120);
    cform_(name__, darray_1.darray, &c__11, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* CESD TABLE FOR LOADED MODULES TOO SHORT */
L50:
    cform_(" NEXT CESD ENTRY = ", darray_1.darray, &c__1, &c__19, (ftnlen)19, 
	    (ftnlen)120);
    cform_(name__, darray_1.darray, &c__20, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* CESD-TABLE FOR LOAD-MODULE TOO SHORT */
L60:
    cform_(" MODULE = ", darray_1.darray, &c__1, &c__10, (ftnlen)10, (ftnlen)
	    120);
    cform_(name__, darray_1.darray, &c__11, &c__8, (ftnlen)8, (ftnlen)120);
    goto L80;

/* TOO MANY MODULES TO BE LOADED */
L70:
    cform_(" MODULE = ", darray_1.darray, &c__1, &c__10, (ftnlen)10, (ftnlen)
	    120);
    cform_(name__, darray_1.darray, &c__11, &c__8, (ftnlen)8, (ftnlen)120);

L80:
    cprint_(darray_1.darray, (ftnlen)120);
    i__1 = *iret + 1000;
    errout_(&i__1);

L90:
    return 0;
} /* errlod_ */

