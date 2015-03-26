      BLOCK DATA BDBCDP
C     BLOCK DATA PROGRAM FOR BCDPTR
      IMPLICIT INTEGER (A-Z)
      COMMON/BCDPTR/BCDPTR
      DIMENSION BCDPTR(   7)
      EQUIVALENCE(DOTAC ,BCDPTR(1)),(FEDRAT,BCDPTR(2))
      EQUIVALENCE(TO    ,BCDPTR(3)),(DS    ,BCDPTR(4))
      EQUIVALENCE(ERASB ,BCDPTR(5)),(ITDOT1,BCDPTR(6))
      EQUIVALENCE(DOTTAB,BCDPTR(7))
C   NAMTBL POINTER FOR .AC.  
      DATA BCDPTR(1)/ 166/
C   NAMTBL POINTER FOR FEDRAT
      DATA BCDPTR(2)/ 724/
C   NAMTBL POINTER FOR TO    
      DATA BCDPTR(3)/1092/
C   NAMTBL POINTER FOR DS    
      DATA BCDPTR(4)/1410/
C   NAMTBL POINTER FOR APTER 
      DATA BCDPTR(5)/ 167/
C   NAMTBL POINTER FOR $21T$1
      DATA BCDPTR(6)/ 168/
C   NAMTBL POINTER FOR $$TAB 
      DATA BCDPTR(7)/ 169/
       END
      BLOCK DATA BDNUMP
C     BLOCK DATA PROGRAM FOR NUMPTR
      IMPLICIT INTEGER (A-Z)
      COMMON/NUMPTR/NUMPTR
      DIMENSION NUMPTR(  13)
      EQUIVALENCE(ZERO  ,NUMPTR( 1)),(ZEROPT,NUMPTR( 2))
      EQUIVALENCE(ONE   ,NUMPTR( 3)),(ONEPT ,NUMPTR( 4))
      EQUIVALENCE(TWO   ,NUMPTR( 5)),(THREE ,NUMPTR( 6))
      EQUIVALENCE(FOUR  ,NUMPTR( 7)),(FIVE  ,NUMPTR( 8))
      EQUIVALENCE(SIX   ,NUMPTR( 9)),(SEVEN ,NUMPTR(10))
      EQUIVALENCE(EIGHT ,NUMPTR(11)),(NINE  ,NUMPTR(12))
      EQUIVALENCE(TENPT ,NUMPTR(13))                    
C
C   NAMTBL POINTER FOR 0  
      DATA NUMPTR( 1)/3001/
C   NAMTBL POINTER FOR 0. 
      DATA NUMPTR( 2)/3011/
C   NAMTBL POINTER FOR 1  
      DATA NUMPTR( 3)/3002/
C   NAMTBL POINTER FOR 1. 
      DATA NUMPTR( 4)/3012/
C   NAMTBL POINTER FOR 2  
      DATA NUMPTR( 5)/3003/
C   NAMTBL POINTER FOR 3  
      DATA NUMPTR( 6)/3004/
C   NAMTBL POINTER FOR 4  
      DATA NUMPTR( 7)/3005/
C   NAMTBL POINTER FOR 5  
      DATA NUMPTR( 8)/3006/
C   NAMTBL POINTER FOR 6  
      DATA NUMPTR( 9)/3007/
C   NAMTBL POINTER FOR 7  
      DATA NUMPTR(10)/3008/
C   NAMTBL POINTER FOR 8  
      DATA NUMPTR(11)/3009/
C   NAMTBL POINTER FOR 9  
      DATA NUMPTR(12)/3010/
C   NAMTBL POINTER FOR 10.
      DATA NUMPTR(13)/3013/
       END
      BLOCK DATA BDSUBL
C     BLOCK DATA PROGRAM FOR SUBLST
      IMPLICIT INTEGER (A-Z)
      COMMON/SUBLST/SUBLST
      DIMENSION SUBLST( 136),APTXXX( 120),APTYYY(   5),ISUB(  10)
C
      EQUIVALENCE(SUBLST(  1),APTXXX(1))
      EQUIVALENCE(SUBLST(121),APTYYY(1))
      EQUIVALENCE(SUBLST(126),ISUB(1))
      EQUIVALENCE (APT085,ISUB( 1))
      EQUIVALENCE (APT200,ISUB( 2))
      EQUIVALENCE (APT201,ISUB( 3))
      EQUIVALENCE (APT298,ISUB( 5))
      EQUIVALENCE (APT299,ISUB( 6))
      EQUIVALENCE (ERROR ,ISUB( 7))
      EQUIVALENCE (PSIS  ,ISUB( 8))
      EQUIVALENCE (REFSYS,ISUB( 9))
      EQUIVALENCE (TLAXIS,ISUB(10))
C   NAMTBL POINTER FOR APT003
      DATA APTXXX(  1)/  59/
C   NAMTBL POINTER FOR APT006
      DATA APTXXX(  2)/  62/
C   NAMTBL POINTER FOR APT007
      DATA APTXXX(  3)/  63/
C   NAMTBL POINTER FOR APT009
      DATA APTXXX(  4)/  65/
C   NAMTBL POINTER FOR APT012
      DATA APTXXX(  5)/  68/
C   NAMTBL POINTER FOR APT011
      DATA APTXXX(  6)/  67/
C   NAMTBL POINTER FOR APT014
      DATA APTXXX(  7)/  69/
C   NAMTBL POINTER FOR APT018
      DATA APTXXX(  8)/  73/
C   NAMTBL POINTER FOR APT019
      DATA APTXXX(  9)/  74/
C   NAMTBL POINTER FOR APT021
      DATA APTXXX( 10)/  76/
C   NAMTBL POINTER FOR APT022
      DATA APTXXX( 11)/  77/
C   NAMTBL POINTER FOR APT049
      DATA APTXXX( 12)/ 100/
C   NAMTBL POINTER FOR APT025
      DATA APTXXX( 13)/  80/
C   NAMTBL POINTER FOR APT026
      DATA APTXXX( 14)/  81/
C   NAMTBL POINTER FOR APT027
      DATA APTXXX( 15)/  82/
C   NAMTBL POINTER FOR APT035
      DATA APTXXX( 16)/  89/
C   NAMTBL POINTER FOR APT023
      DATA APTXXX( 17)/  78/
C   NAMTBL POINTER FOR APT024
      DATA APTXXX( 18)/  79/
C   NAMTBL POINTER FOR APT037
      DATA APTXXX( 19)/  91/
C   NAMTBL POINTER FOR APT038
      DATA APTXXX( 20)/  92/
C   NAMTBL POINTER FOR APT035
      DATA APTXXX( 21)/  89/
C   NAMTBL POINTER FOR APT039
      DATA APTXXX( 22)/  93/
C   NAMTBL POINTER FOR APT040
      DATA APTXXX( 23)/  94/
C   NAMTBL POINTER FOR APT044
      DATA APTXXX( 24)/  95/
C   NAMTBL POINTER FOR APT045
      DATA APTXXX( 25)/  96/
C   NAMTBL POINTER FOR APT046
      DATA APTXXX( 26)/  97/
C   NAMTBL POINTER FOR APT105
      DATA APTXXX( 27)/ 154/
C   NAMTBL POINTER FOR APT048
      DATA APTXXX( 28)/  99/
C   NAMTBL POINTER FOR APT050
      DATA APTXXX( 29)/ 101/
C   NAMTBL POINTER FOR APT051
      DATA APTXXX( 30)/ 102/
C   NAMTBL POINTER FOR APT052
      DATA APTXXX( 31)/ 103/
C   NAMTBL POINTER FOR APT053
      DATA APTXXX( 32)/ 104/
C   NAMTBL POINTER FOR APT054
      DATA APTXXX( 33)/ 105/
C   NAMTBL POINTER FOR APT055
      DATA APTXXX( 34)/ 106/
C   NAMTBL POINTER FOR APT056
      DATA APTXXX( 35)/ 107/
C   NAMTBL POINTER FOR APT057
      DATA APTXXX( 36)/ 108/
C   NAMTBL POINTER FOR APT058
      DATA APTXXX( 37)/ 109/
C   NAMTBL POINTER FOR APT060
      DATA APTXXX( 38)/ 110/
C   NAMTBL POINTER FOR APT062
      DATA APTXXX( 39)/ 112/
C   NAMTBL POINTER FOR APT063
      DATA APTXXX( 40)/ 113/
C   NAMTBL POINTER FOR APT066
      DATA APTXXX( 41)/ 116/
C   NAMTBL POINTER FOR APT067
      DATA APTXXX( 42)/ 117/
C   NAMTBL POINTER FOR APT068
      DATA APTXXX( 43)/ 118/
C   NAMTBL POINTER FOR ZSURF 
      DATA APTXXX( 44)/2541/
C   NAMTBL POINTER FOR APT106
      DATA APTXXX( 45)/ 155/
C   NAMTBL POINTER FOR APT005
      DATA APTXXX( 46)/  61/
C   NAMTBL POINTER FOR APT008
      DATA APTXXX( 47)/  64/
C   NAMTBL POINTER FOR APT010
      DATA APTXXX( 48)/  66/
C   NAMTBL POINTER FOR APT001
      DATA APTXXX( 49)/  58/
C   NAMTBL POINTER FOR APT015
      DATA APTXXX( 50)/  70/
C   NAMTBL POINTER FOR APT016
      DATA APTXXX( 51)/  71/
C   NAMTBL POINTER FOR APT017
      DATA APTXXX( 52)/  72/
C   NAMTBL POINTER FOR APT020
      DATA APTXXX( 53)/  75/
C   NAMTBL POINTER FOR APT028
      DATA APTXXX( 54)/  83/
C   NAMTBL POINTER FOR APT029
      DATA APTXXX( 55)/  84/
C   NAMTBL POINTER FOR APT030
      DATA APTXXX( 56)/  85/
C   NAMTBL POINTER FOR APT031
      DATA APTXXX( 57)/  86/
C   NAMTBL POINTER FOR APT032
      DATA APTXXX( 58)/  87/
C   NAMTBL POINTER FOR APT033
      DATA APTXXX( 59)/  88/
C   NAMTBL POINTER FOR APT036
      DATA APTXXX( 60)/  90/
C   NAMTBL POINTER FOR APT010
      DATA APTXXX( 61)/  66/
C   NAMTBL POINTER FOR APT047
      DATA APTXXX( 62)/  98/
C   NAMTBL POINTER FOR APT064
      DATA APTXXX( 63)/ 114/
C   NAMTBL POINTER FOR APT065
      DATA APTXXX( 64)/ 115/
C   NAMTBL POINTER FOR APT004
      DATA APTXXX( 65)/  60/
C   NAMTBL POINTER FOR APT036
      DATA APTXXX( 66)/  90/
C   NAMTBL POINTER FOR APT088
      DATA APTXXX( 67)/ 128/
C   NAMTBL POINTER FOR APT094
      DATA APTXXX( 68)/ 132/
C   NAMTBL POINTER FOR APT061
      DATA APTXXX( 69)/ 111/
C   NAMTBL POINTER FOR APT012
      DATA APTXXX( 70)/  68/
C   NAMTBL POINTER FOR APT061
      DATA APTXXX( 71)/ 111/
C   NAMTBL POINTER FOR APT087
      DATA APTXXX( 72)/ 127/
C   NAMTBL POINTER FOR APT100
      DATA APTXXX( 73)/ 133/
C   NAMTBL POINTER FOR UNDEF 
      DATA APTXXX( 74)/  57/
C   NAMTBL POINTER FOR APT041
      DATA APTXXX( 75)/ 138/
C   NAMTBL POINTER FOR APT043
      DATA APTXXX( 76)/ 139/
C   NAMTBL POINTER FOR APT042
      DATA APTXXX( 77)/ 141/
C   NAMTBL POINTER FOR APT069
      DATA APTXXX( 78)/ 142/
C   NAMTBL POINTER FOR APT070
      DATA APTXXX( 79)/ 143/
C   NAMTBL POINTER FOR APT071
      DATA APTXXX( 80)/ 144/
C   NAMTBL POINTER FOR APT072
      DATA APTXXX( 81)/ 145/
C   NAMTBL POINTER FOR DEFEXT
      DATA APTXXX( 82)/ 148/
C   NAMTBL POINTER FOR APT074
      DATA APTXXX( 83)/ 146/
C   NAMTBL POINTER FOR APT034
      DATA APTXXX( 84)/ 147/
C   NAMTBL POINTER FOR APT104
      DATA APTXXX( 85)/ 157/
C   NAMTBL POINTER FOR APT102
      DATA APTXXX( 86)/ 158/
C   NAMTBL POINTER FOR APT103
      DATA APTXXX( 87)/ 159/
C   NAMTBL POINTER FOR APT107
      DATA APTXXX( 88)/ 160/
C   NAMTBL POINTER FOR APT013
      DATA APTXXX( 89)/ 161/
C   NAMTBL POINTER FOR APT108
      DATA APTXXX( 90)/ 162/
C   NAMTBL POINTER FOR APT109
      DATA APTXXX( 91)/ 163/
C   NAMTBL POINTER FOR APT110
      DATA APTXXX( 92)/ 164/
C   NAMTBL POINTER FOR APT101
      DATA APTXXX( 95)/ 149/
C   NAMTBL POINTER FOR NDTEST
      DATA APTXXX( 96)/ 150/
C   NAMTBL POINTER FOR COMP3D
      DATA APTXXX( 97)/ 151/
C   NAMTBL POINTER FOR TLON  
      DATA APTXXX( 98)/ 152/
C   NAMTBL POINTER FOR GOTOPN
      DATA APTXXX( 99)/ 153/
C   NAMTBL POINTER FOR APT090
      DATA APTXXX(100)/ 129/
C   NAMTBL POINTER FOR APT105
      DATA APTXXX(101)/ 154/
C   NAMTBL POINTER FOR APT106
      DATA APTXXX(102)/ 155/
C   NAMTBL POINTER FOR TRANSF
      DATA APTXXX(103)/ 156/
C   NAMTBL POINTER FOR LOGIF 
      DATA APTXXX(104)/ 165/
C   NAMTBL POINTER FOR APT081
      DATA APTYYY(1)/ 124/
C   NAMTBL POINTER FOR APT083
      DATA APTYYY(2)/ 125/
C   NAMTBL POINTER FOR APT078
      DATA APTYYY(3)/ 122/
C   NAMTBL POINTER FOR APT077
      DATA APTYYY(4)/ 121/
C   NAMTBL POINTER FOR APT079
      DATA APTYYY(5)/ 123/
C   NAMTBL POINTER FOR APT085
      DATA ISUB( 1)/ 126/
C   NAMTBL POINTER FOR APT200
      DATA ISUB( 2)/ 134/
C   NAMTBL POINTER FOR APT201
      DATA ISUB( 3)/ 135/
C   NAMTBL POINTER FOR APT295
      DATA ISUB( 4)/ 140/
C   NAMTBL POINTER FOR APT298
      DATA ISUB( 5)/ 136/
C   NAMTBL POINTER FOR APT299
      DATA ISUB( 6)/ 137/
C   NAMTBL POINTER FOR ERROR 
      DATA ISUB( 7)/ 637/
C   NAMTBL POINTER FOR PSIS  
      DATA ISUB( 8)/1029/
C   NAMTBL POINTER FOR REFSYS
      DATA ISUB( 9)/1629/
C   NAMTBL POINTER FOR TLAXIS
      DATA ISUB(10)/2598/
       END
      BLOCK DATA BDNAME
C     BLOCK DATA PROGRAM FOR NAMETB
      IMPLICIT INTEGER (A-Z)
      COMMON /NAMETB/ CHARST,CHARND,INAMST,INAMND,NAMEST,NAMMAX,IFIXST,
     / IFIXND,NUMBST,NUMBND,NAMTBL
      COMMON/CNAMTB/CNAMTB,CNUMTB
      DIMENSION NAMTBL(3000)
      CHARACTER*6 CNAMTB(3000)
      CHARACTER*12 CNUMTB(3000)
      DATA CHARST,CHARND,INAMST,INAMND,NAMEST,NAMMAX/
     1          1,    56,    57,   169,   170,  3000/,
     2     IFIXST,IFIXND,NUMBST,NUMBND/
     3          1,    13,    14,  3000/
      DATA NAMTBL/ 3000*0/
      DATA CNAMTB/ 3000*' '/
      DATA CNUMTB/ 3000*' '/
