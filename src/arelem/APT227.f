**** SOURCE FILE : M0000702.W03   ***
*
C
C.....FORTRAN BLOCK DATA ROUTINE  ...APT227      2/69   RC,HG,RN,AR
C
C
C
C...  THIS ROUTINE CONTAINS A LISTING OF ALL CDE PACKAGES
C...      IN THE EXECUTION COMPLEX EXCEPT:
C...  BLOCKS 4., 5., AND 17. ARE LISTED IN APT228
C...  BLOCKS 6.,16., AND 18. ARE LISTED IN APT229
C...  NOTE.APT228 AND APT229 ARE DUMMY ROUTINES AND
C...  SHOULD NOT BE LINK EDITED
C
      BLOCK DATA BDA227
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      COMMON /APT227/ APT227
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'HOLRTH.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IBRKPT.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C...  21. ADDCOM BLOCK
C
      COMMON/ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM( 1),ELMAX ),  (ADDCOM( 2),CLNGTH),
     1            (ADDCOM(23),IBTFLG),  (ADDCOM(24),JLIN),
     2            (ADDCOM(25),KDYNFL)
C
C...  22. TRACE BLOCK
      COMMON /TRACFL/TRACFL
      LOGICAL TRACFL
C
C...  23. DSNAME BLOCK
C
      COMMON /DSNAME/DSNAME,NAMSUB
C
C
C     24.   SRFNAM BLOCK
      COMMON /SRFNAM/ PSNAME,CS1NAM,CS2NAM,IPSSUB,ICS1SB,ICS2SB
C
C
C     25.   COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/  IAERFG,NPCTPT,PCTPTS,PCTPLN,ERRPTS
      DIMENSION  PCTPTS(3,20), PCTPLN(4), ERRPTS(3,3)
C
C
C          29.  COMMON FOR HOLD INFORMATION
C
      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100)
C
      INCLUDE 'DARRAY.INC'
      INCLUDE 'XUNITS.INC'
C*****   DATA FOR DEF BLOCK   ****************************************
C
C
      DATA  A/24*0./, AHOLD/8*0./, C1/70000.D0,7*0./,
C
     1      LN1/40000.D0,4*0./, R/5*0.,1.D0,4*0./, REF/8*0./
C
C
C*****   DATA FOR FXCOR BLOCK *******************************
C
C** B FXCOR. ARELEM REAL ENVIROMENTAL VARIABLES.
C     EVERY VARIABLE IN THIS BLOCK MUST RETAIN A MINIMUM OF
C     7 DECIMAL FIGURES OF RELATIVE SIGNIFICANCE.
C
      DATA AX4/ 3*0./, CAGL/0./, CUTDAT/7*0./, GAMMA/0./,
C
     +    HI/0./, PMOVE/3*0./, RA/0./, RC1/4500.D0/,
C
     +    SAGL/0./, SURD/0./,  TA/0.,0.,1.D0/, TAK/3*0./,
C
     +    TE/3*0./, TEK/3*0/, TEL/3*0./, TEM/10*0./,
C
     +    TEMP/24*0./, TI/3*0./, TIK/3*0./, TIL/3*0./,
C
     +    TM/3*0./, VTEM/0./, ALP/0./, TAL/3*0./,
C
     +    DPMAX/10./, STRTNO/0./, MODFER/'BLANK'/, TLHIT/5./
C        TOOL HT. ALWAYS 5 INCH.
C
C  ***** DATA FOR NEW TLLDAT BLOCK ************
C
      DATA TLHITE/8*0./, SINL/6*0.,2*-1.D38/, COSL/6*0.,2*1.D38/,
C
     +     UMAX/8*0./, RI/8*0./, CORRAD/8*0./,
C
     +     TCONT/6*0.,-1.,1.,-1./, TLINC/9*0./
C
C
C  ***** DATA FOR HOLRTH BLOCK ************************
C
      DATA HPS/'PS    '/, HDS/'DS    '/, HCS/'CS    '/, HLFT/'GOLFT '/,
C
     +     HRGT/'GORGT '/, HFWD/'GOFWD '/, HBACK/'GOBACK'/,
C
     +     HUP/'GOUP  '/, HDOWN/'GODOWN'/, HTO/'TO    '/,
C
     +     HPAST/'PAST  '/, HON/'ON    '/, HTANTO/'TANTO '/,
