C     -------------------
      DIMENSION   NB(COMSIZ),   FP(COMSIZ),   CF(COMSIZ),   IA(COMSIZ),
     X          CM(2,COMSIZ), NT(2,COMSIZ), MT(COMSIZ*2), PP(COMSIZ*2)
      DOUBLE PRECISION  NB,        FP,        CF,     IA
      INTEGER           CM,        NT,        MT,     PP
      EQUIVALENCE      (COM(1),    NB(1),    FP(1),  CF(1),  IA(1),
     X                  CM(1,1),   NT(1,1),  MT(1),  PP(1))
C
