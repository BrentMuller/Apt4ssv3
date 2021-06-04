/* CONBCD.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__2 = 2;
static integer c__40 = 40;
static integer c__45 = 45;
static integer c__48 = 48;
static doublereal c_b14 = 1.;
static doublereal c_b15 = 10.;
static integer c__1 = 1;

/* *** SOURCE FILE : CONBCD00.ORG   *** */

/* Subroutine */ int conbcd_(doublereal *a, real *b, integer *ii, integer *jj,
	 integer *k)
{
    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[1];

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), pow_di(doublereal *, integer *)
	    ;
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(void);

    /* Local variables */
    static doublereal f;
    static integer i__, j, l, l1;
#define as ((real *)equiv_0)
    static integer im, jm, is;
    static logical dfl;
    static doublereal dpf;
    static integer inf, lsd, msd;
    static logical sfl;
    static integer inp;
#define atem (equiv_0)
    static logical lzfl, tzfl;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), abnend_(void);
    static char intfil[32];
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static char outfil[16];
    static doublereal tentoj;

    /* Fortran I/O blocks */
    static icilist io___18 = { 0, intfil, 0, "(F32.14)", 32, 1 };
    static icilist io___24 = { 0, outfil, 0, "(4A4)", 16, 1 };
    static icilist io___25 = { 0, outfil, 0, "(2A4)", 16, 1 };
    static icilist io___26 = { 0, outfil, 0, "(4A4)", 16, 1 };
    static icilist io___27 = { 0, outfil, 0, "(2A4)", 16, 1 };
    static icilist io___28 = { 0, outfil, 0, "(A4)", 16, 1 };



/*  * CONBCD *   VAX11 FORTRAN 77 VERSION  09.09.82  E.MCLELLAN */

/*  PURPOSE      TO CONVERT A FLOATING-POINT NUMBER TO A FIXED */
/*               FORMAT FOR SUBSEQUENT TAPE PUNCHING */

/*  CALLING SEQUENCE */
/*               CALL CONBCD(A,B,I,J,K) */
/*  ARGUMENTS */
/*               A  FLOATING-POINT NUMBER TO BE CONVERTED TO BCD */
/*               B  LOCATION WHERE BCD NUMBERS WILL BE STORED */
/*               I  NUMBER OF BCD DIGITS TO BE INCLUDED IN B. */
/*                  IF I IS NEGATIVE,THE SIGN OF A WILL BE INCLUDED */
/*                  AND THE FIELD LENGTH WILL BE I+1 BCD CHARACTERS */
/*               J  NUMBER OF FRACTIONAL BCD DIGITS TO BE INCLUDED IN I */
/*                  IF J NEGATIVE, DECIMAL POINT WILL BE INCLUDED */
/*                  AND FIELD LENGTH INCREASED TO I+1 BCD CHARACTERS */
/*                  IF BOTH I AND J ARE NEGATIVE,FIELD LENGTH WILL */
/*                  BE I+2 CHARACTERS. */
/*                  IF ABS(J) GT 100, TRAILING ZEROS WILL BE DELETED. */
/*                  J WILL THEN EQUAL ABS(J)-100 */
/*                  IF ABS(J) GT 200, LEADING ZEROS WILL BE DELETED. */
/*                  J WILL THEN EQUAL ABS(J)-200 */
/*                  IF J LT -300, LEADING AND TRAILING ZEROS WILL */
/*                  BE DELETED. J WILL EQUAL ABS(J)-300 */
/*               K  =1  A ASSUMED SINGLE PRECISION */
/*                  =2  A ASSUMED DOUBLE PRECISION */
/*                  =0  A ASSUMED DOUBLE PRECISION */
/*                      (EQUIVALENTTO OMISSION OF K) */
/*         NOTE:    IF K=0 AND I LE 6,THE OUTPUT IS RIGHT JUSTIFIED IN */
/*                  THE FIRST 6 BYTES OF B FOLLOWED BY 2 BLANKS */
/*                  IF K=0 AND I GT 6,THE OUTPUT IS RIGHT JUSTIFIED IN */
/*                  FIRST 12 BYTES OF B FOLLOWED BY 4 BLANKS */
/*                  IF K=1 OR 2 THEN OUTPUT IS RIGHT JUSTIFIED IN B */
/*                  IF B IS DIMENSIONED CORRECTLY */

