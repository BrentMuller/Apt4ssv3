**** SOURCE FILE : APT24100.ORG   ***
*
      SUBROUTINE APT241
      INTEGER HANDL
      EXTERNAL HANDL
      CALL LIB$ESTABLISH(HANDL)
      RETURN
      END
C
C
      SUBROUTINE APT242
      CALL LIB$SIGNAL(%VAL(SS$_ACCVIO))
      RETURN
      END
C
C
      INTEGER FUNCTION HANDL(S,M)
      INTEGER S(3),M(5)
c      INCLUDE 'SYS$LIBRARY:SIGDEF'
      HANDL=SS$_RESIGNAL
      IF (S(2).EQ.SS$_UNWIND) THEN
      RETURN
      END IF
c      CALL SYS$UNWIND(,)
c   i don't know what to replace this with right now, so..
      call abort
      RETURN
      END
