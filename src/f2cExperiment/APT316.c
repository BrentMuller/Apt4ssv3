/* APT316.f -- translated by f2c (version 20100827).
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

struct holrth_1_ {
    char all[8], circle[8], fini[8], from[8], godlta[8], goto__[8], indirp[8],
	     indirv[8], modify[8], mirror[8], same[8], transl[8], xyrot[8], 
	    yzplan[8], zxplan[8], xyplan[8], cut[8], dntcnt[8], intol[8], 
	    outtol[8], kutter[8], ovplot[8], copy[8], on[8], off[8], dummy5[8]
	    , dummy6[8], dummy7[8], dummy8[8], dummy9[8];
};

#define holrth_1 (*(struct holrth_1_ *) &holrth_)

/* Initialized data */

struct {
    char e_1[240];
    } holrth_ = { "ALL     CIRCLE  FINI    FROM    GODLTA  GOTO    INDIRP  I"
	    "NDIRV  MODIFY  MIRROR  SAME    TRANSL  XYROT   YZPLAN  ZXPLAN  X"
	    "YPLAN  CUT     DNTCUT  INTOL   OUTTOL  CUTTER  OVPLOT  COPY    O"
	    "N      OFF     DUMMY5  DUMMY6  DUMMY7  DUMMY8  DUMMY9  " };


/* *** SOURCE FILE : M0000432.V06   *** */


/* .....BLOCK DATA ROUTINE BDA316              APT316          12/67 */
/* PURPOSE      THIS IS A BLOCK DATA SUBROUTINE AND IS NOT */
/*              CALLED OR EXECUTED.  THE SUBROUTINE LOADS THE */
/*              COMMON STORAGE ARRAY HOLRTH WITH THE BCD REPRESENTATION */
/*              OF THE RECORD TYPES WHICH REQUIRE SPECIAL HANDLING */
/*              IN THE CLTAPE EDITOR. */

/* Subroutine */ int bda316_(void)
{
    return 0;
} /* bda316_ */





/* ...CL EDITOR ALPHA-NUMERIC LITERAL CONSTANTS. */








