function main
  vars
    a integer
    b integer
    end boolean
    pi float
  endvars

   %1 = 12
   a = %1
   %2 = 5
   %3 = a * %2
   %4 = 1
   %5 = a + %4
   %6 = a * %5
   %7 = %3 + %6
   b = %7
   %9 = b < a
   %8 = not %9
   %10 = 0
   %11 = a == %10
   %13 = not %11
   %14 = %8 and %13
   end = %14
   %15 = 3.3
   %16 = 1
   %17 = %16 / a
   %18 = float %17
   %19 = %15 +. %18
   %20 = 2.0
   %21 = -. %20
   %22 = float a
   %23 = %21 /. %22
   %24 = %19 -. %23
   pi = %24
   %25 = a == b
   %27 = %25 or end
   writei %27
   writes "\n"
   %28 = a * b
   writei %28
   writes "\n"
   %29 = 2
   %30 = float %29
   %31 = %30 *. pi
   writef %31
   writes "\n"
   return
endfunction


