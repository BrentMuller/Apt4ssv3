**** SOURCE FILE : ARTIME00.ORG   ***
*
*
*  * ARTIME *  FORTRAN 77 SUBROUTINE  9-DEC-1985  E.MCLELLAN
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
*   CTIME           ATIME     CHARACTER  CURRENT TIME
*   CDATE           ATIME     CHARACTER  CURRENT DATE
*
*  LOCAL VARIABLES:  NONE
*                   TYPE       DESCRIPTION
*
*  FILES:  NONE
*
*  SUBSIDIARIES:
*              DATE
*              TIME
*
      SUBROUTINE ARTIME
C
      COMMON/ATIME/CTIME,CDATE
C
      CHARACTER CTIME*8,CDATE*9
C
      CALL TIME(CTIME)
      CALL DATE(CDATE)
C
      RETURN
      END
