#!/bin/sh

#************************************************************************
#* UNIX shell script to replace VAX/VMS Digital Command Language, DCL.  *
#* DCL are .com files                                                   *
#************************************************************************
# FILE04                                                                *
# $ !                                                                   *
# $ ! PROCEDURE TO RUN UNLOAD PROGRAM                                   *
# $ !                                                                   *
# $ SET NOVERIFY                                                        *
# $ INQUIRE FILNAM "Name of Concatenated File to be Unloaded "          *
# $ INQUIRE TYPE "Unload by MODULE or FILE"                             *
# $ INQUIRE SEQ "Sequence number specification: SEQ , NOSEQ or VB"      *
# $ INQUIRE INCTYP "Include File Format : VAX , IBM or NOINC"           *
# $ INQUIRE FORM "File Format : FORT or LIST"                           *
# $ OPEN/WRITE OUTPUT_FILE FOR002                                       *
# $ WRITE OUTPUT_FILE TYPE                                              *
# $ WRITE OUTPUT_FILE SEQ                                               *
# $ WRITE OUTPUT_FILE INCTYP                                            *
# $ WRITE OUTPUT_FILE FORM                                              *
# $ CLOSE OUTPUT_FILE                                                   *
# $ ASS 'FILNAM' FOR001                                                 *
# $ RUN UNLOAD                                                          *
# $ LOC := 'F$LOCATE("FILE",TYPE)                                       *
# $ IF LOC.EQ.0 THEN GOTO FIN                                           *
# $ RENAME *.DAT *.FOR                                                  *
# $ FIN:                                                                *
# $ DEASS FOR001                                                        *
# $ DEL FOR002.*;*                                                      *
#************************************************************************
echo "***************************************************************"
echo "* NO REDISTRIBUTION TO U.S. EMBARGOED DESTINATIONS OR PERSONS *"
echo "* WHICH INCLUDE CUBA, IRAQ, LIBYA, NORTH KOREA, IRAN, SYRIA,  *"
echo "* SUDAN, AFGHANISTAN AND ANY OTHER COUNTRY TO WHICH THE U.S.  *"
echo "* HAS EMBARGOED GOODS AND SERVICES.                           *"
echo "***************************************************************"
echo " "
echo "***********************************"
echo "* PROCEDURE TO RUN UNLOAD PROGRAM *"
echo "*******************************************************"
echo "* ENTER: NAME OF FILE TO BE UNLOADED                  *"
echo "*******************************************************"
#/* promts user to enter the name of the concatenated files */
read -e  FILNAME
clear #/* clear terminal */
echo "*******************************************************"
echo "* RECORD 1: MODULE OR FILE                            *"
echo "* TO INDICATE WHETHER TO DIVIDE INTO MODULES OR FILES *"
echo "* NOTE: MODULES ARE CONCATENATED SETS OF FILES        *"
echo "*******************************************************"
echo "* ENTER: MODULE OR FILE *"
echo "*************************"
#/* prompts usr to unzip into modules or files */
read -e TYPE
clear
echo "*******************************************************"
echo "* RECORD 2: SEQ, NOSEQ OR VB                          *"
echo "* TO INDICATE OUTPUT RECORD FORMAT                    *"
echo "* SEQ   - FIXED LENGTH WITH SEQUENCE NOS (80 BYTES)   *"
echo "* NOSEQ - VARIABLE LENGTH WITHOUT SEQUENCE NOS.       *"
echo "* VB    - VARIABLE LENGTH WITH LEADING SEQUENCE NOS.  *"
echo "*******************************************************"
echo "* ENTER: SEQ, NOSEQ OR VB *"
echo "***************************"
#/* prompts usr to add sequence numbers to fortran files */
read -e SEQ
clear
echo "*******************************************************"
echo "* RECORD 3: VAX, IBM OR NOINC                         *"
echo "* TO INDICATE INCLUDE FILE FORMAT                     *"
echo "* VAX   - INCLUDE *.INC                               *"
echo "* IBM   - INCLUDE (NAME)                              *"
echo "* NOINC - TEXT OF INCLUDE FILES WILL BE INSERTED      *"
echo "* INTO SOURCE CODE DURING UNLOAD PROCEDURE            *"
echo "*******************************************************"
echo "* ENTER: VAX, IBM OR NOINC *"
echo "****************************"
#/* prompts usr on how to handle fortran *.INC files */
read -e INCTYPE
clear
echo "*******************************************************"
echo "* RECORD 4: FORT OR LIST                              *"
echo "* TO INDICATE IF STANDARD FORTRAN OPEN                *"
echo "* OR SPECIAL VAX OPEN (CARRIAGECONTROL='LIST')        *"
echo "*******************************************************"
echo "* ENTER: FORT OR LIST *"
echo "***********************"
#/* prompts usr on how to handle create files */
read -e FORM
clear
printf "$TYPE\n$SEQ\n$INCTYPE\n$FORM" | tr "[:lower:]" "[:upper:]" > FORT.2
mv $FILNAME FORT.1
UNLOAD
exit 0

