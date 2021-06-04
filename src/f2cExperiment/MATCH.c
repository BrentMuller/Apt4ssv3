/* MATCH.f -- translated by f2c (version 20100827).
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
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer macxx5[135];
} macxx5_;

#define macxx5_1 macxx5_

struct {
    integer macxx6[1300];
} macxx6_;

#define macxx6_1 macxx6_

struct {
    integer macxx7[182];
} macxx7_;

#define macxx7_1 macxx7_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__32 = 32;
static integer c__8 = 8;
static integer c__26 = 26;
static integer c__0 = 0;
static integer c__20 = 20;
static integer c__31 = 31;
static integer c__2 = 2;
static integer c__1015 = 1015;

/* *** SOURCE FILE : M0006653.V04   *** */


/*              FORTRAN SUBROUTINE MATCH */

/* LINKAGE      SUBROUTINE MATCH */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    LABELZ          SUBROUTINE    INPUT */
/*          INTEGER FCT.  MODE            SUBROUTINE    PRO020 */
/*          SUBROUTINE    MACLBL          SUBROUTINE    PRO026 */
/*          SUBROUTINE    ALARM           SUBROUTINE    RECOG */
/*          SUBROUTINE    RETMCX          SUBROUTINE    REPLAC */
/*          SUBROUTINE    SETBIT */
/*          SUBROUTINE    HELP */

