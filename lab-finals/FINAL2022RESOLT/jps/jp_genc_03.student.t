function main
  vars
    a integer
    b integer
    A integer 2
    x float
    y float
  endvars

     %1 = 3
     %2 = float %1
     x = %2
     %3 = 1
     a = %3
     readi b
     %4 = b
     %5 = 0
     %6 = 1
     %7 = %4 - %6
     %8 = %4 < %5
     ifFalse %8 goto BASEFACTORIAL1
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL1 :
     %8 = %4 == %5
     ifFalse %8 goto FACTORIAL1
     %4 = %6
     goto ENDFACTORIAL1
  label FACTORIAL1 :
     %8 = %6 < %7
     ifFalse %8 goto ENDFACTORIAL1
     %4 = %4 * %7
     %7 = %7 - %6
     goto FACTORIAL1
  label ENDFACTORIAL1 :
     %9 = float %4
     %10 = %9 +. x
     y = %10
     writef y
     writes "\n"
     %11 = 0
     %12 = 8
     A[%11] = %12
     %13 = 1
     %14 = 9
     A[%13] = %14
     %15 = a
     %16 = 0
     %17 = 1
     %18 = %15 - %17
     %19 = %15 < %16
     ifFalse %19 goto BASEFACTORIAL2
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL2 :
     %19 = %15 == %16
     ifFalse %19 goto FACTORIAL2
     %15 = %17
     goto ENDFACTORIAL2
  label FACTORIAL2 :
     %19 = %17 < %18
     ifFalse %19 goto ENDFACTORIAL2
     %15 = %15 * %18
     %18 = %18 - %17
     goto FACTORIAL2
  label ENDFACTORIAL2 :
     %20 = float %15
     %21 = %20 *. x
     y = %21
     %22 = b
     %23 = 0
     %24 = 1
     %25 = %22 - %24
     %26 = %22 < %23
     ifFalse %26 goto BASEFACTORIAL3
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL3 :
     %26 = %22 == %23
     ifFalse %26 goto FACTORIAL3
     %22 = %24
     goto ENDFACTORIAL3
  label FACTORIAL3 :
     %26 = %24 < %25
     ifFalse %26 goto ENDFACTORIAL3
     %22 = %22 * %25
     %25 = %25 - %24
     goto FACTORIAL3
  label ENDFACTORIAL3 :
     %27 = - %22
     %28 = float %27
     %29 = %28 +. x
     %30 = 0
     %31 = A[%30]
     %32 = 2
     %33 = %31 / %32
     %34 = %33
     %35 = 0
     %36 = 1
     %37 = %34 - %36
     %38 = %34 < %35
     ifFalse %38 goto BASEFACTORIAL4
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL4 :
     %38 = %34 == %35
     ifFalse %38 goto FACTORIAL4
     %34 = %36
     goto ENDFACTORIAL4
  label FACTORIAL4 :
     %38 = %36 < %37
     ifFalse %38 goto ENDFACTORIAL4
     %34 = %34 * %37
     %37 = %37 - %36
     goto FACTORIAL4
  label ENDFACTORIAL4 :
     %39 = a
     %40 = 0
     %41 = 1
     %42 = %39 - %41
     %43 = %39 < %40
     ifFalse %43 goto BASEFACTORIAL5
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL5 :
     %43 = %39 == %40
     ifFalse %43 goto FACTORIAL5
     %39 = %41
     goto ENDFACTORIAL5
  label FACTORIAL5 :
     %43 = %41 < %42
     ifFalse %43 goto ENDFACTORIAL5
     %39 = %39 * %42
     %42 = %42 - %41
     goto FACTORIAL5
  label ENDFACTORIAL5 :
     %44 = %34 * %39
     %47 = float %44
     %45 = %29 <=. %47
     ifFalse %45 goto Endif1
     %48 = 1
     %49 = A[%48]
     %50 = %49
     %51 = 0
     %52 = 1
     %53 = %50 - %52
     %54 = %50 < %51
     ifFalse %54 goto BASEFACTORIAL6
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL6 :
     %54 = %50 == %51
     ifFalse %54 goto FACTORIAL6
     %50 = %52
     goto ENDFACTORIAL6
  label FACTORIAL6 :
     %54 = %52 < %53
     ifFalse %54 goto ENDFACTORIAL6
     %50 = %50 * %53
     %53 = %53 - %52
     goto FACTORIAL6
  label ENDFACTORIAL6 :
     %55 = %50 - b
     %56 = float %55
     x = %56
     %57 = 1
     %58 = 2
     %59 = b - %58
     %60 = %59
     %61 = 0
     %62 = 1
     %63 = %60 - %62
     %64 = %60 < %61
     ifFalse %64 goto BASEFACTORIAL7
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL7 :
     %64 = %60 == %61
     ifFalse %64 goto FACTORIAL7
     %60 = %62
     goto ENDFACTORIAL7
  label FACTORIAL7 :
     %64 = %62 < %63
     ifFalse %64 goto ENDFACTORIAL7
     %60 = %60 * %63
     %63 = %63 - %62
     goto FACTORIAL7
  label ENDFACTORIAL7 :
     %65 = %60
     %66 = 0
     %67 = 1
     %68 = %65 - %67
     %69 = %65 < %66
     ifFalse %69 goto BASEFACTORIAL8
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL8 :
     %69 = %65 == %66
     ifFalse %69 goto FACTORIAL8
     %65 = %67
     goto ENDFACTORIAL8
  label FACTORIAL8 :
     %69 = %67 < %68
     ifFalse %69 goto ENDFACTORIAL8
     %65 = %65 * %68
     %68 = %68 - %67
     goto FACTORIAL8
  label ENDFACTORIAL8 :
     A[%57] = %65
     writes "A[1]="
     %70 = 1
     %71 = A[%70]
     writei %71
     writes "\n"
  label Endif1 :
     writei a
     writes " "
     writei b
     writes "\n"
     writes "A: "
     %72 = 0
     %73 = A[%72]
     writei %73
     writes " "
     %74 = 1
     %75 = A[%74]
     writei %75
     writes "\n"
     writef x
     writes " "
     writef y
     writes "\n"
     return
endfunction


