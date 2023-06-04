function main
  vars
    i integer
  endvars

     %1 = 5
     i = %1
     writei i
     writes "! = "
     %2 = i
     %3 = 0
     %4 = 1
     %5 = %2 - %4
     %6 = %2 < %3
     ifFalse %6 goto BASEFACTORIAL1
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL1 :
     %6 = %2 == %3
     ifFalse %6 goto FACTORIAL1
     %2 = %4
     goto ENDFACTORIAL1
  label FACTORIAL1 :
     %6 = %4 < %5
     ifFalse %6 goto ENDFACTORIAL1
     %2 = %2 * %5
     %5 = %5 - %4
     goto FACTORIAL1
  label ENDFACTORIAL1 :
     writei %2
     writes "\n"
     writes " i = "
     writei i
     writes "\n"
     %7 = 2
     writei %7
     writes "! = "
     %8 = 2
     %9 = %8
     %10 = 0
     %11 = 1
     %12 = %9 - %11
     %13 = %9 < %10
     ifFalse %13 goto BASEFACTORIAL2
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL2 :
     %13 = %9 == %10
     ifFalse %13 goto FACTORIAL2
     %9 = %11
     goto ENDFACTORIAL2
  label FACTORIAL2 :
     %13 = %11 < %12
     ifFalse %13 goto ENDFACTORIAL2
     %9 = %9 * %12
     %12 = %12 - %11
     goto FACTORIAL2
  label ENDFACTORIAL2 :
     writei %9
     writes "\n"
     %14 = 1
     writei %14
     writes "! = "
     %15 = 1
     %16 = %15
     %17 = 0
     %18 = 1
     %19 = %16 - %18
     %20 = %16 < %17
     ifFalse %20 goto BASEFACTORIAL3
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL3 :
     %20 = %16 == %17
     ifFalse %20 goto FACTORIAL3
     %16 = %18
     goto ENDFACTORIAL3
  label FACTORIAL3 :
     %20 = %18 < %19
     ifFalse %20 goto ENDFACTORIAL3
     %16 = %16 * %19
     %19 = %19 - %18
     goto FACTORIAL3
  label ENDFACTORIAL3 :
     writei %16
     writes "\n"
     %21 = 0
     writei %21
     writes "! = "
     %22 = 0
     %23 = %22
     %24 = 0
     %25 = 1
     %26 = %23 - %25
     %27 = %23 < %24
     ifFalse %27 goto BASEFACTORIAL4
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL4 :
     %27 = %23 == %24
     ifFalse %27 goto FACTORIAL4
     %23 = %25
     goto ENDFACTORIAL4
  label FACTORIAL4 :
     %27 = %25 < %26
     ifFalse %27 goto ENDFACTORIAL4
     %23 = %23 * %26
     %26 = %26 - %25
     goto FACTORIAL4
  label ENDFACTORIAL4 :
     writei %23
     writes "\n"
     return
endfunction


