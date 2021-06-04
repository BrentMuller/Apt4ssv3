**** SOURCE FILE : M0000660.V02   ***
*
      SUBROUTINE SNORM(A,B,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION A(*),B(*)
      IRR=1
      W=DSQRT(A(1)*A(1)+A(2)*A(2)+A(3)*A(3))
      IF(W.LT.1.0D-15) RETURN
      IRR=0
      B(1)=A(1)/W
      B(2)=A(2)/W
      B(3)=A(3)/W
      RETURN
      END
