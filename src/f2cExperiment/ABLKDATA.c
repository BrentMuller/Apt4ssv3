/* ABLKDATA.f -- translated by f2c (version 20100827).
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

struct a0con_1_ {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
};

#define a0con_1 (*(struct a0con_1_ *) &a0con_)

struct ataptb_1_ {
    integer i__[23];
};

#define ataptb_1 (*(struct ataptb_1_ *) &ataptb_)

struct asistm_1_ {
    integer j[22];
};

#define asistm_1 (*(struct asistm_1_ *) &asistm_)

struct apostp_1_ {
    doublereal p[40];
};

#define apostp_1 (*(struct apostp_1_ *) &apostp_)

struct atime_1_ {
    doublereal t[4];
};

#define atime_1 (*(struct atime_1_ *) &atime_)

struct aoutfg_1_ {
    integer iflag;
};

#define aoutfg_1 (*(struct aoutfg_1_ *) &aoutfg_)

/* Initialized data */

struct {
    integer e_1[13];
    char e_2[4];
    } a0con_ = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, "    " };

struct {
    integer e_1[23];
    } ataptb_ = { 0, 6, 0, 6, 0, 3, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 4, 0, 6, 
	    5, 6, 7 };

struct {
    integer e_1[22];
    } asistm_ = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0 };

struct {
    doublereal e_1[40];
    } apostp_ = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0. };

struct {
    doublereal e_1[4];
    } atime_ = { 0., 0., 0., 0. };

struct {
    integer e_1;
    } aoutfg_ = { 0 };




/* ....    FORTRAN BLOCK DATA ROUTINE...   ABLKDATA...     12/69   RC */
/* Subroutine */ int ablk_(void)
{
    return 0;
} /* ablk_ */


/* ...     COMMON AREAS FROM SYSTEM 360 APT */


