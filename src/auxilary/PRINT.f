**** SOURCE FILE : M0001206.W02   ***
*
C
C
C.....FORTRAN SUBROUTINE           PRINT
C
C     NEW REORGANIZED VERSION  OCT-1988 E.MCLELLAN
C
C PURPOSE          TO EJECT A PAGE,TAKE A DUMP,TURN THE PRINT FLAG
C                  INTERROGATED BY DEFEXT ON OR OFF,OR PRINT TITLES,
C                  NUMBER IDENTIFIERS OR A SPECIFIED NUMBER OF CANONICAL
C                  FORMS.
C
C CALLING SEQUENCE CALL PRINT(CODE,ARRAY,NUMBER)
C
C ARGUMENTS        CODE             =1,TO PRINT BLOCK 1 SCALARS WITH A
C                                      DESCRIPTIVE HEADER
C                                   =2,TO PRINT BLOCK 2 SCALARS WITH A
C                                      DESCRIPTIVE HEADER
C                                   =3,TO PRINT BLOCK 3 CANONICAL FORMS
C                                      WITH A DESCRIPTIVE HEADER
C                                   =4,TO PRINT BLOCK 1 SCALARS WITH NO
C                                      HEADER
C                                   =5,TO PRINT BLOCK 2 SCALARS WITH NO
C                                      HEADER
C                                   =6,TO PRINT BLOCK 3 CANONICAL FORMS
C                                      WITH NO HEADER
C                                   =7,TO EJECT A PAGE
C                                   =8,TO TAKE A DUMP
C                                   =9,TO PRINT A TITLE
C                                   =10, TO PRINT A NUMBER IDENTIFIER
C                                       (I.E. HANDLES PRINT/2,NUMBER)
C                                   =11,TO TURN PRINT FLAG ON
C                                   =12,TO TURN PRINT FLAG OFF
C                                   =13, TO TURN PCHLST FLAG ON
C                                   =14, TO TURN PCHLST FLAG OFF
C                                   =15, TO PRINT NAME ON TABCYL LISTING
C                                   =16, FOR TABCYL PRINT ON
C                                   =17, FOR TABCYL PRINT OFF
C                                   =18/19 FOR SS-PRINT ON/OFF
C                                   =20/21 FOR SS-TEST-PRINT ON/OFF
C                                   =22/23 FOR AVOIDANCE ACTION PRINT
C                                          (AVPRT) ON/OFF
C                  ARRAY            IF PRINTING IS TO TAKE PLACE,ARRAY
C                                   CONTAINS THE TITLE,NUMBER,OR FIRST
C                                   CANONICAL FORM TO BE PRINTED.
C                                   OTHERWISE ARRAY IS A DUMMY ARGUMENT.
C                  NUMBER           IF CANONICAL FORMS ARE TO BE PRINTED
C                                   NUMBER CONTAINS THE NUMBER OF FORMS
C                                   TO PRINT.
C
C CALLED BY        DEFEXT,APT040,APT045,APT102,APT103,APT089
C
C SUBSIDIARIES     TYPE             ENTRY
C                  ----             -----
C                  INTEGER FUNCTION ADDRSS
C                  SUBROUTINE       INCAN
C                  SUBROUTINE       RECORD
C                  SUBROUTINE       TRANSF
C                  SUBROUTINE       UNPACK
C                  INTEGER FUNCTION XCANON
C                  INTEGER FUNCTION BCDF
C                  SUBROUTINE       HOLFRM
C
C RESTRICTIONS     CANONICAL FORMS TO BE PRINTED MUST BE CONTIGUOUS
C
C DIAGNOSTICS      ERROR CODE       COMMENT
C                  ----------       -------
C                   NONE            INVALID CANONICAL FORM ENCOUNTERED.
C                                   PRINTING SUPPRESSED
C
C METHOD           AN 'IF THEN ELSE' STRUCTURE IS USED TO DIRECT
C                  PROCESSING ACCORDING TO CODE.
C                  NOTE THAT BECAUSE THERE IS MUCH COMMON PROCESSING
C                  FOR CODE=1,2,3,4,5,6 AND 15, THESE ARE PROCESSED
C                  IN THE FIRST BLOCK OF THE STRUCTURE WITH ADDITIONAL
C                  'IF THEN ELSE' STRUCTURES TO DIRECT SUBSEQUENT
C                  PROCESSING ACCORDING TO THE INDIVIDUAL CODES
C
      SUBROUTINE  PRINT(CODE,ARRAY,NUMBER)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DIMENSION  ARRAY(1)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
