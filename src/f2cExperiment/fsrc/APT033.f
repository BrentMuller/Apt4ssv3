**** SOURCE FILE : M0002799.V04   ***
*
C.....FORTRAN SUBROUTINE  ....APT033         8/68                 PH
C.....FORTRAN SUBROUTINE             APT033...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT033
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A RULED SURFACE
C              DEFINED BY EITHER OF THE APT STATEMENTS
C              RLDSRF/S1,P1,P2,P3 OR V1,S2,P4,P5,P6, OR V2
C              RLDSRF/S1,P1,P2,P3 OR V1,P7
C                IN THESE STATEMENTS S REFERS TO A SURFACE,P TO A POINT
C              AND V TO A VECTOR
C
C LINKAGE      CALL APT033(ARG1,ARG2,.....,ARG8,IARG9,IARG10)
C
C ARGUMENTS    THE FIRST EIGHT ARGUMENT CONTAIN RULED SURFACE PARAMETERS
C              THE NINTH ARG CONTAINS A 5 OR 8 TO DISTINGUISH AMOUNG
C              THE STATEMENT TYPES. THE LAST ARG HAS THE ADD. OF THE
C              RULED SURFACE CANONICAL FORM
C
C CALLS        UNPACK,APT094,ERROR,CROSS,VNORM,DOTF
C
C
      SUBROUTINE APT033(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,IARG9,
     1                  IARG10)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DOUBLE PRECISION IARG10
      DOUBLE PRECISION LCANON
      DIMENSION ARG1(*),ARG2(3),ARG3(3),ARG4(3),ARG5(*),ARG6(3),ARG7(3),
     1          ARG8(3),IARG10(2)
C
      INCLUDE 'BLANKCOM.INC'
C
      DIMENSION LCANON(COMSIZ),TEMP(10),PT1(3),PT2(3),DELCHD(3),
     1          DELVEC(3)
      EQUIVALENCE (CANON(1),LCANON(1))
C
C     INITIALIZE
      LENS1 = 0
      LENS2 = 0
      NPTS = 0
      DO 10 I=42,82
   10 LCANON(I) = 0
      LCANON(43) = IARG9
      LCANON(44) = 43
      IF (IARG9.EQ.5) GO TO 20
      NPTS = 6
      GO TO 30
   20 NPTS = 4
   30 CALL UNPACK (ARG1,MODE,ISIZE,SUBS)
      LCANON(83) = MODE
C
C     IS SI A TABCYL
C
      IF((MODE.EQ.11).OR.(MODE.EQ.22)) GO TO 50
      LENS1 = ISIZE
      DO 40 I = 1,LENS1
   40 CANON(I+83) = ARG1(I)
      GO TO 60
   50 LENS1 = ARG1(2)
      CALL APT094(2,ARG1,CANON(84))
C
C     FULL INDEX TO FLAG SURFACE BEING FILLED IN CANON
C
 60   K = LENS1 + 44
      LCANON(45) = K
      LCANON(46) = K+4
      LCANON(47) = K+8
      LCANON(48) = K+12
      K = K +40
      LCANON(K) = 1
      LCANON(K+4) = 1
      TEMP(1) = 0.
C
C     PROCESS P1 AND P2
C
      DO 70 I = 1,3
      L = K + I
      CANON(L) = ARG2(I)
      PT1(I) = ARG2(I)
      CANON(L+4) = ARG3(I)
      PT2(I) = ARG3(I)
      DELCHD(I) = PT2(I) - PT1(I)
   70 TEMP(1) = TEMP(1) + DELCHD(I)*DELCHD(I)
C
C     IF P2-P1 LESS THAN .01 TAKE ERROR OUTLET
C
      IF (TEMP(1).GT..0001) GO TO 80
      CALL ERROR (87,'APT033  ')
      CALL APT094 (4,IARG10,CANON(41))
      GO TO 999
C
   80 CALL UNPACK (ARG4,MODE,ISIZE,SUBS)
      LCANON(LENS1+92) = MODE
