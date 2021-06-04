**** SOURCE FILE : M0006632.V02   ***
*
C
C              FORTRAN SUBROUTINE FOUTXX
C
C LINKAGE      SUBROUTINE FOUTXX (IFILE,ARRAY,COUNT)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    CPRINT          SUBROUTINE    ALARM
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    PRTIL
C                                        SUBROUTINE    PUTTMP
C                                        SUBROUTINE    RLSLIN
C                                        SUBROUTINE    START
C
      SUBROUTINE FOUTXX (IFILE,ARRAY,COUNT)
C
      IMPLICIT INTEGER (A-Z)
C
C       20.    IO - ARRAY
C
      INCLUDE 'DARRAY.INC'
      CHARACTER*(*) ARRAY
C**
      DARRAY(1:COUNT)=ARRAY(1:COUNT)
      CALL CPRINT (DARRAY)
      RETURN
      END
