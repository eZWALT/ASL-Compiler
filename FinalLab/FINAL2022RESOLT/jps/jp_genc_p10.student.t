function main
  vars
    M float 150
  endvars

     %1 = 6
     %2 = 0
     %3 = 15
     %4 = 10
     %5 = %1 < %4
     ifFalse %5 goto DEATH1
     %5 = %2 < %3
     ifFalse %5 goto DEATH1
     goto ALIVE1
  label DEATH1 :
     halt "Container index out of range."
  label ALIVE1 :
     %6 = 15
     %6 = %6 * %1
     %6 = %6 + %2
     %7 = 9999
     %8 = float %7
     M[%6] = %8
     writes "OK and now crash:\n"
     %9 = 5
     %10 = 15
     %11 = 15
     %12 = 10
     %13 = %9 < %12
     ifFalse %13 goto DEATH2
     %13 = %10 < %11
     ifFalse %13 goto DEATH2
     goto ALIVE2
  label DEATH2 :
     halt "Container index out of range."
  label ALIVE2 :
     %16 = 15
     %15 = %9 * %16
     %15 = %15 + %10
     %14 = M[%15]
     writef %14
     writes "\n"
     writes "End without crash!!\n"
     return
endfunction


