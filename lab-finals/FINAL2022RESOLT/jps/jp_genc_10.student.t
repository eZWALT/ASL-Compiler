function main
  vars
    i integer
    j integer
    M float 150
    t float
  endvars

     %1 = 0
     i = %1
  label While2 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile2
     %5 = 0
     j = %5
  label While1 :
     %6 = 15
     %7 = j < %6
     ifFalse %7 goto EndWhile1
     %9 = 15
     %10 = 10
     %11 = i < %10
     ifFalse %11 goto DEATH1
     %11 = j < %9
     ifFalse %11 goto DEATH1
     goto ALIVE1
  label DEATH1 :
     halt "Container index out of range."
  label ALIVE1 :
     %12 = 15
     %12 = %12 * i
     %12 = %12 + j
     %13 = i + j
     %14 = float %13
     M[%12] = %14
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
     i = %19
  label While4 :
     %20 = 15
     %21 = i < %20
     ifFalse %21 goto EndWhile4
     %23 = 0
     j = %23
  label While3 :
     %24 = 10
     %25 = j < %24
     ifFalse %25 goto EndWhile3
     %27 = 15
     %28 = 10
     %29 = i < %28
     ifFalse %29 goto DEATH2
     %29 = j < %27
     ifFalse %29 goto DEATH2
     goto ALIVE2
  label DEATH2 :
     halt "Container index out of range."
  label ALIVE2 :
     %32 = 15
     %31 = i * %32
     %31 = %31 + j
     %30 = M[%31]
     writef %30
     writes " "
     %33 = 1
     %34 = j + %33
     j = %34
     goto While3
  label EndWhile3 :
     writes "\n"
     %35 = 1
     %36 = i + %35
     i = %36
     goto While4
  label EndWhile4 :
     return
endfunction


