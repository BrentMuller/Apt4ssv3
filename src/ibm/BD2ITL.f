**** SOURCE FILE : M0006620.IBM;1   ***
*
C                                                 8/81     MBB
C...  FORTRAN BLOCK DATA               BD2ITL
C                                                 8/81     MBB
      BLOCK DATA BD2ITL
C
      IMPLICIT INTEGER (A-Z)
C
C...         2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST,STACK,ARGSTK
      DIMENSION STKLST(3),STACK(2,99),ARGSTK(99)
C
      EQUIVALENCE(STKLST(1),TOP),(STKLST(2),ARGTOP),(STKLST(3),IARGDM)
C
C
C...         5.    PROGRAM CONTROL FLAGS
C
      COMMON/FLAGS/FLAGS
      DIMENSION FLAGS(4)
      LOGICAL ENDFLG,NEWSTM,APTRAN,REFFLG
C
      EQUIVALENCE(FLAGS(1),ENDFLG),(FLAGS(2),NEWSTM),(FLAGS(3),APTRAN),
     1           (FLAGS(4),REFFLG)
C
C
C...         6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C
      COMMON/TMP/TXXXX
      DIMENSION TXXXX(2,32)
C
C
C...      13.      NAMTBL POINTERS TO NEGATIVE NUMBERS
C
      COMMON/NEGPTR/NONEPT
C
C...        11.    SEQUENCE NUMBER STORAGE
C
C                  COMMENT OF  SEQNO AND SEQNUM
C
      INCLUDE 'SEQCOM.INC'
C
C...        12.    LARGE DATA ARRAY STORAGE REQUIREMENTS
C
      COMMON/CFSIZE/CFSIZE,MAXSIZ,CANSIZ,ISC,KSC
      DIMENSION  CFSIZE(3),MAXSIZ(2),CANSIZ(2,100),KSC(3,300)
      LOGICAL PARDEF,TABCYS
C
      EQUIVALENCE(CFSIZE(1),CANTOP),(CFSIZE(2),PARDEF),
     1           (CFSIZE(3),TABCYS)
C
C
C...      14.      I. L. LIST OPTION FLAGS
C
      COMMON/PRT/PRT
      DIMENSION PRT(7)
      LOGICAL    CILPRT,  ILPRT, INTERP, ASSEMB, TRACFL
     /          ,PRTERR,  MCHDNG
C
      EQUIVALENCE(PRT(1),CILPRT),(PRT(2),ILPRT ),(PRT(3),INTERP),
     1           (PRT(4),ASSEMB),(PRT(5),TRACFL),(PRT(6),PRTERR),
     2           (PRT(7),MCHDNG)
C
C
C...        15.    ARRAY LIMIT STORAGE
C
      COMMON/SBSCPT/RNGPT,RANGE
      DIMENSION RANGE(400)
C
C...        16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C
      EQUIVALENCE(IL( 1),FADD  ),(IL( 2),FSUB  ),(IL( 3),FMPY  ),
     1           (IL( 4),FDIV  ),(IL( 5),FEXP  ),(IL( 6),LABELX),
     2           (IL( 7),ENTRYX),(IL( 8),JUMP  ),(IL( 9),SEQNCE),
     3           (IL(10),RETMC ),(IL(11),CONJMP),(IL(12),RESRV ),
     4           (IL(13),CVTSUB),(IL(14),CALMC ),(IL(15),ASNADD),
     5           (IL(16),ASNJMP),(IL(17),REPL  ),(IL(18),CALL  ),
     7           (IL(19),MOVE  ),(IL(20),VBLJMP),(IL(21),HOLDAT)
C
C
C...        17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C
      EQUIVALENCE(MODX( 1),LINE  ),(MODX( 2),PLANE ),(MODX( 3),CYLNDR),
     1           (MODX( 4),CIRCLE),(MODX( 5),SPHERE),(MODX( 6),HYPERB),
     2           (MODX( 7),CONIC ),(MODX( 8),ELLIPS),(MODX( 9),CONE  ),
     3           (MODX(10),GCONIC),(MODX(11),TABCYL),(MODX(12),RLDSRF),
     4           (MODX(13),POLCON),(MODX(14),QADRIC),(MODX(15),PARSRF),
     5           (MODX(16),UNUS1 ),(MODX(17),UNUS2 ),(MODX(18),MATRIX),
     6           (MODX(19),POINT ),(MODX(20),VECTOR),(MODX(21),REAL  ),
     7           (MODX(22),INTGER),(MODX(23),BOOL  ),(MODX(24),SUBSCR),
     8           (MODX(25),STRING),(MODX(26),PATERN),(MODX(27),BOUNDS),
     9           (MODX(28),OBJECT),(MODX(29),SSURF ),(MODX(30),SCURV ),
     A           (MODX(31),UNUS3 ),(MODX(32),UNUS4 )
