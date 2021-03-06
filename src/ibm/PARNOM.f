**** SOURCE FILE : PARNOM00.IBM;1   ***
*
      SUBROUTINE PARNOM(N,A,J)
*
*  * PARNOM *  VAX-11 FORTRAN 77 VERSION  26.10.82  E.MCLELLAN
*
*  PURPOSE     PUNCH COLUMN BINARY MATRIX REPRESENTATION OF
*              CHARACTERS USED FOR PUNCH TAPE IDENTIFICATION
*  CALLING SEQUENCE
*              CALL PARNOM(N,A,J)
*  ARGUMENTS
*              N  NUMBER OF BCD CHARACTERS TO BE CONVERTED (MAX 504)
*              A  ARRAY CONTAINING BCD CHARACTERS TO BE CONVERTED
*                 FORMAT A6,2X (6 BCD CHARACTERS FOLLOWED BY 2 BLANKS)
*                 THE BLANKS  ARE IGNORED
*              J  J=0  5*7 MATRIX, COLUMN BINARY, ODD PARITY
*                  =1  IGNORED
*                  =2  5*6 MATRIX, COLUMN BINARY, NO PARITY
*  ALTERNATE ENTRY
*              CALL PARNEM(N,A)
*                   PUNCHES A 5*7 MATRIX,COLUMN BINARY,EVEN PARITY
*
*  NOTE:       THE ALLOWABLE CHARACTERS ARE 0 THRO 9, A THRU Z,
*              AND !"#$%&'()*+,-./:;<=>?@[\]^_
*              IE THE COMPLETE ASCII CHARACTER SET LESS LOWER CASE
*
      DOUBLE PRECISION A(84)
      CHARACTER INFIL*504
*
C
C...LOGICAL*1 VARIABLES IN THIS IBM IMPLEMENTATION MIGHT BE ABLE TO BE
C...BYTE VARIABLES ON OTHER SYSTEMS E.G. VAX
      LOGICAL*1 OUT(3024),TABO(6,64),TABE(6,64),TAB56(6,64),CODE(6,64)
      LOGICAL*1 TBO1(6,32),TBO2(6,32),TBE1(6,32),TBE2(6,32),
     1          TB561(6,32),TB562(6,32)
C
      EQUIVALENCE (TABO(1,1),TBO1(1,1)),(TABO(1,33),TBO2(1,1)),
     1            (TABE(1,1),TBE1(1,1)),(TABE(1,33),TBE2(1,1)),
     2            (TAB56(1,1),TB561(1,1)),(TAB56(1,33),TB562(1,1))
*
      INCLUDE (DARRAY)
*
******   TABLE FOR 5X7 MATRIX OUTPUT , ODD PARITY , COLUMN BINARY
*
      DATA TBO1/
*              BLANK                      !
     1Z80,Z80,Z80,Z80,Z80,Z80, Z80,Z80,Z5E,Z80,Z80,Z80,
*                "                        #
     2Z80,Z07,Z80,Z07,Z80,Z80, Z94,Z3E,Z94,Z3E,Z94,Z80,
*                $                        %
     3ZAE,Z2A,Z7F,Z2A,ZAE,Z80, ZE3,Z13,Z08,Z34,ZE3,Z80,
