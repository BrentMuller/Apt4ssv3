/* XCALL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : XCALL000.V06   *** */

/* Subroutine */ int xcall_(integer *ip)
{
    /* Initialized data */

    static integer term = -999;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer ac;
#define cf ((doublereal *)&_BLNK__1)
#define ia ((doublereal *)&_BLNK__1)
#define nb ((doublereal *)&_BLNK__1)
#define cm ((integer *)&_BLNK__1)
#define fp ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int go_(doublereal *, doublereal *);
#define pp ((integer *)&_BLNK__1)
#define mt ((integer *)&_BLNK__1)
#define nt ((integer *)&_BLNK__1)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cut_(void), canf_(doublereal *, doublereal *, 
	    doublereal *), absf_(doublereal *, doublereal *);
    static integer mode;
    extern /* Subroutine */ int fini_(void), cosb_(doublereal *, doublereal *)
	    , logf_(doublereal *, doublereal *), tanf_(doublereal *, 
	    doublereal *), tanb_(doublereal *, doublereal *), cosf_(
	    doublereal *, doublereal *), sinb_(doublereal *, doublereal *), 
	    dotf_(doublereal *, doublereal *, doublereal *), minf_(integer *),
	     maxf_(integer *), sinf_(doublereal *, doublereal *), modf_(
	    doublereal *, doublereal *, doublereal *), intf_(doublereal *, 
	    doublereal *), expf_(doublereal *, doublereal *), from_(
	    doublereal *), goto_(doublereal *), null_(void), tlon_(void), 
	    psis_(doublereal *, doublereal *), nops_(void), apt001_(
	    doublereal *), apt010_(doublereal *, integer *, doublereal *, 
	    doublereal *);
    extern integer apt201_(doublereal *, doublereal *);
    extern /* Subroutine */ int apt003_(doublereal *, doublereal *, 
	    doublereal *), apt004_(doublereal *, integer *, doublereal *, 
	    doublereal *), apt005_(doublereal *, integer *, doublereal *, 
	    doublereal *), apt006_(doublereal *, doublereal *, doublereal *), 
	    apt007_(doublereal *, doublereal *), apt008_(doublereal *, 
	    integer *, doublereal *, doublereal *), apt009_(doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt011_(doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt012_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), apt014_(
	    doublereal *, doublereal *, doublereal *), apt015_(doublereal *, 
	    doublereal *, integer *, doublereal *), apt016_(doublereal *, 
	    integer *, doublereal *, integer *, doublereal *), apt017_(
	    doublereal *, doublereal *, integer *, doublereal *), apt018_(
	    doublereal *, doublereal *, doublereal *), apt019_(doublereal *, 
	    doublereal *, doublereal *), apt020_(doublereal *, doublereal *, 
	    integer *, doublereal *), apt021_(doublereal *, integer *, 
	    doublereal *, integer *, doublereal *), apt022_(doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *), apt023_(
	    doublereal *, doublereal *, doublereal *), apt024_(integer *), 
	    apt025_(doublereal *, doublereal *, doublereal *), apt026_(
	    doublereal *, doublereal *, doublereal *), apt027_(doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt028_(doublereal *, 
	    doublereal *, integer *, doublereal *), apt029_(doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *), apt030_(
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *), apt031_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *), apt032_(
	    doublereal *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *), apt033_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *), apt035_(
	    doublereal *, doublereal *, doublereal *), apt036_(doublereal *, 
	    doublereal *, integer *), apt037_(doublereal *, doublereal *, 
	    doublereal *), apt038_(doublereal *, doublereal *, doublereal *), 
	    apt039_(doublereal *, doublereal *, doublereal *), apt040_(
	    doublereal *, doublereal *), apt044_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt045_(doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt046_(doublereal *, 
	    doublereal *, doublereal *), apt047_(doublereal *, doublereal *, 
	    integer *, doublereal *), apt048_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt049_(doublereal *, doublereal *, 
	    doublereal *), apt050_(doublereal *, doublereal *, doublereal *), 
	    apt051_(doublereal *, doublereal *, doublereal *), apt052_(
	    doublereal *, doublereal *, doublereal *), apt053_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), apt054_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), ldard_(integer *, doublereal *, 
	    integer *), cldat_(integer *, integer *, integer *, integer *), 
	    apt055_(doublereal *, doublereal *, doublereal *, doublereal *), 
	    apt056_(doublereal *, doublereal *, doublereal *, doublereal *), 
	    apt057_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), apt058_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt060_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), apt061_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int apt062_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), apt063_(doublereal *, doublereal *, doublereal *, 
	    doublereal *), undef_(doublereal *), thick_(integer *, doublereal 
	    *), apt064_(doublereal *, integer *, doublereal *), apt065_(
	    doublereal *, doublereal *, doublereal *, doublereal *), apt066_(
	    doublereal *, doublereal *, doublereal *, integer *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int apt067_(doublereal *, doublereal *), maxdp_(
	    doublereal *, doublereal *), apt068_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt073_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt075_(doublereal *, doublereal *), 
	    punch_(doublereal *, doublereal *, doublereal *), apt077_(
	    doublereal *, integer *), apt078_(doublereal *, integer *), 
	    apt079_(doublereal *, integer *), apt081_(doublereal *, integer *)
	    , apt083_(doublereal *, integer *), apt085_(void), apt087_(
	    doublereal *, doublereal *), tllft_(void), toler_(integer *, 
	    doublereal *), intol_(integer *, doublereal *), apt088_(
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *), apt090_(integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), apt094_(integer *, doublereal *, doublereal *), 
	    apt100_(integer *, doublereal *), tlrgt_(void), print_(integer *, 
	    doublereal *, integer *), apt200_(doublereal *, doublereal *, 
	    doublereal *), apt298_(integer *, doublereal *, doublereal *), 
	    apt299_(integer *, integer *, integer *, integer *), atanf_(), 
	    units_(integer *), lnthf_(doublereal *, doublereal *), sqrtf_(
	    doublereal *, doublereal *), apt041_(doublereal *, doublereal *, 
	    doublereal *, integer *), apt042_(doublereal *, doublereal *, 
	    doublereal *, integer *), apt043_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt295_(doublereal *, doublereal *, 
	    doublereal *), zsurf_(doublereal *), anglf_(doublereal *, 
	    doublereal *, doublereal *), apt069_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt070_(doublereal *, doublereal *, 
	    integer *, doublereal *, doublereal *), apt071_(doublereal *, 
	    doublereal *), apt072_(doublereal *, integer *, integer *, 
	    integer *), apt074_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), apt034_(
	    doublereal *, doublereal *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *), apt296_(void), apt297_(void), 
	    apt105_(doublereal *, integer *, doublereal *, integer *, 
	    doublereal *), numf1_(doublereal *, doublereal *), comp3d_(void), 
	    numf2_(doublereal *, doublereal *, doublereal *), apt106_(
	    doublereal *, doublereal *, doublereal *), apt104_(doublereal *), 
	    apt102_(doublereal *, doublereal *, doublereal *, integer *), 
	    apt103_(doublereal *, doublereal *, integer *), apt107_(
	    doublereal *, doublereal *, doublereal *, doublereal *), apt013_(
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *), apt108_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt109_(doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), distf_(doublereal *, doublereal *, 
	    doublereal *), log10f_(doublereal *, doublereal *), atanb_(
	    doublereal *, doublereal *), atan2b_(doublereal *, doublereal *), 
	    sinhf_(doublereal *, doublereal *), coshf_(doublereal *, 
	    doublereal *), tanhf_(doublereal *, doublereal *), signf_(
	    doublereal *, doublereal *, doublereal *), spatf_(doublereal *, 
	    doublereal *, doublereal *), anglb_(doublereal *, doublereal *, 
	    doublereal *), parmf1_(doublereal *, doublereal *), parmf2_(
	    doublereal *, doublereal *, doublereal *), apt110_(doublereal *, 
	    doublereal *), logif_(doublereal *, integer *, doublereal *, 
	    doublereal *), abnend_(void), cldatf_(doublereal *, doublereal *, 
	    integer *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int saveac_(integer *), cotanb_(doublereal *, 
	    doublereal *), arcosb_(doublereal *, doublereal *), godlta_(
	    doublereal *, doublereal *), cotanf_(doublereal *, doublereal *), 
	    arcosf_(doublereal *, doublereal *), arsinb_(doublereal *, 
	    doublereal *), gougck_(doublereal *), chksrf_(doublereal *, 
	    doublereal *), defext_(doublereal *), arsinf_(doublereal *, 
	    doublereal *), region_(doublereal *, doublereal *), indirp_(
	    doublereal *, doublereal *), pocket_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), unasgn_(
	    void), dyndmp_(doublereal *, doublereal *, doublereal *), indirv_(
	    doublereal *, doublereal *), avctrl_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), transf_(doublereal *, doublereal *, integer *, 
	    integer *, integer *), dntcut_(void), ndtest_(void), tlaxis_(
	    integer *, integer *, doublereal *), cutter_(integer *, 
	    doublereal *), tlofps_(void), srfvct_(doublereal *, doublereal *),
	     gotopn_(doublereal *, integer *, integer *, integer *, integer *,
	     doublereal *, doublereal *), multax_(doublereal *), autops_(void)
	    , refsys_(doublereal *), tlonps_(void), outtol_(integer *, 
	    doublereal *), numpts_(doublereal *);


