**** SOURCE FILE : M0004132.V07   ***
*
C
C
      SUBROUTINE GO(HMOD,ADRESS)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IFXCOR.INC'
C
      DIMENSION ADRESS(*)
c      IF(JDS) CALL APT211(0,'NOCS    ',IDUM)
      if(jds) then
         dummy= apt211(0,'nocs    ',idum)
      endif
C-IBM-      CALL APT241
      IF(IAERR.EQ.1)GO TO 10
C-VAX-ESTABLISH CONDITION HANDLER
      CALL APT241
   20 IF(ICTDEF.NE.0.AND.IGOTO.EQ.0)CALL AERR(20201,'GO      ')
      IF (IAERR.EQ.1) GOTO 10
      CALL GO2(HMOD,ADRESS)
      IF (IAERR.EQ.1) GOTO 20
C-VAX- REVERT TO DEFAULT CONDITION HANDLER
c   10 CALL LIB$REVERT
   10 call libsrevert
      RETURN
      END