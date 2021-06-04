/* ALARM.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct {
    integer stklst[300];
} stklst_;

#define stklst_1 stklst_

struct {
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer seqno;
} seqcom_;

#define seqcom_1 seqcom_

struct {
    char seqnum[6];
} cseqcm_;

#define cseqcm_1 cseqcm_

struct {
    integer prt[7];
} prt_;

#define prt_1 prt_

struct {
    integer errad1[159], errad2[159];
} errwr_;

#define errwr_1 errwr_

struct {
    char errtxt[7940];
} errtxt_;

#define errtxt_1 errtxt_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer super[36];
} super_;

#define super_1 super_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__2 = 2;
static integer c__5 = 5;
static integer c__88 = 88;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__20 = 20;
static integer c__44 = 44;

/* *** SOURCE FILE : M0004609.W03   *** */


/*              RENTRAN SUBROUTINE ALARM */

/* LINKAGE      SUBROUTINE ALARM(NUMBER,IPOS,ERLV,SUBNAM) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    BINBCD          SUBROUTINE    BOOLIF */
/*          SUBROUTINE    FOUTXX          SUBROUTINE    COMSTR */
/*          SUBROUTINE    MCXTRN          SUBROUTINE    GOLO */
/*          ASM ROUT.     CFORM           SUBROUTINE    GOPAT */
/*          ASM ROUT.     MOVE            SUBROUTINE    ICMPRS */
/*          ASM ROUT.     IVERGL          SUBROUTINE    INPAT */
/*                                        SUBROUTINE    INPUT */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    LABCON */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACLBL */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MATCH */
/*                                        SUBROUTINE    MCXTRN */
/*                                        SUBROUTINE    MNPROC */
/*                                        SUBROUTINE    MOTION */
/*                                        INTEGER FCT.  NAME */
/*                                        SUBROUTINE    ONEARG */
/*                                        SUBROUTINE    OPCODE */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    READ */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REFREF */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    RESERV */
/*                                        SUBROUTINE    RESRED */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */
/*                                        SUBROUTINE    TWOARG */

