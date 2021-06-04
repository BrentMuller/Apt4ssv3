/* INTRP.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer ntb, fpb, ppb, comn, cfb;
} stor_;

#define stor_1 stor_

struct {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp;
} work_;

#define work_1 work_

struct {
    integer kcomt, kcomf;
    logical cilprt;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer ild;
} ild_;

#define ild_1 ild_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__18 = 18;
static integer c__10 = 10;
static integer c__20 = 20;
static integer c__6 = 6;
static integer c__12 = 12;
static integer c__25 = 25;
static integer c__1 = 1;
static integer c__31 = 31;
static integer c__32 = 32;
static integer c__36 = 36;
static integer c__7 = 7;
static integer c__41 = 41;
static integer c__49 = 49;
static integer c__51 = 51;
static integer c__29 = 29;
static integer c__30 = 30;
static integer c__8 = 8;
static integer c__38 = 38;
static integer c__40 = 40;

/* *** SOURCE FILE : M0004105.W03   *** */

/* .....FORTRAN SUBROUTINE  ....INTRP          8/68                 HG */
/* .....FORTRAN ROUTINE              ..INTRP..   HL GRAY 3/68         *ID* */
/* Subroutine */ int intrp_(void)
{
    /* Initialized data */

    static integer ispecl = 319951634;
    static struct {
	integer fill_1[1];
	integer e_2;
	doublereal e_3;
	} equiv_8 = { {0}, 0, 0. };


    /* System generated locals */
    integer i__1;
    static doublereal equiv_6[1], equiv_7[1];

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l;
#define x4 ((integer *)equiv_7)
#define x8 (equiv_7)
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
    static integer jc;
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
    static integer nf;
#define fp ((doublereal *)&_BLNK__1)
    static integer im;
#define ll ((integer *)&equiv_8)
    static integer ln[2], nm, nl, is, op;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
    static integer ix;
#define xl ((doublereal *)&equiv_8)
    static integer nw;
#define tt ((integer *)equiv_6)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int lib_(void);
#define fpp ((integer *)&work_1 + 10)
    extern doublereal get_(integer *);
    extern /* Subroutine */ int adv_(void), seq_(integer *), set_(integer *);
    static integer nbk, lll, nwd;
    extern /* Subroutine */ int put_(doublereal *, integer *);
    static integer ntp1, ntp2, mode;
    extern /* Subroutine */ int help_(void);
    static integer llll, isub;
    static real sqnc;
    static integer comp1;
    extern /* Subroutine */ int apt295_(doublereal *, doublereal *, 
	    doublereal *);
    static integer locx1;
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), iconv_();
    static integer locxi, isize, ksize;
#define xtemp (equiv_6)
    static integer kount;
    extern /* Subroutine */ int resrv_(void);
    static integer isize1;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int record_(real *), unpack_(doublereal *, 
	    integer *, integer *, integer *);
    extern integer xcanon_(integer *);
    extern /* Subroutine */ int holfrm_();
    static integer ischro;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer kztemp;

/* FORTRAN SUBROUTINE 'INTRP', THE MAIN INTERPRETER */

/* PURPOSE      THIS ROUTINE EXECUTES APT INTERMEDIATE LANGUAGE */
/*              INSTRUCTIONS ONE-BY-ONE. */

/* LINKAGE      CALL INTRP */

/* ARGUMENTS    THROUGH COMMON */

/* SUBSIDIARIES 'ADV'     ADVANCE LOCATION COUNTER */
/*              'SET'     SET LOCATION COUNTER */
/*              'LIB'     CALL LIBRARY ROUTINE */
/*               GET      OBTAIN AN OPERAND OR OPERAND ADDRESS */
/*               RESRV    RESERVE STORAGE ROUTINE */
/*               PUT      STORE OPERAND */
/*               SEQ      SEQUENCE ROUTINE */
/*               APT295   EXPONENTIATION ROUTINE */


/* METHOD       THE INTERMEDIATE LANGUAGE OPCODE IS EXTRACTED (L300). */
/*              A BRANCH THEN OCCURS TO A SMALL SUBSECTION WHICH */
/*              EXECUTES THE INSTRUCTION. */

