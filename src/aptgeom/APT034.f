**** SOURCE FILE : M0000784.V06   ***
*
C
C
C              FORTRAN SUBROUTINE APT034
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE,OF A
C              GIVEN RADIUS, TANGENT TO A LINE AND A TABULATED
C              CYLINDER IN THE XYPLANE.
C
C              A CIRCLE IS DEFINED BY THE FOLLOWING STATEMENT
C                RESULT = CIRCLE/ TANTO,LIN,****,TAB,****, $
C                                 PT,RADIUS,RADI
C                **** = XLARGE, YLARGE, XSMALL, YSMALL
C
C LINKAGE      CALL APT034 (RESULT, LIN, M1, TAB, M2, PT, RADI)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING CIRCLE
C              LIN     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT LINE
C              M1      INTEGER EQUIVALENT OF THE FIRST MODIFIER
C                             1 = XLARGE       2 = YLARGE
C                             4 = XSMALL       5 = YSMALL
C              TAB     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT TABCYL
C              M2      INTEGER EQUIVALENT OF THE SECOND MODIFIER
C                             1 = XLARGE       2 = YLARGE
C                             4 = XSMALL       5 = YSMALL
C              PT      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT POINT
C
C
      SUBROUTINE APT034 (RESULT,LIN,M1,TAB,M2,PT,RADI)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DOUBLE PRECISION  LIN,TAB,RADI,PT,RESULT
      DIMENSION RESULT(7),LIN(4),TAB(2),PT(3)
C
      INCLUDE 'BLANKCOM.INC'
C
      DIMENSION D(COMSIZ),VMOD(4,2),XN(11),YN(11),XINTRS(11),
     1 YINTRS(11),VECNRL(11)
      DIMENSION DD(5)
      EQUIVALENCE (CANON(1),D(1))
      LOGICAL CKDEF,LINDEF
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      EQUIVALENCE(UNIT,UINT)
C
      SMAL(Q)=DSIGN(DMAX1(DABS(Q),Z1EM9),Q)
      DO 777 I=1,2
      P(I)=PT(I)
      L(I)=LIN(I)
  777 V(I)=TAB(I)
      L(3)=LIN(3)
      L(4)=LIN(4)
      UNFLAG=LINDEF(L,K5).OR.CKDEF(P).OR.CKDEF(V)
      IF(UNFLAG) GO TO 9998
C
C...  RETRIEVE TABCYL EXTERNAL CANONICAL FORM. STORE CANON INDEX IN J11.
C
      CALL APT094(3,TAB(1),J11)
      J11=J11-2
C
C
C
C
C
C
C
C
C
C
C.....INITIALIZE
C
      IERROR=0
      TOLER=0.000025
C
C...   INUM=1 IF RADIUS PARALLEL LINE INTERSECTS TABCYL,
C           2 IF DIA. + TOL. PARALLEL LINE INTERSECTS,
C           3 IF LINE + TOL. INTERSECTS
C
      INUM=0
C
C...   IBACFG=0 IF DIRECTION OF SEARCH IS FWD,1 IF BACKWARD
C
      IBACFG=0
C
C...   ICOUNT IS COUNTER ON TABCYL INTERVALS SEARCHED
C
      ICOUNT=1
      KCHECK=0
      IONTST=0
      ITBPNT=0
      VMOD(1,1)=1.0
      VMOD(2,1)=-1.0
      VMOD(3,1)=0.0
      VMOD(4,1)=0.0
      VMOD(1,2)=0.0
      VMOD(2,2)=0.0
      VMOD(3,2)=1.0
      VMOD(4,2)=-1.0
C
C.....CHECK FOR NEGATIVE P IN LINE CANONICAL FORM.  LX+MY+NZ=P
C
      IF(L(4).GE.Z0) GO TO 921
      L(4)=-L(4)
      L(2)=-L(2)
      L(3)=-L(3)
      L(1)=-L(1)
  921 ILOUT=0
      LOUT=0
      NT=(D(J11+12)-Z1)*7.0+18.1
      NTZ=NT-2
      RAD=RADI
      RADSQR=RAD*RAD
      EPSILN=Z2*Z1EM5*RAD
      DELTA=Z1EM5/RAD
      DIAMT=Z2*RAD+TOLER
      ITRY=0
      CALL SCHTB(D(J11+1))
      IHU=D(J11+13)+0.1+J11
      IHUT=IHU
      ITL=NT-4+J11
      ITFR=J11+14
      D6SAVE=L(4)
