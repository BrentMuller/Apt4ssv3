**** SOURCE FILE : M0001913.W04   ***
*
      SUBROUTINE SMIL
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---   PURPOSE OF THE ROUTINE IS TO DECODE SMIL/ COMMANDS
C---   AND CALL THE PATH ROUTINE, SSPATH, TO GENERATE CLDATA
C---   ERRORS FROM SSPATH OR UNINITIALIZED DATA AREAS ARE
C---   DETECTED HERE AND CALLS ARE MADE TO AERR.
C
      INCLUDE 'BLANKCOM.INC'
C
      COMMON/MAXLDA/MAXLDA
C
      LOGICAL CKDEF
C
      CHARACTER*6 WALL,WAT,WAXIS,WCLDAT,WCROSS,WCRSSP,WCS,WDS,WFEED,
     1 WIN,WINCR,WINIT,WMINUS,WNORMA,WNORMD,WNORMP,WOFF,WON,WOUT,
     2 WPARAM,WPATH,WPICKF,WPLANE,WPLUS,WPOINT,WPOSN,WPS,WSCALA,
     3 WSCURV,WSSURF,WSTEPO,WTANSP,WTO,WVECTO,WZIGZA,WDISPL
      CHARACTER*8 RNAM1,RNAM2,RNAM3,RNAMA,RNAME
      CHARACTER*6 CTEST,HPOCKT*8
      CHARACTER*20 BADMSG
      INTEGER IPOCKT(2),BCDF
C
      INTEGER IZAL1(7),IZAL2(4)
C
      COMMON/IBUGG/IBUG,I1,I2
      COMMON/XDS/DGEOM(4),DLIM(4),TLDIR(3),DOFSET,ITLDIR,IDTOOL,NDS
      COMMON/XPS/PGEOM(4),PSIDE,PTHICK,IPTOOL,NPS
      COMMON/XFEED/CLRPLN(4),FED(4),NCLRPL,NFEED
      COMMON/XSTEPO/SSTEP(4),NSTEPO
      COMMON/XAXIS/AXIS(3),IAXIS,NAXIS
                                      
      INCLUDE 'RMFLGS.INC'
                          
      DIMENSION TUL(7),VEC(3),VINC(4),TE(3),TA(3),TD(3)
      DIMENSION PTEM(2)
C
C
      DATA     RNAM1   /'SMIL    '/,RNAM2   /'SSPATH  '/,
     *           RNAM3   /'CUTREC  '/,RNAMA   /'SMIL  ??'/,
     *           RNAME   /'        '/
      DATA   IMAX1/ 7/, IZAL1
     *         /3561,3562,3563,3564,3565,3566,3567/
      DATA   IMAX2/ 4/, IZAL2
     *         /3551,3552,3553,3554/
C--WORD MODE VALUES IN REAL FORM AND HOLLERITH FORM.
C--THESE ARE WORDS USED IN SMIL AND SCON COMMANDS
C
      DATA AALL/50.D0/,WALL/'ALL   '/
      DATA AAT/66.D0/,WAT/'AT    '/
      DATA AAXIS/146.D0/,WAXIS/'AXIS  '/
      DATA ACLDAT/69.D0/,WCLDAT/'CLDATA'/
      DATA ACROSS/40.D0/,WCROSS/'CROSS '/
      DATA ACRSSP/137.D0/,WCRSSP/'CRSSPL'/
      DATA ACS/1.D0/,WCS/'CS    '/
      DATA ADS/1.D0/,WDS/'DS    '/
      DATA AFEED/163.D0/,WFEED/'FEED  '/
      DATA AIN/20.D0/,WIN/'IN    '/
      DATA AINCR/57.D0/,WINCR/'INCR  '/
      DATA AINIT/161.D0/,WINIT/'INIT  '/
      DATA AMINUS/41.D0/,WMINUS/'MINUS '/
      DATA ANORMA/13.D0/,WNORMA/'NORMAL'/
      DATA ANORMD/151.D0/,WNORMD/'NORMDS'/
      DATA ANORMP/152.D0/,WNORMP/'NORMPS'/
      DATA AOFF/50.D0/,WOFF/'OFF   '/
      DATA AON/3.D0/,WON/'ON    '/
      DATA AOUT/21.D0/,WOUT/'OUT   '/
      DATA APARAM/144.D0/,WPARAM/'PARAM '/
      DATA APATH/165.D0/,WPATH/'PATH  '/
      DATA APICKF/166.D0/,WPICKF/'PICKFD'/
      DATA APLANE/2.D0/,WPLANE/'PLANE '/
      DATA APLUS/42.D0/,WPLUS/'PLUS  '/
      DATA APOINT/19.D0/,WPOINT/'POINT '/
      DATA APOSN/164.D0/,WPOSN/'POSN  '/
      DATA APS/1.D0/,WPS/'PS    '/
      DATA ASCALA/21.D0/,WSCALA/'SCALAR'/
      DATA ASCURV/30.D0/,WSCURV/'SCURV '/
      DATA ASSURF/29.D0/,WSSURF/'SSURF '/
      DATA ASTEPO/162.D0/,WSTEPO/'STEPOV'/
      DATA ATANSP/136.D0/,WTANSP/'TANSPL'/
      DATA ATO/3.D0/,WTO/'TO    '/
      DATA AVECTO/20.D0/,WVECTO/'VECTOR'/
      DATA AZIGZA/61.D0/,WZIGZA/'ZIGZAG'/
      DATA ADISPL/0.0D0/,WDISPL/'DISPLY'/