*                &                        `
     4ZFB,Z45,Z6B,Z10,Z68,Z80, Z80,Z80,Z07,Z80,Z80,Z80,
*                (                        )
     5Z80,Z1C,ZA2,ZC1,ZC1,Z80, Z80,ZC1,ZC1,ZA2,Z1C,Z80,
*                *                        +
     6Z08,Z2A,Z1C,Z2A,Z08,Z80, Z08,Z08,Z3E,Z08,Z08,Z80,
*                ,                        -
     7Z80,Z80,ZD0,ZB0,Z80,Z80, Z08,Z08,Z08,Z08,Z08,Z80,
*                .                        /
     8Z80,Z80,ZE0,ZE0,Z80,Z80, Z20,Z10,Z08,Z04,Z02,Z80,
*                0                        1
     9Z3E,ZC1,ZC1,ZC1,Z3E,Z80, Z80,Z02,Z7F,Z80,Z80,Z80,
*                2                        3
     AZC2,Z61,Z51,Z49,Z46,Z80, ZA1,ZC1,Z49,ZCD,ZB3,Z80,
*                4                        5
     BZ98,Z94,Z92,Z7F,Z10,Z80, ZA7,Z45,Z45,Z45,ZB9,Z80,
*                6                        7
     CZBC,ZC2,Z49,Z49,ZB0,Z80, Z01,Z01,Z79,Z85,Z83,Z80,
*                8                        9
     DZB6,Z49,Z49,Z49,ZB6,Z80, Z86,Z49,Z49,ZA1,Z9E,Z80,
*                :                        ;
     EZ80,Z80,ZB6,ZB6,Z80,Z80, Z80,Z80,ZD6,ZB6,Z80,Z80,
*                <                        =
     FZ08,Z94,ZA2,ZC1,Z80,Z80, ZA2,ZA2,ZA2,ZA2,ZA2,Z80,
*                >                        ?
     GZ80,ZC1,ZA2,Z94,Z08,Z80, Z02,Z01,ZD9,Z85,Z02,Z80/
      DATA TBO2/
*                @                        A
     1Z3E,ZC1,Z5D,ZD5,Z5E,Z80, ZFE,Z91,Z91,Z91,ZFE,Z80,
*                B                        C
     2Z7F,Z49,Z49,Z49,ZB6,Z80, Z3E,ZC1,ZC1,ZC1,ZA2,Z80,
*                D                        E
     3Z7F,ZC1,ZC1,ZC1,ZE3,Z80, Z7F,Z49,Z49,Z49,ZC1,Z80,
*                F                        G
     4Z7F,Z89,Z89,Z89,Z01,Z80, ZE3,ZC1,ZC1,Z49,Z79,Z80,
*                H                        I
     5Z7F,Z08,Z08,Z08,Z7F,Z80, Z80,ZC1,Z7F,ZC1,Z80,Z80,
*                J                        K
     6Z20,Z40,Z40,ZBF,Z80,Z80, Z7F,Z08,Z94,ZA2,ZC1,Z80,
*                L                        M
     7Z7F,Z40,Z40,Z40,Z40,Z80, Z7F,Z02,Z8C,Z02,Z7F,Z80,
*                N                        O
     8Z7F,Z02,Z04,Z08,Z7F,Z80, Z3E,Z51,Z49,Z45,Z3E,Z80,
*                P                        Q
     9Z7F,Z89,Z89,Z89,Z86,Z80, Z3E,ZC1,Z51,ZA1,Z5E,Z80,
*                R                        S
     AZ7F,Z89,Z19,Z29,Z46,Z80, Z46,Z49,Z49,Z49,Z31,Z80,
*                T                        U
     BZ01,Z01,Z7F,Z01,Z01,Z80, ZBF,Z40,Z40,Z40,ZBF,Z80,
*                V                        W
     CZ8F,ZB0,Z40,ZB0,Z8F,Z80, ZBF,Z40,ZBC,Z40,ZBF,Z80,
*                X                        Y
     DZE3,Z94,Z08,Z94,ZE3,Z80, Z07,Z08,Z70,Z08,Z07,Z80,
*                Z                        [
     EZ61,Z51,Z49,Z45,Z43,Z80, Z7F,Z7F,ZC1,ZC1,ZC1,Z80,
*                \                        ]
     FZ02,Z04,Z08,Z20,Z40,Z80, ZC1,ZC1,ZC1,Z7F,Z7F,Z80,
*                ^                        _
     GZ04,Z02,Z01,Z02,Z04,Z80, Z40,Z40,Z40,Z40,Z40,Z80/
******   TABLE FOR 5X7 MATRIX OUTPUT ,EVEN PARITY , COLUMN BINARY
*
      DATA TBE1/
*              BLANK                      !
     1ZC0,ZC0,ZC0,ZC0,ZC0,ZC0, ZC0,ZC0,Z2F,ZC0,ZC0,ZC0,
*                "                        #
     2ZC0,Z87,ZC0,Z87,ZC0,ZC0, Z14,ZBE,Z14,ZBE,Z14,ZC0,
*                $                        %
     3Z2E,ZAA,ZFF,ZAA,Z3A,ZC0, Z63,Z93,Z88,ZE4,Z63,ZC0,
*                &                        `
     4Z7B,ZC5,ZEB,Z90,ZE9,ZC0, ZC0,ZC0,Z87,ZC0,ZC0,ZC0,
