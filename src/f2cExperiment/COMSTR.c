/* COMSTR.f -- translated by f2c (version 20100827).
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
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx3[1430];
} macxx3_;

#define macxx3_1 macxx3_

struct {
    integer itmpsv[135];
} macxx5_;

#define macxx5_1 macxx5_

struct {
    integer macspd[1300];
} macxx6_;

#define macxx6_1 macxx6_

/* Table of constant values */

static integer c__1 = 1;
static integer c__1021 = 1021;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c_n1 = -1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0006628.V04   *** */

/*              FORTRAN SUBROUTINE COMSTR */

/* LINKAGE      SUBROUTINE COMSTR */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ASNADZ          SUBROUTINE    MACREC */
/*          SUBROUTINE    ASNJPZ */
/*          LOGICAL FCT.  BITMCH */
/*          SUBROUTINE    CALLZZ */
/*          SUBROUTINE    JUMPZZ */
/*          SUBROUTINE    ALARM */
/*          SUBROUTINE    LABELZ */
/*          SUBROUTINE    MACLBL */
/*          INTEGER FCT.  NAME */
/*          SUBROUTINE    RETMCX */
/*          SUBROUTINE    RLSLIN */

/* Subroutine */ int comstr_(void)
{
    /* Initialized data */

    static char i297[6] = "APT297";
    static integer j297 = 19206;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k;
    extern integer name_(char *, ftnlen);
#define label ((integer *)&code_1 + 42)
    static integer wdcal;
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define macdf1 ((integer *)&macxx3_1)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
    static integer bitcal, maccnt;
    extern logical bitmch_(integer *, integer *);
    extern /* Subroutine */ int labelz_(integer *);
    static integer argcnt;
#define numcal ((integer *)&macxx1_1 + 27)
#define mcsrch ((integer *)&macxx1_1 + 58)
#define mactop ((integer *)&macxx1_1 + 41)
#define mcspdp ((integer *)&macxx1_1 + 56)
#define mcsavp ((integer *)&macxx1_1 + 4)
#define numarg ((integer *)&macxx1_1 + 60)
#define bitwds ((integer *)&macxx1_1 + 28)
    extern /* Subroutine */ int asnadz_(integer *, integer *);
#define numbit ((integer *)&macxx1_1 + 55)
    extern /* Subroutine */ int callzz_(integer *);
    static integer argscr;
    extern /* Subroutine */ int retmcx_(integer *), rlslin_(void), asnjpz_(
	    integer *, integer *);
#define maxsps ((integer *)&macxx1_1 + 20)
    extern /* Subroutine */ int jumpzz_(integer *);



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */

/*       22.    MACRO PROCESSING VARIABLES */

/* MCSAVP:      PRESENT NEST LEVEL DURING MACRO PROCESSING */
/* MAXSPS:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* NUMCAL:      CONTAINS NUMBER OF CALLS FOR CURRENT MACRO */
/* BITWDS:      NUMBER OF WORDS NEEDED FOR ALL CALL QUALITIES OF MACRO */
/* MACTOP:      POINTER TO EXPRESSION NUMBER IN MACSPD TABLE */
/* NUMBIT:      CONTAINS NUMBER OF BITS IN A FIXED POINT WORD */
/* MCSPDP:      POINTER TO LAST ENTRY IN MACSPD TABLE */
/* MCSRCH:      AT FINAL MACRO PRECESSING MACDF1 POINTER */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */

/*       24.    MACRO PROCESSING ARRAYS */

/* MACDF1:      STORES MACRO NAME AND ALL MACRO VBL NAMTBL POINTERS */

/*      25A.    TEMPORARY STORAGE DURING FINAL MACRO PROCESSING */


/*       26.    NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */

/* * */
/* PURPOSE      FOR EACH CALL AND NORMAL VALUE INITIALIZATION */
/*              TO GENERATE AND OUTPUT I.L. COMMANDS THAT */
/*              MOVE ASSIGNED VALUE AND BRANCHING LABEL */
/*              ADDRESSES INTO THE APPROPRIATE MACRO */
/*              VARIABLE AND LINKAGE LOCATIONS. */

/* NOTES        1.  COMSTR IS ACCESSED AFTER ALL BRANCHING */
/*                  AND COMMON I.L. TEXT HAS BEEN GENERATED */
/*                  FOR A MACRO. */
/*              2.  FOR EACH ACTUAL BRANCHING SITUATION THE */
/*                  MACSPD TABLE CONTAINS THE FOLLOWING */
/*                  INFORMATION STREAM. */
/*                   M = NUMBER OF WORDS NEEDED FOR CALL */
/*                       QUALITIES. */
/*                   N = NUMBER OF DIFFERENT BRANCHES. */
/*                  1)         NEGATIVE OF BRANCHING EXPRESSION */
/*                             NUMBER. */
/*                  2          CALL QUALITY WORDS.  QUALITIES */
/*                  THRU       SET FOR CALLS ASSOCIATED WITH */
/*                  M+1)       THE FOLLOWING BRANCH LABEL. */
/*                  M+2)       1ST BRANCH LABEL.  NEGATIVE */
/*                             IF ONLY NORMAL VALUES USED. */
/*                  (N-1) (M+2)+2 CALL QUALITY WORDS. */
/*                  THRU N(M+1)) */
/*                  N(M+1)+1)    NTH BRANCH LABEL.  NEGATIVE IF */
/*                               ONLY NORMAL VALUES USED. */

/* ** */
    i__ = name_(i297, (ftnlen)6);
    nametb_1.namtbl[i__ - 1] = j297;
    callzz_(&i__);
    rlslin_();

/* ...     GENERATE RETURN TERMINATOR FOR MACRO COMMON TEXT. */

    retmcx_(&c__1);
    if (*numarg == 0) {
	return 0;
    }

/* ...     INITIALIZE NORMAL VALUE STORAGE. */

    i__1 = *maxsps;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L80: */
	macxx5_1.itmpsv[i__ - 1] = 0;
    }

