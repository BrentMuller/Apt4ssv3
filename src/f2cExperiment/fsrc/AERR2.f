**** SOURCE FILE : M0001934.V11   ***
*
C....    FORTRAN SUBROUTINE                 AERR2
C
C... THIS ROUTINE WRITES ONTO THE EXFILE TAPE ALL THE INFORMATION
C       REQUIRED BY THE CLTAPE EDITOR TO PROCESS ARELEM DIAGNOSTICS
C
C   SUBSIDIARIES   ATAPE, APT242, CUTTER, QSD
C
C
      SUBROUTINE AERR2 (NUMBER,SUBNAM)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DSHAR4.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C...  20. SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
C
C
C...  21. ADDCOM BLOCK
C
      COMMON/ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM( 1),ELMAX ),  (ADDCOM( 2),CLNGTH),
     1            (ADDCOM(23),IBTFLG),  (ADDCOM(24),JLIN)
C
C
C        COMMON BLOCKS FOR SURFACE NAME AND SUBSCRIPT STORAGE
C
C     23. DSNAME BLOCK
      COMMON/DSNAME/DSNAME,NAMSUB
C
C     24. SRFNAM BLOCK
      COMMON /SRFNAM/ PSNAME,CS1NAM,CS2NAM,IPSSUB,ICS1SB,ICS2SB
C
C     25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/  IAERFG,NPCTPT,PCTPTS,PCTPLN,ERRPTS
      DIMENSION  PCTPTS(3,20), PCTPLN(4), ERRPTS(3,3)
      INTEGER BCDF
      CHARACTER*8 SUBNAM
      LOGICAL FIRST
      SAVE FIRST,KERR
      INCLUDE 'DARRAY.INC'
C
      INTEGER Z4E
      PARAMETER (Z4E=1308622848)
C
      DIMENSION DSHARE(100)
C
C        BLANK COMMON CONTAINING CANONICAL FORM OF SURFACES
C
      INCLUDE 'BLANKCOM.INC'
C
C        CANONICAL SIZE ARRAY FOR VARIOUS MODES OF A SURFACE
C
      DIMENSION ICANSZ(30)
C
C        DIMENSION FOR ARGUMENTS IN CALL TO QSD AND CUTTER
      DIMENSION  CANFRM(10), COEFF(10), TRANS(12)
C
      DIMENSION ITEMP(8),DTEMP(4)
      EQUIVALENCE (ITEMP(1),DTEMP(1))
C
C...      32.  PARAMETERS REQUIRED BY SUPERVISOR
C
          COMMON/SUPER/ERR,XC,CL,PX,ERRX,END,FINI,ASM,ABEND,XTRAS
          DIMENSION XTRAS(7),CFLAGS(4),LXTRAS(7)
          INTEGER   ERRX,XTRAS
          LOGICAL   ERR,FINI,XC,CL,ASM,LXTRAS,CFLAGS,PX,END,ABEND
          EQUIVALENCE (LXTRAS(1),XTRAS(1)),(CFLAGS(1),ERR)
C
      DIMENSION KERR(10),ISN(2)
      DATA KERR/0,0,Z4E,1,Z4E,1,Z4E,1,2*0/
      DATA       ICANSZ  / 4,  4,  7,  7,  4,    10, 10, 10,  7, 10,
     +                     2,  2,  2, 10, 10,     1,  1, 12,  3,  3,
     +                     1,  1,  1,  1, 12,     2,  1,  1,  2,  2/
      DATA  IPOW/Z4E/
      DATA  FIRST/.TRUE./
C     ------------------------------------------------------------
C
C
      TAL(1)=FWD(1)
      TAL(2)=FWD(2)
      TAL(3)=FWD(3)
      XTRAS(1) = XTRAS(1) + 1
      IAERR=K1
      IF (FIRST)THEN
        KERR(1) = BCDF('AERR')
        KERR(2) = BCDF('    ')
        FIRST=.FALSE.
      ENDIF
      NERR=NUMBER
      KERR( 9)= BCDF(SUBNAM(1:4))
      KERR(10)= BCDF(SUBNAM(5:8))
      NUMRTN=NERR/100
      CALL ATAPE
      CALL RECORD(ISN(1))
      CALL CPRINT(DARRAY)
      CALL CFORM(' ***** RESTART DIAGNOSTIC ',DARRAY,1,26)
      CALL ICONV(NERR,DARRAY,27,5)
      CALL CFORM('ISN',DARRAY,36,3)
      CALL ICONV(ISN(1),DARRAY,39,5)
      CALL CFORM(' FROM SUBROUTINE ',DARRAY,44,17)
      CALL CFORM(SUBNAM,DARRAY,61,8)
      CALL CFORM('*****',DARRAY,69,5)
      CALL CPRINT(DARRAY)
      CALL ERROUT(NERR)
