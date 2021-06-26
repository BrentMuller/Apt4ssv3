**** SOURCE FILE : APT24100.ORG   ***
*
      SUBROUTINE APT241
      INTEGER HANDL
      EXTERNAL HANDL
c      CALL LIB$ESTABLISH(HANDL)
      write(*,*)'vax lib_establish routine APT241.f'
      RETURN
      END
C
C
      SUBROUTINE APT242
c      CALL LIB$SIGNAL(%VAL(SS$_ACCVIO))
      write(*,*)'vax lib_signal routine APT241.f'
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
      write(*,*)'vax sys_unwind routine APT241.f'
      RETURN
      END
