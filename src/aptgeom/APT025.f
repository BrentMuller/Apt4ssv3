**** SOURCE FILE : M0000775.V04   ***
*
C
C.....FORTRAN SUBROUTINE             APT025...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT025
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED
C              WITH THE CENTER AT A GIVEN POINT AND TANGENT TO A
C              GIVEN LINE BY THE FOLLOWING APT STATEMENT
C              RESULT = CIRCLE/CENTER, PNT, TANTO, LN
C
C LINKAGE      CALL APT025 (RESULT, PNT, LN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C
C                      THE RESULTING CIRCLE
C              PNT     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT POINT
C              LN      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT LINE
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          APT081
C              SUBROUTINE          APT083
C              REAL FUNCTION       ABS
C              SUBROUTINE          DEFEXT
C
      SUBROUTINE APT025 (RESULT,PNT,LN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(7),PNT(3),LN(4)
      DOUBLE PRECISION LN
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C...     TRANSFORM PNT,LN, CHECK FOR VALIDITY
C
      CALL APT077 (LN,28)
      CALL APT081 (PNT,0)
C
C...     DEFINE VERTICAL CYLINDER WITH CENTER PNT,RADIUS DIST TO LN
C
      R(1)=P(1)
      R(2)=P(2)
      R(7)=DABS(L(4)-L(1)*R(1)-L(2)*R(2))
      CALL APT083(R,KM1)
   20 CALL DEFEXT (RESULT)
      RETURN
       END