/*  *  XCALL  *   VAX11 FORTRAN VERSION  17.3.82  E.MCLELLAN */

/*  PURPOSE    TO CONVERT THE PARAMETER LIST GENERATED BY 'LIB' */
/*             TO ACTUAL ADDRESSES IN UNLABELLED COMMON AND TO */
/*             PERFORM THE NECESSARY SUBROUTINE CALL */
/*  CALLING SEQUENCE */
/*             CALL XCALL(IP) */
/*  ARGUMENTS */
/*             IP   PARAMETER LIST */



/*   UNLABELED COMMON */


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*     ------------------- */

    /* Parameter adjustments */
    --ip;

    /* Function Body */


/*   SUBROUTINE MODE */

    mode = -ip[1];

/*   BRANCH ACCORDING TO SUBROUTINE MODE */

    switch (mode) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
	case 16:  goto L16;
	case 17:  goto L17;
	case 18:  goto L18;
	case 19:  goto L19;
	case 20:  goto L20;
	case 21:  goto L21;
	case 22:  goto L22;
	case 23:  goto L23;
	case 24:  goto L24;
	case 25:  goto L25;
	case 26:  goto L26;
	case 27:  goto L27;
	case 28:  goto L28;
	case 29:  goto L29;
	case 30:  goto L30;
	case 31:  goto L31;
	case 32:  goto L32;
	case 33:  goto L33;
	case 34:  goto L34;
	case 35:  goto L35;
	case 36:  goto L36;
	case 37:  goto L37;
	case 38:  goto L38;
	case 39:  goto L39;
	case 40:  goto L40;
	case 41:  goto L41;
	case 42:  goto L42;
	case 43:  goto L43;
	case 44:  goto L44;
	case 45:  goto L45;
	case 46:  goto L46;
	case 47:  goto L47;
	case 48:  goto L48;
	case 49:  goto L49;
	case 50:  goto L50;
	case 51:  goto L51;
	case 52:  goto L52;
	case 53:  goto L53;
	case 54:  goto L54;
	case 55:  goto L55;
	case 56:  goto L56;
	case 57:  goto L57;
	case 58:  goto L58;
	case 59:  goto L59;
	case 60:  goto L60;
	case 61:  goto L61;
	case 62:  goto L62;
	case 63:  goto L63;
	case 64:  goto L64;
	case 65:  goto L65;
	case 66:  goto L66;
	case 67:  goto L67;
	case 68:  goto L68;
	case 69:  goto L69;
	case 70:  goto L70;
	case 71:  goto L71;
	case 72:  goto L72;
	case 73:  goto L73;
	case 74:  goto L74;
	case 75:  goto L75;
	case 76:  goto L76;
	case 77:  goto L77;
	case 78:  goto L78;
	case 79:  goto L79;
	case 80:  goto L80;
	case 81:  goto L81;
	case 82:  goto L82;
	case 83:  goto L83;
	case 84:  goto L84;
	case 85:  goto L85;
	case 86:  goto L86;
	case 87:  goto L87;
	case 88:  goto L88;
	case 89:  goto L89;
	case 90:  goto L90;
	case 91:  goto L91;
	case 92:  goto L92;
	case 93:  goto L93;
	case 94:  goto L94;
	case 95:  goto L95;
	case 96:  goto L96;
	case 97:  goto L97;
	case 98:  goto L98;
	case 99:  goto L99;
	case 100:  goto L100;
	case 101:  goto L101;
	case 102:  goto L102;
	case 103:  goto L103;
	case 104:  goto L104;
	case 105:  goto L105;
	case 106:  goto L106;
	case 107:  goto L107;
	case 108:  goto L108;
	case 109:  goto L109;
	case 110:  goto L110;
	case 111:  goto L111;
	case 112:  goto L112;
	case 113:  goto L113;
	case 114:  goto L114;
	case 115:  goto L115;
	case 116:  goto L116;
	case 117:  goto L117;
	case 118:  goto L118;
	case 119:  goto L119;
	case 120:  goto L120;
	case 121:  goto L121;
	case 122:  goto L122;
	case 123:  goto L123;
	case 124:  goto L124;
	case 125:  goto L125;
	case 126:  goto L126;
	case 127:  goto L127;
	case 128:  goto L128;
	case 129:  goto L129;
	case 130:  goto L130;
	case 131:  goto L131;
	case 132:  goto L132;
	case 133:  goto L133;
	case 134:  goto L134;
	case 135:  goto L135;
	case 136:  goto L136;
	case 137:  goto L137;
	case 138:  goto L138;
	case 139:  goto L139;
	case 140:  goto L140;
	case 141:  goto L141;
	case 142:  goto L142;
	case 143:  goto L143;
	case 144:  goto L144;
	case 145:  goto L145;
	case 146:  goto L146;
	case 147:  goto L147;
	case 148:  goto L148;
	case 149:  goto L149;
	case 150:  goto L150;
	case 151:  goto L151;
	case 152:  goto L152;
	case 153:  goto L153;
	case 154:  goto L154;
	case 155:  goto L155;
	case 156:  goto L156;
	case 157:  goto L157;
	case 158:  goto L158;
	case 159:  goto L159;
	case 160:  goto L160;
	case 161:  goto L161;
	case 162:  goto L162;
	case 163:  goto L163;
	case 164:  goto L164;
	case 165:  goto L165;
	case 166:  goto L166;
	case 167:  goto L167;
	case 168:  goto L168;
	case 169:  goto L169;
	case 170:  goto L170;
	case 171:  goto L171;
	case 172:  goto L172;
	case 173:  goto L173;
	case 174:  goto L174;
	case 175:  goto L175;
	case 176:  goto L176;
	case 177:  goto L177;
	case 178:  goto L178;
	case 179:  goto L179;
	case 180:  goto L180;
	case 181:  goto L181;
	case 182:  goto L182;
	case 183:  goto L183;
	case 184:  goto L184;
	case 185:  goto L185;
	case 186:  goto L186;
	case 187:  goto L187;
	case 188:  goto L188;
	case 189:  goto L189;
	case 190:  goto L190;
	case 191:  goto L191;
	case 192:  goto L192;
	case 193:  goto L193;
	case 194:  goto L194;
	case 195:  goto L195;
	case 196:  goto L196;
	case 197:  goto L197;
	case 198:  goto L198;
	case 199:  goto L199;
	case 200:  goto L200;
	case 201:  goto L201;
	case 202:  goto L202;
	case 203:  goto L203;
	case 204:  goto L204;
	case 205:  goto L205;
	case 206:  goto L206;
	case 207:  goto L207;
	case 208:  goto L208;
	case 209:  goto L209;
	case 210:  goto L210;
	case 211:  goto L211;
	case 212:  goto L212;
	case 213:  goto L213;
	case 214:  goto L214;
	case 215:  goto L215;
	case 216:  goto L216;
	case 217:  goto L217;
	case 218:  goto L218;
	case 219:  goto L219;
	case 220:  goto L220;
	case 221:  goto L221;
	case 222:  goto L222;
	case 223:  goto L223;
	case 224:  goto L224;
	case 225:  goto L225;
	case 226:  goto L226;
	case 227:  goto L227;
	case 228:  goto L228;
	case 229:  goto L229;
	case 230:  goto L230;
	case 231:  goto L231;
	case 232:  goto L232;
	case 233:  goto L233;
	case 234:  goto L234;
	case 235:  goto L235;
	case 236:  goto L236;
	case 237:  goto L237;
	case 238:  goto L238;
	case 239:  goto L239;
	case 240:  goto L240;
	case 241:  goto L241;
	case 242:  goto L242;
	case 243:  goto L243;
	case 244:  goto L244;
	case 245:  goto L245;
	case 246:  goto L246;
	case 247:  goto L247;
	case 248:  goto L248;
	case 249:  goto L249;
    }
    abnend_();
    return 0;

