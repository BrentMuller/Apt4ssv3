/* CNVRT3.f -- translated by f2c (version 20100827).
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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer ivtflg, is, ir, il, ie, jsuber, iabove, nrecex, nreccl, ncflsv;
} i5axis_;

#define i5axis_1 i5axis_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__8 = 8;
static integer c__30030 = 30030;
static integer c__2 = 2;
static integer c__30038 = 30038;
static integer c__3 = 3;

/* *** SOURCE FILE : M0011539.W03   *** */


/* ......    FORTRAN SUBROUTINE CNVRT3    11/69    RC */
/* .....FORTRAN SUBROUTINE                CNVRT3...            8/1/68  AR */
/* PURPOSE          TO CONVERT EXFILE RECORDS INTOAPTIII FORMAT AND */
/*                  WRITE THEM ON CLFIL3. */

/* CALLING SEQUENCE CALL CNVRT3(MLTFLG) */

/* ARGUMENTS        MLTFLG     MULTAX FLAG-0,IF OFF */
/*                                         1,IF ON */

/* CALLED BY        APT301 */

/* SUBSIDIARIES     NONE */

/* DIAGNOSTICS      ERROR CODE   COMMENT */
/*                  ----------   ------- */
/*                               UNIDENTIFIED POSTPROCESSOR COMMAND--- */
/*                               XXXXXX. SEQUENCE NO. NNNNNN. */

/*                               UNIDENTIFIED MODIFIER--- XXXXXX. */
/*                               SEQUENCE NO. NNNNNN. */

/* METHOD           THE CURRENT EXFILE RECORD IN THE RECORD ARRAY IS */
/*                  EXAMINED AND THE APPROPRIATE APTIII CLTAPE RECORDS */
/*                  ARE WRITTEN ON CLFIL3. */

/* ********************************************************************* */

