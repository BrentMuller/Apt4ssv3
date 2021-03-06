**** SOURCE FILE : M0000905.W01   ***
*
C.....FORTRAN SUBROUTINE             GAUSS...               4/1/68   GK
      SUBROUTINE GAUSS(VEC1,D1,VEC2,D2,VEC3,D3,PT,IR)
      IMPLICIT DOUBLE PRECISION(A-H), DOUBLE PRECISION(O-Z)
      DIMENSION A(12),ASAV(4),PT(3),VEC1(3),D1(1),VEC2(3),D2(1),VEC3(3),
     1          D3(1),C(3)
      DATA EPS/0.9999D0/,ONE/1.D0/,ZERO/0.D0/
                                             
C.... CHECK FOR ANY TWO INPUT VECTORS BEING PARALLEL
C
      CALL DOTF(ERG1,VEC1,VEC2)
      CALL DOTF(ERG2,VEC1,VEC3)
      CALL DOTF(ERG3,VEC2,VEC3)
      IF (ABS(ERG1).GT.EPS) THEN
        IR=12
        IF (ERG1.LT.ZERO) IR=-12
      ELSE IF (ABS(ERG2).GT.EPS) THEN
        IR=13
        IF (ERG2.LT.ZERO) IR=-13
      ELSE IF (ABS(ERG3).GT.EPS) THEN
        IR=23
        IF (ERG3.LT.ZERO) IR=-23
      ELSE
      DO 7 I = 1,3
      A(I) = VEC1(I)
      A(I+4) = VEC2(I)
    7 A(I+8) = VEC3(I)
      A(4) = D1(1)
      A(8) = D2(1)
      A(12) = D3(1)
      Q = 0.
      DO 2 I = 1,3
      C(I) =DABS(A(4*I-3))
      Q = Q + C(I)
    2 CONTINUE
      IF (Q) 2000,2000,3
    3 IF (C(2) - C(1)) 30,30,40
   30 IF (C(3) - C(1)) 70,70,50
   40 IF (C(3) - C(2)) 60,60,50
   50 JMAX = 3
      GO TO 65
   60 JMAX = 2
   65 K = 2**JMAX
      DO 66 I = 1,4
      M = I + K
      ASAV(I) = A(I)
      A(I) = A(M)
      A(M) = ASAV(I)
   66 CONTINUE
   70 COE5 =A(5)/A(1)
      COE9 =A(9)/A(1)
      DO 75 J = 2,4
      A(J+4) = A(J+4) - COE5*A(J)
      A(J+8) = A(J+8) - COE9*A(J)
   75 CONTINUE
      C(2) =DABS(A(6))
      C(3) =DABS(A(10))
      IF (C(2)+C(3)) 2000,2000,80
   80 IF (C(2)-C(3)) 90,100,100
   90 DO 95 J = 1,4
      ASAV(J) = A(J+4)
      A(J+4) = A(J+8)
      A(J+8) = ASAV(J)
   95 CONTINUE
  100 COE10 = A(10)/A(6)
      DO 105 J = 3,4
  105 A(J+8) = A(J+8) - A(J+4)*COE10
      IF (A(11)) 1050,2000,1050
 1050 PT(3) = A(12)/A(11)
      PT(2) = (A(8)-A(7)*PT(3))/A(6)
      PT(1) = (A(4)-A(3)*PT(3)-A(2)*PT(2))/A(1)
      GO TO 2010
 2000 IR = 1
      GO TO 2020
 2010 IR = 0
      ENDIF
 2020 RETURN
      END
