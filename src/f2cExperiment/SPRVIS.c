/* SPRVIS.f -- translated by f2c (version 20100827).
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
    logical err, xc, cl, px;
    integer errx;
    logical end, fini, asm__, abend;
    integer xtras[7];
} super_;

#define super_1 super_

struct {
    char irdsav[80];
} csuper_;

#define csuper_1 csuper_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    char jpar[80];
} parlst_;

#define parlst_1 parlst_

struct {
    integer kentry;
} aent_;

#define aent_1 aent_

struct {
    integer icmtes;
} cmptst_;

#define cmptst_1 cmptst_

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;
static integer c__38 = 38;
static integer c__43 = 43;
static integer c__37 = 37;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__9 = 9;
static integer c__55 = 55;
static integer c__23 = 23;
static integer c__64 = 64;
static integer c__8 = 8;
static integer c__72 = 72;
static integer c__6 = 6;
static integer c__15 = 15;
static integer c__19 = 19;
static integer c__29 = 29;
static integer c__17 = 17;
static integer c__47 = 47;
static integer c__2 = 2;
static integer c__44 = 44;
static integer c__45 = 45;
static integer c_n3 = -3;
static integer c__39 = 39;
static integer c__28 = 28;


/*                MODIFIED                 9-MAY-1989  E.MCLELLAN */
/* Subroutine */ int sprvis_0_(int n__)
{
    /* Initialized data */

    static char xfini[4] = "FINI";
    static char blank[4] = "    ";
    static char irds[80] = "REMARK                                          "
	    "                                ";
    static char action[8*3] = " CONTINU" "TERMINAT" "TERMINAT";
    static char kpar[4*4] = "TR  " "XC  " "CL  " "PX  ";
    static char lpcomp[4] = "COMP";
    static struct {
	char e_1[4];
	} equiv_2 = { "    " };

    static struct {
	char e_1[4];
	char fill_2[4];
	} equiv_3 = { "    " };

    static struct {
	char e_1[40];
	} equiv_4 = { "SUPERVISTRANSLATXECUTIONCLEDITORPOSTEXEC" };

    static struct {
	char e_1[132];
	} equiv_5 = { "                                                     "
		"                                                            "
		"                   " };


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k;
#define t ((char *)&equiv_2)
    static char x[1*80];
#define cx ((char *)&equiv_3)
#define wx ((char *)&equiv_3)
    static integer jex, icnt, jjex, iret;
    extern /* Subroutine */ int crtn_(integer *);
    static integer jrtn;
#define phas1 ((char *)&equiv_4)
    static integer time0, time1;
    static char xxxx[80];
    static integer iabnd;
    extern /* Subroutine */ int cread_(char *, integer *, ftnlen);
#define phase ((char *)&equiv_4 + 8)
    static doublereal etime;
    extern /* Subroutine */ int linkf_(char *, ftnlen), cform_(char *, char *,
	     integer *, integer *, ftnlen, ftnlen), fconv_(doublereal *, char 
	    *, integer *, integer *, integer *, ftnlen);
#define xblnk ((char *)&equiv_2)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen), tapop_(integer *, integer *);
    static integer start;
    extern /* Subroutine */ int clocf4_(integer *);
#define cflags ((logical *)&super_1)
#define darray ((char *)&equiv_5)
    extern /* Subroutine */ int artime_(void), cpuclo_(void);
#define larray ((char *)&equiv_5)
    extern /* Subroutine */ int getprm_(void), cprint_(char *, ftnlen);
#define lxtras ((logical *)&super_1 + 9)

/* ... PURPOSE,  CALLS EACH PHASE OF APT4 AND EXECUTES IT.  IN ADDITION */
/*    IT CHECKS FOR ERROR CONDITIONS AND FLAGS WHICH CAN TERMINATE A */
/*    PART PROGRAM BEFORE ALL PHASES ARE COMPLETE.  BATCH PROCESSING */
/*    IS POSSIBLE USING THIS SUPERVISOR. */

/* CALLS  LOAD MODULES   TRANSLAT,XECUTION,CLEDITOR,POSTEXEC. */


/* ... DICTIONARY */

/* ABEND  - FLAG INDICATING ABNORMAL TERMINATION */
/* ASM    - FLAG TO INDICATE IF ASSEMBLY APPROACH IS TO BE USED */
/* CFLAGS - SEE ERR,XC,CL,PX */
/* CL     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 3 */
/* CX     - HOLDS CURRENT STRING OF EIGHT CHARACTERS */
/* END      FLAG SET FALSE WHEN IT IS DETERMINED THAT ANOTHER PART */
/*            PROGRAM FOLLOWS */
/* ERR    - FLAG INDICATING ERRORS ARE NOT TO TERMINATE PROGRAM */
/* ERRX   - ERROR LEVEL */
/* ETIME  - ELAPSED TIME */
/* FINI   - FLAG TO INDICATE IF A FINI CARD HAS BEEN READ */
/* INFILE - INPUT FILE */
/* LXTRAS - SAME AS XTRAS */
/* PHASE  - NAME OF PHASE BEING EXECUTED */
/* PX     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 4 */
/* START  - TIME AT WHICH A PART PROGRAM BEGINS EXECUTION */
/* TIME0  - TIME AT WHICH A PHASE STARTS */
/* TIME1  - CURRENT TIME */
/* VLFILE - VARIFACATION LISTING(PRINTER) FILE */
/* WX     - EQUIVALENT TO CX */
/* X      - HOLDS CARD IMAGE */
/* XC     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 2 */
/* XTRAS(1)- CONTAINS NUMBER OF ERRORS */



/* ...      32.  PARAMETERS REQUIRED BY SUPERVISOR */








/* ...                SYSTEM I/O FILES */




/* ........SET UP PARAMETERS FOR ASSEMBLY APPROACH */




    switch(n__) {
	case 1: goto L_abnend;
	}

/*  ------------------- INITIALIZE FOR PART PROGRAM ---------------- */
    iabnd = 0;
    icnt = 0;
    getprm_();
    artime_();

    s_copy(csuper_1.irdsav, irds, (ftnlen)80, (ftnlen)80);
    super_1.end = TRUE_;
/* L50: */
    super_1.fini = FALSE_;

/* START THE CLOCK */
/* L100: */
    clocf4_(&start);
    time0 = start;

/* INTERPRETIVE METHOD IS THE DEFAULT. */
    super_1.asm__ = FALSE_;
    jjex = 0;
    jex = 0;
/* ---      DEFAULT- OUTPUT PRINT NOT COMPRESSED */
    cmptst_1.icmtes = 0;

/* ERRORS ARE TO TERMINATE PROGRAM,ALL PHASES WILL BE PROCESSED. */
    super_1.err = FALSE_;
    super_1.xc = FALSE_;
    super_1.cl = FALSE_;
    super_1.px = FALSE_;
    i__ = 1;
    if (icnt == 0) {
	goto L106;
    }
    if (s_cmp(parlst_1.jpar, kpar, (ftnlen)4, (ftnlen)4) == 0) {
	i__ = 1;
    }
    if (s_cmp(parlst_1.jpar, kpar + 4, (ftnlen)4, (ftnlen)4) == 0) {
	i__ = 2;
    }
    if (s_cmp(parlst_1.jpar, kpar + 8, (ftnlen)4, (ftnlen)4) == 0) {
	i__ = 3;
    }
    if (s_cmp(parlst_1.jpar, kpar + 12, (ftnlen)4, (ftnlen)4) == 0) {
	i__ = 4;
    }
L106:

/* ---       TEST FOR COMP IN PARM LIST */
    if (s_cmp(parlst_1.jpar, lpcomp, (ftnlen)4, (ftnlen)4) == 0) {
	cmptst_1.icmtes = 1;
    }
/* START NEW PAGE ON PRINTER. */
    cform_("1", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)132);
    cform_("CAM-I SCULPTURED SURFACE SSV3  SYSTEM.", darray, &c__5, &c__38, (
	    ftnlen)38, (ftnlen)132);
    cform_(" CAM-I INC., ARLINGTON,TEXAS  MAY,89 ", darray, &c__43, &c__37, (
	    ftnlen)37, (ftnlen)132);
    cprint_(darray, (ftnlen)132);
    cprint_(darray, (ftnlen)132);


