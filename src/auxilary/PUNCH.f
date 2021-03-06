**** SOURCE FILE : M0001210.W01   ***
*
C.....FORTRAN SUBROUTINE   ...PUNCH         8/68           SR,KH
C
C                                                10/70     RW
C
C PURPOSE          TO WRITE A SPECIFIED NUMBER OF CONTIGUOUS CANONICAL
C                  FORMS,STARTING WITH A GIVEN CANONICAL FORM,ON THE
C                  SYSTEM PUNCH OUTPUT FILE AS APT DEFINITION
C                  STSTEMENTS WHICH CAN BE INCLUDED IN SUBSEQUENT PART
C                  PROGRAMS. SCALARS ARE WRITTEN INTHE FORM---
C                      VSCALAR VARIABLE = NUMBER.
C                  SURFACE DATA IS WRITTEN IN THE FORM---
C                       SURFACE VARIABLE = SURFACE TYPE/CANON,ELEMENT1,
C                       ELEMENT2,...,ELEMENTN.
C
C CALLING SEQUENCE CALL PUNCH(BLOCK,FORM,NUMBER)
C
C ARGUMENTS        BLOCK            NUMBER OF THE CANONICAL FORM BLOCK
C                                   CONTAINING THE FORMS TO BE PUNCHED.
C                                   (BLOCK 1 CONTAINS UNSUBSCRIPTED
C                                    SCALARS,BLOCK 2 CONTAINS
C                                    SUBSCRIPTED SCALARS,BLOCK 3
C                                    CONTAINS SURFACE CANONICAL FORMS)
C                  FORM             FIRST CANONICAL FORM TO BE PUNCHED.
C                  NUMBER           NUMBER OF CONTIGUOUS FORMS TO BE
C                                   PUNCHED.
C
C CALLED BY        NONE
C
C SUBSIDIARIES     TYPE             ENTRY
C                  ----             -----
C
C                  INTEGER FUNCTION ADDRSS
C                  SUBROUTINE       APT094
C                  SUBROUTINE       INCAN
C                  SUBROUTINE       TRANSF
C                  SUBROUTINE       UNPACK
C                  INTEGER FUNCTION XCANON
C
C RESTRICTIONS     IF THERE IS MORE THAN ONE FORM TO BE PUNCHED,ALL
C                  FORMS MUST LIE IN THE SAME BLOCK AND BE CONTIGUOUS.
C                  THE PUNCHING OF TEMPORIES IS SUPPRESSED.
C
C DIAGNOSTICS      ERROR CODE       COMMENT
C                  ----------       -------
C
C                  NONE             X WAS INCORRECTLY DEFINED AND
C                                   WAS NOT PUNCHED.
C
C
C METHOD           A COMPUTED GO TO ON BLOCK IS EXECUTED TO BRANCH TO
C                  THE PROCESSING APPROPRIATE TO THE BLOCK CONTAINING
C                  THE CANONICAL FORMS TO BE PUNCHED.THE VALUE OF NUMBER
C                  SPECIFIES HOW MANY FORMS ARE TO BE PUNCHED.EACH FORM
C                  IS CHECKED TO DETERMINE IF IT IS UNDEFINED OR A
C                  TEMPORARY. IF IT IS UNDEFINED,A DIAGNOSTIC IS ISSUED.
C                  IF IT IS UNDEFINED OR A TEMPORARY,PUNCHING IS
C                  SUPPRESSED.IN THE CASE OF BLOCK 3 AN ADDITIONAL
C                  CHECK IS MADE TO SEE IF THE FORM IS A LARGE DATA
C                  ARRAY. IF SO,APT094 IS CALLED TO RETRIEVE THE
C                  EXTERNAL FORM.
C                       THE FORMS ARE OUTPUT TO THE SYSTEM PUNCH FILE AS
C                  APT PART PROGRAMMING DEFINITIONS IN THE FORMATS
C                  DESCRIBED UNDER PURPOSE.EACH CARD IMAGE IS SERIALIZED
C                  STARTING WITH SERIALIZATION 00000001 AND INCREASING
C                  BY 1 FOR SUBSEQUENT CARD IMAGES.
C
C ********************************************************************
C
      SUBROUTINE PUNCH(BLOCK,FORM,NUMBER)
      IMPLICIT  DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      INCLUDE 'BLANKCOM.INC'
      DOUBLE PRECISION X(COMSIZ)
      EQUIVALENCE (COM(1),X(1))
