/* NEWFUNCS.f -- translated by f2c (version 20100827).
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

static integer c__20 = 20;
static integer c__37 = 37;
static integer c__36 = 36;
static integer c__38 = 38;



/* .... FORTRAN SUBROUTINE   NEW FUNCTIONS                  16/10/78EC */



/* Subroutine */ int logf_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_0 = { -1, -1, 0. };


    /* Builtin functions */
    double log(doublereal);

    /* Local variables */
    static doublereal a;
#define neg ((doublereal *)&equiv_0)
#define ineg ((integer *)&equiv_0)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1];
    if (a < 0.) {
	goto L1;
    } else if (a == 0) {
	goto L2;
    } else {
	goto L3;
    }
L1:
    a = -a;
/*      'NEGATIVE LOGARITHM-ARGUMENT;CONTINUING WITH POSITIVE ARGUMENT' */
    error_(&c__20, "LOGF    ", (ftnlen)8);
L3:
    res[1] = log(a);
    return 0;
/*      'LOGARITHM-ARGUMENT ZERO;RESULT IS A NEGATIVE NUMBER' */
L2:
    error_(&c__37, "LOG10F  ", (ftnlen)8);
    res[1] = *neg;
    return 0;
} /* logf_ */

#undef ineg
#undef neg




/* Subroutine */ int log10f_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_0 = { -1, -1, 0. };


    /* Builtin functions */
    double d_lg10(doublereal *);

    /* Local variables */
    static doublereal a;
#define neg ((doublereal *)&equiv_0)
#define ineg ((integer *)&equiv_0)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1];
    if (a < 0.) {
	goto L4;
    } else if (a == 0) {
	goto L2;
    } else {
	goto L5;
    }
L4:
    a = -a;
/*      'NEGATIVE LOGARITHM-ARGUMENT;CONTINUING WITH POSITIVE ARGUMENT' */
    error_(&c__36, "LOG10F  ", (ftnlen)8);
L5:
    res[1] = d_lg10(&a);
    return 0;
/*      'LOGARITHM-ARGUMENT ZERO;RESULT IS A NEGATIVE NUMBER' */
L2:
    error_(&c__37, "LOG10F  ", (ftnlen)8);
    res[1] = *neg;
    return 0;
} /* log10f_ */

#undef ineg
#undef neg




/* Subroutine */ int tanf_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static doublereal fact = .0174532925;

    /* Builtin functions */
    double tan(doublereal);

    /* Local variables */
    static doublereal a;

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1] * fact;
    res[1] = tan(a);
    return 0;
} /* tanf_ */



/* Subroutine */ int tanb_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double tan(doublereal);

    /* Local variables */
    static doublereal a;

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1];
    res[1] = tan(a);
    return 0;
} /* tanb_ */



/* Subroutine */ int cotanf_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static doublereal fact = .0174532925;

    static doublereal a;
    extern doublereal dcotan_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1] * fact;
    res[1] = dcotan_(&a);
    return 0;
} /* cotanf_ */



/* Subroutine */ int cotanb_(doublereal *res, doublereal *arg)
{
    static doublereal a;
    extern doublereal dcotan_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    a = arg[1];
    res[1] = dcotan_(&a);
    return 0;
} /* cotanb_ */



/* Subroutine */ int sinb_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double sin(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = sin(arg[1]);
    return 0;
} /* sinb_ */



/* Subroutine */ int cosb_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double cos(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = cos(arg[1]);
    return 0;
} /* cosb_ */



/* Subroutine */ int atanb_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double atan(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = atan(arg[1]);
    return 0;
} /* atanb_ */



/* Subroutine */ int arsinf_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static doublereal fact = .0174532925;

    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    extern doublereal darsin_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    if (abs(arg[1]) <= 1.) {
	goto L9;
    }
/*    'ARSINF-ARCOSF ARGUMENT ABSOLUTE GREATER 1.:RESULT 0.' */
    error_(&c__38, "ARSINF  ", (ftnlen)8);
    res[1] = 0.;
    return 0;
