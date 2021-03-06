C
C       AVOIDANCE CONTROL PARAMETERS
C
      DOUBLE PRECISION CTANG,BMIN,BMAX,DMAX
      LOGICAL LATYP1,LANPS,AVLIST
C
      COMMON/AVCPRM/CTANG,BMIN,BMAX,DMAX,LATYP1,LANPS,AVLIST
C
C     CTANG    CONSTANT TECHNOLOGICAL ANGLE
C     BMIN     MINIMUM PITCH ANGLE
C     BMAX     MAXIMUM PITCH ANGLE
C     DMAX     MAXIMUM LINEAR LIFT OFF
C     LATYP1   FLAG INDICATING IF TYPE1 (TILT) AVOIDANCE REQUIRED
C     LANPS    FLAG INDICATING TYPE OF LINEAR LIFT OFF
C              .TRUE.  - LIFT OFF NORMAL TO PS
C              .FALSE. - LIFT OFF PARALLEL TO TOOL AXIS
C     AVLIST   FLAG INDICATING THAT AVOIDANCE DETAILS ARE TO BE PRINTED
C
