
apt4ssv3_FFLAGS = -I$(top_srcdir)/src/include -ffixed-form  -fdollar-ok -g -fno-range-check \
		-fno-automatic -O0

AM_FCFLAGS = -I$(top_srcdir)/src/include  #-O0


bin_PROGRAMS=apt4ssv3


apt4ssv3_SOURCES = \
aptfun/ANGLFB.f aptfun/CANF.f aptfun/DISTF.f aptfun/DOTF.f aptfun/LNTHF.f \
aptfun/MINMAX.f aptfun/NEWFUNCS.f aptfun/NUMF.f aptfun/PARMF.f aptfun/SPATF.f \
aptfun/UTILTY.f \
aptgeom/APT001.f aptgeom/APT003.f aptgeom/APT004.f aptgeom/APT005.f \
aptgeom/APT006.f aptgeom/APT007.f aptgeom/APT008.f aptgeom/APT009.f \
aptgeom/APT010.f aptgeom/APT011.f aptgeom/APT012.f aptgeom/APT013.f \
aptgeom/APT014.f aptgeom/APT015.f aptgeom/APT016.f aptgeom/APT017.f \
aptgeom/APT018.f aptgeom/APT019.f aptgeom/APT020.f aptgeom/APT021.f \
aptgeom/APT022.f aptgeom/APT023.f aptgeom/APT025.f aptgeom/APT026.f \
aptgeom/APT027.f aptgeom/APT028.f aptgeom/APT029.f aptgeom/APT030.f \
aptgeom/APT031.f aptgeom/APT032.f aptgeom/APT033.f aptgeom/APT034.f \
aptgeom/APT035.f aptgeom/APT036.f aptgeom/APT037.f aptgeom/APT038.f \
aptgeom/APT039.f aptgeom/APT040.f aptgeom/APT041.f aptgeom/APT042.f \
aptgeom/APT043.f aptgeom/APT044.f aptgeom/APT045.f aptgeom/APT046.f \
aptgeom/APT047.f aptgeom/APT048.f aptgeom/APT049.f aptgeom/APT050.f \
aptgeom/APT051.f aptgeom/APT052.f aptgeom/APT053.f aptgeom/APT054.f \
aptgeom/APT055.f aptgeom/APT056.f aptgeom/APT057.f aptgeom/APT058.f \
aptgeom/APT059.f aptgeom/APT060.f aptgeom/APT061.f aptgeom/APT062.f \
aptgeom/APT063.f aptgeom/APT064.f aptgeom/APT065.f aptgeom/APT066.f \
aptgeom/APT067.f aptgeom/APT068.f aptgeom/APT069.f aptgeom/APT070.f \
aptgeom/APT071.f aptgeom/APT072.f aptgeom/APT073.f aptgeom/APT074.f \
aptgeom/APT088.f aptgeom/APT089.f aptgeom/APT090.f aptgeom/APT102.f \
aptgeom/APT103.f aptgeom/APT105.f aptgeom/APT106.f \
arelem/AERR2.f arelem/AERR.f arelem/ALTCMV.f arelem/AMIND.f arelem/APT200.f \
arelem/APT227.f arelem/APT232.f arelem/APT233.f arelem/APT234.f arelem/APT235.f \
arelem/APT236.f arelem/APT238.f arelem/APT240.f arelem/ARLM2.f arelem/ARLM3.f \
arelem/AUTOPS.f arelem/BDCLDT.f arelem/BLDGOU.f arelem/CCURV.f arelem/CENTR.f \
arelem/CHECK.f arelem/CLDAT.f arelem/CLDATF.f arelem/COMP3D.f arelem/CPLAN.f \
arelem/CUT.f arelem/DDCYLN.f arelem/DDLIM.f arelem/DDPARA.f arelem/DDPARS.f \
arelem/DDPLAN.f arelem/DDQUAD.f arelem/DDRLSR.f arelem/DDST.f arelem/DDTABC.f \
arelem/DELTA.f arelem/DNTCUT.f arelem/FROM.f arelem/GAUSS.f arelem/GO2.f \
arelem/GODLTA.f arelem/GOTO.f arelem/GOTOPN.f arelem/GOUGE.f arelem/INDIRP.f \
arelem/INDIRV.f arelem/ISVCPY.f arelem/LCLS.f arelem/MAXDP.f arelem/MULTAX.f \
arelem/NOPS.f arelem/NUMPTS.f arelem/PARLND.f arelem/PLANE.f arelem/POCKET.f \
arelem/POLCON.f arelem/PSIS.f arelem/QUAD.f arelem/RADAR.f arelem/SRFVCT.f \
arelem/SVCOPY.f arelem/THICK.f arelem/TINKR.f arelem/TLAXIS.f arelem/TLLFT.f \
arelem/TLNORM.f arelem/TOLER.f arelem/U1COMP.f \
auxilary/AFORM.f auxilary/APT024.f auxilary/APT075.f auxilary/APT076.f \
auxilary/APT077.f auxilary/APT078.f auxilary/APT079.f auxilary/APT081.f \
auxilary/APT083.f auxilary/APT085.f auxilary/APT086.f auxilary/APT087.f \
auxilary/APT094.f auxilary/APT100.f auxilary/APT104.f auxilary/APT202.f \
auxilary/APT295.f auxilary/APT296.f auxilary/APT298.f auxilary/APT299.f \
auxilary/ATAPE.f auxilary/BAD.f auxilary/BDEBUF.f auxilary/BDEXER.f \
auxilary/CHKRET.f auxilary/CIRDEF.f auxilary/CKDEF.f auxilary/DARSIN.f \
auxilary/DEFEXT.f auxilary/DYNDMP.f auxilary/ERRLOD.f auxilary/ERROR.f \
auxilary/ERROUT.f auxilary/FINI.f auxilary/GCIRCL.f auxilary/GCONE.f \
auxilary/GCUBIC.f auxilary/GCYL.f auxilary/GPLANE.f auxilary/GQUAD.f \
auxilary/GSPHER.f auxilary/GSURF.f auxilary/LINDEF.f auxilary/LOGIF.f \
auxilary/NPAT.f auxilary/NULL.f auxilary/PRINT.f auxilary/PSIGN.f \
auxilary/PUNCH.f auxilary/QSD.f auxilary/RECORD.f auxilary/REFSYS.f \
auxilary/ROTAT.f auxilary/SCHTB.f auxilary/TRANRO.f auxilary/TRANSM.f \
auxilary/UNDEF.f auxilary/UNITS.f auxilary/UNPACK.f auxilary/VDOTF.f \
auxilary/VSCALE.f auxilary/ZSURF.f auxilary/ZVECT.f \
cleditor/APT301.f cleditor/APT302.f cleditor/APT303.f cleditor/APT304.f \
cleditor/APT305.f cleditor/APT306.f cleditor/APT308.f cleditor/APT309.f \
cleditor/APT310.f cleditor/APT311.f cleditor/APT312.f cleditor/APT313.f \
cleditor/APT314.f cleditor/APT315.f cleditor/APT316.f cleditor/APT330.f \
cleditor/APT331.f cleditor/APT332.f cleditor/APT335.f cleditor/APT336.f \
cleditor/APT340.f cleditor/APT341.f cleditor/APT342.f cleditor/CLED.f \
cleditor/CLEROR.f cleditor/CLERRW.f cleditor/CNVRT3.f \
goloft/BDCCLR.f goloft/BDGLFL.f goloft/BDPLGL.f goloft/CPLDST.f goloft/GCLEAR.f \
goloft/GOCHOR.f goloft/GOL.f goloft/GOLOFT.f goloft/GOLOVO.f goloft/GOLPLN.f \
goloft/GOP.f goloft/GORETR.f goloft/INTBND.f goloft/INTCON.f goloft/INTFA1.f \
goloft/INTFA2.f goloft/INTNRM.f goloft/INTOUT.f goloft/INTSEC.f goloft/INTSRF.f \
goloft/INTTPL.f goloft/INTTRC.f goloft/NUMVER.f goloft/PLAPOL.f goloft/POLMTN.f \
goloft/POLPOL.f goloft/PRO028.f goloft/QABPST.f goloft/REGION.f goloft/SETVER.f \
goloft/TLCONV.f \
gougechk/DEVCAL.f gougechk/GCHK.f gougechk/MIDKUR.f gougechk/MIDPNT.f \
gougechk/XTPCAL.f \
ileditor/CILOUT.f ileditor/COMPRS.f ileditor/EPILOG.f ileditor/ICMPRS.f \
ileditor/IEPLOG.f ileditor/IPRLOG.f ileditor/PROLOG.f ileditor/RLSBUF.f \
intcheck/ALGO1.f intcheck/ALGO2.f intcheck/AVCTRL.f intcheck/AVMSG.f \
intcheck/AVOID.f intcheck/BDAVCP.f intcheck/BDINID.f intcheck/BDINT.f \
intcheck/CALCB.f intcheck/CALCT.f intcheck/CALMXB.f intcheck/CHKSRF.f \
intcheck/CURCAL.f intcheck/CURINT.f intcheck/DEGSOL.f intcheck/DIST2.f \
intcheck/EVALSS.f intcheck/HULCUT.f intcheck/INEX.f intcheck/INTCHK.f \
intcheck/INTMSG.f intcheck/JMPLT2.f intcheck/MIXAL.f intcheck/NORMA.f \
intcheck/PENCUT.f intcheck/REMINT.f intcheck/REMSCN.f intcheck/RESET.f \
intcheck/RESTOR.f intcheck/SHELLA.f intcheck/SHELLB.f intcheck/SOLVE3.f \
intcheck/TCSPHR.f intcheck/TECALC.f intcheck/TXHULL.f intcheck/VECMOD.f \
nonnativ/EMDCS.f nonnativ/ETORUS.f nonnativ/EVAL.f nonnativ/EVDAFS.f \
nonnativ/KREUZ.f nonnativ/KRUMM.f nonnativ/TEVAL.f nonnativ/TMDCS.f \
nonnativ/TTORUS.f nonnativ/TVDAFS.f \
postexec/ACNTRL.f postexec/CLRD4.f \
regmill/ABW.f regmill/APT110.f regmill/AXSET.f regmill/BALLOC.f \
regmill/BALONE.f regmill/BALSCN.f regmill/BALSRF.f regmill/BALTOL.f \
regmill/BALTWO.f regmill/CHKSET.f regmill/CHKTOP.f regmill/CLIFT.f \
regmill/CLPUT.f regmill/CUTREG.f regmill/DGEOM.f regmill/FEDPUT.f \
regmill/GETAPT.f regmill/GFETCH.f regmill/GOMILL.f regmill/KURSRF.f \
regmill/MESCON.f regmill/PCHG.f regmill/SCON.f regmill/SMIL.f regmill/SQRBN.f \
regmill/SRFDIR.f regmill/SRFTOL.f regmill/SSPATH.f regmill/STEPCK.f \
regmill/TULPOS.f \
ssarelem/APRIX.f ssarelem/BONCHK.f ssarelem/DDSSRF.f ssarelem/DET3.f \
ssarelem/LODINT.f ssarelem/PCHPRC.f ssarelem/PUVLOC.f ssarelem/SQRCUT.f \
ssdata/SSDAT1.f ssdata/SSDAT2.f ssdata/SSDAT3.f \
sseval/BLENDF.f sseval/CMESH.f sseval/CNCURV.f sseval/CNSURF.f sseval/CNSURG.f \
sseval/CNSURH.f sseval/CRBLEN.f sseval/CURFLO.f \
ssgeom/ADER.f ssgeom/ANGDER.f ssgeom/ANGSEG.f ssgeom/APT107.f ssgeom/APT108.f \
ssgeom/APT109.f ssgeom/ARCSEG.f ssgeom/BDIZEL.f ssgeom/BEZIER.f ssgeom/BIQUAD.f \
ssgeom/CHDSEG.f ssgeom/CLOCUB.f ssgeom/COMPTW.f ssgeom/CRSFIT.f ssgeom/CRVLEN.f \
ssgeom/CTRANS.f ssgeom/CURFIT.f ssgeom/DISEG.f ssgeom/FLOINV.f ssgeom/FLOSEG.f \
ssgeom/FORCUB.f ssgeom/GELG.f ssgeom/GENCRV.f ssgeom/GETSCA.f ssgeom/LDARD.f \
ssgeom/LINEAR.f ssgeom/LOOPCH.f ssgeom/MESH.f ssgeom/NORML3.f ssgeom/PARAL.f \
ssgeom/PARINT.f ssgeom/PARMPT.f ssgeom/PNTSON.f ssgeom/RATCON.f ssgeom/REVOLV.f \
ssgeom/SCDUMP.f ssgeom/SCPICT.f ssgeom/SCTRA.f ssgeom/SCURV.f ssgeom/SMMULT.f \
ssgeom/SMOOTH.f ssgeom/SNORM.f ssgeom/SRFCOM.f ssgeom/SSPICT.f ssgeom/SSPLIN.f \
ssgeom/SSTRA.f ssgeom/SYCURV.f ssgeom/TOPGEN.f ssgeom/TRANSP.f \
supervis/ABLKDATA.f supervis/CRTN.f supervis/FLTAB.f supervis/GETPRM.f \
supervis/LINKF.f supervis/SPRVIS.f supervis/SSV3.f supervis/SYMFIL.f \
translat/ALARM.f translat/ANDF.f translat/ARGCVT.f translat/ARGGEN.f \
translat/ASNADZ.f translat/ASNJPZ.f translat/BCDBIN.f translat/BDIPL.f \
translat/BDSDP.f translat/BINBCD.f translat/BINCHK.f translat/BITMCH.f \
translat/BOOLIF.f translat/CALLZZ.f translat/CALMCX.f translat/CLMODE.f \
translat/COMSTR.f translat/CONCAT.f translat/ERRWRD.f translat/FOUTXX.f \
translat/GETTMP.f translat/GOPAT.f translat/HELP.f translat/IFTMP.f \
translat/INPAT.f translat/INPUT.f translat/ISSCOD.f translat/JUMPZZ.f \
translat/KONAST.f translat/LABCON.f translat/LABELZ.f translat/LARGES.f \
translat/LCANON.f translat/LOOP.f translat/MACLBL.f translat/MACREC.f \
translat/MACTAB.f translat/MATCH.f translat/MCXTRN.f translat/MNPROC.f \
translat/MODE.f translat/MOTION.f translat/NAME.f translat/NUMB.f \
translat/ONEARG.f translat/OPCODE.f translat/OPPAIR.f translat/PATH.f \
translat/PRO020.f translat/PRO021.f translat/PRO026.f translat/PRO027.f \
translat/PRTIL.f translat/PUTTMP.f translat/READ.f translat/RECOG.f \
translat/RECOGN.f translat/REFGEN.f translat/REFREF.f translat/REPLAC.f \
translat/RESERV.f translat/RESRED.f translat/RESRVZ.f translat/RETMCX.f \
translat/RLSLIN.f translat/SEARCH.f translat/SETBIT.f translat/SETCHR.f \
translat/SETMOD.f translat/SSDEF.f translat/START.f translat/SUBCOD.f \
translat/TSSMIL.f translat/TWOARG.f translat/VCTPRD.f \
utility/ABCDBN.f utility/ABUFTP.f utility/AREAD.f utility/ASERCH.f \
utility/ATAPOP.f utility/ATAPRD.f utility/ATAPWT.f utility/ATAPXC.f \
utility/AWRITE.f utility/BADNAM.f utility/BCDF.f utility/CARDPN.f \
utility/CFORM.f utility/CHREAD.f utility/CHWRIT.f utility/CLOCF4.f \
utility/CMPRES.f utility/CONBCD.f utility/CPRINT.f utility/CPUNCH.f \
utility/CREAD.f utility/DISPAT.f utility/DNONAM.f utility/FCONV.f \
utility/FREAD.f utility/HEX.f utility/HOLFRM.f utility/ICONV.f \
utility/NNTAIN.f utility/OUTMSG.f utility/PUNIDN.f utility/PUNIDS.f \
utility/RDSATZ.f utility/SHIFT.f utility/SPRINT.f utility/STRTSH.f \
utility/TAPOP.f utility/TRASH.f utility/WTSATZ.f \
vax/ADDRSS.f vax/APT201.f vax/apt211.f vax/APT241.f vax/ARTIME.f vax/BD2ITL.f \
vax/BDLIBC.f vax/CLOSPE.f vax/CPUTIM.f vax/CUTTES.f vax/FILOPN.f vax/FINDME.f \
vax/GO.f vax/LIBOPC.f vax/LIBRD.f vax/LIBSCH.f vax/OUTSET.f vax/PARNOM.f \
vax/PUNCHA.f vax/PUNCHC.f vax/TAPEPN.f vax/WTDIRE.f \
xecution/ADV.f xecution/DAT0.f xecution/DELALL.f xecution/EXEC.f xecution/GET.f \
xecution/IMAIN.f xecution/INIT.f xecution/INTRP.f xecution/LIB.f xecution/PAGE.f \
xecution/PUT.f xecution/RESRV.f xecution/SAVEAC.f xecution/SEQ.f xecution/SET.f \
xecution/UNASGN.f xecution/XCALL.f xecution/XCANON.f xecution/XNUMBR.f \
dummy.f fort1.f fort2.f fort3.f

