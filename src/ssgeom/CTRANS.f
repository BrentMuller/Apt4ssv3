**** SOURCE FILE : M0001059.V06   ***
*
      SUBROUTINE CTRANS(PROFIL,CROS,KCASE,MAXSRF,SURF,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---      PROFIL =INPUT SYNTHETIC PROFILE CURVE
C---      CROS = INPUT SYNTHETIC CROSS COMMAND CURVE
C---      KCASE =INPUT  TYPE OF CROSS TRANSFORMATION TO USE
C---         =1 GIVES TRANSL, =2 GIVES XYROT, =3 GIVES YZROT
C---         =4 GIVES ZXROT, =5 GIVES SCALE
C---      MAXSRF =INPUT IS THE MAXIMUM SPACE AVAILABLE FOR SURF
C---      SURF IS THE OUTPUT ARRAY WHICH CONTAINS THE SURFACE
C---      (LESS TOPOLOGY TABLE)
C---      IRR =OUTPUT, IF NON ZERO ON RETURN INDICATES ERROR.
C---      THIS SUBROUTINE ACCEPTS AN INPUT OF A PROFILE CURVE
C---      PROFIL OF N ARCS AND A CROSS CURVE CROS OF K ARCS.
C---      A MESH-LIKE SURFACE OF N*K RATIONAL BICUBIC PATCHES
C---      IS CONSTRUCTED BY TRANSFORMING EACH OF THE PROFILE ARCS
C---      BY THE CROSS COMMAND CURVE ARCS.  THE IMPLIED SPLINE
C---      DIRECTION IS DETERMINED BY THE PROFILE CURVE AND
C---      THE CROSS DIRECTION BY THE CROSS COMMAND CURVE.
C
      DIMENSION PROFIL(*),CROS(*),SURF(*)
C
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
C
C---      THE FOLLOWING ARRAYS ARE USED TO HOLD THE SELECTOR
C---      MATRIX BSEL AND BOTH INTERIM AND FINAL RATIONAL BICUBIC
C---      PATCH MATRICES BMAT.
      DIMENSION BSEL(16,4),BMAT(16,4),TRN(16)
C---
C---      THE FOLLOWING ARRAYS HOLD INFORMATION NECESSARY TO
C---      GENERATE SELECTOR MATRICES BASED ON THE CASE(KCASE)
      DIMENSION IB(89),BX(2)
      DATA IB/
     X 101,4,1,13,1,102,8,1,14,1,103,12,1,15,1,104,16,1,9999,
     X 201,1,1,6,2,202,2,1,5,1,203,12,1,15,1,204,16,1,9999,
     X 301,4,1,13,1,302,6,1,11,1,303,7,1,10,1,304,16,1,9999,
     X 401,3,2,9,1,402,8,1,14,1,403,1,1,11,1,404,16,1,9999,
     X 501,1,1,502,6,1,503,11,1,504,16,1,9999/
      DATA IBMAX/89/
      DATA IEND/9999/
C---     THE FOLLOWING ARRAY HOLDS REAL VALUES WHICH IB POINTS TO.
      DATA NBX/2/
      DATA BX/1.0D0,-1.0D0/
      DATA ZERO,ONE/0.0D0,1.0D0/
C
C---     THE SIZE OF THE HEADER TABLE AND NUMBER OF ARCS FOR BOTH CURVES
      NHDPRO=PROFIL(2)
      NARCP=PROFIL(4)
      NHDCRS=CROS(2)
      NARCC=CROS(4)
C***      CHECK FOR ENOUGH ROOM FOR SURFACE
      IRR=1
      NPAT=NARCP*NARCC
      IF(10+NPAT*74.GT.MAXSRF) GO TO 990
C---     SET UP THE BSEL MATRIX FOR THIS KCASE(LOGIC IS USED
C---     TO PREVENT STORING MANY COMPLETE BSEL-S)
      DO 101 L=1,4
      DO 101 K=1,16
  101 BSEL(K,L)=ZERO
C---      NOW SKIM THRU THE IB ARRAY TO PICK UP NONZERO BSEL VALUES
      I=1
  201 CONTINUE
C***     ERROR IN IB SET-UP
      IRR=2
      IF(I.GT.IBMAX) GO TO 990
      IF(IB(I)/100.EQ.KCASE) GO TO 203
      I=I+1
      GO TO 201
  203 CONTINUE
      IF(IB(I).EQ.IEND) GO TO 210
      IF(IB(I).LT.100) GO TO 205
      JMAT=MOD(IB(I),100)
      I=I+1
      GO TO 203
  205 CONTINUE
      JVAL=IB(I+1)
      IVAL=IB(I)
C***     INVALID INDEX, SYSTEM ERROR
      IRR=3
      IF(IVAL.LT.1.OR.IVAL.GT.16) GO TO 990
      IF(JMAT.LT.1.OR.JMAT.GT.4) GO TO 990
      IF(JVAL.LT.1.OR.JVAL.GT.NBX) GO TO 990
C
      BSEL(IVAL,JMAT)=BX(JVAL)
      I=I+2
      GO TO 203
  210 CONTINUE
C
      IF(IBUG.NE.11) GO TO 212
      DO 213 L=1,4
      DO 213 K=1,4
      KK=(K-1)*4+1
      CALL BAD(-4,1,'BSEL',BSEL(KK,L))
  213 CONTINUE
  212 CONTINUE
C
C---      FIRST INITIALIZE SURFACE HEADER DATA
      SURF(1)=ZERO
      APAT=NPAT
      SURF(2)=APAT*64.
      SURF(3)=APAT*4.
      SURF(4)=APAT
      SURF(5)=2.
      SURF(6)=5.
      SURF(7)=ONE
      SURF(8)=APAT*74.+10.
      SURF(9)=NARCC+1
      SURF(10)=NARCP+1
C---     SET UP PATCH HEADER TABLE
      AFX=10.+APAT*6.+1.
      ILOC=10
      DO 310 L=1,NPAT
      DO 320 K=1,4
  320 SURF(ILOC+K)=4.
      SURF(ILOC+5)=AFX
      SURF(ILOC+6)=ZERO
      ILOC=ILOC+6
      AFX=AFX+64.
  310 CONTINUE
C
C---     MAIN LOOP  COMPUTE EACH RATIONAL PATCH AND PLACE IN SURF
      DO 301 IC=1,NARCC
      LOCC=(NHDCRS+IC-1)*24+1
      IF(IBUG.EQ.11) CALL BAD(-16,1,'CROS',CROS(LOCC))
      DO 301 IP=1,NARCP
      LOCP=(NHDPRO+IP-1)*24+1
C
C---     TRANSPOSE THE PROFILE MATRIX
      IF(IBUG.EQ.11) CALL BAD(-16,1,'PROF',PROFIL(LOCP))
      CALL TRANSP(PROFIL(LOCP),TRN,4)
      IF(IBUG.EQ.11) CALL BAD(-16,1,'TRN ',TRN)
C
      DO 302 J=1,4
C---     NOTE THAT SMMULT(A,B,C) GIVES C=B*A
      CALL SMMULT(4,4,4,3,CROS(LOCC),BSEL(1,J),BMAT(1,J))
C---      BMAT=BSEL*CROS, THEN BMAT=BMAT*TRN
      CALL SMMULT(4,4,4,3,BMAT(1,J),TRN,BMAT(1,J))
C---     NOW BACK TRANSPOSE THE BMAT RESULT
      CALL TRANSP(BMAT(1,J),BMAT(1,J),4)
      IF(IBUG.NE.11) GO TO 314
      DO 315 L=1,4
      LL=(L-1)*4+1
      CALL BAD(-4,1,'BMAT',BMAT(LL,J))
  315 CONTINUE
  314 CONTINUE
  302 CONTINUE
C---      NOW TRANSFER THE RATIONAL MATRIX BMAT TO SURF
      IPAT=(IC-1)*NARCP+IP
      LOC=10+IPAT*6-1
      LOC=SURF(LOC)
      DO 303 JJ=1,4
      DO 303 KK=1,16
      SURF(LOC)=BMAT(KK,JJ)
      LOC=LOC+1
  303 CONTINUE
C
  301 CONTINUE
C
  980 CONTINUE
      IRR=0
      GO TO 999
C
  990 CONTINUE
      CALL BAD(-1,0,'CTRN',IRR)
      GO TO 999
C
  999 CONTINUE
C
      IF(IBUG.NE.11) GO TO 998
      NN=NPAT*74+10
      CALL BAD(-NN,1,'SURF',SURF)
  998 CONTINUE
C
      RETURN
      END