C
C
C...        18.    STRING STORAGE AREA
C
      COMMON/CHRX/CHR
      CHARACTER CHR*400
C
C...      19.      INTERMEDIATE LANGUAGE TEXT
C
      COMMON/ILTEXT/ILTEXT,TEXTIN
      DIMENSION TEXTIN(90),ILTEXT(4)
      LOGICAL COMFIN
      EQUIVALENCE(ILTEXT(1),COMFIN),(ILTEXT(2),LENGTH),
     1           (ILTEXT(3),TPNTRX),(ILTEXT(4),OPTEXT)
C
C
C         22.      MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      DIMENSION MACXX1(71)
      LOGICAL MACLDD ,CALLON ,CALLMV ,ILHLT  ,MVMAC  ,MACRED ,MVTRUE ,
     1        FINMAC ,ENTRY  ,NESTG  ,ENDMCH ,MACLK  ,MACEND ,SHOULD
C
      EQUIVALENCE(MACXX1( 1),MACDFP),(MACXX1( 2),MCNMB ),
     1           (MACXX1( 3),MCHSTP),(MACXX1( 4),MCTXTP),
     2           (MACXX1( 5),MCSAVP),(MACXX1( 6),MNMVBP),
     3           (MACXX1( 7),MACLDD),(MACXX1( 8),TEMP1 ),
     4           (MACXX1( 9),TEMP2 ),(MACXX1(10),CALLON),
     5           (MACXX1(11),CALLMV),(MACXX1(12),MVSEG ),
     6           (MACXX1(13),CALLPT),(MACXX1(14),ILHLT ),
     7           (MACXX1(15),TEXTST),(MACXX1(16),MVPNT ),
     8           (MACXX1(17),MVMAC ),(MACXX1(18),MACRED),
     9           (MACXX1(19),MVTRUE),(MACXX1(20),BRANCH),
     A           (MACXX1(21),MAXSPS),(MACXX1(22),INTMED)
      EQUIVALENCE(MACXX1(23),MAJWRD),(MACXX1(24),FINMAC),
     1           (MACXX1(25),NMLINE),(MACXX1(26),WAY   ),
     2           (MACXX1(27),NUMVAR),(MACXX1(28),NUMCAL),
     3           (MACXX1(29),BITWDS),(MACXX1(30),MBPTR ),
     4           (MACXX1(31),LSTWRT),(MACXX1(32),MCDFDM),
     5           (MACXX1(33),MHSTDM),(MACXX1(34),MCSVDM),
     6           (MACXX1(35),MNMVDM),(MACXX1(36),MSEQDM),
     7           (MACXX1(37),MACLNT),(MACXX1(38),MCSLNT),
     8           (MACXX1(39),MSP   ),(MACXX1(40),ENTRY ),
     9           (MACXX1(41),MVEXST),(MACXX1(42),MACTOP),
     A           (MACXX1(43),MCSTRT),(MACXX1(44),MAJOR )
      EQUIVALENCE(MACXX1(45),NESTG ),(MACXX1(46),ROUTE ),
     1           (MACXX1(47),ROAD  ),(MACXX1(48),SAVMSP),
     2           (MACXX1(49),TYP   ),(MACXX1(50),ENDMCH),
     3           (MACXX1(51),LNUSDP),(MACXX1(52),MCTOPP),
     4           (MACXX1(53),LNSDDM),(MACXX1(54),MVARDM),
     5           (MACXX1(55),MASDM ),(MACXX1(56),NUMBIT),
     6           (MACXX1(57),MCSPDP),(MACXX1(58),MACLK ),
     7           (MACXX1(59),MCSRCH),(MACXX1(60),MACFND),
     8           (MACXX1(61),NUMARG),(MACXX1(62),MACEND),
     9           (MACXX1(63),WHCHMN),(MACXX1(64),LARGMV),
     A           (MACXX1(65),MSPDDM),(MACXX1(66),VBLSVP)
      EQUIVALENCE(MACXX1(67),IVSVDM),(MACXX1(68),PATHLN),
     1           (MACXX1(69),NEXTLN),(MACXX1(70),SHOULD),
     2           (MACXX1(71),PATHCH)
