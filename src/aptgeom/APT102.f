**** SOURCE FILE : M0001150.V06   ***
*
      SUBROUTINE APT102(BOUNDN,SURFN,HSMOD,M)
C
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
C
C
      INCLUDE 'BLANKCOM.INC'
C
      COMMON/SSBOND/SBOND0,SBOND,MMODE,ICON,PTS,JAG
c      DIMENSION BOUNDN(1),SURFN(1),X(1),HSMOD(3),COEF(10)
      dimension boundn(1),surfn(7),x(1),hsmod(3),coef(10)
      DIMENSION SBOND(9),RESULT(10),PTS(20)
      DIMENSION RESUL0(2)
      EQUIVALENCE (RESUL0(2),RESULT(1))
      EQUIVALENCE (TTEST,IA)
     1    ,(COEF(1),A),(COEF(2),B),(COEF(3),C),(COEF(4),F),(COEF(5),G),
     2     (COEF(6),H),(COEF(7),P),(COEF(8),Q),(COEF(9),R),(COEF(10),D)
      LOGICAL IEFLG,ERR86,ERR85,ERRFLG,CKDEF
      CHARACTER*8 TEST,XPOSX,XPOSY,XNEGX,XNEGY,XIN,XOUT,XSEG
C
C                                                                   *CD*
      DATA XPOSX/'POSX    '/,XPOSY/'POSY    '/,XNEGX/'NEGX    '/
      DATA XNEGY/'NEGY    '/,XIN/'IN      '/,XOUT/'OUT     '/
      DATA XSEG/'SEG     '/
       HHH=SURFN(1)
      CALL HOLFRM(HHH,TEST,1,8,NWD)
      IF(TEST.EQ.XSEG) GO TO 400
      JJJ=4
      IF (BOUNDF) GO TO 1
       BOUNDF=.TRUE.
    1 IF (M .NE. 1) GO TO 2
      JAG=0
      IE=1
      N=0
      SBOND0=SURFN(N)
      ERR85=.FALSE.
      ERR86=.FALSE.
      DO 200 II=1,8
 200  SBOND(II)=SURFN(II)
      IZRO=0
      ICON=0
 2    HHH =HSMOD(1)
      CALL HOLFRM(HHH,TEST,1,8,NWD)
      JAG=JAG+1
      IF(TEST.EQ.XPOSX.OR.TEST.EQ.XOUT) IE=1
      IF(TEST.EQ.XPOSY) IE=2
      IF(TEST.EQ.XNEGX.OR.TEST.EQ.XIN) IE=4
      IF(TEST.EQ.XNEGY) IE=5
      CALL UNPACK(SURFN,MODE,ISIZE,ISUB)
      JJJ=1
      IF(M.EQ.1) MMODE=MODE
      IF(M.EQ.1) GO TO 97
      RESUL0(1)=19030000.0D0
      IF((MMODE.EQ.1).AND.(MODE.EQ.1)) GO TO 210
      IF((MMODE.EQ.4).AND.(MODE.EQ.1)) GO TO 220
      IF((MMODE.EQ.4).AND.(MODE.EQ.4)) GO TO 230
      IF((MMODE.EQ.1).AND.(MODE.EQ.4)) GO TO 240
      GO TO 97
 210  CALL APT003(RESULT,SBOND,SURFN)
      GO TO 300
 220  CALL APT004(RESULT,IE,SURFN,SBOND)
      GO TO 300
 230  CALL APT005(RESULT,IE,SBOND,SURFN)
      GO TO 300
 240  CALL APT004(RESULT,IE,SBOND,SURFN)
 300  JJJ=3
      PTS(ICON+1)=RESULT(1)
      PTS(ICON+2)=RESULT(2)
      PTS(ICON+3)=RESULT(3)
      ICON=ICON+3
      GO TO 97
  400 ITY=1
C  ABFRAGE OB KREISDEFINITION (MMODE=4)
      IF(MMODE.EQ.4) ITY=0
      CALL SYCURV(BOUNDN(1),PTS,SBOND,ITY)
 97    RETURN
      END
