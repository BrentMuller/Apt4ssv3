      BLOCK DATA BDCODE
      IMPLICIT INTEGER (A-Z)
      COMMON/CODE/CODE
      DIMENSION CODE( 150)
C   META LINGUISTIC CLASS    ,     
      DATA CODE(  1),CODE(  2)/ 1000,    48/
C   META LINGUISTIC CLASS    (     
      DATA CODE(  3),CODE(  4)/ 2000,    49/
C   META LINGUISTIC CLASS    )     
      DATA CODE(  5),CODE(  6)/ 3000,    25/
C   META LINGUISTIC CLASS    RTERM 
      DATA CODE(  7),CODE(  8)/ 4000,    51/
C   META LINGUISTIC CLASS    /     
      DATA CODE(  9),CODE( 10)/ 5000,    39/
C   META LINGUISTIC CLASS    -     
      DATA CODE( 11),CODE( 12)/ 6000,    26/
C   META LINGUISTIC CLASS    +     
      DATA CODE( 13),CODE( 14)/ 7000,    14/
C   META LINGUISTIC CLASS    =     
      DATA CODE( 15),CODE( 16)/ 8000,    12/
C   META LINGUISTIC CLASS    *     
      DATA CODE( 17),CODE( 18)/ 9000,    37/
C   META LINGUISTIC CLASS    DIGIT 
      DATA CODE( 19),CODE( 20)/10000,     2/
C   META LINGUISTIC CLASS    LETTER
      DATA CODE( 21),CODE( 22)/11000,    15/
C   META LINGUISTIC CLASS    '     
      DATA CODE( 23),CODE( 24)/12000,    13/
C   META LINGUISTIC CLASS    BLANK 
      DATA CODE( 25),CODE( 26)/13000,    38/
C   META LINGUISTIC CLASS    NUMBER
      DATA CODE( 27),CODE( 28)/14000,    56/
C   META LINGUISTIC CLASS    DOLLAR
      DATA CODE( 29),CODE( 30)/15000,    36/
C   META LINGUISTIC CLASS    GEOM  
      DATA CODE( 31),CODE( 32)/16000,    56/
C   META LINGUISTIC CLASS    TEMP  
      DATA CODE( 33),CODE( 34)/17000,    56/
C   META LINGUISTIC CLASS    FCN   
      DATA CODE( 35),CODE( 36)/18000,    56/
C   META LINGUISTIC CLASS    PROCED
      DATA CODE( 37),CODE( 38)/19000,    56/
C   META LINGUISTIC CLASS    PERMID
      DATA CODE( 39),CODE( 40)/20000,    56/
C   META LINGUISTIC CLASS    .     
      DATA CODE( 41),CODE( 42)/21000,    24/
C   META LINGUISTIC CLASS    LABEL 
      DATA CODE( 43),CODE( 44)/22000,    56/
C   META LINGUISTIC CLASS    IMPLAB
      DATA CODE( 45),CODE( 46)/23000,    56/
C   META LINGUISTIC CLASS    LTERM 
      DATA CODE( 47),CODE( 48)/24000,    50/
C   META LINGUISTIC CLASS    DOT   
      DATA CODE( 49),CODE( 50)/25000,    54/
C   META LINGUISTIC CLASS    KREUZ 
      DATA CODE( 51),CODE( 52)/26000,    55/
C   META LINGUISTIC CLASS    RELAT 
      DATA CODE( 53),CODE( 54)/27000,    56/
C   META LINGUISTIC CLASS    NOT   
      DATA CODE( 55),CODE( 56)/28000,    56/
C   META LINGUISTIC CLASS    AND   
      DATA CODE( 57),CODE( 58)/29000,    56/
C   META LINGUISTIC CLASS    OR    
      DATA CODE( 59),CODE( 60)/30000,    56/
C   META LINGUISTIC CLASS    VBL   
      DATA CODE( 61),CODE( 62)/31000,    56/
C   META LINGUISTIC CLASS    DBLAST
      DATA CODE( 63),CODE( 64)/32000,    53/
C   META LINGUISTIC CLASS    MACRO 
      DATA CODE( 65),CODE( 66)/33000,    56/
C   META LINGUISTIC CLASS    MACNAM
      DATA CODE( 67),CODE( 68)/34000,    56/
C   META LINGUISTIC CLASS    IDENT 
      DATA CODE( 69),CODE( 70)/35000,    56/
C   META LINGUISTIC CLASS    MACVBL
      DATA CODE( 71),CODE( 72)/36000,    56/
C   META LINGUISTIC CLASS    TERMAC
      DATA CODE( 73),CODE( 74)/37000,    56/
C   META LINGUISTIC CLASS    MCLTRM
      DATA CODE( 75),CODE( 76)/38000,    52/
C   META LINGUISTIC CLASS    CONGEO
      DATA CODE( 77),CODE( 78)/39000,    56/
C   META LINGUISTIC CLASS    CONPRO
      DATA CODE( 79),CODE( 80)/40000,    56/
C   META LINGUISTIC CLASS    IF    
      DATA CODE( 81),CODE( 82)/41000,    56/
C   META LINGUISTIC CLASS    CANON 
      DATA CODE( 83),CODE( 84)/42000,    56/
C   META LINGUISTIC CLASS    CONBIG
      DATA CODE( 85),CODE( 86)/43000,    56/
C   META LINGUISTIC CLASS    BIGGEO
      DATA CODE( 87),CODE( 88)/44000,    56/
C   META LINGUISTIC CLASS    CONAST
      DATA CODE( 89),CODE( 90)/45000,    56/
C   META LINGUISTIC CLASS    OBTAIN
      DATA CODE( 91),CODE( 92)/46000,    56/
       END
      BLOCK DATA BDSCRT
C
      IMPLICIT INTEGER (A-Z)
      COMMON/SRCTBL/SRCTBL
      DIMENSION SRCTBL(1492),PRODTB(1440),META(50)
      EQUIVALENCE (BRKPNT,SRCTBL(1)),
     1            (MBKPNT,SRCTBL(2)),
     2            (META(1),SRCTBL(3)),
     3            (PRODTB(1),SRCTBL(53)) 
C    META ENTRY FOR LETTER CLASS 11000  / Z40080000/
      DATA META( 11)                    / 1074266112/
C    META ENTRY FOR DIGIT  CLASS 10000  / Z40040000/
      DATA META( 10)                    / 1074003968/
C    META ENTRY FOR .      CLASS 21000  / Z20080000/
      DATA META( 21)                    /  537395200/
C    META ENTRY FOR (      CLASS  2000  / Z40020000/
      DATA META(  2)                    / 1073872896/
C    META ENTRY FOR *      CLASS  9000  / Z40010000/
      DATA META(  9)                    / 1073807360/
C    META ENTRY FOR DOLLAR CLASS 15000  / Z10080000/
      DATA META( 15)                    /  268959744/
C    META ENTRY FOR '      CLASS 12000  / Z08080000/
      DATA META( 12)                    /  134742016/
C    META ENTRY FOR NUMBER CLASS 14000  / Z04080000/
      DATA META( 14)                    /   67633152/
C    META ENTRY FOR RTERM  CLASS  4000  / Z02080000/
      DATA META(  4)                    /   34078720/
C    META ENTRY FOR MCLTRM CLASS 38000  / Z01080000/
      DATA META( 38)                    /   17301504/
C    META ENTRY FOR TERMAC CLASS 37000  / Z04040000/
      DATA META( 37)                    /   67371008/
C    META ENTRY FOR MACVBL CLASS 36000  / Z00880000/
      DATA META( 36)                    /    8912896/
C    META ENTRY FOR ,      CLASS  1000  / Z40008000/
      DATA META(  1)                    / 1073774592/
C    META ENTRY FOR )      CLASS  3000  / Z00480000/
      DATA META(  3)                    /    4718592/
C    META ENTRY FOR =      CLASS  8000  / Z40004000/
      DATA META(  8)                    / 1073758208/
C    META ENTRY FOR VBL    CLASS 31000  / Z04020000/
      DATA META( 31)                    /   67239936/
C    META ENTRY FOR IDENT  CLASS 35000  / Z04010000/
      DATA META( 35)                    /   67174400/
C    META ENTRY FOR PERMID CLASS 20000  / Z04008000/
      DATA META( 20)                    /   67141632/
C    META ENTRY FOR IMPLAB CLASS 23000  / Z04004000/
      DATA META( 23)                    /   67125248/
C    META ENTRY FOR LABEL  CLASS 22000  / Z04002000/
      DATA META( 22)                    /   67117056/
C    META ENTRY FOR FCN    CLASS 18000  / Z04001000/
      DATA META( 18)                    /   67112960/
C    META ENTRY FOR PROCED CLASS 19000  / Z04000800/
      DATA META( 19)                    /   67110912/
C    META ENTRY FOR GEOM   CLASS 16000  / Z04000400/
      DATA META( 16)                    /   67109888/
C    META ENTRY FOR BIGGEO CLASS 44000  / Z04000200/
      DATA META( 44)                    /   67109376/
C    META ENTRY FOR IF     CLASS 41000  / Z04000100/
      DATA META( 41)                    /   67109120/
C    META ENTRY FOR CANON  CLASS 42000  / Z04000080/
      DATA META( 42)                    /   67108992/
C    META ENTRY FOR CONPRO CLASS 40000  / Z04000040/
      DATA META( 40)                    /   67108928/
C    META ENTRY FOR CONGEO CLASS 39000  / Z04000020/
      DATA META( 39)                    /   67108896/
C    META ENTRY FOR CONBIG CLASS 43000  / Z04000010/
      DATA META( 43)                    /   67108880/
C    META ENTRY FOR OBTAIN CLASS 46000  / Z04000008/
      DATA META( 46)                    /   67108872/
C    META ENTRY FOR MACNAM CLASS 34000  / Z04000004/
      DATA META( 34)                    /   67108868/
C    META ENTRY FOR DBLAST CLASS 32000  / Z00280000/
      DATA META( 32)                    /    2621440/
C    META ENTRY FOR /      CLASS  5000  / Z40002000/
      DATA META(  5)                    / 1073750016/
C    META ENTRY FOR +      CLASS  7000  / Z40001000/
      DATA META(  7)                    / 1073745920/
C    META ENTRY FOR -      CLASS  6000  / Z40000800/
      DATA META(  6)                    / 1073743872/
C    META ENTRY FOR RELAT  CLASS 27000  / Z40000400/
      DATA META( 27)                    / 1073742848/
C    META ENTRY FOR NOT    CLASS 28000  / Z40000200/
      DATA META( 28)                    / 1073742336/
C    META ENTRY FOR AND    CLASS 29000  / Z40000100/
      DATA META( 29)                    / 1073742080/
C    META ENTRY FOR OR     CLASS 30000  / Z40000080/
      DATA META( 30)                    / 1073741952/
C    META ENTRY FOR DOT    CLASS 25000  / Z40000040/
      DATA META( 25)                    / 1073741888/
C    META ENTRY FOR CONAST CLASS 45000  / Z40000020/
      DATA META( 45)                    / 1073741856/
C    META ENTRY FOR KREUZ  CLASS 26000  / Z40000010/
      DATA META( 26)                    / 1073741840/
C    META ENTRY FOR TEMP   CLASS 17000  / Z04000002/
      DATA META( 17)                    /   67108866/
C    META ENTRY FOR MACRO  CLASS 33000  / Z04000001/
      DATA META( 33)                    /   67108865/
C    META ENTRY FOR LTERM  CLASS 24000  / Z00180000/
      DATA META( 24)                    /    1572864/
      DATA BRKPNT,MBKPNT/75,49/
C                         /Z9999/ +    0
      DATA PRODTB(     1) /-1718026240/
C                         / Z40080000/
      DATA PRODTB(     2) / 1074266112/
C                         /ZAAAA/ +   68
      DATA PRODTB(     3) /-1431699388/
C                         / Z40040000/
      DATA PRODTB(     4) / 1074003968/
C                         /ZAAAA/ +  104
      DATA PRODTB(     5) /-1431699352/
C                         / Z20080000/
      DATA PRODTB(     6) /  537395200/
C                         /ZAAAA/ +  140
      DATA PRODTB(     7) /-1431699316/
C                         / Z40020000/
      DATA PRODTB(     8) / 1073872896/
C                         /ZCCCC/ +   15
      DATA PRODTB(     9) / -859045873/
C                         / Z40010000/
      DATA PRODTB(    10) / 1073807360/
C                         /ZCCCC/ +   32
      DATA PRODTB(    11) / -859045856/
C                         / Z10080000/
      DATA PRODTB(    12) /  268959744/
C                         /ZCCCC/ +   19
      DATA PRODTB(    13) / -859045869/
C                         / Z08080000/
      DATA PRODTB(    14) /  134742016/
C                         /ZCCCC/ +    3
      DATA PRODTB(    15) / -859045885/
C                         / Z7FFFFFFF/
      DATA PRODTB(    16) / 2147483647/
C                         /ZAAAA/ +  168
      DATA PRODTB(    17) /-1431699288/
C                         / Z40080000/
      DATA PRODTB(    18) / 1074266112/
C                         /ZCCCC/ +   25
      DATA PRODTB(    19) / -859045863/
C                         / Z40040000/
      DATA PRODTB(    20) / 1074003968/
C                         /ZCCCC/ +   22
      DATA PRODTB(    21) / -859045866/
C                         / Z20080000/
      DATA PRODTB(    22) /  537395200/
C                         /ZCCCC/ +   71
      DATA PRODTB(    23) / -859045817/
C                         / Z04080000/
      DATA PRODTB(    24) /   67633152/
C                         /ZCCCC/ +   74
      DATA PRODTB(    25) / -859045814/
C                         /ZCCCC/ +    9
      DATA PRODTB(    26) / -859045879/
C                         / Z40080000/
      DATA PRODTB(    27) / 1074266112/
C                         /ZCCCC/ +   25
      DATA PRODTB(    28) / -859045863/
C                         / Z40040000/
      DATA PRODTB(    29) / 1074003968/
C                         /ZCCCC/ +   25
      DATA PRODTB(    30) / -859045863/
C                         / Z20080000/
      DATA PRODTB(    31) /  537395200/
C                         /ZCCCC/ +   36
      DATA PRODTB(    32) / -859045852/
C                         / Z04080000/
      DATA PRODTB(    33) /   67633152/
C                         /ZCCCC/ +   25
      DATA PRODTB(    34) / -859045863/
C                         /ZCCCC/ +    9
      DATA PRODTB(    35) / -859045879/
C                         / Z40080000/
      DATA PRODTB(    36) / 1074266112/
