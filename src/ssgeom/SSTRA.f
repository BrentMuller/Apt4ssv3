**** SOURCE FILE : M0008157.V11   ***
*
       SUBROUTINE SSTRA(XMA,ANA,CAN,ISPRNT)
C----------  THE PURPOSE OF THIS SUBROUTINE IS TO PERFORM GEOMETRY
C----------  TRANSFORMATION FOR THE SCULPTURED SURFACES.
C----------      XMA     TRANSFORMATION MATRIX
C----------      ANA     SURFACE NAME
C----------      CAN     CANON OF THE SURFACE
C----------      ISPRNT  PRINT FLAG
C----------
       IMPLICIT DOUBLE PRECISION(A-H,O-Z)
       CHARACTER BLANK*8
       INTEGER BCDF
       DIMENSION ANA(10),CAN(*),A(4,4),B(4,24),C(4,24)
       DIMENSION IFLG(4),W(16),XMA(12)
      CHARACTER*8 TNAME,ANAME*16
      INCLUDE 'DARRAY.INC'
C
       DATA BLANK/'        '/
C
C---      BUDD CHANGE TO TEST TABPRT FLAG FOR PRINT OUTPUT.
       IGNC=0
       CALL HOLFRM(ANA(3),ANAME,1,8,NWD)
       ANAME(9:16)=BLANK
      IF(ISPRNT.EQ.0) GO TO 2
       DO 1 I=1,15
       I1=I*8
  1    DARRAY(I1-7:I1)=BLANK
       CALL CFORM('1THE FOLLOWING SSURF OR SCURV WAS ',DARRAY,1,34)
       CALL CFORM('TRANSFORMED BY THE MATRIX',DARRAY,36,25)
       CALL CPRINT(DARRAY)
       CALL CFORM('0',DARRAY,1,1)
       CALL CPRINT(DARRAY)
C***  INPUT MATRIX
    2 CONTINUE
       DO 7 I=1,3
       DO 7 J=1,4
       LL=(I-1)*4+J
       A(I,J)=XMA(LL)
  7    CONTINUE
       A(4,1)=0.0
       A(4,2)=0.0
       A(4,3)=0.0
       A(4,4)=1.0
C***  ************
      IF(ISPRNT.EQ.0) GO TO 3
       DO 12 I=1,4
       K=2
       DO 11 J=1,4
       CALL FCONV(A(I,J),DARRAY,K,12,5)
       K=K+12
 11    CONTINUE
       CALL CPRINT(DARRAY)
 12    CONTINUE
       CALL CFORM('0',DARRAY,1,1)
       CALL CPRINT(DARRAY)
C***  ************
    3 CONTINUE
       NPCH=CAN(4)
       NNN=CAN(5)
       DO 15 I=1,16
 15    W(I)=0.0
       W(1)=1.0
       W(2)=W(1)
       W(5)=W(1)
       W(6)=W(1)
       DO 500 N=1,NPCH
       I=11+6*(N-1)
       IFLG(1)=CAN(I)
       IFLG(2)=CAN(I+1)
       IFLG(3)=CAN(I+2)
       IFLG(4)=CAN(I+3)
      IF(IFLG(2).NE.0) GOTO 8
C NON NATIVE PATCH TRANSFORMATION
      IGNC=1
      CALL HOLFRM(CAN(I+4),TNAME,1,8,NWD)
      CALL TEVAL(TNAME,XMA,CAN(IFLG(1)))
      GOTO 500
    8 CONTINUE
       IV=CAN(I+4)
       IF(IV.LT.0) GO TO 1000
C----------  GENERAL CURVE TYPE BRANCH TO 1000
C----------  COONS BICUBIC PATCH FOLLOWS
       IF(IFLG(4).NE.4) GO TO 19
       IU=IV+47
       DO 17 IW=1,16
       IX=IU+IW
 17    W(IW)=CAN(IX)
 19    CONTINUE
C----------  NON TWIST CONSTANT
       MM=12
       NST=3
       IH=1
       IF (IFLG(1).EQ.3) GO TO 50
