**** SOURCE FILE : M0000887.V04   ***
*
C
C.....FORTRAN SUBROUTINE             DDPLAN...              3/1/68   GK
      SUBROUTINE DDPLAN(SRFACE)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C
      DIMENSION SRFACE(4)
      IER=K0
      IF(ISTRUP.EQ.5)GO TO 5
      S(IS)=SRFACE(4)
      TEM(1)=TN(1,IS)*SRFACE(1)+TN(2,IS)*SRFACE(2)+TN(3,IS)*SRFACE(3)
      S(IS)=S(IS)-(TP(1,IS)*SRFACE(1)+TP(2,IS)*SRFACE(2)+
     1TP(3,IS)*SRFACE(3))
      IF(DABS(TEM(1))-Z1EM7) 3,3,2
    2 S(IS)=S(IS)/TEM(1)
      ADUMY=IOP(IS)
      IF (IOP(IS).EQ.-1) GOTO 4
      IF(ADUMY*S(IS)) 3,4,4
    3 IER=K1
      RETURN
4     IF(ISTRUP.EQ.4)GO TO 6
      SPL(1,IS)=SP(1,IS)
      SPL(2,IS)=SP(2,IS)
      SPL(3,IS)=SP(3,IS)
      SNL(1,IS)=SN(1,IS)
      SNL(2,IS)=SN(2,IS)
      SNL(3,IS)=SN(3,IS)
6     SP(1,IS)=TP(1,IS)+S(IS)*TN(1,IS)
      SP(2,IS)=TP(2,IS)+S(IS)*TN(2,IS)
      SP(3,IS)=TP(3,IS)+S(IS)*TN(3,IS)
5     SN(1,IS)=SRFACE(1)
      SN(2,IS)=SRFACE(2)
      SN(3,IS)=SRFACE(3)
      RETURN
      END
