**** SOURCE FILE : CONBCD00.ORG   ***
*
      SUBROUTINE CONBCD(A,B,II,JJ,K)
*
*  * CONBCD *   VAX11 FORTRAN 77 VERSION  09.09.82  E.MCLELLAN
*
*  PURPOSE      TO CONVERT A FLOATING-POINT NUMBER TO A FIXED
*               FORMAT FOR SUBSEQUENT TAPE PUNCHING
*
*  CALLING SEQUENCE
*               CALL CONBCD(A,B,I,J,K)
*  ARGUMENTS
*               A  FLOATING-POINT NUMBER TO BE CONVERTED TO BCD
*               B  LOCATION WHERE BCD NUMBERS WILL BE STORED
*               I  NUMBER OF BCD DIGITS TO BE INCLUDED IN B.
*                  IF I IS NEGATIVE,THE SIGN OF A WILL BE INCLUDED
*                  AND THE FIELD LENGTH WILL BE I+1 BCD CHARACTERS
*               J  NUMBER OF FRACTIONAL BCD DIGITS TO BE INCLUDED IN I
*                  IF J NEGATIVE, DECIMAL POINT WILL BE INCLUDED
*                  AND FIELD LENGTH INCREASED TO I+1 BCD CHARACTERS
*                  IF BOTH I AND J ARE NEGATIVE,FIELD LENGTH WILL
*                  BE I+2 CHARACTERS.
*                  IF ABS(J) GT 100, TRAILING ZEROS WILL BE DELETED.
*                  J WILL THEN EQUAL ABS(J)-100
*                  IF ABS(J) GT 200, LEADING ZEROS WILL BE DELETED.
*                  J WILL THEN EQUAL ABS(J)-200
*                  IF J LT -300, LEADING AND TRAILING ZEROS WILL
*                  BE DELETED. J WILL EQUAL ABS(J)-300
*               K  =1  A ASSUMED SINGLE PRECISION
*                  =2  A ASSUMED DOUBLE PRECISION
*                  =0  A ASSUMED DOUBLE PRECISION
*                      (EQUIVALENTTO OMISSION OF K)
*         NOTE:    IF K=0 AND I LE 6,THE OUTPUT IS RIGHT JUSTIFIED IN
*                  THE FIRST 6 BYTES OF B FOLLOWED BY 2 BLANKS
*                  IF K=0 AND I GT 6,THE OUTPUT IS RIGHT JUSTIFIED IN
*                  FIRST 12 BYTES OF B FOLLOWED BY 4 BLANKS
*                  IF K=1 OR 2 THEN OUTPUT IS RIGHT JUSTIFIED IN B
*                  IF B IS DIMENSIONED CORRECTLY
*
*         LIMITS:     K    IMAX     JMAX    BMIN
*                         (CHARS) (DIGITS) (BYTES)
*                     0     12        8       8
*                     1      8        6       4
*                     2     16       14       8
*
*                     IMAX INCLUDES SIGN AND DECIMAL POINT INCLUSION
*
      LOGICAL SFL,DFL,TZFL,LZFL
C.....SFL  TRUE IF SIGN TO BE INCLUDED
C     DFL  TRUE IF DECIMAL POINT TO BE INCLUDED
C     TZFL TRUE IF TRAILING ZEROS TO BE DELETED
C     LZFL TRUE IF LEADING ZEROS TO BE DELETED
C
      DOUBLE PRECISION A,ATEM,F,TENTOJ,DPF
      REAL B(4)
      EQUIVALENCE (AS,ATEM)
      CHARACTER*32 INTFIL
      CHARACTER*16 OUTFIL
C
      INCLUDE 'DARRAY.INC'
C
C
      ATEM=A
      I=II
      J=JJ
C
C..... INITIALIZE FLAGS
C
      SFL=.FALSE.
      DFL=.FALSE.
      TZFL=.FALSE.
      LZFL=.FALSE.
C
C.....CHECK FIFTH PARAMETER AND SET LIMITS
C
      IF (K.EQ.0) THEN
         IM=12
         JM=8
      ELSE IF (K.EQ.1) THEN
         IM=8
         JM=6
      ELSE IF (K.EQ.2) THEN
         IM=16
         JM=14
      END IF
C
C.....IF I NEGATIVE INCLUDE SIGN
C
      IF (I.LT.0) THEN
         SFL=.TRUE.
         I=IABS(I)+1
      ELSE IF (I.EQ.0) THEN
         CALL CFORM('**** INVALID CONBCD PARAMETER (I=0) ****',DARRAY,
     1               2,40)
         CALL CPRINT(DARRAY)
         CALL ABNEND
      END IF
C
C.....IF J NEGATIVE INCLUDE DECIMAL POINT
C
      IF (J.LT.0) THEN
         DFL=.TRUE.
         I=I+1
      END IF
