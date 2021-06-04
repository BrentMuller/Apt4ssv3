/* ICMPRS.f -- translated by f2c (version 20100827).
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
    integer code[150];
} code_;

#define code_1 code_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer iltext[94];
} iltext_;

#define iltext_1 iltext_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer pagpak, isc, iscarr, icform, ifloat, icom, macwds, ppwrds;
    logical macflg, labflg, rsvflg;
    integer lpage, buffer[256], labbuf[256], ibuf, ilbuf, pppage, mcpage;
} outbuf_;

#define outbuf_1 outbuf_

/* Table of constant values */

static integer c__7 = 7;
static integer c__0 = 0;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__38 = 38;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006637.W01   *** */


/*              FORTRAN SUBROUTINE ICMPRS */

/* LINKAGE      SUBROUTINE ICMPRS */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    CILOUT          SUBROUTINE    COMPRS */
/*          SUBROUTINE    ALARM           SUBROUTINE    IPRLOG */
/*          SUBROUTINE    HELP */
/*          SUBROUTINE    BINCHK */
/*          SUBROUTINE    RLSBUF */

/* Subroutine */ int icmprs_(void)
{
    /* Initialized data */

    static integer blksiz = 128;
    static logical operck = FALSE_;
    static logical seqflg = FALSE_;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, m, n;
#define ic ((integer *)&outbuf_1 + 1)
    static integer jc, im;
#define fcn ((integer *)&code_1 + 34)
    static integer siz;
#define real__ ((integer *)&modx_1 + 20)
    static integer mode;
    extern /* Subroutine */ int help_(void);
    static integer left;
#define bool ((integer *)&modx_1 + 22)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
    static integer itext;
    extern /* Subroutine */ int binchk_(integer *);
    static integer labsav[5];
#define proced ((integer *)&code_1 + 36)
#define modulo ((integer *)&moduli_1)
    extern /* Subroutine */ int cilout_(integer *, integer *, integer *), 
	    rlsbuf_(void);
    static integer caltyp, seqnum;
#define textin ((integer *)&iltext_1 + 4)
    static integer pronum;
#define optext ((integer *)&iltext_1 + 3)
#define tpntrx ((integer *)&iltext_1 + 2)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* FCN:         (1)=CODE CLASS 18000,(2)=NAMTBL INDEX OF 'FCN   ' */
/* PROCED:      (1)=CODE CLASS 19000,(2)=NAMTBL INDEX OF 'PROCED' */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR A SCALAR */
/* BOOL:        MODE CODE (23) FOR BOOLEAN TYPE */

/*       19.    INTERMEDIATE LANGUAGE TEXT */

/* TPNTRX:      POINTER TO LAST TEXTIN ENTRY */
/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */
/* TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */

/*       34.    COMMON BLOCK FOR INTERPRETIVE C.I.L. OUTPUT */

/* ICOM:        NUMBER OF WORDS OF BLANK COMMON REQUIRED BY LDA */
/* MACFLG:      TRUE WHEN MACRO PROCESSING IN EFFECT (INTERPRETER) */
/* LABFLG:      INDICATES I.L. COMMAND IS LABEL (INTERPRETER) */
/* RSVFLG:      TRUE IF I.L. COMMAND IS A RESRV (INTERPRETER) */
/* IBUF:        NUMBER OF RECORDS IN BUFFER ARRAY */
/* PPPAGE:      PAGE NUMBER OF PART PROGRAMMING TEXT (INTERPRETER) */
/* MCPAGE:      NUMBER OF PAGES OF MACRO I.L. (INTERPRETER) */
/* IC:          NUMBER OF SCALARS IN BLOCK 1 OF CANONICAL FORMS */



/* * */
/* ** */
/* L100: */
    if (seqflg) {
	goto L510;
    }
L120:
    switch (*optext) {
	case 1:  goto L300;
	case 2:  goto L300;
	case 3:  goto L300;
	case 4:  goto L300;
	case 5:  goto L300;
	case 6:  goto L400;
	case 7:  goto L130;
	case 8:  goto L200;
	case 9:  goto L500;
	case 10:  goto L200;
	case 11:  goto L600;
	case 12:  goto L700;
	case 13:  goto L800;
	case 14:  goto L200;
	case 15:  goto L900;
	case 16:  goto L200;
	case 17:  goto L1000;
	case 18:  goto L1100;
	case 19:  goto L1200;
	case 20:  goto L200;
	case 21:  goto L1300;
    }

/* ...    ENTRY - NO OUTPUT */

L130:
    return 0;

/* ...     NO SPECIAL TREATMENT REQUIRED - OUTPUT USING CILOUT */

L200:
    cilout_(optext, tpntrx, textin);
    return 0;

/* ...    LABEL - STORE I.L. */

L400:
    labsav[0] = *optext;
    labsav[2] = textin[0];

/* ...     RELEASE I.L. BUFFER IF NECCESSARY */

    if (outbuf_1.ibuf + 2 > 254) {
	rlsbuf_();
    }
    outbuf_1.labflg = TRUE_;
    if (outbuf_1.macflg) {
	goto L410;
    }
    labsav[3] = outbuf_1.pppage + 1;
    goto L420;

/* ...     MACRO PROCESSING IN PROGRESS */

L410:
    labsav[3] = -outbuf_1.mcpage - 1;
L420:
    labsav[1] = 3;
    labsav[4] = outbuf_1.ibuf + 3;
    cilout_(labsav, &labsav[1], &labsav[2]);
    outbuf_1.labflg = FALSE_;
    cilout_(&c__7, &c__0, textin);
    return 0;

/* ...     SEQNCE COMMAND - STORE I.L. AND SET SEQFLG */

L500:
    seqnum = textin[0];
    seqflg = TRUE_;
    return 0;

/* ...     RESRV COMMAND - INCREASE APPROPRIATE COUNT AND OUTPUT */

L700:
    mode = textin[1];
    siz = textin[2] + 1;
    n = textin[3];
    im = 1;
    outbuf_1.rsvflg = TRUE_;
/*        MODE NON-SUBCRIPTED SCALAR */
    if (mode != *real__ && mode != *bool || n != 1) {
	goto L701;
    }
    im = 0;
    j = 1;
    goto L710;
/*        MODE SUBSRIPTED SCALAR. */
L701:
    if (mode == *real__ && n != 1) {
	j = 2;
    }
    if (mode == *bool && n != 1) {
	j = 2;
    }
/*        MODE INTERNALLY GENERATED VARIABLE. */
    if (mode != 0) {
	goto L705;
    }
    j = 4;
    --siz;
    im = 0;
/*        MODE BLANK COMMON. */
L705:
    if (mode < 0) {
	goto L760;
    }
/*        MODE NON-SCALAR */
    if (mode > 0 && mode != *real__ && mode != *bool) {
	j = 3;
    }
/* ...     UP POINTER */
L710:
    jc = ic[j - 1] + n * siz + im;
/*        WILL FORM FIT IN CURRENT BLOCK. */
    if (ic[j - 1] / blksiz == jc / blksiz) {
	goto L720;
    }
/*        NO, SPLIT FORM IF INDEXED. */
    left = blksiz - ic[j - 1] % blksiz;
/*        OBTAIN NO. OF ELEMENTS WHICH WILL FIT IN REST OF BLOCK */
    m = (left - 1) / siz;
/*        ENTIRE ARRAY CAN NOT FIT */
    if (m == n) {
	--m;
    }
/*        INCREASE POINTER, DECREASE  NO. OF ELEMENTS, ITERATE */
    ic[j - 1] += left;
    n -= m;
    goto L710;
L720:
    ic[j - 1] = jc;

/* ...     OUTPUT IS TO EXFIL1 */

/* .....   INTERNALLY GENERATED VARIABLES */
L730:
    cilout_(optext, tpntrx, textin);
    outbuf_1.rsvflg = FALSE_;
    return 0;

/* ....    BLANK COMMON */

L760:
    outbuf_1.icom += textin[2];
    goto L730;

/* ...     CALL COMMAND - FORM CORRECT PROCEDURE NUMBER */

L1100:
    itext = textin[0];
    goto L1110;

/* ...     CHECK ARGUMENT LIST FOR PROCEDURE INDICES */

L1120:
    operck = TRUE_;
    j = *tpntrx - 1;
    i__1 = j;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	if (textin[i__ - 1] != 4) {
	    goto L1130;
	}

/* ...     THIS ARGUMENT IS A PROCEDURE INDEX */

	itext = textin[i__];

/* ...     FORM PROCEDURE NUMBER. */
/* ...     ALL PROCEDURES HAVE A UNIQUE MODE, THEREFORE EACH PROCEDURE CAN */
/* ...     BE ASSIGNED A UNIQUE NUMBER.  THIS IS DONE IN ORDER THAT THE */
/* ...     EXECUTION PHASE CAN CALL A PROCEDURE BY NUMBER. */

L1110:
	pronum = nametb_1.namtbl[itext - 1];
	caltyp = *modulo * (pronum / *modulo);
	pronum -= caltyp;

/* ...     CALTYP IS THE CLASS OF THE PROCEDURE, AND SHOULD THEREFORE BE */
/* ...     EITHER PROCED OR FCN */

	if (caltyp != proced[0] && caltyp != fcn[0]) {
	    goto L9999;
	}
	if (pronum < 500) {
	    goto L1125;
	}
	pronum = itext + 1000;
/* ...PRONUM IS NOW A POINTER TO THE PROCEDURE NUMBER */

/* ...     WAS THIS AN ARGUMENT */

L1125:
	if (! operck) {
	    goto L1140;
	}

/* ...     YES. STORE PROCEDURE NUMBER AND CONTINUE LOOP */

	textin[i__] = pronum;
L1130:
	;
    }
    operck = FALSE_;
    goto L1150;

