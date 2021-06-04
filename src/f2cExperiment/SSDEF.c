/* SSDEF.f -- translated by f2c (version 20100827).
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
    integer txxxx[64]	/* was [2][32] */;
} tmp_;

#define tmp_1 tmp_

struct {
    integer srctbl[502];
} srctbl_;

#define srctbl_1 srctbl_

struct {
    integer bcdptr[7];
} bcdptr_;

#define bcdptr_1 bcdptr_

struct {
    integer numptr[12];
} numptr_;

#define numptr_1 numptr_

struct {
    integer geoloc[50], pmidtb[250], argmxy[250], geomtb[2180];
} gmty_;

#define gmty_1 gmty_

struct {
    integer cfsize[1106];
} cfsize_;

#define cfsize_1 cfsize_

struct {
    integer il[21];
} il_;

#define il_1 il_

struct {
    integer modx[32];
} modx_;

#define modx_1 modx_

struct {
    integer macxx1[71];
} macxx1_;

#define macxx1_1 macxx1_

struct {
    integer opmod[6];
} opmod_;

#define opmod_1 opmod_

struct {
    integer sublst[135];
} sublst_;

#define sublst_1 sublst_

struct {
    integer moduli[2];
} moduli_;

#define moduli_1 moduli_

struct {
    integer errpos[302];
} errpos_;

#define errpos_1 errpos_

/* Table of constant values */

static integer c__8 = 8;
static integer c__1 = 1;
static integer c__1204 = 1204;
static integer c__1225 = 1225;
static integer c__0 = 0;
static integer c__52 = 52;
static integer c__4 = 4;
static integer c__34 = 34;
static integer c__1001 = 1001;
static integer c__1228 = 1228;
static integer c__1216 = 1216;
static integer c__1217 = 1217;
static integer c__1211 = 1211;
static integer c__1201 = 1201;
static integer c__1213 = 1213;
static integer c__1206 = 1206;
static integer c__1205 = 1205;
static integer c__1207 = 1207;
static integer c__1208 = 1208;
static integer c__1203 = 1203;
static integer c__1215 = 1215;
static integer c__1212 = 1212;

/* *** SOURCE FILE : M0006687.W03   *** */


/*              FORTRAN SUBROUTINE SSDEF */

/* LINKAGE      SUBROUTINE SSDEF(ACTNO,BIGCNT) */

/*          SUBSIDIARIES                  CALLED BY */
/*          TYPE          ENTRY           TYPE          ENTRY */
/*          SUBROUTINE    ALARM           SUBROUTINE    RECOG */
/*          SUBROUTINE    CALLZZ */
/*          LOGICAL FCT.  IFTMP */
/*          INTEGER FCT.  NUMB */
/*          SUBROUTINE    ONEARG */
/*          SUBROUTINE    OPCODE */
/*          SUBROUTINE    ARGCVT */
/*          SUBROUTINE    PUTTMP */
/*          SUBROUTINE    CONCAT */
/*          SUBROUTINE    RESRVZ */
/*          SUBROUTINE    RLSLIN */
/*          INTEGER FCT.  GETTMP */
/*          SUBROUTINE    TWOARG */
/*          SUBROUTINE    BINBCD */

