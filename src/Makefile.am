
##AUTOMAKE_OPTIONS = subdir-objects

AM_FFLAGS = -I$(top_srcdir)/src/include -ffixed-form  -fdollar-ok -g -fno-range-check \
		-fno-automatic

AM_FCFLAGS = -I$(top_srcdir)/src/include 

bin_PROGRAMS=apt4ssv3

apt4ssv3_SOURCES = aptgeom/APTGEOM.f arelem/ARELEM.f goloft/GOLOFT.f aptfun/APTFUN.f \
ileditor/ILEDITOR.f gougechk/GOUGECHK.f ssarelem/SSARELEM.f \
ssdata/SSDATA.f postexec/POSTEXEC.f sseval/SSEVAL.f ssgeom/SSGEOM.f \
cleditor/CLEDITOR.f regmill/REGMILL.f nonnativ/NONNATIV.f \
intcheck/INTCHECK.f translat/TRANSLAT.f auxilary/AUXILARY.f \
vax/VAX.f xecution/XECUTION.f supervis/SUPERVIS.f  utility/UTILITY.f \
vax/apt211.f dummy.f fort1.f fort2.f fort3.f

#loadcomp/block_data.f 