/* Subroutine */ int match_(void)
{
    /* Initialized data */

    static integer lbrch = 0;
    static logical extern__ = FALSE_;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, m, n, k1, m1, kk;
#define mas ((integer *)&macxx7_1 + 50)
#define msp ((integer *)&macxx1_1 + 38)
#define way ((integer *)&macxx1_1 + 25)
#define typ ((integer *)&macxx1_1 + 48)
    extern integer mode_(integer *);
#define road ((integer *)&macxx1_1 + 46)
    extern /* Subroutine */ int help_(void);
#define label ((integer *)&code_1 + 42)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define masdm ((integer *)&macxx1_1 + 54)
#define major ((integer *)&macxx1_1 + 43)
#define ilhlt ((logical *)&macxx1_1 + 13)
#define nestg ((logical *)&macxx1_1 + 44)
#define route ((integer *)&macxx1_1 + 45)
#define entry__ ((logical *)&macxx1_1 + 39)
    extern /* Subroutine */ int maclbl_(integer *, integer *, integer *);
    static integer argarg;
#define implab ((integer *)&code_1 + 44)
#define macspd ((integer *)&macxx6_1)
#define macvar ((integer *)&macxx7_1 + 150)
#define modhlf ((integer *)&moduli_1 + 1)
    extern /* Subroutine */ int labelz_(integer *);
#define maclnt ((integer *)&macxx1_1 + 36)
#define permid ((integer *)&code_1 + 38)
#define majwrd ((integer *)&macxx1_1 + 22)
#define nmline ((integer *)&macxx1_1 + 24)
#define number ((integer *)&code_1 + 26)
#define mactop ((integer *)&macxx1_1 + 41)
#define argstk ((integer *)&stklst_1 + 201)
#define argtop ((integer *)&stklst_1 + 1)
#define bitwds ((integer *)&macxx1_1 + 28)
#define lnsddm ((integer *)&macxx1_1 + 52)
#define mcslnt ((integer *)&macxx1_1 + 37)
#define mvardm ((integer *)&macxx1_1 + 53)
#define mctopp ((integer *)&macxx1_1 + 51)
#define numbit ((integer *)&macxx1_1 + 55)
#define mcspdp ((integer *)&macxx1_1 + 56)
#define lnusdp ((integer *)&macxx1_1 + 50)
#define numarg ((integer *)&macxx1_1 + 60)
#define savmsp ((integer *)&macxx1_1 + 47)
#define whchmn ((integer *)&macxx1_1 + 62)
#define maxsps ((integer *)&macxx1_1 + 20)
#define mcstrt ((integer *)&macxx1_1 + 42)
#define mspddm ((integer *)&macxx1_1 + 64)
#define linusd ((integer *)&macxx7_1)
#define modulo ((integer *)&moduli_1)
#define itmpsv ((integer *)&macxx5_1)
#define ergstk ((integer *)&errpos_1 + 202)
#define mvexst ((integer *)&macxx1_1 + 40)
    static integer nrmval, nrmsav, majsav;
    extern /* Subroutine */ int setbit_(integer *, integer *), retmcx_(
	    integer *);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* ARGTOP:      POINTER TO LAST ARGSTK ENTRY */
/* ARGSTK:      ARGUMENT STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL ' */
/* IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB' */

/*       22.    MACRO PROCESSING VARIABLES */

/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* MAXSPS:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* MAJWRD:      CONTAINS ACTUAL MAJOR WORD */
/* NMLINE:      EQUALS NUMBER OF EXPRESSIONS THAT REQUIRE BRANCHING I.L. */
/* WAY:         INDICATES TYPE OF MACRO PROCESSING */
/* BITWDS:      NUMBER OF WORDS NEEDED FOR ALL CALL QUALITIES OF MACRO */
/* MACLNT:      TEMPORARY STORAGE FOR MCSLNT */
/* MCSLNT:      NUMBER OF MACRO VBLS IN ARGSTK FOR CURRENT EXPRESSION */
/* MSP:         POINTER TO THE LAST ENTRY IN MAS ARRAY */
/* ENTRY:       FALSE ON FIRST ENTRY TO MATCH FOR A MACRO EXPRESSION */
/* MVEXST:      POSITION NUMBER OF MACRO VARIABLE, 0=NO MACRO VARIABLE */
/* MACTOP:      POINTER TO EXPRESSION NUMBER IN MACSPD TABLE */
/* MCSTRT:      INDEX IN MACSPD OF CURRENT CALL BEING EXAMINED */
/* MAJOR:       CURRENT CALL ASSIGNED VALUE IF MAYWRD IS MACRO VARIABLE */
/* NESTG:       TRUE WHEN A NESTED GEOMETRIC EXPRESSION ENCOUNTERED */
/* ROUTE:       CLASS CODE OF A MAJOR WORD DURING MACRO PROCESSING */
/* ROAD:        CLASS CODE OF A MAJOR WORD DURING MACRO PROCESSING */
/* SAVMSP:      USED TO SAVE A POINTER TO THE MAS ARRAY */
/* TYP:         1 WHEN AN INVALID PATTERN FOR CURRENT EXPRESSION APPEARS */
/* LNUSDP:      INDEX OF LAST LINUSD ENTRY */
/* MCTOPP:      TEMPORARY STORAGE IN MATCH FOR MACTOP VALUE */
/* LNSDDM:      DIMENSION OF LINUSD */
/* MVARDM:      CONTAINS DIMENSION OF THE ARRAY MACVAR */
/* MASDM:       CONTAINS DIMENSION OF ARRAY MAS */
/* NUMBIT:      CONTAINS NUMBER OF BITS IN A FIXED POINT WORD */
/* MCSPDP:      POINTER TO LAST ENTRY IN MACSPD TABLE */
/* NUMARG:      NUMBER OF MACRO VARIABLES+1 FOR CURRENT MACRO */
/* WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED */
/* MSPDDM:      CONTAINS DIMENSION OF THE ARRAY MACSPD */

/*      25A.    MACRO PROCESSING ARRAYS */

/* ITMPSV:      TEMPORARY STORAGE DURING FINAL MACRO PROCESSING */

/*       26.    MACRO PROCESSING ARRAYS */

/* MACSPD:      NAMTBL POINTERS OF THE ASSIGNED VALUES FOR MACRO CALL */

/*      26A.    MACRO PROCESSING ARRAYS */

/* LINUSD:      NUMBERS OF EXPRESSIONS REQUIRING BRANCHING FOR MACROS */
/* MAS:         NAMTBL POINTERS OR ASSIGNED VALUES OF MACRO VBL MAJOR W. */
/* MACVAR:      POSITION NUMBER OF EACH UNIQUE MACRO VARIABLE */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       44.    ERROR POSITION TABLE */

/* ERGSTK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN ARGSTK */
/* * */
/* PURPOSE      TO DETERMINE WHICH EXPRESSIONS IN AN APT MACRO */
/*              REQUIRE BRANCHING */

/* NOTES        1.  MATCH IS ACCESSED DURING THE FIRST PASS OF */
/*                  FINAL MACRO PROCESSING */
/*              2.  FOR EACH CALL A 'STATE' BASED UPON THE KIND */
/*                  OF EXPRESSION ENCONTERED IS CALCULATED FOR */
/*                  EACH INVOLVED MACRO VARIABLE.  EVERY TIME */
/*                  THE CURRENT CALL STRING OF 'STATES' DIFFERS */
/*                  IN AT LEAST ONE POSITION FROM ALL OTHER */
/*                  PREVIOUS STRINGS, A NEW BRANCH IS INITIATED */
/*                  AND THE STRING OF 'STATES' IS STORED IN THE */
/* ** */
    if (*numarg == 0) {
	goto L7;
    }

/* ...     ENTRY=.TRUE. IF MATCH IS BEING ENTERED AGAIN FOR SAME */
/* ...     PRODUCTION INDICATING A BRANCHING SITUATION EXISTS. */

    if (*entry__) {
	goto L99;
    }

/* ...     NMLINE=NUMBER OF CURRENT (POTENTIAL) BRANCHING EXPRESSION. */

    ++(*nmline);
    k1 = *numarg;
    m1 = 0;
    argarg = *argtop;
    i__1 = *numarg;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L1: */
	itmpsv[i__ + 98] = 0;
    }

