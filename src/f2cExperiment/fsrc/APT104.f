**** SOURCE FILE : M0002815.V09   ***
*
C
C...  FORTRAN SUBROUTINE APT104                  5/70      RW
C
C                         FORTRAN SUBROUTINE APT104
C
C
C PURPOSE      TO GENERATE THE CFSFIL FILE FOR THE SUBSEQUENT PREP-
C              ARATION OF OBJECT PLOTS AND/OR ENGINEERING COMPUTATIONS
C              AS EFFECTED BY THE FOLLOWING APT STATEMENT
C
C              CFSAVE/PART
C
C CALLING SEQUENCE    CALL APT104(PART)
C
C ARGUMENTS    PART          ARRAY CONTAINING THE CANONICAL FORM FOR
C                            THE OBJECT OF INTEREST.
C
C CALLED BY    NONE
C
C SUBSIDIARIES TYPE              ENTRY
C              INTEGER FUNCTION  ADDRSS
C              SUBROUTINE        ERROR
C              SUBROUTINE        GSURF
C              SUBROUTINE        INCAN
C              INTEGER FUNCTION  XCANON
C              SUBROUTINE        UNPACK
C
C RESTRICTIONS NONE
C
C DIAGNOSTICS  ERROR CODE    COMMENT
C
C              85            REFERENCED ELEMENT NOT PROPERLY DEFINED.
C
C              89            INVALID OR ERRONEOUS CANONICAL FORM
C                            ENCOUNTERED.  BOUNDED GEOMETRY PROCESSING
C                            TERMINATED.
C
C              90            TOO MUCH EMBEDDEDNESS IN BOUNDS AND
C                            OBJECT STATEMENTS.  BOUNDED GEOMETRY
C                            PROCESSING TERMINATED.
C
C
C
      SUBROUTINE APT104(PART)
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      DIMENSION PART(1)
C
      INCLUDE 'BLANKCOM.INC'
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'KNUMBR.INC'
C
C...            SYSTEM I/O FILE NAMES
      INCLUDE 'SYMFIL.INC'
      COMMON/DARRAY/DARRAY(15)
C
C
C...  LOCAL VARIABLES
C
      DIMENSION MSTK(30),IWHICH(30),ISIZE(31),COEBUF(10),
     1               IARRAY(2,24),BNDARY(24)
      LOGICAL CKSTR,CKDTR
      LOGICAL BNDFLG,ERRFLG
      INTEGER ADDRSS,XCANON,BPRTFL,CFSFIL
      EXTERNAL ADDRSS,XCANON
      INTEGER BCDF
      DATA   KMAX,KSMAX/30,24/
C
C...  INITIALIZE.
C
      K = 1
      BNDFLG = .FALSE.
C
C...  DETERMINE VIRTUAL INDEX OF PART(1) IN COM-ARRAY.
C
      IABS = (ADDRSS(PART) - ADDRSS(COM))/KWRDSZ + 1
      INDEX = IABS
      IF (CANFLG) CALL INCAN(INDEX)
      INDEX = INDEX - IBLK1
C
C...  DETERMINE SIZE AND MODE OF CANONICAL FORM FOR PART.
C
      CALL UNPACK(COM(IABS),MODE,ISIZE(1),ISUB)
C
      IF (MODE .NE. 28) GO TO 900
