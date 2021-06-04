**** SOURCE FILE : M0006629.V01   ***
*
C
C              FORTRAN SUBROUTINE KONAST
C
C LINKAGE      SUBROUTINE  KONAST(TENPT)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    SETCHR          SUBROUTINE    RECOG
C
      SUBROUTINE  KONAST(TENPT)
C
      IMPLICIT INTEGER (A-Z)
C
C        2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST
      DIMENSION STKLST(300),STACK(2,99)
C TOP:         POINTER TO LAST STACK ENTRY
      EQUIVALENCE (TOP,STKLST(1))
C STACK:       WORKING STACK
      EQUIVALENCE (STACK(1,1),STKLST(4))
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),ASTER(2),NUMBER(2),DBLAST(2)
C ASTER:       (1)=CODE CLASS  9000,(2)=NAMTBL INDEX OF '*     '
      EQUIVALENCE (ASTER(1),CODE(17))
C NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER'
      EQUIVALENCE (NUMBER(1),CODE(27))
C DBLAST:      (1)=CODE CLASS 32000,(2)=NAMTBL INDEX OF 'DBLAST'
      EQUIVALENCE (DBLAST(1),CODE(63))
C**
      TOP=TOP+2
      STACK(1,TOP)=STACK(1,TOP-2)
      STACK(2,TOP)=STACK(2,TOP-2)
      STACK(1,TOP-1)=STACK(1,TOP-3)
      STACK(2,TOP-1)=STACK(2,TOP-3)
      CALL SETCHR(TOP-2,DBLAST)
      CALL SETCHR(TOP-3,NUMBER)
      STACK(1,TOP-3)=TENPT
      CALL SETCHR(TOP-4,ASTER)
C
      RETURN
      END
