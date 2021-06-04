/* BDCCLR.f -- translated by f2c (version 20100827).
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

struct cclear_1_ {
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4], ifeedf;
};

#define cclear_1 (*(struct cclear_1_ *) &cclear_)

/* Initialized data */

struct {
    doublereal e_1[19];
    integer e_2[13];
    } cclear_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


/* *** SOURCE FILE : M0012333.V01   *** */

/* Subroutine */ int bdcclr_(void)
{
    return 0;
} /* bdcclr_ */


/* COMMON FOR REGIONAL STARTUP AND RETRACT VALUES */



/*              (1) : START */
/*              (2) : AWAY */
/*              (3) : BACK */
/*              (4) : THRU */
/* DIRMOT(3,4): ARRAY FOR MOTDIR, NORMAL OR VECTOR VALUES */
/*              (1,I) : VALUES OF MOTDIR AND/OR NORMAL */
/*              (2,I) */
/*           OR (1,I) : VALUES OF VECTOR */
/*              (2,I) */
/*              (3,I) */


/* GOFEED(4)  : ARRAY FOR MOTION FEEDRAT */
/*              (1)   : FEDRAT OF START-MOTION (START AT FIRST POINT) */
/*              (2)   : FEDRAT OF AWAY-MOTION */
/*              (3)   : FEDRAT OF BACK-MOTION */
/*              (4)   : FEDRAT OF THRU-MOTION (RETRACT AT LAST POINT) */


/* GLFEED     : VARIABLE FOR NORMAL FEDRAT BEFORE GOMILL OR GOLOFT */

/* REGLDA     : ARRAY FOR CANONICAL FORM OF REGION DATA */

/* IRETRO(4)  : ARRAY FOR START, AWAY, BACK, THRU */
/*              (1) : START */
/*              (2) : AWAY */
/*              (3) : BACK */
/*              (4) : THRU */
/*                    0 : NOT USED */
/*                    1 : CONDITION SET */

/* IDIRMO(4)  : ARRAY FOR START ON AND END CONDITION */
/*                    0 : NOT SET */
/*                    1 : MOTDIR AND/OR NORMAL */
/*                    2 : VECTOR */

/* ICANIN(4)  : ARRAY FOR THE CANONICAL FORM INDEX OF THE SURFACE */
/*                    0 : NOT SET */
/*                    IC: INDEX */

/* IFEEDF     : FLAG (=1) FOR >GOP< TO OUTPUT GLOBAL FEEDRATE */


