/* PARNOM.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__2 = 2;
static integer c__32 = 32;
static integer c__29 = 29;
static integer c__42 = 42;
static integer c__1 = 1;

/* *** SOURCE FILE : PARNOM00.ORG   *** */

/* Subroutine */ int parnom_0_(int n__, integer *n, doublereal *a, integer *j)
{
    /* Initialized data */

    static struct {
	integer1 e_1[384];
	} equiv_1 = { 128, 128, 128, 128, 128, 128, 128, 128, 94, 128, 128, 
		128, 128, 7, 128, 7, 128, 128, 148, 62, 148, 62, 148, 128, 
		174, 42, 127, 42, 174, 128, 227, 19, 8, 52, 227, 128, 251, 69,
		 107, 16, 104, 128, 128, 128, 7, 128, 128, 128, 128, 28, 162, 
		193, 193, 128, 128, 193, 193, 162, 28, 128, 8, 42, 28, 42, 8, 
		128, 8, 8, 62, 8, 8, 128, 128, 128, 208, 176, 128, 128, 8, 8, 
		8, 8, 8, 128, 128, 128, 224, 224, 128, 128, 32, 16, 8, 4, 2, 
		128, 62, 193, 193, 193, 62, 128, 128, 2, 127, 128, 128, 128, 
		194, 97, 81, 73, 70, 128, 161, 193, 73, 205, 179, 128, 152, 
		148, 146, 127, 16, 128, 167, 69, 69, 69, 185, 128, 188, 194, 
		73, 73, 176, 128, 1, 1, 121, 133, 131, 128, 182, 73, 73, 73, 
		182, 128, 134, 73, 73, 161, 158, 128, 128, 128, 182, 182, 128,
		 128, 128, 128, 214, 182, 128, 128, 8, 148, 162, 193, 128, 
		128, 162, 162, 162, 162, 162, 128, 128, 193, 162, 148, 8, 128,
		 2, 1, 217, 133, 2, 128, 62, 193, 93, 213, 94, 128, 254, 145, 
		145, 145, 254, 128, 127, 73, 73, 73, 182, 128, 62, 193, 193, 
		193, 162, 128, 127, 193, 193, 193, 227, 128, 127, 73, 73, 73, 
		193, 128, 127, 137, 137, 137, 1, 128, 227, 193, 193, 73, 121, 
		128, 127, 8, 8, 8, 127, 128, 128, 193, 127, 193, 128, 128, 32,
		 64, 64, 191, 128, 128, 127, 8, 148, 162, 193, 128, 127, 64, 
		64, 64, 64, 128, 127, 2, 140, 2, 127, 128, 127, 2, 4, 8, 127, 
		128, 62, 81, 73, 69, 62, 128, 127, 137, 137, 137, 134, 128, 
		62, 193, 81, 161, 94, 128, 127, 137, 25, 41, 70, 128, 70, 73, 
		73, 73, 49, 128, 1, 1, 127, 1, 1, 128, 191, 64, 64, 64, 191, 
		128, 143, 176, 64, 176, 143, 128, 191, 64, 188, 64, 191, 128, 
		227, 148, 8, 148, 227, 128, 7, 8, 112, 8, 7, 128, 97, 81, 73, 
		69, 67, 128, 127, 127, 193, 193, 193, 128, 2, 4, 8, 32, 64, 
		128, 193, 193, 193, 127, 127, 128, 4, 2, 1, 2, 4, 128, 64, 64,
		 64, 64, 64, 128 };

    static struct {
	integer1 e_1[384];
	} equiv_3 = { 192, 192, 192, 192, 192, 192, 192, 192, 47, 192, 192, 
		192, 192, 135, 192, 135, 192, 192, 20, 190, 20, 190, 20, 192, 
		46, 170, 255, 170, 58, 192, 99, 147, 136, 228, 99, 192, 123, 
		197, 235, 144, 233, 192, 192, 192, 135, 192, 192, 192, 192, 
		156, 34, 65, 65, 192, 192, 65, 65, 34, 156, 192, 136, 170, 
		156, 170, 136, 192, 136, 136, 190, 136, 136, 192, 192, 192, 
		80, 48, 192, 192, 136, 136, 136, 136, 136, 192, 192, 192, 96, 
		96, 192, 192, 160, 144, 136, 132, 130, 192, 190, 49, 49, 49, 
		190, 192, 192, 130, 255, 192, 192, 192, 66, 225, 209, 201, 
		198, 192, 33, 65, 201, 77, 51, 192, 24, 20, 18, 255, 144, 192,
		 39, 203, 197, 197, 57, 192, 60, 66, 201, 201, 48, 192, 129, 
		129, 249, 5, 3, 192, 54, 201, 201, 201, 54, 192, 6, 201, 201, 
		33, 30, 192, 192, 192, 27, 27, 192, 192, 192, 192, 43, 27, 
		192, 192, 136, 20, 34, 65, 192, 192, 34, 34, 34, 34, 34, 192, 
		192, 65, 34, 20, 136, 192, 130, 129, 89, 5, 130, 192, 190, 65,
		 221, 85, 223, 192, 126, 17, 17, 17, 126, 192, 255, 201, 201, 
		201, 54, 192, 190, 65, 65, 65, 34, 192, 255, 65, 65, 65, 190, 
		192, 255, 201, 201, 201, 65, 192, 255, 9, 9, 9, 129, 192, 190,
		 65, 65, 201, 249, 192, 255, 136, 136, 136, 255, 192, 192, 65,
		 255, 65, 192, 192, 160, 192, 192, 63, 192, 192, 255, 136, 20,
		 34, 65, 192, 255, 192, 192, 192, 192, 192, 255, 130, 12, 130,
		 255, 192, 255, 130, 132, 136, 255, 192, 190, 209, 201, 197, 
		190, 192, 255, 9, 9, 9, 6, 192, 190, 65, 209, 33, 222, 192, 
		255, 9, 153, 169, 198, 192, 198, 201, 201, 201, 177, 192, 129,
		 129, 255, 129, 129, 192, 63, 192, 192, 192, 63, 192, 15, 48, 
		192, 48, 15, 192, 63, 192, 60, 192, 63, 192, 99, 20, 136, 20, 
		99, 192, 135, 136, 240, 136, 135, 192, 225, 209, 201, 197, 
		195, 192, 255, 255, 65, 65, 65, 192, 130, 132, 136, 144, 160, 
		192, 65, 65, 65, 255, 255, 192, 132, 130, 129, 130, 132, 192, 
		96, 96, 96, 96, 96, 192 };

    static struct {
	integer1 e_1[384];
	} equiv_5 = { 0, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0, 0, 0, 14, 0, 14, 0, 0,
		 20, 62, 20, 62, 20, 0, 46, 42, 126, 42, 58, 0, 38, 22, 8, 
		100, 98, 0, 118, 74, 86, 32, 80, 0, 0, 0, 14, 0, 0, 0, 0, 0, 
		0, 60, 66, 0, 0, 66, 60, 0, 0, 0, 16, 84, 56, 84, 16, 0, 16, 
		16, 124, 16, 16, 0, 0, 0, 80, 48, 0, 0, 16, 16, 16, 16, 16, 0,
		 0, 96, 96, 0, 0, 0, 64, 32, 16, 8, 4, 0, 60, 66, 66, 66, 60, 
		0, 0, 68, 126, 64, 0, 0, 100, 82, 74, 74, 68, 0, 34, 74, 74, 
		78, 50, 0, 14, 8, 8, 126, 8, 0, 46, 74, 74, 74, 50, 0, 60, 74,
		 74, 74, 48, 0, 2, 2, 114, 10, 6, 0, 52, 74, 74, 74, 52, 0, 4,
		 74, 74, 74, 60, 0, 0, 0, 54, 54, 0, 0, 0, 0, 86, 54, 0, 0, 
		16, 40, 68, 0, 0, 0, 40, 40, 40, 40, 40, 0, 0, 0, 68, 40, 16, 
		0, 4, 2, 82, 10, 4, 0, 60, 66, 90, 90, 76, 0, 120, 20, 18, 20,
		 120, 0, 126, 74, 74, 74, 52, 0, 60, 66, 66, 66, 36, 0, 126, 
		66, 66, 66, 60, 0, 126, 74, 74, 66, 66, 0, 126, 10, 10, 2, 2, 
		0, 60, 66, 66, 82, 114, 0, 126, 8, 8, 8, 126, 0, 0, 66, 116, 
		66, 0, 0, 32, 64, 64, 64, 62, 0, 126, 8, 16, 36, 66, 0, 126, 
		64, 64, 64, 64, 0, 126, 4, 8, 4, 126, 0, 126, 4, 8, 48, 126, 
		0, 60, 66, 66, 66, 60, 0, 126, 10, 10, 10, 4, 0, 60, 66, 82, 
		34, 92, 0, 126, 10, 26, 42, 68, 0, 68, 74, 74, 74, 50, 0, 2, 
		2, 126, 2, 2, 0, 62, 64, 64, 64, 62, 0, 30, 32, 64, 32, 30, 0,
		 126, 32, 24, 32, 126, 0, 102, 16, 8, 16, 102, 0, 6, 8, 112, 
		8, 6, 0, 98, 82, 74, 66, 70, 0, 126, 66, 66, 0, 0, 0, 2, 4, 8,
		 16, 32, 0, 0, 0, 66, 66, 126, 0, 8, 4, 2, 4, 8, 0, 64, 64, 
		64, 64, 64, 0 };


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, k, ic, jc, num;
    static integer1 out[3024];
#define tbe1 ((integer1 *)&equiv_3)
#define tbe2 ((integer1 *)&equiv_3 + 192)
#define tb561 ((integer1 *)&equiv_5)
#define tb562 ((integer1 *)&equiv_5 + 192)
#define tbo1 ((integer1 *)&equiv_1)
#define tbo2 ((integer1 *)&equiv_1 + 192)
    static integer1 code[384]	/* was [6][64] */;
#define tabe ((integer1 *)&equiv_3)
#define tab56 ((integer1 *)&equiv_5)
#define tabo ((integer1 *)&equiv_1)
    static char infil[504];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), tapepn_(integer1 *, integer *), cprint_(char *, 
	    ftnlen);

    /* Fortran I/O blocks */
    static icilist io___15 = { 0, infil, 0, "(84A6)", 504, 1 };



