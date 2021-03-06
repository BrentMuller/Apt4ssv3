**** SOURCE FILE : TVDAFS.ORG   ***
*
      SUBROUTINE TVDAFS(TRM,GEO)
C TRANSFORMATOR ROUTINE FOR VDAFS SURFACE PATCH USING
C APT TRANSFORMATION MATRIX TRM
      DOUBLE PRECISION TRM(4,3),GEO(*),A(3)
      MU=INT(GEO(1))
      MV=INT(GEO(2))
      N=MU*MV
C 1ST 2 LOCATIONS OF GEO CONTAIN DIMENSIONS OF ARRAYS AX,AY,AZ OF COEFFI
C THESE COEFFICIENT MATRICES FOLLOW IN CONSECUTIVE LOCATIONS IN GEO.
C ALL COEFFICIENT VECTORS MUST BE ROTATED.
      DO 10 I=1,N
      IX=2+I
      IY=IX+N
      IZ=IY+N
      DO 5 J=1,3
  5   A(J)=TRM(1,J)*GEO(IX)+TRM(2,J)*GEO(IY)+TRM(3,J)*GEO(IZ)
      GEO(IX)=A(1)
      GEO(IY)=A(2)
      GEO(IZ)=A(3)
 10   CONTINUE
C (0,0) COEFFICIENT IN EACH ARRAY IS ALSO TRANSLATED
      GEO(3)=GEO(3)+TRM(4,1)
      GEO(3+N)=GEO(3+N)+TRM(4,2)
      GEO(3+2*N)=GEO(3+2*N)+TRM(4,3)
      RETURN
      END
