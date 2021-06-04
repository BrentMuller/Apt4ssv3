/* FLTAB.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct filtab_1_ {
    char filnam[480], filacc[300], filfmt[330], opstat[210], clstat[180];
};

#define filtab_1 (*(struct filtab_1_ *) &filtab_)

struct ifiltb_1_ {
    integer u[30], rl[30], nxtrec[30], lstrec[30];
};

#define ifiltb_1 (*(struct ifiltb_1_ *) &ifiltb_)

/* Initialized data */

struct {
    char e_1[1500];
    } filtab_ = { "CLFILP          CLFILE          CLFIL3          EXFILE   "
	    "       INFILE          VLFILE          PNCHFL          XCAN     "
	    "       MAXTXT          XNUM            ELFIL1          ELFIL2   "
	    "       ELFIL3          ELFIL4          CPFILE          AXFILE   "
	    "       POFILE          ELFILE          LDAFIL          TIFILE   "
	    "       PXFILE          FILE12          FILE13          APTLIB   "
	    "                                                                "
	    "                                       DIRECT    DIRECT    SEQUE"
	    "NTIALDIRECT    SEQUENTIALSEQUENTIALSEQUENTIALDIRECT    DIRECT   "
	    " DIRECT    DIRECT    DIRECT    DIRECT    SEQUENTIALSEQUENTIALDIR"
	    "ECT    DIRECT              SEQUENTIALSEQUENTIAL                 "
	    "             SEQUENTIAL                                         "
	    "                   UNFORMATTEDUNFORMATTEDUNFORMATTEDUNFORMATTEDF"
	    "ORMATTED  FORMATTED  FORMATTED  UNFORMATTEDUNFORMATTEDUNFORMATTE"
	    "DUNFORMATTEDUNFORMATTEDUNFORMATTEDUNFORMATTEDUNFORMATTEDUNFORMAT"
	    "TEDUNFORMATTED           UNFORMATTEDFORMATTED                   "
	    "                FORMATTED                                       "
	    "                             UNKNOWNUNKNOWNUNKNOWNSCRATCHOLD    "
	    "NEW    NEW    scratchscratchSCRATCHreplacereplacereplacereplaceU"
	    "NKNOWNSCRATCHreplace       OLD    UNKNOWN                     UN"
	    "KNOWN                                          KEEP  KEEP  KEEP "
	    " DELETEKEEP  KEEP  KEEP  keep  keep  DELETEkeep  keep  keep  kee"
	    "p  DELETEDELETEkeep        KEEP  KEEP                    KEEP   "
	    "                                   " };

struct {
    integer e_1[120];
    } ifiltb_ = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
	    18, 8, 20, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 2064, 2064, 2064, 2064, 
	    320, 480, 320, 1024, 1400, 2160, 1024, 1024, 1024, 114096, 1148, 
	    32768, 96, 0, 320, 320, 0, 0, 0, 320, 0, 0, 0, 0, 0, 0, 1, 1, 1, 
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


/* *** SOURCE FILE : FLTAB000.W01   *** */


/*  *  BLOCK DATA PROGRAM DEFINING FILE ATTRIBUTES  * */

/*                  NEW VERSION   17.07.85   E.MCLELLAN */

/* --------------------------------------------------- */
/*   VARIABLE        BLOCK     TYPE       DESCRIPTION */
/* --------------------------------------------------- */

/*   FILNAM          FILTAB    CHARACTER  FILE NAME */
/*   FILACC          FILTAB    CHARACTER  FILE ACCESS */
/*                                         (DIRECT OR SEQUENTIAL) */
/*   FILFMT          FILTAB    CHARACTER  FILE FORMAT */
/*                                         (FORMATTED OR UNFORMATTED) */
/*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS */
/*                                         (UNKNOWN,SCRATCH,NEW,OLD) */
/*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE) */
/*   U               IFILTB    INTEGER    UNIT NUMBER */
/*   RL              IFILTB    INTEGER    RECORD LENGTH */
/*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE */
/*                                        READ OR WRITTEN (DIRECT ACCESS) */
/*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE */
/*                                         (DIRECT ACCESS) */
/* Subroutine */ int fltab_(void)
{
    return 0;
} /* fltab_ */



/*     F77 forbids opening 'scratch' as a named file */
/*     some record lengths were 4 times too small due */
/*     to byte vs integer record lengths */

/*  *  FILE ATTRIBUTES  * */