*                (                        )
     5ZC0,Z9C,Z22,Z41,Z41,ZC0, ZC0,Z41,Z41,Z22,Z9C,ZC0,
*                *                        +
     6Z88,ZAA,Z9C,ZAA,Z88,ZC0, Z88,Z88,ZBE,Z88,Z88,ZC0,
*                ,                        -
     7ZC0,ZC0,Z50,Z30,ZC0,ZC0, Z88,Z88,Z88,Z88,Z88,ZC0,
*                .                        /
     8ZC0,ZC0,Z60,Z60,ZC0,ZC0, ZA0,Z90,Z88,Z84,Z82,ZC0,
*                0                        1
     9ZBE,Z31,Z31,Z31,ZBE,ZC0, ZC0,Z82,ZFF,ZC0,ZC0,ZC0,
*                2                        3
     AZ42,ZE1,ZD1,ZC9,ZC6,ZC0, Z21,Z41,ZC9,Z4D,Z33,ZC0,
*                4                        5
     6Z18,Z14,Z12,ZFF,Z90,ZC0, Z27,ZCB,ZC5,ZC5,Z39,ZC0,
*                6                        7
     CZ3C,Z42,ZC9,ZC9,Z30,ZC0, Z81,Z81,ZF9,Z05,Z03,ZC0,
*                8                        9
     DZ36,ZC9,ZC9,ZC9,Z36,ZC0, Z06,ZC9,ZC9,Z21,Z1E,ZC0,
*                :                        ;
     EZC0,ZC0,Z1B,Z1B,ZC0,ZC0, ZC0,ZC0,Z2B,Z1B,ZC0,ZC0,
*                <                        =
     FZ88,Z14,Z22,Z41,ZC0,ZC0, Z22,Z22,Z22,Z22,Z22,ZC0,
*                >                        ?
     GZC0,Z41,Z22,Z14,Z88,ZC0, Z82,Z81,Z59,Z05,Z82,ZC0/
      DATA TBE2/
*                @                        A
     1ZBE,Z41,ZDD,Z55,ZDF,ZC0, Z7E,Z11,Z11,Z11,Z7E,ZC0,
*                B                        C
     2ZFF,ZC9,ZC9,ZC9,Z36,ZC0, ZBE,Z41,Z41,Z41,Z22,ZC0,
*                D                        E
     3ZFF,Z41,Z41,Z41,ZBE,ZC0, ZFF,ZC9,ZC9,ZC9,Z41,ZC0,
*                F                        G
     4ZFF,Z09,Z09,Z09,Z81,ZC0, ZBE,Z41,Z41,ZC9,ZF9,ZC0,
*                H                        I
     5ZFF,Z88,Z88,Z88,ZFF,ZC0, ZC0,Z41,ZFF,Z41,ZC0,ZC0,
*                J                        K
     6ZA0,ZC0,ZC0,Z3F,ZC0,ZC0, ZFF,Z88,Z14,Z22,Z41,ZC0,
*                L                        M
     7ZFF,ZC0,ZC0,ZC0,ZC0,ZC0, ZFF,Z82,Z0C,Z82,ZFF,ZC0,
*              BLANK                      O
     8ZFF,Z82,Z84,Z88,ZFF,ZC0, ZBE,ZD1,ZC9,ZC5,ZBE,ZC0,
*                P                        Q
     9ZFF,Z09,Z09,Z09,Z06,ZC0, ZBE,Z41,ZD1,Z21,ZDE,ZC0,
*                R                        S
     AZFF,Z09,Z99,ZA9,ZC6,ZC0, ZC6,ZC9,ZC9,ZC9,ZB1,ZC0,
*                T                        U
     BZ81,Z81,ZFF,Z81,Z81,ZC0, Z3F,ZC0,ZC0,ZC0,Z3F,ZC0,
