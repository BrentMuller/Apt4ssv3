**** SOURCE FILE : SSV3.ORG   ***
*
      PROGRAM SSV3
      INCLUDE 'COMMONS.INC'
      CALL SPRVIS
      STOP
      END
**** SOURCE FILE : M0001353.V04   ***
*
C
C....    FORTRAN BLOCK DATA ROUTINE...   ABLKDATA...     12/69   RC
      BLOCK DATA ABLK
C
C...     COMMON AREAS FROM SYSTEM 360 APT
C
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/ I
      INTEGER I(23)
      COMMON/ASISTM/ J
      INTEGER  J(22)
      COMMON/APOSTP/P
      DOUBLE PRECISION P(40)
      COMMON/ATIME/T
      DOUBLE PRECISION T(4)
      COMMON/AOUTFG/IFLAG
      INTEGER IFLAG
      DATA   K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
     1      / 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,4H    /
      DATA I/0,6,0,6, 0,3,0,6, 0,6,0,6, 0,6,0,6, 0,4,0,6, 5,6,7/
      DATA J/22*0/
      DATA P/40*0.0D0/
      DATA T/4*0.0D0/
      DATA IFLAG/0/
      END
**** SOURCE FILE : CRTN0000.V01   ***
*
      SUBROUTINE CRTN(COND)
*
*  *  CRTN  *   TEMPORARY VAX11 VERSION   13.5.81    E.MCLELLAN
*
      INTEGER COND
      IF (COND.EQ.0) THEN
        STOP 'PROCESSING COMPLETED OK'
      ELSE IF (COND.EQ.4) THEN
        STOP 'PROCESSING COMPLETED - WARNINGS HAVE OCCURRED'
      ELSE
        STOP 'ABNORMAL END - ERRORS HAVE OCCURRED'
      ENDIF
      END
**** SOURCE FILE : FLTAB000.W01   ***
*
*
*  *  BLOCK DATA PROGRAM DEFINING FILE ATTRIBUTES  *
*
*                  NEW VERSION   17.07.85   E.MCLELLAN
*
*---------------------------------------------------
*   VARIABLE        BLOCK     TYPE       DESCRIPTION
*---------------------------------------------------
*
*   FILNAM          FILTAB    CHARACTER  FILE NAME
*   FILACC          FILTAB    CHARACTER  FILE ACCESS
*                                         (DIRECT OR SEQUENTIAL)
*   FILFMT          FILTAB    CHARACTER  FILE FORMAT
*                                         (FORMATTED OR UNFORMATTED)
*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS
*                                         (UNKNOWN,SCRATCH,NEW,OLD)
*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE)
*   U               IFILTB    INTEGER    UNIT NUMBER
*   RL              IFILTB    INTEGER    RECORD LENGTH
*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE
*                                        READ OR WRITTEN (DIRECT ACCESS)
*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE
*                                         (DIRECT ACCESS)
      BLOCK DATA FLTAB
C
      INCLUDE 'FILTAB.INC'
C
c     F77 forbids opening 'scratch' as a named file
c     some record lengths were 4 times too small due
c     to byte vs integer record lengths
      DATA FILNAM(1)/'CLFILP'/,FILACC(1)/'DIRECT '/,
     1     FILFMT(1)/'UNFORMATTED'/,
     2     OPSTAT(1)/'UNKNOWN'/,CLSTAT(1)/'KEEP'/,
c     3     U(1)/1/,RL(1)/516/,NXTREC(1)/1/,LSTREC(1)/0/
     3     u(1)/1/,rl(1)/2064/,nxtrec(1)/1/,lstrec(1)/0/
      DATA FILNAM(2)/'CLFILE'/,FILACC(2)/'DIRECT '/,
     1     FILFMT(2)/'UNFORMATTED'/,
     2     OPSTAT(2)/'UNKNOWN'/,CLSTAT(2)/'KEEP'/,