/*  EXECUTE PHASE I */

L119:

/* SET ERROR LEVEL AT 0. */
    super_1.errx = 0;

/* SET ERROR COUNT AT 0. */
    super_1.xtras[0] = 0;
    super_1.xtras[1] = 0;

/* ASSUME ABNORMAL TERMINATION. */
    super_1.abend = TRUE_;

/* TEST FOR ASSEMBLY APPROACH AND PHASE TWO. */
    j = 1;
    if (super_1.asm__ && i__ == 2) {
	goto L999;
    }
    if (s_cmp(parlst_1.jpar, kpar + 4, (ftnlen)4, (ftnlen)4) == 0) {
	super_1.asm__ = TRUE_;
    }

/* LOAD AND EXECUTE PHASE (I). */
/* L120: */
    linkf_(phase + (i__ - 1 << 3), (ftnlen)8);
/* ...     SET J - DETERMINE IF PROCESSING SHOULD CONTINUE */
    j = 1;

/* IF ERR LEVEL GREATER THAN 4 AND CONTINUE NOT INDICATED, END PART PROG. */
    if (super_1.errx > jjex) {
	jjex = super_1.errx;
    }
    if (jex == 2 && i__ == 3) {
	j = 2;
    }
    if (! super_1.err && super_1.errx > 4 && i__ != 2) {
	j = 2;
    }
    if (! super_1.err && super_1.errx > 4 && i__ == 2) {
	jex = 2;
    }