C
     +     HPSTAN/'PSTAN '/, HDYNP/'DYNDMP'/, HAERR/'AERR  '/,
C
     +     HCLDAT/'CLDATA'/, HGERR/'GERR  '/
C
C *****  DATA FOR SV BLOCK *********************************
C
C      EVERY VARIABLE IN THIS BLOCK MUST RETAIN A MINIMUM OF
C      7 DECIMAL FIGURES OF RELATIVE SIGNIFICANCE.
C
C      FOR ONE DIMENSIONAL ARRAYS - INDEX INDICATES SURFACE
C      FOR TWO DIMENSIONAL ARRAYS - 1ST INDEX INDICATES VECTOR COMPONENT
C                                   2ND INDES INDICATES SURFACE
C      ***** SURFACE *** INDEX *****
C             GOUGE        1
C             PART         2
C             DRIVE        3
C             CHECK1       4
C             CHECK2       5
C
      DATA  CC/15*0./
      DATA  EPS1/0.,4*.00005D0/,  EPS2/0.,4*.99995D0/,
     +      EPS3/0.,4*.0001D0/,   EPS4/0.,4*.001D0/,
     +      EPS6/0.,4*1.D-6/,     EPS8/0.,4*.00005D0/
      DATA  PAST/5*0./,       PLND/5*0./,  PLNV/15*0./
      DATA  RC/0.,4*4500.D0/,    S/5*0./,   SAVE/5*0./
      DATA  SFVCT/15*0./,  SLX/15*0./,   SN/15*0./,  SNK/15*0./,
     +        SNL/15*0./,   SP/15*0./,  SPK/15*0./,  SPL/15*0./
      DATA  TAU/0.,4*.0005D0/,  TAU1/0.,4*.0005D0/,  TAU2/5*0./
      DATA  TH/5*0./
C
      DATA  TN/3*0., 0.,0.,-1, 1.,0.,0., 1.,0.,0., 0.,0.,-1./
      DATA  TOOLHT/15*0./, TOOLWD/5*0./
      DATA  TP/15*0./, TPK/15*0./,  U1/15*0./, VNDIR/15*0./,
     +      VT/15*0./, Z/5*0./, VARBLE/5*0./, U1K/15*0./, SK/15*0./
      DATA    COS1/5*0./, CPLFL/5*0./, CPTST/5*0./,   CSD/5*0./,
     +      DPLAN/15*0./, DPMX1/5*0./, PLNCS/5*0./, PLND1/5*0./,
     +       PLTST/5*0./,  STCK/5*0./, STCKN/5*0./, STCK1/5*0./,
     +       STCK2/5*0./,  TEE/15*0./,  TNL/15*0./
C
C
C
C  ***** DATA FOR ZNUMBR BLOCK ************************
C
      DATA    Z0/    0./,     Z1/  1.D0/,    Z2/  2.D0/,   Z3/   3.D0/,
     1        Z5/  5.D0/,    Z10/ 10.D0/,   Z90/ 90.D0/,  Z1E6/  1.D6/,
     2     Z1E38/ 1.D19/,  Z5EM1/  .5D0/, Z6EM1/  .6D0/, Z9EM1/  .9D0/,
     3    Z11EM1/ 1.1D0/, Z12EM1/ 1.2D0/, Z1EM2/ .01D0/, Z1EM3/.001D0/,
     4     Z1EM5/ 1.D-5/,  Z5EM6/ 5.D-6/, Z1EM6/ 1.D-6/, Z1EM7/ 1.D-7/,
     5     Z1EM9/ 1.D-9/,  Z1EM1/  .1D0/,   ZM1/ -1.D0/,
     6    DEGRAD/  .0174532925D0/,   PI/  3.14159265D0/
C
C
C  ***** DATA FOR LDEF BLOCK **************************
C
      DATA     JCS/.FALSE./,  PRNTON/.FALSE./,  REFFLG/.FALSE./,
     +      SUBFLG/.FALSE./,  UNFLAG/.FALSE./,    ZFLAG/.TRUE./,
     +         JDS/.FALSE./,  BOUNDF/.FALSE./,  PCHLST/.FALSE./,
     +      CANFLG/.FALSE./,  BNDERR/.FALSE./,  TABPRT/.FALSE./,
     +      REFMOT/.FALSE./,  ALTMLT/.FALSE./
