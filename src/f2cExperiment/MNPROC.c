/* MNPROC.f -- translated by f2c (version 20100827).
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
    integer seqcom[3];
} seqcom_;

#define seqcom_1 seqcom_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx3[1430];
} macxx3_;

#define macxx3_1 macxx3_

struct {
    integer macxx4[100];
} macxx4_;

#define macxx4_1 macxx4_

struct {
    integer macxx6[1300];
} macxx6_;

#define macxx6_1 macxx6_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer ntbl[6];
} ntbl_;

#define ntbl_1 ntbl_

/* Table of constant values */

static integer c__31 = 31;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c__1022 = 1022;

/* *** SOURCE FILE : M0006655.V04   *** */


/*              FORTRAN SUBROUTINE MNPROC */

/* LINKAGE      SUBROUTINE MNPROC */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    HELP            SUBROUTINE    MACREC */
/*          SUBROUTINE    ALARM           SUBROUTINE    PRO026 */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    MACLBL */
/*          SUBROUTINE    RLSLIN */

/* Subroutine */ int mnproc_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, m, n, kk;
    extern /* Subroutine */ int help_(void);
    static integer iasv[6000];
#define label ((integer *)&code_1 + 42)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define ilhlt ((logical *)&macxx1_1 + 13)
#define mnmvb ((integer *)&macxx4_1)
#define mnmvc ((integer *)&macxx4_1 + 25)
#define nlast ((integer *)&ntbl_1 + 3)
#define seqno ((integer *)&seqcom_1)
#define macdf1 ((integer *)&macxx3_1)
#define macdf2 ((integer *)&macxx3_1 + 400)
#define entry__ ((logical *)&macxx1_1 + 39)
#define nxtln ((integer *)&macxx1_1 + 68)
#define macend ((logical *)&macxx1_1 + 61)
#define macfnd ((integer *)&macxx1_1 + 59)
#define macdfp ((integer *)&macxx1_1)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
#define finmac ((logical *)&macxx1_1 + 23)
#define macvbl ((integer *)&code_1 + 70)
#define pathch ((integer *)&macxx1_1 + 70)
#define macspd ((integer *)&macxx6_1)
#define macseq ((integer *)&macxx4_1 + 50)
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
    static integer numbeg;
#define numcal ((integer *)&macxx1_1 + 27)
#define mcsrch ((integer *)&macxx1_1 + 58)
#define nmline ((integer *)&macxx1_1 + 24)
#define mactop ((integer *)&macxx1_1 + 41)
#define number ((integer *)&code_1 + 26)
#define mcsavp ((integer *)&macxx1_1 + 4)
#define bitwds ((integer *)&macxx1_1 + 28)
#define mchstp ((integer *)&macxx1_1 + 2)
#define mnmvbp ((integer *)&macxx1_1 + 5)
#define numbit ((integer *)&macxx1_1 + 55)
#define mcspdp ((integer *)&macxx1_1 + 56)
#define numarg ((integer *)&macxx1_1 + 60)
#define whchmn ((integer *)&macxx1_1 + 62)
#define lnusdp ((integer *)&macxx1_1 + 50)
#define largmv ((integer *)&macxx1_1 + 63)
#define mspddm ((integer *)&macxx1_1 + 64)
#define pathln ((integer *)&macxx1_1 + 67)
#define maxsps ((integer *)&macxx1_1 + 20)
#define machst ((integer *)&macxx3_1 + 800)
#define modulo ((integer *)&moduli_1)
    extern /* Subroutine */ int rlslin_(void);
#define entryx ((integer *)&il_1 + 6)
#define textst ((integer *)&macxx1_1 + 14)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* MACVBL:      (1)=CODE CLASS 36000,(2)=NAMTBL INDEX OF 'MACVBL' */

/*       11.    SEQUENCE NUMBER STORAGE */

/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* ENTRYX:      CONTAINS COMMAND CODE ( 7) FOR ENTRY COMMAND */

/*       22.    MACRO PROCESSING VARIABLES */