c     3     U(2)/2/,RL(2)/516/,NXTREC(2)/1/,LSTREC(2)/0/
     3     u(2)/2/,rl(2)/2064/,nxtrec(2)/1/,lstrec(2)/0/
     DATA FILNAM(3)/'CLFIL3'/,FILACC(3)/'SEQUENTIAL'/,
     1     FILFMT(3)/'UNFORMATTED'/,
     2     OPSTAT(3)/'UNKNOWN'/,CLSTAT(3)/'KEEP'/,
     3     U(3)/3/,RL(3)/512/,NXTREC(3)/1/,LSTREC(3)/0/
      DATA FILNAM(4)/'EXFILE'/,FILACC(4)/'DIRECT '/,
     1     FILFMT(4)/'UNFORMATTED'/,
c     2     OPSTAT(4)/'SCRATCH'/,CLSTAT(4)/'DELETE'/,
     2     opstat(4)/'replace'/,clstat(4)/'delete'/,
c     3     U(4)/4/,RL(4)/516/,NXTREC(4)/1/,LSTREC(4)/0/
     3     u(4)/4/,rl(4)/2064/,nxtrec(4)/1/,lstrec(4)/0/
      DATA FILNAM(5)/'INFILE'/,FILACC(5)/'SEQUENTIAL'/,
     1     FILFMT(5)/'FORMATTED'/,
     2     OPSTAT(5)/'OLD'/,CLSTAT(5)/'KEEP'/,
     3     U(5)/5/,RL(5)/80/,NXTREC(5)/1/,LSTREC(5)/0/
      DATA FILNAM(6)/'VLFILE'/,FILACC(6)/'SEQUENTIAL'/,
     1     FILFMT(6)/'FORMATTED'/,
     2     OPSTAT(6)/'NEW'/,CLSTAT(6)/'KEEP'/,
     3     U(6)/6/,RL(6)/120/,NXTREC(6)/1/,LSTREC(6)/0/
      DATA FILNAM(7)/'PNCHFL'/,FILACC(7)/'SEQUENTIAL'/,
     1     FILFMT(7)/'FORMATTED'/,
     2     OPSTAT(7)/'NEW'/,CLSTAT(7)/'KEEP'/,
     3     U(7)/7/,RL(7)/80/,NXTREC(7)/1/,LSTREC(7)/0/
      DATA FILNAM(8)/'XCAN'/,FILACC(8)/'DIRECT '/,
     1     FILFMT(8)/'UNFORMATTED'/
c     2     OPSTAT(8)/'SCRATCH'/,CLSTAT(8)/'DELETE'/,
     2     opstat(8)/'replace'/,clstat(8)/'delete'/,
c     3     U(8)/8/,RL(8)/256/,NXTREC(8)/1/,LSTREC(8)/0/
     3     u(8)/8/,rl(8)/1024/,nxtrec(8)/1/,lstrec(8)/0/
      DATA FILNAM(9)/'MAXTXT'/,FILACC(9)/'DIRECT '/,
     1     FILFMT(9)/'UNFORMATTED'/,
c     2     OPSTAT(9)/'SCRATCH'/,CLSTAT(9)/'DELETE'/,
     2     opstat(9)/'replace'/,clstat(9)/'delete'/,
c     3     U(9)/9/,RL(9)/350/,NXTREC(9)/1/,LSTREC(9)/0/
     3     u(9)/9/,rl(9)/1400/,nxtrec(9)/1/,lstrec(9)/0/
      DATA FILNAM(10)/'XNUM'/,FILACC(10)/'DIRECT '/,
     1     FILFMT(10)/'UNFORMATTED'/,
c     2     OPSTAT(10)/'SCRATCH'/,CLSTAT(10)/'DELETE'/,
     2     opstat(10)/'replace'/,clstat(10)/'delete'/,
