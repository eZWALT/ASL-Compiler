function f
  params
    v integer array
  endparams

  vars
    c integer 10
    i integer
  endvars

     %1 = v
     %4 = 9
     %3 = 0
     %2 = 1
  label ArrayCpy1 :
     %5 = %3 <= %4
     ifFalse %5 goto EndArrayCpy1
     %6 = %1[%4]
     c[%4] = %6
     %4 = %4 - %2
     goto ArrayCpy1
  label EndArrayCpy1 :
     writes "en f. c: "
     %7 = 0
     i = %7
  label While2 :
     %8 = 10
     %9 = i < %8
     ifFalse %9 goto EndWhile2
     %11 = c[i]
     writei %11
     %12 = ' '
     writec %12
     %13 = 1
     %14 = i + %13
     i = %14
     goto While2
  label EndWhile2 :
     %15 = '\n'
     writec %15
     return
endfunction

function g
  params
    v integer array
  endparams

  vars
    d integer 10
    i integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %5 = 1
     %6 = - %5
     d[i] = %6
     %7 = 1
     %8 = i + %7
     i = %8
     goto While1
  label EndWhile1 :
     %9 = v
     %12 = 9
     %11 = 0
     %10 = 1
  label ArrayCpy2 :
     %13 = %11 <= %12
     ifFalse %13 goto EndArrayCpy2
     %14 = d[%12]
     %9[%12] = %14
     %12 = %12 - %10
     goto ArrayCpy2
  label EndArrayCpy2 :
     return
endfunction

function main
  vars
    a integer 10
    b integer 10
    i integer
    j integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     a[i] = i
     %5 = 0
     b[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto While1
  label EndWhile1 :
     %10 = 9
     %9 = 0
     %8 = 1
  label ArrayCpy2 :
     %11 = %9 <= %10
     ifFalse %11 goto EndArrayCpy2
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 - %8
     goto ArrayCpy2
  label EndArrayCpy2 :
     writes "despres de b=a. b: "
     %13 = 0
     i = %13
  label While3 :
     %14 = 10
     %15 = i < %14
     ifFalse %15 goto EndWhile3
     %17 = b[i]
     writei %17
     %18 = ' '
     writec %18
     %19 = 1
     %20 = i + %19
     i = %20
     goto While3
  label EndWhile3 :
     %21 = '\n'
     writec %21
     writes "despres de b=a. a: "
     %22 = 0
     i = %22
  label While4 :
     %23 = 10
     %24 = i < %23
     ifFalse %24 goto EndWhile4
     %26 = a[i]
     writei %26
     %27 = ' '
     writec %27
     %28 = 1
     %29 = i + %28
     i = %29
     goto While4
  label EndWhile4 :
     %30 = '\n'
     writec %30
     %31 = &a
     pushparam %31
     call f
     popparam 
     writes "despres de f(a). a: "
     %32 = 0
     i = %32
  label While5 :
     %33 = 10
     %34 = i < %33
     ifFalse %34 goto EndWhile5
     %36 = a[i]
     writei %36
     %37 = ' '
     writec %37
     %38 = 1
     %39 = i + %38
     i = %39
     goto While5
  label EndWhile5 :
     %40 = '\n'
     writec %40
     %41 = &a
     pushparam %41
     call g
     popparam 
     writes "despres de g(a). a: "
     %42 = 0
     i = %42
  label While6 :
     %43 = 10
     %44 = i < %43
     ifFalse %44 goto EndWhile6
     %46 = a[i]
     writei %46
     %47 = ' '
     writec %47
     %48 = 1
     %49 = i + %48
     i = %49
     goto While6
  label EndWhile6 :
     %50 = '\n'
     writec %50
     return
endfunction


