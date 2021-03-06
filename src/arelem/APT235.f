**** SOURCE FILE : M0002730.V08   ***
*
C
C.....FORTRAN SUBROUTINE                APT235...            8/1/68  AR
      SUBROUTINE APT235
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C
C...            SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
C
      INTEGER Z4E
      PARAMETER (Z4E=1308622848)
C
      INTEGER HCLDTA
      DIMENSION HCLDTA(32)
      DIMENSION HCL(16)
      DOUBLE PRECISION HCL
      EQUIVALENCE(HCL(1),HCLDTA(1))
      DIMENSION IFERM(2)
      EQUIVALENCE(IFERM,FERMOD)
      COMMON/DSNAME/DSNAME,NAMSUB
C
      INCLUDE 'BLANKCOM.INC'
C
      INTEGER BCDF
      LOGICAL FIRST
      SAVE FIRST,HCLDTA
      CHARACTER*8 HGO
      LOGICAL CKDEF,FLAG
C
      DATA HCLDTA /0,0,Z4E,0,Z4E,6,Z4E,1,
     * 0,0,Z4E,0,0,0,Z4E,0,Z4E,0,
     * 14*0/
      DATA HGO/'GO      '/
      DATA FIRST/.TRUE./
C
C
      IF (FIRST)THEN
        HCLDTA(1) = BCDF('CLDA')
        HCLDTA(2) = BCDF('TA  ')
        HCLDTA(9) = BCDF('    ')
        HCLDTA(10) = HCLDTA(9)
        HCLDTA(13) = HCLDTA(9)
        HCLDTA(14) = HCLDTA(9)
        FIRST=.FALSE.
      ENDIF
      FLAG = .FALSE.
      NUMSUR=ICSCNT+K2
C...  PRINT  IDENTIYING FIRST CUT SEQUENCE RECORD ON EXFILE
      CALL RECORD(ISEQNO)
      HCLDTA(4)=ISEQNO
      IFERM(1) = BCDF(MODFER(1:4))
      IFERM(2) = BCDF(MODFER(5:6))
      HCL(5)=FERMOD
      HCLDTA(12)=ISFTYP(IDS)
      HCL(7)=DSNAME
      HCLDTA(16)=NAMSUB
      HCLDTA(18)=ISFIDN(IDS)
      IF(ISFIDN(IDS).EQ.K4.AND.MODFER.NE.HGO) GO TO 10
      HCLDTA(6)=K6
      NR=0
      CALL EWRITE(EXFILE,NR,HCLDTA,18,IR)
      GO TO 15
   10 HCLDTA(6)=K13
      J=ICANON(IDS)
      DO 11 I=10,16
      HCL(I)=CANON(J)
   11 J=J+1
      NR=0
      CALL EWRITE(EXFILE,NR,HCLDTA,32,IR)
   15 IF(IPSDEF)9,9,8
    8 TEMP(1) = TE(3)
      TE(3)=Z0
      CALL AUTOPS
      TE(3) = TEMP(1)
    9 J=IPS
      L=LSV
      DO 1 I = 1,NUMSUR
      M=ICANON(J)
      IF (CKDEF(CANON(M))) FLAG = .TRUE.
      IF (J-ICS)  2,3,4
    2 ITLON(J)=ISFTYP(J)-K3
      GO TO 5
    3 L=LSV1
    4 IF(ISFTYP(J)-K4)2,6,7
    6 ITLON(J)=ITLON(IDS)
      IF(ITLON(J).NE.0) ITLON(J)=2
      GO TO 5
    7 ITLON(J)=ITLON(IPS)
      IF(ITLON(J).NE.0) ITLON(J)=3
      ISFTYP(J)=K4
    5 IAFL(J)=-K1
    1 J=J+L
      IF (FLAG)  CALL AERR(23501,'APT235  ')
      RETURN
       END
