*
*
*  *  BLOCK DATA PROGRAM DEFINING FILE ATTRIBUTES  *
*
*                  NEW VERSION   17.07.85   E.MCLELLAN
*
*---------------------------------------------------
*   VARIABLE        BLOCK     TYPE       DESCRIPTION
*---------------------------------------------------
*
*   FILNAM          FILTAB    CHARACTER  FILE NAME
*   FILACC          FILTAB    CHARACTER  FILE ACCESS
*                                         (DIRECT OR SEQUENTIAL)
*   FILFMT          FILTAB    CHARACTER  FILE FORMAT
*                                         (FORMATTED OR UNFORMATTED)
*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS
*                                         (UNKNOWN,SCRATCH,NEW,OLD)
*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE)
*   U               IFILTB    INTEGER    UNIT NUMBER
*   RL              IFILTB    INTEGER    RECORD LENGTH
*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE
*                                        READ OR WRITTEN (DIRECT ACCESS)
*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE
*                                         (DIRECT ACCESS)
      BLOCK DATA FLTAB
C
      INCLUDE 'FILTAB.INC'
C
      DATA FILNAM(1)/'CLFILP'/,FILACC(1)/'DIRECT '/,
     1     FILFMT(1)/'UNFORMATTED'/,
     2     OPSTAT(1)/'UNKNOWN'/,CLSTAT(1)/'KEEP'/,
     3     U(1)/1/,RL(1)/516/,NXTREC(1)/1/,LSTREC(1)/0/
      DATA FILNAM(2)/'CLFILE'/,FILACC(2)/'DIRECT '/,
     1     FILFMT(2)/'UNFORMATTED'/,
     2     OPSTAT(2)/'UNKNOWN'/,CLSTAT(2)/'KEEP'/,
     3     U(2)/2/,RL(2)/516/,NXTREC(2)/1/,LSTREC(2)/0/
      DATA FILNAM(3)/'CLFIL3'/,FILACC(3)/'SEQUENTIAL'/,
     1     FILFMT(3)/'UNFORMATTED'/,
     2     OPSTAT(3)/'UNKNOWN'/,CLSTAT(3)/'KEEP'/,
     3     U(3)/3/,RL(3)/512/,NXTREC(3)/1/,LSTREC(3)/0/
      DATA FILNAM(4)/'EXFILE'/,FILACC(4)/'DIRECT '/,
     1     FILFMT(4)/'UNFORMATTED'/,
     2     OPSTAT(4)/'SCRATCH'/,CLSTAT(4)/'DELETE'/,
     3     U(4)/4/,RL(4)/516/,NXTREC(4)/1/,LSTREC(4)/0/
      DATA FILNAM(5)/'INFILE'/,FILACC(5)/'SEQUENTIAL'/,
     1     FILFMT(5)/'FORMATTED'/,
     2     OPSTAT(5)/'OLD'/,CLSTAT(5)/'KEEP'/,
     3     U(5)/5/,RL(5)/80/,NXTREC(5)/1/,LSTREC(5)/0/
      DATA FILNAM(6)/'VLFILE'/,FILACC(6)/'SEQUENTIAL'/,
     1     FILFMT(6)/'FORMATTED'/,
     2     OPSTAT(6)/'NEW'/,CLSTAT(6)/'KEEP'/,
     3     U(6)/6/,RL(6)/120/,NXTREC(6)/1/,LSTREC(6)/0/
      DATA FILNAM(7)/'PNCHFL'/,FILACC(7)/'SEQUENTIAL'/,
     1     FILFMT(7)/'FORMATTED'/,
     2     OPSTAT(7)/'NEW'/,CLSTAT(7)/'KEEP'/,
     3     U(7)/7/,RL(7)/80/,NXTREC(7)/1/,LSTREC(7)/0/
      DATA FILNAM(8)/'XCAN'/,FILACC(8)/'DIRECT '/,
     1     FILFMT(8)/'UNFORMATTED'/
     2     OPSTAT(8)/'SCRATCH'/,CLSTAT(8)/'DELETE'/,
     3     U(8)/8/,RL(8)/256/,NXTREC(8)/1/,LSTREC(8)/0/
      DATA FILNAM(9)/'MAXTXT'/,FILACC(9)/'DIRECT '/,
     1     FILFMT(9)/'UNFORMATTED'/,
     2     OPSTAT(9)/'SCRATCH'/,CLSTAT(9)/'DELETE'/,
     3     U(9)/9/,RL(9)/350/,NXTREC(9)/1/,LSTREC(9)/0/
      DATA FILNAM(10)/'XNUM'/,FILACC(10)/'DIRECT '/,
     1     FILFMT(10)/'UNFORMATTED'/,
     2     OPSTAT(10)/'SCRATCH'/,CLSTAT(10)/'DELETE'/,
     3     U(10)/10/,RL(10)/540/,NXTREC(10)/1/,LSTREC(10)/0/
      DATA FILNAM(11)/'ELFIL1'/,FILACC(11)/'DIRECT '/,
     1     FILFMT(11)/'UNFORMATTED'/,
     2     OPSTAT(11)/'SCRATCH'/,CLSTAT(11)/'DELETE'/,
     3     U(11)/11/,RL(11)/256/,NXTREC(11)/1/,LSTREC(11)/0/
      DATA FILNAM(12)/'ELFIL2'/,FILACC(12)/'DIRECT '/,
     1     FILFMT(12)/'UNFORMATTED'/,
     2     OPSTAT(12)/'SCRATCH'/,CLSTAT(12)/'DELETE'/,
     3     U(12)/12/,RL(12)/256/,NXTREC(12)/1/,LSTREC(12)/0/
      DATA FILNAM(13)/'ELFIL3'/,FILACC(13)/'DIRECT '/,
     1     FILFMT(13)/'UNFORMATTED'/,
     2     OPSTAT(13)/'SCRATCH'/,CLSTAT(13)/'DELETE'/,
     3     U(13)/13/,RL(13)/256/,NXTREC(13)/1/,LSTREC(13)/0/
      DATA FILNAM(14)/'ELFIL4'/,FILACC(14)/'SEQUENTIAL'/,
     1     FILFMT(14)/'UNFORMATTED'/,
     2     OPSTAT(14)/'SCRATCH'/,CLSTAT(14)/'DELETE'/,
     3     U(14)/14/,RL(14)/256/,NXTREC(14)/1/,LSTREC(14)/0/
      DATA FILNAM(15)/'CPFILE'/,FILACC(15)/'SEQUENTIAL'/,
     1     FILFMT(15)/'UNFORMATTED'/,
     2     OPSTAT(15)/'UNKNOWN'/,CLSTAT(15)/'DELETE'/,
     3     U(15)/15/,RL(15)/48/,NXTREC(15)/1/,LSTREC(15)/0/
      DATA FILNAM(16)/'AXFILE'/,FILACC(16)/'DIRECT'/,
     1     FILFMT(16)/'UNFORMATTED'/,
     2     OPSTAT(16)/'SCRATCH'/,CLSTAT(16)/'DELETE'/,
     3     U(16)/16/,RL(16)/256/,NXTREC(16)/1/,LSTREC(16)/0/
      DATA FILNAM(17)/'POFILE'/,FILACC(17)/'DIRECT '/,
     1     FILFMT(17)/'UNFORMATTED'/,
     2     OPSTAT(17)/'SCRATCH'/,CLSTAT(17)/'DELETE'/,
     3     U(17)/17/,RL(17)/24/,NXTREC(17)/1/,LSTREC(17)/0/
      DATA FILNAM(18)/'ELFILE'/,FILACC(18)/' '/,
     1     FILFMT(18)/' '/,
     2     OPSTAT(18)/' '/,CLSTAT(18)/' '/,
     3     U(18)/18/,RL(18)/0/,NXTREC(18)/0/,LSTREC(18)/0/
      DATA FILNAM(19)/'LDAFIL'/,FILACC(19)/'SEQUENTIAL'/,
     1     FILFMT(19)/'UNFORMATTED'/,
     2     OPSTAT(19)/'OLD'/,CLSTAT(19)/'KEEP'/,
     3     U(19)/ 8/,RL(19)/80/,NXTREC(19)/1/,LSTREC(19)/0/
      DATA FILNAM(20)/'TIFILE'/,FILACC(20)/'SEQUENTIAL'/,
     1     FILFMT(20)/'FORMATTED'/,
     2     OPSTAT(20)/'UNKNOWN'/,CLSTAT(20)/'KEEP'/,
     3     U(20)/20/,RL(20)/80/,NXTREC(20)/1/,LSTREC(20)/0/
      DATA FILNAM(21)/'PXFILE'/,FILACC(21)/' '/,
     1     FILFMT(21)/' '/,
     2     OPSTAT(21)/' '/,CLSTAT(21)/' '/,
     3     U(21)/0/,RL(21)/0/,NXTREC(21)/0/,LSTREC(21)/0/
      DATA FILNAM(22)/'FILE12'/,FILACC(22)/' '/,
     1     FILFMT(22)/' '/,
     2     OPSTAT(22)/' '/,CLSTAT(22)/' '/,
     3     U(22)/0/,RL(22)/0/,NXTREC(22)/0/,LSTREC(22)/0/
      DATA FILNAM(23)/'FILE13'/,FILACC(23)/' '/,
     1     FILFMT(23)/' '/,
     2     OPSTAT(23)/' '/,CLSTAT(23)/' '/,
     3     U(23)/0/,RL(23)/0/,NXTREC(23)/0/,LSTREC(23)/0/
      DATA FILNAM(24)/'APTLIB'/,FILACC(24)/'SEQUENTIAL'/,
     1     FILFMT(24)/'FORMATTED'/,
     2     OPSTAT(24)/'UNKNOWN'/,CLSTAT(24)/'KEEP'/,
     3     U(24)/24/,RL(24)/80/,NXTREC(24)/0/,LSTREC(24)/0/
      DATA FILNAM(25)/' '/,FILACC(25)/' '/,
     1     FILFMT(25)/' '/,
     2     OPSTAT(25)/' '/,CLSTAT(25)/' '/,
     3     U(25)/0/,RL(25)/0/,NXTREC(25)/0/,LSTREC(25)/0/
      DATA FILNAM(26)/' '/,FILACC(26)/' '/,
     1     FILFMT(26)/' '/,
     2     OPSTAT(26)/' '/,CLSTAT(26)/' '/,
     3     U(26)/0/,RL(26)/0/,NXTREC(26)/0/,LSTREC(26)/0/
      DATA FILNAM(27)/' '/,FILACC(27)/' '/,
     1     FILFMT(27)/' '/,
     2     OPSTAT(27)/' '/,CLSTAT(27)/' '/,
     3     U(27)/0/,RL(27)/0/,NXTREC(27)/0/,LSTREC(27)/0/
      DATA FILNAM(28)/' '/,FILACC(28)/' '/,
     1     FILFMT(28)/' '/,
     2     OPSTAT(28)/' '/,CLSTAT(28)/' '/,
     3     U(28)/0/,RL(28)/0/,NXTREC(28)/0/,LSTREC(28)/0/
      DATA FILNAM(29)/' '/,FILACC(29)/' '/,
     1     FILFMT(29)/' '/,
     2     OPSTAT(29)/' '/,CLSTAT(29)/' '/,
     3     U(29)/0/,RL(29)/0/,NXTREC(29)/0/,LSTREC(29)/0/
      DATA FILNAM(30)/' '/,FILACC(30)/' '/,
     1     FILFMT(30)/' '/,
     2     OPSTAT(30)/' '/,CLSTAT(30)/' '/,
     3     U(30)/0/,RL(30)/0/,NXTREC(30)/0/,LSTREC(30)/0/
C
      END
