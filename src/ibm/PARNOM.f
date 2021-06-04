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
c      LOGICAL*1 OUT(3024),TABO(6,64),TABE(6,64),TAB56(6,64),CODE(6,64)
      integer*1 out(3024),tabo(6,64),tabe(6,64),tab56(6,64),code(6,64)
c      LOGICAL*1 TBO1(6,32),TBO2(6,32),TBE1(6,32),TBE2(6,32),
      integer*1 tbo1(6,32),tbo2(6,32),tbe1(6,32),tbe2(6,32),
     1          TB561(6,32),TB562(6,32)
C
      EQUIVALENCE (TABO(1,1),TBO1(1,1)),(TABO(1,33),TBO2(1,1)),
     1            (TABE(1,1),TBE1(1,1)),(TABE(1,33),TBE2(1,1)),
     2            (TAB56(1,1),TB561(1,1)),(TAB56(1,33),TB562(1,1))
*
      INCLUDE 'DARRAY.INC'
*
******   TABLE FOR 5X7 MATRIX OUTPUT , ODD PARITY , COLUMN BINARY
*
c      DATA TBO1/
*              BLANK                      !
c     1Z80,Z80,Z80,Z80,Z80,Z80, Z80,Z80,Z5E,Z80,Z80,Z80,
c*                "                        #
c     2Z80,Z07,Z80,Z07,Z80,Z80, Z94,Z3E,Z94,Z3E,Z94,Z80,
c*                $                        %
c     3ZAE,Z2A,Z7F,Z2A,ZAE,Z80, ZE3,Z13,Z08,Z34,ZE3,Z80,
c*                &                        `
c     4ZFB,Z45,Z6B,Z10,Z68,Z80, Z80,Z80,Z07,Z80,Z80,Z80,
c*                (                        )
c     5Z80,Z1C,ZA2,ZC1,ZC1,Z80, Z80,ZC1,ZC1,ZA2,Z1C,Z80,
c*                *                        +
c     6Z08,Z2A,Z1C,Z2A,Z08,Z80, Z08,Z08,Z3E,Z08,Z08,Z80,
c*                ,                        -
c     7Z80,Z80,ZD0,ZB0,Z80,Z80, Z08,Z08,Z08,Z08,Z08,Z80,
c*                .                        /
c     8Z80,Z80,ZE0,ZE0,Z80,Z80, Z20,Z10,Z08,Z04,Z02,Z80,
c*                0                        1
c     9Z3E,ZC1,ZC1,ZC1,Z3E,Z80, Z80,Z02,Z7F,Z80,Z80,Z80,
c*                2                        3
c     AZC2,Z61,Z51,Z49,Z46,Z80, ZA1,ZC1,Z49,ZCD,ZB3,Z80,
c*                4                        5
c     BZ98,Z94,Z92,Z7F,Z10,Z80, ZA7,Z45,Z45,Z45,ZB9,Z80,
c*                6                        7
c     CZBC,ZC2,Z49,Z49,ZB0,Z80, Z01,Z01,Z79,Z85,Z83,Z80,
c*                8                        9
c     DZB6,Z49,Z49,Z49,ZB6,Z80, Z86,Z49,Z49,ZA1,Z9E,Z80,
c*                :                        ;
c     EZ80,Z80,ZB6,ZB6,Z80,Z80, Z80,Z80,ZD6,ZB6,Z80,Z80,
c*                <                        =
c     FZ08,Z94,ZA2,ZC1,Z80,Z80, ZA2,ZA2,ZA2,ZA2,ZA2,Z80,
c*                >                        ?
c     GZ80,ZC1,ZA2,Z94,Z08,Z80, Z02,Z01,ZD9,Z85,Z02,Z80/
c      DATA TBO2/
c*                @                        A
c     1Z3E,ZC1,Z5D,ZD5,Z5E,Z80, ZFE,Z91,Z91,Z91,ZFE,Z80,
c*                B                        C
c     2Z7F,Z49,Z49,Z49,ZB6,Z80, Z3E,ZC1,ZC1,ZC1,ZA2,Z80,
c*                D                        E
c     3Z7F,ZC1,ZC1,ZC1,ZE3,Z80, Z7F,Z49,Z49,Z49,ZC1,Z80,
c*                F                        G
c     4Z7F,Z89,Z89,Z89,Z01,Z80, ZE3,ZC1,ZC1,Z49,Z79,Z80,
c*                H                        I
c     5Z7F,Z08,Z08,Z08,Z7F,Z80, Z80,ZC1,Z7F,ZC1,Z80,Z80,
c*                J                        K
c     6Z20,Z40,Z40,ZBF,Z80,Z80, Z7F,Z08,Z94,ZA2,ZC1,Z80,
c*                L                        M
c     7Z7F,Z40,Z40,Z40,Z40,Z80, Z7F,Z02,Z8C,Z02,Z7F,Z80,
c*                N                        O
c     8Z7F,Z02,Z04,Z08,Z7F,Z80, Z3E,Z51,Z49,Z45,Z3E,Z80,
c*                P                        Q
c     9Z7F,Z89,Z89,Z89,Z86,Z80, Z3E,ZC1,Z51,ZA1,Z5E,Z80,
c*                R                        S
c     AZ7F,Z89,Z19,Z29,Z46,Z80, Z46,Z49,Z49,Z49,Z31,Z80,
c*                T                        U
c     BZ01,Z01,Z7F,Z01,Z01,Z80, ZBF,Z40,Z40,Z40,ZBF,Z80,
c*                V                        W
c     CZ8F,ZB0,Z40,ZB0,Z8F,Z80, ZBF,Z40,ZBC,Z40,ZBF,Z80,
c*                X                        Y
c     DZE3,Z94,Z08,Z94,ZE3,Z80, Z07,Z08,Z70,Z08,Z07,Z80,
c*                Z                        [
c     EZ61,Z51,Z49,Z45,Z43,Z80, Z7F,Z7F,ZC1,ZC1,ZC1,Z80,
c*                \                        ]
c     FZ02,Z04,Z08,Z20,Z40,Z80, ZC1,ZC1,ZC1,Z7F,Z7F,Z80,
c*                ^                        _
c     GZ04,Z02,Z01,Z02,Z04,Z80, Z40,Z40,Z40,Z40,Z40,Z80/
c******   TABLE FOR 5X7 MATRIX OUTPUT ,EVEN PARITY , COLUMN BINARY
c*
c      DATA TBE1/
c*              BLANK                      !
c     1ZC0,ZC0,ZC0,ZC0,ZC0,ZC0, ZC0,ZC0,Z2F,ZC0,ZC0,ZC0,
c*                "                        #
c     2ZC0,Z87,ZC0,Z87,ZC0,ZC0, Z14,ZBE,Z14,ZBE,Z14,ZC0,
c*                $                        %
c     3Z2E,ZAA,ZFF,ZAA,Z3A,ZC0, Z63,Z93,Z88,ZE4,Z63,ZC0,
c*                &                        `
c     4Z7B,ZC5,ZEB,Z90,ZE9,ZC0, ZC0,ZC0,Z87,ZC0,ZC0,ZC0,
c*                (                        )
c     5ZC0,Z9C,Z22,Z41,Z41,ZC0, ZC0,Z41,Z41,Z22,Z9C,ZC0,
c*                *                        +
c     6Z88,ZAA,Z9C,ZAA,Z88,ZC0, Z88,Z88,ZBE,Z88,Z88,ZC0,
c*                ,                        -
c     7ZC0,ZC0,Z50,Z30,ZC0,ZC0, Z88,Z88,Z88,Z88,Z88,ZC0,
c*                .                        /
c     8ZC0,ZC0,Z60,Z60,ZC0,ZC0, ZA0,Z90,Z88,Z84,Z82,ZC0,
c*                0                        1
c     9ZBE,Z31,Z31,Z31,ZBE,ZC0, ZC0,Z82,ZFF,ZC0,ZC0,ZC0,
c*                2                        3
c     AZ42,ZE1,ZD1,ZC9,ZC6,ZC0, Z21,Z41,ZC9,Z4D,Z33,ZC0,
c*                4                        5
c     6Z18,Z14,Z12,ZFF,Z90,ZC0, Z27,ZCB,ZC5,ZC5,Z39,ZC0,
c*                6                        7
c     CZ3C,Z42,ZC9,ZC9,Z30,ZC0, Z81,Z81,ZF9,Z05,Z03,ZC0,
c*                8                        9
c     DZ36,ZC9,ZC9,ZC9,Z36,ZC0, Z06,ZC9,ZC9,Z21,Z1E,ZC0,
c*                :                        ;
c     EZC0,ZC0,Z1B,Z1B,ZC0,ZC0, ZC0,ZC0,Z2B,Z1B,ZC0,ZC0,
c*                <                        =
c     FZ88,Z14,Z22,Z41,ZC0,ZC0, Z22,Z22,Z22,Z22,Z22,ZC0,
c*                >                        ?
c     GZC0,Z41,Z22,Z14,Z88,ZC0, Z82,Z81,Z59,Z05,Z82,ZC0/
c      DATA TBE2/
c*                @                        A
c     1ZBE,Z41,ZDD,Z55,ZDF,ZC0, Z7E,Z11,Z11,Z11,Z7E,ZC0,
c*                B                        C
c     2ZFF,ZC9,ZC9,ZC9,Z36,ZC0, ZBE,Z41,Z41,Z41,Z22,ZC0,
c*                D                        E
c     3ZFF,Z41,Z41,Z41,ZBE,ZC0, ZFF,ZC9,ZC9,ZC9,Z41,ZC0,
c*                F                        G
c     4ZFF,Z09,Z09,Z09,Z81,ZC0, ZBE,Z41,Z41,ZC9,ZF9,ZC0,
c*                H                        I
c     5ZFF,Z88,Z88,Z88,ZFF,ZC0, ZC0,Z41,ZFF,Z41,ZC0,ZC0,
c*                J                        K
c     6ZA0,ZC0,ZC0,Z3F,ZC0,ZC0, ZFF,Z88,Z14,Z22,Z41,ZC0,
c*                L                        M
c     7ZFF,ZC0,ZC0,ZC0,ZC0,ZC0, ZFF,Z82,Z0C,Z82,ZFF,ZC0,
c*              BLANK                      O
c     8ZFF,Z82,Z84,Z88,ZFF,ZC0, ZBE,ZD1,ZC9,ZC5,ZBE,ZC0,
c*                P                        Q
c     9ZFF,Z09,Z09,Z09,Z06,ZC0, ZBE,Z41,ZD1,Z21,ZDE,ZC0,
c*                R                        S
c     AZFF,Z09,Z99,ZA9,ZC6,ZC0, ZC6,ZC9,ZC9,ZC9,ZB1,ZC0,
c*                T                        U
c     BZ81,Z81,ZFF,Z81,Z81,ZC0, Z3F,ZC0,ZC0,ZC0,Z3F,ZC0,
c*                V                        W
c     CZ0F,Z30,ZC0,Z30,Z0F,ZC0, Z3F,ZC0,Z3C,ZC0,Z3F,ZC0,
c*                X                        Y
c     DZ63,Z14,Z88,Z14,Z63,ZC0, Z87,Z88,ZF0,Z88,Z87,ZC0,
c*                Z                        [
c     EZE1,ZD1,ZC9,ZC5,ZC3,ZC0, ZFF,ZFF,Z41,Z41,Z41,ZC0,
c*                \                        ]
c     FZ82,Z84,Z88,Z90,ZA0,ZC0, Z41,Z41,Z41,ZFF,ZFF,ZC0,
c*                ^                        _
c     GZ84,Z82,Z81,Z82,Z84,ZC0, Z60,Z60,Z60,Z60,Z60,ZC0/
c******   TABLE FOR 5X6 MATRIX OUTPUT , NO PARITY , COLUMN BINARY
c*
c      DATA TB561/
c*                N                        !
c     1Z00,Z00,Z00,Z00,Z00,Z00, Z00,Z00,Z5E,Z00,Z00,Z00,
c*                "                        #
c     2Z00,Z0E,Z00,Z0E,Z00,Z00, Z14,Z3E,Z14,Z3E,Z14,Z00,
c*                $                        %
c     3Z2E,Z2A,Z7E,Z2A,Z3A,Z00, Z26,Z16,Z08,Z64,Z62,Z00,
c*                &                        `
c     4Z76,Z4A,Z56,Z20,Z50,Z00, Z00,Z00,Z0E,Z00,Z00,Z00,
c*                (                        )
c     5Z00,Z00,Z00,Z3C,Z42,Z00, Z00,Z42,Z3C,Z00,Z00,Z00,
c*                *                        +
c     6Z10,Z54,Z38,Z54,Z10,Z00, Z10,Z10,Z7C,Z10,Z10,Z00,
c*                ,                        -
c     7Z00,Z00,Z50,Z30,Z00,Z00, Z10,Z10,Z10,Z10,Z10,Z00,
c*                .                        /
c     8Z00,Z60,Z60,Z00,Z00,Z00, Z40,Z20,Z10,Z08,Z04,Z00,
c*                0                        1
c     9Z3C,Z42,Z42,Z42,Z3C,Z00, Z00,Z44,Z7E,Z40,Z00,Z00,
c*                2                        3
c     AZ64,Z52,Z4A,Z4A,Z44,Z00, Z22,Z4A,Z4A,Z4E,Z32,Z00,
c*                4                        5
c     BZ0E,Z08,Z08,Z7E,Z08,Z00, Z2E,Z4A,Z4A,Z4A,Z32,Z00,
c*                6                        7
c     CZ3C,Z4A,Z4A,Z4A,Z30,Z00, Z02,Z02,Z72,Z0A,Z06,Z00,
c*                8                        9
c     DZ34,Z4A,Z4A,Z4A,Z34,Z00, Z04,Z4A,Z4A,Z4A,Z3C,Z00,
c*                :                        ;
c     EZ00,Z00,Z36,Z36,Z00,Z00, Z00,Z00,Z56,Z36,Z00,Z00,
c*                <                        =
c     FZ10,Z28,Z44,Z00,Z00,Z00, Z28,Z28,Z28,Z28,Z28,Z00,
c*                >                        ?
c     GZ00,Z00,Z44,Z28,Z10,Z00, Z04,Z02,Z52,Z0A,Z04,Z00/
c      DATA TB562/
c*                @                        A
c     1Z3C,Z42,Z5A,Z5A,Z4C,Z00, Z78,Z14,Z12,Z14,Z78,Z00,
c*                B                        C
c     2Z7E,Z4A,Z4A,Z4A,Z34,Z00, Z3C,Z42,Z42,Z42,Z24,Z00,
c*                D                        E
c     3Z7E,Z42,Z42,Z42,Z3C,Z00, Z7E,Z4A,Z4A,Z42,Z42,Z00,
c*                F                        G
c     4Z7E,Z0A,Z0A,Z02,Z02,Z00, Z3C,Z42,Z42,Z52,Z72,Z00,
c*                H                        I
c     5Z7E,Z08,Z08,Z08,Z7E,Z00, Z00,Z42,Z74,Z42,Z00,Z00,
c*                J                        K
c     6Z20,Z40,Z40,Z40,Z3E,Z00, Z7E,Z08,Z10,Z24,Z42,Z00,
c*                L                        M
c     7Z7E,Z40,Z40,Z40,Z40,Z00, Z7E,Z04,Z08,Z04,Z7E,Z00,
c*                N                        O
c     8Z7E,Z04,Z08,Z30,Z7E,Z00, Z3C,Z42,Z42,Z42,Z3C,Z00,
c*                P                        Q
c     9Z7E,Z0A,Z0A,Z0A,Z04,Z00, Z3C,Z42,Z52,Z22,Z5C,Z00,
c*                R                        S
c     AZ7E,Z0A,Z1A,Z2A,Z44,Z00, Z44,Z4A,Z4A,Z4A,Z32,Z00,
c*                T                        U
c     BZ02,Z02,Z7E,Z02,Z02,Z00, Z3E,Z40,Z40,Z40,Z3E,Z00,
c*                V                        W
c     CZ1E,Z20,Z40,Z20,Z1E,Z00, Z7E,Z20,Z18,Z20,Z7E,Z00,
c*                X                        Y
c     DZ66,Z10,Z08,Z10,Z66,Z00, Z06,Z08,Z70,Z08,Z06,Z00,
c*                Z                        [
c     EZ62,Z52,Z4A,Z42,Z46,Z00, Z7E,Z42,Z42,Z00,Z00,Z00,
c*                \                        ]
c     FZ02,Z04,Z08,Z10,Z20,Z00, Z00,Z00,Z42,Z42,Z7E,Z00,
c*                ^                        _
c     GZ08,Z04,Z02,Z04,Z08,Z00, Z40,Z40,Z40,Z40,Z40,Z00/
C
c*******************************************************      
      data tbo1/
     1z'80',z'80',z'80',z'80',z'80',z'80', z'80',z'80',z'5e',z'80',z'80'
     1,z'80',
     2z'80',z'07',z'80',z'07',z'80',z'80', z'94',z'3e',z'94',z'3e',z'94'
     2,z'80',
     3z'ae',z'2a',z'7f',z'2a',z'ae',z'80', z'e3',z'13',z'08',z'34',z'e3'
     3,z'80',
     4z'fb',z'45',z'6b',z'10',z'68',z'80', z'80',z'80',z'07',z'80',z'80'
     4,z'80',
     5z'80',z'1c',z'a2',z'c1',z'c1',z'80', z'80',z'c1',z'c1',z'a2',z'1c'
     5,z'80',
     6z'08',z'2a',z'1c',z'2a',z'08',z'80', z'08',z'08',z'3e',z'08',z'08'
     6,z'80',
     7z'80',z'80',z'd0',z'b0',z'80',z'80', z'08',z'08',z'08',z'08',z'08'
     7,z'80',
     8z'80',z'80',z'e0',z'e0',z'80',z'80', z'20',z'10',z'08',z'04',z'02'
     8,z'80',
     9z'3e',z'c1',z'c1',z'c1',z'3e',z'80', z'80',z'02',z'7f',z'80',z'80'
     9,z'80',
     az'c2',z'61',z'51',z'49',z'46',z'80', z'a1',z'c1',z'49',z'cd',z'b3'
     a,z'80',
     bz'98',z'94',z'92',z'7f',z'10',z'80', z'a7',z'45',z'45',z'45',z'b9'
     b,z'80',
     cz'bc',z'c2',z'49',z'49',z'b0',z'80', z'01',z'01',z'79',z'85',z'83'
     c,z'80',
     dz'b6',z'49',z'49',z'49',z'b6',z'80', z'86',z'49',z'49',z'a1',z'9e'
     d,z'80',
     ez'80',z'80',z'b6',z'b6',z'80',z'80', z'80',z'80',z'd6',z'b6',z'80'
     e,z'80',
     fz'08',z'94',z'a2',z'c1',z'80',z'80', z'a2',z'a2',z'a2',z'a2',z'a2'
     f,z'80',
     gz'80',z'c1',z'a2',z'94',z'08',z'80', z'02',z'01',z'd9',z'85',z'02'
     g,z'80'/
      data tbo2/
     1z'3e',z'c1',z'5d',z'd5',z'5e',z'80', z'fe',z'91',z'91',z'91',z'fe'
     1,z'80',
     2z'7f',z'49',z'49',z'49',z'b6',z'80', z'3e',z'c1',z'c1',z'c1',z'a2'
     2,z'80',
     3z'7f',z'c1',z'c1',z'c1',z'e3',z'80', z'7f',z'49',z'49',z'49',z'c1'
     3,z'80',
     4z'7f',z'89',z'89',z'89',z'01',z'80', z'e3',z'c1',z'c1',z'49',z'79'
     4,z'80',
     5z'7f',z'08',z'08',z'08',z'7f',z'80', z'80',z'c1',z'7f',z'c1',z'80'
     5,z'80',
     6z'20',z'40',z'40',z'bf',z'80',z'80', z'7f',z'08',z'94',z'a2',z'c1'
     6,z'80',
     7z'7f',z'40',z'40',z'40',z'40',z'80', z'7f',z'02',z'8c',z'02',z'7f'
     7,z'80',
     8z'7f',z'02',z'04',z'08',z'7f',z'80', z'3e',z'51',z'49',z'45',z'3e'
     8,z'80',
     9z'7f',z'89',z'89',z'89',z'86',z'80', z'3e',z'c1',z'51',z'a1',z'5e'
     9,z'80',
     az'7f',z'89',z'19',z'29',z'46',z'80', z'46',z'49',z'49',z'49',z'31'
     a,z'80',
     bz'01',z'01',z'7f',z'01',z'01',z'80', z'bf',z'40',z'40',z'40',z'bf'
     b,z'80',
     cz'8f',z'b0',z'40',z'b0',z'8f',z'80', z'bf',z'40',z'bc',z'40',z'bf'
     c,z'80',
     dz'e3',z'94',z'08',z'94',z'e3',z'80', z'07',z'08',z'70',z'08',z'07'
     d,z'80',
     ez'61',z'51',z'49',z'45',z'43',z'80', z'7f',z'7f',z'c1',z'c1',z'c1'
     e,z'80',
     fz'02',z'04',z'08',z'20',z'40',z'80', z'c1',z'c1',z'c1',z'7f',z'7f'
     f,z'80',
     gz'04',z'02',z'01',z'02',z'04',z'80', z'40',z'40',z'40',z'40',z'40'
     g,z'80'/
******   table for 5x7 matrix output ,even parity , column binary
      data tbe1/
     1z'c0',z'c0',z'c0',z'c0',z'c0',z'c0', z'c0',z'c0',z'2f',z'c0',z'c0'
     1,z'c0',
     2z'c0',z'87',z'c0',z'87',z'c0',z'c0', z'14',z'be',z'14',z'be',z'14'
     2,z'c0',
     3z'2e',z'aa',z'ff',z'aa',z'3a',z'c0', z'63',z'93',z'88',z'e4',z'63'
     3,z'c0',
     4z'7b',z'c5',z'eb',z'90',z'e9',z'c0', z'c0',z'c0',z'87',z'c0',z'c0'
     4,z'c0',
     5z'c0',z'9c',z'22',z'41',z'41',z'c0', z'c0',z'41',z'41',z'22',z'9c'
     5,z'c0',
     6z'88',z'aa',z'9c',z'aa',z'88',z'c0', z'88',z'88',z'be',z'88',z'88'
     6,z'c0',
     7z'c0',z'c0',z'50',z'30',z'c0',z'c0', z'88',z'88',z'88',z'88',z'88'
     7,z'c0',
     8z'c0',z'c0',z'60',z'60',z'c0',z'c0', z'a0',z'90',z'88',z'84',z'82'
     8,z'c0',
     9z'be',z'31',z'31',z'31',z'be',z'c0', z'c0',z'82',z'ff',z'c0',z'c0'
     9,z'c0',
     az'42',z'e1',z'd1',z'c9',z'c6',z'c0', z'21',z'41',z'c9',z'4d',z'33'
     a,z'c0',
     6z'18',z'14',z'12',z'ff',z'90',z'c0', z'27',z'cb',z'c5',z'c5',z'39'
     6,z'c0',
     cz'3c',z'42',z'c9',z'c9',z'30',z'c0', z'81',z'81',z'f9',z'05',z'03'
     c,z'c0',
     dz'36',z'c9',z'c9',z'c9',z'36',z'c0', z'06',z'c9',z'c9',z'21',z'1e'
     d,z'c0',
     ez'c0',z'c0',z'1b',z'1b',z'c0',z'c0', z'c0',z'c0',z'2b',z'1b',z'c0'
     e,z'c0',
     fz'88',z'14',z'22',z'41',z'c0',z'c0', z'22',z'22',z'22',z'22',z'22'
     f,z'c0',
     gz'c0',z'41',z'22',z'14',z'88',z'c0', z'82',z'81',z'59',z'05',z'82'
     g,z'c0'/
      data tbe2/
     1z'be',z'41',z'dd',z'55',z'df',z'c0', z'7e',z'11',z'11',z'11',z'7e'
     1,z'c0',
     2z'ff',z'c9',z'c9',z'c9',z'36',z'c0', z'be',z'41',z'41',z'41',z'22'
     2,z'c0',
     3z'ff',z'41',z'41',z'41',z'be',z'c0', z'ff',z'c9',z'c9',z'c9',z'41'
     3,z'c0',
     4z'ff',z'09',z'09',z'09',z'81',z'c0', z'be',z'41',z'41',z'c9',z'f9'
     4,z'c0',
     5z'ff',z'88',z'88',z'88',z'ff',z'c0', z'c0',z'41',z'ff',z'41',z'c0'
     5,z'c0',
     6z'a0',z'c0',z'c0',z'3f',z'c0',z'c0', z'ff',z'88',z'14',z'22',z'41'
     6,z'c0',
     7z'ff',z'c0',z'c0',z'c0',z'c0',z'c0', z'ff',z'82',z'0c',z'82',z'ff'
     7,z'c0',
     8z'ff',z'82',z'84',z'88',z'ff',z'c0', z'be',z'd1',z'c9',z'c5',z'be'
     8,z'c0',
     9z'ff',z'09',z'09',z'09',z'06',z'c0', z'be',z'41',z'd1',z'21',z'de'
     9,z'c0',
     az'ff',z'09',z'99',z'a9',z'c6',z'c0', z'c6',z'c9',z'c9',z'c9',z'b1'
     a,z'c0',
     bz'81',z'81',z'ff',z'81',z'81',z'c0', z'3f',z'c0',z'c0',z'c0',z'3f'
     b,z'c0',
     cz'0f',z'30',z'c0',z'30',z'0f',z'c0', z'3f',z'c0',z'3c',z'c0',z'3f'
     c,z'c0',
     dz'63',z'14',z'88',z'14',z'63',z'c0', z'87',z'88',z'f0',z'88',z'87'
     d,z'c0',
     ez'e1',z'd1',z'c9',z'c5',z'c3',z'c0', z'ff',z'ff',z'41',z'41',z'41'
     e,z'c0',
     fz'82',z'84',z'88',z'90',z'a0',z'c0', z'41',z'41',z'41',z'ff',z'ff'
     f,z'c0',
     gz'84',z'82',z'81',z'82',z'84',z'c0', z'60',z'60',z'60',z'60',z'60'
     g,z'c0'/
******   table for 5x6 matrix output , no parity , column binary
*
      data tb561/
     1z'00',z'00',z'00',z'00',z'00',z'00', z'00',z'00',z'5e',z'00',z'00'
     1,z'00',
     2z'00',z'0e',z'00',z'0e',z'00',z'00', z'14',z'3e',z'14',z'3e',z'14'
     2,z'00',
     3z'2e',z'2a',z'7e',z'2a',z'3a',z'00', z'26',z'16',z'08',z'64',z'62'
     3,z'00',
     4z'76',z'4a',z'56',z'20',z'50',z'00', z'00',z'00',z'0e',z'00',z'00'
     4,z'00',
     5z'00',z'00',z'00',z'3c',z'42',z'00', z'00',z'42',z'3c',z'00',z'00'
     5,z'00',
     6z'10',z'54',z'38',z'54',z'10',z'00', z'10',z'10',z'7c',z'10',z'10'
     6,z'00',
     7z'00',z'00',z'50',z'30',z'00',z'00', z'10',z'10',z'10',z'10',z'10'
     7,z'00',
     8z'00',z'60',z'60',z'00',z'00',z'00', z'40',z'20',z'10',z'08',z'04'
     8,z'00',
     9z'3c',z'42',z'42',z'42',z'3c',z'00', z'00',z'44',z'7e',z'40',z'00'
     9,z'00',
     az'64',z'52',z'4a',z'4a',z'44',z'00', z'22',z'4a',z'4a',z'4e',z'32'
     a,z'00',
     bz'0e',z'08',z'08',z'7e',z'08',z'00', z'2e',z'4a',z'4a',z'4a',z'32'
     b,z'00',
     cz'3c',z'4a',z'4a',z'4a',z'30',z'00', z'02',z'02',z'72',z'0a',z'06'
     c,z'00',
     dz'34',z'4a',z'4a',z'4a',z'34',z'00', z'04',z'4a',z'4a',z'4a',z'3c'
     d,z'00',
     ez'00',z'00',z'36',z'36',z'00',z'00', z'00',z'00',z'56',z'36',z'00'
     e,z'00',
     fz'10',z'28',z'44',z'00',z'00',z'00', z'28',z'28',z'28',z'28',z'28'
     f,z'00',
     gz'00',z'00',z'44',z'28',z'10',z'00', z'04',z'02',z'52',z'0a',z'04'
     g,z'00'/
      data tb562/
     1z'3c',z'42',z'5a',z'5a',z'4c',z'00', z'78',z'14',z'12',z'14',z'78'
     1,z'00',
     2z'7e',z'4a',z'4a',z'4a',z'34',z'00', z'3c',z'42',z'42',z'42',z'24'
     2,z'00',
     3z'7e',z'42',z'42',z'42',z'3c',z'00', z'7e',z'4a',z'4a',z'42',z'42'
     3,z'00',
     4z'7e',z'0a',z'0a',z'02',z'02',z'00', z'3c',z'42',z'42',z'52',z'72'
     4,z'00',
     5z'7e',z'08',z'08',z'08',z'7e',z'00', z'00',z'42',z'74',z'42',z'00'
     5,z'00',
     6z'20',z'40',z'40',z'40',z'3e',z'00', z'7e',z'08',z'10',z'24',z'42'
     6,z'00',
     7z'7e',z'40',z'40',z'40',z'40',z'00', z'7e',z'04',z'08',z'04',z'7e'
     7,z'00',
     8z'7e',z'04',z'08',z'30',z'7e',z'00', z'3c',z'42',z'42',z'42',z'3c'
     8,z'00',
     9z'7e',z'0a',z'0a',z'0a',z'04',z'00', z'3c',z'42',z'52',z'22',z'5c'
     9,z'00',
     az'7e',z'0a',z'1a',z'2a',z'44',z'00', z'44',z'4a',z'4a',z'4a',z'32'
     a,z'00',
     bz'02',z'02',z'7e',z'02',z'02',z'00', z'3e',z'40',z'40',z'40',z'3e'
     b,z'00',
     cz'1e',z'20',z'40',z'20',z'1e',z'00', z'7e',z'20',z'18',z'20',z'7e'
     c,z'00',
     dz'66',z'10',z'08',z'10',z'66',z'00', z'06',z'08',z'70',z'08',z'06'
     d,z'00',
     ez'62',z'52',z'4a',z'42',z'46',z'00', z'7e',z'42',z'42',z'00',z'00'
     e,z'00',
     fz'02',z'04',z'08',z'10',z'20',z'00', z'00',z'00',z'42',z'42',z'7e'
     f,z'00',
     gz'08',z'04',z'02',z'04',z'08',z'00', z'40',z'40',z'40',z'40',z'40'
     g,z'00'/
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
