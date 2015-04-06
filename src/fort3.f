      BLOCK DATA BDGMTY
C
      IMPLICIT INTEGER (A-Z)
      COMMON/GMTY/GMTY
      DIMENSION GMTY(2730),GEOMTB(2180),GEOLOC(  50),PMIDTB( 250),
     1  ARGMXY( 250)
      EQUIVALENCE (GEOLOC(1),GMTY(1)),
     1            (PMIDTB(1),GMTY( 51)),
     2            (ARGMXY(1),GMTY(301)),
     3            (GEOMTB(1),GMTY(551)) 
C
c      DATA ARGMXY/250*0/
      DATA ARGMXY(  7)/   2/
      DATA ARGMXY(  8)/   3/
      DATA ARGMXY(  9)/   2/
      DATA ARGMXY( 10)/   2/
      DATA ARGMXY( 11)/   3/
      DATA ARGMXY( 13)/   3/
      DATA ARGMXY( 14)/   2/
      DATA ARGMXY( 16)/   4/
      DATA ARGMXY( 19)/   2/
      DATA ARGMXY( 20)/   2/
      DATA ARGMXY( 21)/   3/
      DATA ARGMXY( 32)/   3/
      DATA ARGMXY( 34)/   2/
      DATA ARGMXY( 37)/   3/
      DATA ARGMXY( 38)/   3/
      DATA ARGMXY( 45)/   5/
      DATA ARGMXY( 46)/   6/
      DATA ARGMXY( 47)/   7/
      DATA ARGMXY( 48)/   4/
      DATA ARGMXY( 49)/   3/
      DATA ARGMXY( 51)/   2/
      DATA ARGMXY( 52)/   3/
      DATA ARGMXY( 53)/   4/
      DATA ARGMXY(147)/   2/

c      gfortran chokes on initializing everything, then
c      re-initializing individual memory locations, so this
c      first statement must be commented.
C                     /Z7FFFFFFF/
c      DATA PMIDTB/250* 2147483647/

      data pmidtb(238:250)/13*2147483647/
C                     / Z40800000/
      DATA PMIDTB( 21)/ 1082130432/
C                     / Z40400000/
      DATA PMIDTB( 19)/ 1077936128/
C                     / Z20800000/
      DATA PMIDTB( 57)/  545259520/
C                     / Z20400000/
      DATA PMIDTB( 58)/  541065216/
C                     / Z20200000/
      DATA PMIDTB( 59)/  538968064/
C                     / Z20100000/
      DATA PMIDTB( 82)/  537919488/
C                     / Z40200000/
      DATA PMIDTB( 60)/ 1075838976/
C                     / Z40100000/
      DATA PMIDTB( 61)/ 1074790400/
C                     / Z20080000/
      DATA PMIDTB( 62)/  537395200/
C                     / Z10800000/
      DATA PMIDTB( 56)/  276824064/
C                     / Z40080000/
      DATA PMIDTB( 63)/ 1074266112/
C                     / Z10400000/
      DATA PMIDTB(197)/  272629760/
C                     / Z08800000/
      DATA PMIDTB(  1)/  142606336/
C                     / Z08400000/
      DATA PMIDTB(  2)/  138412032/
C                     / Z08200000/
      DATA PMIDTB( 11)/  136314880/
C                     / Z10200000/
      DATA PMIDTB( 65)/  270532608/
C                     / Z08100000/
      DATA PMIDTB(  4)/  135266304/
C                     / Z08080000/
      DATA PMIDTB(  3)/  134742016/
C                     / Z40040000/
      DATA PMIDTB( 64)/ 1074003968/
C                     / Z40020000/
      DATA PMIDTB( 95)/ 1073872896/
C                     / Z40010000/
      DATA PMIDTB( 88)/ 1073807360/
C                     / Z40008000/
      DATA PMIDTB( 96)/ 1073774592/
C                     / Z40004000/
      DATA PMIDTB( 66)/ 1073758208/
C                     / Z40002000/
      DATA PMIDTB( 97)/ 1073750016/
C                     / Z40001000/
      DATA PMIDTB( 20)/ 1073745920/
C                     / Z10100000/
      DATA PMIDTB( 67)/  269484032/
C                     / Z20040000/
      DATA PMIDTB( 69)/  537133056/
C                     / Z20020000/
      DATA PMIDTB( 99)/  537001984/
C                     / Z10080000/
      DATA PMIDTB( 68)/  268959744/
C                     / Z40000800/
      DATA PMIDTB( 70)/ 1073743872/
C                     / Z40000400/
      DATA PMIDTB( 71)/ 1073742848/
C                     / Z10040000/
      DATA PMIDTB( 72)/  268697600/
C                     / Z10020000/
      DATA PMIDTB(101)/  268566528/
C                     / Z10010000/
      DATA PMIDTB(102)/  268500992/
C                     / Z10008000/
      DATA PMIDTB(103)/  268468224/
C                     / Z10004000/
      DATA PMIDTB( 73)/  268451840/
C                     / Z10002000/
      DATA PMIDTB( 74)/  268443648/
C                     / Z04800000/
      DATA PMIDTB( 75)/   75497472/
C                     / Z04400000/
      DATA PMIDTB( 76)/   71303168/
C                     / Z04200000/
      DATA PMIDTB( 77)/   69206016/
C                     / Z08040000/
      DATA PMIDTB( 78)/  134479872/
C                     / Z20010000/
      DATA PMIDTB( 80)/  536936448/
C                     / Z10001000/
      DATA PMIDTB( 81)/  268439552/
C                     / Z10000800/
      DATA PMIDTB( 18)/  268437504/
C                     / Z10000400/
      DATA PMIDTB( 79)/  268436480/
C                     / Z08020000/
      DATA PMIDTB( 86)/  134348800/
C                     / Z08010000/
      DATA PMIDTB( 84)/  134283264/
C                     / Z08008000/
      DATA PMIDTB( 87)/  134250496/
C                     / Z08004000/
      DATA PMIDTB( 98)/  134234112/
C                     / Z08002000/
      DATA PMIDTB( 83)/  134225920/
C                     / Z04100000/
      DATA PMIDTB( 85)/   68157440/
C                     / Z10000200/
      DATA PMIDTB(119)/  268435968/
C                     / Z40000200/
      DATA PMIDTB( 26)/ 1073742336/
C                     / Z10000100/
      DATA PMIDTB( 30)/  268435712/
C                     / Z10000080/
      DATA PMIDTB( 29)/  268435584/
C                     / Z20008000/
      DATA PMIDTB(194)/  536903680/
C                     / Z20004000/
      DATA PMIDTB(199)/  536887296/
C                     / Z08001000/
      DATA PMIDTB(  8)/  134221824/
C                     / Z08000800/
      DATA PMIDTB( 10)/  134219776/
C                     / Z08000400/
      DATA PMIDTB( 14)/  134218752/
C                     / Z08000200/
      DATA PMIDTB(  7)/  134218240/
C                     / Z08000100/
      DATA PMIDTB(  6)/  134217984/
C                     / Z04080000/
      DATA PMIDTB(231)/   67633152/
C                     / Z04040000/
      DATA PMIDTB(236)/   67371008/
C                     / Z04020000/
      DATA PMIDTB(234)/   67239936/
C                     / Z10000040/
      DATA PMIDTB( 93)/  268435520/
C                     / Z10000020/
      DATA PMIDTB( 94)/  268435488/
C                     / Z10000010/
      DATA PMIDTB( 89)/  268435472/
C                     / Z20002000/
      DATA PMIDTB( 92)/  536879104/
C                     / Z20001000/
      DATA PMIDTB( 91)/  536875008/
C                     / Z08000080/
      DATA PMIDTB( 90)/  134217856/
C                     / Z40000100/
      DATA PMIDTB(186)/ 1073742080/
C                     / Z40000080/
      DATA PMIDTB(187)/ 1073741952/
C                     / Z40000040/
      DATA PMIDTB(195)/ 1073741888/
C                     / Z04010000/
      DATA PMIDTB(232)/   67174400/
C                     / Z04008000/
      DATA PMIDTB(233)/   67141632/
C                     / Z04004000/
      DATA PMIDTB(237)/   67125248/
C                     / Z04002000/
      DATA PMIDTB(235)/   67117056/
C                     / Z08000040/
      DATA PMIDTB(  5)/  134217792/
C                     / Z08000020/
      DATA PMIDTB(  9)/  134217760/
C                     / Z02800000/
      DATA PMIDTB(118)/   41943040/
C                     / Z04001000/
      DATA PMIDTB(107)/   67112960/
C                     / Z02400000/
      DATA PMIDTB(117)/   37748736/
C                     / Z20000800/
      DATA PMIDTB(104)/  536872960/
C                     / Z20000400/
      DATA PMIDTB(105)/  536871936/
C                     / Z02200000/
      DATA PMIDTB(106)/   35651584/
C                     / Z04000800/
      DATA PMIDTB(111)/   67110912/
C                     / Z02100000/
      DATA PMIDTB(112)/   34603008/
C                     / Z20000200/
      DATA PMIDTB(114)/  536871424/
C                     / Z20000100/
      DATA PMIDTB(115)/  536871168/
C                     / Z04000400/
      DATA PMIDTB(116)/   67109888/
C                     / Z20000080/
      DATA PMIDTB(108)/  536871040/
C                     / Z20000040/
      DATA PMIDTB(109)/  536870976/
C                     / Z04000200/
      DATA PMIDTB(113)/   67109376/
C                     / Z08000010/
      DATA PMIDTB( 27)/  134217744/
C                     / Z08000008/
      DATA PMIDTB( 28)/  134217736/
C                     / Z04000100/
      DATA PMIDTB(100)/   67109120/
C                     / Z04000080/
      DATA PMIDTB(110)/   67108992/
C                     / Z20000020/
      DATA PMIDTB(189)/  536870944/
C                     / Z20000010/
      DATA PMIDTB(188)/  536870928/
C                     / Z02080000/
      DATA PMIDTB(200)/   34078720/
C                     / Z04000040/
      DATA PMIDTB(203)/   67108928/
C                     / Z04000020/
      DATA PMIDTB(204)/   67108896/
C                     / Z02040000/
      DATA PMIDTB(221)/   33816576/
C                     / Z10000008/
      DATA PMIDTB(217)/  268435464/
C                     / Z10000004/
      DATA PMIDTB(222)/  268435460/
C                     / Z02020000/
      DATA PMIDTB(218)/   33685504/
C                     / Z20000008/
      DATA PMIDTB(190)/  536870920/
C                     / Z02010000/
      DATA PMIDTB(191)/   33619968/
C                     / Z08000004/
      DATA PMIDTB(193)/  134217732/
C                     / Z20000004/
      DATA PMIDTB(183)/  536870916/
C                     / Z20000002/
      DATA PMIDTB(184)/  536870914/
C                     / Z20000001/
      DATA PMIDTB(185)/  536870913/
C                     / Z40000020/
      DATA PMIDTB(196)/ 1073741856/
C                     / Z08000002/
      DATA PMIDTB(192)/  134217730/
C                     / Z08000001/
      DATA PMIDTB(198)/  134217729/
C                     / Z02008000/
      DATA PMIDTB(182)/   33587200/
C                     / Z02004000/
      DATA PMIDTB(181)/   33570816/
C                     / Z04000010/
      DATA PMIDTB(120)/   67108880/
C                     / Z04000008/
      DATA PMIDTB(208)/   67108872/
C                     / Z04000004/
      DATA PMIDTB(209)/   67108868/
C                     / Z04000002/
      DATA PMIDTB( 53)/   67108866/
C                     / Z02002000/
      DATA PMIDTB(144)/   33562624/
C                     / Z40000010/
      DATA PMIDTB(213)/ 1073741840/
C                     / Z02001000/
      DATA PMIDTB(207)/   33558528/
C                     / Z04000001/
      DATA PMIDTB(216)/   67108865/
C                     / Z02000800/
      DATA PMIDTB(220)/   33556480/
C                     / Z40000008/
      DATA PMIDTB(212)/ 1073741832/
C                     / Z02000400/
      DATA PMIDTB(205)/   33555456/
C                     / Z02000200/
      DATA PMIDTB(206)/   33554944/
C                     / Z02000100/
      DATA PMIDTB(219)/   33554688/
C                     / Z02000080/
      DATA PMIDTB(150)/   33554560/
C                     / Z40000004/
      DATA PMIDTB(201)/ 1073741828/
C                     / Z40000002/
      DATA PMIDTB(202)/ 1073741826/
C                     / Z40000001/
      DATA PMIDTB( 51)/ 1073741825/
C                     / Z02000040/
      DATA PMIDTB(121)/   33554496/
C                     / Z02000020/
      DATA PMIDTB(147)/   33554464/
C                     / Z10000002/
      DATA PMIDTB(145)/  268435458/
C                     / Z10000001/
      DATA PMIDTB(146)/  268435457/
C                     / Z02000010/
      DATA PMIDTB(148)/   33554448/
C                     / Z02000008/
      DATA PMIDTB(211)/   33554440/
C                     / Z02000004/
      DATA PMIDTB(214)/   33554436/
C                     / Z02000002/
      DATA PMIDTB(215)/   33554434/
C                     / Z02000001/
      DATA PMIDTB(124)/   33554433/
C                     / Z01800000/
      DATA PMIDTB(125)/   25165824/
C          SURFACE TYPE 1
      DATA GEOLOC( 1)/   1/
C          SURFACE TYPE 2
      DATA GEOLOC( 2)/ 101/
C          SURFACE TYPE 3
      DATA GEOLOC( 3)/ 282/
C          SURFACE TYPE 4
      DATA GEOLOC( 4)/ 167/
C          SURFACE TYPE 5
      DATA GEOLOC( 5)/ 375/
C          SURFACE TYPE 6
      DATA GEOLOC( 6)/ 426/
C          SURFACE TYPE 7
      DATA GEOLOC( 7)/ 469/
C          SURFACE TYPE 8
      DATA GEOLOC( 8)/ 434/
C          SURFACE TYPE 9
      DATA GEOLOC( 9)/ 442/
C          SURFACE TYPE10
      DATA GEOLOC(10)/ 448/
C          SURFACE TYPE11
      DATA GEOLOC(11)/ 540/
C          SURFACE TYPE12
      DATA GEOLOC(12)/1170/
C          SURFACE TYPE13
      DATA GEOLOC(13)/   0/
C          SURFACE TYPE14
      DATA GEOLOC(14)/ 413/
C          SURFACE TYPE15
      DATA GEOLOC(15)/1167/
C          SURFACE TYPE16
      DATA GEOLOC(16)/   0/
C          SURFACE TYPE17
      DATA GEOLOC(17)/   0/
C          SURFACE TYPE18
      DATA GEOLOC(18)/ 609/
C          SURFACE TYPE19
      DATA GEOLOC(19)/ 802/
C          SURFACE TYPE20
      DATA GEOLOC(20)/ 941/
C          SURFACE TYPE21
      DATA GEOLOC(21)/   0/
C          SURFACE TYPE22
      DATA GEOLOC(22)/   0/
C          SURFACE TYPE23
      DATA GEOLOC(23)/   0/
C          SURFACE TYPE24
      DATA GEOLOC(24)/1302/
C          SURFACE TYPE25
      DATA GEOLOC(25)/   0/
C          SURFACE TYPE26
      DATA GEOLOC(26)/1193/
C          SURFACE TYPE27
      DATA GEOLOC(27)/1289/
C          SURFACE TYPE28
      DATA GEOLOC(28)/1298/
C          SURFACE TYPE29
      DATA GEOLOC(29)/1449/
C          SURFACE TYPE30
      DATA GEOLOC(30)/1343/
C          SURFACE TYPE31
      DATA GEOLOC(31)/   0/
C          SURFACE TYPE32
      DATA GEOLOC(32)/   0/
C          SURFACE TYPE33
      DATA GEOLOC(33)/   0/
C          SURFACE TYPE34
      DATA GEOLOC(34)/   0/
C          SURFACE TYPE35
      DATA GEOLOC(35)/   0/
C          SURFACE TYPE36
      DATA GEOLOC(36)/   0/
C          SURFACE TYPE37
      DATA GEOLOC(37)/   0/
C          SURFACE TYPE38
      DATA GEOLOC(38)/   0/
C          SURFACE TYPE39
      DATA GEOLOC(39)/   0/
C          SURFACE TYPE40
      DATA GEOLOC(40)/   0/
C          SURFACE TYPE41
      DATA GEOLOC(41)/   0/
C          SURFACE TYPE42
      DATA GEOLOC(42)/   0/
C          SURFACE TYPE43
      DATA GEOLOC(43)/   0/
C          SURFACE TYPE44
      DATA GEOLOC(44)/   0/
C          SURFACE TYPE45
      DATA GEOLOC(45)/2148/
C          SURFACE TYPE46
      DATA GEOLOC(46)/1554/
C          SURFACE TYPE47
      DATA GEOLOC(47)/1617/
C          SURFACE TYPE48
      DATA GEOLOC(48)/1708/
C          SURFACE TYPE49
      DATA GEOLOC(49)/1935/
C          SURFACE TYPE50
      DATA GEOLOC(50)/2027/
C
C                         /Z9999/ +    0
      DATA GEOMTB(     1) /-1718026240/
C                         / Z40800000/
      DATA GEOMTB(     2) / 1082130432/
C                         /ZAAAA/ +   72
      DATA GEOMTB(     3) /-1431699384/
C                         / Z40400000/
      DATA GEOMTB(     4) / 1077936128/
C                         /ZAAAA/ +  108
      DATA GEOMTB(     5) /-1431699348/
C                         / Z20800000/
      DATA GEOMTB(     6) /  545259520/
C                         /ZCCCC/ +  111
      DATA GEOMTB(     7) / -859045777/
C                         / Z20400000/
      DATA GEOMTB(     8) /  541065216/
C                         /ZCCCC/ +  112
      DATA GEOMTB(     9) / -859045776/
C                         / Z20300000/
      DATA GEOMTB(    10) /  540016640/
C                         /ZAAAA/ +  264
      DATA GEOMTB(    11) /-1431699192/
C                         / Z40300000/
      DATA GEOMTB(    12) / 1076887552/
C                         /ZAAAA/ +  220
      DATA GEOMTB(    13) /-1431699236/
C                         / Z20080000/
      DATA GEOMTB(    14) /  537395200/
C                         /ZAAAA/ +  292
      DATA GEOMTB(    15) /-1431699164/
C                         / Z10800000/
      DATA GEOMTB(    16) /  276824064/
C                         /ZAAAA/ +  312
      DATA GEOMTB(    17) /-1431699144/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    18) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    19) / 1082130432/
C                         /ZAAAA/ +   84
      DATA GEOMTB(    20) /-1431699372/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    21) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    22) / 1082130432/
C                         /ZAAAA/ +   96
      DATA GEOMTB(    23) /-1431699360/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    24) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    25) / 1082130432/
C                         /ZAAAA/ +  328
      DATA GEOMTB(    26) /-1431699128/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    27) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(    28) / 1077936128/
C                         /ZCCCC/ +    7
      DATA GEOMTB(    29) / -859045881/
C                         / Z40300000/
      DATA GEOMTB(    30) / 1076887552/
C                         /ZAAAA/ +  160
      DATA GEOMTB(    31) /-1431699296/