/*  * PARNOM *  VAX-11 FORTRAN 77 VERSION  26.10.82  E.MCLELLAN */

/*  PURPOSE     PUNCH COLUMN BINARY MATRIX REPRESENTATION OF */
/*              CHARACTERS USED FOR PUNCH TAPE IDENTIFICATION */
/*  CALLING SEQUENCE */
/*              CALL PARNOM(N,A,J) */
/*  ARGUMENTS */
/*              N  NUMBER OF BCD CHARACTERS TO BE CONVERTED (MAX 504) */
/*              A  ARRAY CONTAINING BCD CHARACTERS TO BE CONVERTED */
/*                 FORMAT A6,2X (6 BCD CHARACTERS FOLLOWED BY 2 BLANKS) */
/*                 THE BLANKS  ARE IGNORED */
/*              J  J=0  5*7 MATRIX, COLUMN BINARY, ODD PARITY */
/*                  =1  IGNORED */
/*                  =2  5*6 MATRIX, COLUMN BINARY, NO PARITY */
/*  ALTERNATE ENTRY */
/*              CALL PARNEM(N,A) */
/*                   PUNCHES A 5*7 MATRIX,COLUMN BINARY,EVEN PARITY */

/*  NOTE:       THE ALLOWABLE CHARACTERS ARE 0 THRO 9, A THRU Z, */
/*              AND !"#$%&'()*+,-./:;<=>?@[\]^_ */
/*              IE THE COMPLETE ASCII CHARACTER SET LESS LOWER CASE */