/* Subroutine */ int cnvrt3_(integer *mltflg)
{
    /* Initialized data */

    static char rectyp[6*10] = "FINI  " "AERR  " "GERR  " "MULTAX" "CLDATA" 
	    "CLPRNT" "CLDAT " "      " "      " "      ";
    static char splwds[6*20] = "CUT   " "2DCALC" "******" "INTOL " "OUTTOL" 
	    "CUTTER" "******" "******" "DYNDMP" "******" "DNTCUT" "3DCALC" 
	    "TOLER " "THICK " "MAXDP " "NUMPTS" "GOUGCK" "POCKET" "******" 
	    "******";
    static char ppname[6*22] = "END   " "STOP  " "OPSTOP" "ISTOP " "RAPID " 
	    "SWITCH" "RETRCT" "DRESS " "PICKUP" "UNLOAD" "PENUP " "PENDWN" 
	    "ZERO  " "CODEL " "RESET " "GOCLER" "DRAWLI" "PROBY " "PROBX " 
	    "ULOCKX" "LOCKX " "FACEML";
    static char pp2[6*2] = "GOHOME" "BREAK ";
    static integer ipp2[2] = { 14,17 };
    static char pm2[6*8] = "DELETE" "PPLOT " "WRTMDI" "ENDMDI" "POSMAP" "DEB"
	    "UGG" "LINTOL" "******";
    static integer ipm2[8] = { 1012,1014,1051,1052,1068,1032,1067,0 };
    static char par4[6*7] = "PITCH " "RAIL  " "FULL  " "SAVMDI" "SAVTDI" 
	    "MMPM  " "MMPR  ";
    static integer ipar4[7] = { 67,93,147,398,396,171,172 };
    static integer ircold = -1;
    static char off[6] = "OFF   ";
    static logical multax = FALSE_;
    static char from[6] = "FROM  ";
    static integer nnn = 0;
    static char scalin[8*4] = "MM      " "CM      " "INCHES  " "FEET    ";
    static char scalwd[6] = "UNITS ";
    static integer i3000 = 0;
    static struct {
	char e_1[1200];
	} equiv_13 = { "ATANGLCENTERCROSS FUNOFYINTOF INVERSLARGE LEFT  LENG"
		"THMINUS NEGX  NEGY  NEGZ  NOX   NOY   NOZ   PARLELPERPTOPLUS"
		"  POSX  POSY  POSZ  RADIUSRIGHT SCALE SMALL TANTO TIMES TRAN"
		"SLUNIT  XLARGEXSMALLXYPLANXYROT YLARGEYSMALLYZPLANYZROT ZLAR"
		"GEZSMALLZXPLANZXROT 3PT2SL4PT1SL5PT   INTERCSLOPE IN    OUT "
		"  OPEN  ALL   LAST  NOMORESAME  MODIFYMIRRORSTART ENDARCCCLW"
		"  CLW   MEDIUMHIGH  LOW   CONST DECR  INCR  GRID  ROTREFTO  "
		"  PAST  ON    OFF   IPM   IPR   CIRCULLINEARPARAB RPM   MAXR"
		"PMTURN  FACE  BORE  BOTH  XAXIS YAXIS ZAXIS NORMDSAUTO  FLOO"
		"D MIST  TAPKULSTEP  MAIN  SIDE  LINCIRMAXIPMREV   TYPE  NIXI"
		"E LIGHT FOURPTTWOPT PTSLOPPTNORMSPLINERTHETATHETARXYZ   TANO"
		"N TRFORMNORMALUP    DOWN  LOCK  SFM   XCOORDYCOORDZCOORDMULT"
		"RDXYVIEWYZVIEWZXVIEWSOLID DASH  DOTTEDCTRLINDITTO PEN   SCRI"
		"BEBLACK RED   GREEN BLUE  INTENSLITE  MED   DARK  CHUCK COLL"
		"ETAAXIS BAXIS CAXIS TPI   OPTIONRANGE PSTAN RANDOMFRONT REAR"
		"  SADDLEMILL  THRU  DEEP  TRAV  SETOOLSETANGHOLDERMANUALADJU"
		"STCUTANGNOW   NEXT  DRILL BINARYBCD   PART  REAM  TAP   CAM "
		"  NOCLRPREGTOLTRAVEDMAXWD MAXLNGSPIRALANTSPIZIGZAGNOBND MAXP"
		"TSGAPLES**181*ARC    *183*RETAINZIGZAGOMIT  AVOID  *188*AT  "
		"   *190* *191* *192* *193* *194* *195$ *196* *197* *198* *19"
		"9* *200*" };

    static struct {
	char e_1[8];
	} equiv_16 = { "        " };

    static struct {
	integer fill_1[1];
	integer e_2;
	doublereal fill_3[3];
	doublereal e_4;
	} equiv_7 = { {0}, 1000, {0}, 0. };

    static struct {
	char e_1[600];
	} equiv_9 = { "PLUNGEHEAD  MODE  CLEARPTMARK REWINDCUTCOMREVERSFEDRA"
		"TDELAY AIR   OPSKIPLEADERPPLOT MACHINMCHTOLPIVOTZMCHFINSEQNO"
		" INTCODDISPLYAUXFUNCHECK POSTN TOOLNOROTABLORIGINSAFETYARCSL"
		"PCOOLNTSPINDLIFRO  TURRET*1034*ROTHEDTHREADTRANS TRACUTINDEX"
		" COPY  PLOT  OVPLOTLETTERPPRINTPARTNOINSERTCAMERAPREFUNCOUPL"
		"EPITCH MDWRITMDEND ASLOPECYCLE LOADTLSELCTLCLRSRFDWELL DRAFT"
		" CLAMP PLABELMAXDPMSLOWDNMAXVELLPRINTMOVETOCORNFDPBS   REGBR"
		"KVTLAXSWCORN MAGTAP*1073**1074**1075**1076**1077**1078**1079"
		"**1080**1081**1082**1083**1084**1085*                       "
		"                                                            "
		"       " };


    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    static doublereal equiv_6[258];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, j, m, n, kk, mm, it, lr, ix;
#define pm0 ((char *)&equiv_9)
#define pm1 ((char *)&equiv_9 + 300)
#define r1000 ((doublereal *)((integer *)&equiv_7 + 3))
#define blk ((char *)&equiv_16)
#define ijk ((integer *)equiv_6)
    static doublereal dum;
    static integer nwd, kix;
#define blk2 ((char *)&equiv_16)
#define blk4 ((char *)&equiv_16)
#define par0 ((char *)&equiv_13)
#define par1 ((char *)&equiv_13 + 300)
#define par2 ((char *)&equiv_13 + 600)
#define par3 ((char *)&equiv_13 + 900)
    extern integer bcdf_(char *, ftnlen);
#define ir1000 ((integer *)&equiv_7)
    static char char__[8];
    static integer iseq, iret, kkix;
    static char test[6];
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt336_(integer *, char *, ftnlen);
    static char test8[8];
#define blank ((char *)&equiv_16)
#define param ((char *)&equiv_13)
    static integer nsave;
    static char atest[6];
#define rxxxx (equiv_6 + 2)
#define irecrd ((doublereal *)&editor_1)
#define jrecrd ((integer *)&editor_1)
#define record ((doublereal *)&editor_1)
#define numcld ((integer *)&editor_1 + 1186)
#define pmname ((char *)&equiv_9)
    static integer subcls;
    static char rcdchr[1000];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static doublereal savnam, savsub, sbclsv;
    extern /* Subroutine */ int atapwt_(integer *, integer *, integer *, 
	    integer *, integer *, doublereal *, integer *);
    static integer isvseq;
#define numwds ((integer *)&editor_1 + 5)
    extern /* Subroutine */ int atapop_(integer *, integer *, integer *);
#define subtyp ((integer *)equiv_6 + 3)
#define irxxxx ((integer *)equiv_6 + 1)




/* ...            SYSTEM I/O FILE NAMES */




/* ...                SYSTEM I/O FILES */




/* ... LOCAL VARIABLES */


/* ...     RECORD TYPES AND POST PROCESSOR SUBCLASS WORDS */




/*     -------------------------------------------------------- */

    kkix = 0;
    if (nnn != 0) {
	goto L3;
    }
    for (i__ = 4; i__ <= 7; ++i__) {
	ir1000[i__ - 1] = bcdf_(blk4, (ftnlen)4);
/* L1: */
    }
/* ...     STORE SEQUENCE NUMBER AND INITIALIZE */
L3:
    iseq = jrecrd[3];
    ir1000[2] = iseq - iseq / 10000 * 10000;
    irxxxx[0] = iseq / 10000;
    irxxxx[2] = 0;
    for (i__ = 1; i__ <= 5; ++i__) {
/* L10: */
	rxxxx[i__ - 1] = 0.;
    }
    ix = 0;

/* ...     BRANCH ON RECORD TYPE */
    holfrm_(record, test, &c__1, &c__6, &nwd, (ftnlen)6);
    for (it = 1; it <= 10; ++it) {
	if (s_cmp(test, rectyp + (it - 1) * 6, (ftnlen)6, (ftnlen)6) != 0) {
	    goto L100;
	}
	switch (it) {
	    case 1:  goto L300;
	    case 2:  goto L350;
	    case 3:  goto L400;
	    case 4:  goto L500;
	    case 5:  goto L1000;
	    case 6:  goto L450;
	    case 7:  goto L9999;
	    case 8:  goto L9999;
	    case 9:  goto L9999;
	    case 10:  goto L9999;
	}
L100:
	;
    }

/* ...     CHECK FOR SPECIAL WORDS--SPECIAL PROCESSING NEEDED */
    for (kk = 1; kk <= 20; ++kk) {
	if (s_cmp(test, splwds + (kk - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L600;
	}
/* L105: */
    }

/* ...     *** POSTPROCESSOR TYPE COMMANDS*** */
    if (s_cmp(test, scalwd, (ftnlen)6, (ftnlen)6) == 0) {
	goto L605;
    }
    irxxxx[1] = 2000;
    holfrm_(&record[4], test8, &c__1, &c__8, &nwd, (ftnlen)8);
    if (jrecrd[5] != 2 || s_cmp(test8, blank, (ftnlen)8, (ftnlen)8) != 0) {
	goto L140;
    }
    for (*subtyp = 1; *subtyp <= 22; ++(*subtyp)) {
	if (s_cmp(test, ppname + (*subtyp - 1) * 6, (ftnlen)6, (ftnlen)6) == 
		0) {
	    goto L9000;
	}
/* L110: */
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	*subtyp = ipp2[i__ - 1];
	if (s_cmp(test, pp2 + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L9000;
	}
/* L111: */
    }

L140:
    for (*subtyp = 1001; *subtyp <= 1100; ++(*subtyp)) {
	if (s_cmp(test, pmname + (*subtyp - 1001) * 6, (ftnlen)6, (ftnlen)6) 
		== 0) {
	    goto L160;
	}
/* L150: */
    }
    for (i__ = 1; i__ <= 8; ++i__) {
	*subtyp = ipm2[i__ - 1];
	if (s_cmp(test, pm2 + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L160;
	}
/* L151: */
    }

/* ...     UNIDENTIFIED POSTPROCESSOR COMMAND--ISSUE ERROR MESSAGE */
    apt336_(&c__30030, "CNVRT3  ", (ftnlen)8);
    goto L9999;

L160:
    i5axis_1.ir = 4;
    lr = *numwds + 3;
    if (jrecrd[7] == 3 && jrecrd[11] == 0) {
	ix = 1;
    }
L170:
    ++ix;
    it = jrecrd[(i5axis_1.ir << 1) - 1];
    switch (it) {
	case 1:  goto L180;
	case 2:  goto L190;
	case 3:  goto L230;
	case 4:  goto L225;
    }
/* ...     ***  TYPE 1 --- FLOATING POINT DATA ITEM PAIR */
L180:
    rxxxx[ix - 1] = record[i5axis_1.ir];
    goto L250;
/* ...     ***  TYPE 2 --- ALPHANUMERIC DATA ITEM PAIR */
L190:
    holfrm_(&record[i5axis_1.ir], atest, &c__1, &c__6, &nwd, (ftnlen)6);
    for (i__ = 1; i__ <= 200; ++i__) {
	if (s_cmp(atest, param + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L220;
	}
/* L200: */
    }
    for (j = 1; j <= 7; ++j) {
	i__ = ipar4[j - 1];
	if (s_cmp(atest, par4 + (j - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L220;
	}
/* L201: */
    }
    holfrm_(&record[i5axis_1.ir], rcdchr, &c__1, &c__8, &nwd, (ftnlen)1000);
    s_copy(char__, blank, (ftnlen)8, (ftnlen)8);
    n = 6;
    for (i__ = 6; i__ >= 1; --i__) {
	if (*(unsigned char *)&rcdchr[i__ - 1] == *(unsigned char *)blk) {
	    goto L210;
	}
	*(unsigned char *)&char__[n - 1] = *(unsigned char *)&rcdchr[i__ - 1];
	--n;
L210:
	;
    }
    irxxxx[(ix << 1) + 1] = bcdf_(char__, (ftnlen)4);
    irxxxx[(ix << 1) + 2] = bcdf_(char__ + 4, (ftnlen)4);
    goto L250;
L220:
    mm = (ix << 1) + 2;
    irxxxx[mm - 1] = 0;
    irxxxx[mm] = i__;
    goto L250;
/* ...     ***  TYPE 4 --- GEOMETRIC VARIABLE */
L225:
    m = jrecrd[(i5axis_1.ir + 1 << 1) - 1];
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = ix + i__ - 1;
	rxxxx[j - 1] = record[i5axis_1.ir + i__];
/* L227: */
    }
    ix = j;
    i5axis_1.ir += m;
    goto L250;
/* ...     ***  TYPE 3 --- ALPHANUMERIC LITERAL STRING */
L230:
    m = jrecrd[(i5axis_1.ir + 2 << 1) - 1];
    s_copy(rcdchr, blank, (ftnlen)1000, (ftnlen)8);
    holfrm_(&record[i5axis_1.ir + 2], rcdchr, &c__1, &m, &nwd, (ftnlen)1000);
    n = m / 6;
    if (m > n * 6) {
	++n;
    }
    i__ = 1;
    i__1 = n;
    for (kix = 1; kix <= i__1; ++kix) {
/* Writing concatenation */
	i__2[0] = 6, a__1[0] = rcdchr + (i__ - 1);
	i__2[1] = 2, a__1[1] = blk2;
	s_cat(char__, a__1, i__2, &c__2, (ftnlen)8);
	irxxxx[(ix << 1) + 1] = bcdf_(char__, (ftnlen)4);
	irxxxx[(ix << 1) + 2] = bcdf_(char__ + 4, (ftnlen)4);
	++ix;
	i__ += 6;
/* L232: */
    }
    for (kix = ix; kix <= 12; ++kix) {
	irxxxx[(ix << 1) + 1] = bcdf_(blank, (ftnlen)8);
	irxxxx[(ix << 1) + 2] = bcdf_(blank, (ftnlen)8);
	if (*subtyp >= 1044 && *subtyp <= 1046) {
	    kkix = 11;
	}
/* L240: */
    }
    i5axis_1.ir += jrecrd[(i5axis_1.ir + 1 << 1) - 1];
L250:
    i5axis_1.ir += 2;
/* L260: */
    if (i5axis_1.ir < lr) {
	goto L170;
    }
    goto L9000;
/* ...     FINI RECORD... */
L300:
    irxxxx[1] = 14000;
    if (nnn == 0) {
	return 0;
    }
    goto L9000;

/* ...     AERR RECORD -- STORE PREVIOUS SEQUENCE NUMBER */
L350:
    if (jrecrd[3] != 1) {
	goto L9999;
    }
    ir1000[2] = isvseq - isvseq / 10000 * 10000;
    irxxxx[0] = isvseq / 10000;
/* ...     GERR RECORD */
L400:
    irxxxx[1] = 13000;
    irxxxx[2] = 3;
    irxxxx[4] = jrecrd[7];
L410:
    ix = 1;
    irxxxx[3] = 0;
    goto L9000;
/* ...     CLPRNT RECORD.....SET ON OR OFF */
L450:
    irxxxx[1] = 13000;
    irxxxx[2] = 4;
    irxxxx[4] = 1;
    holfrm_(&record[4], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, off, (ftnlen)6, (ftnlen)6) == 0) {
	irxxxx[4] = 0;
    }
    goto L410;
/* ...     MULTAX RECORD -- SET MULTAX FLAG */
L500:
    irxxxx[1] = 9000;
    irxxxx[2] = 2;
    irxxxx[3] = 0;
    irxxxx[4] = 1;
    holfrm_(&record[4], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, off, (ftnlen)6, (ftnlen)6) == 0) {
	irxxxx[4] = 0;
    }
    multax = FALSE_;
    if (irxxxx[4] == 1) {
	multax = TRUE_;
    }
    goto L410;
L605:
    irxxxx[1] = 9000;
    irxxxx[2] = 9;
    holfrm_(&record[4], test8, &c__1, &c__8, &nwd, (ftnlen)8);
    for (i__ = 1; i__ <= 4; ++i__) {
	if (s_cmp(test8, scalin + (i__ - 1 << 3), (ftnlen)8, (ftnlen)8) == 0) 
		{
	    goto L603;
	}
/* L601: */
    }
/* ...     ERROR 30038 -- ERRONEOUS UNITS COMMAND */
    apt336_(&c__30038, "CNVRT3  ", (ftnlen)8);
    goto L9999;
L603:
    irxxxx[4] = i__;
    goto L410;

/* ...     ********* CLDATA RECORDS ********* */
L1000:
    if (jrecrd[7] - 2 >= 0) {
	goto L1030;
    } else {
	goto L1010;
    }
L1010:
    subcls = 5;
    holfrm_(&record[4], atest, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(atest, from, (ftnlen)6, (ftnlen)6) == 0) {
	subcls = 3;
    }
    savnam = record[6];
    savsub = record[7] + 0.f;
    if (jrecrd[5] <= 6) {
	goto L9997;
    }
    ix = 12;
/* ...     SAVE CIRCLE CANONICAL FORM */
    irxxxx[1] = 3000;
    irxxxx[2] = 2;
    irxxxx[6] = 4;
    irxxxx[8] = 9;
    rxxxx[3] = record[6];
    rxxxx[4] = record[7];
    for (i__ = 6; i__ <= 12; ++i__) {
/* L1020: */
	rxxxx[i__ - 1] = record[i__ + 3];
    }
    goto L9000;

/* ...     SAVE CUTTER LOCATION POINTS */
L1030:
    irxxxx[1] = 5000;
    irxxxx[2] = subcls;
    nsave = nnn;
    sbclsv = (doublereal) subcls;
    subcls = 6;
    rxxxx[0] = savnam;
    rxxxx[1] = savsub;
    i__ = 3;
    mm = 4;
    if (multax) {
	mm = 7;
    }
    i__1 = *numwds;
    for (j = 1; j <= i__1; ++j) {
	if ((j + 1 - (j - 1) / mm * mm) / 3 - 1 >= 0) {
	    goto L1050;
	} else {
	    goto L1070;
	}
L1050:
	rxxxx[i__ - 1] = record[j + 2];
	++i__;
L1070:
	;
    }
    ix = i__ - 1;
    if (irxxxx[2] - 5 <= 0) {
	goto L9010;
    } else {
	goto L9100;
    }
L9000:
    if (kkix >= 11) {
	ix = kkix;
    }
L9010:
    if (i3000 == 1) {
	goto L9050;
    }
    if (ir1000[2] == ircold) {
	goto L9100;
    }
    ++nnn;
    ircold = ir1000[2];
    ir1000[0] = nnn;
    atapwt_(&symfil_1.clfil3, &iret, &c__2, ir1000, &c__3, r1000, &c__2);
L9050:
    i3000 = 0;
L9100:
    ++nnn;
    irxxxx[0] = nnn;
/* ...     CALCULATE CLFIL3 RECORD NUMBER TO LIST ON VLFILE */
    iseq = ir1000[2] + nnn * 10000;
    jrecrd[3] = iseq;
    if (ix == 0) {
	goto L9200;
    }
    if (irxxxx[1] == 3000) {
	i3000 = 1;
    }
    atapwt_(&symfil_1.clfil3, &iret, &c__2, irxxxx, &c__3, rxxxx, &ix);
    goto L9998;
L9200:
    atapwt_(&symfil_1.clfil3, &iret, &c__1, irxxxx, &c__3, &dum, &c__1);
L9998:
    if (irxxxx[1] != 14000) {
	goto L9999;
    }
    atapop_(&symfil_1.clfil3, &c__2, &iret);
    atapop_(&symfil_1.clfil3, &c__1, &iret);
    goto L9999;

/* ...     ***** SPECIAL POSTPROCESSOR TYPE RECORDS ***** */
L600:
    if (kk > 11) {
	goto L9999;
    }
    irxxxx[1] = 6000;
    switch (kk) {
	case 1:  goto L610;
	case 2:  goto L9999;
	case 3:  goto L9999;
	case 4:  goto L620;
	case 5:  goto L620;
	case 6:  goto L620;
	case 7:  goto L9999;
	case 8:  goto L9999;
	case 9:  goto L9999;
	case 10:  goto L9999;
	case 11:  goto L610;
    }

/* ...     ARELEM FLAGS-CUT,DNTCUT */
L610:
    irxxxx[2] = kk - kk / 10 * 10;
    irxxxx[4] = 0;
    if (kk > 10) {
	irxxxx[4] = 1;
    }
    ix = 1;
    goto L410;

/* ...     ARELEM DATA ITEMS-CUTTER,INTOL,OUTTOL */
L620:
    irxxxx[2] = kk;
    lr = *numwds + 3;
    i__1 = lr;
    for (i__ = 5; i__ <= i__1; i__ += 2) {
	ix = i__ / 2 - 1;
	rxxxx[ix - 1] = record[i__ - 1];
/* L625: */
    }
    goto L9000;

/* ...     SAVE SEQUENCE NUMBER IF NOT AERR TYPE RECORD */
L9997:
    i__ = nnn + 2;
    if (ir1000[2] == ircold) {
	--i__;
    }
    jrecrd[3] = ir1000[2] + i__ * 10000;
L9999:
    if (s_cmp(test, rectyp + 6, (ftnlen)6, (ftnlen)6) != 0) {
	isvseq = jrecrd[3];
    }
    return 0;
} /* cnvrt3_ */

#undef irxxxx
#undef subtyp
#undef numwds
#undef pmname
#undef numcld
#undef record
#undef jrecrd
#undef irecrd
#undef rxxxx
#undef param
#undef blank
#undef area3
#undef area2
#undef area1
#undef ir1000
#undef par3
#undef par2
#undef par1
#undef par0
#undef blk4
#undef blk2
#undef ijk
#undef blk
#undef r1000
#undef pm1
#undef pm0