L1:
    tllft_();
    return 0;
L2:
    tlrgt_();
    return 0;
L3:
    tlon_();
    return 0;
L4:
    tlonps_();
    return 0;
L5:
    tlofps_();
    return 0;
L6:
    multax_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L7:
    nops_();
    return 0;
L8:
    autops_();
    return 0;
L9:
    cut_();
    return 0;
L10:
    dntcut_();
    return 0;
L11:
    ndtest_();
    return 0;
L12:
    comp3d_();
    return 0;
L13:
    gougck_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L14:
    unasgn_();
    return 0;
L15:
    unasgn_();
    return 0;
L16:
    unasgn_();
    return 0;
L17:
    refsys_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L18:
    fini_();
    return 0;
L19:
    unasgn_();
    return 0;
L20:
    unasgn_();
    return 0;
L21:
    unasgn_();
    return 0;
L22:
    dyndmp_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L23:
    zsurf_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L24:
    unasgn_();
    return 0;
L25:
    go_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L26:
    godlta_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L27:
    toler_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L28:
    intol_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L29:
    outtol_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L30:
    cutter_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L31:
    maxdp_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L32:
    numpts_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L33:
    thick_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L34:
    unasgn_();
    return 0;
L35:
    goto_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L36:
    from_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L37:
    indirv_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L38:
    srfvct_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L39:
    tlaxis_(&cm[(ip[2] << 1) - 2], &cm[(ip[3] << 1) - 2], &_BLNK__1.com[ip[4] 
	    - 1]);
    return 0;
