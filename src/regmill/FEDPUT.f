**** SOURCE FILE : M0001068.V05   ***
*
      SUBROUTINE FEDPUT(FEED)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
      INTEGER ITEMP(2),BCDF
      EQUIVALENCE (FEDRAT,ITEMP(1))
C
C
      ITEMP(1) = BCDF('FEDR')
      ITEMP(2) = BCDF('AT  ')
      CALL APT299(1,FEDRAT,1,FEED)
      IF(IBUG.NE.11) GO TO 999
      CALL BAD(-1,0,' ',0)
      CALL BAD(-1,1,'FEED',FEED)
      CALL BAD(-1,0,' ',0)
  999 CONTINUE
      RETURN
      END
