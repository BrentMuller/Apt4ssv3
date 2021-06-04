/* CHKSRF.f -- translated by f2c (version 20100827).
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
    logical lgchk, lintck, lavctl, lvaxis;
} rmflgs_;

#define rmflgs_1 rmflgs_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : CHKSRF.ORG   *** */

/* Subroutine */ int chksrf_(doublereal *surf, doublereal *donoff)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer nwd;
    static char test[2];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);


/* .... PROCESS CHKSRF STATEMENT */

/*     ARGUMENTS: */

/*        SURF = PS            CHECK FOR INTERFERENCE WITH PART SURFACE */
/*             = SURFACE_NAME  CHECK FOR INTERFERENCE WITH NAMED SURFACE */

/*                             NOTE: ONLY PS IMPLEMENTED */

/*      DONOFF = ON            SET INTERFERENCE CHECKING FLAG */
/*             = OFF           CANCEL INTERFERENCE CHECKING FLAG */




/* .... NEW REGIONAL MILLING FLAGS */



/*     LGCHK  - GOUGE CHECK FLAG */
/*     LINTCK - INTERFERENCE CHECKING FLAG */
/*     LAVCTL - AVOIDANCE CONTROL FLAG */
/*     LVAXIS - VARIABLE TOOL AXIS FLAG */


    holfrm_(surf, test, &c__1, &c__2, &nwd, (ftnlen)2);

    if (s_cmp(test, "PS", (ftnlen)2, (ftnlen)2) == 0) {
/* .... CHKSRF/PS,... */
	holfrm_(donoff, test, &c__1, &c__2, &nwd, (ftnlen)2);
	if (s_cmp(test, "ON", (ftnlen)2, (ftnlen)2) == 0) {
	    rmflgs_1.lintck = TRUE_;
	} else {
	    rmflgs_1.lintck = FALSE_;
	}
    } else {
/* .... CHKSRF/SURFACE_NAME,... */
    }

    return 0;
} /* chksrf_ */

