**** SOURCE FILE : M0000441.V02   ***
*
C
C.....FORTRAN SUBROUTINE                APT340...            8/1/68  AR
C
C PURPOSE      SETS UP CUT VECTOR TO BE USED IN APT341
C LINKAGE      CALL APT340
C ARGUMENTS    NONE
C SUBSIDIARIES APT341
C********************************************************************
      SUBROUTINE APT340
C***********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C     SYSTEM COMMON,DIMENSION, AND EQUIVALENCE STATEMENTS
      COMMON /EDITOR/EDITOR
C
      DIMENSION EDITOR(1500)
C
      DIMENSION  AREA1(1500), AREA2(1000), AREA3(250)
      EQUIVALENCE (EDITOR(1500),AREA1 (1500),AREA2 (1000),AREA3 (250))
      EQUIVALENCE  (AREA3(82),X1),  (AREA3(83),X2),
     +             (AREA3(87),Y1),  (AREA3(88),Y2)
      COMMON/R5AXIS/
     1Z1    ,Z2    ,ZSTART,YSTART,XSTART,ZD    ,YD    ,XD    ,ZCV   ,
     2YCV   ,XCV   ,ZDO   ,YDO   ,XDO   ,ZCC  ,YCC    ,XCC    ,ZUN   ,
     3YUN   ,XUN   ,ZTR   ,YTR   ,XTR   ,ZTA   ,YTA   ,XTA   ,Z     ,
     4STANG ,ENDANG,DANG  ,CANG  ,DLNGTH,TLNGTH,CUTTER,TEST  ,CRADUS
      COMMON/I5AXIS/
     1IVTFLG,IS,IR,IL,IE,JSUBER,IABOVE,NRECEX,NRECCL,NCFLSV
C...    ESTABLISH CUT VECTOR
      XCV = X2 - X1
      YCV = Y2 - Y1
      ZCV = Z2 - Z1
      DLNGTH = DLNGTH +DSQRT(XCV**2+YCV**2+ZCV**2)
C...    NO WCORN
      CALL APT341
      RETURN
      END