**** SOURCE FILE : ALTCMV.ORG   ***
*
      SUBROUTINE ALTCMV(JC,TN,S,IP,ID,VCS,DCS,EPS1CS,CMOVE,LRET)
C
C.... COMPUTE CMOVE BY ALTERNATIVE METHODS
C
C ARGUMENTS:
C           JC      FLAG INDICATING GAUSS FAILURE CONDITION USED
C                   TO SELECT ALTERNATIVE METHOD FOR COMPUTING CMOVE
C           TN      TOOL NORMAL DIRECTIONS
C           S       DIRECTED DISTANCES
C           IP      INDEX FOR PS
C           ID      INDEX FOR DS
C           VCS     CHECK SURFACE DIRECTION
C           SCS     CHECK SURFACE DIRECTED DISTANCE
C           EPS1CS  TOLERANCE EQ .1*TAU FOR CHECK SURFACE
C           CMOVE   MOVE REQUIRED TO BRING TOOL INTO CONTACT WITH
C                   3 SURFACES
C           LRET    RETURN FLAG = .TRUE. IF WITHIN TOLERANCE WHEN
C                                        PS PARALLEL TO CS
C                               = .FALSE. OTHERWISE
C
      INCLUDE 'ZNUMBR.INC'
C
      INTEGER JC,IP,ID,IVZ,J,I,II
      DOUBLE PRECISION TN,S,VCS,DCS,EPS1CS,CMOVE,C1,C2
      DIMENSION TN(3,5),S(5),VCS(3),CMOVE(3)
      LOGICAL LRET
C
      LRET=.FALSE.
      IVZ=SIGN(1,JC)
      J=ABS(JC)
C
      IF (J.EQ.1) THEN
C.... SELECT LARGER OF PS AND DS MOVES
        IF (ABS(S(IP)).GT.ABS(S(ID))) THEN
          I=IP
        ELSE
          I=ID
        ENDIF
C.... SET MOVE TO .9*LARGER S(I) + CHECK SURF MOVE
        C1=Z9EM1*S(I)
        C2=DCS
        CALL SETMOV(CMOVE,C1,TN(1,I),C2,VCS)
C
      ELSE IF (J.EQ.12) THEN
C
C.... PS PARALLEL TO DS
C
C.... SELECT LARGER OF PS AND DS MOVES
        IF (ABS(S(IP)).GT.ABS(S(ID))) THEN
          I=IP
          II=ID
        ELSE
          I=ID
          II=IP
        ENDIF
C
        IF ( (S(I)*S(II)*IVZ).GT.0) THEN
C.... SET MOVE TO .9*LARGER + .9*CHECK SURF MOVE
          C1=Z9EM1*S(I)
        ELSE
C.... SET MOVE TO .9*(MEAN S(I) IN DIRECTION OF LARGER)
C                           + .9*CHECK SURF MOVE
          C1=Z9EM1*SIGN(Z1,S(I))*Z5EM1*(S(I)+S(II))
        ENDIF
        C2=Z9EM1*DCS
        CALL SETMOV(CMOVE,C1,TN(1,I),C2,VCS)
C
      ELSE IF (J.EQ.13) THEN
C
C.... PS PARALLEL TO CS
C
C.... COMPUTE .9* MEAN (PS AND CS DISTANCES)
        C1=Z9EM1*Z5EM1*(S(IP)+IVZ*DCS)
        IF (ABS(C1).LT.(Z1EM2*EPS1CS)) THEN
C.... CONSIDER AS SUCCESSFUL MOVE
          LRET=.TRUE.
        ELSE
C.... SET MOVE TO .9* MEAN (PS AND CS DISTANCES) IN PS DIRECTION
C               + .9* DS MOVE
          C2=Z9EM1*S(II)
          CALL SETMOV(CMOVE,C1,TN(1,IP),C2,TN(1,ID))
        ENDIF
C
      ELSE
C
C.... DS PARALLEL TO CS
C
C.... SELECT LARGER OF DS AND CS MOVES
        IF (ABS(S(ID)).GT.ABS(DCS)) THEN
C.... DS LARGER
C.... SET MOVE TO .9*IN DIRECTION OF DS + .9*PS MOVE
          C1=Z9EM1
          C2=Z9EM1*S(IP)
          CALL SETMOV(CMOVE,C1,TN(1,ID),C2,TN(1,IP))
        ELSE
C.... CS LARGER
          IF ((S(IP)*S(ID)*IVZ).GT.0) THEN
C.... SET MOVE TO .9*PS MOVE + .9* CHECK SURF MOVE
            C1=Z9EM1*S(IP)
          ELSE
C.... SET MOVE TO .9* MEAN (PS AND DS DISTANCES) IN PS DIRECTION
C               + .9* CHECK SURF MOVE
            C1=Z9EM1*SIGN(Z1,S(I))*Z5EM1*(S(IP)+S(ID))
          ENDIF
          C2=Z9EM1*DCS
          CALL SETMOV(CMOVE,C1,TN(1,IP),C2,VCS)
        ENDIF
      ENDIF
C
      END
      SUBROUTINE SETMOV(CM,A,V1,B,V2)
C
C.... CALCULATE VECTOR MOVE = A*V1 + B*V2
C
      INTEGER I
      DOUBLE PRECISION CM,A,V1,B,V2
      DIMENSION CM(3),V1(3),V2(3)
C
      DO 10 I=1,3
        CM(I)=A*V1(I)+B*V2(I)
   10 CONTINUE
C
      END
