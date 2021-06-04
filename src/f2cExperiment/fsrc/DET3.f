**** SOURCE FILE : M0001064.V02   ***
*
      FUNCTION DET3(A,B,C)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION A(*),B(*),C(*)
C           /-COMPUTE DETERMINANT FROM ROW VECTORS A,B AND C
      DET3=A(1)*(B(2)*C(3)-B(3)*C(2))
     X    -A(2)*(B(1)*C(3)-B(3)*C(1))
     X    +A(3)*(B(1)*C(2)-B(2)*C(1))
      RETURN
      END