/* ...     ARGCNT=NUMBER OF MACRO VARIABLES FOR CORRENT MACRO. */

    argcnt = *numarg - 1;

/* ...     ONE ITERATION PER CALL. */

    i__1 = *numcal;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* ...     COMPUTE WORD POSITION (WDCAL) AND QUALITY (BITCAL) ASSOCIATED */
/* ...     WITH THIS CALL. */

	wdcal = (i__ - 1) / *numbit;
	bitcal = i__ - wdcal * *numbit;

/* ...     CALCULATE LABEL  FOR CALL INITIALIZATION. LABEL NAME BASED ON */
/* ...     MACRO NAMTBL POINTER AND CALL NUMBER. */

	i__2 = -i__;
	maclbl_(&macdf1[*mcsrch - 1], &i__2, &j);
	nametb_1.namtbl[j - 1] = label[0];

/* ...     GENERATE LABEL COMMAND. */

/* L20: */
	labelz_(&j);

/* ...     ONE ITERATION PER MACRO VARIABLE. */

/* L30: */
	i__2 = argcnt;
	for (j = 1; j <= i__2; ++j) {
	    ++(*numarg);

/* ...     IF NEGATIVE, ASSIGNED VALUE=NORMAL VALUE. */

	    if ((i__3 = macxx6_1.macspd[*numarg - 1]) < 0) {
		goto L40;
	    } else if (i__3 == 0) {
		goto L1;
	    } else {
		goto L41;
	    }

/* ...     SAVE IN VBLSAV(J) USED NORMAL VALUE ASSIGNED TO JTH MACRO VAR.. */

L40:
	    macxx5_1.itmpsv[j - 1] = -macxx6_1.macspd[*numarg - 1];
	    goto L1;

/* ...     I.L. TO PLACE ADDRESS OF ASSIGNED VALUE IN MACRO VARIABLE WORD. */

L41:
	    asnadz_(&macxx6_1.macspd[j - 1], &macxx6_1.macspd[*numarg - 1]);
L1:
	    ;
	}

/* ...     BEGIN SEARCH IN THE APPROPRIATE SECTION OF THE MACSPD TABLE */
/* ...     (MACCNT) FOR BRANCHING LABELS ASSOCIATED WITH THIS CALL. */

	maccnt = *mcspdp;

/* ...     ARGSCR KEEPS TRACK OF CURRENT BRANCHING SITUATION. */

	argscr = argcnt + 2;
L2:
	++maccnt;

/* ...     BRANCH IF ALL LABELS HAVE BEEN ASSIGNED FOR THIS CALL. */

	if (argscr > *maxsps) {
	    goto L11;
	}
L50:
	k = maccnt + wdcal;
	maccnt = maccnt + *bitwds + 1;

