**** SOURCE FILE : M0006685.V01   ***
*
C
C              FORTRAN SUBROUTINE SETCHR
C
C LINKAGE      SUBROUTINE SETCHR(PNTR,CLASS)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    KONAST
C                                        SUBROUTINE    LOOP
C                                        SUBROUTINE    VCTPRD
C
      SUBROUTINE SETCHR(PNTR,CLASS)
C
      IMPLICIT INTEGER (A-Z)
C
C        2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST
      DIMENSION STKLST(300),STACK(2,99)
C STACK:       WORKING STACK
      EQUIVALENCE (STACK(1,1),STKLST(4))
C
C        4.    PRODUCTION TABLE
C
      COMMON/SRCTBL/SRCTBL
      DIMENSION SRCTBL(502),META(50)
C META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES
      EQUIVALENCE (META(1),SRCTBL(3))
C
C       29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULI
      DIMENSION MODULI(2)
C MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS
      EQUIVALENCE (MODULO,MODULI(1))
C*
C ARGUMENTS    PNTR      STACK INDEX OF ENTRY
C              CLASS     TWO ELEMENT ARRAY WHERE CLASS(2)
C                        CONTAINS NAME TABLE (NAMTBL) INDEX OF
C                        DESIRED META-CHARACTER.
C     CHANGE A CHARACTER
C**
      DIMENSION CLASS(2)
      STACK(1,PNTR)=CLASS(2)
      I = CLASS(1)/MODULO
      STACK(2,PNTR) = META(I)
      RETURN
       END
