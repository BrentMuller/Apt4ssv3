/* INTMSG.f -- translated by f2c (version 20100827).
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
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;
static integer c__7 = 7;
static integer c__13 = 13;
static integer c__6 = 6;
static integer c__21 = 21;
static integer c__35 = 35;
static integer c__52 = 52;
static integer c__4 = 4;
static integer c__57 = 57;
static integer c__71 = 71;
static integer c__85 = 85;
static integer c__20 = 20;
static integer c__22 = 22;
static integer c__37 = 37;
static integer c__10 = 10;
static integer c__48 = 48;
static integer c__53 = 53;
static integer c__3 = 3;
static integer c__9 = 9;
static integer c__67 = 67;

/* *** SOURCE FILE : INTMSG.ORG   *** */

/* Subroutine */ int intmsg_(doublereal *te, doublereal *ta, integer *intloc)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static char msg[120];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen), iconv_(integer *, char *, integer *, 
	    integer *, ftnlen), cprint_(char *, ftnlen);


/*     PURPOSE: TO PRINT MESSAGE AND RELEVANT DATA IF INTERFERENCE */
/*              HAS BEEN DETECTED */

/*     ARGUMENTS: */

/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     INTLOC  -  LOCATION INTERFERENCE TABLE OF WORST PENETRATION */




/* ..... PRINT MESSAGE */


/*    INTERFERENCE TABLE */





    /* Parameter adjustments */
    --ta;
    --te;

    /* Function Body */
    s_copy(msg, "0INTERFERENCE DETECTED", (ftnlen)120, (ftnlen)22);
    cprint_(msg, (ftnlen)120);
    cform_(" TE =", msg, &c__1, &c__5, (ftnlen)5, (ftnlen)120);
    fconv_(&te[1], msg, &c__7, &c__13, &c__6, (ftnlen)120);
    fconv_(&te[2], msg, &c__21, &c__13, &c__6, (ftnlen)120);
    fconv_(&te[3], msg, &c__35, &c__13, &c__6, (ftnlen)120);
    cform_("TA =", msg, &c__52, &c__4, (ftnlen)4, (ftnlen)120);
    fconv_(&ta[1], msg, &c__57, &c__13, &c__6, (ftnlen)120);
    fconv_(&ta[2], msg, &c__71, &c__13, &c__6, (ftnlen)120);
    fconv_(&ta[3], msg, &c__85, &c__13, &c__6, (ftnlen)120);
    cprint_(msg, (ftnlen)120);

    cform_(" WORST PENETRATION =", msg, &c__1, &c__20, (ftnlen)20, (ftnlen)
	    120);
    fconv_(&interf_1.dintr[*intloc - 1], msg, &c__22, &c__13, &c__6, (ftnlen)
	    120);
    cform_("AT PATCH =", msg, &c__37, &c__10, (ftnlen)10, (ftnlen)120);
    iconv_(&interf_1.pintr[*intloc - 1], msg, &c__48, &c__4, (ftnlen)120);
    cform_("U =", msg, &c__53, &c__3, (ftnlen)3, (ftnlen)120);
    fconv_(&interf_1.uintr[*intloc - 1], msg, &c__57, &c__9, &c__6, (ftnlen)
	    120);
    cform_("V =", msg, &c__67, &c__3, (ftnlen)3, (ftnlen)120);
    fconv_(&interf_1.vintr[*intloc - 1], msg, &c__71, &c__9, &c__6, (ftnlen)
	    120);
    cprint_(msg, (ftnlen)120);

    return 0;
} /* intmsg_ */

