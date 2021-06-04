**** SOURCE FILE : QABPST.ORG   ***
*
      DOUBLE PRECISION FUNCTION QABPST(P1,P2,P3)
C
C  PURPOSE: TO COMPUTE THE DISTANCE OF A POINT FROM A SPACE LINE
C
C  ARGUMENTS:
C            P1    D.P.  1ST POINT OF SPACE LINE
C            P2    D.P.  2ND POINT OF SPACE LINE
C            P3    D.P.  POINT
C
      DOUBLE PRECISION P1,P2,P3,V2,V3,A,B,H,D,ZEM10
      DIMENSION P1(3),P2(3),P3(3),V2(3),V3(3),H(3)
C
      PARAMETER (ZEM10=1.D-10)
C
      DO 10 I=1,3
        V2(I)=P2(I)-P1(I)
        V3(I)=P3(I)-P1(I)
  10  CONTINUE
C
      CALL DOTF(A,V3,V2)
      CALL DOTF(B,V2,V2)
C
      IF (B.GT.ZEM10) THEN
        A=A/B
      ELSE
C.... IF LINE PIS VERY SHORT ASSUME PERPENDICULAR MEETS LINE AT MIDPOIN
        A=0.5
      ENDIF
C
      DO 20 I=1,3
        H(I)=V3(I)-A*V2(I)
  20  CONTINUE
C
      CALL DOTF(D,H,H)
C
      QABPST=SQRT(D)
C
      END
