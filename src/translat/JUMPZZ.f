**** SOURCE FILE : M0006644.V01   ***
*
C
C              FORTRAN SUBROUTINE JUMPZZ
C
C LINKAGE      SUBROUTINE JUMPZZ(INDEX)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ONEARG          SUBROUTINE    COMSTR
C          SUBROUTINE    OPCODE          SUBROUTINE    PRO026
C          SUBROUTINE    RLSLIN
C
      SUBROUTINE JUMPZZ(INDEX)
C
      IMPLICIT INTEGER (A-Z)
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C JUMP:        CONTAINS COMMAND CODE ( 8) FOR JUMP COMMAND
      EQUIVALENCE (JUMP,IL(8))
C*
C PURPOSE      TO GENERATE  AND OUTPUT TO THE I.L. INTERNAL
C              RECORD IMAGE (ILFILE) THE JUMP I.L. COMMAND.
C
C ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF A LABEL.
C**
C...     GENERATE I.L. FOR JUMP COMMAND.
C
      CALL OPCODE(JUMP)
      CALL ONEARG(INDEX)
      CALL RLSLIN
      RETURN
       END
