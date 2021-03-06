**** SOURCE FILE : M0002758.V07   ***
*
C
C.....FORTRAN SUBROUTINE             INDIRV...              3/1/68   GK
      SUBROUTINE INDIRV(SRFC,VCT)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C...  25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/ IAERFG
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(28),SRFACE),(SAVEH(29),VECTOR(1))
      DIMENSION VCT(3)
C
      CHARACTER*8 TEST
      INTEGER IHDS(2),BCDF
      EQUIVALENCE (IHDS,VALHDS)
C
C
C
C...  NEW DIRECTION OF MOTION IS ALONG VECTOR
C...  STORE DIRECTION VECTORS FOR DS,PS,CS AS REQUIRED
      DIMENSION VECTOR(3)
      SRFACE=SRFC
C
      CALL TRANSM(VECTOR,VCT,3,3,0)
      IF(JHLDFG.EQ.0) GO TO 501
      ITABH(ITHCNT)=11
      ITHCNT=ITHCNT+1
      RETURN
  501 CONTINUE
      IF(IGOTO)1,1,2
    2 IF(ISRCH)40,40,1000
    1 TEMP(1)=SRFACE
    3 K=IDS
      CALL HOLFRM(TEMP(1),TEST,1,8,NWD)
      IF(HDS.EQ.TEST) GO TO 5
      K=IPS
      IF(HPS.EQ.TEST) GO TO 5
      K=ICS
      IF(HCS.NE.TEST) GO TO 50
    5 DO 10 I=1,3
      VNDIR(I,K)=VECTOR(I)
   10 CONTINUE
      CALL VNORM(VNDIR(1,K),VNDIR(1,K))
      IF(IER)25,25,20
   20 IAERFG=1
      CALL AERR(21001,'INDIRV  ')
      GO TO 45
   25 INDIR(K)=K1
C...  IF DS,TELL AMIND VNDIR IS ALREADY THE FORWARD DIRECTION
      IF(HDS.NE.TEST) GO TO 1000
   30 DO 35 I=1,3
      TI(I)=VNDIR(I,K)
      TEK(I)=TE(I)-TI(I)
   35 CONTINUE
 1000 CONTINUE
      RETURN
   40 IAERFG=1
      CALL AERR(21002,'INDIRV  ')
   45 IAERR=0
      GO TO 1000
   50 CALL AERR(-21003,'INDIRV  ')
      IHDS(1) = BCDF(HDS(1:4))
      IHDS(2) = BCDF(HDS(5:8))
      TEMP(1)=VALHDS
      GO TO 3
       END
C
C
C
      SUBROUTINE INDRVH(SRFC,VCT)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C...  25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/ IAERFG
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(28),SRFACE),(SAVEH(29),VECTOR(1))
      DIMENSION VCT(3)
C
      CHARACTER*8 TEST
      INTEGER IHDS(2),BCDF
      EQUIVALENCE (IHDS,VALHDS)
C
C
C
C...  NEW DIRECTION OF MOTION IS ALONG VECTOR
C...  STORE DIRECTION VECTORS FOR DS,PS,CS AS REQUIRED
      DIMENSION VECTOR(3)
C
      IF(IGOTO)1,1,2
    2 IF(ISRCH)40,40,1000
    1 TEMP(1)=SRFACE
    3 K=IDS
      CALL HOLFRM(TEMP(1),TEST,1,8,NWD)
      IF(HDS.EQ.TEST) GO TO 5
      K=IPS
      IF(HPS.EQ.TEST) GO TO 5
      K=ICS
      IF(HCS.NE.TEST) GO TO 50
    5 DO 10 I=1,3
      VNDIR(I,K)=VECTOR(I)
   10 CONTINUE
      CALL VNORM(VNDIR(1,K),VNDIR(1,K))
      IF(IER)25,25,20
   20 IAERFG=1
      CALL AERR(21001,'INDRVH  ')
      GO TO 45
   25 INDIR(K)=K1
C...  IF DS,TELL AMIND VNDIR IS ALREADY THE FORWARD DIRECTION
      IF(HDS.NE.TEST) GO TO 1000
   30 DO 35 I=1,3
      TI(I)=VNDIR(I,K)
      TEK(I)=TE(I)-TI(I)
   35 CONTINUE
 1000 CONTINUE
      RETURN
   40 IAERFG=1
      CALL AERR(21002,'INDRHV  ')
   45 IAERR=0
      GO TO 1000
   50 CALL AERR(-21003,'INDRVH  ')
      IHDS(1) = BCDF(HDS(1:4))
      IHDS(2) = BCDF(HDS(5:8))
      TEMP(1)=VALHDS
      GO TO 3
       END
