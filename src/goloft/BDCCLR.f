**** SOURCE FILE : M0012333.V01   ***
*
      BLOCK DATA BDCCLR
C
C COMMON FOR REGIONAL STARTUP AND RETRACT VALUES
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      COMMON/CCLEAR/ DIRMOT(3,4)
     *              ,GOFEED(4)
     *              ,GLFEED
     *              ,REGLDA(2)
     *              ,IRETRO(4)
     *              ,IDIRMO(4)
     *              ,ICANIN(4)
     *              ,IFEEDF
C
C              (1) : START
C              (2) : AWAY
C              (3) : BACK
C              (4) : THRU
C DIRMOT(3,4): ARRAY FOR MOTDIR, NORMAL OR VECTOR VALUES
C              (1,I) : VALUES OF MOTDIR AND/OR NORMAL
C              (2,I)
C           OR (1,I) : VALUES OF VECTOR
C              (2,I)
C              (3,I)
C
      DATA DIRMOT /12*0.D0/
C
C GOFEED(4)  : ARRAY FOR MOTION FEEDRAT
C              (1)   : FEDRAT OF START-MOTION (START AT FIRST POINT)
C              (2)   : FEDRAT OF AWAY-MOTION
C              (3)   : FEDRAT OF BACK-MOTION
C              (4)   : FEDRAT OF THRU-MOTION (RETRACT AT LAST POINT)
C
      DATA GOFEED /4*0.D0/
C
C GLFEED     : VARIABLE FOR NORMAL FEDRAT BEFORE GOMILL OR GOLOFT
      DATA GLFEED /0.D0/
C
C REGLDA     : ARRAY FOR CANONICAL FORM OF REGION DATA
      DATA REGLDA /2*0.D0/
C
C IRETRO(4)  : ARRAY FOR START, AWAY, BACK, THRU
C              (1) : START
C              (2) : AWAY
C              (3) : BACK
C              (4) : THRU
C                    0 : NOT USED
C                    1 : CONDITION SET
      DATA IRETRO /4*0/
C
C IDIRMO(4)  : ARRAY FOR START ON AND END CONDITION
C                    0 : NOT SET
C                    1 : MOTDIR AND/OR NORMAL
C                    2 : VECTOR
      DATA IDIRMO /4*0/
C
C ICANIN(4)  : ARRAY FOR THE CANONICAL FORM INDEX OF THE SURFACE
C                    0 : NOT SET
C                    IC: INDEX
      DATA ICANIN /4*0/
C
C IFEEDF     : FLAG (=1) FOR >GOP< TO OUTPUT GLOBAL FEEDRATE
      DATA IFEEDF /0/
C
      END
