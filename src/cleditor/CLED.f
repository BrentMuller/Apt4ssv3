**** SOURCE FILE : M0000444.V04   ***
*
C
C....FORTRAN SUBROUTINE  ...CLED...       11/69                  HG
      SUBROUTINE CLED
C
C         PURPOSE           ...TO CALL APT301
C
C         CALLING SEQUENCE  ...THIS IS THE MAIN PROGRAM OF THE CLEDITOR
C
C         ARGUMENTS         ...NONE
C
C         CALLED BY         ...NONE
C
C         SUBSIDIARIES      ...TYPE...      ...ENTRY...
C
C                           SUBROUTINE         APT301
C
C         RESTRICTIONS      ...NONE
C
C         DIAGNOSTICS       ...NONE
C....
C
C
C
C...      32.  PARAMETERS REQUIRED BY SUPERVISOR
C
      INCLUDE 'SUPER.INC'
C
C
      INCLUDE 'SYMFIL.INC'
      CALL  APT301
C....    INDICATE NORMAL ENDING
      ABEND=.FALSE.
C
      RETURN
      END
