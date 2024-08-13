function prod_escalar
  params
    _result integer
    a1 integer array
    a2 integer array
  endparams

  vars
    i integer
    s integer
  endvars

     %1 = 0
     s = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %6 = a1
     %5 = %6[i]
     %8 = a2
     %7 = %8[i]
     %9 = %5 * %7
     %10 = s + %9
     s = %10
     %11 = 1
     %12 = i + %11
     i = %12
     goto While1
  label EndWhile1 :
     _result = s
     return
     return
endfunction

function main
  vars
    i integer
    v1 integer 10
    v2 integer 10
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %5 = - i
     v1[i] = %5
     %6 = i * i
     v2[i] = %6
     %7 = 1
     %8 = i + %7
     i = %8
     goto While1
  label EndWhile1 :
     pushparam 
     %10 = &v1
     pushparam %10
     %11 = &v2
     pushparam %11
     call prod_escalar
     popparam 
     popparam 
     popparam %9
     writei %9
     writes "\n"
     return
endfunction