L40:
    indirp_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L41:
    psis_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L42:
    print_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1], &cm[(ip[4] << 1) 
	    - 2]);
    return 0;
L43:
    unasgn_();
    return 0;
L44:
    unasgn_();
    return 0;
L45:
    unasgn_();
    return 0;
L46:
    unasgn_();
    return 0;
L47:
    unasgn_();
    return 0;
L48:
    pocket_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1], &_BLNK__1.com[
	    ip[9] - 1], &_BLNK__1.com[ip[10] - 1], &_BLNK__1.com[ip[11] - 1]);
    return 0;
L49:
    unasgn_();
    return 0;
L50:
    punch_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L51:
    unasgn_();
    return 0;
L52:
    unasgn_();
    return 0;
L53:
    unasgn_();
    return 0;
L54:
    unasgn_();
    return 0;
L55:
    unasgn_();
    return 0;
L56:
    unasgn_();
    return 0;
L57:
    ldard_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1], &cm[(ip[4] << 1) 
	    - 2]);
    return 0;
L58:
    units_(&cm[(ip[2] << 1) - 2]);
    return 0;
L59:
    unasgn_();
    return 0;
L60:
    unasgn_();
    return 0;
L61:
    unasgn_();
    return 0;
L62:
    unasgn_();
    return 0;