C
C..   ***** RESTART DIAGNOSTIC - OUTPUT SURFACE VARIABLE DATA *****
C
C        SET ERROR LEVEL FLAG TO VALUE 8
   20 ERRX=K8
C
C        CHECK FOR POCKET ERROR PROCESSING
      IF (NUMRTN-35) 22,90,22
C
C...     IF ERROR IS FOR MISSING CUTTER USE A POINT CUTTER
   22 IF (ICTDEF .NE. K1) GO TO 23
C
      ICTDEF=0
      NR = 0
      KERR(4)=1
      KERR(6)=2
      KERR(8)=NERR
      CALL EWRITE (EXFILE,NR,KERR,10,IR)
      IAERR=0
      NR=7
      DO 21 I=1,9
      CANFRM(I)=0.0
   21 CONTINUE
      CALL CUTTER(NR,CANFRM)
      GO TO 100
C
C        OUTPUT ERROR NUMBER AND CUTTER PARAMETERS
C
   23 KERR(4)=1
      KERR(6)=9
      KERR(8)=NERR
      CALL AFORM(DSHARE(1),KERR,5)
      CALL AFORM(DSHARE(6),CUTDAT,7)
      NR=0
      CALL EWRITE (EXFILE,NR,DSHARE,24,IR)
C
C        CHECK FOR NO SURFACE VARIABLE OUTPUT
   24 IF (IAERFG) 25,25,99
C
C        WRITE NECESSARY SV AND ISV VARIABLES FOR PS ON EXFILE
   25 L=K2
      J=IPS
      SFNAME=PSNAME
      ISUB=IPSSUB
C
C
C.... *** PRIMARY OUTPUT LOOP FOR EACH SURFACE ***
C
   30 L=L+K1
      IC=ICANON(J)
      MODE=ISFIDN(J)
C
C        SAVE CANONICAL FORM
      ISIZE=ICANSZ(MODE)
      ICC=IC
      DO  32 I=1,ISIZE
      CANFRM(I)=CANON(ICC)
      ICC=ICC+1
   32 CONTINUE
C
C        CALCULATE VT VALUES FOR ERRORS FROM AMIND ASSOCIATED ROUTINES
C              (SINCE THEY MAY BE MISSING AT THIS TIME)
      IF (NUMRTN.LT.260 .OR. NUMRTN.GT.272) GO TO 34
C
   33 VT(1,J)=TP(1,J)-TH(J)*TN(1,J)  -TE(1)
      VT(2,J)=TP(2,J)-TH(J)*TN(2,J)-TE(2)
      VT(3,J)=TP(3,J)-TH(J)*TN(3,J)-TE(3)
C
C        PRIMARY OUTPUT STATEMENT CONTAINING NECESSARY SV AND ISV
C        VARIABLES, SURFACE NAME AND TYPE, AND CANONICAL FORM
C
   34 JSIZE=ISIZE+30
      JL=J+K2
      KERR(4)=L
      KERR(6)=JSIZE
      KERR(8)=NERR
      CALL AFORM(DSHARE(1),KERR,5)
      ITEMP(1)=IPOW
      ITEMP(2)=ITLON(J)
      ITEMP(3)=IPOW
      ITEMP(4)=ISFTYP(J)
      ITEMP(5)=IPOW
      ITEMP(6)=IFL4(J)
      ITEMP(7)=IPOW
      ITEMP(8)=IFAR(J)
      CALL AFORM(DSHARE(6),DTEMP,4)
      CALL AFORM(DSHARE(10),TAU1(J),1)
      CALL AFORM(DSHARE(11),TAU2(J),1)
      CALL AFORM(DSHARE(12),TH(J),1)
      CALL AFORM(DSHARE(13),S(J),1)
      CALL AFORM(DSHARE(14),RC(J),1)
      CALL AFORM(DSHARE(15),SP(1,J),3)
      CALL AFORM(DSHARE(18),SN(1,J),3)
      CALL AFORM(DSHARE(21),TN(1,J),3)
      CALL AFORM(DSHARE(24),CC(1,J),3)
      CALL AFORM(DSHARE(27),VT(1,J),3)
      CALL AFORM(DSHARE(30),SFNAME,1)
      ITEMP(2)=ISUB
      ITEMP(4)=MODE
      ITEMP(6)=ISIZE
      CALL AFORM(DSHARE(31),DTEMP,3)
      CALL AFORM(DSHARE(34),CANFRM,ISIZE)
      NR=0
      N=(JSIZE+3)*2
      CALL EWRITE (EXFILE,NR,DSHARE,N,IR)