C                         /ZCCCC/ +   72
      DATA PRODTB(    37) / -859045816/
C                         / Z40040000/
      DATA PRODTB(    38) / 1074003968/
C                         /ZCCCC/ +   36
      DATA PRODTB(    39) / -859045852/
C                         / Z04080000/
      DATA PRODTB(    40) /   67633152/
C                         /ZCCCC/ +   73
      DATA PRODTB(    41) / -859045815/
C                         /ZCCCC/ +    9
      DATA PRODTB(    42) / -859045879/
C                         / Z40080000/
      DATA PRODTB(    43) / 1074266112/
C                         /ZCCCC/ +   35
      DATA PRODTB(    44) / -859045853/
C                         / Z40040000/
      DATA PRODTB(    45) / 1074003968/
C                         /ZCCCC/ +   34
      DATA PRODTB(    46) / -859045854/
C                         / Z04080000/
      DATA PRODTB(    47) /   67633152/
C                         /ZCCCC/ +   20
      DATA PRODTB(    48) / -859045868/
C                         /Z9999/ +  192
      DATA PRODTB(    49) /-1718026048/
C                         / Z02080000/
      DATA PRODTB(    50) /   34078720/
C                         /ZAAAA/ +   28
      DATA PRODTB(    51) /-1431699428/
C                         / Z01080000/
      DATA PRODTB(    52) /   17301504/
C                         /ZAAAA/ +   60
      DATA PRODTB(    53) /-1431699396/
C                         / Z7FFFFFFF/
      DATA PRODTB(    54) / 2147483647/
C                         /ZAAAA/ +   80
      DATA PRODTB(    55) /-1431699376/
C                         / Z01080000/
      DATA PRODTB(    56) /   17301504/
C                         /ZCCCC/ +   56
      DATA PRODTB(    57) / -859045832/
C                         / Z04040000/
      DATA PRODTB(    58) /   67371008/
C                         /ZAAAA/ +   48
      DATA PRODTB(    59) /-1431699408/
C                         /ZAAAA/ +   88
      DATA PRODTB(    60) /-1431699368/
C                         / Z01080000/
      DATA PRODTB(    61) /   17301504/
C                         /ZCCCC/ +   54
      DATA PRODTB(    62) / -859045834/
C                         /ZAAAA/ +  104
      DATA PRODTB(    63) /-1431699352/
C                         / Z01080000/
      DATA PRODTB(    64) /   17301504/
C                         /ZCCCC/ +   58
      DATA PRODTB(    65) / -859045830/
C                         / Z7FFFFFFF/
      DATA PRODTB(    66) / 2147483647/
C                         /ZAAAA/ +   96
      DATA PRODTB(    67) /-1431699360/
C                         / Z00880000/
      DATA PRODTB(    68) /    8912896/
C                         / Z01080000/
      DATA PRODTB(    69) /   17301504/
C                         /ZCCCC/ +   60
      DATA PRODTB(    70) / -859045828/
C                         / Z7FFFFFFF/
      DATA PRODTB(    71) / 2147483647/
C                         /ZAAAA/ +   96
      DATA PRODTB(    72) /-1431699360/
C                         / Z01080000/
      DATA PRODTB(    73) /   17301504/
C                         /ZCCCC/ +   55
      DATA PRODTB(    74) / -859045833/
C                         /Z9999/ +  292
      DATA PRODTB(    75) /-1718025948/
C                         / Z40008000/
      DATA PRODTB(    76) / 1073774592/
C                         /ZAAAA/ +  112
      DATA PRODTB(    77) /-1431699344/
C                         / Z00480000/
      DATA PRODTB(    78) /    4718592/
C                         /ZAAAA/ + 1064
      DATA PRODTB(    79) /-1431698392/
C                         / Z02080000/
      DATA PRODTB(    80) /   34078720/
C                         /ZAAAA/ + 2060
      DATA PRODTB(    81) /-1431697396/
C                         / Z40024000/
      DATA PRODTB(    82) / 1073889280/
C                         /ZCCCC/ +   29
      DATA PRODTB(    83) / -859045859/
C                         / Z0407FFFC/
      DATA PRODTB(    84) /   67633148/
C                         /ZCCCC/ +   29
      DATA PRODTB(    85) / -859045859/
C                         / Z04080000/
      DATA PRODTB(    86) /   67633152/
C                         /ZCCCC/ +   14
      DATA PRODTB(    87) / -859045874/
C                         / Z00280000/
      DATA PRODTB(    88) /    2621440/
C                         /ZAAAA/ + 4184
      DATA PRODTB(    89) /-1431695272/
C                         / Z40002000/
      DATA PRODTB(    90) / 1073750016/
C                         /ZAAAA/ + 4232
      DATA PRODTB(    91) /-1431695224/
C                         / Z40010000/
      DATA PRODTB(    92) / 1073807360/
C                         /ZAAAA/ + 4308
      DATA PRODTB(    93) /-1431695148/
C                         / Z40001800/
      DATA PRODTB(    94) / 1073747968/
C                         /ZAAAA/ + 4352
      DATA PRODTB(    95) /-1431695104/
C                         / Z40000780/
      DATA PRODTB(    96) / 1073743744/
C                         /ZAAAA/ + 4412
      DATA PRODTB(    97) /-1431695044/
C                         / Z40000060/
      DATA PRODTB(    98) / 1073741920/
C                         /ZAAAA/ + 4484
      DATA PRODTB(    99) /-1431694972/
C                         / Z40000010/
      DATA PRODTB(   100) / 1073741840/
C                         /ZAAAA/ + 4472
      DATA PRODTB(   101) /-1431694984/
C                         /ZCCCC/ +   28
      DATA PRODTB(   102) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   103) / 1073774592/
C                         /ZAAAA/ +  212
      DATA PRODTB(   104) /-1431699244/
C                         / Z00480000/
      DATA PRODTB(   105) /    4718592/
C                         /ZAAAA/ +  232
      DATA PRODTB(   106) /-1431699224/
C                         / Z04020000/
      DATA PRODTB(   107) /   67239936/
C                         /ZAAAA/ +  296
      DATA PRODTB(   108) /-1431699160/
C                         / Z04000002/
      DATA PRODTB(   109) /   67108866/
C                         /ZAAAA/ +  488
      DATA PRODTB(   110) /-1431698968/
C                         / Z04080000/
      DATA PRODTB(   111) /   67633152/
C                         /ZAAAA/ +  580
      DATA PRODTB(   112) /-1431698876/
C                         / Z04010020/
      DATA PRODTB(   113) /   67174432/
C                         /ZAAAA/ +  660
      DATA PRODTB(   114) /-1431698796/
C                         / Z04008400/
      DATA PRODTB(   115) /   67142656/
C                         /ZAAAA/ +  752
      DATA PRODTB(   116) /-1431698704/
C                         / Z04007000/
      DATA PRODTB(   117) /   67137536/
C                         /ZAAAA/ +  816
      DATA PRODTB(   118) /-1431698640/
C                         / Z04000800/
      DATA PRODTB(   119) /   67110912/
C                         /ZAAAA/ +  860
      DATA PRODTB(   120) /-1431698596/
C                         / Z0400028C/
      DATA PRODTB(   121) /   67109516/
C                         /ZAAAA/ +  912
      DATA PRODTB(   122) /-1431698544/
C                         / Z04000040/
      DATA PRODTB(   123) /   67108928/
C                         /ZAAAA/ +  948
      DATA PRODTB(   124) /-1431698508/
C                         / Z04000010/
      DATA PRODTB(   125) /   67108880/
C                         /ZAAAA/ + 1020
      DATA PRODTB(   126) /-1431698436/
C                         /ZCCCC/ +   12
      DATA PRODTB(   127) / -859045876/
C                         / Z04000080/
      DATA PRODTB(   128) /   67108992/
C                         /ZCCCC/ +   42
      DATA PRODTB(   129) / -859045846/
C                         / Z04020002/
      DATA PRODTB(   130) /   67239938/
C                         /ZAAAA/ + 4508
      DATA PRODTB(   131) /-1431694948/
C                         /ZCCCC/ +   12
      DATA PRODTB(   132) / -859045876/
C                         / Z040A0002/
      DATA PRODTB(   133) /   67764226/
C                         /ZAAAA/ +  252
      DATA PRODTB(   134) /-1431699204/
C                         / Z04018000/
      DATA PRODTB(   135) /   67207168/
C                         /ZAAAA/ +  284
      DATA PRODTB(   136) /-1431699172/
C                         /ZCCCC/ +   12
      DATA PRODTB(   137) / -859045876/
C                         / Z40020000/
      DATA PRODTB(   138) / 1073872896/
C                         /ZAAAA/ +  264
      DATA PRODTB(   139) /-1431699192/
C                         /ZCCCC/ +   12
      DATA PRODTB(   140) / -859045876/
C                         / Z04018000/
      DATA PRODTB(   141) /   67207168/
C                         /ZCCCC/ +    4
      DATA PRODTB(   142) / -859045884/
C                         / Z04020000/
      DATA PRODTB(   143) /   67239936/
C                         /ZAAAA/ + 4532
      DATA PRODTB(   144) /-1431694924/
C                         /ZCCCC/ +   12
      DATA PRODTB(   145) / -859045876/
C                         / Z40020000/
      DATA PRODTB(   146) / 1073872896/
C                         /ZAAAA/ +  272
      DATA PRODTB(   147) /-1431699184/
C                         /ZCCCC/ +   12
      DATA PRODTB(   148) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   149) / 1073774592/
C                         /ZAAAA/ +  348
      DATA PRODTB(   150) /-1431699108/
C                         / Z40004000/
      DATA PRODTB(   151) / 1073758208/
C                         /ZAAAA/ +  416
      DATA PRODTB(   152) /-1431699040/
C                         / Z40002000/
      DATA PRODTB(   153) / 1073750016/
C                         /ZAAAA/ +  468
      DATA PRODTB(   154) /-1431698988/
C                         / Z40001800/
      DATA PRODTB(   155) / 1073747968/
C                         /ZAAAA/ + 4564
      DATA PRODTB(   156) /-1431694892/
C                         / Z40010000/
      DATA PRODTB(   157) / 1073807360/
C                         /ZAAAA/ + 4576
      DATA PRODTB(   158) /-1431694880/
C                         / Z00280000/
      DATA PRODTB(   159) /    2621440/
C                         /ZAAAA/ + 4576
      DATA PRODTB(   160) /-1431694880/
C                         /ZCCCC/ +   12
      DATA PRODTB(   161) / -859045876/
C                         / Z04020002/
      DATA PRODTB(   162) /   67239938/
C                         /ZAAAA/ +  384
      DATA PRODTB(   163) /-1431699072/
C                         / Z04000001/
      DATA PRODTB(   164) /   67108865/
C                         /ZAAAA/ + 4592
      DATA PRODTB(   165) /-1431694864/
C                         / Z04098000/
      DATA PRODTB(   166) /   67731456/
C                         /ZAAAA/ + 4604
      DATA PRODTB(   167) /-1431694852/
C                         / Z04000080/
      DATA PRODTB(   168) /   67108992/
C                         /ZAAAA/ + 4620
      DATA PRODTB(   169) /-1431694836/
C                         /ZCCCC/ +   12
      DATA PRODTB(   170) / -859045876/
C                         / Z40002000/
      DATA PRODTB(   171) / 1073750016/
C                         /ZAAAA/ +  396
      DATA PRODTB(   172) /-1431699060/
C                         /ZCCCC/ +   12
      DATA PRODTB(   173) / -859045876/
C                         / Z04000200/
      DATA PRODTB(   174) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(   175) / -859045786/
C                         / Z04000400/
      DATA PRODTB(   176) /   67109888/
C                         /ZAAAA/ + 4648
      DATA PRODTB(   177) /-1431694808/
C                         /ZCCCC/ +   12
      DATA PRODTB(   178) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   179) /   67370608/
C                         /ZAAAA/ +  428
      DATA PRODTB(   180) /-1431699028/
C                         /ZCCCC/ +   12
      DATA PRODTB(   181) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   182) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   183) /-1431699008/
C                         / Z40002000/
      DATA PRODTB(   184) / 1073750016/
C                         /ZAAAA/ + 4664
      DATA PRODTB(   185) /-1431694792/
C                         /ZCCCC/ +   12
      DATA PRODTB(   186) / -859045876/
C                         / Z04000005/
      DATA PRODTB(   187) /   67108869/
C                         /ZCCCC/ +   51
      DATA PRODTB(   188) / -859045837/
C                         / Z04010070/
      DATA PRODTB(   189) /   67174512/
C                         /ZAAAA/ + 4676
      DATA PRODTB(   190) /-1431694780/
C                         /ZCCCC/ +   12
      DATA PRODTB(   191) / -859045876/
C                         / Z040A0002/
      DATA PRODTB(   192) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   193) / -859045880/
C                         / Z04000001/
      DATA PRODTB(   194) /   67108865/
C                         /ZAAAA/ + 4592
      DATA PRODTB(   195) /-1431694864/
C                         /ZCCCC/ +   12
      DATA PRODTB(   196) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   197) / 1073774592/
C                         /ZAAAA/ +  532
      DATA PRODTB(   198) /-1431698924/
C                         / Z40004000/
      DATA PRODTB(   199) / 1073758208/
C                         /ZAAAA/ +  556
      DATA PRODTB(   200) /-1431698900/
C                         / Z40001800/
      DATA PRODTB(   201) / 1073747968/
C                         /ZAAAA/ + 4564
      DATA PRODTB(   202) /-1431694892/
C                         / Z40012000/
      DATA PRODTB(   203) / 1073815552/
C                         /ZAAAA/ + 4576
      DATA PRODTB(   204) /-1431694880/
C                         / Z40000020/
      DATA PRODTB(   205) / 1073741856/
C                         /ZAAAA/ + 4696
      DATA PRODTB(   206) /-1431694760/
C                         /ZAAAA/ +  336
      DATA PRODTB(   207) /-1431699120/
C                         / Z04020002/
      DATA PRODTB(   208) /   67239938/
C                         /ZAAAA/ +  544
      DATA PRODTB(   209) /-1431698912/
C                         /ZAAAA/ +  364
      DATA PRODTB(   210) /-1431699092/
C                         / Z40002000/
      DATA PRODTB(   211) / 1073750016/
C                         /ZAAAA/ +  396
      DATA PRODTB(   212) /-1431699060/
C                         /ZCCCC/ +   12
      DATA PRODTB(   213) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   214) /   67370608/
C                         /ZAAAA/ +  568
      DATA PRODTB(   215) /-1431698888/
