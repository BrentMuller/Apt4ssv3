/* APT340.f -- translated by f2c (version 20100827).
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
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, cutter, test,
	     cradus;
} r5axis_;

#define r5axis_1 r5axis_

struct {
    integer ivtflg, is, ir, il, ie, jsuber, iabove, nrecex, nreccl, ncflsv;
} i5axis_;

#define i5axis_1 i5axis_

/* *** SOURCE FILE : M0000441.V02   *** */


/* .....FORTRAN SUBROUTINE                APT340...            8/1/68  AR */

/* PURPOSE      SETS UP CUT VECTOR TO BE USED IN APT341 */
/* LINKAGE      CALL APT340 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES APT341 */
/* ******************************************************************** */
/* Subroutine */ int apt340_(void)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
#define x1 ((doublereal *)&editor_1 + 1331)
#define x2 ((doublereal *)&editor_1 + 1332)
#define y1 ((doublereal *)&editor_1 + 1336)
#define y2 ((doublereal *)&editor_1 + 1337)
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt341_(void);

/* *********************************************************************** */
/*     SYSTEM COMMON,DIMENSION, AND EQUIVALENCE STATEMENTS */


/* ...    ESTABLISH CUT VECTOR */
    r5axis_1.xcv = *x2 - *x1;
    r5axis_1.ycv = *y2 - *y1;
    r5axis_1.zcv = r5axis_1.z2 - r5axis_1.z1;
/* Computing 2nd power */
    d__1 = r5axis_1.xcv;
/* Computing 2nd power */
    d__2 = r5axis_1.ycv;
/* Computing 2nd power */
    d__3 = r5axis_1.zcv;
    r5axis_1.dlngth += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* ...    NO WCORN */
    apt341_();
    return 0;
} /* apt340_ */

#undef area3
#undef area2
#undef area1
#undef y2
#undef y1
#undef x2
#undef x1


