**** SOURCE FILE : M0001070.W02   ***
*
      SUBROUTINE GETAPT(TUL,PTOLI,PTOLO,DTOL,AMAXDP,ZELMAX,INUM,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C--PURPOSE IS TO FETCH ADDITIONAL APT VARIABLES REQUIRED FOR
C--SMIL TOOL PATH GENERATION.
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'IFXCOR.INC'
C
      DIMENSION TUL(7)
      COMMON/ADDCOM/ADDCOM(25)
      EQUIVALENCE (ADDCOM(1), ELMAX)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
C
      DATA SMAL/1.0D-14/
C
C--FETCH TOOL AND VERIFY THAT IT IS ACCEPTABLE
      TUL(1)=CUTDAT(2)
      TUL(2)=CUTDAT(1)
      TUL(3)=CUTDAT(3)
      IF(TUL(1)**2+TUL(3)**2.LT.SMAL) TUL(3)=TUL(2)
      TUL(4)=CUTDAT(4)-CUTDAT(2)
      TUL(5)=CUTDAT(5)
      TUL(6)=CUTDAT(6)
      TUL(7)=CUTDAT(7)
      IF(IBUG.EQ.11) CALL BAD(-7,1,'CUTD',CUTDAT)
C
      PTOLO=DABS(TAU1(IPS))
      PTOLI=DABS(TAU2(IPS))
      DTOL=DABS(TAU1(IDS))
      IF(DTOL.LT.SMAL) DTOL=DABS(TAU2(IDS))
      AMAXDP=DPMAX
      ZELMAX=ELMAX
      INUM=NMPNTS
      IRR=0
      GO TO 999
  998 CONTINUE
      IF(IBUG.EQ.11) CALL BAD(-7,1,'CUTD',CUTDAT)
C
  999 CONTINUE
      RETURN
      END