C                         /ZCCCC/ +   12
      DATA PRODTB(   216) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   217) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   218) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   219) /-1431699020/
C                         / Z40008000/
      DATA PRODTB(   220) / 1073774592/
C                         /ZAAAA/ +  624
      DATA PRODTB(   221) /-1431698832/
C                         / Z40004000/
      DATA PRODTB(   222) / 1073758208/
C                         /ZAAAA/ +  636
      DATA PRODTB(   223) /-1431698820/
C                         / Z40001800/
      DATA PRODTB(   224) / 1073747968/
C                         /ZAAAA/ + 4564
      DATA PRODTB(   225) /-1431694892/
C                         / Z40012000/
      DATA PRODTB(   226) / 1073815552/
C                         /ZAAAA/ + 4576
      DATA PRODTB(   227) /-1431694880/
C                         / Z40000020/
      DATA PRODTB(   228) / 1073741856/
C                         /ZAAAA/ + 4696
      DATA PRODTB(   229) /-1431694760/
C                         /ZAAAA/ +  336
      DATA PRODTB(   230) /-1431699120/
C                         / Z040B8002/
      DATA PRODTB(   231) /   67862530/
C                         /ZAAAA/ + 4604
      DATA PRODTB(   232) /-1431694852/
C                         /ZAAAA/ +  372
      DATA PRODTB(   233) /-1431699084/
C                         / Z0403FE70/
      DATA PRODTB(   234) /   67370608/
C                         /ZAAAA/ +  648
      DATA PRODTB(   235) /-1431698808/
C                         /ZCCCC/ +   12
      DATA PRODTB(   236) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   237) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   238) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   239) /-1431699020/
C                         / Z40008000/
      DATA PRODTB(   240) / 1073774592/
C                         /ZAAAA/ +  688
      DATA PRODTB(   241) /-1431698768/
C                         / Z40004000/
      DATA PRODTB(   242) / 1073758208/
C                         /ZAAAA/ +  728
      DATA PRODTB(   243) /-1431698728/
C                         / Z40002000/
      DATA PRODTB(   244) / 1073750016/
C                         /ZAAAA/ + 4588
      DATA PRODTB(   245) /-1431694868/
C                         /ZCCCC/ +   12
      DATA PRODTB(   246) / -859045876/
C                         / Z04020002/
      DATA PRODTB(   247) /   67239938/
C                         /ZAAAA/ +  716
      DATA PRODTB(   248) /-1431698740/
C                         / Z04000001/
      DATA PRODTB(   249) /   67108865/
C                         /ZAAAA/ + 4592
      DATA PRODTB(   250) /-1431694864/
C                         / Z04098080/
      DATA PRODTB(   251) /   67731584/
C                         /ZAAAA/ + 4604
      DATA PRODTB(   252) /-1431694852/
C                         /ZCCCC/ +   12
      DATA PRODTB(   253) / -859045876/
C                         / Z40002000/
      DATA PRODTB(   254) / 1073750016/
C                         /ZAAAA/ +  396
      DATA PRODTB(   255) /-1431699060/
C                         /ZCCCC/ +   12
      DATA PRODTB(   256) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   257) /   67370608/
C                         /ZAAAA/ +  740
      DATA PRODTB(   258) /-1431698716/
C                         /ZCCCC/ +   12
      DATA PRODTB(   259) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   260) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   261) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   262) /-1431699020/
C                         / Z40008000/
      DATA PRODTB(   263) / 1073774592/
C                         /ZAAAA/ +  772
      DATA PRODTB(   264) /-1431698684/
C                         / Z40004000/
      DATA PRODTB(   265) / 1073758208/
C                         /ZAAAA/ +  792
      DATA PRODTB(   266) /-1431698664/
C                         /ZAAAA/ +  676
      DATA PRODTB(   267) /-1431698780/
C                         / Z04000001/
      DATA PRODTB(   268) /   67108865/
C                         /ZAAAA/ + 4592
      DATA PRODTB(   269) /-1431694864/
C                         / Z040B8082/
      DATA PRODTB(   270) /   67862658/
C                         /ZAAAA/ + 4604
      DATA PRODTB(   271) /-1431694852/
C                         /ZCCCC/ +   12
      DATA PRODTB(   272) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   273) /   67370608/
C                         /ZAAAA/ +  804
      DATA PRODTB(   274) /-1431698652/
C                         /ZCCCC/ +   12
      DATA PRODTB(   275) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   276) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   277) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   278) /-1431699020/
C                         / Z40004000/
      DATA PRODTB(   279) / 1073758208/
C                         /ZAAAA/ +  836
      DATA PRODTB(   280) /-1431698620/
C                         / Z40008000/
      DATA PRODTB(   281) / 1073774592/
C                         /ZAAAA/ + 4588
      DATA PRODTB(   282) /-1431694868/
C                         /ZAAAA/ +  676
      DATA PRODTB(   283) /-1431698780/
C                         / Z0403FE70/
      DATA PRODTB(   284) /   67370608/
C                         /ZAAAA/ +  848
      DATA PRODTB(   285) /-1431698608/
C                         /ZCCCC/ +   12
      DATA PRODTB(   286) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   287) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   288) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   289) /-1431699020/
C                         / Z40004000/
      DATA PRODTB(   290) / 1073758208/
C                         /ZAAAA/ +  888
      DATA PRODTB(   291) /-1431698568/
C                         / Z00180000/
      DATA PRODTB(   292) /    1572864/
C                         /ZCCCC/ +   26
      DATA PRODTB(   293) / -859045862/
C                         / Z40008000/
      DATA PRODTB(   294) / 1073774592/
C                         /ZAAAA/ + 4588
      DATA PRODTB(   295) /-1431694868/
C                         /ZAAAA/ +  676
      DATA PRODTB(   296) /-1431698780/
C                         / Z0403FE70/
      DATA PRODTB(   297) /   67370608/
C                         /ZAAAA/ +  900
      DATA PRODTB(   298) /-1431698556/
C                         /ZCCCC/ +   12
      DATA PRODTB(   299) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   300) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   301) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   302) /-1431699020/
C                         / Z40004000/
      DATA PRODTB(   303) / 1073758208/
C                         /ZAAAA/ +  924
      DATA PRODTB(   304) /-1431698532/
C                         /ZCCCC/ +   12
      DATA PRODTB(   305) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   306) /   67370608/
C                         /ZAAAA/ +  936
      DATA PRODTB(   307) /-1431698520/
C                         /ZCCCC/ +   12
      DATA PRODTB(   308) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   309) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   310) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   311) /-1431699020/
C                         / Z40008000/
      DATA PRODTB(   312) / 1073774592/
C                         /ZAAAA/ +  976
      DATA PRODTB(   313) /-1431698480/
C                         / Z40004000/
      DATA PRODTB(   314) / 1073758208/
C                         /ZAAAA/ +  996
      DATA PRODTB(   315) /-1431698460/
C                         / Z00180000/
      DATA PRODTB(   316) /    1572864/
C                         /ZCCCC/ +    2
      DATA PRODTB(   317) / -859045886/
C                         /ZAAAA/ +  676
      DATA PRODTB(   318) /-1431698780/
C                         / Z04000001/
      DATA PRODTB(   319) /   67108865/
C                         /ZAAAA/ + 4592
      DATA PRODTB(   320) /-1431694864/
C                         / Z04020002/
      DATA PRODTB(   321) /   67239938/
C                         /ZAAAA/ + 4640
      DATA PRODTB(   322) /-1431694816/
C                         /ZCCCC/ +   12
      DATA PRODTB(   323) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   324) /   67370608/
C                         /ZAAAA/ + 1008
      DATA PRODTB(   325) /-1431698448/
C                         /ZCCCC/ +   12
      DATA PRODTB(   326) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   327) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   328) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   329) /-1431699020/
C                         / Z40004000/
      DATA PRODTB(   330) / 1073758208/
C                         /ZAAAA/ + 1040
      DATA PRODTB(   331) /-1431698416/
C                         / Z40008000/
      DATA PRODTB(   332) / 1073774592/
C                         /ZAAAA/ + 4636
      DATA PRODTB(   333) /-1431694820/
C                         /ZCCCC/ +   12
      DATA PRODTB(   334) / -859045876/
C                         / Z0403FE70/
      DATA PRODTB(   335) /   67370608/
C                         /ZAAAA/ + 1052
      DATA PRODTB(   336) /-1431698404/
C                         /ZCCCC/ +   12
      DATA PRODTB(   337) / -859045876/
C                         / Z40008000/
      DATA PRODTB(   338) / 1073774592/
C                         /ZAAAA/ +  448
      DATA PRODTB(   339) /-1431699008/
C                         /ZAAAA/ +  436
      DATA PRODTB(   340) /-1431699020/
C                         / Z00480000/
      DATA PRODTB(   341) /    4718592/
C                         /ZAAAA/ + 1172
      DATA PRODTB(   342) /-1431698284/
C                         / Z04020000/
      DATA PRODTB(   343) /   67239936/
C                         /ZAAAA/ + 1224
      DATA PRODTB(   344) /-1431698232/
C                         / Z04000002/
      DATA PRODTB(   345) /   67108866/
C                         /ZAAAA/ + 1508
      DATA PRODTB(   346) /-1431697948/
C                         / Z04080000/
      DATA PRODTB(   347) /   67633152/
C                         /ZAAAA/ + 1644
      DATA PRODTB(   348) /-1431697812/
C                         / Z04010000/
      DATA PRODTB(   349) /   67174400/
C                         /ZAAAA/ + 1772
      DATA PRODTB(   350) /-1431697684/
C                         / Z04008000/
      DATA PRODTB(   351) /   67141632/
C                         /ZAAAA/ + 1868
      DATA PRODTB(   352) /-1431697588/
C                         / Z04004050/
      DATA PRODTB(   353) /   67125328/
C                         /ZAAAA/ + 1916
      DATA PRODTB(   354) /-1431697540/
C                         / Z04002000/
      DATA PRODTB(   355) /   67117056/
C                         /ZAAAA/ + 1936
      DATA PRODTB(   356) /-1431697520/
C                         / Z04000400/
      DATA PRODTB(   357) /   67109888/
C                         /ZAAAA/ + 1948
      DATA PRODTB(   358) /-1431697508/
C                         / Z04000080/
      DATA PRODTB(   359) /   67108992/
C                         /ZAAAA/ + 1960
      DATA PRODTB(   360) /-1431697496/
C                         / Z04000020/
      DATA PRODTB(   361) /   67108896/
C                         /ZAAAA/ + 2040
      DATA PRODTB(   362) /-1431697416/
C                         / Z04041A09/
      DATA PRODTB(   363) /   67377673/
C                         /ZAAAA/ + 4708
      DATA PRODTB(   364) /-1431694748/
C                         / Z40008000/
      DATA PRODTB(   365) / 1073774592/
C                         /ZAAAA/ + 4724
      DATA PRODTB(   366) /-1431694732/
C                         /ZCCCC/ +   28
      DATA PRODTB(   367) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(   368) /   67764226/
C                         /ZAAAA/ + 1192
      DATA PRODTB(   369) /-1431698264/
C                         / Z04018000/
      DATA PRODTB(   370) /   67207168/
C                         /ZAAAA/ + 4736
      DATA PRODTB(   371) /-1431694720/
C                         /ZCCCC/ +   28
      DATA PRODTB(   372) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   373) / 1073872896/
C                         /ZAAAA/ + 1204
      DATA PRODTB(   374) /-1431698252/
C                         /ZCCCC/ +   28
      DATA PRODTB(   375) / -859045860/
C                         / Z04020000/
      DATA PRODTB(   376) /   67239936/
C                         /ZCCCC/ +   10
      DATA PRODTB(   377) / -859045878/
C                         / Z04018000/
      DATA PRODTB(   378) /   67207168/
C                         /ZCCCC/ +    4
      DATA PRODTB(   379) / -859045884/
C                         /ZCCCC/ +   28
      DATA PRODTB(   380) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   381) / 1073774592/
C                         /ZAAAA/ + 1316
      DATA PRODTB(   382) /-1431698140/
C                         / Z40020000/
      DATA PRODTB(   383) / 1073872896/
C                         /ZAAAA/ + 1372
      DATA PRODTB(   384) /-1431698084/
C                         / Z40004000/
      DATA PRODTB(   385) / 1073758208/
C                         /ZAAAA/ + 1400
      DATA PRODTB(   386) /-1431698056/
C                         / Z40002000/
      DATA PRODTB(   387) / 1073750016/
C                         /ZAAAA/ + 1440
      DATA PRODTB(   388) /-1431698016/
C                         / Z40000200/
      DATA PRODTB(   389) / 1073742336/
C                         /ZCCCC/ +   75
      DATA PRODTB(   390) / -859045813/
C                         / Z40000180/
      DATA PRODTB(   391) / 1073742208/
C                         /ZAAAA/ + 4752
      DATA PRODTB(   392) /-1431694704/
C                         / Z40000400/
      DATA PRODTB(   393) / 1073742848/
C                         /ZAAAA/ + 4764
      DATA PRODTB(   394) /-1431694692/
C                         / Z40001800/
      DATA PRODTB(   395) / 1073747968/
C                         /ZAAAA/ + 4776
      DATA PRODTB(   396) /-1431694680/
C                         / Z40010000/
      DATA PRODTB(   397) / 1073807360/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   398) /-1431694668/
C                         / Z00280000/
      DATA PRODTB(   399) /    2621440/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   400) /-1431694668/
C                         / Z40000050/
      DATA PRODTB(   401) / 1073741904/
C                         /ZAAAA/ + 4800
      DATA PRODTB(   402) /-1431694656/
C                         /ZCCCC/ +   28
      DATA PRODTB(   403) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(   404) /   67764226/
C                         /ZAAAA/ + 1352
      DATA PRODTB(   405) /-1431698104/
C                         / Z04047E79/
      DATA PRODTB(   406) /   67403385/
C                         /ZCCCC/ +   16
      DATA PRODTB(   407) / -859045872/
C                         / Z04018000/
      DATA PRODTB(   408) /   67207168/
C                         /ZAAAA/ + 4812
      DATA PRODTB(   409) /-1431694644/
C                         / Z04000080/
      DATA PRODTB(   410) /   67108992/
C                         /ZAAAA/ + 4828
      DATA PRODTB(   411) /-1431694628/
C                         /ZCCCC/ +   28
      DATA PRODTB(   412) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   413) / 1073872896/
C                         /ZAAAA/ + 4844
      DATA PRODTB(   414) /-1431694612/
