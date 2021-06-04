/* APT241.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : APT24100.ORG   *** */

/* Subroutine */ int apt241_(void)
{
    extern integer handl_();
    extern /* Subroutine */ int libsestablish_(I_fp);

/*      CALL LIB$ESTABLISH(HANDL) */
    libsestablish_((I_fp)handl_);
    return 0;
} /* apt241_ */



/* Subroutine */ int apt242_(void)
{
/*      CALL LIB$SIGNAL(%VAL(SS$_ACCVIO)) */
    return 0;
} /* apt242_ */



integer handl_(integer *s, integer *m)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern /* Subroutine */ int abort_(void);

/*      INCLUDE 'SYS$LIBRARY:SIGDEF' */
/*      HANDL=SS$_RESIGNAL */
/*      IF (S(2).EQ.SS$_UNWIND) THEN */
/*      RETURN */
/*      END IF */
/*      CALL SYS$UNWIND(,) */
/*   i don't know what to replace this with right now, so.. */
    /* Parameter adjustments */
    --m;
    --s;

    /* Function Body */
    abort_();
    return ret_val;
} /* handl_ */