/* Subroutine */ int ssdef_(integer *actno, integer *bigcnt)
{
    /* Initialized data */

    static char iblank[1] = " ";
    static integer jsave = 0;
    static integer tcurv[4] = { 190,80,191,200 };
    static integer tsurf[11] = { 181,182,191,198,192,193,83,86,84,87,98 };

    /* Format strings */
    static char fmt_1110[] = "";
    static char fmt_1910[] = "";

    /* System generated locals */
    integer i__1, i__2;
    static integer equiv_53[60];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, j, k, l, m, ii, jj, jn;
#define kn (equiv_53 + 38)
#define tp (equiv_53)
    static integer nch, ind;
#define isc ((integer *)&cfsize_1 + 205)
#define ksc ((integer *)&cfsize_1 + 206)
#define one ((integer *)&numptr_1 + 2)
#define dlr ((integer *)&opmod_1 + 1)
#define vbl ((integer *)&code_1 + 60)
#define cnt (equiv_53 + 32)
#define jmp (equiv_53 + 34)
#define spl (equiv_53 + 26)
#define spm (equiv_53 + 20)
#define ptm (equiv_53 + 22)
#define stk (equiv_53)
#define top ((integer *)&stklst_1)
#define pnt (equiv_53 + 24)
#define pms (equiv_53 + 28)
#define nps (equiv_53 + 36)
    static integer iss, nmu;
#define two ((integer *)&numptr_1 + 4)
    static integer typ, tpt2;
#define real__ ((integer *)&modx_1 + 20)
    static integer mode;
#define meta ((integer *)&srctbl_1 + 2)
    static integer save[54]	/* was [2][27] */;
    extern integer numb_(char *, ftnlen);
#define repl ((integer *)&il_1 + 16)
    static integer iret, prod;
#define temp ((integer *)&code_1 + 32)
#define move ((integer *)&il_1 + 18)
    static integer tseg;
#define itmp (equiv_53 + 42)
#define four ((integer *)&numptr_1 + 6)
#define mtop (equiv_53 + 40)
#define mout (equiv_53 + 14)
    static char ibuff[15];
#define comma ((integer *)&code_1)
    extern /* Subroutine */ int alarm_(integer *, integer *, integer *, char *
	    , ftnlen);
    static integer hmode;
#define mmode (equiv_53 + 18)
#define ident ((integer *)&code_1 + 68)
#define stack ((integer *)&stklst_1 + 3)
#define index (equiv_53 + 12)
    static integer class__, segms;
#define count (equiv_53 + 30)
#define point ((integer *)&modx_1 + 18)
    static integer flows, error, errpt;
#define ssurf ((integer *)&modx_1 + 28)
#define scurv ((integer *)&modx_1 + 29)
    extern /* Subroutine */ int binbcd_(integer *, char *, integer *, ftnlen);
#define mindef ((logical *)equiv_53 + 6)
    extern integer search_(integer *, integer *, integer *, integer *);
#define modhlf ((integer *)&moduli_1 + 1)
#define estack ((integer *)&errpos_1 + 102)
    extern /* Subroutine */ int concat_(char *, char *, ftnlen, ftnlen), 
	    opcode_(integer *);
#define dottab ((integer *)&bcdptr_1 + 6)
#define permid ((integer *)&code_1 + 38)
#define number ((integer *)&code_1 + 26)
#define intmed ((integer *)&macxx1_1 + 21)
#define modulo ((integer *)&moduli_1)
#define crsflg ((logical *)equiv_53 + 8)
#define wtflag ((logical *)equiv_53 + 10)
#define vector ((integer *)&modx_1 + 19)
    static integer npatch;
#define matrix ((integer *)&modx_1 + 17)
#define nought ((integer *)&opmod_1)
    static integer geopos;
#define maxsiz ((integer *)&cfsize_1 + 3)
#define foulup ((logical *)equiv_53 + 4)
    static integer splary[16];
#define nowrds (equiv_53 + 16)
    extern /* Subroutine */ int twoarg_(integer *, integer *), rlslin_(void), 
	    onearg_(integer *);
#define zeropt ((integer *)&numptr_1 + 1)
    extern /* Subroutine */ int argcvt_(integer *);
#define nomtrx ((logical *)equiv_53 + 2)
    static integer result;
    extern integer gettmp_(integer *);
    static integer wtmode;
    extern /* Subroutine */ int resrvz_(integer *, integer *, integer *, 
	    integer *);
#define aptxxx ((integer *)&sublst_1)
    extern /* Subroutine */ int callzz_(integer *);
    static integer maxcnt, flwarg;

    /* Fortran I/O blocks */
    static icilist io___85 = { 0, ibuff, 0, "(I3)", 3, 1 };
    static icilist io___90 = { 0, ibuff, 0, "(I3)", 3, 1 };


    /* Assigned format variables */
    static char *tseg_fmt;



/*              FUNCTION DECLARATION */


/*        1.    NAME TABLE AND TABLE LIMITS */

/* NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY */
/* CNAMTB:      NAME TABLE OR DICTIONARY */
/* NAMMAX:      NAMTBL INDEX OF THE PART PROGRAM NAME SECTION */

/*        2.    STACK AND POINTER STORAGE */







/* TOP:         POINTER TO LAST STACK ENTRY */
/* STACK:       WORKING STACK */

/*        3.    METALINGUISTIC VARIABLE CLASS CODES */

/* COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF 'COMMA ' */
/* NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER' */
/* TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  ' */
/* PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID' */
/* VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   ' */
/* IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT ' */
/*        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION */
/*              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE */

/*        4.    PRODUCTION TABLE */

/* META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES */

/*        8.    NAME TABLE POINTERS TO BCD LITERALS */

/* DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB' */

/*        9.    NAME TABLE POINTERS TO NUMBERS */

/* ZEROPT:      NAMTBL POINTER TO '0.    ' */
/* ONE:PT:      NAMTBL POINTER TO '1     ' */
/* TWO:         NAMTBL POINTER TO '2     ' */
/* FOUR:        NAMTBL POINTER TO '4     ' */

/*       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR */

/* GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB */
/* PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB */
/* GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE */

/*       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS */




/* MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY */
/* ISC:         POINTER TO LAST KSC ENTRY */
/* KSC:         CONTAINS SYMBOL,SIZE AND NUMBER OF SEQMENTS OF SS-DEFIN. */

/*       16.    LITERALS FOR I. L. OPERATION CODES */

/* REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND */
/* MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND */

/*       17.    MODE CODES */

/* MATRIX:      MODE CODE (18) FOR MATRIX */
/* POINT:       MODE CODE (19) FOR POINT */
/* VECTOR:      MODE CODE (20) FOR VECTOR */
/* REAL:        MODE CODE (21) FOR A SCALAR */
/* SSURF:       MODE CODE (29) FOR SCULPTURED SURFACE */
/* SCURV:       MODE CODE (30) FOR SCULPTURED CURVE */

/*       22.    MACRO PROCESSING VARIABLES */

/* INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING */

/*       27.    OPERAND MODIFIERS */

/* NOUGHT:      CONTAINS OPERAND TYPE 0 */
/* DLR:         CONTAINS OPERAND TYPE CODE 1 */

/*       28.    OPERAND MODIFIERS */

/* APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES */

/*       29.    CLASS CODE MODULI */

/* MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS */
/* MODHLF:      NORMAL MODE CODE LIMIT 500 */

/*       44.    ERROR POSITION TABLE */

/* ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK */
/* * */
/*       TYPE   MODE  SIZE */
/*       **************************************************************** */
/* SCURV/CURSEG 140  NPS=2  SEGMS=0                    * */
/*       SPLINE  30  NOWRDS=24*(NPS+1)                 * =72 */
/*                   NPS=2  SEGMS.GT.0                 * */
/*       SEG    150  NOWRDS=54*(NPS+1)-18+6*SEGMS      * =144+6*SEGMS */
/*                           I=N */
/*       COMBIN 141   NOWRDS=SUMME(NOWRDS(SS )-24) + 24 */
/*                           I=1            I */
/*       **************************************************************** */
/* SSURF/SMESH,XYZ,...132   KN=59   NOWRDS=10+KN*(SPL-1)*(NPS-1) */
/*       GMESH,XYZ,...125   KN=59 */
/*       SMESH,XYPLAN,132   KN=35 */
/*       COMBIN,......141                  I=N */
/*       RULED,.......143           NOWRDS=SUMME(NOWRDS(SS )-10) + 10 */
/*       TRANSL,......133                  I=1            I */
/*       SCALE,....... 36 */
/*       XYROT,....... 34 */
/*       REVOLV,......142           NOWRDS=74+222*NOWRDS/24 */
/*       GENCUR,......148           NOWRDS=NOWRDS+10 */
/*       PATCH,PNTSON,131 */
/*       PATCH,PNTVEC,131           NOWRDS=8+65*NPATCH */
/*       PATCH,POLYGN,131 */
/*       **************************************************************** */


/* ...  LOCAL VARIABLES WHICH MUST BE SAVED UNTIL THIS SSURF DEF IS */
/*      COMPLETELY TRANSLATED. */

/*                CURSEG SPLINE COMBIN SEG */
/*                PATCH  SMESH  COMBIN GENCUR REVOLV RULED */
/*                TRANSL SCALE  XYROT  YZROT  ZXROT */
/* ** */
    iret = 1;
    ind = 1;
    if (*bigcnt != 1) {
	goto L10;
    }

    *tp = 2;
L1:
    *mtop = *top;
    iss = nametb_1.namtbl[stack[(*top - 5 << 1) - 2] - 1] % *modhlf;
    *foulup = FALSE_;
    *mindef = FALSE_;
    *crsflg = FALSE_;
    *wtflag = FALSE_;
    *nomtrx = FALSE_;
    *index = -9;
    *nowrds = 0;
    *nps = 0;
    *spm = 31;
    *ptm = 31;
    *pms = 31;
    *pnt = 1;
    segms = 0;
    *spl = 0;
    *count = 0;
    *cnt = 0;
    splary[0] = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	itmp[(i__ << 1) - 2] = 1;
/* L5: */
	itmp[(i__ << 1) - 1] = *real__;
    }
    stk[1] = -1;
    *kn = 35;
    *jmp = 5;
    *mout = 1;
    flows = -1;
    npatch = 0;
    l = stack[(*top - 3 << 1) - 2];
    m = stack[(*top - 1 << 1) - 2];
    errpt = *top - 3;
    goto L200;