C
      DIMENSION FORM(1)
      INTEGER BLOCK
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'KNUMBR.INC'
C
C
      INCLUDE 'DARRAY.INC'
C
C
C...  LOCAL VARIABLES
C
      DIMENSION FMT(4),LDAMOD(5),TYPE(30)
      LOGICAL LDASRF,BNDPCH,NAMFLG
      INTEGER PNCHFL,SIZE,SUB,SERIAL,BCD,CNT,D
     1        ,PRNTFL,ADDRSS,XCANON
      EXTERNAL ADDRSS,XCANON
      CHARACTER*2 TWOCHR(4)
      INTEGER IBLNK(2),BCDF
      DIMENSION OUTLST(16),BUFFER(2),IU(8),REFSRF(12),INOUT(2)
      CHARACTER LTEST(8),BUCK,BLK,LPAREN,RPAREN,NO*4,CMA,BUF(16),NUMB,Z
      CHARACTER BLANK*8,DTEST*8,OUTLST*8,BUFFER*8,INOUT*4,TYPE*6
      EQUIVALENCE (LTEST(1),DTEST),(NO(4:4),NUMB)
      EQUIVALENCE (BUFFER,BUF(1)),(BLANK,BLK)
     1,(A,IA),(TWOCHR(1),DTEST),(CANLOC,II)
      DOUBLE PRECISION NAME,MEMBER,RSUB
      CHARACTER LNAME*8,LMEM*8
      LOGICAL CKSTR,CKDTR
      DOUBLE PRECISION ARRAY(10)
      INTEGER IARRAY(2,10)
      EQUIVALENCE (ARRAY(1),IARRAY(1,1))
      DATA LDASRF /.FALSE. /
      DATA  MODTOP,LDAMOD,CNT
     1   / 5,  11,12,26,29,30,  0/
      DATA LPAREN,RPAREN,INOUT/'(',')','  IN',' OUT'/
      DATA BUCK,CMA,BLANK/'$', ',' ,'        '/
      DATA Z/'Z'/
      DATA  TYPE /'LINE  ','PLANE ','CYLNDR','CIRCLE','SPHERE',
     1            'HYPERB','LCONIC','ELLIPS','CONE  ','GCONIC',
     2                     'TABCYL','RLDSRF','POLCON','QADRIC',
     3            'PARSRF','      ','      ','MATRIX','POINT ',
     4            'VECTOR','      ','      ','      ','      ',
     5 '      ','PATERN','BOUNDS','OBJECT','SSURF ','SCURV '/
C
C...  CNVRT IS AN ARITHMETIC FUNCTION THAT CONVERTS AN INTEGER TO A
C     LEFT-JUSTIFIED 2-DIGIT REPRESENTATION WITH LEADING ZEROS.
C
C.... SET UP EQUIVALENT OF 8 BLANK CHARACTERS IN D.P.WORD
      IBLNK(1)=BCDF('    ')
      IBLNK(2)=IBLNK(1)
C
C ... DETERMINE VIRTUAL INDEX OF FORM(1) IN X-ARRAY.
C
      I=(ADDRSS(FORM) - ADDRSS(X))/KWRDSZ + 1
      IABS = I
      IF (CANFLG) CALL INCAN(I)
      NAMFLG = .FALSE.
C
C ... BRANCH TO APPROPRIATE PROCESSING FOR SPECIFIED BLOCK.
C
C
      GO TO (10,1000,2000,1999,1999),BLOCK
C
C                  B L O C K   O N E
C
   10 N=1
   50 CONTINUE
      CNT = 100
C
C ... DETERMINE ABSOLUTE INDEX.
C
      GO TO 3150
C
C... SET K = INDEX OF NEXT SCALAR NAME
C
   15 K=IABS+1
