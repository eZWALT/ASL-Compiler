function main
  vars
    nz integer
    a integer
    b integer
    i integer
    j integer
    sum float
    A integer 2
    M float 200
  endvars

     readi a
     readi b
     %1 = 0
     i = %1
  label While2 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile2
     %5 = 0
     j = %5
  label While1 :
     %6 = 20
     %7 = j < %6
     ifFalse %7 goto EndWhile1
     %9 = 20
     %10 = 10
     %11 = i < %10
     ifFalse %11 goto DEATH1
     %11 = j < %9
     ifFalse %11 goto DEATH1
     goto ALIVE1
  label DEATH1 :
     halt "Container index out of range."
  label ALIVE1 :
     %12 = 20
     %12 = %12 * i
     %12 = %12 + j
     %13 = float a
     M[%12] = %13
     %14 = a - b
     a = %14
     %15 = 1
     %16 = j + %15
     j = %16
     goto While1
  label EndWhile1 :
     %17 = 1
     %18 = i + %17
     i = %18
     goto While2
  label EndWhile2 :
     %19 = 0
     nz = %19
     %20 = 0
     %21 = float %20
     sum = %21
     %22 = 0
     i = %22
  label While4 :
     %23 = 10
     %24 = i < %23
     ifFalse %24 goto EndWhile4
     %26 = 0
     j = %26
  label While3 :
     %27 = 20
     %28 = j < %27
     ifFalse %28 goto EndWhile3
     %30 = 20
     %31 = 10
     %32 = i < %31
     ifFalse %32 goto DEATH2
     %32 = j < %30
     ifFalse %32 goto DEATH2
     goto ALIVE2
  label DEATH2 :
     halt "Container index out of range."
  label ALIVE2 :
     %35 = 20
     %34 = i * %35
     %34 = %34 + j
     %33 = M[%34]
     %36 = 100
     %39 = float %36
     %37 = %33 ==. %39
     ifFalse %37 goto Endif3
     %40 = 1
     %41 = nz + %40
     nz = %41
  label Endif3 :
     %42 = 20
     %43 = 10
     %44 = i < %43
     ifFalse %44 goto DEATH4
     %44 = j < %42
     ifFalse %44 goto DEATH4
     goto ALIVE4
  label DEATH4 :
     halt "Container index out of range."
  label ALIVE4 :
     %47 = 20
     %46 = i * %47
     %46 = %46 + j
     %45 = M[%46]
     %48 = sum +. %45
     sum = %48
     %49 = 10
     %50 = %49 * i
     %51 = %50 + j
     %52 = 12
     %53 = %51 / %52
     %53 = %53 * %52
     %53 = %51 - %53
     %54 = %53 == b
     ifFalse %54 goto Endif5
     writef sum
     writes "\n"
  label Endif5 :
     %56 = 1
     %57 = j + %56
     j = %57
     goto While3
  label EndWhile3 :
     %58 = 1
     %59 = i + %58
     i = %59
     goto While4
  label EndWhile4 :
     %60 = 0
     A[%60] = nz
     %61 = 1
     %62 = 23
     A[%61] = %62
     writes "nz="
     writei nz
     writes "\n"
     writes "sum="
     writef sum
     writes "\n"
     writes "A: ["
     %63 = 0
     %64 = A[%63]
     writei %64
     writes ","
     %65 = 1
     %66 = A[%65]
     writei %66
     writes "]\n"
     return
endfunction