/* MACDFP:      POINTER TO LAST ENTRY IN MACDF1 AND MACDF2 ARRAYS */
/* MCHSTP:      POINTER TO LAST MACHST ENTRY */
/* MCSAVP:      PRESENT NEST LEVEL DURING MACRO PROCESSING */
/* MNMVBP:      POINTER TO LAST MNMVB AND MNMVC TABLE ENTRY */
/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* TEXTST:      POINTER TO MCBUFF OF MACRO TEXT WORD BEING PROCESSED */
/* MAXSPS:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* FINMAC:      TRUE IF SECOND FINAL PASS OF MACRO PROCESSING */
/* NMLINE:      EQUALS NUMBER OF EXPRESSIONS THAT REQUIRE BRANCHING I.L. */
/* NUMCAL:      CONTAINS NUMBER OF CALLS FOR CURRENT MACRO */
/* BITWDS:      NUMBER OF WORDS NEEDED FOR ALL CALL QUALITIES OF MACRO */
/* NUMBIT:      CONTAINS NUMBER OF BITS IN A FIXED POINT WORD */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* MACTOP:      POINTER TO EXPRESSION NUMBER IN MACSPD TABLE */
/* LNUSDP:      INDEX OF LAST LINUSD ENTRY */
/* MCSPDP:      POINTER TO LAST ENTRY IN MACSPD TABLE */
/* MCSRCH:      AT FINAL MACRO PRECESSING MACDF1 POINTER */
/* MACFND:      1 IF NO MACRO OF CURRENT LEVEL ENCOUNTERED. OTHERWISE 0 */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* MACEND:      TRUE WHEN ALL MACRO PROCESSING IS FINISHED */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */
/* LARGMV:      KEEPS TRACK OF LARGEST NUMBER OF MACRO VARIABLES */
/* MSPDDM:      CONTAINS DIMENSION OF THE ARRAY MACSPD */
/* PATHLN:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */
/* NXTLN:       POINTER TO NEXT LINUSD POSITION TO BE EXAMINED */
/* PATHCH:      CURRENT ACTUAL BRANCHING EXPRESSION. INITIALLY=NUMARG */

/*       24.    MACRO PROCESSING ARRAYS */

/* MACDF1:      STORES MACRO NAME AND ALL MACRO VBL NAMTBL POINTERS */
/* MACDF2:      STORES NORMAL VALUES FOR ALL MACRO VARIABLES */
/* MACHST:      MACRO CALL HISTORY TABLE */

/*       25.    MACRO PROCESSING ARRAYS */

/* MNMVB:       INDICATES MACROS IN WHICH ARE ASSIGNED VALUES */
/* MNMVC:       CALLED MACRO FOR WHICH CORRESPONDING MNMVB ENTRY IS MADE */
/* MACSEQ:      PRESERVES INITIAL SEQUENCE NUMBERS OF THE MACROS */

/*      26A.    MACRO PROCESSING ARRAYS */

/* MACSPD:      NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       41.    NUMBER TABLE OVERFLOW VARIABLES */

/* NLAST:       LAST NEW BLOCK NUMBER OF NUMBER TABLE ON THE EXTERN FILE */

/* ..... LOCAL ARRAY TO KEEP TRACK OF ASSIGNED VARIABLES TO AVOID */
/*      CORRUPTING NAME AND NUMBER TABLES */
/* ** */
/* ...     LARGMV KEEPS COUNT OF NUMBER OF MACRO VARIABLES AND LINKAGE */
/* ...     CELLS NEEDED FOR ALL MACROS OF CURRENT LEVEL. */

    if (*maxsps > *largmv) {
	*largmv = *maxsps;
    }

/* ...     BRANCH IF NOT FIRST MACRO TO UNDERGO FINAL PROCESSING. */

    if (*mcsrch != 0) {
	goto L35;
    }
    *mcsavp = 1;
L71:
    *mcsrch = 1;

/* ...     BRANCH IF ALL MACROS OF CURRENT LEVEL HAVE BEEN PROCESSED. */

L1:
    if (*mcsrch > *macdfp) {
	goto L65;
    }
    *mcspdp = 0;

/* ...       SKIP IF MACRO WAS NOT CALLED */

    if (macdf2[*mcsrch + 1] == 0) {
	goto L35;
    }

/* ...     CHECK IF MACRO BEING EXAMINED IS OF CURRENT LEVEL. */
/* ...     = NEGATIVE - MACRO ALREADY PROCESSED. */
/* ...     = ZERO     - PROCESS IT. */
/* ...     = PLUS     - NOT READY TO PROCESS THIS MACRO. */

/* L2: */
    if ((i__1 = macdf2[*mcsrch - 1] - *mcsavp) < 0) {
	goto L35;
    } else if (i__1 == 0) {
	goto L7;
    } else {
	goto L6;
    }

