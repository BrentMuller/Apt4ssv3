**** SOURCE FILE : M0000799.V02   ***
*
C.....FORTRAN SUBROUTINE             APT049...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT049
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE
C              DEFINED WITH A GIVEN POINT AS ITS CENTER AND
C              HAVING A GIVEN RADIUS BY THE FOLLOWING APT
C              STATEMENT
C              RESULT = CIRCLE/CENTER, CNT, RADIUS, RAD
C
C LINKAGE      CALL APT049 (RESULT, CNT, RAD)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING CIRCLE
C              CNT     ARRAY CONTAINING THE CANONICAL FORM
C                      OF THE INPUT POINT
C              RAD     REAL VARIABLE CONTAINING THE VALUE
C                      OF THE DESIRED RADIUS
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT078
C              SUBROUTINE          DEFEXT
C
      SUBROUTINE APT049 (RESULT,CNT,RAD)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(7),CNT(3)
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
C...     CONVERT AXIS TO BASE SYSTEM,SET CENTER AND RADIUS
C
      CALL APT078(R(4),KM1)
      DO 10 I=1,3
      R(I+3)=R(I)
   10 R(I)=CNT(I)
      R(7)=RAD
      CALL DEFEXT(RESULT)
      RETURN
       END
