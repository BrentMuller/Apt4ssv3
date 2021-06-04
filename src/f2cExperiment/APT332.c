/* APT332.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__62 = 62;
static integer c__92 = 92;
static integer c__93 = 93;
static integer c__94 = 94;
static integer c_n1 = -1;
static integer c__89 = 89;
static integer c__90 = 90;
static integer c__91 = 91;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__80 = 80;
static integer c__81 = 81;
static integer c__82 = 82;
static integer c__77 = 77;
static integer c__78 = 78;
static integer c__79 = 79;
static integer c__3 = 3;
static integer c_n10 = -10;
static integer c_n55 = -55;
static integer c_n56 = -56;
static integer c_n50 = -50;
static integer c_n57 = -57;
static integer c__30 = 30;
static integer c__31 = 31;
static integer c__32 = 32;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c__23 = 23;
static integer c__4 = 4;
static integer c_n52 = -52;
static integer c__70 = 70;
static integer c__61 = 61;
static integer c__71 = 71;
static integer c__72 = 72;
static integer c__73 = 73;
static integer c__83 = 83;
static integer c__84 = 84;
static integer c__85 = 85;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c_n7 = -7;
static integer c__7 = 7;
static integer c__67 = 67;
static integer c__68 = 68;
static integer c__69 = 69;
static integer c__98 = 98;
static integer c__99 = 99;
static integer c__100 = 100;
static integer c__11 = 11;
static integer c__33 = 33;
static integer c__34 = 34;
static integer c__35 = 35;
static integer c__24 = 24;
static integer c__25 = 25;
static integer c__26 = 26;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__44 = 44;
static integer c__117 = 117;
static integer c__118 = 118;
static integer c__119 = 119;
static integer c__120 = 120;
static integer c__121 = 121;
static integer c__122 = 122;
static integer c__123 = 123;
static integer c__124 = 124;
static integer c__125 = 125;
static integer c__126 = 126;
static integer c__127 = 127;
static integer c__128 = 128;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__47 = 47;
static integer c__14 = 14;
static integer c__129 = 129;
static integer c__130 = 130;
static integer c__131 = 131;
static integer c__36 = 36;
static integer c__37 = 37;
static integer c__38 = 38;
static integer c__27 = 27;
static integer c__28 = 28;
static integer c__29 = 29;
static integer c__15 = 15;
static integer c_n14 = -14;
static integer c__16 = 16;
static integer c_n15 = -15;
static integer c__17 = 17;
static integer c_n13 = -13;
static integer c__18 = 18;
static integer c__20 = 20;
static integer c_n18 = -18;
static integer c__19 = 19;
static integer c_n12 = -12;
static integer c__86 = 86;
static integer c__87 = 87;
static integer c__88 = 88;
static integer c_n54 = -54;
static integer c__63 = 63;
static integer c__64 = 64;
static integer c__65 = 65;
static integer c__66 = 66;
static integer c_n16 = -16;
static integer c_n51 = -51;
static integer c__39 = 39;
static integer c__40 = 40;
static integer c__41 = 41;
static integer c_n48 = -48;
static integer c_n17 = -17;
static integer c__58 = 58;
static integer c__74 = 74;
static integer c__75 = 75;
static integer c__76 = 76;
static integer c__46 = 46;
static integer c__45 = 45;
static integer c__59 = 59;
static integer c__60 = 60;
static integer c_n11 = -11;
static integer c__103 = 103;
static integer c_n101 = -101;
static integer c__104 = 104;
static integer c__102 = 102;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__107 = 107;
static integer c__111 = 111;
static integer c__112 = 112;
static integer c__113 = 113;
static integer c__114 = 114;
static integer c__115 = 115;
static integer c__116 = 116;
static integer c__108 = 108;
static integer c__109 = 109;
static integer c__110 = 110;
static integer c_n9 = -9;
static integer c_n19 = -19;
static integer c_n8 = -8;
static integer c_n49 = -49;
static integer c__95 = 95;
static integer c__96 = 96;
static integer c__97 = 97;
static integer c_n53 = -53;
static integer c__50 = 50;
static integer c_n2 = -2;

/* *** SOURCE FILE : M0000435.V02   *** */


/* .....FORTRAN SUBROUTINE              APT332                12/67 */
/* PURPOSE      TO WRITE ONTO THE VERIFICATION LISTING TAPE A */
/*              GROUP OF COMMON VARIABLES FOR EACH DYNDMP CALL */
/*              FROM AN ACTIVATED DYNDMP BREAKPOINT. */
/* LINKAGE      CALL APT332 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt332_(void)
{
    /* Local variables */
#define ed ((doublereal *)&editor_1)
    extern /* Subroutine */ int apt330_(integer *, integer *, integer *, 
	    integer *, integer *);
