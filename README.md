# Tiny-C Compiler

This project is a completed implementation of a compiler for the TinyC language, which is a subset of the C programming language specification defined by the International Standard ISO/IEC 9899:1999 (E). The project was completed as part of a series of assignments in a course on compiler design.

The lexical specification and phase structure grammar of tinyC have been defined in Assignments 3 and 4, respectively. The semantic actions have been implemented in Assignment 5 to translate a tinyC program into an array of 3-address quads, a supporting symbol table, and other auxiliary data structures. Finally, a target code translator has been developed in Assignment 6 to generate assembly language code for x86-64 architecture from the 3-address quad array.

All the specifications for the lexical grammar, phase structure grammar, and semantic actions have been given in the respective assignment descriptions in the `problem statements` folder.

## Implementation Details

The tinyC compiler is implemented using Lex and Bison, which are tools for generating lexical analyzers and parsers, respectively. The lexical analyzer tokenizes the input tinyC program, while the parser generates an abstract syntax tree (AST) based on the phase structure grammar of the language.

The AST is then processed to generate 3-address quads, which are intermediate representations of the program. The generated quads are stored in an array along with a supporting symbol table and other auxiliary data structures.

Finally, the target code translator converts the 3-address quad array into assembly language code for the x86-64 architecture. The generated assembly code can be translated with the gcc assembler to produce the final executable codes for the tinyC program.

## Definitions

* The lexical specification and phase structure grammar of tinyC can be found in Assignments 3 and 4, respectively, in the "problem statements" folder.
* The semantic actions for translating a tinyC program into 3-address quads are defined in Assignment 5 in the "problem statements" folder.
* The target code translator for generating x86-64 assembly language code from the 3-address quad array is defined in Assignment 6 in the "problem statements" folder.

## Modules:

-   [ass6_20CS30042.l](ass6_20CS30042.l) : The lexical analyzer for tinyC
-   [ass6_20CS30042.y](ass6_20CS30042.y) : The parser for tinyC
-   [ass6_20CS30042.c](ass6_20CS30042.c) : The implementaion of I/O library
-   [myl.h](myl.h) : The header file for the library functions
-   [ass6_20CS30042_translator.h](ass6_20CS30042_translator.h) : The header file for the translator
-   [ass6_20CS30042_translator.cxx](ass6_20CS30042_translator.cxx) : The implementation of the translator
-   [ass6_20CS30042_target_translator.cxx](ass6_20CS30042_target_translator.cxx) : The implementation of the target translator

## Usage:

- Install flex and bison

```bash
sudo apt-get install flex
sudo apt-get install bison
```

-   Compile parser.out

```bash
make
```

-   run test

```bash
make test
```

-   clean

```bash
make clean
```

-   clean test files

```bash
make testclean
```

-   refer makefile for more details