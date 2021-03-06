**** SOURCE FILE : M0002234.V05   ***
*
C
C.....FORTRAN SUBROUTINE             APT059...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT059
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF AN ELLIPSE OR
C              HYPERBOLA, GIVEN THE CENTER, ROTATION ANGLE,
C              AND MAJOR AND MINOR AXIS.
C
C LINKAGE      CALL APT059 (RESULT, PN, MA, MI, BETA, SGN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE SECOND DEGREE EQUATION
C              PN      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE CENTER POINT
C              MA      REAL VARIABLE CONTAINING THE LENGTH OF
C                      THE SEMI-MAJOR AXIS
C              MI      REAL VARIABLE CONTAINING THE LENGTH
C                      OF THE SEMI-MINOR AXIS
C              BETA    REAL VARIABLE CONTAINING THE VALUE OF
C                      THE ANGLE BETWEEN THE MAJOR AXIS AND THE
C                      X-AXIS
C              SGN     REAL VARIABLE CONTAINING THE SURFACE
C                      INDICATOR
C                           1 = ELLIPSE;   -1 = HYPERBOLA
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT079
C              SUBROUTINE          APT081
C              SUBROUTINE          DEFEXT
C              REAL FUNCTION       COS
C              REAL FUNCTION       SIN
C
      SUBROUTINE APT059 (RESULT,PN,MA,MI,BETA,SGN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10),PN(3)
      DOUBLE PRECISION MA,MI
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      EQUIVALENCE (S1,SC(1)),(S2,SC(2)),(S3,SC(3)),(S4,SC(4)),
     1            (S5,SC(5)),(S6,SC(6)),(S7,SC(7))
C
C
C...     TRANSFORM POINT TO LOCAL SYSTEM, CHECK VALIDITY
C
      CALL APT081(PN,K0)
      IF(MA.GT.MI) GO TO 10
      CALL ERROR(40,'APT059  ')
      SWOP=MA
      MA=MI
      MI=SWOP
      BETA=BETA+90
   10 S1=BETA*DEGRAD
      S2=DSIN(S1)
      S3=DCOS(S1)
      S4=S2**2
      S5=S3**2
      S6=SGN*MA**2
      S7=MI**2
      R(1)=S7*S5+S6*S4
      R(2)=S7*S4+S6*S5
      R(4)=S7*(P(1)*S3+P(2)*S2)**2
     1     +S6*(P(1)*S2-P(2)*S3)**2-S7*MA**2
      R(6)=Z0
      R(7)=S2*S3*(S7-S6)
      R(8)=-P(2)*R(7)-P(1)*R(1)
      R(9)=-P(1)*R(7)-P(2)*R(2)
      CALL APT079(R,KM1)
      CALL DEFEXT(RESULT)
      RETURN
       END
