**** SOURCE FILE : M0006630.V01   ***
*
C
C              FORTRAN SUBROUTINE EPILOG
C
C LINKAGE      SUBROUTINE EPILOG
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    IEPLOG          SUBROUTINE    MACREC
C          SUBROUTINE    LIBOPC          SUBROUTINE    PRO026
C
      SUBROUTINE EPILOG
C
      IMPLICIT INTEGER (A-Z)
C
C       14.    I. L. LIST OPTION FLAGS
C
      COMMON/PRT/PRT
      LOGICAL INTERP,ASSEMB
      DIMENSION PRT(7)
C INTERP:      NORMALLY TRUE,INDICATING INTERPRETIVE APPROACH DEFAULT
      EQUIVALENCE (INTERP,PRT(3))
C ASSEMB:      SET TRUE INDICATES ASSEMBLY APPROACH (CONTRL/ASMBLE)
      EQUIVALENCE (ASSEMB,PRT(4))
C
C       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES
C
      COMMON/MACSEG/MACSEG
      LOGICAL ALOPN
      DIMENSION MACSEG(6)
C ALOPN:       TRUE AFTER MACRO OR PART PROGRAM SEGMENT LIBRARY OPENED
      EQUIVALENCE (ALOPN,MACSEG(1))
C**
C     IF(ASSEMB)CALL AEPLOG
      IF (INTERP) CALL IEPLOG
C...      TERMINATE TRANSLATION
      ASSEMB = .FALSE.
      INTERP = .FALSE.
      IF(ALOPN)CALL LIBOPC(2,IFLAG)
      RETURN
       END
