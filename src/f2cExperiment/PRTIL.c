/* PRTIL.f -- translated by f2c (version 20100827).
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
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

struct {
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer iltext[94];
} iltext_;

#define iltext_1 iltext_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__116 = 116;
static integer c__120 = 120;

/* *** SOURCE FILE : M0006669.V10   *** */


/*              FORTRAN SUBROUTINE PRTIL */

/* LINKAGE      SUBROUTINE PRTIL(LINE) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    FOUTXX          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    OPPAIR */
/*          SUBROUTINE    BINBCD */

/* Subroutine */ int prtil_(char *line, ftnlen line_len)
{
    /* Initialized data */

    static char opbcd[6*21] = "FADD  " "FSUB  " "FMPY  " "FDIV  " "PEXP  " 
	    "LABEL " "ENTRY " "JUMP  " "SEQNCE" "RETMC " "CONJMP" "RESRV " 
	    "CVTSUB" "CALMC " "ASNADD" "ASNJMP" "REPL  " "CALL  " "MOVE  " 
	    "VBLJMP" "HOLDAT";
    static char blk[4] = "    ";
    static char neg[4] = "   -";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, i1, ii, nwd, limit, count, itext;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen),
	     oppair_(char *, integer *, ftnlen), holfrm_(integer *, char *, 
	    integer *, integer *, integer *, ftnlen);
#define textin ((integer *)&iltext_1 + 4)
#define optext ((integer *)&iltext_1 + 3)
    extern /* Subroutine */ int foutxx_(integer *, char *, integer *, ftnlen);
#define tpntrx ((integer *)&iltext_1 + 2)



/*        0.    SYSTEM DEPENDENT PARAMETERS */

/* IWRD:        NO. OF BYTES PER INTEGER WORD */
/* IFAC:        BYTE LEFT SHIFT MULTIPLICATION FACTOR */

/*        1.    NAME TABLE AND TABLE LIMITS */


/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*       19.    INTERMEDIATE LANGUAGE TEXT */







/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* VLFILE:      VERIFICATION LISTING FILE */
/* * */
/* ARGUMENTS    LINE     OUTPUT ARRAY TO CONTAIN ALPHA- */
/*                       NUMERIC EQUIVALENT OF BINARY I.L.. */


/* ...                SYSTEM I/O FILES */



/* ** */
    s_copy(line + 4, opbcd + (0 + (0 + (*optext - 1) * 6)), (ftnlen)120, (
	    ftnlen)6);
    switch (*optext) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L100;
	case 5:  goto L100;
	case 6:  goto L600;
	case 7:  goto L600;
	case 8:  goto L600;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1500;
	case 16:  goto L1600;
	case 17:  goto L1700;
	case 18:  goto L1800;
	case 19:  goto L1900;
	case 20:  goto L2000;
	case 21:  goto L2100;
    }

/* ...  FADD,FSUB,FMPY,FDIV,FEXP */

L100:
    l = 13;
    for (i__ = 1; i__ <= 5; i__ += 2) {
	oppair_(line + (l - 1), &textin[i__ - 1], 124 - (l - 1));
/* L101: */
	l += 20;
    }
    k = 69;
    goto L9000;

/* ...  LABEL,ENTRY,JUMP */

L600:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    k = 21;
    goto L9000;

/* ...     SEQNCE */

L900:
    s_copy(line + 12, blk, (ftnlen)112, (ftnlen)4);
    if (textin[0] >= 0) {
	goto L902;
    } else {
	goto L901;
    }
L901:
    s_copy(line + 12, neg, (ftnlen)112, (ftnlen)4);
L902:
    i__1 = abs(textin[0]);
    binbcd_(&i__1, line + 16, &count, (ftnlen)108);
    k = 25;
    goto L9000;

/* ...     RETMC */

L1000:
    binbcd_(textin, line + 12, &count, (ftnlen)112);
    k = 21;
    goto L9000;

/* ...  CONJMP */

L1100:
    oppair_(line + 12, textin, (ftnlen)112);
    for (i__ = 1; i__ <= 3; ++i__) {
	itext = textin[i__ + 1];
	i1 = (i__ << 3) + 25;
	s_copy(line + (i1 - 1), cnamtb_1.cnamtb + (itext - 1) * 6, 124 - (i1 
		- 1), (ftnlen)6);
/* L1101: */
    }
    k = 57;
    goto L9000;

/* ...  RESRV */

L1200:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    for (i__ = 2; i__ <= 4; ++i__) {
/* L1201: */
	i__1 = (i__ << 3) + 4;
	binbcd_(&textin[i__ - 1], line + i__1, &count, 124 - i__1);
    }
    k = 41;
    goto L9000;

/* ...  CVTSUB */

L1300:
    l = 13;
    for (i__ = 1; i__ <= 5; i__ += 2) {
	oppair_(line + (l - 1), &textin[i__ - 1], 124 - (l - 1));
/* L1301: */
	l += 20;
    }
    binbcd_(&textin[6], line + 64, &count, (ftnlen)60);
    k = 81;
    goto L9000;

/* ...  CALMC */

L1400:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    binbcd_(&textin[1], line + 20, &count, (ftnlen)104);
    binbcd_(&textin[2], line + 28, &count, (ftnlen)96);
    k = 33;
    goto L9000;

