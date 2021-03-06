**** SOURCE FILE : M0000631.V02   ***
*
      SUBROUTINE GELG(R,A,EPS,M,N,IER)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION A(*),R(*)
      IF(M) 230,230,10
   10 IER=0
      PIV=0.
      MM=M*M
      NM=N*M
      DO 30  L=1,MM
      TB=DABS(A(L))
      IF(TB-PIV) 30,30,20
   20 PIV=TB
      I=L
   30 CONTINUE
      TOL=EPS*PIV
      LST=1
      DO 170 K=1,M
      IF(PIV)   230,230,40
   40 IF(IER) 70,50,70
   50 IF(PIV-TOL)  60,60,70
   60 IER=K-1
   70 PIVI=1./A(I)
      J=(I-1)/M
      I=I-J*M-K
      J=J+1-K
      DO 80 L=K,NM,M
      LL=L+I
      TB=PIVI*R(LL)
      R(LL)=R(L)
   80  R(L)=TB
      IF (K-M)  90,180,180
   90 LEND=LST+M-K
      IF(J)  120,120,100
  100 II=J*M
      DO 110 L=LST,LEND
      TB=A(L)
      LL=L+II
      A(L)=A(LL)
  110 A(LL)=TB
  120 DO 130 L=LST,MM,M
      LL=L+I
      TB=PIVI*A(LL)
      A(LL)=A(L)
  130 A(L)=TB
      A(LST)=J
      PIV=0.
      LST=LST+1
      J=0
      DO 160 II=LST,LEND
      PIVI=-A(II)
      IST=II+M
      J=J+1
      DO 150 LX=IST,MM,M
      LL=LX-J
      A(LX)=A(LX)+PIVI*A(LL)
      TB=DABS(A(LX))
      IF(TB-PIV) 150,150,140
  140 PIV=TB
      I=LX
  150 CONTINUE
      DO 165 L=K,NM,M
      LL=L+J
  165 R(LL)=R(LL)+PIVI*R(L)
  160 CONTINUE
  170 LST=LST+M
  180 IF(M-1)  230,220,190
  190 IST=MM+M
      LST=M+1
      DO 210 I=2,M
      II=LST-I
      IST=IST-LST
      L=IST-M
      L=A(L)+.5
      DO  210  J=II,NM,M
      TB=R(J)
      LL=J
      DO 200 K=IST,MM,M
      LL=LL+1
  200 TB=TB-A(K)*R(LL)
      K=J+L
      R(J)=R(K)
  210 R(K)=TB
  220 GO TO 240
  230 IER=-1
  240 RETURN
      END