C                         / Z40002000/
      DATA PRODTB(   415) / 1073750016/
C                         /ZAAAA/ + 4816
      DATA PRODTB(   416) /-1431694640/
C                         /ZCCCC/ +   16
      DATA PRODTB(   417) / -859045872/
C                         / Z04038000/
      DATA PRODTB(   418) /   67338240/
C                         /ZCCCC/ +   29
      DATA PRODTB(   419) / -859045859/
C                         / Z04001000/
      DATA PRODTB(   420) /   67112960/
C                         /ZCCCC/ +   17
      DATA PRODTB(   421) / -859045871/
C                         / Z04000100/
      DATA PRODTB(   422) /   67109120/
C                         /ZCCCC/ +   78
      DATA PRODTB(   423) / -859045810/
C                         /ZCCCC/ +   21
      DATA PRODTB(   424) / -859045867/
C                         / Z04030072/
      DATA PRODTB(   425) /   67305586/
C                         /ZAAAA/ + 1420
      DATA PRODTB(   426) /-1431698036/
C                         / Z00480000/
      DATA PRODTB(   427) /    4718592/
C                         /ZAAAA/ + 4856
      DATA PRODTB(   428) /-1431694600/
C                         /ZCCCC/ +   28
      DATA PRODTB(   429) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   430) / 1073872896/
C                         /ZCCCC/ +   23
      DATA PRODTB(   431) / -859045865/
C                         / Z40004000/
      DATA PRODTB(   432) / 1073758208/
C                         /ZCCCC/ +   23
      DATA PRODTB(   433) / -859045865/
C                         /ZCCCC/ +   28
      DATA PRODTB(   434) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(   435) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   436) / -859045880/
C                         / Z04000400/
      DATA PRODTB(   437) /   67109888/
C                         /ZAAAA/ + 1468
      DATA PRODTB(   438) /-1431697988/
C                         / Z04000200/
      DATA PRODTB(   439) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   440) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   441) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   442) / 1073872896/
C                         /ZCCCC/ +   37
      DATA PRODTB(   443) / -859045851/
C                         / Z40004000/
      DATA PRODTB(   444) / 1073758208/
C                         /ZAAAA/ + 4876
      DATA PRODTB(   445) /-1431694580/
C                         /ZCCCC/ +   28
      DATA PRODTB(   446) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   447) / 1073872896/
C                         /ZCCCC/ +  105
      DATA PRODTB(   448) / -859045783/
C                         / Z40004000/
      DATA PRODTB(   449) / 1073758208/
C                         /ZAAAA/ + 4892
      DATA PRODTB(   450) /-1431694564/
C                         /ZCCCC/ +   28
      DATA PRODTB(   451) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   452) / 1073774592/
C                         /ZAAAA/ + 1592
      DATA PRODTB(   453) /-1431697864/
C                         / Z40020000/
      DATA PRODTB(   454) / 1073872896/
C                         /ZAAAA/ + 1372
      DATA PRODTB(   455) /-1431698084/
C                         / Z40004000/
      DATA PRODTB(   456) / 1073758208/
C                         /ZAAAA/ + 1604
      DATA PRODTB(   457) /-1431697852/
C                         / Z40002000/
      DATA PRODTB(   458) / 1073750016/
C                         /ZAAAA/ + 1616
      DATA PRODTB(   459) /-1431697840/
C                         / Z40000200/
      DATA PRODTB(   460) / 1073742336/
C                         /ZCCCC/ +   75
      DATA PRODTB(   461) / -859045813/
C                         / Z40000180/
      DATA PRODTB(   462) / 1073742208/
C                         /ZAAAA/ + 4752
      DATA PRODTB(   463) /-1431694704/
C                         / Z40000400/
      DATA PRODTB(   464) / 1073742848/
C                         /ZAAAA/ + 4764
      DATA PRODTB(   465) /-1431694692/
C                         / Z40001800/
      DATA PRODTB(   466) / 1073747968/
C                         /ZAAAA/ + 4776
      DATA PRODTB(   467) /-1431694680/
C                         / Z40010000/
      DATA PRODTB(   468) / 1073807360/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   469) /-1431694668/
C                         / Z40000020/
      DATA PRODTB(   470) / 1073741856/
C                         /ZAAAA/ + 4908
      DATA PRODTB(   471) /-1431694548/
C                         /ZAAAA/ + 1296
      DATA PRODTB(   472) /-1431698160/
C                         / Z040A0002/
      DATA PRODTB(   473) /   67764226/
C                         /ZAAAA/ + 1352
      DATA PRODTB(   474) /-1431698104/
C                         /ZAAAA/ + 1324
      DATA PRODTB(   475) /-1431698132/
C                         / Z04030072/
      DATA PRODTB(   476) /   67305586/
C                         /ZAAAA/ + 1420
      DATA PRODTB(   477) /-1431698036/
C                         /ZAAAA/ + 1408
      DATA PRODTB(   478) /-1431698048/
C                         / Z040A0002/
      DATA PRODTB(   479) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   480) / -859045880/
C                         / Z04000400/
      DATA PRODTB(   481) /   67109888/
C                         /ZAAAA/ + 1468
      DATA PRODTB(   482) /-1431697988/
C                         / Z04000200/
      DATA PRODTB(   483) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   484) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   485) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   486) / 1073774592/
C                         /ZAAAA/ + 1720
      DATA PRODTB(   487) /-1431697736/
C                         / Z40020000/
      DATA PRODTB(   488) / 1073872896/
C                         /ZAAAA/ + 1372
      DATA PRODTB(   489) /-1431698084/
C                         / Z40004000/
      DATA PRODTB(   490) / 1073758208/
C                         /ZAAAA/ + 1732
      DATA PRODTB(   491) /-1431697724/
C                         / Z00180000/
      DATA PRODTB(   492) /    1572864/
C                         /ZCCCC/ +    5
      DATA PRODTB(   493) / -859045883/
C                         / Z40002000/
      DATA PRODTB(   494) / 1073750016/
C                         /ZAAAA/ + 1744
      DATA PRODTB(   495) /-1431697712/
C                         / Z40000400/
      DATA PRODTB(   496) / 1073742848/
C                         /ZAAAA/ + 4764
      DATA PRODTB(   497) /-1431694692/
C                         / Z40001800/
      DATA PRODTB(   498) / 1073747968/
C                         /ZAAAA/ + 4776
      DATA PRODTB(   499) /-1431694680/
C                         / Z40010000/
      DATA PRODTB(   500) / 1073807360/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   501) /-1431694668/
C                         / Z40000020/
      DATA PRODTB(   502) / 1073741856/
C                         /ZAAAA/ + 4908
      DATA PRODTB(   503) /-1431694548/
C                         /ZAAAA/ + 1296
      DATA PRODTB(   504) /-1431698160/
C                         / Z040A0002/
      DATA PRODTB(   505) /   67764226/
C                         /ZAAAA/ + 1352
      DATA PRODTB(   506) /-1431698104/
C                         /ZAAAA/ + 1324
      DATA PRODTB(   507) /-1431698132/
C                         / Z04030072/
      DATA PRODTB(   508) /   67305586/
C                         /ZAAAA/ + 1420
      DATA PRODTB(   509) /-1431698036/
C                         /ZAAAA/ + 1408
      DATA PRODTB(   510) /-1431698048/
C                         / Z040A0002/
      DATA PRODTB(   511) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   512) / -859045880/
C                         / Z04000400/
      DATA PRODTB(   513) /   67109888/
C                         /ZAAAA/ + 1468
      DATA PRODTB(   514) /-1431697988/
C                         / Z04000200/
      DATA PRODTB(   515) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   516) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   517) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   518) / 1073774592/
C                         /ZAAAA/ + 1808
      DATA PRODTB(   519) /-1431697648/
C                         / Z40020000/
      DATA PRODTB(   520) / 1073872896/
C                         /ZAAAA/ + 1828
      DATA PRODTB(   521) /-1431697628/
C                         / Z00180000/
      DATA PRODTB(   522) /    1572864/
C                         /ZCCCC/ +    5
      DATA PRODTB(   523) / -859045883/
C                         / Z40002000/
      DATA PRODTB(   524) / 1073750016/
C                         /ZAAAA/ + 1848
      DATA PRODTB(   525) /-1431697608/
C                         /ZCCCC/ +   28
      DATA PRODTB(   526) / -859045860/
C                         / Z04047E79/
      DATA PRODTB(   527) /   67403385/
C                         /ZCCCC/ +   16
      DATA PRODTB(   528) / -859045872/
C                         / Z040B8082/
      DATA PRODTB(   529) /   67862658/
C                         /ZAAAA/ + 4812
      DATA PRODTB(   530) /-1431694644/
C                         /ZCCCC/ +   28
      DATA PRODTB(   531) / -859045860/
C                         / Z04038000/
      DATA PRODTB(   532) /   67338240/
C                         /ZCCCC/ +   29
      DATA PRODTB(   533) / -859045859/
C                         / Z04001000/
      DATA PRODTB(   534) /   67112960/
C                         /ZCCCC/ +   17
      DATA PRODTB(   535) / -859045871/
C                         /ZCCCC/ +   28
      DATA PRODTB(   536) / -859045860/
C                         / Z04000400/
      DATA PRODTB(   537) /   67109888/
C                         /ZAAAA/ + 1468
      DATA PRODTB(   538) /-1431697988/
C                         / Z04000200/
      DATA PRODTB(   539) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   540) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   541) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   542) / 1073774592/
C                         /ZAAAA/ + 1808
      DATA PRODTB(   543) /-1431697648/
C                         / Z40020000/
      DATA PRODTB(   544) / 1073872896/
C                         /ZAAAA/ + 1828
      DATA PRODTB(   545) /-1431697628/
C                         / Z40002000/
      DATA PRODTB(   546) / 1073750016/
C                         /ZAAAA/ + 1896
      DATA PRODTB(   547) /-1431697560/
C                         /ZCCCC/ +   28
      DATA PRODTB(   548) / -859045860/
C                         / Z04000400/
      DATA PRODTB(   549) /   67109888/
C                         /ZAAAA/ + 1468
      DATA PRODTB(   550) /-1431697988/
C                         / Z04000200/
      DATA PRODTB(   551) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   552) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   553) / -859045860/
C                         / Z00180000/
      DATA PRODTB(   554) /    1572864/
C                         /ZCCCC/ +    5
      DATA PRODTB(   555) / -859045883/
C                         / Z40008000/
      DATA PRODTB(   556) / 1073774592/
C                         /ZAAAA/ + 4712
      DATA PRODTB(   557) /-1431694744/
C                         /ZCCCC/ +   28
      DATA PRODTB(   558) / -859045860/
C                         / Z00180000/
      DATA PRODTB(   559) /    1572864/
C                         /ZCCCC/ +    7
      DATA PRODTB(   560) / -859045881/
C                         /ZAAAA/ + 1924
      DATA PRODTB(   561) /-1431697532/
C                         / Z40008000/
      DATA PRODTB(   562) / 1073774592/
C                         /ZAAAA/ + 1808
      DATA PRODTB(   563) /-1431697648/
C                         /ZCCCC/ +   28
      DATA PRODTB(   564) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   565) / 1073774592/
C                         /ZAAAA/ + 1980
      DATA PRODTB(   566) /-1431697476/
C                         / Z40002000/
      DATA PRODTB(   567) / 1073750016/
C                         /ZAAAA/ + 2000
      DATA PRODTB(   568) /-1431697456/
C                         /ZCCCC/ +   28
      DATA PRODTB(   569) / -859045860/
C                         / Z040DFEF9/
      DATA PRODTB(   570) /   68026105/
C                         /ZCCCC/ +   16
      DATA PRODTB(   571) / -859045872/
C                         / Z04020002/
      DATA PRODTB(   572) /   67239938/
C                         /ZAAAA/ + 4920
      DATA PRODTB(   573) /-1431694536/
C                         /ZCCCC/ +   28
      DATA PRODTB(   574) / -859045860/
C                         / Z04000400/
      DATA PRODTB(   575) /   67109888/
C                         /ZAAAA/ + 2020
      DATA PRODTB(   576) /-1431697436/
C                         / Z04000200/
      DATA PRODTB(   577) /   67109376/
C                         /ZAAAA/ + 1488
      DATA PRODTB(   578) /-1431697968/
C                         /ZCCCC/ +   28
      DATA PRODTB(   579) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   580) / 1073872896/
C                         /ZCCCC/ +   46
      DATA PRODTB(   581) / -859045842/
C                         / Z40004000/
      DATA PRODTB(   582) / 1073758208/
C                         /ZAAAA/ + 4936
      DATA PRODTB(   583) /-1431694520/
C                         /ZCCCC/ +   28
      DATA PRODTB(   584) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   585) / 1073774592/
C                         /ZAAAA/ + 1808
      DATA PRODTB(   586) /-1431697648/
C                         / Z00180000/
      DATA PRODTB(   587) /    1572864/
C                         /ZCCCC/ +    5
      DATA PRODTB(   588) / -859045883/
C                         /ZCCCC/ +   28
      DATA PRODTB(   589) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   590) / 1073774592/
C                         /ZAAAA/ + 2240
      DATA PRODTB(   591) /-1431697216/
C                         / Z00480000/
      DATA PRODTB(   592) /    4718592/
C                         /ZAAAA/ + 2260
      DATA PRODTB(   593) /-1431697196/
C                         / Z04020000/
      DATA PRODTB(   594) /   67239936/
C                         /ZAAAA/ + 2324
      DATA PRODTB(   595) /-1431697132/
C                         / Z04000002/
      DATA PRODTB(   596) /   67108866/
C                         /ZAAAA/ + 2644
      DATA PRODTB(   597) /-1431696812/
C                         / Z04080000/
      DATA PRODTB(   598) /   67633152/
C                         /ZAAAA/ + 2860
      DATA PRODTB(   599) /-1431696596/
C                         / Z04010000/
      DATA PRODTB(   600) /   67174400/
C                         /ZAAAA/ + 3152
      DATA PRODTB(   601) /-1431696304/
C                         / Z04008000/
      DATA PRODTB(   602) /   67141632/
C                         /ZAAAA/ + 3300
      DATA PRODTB(   603) /-1431696156/
C                         / Z04006000/
      DATA PRODTB(   604) /   67133440/
C                         /ZAAAA/ + 3392
      DATA PRODTB(   605) /-1431696064/
C                         / Z04001000/
      DATA PRODTB(   606) /   67112960/
C                         /ZAAAA/ + 3472
      DATA PRODTB(   607) /-1431695984/
C                         / Z04000800/
      DATA PRODTB(   608) /   67110912/
