**** SOURCE FILE : M0002803.V03   ***
*
C
C.....FORTRAN SUBROUTINE           APT074        2/69      SR
C
C              FORTRAN SUBROUTINE APT074
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CONIC
C              DEFINED BY ONE OF THE FOLLOWING APT STATEMENTS
C              RESULT = LCONIC/5PT,P1,P2,P3,P4,P5
C              RESULT = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5
C              RESULT = LCONIC/4PT1SL,P1,S1,P2,P3,P4
C              RESULT = LCONIC/4PT1SL,X1,Y1,S1,X2,Y2,X3,Y3,X4,Y4
C              RESULT = LCONIC/3PT2SL,P1,S1,P2,S2,P3
C              RESULT = LCONIC/3PT2SL,X1,Y1,S1,X2,Y2,S2,X3,Y3
C
C LINKAGE      CALL APT074(RESULT,MN,PP1,PP2,PP3,PP4,PP5)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE
C                      RESULTING CONIC
C              MN      INTEGER EQUIVALENT OF THE MODIFIER
C                      5PT = 1   4PT1SL = 2   3PT2SL = 3
C              PP1     ARRAY CONTAINING THE CANONICAL FORM OF AN
C                      INPUT POINT
C              PP2     ARRAY CONTAINING THE CANONICAL FORM OF AN
C                      CANONICAL FORM OF AN INPUT POINT
C              PP3     ARRAY CONTAINING THE CANONICAL FORM OF AN
C                      INPUT POINT
C              PP4     ARRAY CONTAINING THE CANONICAL FORM OF AN
C                      CANONICAL FORM OF AN INPUT POINT
C              PP5     ARRAY CONTAINING THE CANONICAL FORM OF AN
C                      INPUT POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT079
C              SUBROUTINE          DEFEXT
C              SUBROUTINE          ERROR
C              SUBROUTINE          TRANSF
C              REAL FUNCTION       DABS
C              REAL FUNCTION       DSQRT
C
      SUBROUTINE APT074(RESULT,MN,PP1,PP2,PP3,PP4,PP5)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DIMENSION RESULT(10),P1(3),P2(3),P3(3),P4(3),P5(3),
     /          PP1(3),PP2(3),PP3(3),PP4(3),PP5(3),
     /          SR(2),S(4),AA(4),BB(4),CC(4)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'KNUMBR.INC'
C
      DO 700 I=1,4
      GO TO (100,200,300,400),I
  100 CALL TRANSF(P1,PP1,K2,K3,K0)
      IF(UNFLAG)GO TO 910
      CALL TRANSF(P3,PP3,K2,K3,K0)
      IF(UNFLAG)GO TO 910
      CALL TRANSF(P5,PP5,K2,K3,K0)
      IF(UNFLAG)GO TO 910
      IF(MN.NE.K1)GO TO 110
      CALL TRANSF(P2,PP2,K2,K3,K0)
      IF(UNFLAG)GO TO 910
      SR(1) = P2(2)-P1(2)
      SR(2) = P2(1)-P1(1)
      GO TO 500
C
C        4PT1SL OR 3PT2SL FORMAT
C        OBTAIN FIRST SLOPE FROM P2(1), SET P2 = P1
C
  110 S(I)=PP2(1)
      P2(1) = P1(1)
      P2(2) = P1(2)
      GO TO 600
  200 IF(MN.EQ.K3)GO TO 210
      CALL TRANSF(P4,PP4,K2,K3,K0)
      IF(UNFLAG)GO TO 910
      SR(1) = P5(2)-P4(2)
      SR(2) = P5(1)-P4(1)
      GO TO 500
C
C        3PT2SL FORMAT
C        OBTAIN SECOND SLOPE FROM P4(1), SET P4 = P5
C
  210 S(I)=PP4(1)
      DO 220 J=1,2
      P4(J)=P3(J)
      P3(J)=P5(J)
  220 P5(J)=P4(J)
      GO TO 600
  300 SR(1) = P4(2)-P1(2)
      SR(2) = P4(1)-P1(1)
      GO TO 500
  400 SR(1) = P5(2)-P2(2)
      SR(2) = P5(1)-P2(1)
