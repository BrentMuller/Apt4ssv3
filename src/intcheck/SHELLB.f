**** SOURCE FILE : SHELLB.ORG   ***
*
      SUBROUTINE SHELLB(NN,N3,N4,RCORN1,RCORN2,CV1,CV2,RNET,
     1      SCENT,SRAD,NFLAGS)
C
C     CALCULATES THE FOUR "EDGE" SHELLS FOR A PATCH SPECIFIED BY RNET, E
C     ON CALL:-
C     N3=3
C     N4=4
C     NN      FIRST DIMENSION OF RNET ARRAY
C
C
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C
C.... CORNER POINTS
      DIMENSION RCORN1(N4,N3),RCORN2(N4,N3)
C.... CORNER VECTORS
      DIMENSION CV1(N4,N3),CV2(N4,N3)
C.... NET OF POINTS
      DIMENSION RNET(NN,N3)
C
      DIMENSION V1(3),V2(3)
C
      DIMENSION D(3),E(3),F(3),AB(3),CD(3),DE(3),EA(3),EB(3),EF(3)
C
C.... SPHERE CENTRES
      DIMENSION SCENT(N4,N3)
C.... SPHERE RADII
      DIMENSION SRAD(N4)
C.... SET TO 1 IF SPHERE CALCULATED, ELSE 0
      DIMENSION NFLAGS(N4)
C
      PARAMETER (TOL=1D-3,ETA6=1D-6,BIG8=1D8,RMAX=1D5)
C
      JEDGE=2
C
C.... MAIN LOOP
      DO 10 K=1,4
        IF (K.EQ.3) JEDGE=-JEDGE
        NFLAGS(K)=0
        JJ=K+JEDGE
C
C     CONSTRUCT VECTORS:-
        DO 20 I=1,3
          E(I)=(RCORN1(K,I)+RCORN2(K,I))/FLOAT(2)
          AB(I)=RCORN2(K,I)-RCORN1(K,I)
          EA(I)=RCORN1(K,I)-E(I)
          D(I)=RCORN1(JJ,I)
          CD(I)=D(I)-RCORN2(JJ,I)
          DE(I)=E(I)-D(I)
20      CONTINUE
        CALL VECMOD(AB,ABMOD)
        IF (ABMOD.LT.TOL) THEN
C.... PATCH EDGE DEGENERATED TO NEAR POINT
            SRAD(K)=0.D0
C                         NO SHELL CALCULATED
            GOTO 10
        END IF
C
        CALL DOTF(A1,DE,AB)
        CALL DOTF(A2,AB,CD)
        AL=A1/A2
        DO 30 I=1,3
          V1(I)=CV1(K,I)
          V2(I)=CV2(K,I)
          F(I)=D(I)+AL*CD(I)
          EF(I)=F(I)-E(I)
30      CONTINUE
C
        CALL DOTF(A1,EA,V1)
        CALL DOTF(A2,EF,V1)
        IF (ABS(A2).LT.ETA6) THEN
            AM1=BIG8
        ELSE
            AM1=A1/A2
        END IF
        CALL DOTF(A1,EB,V2)
        CALL DOTF(A2,EF,V2)
        IF (ABS(A2).LT.ETA6) THEN
            AM2=BIG8
        ELSE
            AM2=A1/A2
        END IF
        IF (AM1.GT.0.D0 .AND. AM2.GT.0.D0 .AND. AM2.LT.AM1) THEN
            AM1=AM2
        ELSE IF (AM2.GT.0.D0 .AND. AM1.LE.0.D0) THEN
            AM1=AM2
        END IF
C
        CALL VECMOD(EF,EFMOD)
C
        A2=ABMOD*ABMOD/4.D0
        IF (AM1.LE.0.D0) THEN
            AR=RMAX
        ELSE
            A1=AM1*EFMOD
            AR=SQRT(A1*A1+A2)
        END IF
C
        IF (AR.GE.RMAX) THEN
            AR=RMAX
            AM1=SQRT(AR*AR-A2)/EFMOD
        END IF
C
C
        SRAD(K)=AR
        DO 60 I=1,3
          SCENT(K,I)=E(I)+AM1*EF(I)
60      CONTINUE
C
        NCOUNT=0
100     CONTINUE
        NCOUNT=NCOUNT+1
C     SPHERE ENCLOSES V1 AND V2. NOW TEST THAT RNET POINTS ARE INCLUDED
        AMAX=0
        DO 110 J=1,25
          A1=0
          DO 120 I=1,3
            A2=RNET(J,I)-SCENT(K,I)
            A1=A1+A2*A2
120       CONTINUE
          IF (A1.GT.AMAX) AMAX=A1
110     CONTINUE
C.... A IS DIST. FROM CENTRE TO FURTHEST POINT OF RNET
        A=SQRT(AMAX)
        A1=A-AR
C.... HULL POINTS INSIDE SPHERE
        IF (A1.LE.TOL) THEN
C.... CONVEX HULL FOUND - SET FLAG
            NFLAGS(K)=1
            GOTO 10
        END IF
        IF (A1.LE.(1.1*ABMOD)) THEN
C.... INCREASE RADIUS
            AR=A
            SRAD(K)=A
C.... TRY FOR FIT
            IF (NCOUNT.LE.2) GOTO 100
        ELSE
            SRAD(K)=0
        END IF
C
10    CONTINUE
C
      END