C                         / Z40080000/
      DATA GEOMTB(    32) / 1074266112/
C                         /ZAAAA/ +  200
      DATA GEOMTB(    33) /-1431699256/
C                         / Z10400000/
      DATA GEOMTB(    34) /  272629760/
C                         /ZAAAA/ +  344
      DATA GEOMTB(    35) /-1431699112/
C                         / Z20080000/
      DATA GEOMTB(    36) /  537395200/
C                         /ZAAAA/ +  360
      DATA GEOMTB(    37) /-1431699096/
C                         / Z20300000/
      DATA GEOMTB(    38) /  540016640/
C                         /ZAAAA/ +  372
      DATA GEOMTB(    39) /-1431699084/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    40) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    41) / 1082130432/
C                         /ZAAAA/ +  172
      DATA GEOMTB(    42) /-1431699284/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    43) / -859045688/
C                         / Z20800000/
      DATA GEOMTB(    44) /  545259520/
C                         /ZCCCC/ +   52
      DATA GEOMTB(    45) / -859045836/
C                         / Z20400000/
      DATA GEOMTB(    46) /  541065216/
C                         /ZCCCC/ +  113
      DATA GEOMTB(    47) / -859045775/
C                         / Z08C00000/
      DATA GEOMTB(    48) /  146800640/
C                         /ZCCCC/ +   11
      DATA GEOMTB(    49) / -859045877/
C                         /ZCCCC/ +   52
      DATA GEOMTB(    50) / -859045836/
C                         / Z08C00000/
      DATA GEOMTB(    51) /  146800640/
C                         /ZCCCC/ +    9
      DATA GEOMTB(    52) / -859045879/
C                         / Z08200000/
      DATA GEOMTB(    53) /  136314880/
C                         /ZAAAA/ +  348
      DATA GEOMTB(    54) /-1431699108/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    55) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    56) / 1082130432/
C                         /ZAAAA/ +  232
      DATA GEOMTB(    57) /-1431699224/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    58) / -859045688/
C                         / Z10200000/
      DATA GEOMTB(    59) /  270532608/
C                         /ZAAAA/ +  244
      DATA GEOMTB(    60) /-1431699212/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    61) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    62) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(    63) / -859045878/
C                         / Z20C00000/
      DATA GEOMTB(    64) /  549453824/
C                         /ZAAAA/ +  388
      DATA GEOMTB(    65) /-1431699068/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    66) / -859045688/
C                         / Z10400000/
      DATA GEOMTB(    67) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(    68) /  135790592/
C                         / Z20300000/
      DATA GEOMTB(    69) /  540016640/
C                         / Z10400000/
      DATA GEOMTB(    70) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(    71) /  135790592/
C                         /ZCCCC/ +   51
      DATA GEOMTB(    72) / -859045837/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    73) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(    74) /  146800640/
C                         / Z4007E000/
      DATA GEOMTB(    75) / 1074257920/
C                         / Z40800000/
      DATA GEOMTB(    76) / 1082130432/
C                         /ZCCCC/ +   53
      DATA GEOMTB(    77) / -859045835/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    78) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(    79) /  146800640/
C                         / Z08C00000/
      DATA GEOMTB(    80) /  146800640/
C                         /ZCCCC/ +   17
      DATA GEOMTB(    81) / -859045871/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    82) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    83) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(    84) / 1082130432/
C                         /ZCCCC/ +   70
      DATA GEOMTB(    85) / -859045818/
C                         /ZCCCC/ +    5
      DATA GEOMTB(    86) / -859045883/
C                         / Z08200000/
      DATA GEOMTB(    87) /  136314880/
C                         / Z40400000/
      DATA GEOMTB(    88) / 1077936128/
C                         /ZCCCC/ +   79
      DATA GEOMTB(    89) / -859045809/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    90) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(    91) /  146800640/
C                         /ZCCCC/ +    8
      DATA GEOMTB(    92) / -859045880/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    93) / -859045688/
C                         / Z10400000/
      DATA GEOMTB(    94) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(    95) /  135790592/
C                         /ZCCCC/ +   50
      DATA GEOMTB(    96) / -859045838/
C                         /ZCCCC/ +  200
      DATA GEOMTB(    97) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(    98) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(    99) / -859045878/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   100) / -859045688/
C                         /Z9999/ +  400
      DATA GEOMTB(   101) /-1718025840/
C                         / Z40800000/
      DATA GEOMTB(   102) / 1082130432/
C                         /ZAAAA/ +  124
      DATA GEOMTB(   103) /-1431699332/
C                         / Z40400000/
      DATA GEOMTB(   104) / 1077936128/
C                         /ZAAAA/ +   48
      DATA GEOMTB(   105) /-1431699408/
C                         / Z20080000/
      DATA GEOMTB(   106) /  537395200/
C                         /ZAAAA/ +  144
      DATA GEOMTB(   107) /-1431699312/
C                         / Z40080000/
      DATA GEOMTB(   108) / 1074266112/
C                         /ZAAAA/ +  164
      DATA GEOMTB(   109) /-1431699292/
C                         / Z20300000/
      DATA GEOMTB(   110) /  540016640/
C                         /ZAAAA/ +  184
      DATA GEOMTB(   111) /-1431699272/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   112) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   113) / 1077936128/
C                         /ZAAAA/ +   84
      DATA GEOMTB(   114) /-1431699372/
C                         / Z40080000/
      DATA GEOMTB(   115) / 1074266112/
C                         /ZAAAA/ +  104
      DATA GEOMTB(   116) /-1431699352/
C                         / Z20300000/
      DATA GEOMTB(   117) /  540016640/
C                         /ZAAAA/ +  212
      DATA GEOMTB(   118) /-1431699244/
C                         / Z20080000/
      DATA GEOMTB(   119) /  537395200/
C                         /ZAAAA/ +  228
      DATA GEOMTB(   120) /-1431699228/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   121) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   122) / 1077936128/
C                         /ZCCCC/ +   25
      DATA GEOMTB(   123) / -859045863/
C                         / Z40080000/
      DATA GEOMTB(   124) / 1074266112/
C                         /ZAAAA/ +  240
      DATA GEOMTB(   125) /-1431699216/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   126) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(   127) / 1073745920/
C                         /ZCCCC/ +   26
      DATA GEOMTB(   128) / -859045862/
C                         / Z08C00000/
      DATA GEOMTB(   129) /  146800640/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   130) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   131) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   132) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   133) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   134) / 1082130432/
C                         /ZCCCC/ +   24
      DATA GEOMTB(   135) / -859045864/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   136) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   137) /  146800640/
C                         / Z4007E000/
      DATA GEOMTB(   138) / 1074257920/
C                         / Z40800000/
      DATA GEOMTB(   139) / 1082130432/
C                         /ZCCCC/ +   62
      DATA GEOMTB(   140) / -859045826/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   141) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   142) /  146800640/
C                         / Z40400000/
      DATA GEOMTB(   143) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   144) / 1077936128/
C                         /ZCCCC/ +   28
      DATA GEOMTB(   145) / -859045860/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   146) / -859045688/
C                         / Z10400000/
      DATA GEOMTB(   147) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(   148) /  135790592/
C                         / Z20300000/
      DATA GEOMTB(   149) /  540016640/
C                         / Z10400000/
      DATA GEOMTB(   150) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(   151) /  135790592/
C                         /ZCCCC/ +   51
      DATA GEOMTB(   152) / -859045837/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   153) / -859045688/
C                         / Z10400000/
      DATA GEOMTB(   154) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(   155) /  135790592/
C                         /ZCCCC/ +   50
      DATA GEOMTB(   156) / -859045838/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   157) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   158) /  146800640/
C                         /ZCCCC/ +   26
      DATA GEOMTB(   159) / -859045862/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   160) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   161) /  146800640/
C                         /ZCCCC/ +  183
      DATA GEOMTB(   162) / -859045705/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   163) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   164) /  146800640/
C                         /ZCCCC/ +   76
      DATA GEOMTB(   165) / -859045812/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   166) / -859045688/
C                         /Z9999/ +  664
      DATA GEOMTB(   167) /-1718025576/
C                         / Z40800000/
      DATA GEOMTB(   168) / 1082130432/
C                         /ZAAAA/ +   48
      DATA GEOMTB(   169) /-1431699408/
C                         / Z10100000/
      DATA GEOMTB(   170) /  269484032/
C                         /ZAAAA/ +   72
      DATA GEOMTB(   171) /-1431699384/
C                         / Z40400000/
      DATA GEOMTB(   172) / 1077936128/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   173) /-1431699204/
C                         / Z10400000/
      DATA GEOMTB(   174) /  272629760/
C                         /ZAAAA/ +  128
      DATA GEOMTB(   175) /-1431699328/
C                         / Z4007E000/
      DATA GEOMTB(   176) / 1074257920/
C                         /ZAAAA/ +  180
      DATA GEOMTB(   177) /-1431699276/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   178) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   179) / 1082130432/
C                         /ZAAAA/ +   60
      DATA GEOMTB(   180) /-1431699396/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   181) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   182) / 1082130432/
C                         /ZAAAA/ +  268
      DATA GEOMTB(   183) /-1431699188/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   184) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   185) / 1077936128/
C                         /ZAAAA/ +   92
      DATA GEOMTB(   186) /-1431699364/
C                         / Z40800000/
      DATA GEOMTB(   187) / 1082130432/
C                         /ZAAAA/ +  280
      DATA GEOMTB(   188) /-1431699176/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   189) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   190) / 1077936128/
C                         /ZCCCC/ +   14
      DATA GEOMTB(   191) / -859045874/
C                         / Z20060000/
      DATA GEOMTB(   192) /  537264128/
C                         /ZAAAA/ +  304
      DATA GEOMTB(   193) /-1431699152/
C                         / Z10400000/
      DATA GEOMTB(   194) /  272629760/
C                         /ZAAAA/ +  320
      DATA GEOMTB(   195) /-1431699136/
C                         / Z10080000/
      DATA GEOMTB(   196) /  268959744/
C                         /ZAAAA/ +  332
      DATA GEOMTB(   197) /-1431699124/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   198) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   199) /  146800640/
C                         /ZAAAA/ +  140
      DATA GEOMTB(   200) /-1431699316/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   201) / -859045688/
C                         / Z40078000/
      DATA GEOMTB(   202) / 1074233344/
C                         /ZAAAA/ +  160
      DATA GEOMTB(   203) /-1431699296/
C                         / Z40006000/
      DATA GEOMTB(   204) / 1073766400/
C                         /ZAAAA/ +  344
      DATA GEOMTB(   205) /-1431699112/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   206) / -859045688/
C                         / Z08200000/
      DATA GEOMTB(   207) /  136314880/
C                         /ZAAAA/ +  364
      DATA GEOMTB(   208) /-1431699092/
C                         / Z40400000/
      DATA GEOMTB(   209) / 1077936128/
C                         /ZAAAA/ +  348
      DATA GEOMTB(   210) /-1431699108/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   211) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   212) /  146800640/
C                         /ZAAAA/ +  200
      DATA GEOMTB(   213) /-1431699256/
C                         / Z40000C00/
      DATA GEOMTB(   214) / 1073744896/
C                         /ZAAAA/ +  388
      DATA GEOMTB(   215) /-1431699068/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   216) / -859045688/
C                         / Z4007E000/
      DATA GEOMTB(   217) / 1074257920/
C                         /ZAAAA/ +  212
      DATA GEOMTB(   218) /-1431699244/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   219) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   220) /  146800640/
C                         /ZAAAA/ +  232
      DATA GEOMTB(   221) /-1431699224/
C                         / Z40000C00/
      DATA GEOMTB(   222) / 1073744896/
C                         /ZAAAA/ +  416
      DATA GEOMTB(   223) /-1431699040/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   224) / -859045688/
C                         / Z4007E000/
      DATA GEOMTB(   225) / 1074257920/
C                         /ZAAAA/ +  436
      DATA GEOMTB(   226) /-1431699020/
C                         / Z10080000/
      DATA GEOMTB(   227) /  268959744/
C                         /ZAAAA/ +  448
      DATA GEOMTB(   228) /-1431699008/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   229) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   230) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   231) / 1077936128/
C                         /ZCCCC/ +   15
      DATA GEOMTB(   232) / -859045873/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   233) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   234) / 1082130432/
C                         /ZCCCC/ +  103
      DATA GEOMTB(   235) / -859045785/
C                         /ZCCCC/ +  104
      DATA GEOMTB(   236) / -859045784/
C                         / Z40800000/
      DATA GEOMTB(   237) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   238) / 1082130432/
C                         / Z10080000/
      DATA GEOMTB(   239) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   240) / 1082130432/
C                         /ZCCCC/ +  105
      DATA GEOMTB(   241) / -859045783/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   242) / -859045688/
C                         / Z10400000/
      DATA GEOMTB(   243) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(   244) /  135790592/
C                         /ZCCCC/ +   54
      DATA GEOMTB(   245) / -859045834/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   246) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   247) /  146800640/
C                         /ZCCCC/ +   13
      DATA GEOMTB(   248) / -859045875/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   249) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   250) / 1082130432/
C                         /ZCCCC/ +   12
      DATA GEOMTB(   251) / -859045876/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   252) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   253) / 1077936128/
C                         / Z10080000/
      DATA GEOMTB(   254) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   255) / 1082130432/
C                         /ZCCCC/ +   55
      DATA GEOMTB(   256) / -859045833/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   257) / -859045688/
C                         / Z40078000/
      DATA GEOMTB(   258) / 1074233344/
C                         / Z40400000/
      DATA GEOMTB(   259) / 1077936128/
C                         / Z10080000/
      DATA GEOMTB(   260) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   261) / 1082130432/
C                         /ZCCCC/ +   84
      DATA GEOMTB(   262) / -859045804/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   263) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   264) /  135790592/
C                         / Z40000C00/
      DATA GEOMTB(   265) / 1073744896/
C                         / Z08180000/
      DATA GEOMTB(   266) /  135790592/
C                         / Z10080000/
      DATA GEOMTB(   267) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   268) / 1082130432/
C                         /ZCCCC/ +   57
      DATA GEOMTB(   269) / -859045831/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   270) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   271) /  135790592/
C                         / Z10080000/
      DATA GEOMTB(   272) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   273) / 1082130432/
C                         /ZCCCC/ +   58
      DATA GEOMTB(   274) / -859045830/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   275) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   276) /  146800640/
C                         /ZCCCC/ +   89
      DATA GEOMTB(   277) / -859045799/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   278) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   279) / 1082130432/
C                         /ZCCCC/ +   56
      DATA GEOMTB(   280) / -859045832/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   281) / -859045688/
C                         /Z9999/ + 1124
      DATA GEOMTB(   282) /-1718025116/
C                         / Z40400000/
      DATA GEOMTB(   283) / 1077936128/
C                         /ZAAAA/ +   48
      DATA GEOMTB(   284) /-1431699408/
C                         / Z40800000/
      DATA GEOMTB(   285) / 1082130432/
C                         /ZAAAA/ +   68
      DATA GEOMTB(   286) /-1431699388/
C                         / Z4007E000/
      DATA GEOMTB(   287) / 1074257920/
C                         /ZAAAA/ +  112
      DATA GEOMTB(   288) /-1431699344/
C                         / Z10100000/
      DATA GEOMTB(   289) /  269484032/
C                         /ZAAAA/ +  184
      DATA GEOMTB(   290) /-1431699272/
C                         / Z10400000/
      DATA GEOMTB(   291) /  272629760/
C                         /ZAAAA/ +  208
      DATA GEOMTB(   292) /-1431699248/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   293) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(   294) / 1073745920/
C                         /ZAAAA/ +  236
      DATA GEOMTB(   295) /-1431699220/
C                         / Z40800000/
      DATA GEOMTB(   296) / 1082130432/
C                         /ZAAAA/ +  248
      DATA GEOMTB(   297) /-1431699208/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   298) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   299) / 1082130432/
C                         /ZAAAA/ +   80
      DATA GEOMTB(   300) /-1431699376/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   301) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   302) / 1082130432/
C                         /ZAAAA/ +   92
      DATA GEOMTB(   303) /-1431699364/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   304) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   305) / 1082130432/
C                         /ZAAAA/ +  268
      DATA GEOMTB(   306) /-1431699188/
C                         / Z40001000/
      DATA GEOMTB(   307) / 1073745920/
C                         /ZAAAA/ +  288
      DATA GEOMTB(   308) /-1431699168/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   309) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   310) /  146800640/
C                         /ZAAAA/ +  132
      DATA GEOMTB(   311) /-1431699324/
C                         / Z40000C00/
      DATA GEOMTB(   312) / 1073744896/
C                         /ZAAAA/ +  300
      DATA GEOMTB(   313) /-1431699156/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   314) / -859045688/
C                         / Z4007E000/
      DATA GEOMTB(   315) / 1074257920/
C                         /ZAAAA/ +  144
      DATA GEOMTB(   316) /-1431699312/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   317) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   318) /  146800640/
C                         /ZAAAA/ +  164
      DATA GEOMTB(   319) /-1431699292/
C                         / Z40000C00/
      DATA GEOMTB(   320) / 1073744896/
C                         /ZAAAA/ +  328
      DATA GEOMTB(   321) /-1431699128/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   322) / -859045688/
C                         / Z10080000/
      DATA GEOMTB(   323) /  268959744/
C                         /ZAAAA/ +  348
      DATA GEOMTB(   324) /-1431699108/
C                         / Z4007E000/
      DATA GEOMTB(   325) / 1074257920/
C                         /ZAAAA/ +  360
      DATA GEOMTB(   326) /-1431699096/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   327) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   328) / 1077936128/
C                         / Z20060000/
      DATA GEOMTB(   329) /  537264128/
C                         / Z10400000/
      DATA GEOMTB(   330) /  272629760/
C                         / Z08180000/
      DATA GEOMTB(   331) /  135790592/
C                         /ZCCCC/ +   54
      DATA GEOMTB(   332) / -859045834/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   333) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   334) /  146800640/
C                         / Z4007E000/
      DATA GEOMTB(   335) / 1074257920/
C                         / Z40400000/
      DATA GEOMTB(   336) / 1077936128/
C                         / Z10080000/
      DATA GEOMTB(   337) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   338) / 1082130432/
C                         /ZCCCC/ +   55
      DATA GEOMTB(   339) / -859045833/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   340) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   341) / 1082130432/
C                         /ZCCCC/ +   34
      DATA GEOMTB(   342) / -859045854/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   343) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   344) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   345) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   346) / 1082130432/
C                         /ZCCCC/ +   33
      DATA GEOMTB(   347) / -859045855/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   348) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   349) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   350) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   351) / 1082130432/
C                         /ZCCCC/ +  178
      DATA GEOMTB(   352) / -859045710/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   353) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   354) / 1082130432/
C                         /ZCCCC/ +  182
      DATA GEOMTB(   355) / -859045706/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   356) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   357) /  135790592/
C                         / Z40000C00/
      DATA GEOMTB(   358) / 1073744896/
C                         / Z08180000/
      DATA GEOMTB(   359) /  135790592/
C                         / Z10080000/
      DATA GEOMTB(   360) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   361) / 1082130432/
C                         /ZCCCC/ +   57
      DATA GEOMTB(   362) / -859045831/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   363) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   364) /  135790592/