L63:
    cldat_(&cm[(ip[2] << 1) - 2], &cm[(ip[3] << 1) - 2], &cm[(ip[4] << 1) - 2]
	    , &cm[(ip[5] << 1) - 2]);
    return 0;
L64:
    chksrf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L65:
    avctrl_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L66:
    region_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L67:
    unasgn_();
    return 0;
L68:
    unasgn_();
    return 0;
L69:
    unasgn_();
    return 0;
L70:
    unasgn_();
    return 0;
L71:
    unasgn_();
    return 0;
L72:
    unasgn_();
    return 0;
L73:
    unasgn_();
    return 0;
L74:
    unasgn_();
    return 0;
L75:
    unasgn_();
    return 0;
L76:
    unasgn_();
    return 0;
L77:
    unasgn_();
    return 0;
L78:
    unasgn_();
    return 0;
L79:
    unasgn_();
    return 0;
L80:
    unasgn_();
    return 0;
L81:
    unasgn_();
    return 0;
L82:
    unasgn_();
    return 0;
L83:
    unasgn_();
    return 0;
L84:
    unasgn_();
    return 0;
L85:
    unasgn_();
    return 0;
L86:
    unasgn_();
    return 0;
L87:
    unasgn_();
    return 0;
L88:
    unasgn_();
    return 0;
