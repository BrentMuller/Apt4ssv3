**** SOURCE FILE : PUNIDN00.V01   ***
*
      SUBROUTINE PUNIDN(A)
*
*  * PUNIDN *  VAX-11 FORTRAN 77 VERSION  21.10.82  E.MCLELLAN
*
*  PURPOSE     TO SET UP CARD IDENTIFICATION AND SEQUENCE NUMBERS
*
*  CALLING SEQUENCE
*              CALL PUNIDN(A)
*  ARGUMENTS
*             A  ADDRESS FIELD OF 4 BCD CHARACTERS
*  ALTERNATE ENTRIES
*             CALL PUNSEQ(B)
*             B  START SEQUENCE NUMBER TO BE PUNCHED - REAL*4
*
*             CALL PUNNUM(C)
*             C  LATEST SEQUENCE NUMBER BEING PUNCHED - REAL*4
*
      COMMON/PUN/PNID,PNO
C
      PNID=A
      RETURN
C
      ENTRY PUNSEQ(B)
      PNO=B
      RETURN
C
      ENTRY PUNNUM(C)
      C=PNO
      RETURN
      END
