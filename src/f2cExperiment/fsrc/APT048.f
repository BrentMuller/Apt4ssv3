**** SOURCE FILE : M0000798.V03   ***
*
C
C.....FORTRAN SUBROUTINE             APT048...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT048
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE
C              DEFINED AS PERPENDICULAR TO A GIVEN PLANE
C              AND PASSING THROUGH TWO GIVEN POINTS BY THE
C              FOLLOWING APT STATEMENT
C              RESULT = PLANE/PERPTO, PL, PN1, PN2
C
C LINKAGE      CALL APT048 (RESULT, PL, PN1, PN2)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING PLANE
C              PL      ARRAY CONTAINING THE CANONICAL FORM
C                      OF THE INPUT PLANE
C              PN1     ARRAY CONTAINING THE CANONICAL FORM
C                      OF THE FIRST INPUT POINT
C              PN2     ARRAY CONTAINING THE CANONICAL FORM
C                      OF THE SECOND INPUT POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT035
C              SUBROUTINE          APT073
C
      SUBROUTINE APT048 (RESULT,PL,PN1,PN2)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4),PL(4),PN1(3),PN2(3)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISHR16.INC'
C
C
C
C
C...     DEFINE A VECTOR IN THE DESIRED PLANE
C
      CALL APT035 (LN1(2),PN2,PN1)
C
C...     DEFINE THE PLANE CONTAINING A POINT, THE DEFINED VECTOR, AND A
C...     NORMAL VECTOR TO THE ORIGINAL PLANE
C
      CALL APT073 (RESULT,PL,LN1(2),PN1)
      IF (PRNTON) CALL PRINT(3,RESULT,1)
      RETURN
       END