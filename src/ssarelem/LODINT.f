**** SOURCE FILE : M0000640.W01   ***
*
C
C
      SUBROUTINE LODINT(SS,B,UST,VST,TP,TN,IFLAG,ITOP,IPNUM,MODE)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C--------PROGRAM PERFORMS GLOBAL SEARCH OF PATCH STRUCTURE
C--------AND LOADS AN INITIAL PATCH BASED ON DISTANCE
C--------AS RETURNED BY PUVLOC
      DIMENSION SS(*)
      DIMENSION B(64),IFLAG(4),ITOP(6,4)
      DIMENSION TP(3),TN(3)
      HALF=0.5D0
      D=1.0D10
      IPNUM=1
      NPCHS=SS(4)
      IF (NPCHS.NE.1) THEN
      DO 20 I=1,NPCHS
      CALL LODPCH(SS,B,IFLAG,ITOP,I,1)
C.... TAKE 'CENTRE POINT' OF PATCH FOR START OF SEARCH
      UT=HALF
      VT=HALF
      CALL PUVLOC(B,TP,TN,UT,VT,DT,MODE,IFLAG)
      IF(DT.GT.D) GO TO 20
      IPNUM=I
      UST=UT
      VST=VT
      D=DT
   20 CONTINUE
      ELSE
C.... SPECIAL TREATMENT FOR SINGLE PATCH SURFACES
C.... CONSIDER 9 START POINTS
        CALL LODPCH(SS,B,IFLAG,ITOP,1,1)
        ISTEP=2
        JSTEP=2
        DO 210 I=1,ISTEP+1
          DO 200 J=1,JSTEP+1
            UT=I-1
            UT=UT/DBLE(ISTEP)
            VT=J-1
            VT=VT/DBLE(JSTEP)
            CALL PUVLOC(B,TP,TN,UT,VT,DT,MODE,IFLAG)
            IF (DT.LT.D) THEN
              IPNUM=1
              UST=UT
              VST=VT
              D=DT
            ENDIF
  200     CONTINUE
  210   CONTINUE
      ENDIF
      CALL LODPCH(SS,B,IFLAG,ITOP,IPNUM,3)
      END
