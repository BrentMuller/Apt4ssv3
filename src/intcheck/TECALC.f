**** SOURCE FILE : TECALC.ORG   ***
*
      SUBROUTINE TECALC(R,TA,U,PSIDE,PTHICK,TOLCOM,TUL,TE)
C
C     PURPOSE: COMPUTE TE GIVEN CURRENT CONTACT POINT R AND TA
C
C
C     ARGUMENTS:
C      R      - INPUT SURFACE CONTACT POINT/DERIVATIVES(SEE CNSURF)
C      TA     - INPUT TOOL AXIS
C      U      - LOCAL FORWARD DIRECTION
C      PSIDE  - INPUT 1 OR -1, DEFINES CUTTER SIDE OF SURFACE
C      PTHICK - PART GEOMETRY THICK SPECIFICATION
C      TOLCOM - TOLERANCE BAND COMPENSATION
C      TUL    - CUTTER PARAMETERS
C      TE     - OUTPUT TOOL END
C
      DOUBLE PRECISION R,TA,U,PSIDE,PTHICK,TOLCOM,TUL,TE
      DIMENSION R(32),TA(3),U(3),TUL(7),TE(3)
C
C     GLOBAL VARIABLES:
C
      INCLUDE 'TLLDAT.INC'
      INCLUDE 'DARRAY.INC'
C
C     LOCAL VARIABLES:
C
C       OFFSET - TOOL OFFSET FROM SURFACE
C       VEC    - TOOL RADIAL AXIS
C       VLEN2  - LENGTH OF VEC SQUARED
C       V,VN   - WORK VECTORS
C       CANG   - COS(ANGLE BETWEEN TOOL NORMAL AND TOOL RADIAL AXES)
C       SANG   - SINE OF SAME ANGLE
C       TANG   - TANGENT OF SAME ANGLE
C       BADMSG - DIAGNOSTIC MESSAGE
C
      DOUBLE PRECISION OFFSET,VEC,VLEN2,V,VN,CANG,SANG,TANG
      DIMENSION VEC(3),V(3),VN(3)
      CHARACTER BADMSG*20
C
C     GENERAL CASE,TOOL OFFSET FROM SURFACE
      OFFSET=PSIDE*(PTHICK+TOLCOM)
C     COMPUTE TOOL RADIAL AXIS
      CALL CROSS(TA,R(29),VEC)
C...IF TA IS PARALLEL TO SN USE U (FWD) TO DETERMINE TOOL RADIAL AXIS
      VLEN2=VEC(1)*VEC(1)+VEC(2)*VEC(2)+VEC(3)*VEC(3)
      IF (VLEN2.LT.1.0D-12) THEN
        CALL CROSSV(TA,U,VEC)
      ELSE
        DO 20 I=1,3
          VEC(I)=PSIDE*VEC(I)
   20   CONTINUE
      ENDIF
      CALL CROSSV(VEC,TA,VEC)
C...COMPUTE TANGENT OF ANGLE BETWEEN TOOL NORMAL AND TOOL RADIAL AXIS
      CALL DOTV(CANG,VEC,R(29))
      CALL CROSS(VEC,R(29),V)
      CALL VNORM(V,VN)
      CALL DOTV(SANG,V,VN)
      IF (ABS(CANG).GT.1.D-15) THEN
        TANG=SANG/CANG
      ELSE
        TANG=SIGN(1.D0,SANG)*1.D15
      ENDIF
C...IS ANGLE VALID FOR SEGMENTS 3,4,5 OF CUTTER
C   I.E. CORNER RADIUS AND ADJACENT POINT CIRCLE SEGMENTS
      DO 30 I=3,5
        IF ((TCONT(I).GT.0).AND.
     1     ((TANG-TANLO(I))*(TANG-TANHI(I)).LE.0.D0)) THEN
C...COMPUTE TOOL END COORDS
          DO 25 K=1,3
            TE(K)=R(K)+(OFFSET+PSIDE*CORRAD(I))*R(28+K)
     1           +RI(I)*VEC(K)-TLHITE(I)*TA(K)
   25     CONTINUE
          GOTO 999
        ENDIF
   30 CONTINUE
C...NO - IS ANGLE VALID FOR TOOL TIP
      IF ( (TCONT(1).GT.0).AND.
     1   ( (TANG-TANLO(1))*(TANG-TANHI(1)).LE.0.D0) ) THEN
C...YES - OUTPUT WARNING
        CALL CFORM(' *** WARNING - CUTTING ON TOOL TIP ***',DARRAY,1,38)
        CALL CPRINT(DARRAY)
        DO 40 K=1,3
          TE(K)=R(K)+OFFSET*R(28+K)
   40   CONTINUE
C...NO - IS ANGLE VALID FOR TOP OF UPPER LINE SEGMENT
      ELSE IF ( (TCONT(7).GT.0).AND.
     1        ( (TANG-TANLO(7))*(TANG-TANHI(7)).LE.0.D0) ) THEN
C...YES - OUTPUT WARNING
        CALL CFORM(' *** WARNING - CUTTING ON POINT CIRCLE AT TOP OF UPP
     1ER LINE SEGMENT ***',DARRAY,1,71)
        CALL CPRINT(DARRAY)
        DO 50 K=1,3
          TE(K)=R(K)+OFFSET*R(28+K)+RI(7)*VEC(K)-TLHITE(7)*TA(K)
   50   CONTINUE
C...NO - INVALID ANGLE FOR THIS CUTTER
      ELSE
        CALL CFORM(' *** WARNING - UNABLE TO POSITION 7 SEGMENT CUTTER A
     1T CURRENT SURFACE POINT - SPHERICAL CUTTER ASSUMED',DARRAY,1,101)
        CALL CPRINT(DARRAY)
C
      ENDIF
999   CONTINUE
      IF(IBUG.NE.11) GO TO 1999
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER TECALC'
      CALL CPRINT(BADMSG)
      CALL BAD(-1,1,'TCOM',TOLCOM)
      CALL BAD(3,1,'TE  ',TE)
      CALL BAD(-3,1,'TA  ',TA)
      CALL BAD(-3,1,'TBEF',TBEF)
 1999 CONTINUE
C
      END
