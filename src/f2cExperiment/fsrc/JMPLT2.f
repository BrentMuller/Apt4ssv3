**** SOURCE FILE : JMPLT2.ORG   ***
*
      SUBROUTINE JMPLT2(U,V,DU,DV,IEDGE)
C
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C
C     LIMITS JUMP DU,DV TO KEEP U,V IN RANGE 0-1
C     DIRECTION OF LIMITED JUMP SAME AS ORIGINAL,UNLESS EITHER U OR V
C     ARE ALREADY AT LIMIT
C     U, V UNCHANGED
C     IEDGE = 0      NOT LIMITED
C             1      LIMITED
C
C
      INCLUDE 'ZNUMBR.INC'
C
      IEDGE=0
C
C     TEST DU, MODIFY DU,DV
C
      IF ( (ABS(DU-Z0).LE.Z1EM9).OR.
     +     (ABS(U-Z1).LE.Z1EM9 .AND. DU.GT.0).OR.
     +     (ABS(U-Z0).LE.Z1EM9 .AND. DU.LT.0) ) THEN
            IEDGE=1
            DU=Z0
      ELSE IF (U+DU.GT.Z1) THEN
            IEDGE=1
            C=Z1-U
            DV=DV*C/DU
            DU=C
      ELSE IF (U+DU.LT.Z0) THEN
            IEDGE=1
            DV=-DV*U/DU
            DU=-U
      END IF
C
C     TEST DV, MODIFY DU,DV
C
      IF ( (ABS(DV-Z0).LE.Z1EM9).OR.
     +     (ABS(V-Z1).LE.Z1EM9 .AND. DV.GT.0).OR.
     +     (ABS(V-Z0).LE.Z1EM9 .AND. DV.LT.0) ) THEN
            IEDGE=1
            DV=Z0
      ELSE IF (V+DV.GT.Z1) THEN
            IEDGE=1
            C=Z1-V
            DU=DU*C/DV
            DV=C
      ELSE IF (V+DV.LT.Z0) THEN
            IEDGE=1
            DU=-DU*V/DV
            DV=-V
      END IF
C
      END
