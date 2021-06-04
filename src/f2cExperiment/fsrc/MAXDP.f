**** SOURCE FILE : M0001137.V05   ***
*
 
 
 
C
C
C.....FORTRAN SUBROUTINES          MAXDP & MAXDPH            4/1/68   GK
C
C
      SUBROUTINE MAXDP(DCML,ELNGTH)
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
      INCLUDE 'FXCOR.INC'
C
C...  21. ADDCOM BLOCK
C
      COMMON/ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM( 1),ELMAX ),  (ADDCOM( 2),CLNGTH),
     1            (ADDCOM(23),IBTFLG),  (ADDCOM(24),JLIN)
C
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(26),DECMAL),(SAVEH(27),ELNGH)
C
      COMMON/MODESS/MODESS,MSSCHK,MSSARL
C
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      CHARACTER*8 PPWORD
      INTEGER IPPWRD(2),BCDF
      DATA  PPWORD /'MAXDP '/
C
      DATA Z2,Z3,Z4,SMAL/2.D0,3.D0,4.D0,1.D-12/
C
      DECMAL=DCML
      ELNGH=ELNGTH
      IF(JHLDFG.EQ.0) GO TO 1
C             /-IF JHLDFG IS NOT ZERO, ARELEM IS SEARCHING FOR A CHECK
C             /-SURFACE.  INTERVENING COMMANDS NOT TO BE EXECUTED YET.
      ITABH(ITHCNT)=10
      ITHCNT=ITHCNT+1
      RETURN
            
    1 CONTINUE
C
C             /-SPECIAL FLAG FOR SS ARELEM MODE AND DEBUGGING LEVEL PRIN
C             /-MAXDP/-K,L WHERE -K IS -2 OR LESS AND IBUG=L
      IF(DECMAL.GT.-Z2) GO TO 200
C             /-SET SWITCH FOR SS SPECIAL ARELEM(ON FOR-2, OFF FOR -3)
      IF(DABS(DECMAL+Z2).LT.SMAL) MSSARL=1
      IF(DABS(DECMAL+Z3).LT.SMAL) MSSARL=0
C             /-SET VALUE OF IBUG FROM SECOND ARGUMENT IF DECMAL=-4
      IF(DABS(DECMAL+Z4).LT.SMAL) IBUG=ELNGH
C             /-OMIT WRITING A MAXDP RECORD FOR THESE CASES
      GO TO 100
C
  200 CONTINUE
      IPPWRD(1)=BCDF(PPWORD(1:4))
      IPPWRD(2)=BCDF(PPWORD(5:8))
C...  USE THIS MAXIMUM STEP IN ALL ARITHMETIC CALCULATIONS
      IF (ELNGH) 30,30,10
   10 ELMAX = ELNGH
      KK=2
   20 DPMAX = DECMAL
      GO TO 70
C
   30 KK=1
      IF (DECMAL) 50,40,20
   40 JLIN=0
      GO TO 70
C
C...     THE COMMAND MAXDP/-1 IS NOT IMPLEMENTED
   50 IF (DECMAL+1.) 60,70,40
   60 IF(DECMAL+1.1.GT.0.0) JLIN=1
C
   70 CALL APT299(KK,IPPWRD,1,DECMAL)
      IF (KK .EQ. 1) GO TO 100
      CALL APT299(1,ELNGH,0,0)
C
  100 RETURN
      END
C
C
C
C
C
C
C.....FORTRAN SUBROUTINE            MAXDPH...               4/1/68   GK
C
      SUBROUTINE MAXDPH(DCML,ELNGTH)
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
C
C...  21. ADDCOM BLOCK
C
      COMMON/ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM( 1),ELMAX ),  (ADDCOM( 2),CLNGTH),
     1            (ADDCOM(23),IBTFLG),  (ADDCOM(24),JLIN)
C
      COMMON /HSAVE/ SAVEH(50)
      EQUIVALENCE (SAVEH(26),DECMAL),(SAVEH(27),ELNGH)
C
      COMMON/MODESS/MODESS,MSSCHK,MSSARL
C
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      CHARACTER*8 PPWORD
      INTEGER IPPWRD(2),BCDF
      DATA  PPWORD /'MAXDP '/
C
      DATA Z2,Z3,Z4,SMAL/2.D0,3.D0,4.D0,1.D-12/
C
C
C             /-SPECIAL FLAG FOR SS ARELEM MODE AND DEBUGGING LEVEL PRIN
C             /-MAXDP/-K,L WHERE -K IS -2 OR LESS AND IBUG=L
      IF(DECMAL.GT.-Z2) GO TO 200
C             /-SET SWITCH FOR SS SPECIAL ARELEM(ON FOR-2, OFF FOR -3)
      IF(DABS(DECMAL+Z2).LT.SMAL) MSSARL=1
      IF(DABS(DECMAL+Z3).LT.SMAL) MSSARL=0
C             /-SET VALUE OF IBUG FROM SECOND ARGUMENT IF DECMAL=-4
      IF(DABS(DECMAL+Z4).LT.SMAL) IBUG=ELNGH
C             /-OMIT WRITING A MAXDP RECORD FOR THESE CASES
      GO TO 100
C
  200 CONTINUE
      IPPWRD(1)=BCDF(PPWORD(1:4))
      IPPWRD(2)=BCDF(PPWORD(5:8))
C...  USE THIS MAXIMUM STEP IN ALL ARITHMETIC CALCULATIONS
      IF (ELNGH) 30,30,10
   10 ELMAX = ELNGH
      KK=2
   20 DPMAX = DECMAL
      GO TO 70
C
   30 KK=1
      IF (DECMAL) 50,40,20
   40 JLIN=0
      GO TO 70
C
C...     THE COMMAND MAXDP/-1 IS NOT IMPLEMENTED
   50 IF (DECMAL+1.) 60,70,40
   60 IF(DECMAL+1.1.GT.0.0) JLIN=1
C
   70 CALL APT299(KK,IPPWRD,1,DECMAL)
      IF (KK .EQ. 1) GO TO 100
      CALL APT299(1,ELNGH,0,0)
C
  100 RETURN
      END
