function f
  params
    _result boolean
    a integer
    f float
  endparams

  vars
    x integer
    b boolean
    z integer 10
  endvars

     %1 = 5
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     %5 = 88
     %6 = float %5
     %7 = %6 *. f
     %8 = float %4
     %9 = %8 -. %7
     writef %9
     readi b
     readf f
     ifFalse b goto Endif1
     writes "h\n\tl\\a"
     %10 = -. f
     %11 = -. %10
     %12 = -. %11
     writef %12
     writes "\n"
  label Endif1 :
     %13 = 1
     _result = %13
     return
     return
endfunction

function fz
  params
    _result float
    r integer
    u float
  endparams

  label While1 :
     %1 = 0.01
     %4 = float r
     %3 = %4 <=. %1
     %2 = not %3
     ifFalse %2 goto EndWhile1
     %5 = 1
     %6 = r - %5
     r = %6
     goto While1
  label EndWhile1 :
     %7 = 0
     %8 = r == %7
     ifFalse %8 goto Endif1
     pushparam 
     %10 = 55555
     pushparam %10
     %11 = 5
     %12 = - %11
     %13 = 4
     %14 = %12 / %13
     %15 = float %14
     pushparam %15
     call f
     popparam 
     popparam 
     popparam 
  label Endif1 :
     %16 = 3
     %17 = r + %16
     %18 = float %17
     %19 = %18 *. u
     _result = %19
     return
     return
endfunction

function main
  vars
    a integer
    q float
  endvars

   %1 = 1
   %2 = - %1
   %3 = float %2
   q = %3
   pushparam 
   %5 = 3
   %6 = 4
   %7 = %5 + %6
   pushparam %7
   pushparam 
   %9 = 4444
   pushparam %9
   %10 = 3
   %11 = float %10
   %12 = q +. %11
   pushparam %12
   call fz
   popparam 
   popparam 
   popparam %8
   pushparam %8
   call fz
   popparam 
   popparam 
   popparam %4
   q = %4
   %13 = 3.7
   %14 = q +. %13
   %15 = 4
   %16 = float %15
   %17 = %14 +. %16
   writef %17
   writes "\n"
   return
endfunction