c     3     U(10)/10/,RL(10)/540/,NXTREC(10)/1/,LSTREC(10)/0/
     3     u(10)/10/,rl(10)/2160/,nxtrec(10)/1/,lstrec(10)/0/
      DATA FILNAM(11)/'ELFIL1'/,FILACC(11)/'DIRECT '/,
     1     FILFMT(11)/'UNFORMATTED'/,
c     2     OPSTAT(11)/'SCRATCH'/,CLSTAT(11)/'DELETE'/,
     2     opstat(11)/'replace'/,clstat(11)/'delete'/,
c     2     opstat(11)/'new'/,clstat(11)/'keep'/,
c     3     U(11)/11/,RL(11)/256/,NXTREC(11)/1/,LSTREC(11)/0/
     3     u(11)/11/,rl(11)/1024/,nxtrec(11)/1/,lstrec(11)/0/
      DATA FILNAM(12)/'ELFIL2'/,FILACC(12)/'DIRECT '/,
     1     FILFMT(12)/'UNFORMATTED'/,
c     2     OPSTAT(12)/'SCRATCH'/,CLSTAT(12)/'DELETE'/,
     2     opstat(12)/'replace'/,clstat(12)/'delete'/,
c     2     opstat(12)/'new'/,clstat(12)/'keep'/,
c     3     U(12)/12/,RL(12)/256/,NXTREC(12)/1/,LSTREC(12)/0/
     3     u(12)/12/,rl(12)/1024/,nxtrec(12)/1/,lstrec(12)/0/
      DATA FILNAM(13)/'ELFIL3'/,FILACC(13)/'DIRECT '/,
     1     FILFMT(13)/'UNFORMATTED'/,
c     2     OPSTAT(13)/'SCRATCH'/,CLSTAT(13)/'DELETE'/,
     2     opstat(13)/'replace'/,clstat(13)/'delete'/,
c     3     U(13)/13/,RL(13)/256/,NXTREC(13)/1/,LSTREC(13)/0/
     3     U(13)/13/,RL(13)/1024/,NXTREC(13)/1/,LSTREC(13)/0/
      DATA FILNAM(14)/'ELFIL4'/,FILACC(14)/'SEQUENTIAL'/,
     1     FILFMT(14)/'UNFORMATTED'/,
c     2     OPSTAT(14)/'SCRATCH'/,CLSTAT(14)/'DELETE'/,
     2     opstat(14)/'replace'/,clstat(14)/'delete'/,
c     3     U(14)/14/,RL(14)/256/,NXTREC(14)/1/,LSTREC(14)/0/
     3     u(14)/14/,rl(14)/114096/,nxtrec(14)/1/,lstrec(14)/0/
      DATA FILNAM(15)/'CPFILE'/,FILACC(15)/'SEQUENTIAL'/,
     1     FILFMT(15)/'UNFORMATTED'/,
     2     OPSTAT(15)/'UNKNOWN'/,CLSTAT(15)/'DELETE'/,
c     3     U(15)/15/,RL(15)/48/,NXTREC(15)/1/,LSTREC(15)/0/
     3     u(15)/15/,rl(15)/1148/,nxtrec(15)/1/,lstrec(15)/0/
      DATA FILNAM(16)/'AXFILE'/,FILACC(16)/'DIRECT'/,
     1     FILFMT(16)/'UNFORMATTED'/,
c     2     OPSTAT(16)/'SCRATCH'/,CLSTAT(16)/'DELETE'/,
     2     opstat(16)/'replace'/,clstat(16)/'delete'/,
c     3     U(16)/16/,RL(16)/256/,NXTREC(16)/1/,LSTREC(16)/0/
     3     u(16)/16/,rl(16)/1024/,nxtrec(16)/1/,lstrec(16)/0/
      DATA FILNAM(17)/'POFILE'/,FILACC(17)/'DIRECT '/,
     1     FILFMT(17)/'UNFORMATTED'/,
c     2     OPSTAT(17)/'SCRATCH'/,CLSTAT(17)/'DELETE'/,
     2     opstat(17)/'replace'/,clstat(17)/'delete'/,