/* ...     MCSLNT=NUMBER OF UNIQUE MACRO VARIABLES IN ARGSTK. */

    *mcslnt = 0;

/* ...     MVEXST=POSITION NUMBER IF APT MAJOR WORD A MACRO VARIABLE. */
/* ...     NORMALLY=0. */

    *mvexst = 0;

/* ...     IF FUNCTION,NO BRANCHING REQUIRED FOR MACRO VARIABLE ARGUMENTS. */

    if (*argtop == 0 || *way == 3) {
	goto L3;
    }
    i__1 = *argtop;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* ...     SAVE CONTENTS OF ARGSTK IN ITMPSV(1) THRU ITMPSV(99) */

	itmpsv[i__ - 1] = argstk[i__ - 1];

/* ...     SCAN ARGSTK AND PLACE THE POSITION NUMBER OF EACH UNIQUE MACRO */
/* ...     VARIABLE FOUND IN THE FIRST FREE POSITION OF MACVAR ARRAY. */

	i__2 = *numarg;
	for (j = 2; j <= i__2; ++j) {
	    if (macspd[j - 2] != argstk[i__ - 1]) {
		goto L2;
	    }
	    if (itmpsv[j + 98] != 0) {
		goto L2;
	    }
	    ++(*mcslnt);
	    if (*mcslnt <= *mvardm) {
		goto L17;
	    }
L18:
	    i__3 = -i__;
	    alarm_(&c__32, &i__3, &c__8, "MATCH   ", (ftnlen)8);
	    help_();
L17:
	    macvar[*mcslnt - 1] = j - 1;
	    itmpsv[j + 98] = 1;
L2:
	    ;
	}
    }
L3:
    *maclnt = *mcslnt;

/* ...     CALL EXPRESSIONS REQUIRE NO MAJOR WORD ANALYSIS. */

    if (*way == 5) {
	goto L6;
    }

/* ...     ROUTE=CLASS CODE OF MAJOR WORD. */
/* ...     ROAD=MODE CODE OF MAJOR WORD. */

    *route = *modulo * (nametb_1.namtbl[*majwrd - 1] / *modulo);
    *road = nametb_1.namtbl[*majwrd - 1] - *route;
    i__2 = *numarg;
    for (i__ = 2; i__ <= i__2; ++i__) {
	if (macspd[i__ - 2] == *majwrd) {
	    goto L5;
	}
/* L4: */
    }
    goto L6;

