function f
  params
    a float array
  endparams

   %1 = 5
   %2 = a
   %3 = 5
   %5 = a
   %4 = %5[%3]
   %6 = 10
   %7 = float %6
   %8 = %4 *. %7
   %2[%1] = %8
   return
endfunction

function main
  vars
    b float 10
    c float 10
  endvars

   %1 = 5
   readf %2
   b[%1] = %2
   %3 = 7
   %4 = 5
   %5 = b[%4]
   c[%3] = %5
   %6 = 5
   %7 = b[%6]
   writef %7
   writes "\n"
   %8 = 7
   %9 = c[%8]
   writef %9
   writes "\n"
   %10 = &b
   pushparam %10
   call f
   popparam 
   %11 = 5
   %12 = b[%11]
   writef %12
   writes "\n"
   %13 = 7
   %14 = c[%13]
   writef %14
   writes "\n"
   return
endfunction