C
C
C         23.      MACRO PROCESSING ARRAYS
C
      COMMON/MACXX2/MACXX2
      DIMENSION MACXX2(902),MBREC(2),MBUFF(350,2),MACRTB(200)
      EQUIVALENCE(MACXX2(  1),MBREC(1)),(MACXX2( 3),MBUFF(1,1))
      EQUIVALENCE(MACXX2(703),MACRTB(1))
C
C         24.      MACRO PROCESSING ARRAYS
C
      COMMON/MACXX3/MACXX3
      DIMENSION MACXX3(2630),MACDF1(400),MACDF2(400),MACHST(1800),
     1                       MACSV1( 10),MACSV2( 10),MACSV3( 10)
      EQUIVALENCE(MACXX3(   1),MACDF1(1)),(MACXX3( 401),MACDF2(1)),
     1           (MACXX3( 801),MACHST(1)),(MACXX3(2601),MACSV1(1)),
     2           (MACXX3(2611),MACSV2(1)),(MACXX3(2621),MACSV3(1))
C
C         25.      MACRO PROCESSING ARRAYS
C
      COMMON/MACXX4/MACXX4
      DIMENSION MACXX4( 100),MNMVB ( 25),MNMVC ( 25),MACSEQ( 50)
      EQUIVALENCE(MACXX4( 1),MNMVB(1)),(MACXX4(26),MNMVC(1)),
     1           (MACXX4(51),MACSEQ(1))
C
C         25A.     MACRO PROCESSING ARRAYS
C
      COMMON/MACXX5/ITMPSV
      DIMENSION ITMPSV(135)
C
C         26.      MACRO PROCESSING ARRAYS
C
      COMMON/MACXX6/MACXX6
      DIMENSION MACXX6(1300),VBLSAV(900)
      EQUIVALENCE(MACXX6(401),VBLSAV(1))
C
C         26A.     MACRO PROCESSING ARRAYS
C
      COMMON/MACXX7/MACXX7
      DIMENSION MACXX7(182),LINUSD(50),MAS(100),MACVAR(32)
      EQUIVALENCE(MACXX7(  1),LINUSD(1)),(MACXX7( 51),MAS(1)),
     1           (MACXX7(151),MACVAR(1))
C
C...        27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION    OPMOD(8)
C
      EQUIVALENCE(OPMOD(1),NOUGHT),(OPMOD(2),DLR   ),(OPMOD(3),DBLDLR),
     1           (OPMOD(4),TRPDLR),(OPMOD(5),QUADLR),(OPMOD(6),QUIDLR),
     2           (OPMOD(7),HEXDLR),(OPMOD(8),SPTDLR)
C
C
C...        29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULO,MODHLF
C
C...        30.   NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK
C
      COMMON/BLKCFS/FIRST
      DIMENSION  FIRST(2,3)
C....
C           31.   COMMON BLOCK FOR PRO026 AND MOTION
C....
      COMMON /COMP26/COMP26,TAGTBL
      DIMENSION TAGTBL(3),COMP26(13)
      LOGICAL FEDSAV, FMTERR, MCSJMP, JMPING
C
      EQUIVALENCE(COMP26( 1),INTOF ),(COMP26( 2),ARGCNT),
     1           (COMP26( 3),CSPNTR),(COMP26( 4),JMPCS ),
     2           (COMP26( 5),NUMBCS),(COMP26( 6),TEST  ),
     3           (COMP26( 7),TEST1 ),(COMP26( 8),FEDSAV),
     4           (COMP26( 9),FMTERR),(COMP26(10),MCSJMP),
     5           (COMP26(11),JMPING),(COMP26(12),K     ),
     6           (COMP26(13),LERR  )
