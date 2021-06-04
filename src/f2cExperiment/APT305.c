/* APT305.f -- translated by f2c (version 20100827).
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
    integer kflags[5];
} kflags_;

#define kflags_1 kflags_

/* *** SOURCE FILE : M0000422.V02   *** */


/* ......    FORTRAN SUBROUTINE APT305    11/69    RC */
/* PURPOSE      TO GENERATE THE TRANSFORMATION MATRIX, TMATRX. */
/* LINKAGE      CALL APT305 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES APT306, APT308 */
/* Subroutine */ int apt305_(void)
{
    /* Local variables */
    extern /* Subroutine */ int apt306_(doublereal *, doublereal *, 
	    doublereal *), apt308_(doublereal *, doublereal *);
#define icopy ((integer *)&editor_1 + 1188)
#define amttab ((doublereal *)&editor_1 + 286)
#define itrafl ((integer *)&kflags_1 + 4)
#define mltflg ((integer *)&editor_1 + 748)
#define tramat ((doublereal *)&editor_1 + 1021)
#define tmatrx ((doublereal *)&editor_1 + 984)


/*      THIS SUBROUTINE GENERATES TMATRX FROM AMTTAB AND TRAMAT */
/*      DEPENDING ON COPY LEVEL (ICOPY) AND TRACUT (ITRAFL) */

/*      MLTFLG DETERMINES MATRIX MULTIPLICATION ORDER 1=POINT 0=PATTERN */



    if (*icopy == 0) {
	goto L90;
    }
    if (*mltflg == 0) {
	goto L40;
    }
    switch (*icopy) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
    }
L10:
    apt308_(tmatrx, amttab);
    goto L80;
L20:
    apt306_(tmatrx, &amttab[16], amttab);
    goto L80;
L30:
    apt306_(tmatrx, &amttab[16], amttab);
    apt306_(tmatrx, &amttab[32], tmatrx);
    goto L80;
L40:
    switch (*icopy) {
	case 1:  goto L50;
	case 2:  goto L60;
	case 3:  goto L70;
    }
L50:
    apt308_(tmatrx, amttab);
    goto L80;
L60:
    apt306_(tmatrx, amttab, &amttab[16]);
    goto L80;
L70:
    apt306_(tmatrx, amttab, &amttab[16]);
    apt306_(tmatrx, tmatrx, &amttab[32]);

/* ...     CHECK FOR TRACUT MODIFICATION OF COPY MATRIX */
L80:
    if (*itrafl == 0) {
	goto L100;
    }
    apt306_(tmatrx, tmatrx, tramat);
    goto L100;

/* ...     CHECK FOR A TRACUT TRANSFORMATION ONLY */

L90:
    if (*itrafl == 0) {
	goto L100;
    }
    apt308_(tmatrx, tramat);

L100:
    return 0;
} /* apt305_ */

#undef tmatrx
#undef tramat
#undef mltflg
#undef itrafl
#undef amttab
#undef icopy


