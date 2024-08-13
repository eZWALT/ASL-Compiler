function main
  vars
    i integer
    j integer
    M float 150
    K float 150
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
     readf %13
     M[%12] = %13
     %14 = 1
     %15 = j + %14
     j = %15
     goto While1
  label EndWhile1 :
     %16 = 1
     %17 = i + %16
     i = %17
     goto While2
  label EndWhile2 :
     %20 = 149
     %19 = 0
     %18 = 1
  label MatrixCpy3 :
     %21 = %19 <= %20
     ifFalse %21 goto EndMatrixCpy3
     %22 = M[%20]
     K[%20] = %22
     %20 = %20 - %18
     goto MatrixCpy3
  label EndMatrixCpy3 :
     %23 = 3
     i = %23
  label While5 :
     %24 = 7
     %25 = i < %24
     ifFalse %25 goto EndWhile5
     %27 = 3
     j = %27
  label While4 :
     %28 = j < i
     ifFalse %28 goto EndWhile4
     %30 = 15
     %31 = 10
     %32 = i < %31
     ifFalse %32 goto DEATH2
     %32 = j < %30
     ifFalse %32 goto DEATH2
     goto ALIVE2
  label DEATH2 :
     halt "Container index out of range."
  label ALIVE2 :
     %35 = 15
     %34 = i * %35
     %34 = %34 + j
     %33 = K[%34]
     t = %33
     %36 = 15
     %37 = 10
     %38 = i < %37
     ifFalse %38 goto DEATH3
     %38 = j < %36
     ifFalse %38 goto DEATH3
     goto ALIVE3
  label DEATH3 :
     halt "Container index out of range."
  label ALIVE3 :
     %39 = 15
     %39 = %39 * i
     %39 = %39 + j
     %40 = 15
     %41 = 10
     %42 = j < %41
     ifFalse %42 goto DEATH4
     %42 = i < %40
     ifFalse %42 goto DEATH4
     goto ALIVE4
  label DEATH4 :
     halt "Container index out of range."
  label ALIVE4 :
     %45 = 15
     %44 = j * %45
     %44 = %44 + i
     %43 = K[%44]
     K[%39] = %43
     %46 = 15
     %47 = 10
     %48 = j < %47
     ifFalse %48 goto DEATH5
     %48 = i < %46
     ifFalse %48 goto DEATH5
     goto ALIVE5
  label DEATH5 :
     halt "Container index out of range."
  label ALIVE5 :
     %49 = 15
     %49 = %49 * j
     %49 = %49 + i
     K[%49] = t
     %50 = 1
     %51 = j + %50
     j = %51
     goto While4
  label EndWhile4 :
     %52 = 1
     %53 = i + %52
     i = %53
     goto While5
  label EndWhile5 :
     %54 = 0
     i = %54
  label While7 :
     %55 = 10
     %56 = i < %55
     ifFalse %56 goto EndWhile7
     %58 = 0
     j = %58
  label While6 :
     %59 = 15
     %60 = j < %59
     ifFalse %60 goto EndWhile6
     %62 = 15
     %63 = 10
     %64 = i < %63
     ifFalse %64 goto DEATH6
     %64 = j < %62
     ifFalse %64 goto DEATH6
     goto ALIVE6
  label DEATH6 :
     halt "Container index out of range."
  label ALIVE6 :
     %67 = 15
     %66 = i * %67
     %66 = %66 + j
     %65 = K[%66]
     writef %65
     writes " "
     %68 = 1
     %69 = j + %68
     j = %69
     goto While6
  label EndWhile6 :
     writes "\n"
     %70 = 1
     %71 = i + %70
     i = %71
     goto While7
  label EndWhile7 :
     return
endfunction


