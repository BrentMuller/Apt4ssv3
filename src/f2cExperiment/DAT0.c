/* DAT0.f -- translated by f2c (version 20100827).
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
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
} nametb_;

#define nametb_1 nametb_

struct {
    char cnamtb[18000], cnumtb[36000];
} cnamtb_;

#define cnamtb_1 cnamtb_

struct stor_1_ {
    integer ntb, fpb, ppb, comn, cfb, nblk, nrecrd[10], ntparm[10];
};

#define stor_1 (*(struct stor_1_ *) &stor_)

struct work_1_ {
    integer pgc, pgcn, ilc, ixc, scp, sap, nsp, iap, cfp, comp, ntp, lna[40]	
	    /* was [2][20] */, rtp, ac, avt[32], iwrit;
};

#define work_1 (*(struct work_1_ *) &work_)

struct const_1_ {
    integer kcomt, kcomf;
    logical cilprt;
    integer kcbn;
};

#define const_1 (*(struct const_1_ *) &const_)

/* Initialized data */

struct {
    integer e_1;
    integer fill_2[2];
    integer e_3;
    integer fill_4[2];
    integer e_5[20];
    } stor_ = { 0, {0}, 5000, {0}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0 };

struct {
    integer e_1[4];
    integer fill_2[47];
    integer e_3;
    integer fill_4[1];
    integer e_5[33];
    } work_ = { 0, 0, 0, 0, {0}, 0, {0}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

struct {
    integer e_1[2];
    integer fill_2[1];
    integer e_3;
    } const_ = { 16, 40, {0}, 128 };


/* *** SOURCE FILE : M0000882.V04   *** */

/* .....FORTRAN BLOCK DATA ROUTINE  ...DATA    8/68                 HG */
/* .....FORTRAN ROUTINE              ..DATA..    HL GRAY 3/68         *ID* */
/* Subroutine */ int dat0_(void)
{
    return 0;
} /* dat0_ */





/* ABBREVIATIONS AND TERMS */




/*     THE FOLLOWING ABBREVIATIONS AND TERMS ARE USED THROUGHOUT THE */
/*     CODING OF THE INTERPRETER.  IN GENERAL, TERMS ARE FORMED BY */
/*     CONCATENATING ROOT WORDS.  FOR EXAMPLE */

/*              NT        FOR NAME TABLE */
/*              P         FOR POINTER */

/*     FORM */

/*              NTP       NAME TABLE POINTER */

/*     AND ARE PRESENTED IN THIS GLOSSARY AS */

/*              NT.P */

/*     WHERE THE PERIODS INDICATE THE CONCATENATION AS A MEMORY AID. */




/* TERM         DEFINITION                                          TYPE */


/* A            ARRAY                                             MIXED */

/* AVT          ACTUAL VS VIRTUAL ADDRESS TABLE */

/* B            BEGINNING (USUALLY OF AN ARRAY)                     I */

/* C            CURRENT */

/* CF           CANONICAL FORM                                      D */

/* CF.B         CANONICAL FORM TABLE BEGINNING                      I */

/* CF.E         CANONICAL FORM TABLE END                            I */

/* CF.N         CANONICAL FORM TABLE LENGTH                         I */

/* CF.P         CANONICAL FORM TABLE POINTER                        I */

/* CILPRT       PRINT COMPRESSED I.L. FLAG */

/* COM          STORAGE (BLANK COMMON)                              D */

/* COM.B        STORAGE BEGINNING                                   I */

/* COM.E        STORAGE END                                         I */

/* COM.N        TOTAL LENGTH OF COMMON */

/* COM.P        STORAGE POINTER                                     I */

/* COM.S        SIZE OF ASSIGNED STORAGE FOR COMMON */

/* CM           STORAGE (BLANK COMMON) SAME AS COM)                 I */

/* E            END (USUALLY OF AN ARRAY)                           I */

/* FP           FLOATING POINT NUMBER TABLE                         D */

/* FP.B         FLOATING POINT TABLE BEGINNING                      I */

/* FP.E         FLOATING POINT TABLE END                            I */

/* FP.N         FLOATING POINT TABLE LENGTH                         I */

/* FP.P         FLOATING POINT TABLE POINTER                        I */

/* IA           INTERNAL ARRARY                                     D */

/* IA.B         INTERNAL ARRAY BEGINNING                            I */

/* IA.P         INTERNAL ARRAY POINTER                              I */

/* IL           INTERMEDIATE LANGUAGE INSTRUCTION.  AN N-TUPLE      I */
/*              WHOSE FORM IS SHOWN UNDER STRUCTURE. */

/* IL.C         POSITION OF CURRENT INTERMEDIATE LANGUAGE           I */
/*              INSTRUCTION RELATIVE TO PART PROGRAM BEGINNING */

/* IX           INDEX.  POINTER RELATIVE TO BEGINNING OF PAGE.      I */
/*              FIRST WORD OF PAGE HAS ZERO INDEX. */

/* IX.C         POSITION OF CURRENT INTERMEDIATE LANGUAGE           I */
/*              INSTRUCTION RELATIVE TO BEGINNING OF CURRENT PAGE */

/* K.           INTRODUCES A CONSTANT */

/* K.CB.N       EXTERNAL CANNON BLOCK LENGTH */

/* K.COM.F      LENGTH OF FIXED PORTION OF COMMON */

/* K.COM.T      LENGTH OF TEMPORARY PORTION OF COMMON */

/* K.IL.N       CONSTANT WHICH ADDED TO NUMBER OF PARAMETERS IN     I */
/*              ANY INTERMEDIATE LANGUAGE INSTRUCTION GIVES LENGTH */
/*              OF THAT INSTRUCTION IN WORDS. */

/* K.IL.P       POSITION RELATIVE TO BEGINNING OF INSTRUCTION  OF   I */
/*              THE WORD CONTAINING NUMBER OF PARAMETERS IN THE */
/*              INSTRUCTION. */

/* K.IL.1       POSTION RELATIVE TO BEGINNING OF PAGE OF FIRST */
/*              INSTRUCTION. */

/* K.NT.P       CORRECTION TO NAME TABLE POINTER TO EFFECT */
/*              PART PROGRAM CORRESPONDENCE */

/* K.MT.ST      MACRO TEXT FITS IN MEMORY                           L */

/* K.PG.LN      PAGE TO LINE PACKING FACTOR                         I */

/* K.PG.N       PAGE LENGTH                                         I */
/* K.PK.M       PACKING FACTOR FOR MODE                             I */

/* K.PK.S       PACKING FACTOR FOR SIZE                             I */


/* K.PP.ST      PART PROGRAM FITS IN MEMORY (INCLUDING MACRO TEXT)  L */


/* LN           LINE = (PAGE,INDEX)ING FACTOR) + INDEX              I */

/* LN.A         LINE ARRAY.  CONTAINS LINE NUMBERS FOR              I */

/* LN.C         CURRENT LINE NUMBER   GC*KPGLN + IXC)               I */

/* MT           MACRO TEXT (A PORTION OF THE PART PROGRAM)          H */

/* MT.B         MACRO TEXT BEGINNING                                I */

/* MT.E         MACRO TEXT END                                      I */

/* MT.N         MACRO TEXT LENGTH                                   I */

/* N            LENGTH (USUALLY OF AN ARRAY)                        I */

/* NB           NAME TABLE (SAME AS NT)                             D */

/* NBLK         NUMBER OF BLOCKS OF CANNON ALLOWED */

/* NS           NONSCALAR ARRAY                                     D */

/* NS.B         NONSCALAR ARRAY BEGINNING                           I */

/* NS.P         NONSCALAR ARRAY POINTER                             I */

/* NT           NAME TABLE                                          I */

/* NT.B         NAME TABLE BEGINNING                                I */

/* NT.E         NAME TABLE END                                      I */

/* NT.N         NAME TABLE LENGTH                                   I */

/* NT.P         NAME TABLE POINTER                                  I */

/* OD           OPERAND.  AN ORDERED PAIR, (TYPE, VALUE).           I */

/* OP           OPCODE (PORTION OF INTERMEDIATE LANGUAGE */
/*              INSTRUCTION) */

/* P            POINTER (USUALLY TO AN ELEMENT IN AN ARRAY          I */

/* PG           PAGE OF TEXT--POSITIVE FOR PART PROGRAM, NEGATIVE   I */
/*              FOR MACRO TEXT */

/* PG.C         CURRENT PAGE NUMBER                                 I */

/* PG.C.N       NUMBER OF WORDS ON CURRENT PAGE                     I */

/* PP           PART PROGRAM (INCLUDING MACRO TEXT)                 H */

/* PP.B         PART PROGRAM BEGINNING                              I */

/* PP.E         PART PROGRAM END                                    I */

/* PP.N         PART PROGRAM LENGTH                                 I */

/* RT.P         RETURN POINTER.  POINTS TO RETURN LINE IN MACRO     I */
/*              CALL/RETURN ARRAY, LN.A. */

/* SA           SCALAR ARRAY                                        D */

/* SA.B         SCALAR ARRAY TABLE BEGINNING                        I */

/* SA.E         SCALAR ARRAY TABLE END                              I */

/* SA.N         SCALAR ARRAY TABLE LENGTH                           I */

/* SA.P         SCALAR ARRAY TABLE POINTER                          I */

/* SC           SCALAR                                              R */

/* SC.B         SCALAR TABLE BEGINNING                              I */

/* SC.E         SCALAR TABLE END                                    I */

/* SC.N         SCALAR TABLE LENGTH                                 I */

/* SC.P         SCALAR TABLE POINTER                                I */





/* MASTER COMMON DECK */
/* --------------------------------------------------------------CDE PAK */



/* UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/* NAME TABLE */
/*     ------------------- */




/* STOR--COMMON CONTAINING STORAGE PARAMETERS */









/*   ADDITIONAL STOR PARAMETERS USED FOR NUMBER TABLE DIRECT ACCESS */


/* WORK--COMMON CONTAINING WORKING VARIABLES */




/*  THIS LOCATION IS USED TO PASS FUNCTION RESULTS FROM XCALL */
/*   THIS ARRAY USED BY THE ROUTINES INCAN AND XCANON */


/* CONST--COMMON CONTAINING CONSTANTS */






/* --------------------------------------------------------------------- */