C                         / Z10080000/
      DATA GEOMTB(   365) /  268959744/
C                         / Z40800000/
      DATA GEOMTB(   366) / 1082130432/
C                         /ZCCCC/ +   58
      DATA GEOMTB(   367) / -859045830/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   368) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   369) / 1082130432/
C                         /ZCCCC/ +   56
      DATA GEOMTB(   370) / -859045832/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   371) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   372) /  146800640/
C                         /ZCCCC/ +   89
      DATA GEOMTB(   373) / -859045799/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   374) / -859045688/
C                         /Z9999/ + 1496
      DATA GEOMTB(   375) /-1718024744/
C                         / Z40800000/
      DATA GEOMTB(   376) / 1082130432/
C                         /ZAAAA/ +   92
      DATA GEOMTB(   377) /-1431699364/
C                         / Z40400000/
      DATA GEOMTB(   378) / 1077936128/
C                         /ZAAAA/ +   32
      DATA GEOMTB(   379) /-1431699424/
C                         / Z10100000/
      DATA GEOMTB(   380) /  269484032/
C                         /ZAAAA/ +   52
      DATA GEOMTB(   381) /-1431699404/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   382) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   383) / 1082130432/
C                         /ZCCCC/ +   29
      DATA GEOMTB(   384) / -859045859/
C                         / Z40400000/
      DATA GEOMTB(   385) / 1077936128/
C                         /ZAAAA/ +  112
      DATA GEOMTB(   386) /-1431699344/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   387) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   388) / 1077936128/
C                         /ZAAAA/ +   64
      DATA GEOMTB(   389) /-1431699392/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   390) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   391) / 1077936128/
C                         /ZCCCC/ +   30
      DATA GEOMTB(   392) / -859045858/
C                         / Z10400000/
      DATA GEOMTB(   393) /  272629760/
C                         /ZAAAA/ +  128
      DATA GEOMTB(   394) /-1431699328/
C                         / Z10080000/
      DATA GEOMTB(   395) /  268959744/
C                         /ZAAAA/ +  140
      DATA GEOMTB(   396) /-1431699316/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   397) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   398) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   399) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   400) / 1082130432/
C                         /ZCCCC/ +  108
      DATA GEOMTB(   401) / -859045780/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   402) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   403) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   404) / 1077936128/
C                         /ZCCCC/ +   32
      DATA GEOMTB(   405) / -859045856/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   406) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   407) /  146800640/
C                         /ZCCCC/ +   31
      DATA GEOMTB(   408) / -859045857/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   409) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   410) / 1082130432/
C                         /ZCCCC/ +   29
      DATA GEOMTB(   411) / -859045859/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   412) / -859045688/
C                         /Z9999/ + 1648
      DATA GEOMTB(   413) /-1718024592/
C                         / Z40800000/
      DATA GEOMTB(   414) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   415) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   416) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   417) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   418) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   419) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   420) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   421) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   422) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   423) / 1082130432/
C                         /ZCCCC/ +   39
      DATA GEOMTB(   424) / -859045849/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   425) / -859045688/
C                         /Z9999/ + 1700
      DATA GEOMTB(   426) /-1718024540/
C                         / Z10100000/
      DATA GEOMTB(   427) /  269484032/
C                         / Z40400000/
      DATA GEOMTB(   428) / 1077936128/
C                         / Z40800000/
      DATA GEOMTB(   429) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   430) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   431) / 1082130432/
C                         /ZCCCC/ +   37
      DATA GEOMTB(   432) / -859045851/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   433) / -859045688/
C                         /Z9999/ + 1732
      DATA GEOMTB(   434) /-1718024508/
C                         / Z10100000/
      DATA GEOMTB(   435) /  269484032/
C                         / Z40400000/
      DATA GEOMTB(   436) / 1077936128/
C                         / Z40800000/
      DATA GEOMTB(   437) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   438) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   439) / 1082130432/
C                         /ZCCCC/ +   36
      DATA GEOMTB(   440) / -859045852/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   441) / -859045688/
C                         /Z9999/ + 1764
      DATA GEOMTB(   442) /-1718024476/
C                         / Z40400000/
      DATA GEOMTB(   443) / 1077936128/
C                         / Z40001000/
      DATA GEOMTB(   444) / 1073745920/
C                         / Z40800000/
      DATA GEOMTB(   445) / 1082130432/
C                         /ZCCCC/ +   35
      DATA GEOMTB(   446) / -859045853/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   447) / -859045688/
C                         /Z9999/ + 1788
      DATA GEOMTB(   448) /-1718024452/
C                         / Z40800000/
      DATA GEOMTB(   449) / 1082130432/
C                         /ZAAAA/ +   16
      DATA GEOMTB(   450) /-1431699440/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   451) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   452) / 1082130432/
C                         /ZAAAA/ +   28
      DATA GEOMTB(   453) /-1431699428/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   454) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   455) / 1082130432/
C                         /ZAAAA/ +   40
      DATA GEOMTB(   456) /-1431699416/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   457) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   458) / 1082130432/
C                         /ZAAAA/ +   52
      DATA GEOMTB(   459) /-1431699404/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   460) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   461) / 1082130432/
C                         /ZAAAA/ +   64
      DATA GEOMTB(   462) /-1431699392/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   463) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   464) / 1082130432/
C                         /ZCCCC/ +   38
      DATA GEOMTB(   465) / -859045850/
C                         / Z10040000/
      DATA GEOMTB(   466) /  268697600/
C                         /ZCCCC/ +   69
      DATA GEOMTB(   467) / -859045819/
C                         /ZCCCC/ +   71
      DATA GEOMTB(   468) / -859045817/
C                         /Z9999/ + 1872
      DATA GEOMTB(   469) /-1718024368/
C                         / Z10020000/
      DATA GEOMTB(   470) /  268566528/
C                         /ZAAAA/ +   32
      DATA GEOMTB(   471) /-1431699424/
C                         / Z10010000/
      DATA GEOMTB(   472) /  268500992/
C                         /ZAAAA/ +   52
      DATA GEOMTB(   473) /-1431699404/
C                         / Z10008000/
      DATA GEOMTB(   474) /  268468224/
C                         /ZAAAA/ +   72
      DATA GEOMTB(   475) /-1431699384/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   476) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   477) / 1082130432/
C                         /ZAAAA/ +   92
      DATA GEOMTB(   478) /-1431699364/
C                         / Z40400000/
      DATA GEOMTB(   479) / 1077936128/
C                         /ZAAAA/ +  136
      DATA GEOMTB(   480) /-1431699320/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   481) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   482) / 1082130432/
C                         /ZAAAA/ +  160
      DATA GEOMTB(   483) /-1431699296/
C                         / Z40400000/
      DATA GEOMTB(   484) / 1077936128/
C                         /ZAAAA/ +  200
      DATA GEOMTB(   485) /-1431699256/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   486) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   487) / 1082130432/
C                         /ZAAAA/ +  224
      DATA GEOMTB(   488) /-1431699232/
C                         / Z40400000/
      DATA GEOMTB(   489) / 1077936128/
C                         /ZAAAA/ +  260
      DATA GEOMTB(   490) /-1431699196/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   491) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   492) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   493) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   494) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   495) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   496) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   497) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   498) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   499) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   500) / 1082130432/
C                         /ZCCCC/ +  179
      DATA GEOMTB(   501) / -859045709/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   502) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   503) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   504) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   505) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   506) / 1077936128/
C                         /ZCCCC/ +   83
      DATA GEOMTB(   507) / -859045805/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   508) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   509) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   510) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   511) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   512) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   513) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   514) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   515) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   516) / 1082130432/
C                         /ZCCCC/ +  180
      DATA GEOMTB(   517) / -859045708/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   518) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   519) / 1082130432/
C                         / Z40400000/
      DATA GEOMTB(   520) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   521) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(   522) / 1077936128/
C                         /ZCCCC/ +   83
      DATA GEOMTB(   523) / -859045805/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   524) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   525) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   526) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   527) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   528) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   529) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   530) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   531) / 1082130432/
C                         /ZCCCC/ +  181
      DATA GEOMTB(   532) / -859045707/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   533) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   534) / 1082130432/
C                         / Z40400000/
      DATA GEOMTB(   535) / 1077936128/
C                         / Z40800000/
      DATA GEOMTB(   536) / 1082130432/
C                         / Z40400000/
      DATA GEOMTB(   537) / 1077936128/
C                         /ZCCCC/ +   83
      DATA GEOMTB(   538) / -859045805/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   539) / -859045688/
C                         /Z9999/ + 2156
      DATA GEOMTB(   540) /-1718024084/
C                         / Z10004000/
      DATA GEOMTB(   541) /  268451840/
C                         /ZAAAA/ +   40
      DATA GEOMTB(   542) /-1431699416/
C                         / Z10002000/
      DATA GEOMTB(   543) /  268443648/
C                         /ZAAAA/ +   84
      DATA GEOMTB(   544) /-1431699372/
C                         / Z04E00000/
      DATA GEOMTB(   545) /   81788928/
C                         /ZAAAA/ +  128
      DATA GEOMTB(   546) /-1431699328/
C                         / Z08040000/
      DATA GEOMTB(   547) /  134479872/
C                         /ZAAAA/ +  172
      DATA GEOMTB(   548) /-1431699284/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   549) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(   550) /  536936448/
C                         /ZCCCC/ +    1
      DATA GEOMTB(   551) / -859045887/
C                         / Z40400000/
      DATA GEOMTB(   552) / 1077936128/
C                         /ZCCCC/ +   12
      DATA GEOMTB(   553) / -859045876/
C                         / Z40800000/
      DATA GEOMTB(   554) / 1082130432/
C                         /ZAAAA/ +  228
      DATA GEOMTB(   555) /-1431699228/
C                         / Z40180000/
      DATA GEOMTB(   556) / 1075314688/
C                         /ZAAAA/ +  240
      DATA GEOMTB(   557) /-1431699216/
C                         / Z10001000/
      DATA GEOMTB(   558) /  268439552/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   559) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   560) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(   561) /  536936448/
C                         /ZCCCC/ +    1
      DATA GEOMTB(   562) / -859045887/
C                         / Z40400000/
      DATA GEOMTB(   563) / 1077936128/
C                         /ZCCCC/ +   13
      DATA GEOMTB(   564) / -859045875/
C                         / Z40800000/
      DATA GEOMTB(   565) / 1082130432/
C                         /ZAAAA/ +  228
      DATA GEOMTB(   566) /-1431699228/
C                         / Z40180000/
      DATA GEOMTB(   567) / 1075314688/
C                         /ZAAAA/ +  240
      DATA GEOMTB(   568) /-1431699216/
C                         / Z10001000/
      DATA GEOMTB(   569) /  268439552/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   570) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   571) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(   572) /  536936448/
C                         /ZCCCC/ +    1
      DATA GEOMTB(   573) / -859045887/
C                         / Z40400000/
      DATA GEOMTB(   574) / 1077936128/
C                         /ZCCCC/ +   11
      DATA GEOMTB(   575) / -859045877/
C                         / Z40800000/
      DATA GEOMTB(   576) / 1082130432/
C                         /ZAAAA/ +  228
      DATA GEOMTB(   577) /-1431699228/
C                         / Z40180000/
      DATA GEOMTB(   578) / 1075314688/
C                         /ZAAAA/ +  240
      DATA GEOMTB(   579) /-1431699216/
C                         / Z10001000/
      DATA GEOMTB(   580) /  268439552/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   581) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   582) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(   583) /  536936448/
C                         /ZCCCC/ +    1
      DATA GEOMTB(   584) / -859045887/
C                         / Z40001000/
      DATA GEOMTB(   585) / 1073745920/
C                         /ZCCCC/ +    4
      DATA GEOMTB(   586) / -859045884/
C                         / Z40800000/
      DATA GEOMTB(   587) / 1082130432/
C                         /ZAAAA/ +  216
      DATA GEOMTB(   588) /-1431699240/
C                         / Z40400000/
      DATA GEOMTB(   589) / 1077936128/
C                         /ZCCCC/ +   14
      DATA GEOMTB(   590) / -859045874/
C                         / Z10001000/
      DATA GEOMTB(   591) /  268439552/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   592) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   593) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   594) / 1082130432/
C                         /ZAAAA/ +  264
      DATA GEOMTB(   595) /-1431699192/
C                         /ZCCCC/ +   10
      DATA GEOMTB(   596) / -859045878/
C                         / Z40800000/
      DATA GEOMTB(   597) / 1082130432/
C                         /ZCCCC/ +    7
      DATA GEOMTB(   598) / -859045881/
C                         /ZCCCC/ +   10
      DATA GEOMTB(   599) / -859045878/
C                         / Z40800000/
      DATA GEOMTB(   600) / 1082130432/
C                         /ZCCCC/ +    5
      DATA GEOMTB(   601) / -859045883/
C                         /ZCCCC/ +    6
      DATA GEOMTB(   602) / -859045882/
C                         / Z10000800/
      DATA GEOMTB(   603) /  268437504/
C                         /ZCCCC/ +    2
      DATA GEOMTB(   604) / -859045886/
C                         /ZCCCC/ +    3
      DATA GEOMTB(   605) / -859045885/
C                         / Z40800000/
      DATA GEOMTB(   606) / 1082130432/
C                         /ZCCCC/ +    8
      DATA GEOMTB(   607) / -859045880/
C                         /ZCCCC/ +    9
      DATA GEOMTB(   608) / -859045879/
C                         /Z9999/ + 2432
      DATA GEOMTB(   609) /-1718023808/
C                         / Z40800000/
      DATA GEOMTB(   610) / 1082130432/
C                         /ZAAAA/ +  500
      DATA GEOMTB(   611) /-1431698956/
C                         / Z10000400/
      DATA GEOMTB(   612) /  268436480/
C                         /ZAAAA/ +   80
      DATA GEOMTB(   613) /-1431699376/
C                         / Z08C00000/
      DATA GEOMTB(   614) /  146800640/
C                         /ZAAAA/ +  552
      DATA GEOMTB(   615) /-1431698904/
C                         / Z08020000/
      DATA GEOMTB(   616) /  134348800/
C                         /ZAAAA/ +  112
      DATA GEOMTB(   617) /-1431699344/
C                         / Z40400000/
      DATA GEOMTB(   618) / 1077936128/
C                         /ZAAAA/ +  184
      DATA GEOMTB(   619) /-1431699272/
C                         / Z0801C000/
      DATA GEOMTB(   620) /  134332416/
C                         /ZAAAA/ +  216
      DATA GEOMTB(   621) /-1431699240/
C                         / Z10000800/
      DATA GEOMTB(   622) /  268437504/
C                         /ZAAAA/ +  288
      DATA GEOMTB(   623) /-1431699168/
C                         / Z08002000/
      DATA GEOMTB(   624) /  134225920/
C                         /ZAAAA/ +  348
      DATA GEOMTB(   625) /-1431699108/
C                         / Z04100000/
      DATA GEOMTB(   626) /   68157440/
C                         /ZAAAA/ +  568
      DATA GEOMTB(   627) /-1431698888/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   628) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   629) /  146800640/
C                         /ZCCCC/ +   80
      DATA GEOMTB(   630) / -859045808/
C                         / Z0801C000/
      DATA GEOMTB(   631) /  134332416/
C                         /ZAAAA/ +  100
      DATA GEOMTB(   632) /-1431699356/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   633) / -859045688/
C                         / Z0801C000/
      DATA GEOMTB(   634) /  134332416/
C                         /ZAAAA/ +  580
      DATA GEOMTB(   635) /-1431698876/
C                         /ZCCCC/ +  176
      DATA GEOMTB(   636) / -859045712/
C                         / Z40800000/
      DATA GEOMTB(   637) / 1082130432/
C                         /ZAAAA/ +  124
      DATA GEOMTB(   638) /-1431699332/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   639) / -859045688/
C                         / Z10000800/
      DATA GEOMTB(   640) /  268437504/
C                         /ZCCCC/ +  170
      DATA GEOMTB(   641) / -859045718/
C                         / Z08002000/
      DATA GEOMTB(   642) /  134225920/
C                         /ZAAAA/ +  160
      DATA GEOMTB(   643) /-1431699296/
C                         / Z0801C000/
      DATA GEOMTB(   644) /  134332416/
C                         /ZAAAA/ +  592
      DATA GEOMTB(   645) /-1431698864/
C                         / Z08020000/
      DATA GEOMTB(   646) /  134348800/
C                         /ZAAAA/ +  604
      DATA GEOMTB(   647) /-1431698852/
C                         /ZCCCC/ +  110
      DATA GEOMTB(   648) / -859045778/
C                         / Z40800000/
      DATA GEOMTB(   649) / 1082130432/
C                         /ZAAAA/ +  172
      DATA GEOMTB(   650) /-1431699284/
C                         /ZCCCC/ +  110
      DATA GEOMTB(   651) / -859045778/
C                         / Z40800000/
      DATA GEOMTB(   652) / 1082130432/
C                         /ZAAAA/ +  616
      DATA GEOMTB(   653) /-1431698840/
C                         /ZCCCC/ +  110
      DATA GEOMTB(   654) / -859045778/
C                         / Z40001000/
      DATA GEOMTB(   655) / 1073745920/
C                         /ZAAAA/ +  196
      DATA GEOMTB(   656) /-1431699260/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   657) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   658) / 1082130432/
C                         /ZCCCC/ +   78
      DATA GEOMTB(   659) / -859045810/
C                         / Z40001000/
      DATA GEOMTB(   660) / 1073745920/
C                         /ZCCCC/ +   64
      DATA GEOMTB(   661) / -859045824/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   662) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   663) / 1082130432/
C                         /ZAAAA/ +  228
      DATA GEOMTB(   664) /-1431699228/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   665) / -859045688/
C                         / Z10000800/
      DATA GEOMTB(   666) /  268437504/
C                         /ZCCCC/ +  165
      DATA GEOMTB(   667) / -859045723/
C                         / Z08002000/
      DATA GEOMTB(   668) /  134225920/
C                         /ZAAAA/ +  264
      DATA GEOMTB(   669) /-1431699192/
C                         / Z08020000/
      DATA GEOMTB(   670) /  134348800/
C                         /ZAAAA/ +  628
      DATA GEOMTB(   671) /-1431698828/
C                         / Z0801C000/
      DATA GEOMTB(   672) /  134332416/
C                         /ZAAAA/ +  640
      DATA GEOMTB(   673) /-1431698816/
C                         /ZCCCC/ +   63
      DATA GEOMTB(   674) / -859045825/
C                         / Z40800000/
      DATA GEOMTB(   675) / 1082130432/
C                         /ZAAAA/ +  276
      DATA GEOMTB(   676) /-1431699180/
C                         /ZCCCC/ +   63
      DATA GEOMTB(   677) / -859045825/
C                         / Z40800000/
      DATA GEOMTB(   678) / 1082130432/
C                         /ZAAAA/ +  652
      DATA GEOMTB(   679) /-1431698804/
C                         /ZCCCC/ +   63
      DATA GEOMTB(   680) / -859045825/
C                         / Z10000800/
      DATA GEOMTB(   681) /  268437504/
C                         /ZCCCC/ +   41
      DATA GEOMTB(   682) / -859045847/
C                         / Z08002000/
      DATA GEOMTB(   683) /  134225920/
