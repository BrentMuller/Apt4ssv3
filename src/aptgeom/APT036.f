**** SOURCE FILE : M0000786.V03   ***
*
C
C.....FORTRAN SUBROUTINE              APT036                12/67
C
C              FORTRAN SUBROUTINE APT036
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR DEFINED
C              AS PERPENDICULAR TO A GIVEN PLANE BY THE FOLLOWING
C              APT STATEMENT
C              RESULT = VECTOR/PERPTO, PLN, ****
C                **** = POSX, POSY, POSZ, NEGX, NEGY, OR NEGZ
C
C LINKAGE      CALL APT036 (RESULT, PLN, MN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING VECTOR
C              PLN     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT PLANE
C              MN      INTEGER EQUIVALENT OF THE MODIFIER
C                      1 = POSX  2 = POSY  3 = POSZ
C                      4 = NEGX  5 = NEGY  6 = NEGZ
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          APT078
C              SUBROUTINE          DEFEXT
C              REMAINDERING FUNCTION MOD
C              REAL FUNCTION       SIGN
C              REAL FUNCTION       FLOAT
C
      SUBROUTINE APT036 (RESULT,PLN,MN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(3),PLN(4)
      EQUIVALENCE (S1,SC(1))
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
C
      DATA ZLIT1/3.5D0/
C
C...     TRANFORM CANONICAL FORM, CHECK VALIDITY
C
      CALL APT077(PLN,0)
      I = K1+ MOD(MN -K1,K3)
      DUMMY1 = MN
      S1 = DSIGN(Z1,L(I)*(ZLIT1-DUMMY1))
C
C...     IF NORMAL TO PLN HAS WRONG ORIENTATION,REVERSE DIRECTION
C
      DO 10 J=1,3
   10 L(J)=S1*L(J)
      CALL APT078(L,KM1)
      CALL DEFEXT(RESULT)
      RETURN
       END