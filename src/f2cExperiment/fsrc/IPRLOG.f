**** SOURCE FILE : M0006642.V03   ***
*
C
C              FORTRAN SUBROUTINE IPRLOG
C
C LINKAGE      SUBROUTINE IPRLOG
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ICMPRS          SUBROUTINE    PROLOG
C          INTEGER FCT.  NAME
C
      SUBROUTINE IPRLOG
C
      IMPLICIT INTEGER (A-Z)
C
C       19.    INTERMEDIATE LANGUAGE TEXT
C
      COMMON/ILTEXT/ILTEXT
      DIMENSION ILTEXT(94),TEXTIN(90)
C TPNTRX:      POINTER TO LAST TEXTIN ENTRY
      EQUIVALENCE (TPNTRX,ILTEXT(3))
C OPTEXT:      CONTAINS COMMAND CODE FOR CURRENT I.L. COMMAND
      EQUIVALENCE (OPTEXT,ILTEXT(4))
C TEXTIN:      STORAGE FOR CURRENTLY GENERATED I.L. COMMAND ARGUM.LIST
      EQUIVALENCE (TEXTIN(1),ILTEXT(5))
C**
      CHARACTER*6 S21TS1
      DATA S21TS1/'$21T$1'/
C
      CALL ICMPRS
      OPTEXT = 12
      TPNTRX=4
      TEXTIN(1)=NAME(S21TS1)
      TEXTIN(2) =21
      TEXTIN(3)= 1
      TEXTIN(4)= 1
      RETURN
      END