C                         /ZAAAA/ +  324
      DATA GEOMTB(   684) /-1431699132/
C                         / Z08020000/
      DATA GEOMTB(   685) /  134348800/
C                         /ZAAAA/ +  664
      DATA GEOMTB(   686) /-1431698792/
C                         / Z0801C000/
      DATA GEOMTB(   687) /  134332416/
C                         /ZAAAA/ +  676
      DATA GEOMTB(   688) /-1431698780/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   689) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   690) / 1082130432/
C                         /ZAAAA/ +  336
      DATA GEOMTB(   691) /-1431699120/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   692) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   693) / 1082130432/
C                         /ZAAAA/ +  688
      DATA GEOMTB(   694) /-1431698768/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   695) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   696) / 1082130432/
C                         /ZAAAA/ +  360
      DATA GEOMTB(   697) /-1431699096/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   698) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   699) / 1082130432/
C                         /ZAAAA/ +  372
      DATA GEOMTB(   700) /-1431699084/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   701) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   702) / 1082130432/
C                         /ZAAAA/ +  416
      DATA GEOMTB(   703) /-1431699040/
C                         / Z10000800/
      DATA GEOMTB(   704) /  268437504/
C                         /ZCCCC/ +  160
      DATA GEOMTB(   705) / -859045728/
C                         / Z08002000/
      DATA GEOMTB(   706) /  134225920/
C                         /ZAAAA/ +  476
      DATA GEOMTB(   707) /-1431698980/
C                         / Z08020000/
      DATA GEOMTB(   708) /  134348800/
C                         /ZAAAA/ +  700
      DATA GEOMTB(   709) /-1431698756/
C                         / Z0801C000/
      DATA GEOMTB(   710) /  134332416/
C                         /ZAAAA/ +  712
      DATA GEOMTB(   711) /-1431698744/
C                         /ZCCCC/ +  175
      DATA GEOMTB(   712) / -859045713/
C                         / Z10000800/
      DATA GEOMTB(   713) /  268437504/
C                         /ZCCCC/ +  155
      DATA GEOMTB(   714) / -859045733/
C                         / Z08002000/
      DATA GEOMTB(   715) /  134225920/
C                         /ZAAAA/ +  452
      DATA GEOMTB(   716) /-1431699004/
C                         / Z08020000/
      DATA GEOMTB(   717) /  134348800/
C                         /ZAAAA/ +  724
      DATA GEOMTB(   718) /-1431698732/
C                         / Z0801C000/
      DATA GEOMTB(   719) /  134332416/
C                         /ZAAAA/ +  736
      DATA GEOMTB(   720) /-1431698720/
C                         /ZCCCC/ +   40
      DATA GEOMTB(   721) / -859045848/
C                         / Z40800000/
      DATA GEOMTB(   722) / 1082130432/
C                         /ZAAAA/ +  464
      DATA GEOMTB(   723) /-1431698992/
C                         /ZCCCC/ +   40
      DATA GEOMTB(   724) / -859045848/
C                         / Z40800000/
      DATA GEOMTB(   725) / 1082130432/
C                         /ZAAAA/ +  748
      DATA GEOMTB(   726) /-1431698708/
C                         /ZCCCC/ +   40
      DATA GEOMTB(   727) / -859045848/
C                         / Z40800000/
      DATA GEOMTB(   728) / 1082130432/
C                         /ZAAAA/ +  488
      DATA GEOMTB(   729) /-1431698968/
C                         /ZCCCC/ +  175
      DATA GEOMTB(   730) / -859045713/
C                         / Z40800000/
      DATA GEOMTB(   731) / 1082130432/
C                         /ZAAAA/ +  760
      DATA GEOMTB(   732) /-1431698696/
C                         /ZCCCC/ +  175
      DATA GEOMTB(   733) / -859045713/
C                         / Z40800000/
      DATA GEOMTB(   734) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   735) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   736) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   737) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   738) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   739) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   740) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   741) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   742) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   743) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   744) / 1082130432/
C                         /ZCCCC/ +  109
      DATA GEOMTB(   745) / -859045779/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   746) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   747) /  146800640/
C                         / Z08C00000/
      DATA GEOMTB(   748) /  146800640/
C                         /ZCCCC/ +   43
      DATA GEOMTB(   749) / -859045845/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   750) / -859045688/
C                         / Z10000800/
      DATA GEOMTB(   751) /  268437504/
C                         /ZCCCC/ +   42
      DATA GEOMTB(   752) / -859045846/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   753) / -859045688/
C                         / Z0801C000/
      DATA GEOMTB(   754) /  134332416/
C                         /ZCCCC/ +   81
      DATA GEOMTB(   755) / -859045807/
C                         /ZCCCC/ +  177
      DATA GEOMTB(   756) / -859045711/
C                         / Z40800000/
      DATA GEOMTB(   757) / 1082130432/
C                         /ZCCCC/ +  173
      DATA GEOMTB(   758) / -859045715/
C                         /ZCCCC/ +  110
      DATA GEOMTB(   759) / -859045778/
C                         / Z40800000/
      DATA GEOMTB(   760) / 1082130432/
C                         /ZCCCC/ +  174
      DATA GEOMTB(   761) / -859045714/
C                         /ZCCCC/ +  110
      DATA GEOMTB(   762) / -859045778/
C                         / Z40800000/
      DATA GEOMTB(   763) / 1082130432/
C                         /ZCCCC/ +  171
      DATA GEOMTB(   764) / -859045717/
C                         /ZCCCC/ +  172
      DATA GEOMTB(   765) / -859045716/
C                         / Z40800000/
      DATA GEOMTB(   766) / 1082130432/
C                         /ZCCCC/ +  169
      DATA GEOMTB(   767) / -859045719/
C                         /ZCCCC/ +   63
      DATA GEOMTB(   768) / -859045825/
C                         / Z40800000/
      DATA GEOMTB(   769) / 1082130432/
C                         /ZCCCC/ +  168
      DATA GEOMTB(   770) / -859045720/
C                         /ZCCCC/ +   63
      DATA GEOMTB(   771) / -859045825/
C                         / Z40800000/
      DATA GEOMTB(   772) / 1082130432/
C                         /ZCCCC/ +  166
      DATA GEOMTB(   773) / -859045722/
C                         /ZCCCC/ +  167
      DATA GEOMTB(   774) / -859045721/
C                         / Z40800000/
      DATA GEOMTB(   775) / 1082130432/
C                         /ZCCCC/ +  154
      DATA GEOMTB(   776) / -859045734/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   777) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   778) / 1082130432/
C                         /ZCCCC/ +  153
      DATA GEOMTB(   779) / -859045735/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   780) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   781) / 1082130432/
C                         /ZCCCC/ +  151
      DATA GEOMTB(   782) / -859045737/
C                         /ZCCCC/ +  152
      DATA GEOMTB(   783) / -859045736/
C                         / Z40800000/
      DATA GEOMTB(   784) / 1082130432/
C                         /ZCCCC/ +  164
      DATA GEOMTB(   785) / -859045724/
C                         /ZCCCC/ +  175
      DATA GEOMTB(   786) / -859045713/
C                         / Z40800000/
      DATA GEOMTB(   787) / 1082130432/
C                         /ZCCCC/ +  163
      DATA GEOMTB(   788) / -859045725/
C                         /ZCCCC/ +  175
      DATA GEOMTB(   789) / -859045713/
C                         / Z40800000/
      DATA GEOMTB(   790) / 1082130432/
C                         /ZCCCC/ +  159
      DATA GEOMTB(   791) / -859045729/
C                         /ZCCCC/ +   40
      DATA GEOMTB(   792) / -859045848/
C                         / Z40800000/
      DATA GEOMTB(   793) / 1082130432/
C                         /ZCCCC/ +  158
      DATA GEOMTB(   794) / -859045730/
C                         /ZCCCC/ +   40
      DATA GEOMTB(   795) / -859045848/
C                         / Z40800000/
      DATA GEOMTB(   796) / 1082130432/
C                         /ZCCCC/ +  156
      DATA GEOMTB(   797) / -859045732/
C                         /ZCCCC/ +  157
      DATA GEOMTB(   798) / -859045731/
C                         / Z40800000/
      DATA GEOMTB(   799) / 1082130432/
C                         /ZCCCC/ +  161
      DATA GEOMTB(   800) / -859045727/
C                         /ZCCCC/ +  162
      DATA GEOMTB(   801) / -859045726/
C                         /Z9999/ + 3204
      DATA GEOMTB(   802) /-1718023036/
C                         / Z40800000/
      DATA GEOMTB(   803) / 1082130432/
C                         /ZAAAA/ +   80
      DATA GEOMTB(   804) /-1431699376/
C                         / Z10800000/
      DATA GEOMTB(   805) /  276824064/
C                         /ZAAAA/ +   92
      DATA GEOMTB(   806) /-1431699364/
C                         / Z4007E000/
      DATA GEOMTB(   807) / 1074257920/
C                         /ZAAAA/ +  272
      DATA GEOMTB(   808) /-1431699184/
C                         / Z08180000/
      DATA GEOMTB(   809) /  135790592/
C                         /ZAAAA/ +  336
      DATA GEOMTB(   810) /-1431699120/
C                         / Z10100000/
      DATA GEOMTB(   811) /  269484032/
C                         /ZAAAA/ +  352
      DATA GEOMTB(   812) /-1431699104/
C                         / Z04400000/
      DATA GEOMTB(   813) /   71303168/
C                         /ZAAAA/ +  364
      DATA GEOMTB(   814) /-1431699092/
C                         / Z04200000/
      DATA GEOMTB(   815) /   69206016/
C                         /ZAAAA/ +  384
      DATA GEOMTB(   816) /-1431699072/
C                         / Z10000200/
      DATA GEOMTB(   817) /  268435968/
C                         /ZAAAA/ +  324
      DATA GEOMTB(   818) /-1431699132/
C                         / Z40000200/
      DATA GEOMTB(   819) / 1073742336/
C                         /ZAAAA/ +  404
      DATA GEOMTB(   820) /-1431699052/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   821) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   822) / 1082130432/
C                         /ZAAAA/ +  416
      DATA GEOMTB(   823) /-1431699040/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   824) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   825) /  146800640/
C                         /ZAAAA/ +  120
      DATA GEOMTB(   826) /-1431699336/
C                         / Z10000100/
      DATA GEOMTB(   827) /  268435712/
C                         /ZAAAA/ +  148
      DATA GEOMTB(   828) /-1431699308/
C                         / Z10000080/
      DATA GEOMTB(   829) /  268435584/
C                         /ZAAAA/ +  172
      DATA GEOMTB(   830) /-1431699284/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   831) / -859045688/
C                         / Z10000100/
      DATA GEOMTB(   832) /  268435712/
C                         /ZAAAA/ +  428
      DATA GEOMTB(   833) /-1431699028/
C                         / Z08200000/
      DATA GEOMTB(   834) /  136314880/
C                         /ZAAAA/ +  440
      DATA GEOMTB(   835) /-1431699016/
C                         / Z08C00000/
      DATA GEOMTB(   836) /  146800640/
C                         /ZAAAA/ +  452
      DATA GEOMTB(   837) /-1431699004/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   838) / -859045688/
C                         / Z2000C000/
      DATA GEOMTB(   839) /  536920064/
C                         /ZAAAA/ +  160
      DATA GEOMTB(   840) /-1431699296/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   841) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   842) / 1082130432/
C                         /ZAAAA/ +  464
      DATA GEOMTB(   843) /-1431698992/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   844) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   845) / 1082130432/
C                         /ZAAAA/ +  200
      DATA GEOMTB(   846) /-1431699256/
C                         / Z40400000/
      DATA GEOMTB(   847) / 1077936128/
C                         /ZAAAA/ +  212
      DATA GEOMTB(   848) /-1431699244/
C                         / Z2000C000/
      DATA GEOMTB(   849) /  536920064/
C                         /ZAAAA/ +  232
      DATA GEOMTB(   850) /-1431699224/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   851) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   852) / 1082130432/
C                         /ZAAAA/ +  476
      DATA GEOMTB(   853) /-1431698980/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   854) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   855) / 1077936128/
C                         /ZCCCC/ +  207
      DATA GEOMTB(   856) / -859045681/
C                         / Z40001000/
      DATA GEOMTB(   857) / 1073745920/
C                         /ZAAAA/ +  488
      DATA GEOMTB(   858) /-1431698968/
C                         /ZCCCC/ +  213
      DATA GEOMTB(   859) / -859045675/
C                         / Z40400000/
      DATA GEOMTB(   860) / 1077936128/
C                         /ZAAAA/ +  252
      DATA GEOMTB(   861) /-1431699204/
C                         / Z40800000/
      DATA GEOMTB(   862) / 1082130432/
C                         /ZAAAA/ +  500
      DATA GEOMTB(   863) /-1431698956/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   864) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   865) / 1077936128/
C                         /ZCCCC/ +  208
      DATA GEOMTB(   866) / -859045680/
C                         / Z40001000/
      DATA GEOMTB(   867) / 1073745920/
C                         /ZAAAA/ +  516
      DATA GEOMTB(   868) /-1431698940/
C                         /ZCCCC/ +  214
      DATA GEOMTB(   869) / -859045674/
C                         / Z10800000/
      DATA GEOMTB(   870) /  276824064/
C                         /ZAAAA/ +  284
      DATA GEOMTB(   871) /-1431699172/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   872) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   873) /  146800640/
C                         /ZAAAA/ +  304
      DATA GEOMTB(   874) /-1431699152/
C                         / Z08180000/
      DATA GEOMTB(   875) /  135790592/
C                         /ZAAAA/ +  528
      DATA GEOMTB(   876) /-1431698928/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   877) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   878) /  135790592/
C                         /ZCCCC/ +   65
      DATA GEOMTB(   879) / -859045823/
C                         / Z08001F00/
      DATA GEOMTB(   880) /  134225664/
C                         /ZCCCC/ +   47
      DATA GEOMTB(   881) / -859045841/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   882) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   883) / 1082130432/
C                         /ZAAAA/ +  540
      DATA GEOMTB(   884) /-1431698916/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   885) / -859045688/
C                         / Z40200000/
      DATA GEOMTB(   886) / 1075838976/
C                         / Z40800000/
      DATA GEOMTB(   887) / 1082130432/
C                         /ZCCCC/ +    2
      DATA GEOMTB(   888) / -859045886/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   889) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(   890) /  135790592/
C                         /ZCCCC/ +    3
      DATA GEOMTB(   891) / -859045885/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   892) / -859045688/
C                         / Z0801C000/
      DATA GEOMTB(   893) /  134332416/
C                         / Z40800000/
      DATA GEOMTB(   894) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   895) / 1082130432/
C                         /ZCCCC/ +   48
      DATA GEOMTB(   896) / -859045840/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   897) / -859045688/
C                         / Z0801C000/
      DATA GEOMTB(   898) /  134332416/
C                         / Z40800000/
      DATA GEOMTB(   899) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   900) / 1082130432/
C                         /ZCCCC/ +  184
      DATA GEOMTB(   901) / -859045704/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   902) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   903) / 1082130432/
C                         /ZCCCC/ +   45
      DATA GEOMTB(   904) / -859045843/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   905) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   906) / 1082130432/
C                         /ZCCCC/ +  101
      DATA GEOMTB(   907) / -859045787/
C                         /ZCCCC/ +  102
      DATA GEOMTB(   908) / -859045786/
C                         / Z40400000/
      DATA GEOMTB(   909) / 1077936128/
C                         /ZCCCC/ +  206
      DATA GEOMTB(   910) / -859045682/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   911) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   912) / 1077936128/
C                         /ZCCCC/ +    6
      DATA GEOMTB(   913) / -859045882/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   914) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   915) /  146800640/
C                         /ZCCCC/ +    4
      DATA GEOMTB(   916) / -859045884/
C                         /ZCCCC/ +    1
      DATA GEOMTB(   917) / -859045887/
C                         / Z40800000/
      DATA GEOMTB(   918) / 1082130432/
C                         /ZCCCC/ +  202
      DATA GEOMTB(   919) / -859045686/
C                         /ZCCCC/ +  201
      DATA GEOMTB(   920) / -859045687/
C                         / Z40800000/
      DATA GEOMTB(   921) / 1082130432/
C                         /ZCCCC/ +  204
      DATA GEOMTB(   922) / -859045684/
C                         /ZCCCC/ +  203
      DATA GEOMTB(   923) / -859045685/
C                         / Z40400000/
      DATA GEOMTB(   924) / 1077936128/
C                         /ZCCCC/ +  209
      DATA GEOMTB(   925) / -859045679/
C                         /ZCCCC/ +  211
      DATA GEOMTB(   926) / -859045677/
C                         / Z40800000/
      DATA GEOMTB(   927) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(   928) / 1082130432/
C                         /ZCCCC/ +  205
      DATA GEOMTB(   929) / -859045683/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   930) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   931) / 1077936128/
C                         /ZCCCC/ +  210
      DATA GEOMTB(   932) / -859045678/
C                         /ZCCCC/ +  212
      DATA GEOMTB(   933) / -859045676/
C                         / Z08180000/
      DATA GEOMTB(   934) /  135790592/
C                         /ZCCCC/ +   46
      DATA GEOMTB(   935) / -859045842/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   936) / -859045688/
C                         / Z040E0000/
      DATA GEOMTB(   937) /   68026368/
C                         / Z40800000/
      DATA GEOMTB(   938) / 1082130432/
C                         /ZCCCC/ +   90
      DATA GEOMTB(   939) / -859045798/
C                         /ZCCCC/ +   27
      DATA GEOMTB(   940) / -859045861/
C                         /Z9999/ + 3760
      DATA GEOMTB(   941) /-1718022480/
C                         / Z40800000/
      DATA GEOMTB(   942) / 1082130432/
C                         /ZAAAA/ +   88
      DATA GEOMTB(   943) /-1431699368/
C                         / Z40400000/
      DATA GEOMTB(   944) / 1077936128/
C                         /ZAAAA/ +  120
      DATA GEOMTB(   945) /-1431699336/
C                         / Z40080000/
      DATA GEOMTB(   946) / 1074266112/
C                         /ZAAAA/ +  576
      DATA GEOMTB(   947) /-1431698880/
C                         / Z40001000/
      DATA GEOMTB(   948) / 1073745920/
C                         /ZAAAA/ +  148
      DATA GEOMTB(   949) /-1431699308/
C                         / Z10000040/
      DATA GEOMTB(   950) /  268435520/
C                         /ZAAAA/ +  176
      DATA GEOMTB(   951) /-1431699280/
C                         / Z10000020/
      DATA GEOMTB(   952) /  268435488/
C                         /ZAAAA/ +  592
      DATA GEOMTB(   953) /-1431698864/
C                         / Z40200000/
      DATA GEOMTB(   954) / 1075838976/
C                         /ZAAAA/ +  616
      DATA GEOMTB(   955) /-1431698840/
C                         / Z20080000/
      DATA GEOMTB(   956) /  537395200/
C                         /ZAAAA/ +  636
      DATA GEOMTB(   957) /-1431698820/
C                         / Z10800000/
      DATA GEOMTB(   958) /  276824064/
C                         /ZAAAA/ +  196
      DATA GEOMTB(   959) /-1431699260/
