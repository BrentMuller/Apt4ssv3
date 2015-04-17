c ** some dummy routines to fill in for linker undefined ref errors


      subroutine lib$establish
      write(*,*)"unimplemented VAX subroutine LIB$ESTABLISH"
      return
      end

      subroutine time(ct)
c     TODO
      character ctme*30
      character ct*8
      integer vals(9)
      write(*,*)"unimplemented VAX subroutine TIME"
      i=time8()
      call ctime(i,ct)
      call ctime(i,ctme)
      call ltime(i,vals)
      write(*,*)ctme
c      ct=ctme
      return
      end

      subroutine date
      write(*,*)"unimplemented VAX subroutine DATE"
      return
      end

      subroutine lib$revert
      write(*,*)"unimplemented VAX subroutine LIB$REVERT"
      return
      end
      
      subroutine lib$signal
      write(*,*)"unimplemented VAX subroutine LIB$SIGNAL"
      return
      end


      subroutine cputim
      write(*,*)"unimplemented VAX subroutine CPUTIM"
      return
      end
