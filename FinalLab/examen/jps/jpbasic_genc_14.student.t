function one
  params
    _result float
  endparams

   %1 = 1
   _result = %1
   return
   return
endfunction

function sort
  params
    v float array
  endparams

  vars
    i integer
    j integer
    jmin integer
    aux float
  endvars

     %1 = 0
     i = %1
  label While2 :
     %2 = 20
     %3 = 1
     %4 = %2 - %3
     %5 = i < %4
     ifFalse %5 goto EndWhile2
     jmin = i
     %7 = 1
     %8 = i + %7
     j = %8
  label While1 :
     %9 = 20
     %10 = j < %9
     ifFalse %10 goto EndWhile1
     %13 = v
     %12 = %13[j]
     %15 = v
     %14 = %15[jmin]
     %16 = %12 <. %14
     ifFalse %16 goto Endif1
     jmin = j
  label Endif1 :
     %18 = 1
     %19 = j + %18
     j = %19
     goto While1
  label EndWhile1 :
     %21 = jmin == i
     %20 = not %21
     ifFalse %20 goto Endif2
     %23 = v
     %22 = %23[i]
     aux = %22
     %24 = v
     %26 = v
     %25 = %26[jmin]
     %24[i] = %25
     %27 = v
     %27[jmin] = aux
  label Endif2 :
     %28 = 1
     %29 = i + %28
     i = %29
     goto While2
  label EndWhile2 :
     return
endfunction

function evenPositivesAndSort
  params
    v float array
  endparams

  vars
    i integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 20
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %6 = v
     %5 = %6[i]
     %7 = 0
     %10 = float %7
     %9 = %5 <=. %10
     %8 = not %9
     ifFalse %8 goto Endif1
     %11 = v
     pushparam 
     call one
     popparam %12
     %11[i] = %12
  label Endif1 :
     %13 = 1
     %14 = i + %13
     i = %14
     goto While1
  label EndWhile1 :
     pushparam v
     call sort
     popparam 
     return
endfunction

function main
  vars
    af float 20
    i integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 20
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     readf %5
     af[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto While1
  label EndWhile1 :
     %8 = &af
     pushparam %8
     call evenPositivesAndSort
     popparam 
     %9 = 0
     i = %9
  label While2 :
     %10 = 20
     %11 = i < %10
     ifFalse %11 goto EndWhile2
     %13 = af[i]
     pushparam 
     call one
     popparam %14
     %16 = %13 ==. %14
     %15 = not %16
     ifFalse %15 goto If1
     %17 = af[i]
     writef %17
     %18 = ' '
     writec %18
     %19 = 1
     %20 = i + %19
     i = %20
     goto Else1
  label If1 :
     %21 = '\n'
     writec %21
     return
  label Else1 :
     goto While2
  label EndWhile2 :
     %22 = '\n'
     writec %22
     return
endfunction


