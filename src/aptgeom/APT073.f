**** SOURCE FILE : M0000823.V02   ***
*
C.....FORTRAN SUBROUTINE             APT073...              3/1/68   GK
C                                                6/70      RW
C              FORTRAN SUBROUTINE APT073
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE DEFINED
C              AS CONTAINING TWO NON-PARALLEL VECTORS AND A POINT.
C
C LINKAGE      CALL APT073 (RESULT, VT1, VT2, PT)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING PLANE
C              VT1     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE FIRST INPUT VECTOR
C              VT2     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE SECOND INPUT VECTOR
C              PT      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          CKDEF
C              SUBROUTINE          CROSS
C              SUBROUTINE          DOTF
C              LOGICAL FUNCTION    VNORM
C              LOGICAL FUNCTION    ZVECT
C
      SUBROUTINE APT073 (RESULT,VT1,VT2,PT)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4),VT1(3),VT2(3),PT(3)
      LOGICAL CKDEF,ZVECT
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
      UNFLAG = UNFLAG .OR. CKDEF(PT)
C
C...     CALCULATE VECTOR PERPENDICULAR TO VT1, VT2
C
      CALL CROSS(VT1,VT2,V)
      IF (.NOT.ZVECT(V)) IERROR=K51
      CALL VNORM(V,RESULT)
C
C...     DISTANCE TO PLANE IS DOT PRODUCT OF PT VECTOR AND UNIT NORMAL
C
      CALL DOTF(RESULT(4),RESULT,PT)
      RETURN
       END