/* ...     STORE POSITION NUMBER OF MACRO VARIABLE MAJOR WORD IN BOTH */
/* ...     MVEXST AND FIRST FREE CELL OF MACVAR ARRAY. */

L5:
    *mvexst = i__ - 1;

/* ...     IF GEOMETRIC EXPRESSION HAS MACRO VARIABLE MAJOR WORD, THEN */
/* ...     ISSUE DIAGNOSTIC. */

    if (*nestg) {
	goto L62;
    }
    i__ = 100;
    if (*mcslnt >= *mvardm) {
	goto L18;
    }
    macvar[*mcslnt] = *mvexst;
    *maclnt = *mcslnt + 1;

/* ...     RETURN IF NO MACRO VARIABLES INVOLVED IN EXPRESSION. */

L6:
    if (*maclnt != 0) {
	goto L8;
    }
L7:
    return 0;

/* ...     EACH CALL IS EXAMINED AND COMPARED TO THE ONES PRECEDING IT TO */
/* ...     DETERMINE WHEN AND IF CODE FOR A NEW BRANCH IS REQUIRED. */
/* ...     MCSTRT POINTS TO CURRENT CALL ASSIGNED VALUES IN MACSPD TABLE. */
/* ...     MSP POINTS TO LAST ENTRY IN MAS TABLE. */

L8:
    *mcstrt = 0;
    *msp = 0;
L9:
    *mcstrt += *numarg;

/* ...     IF CALLS REMAIN TO BE PROCESSED, THEN BRANCH. */

    if (*mcstrt < *mcspdp) {
	goto L10;
    }

/* ...     RESET CONTROL PARAMETERS FOR FINAL EXIT FOR THIS EXPRESSION. */

    l = *numarg;
    *ilhlt = TRUE_;
    *entry__ = FALSE_;
    m1 = 1;
    goto L60;
L10:
    *typ = 0;
    nrmval = -1;
    *savmsp = *msp + 1;
    *argtop = argarg;

/* ...     MAJOR=CURRENT CALL ASSIGNED VALUE (MACSPD(I)) IF MAJOR WORD IS */
/* ...     A MACRO VARIABLE. OTHERWISE MAJOR=MAJOR WORD (MAJWRD). */

    *major = *majwrd;
    if (*mvexst == 0) {
	goto L13;
    }
/* L11: */
    i__ = *mvexst + *mcstrt;
    *major = (i__2 = macspd[i__ - 1], abs(i__2));

/* ...     FOR EACH CALL A MACRO VARIABLE MAJOR WORD HAS EITHER ITS */
/* ...     ASSIGNED VALUE MODE OR NAMTBL POINTER STORED IN MAS ARRAY */
/* ...     DEPENDING UPON EXPRESSION TYPE. */

    switch (*way) {
	case 1:  goto L101;
	case 2:  goto L202;
	case 3:  goto L202;
	case 4:  goto L102;
    }
L101:
    mas[*msp] = *major;
    goto L12;
L202:
    mas[*msp] = nametb_1.namtbl[*major - 1] - *route;
    if (*entry__) {
	goto L20;
    }
    extern__ = TRUE_;
    m1 = 1;
    goto L20;
L102:
    mas[*msp] = nametb_1.namtbl[*major - 1] - *route;
    if (*way == 4) {
	goto L12;
    }

/* ...     IF A POSTPROCESSOR OR GOLFT,GORGT,GOUP,GODOWN,GOFWD,GOBACK */
/* ...     PROCEDURE IS ENCOUNTERED, BRANCHING ON MAJOR WORD UNNECESSARY. */

L20:
    if (mas[*msp] == 0 || mas[*msp] == 34) {
	*major = *majwrd;
    }
L12:
    *road = mas[*msp];
    ++(*msp);
    if (*msp < *masdm) {
	goto L13;
    }
L16:
    alarm_(&c__26, &c__0, &c__8, "MATCH   ", (ftnlen)8);
    help_();

/* ...     IF NO ELEMENTS OF ARGSTK ARE MACRO VARIABLES, THEN BRANCH. */

L13:
    if (*argtop == 0 || *way == 3) {
	goto L51;
    }

