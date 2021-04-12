**** SOURCE FILE : DIST2.ORG   ***
*
c      DOUBLE PRECISION FUNCTION DIST2(A,B)
      real*4 function dist2(a,b)
C
C.... COMPUTE THE SQUARE OF THE DISTANCE BETWEEN TWO POINTS
C
      DOUBLE PRECISION A(3),B(3)
C
      DIST2 = (A(1)-B(1))*(A(1)-B(1))
     +      + (A(2)-B(2))*(A(2)-B(2))
     +      + (A(3)-B(3))*(A(3)-B(3))
      END