/*              IF THE INSTRUCTION DOES NOT CONTAIN A JUMP, THE RETURN */
/*              CAUSES THE PSEUDOLOCATION COUNTER TO ADVANCE ONE */
/*              INSTRUCTION (L200), THEN EXTRACTION OCCURS */

/*              IF THE INSTRUCTION CONTAINS A JUMP, THE PSEUDOLOCATION */
/*              COUNTER IS RESET TO THE DESTINATION INSTRUCTION AND THE */
/*              RETURN IS TO THE EXTRACTION PROCESS. */

/* --------------------------------------------------------------CDE PAK */




/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */







/* STOR--COMMON CONTAINING STORAGE PARAMETERS */


/*     ------------------- */



/* WORK--COMMON CONTAINING WORKING VARIABLES */







/* CONST--COMMON CONTAINING CONSTANTS */







/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* --------------------------------------------------------------------- */

/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*        ADVANCE PSEUDOLOCATION COUNTER */

L200:
    adv_();

/*        EXTRACT OPCODE FROM INSTRUCTION AND EXECUTE IT. */
L300:
    op = pp[work_1.ilc - 1];
    j = pp[work_1.ilc] + work_1.ilc + 1;
    if (! const_1.cilprt) {
	goto L2;
    }
/*  PRINT COMPRESSED I.L. */
    jc = j;
    cform_("PAG", darray_1.darray, &c__2, &c__3, (ftnlen)3, (ftnlen)120);
    iconv_(&work_1.pgc, darray_1.darray, &c__5, &c__4, (ftnlen)120);
    cform_("(    ),LOC(      )", darray_1.darray, &c__9, &c__18, (ftnlen)18, (
	    ftnlen)120);
    iconv_(&work_1.ixc, darray_1.darray, &c__10, &c__4, (ftnlen)120);
    iconv_(&work_1.ilc, darray_1.darray, &c__20, &c__6, (ftnlen)120);
    if (op == 21) {
	jc = work_1.ilc + 3;
    }
    i__ = work_1.ilc;
L8999:
    l = 29;
L9000:
    k = pp[i__ - 1];
    iconv_(&k, darray_1.darray, &l, &c__5, (ftnlen)120);
    l += 6;
    if (k != 7 || i__ < work_1.ilc + 2) {
	goto L99;
    }
/*            1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 */
    switch (op) {
	case 1:  goto L98;
	case 2:  goto L98;
	case 3:  goto L98;
	case 4:  goto L98;
	case 5:  goto L98;
	case 6:  goto L99;
	case 7:  goto L99;
	case 8:  goto L99;
	case 9:  goto L99;
	case 10:  goto L99;
	case 11:  goto L98;
	case 12:  goto L99;
	case 13:  goto L98;
	case 14:  goto L99;
	case 15:  goto L98;
	case 16:  goto L99;
	case 17:  goto L98;
	case 18:  goto L98;
	case 19:  goto L98;
	case 20:  goto L99;
	case 21:  goto L99;
    }
L98:
    if (pp[i__ - 2] == 5 || pp[i__ - 2] == 6) {
	goto L99;
    }
    x4[0] = pp[i__];
    x4[1] = pp[i__ + 1];
    fconv_(x8, darray_1.darray, &l, &c__12, &c__5, (ftnlen)120);
    i__ += 2;
    l += 13;
