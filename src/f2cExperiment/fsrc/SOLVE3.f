**** SOURCE FILE : SOLVE3.ORG   ***
*
      SUBROUTINE SOLVE3(A,B,X,IFLAG)
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C     GIVEN A, B, SOLVES AX=B
      DIMENSION A(3,3),B(3),X(3)
C
C
      D=A(1,1)*(A(2,2)*A(3,3)-A(2,3)*A(3,2))
     1       -A(1,2)*(A(2,1)*A(3,3)-A(2,3)*A(3,1))
     1       +A(1,3)*(A(2,1)*A(3,2)-A(2,2)*A(3,1))
      IF (ABS(D).LT.1D-8) THEN
            IFLAG=1
            GOTO 100
      END IF
C
      IFLAG=0
      D=1.D0/D
C
      E=B(1)*(A(2,2)*A(3,3)-A(2,3)*A(3,2))
     1       -A(1,2)*(B(2)*A(3,3)-A(2,3)*B(3))
     1       +A(1,3)*(B(2)*A(3,2)-A(2,2)*B(3))
      X(1)=E*D
C
      E=A(1,1)*(B(2)*A(3,3)-A(2,3)*B(3))
     1       -B(1)*(A(2,1)*A(3,3)-A(2,3)*A(3,1))
     1       +A(1,3)*(A(2,1)*B(3)-B(2)*A(3,1))
      X(2)=E*D
C
      E=A(1,1)*(A(2,2)*B(3)-B(2)*A(3,2))
     1       -A(1,2)*(A(2,1)*B(3)-B(2)*A(3,1))
     1       +B(1)*(A(2,1)*A(3,2)-A(2,2)*A(3,1))
      X(3)=E*D
C
100   CONTINUE
C
      END
