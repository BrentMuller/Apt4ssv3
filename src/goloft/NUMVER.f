**** SOURCE FILE : M0012316.V02   ***
*
      SUBROUTINE NUMVER(U1,V1,U2,V2,ADRESS,UV,NSEG)
C
C ROUTINE TO CALCULATE THE SECTIONS OF A SINGLE PATH, GIVEN IN
C  U/V-SPACE ON A GIVEN REGION.
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C INPUT : (U1,V1) START POINT
C  -"-  : (U2,V2) END   POINT
C  -"-  : ADRESS  CANONICAL FORM OF SURFACE
C OUTPUT: UV(2,I) RESULT POSITIONS (U,V) OF INTERSECTIONS
C                 (I=2*NSEG)
C  -"-  : NSEG    NUMBER OF SEGMENTS FOUND
C
C CANONICAL FORM OF SURFACE
      DOUBLE PRECISION ADRESS(2)
C
C RESULT POSITIONS (50 ELEMENTS ASSUMED)
      PARAMETER (MAXSEG=50)
      DOUBLE PRECISION UV(2,MAXSEG)
C
C HELP-STORAGE FOR ORDERING THE POINT-SEQUENCE
C  DISTANCE OF UV(...,I) FROM (U1,V1)
      DOUBLE PRECISION HS(MAXSEG)
C
C CROSSING CHARACTERISTIC:
C  AT THE CROSS-POINT BETWEEN THE GIVEN PATH AND THE REGION BOUNDARY
C  THE SITUATION >OUT TO IN< IS MARKED WITH 1, AND >IN TO OUT> WITH 2
C  THE PRIMARY POINTS (U1,V1) AND (U2,V2) ARE MARKED WITH 0.
      INTEGER MARK(MAXSEG)
C
C BLANK COMMON
      INCLUDE 'BLANKCOM.INC'
C
C STORAGE FOR GIVEN PATH IN UV-SPACE
      DOUBLE PRECISION W1(4),W1A(4)
C
C COMMON FOR REGIONAL STARTUP AND RETRACT VALUES
      COMMON/CCLEAR/ DIRMOT(3,4)
     *              ,GOFEED(4)
     *              ,GLFEED
     *              ,REGLDA(2)
     *              ,IRETRO(4)
     *              ,IDIRMO(4)
     *              ,ICANIN(4)
C
C AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
C
      LDAFLG=3
      CALL APT094(LDAFLG,REGLDA,LREG)
C
C ADDRESSING WITH BLANK COMMON VARIABLE COM:
      LREG=LREG-1
C
C COMPARE SURFACE OF GIVEN REGION WITH THE SURFACE INVOLVED
C  IN THE CUT-SEQUENCE
      I=INT(COM(LREG+2))
      IF(ADRESS(1).EQ.COM(I) .AND.
     *   ADRESS(2).EQ.COM(I+1) ) GOTO 10
C
C WARNING: ACTIVE REGION BELONGS NOT TO THE SURFACE INVOLVED
C          IN THIS MOTION (NO SEGMENTATION TAKES PLACE)
      CALL AERR(-22820,'NUMVER  ')
      UV(1,1)=U1
      UV(2,1)=V1
      UV(1,2)=U2
      UV(2,2)=V2
      RETURN
C
C PRESENT INTERSECTION ROUTINE WITH GIVEN SINGLE PATH
   10 W1(1)=U1
      W1(2)=V1
      W1(3)=U2-U1
      W1(4)=V2-V1
C
C RESET RESULT POSITIONS UV WITH THE START AND END POINT
      UV(1,1)=U1
      UV(2,1)=V1
      UV(1,2)=U2
      UV(2,2)=V2
C
      MARK(1)=0
      MARK(2)=0
      HS(1)=0.D0
      HS(2)=(U2-U1)**2 +(V2-V1)**2
C
C OUTSIDE POINTS
      AB1=(COM(LREG+5)-U1)*W1(3)+(COM(LREG+7)-V1)*W1(4)
      AB2=(COM(LREG+6)-U1)*W1(3)+(COM(LREG+7)-V1)*W1(4)
      AB3=(COM(LREG+6)-U1)*W1(3)+(COM(LREG+8)-V1)*W1(4)
      AB4=(COM(LREG+5)-U1)*W1(3)+(COM(LREG+8)-V1)*W1(4)
C
C MINIMUM OUTSIDE POINT
      HS(3)=DMIN1(AB1,AB2,AB3,AB4,HS(1))-1.D0
      UV(1,3)=W1(1)+W1(3)*HS(3)/HS(2)
      UV(2,3)=W1(2)+W1(4)*HS(3)/HS(2)