C
C...  PRINT VERIFICATION LISTING.
C
      NN = ISIZE(1) + 1
      BNDNAM = PART(NN)
      CALL CFORM('0',DARRAY,0,1)
      CALL CFORM('CFSAVE/',DARRAY,6,7)
      CALL CFORM(BNDNAM,DARRAY,13,6)
      CALL CPRINT(DARRAY)
      CALL CFORM('NAME PRI.  SUB      * * *  B O U N D I N G   S U R F
     1 A C E S   * * *',DARRAY,1,68)
      CALL CPRINT(DARRAY)
      CALL CFORM('SURF       1ST   SUB MOD  2ND   SUB MOD  3RD   SUB
     1MOD  4TH   SUB MOD  5TH   SUB MOD 6TH   SUB MOD  7TH   SUB MOD
     2 ', DARRAY,6,114)
      CALL CPRINT(DARRAY)
      GO TO 40
C
C...  DETERMINE MODE, SIZE AND SUBSCRIPT OF NEXT FORM AND CHECK VALIDITY
C
   20 NN = K + 1
      CALL UNPACK (COM(IABS),MODE,ISIZ,ISUB)
      IF(ISIZ.LE.0.OR.ISIZ.GT.48.OR.ISUB.LT.0.OR.ISUB.GT.999.OR.MODE.LE.
     1        0) GO TO 900
      ISIZE(NN) = ISIZ
      ASSIGN 90 TO M
C
C...  DETERMINE IF FORM HAS BEEN DEFINED AND CHECK ITS MODE.
C     BYPASS WRITING OF BEVISION INPUT FILE IF PRIOR ERRORS HAVE OCCURED
C
      IF (MODE - 28) 25,30,30
   25 IF (CKDTR(COM(IABS))) GO TO 28
      IF (MODE .EQ. 27) GO TO 60
C
C...  BYPASS WRITING CFSAVE FILE IF PRIOR BOUNDED GEOM. ERR DETECTED.
C
      IF (BNDERR) GO TO 140
      CALL GSURF(COEBUF,COM(IABS),MODE,ISIZ,ERRFLG)
      IF (.NOT. ERRFLG) GO TO 110
C
C...  ERROR 85 - REFERENCED ELEMENT NOT PROPERLY DEFINED.
C
   28 BNDERR = .TRUE.
      CALL ERROR(85,'APT104  ')
      GO TO 140
C...  AN OBJECT.
C
   30 K = K + 1
      IF (K .GT. KMAX) GO TO 910
C
C...  SET MAIN STACK.
C
   40 MSTK(K) = INDEX
      IWHICH(K) = INDEX + 1
      IF (MODE .NE. 28) GO TO 70
C
C...  MAKE SURE CANONICAL FORM IN OBJECT ARGUMENT IS NOT ERRONEOUSLY DE-
C     FINED.  SAVE ITS VIRTUAL INDEX.
C
   45 IF (CKSTR(COM(IABS))) GO TO 900
      INDEX = COM(IABS + 1)
C
C...  DETERMINE ABSOLUTE INDEX.
C
   50 IABS = INDEX + IBLK1
      IF (CANFLG) IABS = XCANON(IABS - 1) + 1
      GO TO 20
C
C...  A BOUNDS.
C     IF NOT THE FIRST BOUND AFTER AN OBJECT GO GET PRIMARY SURFACE.
C
   60 IF (BNDFLG) GO TO 65
C
C...  FOR FIRST BOUND AFTER ENCOUNTERING AN OBJECT STATEMENT, PUT ON STK
C
      BNDFLG = .TRUE.
      GO TO 30
C
C...  SET TO SAVE HALF-SPACE MODIFIER ASSOCIATED WITH BOUNDS ARGUMENT.
C
   65 ASSIGN 100 TO M
      GO TO 80
C
C...  FIRST TIME THRU A BOUNDS STATEMENT.  SET TO PRINT ITS NAME.
C
   70 KS = 1
      NN = ISIZE(K)
      BNDNAM = COM(IABS + NN)
C
C...  DETERMINE VIRTUAL INDEX AND SUBSCRIPT FROM BOUNDS PACKED WORD.
C     SAVE ITS NAME IN BNDARY(KS), HALF-SPACE MODIFIER IN IARRAY(1,KS),
C     AND SUBSCRIPT IN IARRAY(2,KS).
C
   80 BNDARY(KS) = COM(IABS)
      NN = COM(IABS + 1)
      INDEX = NN/K1E4
      IARRAY(2,KS) = (NN - INDEX * K1E4)/K10
      GO TO M, (90,100)
C
C...  SAVE OLD HALF-SPACE MODIFIER IF BOUNDS ARGUMENT IS A BOUNDS.
C
   90 IARRAY(1,KS) = NN - INDEX * K1E4 - IARRAY(2,KS) * K10
C
C...  IF CANONICAL FORM IN BOUNDS ARGUMENT IS ERRONEOUSLY DEFINED,
C     SKIP IT.  IF OKAY, DETERMINE ITS ABSOLUTE INDEX.
C
  100 IF (.NOT.CKSTR(COM(IABS))) GO TO 50
      CALL BADNAM(BNDARY(KS))
      GO TO 140
C
C...  WRITE BEVISION INPUT FILE.
C
  110 IF (KS .EQ. 1) GO TO 120
C
C     WRITE BOUNDING SURFACE COEFFICIENTS.
C
C     WRITE (CFSFIL,112) IARRAY(1,KS),(COEBUF(I), I=1,10)
  112 FORMAT (I2,6F12.6/1X,4F12.6)
      GO TO 140
C
C     WRITE NUMBER OF BOUNDS.
C
  120 ISIZ = (ISIZE(K) - 2)/2
C     WRITE (CFSFIL,125) ISIZ
  125 FORMAT (I4)
C
C     WRITE PRIMARY SURFACE COEFFICIENTS.
C
C     WRITE (CFSFIL,128) (COEBUF(I), I=1,10)
  128 FORMAT (1X,6F12.6/1X,4F12.6)
C
C...  LOOK AT NEXT BOUNDS ARGUMENT AND SAVE POINTER UNTIL ALL BOUNDS
C     ARE FOUND.
C
  140 INDEX = IWHICH(K) + 2
      IS = MSTK(K)
C
C...  TEST FOR END OF A BOUNDS STATEMENT.
C
      IF (INDEX .GT. IS + ISIZE(K)) GO TO 150
      KS = KS + 1
      IF (KS .GT. KSMAX) GO TO 910
C
C...  MORE BOUNDING SURFACES.
C
      IWHICH(K) = INDEX
      IABS = IBLK1 + INDEX - 1
      IF (CANFLG) IABS = XCANON(IABS)
      GO TO 80
C
C...  END OF A BOUNDS STATEMENT.  WRITE IT OUT ON VERIFICATION LISTING.
C
  150 DO 160 I = 2,KS
      IF (IARRAY(1,I) - 2) 152,154,156
  152 IARRAY(1,I) = BCDF('IN  ')
      GO TO 160
  154 IARRAY(1,I) = BCDF('OUT ')
      GO TO 160
  156 IARRAY(1,I) = BCDF('  * ')
  160 CONTINUE
      CALL CFORM(BNDNAM,DARRAY,1,6)
      CALL CPRINT (DARRAY)
      CALL CFORM(BNDARY(1),DARRAY,5,6)
      CALL CFORM('(   )',DARRAY,11,5)
      CALL ICONV(IARRAY(2,1),DARRAY,12,3)
      L=16
      DO 165 I=2,KS
      CALL CFORM(BNDARY(I),DARRAY,L,6)
      CALL CFORM('(   )',DARRAY,L+6,5)
      CALL ICONV(IARRAY(2,I),DARRAY,L+7,3)
      CALL CFORM(IARRAY(1,I),DARRAY,L+11,3)
      L=L+15
      IF(I.EQ.KS) GO TO 164
      IF(L.LT.110) GO TO 165
  164 CALL CPRINT(DARRAY)
      L=16
  165 CONTINUE
      BNDFLG = .FALSE.
  170 K = K - 1
C
C...  ARE WE FINISHED.
C
      IF (K .EQ. 0) GO TO 180
      INDEX = IWHICH(K) + 2
      IS = MSTK(K)
C
C...  TEST FOR END OF OBJECT STATEMENT.
C
      IF (INDEX .GT. IS + ISIZE(K)) GO TO 170
C
C...  MORE OBJECT ARGUMENTS.
C
      IWHICH(K) = INDEX
      IABS = IBLK1 + INDEX - 1
      IF (CANFLG) IABS = XCANON(IABS)
      GO TO 45
C
C...  WRITE MESSAGE IF PRIOR ERRORS DETECTED.
C
  180 IF (BNDERR) GO TO 998
      CALL CFORM('GEOMETRY GENERATION COMPLETED.',DARRAY,8,30)
      CALL CPRINT(DARRAY)
      GO TO 999
C
C...  ERROR 89 - INVALID OR ERRONEOUS CANONICAL FORM ENCOUNTERED.
C     BOUNDED GEOMETRY PROCESSING TERMINATED.
C
  900 CALL ERROR(89,'APT104  ')
      GO TO 998
C
C...  ERROR 90 - TOO MUCH EMBEDDEDNESS IN BOUNDS AND OBJECT STATEMENTS.
C     BOUNDED GEOMETRY PROCESSING TERMINATED.
  910 CALL ERROR(90,'APT104  ')
  998 CALL CFORM('***BOUNDED GEOMETRY ERRORS DETECTED. NO BEVISION INP
     1UT FILE WRITTEN.', DARRAY,8,68)
      CALL CPRINT(DARRAY)
C     REWIND CFSFIL
C
C...  WRITE END OF FILE INDICATOR.
C
  999 CONTINUE
C     WRITE (CFSFIL,125) KM1
C     END FILE CFSFIL
C     REWIND CFSFIL
      RETURN
      END