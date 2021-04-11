**** SOURCE FILE : M0000713.V09   ***
*
C.....FORTRAN SUBROUTINE  ....CUT            8/68                 PH,HG
C.....FORTRAN SUBROUTINE             CUT   ...              3/1/68   GK
      SUBROUTINE CUT
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
C
C
C
      CHARACTER*4 PPWORD
      CHARACTER*32 MESAGE
C...
      DIMENSION     MSGARY(10)
C
      INTEGER BCDF,IPPWRD(2)
C
      DATA  PPWORD /'CUT '/
      DATA  MESAGE /' ...LOCATION WHERE CUT RESUMES..'/
      IF(JHLDFG.EQ.0) GO TO 1
      ITABH(ITHCNT)=6
      ITHCNT=ITHCNT+1
      RETURN
C
    1 CONTINUE
C...  OUTPUT CUTTER CENTERS ON EXFILE
      IF(ICUT)20,20,10
C
C...     WRITE ON EXFILE A MESSAGE INDICATING START OF CUT SEQUENCE
   10 MSGARY(1)=10
      MSGARY(2)=32
      DO 15 I=1,8
      I4 =I*4
      MSGARY(I+2) = BCDF(MESAGE(I4-3:I4))
   15 CONTINUE
      IPPWRD(1) = BCDF(PPWORD)
      IPPWRD(2) = BCDF('    ')
      CALL APT299(1,IPPWRD,27,MSGARY)
      ICL=K3
      ICUT=0
      CALL APT233
   20 CONTINUE
      RETURN
       END
C
C
C
      SUBROUTINE CUTH
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
C
C
C
      CHARACTER*4 PPWORD
      CHARACTER*32 MESAGE
C...
      DIMENSION     MSGARY(10)
C
      INTEGER BCDF
C
      DATA  PPWORD /'CUT '/
      DATA  MESAGE /' ...LOCATION WHERE CUT RESUMES..'/
C
    1 CONTINUE
C...  OUTPUT CUTTER CENTERS ON EXFILE
      IF(ICUT)20,20,10
C
C...     WRITE ON EXFILE A MESSAGE INDICATING START OF CUT SEQUENCE
   10 MSGARY(1)=10
      MSGARY(2)=32
      DO 15 I=1,8
      I4 =I*4
      MSGARY(I+2) = BCDF(MESAGE(I4-3:I4))
   15 CONTINUE
      IPPWRD = BCDF(PPWORD)
      CALL APT299(1,IPPWRD,27,MSGARY)
      ICL=K3
      ICUT=0
      CALL APT233
   20 CONTINUE
      RETURN
       END