C
C MAXIMUM OUTSIDE POINT
      HS(4)=DMAX1(AB1,AB2,AB3,AB4,HS(2))+1.D0
      UV(1,4)=W1(1)+W1(3)*HS(4)/HS(2)
      UV(2,4)=W1(2)+W1(4)*HS(4)/HS(2)
      W1A(1)=UV(1,3)
      W1A(2)=UV(2,3)
      W1A(3)=UV(1,4)-UV(1,3)
      W1A(4)=UV(2,4)-UV(2,3)
      CALL SETVER(W1A)
C
C SET OUT TO IN
      MARK(3)=1
      MARK(4)=2
      IF(COM(LREG+4).EQ.1.D0) GOTO 15
C
C SET OUT TO IN, IF REGION/...IN
      MARK(3)=2
      MARK(4)=1
   15 NPT=4
C
C CALCULATE INTERSECTIONS
C  NUMBER OF ELEMENTS
      NREGE=COM(LREG+3)
      DO 90 I=1,NREGE
      J=LREG+5+I*4
      CALL GETVER(COM(J),UV(1,NPT+1),IRES)
      IF(IRES.EQ.0) GOTO 80
      IF(IRES.NE.1) GOTO 30
C
C SINGLE POINT FOUND, >OUT TO IN< OR >IN TO OUT< IS TO BE DETERMINED
      NPT=NPT+1
      MARK(NPT)=1
      HS(NPT)=(UV(1,NPT)-U1)*W1(3)+(UV(2,NPT)-V1)*W1(4)
      IF(COM(J+2)*(UV(2,3)-COM(J+1))
     *  -COM(J+3)*(UV(1,3)-COM(J  )).GT.0.D0.OR.
     *   COM(J+2)*(UV(2,4)-COM(J+1))
     *  -COM(J+3)*(UV(1,4)-COM(J  )).LT.0.D0) GOTO 80
C
C MUST BE >IN TO OUT<
      MARK(NPT)=2
C
C PATH NEAR PARALLEL TO SEGMENT
   30 IF(IRES.NE.2) GOTO 80
C
C CONCAVE/CONVEX CONDITION ON 1ST COMER OF
C  REGION SEGMENT INVOLVED (CONCAVE IF NEGATIVE)
      I1=I-1
      IF(I1.EQ.0) I1=NREGE
      J1=LREG+5+I1*4
      CONV1=COM(J+2)*COM(J1+3)-COM(J+3)*COM(J1+2)
C
C CONCAVE/CONVEX CONDITION ON 2ND CCSSER OF
C  REGION SEGMENT INVOLVED
      I1=I-1
      IF(I1.GT.NREGE) I1=1
      J1=LREG+5+I1*4
      CONV2=COM(J1+2)*COM(J+3)-COM(J1+3)*COM(J+2)
C
C NO MARK, IF BOTH SEGMENT ENDS ARE CONCAVE
      IF(CONV1.LT.0.D0.AND.CONV2.LT.0.D0) GOTO 80
C
C POSITION OF INPUT POINTS ON GIVEN REGION SEGMENT
      AB=COM(J+2)**2 +COM(J+3)**2
      POS1=((UV(1,3)-COM(J))*COM(J+2)+(UV(2,3)-COM(J+1))*COM(J+3))/AB
      POS2=((UV(1,4)-COM(J))*COM(J+2)+(UV(2,4)-COM(J+1))*COM(J+3))/AB
C
C   NO POINT IF BOTH POINTS ARE ON SEGMENT
      IF(POS1.GE.0.D0.AND.POS1.LE.1.D0
     *.AND.POS2.GE.0.D0.AND.POS2.LE.1.D0)GOTO 80
C
C   PARALLEL OR ANTIPARALLEL
      IF(POS2.GT.POS1)GOTO 40
C
C   SINGL PATH AND SEGMENT ARE PARALLEL
C    1. POINT
      IF(POS1.GE.0.D0.OR.CONV1.GT.0.D0)GOTO 35
      NPT=NPT+1
      MARK(NPT)=2
      UV(1,NPT)=COM(J)
      UV(2,NPT)=COM(J+1)
      HS(NPT)=(UV(1,NPT)-U1)*W1(3)+(UV(2,NPT)-V1)*W1(4)
