/* APT105.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* Table of constant values */

static integer c__3 = 3;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0011441.V02   *** */

/* ........  FORTRAN SUBROUTINE  APT105                   5/1/72     RN */

/* Subroutine */ int apt105_(doublereal *result, integer *m, doublereal *sn, 
	integer *nt, doublereal *rm)
{
    static integer i__, j, l, n;
    static doublereal p[6];
    static integer iee, isc, ntp;
    extern /* Subroutine */ int ataper_(doublereal *, integer *, integer *, 
	    integer *, integer *), defext_(doublereal *), transf_(doublereal *
	    , doublereal *, integer *, integer *, integer *);


/*  PURPOSE  TO RETRIEVE CL POINT OR VECTOR FROM CLTAPE AND STORE IT */
/*           IN RESULT ARRAY. */

/*  LINKAGE   CALL  APT105 (RESULT ,M,SN,NT,RM) */

/*  ARGUMENTS   RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING POINT OR VECTOR DEFINED AS N TH POINT */
/*                      OR VECTOR OF A PREVIOUS MOTION STATEMENT. */
/*              M       INTEGER */
/*                        0   IF RESULT IS POINT */
/*                        1   IF RESULT IS VECTOR */
/*              SN      REAL NUMBER OF THE CLDAT SECTION */
/*              NT      INTEGER DATA TYPE */
/*                        1      2      3     4     5     6     7 */
/*                        TP     TA     TV    PDS   NDS   PPS   NPS */
/*              RM      REAL VALUE N CORRESPONDING TO DESIRED POINT */
/*                      OR VECTOR. */

/*  IMPORTANT VARIABLES */
/*              IEE     ERROR INDICATOR TO BE SET BY ATAPER WHEN THE */
/*                      SPECIFIED CL POINT DOES NOT EXIST. */
/*              J       INDICATOR OF POINT OR VECTOR FOR TRANSF. */
/*              I       POINTER OF ARRAY P ACCORDING TO POINT OR VECTOR. */
/*              P       ARRAY TO CONTAIN X,Y,Z,I,J,K. */
/*              I       COUNTER TO PICK UP POINT OR VECTOR. */
/*              IERROR  COMMON VARIABLE TO CARRY ERROR CODE. */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */



    /* Parameter adjustments */
    --result;

    /* Function Body */
    n = (integer) (*rm);
    isc = (integer) (*sn);
    ntp = *nt;
    ataper_(p, &n, &isc, &ntp, &iee);
    if (iee == 0) {
	goto L2;
    }
    idef_1.ierror = 93;
    goto L3;
L2:
    j = 2;
    i__ = 1;
    if (*m == 1) {
	i__ = 4;
    }
    if (*m == 1) {
	j = 3;
    }
    for (l = 1; l <= 3; ++l) {
	result[l] = p[i__ - 1];
/* L1: */
	++i__;
    }
    transf_(p, &result[1], &j, &c__3, &c_n1);
L3:
    defext_(&result[1]);
    return 0;
} /* apt105_ */

