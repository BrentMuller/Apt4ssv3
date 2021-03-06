**** SOURCE FILE : ARTIME00.IBM;1   ***
*
*
*  * ARTIME *  FORTRAN 77 SUBROUTINE  9-DEC-1985  E.MCLELLAN
*                MODIFIED                 9-FEB-1988  E.MCLELLAN
*
*  PURPOSE:  EXTRACT CURRENT DATE AND TIME AND STORE IN ATIME BLOCK
*
*  CALLING SEQUENCE:
*                   CALL ARTIME
*
*  ARGUMENTS:  NONE
*
*  GLOBAL VARIABLES:
*
*---------------------------------------------------
*   VARIABLE        BLOCK     TYPE       DESCRIPTION
*---------------------------------------------------
*   T               ATIME     DOUBLE     CURRENT TIME
*                             PRECISION  CURRENT DATE
*
*  LOCAL VARIABLES:  NONE
*                   TYPE       DESCRIPTION
*   CTIME           CHARACTER  CURRENT TIME
*   CDATE           CHARACTER  CURRENT DATE
*
*  FILES:  NONE
*
*  SUBSIDIARIES:
*              DATE
*              TIME
*
      SUBROUTINE ARTIME
C
      DOUBLE PRECISION T(4)
      COMMON/ATIME/T
C
      CHARACTER CTIME*8,CDATE*8,DAOFWK*9
C
      CALL TIME(CTIME)
      CALL DATE(DAOFWK,CDATE)
C
      RETURN
      END
