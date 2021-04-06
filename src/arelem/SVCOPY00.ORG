**** SOURCE FILE : SVCOPY00.ORG   ***
*
      SUBROUTINE SVCOPY(I,J)
C
      INCLUDE 'SV.INC'
C
      DO 10 K=1,3
      CC(K,J) = CC(K,I)
      PLNV(K,J) = PLNV(K,I)
      SFVCT(K,J) = SFVCT(K,I)
      SLX(K,J) = SLX(K,I)
      SN(K,J) = SN(K,I)
      SNK(K,J) = SNK(K,I)
      SNL(K,J) = SNL(K,I)
      SP(K,J) = SP(K,I)
      SPK(K,J) = SPK(K,I)
      SPL(K,J) = SPL(K,I)
      TN(K,J) = TN(K,I)
      TOOLHT(K,J) = TOOLHT(K,I)
      TP(K,J) = TP(K,I)
      TPK(K,J) = TPK(K,I)
      U1(K,J) = U1(K,I)
      VNDIR(K,J) = VNDIR(K,I)
      VT(K,J) = VT(K,I)
      U1K(K,J) = U1K(K,I)
      SK(K,J) = SK(K,I)
10      CONTINUE
                
      EPS1(J) = EPS1(I)
      EPS2(J) = EPS2(I)
      EPS3(J) = EPS3(I)
      EPS4(J) = EPS4(I)
      EPS6(J) = EPS6(I)
      EPS8(J) = EPS8(I)
      PAST(J) = PAST(I)
      PLND(J) = PLND(I)
      RC(J) = RC(I)
      S(J) = S(I)
      SAVE(J) = SAVE(I)
      TAU(J) = TAU(I)
      TAU1(J) = TAU1(I)
      TAU2(J) = TAU2(I)
      TH(J) = TH(I)
      TOOLWD(J) = TOOLWD(I)
      Z(J) = Z(I)
      VARBLE(J) = VARBLE(I)
C
      RETURN
      END
         
