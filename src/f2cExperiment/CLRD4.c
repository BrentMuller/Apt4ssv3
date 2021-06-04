/* CLRD4.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000396.V02   *** */


/* ....  FORTRAN SUBROUTINE  CLRD4                          8/1/72 */
/*  PURPOSE     TO READ CLFIL2 AND PLACE RHE RECORD IN THE ARRAY. */
/*  LINKAGE     CALL CLRD4  (FILE,NR,NBUFF,IR) */

/*  ARGUMENTS   FILE    FILE NUMBER IN THE SYMFIL COMMON. */
/*                      IF FILE=-1, RESET ALL COUNTERS FOR OTHER FILE. */
/*              NR      CONTAINING RECORD NUMBER TO BE RETRIEVED. */
/*              NBUFF   DATA ARRAY TO CONTAIN THE RETRIEVED RECORD. */
/*              IR      RETURN ERROR FLAG. =0 NOERROR, =1 ERROR. */

/* Subroutine */ int clrd4_(integer *file, integer *nr, integer *nbuff, 
	integer *ir)
{
    /* Initialized data */

    static integer n = 0;
    static integer nb = 0;
    static integer m = 0;
    static integer k = 3;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, l, kr;
    extern /* Subroutine */ int aread_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer ebuff[516];

    /* Parameter adjustments */
    --nbuff;

    /* Function Body */
    if (*file != -1) {
	goto L100;
    }
/*     INITIALIZE FLAGS */
/*     N IS MAXIMUM RECORD NUMBER IN THIS BLOCK */
    n = 0;
/*     NB IS BLOCK NUMBER COUNTER */
    nb = 0;
/*     M IS MINIMUM RECORD NUMBER IN THIS BLOCK */
    m = 0;
/*     K IS POINTER OF BUFFER */
    k = 3;
/*     CHECK SPECIFIED RECORD IS IN CURRENT BLOCK */
L100:
    if (*nr > m) {
	goto L10;
    }
    if (*nr < n) {
	goto L20;
    }
/*     YES, SPECIFIED RECORD IS IN CURRENT BLOCK */
    if (*nr == ebuff[k - 1]) {
	goto L30;
    }
    k = 3;
/*     FIND THE POSITION OF THE RECORD */
L3:
    if (*nr == ebuff[k - 1]) {
	goto L30;
    }
    k = k + ebuff[k] + 2;
    if (k > 516) {
	goto L200;
    }
    goto L3;
L30:
    ++k;
/*     GET THE SIZE OF RECORD */
    l = ebuff[k - 1];
/*     MOVE THE RECORD */
    i__1 = l;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L31: */
	nbuff[i__] = ebuff[k + i__ - 1];
    }
    k = k + l + 1;
    return 0;
/*     TRY NEXT BLOCK */
L10:
    ++nb;
L15:
    k = 516;
    aread_(file, &nb, ebuff, &k, &kr);
    if (kr == 3) {
	goto L200;
    }
    k = 3;
    n = ebuff[0];
    m = ebuff[1];
    goto L100;
/*     TRY PREVIOUS RECORD */
L20:
    --nb;
    goto L15;
L200:
    *ir = 1;
    return 0;
} /* clrd4_ */

