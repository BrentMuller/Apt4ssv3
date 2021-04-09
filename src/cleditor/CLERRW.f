**** SOURCE FILE : M0011541.W01   ***
*
C
C...FORTRAN SUBROUTINE CLERRW  (BLOCK DATA)
C
      BLOCK DATA BDCLER
C
      INCLUDE 'CLERR.INC'
C
      INTEGER A,B
      DIMENSION A(34),B(34)
      CHARACTER*4 E(570)
C...CERAD1 : ERROR & WARNING NUMBERS FOR CL EDITOR
C...CERAD2 : POSITION IN ARRAY CERTXT OF END OF ERROR MESSAGE
      EQUIVALENCE (A(1),CERAD1(1))
      EQUIVALENCE (B(1),CERAD2(1))
      EQUIVALENCE (E(1),CERTXT(1))
C
      DATA CERCNT,CERDM     / 570,  34/
C
      DATA A(  1),A(  2),A(  3),A(  4)/  30001,  30002,  30003,  30004/
      DATA A(  5),A(  6),A(  7),A(  8)/  30005,  30006,  30008,  30009/
      DATA A(  9),A( 10),A( 11),A( 12)/  30010,  30011,  30012,  30013/
      DATA A( 13),A( 14),A( 15),A( 16)/  30014,  30015,  30016,  30017/
      DATA A( 17),A( 18),A( 19),A( 20)/  30018,  30019,  30020,  30021/
      DATA A( 21),A( 22),A( 23),A( 24)/  30024,  30025,  30026,  30027/
      DATA A( 25),A( 26),A( 27),A( 28)/  30030,  30031,  30032,  30034/
      DATA A( 29),A( 30),A( 31),A( 32)/  30035,  30036,  30037,  30038/
      DATA A( 33),A( 34)/  30039,  30040/
      DATA B(  1),B(  2),B(  3),B(  4)/      7,     32,     52,     76/
      DATA B(  5),B(  6),B(  7),B(  8)/     94,    110,    126,    141/
      DATA B(  9),B( 10),B( 11),B( 12)/    153,    171,    189,    199/
      DATA B( 13),B( 14),B( 15),B( 16)/    206,    219,    232,    246/
      DATA B( 17),B( 18),B( 19),B( 20)/    272,    279,    287,    294/
      DATA B( 21),B( 22),B( 23),B( 24)/    314,    324,    345,    369/
      DATA B( 25),B( 26),B( 27),B( 28)/    379,    400,    410,    434/
      DATA B( 29),B( 30),B( 31),B( 32)/    461,    487,    514,    521/
      DATA B( 33),B( 34)/    553,    570/
      DATA E(   1),E(   2),E(   3),E(   4)/'INVA','LID ','VTLA','XS S'/
      DATA E(   5),E(   6),E(   7),E(   8)/'TATE','MENT','.   ','A VT'/
      DATA E(   9),E(  10),E(  11),E(  12)/'LAXS','/OFF',' COM','MAND'/
      DATA E(  13),E(  14),E(  15),E(  16)/' WAS',' GIV','EN W','ITHO'/
      DATA E(  17),E(  18),E(  19),E(  20)/'UT A',' VTL','AXS/','ON C'/
      DATA E(  21),E(  22),E(  23),E(  24)/'OMMA','ND O','R  A',' PRE'/
      DATA E(  25),E(  26),E(  27),E(  28)/'VIOU','S VT','LAXS',' ERR'/
      DATA E(  29),E(  30),E(  31),E(  32)/'OR O','CCUR','RED.','    '/
      DATA E(  33),E(  34),E(  35),E(  36)/'TWO ','VTLA','XS/O','N CO'/
      DATA E(  37),E(  38),E(  39),E(  40)/'MMAN','DS W','ERE ','GIVE'/
      DATA E(  41),E(  42),E(  43),E(  44)/'N WI','THOU','T A ','VTLA'/
      DATA E(  45),E(  46),E(  47),E(  48)/'XS/O','FF C','OMMA','ND B'/
      DATA E(  49),E(  50),E(  51),E(  52)/'ETWE','EN T','HEM.','    '/
      DATA E(  53),E(  54),E(  55),E(  56)/'A FR','OM C','OMMA','ND W'/
      DATA E(  57),E(  58),E(  59),E(  60)/'AS G','IVEN',' BET','WEEN'/
      DATA E(  61),E(  62),E(  63),E(  64)/' A V','TLAX','S/ON',' COM'/
      DATA E(  65),E(  66),E(  67),E(  68)/'MAND',' AND',' ITS','  CO'/
      DATA E(  69),E(  70),E(  71),E(  72)/'RRES','POND','ING ','VTLA'/
      DATA E(  73),E(  74),E(  75),E(  76)/'XS/O','FF C','OMMA','ND. '/
      DATA E(  77),E(  78),E(  79),E(  80)/'A VT','LAXS',' COM','MAND'/
      DATA E(  81),E(  82),E(  83),E(  84)/' WAS',' GIV','EN W','ITHO'/
      DATA E(  85),E(  86),E(  87),E(  88)/'UT A',' PRE','VIOU','S MO'/
      DATA E(  89),E(  90),E(  91),E(  92)/'TION',' OR ','FROM','  CO'/
      DATA E(  93),E(  94),E(  95),E(  96)/'MMAN','D.  ','A VT','LAXS'/
      DATA E(  97),E(  98),E(  99),E( 100)/' COM','MAND',' WAS',' GIV'/
      DATA E( 101),E( 102),E( 103),E( 104)/'EN W','ITHO','UT A',' PRE'/
      DATA E( 105),E( 106),E( 107),E( 108)/'VIOU','S MU','LTAX',' COM'/
      DATA E( 109),E( 110),E( 111),E( 112)/'MAND','.   ','VTLA','XS E'/
      DATA E( 113),E( 114),E( 115),E( 116)/'RROR','. CO','RNER',' RAD'/
      DATA E( 117),E( 118),E( 119),E( 120)/'IUS ','IS G','REAT','ER T'/
      DATA E( 121),E( 122),E( 123),E( 124)/'HAN ','THE ','CUTT','ER R'/
      DATA E( 125),E( 126),E( 127),E( 128)/'ADIU','S.  ','VTLA','XS E'/
      DATA E( 129),E( 130),E( 131),E( 132)/'RROR','. CO','RNER',' RAD'/
      DATA E( 133),E( 134),E( 135),E( 136)/'IUS ','MUST',' BE ','ZERO'/
      DATA E( 137),E( 138),E( 139),E( 140)/' WHE','N US','ING ','ZSMA'/
      DATA E( 141),E( 142),E( 143),E( 144)/'LL. ','NO M','OTIO','N BE'/
      DATA E( 145),E( 146),E( 147),E( 148)/'TWEE','N A ','VTLA','XS/O'/
      DATA E( 149),E( 150),E( 151),E( 152)/'N AN','D A ','VTLA','XS/O'/
      DATA E( 153),E( 154),E( 155),E( 156)/'FF. ','TRAC','UT W','AS G'/
      DATA E( 157),E( 158),E( 159),E( 160)/'IVEN',' BET','WEEN',' A V'/
      DATA E( 161),E( 162),E( 163),E( 164)/'TLAX','S/ON',' AND',' ITS'/
      DATA E( 165),E( 166),E( 167),E( 168)/' COR','RESP','ONDI','NG  '/
      DATA E( 169),E( 170),E( 171),E( 172)/'VTLA','XS/O','FF. ','COPY'/
      DATA E( 173),E( 174),E( 175),E( 176)/' WAS',' GIV','EN B','ETWE'/
      DATA E( 177),E( 178),E( 179),E( 180)/'EN A',' VTL','AXS/','ON A'/
      DATA E( 181),E( 182),E( 183),E( 184)/'ND I','TS C','ORRE','SPON'/
      DATA E( 185),E( 186),E( 187),E( 188)/'DING','  VT','LAXS','/OFF'/
      DATA E( 189),E( 190),E( 191),E( 192)/'.   ','INCO','RREC','T MO'/
      DATA E( 193),E( 194),E( 195),E( 196)/'DIFI','ER I','N A ','COPY'/
      DATA E( 197),E( 198),E( 199),E( 200)/' COM','MAND','.   ','INDE'/
      DATA E( 201),E( 202),E( 203),E( 204)/'X NU','MBER',' NOT',' DEF'/
      DATA E( 205),E( 206),E( 207),E( 208)/'INED','.   ','INCO','RREC'/
      DATA E( 209),E( 210),E( 211),E( 212)/'T NU','MBER',' OF ','PARA'/
      DATA E( 213),E( 214),E( 215),E( 216)/'METE','RS I','N TH','E CO'/
      DATA E( 217),E( 218),E( 219),E( 220)/'PY C','OMMA','ND. ','THE '/
      DATA E( 221),E( 222),E( 223),E(224)/'PARA','METE','R ''N',''' IN'/
      DATA E( 225),E( 226),E( 227),E( 228)/' THE',' COP','Y IS',' ZER'/
      DATA E( 229),E( 230),E( 231),E( 232)/'O OR',' NEG','ATIV','E.  '/
      DATA E( 233),E( 234),E( 235),E( 236)/'MIRR','OR, ','MIRR','OR O'/
      DATA E( 237),E( 238),E( 239),E( 240)/'N TH','E WA','LL, ','YOU '/
      DATA E( 241),E( 242),E( 243),E( 244)/'ARE ','NOT ','ALLO','WED '/
      DATA E( 245),E( 246),E( 247),E( 248)/'AT A','LL. ','COPY',' LOG'/
      DATA E( 249),E( 250),E( 251),E( 252)/'IC E','RROR','. CH','ECK '/
      DATA E( 253),E( 254),E( 255),E( 256)/'PART',' PRO','GRAM',' FOR'/
      DATA E( 257),E( 258),E( 259),E( 260)/' OVE','RLAP','PING',' COP'/
      DATA E( 261),E( 262),E( 263),E( 264)/'Y AR','EAS ',' OR ','AN I'/
      DATA E( 265),E( 266),E( 267),E( 268)/'LLEG','AL T','RANS','FER '/
      DATA E( 269),E( 270),E( 271),E( 272)/'INTO',' COP','Y LO','OP. '/
      DATA E( 273),E( 274),E( 275),E( 276)/'COPY',' IS ','OVER',' 3 N'/
      DATA E( 277),E( 278),E( 279),E( 280)/'EST ','LEVE','LS. ','INDE'/
      DATA E( 281),E( 282),E( 283),E( 284)/'X NU','MBER',' PRE','VIOU'/
      DATA E( 285),E( 286),E( 287),E( 288)/'SLY ','USED','.   ','TOO '/
      DATA E( 289),E( 290),E( 291),E( 292)/'MANY',' IND','EX/N',' COM'/
      DATA E( 293),E( 294),E( 295),E( 296)/'MAND','S.  ','SYST','EM F'/
      DATA E( 297),E( 298),E( 299),E( 300)/'AILU','RE. ','POSI','TION'/
      DATA E( 301),E( 302),E( 303),E( 304)/'ING ','ERRO','R IN',' COP'/
      DATA E( 305),E( 306),E( 307),E( 308)/'Y LO','GIC.','  CH','ECK '/
      DATA E( 309),E( 310),E( 311),E( 312)/'COMP','UTER',' PRO','GRAM'/
      DATA E( 313),E( 314),E( 315),E( 316)/'MER.','    ','BAD ','PARA'/
      DATA E( 317),E( 318),E( 319),E( 320)/'METE','R IN',' THI','S CL'/
      DATA E( 321),E( 322),E( 323),E( 324)/'DAT ','STAT','EMEN','T.  '/
      DATA E( 325),E( 326),E( 327),E( 328)/'THE ','FIRS','T RE','CORD'/
      DATA E( 329),E( 330),E( 331),E( 332)/' NUM','BER ','GIVE','N IN'/
      DATA E( 333),E( 334),E( 335),E( 336)/' THE',' CLD','AT S','TATE'/
      DATA E( 337),E( 338),E( 339),E( 340)/'MENT',' WAS',' NOT','  FO'/
      DATA E( 341),E( 342),E( 343),E( 344)/'UND ','IN O','LD C','LFIL'/
      DATA E( 345),E( 346),E( 347),E( 348)/'E.  ','EXFI','LE F','ORMA'/
      DATA E( 349),E( 350),E( 351),E( 352)/'T ER','ROR.',' UNR','ECOG'/
      DATA E( 353),E( 354),E( 355),E( 356)/'NIZA','BLE ','COMM','AND.'/
      DATA E( 357),E( 358),E( 359),E( 360)/' FRA','ME S','IZE ','IS  '/
      DATA E( 361),E( 362),E( 363),E( 364)/'LESS',' THA','N ZE','RO I'/
      DATA E( 365),E( 366),E( 367),E( 368)/'N WI','DTH ','OR L','ENGT'/
      DATA E( 369),E( 370),E( 371),E( 372)/'H.  ','UNID','ENTI','FIED'/
      DATA E( 373),E( 374),E( 375),E( 376)/' POS','T PR','OCES','SOR '/
      DATA E( 377),E( 378),E( 379),E( 380)/'COMM','AND.','    ','THE '/
      DATA E( 381),E( 382),E( 383),E( 384)/'LAST',' REC','ORD ','NUMB'/
      DATA E( 385),E( 386),E( 387),E( 388)/'ER G','IVEN',' IN ','THE '/
      DATA E( 389),E( 390),E( 391),E( 392)/'CLDA','T ST','ATEM','ENT '/
      DATA E( 393),E( 394),E( 395),E( 396)/'WAS ','NOT ',' FOU','ND I'/
      DATA E( 397),E( 398),E( 399),E( 400)/'N OL','D CL','FILE','.   '/
      DATA E( 401),E( 402),E( 403),E( 404)/'INVA','LID ','CLFI','LE R'/
      DATA E( 405),E( 406),E( 407),E( 408)/'ECOR','D. R','UN T','ERMI'/
      DATA E( 409),E( 410),E( 411),E( 412)/'NATE','D.  ','NO C','OPY '/
      DATA E( 413),E( 414),E( 415),E( 416)/'TRAN','SFOR','MATI','ON H'/
      DATA E( 417),E( 418),E( 419),E( 420)/'AS B','EEN ','PERF','ORME'/
      DATA E( 421),E( 422),E( 423),E( 424)/'D BE','CAUS','E AN',' ERR'/
      DATA E( 425),E( 426),E( 427),E( 428)/'OR  ','HAS ','OCCU','RED '/
      DATA E( 429),E( 430),E( 431),E( 432)/'INSI','DE T','HE C','OPY '/
      DATA E( 433),E( 434),E( 435),E( 436)/'LOOP','.   ','THE ','LIMI'/
      DATA E( 437),E( 438),E( 439),E( 440)/'T ON',' THE',' NUM','BER '/
      DATA E( 441),E( 442),E( 443),E( 444)/'OF L','ENGT','H OF',' POS'/
      DATA E( 445),E( 446),E( 447),E( 448)/'TPRO','CESS','OR T','YPE '/
      DATA E( 449),E( 450),E( 451),E( 452)/' COM','MAND','S AF','TER '/
      DATA E( 453),E( 454),E( 455),E( 456)/'A HO','LDPP',' COM','MAND'/
      DATA E( 457),E( 458),E( 459),E( 460)/' HAS',' BEE','N EX','CEED'/
      DATA E( 461),E( 462),E( 463),E( 464)/'ED. ','THE ','FOLL','OWIN'/
      DATA E( 465),E( 466),E( 467),E( 468)/'G VT','LAXS',' SEQ','UENC'/
      DATA E( 469),E( 470),E( 471),E( 472)/'E HA','S NO','T BE','EN P'/
      DATA E( 473),E( 474),E( 475),E( 476)/'ROCE','SSED',' BEC','AUSE'/
      DATA E( 477),E( 478),E( 479),E( 480)/'  AN',' ARE','LEM ','ERRO'/
      DATA E( 481),E( 482),E( 483),E( 484)/'R HA','S OC','CURR','ED W'/
      DATA E( 485),E( 486),E( 487),E( 488)/'ITHI','N IT','.   ','AN A'/
      DATA E( 489),E( 490),E( 491),E( 492)/'RELE','M RE','STAR','T ER'/
      DATA E( 493),E( 494),E( 495),E( 496)/'ROR ','HAS ','CAUS','ED C'/
      DATA E( 497),E( 498),E( 499),E( 500)/'L PR','INTO','UT S','TART'/
      DATA E( 501),E( 502),E( 503),E( 504)/'ING ','AT T','HE  ','CL P'/
      DATA E( 505),E( 506),E( 507),E( 508)/'OINT',' PRE','CEDI','NG T'/
      DATA E( 509),E( 510),E( 511),E( 512)/'HE E','RROR',' INF','ORMA'/
      DATA E( 513),E( 514),E( 515),E( 516)/'TION','.   ','ERRO','NEOU'/
      DATA E( 517),E( 518),E( 519),E( 520)/'S UN','ITS ','COMM','AND.'/
      DATA E( 521),E( 522),E( 523),E( 524)/'    ','TOO ','EXTE','NSIV'/
      DATA E( 525),E( 526),E( 527),E( 528)/'E CO','PY C','OMMA','NDS,'/
      DATA E( 529),E( 530),E( 531),E( 532)/' COM','MON ','NCFS','TO T'/
      DATA E( 533),E( 534),E( 535),E( 536)/'OO S','MALL',': SU','BDIV'/
      DATA E( 537),E( 538),E( 539),E( 540)/'IDE ',' COP','Y-SE','QUEN'/
      DATA E( 541),E( 542),E( 543),E( 544)/'CE, ','OR I','NCRE','ASE '/
      DATA E( 545),E( 546),E( 547),E( 548)/'NCFS','TO-S','TORA','GE ('/
      DATA E( 549),E( 550),E( 551),E( 552)/'SYST','EM P','ROGR','AMME'/
      DATA E( 553),E( 554),E( 555),E( 556)/'R). ','COPY',' OR ','TRAC'/
      DATA E( 557),E( 558),E( 559),E( 560)/'UT P','ROCE','SSIN','G FO'/
      DATA E( 561),E( 562),E( 563),E( 564)/'R EX','TEND','ED C','LDAT'/
      DATA E( 565),E( 566),E( 567),E( 568)/'A FO','RMAT','S NO','T MO'/
      DATA E( 569),E( 570)/'UNTE','D.  '/
C
      END