C                         /ZAAAA/ + 3536
      DATA PRODTB(   609) /-1431695920/
C                         / Z04000400/
      DATA PRODTB(   610) /   67109888/
C                         /ZAAAA/ + 3628
      DATA PRODTB(   611) /-1431695828/
C                         / Z04000200/
      DATA PRODTB(   612) /   67109376/
C                         /ZAAAA/ + 3700
      DATA PRODTB(   613) /-1431695756/
C                         / Z04000080/
      DATA PRODTB(   614) /   67108992/
C                         /ZAAAA/ + 3744
      DATA PRODTB(   615) /-1431695712/
C                         / Z04000040/
      DATA PRODTB(   616) /   67108928/
C                         /ZAAAA/ + 3816
      DATA PRODTB(   617) /-1431695640/
C                         / Z04000020/
      DATA PRODTB(   618) /   67108896/
C                         /ZAAAA/ + 3912
      DATA PRODTB(   619) /-1431695544/
C                         / Z04000010/
      DATA PRODTB(   620) /   67108880/
C                         /ZAAAA/ + 4008
      DATA PRODTB(   621) /-1431695448/
C                         / Z00180000/
      DATA PRODTB(   622) /    1572864/
C                         /ZCCCC/ +    6
      DATA PRODTB(   623) / -859045882/
C                         / Z04000008/
      DATA PRODTB(   624) /   67108872/
C                         /ZAAAA/ + 4080
      DATA PRODTB(   625) /-1431695376/
C                         / Z04000001/
      DATA PRODTB(   626) /   67108865/
C                         /ZAAAA/ + 4116
      DATA PRODTB(   627) /-1431695340/
C                         / Z04000004/
      DATA PRODTB(   628) /   67108868/
C                         /ZAAAA/ + 4128
      DATA PRODTB(   629) /-1431695328/
C                         / Z04040000/
      DATA PRODTB(   630) /   67371008/
C                         /ZAAAA/ + 4172
      DATA PRODTB(   631) /-1431695284/
C                         / Z40002000/
      DATA PRODTB(   632) / 1073750016/
C                         /ZAAAA/ + 4952
      DATA PRODTB(   633) /-1431694504/
C                         /ZCCCC/ +   28
      DATA PRODTB(   634) / -859045860/
C                         / Z04000080/
      DATA PRODTB(   635) /   67108992/
C                         /ZCCCC/ +   42
      DATA PRODTB(   636) / -859045846/
C                         / Z04020002/
      DATA PRODTB(   637) /   67239938/
C                         /ZAAAA/ + 4976
      DATA PRODTB(   638) /-1431694480/
C                         /ZCCCC/ +   28
      DATA PRODTB(   639) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(   640) /   67764226/
C                         /ZAAAA/ + 2280
      DATA PRODTB(   641) /-1431697176/
C                         / Z04018000/
      DATA PRODTB(   642) /   67207168/
C                         /ZAAAA/ + 2312
      DATA PRODTB(   643) /-1431697144/
C                         /ZCCCC/ +   28
      DATA PRODTB(   644) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   645) / 1073872896/
C                         /ZAAAA/ + 2292
      DATA PRODTB(   646) /-1431697164/
C                         /ZCCCC/ +   28
      DATA PRODTB(   647) / -859045860/
C                         / Z04018000/
      DATA PRODTB(   648) /   67207168/
C                         /ZCCCC/ +    4
      DATA PRODTB(   649) / -859045884/
C                         / Z04020000/
      DATA PRODTB(   650) /   67239936/
C                         /ZAAAA/ + 5000
      DATA PRODTB(   651) /-1431694456/
C                         /ZCCCC/ +   28
      DATA PRODTB(   652) / -859045860/
C                         / Z40020000/
      DATA PRODTB(   653) / 1073872896/
C                         /ZAAAA/ + 2300
      DATA PRODTB(   654) /-1431697156/
C                         /ZCCCC/ +   28
      DATA PRODTB(   655) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   656) / 1073774592/
C                         /ZAAAA/ + 2352
      DATA PRODTB(   657) /-1431697104/
C                         / Z40004000/
      DATA PRODTB(   658) / 1073758208/
C                         /ZAAAA/ + 2456
      DATA PRODTB(   659) /-1431697000/
C                         / Z40002000/
      DATA PRODTB(   660) / 1073750016/
C                         /ZAAAA/ + 2572
      DATA PRODTB(   661) /-1431696884/
C                         /ZAAAA/ + 1256
      DATA PRODTB(   662) /-1431698200/
C                         / Z04020002/
      DATA PRODTB(   663) /   67239938/
C                         /ZAAAA/ + 2388
      DATA PRODTB(   664) /-1431697068/
C                         / Z04080000/
      DATA PRODTB(   665) /   67633152/
C                         /ZAAAA/ + 2436
      DATA PRODTB(   666) /-1431697020/
C                         / Z04047E78/
      DATA PRODTB(   667) /   67403384/
C                         /ZCCCC/ +   16
      DATA PRODTB(   668) / -859045872/
C                         / Z04000001/
      DATA PRODTB(   669) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(   670) /-1431694424/
C                         /ZAAAA/ + 1332
      DATA PRODTB(   671) /-1431698124/
C                         / Z40002000/
      DATA PRODTB(   672) / 1073750016/
C                         /ZAAAA/ + 2416
      DATA PRODTB(   673) /-1431697040/
C                         / Z40008000/
      DATA PRODTB(   674) / 1073774592/
C                         /ZAAAA/ + 5044
      DATA PRODTB(   675) /-1431694412/
C                         / Z40004000/
      DATA PRODTB(   676) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   677) /-1431694404/
C                         /ZCCCC/ +   16
      DATA PRODTB(   678) / -859045872/
C                         / Z04000200/
      DATA PRODTB(   679) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(   680) / -859045786/
C                         / Z04000400/
      DATA PRODTB(   681) /   67109888/
C                         /ZAAAA/ + 5092
      DATA PRODTB(   682) /-1431694364/
C                         /ZCCCC/ +   16
      DATA PRODTB(   683) / -859045872/
C                         / Z40008000/
      DATA PRODTB(   684) / 1073774592/
C                         /ZAAAA/ + 5044
      DATA PRODTB(   685) /-1431694412/
C                         / Z40004000/
      DATA PRODTB(   686) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   687) /-1431694404/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   688) /-1431698096/
C                         / Z04030070/
      DATA PRODTB(   689) /   67305584/
C                         /ZAAAA/ + 2484
      DATA PRODTB(   690) /-1431696972/
C                         / Z04000002/
      DATA PRODTB(   691) /   67108866/
C                         /ZAAAA/ + 2540
      DATA PRODTB(   692) /-1431696916/
C                         / Z0400FE00/
      DATA PRODTB(   693) /   67173888/
C                         /ZAAAA/ + 2560
      DATA PRODTB(   694) /-1431696896/
C                         /ZAAAA/ + 1408
      DATA PRODTB(   695) /-1431698048/
C                         / Z40008000/
      DATA PRODTB(   696) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   697) /-1431696936/
C                         / Z40004000/
      DATA PRODTB(   698) / 1073758208/
C                         /ZCCCC/ +   23
      DATA PRODTB(   699) / -859045865/
C                         / Z00180000/
      DATA PRODTB(   700) /    1572864/
C                         /ZCCCC/ +   24
      DATA PRODTB(   701) / -859045864/
C                         / Z40002000/
      DATA PRODTB(   702) / 1073750016/
C                         /ZAAAA/ + 5108
      DATA PRODTB(   703) /-1431694348/
C                         /ZCCCC/ +   28
      DATA PRODTB(   704) / -859045860/
C                         / Z04000005/
      DATA PRODTB(   705) /   67108869/
C                         /ZCCCC/ +   51
      DATA PRODTB(   706) / -859045837/
C                         / Z04010070/
      DATA PRODTB(   707) /   67174512/
C                         /ZAAAA/ + 5120
      DATA PRODTB(   708) /-1431694336/
C                         /ZCCCC/ +   28
      DATA PRODTB(   709) / -859045860/
C                         / Z40004000/
      DATA PRODTB(   710) / 1073758208/
C                         /ZCCCC/ +   23
      DATA PRODTB(   711) / -859045865/
C                         / Z00180000/
      DATA PRODTB(   712) /    1572864/
C                         /ZCCCC/ +   24
      DATA PRODTB(   713) / -859045864/
C                         /ZCCCC/ +   28
      DATA PRODTB(   714) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   715) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   716) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   717) /-1431696948/
C                         / Z040A0002/
      DATA PRODTB(   718) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   719) / -859045880/
C                         / Z04000400/
      DATA PRODTB(   720) /   67109888/
C                         /ZAAAA/ + 2624
      DATA PRODTB(   721) /-1431696832/
C                         / Z04000200/
      DATA PRODTB(   722) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(   723) /-1431694316/
C                         / Z04000800/
      DATA PRODTB(   724) /   67110912/
C                         /ZAAAA/ + 5164
      DATA PRODTB(   725) /-1431694292/
C                         / Z04000001/
      DATA PRODTB(   726) /   67108865/
C                         /ZAAAA/ + 5180
      DATA PRODTB(   727) /-1431694276/
C                         / Z04000080/
      DATA PRODTB(   728) /   67108992/
C                         /ZAAAA/ + 5192
      DATA PRODTB(   729) /-1431694264/
C                         /ZCCCC/ +   28
      DATA PRODTB(   730) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   731) / 1073774592/
C                         /ZAAAA/ + 5204
      DATA PRODTB(   732) /-1431694252/
C                         / Z40004000/
      DATA PRODTB(   733) / 1073758208/
C                         /ZAAAA/ + 5224
      DATA PRODTB(   734) /-1431694232/
C                         /ZCCCC/ +   28
      DATA PRODTB(   735) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   736) / 1073774592/
C                         /ZAAAA/ + 2720
      DATA PRODTB(   737) /-1431696736/
C                         / Z40004000/
      DATA PRODTB(   738) / 1073758208/
C                         /ZAAAA/ + 2772
      DATA PRODTB(   739) /-1431696684/
C                         / Z40002000/
      DATA PRODTB(   740) / 1073750016/
C                         /ZAAAA/ + 2824
      DATA PRODTB(   741) /-1431696632/
C                         / Z40000200/
      DATA PRODTB(   742) / 1073742336/
C                         /ZCCCC/ +   75
      DATA PRODTB(   743) / -859045813/
C                         / Z40000180/
      DATA PRODTB(   744) / 1073742208/
C                         /ZAAAA/ + 4752
      DATA PRODTB(   745) /-1431694704/
C                         / Z40000400/
      DATA PRODTB(   746) / 1073742848/
C                         /ZAAAA/ + 4764
      DATA PRODTB(   747) /-1431694692/
C                         / Z40001800/
      DATA PRODTB(   748) / 1073747968/
C                         /ZAAAA/ + 4776
      DATA PRODTB(   749) /-1431694680/
C                         / Z40010000/
      DATA PRODTB(   750) / 1073807360/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   751) /-1431694668/
C                         / Z40000020/
      DATA PRODTB(   752) / 1073741856/
C                         /ZAAAA/ + 4908
      DATA PRODTB(   753) /-1431694548/
C                         /ZAAAA/ + 1296
      DATA PRODTB(   754) /-1431698160/
C                         / Z04020002/
      DATA PRODTB(   755) /   67239938/
C                         /ZAAAA/ + 2740
      DATA PRODTB(   756) /-1431696716/
C                         / Z04080000/
      DATA PRODTB(   757) /   67633152/
C                         /ZAAAA/ + 2752
      DATA PRODTB(   758) /-1431696704/
C                         /ZAAAA/ + 1324
      DATA PRODTB(   759) /-1431698132/
C                         / Z40002000/
      DATA PRODTB(   760) / 1073750016/
C                         /ZAAAA/ + 2416
      DATA PRODTB(   761) /-1431697040/
C                         /ZAAAA/ + 2396
      DATA PRODTB(   762) /-1431697060/
C                         / Z40008000/
      DATA PRODTB(   763) / 1073774592/
C                         /ZAAAA/ + 5044
      DATA PRODTB(   764) /-1431694412/
C                         / Z40004000/
      DATA PRODTB(   765) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   766) /-1431694404/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   767) /-1431698096/
C                         / Z04030070/
      DATA PRODTB(   768) /   67305584/
C                         /ZAAAA/ + 2800
      DATA PRODTB(   769) /-1431696656/
C                         / Z04000002/
      DATA PRODTB(   770) /   67108866/
C                         /ZAAAA/ + 2540
      DATA PRODTB(   771) /-1431696916/
C                         / Z0400FE00/
      DATA PRODTB(   772) /   67173888/
C                         /ZAAAA/ + 2812
      DATA PRODTB(   773) /-1431696644/
C                         /ZAAAA/ + 1408
      DATA PRODTB(   774) /-1431698048/
C                         / Z40008000/
      DATA PRODTB(   775) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   776) /-1431696936/
C                         /ZAAAA/ + 2492
      DATA PRODTB(   777) /-1431696964/
C                         / Z40008000/
      DATA PRODTB(   778) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   779) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   780) /-1431696948/
C                         / Z040A0002/
      DATA PRODTB(   781) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   782) / -859045880/
C                         / Z04000400/
      DATA PRODTB(   783) /   67109888/
C                         /ZAAAA/ + 2624
      DATA PRODTB(   784) /-1431696832/
C                         / Z04000200/
      DATA PRODTB(   785) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(   786) /-1431694316/
C                         / Z04000800/
      DATA PRODTB(   787) /   67110912/
C                         /ZAAAA/ + 5164
      DATA PRODTB(   788) /-1431694292/
C                         /ZCCCC/ +   28
      DATA PRODTB(   789) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   790) / 1073774592/
C                         /ZAAAA/ + 2920
      DATA PRODTB(   791) /-1431696536/
C                         / Z40004000/
      DATA PRODTB(   792) / 1073758208/
C                         /ZAAAA/ + 3072
      DATA PRODTB(   793) /-1431696384/
C                         / Z40002000/
      DATA PRODTB(   794) / 1073750016/
C                         /ZAAAA/ + 3124
      DATA PRODTB(   795) /-1431696332/
C                         / Z40000400/
      DATA PRODTB(   796) / 1073742848/
C                         /ZAAAA/ + 4764
      DATA PRODTB(   797) /-1431694692/
C                         / Z40001800/
      DATA PRODTB(   798) / 1073747968/
C                         /ZAAAA/ + 4776
      DATA PRODTB(   799) /-1431694680/
C                         / Z40010000/
      DATA PRODTB(   800) / 1073807360/