/*         STORE INTERNAL BIT REPRESENTATION IN STK */

L10:
    if (*actno > 102) {
	goto L500;
    }
    if (*foulup) {
	goto L140;
    }
    if (*top > *mtop) {
	goto L900;
    }
L20:
    l = stack[(*top - 1 << 1) - 2];
    errpt = *top - 1;
    if (l > nametb_1.nammax) {
	goto L50;
    }
    class__ = *modulo * (nametb_1.namtbl[l - 1] / *modulo);
    mode = nametb_1.namtbl[l - 1] - class__;
    if (mode > *modhlf) {
	mode -= *modhlf;
    }
    if (class__ != ident[0]) {
	goto L40;
    }
    class__ = permid[0];
    nametb_1.namtbl[l - 1] = nametb_1.namtbl[l - 1] - ident[0] + permid[0];
L40:
    if (class__ == permid[0]) {
	mode += 50;
    }
    if (class__ == vbl[0] || class__ == permid[0] || class__ == temp[0]) {
	goto L60;
    }
    if (class__ != number[0]) {
	goto L80;
    }
L50:
    mode = *real__;
    class__ = number[0];
L60:
    if (*wtflag) {
	goto L1000;
    }
    ++(*tp);
    error = 1227;
    if (*tp > 30) {
	goto L100;
    }
    stk[(*tp << 1) - 1] = gmty_1.pmidtb[mode - 1];
    geopos = gmty_1.geoloc[iss - 1];
    tpt2 = *tp << 1;
    prod = search_(stk, &tpt2, &gmty_1.geomtb[geopos - 1], &errpt);

    switch (prod) {
	case 1:  goto L1100;
	case 2:  goto L1200;
	case 3:  goto L1300;
	case 4:  goto L1400;
	case 5:  goto L1500;
	case 6:  goto L1600;
	case 7:  goto L1700;
	case 8:  goto L1800;
	case 9:  goto L1900;
	case 10:  goto L2000;
	case 11:  goto L2100;
	case 12:  goto L2200;
	case 13:  goto L2300;
	case 14:  goto L2400;
	case 15:  goto L2500;
	case 16:  goto L2600;
	case 17:  goto L2700;
	case 18:  goto L2800;
	case 19:  goto L2900;
	case 20:  goto L3000;
	case 21:  goto L3100;
	case 22:  goto L3200;
	case 23:  goto L3300;
	case 24:  goto L3400;
	case 25:  goto L3500;
	case 26:  goto L3600;
	case 27:  goto L3700;
    }

