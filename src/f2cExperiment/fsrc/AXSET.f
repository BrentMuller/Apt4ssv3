**** SOURCE FILE : M0001038.X02   ***
*
      SUBROUTINE AXSET(MODE,FAX,VAX,AX)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
C--PURPOSE IS TO SET AXIS AX TO FAX IF MODE IS 0 OR VAX IF
C--MODE IS NOT ZERO.  IF VAX IS ZERO, AX WILL BE SET TO FAX
C.... IF MODE=2 THEN VAX WILL BE VARIED BY APPLYING ANGLE ALPHA
C                    IN DIRECTION INDICATED BY FAX
      DIMENSION FAX(3),VAX(3),AX(4),FAXN(3)
      CHARACTER*20 BADMSG
      INCLUDE 'TAC.INC'
      DATA ONE,SMAL/1.0D0,1.0D-38/
C
      IF(MODE.NE.0) GO TO 50
C--FIXED AXIS CASE
   10 CONTINUE
      DO 20 I=1,3
   20 AX(I)=FAX(I)
      AX(4)=ONE
      GO TO 100
C
   50 CONTINUE
C---VARIABLE AXIS CASE
      CALL DOTF(SIZ,VAX,VAX)
      IF(SIZ.LT.SMAL) GO TO 10
      FAC=ONE/DSQRT(SIZ)
C--ADJUST SIGN OF AXIS ACCORDING TO SIGN OF MODE
      IF(MODE.LT.0) FAC=-FAC
      DO 60 I=1,3
   60 AX(I)=VAX(I)*FAC
C...NOW APPLY ALPHA IF REQUIRED
      IF (ABS(MODE).EQ.2) THEN
C... NORMALIZE FAX
        CALL VNORM(FAX,FAXN)
        DO 70 I=1,3
          AX(I)=COSA*AX(I)+SINA*FAXN(I)
   70   CONTINUE
      ENDIF
C
  100 CONTINUE
      IF(IBUG.NE.11) GO TO 1999
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER AXSET'
      CALL CPRINT(BADMSG)
      CALL BAD(1,0,'MODE',MODE)
      CALL BAD(-3,1,'AX  ',AX)
 1999 CONTINUE
      RETURN
      END
