**** SOURCE FILE : PUNCHC00.IBM;1   ***
*
      SUBROUTINE PUNCHC(N,A,J,K)
*
*  * PUNCHC *   VAX-11 FORTRAN 77 VERSION 29.11.82 E.MCLELLAN
*               REVISED FOR CHARACTER HANDLING 5.9.85 E.MCL.
*
*  PURPOSE     TO GENERATE REQUIRED PAPER TAPE CODES FOR CHARACTERS
*
*  CALLING SEQUENCE
*              CALL PUNCHC(N,A,J,K)
*  ARGUMENTS
*              N NUMBER OF CHARACTERS IN A
*              A CHARACTER STRING TO BE PUNCHED
*              J NUMBER OF CHARACTERS PUNCHED
*              K -2  BLANKS AND PERIODS IGNORED
*                -1  PERIODS IGNORED
*                 0  BLANKS IGNORED
*                >0  BLANKS ARE PROCESSED
*
*  ALTERNATE ENTRY
*              CALL PUNCHD(N,A,J,K)
*
C
C...LOGICAL*1 VARIABLES IN THIS IBM IMPLEMENTATION MIGHT BE ABLE TO BE
C...BYTE VARIABLES ON OTHER SYSTEMS E.G. VAX
C
      COMMON/PUNTAB/PUNCOD
c      LOGICAL*1 PUNCOD(128),ILEGAL
      integer*2 puncod(128),ilegal
*
      CHARACTER*512 A
      CHARACTER*512 INFIL,OUTFIL
c      LOGICAL*1 PUNOUT(512)
      integer*2 punout(512)
      LOGICAL OD
C
      INCLUDE 'DARRAY.INC'
C
c      DATA ILEGAL/ZEE/
      data ilegal/238/
C
C
      ENTRY PUNCHD(N,A,J,K)
C
      INFIL=A
C
      M=N
C
      IF (K.LE.0) THEN
         L=1
         DO 10 I=1,N
           IF ((INFIL(I:I).EQ.' ').AND.((K.EQ.0).OR.(K.EQ.-2))) THEN
              GO TO 10
           ELSE IF ((INFIL(I:I).EQ.'.').AND.(K.LT.0)) THEN
              GO TO 10
           ELSE
              OUTFIL(L:L)=INFIL(I:I)
              L=L+1
           END IF
   10    CONTINUE
         M=L-1
      ELSE
C
      OUTFIL=INFIL
C
      END IF
C
C.....CONVERT TO REQUIRED TAPE CODE
C
      JC=0
      DO 100 I=1,M
      IC=ICHAR(OUTFIL(I:I))+1
c      IF (PUNCOD(IC).EQV.ILEGAL) THEN
      if (puncod(ic).eq.ilegal) then
         CALL CFORM('**** ILLEGAL CHARACTER CONVERSION IN PUNCHC ****',
     1              DARRAY,2,48)
         CALL CPRINT(DARRAY)
         GO TO 100
      END IF
C
      JC=JC+1
      PUNOUT(JC)=PUNCOD(IC)
  100 CONTINUE
C
C.....OUTPUT TO PUNCH FILE, JC IS NO OF BYTES
C
      CALL TAPEPN(PUNOUT,JC)
      J=JC
      RETURN
      END
