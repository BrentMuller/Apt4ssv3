**** SOURCE FILE : TAPEPN00.ORG   ***
*
      SUBROUTINE TAPEPN(CHAR,N)
*
*  * TAPEPN *  VAX-11 FORTRAN 77 VERSION  26.10.82  E.MCLELLAN
*
*  PURPOSE     TO WRITE COLUMN BINARY DATA TO PAPER TAPE PUNCH FILE
*
*  CALLING SEQUENCE
*              CALL TAPEPN(CHAR,N)
*  ARGUMENTS
*              CHAR  BYTE ARRAY CONTAINING COLUMN BINARY CODES
*              N     NO OF COLUMNS (CHARACTERS) TO BE PUNCHED
*
C
C...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA
C...ON OTHER SYSTEMS
      BYTE CHAR(3024)
*
      LOGICAL OD
C
      INCLUDE 'DARRAY.INC'
C
C
C.....WRITE IN A FORMAT TO FILE PUNTAP.DAT
C
C.....IS PUNTAP.DAT OPEN
C
      INQUIRE(FILE='PUNTAP.DAT',OPENED=OD)
         IF (.NOT.OD) THEN
            OPEN(UNIT=7,FILE='PUNTAP.DAT',ERR=90,STATUS='NEW',
     1           ACCESS='SEQUENTIAL',FORM='FORMATTED')
         END IF
C
C.....WRITE TO PUNTAP.DAT
C
      WRITE(7,'(80A1)') (CHAR(I),I=1,N)
      RETURN
C
   90 CALL CFORM('**** ERROR OPENING PUNTAP.DAT ****',DARRAY,2,34)
      CALL CPRINT(DARRAY)
      CALL ABNEND
      RETURN
      END