L9:
    res[1] = darsin_(&arg[1]);
    res[1] /= fact;
    return 0;
} /* arsinf_ */



/* Subroutine */ int arsinb_(doublereal *res, doublereal *arg)
{
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    extern doublereal darsin_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    if (abs(arg[1]) <= 1.) {
	goto L9;
    }
/*    'ARSINF-ARCOSF ARGUMENT ABSOLUTE GREATER 1.:RESULT 0.' */
    error_(&c__38, "ARSINB  ", (ftnlen)8);
    res[1] = 0.;
    return 0;
L9:
    res[1] = darsin_(&arg[1]);
    return 0;
} /* arsinb_ */



/* Subroutine */ int arcosf_(doublereal *res, doublereal *arg)
{
    /* Initialized data */

    static doublereal fact = .0174532925;

    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    extern doublereal darcos_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    if (abs(arg[1]) <= 1.) {
	goto L11;
    }
/*    'ARSINF-ARCOSF ARGUMENT ABSOLUTE GREATER 1.:RESULT 0.' */
    error_(&c__38, "ARCOSF  ", (ftnlen)8);
    res[1] = 0.;
    return 0;
L11:
    res[1] = darcos_(&arg[1]);
    res[1] /= fact;
    return 0;
} /* arcosf_ */



/* Subroutine */ int arcosb_(doublereal *res, doublereal *arg)
{

    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    extern doublereal darcos_(doublereal *);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    if (abs(arg[1]) <= 1.) {
	goto L11;
    }
/*    'ARSINF-ARCOSF ARGUMENT ABSOLUTE GREATER 1.:RESULT 0.' */
    error_(&c__38, "ARCOSB  ", (ftnlen)8);
    res[1] = 0.;
    return 0;
L11:
    res[1] = darcos_(&arg[1]);
    return 0;
} /* arcosb_ */



/* Subroutine */ int sinhf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double sinh(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = sinh(arg[1]);
    return 0;
} /* sinhf_ */



/* Subroutine */ int coshf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double cosh(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = cosh(arg[1]);
    return 0;
} /* coshf_ */



/* Subroutine */ int tanhf_(doublereal *res, doublereal *arg)
{
    /* Builtin functions */
    double tanh(doublereal);

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    res[1] = tanh(arg[1]);
    return 0;
} /* tanhf_ */



/* Subroutine */ int intf_(doublereal *res, doublereal *arg)
{
    static integer i__;

    /* Parameter adjustments */
    --arg;
    --res;

    /* Function Body */
    i__ = (integer) arg[1];
    res[1] = (doublereal) i__;
    return 0;
} /* intf_ */



/* Subroutine */ int modf_(doublereal *res, doublereal *arg, doublereal *brg)
{
    /* Builtin functions */
    double d_mod(doublereal *, doublereal *);

    /* Parameter adjustments */
    --brg;
    --arg;
    --res;

    /* Function Body */
    res[1] = d_mod(&arg[1], &brg[1]);
    return 0;
} /* modf_ */



/* Subroutine */ int signf_(doublereal *res, doublereal *arg, doublereal *brg)
{
    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Parameter adjustments */
    --brg;
    --arg;
    --res;

    /* Function Body */
    res[1] = d_sign(&arg[1], &brg[1]);
    return 0;
} /* signf_ */



/* Subroutine */ int atan2f_(doublereal *res, doublereal *arg, doublereal *
	brg)
{
    /* Initialized data */

    static doublereal fact = .0174532925;

    /* Builtin functions */
    double atan2(doublereal, doublereal);

    /* Parameter adjustments */
    --brg;
    --arg;
    --res;

    /* Function Body */
    res[1] = atan2(arg[1], brg[1]);
    res[1] /= fact;
    return 0;
} /* atan2f_ */



/* Subroutine */ int atan2b_(doublereal *res, doublereal *arg, doublereal *
	brg)
{
    /* Builtin functions */
    double atan2(doublereal, doublereal);

    /* Parameter adjustments */
    --brg;
    --arg;
    --res;

    /* Function Body */
    res[1] = atan2(arg[1], brg[1]);
    return 0;
} /* atan2b_ */

