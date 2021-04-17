**** SOURCE FILE : M0006671.W01   ***
*
C
C              FORTRAN SUBROUTINE READ
C
C LINKAGE      SUBROUTINE READ (INCHAR)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ICONV           SUBROUTINE    INPUT
C          SUBROUTINE    CREAD           SUBROUTINE    PRO026
C          SUBROUTINE    LIBRD
C          SUBROUTINE    CPRINT
C          SUBROUTINE    ALARM
C          SUBROUTINE    CFORM
C
      SUBROUTINE READ (INCHAR)
C
      IMPLICIT INTEGER (A-Z)
C
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C
C        2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST
      DIMENSION STKLST(300),STACK(2,99)
C TOP:         POINTER TO LAST STACK ENTRY
      EQUIVALENCE (TOP,STKLST(1))
C STACK:       WORKING STACK
      EQUIVALENCE (STACK(1,1),STKLST(4))
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),RTERM(2),SLASH(2),QUOTE(2)
C RTERM:       (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM '
      EQUIVALENCE (RTERM(1),CODE(7))
C SLASH:       (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     '
      EQUIVALENCE (SLASH(1),CODE(9))
C QUOTE:       (1)=CODE CLASS 12000,(2)=NAMTBL INDEX OF ''     '
      EQUIVALENCE (QUOTE(1),CODE(23))
C
C        4.    PRODUCTION TABLE
C
      COMMON/SRCTBL/SRCTBL
      DIMENSION SRCTBL(502),META(50)
C META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES
      EQUIVALENCE (META(1),SRCTBL(3))
C
C        5.    PROGRAM CONTROL FLAGS
C
      COMMON/FLAGS/FLAGS
      LOGICAL NEWSTM
      DIMENSION FLAGS(4)
C NEWSTM:      TRUE WHEN NEXT SOURCE STATEMENT REQUESTED FOR PROCESS
      EQUIVALENCE (NEWSTM,FLAGS(2))
C
C        7.    STRING STORAGE AREA
C              POINTER TO THE LAST PROCESSED CHARACTER OF A STATEMENT
      COMMON/INPTR/CNT
C
C       11.    SEQUENCE NUMBER STORAGE
C
      INCLUDE 'SEQCOM.INC'
C SEQNO:       INTERNALLY GENERATED STATEMENT NUMBER
C
C       20.    IO - ARRAY
C              I/O ARRAY
      INCLUDE 'DARRAY.INC'
C
C       22.    MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      LOGICAL MACLDD
      DIMENSION MACXX1(71)
C MACLDD:      TRUE WHEN MACRO TEXT IS TO BE LOAD INTO MCBUFF TABLE
      EQUIVALENCE (MACLDD,MACXX1(7))
C
C      25A.    MACRO PROCESSING ARRAY
C
      COMMON/MACXX5/MACXX5
      DIMENSION MACXX5(135),ITMPSV(135)
C ITMPSV:      TEMPORARY STORAGE DURING FINAL MACRO PROCESSING
      EQUIVALENCE (ITMPSV(1),MACXX5(1))
C
C       29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULI
      DIMENSION MODULI(2)
C MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS
      EQUIVALENCE (MODULO,MODULI(1))
C
C       36.    SYSTEM MACRO AND SEGMENT READ VARIABLES
C
      COMMON/MACSEG/MACSEG
      LOGICAL LMRSTR,LMREND
      DIMENSION MACSEG(6)
C NMSEG:       NAMTBL POINTER TO THE NAME OF THE PART PROGRAM SEGMENT
      EQUIVALENCE (NMSEG,MACSEG(2))
C NMMAC:       NAMTBL POINTER TO SYSTEM MACRO NAME
      EQUIVALENCE (NMMAC,MACSEG(3))
C LMRSTR:      FLAG ON STARTS READING IN A SYSTEM MACRO
      EQUIVALENCE (LMRSTR,MACSEG(4))
C LMREND:      FLAG ON AFTER COMPLETION READING A SYSTEM MACRO
      EQUIVALENCE (LMREND,MACSEG(6))
C
C       39.    COMMON BLOCK LIBRARY PRINTING FLAG
C              FLAG ON CAUSE PRINTING OF INPUT LIBRARIES
      COMMON/LIBPRT/LIBPRT
      LOGICAL LIBPRT
C
C       40.    PARAMETERS REQUIRED BY SUPERVISOR
C
      INCLUDE 'SUPER.INC'
C END:         FLAG TO INDICATE LAST PART PROGRAM
C IRDSAV:      SAVE AREA FOR FIRST CARD IN PART PROGRAM
C
C       43.    DO LOOP CONTROL VALUES
C
      COMMON/DOLOOP/DOLOOP
      LOGICAL DLRFLG
      DIMENSION DOLOOP(8)
C DLRFLG:      FLAG IS ON WHEN CONTINUATION CARD EXPECTED
      EQUIVALENCE (DLRFLG,DOLOOP(8))
C
C       44.    ERROR POSITION TABLE
C
      COMMON/ERRPOS/ERRPOS
      INTEGER ERRPOS,ERRPNT
      DIMENSION ERRPOS(302),ERRPNT(100)
C ERRPNT:      CONTAINS POINTERS TO INPUT STATEMENT TEXT POSITIONS
      EQUIVALENCE (ERRPNT(1),ERRPOS(3))
C*
      PARAMETER (NVLD=80)
      CHARACTER RDCHAR*80,VALIDC*(NVLD)
      DIMENSION INCHAR(76),CONV(NVLD)
      CHARACTER*6 IA(5),LRARG
      CHARACTER*4 IBLK,CFINI
      LOGICAL QTFLG,READFG,LIBFLG
      DATA          READFG /.TRUE./
      DATA  II,IBLK,CFINI,LINEST /0,'    ','FINI',13/
      DATA IA/'PARTNO','TITLES','PPRINT','INSERT','REMARK'/
C
C     LIST OF VALID CHARACTERS
C
      DATA VALIDC( 1:10)/'0123456789'/
      DATA VALIDC(11:36)/'ABCDEFGHIJKLMNOPQRSTUVWXYZ'/
      DATA VALIDC(37:48)/' +-*/=.,''()$'/
C  ASCII/EBCDIC REPRESENTATION OF BCDIC CHARACTERS ()+='
      DATA VALIDC(49:53)/'%<&#@'/
C  SEMI-COLON
      DATA VALIDC(54:54)/';'/
C  LOWER CASE CHARACTERS
      DATA VALIDC(55:80)/'abcdefghijklmnopqrstuvwxyz'/
C
C                   CONV TABLE
C
C                 0   1   2   3   4   5   6   7   8   9
      DATA CONV/  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
C                 A   B   C   D   E   F   G   H   I
     1           15, 16, 17, 18, 19, 20, 21, 22, 23,
C                 J   K   L   M   N   O   P   Q   R
     2           27, 28, 29, 30, 31, 32, 33, 34, 35,
C                 S   T   U   V   W   X   Y   Z
     3           40, 41, 42, 43, 44, 45, 46, 47,
C                SP   +   -   *   /   =   .   ,   '   (   )   $
     4           38, 14, 26, 37, 39, 12, 24, 48, 13, 49, 25, 36,
C                 %   <   &   #   @   ;
     5           49, 25, 26, 12, 13,  0,
C                 a   b   c   d   e   f   g   h   i
     6           15, 16, 17, 18, 19, 20, 21, 22, 23,
C                 j   k   l   m   n   o   p   q   r
     7           27, 28, 29, 30, 31, 32, 33, 34, 35,
C                 s   t   u   v   w   x   y   z
     8           40, 41, 42, 43, 44, 45, 46, 47/
C**
      external alarm
      IF(.NOT.DLRFLG)INLIN=0
      IF(.NOT.READFG) GO TO 110
      NUMCHR = 72
      NUMI = 0
C
C...   IF END IS FALSE, FIRST CARD FOR THIS PROGRAM IS IN IRDSAV
C
      LIBFLG=.TRUE.
      IF(END)GO TO 15
      RDCHAR=IRDSAV
      END=.TRUE.
      GO TO 25
C
C                   READ CARD IMAGE
C
   15 IF(NMSEG.EQ.0)GO TO 16
      LRARG=CNAMTB(NMSEG)
      CALL LIBRD(LRARG,IFLAG,RDCHAR)
      IF(IFLAG.EQ.0) GO TO 27
      IF(IFLAG.NE.1)CALL ALARM(74,0,8,'READ    ')
      NMSEG=0
      GO TO 19
   16 IF(NMMAC.NE.0)GO TO 32
   19 CALL CREAD (RDCHAR,IEND)
      IF (IEND.EQ.1) GO TO 50
   25 LIBFLG=.FALSE.
   26 CNT=0
      GO TO 34
   27 IF(LIBPRT) GO TO 25
      GO TO 26
   32 IF(.NOT.LMRSTR)GO TO 38
      IRDSAV=RDCHAR
      ITMPSV(1)=CNT-1
      LMRSTR=.FALSE.
   38 LRARG=CNAMTB(NMMAC)
      CALL LIBRD(LRARG,IFLAG,RDCHAR)
      IF(IFLAG.EQ.0) GO TO 27
      IF(IFLAG.NE.1)CALL ALARM(74,0,8,'READ    ')
      RDCHAR=IRDSAV
      CNT=ITMPSV(1)
      TOP=ITMPSV(2)
      DO 37 I=1,TOP
      STACK(1,I)=ITMPSV(2*I+1)
      STACK(2,I)=ITMPSV(2*I+2)
   37 CONTINUE
      I=NAMTBL(NMMAC)/MODULO
      STACK(2,4)=META(I)
      NMMAC=0
      LMREND=.TRUE.
C
   34 QTFLG=.FALSE.
C        CHECK FOR PARTNO, TITLES, PPRINT, INSERT, REMARK
      DO 90 I=1,5
      IF(RDCHAR(1:6).NE.IA(I))GO TO 90
      J=0
      IF(I.EQ.5)GO TO 80
      GO TO 98
   90 CONTINUE
   40 J=0
      DLRFLG=.FALSE.
      READFG = .TRUE.
      L = NUMI + 1
      DO 70 I=L,72
C...FOR EACH CHARACTER INPUT CHECK IF A VALID CHARACTER
C   INCHAR(I)=0 INVALID CHARACTER
C   OTHERWISE LOCATION OF CHARACTER IN NAME TABLE
      II=INDEX(VALIDC,RDCHAR(I:I))
      IF (II.EQ.0) THEN
        INCHAR(I)=0
      ELSE
        INCHAR(I)=CONV(II)
      ENDIF
C   DOLLAR GESETZT?
      IF(DLRFLG)GOTO 75
C   HOCHKOMMA?
      IF(II.NE.45)GO TO 43
      IF(QTFLG)GOTO42
      IF(J.EQ.0)GOTO41
C  VORHERGEHENDES ZEICHEN HOCHKOMMA? :FORTSETZUNG EINER ZEICHENKETTE
      IF(INCHAR(J).NE.13)GOTO41
      QTFLG=.TRUE.
      J=J-1
      GOTO 61
C  NEUER START EINER ZEICHENKETTE
   41 QTFLG=.TRUE.
      GOTO 60
   42 QTFLG=.FALSE.
      GO TO 60
   43 IF(.NOT.QTFLG)GO TO 45
C AUSGABE EINES NEGATIVEN BUCHSTABEN-WERTES,DA ZEICHENKETTE
   61 J=J+1
      INCHAR(J)=-CONV(II)
      GOTO 70
C     AUF BLANK PRUEFEN
   45 IF(II.EQ.37)GO TO 70
C
C     STRICHPUNKT  = ENDE EINES APT-SATZES
C
      IF(II.EQ.54) GOTO 105
C
C        AUF DOLLAR PRUEFEN
      IF(II.EQ.48)DLRFLG=.TRUE.
C    AUSGABE DES NAMENSTAFEL-INDEX
   60 J=J+1
      INCHAR(J)=CONV(II)
      ERRPNT(J)=I+INLIN
   70 CONTINUE
      IF(NUMI .NE. 0) NUMCHR = 85 - LINEST
C  VERHINDERUNG VON UEBER KARTENGRENZE REICHENDER ZEICHENKETTE
      IF(.NOT.QTFLG)GOTO 80
      J=J+1
      INCHAR(J)=QUOTE(2)
C
C        END OF CARD - SET POINTER TO RTERM
   80 INCHAR(J+1)=RTERM(2)
   82 IF(LIBFLG) GO TO 100
      CALL ICONV(SEQNO ,DARRAY,5,4)
      CALL CFORM('.',DARRAY,9,1)
      CALL CFORM(RDCHAR,DARRAY,LINEST,NUMCHR)
      CALL CFORM(RDCHAR(73:80),DARRAY,85,8 )
      CALL CPRINT (DARRAY)
  100 RETURN
  105 READFG = .FALSE.
      NUMCHR = I
      NUMI = I
      GOTO 80
  110 RDCHAR(1:NUMI)=IBLK
      GO TO 26
C        IS THIS $$
   75 NUMCHR = 72
      INLIN=INLIN+100
      IF(II.EQ.48)GOTO 78
      GO TO 80
   78 J = J - 1
      DLRFLG = .FALSE.
      GO TO 80
C        MISSING FINI - INSERT FINI AND COMPLETE PROCESSING
   50 IFLAG=55
      IF(MACLDD)IFLAG=56
      CALL ALARM(IFLAG,0,4,'READ    ')
      END=.FALSE.
      IF(MACLDD)GO TO 56
      RDCHAR = CFINI
      GO TO 25
   56 IRDSAV=CFINI
      MACLDD=.FALSE.
      NEWSTM=.TRUE.
      INCHAR(1)=RTERM(2)
      CNT=0
      GO TO 100
C        CHANGE PARTNO, TITLES, PPRINT, INSERT TO NEW FORMAT
   98 DO 91 I=7,72
        II=INDEX(VALIDC,RDCHAR(I:I))
        IF (II.EQ.0) THEN
          INCHAR(I)=0
        ELSE
          INCHAR(I)=CONV(II)
        ENDIF
        IF(INCHAR(I).EQ.SLASH(2))GO TO 40
        IF(II.NE.37)GO TO 92
   91 CONTINUE
   92 QTFLG=.FALSE.
      DO 96 K=1,72
      I=73-K
        II=INDEX(VALIDC,RDCHAR(I:I))
        IF (II.EQ.0) THEN
          INCHAR(I)=0
        ELSE
          INCHAR(I)=CONV(II)
        ENDIF
      IF(QTFLG)GO TO 94
   93 IF(II.EQ.37 .AND. I.NE.7)GO TO 96
      QTFLG=.TRUE.
      INCHAR(I+4)=RTERM(2)
      INCHAR(I+3)=QUOTE(2)
   94 IF (II.EQ.0) THEN
        IF(I.GE.7)INCHAR(I+2)=0
        IF(I.LE.7)INCHAR(I)=0
      ELSE
        IF(I.GE.7)INCHAR(I+2)=-CONV(II)
        IF(I.LE.7)INCHAR(I)=CONV(II)
      ENDIF
   96 CONTINUE
      QTFLG=.FALSE.
      INCHAR(7)=SLASH(2)
      INCHAR(8)=QUOTE(2)
      GO TO 82
      END