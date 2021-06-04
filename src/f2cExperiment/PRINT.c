/* PRINT.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    doublereal ctang, bmin, bmax, dmax__;
    logical latyp1, lanps, avlist;
} avcprm_;

#define avcprm_1 avcprm_

/* Table of constant values */

static integer c__5 = 5;
static integer c__55 = 55;
static integer c__1 = 1;
static integer c__16 = 16;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__12 = 12;
static integer c__19 = 19;
static integer c__25 = 25;
static integer c__30 = 30;
static integer c__13 = 13;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c__18 = 18;
static integer c__28 = 28;
static integer c__66 = 66;

/* *** SOURCE FILE : M0001206.W02   *** */



/* .....FORTRAN SUBROUTINE           PRINT */

/*     NEW REORGANIZED VERSION  OCT-1988 E.MCLELLAN */

/* PURPOSE          TO EJECT A PAGE,TAKE A DUMP,TURN THE PRINT FLAG */
/*                  INTERROGATED BY DEFEXT ON OR OFF,OR PRINT TITLES, */
/*                  NUMBER IDENTIFIERS OR A SPECIFIED NUMBER OF CANONICAL */
/*                  FORMS. */

/* CALLING SEQUENCE CALL PRINT(CODE,ARRAY,NUMBER) */

/* ARGUMENTS        CODE             =1,TO PRINT BLOCK 1 SCALARS WITH A */
/*                                      DESCRIPTIVE HEADER */
/*                                   =2,TO PRINT BLOCK 2 SCALARS WITH A */
/*                                      DESCRIPTIVE HEADER */
/*                                   =3,TO PRINT BLOCK 3 CANONICAL FORMS */
/*                                      WITH A DESCRIPTIVE HEADER */
/*                                   =4,TO PRINT BLOCK 1 SCALARS WITH NO */
/*                                      HEADER */
/*                                   =5,TO PRINT BLOCK 2 SCALARS WITH NO */
/*                                      HEADER */
/*                                   =6,TO PRINT BLOCK 3 CANONICAL FORMS */
/*                                      WITH NO HEADER */
/*                                   =7,TO EJECT A PAGE */
/*                                   =8,TO TAKE A DUMP */
/*                                   =9,TO PRINT A TITLE */
/*                                   =10, TO PRINT A NUMBER IDENTIFIER */
/*                                       (I.E. HANDLES PRINT/2,NUMBER) */
/*                                   =11,TO TURN PRINT FLAG ON */
/*                                   =12,TO TURN PRINT FLAG OFF */
/*                                   =13, TO TURN PCHLST FLAG ON */
/*                                   =14, TO TURN PCHLST FLAG OFF */
/*                                   =15, TO PRINT NAME ON TABCYL LISTING */
/*                                   =16, FOR TABCYL PRINT ON */
/*                                   =17, FOR TABCYL PRINT OFF */
/*                                   =18/19 FOR SS-PRINT ON/OFF */
/*                                   =20/21 FOR SS-TEST-PRINT ON/OFF */
/*                                   =22/23 FOR AVOIDANCE ACTION PRINT */
/*                                          (AVPRT) ON/OFF */
/*                  ARRAY            IF PRINTING IS TO TAKE PLACE,ARRAY */
/*                                   CONTAINS THE TITLE,NUMBER,OR FIRST */
/*                                   CANONICAL FORM TO BE PRINTED. */
/*                                   OTHERWISE ARRAY IS A DUMMY ARGUMENT. */
/*                  NUMBER           IF CANONICAL FORMS ARE TO BE PRINTED */
/*                                   NUMBER CONTAINS THE NUMBER OF FORMS */
/*                                   TO PRINT. */

/* CALLED BY        DEFEXT,APT040,APT045,APT102,APT103,APT089 */

/* SUBSIDIARIES     TYPE             ENTRY */
/*                  ----             ----- */
/*                  INTEGER FUNCTION ADDRSS */
/*                  SUBROUTINE       INCAN */
/*                  SUBROUTINE       RECORD */
/*                  SUBROUTINE       TRANSF */
/*                  SUBROUTINE       UNPACK */
/*                  INTEGER FUNCTION XCANON */
/*                  INTEGER FUNCTION BCDF */
/*                  SUBROUTINE       HOLFRM */