C
C.....EXAMINE MOD 1 AND SET A LINE PARALLEL TO THE GIVEN LINE, ON
C.....WHICH THE CENTER OF THE TANGENT CIRCLE WILL LIE.
C
      IF(M1.EQ.1) IMOD=1
      IF(M1.EQ.2) IMOD=3
      IF(M1.EQ.4) IMOD=2
      IF(M1.EQ.5) IMOD=4
      XTEST=L(1)*VMOD(IMOD,1)+L(2)*VMOD(IMOD,2)
      IF(DABS(XTEST).GT.Z1EM7) GO TO 12
C
C.....IF MODIFIER 1 IS IN ERROR
C
   10 IERROR=77
      GO TO 9999
   12 IF(XTEST) 13,10,14
   13 L(4)=DABS(L(4))-DABS(RAD)
      SAVD6=L(4)
      GO TO 102
   14 L(4)=DABS(L(4))+DABS(RAD)
      SAVD6=L(4)
  102 D3SAVE=L(1)
      INUM=1
   15 CONTINUE
C
C.....IHUINT = INDEX LOCATING INTERVAL IN WHICH INTERSECTION
C.....ACTUALLY OCCURS
C
      IHUINT=0
C
C.....UNIT = X COORD. IN LOCAL SYSTEM OF INTERSECTION POINT
C.....OF PARALLEL LINE AND TABCYL
C
      UNIT=Z0
   41 IHU=IHUT
      L(1)=D3SAVE
      XAA=D(IHU+7)-D(IHU)
      YAA=D(IHU+8)-D(IHU+1)
      IZ=K1
      RA=-DATAN(YAA/SMAL(XAA))
      IF(XAA) 1000,1001,1001
 1000 RA=RA+PI
 1001 CALL TRANRO(XAA,YAA,XBB,YBB,RA,IZ)
C
C.....TABCYL MODIFIER ACCEPTANCE CRITERION
C
      IF(M2.NE.1) GO TO 17
      DPVALU=Z1
      GO TO 504
   17 IF(M2.NE.4) GO TO 19
      DPVALU=-Z1
  504 XAXIS=Z1
      YAXIS=Z0
      GO TO 22
   19 IF(M2.NE.2) GO TO 21
      DPVALU=Z1
      GO TO 505
   21 IF(M2.NE.5) GO TO 10
      DPVALU=-Z1
  505 XAXIS=Z0
      YAXIS=Z1
   22 CONTINUE
   31 CALL CHKRET(IHU,RAD,INTRCT,D,L)
      IF(INTRCT) 42,42,400
  400 DIS=-(L(1)*D(IHU)+L(2)*D(IHU+1)-SAVD6)
      CALL TRANRO(L(1),L(2),XF,YF,RA,IZ)
      X1PLIN=XF*DIS
      Y1PLIN=YF*DIS
C
C.....CHECK FOR VERTICAL PARALLEL LINE IN LOCAL SYSTEM
C
      IF(DABS(YF).GT.Z1EM7) GO TO 501
  500 SLPLIN =9.0D+7
      GO TO 502
  501 SLPLIN =-XF/YF
  502 BPLIN=Y1PLIN-SLPLIN*X1PLIN
      KOUNT=1
      KCHECK=0
C
C.....DIVISION OF TABCYL INTERVAL INTO 10 EQUAL PARTS.
C
   64 IF(IBACFG.EQ.0) GO TO 105
      XSTART=XBB
      XLENTH=-XBB
      GO TO 107
  105 XSTART=Z0
      XLENTH=XBB
  107 KOUNT=2
      GO TO 67
  866 ISAVE=I-1
