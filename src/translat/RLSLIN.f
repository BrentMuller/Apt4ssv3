**** SOURCE FILE : M0006682.V05   ***
*
C
C              FORTRAN SUBROUTINE RLSLIN
C
C LINKAGE      SUBROUTINE RLSLIN
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    FOUTXX          SUBROUTINE    ASNADZ
C          SUBROUTINE    COMPRS          SUBROUTINE    ASNJPZ
C          SUBROUTINE    PRTIL           SUBROUTINE    BOOLIF
C          SUBROUTINE    BINBCD          SUBROUTINE    CALMCX
C                                        SUBROUTINE    COMSTR
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    GOPAT
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    ISSCOD
C                                        SUBROUTINE    JUMPZZ
C                                        SUBROUTINE    LABELZ
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MNPROC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REFGEN
C                                        SUBROUTINE    REFREF
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    RESRVZ
C                                        SUBROUTINE    RETMCX
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE RLSLIN
C
      IMPLICIT INTEGER (A-Z)
C
C       11.    SEQUENCE NUMBER STORAGE
C
      INCLUDE 'SEQCOM.INC'
C
C SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER
C SEQNUM:      ALPHANUMERIC REPRESENTATION OF CURRRENT STATEMENT NUMBER
C
C       14.    I. L. LIST OPTION FLAGS
C
      COMMON/PRT/PRT
      LOGICAL ILPRT,MCHDNG
      DIMENSION PRT(7)
C ILPRT:       TRUE INDICATES I.L. PRINTING (PPOPTN/INTLNG,ON)
      EQUIVALENCE (ILPRT,PRT(2))
C MCHDNG:      TRUE IF START OF NEW MACRO PROCESSING
      EQUIVALENCE (MCHDNG,PRT(7))
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C RESRV:       CONTAINS COMMAND CODE (12) FOR RESRV COMMAND
      EQUIVALENCE (RESRV,IL(12))
C
C       19.    INTERMEDIATE LANGUAGE TEXT
C
      COMMON/ILTEXT/ILTEXT
      LOGICAL COMFIN
      DIMENSION ILTEXT(94)
C COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN
      EQUIVALENCE (COMFIN,ILTEXT(1))
C OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND
      EQUIVALENCE (OPTEXT,ILTEXT(4))
C
C       22.    MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      LOGICAL ILHLT
      DIMENSION MACXX1(71)
C ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE
      EQUIVALENCE (ILHLT,MACXX1(14))
C INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING
      EQUIVALENCE (INTMED,MACXX1(22))
C
C       33.    SYMBOLIC FILE DEFINITIONS
C
      INCLUDE 'SYMFIL.INC'
C VLFILE:      VERIFICATION LISTING FILE
C*
      LOGICAL  HEADNG
      CHARACTER LINE*124,M1*36,M2*44
      DATA  LINE(1:4),HEADNG/' ',.TRUE./
      DATA M1/'0 ** FINAL MACRO I.L. PROCESSING ** '/
      DATA M2/'0GENERATED I.L. FOR MACRO AT SEQNCE '/
C**
      COMFIN=.FALSE.
      IF (ILHLT) GOTO 6
    1 IF (.NOT.ILPRT) GOTO 3
C...CHECK FOR FINAL MACRO PROCESSING
      IF (INTMED) 2,2,4
    2 LINE(121:124)=SEQNUM(1:4)
      CALL PRTIL(LINE)
    3 CALL COMPRS
      GO TO 7
C...CHECK IF HEADING SHOULD BE PRINTED ON VLFILE
    4 IF (.NOT.HEADNG) GOTO 5
      CALL FOUTXX(VLFILE,M1,36)
      HEADNG=.FALSE.
C
C...CHECK FOR START OF NEW MACRO I.L.
    5 IF (.NOT.MCHDNG) GOTO 2
      CALL BINBCD(SEQNO,SEQNUM,N)
      M2(37:44)=SEQNUM
      CALL FOUTXX(VLFILE,M2,44)
      MCHDNG=.FALSE.
      GOTO 2
    6 IF (OPTEXT.EQ.RESRV) GOTO 1
    7 RETURN
      END