/* RESTRICTIONS     CANONICAL FORMS TO BE PRINTED MUST BE CONTIGUOUS */

/* DIAGNOSTICS      ERROR CODE       COMMENT */
/*                  ----------       ------- */
/*                   NONE            INVALID CANONICAL FORM ENCOUNTERED. */
/*                                   PRINTING SUPPRESSED */

/* METHOD           AN 'IF THEN ELSE' STRUCTURE IS USED TO DIRECT */
/*                  PROCESSING ACCORDING TO CODE. */
/*                  NOTE THAT BECAUSE THERE IS MUCH COMMON PROCESSING */
/*                  FOR CODE=1,2,3,4,5,6 AND 15, THESE ARE PROCESSED */
/*                  IN THE FIRST BLOCK OF THE STRUCTURE WITH ADDITIONAL */
/*                  'IF THEN ELSE' STRUCTURES TO DIRECT SUBSEQUENT */
/*                  PROCESSING ACCORDING TO THE INDIVIDUAL CODES */

/* Subroutine */ int print_(integer *code, doublereal *array, integer *number)
{
    /* Initialized data */

    static char modhs[4*2] = "  IN" " OUT";
    static char z__[1] = "Z";
    static char star[1] = "*";
    static char blk[1] = " ";
    static char lparen[1] = "(";
    static char dollar[1] = "$";
    static char right[5] = "RIGHT";
    static char rparen[1] = ")";
    static char type__[6*30] = "LINE  " "PLANE " "CYLNDR" "CIRCLE" "SPHERE" 
	    "HYPERB" "LCONIC" "ELLIPS" "CONE  " "GCONIC" "TABCYL" "RLDSRF" 
	    "PCONIC" "QADRIC" "PARSRF" "**16**" "**17**" "MATRIX" "POINT " 
	    "VECTOR" "SCALAR" "**22**" "**23**" "**24**" "STRING" "PATERN" 
	    "BOUNDS" "OBJECT" "SSURF " "SCURV ";
    static char f13[18] = "TABULATED CYLINDER";
    static char f30[19] = "INCORRECTLY DEFINED";
    static char f40[55] = "INVALID CANONICAL FORM ENCOUNTERED. PRINTING SUPP"
	    "RESSED";
    static integer kright = 0;
    static integer ku = 10000;
    static integer kv = 10;
    static struct {
	char e_1[8];
	} equiv_10 = { "0000000)" };


    /* System generated locals */
    integer i__1, i__2, i__3;
    static doublereal equiv_5[1], equiv_6[17], equiv_7[16], equiv_8[2], 
	    equiv_9[1];
    static char equiv_12[16], equiv_13[4];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define a (equiv_6)
#define c__ (equiv_5)
    static doublereal d__;
    static integer i__, j, k, l, n;
#define x ((doublereal *)&_BLNK__1)
#define ia ((integer *)equiv_6)
    static integer ic, ii, jj, ik, mm, ir;
#define no (equiv_13)
    static integer iu, iw, bcd;
#define can ((doublereal *)&_BLNK__1 + 40)
#define nam (equiv_12)
    static integer iph, nwd, sub;
#define stg ((char *)&equiv_10)
    extern integer bcdf_(char *, ftnlen);
#define cnam (equiv_12)
    static integer iabs;
#define name__ (equiv_8)
#define inam ((integer *)equiv_8)
    static integer mode;
#define numb (equiv_13 + 3)
#define cnum (equiv_13)
    static integer iseq, isub;
#define temp (equiv_9)
    static integer size, iuvw;
    static char check[8];
    extern /* Subroutine */ int incan_(integer *);
#define canon ((doublereal *)&_BLNK__1)
#define stage ((char *)&equiv_10)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern logical ckdtr_(doublereal *);
    static integer index;
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
#define itemp ((integer *)equiv_9)
#define iskip ((integer *)equiv_5)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen);
    extern logical ckstr_(doublereal *);
    static integer count;
    extern /* Subroutine */ int badnam_(doublereal *);
    static logical ldaflg, bndflg;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static logical namflg;
    extern integer addrss_(doublereal *);
#define refsrf (equiv_7)
    extern integer xcanon_(integer *);
#define irfsrf ((integer *)equiv_7)
    static integer namept;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), cprint_(char *, ftnlen);
    static doublereal savnam;
    extern /* Subroutine */ int holfrm_(), dnonam_(doublereal *);
    static integer iseqno;
    extern /* Subroutine */ int record_(integer *), transf_(doublereal *, 
	    doublereal *, integer *, integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */







/* ...  LOCAL VARIABLES */

/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





/*       AVOIDANCE CONTROL PARAMETERS */



/*     CTANG    CONSTANT TECHNOLOGICAL ANGLE */
/*     BMIN     MINIMUM PITCH ANGLE */
/*     BMAX     MAXIMUM PITCH ANGLE */
/*     DMAX     MAXIMUM LINEAR LIFT OFF */
/*     LATYP1   FLAG INDICATING IF TYPE1 (TILT) AVOIDANCE REQUIRED */
/*     LANPS    FLAG INDICATING TYPE OF LINEAR LIFT OFF */
/*              .TRUE.  - LIFT OFF NORMAL TO PS */
/*              .FALSE. - LIFT OFF PARALLEL TO TOOL AXIS */
/*     AVLIST   FLAG INDICATING THAT AVOIDANCE DETAILS ARE TO BE PRINTED */





    /* Parameter adjustments */
    --array;

    /* Function Body */


/* ******************************************************************** */


/* ...      P R O C E S S   A C C O R D I N G   T O   C O D E */

    if (*code <= 6 || *code == 15) {
	namflg = FALSE_;
	iph = 1;
	mode = 21;
	jj = 0;
	size = 1;
	bndflg = FALSE_;
	ldaflg = FALSE_;

/* ... DETERMINE VIRTUAL INDEX OF ARRAY(1) IN X-ARRAY. */

	index = (addrss_(&array[1]) - addrss_(x)) / idef_1.kwrdsz + 1;
	iabs = index;
	if (ldef_1.canflg) {
	    incan_(&index);
	}

/* ... PROCESS ACCORDING TO TYPE */

	ic = *code % 3;
	if (ic == 0) {
/* .... CODE = 3,6 OR 15 */
	    jj = 1;
	} else if (ic == 1) {
/* .... CODE = 1 OR 4 */
	    sub = 0;
	} else {
/* .... CODE = 2 OR 5 */
	}

/* .... FOR EACH CANONICAL FORM REQUIRED */

	i__1 = *number;
	for (ii = 1; ii <= i__1; ++ii) {

/* ... DETERMINE ABSOLUTE INDEX. */

L60000:
	    *c__ = x[iabs - jj - 1];
	    if (*iskip > 0 && *iskip <= 1024) {
		index += *iskip;
		iabs = index;
		if (ldef_1.canflg) {
		    iabs = xcanon_(&index);
		}
		goto L60000;
	    }

	    if (ic == 1) {

/* ...  P R I N T   B L O C K   1   S C A L A R S */

		namept = iabs + 1;
		goto L50000;

	    } else if (ic == 2) {

/* ...  P R I N T   B L O C K   2   S C A L A R S */

		sub = (integer) x[iabs];

	    } else {

/* ...  P R I N T   B L O C K   3   S U R F A C E S */


/* ... GET SIZE,MODE,AND SUBSCRIPT OF NEXT FORM */

		unpack_(&x[iabs - 1], &mode, &size, &sub);
		if (mode == 27 || mode == 28) {
		    bndflg = TRUE_;
		}
		if (mode > 0 && mode < 31 && size > 0 && (size < 13 || bndflg)
			) {

/* ... IF FORM IS A LARGE DATA ARRAY, TURN ON LDAFLG */

		    if (mode == 11 || mode == 12 || mode == 26 || mode == 29 
			    || mode == 30) {
			ldaflg = TRUE_;
		    }
		} else {
		    cform_(f40, darray_1.darray, &c__5, &c__55, (ftnlen)55, (
			    ftnlen)120);
		    cprint_(darray_1.darray, (ftnlen)120);
		    goto L99999;
		}
	    }

/* ... FIND ALPHANUMERIC NAME. */

	    if (sub < 0 || sub > 9999) {
		cform_(f40, darray_1.darray, &c__5, &c__55, (ftnlen)55, (
			ftnlen)120);
		cprint_(darray_1.darray, (ftnlen)120);
		goto L99999;
	    } else if (sub > 1) {

/* ... DETERMINE ABSOLUTE LOCATION OF FORM NAME. */

		if (! namflg) {
		    namflg = TRUE_;
		    namept = iabs + size + 1 - jj;
		    ik = index + size + 1 - jj;
		    i__2 = sub;
		    for (mm = 2; mm <= i__2; ++mm) {
L60102:
			*c__ = x[namept - 1];
			if (*iskip <= 0 || *iskip > 1024) {
			    namept = namept + size + 1;
			    ik = ik + size + 1;
			} else {
			    ik += *iskip;
			    namept = ik;
			    if (ldef_1.canflg) {
				namept = xcanon_(&ik);
			    }
			    goto L60102;
			}
/* L60110: */
		    }

		    if (ldef_1.canflg) {
			iabs = xcanon_(&index);
		    }
		    savnam = x[namept - 1];
		}

		name__[0] = savnam;
		goto L50002;
	    } else {
		namflg = FALSE_;
		namept = iabs + size + 1 - jj;
	    }

/* ...  U T I L I T Y   P R I N T   M O D U L E */


/* ... SET NAME(1) = CURRENT CANONICAL FORM NAME */
/*     AND, IF LDA, SET SIZE = SIZE OF EXTERNAL CANONICAL FORM. */

L50000:
	    name__[0] = x[namept - 1];
L50002:
	    if (ldaflg) {
		size = (integer) x[iabs];
	    }
	    inam[2] = bcdf_("    ", (ftnlen)4);
	    inam[3] = inam[2];

/* ...  IF FORM NAME BEGINS WITH $ OR Z$, SUPPRESS PRINTING IT */

	    holfrm_(inam, cnam, &c__1, &c__16, &nwd, (ftnlen)16);
	    if (*(unsigned char *)&nam[0] == *(unsigned char *)&dollar[0] || *
		    (unsigned char *)&nam[0] == *(unsigned char *)&z__[0] && *
		    (unsigned char *)&nam[1] == *(unsigned char *)&dollar[0]) 
		    {

/* ... PRINT UNASSIGNED NESTED ELEMENTS FOR PRINT/ON. */

		if (*number > 1 || mode == 21) {
		    goto L50100;
		}
		dnonam_(name__);
	    } else {

/* ... IF THE FORM IS SUBSCRIPTED, CONVERT THE SUBSCRIPT TO CHARACTERS */
/* ... AND LEFT JUSTIFY IT NEXT TO THE FORM NAME READY FOR PRINTING */

		if (sub != 0) {
		    if (*code == 6 || *code == 5) {
			goto L50060;
		    }
		    for (j = 4; j <= 9; ++j) {
			if (*(unsigned char *)&nam[j - 3] == *(unsigned char *
				)&blk[0]) {
			    goto L50020;
			}
/* L50010: */
		    }
L50020:
		    *(unsigned char *)&nam[j - 2] = *(unsigned char *)&lparen[
			    0];
		    n = sub;
		    for (i__ = 1; i__ <= 7; ++i__) {
			k = 8 - i__;
			bcd = n % 10;
			iconv_(&bcd, numb, &c__1, &c__1, (ftnlen)1);
			*(unsigned char *)&stg[k - 1] = *(unsigned char *)
				numb;
			n /= 10;
			if (n == 0) {
			    goto L50040;
			}
/* L50030: */
		    }
L50040:
		    for (i__ = k; i__ <= 8; ++i__) {
			*(unsigned char *)&nam[j - 1] = *(unsigned char *)&
				stg[i__ - 1];
			++j;
/* L50050: */
		    }
		    *(unsigned char *)&nam[j - 2] = *(unsigned char *)&rparen[
			    0];
		}
	    }

/* ... WRITE HEADER CONTAINING FORM NAME,MODE AND SIZE */
/*     BUT SUPPRESS IF FORM IS UNDEFINED. */

L50060:
	    if (ckdtr_(&x[iabs - 1])) {
		goto L50100;
	    }
	    if (iph == 1) {
		iseq = iseqno;
		record_(&iseqno);
		if (iseq == iseqno) {
		    iph = 2;
		} else {
		    cform_("-", darray_1.darray, &c__1, &c__1, (ftnlen)1, (
			    ftnlen)120);
		    iph = 2;
		    iconv_(&iseqno, darray_1.darray, &c__2, &c__4, (ftnlen)
			    120);
		    cform_(".", darray_1.darray, &c__6, &c__1, (ftnlen)1, (
			    ftnlen)120);
		}
	    }

/* ... IF PROCESSING A PRINT/2 STATEMENT, SUPPRESS PRINTING THE HEADER. */

/* L50062: */
	    if (*code <= 3) {
		cform_(cnam, darray_1.darray, &c__7, &c__12, (ftnlen)16, (
			ftnlen)120);
		cform_(type__ + (mode - 1) * 6, darray_1.darray, &c__19, &
			c__6, (ftnlen)6, (ftnlen)120);
		iconv_(&size, darray_1.darray, &c__25, &c__5, (ftnlen)120);
		if (ldaflg) {
		    cprint_(darray_1.darray, (ftnlen)120);
		}
	    }

/* ... PRINT DIAGNOSTIC IF INCORRECTLY DEFINED. */

	    if (ckstr_(&x[iabs - 1])) {
		cform_(f30, darray_1.darray, &c__30, &c__19, (ftnlen)19, (
			ftnlen)120);
		cprint_(darray_1.darray, (ftnlen)120);
		goto L50100;
	    }
	    if (ldaflg || mode == 15) {
		goto L50100;
	    }

	    if (ic == 1) {

/* BLOCK 1 SCALARS */

		k = 30;
		fconv_(&x[iabs - 1], darray_1.darray, &k, &c__13, &c__6, (
			ftnlen)120);
		cprint_(darray_1.darray, (ftnlen)120);

	    } else if (ic == 2) {

/* BLOCK 2 SCALARS */

		k = 30;
		fconv_(&x[iabs - 1], darray_1.darray, &k, &c__13, &c__6, (
			ftnlen)120);
		cprint_(darray_1.darray, (ftnlen)120);

	    } else {

/* BLOCK 3 SURFACES */

/* ... CHECK IF REFSYS IN EFFECT. IF SO,PRINT FORM IN LOCAL SYSTEM */

		if (! bndflg) {
		    if (mode == 25) {

/* ...  PRINT A STRING FORM */

			a[0] = x[iabs - 1];
			count = (ia[1] + 3) / 4;
			j = count / 2 + count % 2;
			i__2 = j;
			for (i__ = 1; i__ <= i__2; ++i__) {
			    a[i__ - 1] = x[iabs + i__ - 1];
/* L3020: */
			}
			i__2 = count << 2;
			holfrm_(ia, darray_1.darray, &c__30, &i__2, &nwd, (
				ftnlen)120);
			cprint_(darray_1.darray, (ftnlen)120);
			goto L50100;
		    }

		    i__2 = size;
		    for (j = 1; j <= i__2; ++j) {
			k = iabs + j - 1;
			refsrf[j - 1] = x[k - 1];
/* L3030: */
		    }
		    if (ldef_1.refflg) {
			if (mode == 1 || mode == 2) {
			    ir = 4;
			} else if (mode == 3 || mode == 4 || mode == 9) {
			    ir = 5;
			} else if (mode == 5 || mode == 19) {
			    ir = 2;
			} else if (mode == 6 || mode == 7 || mode == 8 || 
				mode == 10 || mode == 14) {
			    ir = 1;
			} else if (mode == 20) {
			    ir = 3;
			} else {
			    goto L3038;
			}
			transf_(refsrf, &x[iabs - 1], &ir, &size, &c__0);
		    }

/* ... WRITE FORM ELEMENTS */

L3038:
		    k = 29;
		    i__2 = size;
		    for (j = 1; j <= i__2; ++j) {
			if (k + 13 <= 120) {
			    goto L13038;
			}
			cprint_(darray_1.darray, (ftnlen)120);
			k = 17;
L13038:
			fconv_(&refsrf[j - 1], darray_1.darray, &k, &c__13, &
				c__6, (ftnlen)120);
			k += 13;
/* L13039: */
		    }
		    cprint_(darray_1.darray, (ftnlen)120);

		} else {

/* ... P R I N T   B O U N D S   A N D   O B J E C T */

		    isub = sub;
		    i__2 = size;
		    for (l = 2; l <= i__2; l += 2) {
			k = iabs + l;
			name__[0] = x[k - 3];
			holfrm_(inam, cnam, &c__1, &c__8, &nwd, (ftnlen)16);
			if (*(unsigned char *)&nam[0] == *(unsigned char *)&
				star[0]) {
			    badnam_(name__);
			}
			if (*(unsigned char *)&nam[0] == *(unsigned char *)&
				dollar[0]) {
			    dnonam_(name__);
			}
			itemp[0] = bcdf_("    ", (ftnlen)4);
			itemp[1] = itemp[0];
			refsrf[l - 1] = *temp;
			if (mode == 28) {
			    goto L50235;
			}

/* ... BOUNDS */

/* L50220: */
			inam[2] = bcdf_("    ", (ftnlen)4);
			inam[3] = inam[2];
			iuvw = (integer) x[k - 2];
			iu = iuvw / ku;
			sub = (iuvw - iu * ku) / kv;
			iw = iuvw - iu * ku - sub * kv;
			if (sub != 0) {

/* ... IF THE FORM IS SUBSCRIPTED, CONVERT THE SUBSCRIPT TO CHARACTERS */
/* ... AND LEFT JUSTIFY IT NEXT TO THE FORM NAME READY FOR PRINTING */

			    for (j = 4; j <= 9; ++j) {
				if (*(unsigned char *)&nam[j - 3] == *(
					unsigned char *)&blk[0]) {
				    goto L50222;
				}
/* L50221: */
			    }
L50222:
			    *(unsigned char *)&nam[j - 2] = *(unsigned char *)
				    &lparen[0];
			    n = sub;
			    for (i__ = 1; i__ <= 7; ++i__) {
				k = 8 - i__;
				bcd = n % 10;
				iconv_(&bcd, numb, &c__1, &c__1, (ftnlen)1);
				*(unsigned char *)&stg[k - 1] = *(unsigned 
					char *)numb;
				n /= 10;
				if (n == 0) {
				    goto L50224;
				}
/* L50223: */
			    }
L50224:
			    for (i__ = k; i__ <= 8; ++i__) {
				*(unsigned char *)&nam[j - 1] = *(unsigned 
					char *)&stg[i__ - 1];
				++j;
/* L50225: */
			    }
			    *(unsigned char *)&nam[j - 2] = *(unsigned char *)
				    &rparen[0];
			} else {
			    j = 9;
			}
/* L50230: */
			if (l == 2) {
			    goto L50232;
			}
			bcd = iw;
			if (iw == 1 || iw == 2) {
			    s_copy(cnum, modhs + (iw - 1 << 2), (ftnlen)4, (
				    ftnlen)4);
			} else {
			    iconv_(&bcd, cnum, &c__1, &c__4, (ftnlen)4);
			}
			*(unsigned char *)&nam[j] = *(unsigned char *)&no[1];
			*(unsigned char *)&nam[j + 1] = *(unsigned char *)&no[
				2];
			*(unsigned char *)&nam[j + 2] = *(unsigned char *)&no[
				3];
			inam[2] = bcdf_(cnam + 8, (ftnlen)4);
L50232:
			refsrf[l - 1] = name__[1];

L50235:
			refsrf[l - 2] = name__[0];
/* L50250: */
		    }
		    cprint_(darray_1.darray, (ftnlen)120);
		    k = 12;
		    if (mode == 28) {
			k = 16;
		    }
		    i__2 = size << 1;
		    for (j = 1; j <= i__2; j += 4) {
			holfrm_(&irfsrf[j - 1], darray_1.darray, &k, &c__16, &
				nwd, (ftnlen)120);
			k += 14;
			if (mode == 27) {
			    k += 4;
			}
			if (k <= 108) {
			    goto L20251;
			}
			cprint_(darray_1.darray, (ftnlen)120);
			k = 12;
			if (mode == 28) {
			    k = 16;
			}
L20251:
			;
		    }
		    cprint_(darray_1.darray, (ftnlen)120);
		    iph = 2;
		    bndflg = FALSE_;
		    sub = isub;
		}
	    }

L50100:
	    if (*code == 15) {

/* ... P R I N T   N A M E   O N   T A B C Y L   L I S T I N G */

		record_(&iseqno);
		cform_("-", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)
			120);
		iconv_(&iseqno, darray_1.darray, &c__2, &c__4, (ftnlen)120);
		cform_(".", darray_1.darray, &c__6, &c__1, (ftnlen)1, (ftnlen)
			120);
		cform_(f13, darray_1.darray, &c__8, &c__18, (ftnlen)18, (
			ftnlen)120);
		cform_(cnam, darray_1.darray, &c__28, &c__12, (ftnlen)16, (
			ftnlen)120);
		cprint_(darray_1.darray, (ftnlen)120);
		goto L99999;
	    } else {

/* .... ADVANCE CURRENT FORM INDEX */

		if (ic == 1) {
		    index += 2;
		    iabs += 2;
		} else if (ic == 2) {
/* Computing MIN */
		    i__2 = 1, i__3 = sub - 1;
		    d__ = (doublereal) (3 - min(i__2,i__3));
		    index = (integer) (index + d__);
		    iabs = (integer) (iabs + d__);
		} else {
		    if (ldaflg) {
			size = 2;
			ldaflg = FALSE_;
		    }
/* Computing MIN */
		    i__2 = sub / 2;
		    d__ = (doublereal) (size + 2 - min(i__2,1));
		    index = (integer) (index + d__);
		    iabs = (integer) (iabs + d__);
		}
	    }
/* L5000: */
	}

    } else if (*code == 7) {

/* ...  E J E C T   A   P A G E */

	cform_("1", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);

    } else if (*code == 8) {

/* ...  T A K E   A   C O R E   D U M P */


    } else if (*code == 9) {

/* ...  P R I N T   A   T I T L E */

	namflg = FALSE_;
	iph = 1;
	mode = 21;
	jj = 0;
	size = 1;
	bndflg = FALSE_;
	ldaflg = FALSE_;

/* ... DETERMINE VIRTUAL INDEX OF ARRAY(1) IN X-ARRAY. */

	index = (addrss_(&array[1]) - addrss_(x)) / idef_1.kwrdsz + 1;
	iabs = index;
	if (ldef_1.canflg) {
	    incan_(&index);
	}

	a[0] = x[iabs - 1];
	count = (ia[1] + 3) / 4;
	cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
	if (count == 0) {
	    cprint_(darray_1.darray, (ftnlen)120);
	} else {
	    j = count / 2 + count % 2;
	    i__1 = j;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		a[i__ - 1] = x[iabs + i__ - 1];
/* L9010: */
	    }
	    holfrm_(a, check, &c__1, &c__8, &nwd, (ftnlen)8);
	    if (s_cmp(check + 1, right, (ftnlen)5, (ftnlen)5) == 0) {
		s_copy(check + 4, "  ", (ftnlen)2, (ftnlen)2);
		ia[1] = bcdf_(check + 4, (ftnlen)4);
		k = count - 1 << 2;
		if (k > 54) {
		    k = 54;
		}
		holfrm_(&ia[1], darray_1.darray, &c__66, &k, &nwd, (ftnlen)
			120);
		kright = 1;
		cprint_(darray_1.darray, (ftnlen)120);
	    } else {
		i__1 = count << 2;
		holfrm_(ia, darray_1.darray, &c__2, &i__1, &nwd, (ftnlen)120);
		if (kright == 1) {
		    cform_("+", darray_1.darray, &c__1, &c__1, (ftnlen)1, (
			    ftnlen)120);
		}
		kright = 0;
		cprint_(darray_1.darray, (ftnlen)120);
	    }
	}

    } else if (*code == 10) {

/* ...  P R I N T   N U M  B E R   I D E N T I F I E R */

	iseq = iseqno;
	record_(&iseqno);
	if (iseq == iseqno) {
	    goto L10010;
	}
	iconv_(&iseqno, darray_1.darray, &c__2, &c__4, (ftnlen)120);
	cform_(".", darray_1.darray, &c__6, &c__1, (ftnlen)1, (ftnlen)120);
L10010:
	fconv_(&array[1], darray_1.darray, &c__30, &c__13, &c__6, (ftnlen)120)
		;
	cprint_(darray_1.darray, (ftnlen)120);
    } else if (*code == 11) {

/* ...  T U R N   P R I N T   F L A G   O N */

	ldef_1.prnton = TRUE_;

    } else if (*code == 12) {

/* ...  T U R N   P R I N T   F L A G   O F F */

	ldef_1.prnton = FALSE_;

    } else if (*code == 13) {

/* ... T U R N   P C H L S T   F L A G   O N */

	ldef_1.pchlst = TRUE_;

    } else if (*code == 14) {

/* ... T U R N   P C H L S T   F L A G   O F F */

	ldef_1.pchlst = FALSE_;

    } else if (*code == 16) {

/* ... T U R N   T A B P R T   F L A G   O F F */

/*         T O   P R I N T   T A B C Y L S */

	ldef_1.tabprt = FALSE_;

    } else if (*code == 17) {

/* ... T U R N   T A B P R T   F L A G   O N */

/*     T O   S U P P R E S S   T A B C Y L   P R I N T O U T */

	ldef_1.tabprt = TRUE_;

    } else if (*code == 18) {

/* ... T U R N   S S P R T   F L A G  O N */

/*     T O  P R I N T   S S U R F   A N D   S C U R V */

/*     PRINT/SSPRT ,ON */

	ssprt_1.ssprt = TRUE_;

    } else if (*code == 19) {

/* ... T U R N   S S P R T   F L A G  O F F */

/*     T O  S U P P R E S S   S S U R F   A N D   S C U R V   P R I N T */

/*     PRINT/SSPRT ,OFF */

	ssprt_1.ssprt = FALSE_;

    } else if (*code == 20) {

/*     PRINT/SSTEST,ON */

	ssprt_1.sstest = TRUE_;

    } else if (*code == 21) {

/*    PRINT/SSTEST,OFF */

	ssprt_1.sstest = FALSE_;

    } else if (*code == 22) {

/*     PRINT/AVPRT,ON   - PRINT AVOIDANCE ACTION DETAILS */

	avcprm_1.avlist = TRUE_;

    } else if (*code == 23) {

/*     PRINT/AVPRT,OFF   - SUPPRESS PRINT OF AVOIDANCE ACTION DETAILS */

	avcprm_1.avlist = FALSE_;

    } else {
/* .... NON VALID CODE */
    }

/* ...  E X I T */

L99999:
    return 0;
} /* print_ */

#undef irfsrf
#undef refsrf
#undef bcanon
#undef iskip
#undef itemp
#undef sscan
#undef stage
#undef canon
#undef temp
#undef cnum
#undef numb
#undef inam
#undef name__
#undef cnam
#undef stg
#undef nam
#undef can
#undef no
#undef ia
#undef x
#undef c__
#undef a