C                         / Z10000200/
      DATA GEOMTB(   960) /  268435968/
C                         /ZAAAA/ +  564
      DATA GEOMTB(   961) /-1431698892/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   962) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   963) / 1082130432/
C                         /ZAAAA/ +  108
      DATA GEOMTB(   964) /-1431699348/
C                         / Z10000010/
      DATA GEOMTB(   965) /  268435472/
C                         /ZAAAA/ +  660
      DATA GEOMTB(   966) /-1431698796/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   967) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(   968) / 1082130432/
C                         /ZAAAA/ +  672
      DATA GEOMTB(   969) /-1431698784/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   970) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(   971) / 1077936128/
C                         /ZCCCC/ +   16
      DATA GEOMTB(   972) / -859045872/
C                         / Z20002000/
      DATA GEOMTB(   973) /  536879104/
C                         /ZAAAA/ +  692
      DATA GEOMTB(   974) /-1431698764/
C                         / Z20001000/
      DATA GEOMTB(   975) /  536875008/
C                         /ZAAAA/ +  704
      DATA GEOMTB(   976) /-1431698752/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   977) / -859045688/
C                         / Z08000080/
      DATA GEOMTB(   978) /  134217856/
C                         /ZAAAA/ +  716
      DATA GEOMTB(   979) /-1431698740/
C                         / Z20002000/
      DATA GEOMTB(   980) /  536879104/
C                         /ZAAAA/ +  692
      DATA GEOMTB(   981) /-1431698764/
C                         / Z20001000/
      DATA GEOMTB(   982) /  536875008/
C                         /ZAAAA/ +  704
      DATA GEOMTB(   983) /-1431698752/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   984) / -859045688/
C                         / Z40401000/
      DATA GEOMTB(   985) / 1077940224/
C                         /ZCCCC/ +   23
      DATA GEOMTB(   986) / -859045865/
C                         / Z40800000/
      DATA GEOMTB(   987) / 1082130432/
C                         /ZAAAA/ +  728
      DATA GEOMTB(   988) /-1431698728/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   989) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(   990) /  146800640/
C                         /ZAAAA/ +  224
      DATA GEOMTB(   991) /-1431699232/
C                         / Z10000100/
      DATA GEOMTB(   992) /  268435712/
C                         /ZAAAA/ +  260
      DATA GEOMTB(   993) /-1431699196/
C                         / Z10000080/
      DATA GEOMTB(   994) /  268435584/
C                         /ZAAAA/ +  316
      DATA GEOMTB(   995) /-1431699140/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   996) / -859045688/
C                         / Z10000100/
      DATA GEOMTB(   997) /  268435712/
C                         /ZAAAA/ +  236
      DATA GEOMTB(   998) /-1431699220/
C                         /ZCCCC/ +  200
      DATA GEOMTB(   999) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1000) / 1077936128/
C                         /ZAAAA/ +  248
      DATA GEOMTB(  1001) /-1431699208/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1002) / -859045688/
C                         / Z400801C0/
      DATA GEOMTB(  1003) / 1074266560/
C                         /ZAAAA/ +  744
      DATA GEOMTB(  1004) /-1431698712/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1005) / -859045688/
C                         / Z2000C000/
      DATA GEOMTB(  1006) /  536920064/
C                         /ZAAAA/ +  272
      DATA GEOMTB(  1007) /-1431699184/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1008) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1009) / 1082130432/
C                         /ZAAAA/ +  284
      DATA GEOMTB(  1010) /-1431699172/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1011) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1012) / 1082130432/
C                         /ZAAAA/ +  304
      DATA GEOMTB(  1013) /-1431699152/
C                         / Z400801C0/
      DATA GEOMTB(  1014) / 1074266560/
C                         /ZAAAA/ +  756
      DATA GEOMTB(  1015) /-1431698700/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1016) / -859045688/
C                         / Z400801C0/
      DATA GEOMTB(  1017) / 1074266560/
C                         /ZAAAA/ +  768
      DATA GEOMTB(  1018) /-1431698688/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1019) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1020) / 1082130432/
C                         /ZAAAA/ +  344
      DATA GEOMTB(  1021) /-1431699112/
C                         / Z40400000/
      DATA GEOMTB(  1022) / 1077936128/
C                         /ZAAAA/ +  388
      DATA GEOMTB(  1023) /-1431699068/
C                         / Z2000C000/
      DATA GEOMTB(  1024) /  536920064/
C                         /ZAAAA/ +  460
      DATA GEOMTB(  1025) /-1431698996/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1026) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1027) / 1082130432/
C                         /ZAAAA/ +  356
      DATA GEOMTB(  1028) /-1431699100/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1029) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1030) / 1082130432/
C                         /ZAAAA/ +  376
      DATA GEOMTB(  1031) /-1431699080/
C                         / Z40080180/
      DATA GEOMTB(  1032) / 1074266496/
C                         /ZAAAA/ +  780
      DATA GEOMTB(  1033) /-1431698676/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1034) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1035) / 1074266496/
C                         /ZAAAA/ +  792
      DATA GEOMTB(  1036) /-1431698664/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1037) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1038) / 1077936128/
C                         /ZAAAA/ +  416
      DATA GEOMTB(  1039) /-1431699040/
C                         / Z40001000/
      DATA GEOMTB(  1040) / 1073745920/
C                         /ZAAAA/ +  428
      DATA GEOMTB(  1041) /-1431699028/
C                         / Z40080180/
      DATA GEOMTB(  1042) / 1074266496/
C                         /ZAAAA/ +  804
      DATA GEOMTB(  1043) /-1431698652/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1044) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1045) / 1074266496/
C                         /ZAAAA/ +  816
      DATA GEOMTB(  1046) /-1431698640/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1047) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1048) / 1077936128/
C                         /ZAAAA/ +  448
      DATA GEOMTB(  1049) /-1431699008/
C                         / Z40080180/
      DATA GEOMTB(  1050) / 1074266496/
C                         /ZAAAA/ +  828
      DATA GEOMTB(  1051) /-1431698628/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1052) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1053) / 1074266496/
C                         /ZAAAA/ +  840
      DATA GEOMTB(  1054) /-1431698616/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1055) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1056) / 1082130432/
C                         /ZAAAA/ +  480
      DATA GEOMTB(  1057) /-1431698976/
C                         / Z40400000/
      DATA GEOMTB(  1058) / 1077936128/
C                         /ZAAAA/ +  516
      DATA GEOMTB(  1059) /-1431698940/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1060) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1061) / 1082130432/
C                         /ZAAAA/ +  492
      DATA GEOMTB(  1062) /-1431698964/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1063) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1064) / 1082130432/
C                         /ZAAAA/ +  504
      DATA GEOMTB(  1065) /-1431698952/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1066) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1067) / 1074266496/
C                         /ZAAAA/ +  852
      DATA GEOMTB(  1068) /-1431698604/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1069) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1070) / 1074266496/
C                         /ZCCCC/ +  229
      DATA GEOMTB(  1071) / -859045659/
C                         / Z40001000/
      DATA GEOMTB(  1072) / 1073745920/
C                         /ZAAAA/ +  544
      DATA GEOMTB(  1073) /-1431698912/
C                         / Z40400000/
      DATA GEOMTB(  1074) / 1077936128/
C                         /ZAAAA/ +  864
      DATA GEOMTB(  1075) /-1431698592/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1076) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1077) / 1074266496/
C                         /ZCCCC/ +  235
      DATA GEOMTB(  1078) / -859045653/
C                         / Z40400000/
      DATA GEOMTB(  1079) / 1077936128/
C                         /ZAAAA/ +  876
      DATA GEOMTB(  1080) /-1431698580/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1081) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1082) / 1082130432/
C                         /ZAAAA/ +  888
      DATA GEOMTB(  1083) /-1431698568/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1084) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(  1085) /  146800640/
C                         / Z4007E000/
      DATA GEOMTB(  1086) / 1074257920/
C                         /ZCCCC/ +   60
      DATA GEOMTB(  1087) / -859045828/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1088) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1089) / 1082130432/
C                         / Z40200000/
      DATA GEOMTB(  1090) / 1075838976/
C                         / Z40800000/
      DATA GEOMTB(  1091) / 1082130432/
C                         / Z0801C000/
      DATA GEOMTB(  1092) /  134332416/
C                         /ZCCCC/ +   61
      DATA GEOMTB(  1093) / -859045827/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1094) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1095) / 1082130432/
C                         / Z08C00000/
      DATA GEOMTB(  1096) /  146800640/
C                         / Z40078000/
      DATA GEOMTB(  1097) / 1074233344/
C                         /ZCCCC/ +   77
      DATA GEOMTB(  1098) / -859045811/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1099) / -859045688/
C                         / Z10800000/
      DATA GEOMTB(  1100) /  276824064/
C                         / Z08C00000/
      DATA GEOMTB(  1101) /  146800640/
C                         / Z08C00000/
      DATA GEOMTB(  1102) /  146800640/
C                         / Z4007E000/
      DATA GEOMTB(  1103) / 1074257920/
C                         /ZCCCC/ +   75
      DATA GEOMTB(  1104) / -859045813/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1105) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1106) / 1073745920/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1107) / -859045869/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1108) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1109) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  1110) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  1111) / 1082130432/
C                         /ZCCCC/ +  100
      DATA GEOMTB(  1112) / -859045788/
C                         /ZCCCC/ +  106
      DATA GEOMTB(  1113) / -859045782/
C                         / Z40401000/
      DATA GEOMTB(  1114) / 1077940224/
C                         /ZCCCC/ +   22
      DATA GEOMTB(  1115) / -859045866/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1116) / -859045688/
C                         / Z40401000/
      DATA GEOMTB(  1117) / 1077940224/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1118) / -859045867/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1119) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1120) / 1073745920/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  1121) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1122) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1123) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  1124) / 1082130432/
C                         /ZCCCC/ +  107
      DATA GEOMTB(  1125) / -859045781/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1126) / -859045688/
C                         / Z10000040/
      DATA GEOMTB(  1127) /  268435520/
C                         /ZCCCC/ +  226
      DATA GEOMTB(  1128) / -859045662/
C                         /ZCCCC/ +  225
      DATA GEOMTB(  1129) / -859045663/
C                         / Z10000040/
      DATA GEOMTB(  1130) /  268435520/
C                         /ZCCCC/ +  215
      DATA GEOMTB(  1131) / -859045673/
C                         /ZCCCC/ +  217
      DATA GEOMTB(  1132) / -859045671/
C                         / Z10000040/
      DATA GEOMTB(  1133) /  268435520/
C                         /ZCCCC/ +  216
      DATA GEOMTB(  1134) / -859045672/
C                         /ZCCCC/ +  218
      DATA GEOMTB(  1135) / -859045670/
C                         / Z10000040/
      DATA GEOMTB(  1136) /  268435520/
C                         /ZCCCC/ +  219
      DATA GEOMTB(  1137) / -859045669/
C                         /ZCCCC/ +  222
      DATA GEOMTB(  1138) / -859045666/
C                         / Z10000040/
      DATA GEOMTB(  1139) /  268435520/
C                         /ZCCCC/ +  220
      DATA GEOMTB(  1140) / -859045668/
C                         /ZCCCC/ +  223
      DATA GEOMTB(  1141) / -859045665/
C                         / Z10000040/
      DATA GEOMTB(  1142) /  268435520/
C                         /ZCCCC/ +  228
      DATA GEOMTB(  1143) / -859045660/
C                         /ZCCCC/ +  227
      DATA GEOMTB(  1144) / -859045661/
C                         / Z10000040/
      DATA GEOMTB(  1145) /  268435520/
C                         /ZCCCC/ +  231
      DATA GEOMTB(  1146) / -859045657/
C                         /ZCCCC/ +  230
      DATA GEOMTB(  1147) / -859045658/
C                         / Z10000040/
      DATA GEOMTB(  1148) /  268435520/
C                         /ZCCCC/ +  234
      DATA GEOMTB(  1149) / -859045654/
C                         /ZCCCC/ +  233
      DATA GEOMTB(  1150) / -859045655/
C                         / Z10000040/
      DATA GEOMTB(  1151) /  268435520/
C                         /ZCCCC/ +  237
      DATA GEOMTB(  1152) / -859045651/
C                         /ZCCCC/ +  236
      DATA GEOMTB(  1153) / -859045652/
C                         / Z10000040/
      DATA GEOMTB(  1154) /  268435520/
C                         /ZCCCC/ +  221
      DATA GEOMTB(  1155) / -859045667/
C                         /ZCCCC/ +  224
      DATA GEOMTB(  1156) / -859045664/
C                         / Z40080180/
      DATA GEOMTB(  1157) / 1074266496/
C                         /ZCCCC/ +  232
      DATA GEOMTB(  1158) / -859045656/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1159) / -859045688/
C                         / Z40080180/
      DATA GEOMTB(  1160) / 1074266496/
C                         /ZCCCC/ +  238
      DATA GEOMTB(  1161) / -859045650/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1162) / -859045688/
C                         / Z0401E000/
      DATA GEOMTB(  1163) /   67231744/
C                         / Z40800000/
      DATA GEOMTB(  1164) / 1082130432/
C                         /ZCCCC/ +   90
      DATA GEOMTB(  1165) / -859045798/
C                         /ZCCCC/ +   27
      DATA GEOMTB(  1166) / -859045861/
C                         /Z9999/ + 4664
      DATA GEOMTB(  1167) /-1718021576/
C                         /ZCCCC/ +  301
      DATA GEOMTB(  1168) / -859045587/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1169) / -859045688/
C                         /Z9999/ + 4676
      DATA GEOMTB(  1170) /-1718021564/
C                         / Z08F81F60/
      DATA GEOMTB(  1171) /  150478688/
C                         /ZAAAA/ +   16
      DATA GEOMTB(  1172) /-1431699440/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1173) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1174) / 1077936128/
C                         /ZAAAA/ +   28
      DATA GEOMTB(  1175) /-1431699428/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1176) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1177) / 1077936128/
C                         /ZAAAA/ +   40
      DATA GEOMTB(  1178) /-1431699416/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1179) / -859045688/
C                         / Z40401000/
      DATA GEOMTB(  1180) / 1077940224/
C                         /ZAAAA/ +   52
      DATA GEOMTB(  1181) /-1431699404/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1182) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1183) / 1077936128/
C                         /ZCCCC/ +  401
      DATA GEOMTB(  1184) / -859045487/
C                         / Z08F81F60/
      DATA GEOMTB(  1185) /  150478688/
C                         /ZAAAA/ +   72
      DATA GEOMTB(  1186) /-1431699384/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1187) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1188) / 1077936128/
C                         / Z40400000/
      DATA GEOMTB(  1189) / 1077936128/
C                         / Z40401000/
      DATA GEOMTB(  1190) / 1077940224/
C                         /ZCCCC/ +  402
      DATA GEOMTB(  1191) / -859045486/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1192) / -859045688/
C                         /Z9999/ + 4768
      DATA GEOMTB(  1193) /-1718021472/
C                         / Z02800000/
      DATA GEOMTB(  1194) /   41943040/
C                         /ZAAAA/ +   72
      DATA GEOMTB(  1195) /-1431699384/
C                         / Z04001000/
      DATA GEOMTB(  1196) /   67112960/
C                         /ZAAAA/ +  124
      DATA GEOMTB(  1197) /-1431699332/
C                         / Z02400000/
      DATA GEOMTB(  1198) /   37748736/
C                         /ZAAAA/ +  156
      DATA GEOMTB(  1199) /-1431699300/
C                         / Z20000C00/
      DATA GEOMTB(  1200) /  536873984/
C                         /ZAAAA/ +  200
      DATA GEOMTB(  1201) /-1431699256/
C                         / Z02200000/
      DATA GEOMTB(  1202) /   35651584/
C                         /ZAAAA/ +  288
      DATA GEOMTB(  1203) /-1431699168/
C                         / Z04100800/
      DATA GEOMTB(  1204) /   68159488/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1205) / -859045875/
C                         / Z02100000/
      DATA GEOMTB(  1206) /   34603008/
C                         /ZAAAA/ +  252
      DATA GEOMTB(  1207) /-1431699204/
C                         / Z20000300/
      DATA GEOMTB(  1208) /  536871680/
C                         /ZAAAA/ +  276
      DATA GEOMTB(  1209) /-1431699180/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1210) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1211) / 1077936128/
C                         /ZAAAA/ +   84
      DATA GEOMTB(  1212) /-1431699372/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1213) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1214) / 1073745920/
C                         /ZAAAA/ +  104
      DATA GEOMTB(  1215) /-1431699352/
C                         / Z40400000/
      DATA GEOMTB(  1216) / 1077936128/
C                         /ZAAAA/ +  300
      DATA GEOMTB(  1217) /-1431699156/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1218) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1219) / 1082130432/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  1220) / -859045886/
C                         / Z04001000/
      DATA GEOMTB(  1221) /   67112960/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  1222) / -859045885/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1223) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1224) / 1082130432/
C                         /ZAAAA/ +  136
      DATA GEOMTB(  1225) /-1431699320/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1226) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1227) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  1228) / -859045878/
C                         / Z04000400/
      DATA GEOMTB(  1229) /   67109888/
C                         /ZAAAA/ +  312
      DATA GEOMTB(  1230) /-1431699144/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1231) / -859045688/
C                         / Z08180000/
      DATA GEOMTB(  1232) /  135790592/
C                         /ZAAAA/ +  168
      DATA GEOMTB(  1233) /-1431699288/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1234) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1235) / 1082130432/
C                         /ZAAAA/ +  180
      DATA GEOMTB(  1236) /-1431699276/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1237) / -859045688/
C                         / Z200000C0/
      DATA GEOMTB(  1238) /  536871104/
C                         /ZAAAA/ +  324
      DATA GEOMTB(  1239) /-1431699132/
C                         / Z40800000/
      DATA GEOMTB(  1240) / 1082130432/
C                         /ZAAAA/ +  336
      DATA GEOMTB(  1241) /-1431699120/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1242) / -859045688/
C                         / Z40000200/
      DATA GEOMTB(  1243) / 1073742336/
C                         /ZAAAA/ +  212
      DATA GEOMTB(  1244) /-1431699244/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1245) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1246) / 1073745920/
C                         /ZAAAA/ +  232
      DATA GEOMTB(  1247) /-1431699224/
C                         / Z40000200/
      DATA GEOMTB(  1248) / 1073742336/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1249) / -859045882/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1250) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1251) / 1082130432/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1252) / -859045881/
C                         / Z04001000/
      DATA GEOMTB(  1253) /   67112960/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1254) / -859045880/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1255) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1256) / 1082130432/
C                         /ZAAAA/ +  264
      DATA GEOMTB(  1257) /-1431699192/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1258) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1259) / 1082130432/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1260) /-1431699104/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1261) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1262) / 1082130432/
C                         /ZAAAA/ +  368
      DATA GEOMTB(  1263) /-1431699088/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1264) / -859045688/
C                         / Z40400200/
      DATA GEOMTB(  1265) / 1077936640/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  1266) / -859045879/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1267) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1268) / 1082130432/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1269) / -859045887/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1270) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1271) / 1082130432/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1272) / -859045877/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1273) / -859045688/
C                         / Z04001000/
      DATA GEOMTB(  1274) /   67112960/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1275) / -859045883/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1276) / -859045688/
