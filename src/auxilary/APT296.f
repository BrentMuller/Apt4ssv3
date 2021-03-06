**** SOURCE FILE : M0000706.W01   ***
*
      SUBROUTINE APT296
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'IFXCOR.INC'
C
C...            SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
      DIMENSION KHOLDP(8)
      LOGICAL FIRST
      INTEGER Z4E,BCDF
      PARAMETER (Z4E=1308622848)
      SAVE IFIRST,KHOLDP
      DATA KHOLDP/0,0,Z4E,0,Z4E,1,Z4E,3/
      DATA FIRST/.TRUE./
C
C     THIS SUBROUTINE WRITES THE HOLDPP
C      RECORD ON EXFILE AT THE BEGINNING OF MACRO OUT PUT
C
      IF (FIRST) THEN
        KHOLDP(1)=BCDF('HOLD')
        KHOLDP(2)=BCDF('PP  ')
        FIRST=.FALSE.
      ENDIF
      CALL RECORD(KHOLDP(4))
      NR=0
      CALL EWRITE(EXFILE,NR,KHOLDP,8,IR)
      RETURN
      END
C
C---    APT297 ENTERED TO WRITE END RECORD FOR MACRO ON EXFILE
      SUBROUTINE APT297
C
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'IFXCOR.INC'
                          
C...            SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
      DIMENSION KHOLDP(8)
      LOGICAL FIRST
      INTEGER Z4E,BCDF
      PARAMETER (Z4E=1308622848)
      SAVE IFIRST,KHOLDP
      DATA KHOLDP/0,0,Z4E,0,Z4E,1,Z4E,4/
      DATA FIRST/.TRUE./
C
C     THIS SUBROUTINE WRITES THE HOLDPP
C      RECORD ON EXFILE AT THE BEGINNING OF MACRO OUT PUT
C
      IF (FIRST) THEN
        KHOLDP(1)=BCDF('HOLD')
        KHOLDP(2)=BCDF('PP  ')
        FIRST=.FALSE.
      ENDIF
      CALL RECORD(KHOLDP(4))
      NR=0
      CALL EWRITE(EXFILE,NR,KHOLDP,8,IR)
      RETURN
      END