/* ...     STORE PROCEDURE NUMBER AND START TO INSPECT ARGUMENT LIST */

L1140:
    textin[0] = pronum;
    if (*tpntrx > 1) {
	goto L1120;
    }

/* ...     OUTPUT I.L. */



/* ...     WAS THIS A CALL TO FINI. IF NOT RETURN */

L1160:
    if (pronum != 18) {
	goto L200;
    }

/* ...     CALL WAS TO FINI. */
/* ...     FUTURE I.L. WILL BE MACRO TEXT. */

    cilout_(optext, tpntrx, textin);
    rlsbuf_();
    outbuf_1.macflg = TRUE_;
    return 0;

/* ...     LAST COMMAND WAS SEQUENCE, AND NOT OUTPUT. */
/* ...    IF THIS IS A LABEL COMMAND,OUTPUT THIS FIRST */

L510:
    if (*optext == 6) {
	goto L120;
    }
    cilout_(&c__9, &c__1, &seqnum);
    seqflg = FALSE_;
    goto L120;

/* ...     THE FOLLOWING CODE IS TO CHECK OPERANDS FOR THOSE WITH A */
/* ...     MODIFIER OF 1, FOLLOWED BY AN INTEGER CONSTANT INDEX. */
/* ...     THESE ARE TO BE CHANGED TO MODIFIER OF 5, FOLLOWED BY */
/* ...     THE BINARY NUMBER ITSELF */