/* ...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA */
/* ...ON OTHER SYSTEMS */



/* *****   TABLE FOR 5X7 MATRIX OUTPUT , ODD PARITY , COLUMN BINARY */

/*      DATA TBO1/ */
/*              BLANK                      ! */
/*     1Z80,Z80,Z80,Z80,Z80,Z80, Z80,Z80,Z5E,Z80,Z80,Z80, */
/* *                "                        # */
/*     2Z80,Z07,Z80,Z07,Z80,Z80, Z94,Z3E,Z94,Z3E,Z94,Z80, */
/* *                $                        % */
/*     3ZAE,Z2A,Z7F,Z2A,ZAE,Z80, ZE3,Z13,Z08,Z34,ZE3,Z80, */
/* *                &                        ` */
/*     4ZFB,Z45,Z6B,Z10,Z68,Z80, Z80,Z80,Z07,Z80,Z80,Z80, */
/* *                (                        ) */
/*     5Z80,Z1C,ZA2,ZC1,ZC1,Z80, Z80,ZC1,ZC1,ZA2,Z1C,Z80, */
/* *                *                        + */
/*     6Z08,Z2A,Z1C,Z2A,Z08,Z80, Z08,Z08,Z3E,Z08,Z08,Z80, */
/* *                ,                        - */
/*     7Z80,Z80,ZD0,ZB0,Z80,Z80, Z08,Z08,Z08,Z08,Z08,Z80, */
/* *                .                        / */
/*     8Z80,Z80,ZE0,ZE0,Z80,Z80, Z20,Z10,Z08,Z04,Z02,Z80, */
/* *                0                        1 */
/*     9Z3E,ZC1,ZC1,ZC1,Z3E,Z80, Z80,Z02,Z7F,Z80,Z80,Z80, */
/* *                2                        3 */
/*     AZC2,Z61,Z51,Z49,Z46,Z80, ZA1,ZC1,Z49,ZCD,ZB3,Z80, */
/* *                4                        5 */
/*     BZ98,Z94,Z92,Z7F,Z10,Z80, ZA7,Z45,Z45,Z45,ZB9,Z80, */
/* *                6                        7 */
/*     CZBC,ZC2,Z49,Z49,ZB0,Z80, Z01,Z01,Z79,Z85,Z83,Z80, */
/* *                8                        9 */
/*     DZB6,Z49,Z49,Z49,ZB6,Z80, Z86,Z49,Z49,ZA1,Z9E,Z80, */
/* *                :                        ; */
/*     EZ80,Z80,ZB6,ZB6,Z80,Z80, Z80,Z80,ZD6,ZB6,Z80,Z80, */
/* *                <                        = */
/*     FZ08,Z94,ZA2,ZC1,Z80,Z80, ZA2,ZA2,ZA2,ZA2,ZA2,Z80, */
/* *                >                        ? */
/*     GZ80,ZC1,ZA2,Z94,Z08,Z80, Z02,Z01,ZD9,Z85,Z02,Z80/ */
/*      DATA TBO2/ */
/* *                @                        A */
/*     1Z3E,ZC1,Z5D,ZD5,Z5E,Z80, ZFE,Z91,Z91,Z91,ZFE,Z80, */
/* *                B                        C */
/*     2Z7F,Z49,Z49,Z49,ZB6,Z80, Z3E,ZC1,ZC1,ZC1,ZA2,Z80, */
/* *                D                        E */
/*     3Z7F,ZC1,ZC1,ZC1,ZE3,Z80, Z7F,Z49,Z49,Z49,ZC1,Z80, */
/* *                F                        G */
/*     4Z7F,Z89,Z89,Z89,Z01,Z80, ZE3,ZC1,ZC1,Z49,Z79,Z80, */
/* *                H                        I */
/*     5Z7F,Z08,Z08,Z08,Z7F,Z80, Z80,ZC1,Z7F,ZC1,Z80,Z80, */
/* *                J                        K */
/*     6Z20,Z40,Z40,ZBF,Z80,Z80, Z7F,Z08,Z94,ZA2,ZC1,Z80, */
/* *                L                        M */
/*     7Z7F,Z40,Z40,Z40,Z40,Z80, Z7F,Z02,Z8C,Z02,Z7F,Z80, */
/* *                N                        O */
/*     8Z7F,Z02,Z04,Z08,Z7F,Z80, Z3E,Z51,Z49,Z45,Z3E,Z80, */
/* *                P                        Q */
/*     9Z7F,Z89,Z89,Z89,Z86,Z80, Z3E,ZC1,Z51,ZA1,Z5E,Z80, */
/* *                R                        S */
/*     AZ7F,Z89,Z19,Z29,Z46,Z80, Z46,Z49,Z49,Z49,Z31,Z80, */
/* *                T                        U */
/*     BZ01,Z01,Z7F,Z01,Z01,Z80, ZBF,Z40,Z40,Z40,ZBF,Z80, */
/* *                V                        W */
/*     CZ8F,ZB0,Z40,ZB0,Z8F,Z80, ZBF,Z40,ZBC,Z40,ZBF,Z80, */
/* *                X                        Y */
/*     DZE3,Z94,Z08,Z94,ZE3,Z80, Z07,Z08,Z70,Z08,Z07,Z80, */
/* *                Z                        [ */
/*     EZ61,Z51,Z49,Z45,Z43,Z80, Z7F,Z7F,ZC1,ZC1,ZC1,Z80, */
/* *                \                        ] */
/*     FZ02,Z04,Z08,Z20,Z40,Z80, ZC1,ZC1,ZC1,Z7F,Z7F,Z80, */
/* *                ^                        _ */
/*     GZ04,Z02,Z01,Z02,Z04,Z80, Z40,Z40,Z40,Z40,Z40,Z80/ */
/* ******   TABLE FOR 5X7 MATRIX OUTPUT ,EVEN PARITY , COLUMN BINARY */
/* * */
/*      DATA TBE1/ */
/* *              BLANK                      ! */
/*     1ZC0,ZC0,ZC0,ZC0,ZC0,ZC0, ZC0,ZC0,Z2F,ZC0,ZC0,ZC0, */
/* *                "                        # */
/*     2ZC0,Z87,ZC0,Z87,ZC0,ZC0, Z14,ZBE,Z14,ZBE,Z14,ZC0, */
/* *                $                        % */
/*     3Z2E,ZAA,ZFF,ZAA,Z3A,ZC0, Z63,Z93,Z88,ZE4,Z63,ZC0, */
/* *                &                        ` */
/*     4Z7B,ZC5,ZEB,Z90,ZE9,ZC0, ZC0,ZC0,Z87,ZC0,ZC0,ZC0, */
/* *                (                        ) */
/*     5ZC0,Z9C,Z22,Z41,Z41,ZC0, ZC0,Z41,Z41,Z22,Z9C,ZC0, */
/* *                *                        + */
/*     6Z88,ZAA,Z9C,ZAA,Z88,ZC0, Z88,Z88,ZBE,Z88,Z88,ZC0, */
/* *                ,                        - */
/*     7ZC0,ZC0,Z50,Z30,ZC0,ZC0, Z88,Z88,Z88,Z88,Z88,ZC0, */
/* *                .                        / */
/*     8ZC0,ZC0,Z60,Z60,ZC0,ZC0, ZA0,Z90,Z88,Z84,Z82,ZC0, */
/* *                0                        1 */
/*     9ZBE,Z31,Z31,Z31,ZBE,ZC0, ZC0,Z82,ZFF,ZC0,ZC0,ZC0, */
/* *                2                        3 */
/*     AZ42,ZE1,ZD1,ZC9,ZC6,ZC0, Z21,Z41,ZC9,Z4D,Z33,ZC0, */
/* *                4                        5 */
/*     6Z18,Z14,Z12,ZFF,Z90,ZC0, Z27,ZCB,ZC5,ZC5,Z39,ZC0, */
/* *                6                        7 */
/*     CZ3C,Z42,ZC9,ZC9,Z30,ZC0, Z81,Z81,ZF9,Z05,Z03,ZC0, */
/* *                8                        9 */
/*     DZ36,ZC9,ZC9,ZC9,Z36,ZC0, Z06,ZC9,ZC9,Z21,Z1E,ZC0, */
/* *                :                        ; */
/*     EZC0,ZC0,Z1B,Z1B,ZC0,ZC0, ZC0,ZC0,Z2B,Z1B,ZC0,ZC0, */
/* *                <                        = */
/*     FZ88,Z14,Z22,Z41,ZC0,ZC0, Z22,Z22,Z22,Z22,Z22,ZC0, */
/* *                >                        ? */
/*     GZC0,Z41,Z22,Z14,Z88,ZC0, Z82,Z81,Z59,Z05,Z82,ZC0/ */
/*      DATA TBE2/ */
/* *                @                        A */
/*     1ZBE,Z41,ZDD,Z55,ZDF,ZC0, Z7E,Z11,Z11,Z11,Z7E,ZC0, */
/* *                B                        C */
/*     2ZFF,ZC9,ZC9,ZC9,Z36,ZC0, ZBE,Z41,Z41,Z41,Z22,ZC0, */
/* *                D                        E */
/*     3ZFF,Z41,Z41,Z41,ZBE,ZC0, ZFF,ZC9,ZC9,ZC9,Z41,ZC0, */
/* *                F                        G */
/*     4ZFF,Z09,Z09,Z09,Z81,ZC0, ZBE,Z41,Z41,ZC9,ZF9,ZC0, */
/* *                H                        I */
/*     5ZFF,Z88,Z88,Z88,ZFF,ZC0, ZC0,Z41,ZFF,Z41,ZC0,ZC0, */
/* *                J                        K */
/*     6ZA0,ZC0,ZC0,Z3F,ZC0,ZC0, ZFF,Z88,Z14,Z22,Z41,ZC0, */
/* *                L                        M */
/*     7ZFF,ZC0,ZC0,ZC0,ZC0,ZC0, ZFF,Z82,Z0C,Z82,ZFF,ZC0, */
/* *              BLANK                      O */
/*     8ZFF,Z82,Z84,Z88,ZFF,ZC0, ZBE,ZD1,ZC9,ZC5,ZBE,ZC0, */
/* *                P                        Q */
/*     9ZFF,Z09,Z09,Z09,Z06,ZC0, ZBE,Z41,ZD1,Z21,ZDE,ZC0, */
/* *                R                        S */
/*     AZFF,Z09,Z99,ZA9,ZC6,ZC0, ZC6,ZC9,ZC9,ZC9,ZB1,ZC0, */
/* *                T                        U */
/*     BZ81,Z81,ZFF,Z81,Z81,ZC0, Z3F,ZC0,ZC0,ZC0,Z3F,ZC0, */
/* *                V                        W */
/*     CZ0F,Z30,ZC0,Z30,Z0F,ZC0, Z3F,ZC0,Z3C,ZC0,Z3F,ZC0, */
/* *                X                        Y */
/*     DZ63,Z14,Z88,Z14,Z63,ZC0, Z87,Z88,ZF0,Z88,Z87,ZC0, */
/* *                Z                        [ */
/*     EZE1,ZD1,ZC9,ZC5,ZC3,ZC0, ZFF,ZFF,Z41,Z41,Z41,ZC0, */
/* *                \                        ] */
/*     FZ82,Z84,Z88,Z90,ZA0,ZC0, Z41,Z41,Z41,ZFF,ZFF,ZC0, */
/* *                ^                        _ */
/*     GZ84,Z82,Z81,Z82,Z84,ZC0, Z60,Z60,Z60,Z60,Z60,ZC0/ */
/* ******   TABLE FOR 5X6 MATRIX OUTPUT , NO PARITY , COLUMN BINARY */
/* * */
/*      DATA TB561/ */
/* *                N                        ! */
/*     1Z00,Z00,Z00,Z00,Z00,Z00, Z00,Z00,Z5E,Z00,Z00,Z00, */
/* *                "                        # */
/*     2Z00,Z0E,Z00,Z0E,Z00,Z00, Z14,Z3E,Z14,Z3E,Z14,Z00, */
/* *                $                        % */
/*     3Z2E,Z2A,Z7E,Z2A,Z3A,Z00, Z26,Z16,Z08,Z64,Z62,Z00, */
/* *                &                        ` */
/*     4Z76,Z4A,Z56,Z20,Z50,Z00, Z00,Z00,Z0E,Z00,Z00,Z00, */
/* *                (                        ) */
/*     5Z00,Z00,Z00,Z3C,Z42,Z00, Z00,Z42,Z3C,Z00,Z00,Z00, */
/* *                *                        + */
/*     6Z10,Z54,Z38,Z54,Z10,Z00, Z10,Z10,Z7C,Z10,Z10,Z00, */
/* *                ,                        - */
/*     7Z00,Z00,Z50,Z30,Z00,Z00, Z10,Z10,Z10,Z10,Z10,Z00, */
/* *                .                        / */
/*     8Z00,Z60,Z60,Z00,Z00,Z00, Z40,Z20,Z10,Z08,Z04,Z00, */
/* *                0                        1 */
/*     9Z3C,Z42,Z42,Z42,Z3C,Z00, Z00,Z44,Z7E,Z40,Z00,Z00, */
/* *                2                        3 */
/*     AZ64,Z52,Z4A,Z4A,Z44,Z00, Z22,Z4A,Z4A,Z4E,Z32,Z00, */
/* *                4                        5 */
/*     BZ0E,Z08,Z08,Z7E,Z08,Z00, Z2E,Z4A,Z4A,Z4A,Z32,Z00, */
/* *                6                        7 */
/*     CZ3C,Z4A,Z4A,Z4A,Z30,Z00, Z02,Z02,Z72,Z0A,Z06,Z00, */
/* *                8                        9 */
/*     DZ34,Z4A,Z4A,Z4A,Z34,Z00, Z04,Z4A,Z4A,Z4A,Z3C,Z00, */
/* *                :                        ; */
/*     EZ00,Z00,Z36,Z36,Z00,Z00, Z00,Z00,Z56,Z36,Z00,Z00, */
/* *                <                        = */
/*     FZ10,Z28,Z44,Z00,Z00,Z00, Z28,Z28,Z28,Z28,Z28,Z00, */
/* *                >                        ? */
/*     GZ00,Z00,Z44,Z28,Z10,Z00, Z04,Z02,Z52,Z0A,Z04,Z00/ */
/*      DATA TB562/ */
/* *                @                        A */
/*     1Z3C,Z42,Z5A,Z5A,Z4C,Z00, Z78,Z14,Z12,Z14,Z78,Z00, */
/* *                B                        C */
/*     2Z7E,Z4A,Z4A,Z4A,Z34,Z00, Z3C,Z42,Z42,Z42,Z24,Z00, */
/* *                D                        E */
/*     3Z7E,Z42,Z42,Z42,Z3C,Z00, Z7E,Z4A,Z4A,Z42,Z42,Z00, */
/* *                F                        G */
/*     4Z7E,Z0A,Z0A,Z02,Z02,Z00, Z3C,Z42,Z42,Z52,Z72,Z00, */
/* *                H                        I */
/*     5Z7E,Z08,Z08,Z08,Z7E,Z00, Z00,Z42,Z74,Z42,Z00,Z00, */
/* *                J                        K */
/*     6Z20,Z40,Z40,Z40,Z3E,Z00, Z7E,Z08,Z10,Z24,Z42,Z00, */
/* *                L                        M */
/*     7Z7E,Z40,Z40,Z40,Z40,Z00, Z7E,Z04,Z08,Z04,Z7E,Z00, */
/* *                N                        O */
/*     8Z7E,Z04,Z08,Z30,Z7E,Z00, Z3C,Z42,Z42,Z42,Z3C,Z00, */
/* *                P                        Q */
/*     9Z7E,Z0A,Z0A,Z0A,Z04,Z00, Z3C,Z42,Z52,Z22,Z5C,Z00, */
/* *                R                        S */
/*     AZ7E,Z0A,Z1A,Z2A,Z44,Z00, Z44,Z4A,Z4A,Z4A,Z32,Z00, */
/* *                T                        U */
/*     BZ02,Z02,Z7E,Z02,Z02,Z00, Z3E,Z40,Z40,Z40,Z3E,Z00, */
/* *                V                        W */
/*     CZ1E,Z20,Z40,Z20,Z1E,Z00, Z7E,Z20,Z18,Z20,Z7E,Z00, */
/* *                X                        Y */
/*     DZ66,Z10,Z08,Z10,Z66,Z00, Z06,Z08,Z70,Z08,Z06,Z00, */
/* *                Z                        [ */
/*     EZ62,Z52,Z4A,Z42,Z46,Z00, Z7E,Z42,Z42,Z00,Z00,Z00, */
/* *                \                        ] */
/*     FZ02,Z04,Z08,Z10,Z20,Z00, Z00,Z00,Z42,Z42,Z7E,Z00, */
/* *                ^                        _ */
/*     GZ08,Z04,Z02,Z04,Z08,Z00, Z40,Z40,Z40,Z40,Z40,Z00/ */