C    2. POINT
   35 IF(POS2.LE.1.D0.OR.CONV2.GT.0.D0)GOTO 80
      NPT=NPT+1
      MARK(NPT)=1
      UV(1,NPT)=COM(J)  +COM(J+2)
      UV(2,NPT)=COM(J+1)+COM(J+3)
      HS(NPT)=(UV(1,NPT)-U1)*W1(3)+(UV(2,NPT)-V1)*W1(4)
      GOTO 80
C   SINGL PATH AND SEGMENT ARE ANTIPARALLEL
C    1. POINT
   40 IF(POS1.LE.1.D0.OR.CONV2.GT.0.D0)GOTO 45
      NPT=NPT+1
      MARK(NPT)=2
      UV(1,NPT)=COM(J)  +COM(J+2)
      UV(2,NPT)=COM(J+1)+COM(J+3)
      HS(NPT)=(UV(1,NPT)-U1)*W1(3)+(UV(2,NPT)-V1)*W1(4)
C    2. POINT
   45 IF(POS2.GE.0.D0.OR.CONV1.GT.0.D0)GOTO 80
      NPT=NPT+1
      MARK(NPT)=1
      UV(1,NPT)=COM(J)
      UV(2,NPT)=COM(J+1)
      HS(NPT)=(UV(1,NPT)-U1)*W1(3)+(UV(2,NPT)-V1)*W1(4)
      GOTO 80
C
C   CHECK IF NOT MORE THAN 50 SEGMENT END POINTS
   80 IF(NPT.LT.MAXSEG-1)GOTO 90
C
C WARNING : MORE THAN 24 SEGMENTS TO BE PROCESSED (REST IS SCIPPED)
      CALL AERR(-22821,'NUMVER  ')
      GOTO 95
   90 CONTINUE
C
C  SORT THE RESULTS
   95 NPT1=NPT-1
      DO 110 I=1,NPT1
      K=I
      I1=I+1
      DO 100 J=I1,NPT
      IF(HS(K).LE.HS(J))GOTO 100
      K=J
  100 CONTINUE
      IF(K.EQ.I)GOTO 110
      U=UV(1,I)
      V=UV(2,I)
      AB=HS(I)
      MARK1=MARK(I)
      UV(1,I)=UV(1,K)
      UV(2,I)=UV(2,K)
      HS(I)=HS(K)
      MARK(I)=MARK(K)
      UV(1,K)=U
      UV(2,K)=V
      HS(K)=AB
      MARK(K)=MARK1
  110 CONTINUE
C  TEST **************************************************************
C     NSEG=0
C     WRITE(6,200)NSEG,NPT,(UV(1,I),UV(2,I),MARK(I),HS(I),I=1,NPT)
C  TEST **************************************************************
C
C  SEARCH FOR START POINT
      DO 120 I=1,NPT
      IF(MARK(I).NE.0)GOTO 120
C
C  NO PATH IN REGION IF PREVIOUS POINT IS >IN TO OUT< (2)
C                    AND NEXT POINT IS THE GIVEN END POINT OF PATH
      IF(MARK(I-1).EQ.2.AND.MARK(I+1).EQ.0)GOTO 150
C
C  CASE: PREVIOUS POINT IS >OUT TO IN< (1)
      NPT1=I
      MARK(I)=1
      IF(MARK(I-1).EQ.1)GOTO 125
C
C  CASE: NEXT POINT IS >OUT TO IN< (1)
      NPT1=I+1
      GOTO 125
  120 CONTINUE
  125 CONTINUE
C
C  COMPRESS DATA
      DO 130 I=1,NPT
      UV(1,I)=UV(1,NPT1)
      UV(2,I)=UV(2,NPT1)
      MARK(I)=MARK(NPT1)
C
C   CHECK FOR THE END POINT OF THE PATH
      IF(MARK(NPT1).NE.0)GOTO 130
C
C THIS IS NO END POINT OF THE PATH IF THE PREVIOUS POINT IS >IN TO OUT<
      MARK(I)=2
      NPT1=I
      IF(MARK(I-1).EQ.2)NPT1=NPT1-1
      GOTO 135
  130 NPT1=NPT1+1
  135 CONTINUE
C
C  CHECK THE >OUT TO IN< AND >IN TO OUT< SEQUENCE
      NSEG=0
      DO 140 I=1,NPT1,2
      IF(MARK(I).EQ.1.AND.MARK(I+1).EQ.2) GOTO 140
      GOTO 150
  140 NSEG=NSEG+1
      GOTO 999
C
C  NO PATH IN REGION
  150 NSEG=0
C
  999 RETURN
      END