C          NAMTBL ENTRY FOR 0     
      DATA NAMTBL(   2),   CNAMTB(   2)
     *        /10000   ,     '0     '/
C          NAMTBL ENTRY FOR 1     
      DATA NAMTBL(   3),   CNAMTB(   3)
     *        /10000   ,     '1     '/
C          NAMTBL ENTRY FOR 2     
      DATA NAMTBL(   4),   CNAMTB(   4)
     *        /10000   ,     '2     '/
C          NAMTBL ENTRY FOR 3     
      DATA NAMTBL(   5),   CNAMTB(   5)
     *        /10000   ,     '3     '/
C          NAMTBL ENTRY FOR 4     
      DATA NAMTBL(   6),   CNAMTB(   6)
     *        /10000   ,     '4     '/
C          NAMTBL ENTRY FOR 5     
      DATA NAMTBL(   7),   CNAMTB(   7)
     *        /10000   ,     '5     '/
C          NAMTBL ENTRY FOR 6     
      DATA NAMTBL(   8),   CNAMTB(   8)
     *        /10000   ,     '6     '/
C          NAMTBL ENTRY FOR 7     
      DATA NAMTBL(   9),   CNAMTB(   9)
     *        /10000   ,     '7     '/
C          NAMTBL ENTRY FOR 8     
      DATA NAMTBL(  10),   CNAMTB(  10)
     *        /10000   ,     '8     '/
C          NAMTBL ENTRY FOR 9     
      DATA NAMTBL(  11),   CNAMTB(  11)
     *        /10000   ,     '9     '/
C          NAMTBL ENTRY FOR =     
      DATA NAMTBL(  12),   CNAMTB(  12)
     *        / 8000   ,     '=     '/