/* ...     FADD,FSUB,FMPY,FDIV,FEXP */

L300:
    binchk_(&c__1);
    binchk_(&c__3);
    binchk_(&c__5);
    goto L200;

/* ...     CONJMP */

L600:
    binchk_(&c__1);
    goto L200;

/* ...     CVTSUB */

L800:
    binchk_(&c__5);
    goto L200;

/* ...     ASNADD */

L900:
    goto L1120;


/* ...     REPL */

L1000:
    binchk_(&c__4);
    goto L200;

/* ...     CALL */

L1150:
    j = *tpntrx - 1;
    i__1 = j;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
/* L1170: */
	binchk_(&i__);
    }
    goto L1160;

/* ...     MOVE */

L1200:
    j = *tpntrx - 1;
    i__1 = j;
    for (i__ = 3; i__ <= i__1; i__ += 2) {
/* L1210: */
	binchk_(&i__);
    }
    goto L200;

/* ...     HOLDAT STATEMENT */

L1300:
    j = 4;
    siz = (*tpntrx + 1) / 2;
    n = 1;
    im = 0;
    goto L710;

/* ...     SUPPOSED PROCEDURE DOES NOT HAVE CLASS PROCED OR FCN */

L9999:
    alarm_(&c__38, &c__0, &c__8, "ICMPRS  ", (ftnlen)8);
    help_();
    return 0;
} /* icmprs_ */

#undef tpntrx
#undef optext
#undef textin
#undef modulo
#undef proced
#undef bool
#undef real__
#undef fcn
#undef ic