/*     3     U(1)/1/,RL(1)/516/,NXTREC(1)/1/,LSTREC(1)/0/ */
/*     3     U(2)/2/,RL(2)/516/,NXTREC(2)/1/,LSTREC(2)/0/ */
/*     3     U(3)/3/,RL(3)/512/,NXTREC(3)/1/,LSTREC(3)/0/ */
/*     2     opstat(4)/'scratch'/,clstat(4)/'keep'/, */
/*     2     opstat(4)/'replace'/,clstat(4)/'delete'/, */
/*     3     U(4)/4/,RL(4)/516/,NXTREC(4)/1/,LSTREC(4)/0/ */
/*     3     U(5)/5/,RL(5)/80/,NXTREC(5)/1/,LSTREC(5)/0/ */
/*     3     U(6)/6/,RL(6)/120/,NXTREC(6)/1/,LSTREC(6)/0/ */
/*     3     U(7)/7/,RL(7)/80/,NXTREC(7)/1/,LSTREC(7)/0/ */
/*     2     OPSTAT(8)/'SCRATCH'/,CLSTAT(8)/'DELETE'/, */
/*     2     opstat(8)/'replace'/,clstat(8)/'delete'/, */
/*     3     U(8)/8/,RL(8)/256/,NXTREC(8)/1/,LSTREC(8)/0/ */
/*     2     OPSTAT(9)/'SCRATCH'/,CLSTAT(9)/'DELETE'/, */
/*     2     opstat(9)/'replace'/,clstat(9)/'delete'/, */
/*     3     U(9)/9/,RL(9)/350/,NXTREC(9)/1/,LSTREC(9)/0/ */
/*     2     opstat(10)/'scratch'/,clstat(10)/'keep'/, */
/*     2     opstat(10)/'replace'/,clstat(10)/'delete'/, */
/*     3     U(10)/10/,RL(10)/540/,NXTREC(10)/1/,LSTREC(10)/0/ */
/*     2     OPSTAT(11)/'SCRATCH'/,CLSTAT(11)/'DELETE'/, */
/*     2     opstat(11)/'replace'/,clstat(11)/'delete'/, */
/*     2     opstat(11)/'new'/,clstat(11)/'keep'/, */
/*     3     U(11)/11/,RL(11)/256/,NXTREC(11)/1/,LSTREC(11)/0/ */
/*     2     OPSTAT(12)/'SCRATCH'/,CLSTAT(12)/'DELETE'/, */
/*     2     opstat(12)/'replace'/,clstat(12)/'delete'/, */
/*     2     opstat(12)/'new'/,clstat(12)/'keep'/, */
/*     3     U(12)/12/,RL(12)/256/,NXTREC(12)/1/,LSTREC(12)/0/ */
/*     2     OPSTAT(13)/'SCRATCH'/,CLSTAT(13)/'DELETE'/, */
/*     3     U(13)/13/,RL(13)/256/,NXTREC(13)/1/,LSTREC(13)/0/ */
/*     2     OPSTAT(14)/'SCRATCH'/,CLSTAT(14)/'DELETE'/, */
/*     2     opstat(14)/'replace'/,clstat(14)/'delete'/, */
/*     3     U(14)/14/,RL(14)/256/,NXTREC(14)/1/,LSTREC(14)/0/ */
/*     2     opstat(15)/'unknown'/,clstat(15)/'keep'/, */
/*     3     U(15)/15/,RL(15)/48/,NXTREC(15)/1/,LSTREC(15)/0/ */
/*     2     opstat(16)/'replace'/,clstat(16)/'delete'/, */
/*     2     opstat(16)/'replace'/,clstat(16)/'keep'/, */
/*     3     U(16)/16/,RL(16)/256/,NXTREC(16)/1/,LSTREC(16)/0/ */
/*     3     u(16)/16/,rl(16)/1024/,nxtrec(16)/1/,lstrec(16)/0/ */
/*     3     u(16)/16/,rl(16)/4096/,nxtrec(16)/1/,lstrec(16)/0/ */
/*     3     u(16)/16/,rl(16)/8192/,nxtrec(16)/1/,lstrec(16)/0/ */
/*     3     u(16)/16/,rl(16)/16384/,nxtrec(16)/1/,lstrec(16)/0/ */
/*     2     OPSTAT(17)/'SCRATCH'/,CLSTAT(17)/'DELETE'/, */
/*     2     opstat(17)/'replace'/,clstat(17)/'delete'/, */
/*     3     U(17)/17/,RL(17)/24/,NXTREC(17)/1/,LSTREC(17)/0/ */
/*     3     U(19)/ 8/,RL(19)/80/,NXTREC(19)/1/,LSTREC(19)/0/ */
/*     3     U(20)/20/,RL(20)/80/,NXTREC(20)/1/,LSTREC(20)/0/ */
/*     3     U(24)/24/,RL(24)/80/,NXTREC(24)/0/,LSTREC(24)/0/ */


