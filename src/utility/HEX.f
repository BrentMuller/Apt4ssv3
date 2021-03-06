**** SOURCE FILE : HEX00000.ORG   ***
*
*
*  * HEX *  FORTRAN 77 CHARACTER FUNCTION   6.11.85  E.MCLELLAN
*
*  PURPOSE:  TO CONVERT AN INTEGER VALUE TO A CHARACTER STRING
*            REPRESENTING THE EQUIVALENT HEXADECIMAL NUMBER
*
*  CALLING SEQUENCE:
*                   STRING=HEX(VALUE)
*
*  ARGUMENTS:
*                   TYPE       DESCRIPTION
*       VALUE       INTEGER    INTEGER VALUE TO BE CONVERTED
*                              TO HEX CHARACTER STRING
*
*  GLOBAL VARIABLES:  NONE
*
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*       DIV         INTEGER    DIVISORS FOR EACH HALF BYTE
*                              POSITION (POWERS OF 16)
*       J           INTEGER    INTEGRAL QUOTIENT
*       V           INTEGER    DIVIDEND
*       H           CHARACTER  HEX CHARACTERS (0-F)
*
*  FILES:  NONE
*
*  SUBSIDIARIES:  NONE
*
      CHARACTER*8 FUNCTION HEX(VALUE)
C
      INTEGER VALUE,DIV(7),J,V
      CHARACTER H(0:15)
C
      DATA DIV / 268435456, 16777216, 1048576,
     1           65536,  4096,  256,   16    /
C
      DATA H / '0','1','2','3','4','5','6','7',
     1         '8','9','A','B','C','D','E','F'/
C
      V=VALUE
      DO 10 I=1,7
        J=V/DIV(I)
        V=V-J*DIV(I)
        HEX(I:I)=H(J)
  10  CONTINUE
      HEX(8:8)=H(V)
C
      RETURN
      END