/* ...     RESTORE CONTENTS OF ARGSTK WHICH MIGHT HAVE BEEN ALTERED IN */
/* ...     GENERATING BRANCHING CODE FOR PRIOR CALLS. */

    i__2 = *argtop;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L14: */
	argstk[i__ - 1] = itmpsv[i__ - 1];
    }
    if (*mcslnt == 0) {
	goto L51;
    }

/* ...     ESTABLISH 'STATE' OF EACH INVOLVED MACRO VARIABLE FOR THIS CALL */

    i__2 = *mcslnt;
    for (i__ = 1; i__ <= i__2; ++i__) {
	j = macvar[i__ - 1] + *mcstrt;

/* ...     PICK UP ASSIGNED VALUE POINTER. */

	k = (i__1 = macspd[j - 1], abs(i__1));

/* ...     NRMVAL=1 IF AT LEAST ONE NON-NORMAL VALUE USED. */

	if (macspd[j - 1] >= 0) {
	    nrmval = 1;
	}

/* ...     ASSIGN INITIAL 'STATE' OF MACRO VARIABLE. */

	mas[*msp] = mode_(&k);

/* ...     M=CLASS OF ASSIGNED VALUE. */

	if (k <= nametb_1.nammax) {
	    goto L1100;
	}
	m = number[0];
	goto L1110;
L1100:
	m = *modulo * (nametb_1.namtbl[k - 1] / *modulo);
	l = nametb_1.namtbl[k - 1] - m;

/* ...     WAY=1 FOR GEOM, WAY=2 FOR PROC, WAY=3 FOR FUNC, WAY=4 FOR REPL, */
/* ...     WAY=5 FOR CALL. */

L1110:
	switch (*way) {
	    case 1:  goto L41;
	    case 2:  goto L15;
	    case 3:  goto L50;
	    case 4:  goto L71;
	    case 5:  goto L43;
	}
L71:
	if (mas[*msp] == 0) {
	    goto L22;
	}
	if (mas[*msp] == *road) {
	    goto L50;
	}
	goto L22;
L15:
	if (*road == 0) {
	    goto L50;
	}
	if (*road < 22) {
	    goto L22;
	}
	if ((i__1 = *road - 41) < 0) {
	    goto L26;
	} else if (i__1 == 0) {
	    goto L25;
	} else {
	    goto L22;
	}
L26:
	if ((i__1 = *road - 24) < 0) {
	    goto L24;
	} else if (i__1 == 0) {
	    goto L21;
	} else {
	    goto L44;
	}
L21:
	if (m != label[0] && m != implab[0]) {
	    goto L22;
	}
/* L23: */
	if (l != *whchmn) {
	    goto L22;
	}
	mas[*msp] = 200;
	goto L50;
L25:
	if (mas[*msp] == 0 || mas[*msp] > 17) {
	    goto L22;
	}
/* L38: */
	mas[*msp] = 50;
	goto L50;
L24:
	if (*road == 23) {
	    goto L47;
	}
	if (mas[*msp] != 21) {
	    goto L22;
	}
	goto L50;
L47:
	if (mas[*msp] != 2) {
	    goto L22;
	}
	goto L50;
L44:
	if (mas[*msp] == 21) {
	    goto L50;
	}
	if ((i__1 = *road - 34) < 0) {
	    goto L27;
	} else if (i__1 == 0) {
	    goto L29;
	} else {
	    goto L30;
	}
L27:
	if (*road == 25) {
	    goto L36;
	}

/* ...     INVALID 'STATE'. A SINGLE BRANCH FOR ALL SUCH CALLS. */

L22:
	*typ = 1;
	goto L50;
L36:
	if (m != permid[0]) {
	    goto L25;
	}
	goto L42;
L29:
	if (mas[*msp] != 0) {
	    goto L25;
	}
	if (m != permid[0]) {
	    goto L21;
	}
	if (l == 5) {
	    l = 3;
	}
	goto L42;
L30:
	if ((i__1 = *road - 37) < 0) {
	    goto L31;
	} else if (i__1 == 0) {
	    goto L33;
	} else {
	    goto L32;
	}
L31:
	if (mas[*msp] == 19) {
	    goto L50;
	}
	goto L22;
L32:
	if ((i__1 = *road - 39) < 0) {
	    goto L33;
	} else if (i__1 == 0) {
	    goto L46;
	} else {
	    goto L39;
	}
L33:
	if (mas[*msp] == 20) {
	    goto L50;
	}
	goto L46;
L39:
	if (mas[*msp] == 19) {
	    goto L50;
	}
	goto L46;
L41:
	if (mas[*msp] != 0) {
	    goto L50;
	}
L46:
	if (m != permid[0]) {
	    goto L22;
	}
L42:
	if (l == 0) {
	    goto L22;
	}
	mas[*msp] = l + 100;
	goto L50;
L43:
	mas[*msp] = k;
L50:
	++(*msp);
    }
    if (*msp >= *masdm) {
	goto L16;
    }