/* IF ABEND NOT TURNED OFF OR ERR LEVEL GREATER THAN 8, TERMINATE. */
    if (super_1.abend || super_1.errx > 8) {
	j = 3;
    }
/* IF NO ERRORS, CONTINUE. */
    if (super_1.errx == 0) {
	goto L110;
    }

/* PRINT NUMBER OF ERRS AND ACTION TO BE TAKEN. */
/* L130: */
    iconv_(super_1.xtras, darray, &c__5, &c__3, (ftnlen)132);
    cform_("0***", darray, &c__1, &c__4, (ftnlen)4, (ftnlen)132);
    cform_(" ERROR(S) AND     WARNING(S) IN THIS PHASE. PROCESSING ", darray, 
	    &c__9, &c__55, (ftnlen)55, (ftnlen)132);
    iconv_(&super_1.xtras[1], darray, &c__23, &c__3, (ftnlen)132);
    cform_(action + (j - 1 << 3), darray, &c__64, &c__8, (ftnlen)8, (ftnlen)
	    132);
    cform_("ED.***", darray, &c__72, &c__6, (ftnlen)6, (ftnlen)132);
    cprint_(darray, (ftnlen)132);

/* PRINT ELAPSED TIME. */
L110:
    clocf4_(&time1);
    etime = (i__1 = time1 - time0, abs(i__1)) / 100.f;
    cform_("0APT-IV   SSV3 ", darray, &c__1, &c__15, (ftnlen)15, (ftnlen)132);
    cform_(phase + (i__ - 1 << 3), darray, &c__19, &c__8, (ftnlen)8, (ftnlen)
	    132);
    cform_("PHASE - CPU TIME=", darray, &c__29, &c__17, (ftnlen)17, (ftnlen)
	    132);
    fconv_(&etime, darray, &c__47, &c__6, &c__2, (ftnlen)132);
    cform_("SECS.", darray, &c__55, &c__5, (ftnlen)5, (ftnlen)132);
    cprint_(darray, (ftnlen)132);

/*  IF J=1, PROCESSING CONTINUES.  IF J=2, PROCESSING TERMINATES. */
/*        IF J=3, ABNORMAL TERMINATION. */
    switch (j) {
	case 1:  goto L140;
	case 2:  goto L800;
	case 3:  goto L900;
    }

/* WAS THERE A REQUEST TO TERMINATE AT THE END OF THIS PHASE. */
L140:

    time0 = time1;
    if (i__ == 4) {
	goto L800;
    }
    ++i__;
    if (! cflags[i__ - 1]) {
	goto L119;
    }



/*  XC,CL OR PX APPEARS IN CONTRL/ STATEMENT OR NOPOST=CNTRL/PX */

