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
     readi b
     %3 = b
     %4 = 0
     %5 = 1
     %6 = %3 - %5
     %7 = %3 < %4
     ifFalse %7 goto BASEFACTORIAL1
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL1 :
     %7 = %3 == %4
     ifFalse %7 goto FACTORIAL1
     %3 = %5
     goto ENDFACTORIAL1
  label FACTORIAL1 :
     %7 = %5 < %6
     ifFalse %7 goto ENDFACTORIAL1
     %3 = %3 * %6
     %6 = %6 - %5
     goto FACTORIAL1
  label ENDFACTORIAL1 :
     %8 = %3 / b
     a = %8
     %9 = 0
     %10 = 8
     A[%9] = %10
     %11 = 1
     %12 = 9
     A[%11] = %12
     %13 = a
     %14 = 0
     %15 = 1
     %16 = %13 - %15
     %17 = %13 < %14
     ifFalse %17 goto BASEFACTORIAL2
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL2 :
     %17 = %13 == %14
     ifFalse %17 goto FACTORIAL2
     %13 = %15
     goto ENDFACTORIAL2
  label FACTORIAL2 :
     %17 = %15 < %16
     ifFalse %17 goto ENDFACTORIAL2
     %13 = %13 * %16
     %16 = %16 - %15
     goto FACTORIAL2
  label ENDFACTORIAL2 :
     %18 = float %13
     %19 = %18 *. x
     y = %19
  label While9 :
     %20 = 100
     %23 = float %20
     %21 = x <. %23
     ifFalse %21 goto EndWhile9
     %24 = b
     %25 = 0
     %26 = 1
     %27 = %24 - %26
     %28 = %24 < %25
     ifFalse %28 goto BASEFACTORIAL3
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL3 :
     %28 = %24 == %25
     ifFalse %28 goto FACTORIAL3
     %24 = %26
     goto ENDFACTORIAL3
  label FACTORIAL3 :
     %28 = %26 < %27
     ifFalse %28 goto ENDFACTORIAL3
     %24 = %24 * %27
     %27 = %27 - %26
     goto FACTORIAL3
  label ENDFACTORIAL3 :
     %29 = - %24
     %30 = float %29
     %31 = %30 +. x
     %32 = 0
     %33 = A[%32]
     %34 = 2
     %35 = %33 / %34
     %36 = %35
     %37 = 0
     %38 = 1
     %39 = %36 - %38
     %40 = %36 < %37
     ifFalse %40 goto BASEFACTORIAL4
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL4 :
     %40 = %36 == %37
     ifFalse %40 goto FACTORIAL4
     %36 = %38
     goto ENDFACTORIAL4
  label FACTORIAL4 :
     %40 = %38 < %39
     ifFalse %40 goto ENDFACTORIAL4
     %36 = %36 * %39
     %39 = %39 - %38
     goto FACTORIAL4
  label ENDFACTORIAL4 :
     %41 = a
     %42 = 0
     %43 = 1
     %44 = %41 - %43
     %45 = %41 < %42
     ifFalse %45 goto BASEFACTORIAL5
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL5 :
     %45 = %41 == %42
     ifFalse %45 goto FACTORIAL5
     %41 = %43
     goto ENDFACTORIAL5
  label FACTORIAL5 :
     %45 = %43 < %44
     ifFalse %45 goto ENDFACTORIAL5
     %41 = %41 * %44
     %44 = %44 - %43
     goto FACTORIAL5
  label ENDFACTORIAL5 :
     %46 = %36 * %41
     %49 = float %46
     %48 = %31 <=. %49
     %47 = not %48
     ifFalse %47 goto If1
     %50 = 1
     %51 = A[%50]
     %52 = %51
     %53 = 0
     %54 = 1
     %55 = %52 - %54
     %56 = %52 < %53
     ifFalse %56 goto BASEFACTORIAL6
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL6 :
     %56 = %52 == %53
     ifFalse %56 goto FACTORIAL6
     %52 = %54
     goto ENDFACTORIAL6
  label FACTORIAL6 :
     %56 = %54 < %55
     ifFalse %56 goto ENDFACTORIAL6
     %52 = %52 * %55
     %55 = %55 - %54
     goto FACTORIAL6
  label ENDFACTORIAL6 :
     %57 = %52 - b
     %58 = float %57
     x = %58
     %59 = 1
     %60 = 1
     %61 = b + %60
     %62 = %61
     %63 = 0
     %64 = 1
     %65 = %62 - %64
     %66 = %62 < %63
     ifFalse %66 goto BASEFACTORIAL7
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL7 :
     %66 = %62 == %63
     ifFalse %66 goto FACTORIAL7
     %62 = %64
     goto ENDFACTORIAL7
  label FACTORIAL7 :
     %66 = %64 < %65
     ifFalse %66 goto ENDFACTORIAL7
     %62 = %62 * %65
     %65 = %65 - %64
     goto FACTORIAL7
  label ENDFACTORIAL7 :
     %67 = %62
     %68 = 0
     %69 = 1
     %70 = %67 - %69
     %71 = %67 < %68
     ifFalse %71 goto BASEFACTORIAL8
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL8 :
     %71 = %67 == %68
     ifFalse %71 goto FACTORIAL8
     %67 = %69
     goto ENDFACTORIAL8
  label FACTORIAL8 :
     %71 = %69 < %70
     ifFalse %71 goto ENDFACTORIAL8
     %67 = %67 * %70
     %70 = %70 - %69
     goto FACTORIAL8
  label ENDFACTORIAL8 :
     A[%59] = %67
     goto Else1
  label If1 :
     readf x
  label Else1 :
     writes "loop "
     %72 = 1
     %73 = A[%72]
     writei %73
     writes " "
     writef x
     writes "\n"
     goto While9
  label EndWhile9 :
     %74 = 12
     %75 = b - %74
     writei %75
     writes "\n"
     %76 = 12
     %77 = b - %76
     %78 = %77
     %79 = 0
     %80 = 1
     %81 = %78 - %80
     %82 = %78 < %79
     ifFalse %82 goto BASEFACTORIAL10
     halt "Invalid integer value in math operation."
  label BASEFACTORIAL10 :
     %82 = %78 == %79
     ifFalse %82 goto FACTORIAL10
     %78 = %80
     goto ENDFACTORIAL10
  label FACTORIAL10 :
     %82 = %80 < %81
     ifFalse %82 goto ENDFACTORIAL10
     %78 = %78 * %81
     %81 = %81 - %80
     goto FACTORIAL10
  label ENDFACTORIAL10 :
     %83 = 5
     %84 = %78 * %83
     a = %84
     writes "end "
     writef y
     writes "\n"
     return
endfunction


