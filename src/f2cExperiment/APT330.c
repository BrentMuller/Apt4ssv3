/* APT330.f -- translated by f2c (version 20100827).
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
    doublereal editor[1500];
} editor_;

#define editor_1 editor_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__7 = 7;
static integer c__8 = 8;
static integer c__15 = 15;
static integer c__4 = 4;
static integer c__13 = 13;
static integer c__6 = 6;

/* *** SOURCE FILE : M0000607.V02   *** */



/* .....  FORTRAN SUBROUTINE  APT330 */
/*  PURPOSE     TO PRINT DYNDMP INFORMATION */
/*  LINKAGE     CALL APT330 (J,N(1),N(2),N(3),N(4)) */

/*  ARGUMENTS   J     INDEX TO POINT SUBROUTINE NAME AND DYNDMP NUMBER. */
/*                    IF J IS -1, IT INDICATES CONTINUATION CALL. */
/*              N(K)  INDEX TO POINT PARAMETER NAME AND ITS VALUE. */

/* Subroutine */ int apt330_(integer *j, integer *n1, integer *n2, integer *
	n3, integer *n4)
{
    /* Initialized data */

    static char hdynd[8] = "DYNDMP  ";
    static struct {
	char fill_1[8];
	char e_2[8];
	char fill_3[8];
	char e_4[1024];
	} equiv_15 = { {0}, "NUMBER= ", {0}, "DP=     DPI=    FLIPCK= IAMDCT"
		"= IAUTPS= INOPS=  IS=     IT=     IWS=    JCKR=   JCR=    JD"
		"R=    JPR=    JPXR=   NUMPT1= NUMSUR= VL=     TA(1)=  TA(2)="
		"  TA(3)=  TAK(1)= TAK(2)= TAK(3)= TAL(1)= TAL(2)= TAL(3)= TE"
		"(1)=  TE(2)=  TE(3)=  TEK(1)= TEK(2)= TEK(3)= TEL(1)= TEL(2)"
		"= TEL(3)= TI(1)=  TI(2)=  TI(3)=  TIK(1)= TIK(2)= TIK(3)= CP"
		"LFL=  CPTST=  CSD=    IFAR=   INDIR=  IOPSET= ISFTYP= ISIGCR"
		"= ISVFL=  J23=    JENT=   JTN=    JU1=    PLND=   PLND1=  PL"
		"TST=  RC=     S=      STCK=   STCK1=  STCK2=  STCKN=  TAU1= "
		"  TAU2=   TH=     Z=      CC(1)=  CC(2)=  CC(3)=  PLNV(1)=PL"
		"NV(2)=PLNV(3)=SN(1)=  SN(2)=  SN(3)=  SP(1)=  SP(2)=  SP(3)="
		"  SPL(1)= SPL(2)= SPL(3)= TEE(1)= TEE(2)= TEE(3)= TN(1)=  TN"
		"(2)=  TN(3)=  TP(1)=  TP(2)=  TP(3)=  VNDIR(1)VNDIR(2)VNDIR("
		"3)VT(1)=  VT(2)=  VT(3)=  ISGCRT= RCT=    ST=     ZT=     CC"
		"T(1)= CCT(2)= CCT(3)= SNT(1)= SNT(2)= SNT(3)= SPT(1)= SPT(2)"
		"= SPT(3)= SPLT(1)=SPLT(2)=SPLT(3)=SPKIPS 1SPKIPS 2SPKIPS 3TP"
		"KIPS 1TPKIPS 2TPKIPS 3SPKIDS 1SPKIDS 2SPKIDS 3TPKIDS 1TPKIDS"
		" 2TPKIDS 3CMOVE(1)CMOVE(2)CMOVE(3)" };

#define name__ ((char *)&equiv_15)

    static struct {
	char e_1[56];
	char fill_2[24];
	char e_3[136];
	char fill_4[24];
	char e_5[32];
	char fill_6[48];
	char e_7[40];
	char fill_8[32];
	char e_9[8];
	} equiv_16 = { "AJUNDD( AJUNDD( AMIND ( AMIND ( AMIND ( AMIND ( AMIN"
		"D ( ", {0}, "ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ("
		" ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARLM3 ( ARL"
		"M3 ( ARLM3 ( ARLM3 ( ARLM3 ( ", {0}, "CENTR ( CENTR ( CENTR "
		"( CPLAN ( ", {0}, "GO    ( GO    ( GO    ( GO    ( GO    ( ", 
		{0}, "BRKPNT( " };

#define subnam ((char *)&equiv_16)

    static struct {
	char e_1[28];
	char fill_2[12];
	char e_3[68];
	char fill_4[12];
	char e_5[16];
	char fill_6[24];
	char e_7[20];
	char fill_8[16];
	char e_9[4];
	} equiv_17 = { "101)102)103)104)105)106)107)", {0}, "201)202)203)204"
		")205)206)207)208)209)210)211)212)213)214)215)216)217)", {0}, 
		"401)402)403)404)", {0}, "501)502)503)504)505)", {0}, "999)" }
		;

#define nmb ((char *)&equiv_17)


    /* Local variables */
    static integer i__, k, l, m;
#define ed ((doublereal *)&editor_1)
    static integer ii, kk, nn[4];
#define ied ((integer *)&editor_1)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen), iconv_(integer *, char *, integer *, 
	    integer *, ftnlen), cprint_(char *, ftnlen);




/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    if (*j == -1) {
	goto L10;
    }
    cform_(hdynd, darray_1.darray, &c__1, &c__7, (ftnlen)8, (ftnlen)120);
    cform_(subnam + (*j - 1 << 3), darray_1.darray, &c__8, &c__7, (ftnlen)8, (
	    ftnlen)120);
    cform_(nmb + (*j - 1 << 2), darray_1.darray, &c__15, &c__4, (ftnlen)4, (
	    ftnlen)120);
    m = 4;
L10:
    l = 21;
    nn[0] = *n1;
    nn[1] = *n2;
    nn[2] = *n3;
    nn[3] = *n4;
    for (i__ = 1; i__ <= 4; ++i__) {
	l += 2;
	k = nn[i__ - 1];
	if (k == 0) {
	    goto L200;
	}
	ii = abs(k);
	cform_(name__ + (ii - 1 << 3), darray_1.darray, &l, &c__8, (ftnlen)8, 
		(ftnlen)120);
	l += 8;
	if (k < 0) {
	    goto L50;
	}
	fconv_(&ed[m - 1], darray_1.darray, &l, &c__13, &c__6, (ftnlen)120);
	l += 13;
	goto L100;
L50:
	l += 2;
	kk = (m << 1) - 1;
	iconv_(&ied[kk - 1], darray_1.darray, &l, &c__8, (ftnlen)120);
	l += 11;
L100:
	++m;
    }
L200:
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
} /* apt330_ */

#undef area3
#undef ied
#undef ed
#undef nmb
#undef subnam
#undef name__