/* ...     DETERMINE LOCATION OF NEXT MACRO IN MACDF1 TABLE. */

L35:
    if (macdf1[*mcsrch + 1] <= 0) {
	goto L3;
    } else {
	goto L4;
    }
L3:
    *mcsrch += 3;
    goto L1;
L4:
    *mcsrch = macdf1[*mcsrch + 1] + 1;
    goto L1;

/* ...     MACFND SET TO 1 IF NO MACRO OF CURRENT LEVEL ENCOUNTERED. */
/* ...     OTHERWISE SET TO 0. */

L6:
    *macfnd = abs(*macfnd);
    goto L35;
L7:
    *macfnd = 0;

/* ...     COMPUTE BEGINNING (NUMBEG) AND END (NUMARG) OF MACRO VARIABLES */
/* ...     IN THE MACDF1 TABLE. */

    *numarg = macdf1[*mcsrch + 1];
/* L8: */
    numbeg = *mcsrch + 3;

/* ...     INITIALLY ZERO THE MACSPD TABLE PRIOR TO STORING CALL HISTORY. */

    for (i__ = 1; i__ <= 1300; ++i__) {
/* L51: */
	macspd[i__ - 1] = 0;
    }
    *mcspdp = 1;
    if (*numarg != 0) {
	*mcspdp = *numarg - *mcsrch - 1;
    }

/* ...     BEGIN SCANNING THE MACHST TABLE TO RETRIEVE, EXPAND, AND PLACE */
/* ...     IN THE MACSPD TABLE CALL INFORMATION FOR CURRENT MACRO. */

    l = 2;

/* ...     DO NOT BRANCH IF CALL INFORMATION FOR CURRENT MACRO FOUND. */

L9:
    if (machst[l - 1] != *mcsrch) {
	goto L5;
    }
    k = 1;
    m = l;
    if (machst[l] == 0) {
	goto L91;
    }
    if (*numarg == 0) {
	goto L93;
    }
    if (*mcspdp + *numarg - numbeg + 2 <= *mspddm) {
	goto L94;
    }
L95:
    alarm_(&c__31, &c__0, &c__8, "MNPROC  ", (ftnlen)8);
    help_();

/* ...     PLACE ASSIGNED VALUES FOR THIS CALL IN MACSPD TABLE. */

L94:
    i__1 = *numarg;
    for (i__ = numbeg; i__ <= i__1; ++i__) {
	if (k != machst[l + 1] / 100000) {
	    goto L10;
	}
	macspd[*mcspdp] = machst[l + 1] - k * 100000;
	++l;
	goto L11;
L10:
	macspd[*mcspdp] = macdf2[i__ - 1];
	if (*nlast > 0) {
	    macspd[*mcspdp] = -macspd[*mcspdp];
	}
L11:
	++(*mcspdp);
/* L12: */
	++k;
    }

/* ...     PLACE CALL NUMBER IN MACSPD TABLE. */

L93:
    ++(*mcspdp);
    if (*mcspdp > *mspddm) {
	goto L95;
    }
    macspd[*mcspdp - 1] = machst[m];
L91:
    l += 2;
/* L92: */
    if (*mchstp - l >= 0) {
	goto L14;
    } else {
	goto L13;
    }

/* ...     NO MORE CALL INFORMATION REMAINS TO BE SCANNED. */

L13:
    *mchstp = m - 2;

/* ...     BRANCH IF THERE ARE NO MACRO VARIABLES. */

L18:
    if (*numarg == 0) {
	goto L19;
    }
    *numarg = *numarg - numbeg + 2;

/* ...     GENERATE MACRO VARIABLE NAMES, STORE THEM IN NAMTBL, AND PLACE */
/* ...     THEIR NAMTBL INDICES IN THE MACSPD TABLE. */

    i__1 = *numarg;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = -(*mcsavp);
	i__3 = -i__;
	maclbl_(&i__2, &i__3, &l);
/*      PROTECT NAMTBL ENTRY ON SUBSEQUENT CALLS */
	nametb_1.namtbl[l - 1] = macvbl[0];
/* L32: */
	macspd[i__ - 2] = l;
    }

/* ...     BRANCH IF NO MACRO VARIABLES HAVE BEEN ASSIGNED MACRO NAMES. */

L19:
    if (*mnmvbp == 0) {
	goto L20;
    }
    i__ = 1;
L61:
    if (mnmvc[i__ - 1] != *mcsrch) {
	goto L62;
    }

