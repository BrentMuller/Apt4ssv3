**** SOURCE FILE : M0006684.V01   ***
*
C
C              FORTRAN SUBROUTINE SETBIT
C
C LINKAGE      SUBROUTINE SETBIT (WORD,N)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C                                        SUBROUTINE    MATCH
C
      SUBROUTINE SETBIT (WORD,N)
C
      IMPLICIT INTEGER (A-Z)
C
C       32.    COMMON BLOCK FOR SETBIT AND BITMCH
C              CONTAINS ONE WORD FOR EACH BIT WITH ONLY THAT BIT SET
      COMMON/BITCOM/BIT
      DIMENSION BIT(32)
C*
C ARGUMENTS    WORD    CELL WHOSE BIT POSITION IS REFERENCED
C              N       BIT POSITION OF WORD TO BE SET
      REAL WORD,WORDR,ALLBIT
      LOGICAL WORDL,BIT
      EQUIVALENCE (WORDR,WORDL)
C**
      WORDR=WORD
      WORDL=WORDL.OR.BIT(N+1)
      WORD=WORDR
      GOTO 1040
 1040 RETURN
       END