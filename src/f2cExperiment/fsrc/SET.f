**** SOURCE FILE : M0000732.V07   ***
*
C
C.....FORTRAN ROUTINE              ..SET..     HL GRAY 3/68         *ID*
      SUBROUTINE  SET(LN)
C
C FORTRAN SUBROUTINE 'SET(LN)'  -- SET LOCATION COUNTER TO LINE
C
C PURPOSE      'SET'    SETS THE INTERPRETER PSEUDOLOCATION  COUNTER,
C              'ILC' AND OTHER DEPENDENT VARIABLES TO THE VALUES
C              CORRESPONDING TO THE INPUT LINE.
C
C LINKAGE      CALL SET(LN)
C
C              WHERE
C              LN IS ANY LINE
C
C--------------------------------------------------------------CDE PAK
C
C
C
C UNLABELED COMMON
C
C
       INCLUDE 'BLANKCOM.INC'
       INCLUDE 'INTRPEQ.INC'
C
C
C
C
C WORK--COMMON CONTAINING WORKING VARIABLES
C
C
      COMMON/WORK/  PGC,      PGCN,     ILC,      IXC
      INTEGER       PGC,      PGCN,     ILC,      IXC
C
C
C
C---------------------------------------------------------------------
C
      INTEGER SQNC
C
      INCLUDE 'DARRAY.INC'
C
C         LN IS ANY LINE(PAGE AND INDEX)
      INTEGER LN
      DIMENSION LN(2)
C
      EXTERNAL PAGE
      INTEGER  PAGE
      LN1=IABS(LN(1))
      IF((LN1.GT.0.AND.LN1.LE.400).AND.(LN(2).GT.0.AND.
     1 LN(2).LE.256)) GOTO 100
      CALL RECORD(SQNC)
      CALL CFORM('029007 UNDEFINED LABEL REFERENCED. ISN=',DARRAY,1,39)
      CALL ICONV(SQNC,DARRAY,40,4)
      CALL CPRINT(DARRAY)
      CALL HELP
C
C        SET LOCATION COUNTER TO BEGINNING OF PAGE
C
  100 ILC = PAGE(LN(1))
C
C        SET NEW PAGE NUMBER AND INDEX
C
      PGC = LN(1)
C
      IXC = LN(2)
C
C
C        SET NUMBER OF WORDS ON CURRENT PAGE
C
      PGCN = PP(ILC+1)+2
C
C        ADVANCE LOCATION COUNTER TO INSTRUCTION
C
      ILC = ILC + IXC -1
      RETURN
      END