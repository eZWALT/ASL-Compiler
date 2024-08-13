function read_chars
  params
    _result integer
    a character array
  endparams

  vars
    i integer
  endvars

     %1 = 0
     i = %1
  label While1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto EndWhile1
     %5 = a
     readc %6
     %5[i] = %6
     %8 = a
     %7 = %8[i]
     %9 = '.'
     %11 = %7 == %9
     %10 = not %11
     ifFalse %10 goto If1
     %12 = 1
     %13 = i + %12
     i = %13
     goto Else1
  label If1 :
     _result = i
     return
  label Else1 :
     goto While1
  label EndWhile1 :
     %14 = 10
     _result = %14
     return
     return
endfunction

function find_vowels
  params
    n integer
    vc character array
    vb boolean array
  endparams

  vars
    c character
  endvars

  label While1 :
     %1 = 0
     %3 = n <= %1
     %2 = not %3
     ifFalse %2 goto EndWhile1
     %4 = 1
     %5 = n - %4
     %7 = vc
     %6 = %7[%5]
     c = %6
     %8 = 1
     %9 = n - %8
     %10 = vb
     %11 = 'a'
     %12 = c == %11
     %14 = 'e'
     %15 = c == %14
     %17 = %12 or %15
     %18 = 'i'
     %19 = c == %18
     %21 = %17 or %19
     %22 = 'o'
     %23 = c == %22
     %25 = %21 or %23
     %26 = 'u'
     %27 = c == %26
     %29 = %25 or %27
     %10[%9] = %29
     %30 = 1
     %31 = n - %30
     n = %31
     goto While1
  label EndWhile1 :
     return
endfunction

function write_consonants
  params
    _result float
    n integer
    vc character array
    vb boolean array
  endparams

  vars
    k float
    i integer
  endvars

     %1 = 0
     i = %1
     %2 = 0
     %3 = float %2
     k = %3
  label While1 :
     %5 = i == n
     %4 = not %5
     ifFalse %4 goto EndWhile1
     %7 = vb
     %6 = %7[i]
     ifFalse %6 goto If1
     %8 = 1
     %9 = float %8
     %10 = k +. %9
     k = %10
     goto Else1
  label If1 :
     %12 = vc
     %11 = %12[i]
     writec %11
  label Else1 :
     %13 = 1
     %14 = i + %13
     i = %14
     goto While1
  label EndWhile1 :
     %15 = '\n'
     writec %15
     %16 = 100
     %17 = float %16
     %18 = %17 *. k
     %19 = float n
     %20 = %18 /. %19
     _result = %20
     return
     return
endfunction

function main
  vars
    a character 10
    b boolean 10
    n integer
    p float
  endvars

   pushparam 
   %2 = &a
   pushparam %2
   call read_chars
   popparam 
   popparam %1
   n = %1
   pushparam n
   %3 = &a
   pushparam %3
   %4 = &b
   pushparam %4
   call find_vowels
   popparam 
   popparam 
   popparam 
   pushparam 
   pushparam n
   %6 = &a
   pushparam %6
   %7 = &b
   pushparam %7
   call write_consonants
   popparam 
   popparam 
   popparam 
   popparam %5
   p = %5
   writef p
   writes "\n"
   return
endfunction


