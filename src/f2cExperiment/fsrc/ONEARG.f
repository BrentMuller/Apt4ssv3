**** SOURCE FILE : M0006660.V01   ***
*
C
C              FORTRAN SUBROUTINE ONEARG
C
C LINKAGE      SUBROUTINE ONEARG(I)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    ASNADZ
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    CALLZZ
C                                        SUBROUTINE    CALMCX
C                                        SUBROUTINE    ISSCOD
C                                        SUBROUTINE    JUMPZZ
C                                        SUBROUTINE    LABELZ
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MNPROC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    RETMCX
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE ONEARG(I)
C
      IMPLICIT INTEGER (A-Z)
C
C       19.    INTERMEDIATE LANGUAGE TEXT
C
      COMMON/ILTEXT/ILTEXT
      LOGICAL COMFIN
      DIMENSION ILTEXT(94),TEXTIN(90)
C COMFIN:      TRUE IF I.L. OPERATION CODE GIVEN
      EQUIVALENCE (COMFIN,ILTEXT(1))
C TPNTRX:      POINTER TO LAST TEXTIN ENTRY
      EQUIVALENCE (TPNTRX,ILTEXT(3))
C TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST
      EQUIVALENCE (TEXTIN(1),ILTEXT(5))
      external alarm
C*
C ARGUMENTS    I       NAME TABLE (NAMTBL) INDEX OF ARGUMENT
C**
      IF (COMFIN) GOTO 10
      IERROR=3
      GO TO 90
   10 IF (TPNTRX.LT.90) GOTO 20
      IERROR=2
   90 CALL ALARM(IERROR,0,8,'ONEARG  ')
      GO TO 100
   20 TEXTIN(TPNTRX+1) = I
      TPNTRX = TPNTRX+1
  100 RETURN
       END
