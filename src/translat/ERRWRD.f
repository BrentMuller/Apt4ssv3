**** SOURCE FILE : M0004613.W03   ***
*
C
C     FORTRAN SUBROUTINE ERRWRD
C
      BLOCK DATA TRERRW
C
      INCLUDE 'ERRTXT.INC'
C
      INTEGER A,B
      CHARACTER*4 E
      DIMENSION A(ERND),B(ERND),E(ERRDM)
      EQUIVALENCE (A(1),ERRAD1(1))
      EQUIVALENCE (B(1),ERRAD2(1))
      EQUIVALENCE (E(1),ERRTXT(1))
                                  
C
C
      DATA A(  1),A(  2),A(  3),A(  4)/      1,      2,      3,      4/
      DATA A(  5),A(  6),A(  7),A(  8)/      7,      9,     10,     12/
      DATA A(  9),A( 10),A( 11),A( 12)/     13,     14,     15,     16/
      DATA A( 13),A( 14),A( 15),A( 16)/     17,     18,     19,     20/
      DATA A( 17),A( 18),A( 19),A( 20)/     21,     22,     24,     26/
      DATA A( 21),A( 22),A( 23),A( 24)/     27,     28,     29,     31/
      DATA A( 25),A( 26),A( 27),A( 28)/     32,     34,     35,     36/
      DATA A( 29),A( 30),A( 31),A( 32)/     37,     38,     40,     50/
      DATA A( 33),A( 34),A( 35),A( 36)/     52,     53,     55,     56/
      DATA A( 37),A( 38),A( 39),A( 40)/     71,     72,     73,     74/
      DATA A( 41),A( 42),A( 43),A( 44)/   1001,   1002,   1003,   1004/
      DATA A( 45),A( 46),A( 47),A( 48)/   1005,   1007,   1008,   1009/
      DATA A( 49),A( 50),A( 51),A( 52)/   1010,   1011,   1012,   1013/
      DATA A( 53),A( 54),A( 55),A( 56)/   1014,   1015,   1016,   1017/
      DATA A( 57),A( 58),A( 59),A( 60)/   1018,   1019,   1020,   1021/
      DATA A( 61),A( 62),A( 63),A( 64)/   1022,   1023,   1024,   1025/
      DATA A( 65),A( 66),A( 67),A( 68)/   1026,   1028,   1029,   1032/
      DATA A( 69),A( 70),A( 71),A( 72)/   1035,   1036,   1037,   1038/
      DATA A( 73),A( 74),A( 75),A( 76)/   1039,   1040,   1041,   1050/
      DATA A( 77),A( 78),A( 79),A( 80)/   1111,   1201,   1203,   1204/
      DATA A( 81),A( 82),A( 83),A( 84)/   1205,   1206,   1207,   1208/
      DATA A( 85),A( 86),A( 87),A( 88)/   1209,   1210,   1211,   1212/
      DATA A( 89),A( 90),A( 91),A( 92)/   1213,   1215,   1216,   1217/
      DATA A( 93),A( 94),A( 95),A( 96)/   1218,   1219,   1220,   1221/
      DATA A( 97),A( 98),A( 99),A(100)/   1222,   1223,   1224,   1225/
      DATA A(101),A(102),A(103),A(104)/   1227,   1228,   1229,   1230/
      DATA A(105),A(106),A(107),A(108)/   1232,   1233,   1235,   2001/
      DATA A(109),A(110),A(111),A(112)/   2002,   2003,   2004,   2005/
      DATA A(113),A(114),A(115),A(116)/   2006,   2007,   2008,   2009/
      DATA A(117),A(118),A(119),A(120)/   2010,   2011,   2012,   2013/
      DATA A(121),A(122),A(123),A(124)/   2015,   2017,   2018,   2019/
      DATA A(125),A(126),A(127),A(128)/   2020,   2021,   2022,   2023/
      DATA A(129),A(130),A(131),A(132)/   2024,   2025,   2026,   2027/
      DATA A(133),A(134),A(135),A(136)/   2028,   2029,   2030,   2031/
      DATA A(137),A(138),A(139),A(140)/   2032,   2033,   2034,   2035/
      DATA A(141),A(142),A(143),A(144)/   2036,   2037,   2038,   2039/
      DATA A(145),A(146),A(147),A(148)/   2041,   2042,   2044,   2045/
      DATA A(149),A(150),A(151),A(152)/   2046,   2051,   2052,   2053/
      DATA A(153),A(154),A(155),A(156)/   2054,   2055,   2056,   2057/
      DATA A(157),A(158),A(159)       /   2058,   3001,   3002 /
      DATA B(  1),B(  2),B(  3),B(  4)/     11,     25,     37,     50/
      DATA B(  5),B(  6),B(  7),B(  8)/     64,     80,     98,    106/
      DATA B(  9),B( 10),B( 11),B( 12)/    119,    131,    145,    158/
      DATA B( 13),B( 14),B( 15),B( 16)/    178,    188,    206,    225/
      DATA B( 17),B( 18),B( 19),B( 20)/    244,    266,    284,    302/
      DATA B( 21),B( 22),B( 23),B( 24)/    317,    340,    361,    380/
      DATA B( 25),B( 26),B( 27),B( 28)/    401,    416,    421,    428/
      DATA B( 29),B( 30),B( 31),B( 32)/    435,    457,    472,    499/
      DATA B( 33),B( 34),B( 35),B( 36)/    522,    537,    551,    565/
      DATA B( 37),B( 38),B( 39),B( 40)/    590,    609,    622,    643/
      DATA B( 41),B( 42),B( 43),B( 44)/    670,    683,    687,    690/
      DATA B( 45),B( 46),B( 47),B( 48)/    697,    704,    709,    719/
      DATA B( 49),B( 50),B( 51),B( 52)/    724,    729,    732,    738/
      DATA B( 53),B( 54),B( 55),B( 56)/    744,    757,    763,    772/
      DATA B( 57),B( 58),B( 59),B( 60)/    781,    790,    796,    804/
      DATA B( 61),B( 62),B( 63),B( 64)/    810,    821,    835,    842/
      DATA B( 65),B( 66),B( 67),B( 68)/    853,    864,    879,    892/
      DATA B( 69),B( 70),B( 71),B( 72)/    918,    930,    940,    946/
      DATA B( 73),B( 74),B( 75),B( 76)/    950,    961,    970,    985/
      DATA B( 77),B( 78),B( 79),B( 80)/    999,   1009,   1019,   1028/
      DATA B( 81),B( 82),B( 83),B( 84)/   1038,   1049,   1061,   1068/
      DATA B( 85),B( 86),B( 87),B( 88)/   1077,   1088,   1101,   1110/
      DATA B( 89),B( 90),B( 91),B( 92)/   1120,   1131,   1143,   1159/
      DATA B( 93),B( 94),B( 95),B( 96)/   1166,   1173,   1180,   1184/
      DATA B( 97),B( 98),B( 99),B(100)/   1196,   1209,   1219,   1235/
      DATA B(101),B(102),B(103),B(104)/   1244,   1253,   1260,   1267/
      DATA B(105),B(106),B(107),B(108)/   1279,   1291,   1304,   1316/
      DATA B(109),B(110),B(111),B(112)/   1327,   1334,   1347,   1366/
      DATA B(113),B(114),B(115),B(116)/   1381,   1404,   1426,   1445/
      DATA B(117),B(118),B(119),B(120)/   1455,   1471,   1477,   1482/
      DATA B(121),B(122),B(123),B(124)/   1500,   1512,   1530,   1542/
      DATA B(125),B(126),B(127),B(128)/   1562,   1568,   1579,   1595/
      DATA B(129),B(130),B(131),B(132)/   1613,   1620,   1637,   1653/
      DATA B(133),B(134),B(135),B(136)/   1663,   1674,   1694,   1711/
      DATA B(137),B(138),B(139),B(140)/   1723,   1733,   1739,   1755/
      DATA B(141),B(142),B(143),B(144)/   1766,   1780,   1800,   1817/
      DATA B(145),B(146),B(147),B(148)/   1825,   1836,   1846,   1854/
      DATA B(149),B(150),B(151),B(152)/   1868,   1878,   1891,   1900/
      DATA B(153),B(154),B(155),B(156)/   1917,   1924,   1933,   1945/
      DATA B(157),B(158),B(159)       /   1961,   1973,   1985/
      DATA E(   1),E(   2),E(   3),E(   4)/'INVA','LID ','CHAR','ACTE'/
      DATA E(   5),E(   6),E(   7),E(   8)/'R IN',' PRE','CEDI','NG S'/
      DATA E(   9),E(  10),E(  11),E(  12)/'TATE','MENT','    ','I.L.'/
      DATA E(  13),E(  14),E(  15),E(  16)/' STO','RAGE',' EXH','AUST'/
      DATA E(  17),E(  18),E(  19),E(  20)/'ED. ','FURT','HER ','CALL'/
      DATA E(  21),E(  22),E(  23),E(  24)/'S CA','USE ','DATA',' LOS'/
      DATA E(  25),E(  26),E(  27),E(  28)/'S   ','ARGU','MENT','S CA'/
      DATA E(  29),E(  30),E(  31),E(  32)/'NNOT',' PRE','CEDE',' OPC'/
      DATA E(  33),E(  34),E(  35),E(  36)/'ODE.',' CAL','L IG','NORE'/
      DATA E(  37),E(  38),E(  39),E(  40)/'D   ','OPCO','DE C','ALL '/
      DATA E(  41),E(  42),E(  43),E(  44)/'PREC','EDED',' REL','EASE'/
      DATA E(  45),E(  46),E(  47),E(  48)/'. PR','EVIO','US L','INE '/
      DATA E(  49),E(  50),E(  51),E(  52)/'LOST','    ','PARA','METR'/
      DATA E(  53),E(  54),E(  55),E(  56)/'IC S','URFA','CE I','S NO'/
      DATA E(  57),E(  58),E(  59),E(  60)/'T NA','MED.',' SUR','FACE'/
      DATA E(  61),E(  62),E(  63),E(  64)/' IS ','UNDE','FINE','D   '/
      DATA E(  65),E(  66),E(  67),E(  68)/'PARA','METR','IC S','URFA'/
      DATA E(  69),E(  70),E(  71),E(  72)/'CE V','ARIA','BLE ','IS N'/
      DATA E(  73),E(  74),E(  75),E(  76)/'OT A',' SCA','LAR.','SURF'/
      DATA E(  77),E(  78),E(  79),E(  80)/'ACE ','IS U','NDEF','INED'/
      DATA E(  81),E(  82),E(  83),E(  84)/'PARA','METR','IC S','URFA'/
      DATA E(  85),E(  86),E(  87),E(  88)/'CE M','ODIF','IER ','IS N'/
      DATA E(  89),E(  90),E(  91),E(  92)/'OT D','ERIV',' OR ','NODE'/
      DATA E(  93),E(  94),E(  95),E(  96)/'R. S','URFA','CE I','S UN'/
      DATA E(  97),E(  98),E(  99),E( 100)/'DEFI','NED ','NO P','ARAM'/
      DATA E( 101),E( 102),E( 103),E( 104)/'ETER','S FO','LLOW',' COM'/
      DATA E( 105),E( 106),E( 107),E( 108)/'MAND','    ','NO S','URFA'/
      DATA E( 109),E( 110),E( 111),E( 112)/'CE I','S NA','MED.',' COM'/
      DATA E( 113),E( 114),E( 115),E( 116)/'MAND',' IGN','ORED',', CO'/
      DATA E( 117),E( 118),E( 119),E( 120)/'NTIN','UING','    ','TAGT'/
      DATA E( 121),E( 122),E( 123),E( 124)/'BL M','AY O','VERF','LOW.'/
      DATA E( 125),E( 126),E( 127),E( 128)/' TOO',' MAN','Y CH','ECK '/
      DATA E( 129),E( 130),E( 131),E( 132)/'SURF','ACES','    ','TOO '/
      DATA E( 133),E( 134),E( 135),E( 136)/'MANY',' SYS','TEM-','GENE'/
      DATA E( 137),E( 138),E( 139),E( 140)/'RATE','D LA','BELS','; TA'/
      DATA E( 141),E( 142),E( 143),E( 144)/'BLE ','LENG','TH E','XCEE'/
      DATA E( 145),E( 146),E( 147),E( 148)/'DED ','SYMB','OL E','XCEE'/
      DATA E( 149),E( 150),E( 151),E( 152)/'DS S','IX C','HARA','CTER'/
      DATA E( 153),E( 154),E( 155),E( 156)/'S; I','T MA','Y BE',' TRU'/
      DATA E( 157),E( 158),E( 159),E( 160)/'NCAT','ED  ','NAME',' FOL'/
      DATA E( 161),E( 162),E( 163),E( 164)/'LOWI','NG C','ALL/',' IS '/
      DATA E( 165),E( 166),E( 167),E( 168)/'NOT ','A PR','EVIO','USLY'/
      DATA E( 169),E( 170),E( 171),E( 172)/' DEF','INED',' MAC','RO N'/
      DATA E( 173),E( 174),E( 175),E( 176)/'OR I','T IS',' A S','YSTE'/
      DATA E( 177),E( 178),E( 179),E( 180)/'M MA','CRO ','UNKN','OWN '/
      DATA E( 181),E( 182),E( 183),E( 184)/'FORM','AT U','SED ','IN O'/
      DATA E( 185),E( 186),E( 187),E( 188)/'BTAI','N ST','ATEM','ENT '/
      DATA E( 189),E( 190),E( 191),E( 192)/'TOO ','MANY',' ARG','UMEN'/
      DATA E( 193),E( 194),E( 195),E( 196)/'TS I','N CA','NON ','OR O'/
      DATA E( 197),E( 198),E( 199),E( 200)/'BTAI','N ST','ATEM','ENT;'/
      DATA E( 201),E( 202),E( 203),E( 204)/'CANS','TK A','RRAY',' EXC'/
      DATA E( 205),E( 206),E( 207),E( 208)/'EEDE','D   ','LINU','SD T'/
      DATA E( 209),E( 210),E( 211),E( 212)/'ABLE',' USE','D IN',' MAC'/
      DATA E( 213),E( 214),E( 215),E( 216)/'RO P','ROCE','SSIN','G IS'/
      DATA E( 217),E( 218),E( 219),E( 220)/' FIL','LED.',' SEE',' APT'/
      DATA E( 221),E( 222),E( 223),E( 224)/' SYS','TEM ','PROG','RAMM'/
      DATA E( 225),E( 226),E( 227),E( 228)/'ER  ','TOO ','MANY',' MAC'/
      DATA E( 229),E( 230),E( 231),E( 232)/'RO V','ARIA','BLES',' IN '/
      DATA E( 233),E( 234),E( 235),E( 236)/'PART',' PRO','GRAM','. MA'/
      DATA E( 237),E( 238),E( 239),E( 240)/'CDF1',' AND',' MAC','DF2 '/
      DATA E( 241),E( 242),E( 243),E( 244)/'TABL','ES E','XCEE','DED '/
      DATA E( 245),E( 246),E( 247),E( 248)/'TOO ','MANY',' VAL','UES '/
      DATA E( 249),E( 250),E( 251),E( 252)/'ASSI','GNED',' TO ','THE '/
      DATA E( 253),E( 254),E( 255),E( 256)/'MACR','O VA','RIAB','LES '/
      DATA E( 257),E( 258),E( 259),E( 260)/'IN P','ART ','PROG','RAM.'/
      DATA E( 261),E( 262),E( 263),E( 264)/' MAC','HST ','TABL','E EX'/
      DATA E( 265),E( 266),E( 267),E( 268)/'CEED','ED  ','MACR','O NE'/
      DATA E( 269),E( 270),E( 271),E( 272)/'ST L','EVEL',' MAX','IMUM'/
      DATA E( 273),E( 274),E( 275),E( 276)/' EXC','EEDE','D. M','ACSV'/
      DATA E( 277),E( 278),E( 279),E( 280)/'1,MA','CSV2',',MAC','SV3 '/
      DATA E( 281),E( 282),E( 283),E( 284)/'TABL','ES E','XCEE','DED '/
      DATA E( 285),E( 286),E( 287),E( 288)/'MAS ','TABL','E US','ED I'/
      DATA E( 289),E( 290),E( 291),E( 292)/'N MA','CRO ','PROC','ESSI'/
      DATA E( 293),E( 294),E( 295),E( 296)/'NG I','S FI','LLED','. SE'/
      DATA E( 297),E( 298),E( 299),E( 300)/'E AP','T SY','STEM',' PRO'/
      DATA E( 301),E( 302),E( 303),E( 304)/'GRAM','MER ','MORE',' THA'/
      DATA E( 305),E( 306),E( 307),E( 308)/'N 50',' MAC','ROS ','IN P'/
      DATA E( 309),E( 310),E( 311),E( 312)/'ART ','PROG','RAM.',' MAC'/
      DATA E( 313),E( 314),E( 315),E( 316)/'SEQ ','TABL','E EX','CEED'/
      DATA E( 317),E( 318),E( 319),E( 320)/'ED  ','TOO ','MANY',' MAC'/
      DATA E( 321),E( 322),E( 323),E( 324)/'RO V','ARIA','BLES',' HAV'/
      DATA E( 325),E( 326),E( 327),E( 328)/'E BE','EN A','SSIG','NED '/
      DATA E( 329),E( 330),E( 331),E( 332)/'MACR','O NA','MES.',' MNM'/
      DATA E( 333),E( 334),E( 335),E( 336)/'VB A','ND M','NMVC',' TAB'/
      DATA E( 337),E( 338),E( 339),E( 340)/'LES ','EXCE','EDED','    '/
      DATA E( 341),E( 342),E( 343),E( 344)/'VBLS','AV T','ABLE',' OVE'/
      DATA E( 345),E( 346),E( 347),E( 348)/'RFLO','W.RE','DUCE',' NUM'/
      DATA E( 349),E( 350),E( 351),E( 352)/'BER ','OF M','ACRO',' CAL'/
      DATA E( 353),E( 354),E( 355),E( 356)/'LS A','ND/O','R NU','MBER'/
      DATA E( 357),E( 358),E( 359),E( 360)/' OF ','MACR','O VA','RIAB'/
      DATA E( 361),E( 362),E( 363),E( 364)/'LES ','MACS','PD T','ABLE'/
      DATA E( 365),E( 366),E( 367),E( 368)/' USE','D IN',' MAC','RO P'/
      DATA E( 369),E( 370),E( 371),E( 372)/'ROCE','SSIN','G IS',' FIL'/
      DATA E( 373),E( 374),E( 375),E( 376)/'LED.','SEE ','APT ','SYST'/
      DATA E( 377),E( 378),E( 379),E( 380)/'EM P','ROGR','AMME','R   '/
      DATA E( 381),E( 382),E( 383),E( 384)/'TOO ','MANY',' MAC','RO V'/
      DATA E( 385),E( 386),E( 387),E( 388)/'ARIA','BLES',' IN ','A SI'/
      DATA E( 389),E( 390),E( 391),E( 392)/'NGLE',' EXP','RESS','ION.'/
      DATA E( 393),E( 394),E( 395),E( 396)/' MRG','STK ','OR M','ACVA'/
      DATA E( 397),E( 398),E( 399),E( 400)/'R TA','BLE ','OVER','FLOW'/
      DATA E( 401),E( 402),E( 403),E( 404)/'    ','KSC ','TABL','E FI'/
      DATA E( 405),E( 406),E( 407),E( 408)/'LLED','. TO','O MA','NY S'/
      DATA E( 409),E( 410),E( 411),E( 412)/'CULP','TURE','D SU','RFAC'/
      DATA E( 413),E( 414),E( 415),E( 416)/'E DE','FINI','TION','S   '/
      DATA E( 417),E( 418),E( 419),E( 420)/'TOO ','MUCH',' MAC','RO T'/
      DATA E( 421),E( 422),E( 423),E( 424)/'EXT ','NUME','RIC ','NAME'/
      DATA E( 425),E( 426),E( 427),E( 428)/' TAB','LE O','VERF','LOW '/
      DATA E( 429),E( 430),E( 431),E( 432)/'INVA','LID ','USE ','OF W'/
      DATA E( 433),E( 434),E( 435),E( 436)/'ORD ','TERM','AC  ','SUPP'/
      DATA E( 437),E( 438),E( 439),E( 440)/'OSED',' PRO','CEDU','RE D'/
      DATA E( 441),E( 442),E( 443),E( 444)/'OES ','NOT ','HAVE',' CLA'/
      DATA E( 445),E( 446),E( 447),E( 448)/'SS P','ROCE','DURE',' OR '/
      DATA E( 449),E( 450),E( 451),E( 452)/'FUNC','TION','. SE','E AP'/
      DATA E( 453),E( 454),E( 455),E( 456)/'T SY','STEM',' PRO','GRAM'/
      DATA E( 457),E( 458),E( 459),E( 460)/'MER ','LABA','RY T','ABLE'/
      DATA E( 461),E( 462),E( 463),E( 464)/' FIL','LED.',' NO ','FURT'/
      DATA E( 465),E( 466),E( 467),E( 468)/'HER ','SEAR','CH F','OR M'/
      DATA E( 469),E( 470),E( 471),E( 472)/'ISSI','NG L','ABEL','S   '/
      DATA E( 473),E( 474),E( 475),E( 476)/'GEOM','ETRI','C VA','RIAB'/
      DATA E( 477),E( 478),E( 479),E( 480)/'LE B','EING',' USE','D HA'/
      DATA E( 481),E( 482),E( 483),E( 484)/'S BE','EN P','REVI','OUSL'/
      DATA E( 485),E( 486),E( 487),E( 488)/'Y DE','FINE','D WI','TH T'/
      DATA E( 489),E( 490),E( 491),E( 492)/'HE S','AME ','MODE','. FI'/
      DATA E( 493),E( 494),E( 495),E( 496)/'RST ','DEFI','NITI','ON O'/
      DATA E( 497),E( 498),E( 499),E( 500)/'VERR','IDDE','N   ','SCUL'/
      DATA E( 501),E( 502),E( 503),E( 504)/'PTUR','ED S','URFA','CE V'/
      DATA E( 505),E( 506),E( 507),E( 508)/'ARIA','BLE ','BEIN','G US'/
      DATA E( 509),E( 510),E( 511),E( 512)/'ED H','AS B','EEN ','PREV'/
      DATA E( 513),E( 514),E( 515),E( 516)/'IOUS','LY D','EFIN','ED. '/
      DATA E( 517),E( 518),E( 519),E( 520)/'FIRS','T DE','F. O','VERR'/
      DATA E( 521),E( 522),E( 523),E( 524)/'IDDE','N   ','TOO ','MANY'/
      DATA E( 525),E( 526),E( 527),E( 528)/' LAR','GE D','ATA ','ARRA'/
      DATA E( 529),E( 530),E( 531),E( 532)/'Y DE','FINI','TION','S. C'/
      DATA E( 533),E( 534),E( 535),E( 536)/'ANSI','Z TA','BLE ','FILL'/
      DATA E( 537),E( 538),E( 539),E( 540)/'ED  ','MISS','ING ','FINI'/
      DATA E( 541),E( 542),E( 543),E( 544)/'. FI','NI I','NSER','TED '/
      DATA E( 545),E( 546),E( 547),E( 548)/'AND ','PROC','ESSI','NG C'/
      DATA E( 549),E( 550),E( 551),E( 552)/'ONTI','NUES','    ','MISS'/
      DATA E( 553),E( 554),E( 555),E( 556)/'ING ','TERM','AC. ','FINI'/
      DATA E( 557),E( 558),E( 559),E( 560)/' INS','ERTE','D AN','D PR'/
      DATA E( 561),E( 562),E( 563),E( 564)/'OCES','SING',' CON','TINU'/
      DATA E( 565),E( 566),E( 567),E( 568)/'ES  ','SEGM','ENT ','READ'/
      DATA E( 569),E( 570),E( 571),E( 572)/' OR ','FIRS','T CA','LL T'/
      DATA E( 573),E( 574),E( 575),E( 576)/'O SY','STEM',' MAC','RO C'/
      DATA E( 577),E( 578),E( 579),E( 580)/'ANNO','T BE',' CON','TAIN'/
      DATA E( 581),E( 582),E( 583),E( 584)/'ED I','N A ','SEGM','ENT '/
      DATA E( 585),E( 586),E( 587),E( 588)/'READ',' OR ','A SY','STEM'/
      DATA E( 589),E( 590),E( 591),E( 592)/' MAC','RO  ','UNAB','LE T'/
      DATA E( 593),E( 594),E( 595),E( 596)/'O OP','EN L','IBRA','RY A'/
      DATA E( 597),E( 598),E( 599),E( 600)/'PTLI','B. C','OULD',' RES'/
      DATA E( 601),E( 602),E( 603),E( 604)/'ULT ','FROM',' CAL','L TO'/
      DATA E( 605),E( 606),E( 607),E( 608)/' UND','EFIN','ED M','ACRO'/
      DATA E( 609),E( 610),E( 611),E( 612)/'    ','SEGM','ENT ','NAME'/
      DATA E( 613),E( 614),E( 615),E( 616)/'D IN',' REA','D/ S','TATE'/
      DATA E( 617),E( 618),E( 619),E( 620)/'MENT',' IS ','NOT ','IN A'/
      DATA E( 621),E( 622),E( 623),E( 624)/'PTLI','B   ','UNAB','LE T'/
      DATA E( 625),E( 626),E( 627),E( 628)/'O RE','AD A',' REC','ORD '/
      DATA E( 629),E( 630),E( 631),E( 632)/'FROM',' APT','LIB;',' I/O'/
      DATA E( 633),E( 634),E( 635),E( 636)/' ERR','OR O','R IL','LEGA'/
      DATA E( 637),E( 638),E( 639),E( 640)/'L BL','OCKS','IZE ','OR R'/
      DATA E( 641),E( 642),E( 643),E( 644)/'ECOR','D SI','ZE  ','GEOM'/
      DATA E( 645),E( 646),E( 647),E( 648)/'ETRI','C VA','RIAB','LE B'/
      DATA E( 649),E( 650),E( 651),E( 652)/'EING',' USE','D HA','S BE'/
      DATA E( 653),E( 654),E( 655),E( 656)/'EN P','REVI','OUSL','Y DE'/
      DATA E( 657),E( 658),E( 659),E( 660)/'FINE','D WI','TH A',' DIF'/
      DATA E( 661),E( 662),E( 663),E( 664)/'FERE','NT M','ODE.',' FIR'/
      DATA E( 665),E( 666),E( 667),E( 668)/'ST D','EFIN','ITIO','N RE'/
      DATA E( 669),E( 670),E( 671),E( 672)/'TAIN','ED  ','MISS','ING '/
      DATA E( 673),E( 674),E( 675),E( 676)/'LABE','L ST','ATEM','ENT '/
      DATA E( 677),E( 678),E( 679),E( 680)/'ADDR','ESSE','D BY',' JUM'/
      DATA E( 681),E( 682),E( 683),E( 684)/'PTO ','OR I','F   ','DUPL'/
      DATA E( 685),E( 686),E( 687),E( 688)/'ICAT','E LA','BEL ','MIXE'/
      DATA E( 689),E( 690),E( 691),E( 692)/'D MO','DE  ','INVA','LID '/
      DATA E( 693),E( 694),E( 695),E( 696)/'USE ','OF M','INUS',' SIG'/
      DATA E( 697),E( 698),E( 699),E( 700)/'N   ','INVA','LID ','STAT'/
      DATA E( 701),E( 702),E( 703),E( 704)/'EMEN','T IG','NORE','D   '/
      DATA E( 705),E( 706),E( 707),E( 708)/'IMPR','OPER',' ARG','UMEN'/
      DATA E( 709),E( 710),E( 711),E( 712)/'T   ','MISS','ING ','LABE'/
      DATA E( 713),E( 714),E( 715),E( 716)/'L. S','TATE','MENT',' NOT'/
      DATA E( 717),E( 718),E( 719),E( 720)/' REA','CHAB','LE  ','MATR'/
      DATA E( 721),E( 722),E( 723),E( 724)/'IX M','UST ','FOLL','OW  '/
      DATA E( 725),E( 726),E( 727),E( 728)/'NOMO','RE M','UST ','FOLL'/
      DATA E( 729),E( 730),E( 731),E( 732)/'OW  ','MIXE','D MO','DE  '/
      DATA E( 733),E( 734),E( 735),E( 736)/'VARI','ABLE',' IS ','UNRE'/
      DATA E( 737),E( 738),E( 739),E( 740)/'SERV','ED  ','NO T','YPE '/
      DATA E( 741),E( 742),E( 743),E( 744)/'FOR ','VARI','ABLE','    '/
      DATA E( 745),E( 746),E( 747),E( 748)/'SURF','ACE ','TYPE',' CHA'/
      DATA E( 749),E( 750),E( 751),E( 752)/'NGED',' IN ','NEST','ED G'/
      DATA E( 753),E( 754),E( 755),E( 756)/'EOME','TRIC',' DEF','INIT'/
      DATA E( 757),E( 758),E( 759),E( 760)/'ION ','MACR','O DE','FINI'/
      DATA E( 761),E( 762),E( 763),E( 764)/'TION',' NES','TED ','MACR'/
      DATA E( 765),E( 766),E( 767),E( 768)/'O NA','ME N','OT P','RECE'/
      DATA E( 769),E( 770),E( 771),E( 772)/'EDED',' BY ','CALL','    '/
      DATA E( 773),E( 774),E( 775),E( 776)/'DUMM','Y VA','RIAB','LE E'/
      DATA E( 777),E( 778),E( 779),E( 780)/'XPEC','TS M','ACRO',' NAM'/
      DATA E( 781),E( 782),E( 783),E( 784)/'E   ','DUMM','Y VA','RIAB'/
      DATA E( 785),E( 786),E( 787),E( 788)/'LE R','EJEC','TS M','ACRO'/
      DATA E( 789),E( 790),E( 791),E( 792)/' NAM','E   ','UNKN','OWN '/
      DATA E( 793),E( 794),E( 795),E( 796)/'MACR','O VA','RIAB','LE  '/
      DATA E( 797),E( 798),E( 799),E( 800)/'ERRO','R IN',' FIN','AL M'/
      DATA E( 801),E( 802),E( 803),E( 804)/'ACRO',' PRO','CESS','ING '/
      DATA E( 805),E( 806),E( 807),E( 808)/'RECU','RSIV','E US','E OF'/
      DATA E( 809),E( 810),E( 811),E( 812)/' MAC','ROS ','ILLE','GAL '/
      DATA E( 813),E( 814),E( 815),E( 816)/'MODE',' FOR',' TEM','PORA'/
      DATA E( 817),E( 818),E( 819),E( 820)/'RY I','N CA','LL T','O MA'/
      DATA E( 821),E( 822),E( 823),E( 824)/'CRO ','VARI','ABLE',' NAM'/
      DATA E( 825),E( 826),E( 827),E( 828)/'E IN',' CAN','ON D','EFIN'/
      DATA E( 829),E( 830),E( 831),E( 832)/'ITIO','N IS',' OF ','INCO'/
      DATA E( 833),E( 834),E( 835),E( 836)/'RREC','T MO','DE  ','INVA'/
      DATA E( 837),E( 838),E( 839),E( 840)/'LID ','TABC','YL D','EFIN'/
      DATA E( 841),E( 842),E( 843),E( 844)/'ITIO','N   ','INVA','LID '/
      DATA E( 845),E( 846),E( 847),E( 848)/'TABC','YL U','SED ','IN R'/
      DATA E( 849),E( 850),E( 851),E( 852)/'LDSR','F DE','FINI','TION'/
      DATA E( 853),E( 854),E( 855),E( 856)/'    ','INPU','T ST','ATEM'/
      DATA E( 857),E( 858),E( 859),E( 860)/'ENT ','IS T','OO L','ONG.'/
      DATA E( 861),E( 862),E( 863),E( 864)/' STA','CK O','VERF','LOW '/
      DATA E( 865),E( 866),E( 867),E( 868)/'BOUN','DED ','GEOM','ETRY'/
      DATA E( 869),E( 870),E( 871),E( 872)/' MUS','T NO','T BE',' SUB'/
      DATA E( 873),E( 874),E( 875),E( 876)/'SCRI','PTED','. ST','ATEM'/
      DATA E( 877),E( 878),E( 879),E( 880)/'ENT ','IGNO','RED ','INVA'/
      DATA E( 881),E( 882),E( 883),E( 884)/'LID ','ARGU','MENT',' IN '/
      DATA E( 885),E( 886),E( 887),E( 888)/'A LA','RGE ','DATA',' CAN'/
      DATA E( 889),E( 890),E( 891),E( 892)/'ON S','TATE','MENT','    '/
      DATA E( 893),E( 894),E( 895),E( 896)/'OBTA','IN S','TATE','MENT'/
      DATA E( 897),E( 898),E( 899),E( 900)/' SPE','CIFI','ES M','ORE '/
      DATA E( 901),E( 902),E( 903),E( 904)/'VARI','ABLE','S TH','AN T'/
      DATA E( 905),E( 906),E( 907),E( 908)/'HERE',' ARE',' ELE','MENT'/
      DATA E( 909),E( 910),E( 911),E( 912)/'S IN',' IND','ICAT','ED S'/
      DATA E( 913),E( 914),E( 915),E( 916)/'URFA','CE C','ANON','ICAL'/
      DATA E( 917),E( 918),E( 919),E( 920)/' FOR','M   ','TOO ','MANY'/
      DATA E( 921),E( 922),E( 923),E( 924)/' DO-','ARGU','MENT','S OR'/
      DATA E( 925),E( 926),E( 927),E( 928)/' ARG','UMEN','T WI','THOU'/
      DATA E( 929),E( 930),E( 931),E( 932)/'T VA','LUE ','DO-L','OOP '/
      DATA E( 933),E( 934),E( 935),E( 936)/'NOT ','CLOS','ED A','T FI'/
      DATA E( 937),E( 938),E( 939),E( 940)/'NI O','R TE','RMAC','    '/
      DATA E( 941),E( 942),E( 943),E( 944)/'MORE',' THA','N 10',' DO '/
      DATA E( 945),E( 946),E( 947),E( 948)/'NEST','ED  ','BAD ','NEST'/
      DATA E( 949),E( 950),E( 951),E( 952)/'ED D','O   ','IDEN','TICA'/
      DATA E( 953),E( 954),E( 955),E( 956)/'L NA','MES ','OF V','ARIA'/
      DATA E( 957),E( 958),E( 959),E( 960)/'BLES',' IN ','NEST','ED D'/
      DATA E( 961),E( 962),E( 963),E( 964)/'O   ','ILLE','GAL ','PATE'/
      DATA E( 965),E( 966),E( 967),E( 968)/'RN D','EFIN','ITIO','N FO'/
      DATA E( 969),E( 970),E( 971),E( 972)/'RMAT','    ','WRON','G SU'/
      DATA E( 973),E( 974),E( 975),E( 976)/'RFAC','E AS','SOCI','ATED'/
      DATA E( 977),E( 978),E( 979),E( 980)/' WIT','H VA','RIAB','LE I'/
      DATA E( 981),E( 982),E( 983),E( 984)/'N OB','TAIN',' STA','TEME'/
      DATA E( 985),E( 986),E( 987),E( 988)/'NT  ','ILLE','GAL ','SUBS'/
      DATA E( 989),E( 990),E( 991),E( 992)/'CRIP','TED ','VARI','ABLE'/
      DATA E( 993),E( 994),E( 995),E( 996)/'. CH','ECK ','FOR ','MISS'/
      DATA E( 997),E( 998),E( 999),E(1000)/'ING ','RESE','RV  ','MORE'/
      DATA E(1001),E(1002),E(1003),E(1004)/' THA','N 30',' RES','P. 5'/
      DATA E(1005),E(1006),E(1007),E(1008)/' POI','NT D','EFIN','ITIO'/
      DATA E(1009),E(1010),E(1011),E(1012)/'NS  ','MORE',' THA','N 30'/
      DATA E(1013),E(1014),E(1015),E(1016)/' RES','P. 5',' SPL','INE '/
      DATA E(1017),E(1018),E(1019),E(1020)/'DEFI','NITI','ONS ','SURF'/
      DATA E(1021),E(1022),E(1023),E(1024)/'ACE ','DEFI','NITI','ON I'/
      DATA E(1025),E(1026),E(1027),E(1028)/'S NO','T CO','MPLE','TE  '/
      DATA E(1029),E(1030),E(1031),E(1032)/'TOO ','MANY',' SEG','MENT'/
      DATA E(1033),E(1034),E(1035),E(1036)/'S IN',' THE',' FLO','W SE'/
      DATA E(1037),E(1038),E(1039),E(1040)/'CTIO','N   ','INCO','RREC'/
      DATA E(1041),E(1042),E(1043),E(1044)/'T DE','FINI','TION',' OF '/
      DATA E(1045),E(1046),E(1047),E(1048)/'THE ','FLOW',' SEG','MENT'/
      DATA E(1049),E(1050),E(1051),E(1052)/'    ','TOO ','MANY',' OR '/
      DATA E(1053),E(1054),E(1055),E(1056)/'INCO','RREC','T IT','EMS '/
      DATA E(1057),E(1058),E(1059),E(1060)/'IN T','HE F','LOW ','SECT'/
      DATA E(1061),E(1062),E(1063),E(1064)/'ION ','TOO ','MANY',' SEG'/
      DATA E(1065),E(1066),E(1067),E(1068)/' DEF','INIT','IONS','    '/
      DATA E(1069),E(1070),E(1071),E(1072)/'MULT','IPLE',' DEF','INED'/
      DATA E(1073),E(1074),E(1075),E(1076)/' LIM','IT O','R WE','IGHT'/
      DATA E(1077),E(1078),E(1079),E(1080)/'    ','TANS','PL,C','RSSP'/
      DATA E(1081),E(1082),E(1083),E(1084)/'L OR',' NOR','MAL ','MULT'/
      DATA E(1085),E(1086),E(1087),E(1088)/'IPLE',' DEF','INED','    '/
      DATA E(1089),E(1090),E(1091),E(1092)/'USE ','OF C','RSSP','L ON'/
      DATA E(1093),E(1094),E(1095),E(1096)/'LY C','ORRE','CT A','T ST'/
      DATA E(1097),E(1098),E(1099),E(1100)/'ART ','AND ','END ','POIN'/
      DATA E(1101),E(1102),E(1103),E(1104)/'T   ','MODI','FICA','TOR '/
      DATA E(1105),E(1106),E(1107),E(1108)/'OR D','EFIN','ITIO','N RE'/
      DATA E(1109),E(1110),E(1111),E(1112)/'PEAT','ING ','MORE',' THA'/
      DATA E(1113),E(1114),E(1115),E(1116)/'N 30',' SUR','FACE','S DE'/
      DATA E(1117),E(1118),E(1119),E(1120)/'FINE',' A C','OMBI','N   '/
      DATA E(1121),E(1122),E(1123),E(1124)/'MORE',' THA','N ON','E PA'/
      DATA E(1125),E(1126),E(1127),E(1128)/'TCH ','DEFI','NE A',' PAT'/
      DATA E(1129),E(1130),E(1131),E(1132)/'CH/P','NTSO','N   ','TRFO'/
      DATA E(1133),E(1134),E(1135),E(1136)/'RM,M','ATRI','X NO','T AL'/
      DATA E(1137),E(1138),E(1139),E(1140)/'LOWE','D IN',' THI','S DE'/
      DATA E(1141),E(1142),E(1143),E(1144)/'FINI','TION','    ','TRFO'/
      DATA E(1145),E(1146),E(1147),E(1148)/'RM,M','ATRI','X SH','OULD'/
      DATA E(1149),E(1150),E(1151),E(1152)/' BE ','DEFI','NED ','AT T'/
      DATA E(1157),E(1158),E(1159),E(1160)/'FINI','TION','    ','MATR'/
      DATA E(1161),E(1162),E(1163),E(1164)/'IX D','EFIN','ITIO','N EX'/
      DATA E(1165),E(1166),E(1167),E(1168)/'PECT','ED  ','POIN','T DE'/
      DATA E(1169),E(1170),E(1171),E(1172)/'FINI','TION',' EXP','ECTE'/
      DATA E(1173),E(1174),E(1175),E(1176)/'D   ','VECT','OR D','EFIN'/
      DATA E(1177),E(1178),E(1179),E(1180)/'ITIO','N EX','PECT','ED  '/
      DATA E(1181),E(1182),E(1183),E(1184)/'SCAL','AR E','XPEC','TED '/
      DATA E(1185),E(1186),E(1187),E(1188)/'POIN','T DE','FINI','TION'/
      DATA E(1189),E(1190),E(1191),E(1192)/' NOT',' PER','MITT','ED I'/
      DATA E(1193),E(1194),E(1195),E(1196)/'N TH','IS P','OSIT','ION '/
      DATA E(1197),E(1198),E(1199),E(1200)/'VECT','OR D','EFIN','ITIO'/
      DATA E(1201),E(1202),E(1203),E(1204)/'N NO','T PE','RMIT','TED '/
      DATA E(1205),E(1206),E(1207),E(1208)/'IN T','HIS ','POSI','TION'/
      DATA E(1209),E(1210),E(1211),E(1212)/'    ','SCAL','AR N','OT P'/
      DATA E(1213),E(1214),E(1215),E(1216)/'ERMI','TTED',' IN ','THIS'/
      DATA E(1217),E(1218),E(1219),E(1220)/' POS','ITIO','N   ','VARI'/
      DATA E(1221),E(1222),E(1223),E(1224)/'OUS ','NUMB','ERS ','OF P'/
      DATA E(1225),E(1226),E(1227),E(1228)/'OINT','S OR',' LES','S TH'/
      DATA E(1229),E(1230),E(1231),E(1232)/'AN T','WO P','OINT','S IN'/
      DATA E(1233),E(1234),E(1235),E(1236)/' THE',' SPL','INES','STK '/
      DATA E(1237),E(1238),E(1239),E(1240)/'TABL','E FI','LLED','. SU'/
      DATA E(1241),E(1242),E(1243),E(1244)/'RFAC','E UN','DEFI','NED '/
      DATA E(1245),E(1246),E(1247),E(1248)/'TRIP','LE N','ESTE','D SU'/
      DATA E(1249),E(1250),E(1251),E(1252)/'RFAC','E DE','FINI','TION'/
      DATA E(1253),E(1254),E(1255),E(1256)/'    ','SSUR','F DE','FINI'/
      DATA E(1257),E(1258),E(1259),E(1260)/'TION',' EXP','ECTE','D   '/
      DATA E(1261),E(1262),E(1263),E(1264)/'SCUR','V DE','FINI','TION'/
      DATA E(1265),E(1266),E(1267),E(1268)/' EXP','ECTE','D   ','SSUR'/
      DATA E(1269),E(1270),E(1271),E(1272)/'F DE','FINI','TION',' NOT'/
      DATA E(1273),E(1274),E(1275),E(1276)/' PER','MITT','ED I','N TH'/
      DATA E(1277),E(1278),E(1279),E(1280)/'IS P','OSIT','ION ','SCUR'/
      DATA E(1281),E(1282),E(1283),E(1284)/'V DE','FINI','TION',' NOT'/
      DATA E(1285),E(1286),E(1287),E(1288)/' PER','MITT','ED I','N TH'/
      DATA E(1289),E(1290),E(1291),E(1292)/'IS P','OSIT','ION ','SURF'/
      DATA E(1293),E(1294),E(1295),E(1296)/'ACE ','DEFI','NITI','ON A'/
      DATA E(1297),E(1298),E(1299),E(1300)/'ND I','TS S','IZE ','IS N'/
      DATA E(1301),E(1302),E(1303),E(1304)/'OT T','O BE',' FOU','ND  '/
      DATA E(1305),E(1306),E(1307),E(1308)/'FORM','AT U','NKNO','WN O'/
      DATA E(1309),E(1310),E(1311),E(1312)/'R SO','ME P','ARAM','ETER'/
      DATA E(1313),E(1314),E(1315),E(1316)/'S AR','E UN','DEFI','NED '/
      DATA E(1317),E(1318),E(1319),E(1320)/'ILLE','GAL ','ARGU','MENT'/
      DATA E(1321),E(1322),E(1323),E(1324)/' IN ','POST','PROC','ESSO'/
      DATA E(1325),E(1326),E(1327),E(1328)/'R ST','ATEM','ENT ','ILLE'/
      DATA E(1329),E(1330),E(1331),E(1332)/'GAL ','GODL','TA S','TATE'/
      DATA E(1333),E(1334),E(1335),E(1336)/'MENT','    ','NO D','RIVE'/
      DATA E(1337),E(1338),E(1339),E(1340)/' SUR','FACE',' NAM','ED A'/
      DATA E(1341),E(1342),E(1343),E(1344)/'FTER',' GO/',', EN','TERI'/
      DATA E(1345),E(1346),E(1347),E(1348)/'NG R','ESTA','RT  ','ITEM'/
      DATA E(1349),E(1350),E(1351),E(1352)/' NOT',' FED','RAT,',' TO,'/
      DATA E(1353),E(1354),E(1355),E(1356)/' ON,',' PAS','T OR',' SUR'/
      DATA E(1357),E(1358),E(1359),E(1360)/'FACE',' FOU','ND A','FTER'/
      DATA E(1361),E(1362),E(1363),E(1364)/' GO/','. EN','TERI','NG R'/
      DATA E(1365),E(1366),E(1367),E(1368)/'ESTA','RT  ','ILLE','GAL '/
      DATA E(1369),E(1370),E(1371),E(1372)/'PERM','ANEN','T ID','ENTI'/
      DATA E(1373),E(1374),E(1375),E(1376)/'FIER',' FOL','LOWS',' GO/'/
      DATA E(1377),E(1378),E(1379),E(1380)/'. EN','TERI','NG R','ESTA'/
      DATA E(1381),E(1382),E(1383),E(1384)/'RT  ','A LO','GICA','LLY '/
      DATA E(1385),E(1386),E(1387),E(1388)/'COMP','LETE',' GO/',' COM'/
      DATA E(1389),E(1390),E(1391),E(1392)/'MAND',' WAS',' FOL','LOWE'/
      DATA E(1393),E(1394),E(1395),E(1396)/'D BY',' OTH','ER D','ATA.'/
      DATA E(1397),E(1398),E(1399),E(1400)/' SUR','PLUS',' CHE','CK S'/
      DATA E(1401),E(1402),E(1403),E(1404)/'URFA','CES ','IGNO','RED '/
      DATA E(1405),E(1406),E(1407),E(1408)/'MORE',' THA','N ON','E CH'/
      DATA E(1409),E(1410),E(1411),E(1412)/'ECK ','SURF','ACE ','FOUN'/
      DATA E(1413),E(1414),E(1415),E(1416)/'D AF','TER ','A GO',' COM'/
      DATA E(1417),E(1418),E(1419),E(1420)/'MAND','. SU','RPLU','S CH'/
      DATA E(1421),E(1422),E(1423),E(1424)/'ECK ','SURF','ACES',' IGN'/
      DATA E(1425),E(1426),E(1427),E(1428)/'ORED','    ','ILLE','GAL '/
      DATA E(1429),E(1430),E(1431),E(1432)/'LANG','UAGE',' USA','GE E'/
      DATA E(1433),E(1434),E(1435),E(1436)/'NCOU','NTER','ED B','EFOR'/
      DATA E(1437),E(1438),E(1439),E(1440)/'E DR','IVE ','SURF','ACE.'/
      DATA E(1441),E(1442),E(1443),E(1444)/'ENTE','RING',' RES','TART'/
      DATA E(1445),E(1446),E(1447),E(1448)/'    ','FIRS','T NO','T DR'/
      DATA E(1449),E(1450),E(1451),E(1452)/'IVE ','SURF','ACE.',' DS '/
      DATA E(1453),E(1454),E(1455),E(1456)/'IS A','SSUM','ED  ','STAT'/
      DATA E(1457),E(1458),E(1459),E(1460)/'EMEN','T WI','TH W','RONG'/
      DATA E(1461),E(1462),E(1463),E(1464)/' ARG','UMEN','TS: ','TOO '/
      DATA E(1465),E(1466),E(1467),E(1468)/'LONG',' OR ','ILLE','GAL '/
      DATA E(1469),E(1470),E(1471),E(1472)/'GEOM','ETRY','    ','PARA'/
      DATA E(1473),E(1474),E(1475),E(1476)/'METE','R LI','ST T','OO L'/
      DATA E(1477),E(1478),E(1479),E(1480)/'ONG ','ILLE','GAL ','ARGU'/
      DATA E(1481),E(1482),E(1483),E(1484)/'MENT','    ','APPR','OPRI'/
      DATA E(1485),E(1486),E(1487),E(1488)/'ATE ','SURF','ACE ','IS N'/
      DATA E(1489),E(1490),E(1491),E(1492)/'OT N','AMED',' AFT','ER P'/
      DATA E(1493),E(1494),E(1495),E(1496)/'SIS.','COMM','AND ','IGNO'/
      DATA E(1497),E(1498),E(1499),E(1500)/'RED.','CONT','INUI','NG  '/
      DATA E(1501),E(1502),E(1503),E(1504)/'INPR','OPER',' FOR','MAT '/
      DATA E(1505),E(1506),E(1507),E(1508)/'FOR ','JUMP','TO. ','STAT'/
      DATA E(1509),E(1510),E(1511),E(1512)/'EMEN','T IG','NORE','D   '/
      DATA E(1513),E(1514),E(1515),E(1516)/'SYN ','OR R','ESER','V ST'/
      DATA E(1517),E(1518),E(1519),E(1520)/'ATEM','ENT ','HAS ','NO A'/
      DATA E(1521),E(1522),E(1523),E(1524)/'RGUM','ENTS',' OR ','AN O'/
      DATA E(1525),E(1526),E(1527),E(1528)/'DD N','UMBE','R OF',' ARG'/
      DATA E(1529),E(1530),E(1531),E(1532)/'UMEN','TS  ','SYN ','STAT'/
      DATA E(1533),E(1534),E(1535),E(1536)/'EMEN','T HA','S A ','VALU'/
      DATA E(1537),E(1538),E(1539),E(1540)/'E OR',' AN ','ILLE','GAL '/
      DATA E(1541),E(1542),E(1543),E(1544)/'WORD','    ','NO D','RIVE'/
      DATA E(1545),E(1546),E(1547),E(1548)/' SUR','FACE',' FOU','ND P'/
      DATA E(1549),E(1550),E(1551),E(1552)/'RECE','DING',' OTH','ERWI'/
      DATA E(1553),E(1554),E(1555),E(1556)/'SE A','CCEP','TABL','E FO'/
      DATA E(1557),E(1558),E(1559),E(1560)/'RMAT','S. E','NTER','ING '/
      DATA E(1561),E(1562),E(1563),E(1564)/'REST','ART ','ARGU','MENT'/
      DATA E(1565),E(1566),E(1567),E(1568)/' MOD','E IS',' WRO','NG  '/
      DATA E(1569),E(1570),E(1571),E(1572)/'AN A','CCEP','TABL','E CH'/
      DATA E(1573),E(1574),E(1575),E(1576)/'ECK ','SURF','ACE ','IS N'/
      DATA E(1577),E(1578),E(1579),E(1580)/'OT N','AMED','    ','IDEN'/
      DATA E(1581),E(1582),E(1583),E(1584)/'TIFI','ER N','OT P','RECE'/
      DATA E(1585),E(1586),E(1587),E(1588)/'DED ','BY A','CCEP','TABL'/
      DATA E(1589),E(1590),E(1591),E(1592)/'E SU','RFAC','E. E','NTER'/
      DATA E(1593),E(1594),E(1595),E(1596)/'ING ','REST','ART ','THE '/
      DATA E(1597),E(1598),E(1599),E(1600)/'WORD',' INT','OF W','AS N'/
      DATA E(1601),E(1602),E(1603),E(1604)/'OT P','RECE','DED ','BY A'/
      DATA E(1605),E(1606),E(1607),E(1608)/' NUM','BER.','FIRS','T IN'/
      DATA E(1609),E(1610),E(1611),E(1612)/'TERS','ECTI','ON A','SSUM'/
      DATA E(1613),E(1614),E(1615),E(1616)/'ED  ','MACR','O VA','RIAB'/
      DATA E(1617),E(1618),E(1619),E(1620)/'LE N','OT F','UNCT','ION '/
      DATA E(1621),E(1622),E(1623),E(1624)/'TOO ','MANY',' DIM','ENSI'/
      DATA E(1625),E(1626),E(1627),E(1628)/'ONED',' VAR','IABL','ES I'/
      DATA E(1629),E(1630),E(1631),E(1632)/'N PA','RT P','ROGR','AM. '/
      DATA E(1633),E(1634),E(1635),E(1636)/'RANG','E TA','BLE ','FILL'/
      DATA E(1637),E(1638),E(1639),E(1640)/'ED  ','INCO','RREC','T FO'/
      DATA E(1641),E(1642),E(1643),E(1644)/'RMAT',' FOR',' RES','ERV '/
      DATA E(1645),E(1646),E(1647),E(1648)/'STAT','EMEN','T. M','UST '/
      DATA E(1649),E(1650),E(1651),E(1652)/'BE S','YMBO','L,NU','MBER'/
      DATA E(1653),E(1654),E(1655),E(1656)/'    ','NO A','RGUM','ENTS'/
      DATA E(1657),E(1658),E(1659),E(1660)/' DES','IRED','. AR','GUME'/
      DATA E(1661),E(1662),E(1663),E(1664)/'NTS ','IGNO','RED ','ARGU'/
      DATA E(1665),E(1666),E(1667),E(1668)/'MENT',' FOL','LOWI','NG Z'/
      DATA E(1669),E(1670),E(1671),E(1672)/'SURF','/ IS',' NOT',' A P'/
      DATA E(1673),E(1674),E(1675),E(1676)/'LANE','    ','NO A','RGUM'/
      DATA E(1677),E(1678),E(1679),E(1680)/'ENTS',' FOL','LOW ','PRIN'/
      DATA E(1681),E(1682),E(1683),E(1684)/'T/,P','UNCH','/,CF','SAVE'/
      DATA E(1685),E(1686),E(1687),E(1688)/'/,CO','NTRL','/ OR',' PPO'/
      DATA E(1689),E(1690),E(1691),E(1692)/'PTN/','. ST','ATEM','ENT '/
      DATA E(1693),E(1694),E(1695),E(1696)/'IGNO','RED ','INVA','LID '/
      DATA E(1697),E(1698),E(1699),E(1700)/'ARGU','MENT',' FOL','LOWS'/
      DATA E(1701),E(1702),E(1703),E(1704)/' PRI','NT/,',' PUN','CH/ '/
      DATA E(1705),E(1706),E(1707),E(1708)/'OR C','FSAV','E/.A','RGUM'/
      DATA E(1709),E(1710),E(1711),E(1712)/'ENT ','IGNO','RED ','INVA'/
      DATA E(1713),E(1714),E(1715),E(1716)/'LID ','NUMB','ER O','F AR'/
      DATA E(1717),E(1718),E(1719),E(1720)/'GUME','NTS ','IN C','ANON'/
      DATA E(1721),E(1722),E(1723),E(1724)/' DEF','INIT','ION ','INVA'/
      DATA E(1725),E(1726),E(1727),E(1728)/'LID ','ARGU','MENT',' IN '/
      DATA E(1729),E(1730),E(1731),E(1732)/'CANO','N DE','FINI','TION'/
      DATA E(1733),E(1734),E(1735),E(1736)/'    ','INVA','LID ','POCK'/
      DATA E(1737),E(1738),E(1739),E(1740)/'ET F','ORMA','T   ','A SY'/
      DATA E(1741),E(1742),E(1743),E(1744)/'NONY','M AR','GUME','NT P'/
      DATA E(1745),E(1746),E(1747),E(1748)/'AIR ','CONT','AINS',' NO '/
      DATA E(1749),E(1750),E(1751),E(1752)/'VARI','ABLE',' OR ','TWO '/
      DATA E(1753),E(1754),E(1755),E(1756)/'VARI','ABLE','S   ','INPR'/
      DATA E(1757),E(1758),E(1759),E(1760)/'OPER',' ARG','UMEN','T IN'/
      DATA E(1761),E(1762),E(1763),E(1764)/' GOT','O/PA','TERN',' STA'/
      DATA E(1765),E(1766),E(1767),E(1768)/'TEME','NT  ','BOTH',' OMI'/
      DATA E(1769),E(1770),E(1771),E(1772)/'T AN','D RE','TAIN',' SPE'/
      DATA E(1773),E(1774),E(1775),E(1776)/'CIFI','ED I','N GO','TO/P'/
      DATA E(1777),E(1778),E(1779),E(1780)/'ATER','N ST','ATEM','ENT '/
      DATA E(1781),E(1782),E(1783),E(1784)/'TOO ','MANY',' ARG','UMEN'/
      DATA E(1785),E(1786),E(1787),E(1788)/'TS S','PECI','FIED',' IN '/
      DATA E(1789),E(1790),E(1791),E(1792)/'GOTO','/PAT','ERN ','STAT'/
      DATA E(1793),E(1794),E(1795),E(1796)/'EMEN','T. A','RGST','K TA'/
      DATA E(1797),E(1798),E(1799),E(1800)/'BLE ','OVER','FLOW','    '/
      DATA E(1801),E(1802),E(1803),E(1804)/'ILLE','GAL ','ARGU','MENT'/
      DATA E(1805),E(1806),E(1807),E(1808)/' OR ','UNEV','EN N','UMBE'/
      DATA E(1809),E(1810),E(1811),E(1812)/'R OF',' ARG','UMEN','TS I'/
      DATA E(1813),E(1814),E(1815),E(1816)/'N PP','OPTN',' STA','TEME'/
      DATA E(1817),E(1818),E(1819),E(1820)/'NT  ','TOO ','MANY',' ARG'/
      DATA E(1821),E(1822),E(1823),E(1824)/'UMEN','TS I','N IN','CR L'/
      DATA E(1825),E(1826),E(1827),E(1828)/'IST ','INVA','LID ','CONT'/
      DATA E(1829),E(1830),E(1831),E(1832)/'ROL ','STAT','EMEN','T. A'/
      DATA E(1833),E(1834),E(1835),E(1836)/'RGUM','ENT ','IGNO','RED '/
      DATA E(1837),E(1838),E(1839),E(1840)/'DUPL','ICAT','E NA','ME O'/
      DATA E(1841),E(1842),E(1843),E(1844)/'F DI','MENS','IONE','D VA'/
      DATA E(1845),E(1846),E(1847),E(1848)/'RIAB','LES ','RESE','RV I'/
      DATA E(1849),E(1850),E(1851),E(1852)/'NVAL','ID I','N MA','CRO '/
      DATA E(1853),E(1854),E(1855),E(1856)/'PROG','RAM ','CLDA','T SE'/
      DATA E(1857),E(1858),E(1859),E(1860)/'CTIO','N NE','STED',' OR '/
      DATA E(1861),E(1862),E(1863),E(1864)/'STAT','EMEN','T IN',' WRO'/
      DATA E(1865),E(1866),E(1867),E(1868)/'NG S','EQUE','NCE.','    '/
      DATA E(1869),E(1870),E(1871),E(1872)/'INVA','LID ','ARGU','MENT'/
      DATA E(1873),E(1874),E(1875),E(1876)/' IN ','OBTA','IN S','TATE'/
      DATA E(1877),E(1878),E(1879),E(1880)/'MENT','    ','INCO','RREC'/
      DATA E(1881),E(1882),E(1883),E(1884)/'T NU','MBER',' OF ','ARGU'/
      DATA E(1885),E(1886),E(1887),E(1888)/'MENT','S OR',' INV','ALID'/
      DATA E(1889),E(1890),E(1891),E(1892)/' ARG','UMEN','T   ','INVA'/
      DATA E(1893),E(1894),E(1895),E(1896)/'LID ','INCL','USIV',' SUB'/
      DATA E(1897),E(1898),E(1899),E(1900)/'SCRI','PT F','ORMA','T   '/
      DATA E(1901),E(1902),E(1903),E(1904)/'A,B ','AND ','C IN',' INC'/
      DATA E(1905),E(1906),E(1907),E(1908)/'LUSI','VE S','UBSC','RIPT'/
      DATA E(1909),E(1910),E(1911),E(1912)/' FOR','MAT ','MUST',' BE '/
      DATA E(1913),E(1914),E(1915),E(1916)/'EXPL','ICIT',' INT','EGER'/
      DATA E(1917),E(1918),E(1919),E(1920)/'S   ','UNEV','EN N','UMBE'/
      DATA E(1921),E(1922),E(1923),E(1924)/'R OF',' ARG','UMEN','TS  '/
      DATA E(1925),E(1926),E(1927),E(1928)/'INVA','LID ','ARGU','MENT'/
      DATA E(1929),E(1930),E(1931),E(1932)/' SHO','ULD ','BE O','N OR'/
      DATA E(1933),E(1934),E(1935),E(1936)/' OFF','INVA','LID ','ARGU'/
      DATA E(1937),E(1938),E(1939),E(1940)/'MENT',' SHO','ULD ','BE P'/
      DATA E(1941),E(1942),E(1943),E(1944)/'S OR',' A S','SURF',' NAM'/
      DATA E(1945),E(1946),E(1947),E(1948)/'E   ','THER','E IS',' NO '/
      DATA E(1949),E(1950),E(1951),E(1952)/'ASSI','GNME','NT T','O AR'/
      DATA E(1953),E(1954),E(1955),E(1956)/'GUME','NT: ','....','....'/
      DATA E(1957),E(1958),E(1959),E(1960)/' IN ','MACR','O : ','....'/
      DATA E(1961),E(1962),E(1963),E(1964)/'....','SYMB','OLIC',' NAM'/
      DATA E(1965),E(1966),E(1967),E(1968)/'E TA','BLE ','OVER','FLOW'/
      DATA E(1969),E(1970),E(1971),E(1972)/'. SY','MBOL',' IGN','ORED'/
      DATA E(1973),E(1974),E(1975),E(1976)/'    ','TABL','E OV','ERFL'/
      DATA E(1977),E(1978),E(1979),E(1980)/'OW F','OR N','UMER','ICAL'/
      DATA E(1981),E(1982),E(1983),E(1984)/' MAC','RO A','SSIG','NMEN'/
      DATA E(1985)/'TS. '/
      END
