**** SOURCE FILE : RDSATZ00.ORG   ***
*
      SUBROUTINE RDSATZ(ID,ARRAY,IANZ,NRSATZ,IRET)
C
      DOUBLE PRECISION ARRAY(10)
      INTEGER ID,IANZ,NRSATZ,IRET
C
      READ(UNIT=ID,ERR=90,END=95) (ARRAY(I),I=1,10)
      IRET=0
      RETURN
C
   90 IRET=3
      RETURN
C
   95 IRET=-1
      RETURN
      END
