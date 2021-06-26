**** SOURCE FILE : M0002832.V06   ***
*
C
C.....FORTRAN SUBROUTINE             DEFEXT...              3/1/68   GK
C
C              FORTRAN SUBROUTINE DEFEXT
C
C PURPOSE      TO PROVIDE A COMMON EXIT TO THE DEFINITION
C              REDUCTION SUBROUTINES, TO MOVE THE RESULTANT
C              CANONICAL FORM INTO THE RESULT CELLS, PRINT
C              ERROR MESSAGES, PRINT THE CANONICAL FORM
C              IF THE APPROPRIATE PRINT COMMAND IS IN
C              EFFECT AND TO RESTORE THE ARRAY R TO ITS
C              INITIAL VALUE.
C
C LINKAGE      CALL DEFEXT (RESULT)
C
C ARGUMENTS    RESULT  AN ARRAY TO CONTAIN THE RESULTANT
C                      CANONICAL FORM
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          ERROR
C              SUBROUTINE          PRINT
C              SUBROUTINE          UNDEF
C              SUBROUTINE          UNPACK
C
      SUBROUTINE DEFEXT (RESULT)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(*)
      INTEGER INAM(37,2)
      CHARACTER*8  RNAME, RNAM(22)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'ISHR16.INC'
C
      DATA INAM / 4, 6,15,16,18,19,23,24,25,27,
     1                    29,37,38,43,44,47,48,51,57,58,
     2                    59,69,70,73,74,75,76,77,79,93,
     3 5153,5154,5155,5156,5157,5158,5159,
     4                     1, 2, 3, 3, 4, 5, 6, 6, 6, 7,
     5                     8, 9, 9,10,11,12,13,14,15,16,
     6                    10,17,17,18,18,18,18,21,21,19,
     6   20,  20,  20,  20,  20,  20,  20/
      DATA RNAM
     1 /'APT003  ','APT004  ','APT008  ','APT009  ','APT012  ',
     2  'APT016  ','APT023  ','APT027  ','APT106  ','APT013  ',
     3  'APT044  ','APT059  ','APT056  ','APT073  ','APT053  ',
     4  'APT055  ','APT074  ','APT070  ','APT105  ','APT109  ',
     5  'APT034  ','DEFEXT??'/
C IMAX: ANZAHL FEHLERNUMMERN, MAX: ANZAHL ROUTINENEN-NAMEN + 1 '??'
      DATA IMAX /37/, MAX /22/
C
C
C...     CHECK FOR ERRORS
C
      IF (IERROR.EQ.0) GO TO 20
      DO 810 I=1,IMAX
      IN=MAX
      IF (IERROR.NE.INAM(I,1))GOTO 810
      IN=INAM(I,2)
      GOTO 820
  810 CONTINUE
  820 RNAME=RNAM(IN)
      CALL ERROR (IERROR,RNAME)
   10 CALL UNDEF (RESULT)
      UNFLAG=.FALSE.
      GO TO 40
C
   20 IF (UNFLAG) GO TO 10
C
C...     DEFINITION OK -- CHECK INTFLG, PRNTON AND MOVE R TO RESULT
C
      CALL UNPACK (RESULT,IS1,IS2,IS3)
C   MATRIX ?
      IF(IS1.EQ.18)GOTO 31
      DO 30 I=1,IS2
   30 RESULT(I)=R(I)
   31 IF(.NOT.PRNTON)GO TO 40
      IF((IS1.GT.0).AND.(IS1.LT.27))CALL PRINT(3,RESULT,1)
   40 IERROR = 0
      DO 41 I = 1,10
   41 R(I) = 0.
      R(6) = 1.
       RETURN
       END