/* ADV.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer pgc, pgcn, ilc, ixc;
} work_;

#define work_1 work_

/* *** SOURCE FILE : M0000746.V03   *** */


/* .....FORTRAN ROUTINE              ..ADV..     HL GRAY 3/68         *ID* */
/* Subroutine */ int adv_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern integer page_(integer *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)


/* FORTRAN SUBROUTINE ADV --- ADVANCE LOCATION COUNTER */

/* PURPOSE      'ADV'    ADVANCES THE INTERPRETER PSEUDOLOCATION */
/*              COUNTER, 'ILC' BY ONE INTERMEDIATE LANGUAGE INSTRUCTION. */
/*              OTHER DEPENDENT VARIABLES ARE SET TO CORRESPONDING */
/*              VALUES. */

/* LINKAGE      CALL ADV */

/* ARGUMENTS    THROUGH COMMON */

/* NOTES        THIS ROUTINE IS QUITE SIMILAR TO 'SET'   .  THE MAIN */
/*              DIFFERENCE IS THAT 'ADV'    DOES NOT EXAMINE VARIABLES */
/*              DEPENDING ON THE PSEUDOLOCATION COUNTER UNTIL A PAGE */
/*              BREAK OCCURS. */

/* METHOD       THE PSEUDOLOCATION COUNTER IS ADVANCED BY THE LENGTH */
/*              OF THE INSTRUCTION JUST PROCESSED.  IF THE PAGE BREAK */
/*              OCCURS, SUITABLE RESETTING OCCURS. */

/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* WORK--COMMON CONTAINING WORKING VARIABLES */


/*     ------------------- */





/* --------------------------------------------------------------------- */




/*        ADVANCE INDEX */

    k = pp[work_1.ilc] + 2;
    work_1.ixc += k;

/*        TEST--HAS PAGE BREAK OCCURRED */

    if (work_1.ixc > work_1.pgcn) {
	goto L50;
    }

/*        NO.  UPDATE LOCATION COUNTER, THEN RETURN */

    work_1.ilc += k;


    return 0;


/*        ADVANCE LOCATION COUNTER TO BEGINING OF NEW PAGE */

L50:
    if (work_1.pgc < 0) {
	goto L60;
    }
    i__1 = work_1.pgc + 1;
    work_1.ilc = page_(&i__1);

/*        UPDATE PAGE NUMBER */
    ++work_1.pgc;
    goto L70;

L60:
    i__1 = work_1.pgc - 1;
    work_1.ilc = page_(&i__1);

/*        UPDATE PAGE NUMBER */
    --work_1.pgc;

/*        EXTRAC NUMBER OF WORDS ON THIS PAGE */
L70:
    work_1.pgcn = pp[work_1.ilc] + 2;


/*        SET LOCATION COUNTER TO FIRST INSTRUCTION */

    work_1.ilc += 2;

/*        RESET INDEX */

    work_1.ixc = 3;

    return 0;
} /* adv_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


