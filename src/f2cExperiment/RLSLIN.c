/* RLSLIN.f -- translated by f2c (version 20100827).
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
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer iltext[94];
} iltext_;

#define iltext_1 iltext_

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

/* Table of constant values */

static integer c__36 = 36;
static integer c__44 = 44;

/* *** SOURCE FILE : M0006682.V05   *** */


/*              FORTRAN SUBROUTINE RLSLIN */

/* LINKAGE      SUBROUTINE RLSLIN */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    FOUTXX          SUBROUTINE    ASNADZ */
/*          SUBROUTINE    COMPRS          SUBROUTINE    ASNJPZ */
/*          SUBROUTINE    PRTIL           SUBROUTINE    BOOLIF */
/*          SUBROUTINE    BINBCD          SUBROUTINE    CALMCX */
/*                                        SUBROUTINE    COMSTR */
/*                                        SUBROUTINE    GOLO */
/*                                        SUBROUTINE    GOPAT */
/*                                        SUBROUTINE    INPAT */
/*                                        SUBROUTINE    ISSCOD */
/*                                        SUBROUTINE    JUMPZZ */
/*                                        SUBROUTINE    LABELZ */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    LOOP */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    MNPROC */
/*                                        SUBROUTINE    MOTION */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO021 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REFGEN */
/*                                        SUBROUTINE    REFREF */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    RESRVZ */
/*                                        SUBROUTINE    RETMCX */
/*                                        SUBROUTINE    SSDEF */
/*                                        SUBROUTINE    SUBCOD */
/*                                        SUBROUTINE    TSSMIL */

/* Subroutine */ int rlslin_(void)
{
    /* Initialized data */

    static char m1[36] = "0 ** FINAL MACRO I.L. PROCESSING ** ";
    static char m2[44] = "0GENERATED I.L. FOR MACRO AT SEQNCE         ";
    static char line[124] = "    ";
    static logical headng = TRUE_;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer n;
#define ilhlt ((logical *)&macxx1_1 + 13)
#define ilprt ((logical *)&prt_1 + 1)
    extern /* Subroutine */ int prtil_(char *, ftnlen);
#define resrv ((integer *)&il_1 + 11)
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
#define mchdng ((logical *)&prt_1 + 6)
#define comfin ((logical *)&iltext_1)
#define intmed ((integer *)&macxx1_1 + 21)
    extern /* Subroutine */ int comprs_(void);
#define optext ((integer *)&iltext_1 + 3)
    extern /* Subroutine */ int foutxx_(integer *, char *, integer *, ftnlen);



/*       11.    SEQUENCE NUMBER STORAGE */


/* SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER */
/* SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRRENT STATEMENT NUMBER */

/*       14.    I. L. LIST OPTION FLAGS */




/* ILPRT:       TRUE INDICATES I.L. PRINTING (PPOPTN/INTLNG,ON) */
/* MCHDNG:      TRUE IF START OF NEW MACRO PROCESSING */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* RESRV:       CONTAINS COMMAND CODE (12) FOR RESRV COMMAND */

/*       19.    INTERMEDIATE LANGUAGE TEXT */

/* COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN */
/* OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND */

/*       22.    MACRO PROCESSING VARIABLES */

/* ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE */
/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */

/*       33.    SYMBOLIC FILE DEFINITIONS */

/* VLFILE:      VERIFICATION LISTING FILE */
/* * */

/* ...                SYSTEM I/O FILES */



/* ** */
    *comfin = FALSE_;
    if (*ilhlt) {
	goto L6;
    }
L1:
    if (! (*ilprt)) {
	goto L3;
    }
/* ...CHECK FOR FINAL MACRO PROCESSING */
    if (*intmed <= 0) {
	goto L2;
    } else {
	goto L4;
    }
L2:
    s_copy(line + 120, cseqcm_1.seqnum, (ftnlen)4, (ftnlen)4);
    prtil_(line, (ftnlen)124);
L3:
    comprs_();
    goto L7;
/* ...CHECK IF HEADING SHOULD BE PRINTED ON VLFILE */
L4:
    if (! headng) {
	goto L5;
    }
    foutxx_(&symfil_1.vlfile, m1, &c__36, (ftnlen)36);
    headng = FALSE_;

/* ...CHECK FOR START OF NEW MACRO I.L. */
L5:
    if (! (*mchdng)) {
	goto L2;
    }
    binbcd_(&seqcom_1.seqno, cseqcm_1.seqnum, &n, (ftnlen)6);
    s_copy(m2 + 36, cseqcm_1.seqnum, (ftnlen)8, (ftnlen)6);
    foutxx_(&symfil_1.vlfile, m2, &c__44, (ftnlen)44);
    *mchdng = FALSE_;
    goto L2;
L6:
    if (*optext == *resrv) {
	goto L1;
    }
L7:
    return 0;
} /* rlslin_ */

#undef optext
#undef intmed
#undef comfin
#undef mchdng
#undef resrv
#undef ilprt
#undef ilhlt


