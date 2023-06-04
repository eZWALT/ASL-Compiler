function main
  vars
    nz integer
    i integer
    j integer
    sum float
    A integer 2
    M float 200
  endvars

     %1 = 0
     nz = %1
     %2 = 0
     %3 = float %2
     sum = %3
     %4 = 0
     i = %4
  label While2 :
     %5 = 10
     %6 = i < %5
     ifFalse %6 goto EndWhile2
     %8 = 0
     j = %8
  label While1 :
     %9 = 20
     %10 = j < %9
     ifFalse %10 goto EndWhile1
     %12 = 20
     %13 = 10
     %14 = i < %13
     ifFalse %14 goto DEATH1
     %14 = j < %12
     ifFalse %14 goto DEATH1
     goto ALIVE1
  label DEATH1 :
     halt "Container index out of range."
  label ALIVE1 :
     %17 = 20
     %16 = i * %17
     %16 = %16 + j
     %15 = M[%16]
     %18 = 0
     %21 = float %18
     %19 = %15 ==. %21
     ifFalse %19 goto Endif2
     %22 = 1
     %23 = nz + %22
     nz = %23
  label Endif2 :
     %24 = 20
     %25 = 10
     %26 = i < %25
     ifFalse %26 goto DEATH3
     %26 = j < %24
     ifFalse %26 goto DEATH3
     goto ALIVE3
  label DEATH3 :
     halt "Container index out of range."
  label ALIVE3 :
     %29 = 20
     %28 = i * %29
     %28 = %28 + j
     %27 = M[%28]
     %30 = sum +. %27
     sum = %30
     %31 = 10
     %32 = %31 * i
     %33 = %32 + j
     %34 = 12
     %35 = %33 / %34
     %35 = %35 * %34
     %35 = %33 - %35
     %36 = 0
     %37 = %35 == %36
     ifFalse %37 goto Endif4
     writei nz
     writes "\n"
  label Endif4 :
     %39 = 1
     %40 = j + %39
     j = %40
     goto While1
  label EndWhile1 :
     %41 = 1
     %42 = i + %41
     i = %42
     goto While2
  label EndWhile2 :
     %43 = 0
     A[%43] = nz
     %44 = 1
     %45 = 23
     A[%44] = %45
     writes "nz="
     writei nz
     writes "\n"
     writes "sum="
     writef sum
     writes "\n"
     writes "A: ["
     %46 = 0
     %47 = A[%46]
     writei %47
     writes ","
     %48 = 1
     %49 = A[%48]
     writei %49
     writes "]\n"
     return
endfunction