/* Subroutine */ int alarm_(integer *number, integer *ipos, integer *erlv, 
	char *subnam, ftnlen subnam_len)
{
    /* Initialized data */

    static char b[92] = "                                                   "
	    "                                         ";
    static char astrt[4] = "**  ";
    static char estrt[4] = "*$$*";
    static char wstrt[4] = "*$*$";
    static char blk[4] = "    ";
    static char herrno[8] = "ERR.NO. ";
    static char hequ[16] = " EQUIVALENT TO  ";
    static char hwarn[8] = "WARNING ";
    static char notext[52] = "THERE IS NO DIAGNOSTIC MESSAGE FOR THIS ERROR "
	    "NUMBER";
    static char isncde[4] = "ISN ";
    static integer iseq = 0;
    static integer inum = 0;
    static char from[16] = "FROM SUBROUTINE ";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n, ii, jj, kk, ll;
#define top ((integer *)&stklst_1)
    static integer numb;
#define errx ((integer *)&super_1 + 4)
#define stack ((integer *)&stklst_1 + 3)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define ilhlt ((logical *)&macxx1_1 + 13)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
#define nlast ((integer *)&ntbl_1 + 3)
#define rterm ((integer *)&code_1 + 6)
#define xtras ((integer *)&super_1 + 9)
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
#define finmac ((logical *)&macxx1_1 + 23)
#define estack ((integer *)&errpos_1 + 102)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define ergstk ((integer *)&errpos_1 + 202)
    static integer nummin;
#define nowarn ((logical *)&errpos_1)
    static integer idummy, nummax;
#define errpnt ((integer *)&errpos_1 + 2)
    extern /* Subroutine */ int mcxtrn_(integer *, integer *, integer *);
    static integer nummer;
#define prterr ((logical *)&prt_1 + 5)
    extern /* Subroutine */ int foutxx_(integer *, char *, integer *, ftnlen);




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* CNUMTB:      NUMBER TABLE */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* STACK:       WORKING STACK */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM ' */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */
/* SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRRENT STATEMENT NUMBER */

/*       14.    I. L. LIST OPTION FLAGS */




/* PRTERR:      TRUE IF PPOPTN/PRTER,ON. PRINTOUT OF STACK OR ARGSTK */

/*       21.    ERROR TEXT TABLE */

/* ERND:        DIMENSION OF ERRAD1 AND ERRAD2 (PARTS OF ERRTXT) */
/* ERRDM:       DIMENSION OF ERRTXT */
/* ERRTXT:      STORAGE OF ERROR MESSAGES */
/* ERRAD1:      TRANSLATOR ERROR AND WARNING NUMBERS */
/* ERRAD2:      START POSITIONS OF ERROR MESSAGES IN ERRTXT */

/*       22.    MACRO PROCESSING VARIABLES */







/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* FINMAC:      TRUE DURING FINAL MACRO PROCESSING */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* VLFILE:      VERIFICATION LISTING FILE */

/*       40.    PARAMETERS REQUIRED BY SUPERVISOR */


/* ...                SYSTEM I/O FILES */



/* ERRX:        ERROR LEVEL USED FOR SUPERVISOR */
/* XTRAS:       SPACE FOR ADDITIONAL PARAMETERS */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/*       44.    ERROR POSITION TABLE */

/* NOWARN:      FLAG TRUE IS SUPPRESSING OUTPUT OF WARNING NR. 50 */
/* ERRPNT:      CONTAINS POINTERS TO INPUT STATEMENT TEXT POSITION */
/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* ARGUMENTS    NUMBER     INTEGER ERROR NUMBER */
/*              SUBNAM     NAME OF THE CALLING SUBROUTINE */
/*              IPOS       ERROR POSITION IN STACK OR ARGSTK */

/* ... INITILIZE ARRAY INDICATING WHICH ERRORS ARE OF SEVERITY LEVEL FOUR. */

/* ** */
/* ...     CONVERT ERROR NO. TO BCD AND OUTPUT ERROR MESSAGE */

/* ...     IF MACRO PROCESSING, ONLY OUTPUT ERROR DURING FINAL PASS */
    if (*number >= 20 && *number < 50) {
	goto L5;
    }
    if (*ilhlt) {
	goto L10;
    }
    if (*number == 50 && *nowarn) {
	goto L10;
    }

/* ...     POSITION OF ERROR IN THE INPUT STATEMENT */

L5:
    if (*ipos < 0) {
	goto L510;
    } else if (*ipos == 0) {
	goto L550;
    } else {
	goto L520;
    }
L510:
    kk = ergstk[-(*ipos) - 1];
    goto L530;
L520:
    if (*ipos < 2) {
	*ipos = 2;
    }
    kk = estack[*ipos - 1];
L530:
    if (*finmac) {
	goto L600;
    }
    jj = kk / 100 + 1;
    kk = kk % 100 + 12;
    if (jj == 1) {
	goto L820;
    }
    i__1 = kk + 2;
    iconv_(&jj, b, &i__1, &c__2, (ftnlen)92);
    goto L820;
L600:
    jj = *top;
    if (stack[(*top << 1) - 2] == rterm[1]) {
	--jj;
    }
    if (*ipos > 0) {
/* Computing MIN */
	i__1 = *ipos + 2;
	jj = min(i__1,jj);
    }
    k = 2;
    kk = 0;
L605:
    s_copy(b, blk, (ftnlen)88, (ftnlen)4);
    j = 12;

    i__1 = jj;
    for (i__ = k; i__ <= i__1; ++i__) {
	ii = stack[(i__ << 1) - 2];
	if (ii <= nametb_1.nammax) {
	    goto L610;
	}
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
	ii -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, &ii, &idummy);
	}
	s_copy(b + (j - 1), cnamtb_1.cnumtb + (ii - 1) * 12, (ftnlen)12, (
		ftnlen)12);
	goto L620;
L610:
	if (ii < 0) {
	    ii = -nametb_1.namtbl[ii - 1];
	}
	s_copy(b + (j - 1), cnamtb_1.cnamtb + (ii - 1) * 6, (ftnlen)6, (
		ftnlen)6);
L620:
	if (i__ == *ipos) {
	    kk = j - 1;
	}
	l = i_indx(b + (j - 1), " ", (ftnlen)12, (ftnlen)1);
	if (l == 0) {
	    j += 13;
	} else {
	    j += l;
	}
	if (j > 68) {
	    goto L660;
	}
/* L650: */
    }

L660:
    if (kk > 0) {
	goto L790;
    }
    if (i__ >= jj) {
	goto L670;
    }
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);
    k = i__ + 1;
    goto L605;

L670:
    if (*ipos > 0) {
	goto L550;
    }
    ll = -(*ipos);
    k = 1;
    goto L700;

L680:
    s_copy(b, blk, (ftnlen)88, (ftnlen)4);
    j = 12;

L700:
    i__1 = *argtop;
    for (i__ = k; i__ <= i__1; ++i__) {
	s_copy(b + (j - 1), ", ", (ftnlen)2, (ftnlen)2);
	j += 2;
	l = *argtop + 1 - i__;
	ii = argstk[l - 1];
	if (ii <= nametb_1.nammax) {
	    goto L710;
	}
/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
	ii -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, &ii, &idummy);
	}
	s_copy(b + (j - 1), cnamtb_1.cnumtb + (ii - 1) * 12, (ftnlen)12, (
		ftnlen)12);
	goto L720;
