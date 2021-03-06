**** SOURCE FILE : M0006691.W03   ***
*
C
C              FORTRAN SUBROUTINE TWOARG
C
C LINKAGE      SUBROUTINE TWOARG(I,J)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    ARGCVT
C                                        SUBROUTINE    ASNJPZ
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    CALMCX
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    GOPAT
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    RESRVZ
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE TWOARG(I,J)
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C CNUMTB:      NUMBER TABLE
C
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
C
C       27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION OPMOD(8)
C HEXDLR:      CONTAINS OPERAND TYPE CODE 6
      EQUIVALENCE (HEXDLR,OPMOD(7))
C SPTDLR:      CONTAINS OPERAND TYPE CODE 7
      EQUIVALENCE (SPTDLR,OPMOD(8))
C
C       45.    NUMBER TABLE INDICES
C
      INCLUDE 'NUMBLK.INC'
C MNMBND:      LAST NAME TABLE ENTRY TO MACRO ASSIGNED NUMBER SECTION
C NMBRS:       QUANTITY OF NUMBERS IN THE CURRENT STATEMENT
C*
C ARGUMENTS    I         NORMALLY TYPE DESIGNATION OF
C                        ARGUMENT J.  COULD BE A NAME
C                        TABLE (NAMTBL) INDEX OF NUMBER.
C              J         NAME TABLE (NAMTBL) INDEX OF
C**                      ARGUMENT.
      external alarm
      IF (COMFIN) GOTO 10
      IERROR=3
      GO TO 90
   10 IF (TPNTRX.LT.89) GOTO 20
      IERROR=2
   90 CALL ALARM(IERROR,0,8,'TWOARG  ')
      GO TO 100
   20 K=I
      IF(J.LE.(MNMBND+NAMMAX))GOTO 30
C     HEXDLR: INDICATES NON FRACTIONAL REAL LITERAL
C     SPTDLR: INDICATES FRACTIONAL REAL LITERAL
      K=HEXDLR
      IDP=INDEX(CNUMTB(J-NAMMAX),'.')
      IF (CNUMTB(J-NAMMAX)(IDP+1:).EQ.' ') GOTO 30
      K=SPTDLR
      NMBRS=NMBRS+1
   30 TEXTIN(TPNTRX+1) = K
      TEXTIN(TPNTRX+2) = J
      TPNTRX = TPNTRX+2
  100 RETURN
       END
