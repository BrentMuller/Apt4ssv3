**** SOURCE FILE : M0006622.V01   ***
*
C
C              FORTRAN SUBROUTINE CALLZZ
C
C LINKAGE      SUBROUTINE CALLZZ(INDEX)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ONEARG          SUBROUTINE    BOOLIF
C          SUBROUTINE    OPCODE          SUBROUTINE    COMSTR
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    GOPAT
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REFGEN
C                                        SUBROUTINE    REFREF
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE CALLZZ(INDEX)
C
      IMPLICIT INTEGER (A-Z)
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C CALL:        CONTAINS COMMAND CODE (18) FOR CALL COMMAND
      EQUIVALENCE (CALL,IL(18))
C*
C PURPOSE      TO GENERATE THE I.L. FOR A CALL OPCODE AND
C              THE PROCEDURE INDEX.
C
C ARGUMENTS    INDEX  NAME TABLE (NAMTBL) INDEX OF THE PROCEDURE NAME.
C**
C...     GENERATE CALL OPCODE, AND FIRST ARGUMENT (PROCEDURE INDEX)
C
      CALL OPCODE(CALL)
      CALL ONEARG(INDEX)
      RETURN
       END