L89:
    unasgn_();
    return 0;
L90:
    unasgn_();
    return 0;
L91:
    unasgn_();
    return 0;
L92:
    unasgn_();
    return 0;
L93:
    unasgn_();
    return 0;
L94:
    unasgn_();
    return 0;
L95:
    unasgn_();
    return 0;
L96:
    unasgn_();
    return 0;
L97:
    unasgn_();
    return 0;
L98:
    unasgn_();
    return 0;
L99:
    unasgn_();
    return 0;
L100:
    undef_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L101:
    apt001_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L102:
    apt003_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L103:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt004_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L104:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt005_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L105:
    apt006_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L106:
    apt007_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L107:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt008_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L108:
    apt009_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L109:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt010_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L110:
    apt011_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L111:
    apt012_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L112:
    apt014_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L113:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt015_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L114:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    apt016_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &_BLNK__1.com[ip[6] - 1]);
    return 0;
L115:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt017_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L116:
    apt018_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L117:
    apt019_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L118:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt020_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L119:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    apt021_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &_BLNK__1.com[ip[6] - 1]);
    return 0;
L120:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt022_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L121:
    apt023_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L122:
    i__1 = (integer) _BLNK__1.com[ip[2] - 1];
    apt024_(&i__1);
    return 0;
L123:
    apt025_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L124:
    apt026_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L125:
    apt027_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L126:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt028_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L127:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt029_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L128:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    apt030_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &_BLNK__1.com[ip[6] - 1], &_BLNK__1.com[ip[7] - 1]);
    return 0;
L129:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[4] - 1];
    i__3 = (integer) _BLNK__1.com[ip[6] - 1];
    apt031_(&_BLNK__1.com[ip[2] - 1], &i__1, &i__2, &_BLNK__1.com[ip[5] - 1], 
	    &i__3, &_BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L130:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    i__3 = (integer) _BLNK__1.com[ip[6] - 1];
    apt032_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &i__3, &_BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L131:
    i__1 = cm[(ip[10] << 1) - 2];
    apt033_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1], &_BLNK__1.com[
	    ip[9] - 1], &i__1, &_BLNK__1.com[ip[11] - 1]);
    return 0;
L132:
    apt035_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L133:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt036_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1);
    return 0;
L134:
    apt037_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L135:
    apt038_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L136:
    apt039_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L137:
    apt040_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L138:
    apt044_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L139:
    apt045_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L140:
    apt046_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L141:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt047_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1]);
    return 0;
L142:
    apt048_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L143:
    apt049_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L144:
    apt050_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L145:
    apt051_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L146:
    apt052_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L147:
    apt053_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L148:
    apt054_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1]);
    return 0;
L149:
    apt055_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L150:
    apt056_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L151:
    apt057_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L152:
    apt058_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L153:
    apt060_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L154:
    i__1 = (integer) _BLNK__1.com[ip[8] - 1];
    apt061_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[6] - 1], &i__1);
    return 0;