/* ...     FOR CURRENT BRANCHING SITUATION IF BRANCHING LABEL FOR CURRENT */
/* ...     CALL IS FOUND BITMCH=.TRUE.. IF LOOP IS EXHAUSTED WITHOUT */
/* ...     LOCATING LABEL ISSUE DIAGNOSTIC. */

	if (bitmch_(&macxx6_1.macspd[k], &bitcal)) {
	    goto L10;
	}
	if (maccnt < *mactop && macxx6_1.macspd[maccnt] >= 0) {
	    goto L50;
	}

/* ...     1021 - ERROR IN FINAL MACRO PROCESSING */

	alarm_(&c__1021, &c__0, &c__8, "COMSTR  ", (ftnlen)8);
	goto L11;

/* ...     IF CALL BRANCHING LABEL DOES NOT INVOLVE ONLY NORMAL VALUES */
/* ...     THEN BRANCH. */

L10:
	if (macxx6_1.macspd[maccnt - 1] > 0) {
	    goto L6;
	}

/* ...     SAVE BRANCHING LABEL FOR BRANCH INVOLVING ONLY NORMAL VALUES IN */
/* ...     POSITION OF VBLSAV ARRAY CORRESPONDING TO CURRENT BRANCHING */
/* ...     SITUATION. */

	macxx5_1.itmpsv[argscr - 1] = -macxx6_1.macspd[maccnt - 1];
	goto L7;

/* ...     CALCULATE LABEL NAME BASED ON MACRO NEST LEVEL AND NUMBER OF */
/* ...     CURRENT BRANCHING SITUATION. */

L6:
	i__2 = -(*mcsavp);
	i__3 = -argscr;
	maclbl_(&i__2, &i__3, &j);
	nametb_1.namtbl[j - 1] = label[0];
	asnjpz_(&j, &macxx6_1.macspd[maccnt - 1]);

/* ...     I.L. TO PLACE CALL BRANCHING LABEL IN APPROPRIATE LINKAGE CELL */
/* ...     SO THAT CORRECT BRANCH FOR THIS BRANCHING SITUATION IS */
/* ...     SELECTED WHEN EXECUTING MACRO FOR THIS CALL. */

L7:
	++argscr;
L8:
	if (maccnt >= *mactop) {
	    goto L11;
	}
	if (macxx6_1.macspd[maccnt] < 0) {
	    goto L2;
	}

/* ...     LOCATE NEXT BRANCHING SITUATION INFORMATION. */

	maccnt = maccnt + *bitwds + 1;
	goto L8;

/* ...     CALCULATE LABEL NAME OF MACRO COMMON TEXT AND GENERATE A */
/* ...     TRANSFER TO IT AS A CALL INITIALIZATION TERMINATOR. */

L11:
	maclbl_(&c_n1, &macdf1[*mcsrch - 1], &j);
	nametb_1.namtbl[j - 1] = label[0];
	jumpzz_(&j);
/* L200: */
	++(*numarg);
    }

/* ...     GENERATE LABEL FOR NORMAL VALUE INITIALIZATION. */

    labelz_(&macdf1[*mcsrch - 1]);

/* ...     FOR EACH MACRO VARIABLE AND EACH BRANCHING SITUATION USING */
/* ...     NORMAL VALUES (VBLSAV(J).GT.0) ASSIGN NORMAL VALUE AND LABEL */
/* ...     ADDRESSES TO THE CORRESPONDING MACRO VARIABLE AND LINKAGE CELLS */

    i__1 = *maxsps;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (macxx5_1.itmpsv[i__ - 1] == 0) {
	    goto L100;
	}
	if (i__ - argcnt <= 0) {
	    goto L110;
	} else {
	    goto L120;
	}
L110:
	asnadz_(&macxx6_1.macspd[i__ - 1], &macxx5_1.itmpsv[i__ - 1]);
	goto L100;
L120:
	i__2 = -(*mcsavp);
	i__3 = -i__;
	maclbl_(&i__2, &i__3, &j);
	nametb_1.namtbl[j - 1] = 1;
	asnjpz_(&j, &macxx5_1.itmpsv[i__ - 1]);
L100:
	;
    }

/* ...     GENERATE RETURN TERMINATOR FOR NORMAL VALUE INITIALIZATION. */

    retmcx_(&c__2);
    return 0;
} /* comstr_ */

#undef maxsps
#undef numbit
#undef bitwds
#undef numarg
#undef mcsavp
#undef mcspdp
#undef mactop
#undef mcsrch
#undef numcal
#undef macdf1
#undef label


