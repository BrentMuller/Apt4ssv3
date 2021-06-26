**** SOURCE FILE : FILOPN00.ORG   ***
*
*
*  * FILOPN *    VAX11 FORTRAN SUBROUTINE  10.5.82 E.MCLELLAN
*                MODIFIED                  18.07.85 E.MCLELLAN
*
*  PURPOSE     TO OPEN A FILE WITH REQUIRED ATTRIBUTES
*
*  CALLING SEQUENCE
*              CALL FILOPN(NO)
*  ARGUMENTS
*              NO    FILE NUMBER
*
*  GLOBAL VARIABLES:
*
*---------------------------------------------------
*   VARIABLE        BLOCK     TYPE       DESCRIPTION
*---------------------------------------------------
*   FILNAM          FILTAB    CHARACTER  FILE NAME
*   FILACC          FILTAB    CHARACTER  FILE ACCESS
*                                         (DIRECT OR SEQUENTIAL)
*   FILFMT          FILTAB    CHARACTER  FILE FORMAT
*                                         (FORMATTED OR UNFORMATTED)
*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS
*                                         (UNKNOWN,SCRATCH,NEW,OLD)
*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE)
*   U               IFILTB    INTEGER    UNIT NUMBER
*   RL              IFILTB    INTEGER    RECORD LENGTH
*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE
*                                        READ OR WRITTEN (DIRECT ACCESS)
*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE
*                                         (DIERECT ACCESS)
*
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*        DARRAY     CHARACTER  PRINT BUFFER
*        POSN       INTEGER    START POSITION IN PRINT BUFFER
*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN BUFFER
*
*  FILES:  FILE REFERENCED BY FILE NUMBER
*
*  SUBSIDIARIES:
*               CFORM
*               ICONV
*               CPRINT
*
      SUBROUTINE FILOPN(NO)
C
      INCLUDE 'FILTAB.INC'
C
      INTEGER POSN,SLEN
      CHARACTER*80 DARRAY
      DATA DARRAY/' '/
      
cc   fortran 77 disallows a named scratch file
c       if(opstat(no).eq.'SCRATCH')then
c            write(*,*)'opstat is scratch'
c            write(*,*)'opstat is: ',opstat(no)
cc    no file name-
c      open (unit=u(no),iostat=iret,err=90,
c     1      status=opstat(no),access=filacc(no),
c     2      form=filfmt(no),recl=rl(no))
c      else
cc    file name-
c      open (unit=u(no),file=filnam(no),iostat=iret,err=90,
c     1      status=opstat(no),access=filacc(no),
c     2      form=filfmt(no),recl=rl(no))
c            write(*,*)'opstat is: ',opstat(no)
c      endif
C
c      gfortran doesn't like an option in this open statement
     OPEN (UNIT=U(NO),FILE=FILNAM(NO),IOSTAT=IRET,ERR=90,
    1      STATUS=OPSTAT(NO),ACCESS=FILACC(NO),
    2      FORM=FILFMT(NO),RECL=RL(NO))
c     open (unit=u(no),file=filnam(no),iostat=iret,err=90,
c      open (unit=u(no),iostat=iret,err=90,
c     1      status=opstat(no),access=filacc(no),
c     1      access=filacc(no),
c     2      form=filfmt(no),recl=rl(no))
C
      RETURN
C
   90 SLEN=0
      CALL CFORM (' **** ERROR OPENING FILE :',DARRAY,2,SLEN)
      POSN=SLEN+3
      SLEN=0
      CALL CFORM (FILNAM(NO),DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+1
      SLEN=0
      CALL CFORM ('; UNIT NO :',DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+1
      CALL ICONV (U(NO),DARRAY,POSN,2)
      POSN=POSN+4
      SLEN=0
      CALL CFORM ('****',DARRAY,POSN,SLEN)
      CALL CPRINT (DARRAY)
      CALL ABNEND
      RETURN
      END