L99:
    if (i__ == jc) {
	goto L9002;
    }
    ++i__;
    if (l < 101) {
	goto L9000;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    goto L8999;
L9002:
    cprint_(darray_1.darray, (ftnlen)120);
    if (op != 21) {
	goto L2;
    }
L9003:
    l = k;
    if (k > 92) {
	l = 92;
    }
    holfrm_(&pp[i__], darray_1.darray, &c__25, &l, &nw, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (k <= 92) {
	goto L2;
    }
    i__ += nw;
    k += -92;
    goto L9003;
L2:
    if (op < 1 || op > 21) {
	goto L9020;
    }
    ild_1.ild = 0;

/* OPCODE     1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 */

    switch (op) {
	case 1:  goto L1;
	case 2:  goto L1;
	case 3:  goto L1;
	case 4:  goto L1;
	case 5:  goto L1;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
	case 16:  goto L16;
	case 17:  goto L17;
	case 18:  goto L18;
	case 19:  goto L19;
	case 20:  goto L20;
	case 21:  goto L21;
    }
/*            . . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  . */
/*            . . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  . */
/*            . . . . FEXP. . .  RETMC .  .  .  ASNADD.  .  .  VBLJMP */
/*            . . . FDIV. . . SEQNCE.  .  .  CALMC .  .  .  MOVE  . */
/*            . . FMPY  . . JUMP    .  .  CVTSUB   .  .  CALL     . */
/*            . FSUB    . ENTRY     .  RESRV       .  REPL        . */
/*            FADD      LABEL       CONJMP         ASNJMP         HOLDAT */






/*        PROCESS ARITHMETIC OPCODES */


/*        GET ARGUMENTS FROM OPERANDS */

L1:
    a = get_(&c__4);
    b = get_(&c__6);

/*        BRANCH TO CALCULATE  C = (A) OPERATION (B) */

/*        OPCODE +     -     *     /    ** */
    switch (op) {
	case 1:  goto L1001;
	case 2:  goto L1002;
	case 3:  goto L1003;
	case 4:  goto L1004;
	case 5:  goto L1005;
    }

/*        ADDITION */

L1001:
    c__ = a + b;
    goto L1006;

/*        SUBTRACTION */

L1002:
    c__ = a - b;
    goto L1006;

/*        MULTIPLICATION */

L1003:
    c__ = a * b;
    goto L1006;

/*        DIVISION */

L1004:
    c__ = a / b;
    goto L1006;

/*        EXPONENTIATION */

L1005:
    apt295_(&c__, &a, &b);
    goto L1006;

/*        STORE RESULT IN FIRST OPERAND AND RETURN */

L1006:
    put_(&c__, &c__2);

    goto L200;




/*       PROCESS LABEL INSTRUCTIONS */
/*        PROCESS LABEL AND ENTRY INSTRUCTIONS */


/*        COMPUTE NAME TABLE POINTER, ENTER LINE, AND RETURN */

L6:
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
    nt[(work_1.ntp << 1) - 2] = pp[work_1.ilc + 2];
    nt[(work_1.ntp << 1) - 1] = pp[work_1.ilc + 3];
    goto L200;


/*       PROCESS ENTRY INSTRUCTION (THIS ALSO USED AS A NOOP INSTRUCTION) */


L7:
    goto L200;


/*        PROCESS JUMP INSTRUCTION */


/*        GET INDEX OF LABEL */

L8:
    ntp1 = pp[work_1.ilc + 1];


/*        COMPUTE NAME TABLE POINTER--ALSO ENTRY FROM CONJMP INSTRUCTION */

L8001:
    work_1.ntp = ntp1 + stor_1.ntb;

/*        EXTRACT LINE */
    ln[0] = nt[(work_1.ntp << 1) - 2];
    ln[1] = nt[(work_1.ntp << 1) - 1];

/*        RESET LOCATION COUNTER */

    set_(ln);

/*        AND RETURN */
    goto L300;




/*        PROCESS SEQUENCE INSTRUCTION */


L9:
    seq_(&pp[work_1.ilc + 1]);
    ischro = 0;
    goto L200;




/*        PROCESS RETMAC INSTRUCTION */

/*        SET LOCATION COUNTER TO TOP OF MACRO STACK */

L10:
    set_(&work_1.lna[(work_1.rtp << 1) - 2]);

/*        POP UP MACRO STACK */
    --work_1.rtp;

/*        ADVANCE LOCATION COUNTER */
    goto L200;



/*        PROCESS CONJUMP INSTRUCTION */


/*        GET VALUE OF OPERAND */

L11:
    a = get_(&c__2);

/*        TEST VALUE AND GO TO JUMP WITH PROPER POINTER */

/*              )0     =0     >0 */
    if (abs(a) < 1e-12) {
	goto L11002;
    }
    if (a < 0.) {
	goto L11001;
    } else if (a == 0) {
	goto L11002;
    } else {
	goto L11003;
    }

L11001:
    ntp1 = pp[work_1.ilc + ild_1.ild + 3];
    goto L8001;

L11002:
    ntp1 = pp[work_1.ilc + ild_1.ild + 4];
    goto L8001;

L11003:
    ntp1 = pp[work_1.ilc + ild_1.ild + 5];
    goto L8001;




/*        PROCESS RESRV INSTRUCTION */

/*        ALL RESRS INSTRUCTIONS EXECUTED DURING INITIALIZATION */

L12:
    resrv_();
    goto L200;




/*        PROCESS CVTSUB */


/*        GET SUBSCRIPT */
/*        FIND LOCATION OF X(I) */
L13:
    i__ = (integer) get_(&c__6);
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 4];
    ksize = pp[work_1.ilc + 7] + 1;
    locx1 = nt[(work_1.ntp << 1) - 2] - stor_1.cfb;
    locxi = locx1 - (i__ - 1) * ksize;
    if (! ldef_1.canflg) {
	goto L1310;
    }
/*        IS X(I) IN FIRST BLOCK OF X ARRAY */
    if (locx1 / const_1.kcbn == locxi / const_1.kcbn) {
	goto L1310;
    }
/*        NO,FIND NO. OF ELEMENTS OF X IN FIRST BLOCK */
    nf = locx1 % const_1.kcbn / ksize + 1;
/*        FIND NO. OF  FULL BLOCKS OF X ELEMENTS */
    nbk = (i__ - nf) / ((const_1.kcbn - 1) / ksize);
/*        FIND NO. OF ELEMENTS OF X IN MIDDLE BLOCKS */
    nm = nbk * ((const_1.kcbn - 1) / ksize);
/*        FIND  NO. OF ELEMENTS OF X IN LAST BLOCK */
    nl = i__ - nf - nm;
    locxi = locx1 - (nf + nl - 1) * ksize - nbk * const_1.kcbn - 1;
    if (nl == 0) {
	locxi = locxi + (const_1.kcbn - 1) % ksize + 1;
    }

/*        STORE ADDRESS */
L1310:
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 2];
    nt[(work_1.ntp << 1) - 2] = locxi + stor_1.cfb;

