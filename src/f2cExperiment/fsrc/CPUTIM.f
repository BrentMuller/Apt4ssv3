**** SOURCE FILE : CPUTIM.ORG   ***
*
c original code in this source file lower-case; made 
c upper-case to distinguish my changes
c     INTEGER*4 FUNCTION CPUTIM
c     INTEGER*2 W_LEN1,W_COD1
c     INTEGER*4 L_ADD1,L_LENADD1
c      INTEGER*4 STATUS,SYS$GETJPI
c     integer*4 sys$getjpi
c     logical status
c     PARAMETER (JPI$_CPUTIM='0407'X)
c     COMMON/JPI_PARAMS/W_LEN1,W_COD1,L_ADD1,L_LENADD1
c     DATA W_LEN1,W_COD1/4,JPI$_CPUTIM/
c     DATA L_LENADD1/0/,ISTART/0/
c      L_ADD1=%LOC(CPUTIM)
c      STATUS=SYS$GETJPI(,,,W_LEN1,,,)
c     status =0
c     IF(.NOT.STATUS)THEN
c           WRITE(6,*)'*** ERROR IN GETTING CPU TIME ***'
c           CPUTIM=0
c           RETURN
c     END IF
c     RETURN
c     END