C          NAMTBL ENTRY FOR '     
      DATA NAMTBL(  13),   CNAMTB(  13)
     *        /12000   ,     '''    '/
C          NAMTBL ENTRY FOR +     
      DATA NAMTBL(  14),   CNAMTB(  14)
     *        / 7000   ,     '+     '/
C          NAMTBL ENTRY FOR A     
      DATA NAMTBL(  15),   CNAMTB(  15)
     *        /11000   ,     'A     '/
C          NAMTBL ENTRY FOR B     
      DATA NAMTBL(  16),   CNAMTB(  16)
     *        /11000   ,     'B     '/
C          NAMTBL ENTRY FOR C     
      DATA NAMTBL(  17),   CNAMTB(  17)
     *        /11000   ,     'C     '/
C          NAMTBL ENTRY FOR D     
      DATA NAMTBL(  18),   CNAMTB(  18)
     *        /11000   ,     'D     '/
C          NAMTBL ENTRY FOR E     
      DATA NAMTBL(  19),   CNAMTB(  19)
     *        /11000   ,     'E     '/
C          NAMTBL ENTRY FOR F     
      DATA NAMTBL(  20),   CNAMTB(  20)
     *        /11000   ,     'F     '/
C          NAMTBL ENTRY FOR G     
      DATA NAMTBL(  21),   CNAMTB(  21)
     *        /11000   ,     'G     '/
C          NAMTBL ENTRY FOR H     
      DATA NAMTBL(  22),   CNAMTB(  22)
     *        /11000   ,     'H     '/
C          NAMTBL ENTRY FOR I     
      DATA NAMTBL(  23),   CNAMTB(  23)
     *        /11000   ,     'I     '/
C          NAMTBL ENTRY FOR .     
      DATA NAMTBL(  24),   CNAMTB(  24)
     *        /21000   ,     '.     '/
C          NAMTBL ENTRY FOR )     
      DATA NAMTBL(  25),   CNAMTB(  25)
     *        / 3000   ,     ')     '/
C          NAMTBL ENTRY FOR -     
      DATA NAMTBL(  26),   CNAMTB(  26)
     *        / 6000   ,     '-     '/
C          NAMTBL ENTRY FOR J     
      DATA NAMTBL(  27),   CNAMTB(  27)
     *        /11000   ,     'J     '/
C          NAMTBL ENTRY FOR K     
      DATA NAMTBL(  28),   CNAMTB(  28)
     *        /11000   ,     'K     '/
C          NAMTBL ENTRY FOR L     
      DATA NAMTBL(  29),   CNAMTB(  29)
     *        /11000   ,     'L     '/
C          NAMTBL ENTRY FOR M     
      DATA NAMTBL(  30),   CNAMTB(  30)
     *        /11000   ,     'M     '/
C          NAMTBL ENTRY FOR N     
      DATA NAMTBL(  31),   CNAMTB(  31)
     *        /11000   ,     'N     '/
C          NAMTBL ENTRY FOR O     
      DATA NAMTBL(  32),   CNAMTB(  32)
     *        /11000   ,     'O     '/
C          NAMTBL ENTRY FOR P     
      DATA NAMTBL(  33),   CNAMTB(  33)
     *        /11000   ,     'P     '/
C          NAMTBL ENTRY FOR Q     
      DATA NAMTBL(  34),   CNAMTB(  34)
     *        /11000   ,     'Q     '/
C          NAMTBL ENTRY FOR R     
      DATA NAMTBL(  35),   CNAMTB(  35)
     *        /11000   ,     'R     '/
C          NAMTBL ENTRY FOR $     
      DATA NAMTBL(  36),   CNAMTB(  36)
     *        /15000   ,     '$     '/
C          NAMTBL ENTRY FOR *     
      DATA NAMTBL(  37),   CNAMTB(  37)
     *        / 9000   ,     '*     '/
C          NAMTBL ENTRY FOR       
      DATA NAMTBL(  38),   CNAMTB(  38)
     *        /13000   ,     '      '/
C          NAMTBL ENTRY FOR /     
      DATA NAMTBL(  39),   CNAMTB(  39)
     *        / 5000   ,     '/     '/
C          NAMTBL ENTRY FOR S     
      DATA NAMTBL(  40),   CNAMTB(  40)
     *        /11000   ,     'S     '/
C          NAMTBL ENTRY FOR T     
      DATA NAMTBL(  41),   CNAMTB(  41)
     *        /11000   ,     'T     '/
C          NAMTBL ENTRY FOR U     
      DATA NAMTBL(  42),   CNAMTB(  42)
     *        /11000   ,     'U     '/
C          NAMTBL ENTRY FOR V     
      DATA NAMTBL(  43),   CNAMTB(  43)
     *        /11000   ,     'V     '/
C          NAMTBL ENTRY FOR W     
      DATA NAMTBL(  44),   CNAMTB(  44)
     *        /11000   ,     'W     '/
C          NAMTBL ENTRY FOR X     
      DATA NAMTBL(  45),   CNAMTB(  45)
     *        /11000   ,     'X     '/
C          NAMTBL ENTRY FOR Y     
      DATA NAMTBL(  46),   CNAMTB(  46)
     *        /11000   ,     'Y     '/
C          NAMTBL ENTRY FOR Z     
      DATA NAMTBL(  47),   CNAMTB(  47)
     *        /11000   ,     'Z     '/
C          NAMTBL ENTRY FOR ,     
      DATA NAMTBL(  48),   CNAMTB(  48)
     *        / 1000   ,     ',     '/
C          NAMTBL ENTRY FOR (     
      DATA NAMTBL(  49),   CNAMTB(  49)
     *        / 2000   ,     '(     '/
C          NAMTBL ENTRY FOR LTERM 
      DATA NAMTBL(  50),   CNAMTB(  50)
     *        /24000   ,     'LTERM '/
C          NAMTBL ENTRY FOR RTERM 
      DATA NAMTBL(  51),   CNAMTB(  51)
     *        / 4000   ,     'RTERM '/
C          NAMTBL ENTRY FOR MCLTRM
      DATA NAMTBL(  52),   CNAMTB(  52)
     *        /38000   ,     'MCLTRM'/
C          NAMTBL ENTRY FOR DBLAST
      DATA NAMTBL(  53),   CNAMTB(  53)
     *        /32000   ,     'DBLAST'/
C          NAMTBL ENTRY FOR DOT   
      DATA NAMTBL(  54),   CNAMTB(  54)
     *        /25000   ,     'DOT   '/
C          NAMTBL ENTRY FOR KREUZ 
      DATA NAMTBL(  55),   CNAMTB(  55)
     *        /26000   ,     'KREUZ '/
C          NAMTBL ENTRY FOR CONAST
      DATA NAMTBL(  56),   CNAMTB(  56)
     *        /45000   ,     'CONAST'/
C          NAMTBL ENTRY FOR UNDEF 
      DATA NAMTBL(  57),   CNAMTB(  57)
     *        /19100   ,     'UNDEF '/
C          NAMTBL ENTRY FOR APT001
      DATA NAMTBL(  58),   CNAMTB(  58)
     *        /19101   ,     'APT001'/
C          NAMTBL ENTRY FOR APT003
      DATA NAMTBL(  59),   CNAMTB(  59)
     *        /19102   ,     'APT003'/
C          NAMTBL ENTRY FOR APT004
      DATA NAMTBL(  60),   CNAMTB(  60)
     *        /19103   ,     'APT004'/
C          NAMTBL ENTRY FOR APT005
      DATA NAMTBL(  61),   CNAMTB(  61)
     *        /19104   ,     'APT005'/
C          NAMTBL ENTRY FOR APT006
      DATA NAMTBL(  62),   CNAMTB(  62)
     *        /19105   ,     'APT006'/
C          NAMTBL ENTRY FOR APT007
      DATA NAMTBL(  63),   CNAMTB(  63)
     *        /19106   ,     'APT007'/
C          NAMTBL ENTRY FOR APT008
      DATA NAMTBL(  64),   CNAMTB(  64)
     *        /19107   ,     'APT008'/
C          NAMTBL ENTRY FOR APT009
      DATA NAMTBL(  65),   CNAMTB(  65)
     *        /19108   ,     'APT009'/
C          NAMTBL ENTRY FOR APT010
      DATA NAMTBL(  66),   CNAMTB(  66)
     *        /19109   ,     'APT010'/
C          NAMTBL ENTRY FOR APT011
      DATA NAMTBL(  67),   CNAMTB(  67)
     *        /19110   ,     'APT011'/
C          NAMTBL ENTRY FOR APT012
      DATA NAMTBL(  68),   CNAMTB(  68)
     *        /19111   ,     'APT012'/
C          NAMTBL ENTRY FOR APT014
      DATA NAMTBL(  69),   CNAMTB(  69)
     *        /19112   ,     'APT014'/
C          NAMTBL ENTRY FOR APT015
      DATA NAMTBL(  70),   CNAMTB(  70)
     *        /19113   ,     'APT015'/
C          NAMTBL ENTRY FOR APT016
      DATA NAMTBL(  71),   CNAMTB(  71)
     *        /19114   ,     'APT016'/
C          NAMTBL ENTRY FOR APT017
      DATA NAMTBL(  72),   CNAMTB(  72)
     *        /19115   ,     'APT017'/
C          NAMTBL ENTRY FOR APT018
      DATA NAMTBL(  73),   CNAMTB(  73)
     *        /19116   ,     'APT018'/
C          NAMTBL ENTRY FOR APT019
      DATA NAMTBL(  74),   CNAMTB(  74)
     *        /19117   ,     'APT019'/
C          NAMTBL ENTRY FOR APT020
      DATA NAMTBL(  75),   CNAMTB(  75)
     *        /19118   ,     'APT020'/
C          NAMTBL ENTRY FOR APT021
      DATA NAMTBL(  76),   CNAMTB(  76)
     *        /19119   ,     'APT021'/
C          NAMTBL ENTRY FOR APT022
      DATA NAMTBL(  77),   CNAMTB(  77)
     *        /19120   ,     'APT022'/
C          NAMTBL ENTRY FOR APT023
      DATA NAMTBL(  78),   CNAMTB(  78)
     *        /19121   ,     'APT023'/
C          NAMTBL ENTRY FOR APT024
      DATA NAMTBL(  79),   CNAMTB(  79)
     *        /19122   ,     'APT024'/
C          NAMTBL ENTRY FOR APT025
      DATA NAMTBL(  80),   CNAMTB(  80)
     *        /19123   ,     'APT025'/
C          NAMTBL ENTRY FOR APT026
      DATA NAMTBL(  81),   CNAMTB(  81)
     *        /19124   ,     'APT026'/
C          NAMTBL ENTRY FOR APT027
      DATA NAMTBL(  82),   CNAMTB(  82)
     *        /19125   ,     'APT027'/
C          NAMTBL ENTRY FOR APT028
      DATA NAMTBL(  83),   CNAMTB(  83)
     *        /19126   ,     'APT028'/
C          NAMTBL ENTRY FOR APT029
      DATA NAMTBL(  84),   CNAMTB(  84)
     *        /19127   ,     'APT029'/
C          NAMTBL ENTRY FOR APT030
      DATA NAMTBL(  85),   CNAMTB(  85)
     *        /19128   ,     'APT030'/
C          NAMTBL ENTRY FOR APT031
      DATA NAMTBL(  86),   CNAMTB(  86)
     *        /19129   ,     'APT031'/
C          NAMTBL ENTRY FOR APT032
      DATA NAMTBL(  87),   CNAMTB(  87)
     *        /19130   ,     'APT032'/
C          NAMTBL ENTRY FOR APT033
      DATA NAMTBL(  88),   CNAMTB(  88)
     *        /19131   ,     'APT033'/
C          NAMTBL ENTRY FOR APT035
      DATA NAMTBL(  89),   CNAMTB(  89)
     *        /19132   ,     'APT035'/
C          NAMTBL ENTRY FOR APT036
      DATA NAMTBL(  90),   CNAMTB(  90)
     *        /19133   ,     'APT036'/
C          NAMTBL ENTRY FOR APT037
      DATA NAMTBL(  91),   CNAMTB(  91)
     *        /19134   ,     'APT037'/
C          NAMTBL ENTRY FOR APT038
      DATA NAMTBL(  92),   CNAMTB(  92)
     *        /19135   ,     'APT038'/
C          NAMTBL ENTRY FOR APT039
      DATA NAMTBL(  93),   CNAMTB(  93)
     *        /19136   ,     'APT039'/
C          NAMTBL ENTRY FOR APT040
      DATA NAMTBL(  94),   CNAMTB(  94)
     *        /19137   ,     'APT040'/
C          NAMTBL ENTRY FOR APT044
      DATA NAMTBL(  95),   CNAMTB(  95)
     *        /19138   ,     'APT044'/
C          NAMTBL ENTRY FOR APT045
      DATA NAMTBL(  96),   CNAMTB(  96)
     *        /19139   ,     'APT045'/
C          NAMTBL ENTRY FOR APT046
      DATA NAMTBL(  97),   CNAMTB(  97)
     *        /19140   ,     'APT046'/
C          NAMTBL ENTRY FOR APT047
      DATA NAMTBL(  98),   CNAMTB(  98)
     *        /19141   ,     'APT047'/
C          NAMTBL ENTRY FOR APT048
      DATA NAMTBL(  99),   CNAMTB(  99)
     *        /19142   ,     'APT048'/
C          NAMTBL ENTRY FOR APT049
      DATA NAMTBL( 100),   CNAMTB( 100)
     *        /19143   ,     'APT049'/
C          NAMTBL ENTRY FOR APT050
      DATA NAMTBL( 101),   CNAMTB( 101)
     *        /19144   ,     'APT050'/
C          NAMTBL ENTRY FOR APT051
      DATA NAMTBL( 102),   CNAMTB( 102)
     *        /19145   ,     'APT051'/
C          NAMTBL ENTRY FOR APT052
      DATA NAMTBL( 103),   CNAMTB( 103)
     *        /19146   ,     'APT052'/
C          NAMTBL ENTRY FOR APT053
      DATA NAMTBL( 104),   CNAMTB( 104)
     *        /19147   ,     'APT053'/
C          NAMTBL ENTRY FOR APT054
      DATA NAMTBL( 105),   CNAMTB( 105)
     *        /19148   ,     'APT054'/
C          NAMTBL ENTRY FOR APT055
      DATA NAMTBL( 106),   CNAMTB( 106)
     *        /19149   ,     'APT055'/
C          NAMTBL ENTRY FOR APT056
      DATA NAMTBL( 107),   CNAMTB( 107)
     *        /19150   ,     'APT056'/
C          NAMTBL ENTRY FOR APT057
      DATA NAMTBL( 108),   CNAMTB( 108)
     *        /19151   ,     'APT057'/
C          NAMTBL ENTRY FOR APT058
      DATA NAMTBL( 109),   CNAMTB( 109)
     *        /19152   ,     'APT058'/
C          NAMTBL ENTRY FOR APT060
      DATA NAMTBL( 110),   CNAMTB( 110)
     *        /19153   ,     'APT060'/
C          NAMTBL ENTRY FOR APT061
      DATA NAMTBL( 111),   CNAMTB( 111)
     *        /19154   ,     'APT061'/
C          NAMTBL ENTRY FOR APT062
      DATA NAMTBL( 112),   CNAMTB( 112)
     *        /19155   ,     'APT062'/
C          NAMTBL ENTRY FOR APT063
      DATA NAMTBL( 113),   CNAMTB( 113)
     *        /19156   ,     'APT063'/
C          NAMTBL ENTRY FOR APT064
      DATA NAMTBL( 114),   CNAMTB( 114)
     *        /19157   ,     'APT064'/
C          NAMTBL ENTRY FOR APT065
      DATA NAMTBL( 115),   CNAMTB( 115)
     *        /19158   ,     'APT065'/
C          NAMTBL ENTRY FOR APT066
      DATA NAMTBL( 116),   CNAMTB( 116)
     *        /19159   ,     'APT066'/
C          NAMTBL ENTRY FOR APT067
      DATA NAMTBL( 117),   CNAMTB( 117)
     *        /19160   ,     'APT067'/
C          NAMTBL ENTRY FOR APT068
      DATA NAMTBL( 118),   CNAMTB( 118)
     *        /19161   ,     'APT068'/
C          NAMTBL ENTRY FOR APT073
      DATA NAMTBL( 119),   CNAMTB( 119)
     *        /19162   ,     'APT073'/
C          NAMTBL ENTRY FOR APT075
      DATA NAMTBL( 120),   CNAMTB( 120)
     *        /19163   ,     'APT075'/
C          NAMTBL ENTRY FOR APT077
      DATA NAMTBL( 121),   CNAMTB( 121)
     *        /19164   ,     'APT077'/
C          NAMTBL ENTRY FOR APT078
      DATA NAMTBL( 122),   CNAMTB( 122)
     *        /19165   ,     'APT078'/
C          NAMTBL ENTRY FOR APT079
      DATA NAMTBL( 123),   CNAMTB( 123)
     *        /19166   ,     'APT079'/
C          NAMTBL ENTRY FOR APT081
      DATA NAMTBL( 124),   CNAMTB( 124)
     *        /19167   ,     'APT081'/
C          NAMTBL ENTRY FOR APT083
      DATA NAMTBL( 125),   CNAMTB( 125)
     *        /19168   ,     'APT083'/
C          NAMTBL ENTRY FOR APT085
      DATA NAMTBL( 126),   CNAMTB( 126)
     *        /19169   ,     'APT085'/
C          NAMTBL ENTRY FOR APT087
      DATA NAMTBL( 127),   CNAMTB( 127)
     *        /19170   ,     'APT087'/
C          NAMTBL ENTRY FOR APT088
      DATA NAMTBL( 128),   CNAMTB( 128)
     *        /19171   ,     'APT088'/
C          NAMTBL ENTRY FOR APT090
      DATA NAMTBL( 129),   CNAMTB( 129)
     *        /19172   ,     'APT090'/
C          NAMTBL ENTRY FOR APT092
      DATA NAMTBL( 130),   CNAMTB( 130)
     *        /19173   ,     'APT092'/
C          NAMTBL ENTRY FOR APT093
      DATA NAMTBL( 131),   CNAMTB( 131)
     *        /19174   ,     'APT093'/
C          NAMTBL ENTRY FOR APT094
      DATA NAMTBL( 132),   CNAMTB( 132)
     *        /19175   ,     'APT094'/
C          NAMTBL ENTRY FOR APT100
      DATA NAMTBL( 133),   CNAMTB( 133)
     *        /19176   ,     'APT100'/
C          NAMTBL ENTRY FOR APT200
      DATA NAMTBL( 134),   CNAMTB( 134)
     *        /19177   ,     'APT200'/
C          NAMTBL ENTRY FOR APT201
      DATA NAMTBL( 135),   CNAMTB( 135)
     *        /19178   ,     'APT201'/
C          NAMTBL ENTRY FOR APT298
      DATA NAMTBL( 136),   CNAMTB( 136)
     *        /19179   ,     'APT298'/
C          NAMTBL ENTRY FOR APT299
      DATA NAMTBL( 137),   CNAMTB( 137)
     *        /19180   ,     'APT299'/
C          NAMTBL ENTRY FOR APT041
      DATA NAMTBL( 138),   CNAMTB( 138)
     *        /19193   ,     'APT041'/
C          NAMTBL ENTRY FOR APT043
      DATA NAMTBL( 139),   CNAMTB( 139)
     *        /19195   ,     'APT043'/
C          NAMTBL ENTRY FOR APT295
      DATA NAMTBL( 140),   CNAMTB( 140)
     *        /19196   ,     'APT295'/
C          NAMTBL ENTRY FOR APT042
      DATA NAMTBL( 141),   CNAMTB( 141)
     *        /19194   ,     'APT042'/
C          NAMTBL ENTRY FOR APT069
      DATA NAMTBL( 142),   CNAMTB( 142)
     *        /19198   ,     'APT069'/
C          NAMTBL ENTRY FOR APT070
      DATA NAMTBL( 143),   CNAMTB( 143)
     *        /19199   ,     'APT070'/
C          NAMTBL ENTRY FOR APT071
      DATA NAMTBL( 144),   CNAMTB( 144)
     *        /19200   ,     'APT071'/
C          NAMTBL ENTRY FOR APT072
      DATA NAMTBL( 145),   CNAMTB( 145)
     *        /19201   ,     'APT072'/
C          NAMTBL ENTRY FOR APT074
      DATA NAMTBL( 146),   CNAMTB( 146)
     *        /19203   ,     'APT074'/
C          NAMTBL ENTRY FOR APT034
      DATA NAMTBL( 147),   CNAMTB( 147)
     *        /19204   ,     'APT034'/
C          NAMTBL ENTRY FOR DEFEXT
      DATA NAMTBL( 148),   CNAMTB( 148)
     *        /19202   ,     'DEFEXT'/
C          NAMTBL ENTRY FOR APT101
      DATA NAMTBL( 149),   CNAMTB( 149)
     *        /19207   ,     'APT101'/
C          NAMTBL ENTRY FOR NDTEST
      DATA NAMTBL( 150),   CNAMTB( 150)
     *        /19011   ,     'NDTEST'/
C          NAMTBL ENTRY FOR COMP3D
      DATA NAMTBL( 151),   CNAMTB( 151)
     *        /19012   ,     'COMP3D'/
C          NAMTBL ENTRY FOR TLON  
      DATA NAMTBL( 152),   CNAMTB( 152)
     *        /19003   ,     'TLON  '/
C          NAMTBL ENTRY FOR GOTOPN
      DATA NAMTBL( 153),   CNAMTB( 153)
     *        /19208   ,     'GOTOPN'/
C          NAMTBL ENTRY FOR APT105
      DATA NAMTBL( 154),   CNAMTB( 154)
     *        /19209   ,     'APT105'/
C          NAMTBL ENTRY FOR APT106
      DATA NAMTBL( 155),   CNAMTB( 155)
     *        /19211   ,     'APT106'/
C          NAMTBL ENTRY FOR TRANSF
      DATA NAMTBL( 156),   CNAMTB( 156)
     *        /19212   ,     'TRANSF'/
C          NAMTBL ENTRY FOR APT104
      DATA NAMTBL( 157),   CNAMTB( 157)
     *        /19213   ,     'APT104'/
C          NAMTBL ENTRY FOR APT102
      DATA NAMTBL( 158),   CNAMTB( 158)
     *        /19214   ,     'APT102'/
C          NAMTBL ENTRY FOR APT103
      DATA NAMTBL( 159),   CNAMTB( 159)
     *        /19215   ,     'APT103'/
C          NAMTBL ENTRY FOR APT107
      DATA NAMTBL( 160),   CNAMTB( 160)
     *        /19216   ,     'APT107'/
C          NAMTBL ENTRY FOR APT013
      DATA NAMTBL( 161),   CNAMTB( 161)
     *        /19217   ,     'APT013'/
C          NAMTBL ENTRY FOR APT108
      DATA NAMTBL( 162),   CNAMTB( 162)
     *        /19218   ,     'APT108'/
C          NAMTBL ENTRY FOR APT109
      DATA NAMTBL( 163),   CNAMTB( 163)
     *        /19219   ,     'APT109'/
C          NAMTBL ENTRY FOR APT110
      DATA NAMTBL( 164),   CNAMTB( 164)
     *        /19247   ,     'APT110'/
C          NAMTBL ENTRY FOR LOGIF 
      DATA NAMTBL( 165),   CNAMTB( 165)
     *        /19248   ,     'LOGIF '/
C          NAMTBL ENTRY FOR .AC.  
      DATA NAMTBL( 166),   CNAMTB( 166)
     *        /31000   ,     '.AC.  '/
C          NAMTBL ENTRY FOR APTER 
      DATA NAMTBL( 167),   CNAMTB( 167)
     *        /31000   ,     'APTER '/
C          NAMTBL ENTRY FOR $21T$1
      DATA NAMTBL( 168),   CNAMTB( 168)
     *        /31000   ,     '$21T$1'/
C          NAMTBL ENTRY FOR $$TAB 
      DATA NAMTBL( 169),   CNAMTB( 169)
     *        /31000   ,     '$$TAB '/
C          NAMTBL ENTRY FOR INSERT
      DATA NAMTBL( 173),   CNAMTB( 173)
     *        /40000   ,     'INSERT'/
C          NAMTBL ENTRY FOR CORNFD
      DATA NAMTBL( 176),   CNAMTB( 176)
     *        /40000   ,     'CORNFD'/
C          NAMTBL ENTRY FOR PTONLY
      DATA NAMTBL( 177),   CNAMTB( 177)
     *        /40056   ,     'PTONLY'/
C          NAMTBL ENTRY FOR DRILL 
      DATA NAMTBL( 184),   CNAMTB( 184)
     *        /35100   ,     'DRILL '/
C          NAMTBL ENTRY FOR OMIT  
      DATA NAMTBL( 208),   CNAMTB( 208)
     *        /35064   ,     'OMIT  '/
C          NAMTBL ENTRY FOR TMARK 
      DATA NAMTBL( 209),   CNAMTB( 209)
     *        /40000   ,     'TMARK '/
C          NAMTBL ENTRY FOR FWD   
      DATA NAMTBL( 212),   CNAMTB( 212)
     *        /35100   ,     'FWD   '/
C          NAMTBL ENTRY FOR SUBSCR
      DATA NAMTBL( 227),   CNAMTB( 227)
     *        /39024   ,     'SUBSCR'/
C          NAMTBL ENTRY FOR GOCLER
      DATA NAMTBL( 238),   CNAMTB( 238)
     *        /40000   ,     'GOCLER'/
C          NAMTBL ENTRY FOR TLNDON
      DATA NAMTBL( 246),   CNAMTB( 246)
     *        /40053   ,     'TLNDON'/
C          NAMTBL ENTRY FOR NPS   
      DATA NAMTBL( 248),   CNAMTB( 248)
     *        /35187   ,     'NPS   '/
C          NAMTBL ENTRY FOR SMESH 
      DATA NAMTBL( 257),   CNAMTB( 257)
     *        /35132   ,     'SMESH '/
C          NAMTBL ENTRY FOR CYLNDR
      DATA NAMTBL( 270),   CNAMTB( 270)
     *        /39003   ,     'CYLNDR'/
C          NAMTBL ENTRY FOR GRID  
      DATA NAMTBL( 274),   CNAMTB( 274)
     *        /35054   ,     'GRID  '/
C          NAMTBL ENTRY FOR STOP  
      DATA NAMTBL( 276),   CNAMTB( 276)
     *        /40000   ,     'STOP  '/
C          NAMTBL ENTRY FOR AWAY  
      DATA NAMTBL( 281),   CNAMTB( 281)
     *        /35158   ,     'AWAY  '/
C          NAMTBL ENTRY FOR SADDLE
      DATA NAMTBL( 294),   CNAMTB( 294)
     *        /35100   ,     'SADDLE'/
C          NAMTBL ENTRY FOR 2DCALC
      DATA NAMTBL( 295),   CNAMTB( 295)
     *        /40051   ,     '2DCALC'/
C          NAMTBL ENTRY FOR UCONST
      DATA NAMTBL( 304),   CNAMTB( 304)
     *        /35170   ,     'UCONST'/
C          NAMTBL ENTRY FOR REWIND
      DATA NAMTBL( 311),   CNAMTB( 311)
     *        /40000   ,     'REWIND'/
C          NAMTBL ENTRY FOR PVAL  
      DATA NAMTBL( 312),   CNAMTB( 312)
     *        /35069   ,     'PVAL  '/
C          NAMTBL ENTRY FOR CIRCUL
      DATA NAMTBL( 319),   CNAMTB( 319)
     *        /35100   ,     'CIRCUL'/
C          NAMTBL ENTRY FOR CIRCLE
      DATA NAMTBL( 320),   CNAMTB( 320)
     *        /39004   ,     'CIRCLE'/
C          NAMTBL ENTRY FOR RTHETA
      DATA NAMTBL( 327),   CNAMTB( 327)
     *        /35026   ,     'RTHETA'/
C          NAMTBL ENTRY FOR CIRLIN
      DATA NAMTBL( 328),   CNAMTB( 328)
     *        /35100   ,     'CIRLIN'/
C          NAMTBL ENTRY FOR READ  
      DATA NAMTBL( 334),   CNAMTB( 334)
     *        /40057   ,     'READ  '/
C          NAMTBL ENTRY FOR RELTOL
      DATA NAMTBL( 336),   CNAMTB( 336)
     *        /35171   ,     'RELTOL'/
C          NAMTBL ENTRY FOR REAL  
      DATA NAMTBL( 342),   CNAMTB( 342)
     *        /39021   ,     'REAL  '/
C          NAMTBL ENTRY FOR REAM  
      DATA NAMTBL( 343),   CNAMTB( 343)
     *        /35100   ,     'REAM  '/
C          NAMTBL ENTRY FOR AVCTRL
      DATA NAMTBL( 344),   CNAMTB( 344)
     *        /40065   ,     'AVCTRL'/
C          NAMTBL ENTRY FOR AVCXXX
      DATA NAMTBL( 346),   CNAMTB( 346)
     *        /39045   ,     'AVCXXX'/
C          NAMTBL ENTRY FOR OVPLOT
      DATA NAMTBL( 347),   CNAMTB( 347)
     *        /40000   ,     'OVPLOT'/
C          NAMTBL ENTRY FOR REAR  
      DATA NAMTBL( 348),   CNAMTB( 348)
     *        /35100   ,     'REAR  '/
C          NAMTBL ENTRY FOR PUNCH 
      DATA NAMTBL( 355),   CNAMTB( 355)
     *        /19050   ,     'PUNCH '/
C          NAMTBL ENTRY FOR CENTER
      DATA NAMTBL( 358),   CNAMTB( 358)
     *        /35017   ,     'CENTER'/
C          NAMTBL ENTRY FOR DDLIM 
      DATA NAMTBL( 365),   CNAMTB( 365)
     *        /19185   ,     'DDLIM '/
C          NAMTBL ENTRY FOR .EQ   
      DATA NAMTBL( 388),   CNAMTB( 388)
     *        /27001   ,     '.EQ   '/
C          NAMTBL ENTRY FOR XCOORD
      DATA NAMTBL( 403),   CNAMTB( 403)
     *        /35100   ,     'XCOORD'/
C          NAMTBL ENTRY FOR SVAL  
      DATA NAMTBL( 410),   CNAMTB( 410)
     *        /35069   ,     'SVAL  '/
C          NAMTBL ENTRY FOR COSB  
      DATA NAMTBL( 420),   CNAMTB( 420)
     *        /18228   ,     'COSB  '/
C          NAMTBL ENTRY FOR COSF  
      DATA NAMTBL( 424),   CNAMTB( 424)
     *        /18184   ,     'COSF  '/
C          NAMTBL ENTRY FOR COSHF 
      DATA NAMTBL( 426),   CNAMTB( 426)
     *        /18236   ,     'COSHF '/
C          NAMTBL ENTRY FOR SCALE 
      DATA NAMTBL( 427),   CNAMTB( 427)
     *        /35036   ,     'SCALE '/
C          NAMTBL ENTRY FOR SCALAR
      DATA NAMTBL( 428),   CNAMTB( 428)
     *        /35126   ,     'SCALAR'/
C          NAMTBL ENTRY FOR INTERC
      DATA NAMTBL( 429),   CNAMTB( 429)
     *        /35015   ,     'INTERC'/
C          NAMTBL ENTRY FOR INTF  
      DATA NAMTBL( 430),   CNAMTB( 430)
     *        /18241   ,     'INTF  '/
C          NAMTBL ENTRY FOR INTENS
      DATA NAMTBL( 431),   CNAMTB( 431)
     *        /35100   ,     'INTENS'/
C          NAMTBL ENTRY FOR SCALOP
      DATA NAMTBL( 432),   CNAMTB( 432)
     *        /35155   ,     'SCALOP'/
C          NAMTBL ENTRY FOR BACK  
      DATA NAMTBL( 433),   CNAMTB( 433)
     *        /35159   ,     'BACK  '/
C          NAMTBL ENTRY FOR CS    
      DATA NAMTBL( 434),   CNAMTB( 434)
     *        /35001   ,     'CS    '/
C          NAMTBL ENTRY FOR INTCOD
      DATA NAMTBL( 435),   CNAMTB( 435)
     *        /40000   ,     'INTCOD'/
C          NAMTBL ENTRY FOR .LE   
      DATA NAMTBL( 438),   CNAMTB( 438)
     *        /27004   ,     '.LE   '/
C          NAMTBL ENTRY FOR INTOF 
      DATA NAMTBL( 439),   CNAMTB( 439)
     *        /35006   ,     'INTOF '/
C          NAMTBL ENTRY FOR INTOL 
      DATA NAMTBL( 440),   CNAMTB( 440)
     *        /40028   ,     'INTOL '/
C          NAMTBL ENTRY FOR INTSEC
      DATA NAMTBL( 443),   CNAMTB( 443)
     *        /40060   ,     'INTSEC'/
C          NAMTBL ENTRY FOR TITLES
      DATA NAMTBL( 452),   CNAMTB( 452)
     *        /40049   ,     'TITLES'/
C          NAMTBL ENTRY FOR LOG10F
      DATA NAMTBL( 455),   CNAMTB( 455)
     *        /18221   ,     'LOG10F'/
C          NAMTBL ENTRY FOR PPLOT 
      DATA NAMTBL( 456),   CNAMTB( 456)
     *        /40000   ,     'PPLOT '/
C          NAMTBL ENTRY FOR INIT  
      DATA NAMTBL( 458),   CNAMTB( 458)
     *        /35161   ,     'INIT  '/
C          NAMTBL ENTRY FOR ZSMALL
      DATA NAMTBL( 475),   CNAMTB( 475)
     *        /35047   ,     'ZSMALL'/
C          NAMTBL ENTRY FOR LOGF  
      DATA NAMTBL( 476),   CNAMTB( 476)
     *        /18190   ,     'LOGF  '/
C          NAMTBL ENTRY FOR CUT   
      DATA NAMTBL( 488),   CNAMTB( 488)
     *        /40009   ,     'CUT   '/
C          NAMTBL ENTRY FOR IF    
      DATA NAMTBL( 492),   CNAMTB( 492)
     *        /41001   ,     'IF    '/
C          NAMTBL ENTRY FOR GODLTA
      DATA NAMTBL( 494),   CNAMTB( 494)
     *        /40026   ,     'GODLTA'/
C          NAMTBL ENTRY FOR GODOWN
      DATA NAMTBL( 497),   CNAMTB( 497)
     *        /40034   ,     'GODOWN'/
C          NAMTBL ENTRY FOR OPPLOT
      DATA NAMTBL( 500),   CNAMTB( 500)
     *        /40000   ,     'OPPLOT'/
C          NAMTBL ENTRY FOR TLOFPS
      DATA NAMTBL( 504),   CNAMTB( 504)
     *        /40005   ,     'TLOFPS'/
C          NAMTBL ENTRY FOR HYPERB
      DATA NAMTBL( 505),   CNAMTB( 505)
     *        /39006   ,     'HYPERB'/
C          NAMTBL ENTRY FOR VVAL  
      DATA NAMTBL( 508),   CNAMTB( 508)
     *        /35069   ,     'VVAL  '/
C          NAMTBL ENTRY FOR TA    
      DATA NAMTBL( 509),   CNAMTB( 509)
     *        /35182   ,     'TA    '/
C          NAMTBL ENTRY FOR SETANG
      DATA NAMTBL( 511),   CNAMTB( 511)
     *        /35100   ,     'SETANG'/
C          NAMTBL ENTRY FOR TLON  
      DATA NAMTBL( 512),   CNAMTB( 512)
     *        /40003   ,     'TLON  '/
C          NAMTBL ENTRY FOR TLONPS
      DATA NAMTBL( 513),   CNAMTB( 513)
     *        /40004   ,     'TLONPS'/
C          NAMTBL ENTRY FOR OPEN  
      DATA NAMTBL( 516),   CNAMTB( 516)
     *        /35100   ,     'OPEN  '/
C          NAMTBL ENTRY FOR CUTANG
      DATA NAMTBL( 521),   CNAMTB( 521)
     *        /35071   ,     'CUTANG'/
C          NAMTBL ENTRY FOR CUTCOM
      DATA NAMTBL( 523),   CNAMTB( 523)
     *        /40000   ,     'CUTCOM'/
C          NAMTBL ENTRY FOR SETOOL
      DATA NAMTBL( 525),   CNAMTB( 525)
     *        /35100   ,     'SETOOL'/
C          NAMTBL ENTRY FOR LNTHF 
      DATA NAMTBL( 530),   CNAMTB( 530)
     *        /18189   ,     'LNTHF '/
C          NAMTBL ENTRY FOR POCKET
      DATA NAMTBL( 531),   CNAMTB( 531)
     *        /40048   ,     'POCKET'/
C          NAMTBL ENTRY FOR UVPDS 
      DATA NAMTBL( 534),   CNAMTB( 534)
     *        /35188   ,     'UVPDS '/
C          NAMTBL ENTRY FOR CUTTER
      DATA NAMTBL( 540),   CNAMTB( 540)
     *        /40030   ,     'CUTTER'/
C          NAMTBL ENTRY FOR WITH  
      DATA NAMTBL( 546),   CNAMTB( 546)
     *        /35073   ,     'WITH  '/
C          NAMTBL ENTRY FOR SPLINE
      DATA NAMTBL( 547),   CNAMTB( 547)
     *        /35030   ,     'SPLINE'/
C          NAMTBL ENTRY FOR STEP  
      DATA NAMTBL( 548),   CNAMTB( 548)
     *        /35100   ,     'STEP  '/
C          NAMTBL ENTRY FOR STEPOV
      DATA NAMTBL( 549),   CNAMTB( 549)
     *        /35162   ,     'STEPOV'/
C          NAMTBL ENTRY FOR UVPPS 
      DATA NAMTBL( 550),   CNAMTB( 550)
     *        /35188   ,     'UVPPS '/
C          NAMTBL ENTRY FOR NDS   
      DATA NAMTBL( 556),   CNAMTB( 556)
     *        /35185   ,     'NDS   '/
C          NAMTBL ENTRY FOR DARK  
      DATA NAMTBL( 565),   CNAMTB( 565)
     *        /35100   ,     'DARK  '/
C          NAMTBL ENTRY FOR MINF  
      DATA NAMTBL( 568),   CNAMTB( 568)
     *        /18238   ,     'MINF  '/
C          NAMTBL ENTRY FOR YZPLAN
      DATA NAMTBL( 570),   CNAMTB( 570)
     *        /35037   ,     'YZPLAN'/
C          NAMTBL ENTRY FOR SPATF 
      DATA NAMTBL( 572),   CNAMTB( 572)
     *        /18243   ,     'SPATF '/
C          NAMTBL ENTRY FOR AVOID 
      DATA NAMTBL( 573),   CNAMTB( 573)
     *        /35062   ,     'AVOID '/
C          NAMTBL ENTRY FOR REMARK
      DATA NAMTBL( 574),   CNAMTB( 574)
     *        /40056   ,     'REMARK'/
C          NAMTBL ENTRY FOR PRINT 
      DATA NAMTBL( 578),   CNAMTB( 578)
     *        /19042   ,     'PRINT '/
C          NAMTBL ENTRY FOR MINUS 
      DATA NAMTBL( 583),   CNAMTB( 583)
     *        /35041   ,     'MINUS '/
C          NAMTBL ENTRY FOR GFTXXX
      DATA NAMTBL( 588),   CNAMTB( 588)
     *        /39048   ,     'GFTXXX'/
C          NAMTBL ENTRY FOR DSTAN 
      DATA NAMTBL( 605),   CNAMTB( 605)
     *        /35147   ,     'DSTAN '/
C          NAMTBL ENTRY FOR RAIL  
      DATA NAMTBL( 606),   CNAMTB( 606)
     *        /35100   ,     'RAIL  '/
C          NAMTBL ENTRY FOR 4PT1SL
      DATA NAMTBL( 615),   CNAMTB( 615)
     *        /35052   ,     '4PT1SL'/
C          NAMTBL ENTRY FOR ANGLF 
      DATA NAMTBL( 620),   CNAMTB( 620)
     *        /18197   ,     'ANGLF '/
C          NAMTBL ENTRY FOR ANGLB 
      DATA NAMTBL( 621),   CNAMTB( 621)
     *        /18244   ,     'ANGLB '/
C          NAMTBL ENTRY FOR ANGLE 
      DATA NAMTBL( 622),   CNAMTB( 622)
     *        /35153   ,     'ANGLE '/
C          NAMTBL ENTRY FOR LIGHT 
      DATA NAMTBL( 632),   CNAMTB( 632)
     *        /35100   ,     'LIGHT '/
C          NAMTBL ENTRY FOR ERROR 
      DATA NAMTBL( 637),   CNAMTB( 637)
     *        /18188   ,     'ERROR '/
C          NAMTBL ENTRY FOR LENGTH
      DATA NAMTBL( 639),   CNAMTB( 639)
     *        /35044   ,     'LENGTH'/
C          NAMTBL ENTRY FOR CHUCK 
      DATA NAMTBL( 641),   CNAMTB( 641)
     *        /35100   ,     'CHUCK '/
C          NAMTBL ENTRY FOR ZXPLAN
      DATA NAMTBL( 654),   CNAMTB( 654)
     *        /35048   ,     'ZXPLAN'/
C          NAMTBL ENTRY FOR MDWRIT
      DATA NAMTBL( 655),   CNAMTB( 655)
     *        /40000   ,     'MDWRIT'/
C          NAMTBL ENTRY FOR COTANF
      DATA NAMTBL( 675),   CNAMTB( 675)
     *        /18224   ,     'COTANF'/
C          NAMTBL ENTRY FOR COTANB
      DATA NAMTBL( 676),   CNAMTB( 676)
     *        /18230   ,     'COTANB'/
C          NAMTBL ENTRY FOR HOLDER
      DATA NAMTBL( 680),   CNAMTB( 680)
     *        /35100   ,     'HOLDER'/
C          NAMTBL ENTRY FOR XYVIEW
      DATA NAMTBL( 681),   CNAMTB( 681)
     *        /35100   ,     'XYVIEW'/
C          NAMTBL ENTRY FOR MODE  
      DATA NAMTBL( 683),   CNAMTB( 683)
     *        /40000   ,     'MODE  '/
C          NAMTBL ENTRY FOR MODF  
      DATA NAMTBL( 684),   CNAMTB( 684)
     *        /18240   ,     'MODF  '/
C          NAMTBL ENTRY FOR PICKFD
      DATA NAMTBL( 685),   CNAMTB( 685)
     *        /35166   ,     'PICKFD'/
C          NAMTBL ENTRY FOR PICKUP
      DATA NAMTBL( 686),   CNAMTB( 686)
     *        /40000   ,     'PICKUP'/
C          NAMTBL ENTRY FOR MODIFY
      DATA NAMTBL( 687),   CNAMTB( 687)
     *        /35100   ,     'MODIFY'/
C          NAMTBL ENTRY FOR .AND  
      DATA NAMTBL( 702),   CNAMTB( 702)
     *        /29000   ,     '.AND  '/
C          NAMTBL ENTRY FOR TPI   
      DATA NAMTBL( 714),   CNAMTB( 714)
     *        /35100   ,     'TPI   '/
C          NAMTBL ENTRY FOR FEDRAT
      DATA NAMTBL( 724),   CNAMTB( 724)
     *        /40000   ,     'FEDRAT'/
C          NAMTBL ENTRY FOR CROSS 
      DATA NAMTBL( 751),   CNAMTB( 751)
     *        /35040   ,     'CROSS '/
C          NAMTBL ENTRY FOR TABCYL
      DATA NAMTBL( 757),   CNAMTB( 757)
     *        /43011   ,     'TABCYL'/
C          NAMTBL ENTRY FOR SINB  
      DATA NAMTBL( 760),   CNAMTB( 760)
     *        /18227   ,     'SINB  '/
C          NAMTBL ENTRY FOR SINF  
      DATA NAMTBL( 764),   CNAMTB( 764)
     *        /18191   ,     'SINF  '/
C          NAMTBL ENTRY FOR SINHF 
      DATA NAMTBL( 766),   CNAMTB( 766)
     *        /18235   ,     'SINHF '/
C          NAMTBL ENTRY FOR TABPRT
      DATA NAMTBL( 770),   CNAMTB( 770)
     *        /35130   ,     'TABPRT'/
C          NAMTBL ENTRY FOR IPR   
      DATA NAMTBL( 772),   CNAMTB( 772)
     *        /35100   ,     'IPR   '/
C          NAMTBL ENTRY FOR TLPROJ
      DATA NAMTBL( 773),   CNAMTB( 773)
     *        /40062   ,     'TLPROJ'/
C          NAMTBL ENTRY FOR GCONIC
      DATA NAMTBL( 790),   CNAMTB( 790)
     *        /39010   ,     'GCONIC'/
C          NAMTBL ENTRY FOR CYCLE 
      DATA NAMTBL( 794),   CNAMTB( 794)
     *        /40000   ,     'CYCLE '/
C          NAMTBL ENTRY FOR DELAY 
      DATA NAMTBL( 803),   CNAMTB( 803)
     *        /40000   ,     'DELAY '/
C          NAMTBL ENTRY FOR DELETE
      DATA NAMTBL( 807),   CNAMTB( 807)
     *        /40000   ,     'DELETE'/
C          NAMTBL ENTRY FOR SAFETY
      DATA NAMTBL( 808),   CNAMTB( 808)
     *        /40000   ,     'SAFETY'/
C          NAMTBL ENTRY FOR NEGX  
      DATA NAMTBL( 816),   CNAMTB( 816)
     *        /35045   ,     'NEGX  '/
C          NAMTBL ENTRY FOR NEGY  
      DATA NAMTBL( 817),   CNAMTB( 817)
     *        /35046   ,     'NEGY  '/
C          NAMTBL ENTRY FOR NEGZ  
      DATA NAMTBL( 818),   CNAMTB( 818)
     *        /35047   ,     'NEGZ  '/
C          NAMTBL ENTRY FOR DASH  
      DATA NAMTBL( 819),   CNAMTB( 819)
     *        /35100   ,     'DASH  '/
C          NAMTBL ENTRY FOR NOW   
      DATA NAMTBL( 826),   CNAMTB( 826)
     *        /35100   ,     'NOW   '/
C          NAMTBL ENTRY FOR RIGHT 
      DATA NAMTBL( 828),   CNAMTB( 828)
     *        /35009   ,     'RIGHT '/
C          NAMTBL ENTRY FOR XLARGE
      DATA NAMTBL( 836),   CNAMTB( 836)
     *        /35014   ,     'XLARGE'/
C          NAMTBL ENTRY FOR AVPRT 
      DATA NAMTBL( 838),   CNAMTB( 838)
     *        /35130   ,     'AVPRT '/
C          NAMTBL ENTRY FOR FROM  
      DATA NAMTBL( 843),   CNAMTB( 843)
     *        /40036   ,     'FROM  '/
C          NAMTBL ENTRY FOR FRONT 
      DATA NAMTBL( 844),   CNAMTB( 844)
     *        /35100   ,     'FRONT '/
C          NAMTBL ENTRY FOR NDTEST
      DATA NAMTBL( 849),   CNAMTB( 849)
     *        /40011   ,     'NDTEST'/
C          NAMTBL ENTRY FOR UNIT  
      DATA NAMTBL( 850),   CNAMTB( 850)
     *        /35043   ,     'UNIT  '/
C          NAMTBL ENTRY FOR UNITS 
      DATA NAMTBL( 851),   CNAMTB( 851)
     *        /40058   ,     'UNITS '/
C          NAMTBL ENTRY FOR OUT   
      DATA NAMTBL( 880),   CNAMTB( 880)
     *        /35021   ,     'OUT   '/
C          NAMTBL ENTRY FOR NOLIST
      DATA NAMTBL( 881),   CNAMTB( 881)
     *        /35129   ,     'NOLIST'/
C          NAMTBL ENTRY FOR END   
      DATA NAMTBL( 882),   CNAMTB( 882)
     *        /40000   ,     'END   '/
C          NAMTBL ENTRY FOR MAGTAP
      DATA NAMTBL( 883),   CNAMTB( 883)
     *        /40000   ,     'MAGTAP'/
C          NAMTBL ENTRY FOR CALL  
      DATA NAMTBL( 884),   CNAMTB( 884)
     *        /19043   ,     'CALL  '/
C          NAMTBL ENTRY FOR TRFORM
      DATA NAMTBL( 885),   CNAMTB( 885)
     *        /35031   ,     'TRFORM'/
C          NAMTBL ENTRY FOR LISTON
      DATA NAMTBL( 886),   CNAMTB( 886)
     *        /35128   ,     'LISTON'/
C          NAMTBL ENTRY FOR TYPE  
      DATA NAMTBL( 897),   CNAMTB( 897)
     *        /35100   ,     'TYPE  '/
C          NAMTBL ENTRY FOR CLDATF
      DATA NAMTBL( 901),   CNAMTB( 901)
     *        /18249   ,     'CLDATF'/
C          NAMTBL ENTRY FOR CLDATA
      DATA NAMTBL( 902),   CNAMTB( 902)
     *        /35069   ,     'CLDATA'/
C          NAMTBL ENTRY FOR CLDAT 
      DATA NAMTBL( 903),   CNAMTB( 903)
     *        /40063   ,     'CLDAT '/
C          NAMTBL ENTRY FOR LPRINT
      DATA NAMTBL( 911),   CNAMTB( 911)
     *        /40000   ,     'LPRINT'/
C          NAMTBL ENTRY FOR ENDARC
      DATA NAMTBL( 915),   CNAMTB( 915)
     *        /35100   ,     'ENDARC'/
C          NAMTBL ENTRY FOR ENDMDI
      DATA NAMTBL( 927),   CNAMTB( 927)
     *        /40000   ,     'ENDMDI'/
C          NAMTBL ENTRY FOR CHKSRF
      DATA NAMTBL( 928),   CNAMTB( 928)
     *        /40064   ,     'CHKSRF'/
C          NAMTBL ENTRY FOR OBTAIN
      DATA NAMTBL( 929),   CNAMTB( 929)
     *        /46000   ,     'OBTAIN'/
C          NAMTBL ENTRY FOR ZAXIS 
      DATA NAMTBL( 931),   CNAMTB( 931)
     *        /35100   ,     'ZAXIS '/
C          NAMTBL ENTRY FOR OUTTOL
      DATA NAMTBL( 932),   CNAMTB( 932)
     *        /40029   ,     'OUTTOL'/
C          NAMTBL ENTRY FOR INVERS
      DATA NAMTBL( 941),   CNAMTB( 941)
     *        /35035   ,     'INVERS'/
C          NAMTBL ENTRY FOR COUPLE
      DATA NAMTBL( 946),   CNAMTB( 946)
     *        /40000   ,     'COUPLE'/
C          NAMTBL ENTRY FOR PARAB 
      DATA NAMTBL( 947),   CNAMTB( 947)
     *        /35100   ,     'PARAB '/
C          NAMTBL ENTRY FOR PARAM 
      DATA NAMTBL( 948),   CNAMTB( 948)
     *        /35144   ,     'PARAM '/
C          NAMTBL ENTRY FOR PARLEL
      DATA NAMTBL( 958),   CNAMTB( 958)
     *        /35012   ,     'PARLEL'/
C          NAMTBL ENTRY FOR PARMF 
      DATA NAMTBL( 959),   CNAMTB( 959)
     *        /18245   ,     'PARMF '/
C          NAMTBL ENTRY FOR DRAFT 
      DATA NAMTBL( 960),   CNAMTB( 960)
     *        /40000   ,     'DRAFT '/
C          NAMTBL ENTRY FOR ALL   
      DATA NAMTBL( 964),   CNAMTB( 964)
     *        /35050   ,     'ALL   '/
C          NAMTBL ENTRY FOR PARSRF
      DATA NAMTBL( 965),   CNAMTB( 965)
     *        /39015   ,     'PARSRF'/
C          NAMTBL ENTRY FOR PART  
      DATA NAMTBL( 966),   CNAMTB( 966)
     *        /35100   ,     'PART  '/
C          NAMTBL ENTRY FOR FEED  
      DATA NAMTBL( 967),   CNAMTB( 967)
     *        /35163   ,     'FEED  '/
C          NAMTBL ENTRY FOR PARTNO
      DATA NAMTBL( 968),   CNAMTB( 968)
     *        /40000   ,     'PARTNO'/
C          NAMTBL ENTRY FOR PLUNGE
      DATA NAMTBL( 974),   CNAMTB( 974)
     *        /40000   ,     'PLUNGE'/
C          NAMTBL ENTRY FOR DRAWLI
      DATA NAMTBL( 977),   CNAMTB( 977)
     *        /40000   ,     'DRAWLI'/
C          NAMTBL ENTRY FOR PLUS  
      DATA NAMTBL( 979),   CNAMTB( 979)
     *        /35042   ,     'PLUS  '/
C          NAMTBL ENTRY FOR NUMF  
      DATA NAMTBL( 980),   CNAMTB( 980)
     *        /18210   ,     'NUMF  '/
C          NAMTBL ENTRY FOR TERMAC
      DATA NAMTBL( 987),   CNAMTB( 987)
     *        /37000   ,     'TERMAC'/
C          NAMTBL ENTRY FOR NUMPTS
      DATA NAMTBL( 990),   CNAMTB( 990)
     *        /40032   ,     'NUMPTS'/
C          NAMTBL ENTRY FOR PSTAN 
      DATA NAMTBL( 997),   CNAMTB( 997)
     *        /35004   ,     'PSTAN '/
C          NAMTBL ENTRY FOR TANB  
      DATA NAMTBL( 998),   CNAMTB( 998)
     *        /18229   ,     'TANB  '/
C          NAMTBL ENTRY FOR FLOOD 
      DATA NAMTBL( 999),   CNAMTB( 999)
     *        /35100   ,     'FLOOD '/
C          NAMTBL ENTRY FOR TANF  
      DATA NAMTBL(1002),   CNAMTB(1002)
     *        /18222   ,     'TANF  '/
C          NAMTBL ENTRY FOR TANHF 
      DATA NAMTBL(1004),   CNAMTB(1004)
     *        /18237   ,     'TANHF '/
C          NAMTBL ENTRY FOR FLOW  
      DATA NAMTBL(1007),   CNAMTB(1007)
     *        /35149   ,     'FLOW  '/
C          NAMTBL ENTRY FOR TANON 
      DATA NAMTBL(1011),   CNAMTB(1011)
     *        /35100   ,     'TANON '/
C          NAMTBL ENTRY FOR TANSPL
      DATA NAMTBL(1015),   CNAMTB(1015)
     *        /35136   ,     'TANSPL'/
C          NAMTBL ENTRY FOR TANTO 
      DATA NAMTBL(1016),   CNAMTB(1016)
     *        /35147   ,     'TANTO '/
C          NAMTBL ENTRY FOR GOFWD 
      DATA NAMTBL(1017),   CNAMTB(1017)
     *        /40034   ,     'GOFWD '/
C          NAMTBL ENTRY FOR PSIS  
      DATA NAMTBL(1029),   CNAMTB(1029)
     *        /19041   ,     'PSIS  '/
C          NAMTBL ENTRY FOR SIDE  
      DATA NAMTBL(1033),   CNAMTB(1033)
     *        /35100   ,     'SIDE  '/
C          NAMTBL ENTRY FOR .GE   
      DATA NAMTBL(1038),   CNAMTB(1038)
     *        /27003   ,     '.GE   '/
C          NAMTBL ENTRY FOR FOURPT
      DATA NAMTBL(1046),   CNAMTB(1046)
     *        /35100   ,     'FOURPT'/
C          NAMTBL ENTRY FOR RED   
      DATA NAMTBL(1066),   CNAMTB(1066)
     *        /35100   ,     'RED   '/
C          NAMTBL ENTRY FOR TOLER 
      DATA NAMTBL(1073),   CNAMTB(1073)
     *        /40027   ,     'TOLER '/
C          NAMTBL ENTRY FOR NOX   
      DATA NAMTBL(1082),   CNAMTB(1082)
     *        /35023   ,     'NOX   '/
C          NAMTBL ENTRY FOR YZROT 
      DATA NAMTBL(1085),   CNAMTB(1085)
     *        /35037   ,     'YZROT '/
C          NAMTBL ENTRY FOR TO    
      DATA NAMTBL(1092),   CNAMTB(1092)
     *        /35003   ,     'TO    '/
C          NAMTBL ENTRY FOR DEBUGG
      DATA NAMTBL(1093),   CNAMTB(1093)
     *        /40000   ,     'DEBUGG'/
C          NAMTBL ENTRY FOR CAM   
      DATA NAMTBL(1096),   CNAMTB(1096)
     *        /35100   ,     'CAM   '/
C          NAMTBL ENTRY FOR SSTEST
      DATA NAMTBL(1099),   CNAMTB(1099)
     *        /35130   ,     'SSTEST'/
C          NAMTBL ENTRY FOR .NOT  
      DATA NAMTBL(1112),   CNAMTB(1112)
     *        /28000   ,     '.NOT  '/
C          NAMTBL ENTRY FOR CAXIS 
      DATA NAMTBL(1123),   CNAMTB(1123)
     *        /35100   ,     'CAXIS '/
C          NAMTBL ENTRY FOR ANTSPI
      DATA NAMTBL(1125),   CNAMTB(1125)
     *        /35100   ,     'ANTSPI'/
C          NAMTBL ENTRY FOR LITE  
      DATA NAMTBL(1127),   CNAMTB(1127)
     *        /35100   ,     'LITE  '/
C          NAMTBL ENTRY FOR CAMERA
      DATA NAMTBL(1133),   CNAMTB(1133)
     *        /40000   ,     'CAMERA'/
C          NAMTBL ENTRY FOR NOMORE
      DATA NAMTBL(1143),   CNAMTB(1143)
     *        /35100   ,     'NOMORE'/
C          NAMTBL ENTRY FOR BINARY
      DATA NAMTBL(1147),   CNAMTB(1147)
     *        /35100   ,     'BINARY'/
C          NAMTBL ENTRY FOR NOBND 
      DATA NAMTBL(1156),   CNAMTB(1156)
     *        /35100   ,     'NOBND '/
C          NAMTBL ENTRY FOR CLEARS
      DATA NAMTBL(1157),   CNAMTB(1157)
     *        /35157   ,     'CLEARS'/
C          NAMTBL ENTRY FOR CLEARP
      DATA NAMTBL(1158),   CNAMTB(1158)
     *        /40000   ,     'CLEARP'/
C          NAMTBL ENTRY FOR CLPRNT
      DATA NAMTBL(1160),   CNAMTB(1160)
     *        /19014   ,     'CLPRNT'/
C          NAMTBL ENTRY FOR BINORM
      DATA NAMTBL(1161),   CNAMTB(1161)
     *        /35145   ,     'BINORM'/
C          NAMTBL ENTRY FOR AIR   
      DATA NAMTBL(1162),   CNAMTB(1162)
     *        /40000   ,     'AIR   '/
C          NAMTBL ENTRY FOR ABSF  
      DATA NAMTBL(1164),   CNAMTB(1164)
     *        /18181   ,     'ABSF  '/
C          NAMTBL ENTRY FOR ROTABL
      DATA NAMTBL(1165),   CNAMTB(1165)
     *        /40000   ,     'ROTABL'/
C          NAMTBL ENTRY FOR ZXROT 
      DATA NAMTBL(1169),   CNAMTB(1169)
     *        /35048   ,     'ZXROT '/
C          NAMTBL ENTRY FOR ROTHED
      DATA NAMTBL(1172),   CNAMTB(1172)
     *        /40000   ,     'ROTHED'/
C          NAMTBL ENTRY FOR ROTREF
      DATA NAMTBL(1182),   CNAMTB(1182)
     *        /35100   ,     'ROTREF'/
C          NAMTBL ENTRY FOR SCON  
      DATA NAMTBL(1183),   CNAMTB(1183)
     *        /40059   ,     'SCON  '/
C          NAMTBL ENTRY FOR ZERO  
      DATA NAMTBL(1185),   CNAMTB(1185)
     *        /40000   ,     'ZERO  '/
C          NAMTBL ENTRY FOR QADRIC
      DATA NAMTBL(1186),   CNAMTB(1186)
     *        /39014   ,     'QADRIC'/
C          NAMTBL ENTRY FOR PTSLOP
      DATA NAMTBL(1198),   CNAMTB(1198)
     *        /35100   ,     'PTSLOP'/
C          NAMTBL ENTRY FOR OBJECT
      DATA NAMTBL(1203),   CNAMTB(1203)
     *        /39028   ,     'OBJECT'/
C          NAMTBL ENTRY FOR DNTCUT
      DATA NAMTBL(1207),   CNAMTB(1207)
     *        /40010   ,     'DNTCUT'/
C          NAMTBL ENTRY FOR PAST  
      DATA NAMTBL(1222),   CNAMTB(1222)
     *        /35003   ,     'PAST  '/
C          NAMTBL ENTRY FOR PPOPTN
      DATA NAMTBL(1224),   CNAMTB(1224)
     *        /40055   ,     'PPOPTN'/
C          NAMTBL ENTRY FOR IN    
      DATA NAMTBL(1230),   CNAMTB(1230)
     *        /35020   ,     'IN    '/
C          NAMTBL ENTRY FOR GORGT 
      DATA NAMTBL(1243),   CNAMTB(1243)
     *        /40034   ,     'GORGT '/
C          NAMTBL ENTRY FOR OPSKIP
      DATA NAMTBL(1267),   CNAMTB(1267)
     *        /40000   ,     'OPSKIP'/
C          NAMTBL ENTRY FOR 3DCALC
      DATA NAMTBL(1271),   CNAMTB(1271)
     *        /40052   ,     '3DCALC'/
C          NAMTBL ENTRY FOR TLRGT 
      DATA NAMTBL(1273),   CNAMTB(1273)
     *        /40002   ,     'TLRGT '/
C          NAMTBL ENTRY FOR SMIL  
      DATA NAMTBL(1274),   CNAMTB(1274)
     *        /40060   ,     'SMIL  '/
C          NAMTBL ENTRY FOR OPSTOP
      DATA NAMTBL(1276),   CNAMTB(1276)
     *        /40000   ,     'OPSTOP'/
C          NAMTBL ENTRY FOR NIXIE 
      DATA NAMTBL(1277),   CNAMTB(1277)
     *        /35100   ,     'NIXIE '/
C          NAMTBL ENTRY FOR VCONST
      DATA NAMTBL(1280),   CNAMTB(1280)
     *        /35170   ,     'VCONST'/
C          NAMTBL ENTRY FOR SELCTL
      DATA NAMTBL(1295),   CNAMTB(1295)
     *        /40000   ,     'SELCTL'/
C          NAMTBL ENTRY FOR ASLOPE
      DATA NAMTBL(1303),   CNAMTB(1303)
     *        /40000   ,     'ASLOPE'/
C          NAMTBL ENTRY FOR .NE   
      DATA NAMTBL(1330),   CNAMTB(1330)
     *        /27002   ,     '.NE   '/
C          NAMTBL ENTRY FOR ARC   
      DATA NAMTBL(1336),   CNAMTB(1336)
     *        /35067   ,     'ARC   '/
C          NAMTBL ENTRY FOR NOY   
      DATA NAMTBL(1338),   CNAMTB(1338)
     *        /35024   ,     'NOY   '/
C          NAMTBL ENTRY FOR DECR  
      DATA NAMTBL(1346),   CNAMTB(1346)
     *        /35060   ,     'DECR  '/
C          NAMTBL ENTRY FOR XSMALL
      DATA NAMTBL(1353),   CNAMTB(1353)
     *        /35045   ,     'XSMALL'/
C          NAMTBL ENTRY FOR SSURF 
      DATA NAMTBL(1368),   CNAMTB(1368)
     *        /43029   ,     'SSURF '/
C          NAMTBL ENTRY FOR MATRIX
      DATA NAMTBL(1378),   CNAMTB(1378)
     *        /39018   ,     'MATRIX'/
C          NAMTBL ENTRY FOR YCOORD
      DATA NAMTBL(1379),   CNAMTB(1379)
     *        /35100   ,     'YCOORD'/
C          NAMTBL ENTRY FOR ARCOSF
      DATA NAMTBL(1383),   CNAMTB(1383)
     *        /18226   ,     'ARCOSF'/
C          NAMTBL ENTRY FOR ARCOSB
      DATA NAMTBL(1384),   CNAMTB(1384)
     *        /18232   ,     'ARCOSB'/
C          NAMTBL ENTRY FOR TV    
      DATA NAMTBL(1385),   CNAMTB(1385)
     *        /35183   ,     'TV    '/
C          NAMTBL ENTRY FOR TVAL  
      DATA NAMTBL(1386),   CNAMTB(1386)
     *        /35069   ,     'TVAL  '/
C          NAMTBL ENTRY FOR ARCSLP
      DATA NAMTBL(1387),   CNAMTB(1387)
     *        /40000   ,     'ARCSLP'/
C          NAMTBL ENTRY FOR MAIN  
      DATA NAMTBL(1388),   CNAMTB(1388)
     *        /35100   ,     'MAIN  '/
C          NAMTBL ENTRY FOR CANF  
      DATA NAMTBL(1390),   CNAMTB(1390)
     *        /18246   ,     'CANF  '/
C          NAMTBL ENTRY FOR DWELL 
      DATA NAMTBL(1391),   CNAMTB(1391)
     *        /40000   ,     'DWELL '/
C          NAMTBL ENTRY FOR CANON 
      DATA NAMTBL(1399),   CNAMTB(1399)
     *        /42000   ,     'CANON '/
C          NAMTBL ENTRY FOR RLDSRF
      DATA NAMTBL(1409),   CNAMTB(1409)
     *        /39012   ,     'RLDSRF'/
C          NAMTBL ENTRY FOR DS    
      DATA NAMTBL(1410),   CNAMTB(1410)
     *        /35001   ,     'DS    '/
C          NAMTBL ENTRY FOR NOCLRP
      DATA NAMTBL(1411),   CNAMTB(1411)
     *        /35100   ,     'NOCLRP'/
C          NAMTBL ENTRY FOR FULL  
      DATA NAMTBL(1412),   CNAMTB(1412)
     *        /35100   ,     'FULL  '/
C          NAMTBL ENTRY FOR AUTO  
      DATA NAMTBL(1413),   CNAMTB(1413)
     *        /35098   ,     'AUTO  '/
C          NAMTBL ENTRY FOR AUTOPS
      DATA NAMTBL(1414),   CNAMTB(1414)
     *        /40008   ,     'AUTOPS'/
C          NAMTBL ENTRY FOR GENCUR
      DATA NAMTBL(1415),   CNAMTB(1415)
     *        /35148   ,     'GENCUR'/
C          NAMTBL ENTRY FOR ON    
      DATA NAMTBL(1426),   CNAMTB(1426)
     *        /35003   ,     'ON    '/
C          NAMTBL ENTRY FOR TUNEUP
      DATA NAMTBL(1431),   CNAMTB(1431)
     *        /40056   ,     'TUNEUP'/
C          NAMTBL ENTRY FOR LEFT  
      DATA NAMTBL(1434),   CNAMTB(1434)
     *        /35032   ,     'LEFT  '/
C          NAMTBL ENTRY FOR .LT   
      DATA NAMTBL(1448),   CNAMTB(1448)
     *        /27006   ,     '.LT   '/
C          NAMTBL ENTRY FOR BLUE  
      DATA NAMTBL(1451),   CNAMTB(1451)
     *        /35100   ,     'BLUE  '/
C          NAMTBL ENTRY FOR PATCH 
      DATA NAMTBL(1461),   CNAMTB(1461)
     *        /35131   ,     'PATCH '/
C          NAMTBL ENTRY FOR PATERN
      DATA NAMTBL(1463),   CNAMTB(1463)
     *        /43026   ,     'PATERN'/
C          NAMTBL ENTRY FOR PATH  
      DATA NAMTBL(1466),   CNAMTB(1466)
     *        /35165   ,     'PATH  '/
C          NAMTBL ENTRY FOR COLLET
      DATA NAMTBL(1468),   CNAMTB(1468)
     *        /35100   ,     'COLLET'/
C          NAMTBL ENTRY FOR TAP   
      DATA NAMTBL(1476),   CNAMTB(1476)
     *        /35100   ,     'TAP   '/
C          NAMTBL ENTRY FOR ULOCKX
      DATA NAMTBL(1477),   CNAMTB(1477)
     *        /40000   ,     'ULOCKX'/
C          NAMTBL ENTRY FOR TIMES 
      DATA NAMTBL(1483),   CNAMTB(1483)
     *        /35039   ,     'TIMES '/
C          NAMTBL ENTRY FOR RGMXXX
      DATA NAMTBL(1488),   CNAMTB(1488)
     *        /39050   ,     'RGMXXX'/
C          NAMTBL ENTRY FOR FACE  
      DATA NAMTBL(1501),   CNAMTB(1501)
     *        /35100   ,     'FACE  '/
C          NAMTBL ENTRY FOR FACEML
      DATA NAMTBL(1502),   CNAMTB(1502)
     *        /40000   ,     'FACEML'/
C          NAMTBL ENTRY FOR PLABEL
      DATA NAMTBL(1503),   CNAMTB(1503)
     *        /40000   ,     'PLABEL'/
C          NAMTBL ENTRY FOR PLANO 
      DATA NAMTBL(1514),   CNAMTB(1514)
     *        /35168   ,     'PLANO '/
C          NAMTBL ENTRY FOR PLANE 
      DATA NAMTBL(1515),   CNAMTB(1515)
     *        /39002   ,     'PLANE '/
C          NAMTBL ENTRY FOR TAPKUL
      DATA NAMTBL(1519),   CNAMTB(1519)
     *        /35100   ,     'TAPKUL'/
C          NAMTBL ENTRY FOR OPTION
      DATA NAMTBL(1521),   CNAMTB(1521)
     *        /35100   ,     'OPTION'/
C          NAMTBL ENTRY FOR GOHOME
      DATA NAMTBL(1522),   CNAMTB(1522)
     *        /40000   ,     'GOHOME'/
C          NAMTBL ENTRY FOR BCD   
      DATA NAMTBL(1538),   CNAMTB(1538)
     *        /35100   ,     'BCD   '/
C          NAMTBL ENTRY FOR TP    
      DATA NAMTBL(1539),   CNAMTB(1539)
     *        /35181   ,     'TP    '/
C          NAMTBL ENTRY FOR DISPLY
      DATA NAMTBL(1564),   CNAMTB(1564)
     *        /40000   ,     'DISPLY'/
C          NAMTBL ENTRY FOR DISTF 
      DATA NAMTBL(1568),   CNAMTB(1568)
     *        /18220   ,     'DISTF '/
C          NAMTBL ENTRY FOR 5PT   
      DATA NAMTBL(1574),   CNAMTB(1574)
     *        /35051   ,     '5PT   '/
C          NAMTBL ENTRY FOR NOZ   
      DATA NAMTBL(1594),   CNAMTB(1594)
     *        /35025   ,     'NOZ   '/
C          NAMTBL ENTRY FOR MIRROR
      DATA NAMTBL(1604),   CNAMTB(1604)
     *        /35029   ,     'MIRROR'/
C          NAMTBL ENTRY FOR WEIGHT
      DATA NAMTBL(1605),   CNAMTB(1605)
     *        /35138   ,     'WEIGHT'/
C          NAMTBL ENTRY FOR UNLOAD
      DATA NAMTBL(1613),   CNAMTB(1613)
     *        /40000   ,     'UNLOAD'/
C          NAMTBL ENTRY FOR PNTSON
      DATA NAMTBL(1615),   CNAMTB(1615)
     *        /35135   ,     'PNTSON'/
C          NAMTBL ENTRY FOR PBS   
      DATA NAMTBL(1616),   CNAMTB(1616)
     *        /40000   ,     'PBS   '/
C          NAMTBL ENTRY FOR PNTVEC
      DATA NAMTBL(1618),   CNAMTB(1618)
     *        /35133   ,     'PNTVEC'/
C          NAMTBL ENTRY FOR REFSYS
      DATA NAMTBL(1629),   CNAMTB(1629)
     *        /19017   ,     'REFSYS'/
C          NAMTBL ENTRY FOR DOTF  
      DATA NAMTBL(1656),   CNAMTB(1656)
     *        /18186   ,     'DOTF  '/
C          NAMTBL ENTRY FOR GMLXXX
      DATA NAMTBL(1662),   CNAMTB(1662)
     *        /39047   ,     'GMLXXX'/
C          NAMTBL ENTRY FOR XYZ   
      DATA NAMTBL(1664),   CNAMTB(1664)
     *        /35028   ,     'XYZ   '/
C          NAMTBL ENTRY FOR DOTTED
      DATA NAMTBL(1670),   CNAMTB(1670)
     *        /35100   ,     'DOTTED'/
C          NAMTBL ENTRY FOR CLRSRF
      DATA NAMTBL(1673),   CNAMTB(1673)
     *        /40000   ,     'CLRSRF'/
C          NAMTBL ENTRY FOR PEN   
      DATA NAMTBL(1674),   CNAMTB(1674)
     *        /35100   ,     'PEN   '/
C          NAMTBL ENTRY FOR CLRXXX
      DATA NAMTBL(1678),   CNAMTB(1678)
     *        /39046   ,     'CLRXXX'/
C          NAMTBL ENTRY FOR GEOM  
      DATA NAMTBL(1681),   CNAMTB(1681)
     *        /35127   ,     'GEOM  '/
C          NAMTBL ENTRY FOR MDEND 
      DATA NAMTBL(1702),   CNAMTB(1702)
     *        /40000   ,     'MDEND '/
C          NAMTBL ENTRY FOR LOW   
      DATA NAMTBL(1704),   CNAMTB(1704)
     *        /35100   ,     'LOW   '/
C          NAMTBL ENTRY FOR PENDWN
      DATA NAMTBL(1710),   CNAMTB(1710)
     *        /40000   ,     'PENDWN'/
C          NAMTBL ENTRY FOR COMBIN
      DATA NAMTBL(1714),   CNAMTB(1714)
     *        /35141   ,     'COMBIN'/
C          NAMTBL ENTRY FOR .TRUE 
      DATA NAMTBL(1727),   CNAMTB(1727)
     *        /27000   ,     '.TRUE '/
C          NAMTBL ENTRY FOR PENUP 
      DATA NAMTBL(1728),   CNAMTB(1728)
     *        /40000   ,     'PENUP '/
C          NAMTBL ENTRY FOR WRTMDI
      DATA NAMTBL(1735),   CNAMTB(1735)
     *        /40000   ,     'WRTMDI'/
C          NAMTBL ENTRY FOR DYNDMP
      DATA NAMTBL(1748),   CNAMTB(1748)
     *        /40022   ,     'DYNDMP'/
C          NAMTBL ENTRY FOR INCR  
      DATA NAMTBL(1750),   CNAMTB(1750)
     *        /35057   ,     'INCR  '/
C          NAMTBL ENTRY FOR AT    
      DATA NAMTBL(1758),   CNAMTB(1758)
     *        /35066   ,     'AT    '/
C          NAMTBL ENTRY FOR ATANF 
      DATA NAMTBL(1762),   CNAMTB(1762)
     *        /18182   ,     'ATANF '/
C          NAMTBL ENTRY FOR ATAN2F
      DATA NAMTBL(1763),   CNAMTB(1763)
     *        /18223   ,     'ATAN2F'/
C          NAMTBL ENTRY FOR ATANB 
      DATA NAMTBL(1764),   CNAMTB(1764)
     *        /18233   ,     'ATANB '/
C          NAMTBL ENTRY FOR ATAN2B
      DATA NAMTBL(1765),   CNAMTB(1765)
     *        /18234   ,     'ATAN2B'/
C          NAMTBL ENTRY FOR ATANGL
      DATA NAMTBL(1766),   CNAMTB(1766)
     *        /35010   ,     'ATANGL'/
C          NAMTBL ENTRY FOR GOTO  
      DATA NAMTBL(1767),   CNAMTB(1767)
     *        /40035   ,     'GOTO  '/
C          NAMTBL ENTRY FOR LOADTL
      DATA NAMTBL(1768),   CNAMTB(1768)
     *        /40000   ,     'LOADTL'/
C          NAMTBL ENTRY FOR CRSSPL
      DATA NAMTBL(1775),   CNAMTB(1775)
     *        /35137   ,     'CRSSPL'/
C          NAMTBL ENTRY FOR CCLW  
      DATA NAMTBL(1787),   CNAMTB(1787)
     *        /35059   ,     'CCLW  '/
C          NAMTBL ENTRY FOR RULED 
      DATA NAMTBL(1797),   CNAMTB(1797)
     *        /35143   ,     'RULED '/
C          NAMTBL ENTRY FOR POSMAP
      DATA NAMTBL(1799),   CNAMTB(1799)
     *        /40000   ,     'POSMAP'/
C          NAMTBL ENTRY FOR POSN  
      DATA NAMTBL(1800),   CNAMTB(1800)
     *        /35164   ,     'POSN  '/
C          NAMTBL ENTRY FOR PS    
      DATA NAMTBL(1802),   CNAMTB(1802)
     *        /35001   ,     'PS    '/
C          NAMTBL ENTRY FOR POSTN 
      DATA NAMTBL(1806),   CNAMTB(1806)
     *        /40000   ,     'POSTN '/
C          NAMTBL ENTRY FOR XAXIS 
      DATA NAMTBL(1809),   CNAMTB(1809)
     *        /35007   ,     'XAXIS '/
C          NAMTBL ENTRY FOR SIGNF 
      DATA NAMTBL(1810),   CNAMTB(1810)
     *        /18242   ,     'SIGNF '/
C          NAMTBL ENTRY FOR POSX  
      DATA NAMTBL(1811),   CNAMTB(1811)
     *        /35014   ,     'POSX  '/
C          NAMTBL ENTRY FOR POSZ  
      DATA NAMTBL(1812),   CNAMTB(1812)
     *        /35016   ,     'POSZ  '/
C          NAMTBL ENTRY FOR POSY  
      DATA NAMTBL(1813),   CNAMTB(1813)
     *        /35038   ,     'POSY  '/
C          NAMTBL ENTRY FOR YLARGE
      DATA NAMTBL(1814),   CNAMTB(1814)
     *        /35038   ,     'YLARGE'/
C          NAMTBL ENTRY FOR DITTO 
      DATA NAMTBL(1824),   CNAMTB(1824)
     *        /35100   ,     'DITTO '/
C          NAMTBL ENTRY FOR THETAR
      DATA NAMTBL(1834),   CNAMTB(1834)
     *        /35027   ,     'THETAR'/
C          NAMTBL ENTRY FOR MED   
      DATA NAMTBL(1846),   CNAMTB(1846)
     *        /35100   ,     'MED   '/
C          NAMTBL ENTRY FOR TOOL  
      DATA NAMTBL(1848),   CNAMTB(1848)
     *        /39017   ,     'TOOL  '/
C          NAMTBL ENTRY FOR TOOLNO
      DATA NAMTBL(1849),   CNAMTB(1849)
     *        /40000   ,     'TOOLNO'/
C          NAMTBL ENTRY FOR DEEP  
      DATA NAMTBL(1856),   CNAMTB(1856)
     *        /35100   ,     'DEEP  '/
C          NAMTBL ENTRY FOR MIST  
      DATA NAMTBL(1862),   CNAMTB(1862)
     *        /35100   ,     'MIST  '/
C          NAMTBL ENTRY FOR REGBRK
      DATA NAMTBL(1868),   CNAMTB(1868)
     *        /40000   ,     'REGBRK'/
C          NAMTBL ENTRY FOR REGION
      DATA NAMTBL(1875),   CNAMTB(1875)
     *        /40066   ,     'REGION'/
C          NAMTBL ENTRY FOR RANDOM
      DATA NAMTBL(1878),   CNAMTB(1878)
     *        /35056   ,     'RANDOM'/
C          NAMTBL ENTRY FOR RANGE 
      DATA NAMTBL(1881),   CNAMTB(1881)
     *        /35075   ,     'RANGE '/
C          NAMTBL ENTRY FOR REGTOL
      DATA NAMTBL(1886),   CNAMTB(1886)
     *        /35100   ,     'REGTOL'/
C          NAMTBL ENTRY FOR MEDIUM
      DATA NAMTBL(1887),   CNAMTB(1887)
     *        /35100   ,     'MEDIUM'/
C          NAMTBL ENTRY FOR HEAD  
      DATA NAMTBL(1894),   CNAMTB(1894)
     *        /40000   ,     'HEAD  '/
C          NAMTBL ENTRY FOR NOPOST
      DATA NAMTBL(1911),   CNAMTB(1911)
     *        /40047   ,     'NOPOST'/
C          NAMTBL ENTRY FOR NOPS  
      DATA NAMTBL(1915),   CNAMTB(1915)
     *        /40007   ,     'NOPS  '/
C          NAMTBL ENTRY FOR OFF   
      DATA NAMTBL(1926),   CNAMTB(1926)
     *        /35050   ,     'OFF   '/
C          NAMTBL ENTRY FOR FUNOFY
      DATA NAMTBL(1927),   CNAMTB(1927)
     *        /35022   ,     'FUNOFY'/
C          NAMTBL ENTRY FOR VECTOR
      DATA NAMTBL(1936),   CNAMTB(1936)
     *        /39020   ,     'VECTOR'/
C          NAMTBL ENTRY FOR SCRIBE
      DATA NAMTBL(1945),   CNAMTB(1945)
     *        /35100   ,     'SCRIBE'/
C          NAMTBL ENTRY FOR MOTDIR
      DATA NAMTBL(1948),   CNAMTB(1948)
     *        /35094   ,     'MOTDIR'/
C          NAMTBL ENTRY FOR CHORD 
      DATA NAMTBL(1950),   CNAMTB(1950)
     *        /35154   ,     'CHORD '/
C          NAMTBL ENTRY FOR CHDPT 
      DATA NAMTBL(1962),   CNAMTB(1962)
     *        /35172   ,     'CHDPT '/
C          NAMTBL ENTRY FOR SFM   
      DATA NAMTBL(1963),   CNAMTB(1963)
     *        /40000   ,     'SFM   '/
C          NAMTBL ENTRY FOR CONE  
      DATA NAMTBL(1973),   CNAMTB(1973)
     *        /39009   ,     'CONE  '/
C          NAMTBL ENTRY FOR OFFSET
      DATA NAMTBL(1977),   CNAMTB(1977)
     *        /40025   ,     'OFFSET'/
C          NAMTBL ENTRY FOR XYPLAN
      DATA NAMTBL(1978),   CNAMTB(1978)
     *        /35034   ,     'XYPLAN'/
C          NAMTBL ENTRY FOR PPRINT
      DATA NAMTBL(1985),   CNAMTB(1985)
     *        /40000   ,     'PPRINT'/
C          NAMTBL ENTRY FOR CONST 
      DATA NAMTBL(1987),   CNAMTB(1987)
     *        /35074   ,     'CONST '/
C          NAMTBL ENTRY FOR CONTRL
      DATA NAMTBL(1988),   CNAMTB(1988)
     *        /19020   ,     'CONTRL'/
C          NAMTBL ENTRY FOR CONTIN
      DATA NAMTBL(1989),   CNAMTB(1989)
     *        /19045   ,     'CONTIN'/
C          NAMTBL ENTRY FOR BLACK 
      DATA NAMTBL(1990),   CNAMTB(1990)
     *        /35100   ,     'BLACK '/
C          NAMTBL ENTRY FOR INDEX 
      DATA NAMTBL(1993),   CNAMTB(1993)
     *        /40000   ,     'INDEX '/
C          NAMTBL ENTRY FOR DRESS 
      DATA NAMTBL(1997),   CNAMTB(1997)
     *        /40000   ,     'DRESS '/
C          NAMTBL ENTRY FOR INDIRV
      DATA NAMTBL(1998),   CNAMTB(1998)
     *        /40037   ,     'INDIRV'/
C          NAMTBL ENTRY FOR INDIRP
      DATA NAMTBL(1999),   CNAMTB(1999)
     *        /40040   ,     'INDIRP'/
C          NAMTBL ENTRY FOR AAXIS 
      DATA NAMTBL(2001),   CNAMTB(2001)
     *        /35100   ,     'AAXIS '/
C          NAMTBL ENTRY FOR GOUGCK
      DATA NAMTBL(2011),   CNAMTB(2011)
     *        /40013   ,     'GOUGCK'/
C          NAMTBL ENTRY FOR APTRAN
      DATA NAMTBL(2016),   CNAMTB(2016)
     *        /19015   ,     'APTRAN'/
C          NAMTBL ENTRY FOR APTREN
      DATA NAMTBL(2017),   CNAMTB(2017)
     *        /19016   ,     'APTREN'/
C          NAMTBL ENTRY FOR MCHFIN
      DATA NAMTBL(2018),   CNAMTB(2018)
     *        /40000   ,     'MCHFIN'/
C          NAMTBL ENTRY FOR IFRO  
      DATA NAMTBL(2019),   CNAMTB(2019)
     *        /40000   ,     'IFRO  '/
C          NAMTBL ENTRY FOR GOUP  
      DATA NAMTBL(2020),   CNAMTB(2020)
     *        /40034   ,     'GOUP  '/
C          NAMTBL ENTRY FOR BORE  
      DATA NAMTBL(2021),   CNAMTB(2021)
     *        /35100   ,     'BORE  '/
C          NAMTBL ENTRY FOR MCHTOL
      DATA NAMTBL(2030),   CNAMTB(2030)
     *        /40000   ,     'MCHTOL'/
C          NAMTBL ENTRY FOR .GT   
      DATA NAMTBL(2048),   CNAMTB(2048)
     *        /27005   ,     '.GT   '/
C          NAMTBL ENTRY FOR SMALL 
      DATA NAMTBL(2056),   CNAMTB(2056)
     *        /35049   ,     'SMALL '/
C          NAMTBL ENTRY FOR CFSAVE
      DATA NAMTBL(2065),   CNAMTB(2065)
     *        /40054   ,     'CFSAVE'/
C          NAMTBL ENTRY FOR POINT 
      DATA NAMTBL(2070),   CNAMTB(2070)
     *        /39019   ,     'POINT '/
C          NAMTBL ENTRY FOR ELLIPS
      DATA NAMTBL(2079),   CNAMTB(2079)
     *        /39008   ,     'ELLIPS'/
C          NAMTBL ENTRY FOR GREEN 
      DATA NAMTBL(2081),   CNAMTB(2081)
     *        /35100   ,     'GREEN '/
C          NAMTBL ENTRY FOR SAVMDI
      DATA NAMTBL(2082),   CNAMTB(2082)
     *        /35180   ,     'SAVMDI'/
C          NAMTBL ENTRY FOR HEX   
      DATA NAMTBL(2086),   CNAMTB(2086)
     *        /35072   ,     'HEX   '/
C          NAMTBL ENTRY FOR SAVTDI
      DATA NAMTBL(2088),   CNAMTB(2088)
     *        /35180   ,     'SAVTDI'/
C          NAMTBL ENTRY FOR PROBX 
      DATA NAMTBL(2102),   CNAMTB(2102)
     *        /40000   ,     'PROBX '/
C          NAMTBL ENTRY FOR YZVIEW
      DATA NAMTBL(2103),   CNAMTB(2103)
     *        /35100   ,     'YZVIEW'/
C          NAMTBL ENTRY FOR PROBY 
      DATA NAMTBL(2104),   CNAMTB(2104)
     *        /40000   ,     'PROBY '/
C          NAMTBL ENTRY FOR RESERV
      DATA NAMTBL(2113),   CNAMTB(2113)
     *        /19019   ,     'RESERV'/
C          NAMTBL ENTRY FOR RESET 
      DATA NAMTBL(2114),   CNAMTB(2114)
     *        /40000   ,     'RESET '/
C          NAMTBL ENTRY FOR RADIUS
      DATA NAMTBL(2153),   CNAMTB(2153)
     *        /35018   ,     'RADIUS'/
C          NAMTBL ENTRY FOR LIMIT 
      DATA NAMTBL(2169),   CNAMTB(2169)
     *        /35139   ,     'LIMIT '/
C          NAMTBL ENTRY FOR ZXVIEW
      DATA NAMTBL(2187),   CNAMTB(2187)
     *        /35100   ,     'ZXVIEW'/
C          NAMTBL ENTRY FOR LETTER
      DATA NAMTBL(2188),   CNAMTB(2188)
     *        /40000   ,     'LETTER'/
C          NAMTBL ENTRY FOR LIBPRT
      DATA NAMTBL(2190),   CNAMTB(2190)
     *        /35160   ,     'LIBPRT'/
C          NAMTBL ENTRY FOR PITCH 
      DATA NAMTBL(2199),   CNAMTB(2199)
     *        /40000   ,     'PITCH '/
C          NAMTBL ENTRY FOR PPS   
      DATA NAMTBL(2200),   CNAMTB(2200)
     *        /35186   ,     'PPS   '/
C          NAMTBL ENTRY FOR SYN   
      DATA NAMTBL(2202),   CNAMTB(2202)
     *        /19021   ,     'SYN   '/
C          NAMTBL ENTRY FOR CHECK 
      DATA NAMTBL(2205),   CNAMTB(2205)
     *        /40000   ,     'CHECK '/
C          NAMTBL ENTRY FOR EJECT 
      DATA NAMTBL(2219),   CNAMTB(2219)
     *        /19042   ,     'EJECT '/
C          NAMTBL ENTRY FOR FINI  
      DATA NAMTBL(2229),   CNAMTB(2229)
     *        /19018   ,     'FINI  '/
C          NAMTBL ENTRY FOR COOLNT
      DATA NAMTBL(2236),   CNAMTB(2236)
     *        /40000   ,     'COOLNT'/
C          NAMTBL ENTRY FOR CODEL 
      DATA NAMTBL(2243),   CNAMTB(2243)
     *        /40000   ,     'CODEL '/
C          NAMTBL ENTRY FOR WCORN 
      DATA NAMTBL(2260),   CNAMTB(2260)
     *        /40000   ,     'WCORN '/
C          NAMTBL ENTRY FOR .OR   
      DATA NAMTBL(2274),   CNAMTB(2274)
     *        /30000   ,     '.OR   '/
C          NAMTBL ENTRY FOR PLOT  
      DATA NAMTBL(2275),   CNAMTB(2275)
     *        /40000   ,     'PLOT  '/
C          NAMTBL ENTRY FOR PLOTFT
      DATA NAMTBL(2276),   CNAMTB(2276)
     *        /40060   ,     'PLOTFT'/
C          NAMTBL ENTRY FOR LOCK  
      DATA NAMTBL(2287),   CNAMTB(2287)
     *        /35100   ,     'LOCK  '/
C          NAMTBL ENTRY FOR LOCKX 
      DATA NAMTBL(2288),   CNAMTB(2288)
     *        /40000   ,     'LOCKX '/
C          NAMTBL ENTRY FOR THREAD
      DATA NAMTBL(2317),   CNAMTB(2317)
     *        /40000   ,     'THREAD'/
C          NAMTBL ENTRY FOR IPM   
      DATA NAMTBL(2322),   CNAMTB(2322)
     *        /35100   ,     'IPM   '/
C          NAMTBL ENTRY FOR YSMALL
      DATA NAMTBL(2329),   CNAMTB(2329)
     *        /35046   ,     'YSMALL'/
C          NAMTBL ENTRY FOR THRU  
      DATA NAMTBL(2333),   CNAMTB(2333)
     *        /35063   ,     'THRU  '/
C          NAMTBL ENTRY FOR NEXT  
      DATA NAMTBL(2334),   CNAMTB(2334)
     *        /35100   ,     'NEXT  '/
C          NAMTBL ENTRY FOR SPHERE
      DATA NAMTBL(2349),   CNAMTB(2349)
     *        /39005   ,     'SPHERE'/
C          NAMTBL ENTRY FOR START 
      DATA NAMTBL(2354),   CNAMTB(2354)
     *        /35070   ,     'START '/
C          NAMTBL ENTRY FOR ZCOORD
      DATA NAMTBL(2355),   CNAMTB(2355)
     *        /35100   ,     'ZCOORD'/
C          NAMTBL ENTRY FOR UVAL  
      DATA NAMTBL(2362),   CNAMTB(2362)
     *        /35069   ,     'UVAL  '/
C          NAMTBL ENTRY FOR RETAIN
      DATA NAMTBL(2365),   CNAMTB(2365)
     *        /35065   ,     'RETAIN'/
C          NAMTBL ENTRY FOR SLOPE 
      DATA NAMTBL(2368),   CNAMTB(2368)
     *        /35011   ,     'SLOPE '/
C          NAMTBL ENTRY FOR SLOWDN
      DATA NAMTBL(2375),   CNAMTB(2375)
     *        /40000   ,     'SLOWDN'/
C          NAMTBL ENTRY FOR PREFUN
      DATA NAMTBL(2376),   CNAMTB(2376)
     *        /40000   ,     'PREFUN'/
C          NAMTBL ENTRY FOR RETR  
      DATA NAMTBL(2382),   CNAMTB(2382)
     *        /35169   ,     'RETR  '/
C          NAMTBL ENTRY FOR RETRCT
      DATA NAMTBL(2383),   CNAMTB(2383)
     *        /40000   ,     'RETRCT'/
C          NAMTBL ENTRY FOR HIGHT 
      DATA NAMTBL(2388),   CNAMTB(2388)
     *        /35097   ,     'HIGHT '/
C          NAMTBL ENTRY FOR HIGH  
      DATA NAMTBL(2389),   CNAMTB(2389)
     *        /35100   ,     'HIGH  '/
C          NAMTBL ENTRY FOR MAXF  
      DATA NAMTBL(2390),   CNAMTB(2390)
     *        /18239   ,     'MAXF  '/
C          NAMTBL ENTRY FOR MAXDPM
      DATA NAMTBL(2391),   CNAMTB(2391)
     *        /40000   ,     'MAXDPM'/
C          NAMTBL ENTRY FOR MAXDP 
      DATA NAMTBL(2392),   CNAMTB(2392)
     *        /40031   ,     'MAXDP '/
C          NAMTBL ENTRY FOR MAXIPM
      DATA NAMTBL(2393),   CNAMTB(2393)
     *        /35100   ,     'MAXIPM'/
C          NAMTBL ENTRY FOR RAPID 
      DATA NAMTBL(2395),   CNAMTB(2395)
     *        /40000   ,     'RAPID '/
C          NAMTBL ENTRY FOR MAXLNG
      DATA NAMTBL(2396),   CNAMTB(2396)
     *        /35100   ,     'MAXLNG'/
C          NAMTBL ENTRY FOR MAXPTS
      DATA NAMTBL(2400),   CNAMTB(2400)
     *        /35100   ,     'MAXPTS'/
C          NAMTBL ENTRY FOR MAXRPM
      DATA NAMTBL(2402),   CNAMTB(2402)
     *        /35100   ,     'MAXRPM'/
C          NAMTBL ENTRY FOR MAXSTP
      DATA NAMTBL(2403),   CNAMTB(2403)
     *        /35156   ,     'MAXSTP'/
C          NAMTBL ENTRY FOR MAXVEL
      DATA NAMTBL(2406),   CNAMTB(2406)
     *        /40000   ,     'MAXVEL'/
C          NAMTBL ENTRY FOR MAXWD 
      DATA NAMTBL(2407),   CNAMTB(2407)
     *        /35100   ,     'MAXWD '/
C          NAMTBL ENTRY FOR LINCIR
      DATA NAMTBL(2419),   CNAMTB(2419)
     *        /35100   ,     'LINCIR'/
C          NAMTBL ENTRY FOR NORMAL
      DATA NAMTBL(2421),   CNAMTB(2421)
     *        /35013   ,     'NORMAL'/
C          NAMTBL ENTRY FOR LINEAR
      DATA NAMTBL(2422),   CNAMTB(2422)
     *        /35068   ,     'LINEAR'/
C          NAMTBL ENTRY FOR NORMDS
      DATA NAMTBL(2423),   CNAMTB(2423)
     *        /35151   ,     'NORMDS'/
C          NAMTBL ENTRY FOR NORMPS
      DATA NAMTBL(2424),   CNAMTB(2424)
     *        /35152   ,     'NORMPS'/
C          NAMTBL ENTRY FOR LINE  
      DATA NAMTBL(2425),   CNAMTB(2425)
     *        /39001   ,     'LINE  '/
C          NAMTBL ENTRY FOR ORIGIN
      DATA NAMTBL(2426),   CNAMTB(2426)
     *        /40000   ,     'ORIGIN'/
C          NAMTBL ENTRY FOR TRACUT
      DATA NAMTBL(2427),   CNAMTB(2427)
     *        /40000   ,     'TRACUT'/
C          NAMTBL ENTRY FOR AUXFUN
      DATA NAMTBL(2428),   CNAMTB(2428)
     *        /40000   ,     'AUXFUN'/
C          NAMTBL ENTRY FOR VTLAXS
      DATA NAMTBL(2429),   CNAMTB(2429)
     *        /40000   ,     'VTLAXS'/
C          NAMTBL ENTRY FOR DOWN  
      DATA NAMTBL(2432),   CNAMTB(2432)
     *        /35100   ,     'DOWN  '/
C          NAMTBL ENTRY FOR TRANSL
      DATA NAMTBL(2434),   CNAMTB(2434)
     *        /35033   ,     'TRANSL'/
C          NAMTBL ENTRY FOR TRANS 
      DATA NAMTBL(2435),   CNAMTB(2435)
     *        /40000   ,     'TRANS '/
C          NAMTBL ENTRY FOR LINTOL
      DATA NAMTBL(2436),   CNAMTB(2436)
     *        /40000   ,     'LINTOL'/
C          NAMTBL ENTRY FOR TRANTO
      DATA NAMTBL(2437),   CNAMTB(2437)
     *        /19024   ,     'TRANTO'/
C          NAMTBL ENTRY FOR .FALSE
      DATA NAMTBL(2442),   CNAMTB(2442)
     *        /27000   ,     '.FALSE'/
C          NAMTBL ENTRY FOR TRAV  
      DATA NAMTBL(2443),   CNAMTB(2443)
     *        /35100   ,     'TRAV  '/
C          NAMTBL ENTRY FOR TRAVED
      DATA NAMTBL(2444),   CNAMTB(2444)
     *        /35100   ,     'TRAVED'/
C          NAMTBL ENTRY FOR DO    
      DATA NAMTBL(2456),   CNAMTB(2456)
     *        /41002   ,     'DO    '/
C          NAMTBL ENTRY FOR MOVETO
      DATA NAMTBL(2461),   CNAMTB(2461)
     *        /40000   ,     'MOVETO'/
C          NAMTBL ENTRY FOR TURN  
      DATA NAMTBL(2464),   CNAMTB(2464)
     *        /35100   ,     'TURN  '/
C          NAMTBL ENTRY FOR TURRET
      DATA NAMTBL(2468),   CNAMTB(2468)
     *        /40000   ,     'TURRET'/
C          NAMTBL ENTRY FOR 3PT2SL
      DATA NAMTBL(2470),   CNAMTB(2470)
     *        /35053   ,     '3PT2SL'/
C          NAMTBL ENTRY FOR XYROT 
      DATA NAMTBL(2493),   CNAMTB(2493)
     *        /35034   ,     'XYROT '/
C          NAMTBL ENTRY FOR COPY  
      DATA NAMTBL(2505),   CNAMTB(2505)
     *        /40000   ,     'COPY  '/
C          NAMTBL ENTRY FOR PDS   
      DATA NAMTBL(2508),   CNAMTB(2508)
     *        /35184   ,     'PDS   '/
C          NAMTBL ENTRY FOR UP    
      DATA NAMTBL(2514),   CNAMTB(2514)
     *        /35100   ,     'UP    '/
C          NAMTBL ENTRY FOR LOOPST
      DATA NAMTBL(2534),   CNAMTB(2534)
     *        /19044   ,     'LOOPST'/
C          NAMTBL ENTRY FOR LOOPND
      DATA NAMTBL(2535),   CNAMTB(2535)
     *        /19045   ,     'LOOPND'/
C          NAMTBL ENTRY FOR BOTH  
      DATA NAMTBL(2536),   CNAMTB(2536)
     *        /35100   ,     'BOTH  '/
C          NAMTBL ENTRY FOR GOLFT 
      DATA NAMTBL(2537),   CNAMTB(2537)
     *        /40034   ,     'GOLFT '/
C          NAMTBL ENTRY FOR SQRTF 
      DATA NAMTBL(2540),   CNAMTB(2540)
     *        /18192   ,     'SQRTF '/
C          NAMTBL ENTRY FOR ZSURF 
      DATA NAMTBL(2541),   CNAMTB(2541)
     *        /40023   ,     'ZSURF '/
C          NAMTBL ENTRY FOR GOLOFT
      DATA NAMTBL(2545),   CNAMTB(2545)
     *        /40060   ,     'GOLOFT'/
C          NAMTBL ENTRY FOR GO    
      DATA NAMTBL(2554),   CNAMTB(2554)
     *        /40025   ,     'GO    '/
C          NAMTBL ENTRY FOR DUMYA 
      DATA NAMTBL(2559),   CNAMTB(2559)
     *        /35005   ,     'DUMYA '/
C          NAMTBL ENTRY FOR DUMYB 
      DATA NAMTBL(2560),   CNAMTB(2560)
     *        /35005   ,     'DUMYB '/
C          NAMTBL ENTRY FOR TLLFT 
      DATA NAMTBL(2566),   CNAMTB(2566)
     *        /40001   ,     'TLLFT '/
C          NAMTBL ENTRY FOR SEQNO 
      DATA NAMTBL(2586),   CNAMTB(2586)
     *        /40000   ,     'SEQNO '/
C          NAMTBL ENTRY FOR TWOPT 
      DATA NAMTBL(2590),   CNAMTB(2590)
     *        /35100   ,     'TWOPT '/
C          NAMTBL ENTRY FOR MULTRD
      DATA NAMTBL(2592),   CNAMTB(2592)
     *        /35100   ,     'MULTRD'/
C          NAMTBL ENTRY FOR MULTAX
      DATA NAMTBL(2593),   CNAMTB(2593)
     *        /40006   ,     'MULTAX'/
C          NAMTBL ENTRY FOR ADJUST
      DATA NAMTBL(2597),   CNAMTB(2597)
     *        /35100   ,     'ADJUST'/
C          NAMTBL ENTRY FOR TLAXIS
      DATA NAMTBL(2598),   CNAMTB(2598)
     *        /19039   ,     'TLAXIS'/
C          NAMTBL ENTRY FOR SAME  
      DATA NAMTBL(2599),   CNAMTB(2599)
     *        /35100   ,     'SAME  '/
C          NAMTBL ENTRY FOR TLAXXX
      DATA NAMTBL(2600),   CNAMTB(2600)
     *        /39049   ,     'TLAXXX'/
C          NAMTBL ENTRY FOR SPINDL
      DATA NAMTBL(2614),   CNAMTB(2614)
     *        /40000   ,     'SPINDL'/
C          NAMTBL ENTRY FOR RPM   
      DATA NAMTBL(2616),   CNAMTB(2616)
     *        /35100   ,     'RPM   '/
C          NAMTBL ENTRY FOR SPIRAL
      DATA NAMTBL(2618),   CNAMTB(2618)
     *        /35100   ,     'SPIRAL'/
C          NAMTBL ENTRY FOR ARSINF
      DATA NAMTBL(2643),   CNAMTB(2643)
     *        /18225   ,     'ARSINF'/
C          NAMTBL ENTRY FOR ARSINB
      DATA NAMTBL(2644),   CNAMTB(2644)
     *        /18231   ,     'ARSINB'/
C          NAMTBL ENTRY FOR ISTOP 
      DATA NAMTBL(2669),   CNAMTB(2669)
     *        /40000   ,     'ISTOP '/
C          NAMTBL ENTRY FOR MANUAL
      DATA NAMTBL(2675),   CNAMTB(2675)
     *        /35100   ,     'MANUAL'/
C          NAMTBL ENTRY FOR MACHIN
      DATA NAMTBL(2676),   CNAMTB(2676)
     *        /40046   ,     'MACHIN'/
C          NAMTBL ENTRY FOR LAG   
      DATA NAMTBL(2684),   CNAMTB(2684)
     *        /35096   ,     'LAG   '/
C          NAMTBL ENTRY FOR MACRO 
      DATA NAMTBL(2686),   CNAMTB(2686)
     *        /33000   ,     'MACRO '/
C          NAMTBL ENTRY FOR LARGE 
      DATA NAMTBL(2709),   CNAMTB(2709)
     *        /35019   ,     'LARGE '/
C          NAMTBL ENTRY FOR SCURV 
      DATA NAMTBL(2722),   CNAMTB(2722)
     *        /43030   ,     'SCURV '/
C          NAMTBL ENTRY FOR PIVOT 
      DATA NAMTBL(2723),   CNAMTB(2723)
     *        /35167   ,     'PIVOT '/
C          NAMTBL ENTRY FOR PIVOTZ
      DATA NAMTBL(2724),   CNAMTB(2724)
     *        /40000   ,     'PIVOTZ'/
C          NAMTBL ENTRY FOR PERIM 
      DATA NAMTBL(2739),   CNAMTB(2739)
     *        /35055   ,     'PERIM '/
C          NAMTBL ENTRY FOR PERPTO
      DATA NAMTBL(2746),   CNAMTB(2746)
     *        /35013   ,     'PERPTO'/
C          NAMTBL ENTRY FOR JUMPTO
      DATA NAMTBL(2747),   CNAMTB(2747)
     *        /40024   ,     'JUMPTO'/
C          NAMTBL ENTRY FOR SRFVCT
      DATA NAMTBL(2748),   CNAMTB(2748)
     *        /40038   ,     'SRFVCT'/
C          NAMTBL ENTRY FOR PTNORM
      DATA NAMTBL(2751),   CNAMTB(2751)
     *        /35100   ,     'PTNORM'/
C          NAMTBL ENTRY FOR AXIS  
      DATA NAMTBL(2769),   CNAMTB(2769)
     *        /35146   ,     'AXIS  '/
C          NAMTBL ENTRY FOR YAXIS 
      DATA NAMTBL(2785),   CNAMTB(2785)
     *        /35008   ,     'YAXIS '/
C          NAMTBL ENTRY FOR ZLARGE
      DATA NAMTBL(2788),   CNAMTB(2788)
     *        /35016   ,     'ZLARGE'/
C          NAMTBL ENTRY FOR EXPF  
      DATA NAMTBL(2792),   CNAMTB(2792)
     *        /18187   ,     'EXPF  '/
C          NAMTBL ENTRY FOR GOMILL
      DATA NAMTBL(2795),   CNAMTB(2795)
     *        /40060   ,     'GOMILL'/
C          NAMTBL ENTRY FOR BOUNDS
      DATA NAMTBL(2798),   CNAMTB(2798)
     *        /39027   ,     'BOUNDS'/
C          NAMTBL ENTRY FOR GOBACK
      DATA NAMTBL(2801),   CNAMTB(2801)
     *        /40034   ,     'GOBACK'/
C          NAMTBL ENTRY FOR SEG   
      DATA NAMTBL(2810),   CNAMTB(2810)
     *        /35150   ,     'SEG   '/
C          NAMTBL ENTRY FOR POLCON
      DATA NAMTBL(2827),   CNAMTB(2827)
     *        /43013   ,     'POLCON'/
C          NAMTBL ENTRY FOR LCONIC
      DATA NAMTBL(2840),   CNAMTB(2840)
     *        /39007   ,     'LCONIC'/
C          NAMTBL ENTRY FOR THICK 
      DATA NAMTBL(2841),   CNAMTB(2841)
     *        /40033   ,     'THICK '/
C          NAMTBL ENTRY FOR GCLEAR
      DATA NAMTBL(2843),   CNAMTB(2843)
     *        /40059   ,     'GCLEAR'/
C          NAMTBL ENTRY FOR REV   
      DATA NAMTBL(2844),   CNAMTB(2844)
     *        /35100   ,     'REV   '/
C          NAMTBL ENTRY FOR POLYGN
      DATA NAMTBL(2849),   CNAMTB(2849)
     *        /35134   ,     'POLYGN'/
C          NAMTBL ENTRY FOR CURSEG
      DATA NAMTBL(2857),   CNAMTB(2857)
     *        /35140   ,     'CURSEG'/
C          NAMTBL ENTRY FOR BREAK 
      DATA NAMTBL(2858),   CNAMTB(2858)
     *        /40000   ,     'BREAK '/
C          NAMTBL ENTRY FOR MMPM  
      DATA NAMTBL(2871),   CNAMTB(2871)
     *        /35100   ,     'MMPM  '/
C          NAMTBL ENTRY FOR MMPR  
      DATA NAMTBL(2876),   CNAMTB(2876)
     *        /35100   ,     'MMPR  '/
C          NAMTBL ENTRY FOR REVERS
      DATA NAMTBL(2881),   CNAMTB(2881)
     *        /40000   ,     'REVERS'/
C          NAMTBL ENTRY FOR REVOLV
      DATA NAMTBL(2891),   CNAMTB(2891)
     *        /35142   ,     'REVOLV'/
C          NAMTBL ENTRY FOR MILL  
      DATA NAMTBL(2892),   CNAMTB(2892)
     *        /35100   ,     'MILL  '/
C          NAMTBL ENTRY FOR CLW   
      DATA NAMTBL(2902),   CNAMTB(2902)
     *        /35058   ,     'CLW   '/
C          NAMTBL ENTRY FOR SWITCH
      DATA NAMTBL(2912),   CNAMTB(2912)
     *        /40000   ,     'SWITCH'/
C          NAMTBL ENTRY FOR SSPRT 
      DATA NAMTBL(2918),   CNAMTB(2918)
     *        /35130   ,     'SSPRT '/
C          NAMTBL ENTRY FOR SOLID 
      DATA NAMTBL(2931),   CNAMTB(2931)
     *        /35100   ,     'SOLID '/
C          NAMTBL ENTRY FOR LEAD  
      DATA NAMTBL(2968),   CNAMTB(2968)
     *        /35095   ,     'LEAD  '/
C          NAMTBL ENTRY FOR LEADER
      DATA NAMTBL(2969),   CNAMTB(2969)
     *        /40000   ,     'LEADER'/
C          NAMTBL ENTRY FOR CLAMP 
      DATA NAMTBL(2975),   CNAMTB(2975)
     *        /40000   ,     'CLAMP '/
C          NAMTBL ENTRY FOR BAXIS 
      DATA NAMTBL(2977),   CNAMTB(2977)
     *        /35100   ,     'BAXIS '/
C          NAMTBL ENTRY FOR LAST  
      DATA NAMTBL(2978),   CNAMTB(2978)
     *        /35100   ,     'LAST  '/
C          NAMTBL ENTRY FOR GAPLES
      DATA NAMTBL(2982),   CNAMTB(2982)
     *        /35100   ,     'GAPLES'/
C          NAMTBL ENTRY FOR ZIGZAG
      DATA NAMTBL(2994),   CNAMTB(2994)
     *        /35061   ,     'ZIGZAG'/
C     CNUMTB ENTRIES FROM IFIXST TO IFIXND
      DATA CNUMTB(   1) /'0           '/
      DATA CNUMTB(   2) /'1           '/
      DATA CNUMTB(   3) /'2           '/
      DATA CNUMTB(   4) /'3           '/
      DATA CNUMTB(   5) /'4           '/
      DATA CNUMTB(   6) /'5           '/
      DATA CNUMTB(   7) /'6           '/
      DATA CNUMTB(   8) /'7           '/
      DATA CNUMTB(   9) /'8           '/
      DATA CNUMTB(  10) /'9           '/
      DATA CNUMTB(  11) /'0.          '/
      DATA CNUMTB(  12) /'1.          '/
      DATA CNUMTB(  13) /'10.         '/
       END