L155:
    apt062_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1], &_BLNK__1.com[
	    ip[9] - 1], &_BLNK__1.com[ip[10] - 1], &_BLNK__1.com[ip[11] - 1], 
	    &_BLNK__1.com[ip[12] - 1]);
    return 0;
L156:
    apt063_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L157:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt064_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1]);
    return 0;
L158:
    apt065_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L159:
    i__1 = (integer) _BLNK__1.com[ip[5] - 1];
    apt066_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &i__1);
    return 0;
L160:
    apt067_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L161:
    apt068_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L162:
    apt073_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L163:
    apt075_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L164:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt077_(&_BLNK__1.com[ip[2] - 1], &i__1);
    return 0;
L165:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt078_(&_BLNK__1.com[ip[2] - 1], &i__1);
    return 0;
L166:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt079_(&_BLNK__1.com[ip[2] - 1], &i__1);
    return 0;
L167:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt081_(&_BLNK__1.com[ip[2] - 1], &i__1);
    return 0;
L168:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt083_(&_BLNK__1.com[ip[2] - 1], &i__1);
    return 0;
L169:
    apt085_();
    return 0;
L170:
    apt087_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L171:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    i__3 = (integer) _BLNK__1.com[ip[6] - 1];
    i__4 = (integer) _BLNK__1.com[ip[7] - 1];
    apt088_(&_BLNK__1.com[ip[2] - 1], &i__1, &cm[(ip[4] << 1) - 2], &i__2, &
	    i__3, &i__4, &_BLNK__1.com[ip[8] - 1]);
    return 0;
L172:
    apt090_(&cm[(ip[2] << 1) - 2], &_BLNK__1.com[ip[3] - 1], &cm[(ip[4] << 1) 
	    - 2], &_BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1], &_BLNK__1.com[
	    ip[9] - 1]);
    return 0;
L173:
    unasgn_();
    return 0;
L174:
    unasgn_();
    return 0;
L175:
    i__1 = (integer) _BLNK__1.com[ip[2] - 1];
    apt094_(&i__1, &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[ip[4] - 1]);
    return 0;
L176:
    i__1 = (integer) _BLNK__1.com[ip[2] - 1];
    apt100_(&i__1, &_BLNK__1.com[ip[3] - 1]);
    return 0;
L177:
    apt200_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L178:
    ac = apt201_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    saveac_(&ac);
    return 0;
L179:
    i__1 = (integer) _BLNK__1.com[ip[2] - 1];
    apt298_(&i__1, &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[ip[4] - 1]);
    return 0;
L180:
    apt299_(&cm[(ip[2] << 1) - 2], &cm[(ip[3] << 1) - 2], &cm[(ip[4] << 1) - 
	    2], &cm[(ip[5] << 1) - 2]);
    return 0;
L181:
    absf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L182:
    atanf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L183:
    unasgn_();
    return 0;
L184:
    cosf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L185:
    null_();
    return 0;
L186:
    dotf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L187:
    expf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L188:
    unasgn_();
    return 0;
L189:
    lnthf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L190:
    logf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L191:
    sinf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L192:
    sqrtf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L193:
    i__1 = (integer) _BLNK__1.com[ip[5] - 1];
    apt041_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &i__1);
    return 0;
L194:
    i__1 = (integer) _BLNK__1.com[ip[5] - 1];
    apt042_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &i__1);
    return 0;
L195:
    apt043_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L196:
    apt295_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L197:
    anglf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L198:
    apt069_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L199:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt070_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1]);
    return 0;
L200:
    apt071_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L201:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[4] - 1];
    i__3 = (integer) _BLNK__1.com[ip[5] - 1];
    apt072_(&_BLNK__1.com[ip[2] - 1], &i__1, &i__2, &i__3);
    return 0;
L202:
    defext_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L203:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt074_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &_BLNK__1.com[
	    ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L204:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    i__2 = (integer) _BLNK__1.com[ip[6] - 1];
    apt034_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &
	    _BLNK__1.com[ip[5] - 1], &i__2, &_BLNK__1.com[ip[7] - 1], &
	    _BLNK__1.com[ip[8] - 1]);
    return 0;
L205:
    apt296_();
    return 0;
L206:
    apt297_();
    return 0;