L710:
	if (ii < 0) {
	    ii = -nametb_1.namtbl[ii - 1];
	}
	s_copy(b + (j - 1), cnamtb_1.cnamtb + (ii - 1) * 6, (ftnlen)6, (
		ftnlen)6);
L720:
	if (l != ll) {
	    goto L725;
	}
	kk = j - 1;
	goto L790;
L725:
	l = i_indx(b + (j - 1), " ", (ftnlen)12, (ftnlen)1);
	if (l == 0) {
	    j += 13;
	} else {
	    j += l;
	}
	if (j > 68) {
	    goto L760;
	}
/* L750: */
    }

L760:
    if (kk > 0) {
	goto L790;
    }
    if (i__ >= *argtop) {
	goto L550;
    }
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);
    k = i__ + 1;
    goto L680;

L790:
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);
    s_copy(b, blk, (ftnlen)88, (ftnlen)4);
L820:
    cform_("A", b, &kk, &c__1, (ftnlen)1, (ftnlen)92);
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);
    cform_("    ", b, &kk, &c__4, (ftnlen)4, (ftnlen)92);

/* ...     POSITION OF THE CURRENT ERROR NUMBER */

L550:
    i__ = 0;
    nummin = 1;
    nummax = 159;
L200:
    nummer = (nummin + nummax) / 2;
    numb = errwr_1.errad1[nummer - 1];
    if (i__ > 159) {
	goto L230;
    }
    ++i__;
    if ((i__1 = *number - numb) < 0) {
	goto L220;
    } else if (i__1 == 0) {
	goto L230;
    } else {
	goto L210;
    }
L210:
    nummin = nummer + 1;
    goto L200;
L220:
    nummax = nummer - 1;
    goto L200;
L230:
    s_copy(b, estrt, (ftnlen)4, (ftnlen)4);
    s_copy(b + 4, estrt, (ftnlen)4, (ftnlen)4);
    s_copy(b + 8, astrt, (ftnlen)4, (ftnlen)4);
    s_copy(b + 12, herrno, (ftnlen)8, (ftnlen)8);
    binbcd_(number, b + 20, &n, (ftnlen)72);
    s_copy(b + 28, blk, (ftnlen)4, (ftnlen)4);
    s_copy(b + 32, isncde, (ftnlen)4, (ftnlen)4);
    s_copy(b + 36, cseqcm_1.seqnum, (ftnlen)8, (ftnlen)6);
    s_copy(b + 44, blk, (ftnlen)4, (ftnlen)4);
    s_copy(b + 48, from, (ftnlen)16, (ftnlen)16);
    s_copy(b + 64, subnam, (ftnlen)8, (ftnlen)8);

/* ... SET ERROR LEVEL INDICATOR FOR THE SUPERVISOR. */

    i__ = 2 - *erlv / 8;
    ++xtras[i__ - 1];
    if (*erlv > *errx) {
	*errx = *erlv;
    }
    if (*erlv == 8) {
	goto L8;
    }
    s_copy(b, wstrt, (ftnlen)4, (ftnlen)4);
    s_copy(b + 4, wstrt, (ftnlen)4, (ftnlen)4);
    s_copy(b + 12, hwarn, (ftnlen)8, (ftnlen)8);
L8:
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);

    if (iseq == seqcom_1.seqno && inum == *number) {
	goto L150;
    }
    if (i__ <= 159) {
	goto L235;
    }
    s_copy(b + 12, notext, (ftnlen)52, (ftnlen)52);
    goto L245;
L235:
    kk = errwr_1.errad2[nummer - 1];
    if (nummer == 1) {
	ii = nummer;
    } else {
	ii = errwr_1.errad2[nummer - 2] + 1;
    }
L237:
    k = 12;
    i__1 = kk;
    for (i__ = ii; i__ <= i__1; ++i__) {
	if (k >= 92) {
	    goto L245;
	}
	k += 4;
/* L240: */
	i__2 = k - 4;
	s_copy(b + i__2, errtxt_1.errtxt + (i__ - 1 << 2), k - i__2, (ftnlen)
		4);
    }
L245:
    if (*number == 2058) {
/* Writing concatenation */
	i__3[0] = 6, a__1[0] = cnamtb_1.cnamtb + (stack[(*top + 2 << 1) - 2] 
		- 1) * 6;
	i__3[1] = 2, a__1[1] = "  ";
	s_cat(b + 48, a__1, i__3, &c__2, (ftnlen)8);
/* Writing concatenation */
	i__3[0] = 6, a__1[0] = cnamtb_1.cnamtb + (stack[(*top + 1 << 1) - 2] 
		- 1) * 6;
	i__3[1] = 2, a__1[1] = "  ";
	s_cat(b + 68, a__1, i__3, &c__2, (ftnlen)8);
	seqcom_1.seqno = 0;
    }
    foutxx_(&symfil_1.vlfile, b, &k, (ftnlen)92);
    if (kk - ii < 20) {
	goto L150;
    }
    ii = i__;
    goto L237;