C
C.....IF J.GT.300 ,NOT VALID
C
      IF (J.GT.300) THEN
         CALL CFORM('**** INVALID CONBCD PARAMETER (J.GT.300) ****',
     1               DARRAY,2,45)
         CALL CPRINT(DARRAY)
         CALL ABNEND
C
C.....IF J.LT.-300, DELETE LEADING AND TRAILING ZEROS
C                  (ONLY VALID IF DECIMAL POINT INCLUDED)
      ELSE IF (J.LT.-300) THEN
         TZFL=.TRUE.
         LZFL=.TRUE.
         J=IABS(J)-300
C
C.....IF ABS(J).GT.200 , DELETE LEADING ZEROS
C
      ELSE IF (IABS(J).GT.200) THEN
         LZFL=.TRUE.
         J=IABS(J)-200
C
C.....IF ABS(J).GT.100 , DELETE TRAILING ZEROS
C
      ELSE IF (IABS(J).GT.100) THEN
         TZFL=.TRUE.
         J=IABS(J)-100
      ELSE
         J=IABS(J)
      END IF
C
C.....CHECK LIMITS
C
      IF (I.GT.IM) THEN
         CALL CFORM('**** I.GT.IMAX FOR CURRENT K IN CONBCD CALL****',
     1              DARRAY,2,48)
         CALL CPRINT(DARRAY)
         I=IM
      END IF
C
      IF (J.GT.JM) THEN
         CALL CFORM('**** J.GT.JMAX FOR CURRENT K IN CONBCD CALL****',
     1            DARRAY,2,48)
         CALL CPRINT(DARRAY)
         J=JM
      END IF
C
C.....STORE VALUE IN DOUBLE PRECISION WORD F
C
      IF (K.EQ.1) THEN
          F=AS
      ELSE
          F=A
      END IF
C
C.....STORE SIGN OF F
C
      IS=INT(DSIGN(1.0D0,F))
C
C.....ROUND ABS VALUE OF F TO J DECIMAL PLACES
C
      TENTOJ=10.0D0**J
      F=ABS(F)
      INF=INT(F)
      DPF=F-DFLOAT(INF)
      INP=INT(DPF*TENTOJ+0.5D0)
      F=DFLOAT(INF)+DFLOAT(INP)/TENTOJ
C
C.....WRITE F TO INTERNAL FILE
C
      WRITE (INTFIL,'(F32.14)') F
C
C.....INSERT TRAILING BLANKS
C
      LSD=J+18
      INTFIL(LSD+1:32)=' '
C
C.....ARE TRAILING ZEROS TO BE DELETED
C
      IF (TZFL) THEN
          L=LSD
   10     IF (INTFIL(L:L).EQ.'0') THEN
             INTFIL(L:L)=' '
             L=L-1
             GO TO 10
          END IF
      END IF
C
C.....WHERE IS FIRST NON BLANK CHARACTER IN INTFIL
C
      L=1
  20  IF (INTFIL(L:L).EQ.' ') THEN
        IF (.NOT.LZFL) THEN
           INTFIL(L:L)='0'
        END IF
        L=L+1
        GO TO 20
      END IF
      L1=L
C
C.....IS DECIMAL POINT REQUIRED
C
      IF (.NOT.DFL) THEN
C.....NO DELETE DECIMAL POINT
      L=17
  30  INTFIL(L+1:L+1)=INTFIL(L:L)
      IF (L.EQ.L1) THEN
         IF (LZFL) THEN
            INTFIL(L1:L1)=' '
         ELSE
            INTFIL(L1:L1)='0'
         END IF
      ELSE
         L=L-1
         GO TO 30
      END IF
      END IF
C
C.....IS SIGN REQUIRED
C
      MSD=LSD-I+1
      IF (SFL) THEN
         IF (IS.GE.0) THEN
            INTFIL(MSD:MSD)='+'
         ELSE
            INTFIL(MSD:MSD)='-'
         END IF
      END IF
C
C.....SET UP OUTFIL ACCORDING TO K AND I
C
      OUTFIL(1:16)=' '
      IF (K.EQ.0) THEN
         IF (I.GT.6) THEN
            OUTFIL(13-I:12)=INTFIL(MSD:LSD)
            READ (OUTFIL,'(4A4)') (B(L),L=1,4)
         ELSE
            OUTFIL(7-I:6)=INTFIL(MSD:LSD)
            READ (OUTFIL,'(2A4)') B(1),B(2)
         END IF
C
      ELSE IF (I.GT.8) THEN
            OUTFIL(17-I:16)=INTFIL(MSD:LSD)
            READ (OUTFIL,'(4A4)') (B(L),L=1,4)
      ELSE IF (I.GT.4) THEN
            OUTFIL(9-I:8)=INTFIL(MSD:LSD)
            READ (OUTFIL,'(2A4)') B(1),B(2)
      ELSE
            OUTFIL(5-I:4)=INTFIL(MSD:LSD)
            READ (OUTFIL,'(A4)') B(1)
      END IF
C
      RETURN
      END
