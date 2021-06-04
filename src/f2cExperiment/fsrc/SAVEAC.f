**** SOURCE FILE : SAVEAC.V01   ***
*
      SUBROUTINE SAVEAC(AC)
C
C   PURPOSE: SYSTEM INDEPENDENT ROUTINE TO SAVE VALUE REFERENCED BY .AC.
C
      INTEGER AC,XCANON
C
      INCLUDE 'BLANKCOM.INC'
      INCLUDE 'INTRPEQ.INC'
      INCLUDE 'LDEF.INC'
C
      COMMON/STOR/NTB,FPB,PPB,COMN,CFB
      INTEGER NTB,FPB,PPB,COMN,CFB
C
C    .AC. IS IN FIXED LOCATION OF NAMTBL
C
      NTP=NTB+166
C
      J=NT(1,NTP)
      IF (CANFLG)J=XCANON(J)
C
      COM(J)=DBLE(AC)
C
      RETURN
      END
         
