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
