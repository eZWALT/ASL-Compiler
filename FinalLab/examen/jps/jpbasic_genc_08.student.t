function x2
  params
    _result integer
    a integer array
  endparams

  vars
    i integer
    n integer
  endvars

     %1 = 0
     n = %1
     %2 = 0
     i = %2
  label While1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto EndWhile1
     %7 = a
     %6 = %7[i]
     %8 = 80
     %9 = %6 < %8
     ifFalse %9 goto Endif1
     %11 = 1
     %12 = n + %11
     n = %12
  label Endif1 :
     %13 = a
     %15 = a
     %14 = %15[i]
     %16 = 2
     %17 = %14 * %16
     %13[i] = %17
     %19 = a
     %18 = %19[i]
     writei %18
     writes "\n"
     %20 = 1
     %21 = i + %20
     i = %21
     goto While1
  label EndWhile1 :
     _result = n
     return
     return
endfunction

function main
  vars
    x integer 10
    i integer
    z integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %5 = 77
     %6 = %5 + i
     x[i] = %6
     %7 = 1
     %8 = i + %7
     i = %8
     goto While1
  label EndWhile1 :
     %9 = 0
     i = %9
  label While2 :
     %10 = 10
     %11 = i < %10
     ifFalse %11 goto EndWhile2
     %13 = x[i]
     writei %13
     writes "\n"
     %14 = 1
     %15 = i + %14
     i = %15
     goto While2
  label EndWhile2 :
     pushparam 
     %17 = &x
     pushparam %17
     call x2
     popparam 
     popparam %16
     z = %16
     writes "z:"
     writei z
     writes "\n"
     %18 = 0
     i = %18
  label While3 :
     %19 = 10
     %20 = i < %19
     ifFalse %20 goto EndWhile3
     writes "x["
     writei i
     writes "]="
     %22 = x[i]
     writei %22
     writes "\n"
     %23 = 1
     %24 = i + %23
     i = %24
     goto While3
  label EndWhile3 :
     return
endfunction


