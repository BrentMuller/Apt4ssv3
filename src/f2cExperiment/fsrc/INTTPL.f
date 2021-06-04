**** SOURCE FILE : M0012369.V02   ***
*
      SUBROUTINE INTTPL(NS,PT,PL,IRC)
C
C     COMPUTES THE NORMALIZED COEFFICIENTS OF A PLANE TANGENT TO SURFACE
C     "NS" WHOSE NORMAL PASSES THROUGH POINT "PT".
C     INTTPL IS CALLED BY INTERSECTION ROUTINES INTCON & INTBND.
C
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C
C SS - ARELEM - COMMON
      COMMON/SSARLM/BB(64,4),UU(4),VV(4),
     *              IITOP(6,4,4),IIFLAG(4,4),IPNUM(4)
C
C   COMMON FOR 2 SURFACE INTERSECTION
      COMMON/INTCOM/IKEEP(255)
C   EVALUATION VECTOR FOR PS AND DS
      DOUBLE PRECISION SPV(4,8,2)
      EQUIVALENCE (IKEEP(  1),SPV(1,1,1))
C   LAST THREE U,V PAIRS OF PS AND DS
      DOUBLE PRECISION UV(2,3,2)
      EQUIVALENCE (IKEEP(129),UV(1,1,1))
C   POINT OF TANGENCY ON PS AND DS
      DOUBLE PRECISION PTT(3,2)
      EQUIVALENCE (IKEEP(153),PTT(1,1))
C   THICKNESS ON PS AND DS
      DOUBLE PRECISION THICK(2)
      EQUIVALENCE (IKEEP(201),THICK(1))
C  TRACE
CCCCC EQUIVALENCE (IKEEP(249),ITRACE)
C   INTERNAL POINT COUNT
      EQUIVALENCE (IKEEP(250),IPTKNT)
C   MAXIMUM NUMBER OF POINTS
      EQUIVALENCE (IKEEP(251),NPTS)
C
      DIMENSION PT(3),PL(4),HN(3,2)
      INTEGER IPKNT(2)
      DATA IPKNT/0,0/
C
C AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
C
CCCCC IF(ITRACE.EQ.1)
CCCCC*WRITE(6,1000)
C1000 FORMAT(' ***TRACE***INTTPL')
C
C IS SURFACE NOT A PLANE ?
      IF (IIFLAG(1,NS).GT.0)GOTO 30
C
C LOAD THE PLANE
      DO 20 I=1,4
   20 PL(I)=BB(I,NS)
      IRC=0
      GOTO 999
C
C SURFACE IS NOT A PLANE; FIND TANGENT PLANE.
   30 CONTINUE
      IRC=1
      IF (NS.NE.1.AND.NS.NE.2) GOTO 100
      IRC=0
      U=UV(1,1,NS)
      V=UV(2,1,NS)
C
C EXTRAPOLATE NEXT UV IF 2 POINTS HAVE BEEN CALCULATED.
      IF (NPTS.LE.IPTKNT+2.OR.IPTKNT.EQ.IPKNT(NS)) GOTO 50
      U=U + 2.D0*(U-UV(1,2,NS)) - (UV(1,2,NS)-UV(1,3,NS))
      V=V + 2.D0*(V-UV(2,2,NS)) - (UV(2,2,NS)-UV(2,3,NS))
   50 CONTINUE
C
C CALL NORMAL DISTANCE ROUTINE
      CALL INTNRM(NS,U,V,PT,SPV(1,1,NS),IRC)
C
C SAVE SURFACE POINT
      PTT(1,NS)=SPV(1,1,NS)
      PTT(2,NS)=SPV(2,1,NS)
      PTT(3,NS)=SPV(3,1,NS)
C
C SAVE UV POSITION (NOTE: RECALCULATED IN SUB INTNRM)
      UV(1,1,NS)=U
      UV(2,1,NS)=V
      IPKNT(NS) = IPTKNT
C
C LOAD SURFACE NORMAL
      PL(1)=SPV(1,8,NS)
      PL(2)=SPV(2,8,NS)
      PL(3)=SPV(3,8,NS)
C
C HECK DIR. OF THIS NORMAL
      IF (IPTKNT.GE.NPTS-1) GOTO 80
      CS=HN(1,NS)*PL(1) + HN(2,NS)*PL(2) + HN(3,NS)*PL(3)
C IS THE NORMAL ORIENTED THE SAME AS LAST TIME?
      IF (CS.GE.0.D0) GOTO 70
C
C NO; FLIP DIR.
      PL(1)=-PL(1)
      PL(2)=-PL(2)
      PL(3)=-PL(3)
   70 CONTINUE
   80 CONTINUE
C
C SAVE THIS NORMAL FOR NEXT SOL. & CAL. CONSTANT
      HN(1,NS)=PL(1)
      HN(2,NS)=PL(2)
      HN(3,NS)=PL(3)
      PL(4)=PL(1)*SPV(1,1,NS) + PL(2)*SPV(2,1,NS) + PL(3)*SPV(3,1,NS)
  100 CONTINUE
      PL(4)=PL(4) + THICK(NS)
C
  999 RETURN
      END
