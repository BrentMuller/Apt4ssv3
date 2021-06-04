/* ISVCPY.f -- translated by f2c (version 20100827).
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
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

/* *** SOURCE FILE : ISVCPY00.ORG   *** */

/* Subroutine */ int isvcpy_(integer *i__, integer *j)
{



/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */





    isv_1.iafl[*j - 1] = isv_1.iafl[*i__ - 1];
    isv_1.icanon[*j - 1] = isv_1.icanon[*i__ - 1];
    isv_1.index[*j - 1] = isv_1.index[*i__ - 1];
    isv_1.indir__[*j - 1] = isv_1.indir__[*i__ - 1];
    isv_1.iop[*j - 1] = isv_1.iop[*i__ - 1];
    isv_1.iopset[*j - 1] = isv_1.iopset[*i__ - 1];
    isv_1.ipl[*j - 1] = isv_1.ipl[*i__ - 1];
    isv_1.isfidn[*j - 1] = isv_1.isfidn[*i__ - 1];
    isv_1.isftyp[*j - 1] = isv_1.isftyp[*i__ - 1];
    isv_1.isigcr[*j - 1] = isv_1.isigcr[*i__ - 1];
    isv_1.isvfl[*j - 1] = isv_1.isvfl[*i__ - 1];
    isv_1.itlon[*j - 1] = isv_1.itlon[*i__ - 1];
    isv_1.itseg[*j - 1] = isv_1.itseg[*i__ - 1];
    isv_1.iunfl[*j - 1] = isv_1.iunfl[*i__ - 1];
    isv_1.jent[*j - 1] = isv_1.jent[*i__ - 1];
    isv_1.jiops[*j - 1] = isv_1.jiops[*i__ - 1];
    isv_1.jtlflg[*j - 1] = isv_1.jtlflg[*i__ - 1];
    isv_1.jtn[*j - 1] = isv_1.jtn[*i__ - 1];
    isv_1.ju1[*j - 1] = isv_1.ju1[*i__ - 1];
    isv_1.limfl[*j - 1] = isv_1.limfl[*i__ - 1];
    isv_1.itsegk[*j - 1] = isv_1.itsegk[*i__ - 1];

    return 0;
} /* isvcpy_ */

