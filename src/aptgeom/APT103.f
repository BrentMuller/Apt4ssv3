**** SOURCE FILE : M0002811.V05   ***
*
C...  FORTRAN SUBROUTINE APT103                  6/70      RW
C
C                          FORTRAN SUBROUTINE APT103
C
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A BOUNDED GEOMETRY
C              OBJECT DEFINED BY THE FOLLOWING APT STATEMENT.
C
C              OBJCTN=OBJECT/BOUND1,BOUND2,...,BOUNDI
C
C CALLING SEQUENCE  CALL APT103(OBJCTN,BOUNDN,M)
C
C ARGUMENTS    OBJCTN    ARRAY TO CONTAIN THE CANONICAL FORM OF THE
C                        BOUNDED GEOMETRY OBJECT
C
C              BOUNDN    ARRAY CONTAINING THE CANONICAL FORM OF THE
C                        BOUNDED SURFACE OR OBJECT IN \HE OPERAND LIST
C                        CURRENTLY BEING PROCESSED
C
C              M         INDICATOR IDENTIFYING THE POSITION OF BOUNDN
C                        IN THE OPERAND LIST
C
C                        TAKES THE FOLLOWING VALUES.
C                        3  IF BOUNDN IS THE LAST ARGUMENT
C
C                        2  IF BOUNDN IS ANYTHING BUT THE FIRST
C                           OR LAST ARGUMENT
C
C                        1  IF PROCESSING THE FIRST ARGUMENT OF A
C                           STATEMENT WITH TWO OR MORE ARGUMENTS
C
C                        0  IF PROCESSING THE FIRST ARGUMENT OF A
C                           STATEMENT WITH ONLY ONE ARGUMENT.
C
C CALLED BY    NONE
C
C SUBSIDIARIES TYPE              ENTRY
C
C              INTEGER FUNCTION  ADDRSS
C              SUBROUTINE        ERROR
C              SUBROUTINE        INCAN
C              SUBROUTINE        PRINT
C              SUBROUTINE        UNPACK
C
C RESTRICTIONS NONE
C
C DIAGNOSTICS  ERROR CODE  COMMENT
C              85          REFERENCED ELEMENT NOT PROPERLY DEFINED.
C
C              86          BOUNDED GEOMETRY ELEMENT HAS BEEN REDEFINED
C                          WITH A DIFFERENT NUMBER OF ARGUMENTS.
C
C
C
      SUBROUTINE APT103(OBJCTN,BOUNDN,M)
C
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
C
C
      INCLUDE 'BLANKCOM.INC'
C
      DIMENSION OBJCTN(1),BOUNDN(1)
      INTEGER ADDRSS
      LOGICAL ERR85,ERR86
      LOGICAL CKSTR
C
C                                                                   *CD*
      CHARACTER*1 TEST,DLR
      LOGICAL DLRTST(8)
      EQUIVALENCE (TTEST,DLRTST(1))
      DATA DLR/'$'/
C                                                                   *CD*
C
C
      IF (M .GT. 1) GO TO 2
      N=0
      ERR85=.FALSE.
      ERR86=.FALSE.
      CALL UNPACK(OBJCTN,MODE,IOBJSZ,ISUB)
      IF(M .EQ. 0)M=3
   2  N=N+2
C
C...  MAKE SURE OBJCTN IS NOT REDEFINED ERRONEOUSLY.
C
      IF (N .GT. IOBJSZ) GO TO 20
C
C...  MAKE SURE BOUNDN IS PROPERLY DEFINED.
C
      CALL UNPACK(BOUNDN,MODE,ISIZE,ISUB)
      IF (CKSTR(BOUNDN(1)) .OR. ISUB .NE. 0) GO TO 10
C
C        * STORE NAME IN CANONICAL FORM
      OBJCTN(N-1)=BOUNDN(ISIZE+1)
C
C...  IF BOUNDN IS AN UNASSIGNED NESTED ARGUMENT, GENERATE DIAGNOSTIC.
C
      TTEST = OBJCTN(N-1)
      CALL HOLFRM(DLRTST(1),TEST,1,1,NWD)
      IF (TEST .EQ. DLR) ERR85 = .TRUE.
C
C...  DETERMINE INDEX FOR BOUNDN
      IOBJN=(ADDRSS(BOUNDN)-ADDRSS(COM))/KWRDSZ+1
      IF (CANFLG) CALL INCAN(IOBJN)
      OBJCTN(N)=IOBJN-IBLK1
C
   5  IF (M .EQ. 3) GO TO 30
      RETURN
C
C...  ERROR 85:  REFERENCED ELEMENT NOT PROPERLY DEFINED.
C
   10 CALL UNDEF(OBJCTN(N-1))
      OBJCTN(  N)=0
      ERR85=.TRUE.
      GO TO 5
C
C...  ERROR 86:  BOUNDED GEOMETRY ELEMENT HAS BEEN REDEFINED WITH
C     A DIFFERENT NUMBER OF OPERANDS.
C
   20 ERR86=.TRUE.
      IF (M .NE. 3) GO TO 40
   30 IF (N .NE. IOBJSZ) ERR86=.TRUE.
C
      IF (PRNTON) CALL PRINT(3,OBJCTN,1)
      IF (ERR85) CALL ERROR(85,'APT103  ')
      IF (ERR86) CALL ERROR(86,'APT103  ')
      IF (ERR86 .OR. ERR85 ) BNDERR = .TRUE.
   40 RETURN
      END