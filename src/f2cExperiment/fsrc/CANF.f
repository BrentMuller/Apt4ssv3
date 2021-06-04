**** SOURCE FILE : M0002880.V03   ***
*
C.....FORTRAN SUBROUTINE             CANF....             16.10.78  EC
C
C              FORTRAN SUBROUTINE CANF
C
C ZWECK        EXTRAKTION VON KANONISCHEN ELEMENTEN
C
C VERKNUEPFUNG CALL CANF (RES, ORT, ARG)
C
C ARGUMENTE    RES     REAL VARIABLE FUER RESULTAT
C              ORT     STELLENANGABE IN DER KANONISCHEN FORM
C              ARG     FELD MIT DER KANONISCHEN FORM
C
C UNTEPROGR.:  TYPE                ENTRY
C              LOGICAL FUNCTION    CKDEF
C              SUBROUTINE          ERROR
C              SUBROUTINE          UNPACK
C              SUBROUTINE          UNDEF
C              SUBROUTINE          TRANSF
      SUBROUTINE CANF (RES,ORT,ARG)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION ARG(*),A(12),RES(*)
      INTEGER IR(20)
      LOGICAL CKDEF
      DATA IR/4,4,5,5,2,1,1,1,5,1,0,0,0,1,0,0,0,0,2,3/
C...     CHECK OB KANONISCHE FORM DEFINIERT
      IF (CKDEF(ARG)) GO TO 20
C...     KONTROLLE OB KANONISCHE FORM LANG GENUG
      I=ORT
      CALL UNPACK(ARG(1),MODE,ISIZE,ISUB)
      IF(I.LE.0)GOTO22
      IF(I.GT.ISIZE)GOTO21
C...     KONTROLLE OB TRANSFORMIERT WERDEN KANN UND TRANSFORMATION
      IF(MODE.EQ.18)GOTO 10
      IF(MODE.LE.0.OR.MODE.GT.20.OR.IR(MODE).EQ.0)GOTO 20
      CALL TRANSF (A,ARG,IR(MODE),ISIZE,0)
      RES(1)=A(I)
      RETURN
C   MATRIX-ABGRIFF
   10 RES(1)=ARG(I)
      RETURN
C
C...   'GEOMETRIE NICHT DEFINIERT'
   20 CALL ERROR( 39,'CANF    ')
      GOTO 23
C...   'KANONISCHE FORM ZU KURZ FUER INDEX ODER INDEX NICHT DEFINIERT'
   21 CALL ERROR( 40,'CANF    ')
      GOTO 23
C...   'INDEX KLEINER ODER GLEICH NULL'
   22 CALL ERROR( 41,'CANF    ')
   23 CALL UNDEF(RES(1))
      RETURN
      END