C----------  TWIST CONSTANT
       MM=16
       NST=4
   50  IF(IFLG(1).LT.3) GO TO 900
       DO 400 IJK=1,NST
       IA=IV
       IB=IV+MM
       IC=IV+MM+MM
       B(1,1)=CAN(IA)
       B(2,1)=CAN(IB)
       B(3,1)=CAN(IC)
       B(4,1)=W(IH)
       B(1,2)=CAN(IA+1)
       B(2,2)=CAN(IB+1)
       B(3,2)=CAN(IC+1)
       B(4,2)=W(IH+1)
       L=4
       IF((IJK.EQ.3).AND.(NST.EQ.3)) L=2
       B(1,3)=CAN(IA+L)
       B(2,3)=CAN(IB+L)
       B(3,3)=CAN(IC+L)
       B(4,3)=W(IH+L)
       B(1,4)=CAN(IA+L+1)
       B(2,4)=CAN(IB+L+1)
       B(3,4)=CAN(IC+L+1)
       B(4,4)=W(IH+L+1)
       DO 40 KA=1,4
       DO 30 II=1,4
       D=0.0
       DO 20 JJ=1,4
       C(II,KA)=A(II,JJ)*B(JJ,KA)+D
 20    D=C(II,KA)
 30    CONTINUE
 40    CONTINUE
       IA=IV
       IB=IV+MM
       IC=IV+MM+MM
       CAN(IA)=C(1,1)
       CAN(IB)=C(2,1)
       CAN(IC)=C(3,1)
       CAN(IA+1)=C(1,2)
       CAN(IB+1)=C(2,2)
       CAN(IC+1)=C(3,2)
       CAN(IA+L)=C(1,3)
       CAN(IB+L)=C(2,3)
       CAN(IC+L)=C(3,3)
       CAN(IA+L+1)=C(1,4)
       CAN(IB+L+1)=C(2,4)
       CAN(IC+L+1)=C(3,4)
       IV=IV+2
       IF(IJK.EQ.2) IV=IV+4
       IH=IH+2
       IF(IJK.EQ.2) IH=IH+4
400    CONTINUE
       GO TO 500
C----------  GENCUR  SURFACE
 1000  IGNC=1
       DO 1900 JK=1,4
       ISC=IFLG(JK)
       IF(ISC.EQ.0) GO TO 1900
       NARC=CAN(ISC+3)
       NPT=NARC+1
       IQ=CAN(ISC+4)+ISC-1
       IA=IQ
       DO 1200 NR=1,NARC
       IB=IA
       DO 1100 M=1,4
       B(1,M)=CAN(IB)
       B(2,M)=CAN(IB+4)
       B(3,M)=CAN(IB+8)
       B(4,M)=CAN(IB+12)
       IB=IB+1
 1100  CONTINUE
       IB=IA
C----------  CRSSPL  AND  NANDMAL
       DO 1300 K=1,2
       KK=K+4
       IC=IB-(3-K)*4
       B(1,KK)=CAN(IC)
       B(2,KK)=CAN(IC+1)
       B(3,KK)=CAN(IC+2)
       B(4,KK)=0.0
 1300  CONTINUE
       ML=6
       IF(NR.NE.NARC) GO TO 1500
       IA1=IA+19
       IA2=IA+23
       IF((CAN(IA1).EQ.0).AND.(CAN(IA2).EQ.0)) GO TO 1500
       DO 1310 K=1,2
       KK=K+6
       IC=IB+16+(K-1)*4
       B(1,KK)=CAN(IC)
       B(2,KK)=CAN(IC+1)
       B(3,KK)=CAN(IC+2)
       B(4,KK)=0.0
 1310  CONTINUE
       ML=8
 1500  CONTINUE
       DO 140 KA=1,ML
       DO 130 II=1,4
       D=0.0
       DO 120 JJ=1,4
       C(II,KA)=A(II,JJ)*B(JJ,KA)+D
 120   D=C(II,KA)
 130   CONTINUE
 140   CONTINUE
       IB=IA
       DO 1600 M=1,4
       CAN(IB)=C(1,M)
       CAN(IB+4)=C(2,M)
       CAN(IB+8)=C(3,M)
       CAN(IB+12)=C(4,M)
       IB=IB+1
 1600  CONTINUE
       IB=IA
       DO 1700 K=1,2
       KK=K+4
       IC=IB-(3-K)*4
       CAN(IC)=C(1,KK)
       CAN(IC+1)=C(2,KK)
       CAN(IC+2)=C(3,KK)
 1700  CONTINUE
       IF(ML.EQ.6) GO TO 1800
       DO 1710 K=1,2
       KK=K+6
       IC=IB+16+(K-1)*4
       CAN(IC)=C(1,KK)
       CAN(IC+1)=C(2,KK)
       CAN(IC+2)=C(3,KK)
 1710  CONTINUE
 1800  IA=IA+24
 1200  CONTINUE
 1900  CONTINUE
 500   CONTINUE
       IF(IGNC.NE.1) GO TO 550
       JMD=1
       CALL APT094(JMD,ANA(1),CAN(1))
  550 IF(ISPRNT.EQ.0) GO TO 999
      CALL SSPICT(CAN,ANAME,ISPRNT)
       GO TO 999
C----------  LINEAR OR CONSTANT MATRIX, WILL NOT TRANSFORM
 900    CONTINUE
 999   RETURN
       END