/* ...     BRANCH IF NO INVALID 'STATES' ENCOUNTERED. */

    if (*typ == 0) {
	goto L51;
    }

/* ...     SET ALL 'STATES' = 0 FOR THIS CALL. */

/* L61: */
    i__2 = *msp;
    for (i__ = *savmsp; i__ <= i__2; ++i__) {
/* L45: */
	mas[i__ - 1] = 0;
    }
L51:
    j = macvar[*maclnt - 1] + *mcstrt;
    if (macspd[j - 1] >= 0) {
	nrmval = 1;
    }
    if (*msp != *maclnt) {
	goto L98;
    }

/* ...     THIS PATH FOLLOWED FOR 1ST CALL SINCE NO COMPARISON CAN YET BE */
/* ...     MADE TO DETERMINE IF BRANCHING IS NECESSARY. */

    nrmsav = nrmval;
    majsav = *major;
    if (! extern__) {
	goto L9;
    }
    extern__ = FALSE_;
    goto L105;
L98:
    k1 += *numarg;
    l = *msp - *maclnt;
    k = l + 1;

/* ...     COMPARE 'STATES' FOR THIS CALL WITH 'STATES' FOR EACH CALL THAT */
/* ...     INITIATED A NEW BRANCH. UPON COMPLETION OF A CALL COMPARISON */
/* ...     M1=0 IF SAME AS SOME PREVIOUS CALL. OTHERWISE BRANCH (M1=1). */

    i__2 = l;
    i__1 = *maclnt;
    for (i__ = 1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
	m1 = 0;
	i__3 = *msp;
	for (j = k; j <= i__3; ++j) {
	    n = i__ + j - k;
/* L52: */
	    if (mas[j - 1] != mas[n - 1]) {
		m1 = 1;
	    }
	}
	if (m1 == 0) {
	    goto L59;
	}
/* L53: */
    }

/* ...     ENTRY=.FALSE. IF 1ST BRANCH ENCOUNTERED FOR THIS EXPRESSION. */

    if (*entry__) {
	goto L56;
    }

/* ...     MAXSPS KEEPS TRACK OF NUMBER OF ACTUAL BRANCHING EXPRESSIONS IN */
/* ...     MACRO. */

L105:
    ++(*maxsps);

/* ...     EVERY POTENTIAL BRANCHING SITUATION HAS A NUMBER ASSOCIATED */
/* ...     WITH IT (NMLINE INCREMENTED EACH TIME). THOSE ACTUAL BRANCHING */
/* ...     EXPRESSIONS HAVE CURRENT VALUE OF NMLINE STORED IN LINUSD ARRAY */

    ++(*lnusdp);
    if (*lnusdp <= *lnsddm) {
	goto L54;
    }
    alarm_(&c__20, &c__0, &c__8, "MATCH   ", (ftnlen)8);
    help_();
L54:
    linusd[*lnusdp - 1] = *nmline;

/* ...     NEGATIVE OF BRANCHING EXPRESSION NUMBER STORED IN MACSPD TABLE. */

    macspd[*mactop] = -(*nmline);
    *ilhlt = FALSE_;
    nrmval = nrmsav;
    *major = majsav;
    k1 = *numarg << 1;
    *mcstrt = *numarg;
    *msp = *maclnt;
    if (*msp >= *masdm) {
	goto L16;
    }
    *entry__ = TRUE_;
    ++(*mactop);

