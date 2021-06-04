/* RESRVZ.f -- translated by f2c (version 20100827).
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
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer first[6]	/* was [2][3] */;
} blkcfs_;

#define blkcfs_1 blkcfs_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0006679.W01   *** */


/*              FORTRAN SUBROUTINE RESRVZ */

/* LINKAGE      SUBROUTINE RESRVZ(INDEX,MODE,ISIZE,NNNBER) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          INTEGER FCT.  NAME            INTEGER FCT.  GETTMP */
/*          SUBROUTINE    OPCODE          SUBROUTINE    GOPAT */
/*          SUBROUTINE    RLSLIN          SUBROUTINE    INPAT */
/*          SUBROUTINE    TWOARG          SUBROUTINE    LARGES */
/*                                        SUBROUTINE    LCANON */
/*                                        SUBROUTINE    MACREC */
/*                                        SUBROUTINE    PRO020 */
/*                                        SUBROUTINE    PRO026 */
/*                                        SUBROUTINE    PRO027 */
/*                                        SUBROUTINE    RECOG */
/*                                        SUBROUTINE    RECOGN */
/*                                        SUBROUTINE    REPLAC */
/*                                        SUBROUTINE    RESRED */
/*                                        SUBROUTINE    SSDEF */

/* Subroutine */ int resrvz_(integer *index, integer *mode, integer *isize, 
	integer *nnnber)
{
    /* Initialized data */

    static char dlrblk[6*3] = "      " "$$BLK2" "$$BLK3";

    /* Local variables */
    static integer i__, md;
#define vbl ((integer *)&code_1 + 60)
    extern integer name_(char *, ftnlen);
#define real__ ((integer *)&modx_1 + 20)
#define bool ((integer *)&modx_1 + 22)
    static integer block;
#define resrv ((integer *)&il_1 + 11)
    extern /* Subroutine */ int opcode_(integer *), twoarg_(integer *, 
	    integer *), rlslin_(void);



/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */







/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* RESRV:       CONTAINS COMMAND CODE (12) FOR RESRV COMMAND */

/*       17.    MODE CODES */

/* REAL:        MODE CODE (21) FOR A SCALAR */
/* BOOL:        MODE CODE (23) FOR BOOLEAN TYPE */

/*       30.    NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK */

/* * */
/* ARGUMENT     INDEX     NAME TABLE (NAMTBL) INDEX OF */
/*                        VARIABLE FOR WHICH OBJECT TIME */
/*                        CANONICAL FORM SPACE IS BEING ALLOCATED. */
/*              MODE      MODE OF VARIABLE. */
/*              ISIZE     NUMBER OF ELEMENTS IN CANONICAL FORM */
/*                        EXCLUDING SUBSCRIPT AND BCD NAME. */
/*              NNNBER    UPPER SUBSCRIPT LIMIT (1 IF NON- */
/*                        SUBSCRIPTED VARIABLE). */

/* ** */
/* ... DETERMINE WHICH BLOCK THE VARIABLE BELONGS IN */

    block = 4;
    md = *mode;
    if (md == *bool) {
	md = *real__;
    }
    if (md == *real__ && *nnnber == 1) {
	block = 1;
    }
    if (md == *real__ && *nnnber > 1) {
	block = 2;
    }
    if (md < *real__ && md > 0 || md >= 24) {
	block = 3;
    }

    if (block != 2 || blkcfs_1.first[3] != 0) {
	goto L5;
    }
/* ... PUT FIRST ITEM IN CANONICAL FORM BLOCK 2. */
    i__ = name_(dlrblk + 6, (ftnlen)6);
    nametb_1.namtbl[i__ - 1] = vbl[0] + *mode;
    opcode_(resrv);
    twoarg_(&i__, mode);
    twoarg_(&c__1, &c__2);
    rlslin_();
    blkcfs_1.first[2] = i__;
    blkcfs_1.first[3] = 1;

L5:
    opcode_(resrv);
    twoarg_(index, mode);
    twoarg_(isize, nnnber);
    rlslin_();
    if (block == 4) {
	goto L20;
    }
/* ... IF FIRST CANONICAL FORM FOR THIS BLOCK, SAVE NAMTBL INDEX. */
    if (blkcfs_1.first[(block << 1) - 1] != 0) {
	goto L10;
    }
    blkcfs_1.first[(block << 1) - 2] = *index;
/* ... INCREMENT COUNT OF NUMBER OF FORMS IN THIS BLOCK */

L10:
    blkcfs_1.first[(block << 1) - 1] += *nnnber;
L20:
    return 0;
} /* resrvz_ */

#undef resrv
#undef bool
#undef real__
#undef vbl


