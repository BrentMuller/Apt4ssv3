/* dummy.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;

/* ** some dummy routines to fill in for linker undefined ref errors */
/* Subroutine */ int libsestablish_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___1);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine LIB$ESTABLISH", (
	    ftnlen)42);
    e_wsle();
    return 0;
} /* libsestablish_ */

/* Subroutine */ int time_(char *ct, ftnlen ct_len)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, 0, 0 };


/*     TODO */
    s_wsle(&io___2);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine TIME", (ftnlen)33);
    e_wsle();
/*      i=time8() */
/*      call ctime(i,ct) */
/*      call ctime(i,ctme) */
/*      call ltime(i,vals) */
/*      write(*,*)ctme */
/*      ct=ctme */
    return 0;
} /* time_ */

/* Subroutine */ int date_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___3);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine DATE", (ftnlen)33);
    e_wsle();
    return 0;
} /* date_ */

/* Subroutine */ int libsrevert_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___4);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine LIB$REVERT", (ftnlen)
	    39);
    e_wsle();
    return 0;
} /* libsrevert_ */

/* Subroutine */ int libssignal_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___5);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine LIB$SIGNAL", (ftnlen)
	    39);
    e_wsle();
    return 0;
} /* libssignal_ */

/* Subroutine */ int cputim_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___6);
    do_lio(&c__9, &c__1, "unimplemented VAX subroutine CPUTIM", (ftnlen)35);
    e_wsle();
    return 0;
} /* cputim_ */