/*                ERROR OUTPUT */

L80:
    errpt = *top - 1;
L90:
    error = 1007;
    if (class__ == permid[0]) {
	goto L100;
    }
    j = (mode - 9) % 10;
    if (mode < 19 || j > 2) {
	goto L100;
    }
    error = mode + 1203;
L100:
    *foulup = TRUE_;
    *mindef = TRUE_;
L110:
    --(*tp);
    alarm_(&error, &errpt, &c__8, "SSDEF   ", (ftnlen)8);
L140:
    stack[(*top - 2 << 1) - 2] = stack[(*top << 1) - 2];
    stack[(*top - 2 << 1) - 1] = stack[(*top << 1) - 1];
    estack[*top - 3] = estack[*top - 1];
    *top += -2;
L150:
    return 0;

/*                I.L.  OUTPUT */

/*           SPECIAL CONTROL AND OUTPUT OF THE SUBTYPE */

L200:
    tseg = 0;
    tseg_fmt = fmt_1110;
    mode = nametb_1.namtbl[l - 1] % *modhlf;
    class__ = nametb_1.namtbl[l - 1] - mode;
    if (class__ != ident[0]) {
	goto L201;
    }
    class__ = permid[0];
    nametb_1.namtbl[l - 1] = nametb_1.namtbl[l - 1] - ident[0] + permid[0];
L201:
    if (class__ != permid[0]) {
	goto L202;
    }
    itmp[0] = l;
    mode += 50;
L202:
    *mmode = mode;
    stk[(*tp << 1) - 1] = gmty_1.pmidtb[*mmode - 1];
    hmode = nametb_1.namtbl[m - 1] % *modhlf;
    typ = nametb_1.namtbl[m - 1] - hmode;
    if (typ != permid[0] && typ != ident[0]) {
	goto L204;
    }
    hmode += 50;
    if (hmode != 188 && hmode != 189) {
	itmp[4] = m;
    }
L204:
    if (iss == 29) {
	goto L215;
    }

    for (typ = 1; typ <= 4; ++typ) {
	if (tcurv[typ - 1] == *mmode) {
	    goto L225;
	}
/* L210: */
    }
    goto L90;

L215:
    for (typ = 1; typ <= 11; ++typ) {
	if (tsurf[typ - 1] == *mmode) {
	    goto L217;
	}
/* L216: */
    }
    goto L90;
L217:
    typ += 4;

L225:
    iret = 2;
    *top += -2;
    switch (typ) {
	case 1:  goto L230;
	case 2:  goto L232;
	case 3:  goto L234;
	case 4:  goto L236;
	case 5:  goto L244;
	case 6:  goto L270;
	case 7:  goto L246;
	case 8:  goto L270;
	case 9:  goto L320;
	case 10:  goto L248;
	case 11:  goto L320;
	case 12:  goto L320;
	case 13:  goto L320;
	case 14:  goto L320;
	case 15:  goto L320;
    }
/*            CURSEG */
L230:
    *nps = 1;
    *ptm = 6;
/*            SPLINE */
L232:
    *spl = 1;
    ++(*nps);
    *jmp = 6;
    goto L320;
/*            COMBIN */
L234:
    *nps = 1;
    *jmp = 7;
    goto L270;
/*            SEG */
L236:
    *spl = 1;
    *nps = 2;
    *pnt = 2;
    *jmp = 6;
    tseg = 1;
    tseg_fmt = fmt_1910;
    goto L270;
/*            PATCH */
L244:
    *mout = 2;
    *jmp = 2;
    goto L270;
/*            SSURF/COMBIN */
L246:
    *jmp = 3;
    goto L270;
/*            SSURF/RULED */
L248:
    *spl = 1;
    goto L320;

L270:
    iret = 1;
    *top += 2;
    goto L20;

L280:
    jj = iss - 28;
    if (class__ == temp[0]) {
	goto L290;
    }
    i__1 = *isc;
    for (jj = 4; jj <= i__1; ++jj) {
	if (l == ksc[jj * 3 - 3]) {
	    goto L290;
	}
/* L285: */
    }
    errpt = *top - 1;
    error = 1235;
    goto L100;
L290:
    k = 24;
    if (mode != *scurv) {
	k = 10;
    }
    *nowrds = *nowrds + ksc[jj * 3 - 2] - k;
    if (*jmp == 5) {
	*nowrds = *nowrds + ksc[jj * 3 - 2] + ksc[jj * 3 - 1] * 24;
    }
    goto L330;

/*                MOVE COUPLER TO LINE */

L300:
    switch (*mout) {
	case 1:  goto L310;
	case 2:  goto L330;
    }