/* ...  ASNADD */

L1500:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    oppair_(line + 24, &textin[1], (ftnlen)100);
    k = 41;
    goto L1601;

/* ...  ASNJMP */

L1600:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    itext = textin[1];
    s_copy(line + 24, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)100, (ftnlen)
	    6);
    k = 33;
L1601:
    s_copy(line + 20, blk, (ftnlen)104, (ftnlen)4);
    goto L9000;

/* ...  REPL */

L1700:
    binbcd_(textin, line + 12, &count, (ftnlen)112);
    oppair_(line + 20, &textin[1], (ftnlen)104);
    oppair_(line + 40, &textin[3], (ftnlen)84);
    k = 61;
    goto L9000;

/* ...  CALL */

L1800:
    itext = textin[0];
    s_copy(line + 12, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)112, (ftnlen)
	    6);
    s_copy(line + 20, blk, (ftnlen)12, (ftnlen)4);
    limit = *tpntrx - 9;
    j = 2;
    l = 33;
    if (limit <= 0) {
	goto L1804;
    } else {
	goto L1801;
    }
L1801:
    i__1 = limit;
    for (i__ = 1; i__ <= i__1; i__ += 10) {
	for (ii = l; ii <= 100; ii += 20) {
	    oppair_(line + (ii - 1), &textin[j - 1], 124 - (ii - 1));
/* L1802: */
	    j += 2;
	}
	foutxx_(&symfil_1.vlfile, line, &c__116, (ftnlen)124);
	l = 13;
	s_copy(line + 8, blk, (ftnlen)116, (ftnlen)4);
/* L1803: */
	s_copy(line + 4, blk, (ftnlen)120, (ftnlen)4);
    }
L1804:
    if (*tpntrx == 1) {
	goto L1807;
    }
    i__1 = *tpntrx;
    for (i__ = j; i__ <= i__1; i__ += 2) {
	oppair_(line + (l - 1), &textin[i__ - 1], 124 - (l - 1));
/* L1805: */
	l += 20;
    }
L1807:
    k = l;
    goto L9000;

/* ...  MOVE */

L1900:
    limit = *tpntrx - 11;
    j = 1;
    l = 13;
    if (limit <= 0) {
	goto L1804;
    } else {
	goto L1801;
    }

/* ...  VBLJMP */

L2000:
    oppair_(line + 12, textin, (ftnlen)112);
    itext = textin[1];
    s_copy(line + 20, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)104, (ftnlen)
	    6);
    l = 29;
L2006:
    j = 3;
    limit = *tpntrx - 20 + l / 4;
    if (limit <= 0) {
	goto L2004;
    } else {
	goto L2001;
    }
L2001:
    i__1 = limit;
    for (i__ = 1; i__ <= i__1; i__ += 13) {
	for (ii = l; ii <= 112; ii += 8) {
	    if (*optext > 20) {
		goto L2007;
	    }
	    itext = textin[j - 1];
	    s_copy(line + (ii - 1), cnamtb_1.cnamtb + (itext - 1) * 6, 124 - (
		    ii - 1), (ftnlen)6);
	    goto L2002;
L2007:
	    holfrm_(&textin[j - 1], line, &ii, &sdp_1.iwrd, &nwd, (ftnlen)124)
		    ;
	    i__2 = ii + 3;
	    s_copy(line + i__2, blk, ii + 7 - i__2, (ftnlen)4);
L2002:
	    ++j;
	}
	foutxx_(&symfil_1.vlfile, line, &c__120, (ftnlen)124);
	l = 13;
	s_copy(line + 8, blk, (ftnlen)4, (ftnlen)4);
/* L2003: */
	s_copy(line + 4, line, (ftnlen)4, (ftnlen)4);
    }
L2004:
    i__1 = *tpntrx;
    for (i__ = j; i__ <= i__1; ++i__) {
	if (*optext > 20) {
	    goto L2008;
	}
	itext = textin[i__ - 1];
	s_copy(line + (l - 1), cnamtb_1.cnamtb + (itext - 1) * 6, 124 - (l - 
		1), (ftnlen)6);
	goto L2005;
L2008:
	holfrm_(&textin[i__ - 1], line, &l, &sdp_1.iwrd, &nwd, (ftnlen)124);
	i__2 = l + 3;
	s_copy(line + i__2, blk, l + 7 - i__2, (ftnlen)4);
L2005:
	l += 8;
    }
    k = l;
L9000:
    if (k > 120) {
	goto L9002;
    }
/* L9001: */
    s_copy(line + (k - 1), blk, 124 - (k - 1), (ftnlen)4);
L9002:
    foutxx_(&symfil_1.vlfile, line, &c__120, (ftnlen)124);
    return 0;

/* ...  HOLDAT */

L2100:
    itext = textin[0];
    s_copy(line + 12, blk, (ftnlen)112, (ftnlen)4);
    s_copy(line + 16, cnamtb_1.cnamtb + (itext - 1) * 6, (ftnlen)108, (ftnlen)
	    6);
    s_copy(line + 24, blk, (ftnlen)100, (ftnlen)4);
    binbcd_(&textin[1], line + 28, &count, (ftnlen)96);
    l = 37;
    goto L2006;
} /* prtil_ */

#undef tpntrx
#undef optext
#undef textin