C
      DATA ZERO,ONE/0.D0,1.D0/
      DATA SMAL/1.0D-14/
      DATA IBEGIN/42/,NOGOOD/-121/
      DATA NLAST/0/,NBIG/50/,IOK/121/
      DATA IRBASE/3550/
      DATA HPOCKT/'POCKET'/
C
      IPOCKT(1)=BCDF(HPOCKT(1:4))
      IPOCKT(2)=BCDF(HPOCKT(5:8))
      CALL APT299(0,IPOCKT,0,0)
      DO 10 I=1,3
      TE(I)=ZERO
   10 TA(I)=ZERO
      ICUR=IBEGIN
      NLEN=COM(ICUR)
      NLAST=IBEGIN+NLEN-2
      COM(NLAST)=ZERO
      ICUR=ICUR+1
      IF(NLEN.LT.3.OR.NLEN.GT.NBIG) GO TO 995
C
      WORD=COM(ICUR)
      CALL HOLFRM(COM(ICUR+1),CTEST,1,6,NWD)
      IF(CTEST.EQ.WDISPL) WORD=COM(ICUR+1)
      ICUR=ICUR+2
      IF(WORD.EQ.APOSN) GO TO 100
      IF(WORD.EQ.APATH) GO TO 200
      IF(WORD.EQ.AZIGZA) GO TO 300
      IF(WORD.EQ.APICKF) GO TO 300
      CALL HOLFRM(WORD,CTEST,1,6,NWD)
      IF(CTEST.EQ.WDISPL) GO TO 300
      GO TO 998
C
C--PROCESS THE SMIL/POSN COMMAND
  100 CONTINUE
      CALL CLPUT(TE,TA,-1)
      CALL HOLFRM(COM(ICUR+1),CTEST,1,6,NWD)
      IF(CTEST.NE.WDS) GO TO 998
      IF(COM(ICUR).NE.APARAM) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      UST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      VST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.AINCR) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).EQ.ASCALA) GO TO 110
      IF(COM(ICUR).EQ.AVECTO) GO TO 130
      IF(COM(ICUR).EQ.APLANE) GO TO 150
      GO TO 998
C--SCALAR LIFT BACK PARAMETER
  110 CONTINUE
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      VINC(1)=COM(ICUR+1)
      ICUR=ICUR+2
      INCTYP=21
      GO TO 190
  130 CONTINUE
C--VECTOR LIFTBACK PARAMETER
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      DO 140 I=1,3
  140 VINC(I)=COM(ICUR+I)
      ICUR=ICUR+4
      INCTYP=20
      GO TO 190
  150 CONTINUE
C--CLEARANCE PLANE LIFTBACK
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      DO 160 I=1,4
  160 VINC(I)=COM(ICUR+I)
      INCTYP=2
      ICUR=ICUR+5
      GO TO 190
C
  190 CONTINUE
      IF(ICUR.NE.NLAST) GO TO 996
