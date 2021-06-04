/* SVCOPY.f -- translated by f2c (version 20100827).
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
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

/* *** SOURCE FILE : SVCOPY00.ORG   *** */

/* Subroutine */ int svcopy_(integer *i__, integer *j)
{
    static integer k;




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */





    for (k = 1; k <= 3; ++k) {
	sv_1.cc[k + *j * 3 - 4] = sv_1.cc[k + *i__ * 3 - 4];
	sv_1.plnv[k + *j * 3 - 4] = sv_1.plnv[k + *i__ * 3 - 4];
	sv_1.sfvct[k + *j * 3 - 4] = sv_1.sfvct[k + *i__ * 3 - 4];
	sv_1.slx[k + *j * 3 - 4] = sv_1.slx[k + *i__ * 3 - 4];
	sv_1.sn[k + *j * 3 - 4] = sv_1.sn[k + *i__ * 3 - 4];
	sv_1.snk[k + *j * 3 - 4] = sv_1.snk[k + *i__ * 3 - 4];
	sv_1.snl[k + *j * 3 - 4] = sv_1.snl[k + *i__ * 3 - 4];
	sv_1.sp[k + *j * 3 - 4] = sv_1.sp[k + *i__ * 3 - 4];
	sv_1.spk[k + *j * 3 - 4] = sv_1.spk[k + *i__ * 3 - 4];
	sv_1.spl[k + *j * 3 - 4] = sv_1.spl[k + *i__ * 3 - 4];
	sv_1.tn[k + *j * 3 - 4] = sv_1.tn[k + *i__ * 3 - 4];
	sv_1.toolht[k + *j * 3 - 4] = sv_1.toolht[k + *i__ * 3 - 4];
	sv_1.tp[k + *j * 3 - 4] = sv_1.tp[k + *i__ * 3 - 4];
	sv_1.tpk[k + *j * 3 - 4] = sv_1.tpk[k + *i__ * 3 - 4];
	sv_1.u1[k + *j * 3 - 4] = sv_1.u1[k + *i__ * 3 - 4];
	sv_1.vndir[k + *j * 3 - 4] = sv_1.vndir[k + *i__ * 3 - 4];
	sv_1.vt[k + *j * 3 - 4] = sv_1.vt[k + *i__ * 3 - 4];
	sv_1.u1k[k + *j * 3 - 4] = sv_1.u1k[k + *i__ * 3 - 4];
	sv_1.sk[k + *j * 3 - 4] = sv_1.sk[k + *i__ * 3 - 4];
/* L10: */
    }
    sv_1.eps1[*j - 1] = sv_1.eps1[*i__ - 1];
    sv_1.eps2[*j - 1] = sv_1.eps2[*i__ - 1];
    sv_1.eps3[*j - 1] = sv_1.eps3[*i__ - 1];
    sv_1.eps4[*j - 1] = sv_1.eps4[*i__ - 1];
    sv_1.eps6[*j - 1] = sv_1.eps6[*i__ - 1];
    sv_1.eps8[*j - 1] = sv_1.eps8[*i__ - 1];
    sv_1.past[*j - 1] = sv_1.past[*i__ - 1];
    sv_1.plnd[*j - 1] = sv_1.plnd[*i__ - 1];
    sv_1.rc[*j - 1] = sv_1.rc[*i__ - 1];
    sv_1.s[*j - 1] = sv_1.s[*i__ - 1];
    sv_1.save[*j - 1] = sv_1.save[*i__ - 1];
    sv_1.tau[*j - 1] = sv_1.tau[*i__ - 1];
    sv_1.tau1[*j - 1] = sv_1.tau1[*i__ - 1];
    sv_1.tau2[*j - 1] = sv_1.tau2[*i__ - 1];
    sv_1.th[*j - 1] = sv_1.th[*i__ - 1];
    sv_1.toolwd[*j - 1] = sv_1.toolwd[*i__ - 1];
    sv_1.z__[*j - 1] = sv_1.z__[*i__ - 1];
    sv_1.varble[*j - 1] = sv_1.varble[*i__ - 1];

    return 0;
} /* svcopy_ */