C                         / Z200000C0/
      DATA GEOMTB(  1277) /  536871104/
C                         / Z40800000/
      DATA GEOMTB(  1278) / 1082130432/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1279) / -859045884/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1280) / -859045688/
C                         / Z04000200/
      DATA GEOMTB(  1281) /   67109376/
C                         / Z40800000/
      DATA GEOMTB(  1282) / 1082130432/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1283) / -859045874/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1284) / -859045872/
C                         / Z04000200/
      DATA GEOMTB(  1285) /   67109376/
C                         / Z40800000/
      DATA GEOMTB(  1286) / 1082130432/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1287) / -859045873/
C                         /ZCCCC/ +   17
      DATA GEOMTB(  1288) / -859045871/
C                         /Z9999/ + 5152
      DATA GEOMTB(  1289) /-1718021088/
C                         / Z08F81F70/
      DATA GEOMTB(  1290) /  150478704/
C                         /ZAAAA/ +   16
      DATA GEOMTB(  1291) /-1431699440/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1292) / -859045688/
C                         / Z40800C00/
      DATA GEOMTB(  1293) / 1082133504/
C                         /ZCCCC/ +  185
      DATA GEOMTB(  1294) / -859045703/
C                         / Z4047E000/
      DATA GEOMTB(  1295) / 1078452224/
C                         /ZCCCC/ +  186
      DATA GEOMTB(  1296) / -859045702/
C                         /ZCCCC/ +   86
      DATA GEOMTB(  1297) / -859045802/
C                         /Z9999/ + 5188
      DATA GEOMTB(  1298) /-1718021052/
C                         / Z08000018/
      DATA GEOMTB(  1299) /  134217752/
C                         /ZCCCC/ +   87
      DATA GEOMTB(  1300) / -859045801/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1301) / -859045688/
C                         /Z9999/ + 5204
      DATA GEOMTB(  1302) /-1718021036/
C                         / Z04000100/
      DATA GEOMTB(  1303) /   67109120/
C                         /ZAAAA/ +   84
      DATA GEOMTB(  1304) /-1431699372/
C                         / Z40800000/
      DATA GEOMTB(  1305) / 1082130432/
C                         /ZAAAA/ +   32
      DATA GEOMTB(  1306) /-1431699424/
C                         / Z04000200/
      DATA GEOMTB(  1307) /   67109376/
C                         /ZAAAA/ +   64
      DATA GEOMTB(  1308) /-1431699392/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1309) / -859045688/
C                         / Z04000200/
      DATA GEOMTB(  1310) /   67109376/
C                         /ZAAAA/ +   44
      DATA GEOMTB(  1311) /-1431699412/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1312) / -859045688/
C                         / Z04000100/
      DATA GEOMTB(  1313) /   67109120/
C                         /ZAAAA/ +  100
      DATA GEOMTB(  1314) /-1431699356/
C                         / Z40800000/
      DATA GEOMTB(  1315) / 1082130432/
C                         /ZAAAA/ +  116
      DATA GEOMTB(  1316) /-1431699340/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1317) / -859045688/
C                         / Z04000100/
      DATA GEOMTB(  1318) /   67109120/
C                         /ZAAAA/ +  132
      DATA GEOMTB(  1319) /-1431699324/
C                         / Z40800000/
      DATA GEOMTB(  1320) / 1082130432/
C                         /ZAAAA/ +  148
      DATA GEOMTB(  1321) /-1431699308/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1322) / -859045688/
C                         / Z04001080/
      DATA GEOMTB(  1323) /   67113088/
C                         / Z40800000/
      DATA GEOMTB(  1324) / 1082130432/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1325) / -859045882/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1326) / -859045887/
C                         / Z04001080/
      DATA GEOMTB(  1327) /   67113088/
C                         / Z40800000/
      DATA GEOMTB(  1328) / 1082130432/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  1329) / -859045879/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1330) / -859045884/
C                         / Z04001080/
      DATA GEOMTB(  1331) /   67113088/
C                         / Z40800000/
      DATA GEOMTB(  1332) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  1333) / -859045878/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1334) / -859045883/
C                         / Z04001080/
      DATA GEOMTB(  1335) /   67113088/
C                         / Z40800000/
      DATA GEOMTB(  1336) / 1082130432/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1337) / -859045881/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  1338) / -859045886/
C                         / Z04001080/
      DATA GEOMTB(  1339) /   67113088/
C                         / Z40800000/
      DATA GEOMTB(  1340) / 1082130432/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1341) / -859045880/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  1342) / -859045885/
C                         /Z9999/ + 5368
      DATA GEOMTB(  1343) /-1718020872/
C                         / Z40400000/
      DATA GEOMTB(  1344) / 1077936128/
C                         /ZAAAA/ +  144
      DATA GEOMTB(  1345) /-1431699312/
C                         / Z40080180/
      DATA GEOMTB(  1346) / 1074266496/
C                         /ZAAAA/ +  272
      DATA GEOMTB(  1347) /-1431699184/
C                         / Z20000030/
      DATA GEOMTB(  1348) /  536870960/
C                         /ZAAAA/ +  192
      DATA GEOMTB(  1349) /-1431699264/
C                         / Z10000100/
      DATA GEOMTB(  1350) /  268435712/
C                         /ZAAAA/ +  212
      DATA GEOMTB(  1351) /-1431699244/
C                         / Z08900000/
      DATA GEOMTB(  1352) /  143654912/
C                         /ZAAAA/ +  232
      DATA GEOMTB(  1353) /-1431699224/
C                         / Z02080000/
      DATA GEOMTB(  1354) /   34078720/
C                         /ZAAAA/ +  288
      DATA GEOMTB(  1355) /-1431699168/
C                         / Z40078000/
      DATA GEOMTB(  1356) / 1074233344/
C                         /ZAAAA/ +  300
      DATA GEOMTB(  1357) /-1431699156/
C                         / Z20004000/
      DATA GEOMTB(  1358) /  536887296/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  1359) / -859045878/
C                         / Z20008000/
      DATA GEOMTB(  1360) /  536903680/
C                         /ZAAAA/ +  252
      DATA GEOMTB(  1361) /-1431699204/
C                         / Z02400000/
      DATA GEOMTB(  1362) /   37748736/
C                         /ZAAAA/ +  316
      DATA GEOMTB(  1363) /-1431699140/
C                         / Z04000060/
      DATA GEOMTB(  1364) /   67108960/
C                         /ZAAAA/ +  328
      DATA GEOMTB(  1365) /-1431699128/
C                         / Z02040000/
      DATA GEOMTB(  1366) /   33816576/
C                         /ZAAAA/ +  340
      DATA GEOMTB(  1367) /-1431699116/
C                         / Z1000000C/
      DATA GEOMTB(  1368) /  268435468/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1369) /-1431699104/
C                         / Z02020000/
      DATA GEOMTB(  1370) /   33685504/
C                         /ZAAAA/ +  364
      DATA GEOMTB(  1371) /-1431699092/
C                         / Z40801000/
      DATA GEOMTB(  1372) / 1082134528/
C                         /ZAAAA/ +  376
      DATA GEOMTB(  1373) /-1431699080/
C                         / Z10000020/
      DATA GEOMTB(  1374) /  268435488/
C                         /ZAAAA/ +  388
      DATA GEOMTB(  1375) /-1431699068/
C                         / Z10001000/
      DATA GEOMTB(  1376) /  268439552/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1377) / -859045869/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1378) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1379) / 1077936128/
C                         /ZAAAA/ +  172
      DATA GEOMTB(  1380) /-1431699284/
C                         / Z20010008/
      DATA GEOMTB(  1381) /  536936456/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1382) / -859045887/
C                         / Z20004000/
      DATA GEOMTB(  1383) /  536887296/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1384) / -859045872/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1385) / -859045688/
C                         / Z20000008/
      DATA GEOMTB(  1386) /  536870920/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  1387) / -859045886/
C                         / Z20010000/
      DATA GEOMTB(  1388) /  536936448/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  1389) / -859045885/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1390) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1391) /  536936448/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1392) / -859045883/
C                         / Z40400000/
      DATA GEOMTB(  1393) / 1077936128/
C                         /ZAAAA/ +  400
      DATA GEOMTB(  1394) /-1431699056/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1395) / -859045688/
C                         / Z02010000/
      DATA GEOMTB(  1396) /   33619968/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1397) / -859045882/
C                         / Z10000100/
      DATA GEOMTB(  1398) /  268435712/
C                         /ZAAAA/ +  412
      DATA GEOMTB(  1399) /-1431699044/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1400) / -859045688/
C                         / Z08900000/
      DATA GEOMTB(  1401) /  143654912/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1402) / -859045880/
C                         / Z02080000/
      DATA GEOMTB(  1403) /   34078720/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1404) / -859045880/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1405) / -859045688/
C                         / Z02080000/
      DATA GEOMTB(  1406) /   34078720/
C                         /ZCCCC/ +   18
      DATA GEOMTB(  1407) / -859045870/
C                         / Z20004000/
      DATA GEOMTB(  1408) /  536887296/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1409) / -859045877/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1410) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1411) / 1077936128/
C                         / Z20010008/
      DATA GEOMTB(  1412) /  536936456/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1413) / -859045884/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1414) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1415) /  536887296/
C                         /ZCCCC/ +   17
      DATA GEOMTB(  1416) / -859045871/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1417) / -859045688/
C                         / Z08900000/
      DATA GEOMTB(  1418) /  143654912/
C                         / Z08900000/
      DATA GEOMTB(  1419) /  143654912/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  1420) / -859045879/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1421) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1422) /  536887296/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1423) / -859045877/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1424) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1425) /  536887296/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1426) / -859045876/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1427) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1428) /  536887296/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1429) / -859045875/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1430) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1431) /  536887296/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1432) / -859045874/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1433) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1434) /  536887296/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1435) / -859045873/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1436) / -859045688/
C                         / Z20004000/
      DATA GEOMTB(  1437) /  536887296/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1438) / -859045872/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1439) / -859045688/
C                         / Z02080000/
      DATA GEOMTB(  1440) /   34078720/
C                         /ZCCCC/ +   18
      DATA GEOMTB(  1441) / -859045870/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1442) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1443) /  536936448/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1444) / -859045883/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1445) / -859045688/
C                         / Z02010000/
      DATA GEOMTB(  1446) /   33619968/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1447) / -859045881/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1448) / -859045688/
C                         /Z9999/ + 5792
      DATA GEOMTB(  1449) /-1718020448/
C                         / Z40400000/
      DATA GEOMTB(  1450) / 1077936128/
C                         /ZAAAA/ +  120
      DATA GEOMTB(  1451) /-1431699336/
C                         / Z20010000/
      DATA GEOMTB(  1452) /  536936448/
C                         /ZAAAA/ +  140
      DATA GEOMTB(  1453) /-1431699316/
C                         / Z08040000/
      DATA GEOMTB(  1454) /  134479872/
C                         /ZAAAA/ +  280
      DATA GEOMTB(  1455) /-1431699176/
C                         / Z0801C004/
      DATA GEOMTB(  1456) /  134332420/
C                         /ZAAAA/ +  280
      DATA GEOMTB(  1457) /-1431699176/
C                         / Z20000030/
      DATA GEOMTB(  1458) /  536870960/
C                         /ZAAAA/ +  160
      DATA GEOMTB(  1459) /-1431699296/
C                         / Z40080180/
      DATA GEOMTB(  1460) / 1074266496/
C                         /ZAAAA/ +  292
      DATA GEOMTB(  1461) /-1431699164/
C                         / Z20000007/
      DATA GEOMTB(  1462) /  536870919/
C                         /ZAAAA/ +  312
      DATA GEOMTB(  1463) /-1431699144/
C                         / Z20003000/
      DATA GEOMTB(  1464) /  536883200/
C                         /ZAAAA/ +  324
      DATA GEOMTB(  1465) /-1431699132/
C                         / Z10000100/
      DATA GEOMTB(  1466) /  268435712/
C                         /ZAAAA/ +  180
      DATA GEOMTB(  1467) /-1431699276/
C                         / Z40000020/
      DATA GEOMTB(  1468) / 1073741856/
C                         /ZAAAA/ +  336
      DATA GEOMTB(  1469) /-1431699120/
C                         / Z200000C0/
      DATA GEOMTB(  1470) /  536871104/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1471) /-1431699104/
C                         / Z08000080/
      DATA GEOMTB(  1472) /  134217856/
C                         /ZAAAA/ +  228
      DATA GEOMTB(  1473) /-1431699228/
C                         / Z10000080/
      DATA GEOMTB(  1474) /  268435584/
C                         /ZAAAA/ +  260
      DATA GEOMTB(  1475) /-1431699196/
C                         / Z10001000/
      DATA GEOMTB(  1476) /  268439552/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1477) / -859045869/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1478) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1479) /  536936448/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1480) / -859045887/
C                         / Z40400000/
      DATA GEOMTB(  1481) / 1077936128/
C                         /ZAAAA/ +  368
      DATA GEOMTB(  1482) /-1431699088/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1483) / -859045688/
C                         / Z0805C000/
      DATA GEOMTB(  1484) /  134594560/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1485) / -859045867/
C                         / Z40400000/
      DATA GEOMTB(  1486) / 1077936128/
C                         /ZAAAA/ +  380
      DATA GEOMTB(  1487) /-1431699076/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1488) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1489) /  536936448/
C                         /ZAAAA/ +  396
      DATA GEOMTB(  1490) /-1431699060/
C                         / Z40400000/
      DATA GEOMTB(  1491) / 1077936128/
C                         /ZAAAA/ +  392
      DATA GEOMTB(  1492) /-1431699064/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1493) / -859045688/
C                         / Z08000007/
      DATA GEOMTB(  1494) /  134217735/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1495) / -859045887/
C                         / Z0803E000/
      DATA GEOMTB(  1496) /  134471680/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1497) / -859045887/
C                         / Z10000100/
      DATA GEOMTB(  1498) /  268435712/
C                         /ZAAAA/ +  208
      DATA GEOMTB(  1499) /-1431699248/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1500) / -859045688/
C                         / Z08000004/
      DATA GEOMTB(  1501) /  134217732/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1502) / -859045882/
C                         / Z08000081/
      DATA GEOMTB(  1503) /  134217857/
C                         /ZCCCC/ +   26
      DATA GEOMTB(  1504) / -859045862/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1505) / -859045688/
C                         / Z10000100/
      DATA GEOMTB(  1506) /  268435712/
C                         /ZAAAA/ +  240
      DATA GEOMTB(  1507) /-1431699216/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1508) / -859045688/
C                         / Z0803E000/
      DATA GEOMTB(  1509) /  134471680/
C                         /ZCCCC/ +   27
      DATA GEOMTB(  1510) / -859045861/
C                         / Z08000001/
      DATA GEOMTB(  1511) /  134217729/
C                         /ZCCCC/ +   26
      DATA GEOMTB(  1512) / -859045862/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1513) / -859045688/
C                         / Z02010000/
      DATA GEOMTB(  1514) /   33619968/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1515) / -859045882/
C                         / Z10000080/
      DATA GEOMTB(  1516) /  268435584/
C                         /ZAAAA/ +  408
      DATA GEOMTB(  1517) /-1431699048/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1518) / -859045688/
C                         / Z02008000/
      DATA GEOMTB(  1519) /   33587200/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  1520) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1521) / -859045688/
C                         / Z40400000/
      DATA GEOMTB(  1522) / 1077936128/
C                         / Z20010000/
      DATA GEOMTB(  1523) /  536936448/
C                         / Z0805C000/
      DATA GEOMTB(  1524) /  134594560/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1525) / -859045884/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1526) / -859045688/
C                         / Z02004000/
      DATA GEOMTB(  1527) /   33570816/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  1528) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1529) / -859045688/
C                         / Z20000007/
      DATA GEOMTB(  1530) /  536870919/
C                         /ZCCCC/ +   23
      DATA GEOMTB(  1531) / -859045865/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1532) / -859045688/
C                         / Z10000100/
      DATA GEOMTB(  1533) /  268435712/
C                         / Z08000006/
      DATA GEOMTB(  1534) /  134217734/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1535) / -859045864/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1536) / -859045688/
C                         / Z40000020/
      DATA GEOMTB(  1537) / 1073741856/
C                         / Z08000002/
      DATA GEOMTB(  1538) /  134217730/
C                         /ZCCCC/ +   25
      DATA GEOMTB(  1539) / -859045863/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1540) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1541) /  536936448/
C                         /ZCCCC/ +   22
      DATA GEOMTB(  1542) / -859045866/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1543) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1544) /  536936448/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1545) / -859045867/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1546) / -859045688/
C                         / Z20010000/
      DATA GEOMTB(  1547) /  536936448/
C                         / Z08040000/
      DATA GEOMTB(  1548) /  134479872/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1549) / -859045883/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1550) / -859045688/
C                         / Z02010000/
      DATA GEOMTB(  1551) /   33619968/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1552) / -859045881/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1553) / -859045688/
C                         /Z9999/ + 6212
      DATA GEOMTB(  1554) /-1718020028/
C                         / Z0400021C/
      DATA GEOMTB(  1555) /   67109404/
C                         /ZAAAA/ +   64
      DATA GEOMTB(  1556) /-1431699392/
C                         / Z04000102/
      DATA GEOMTB(  1557) /   67109122/
C                         /ZCCCC/ +   26
      DATA GEOMTB(  1558) / -859045862/
C                         / Z02002000/
      DATA GEOMTB(  1559) /   33562624/
C                         /ZAAAA/ +  156
      DATA GEOMTB(  1560) /-1431699300/
C                         / Z40080000/
      DATA GEOMTB(  1561) / 1074266112/
C                         /ZAAAA/ +  168
      DATA GEOMTB(  1562) /-1431699288/
C                         / Z20080000/
      DATA GEOMTB(  1563) /  537395200/
C                         /ZAAAA/ +  180
      DATA GEOMTB(  1564) /-1431699276/
C                         / Z40000010/
      DATA GEOMTB(  1565) / 1073741840/
C                         /ZAAAA/ +  192
      DATA GEOMTB(  1566) /-1431699264/
C                         / Z02001000/
      DATA GEOMTB(  1567) /   33558528/
C                         /ZAAAA/ +  136
      DATA GEOMTB(  1568) /-1431699320/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1569) / -859045688/
C                         / Z04000102/
      DATA GEOMTB(  1570) /   67109122/
C                         /ZCCCC/ +   25
      DATA GEOMTB(  1571) / -859045863/
C                         / Z02001000/
      DATA GEOMTB(  1572) /   33558528/
C                         /ZAAAA/ +  116
      DATA GEOMTB(  1573) /-1431699340/
C                         / Z40000010/
      DATA GEOMTB(  1574) / 1073741840/
C                         /ZAAAA/ +  204
      DATA GEOMTB(  1575) /-1431699252/
C                         / Z20080000/
      DATA GEOMTB(  1576) /  537395200/
C                         /ZAAAA/ +  216
      DATA GEOMTB(  1577) /-1431699240/
C                         / Z40080000/
      DATA GEOMTB(  1578) / 1074266112/
C                         /ZAAAA/ +  228
      DATA GEOMTB(  1579) /-1431699228/
