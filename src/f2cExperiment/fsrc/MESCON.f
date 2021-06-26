**** SOURCE FILE : M0001079.W01   ***
*
      SUBROUTINE MESCON(SURF,U,V,NPAT,U1,V1,MODE)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
C--PURPOSE IS TO CONVERT GLOBAL MESH COORDINATES U,V
C--INTO LOCAL PATCH NUMBER(NPAT) AND LOCAL PATCH COORDINATES
C--U1,V1 IF MODE IS 1.  OTHERWISE THE REVERSE IF MODE IS 2
      DIMENSION SURF(*)
      CHARACTER*20 BADMSG
      DATA ONE/1.0D0/
      DATA TWO/2.D0/
C
      NUMSPL=SURF(9)
      NUMCRS=SURF(10)
      ACRS=SURF(10)-TWO
      ASPL=SURF(9)-TWO
C
      IF(MODE.GT.1) GO TO 100
C--CONVERT GLOBAL U,V TO LOCAL PATCH NUMBER NPAT AND LOCAL U1,V1
      IU=1
      IF(U.LT.ONE) GO TO 10
      IU=NUMCRS-1
      IF(U.GE.ACRS) GO TO 10
      IU=IDINT(U)+1
   10 CONTINUE
      BASE=IU-1
      U1=U-BASE
C
      IV=1
      IF(V.LT.ONE) GO TO 20
      IV=NUMSPL-1
      IF(V.GE.ASPL) GO TO 20
      IV=IDINT(V)+1
   20 CONTINUE
      BASE=IV-1
      V1=V-BASE
C
      NPAT=IU+(IV-1)*(NUMCRS-1)
      GO TO 999
C
  100 CONTINUE
C--CONVERT NPAT,U1,V1 TO GLOBAL U,V
      IU=MOD(NPAT-1,NUMCRS-1)+1
      IV=(NPAT-1)/(NUMCRS-1)+1
      U=U1+IU-1
      V=V1+IV-1
C
  999 CONTINUE
      IF(IBUG.NE.11) GO TO 1999
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER MESCON'
      CALL CPRINT(BADMSG)
      CALL BAD(1,1,'U   ',U)
      CALL BAD(1,1,'V   ',V)
      CALL BAD(1,0,'NPAT',NPAT)
      CALL BAD(1,1,'U1  ',U1)
      CALL BAD(-1,1,'V1  ',V1)
      CALL BAD(-1,0,'MODE',MODE)
 1999 CONTINUE
      RETURN
      END