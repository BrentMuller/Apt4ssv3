**** SOURCE FILE : M0004142.V09   ***
*
C.....FORTRAN SUBROUTINE  ....APT299         8/68                 AR,HG
C.....FORTRAN SUBROUTINE      APT299                4/18/68    AR
C
C PURPOSE      TO CREATE AND WRITE EXFILE RECORDS FROM DATA SUPPLIED BY
C              THE PART PROGRAM.
C
C LINKAGE      CALL APT299(ARG1,ARG2,ARG3,ARG4)
C
C NOTE 1       APT299 IS CALLED REPEATEDLY BY THE PART PROGRAM UNTIL ALL
C              ARGUMENTS NECESSARY FOR THE CREATION OF THE EXFILE RECORD
C              HAVE BENN PASSED.
C
C ARGUMENTS    ARG1           IN THE FIRST CALL TO APT299 ARG1 = THE
C                             NUMBER OF DATA ITEM ARGUMENT PAIRS.
C                             THEREAFTER IT IS THE FIRST ELEMENT OF A
C                             DATA ITEM ARGUMENT PAIR.
C              ARG2           IN THE FIRST CALL TO APT299 ARG2 = THE
C                             MAJOR WORD OF THE PART PROGRAM STATEMENT
C                             THAT IS CAUSING AN EXFILE RECORD TO BE
C                             CREATED. THEREAFTER IT IS THE SECOND
C                             ITEM OF A DATA ITEM ARGUMENT PAIR.
C              ARGK (K=1,3)   THE FIRST ELEMENT OF A DATA ITEM ARGUMENT
C                             PAIR. IT IS USED AS AN INDEX ON THE CLSIZE
C                             ARRAY TO LOCATE THE SIZE OF AN ITEM.
C              ARGL (L=2,4)   THE SECOND ELEMENT OF A DATA ITEM ARGUMENT
C                             PAIR. IT IS EITHER A SINGLE DATA ITEM OR
C                             AN ARRAY CONTAINING A STRING OF DATA ITEMS
C
C NOTE 2       A DATA ITEM ARGUMENT PAIR OCCURS FOR EACH SINGLE ITEM OR
C              EACH STRING OF ITEMS TO BE INCLUDED IN THE EXFILE RECORD.
C
C SUBSIDARY    MACHINE LANGUAGE SUBROUTINE        RECORD
C
C
      SUBROUTINE APT299(ARG1,ARG2,ARG3,ARG4)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'KNUMBR.INC'
      INCLUDE 'SYMFIL.INC'
C......  LOCAL VARIABLES
C
      LOGICAL  FIRST,ODD
      INTEGER  CLSIZE,SIZE,START,T,ARG1,ARG2,ARG3,ARG4,W,BLANK,BCDF
      INTEGER  Z4E
      PARAMETER (Z4E=1308622848)
C
      DIMENSION ARG1(1),ARG2(*),ARG3(1),ARG4(*),W(200),
     / CLSIZE(27)
C
      SAVE FIRST,BLANK
C
      DATA  FIRST,IUNORM /.TRUE.,Z4E/
      DATA  CLSIZE /1,1,4,4,7,7,4,3*10,7,10,0,0,79,10,3*0,12,3,3,4*1,0/
C
C ********************************************************************
C
C
C... CHECK IF THIS IS THE FIRST CALL TO APT299 FOR THE CURRENT EXFILE
C... RECORD BEING CREATED. IF NOT,CONTINUE INSERTING ITEMS IN THE
C... RECORD. IF IT IS THE FIRST CALL,DO HOUSEKEEPING.
C
      IF (.NOT. FIRST)  GO TO 15
C
C... SET FIRST CALL FLAG FALSE.
C
      FIRST = .FALSE.
C
C    INITIALIZE BLANK
      BLANK = BCDF('    ')
C
C... SET NOPAIR = THE NUMBER OF DATA ITEM ARGUMENT PAIRS.
C
      NOPAIR=ARG1(1)
C
C... SET FIRST RECORD WORD = MAJOR WORD.
C... SET SECOND RECORD WORD = PART PROGRAM STATEMENT INTERNAL SEQUENCE
C... NUMBER
C
      W(3)=IUNORM
      W(1)=ARG2(1)
      W(2)=ARG2(2)
      CALL RECORD(W(4))
