**** SOURCE FILE : OUTSET00.ORG   ***
*
      SUBROUTINE OUTSET(J)
*
*  * OUTSET *  VAX-11 FORTRAN 77 SUBROUTINE   E.MCLELLAN
*
*  PURPOSE     TO SET UP PAPER TAPE CODE CONVERSION TABLE
*
*  CALLING SEQUENCE
*              CALL OUTSET(J)
*  ARGUMENT
*              J  INDICATES REQUIRED CODE
*                 =1  NAS943  ,ODD PARITY, COLUMN BINARY
*                 =2  ISO     ,EVEN PARITY,COLUMN BINARY
*                 =3  ASCII   ,NO PARITY,  NO CONVERSION
*
C
      INCLUDE 'DARRAY.INC'
C
      COMMON/PUNTAB/PUNCOD
C
C...BYTE VARIABLES IN THIS VAX IMPLEMENTATION MIGHT BE ABLE TO BE LOGICA
C...ON OTHER SYSTEMS
      BYTE PUNCOD(128)
c      integer*8 puncod(128)
      BYTE NAS943(128),ISO(128),ASCII(128)
c      integer*8 nas943(128),iso(128),ascii(128)
*
******  NAS943 ODD PARITY COLUMN BINARY
*
      data nas943/
*      0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
c     *Z00,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,Z3E,ZEE,ZEE,ZEE,Z80,ZEE,ZEE,
     *z'00',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'3e',z'ee'
     *,z'ee',z'ee',z'80',z'ee',z'ee',
c     1ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,
     1z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     1,z'ee',z'ee',z'ee',z'ee',z'ee',
c     2Z10,ZEE,ZEE,Z7F,Z80,Z0B,Z70,ZEE,Z0B,Z2A,Z3E,Z70,Z3B,Z40,Z6B,Z31,
     2z'10',z'ee',z'ee',z'7f',z'80',z'0b',z'70',z'ee',z'0b',z'2a',z'3e'
     2,z'70',z'3b',z'40',z'6b',z'31',
c     3Z20,Z01,Z02,Z13,Z04,Z15,Z16,Z07,Z08,Z19,Z7C,Z7A,ZEE,Z7F,ZEE,ZEE,
     3z'20',z'01',z'02',z'13',z'04',z'15',z'16',z'07',z'08',z'19',z'7c'
     3,z'7a',z'ee',z'7f',z'ee',z'ee',
c     4Z0E,Z61,Z62,Z73,Z64,Z75,Z76,Z67,Z68,Z79,Z51,Z52,Z43,Z54,Z45,Z46,
     4z'0e',z'61',z'62',z'73',z'64',z'75',z'76',z'67',z'68',z'79',z'51'
     4,z'52',z'43',z'54',z'45',z'46',
c     5Z57,Z58,Z49,Z32,Z23,Z34,Z25,Z26,Z37,Z38,Z29,ZEE,ZEE,ZEE,ZEE,ZEE,
     5z'57',z'58',z'49',z'32',z'23',z'34',z'25',z'26',z'37',z'38',z'29'
     5,z'ee',z'ee',z'ee',z'ee',z'ee',
c     6ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,
     6z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     6,z'ee',z'ee',z'ee',z'ee',z'ee',
c     7ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE/
     7z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     7,z'ee',z'ee',z'ee',z'ee',z'ee'/
*
******  ISO/
*
      DATA ISO/
*      0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
c     *Z00,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,Z09,Z0A,ZEE,ZEE,Z8D,ZEE,ZEE,
c     1ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,
c     2ZA0,ZEE,ZEE,ZA3,Z24,ZA5,ZA6,Z27,Z28,ZA9,ZAA,Z2B,ZAC,Z2D,Z2E,ZAF,
c     3Z30,ZB1,ZB2,Z33,ZB4,Z35,Z36,ZB7,ZB8,Z39,Z3A,ZEE,ZEE,ZEE,ZEE,ZEE,
c     4ZC0,Z41,Z42,ZC3,Z44,ZC5,ZC6,Z47,Z48,ZC9,ZCA,Z4B,ZCC,Z4D,Z4E,ZCF,
c     5Z50,ZD1,ZD2,Z53,ZD4,Z55,Z56,ZD7,ZD8,Z59,Z5A,ZEE,ZEE,ZEE,ZEE,ZEE,
c     6ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,
c     7ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZFF/

     *z'00',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'09',z'0a'
     *,z'ee',z'ee',z'8d',z'ee',z'ee',
     1z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     1,z'ee',z'ee',z'ee',z'ee',z'ee',
     2z'a0',z'ee',z'ee',z'a3',z'24',z'a5',z'a6',z'27',z'28',z'a9',z'aa'
     2,z'2b',z'ac',z'2d',z'2e',z'af',
     3z'30',z'b1',z'b2',z'33',z'b4',z'35',z'36',z'b7',z'b8',z'39',z'3a'
     3,z'ee',z'ee',z'ee',z'ee',z'ee',
     4z'c0',z'41',z'42',z'c3',z'44',z'c5',z'c6',z'47',z'48',z'c9',z'ca'
     4,z'4b',z'cc',z'4d',z'4e',z'cf',
     5z'50',z'd1',z'd2',z'53',z'd4',z'55',z'56',z'd7',z'd8',z'59',z'5a'
     5,z'ee',z'ee',z'ee',z'ee',z'ee',
     6z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     6,z'ee',z'ee',z'ee',z'ee',z'ee',
     7z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     7,z'ee',z'ee',z'ee',z'ee',z'ff'/
