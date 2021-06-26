**** SOURCE FILE : M0000398.W01   ***
*
C
C...  FORTRAN SUBROUTINE           ACNTRL...         RC,AR
C     MODIFIED FOR SSV3  E.MCLELLAN
C
      SUBROUTINE ACNTRL(ARRAY,FILEA)
      IMPLICIT  DOUBLE PRECISION(A-H,O-Z)
C
C...  THIS SUBROUTINE RECEIVES CONTROL FOR THE POSTEXEC LOAD MODULE.
C     IT READS CPFILE AND AND LISTS THE NAMES OF THE NECESSARY
C     POSTPROCESSORS.
C     CLFILE(S) ARE ALSO SAVED FOR FUTURE POST PROCESSING
C
      INCLUDE 'SYMFIL.INC'
      CHARACTER*6 PPNAME
C
C     ****         ****      ****      ****      ****      ****
C
C
C...      32.  PARAMETERS REQUIRED BY SUPERVISOR
C
          COMMON/SUPER/ERR,XC,CL,PX,ERRX,END,FINI,ASM,ABEND,XTRAS
          DIMENSION XTRAS(7),CFLAGS(4),LXTRAS(7)
          INTEGER   ERRX,XTRAS
          LOGICAL   ERR,FINI,XC,CL,ASM,LXTRAS,CFLAGS,PX,END,ABEND
          EQUIVALENCE (LXTRAS(1),XTRAS(1)),(CFLAGS(1),ERR)
C
      DIMENSION NNN(48),PPS(2,10)
      EQUIVALENCE (NNN(6),NOP),(NNN(3),N)
      EQUIVALENCE (PPS(1,1),NNN(9))
C
C
c     adding this line because the tape has data, but is at the end
c     of the file
      call tapop(cpfile,-4)
      CALL AREAD(CPFILE,1,NNN,48,IR)
C
C... IS POST PROCESSING REQUIRED
C
      IF(N.NE.0) THEN
C
C...CLOSE CLFILES AND KEEP
C
        CALL TAPOP(CLFILP,-3)
        IF (NOP.EQ.1) CALL TAPOP(CLFILE,-3)
        CALL TAPOP(CLFIL3,-3)
C
C....WRITE CURRENT POST PROCESSOR NAMES TO FILE - PPFILE.DAT
C
        NUMPST=N/2
C
        DO 50 I=1,NUMPST
          CALL HOLFRM(PPS(1,I),PPNAME,1,6,NWD)
          CALL OUTMSG(' POST PROCESSOR '//PPNAME//' REQUESTED')
   50   CONTINUE
C
      ENDIF
C
      ABEND=.FALSE.
C
      END