*                V                        W
     CZ0F,Z30,ZC0,Z30,Z0F,ZC0, Z3F,ZC0,Z3C,ZC0,Z3F,ZC0,
*                X                        Y
     DZ63,Z14,Z88,Z14,Z63,ZC0, Z87,Z88,ZF0,Z88,Z87,ZC0,
*                Z                        [
     EZE1,ZD1,ZC9,ZC5,ZC3,ZC0, ZFF,ZFF,Z41,Z41,Z41,ZC0,
*                \                        ]
     FZ82,Z84,Z88,Z90,ZA0,ZC0, Z41,Z41,Z41,ZFF,ZFF,ZC0,
*                ^                        _
     GZ84,Z82,Z81,Z82,Z84,ZC0, Z60,Z60,Z60,Z60,Z60,ZC0/
******   TABLE FOR 5X6 MATRIX OUTPUT , NO PARITY , COLUMN BINARY
*
      DATA TB561/
*                N                        !
     1Z00,Z00,Z00,Z00,Z00,Z00, Z00,Z00,Z5E,Z00,Z00,Z00,
*                "                        #
     2Z00,Z0E,Z00,Z0E,Z00,Z00, Z14,Z3E,Z14,Z3E,Z14,Z00,
*                $                        %
     3Z2E,Z2A,Z7E,Z2A,Z3A,Z00, Z26,Z16,Z08,Z64,Z62,Z00,