/*  207 CALL APT101(COM(IP(2)),COM(IP(3)),COM(IP(4)),INT(COM(IP(5))), */
/*    1            COM(IP(6)),COM(IP(7)),COM(IP(8)),COM(IP(9)), */
/*     2            COM(IP(10)),COM(IP(11)),COM(IP(12))) */
L207:
    unasgn_();
    return 0;
L208:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[4] - 1];
    i__3 = (integer) _BLNK__1.com[ip[5] - 1];
    i__4 = (integer) _BLNK__1.com[ip[6] - 1];
    gotopn_(&_BLNK__1.com[ip[2] - 1], &i__1, &i__2, &i__3, &i__4, &
	    _BLNK__1.com[ip[7] - 1], &_BLNK__1.com[ip[8] - 1]);
    return 0;
L209:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    apt105_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &_BLNK__1.com[ip[6] - 1]);
    return 0;
L210:
    if (ip[4] == term) {
	numf1_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    } else {
	numf2_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &
		_BLNK__1.com[ip[4] - 1]);
    }
    return 0;
L211:
    apt106_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L212:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    i__3 = (integer) _BLNK__1.com[ip[6] - 1];
    transf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1, &i__2, 
	    &i__3);
    return 0;
L213:
    apt104_(&_BLNK__1.com[ip[2] - 1]);
    return 0;
L214:
    i__1 = (integer) _BLNK__1.com[ip[5] - 1];
    apt102_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &i__1);
    return 0;
L215:
    i__1 = (integer) _BLNK__1.com[ip[4] - 1];
    apt103_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &i__1);
    return 0;
L216:
    apt107_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L217:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    i__2 = (integer) _BLNK__1.com[ip[5] - 1];
    i__3 = (integer) _BLNK__1.com[ip[7] - 1];
    apt013_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &i__2, 
	    &_BLNK__1.com[ip[6] - 1], &i__3, &_BLNK__1.com[ip[8] - 1]);
    return 0;
L218:
    apt108_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L219:
    i__1 = (integer) _BLNK__1.com[ip[3] - 1];
    apt109_(&_BLNK__1.com[ip[2] - 1], &i__1, &_BLNK__1.com[ip[4] - 1], &
	    _BLNK__1.com[ip[5] - 1], &_BLNK__1.com[ip[6] - 1], &_BLNK__1.com[
	    ip[7] - 1], &_BLNK__1.com[ip[8] - 1], &_BLNK__1.com[ip[9] - 1]);
    return 0;
L220:
    distf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L221:
    log10f_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L222:
    tanf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L223:
    atanf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L224:
    cotanf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L225:
    arsinf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L226:
    arcosf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L227:
    sinb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L228:
    cosb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L229:
    tanb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L230:
    cotanb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L231:
    arsinb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L232:
    arcosb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L233:
    atanb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L234:
    atan2b_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L235:
    sinhf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L236:
    coshf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L237:
    tanhf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L238:
    minf_(&ip[1]);
    return 0;
L239:
    maxf_(&ip[1]);
    return 0;
L240:
    modf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L241:
    intf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L242:
    signf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L243:
    spatf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L244:
    anglb_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L245:
    if (ip[4] == term) {
	parmf1_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    } else {
	parmf2_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &
		_BLNK__1.com[ip[4] - 1]);
    }
    return 0;
L246:
    canf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &_BLNK__1.com[
	    ip[4] - 1]);
    return 0;
L247:
    apt110_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1]);
    return 0;
L248:
    logif_(&_BLNK__1.com[ip[2] - 1], &cm[(ip[3] << 1) - 2], &_BLNK__1.com[ip[
	    4] - 1], &_BLNK__1.com[ip[5] - 1]);
    return 0;
L249:
    cldatf_(&_BLNK__1.com[ip[2] - 1], &_BLNK__1.com[ip[3] - 1], &cm[(ip[4] << 
	    1) - 2], &_BLNK__1.com[ip[5] - 1]);
    return 0;
} /* xcall_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef nt
#undef mt
#undef pp
#undef fp
#undef cm
#undef nb
#undef ia
#undef cf


