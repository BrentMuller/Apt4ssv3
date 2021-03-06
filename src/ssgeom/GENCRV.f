**** SOURCE FILE : M0001505.V08   ***
*
      SUBROUTINE GENCRV(A,CONCHK,AVERG,TYPE,IERROR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---     MAIN SUBROUTINE FOR CREATING GENCUR SURFACE
C---     INPUT CANONICAL FORM A(2) FOR SURFACE TO BE DEFINED
C---     CONCHK,AVERG,TYPE ARE 3 ARGUMENTS PASSED TO APT107
C---     PART PROGRAMMER INPUT STREAM IS IN CANON(41 ON)
C---     SURFACE UP TO BUT NOT INCLUDING TOPOLOGY TABLE IS
C---     DEFINED IN CANON(41) ON.  SSPAD IS USED AS A SCRATCH
C---     AREA FOR READING CURVES AND MANIPULATING THEM.
C---     OUTPUT IERROR IS NOT ZERO FOR AN ERROR
C---     MAIN OUTPUT IS IN CANON(41 ON)
C
C---     BLANK COMMON CAN CONTAINS THE PART PROGRAMMERS INPUT
C---     THIS IS TRANSFERRED TO THE ARRAY SCAN AND THEN CAN IS
C---     USED TO BUILD UP THE CANON FORM OF THE GENCUR SURFACE
C---     THE AVAILABLE SIZE OF CAN IS HELD IN MAXLDA
C
      INCLUDE 'BLANKCOM.INC'
C
      COMMON/MAXLDA/MAXLDA
C
C---     THE SCAN ARRAY IS USED AS A WORKING BUFFER OF TEMPORARY
C---     DATA.  IT HOLDS THE PP INPUT AND VARIOUS INPUT CURVES.
C---     NSCNMX IS THE MAXIMUM SPACE IN SCAN AND ISCAN POINTS
C---     TO THE LAST USED LOCATION IN SCAN.
      INCLUDE 'SSPAD.INC'
C
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      LOGICAL CKDEF
      LOGICAL CR
      CHARACTER*8 CRASS
      CHARACTER*8 TEST
      DIMENSION NLOC(100)
      DIMENSION VECA(3),VECB(3),PP(3),CV(32)
C---     NLOC HOLDS POINTERS TO THE LOCATIONS OF SPLINE AND
C---     CROSS CURVES HELD IN THE SCAN ARRAY. NC IS THE LAST
C---     USED LOCATION IN NLOC AND NCMAX IS THE SIZE OF NLOC
      DATA NLOC/100*0/,NCMAX/100/
      DATA CRASS/'CROSS   '/
C
C
      DATA ZERO,ONE,SMAL/0.0D0,1.0D0,0.000001D0/
C
C---     INITIALIZE VARIOUS POINTERS AND COUNTERS
C---     CR IS TRUE IF CROSS SPLINE CURVES ARE ENTERED
      CR=.FALSE.
C---     NUMSPL IS THE TOTAL NUMBER OF INPUT SPLINE CURVES
      NUMSPL=0
C---     NUMCRS IS THE TOTAL NUMBER OF INPUT CROSS CURVES
      NUMCRS=0
C---     ISCAN IS THE POINTER TO THE LAST USED SPACE IN SCAN ARRAY
      ISCAN=0
C---     NSEG IS THE TOTAL NUMBER OF SEGMENTS PER INPUT CURVE
      NSEG=0
C---     NC IS THE POINTER TO THE LAST USED SPACE IN NLOC
      NC=0
C---     NLEN IS THE TOTAL LENGTH OF PART PROGRAMMER INPUT DATA
      NLEN=CAN(5)
C---     TRANSFER PART PROGRAMMERS INPUT TO THE SCAN ARRAY
      DO 10 I=1,NLEN
      SCAN(I)=CAN(I)
      CAN(I)=ZERO
   10 CONTINUE
      ISCAN=NLEN
C
C---     ISX WILL BE AN INDEX FOR SEARCHING THE SCAN ARRAY
      ISX=9
  100 CONTINUE
      IF(ISX.GE.NLEN) GO TO 199
C---     DATA SHOULD REPRESENT EITHER AN SCURV OR THE WORD CROSS
      CALL HOLFRM(SCAN(ISX+1),TEST,1,8,NWD)
      IF(TEST.NE.CRASS) GO TO 110
C---     THE WORD CROSS HAS BEEN ENCOUNTERED
C****    THE WORD CROSS WAS ENCOUNTERED TWICE
      IERROR=05
      IF(CR) GO TO 9998
C****    LESS THAN TWO SPLINE CURVES WERE INPUT BEFORE CROSS
      IERROR=06
      IF(NUMSPL.LT.2) GO TO 9998
C---     SAVE THE STARTING INDEX TO CROSS CURVE DATA
      ISXSAV=ISX+2
      CR=.TRUE.
      GO TO 198
C
C---     A CURVE HAS BEEN ENCOUNTERED
  110 CONTINUE
      IF(.NOT.CKDEF(SCAN(ISX))) GO TO 120
C****    INPUT CURVE HAS NOT BEEN DEFINED CORRECTLY
      IERROR=07
      GO TO 9998
  120 CONTINUE
      IF(NUMSPL.GT.0) GO TO 130
C---     LOAD THE FIRST CURVE ONLY
      JMODE=2
      CALL APT094(JMODE,SCAN(ISX),SCAN(ISCAN+1))
C****    CURVE COULD NOT BE SUCCESSFULLY RETRIEVED
      IERROR=08
      IF(JMODE.NE.2) GO TO 9998
C---     ENTER CURVE LOCATION INTO DIRECTORY TABLE
      NC=NC+1
      NLOC(NC)=ISCAN+1
C---     OBTAIN SEGMENT COUNT FROM THIS CURVE
      NSEG=SCAN(ISCAN+8)
      ISCAN=ISCAN+SCAN(ISCAN+12)
C****    FIRST INPUT CURVE WAS NOT OF THE FLOW TYPE
      IERROR=09
      IF(NSEG.LT.1) GO TO 9998
  130 CONTINUE
      IF(.NOT.CR) NUMSPL=NUMSPL+1
      IF(CR) NUMCRS=NUMCRS+1
  198 CONTINUE
      ISX=ISX+2
      GO TO 100
  199 CONTINUE
C
C---     NOW BEGIN PREPARATION OF THE SURFACE CANON FORM IN CAN
C---     ALL INPUT CURVES MUST BE LOADED INTO THE SCAN ARRAY
      NUMPAT=(NUMSPL-1)*NSEG
      J=10+NUMPAT*6
      DO 210 I=1,J
  210 CAN(I)=ZERO
      CAN(3)=NUMPAT*4
      CAN(4)=NUMPAT
      CAN(5)=2.
      CAN(6)=5.
      CAN(7)=ONE
      CAN(9)=NUMSPL
      CAN(10)=NSEG+1
C
C---     THIRD PHASE, LOAD ALL OF THE SPLINE CURVES INTO THE SCAN ARRAY
C---     SKIP THE FIRST CURVE, SINCE IT HAS ALREADY BEEN LOADED
      ISX=9+2
  300 CONTINUE
      CALL HOLFRM(SCAN(ISX+1),TEST,1,8,NWD)
      IF(TEST.EQ.CRASS.OR.ISX.GE.NLEN) GO TO 399
C****    THE CURVE DIRECTORY TABLE SIZE HAS BEEN EXCEEDED
      IERROR=10
      IF(NC+1.GT.NCMAX) GO TO 9998
C---     CONSIDER THE ANTICIPATED SIZE OF THIS CURVE
      ISIZE=SCAN(ISX+1)
C****    THERE IS NOT ENOUGH BUFFER SPACE TO HOLD THIS SPLINE CURVE
      IERROR=11
      IF(ISIZE+ISCAN.GT.NSCNMX) GO TO 9998
      JMODE=2
      CALL APT094(JMODE,SCAN(ISX),SCAN(ISCAN+1))
C****    INPUT SPLINE CURVE COULD NOT BE FETCHED
      IERROR=12
      IF(JMODE.NE.2) GO TO 9998
      ISEG=SCAN(ISCAN+8)
C****    THE NUMBER OF SEGMENTS IN TWO INPUT SPLINE CURVES WAS UNEQUAL
      IERROR=13
      IF(ISEG.NE.NSEG) GO TO 9998
C---     UPDATE DIRECTORY TABLE OF CURVE LOCATION
      NC=NC+1
      NLOC(NC)=ISCAN+1
      ISCAN=ISCAN+SCAN(ISCAN+12)
  390 CONTINUE
      ISX=ISX+2
      GO TO 300
C
  399 CONTINUE
C
C---     PHASE 4.  ONE-BY-ONE LOAD CROSS CURVES INTO SCAN ARRAY
C---     AND COMPARE THEM TO SPLINE JUNCTIONS TO DETERMINE
C---     THEIR RELATIVE LOCATION.
C---     FIRST, ZERO OUT THIS PART OF THE DIRECTORY TABLE
C****    THERE IS NOT ENOUGH ROOM IN THE DIRECTORY FOR CROSS CURVES
      IERROR=14
      IF(NC+NSEG+1.GT.NCMAX) GO TO 9998
C---     ZERO OUT THE CROSS PORTION OF THE DIRECTORY TABLE
      NSEG1=NSEG+1
      DO 401 I=1,NSEG1
      NLOC(I+NUMSPL)=0
  401 CONTINUE
C---     THE NEXT SECTION IS TO READ IN CROSS CURVES
C---     IF THERE ARE NO CROSS CURVES, SKIP THIS SECTION
      IF(.NOT.CR.OR.NUMCRS.LT.1) GO TO 500
C
C---     BEGIN LOADING CROSS CURVES (FROM THE PREVIOUS SAVE POINT)
      ISX=ISXSAV
C
  420 CONTINUE
      IF(ISX.GE.NLEN) GO TO 499
      ISIZE=SCAN(ISX+1)
C****    THERE IS NOT ENOUGH BUFFER SPACE TO LOAD A CROSS CURVE
      IERROR=15
      IF(ISIZE+ISCAN.GT.NSCNMX) GO TO 9998
      JMODE=2
      CALL APT094(JMODE,SCAN(ISX),SCAN(ISCAN+1))
C****    CROSS CURVE COULD NOT BE FETCHED
      IERROR=16
      IF(JMODE.NE.2) GO TO 9998
      ISEG=SCAN(ISCAN+8)
C****    NUMBER OF SEGMENTS IN CROSS CURVE DID NOT MATCH NO. SPLINES
      IERROR=17
      IF(ISEG+1.NE.NUMSPL) GO TO 9998
C
C---     A MAJOR TASK- IDENTIFY WHICH CROSS CURVE THIS IS.
C---     ISPL IS THE PREVIOUS SPLINE POINT WHICH MATCHED A
C---     CROSS CURVE POINT
      ISPL=1
  429 CONTINUE
C---     ICRS IS THE PRESENT POINT ON THE CROSS CURVE BEING EXAMINED
      ICRS=1
  430 CONTINUE
      IF(ICRS.GT.NUMSPL) GO TO 469
C---     CALCULATE THE CURVE POINT
      U=ICRS-1
      CALL CURFLO(U,SCAN(ISCAN+1),CV,0,0)
      DO 431 I=1,3
  431 PP(I)=CV(I)
C---     NOW SCAN THRU THE ICR-TH SPLINE FOR A MATCH ON PP
      NL=NLOC(ICRS)
      NSP=ISPL
  440 CONTINUE
      IF(NSP.GT.NSEG1) GO TO 459
      U=NSP-1
      CALL CURFLO(U,SCAN(NL),CV,0,0)
      W=DABS(CV(1)-PP(1))+DABS(CV(2)-PP(2))+DABS(CV(3)-PP(3))
      IF(W.GT.0.0001) GO TO 458
C---     JUNCTION POINTS OF CROSS CURVE AND SPLINE MATCH HERE
      IF(NSP.EQ.ISPL) GO TO 468
C---     UPDATE ISPL AND RESTART
      ISPL=NSP
      GO TO 429
C
  458 CONTINUE
      NSP=NSP+1
      GO TO 440
C
  459 CONTINUE
C****    THERE IS NO MATCH AT A JUNCTION PT BETWEEN A SPLINE AND CROSS
      IERROR=18
      GO TO 9998
C
  468 CONTINUE
      ICRS=ICRS+1
      GO TO 430
  469 CONTINUE
C---     MATCH HAS BEEN ACHIEVED, CROSS CURVE IS NUMBER ICRS
C****    ERROR, ANOTHER CROSS CURVE WAS ENTERED THRU SAME POINTS
      IERROR=19
      IF(NLOC(NUMSPL+ISPL).NE.0) GO TO 9998
      NLOC(NUMSPL+ISPL)=ISCAN+1
      ISCAN=ISCAN+SCAN(ISCAN+12)
      ISX=ISX+2
      GO TO 420
C
  499 CONTINUE
C
  500 CONTINUE
C---     ALL CROSS CURVES HAVE BEEN SAVED , NOW GENERATE
C---     ALL  CROSS CURVES NOT INPUT BY USER
C
C---     FIRST CHECK WHETHER A RULED SURFACE IS INDICATED
      IF(NUMSPL.NE.2.OR.NUMCRS.GT.0) GO TO 600
C
C---     PHASE 5.  DEFINTION OF A RULED SURFACE.
C---     THE SURFACE IS RULED PROVIDED THAT NO CROSS SPLINE
C---     OR NORMAL CONSTRAINTS EXIST
      DO 510 I=1,NUMSPL
      NL=NLOC(I)-1
      NLOC1=SCAN(NL+2)*24.-4.+NL
      NLOC2=NLOC1+24.*SCAN(NL+4)
      DO 520 J=NLOC1,NLOC2,24
      W=DABS(SCAN(J)-ONE)
      IF(W.LT.SMAL) GO TO 600
      W=DABS(SCAN(J+4)-ONE)
      IF(W.LT.SMAL) GO TO 600
  520 CONTINUE
  510 CONTINUE
C
C---     ALL CONDITIONS FOR A RULED SURFACE HAVE BEEN MET
C---     FINISH THE DEFINITION OF THE RULED SURFACE NOW
      NUMPAT=NSEG
      ICAN=6*NSEG+10
C
C---     DISSECT CURVES INTO SEGMENT CURVES AND SET UP RULED PATCHES
      DO 530 I=1,NSEG
      ILOC=10+6*(I-1)
      DO 540 J=1,NUMSPL
      NL=NLOC(J)
      ICANMX=MAXLDA-ICAN
      CALL DISEG(I,SCAN(NL),CAN(ICAN+1),ICANMX,IERROR)
C****    ERROR IN DISSEGMENTING CURVE
      IF(IERROR.NE.0) GO TO 9998
      ILOC=ILOC+1
      CAN(ILOC)=ICAN+1
      ICAN=ICAN+CAN(ICAN+12)
  540 CONTINUE
C---     TYPE FLAG INDICATES A BLEND BETWEEN TWO SPLINES
      CAN (ILOC+3)=-1.
      CAN(ILOC+4)=ZERO
  530 CONTINUE
      CAN(2)=ICAN-(6*NSEG+11)
      CAN(8)=CAN(2)+CAN(3)+(6*NUMPAT+10)
C
C
      GO TO 9997
C
C---     CROSS FIT LIKE SEGMENT JUNCTION POINTS TO OBTAIN GOOD
C---     CROSS SLOPE CONSTRAINTS
  600 CONTINUE
      I=1
  610 CONTINUE
      IF(I.GT.NSEG1) GO TO 699
C---     IF A CROSS CURVE HAS ALREADY BEEN ENTERED, SKIP TO NEXT JNCT.
      IF(NLOC(NUMSPL+I).NE.0) GO TO 690
C---     CHECK FOR AVAILABLE SPACE TO FIT CROSS CURVE
      NSIZE=(NUMSPL+1)*24
C****    THERE IS NOT ENOUGH ROOM IN THE BUFFER TO FIT THIS CROSS CURVE
      IERROR=20
      IF(NSIZE+ISCAN.GT.NSCNMX) GO TO 9998
      U=ZERO
      ISEG=I
      IF(I.GT.NSEG) U=ONE
      ISEG=MIN0(NSEG,I)
      J=1
C---     PREPARE THE INPUT CURVE HEADER TABLE
      DO 615 L=1,24
  615 SCAN(ISCAN+L)=ZERO
      SCAN(ISCAN+2)=ONE
      SCAN(ISCAN+3)=2.
      SCAN(ISCAN+4)=NUMSPL
  620 CONTINUE
C---     LOAD SPLINE CURVES ONE AT A  TIME TO OBTAIN POINT OR
C---     VECTOR DATA AT JUNCTION POINTS I
      IF(J.GT.NUMSPL) GO TO 650
C---     SET ADDRESS OF SPLINE J
      NL=NLOC(J)-1
      CALL CURFLO(U,SCAN(NL+1),CV,2,ISEG)
C---     MOVE RELEVANT POINTS AND VECTOR CONSTRAINTS INTO BUFFER
      NBASE=J*24+ISCAN
C---     ZERO OUT THE J-TH POINT BLOCK FIRST
      DO 630 L=1,24
  630 SCAN(NBASE+L)=ZERO
      DO 640 L=1,3
      SCAN(NBASE+L)=CV(L)
      IF(DABS(CV(20)-ONE).LT.SMAL) SCAN(NBASE+4+L)=CV(L+16)
      IF(DABS(CV(32)-ONE).LT.SMAL) SCAN(NBASE+12+L)=CV(L+28)
      SCAN(NBASE+8+L)=CV(L+4)
  640 CONTINUE
      IF(DABS(CV(20)-ONE).LT.SMAL) SCAN(NBASE+8)=ONE
      IF(DABS(CV(32)-ONE).LT.SMAL) SCAN(NBASE+16)=ONE
      SCAN(NBASE+12)=ONE
      SCAN(NBASE+17)=ONE
C
      J=J+1
      GO TO 620
C---
  650 CONTINUE
      IF(IBUG.EQ.11) CALL SCDUMP(650,SCAN(ISCAN+1))
C---     NOW DEFINE A SYNTHETIC CURVE IN THE CROSS DIRECTION
      IRR=0
      CALL SCURV(SCAN(ISCAN+1),IRR)
C****    ERROR IN TRYING TO DEFINE A CROSS CURVE
      IERROR=21
      IF(IRR.NE.0) GO TO 9998
C
      SCAN(ISCAN+5)=SCAN(ISCAN+2)*24.+ONE
      SCAN(ISCAN+12)=NUMSPL*24.
C---     IF CROSS CURVES HAVE BEEN INPUT BY THE USER, THEN INTERNALLY
C---     GENERATED CROSS CURVES MUST HAVE A FLOW STRUCTURE APPENDED
C
      IF(NUMCRS.LT.1) GO TO 680
C
C---     NOW APPEND AN IDENTITY-TYPE FLOW STRUCTURE
      NSIZE=ISCAN+NUMSPL*40
C****    THERE IS NOT ENOUGH ROOM FOR FLOW STRUCTURE OF A CROSS CURVE
      IERROR=23
      IF(NSIZE.GT.ICANMX) GO TO 9998
C
C---     NOW SETUP THE COMPLETE HEADER TABLE FOR A FLOW CURVE
      SCAN(ISCAN+5)=25+ISCAN
      SCAN(ISCAN+6)=NUMSPL-1
      SCAN(ISCAN+7)=NUMSPL*24+1
      SCAN(ISCAN+8)=SCAN(ISCAN+6)
      SCAN(ISCAN+9)=SCAN(ISCAN+7)+(NUMSPL-1)*4
      SCAN(ISCAN+10)=2*(NUMSPL-1)
      SCAN(ISCAN+11)=SCAN(ISCAN+9)+(NUMSPL-1)*4
      SCAN(ISCAN+12)=SCAN(ISCAN+11)+(NUMSPL-1)*8
      SCAN(ISCAN+13)=ONE
C---     NOW FILL IN FLOW, SEGMENT, AND FLOW SPLINE DATA
C---     KEEP TRACK OF EACH TYPE OF DATA WITH ITS OWN POINTER.
      NFLOWR=SCAN(ISCAN+7)-5.
      NSEGR=SCAN(ISCAN+9)-5.
      NSPLR=SCAN(ISCAN+11)-9.
C---     LOOP THRU SEGMENT BY SEGMENT AND FILL IN FLOW DATA
      NN=NUMSPL-1
      DO 660 L=1,NN
C---     INCREMENT SEGMENT POINTERS
      NFLOWR=NFLOWR+4
      NSEGR=NSEGR+4
      NSPLR=NSPLR+8
C---     FILL IN FLOW DATA FOR THE L-TH ARC
      SCAN(NFLOWR+1)=NSPLR
      SCAN(NFLOWR+2)=2.
      SCAN(NFLOWR+3)=4.0001
      SCAN(NFLOWR+4)=ONE
C---     FILL IN SEGMENT SUMMARY DATA
      SCAN(NSEGR+1)=L-1
      SCAN(NSEGR+2)=L
      SCAN(NSEGR+3)=ONE
      SCAN(NSEGR+4)=ONE
C---     FIRST SET UP AN IDENTITY FLOW SPLINE
      SCAN(NSPLR+1)=ZERO
      SCAN(NSPLR+2)=ZERO
      SCAN(NSPLR+3)=ONE
      SCAN(NSPLR+4)=ZERO
      SCAN(NSPLR+5)=ONE
      SCAN(NSPLR+6)=ONE
      SCAN(NSPLR+7)=ONE
      SCAN(NSPLR+8)=ZERO
  660 CONTINUE
C
  680 CONTINUE
C
C---     CONSOLIDATE THIS CROSS CURVE INTO THE BUFFER AREA
      NLOC(NUMSPL+I)=ISCAN+1
C
      IF(NUMCRS.LT.1) ISCAN=ISCAN+24*NUMSPL
      IF(NUMCRS.GT.0) ISCAN=ISCAN+SCAN(ISCAN+12)
C
  690 CONTINUE
      I=I+1
      GO TO 610
C
  699 CONTINUE
C---     NOW ADD CROSS VECTORS AT ALL UNSPECIFIED POINTS
C---    THIS IS ACCOMPLISHED BY CROSS SPLINING THE SURFACE FOR
C---    FOR EACH AND EVERY USER INPUT POINT.
C
C---    FIRST CHECK FOR STORAGE SPACE
      NSIZE=ISCAN+(NUMSPL+1)*24
C****    THERE IS NOT ENOUGH ROOM TO DETERMINE CROSS VECTOR BY SPLINING
      IERROR=24
      IF(NSIZE.GT.NSCNMX) GO TO 9998
C
C---     MAJOR LOOP, DETERMINE UNSPECIFIED POINTS ON EACH SPLINE
C---     SKIP THIS LOOP IF THERE ARE ONLY TWO SPLINES
      IF(NUMSPL.LE.2) GO TO 709
C
      DO 710 I=1,NUMSPL
      NL=NLOC(I)-1
C---     EXAMINE EACH JUNCTION POINT OF THE ITH SPLINE
      NJ=SCAN(NL+4)
      IF(NJ.EQ.1) GO TO 721
C
C---     SET UP PARAMETERS FOR DETECTING FLOW JUNCTIONS
      NJFLO=SCAN(NL+6)*4.+ONE
      NJST=SCAN(NL+7)
C
      DO 720 NK=1,NJ
      JUNC=NK
C---     SKIP CROSS CALCULATIONS FOR SEGMENT JUNCTION POINTS
      DO 722 II=1,NJFLO,4
      JUNCLO=SCAN(NL+NJST+II-1)
      JUNCHI=JUNCLO+SCAN(NL+NJST+II)
C---     SKIP CALCULATION IF JUNC EQUALS ONE OF THESE
      IF(JUNC.EQ.JUNCLO.OR.JUNC.EQ.JUNCHI) GO TO 720
C---     TERMINATE SEARCH AND CONTINUE WHEN JUNC IS BIG
      IF(JUNC.GT.JUNCHI) GO TO 723
  722 CONTINUE
C
  723 CONTINUE
C
      LOC=JUNC*24+16
C---     SKIP IF A CROSS VECTOR IS ALREADY THERE
      IF(DABS(SCAN(NL+LOC+4)-ONE).LT.SMAL) GO TO 720
C---     NOW PREPARE THE HEADER TABLE FOR SPLINING
      DO 730 NN=5,24
  730 SCAN(ISCAN+NN)=ZERO
      SCAN(ISCAN+2)=ONE
      SCAN(ISCAN+3)=2.
      SCAN(ISCAN+4)=NUMSPL
C---     FIND THE SEGMENT NUMBER AND FLOW VALUE AT ARC JUNCTIONS
      U=JUNC
      CALL FLOINV(U,SCAN(NL+1),FLO,ISEG)
C---     PICK A POINT OFF OF EACH SPLINE CURVE WITH THIS FLOW
C---     AND SEGMENT VALUE AND PLACE IT INTO A POINT BLOCK OF
C---     THE BUFFERED SCAN ARRAY
C
      DO 740 K=1,NUMSPL
      JSC1=K*24+1
      JSC2=JSC1+23
      DO 750 J=JSC1,JSC2
      SCAN(J+ISCAN)=ZERO
  750 CONTINUE
      SCAN(JSC1+ISCAN+16)=ONE
C---     NOW RETRIEVE A POINT FROM THE K-TH SPLINE
      NKS=NLOC(K)
      CALL CURFLO(FLO,SCAN(NKS),CV,0,ISEG)
      DO 760 J=1,3
  760 SCAN(ISCAN+JSC1+J-1)=CV(J)
  740 CONTINUE
C
C---     NOW FIT A SPLINE THRU THESE POINTS
      CALL SCURV(SCAN(ISCAN+1),IRR)
C****    CROSS FITTING FAILED AT A SEGMENT INTERIOR POINT
      IERROR=25
      IF(IRR.NE.0) GO TO 9998
C---     RETRIEVE AND STORE BOTH THE ENTERING AND EXITING TANGENTS
C---     FIRST STORE THE EXITING VECTOR
      NN=I*24
      U=ZERO
      IF(I.EQ.NUMSPL) NN=NN-24
      IF(I.EQ.NUMSPL) U=ONE
      CALL CNCURV(U,SCAN(ISCAN+1+NN),CV,1)
C---     STORE THIS VECTOR AS A CROSS CONSTRAINT OF THE SPLINE
      DO 770 L=1,3
  770 SCAN(NL+LOC+L)=CV(L+4)
      SCAN(NL+LOC+4)=ONE
C---     NEXT RETRIEVE AND STORE THE ENTERING VECTOR
      U=ONE
      NN=(I-1)*24
      IF(I.EQ.1) U=ZERO
      IF(I.EQ.1) NN=NN+24
      CALL CNCURV(U,SCAN(ISCAN+1+NN),CV,1)
      DO 780 L=1,3
  780 SCAN(NL+LOC+L+4)=CV(L+4)
      SCAN(NL+LOC+8)=ONE
C
  720 CONTINUE
C
  721 CONTINUE
C
  710 CONTINUE
C
  709 CONTINUE
C---     END OF LOOP TO GENERATE CROSS CONSTRAINTS ON SPLINES
C
C
  800 CONTINUE
C---     CASE OF A GENCUR SURFACE WITH NO CROSS SPLINES
C---     FETCH CURVES AND DECOMPOSE SURFACE DEFINITION INTO A
C---     PATCH STRUCTURE
C
      NM=NUMSPL-1
C---     ICAN IS THE LAST USED LOCATION IN THE CAN ARRAY
      ICAN=10+6*NSEG*NM
C
C---     GENERATE SURFACE ON A PATCH-BY-PATCH BASIS
C
      DO 810 J=1,NM
      DO 810 I=1,NSEG
C
      NUMPAT=I+(J-1)*NSEG
C---     ILOC IS THE LAST USED LOCATION IN THE PATCH POINTER TABLE
      ILOC=10+(NUMPAT-1)*6
C
C---     LOAD TWO SPLINE CURVE BOUNDARIES OF THIS PATCH
      DO 820 K=1,2
C
      ICURV=NLOC(J+K-1)
      ICANMX=MAXLDA-ICAN
      CALL DISEG(I,SCAN(ICURV),CAN(ICAN+1),ICANMX,IERROR)
C****    DISSECTION OF A SPLINE CURVE FAILED
      IF(IERROR.NE.0) GO TO 9998
      ILOC=ILOC+1
      CAN(ILOC)=ICAN+1
      ICAN=ICAN+CAN(ICAN+12)
  820 CONTINUE
C
C---     NOW LOAD THE CROSS CURVES IN A SIMILAR FASHION, BUT
C---     DO NOT SAVE THEM UNLESS CROSS CURVES HAVE BEEN ENTERED
C
      ICANSV=ICAN
      DO 830 K=1,2
C
      ICURV=NLOC(NUMSPL+I+K-1)
      ICANMX=MAXLDA-ICAN
      CALL DISEG(J,SCAN(ICURV),CAN(ICAN+1),ICANMX,IERROR)
C****    A CROSS CURVE COULD NOT BE DISSECTED
      IF(IERROR.NE.0) GO TO 9998
      ILOC=ILOC+1
      CAN(ILOC)=ICAN+1
      ICAN=ICAN+CAN(ICAN+12)
  830 CONTINUE
C
C---     NOW COMPLETE ALL BOUNDARY CURVES BY FILLING IN
C---     ALL CROSS VECTORS AT ARC JUNCTIONS
      IA=CAN(ILOC-3)
      IB=CAN(ILOC-2)
      IC=CAN(ILOC-1)
      ID=CAN(ILOC)
C
C---     SPECIAL LOGIC WHERE DUAL(INCOMING AND OUTGOING) TANGENTS
C---     HAVE BEEN GENERATED EARLIER.  SKIP IF 2 OR FEWER SPLINES
      IF(NUMSPL.LT.3) GO TO 839
C
C---     RETAIN EXITING VECTORS FOR CAN(IA) AND ENTERING VECTORS FOR IB.
      NUMJNC=CAN(IA+3)
      IF(NUMJNC.LT.2) GO TO 834
      DO 832 II=2,NUMJNC
      KK=(II-1)*24+15
      DO 833 JJ=1,4
      CAN(IA+KK+4+JJ)=ZERO
  833 CONTINUE
  832 CONTINUE
  834 CONTINUE
C---     NEXT REARRANGE THE ENTERING VECTORS FOR CAN(IB)
      NUMJNC=CAN(IB+3)
      IF(NUMJNC.LT.2) GO TO 838
      DO 836 II=2,NUMJNC
      KK=(II-1)*24+15
      DO 837 JJ=1,4
      CAN(IB+KK+JJ)=CAN(IB+KK+JJ+4)
      CAN(IB+KK+JJ+4)=ZERO
  837 CONTINUE
  836 CONTINUE
  838 CONTINUE
C
  839 CONTINUE
C
C---     NOW FIT ANY UNRESOLVED CROSS VECTORS
C---     SINCE ALL TANGENTS HAVE ALREADY BEEN DETERMINED , SET BYPASS
C---     FLAG FOR CRSFIT LOGIC  --  CRSFIT IS CALLED FOR DISPLAY
      IERROR=0
      IF(NUMSPL.GT.2) IERROR=-11
      CALL CRSFIT(CAN(IA),CAN(IB),CAN(IC),CAN(ID),IERROR)
C****    FILLING IN OF CROSS SLOPES ON SPLINE CURVES FAILED
      IF(IERROR.NE.0) GO TO 9998
C
C---     FILL IN IC ID CURVES IF NUMCRS IS NOT ZERO.
      IF(NUMCRS.GT.0)
     X CALL CRSFIT(CAN(IC),CAN(ID),CAN(IA),CAN(IB),IERROR)
C****    FILLING IN OF CROSS SLOPES ON CROSS CURVES FAILED
      IF(IERROR.NE.0) GO TO 9998
C
C---     NOW FILL IN REMAINDER OF PATCH HEADER TABLE
C
      IF(NUMCRS.GT.0) GO TO 840
C---     FOR SPLINE CURVES ONLY, CUT BACK SPACE FROM CROSS CURVES
      ICAN=ICANSV
      CAN(ILOC-1)=ZERO
      CAN(ILOC)=ZERO
      ILOC=ILOC+1
      CAN(ILOC)=-2.
      ILOC=ILOC+1
      CAN(ILOC)=ZERO
      GO TO 810
C
  840 CONTINUE
      ILOC=ILOC+1
      CAN(ILOC)=-22.
      ILOC=ILOC+1
      CAN(ILOC)=ZERO
C
  810 CONTINUE
C
C---     FILL IN SURFACE HEADER TABLE
C
C---     LAST PATCH,LAST BOUNDARY LOCATION
      ILAST=CAN(10+NUMPAT*6-4)
      IF(NUMCRS.GT.0) ILAST=CAN(10+NUMPAT*6-2)
C---     VALUE TABLE SIZE
      CAN(2)=CAN(ILAST+11)+(ILAST-10-NUMPAT*6-1)
C---     TOPOLOGY TABLE SIZE
      CAN(3)=NUMPAT*4
C---     NUMBER OF PATCHES IN SURFACE
      CAN(4)=NUMPAT
C---     SURFACE TYPE, MESH TYPE
      CAN(5)=2.
C---     SURFACE SUBTYPE, GENCUR
      CAN(6)=5.
C---     SIGN OF SURFACE NORMAL
      CAN(7)=ONE
C---     TOTAL SIZE OF THIS SURFACE
      CAN(8)=(10+NUMPAT*6)+CAN(2)+CAN(3)
C---     NUMBER OF SPLINES
      CAN(9)=NUMSPL
C---     NUMBER OF CROSS SPLINES OR SEGMENT JUNCTION POINTS PER SPLINE
      CAN(10)=NSEG1
C
      IBADSZ=CAN(8)
      IF(IBUG.EQ.11) CALL BAD(IBADSZ,1,'CAN ',CAN)
C
C---     END OF PATCH GENERATING LOOP
C
      GO TO 9997
C
C 900 CONTINUE
C     GO TO 9997
C
 9997 CONTINUE
      IERROR=0
      GO TO 9999
C
 9998 CONTINUE
C---     GENERATE DEBUG PRINTOUT IF IBUG FLAG IS SET
      IF(IBUG.NE.11) GO TO 9996
      CALL BAD(1,0,'IRR ',IRR)
      CALL BAD(1,0,'IERR',IERROR)
      CALL BAD(1,0,'NUMS',NUMSPL)
      CALL BAD(1,0,'ISCN',ISCAN)
      CALL BAD(1,0,'NSEG',NSEG)
      CALL BAD(-1,0,'NLEN',NLEN)
      CALL BAD(-NC,0,'NLOC',NLOC)
      I1=MIN0(MAXLDA,ICAN)
      CALL BAD(-I1,1,'CAN ',CAN(1))
      I1=ISCAN+200
      I1=MIN0(ISCAN,NSCNMX)
      CALL BAD(-I1,1,'SCAN',SCAN)
 9996 CONTINUE
      IERROR=IERROR+5020
      GO TO 9999
C
 9999 CONTINUE
      RETURN
      END