/* ...     MCTOPP IS POINTER TO EXPRESSION NUMBER IN MACSPD TABLE. */

    *mctopp = *mactop;
    if (*mactop < *mspddm) {
	goto L56;
    }
L55:
    alarm_(&c__31, &c__0, &c__8, "MATCH   ", (ftnlen)8);
    help_();
L56:
    ++lbrch;
    i__1 = -lbrch;
    maclbl_(&c__2, &i__1, &n);
    nametb_1.namtbl[n - 1] = label[0];

/* ...     GENERATE BRANCH LABEL COMMAND. */

    labelz_(&n);
    m = *mactop;
    *mactop = *mactop + *bitwds + 1;
    if (*mactop >= *mspddm) {
	goto L55;
    }

/* ...     STORE THE LATEST BRANCH LABEL IN THE BRANCHING HISTORY PORTION */
/* ...     OF THE MACSPD TABLE. IF THIS BRANCH ONLY EMPLOYS NORMAL VALUES */
/*        (NRMVAL=-1), THEN STORE THE NEGATIVE OF THE LABEL POINTER. */

    macspd[*mactop - 1] = nrmval * n;
L57:
    j = (macspd[k1 - 1] - 1) / *numbit;
    n = macspd[k1 - 1] - *numbit * j;
    k = m + j + 1;

/* ...     SET THE NTH CALL QUALITY FOR THE APPROPRIATE BRANCH. */

    setbit_(&macspd[k - 1], &n);
    l = *mcstrt;

/* ...     UPDATE THE CLASS AND MODE FOR EACH MACRO VARIABLE TO CORRESPOND */
/* ...     TO THE ASSIGNED VALUES FOR THE CURRENT CALL. */

L60:
    i__1 = *numarg;
    for (i__ = 2; i__ <= i__1; ++i__) {
	j = macspd[i__ - 2];
	k = (i__2 = macspd[l], abs(i__2));
	nametb_1.namtbl[j - 1] = number[0] + *modhlf;
	if (k > nametb_1.nammax) {
	    goto L58;
	}
	kk = nametb_1.namtbl[k - 1];
	if (kk - *modulo * (kk / *modulo) < *modhlf) {
	    kk += *modhlf;
	}
	nametb_1.namtbl[j - 1] = kk;
L58:
	++l;
    }
    if (m1 == 0) {
	goto L9;
    }
    goto L7;
L59:
    *msp -= *maclnt;
    if (! (*entry__)) {
	goto L9;
    }

/* ...     COMPUTE POSITION IN MACSPD TABLE FOR BRANCH ASSOCIATED WITH */
/* ...     THIS CALL. */

    m = *mctopp + (i__ - 1) / *maclnt * (*bitwds + 1);
    goto L57;

/* ...     GENERATE RETURN TERMINATOR FOR BRANCH CODE. */

L99:
    retmcx_(&c__2);
    goto L9;

/* ...     1015 - SURFACE TYPE CHANGED IN NESTED GEOMETRIC DEFINITION */

L62:
    alarm_(&c__1015, &ergstk[99], &c__8, "MATCH   ", (ftnlen)8);
    goto L7;
} /* match_ */

#undef mvexst
#undef ergstk
#undef itmpsv
#undef modulo
#undef linusd
#undef mspddm
#undef mcstrt
#undef maxsps
#undef whchmn
#undef savmsp
#undef numarg
#undef lnusdp
#undef mcspdp
#undef numbit
#undef mctopp
#undef mvardm
#undef mcslnt
#undef lnsddm
#undef bitwds
#undef argtop
#undef argstk
#undef mactop
#undef number
#undef nmline
#undef majwrd
#undef permid
#undef maclnt
#undef modhlf
#undef macvar
#undef macspd
#undef implab
#undef entry__
#undef route
#undef nestg
#undef ilhlt
#undef major
#undef masdm
#undef label
#undef road
#undef typ
#undef way
#undef msp
#undef mas


