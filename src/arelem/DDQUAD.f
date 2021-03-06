**** SOURCE FILE : M0000888.V05   ***
*
C
C.....FORTRAN SUBROUTINE             DDQUAD...              3/1/68   GK
      SUBROUTINE DDQUAD(SRFACE)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DSHAR4.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
C
C
      DIMENSION SRFACE(10)
      IER=0
      IF(ISTRUP.EQ.5)GO TO 1015
      IF(JSW.EQ.5.OR.JSW.EQ.9)GO TO 5
      DO 1 I=1,10
    1 TEM(I)=SRFACE(I)
      A=Z2*(TEM(6)*TN(3,IS)*TN(1,IS)
     1     +TEM(7)*TN(1,IS)*TN(2,IS)
     2     +TEM(5)*TN(2,IS)*TN(3,IS))
     3     +TN(1,IS)**2*TEM(1)+TN(2,IS)**2*TEM(2)
     4     +TN(3,IS)**2*TEM(3)
      B=(TEM(1)*TN(1,IS)+TEM(7)*TN(2,IS)+TEM(6)*TN(3,IS))*TP(1,IS)
     1 +(TEM(7)*TN(1,IS)+TEM(2)*TN(2,IS)+TEM(5)*TN(3,IS))*TP(2,IS)
     2 +(TEM(6)*TN(1,IS)+TEM(5)*TN(2,IS)+TEM(3)*TN(3,IS))*TP(3,IS)
     3 +TN(1,IS)*TEM(8)+TN(2,IS)*TEM(9)+TN(3,IS)*TEM(10)
      C=Z2*(TEM(6)*TP(3,IS)*TP(1,IS)
     1  +TEM(7)*TP(1,IS)*TP(2,IS)
     2  +TEM(5)*TP(2,IS)*TP(3,IS)
     3  +TP(1,IS)*TEM(8)+TP(2,IS)*TEM(9)+TP(3,IS)*TEM(10))
     4  +TP(1,IS)**2*TEM(1)+TP(2,IS)**2*TEM(2)
     5  +TP(3,IS)**2*TEM(3)+TEM(4)
      GO TO 1000
5     A=TN(1,IS)*TN(1,IS)+TN(2,IS)*TN(2,IS)+TN(3,IS)*TN(3,IS)
      TEM(1)=TP(1,IS)-SRFACE(1)
      TEM(2)=TP(2,IS)-SRFACE(2)
      TEM(3)=TP(3,IS)-SRFACE(3)
      B=TEM(1)*TN(1,IS)+TEM(2)*TN(2,IS)+TEM(3)*TN(3,IS)
      E=TEM(1)*TEM(1)+TEM(2)*TEM(2)+TEM(3)*TEM(3)
      IF(JSW.EQ.9)GO TO 10
      C=E-SRFACE(4)*SRFACE(4)
      GO TO 1000
10    TEM(4)=SRFACE(7)*SRFACE(7)
      TEM(5)=A
      A=TN(1,IS)*SRFACE(4)+TN(2,IS)*SRFACE(5)+TN(3,IS)*SRFACE(6)
      D=TEM(1)*SRFACE(4)+TEM(2)*SRFACE(5)+TEM(3)*SRFACE(6)
      B=A*D-TEM(4)*B
      A=A*A-TEM(5)*TEM(4)
      C=D*D-TEM(4)*E
      CALL QUAD
      IF(IER)20,20,3000
20    CONTINUE
      IF((TEM(1)+S(IS)*TN(1,IS))*SRFACE(4)+(TEM(2)+S(IS)*TN(2,IS))*
     1SRFACE(5)+(TEM(3)+S(IS)*TN(3,IS))*SRFACE(6))25,25,1011
C
C     **SOLUTION INVALID**
C
25    IF(SURD)30,50,40
30    IF(IOP(IS))40,40,50
40    S(IS)=SURD
      SURD=Z0
      GO TO 20
50    IER=1
      GO TO 3000
1000  CALL QUAD
1010  IF(IER.EQ.1)GO TO 3000
1011  IF(ISTRUP.EQ.4)GO TO 1012
      SPL(1,IS)=SP(1,IS)
      SPL(2,IS)=SP(2,IS)
      SPL(3,IS)=SP(3,IS)
      SNL(1,IS)=SN(1,IS)
      SNL(2,IS)=SN(2,IS)
      SNL(3,IS)=SN(3,IS)
1012  SP(1,IS)=TP(1,IS)+S(IS)*TN(1,IS)
      SP(2,IS)=TP(2,IS)+S(IS)*TN(2,IS)
      SP(3,IS)=TP(3,IS)+S(IS)*TN(3,IS)
1015  IF(JSW.EQ.5.OR.JSW.EQ.9)GO TO 2000
      TEM(1)=SRFACE(1)*SP(1,IS)+SRFACE(7)*SP(2,IS)+
     1SRFACE(6)*SP(3,IS)+SRFACE(8)
      TEM(2)=SRFACE(7)*SP(1,IS)+SRFACE(2)*SP(2,IS)+
     1SRFACE(5)*SP(3,IS)+SRFACE(9)
      TEM(3)=SRFACE(6)*SP(1,IS)+SRFACE(5)*SP(2,IS)+
     1SRFACE(3)*SP(3,IS)+SRFACE(10)
      CALL VNORM(TEM,SN(1,IS))
      GO TO 3000
2000  SN(1,IS)=SP(1,IS)-SRFACE(1)
      SN(2,IS)=SP(2,IS)-SRFACE(2)
      SN(3,IS)=SP(3,IS)-SRFACE(3)
      CALL VNORM(SN(1,IS),SN(1,IS))
      IF(JSW.EQ.5)GO TO 3000
      IF(IER)2002,2002,2009
2009  IER=0
      SN(1,IS)=-SRFACE(4)
      SN(2,IS)=-SRFACE(5)
      SN(3,IS)=-SRFACE(6)
      GO TO 3000
2002  TEM(4)=SN(1,IS)*SRFACE(4)+SN(2,IS)*SRFACE(5)+SN(3,IS)*SRFACE(6)
      TEM(6)=DSQRT(Z1-TEM(4)*TEM(4))
      TEM(7)=DSQRT(Z1-SRFACE(7)*SRFACE(7))
      TEM(8)=TEM(4)*SRFACE(7)+TEM(6)*TEM(7)
      IF(TEM(8))3000,2005,2005
 2005 SN(1,IS)=(SRFACE(7)*SN(1,IS)-TEM(8)*SRFACE(4))/TEM(6)
      SN(2,IS)=(SRFACE(7)*SN(2,IS)-TEM(8)*SRFACE(5))/TEM(6)
      SN(3,IS)=(SRFACE(7)*SN(3,IS)-TEM(8)*SRFACE(6))/TEM(6)
3000  RETURN
      END
