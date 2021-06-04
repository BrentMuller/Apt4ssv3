**** SOURCE FILE : APT24100.ORG   ***
*
      SUBROUTINE APT241
      INTEGER HANDL
      EXTERNAL HANDL
c      CALL LIB$ESTABLISH(HANDL)
      call libsestablish(handl)
      RETURN
      END
C
C
      SUBROUTINE APT242
c      CALL LIB$SIGNAL(%VAL(SS$_ACCVIO))
      RETURN
      END
C
C
      INTEGER FUNCTION HANDL(S,M)
      INTEGER S(3),M(5)
c      INCLUDE 'SYS$LIBRARY:SIGDEF'
c      HANDL=SS$_RESIGNAL
c      IF (S(2).EQ.SS$_UNWIND) THEN
c      RETURN
c      END IF
c      CALL SYS$UNWIND(,)
c   i don't know what to replace this with right now, so..
      call abort
      RETURN
      END