C                         / Z02002000/
      DATA GEOMTB(  1580) /   33562624/
C                         /ZAAAA/ +  240
      DATA GEOMTB(  1581) /-1431699216/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1582) / -859045688/
C                         / Z10000080/
      DATA GEOMTB(  1583) /  268435584/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1584) / -859045869/
C                         / Z08D80060/
      DATA GEOMTB(  1585) /  148373600/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1586) / -859045869/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1587) / -859045688/
C                         / Z10000080/
      DATA GEOMTB(  1588) /  268435584/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1589) / -859045864/
C                         / Z08D80060/
      DATA GEOMTB(  1590) /  148373600/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1591) / -859045864/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1592) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1593) / 1082130432/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  1594) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1595) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1596) / 1082130432/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1597) / -859045867/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1598) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1599) / 1073745920/
C                         /ZCCCC/ +   22
      DATA GEOMTB(  1600) / -859045866/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1601) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1602) / 1082130432/
C                         /ZCCCC/ +   23
      DATA GEOMTB(  1603) / -859045865/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1604) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1605) / 1082130432/
C                         /ZCCCC/ +   18
      DATA GEOMTB(  1606) / -859045870/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1607) / -859045688/
C                         / Z40001000/
      DATA GEOMTB(  1608) / 1073745920/
C                         /ZCCCC/ +   17
      DATA GEOMTB(  1609) / -859045871/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1610) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1611) / 1082130432/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1612) / -859045872/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1613) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1614) / 1082130432/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1615) / -859045873/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1616) / -859045688/
C                         /Z9999/ + 6464
      DATA GEOMTB(  1617) /-1718019776/
C                         / Z10000080/
      DATA GEOMTB(  1618) /  268435584/
C                         /ZAAAA/ +   64
      DATA GEOMTB(  1619) /-1431699392/
C                         / Z04000801/
      DATA GEOMTB(  1620) /   67110913/
C                         /ZAAAA/ +  112
      DATA GEOMTB(  1621) /-1431699344/
C                         / Z10000100/
      DATA GEOMTB(  1622) /  268435712/
C                         /ZAAAA/ +  296
      DATA GEOMTB(  1623) /-1431699160/
C                         / Z04000400/
      DATA GEOMTB(  1624) /   67109888/
C                         /ZAAAA/ +  196
      DATA GEOMTB(  1625) /-1431699260/
C                         / Z04100000/
      DATA GEOMTB(  1626) /   68157440/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1627) / -859045875/
C                         / Z04000010/
      DATA GEOMTB(  1628) /   67108880/
C                         /ZAAAA/ +  240
      DATA GEOMTB(  1629) /-1431699216/
C                         / Z04000200/
      DATA GEOMTB(  1630) /   67109376/
C                         /ZAAAA/ +  284
      DATA GEOMTB(  1631) /-1431699172/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1632) / -859045688/
C                         / Z02000800/
      DATA GEOMTB(  1633) /   33556480/
C                         /ZAAAA/ +   76
      DATA GEOMTB(  1634) /-1431699380/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1635) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1636) / 1082130432/
C                         /ZAAAA/ +   88
      DATA GEOMTB(  1637) /-1431699368/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1638) / -859045688/
C                         / Z40000008/
      DATA GEOMTB(  1639) / 1073741832/
C                         /ZAAAA/ +  100
      DATA GEOMTB(  1640) /-1431699356/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1641) / -859045877/
C                         / Z40800000/
      DATA GEOMTB(  1642) / 1082130432/
C                         /ZAAAA/ +  312
      DATA GEOMTB(  1643) /-1431699144/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1644) / -859045877/
C                         / Z02000400/
      DATA GEOMTB(  1645) /   33555456/
C                         /ZAAAA/ +  140
      DATA GEOMTB(  1646) /-1431699316/
C                         / Z02000200/
      DATA GEOMTB(  1647) /   33554944/
C                         /ZAAAA/ +  184
      DATA GEOMTB(  1648) /-1431699272/
C                         / Z02000100/
      DATA GEOMTB(  1649) /   33554688/
C                         /ZAAAA/ +  324
      DATA GEOMTB(  1650) /-1431699132/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1651) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1652) / 1082130432/
C                         /ZAAAA/ +  152
      DATA GEOMTB(  1653) /-1431699304/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1654) / -859045688/
C                         / Z02000200/
      DATA GEOMTB(  1655) /   33554944/
C                         /ZAAAA/ +  172
      DATA GEOMTB(  1656) /-1431699284/
C                         / Z02000100/
      DATA GEOMTB(  1657) /   33554688/
C                         /ZAAAA/ +  340
      DATA GEOMTB(  1658) /-1431699116/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1659) / -859045874/
C                         / Z40800000/
      DATA GEOMTB(  1660) / 1082130432/
C                         /ZAAAA/ +  336
      DATA GEOMTB(  1661) /-1431699120/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1662) / -859045874/
C                         / Z40800000/
      DATA GEOMTB(  1663) / 1082130432/
C                         /ZAAAA/ +  336
      DATA GEOMTB(  1664) /-1431699120/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1665) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1666) / 1082130432/
C                         /ZAAAA/ +  208
      DATA GEOMTB(  1667) /-1431699248/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1668) / -859045688/
C                         / Z02000100/
      DATA GEOMTB(  1669) /   33554688/
C                         /ZAAAA/ +  220
      DATA GEOMTB(  1670) /-1431699236/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1671) / -859045876/
C                         / Z40801000/
      DATA GEOMTB(  1672) / 1082134528/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1673) / -859045876/
C                         / Z08400000/
      DATA GEOMTB(  1674) /  138412032/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1675) / -859045876/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1676) / -859045876/
C                         / Z40800000/
      DATA GEOMTB(  1677) / 1082130432/
C                         /ZAAAA/ +  252
      DATA GEOMTB(  1678) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1679) / -859045688/
C                         / Z04100000/
      DATA GEOMTB(  1680) /   68157440/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1681) / -859045875/
C                         / Z04000200/
      DATA GEOMTB(  1682) /   67109376/
C                         /ZAAAA/ +  272
      DATA GEOMTB(  1683) /-1431699184/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1684) / -859045875/
C                         / Z40800000/
      DATA GEOMTB(  1685) / 1082130432/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1686) /-1431699104/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1687) / -859045875/
C                         / Z40800000/
      DATA GEOMTB(  1688) / 1082130432/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1689) /-1431699104/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1690) / -859045688/
C                         / Z02000800/
      DATA GEOMTB(  1691) /   33556480/
C                         / Z40800000/
      DATA GEOMTB(  1692) / 1082130432/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1693) / -859045877/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1694) / -859045688/
C                         / Z04000801/
      DATA GEOMTB(  1695) /   67110913/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1696) / -859045874/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  1697) / -859045878/
C                         / Z40801000/
      DATA GEOMTB(  1698) / 1082134528/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1699) / -859045874/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1700) / -859045688/
C                         / Z02000100/
      DATA GEOMTB(  1701) /   33554688/
C                         / Z40801000/
      DATA GEOMTB(  1702) / 1082134528/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1703) / -859045874/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1704) / -859045874/
C                         / Z04100000/
      DATA GEOMTB(  1705) /   68157440/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1706) / -859045875/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1707) / -859045875/
C                         /Z9999/ + 6828
      DATA GEOMTB(  1708) /-1718019412/
C                         / Z10000080/
      DATA GEOMTB(  1709) /  268435584/
C                         /ZAAAA/ +   24
      DATA GEOMTB(  1710) /-1431699432/
C                         / Z10000100/
      DATA GEOMTB(  1711) /  268435712/
C                         /ZAAAA/ +  432
      DATA GEOMTB(  1712) /-1431699024/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1713) / -859045688/
C                         / Z04000010/
      DATA GEOMTB(  1714) /   67108880/
C                         /ZAAAA/ +   92
      DATA GEOMTB(  1715) /-1431699364/
C                         / Z04000600/
      DATA GEOMTB(  1716) /   67110400/
C                         /ZAAAA/ +  188
      DATA GEOMTB(  1717) /-1431699268/
C                         / Z04100000/
      DATA GEOMTB(  1718) /   68157440/
C                         /ZAAAA/ +  208
      DATA GEOMTB(  1719) /-1431699248/
C                         / Z10000400/
      DATA GEOMTB(  1720) /  268436480/
C                         /ZAAAA/ +  280
      DATA GEOMTB(  1721) /-1431699176/
C                         / Z04001020/
      DATA GEOMTB(  1722) /   67112992/
C                         /ZAAAA/ +  312
      DATA GEOMTB(  1723) /-1431699144/
C                         / Z20000800/
      DATA GEOMTB(  1724) /  536872960/
C                         /ZAAAA/ +  324
      DATA GEOMTB(  1725) /-1431699132/
C                         / Z10000020/
      DATA GEOMTB(  1726) /  268435488/
C                         /ZAAAA/ +  572
      DATA GEOMTB(  1727) /-1431698884/
C                         / Z02000800/
      DATA GEOMTB(  1728) /   33556480/
C                         /ZAAAA/ +  584
      DATA GEOMTB(  1729) /-1431698872/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1730) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1731) / 1082130432/
C                         /ZAAAA/ +  112
      DATA GEOMTB(  1732) /-1431699344/
C                         / Z04000002/
      DATA GEOMTB(  1733) /   67108866/
C                         /ZAAAA/ +  144
      DATA GEOMTB(  1734) /-1431699312/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1735) / -859045688/
C                         / Z04000200/
      DATA GEOMTB(  1736) /   67109376/
C                         /ZAAAA/ +  124
      DATA GEOMTB(  1737) /-1431699332/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1738) / -859045882/
C                         / Z40800000/
      DATA GEOMTB(  1739) / 1082130432/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  1740) / -859045883/
C                         / Z04000002/
      DATA GEOMTB(  1741) /   67108866/
C                         /ZAAAA/ +  596
      DATA GEOMTB(  1742) /-1431698860/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1743) / -859045882/
C                         / Z08C00000/
      DATA GEOMTB(  1744) /  146800640/
C                         /ZAAAA/ +  156
      DATA GEOMTB(  1745) /-1431699300/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1746) / -859045688/
C                         / Z04000200/
      DATA GEOMTB(  1747) /   67109376/
C                         /ZAAAA/ +  168
      DATA GEOMTB(  1748) /-1431699288/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1749) / -859045881/
C                         / Z40800000/
      DATA GEOMTB(  1750) / 1082130432/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1751) / -859045884/
C                         / Z04000002/
      DATA GEOMTB(  1752) /   67108866/
C                         /ZAAAA/ +  608
      DATA GEOMTB(  1753) /-1431698848/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1754) / -859045881/
C                         / Z40800000/
      DATA GEOMTB(  1755) / 1082130432/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1756) / -859045882/
C                         / Z04000002/
      DATA GEOMTB(  1757) /   67108866/
C                         /ZAAAA/ +  620
      DATA GEOMTB(  1758) /-1431698836/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1759) / -859045688/
C                         / Z10000400/
      DATA GEOMTB(  1760) /  268436480/
C                         /ZAAAA/ +  236
      DATA GEOMTB(  1761) /-1431699220/
C                         / Z04001020/
      DATA GEOMTB(  1762) /   67112992/
C                         /ZAAAA/ +  268
      DATA GEOMTB(  1763) /-1431699188/
C                         / Z10000020/
      DATA GEOMTB(  1764) /  268435488/
C                         /ZAAAA/ +  632
      DATA GEOMTB(  1765) /-1431698824/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1766) / -859045874/
C                         / Z04001020/
      DATA GEOMTB(  1767) /   67112992/
C                         /ZAAAA/ +  256
      DATA GEOMTB(  1768) /-1431699200/
C                         / Z10000020/
      DATA GEOMTB(  1769) /  268435488/
C                         /ZAAAA/ +  644
      DATA GEOMTB(  1770) /-1431698812/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1771) / -859045877/
C                         / Z40800000/
      DATA GEOMTB(  1772) / 1082130432/
C                         /ZAAAA/ +  656
      DATA GEOMTB(  1773) /-1431698800/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1774) / -859045877/
C                         / Z40800000/
      DATA GEOMTB(  1775) / 1082130432/
C                         /ZAAAA/ +  672
      DATA GEOMTB(  1776) /-1431698784/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1777) / -859045874/
C                         / Z04001020/
      DATA GEOMTB(  1778) /   67112992/
C                         /ZAAAA/ +  300
      DATA GEOMTB(  1779) /-1431699156/
C                         / Z10000020/
      DATA GEOMTB(  1780) /  268435488/
C                         /ZAAAA/ +  632
      DATA GEOMTB(  1781) /-1431698824/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1782) / -859045874/
C                         / Z40800000/
      DATA GEOMTB(  1783) / 1082130432/
C                         /ZAAAA/ +  672
      DATA GEOMTB(  1784) /-1431698784/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1785) / -859045874/
C                         / Z40800000/
      DATA GEOMTB(  1786) / 1082130432/
C                         /ZAAAA/ +  688
      DATA GEOMTB(  1787) /-1431698768/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1788) / -859045688/
C                         / Z02000800/
      DATA GEOMTB(  1789) /   33556480/
C                         /ZAAAA/ +  344
      DATA GEOMTB(  1790) /-1431699112/
C                         / Z04001020/
      DATA GEOMTB(  1791) /   67112992/
C                         /ZAAAA/ +  704
      DATA GEOMTB(  1792) /-1431698752/
C                         /ZCCCC/ +   42
      DATA GEOMTB(  1793) / -859045846/
C                         / Z02000800/
      DATA GEOMTB(  1794) /   33556480/
C                         /ZAAAA/ +  372
      DATA GEOMTB(  1795) /-1431699084/
C                         / Z40800000/
      DATA GEOMTB(  1796) / 1082130432/
C                         /ZAAAA/ +  392
      DATA GEOMTB(  1797) /-1431699064/
C                         / Z04001020/
      DATA GEOMTB(  1798) /   67112992/
C                         /ZAAAA/ +  716
      DATA GEOMTB(  1799) /-1431698740/
C                         /ZCCCC/ +   41
      DATA GEOMTB(  1800) / -859045847/
C                         / Z04001020/
      DATA GEOMTB(  1801) /   67112992/
C                         /ZAAAA/ +  728
      DATA GEOMTB(  1802) /-1431698728/
C                         / Z40800000/
      DATA GEOMTB(  1803) / 1082130432/
C                         /ZAAAA/ +  740
      DATA GEOMTB(  1804) /-1431698716/
C                         /ZCCCC/ +   37
      DATA GEOMTB(  1805) / -859045851/
C                         / Z02000800/
      DATA GEOMTB(  1806) /   33556480/
C                         /ZAAAA/ +  412
      DATA GEOMTB(  1807) /-1431699044/
C                         / Z04001020/
      DATA GEOMTB(  1808) /   67112992/
C                         /ZAAAA/ +  756
      DATA GEOMTB(  1809) /-1431698700/
C                         /ZCCCC/ +   39
      DATA GEOMTB(  1810) / -859045849/
C                         / Z04001020/
      DATA GEOMTB(  1811) /   67112992/
C                         /ZAAAA/ +  768
      DATA GEOMTB(  1812) /-1431698688/
C                         / Z40800000/
      DATA GEOMTB(  1813) / 1082130432/
C                         /ZAAAA/ +  780
      DATA GEOMTB(  1814) /-1431698676/
C                         /ZCCCC/ +   35
      DATA GEOMTB(  1815) / -859045853/
C                         / Z04000010/
      DATA GEOMTB(  1816) /   67108880/
C                         /ZAAAA/ +  468
      DATA GEOMTB(  1817) /-1431698988/
C                         / Z04000200/
      DATA GEOMTB(  1818) /   67109376/
C                         /ZAAAA/ +  540
      DATA GEOMTB(  1819) /-1431698916/
C                         / Z04001020/
      DATA GEOMTB(  1820) /   67112992/
C                         /ZAAAA/ +  796
      DATA GEOMTB(  1821) /-1431698660/
C                         / Z2000C000/
      DATA GEOMTB(  1822) /  536920064/
C                         /ZAAAA/ +  808
      DATA GEOMTB(  1823) /-1431698648/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1824) / -859045864/
C                         / Z40800000/
      DATA GEOMTB(  1825) / 1082130432/
C                         /ZAAAA/ +  480
      DATA GEOMTB(  1826) /-1431698976/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1827) / -859045864/
C                         / Z04000200/
      DATA GEOMTB(  1828) /   67109376/
C                         /ZAAAA/ +  508
      DATA GEOMTB(  1829) /-1431698948/
C                         / Z04001020/
      DATA GEOMTB(  1830) /   67112992/
C                         /ZAAAA/ +  824
      DATA GEOMTB(  1831) /-1431698632/
C                         / Z2000C000/
      DATA GEOMTB(  1832) /  536920064/
C                         /ZAAAA/ +  836
      DATA GEOMTB(  1833) /-1431698620/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1834) / -859045859/
C                         / Z40800000/
      DATA GEOMTB(  1835) / 1082130432/
C                         /ZAAAA/ +  520
      DATA GEOMTB(  1836) /-1431698936/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1837) / -859045859/
C                         / Z04001020/
      DATA GEOMTB(  1838) /   67112992/
C                         /ZAAAA/ +  852
      DATA GEOMTB(  1839) /-1431698604/
C                         / Z2000C000/
      DATA GEOMTB(  1840) /  536920064/
C                         /ZAAAA/ +  864
      DATA GEOMTB(  1841) /-1431698592/
C                         /ZCCCC/ +   26
      DATA GEOMTB(  1842) / -859045862/
C                         / Z40800000/
      DATA GEOMTB(  1843) / 1082130432/
C                         /ZAAAA/ +  552
      DATA GEOMTB(  1844) /-1431698904/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1845) / -859045864/
C                         / Z04001020/
      DATA GEOMTB(  1846) /   67112992/
C                         /ZAAAA/ +  880
      DATA GEOMTB(  1847) /-1431698576/
C                         / Z2000C000/
      DATA GEOMTB(  1848) /  536920064/
C                         /ZAAAA/ +  892
      DATA GEOMTB(  1849) /-1431698564/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1850) / -859045859/
C                         / Z40800000/
      DATA GEOMTB(  1851) / 1082130432/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1852) / -859045873/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1853) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1854) / 1082130432/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  1855) / -859045887/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1856) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(  1857) /  146800640/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  1858) / -859045885/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1859) / -859045882/
C                         / Z08C00000/
      DATA GEOMTB(  1860) /  146800640/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  1861) / -859045886/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1862) / -859045881/
C                         / Z08C00000/
      DATA GEOMTB(  1863) /  146800640/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1864) / -859045881/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1865) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1866) / 1082130432/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1867) / -859045875/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  1868) / -859045874/
C                         / Z40800000/
      DATA GEOMTB(  1869) / 1082130432/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  1870) / -859045879/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  1871) / -859045877/
C                         / Z10000020/
      DATA GEOMTB(  1872) /  268435488/
C                         / Z40800000/
      DATA GEOMTB(  1873) / 1082130432/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1874) / -859045880/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  1875) / -859045879/
C                         / Z10000020/
      DATA GEOMTB(  1876) /  268435488/
C                         / Z40800000/
      DATA GEOMTB(  1877) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  1878) / -859045878/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  1879) / -859045875/
