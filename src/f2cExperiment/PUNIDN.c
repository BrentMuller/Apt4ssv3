/* PUNIDN.f -- translated by f2c (version 20100827).
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
    real pnid, pno;
} pun_;

#define pun_1 pun_

/* *** SOURCE FILE : PUNIDN00.V01   *** */

/* Subroutine */ int punidn_0_(int n__, real *a, real *b, real *c__)
{

/*  * PUNIDN *  VAX-11 FORTRAN 77 VERSION  21.10.82  E.MCLELLAN */

/*  PURPOSE     TO SET UP CARD IDENTIFICATION AND SEQUENCE NUMBERS */

/*  CALLING SEQUENCE */
/*              CALL PUNIDN(A) */
/*  ARGUMENTS */
/*             A  ADDRESS FIELD OF 4 BCD CHARACTERS */
/*  ALTERNATE ENTRIES */
/*             CALL PUNSEQ(B) */
/*             B  START SEQUENCE NUMBER TO BE PUNCHED - REAL*4 */

/*             CALL PUNNUM(C) */
/*             C  LATEST SEQUENCE NUMBER BEING PUNCHED - REAL*4 */


    switch(n__) {
	case 1: goto L_punseq;
	case 2: goto L_punnum;
	}

    pun_1.pnid = *a;
    return 0;


L_punseq:
    pun_1.pno = *b;
    return 0;


L_punnum:
    *c__ = pun_1.pno;
    return 0;
} /* punidn_ */

/* Subroutine */ int punidn_(real *a)
{
    return punidn_0_(0, a, (real *)0, (real *)0);
    }

/* Subroutine */ int punseq_(real *b)
{
    return punidn_0_(1, (real *)0, b, (real *)0);
    }

/* Subroutine */ int punnum_(real *c__)
{
    return punidn_0_(2, (real *)0, (real *)0, c__);
    }