C
C
C
C
C...  LOCAL VARIABLES
      INCLUDE 'BLANKCOM.INC'
      DIMENSION X(COMSIZ)
      EQUIVALENCE (COM(1),X(1))
C
      DOUBLE PRECISION NAME
      CHARACTER F13*18,F30*19,F40*55
      INCLUDE  'DARRAY.INC'
      COMMON/SSPRT/SSPRT,SSTEST
      LOGICAL SSPRT,SSTEST
      INCLUDE 'AVCPRM.INC'
C
      INTEGER DLR,LP,RP,ZERO,SUB,BCD,CODE,COUNT,SIZE,PLUS,BBBB,STR
C
      LOGICAL LDAFLG,BNDFLG,BNDSUB,NAMFLG
      CHARACTER BLK,LPAREN,DOLLAR,NUMB,RPAREN,B,Z,STAR,NAM(16),CNAM*16,
     + STG(8),STAGE*8,CHECK*8,RIGHT*5,MODHS*4,
     + TYPE*6,NO(4),CNUM*4
C
      DIMENSION TYPE(30),NAME(2),A(17),IA(34),REFSRF(16),IRFSRF(32),
     1            MODHS(2),INAM(4),ITEMP(2)
C
      EQUIVALENCE  (C,ISKIP),(A(1),IA(1)),(REFSRF(1),IRFSRF(1)),
     +             (NAME(1),INAM(1)),(ITEMP(1),TEMP),
     +             (STG(1),STAGE),(NO(4),NUMB),
     +             (NAM(1),CNAM),(NO(1),CNUM)
      EXTERNAL XCANON,ADDRSS,CKDTR,CKSTR
      INTEGER XCANON,ADDRSS,BCDF
      LOGICAL CKDTR,CKSTR
      SAVE KRIGHT
C
      DATA MODHS/'  IN',' OUT'/
      DATA B,Z,STAR/' ','Z','*'/
      DATA  BLK,LPAREN,ZERO,STAGE,DOLLAR,RIGHT,RPAREN
     1 /' ','(',0,'0000000)','$','RIGHT',')'/
      DATA  TYPE /'LINE  ','PLANE ','CYLNDR','CIRCLE','SPHERE','HYPERB',
     1                     'LCONIC','ELLIPS','CONE  ','GCONIC','TABCYL',
     2            'RLDSRF','PCONIC','QADRIC','PARSRF','**16**','**17**',
     3            'MATRIX','POINT ','VECTOR','SCALAR','**22**','**23**',
     4'**24**','STRING','PATERN','BOUNDS','OBJECT','SSURF ','SCURV '/
C
      DATA F13/'TABULATED CYLINDER'/
      DATA F30/'INCORRECTLY DEFINED'/
      DATA F40
     +    /'INVALID CANONICAL FORM ENCOUNTERED. PRINTING SUPPRESSED'/
      DATA KRIGHT /0/
      DATA     KU,KV/10000,10/
C
C ********************************************************************
C
C
C...      P R O C E S S   A C C O R D I N G   T O   C O D E
C
      IF ( (CODE.LE.6).OR.(CODE.EQ.15) ) THEN
        NAMFLG = .FALSE.
        IPH=1
        MODE = 21
        JJ = 0
        SIZE=1
        BNDFLG=.FALSE.
        LDAFLG = .FALSE.
