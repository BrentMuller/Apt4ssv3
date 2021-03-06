**** SOURCE FILE : MINF0000.ORG   ***
*
      SUBROUTINE MINF(PTABLE)
*
*  * MINF *   VAX11 FORTRAN VERSION  29.8.86  E.MCLELLAN
*
*  PURPOSE    TO FIND THE MINIMUM VALUE OF ITEMS IN UNLABELLED
*             COMMON REFERENCED BY THE PARAMETER LIST
*  CALLING SEQUENCE
*             CALL MINF(PTABLE)
*  ARGUMENTS
*             PTABLE    PARAMETER LIST
*
C      UNLABELED COMMON
C
      INCLUDE 'BLANKCOM.INC'
C
      DIMENSION PTABLE(50)
      DOUBLE PRECISION RESULT
      INTEGER PTABLE,TERM
C
      DATA TERM/-999/
C
C
      RESULT=COM(PTABLE(3))
      I=4
   10 IF (COM(PTABLE(I)).LT.RESULT)RESULT=COM(PTABLE(I))
      I=I+1
      IF (PTABLE(I).NE.TERM) GOTO 10
      COM(PTABLE(2))=RESULT
      RETURN
      END
C
C
C
      SUBROUTINE MAXF(PTABLE)
*
*  * MAXF *   VAX11 FORTRAN VERSION  29.8.86  E.MCLELLAN
*
*  PURPOSE    TO FIND THE MAXIMUM VALUE OF ITEMS IN UNLABELLED
*             COMMON REFERENCED BY THE PARAMETER LIST
*  CALLING SEQUENCE
*             CALL MAXF(PTABLE)
*  ARGUMENTS
*             PTABLE    PARAMETER LIST
*
C      UNLABELED COMMON
C
      INCLUDE 'BLANKCOM.INC'
C
      DIMENSION PTABLE(50)
      DOUBLE PRECISION RESULT
      INTEGER PTABLE,TERM
C
      DATA TERM/-999/
C
C
      RESULT=COM(PTABLE(3))
      I=4
   20 IF (COM(PTABLE(I)).GT.RESULT)RESULT=COM(PTABLE(I))
      I=I+1
      IF (PTABLE(I).NE.TERM) GOTO 20
      COM(PTABLE(2))=RESULT
      RETURN
      END
