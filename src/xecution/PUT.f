**** SOURCE FILE : M0000952.V04   ***
*
C.....FORTRAN SUBROUTINE  ....PUT            8/68                 HG
C.....FORTRAN FUNCTION             ..PUT..     HL GRAY 3/68         *ID*
      SUBROUTINE PUT (ARG, OD)
C
C FORTRAN SUBROUTINE 'PUT (ARG, OD)'--PUT ARGUMENT INTO OPERAND
C
C PURPOSE      TO PUT THE VALUE OF AN ARGUMENT INTO THE PART PROGRAM
C              OPERAND, OD
C
C LINKAGE      CALL PUT(ARG, OD)
C
C ARGUMENTS    ARG    IS THE VALUE TO BE STORED
C              OD     IS THE ORDINAL NUMBER OF THE OPERAND
C
C METHOD       THE OPERAND CONSISTS OF THE ORDERED PAIR (TYPE, VALUE)
C              WHERE--
C
C              TYPE     VALUE
C               0        INDEX TO NAME TABLE WHICH CONTAINS POINTER
C                        TO STORAGE FOR VARIABLE
C               1,2      ERROR CONDITION
C               3        INDEX TO NAME TABLE
C              -N        INDEX TO NAME TABLE WHICH CONTAINS BASE ADDR.
C
C--------------------------------------------------------------CDE PAK
C
C
C
C UNLABELED COMMON
C
C
      INCLUDE 'BLANKCOM.INC'
      INCLUDE 'INTRPEQ.INC'
C
C
C
C STOR--COMMON CONTAINING STORAGE PARAMETERS
C
C
      COMMON/STOR/  NTB,      FPB,      PPB,      COMN
      INTEGER       NTB,      FPB,      PPB,      COMN
C
C
C WORK--COMMON CONTAINING WORKING VARIABLES
C
C
      COMMON/WORK/  PGC,      PGCN,     ILC,      IXC
      INTEGER       PGC,      PGCN,     ILC,      IXC
C
      COMMON/WORK/  SCP,      SAP,      NSP,      IAP,    CFP,    COMP
      INTEGER       SCP,      SAP,      NSP,      IAP,    CFP,    COMP
C
      COMMON/WORK/         NTP,   LNA,   RTP
      INTEGER  FPP,    NTP,    LNA,    RTP
      EQUIVALENCE  (FPP,   NTP)
      DIMENSION                   LNA(2,20)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
C
C
C---------------------------------------------------------------------
C
      INTEGER OD,K,L,XCANON
      DOUBLE PRECISION ARG
      EXTERNAL XCANON
C
C        EXTRACT TYPE AND ADD ONE FOR 'GO TO' (L)
C
      K=ILC + OD
      L = PP(K) + 1
C
C        EXTRACT VALUE OF OPERAND (K)
C
      K = PP(K+1)
C
C        PUT OPERAND ACCORDING TO TYPE
C
      IF (L .LE. 0) GO TO 50
C
C
C        COMPUTE NAME TABLE POINTER, STORE ARG AND EXIT
C
 10   NTP = NTB + K
      K = NT(1,NTP)
      IF(CANFLG) K=XCANON(K)
      CF(K) = ARG
      RETURN
C
C
C        TYPE -N
C
C        COMPUTE EFFECTIVE ADDRESS = BASE ADDRESS + INDEX,
C        STORE ARGUMENT AND EXIT
C
 50   NTP = NTB + K
      K = NT(1,NTP) - L
      IF(CANFLG) K=XCANON(K)
      IA(K) = ARG
      RETURN
C
      END
