/* APT312.f -- translated by f2c (version 20100827).
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

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__4 = 4;

/* *** SOURCE FILE : M0000428.V05   *** */


/* .....FORTRAN SUBROUTINE                   APT312 */
/* PURPOSE      TO BLOCK AND WRITE CLFILE AND TO AUGMENT EACH */
/*              RECORD WRITTEN BY A UNIQUE SEQUENCE NUMBER. */
/* LINKAGE      CALL APT312 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt312_(void)
{
    /* Initialized data */

    static integer ebuff[516] = { 1 };
    static char aerr__[8] = "AERR    ";
    static integer k = 2;
    static integer n = 0;
    static char kfini[4] = "FINI";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, ir, nr, nwd, irec;
    static char test[8], atest[4];
#define nrecn1 ((integer *)&editor_1 + 774)
#define irecrd ((doublereal *)&editor_1)
#define jrecrd ((integer *)&editor_1)
#define record ((doublereal *)&editor_1)
    extern /* Subroutine */ int holfrm_(), awrite_(integer *, integer *, 
	    integer *, integer *, integer *);
#define savseq ((doublereal *)&editor_1 + 476)
#define numwds ((integer *)&editor_1 + 5)


/*       THIS ROUTINE BLOCKS AND WRITES CLFILE FROM RECORD */


/* ...            SYSTEM I/O FILE NAMES */


/* ...                SYSTEM I/O FILES */




    holfrm_(record, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, aerr__, (ftnlen)8, (ftnlen)8) != 0) {
	goto L10;
    }
    irec = jrecrd[3];
    goto L20;

L10:
    irec = jrecrd[3] / 10000;
    irec = jrecrd[3] - irec * 10000;
    irec += *nrecn1 * 10000;
    jrecrd[3] = irec;
    *savseq = irecrd[1];
L20:
    ++(*nrecn1);
/* .... IF APT4 TYPE POST PROCESSOR USE FORTRAN READ STATEMENT, */
/*     USE NEXT FORTRAN WRITE */
/*     WRITE(CLFILE) RECORD(1),IPOW,IREC,IPOW,NUMWDS, */
/*    1  (RECORD(I+3),I=1,NUMWDS) */
/* ..... IF APT4 TYPE POST PROCESSOR USE APT4 I/O, */
/*      USE NEXT APT4 I/O WRITE */
    j = *numwds + 3 << 1;

    if (k + j > 514) {
	goto L101;
    }
L110:
    ++n;
    ebuff[k] = n;
    ebuff[k + 1] = j;
    k += 2;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++k;
/* L120: */
	ebuff[k - 1] = jrecrd[i__ - 1];
    }
    holfrm_(jrecrd, atest, &c__1, &c__4, &nwd, (ftnlen)4);
    if (s_cmp(atest, kfini, (ftnlen)4, (ftnlen)4) == 0) {
	goto L130;
    }
    return 0;
L101:
    ebuff[1] = n;
    nr = 0;
    awrite_(&symfil_1.clfile, &nr, ebuff, &k, &ir);
    k = 2;
    ebuff[0] = n + 1;
    goto L110;
L130:
    ebuff[1] = n;
    nr = 0;
    awrite_(&symfil_1.clfile, &nr, ebuff, &k, &ir);
    return 0;
} /* apt312_ */

#undef numwds
#undef savseq
#undef record
#undef jrecrd
#undef irecrd
#undef nrecn1


