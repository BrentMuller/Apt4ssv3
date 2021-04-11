**** SOURCE FILE : M0001039.V08   ***
*
      SUBROUTINE BAD(ICNTRL,ITYPE,ID,VALUE)
C---  ROUTINE TO FORMAT AND PRINT LINES OF PRINT FOR DEBUGGING
C---  EACH LINE CONTAINS UP TO SIX VALUES WITH IDENTIFIERS FOR EACH
C---  ICNTRL=-1  MEANS RELEASE THE BUFFER (DARRAY) FOR PRINTING AND BLNK
C---  ICNTRL=0 MEANS BLANK THE BUFFER AND SET COLUMN POINTER NCOL TO 4
C---  ICNTRL GT 0 MEANS  TO PLACE ICNTRL ITEMS INTO THE BUFFER AND
C---  ICNTRL=-N MEANS PRINT N ITEMS AND THEN RELEASE BUFFER TO PRINT.
C---  AUTOMATICALLY PRINT THE BUFFER AS ROOM IS EXHAUSTED
C---  ITYPE =0 MEANS PRINT THE INTEGER AT VALUE
C---    AND =1 MEANS PRINT THE DOUBLE PRECISION
C---  ID IS THE 4 CHARACTER IDENTIFYING NAME FOR VALUE AND VALUE
C---     IS THE DATA TO BE FORMATTED INTO THE PRINT LINE.
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      INCLUDE 'DARRAY.INC'
      CHARACTER BLANK*3,STAR*2,EQUAL,ID*4
      INTEGER VALUE
      DIMENSION VALUE(*)
      DIMENSION II(2)
      EQUIVALENCE (AA,II(1))
C
      SAVE NCOL
C
C
C---     BUFFUL IS A FLAG TO SIGNAL THAT A BUFFER IS NOW FULL
C---     SO THAT IT SHOULD NOW BE EMPTIED BEFORE INSERTING MORE DATA
      LOGICAL BUFFUL
C
      DATA BLANK/'   '/,STAR/'**'/,NCOL/4/,EQUAL/'='/
C---
C---  IC IS A COUNT DOWN VARIABLE FOR CASES WHEN ICNTRL GT 1
      IC=0
      BUFFUL=.FALSE.
C---     TRANSFER ICNTRL TO ICNTRX SO ICNTRL IS NOT ALTERED
      ICNTRX=ICNTRL
C---     THIS IS A PATCH TO ENABLE DUMPING OF DATA AT END OF CALL
C---     IF ICNTRX IS NEGATIVE, THEN DATA SHOULD BE DUMPED AT
C---     AT THE END OF THE CURRENT CALL
      IRLSE=1
      IF(ICNTRX.LT.0) IRLSE=-1
C---     IF ID IS ZERO AND ICNTRX IS NEGATIVE THEN RELEASE NOW
      IF(ID(1:1).EQ.' '.AND.ICNTRX.LT.0) GO TO 300
C---     SET ICNTRX POSITIVE, SINCE IRLSE HOLDS THE NEGATIVE INDICATION
      ICNTRX=IABS(ICNTRX)
      IF ( ICNTRX ) 300, 100, 200
C
C---  INITIALIZE THE BUFFER BY BLANK FILLING AND COLUMN SETTING
  100 CONTINUE
      DARRAY=BLANK
      NCOL=4
      IF(.NOT.BUFFUL) GO TO 999
C---  BUFFER HAS JUST BEEN AUTOMATICALLY EMPTIED.  NOW INSERT DATA
      BUFFUL=.FALSE.
      GO TO 210
C
C---   ADD A NEW DATA ELEMENT INTO THE BUFFER LINE
  200 CONTINUE
      BUFFUL=.TRUE.
      IF(NCOL+18.GT.120) GO TO 300
  210 CALL CFORM(BLANK,DARRAY,NCOL,1)
      NCOL=NCOL+1
      IC=IC+1
C---   PLACE AN ID FOR THE FIRST ARRAY EL, COUNTERS THEREAFTER
      IF(IC.EQ.1)  CALL CFORM(ID,DARRAY,NCOL,4)
      IF(IC.GT.1) CALL ICONV(IC,DARRAY,NCOL,4)
      NCOL=NCOL+4
      CALL CFORM(EQUAL,DARRAY,NCOL,1)
      NCOL=NCOL+1
C---   BRANCH BASED ON TYPE OF DATA -- INTEGER OR REAL
      IF (ITYPE.EQ.0) THEN
C---   ADD AN INTEGER TO THE LINE BUFFER
C---  THE INTEGER JJ IS SETUP BY THE MOVEMENT OF VALUE INTO AA
      CALL ICONV(VALUE(IC),DARRAY,NCOL,10)
      NCOL=NCOL+10
      CALL CFORM(BLANK,DARRAY,NCOL,3)
      NCOL=NCOL+3
      ELSE IF (ITYPE.EQ.1) THEN
C---   ADD A REAL TO THE LINE BUFFER
C---  CARE MUST BE TAKEN TO TRANSFER DATA TO A DOUBLE WORD  BOUNDARY
      II(1)=VALUE(2*IC-1)
      II(2)=VALUE(2*IC)
C---  THE DOUBLE VALUE IS NOW AVAILABLE IN AA THRU EQUIVALENCE
      INPUT=VALUE(2*IC-1)
      CALL FCONV(AA,DARRAY,NCOL,13,5)
      NCOL=NCOL+13
      ELSE
        CALL CFORM('******',DARRAY,NCOL,6)
        NCOL=NCOL+13
      ENDIF
      GOTO 999
C
C
C---   PRINT THE BUFFER AND BLANK THE LINE
  300 CONTINUE
C---  IF THE BUFFER IS EMPTIED AUTOMATICALLY, MARK IT WITH STARS
      IF(.NOT.BUFFUL) GO TO 310
      IF(IRLSE.GT.0) CALL CFORM(STAR,DARRAY,2,2)
  310 CALL CPRINT(DARRAY)
      GO TO 100
C---
  999 CONTINUE
C---  CHECK TO SEE IF AN ARRAY HAS BEEN EXHAUSTED
      IF(ICNTRX.GT.0.AND.IC.LT.ICNTRX) GO TO 200
C---     IF IRLSE IS NEGATIVE THEN THE BUFFER SHOULD BE
C---     RELEASED NOW
      IF(IRLSE.GT.0) GO TO 9999
      IF(NCOL.EQ.4) GO TO 9999
C---     DATA IS PRESENT SO RELEASE THE BUFFER
      CALL CPRINT(DARRAY)
      NCOL=4
C
 9999 CONTINUE
      RETURN
      END