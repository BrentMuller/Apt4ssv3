**** SOURCE FILE : M0006646.V01   ***
*
C
C              FORTRAN SUBROUTINE LABELZ
C
C LINKAGE      SUBROUTINE LABELZ(INDEX)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ONEARG          SUBROUTINE    BOOLIF
C          SUBROUTINE    OPCODE          SUBROUTINE    COMSTR
C          SUBROUTINE    RLSLIN          SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MATCH
C                                        SUBROUTINE    RECOG
C
      SUBROUTINE LABELZ(INDEX)
C
      IMPLICIT INTEGER (A-Z)
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C LABELX:      CONTAINS COMMAND CODE ( 6) FOR LABEL COMMAND
      EQUIVALENCE (LABELX,IL(6))
C*
C PURPOSE      TO GENERATE AND OUTPUT TO THE I.L. RECORD IMAGE
C              (ILFILE) THE LABEL I.L. COMMAND.
C
C ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF LABEL.
C**
      CALL OPCODE(LABELX)
      CALL ONEARG(INDEX)
      CALL RLSLIN
      RETURN
       END