C--CHECK IF PROPER BLOCKS ARE INITIALIZED
      IF(NDS.EQ.NOGOOD) GO TO 994
      IF(NPS.EQ.NOGOOD) GO TO 994
      IF(NAXIS.EQ.NOGOOD) GO TO 994
C
C--GET OTHER NEEDED APT VARIABLES
      CALL GETAPT(TUL,PTOLI,PTOLO,DTOL,AMAXDP,ELMAX,MAXCL,IR)
      IF(IR.NE.0) GO TO 993
C--FETCH PART AND DRIVE SURFACES
      CALL GFETCH(NBIG,MAXLDA,COM,DGEOM,PGEOM,IR)
      IF(IR.NE.0) GO TO 992
C--SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH
C--ICLSKP NEGATIVE GUARANTEES NO CL OUTPUT UNTIL TE IS
C--COMPENSATED
      IF(UST.LT.DLIM(1)-SMAL.OR.UST.GT.DLIM(2)+SMAL) GO TO 996
      IF(VST.LT.DLIM(3)-SMAL.OR.VST.GT.DLIM(4)+SMAL) GO TO 996
      PDIR=ONE
      IDTYPE=1
      IF(DGEOM(3).EQ.ASCURV) IDTYPE=0
      SCALHT=ZERO
      STEPOV=ZERO
      MAXCL=1
      ICLSKP=-1
      IQUAL=0
      DO 170 I=1,3
      TE(I)=ZERO
      TA(I)=ZERO
      TD(I)=ZERO
  170 CONTINUE
C
      DSTEP=ONE
      IPART=PGEOM(4)
      IDRIV=DGEOM(4)
      STEPMX=ZERO
C
C.... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD
      IF (LINTCK) CALL INEX(COM(IPART),PSIDE,PTOLI,PTOLO)
C
      CALL SSPATH(COM(IDRIV), IDTYPE, PDIR, DTOL, DSTEP, DOFSET,
     X           DLIM, IDTOOL, IAXIS, AXIS, ITLDIR,
     X       TLDIR, COM(IPART), PSIDE, PTHICK, PTOLI, PTOLO, IPTOOL,
     X           TUL, UST, VST, SCALHT, STEPOV, STEPMX,
     X           AMAXDP,ELMAX, MAXCL, ICLSKP, IQUAL,
     X           TE,  TA,  TD,  PTEM,  IRR)
      IF(IRR.NE.0) GO TO 990
C--POSN SUCESSFUL, NOW COMPENSATE TOOL END
      IF(INCTYP.EQ.20) GO TO 172
      IF(INCTYP.EQ.2) GO TO 174
      BACKUP=VINC(1)
      DO 181 I=1,3
  181 TE(I)=TE(I)-BACKUP*TD(I)
      GO TO 185
C
  174 CONTINUE
C---CLEARANCE PLANE CALCULATION
      CALL CLIFT(TE,VINC,TE)
      GO TO 185
C
  172 CONTINUE
C--VECTOR INCREMENT
      DO 183 I=1,3
  183 TE(I)=TE(I)+VINC(I)
      GO TO 185
C
  185 CONTINUE
      CALL CLPUT(TE,TA,1)
      GO TO 999
C
C--PROCESS PATH COMMAND
  200 CONTINUE
      CALL CLPUT(TE,TA,-1)
      CALL HOLFRM(COM(ICUR+1),CTEST,1,6,NWD)
      IF(CTEST.NE.WDS) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.APARAM) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      UST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      VST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ATANSP.AND.COM(ICUR).NE.ACRSSP) GO TO 998
      IDTYPE=1
      IF(COM(ICUR).EQ.ACRSSP) IDTYPE=2
      IF(DGEOM(3).EQ.ASCURV) IDTYPE=0
      ICUR=ICUR+2
      IF(COM(ICUR).NE.APLUS.AND.COM(ICUR).NE.AMINUS) GO TO 998
      PDIR=ONE
      IF(COM(ICUR).EQ.AMINUS) PDIR=-ONE
      ICUR=ICUR+2
C---OPTIONAL PARAMETER TO INDICATE WHETHER TO SKIP FIRST RECORD
      ISKP=0
      IF(COM(ICUR).NE.ASCALA) GO TO 210
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      IF(COM(ICUR+1).GT.SMAL) ISKP=1
      ICUR=ICUR+2
      GO TO 210
