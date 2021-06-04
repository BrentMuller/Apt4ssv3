/* APT314.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002942.V03   *** */


/* .....FORTRAN SUBROUTINE                   APT314 */
/* PURPOSE      TO READ EXFILE OR AN OLD CLFILE AND PLACE THE */
/*              RECORD IN THE ARRAY RECORD. */
/* LINKAGE      CALL APT314 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt314_(integer *ntape, integer *nrec)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, l, m, n, nb, ir;
    extern /* Subroutine */ int help_(void), aread_(integer *, integer *, 
	    integer *, integer *, integer *);
    static integer ebuff[516];
#define irecrd ((doublereal *)&editor_1)
#define jrecrd ((integer *)&editor_1)
#define record ((doublereal *)&editor_1)


/*       THIS SUBROUTINE READS AND UNBLOCKS CLFILE INTO RECORD */


    if (*nrec == 0) {
	*nrec = 1;
    }
    if (*nrec != -1) {
	goto L100;
    }
    n = 0;
    nb = 0;
    m = 0;
    k = 3;
    return 0;

L100:
    if (*nrec > m) {
	goto L10;
    }
    if (*nrec < n) {
	goto L20;
    }
    if (*nrec == ebuff[k - 1]) {
	goto L30;
    }
    k = 3;
L3:
    if (*nrec == ebuff[k - 1]) {
	goto L30;
    }
    k = k + ebuff[k] + 2;
    if (k > 516) {
	help_();
    }
    goto L3;
L30:
    ++k;
    l = ebuff[k - 1];
    i__1 = l;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L31: */
	jrecrd[i__ - 1] = ebuff[k + i__ - 1];
    }
    k = k + l + 1;
    return 0;
L10:
    ++nb;
L15:
    k = 516;
    aread_(ntape, &nb, ebuff, &k, &ir);
    k = 3;
    n = ebuff[0];
    m = ebuff[1];
    goto L100;
L20:
    --nb;
    goto L15;
} /* apt314_ */

#undef record
#undef jrecrd
#undef irecrd


