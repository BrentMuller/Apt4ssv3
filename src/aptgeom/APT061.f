**** SOURCE FILE : M0000811.V03   ***
*
C
C.....FORTRAN SUBROUTINE             APT061...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT061
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A GENERAL
C              CONIC IN THE XY PLANE BY THE COEFFICIENTS OF
C              THE EXPRESSION OF ONE VARIABLE AS A FUNCTION OF
C              THE OTHER
C                Y = PX + Q + RX2 + SX + T OR
C                X = PY + Q + RY2 + SY + T
C              BY THE APT STATEMENTS
C                   RESULT = GCONIC/P,Q,RA,S,T OR
C                   RESULT = GCONIC/P,Q,RA,S,T, FUNOFY
C                            RESPECTIVELY.
C
C LINKAGE      CALL APT061 (RESULT, PM,Q,RA,SM,TM,MN,)
C
C ARGUMENTS    RESULTS ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING CONIC
C              PM      COEFFICIENT IN APPROPRIATE EQUATION
C                      ABOVE
C              Q       COEFFICIENT IN APPROPRIATE EQUATION
C                      ABOVE
C              RA      COEFFICIENT IN APPROPRIATE EQUATION
C                      ABOVE
C              SM      COEFFICIENT IN APPROPRIATE EQUATION
C                      ABOVE
C              TM      COEFFICIENT IN APPROPRIATE EQUATION
C                      ABOVE
C              MN      INTEGER EQUIVALENT OF MODIFIER
C                      1 IF NOT FUNOFY; 2 IF FUNOFY
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT079
C              SUBROUTINE          DEFEXT
C
      SUBROUTINE APT061 (RESULT,PM,Q,RA,SM,TM,MN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10)
C
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
      EQUIVALENCE (S1,SC(1)),(S2,SC(2))
C
C
      S1=PM
      S2=Q
      I=MN
      J=K3-I
      R(I) = S1**2-RA
      R(I+7) = S1*S2-SM/Z2
      R(J)=Z1
      R(J+7)=-S2
      R(4)=S2**2-TM
      R(6)=Z0
      R(7)=-S1
      CALL APT079(R,KM1)
      CALL DEFEXT(RESULT)
      RETURN
       END
