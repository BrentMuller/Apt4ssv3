**** SOURCE FILE : CPUTIM00.IBM;1   ***
*
C.... INTEGER FUNCTION CPUTIM
C     UTILIZING IBM FORTRAN UTILITY DATETM ( TXTLIB UTILITY )
C
      INTEGER FUNCTION CPUTIM()
c      CHARACTER*23 DATTIM
      REAL ECPU,ETIME,ETCPU
      character*8 date
      character*10 time
      character*5 zone
C
c      CALL DATETM(DATTIM,ECPU,ETIME,ETCPU)
        
       call date_and_time(date, time, zone)
C
c      CPUTIM=INT(ECPU*100.0)
      RETURN
      END
