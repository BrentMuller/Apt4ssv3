**** SOURCE FILE : ANDF0000.ORG   ***
*
      INTEGER FUNCTION ANDF(A,B)
C
C.   THIS ROUTINE IS COMPILER DEPENDENT.
C
C    TWO POSSIBLE SOLUTIONS ARE OUTLINED HERE
C
C-VAX-VERSION
C
      INTEGER A,B
      ANDF=IAND(A,B)
C
C-PRIME=VERSION
C
C      INTEGER
C      ANDF=AND(A,B)
C
      RETURN
      END