C
C.....SUBDIVISION OF LIKELY DIVISION.
C
   65 IF(KOUNT-2) 64,103,103
  103 IF(KOUNT-12) 66,66,42
   66 XLENTH=DABS(XN(ISAVE+1)-XN(ISAVE))
  633 XSTART=XN(ISAVE)
      IF(IBACFG.EQ.0) GO TO 111
  109 XLENTH=-XLENTH
  111 KOUNT=KOUNT+1
   67 DELTX=XLENTH/Z10
C
C.....IF LENGTH OF NORMAL VECTOR FROM TABCYL TO PLINE IS LESS THAN
C.....RADSQR MORE=0,WHEN ONE IS FOUND GREATER THAN RADSQR MORE=2
C
  671 MORE=0
C
C.... INDEX OF FIRST VECTOR IN PROPER DIRECTION
C
      IFIRST=-1
C.... INDEX OF LAST VECTOR IN PROPER DIRECTION
      ILAST=-4
C
C.... LESS=5 UNTIL NORMAL VECTOR IS FOUND LESS THAN,THEN LESS=1
C
      LESS=5
      ILESS=0
      IMORE=0
      DO 84 I=1,11
      XI=I-1
      XN(I)=XSTART+XI*DELTX
      YN(I)=D(IHU+2)*XN(I)**3+D(IHU+3)*XN(I)**2-(D(IHU+2)*D(IHU+4)+
     C D(IHU+3))*(D(IHU+4)*XN(I))
      SLOPE= Z3*D(IHU+2)*XN(I)**2+Z2*D(IHU+3)*XN(I)-(D(IHU+2)*D(IHU+4)+
     C D(IHU+3))*D(IHU+4)
      IF(DABS(SLOPE).GE.Z1EM7) GO TO 69
      SLPNOR=-DSIGN(9.0D+7,SLOPE)
      IF(DABS(SLPLIN).GE.9.0D7) GO TO 79
      XINTRS(I)=XN(I)
      YINTRS(I)=SLPLIN*(XINTRS(I))+BPLIN
      GO TO 25
C
C.....SLOPE OF NORMAL AT EACH POINT IS SLPNOR
C
   69 SLPNOR=-Z1/SLOPE
   70 BNLIN=YN(I)-SLPNOR*XN(I)
C
C.....INTERSECTION OF PLINE AND NORMAL TO TABCYL AT EACH TABCYL
C.....DIVISION POINT.
      XINTRS(I)=((BNLIN-BPLIN)/(SLPLIN-SLPNOR))
C...
      YINTRS(I)= SLPLIN*XINTRS(I)+BPLIN
   25 VECNRX=XINTRS(I)-XN(I)
      VECNRY=YINTRS(I)-YN(I)
      CC=IZ
      AXISXV=XAXIS*DCOS(RA)-CC*YAXIS*DSIN(RA)
      AXISYV= CC*XAXIS*DSIN(RA)+YAXIS*DCOS(RA)
C
C.....CHECK TO SEE IF TABCYL MODIFIER IS ACCEPTABLE FOR THIS NORMAL
C
      DOTP=VECNRX*AXISXV+VECNRY*AXISYV
      IF((DPVALU*DOTP).LE.Z1EM5) GO TO 79
C
C.....LENGTH OF NORMAL VECTOR FROM TABCYL POINT TO PLINE
C
   80 VECNRL(I)=VECNRX**2+VECNRY**2
      IF(IFIRST) 183,183,184
  183 IFIRST=I
  184 ILAST=I
C
C.....HAVE WE FOUND LOCATION OF CIRCLE CENTER
C
      IF(DABS(VECNRL(I)-RADSQR)-EPSILN)83,83,82
   82 IF(VECNRL(I)-RADSQR) 85,83,86
   85 LESS=1
      ILESS=I
      GO TO 876
   86 MORE=2
      IMORE=I
C
C.....DO WE HAVE ONE VECTOR GREATER AND ONE SMALLER THAN RADSQR
C
  876 IF(MORE.LE.LESS) GO TO 84
C
C.....YES-ARE THEY ADJACENT
C
  890 IF(IABS(ILESS-IMORE)-K1) 878,878,84