/*  CHECK IF INDEX IS IN RANGE. */
    if (locxi + stor_1.cfb > work_1.iap) {
	goto L9010;
    }
    ix = locxi + stor_1.cfb;
    if (ldef_1.canflg) {
	ix = xcanon_(&ix);
    }
    if (ksize == 2) {
	goto L1320;
    }
    unpack_(&_BLNK__1.com[ix - 1], &im, &is, &ix);
    if (ix == 0) {
	ix = 1;
    }
L1330:
    if (ix != i__) {
	goto L9010;
    }
    goto L200;
L1320:
    ix = (integer) _BLNK__1.com[ix];
    goto L1330;



/*     PROCESS CALMC INSTRUCTION */

/*        PUSH DOWN MACRO STACK */

L14:
    ++work_1.rtp;

/*        SAVE LINE(PAGE AND INDEX  OF THIS INSTRUCTION */

    work_1.lna[(work_1.rtp << 1) - 2] = work_1.pgc;
    work_1.lna[(work_1.rtp << 1) - 1] = work_1.ixc;

/*        RESET LOCATION COUNTER TO MACRO ADDRESS */

    work_1.ntp = pp[work_1.ilc + 1] + stor_1.ntb;
    set_(&nt[(work_1.ntp << 1) - 2]);
    goto L300;


/*        PROCESS ASNADD INSTRUCTION */

/*        GET COM POINTER OF OPERAND */
L15:
    kztemp = pp[work_1.ilc + 2];
    if (kztemp != 1) {
	goto L1510;
    }
/* ---     SPECIAL ACTION FOR NUMBER ASSIGNMENT IN PAGING ENVIRONMENT */
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
    nt[(work_1.ntp << 1) - 2] = pp[work_1.ilc + 3];
    nt[(work_1.ntp << 1) - 1] = ispecl;
    goto L200;
L1510:
    *xtemp = get_(&c__3);
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
    nt[(work_1.ntp << 1) - 2] = work_1.comp;
    nt[(work_1.ntp << 1) - 1] = 0;
    goto L200;


/*        PROCESS ASNJMP INSTRUCTION */

/*        COMPUTE THE TWO NAME TABLE POINTERS, TRANSFER DATA AND EXIT */

L16:
    ntp1 = stor_1.ntb + pp[work_1.ilc + 1];
    ntp2 = stor_1.ntb + pp[work_1.ilc + 2];
    nb[ntp1 - 1] = nb[ntp2 - 1];
    goto L200;


