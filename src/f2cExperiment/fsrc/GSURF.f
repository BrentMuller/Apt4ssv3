**** SOURCE FILE : M0000921.V02   ***
*
C...  FORTRAN SUBROUTINE GSURF                   7/70      RW
C
C PURPOSE      CONTROL ROUTINE TO TRANSFORM APT SURFACE CANONICAL FORMS
C              INTO QUADRIC EQUATION COEFFICIENTS.
C
C CALLING SEQUENCE    CALL GSURF(COEBUF,CANON,MODE,ISIZ,ERRFLG)
C
C ARGUMENTS    COEBUF        ARRAY TO CONTAIN QUADRIC EQUATION COEF.
C
C              CANON         INPUT ARRAY CONTAINING CANONICAL FORM
C
C              MODE          MODE OF CANONICAL FORM
C
C              ISIZ          SIZE OF CANONICAL FORM
C
C              ERRFLG        LOGICAL FLAG WHICH IS RETURNED AS TRUE ONLY
C                            IF MODE IS NOT A QUADRIC SURFACE.
C
C CALLED BY    APT102
C              APT104
C
C SUBSIDIARIES TYPE              ENTRY
C              SUBROUTINE        GCIRCL
C              SUBROUTINE        GCONE
C              SUBROUTINE        GCYL
C              SUBROUTINE        GPLANE
C              SUBROUTINE        GQUAD
C              SUBROUTINE        GSPHER
C              SUBROUTINE        TRANSF
C
C RESTRICTIONS NONE
C
C DIAGNOSTICS  NONE
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
C
      SUBROUTINE GSURF(COEBUF,CANON,MODE,ISIZ,ERRFLG)
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      LOGICAL ERRFLG
      DIMENSION COEBUF(10),CANON(10),REFSRF(10)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'KNUMBR.INC'
C
C
      DO 5 I=1,ISIZ
    5 REFSRF(I) = CANON(I)
      ERRFLG = .FALSE.
C
C      MODE = 1   2   3   4   5   6   7   8   9 10  11  12  13  14  15
      GO TO(101,101,103,104,105,106,106,106,109,106,130,130,130,106,130,
C      MODE = 16 17  18  19  20  21  22  23  24  25  26
     1      130,130,130,130,130,130,130,130,130,130,130), MODE
C
C...  A LINE OR PLANE.
C
   10 CALL GPLANE (REFSRF, COEBUF)
      GO TO 100
C
C...  A CYLINDER.
C
   30 CALL GCYL (REFSRF, COEBUF)
      GO TO 100
C
C...  A CIRCLE.
C
   40 CALL GCIRCL (REFSRF, COEBUF)
      GO TO 100
C
C...  A SPHERE.
C
   50 CALL GSPHER (REFSRF, COEBUF)
      GO TO 100
C
C...  A HYPERBOLA, LCONIC, ELLIPSE, GCONIC, OR QUADRIC.
C
   60 CALL GQUAD (REFSRF, COEBUF)
      GO TO 100
C
C...  A CONE.
C
   90 CALL GCONE (REFSRF, COEBUF)
  100 RETURN
C
C...  TRANSFORM TO LOCAL COORDINATE SYSTEM IF REFSYS IN EFFECT.
C
  101 IR = K4
      ASSIGN 10 TO M
      GO TO 110
  103 IR = K5
      ASSIGN 30 TO M
      GO TO 110
  104 IR = K5
      ASSIGN 40 TO M
      GO TO 110
  105 IR = K2
        ASSIGN 50 TO M
      GO TO 110
  106 IR = K1
      ASSIGN 60 TO M
      GO TO 110
  109 IR = K5
      ASSIGN 90 TO M
  110 IF(REFFLG) CALL TRANSF(REFSRF,CANON,IR,ISIZ,K0)
      GO TO M,(10,30,40,50,60,90)
C
  130 ERRFLG = .TRUE.
      GO TO 100
      END