c     3     U(17)/17/,RL(17)/24/,NXTREC(17)/1/,LSTREC(17)/0/
     3     u(17)/17/,rl(17)/96/,nxtrec(17)/1/,lstrec(17)/0/
      DATA FILNAM(18)/'ELFILE'/,FILACC(18)/' '/,
     1     FILFMT(18)/' '/,
     2     OPSTAT(18)/' '/,CLSTAT(18)/' '/,
     3     U(18)/18/,RL(18)/0/,NXTREC(18)/0/,LSTREC(18)/0/
      DATA FILNAM(19)/'LDAFIL'/,FILACC(19)/'SEQUENTIAL'/,
     1     FILFMT(19)/'UNFORMATTED'/,
     2     OPSTAT(19)/'OLD'/,CLSTAT(19)/'KEEP'/,
     3     U(19)/ 8/,RL(19)/80/,NXTREC(19)/1/,LSTREC(19)/0/
      DATA FILNAM(20)/'TIFILE'/,FILACC(20)/'SEQUENTIAL'/,
     1     FILFMT(20)/'FORMATTED'/,
     2     OPSTAT(20)/'UNKNOWN'/,CLSTAT(20)/'KEEP'/,
     3     U(20)/20/,RL(20)/80/,NXTREC(20)/1/,LSTREC(20)/0/
      DATA FILNAM(21)/'PXFILE'/,FILACC(21)/' '/,
     1     FILFMT(21)/' '/,
     2     OPSTAT(21)/' '/,CLSTAT(21)/' '/,
     3     U(21)/0/,RL(21)/0/,NXTREC(21)/0/,LSTREC(21)/0/
      DATA FILNAM(22)/'FILE12'/,FILACC(22)/' '/,
     1     FILFMT(22)/' '/,
     2     OPSTAT(22)/' '/,CLSTAT(22)/' '/,
     3     U(22)/0/,RL(22)/0/,NXTREC(22)/0/,LSTREC(22)/0/
      DATA FILNAM(23)/'FILE13'/,FILACC(23)/' '/,
     1     FILFMT(23)/' '/,
     2     OPSTAT(23)/' '/,CLSTAT(23)/' '/,
     3     U(23)/0/,RL(23)/0/,NXTREC(23)/0/,LSTREC(23)/0/
      DATA FILNAM(24)/'APTLIB'/,FILACC(24)/'SEQUENTIAL'/,
     1     FILFMT(24)/'FORMATTED'/,
     2     OPSTAT(24)/'UNKNOWN'/,CLSTAT(24)/'KEEP'/,
     3     U(24)/24/,RL(24)/80/,NXTREC(24)/0/,LSTREC(24)/0/
      DATA FILNAM(25)/' '/,FILACC(25)/' '/,
     1     FILFMT(25)/' '/,
     2     OPSTAT(25)/' '/,CLSTAT(25)/' '/,
     3     U(25)/0/,RL(25)/0/,NXTREC(25)/0/,LSTREC(25)/0/
      DATA FILNAM(26)/' '/,FILACC(26)/' '/,
     1     FILFMT(26)/' '/,
     2     OPSTAT(26)/' '/,CLSTAT(26)/' '/,
     3     U(26)/0/,RL(26)/0/,NXTREC(26)/0/,LSTREC(26)/0/
      DATA FILNAM(27)/' '/,FILACC(27)/' '/,
     1     FILFMT(27)/' '/,
     2     OPSTAT(27)/' '/,CLSTAT(27)/' '/,
     3     U(27)/0/,RL(27)/0/,NXTREC(27)/0/,LSTREC(27)/0/
      DATA FILNAM(28)/' '/,FILACC(28)/' '/,
     1     FILFMT(28)/' '/,
     2     OPSTAT(28)/' '/,CLSTAT(28)/' '/,
     3     U(28)/0/,RL(28)/0/,NXTREC(28)/0/,LSTREC(28)/0/
      DATA FILNAM(29)/' '/,FILACC(29)/' '/,
     1     FILFMT(29)/' '/,
     2     OPSTAT(29)/' '/,CLSTAT(29)/' '/,
     3     U(29)/0/,RL(29)/0/,NXTREC(29)/0/,LSTREC(29)/0/
      DATA FILNAM(30)/' '/,FILACC(30)/' '/,
     1     FILFMT(30)/' '/,
     2     OPSTAT(30)/' '/,CLSTAT(30)/' '/,
     3     U(30)/0/,RL(30)/0/,NXTREC(30)/0/,LSTREC(30)/0/

