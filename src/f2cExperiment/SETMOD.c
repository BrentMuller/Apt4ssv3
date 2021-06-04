/* SETMOD.f -- translated by f2c (version 20100827).
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
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

/* *** SOURCE FILE : M0006686.V03   *** */


/*              FORTRAN SUBROUTINE SETMOD */

/* LINKAGE      SUBROUTINE SETMOD(PNTR,CLASS) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    LARGES */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */

/* Subroutine */ int setmod_(integer *pntr, integer *class__)
{
    /* Local variables */
    static integer i__, j;
#define fcn ((integer *)&code_1 + 34)
#define meta ((integer *)&srctbl_1 + 2)
#define geom ((integer *)&code_1 + 30)
#define stack ((integer *)&stklst_1 + 3)
#define biggeo ((integer *)&code_1 + 86)
#define proced ((integer *)&code_1 + 36)
#define permid ((integer *)&code_1 + 38)
#define modulo ((integer *)&moduli_1)



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        2.    STACK AND POINTER STORAGE */







/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* GEOM:        (1)=CODE CLASS 16000,(2)=NAMTBL INDEX OF 'GEOM  ' */
/* FCN:         (1)=CODE CLASS 18000,(2)=NAMTBL INDEX OF 'FCN   ' */
/* PROCED:      (1)=CODE CLASS 19000,(2)=NAMTBL INDEX OF 'PROCED' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* BIGGEO:      (1)=CODE CLASS 44000,(2)=NAMTBL INDEX OF 'BIGGEO' */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* * */
/* ARGUMENTS    PNTR      WORKING STACK (STACK) POINTER OF */
/*                        ITEM WHOSE CLASS IS TO BE CHANGED. */
/*              CLASS     NEW META-LINQUISTIC CLASS ASSIGNMENT. */

/* NOTES        IF CLASS IS PERMID, PROCED, OR GEOM, IT IS */
/*              ASSUMED THAT PREVIOUS CLASS WAS IDENT, CONPRO, */
/*              OR CONGEO, RESPECTIVELY, IN WHICH CASE THE */
/*              ORIGINAL MODE IS RETAINED. */

/*     CHANGE THE CLASS OF A CHARACTER */
/* ** */
    /* Parameter adjustments */
    --class__;

    /* Function Body */
    i__ = stack[(*pntr << 1) - 2];
    j = class__[1];
    if (j == permid[0] || j == geom[0] || j == biggeo[0] || j == proced[0]) {
	goto L1;
    }
    if (j == fcn[0]) {
	goto L1;
    }
    nametb_1.namtbl[i__ - 1] = j;
    goto L2;
L1:
    nametb_1.namtbl[i__ - 1] = j + (nametb_1.namtbl[i__ - 1] - *modulo * (
	    nametb_1.namtbl[i__ - 1] / *modulo));
L2:
    j /= *modulo;
    stack[(*pntr << 1) - 1] = meta[j - 1];
    return 0;
} /* setmod_ */

#undef modulo
#undef permid
#undef proced
#undef biggeo
#undef stack
#undef geom
#undef meta
#undef fcn