C
C
C           32.   COMMON BLOCK FOR SETBIT AND BITMCH
C
      COMMON/BITCOM/BIT
      DIMENSION BIT(32)
      DIMENSION LOBIT(16),HIBIT(16)
      EQUIVALENCE (LOBIT(1),BIT(1)),(HIBIT(1),BIT(17))
C...
C ...       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE
C
C
      COMMON/BGEOM/BGEOM
      DIMENSION     BGEOM(4)
C
      EQUIVALENCE(BGEOM(1),IFBNDS),(BGEOM(2),IFDUMP),(BGEOM(3),J     ),
     1           (BGEOM(4),L     )
C
C           36.    SYSTEM MACRO AND SEGMENT READ VARIABLES
C
      COMMON/MACSEG/MACSEG
      DIMENSION     MACSEG(6)
      LOGICAL ALOPN,LMRSTR,LMREND
C
      EQUIVALENCE(MACSEG(1),ALOPN ),(MACSEG(2),NMSEG ),
     1           (MACSEG(3),NMMAC ),(MACSEG(4),LMRSTR),
     2           (MACSEG(5),ITMPCT),(MACSEG(6),LMREND)
C
C...        37.    INCLUSIVE SUBSCRIPT VARIABLES
C
      COMMON/ISSCOM/ISSCOM,ISSTRM
      DIMENSION ISSTRM(2),ISSCOM(7)
      LOGICAL ISSFL,ISSEND
C
      EQUIVALENCE(ISSCOM(1),ISSA  ),(ISSCOM(2),ISSB  ),
     1           (ISSCOM(3),ISSC  ),(ISSCOM(4),ISSVBL),
     2           (ISSCOM(5),ISSMOD),(ISSCOM(6),ISSFL ),
     3           (ISSCOM(7),ISSEND)
C
C
C...        39.    COMMON BLOCK LIBRARY PRINTING FLAG
C
      COMMON/LIBPRT/LIBPRT
      LOGICAL       LIBPRT
C
C...        41.    NUMBER TABLE OVERFLOW VARIABLES
C
      COMMON/NTBL/NTBL
      DIMENSION   NTBL(6)
C
      EQUIVALENCE(NTBL(1),NMOD  ),(NTBL(2),NCRNT ),(NTBL(3),NNDX  ),
     1           (NTBL(4),NLAST ),(NTBL(5),NSTR  ),(NTBL(6),NMAX  )
C
C
C           42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE
C
      COMMON/CANSTR/CANSTR,CANSTK
      DIMENSION CANSTK(16),CANSTR(2)
C
      EQUIVALENCE(CANSTR(1),CANPTR),(CANSTR(2),CANCHK)
C
C
C           43.    COMMON BLOCK FOR LOOP
C
      COMMON/DOLOOP/DOLOOP
      DIMENSION DOLOOP(9)
      LOGICAL DOFLAG,DLRFLG,IFFLAG
C
      EQUIVALENCE(DOLOOP(1),JUMPTO),(DOLOOP(2),ABSDO ),
     1           (DOLOOP(3),RELDO ),(DOLOOP(4),DONEST),
     2           (DOLOOP(5),DOMAX ),(DOLOOP(6),DOJUMP),
     3           (DOLOOP(7),DOFLAG),(DOLOOP(8),DLRFLG),
     4           (DOLOOP(9),IFFLAG)
C
C
C           44.    COMMON BLOCK FOR ERROR POSITIONS
C
      COMMON/ERRPOS/ERRPOS
      INTEGER ERRPOS(302),ERRPNT(100),ESTACK(100),ERGSTK(100)
      LOGICAL NOWARN
C
      EQUIVALENCE(ERRPOS(1),NOWARN),(ERRPOS(3),ERRPNT(1)),
     1           (ERRPOS(103),ESTACK(1)),(ERRPOS(203),ERGSTK(1))
C
C
C           45.    NUMBER TABLE INDICES
C
      INCLUDE 'NUMBLK.INC'
                          
C     DATA STATEMENTS
C
C...         2.    STACK AND POINTER STORAGE
C
      DATA TOP,ARGTOP,IARGDM/0,0,99/
C
C...         5.    PROGRAM CONTROL FLAGS
C
      DATA ENDFLG,NEWSTM,APTRAN,REFFLG/.TRUE.,.TRUE.,.FALSE.,.FALSE./
