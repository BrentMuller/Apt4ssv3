**** SOURCE FILE : M0000422.V02   ***
*
C
C......    FORTRAN SUBROUTINE APT305    11/69    RC
C PURPOSE      TO GENERATE THE TRANSFORMATION MATRIX, TMATRX.
C LINKAGE      CALL APT305
C ARGUMENTS    NONE
C SUBSIDIARIES APT306, APT308
      SUBROUTINE APT305
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C      THIS SUBROUTINE GENERATES TMATRX FROM AMTTAB AND TRAMAT
C      DEPENDING ON COPY LEVEL (ICOPY) AND TRACUT (ITRAFL)
C
C      MLTFLG DETERMINES MATRIX MULTIPLICATION ORDER 1=POINT 0=PATTERN
C
C
      COMMON /EDITOR/EDITOR/KFLAGS/KFLAGS
      DIMENSION EDITOR(1500),KFLAGS(5),AMTTAB(4,4,3)
      EQUIVALENCE  (EDITOR( 595),ICOPY) , (EDITOR(985),TMATRX),
     1             (EDITOR(1022),TRAMAT), (EDITOR(375),MLTFLG),
     2             (EDITOR( 287),AMTTAB(1,1,1)), (KFLAGS(5),ITRAFL)
C
      IF (ICOPY.EQ.0) GO TO 90
      IF (MLTFLG.EQ.0) GO TO 40
      GO TO (10,20,30),ICOPY
   10 CALL APT308 (TMATRX,AMTTAB(1,1,1))
      GO TO 80
   20 CALL APT306 (TMATRX,AMTTAB(1,1,2),AMTTAB(1,1,1))
      GO TO 80
   30 CALL APT306 (TMATRX,AMTTAB(1,1,2),AMTTAB(1,1,1))
      CALL APT306 (TMATRX,AMTTAB(1,1,3),TMATRX)
      GO TO 80
   40 GO TO (50,60,70),ICOPY
   50 CALL APT308 (TMATRX,AMTTAB(1,1,1))
      GO TO 80
   60 CALL APT306 (TMATRX,AMTTAB(1,1,1),AMTTAB(1,1,2))
      GO TO 80
   70 CALL APT306 (TMATRX,AMTTAB(1,1,1),AMTTAB(1,1,2))
      CALL APT306 (TMATRX,TMATRX,AMTTAB(1,1,3))
C
C...     CHECK FOR TRACUT MODIFICATION OF COPY MATRIX
   80 IF (ITRAFL .EQ. 0) GO TO 100
      CALL APT306(TMATRX,TMATRX,TRAMAT)
      GO TO 100
C
C...     CHECK FOR A TRACUT TRANSFORMATION ONLY
C
   90 IF (ITRAFL .EQ. 0) GO TO 100
      CALL APT308 (TMATRX,TRAMAT)
C
  100 CONTINUE
      RETURN
      END