C
C
C  ***** DATA FOR ISV BLOCK ***************************
C
      DATA  IAFL/0,4*-1/,  ICANON/5*0/, INDEX/5*0/,  INDIR/5*0/,
     +      IOP/5*0/,      IOPSET/5*0/, IPL/5*0/,    ISFIDN/5*0/,
     +      ISFTYP/5*0/,   ISIGCR/5*0/, ISVFL/5*0/,  ITLON/5*0/,
     +      ITSEG/5*0/,    IUNFL/5*0/,  JENT/0,4*1/, JIOPS/5*0/,
     +      JTLFLG/5*0/,   JTN/5*0/,    JU1/5*0/,    LIMFL/5*0/,
     +      ITSEGK/5*0/
      DATA  IFAR/3*0,2*1/, IFL4/5*0/,   J20/5*0/,    J21/5*0/,
     +      J22/5*0/,      J23/5*0/,    J50/5*0/,    J51/5*0/,
     +      NOTAN/5*0/,    JPH/5*0/
C
C
C    *** IBRKPT BLOCK DATA ***
C
      DATA IBRKPT/51*0/
C
C    *** KNUMBR BLOCK DATA--EACH VARIABLE NAME IS ITS VALUE (K0=0 ETC.)
C
      DATA  K0/ 0/,  K1/ 1/,  K2/ 2/,  K3/ 3/,  K4/ 4/,  K5/ 5/,
     +      K6/ 6/,  K7/ 7/,  K8/ 8/,  K9/ 9/, K10/10/, K12/12/,
     +     K13/13/, K15/15/, K16/16/, K18/18/, K19/19/, K23/23/,
     +     K24/24/, K25/25/, K26/26/, K27/27/, K29/29/, K30/30/,
     +     K31/31/, K32/32/, K33/33/, K34/34/, K44/44/, K45/45/,
     +     K46/46/, K47/47/, K48/48/, K50/50/, K51/51/, K52/52/,
     +     K1013/1013/,  K1E4/10000/,    K1E6/1000000/, KM1/-1/
C
C
C    *** IDEF BLOCK DATA ***
C
      DATA LDASIZ/0/,IERROR/0/,SURFAD/4*0/,KWRDSZ/8/,IBLK1/0/
C
C
C    *** IFXCOR BLOCK DATA ***
C
      DATA  IAERR/0/  IAUTPS/0/, IBEGIN/0/,      IC/0/,    ICL/0/,
     +        ICS/4/, ICSCNT/0/, ICTDEF/1/,    ICUT/0/,    IDS/3/,
     +        IER/0/,    IGO/0/,  IGOTO/1/,   IGOUG/0/,    IGS/1/,
     +      INOPS/0/, IPSDEF/1/,    IPS/2/,    IPT1/0/,     IS/0/,
     +     ISEQNO/0/,  ISRCH/0/, ISTRUP/0/,      IT/0/, I3DFLG/0/,
     +        JBR/0/,    JSW/0/,    LSV/1/,    LSV1/1/, MOTMOD/0/,
     +     MULOUT/0/, MANTAX/1/, NMPNTS/400/,  NREC/0/,  NUMAX/0/,
     +     NUMCNT/0/,   NUMP/5/, NUMPT1/0/,  NUMSFS/4/, NUMSUR/0/,
     +         NW/0/, ICHECK/0/,   ISEG/0/,  NMBSEG/0/,   NWDS/0/,
     +       MSAV/0/
C
C  ***** DATA FOR ADDCOM BLOCK **************
C
C
      DATA ELMAX/ 200./,CLNGTH/0./,(ADDCOM(I),I=3,22)/20*0./
      DATA  IBTFLG /-1/,  JLIN /0/,  KDYNFL /0/
C
C
C  ****  TRACFL BLOCK DATA ******************
C     INITIALIZED FALSE SET TRUE BY FIRST ENTRY INTO APT024.
C
      DATA TRACFL/.FALSE./
C
C
C...  ***** DATA FOR AERR BLOCK ******
      DATA   IAERFG, NPCTPT, PCTPTS, PCTPLN, ERRPTS / 2*0,  73*0.0 /
C
C     ***** DATA FOR HOLD **********
      DATA JHLDFG,ITHCNT /0,1/
C
C     *****DATA FOR DARRAY ***********
C
      DATA DARRAY/'
     +
     + '/
C---    INITIALIZATION FOR UNITS
      DATA OLDMOD/'INCHES'/,IOLD/3/,TABEXT/10.0/,SSEXT/10.0/
      END