C
  210 CONTINUE
      IF(ICUR.NE.NLAST) GO TO 995
      IF(NDS.EQ.NOGOOD) GO TO 994
      IF(NPS.EQ.NOGOOD) GO TO 994
      IF(NAXIS.EQ.NOGOOD) GO TO 994
C
C--GET OTHER NEEDED APT VARIABLES
      CALL GETAPT(TUL,PTOLI,PTOLO,DTOL,AMAXDP,ELMAX,MAXCL,IR)
      IF(IR.NE.0) GO TO 993
C--FETCH PART AND DRIVE SURFACES
      CALL GFETCH(NBIG,MAXLDA,COM,DGEOM,PGEOM,IR)
      IF(IR.NE.0) GO TO 992
C--SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH
C--ICLSKP NEGATIVE GUARANTEES NO CL OUTPUT UNTIL TE IS
C--COMPENSATED
      IF(UST.LT.DLIM(1)-SMAL.OR.UST.GT.DLIM(2)+SMAL) GO TO 996
      IF(VST.LT.DLIM(3)-SMAL.OR.VST.GT.DLIM(4)+SMAL) GO TO 996
      SCALHT=ZERO
      STEPOV=ZERO
      ICLSKP=ISKP
      IQUAL=0
      DO 220 I=1,3
      TE(I)=ZERO
      TA(I)=ZERO
      TD(I)=ZERO
  220 CONTINUE
C
      IPART=PGEOM(4)
      DSTEP=ONE
      IDRIV=DGEOM(4)
      STEPMX=ZERO
C
C.... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD
      IF (LINTCK) CALL INEX(COM(IPART),PSIDE,PTOLI,PTOLO)
C
      CALL SSPATH(COM(IDRIV), IDTYPE, PDIR, DTOL, DSTEP, DOFSET,
     X           DLIM, IDTOOL, IAXIS, AXIS, ITLDIR,
     X       TLDIR, COM(IPART), PSIDE, PTHICK, PTOLI, PTOLO, IPTOOL,
     X           TUL, UST, VST, SCALHT, STEPOV, STEPMX,
     X           AMAXDP,ELMAX, MAXCL, ICLSKP, IQUAL,
     X           TE,  TA,  TD,  PTEM,  IRR)
      IF(IRR.NE.0) GO TO 990
      GO TO 999
C
C--PROCESS INPUT FOR ZIGZAG AND PICKFD
  300 CONTINUE
      CALL HOLFRM(COM(ICUR+1),CTEST,1,6,NWD)
      IF(CTEST.NE.WDS) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.APARAM) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      UST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASCALA) GO TO 998
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      VST=COM(ICUR+1)
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ATANSP.AND.COM(ICUR).NE.ACRSSP) GO TO 998
      IDTYPE=1
      IF(COM(ICUR).EQ.ACRSSP) IDTYPE=2
      IF(DGEOM(3).EQ.ASCURV) IDTYPE=0
      ICUR=ICUR+2
      IF(COM(ICUR).NE.APLUS.AND.COM(ICUR).NE.AMINUS) GO TO 998
      PDIR=ONE
      IF(COM(ICUR).EQ.AMINUS) PDIR=-ONE
      ICUR=ICUR+2
      IF(COM(ICUR).NE.ASTEPO) GO TO 998
      ICUR=ICUR+2
      IF(COM(ICUR).NE.APLUS.AND.COM(ICUR).NE.AMINUS) GO TO 998
      CDIR=ONE
      IF(COM(ICUR).EQ.AMINUS) CDIR=-ONE
      ICUR=ICUR+2
C---OPTIONAL PARAMETER TO INDICATE WHETHER TO SKIP FIRST RECORD
      ISKP=0
      IF(COM(ICUR).NE.ASCALA) GO TO 310
      IF(CKDEF(COM(ICUR+1))) GO TO 997
      IF(COM(ICUR+1).GT.SMAL) ISKP=1
      ICUR=ICUR+2
      GO TO 310