C
C... CHECK IF FORM IS A TEMPORARY OR UNDEFINED
C
      GO TO 3000
C
C... WRITE SCALAR DEFINITION
C
   20 CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('=',DARRAY,21,1)
      CALL FCONV(X(IABS),DARRAY,22,14,6)
      CALL ICONV(CNT,DARRAY,85,3)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
   40 I = I + 2
      IABS = IABS + 2
      N=N+1
      IF (N.LE.NUMBER) GOTO 50
      RETURN
C
C                  B L O C K   T W O
C
 1000 SIZE = 1
      N = 1
 1040 CONTINUE
C
C ... DETERMINE ABSOLUTE INDEX.
C
      GO TO 3150
C
C... SET SUB = NEXT SUBSCRIPT. SET K = INDEX OF NEXT SCALAR NAME.
C
 1005 SUB = X(IABS + 1)
      CNT = 0
C
      GO TO 2007
C
C... WRITE SCALAR DEFINITION
C
 1010 CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('(    ) =',DARRAY,20,8)
      CALL ICONV(SUB,DARRAY,21,4)
      CALL FCONV(X(IABS),DARRAY,28,14,6)
      CALL ICONV(CNT,DARRAY,85,3)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
C
C... ADVANCE CURRENT CANONICAL FORM INDEX
C
 1030 D = 3 - MIN0(1,SUB-1)
      I = I + D
      IABS = IABS + D
      N=N+1
      IF (N.LE.NUMBER) GOTO 1040
      RETURN
C
C                  B L O C K   T H R E E
C
C     VORBEREITUNG FUER MEMBERAUSGABE
 1999 CALL DATE(DATUM)
C
C
 2000 BNDPCH=.FALSE.
      N=1
 2005 CNT=100
C
C ... DETERMINE ABSOLUTE INDEX.
      GO TO 3150
C
C... GET MODE,SIZE AND SUBSCRIPT OF NEXT CANONICAL FORM
C     AND CHECK VALIDITY.
C
 2006 CALL UNPACK(X(IABS),MODE,SIZE,SUB)
      IF(MODE.LE.0.OR.MODE.GT.30.OR.SIZE.LE.0.OR.SIZE.GT.
     1 50) GO TO 3200
C
C ... BYPASS IF THIS FORM HAS ALREADY BEEN PUNCHED.
C
      IF (X(IABS-1) .GT. 0) GO TO 2007
      IF (SUB .LE. 1) NAMFLG = .FALSE.
      GO TO 2110
C
C ... FIND ALPHANUMERIC NAME.
C
 2007 IF (SUB .LT. 0 .OR. SUB .GT. 9999) GO TO 3200
      IF (SUB .GT. 1) GO TO 3170
      NAMFLG = .FALSE.
      K = IABS + SIZE + 1 - BLOCK/3
 2008 IF (BLOCK .EQ. 2) GO TO 3000
      X(IABS-1) = -X(IABS-1)
C
C... SET II = INDEX OF FIRST ELEMENT IN CURRENT CANONICAL FORM
C
      II = 1
C
C...  SKIP PUNCHING IF PARAMETRIC SURFACE OR NO SURFACE
C
      IF((MODE.EQ.15).OR.(MODE.GT.20.AND.MODE.LT.26))GO TO 2110
C
C...  CHECK IF FORM IS TEMPORARY OR UNDEFINED
C
      GO TO 3000
C
C... IF THE CANONICAL FORM IS A LARGE DATA ARRAY,RETRIEVE THE EXTERNAL
C... FORMAND SET LDASRF = .TRUE.  RESET SIZE TO THE SIZE OF THE EXTERNAL
C... FORM. RESET II TO THE RELATIVE POSITION IN BLANK COMMON OF THE
C... FIRST ELEMENT OF THE EXTERNAL FORM
C
 2020 LDASRF=.FALSE.
      DO 2010  J = 1,MODTOP
      IF (MODE .NE. LDAMOD(J))  GO TO 2010
      CALL APT094(3,X(IABS),CANLOC)
      SIZE = X(IABS+1) + II -2
      LDASRF = .TRUE.
 2010 CONTINUE
      GO TO 2015