*
******  ASCII 7 BIT NO PARITY
*
      data ascii/
*      0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
c     *Z00,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,Z09,Z0A,ZEE,ZEE,Z0D,ZEE,ZEE,
c     1ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,ZEE,
c     2Z20,Z21,Z22,Z23,Z24,Z25,Z26,Z27,Z28,Z29,Z2A,Z2B,Z2C,Z2D,Z2E,Z2F,
c     3Z30,Z31,Z32,Z33,Z34,Z35,Z36,Z37,Z38,Z39,Z3A,Z3B,Z3C,Z3D,Z3E,Z3F,
c     4Z40,Z41,Z42,Z43,Z44,Z45,Z46,Z47,Z48,Z49,Z4A,Z4B,Z4C,Z4D,Z4E,Z4F,
c     5Z50,Z51,Z52,Z53,Z54,Z55,Z56,Z57,Z58,Z59,Z5A,Z5B,Z5C,Z5D,Z5E,Z5F,
c     6Z60,Z61,Z62,Z63,Z64,Z65,Z66,Z67,Z68,Z69,Z6A,Z6B,Z6C,Z6D,Z6E,Z6F,
c     7Z70,Z71,Z72,Z73,Z74,Z75,Z76,Z77,Z78,Z79,Z7A,ZEE,ZEE,ZEE,ZEE,Z7F/
     *z'00',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'09',z'0a'
     *,z'ee',z'ee',z'0d',z'ee',z'ee',
     1z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee',z'ee'
     1,z'ee',z'ee',z'ee',z'ee',z'ee',
     2z'20',z'21',z'22',z'23',z'24',z'25',z'26',z'27',z'28',z'29',z'2a'
     2,z'2b',z'2c',z'2d',z'2e',z'2f',
     3z'30',z'31',z'32',z'33',z'34',z'35',z'36',z'37',z'38',z'39',z'3a'
     3,z'3b',z'3c',z'3d',z'3e',z'3f',
     4z'40',z'41',z'42',z'43',z'44',z'45',z'46',z'47',z'48',z'49',z'4a'
     4,z'4b',z'4c',z'4d',z'4e',z'4f',
     5z'50',z'51',z'52',z'53',z'54',z'55',z'56',z'57',z'58',z'59',z'5a'
     5,z'5b',z'5c',z'5d',z'5e',z'5f',
     6z'60',z'61',z'62',z'63',z'64',z'65',z'66',z'67',z'68',z'69',z'6a'
     6,z'6b',z'6c',z'6d',z'6e',z'6f',
     7z'70',z'71',z'72',z'73',z'74',z'75',z'76',z'77',z'78',z'79',z'7a'
     7,z'ee',z'ee',z'ee',z'ee',z'7f'/
*
      IF (J.EQ.1) THEN
         DO 100 I=1,128
  100    PUNCOD(I)=NAS943(I)
*
      ELSE IF (J.EQ.2) THEN
         DO 200 I=1,128
  200    PUNCOD(I)=ISO(I)
*
      ELSE IF (J.EQ.3) THEN
         DO 300 I=1,128
  300    PUNCOD(I)=ASCII(I)
*
      ELSE
         CALL CFORM('**** INVALID ARGUMENT IN CALL TO OUTSET ****',
     1               DARRAY,2,44)
         CALL CPRINT(DARRAY)
         CALL ABNEND
      END IF
      RETURN
      END