C
C.....YES-HAVE SUBDIVISIONS BECOME SMALL ENOUGH TO ASSUME
C.....PERPENDICULARITY
C
  878 IF(DABS(XN(1)-XN(2))-Z1EM7) 5500,5500,866
   79 VECNRL(I)=-1.0
   84 CONTINUE
C
C.....UTILIZE TABPNT SUBROUTINE TO FIND THE INTERSECTION OF THE PARALLEL
C.....LINE AND THE TABCYL.
      IF(ITBPNT.NE.0) GO TO 867
C..
C..   DD(1),DD(2) ARE UV CORDINATE OF INTERSECTION
C..   DD(3)       SUBSCRIPT OF D LOCATION AT WHICH THE DATA BEGINS
C..               FOR THE TABCYL INTERVAL IN WHICH THE INTERSECTION
C..               POINT WAS FOUND
C
C
C
C
C
      J111=J11
      SUBFLG =.TRUE.
      CALL APT011(DD,L,TAB,PT)
      J11=J111
C
      ITBPNT=1
      IF(IERROR) 621,600,621
  600 IHUINT=D(J11+13)+0.1+J11
      XXAA=D(IHUINT+7)-D(IHUINT)
      YYAA=D(IHUINT+8)-D(IHUINT+1)
      IIZZ=K1
      RRA=-DATAN(YYAA/SMAL(XXAA))
      IF(XXAA.LT.Z0) RRA=RRA+PI
      CALL TRANRO(DD(1),DD(2),UINT,UINT2,RRA,IIZZ)
      IERROR=0
      SAUINT=UINT
      SAVXBB=DSQRT((D(IHUINT+7)-D(IHUINT))**2+(D(IHUINT+8)-D(IHUINT+1))
     C  **2)
C
C.....IS THIS INTERVAL WITHIN ONE ON EITHER SIDE OF
C.....INTERVAL OF INTERSECTION
C
  867 IF(IABS(IHU-IHUINT)-7) 800,800,621
C
C.... IT IS WITHIN ONE-IS IT BEFORE,IN,OR AFTER THE INTERSECTION
C.... INTERVAL
C
  800 IF(IHU-IHUINT) 809,801,802
  809 IF(DABS(SAUINT)-Z1EM6) 803,803,621
  803 UINT=XBB
      GO TO 602
  801 UINT=SAUINT
      GO TO 602
  802 IF(DABS(SAUINT-SAVXBB)-Z1EM6) 806,806,621
  806 UNIT=Z0
  602 CSLOPE=Z3*D(IHU+2)*UINT**2+Z2*D(IHU+3)*UNIT-(D(IHU+2)*D(IHU+4)+
     C D(IHU+3))*D(IHU+4)
C
C.....TEST FOR LINE PERPENDICULAR TO TABCYL
C
      IF(DABS(SLPLIN)-0.000015) 6073,6073,6071
 6071 IF(DABS(CSLOPE)-0.000015) 6075,6072,6072
 6075 IF(DABS(SLPLIN)-99000.) 6073,6070,6070
 6072 COSTHA=((SLPLIN*CSLOPE)+Z1)/(DABS(SLPLIN*CSLOPE))
      IF(DABS(COSTHA)-DMIN1(Z1EM3,DELTA)) 6070,6070,6073
