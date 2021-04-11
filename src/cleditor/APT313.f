**** SOURCE FILE : M0000429.V03   ***
*
C
C.....FORTRAN SUBROUTINE              APT313                12/67
C PURPOSE      TO TERMINATE WRITING OF CLFILE AT THE END OF
C              THE DATA ON CLFILE.
C LINKAGE      CALL APT313
C ARGUMENTS    NONE
C SUBSIDIARIES NONE
      SUBROUTINE APT313
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C...            SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
C
C       THIS ROUTINE TERMINATES WRITING OF CLFILE
C
      CALL TAPOP (CLFILE,-2)
C     ENDFILE
C     REWIND CLFILE
      RETURN
      END