C
C     IF P3 RATHER THAN V1 CONVERT TO VECTOR
C
      IF (MODE.EQ.20) GO TO 100
      DO 90 I = 1,3
   90 DELVEC(I) = ARG4(I) - PT1(I)
      CALL CROSS (DELVEC,DELCHD,DELVEC)
      CALL CROSS (DELCHD,DELVEC,DELVEC)
      GO TO 120
  100 DO 110 I = 1,3
  110 DELVEC(I) = ARG4(I)
 120  CALL VNORM (DELCHD,DELCHD)
      CALL VNORM (DELVEC,DELVEC)
C
C     VECTOR AND CHORD CANNOT BE PARALLEL
C
      CALL CROSS (DELVEC,DELCHD,TEMP)
      TEMP(1)=TEMP(1)**2+TEMP(2)**2+TEMP(3)**2
      IF (TEMP(1).GT..01) GO TO 130
      CALL ERROR (88,'APT033  ')
      CALL APT094 (4,IARG10,CANON(41))
      RETURN
 130  K = LENS1 + 92
      DO 140 I = 1,3
      L = K + I
      CANON(L) = DELVEC(I)
      IF (IARG9.NE.5) GO TO 140
      CANON(L+4) = ARG5(I)
  140 CONTINUE
      IF (IARG9.NE.5) GO TO145
      LCANON(K) = 1
      LCANON(K+4)=1.
      GOTO 250
C
C     PROCESS S2
C
  145 CALL UNPACK (ARG5,MODE,ISIZE,SUBS)
      K = LENS1 + 96
      IF ((MODE.EQ.11).OR.(MODE.EQ.22)) GO TO 160
      LENS2 = ISIZE
      DO 150 I = 1,LENS2
      L = K + I
  150 CANON(L) = ARG5(I)
      GO TO 165
  160 LENS2 = ARG5(2)
      CALL APT094(2,ARG5,CANON(K+1))
 165  L=K+LENS2+1
      I = L - 40
      LCANON(49) = I
      LCANON(50) = I + 4
      LCANON(51) = I + 8
      LCANON(K) = MODE
      LCANON(L) = 1
      LCANON(L+4) = 1
      TEMP(1) = 0.
      K = L
      DO 170 I = 1,3
      L = K + I
      CANON(L) = ARG6(I)
      PT1(I) = ARG6(I)
      CANON(L+4) = ARG7(I)
      PT2(I) = ARG7(I)
      DELCHD(I) = PT2(I) - PT1(I)
  170 TEMP(1) = TEMP(1) + DELCHD(I)*DELCHD(I)
      IF (TEMP(1).GT..0001) GO TO 180
      CALL ERROR (87,'APT033  ')
      CALL APT094 (4,IARG10,CANON(41))
      GO TO 999
  180 CALL UNPACK (ARG8,MODE,ISIZE,SUBS)
      N = LENS1+LENS2+105
      LCANON(N) = MODE
      IF (MODE.EQ.20) GO TO 200
      DO 190 I = 1,3
  190 DELVEC(I) = ARG8(I) - PT1(I)
      CALL CROSS (DELVEC,DELCHD,DELVEC)
      CALL CROSS (DELCHD,DELVEC,DELVEC)
      GO TO 220
  200 DO 210 I = 1,3
  210 DELVEC(I) = ARG8(I)
  220 CALL VNORM (DELCHD,DELCHD)
      CALL VNORM (DELVEC,DELVEC)
      CALL CROSS (DELVEC,DELCHD,TEMP)
      TEMP(1)=TEMP(1)**2+TEMP(2)**2+TEMP(3)**2
      IF (TEMP(1).GT..01) GO TO 230
      CALL ERROR (88,'APT033  ')
      CALL APT094 (4,IARG10,CANON(41))
      GO TO 999
 230  K = 105 +LENS1+LENS2
      DO 240 I = 1,3
      L = K + I
  240 CANON(L) = DELVEC(I)
      IF (IARG9.EQ.5) GO TO 250
      N = 2
      GO TO 260
  250 N = 1
 260  LSIZE = LENS1+LENS2+N+4*NPTS+42
      LCANON(42) = LSIZE
      IARG10(2) = LSIZE
      CALL APT094 (1,IARG10,CANON(41))
  999 CONTINUE
      RETURN
      END