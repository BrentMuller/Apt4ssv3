**** SOURCE FILE : M0002891.V03   ***
*
C.....FORTRAN SUBROUTINE              SPATF                16.10.78 EC
C
C              FORTRAN SUBROUTINE SPATF
C PURPOSE      COMPUTATION OF THE SPAT-PRODUCT OF 3 VECTORS
C
C CALLING SEQ.: CALL SPATF(RES,ARG1,ARG2,ARG3)
C
C ARGUMENTS    RES     FIELD FOR RESULT
C              ARG1    FIELD OF 1ST VECTOR
C              ARG2    FIELD OF 2ND VECTOR
C              ARG3    FIELD OF 3RD VECTOR
C
C SUBPROGRAMS  TYPE                ENTRY
C              LOGICAL FUNCTION    CKDEF
C              SUBROUTINE          ERROR
C              SUBROUTINE          UNPACK
C              SUBROUTINE          UNDEF
      SUBROUTINE SPATF(RES,ARG1,ARG2,ARG3)
      DOUBLE PRECISION RES(*),ARG1(*),ARG2(*),ARG3(*)
      LOGICAL CKDEF
      INTEGER IS(20)
      DATA IS/1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1/
      IF(CKDEF(ARG1).OR.CKDEF(ARG2).OR.CKDEF(ARG3))GOTO 30
      CALL UNPACK (ARG1,MODE,ISI,ISU)
      IF(MODE.LT.1.OR.MODE.GT.20.OR.IS(MODE).NE.1) GOTO 30
      CALL UNPACK (ARG2,MODE,ISI,ISU)
      IF(MODE.LT.1.OR.MODE.GT.20.OR.IS(MODE).NE.1) GOTO 30
      CALL UNPACK (ARG3,MODE,ISI,ISU)
      IF(MODE.LT.1.OR.MODE.GT.20.OR.IS(MODE).NE.1) GOTO 30
      RES(1)=ARG1(1)*(ARG2(2)*ARG3(3)-ARG2(3)*ARG3(2))
     1   +ARG1(2)*(ARG2(3)*ARG3(1)-ARG2(1)*ARG3(3))
     2   +ARG1(3)*(ARG2(1)*ARG3(2)-ARG2(2)*ARG3(1))
      RETURN
C     'AT LEAST ONE OF THE VECTORS UNDEFINED OR WRONG INPUT'
   30 CALL ERROR(54,'SPATF   ')
      CALL UNDEF(RES(1))
      RETURN
      END
