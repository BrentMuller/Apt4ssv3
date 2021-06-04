/* LINKF.f -- translated by f2c (version 20100827).
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
static integer c__25 = 25;
static integer c__26 = 26;
static integer c__18 = 18;
static integer c__43 = 43;
static integer c__8 = 8;



/*  *  LINKF  *   FORTRAN 77 SUBROUTINE   6-DEC-85   E.MCLELLAN */

/*  PURPOSE:     TO CALL NEXT PHASE */

/*  CALLING SEQUENCE: */
/*                   CALL LINKF(PHASE) */
/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*           PHASE   CHARACTER  PHASE NAME */

/*  GLOBAL VARIABLES: NONE */

/*  LOCAL VARIABLES: NONE */

/*  FILES: NONE */

/*  SUBSIDIARIES: NONE */

/* Subroutine */ int linkf_(char *phase, ftnlen phase_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int cled_(void), exec_(void), cform_(char *, char 
	    *, integer *, integer *, ftnlen, ftnlen), start_(void), abnend_(
	    void), acntrl_(void), cprint_(char *, ftnlen);





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    if (s_cmp(phase, "TRANSLAT", (ftnlen)8, (ftnlen)8) == 0) {
	start_();
    } else if (s_cmp(phase, "XECUTION", (ftnlen)8, (ftnlen)8) == 0) {
	exec_();
    } else if (s_cmp(phase, "CLEDITOR", (ftnlen)8, (ftnlen)8) == 0) {
	cled_();
    } else if (s_cmp(phase, "POSTEXEC", (ftnlen)8, (ftnlen)8) == 0) {
	acntrl_();
    } else {
	cform_("  *** FAILURE IN LINKF - ", darray_1.darray, &c__1, &c__25, (
		ftnlen)25, (ftnlen)120);
	cform_("REQUESTED PHASE = ", darray_1.darray, &c__26, &c__18, (ftnlen)
		18, (ftnlen)120);
	cform_(phase, darray_1.darray, &c__43, &c__8, (ftnlen)8, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	abnend_();
    }

    return 0;
} /* linkf_ */

