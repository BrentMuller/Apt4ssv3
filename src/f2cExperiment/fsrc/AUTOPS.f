**** SOURCE FILE : M0000869.V05   ***
*
C...  FORTRAN SUBROUTINE               AUTOPS
      SUBROUTINE AUTOPS
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C
      INCLUDE 'BLANKCOM.INC'
C
      IF(JDS) CALL APT201(0,'NOCS    ')
      CANON(1)=Z0
      CANON(2)=Z0
      CANON(3)=Z1
      CANON(4)=TE(3)
      ISFIDN(IPS)=K2
      ICANON(IPS)=K1
      ISFTYP(IPS)=K3
      IUNFL(IPS)=K1
      IPL(IPS)=K1
      PAST(IPS)=Z1
      LIMFL(IPS)=0
      IPSDEF=0
      TN(1,IPS)=Z0
      TN(2,IPS)=Z0
      TN(3,IPS)=-Z1
      JENT(IPS) = K1
      RETURN
       END