C
  310 CONTINUE
      IF(ICUR.NE.NLAST) GO TO 995
      IF(NDS.EQ.NOGOOD) GO TO 994
      IF(NPS.EQ.NOGOOD) GO TO 994
      IF(NAXIS.EQ.NOGOOD) GO TO 994
      IF(NFEED.EQ.NOGOOD) GO TO 994
      IF(NSTEPO.EQ.NOGOOD) GO TO 994
      IF(WORD.EQ.APICKF.AND.NCLRPL.EQ.NOGOOD) GO TO 994
C
C--GET OTHER NEEDED APT VARIABLES
      CALL GETAPT(TUL,PTOLI,PTOLO,DTOL,AMAXDP,ELMAX,MAXCL,IR)
      IF(IR.NE.0) GO TO 993
C--FETCH PART AND DRIVE SURFACES
      CALL GFETCH(NBIG,MAXLDA,COM,DGEOM,PGEOM,IR)
      IF(IR.NE.0) GO TO 992
C--SET APPROPRIATE STARTING VALUES FOR CALL TO SSPATH
      IF(UST.LT.DLIM(1)-SMAL.OR.UST.GT.DLIM(2)+SMAL) GO TO 996
      IF(VST.LT.DLIM(3)-SMAL.OR.VST.GT.DLIM(4)+SMAL) GO TO 996
C--CUTREG ROUTINE SEPARATED TO REDUCE SUBROUTINE SIZE
      IQUAL=0
C
C.... PERFORM PRELIMINARY INTERFERENCE CHECKING CALCULATIONS IF REQD
      IPART=PGEOM(4)
      IF (LINTCK) CALL INEX(COM(IPART),PSIDE,PTOLI,PTOLO)
C
      CALL CUTREG(WORD,CDIR,UST,VST,PDIR,IDTYPE,IQUAL,
     X   TUL,PTOLI,PTOLO,DTOL,AMAXDP,ELMAX,MAXCL,ISKP,IRR)
      IF(IRR.NE.0) GO TO 990
      GO TO 999
C
  992 CONTINUE
C---ERROR, PART OR DRIVE GEOMETRY COULD NOT BE FETCHED
      IRR=17
      GO TO 990
  993 CONTINUE
C---ERROR, GENERAL APT ARELEM VARIABLES INVALID
      IRR=16
      GO TO 990
  994 CONTINUE
C---ERROR,  SCON DATA AREA IS UNINITIALIZED
      IRR=15
      GO TO 990
  995 CONTINUE
C---ERROR, LENGTH OF SMIL INPUT FIELD INVALID
      IRR=14
      GO TO 990
  996 CONTINUE
C---ERROR, INPUT VALUES ARE INVALID
      IRR=13
      GO TO 990
  997 CONTINUE
C---ERROR, INPUT CANON FORM NOT DEFINED
      IRR=12
      GO TO 990
  998 CONTINUE
C---ERROR, INPUT VARIABLE WAS UNRECOGNIZED IN POSITION
      IRR=11
      GO TO 990
C
  990 CONTINUE
      IRR=IRBASE+IRR
      CALL RECORD(ISQ)
      CALL BAD(-1,0,' ',0)
      BADMSG=' END OF SMIL'
      CALL CPRINT(BADMSG)
      CALL BAD(1,0,'ISEQ',ISQ)
      CALL BAD(1,0,'NLST',NLAST)
      CALL BAD(1,0,'NLEN',NLEN)
      CALL BAD(1,0,'IRR ',IRR)
      CALL BAD(1,0,'ICUR',ICUR)
      CALL BAD(-1,0,'IRBS',IRBASE)
      CALL BAD(1,0,'DS  ',NDS)
      CALL BAD(1,0,'PS  ',NPS)
      CALL BAD(1,0,'FEED',NFEED)
      CALL BAD(1,0,'STOV',NSTEPO)
      CALL BAD(1,0,'AXIS',NAXIS)
      CALL BAD(-1,0,'CPLN',NCLRPL)
C
      RNAME=RNAMA
      DO 8001 IL1 = 1,IMAX1
 8001 IF (IRR.EQ.IZAL1(IL1)) RNAME=RNAM1
      DO 8002 IL2 = 1,IMAX2
 8002 IF (IRR.EQ.IZAL2(IL2)) RNAME=RNAM2
      CALL AERR(IRR,RNAME)
C
      GO TO 999
C
  999 CONTINUE
C
      RETURN
      END