C
      END
**** SOURCE FILE : GETPRM00.ORG   ***
*
      SUBROUTINE GETPRM
C     DUMMY GETPRM
      RETURN
      END
**** SOURCE FILE : LINKF000.V01   ***
*
*
*  *  LINKF  *   FORTRAN 77 SUBROUTINE   6-DEC-85   E.MCLELLAN
*
*  PURPOSE:     TO CALL NEXT PHASE
*
*  CALLING SEQUENCE:
*                   CALL LINKF(PHASE)
*  ARGUMENTS:
*                   TYPE       DESCRIPTION
*           PHASE   CHARACTER  PHASE NAME
*
*  GLOBAL VARIABLES: NONE
*
*  LOCAL VARIABLES: NONE
*
*  FILES: NONE
*
*  SUBSIDIARIES: NONE
*
      SUBROUTINE LINKF(PHASE)
C
      CHARACTER*8 PHASE
C
      INCLUDE 'DARRAY.INC'
C
      IF (PHASE.EQ.'TRANSLAT') THEN
         CALL START
      ELSE IF (PHASE.EQ.'XECUTION') THEN
         CALL EXEC
      ELSE IF (PHASE.EQ.'CLEDITOR') THEN
         CALL CLED
      ELSE IF (PHASE.EQ.'POSTEXEC') THEN
         CALL ACNTRL
      ELSE
         CALL CFORM('  *** FAILURE IN LINKF - ',DARRAY,1,25)
         CALL CFORM('REQUESTED PHASE = ',DARRAY,26,18)
         CALL CFORM(PHASE,DARRAY,43,8)
         CALL CPRINT(DARRAY)
         CALL ABNEND
      END IF
C
      RETURN
      END
**** SOURCE FILE : M0006631.W02   ***
*
*                MODIFIED                 9-MAY-1989  E.MCLELLAN
       SUBROUTINE SPRVIS
C... PURPOSE,  CALLS EACH PHASE OF APT4 AND EXECUTES IT.  IN ADDITION
C    IT CHECKS FOR ERROR CONDITIONS AND FLAGS WHICH CAN TERMINATE A
C    PART PROGRAM BEFORE ALL PHASES ARE COMPLETE.  BATCH PROCESSING
C    IS POSSIBLE USING THIS SUPERVISOR.
C
C CALLS  LOAD MODULES   TRANSLAT,XECUTION,CLEDITOR,POSTEXEC.
C
C
C... DICTIONARY
C
C ABEND  - FLAG INDICATING ABNORMAL TERMINATION
C ASM    - FLAG TO INDICATE IF ASSEMBLY APPROACH IS TO BE USED
C CFLAGS - SEE ERR,XC,CL,PX
C CL     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 3
C CX     - HOLDS CURRENT STRING OF EIGHT CHARACTERS
C END      FLAG SET FALSE WHEN IT IS DETERMINED THAT ANOTHER PART
C            PROGRAM FOLLOWS
C ERR    - FLAG INDICATING ERRORS ARE NOT TO TERMINATE PROGRAM
C ERRX   - ERROR LEVEL
C ETIME  - ELAPSED TIME
C FINI   - FLAG TO INDICATE IF A FINI CARD HAS BEEN READ
C INFILE - INPUT FILE
C LXTRAS - SAME AS XTRAS
C PHASE  - NAME OF PHASE BEING EXECUTED
C PX     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 4
C START  - TIME AT WHICH A PART PROGRAM BEGINS EXECUTION
C TIME0  - TIME AT WHICH A PHASE STARTS
C TIME1  - CURRENT TIME
C VLFILE - VARIFACATION LISTING(PRINTER) FILE
C WX     - EQUIVALENT TO CX
C X      - HOLDS CARD IMAGE
C XC     - FLAG INDICATING EXECUTION TO TERMINATE AT PHASE 2
C XTRAS(1)- CONTAINS NUMBER OF ERRORS
C
C
C
C...      32.  PARAMETERS REQUIRED BY SUPERVISOR
C
      INCLUDE 'SUPER.INC'
