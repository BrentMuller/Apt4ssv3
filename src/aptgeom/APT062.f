**** SOURCE FILE : M0000812.V02   ***
*
C.....FORTRAN SUBROUTINE             APT062...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT062
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A QUADRIC
C              SURFACE DEFINED BY THE COEFFICIENTS OF THE
C              GENERAL EQUATION AX2+BY2+CZ2+D+FYZ+GXZ+HXY
C              +PX+QY+RZ = O
C              BY THE FOLLOWING APT STATEMENT
C                RESULT = QADRIC/A,B,C,F,G,H,P,Q,R,D
C
C LINKAGE      CALL APT062 (RESULT, AN,BN,C2,F,GN,H,PN,Q,RA,D)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING QUADRIC
C              AN      COEFFICIENT OF THE X2 TERM
C              BN      COEFFICIENT OF THE Y2 TERM
C              C2      COEFFICIENT OF THE Z2 TERM
C              F       COEFFICIENT OF THE YZ TERM
C              GN      COEFFICIENT OF THE XZ TERM
C              H       COEFFICIENT OF THE XY TERM
C              PN      COEFFICIENT OF THE X TERM
C              Q       COEFFICIENT OF THE Y TERM
C              RA      COEFFICIENT OF THE Z TERM
C              D       CONSTANT TERM
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT079
C              SUBROUTINE          DEFEXT
C
      SUBROUTINE APT062 (RESULT,AN,BN,C2,F,GN,H,PN,Q,RA,D)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
      R(1)=AN
      R(2)=BN
      R(3)=C2
      R(4)=D
      R(5)=F/Z2
      R(6)=GN/Z2
      R(7)=H/Z2
      R(8)=PN/Z2
      R(9)=Q/Z2
      R(10)=RA/Z2
C
C...     CONVERT FORM TO BASE SYSTEM
C
      CALL APT079(R,KM1)
C
C...     MOVE TO RESULT
C
      CALL DEFEXT(RESULT)
      RETURN
       END