C
C.....LINE NOT PERPENDICULAR TO TABCYL
C
 6073 IF(KCHECK-1) 6074,603,6074
 6074 IF(KOUNT-12) 180,180,42
 6070 IF(DABS(L(2))-Z1EM7) 651,651,650
  651 XCOMP=Z0
      YCOMP=RAD
      CLOPE=9999999.
      GO TO 652
  650 CLOPE=-L(1)/L(2)
      XCOMP=DSQRT(RADSQR/(Z1+CLOPE**2))
      YCOMP=DABS(CLOPE*XCOMP)
  652 IZ=-K1
      XAA=D(IHU+7)-D(IHU)
      YAA=D(IHU+8)-D(IHU+1)
      RA=-DATAN(YAA/SMAL(XAA))
      IF(XAA) 1002,1003,1003
 1002 RA=RA+PI
 1003 CALL TRANRO(DD(1),DD(2),PX,PY,RA,IZ)
      IF(M2-2) 608,609,610
  608 RESULT(1)=D(IHU)+PX+XCOMP
      RESULT(2)=D(IHU+1)+PY+DSIGN(YCOMP,CLOPE)
      GO TO 613
  609 RESULT(1)=D(IHU)+PX-XCOMP
      RESULT(2)=D(IHU+1)+PY-DSIGN(YCOMP,CLOPE)
      GO TO 613
  610 IF(M2.EQ.5) GO TO 612
      RESULT(1)=D(IHU)+PX+DSIGN(XCOMP,CLOPE)
      RESULT(2)=D(IHU+1)+PY+YCOMP
      GO TO 613
  612 RESULT(1)=D(IHU)+PX-DSIGN(XCOMP,CLOPE)
      RESULT(2)=D(IHU+1)+PY-YCOMP
      GO TO 613
C
C....
C.... THIS SECTION IS FOR THE CASE WHERE THE RADIUS OF CURVATURE OF THE
C.... TABCYL IS SMALL,AND THE NORMALS FROM POINTS VERY CLOSE TOGETHER
C.... ON THE TABCYL HIT THE STRAIGHT LINE UPON WHICH THE CIRCLE CENTER
C.... IS TO LIE AT POINTS THAT ARE A SIGNIFICANT DISTANCE APART.
C
 5500 IF(DABS(XN(1)-DD(1))-Z1EM7) 6070,6070,5501
 5501 XP = (XN(I) + SLPLIN*(YN(I)-BPLIN))/(SLPLIN**2+Z1)
      YP = (SLPLIN*(XN(I)+SLPLIN*YN(I))+BPLIN)/(SLPLIN**2+Z1)
      DISP = ((XN(I)-XP)**2+(YN(I)-YP)**2)
      DMOVE = RADSQR-DIST
      XMOVE = DSQRT(DMOVE/(Z1+SLPLIN**2))
      YMOVE = DABS(SLPLIN*XMOVE)
      IF(IMORE.GT.ILESS) GO TO 5503
      XLONG=XINTRS(I-1)
      YLONG=YINTRS(I-1)
      GO TO 5505
 5503 XLONG=XINTRS(I)
      YLONG=YINTRS(I)
 5505 IF(XLONG.GT.XP) GO TO 27
      XINTRS(I)=XP-XMOVE
      GO TO 28
   27 XINTRS(I)=XP+XMOVE
   28 IF(YLONG.GT.YP) GO TO 30
      YINTRS(I)=YP-YMOVE
      GO TO 83
   30 YINTRS(I)=YP+YMOVE
      GO TO 83
C
C.....CHECK FOR A HUMP OR VALLEY WHERE THE SUCCESSIVE VECTOR LENGTHS
C.....CHANGE FROM INCREASING TO DECREASING OR VICE VERSA
C
  621 INCRES=0
      IDECRS=0
      IERROR=0
  199 DO 630 I=1,11
      IF(I-9) 622,622,42
  622 IF(VECNRL(I)) 630,625,625
  625 IF(VECNRL(I+1)) 630,6251,6251
 6251 IF(VECNRL(I+2)) 630,6252,6252
 6252 IF(VECNRL(I+1)-VECNRL(I)) 626,630,627
  626 IDECRS=1
      GO TO 6271
  627 INCRES=1
 6271 IF(VECNRL(I+2)-VECNRL(I+1)) 628,630,629
  628 IDECRS=1
      GO TO 6291
  629 INCRES=1
 6291 IF(INCRES-IDECRS) 630,631,630
  630 CONTINUE
      GO TO 42
  631 IF(KOUNT-12) 632,632,42
  632 IF(KOUNT-12) 634,196,196
  634 XLENTH=DABS(XN(I+2)-XN(I))
      ISAVE=I
      GO TO 633