/*         LIMITS:     K    IMAX     JMAX    BMIN */
/*                         (CHARS) (DIGITS) (BYTES) */
/*                     0     12        8       8 */
/*                     1      8        6       4 */
/*                     2     16       14       8 */

/*                     IMAX INCLUDES SIGN AND DECIMAL POINT INCLUSION */

/* .....SFL  TRUE IF SIGN TO BE INCLUDED */
/*     DFL  TRUE IF DECIMAL POINT TO BE INCLUDED */
/*     TZFL TRUE IF TRAILING ZEROS TO BE DELETED */
/*     LZFL TRUE IF LEADING ZEROS TO BE DELETED */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --b;

    /* Function Body */
    *atem = *a;
    i__ = *ii;
    j = *jj;

/* ..... INITIALIZE FLAGS */

    sfl = FALSE_;
    dfl = FALSE_;
    tzfl = FALSE_;
    lzfl = FALSE_;

/* .....CHECK FIFTH PARAMETER AND SET LIMITS */

    if (*k == 0) {
	im = 12;
	jm = 8;
    } else if (*k == 1) {
	im = 8;
	jm = 6;
    } else if (*k == 2) {
	im = 16;
	jm = 14;
    }

/* .....IF I NEGATIVE INCLUDE SIGN */

    if (i__ < 0) {
	sfl = TRUE_;
	i__ = abs(i__) + 1;
    } else if (i__ == 0) {
	cform_("**** INVALID CONBCD PARAMETER (I=0) ****", darray_1.darray, &
		c__2, &c__40, (ftnlen)40, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	abnend_();
    }

/* .....IF J NEGATIVE INCLUDE DECIMAL POINT */

    if (j < 0) {
	dfl = TRUE_;
	++i__;
    }

/* .....IF J.GT.300 ,NOT VALID */

    if (j > 300) {
	cform_("**** INVALID CONBCD PARAMETER (J.GT.300) ****", 
		darray_1.darray, &c__2, &c__45, (ftnlen)45, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	abnend_();

/* .....IF J.LT.-300, DELETE LEADING AND TRAILING ZEROS */
/*                  (ONLY VALID IF DECIMAL POINT INCLUDED) */
    } else if (j < -300) {
	tzfl = TRUE_;
	lzfl = TRUE_;
	j = abs(j) - 300;

/* .....IF ABS(J).GT.200 , DELETE LEADING ZEROS */

    } else if (abs(j) > 200) {
	lzfl = TRUE_;
	j = abs(j) - 200;

/* .....IF ABS(J).GT.100 , DELETE TRAILING ZEROS */

    } else if (abs(j) > 100) {
	tzfl = TRUE_;
	j = abs(j) - 100;
    } else {
	j = abs(j);
    }

/* .....CHECK LIMITS */

    if (i__ > im) {
	cform_("**** I.GT.IMAX FOR CURRENT K IN CONBCD CALL****", 
		darray_1.darray, &c__2, &c__48, (ftnlen)47, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	i__ = im;
    }

    if (j > jm) {
	cform_("**** J.GT.JMAX FOR CURRENT K IN CONBCD CALL****", 
		darray_1.darray, &c__2, &c__48, (ftnlen)47, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	j = jm;
    }

/* .....STORE VALUE IN DOUBLE PRECISION WORD F */

    if (*k == 1) {
	f = *as;
    } else {
	f = *a;
    }

/* .....STORE SIGN OF F */

    is = (integer) d_sign(&c_b14, &f);

/* .....ROUND ABS VALUE OF F TO J DECIMAL PLACES */

    tentoj = pow_di(&c_b15, &j);
    f = abs(f);
    inf = (integer) f;
    dpf = f - (doublereal) inf;
    inp = (integer) (dpf * tentoj + .5);
    f = (doublereal) inf + (doublereal) inp / tentoj;

/* .....WRITE F TO INTERNAL FILE */

    s_wsfi(&io___18);
    do_fio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
    e_wsfi();

/* .....INSERT TRAILING BLANKS */

    lsd = j + 18;
    i__1 = lsd;
    s_copy(intfil + i__1, " ", 32 - i__1, (ftnlen)1);

/* .....ARE TRAILING ZEROS TO BE DELETED */

    if (tzfl) {
	l = lsd;
L10:
	if (*(unsigned char *)&intfil[l - 1] == '0') {
	    *(unsigned char *)&intfil[l - 1] = ' ';
	    --l;
	    goto L10;
	}
    }

/* .....WHERE IS FIRST NON BLANK CHARACTER IN INTFIL */

    l = 1;
L20:
    if (*(unsigned char *)&intfil[l - 1] == ' ') {
	if (! lzfl) {
	    *(unsigned char *)&intfil[l - 1] = '0';
	}
	++l;
	goto L20;
    }
    l1 = l;

/* .....IS DECIMAL POINT REQUIRED */

    if (! dfl) {
/* .....NO DELETE DECIMAL POINT */
	l = 17;
L30:
	i__1 = l;
	s_copy(intfil + i__1, intfil + (l - 1), l + 1 - i__1, (ftnlen)1);
	if (l == l1) {
	    if (lzfl) {
		*(unsigned char *)&intfil[l1 - 1] = ' ';
	    } else {
		*(unsigned char *)&intfil[l1 - 1] = '0';
	    }
	} else {
	    --l;
	    goto L30;
	}
    }

/* .....IS SIGN REQUIRED */

    msd = lsd - i__ + 1;
    if (sfl) {
	if (is >= 0) {
	    *(unsigned char *)&intfil[msd - 1] = '+';
	} else {
	    *(unsigned char *)&intfil[msd - 1] = '-';
	}
    }

/* .....SET UP OUTFIL ACCORDING TO K AND I */

    s_copy(outfil, " ", (ftnlen)16, (ftnlen)1);
    if (*k == 0) {
	if (i__ > 6) {
	    i__1 = 13 - i__ - 1;
	    s_copy(outfil + i__1, intfil + (msd - 1), 12 - i__1, lsd - (msd - 
		    1));
	    s_rsfi(&io___24);
	    for (l = 1; l <= 4; ++l) {
		do_fio(&c__1, (char *)&b[l], (ftnlen)sizeof(real));
	    }
	    e_rsfi();
	} else {
	    i__1 = 7 - i__ - 1;
	    s_copy(outfil + i__1, intfil + (msd - 1), 6 - i__1, lsd - (msd - 
		    1));
	    s_rsfi(&io___25);
	    do_fio(&c__1, (char *)&b[1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&b[2], (ftnlen)sizeof(real));
	    e_rsfi();
	}

    } else if (i__ > 8) {
	i__1 = 17 - i__ - 1;
	s_copy(outfil + i__1, intfil + (msd - 1), 16 - i__1, lsd - (msd - 1));
	s_rsfi(&io___26);
	for (l = 1; l <= 4; ++l) {
	    do_fio(&c__1, (char *)&b[l], (ftnlen)sizeof(real));
	}
	e_rsfi();
    } else if (i__ > 4) {
	i__1 = 9 - i__ - 1;
	s_copy(outfil + i__1, intfil + (msd - 1), 8 - i__1, lsd - (msd - 1));
	s_rsfi(&io___27);
	do_fio(&c__1, (char *)&b[1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&b[2], (ftnlen)sizeof(real));
	e_rsfi();
    } else {
	i__1 = 5 - i__ - 1;
	s_copy(outfil + i__1, intfil + (msd - 1), 4 - i__1, lsd - (msd - 1));
	s_rsfi(&io___28);
	do_fio(&c__1, (char *)&b[1], (ftnlen)sizeof(real));
	e_rsfi();
    }

    return 0;
} /* conbcd_ */

#undef atem
#undef as


