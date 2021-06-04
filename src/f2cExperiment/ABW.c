/* ABW.f -- translated by f2c (version 20100827).
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

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0011518.V01   *** */

/* K    SUBROUTINE    ABW       FORT      3-D     GEOLAN       WEISS */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++790724 */
/*   LETZTE AENDERUNG: D790724.T0835 */
/*     SUBROUTINE ABW(X1,X2,T1,T2,ERR) */
/*     ********************************* */

/*     KURZBESCHREIBUNG: */
/*     DAS UNTERPROGRAMM BERECHNET DIE MAXIMALE ABWEICHUNG EINER */
/*     SPLINE-KURVE ZWISCHEN ZWEI PUNKTEN VON DER VERBINDENDEN */
/*     GERADEN */

/*     EINGABE: */
/*     X1      KOORDINATEN DES ERSTEN PUNKTES, BLOCK DER LAENGE 3 */
/*     X2      KOORDINATEN DES ZWEITEN PUNKTES, BLOCK DER LAENGE 3 */
/*     T1      TANGENTENVEKTOR IM ERSTEN PUNKT,BLOCK DER LAENGE 3 */
/*     T2      TANGENTENVEKTOR IM ZWEITEN PUNKT, BLOCK DER LAENGE 3 */

/*     ERGEBNIS: */
/*     ERR     GESCHAETZTE ABSOLUTE ABWEICHUNG */

/*     UNTERPROGRAMME: DOTF FUER SCALP */

/*     ERSTELLER: WEISS, GDT4 */
/*                PLARRE,CAMI-UMSTELLUNG */

/* Subroutine */ int abw_(doublereal *x1, doublereal *x2, doublereal *t1, 
	doublereal *t2, doublereal *err)
{
    /* Format strings */
    static char fmt_2[] = "(\002 ABW:X1,X2,T1,T2,ERR:\002,/,\002 \002,13f10."
	    "4)";

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal a[3], c__;
    static integer i__;
    static doublereal a1, b1, c1, al, pi;
    static integer kq;
    static doublereal cos1, cos2, beta;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal gamma;
    extern doublereal darcos_(doublereal *);

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 0, 0, fmt_2, 0 };


    /* Parameter adjustments */
    --t2;
    --t1;
    --x2;
    --x1;

    /* Function Body */
    kq = 6;
    pi = 3.1415926535f;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1: */
	a[i__ - 1] = x2[i__] - x1[i__];
    }
    dotf_(&al, a, a);
    al = sqrt(al);
    dotf_(&cos1, a, &t1[1]);
    cos1 /= al;
    if (abs(cos1) <= 1.f) {
	goto L3;
    }
    if (cos1 > 1.f) {
	cos1 = 1.f;
    }
    if (cos1 < -1.f) {
	cos1 = -1.f;
    }
L3:
    b1 = darcos_(&cos1);
    beta = b1 * 180.f / pi;
    dotf_(&cos2, a, &t2[1]);
    cos2 /= al;
    if (abs(cos2) <= 1.f) {
	goto L5;
    }
    if (cos2 < -1.f) {
	cos2 = -1.f;
    }
    if (cos2 > 1.f) {
	cos2 = 1.f;
    }
L5:
    c1 = darcos_(&cos2);
    gamma = c1 * 180.f / pi;
    a1 = (180.f - beta - gamma) * pi / 180.f;
    c__ = al * sin(c1) / sin(a1);
    *err = c__ * sin(b1) * .1f;
    *err = abs(*err);
    if (kq != 0) {
	io___14.ciunit = kq;
	s_wsfe(&io___14);
	do_fio(&c__3, (char *)&x1[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__3, (char *)&x2[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__3, (char *)&t1[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__3, (char *)&t2[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*err), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* abw_ */