/* ******************************************************* */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --a;

    /* Function Body */
    switch(n__) {
	case 1: goto L_parnem;
	}

/* *****   table for 5x7 matrix output ,even parity , column binary */
/* *****   table for 5x6 matrix output , no parity , column binary */

    if (*j == 0) {

/* .....5*7 MATRIX, ODD PARITY, COLUMN BINARY */

	for (i__ = 1; i__ <= 6; ++i__) {
	    for (k = 1; k <= 64; ++k) {
/* L10: */
		code[i__ + k * 6 - 7] = tabo[i__ + k * 6 - 7];
	    }
	}

    } else if (*j == 2) {

/* .....5*6 MATRIX, NO PARITY, COLUMN BINARY */

	for (i__ = 1; i__ <= 6; ++i__) {
	    for (k = 1; k <= 64; ++k) {
/* L20: */
		code[i__ + k * 6 - 7] = tab56[i__ + k * 6 - 7];
	    }
	}

    } else {
	cform_("**** INVALID CALL TO PARNOM ****", darray_1.darray, &c__2, &
		c__32, (ftnlen)32, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	return 0;
    }
    goto L100;

/* .....ENTRY PARNEM */


L_parnem:

/* .....5*7 MATRIX, EVEN PARITY, COLUMN BINARY */

    for (i__ = 1; i__ <= 6; ++i__) {
	for (k = 1; k <= 64; ++k) {
/* L30: */
	    code[i__ + k * 6 - 7] = tabe[i__ + k * 6 - 7];
	}
    }

/* .....CHECK N.LE.504 */

L100:
    *n = abs(*n);
    if (*n > 504) {
	cform_("**** MORE THAN 504 CHARACTERS", darray_1.darray, &c__2, &
		c__29, (ftnlen)29, (ftnlen)120);
	cform_("REQUESTED IN CALL TO PARNOM OR PARNEM ****", darray_1.darray, 
		&c__32, &c__42, (ftnlen)42, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	*n = 504;
    }

/* .....CALCULATE NUMBER OF WORDS CONTAINING CHARACTERS (6 PER WORD) */

    num = *n / 6;
    if (num * 6 < *n) {
	++num;
    }

/* .....WRITE CHARCTERS FOR CONVERSION TO INTERNAL FILE */

    s_wsfi(&io___15);
    i__1 = num;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfi();

/* .....FOR EACH CHARACTER INPUT, IDENTIFY POSITION IN ASCII CHAR SET */

    jc = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ic = *(unsigned char *)&infil[i__ - 1] - 31;

/* .....STORE APPROP MATRIX IN OUTPUT ARRAY */

	for (k = 1; k <= 6; ++k) {
	    ++jc;
	    out[jc - 1] = code[k + ic * 6 - 7];
/* L200: */
	}
    }

/* .....OUTPUT TO PUNCH FILE, JC IS NO OF BYTES */

    tapepn_(out, &jc);
    return 0;
} /* parnom_ */

#undef tabo
#undef tab56
#undef tabe
#undef tbo2
#undef tbo1
#undef tb562
#undef tb561
#undef tbe2
#undef tbe1


/* Subroutine */ int parnom_(integer *n, doublereal *a, integer *j)
{
    return parnom_0_(0, n, a, j);
    }

/* Subroutine */ int parnem_(integer *n, doublereal *a)
{
    return parnom_0_(1, n, a, (integer *)0);
    }

