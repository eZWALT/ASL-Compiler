function fact
  params
    _result integer
    n integer
  endparams

  vars
    f integer
  endvars

     %1 = 1
     f = %1
  label While1 :
     %2 = 1
     %4 = n <= %2
     %3 = not %4
     ifFalse %3 goto EndWhile1
     %5 = f * n
     f = %5
     %6 = 1
     %7 = n - %6
     n = %7
     goto While1
  label EndWhile1 :
     _result = f
     return
     return
endfunction

function main
  vars
    max integer
    i integer
    f integer
    end boolean
  endvars

     %1 = 0
     i = %1
     %2 = 1
     end = %2
     readi max
     %3 = i <= max
     ifFalse %3 goto If1
     %5 = 0
     end = %5
     goto Else1
  label If1 :
     %6 = 0
     i = %6
  label Else1 :
  label While1 :
     %7 = not end
     ifFalse %7 goto EndWhile1
     writei i
     writes "!="
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %8
     writei %8
     writes "\n"
     %9 = i == max
     ifFalse %9 goto If2
     %11 = 1
     end = %11
     goto Else2
  label If2 :
     %12 = 1
     %13 = i + %12
     i = %13
  label Else2 :
     goto While1
  label EndWhile1 :
     return
endfunction