C
C ... DETERMINE VIRTUAL INDEX OF ARRAY(1) IN X-ARRAY.
C
        INDEX = (ADDRSS(ARRAY) - ADDRSS(X))/KWRDSZ + 1
        IABS = INDEX
        IF (CANFLG) CALL INCAN(INDEX)
C
C... PROCESS ACCORDING TO TYPE
C
        IC=MOD(CODE,3)
        IF (IC.EQ.0) THEN
C.... CODE = 3,6 OR 15
          JJ=1
        ELSE IF (IC.EQ.1) THEN
C.... CODE = 1 OR 4
          SUB=0
        ELSE
C.... CODE = 2 OR 5
          CONTINUE
        ENDIF
C
C.... FOR EACH CANONICAL FORM REQUIRED
C
        DO 5000 II = 1,NUMBER
C
C ... DETERMINE ABSOLUTE INDEX.
C
60000     C = X(IABS - JJ)
          IF (ISKIP .GT. 0 .AND. ISKIP .LE. 1024) THEN
            INDEX = INDEX + ISKIP
            IABS = INDEX
            IF (CANFLG) IABS = XCANON(INDEX)
            GO TO 60000
          ENDIF
C
          IF (IC.EQ.1) THEN
C
C...  P R I N T   B L O C K   1   S C A L A R S
C
            NAMEPT = IABS + 1
            GO TO 50000
C
          ELSE IF (IC.EQ.2) THEN
C
C...  P R I N T   B L O C K   2   S C A L A R S
C
            SUB = X(IABS + 1)
C
          ELSE
C
C...  P R I N T   B L O C K   3   S U R F A C E S
C
C
C... GET SIZE,MODE,AND SUBSCRIPT OF NEXT FORM
C
            CALL UNPACK(X(IABS),MODE,SIZE,SUB)
            IF (MODE .EQ. 27 .OR. MODE .EQ. 28) BNDFLG=.TRUE.
            IF (MODE.GT.0.AND.MODE.LT.31.AND.SIZE.GT.0.AND.
     /         (SIZE.LT.13 .OR. BNDFLG)) THEN
C
C... IF FORM IS A LARGE DATA ARRAY, TURN ON LDAFLG
C
              IF (MODE.EQ.11.OR.MODE.EQ.12.OR.MODE.EQ.26.OR.
     1            MODE.EQ.29.OR.MODE.EQ.30) THEN
                LDAFLG = .TRUE.
              ENDIF
            ELSE
              CALL CFORM(F40,DARRAY,5,55)
              CALL CPRINT (DARRAY)
              GOTO 99999
            ENDIF
          ENDIF
C
C ... FIND ALPHANUMERIC NAME.
C
          IF (SUB .LT. 0 .OR. SUB .GT. 9999) THEN
            CALL CFORM(F40,DARRAY,5,55)
            CALL CPRINT (DARRAY)
            GOTO 99999
          ELSE IF (SUB .GT. 1) THEN
C
C ... DETERMINE ABSOLUTE LOCATION OF FORM NAME.
C
            IF (.NOT.NAMFLG) THEN
              NAMFLG = .TRUE.
              NAMEPT = IABS + SIZE + 1 - JJ
              IK = INDEX + SIZE + 1 - JJ
              DO 60110 MM = 2,SUB
60102           C = X(NAMEPT)
                IF (ISKIP .LE. 0 .OR. ISKIP .GT. 1024) THEN
                  NAMEPT = NAMEPT + SIZE + 1
                  IK = IK + SIZE + 1
                ELSE
                  IK = IK + ISKIP
                  NAMEPT = IK
                  IF (CANFLG) NAMEPT = XCANON(IK)
                  GO TO 60102
                ENDIF
60110         CONTINUE
C
              IF (CANFLG) IABS = XCANON(INDEX)
              SAVNAM = X(NAMEPT)
            ENDIF
C
            NAME(1) = SAVNAM
            GO TO 50002
          ELSE
            NAMFLG = .FALSE.
            NAMEPT = IABS + SIZE + 1 - JJ
          ENDIF
