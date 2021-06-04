c ** some dummy routines to fill in for linker undefined ref errors


      subroutine libsestablish
      write(*,*)"unimplemented VAX subroutine LIB$ESTABLISH"
      return
      end

      subroutine time(ct)
c     TODO
      character ctme*30
      character ct*8
      integer vals(9)
      write(*,*)"unimplemented VAX subroutine TIME"
c      i=time8()
c      call ctime(i,ct)
c      call ctime(i,ctme)
c      call ltime(i,vals)
c      write(*,*)ctme
c      ct=ctme
      return
      end

      subroutine date
      write(*,*)"unimplemented VAX subroutine DATE"
      return
      end

      subroutine libsrevert
      write(*,*)"unimplemented VAX subroutine LIB$REVERT"
      return
      end
      
      subroutine libssignal
      write(*,*)"unimplemented VAX subroutine LIB$SIGNAL"
      return
      end


      subroutine cputim
      write(*,*)"unimplemented VAX subroutine CPUTIM"
      return
      end