C
C ... WRITE FIRST DEFINITION CARD FOR SUBSCRIPTED SURFACE NAME.
C
 2012 CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('(    ) =',DARRAY,20,8)
      CALL ICONV(SUB,DARRAY,21,4)
      CALL CFORM(TYPE(MODE),DARRAY,29,6)
      CALL CFORM('/CANON,$',DARRAY,35,8)
      CALL ICONV(CNT,DARRAY,85,3)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
      GO TO 2045
C
C... SPECIAL PROCESSING IS REQUIRED FOR BOUNDS OR OBJECT CANON FORMS.
C
 2015 IF(BLOCK.GE.4)GO TO 5000
      IF(MODE.EQ.27 .OR. MODE.EQ.28)GO TO 4000
C
C... WRITE FIRST DEFINITION CARD
C
      IF(SUB .NE. 0) GO TO 2012
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('=',DARRAY,21,1)
      CALL CFORM(TYPE(MODE),DARRAY,23,6)
      CALL CFORM('/CANON,$',DARRAY,29,8)
      CALL ICONV(CNT,DARRAY,85,3)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
C
C ... IF LDASRF = FALSE, PUT C.F. INTO REFSRF AND CHK FOR REFSYS.
C
 2045 IF (.NOT. LDASRF) GO TO 3050
C
 2050 CNT=CNT+1
      L=14
      DO 2055 JJ=1,4
      IF(LDASRF) XX=X(II+1)
      IF(.NOT.LDASRF) XX=REFSRF(II)
      CALL FCONV(XX,DARRAY,L,14,6)
      L=L+14
      II=II+1
      IF(II.GT.SIZE) GO TO 2060
      CALL CFORM(',',DARRAY,L,1)
 2055 L=L+1
      CALL CFORM('$',DARRAY,L,1)
 2060 CALL ICONV(CNT,DARRAY,85,3)
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF (PCHLST) CALL CPRINT (DARRAY)
      IF(II.LE.SIZE) GO TO 2050
C
C... IF SURFACE IS A LARGE DATA ARRAY, RESET SIZE = 2
C
 2110 IF (.NOT. LDASRF) GO TO 2115
      SIZE = 2
      LDASRF = .FALSE.
C
C...  IF IN SUBSIDIARY BOUNDS PUNCH MODE, RETURN TO BOUNDS PROCESSING.
C
 2115 IF (BNDPCH) GO TO 4260
C
C... ADVANCE CURRENT CANONICAL FORM INDEX
C
 2120 D = SIZE + 2 - MIN0(SUB/2,1)
      I = I + D
      IABS = IABS + D
      N = N + 1
      IF (N .LE. NUMBER) GO TO 2005
      RETURN
