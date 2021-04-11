**** SOURCE FILE : M0000845.V03   ***
*
C...  FORTRAN SUBROUTINE     APT106    6/69      SR
C
C PURPOSE      TO COMPUTE AND STORE THE CANONICAL FORM
C              OF THE NTH POINT OF A PATERN
C
C LINKAGE      CALL APT106(RESULT,PAT,RN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE POINT
C              PAT     ARRAY CONTAINING THE I.C.F. OF THE PATERN
C              RN      NUMBER OF THE DESIRED POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT094
C              LOGICAL FUNCTION    CKDEF
C              SUBROUTINE          DEFEXT
C              SUBROUTINE          NPAT
C
      SUBROUTINE APT106(RESULT,PAT,RN)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DIMENSION RESULT(3),PAT(2)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'IDEF.INC'
C
C
      INCLUDE 'BLANKCOM.INC'
C
      LOGICAL CKDEF
C
      IF(CKDEF(PAT))GO TO 90
C
C              MOVE THE EXTERNAL CANONICAL FORM TO BCANON
C
      CALL APT094(2,PAT,BCANON)
      IF(CKDEF(PAT))GO TO 90
C
C              CHECK TO SEE THAT N IS LESS THAN OR EQUAL TO
C              THE NUMBER OF POINTS IN THIS PATERN
C
      IF(RN.GT.BCANON(4))GO TO 95
      N=RN+Z1EM5
C
C          DETERMINE AND STORE THE COORDINATES OF THE POINT
C
      CALL NPAT(R,N)
   10 CALL DEFEXT(RESULT)
C
      RETURN
C
C          REFERENCED PATERN HAS NOT BEEN PREVIOUSLY CORRECTLY DEFINED
C
   90 IERROR=37
      GO TO 10
C
C          THE NUMBER OF THE REQUESTED POINT IS GREATER THAN THE
C          NUMBER OF POINTS IN THE PATERN
C
   95 IERROR=38
      GO TO 10
      END