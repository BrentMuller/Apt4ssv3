**** SOURCE FILE : M0000819.V03   ***
*
C.....FORTRAN SUBROUTINE  ....APT069         8/68                    RN
C.....FORTRAN SUBROUTINE              APT069
C
C              FORTRAN SUBROUTINE APT069
C
C PURPOSE      TO GENERATE A MATRIX OF ROTATION ABOUT
C              A POINT AND VECTOR BY THE FOLLOWING APT STATEMENT
C              RESULT = MATRIX/ PT1,VEC1, ANGLE
C
C LINKAGE      CALL APT069 (RESULT,PT,VT1,BETA)
C
C ARGUMENTS   RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING MATRIX
C              PT      ARRAY CONTAINING THE CANONICAL FORM OF
C                      INPUT POINT
C              VT1     ARRAY CONTAINING THE CANONICAL FORM OF
C                      INPUT VECTOR
C              BETA    REAL VARIABLE CONTAINING THE VALUE OF
C                      ROTATION ANGLE (DEGREES)
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          VNORM
C              LOGICAL FUNCTION    CKDEF
C              SUBROUTINE          DOTF
C              REAL    FUNCTION    DCOS
C              REAL    FUNCTION    DSIN
C
      SUBROUTINE APT069(RESULT,PT,VT1,BETA)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION  RESULT(12),PT(3),VT1(3)
C
C
C
      INCLUDE 'TOTAL.INC'
      LOGICAL CKDEF
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      EQUIVALENCE (SC(1),ALP,D1),(SC(2),COSA),(SC(3),SINA),(SC(4),OMC)
      UNFLAG=CKDEF(PT).OR.CKDEF(VT1)
      CALL VNORM(VT1,V)
      ALP=BETA*DEGRAD
      COSA=DCOS(ALP)
      SINA=DSIN(ALP)
      IF (DABS(COSA) .LT. Z1EM9) COSA=Z0
      IF (DABS(SINA) .LT. Z1EM9) SINA=Z0
      OMC =Z1-COSA
      RESULT( 1)=COSA
      RESULT( 2)=-V(3)*SINA
      RESULT( 3)=V(2)*SINA
      RESULT( 5)=V(3)*SINA
      RESULT( 6)=COSA
      RESULT( 7)=-V(1)*SINA
      RESULT( 9)=-V(2)*SINA
      RESULT(10)=V(1)*SINA
      RESULT(11)=COSA
      DO 10 J=1,3
      D1=V(J)
      RESULT(J)=V(1)*OMC*D1+RESULT(J)
      RESULT(J+4)=V(2)*OMC*D1+RESULT(J+4)
   10 RESULT(J+8)=V(3)*OMC*D1+RESULT(J+8)
      J=0
      DO 20 I=1,3
      CALL DOTF(RESULT(J+4),RESULT(J+1),PT(1))
      RESULT(J+4)=PT(I)-RESULT(J+4)
   20 J=J+4
      RETURN
      END
