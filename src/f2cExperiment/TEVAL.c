/* TEVAL.f -- translated by f2c (version 20100827).
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
static integer c__8 = 8;

/* *** SOURCE FILE : TEVAL.V01   *** */

/* Subroutine */ int teval_(char *name__, doublereal *trm, doublereal *data, 
	ftnlen name_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer slen, ipos;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), tmdcs_(doublereal *, doublereal *), abnend_(void)
	    , tvdafs_(doublereal *, doublereal *), cprint_(char *, ftnlen), 
	    ttorus_(doublereal *, doublereal *);




/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





    /* Parameter adjustments */
    --data;
    trm -= 5;

    /* Function Body */
    if (s_cmp(name__, "MDCS", (ftnlen)8, (ftnlen)4) == 0) {
	tmdcs_(&trm[5], &data[1]);
    } else if (s_cmp(name__, "TORUS", (ftnlen)8, (ftnlen)5) == 0) {
	ttorus_(&trm[5], &data[1]);
    } else if (s_cmp(name__, "VDAFS", (ftnlen)8, (ftnlen)5) == 0) {
	tvdafs_(&trm[5], &data[1]);
    } else {
	slen = 0;
	cform_("0 TRANSFORMATOR FOR NON-NATIVE SURFACE TYPE :", 
		darray_1.darray, &c__1, &slen, (ftnlen)45, (ftnlen)120);
	ipos = slen + 2;
	cform_(name__, darray_1.darray, &ipos, &c__8, (ftnlen)8, (ftnlen)120);
	ipos += 10;
	slen = 0;
	cform_(": NOT AVAILABLE", darray_1.darray, &ipos, &slen, (ftnlen)15, (
		ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	abnend_();
    }
    return 0;
} /* teval_ */