C
      INCLUDE 'SYMFIL.INC'
C
      DOUBLE PRECISION ETIME
      INTEGER START,TIME0,TIME1
      DIMENSION  DIAGS(33)
      CHARACTER  X(80),CX(8),T,XXXX*80
      CHARACTER*4 WX,XFINI,XBLNK,BLANK
      EQUIVALENCE (T,XBLNK)
      EQUIVALENCE (WX,CX(1))
C
C........SET UP PARAMETERS FOR ASSEMBLY APPROACH
      CHARACTER LXPARM*21,PARASM*16,IRDS*80
C
      CHARACTER*8 PHASE(4)
      CHARACTER*8 PHAS1(5)
      EQUIVALENCE (PHAS1(2),PHASE(1))
      CHARACTER*8 ACTION(3)
      COMMON/PARLST/JPAR
      CHARACTER*4 KPAR(4),JPAR(20)
C
      COMMON /AENT/ KENTRY
      COMMON /CMPTST/ICMTES
C
      CHARACTER*132 DARRAY
      CHARACTER LARRAY(132),LPCOMP*4
      EQUIVALENCE (DARRAY,LARRAY(1))
C
      DATA  WX/'    '/, XFINI/'FINI'/
      DATA  XBLNK,BLANK/'    ','    '/
      DATA  LXPARM/'OVLY,NOLIST,NOMAP,LET'/
      DATA  PARASM/'LOAD,NODECK,LIST'/
      DATA IRDS/'REMARK'/
      DATA PHASE/'TRANSLAT','XECUTION','CLEDITOR','POSTEXEC'/
      DATA PHAS1(1)/'SUPERVIS'/
      DATA ACTION/' CONTINU','TERMINAT','TERMINAT'/
      DATA KPAR/'TR  ','XC  ','CL  ','PX  '/
      DATA DARRAY/' '/
      DATA LPCOMP/'COMP'/
C  ------------------- INITIALIZE FOR PART PROGRAM ----------------
      IABND=0
      ICNT=0
      CALL GETPRM
      CALL ARTIME
C
      IRDSAV=IRDS
      END= .TRUE.
   50 FINI=.FALSE.
C
C START THE CLOCK
  100 CALL CLOCF4(START)
      TIME0 = START
C
C INTERPRETIVE METHOD IS THE DEFAULT.
      ASM  = .FALSE.
      JJEX = 0
      JEX = 0
C---      DEFAULT- OUTPUT PRINT NOT COMPRESSED
      ICMTES=0
C
C ERRORS ARE TO TERMINATE PROGRAM,ALL PHASES WILL BE PROCESSED.
      ERR=.FALSE.
      XC=.FALSE.
      CL=.FALSE.
      PX=.FALSE.
      I=1
      IF(ICNT.EQ.0) GO TO 106
      IF(JPAR(1).EQ.KPAR(1)) I=1
      IF(JPAR(1).EQ.KPAR(2)) I=2
      IF(JPAR(1).EQ.KPAR(3)) I=3
      IF(JPAR(1).EQ.KPAR(4)) I=4
  106 CONTINUE
