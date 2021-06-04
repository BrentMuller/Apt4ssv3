/* XNUMBR.f -- translated by f2c (version 20100827).
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
    integer ntb, fpb, ppb, comn, cfb, nblk, nrecrd[10], ntparm[10];
} stor_;

#define stor_1 stor_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* *** SOURCE FILE : M0000989.V05   *** */


/* -------- FORTRAN SUBROUTINE... XNUMBR           R.COLLINS  4/16/70 */

/* Subroutine */ int xnumbr_(integer *ipntr)
{
    /* Local variables */
    static integer l;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
    static integer ir;
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer jrec;
    extern /* Subroutine */ int fread_(integer *, integer *, doublereal *, 
	    integer *, integer *);
#define ipage ((integer *)&stor_1 + 20)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer ipmod;
#define numod ((integer *)&stor_1 + 17)
    static integer nstrt;
#define ndaflg ((integer *)&stor_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define nrecst ((integer *)&stor_1 + 19)
#define numbst ((integer *)&stor_1 + 16)



/* -----PURPOSE.......TO PROVIDE ACCESS TO THE NUMBER TABLE VALUES WHEN */
/*                   PASSED ON DIRECT ACCESS FILE FROM THE TRANSLATOR */

/* -----ARGUMENTS.....IPNTR - VIRTUAL POINTER TO NUMBER TABLE VALUE - */
/*                   CHANGED TO ACTUAL POINTER TO VALUE UPON EXIT */

/* -----CALLED BY.....GET, LIB */

/* -----SUBSIDIARIES..NONE */

/* -----DIAGNOSTICS...NONE */



/* --------**** COMMON AREAS NEEDED FOR THIS ROUTINE **** */

/* --------UNLABELED COMMON - COM */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/* STOR--COMMON CONTAINING STORAGE PARAMETERS */

/*     ------------------- */


/*   ADDITIONAL STOR PARAMETERS USED FOR NUMBER TABLE DIRECT ACCESS */



/* ...  20. SYSTEM I/O FILE NAMES */


/*  ------------------------------------------------------------------ */

/* --------CALCULATE VIRTUAL PAGE POINTER AND ACTUAL NUMBER TABLE */
/* --------POINTER USING CURRENT VIRTUAL NUMBER TABLE POINTER */


/* ...                SYSTEM I/O FILES */



    if (*ipntr < *numbst) {
	goto L999;
    }
    ipmod = (*ipntr - *numbst) / *numod + 1;
    *ipntr -= (ipmod - 1) * *numod;

/* --------IF NEW PAGE IS CURRENTLY IN COMMON AREA - RETURN */
    if (ipmod == *ipage) {
	goto L999;
    }


    jrec = (ipmod << 1) - 1;
    nstrt = stor_1.ntb + *numbst;
    l = *numod / 2;
    fread_(&symfil_1.xnum, &jrec, &fp[nstrt - 1], &l, &ir);
    nstrt += l;
    ++jrec;
    fread_(&symfil_1.xnum, &jrec, &fp[nstrt - 1], &l, &ir);

/* --------SET CURRENT PAGE POINTER AND RETURN */
    *ipage = ipmod;
L999:
    return 0;
} /* xnumbr_ */

#undef numbst
#undef nrecst
#undef bcanon
#undef ndaflg
#undef numod
#undef sscan
#undef canon
#undef ipage
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