C
C ... C H E C K   I F    T E M P   O R   U N D E F I N E D.
C
 2970 CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      L=21
      IF(SUB.EQ.0) GO TO 2971
      CALL CFORM('(    )',DARRAY,20,6)
      CALL ICONV(SUB,DARRAY,21,4)
      L=27
 2971 CALL CFORM('IS INCORRECTLY DEFINED AND WAS NOT PUNCHED.
     C    ',DARRAY,L,43)
      CALL CPRINT(DARRAY)
 2980 GO TO (40,1030,2110,2110,2110), BLOCK
C
C... IF THE FORM IS UNDEFINED OR A TEMPORARY,SUPPRESS PUNCHING IT
C
 3000 IF (CKDTR(X(IABS))) GO TO 2980
      CALL HOLFRM(X(K),DTEST,1,8,NWD)
      IF (LTEST(1) .EQ. BUCK .OR. (LTEST(2) .EQ. BUCK .AND. LTEST(1)
     1 .EQ. Z)) GO TO 2980
C
C ... IF FORM INCORRECTLY DEFINED, WRITE A DIAGNOSTIC.
C
      IF (CKSTR(X(IABS))) GO TO 2970
C
C
C... ADVANCE CARD SERIALIZATION
C
      CNT = CNT + 1
      GO TO (20,1010,2020,2020,2020), BLOCK
C
C ... REFSYS TEST.
C
 3050 DO 3060 J=1,SIZE
      KK=IABS+J-1
 3060 REFSRF(J) = X(KK)
      IF (.NOT.REFFLG.OR.MODE.LE.0.OR.MODE.GT.20) GO TO 2050
      GO TO (3070,3070,3080,3080,3090,3100,3100,3100,3080,3100,2050,
     1 2050,2050,3100,2050,2050,2050,2050,3090,3110), MODE
 3070 IR=4
      GO TO 3120
 3080 IR=5
      GO TO 3120
 3090 IR=2
      GO TO 3120
 3100 IR=1
      GO TO 3120
 3110 IR=3
 3120 CALL  TRANSF(REFSRF,X(IABS),IR,SIZE,0)
      GO TO 2050
C
C ... DETERMINE ABSOLUTE INDEX.
C
 3150 A = X(IABS - BLOCK/3)
      IF (IA .LE. 0 .OR. IA .GT. 1024) GO TO 3160
      I = I + IA
      IABS = I
      IF (CANFLG) IABS = XCANON(I)
      GO TO 3150
 3160 GO TO (15,1005,2006,2006,2006), BLOCK
C
C ... DETERMINE ABSOLUTE LOCATION OF FORM NAME.
C
 3170 IF (.NOT. NAMFLG) GO TO 3175
      IF (CANFLG) K = XCANON(IK)
      GO TO 3195
C
 3175 NAMFLG = .TRUE.
      INCR = SIZE + 1 - BLOCK/3
      K = IABS + INCR
      IK = I + INCR
      DO 3190 MM = 2,SUB
 3178 A = X(K)
      IF (IA .LE. 0 .OR. IA .GT. 1024) GO TO 3180
      IK = IK + IA
      K = IK
      IF (CANFLG) K = XCANON(IK)
      GO TO 3178
 3180 K = K + SIZE + 1
      IK = IK + SIZE + 1
 3190 CONTINUE
 3195 IF (CANFLG) IABS = XCANON(I)
      GO TO 2008
C
C ... IF CANONICAL FORM IS INVALID, PRINT DIAGNOSTIC AND RETURN.
C
 3200 CALL CFORM('INVALID CANONICAL FORM PUNCHING SUPPRESSED
     C      ',  DARRAY,14,42)
      CALL CPRINT (DARRAY)
      RETURN
C
C...  PROCESSING FOR BOUNDS AND OBJECTS
C
 4000 IF (BNDPCH) GO TO 4260
      JK = SIZE + 16
      IF (MODE .EQ. 27) GO TO 4050
C
C... P U N C H   O B J E C T   C A R D
C
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('=OBJECT/',DARRAY,20,8)
      M=101
      J=-2
 4004 L=28
 4005 J=J+2
      CALL HOLFRM(X(IABS+J),DTEST,1,8,NWD)
      IF(LTEST(1).EQ.BUCK.OR.CKSTR(X(IABS+J))) GO TO 2970
      CALL CFORM(DTEST,DARRAY,L,6)
      CALL CFORM(',' ,DARRAY,L+6,1)
      IF(J.EQ.SIZE-2) GO TO 4010
      L=L+7
      IF (L.LT.73) GO TO 4005
      CALL CFORM ('$',DARRAY,L,1)
 4006 CALL ICONV(M,DARRAY,85,3)
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,80,6)
      M=M+1
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
      IF(J.EQ.SIZE-2) GO TO 4011
      GO TO 4004
 4010 CALL CFORM(' ',DARRAY,L+6,1)
      GO TO 4006
 4011 GO TO 2120
C
C ... P U N C H   B O U N D S   C A R D S
C
 4050 DO 4051 JJ=1,66
 4051 OUTLST(JJ) = BLANK
      DO 4130 JJ=2,SIZE,2
C
C ... CHECK FOR INVALID OR UNASSIGNED NESTED ARGUMENTS.
C
      CALL HOLFRM(X(IABS+JJ-2),BUFFER(1),1,8,NWD)
      IF (BUF(1) .EQ. BUCK .OR. CKSTR(X(IABS+JJ-2))) GO TO 2970
C
C... DETERMINE INDEX,SUBSCRIPT, AND HALF-SPACE MODIFIER FOR EA. OPERAND.
C
      J=JJ/2
      BUFFER(2)=BLANK
      IUVW=X(IABS+JJ-1)
      IU(J)=IUVW/K1E4
      ISUB=(IUVW-IU(J)*K1E4)/K10
      IHSMOD=IUVW-IU(J)*K1E4-ISUB*K10
C
C...  IF REFERENCED SURFACE IS SUBSCRIPTED, CONVERT SUBSCRIPT TO ALPHA-
C     NUMERIC FORM AND LEFT-JUSTIFY IT NEXT TO THE NAME.
C
      DO 4060 M=3,8
      IF (BUF(M-1) .EQ. BLK) GO TO 4070
 4060 CONTINUE
 4070 IF (ISUB .EQ. 0) GO TO 4110
      BUF(M-1)=LPAREN
      DO 4080 KK=1,3
      L=4-KK
      BCD=MOD(ISUB,10)
      CALL HOLFRM(BCD,NO,1,4,NWD)
      LTEST(L)=NUMB
      ISUB = ISUB/K10
      IF (ISUB .EQ. 0) GO TO 4090
 4080 CONTINUE
 4090 DO 4100 KK=L,4
      BUF(M)=LTEST(KK)
 4100 M=M+1
      BUF(M-1)=RPAREN
 4110 BUF(M)=CMA
C
C...  SUPPRESS HSMOD AND COMMA IF PRIMARY SURFACE.
C
      IF (J .EQ. 1) GO TO 4125
      IF (IHSMOD .EQ. 1 .OR. IHSMOD .EQ. 2) GO TO 4112
      BCD=IHSMOD
      CALL HOLFRM(BCD,NO,1,4,NWD)
      GO TO 4116
 4112 NO=INOUT(IHSMOD)
      BUF(M+1) = NO(2:2)
      BUF(M+2) = NO(3:3)
 4116 BUF(M+3)=NUMB
C
C...  SUPPRESS FINAL COMMA IF LAST BOUNDING SURFACE.
C
      IF (JJ .EQ. SIZE) GO TO 4125
      BUF(M+4)=CMA
C
C...  WILL NEED SECOND CARD IF MORE THAN TWO BOUNDING SURFACES, AND
C     THIRD CARD IF MORE THAN SIX SURFACES, ETC.
      JK =JJ - 6
      IF ((JK - (JK/8)*8) .EQ. 0) BUF(M + 4) = BUCK
C
 4125 OUTLST(JJ-1)=BUFFER(1)
 4130 OUTLST(JJ)=BUFFER(2)
C
C...  PUNCH FIRST CARD.
C
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,14,6)
      CALL CFORM('=BOUNDS/',DARRAY,20,8)
      CALL CFORM(OUTLST(1),DARRAY,28,48)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CFORM('01',DARRAY, 86,2)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
      IF (SIZE .LE. 6) GO TO 4250
