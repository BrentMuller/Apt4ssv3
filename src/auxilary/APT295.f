**** SOURCE FILE : M0000861.V02   ***
*
C.....FORTRAN SUBROUTINE              APT295               4/30/68
C
C PURPOSE      TO HANDLE EXPONENTIATION
C
C LINKAGE      CALL APT295 (RESULT,A,B)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN RESULT
C              A       BASE
C              B       EXPONENT
C
C SUBSIDIARIES TYPE                ENTRY
C              REAL FUNCTION       DABS
C
      SUBROUTINE APT295 (RESULT,A,B)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DIMENSION RESULT(1),A(1),B(1)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'ZNUMBR.INC'
C
C
      BABS=DABS(B(1))
      RESULT(1)=DABS(A(1))**BABS
      IF(A(1).GE.Z0)GO TO 10
C
C          WARNING - THE FOLLOWING PROCEDURE WILL GIVE AN INCORRECT
C          RESULT FOR THE PART PROGRAM COMBINATION NEGATIVE A
C          AND NON-INTEGER B
C
      IBABS=BABS+Z1EM2
      RESULT(1)=(ZM1**IBABS)*RESULT(1)
   10 IF(B(1).GE.Z0)GO TO 20
      RESULT(1)=Z1/RESULT(1)
   20 RETURN
       END
