**** SOURCE FILE : M0000435.V02   ***
*
C
C.....FORTRAN SUBROUTINE              APT332                12/67
C PURPOSE      TO WRITE ONTO THE VERIFICATION LISTING TAPE A
C              GROUP OF COMMON VARIABLES FOR EACH DYNDMP CALL
C              FROM AN ACTIVATED DYNDMP BREAKPOINT.
C LINKAGE      CALL APT332
C ARGUMENTS    NONE
C SUBSIDIARIES NONE
      SUBROUTINE APT332
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C...  THIS PROGRAM WRITES THE DYNDMP INFORMATION BLOCKS ONTO THE
C     VERIFICATION LISTING TAPE
C
      COMMON / EDITOR/EDITOR
C
      DIMENSION EDITOR (1500)
C
      EQUIVALENCE (EDITOR(1500),ED(1500))
C
      DIMENSION ED(1500)
      INTEGER   WORDNO(2)
C
      DIMENSION NUMBER(2)
      EQUIVALENCE(ED(2),NUMBER(1))
      EQUIVALENCE (NUMBER(1), NUMBR1)
      EQUIVALENCE (NUMBER(2), NUMBR2)
C
      GO TO (101,102,103,104,105,106,107,999,999,999,
     1       201,202,203,204,205,206,207,208,209,210,
     2       211,212,213,214,215,216,217,999,999,999,
     3       401,402,403,404,999,999,999,999,999,999,
     4       501,502,503,504,505,999,999,999,999,999),NUMBR2
  101 CALL APT330 (1,62,92,93,94)
      CALL APT330 (-1,89,90,91,0)
      GO TO 9999
  102 CALL APT330 (2,62,80,81,82)
      CALL APT330 (-1,77,78,79,0)
      GO TO 9999
  103 CALL APT330 (3,-10,-55,-56,-50)
      CALL APT330 (-1,-57,30,31,32)
      CALL APT330 (-1,21,22,23,0)
      GO TO 9999
  104 CALL APT330 (4,-10,62,-52,70)
      CALL APT330 (-1,61,71,72,73)
      CALL APT330 (-1,80,81,82,83)
      CALL APT330 (-1,84,85,77,78)
      CALL APT330 (-1,79,0,0,0)
      GO TO 9999
  105 CALL APT330 (5,-10,92,93,94)
      CALL APT330 (-1,89,90,91,0)
      GO TO 9999
  106 CALL APT330 (6,-10,62,70,6)
      CALL APT330 (-1,-7,80,81,82)
      CALL APT330 (-1,77,78,79,92)
      CALL APT330 (-1,93,94,89,90)
      CALL APT330 (-1,91,0,0,0)
      GO TO 9999
  107 CALL APT330 (7,-10,62,67,68)
      CALL APT330 (-1,70,6,-7,69)
      CALL APT330 (-1,61,80,81,82)
      CALL APT330 (-1,77,78,79,92)
      CALL APT330 (-1,93,94,89,90)
      CALL APT330 (-1,91,71,72,73)
      CALL APT330 (-1,98,99,100,0)
      GO TO 9999
  201 CALL APT330 (11,33,34,35,24)
      CALL APT330 (-1,25,26,42,43)
      CALL APT330 (-1,44,117,118,119)
      CALL APT330 (-1,120,121,122,123)
      CALL APT330 (-1,124,125,126,127)
      CALL APT330 (-1,128,0,0,0)
      GO TO 9999
  202 CALL APT330 (12,4,5,0,0)
      GO TO 9999
  203 CALL APT330 (13,-10,47,5,0)
      GO TO 9999
  204 CALL APT330 (14,4,129,130,131)
      CALL APT330 (-1,36,37,38,27)
      CALL APT330 (-1,28,29,30,31)
      CALL APT330 (-1,32,21,22,23)
      GO TO 9999
  205 CALL APT330 (15,-10,-14,30,31)
      CALL APT330 (-1,32,21,22,23)
      GO TO 9999
  206 CALL APT330 (16,-15,4,0,0)
      GO TO 9999
  207 CALL APT330 (17,-10,-13,47,0)
      GO TO 9999
  208 CALL APT330 (18,20,-18,0,0)
      GO TO 9999
  209 CALL APT330 (19,-14,-12,86,87)
      CALL APT330 (-1,88,0,0,0)
      GO TO 9999
  210 CALL APT330 (20,-10,62,70,-54)
      CALL APT330 (-1,63,64,0,0)
      GO TO 9999
  211 CALL APT330 (21,-10,-54,65,66)
      CALL APT330 (-1,77,78,79,0)
      GO TO 9999
  212 CALL APT330 (22,-10,-15,4,20)
      GO TO 9999
  213 CALL APT330 (23,-10,4,0,0)
      GO TO 9999
  214 CALL APT330 (24,-10,-16,47,0)
      GO TO 9999
  215 CALL APT330 (25,-10,-51,-54,62)
      CALL APT330 (-1,70,63,64,65)
      GO TO 9999
  216 CALL APT330 (26,-51,-54,65,66)
      CALL APT330 (-1,77,78,79,39)
      CALL APT330 (-1,40,41,0,0)
      GO TO 9999
  217 CALL APT330 (27,-10,-48,30,31)
      CALL APT330 (-1,32,21,22,23)
      GO TO 9999
  401 CALL APT330 (31,-17,58,74,75)
      CALL APT330 (-1,76,129,130,131)
      GO TO 9999
  402 CALL APT330 (32,46,45,58,74)
      CALL APT330 (-1,75,76,0,0)
      GO TO 9999
  403 CALL APT330 (33,-10,59,60,0)
      GO TO 9999
  404 CALL APT330 (34,-11,103,-101,104)
      CALL APT330 (-1,102,105,106,107)
      CALL APT330 (-1,111,112,113,114)
      CALL APT330 (-1,115,116,108,109)
      CALL APT330 (-1,110,0,0,0)
      GO TO 9999
  501 CALL APT330 (41,-9,-19,-8,0)
      GO TO 9999
  502 CALL APT330 (42,-10,-49,0,0)
      GO TO 9999
  503 CALL APT330 (43,-10,95,96,97)
      CALL APT330 (-1,30,31,32,0)
      GO TO 9999
  504 CALL APT330 (44,-10,-53,47,77)
      CALL APT330 (-1,78,79,0,0)
      GO TO 9999
  505 CALL APT330 (45,30,31,32,0)
      GO TO 9999
  999 CALL APT330 (50,-2,0,0,0)
 9999 RETURN
       END
