**** SOURCE FILE : CALMXB.ORG   ***
*
      SUBROUTINE CALMXB(RS,TUL,W,U,SN,BETA,LRET)
C
C     PURPOSE: TO COMPUTE MAXIMUM TILT ANGLE WHERE TOOL WILL FIT
C              INTO CONCAVE SURFACE
C
C     ARGUMENTS:
C       RS     - MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT
C       TUL    - TOOL GEOMETRY
C       W      - ORIGINAL TOOL AXIS
C       U      - LOCAL AXIS DIRECTION ORTHOGONAL TO W IN DIRECTION
C                OF POSITIVE TILT
C       SN     - SURFACE NORMAL AT POINT OF CONTACT (TOWARDS TOOL)
C       BETA   - TILT ANGLE
C                  VALUE ON INPUT WILL BE IDEAL TILT TO CLEAR SURFACE
C                  AND WILL BE USED TO DETERMINE WHICH OF THE
C                  TWO ALTERNATIVE IS TO BE RETURNED AS THE MAXIMUM
C       LRET   - RETURN FLAG = .TRUE. - COMPUTED OK, ELSE .FALSE.
C
      DOUBLE PRECISION RS,TUL,W,U,SN,BETA
      DIMENSION TUL(7),W(3),U(3),SN(3)
      LOGICAL LRET
C
C     GLOBAL VARIABLES:
C
      INCLUDE 'ZNUMBR.INC'
C
C     LOCAL VARIABLES:
C
C       SPHI     - SIN(PHI)   WHERE PHI IS ANGLE BETWEEN TA AND SN
C       CPHI     - COS(PHI)   WHEN TOOL AND SURFACE CURVATURES MATCH
C       A,B,C,D1 - WORK VARIABLES
C       DISC     - DISCRIMINANT OF QUADRATIC EQUATION
C       SB1,SB2  - TWO POSSIBLE VALUES FOR SIN(BETA)
C       B1,B2    - TWO POSSIBLE VALUES OF BETA
C       BNEW     - NEW VALUE OF BEAT
C
      DOUBLE PRECISION SPHI,CPHI,A,B,C,D1,DISC,SB1,SB2,B1,B2,BNEW
C
C.... COMPUTE SINE OF ANGLE BETWEEN TOOL AXIS (W) AND SN SUCH THAT
C     TOOL CURVATURE WILL FIT SURFACE CURVATURE AT POINT OF CONTACT
C
      SPHI=TUL(3)/(RS-TUL(1))
      A=Z1-SPHI*SPHI
      IF (ABS(A).LE.Z1EM6) THEN
        CPHI=Z1
      ELSE
        CPHI=SQRT(A)
      ENDIF
C
C.... BETA HAS TO SATISFY TWO EQUATIONS
C
C      TA = COS(BETA)*W + SIN(BETA)*U   (1)
C      TA.SN = COS(PHI)                 (2)
C
C      TAKING SN DOT (1) AND SUBSTITUTING FOR TA.SN, RESULTS IN
C
C      COS(PHI)=COS(BETA)*(W.SN)+SIN(BETA)*(U.SN)
C
C                                       2
C      SQUARING AND SUBSTITUTING FOR COS (BETA)
C      WILL GIVE A QUADRATIC IN SIN(BETA) - HENCE BETA
C
      CALL DOTF(A,W,SN)
      CALL DOTF(B,U,SN)
C
      D1=A*A+B*B
      DISC=D1-CPHI*CPHI
C
      IF ((DISC.GT.Z1EM6).AND.(D1.GT.Z1EM6)) THEN
C
        C=SQRT(DISC)
C
        SB1=(B*CPHI+A*C)/D1
        SB2=(B*CPHI-A*C)/D1
        B1=ASIN(SB1)
        B2=ASIN(SB2)
C
C.... SELECT APPROPRIATE SOLUTION DEPENDENT ON IDEAL BETA TO CLEAR SURF
C
        IF (BETA.GT.Z0) THEN
          BNEW=MAX(B1,B2)
          IF (BNEW.GT.Z0) THEN
            BETA=BNEW
            LRET=.TRUE.
          ELSE
            BETA=Z0
            LRET=.FALSE.
          ENDIF
        ELSE IF (BETA.LT.Z0) THEN
          BNEW=MIN(B1,B2)
          IF (BNEW.LT.Z0) THEN
            BETA=BNEW
            LRET=.TRUE.
          ELSE
            BETA=Z0
            LRET=.FALSE.
          ENDIF
        ELSE
          BETA=Z0
          LRET=.FALSE.
        ENDIF
      ELSE
C.... NO SOLUTION TO QUADRATIC
        BETA=Z0
        LRET=.FALSE.
      ENDIF
C
      END