/* L600: */
    cform_("0***PROGRAM TERMINATED AT REQUESTED PHASE***", darray, &c__1, &
	    c__44, (ftnlen)44, (ftnlen)132);
    cprint_(darray, (ftnlen)132);
    j = 4;

/*  END OF A PART PROGRAM PROCESSING. */

L800:
    etime = (i__1 = time1 - start, abs(i__1)) / 100.f;
    fconv_(&etime, darray, &c__47, &c__6, &c__2, (ftnlen)132);
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)132);
    cform_("TOTAL - CPU TIME=", darray, &c__29, &c__17, (ftnlen)17, (ftnlen)
	    132);
    cform_("SECS.", darray, &c__55, &c__5, (ftnlen)5, (ftnlen)132);
    cprint_(darray, (ftnlen)132);


    cform_("0APT-IV    ERROR LEVEL IN THIS PART PROGRAM =", darray, &c__1, &
	    c__45, (ftnlen)45, (ftnlen)132);
    iconv_(&jjex, darray, &c__45, &c__3, (ftnlen)132);
    cprint_(darray, (ftnlen)132);
    if (iabnd == 1) {
	goto L999;
    }


/* CHECK FOR END OF DATA - THAT IS, NO MORE PART PROGRAMS */
/* L850: */
    if (super_1.asm__) {
	goto L999;
    }
    if (! super_1.end) {
	goto L999;
    }
    cread_(csuper_1.irdsav, &iret, (ftnlen)80);
    if (iret == 1) {
	goto L999;
    }
    super_1.end = FALSE_;
    tapop_(&symfil_1.clfil3, &c_n3);
    tapop_(&symfil_1.exfile, &c_n3);
    tapop_(&symfil_1.mactxt, &c_n3);
    tapop_(&symfil_1.xnum, &c_n3);
    cform_("0*** ONLY ONE PART PROGRAM PERMITTED***", darray, &c__1, &c__39, (
	    ftnlen)39, (ftnlen)132);
    cprint_(darray, (ftnlen)132);
    goto L999;



L_abnend:

    iabnd = 1;

/*  PHASE DID NOT HAVE A NORMAL ENDING. */

L900:
    cform_("0***ABNORMAL TERMINATION OF ", darray, &c__1, &c__28, (ftnlen)28, 
	    (ftnlen)132);
    cform_(phase + (i__ - 1 << 3), darray, &c__28, &c__8, (ftnlen)8, (ftnlen)
	    132);
    cform_("PHASE***", darray, &c__37, &c__8, (ftnlen)8, (ftnlen)132);
    cprint_(darray, (ftnlen)132);
    jjex = 16;
    if (iabnd == 1) {
	goto L800;
    }

    if (super_1.fini) {
	goto L800;
    }

/*  NO FINI.  SKIP TO END OF PART PROGRAM. */
L905:
    cread_(xxxx, &iret, (ftnlen)80);
    s_copy(wx, blank, (ftnlen)4, (ftnlen)4);
    if (iret == 1) {
	goto L999;
    }
    j = 1;
    k = 0;
L920:
    ++k;
    *(unsigned char *)t = *(unsigned char *)&x[k - 1];
    if (s_cmp(xblnk, blank, (ftnlen)4, (ftnlen)4) == 0) {
	goto L920;
    }
    *(unsigned char *)&cx[j - 1] = *(unsigned char *)&x[k - 1];
    ++j;
    if (j <= 4) {
	goto L920;
    }
    if (s_cmp(wx, xfini, (ftnlen)4, (ftnlen)4) == 0) {
	goto L800;
    }
    goto L905;


/*  END OF ALL PART PROGRAM PROCESSING. */

L999:
    jrtn = jjex;
    if (j == 1 && super_1.errx < 4) {
	jrtn = 0;
    }
    cpuclo_();
    crtn_(&jrtn);
    goto L999;

} /* sprvis_ */

#undef lxtras
#undef larray
#undef darray
#undef cflags
#undef xblnk
#undef phase
#undef phas1
#undef wx
#undef cx
#undef t


/* Subroutine */ int sprvis_(void)
{
    return sprvis_0_(0);
    }

/* Subroutine */ int abnend_(void)
{
    return sprvis_0_(1);
    }

