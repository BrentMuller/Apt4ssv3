**** SOURCE FILE : M0000882.V04   ***
*
C.....FORTRAN BLOCK DATA ROUTINE  ...DATA    8/68                 HG
C.....FORTRAN ROUTINE              ..DATA..    HL GRAY 3/68         *ID*
      BLOCK DATA DAT0
C
C
C
C
C ABBREVIATIONS AND TERMS
C
C
C
C
C     THE FOLLOWING ABBREVIATIONS AND TERMS ARE USED THROUGHOUT THE
C     CODING OF THE INTERPRETER.  IN GENERAL, TERMS ARE FORMED BY
C     CONCATENATING ROOT WORDS.  FOR EXAMPLE
C
C              NT        FOR NAME TABLE
C              P         FOR POINTER
C
C     FORM
C
C              NTP       NAME TABLE POINTER
C
C     AND ARE PRESENTED IN THIS GLOSSARY AS
C
C              NT.P
C
C     WHERE THE PERIODS INDICATE THE CONCATENATION AS A MEMORY AID.
C
C
C
C
C TERM         DEFINITION                                          TYPE
C
C
C A            ARRAY                                             MIXED
C
C AVT          ACTUAL VS VIRTUAL ADDRESS TABLE
C
C B            BEGINNING (USUALLY OF AN ARRAY)                     I
C
C C            CURRENT
C
C CF           CANONICAL FORM                                      D
C
C CF.B         CANONICAL FORM TABLE BEGINNING                      I
C
C CF.E         CANONICAL FORM TABLE END                            I
C
C CF.N         CANONICAL FORM TABLE LENGTH                         I
C
C CF.P         CANONICAL FORM TABLE POINTER                        I
C
C CILPRT       PRINT COMPRESSED I.L. FLAG
C
C COM          STORAGE (BLANK COMMON)                              D
C
C COM.B        STORAGE BEGINNING                                   I
C
C COM.E        STORAGE END                                         I
C
C COM.N        TOTAL LENGTH OF COMMON
C
C COM.P        STORAGE POINTER                                     I
C
C COM.S        SIZE OF ASSIGNED STORAGE FOR COMMON
C
C CM           STORAGE (BLANK COMMON) SAME AS COM)                 I
C
C E            END (USUALLY OF AN ARRAY)                           I
C
C FP           FLOATING POINT NUMBER TABLE                         D
C
C FP.B         FLOATING POINT TABLE BEGINNING                      I
C
C FP.E         FLOATING POINT TABLE END                            I
C
C FP.N         FLOATING POINT TABLE LENGTH                         I
C
C FP.P         FLOATING POINT TABLE POINTER                        I
C
C IA           INTERNAL ARRARY                                     D
C
C IA.B         INTERNAL ARRAY BEGINNING                            I
C
C IA.P         INTERNAL ARRAY POINTER                              I
C
C IL           INTERMEDIATE LANGUAGE INSTRUCTION.  AN N-TUPLE      I
C              WHOSE FORM IS SHOWN UNDER STRUCTURE.
C
C IL.C         POSITION OF CURRENT INTERMEDIATE LANGUAGE           I
C              INSTRUCTION RELATIVE TO PART PROGRAM BEGINNING
C
C IX           INDEX.  POINTER RELATIVE TO BEGINNING OF PAGE.      I
C              FIRST WORD OF PAGE HAS ZERO INDEX.
C
C IX.C         POSITION OF CURRENT INTERMEDIATE LANGUAGE           I
C              INSTRUCTION RELATIVE TO BEGINNING OF CURRENT PAGE
C
C K.           INTRODUCES A CONSTANT
C
C K.CB.N       EXTERNAL CANNON BLOCK LENGTH
C
C K.COM.F      LENGTH OF FIXED PORTION OF COMMON
C
C K.COM.T      LENGTH OF TEMPORARY PORTION OF COMMON
C
C K.IL.N       CONSTANT WHICH ADDED TO NUMBER OF PARAMETERS IN     I
C              ANY INTERMEDIATE LANGUAGE INSTRUCTION GIVES LENGTH
C              OF THAT INSTRUCTION IN WORDS.
C
C K.IL.P       POSITION RELATIVE TO BEGINNING OF INSTRUCTION  OF   I
C              THE WORD CONTAINING NUMBER OF PARAMETERS IN THE
C              INSTRUCTION.
C
C K.IL.1       POSTION RELATIVE TO BEGINNING OF PAGE OF FIRST
C              INSTRUCTION.
C
C K.NT.P       CORRECTION TO NAME TABLE POINTER TO EFFECT
C              PART PROGRAM CORRESPONDENCE
C
C K.MT.ST      MACRO TEXT FITS IN MEMORY                           L
C
C K.PG.LN      PAGE TO LINE PACKING FACTOR                         I
C
C K.PG.N       PAGE LENGTH                                         I
C K.PK.M       PACKING FACTOR FOR MODE                             I
C
C K.PK.S       PACKING FACTOR FOR SIZE                             I
C
C
C K.PP.ST      PART PROGRAM FITS IN MEMORY (INCLUDING MACRO TEXT)  L
C
C
C LN           LINE = (PAGE,INDEX)ING FACTOR) + INDEX              I
C
C LN.A         LINE ARRAY.  CONTAINS LINE NUMBERS FOR              I
C
C LN.C         CURRENT LINE NUMBER   GC*KPGLN + IXC)               I
C
C MT           MACRO TEXT (A PORTION OF THE PART PROGRAM)          H
C
C MT.B         MACRO TEXT BEGINNING                                I
C
C MT.E         MACRO TEXT END                                      I
C
C MT.N         MACRO TEXT LENGTH                                   I
C
C N            LENGTH (USUALLY OF AN ARRAY)                        I
C
C NB           NAME TABLE (SAME AS NT)                             D
C
C NBLK         NUMBER OF BLOCKS OF CANNON ALLOWED
C
C NS           NONSCALAR ARRAY                                     D
C
C NS.B         NONSCALAR ARRAY BEGINNING                           I
C
C NS.P         NONSCALAR ARRAY POINTER                             I
C
C NT           NAME TABLE                                          I
C
C NT.B         NAME TABLE BEGINNING                                I
C
C NT.E         NAME TABLE END                                      I
C
C NT.N         NAME TABLE LENGTH                                   I
C
C NT.P         NAME TABLE POINTER                                  I
C
C OD           OPERAND.  AN ORDERED PAIR, (TYPE, VALUE).           I
C
C OP           OPCODE (PORTION OF INTERMEDIATE LANGUAGE
C              INSTRUCTION)
C
C P            POINTER (USUALLY TO AN ELEMENT IN AN ARRAY          I
C
C PG           PAGE OF TEXT--POSITIVE FOR PART PROGRAM, NEGATIVE   I
C              FOR MACRO TEXT
C
C PG.C         CURRENT PAGE NUMBER                                 I
C
C PG.C.N       NUMBER OF WORDS ON CURRENT PAGE                     I
C
C PP           PART PROGRAM (INCLUDING MACRO TEXT)                 H
C
C PP.B         PART PROGRAM BEGINNING                              I
C
C PP.E         PART PROGRAM END                                    I
C
C PP.N         PART PROGRAM LENGTH                                 I
C
C RT.P         RETURN POINTER.  POINTS TO RETURN LINE IN MACRO     I
C              CALL/RETURN ARRAY, LN.A.
C
C SA           SCALAR ARRAY                                        D
C
C SA.B         SCALAR ARRAY TABLE BEGINNING                        I
C
C SA.E         SCALAR ARRAY TABLE END                              I
C
C SA.N         SCALAR ARRAY TABLE LENGTH                           I
C
C SA.P         SCALAR ARRAY TABLE POINTER                          I
C
C SC           SCALAR                                              R
C
C SC.B         SCALAR TABLE BEGINNING                              I
C
C SC.E         SCALAR TABLE END                                    I
C
C SC.N         SCALAR TABLE LENGTH                                 I
C
C SC.P         SCALAR TABLE POINTER                                I
C
C
C
C
C
C MASTER COMMON DECK
C--------------------------------------------------------------CDE PAK
C
C
C
C UNLABELED COMMON
C
C
      INCLUDE 'BLANKCOM.INC'
      INCLUDE 'INTRPEQ.INC'
C NAME TABLE
      INCLUDE 'NAMETB.INC'
C
C
C
C STOR--COMMON CONTAINING STORAGE PARAMETERS
C
C
      COMMON/STOR/  NTB,      FPB,      PPB,      COMN,  CFB,  NBLK
      INTEGER       NTB,      FPB,      PPB,      COMN,  CFB,  NBLK
C
C   ADDITIONAL STOR PARAMETERS USED FOR NUMBER TABLE DIRECT ACCESS
C
      COMMON/STOR/  NRECRD,  NTPARM
      DIMENSION     NRECRD(10), NTPARM(10)
      EQUIVALENCE   (NTPARM(1),NUMST), (NTPARM(2),NUMOD ),
     .              (NTPARM(3),NDAFLG), (NTPARM(4),NRECST),
     .              (NTPARM(5),IPAGE )
C
C WORK--COMMON CONTAINING WORKING VARIABLES
C
C
      COMMON/WORK/  PGC,      PGCN,     ILC,      IXC
      INTEGER       PGC,      PGCN,     ILC,      IXC
C
      COMMON/WORK/  SCP,      SAP,      NSP,      IAP,   CFP,   COMP
      INTEGER       SCP,      SAP,      NSP,      IAP,   CFP,   COMP
C
      COMMON/WORK/     NTP,   LNA,    RTP
C  THIS LOCATION IS USED TO PASS FUNCTION RESULTS FROM XCALL
      COMMON/WORK/AC
C   THIS ARRAY USED BY THE ROUTINES INCAN AND XCANON
      COMMON/WORK/AVT,IWRIT
      INTEGER  FPP,    NTP,    LNA,    RTP
      INTEGER                            AVT
      EQUIVALENCE  (FPP,   NTP)
      DIMENSION                LNA(2,20),      AVT(32)
      INTEGER       AC
C
C
C CONST--COMMON CONTAINING CONSTANTS
C
C
      COMMON/CONST/KCOMT,KCOMF,CILPRT,KCBN
      LOGICAL CILPRT
C
C
C
C
C---------------------------------------------------------------------
      DATA          PGC,   PGCN,   ILC,   IXC   / 0, 0, 0, 0/
      DATA          NTB/0/,RTP/0/,COMN/5000/,AVT/32*0/,IWRIT/0/
      DATA          KCOMF/40/,KCOMT/16/,KCBN/128/
      DATA          NRECRD,NTPARM /10*0, 10*0/
       END
