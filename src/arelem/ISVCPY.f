**** SOURCE FILE : ISVCPY00.ORG   ***
*
      SUBROUTINE ISVCPY(I,J)
C
      INCLUDE 'ISV.INC'
C
      IAFL(J) = IAFL(I)
      ICANON(J) = ICANON(I)
      INDEX(J) = INDEX(I)
      INDIR(J) = INDIR(I)
      IOP(J) = IOP(I)
      IOPSET(J) = IOPSET(I)
      IPL(J) = IPL(I)
      ISFIDN(J) = ISFIDN(I)
      ISFTYP(J) = ISFTYP(I)
      ISIGCR(J) = ISIGCR(I)
      ISVFL(J) = ISVFL(I)
      ITLON(J) = ITLON(I)
      ITSEG(J) = ITSEG(I)
      IUNFL(J) = IUNFL(I)
      JENT(J) = JENT(I)
      JIOPS(J) = JIOPS(I)
      JTLFLG(J) = JTLFLG(I)
      JTN(J) = JTN(I)
      JU1(J) = JU1(I)
      LIMFL(J) = LIMFL(I)
      ITSEGK(J) = ITSEGK(I)
C
      RETURN
      END