C
C---       TEST FOR COMP IN PARM LIST
      IF(JPAR(1).EQ.LPCOMP) ICMTES=1
C START NEW PAGE ON PRINTER.
      CALL CFORM ('1',DARRAY,1,1)
      CALL CFORM('CAM-I SCULPTURED SURFACE SSV3  SYSTEM.',DARRAY,5,38)
      CALL CFORM(' CAM-I INC., ARLINGTON,TEXAS  MAY,89 ',DARRAY,43,37)
      CALL CPRINT(DARRAY)
      CALL CPRINT (DARRAY)
C
C
C  EXECUTE PHASE I
C
  119 CONTINUE
C
C SET ERROR LEVEL AT 0.
      ERRX = 0
C
C SET ERROR COUNT AT 0.
      XTRAS(1) = 0
      XTRAS(2) = 0
C
C ASSUME ABNORMAL TERMINATION.
      ABEND= .TRUE.
C
C TEST FOR ASSEMBLY APPROACH AND PHASE TWO.
      J=1
      IF(ASM.AND.I.EQ.2) GO TO 999
      IF ( JPAR(1) .EQ. KPAR(2)) ASM = .TRUE.
C
C LOAD AND EXECUTE PHASE (I).
  120 CALL LINKF (PHASE(I))
C...     SET J - DETERMINE IF PROCESSING SHOULD CONTINUE
      J = 1
C
C IF ERR LEVEL GREATER THAN 4 AND CONTINUE NOT INDICATED, END PART PROG.
      IF(ERRX.GT.JJEX) JJEX = ERRX
      IF(JEX.EQ.2.AND.I.EQ.3) J=2
      IF(.NOT.ERR.AND.(ERRX.GT.4).AND.(I.NE.2)) J=2
      IF(.NOT.ERR.AND.(ERRX.GT.4).AND.(I.EQ.2)) JEX=2
C
C IF ABEND NOT TURNED OFF OR ERR LEVEL GREATER THAN 8, TERMINATE.
      IF(ABEND.OR.ERRX.GT.8) J=3
C IF NO ERRORS, CONTINUE.
      IF(ERRX.EQ.0) GOTO 110