/* ...     REMOVE REFERENCES TO CURRENT MACRO FROM MNMVC TABLE. */

    --(*mnmvbp);
    mnmvb[i__ - 1] = mnmvb[*mnmvbp];
    mnmvc[i__ - 1] = mnmvc[*mnmvbp];
L63:
    if (*mnmvbp < i__) {
	goto L20;
    }
    goto L61;
L62:
    ++i__;
    goto L63;

/* ...     INITIALIZE COUNTERS,POINTERS, AND FLAGS USED IN FINAL MACRO */
/* ...     PROCESSING. */

L20:
    *textst = macdf1[*mcsrch];
    *whchmn = macdf2[*mcsrch];
    *seqno = macseq[*whchmn - 1];
    *ilhlt = TRUE_;
    *finmac = FALSE_;
    *mactop = *mcspdp;
    *entry__ = FALSE_;
    *nmline = *numarg;
    *numcal = macdf2[*mcsrch + 1];
    if (*numarg == 0) {
	goto L53;
    }

/* ...     FOR EACH MACRO VARIABLE SELECT AS ITS NORMAL VALUE THE MOST */
/* ...     COMMONLY USED ASSIGNED VALUE. ALSO ESTABLISH AS THE CLASS AND */
/* ...     MODE OF EACH MACRO VARIABLE THAT OF ITS FIRST ASSIGNED VALUE. */

    i__ = 1;
L52:
    ++i__;
    j = macspd[i__ - 2];
    l = *numarg + i__;
    k = macspd[l - 2];
    if (*nlast > 0 && k < 0) {
	k = -k;
    }
    nametb_1.namtbl[j - 1] = number[0] + *modhlf;
    if (k > nametb_1.nammax) {
	goto L55;
    }
    kk = nametb_1.namtbl[k - 1];
    if (kk - *modulo * (kk / *modulo) < *modhlf) {
	kk += *modhlf;
    }
    nametb_1.namtbl[j - 1] = kk;
L55:
    if (*nlast > 0) {
	goto L140;
    }
    l = 0;

/* ...IASV IS USED TO KEEP TRACK OF THE FREQUENCY OF THE ASSIGNED VALUES. */

    m = i__;
    i__1 = *numcal;
    for (j = 1; j <= i__1; ++j) {
	m += *numarg;
	n = macspd[m - 2];
/* L109: */
	iasv[n - 1] = 0;
    }

/* ...     K POINTS TO MOST COMMONLY USED ASSIGNED VALUE. */
/* ...     L KEEPS TRACK OF ITS FREQUENCY. */

    i__1 = *numcal;
    for (j = 1; j <= i__1; ++j) {
	m = j * *numarg + i__;
	n = macspd[m - 2];
	++iasv[n - 1];
	if (n == k) {
	    goto L102;
	}
	if (iasv[n - 1] <= l) {
	    goto L110;
	}
	l = iasv[n - 1];
	k = n;
	goto L110;
L102:
	++l;
L110:
	;
    }
    goto L130;

/* ...     INITIALIZE PARAMETERS AND COUNTERS USED IN MACRO PROCESSING. */

L53:
    *bitwds = (*numcal - 1) / *numbit + 1;
    *maxsps = *numarg;
    *nxtln = 1;
    *lnusdp = 0;
    *pathln = *numarg;
    *pathch = *numarg;
    return 0;

/* ...     COMPRESS MACHST TABLE TO ERASE CURRENT CALL INFORMATION STRING. */

L14:
    i__1 = *mchstp;
    for (i__ = l; i__ <= i__1; ++i__) {
	j = i__ - (l - m + 1);
/* L15: */
	machst[j - 1] = machst[i__ - 1];
    }
    machst[j] = 0;
    *mchstp = j;
    l = m;
    goto L9;

/* ...     LOCATE NEXT CALL INFORMATION STRING IN MACHST. */

L5:
    if (machst[l + 1] / 100000 != 0) {
	goto L16;
    } else {
	goto L17;
    }
L16:
    ++l;
    goto L5;
L17:
    l += 3;
    if (l - *mchstp <= 0) {
	goto L9;
    } else {
	goto L18;
    }
L65:
    if (*largmv <= 0) {
	goto L27;
    } else {
	goto L25;
    }

/* ...     GENERATE I.L. TRANSFER COMMANDS FOR MACRO VARIABLES AND LINKAGE */
/* ...     CELLS FOR CURRENT MACRO DEPTH LEVEL. */