L310:
    if (class__ == permid[0]) {
	mode += -50;
    }
    s_copy(ibuff + 7, iblank, (ftnlen)8, (ftnlen)1);
    binbcd_(&mode, ibuff + 3, &nch, (ftnlen)12);
    s_wsfi(&io___85);
    do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
    e_wsfi();
    concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
    jn = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
    opcode_(move);
    twoarg_(index, dottab);
    twoarg_(dlr, &jn);
    rlslin_();
    --(*index);
    if (ind > 1) {
	goto L330;
    }

L320:
    opcode_(move);
    goto L340;
L330:
    opcode_(repl);
    onearg_(&ind);
L340:
    twoarg_(index, dottab);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    rlslin_();
    *index -= ind;
    switch (iret) {
	case 1:  goto L140;
	case 2:  goto L270;
    }

/*                PROCESS END OF DEFINITION */

L500:
    if (*mindef && flows != 0) {
	goto L510;
    }
    alarm_(&c__1204, top, &c__8, "SSDEF   ", (ftnlen)8);
    *foulup = TRUE_;
    goto L520;
L510:
    if (*mmode == 182 && *pnt != *nps) {
	alarm_(&c__1225, &c__0, &c__8, "SSDEF   ", (ftnlen)8);
    }
L520:
    iss = nametb_1.namtbl[stack[(*top - 3 << 1) - 2] - 1] % *modhlf;
    if (*actno != 105) {
	goto L530;
    }
    result = gettmp_(&iss);
    goto L560;
L530:
    result = stack[(*top - 5 << 1) - 2];
    class__ = *modulo * (nametb_1.namtbl[result - 1] / *modulo);
    mode = nametb_1.namtbl[result - 1] % *modhlf;
    if (class__ == vbl[0] || class__ == temp[0]) {
	goto L540;
    }
    nametb_1.namtbl[result - 1] = vbl[0] + iss;
    resrvz_(&result, &iss, &tmp_1.txxxx[(iss << 1) - 2], &c__1);
    mode = nametb_1.namtbl[result - 1] % *modhlf;
