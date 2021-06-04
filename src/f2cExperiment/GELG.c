/* GELG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000631.V02   *** */

/* Subroutine */ int gelg_(doublereal *r__, doublereal *a, doublereal *eps, 
	integer *m, integer *n, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, l, ii;
    static doublereal tb;
    static integer ll, mm, nm, lx;
    static doublereal piv, tol;
    static integer ist, lst, lend;
    static doublereal pivi;

    /* Parameter adjustments */
    --a;
    --r__;

    /* Function Body */
    if (*m <= 0) {
	goto L230;
    } else {
	goto L10;
    }
L10:
    *ier = 0;
    piv = 0.f;
    mm = *m * *m;
    nm = *n * *m;
    i__1 = mm;
    for (l = 1; l <= i__1; ++l) {
	tb = (d__1 = a[l], abs(d__1));
	if (tb - piv <= 0.) {
	    goto L30;
	} else {
	    goto L20;
	}
L20:
	piv = tb;
	i__ = l;
L30:
	;
    }
    tol = *eps * piv;
    lst = 1;
    i__1 = *m;
    for (k = 1; k <= i__1; ++k) {
	if (piv <= 0.) {
	    goto L230;
	} else {
	    goto L40;
	}
L40:
	if (*ier != 0) {
	    goto L70;
	} else {
	    goto L50;
	}
L50:
	if (piv - tol <= 0.) {
	    goto L60;
	} else {
	    goto L70;
	}
L60:
	*ier = k - 1;
L70:
	pivi = 1.f / a[i__];
	j = (i__ - 1) / *m;
	i__ = i__ - j * *m - k;
	j = j + 1 - k;
	i__2 = nm;
	i__3 = *m;
	for (l = k; i__3 < 0 ? l >= i__2 : l <= i__2; l += i__3) {
	    ll = l + i__;
	    tb = pivi * r__[ll];
	    r__[ll] = r__[l];
/* L80: */
	    r__[l] = tb;
	}
	if (k - *m >= 0) {
	    goto L180;
	} else {
	    goto L90;
	}
L90:
	lend = lst + *m - k;
	if (j <= 0) {
	    goto L120;
	} else {
	    goto L100;
	}
L100:
	ii = j * *m;
	i__3 = lend;
	for (l = lst; l <= i__3; ++l) {
	    tb = a[l];
	    ll = l + ii;
	    a[l] = a[ll];
/* L110: */
	    a[ll] = tb;
	}
L120:
	i__3 = mm;
	i__2 = *m;
	for (l = lst; i__2 < 0 ? l >= i__3 : l <= i__3; l += i__2) {
	    ll = l + i__;
	    tb = pivi * a[ll];
	    a[ll] = a[l];
/* L130: */
	    a[l] = tb;
	}
	a[lst] = (doublereal) j;
	piv = 0.f;
	++lst;
	j = 0;
	i__2 = lend;
	for (ii = lst; ii <= i__2; ++ii) {
	    pivi = -a[ii];
	    ist = ii + *m;
	    ++j;
	    i__3 = mm;
	    i__4 = *m;
	    for (lx = ist; i__4 < 0 ? lx >= i__3 : lx <= i__3; lx += i__4) {
		ll = lx - j;
		a[lx] += pivi * a[ll];
		tb = (d__1 = a[lx], abs(d__1));
		if (tb - piv <= 0.) {
		    goto L150;
		} else {
		    goto L140;
		}
L140:
		piv = tb;
		i__ = lx;
L150:
		;
	    }
	    i__4 = nm;
	    i__3 = *m;
	    for (l = k; i__3 < 0 ? l >= i__4 : l <= i__4; l += i__3) {
		ll = l + j;
/* L165: */
		r__[ll] += pivi * r__[l];
	    }
/* L160: */
	}
/* L170: */
	lst += *m;
    }
L180:
    if ((i__1 = *m - 1) < 0) {
	goto L230;
    } else if (i__1 == 0) {
	goto L220;
    } else {
	goto L190;
    }
L190:
    ist = mm + *m;
    lst = *m + 1;
    i__1 = *m;
    for (i__ = 2; i__ <= i__1; ++i__) {
	ii = lst - i__;
	ist -= lst;
	l = ist - *m;
	l = (integer) (a[l] + .5f);
	i__2 = nm;
	i__3 = *m;
	for (j = ii; i__3 < 0 ? j >= i__2 : j <= i__2; j += i__3) {
	    tb = r__[j];
	    ll = j;
	    i__4 = mm;
	    i__5 = *m;
	    for (k = ist; i__5 < 0 ? k >= i__4 : k <= i__4; k += i__5) {
		++ll;
/* L200: */
		tb -= a[k] * r__[ll];
	    }
	    k = j + l;
	    r__[j] = r__[k];
/* L210: */
	    r__[k] = tb;
	}
    }
L220:
    goto L240;
L230:
    *ier = -1;
L240:
    return 0;
} /* gelg_ */

