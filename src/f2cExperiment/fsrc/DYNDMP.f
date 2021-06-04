**** SOURCE FILE : M0000897.V04   ***
*
C
C.....FORTRAN SUBROUTINE             DYNDMP...              4/1/68   GK
CIBFTC DYNDMP  XR6
      SUBROUTINE DYNDMP (BRKPNT,ONOFF,PTNO)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
      INCLUDE 'IBRKPT.INC'
C
C...  21. ADDCOM BLOCK
C
      COMMON/ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM( 1),ELMAX ),  (ADDCOM( 2),CLNGTH),
     1            (ADDCOM(23),IBTFLG),  (ADDCOM(24),JLIN),
     2            (ADDCOM(25),KDYNFL)
C
C ***    VALUES OF BRKPNT SET AS FOLLOWS
C                  1 ACTIVATES ALL BREAKPOINTS
C                  100 ACTIVATES ALL AJUNDD AND AMIND BREAKPOINTS
C                  200 ACTIVATES ALL ARLM3 BREAKPOINTS
C                  500 ACTIVATES ALL GO BREAKPOINTS
C                  IJK ACTIVATES THE JK BREAKPOINT IN THE I SERIES
C ***
C
C
      KDYNFL=K1
      N=51
      L = BRKPNT
      IF(L.EQ.K1) GOTO 30
      J=L/100
      K=L-J*100
      L=K10*(J-K1)+K
      N=L
C...  IF K=0, ACTIVATE OR DEACTIVATE ALL BREAKPOINTS FOR THAT ROUTINE
      IF(K)50,10,30
   10 IF(J.NE.K2)GOTO 20
      N=N+K10
   20 N=N+K10
      L=L+K1
C...  EACH BREAKPOINT CORRESPONDS TO AN ELEMENT OF THE ARRAY BRAKPT(I)
C        THE BREAKPOINT IS ACTIVATED OR DEACTIVATED ACCORDING AS HOW
C        BRAKPT(J)=1 OR 0
   30 DO 40 J=L,N
   40 IBRKPT(J) = ONOFF
C...  STRTNO CONTAINS THE NUMBER OF THE FIRST CUTTER POINT TO OUTPUT
C     DYNDMP PRINTING FOR EACH CUT SEQUENCE
      STRTNO=PTNO
   50 RETURN
       END