C
C...  U T I L I T Y   P R I N T   M O D U L E
C
C
C... SET NAME(1) = CURRENT CANONICAL FORM NAME
C     AND, IF LDA, SET SIZE = SIZE OF EXTERNAL CANONICAL FORM.
C
50000     NAME(1) = X(NAMEPT)
50002     IF (LDAFLG) SIZE = X(IABS + 1)
          INAM(3) = BCDF('    ')
          INAM(4) = INAM(3)
C
C...  IF FORM NAME BEGINS WITH $ OR Z$, SUPPRESS PRINTING IT
C
          CALL HOLFRM(INAM,CNAM,1,16,NWD)
          IF((NAM(1).EQ.DOLLAR).OR.((NAM(1).EQ.Z).AND.
     1      (NAM(2) .EQ. DOLLAR))) THEN
C
C ... PRINT UNASSIGNED NESTED ELEMENTS FOR PRINT/ON.
C
            IF (NUMBER .GT. 1 .OR. MODE .EQ. 21) GO TO 50100
            CALL DNONAM(NAME(1))
          ELSE
C
C... IF THE FORM IS SUBSCRIPTED, CONVERT THE SUBSCRIPT TO CHARACTERS
C... AND LEFT JUSTIFY IT NEXT TO THE FORM NAME READY FOR PRINTING
C
            IF (SUB .NE. 0) THEN
              IF (CODE .EQ. 6 .OR. CODE .EQ. 5) GO TO 50060
              DO 50010 J=4,9
                IF (NAM(J-2) .EQ. BLK)  GO TO 50020
50010         CONTINUE
50020         NAM(J-1) = LPAREN
              N = SUB
              DO 50030  I = 1,7
                K=8-I
                BCD = MOD(N,10)
                CALL ICONV(BCD,NUMB,1,1)
                STG(K) = NUMB
                N = N/10
                IF (N .EQ. 0)  GO TO 50040
50030         CONTINUE
50040         DO 50050 I=K,8
                NAM(J) = STG(I)
                J = J + 1
50050         CONTINUE
              NAM(J-1)=RPAREN
            ENDIF
          ENDIF
C
C... WRITE HEADER CONTAINING FORM NAME,MODE AND SIZE
C     BUT SUPPRESS IF FORM IS UNDEFINED.
C
50060     IF (CKDTR(X(IABS))) GO TO 50100
          IF(IPH.EQ.1) THEN
            ISEQ = ISEQNO
            CALL RECORD(ISEQNO)
            IF (ISEQ .EQ. ISEQNO) THEN
              IPH = 2
            ELSE
              CALL CFORM('-',DARRAY,1,1)
              IPH=2
              CALL ICONV (ISEQNO,DARRAY,2,4)
              CALL CFORM('.',DARRAY,6,1)
            ENDIF
          ENDIF
C
C... IF PROCESSING A PRINT/2 STATEMENT, SUPPRESS PRINTING THE HEADER.
C
50062     IF (CODE .LE. 3) THEN
            CALL CFORM(CNAM,DARRAY,7,12)
            CALL CFORM(TYPE(MODE),DARRAY,19,6)
            CALL ICONV(SIZE,DARRAY,25,5)
            IF(LDAFLG) CALL CPRINT(DARRAY)
          ENDIF
C
C ... PRINT DIAGNOSTIC IF INCORRECTLY DEFINED.
C
          IF (CKSTR(X(IABS))) THEN
            CALL CFORM(F30,DARRAY,30,19)
            CALL CPRINT (DARRAY)
            GOTO 50100
          ENDIF
          IF (LDAFLG .OR. MODE.EQ.15) GOTO 50100
C
          IF (IC.EQ.1) THEN
C
C BLOCK 1 SCALARS
C
            K=30
            CALL FCONV ( X(IABS) , DARRAY,K,13,6)
            CALL CPRINT (DARRAY)
C
          ELSE IF (IC.EQ.2) THEN
