**** SOURCE FILE : M0004287.V03   ***
*
      SUBROUTINE CRVLEN(PA,PB,TA,TB,A,B,NUMINT,MXCT,CTOLR,ILEVEL)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---MAIN ROUTINE TO DETERMINE OPTIMUM VECTOR LENGTHS FOR TANGENT
C---VECTORS OF A CUBIC.  INPUT CONSTRAINTS INCLUDE
C--- PA,PB  START AND END POINTS OF PARAMETRIC CUBIC
C--- TA,TB  START AND END UNIT TANGENT VECTORS
C--- NUMINT IS NUMBER OF SIMPSON INTERVALS FOR DETERMINING AREA
C--- MXCT IS THE MAXIMUM NUMBER OF NEWTON-RHAPSON ITERATIONS
C--- CTOLR IS THE RATIO OF CHANGE FOR TERMINATION OF ITERATIONS
C--- ILEVEL CONTROLS THE LEVEL OF CALCULATION FOR A,B
C--- =1 CHORD LENGTH, =2 MINIMIZE DDR, =3 NEWTON RHAPSON
C--- A,B ARE THE OUTPUT LENGTHS OF TANGENTS.
C--- A,B ARE SELECTED TO MINIMZE INTEGRAL OF K*K*DS OVER 0,1
C--- METHOD IS NEWTON-RHAPSON WITH ITERATIONS AND
C--- SIMPSONS RULE TO DETERMINE APPROXIMATE AREA
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      DIMENSION PA(3),PB(3),TA(3),TB(3)
      DIMENSION SUM(6),AREA(6),DIF(3)
      CHARACTER*20 BADMSG
C
      DATA ZERO,ONE,SMAL/0.0D0,1.0D0,1.0D-15/
C
      DO 5 I=1,3
    5 DIF(I)=PB(I)-PA(I)
      CALL VNORM(TA,TA)
      CALL VNORM(TB,TB)
      ISTART=1
      IEND=2*NUMINT+1
      H=1./(2.*NUMINT)
      H3=H/3.
      W=H+H
C
C---      INITIAL ESTIMATE OF A,B IS FROM CHORD LENGTH
      CALL DOTF(A,DIF,DIF)
      A=DSQRT(A)
      B=A
      IF(ILEVEL.LE.1) GO TO 70
C---      A SECOND INITIAL ESTIMATE IS FROM MINIMIZE DDR AT ENDS
      CALL DOTF(X1,TA,DIF)
      CALL DOTF(X2,TB,DIF)
      CALL DOTF(X3,TA,TB)
      TEMP=3./(4.-X3**2)
      A1=(2.*X1-X3*X2)*TEMP
      B1=(2.*X2-X3*X1)*TEMP
C---      IF A1 OR B1 IS NEGATIVE, IGNORE THESE VALUES
      IF(A1.LT.SMAL.OR.B1.LT.SMAL) GO TO 7
      A=A1
      B=B1
    7 CONTINUE
C---      NOW SAVE THESE A,B ESTIMATES AS A BACKUP
      ASAVE=A
      BSAVE=B
C
      IF(ILEVEL.LE.2) GO TO 70
      ICT=0
C
   10 CONTINUE
C---      ICT IS THE COUNT OF THE NUMBER OF NEWTON RHAPSON ITERATIONS
      IF(ICT.GT.MXCT) GO TO 70
      DO 20 I=1,6
   20 AREA(I)=ZERO
C
C---      PERFORM INTEGRATION TO OBTAIN ESTIMATES OF TENSION AND DERIVS.
      DO 30 I=ISTART,IEND
      SIMFAC=4.
      IF(MOD(I,2).EQ.1) SIMFAC=2.
      IF(I.EQ.ISTART.OR.I.EQ.IEND) SIMFAC=1.
      SIMFAC=SIMFAC*H3
      MODE=0
      IF(I.EQ.ISTART) MODE=1
      U=(I-1.)*H
C
      CALL ADER(DIF,TA,TB,A,B,U,MODE,SUM)
C
      IF(IBUG.EQ.11) CALL BAD(-6,1,'SUM ',SUM)
      DO 40 J=1,6
   40 AREA(J)=SIMFAC*SUM(J)+AREA(J)
C
   30 CONTINUE
C
      IF(IBUG.EQ.11) CALL BAD(-6,1,'AREA',AREA)
C
C---      ESTIMATE CHANGE DA,DB IN A,B TO REDUCE TENSION IN CURVE
      DET=AREA(4)*AREA(6)-AREA(5)**2
      IF(DABS(DET).GT.SMAL) GO TO 50
C---      USE THE PREVIOUS VALUES FOR A,B
      A=ASAVE
      B=BSAVE
      GO TO 70
C
   50 CONTINUE
C
      DA=(-AREA(2)*AREA(6)+AREA(3)*AREA(5))/DET
      DB=(-AREA(4)*AREA(3)+AREA(5)*AREA(2))/DET
C
      RATIO=DSQRT(DA**2+DB**2)/DSQRT(A**2+B**2)
      IF(IBUG.NE.11) GO TO 93
      CALL BAD(-1,0,' ',0)
      BADMSG=' ENTRY TO CRVLEN'
      CALL CPRINT(BADMSG)
      CALL BAD(1,1,'A   ',A)
      CALL BAD(1,1,'B   ',B)
      CALL BAD(1,1,'DA  ',DA)
      CALL BAD(1,1,'DB  ',DB)
      CALL BAD(-1,1,'RATI',RATIO)
   93 CONTINUE
      A=A+DA
      B=B+DB
      IF(RATIO.LT.CTOLR) GO TO 70
C
      ICT=ICT+1
      GO TO 10
C
   70 CONTINUE
C---      A NEGATIVE A OR B IS NOT ACCEPTABLE SO USE THE BACKUP
C---      VALUES IF A OR B ARE NEGATIVE
      IF(A.GT.ZERO.AND.B.GT.ZERO) GO TO 999
      A=ASAVE
      B=BSAVE
  999 CONTINUE
      IF(IBUG.NE.11) GO TO 998
      CALL BAD(-1,0,' ',0)
      BADMSG=' EXIT FROM CRVLEN'
      CALL CPRINT(BADMSG)
      CALL BAD(1,1,'A   ',A)
      CALL BAD(1,1,'B   ',B)
      CALL BAD(1,1,'ASAV',ASAVE)
      CALL BAD(-1,1,'BSAV',BSAVE)
      CALL BAD(-1,0,' ',0)
  998 CONTINUE
C
      RETURN
      END
