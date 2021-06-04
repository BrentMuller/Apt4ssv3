**** SOURCE FILE : M0001113.W01   ***
*
      SUBROUTINE STEPCK(SIDE,R,RX,RK,RL,RXL,RKL,EFRAD,TOL,
     X                  SRMIN,TLMIN)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
      DIMENSION R(*),RX(1),RL(*),RXL(1)
      DIMENSION RDIF(3)
      CHARACTER*20 BADMSG
      DATA SMAL,BIG/1.0D-38,1.0D+10/
C--PURPOSE IS TO COMPUTE MINIMUM SURFACE (SRMIN) AND TOOL STEPS
C--(TLMIN) BASED ON CURRENT AND LAST CONTACT POINTS
C
      SRMIN=BIG
      TLMIN=BIG
      DO 10 I=1,3
   10 RDIF(I)=R(I)-RL(I)
      CALL DOTF(RSQ,RDIF,RDIF)
C
      CALL SRFTOL(RK,EFRAD,TOL,SMIN,TMIN)
      SRMIN=DMIN1(SRMIN,SMIN)
      TLMIN=DMIN1(TLMIN,TMIN)
C
      CALL SRFTOL(RKL,EFRAD,TOL,SMIN,TMIN)
      SRMIN=DMIN1(SRMIN,SMIN)
      TLMIN=DMIN1(TLMIN,TMIN)
C
      IF(RSQ.LT.SMAL) GO TO 999
      CALL DOTF(W,R(29),RDIF)
      W=-2.*W*SIDE/RSQ
      CALL SRFTOL(W,EFRAD,TOL,SMIN,TMIN)
      SRMIN=DMIN1(SRMIN,SMIN)
      TLMIN=DMIN1(TLMIN,TMIN)
C
      CALL DOTF(W,RL(29),RDIF)
      W=2.*W*SIDE/RSQ
      CALL SRFTOL(W,EFRAD,TOL,SMIN,TMIN)
      SRMIN=DMIN1(SRMIN,SMIN)
      TLMIN=DMIN1(TLMIN,TMIN)
C
  999 CONTINUE
      IF(IBUG.NE.11) GO TO 1999
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER STEPCK'
      CALL CPRINT(BADMSG)
      CALL BAD(1,1,'SIDE',SIDE)
      CALL BAD(1,1,'RK  ',RK)
      CALL BAD(1,1,'RKL ',RKL)
      CALL BAD(1,1,'ERAD',EFRAD)
      CALL BAD(-1,1,'TOL ',TOL)
      CALL BAD(1,1,'SRMN',SRMIN)
      CALL BAD(-1,1,'TLMN',TLMIN)
 1999 CONTINUE
      RETURN
      END
