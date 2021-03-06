**** SOURCE FILE : ALGO1.ORG   ***
*
      SUBROUTINE ALGO1(T,R,RN,RU,RV,DU,DV)
C
C     PURPOSE: CALCULATE DU,DV USING ALGORITHM 1
C
C              GIVEN A SURFACE POINT R AND SURFACE NORMAL RN
C              AND A POINT ON THE TOOL T WITH SAME NORMAL
C              CALCULATE POINT B WHERE THIS TOOL NORMAL INTERSECTS
C              THE TANGENT PLANE AT R.
C              THE INDUCED PARAMETERIZATION OF THE TANGENT PLANE
C              IS USED TO DETERINE DU AND DV
C
C
C     CALC. UVSTEP AS STEP ON TANGENT PLANE AT POINT R
C
      DOUBLE PRECISION T,R,RN,RU,RV,UVSTEP,A,V4,S,DU,DV
      DIMENSION T(3),R(3),RN(3),RU(3),RV(3),UVSTEP(3),V4(3)
C
      DO 100 I=1,3
        V4(I)=T(I)-R(I)
100   CONTINUE
      CALL DOTF(A,V4,RN)
      DO 200 I=1,3
        UVSTEP(I)=V4(I)-A*RN(I)
200   CONTINUE
C
C.... S IS STEP LENGTH
C
      CALL VECMOD(UVSTEP,S)
C
C.... COMPUTE DU,DV FROM INDUCED PARAMETERIZATION OF TANGENT PLANE
C
      CALL DEGSOL(UVSTEP,RU,RV,DU,DV,ISF)
C
      END
