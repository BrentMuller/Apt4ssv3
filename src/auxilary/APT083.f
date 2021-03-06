**** SOURCE FILE : M0000831.V02   ***
*
C.....FORTRAN SUBROUTINE             APT083...              5/1/68   GK
C
C              FORTRAN SUBROUTINE APT083
C
C PURPOSE      TO SET UP THE COMPLETE PARAMETER LIST FOR THE
C              TRANSFORMATION OF THE CANONICAL FORM OF A
C              CIRCLE, CONE OR CYLINDER WHEN A REFSYS STATE-
C              MENT IS IN EFFECT.
C
C LINKAGE      CALL APT083 (SI, IE)
C
C ARGUMENTS    SI      ARRAY CONTAINING THE CANONICAL FORM TO BE
C                      TRANSFORMED
C              IE      INTEGER WHICH INDICATES TRANSFORMATION
C                      DIRECTION AND AN ERROR CODE NUMBER WHEN AN
C                      INPUT CIRCLE IS TO BE CHECKED TO BE SURE IT
C                      IS A VERTICAL CYLINDER
C                      IE + O TRANSFORM LOCAL TO BASE
C                      IE = O TRANSFORM BASE TO LOCAL
C                      IE = O TRANSFORM BASE TO LOCAL AND CHECK
C                             FOR VERTICAL CYLINDER.
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          TRANSF
C
      SUBROUTINE APT083 (SI,IE)
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
      CALL TRANSF (C,SI,K5,K7,IE)
       RETURN
       END