C
C BLOCK 2 SCALARS
C
            K=30
            CALL FCONV (X(IABS),DARRAY,K,13,6)
            CALL CPRINT (DARRAY)
C
          ELSE
C
C BLOCK 3 SURFACES
C
C... CHECK IF REFSYS IN EFFECT. IF SO,PRINT FORM IN LOCAL SYSTEM
C
            IF(.NOT.BNDFLG) THEN
              IF (MODE .EQ. 25) THEN
C
C...  PRINT A STRING FORM
C
                A(1) = X(IABS)
                COUNT=(IA(2)+3)/4
                J=COUNT/2+MOD(COUNT,2)
                DO 3020  I = 1,J
                  A(I) = X(IABS + I)
 3020           CONTINUE
                CALL HOLFRM(IA(1),DARRAY,30,COUNT*4,NWD)
                CALL CPRINT (DARRAY)
                GOTO 50100
              ENDIF
C
              DO 3030 J=1,SIZE
                K = IABS + J - 1
                REFSRF(J) = X(K)
 3030         CONTINUE
              IF (REFFLG) THEN
                IF (MODE.EQ.1. OR. MODE.EQ.2) THEN
                  IR = 4
                ELSE IF (MODE.EQ.3 .OR. MODE.EQ.4 .OR. MODE.EQ.9) THEN
                  IR = 5
                ELSE IF (MODE.EQ.5 .OR. MODE.EQ.19) THEN
                  IR = 2
                ELSE IF (MODE.EQ.6 .OR. MODE.EQ.7 .OR. MODE.EQ.8 .OR.
     +                   MODE.EQ.10 .OR. MODE.EQ.14 ) THEN
                  IR = 1
                ELSE IF (MODE.EQ.20) THEN
                  IR = 3
                ELSE
                  GOTO 3038
                ENDIF
                CALL TRANSF(REFSRF,X(IABS),IR,SIZE,0)
              ENDIF
C
C... WRITE FORM ELEMENTS
C
 3038         K=29
              DO 13039 J=1,SIZE
                IF(K+13.LE.120) GO TO 13038
                CALL CPRINT(DARRAY)
                K=17
13038           CALL FCONV (REFSRF(J),DARRAY,K,13,6)
                K=K+13
13039         CONTINUE
              CALL CPRINT(DARRAY)
C
            ELSE
C
C... P R I N T   B O U N D S   A N D   O B J E C T
C
              ISUB = SUB
              DO 50250 L =2,SIZE,2
                K = IABS + L
                NAME(1) = X(K-2)
                CALL HOLFRM(INAM,CNAM,1,8,NWD)
                IF (NAM(1) .EQ. STAR) CALL BADNAM(NAME(1))
                IF (NAM(1) .EQ. DOLLAR) CALL DNONAM(NAME(1))
                ITEMP(1)=BCDF('    ')
                ITEMP(2)=ITEMP(1)
                REFSRF(L) = TEMP
                IF(MODE.EQ.28) GO TO 50235
C
C... BOUNDS
C
50220           INAM(3)=BCDF('    ')
                INAM(4)=INAM(3)
                IUVW = X(K-1)
                IU=IUVW/KU
                SUB=(IUVW-IU*KU)/KV
                IW=IUVW-IU*KU-SUB*KV
                IF(SUB .NE. 0) THEN
C
C... IF THE FORM IS SUBSCRIPTED, CONVERT THE SUBSCRIPT TO CHARACTERS
C... AND LEFT JUSTIFY IT NEXT TO THE FORM NAME READY FOR PRINTING
C
                  DO 50221 J=4,9
                    IF (NAM(J-2) .EQ. BLK)  GO TO 50222
50221             CONTINUE
50222             NAM(J-1) = LPAREN
                  N = SUB
                  DO 50223  I = 1,7
                    K=8-I
                    BCD = MOD(N,10)
                    CALL ICONV(BCD,NUMB,1,1)
                    STG(K) = NUMB
                    N = N/10
                    IF (N .EQ. 0)  GO TO 50224
