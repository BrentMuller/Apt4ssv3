**** SOURCE FILE : M0002754.V09   ***
*
C
C.....FORTRAN SUBROUTINE             INDIRP...              3/1/68   GK
      SUBROUTINE INDIRP(SRFC,PNT)
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
      CHARACTER*8 TEST
      INTEGER IHDS(2),BCDF
      EQUIVALENCE(IHDS,VALHDS)
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(32),SRFACE),(SAVEH(33),POINT(1))
C
C     25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/ IAERFG,NPCTPT,PCTPTS,PCTPLN,ERRPTS
      DIMENSION PCTPTS(3,20),PCTPLN(4),ERRPTS(3,3)
C
C...  NEW DIRECTION OF MOTION IS FROM PRESENT TOOL POSITION TO POINT
C...  STORE DIRECTION VECTORS FOR DS,PS,CS AS REQUIRED
      DIMENSION POINT(3)
      DIMENSION PNT(3)
C
      SRFACE=SRFC
C
      CALL TRANSM(POINT,PNT,2,3,0)
      IF(JHLDFG.EQ.0) GO TO 501
      ITABH(ITHCNT)=12
      ITHCNT=ITHCNT+1
      RETURN
C
  501 CONTINUE
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
      VNDIR(I,K)=POINT(I)-TE(I)
   10 CONTINUE
      CALL VNORM(VNDIR(1,K),VNDIR(1,K))
      IF(IER)25,25,20
   20 IAERFG=1
      CALL AERR(20901,'INDIRP  ')
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
C...  DIRECTION OF MOTION GIVEN WITHOUT A STARTING POINT GIVEN
   40 IAERFG=1
      CALL AERR(20902,'INDIRP  ')
   45 IAERR=0
      GO TO 1000
C...  WARNING-CANNOT DETERMINE SURFACE TYPE. DS ASSUMED
   50 CALL AERR(-20903,'INDIRP  ')
      IHDS(1) = BCDF(HDS(1:4))
      IHDS(2) = BCDF(HDS(5:8))
      TEMP(1)=VALHDS
      GO TO 3
       END
C
C
C
      SUBROUTINE INDRPH(SRFC,PNT)
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
      CHARACTER*8 TEST
      INTEGER IHDS(2),BCDF
      EQUIVALENCE(IHDS,VALHDS)
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(32),SRFACE),(SAVEH(33),POINT(1))
C
C     25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/ IAERFG,NPCTPT,PCTPTS,PCTPLN,ERRPTS
      DIMENSION PCTPTS(3,20),PCTPLN(4),ERRPTS(3,3)
C
C...  NEW DIRECTION OF MOTION IS FROM PRESENT TOOL POSITION TO POINT
C...  STORE DIRECTION VECTORS FOR DS,PS,CS AS REQUIRED
      DIMENSION POINT(3)
      DIMENSION PNT(3)
C
C
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
      VNDIR(I,K)=POINT(I)-TE(I)
   10 CONTINUE
      CALL VNORM(VNDIR(1,K),VNDIR(1,K))
      IF(IER)25,25,20
   20 IAERFG=1
      CALL AERR(20901,'INDRPH  ')
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
C...  DIRECTION OF MOTION GIVEN WITHOUT A STARTING POINT GIVEN
   40 IAERFG=1
      CALL AERR(20902,'INDRPH  ')
   45 IAERR=0
      GO TO 1000
C...  WARNING-CANNOT DETERMINE SURFACE TYPE. DS ASSUMED
   50 CALL AERR(-20903,'INDRPH  ')
      IHDS(1) = BCDF(HDS(1:4))
      IHDS(2) = BCDF(HDS(5:8))
      TEMP(1)=VALHDS
      GO TO 3
       END