C
C        CHECK FOR QUADRIC, LCONIC, OR GCONIC TYPE SURFACES,
C        IF FOUND, CALL QSD TO IDENTIFY AND SOLVE FOR PARAMETERS
C
      GO TO (35,35,35,35,35,  80,80,80,35,80,  35,35,35,80,35,
     +35,35,35,35,35,35,35,35,35,35,35,35,35,35,35),MODE
C
C        CHECK FOR FURTHER SURFACE OUTPUT
   35 IF (((NUMSUR+K2).EQ.L) .OR. (NUMSUR.LE.K0)) GO TO 95
      IF(L-K4) 40,50,60
C
C        WRITE NECESSARY SV AND ISV VARIABLES FOR DS ON EXFILE
   40 J=IDS
      IGOTO=K1
      ISRCH=K1
      SFNAME=DSNAME
      ISUB=NAMSUB
      GO TO 30
C
C        WRITE NECESSARY SV AND ISV VARIABLES FOR CS1 ON EXFILE
   50 J=ICS
      SFNAME=CS1NAM
      ISUB=ICS1SB
      GO TO 30
C
C        WRITE NECESSARY SV AND ISV VARIABLES FOR CS2 ON EXFILE
   60 J=J+LSV1
      SFNAME=CS2NAM
      ISUB=ICS2SB
      GO TO 30
C
C        OUTPUT QUADRIC INFORMATION
C
   80 CALL QSD (CANFRM,IQSDFG,COEFF,TRANS)
      KERR(4)=7
      KERR(6)=24
      KERR(8)=IQSDFG
      NR=0
      CALL AFORM(DSHARE(1),KERR,5)
      CALL AFORM(DSHARE(6),COEFF,10)
      CALL AFORM(DSHARE(16),TRANS,12)
      CALL EWRITE (EXFILE,NR,DSHARE,54,IR)
      GO TO 35
C
C        OUTPUT POCKET INFORMATION AND RETURN
C
   90 JSZ=3*NPCTPT
      JSIZE=JSZ+16
      KERR(4)=8
      KERR(6)=JSIZE
      KERR(8)=NERR
      NR=0
      N=(JSIZE+3)*2
      CALL AFORM(DSHARE(1),KERR,5)
      ITEMP(2)=NPCTPT
      CALL AFORM(DSHARE(6),DTEMP,1)
      CALL AFORM(DSHARE(7),ERRPTS,9)
      CALL AFORM(DSHARE(16),PCTPLN,4)
      CALL AFORM(DSHARE(20),PCTPTS,3*NPCPT)
      CALL EWRITE(EXFILE,NR,DSHARE,N,IR)
      GO TO 99
C
C        WRITE NECESSARY VARIABLES FOR IDENTIFICATION OF SURFACE
C
   95 NR=0
      KERR(4)=2
      KERR(6)=20
      KERR(8)=ICSCNT
      CALL AFORM(DSHARE(1),KERR,5)
      ITEMP(2)=IGO
      ITEMP(4)=ISTRUP
      CALL AFORM(DSHARE(6),DTEMP,2)
      CALL AFORM(DSHARE(8),DPMAX,1)
      ITEMP(2)=NMPNTS
      CALL AFORM(DSHARE(9),DTEMP,1)
      CALL AFORM(DSHARE(10),ELMAX,1)
      CALL AFORM(DSHARE(11),TI,3)
      CALL AFORM(DSHARE(14),TE,3)
      ITEMP(2)=IS
      CALL AFORM(DSHARE(17),DTEMP,1)
      CALL AFORM(DSHARE(18),TAL,3)
      CALL AFORM(DSHARE(21),TA,3)
      CALL EWRITE (EXFILE,NR,DSHARE,46,IR)
C
      CALL APT236
      CALL APT242
   99 IAERFG=0
  100 RETURN
      END