50223             CONTINUE
50224             DO 50225 I=K,8
                    NAM(J) = STG(I)
                    J = J + 1
50225             CONTINUE
                  NAM(J-1)=RPAREN
                ELSE
                  J=9
                ENDIF
50230           IF (L .EQ. 2) GO TO 50232
                BCD=IW
                IF (IW .EQ. 1 .OR. IW .EQ. 2) THEN
                  CNUM=MODHS(IW)
                ELSE
                  CALL ICONV(BCD,CNUM,1,4)
                ENDIF
                NAM(J+1)=NO(2)
                NAM(J+2)=NO(3)
                NAM(J+3)=NO(4)
                INAM(3)=BCDF(CNAM(9:12))
50232           REFSRF(L )=NAME(2)
C
50235           REFSRF(L -1)=NAME(1)
50250         CONTINUE
              CALL CPRINT(DARRAY)
              K=12
              IF(MODE.EQ.28) K=16
              DO 20251 J=1,SIZE*2,4
                CALL HOLFRM(IRFSRF(J),DARRAY,K,16,NWD)
                K=K+14
                IF(MODE.EQ.27) K=K+4
                IF(K.LE.108) GO TO 20251
                CALL CPRINT (DARRAY)
                K=12
                IF(MODE.EQ.28) K=16
20251         CONTINUE
              CALL CPRINT (DARRAY)
              IPH = 2
              BNDFLG=.FALSE.
              SUB = ISUB
            ENDIF
          ENDIF
C
50100     IF(CODE.EQ.15) THEN
C
C ... P R I N T   N A M E   O N   T A B C Y L   L I S T I N G
C
            CALL RECORD(ISEQNO)
            CALL CFORM('-',DARRAY,1,1)
            CALL ICONV(ISEQNO,DARRAY,2,4)
            CALL CFORM('.',DARRAY,6,1)
            CALL CFORM(F13,DARRAY,8,18)
            CALL CFORM(CNAM,DARRAY,28,12)
            CALL CPRINT (DARRAY)
            GOTO 99999
          ELSE
C
C.... ADVANCE CURRENT FORM INDEX
C
            IF (IC.EQ.1) THEN
              INDEX = INDEX + 2
              IABS = IABS + 2
            ELSE IF (IC.EQ.2) THEN
              D = 3 - MIN0(1,SUB-1)
              INDEX = INDEX + D
              IABS = IABS + D
            ELSE
              IF (LDAFLG) THEN
                SIZE=2
                LDAFLG=.FALSE.
              ENDIF
              D = SIZE + 2 - MIN0(SUB/2,1)
              INDEX = INDEX + D
              IABS = IABS + D
            ENDIF
          ENDIF
 5000   CONTINUE
C
      ELSE IF (CODE.EQ.7) THEN
C
C...  E J E C T   A   P A G E
C
        CALL CFORM('1',DARRAY,1,1)
        CALL CPRINT (DARRAY)
C
      ELSE IF (CODE.EQ.8) THEN
C
C...  T A K E   A   C O R E   D U M P
C
        CONTINUE
C
      ELSE IF (CODE.EQ.9) THEN
C
C...  P R I N T   A   T I T L E
C
        NAMFLG = .FALSE.
        IPH=1
        MODE = 21
        JJ = 0
        SIZE=1
        BNDFLG=.FALSE.
        LDAFLG = .FALSE.
C
C ... DETERMINE VIRTUAL INDEX OF ARRAY(1) IN X-ARRAY.
C
        INDEX = (ADDRSS(ARRAY) - ADDRSS(X))/KWRDSZ + 1
        IABS = INDEX
        IF (CANFLG) CALL INCAN(INDEX)
