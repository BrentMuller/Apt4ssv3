**** SOURCE FILE : M0006670.V03   ***
*
C
C              FORTRAN SUBROUTINE PUTTMP
C
C LINKAGE      SUBROUTINE PUTTMP(MODE)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    BINBCD          SUBROUTINE    BOOLIF
C          SUBROUTINE    FOUTXX          SUBROUTINE    INPAT
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C
      SUBROUTINE PUTTMP(MODE)
C
      IMPLICIT INTEGER (A-Z)
C
C        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE
      COMMON/TMP/TXXXX
      DIMENSION TXXXX(2,32)
C
C       33.    SYMBOLIC FILE DEFINITIONS
C
      INCLUDE 'SYMFIL.INC'
C ELFIL1:      OUTPUT OF PACKING FACTOR FOR CREATING PAGES (INTERPRETER)
C*
C ARGUMENT     MODE      MODE OF TEMPORARY STORAGE NAME TO BE RELEASED
C
      CHARACTER INAM*24
      DATA INAM/' PUTTMP ERROR   '/
C**
      IF (TXXXX(2,MODE) .EQ. 0)    GO  TO  999
      TXXXX(2,MODE) = TXXXX(2,MODE)-1
      RETURN
C
C     ERROR
  999 CALL BINBCD(MODE,INAM(17:),I)
      CALL FOUTXX (ELFIL1,INAM,24)
      RETURN
       END
