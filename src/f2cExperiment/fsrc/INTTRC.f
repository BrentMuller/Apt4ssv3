**** SOURCE FILE : M0005847.V01   ***
*
      SUBROUTINE INTTRC (J12,J11,PT,IDIR,IRC)
C
C   J12 : I: SURFACE INDEX OF PS
C   J11 : I: SURFACE INDEX OF DS
C   PT  : I: POINT STORAGE OF SEGMENT END
C   IDIR: I: FIRST (=1) OR LAST (=-1) SEGMENT POINT
C   IRC : O: =0: NO CONNECTING PAIR OF PATCHES FOUND ; =1: FOUND
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C BLANK COMMON
      INCLUDE 'BLANKCOM.INC'
C
C   COMMON FOR 2 SURFACE INTERSECTION
      COMMON/INTCOM/IKEEP(255)
C   PATCH NUMBER FOR PS AND DS (SURFACE RECNO*1000 + PATCH NO)
      INTEGER IPNR(2)
      EQUIVALENCE (IKEEP(254),IPNR(1))
C
C SS - ARELEM - COMMON
      COMMON/SSARLM/BB(64,4),UU(4),VV(4),
     *              IITOP(6,4,4),IIFLAG(4,4),IPNUM(4)
      DOUBLE PRECISION PT(9,1)
C
C   FIRST BORDER NUMBER FIELD
      INTEGER IBO1(3,3)
C
C   SECOND BORDER NUMBER FIELD
      INTEGER IBO2(3,3)
C
      DATA IBO1/2,1,1,2,0,3,4,4,3/
      DATA IBO2/1,0,3,0,0,0,2,0,4/
C
C AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
C
C   RETURN CODE
      IRC=0
C
C  PS SEARCH
      JU=2
      IF(DABS(PT(7,1)).LT.1.D-5)JU=1
      IF(DABS(PT(7,1)-1.D0).LT.1.D-5)JU=3
      JV=2
      IF(DABS(PT(8,1)).LT.1.D-5)JV=1
      IF(DABS(PT(8,1)-1.D0).LT.1.D-5)JV=3
C
C  BOUNDARY NUMBER
      NB1=IBO1(JU,JV)
      IF(NB1.EQ.0)GOTO 50
C
C  NEXT PATCH
      NP=IITOP(2,NB1,1)
      IF(NP.EQ.0)GOTO 50
C
C  LOAD PATCH
      M=0
      NB2=IBO2(JU,JV)
      IF(NB2.NE.0)M=2
      CALL LODPCH(SSCAN(J12+1),BB(1,1),IIFLAG(1,1),IITOP(1,1,1),NP,M)
      IPNR(1)=IPNR(1)/1000*1000+NP
      IPNUM(1)=NP
C
C   CORNER PATCH ?
      IF(NB2.NE.0)GOTO 20
      IRC=1
      GOTO 50
C  NEXT PATCH AT CORNER
   20 NP=IITOP(2,NB2,1)
      IF(NP.EQ.0)GOTO 50
C
C  LOAD PATCH
      CALL LODPCH(SSCAN(J12+1),BB(1,1),IIFLAG(1,1),IITOP(1,1,1),NP,0)
      IPNR(1)=IPNR(1)/1000*1000+NP
      IPNUM(1)=NP
      IRC=1
C
C  DS SEARCH
   50 IF(IIFLAG(1,2).LE.0)GOTO 99
      JU=2
      IF(DABS(PT(4,1)).LT.1.D-5)JU=1
      IF(DABS(PT(4,1)-1.D0).LT.1.D-5)JU=3
      JV=2
      IF(DABS(PT(5,1)).LT.1.D-5)JV=1
      IF(DABS(PT(5,1)-1.D0).LT.1.D-5)JV=3
C
C  BOUNDARY NUMBER
      NB1=IBO1(JU,JV)
      IF(NB1.EQ.0)GOTO 99
      NB2=IBO2(JU,JV)
C
C  NEXT PATCH
      NP=IITOP(2,NB1,2)
      IF(NP.EQ.0)GOTO 99
C
C  LOAD PATCH
      M=0
      NB2=IBO2(JU,JV)
      IF(NB2.NE.0)M=2
      CALL LODPCH(SSCAN(J11+1),BB(1,2),IIFLAG(1,2),IITOP(1,1,2),NP,M)
      IPNR(2)=IPNR(2)/1000*1000+NP
      IPNUM(2)=NP
C
C   CORNER PATCH ?
      IF(NB2.NE.0)GOTO 70
      IRC=1
      GOTO 99
C  NEXT PATCH AT CORNER
   70 NP=IITOP(2,NB2,2)
      IF(NP.EQ.0)GOTO 99
C
C  LOAD PATCH
      CALL LODPCH(SSCAN(J11+1),BB(1,2),IIFLAG(1,2),IITOP(1,1,2),NP,0)
      IPNR(2)=IPNR(2)/1000*1000+NP
      IPNUM(2)=NP
      IRC=1
C
   99 RETURN
      END