/*        PROCESS REPL INSTRUCTION */

/*        GET COM POINTER OF OPERAND */
L17:
    *xtemp = get_(&c__3);
    comp1 = work_1.comp;

/*        GET COM POINTER OF RESULTANT */
    *xtemp = get_(&c__5);
    if (! ldef_1.canflg) {
	goto L1705;
    }
    comp1 = xcanon_(&comp1);
    work_1.comp = xcanon_(&work_1.comp);
/*  ABFANGEN BEI FEHLERHAFTEM EINGABEELEMENT */
L1705:
    llll = pp[work_1.ilc + 4];
    if (llll > 0 && llll != 3) {
	goto L1709;
    }
    lll = 0;
    if (llll < 0) {
	lll = llll + 1;
    }
    if (! ckdef_(&_BLNK__1.com[work_1.comp + lll - 1])) {
	goto L1709;
    }
    goto L1708;
/*        REPLACE ELEMENTS */
L1709:
    kount = pp[work_1.ilc + 1];
    i__1 = kount;
    for (i__ = 1; i__ <= i__1; ++i__) {
	_BLNK__1.com[comp1 - 1] = _BLNK__1.com[work_1.comp - 1];
	++work_1.comp;
/* L1710: */
	++comp1;
    }

    goto L200;


/*        PROCESS CALL INSTRUCTION */

L18:
    if (ischro != 0) {
	goto L181;
    }
    lib_();
L181:
    if (pp[work_1.ilc + 1] == 18) {
	return 0;
    }
    goto L200;


/*        PROCESS MOVE INSTRUCTION */

/*        GET COM POINTER OF OPERAND */
L19:
    *xtemp = get_(&c__2);
    comp1 = work_1.comp;
    if (ldef_1.canflg) {
	comp1 = xcanon_(&comp1);
    }

/*        MOVE ELEMENTS */
    kount = pp[work_1.ilc];
    i__1 = kount;
    for (i__ = 4; i__ <= i__1; i__ += 2) {
	k = work_1.ilc + ild_1.ild + i__;
	if (k >= j) {
	    goto L200;
	}
	_BLNK__1.com[comp1 - 1] = get_(&i__);
	llll = pp[k - 1];
	if (llll > 0 && llll != 3) {
	    goto L1910;
	}
	lll = 0;
	if (llll < 0) {
	    lll = llll + 1;
	}
	work_1.comp += lll;
	if (ldef_1.canflg) {
	    work_1.comp = xcanon_(&work_1.comp);
	}
	if (! ckdef_(&_BLNK__1.com[work_1.comp - 1])) {
	    goto L1910;
	}
	comp1 = work_1.comp;
	goto L1708;
L1910:
	++comp1;
    }

    goto L200;


/*        PROCESS VBLJMP INSTRUCTION */

/*        OBTAIN INDEX TO JUMP */
/* .... USING MODIFIED IL FOR INDEX WHICH IS NOT SYSTEM DEPENDENT */
L20:
    *xtemp = get_(&c__2);
    kount = (integer) (*xtemp);

/*        IF INDEX NOT IN RANGE,CONTINUE */
    if (kount >= pp[work_1.ilc] - 1 || kount <= 0) {
	goto L200;
    }

/*        GO TO LABEL INDICATED BY INDEX */
    kount = kount + work_1.ilc + 3;
    ntp1 = pp[kount - 1];
    goto L8001;


/*        PROCESS HOLDAT INSTRUCTION */

/*        THE FOLLOWING CODE IS IMPLIMENTATION DEPENDENT             *ID* */
/*        ALL HOLDAT INSTRUCTIONS EXECUTED DURING INITIALIZATION */

/*        STORE NUMBER OF WORDS OF BCD DATA */
L21:
    tt[0] = pp[work_1.ilc];

/*        STORE NUMBER OF CHARACTERS */
    tt[1] = pp[work_1.ilc + 2];

    l = work_1.iap;

/*        STORE CHARACTERS */
    k = pp[work_1.ilc + 2] / 8;
    if (pp[work_1.ilc + 2] > k << 3) {
	++k;
    }
    if (! ldef_1.canflg) {
	goto L2105;
    }