C
C...  PUNCH INTERMEDIATE CARDS.
C
      INTCDS = SIZE/8
      CNT=101
      JK = -1
      DO 4170 JJ = 1,INTCDS
      JK = JK + 8
      CNT = CNT + 1
      CALL CFORM(',',DARRAY,14,1)
      CALL CFORM(OUTLST(JK),DARRAY,15,64)
      CALL ICONV(CNT,DARRAY,85,3)
      CALL HOLFRM(X(K),LNAME,1,8,NWD)
      CALL CFORM(LNAME,DARRAY,80,6)
      CALL CPUNCH(DARRAY(9:88),PCHLST)
      IF(PCHLST) CALL CPRINT(DARRAY)
 4170 CONTINUE
C
C...  P U N C H   C A R D S   F O R   B O U N D I N G   S U R F A C E S
C
C ... BYPASS IF PUNCH/ALL OR PUNCH/GEOM IS SPECIFIED.
C
 4250 IF (NUMBER .GT. 1) GO TO 2120
C
C...  SET FLAG FOR SUBSIDIARY BOUNDS PUNCHING MODE AND PUNCH CARD(S).
C
      BNDPCH=.TRUE.
C
      JJJ=SIZE/2
      DO 4260 JK=1,JJJ
      I=IU(JK)+IBLK1
      IABS = I
      IF (CANFLG) IABS = XCANON(I - 1) + 1
      NAMFLG = .FALSE.
      GO TO 2005
 4260 CONTINUE
      RETURN
