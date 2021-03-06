**** SOURCE FILE : M0000797.V03   ***
*
C
C.....FORTRAN SUBROUTINE             APT047...              6/10/68 EAN
C
C              FORTRAN SUBROUTINE APT047
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE DEFINED
C              AS PARALLEL TO A GIVEN PLANE AND OFFSET A GIVEN
C              DISTANCE BY THE FOLLOWING APT STATEMENT
C              RESULT = PLANE/PARLEL, P1, ****, D,
C                **** = XLARGE, YLARGE, ZLARGE, XSMALL, YSMALL,
C                       OR ZSMALL
C
C LINKAGE      CALL APT047 (RESULT, PL, MN, D)
C
C ARGUMENT     RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING PLANE
C              PL      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT PLANE
C              MN      INTEGER EQUIVALENT OF THE MODIFIER
C                      1 = XLARGE, 2 = YLARGE, 3 = ZLARGE,
C                      4 = XSMALL, 5 = YSMALL, 6 = XSMALL
C              D       REAL VARIABLE CONTAINING THE VALUE OF
C                      OFFSET DISTANCE
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          DEFEXT
C              REAL FUNCTION       FLOAT
C              REMAINDERING FUNCTION MOD
C              REAL FUNCTION       SIGN
C              LOGICAL FUNCTION    XVECT
C
      SUBROUTINE APT047 (RESULT,PL,MN,D)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4), PL(4)
      LOGICAL ZVECT
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
      EQUIVALENCE (S1,SC(1))
C
C...     TRANSFORM CANONICAL FORM TO LOCAL COORDINATE SYSTEM
C
      DATA ZLIT1,K59/3.5D0,59/
      CALL APT077(PL,0)
      IF (UNFLAG) GO TO 50
      UNFLAG =.NOT.ZVECT(L)
C
C...     CHECK WHICH SIDE NEW PLANE IS ON
C
      I= MOD(MN -K1,K3)
      DO 20 K=1,3
      DUMMY1 = MN
      S1 = L(I+1)*(ZLIT1-DUMMY1)
      IF (S1.NE.Z0) GO TO 30
C
C...     UNABLE TO DISTINGUISH PLANE, TRY NEXT DIMENSION
C
      I =MOD(I+K1,K3)
   20 IERROR = K59
C
C...     FORM DESIRED PLANE
C
   30 L(4)=L(4)+D*DSIGN(1.0D0,S1)
      CALL APT077 (L,KM1)
   40 CALL DEFEXT (RESULT)
      RETURN
   50 IERROR=K1
      GO TO 40
       END
