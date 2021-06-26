**** SOURCE FILE : M0000431.V02   ***
*
C
C.....FORTRAN SUBROUTINE              APT315                12/67
C PURPOSE      TO NORMALIZE A GIVEN VECTOR.
C LINKAGE      CALL APT315 (B,C)
C ARGUMENTS    B    ARRAY TO CONTAIN THE NORMALIZED VECTOR
C              C    ARRAY CONTAINING THE VECTOR TO BE NORMALIZED
C SUBSIDIARIES NONE
      SUBROUTINE APT315 (B,C)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C      NORM NORMALIZES A VECTOR V---NORM= VX/V + VY/V + VZ/V
      DIMENSION A(3),B(3),C(3)
           DO 10 I = 1,3
 10           A(I) = C(I)
      S = DSQRT(A(1)*A(1)+A(2)*A(2)+A(3)*A(3))
      IF (S .LT. 0.000001D0)  S=1.0
C
       DO 2  I=1,3
       B(I)= A(I)/S
      IF ((DABS(B(I)))-0.000001D0) 1,1,2
 1     B(I)=0.0
 2     CONTINUE
       RETURN
       END