C
C.....SUBDIVIDED BETWEEN ADJACENT GOOD AND BAD VECTORS
C
  180 IF(IFIRST) 603,603,186
  186 IF(VECNRL(IFIRST)-VECNRL(ILAST)) 181,193,185
  182 IF(IFIRST-1) 196,196,187
  187 IF(IFIRST-11) 188,196,196
  188 I=IFIRST-1
      GO TO 632
  185 IF(LESS-1) 189,182,189
  189 IF(ILAST-11) 190,196,196
  190 I=ILAST-1
      GO TO 632
  181 IF(LESS-1) 182,189,182
  193 IF(IFIRST-1) 191,191,194
  194 IF(ILAST-11) 188,192,192
  191 I=2
  195 IF(KOUNT-12) 866,196,196
  196 IF(KCHECK-1) 197,42,42
  197 KCHECK=1
      KOUNT=1
      GO TO 64
  192 I=11
      GO TO 195
  618 IF(KOUNT-12) 619,619,42
C
C.....SUBDIVIDE AROUND THE INTERSECTION OF PARALLEL LINE AND TABCYL
C
  619 IF(I-2) 720,720,721
  720 ISAVE=I-1
  724 XLENTH=DABS(XN(ISAVE+2)-XN(ISAVE))
      GO TO 633
  721 ISAVE=I-2
      IF(I-11) 722,724,724
  722 XLENTH=DABS(XN(ISAVE+3)-XN(ISAVE))
      GO TO 633
  603 DO 605 I=2,11
      IF(IBACFG) 604,604,606
  604 IF(UNIT-Z1EM6-XN(I)) 618,618,605
  606 IF(UNIT+Z1EM6-XN(I)) 605,618,618
  605 CONTINUE
C
C.....SET-UP RE-TRY IN ANOTHER INTERVAL UNTIL 3 INTERVALS ON EACH SIDE
C.....OF THE ESTIMATED INTERVAL HAVE BEEN TRIED----A TOTAL OF 7
C.....INTERVALS.(EXTENSION INTERVALS ARE INCLUDED)
C
   42 IF(ICOUNT-7) 422,43,43
  422 IZ=-K1
      XAA=D(IHU+7)-D(IHU)
      YAA=D(IHU+8)-D(IHU+1)
      RA=-DATAN(YAA/SMAL(XAA))
      IF(XAA) 1004,330,330
 1004 RA=RA+PI
  330 IF(MOD(ICOUNT,2)) 301,300,301
  300 IHU=IHU+7*ICOUNT
      IBACFG=0
      ICOUNT=ICOUNT+1
      IF(IHU-ITL) 72,340,340
  301 IHU=IHU-7*ICOUNT
      IBACFG=1
      ICOUNT=ICOUNT+1
      IF(IHU-ITFR) 350,350,72
  340 LOUT=1
      GO TO 330
  350 ILOUT=1
      IF(LOUT-ILOUT) 330,43,330
   43 IERROR=77
      GO TO 9999
   72 IZ=1
      XAA=D(IHU+7)-D(IHU)
      YAA=D(IHU+8)-D(IHU+1)
      RA=-DATAN(YAA/SMAL(XAA))
      IF(XAA) 1005,1006,1006
 1005 RA=RA+PI
 1006 CALL TRANRO(XAA,YAA,XBB,YBB,RA,IZ)
      GO TO 31
   83 X11=XINTRS(I)
      Y11=YINTRS(I)
C
C.....CENTER FOUND, PUT IT BACK INTO ORIGINAL COORDINATE SYSTEM AND PUT
C.....CANONICAL FORM OF CIRCLE IN DEFANS BLOCK.
C
   50 IZ=-1
      XAA=D(IHU+7)-D(IHU)
      YAA=D(IHU+8)-D(IHU+1)
      RA=-DATAN(YAA/SMAL(XAA))
      IF(XAA) 1007,1008,1008
 1007 RA=RA+PI
 1008 CALL TRANRO(X11,Y11,XA,YA,RA,IZ)
      R(1)=D(IHU)+XA
      R(2)=D(IHU+1)+YA
  613 R(7)=RAD
      CALL APT083(R,KM1)
 9999 CALL DEFEXT(RESULT)
   51 CONTINUE
      RETURN
 9998 IERROR=79
      GO TO 9999
       END