C
        A(1) = X(IABS)
        COUNT=(IA(2)+3)/4
        CALL CFORM('0',DARRAY,1,1)
        IF (COUNT.EQ.0) THEN
          CALL CPRINT (DARRAY)
        ELSE
          J=COUNT/2+MOD(COUNT,2)
          DO 9010  I = 1,J
            A(I) = X(IABS + I)
 9010     CONTINUE
          CALL HOLFRM(A(1),CHECK,1,8,NWD)
          IF (CHECK(2:6) .EQ. RIGHT)  THEN
            CHECK(5:6)='  '
            IA(2)=BCDF(CHECK(5:8))
            K=(COUNT-1)*4
            IF(K.GT.54) K=54
            CALL HOLFRM(IA(2),DARRAY,66,K,NWD)
            KRIGHT = 1
            CALL CPRINT (DARRAY)
          ELSE
            CALL HOLFRM(IA(1),DARRAY,2,COUNT*4,NWD)
            IF (KRIGHT .EQ. 1) CALL CFORM('+',DARRAY,1,1)
            KRIGHT = 0
            CALL CPRINT (DARRAY)
          ENDIF
        ENDIF
C
      ELSE IF (CODE.EQ.10) THEN
C
C...  P R I N T   N U M  B E R   I D E N T I F I E R
C
        ISEQ = ISEQNO
        CALL RECORD(ISEQNO)
        IF (ISEQ .EQ. ISEQNO) GO TO 10010
        CALL ICONV(ISEQNO,DARRAY,2,4)
        CALL CFORM('.',DARRAY,6,1)
10010   CALL FCONV(ARRAY(1),DARRAY,30,13,6)
        CALL CPRINT (DARRAY)
      ELSE IF (CODE.EQ.11) THEN
                               
C
C...  T U R N   P R I N T   F L A G   O N
C
        PRNTON = .TRUE.
C
      ELSE IF (CODE.EQ.12) THEN
C
C...  T U R N   P R I N T   F L A G   O F F
C
        PRNTON = .FALSE.
C
      ELSE IF (CODE.EQ.13) THEN
C
C ... T U R N   P C H L S T   F L A G   O N
C
        PCHLST = .TRUE.
C
      ELSE IF (CODE.EQ.14) THEN
C
C ... T U R N   P C H L S T   F L A G   O F F
C
        PCHLST = .FALSE.
C
      ELSE IF (CODE.EQ.16) THEN
C
C ... T U R N   T A B P R T   F L A G   O F F
C
C         T O   P R I N T   T A B C Y L S
C
        TABPRT = .FALSE.
C
      ELSE IF (CODE.EQ.17) THEN
C
C ... T U R N   T A B P R T   F L A G   O N
C
C     T O   S U P P R E S S   T A B C Y L   P R I N T O U T
C
        TABPRT = .TRUE.
C
      ELSE IF (CODE.EQ.18) THEN
C
C ... T U R N   S S P R T   F L A G  O N
C
C     T O  P R I N T   S S U R F   A N D   S C U R V
C
C     PRINT/SSPRT ,ON
C
        SSPRT = .TRUE.
C
      ELSE IF (CODE.EQ.19) THEN
C
C ... T U R N   S S P R T   F L A G  O F F
C
C     T O  S U P P R E S S   S S U R F   A N D   S C U R V   P R I N T
C
C     PRINT/SSPRT ,OFF
C
        SSPRT =.FALSE.
C
      ELSE IF (CODE.EQ.20) THEN
C
C     PRINT/SSTEST,ON
C
        SSTEST= .TRUE.
C
      ELSE IF (CODE.EQ.21) THEN
C
C    PRINT/SSTEST,OFF
C
        SSTEST=.FALSE.
C
      ELSE IF (CODE.EQ.22) THEN
C
C     PRINT/AVPRT,ON   - PRINT AVOIDANCE ACTION DETAILS
C
        AVLIST=.TRUE.
C
      ELSE IF (CODE.EQ.23) THEN
C
C     PRINT/AVPRT,OFF   - SUPPRESS PRINT OF AVOIDANCE ACTION DETAILS
C
        AVLIST=.FALSE.
C
      ELSE
C.... NON VALID CODE
      ENDIF
C
C...  E X I T
C
99999 CONTINUE
      END
