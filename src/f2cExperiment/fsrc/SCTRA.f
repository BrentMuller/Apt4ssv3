**** SOURCE FILE : M0001090.V07   ***
*
       SUBROUTINE SCTRA(XMA,ANA,CAN,ISPRNT)
C----------  THE PURPOSE OF THIS SUBROUTINE IS TO PERFORM GEOMETRY
C----------  TRANSFORMATION FOR THE SYNTHETIC CURVESS.
C----------      XMA     TRANSFORMATION MATRIX
C----------      ANA     CURVE NAME
C----------      CAN     CANON OF THE CURVE
C----------      ISPRNT  PRINT FLAG
C----------
       IMPLICIT DOUBLE PRECISION(A-H,O-Z)
       CHARACTER*8 BLANK,DARRAY*120,ANAME*16
       DIMENSION ANA(10),CAN(*),A(4,4),B(4,24),C(4,24)
       DIMENSION IFLG(4),W(16),XMA(12)
       DATA BLANK/'        '/
       IGNC=0
       CALL HOLFRM(ANA(3),ANAME,1,8,NWD)
       ANAME(9:16)=BLANK
       DARRAY=BLANK
       CALL CFORM('1THE FOLLOWING SSURF OR SCURV WAS ',DARRAY,1,34)
       CALL CFORM('TRANSFORMED BY THE MATRIX',DARRAY,36,25)
       CALL CPRINT(DARRAY)
       CALL CFORM('0',DARRAY,1,1)
       CALL CPRINT(DARRAY)
C***  INPUT MATRIX
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
       NARC=CAN(4)
       NPT=NARC+1
       IV=CAN(5)
       IA=IV
       DO 2200 N=1,NARC
       IB=IA
       DO 2100 M=1,4
       B(1,M)=CAN(IB)
       B(2,M)=CAN(IB+4)
       B(3,M)=CAN(IB+8)
       B(4,M)=CAN(IB+12)
       IB=IB+1
 2100  CONTINUE
       IB=IA
C----------  CRSSPL  OR  NORMAL
       DO 2300 K=1,2
       KK=K+4
       IC=IB-(3-K)*4
       B(1,KK)=CAN(IC)
       B(2,KK)=CAN(IC+1)
       B(3,KK)=CAN(IC+2)
       B(4,KK)=0.0
 2300  CONTINUE
       ML=6
       IF(N.NE.NARC) GO TO 2500
       IA1=IA+19
       IA2=IA+23
       IF((CAN(IA1).EQ.0).AND.(CAN(IA2).EQ.0)) GO TO 2500
       DO 2310 K=1,2
       KK=K+6
       IC=IB+16+(K-1)*4
       B(1,KK)=CAN(IC)
       B(2,KK)=CAN(IC+1)
       B(3,KK)=CAN(IC+2)
       B(4,KK)=0.0
 2310  CONTINUE
       ML=8
 2500  CONTINUE
       DO 240 KA=1,ML
       DO 230 II=1,4
       D=0.0
       DO 220 JJ=1,4
       C(II,KA)=A(II,JJ)*B(JJ,KA)+D
 220   D=C(II,KA)
 230   CONTINUE
 240   CONTINUE
       IB=IA
       DO 2600 M=1,4
       CAN(IB)=C(1,M)
       CAN(IB+4)=C(2,M)
       CAN(IB+8)=C(3,M)
       CAN(IB+12)=C(4,M)
       IB=IB+1
 2600  CONTINUE
       IB=IA
       DO 2700 K=1,2
       KK=K+4
       IC=IB-(3-K)*4
       CAN(IC)=C(1,KK)
       CAN(IC+1)=C(2,KK)
       CAN(IC+2)=C(3,KK)
 2700  CONTINUE
       IF(ML.EQ.6) GO TO 2800
       DO 2710 K=1,2
       KK=K+6
       IC=IB+16+(K-1)*4
       CAN(IC)=C(1,KK)
       CAN(IC+1)=C(2,KK)
       CAN(IC+2)=C(3,KK)
 2710  CONTINUE
 2800  IA=IA+24
 2200  CONTINUE
       CALL SCPICT(CAN,ANAME,ISPRNT)
 999    RETURN
        END
