**** SOURCE FILE : M0000829.V02   ***
*
C.....FORTRAN SUBROUTINE             APT079...              5/1/68   GK
C
C              FORTRAN SUBROUTINE APT079
C
C PURPOSE      TO SET UP THE COMPLETE PARAMETER LIST FOR THE
C              TRANSFORMATION OF THE CANONICAL FORM OF A QUADRIC
C              SURFACE WHEN A REFSYS STATEMENT IS IN EFFECT.
C
C LINKAGE      CALL APT079 (SI, IE)
C
C ARGUMENTS    SI      ARRAY CONTAINING THE CANONICAL FORM TO BE
C                      TRANSFORMED.
C              IE      INTEGER INDICATING TRANSFORMATION DIRECTION.
C                      IE + O TRANSFORM LOCAL TO BASE
C                      IE = O TRANSFORM BASE TO LOCAL
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          TRANSF
C
      SUBROUTINE APT079 (SI,IE)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION SI(10)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'KNUMBR.INC'
C
C
      CALL TRANSF (G,SI,K1,K10,IE)
       RETURN
       END