####apt4ssv3_SOURCES = aptgeom/APTGEOM.f arelem/ARELEM.f goloft/GOLOFT.f \
####aptfun/UTILTY.f \
####aptfun/ANGLFB.f \
####aptfun/NEWFUNCS.f \
####aptfun/CANF.f \
####aptfun/DOTF.f \
####aptfun/DISTF.f \
####aptfun/MINMAX.f \
####aptfun/NUMF.f \
####aptfun/PARMF.f \
####aptfun/SPATF.f \
####aptfun/LNTHF.f \
####ileditor/ILEDITOR.f gougechk/GOUGECHK.f ssarelem/SSARELEM.f \
####ssdata/SSDATA.f postexec/POSTEXEC.f sseval/SSEVAL.f ssgeom/SSGEOM.f \
####cleditor/CLEDITOR.f regmill/REGMILL.f nonnativ/NONNATIV.f \
####intcheck/INTCHECK.f translat/TRANSLAT.f auxilary/AUXILARY.f \
####vax/VAX.f xecution/XECUTION.f \
####supervis/LINKF.f supervis/SYMFIL.f \
####supervis/GETPRM.f supervis/FLTAB.f supervis/SSV3.f \
####supervis/CRTN.f supervis/ABLKDATA.f supervis/SPRVIS.f  \
####utility/UTILITY.f \
####vax/apt211.f dummy.f fort1.f fort2.f fort3.f
