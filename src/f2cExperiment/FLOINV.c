/* FLOINV.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000627.V02   *** */

/* Subroutine */ int floinv_(doublereal *u, doublereal *sc, doublereal *flo, 
	integer *iseg)
{
    static integer nn, iarc, junc, locarc, locseg, locflo, numarc, numseg;

/* ---     PURPOSE IS TO CONVERT A COONS PARAMETER U */
/* ---     INTO A FLOW VALUE FLO AND SEGMENT NUMBER ISEG */
/* ---     ON A GIVEN FLOW CURVE SC. */
/* ---     PRESENT ROUTINE ONLY WORKS FOR INTEGRAL U */

    /* Parameter adjustments */
    --sc;

    /* Function Body */
    numseg = (integer) sc[8];
    if (numseg > 0) {
	goto L10;
    }
/* ---     CURVE HAS NO FLOW STRUCTURE, SET FLO TO U */
    *u = *flo;
    *iseg = 0;
    goto L999;

L10:
    locseg = (integer) (sc[9] - 5.f);
/* ---     FIRST SEARCH FOR A SEGMENT NUMBER */
    *iseg = 1;
L20:
    if (*iseg >= numseg) {
	goto L40;
    }
    locseg += 4;
    if (*u < sc[locseg + 1]) {
	goto L40;
    }
    if (*u <= sc[locseg + 2]) {
	goto L40;
    }
    ++(*iseg);
    goto L20;

L40:
/* ---     NOW DETERMINE THE FLOW VALUE WITHIN THIS SEGMENT */
    junc = (integer) (*u);
    numarc = (integer) sc[4];
    iarc = junc + 1;
    if (junc >= numarc) {
	iarc = numarc;
    }
    locarc = (integer) (sc[7] + (iarc - 1 << 2));
    nn = 1;
    locflo = (integer) sc[locarc];
    if (junc >= numarc) {
	nn = (integer) sc[locarc + 1];
    }
    locflo += nn - 1 << 2;
    *flo = sc[locflo];
L999:
    return 0;
} /* floinv_ */

