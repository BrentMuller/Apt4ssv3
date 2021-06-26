**** SOURCE FILE : M0001098.W02   ***
*
      SUBROUTINE SRFTOL(SKRV,TRAD,TOL,SSTEP,TSTEP)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
C--PURPOSE IS TO COMPUTE SURFACE STEP DISTANCE SSTEP AND
C--TOOL STEP DISTANCE TSTEP ALONG SURFACE BASED ON CURVATURE
C--SKRV AND TOOL RADIUS TRAD AND TOLERANCE BAND TOL
C
      CHARACTER*20 BADMSG
      DATA ZERO,ONE,SMAL,BIG/0.0D0,1.0D0,1.0D-9,1.0D+9/
C
      SSTEP=BIG
      TSTEP=SSTEP
      IF(DABS(SKRV).LT.SMAL) GO TO 999
      SRAD=1/SKRV
      W=DABS(SRAD-TRAD)
      IF(W.LT.SMAL) GO TO 999
C--COSINE OF HALF ANGLE OF MOVEMENT
      CHAF=ONE-TOL/W
      SHAF=ONE-CHAF**2
      SHAF=DMAX1(SMAL,SHAF)
      SHAF=DSQRT(SHAF)
      SSTEP=2.*DABS(SRAD)*SHAF
      TSTEP=2.*W*SHAF
C
  999 CONTINUE
      IF(IBUG.NE.11) GO TO 1999
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER SRFTOL'
      CALL CPRINT(BADMSG)
      CALL BAD(1,1,'SKRV',SKRV)
      CALL BAD(1,1,'TRAD',TRAD)
      CALL BAD(1,1,'TOL ',TOL)
      CALL BAD(1,1,'SSTP',SSTEP)
      CALL BAD(-1,1,'TSTP',TSTEP)
 1999 CONTINUE
      RETURN
      END