function f1
  params
    a integer
    b integer
  endparams

  vars
    c float
    d integer
    found boolean
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %3 = float a
     %4 = %3 +. %2
     c = %4
     %5 = 0
     d = %5
     %6 = a + d
     %9 = float %6
     %8 = %9 <=. c
     %7 = not %8
     %10 = not found
     %11 = %7 or %10
     ifFalse %11 goto Endif1
  label While1 :
     %12 = 0
     %14 = b <= %12
     %13 = not %14
     ifFalse %13 goto EndWhile1
     %15 = 1
     %16 = b - %15
     b = %16
     %17 = 1
     found = %17
     goto While1
  label EndWhile1 :
  label Endif1 :
     %18 = 11
     %19 = b <= %18
     ifFalse %19 goto Endif2
     %21 = 2
     %22 = float %21
     %23 = %22 *. c
     %24 = 1
     %25 = float %24
     %26 = %23 +. %25
     c = %26
  label Endif2 :
     writef c
     writes "\n"
     return
endfunction

function main
  vars
    a integer
    b integer
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   pushparam b
   %6 = 3
   %7 = %6 + b
   pushparam %7
   call f1
   popparam 
   popparam 
   return
endfunction


