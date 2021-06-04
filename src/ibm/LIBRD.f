**** SOURCE FILE : LIBRD000.IBM;1   ***
*
      SUBROUTINE LIBRD(MEMBER,FLAG,ARRAY)
*
*  * LIBRD *  VAX-11 FORTRAN 77 VERSION  28.09.82  E.MCLELLAN
*                              MODIFIED  26.09.86
*                MODIFIED                25-FEB-1988  E.MCLELLAN
*
*  PURPOSE    TO READ A RECORD (80 CHARACTERS) FROM THE GIVEN
*             MEMBER FILE OF [.APTLIB]
*  CALLING SEQUENCE
*             CALL LIBRD(MEMBER,FLAG,ARRAY)
*  ARGUMENTS
*             MEMBER    CHARACTER STRING CONTAINING THE
*                       MEMBER NAME (BCD LEFT JUSTIFIED)
*             FLAG      INTEGER SET BY LIBRD
*                       0 = SUCCESSFUL READ
*                       1 = END OF DATA ENCOUNTERED (EOF)
*                       2 = I/O ERROR
*                       3 = NOT USED
*                       4 = A DIFFERENT MEMBER NAME APPEARED WITHOUT
*                           CALLING LIBSCH OR BEFORE END OF DATA
*                           ENCOUNTERED
*             ARRAY     CHARACTER STRING TO CONTAIN A RETRIEVED RECORD
*
      CHARACTER MEMBER*(*),ARRAY*80,TEST*8
      INTEGER FLAG
C
      INCLUDE 'FILTAB.INC'
C
      CHARACTER*8 MEMNAM
      COMMON/CLIBCM/MEMNAM
      COMMON/LIBCOM/IEOF
C
      TEST=MEMBER//' '
C
C.....IS MEMBER NAME SAME AS IN LAST CALL TO LIBSCH
C
      IF (TEST.NE.MEMNAM) THEN
         FLAG=4
         RETURN
      ELSE
C.....YES - READ A RECORD FROM MEMBER FILE
         ID=U(24)
         READ (UNIT=ID,FMT='(A80)',ERR=80,END=90) ARRAY
         FLAG=0
         RETURN
C
C.....I/O ERROR
   80    FLAG=2
c         CALL UCLOSE(ID,2,JRET)
      write(*,*)'TODO: uclose command-LIBRD.f'
         RETURN
C
C.....EOF ENCOUNTERED
   90    FLAG=1
         IEOF=1
c         CALL UCLOSE(ID,2,JRET)
      write(*,*)'TODO: uclose command-LIBRD.f'
         RETURN
      END IF
      END
