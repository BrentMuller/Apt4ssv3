**** SOURCE FILE : M0008153.W01   ***
*
C
C              FORTRAN SUBROUTINE LOGIF
C
C LINKAGE      SUBROUTINE LOGIF(TEMP,MODE,COM1,COM2)
C
C         SUBSIDIARIES              CALLED FROM
C         NONE                      TYPE           ENTRY
C                                                  XCALL
C
      SUBROUTINE LOGIF(TEMP,MODE,COM1,COM2)
C
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C*
C     TEMP   1.D0 = .TRUE. ; 0.D0 = .FALSE.
C     MODE   COMPARATIVE CODE
C            1      2      3      4      5      6      7      8     9
C            EQ     NE     GE     LE     GT     LT     NOT    OR    AND
C     COM1  1ST LOGICAL OR RELATIONAL OPERATOR
C     COM2  2ND LOGICAL OR RELATIONAL OPERATOR
C**
      DATA TRUE,FALSE,SMAL,DIVIS/1.D0,0.D0,1.D-12,2.D0/
C
      COMP1=COM1
      COMP2=COM2
C
      GOTO(10,20,30,40,50,60,70,80,90),MODE
C                   ** COMP1 EQUAL COMP2 **
   10 IF(DABS(COMP1-COMP2).GT.SMAL)GOTO 110
      GOTO 100
C                   ** COMP1 NOT EQUAL COMP2 **
   20 IF(DABS(COMP1-COMP2).GT.SMAL)GOTO 100
      GOTO 110
C                   ** COMP1 GREATER EQUAL COMP2 **
   30 IF(COMP1.GT.COMP2)GOTO 100
      GOTO 10
C                   ** COMP1 LESS EQUAL COMP2 **
   40 IF(COMP1.LT.COMP2)GOTO 100
      GOTO 10
C                   ** COMP1 GREATER THAN COMP2 **
   50 IF(COMP1.GT.(COMP2+SMAL))GOTO 100
      GOTO 110
C                   ** COMP1 LESS THAN COMP2 **
   60 IF(COMP1.LT.(COMP2-SMAL))GOTO 100
      GOTO 110
C                   ** .NOT. COMP1 **
   70 TEMP=DINT(DABS(COMP1-TRUE)+SMAL)
      GOTO 120
C                   ** COMP1 .OR. COMP2 **
   80 TEMP=DINT((COMP1+COMP2+TRUE)/DIVIS+SMAL)
      GOTO 120
C                   ** COMP1 .AND. COMP2 **
   90 TEMP=DINT(COMP1*COMP2+SMAL)
      GOTO 120
C
  100 TEMP=TRUE
      GOTO 120
  110 TEMP=FALSE
  120 RETURN
      END