C
C...         6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C
C***  DATA SPECIFICATIONS TO COMPLEMENT 'INITAL'
C
C     LINE
      DATA TXXXX(1, 1),TXXXX(2, 1)/4,0/
C     PLANE
      DATA TXXXX(1, 2),TXXXX(2, 2)/4,0/
C     CYLINDER
      DATA TXXXX(1, 3),TXXXX(2, 3)/7,0/
C     CIRCLE
      DATA TXXXX(1, 4),TXXXX(2, 4)/7,0/
C     SPHERE
      DATA TXXXX(1, 5),TXXXX(2, 5)/4,0/
C     HYPERBOLA
      DATA TXXXX(1, 6),TXXXX(2, 6)/10,0/
C     LOFT CONIC
      DATA TXXXX(1, 7),TXXXX(2, 7)/10,0/
C     ELLIPSE
      DATA TXXXX(1, 8),TXXXX(2, 8)/10,0/
C     CONE
      DATA TXXXX(1, 9),TXXXX(2, 9)/7,0/
C     GENERAL CONIC
      DATA TXXXX(1,10),TXXXX(2,10)/10,0/
C     TABULATED CYLINDER
      DATA TXXXX(1,11),TXXXX(2,11)/2,0/
C     RULED SURFACE
      DATA TXXXX(1,12),TXXXX(2,12)/2,0/
C     POLYCONIC SURFACE
      DATA TXXXX(1,13),TXXXX(2,13)/2,0/
C     QUADRIC
      DATA TXXXX(1,14),TXXXX(2,14)/10,0/
C     PARAMETRIC SURFACE
      DATA TXXXX(1,15),TXXXX(2,15)/10,0/
C     UNUSED
      DATA TXXXX(1,16),TXXXX(2,16)/0,0/
C     UNUSED
      DATA TXXXX(1,17),TXXXX(2,17)/0,0/
C     MATRIX
      DATA TXXXX(1,18),TXXXX(2,18)/12,0/
C     POINT
      DATA TXXXX(1,19),TXXXX(2,19)/3,0/
C     VECTOR
      DATA TXXXX(1,20),TXXXX(2,20)/3,0/
C     REAL
      DATA TXXXX(1,21),TXXXX(2,21)/1,0/
C     INTEGER
      DATA TXXXX(1,22),TXXXX(2,22)/1,0/
C     BOOLEAN
      DATA TXXXX(1,23),TXXXX(2,23)/1,0/
C     SUBSCRIPT
      DATA TXXXX(1,24),TXXXX(2,24)/1,0/
C     STRING
      DATA TXXXX(1,25),TXXXX(2,25)/12,0/
C     PATERN
      DATA TXXXX(1,26),TXXXX(2,26)/2,0/
C     BOUNDS
      DATA TXXXX(1,27),TXXXX(2,27)/0,0/
C     OBJECT
      DATA TXXXX(1,28),TXXXX(2,28)/0,0/
C     SSURF
      DATA TXXXX(1,29),TXXXX(2,29)/2,0/
C     SCURV
      DATA TXXXX(1,30),TXXXX(2,30)/2,0/
C     UNUSED
      DATA TXXXX(1,31),TXXXX(2,31)/0,0/
C     UNUSED
      DATA TXXXX(1,32),TXXXX(2,32)/0,0/
C
C...      13.      NAMTBL POINTERS TO NEGATIVE NUMBERS
C
C
C...        11.    SEQUENCE NUMBER STORAGE
C
      DATA     SEQNO/1/
C
C...        12.    LARGE DATA ARRAY STORAGE REQUIREMENTS
C
      DATA  MAXSIZ,CANSIZ,KSC,CANTOP,ISC /1102*0,100,3/
      DATA PARDEF,TABCYS/.FALSE.,.FALSE./
C
C...      14.      I. L. LIST OPTION FLAGS
C
      DATA       CILPRT,  ILPRT, INTERP, ASSEMB, TRACFL
     /          ,PRTERR,  MCHDNG/
     /           2*.FALSE.,.TRUE.,4*.FALSE./
C
C...        15.    ARRAY LIMIT STORAGE
C
      DATA RNGPT,RANGE/1,400*0/
