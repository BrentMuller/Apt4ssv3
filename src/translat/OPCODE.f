**** SOURCE FILE : M0006661.V01   ***
*
C
C              FORTRAN SUBROUTINE OPCODE
C
C LINKAGE      SUBROUTINE OPCODE(I)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    ASNADZ
C                                        SUBROUTINE    ASNJPZ
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    CALLZZ
C                                        SUBROUTINE    CALMCX
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
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    RESRVZ
C                                        SUBROUTINE    RETMCX
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE OPCODE(I)
C
      IMPLICIT INTEGER (A-Z)
C
C       19.    INTERMEDIATE LANGUAGE TEXT
C
      COMMON/ILTEXT/ILTEXT
      LOGICAL COMFIN
      DIMENSION ILTEXT(94)
C COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN
      EQUIVALENCE (COMFIN,ILTEXT(1))
C LENGTH:      NUMBER OF ITEMS IN CURRENT I.L. COMMAND ARGUMENT LIST
      EQUIVALENCE (LENGTH,ILTEXT(2))
C TPNTRX:      POINTER TO LAST TEXTIN ENTRY
      EQUIVALENCE (TPNTRX,ILTEXT(3))
C OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND
      EQUIVALENCE (OPTEXT,ILTEXT(4))
C*
C ARGUMENTS    I     INTEGER CODE FOR CURRENT I.L. COMMAND
C**
      external alarm
      IF(COMFIN)CALL ALARM(4,0,8,'OPCODE  ')
      OPTEXT = I
      LENGTH = 0
      TPNTRX = 0
      COMFIN = .TRUE.
      RETURN
       END