L540:
    if (mode != iss) {
	goto L800;
    }
    if (class__ == vbl[0] && *intmed == 0) {
	i__1 = *top - 5;
	alarm_(&c__52, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
L560:
    if (*foulup) {
	goto L810;
    }
    if (! (*wtflag)) {
	goto L570;
    }
    i__1 = wtmode + 1200;
    alarm_(&i__1, top, &c__8, "SSDEF   ", (ftnlen)8);
L570:
    for (i__ = 3; i__ <= 5; ++i__) {
	j = -i__;
	if ((i__1 = i__ - 4) < 0) {
	    goto L573;
	} else if (i__1 == 0) {
	    goto L574;
	} else {
	    goto L575;
	}
L573:
	nmu = *spl;
	goto L580;
L574:
	nmu = *nps;
	goto L580;
L575:
	nmu = -(*index);
L580:
	s_copy(ibuff + 7, iblank, (ftnlen)8, (ftnlen)1);
	binbcd_(&nmu, ibuff + 3, &nch, (ftnlen)12);
	s_wsfi(&io___90);
	do_fio(&c__1, (char *)&nch, (ftnlen)sizeof(integer));
	e_wsfi();
	concat_(ibuff, ".", (ftnlen)15, (ftnlen)1);
	jn = numb_(ibuff + 3, (ftnlen)12) + nametb_1.nammax;
	opcode_(move);
	twoarg_(&j, dottab);
	twoarg_(dlr, &jn);
/* L590: */
	rlslin_();
    }
    if (iss == 30) {
	goto L585;
    }
    callzz_(&aptxxx[87]);
    goto L595;
L585:
    i__ = 90;
    if (*mmode == 200) {
	i__ = 86;
    }
    callzz_(&aptxxx[i__ - 1]);
L595:
    argcvt_(&result);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L600: */
	argcvt_(&itmp[(i__ << 1) - 2]);
    }
    rlslin_();

/*                STORAGE OF THE SIZE */

    switch (*jmp) {
	case 1:  goto L610;
	case 2:  goto L620;
	case 3:  goto L630;
	case 4:  goto L640;
	case 5:  goto L650;
	case 6:  goto L660;
	case 7:  goto L670;
    }
/* **** SSURF/                   SMESH */
L610:
    if (*spl == 2 || *nps == 2) {
	*kn = 47;
    }
    *nowrds = *kn * (*spl - 1) * (*nps - 1) + 10;
    goto L700;
/* **** SSURF/                   PATCH */
L620:
    *nowrds = npatch * 65 + 8;
    goto L700;
/* **** SSURF/                   COMBIN */
L630:
    *nowrds += 10;
    goto L700;
/* **** SSURF/                   REVOLV */
L640:
    *nowrds = *nowrds * 222 / 24 + 10;
    goto L700;
/* **** SSURF/                   GENCUR,RULED */
/* ****                          TRANSL,SCALE,XYROT,YZROT,ZXROT */
L650:
    *nowrds += 10;
    goto L700;
L660:
    if (*nowrds > 0) {
	goto L670;
    }
/* **** SCURV/                   CURSEG,SPLINE,SEG */
    *nowrds = 72;
    if (segms > 0) {
	*nowrds = segms * 6 + 144;
    }
    goto L700;
/* **** SCURV/                   COMBIN */
L670:
    *nowrds += 24;

L700:
    if (class__ != temp[0]) {
	goto L720;
    }
    j = iss - 28;
    if (*nowrds > ksc[j * 3 - 2]) {
	ksc[j * 3 - 2] = *nowrds;
    }
    if (segms > ksc[j * 3 - 1]) {
	ksc[j * 3 - 1] = segms;
    }
    goto L760;
L720:
    ++(*isc);
    if (*isc <= 300) {
	goto L740;
    }
    i__1 = *top - 5;
    alarm_(&c__34, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    goto L810;
L740:
    ksc[*isc * 3 - 3] = result;
    ksc[*isc * 3 - 2] = *nowrds;
    ksc[*isc * 3 - 1] = segms;
L760:
    if (*nowrds <= maxsiz[1]) {
	goto L820;
    }
    if (*nowrds >= maxsiz[0]) {
	goto L780;
    }
    maxsiz[1] = *nowrds;
    goto L820;
L780:
    maxsiz[1] = maxsiz[0];
    maxsiz[0] = *nowrds;
    goto L820;

/*                ERROR PROCESSING GENERATE CALL TO APT094 */

L800:
    i__1 = *top - 5;
    alarm_(&c__1001, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
L810:
    callzz_(&aptxxx[67]);
    twoarg_(dlr, four);
    argcvt_(&result);
    twoarg_(nought, dottab);
    rlslin_();

/*                IF NESTED DEFINITION LOAD SAVED DATA */

L820:
    if ((i__1 = *actno - 104) < 0) {
	goto L150;
    } else if (i__1 == 0) {
	goto L830;
    } else {
	goto L840;
    }
L830:
    *top += -6;
    goto L860;
L840:
    *top += -4;
L860:
    stack[(*top << 1) - 2] = result;
    class__ = nametb_1.namtbl[result - 1] / *modulo;
    stack[(*top << 1) - 1] = meta[class__ - 1];
    if (jsave == 0) {
	goto L890;
    }
    if (*top > save[jsave + 39]) {
	goto L890;
    }
    for (i__ = 1; i__ <= 27; ++i__) {
/* L880: */
	stk[(i__ << 1) - 2] = save[jsave + (i__ << 1) - 3];
    }
    --jsave;
    goto L150;
L890:
    *bigcnt = 0;
    goto L150;

/*                NESTED DEFINITION, SAVE DATA */

L900:
    if (jsave < 2) {
	goto L910;
    }
    i__1 = *top - 5;
    alarm_(&c__1228, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    *foulup = TRUE_;
    *mindef = TRUE_;
    goto L140;
L910:
    ++jsave;
    for (i__ = 1; i__ <= 27; ++i__) {
/* L920: */
	save[jsave + (i__ << 1) - 3] = stk[(i__ << 1) - 2];
    }
    ++(*tp);
    goto L1;

/*       ****  POINT,VECTOR,SCALAR OR SURFACES EXPECTED **** */

L1000:
    ++(*count);
    if (*count == maxcnt) {
	*wtflag = FALSE_;
    }
    if ((i__1 = maxcnt - 10) < 0) {
	goto L1030;
    } else if (i__1 == 0) {
	goto L1005;
    } else {
	goto L1020;
    }
L1005:
    if (*mmode != 193) {
	goto L1010;
    }
    if (mode == *point) {
	goto L1025;
    }
    wtmode = *vector;
    *wtflag = FALSE_;
    goto L1025;
L1010:
    if (*count == 9) {
	goto L1030;
    }
    if (mode == wtmode) {
	goto L1025;
    }
    wtmode = *vector;
    if (*mmode != 192) {
	wtmode = *ssurf;
    }
    goto L1025;
L1020:
    wtmode = splary[*count - 1];
L1025:
    if (! (*wtflag)) {
	maxcnt = 1;
    }
L1030:
    error = wtmode + 1200;
    if (mode != wtmode) {
	i__1 = *top - 1;
	alarm_(&error, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    if (mode != *matrix) {
	goto L1040;
    }
    if (*nomtrx) {
	i__1 = *top - 1;
	alarm_(&c__1216, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    ind = 12;
    if (stack[(*top << 1) - 2] != comma[1]) {
	goto L330;
    }
    *foulup = TRUE_;
    alarm_(&c__1217, top, &c__8, "SSDEF   ", (ftnlen)8);
    goto L330;
L1040:
    switch (tseg) {
	case 0: goto L1110;
	case 1: goto L1910;
	case 2: goto L1080;
    }

/*       ****  SCURV/CURSEG-SPLINE  **** */

L1080:
    *count = 0;
    *wtflag = TRUE_;
L1090:
    --(*tp);
    goto L1110;

L1100:
    *cnt = 0;
    splary[0] = 0;
L1110:
    ind = 1;
    if (class__ != permid[0]) {
	ind = tmp_1.txxxx[(mode << 1) - 2];
    }
    if (ind == 2) {
	goto L280;
    }
    goto L300;

L1200:
    if (! (*crsflg) || *pnt < 2) {
	goto L1210;
    }
    estack[*top - 2] = errpos_1.errpos[101];
    i__1 = *top - 1;
    alarm_(&c__1211, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
L1210:
    *crsflg = FALSE_;
    goto L1310;

L1300:
    ++(*nps);
L1310:
    *mindef = TRUE_;
L1320:
    ++(*pnt);
    if (*pnt == *ptm) {
	i__1 = *top - 1;
	alarm_(&c__1201, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    *cnt = 0;
    splary[0] = 0;
    goto L1090;

L1400:
    wtmode = *vector;
    error = 1210;
    if (mode != 187) {
	goto L1510;
    }
    errpos_1.errpos[101] = estack[*top - 2];
    *crsflg = TRUE_;
    goto L1510;

L1500:
    wtmode = *real__;
    error = 1209;
L1510:
    i__1 = *cnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (splary[i__ - 1] != mode) {
	    goto L1520;
	}
	i__2 = *top - 1;
	alarm_(&error, &i__2, &c__4, "SSDEF   ", (ftnlen)8);
	goto L1530;
L1520:
	;
    }
    ++(*cnt);
    splary[*cnt - 1] = mode;
L1530:
    maxcnt = 1;
    goto L1080;

/*                   **** SCURV-SSURF/COMBIN  **** */

L1600:
    *mindef = TRUE_;
    goto L1110;

L1700:
    if (iss == *ssurf) {
	goto L1090;
    }
    ++(*nps);
    *pnt = *nps + 1;
    if (*nps == *ptm) {
	i__1 = *top - 1;
	alarm_(&c__1213, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    goto L1090;

/*                   ****  SCURV/SEG  **** */

L1800:
    ++(*cnt);
    error = 1212;
    errpt = *top - 1;
    switch (*cnt) {
	case 1:  goto L1810;
	case 2:  goto L1820;
	case 3:  goto L1830;
	case 4:  goto L110;
    }
L1810:
    callzz_(&aptxxx[85]);
    argcvt_(&stack[(*top - 7 << 1) - 2]);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    argcvt_(zeropt);
    argcvt_(one);
    rlslin_();
L1820:
    ii = stack[(*top - 1 << 1) - 2];
    goto L140;
L1830:
    *mindef = TRUE_;
    if (*count > 0) {
	goto L1820;
    }
    ++(*count);
L1840:
    ++(*count);
L1850:
    callzz_(&aptxxx[85]);
    argcvt_(&stack[(*top - 7 << 1) - 2]);
    argcvt_(&ii);
    argcvt_(&stack[(*top - 1 << 1) - 2]);
    argcvt_(two);
    rlslin_();
    ii = -ii;
    goto L140;

L1900:
    *tp += -2;
    if (*count >= 2) {
	goto L1820;
    }
    goto L1840;
L1910:
    if (ii < 0) {
	goto L1820;
    }
    goto L1850;

/*                   ****  FLOW AND SEG SECTION **** */

L2000:
    flows = 0;
L2010:
    if (*mindef) {
	goto L2020;
    }
    *foulup = TRUE_;
    i__1 = *top - 1;
    alarm_(&c__1204, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
L2020:
    switch (tseg) {
	case 0: goto L1110;
	case 1: goto L1910;
	case 2: goto L1080;
    }

L2100:
    flwarg = 2;
    if (mode == 117) {
	flwarg = 3;
    }
    goto L2210;

L2200:
    flwarg = 5;
    if (mode == 204) {
	flwarg = 6;
    }
    if (*jmp == 5) {
	i__1 = *top - 1;
	alarm_(&c__1206, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    *jmp = flwarg;
L2210:
    ++flows;
    if (flows == *pnt) {
	i__1 = *top - 1;
	alarm_(&c__1205, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
L2220:
    *count = 0;
    maxcnt = 2;
/* L2240: */
    wtmode = *real__;
/* L2250: */
    *wtflag = TRUE_;
    goto L2640;

L2300:
    if (*count != 2 || flwarg < 3) {
	i__1 = *top - 1;
	alarm_(&c__1206, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    *count = 2;
    maxcnt = 3;
    wtmode = *real__;
    goto L2410;

L2400:
    if (*count > 3 || flwarg < 5) {
	i__1 = *top - 1;
	alarm_(&c__1206, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    if (flwarg + mode == 223) {
	i__1 = *top - 1;
	alarm_(&c__1206, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    *jmp = 0;
    wtmode = *point;
    *count = 3;
    maxcnt = *count + mode / 110;
L2410:
    *wtflag = TRUE_;
    --(*tp);
    goto L140;

L2500:
    if (flwarg < 5 || flwarg <= *count) {
	i__1 = *top - 1;
	alarm_(&c__1206, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    wtmode = *vector;
    maxcnt = flwarg;
    *count = maxcnt - 1;
    goto L2410;

L2600:
    if ((i__1 = mode - *vector) < 0) {
	goto L2610;
    } else if (i__1 == 0) {
	goto L2620;
    } else {
	goto L2630;
    }
L2610:
    ++(*count);
    if (*count < 4) {
	*count = 4;
    }
    *jmp = 0;
    if (*count > flwarg - 1) {
	i__1 = *top - 1;
	alarm_(&c__1207, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    goto L2640;
L2620:
    if (flwarg < 5) {
	i__1 = *top - 1;
	alarm_(&c__1207, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    if (flwarg == 6 && *count == 4) {
	i__1 = *top - 1;
	alarm_(&c__1207, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    ++(*count);
    if (*count < flwarg) {
	*count = flwarg;
    }
    if (*count > flwarg) {
	i__1 = *top - 1;
	alarm_(&c__1207, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    goto L2640;
L2630:
    if (*count > 2 || flwarg < 3) {
	i__1 = *top - 1;
	alarm_(&c__1207, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    *count = 3;
L2640:
    --(*tp);
    switch (tseg) {
	case 0: goto L1110;
	case 1: goto L1910;
	case 2: goto L1080;
    }

L2700:
    segms = 0;
    *mindef = FALSE_;
    if (mode == *mmode) {
	goto L140;
    }
    goto L1110;

L2800:
    ++segms;
    *mindef = TRUE_;
    if (segms == *pnt) {
	i__1 = *top - 1;
	alarm_(&c__1208, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    goto L2220;

/*                   ****  TRFORM,MATRIX  **** */

L2900:
    wtmode = *matrix;
    itmp[2] = l;
    maxcnt = 1;
    *mout = 1;
    tseg = 2;
    goto L2010;

/*                   ****  SSURF/SMESH  **** */

L3000:
    if (*mmode == 181) {
	goto L140;
    }
    if (mode == 193) {
	*spm = 3;
    }
    if (hmode > 83 && hmode < 99) {
	*nomtrx = TRUE_;
    }
    *jmp = 1;
    goto L140;

L3100:
    *mindef = FALSE_;
    ++(*spl);
    *cnt = 0;
    splary[0] = 0;
    if ((i__1 = *spl - 2) < 0) {
	goto L320;
    } else if (i__1 == 0) {
	goto L3110;
    } else {
	goto L3120;
    }
L3110:
    *nps = *pnt;
    if (*nps < 2) {
	i__1 = *top - 1;
	alarm_(&c__1225, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
    goto L3130;
L3120:
    if (*spl == *spm) {
	i__1 = *top - 1;
	alarm_(&c__1203, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    if (*pnt != *nps) {
	i__1 = *top - 1;
	alarm_(&c__1225, &i__1, &c__8, "SSDEF   ", (ftnlen)8);
    }
L3130:
    *pnt = 1;
    *tp += -2;
    goto L320;

L3200:
    if (*pnt + 1 == *nps) {
	goto L1310;
    }
    goto L1320;

/*                   ****  SSURF/PATCH  **** */

L3300:
    ++npatch;
    *mindef = TRUE_;
    for (i__ = 1; i__ <= 16; ++i__) {
/* L3310: */
	splary[i__ - 1] = *point;
    }
    if ((i__1 = hmode - 184) < 0) {
	goto L3320;
    } else if (i__1 == 0) {
	goto L3360;
    } else {
	goto L3350;
    }
L3320:
    splary[2] = *vector;
    splary[3] = *vector;
    for (i__ = 7; i__ <= 16; ++i__) {
/* L3340: */
	splary[i__ - 1] = *vector;
    }
    goto L3360;
L3350:
    if (npatch == 2) {
	i__1 = *top - 1;
	alarm_(&c__1215, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
L3360:
    maxcnt = 16;
    *count = 0;
    *wtflag = TRUE_;
    --(*tp);
    *spl = npatch;
    goto L320;

/*                   ****  SSURF/REVOLV-RULED  **** */

L3400:
    if (*mmode == 192) {
	goto L3430;
    }
    *spl = 0;
    *mindef = TRUE_;
    goto L3440;
L3430:
    *jmp = 4;
    stk[(*tp - 1 << 1) - 1] = stk[(*tp << 1) - 1];
L3440:
    --(*tp);
    wtmode = *point;
    *count = 8;
    maxcnt = 10;
    *wtflag = TRUE_;
    goto L1110;

L3500:
    wtmode = *real__;
    maxcnt = 2;
    *mindef = TRUE_;
    *cnt = 0;
    goto L1080;

/*                   ****  SSURF/GENCUR  **** */

L3600:
    if (class__ == permid[0]) {
	goto L3610;
    }
    ++(*pnt);
    if (*pnt == *ptm && *mmode == 205) {
	i__1 = *top - 1;
	alarm_(&c__1201, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    --(*tp);
    goto L1600;
L3610:
    *mindef = FALSE_;
    if (*cnt == *tp) {
	i__1 = *top - 1;
	alarm_(&c__1212, &i__1, &c__4, "SSDEF   ", (ftnlen)8);
    }
    *cnt = *tp;
    goto L1090;

/*               ****  SSURF/TRANSL,SCALE,XYTRANS,YZTRANS,ZXTRANS *** */

L3700:
    wtmode = *scurv;
    *mindef = TRUE_;
    maxcnt = 1;
    goto L1080;

} /* ssdef_ */

#undef aptxxx
#undef nomtrx
#undef zeropt
#undef nowrds
#undef foulup
#undef maxsiz
#undef nought
#undef matrix
#undef vector
#undef wtflag
#undef crsflg
#undef modulo
#undef intmed
#undef number
#undef permid
#undef dottab
#undef estack
#undef modhlf
#undef mindef
#undef scurv
#undef ssurf
#undef point
#undef count
#undef index
#undef stack
#undef ident
#undef mmode
#undef comma
#undef mout
#undef mtop
#undef four
#undef itmp
#undef move
#undef temp
#undef repl
#undef meta
#undef real__
#undef two
#undef nps
#undef pms
#undef pnt
#undef top
#undef stk
#undef ptm
#undef spm
#undef spl
#undef jmp
#undef cnt
#undef vbl
#undef dlr
#undef one
#undef ksc
#undef isc
#undef tp
#undef kn