L150:
    if (! (*prterr)) {
	goto L250;
    }
    i__ = *number / 1000 + 1;
    j = 1;
    s_copy(b, blk, (ftnlen)44, (ftnlen)4);

/* ...     BRANCH ON ERROR TYPE (= NUMBER/1000) TO SET UP DUMP LIMITS */

    switch (i__) {
	case 1:  goto L250;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }

/* ...     1000 SERIES - DUMP STACK (FROM 1 TO TOP) */

L20:
    k = *top;
    if (*number == 1028) {
	k = *top - 1;
    }
    goto L50;

/* ...     2000 SERIES - DUMP ARGSTK (FROM 1 TO ARGTOP) */

L30:
    k = *argtop;
    goto L50;

/* ...     3000 SERIES - DUMP NAME PORTION OF NAMTBL (FROM 1 TO NAMMAX) */

L40:
    k = nametb_1.nammax;
    goto L50;

/* ...     THIS LOOP DUMPS APPROPRIATE TABLE */

L50:
    i__2 = k;
    for (l = j; l <= i__2; ++l) {

/* ...     BRANCH ON ERROR TYPE TO DUMP APPROPRIATE TABLE */

	switch (i__) {
	    case 1:  goto L250;
	    case 2:  goto L70;
	    case 3:  goto L80;
	    case 4:  goto L90;
	}

/* ...     1000 SERIES - EXTRACT NAMTBL POINTER FROM STACK */

L70:
	m = stack[(l << 1) - 2];
	goto L60;

/* ...     2000 SERIES - EXTRACT NAMTBL POINTER FROM ARGSTK */

L80:
	m = *argtop + 1 - l;
	m = argstk[m - 1];
	goto L60;

/* ...     3000 SERIES - USE NAMTBL POINTER */

L90:
	m = l;

/* ...     BRANCH IF ITEM IS NOT A NUMBER */

L60:
	if (m <= nametb_1.nammax) {
	    goto L61;
	}

/* ...     STORE BCD OF NUMBER */

/* .... DECREMENT BY NAMMAX FOR ADDRESS IN NUMBER TABLE, CNUMTB */
	m -= nametb_1.nammax;
	if (*nlast > 0) {
	    mcxtrn_(&c__5, &m, &idummy);
	}
	s_copy(b + 4, cnamtb_1.cnumtb + (m - 1) * 12, (ftnlen)12, (ftnlen)12);
	s_copy(b + 16, b, (ftnlen)4, (ftnlen)4);
	goto L62;

/* ...     STORE BCD OF NAME */

L61:
	s_copy(b + 4, cnamtb_1.cnamtb + (m - 1) * 6, (ftnlen)6, (ftnlen)6);

/* ...     IS IT A SYNONYM */

	if (nametb_1.namtbl[m - 1] < 0) {
	    goto L105;
	}

/* ...     NO. CONVERT CLASS/MODE TO BCD. */

	binbcd_(&nametb_1.namtbl[m - 1], b + 12, &n, (ftnlen)80);

/* ...     OUTPUT LINE */

L62:
	if (*prterr) {
	    foutxx_(&symfil_1.vlfile, b, &c__20, (ftnlen)92);
	}
	goto L110;

/* ...     SYNONYM - FIND EQUIVALENT NAME, CONVERT TO BCD AND OUTPUT */

L105:
	m = -nametb_1.namtbl[m - 1];
	s_copy(b + 12, hequ, (ftnlen)16, (ftnlen)16);
	s_copy(b + 28, cnamtb_1.cnamtb + (m - 1) * 6, (ftnlen)6, (ftnlen)6);
	binbcd_(&nametb_1.namtbl[m - 1], b + 36, &n, (ftnlen)56);
	if (*prterr) {
	    foutxx_(&symfil_1.vlfile, b, &c__44, (ftnlen)92);
	}
L110:

/* .....   END OF LOOP */

/* L120: */
	;
    }

/* ...     ALL OF RELEVANT INFORMATION HAS BEEN PRINTED - RETURN */

L250:
    s_copy(b, blk, (ftnlen)88, (ftnlen)4);
    foutxx_(&symfil_1.vlfile, b, &c__88, (ftnlen)92);
    iseq = seqcom_1.seqno;
    inum = *number;
L10:
    return 0;
} /* alarm_ */

#undef prterr
#undef errpnt
#undef nowarn
#undef ergstk
#undef argtop
#undef argstk
#undef estack
#undef finmac
#undef xtras
#undef rterm
#undef nlast
#undef ilhlt
#undef stack
#undef errx
#undef top