C
C PRINT NUMBER OF ERRS AND ACTION TO BE TAKEN.
  130 CALL ICONV(XTRAS(1),DARRAY,5,3)
      CALL CFORM('0***',DARRAY,1,4)
      CALL CFORM(' ERROR(S) AND     WARNING(S) IN THIS PHASE. PROCESSING
     / ',DARRAY,9,55)
      CALL ICONV(XTRAS(2),DARRAY,23,3)
      CALL CFORM(ACTION(J),DARRAY,64,8)
      CALL CFORM('ED.***',DARRAY,72,6)
      CALL CPRINT (DARRAY)
C
C PRINT ELAPSED TIME.
  110 CALL CLOCF4(TIME1)
      ETIME = IABS(TIME1-TIME0)/100.0
      CALL CFORM('0APT-IV   SSV3 ',DARRAY,1,15)
      CALL CFORM(PHASE(I),DARRAY,19,8)
      CALL CFORM('PHASE - CPU TIME=',DARRAY,29,17)
      CALL FCONV(ETIME,DARRAY,47,6,2)
      CALL CFORM('SECS.',DARRAY,55,5)
      CALL CPRINT (DARRAY)
C
C  IF J=1, PROCESSING CONTINUES.  IF J=2, PROCESSING TERMINATES.
C        IF J=3, ABNORMAL TERMINATION.
      GO TO (140,800,900), J
C
C WAS THERE A REQUEST TO TERMINATE AT THE END OF THIS PHASE.
  140 CONTINUE
C
      TIME0 = TIME1
      IF (I.EQ.4) GO TO 800
      I=I+1
      IF(.NOT.CFLAGS(I))GOTO 119
C
C
C
C  XC,CL OR PX APPEARS IN CONTRL/ STATEMENT OR NOPOST=CNTRL/PX
C
  600 CALL CFORM('0***PROGRAM TERMINATED AT REQUESTED PHASE***',
     C         DARRAY,1,44)
      CALL CPRINT (DARRAY)
      J=4
C
C  END OF A PART PROGRAM PROCESSING.
C
  800 ETIME = IABS(TIME1-START)/100.0
      CALL FCONV(ETIME,DARRAY,47,6,2)
      CALL CFORM('0',DARRAY,1,1)
      CALL CFORM('TOTAL - CPU TIME=',DARRAY,29,17)
      CALL CFORM('SECS.',DARRAY,55,5)
      CALL CPRINT (DARRAY)
C
C
      CALL CFORM('0APT-IV    ERROR LEVEL IN THIS PART PROGRAM =',
     C  DARRAY,1,45)
      CALL ICONV(JJEX,DARRAY,45,3)
      CALL CPRINT (DARRAY)
      IF (IABND.EQ.1) GO TO 999
C
C
C CHECK FOR END OF DATA - THAT IS, NO MORE PART PROGRAMS
  850 IF (ASM) GO TO 999
      IF (.NOT. END) GO TO 999
      CALL CREAD(IRDSAV,IRET)
      IF(IRET.EQ.1) GO TO 999
      END=.FALSE.
      CALL TAPOP(CLFIL3,-3)
      CALL TAPOP(EXFILE,-3)
      CALL TAPOP(MACTXT,-3)
      CALL TAPOP(XNUM,-3)
      CALL CFORM('0*** ONLY ONE PART PROGRAM PERMITTED***',DARRAY,1,39)
      CALL CPRINT(DARRAY)
      GOTO 999
C
C
      ENTRY ABNEND
C
      IABND=1
C
C  PHASE DID NOT HAVE A NORMAL ENDING.
C
  900 CALL CFORM('0***ABNORMAL TERMINATION OF ',DARRAY,1,28)
      CALL CFORM(PHASE(I),DARRAY,28,8)
      CALL CFORM('PHASE***',DARRAY,37,8)
      CALL CPRINT(DARRAY)
      JJEX = 16
      IF(IABND.EQ.1) GO TO 800
C
      IF(FINI) GOTO 800
C
C  NO FINI.  SKIP TO END OF PART PROGRAM.
  905 CALL CREAD(XXXX,IRET)
      WX=BLANK
      IF(IRET.EQ.1) GO TO 999
      J=1
      K=0
  920 K=K+1
      T=X(K)
      IF (XBLNK .EQ. BLANK) GO TO 920
      CX(J) = X(K)
      J=J+1
      IF (J.LE.4) GO TO 920
      IF (WX .EQ. XFINI) GO TO 800
      GOTO 905
C
C
C  END OF ALL PART PROGRAM PROCESSING.
C
  999 JRTN=JJEX
      IF ( J.EQ.1 .AND. ERRX.LT.4 ) JRTN = 0
      CALL CPUCLO
      CALL CRTN(JRTN)
      GO TO 999
C
      END
**** SOURCE FILE : M0000486.W01   ***
*
C....  SYMFIL BLOCK   .....  MEMBER NAME = SSYMFIL
      BLOCK DATA SYMFL
      INCLUDE 'SYMFIL.INC'
C
      DATA CLFILP,CLFILE,CLFIL3,EXFILE,INFILE/
     1          1,     2,     3,     4,     5/,
     2     VLFILE,PNCHFL,XCAN  ,MACTXT,XNUM  /
     3          6,     7,     8,     9,    10/,
     4     ELFIL1,ELFIL2,ELFIL3,ELFIL4,CPFILE/
     5         11,    12,    13,    14,    15/,
     6     AXFILE,POFILE,ELFILE,LDAFIL,TIFILE/
     7         16,    17,    18,    19,    20/
     8     PXFILE,NFIL12,NFIL13,LIBFIL/
     9         21,    22,    23,    24/
      END