C        COMPUTE THE I TH SLOPE, S(I)
C
  500 IF((SR(1).EQ.Z0).AND.(SR(2).EQ.Z0)) GO TO 900
      IF(DABS(SR(1)).GT.DABS(SR(2))*Z1E6) GO TO 510
      S(I) = SR(1)/SR(2)
      GO TO 600
  510 S(I) = (SR(1)/DABS(SR(1)))*Z1E6
C
C        COMPUTE COEFFICIENTS AA(I), BB(I), CC(I), OF THE EQUATION
C        OF THE I TH LINE
C
  600 DIV = Z1
      IF(DABS(S(I)).GT.Z1) DIV =  DSQRT(S(I)**2+Z1)
      AA(I) = S(I)/DIV
      BB(I) = ZM1/DIV
      IF(DABS(BB(I)).LT.Z1EM6) BB(I)=Z0
  620 IF((I.EQ.K2).OR.(I.EQ.K4))GO TO 630
      CC(I) = -AA(I)*P1(1)-BB(I)*P1(2)
      GO TO 700
  630 CC(I) = -AA(I)*P5(1)-BB(I)*P5(2)
  700 CONTINUE
C
C        COMPUTE COEFFICIENTS OF THE QUADRIC EQUATION
C
      SR(1) = (AA(3)*P3(1)+BB(3)*P3(2)+CC(3))
     /       *(AA(4)*P3(1)+BB(4)*P3(2)+CC(4))
      SR(2) =-(AA(1)*P3(1)+BB(1)*P3(2)+CC(1))
     /       *(AA(2)*P3(1)+BB(2)*P3(2)+CC(2))
      R(1) = SR(1)*AA(1)*AA(2)+SR(2)*AA(3)*AA(4)
      R(2) = SR(1)*BB(1)*BB(2)+SR(2)*BB(3)*BB(4)
      R(3) = Z0
      R(4) = SR(1)*CC(1)*CC(2)+SR(2)*CC(3)*CC(4)
      R(5) = Z0
      R(6) = Z0
      R(7) = Z5EM1*(SR(1)*(BB(1)*AA(2)+AA(1)*BB(2))+
     /              SR(2)*(BB(3)*AA(4)+AA(3)*BB(4)))
      R(8) = Z5EM1*(SR(1)*(CC(1)*AA(2)+AA(1)*CC(2))+
     /              SR(2)*(CC(3)*AA(4)+AA(3)*CC(4)))
      R(9) = Z5EM1*(SR(1)*(CC(1)*BB(2)+BB(1)*CC(2))+
     /              SR(2)*(CC(3)*BB(4)+BB(3)*CC(4)))
      R(10)= Z0
      DET = R(1)*R(2)*R(4)-R(2)*R(8)**2-R(4)*R(7)**2
     /     -R(1)*R(9)**2+2*R(7)*R(8)*R(9)
C
C        PRINT WARNING IF THIS IS A DEGENERATE CONIC
C
      IF(DABS(DET).LT.Z1EM9) CALL ERROR(71,'APT074  ')
      IF((DABS(DET/DMAX1(R(1),R(2),R(4),R(7),R(8),R(9))).LT.Z1EM9).AND.
     / (DABS(DET).GE.Z1EM9)) CALL ERROR(71,'APT074  ')
C
C        TRANSFORM TO BASE SYSTEM AND STORE ANSWER IN RESULT
C
      CALL APT079(R,KM1)
  800 CALL DEFEXT(RESULT)
      RETURN
C
C        ERROR - TWO INPUT POINTS COINCIDE
C
  900 IERROR = 70
      GO TO 800
C
C        ERROR - INPUT POINT IS UNDEFINED
C
  910 IERROR =69
      GO TO 800
      END