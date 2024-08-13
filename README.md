# Compilers (CL) and the ASL Compiler 🎯
## Description
This repository contains various theoretical resources, previous final exams, laboratory exams, and my solution to the ASL project for the Compilers (CL) subject 2022-23 Q2 FIB-GEI. In this subject, I learned about practical and advanced theory of computation topics, compilers and interpreters concepts, parsing and lexing algorithms, semantic analysis, intermediate representation lowering, optimization algorithms, and the main types of compilers (AOT, JIT).

## The ASL Compiler
### Description
The ASL Compiler is designed to compile programs written in ASL (A Simple Language), an imperative high-level programming language. ASL supports basic data types, control structures, and arrays.

### Execution and Compilation
To use the ASL compiler located in the /asl/ directory, ensure the following packages are installed:

- ANTLR v4
- ANTLR C++ Runtime
- Make
To compile and execute a program, use:

```sh
    ./main aslfile.asl
```

If successful, the compiler generates a t-Code intermediate representation (using LLVM) that can be executed with a virtual machine in the /tvm/ directory.

### ASL Samples
Examples of ASL programs can be found in the project-asl-compiler/examples directory.

## ASL Language
ASL (A Simple Language) is an imperative programming language with the following features:

### Data Types:
- int (Integer)
- float (Real)
- bool (Boolean)
- char (Character)
- Arrays are defined as array [size] of type, where size is an integer and type is a basic type.

### Variable Declarations:
Variables must be declared at the beginning of a function using var id1, id2, ... : type.

### Functions:
Declared with func and endfunc. Functions have parameters with types and may return basic types. Parameters are passed by value, but arrays are passed by reference. Functions can return early with a return statement.

### Operators:

Arithmetic: +, -, *, /, %
Relational: ==, !=, >, >=, <, <=
Boolean: and, or, not
Array indexing is highest precedence.
Instructions:

Assignment: var x : int; x = 5;
Input/Output: read x;, write x + 1;, write "Message";
Return: return x; or return; for void functions.
Control Structures:

Conditional: if condition then ... else ... endif
Loop: while condition do ... endwhile

## Credits
- Jose Miguel Rivero Almeida
- Alexandre Ros Roger @alexland7219
- Walter J. Troiani Vargas @eZWALT


## License
This project is licensed under the GPLv3 License. See the LICENSE file for details.