*                &                        `
     4Z76,Z4A,Z56,Z20,Z50,Z00, Z00,Z00,Z0E,Z00,Z00,Z00,
*                (                        )
     5Z00,Z00,Z00,Z3C,Z42,Z00, Z00,Z42,Z3C,Z00,Z00,Z00,
*                *                        +
     6Z10,Z54,Z38,Z54,Z10,Z00, Z10,Z10,Z7C,Z10,Z10,Z00,
*                ,                        -
     7Z00,Z00,Z50,Z30,Z00,Z00, Z10,Z10,Z10,Z10,Z10,Z00,
*                .                        /
     8Z00,Z60,Z60,Z00,Z00,Z00, Z40,Z20,Z10,Z08,Z04,Z00,
*                0                        1
     9Z3C,Z42,Z42,Z42,Z3C,Z00, Z00,Z44,Z7E,Z40,Z00,Z00,
*                2                        3
     AZ64,Z52,Z4A,Z4A,Z44,Z00, Z22,Z4A,Z4A,Z4E,Z32,Z00,
*                4                        5
     BZ0E,Z08,Z08,Z7E,Z08,Z00, Z2E,Z4A,Z4A,Z4A,Z32,Z00,
*                6                        7
     CZ3C,Z4A,Z4A,Z4A,Z30,Z00, Z02,Z02,Z72,Z0A,Z06,Z00,
*                8                        9
     DZ34,Z4A,Z4A,Z4A,Z34,Z00, Z04,Z4A,Z4A,Z4A,Z3C,Z00,
*                :                        ;
     EZ00,Z00,Z36,Z36,Z00,Z00, Z00,Z00,Z56,Z36,Z00,Z00,
*                <                        =
     FZ10,Z28,Z44,Z00,Z00,Z00, Z28,Z28,Z28,Z28,Z28,Z00,
*                >                        ?
     GZ00,Z00,Z44,Z28,Z10,Z00, Z04,Z02,Z52,Z0A,Z04,Z00/
      DATA TB562/
*                @                        A
     1Z3C,Z42,Z5A,Z5A,Z4C,Z00, Z78,Z14,Z12,Z14,Z78,Z00,
*                B                        C
     2Z7E,Z4A,Z4A,Z4A,Z34,Z00, Z3C,Z42,Z42,Z42,Z24,Z00,
*                D                        E
     3Z7E,Z42,Z42,Z42,Z3C,Z00, Z7E,Z4A,Z4A,Z42,Z42,Z00,
*                F                        G
     4Z7E,Z0A,Z0A,Z02,Z02,Z00, Z3C,Z42,Z42,Z52,Z72,Z00,
*                H                        I
     5Z7E,Z08,Z08,Z08,Z7E,Z00, Z00,Z42,Z74,Z42,Z00,Z00,
*                J                        K
     6Z20,Z40,Z40,Z40,Z3E,Z00, Z7E,Z08,Z10,Z24,Z42,Z00,
*                L                        M
     7Z7E,Z40,Z40,Z40,Z40,Z00, Z7E,Z04,Z08,Z04,Z7E,Z00,
*                N                        O
     8Z7E,Z04,Z08,Z30,Z7E,Z00, Z3C,Z42,Z42,Z42,Z3C,Z00,
*                P                        Q
     9Z7E,Z0A,Z0A,Z0A,Z04,Z00, Z3C,Z42,Z52,Z22,Z5C,Z00,
*                R                        S
     AZ7E,Z0A,Z1A,Z2A,Z44,Z00, Z44,Z4A,Z4A,Z4A,Z32,Z00,
*                T                        U
     BZ02,Z02,Z7E,Z02,Z02,Z00, Z3E,Z40,Z40,Z40,Z3E,Z00,
*                V                        W
     CZ1E,Z20,Z40,Z20,Z1E,Z00, Z7E,Z20,Z18,Z20,Z7E,Z00,
*                X                        Y
     DZ66,Z10,Z08,Z10,Z66,Z00, Z06,Z08,Z70,Z08,Z06,Z00,
*                Z                        [
     EZ62,Z52,Z4A,Z42,Z46,Z00, Z7E,Z42,Z42,Z00,Z00,Z00,
*                \                        ]
     FZ02,Z04,Z08,Z10,Z20,Z00, Z00,Z00,Z42,Z42,Z7E,Z00,
*                ^                        _
     GZ08,Z04,Z02,Z04,Z08,Z00, Z40,Z40,Z40,Z40,Z40,Z00/
C
      IF (J.EQ.0) THEN
C
C.....5*7 MATRIX, ODD PARITY, COLUMN BINARY
C
      DO 10 I=1,6
      DO 10 K=1,64
   10 CODE(I,K)=TABO(I,K)
C
      ELSE IF (J.EQ.2) THEN
C
C.....5*6 MATRIX, NO PARITY, COLUMN BINARY
C
      DO 20 I=1,6
      DO 20 K=1,64
   20 CODE(I,K)=TAB56(I,K)
C
      ELSE
         CALL CFORM('**** INVALID CALL TO PARNOM ****',DARRAY,2,32)
         CALL CPRINT(DARRAY)
         RETURN
      END IF
      GO TO 100
C
C.....ENTRY PARNEM
C
      ENTRY PARNEM(N,A)
C
C.....5*7 MATRIX, EVEN PARITY, COLUMN BINARY
C
      DO 30 I=1,6
      DO 30 K=1,64
   30 CODE(I,K)=TABE(I,K)
C
C.....CHECK N.LE.504
C
  100 N=ABS(N)
      IF (N.GT.504) THEN
         CALL CFORM('**** MORE THAN 504 CHARACTERS',DARRAY,2,29)
         CALL CFORM('REQUESTED IN CALL TO PARNOM OR PARNEM ****',DARRAY,
     1                32,42)
         CALL CPRINT(DARRAY)
         N=504
      END IF
C
C.....CALCULATE NUMBER OF WORDS CONTAINING CHARACTERS (6 PER WORD)
C
      NUM=N/6
      IF (NUM*6.LT.N) NUM=NUM+1
C
C.....WRITE CHARCTERS FOR CONVERSION TO INTERNAL FILE
C
      WRITE (INFIL,'(84A6)') (A(I),I=1,NUM)
C
C.....FOR EACH CHARACTER INPUT, IDENTIFY POSITION IN ASCII CHAR SET
C
      JC=0
      DO 200 I=1,N
      IC=ICHAR(INFIL(I:I))-31
C
C.....STORE APPROP MATRIX IN OUTPUT ARRAY
C
      DO 200 K=1,6
      JC=JC+1
      OUT(JC)=CODE(K,IC)
  200 CONTINUE
C
C.....OUTPUT TO PUNCH FILE, JC IS NO OF BYTES
C
      CALL TAPEPN(OUT,JC)
      RETURN
      END