C                         / Z10000020/
      DATA GEOMTB(  1880) /  268435488/
C                         / Z40800000/
      DATA GEOMTB(  1881) / 1082130432/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  1882) / -859045876/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1883) / -859045873/
C                         / Z40800000/
      DATA GEOMTB(  1884) / 1082130432/
C                         /ZCCCC/ +   39
      DATA GEOMTB(  1885) / -859045849/
C                         /ZCCCC/ +   41
      DATA GEOMTB(  1886) / -859045847/
C                         / Z40800000/
      DATA GEOMTB(  1887) / 1082130432/
C                         /ZCCCC/ +   40
      DATA GEOMTB(  1888) / -859045848/
C                         /ZCCCC/ +   41
      DATA GEOMTB(  1889) / -859045847/
C                         / Z40800000/
      DATA GEOMTB(  1890) / 1082130432/
C                         /ZCCCC/ +   36
      DATA GEOMTB(  1891) / -859045852/
C                         /ZCCCC/ +   37
      DATA GEOMTB(  1892) / -859045851/
C                         / Z04001020/
      DATA GEOMTB(  1893) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1894) / 1082130432/
C                         /ZCCCC/ +   32
      DATA GEOMTB(  1895) / -859045856/
C                         /ZCCCC/ +   33
      DATA GEOMTB(  1896) / -859045855/
C                         / Z40800000/
      DATA GEOMTB(  1897) / 1082130432/
C                         /ZCCCC/ +   38
      DATA GEOMTB(  1898) / -859045850/
C                         /ZCCCC/ +   39
      DATA GEOMTB(  1899) / -859045849/
C                         / Z40800000/
      DATA GEOMTB(  1900) / 1082130432/
C                         /ZCCCC/ +   34
      DATA GEOMTB(  1901) / -859045854/
C                         /ZCCCC/ +   35
      DATA GEOMTB(  1902) / -859045853/
C                         / Z04001020/
      DATA GEOMTB(  1903) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1904) / 1082130432/
C                         /ZCCCC/ +   30
      DATA GEOMTB(  1905) / -859045858/
C                         /ZCCCC/ +   31
      DATA GEOMTB(  1906) / -859045857/
C                         / Z40800000/
      DATA GEOMTB(  1907) / 1082130432/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1908) / -859045859/
C                         /ZCCCC/ +   24
      DATA GEOMTB(  1909) / -859045864/
C                         / Z04001020/
      DATA GEOMTB(  1910) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1911) / 1082130432/
C                         /ZCCCC/ +   23
      DATA GEOMTB(  1912) / -859045865/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1913) / -859045872/
C                         / Z40800000/
      DATA GEOMTB(  1914) / 1082130432/
C                         /ZCCCC/ +   27
      DATA GEOMTB(  1915) / -859045861/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1916) / -859045859/
C                         / Z04001020/
      DATA GEOMTB(  1917) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1918) / 1082130432/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1919) / -859045869/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1920) / -859045867/
C                         / Z40800000/
      DATA GEOMTB(  1921) / 1082130432/
C                         /ZCCCC/ +   25
      DATA GEOMTB(  1922) / -859045863/
C                         /ZCCCC/ +   26
      DATA GEOMTB(  1923) / -859045862/
C                         / Z04001020/
      DATA GEOMTB(  1924) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1925) / 1082130432/
C                         /ZCCCC/ +   17
      DATA GEOMTB(  1926) / -859045871/
C                         /ZCCCC/ +   18
      DATA GEOMTB(  1927) / -859045870/
C                         / Z40800000/
      DATA GEOMTB(  1928) / 1082130432/
C                         /ZCCCC/ +   28
      DATA GEOMTB(  1929) / -859045860/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  1930) / -859045859/
C                         / Z04001020/
      DATA GEOMTB(  1931) /   67112992/
C                         / Z40800000/
      DATA GEOMTB(  1932) / 1082130432/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  1933) / -859045868/
C                         /ZCCCC/ +   22
      DATA GEOMTB(  1934) / -859045866/
C                         /Z9999/ + 7736
      DATA GEOMTB(  1935) /-1718018504/
C                         / Z40200000/
      DATA GEOMTB(  1936) / 1075838976/
C                         /ZAAAA/ +   56
      DATA GEOMTB(  1937) /-1431699400/
C                         / Z40800000/
      DATA GEOMTB(  1938) / 1082130432/
C                         /ZAAAA/ +  260
      DATA GEOMTB(  1939) /-1431699196/
C                         / Z02000080/
      DATA GEOMTB(  1940) /   33554560/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  1941) / -859045882/
C                         / Z40001000/
      DATA GEOMTB(  1942) / 1073745920/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  1943) / -859045881/
C                         / Z40000006/
      DATA GEOMTB(  1944) / 1073741830/
C                         /ZCCCC/ +    8
      DATA GEOMTB(  1945) / -859045880/
C                         / Z20080000/
      DATA GEOMTB(  1946) /  537395200/
C                         /ZAAAA/ +  208
      DATA GEOMTB(  1947) /-1431699248/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1948) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  1949) / 1073741825/
C                         /ZAAAA/ +  116
      DATA GEOMTB(  1950) /-1431699340/
C                         / Z40001000/
      DATA GEOMTB(  1951) / 1073745920/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1952) / -859045867/
C                         / Z02000040/
      DATA GEOMTB(  1953) /   33554496/
C                         /ZAAAA/ +  160
      DATA GEOMTB(  1954) /-1431699296/
C                         / Z08C00000/
      DATA GEOMTB(  1955) /  146800640/
C                         /ZCCCC/ +   21
      DATA GEOMTB(  1956) / -859045867/
C                         / Z02002000/
      DATA GEOMTB(  1957) /   33562624/
C                         /ZCCCC/ +   22
      DATA GEOMTB(  1958) / -859045866/
C                         / Z40080000/
      DATA GEOMTB(  1959) / 1074266112/
C                         /ZAAAA/ +  272
      DATA GEOMTB(  1960) /-1431699184/
C                         / Z20080000/
      DATA GEOMTB(  1961) /  537395200/
C                         /ZAAAA/ +  284
      DATA GEOMTB(  1962) /-1431699172/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1963) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1964) / 1082130432/
C                         /ZAAAA/ +  128
      DATA GEOMTB(  1965) /-1431699328/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1966) / -859045688/
C                         / Z10080000/
      DATA GEOMTB(  1967) /  268959744/
C                         /ZAAAA/ +  148
      DATA GEOMTB(  1968) /-1431699308/
C                         / Z02000020/
      DATA GEOMTB(  1969) /   33554464/
C                         /ZAAAA/ +  296
      DATA GEOMTB(  1970) /-1431699160/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1971) / -859045884/
C                         / Z40800000/
      DATA GEOMTB(  1972) / 1082130432/
C                         /ZAAAA/ +  308
      DATA GEOMTB(  1973) /-1431699148/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  1974) / -859045884/
C                         / Z40800000/
      DATA GEOMTB(  1975) / 1082130432/
C                         /ZCCCC/ +   17
      DATA GEOMTB(  1976) / -859045871/
C                         / Z10000003/
      DATA GEOMTB(  1977) /  268435459/
C                         /ZAAAA/ +  188
      DATA GEOMTB(  1978) /-1431699268/
C                         / Z02000010/
      DATA GEOMTB(  1979) /   33554448/
C                         /ZCCCC/ +   19
      DATA GEOMTB(  1980) / -859045869/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1981) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  1982) / 1082130432/
C                         /ZCCCC/ +   16
      DATA GEOMTB(  1983) / -859045872/
C                         / Z02000010/
      DATA GEOMTB(  1984) /   33554448/
C                         /ZCCCC/ +   18
      DATA GEOMTB(  1985) / -859045870/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1986) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  1987) / 1073741825/
C                         /ZAAAA/ +  228
      DATA GEOMTB(  1988) /-1431699228/
C                         / Z40800000/
      DATA GEOMTB(  1989) / 1082130432/
C                         /ZAAAA/ +  324
      DATA GEOMTB(  1990) /-1431699132/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  1991) / -859045688/
C                         / Z10080000/
      DATA GEOMTB(  1992) /  268959744/
C                         /ZAAAA/ +  248
      DATA GEOMTB(  1993) /-1431699208/
C                         / Z02000020/
      DATA GEOMTB(  1994) /   33554464/
C                         /ZAAAA/ +  340
      DATA GEOMTB(  1995) /-1431699116/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1996) / -859045873/
C                         / Z40800000/
      DATA GEOMTB(  1997) / 1082130432/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  1998) /-1431699104/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  1999) / -859045873/
C                         / Z40800000/
      DATA GEOMTB(  2000) / 1082130432/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  2001) / -859045883/
C                         /ZCCCC/ +    9
      DATA GEOMTB(  2002) / -859045879/
C                         / Z40001000/
      DATA GEOMTB(  2003) / 1073745920/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  2004) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2005) / -859045688/
C                         / Z08C00000/
      DATA GEOMTB(  2006) /  146800640/
C                         /ZCCCC/ +   20
      DATA GEOMTB(  2007) / -859045868/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2008) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2009) / 1082130432/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  2010) / -859045885/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2011) / -859045884/
C                         / Z02000020/
      DATA GEOMTB(  2012) /   33554464/
C                         / Z40800000/
      DATA GEOMTB(  2013) / 1082130432/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  2014) / -859045887/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  2015) / -859045886/
C                         / Z40800000/
      DATA GEOMTB(  2016) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2017) / 1082130432/
C                         /ZCCCC/ +   10
      DATA GEOMTB(  2018) / -859045878/
C                         /ZCCCC/ +   11
      DATA GEOMTB(  2019) / -859045877/
C                         / Z40800000/
      DATA GEOMTB(  2020) / 1082130432/
C                         /ZCCCC/ +   14
      DATA GEOMTB(  2021) / -859045874/
C                         /ZCCCC/ +   15
      DATA GEOMTB(  2022) / -859045873/
C                         / Z02000020/
      DATA GEOMTB(  2023) /   33554464/
C                         / Z40800000/
      DATA GEOMTB(  2024) / 1082130432/
C                         /ZCCCC/ +   12
      DATA GEOMTB(  2025) / -859045876/
C                         /ZCCCC/ +   13
      DATA GEOMTB(  2026) / -859045875/
C                         /Z9999/ + 8104
      DATA GEOMTB(  2027) /-1718018136/
C                         / Z02000008/
      DATA GEOMTB(  2028) /   33554440/
C                         /ZAAAA/ +   72
      DATA GEOMTB(  2029) /-1431699384/
C                         / Z40000001/
      DATA GEOMTB(  2030) / 1073741825/
C                         /ZAAAA/ +   92
      DATA GEOMTB(  2031) /-1431699364/
C                         / Z40000020/
      DATA GEOMTB(  2032) / 1073741856/
C                         /ZAAAA/ +  120
      DATA GEOMTB(  2033) /-1431699336/
C                         / Z40000010/
      DATA GEOMTB(  2034) / 1073741840/
C                         /ZAAAA/ +  196
      DATA GEOMTB(  2035) /-1431699260/
C                         / Z40000008/
      DATA GEOMTB(  2036) / 1073741832/
C                         /ZAAAA/ +  296
      DATA GEOMTB(  2037) /-1431699160/
C                         / Z02000004/
      DATA GEOMTB(  2038) /   33554436/
C                         /ZAAAA/ +  216
      DATA GEOMTB(  2039) /-1431699240/
C                         / Z02000002/
      DATA GEOMTB(  2040) /   33554434/
C                         /ZAAAA/ +  320
      DATA GEOMTB(  2041) /-1431699136/
C                         / Z04000801/
      DATA GEOMTB(  2042) /   67110913/
C                         /ZAAAA/ +  352
      DATA GEOMTB(  2043) /-1431699104/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2044) / -859045688/
C                         / Z04000100/
      DATA GEOMTB(  2045) /   67109120/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2046) / -859045884/
C                         / Z40000039/
      DATA GEOMTB(  2047) / 1073741881/
C                         /ZCCCC/ +    1
      DATA GEOMTB(  2048) / -859045887/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2049) / -859045688/
C                         / Z04000002/
      DATA GEOMTB(  2050) /   67108866/
C                         /ZAAAA/ +  392
      DATA GEOMTB(  2051) /-1431699064/
C                         / Z10000080/
      DATA GEOMTB(  2052) /  268435584/
C                         /ZAAAA/ +  408
      DATA GEOMTB(  2053) /-1431699048/
C                         / Z10000100/
      DATA GEOMTB(  2054) /  268435712/
C                         /ZAAAA/ +  444
      DATA GEOMTB(  2055) /-1431699012/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2056) / -859045688/
C                         / Z40200000/
      DATA GEOMTB(  2057) / 1075838976/
C                         /ZAAAA/ +  140
      DATA GEOMTB(  2058) /-1431699316/
C                         / Z40001004/
      DATA GEOMTB(  2059) / 1073745924/
C                         /ZAAAA/ +  472
      DATA GEOMTB(  2060) /-1431698984/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2061) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  2062) / 1073741825/
C                         /ZAAAA/ +  152
      DATA GEOMTB(  2063) /-1431699304/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2064) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2065) / 1082130432/
C                         /ZAAAA/ +  164
      DATA GEOMTB(  2066) /-1431699292/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2067) / -859045688/
C                         / Z02000040/
      DATA GEOMTB(  2068) /   33554496/
C                         /ZAAAA/ +  176
      DATA GEOMTB(  2069) /-1431699280/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2070) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2071) / 1082130432/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2072) / -859045884/
C                         / Z10000003/
      DATA GEOMTB(  2073) /  268435459/
C                         /ZAAAA/ +  308
      DATA GEOMTB(  2074) /-1431699148/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2075) / -859045688/
C                         / Z08400000/
      DATA GEOMTB(  2076) /  138412032/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2077) / -859045884/
C                         / Z40800000/
      DATA GEOMTB(  2078) / 1082130432/
C                         /ZAAAA/ +  300
      DATA GEOMTB(  2079) /-1431699156/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2080) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  2081) / 1073741825/
C                         /ZAAAA/ +  228
      DATA GEOMTB(  2082) /-1431699228/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2083) / -859045688/
C                         / Z20008000/
      DATA GEOMTB(  2084) /  536903680/
C                         /ZAAAA/ +  240
      DATA GEOMTB(  2085) /-1431699216/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2086) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2087) / 1082130432/
C                         /ZAAAA/ +  252
      DATA GEOMTB(  2088) /-1431699204/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2089) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2090) / 1082130432/
C                         /ZAAAA/ +  264
      DATA GEOMTB(  2091) /-1431699192/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2092) / -859045688/
C                         / Z04001000/
      DATA GEOMTB(  2093) /   67112960/
C                         /ZAAAA/ +  276
      DATA GEOMTB(  2094) /-1431699180/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2095) / -859045688/
C                         / Z40801000/
      DATA GEOMTB(  2096) / 1082134528/
C                         /ZCCCC/ +    6
      DATA GEOMTB(  2097) / -859045882/
C                         / Z08400000/
      DATA GEOMTB(  2098) /  138412032/
C                         /ZCCCC/ +    7
      DATA GEOMTB(  2099) / -859045881/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2100) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2101) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2102) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2103) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2104) / 1082130432/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2105) / -859045884/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2106) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  2107) / 1073741825/
C                         / Z20008000/
      DATA GEOMTB(  2108) /  536903680/
C                         / Z40800000/
      DATA GEOMTB(  2109) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2110) / 1082130432/
C                         / Z40000180/
      DATA GEOMTB(  2111) / 1073742208/
C                         / Z20003000/
      DATA GEOMTB(  2112) /  536883200/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  2113) / -859045883/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2114) / -859045688/
C                         / Z40000001/
      DATA GEOMTB(  2115) / 1073741825/
C                         / Z20008000/
      DATA GEOMTB(  2116) /  536903680/
C                         / Z40800000/
      DATA GEOMTB(  2117) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2118) / 1082130432/
C                         / Z40000180/
      DATA GEOMTB(  2119) / 1073742208/
C                         / Z20003000/
      DATA GEOMTB(  2120) /  536883200/
C                         / Z40000008/
      DATA GEOMTB(  2121) / 1073741832/
C                         / Z20003000/
      DATA GEOMTB(  2122) /  536883200/
C                         /ZCCCC/ +    5
      DATA GEOMTB(  2123) / -859045883/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2124) / -859045688/
C                         / Z10000080/
      DATA GEOMTB(  2125) /  268435584/
C                         / Z20003000/
      DATA GEOMTB(  2126) /  536883200/
C                         /ZCCCC/ +    3
      DATA GEOMTB(  2127) / -859045885/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2128) / -859045688/
C                         / Z20008000/
      DATA GEOMTB(  2129) /  536903680/
C                         / Z40800000/
      DATA GEOMTB(  2130) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2131) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2132) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2133) / 1082130432/
C                         / Z04000402/
      DATA GEOMTB(  2134) /   67109890/
C                         / Z40081000/
      DATA GEOMTB(  2135) / 1074270208/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  2136) / -859045886/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2137) / -859045688/
C                         / Z20008000/
      DATA GEOMTB(  2138) /  536903680/
C                         / Z40800000/
      DATA GEOMTB(  2139) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2140) / 1082130432/
C                         / Z04000402/
      DATA GEOMTB(  2141) /   67109890/
C                         / Z40001080/
      DATA GEOMTB(  2142) / 1073746048/
C                         /ZCCCC/ +    2
      DATA GEOMTB(  2143) / -859045886/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2144) / -859045688/
C                         / Z20003000/
      DATA GEOMTB(  2145) /  536883200/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2146) / -859045884/
C                         /ZCCCC/ +    4
      DATA GEOMTB(  2147) / -859045884/
C                         /Z9999/ + 8588
      DATA GEOMTB(  2148) /-1718017652/
C                         / Z04000102/
      DATA GEOMTB(  2149) /   67109122/
C                         /ZCCCC/ +   27
      DATA GEOMTB(  2150) / -859045861/
C                         / Z02000040/
      DATA GEOMTB(  2151) /   33554496/
C                         /ZAAAA/ +   40
      DATA GEOMTB(  2152) /-1431699416/
C                         / Z40000022/
      DATA GEOMTB(  2153) / 1073741858/
C                         /ZCCCC/ +   29
      DATA GEOMTB(  2154) / -859045859/
C                         / Z20000020/
      DATA GEOMTB(  2155) /  536870944/
C                         /ZAAAA/ +   68
      DATA GEOMTB(  2156) /-1431699388/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2157) / -859045688/
C                         / Z02000001/
      DATA GEOMTB(  2158) /   33554433/
C                         / Z40800000/
      DATA GEOMTB(  2159) / 1082130432/
C                         / Z01800000/
      DATA GEOMTB(  2160) /   25165824/
C                         / Z40800000/
      DATA GEOMTB(  2161) / 1082130432/
C                         / Z40800000/
      DATA GEOMTB(  2162) / 1082130432/
C                         /ZCCCC/ +   28
      DATA GEOMTB(  2163) / -859045860/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2164) / -859045688/
C                         / Z40800000/
      DATA GEOMTB(  2165) / 1082130432/
C                         /ZCCCC/ +   30
      DATA GEOMTB(  2166) / -859045858/
C                         /ZCCCC/ +  200
      DATA GEOMTB(  2167) / -859045688/
       END
