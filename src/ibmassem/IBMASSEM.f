**** SOURCE FILE : M0000745.ORG ****
*.....IMPLEMENTATION DEPENDENT SUBROUTINE ADDRSS...         12/67  *ID*
ADDRSS START  0
       BC     15,12(0,15)
       DC     X'0700C1C4'
       DC     X'C4D9E2E2'
       L      1,0(1)
       LA     0,0(1)
       BCR    15,14
       END
**** SOURCE FILE : M0000860.ORG ****
*.....IMPLEMENTATION DEPENDENT SUBROUTINE   ...APT241       8/68  DE,PH
*
* PURPOSE          TO SAVE NECESSARY RETURN INFORMATION IN LOCAL
*                  STORAGE, FOR USE IN RETURNING FROM APT242.
*
* CALLING SEQUENCE  CALL APT241
*
* ARGUMENTS        NONE
*
* CALLED BY        APT200
*                  APT201
*                  GO
*
* SUBSIDIARIES     NONE
*
* RESTRICTIONS     NONE
*
* DIAGNOSTICS      NONE
*
* IMPLEMENTATION DEPENDENT SUBROUTINE ENTRY APT242
*
* PURPOSE          TO RETURN TO THE SUBROUTINE WHICH CALLED APT241
*
* CALLING SEQUENCE  CALL APT242
*
* ARGUMENTS        NONE
*
* CALLED BY        AERR
*
* SUBSIDIARIES     NONE
*
* RESTRICTIONS     NONE
*
* DIAGNOSTICS      NONE
         ENTRY APT242
APT241   START
         STM    14,12,12(13)
         BALR   2,0
         USING  *,2
         ST     13,A
         MVC   B(60),12(13)
         LM     14,12,12(13)
         BR     14
APT242   BALR   2,0
         USING  *,2
         L      13,A
          LM   14,12,B
         BR     14
A        DS     F
B        DS    15F
         END