C
C...        16.    LITERALS FOR I. L. OPERATION CODES
C
      DATA FADD  / 1/
      DATA FSUB  / 2/
      DATA FMPY  / 3/
      DATA FDIV  / 4/
      DATA FEXP  / 5/
      DATA LABELX/ 6/
      DATA ENTRYX/ 7/
      DATA JUMP  / 8/
      DATA SEQNCE/ 9/
      DATA RETMC /10/
      DATA CONJMP/11/
      DATA RESRV /12/
      DATA CVTSUB/13/
      DATA CALMC /14/
      DATA ASNADD/15/
      DATA ASNJMP/16/
      DATA REPL  /17/
      DATA CALL  /18/
      DATA MOVE  /19/
      DATA VBLJMP/20/
      DATA HOLDAT/21/
C
C...        17.    MODE CODES
C
      DATA  LINE  / 1/
      DATA  PLANE / 2/
      DATA  CYLNDR/ 3/
      DATA  CIRCLE/ 4/
      DATA  SPHERE/ 5/
      DATA  HYPERB/ 6/
      DATA  CONIC / 7/
      DATA  ELLIPS/ 8/
      DATA  CONE  / 9/
      DATA  GCONIC/10/
      DATA  TABCYL/11/
      DATA  RLDSRF/12/
      DATA  POLCON/13/
      DATA  QADRIC/14/
      DATA  PARSRF/15/
      DATA  UNUS1 /16/
      DATA  UNUS2 /17/
      DATA  MATRIX/18/
      DATA  POINT /19/
      DATA  VECTOR/20/
      DATA  REAL  /21/
      DATA  INTGER/22/
      DATA  BOOL  /23/
      DATA  SUBSCR/24/
      DATA  STRING/25/
      DATA  PATERN/26/
      DATA  BOUNDS/27/
      DATA  OBJECT/28/
      DATA  SSURF /29/
      DATA  SCURV /30/
      DATA  UNUS3 /31/
      DATA  UNUS4 /32/
C
C...        18.    STRING STORAGE AREA
C
      DATA CHR    /' '/
C
C...      19.      INTERMEDIATE LANGUAGE TEXT
C
      DATA COMFIN,LENGTH,TPNTRX/.FALSE.,0,0/
C
C         22.      MACRO PROCESSING VARIABLES
C
      DATA MACDFP ,MCNMB  ,MCHSTP ,MCTXTP ,MCSAVP ,MNMVBP ,MVSEG  ,
     1     CALLPT ,TEXTST ,MVPNT  ,BRANCH ,MAXSPS ,INTMED ,MAJWRD ,
     2     NMLINE ,WAY    ,BITWDS ,MCSLNT ,MACLNT ,MSP    ,MVEXST ,
     3     MACTOP ,MCSTRT ,MAJOR  ,ROUTE  ,ROAD   ,SAVMSP ,TYP    ,
     4     LNUSDP ,MCTOPP ,MCSPDP ,MCSRCH ,NUMARG ,WHCHMN ,LARGMV ,
     5     VBLSVP ,PATHLN ,NEXTLN ,PATHCH ,NUMVAR,NUMCAL  /41*0/
C
      DATA MACLDD ,CALLON ,CALLMV ,ILHLT  ,MVMAC  ,MACRED ,MVTRUE ,
     1     FINMAC ,ENTRY  ,NESTG  ,ENDMCH ,MACLK  ,MACEND ,SHOULD
     2     /14*.FALSE./
C
      DATA MBPTR  ,LSTWRT ,MCDFDM ,MHSTDM ,MCSVDM ,MNMVDM ,MSEQDM
     1    /    2  ,     1 ,   400 ,  1800 ,    10 ,    25 ,    50/
      DATA LNSDDM ,MVARDM ,MASDM  ,NUMBIT ,MACFND ,MSPDDM ,IVSVDM
     1    /    50 ,    32 ,  100  ,    31 ,    -1 ,  1300 ,   900/
C
C         23.      MACRO PROCESSING ARRAYS
C
      DATA  MACXX2/1,2,900*0/
C
C         24.      MACRO PROCESSING ARRAYS
C
      DATA  MACXX3/2630*0/
C
C         25.      MACRO PROCESSING ARRAYS
C
      DATA  MACXX4/100*0/
C
C         25A.     MACRO PROCESSING ARRAYS
C
C
C         26.      MACRO PROCESSING ARRAYS
C
      DATA  MACXX6/1300*0/