#define numbr1 ((integer *)&editor_1 + 2)
#define numbr2 ((integer *)&editor_1 + 3)
#define number ((integer *)&editor_1 + 2)


/* ...  THIS PROGRAM WRITES THE DYNDMP INFORMATION BLOCKS ONTO THE */
/*     VERIFICATION LISTING TAPE */






    switch (*numbr2) {
	case 1:  goto L101;
	case 2:  goto L102;
	case 3:  goto L103;
	case 4:  goto L104;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L107;
	case 8:  goto L999;
	case 9:  goto L999;
	case 10:  goto L999;
	case 11:  goto L201;
	case 12:  goto L202;
	case 13:  goto L203;
	case 14:  goto L204;
	case 15:  goto L205;
	case 16:  goto L206;
	case 17:  goto L207;
	case 18:  goto L208;
	case 19:  goto L209;
	case 20:  goto L210;
	case 21:  goto L211;
	case 22:  goto L212;
	case 23:  goto L213;
	case 24:  goto L214;
	case 25:  goto L215;
	case 26:  goto L216;
	case 27:  goto L217;
	case 28:  goto L999;
	case 29:  goto L999;
	case 30:  goto L999;
	case 31:  goto L401;
	case 32:  goto L402;
	case 33:  goto L403;
	case 34:  goto L404;
	case 35:  goto L999;
	case 36:  goto L999;
	case 37:  goto L999;
	case 38:  goto L999;
	case 39:  goto L999;
	case 40:  goto L999;
	case 41:  goto L501;
	case 42:  goto L502;
	case 43:  goto L503;
	case 44:  goto L504;
	case 45:  goto L505;
	case 46:  goto L999;
	case 47:  goto L999;
	case 48:  goto L999;
	case 49:  goto L999;
	case 50:  goto L999;
    }
L101:
    apt330_(&c__1, &c__62, &c__92, &c__93, &c__94);
    apt330_(&c_n1, &c__89, &c__90, &c__91, &c__0);
    goto L9999;
L102:
    apt330_(&c__2, &c__62, &c__80, &c__81, &c__82);
    apt330_(&c_n1, &c__77, &c__78, &c__79, &c__0);
    goto L9999;
L103:
    apt330_(&c__3, &c_n10, &c_n55, &c_n56, &c_n50);
    apt330_(&c_n1, &c_n57, &c__30, &c__31, &c__32);
    apt330_(&c_n1, &c__21, &c__22, &c__23, &c__0);
    goto L9999;
L104:
    apt330_(&c__4, &c_n10, &c__62, &c_n52, &c__70);
    apt330_(&c_n1, &c__61, &c__71, &c__72, &c__73);
    apt330_(&c_n1, &c__80, &c__81, &c__82, &c__83);
    apt330_(&c_n1, &c__84, &c__85, &c__77, &c__78);
    apt330_(&c_n1, &c__79, &c__0, &c__0, &c__0);
    goto L9999;
L105:
    apt330_(&c__5, &c_n10, &c__92, &c__93, &c__94);
    apt330_(&c_n1, &c__89, &c__90, &c__91, &c__0);
    goto L9999;
L106:
    apt330_(&c__6, &c_n10, &c__62, &c__70, &c__6);
    apt330_(&c_n1, &c_n7, &c__80, &c__81, &c__82);
    apt330_(&c_n1, &c__77, &c__78, &c__79, &c__92);
    apt330_(&c_n1, &c__93, &c__94, &c__89, &c__90);
    apt330_(&c_n1, &c__91, &c__0, &c__0, &c__0);
    goto L9999;
L107:
    apt330_(&c__7, &c_n10, &c__62, &c__67, &c__68);
    apt330_(&c_n1, &c__70, &c__6, &c_n7, &c__69);
    apt330_(&c_n1, &c__61, &c__80, &c__81, &c__82);
    apt330_(&c_n1, &c__77, &c__78, &c__79, &c__92);
    apt330_(&c_n1, &c__93, &c__94, &c__89, &c__90);
    apt330_(&c_n1, &c__91, &c__71, &c__72, &c__73);
    apt330_(&c_n1, &c__98, &c__99, &c__100, &c__0);
    goto L9999;
L201:
    apt330_(&c__11, &c__33, &c__34, &c__35, &c__24);
    apt330_(&c_n1, &c__25, &c__26, &c__42, &c__43);
    apt330_(&c_n1, &c__44, &c__117, &c__118, &c__119);
    apt330_(&c_n1, &c__120, &c__121, &c__122, &c__123);
    apt330_(&c_n1, &c__124, &c__125, &c__126, &c__127);
    apt330_(&c_n1, &c__128, &c__0, &c__0, &c__0);
    goto L9999;
