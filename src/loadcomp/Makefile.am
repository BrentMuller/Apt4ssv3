
AM_FCFLAGS = -I$(top_srcdir)/src/include -ffixed-form

#SUFFIXES = .f
#.f.o:
#	$(F77) -c $(AM_FFLAGS) $(INCLUDES) $<

#SUFFIXES = .f90
#.f.o:
#	$(F77) -c $(AM_FFLAGS) $(INCLUDES) $<

bin_PROGRAMS=loadcomp

#loadcomp_FFLAGS = -I$(top_srcdir)/src/include

loadcomp_SOURCES= block_data.f90 fun_bcdf.f90 fun_hex.f90 fun_name.f90 fun_orf.f90\
	sub_bcdbin.f90\
	sub_binbcd.f90\
	sub_cform.f90\
	sub_help.f90\
	sub_input.f90\
	sub_load0.f90\
	sub_load1.f90\
	sub_load2.f90\
	sub_loada.f90\
	sub_loadb.f90\
	sub_loadg.f90\
	sub_loadi.f90\
	sub_loadm.f90\
	sub_loadn.f90\
	sub_loadp.f90\
	sub_loads.f90\
	sub_loadt.f90\
	sub_loadu.f90\
	sub_read.f90\
	sub_shift.f90\
	sub_sort.f90\
	sub_spill.f90\
	main_loadcomp.f90\
	../vaxbitcm/vaxbitcm.f90