C                         /ZAAAA/ + 4788
      DATA PRODTB(   801) /-1431694668/
C                         / Z40000020/
      DATA PRODTB(   802) / 1073741856/
C                         /ZAAAA/ + 4908
      DATA PRODTB(   803) /-1431694548/
C                         /ZAAAA/ + 1296
      DATA PRODTB(   804) /-1431698160/
C                         / Z04020002/
      DATA PRODTB(   805) /   67239938/
C                         /ZAAAA/ + 2972
      DATA PRODTB(   806) /-1431696484/
C                         / Z04080000/
      DATA PRODTB(   807) /   67633152/
C                         /ZAAAA/ + 2992
      DATA PRODTB(   808) /-1431696464/
C                         / Z04010000/
      DATA PRODTB(   809) /   67174400/
C                         /ZAAAA/ + 3060
      DATA PRODTB(   810) /-1431696396/
C                         / Z04041E09/
      DATA PRODTB(   811) /   67378697/
C                         /ZCCCC/ +   16
      DATA PRODTB(   812) / -859045872/
C                         / Z04006070/
      DATA PRODTB(   813) /   67133552/
C                         /ZAAAA/ + 5240
      DATA PRODTB(   814) /-1431694216/
C                         / Z04008000/
      DATA PRODTB(   815) /   67141632/
C                         /ZAAAA/ + 4812
      DATA PRODTB(   816) /-1431694644/
C                         /ZAAAA/ + 1340
      DATA PRODTB(   817) /-1431698116/
C                         / Z40008000/
      DATA PRODTB(   818) / 1073774592/
C                         /ZAAAA/ + 5044
      DATA PRODTB(   819) /-1431694412/
C                         / Z40004000/
      DATA PRODTB(   820) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   821) /-1431694404/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   822) /-1431698096/
C                         / Z40008000/
      DATA PRODTB(   823) / 1073774592/
C                         /ZAAAA/ + 3012
      DATA PRODTB(   824) /-1431696444/
C                         / Z40004000/
      DATA PRODTB(   825) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   826) /-1431694404/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   827) /-1431698096/
C                         / Z04080000/
      DATA PRODTB(   828) /   67633152/
C                         /ZAAAA/ + 3040
      DATA PRODTB(   829) /-1431696416/
C                         / Z04016070/
      DATA PRODTB(   830) /   67199088/
C                         /ZAAAA/ + 5248
      DATA PRODTB(   831) /-1431694208/
C                         / Z04020002/
      DATA PRODTB(   832) /   67239938/
C                         /ZAAAA/ + 5048
      DATA PRODTB(   833) /-1431694408/
C                         /ZCCCC/ +   16
      DATA PRODTB(   834) / -859045872/
C                         / Z00480000/
      DATA PRODTB(   835) /    4718592/
C                         /ZAAAA/ + 5252
      DATA PRODTB(   836) /-1431694204/
C                         / Z40004000/
      DATA PRODTB(   837) / 1073758208/
C                         /ZAAAA/ + 5052
      DATA PRODTB(   838) /-1431694404/
C                         /ZCCCC/ +   16
      DATA PRODTB(   839) / -859045872/
C                         / Z40008000/
      DATA PRODTB(   840) / 1073774592/
C                         /ZAAAA/ + 5244
      DATA PRODTB(   841) /-1431694212/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   842) /-1431698096/
C                         / Z04030070/
      DATA PRODTB(   843) /   67305584/
C                         /ZAAAA/ + 3100
      DATA PRODTB(   844) /-1431696356/
C                         / Z04000002/
      DATA PRODTB(   845) /   67108866/
C                         /ZAAAA/ + 2540
      DATA PRODTB(   846) /-1431696916/
C                         / Z0400FE00/
      DATA PRODTB(   847) /   67173888/
C                         /ZAAAA/ + 3112
      DATA PRODTB(   848) /-1431696344/
C                         /ZAAAA/ + 1408
      DATA PRODTB(   849) /-1431698048/
C                         / Z40008000/
      DATA PRODTB(   850) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   851) /-1431696936/
C                         /ZAAAA/ + 2492
      DATA PRODTB(   852) /-1431696964/
C                         / Z40008000/
      DATA PRODTB(   853) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   854) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   855) /-1431696948/
C                         / Z040A0002/
      DATA PRODTB(   856) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(   857) / -859045880/
C                         / Z04000200/
      DATA PRODTB(   858) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(   859) /-1431694316/
C                         / Z04000400/
      DATA PRODTB(   860) /   67109888/
C                         /ZAAAA/ + 5220
      DATA PRODTB(   861) /-1431694236/
C                         /ZAAAA/ + 2848
      DATA PRODTB(   862) /-1431696608/
C                         / Z40008000/
      DATA PRODTB(   863) / 1073774592/
C                         /ZAAAA/ + 3180
      DATA PRODTB(   864) /-1431696276/
C                         / Z40004000/
      DATA PRODTB(   865) / 1073758208/
C                         /ZAAAA/ + 3256
      DATA PRODTB(   866) /-1431696200/
C                         / Z40002000/
      DATA PRODTB(   867) / 1073750016/
C                         /ZAAAA/ + 3280
      DATA PRODTB(   868) /-1431696176/
C                         /ZCCCC/ +   28
      DATA PRODTB(   869) / -859045860/
C                         / Z04020002/
      DATA PRODTB(   870) /   67239938/
C                         /ZAAAA/ + 3232
      DATA PRODTB(   871) /-1431696224/
C                         / Z04090000/
      DATA PRODTB(   872) /   67698688/
C                         /ZAAAA/ + 3244
      DATA PRODTB(   873) /-1431696212/
C                         / Z04041E08/
      DATA PRODTB(   874) /   67378696/
C                         /ZCCCC/ +   16
      DATA PRODTB(   875) / -859045872/
C                         / Z04006070/
      DATA PRODTB(   876) /   67133552/
C                         /ZAAAA/ + 5240
      DATA PRODTB(   877) /-1431694216/
C                         / Z04000001/
      DATA PRODTB(   878) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(   879) /-1431694424/
C                         / Z04008080/
      DATA PRODTB(   880) /   67141760/
C                         /ZAAAA/ + 4812
      DATA PRODTB(   881) /-1431694644/
C                         /ZCCCC/ +   28
      DATA PRODTB(   882) / -859045860/
C                         / Z40002000/
      DATA PRODTB(   883) / 1073750016/
C                         /ZAAAA/ + 2416
      DATA PRODTB(   884) /-1431697040/
C                         /ZCCCC/ +   16
      DATA PRODTB(   885) / -859045872/
C                         / Z40008000/
      DATA PRODTB(   886) / 1073774592/
C                         /ZAAAA/ + 5244
      DATA PRODTB(   887) /-1431694212/
C                         /ZAAAA/ + 1360
      DATA PRODTB(   888) /-1431698096/
C                         / Z0403FE70/
      DATA PRODTB(   889) /   67370608/
C                         /ZAAAA/ + 3268
      DATA PRODTB(   890) /-1431696188/
C                         /ZCCCC/ +   28
      DATA PRODTB(   891) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   892) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   893) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   894) /-1431696948/
C                         / Z04000200/
      DATA PRODTB(   895) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(   896) /-1431694316/
C                         / Z04000400/
      DATA PRODTB(   897) /   67109888/
C                         /ZAAAA/ + 5220
      DATA PRODTB(   898) /-1431694236/
C                         /ZAAAA/ + 2596
      DATA PRODTB(   899) /-1431696860/
C                         / Z40008000/
      DATA PRODTB(   900) / 1073774592/
C                         /ZAAAA/ + 3328
      DATA PRODTB(   901) /-1431696128/
C                         / Z40004000/
      DATA PRODTB(   902) / 1073758208/
C                         /ZAAAA/ + 3348
      DATA PRODTB(   903) /-1431696108/
C                         / Z40002000/
      DATA PRODTB(   904) / 1073750016/
C                         /ZAAAA/ + 3372
      DATA PRODTB(   905) /-1431696084/
C                         /ZCCCC/ +   28
      DATA PRODTB(   906) / -859045860/
C                         / Z04047E78/
      DATA PRODTB(   907) /   67403384/
C                         /ZCCCC/ +   16
      DATA PRODTB(   908) / -859045872/
C                         / Z04000001/
      DATA PRODTB(   909) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(   910) /-1431694424/
C                         /ZAAAA/ + 1816
      DATA PRODTB(   911) /-1431697640/
C                         / Z0403FE70/
      DATA PRODTB(   912) /   67370608/
C                         /ZAAAA/ + 3360
      DATA PRODTB(   913) /-1431696096/
C                         /ZCCCC/ +   28
      DATA PRODTB(   914) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   915) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   916) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   917) /-1431696948/
C                         / Z04000200/
      DATA PRODTB(   918) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(   919) /-1431694316/
C                         / Z04000400/
      DATA PRODTB(   920) /   67109888/
C                         /ZAAAA/ + 5220
      DATA PRODTB(   921) /-1431694236/
C                         /ZAAAA/ + 2596
      DATA PRODTB(   922) /-1431696860/
C                         / Z40008000/
      DATA PRODTB(   923) / 1073774592/
C                         /ZAAAA/ + 3420
      DATA PRODTB(   924) /-1431696036/
C                         / Z40004000/
      DATA PRODTB(   925) / 1073758208/
C                         /ZAAAA/ + 3448
      DATA PRODTB(   926) /-1431696008/
C                         / Z40002000/
      DATA PRODTB(   927) / 1073750016/
C                         /ZAAAA/ + 2596
      DATA PRODTB(   928) /-1431696860/
C                         /ZCCCC/ +   28
      DATA PRODTB(   929) / -859045860/
C                         / Z04069E8A/
      DATA PRODTB(   930) /   67542666/
C                         /ZCCCC/ +   16
      DATA PRODTB(   931) / -859045872/
C                         / Z04096070/
      DATA PRODTB(   932) /   67723376/
C                         /ZAAAA/ + 5240
      DATA PRODTB(   933) /-1431694216/
C                         / Z04000001/
      DATA PRODTB(   934) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(   935) /-1431694424/
C                         /ZCCCC/ +   28
      DATA PRODTB(   936) / -859045860/
C                         / Z0403FE70/
      DATA PRODTB(   937) /   67370608/
C                         /ZAAAA/ + 3460
      DATA PRODTB(   938) /-1431695996/
C                         /ZCCCC/ +   28
      DATA PRODTB(   939) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   940) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   941) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   942) /-1431696948/
C                         / Z40008000/
      DATA PRODTB(   943) / 1073774592/
C                         /ZAAAA/ + 3500
      DATA PRODTB(   944) /-1431695956/
C                         / Z40004000/
      DATA PRODTB(   945) / 1073758208/
C                         /ZAAAA/ + 3512
      DATA PRODTB(   946) /-1431695944/
C                         / Z40002000/
      DATA PRODTB(   947) / 1073750016/
C                         /ZAAAA/ + 5176
      DATA PRODTB(   948) /-1431694280/
C                         /ZCCCC/ +   28
      DATA PRODTB(   949) / -859045860/
C                         / Z040FFEFA/
      DATA PRODTB(   950) /   68157178/
C                         /ZCCCC/ +   16
      DATA PRODTB(   951) / -859045872/
C                         /ZAAAA/ + 3436
      DATA PRODTB(   952) /-1431696020/
C                         / Z0403FE70/
      DATA PRODTB(   953) /   67370608/
C                         /ZAAAA/ + 3524
      DATA PRODTB(   954) /-1431695932/
C                         /ZCCCC/ +   28
      DATA PRODTB(   955) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   956) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   957) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   958) /-1431696948/
C                         / Z40008000/
      DATA PRODTB(   959) / 1073774592/
C                         /ZAAAA/ + 3572
      DATA PRODTB(   960) /-1431695884/
C                         / Z40004000/
      DATA PRODTB(   961) / 1073758208/
C                         /ZAAAA/ + 3584
      DATA PRODTB(   962) /-1431695872/
C                         / Z00180000/
      DATA PRODTB(   963) /    1572864/
C                         /ZCCCC/ +   26
      DATA PRODTB(   964) / -859045862/
C                         / Z40002000/
      DATA PRODTB(   965) / 1073750016/
C                         /ZAAAA/ + 3608
      DATA PRODTB(   966) /-1431695848/
C                         /ZCCCC/ +   28
      DATA PRODTB(   967) / -859045860/
C                         / Z040FFEFA/
      DATA PRODTB(   968) /   68157178/
C                         /ZCCCC/ +   16
      DATA PRODTB(   969) / -859045872/
C                         /ZAAAA/ + 3436
      DATA PRODTB(   970) /-1431696020/
C                         / Z0403FE70/
      DATA PRODTB(   971) /   67370608/
C                         /ZAAAA/ + 3596
      DATA PRODTB(   972) /-1431695860/
C                         /ZCCCC/ +   28
      DATA PRODTB(   973) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   974) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   975) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   976) /-1431696948/
C                         / Z04000800/
      DATA PRODTB(   977) /   67110912/
C                         /ZAAAA/ + 5164
      DATA PRODTB(   978) /-1431694292/
C                         / Z04000001/
      DATA PRODTB(   979) /   67108865/
C                         /ZAAAA/ + 5180
      DATA PRODTB(   980) /-1431694276/
C                         /ZCCCC/ +   28
      DATA PRODTB(   981) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   982) / 1073774592/
C                         /ZAAAA/ + 3656
      DATA PRODTB(   983) /-1431695800/
C                         / Z40004000/
      DATA PRODTB(   984) / 1073758208/
C                         /ZAAAA/ + 3676
      DATA PRODTB(   985) /-1431695780/
C                         / Z40002000/
      DATA PRODTB(   986) / 1073750016/
C                         /ZAAAA/ + 3608
      DATA PRODTB(   987) /-1431695848/
C                         /ZCCCC/ +   28
      DATA PRODTB(   988) / -859045860/
C                         / Z04047E78/
      DATA PRODTB(   989) /   67403384/
C                         /ZCCCC/ +   16
      DATA PRODTB(   990) / -859045872/
C                         / Z04000001/
      DATA PRODTB(   991) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(   992) /-1431694424/
C                         /ZAAAA/ + 1816
      DATA PRODTB(   993) /-1431697640/
C                         / Z0403FE70/
      DATA PRODTB(   994) /   67370608/
C                         /ZAAAA/ + 3688
      DATA PRODTB(   995) /-1431695768/
C                         /ZCCCC/ +   28
      DATA PRODTB(   996) / -859045860/
C                         / Z40008000/
      DATA PRODTB(   997) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(   998) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(   999) /-1431696948/
