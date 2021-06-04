/* LIBRD.f -- translated by f2c (version 20100827).
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
    char filnam[480], filacc[300], filfmt[330], opstat[210], clstat[180];
} filtab_;

#define filtab_1 filtab_

struct {
    integer u[30], rl[30], nxtrec[30], lstrec[30];
} ifiltb_;

#define ifiltb_1 ifiltb_

struct {
    integer ieof;
} libcom_;

#define libcom_1 libcom_

struct {
    char aptlib[11], filenm[40], memnam[8];
} libfil_;

#define libfil_1 libfil_

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : LIBRD000.V01   *** */

/* Subroutine */ int librd_(char *member, integer *flag__, char *array, 
	ftnlen member_len, ftnlen array_len)
{
    /* System generated locals */
    integer i__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer id;

    /* Fortran I/O blocks */
    static cilist io___2 = { 1, 0, 1, "(A80)", 0 };



/*  * LIBRD *  VAX-11 FORTRAN 77 VERSION  28.09.82  E.MCLELLAN */
/*                              MODIFIED  26.09.86 */

/*  PURPOSE    TO READ A RECORD (80 CHARACTERS) FROM THE GIVEN */
/*             MEMBER FILE OF APTLIB */
/*  CALLING SEQUENCE */
/*             CALL LIBRD(MEMBER,FLAG,ARRAY) */
/*  ARGUMENTS */
/*             MEMBER    CHARACTER STRING CONTAINING THE */
/*                       MEMBER NAME (BCD LEFT JUSTIFIED) */
/*             FLAG      INTEGER SET BY LIBRD */
/*                       0 = SUCCESSFUL READ */
/*                       1 = END OF DATA ENCOUNTERED (EOF) */
/*                       2 = I/O ERROR */
/*                       3 = NOT USED */
/*                       4 = A DIFFERENT MEMBER NAME APPEARED WITHOUT */
/*                           CALLING LIBSCH OR BEFORE END OF DATA */
/*                           ENCOUNTERED */
/*             ARRAY     CHARACTER STRING TO CONTAIN A RETRIEVED RECORD */




/*  *  FILE ATTRIBUTES  * */








/* .....IS MEMBER NAME SAME AS IN LAST CALL TO LIBSCH */




    if (s_cmp(member, libfil_1.memnam, (ftnlen)8, (ftnlen)8) != 0) {
	*flag__ = 4;
	return 0;
    } else {
/* .....YES - READ A RECORD FROM MEMBER FILE */
	id = ifiltb_1.u[23];
	io___2.ciunit = id;
	i__1 = s_rsfe(&io___2);
	if (i__1 != 0) {
	    goto L100001;
	}
	i__1 = do_fio(&c__1, array, (ftnlen)80);
	if (i__1 != 0) {
	    goto L100001;
	}
	i__1 = e_rsfe();
L100001:
	if (i__1 < 0) {
	    goto L90;
	}
	if (i__1 > 0) {
	    goto L80;
	}
	*flag__ = 0;
	return 0;

/* .....I/O ERROR */
L80:
	*flag__ = 2;
	cl__1.cerr = 0;
	cl__1.cunit = id;
	cl__1.csta = 0;
	f_clos(&cl__1);
	return 0;

/* .....EOF ENCOUNTERED */
L90:
	*flag__ = 1;
	libcom_1.ieof = 1;
	cl__1.cerr = 0;
	cl__1.cunit = id;
	cl__1.csta = 0;
	f_clos(&cl__1);
	return 0;
    }
    return 0;
} /* librd_ */

