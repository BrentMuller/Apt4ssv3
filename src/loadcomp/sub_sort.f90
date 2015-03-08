! Modified to .f90 from M0006200.F                                    
!******************************************************************** 
!                                                                       
      SUBROUTINE SORT(F,L,N,IS,IL) 
      INTEGER F(L,N),TEMP 
      LOGICAL EQULTY 
!    'N' RECORDS OF LENGTH 'L' IN ARRAY 'F' ARE SORTED IN ASCENDING     
!    ORDER ACCORDING TO THE VALUE OF 'IL' ITEMS STARTING FROM THE       
!    'IS'TH IN EACH RECORD)                                             
!    INDEX FOR LAST WORD TO BE SORTED ON                                
      IT=IS+IL-1 
!    FOR EACH RECORD EXCEPT THE LAST                                    
      NM1=N-1 
      DO 1 I=1,NM1 
      IP1=I+1 
!    RECORD WITH LOWEST CHARACTER-STRING VALUE                          
      IK=I 
      DO 2 J=IP1,N 
        EQULTY=.TRUE. 
        DO 3 K=IS,IT 
          IF (EQULTY) THEN 
            IF (F(K,IK).GT.F(K,J)) THEN 
              IK=J 
              EQULTY=.FALSE. 
            ELSE IF (F(K,IK).LT.F(K,J)) THEN 
              EQULTY=.FALSE. 
            ELSE 
              EQULTY=.TRUE. 
            ENDIF 
          ENDIF 
    3   CONTINUE 
    2 END DO 
      IF (IK.NE.I) THEN 
!   INTERCHANGE RECORDS                                                 
        DO 4 J=1,L 
          TEMP=F(J,IK) 
          F(J,IK)=F(J,I) 
          F(J,I)=TEMP 
    4   CONTINUE 
      ENDIF 
!                                                                       
    1 END DO 
      RETURN 
      END                                           
