/* ISSCOD.f -- translated by f2c (version 20100827).
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
    integer srctbl[502];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer cnt;
} inptr_;

#define inptr_1 inptr_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer isscom[9];
} isscom_;

#define isscom_1 isscom_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;

/* *** SOURCE FILE : M0006643.V06   *** */


/*              FORTRAN SUBROUTINE ISSCOD */

/* LINKAGE      SUBROUTINE ISSCOD */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    INPUT */
/*          SUBROUTINE    CONCAT */
/*          SUBROUTINE    BINBCD */
/*          INTEGER FCT.  GETTMP */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    RLSLIN */
/*          SUBROUTINE    ARGCVT */

/* Subroutine */ int isscod_(void)
{
    /* Initialized data */

    static char ihblk[4] = "    ";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__;
#define top ((integer *)&stklst_1)
#define meta ((integer *)&srctbl_1 + 2)
#define issa ((integer *)&isscom_1)
#define issb ((integer *)&isscom_1 + 1)
#define issc ((integer *)&isscom_1 + 2)
    extern integer numb_(char *, ftnlen);
#define temp ((integer *)&code_1 + 32)
    static char ibuff[15];
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
#define stack ((integer *)&stklst_1 + 3)
    static integer inumb;
#define issfl ((logical *)&isscom_1 + 5)
    static integer irslt;
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen),
	     concat_(char *, char *, ftnlen, ftnlen);
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int opcode_(integer *), onearg_(integer *);
#define issend ((logical *)&isscom_1 + 6)
    extern /* Subroutine */ int argcvt_(integer *);
#define issmod ((integer *)&isscom_1 + 4)
#define modulo ((integer *)&moduli_1)
    extern integer gettmp_(integer *);
#define subscr ((integer *)&modx_1 + 23)
#define issvbl ((integer *)&isscom_1 + 3)
    static integer ierror;
    extern /* Subroutine */ int rlslin_(void);
#define cvtsub ((integer *)&il_1 + 12)
#define errpnt ((integer *)&errpos_1 + 2)
#define isstrm ((integer *)&isscom_1 + 7)

    /* Fortran I/O blocks */
    static icilist io___24 = { 0, ibuff, 0, "(I3)", 3, 1 };




/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     ' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        7.    STRING STORAGE AREA */
/*              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* CVTSUB:      CONTAINS COMMAND CODE (13) FOR CVTSUB COMMAND */

/*       17.    MODE CODES */

/* SUBSCR:      MODE CODE (24) FOR SUBSCRIPT */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       37.    INCLUSIVE SUBSCRIPT VARIABLES */

/* ISSA:        LOWEST SUBSCRIPT OF AN INCLUSIVE SUBSCRIPT STRING */
/* ISSB:        HIGHEST SUBSCRIPT OF AN INCLUSIVE SUBSCRIPT STRING */
/* ISSC:        INCREMENT OR DECREMENT FOR INCLUSIVE SUBSCRIPT STRING */
/* ISSVBL:      NAMTBL POINTER TO THE INCLUSIVE SUBSCRIPTED VARIABLE */
/* ISSMOD:      MODE OF THE INCLUSIVE SUBSCRIPTED VARIABLE */
/* ISSFL:       TRUE DURING INCLUSIVE SUBSCRIPT PROCESSING */
/* ISSEND:      END OF INCLUSIVE SUBSCRIPT PROCESSING */
/* ISSTRM:      SAVES THE STACK TOP ITEMS DURING SUBSCRIPT PROCESSING */

/*       44.    ERROR POSITION TABLE */

/* ERRPNT:      CONTAINS POINTERS TO INPUT STATEMENT TEXT POSITIONS */
/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* ** */

/* ...     CHECK FOR SPACE IN STACK */

    ierror = 0;
    if (*top + 2 <= 97) {
	goto L10;
    }
    ierror = 1028;

/* ...     ENTER NEW SUBSCRIPT IN NAMTBL */

L10:
    s_copy(ibuff + 11, ihblk, (ftnlen)4, (ftnlen)4);
    binbcd_(issa, ibuff + 3, &i__, (ftnlen)12);
    s_wsfi(&io___24);
    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    e_wsfi();
    concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
    inumb = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;

/* ...     GENERATE SUBSCRIPT I.L. AND PLACE TEMPORARY IN STACK */

    irslt = gettmp_(subscr);
    nametb_1.namtbl[irslt - 1] = temp[0] + *subscr;
    opcode_(cvtsub);
    argcvt_(&irslt);
    argcvt_(issvbl);
    argcvt_(&inumb);
    onearg_(&tmp_1.txxxx[(*issmod << 1) - 2]);
    rlslin_();
    nametb_1.namtbl[irslt - 1] = temp[0] + *issmod + *modhlf;
    stack[(*top + 1 << 1) - 2] = irslt;
    i__ = temp[0] / *modulo;
    stack[(*top + 1 << 1) - 1] = meta[i__ - 1];
    *top += 2;
    estack[*top - 1] = errpnt[inptr_1.cnt - 3];

/* ...     UPDATE ISSA AND CHECK FOR END OF SUBSCRIPT STRING */

    *issa += *issc;
    if (*issc < 0 && *issa < *issb || *issc > 0 && *issa > *issb) {
	goto L500;
    }
    if (ierror != 0) {
	goto L400;
    }

/* ...     PLACE COMMA IN TOP OF STACK AND CONTINUE */

    stack[(*top << 1) - 2] = comma[1];
    i__ = comma[0] / *modulo;
    stack[(*top << 1) - 1] = meta[i__ - 1];
    goto L600;

/* ...     END OF INCLUSIVE SUBSCRIPT STRING - RESTORE TOP ITEM */
/*          OF STACK AND SET FLAGS */

L400:
    alarm_(&ierror, top, &c__8, "ISSCOD  ", (ftnlen)8);
L500:
    for (i__ = 1; i__ <= 2; ++i__) {
	stack[i__ + (*top << 1) - 3] = isstrm[i__ - 1];
/* L550: */
    }
    *issend = TRUE_;
    *issfl = FALSE_;

L600:
    return 0;
} /* isscod_ */

#undef isstrm
#undef errpnt
#undef cvtsub
#undef issvbl
#undef subscr
#undef modulo
#undef issmod
#undef issend
#undef estack
#undef modhlf
#undef issfl
#undef stack
#undef comma
#undef temp
#undef issc
#undef issb
#undef issa
#undef meta
#undef top