C                         / Z40004000/
      DATA PRODTB(  1000) / 1073758208/
C                         /ZAAAA/ + 3720
      DATA PRODTB(  1001) /-1431695736/
C                         / Z40002000/
      DATA PRODTB(  1002) / 1073750016/
C                         /ZAAAA/ + 5160
      DATA PRODTB(  1003) /-1431694296/
C                         /ZAAAA/ + 1924
      DATA PRODTB(  1004) /-1431697532/
C                         / Z0403FE70/
      DATA PRODTB(  1005) /   67370608/
C                         /ZAAAA/ + 3732
      DATA PRODTB(  1006) /-1431695724/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1007) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1008) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1009) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1010) /-1431696948/
C                         / Z40008000/
      DATA PRODTB(  1011) / 1073774592/
C                         /ZAAAA/ + 1980
      DATA PRODTB(  1012) /-1431697476/
C                         / Z40004000/
      DATA PRODTB(  1013) / 1073758208/
C                         /ZAAAA/ + 3772
      DATA PRODTB(  1014) /-1431695684/
C                         / Z40002000/
      DATA PRODTB(  1015) / 1073750016/
C                         /ZAAAA/ + 3796
      DATA PRODTB(  1016) /-1431695660/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1017) / -859045860/
C                         / Z0403FE70/
      DATA PRODTB(  1018) /   67370608/
C                         /ZAAAA/ + 3784
      DATA PRODTB(  1019) /-1431695672/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1020) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1021) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1022) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1023) /-1431696948/
C                         / Z04000400/
      DATA PRODTB(  1024) /   67109888/
C                         /ZAAAA/ + 5276
      DATA PRODTB(  1025) /-1431694180/
C                         / Z04000200/
      DATA PRODTB(  1026) /   67109376/
C                         /ZAAAA/ + 5140
      DATA PRODTB(  1027) /-1431694316/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1028) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1029) / 1073774592/
C                         /ZAAAA/ + 3852
      DATA PRODTB(  1030) /-1431695604/
C                         / Z40004000/
      DATA PRODTB(  1031) / 1073758208/
C                         /ZAAAA/ + 3888
      DATA PRODTB(  1032) /-1431695568/
C                         / Z00180000/
      DATA PRODTB(  1033) /    1572864/
C                         /ZCCCC/ +    2
      DATA PRODTB(  1034) / -859045886/
C                         / Z40002000/
      DATA PRODTB(  1035) / 1073750016/
C                         /ZAAAA/ + 3608
      DATA PRODTB(  1036) /-1431695848/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1037) / -859045860/
C                         / Z04049E88/
      DATA PRODTB(  1038) /   67411592/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1039) / -859045872/
C                         / Z04096070/
      DATA PRODTB(  1040) /   67723376/
C                         /ZAAAA/ + 5240
      DATA PRODTB(  1041) /-1431694216/
C                         / Z04000001/
      DATA PRODTB(  1042) /   67108865/
C                         /ZAAAA/ + 5032
      DATA PRODTB(  1043) /-1431694424/
C                         / Z04020002/
      DATA PRODTB(  1044) /   67239938/
C                         /ZAAAA/ + 5084
      DATA PRODTB(  1045) /-1431694372/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1046) / -859045860/
C                         / Z0403FE70/
      DATA PRODTB(  1047) /   67370608/
C                         /ZAAAA/ + 3900
      DATA PRODTB(  1048) /-1431695556/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1049) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1050) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1051) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1052) /-1431696948/
C                         / Z40008000/
      DATA PRODTB(  1053) / 1073774592/
C                         /ZAAAA/ + 3940
      DATA PRODTB(  1054) /-1431695516/
C                         / Z40004000/
      DATA PRODTB(  1055) / 1073758208/
C                         /ZAAAA/ + 3984
      DATA PRODTB(  1056) /-1431695472/
C                         / Z40002000/
      DATA PRODTB(  1057) / 1073750016/
C                         /ZAAAA/ + 3608
      DATA PRODTB(  1058) /-1431695848/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1059) / -859045860/
C                         / Z04020002/
      DATA PRODTB(  1060) /   67239938/
C                         /ZAAAA/ + 3960
      DATA PRODTB(  1061) /-1431695496/
C                         / Z04090000/
      DATA PRODTB(  1062) /   67698688/
C                         /ZAAAA/ + 3972
      DATA PRODTB(  1063) /-1431695484/
C                         /ZAAAA/ + 3196
      DATA PRODTB(  1064) /-1431696260/
C                         / Z40002000/
      DATA PRODTB(  1065) / 1073750016/
C                         /ZAAAA/ + 2416
      DATA PRODTB(  1066) /-1431697040/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1067) / -859045872/
C                         / Z40008000/
      DATA PRODTB(  1068) / 1073774592/
C                         /ZAAAA/ + 5244
      DATA PRODTB(  1069) /-1431694212/
C                         /ZAAAA/ + 1360
      DATA PRODTB(  1070) /-1431698096/
C                         / Z0403FE70/
      DATA PRODTB(  1071) /   67370608/
C                         /ZAAAA/ + 3996
      DATA PRODTB(  1072) /-1431695460/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1073) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1074) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1075) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1076) /-1431696948/
C                         / Z40008000/
      DATA PRODTB(  1077) / 1073774592/
C                         /ZAAAA/ + 4036
      DATA PRODTB(  1078) /-1431695420/
C                         / Z40004000/
      DATA PRODTB(  1079) / 1073758208/
C                         /ZAAAA/ + 4056
      DATA PRODTB(  1080) /-1431695400/
C                         / Z40002000/
      DATA PRODTB(  1081) / 1073750016/
C                         /ZAAAA/ + 5160
      DATA PRODTB(  1082) /-1431694296/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1083) / -859045860/
C                         / Z04049E89/
      DATA PRODTB(  1084) /   67411593/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1085) / -859045872/
C                         / Z04096070/
      DATA PRODTB(  1086) /   67723376/
C                         /ZAAAA/ + 5240
      DATA PRODTB(  1087) /-1431694216/
C                         /ZAAAA/ + 3876
      DATA PRODTB(  1088) /-1431695580/
C                         / Z0403FE70/
      DATA PRODTB(  1089) /   67370608/
C                         /ZAAAA/ + 4068
      DATA PRODTB(  1090) /-1431695388/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1091) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1092) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1093) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1094) /-1431696948/
C                         / Z40004000/
      DATA PRODTB(  1095) / 1073758208/
C                         /ZAAAA/ + 4092
      DATA PRODTB(  1096) /-1431695364/
C                         /ZAAAA/ + 1924
      DATA PRODTB(  1097) /-1431697532/
C                         / Z0403FE70/
      DATA PRODTB(  1098) /   67370608/
C                         /ZAAAA/ + 4104
      DATA PRODTB(  1099) /-1431695352/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1100) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1101) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1102) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1103) /-1431696948/
C                         / Z40004000/
      DATA PRODTB(  1104) / 1073758208/
C                         /ZAAAA/ + 5296
      DATA PRODTB(  1105) /-1431694160/
C                         /ZAAAA/ + 1924
      DATA PRODTB(  1106) /-1431697532/
C                         / Z40004000/
      DATA PRODTB(  1107) / 1073758208/
C                         /ZAAAA/ + 4148
      DATA PRODTB(  1108) /-1431695308/
C                         / Z40002000/
      DATA PRODTB(  1109) / 1073750016/
C                         /ZAAAA/ + 5312
      DATA PRODTB(  1110) /-1431694144/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1111) / -859045860/
C                         / Z0403FE70/
      DATA PRODTB(  1112) /   67370608/
C                         /ZAAAA/ + 4160
      DATA PRODTB(  1113) /-1431695296/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1114) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1115) / 1073774592/
C                         /ZAAAA/ + 2520
      DATA PRODTB(  1116) /-1431696936/
C                         /ZAAAA/ + 2508
      DATA PRODTB(  1117) /-1431696948/
C                         / Z00180000/
      DATA PRODTB(  1118) /    1572864/
C                         /ZCCCC/ +   59
      DATA PRODTB(  1119) / -859045829/
C                         /ZAAAA/ + 1924
      DATA PRODTB(  1120) /-1431697532/
C                         / Z04080002/
      DATA PRODTB(  1121) /   67633154/
C                         /ZAAAA/ + 4212
      DATA PRODTB(  1122) /-1431695244/
C                         / Z04020000/
      DATA PRODTB(  1123) /   67239936/
C                         /ZAAAA/ + 5328
      DATA PRODTB(  1124) /-1431694128/
C                         / Z00480000/
      DATA PRODTB(  1125) /    4718592/
C                         /ZAAAA/ + 4488
      DATA PRODTB(  1126) /-1431694968/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1127) / -859045859/
C                         / Z40000020/
      DATA PRODTB(  1128) / 1073741856/
C                         /ZAAAA/ + 5344
      DATA PRODTB(  1129) /-1431694112/
C                         / Z00280000/
      DATA PRODTB(  1130) /    2621440/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1131) /-1431694124/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1132) / -859045859/
C                         / Z04020000/
      DATA PRODTB(  1133) /   67239936/
C                         /ZAAAA/ + 4284
      DATA PRODTB(  1134) /-1431695172/
C                         / Z04080002/
      DATA PRODTB(  1135) /   67633154/
C                         /ZAAAA/ + 4296
      DATA PRODTB(  1136) /-1431695160/
C                         / Z04000600/
      DATA PRODTB(  1137) /   67110400/
C                         /ZAAAA/ + 5356
      DATA PRODTB(  1138) /-1431694100/
C                         / Z04000040/
      DATA PRODTB(  1139) /   67108928/
C                         /ZAAAA/ + 5384
      DATA PRODTB(  1140) /-1431694072/
C                         / Z04000010/
      DATA PRODTB(  1141) /   67108880/
C                         /ZAAAA/ + 5396
      DATA PRODTB(  1142) /-1431694060/
C                         / Z04000020/
      DATA PRODTB(  1143) /   67108896/
C                         /ZAAAA/ + 5408
      DATA PRODTB(  1144) /-1431694048/
C                         /ZAAAA/ + 4200
      DATA PRODTB(  1145) /-1431695256/
C                         / Z40012000/
      DATA PRODTB(  1146) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1147) /-1431694124/
C                         /ZAAAA/ + 4220
      DATA PRODTB(  1148) /-1431695236/
C                         / Z40012000/
      DATA PRODTB(  1149) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1150) /-1431694124/
C                         /ZAAAA/ + 4212
      DATA PRODTB(  1151) /-1431695244/
C                         / Z04020000/
      DATA PRODTB(  1152) /   67239936/
C                         /ZAAAA/ + 4328
      DATA PRODTB(  1153) /-1431695128/
C                         / Z04080002/
      DATA PRODTB(  1154) /   67633154/
C                         /ZAAAA/ + 4340
      DATA PRODTB(  1155) /-1431695116/
C                         /ZAAAA/ + 4200
      DATA PRODTB(  1156) /-1431695256/
C                         / Z40012000/
      DATA PRODTB(  1157) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1158) /-1431694124/
C                         /ZAAAA/ + 4220
      DATA PRODTB(  1159) /-1431695236/
C                         / Z40012000/
      DATA PRODTB(  1160) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1161) /-1431694124/
C                         /ZAAAA/ + 4212
      DATA PRODTB(  1162) /-1431695244/
C                         / Z04020000/
      DATA PRODTB(  1163) /   67239936/
C                         /ZAAAA/ + 4372
      DATA PRODTB(  1164) /-1431695084/
C                         / Z04080002/
      DATA PRODTB(  1165) /   67633154/
C                         /ZAAAA/ + 4392
      DATA PRODTB(  1166) /-1431695064/
C                         /ZAAAA/ + 4200
      DATA PRODTB(  1167) /-1431695256/
C                         / Z40001800/
      DATA PRODTB(  1168) / 1073747968/
C                         /ZAAAA/ + 5420
      DATA PRODTB(  1169) /-1431694036/
C                         / Z40012000/
      DATA PRODTB(  1170) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1171) /-1431694124/
C                         /ZAAAA/ + 4220
      DATA PRODTB(  1172) /-1431695236/
C                         / Z40001800/
      DATA PRODTB(  1173) / 1073747968/
C                         /ZAAAA/ + 5420
      DATA PRODTB(  1174) /-1431694036/
C                         / Z40012000/
      DATA PRODTB(  1175) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1176) /-1431694124/
C                         /ZAAAA/ + 4212
      DATA PRODTB(  1177) /-1431695244/
C                         / Z04020000/
      DATA PRODTB(  1178) /   67239936/
C                         /ZAAAA/ + 4432
      DATA PRODTB(  1179) /-1431695024/
C                         / Z04080002/
      DATA PRODTB(  1180) /   67633154/
C                         /ZAAAA/ + 4452
      DATA PRODTB(  1181) /-1431695004/
C                         /ZAAAA/ + 4200
      DATA PRODTB(  1182) /-1431695256/
C                         / Z40001800/
      DATA PRODTB(  1183) / 1073747968/
C                         /ZAAAA/ + 5420
      DATA PRODTB(  1184) /-1431694036/
C                         / Z40012000/
      DATA PRODTB(  1185) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1186) /-1431694124/
C                         /ZAAAA/ + 4220
      DATA PRODTB(  1187) /-1431695236/
C                         / Z40001800/
      DATA PRODTB(  1188) / 1073747968/
C                         /ZAAAA/ + 5420
      DATA PRODTB(  1189) /-1431694036/
C                         / Z40012000/
      DATA PRODTB(  1190) / 1073815552/
C                         /ZAAAA/ + 5332
      DATA PRODTB(  1191) /-1431694124/
C                         /ZAAAA/ + 4212
      DATA PRODTB(  1192) /-1431695244/
C                         / Z040A0002/
      DATA PRODTB(  1193) /   67764226/
C                         /ZAAAA/ + 5356
      DATA PRODTB(  1194) /-1431694100/
C                         /ZAAAA/ + 4200
      DATA PRODTB(  1195) /-1431695256/
C                         / Z00480000/
      DATA PRODTB(  1196) /    4718592/
C                         / Z040B8002/
      DATA PRODTB(  1197) /   67862530/
C                         / Z40020000/
      DATA PRODTB(  1198) / 1073872896/
C                         / Z04020000/
      DATA PRODTB(  1199) /   67239936/
C                         /ZCCCC/ +   10
      DATA PRODTB(  1200) / -859045878/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1201) / -859045859/
C                         / Z40002000/
      DATA PRODTB(  1202) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1203) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1204) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1205) /   67108872/