C
C... IF THERE ARE NO MORE ARGUMENTS,ADD ALPHANUMERIC DATA ITEM
C... AND WRITE THE RECORD.
C
      IF (NOPAIR .GT. K0)  GO TO 10
    5 W(7)=IUNORM
      W(8)=K2
      W(9)=BLANK
      W(10)=BLANK
      J=10
      GO TO 80
C
C... INITIALIZE RECORD INDEX
C
   10 J=K6
C
C... INSERT DATA ITEMS IN RECORD.
C... INITIALIZE DO LOOP INDEX
C
      IDO = K1
   15 START = IDO
      DO 70  I = START,NOPAIR
C
C... IF I IS EVEN,SET ODD = .FALSE. INDICATING ARG1 AND ARG2 ARE TO BE
C...    USED DURING THIS ITERATION.
C... IF I IS ODD, SET ODD = .TRUE. INDICATING ARG3 AND ARG4 ARE TO BE
C...    USED DURING THIS ITERATION.
C
      ODD = .TRUE.
      IF ((I - K2*(I/K2)) .EQ. K0)  ODD = .FALSE.
C
C... INSERT ITEM INDICATOR CODE IN RECORD.
C
      J=J+K2
      W(J-1)=IUNORM
      W(J)=ARG1(1)
      IF(ODD) W(J)=ARG3(1)
      T=W(J)
      IF(T.GT.K2.AND.T.LT.K27)  W(J)=K4
      IF(T.EQ.K27) W(J)=K3
C
C... SET SIZE = CLSIZE FOR THIS ITEM. FROM THE MAGNITUDE OF SIZE
C... DETERMINE THE TYPE OF THE ITEM.
C
      SIZE = CLSIZE(T)
      IF (SIZE - K1)  20,40,30
C
C... ALPHANUMERIC DATA ITEM STRING --- INSERT NUMBER OF ITEMS,TOTAL
C... CHARACTER COUNT, AND DATA ITEMS IN THE RECORD.
C... RESET SIZE = NUMBER OF ITEMS IN THE STRING.
C
   20 J=J+K4
      W(J-1)=IUNORM
      W(J-3)=IUNORM
      SIZE=ARG4(1)
      W(J)=ARG4(2)
      IF(ODD) GO TO 22
      SIZE=ARG2(1)
      W(J)=ARG2(2)
      GO TO 25
   22 IF(W(J).NE.K0) GO TO 25
      W(J-2)=K2
      J=J+K2
      W(J-1)=BLANK
      W(J)=BLANK
      GO TO 80
C
C... SET STRING ARRAY SUBSCRIPT =3.
C
   25 W(J-2)=(SIZE+K1)/K2
      L=K3
      GO TO 50
C
C... GEOMETRIC VARIABLE --- INSERT NUMBER OF ITEMS AND GEOMETRIC DATA.
C
   30 J=J+K2
      W(J-1)=IUNORM
      W(J)=SIZE
C
C... FLOATING POINT OR ALPHANUMERIC DATA ITEM.--- SET ARRAY SUBSCRIPT
C... =1.
C
   40 L = K1
C
      SIZE=SIZE*2
C... ADD ARRAY ELEMENTS TO RECORD.
   50 L1=L
      DO 60 L=L1,SIZE
      J = J + K1
      W(J) = ARG2(L)
      IF (ODD)  W(J) = ARG4(L)
   60 CONTINUE
C
C... CHECK IF IT IS NECESSARY TO RETURN TO THE PART PROGRAM FOR MORE
C... ARGUMENTS.
C
      IF ((.NOT. ODD) .OR. (I .EQ. NOPAIR))  GO TO 70
      IDO = I + 1
      GO TO 99
   70 CONTINUE
C
C... SET THIRD RECORD WORD = NUMBER OF DATA ITEMS, RESET FIRST CALL FLAG
C... .TRUE., WRITE RECORD TO EXFILE ,AND RETURN TO CALLER.
C
   80 W(5)=IUNORM
      IF((J-K2*(J/K2)).EQ.K0) GO TO 85
      J=J+1
      W(J)=BLANK
   85 W(6)=J/2-K3
      FIRST = .TRUE.
      NR=0
      CALL EWRITE(EXFILE,NR,W,J,IR)
   99 RETURN
       END