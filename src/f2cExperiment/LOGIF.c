/* LOGIF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0008153.W01   *** */


/*              FORTRAN SUBROUTINE LOGIF */

/* LINKAGE      SUBROUTINE LOGIF(TEMP,MODE,COM1,COM2) */

/*         SUBSIDIARIES              CALLED FROM */
/*         NONE                      TYPE           ENTRY */
/*                                                  XCALL */

/* Subroutine */ int logif_(doublereal *temp, integer *mode, doublereal *com1,
	 doublereal *com2)
{
    /* Initialized data */

    static doublereal true__ = 1.;
    static doublereal false__ = 0.;
    static doublereal smal = 1e-12;
    static doublereal divis = 2.;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double d_int(doublereal *);

    /* Local variables */
    static doublereal comp1, comp2;


/* * */
/*     TEMP   1.D0 = .TRUE. ; 0.D0 = .FALSE. */
/*     MODE   COMPARATIVE CODE */
/*            1      2      3      4      5      6      7      8     9 */
/*            EQ     NE     GE     LE     GT     LT     NOT    OR    AND */
/*     COM1  1ST LOGICAL OR RELATIONAL OPERATOR */
/*     COM2  2ND LOGICAL OR RELATIONAL OPERATOR */
/* ** */

    comp1 = *com1;
    comp2 = *com2;

    switch (*mode) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
	case 8:  goto L80;
	case 9:  goto L90;
    }
/*                   ** COMP1 EQUAL COMP2 ** */
L10:
    if ((d__1 = comp1 - comp2, abs(d__1)) > smal) {
	goto L110;
    }
    goto L100;
/*                   ** COMP1 NOT EQUAL COMP2 ** */
L20:
    if ((d__1 = comp1 - comp2, abs(d__1)) > smal) {
	goto L100;
    }
    goto L110;
/*                   ** COMP1 GREATER EQUAL COMP2 ** */
L30:
    if (comp1 > comp2) {
	goto L100;
    }
    goto L10;
/*                   ** COMP1 LESS EQUAL COMP2 ** */
L40:
    if (comp1 < comp2) {
	goto L100;
    }
    goto L10;
/*                   ** COMP1 GREATER THAN COMP2 ** */
L50:
    if (comp1 > comp2 + smal) {
	goto L100;
    }
    goto L110;
/*                   ** COMP1 LESS THAN COMP2 ** */
L60:
    if (comp1 < comp2 - smal) {
	goto L100;
    }
    goto L110;
/*                   ** .NOT. COMP1 ** */
L70:
    d__2 = (d__1 = comp1 - true__, abs(d__1)) + smal;
    *temp = d_int(&d__2);
    goto L120;
/*                   ** COMP1 .OR. COMP2 ** */
L80:
    d__1 = (comp1 + comp2 + true__) / divis + smal;
    *temp = d_int(&d__1);
    goto L120;
/*                   ** COMP1 .AND. COMP2 ** */
L90:
    d__1 = comp1 * comp2 + smal;
    *temp = d_int(&d__1);
    goto L120;

L100:
    *temp = true__;
    goto L120;
L110:
    *temp = false__;
L120:
    return 0;
} /* logif_ */