L202:
    apt330_(&c__12, &c__4, &c__5, &c__0, &c__0);
    goto L9999;
L203:
    apt330_(&c__13, &c_n10, &c__47, &c__5, &c__0);
    goto L9999;
L204:
    apt330_(&c__14, &c__4, &c__129, &c__130, &c__131);
    apt330_(&c_n1, &c__36, &c__37, &c__38, &c__27);
    apt330_(&c_n1, &c__28, &c__29, &c__30, &c__31);
    apt330_(&c_n1, &c__32, &c__21, &c__22, &c__23);
    goto L9999;
L205:
    apt330_(&c__15, &c_n10, &c_n14, &c__30, &c__31);
    apt330_(&c_n1, &c__32, &c__21, &c__22, &c__23);
    goto L9999;
L206:
    apt330_(&c__16, &c_n15, &c__4, &c__0, &c__0);
    goto L9999;
L207:
    apt330_(&c__17, &c_n10, &c_n13, &c__47, &c__0);
    goto L9999;
L208:
    apt330_(&c__18, &c__20, &c_n18, &c__0, &c__0);
    goto L9999;
L209:
    apt330_(&c__19, &c_n14, &c_n12, &c__86, &c__87);
    apt330_(&c_n1, &c__88, &c__0, &c__0, &c__0);
    goto L9999;
L210:
    apt330_(&c__20, &c_n10, &c__62, &c__70, &c_n54);
    apt330_(&c_n1, &c__63, &c__64, &c__0, &c__0);
    goto L9999;
L211:
    apt330_(&c__21, &c_n10, &c_n54, &c__65, &c__66);
    apt330_(&c_n1, &c__77, &c__78, &c__79, &c__0);
    goto L9999;
L212:
    apt330_(&c__22, &c_n10, &c_n15, &c__4, &c__20);
    goto L9999;
L213:
    apt330_(&c__23, &c_n10, &c__4, &c__0, &c__0);
    goto L9999;
L214:
    apt330_(&c__24, &c_n10, &c_n16, &c__47, &c__0);
    goto L9999;
L215:
    apt330_(&c__25, &c_n10, &c_n51, &c_n54, &c__62);
    apt330_(&c_n1, &c__70, &c__63, &c__64, &c__65);
    goto L9999;
L216:
    apt330_(&c__26, &c_n51, &c_n54, &c__65, &c__66);
    apt330_(&c_n1, &c__77, &c__78, &c__79, &c__39);
    apt330_(&c_n1, &c__40, &c__41, &c__0, &c__0);
    goto L9999;
L217:
    apt330_(&c__27, &c_n10, &c_n48, &c__30, &c__31);
    apt330_(&c_n1, &c__32, &c__21, &c__22, &c__23);
    goto L9999;
L401:
    apt330_(&c__31, &c_n17, &c__58, &c__74, &c__75);
    apt330_(&c_n1, &c__76, &c__129, &c__130, &c__131);
    goto L9999;
L402:
    apt330_(&c__32, &c__46, &c__45, &c__58, &c__74);
    apt330_(&c_n1, &c__75, &c__76, &c__0, &c__0);
    goto L9999;
L403:
    apt330_(&c__33, &c_n10, &c__59, &c__60, &c__0);
    goto L9999;
L404:
    apt330_(&c__34, &c_n11, &c__103, &c_n101, &c__104);
    apt330_(&c_n1, &c__102, &c__105, &c__106, &c__107);
    apt330_(&c_n1, &c__111, &c__112, &c__113, &c__114);
    apt330_(&c_n1, &c__115, &c__116, &c__108, &c__109);
    apt330_(&c_n1, &c__110, &c__0, &c__0, &c__0);
    goto L9999;
L501:
    apt330_(&c__41, &c_n9, &c_n19, &c_n8, &c__0);
    goto L9999;
L502:
    apt330_(&c__42, &c_n10, &c_n49, &c__0, &c__0);
    goto L9999;
L503:
    apt330_(&c__43, &c_n10, &c__95, &c__96, &c__97);
    apt330_(&c_n1, &c__30, &c__31, &c__32, &c__0);
    goto L9999;
L504:
    apt330_(&c__44, &c_n10, &c_n53, &c__47, &c__77);
    apt330_(&c_n1, &c__78, &c__79, &c__0, &c__0);
    goto L9999;
L505:
    apt330_(&c__45, &c__30, &c__31, &c__32, &c__0);
    goto L9999;
L999:
    apt330_(&c__50, &c_n2, &c__0, &c__0, &c__0);
L9999:
    return 0;
} /* apt332_ */

#undef number
#undef numbr2
#undef numbr1
#undef ed


