**** SOURCE FILE : ATAPWT.ORG   ***
*
*
*  *  ATAPWT  *  FORTRAN 77 VERSION   1-MAR-1988 E.MCLELLAN
*
*  PURPOSE     TO WRITE AN APT 111 FORMATTED CLFILE
*              RESTRICTED TO TWO INPUT ARRAYS MAXIMUM
*
*  CALLING SEQUENCE
*              CALL ATAPWT(NO,IRET,N,A1,N1,A2,N2)
*  ARGUMENTS
*              NO         FILE NUMBER
*                         FOR NC 360 HELD IN SECOND HALF
*                         OF DOUBLE PRECISION WORD
*              IRET.LT.0  NORMAL RETURN
*                  .GT.0  ABNORMAL CONDITION
*              N          NO OF ARRAYS AI SPECIFIED IN CALLING SEQUENCE
*              AI         ARRAY CONTAINING DATA TO BE WRITTEN TO FILE
*              NI         NO OF ITEMS IN ARRAY AI TO BE WRITTEN TO FILE
*
      SUBROUTINE ATAPWT(NO,IRET,NUM,A1,N1,A2,N2)
C
C.... ARGUMENTS
      INTEGER NO,IRET,NUM,A1,N1,N2
      DOUBLE PRECISION A2
      DIMENSION NO(2),A1(N1),A2(N2)
C
C.... LOCAL VARIABLES
      INTEGER NWRDS,IREC
      REAL REC
      DOUBLE PRECISION DREC
      DIMENSION REC(512),DREC(254),IREC(512)
      EQUIVALENCE (REC(1),IREC(1))
      EQUIVALENCE (REC(5),DREC(1))
C
C.... COMMON BLOCKS
      INCLUDE 'DARRAY.INC'
C
      ID=NO(1)
      IF (NO(1).EQ.0)  ID=NO(2)
C
      IF (NUM.EQ.1) THEN
        NWRDS=N1
      ELSE IF (NUM.EQ.2) THEN
        NWRDS=3+2*N2
      ELSE
        CALL CFORM(' *** ERROR IN CALL TO ATAPWT, MAXIMUM OF TWO ARRAYS
     +ALLOWED ***',DARRAY,2,63)
        CALL CPRINT(DARRAY)
        IRET=1
        RETURN
      ENDIF
C
      IREC(1)=NWRDS
      DO 10 I=2,4
       IREC(I)=0
  10  CONTINUE
C
      DO 20 I=1,N1
       IREC(I+1)=A1(I)
  20  CONTINUE
C
      IF (NUM.EQ.2) THEN
        DO 30 I=1,N2
          DREC(I)=A2(I)
  30    CONTINUE
      ENDIF
C
      WRITE(ID,IOSTAT=IRET) (REC(I),I=1,NWRDS+1)
C
      RETURN
      END