C                         /ZCCCC/ +   42
      DATA PRODTB(  1206) / -859045846/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1207) / -859045876/
C                         / Z40008000/
      DATA PRODTB(  1208) / 1073774592/
C                         / Z04020002/
      DATA PRODTB(  1209) /   67239938/
C                         / Z40002000/
      DATA PRODTB(  1210) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1211) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1212) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1213) /   67108872/
C                         /ZCCCC/ +   48
      DATA PRODTB(  1214) / -859045840/
C                         /ZCCCC/ +   10
      DATA PRODTB(  1215) / -859045878/
C                         / Z040A0002/
      DATA PRODTB(  1216) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1217) / -859045880/
C                         /ZCCCC/ +   13
      DATA PRODTB(  1218) / -859045875/
C                         / Z040A0002/
      DATA PRODTB(  1219) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1220) / -859045880/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1221) / -859045876/
C                         / Z04000001/
      DATA PRODTB(  1222) /   67108865/
C                         / Z40004000/
      DATA PRODTB(  1223) / 1073758208/
C                         /ZCCCC/ +   52
      DATA PRODTB(  1224) / -859045836/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1225) / -859045876/
C                         / Z40002000/
      DATA PRODTB(  1226) / 1073750016/
C                         / Z04000200/
      DATA PRODTB(  1227) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(  1228) / -859045786/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1229) / -859045876/
C                         / Z40002000/
      DATA PRODTB(  1230) / 1073750016/
C                         / Z04000200/
      DATA PRODTB(  1231) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(  1232) / -859045786/
C                         /ZCCCC/ +   41
      DATA PRODTB(  1233) / -859045847/
C                         / Z04020002/
      DATA PRODTB(  1234) /   67239938/
C                         / Z40002000/
      DATA PRODTB(  1235) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1236) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1237) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1238) /   67108872/
C                         /ZCCCC/ +   41
      DATA PRODTB(  1239) / -859045847/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1240) / -859045876/
C                         / Z04000005/
      DATA PRODTB(  1241) /   67108869/
C                         /ZCCCC/ +   51
      DATA PRODTB(  1242) / -859045837/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1243) / -859045876/
C                         / Z40002000/
      DATA PRODTB(  1244) / 1073750016/
C                         / Z04000800/
      DATA PRODTB(  1245) /   67110912/
C                         / Z00180000/
      DATA PRODTB(  1246) /    1572864/
C                         /ZCCCC/ +   31
      DATA PRODTB(  1247) / -859045857/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1248) / -859045876/
C                         / Z04080002/
      DATA PRODTB(  1249) /   67633154/
C                         /ZCCCC/ +   40
      DATA PRODTB(  1250) / -859045848/
C                         /ZCCCC/ +   12
      DATA PRODTB(  1251) / -859045876/
C                         / Z40008000/
      DATA PRODTB(  1252) / 1073774592/
C                         / Z040FFEFB/
      DATA PRODTB(  1253) /   68157179/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1254) / -859045872/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1255) / -859045860/
C                         / Z04000080/
      DATA PRODTB(  1256) /   67108992/
C                         /ZCCCC/ +   42
      DATA PRODTB(  1257) / -859045846/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1258) / -859045860/
C                         / Z40020000/
      DATA PRODTB(  1259) / 1073872896/
C                         / Z04020000/
      DATA PRODTB(  1260) /   67239936/
C                         /ZCCCC/ +   10
      DATA PRODTB(  1261) / -859045878/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1262) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(  1263) /   67764226/
C                         /ZCCCC/ +   77
      DATA PRODTB(  1264) / -859045811/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1265) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(  1266) /   67764226/
C                         /ZCCCC/ +   76
      DATA PRODTB(  1267) / -859045812/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1268) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(  1269) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1270) / -859045880/
C                         /ZCCCC/ +   13
      DATA PRODTB(  1271) / -859045875/
C                         / Z040A0002/
      DATA PRODTB(  1272) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1273) / -859045880/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1274) / -859045860/
C                         / Z040A0002/
      DATA PRODTB(  1275) /   67764226/
C                         /ZCCCC/ +   33
      DATA PRODTB(  1276) / -859045855/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1277) / -859045860/
C                         / Z40002000/
      DATA PRODTB(  1278) / 1073750016/
C                         / Z04000200/
      DATA PRODTB(  1279) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(  1280) / -859045786/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1281) / -859045872/
C                         / Z40002000/
      DATA PRODTB(  1282) / 1073750016/
C                         / Z04000200/
      DATA PRODTB(  1283) /   67109376/
C                         /ZCCCC/ +  102
      DATA PRODTB(  1284) / -859045786/
C                         /ZCCCC/ +   41
      DATA PRODTB(  1285) / -859045847/
C                         / Z4002E000/
      DATA PRODTB(  1286) / 1073930240/
C                         /ZCCCC/ +   49
      DATA PRODTB(  1287) / -859045839/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1288) / -859045872/
C                         / Z040A0002/
      DATA PRODTB(  1289) /   67764226/
C                         / Z40020000/
      DATA PRODTB(  1290) / 1073872896/
C                         / Z04020000/
      DATA PRODTB(  1291) /   67239936/
C                         /ZCCCC/ +   11
      DATA PRODTB(  1292) / -859045877/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1293) / -859045860/
C                         / Z04030072/
      DATA PRODTB(  1294) /   67305586/
C                         / Z40020000/
      DATA PRODTB(  1295) / 1073872896/
C                         /ZCCCC/ +   39
      DATA PRODTB(  1296) / -859045849/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1297) / -859045860/
C                         / Z04030072/
      DATA PRODTB(  1298) /   67305586/
C                         / Z40020000/
      DATA PRODTB(  1299) / 1073872896/
C                         /ZCCCC/ +  104
      DATA PRODTB(  1300) / -859045784/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1301) / -859045860/
C                         / Z04080002/
      DATA PRODTB(  1302) /   67633154/
C                         /ZCCCC/ +   40
      DATA PRODTB(  1303) / -859045848/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1304) / -859045860/
C                         / Z40002000/
      DATA PRODTB(  1305) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1306) /   67109888/
C                         /ZCCCC/ +   43
      DATA PRODTB(  1307) / -859045845/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1308) / -859045872/
C                         / Z04030062/
      DATA PRODTB(  1309) /   67305570/
C                         / Z40020000/
      DATA PRODTB(  1310) / 1073872896/
C                         /ZCCCC/ +   45
      DATA PRODTB(  1311) / -859045843/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1312) / -859045860/
C                         / Z04000001/
      DATA PRODTB(  1313) /   67108865/
C                         / Z40004000/
      DATA PRODTB(  1314) / 1073758208/
C                         / Z04010070/
      DATA PRODTB(  1315) /   67174512/
C                         / Z00180000/
      DATA PRODTB(  1316) /    1572864/
C                         /ZCCCC/ +   61
      DATA PRODTB(  1317) / -859045827/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1318) / -859045860/
C                         / Z40002000/
      DATA PRODTB(  1319) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1320) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1321) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1322) /   67108872/
C                         /ZCCCC/ +   42
      DATA PRODTB(  1323) / -859045846/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1324) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1325) / 1073774592/
C                         / Z04020002/
      DATA PRODTB(  1326) /   67239938/
C                         / Z40002000/
      DATA PRODTB(  1327) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1328) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1329) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1330) /   67108872/
C                         /ZCCCC/ +   48
      DATA PRODTB(  1331) / -859045840/
C                         /ZCCCC/ +   10
      DATA PRODTB(  1332) / -859045878/
C                         / Z40004000/
      DATA PRODTB(  1333) / 1073758208/
C                         /ZCCCC/ +   52
      DATA PRODTB(  1334) / -859045836/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1335) / -859045872/
C                         / Z040A0002/
      DATA PRODTB(  1336) /   67764226/
C                         / Z40004000/
      DATA PRODTB(  1337) / 1073758208/
C                         / Z04030070/
      DATA PRODTB(  1338) /   67305584/
C                         / Z40008000/
      DATA PRODTB(  1339) / 1073774592/
C                         / Z04096070/
      DATA PRODTB(  1340) /   67723376/
C                         / Z40002000/
      DATA PRODTB(  1341) / 1073750016/
C                         / Z04000100/
      DATA PRODTB(  1342) /   67109120/
C                         / Z00180000/
      DATA PRODTB(  1343) /    1572864/
C                         /ZCCCC/ +   27
      DATA PRODTB(  1344) / -859045861/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1345) / -859045872/
C                         / Z40002000/
      DATA PRODTB(  1346) / 1073750016/
C                         / Z04000400/
      DATA PRODTB(  1347) /   67109888/
C                         / Z40008000/
      DATA PRODTB(  1348) / 1073774592/
C                         / Z04000008/
      DATA PRODTB(  1349) /   67108872/
C                         /ZCCCC/ +   41
      DATA PRODTB(  1350) / -859045847/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1351) / -859045872/
C                         / Z04000005/
      DATA PRODTB(  1352) /   67108869/
C                         /ZCCCC/ +   51
      DATA PRODTB(  1353) / -859045837/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1354) / -859045860/
C                         / Z40002000/
      DATA PRODTB(  1355) / 1073750016/
C                         / Z04000800/
      DATA PRODTB(  1356) /   67110912/
C                         / Z00180000/
      DATA PRODTB(  1357) /    1572864/
C                         /ZCCCC/ +   31
      DATA PRODTB(  1358) / -859045857/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1359) / -859045860/
C                         / Z40004000/
      DATA PRODTB(  1360) / 1073758208/
C                         / Z04030072/
      DATA PRODTB(  1361) /   67305586/
C                         / Z00180000/
      DATA PRODTB(  1362) /    1572864/
C                         /ZCCCC/ +  103
      DATA PRODTB(  1363) / -859045785/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1364) / -859045860/
C                         / Z04000800/
      DATA PRODTB(  1365) /   67110912/
C                         / Z00180000/
      DATA PRODTB(  1366) /    1572864/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1367) / -859045872/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1368) / -859045860/
C                         / Z04000001/
      DATA PRODTB(  1369) /   67108865/
C                         / Z40004000/
      DATA PRODTB(  1370) / 1073758208/
C                         /ZCCCC/ +   52
      DATA PRODTB(  1371) / -859045836/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1372) / -859045860/
C                         / Z00180000/
      DATA PRODTB(  1373) /    1572864/
C                         /ZCCCC/ +   50
      DATA PRODTB(  1374) / -859045838/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1375) / -859045860/
C                         / Z04000008/
      DATA PRODTB(  1376) /   67108872/
C                         / Z00180000/
      DATA PRODTB(  1377) /    1572864/
C                         /ZCCCC/ +   47
      DATA PRODTB(  1378) / -859045841/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1379) / -859045860/
C                         / Z40004000/
      DATA PRODTB(  1380) / 1073758208/
C                         / Z04030072/
      DATA PRODTB(  1381) /   67305586/
C                         / Z00180000/
      DATA PRODTB(  1382) /    1572864/
C                         /ZCCCC/ +   38
      DATA PRODTB(  1383) / -859045850/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1384) / -859045860/
C                         / Z40008000/
      DATA PRODTB(  1385) / 1073774592/
C                         / Z04096070/
      DATA PRODTB(  1386) /   67723376/
C                         / Z00480000/
      DATA PRODTB(  1387) /    4718592/
C                         / Z040A0002/
      DATA PRODTB(  1388) /   67764226/
C                         / Z40020000/
      DATA PRODTB(  1389) / 1073872896/
C                         / Z04000100/
      DATA PRODTB(  1390) /   67109120/
C                         / Z00180000/
      DATA PRODTB(  1391) /    1572864/
C                         /ZCCCC/ +   30
      DATA PRODTB(  1392) / -859045858/
C                         /ZCCCC/ +   16
      DATA PRODTB(  1393) / -859045872/
C                         / Z40004000/
      DATA PRODTB(  1394) / 1073758208/
C                         / Z04030062/
      DATA PRODTB(  1395) /   67305570/
C                         / Z00180000/
      DATA PRODTB(  1396) /    1572864/
C                         /ZCCCC/ +   44
      DATA PRODTB(  1397) / -859045844/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1398) / -859045860/
C                         / Z04010070/
      DATA PRODTB(  1399) /   67174512/
C                         / Z00180000/
      DATA PRODTB(  1400) /    1572864/
C                         /ZCCCC/ +   53
      DATA PRODTB(  1401) / -859045835/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1402) / -859045860/
C                         / Z04000800/
      DATA PRODTB(  1403) /   67110912/
C                         / Z00180000/
      DATA PRODTB(  1404) /    1572864/
C                         /ZCCCC/ +   57
      DATA PRODTB(  1405) / -859045831/
C                         /ZCCCC/ +   28
      DATA PRODTB(  1406) / -859045860/
C                         / Z00280000/
      DATA PRODTB(  1407) /    2621440/
C                         / Z040A0002/
      DATA PRODTB(  1408) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1409) / -859045880/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1410) / -859045859/
C                         / Z04080002/
      DATA PRODTB(  1411) /   67633154/
C                         /ZCCCC/ +   40
      DATA PRODTB(  1412) / -859045848/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1413) / -859045859/
C                         / Z40004000/
      DATA PRODTB(  1414) / 1073758208/
C                         / Z00480000/
      DATA PRODTB(  1415) /    4718592/
C                         / Z040A0002/
      DATA PRODTB(  1416) /   67764226/
C                         / Z40020000/
      DATA PRODTB(  1417) / 1073872896/
C                         / Z04020000/
      DATA PRODTB(  1418) /   67239936/
C                         /ZCCCC/ +   18
      DATA PRODTB(  1419) / -859045870/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1420) / -859045859/
C                         / Z00180000/
      DATA PRODTB(  1421) /    1572864/
C                         /ZCCCC/ +    2
      DATA PRODTB(  1422) / -859045886/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1423) / -859045859/
C                         / Z40024000/
      DATA PRODTB(  1424) / 1073889280/
C                         /ZCCCC/ +  101
      DATA PRODTB(  1425) / -859045787/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1426) / -859045859/
C                         / Z4002C000/
      DATA PRODTB(  1427) / 1073922048/
C                         /ZCCCC/ +    1
      DATA PRODTB(  1428) / -859045887/
C                         /ZCCCC/ +   29
      DATA PRODTB(  1429) / -859045859/
C                         / Z040A0002/
      DATA PRODTB(  1430) /   67764226/
C                         /ZCCCC/ +    8
      DATA PRODTB(  1431) / -859045880/
C                         /ZCCCC/ +   13
      DATA PRODTB(  1432) / -859045875/
       END
