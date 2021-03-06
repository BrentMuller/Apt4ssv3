**** SOURCE FILE : M0011487.V03   ***
*
C
C.....FORTRAN SUBROUTINE     CLDATF
C
C PURPOSE      TO RETRIEVE THE U OR V COORDINATE OR THE PATCH NUMBER
C              OF THE PART OR DRIVE SURFACE OF A PREVIOUS CL DATA
C              FROM EXFILE AND STORE IT IN RESULT.
C
C LINKAGE      CALL CLDATF(RESULT,ARG1,ARG2,ARG3)
C
C ARGUMENTS    RESULT  REAL VARIABLE TO CONTAIN THE DESIRED SCALAR.
C              ARG1    REAL NUMBER OF CLDAT SECTION.
C              ARG2    INTEGER DESIRED SCALAR NAME.
C              ARG3    REAL NUMBER OF DESIRED POINT.
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          ATAPER
C
      SUBROUTINE CLDATF(RESULT,ARG1,ARG2,ARG3)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      INTEGER ARG2
C
      INCLUDE 'TOTAL.INC'
C
      DIMENSION P(6),NARG2(6)
C
      LOGICAL FIRST
      INTEGER BCDF
      SAVE FIRST,NARG2
C
      DATA FIRST/.TRUE./
C
      IF (FIRST)THEN
        NARG2(1) = BCDF('UDS ')
        NARG2(2) = BCDF('VDS ')
        NARG2(3) = BCDF('PDS ')
        NARG2(4) = BCDF('UPS ')
        NARG2(5) = BCDF('VPS ')
        NARG2(6) = BCDF('PPS ')
        FIRST = .FALSE.
      ENDIF
C
      DO 10 II=1,6
      IF(NARG2(II).EQ.ARG2)GOTO 20
   10 CONTINUE
C
   15 CALL ERROR(93,'CLDATF  ')
      RESULT=0.D0
C
      RETURN
   20 ITYP =8+II/4
      ISCT =ARG1
      IPNT =ARG3
      CALL ATAPER(P,IPNT,ISCT,ITYP,IEE)
      IF(IEE.EQ.0)GOTO 30
      GOTO 15
   30 IF(II.GT.3)II=II-3
      RESULT=P(II)
   40 RETURN
      END