/*        WILL STORAGE REQUIREMENTS EXCEED BLOCK LENGTH */
    if ((l - stor_1.cfb + k) / const_1.kcbn == (l - stor_1.cfb) / 
	    const_1.kcbn) {
	goto L2102;
    }
/*        YES,INDICATE NO. OF WORDS TO BE SKIPPED. */
    j = xcanon_(&l);
    ll[0] = const_1.kcbn - (l - stor_1.cfb) % const_1.kcbn;
    ia[j - 1] = *xl;
/*        SKIP TO NEXT BLOCK OF STORAGE */
    l = (l - stor_1.cfb + k) / const_1.kcbn * const_1.kcbn + stor_1.cfb;
    work_1.iap = l;
L2102:
    l = xcanon_(&l);
L2105:
    ia[l - 1] = *xtemp;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++l;
	j = work_1.ilc + (i__ + 1 << 1);

/*        OBTAIN CHARACTERS ONE INTEGER WORD FULL AT A TIME */
	tt[0] = pp[j - 1];
	tt[1] = pp[j];
	ia[l - 1] = *xtemp;

/*        STORE CHARACTERS EIGHT AT A TIME */
/* L2110: */
    }
/*        STORE POINTER */
    work_1.ntp = stor_1.ntb + pp[work_1.ilc + 1];
    nt[(work_1.ntp << 1) - 2] = work_1.iap;
    work_1.iap = work_1.iap + k + 1;

    goto L200;


L9010:
    record_(&sqnc);
    cform_("029003 INDEX OUT OF RANGE. ISN=", darray_1.darray, &c__1, &c__31, 
	    (ftnlen)31, (ftnlen)120);
    iconv_(&sqnc, darray_1.darray, &c__32, &c__4, (ftnlen)120);
    cform_(" INDEX=", darray_1.darray, &c__36, &c__7, (ftnlen)7, (ftnlen)120);
    iconv_(&i__, darray_1.darray, &c__41, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    help_();
L9020:
    record_(&sqnc);
    cform_("029004 SYSTEM ERR-ILLEGAL I.L. INSTRUCTION. ISN= ", 
	    darray_1.darray, &c__1, &c__49, (ftnlen)49, (ftnlen)120);
    iconv_(&sqnc, darray_1.darray, &c__51, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    help_();
    return 0;
/*  AUSGABE DER FEHLERHAFTEN GEOMETRIE-NAMEN */
L1708:
    ischro = 1;
    if (comp1 >= work_1.scp) {
	goto L1720;
    }
/*  NAME EINES SKALARELEMENTES */
    isize = 1;
    isub = 0;
    goto L1750;
L1720:
    if (comp1 >= work_1.sap) {
	goto L1730;
    }
/*  NAME EINES INDIZIERTEN SKALARELEMENTES */
    isize = 2;
    isub = (integer) _BLNK__1.com[comp1];
    isize1 = isub << 1;
    goto L1750;
/*  NAME EINES GEOMETRIEELEMENTES */
L1730:
    unpack_(&_BLNK__1.com[comp1 - 1], &mode, &isize, &isub);
    if (isub >= 1) {
	isize1 = isub * isize + isub - 1;
    }
L1750:
    cform_(" WRONG INPUT ELEMENT        :", darray_1.darray, &c__1, &c__29, (
	    ftnlen)29, (ftnlen)120);
    if (isub >= 1) {
	goto L1706;
    }
/*  NICHT INDIZIERTE VARIABLE */
    holfrm_(&_BLNK__1.com[comp1 + isize - 1], darray_1.darray, &c__30, &c__8, 
	    &nwd, (ftnlen)120);
    goto L1707;
/*  INDIZIERTE VARIABLE */
L1706:
    holfrm_(&_BLNK__1.com[comp1 + isize1 - 1], darray_1.darray, &c__30, &c__8,
	     &nwd, (ftnlen)120);
    cform_("(      )", darray_1.darray, &c__38, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&isub, darray_1.darray, &c__40, &c__4, (ftnlen)120);
L1707:
    cprint_(darray_1.darray, (ftnlen)120);
    goto L200;
} /* intrp_ */

#undef bcanon
#undef xtemp
#undef sscan
#undef canon
#undef fpp
#undef can
#undef tt
#undef xl
#undef nt
#undef mt
#undef pp
#undef ll
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf
#undef x8
#undef x4


