**** SOURCE FILE : M0012335.V02   ***
*
      SUBROUTINE SETVER(W)
C
C ROUTINE SETVER SETS THE STARTING VALUES FOR INTERSECTION
C
C STORES ARRAY W IN ARRAY W1 IN COMMON/VERCOM FOR USE BY GETVER
C
C       W1     : I: DEFINITION OF 1ST LINE: START POINT (U1,V1)
C                                           END   POINT (U2,V2)
C                    W1(1) = U1
C                    W1(2) = V1
C                    W1(3) = U2-U1
C                    W1(4) = V2-V1
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      DIMENSION W1(4),W(4)
C
      COMMON/VERCOM/UMIN1,UMAX1,VMIN1,VMAX1,W1
C
      DO 10 I=1,4
        W1(I)=W(I)
   10 CONTINUE
C
      UMIN1=DMIN1(W1(1),W1(1)+W1(3))
      UMAX1=DMAX1(W1(1),W1(1)+W1(3))
      VMIN1=DMIN1(W1(2),W1(2)+W1(4))
      VMAX1=DMAX1(W1(2),W1(2)+W1(4))
      END
C
      SUBROUTINE GETVER(W2,RESULT,IRES)
C
C ROUTINE   GETVER COMPUTES THE INTERSECTION
C       W2     : I: DEFINITION OF 2ND LINE: START POINT (U3,V3)
C                                           END   POINT (U4,V4)
C                    W2(1) = U3
C                    W2(2) = V3
C                    W2(3) = U4-U3
C                    W2(4) = V4-V3
C       RESULT : O: RESULTING VALUES, POINT OF INTERSECTION
C       IRES   : O: =0: NO INTERSECTION
C                   =1: INTERSECTION, RESULT IN RESULT
C                   =2: INTERSECTION, PARALLEL LINES,
C                        UPON EACH OTHER
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      DIMENSION W1(4), W2(4), RESULT(2)
C
      COMMON/VERCOM/UMIN1,UMAX1,VMIN1,VMAX1,W1
C
      IRES=0
C
      IF(UMIN1.GT.DMAX1(W2(1),W2(1)+W2(3))) RETURN
      IF(UMAX1.LT.DMIN1(W2(1),W2(1)+W2(3))) RETURN
      IF(VMIN1.GT.DMAX1(W2(2),W2(2)+W2(4))) RETURN
      IF(VMAX1.LT.DMIN1(W2(2),W2(2)+W2(4))) RETURN
C
      IF(((W2(1)-W1(1))*W1(4)  -
     *    (W2(2)-W1(2))*W1(3)) *
     *   ((W2(1)+W2(3) -W1(1)) *W1(4) -
     *    (W2(2)+W2(4) -W1(2)) *W1(3))
     *                            .GT.0.D0) RETURN
C
      IF(((W1(1)-W2(1))*W2(4)  -
     *    (W1(2)-W2(2))*W2(3)) *
     *   ((W1(1)+W1(3) -W2(1)) *W2(4) -
     *    (W1(2)+W1(4) -W2(2)) *W2(3))
     *                            .GT.0.D0) RETURN
C
C INTERSECT THE 1ST AND 2ND LINE
      A1= W1(4)
      A2=-W1(3)
      A3= W1(4)*W1(1)-W1(3)*W1(2)
      B1= W2(4)
      B2=-W2(3)
      B3= W2(4)*W2(1)-W2(3)*W2(2)
C
C  CHECK FOR PARALLEL
      D=A2*B1-A1*B2
      IF(DABS(D).LT.1D-10)GOTO 50
      RESULT(1)=-(A3*B2-A2*B3)/D
      RESULT(2)=(A3*B1-A1*B3)/D
      IRES=1
      GOTO 60
   50 IRES=2
   60 CONTINUE
CCCCC WRITE(6,100)IRES,W1,W2,RESULT
CC100 FORMAT(' IRES,W1,W2,RESULT:'/I3/1X,4F20.5/1X,4F20.5/1X,2F20.5)
C
      RETURN
      END