L25:
    i__1 = *largmv;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = -(*mcsavp);
	i__3 = -i__;
	maclbl_(&i__2, &i__3, &l);
	nametb_1.namtbl[l - 1] = label[0];
	opcode_(entryx);
	onearg_(&l);
/* L26: */
	rlslin_();
    }
L27:
    if (*macfnd < 0) {
	goto L28;
    } else if (*macfnd == 0) {
	goto L29;
    } else {
	goto L30;
    }

/* ...     PREPARE TO PROCESS MACROS OF NEXT DEPTH LEVEL. */

L29:
    ++(*mcsavp);
    *largmv = 0;
    *macfnd = -1;
    if (*mnmvbp == 0) {
	goto L73;
    }

/* ...     ADJUST DEPTH LEVEL IN MACDF2 TABLE OF THOSE UNPROCESSED MACROS */
/* ...     WHICH ARE MACRO VARIABLE ASSIGNED VALUES. */

    i__1 = *mnmvbp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k = mnmvc[i__ - 1];
/* L72: */
	if (macdf2[k - 1] <= *mcsavp) {
	    macdf2[k - 1] = *mcsavp + 1;
	}
    }

/* ...     ADJUST DEPTH LEVEL OF THOSE MACROS WHICH ARE DIRECTLY CALLED BY */
/* ...     UNPROCESSED MACROS WHICH ARE MACRO VARIABLE ASSIGNED VALUES. */

L73:
    i__ = 1;
L74:
    if (i__ > *mchstp) {
	goto L71;
    }
    k = machst[i__ - 1];
    if (macdf2[k - 1] < *mcsavp) {
	goto L75;
    }
    j = machst[i__];
    if (macdf2[j - 1] <= macdf2[k - 1]) {
	macdf2[j - 1] = macdf2[k - 1] + 1;
    }
L75:
    i__ += 2;
L76:
    ++i__;
    if (machst[i__ - 1] / 100000 == 0) {
	goto L74;
    }
    goto L76;

/* ...     NO MORE MACROS REMAIN TO BE PROCESSED. */

L28:
    *macend = TRUE_;
    return 0;

/* ...     1022 - RECURSIVE USE OF MACROS */

L30:
    alarm_(&c__1022, &c__0, &c__8, "MNPROC  ", (ftnlen)8);
    goto L28;

/*     MARK MOST COMMON ASSIGNMENT */
L130:
    i__1 = *numcal;
    for (l = 1; l <= i__1; ++l) {
	j = *numcal - l + 1;
	m = j * *numarg + i__;
	n = macspd[m - 2];
	if (n == k) {
	    macspd[m - 2] = -macspd[m - 2];
	}
/* L120: */
    }
    if (i__ < *numarg) {
	goto L52;
    }
    goto L53;
L140:
    kk = *numarg + i__ - 1;
    k = macspd[kk - 1];
    if (k < 0) {
	goto L180;
    }
    i__1 = *numcal;
    for (l = 1; l <= i__1; ++l) {
	j = *numcal - l + 1;
	m = j * *numarg + i__;
	n = macspd[m - 2];
	if (n < 0) {
	    goto L180;
	}
/* L150: */
    }
    i__1 = *numcal;
    for (l = 1; l <= i__1; ++l) {
	j = *numcal - l + 1;
	m = j * *numarg + i__;
	n = macspd[m - 2];
	if (n == k) {
	    macspd[m - 2] = -macspd[m - 2];
	}
/* L160: */
    }
L180:
    if (i__ < *numarg) {
	goto L52;
    }
    goto L53;
} /* mnproc_ */

#undef textst
#undef entryx
#undef modulo
#undef machst
#undef maxsps
#undef pathln
#undef mspddm
#undef largmv
#undef lnusdp
#undef whchmn
#undef numarg
#undef mcspdp
#undef numbit
#undef mnmvbp
#undef mchstp
#undef bitwds
#undef mcsavp
#undef number
#undef mactop
#undef nmline
#undef mcsrch
#undef numcal
#undef modhlf
#undef macseq
#undef macspd
#undef pathch
#undef macvbl
#undef finmac
#undef macdfp
#undef macfnd
#undef macend
#undef nxtln
#undef entry__
#undef macdf2
#undef macdf1
#undef seqno
#undef nlast
#undef mnmvc
#undef mnmvb
#undef ilhlt
#undef label