C
C         26A.     MACRO PROCESSING ARRAYS
      DATA  MACXX7/182*0/
C
C...        27.    OPERAND MODIFIERS
C
      DATA NOUGHT/0/
      DATA DLR   /1/
      DATA DBLDLR/2/
      DATA TRPDLR/3/
      DATA QUADLR/4/
      DATA QUIDLR/5/
      DATA HEXDLR/6/
      DATA SPTDLR/7/
C
C...        29.    CLASS CODE MODULI
C
      DATA MODULO /1000/
      DATA MODHLF / 500/
C
C...        30.   NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK
C
      DATA  FIRST /6*0/
C....
C           31.   COMMON BLOCK FOR PRO026 AND MOTION
C....
      DATA JMPING,FMTERR,MCSJMP,FEDSAV/4*.FALSE./
      DATA NUMBCS/0/
C
C           32.   COMMON BLOCK FOR SETBIT AND BITMCH
C
      DATA LOBIT( 1),LOBIT( 2),LOBIT( 3),LOBIT( 4),
     1     LOBIT( 5),LOBIT( 6),LOBIT( 7),LOBIT( 8),
     2     LOBIT( 9),LOBIT(10),LOBIT(11),LOBIT(12),
     3     LOBIT(13),LOBIT(14),LOBIT(15),LOBIT(16)
C    4    /Z80000000,Z40000000,Z20000000,Z10000000,
     4     /2147483648,1073741824,536870912,268435456,
C    5     Z 8000000,Z 4000000,Z 2000000,Z 1000000,
     5     134217728, 67108864, 33554432, 16777216,
C    6     Z  800000,Z  400000,Z  200000,Z  100000,
     6       8388608,  4194304,  2097152,  1048576,
C    7     Z   80000,Z   40000,Z   20000,Z   10000/
     7        524288,   262144,   131072,    65536/
      DATA HIBIT( 1),HIBIT( 2),HIBIT( 3),HIBIT( 4),
     1     HIBIT( 5),HIBIT( 6),HIBIT( 7),HIBIT( 8),
     2     HIBIT( 9),HIBIT(10),HIBIT(11),HIBIT(12),
     3     HIBIT(13),HIBIT(14),HIBIT(15),HIBIT(16)
C    4    /Z    8000,Z    4000,Z    2000,Z    1000,
     4    /    32768,    16384,     8192,     4096,
C    5     Z     800,Z     400,Z     200,Z     100,
     5          2048,     1024,      512,      256,
C    6     Z      80,Z      40,Z      20,Z      10,
     6           128,       64,       32,       16,
C    7     Z       8,Z       4,Z       2,Z       1/
     7             8,        4,        2,        1/
C...
C ...       35.    COMMON BLOCK FOR BOUNDED GEOMETRY AND CFSAVE
C
C
C
C           36.    SYSTEM MACRO AND SEGMENT READ VARIABLES
C
      DATA ALOPN,LMRSTR,LMREND/3*.FALSE./
      DATA NMSEG,NMMAC,ITMPCT/3*0/
C
C...        37.    INCLUSIVE SUBSCRIPT VARIABLES
C
      DATA ISSFL,ISSEND/2*.FALSE./
C
C...        39.    COMMON BLOCK LIBRARY PRINTING FLAG
C
      DATA LIBPRT/.FALSE./
C
C...        41.    NUMBER TABLE OVERFLOW VARIABLES
C
      DATA NCRNT,NLAST,NSTR,NMAX/1,0,1,100/
C
C           42.    COMMON BLOCK FOR CANON AND OBTAIN ARGUMENT STORAGE
C
      DATA CANPTR,CANCHK/0,16/
C
C           43.    COMMON BLOCK FOR LOOP
C
      DATA DOFLAG,DLRFLG,IFFLAG/3*.FALSE./
      DATA JUMPTO,ABSDO,RELDO,DONEST,DOMAX,DOJUMP/0,0,0,10,13,0/
C
C           44.    COMMON BLOCK FOR ERROR POSITIONS
C
      DATA NOWARN/.FALSE./
C
C           45.    NUMBER TABLE INDICIES
C
      DATA NMBRS,LSTCHR,MASGND/0,13,2000/
C
      END
