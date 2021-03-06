**** SOURCE FILE : M0011486.W01   ***
*
C
      SUBROUTINE CLDAT(ARG1,ARG2,ARG3,ARG4)
C
C   PURPOSE: TO CONTROL AND STORE CLDAT PARAMETERS AND INDICATORS.
C
C     ICLTAB   (1,X)  INDEX OF THE CLDAT SECTION.
C     ICLTAB   (2,X)  NUMBER OF POINTS IN THE CLDAT SECTION.
C     ICLTAB   (3,X)  FORM OF STORAGE ON EXFILE (TP,TA,TV,...).
C     ICLTAB   (4,X)  FIRST EXFILE BLOCK  OF THE CLDAT SECTION.
C     ICLTAB   (5,X)  FIRST EXFILE RECORD OF THE CLDAT SECTION.
C     CLDFG           FLAG TRUE = A CLDAT-SECTION IS OPENED, COUNTING
C                     OF THE POINTS IN ATAPE.
C     ICLCNT          POINTER TO THE LAST ICLTAB ENTRY.
C     ICLINE          ICLTAB INDEX.
C     ICLIDX          ICLTAB INDEX.
C
C     ICLCOD = ICLTAB   (3,X)    ;   ICLBLK = ICLTAB   (4,X)
C     ICLRCD = ICLTAB   (5,X)
C
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'IFXCOR.INC'
C
      INCLUDE 'CLDT.INC'
C
      DIMENSION CLREC(14),NARG(8)
      INTEGER   ARG1,ARG2,ARG3,ARG4,START,CLWRD
      DIMENSION ARG1(*),ARG2(*),ARG3(*),ARG4(*),NPTVCT(2,9),NCLR(2)
      EQUIVALENCE (NCLR(1),CLR)
      INTEGER BCDF
      LOGICAL FIRST
      SAVE FIRST,START,CLWRD,NORM,NOMO
C
      DATA ICLDM/100/
C
      DATA FIRST/.TRUE./
C
C
      IF (FIRST) THEN
        START = BCDF('STAR')
        CLWRD = BCDF('CLDA')
        NORM  = BCDF('NORM')
        NOMO  = BCDF('NOMO')
        FIRST = .FALSE.
      ENDIF
      DO 2 I=1,9
      NPTVCT(1,I)=BCDF(PNTVCT(I)(1:4))
    2 CONTINUE
      IF(ARG2(1).NE.CLWRD)GOTO 10
      ITYP=ARG4(1)
      IF(ITYP.EQ.NORM)GOTO 75
      IF(ITYP.NE.START.AND.ITYP.NE.NOMO)GOTO 5
      GOTO 100
C
C CLDAT/TP,TA,TV,...ETC.
C
    5 ICLCOD=1
      J=ITYP
      GOTO 85
C
   10 IF(ARG1(1).NE.1)GOTO 80
      NCLR(1)=ARG2(1)
      NCLR(2)=ARG2(2)
      J=ARG4(1)
      IF(ITYP.NE.START) GOTO 50
C
C CLDAT/START,IDX,.........
C
      ICLIDX=CLR
      DO 20 ICLINE=1,ICLCNT
      IF(ICLTAB(1,ICLINE).NE.ICLIDX)GOTO 20
C WARNING DIAGNOSTIC 94
C MULTIPLE DEFINED CLDAT-SECTION. FORMER SECTION DELETED.
      CALL ERROR(94,'CLDAT   ')
      GOTO 40
   20 CONTINUE
C IS ICLTAB FILLED ?
      IF(ICLCNT.LT.ICLDM)GOTO 30
C ERROR DIAGNOSTIC 95
C ARRAY ICLTAB FILLED. USE A FORMER DEFINED INDEX OR REDIMENSION ARRAY.
      CALL ERROR(95,'CLDAT   ')
      GOTO 100
   30 ICLCNT=ICLCNT+1
      ICLINE =ICLCNT
   40 CLDFG=.TRUE.
      ICLCOD=1
      ICLTAB(1,ICLINE)=ICLIDX
      ICLTAB(2,ICLINE)=0
      ICLTAB(3,ICLINE)=ICLCOD
      ICLTAB(4,ICLINE)=ICLBLK+1
      ICLTAB(5,ICLINE)=ICLRCD+3
      NUMCNT=0
      IF(J.EQ.0)GOTO 100
      GOTO 85
C
C CLDAT/NOMORE,IDX
C
   50 II=CLR
C WARNING DIAGNOSTIC 94
C CLDAT INDEXES ARE DIFFERENT. FIRST INDEX REMAINS VALID.
   70 IF(II.NE.ICLIDX)CALL ERROR(94,'CLDAT   ')
      ICLTAB(2,ICLINE)=ICLTAB(2,ICLINE)+NUMCNT
      CLDFG=.FALSE.
C
C CLDAT/NORMAL
C
   75 ICLCOD=0
      GOTO 100
C
   80 IF(ICLCOD.EQ.0)GOTO 100
      J=ARG2(1)
   85 K=ARG4(1)
      DO 90 II=1,9
      IF(J.NE.NPTVCT(1,II).AND.K.NE.NPTVCT(1,II))GOTO 90
      IF(MOD(ICLCOD,IPTVEC(II)).NE.0)ICLCOD=ICLCOD*IPTVEC(II)
      IF(CLDFG)ICLTAB(3,ICLINE)=ICLCOD
   90 CONTINUE
C
C OUTPUT CLDAT COMMAND ON EXFILE
C
  100 CALL APT299(ARG1,ARG2,ARG3,ARG4)
C
      RETURN
      END