C    MEMBER-AUSGABE AUF PDS
 5000 ARRAY(1)=X(K)
      MEMBER=X(K)
      CALL HOLFRM(MEMBER,LMEM,1,8,NWD)
      RSUB=0.D0
      IF(SUB.EQ.0)GOTO 5004
      RSUB=SUB
      NAME=X(K)
      CALL HOLFRM(NAME,LNAME,1,8,NWD)
      CALL ICONV(SUB+10000000,LMEM,1,8)
      DO 5001 I1=1,8
      IF(LNAME(I1:I1).EQ.BLK)GOTO 5004
 5001 LMEM(I1:I1)=LNAME(I1:I1)
C INDEX
 5004 ARRAY(2)=RSUB
C OBERFLAECHENART
      IARRAY(1,3)=MODE
C KENNUNG FUER GROSSFLAECHEN
      IARRAY(2,3)=5
C ANZAHL DER CANON-ELEMENTE
      IARRAY(1,4)=0
      ILA=X(IABS+1)
      IARRAY(2,4)=ILA
      ARRAY(5)=0.D0
C *** VAX VERSION - OPEN FILE ON APTLIB BEFORE WRITE   ***
C *** PUNCH/RANDOM (BLOCK=5) GEOMETRY ALWAYS STORED    ***
C *** PUNCH/RETAIN (BLOCK=4) ONLY NEW GEOMETRY STORED  ***
      CALL WTDIRE(19,MEMBER,DATUM,8,IRET)
      IF(IRET.EQ.9.AND.BLOCK.EQ.4)
     /CALL WTDIRE(-19,MEMBER,DATUM,8,IRET)
      IF(IRET.NE.0)GOTO 5020
      JJ=6
      DO 5010 JJJ=II,SIZE
      ARRAY(JJ)=X(JJJ+1)
      IF(JJJ.EQ. SIZE)GOTO 5005
      JJ=JJ+1
      IF(JJ.LE.9)GOTO 5010
 5005 CNT=CNT+1
      ARRAY(10)=CNT
      CALL WTSATZ(19,ARRAY,10,IRET)
      DO 5006 I=1,10
        ARRAY(I)=0.0D0
 5006 CONTINUE
      JJ=1
      IF(IRET.NE.0)GOTO 5020
 5010 CONTINUE
C    ABSCHLUSS
C  *** VAX VERSION - WTDIRE OPENS FILE IN APTLIB    ***
C  ***               NEEDS TO BE DONE BEFORE WRITE  ***
C      CALL WTDIRE(19,MEMBER,DATUM,8,IRET)
C      IF(IRET.EQ.9.AND.BLOCK.EQ.4)
C     /CALL WTDIRE(-19,MEMBER,DATUM,8,IRET)
      IF(IRET.EQ.0)GOTO 5040
 5020 ILEN=0
      IF (IRET.EQ.3) THEN
          CALL CFORM('0 ERROR WRITING TO FILE :',DARRAY,1,ILEN)
      ELSE IF (IRET.EQ.5) THEN
        CALL CFORM('0 ERROR OPENING FILE :',DARRAY,1,ILEN)
      ELSE
        CALL CFORM('0 I/O ERROR FILE :',DARRAY,1,ILEN)
      ENDIF
      IPOS=ILEN+2
      CALL CFORM(LMEM,DARRAY,IPOS,8)
      CALL CPRINT(DARRAY)
 5040 CALL CLOSPE(19,IRET)
      RETURN
      END
