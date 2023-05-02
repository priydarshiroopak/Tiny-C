/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ass6_20CS30042.y"

    #include "ass6_20CS30042_translator.h"
    extern int yylex();
    extern int yylineno;
    void yyerror(string);
    void printInfo(string s1, string s2);

#line 79 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AUTO = 258,                    /* AUTO  */
    BREAK = 259,                   /* BREAK  */
    CASE = 260,                    /* CASE  */
    CHARTYPE = 261,                /* CHARTYPE  */
    CONST = 262,                   /* CONST  */
    CONTINUE = 263,                /* CONTINUE  */
    DEFAULT = 264,                 /* DEFAULT  */
    DO = 265,                      /* DO  */
    DOUBLE = 266,                  /* DOUBLE  */
    ELSE = 267,                    /* ELSE  */
    ENUM = 268,                    /* ENUM  */
    EXTERN = 269,                  /* EXTERN  */
    FLOATTYPE = 270,               /* FLOATTYPE  */
    FOR = 271,                     /* FOR  */
    GOTO = 272,                    /* GOTO  */
    IF = 273,                      /* IF  */
    INLINE = 274,                  /* INLINE  */
    INTTYPE = 275,                 /* INTTYPE  */
    LONG = 276,                    /* LONG  */
    REGISTER = 277,                /* REGISTER  */
    RESTRICT = 278,                /* RESTRICT  */
    RETURN = 279,                  /* RETURN  */
    SHORT = 280,                   /* SHORT  */
    SIGNED = 281,                  /* SIGNED  */
    SIZEOF = 282,                  /* SIZEOF  */
    STATIC = 283,                  /* STATIC  */
    STRUCT = 284,                  /* STRUCT  */
    SWITCH = 285,                  /* SWITCH  */
    TYPEDEF = 286,                 /* TYPEDEF  */
    UNION = 287,                   /* UNION  */
    UNSIGNED = 288,                /* UNSIGNED  */
    VOIDTYPE = 289,                /* VOIDTYPE  */
    VOLATILE = 290,                /* VOLATILE  */
    WHILE = 291,                   /* WHILE  */
    _BOOL = 292,                   /* _BOOL  */
    _COMPLEX = 293,                /* _COMPLEX  */
    _IMAGINARY = 294,              /* _IMAGINARY  */
    IDENTIFIER = 295,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 296,        /* INTEGER_CONSTANT  */
    FLOATING_CONSTANT = 297,       /* FLOATING_CONSTANT  */
    CHARACTER_CONSTANT = 298,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 299,          /* STRING_LITERAL  */
    LEFT_PARENTHESIS = 300,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 301,       /* RIGHT_PARENTHESIS  */
    LEFT_SQUARE_BRACE = 302,       /* LEFT_SQUARE_BRACE  */
    RIGHT_SQUARE_BRACE = 303,      /* RIGHT_SQUARE_BRACE  */
    LEFT_CURLY_BRACE = 304,        /* LEFT_CURLY_BRACE  */
    RIGHT_CURLY_BRACE = 305,       /* RIGHT_CURLY_BRACE  */
    INCREMENT = 306,               /* INCREMENT  */
    DECREMENT = 307,               /* DECREMENT  */
    PLUS = 308,                    /* PLUS  */
    MINUS = 309,                   /* MINUS  */
    ASTERISK = 310,                /* ASTERISK  */
    SLASH = 311,                   /* SLASH  */
    MODULO = 312,                  /* MODULO  */
    EQUALS = 313,                  /* EQUALS  */
    NOT_EQUALS = 314,              /* NOT_EQUALS  */
    LESS_THAN = 315,               /* LESS_THAN  */
    GREATER_THAN = 316,            /* GREATER_THAN  */
    LESS_EQUAL_THAN = 317,         /* LESS_EQUAL_THAN  */
    GREATER_EQUAL_THAN = 318,      /* GREATER_EQUAL_THAN  */
    BITWISE_AND = 319,             /* BITWISE_AND  */
    BITWISE_OR = 320,              /* BITWISE_OR  */
    BITWISE_XOR = 321,             /* BITWISE_XOR  */
    LEFT_SHIFT = 322,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 323,             /* RIGHT_SHIFT  */
    TILDE = 324,                   /* TILDE  */
    LOGICAL_AND = 325,             /* LOGICAL_AND  */
    LOGICAL_OR = 326,              /* LOGICAL_OR  */
    EXCLAMATION = 327,             /* EXCLAMATION  */
    ASSIGNMENT = 328,              /* ASSIGNMENT  */
    PLUS_ASSIGNMENT = 329,         /* PLUS_ASSIGNMENT  */
    MINUS_ASSIGNMENT = 330,        /* MINUS_ASSIGNMENT  */
    ASTERISK_ASSIGNMENT = 331,     /* ASTERISK_ASSIGNMENT  */
    SLASH_ASSIGNMENT = 332,        /* SLASH_ASSIGNMENT  */
    MODULO_ASSIGNMENT = 333,       /* MODULO_ASSIGNMENT  */
    BITWISE_AND_ASSIGNMENT = 334,  /* BITWISE_AND_ASSIGNMENT  */
    BITWISE_OR_ASSIGNMENT = 335,   /* BITWISE_OR_ASSIGNMENT  */
    BITWISE_XOR_ASSIGNMENT = 336,  /* BITWISE_XOR_ASSIGNMENT  */
    LEFT_SHIFT_ASSIGNMENT = 337,   /* LEFT_SHIFT_ASSIGNMENT  */
    RIGHT_SHIFT_ASSIGNMENT = 338,  /* RIGHT_SHIFT_ASSIGNMENT  */
    QUESTION_MARK = 339,           /* QUESTION_MARK  */
    DOT = 340,                     /* DOT  */
    ARROW = 341,                   /* ARROW  */
    COLON = 342,                   /* COLON  */
    SEMI_COLON = 343,              /* SEMI_COLON  */
    ELLIPSIS = 344,                /* ELLIPSIS  */
    COMMA = 345,                   /* COMMA  */
    HASH = 346,                    /* HASH  */
    INVALID_TOKEN = 347,           /* INVALID_TOKEN  */
    THEN = 348                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHARTYPE 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOATTYPE 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INLINE 274
#define INTTYPE 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOIDTYPE 289
#define VOLATILE 290
#define WHILE 291
#define _BOOL 292
#define _COMPLEX 293
#define _IMAGINARY 294
#define IDENTIFIER 295
#define INTEGER_CONSTANT 296
#define FLOATING_CONSTANT 297
#define CHARACTER_CONSTANT 298
#define STRING_LITERAL 299
#define LEFT_PARENTHESIS 300
#define RIGHT_PARENTHESIS 301
#define LEFT_SQUARE_BRACE 302
#define RIGHT_SQUARE_BRACE 303
#define LEFT_CURLY_BRACE 304
#define RIGHT_CURLY_BRACE 305
#define INCREMENT 306
#define DECREMENT 307
#define PLUS 308
#define MINUS 309
#define ASTERISK 310
#define SLASH 311
#define MODULO 312
#define EQUALS 313
#define NOT_EQUALS 314
#define LESS_THAN 315
#define GREATER_THAN 316
#define LESS_EQUAL_THAN 317
#define GREATER_EQUAL_THAN 318
#define BITWISE_AND 319
#define BITWISE_OR 320
#define BITWISE_XOR 321
#define LEFT_SHIFT 322
#define RIGHT_SHIFT 323
#define TILDE 324
#define LOGICAL_AND 325
#define LOGICAL_OR 326
#define EXCLAMATION 327
#define ASSIGNMENT 328
#define PLUS_ASSIGNMENT 329
#define MINUS_ASSIGNMENT 330
#define ASTERISK_ASSIGNMENT 331
#define SLASH_ASSIGNMENT 332
#define MODULO_ASSIGNMENT 333
#define BITWISE_AND_ASSIGNMENT 334
#define BITWISE_OR_ASSIGNMENT 335
#define BITWISE_XOR_ASSIGNMENT 336
#define LEFT_SHIFT_ASSIGNMENT 337
#define RIGHT_SHIFT_ASSIGNMENT 338
#define QUESTION_MARK 339
#define DOT 340
#define ARROW 341
#define COLON 342
#define SEMI_COLON 343
#define ELLIPSIS 344
#define COMMA 345
#define HASH 346
#define INVALID_TOKEN 347
#define THEN 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "ass6_20CS30042.y"

    int intVal;
    char *floatVal;
    char *charVal;
    char *strVal;
    char *identifierVal;
    char *unaryOperator;
    int instrNo;
    int parameterCount;
    Array *array;
    Statement *statement;
    Expression *expression;
    Symbol *symbol;
    SymbolType *symbolType;

#line 334 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO = 3,                       /* AUTO  */
  YYSYMBOL_BREAK = 4,                      /* BREAK  */
  YYSYMBOL_CASE = 5,                       /* CASE  */
  YYSYMBOL_CHARTYPE = 6,                   /* CHARTYPE  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ENUM = 13,                      /* ENUM  */
  YYSYMBOL_EXTERN = 14,                    /* EXTERN  */
  YYSYMBOL_FLOATTYPE = 15,                 /* FLOATTYPE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_GOTO = 17,                      /* GOTO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_INLINE = 19,                    /* INLINE  */
  YYSYMBOL_INTTYPE = 20,                   /* INTTYPE  */
  YYSYMBOL_LONG = 21,                      /* LONG  */
  YYSYMBOL_REGISTER = 22,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 23,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_SHORT = 25,                     /* SHORT  */
  YYSYMBOL_SIGNED = 26,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 27,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 28,                    /* STATIC  */
  YYSYMBOL_STRUCT = 29,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 31,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 32,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 33,                  /* UNSIGNED  */
  YYSYMBOL_VOIDTYPE = 34,                  /* VOIDTYPE  */
  YYSYMBOL_VOLATILE = 35,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL__BOOL = 37,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 38,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 39,                /* _IMAGINARY  */
  YYSYMBOL_IDENTIFIER = 40,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 41,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 42,         /* FLOATING_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 43,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 44,            /* STRING_LITERAL  */
  YYSYMBOL_LEFT_PARENTHESIS = 45,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 46,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_LEFT_SQUARE_BRACE = 47,         /* LEFT_SQUARE_BRACE  */
  YYSYMBOL_RIGHT_SQUARE_BRACE = 48,        /* RIGHT_SQUARE_BRACE  */
  YYSYMBOL_LEFT_CURLY_BRACE = 49,          /* LEFT_CURLY_BRACE  */
  YYSYMBOL_RIGHT_CURLY_BRACE = 50,         /* RIGHT_CURLY_BRACE  */
  YYSYMBOL_INCREMENT = 51,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 52,                 /* DECREMENT  */
  YYSYMBOL_PLUS = 53,                      /* PLUS  */
  YYSYMBOL_MINUS = 54,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 55,                  /* ASTERISK  */
  YYSYMBOL_SLASH = 56,                     /* SLASH  */
  YYSYMBOL_MODULO = 57,                    /* MODULO  */
  YYSYMBOL_EQUALS = 58,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 59,                /* NOT_EQUALS  */
  YYSYMBOL_LESS_THAN = 60,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 61,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL_THAN = 62,           /* LESS_EQUAL_THAN  */
  YYSYMBOL_GREATER_EQUAL_THAN = 63,        /* GREATER_EQUAL_THAN  */
  YYSYMBOL_BITWISE_AND = 64,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 65,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 66,               /* BITWISE_XOR  */
  YYSYMBOL_LEFT_SHIFT = 67,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 68,               /* RIGHT_SHIFT  */
  YYSYMBOL_TILDE = 69,                     /* TILDE  */
  YYSYMBOL_LOGICAL_AND = 70,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 71,                /* LOGICAL_OR  */
  YYSYMBOL_EXCLAMATION = 72,               /* EXCLAMATION  */
  YYSYMBOL_ASSIGNMENT = 73,                /* ASSIGNMENT  */
  YYSYMBOL_PLUS_ASSIGNMENT = 74,           /* PLUS_ASSIGNMENT  */
  YYSYMBOL_MINUS_ASSIGNMENT = 75,          /* MINUS_ASSIGNMENT  */
  YYSYMBOL_ASTERISK_ASSIGNMENT = 76,       /* ASTERISK_ASSIGNMENT  */
  YYSYMBOL_SLASH_ASSIGNMENT = 77,          /* SLASH_ASSIGNMENT  */
  YYSYMBOL_MODULO_ASSIGNMENT = 78,         /* MODULO_ASSIGNMENT  */
  YYSYMBOL_BITWISE_AND_ASSIGNMENT = 79,    /* BITWISE_AND_ASSIGNMENT  */
  YYSYMBOL_BITWISE_OR_ASSIGNMENT = 80,     /* BITWISE_OR_ASSIGNMENT  */
  YYSYMBOL_BITWISE_XOR_ASSIGNMENT = 81,    /* BITWISE_XOR_ASSIGNMENT  */
  YYSYMBOL_LEFT_SHIFT_ASSIGNMENT = 82,     /* LEFT_SHIFT_ASSIGNMENT  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGNMENT = 83,    /* RIGHT_SHIFT_ASSIGNMENT  */
  YYSYMBOL_QUESTION_MARK = 84,             /* QUESTION_MARK  */
  YYSYMBOL_DOT = 85,                       /* DOT  */
  YYSYMBOL_ARROW = 86,                     /* ARROW  */
  YYSYMBOL_COLON = 87,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 88,                /* SEMI_COLON  */
  YYSYMBOL_ELLIPSIS = 89,                  /* ELLIPSIS  */
  YYSYMBOL_COMMA = 90,                     /* COMMA  */
  YYSYMBOL_HASH = 91,                      /* HASH  */
  YYSYMBOL_INVALID_TOKEN = 92,             /* INVALID_TOKEN  */
  YYSYMBOL_THEN = 93,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_primary_expression = 95,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 96,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 97, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 98,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 99,          /* unary_expression  */
  YYSYMBOL_unary_operator = 100,           /* unary_operator  */
  YYSYMBOL_cast_expression = 101,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 102, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 103,      /* additive_expression  */
  YYSYMBOL_shift_expression = 104,         /* shift_expression  */
  YYSYMBOL_relational_expression = 105,    /* relational_expression  */
  YYSYMBOL_equality_expression = 106,      /* equality_expression  */
  YYSYMBOL_AND_expression = 107,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 108,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 109,  /* inclusive_OR_expression  */
  YYSYMBOL_M = 110,                        /* M  */
  YYSYMBOL_N = 111,                        /* N  */
  YYSYMBOL_logical_AND_expression = 112,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 113,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 114,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 116,      /* assignment_operator  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_constant_expression = 118,      /* constant_expression  */
  YYSYMBOL_declaration = 119,              /* declaration  */
  YYSYMBOL_init_declarator_list_opt = 120, /* init_declarator_list_opt  */
  YYSYMBOL_declaration_specifiers = 121,   /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 122, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 123,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 124,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 125,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 126,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 127, /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 128, /* specifier_qualifier_list_opt  */
  YYSYMBOL_enum_specifier = 129,           /* enum_specifier  */
  YYSYMBOL_identifier_opt = 130,           /* identifier_opt  */
  YYSYMBOL_enumerator_list = 131,          /* enumerator_list  */
  YYSYMBOL_enumerator = 132,               /* enumerator  */
  YYSYMBOL_type_qualifier = 133,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 134,       /* function_specifier  */
  YYSYMBOL_declarator = 135,               /* declarator  */
  YYSYMBOL_change_scope = 136,             /* change_scope  */
  YYSYMBOL_direct_declarator = 137,        /* direct_declarator  */
  YYSYMBOL_type_qualifier_list_opt = 138,  /* type_qualifier_list_opt  */
  YYSYMBOL_pointer = 139,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 140,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 141,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 142,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 143,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 144,          /* identifier_list  */
  YYSYMBOL_type_name = 145,                /* type_name  */
  YYSYMBOL_initialiser = 146,              /* initialiser  */
  YYSYMBOL_initialiser_list = 147,         /* initialiser_list  */
  YYSYMBOL_designation_opt = 148,          /* designation_opt  */
  YYSYMBOL_designation = 149,              /* designation  */
  YYSYMBOL_designator_list = 150,          /* designator_list  */
  YYSYMBOL_designator = 151,               /* designator  */
  YYSYMBOL_statement = 152,                /* statement  */
  YYSYMBOL_labeled_statement = 153,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 154,       /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 155,      /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 156,          /* block_item_list  */
  YYSYMBOL_block_item = 157,               /* block_item  */
  YYSYMBOL_expression_statement = 158,     /* expression_statement  */
  YYSYMBOL_expression_opt = 159,           /* expression_opt  */
  YYSYMBOL_selection_statement = 160,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 161,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 162,           /* jump_statement  */
  YYSYMBOL_translation_unit = 163,         /* translation_unit  */
  YYSYMBOL_external_declaration = 164,     /* external_declaration  */
  YYSYMBOL_function_definition = 165,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 166,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 167          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1099

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   348


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   142,   142,   146,   150,   154,   158,   165,   171,   177,
     195,   200,   202,   204,   210,   217,   219,   226,   230,   236,
     241,   249,   252,   257,   262,   288,   290,   296,   298,   300,
     302,   304,   306,   311,   313,   334,   345,   362,   379,   398,
     401,   409,   420,   422,   430,   448,   450,   461,   472,   483,
     497,   499,   510,   525,   527,   537,   539,   549,   551,   570,
     572,   577,   579,   589,   591,   602,   604,   623,   625,   644,
     646,   648,   650,   652,   654,   656,   658,   660,   662,   664,
     669,   671,   676,   682,   687,   690,   693,   695,   697,   699,
     704,   707,   711,   713,   718,   720,   730,   732,   734,   736,
     741,   743,   746,   748,   750,   752,   754,   756,   758,   760,
     762,   764,   766,   771,   773,   778,   781,   785,   787,   789,
     794,   797,   801,   803,   808,   810,   815,   817,   819,   824,
     829,   837,   841,   850,   855,   857,   859,   861,   876,   892,
     894,   896,   898,   900,   902,   916,   918,   935,   938,   947,
     952,   960,   962,   967,   969,   974,   976,   981,   986,   991,
     993,   998,  1003,  1005,  1007,  1012,  1014,  1018,  1021,  1025,
    1030,  1032,  1037,  1039,  1045,  1047,  1049,  1053,  1055,  1057,
    1062,  1064,  1066,  1086,  1094,  1096,  1100,  1102,  1110,  1112,
    1117,  1122,  1125,  1129,  1135,  1142,  1148,  1156,  1163,  1172,
    1177,  1179,  1181,  1183,  1197,  1199,  1204,  1206,  1212,  1226,
    1229,  1233,  1235
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AUTO", "BREAK",
  "CASE", "CHARTYPE", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "ENUM", "EXTERN", "FLOATTYPE", "FOR", "GOTO", "IF", "INLINE",
  "INTTYPE", "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED",
  "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOIDTYPE", "VOLATILE", "WHILE", "_BOOL", "_COMPLEX", "_IMAGINARY",
  "IDENTIFIER", "INTEGER_CONSTANT", "FLOATING_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "LEFT_SQUARE_BRACE", "RIGHT_SQUARE_BRACE",
  "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "INCREMENT", "DECREMENT",
  "PLUS", "MINUS", "ASTERISK", "SLASH", "MODULO", "EQUALS", "NOT_EQUALS",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL_THAN", "GREATER_EQUAL_THAN",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "LEFT_SHIFT", "RIGHT_SHIFT",
  "TILDE", "LOGICAL_AND", "LOGICAL_OR", "EXCLAMATION", "ASSIGNMENT",
  "PLUS_ASSIGNMENT", "MINUS_ASSIGNMENT", "ASTERISK_ASSIGNMENT",
  "SLASH_ASSIGNMENT", "MODULO_ASSIGNMENT", "BITWISE_AND_ASSIGNMENT",
  "BITWISE_OR_ASSIGNMENT", "BITWISE_XOR_ASSIGNMENT",
  "LEFT_SHIFT_ASSIGNMENT", "RIGHT_SHIFT_ASSIGNMENT", "QUESTION_MARK",
  "DOT", "ARROW", "COLON", "SEMI_COLON", "ELLIPSIS", "COMMA", "HASH",
  "INVALID_TOKEN", "THEN", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list_opt",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "M", "N", "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "change_scope", "direct_declarator",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initialiser", "initialiser_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list_opt", "block_item_list", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1026,  -303,  -303,  -303,  -303,   -26,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,    93,  1026,  1026,  -303,  1026,  1026,   989,
    -303,  -303,   -31,    15,  -303,    93,    18,   -49,   -42,  -303,
     378,   -24,     2,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
      36,    37,  -303,    48,    18,  -303,    93,   756,  -303,    93,
    -303,  1026,    69,   645,   -24,    43,    16,  -303,  -303,  -303,
    -303,  -303,    59,   822,  -303,  -303,  -303,  -303,  -303,   606,
      -1,   855,   855,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
      70,   355,   888,  -303,    80,    99,    98,    81,   124,    75,
      83,    94,    76,   -33,  -303,  -303,  -303,   113,  -303,  -303,
     948,   -22,   723,  -303,   120,   131,   684,   888,  -303,    10,
     606,  -303,  -303,   -20,  1060,  -303,  1060,   134,   888,   147,
      21,   756,  -303,    55,  -303,   606,  -303,  -303,   888,   888,
    -303,  -303,   152,   157,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,   888,  -303,  -303,   888,   888,
     888,   888,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   888,   888,  -303,  -303,   114,   314,  -303,    93,
     153,   112,  -303,  -303,   163,   156,   723,  -303,  -303,   888,
    -303,   158,   162,  -303,  -303,  -303,  -303,   159,  -303,   888,
    -303,  -303,  -303,   789,   165,  -303,  -303,    35,  -303,  -303,
    -303,   169,   170,   130,  -303,   -36,  -303,  -303,  -303,  -303,
    -303,  -303,    80,    80,    99,    99,    98,    98,    98,    98,
      81,    81,   124,    75,    83,   888,   888,  -303,   123,   888,
     133,   135,  -303,   178,   184,   180,   888,   181,  -303,   140,
     314,   141,  -303,  -303,  -303,  -303,   182,   186,  -303,  -303,
     142,  -303,  -303,  -303,  -303,  -303,   275,  -303,  -303,   190,
     191,  -303,  -303,   195,  -303,    -1,  -303,  -303,  -303,   756,
     195,  -303,   888,  -303,    94,    76,   888,  -303,   161,  -303,
     556,   556,   499,   164,   888,   166,   888,   201,   556,   199,
    -303,   439,  -303,  -303,  -303,  -303,  -303,    22,  -303,  -303,
     141,   556,  -303,  -303,   888,   167,  -303,   -13,  -303,   -11,
     888,  -303,  -303,  -303,  -303,    60,   171,  -303,   215,   172,
    -303,  -303,   556,   -10,  -303,  -303,   212,   888,   888,   556,
    -303,  -303,   888,   888,   213,   173,  -303,   556,  -303,    -9,
     556,  -303,   250,  -303,   176,  -303,   888,  -303,  -303,  -303,
     556,   219,  -303,  -303,   556,  -303
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   126,   106,   121,    96,   105,   129,   103,
     104,    99,   127,   102,   107,    97,   108,   100,   128,   109,
     110,   111,   207,    85,    91,    91,   112,    91,    91,     0,
     204,   206,   119,     0,   133,     0,   148,     0,    84,    92,
      94,   131,     0,    90,    86,    87,    88,    89,     1,   205,
       0,     0,   151,   149,   147,    83,     0,     0,   211,    85,
     132,   209,   132,     0,   130,   124,     0,   122,   134,   150,
     152,    93,    94,     0,     2,     3,     4,     5,     6,     0,
     168,     0,     0,    29,    30,    28,    27,    31,    32,     8,
      21,    33,     0,    35,    39,    42,    45,    50,    53,    55,
      57,    61,    63,    65,    67,   162,    95,     0,   212,   159,
       0,     0,     0,   138,    28,     0,     0,     0,   117,     0,
       0,    25,    80,     0,   116,   161,   116,     0,     0,     0,
       0,     0,   167,     0,   170,     0,    22,    23,    18,     0,
      13,    14,     0,     0,    69,    73,    74,    70,    71,    72,
      77,    79,    78,    75,    76,     0,    33,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    59,     0,   185,   146,   158,
       0,   153,   155,   145,     0,     0,     0,   143,   137,     0,
     136,    28,     0,    82,   125,   118,   123,     0,     7,     0,
     115,   113,   114,     0,     0,   173,   163,   168,   165,   169,
     171,     0,     0,    17,    19,     0,    11,    12,    68,    36,
      37,    38,    40,    41,    43,    44,    46,    47,    48,    49,
      51,    52,    54,    56,    58,     0,     0,    59,     0,     0,
       0,     0,    59,     0,     0,     0,   192,     0,    59,     2,
     185,   191,   188,   189,   174,   175,     0,    59,   186,   176,
       0,   177,   178,   179,   157,   144,     0,   160,   140,     0,
       0,   142,   135,    26,    81,   168,    34,   172,   164,     0,
       0,    10,     0,     9,    62,    64,     0,   202,     0,   201,
     192,   192,   192,     0,     0,     0,     0,     0,   192,     0,
     208,   192,   190,   154,   156,   139,   141,     0,   166,    20,
      60,   192,   182,    59,   192,     0,   200,     0,   203,     0,
       0,   180,   183,   187,    15,   168,     0,   181,     0,     0,
      59,    59,   192,     0,    16,    59,     0,   192,   192,   192,
     195,    59,     0,     0,     0,     0,    60,   192,    66,     0,
     192,    59,   193,   196,     0,   199,   192,    59,   197,    60,
     192,     0,   194,    59,   192,   198
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,  -303,  -303,  -303,   -72,  -303,   -85,    24,    25,
       5,    26,    97,   100,   102,    38,  -123,  -302,    40,  -303,
    -113,    -8,  -303,   -77,  -115,     0,  -303,     3,   149,  -303,
     221,  -303,   -57,    34,   154,  -303,  -303,  -303,   160,   121,
    -303,   -18,   222,   241,  -303,   232,   -47,  -303,  -303,    27,
    -303,  -101,  -125,    12,  -196,  -303,  -303,   183,   -97,  -303,
    -303,    41,  -303,    -2,  -303,  -187,  -303,  -303,  -303,  -303,
     273,  -303,  -303,  -303
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    89,    90,   212,   213,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   235,   176,   102,   103,
     104,   122,   155,   251,   194,   252,    37,    59,    44,    38,
      39,    24,    25,   125,   201,    26,    33,    66,    67,    27,
      28,    72,   107,    41,    53,    42,    54,   180,   181,   182,
     111,   127,   106,   130,   131,   132,   133,   134,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    29,
      30,    31,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   121,   123,    23,   193,    40,   208,   157,   326,   136,
     137,   279,   283,   204,    32,   193,   116,    51,  -120,   197,
     156,    62,   124,    63,   183,     3,   198,    43,    43,    22,
      43,    43,    23,   331,   211,   332,   341,   354,   175,    55,
      58,    12,    34,   123,   352,   156,   128,    35,    56,   105,
      65,   -60,   236,    18,   199,   115,   156,   361,   123,   295,
     195,   108,   215,   124,    50,   186,   118,   124,   184,   124,
     199,   206,   324,   219,   220,   221,    65,   199,   124,   199,
     199,   199,   128,    68,   129,   278,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   128,    36,   185,   315,   119,   128,   192,   109,
     334,   207,   325,   179,   286,   138,   117,   139,   276,   291,
     129,   140,   141,   105,   288,   297,   193,   329,   209,   279,
     214,   156,    57,    34,   301,   158,   159,   160,    35,   171,
     129,   165,   166,   167,   168,   129,   174,   218,    36,   172,
     344,   345,   161,   162,   308,   142,   143,    52,   200,   173,
     200,   264,   177,   156,   156,   163,   164,   156,   187,   359,
     226,   227,   228,   229,    45,    70,    46,    47,   269,   188,
     203,   270,   169,   170,    52,   222,   223,   205,   224,   225,
     328,   274,   216,   312,   313,   230,   231,   217,   237,   265,
     126,   321,   266,   267,   268,   273,   271,   338,   339,   310,
     272,   287,   342,   277,   327,   280,   281,   317,   347,   319,
     282,   289,   290,   292,   293,   294,   296,   298,   356,   348,
     302,   199,   300,    52,   360,   340,  -184,    70,   305,   306,
     364,   126,   346,   333,   275,   126,   320,   126,   311,   322,
     353,   336,   316,   355,   318,   330,   126,   343,   335,   350,
     337,   351,   357,   362,   358,   363,   349,   365,   232,   179,
     156,   105,   233,   284,   309,   234,   285,    71,     1,   196,
     202,     2,     3,    64,   110,    69,     4,   307,     5,     6,
       7,   299,   314,   304,     8,     9,    10,    11,    12,   323,
      13,    14,    49,    15,     0,     0,     0,    70,    16,    17,
      18,     0,    19,    20,    21,     0,   210,     1,   238,   239,
       2,     3,   240,   241,   242,     4,     0,     5,     6,     7,
     243,   244,   245,     8,     9,    10,    11,    12,   246,    13,
      14,    73,    15,     0,   247,     0,     0,    16,    17,    18,
     248,    19,    20,    21,   249,    75,    76,    77,    78,    79,
       0,     0,     0,   250,   303,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     1,     0,    87,     2,     3,    88,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,  -192,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -210,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     1,   238,   239,     2,     3,   240,   241,   242,
       4,    57,     5,     6,     7,   243,   244,   245,     8,     9,
      10,    11,    12,   246,    13,    14,    73,    15,     0,   247,
       0,     0,    16,    17,    18,   248,    19,    20,    21,   249,
      75,    76,    77,    78,    79,     0,     0,     0,   250,     0,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     1,    86,     0,     2,     3,     0,    87,     0,
       4,    88,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,    73,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
     238,   239,     0,    86,   240,   241,   242,     0,    87,     0,
       0,    88,   243,   244,   245,     0,     0,     0,     0,     0,
     246,     0,     0,    73,     0,     0,   247,     0,     0,     0,
       0,     0,   248,     0,     0,     0,   249,    75,    76,    77,
      78,    79,     0,     0,     0,   250,     0,    81,    82,    83,
      84,    85,     2,     3,     0,     0,     0,     4,     0,     5,
      86,     7,     0,     0,     0,    87,     9,    10,    88,    12,
       0,    13,    14,    73,     0,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,    74,    75,    76,    77,
      78,    79,     3,     0,     0,     0,     0,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    12,     0,
      86,     0,    73,   112,     0,    87,     0,     0,    88,     0,
      18,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,     3,     0,   113,     0,     0,    81,    82,    83,    84,
     114,     0,     0,     0,     0,     0,     0,    12,     0,    86,
       0,    73,   189,     0,    87,     0,     0,    88,     0,    18,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
       3,     0,   190,     0,     0,    81,    82,    83,    84,   191,
       0,     0,     0,     0,     0,     0,    12,     0,    86,     0,
      73,     0,     0,    87,     0,     0,    88,     0,    18,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,     0,
       0,     0,     0,    73,     0,     0,     0,    86,     0,     0,
       0,     0,    87,     0,     0,    88,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    80,     0,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    73,     0,     0,     0,
      86,     0,     0,     0,     0,    87,     0,     0,    88,    74,
      75,    76,    77,    78,    79,     0,     0,     0,   275,     0,
      81,    82,    83,    84,    85,     0,     0,     0,     0,    73,
       0,     0,     0,    86,     0,     0,     0,     0,    87,     0,
       0,    88,    74,    75,    76,    77,    78,   120,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    73,     0,     0,     0,    86,     0,     0,     0,
       0,    87,     0,     0,    88,    74,    75,    76,    77,    78,
     135,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,     0,     0,     0,     0,    73,     0,     0,     0,    86,
       0,     0,     0,     0,    87,     0,     0,    88,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     1,    86,     0,     2,     3,     0,    87,     0,     4,
      88,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,    48,
       0,     0,     1,     0,   178,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    73,    79,     0,   117,    23,   131,    92,   310,    81,
      82,   207,    48,   128,    40,   128,    63,    35,    49,   120,
      92,    45,    79,    47,    46,     7,    46,    24,    25,    29,
      27,    28,    29,    46,   135,    46,    46,    46,    71,    88,
      40,    23,    40,   120,   346,   117,    47,    45,    90,    57,
      40,    84,   175,    35,    90,    63,   128,   359,   135,   246,
      50,    61,   139,   120,    49,   112,    50,   124,    90,   126,
      90,    50,    50,   158,   159,   160,    40,    90,   135,    90,
      90,    90,    47,    46,    85,    50,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    47,    55,   112,   292,    90,    47,   116,    40,
      50,    90,    90,   110,   237,    45,    73,    47,   203,   242,
      85,    51,    52,   131,   239,   248,   239,   314,    73,   325,
     138,   203,    73,    40,   257,    55,    56,    57,    45,    64,
      85,    60,    61,    62,    63,    85,    70,   155,    55,    66,
     337,   338,    53,    54,   279,    85,    86,    36,   124,    65,
     126,   179,    49,   235,   236,    67,    68,   239,    48,   356,
     165,   166,   167,   168,    25,    54,    27,    28,   186,    48,
      46,   189,    58,    59,    63,   161,   162,    40,   163,   164,
     313,   199,    40,   290,   291,   169,   170,    40,    84,    46,
      79,   298,    90,    40,    48,    46,    48,   330,   331,   286,
      48,    88,   335,    48,   311,    46,    46,   294,   341,   296,
      90,    88,    87,    45,    40,    45,    45,    87,   351,   342,
      88,    90,    50,   112,   357,   332,    50,   116,    48,    48,
     363,   120,   339,   320,    49,   124,    45,   126,    87,    50,
     347,    36,    88,   350,    88,    88,   135,    45,    87,    46,
      88,    88,    12,   360,    88,    46,   343,   364,   171,   266,
     342,   279,   172,   235,   282,   173,   236,    56,     3,   119,
     126,     6,     7,    42,    62,    53,    11,   275,    13,    14,
      15,   250,   292,   266,    19,    20,    21,    22,    23,   301,
      25,    26,    29,    28,    -1,    -1,    -1,   186,    33,    34,
      35,    -1,    37,    38,    39,    -1,   133,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    89,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,     3,    -1,    69,     6,     7,    72,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    88,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    73,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    64,    -1,     6,     7,    -1,    69,    -1,
      11,    72,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    64,     8,     9,    10,    -1,    69,    -1,
      -1,    72,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      64,    15,    -1,    -1,    -1,    69,    20,    21,    72,    23,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     7,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      64,    -1,    27,    28,    -1,    69,    -1,    -1,    72,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,     7,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    64,
      -1,    27,    28,    -1,    69,    -1,    -1,    72,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
       7,    -1,    48,    -1,    -1,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    64,    -1,
      27,    -1,    -1,    69,    -1,    -1,    72,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    72,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    64,    -1,     6,     7,    -1,    69,    -1,    11,
      72,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,     0,
      -1,    -1,     3,    -1,    46,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   119,   121,   125,   126,   129,   133,   134,   163,
     164,   165,    40,   130,    40,    45,    55,   120,   123,   124,
     135,   137,   139,   121,   122,   122,   122,   122,     0,   164,
      49,   135,   133,   138,   140,    88,    90,    73,   119,   121,
     166,   167,    45,    47,   137,    40,   131,   132,    46,   139,
     133,   124,   135,    27,    40,    41,    42,    43,    44,    45,
      49,    51,    52,    53,    54,    55,    64,    69,    72,    95,
      96,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   112,   113,   114,   115,   146,   136,   119,    40,
     136,   144,    28,    48,    55,   115,   140,    73,    50,    90,
      45,    99,   115,   117,   126,   127,   133,   145,    47,    85,
     147,   148,   149,   150,   151,    45,    99,    99,    45,    47,
      51,    52,    85,    86,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   116,    99,   101,    55,    56,
      57,    53,    54,    67,    68,    60,    61,    62,    63,    58,
      59,    64,    66,    65,    70,    71,   111,    49,    46,   121,
     141,   142,   143,    46,    90,   115,   140,    48,    48,    28,
      48,    55,   115,   114,   118,    50,   132,   145,    46,    90,
     127,   128,   128,    46,   118,    40,    50,    90,   146,    73,
     151,   145,    97,    98,   115,   117,    40,    40,   115,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   107,   108,   110,   110,    84,     4,     5,
       8,     9,    10,    16,    17,    18,    24,    30,    36,    40,
      49,   117,   119,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   135,    46,    90,    40,    48,   115,
     115,    48,    48,    46,   115,    49,   101,    48,    50,   148,
      46,    46,    90,    48,   109,   112,   110,    88,   118,    88,
      87,   110,    45,    40,    45,   159,    45,   110,    87,   155,
      50,   110,    88,    89,   143,    48,    48,   147,   146,   115,
     117,    87,   152,   152,   119,   159,    88,   117,    88,   117,
      45,   152,    50,   157,    50,    90,   111,   152,   110,   159,
      88,    46,    46,   117,    50,    87,    36,    88,   110,   110,
     152,    46,   110,    45,   159,   159,   152,   110,   114,   117,
      46,    88,   111,   152,    46,   152,   110,    12,    88,   159,
     110,   111,   152,    46,   110,   152
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   104,   105,   105,   105,   105,   105,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   118,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   134,
     135,   135,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   146,   146,   146,   147,   147,   148,   148,   149,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     153,   153,   153,   154,   155,   155,   156,   156,   157,   157,
     158,   159,   159,   160,   160,   160,   161,   161,   161,   161,
     162,   162,   162,   162,   163,   163,   164,   164,   165,   166,
     166,   167,   167
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     3,     3,     2,     2,     6,     7,     1,     0,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     0,
       0,     1,     4,     1,     4,     1,     9,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     0,     2,     2,     2,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     5,     6,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     0,     1,     3,     5,     4,     4,     3,     6,
       5,     6,     5,     4,     5,     4,     4,     1,     0,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     3,     4,     2,     4,     1,     0,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     1,     0,     1,     3,     1,     1,
       2,     1,     0,     7,    10,     5,     7,     9,    13,     8,
       3,     2,     2,     3,     1,     2,     1,     1,     7,     1,
       0,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 142 "ass6_20CS30042.y"
                               { 
                            printInfo("primary_expression", "IDENTIFIER");
                            (yyval.expression) = new Expression(); // create new non boolean expression and symbol is the identifier
                            (yyval.expression)->isBoolean = False; (yyval.expression)->symbol = (yyvsp[0].symbol); }
#line 1923 "y.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 146 "ass6_20CS30042.y"
                                       { 
                            printInfo("primary_expression", "INTEGER_CONSTANT"); 
                            (yyval.expression) = new Expression(); (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT, toString((yyvsp[0].intVal)));
                            QuadArray::emit("=", (yyval.expression)->symbol->name, (yyvsp[0].intVal)); }
#line 1932 "y.tab.c"
    break;

  case 4: /* primary_expression: FLOATING_CONSTANT  */
#line 150 "ass6_20CS30042.y"
                                        { 
                            printInfo("primary_expression", "FLOATING_CONSTANT"); 
                            (yyval.expression) = new Expression(); (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::FLOAT, (yyvsp[0].floatVal));
                            QuadArray::emit("=", (yyval.expression)->symbol->name, (yyvsp[0].floatVal)); }
#line 1941 "y.tab.c"
    break;

  case 5: /* primary_expression: CHARACTER_CONSTANT  */
#line 154 "ass6_20CS30042.y"
                                         { 
                            printInfo("primary_expression", "CHARACTER_CONSTANT"); 
                            (yyval.expression) = new Expression(); (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::CHAR, (yyvsp[0].charVal));
                            QuadArray::emit("=", (yyval.expression)->symbol->name, (yyvsp[0].charVal)); }
#line 1950 "y.tab.c"
    break;

  case 6: /* primary_expression: STRING_LITERAL  */
#line 158 "ass6_20CS30042.y"
                                     { 
                            printInfo("primary_expression", "STRING_LITERAL"); 
                            (yyval.expression) = new Expression(); (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::POINTER, (yyvsp[0].strVal));
		                    (yyval.expression)->symbol->type->arrayType = new SymbolType(SymbolType::CHAR); 
                            QuadArray::emit("=str", (yyval.expression)->symbol->name, stringLiterals.size());
                            stringLiterals.push_back((yyvsp[0].strVal));
                            }
#line 1962 "y.tab.c"
    break;

  case 7: /* primary_expression: LEFT_PARENTHESIS expression RIGHT_PARENTHESIS  */
#line 165 "ass6_20CS30042.y"
                                                                    { 
                            printInfo("primary_expression", "( expression )"); 
                            (yyval.expression) = (yyvsp[-1].expression); }
#line 1970 "y.tab.c"
    break;

  case 8: /* postfix_expression: primary_expression  */
#line 171 "ass6_20CS30042.y"
                                       { 
                            // create new array with the same symbol as the primary expression
                            printInfo("postfix_expression", "primary_expression"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = (yyvsp[0].expression)->symbol; (yyval.array)->temp = (yyval.array)->symbol;
                            (yyval.array)->subArrayType = (yyvsp[0].expression)->symbol->type; }
#line 1981 "y.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression LEFT_SQUARE_BRACE expression RIGHT_SQUARE_BRACE  */
#line 177 "ass6_20CS30042.y"
                                                                                         { 
                            // create a new array
                            printInfo("postfix_expression", "postfix_expression [ expression ]"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = (yyvsp[-3].array)->symbol;    // same symbol
                            (yyval.array)->subArrayType = (yyvsp[-3].array)->subArrayType->arrayType; // go one level deeper
                            (yyval.array)->temp = SymbolTable::gentemp(SymbolType::INT); // temporary to compute location
                            (yyval.array)->type = Array::ARRAY;    // type will be array

                            if((yyvsp[-3].array)->type == Array::ARRAY) {
                                // postfix_expression is already array so multiply size of subarray with expression and add
                                Symbol *sym = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit("*", sym->name, (yyvsp[-1].expression)->symbol->name, toString((yyval.array)->subArrayType->getSize()));
                                QuadArray::emit("+", (yyval.array)->temp->name, (yyvsp[-3].array)->temp->name, sym->name); }
                            else {
                                QuadArray::emit("*", (yyval.array)->temp->name, (yyvsp[-1].expression)->symbol->name, toString((yyval.array)->subArrayType->getSize()));
                            }
                        }
#line 2004 "y.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression LEFT_PARENTHESIS argument_expression_list_opt RIGHT_PARENTHESIS  */
#line 195 "ass6_20CS30042.y"
                                                                                                         {
                            // function call, number of parameters stored in argument_expression_list_opt
                            printInfo("postfix_expression", "postfix_expression ( argument_expression_list_opt )"); 
                            (yyval.array) = new Array(); (yyval.array)->symbol = SymbolTable::gentemp((yyvsp[-3].array)->symbol->type->type);
                            QuadArray::emit("call", (yyval.array)->symbol->name, (yyvsp[-3].array)->symbol->name, toString((yyvsp[-1].parameterCount))); }
#line 2014 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 200 "ass6_20CS30042.y"
                                                        { 
                            printInfo("postfix_expression", "postfix_expression . IDENTIFIER"); }
#line 2021 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 202 "ass6_20CS30042.y"
                                                          { 
                            printInfo("postfix_expression", "postfix_expression -> IDENTIFIER"); }
#line 2028 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression INCREMENT  */
#line 204 "ass6_20CS30042.y"
                                                   { 
                            // post increment, first generate temporary with old value, then add 1
                            printInfo("postfix_expression", "postfix_expression ++");
                            (yyval.array) = new Array(); (yyval.array)->symbol = SymbolTable::gentemp((yyvsp[-1].array)->symbol->type->type);
                            QuadArray::emit("=", (yyval.array)->symbol->name, (yyvsp[-1].array)->symbol->name);
                            QuadArray::emit("+", (yyvsp[-1].array)->symbol->name, (yyvsp[-1].array)->symbol->name, toString(1)); }
#line 2039 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression DECREMENT  */
#line 210 "ass6_20CS30042.y"
                                                   { 
                            // post decrement, first generate temporary with old value, then subtract 1
                            printInfo("postfix_expression", "postfix_expression --"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = SymbolTable::gentemp((yyvsp[-1].array)->symbol->type->type);
                            QuadArray::emit("=", (yyval.array)->symbol->name, (yyvsp[-1].array)->symbol->name);
                            QuadArray::emit("-", (yyvsp[-1].array)->symbol->name, (yyvsp[-1].array)->symbol->name, toString(1)); }
#line 2051 "y.tab.c"
    break;

  case 15: /* postfix_expression: LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS LEFT_CURLY_BRACE initialiser_list RIGHT_CURLY_BRACE  */
#line 217 "ass6_20CS30042.y"
                                                                                                                       { 
                            printInfo("postfix_expression", "( type_name ) { initialiser_list }");  }
#line 2058 "y.tab.c"
    break;

  case 16: /* postfix_expression: LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS LEFT_CURLY_BRACE initialiser_list COMMA RIGHT_CURLY_BRACE  */
#line 219 "ass6_20CS30042.y"
                                                                                                                             { 
                            printInfo("postfix_expression", "( type_name ) { initialiser_list , }");  }
#line 2065 "y.tab.c"
    break;

  case 17: /* argument_expression_list_opt: argument_expression_list  */
#line 226 "ass6_20CS30042.y"
                                             {
                        printInfo("argument_expression_list_opt", "argument_expression_list"); 
                        (yyval.parameterCount) = (yyvsp[0].parameterCount); }
#line 2073 "y.tab.c"
    break;

  case 18: /* argument_expression_list_opt: %empty  */
#line 230 "ass6_20CS30042.y"
                        {// 0 params
                        printInfo("argument_expression_list_opt", "epsilon");
                        (yyval.parameterCount) = 0; }
#line 2081 "y.tab.c"
    break;

  case 19: /* argument_expression_list: assignment_expression  */
#line 236 "ass6_20CS30042.y"
                                          { 
                        // initialise param count to 1
                        printInfo("argument_expression_list", "assignment_expression"); 
                        QuadArray::emit("param", (yyvsp[0].expression)->symbol->name);
                        (yyval.parameterCount) = 1; }
#line 2091 "y.tab.c"
    break;

  case 20: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 241 "ass6_20CS30042.y"
                                                                           { 
                        // new param, add 1 to param count
                        printInfo("argument_expression_list", "argument_expression_list , assignment_expression");
                        QuadArray::emit("param", (yyvsp[0].expression)->symbol->name);
                        (yyval.parameterCount) = (yyvsp[-2].parameterCount) + 1; }
#line 2101 "y.tab.c"
    break;

  case 21: /* unary_expression: postfix_expression  */
#line 249 "ass6_20CS30042.y"
                                       {
                        printInfo("unary_expression", "postfix_expression"); 
                        (yyval.array) = (yyvsp[0].array);}
#line 2109 "y.tab.c"
    break;

  case 22: /* unary_expression: INCREMENT unary_expression  */
#line 252 "ass6_20CS30042.y"
                                                 {
                        // pre increment, no new temporary, add 1
                        printInfo("unary_expression", "++ unary_expression"); 
                        (yyval.array) = (yyvsp[0].array);
                        QuadArray::emit("+", (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->symbol->name, toString(1)); }
#line 2119 "y.tab.c"
    break;

  case 23: /* unary_expression: DECREMENT unary_expression  */
#line 257 "ass6_20CS30042.y"
                                                 { 
                        // pre decrement, no new temporary, subtract 1
                        printInfo("unary_expression", "-- unary_expression"); 
                        (yyval.array) = (yyvsp[0].array);
                        QuadArray::emit("-", (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->symbol->name, toString(1)); }
#line 2129 "y.tab.c"
    break;

  case 24: /* unary_expression: unary_operator cast_expression  */
#line 262 "ass6_20CS30042.y"
                                                     { 
                        printInfo("unary_expression", "unary_operator cast_expression");
                        switch((yyvsp[-1].unaryOperator)[0]) {
                            case '&':   // addressing, this generates a pointer, the subArray type will thus be the symbol type of the cast_expression
                                        (yyval.array) = new Array();
                                        (yyval.array)->symbol = SymbolTable::gentemp(SymbolType::POINTER);
                                        (yyval.array)->symbol->type->arrayType = (yyvsp[0].array)->symbol->type;
                                        QuadArray::emit("=&", (yyval.array)->symbol->name, (yyvsp[0].array)->symbol->name);
                                        break;
                            case '*':   // dereferncing, this generates a pointer, a new temporary generated with type as the subarray type of the cast_expression
                                        // the subArray type will thus be one level deeper that of the cast_expression
                                        (yyval.array) = new Array();   (yyval.array)->symbol = (yyvsp[0].array)->symbol;
                                        (yyval.array)->temp = SymbolTable::gentemp((yyvsp[0].array)->temp->type->arrayType->type);
                                        (yyval.array)->temp->type->arrayType = (yyvsp[0].array)->temp->type->arrayType->arrayType;
                                        (yyval.array)->type = Array::POINTER;
                                        QuadArray::emit("=*", (yyval.array)->temp->name, (yyvsp[0].array)->temp->name);
                                        break;
                            case '+':   (yyval.array) = (yyvsp[0].array); break;
                            default:    // for -, ~ and !
                                        // apply the operator on cast_expression
                                        (yyval.array) = new Array();
                                        (yyval.array)->symbol = SymbolTable::gentemp((yyvsp[0].array)->symbol->type->type);
                                        QuadArray::emit((yyvsp[-1].unaryOperator), (yyval.array)->symbol->name, (yyvsp[0].array)->symbol->name);
                                        break;
                            }
                        }
#line 2160 "y.tab.c"
    break;

  case 25: /* unary_expression: SIZEOF unary_expression  */
#line 289 "ass6_20CS30042.y"
                        { printInfo("unary_expression", "sizeof unary_expression"); }
#line 2166 "y.tab.c"
    break;

  case 26: /* unary_expression: SIZEOF LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS  */
#line 291 "ass6_20CS30042.y"
                        { printInfo("unary_expression", "sizeof ( type_name )"); }
#line 2172 "y.tab.c"
    break;

  case 27: /* unary_operator: BITWISE_AND  */
#line 297 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "&"); (yyval.unaryOperator) = strdup("&"); }
#line 2178 "y.tab.c"
    break;

  case 28: /* unary_operator: ASTERISK  */
#line 299 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "*"); (yyval.unaryOperator) = strdup("*"); }
#line 2184 "y.tab.c"
    break;

  case 29: /* unary_operator: PLUS  */
#line 301 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "+"); (yyval.unaryOperator) = strdup("+"); }
#line 2190 "y.tab.c"
    break;

  case 30: /* unary_operator: MINUS  */
#line 303 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "-"); (yyval.unaryOperator) = strdup("=-"); }
#line 2196 "y.tab.c"
    break;

  case 31: /* unary_operator: TILDE  */
#line 305 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "~"); (yyval.unaryOperator) = strdup("~"); }
#line 2202 "y.tab.c"
    break;

  case 32: /* unary_operator: EXCLAMATION  */
#line 307 "ass6_20CS30042.y"
                    { printInfo("unary_operator", "!"); (yyval.unaryOperator) = strdup("!"); }
#line 2208 "y.tab.c"
    break;

  case 33: /* cast_expression: unary_expression  */
#line 312 "ass6_20CS30042.y"
                    { printInfo("cast_expression", "unary_expression"); (yyval.array) = (yyvsp[0].array); }
#line 2214 "y.tab.c"
    break;

  case 34: /* cast_expression: LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS cast_expression  */
#line 314 "ass6_20CS30042.y"
                    { printInfo("cast_expression", "( type_name ) cast_expression"); 
                    (yyval.array) = new Array(); (yyval.array)->symbol = (yyvsp[0].array)->symbol->convert(currentType); }
#line 2221 "y.tab.c"
    break;

  case 35: /* multiplicative_expression: cast_expression  */
#line 334 "ass6_20CS30042.y"
                                            { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    printInfo("multiplicative_expression", "cast_expression"); 
                                    (yyval.expression) = new Expression();
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        (yyval.expression)->symbol = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", (yyval.expression)->symbol->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name); }
                                    else if((yyvsp[0].array)->type == Array::POINTER) (yyval.expression)->symbol = (yyvsp[0].array)->temp;
                                    else (yyval.expression)->symbol = (yyvsp[0].array)->symbol;
                                }
#line 2237 "y.tab.c"
    break;

  case 36: /* multiplicative_expression: multiplicative_expression ASTERISK cast_expression  */
#line 345 "ass6_20CS30042.y"
                                                                                 { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name); }
                                    else if((yyvsp[0].array)->type == Array::POINTER) temp = (yyvsp[0].array)->temp;
                                    else temp = (yyvsp[0].array)->symbol;

                                    printInfo("multiplicative_expression", "multiplicative_expression * cast_expression"); 
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        QuadArray::emit("*", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name); }
                                    else yyerror("Type error.");
                                }
#line 2259 "y.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 362 "ass6_20CS30042.y"
                                                                              { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name); }
                                    else if((yyvsp[0].array)->type == Array::POINTER) temp = (yyvsp[0].array)->temp;
                                    else temp = (yyvsp[0].array)->symbol;
                                
                                    printInfo("multiplicative_expression", "multiplicative_expression / cast_expression");
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        QuadArray::emit("/", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name); }
                                    else yyerror("Type error.");
                                }
#line 2281 "y.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 379 "ass6_20CS30042.y"
                                                                               { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name); }
                                    else if((yyvsp[0].array)->type == Array::POINTER) temp = (yyvsp[0].array)->temp;
                                    else temp = (yyvsp[0].array)->symbol;
                                    printInfo("multiplicative_expression", "multiplicative_expression % cast_expression"); 
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        QuadArray::emit("%", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name); }
                                    else  yyerror("Type error.");
                                }
#line 2302 "y.tab.c"
    break;

  case 39: /* additive_expression: multiplicative_expression  */
#line 398 "ass6_20CS30042.y"
                                              { 
                            printInfo("additive_expression", "multiplicative_expression"); 
                            (yyval.expression) = (yyvsp[0].expression); }
#line 2310 "y.tab.c"
    break;

  case 40: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 401 "ass6_20CS30042.y"
                                                                         { 
                            printInfo("additive_expression", "additive_expression + multiplicative_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-2].expression)->symbol->type->type);
                                QuadArray::emit("+", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name); }
                            else yyerror("Type error.");
                        }
#line 2323 "y.tab.c"
    break;

  case 41: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 409 "ass6_20CS30042.y"
                                                                          { 
                            printInfo("additive_expression", "additive_expression - multiplicative_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-2].expression)->symbol->type->type);
                                QuadArray::emit("-", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                            } else  yyerror("Type error.");
                        }
#line 2336 "y.tab.c"
    break;

  case 42: /* shift_expression: additive_expression  */
#line 421 "ass6_20CS30042.y"
                        { printInfo("shift_expression", "additive_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2342 "y.tab.c"
    break;

  case 43: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 422 "ass6_20CS30042.y"
                                                                      { 
                            printInfo("shift_expression", "shift_expression << additive_expression"); 
                            if((yyvsp[0].expression)->symbol->type->type == SymbolType::INT) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit("<<", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name); }
                            else  yyerror("Type error.");
                        }
#line 2355 "y.tab.c"
    break;

  case 44: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 430 "ass6_20CS30042.y"
                                                                       { 
                            printInfo("shift_expression", "shift_expression >> additive_expression"); 
                            if((yyvsp[0].expression)->symbol->type->type == SymbolType::INT) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit(">>", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name); }
                            else yyerror("Type error.");
                        }
#line 2368 "y.tab.c"
    break;

  case 45: /* relational_expression: shift_expression  */
#line 449 "ass6_20CS30042.y"
                        { printInfo("relational_expression", "shift_expression");  (yyval.expression) = (yyvsp[0].expression); }
#line 2374 "y.tab.c"
    break;

  case 46: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 450 "ass6_20CS30042.y"
                                                                       { 
                            printInfo("relational_expression", "relational_expression < shift_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
                                (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("<", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
#line 2390 "y.tab.c"
    break;

  case 47: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 461 "ass6_20CS30042.y"
                                                                          { 
                            printInfo("relational_expression", "relational_expression > shift_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
                                (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit(">", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
#line 2406 "y.tab.c"
    break;

  case 48: /* relational_expression: relational_expression LESS_EQUAL_THAN shift_expression  */
#line 472 "ass6_20CS30042.y"
                                                                             { 
                            printInfo("relational_expression", "relational_expression <= shift_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
                                (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("<=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else  yyerror("Type error.");
                        }
#line 2422 "y.tab.c"
    break;

  case 49: /* relational_expression: relational_expression GREATER_EQUAL_THAN shift_expression  */
#line 483 "ass6_20CS30042.y"
                                                                                { 
                            printInfo("relational_expression", "relational_expression >= shift_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
                                (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit(">=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
#line 2438 "y.tab.c"
    break;

  case 50: /* equality_expression: relational_expression  */
#line 498 "ass6_20CS30042.y"
                        { printInfo("equality_expression", "relational_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2444 "y.tab.c"
    break;

  case 51: /* equality_expression: equality_expression EQUALS relational_expression  */
#line 499 "ass6_20CS30042.y"
                                                                       { 
                            printInfo("equality_expression", "equality_expression == relational_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyvsp[-2].expression)->toInt(); (yyvsp[0].expression)->toInt();
                                (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
			                    (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("==", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
#line 2460 "y.tab.c"
    break;

  case 52: /* equality_expression: equality_expression NOT_EQUALS relational_expression  */
#line 510 "ass6_20CS30042.y"
                                                                           { 
                            printInfo("equality_expression", "equality_expression != relational_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyvsp[-2].expression)->toInt(); (yyvsp[0].expression)->toInt();
                                (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = True;
                                (yyval.expression)->trueList = makeList(nextInstruction());
			                    (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("!=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
#line 2476 "y.tab.c"
    break;

  case 53: /* AND_expression: equality_expression  */
#line 526 "ass6_20CS30042.y"
                        { printInfo("AND_expression", "equality_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2482 "y.tab.c"
    break;

  case 54: /* AND_expression: AND_expression BITWISE_AND equality_expression  */
#line 527 "ass6_20CS30042.y"
                                                                     { 
                            printInfo("AND_expression", "AND_expression & equality_expression"); 
                            (yyvsp[-2].expression)->toInt(); (yyvsp[0].expression)->toInt();
                            (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = False;
                            (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("&", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                        }
#line 2494 "y.tab.c"
    break;

  case 55: /* exclusive_OR_expression: AND_expression  */
#line 538 "ass6_20CS30042.y"
                        { printInfo("exclusive_OR_expression", "AND_expression");  (yyval.expression) = (yyvsp[0].expression); }
#line 2500 "y.tab.c"
    break;

  case 56: /* exclusive_OR_expression: exclusive_OR_expression BITWISE_XOR AND_expression  */
#line 539 "ass6_20CS30042.y"
                                                                         { 
                            printInfo("exclusive_OR_expression", "exclusive_OR_expression ^ AND_expression"); 
                            (yyvsp[-2].expression)->toInt(); (yyvsp[0].expression)->toInt();
                            (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = False;
                            (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("^", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                        }
#line 2512 "y.tab.c"
    break;

  case 57: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 550 "ass6_20CS30042.y"
                        { printInfo("inclusive_OR_expression", "exclusive_OR_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2518 "y.tab.c"
    break;

  case 58: /* inclusive_OR_expression: inclusive_OR_expression BITWISE_OR exclusive_OR_expression  */
#line 551 "ass6_20CS30042.y"
                                                                                 { 
                            printInfo("inclusive_OR_expression", "inclusive_OR_expression | exclusive_OR_expression"); 
                            (yyvsp[-2].expression)->toInt(); (yyvsp[0].expression)->toInt();
                            (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = False;
                            (yyval.expression)->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("|", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                        }
#line 2530 "y.tab.c"
    break;

  case 59: /* M: %empty  */
#line 570 "ass6_20CS30042.y"
    { printInfo("M", "epsilon"); (yyval.instrNo) = nextInstruction(); }
#line 2536 "y.tab.c"
    break;

  case 60: /* N: %empty  */
#line 572 "ass6_20CS30042.y"
    { printInfo("N", "epsilon"); (yyval.statement) = new Statement();
      (yyval.statement)->nextList = makeList(nextInstruction()); QuadArray::emit("goto", "");
    }
#line 2544 "y.tab.c"
    break;

  case 61: /* logical_AND_expression: inclusive_OR_expression  */
#line 578 "ass6_20CS30042.y"
                        { printInfo("logical_AND_expression", "inclusive_OR_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2550 "y.tab.c"
    break;

  case 62: /* logical_AND_expression: logical_AND_expression LOGICAL_AND M inclusive_OR_expression  */
#line 579 "ass6_20CS30042.y"
                                                                                   { 
                            printInfo("logical_AND_expression", "logical_AND_expression && inclusive_OR_expression");
                            (yyvsp[-3].expression)->toBool(); (yyvsp[0].expression)->toBool();
                            (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = True;
                            backpatch((yyvsp[-3].expression)->trueList, (yyvsp[-1].instrNo)); (yyval.expression)->trueList = (yyvsp[0].expression)->trueList;
                            (yyval.expression)->falseList = merge((yyvsp[-3].expression)->falseList, (yyvsp[0].expression)->falseList);
                        }
#line 2562 "y.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_AND_expression  */
#line 590 "ass6_20CS30042.y"
                        { printInfo("logical_OR_expression", "logical_AND_expression");  (yyval.expression) = (yyvsp[0].expression); }
#line 2568 "y.tab.c"
    break;

  case 64: /* logical_OR_expression: logical_OR_expression LOGICAL_OR M logical_AND_expression  */
#line 591 "ass6_20CS30042.y"
                                                                                { 
                            printInfo("logical_OR_expression", "logical_OR_expression || logical_AND_expression"); 
                            (yyvsp[-3].expression)->toBool(); (yyvsp[0].expression)->toBool();
                            (yyval.expression) = new Expression(); (yyval.expression)->isBoolean = True;
                            backpatch((yyvsp[-3].expression)->falseList, (yyvsp[-1].instrNo));
                            (yyval.expression)->trueList = merge((yyvsp[-3].expression)->trueList, (yyvsp[0].expression)->trueList);
                            (yyval.expression)->falseList = (yyvsp[0].expression)->falseList;
                        }
#line 2581 "y.tab.c"
    break;

  case 65: /* conditional_expression: logical_OR_expression  */
#line 603 "ass6_20CS30042.y"
                        { printInfo("conditional_expression", "logical_OR_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2587 "y.tab.c"
    break;

  case 66: /* conditional_expression: logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression  */
#line 604 "ass6_20CS30042.y"
                                                                                                          { 
                            printInfo("conditional_expression", "logical_OR_expression ? expression : conditional_expression"); 
                            (yyval.expression)->symbol = SymbolTable::gentemp((yyvsp[-4].expression)->symbol->type->type);
                            QuadArray::emit("=", (yyval.expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                            vector<int> l = makeList(nextInstruction());
                            QuadArray::emit("goto", "");
                            backpatch((yyvsp[-3].statement)->nextList, nextInstruction());
                            QuadArray::emit("=", (yyval.expression)->symbol->name, (yyvsp[-4].expression)->symbol->name);
                            l = merge(l, makeList(nextInstruction()));
                            QuadArray::emit("goto", "");
                            backpatch((yyvsp[-7].statement)->nextList, nextInstruction());
                            (yyvsp[-8].expression)->toBool();
                            backpatch((yyvsp[-8].expression)->trueList, (yyvsp[-5].instrNo));
                            backpatch((yyvsp[-8].expression)->falseList, (yyvsp[-1].instrNo));
                            backpatch(l, nextInstruction());
                        }
#line 2608 "y.tab.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 624 "ass6_20CS30042.y"
                        { printInfo("assignment_expression", "conditional_expression");  (yyval.expression) = (yyvsp[0].expression); }
#line 2614 "y.tab.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 625 "ass6_20CS30042.y"
                                                                                 { 
                            printInfo("assignment_expression", "unary_expression assignment_operator assignment_expression"); 
                            if((yyvsp[-2].array)->type == Array::ARRAY) {
                                // assignment to array
                                (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->subArrayType->type);
                                QuadArray::emit("[]=", (yyvsp[-2].array)->symbol->name, (yyvsp[-2].array)->temp->name, (yyvsp[0].expression)->symbol->name); }
                            else if((yyvsp[-2].array)->type == Array::POINTER) {
                                // assignment to pointer
                                (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->temp->type->type);
                                QuadArray::emit("*=", (yyvsp[-2].array)->temp->name, (yyvsp[0].expression)->symbol->name); }
                            else {
                                // assignment to other
                                (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->symbol->type->type);
                                QuadArray::emit("=", (yyvsp[-2].array)->symbol->name, (yyvsp[0].expression)->symbol->name); }
                            (yyval.expression) = (yyvsp[0].expression);
                        }
#line 2635 "y.tab.c"
    break;

  case 69: /* assignment_operator: ASSIGNMENT  */
#line 645 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "="); }
#line 2641 "y.tab.c"
    break;

  case 70: /* assignment_operator: ASTERISK_ASSIGNMENT  */
#line 647 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "*="); }
#line 2647 "y.tab.c"
    break;

  case 71: /* assignment_operator: SLASH_ASSIGNMENT  */
#line 649 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "/="); }
#line 2653 "y.tab.c"
    break;

  case 72: /* assignment_operator: MODULO_ASSIGNMENT  */
#line 651 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "%="); }
#line 2659 "y.tab.c"
    break;

  case 73: /* assignment_operator: PLUS_ASSIGNMENT  */
#line 653 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "+= "); }
#line 2665 "y.tab.c"
    break;

  case 74: /* assignment_operator: MINUS_ASSIGNMENT  */
#line 655 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "-= "); }
#line 2671 "y.tab.c"
    break;

  case 75: /* assignment_operator: LEFT_SHIFT_ASSIGNMENT  */
#line 657 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "<<="); }
#line 2677 "y.tab.c"
    break;

  case 76: /* assignment_operator: RIGHT_SHIFT_ASSIGNMENT  */
#line 659 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", ">>="); }
#line 2683 "y.tab.c"
    break;

  case 77: /* assignment_operator: BITWISE_AND_ASSIGNMENT  */
#line 661 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "&="); }
#line 2689 "y.tab.c"
    break;

  case 78: /* assignment_operator: BITWISE_XOR_ASSIGNMENT  */
#line 663 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "^="); }
#line 2695 "y.tab.c"
    break;

  case 79: /* assignment_operator: BITWISE_OR_ASSIGNMENT  */
#line 665 "ass6_20CS30042.y"
                        { printInfo("assignment_operator", "|="); }
#line 2701 "y.tab.c"
    break;

  case 80: /* expression: assignment_expression  */
#line 670 "ass6_20CS30042.y"
                        { printInfo("expression", "assignment_expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 2707 "y.tab.c"
    break;

  case 81: /* expression: expression COMMA assignment_expression  */
#line 672 "ass6_20CS30042.y"
                        { printInfo("expression", "expression , assignment_expression"); }
#line 2713 "y.tab.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 677 "ass6_20CS30042.y"
                        { printInfo("constant_expression", "conditional_expression"); }
#line 2719 "y.tab.c"
    break;

  case 83: /* declaration: declaration_specifiers init_declarator_list_opt SEMI_COLON  */
#line 683 "ass6_20CS30042.y"
                        { printInfo("declaration", "declaration_specifiers init_declarator_list_opt ;"); }
#line 2725 "y.tab.c"
    break;

  case 84: /* init_declarator_list_opt: init_declarator_list  */
#line 688 "ass6_20CS30042.y"
                        { printInfo("init_declarator_list_opt", "init_declarator_list"); }
#line 2731 "y.tab.c"
    break;

  case 85: /* init_declarator_list_opt: %empty  */
#line 690 "ass6_20CS30042.y"
                        { printInfo("init_declarator_list_opt", "Epsilon"); }
#line 2737 "y.tab.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers_opt  */
#line 694 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers", "storage_class_specifier declaration_specifiers_opt"); }
#line 2743 "y.tab.c"
    break;

  case 87: /* declaration_specifiers: type_specifier declaration_specifiers_opt  */
#line 696 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers", "type_specifier declaration_specifiers_opt"); }
#line 2749 "y.tab.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers_opt  */
#line 698 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers", "type_qualifier declaration_specifiers_opt"); }
#line 2755 "y.tab.c"
    break;

  case 89: /* declaration_specifiers: function_specifier declaration_specifiers_opt  */
#line 700 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers", "function_specifier declaration_specifiers_opt"); }
#line 2761 "y.tab.c"
    break;

  case 90: /* declaration_specifiers_opt: declaration_specifiers  */
#line 705 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers_opt", "declaration_specifiers"); }
#line 2767 "y.tab.c"
    break;

  case 91: /* declaration_specifiers_opt: %empty  */
#line 707 "ass6_20CS30042.y"
                        { printInfo("declaration_specifiers_opt", "Epsilon "); }
#line 2773 "y.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 712 "ass6_20CS30042.y"
                        { printInfo("init_declarator_list", "init_declarator"); }
#line 2779 "y.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 714 "ass6_20CS30042.y"
                        { printInfo("init_declarator_list", "init_declarator_list , init_declarator"); }
#line 2785 "y.tab.c"
    break;

  case 94: /* init_declarator: declarator  */
#line 719 "ass6_20CS30042.y"
                        { printInfo("init_declarator", "declarator"); (yyval.symbol) = (yyvsp[0].symbol); }
#line 2791 "y.tab.c"
    break;

  case 95: /* init_declarator: declarator ASSIGNMENT initialiser  */
#line 720 "ass6_20CS30042.y"
                                                        { 
                            printInfo("init_declarator", "declarator = initialiser");
                            // if there is some initial value assign it 
                            if((yyvsp[0].symbol)->initialValue != "") (yyvsp[-2].symbol)->initialValue = (yyvsp[0].symbol)->initialValue;
                            // = assignment
                            QuadArray::emit("=", (yyvsp[-2].symbol)->name, (yyvsp[0].symbol)->name);
                        }
#line 2803 "y.tab.c"
    break;

  case 96: /* storage_class_specifier: EXTERN  */
#line 731 "ass6_20CS30042.y"
                        { printInfo("storage_class_specifier", "extern"); }
#line 2809 "y.tab.c"
    break;

  case 97: /* storage_class_specifier: STATIC  */
#line 733 "ass6_20CS30042.y"
                        { printInfo("storage_class_specifier", "static"); }
#line 2815 "y.tab.c"
    break;

  case 98: /* storage_class_specifier: AUTO  */
#line 735 "ass6_20CS30042.y"
                        { printInfo("storage_class_specifier", "auto"); }
#line 2821 "y.tab.c"
    break;

  case 99: /* storage_class_specifier: REGISTER  */
#line 737 "ass6_20CS30042.y"
                        { printInfo("storage_class_specifier", "register"); }
#line 2827 "y.tab.c"
    break;

  case 100: /* type_specifier: VOIDTYPE  */
#line 742 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "void"); currentType = SymbolType::VOID; }
#line 2833 "y.tab.c"
    break;

  case 101: /* type_specifier: CHARTYPE  */
#line 744 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "char"); 
                            currentType = SymbolType::CHAR; }
#line 2840 "y.tab.c"
    break;

  case 102: /* type_specifier: SHORT  */
#line 747 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "short"); }
#line 2846 "y.tab.c"
    break;

  case 103: /* type_specifier: INTTYPE  */
#line 749 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "int"); currentType = SymbolType::INT; }
#line 2852 "y.tab.c"
    break;

  case 104: /* type_specifier: LONG  */
#line 751 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "long"); }
#line 2858 "y.tab.c"
    break;

  case 105: /* type_specifier: FLOATTYPE  */
#line 753 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "float"); currentType = SymbolType::FLOAT;}
#line 2864 "y.tab.c"
    break;

  case 106: /* type_specifier: DOUBLE  */
#line 755 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "double"); }
#line 2870 "y.tab.c"
    break;

  case 107: /* type_specifier: SIGNED  */
#line 757 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "signed"); }
#line 2876 "y.tab.c"
    break;

  case 108: /* type_specifier: UNSIGNED  */
#line 759 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "unsigned"); }
#line 2882 "y.tab.c"
    break;

  case 109: /* type_specifier: _BOOL  */
#line 761 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "_Bool"); }
#line 2888 "y.tab.c"
    break;

  case 110: /* type_specifier: _COMPLEX  */
#line 763 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "_Complex"); }
#line 2894 "y.tab.c"
    break;

  case 111: /* type_specifier: _IMAGINARY  */
#line 765 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "_Imaginary"); }
#line 2900 "y.tab.c"
    break;

  case 112: /* type_specifier: enum_specifier  */
#line 767 "ass6_20CS30042.y"
                        { printInfo("type_specifier", "enum_specifier"); }
#line 2906 "y.tab.c"
    break;

  case 113: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 772 "ass6_20CS30042.y"
                        { printInfo("specifier_qualifier_list", "type_specifier specifier_qualifier_list_opt"); }
#line 2912 "y.tab.c"
    break;

  case 114: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 774 "ass6_20CS30042.y"
                        { printInfo("specifier_qualifier_list", "type_qualifier specifier_qualifier_list_opt"); }
#line 2918 "y.tab.c"
    break;

  case 115: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 779 "ass6_20CS30042.y"
                        { printInfo("specifier_qualifier_list_opt", "specifier_qualifier_list"); }
#line 2924 "y.tab.c"
    break;

  case 116: /* specifier_qualifier_list_opt: %empty  */
#line 781 "ass6_20CS30042.y"
                        { printInfo("specifier_qualifier_list_opt", "Epsilon"); }
#line 2930 "y.tab.c"
    break;

  case 117: /* enum_specifier: ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE  */
#line 786 "ass6_20CS30042.y"
                        { printInfo("enum_specifier", "enum identifier_opt { enumerator_list }"); }
#line 2936 "y.tab.c"
    break;

  case 118: /* enum_specifier: ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE  */
#line 788 "ass6_20CS30042.y"
                        { printInfo("enum_specifier", "enum identifier_opt { enumerator_list , }"); }
#line 2942 "y.tab.c"
    break;

  case 119: /* enum_specifier: ENUM IDENTIFIER  */
#line 790 "ass6_20CS30042.y"
                        { printInfo("enum_specifier", "enum IDENTIFIER"); }
#line 2948 "y.tab.c"
    break;

  case 120: /* identifier_opt: IDENTIFIER  */
#line 795 "ass6_20CS30042.y"
                        { printInfo("identifier_opt", "IDENTIFIER"); }
#line 2954 "y.tab.c"
    break;

  case 121: /* identifier_opt: %empty  */
#line 797 "ass6_20CS30042.y"
                        { printInfo("identifier_opt", "epsilon"); }
#line 2960 "y.tab.c"
    break;

  case 122: /* enumerator_list: enumerator  */
#line 802 "ass6_20CS30042.y"
                        { printInfo("enumerator_list", "enumerator"); }
#line 2966 "y.tab.c"
    break;

  case 123: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 804 "ass6_20CS30042.y"
                        { printInfo("enumerator_list", "enumerator_list , enumerator"); }
#line 2972 "y.tab.c"
    break;

  case 124: /* enumerator: IDENTIFIER  */
#line 809 "ass6_20CS30042.y"
                        { printInfo("enumerator", "ENUMERATION_CONSTANT"); }
#line 2978 "y.tab.c"
    break;

  case 125: /* enumerator: IDENTIFIER ASSIGNMENT constant_expression  */
#line 811 "ass6_20CS30042.y"
                        { printInfo("enumerator", "ENUMERATION_CONSTANT = constant_expression"); }
#line 2984 "y.tab.c"
    break;

  case 126: /* type_qualifier: CONST  */
#line 816 "ass6_20CS30042.y"
                        { printInfo("type_qualifier", "const"); }
#line 2990 "y.tab.c"
    break;

  case 127: /* type_qualifier: RESTRICT  */
#line 818 "ass6_20CS30042.y"
                        { printInfo("type_qualifier", "restrict"); }
#line 2996 "y.tab.c"
    break;

  case 128: /* type_qualifier: VOLATILE  */
#line 820 "ass6_20CS30042.y"
                        { printInfo("type_qualifier", "volatile"); }
#line 3002 "y.tab.c"
    break;

  case 129: /* function_specifier: INLINE  */
#line 825 "ass6_20CS30042.y"
                        { printInfo("function_specifier", "inline"); }
#line 3008 "y.tab.c"
    break;

  case 130: /* declarator: pointer direct_declarator  */
#line 829 "ass6_20CS30042.y"
                                              { 
                            printInfo("declarator", "pointer direct_declarator"); 
                            SymbolType *it = (yyvsp[-1].symbolType);
                            while(it->arrayType != NULL) 
                                it = it->arrayType;
                            it->arrayType = (yyvsp[0].symbol)->type;
                            (yyval.symbol) = (yyvsp[0].symbol)->update((yyvsp[-1].symbolType));
                        }
#line 3021 "y.tab.c"
    break;

  case 131: /* declarator: direct_declarator  */
#line 838 "ass6_20CS30042.y"
                        { printInfo("declarator", "direct_declarator"); }
#line 3027 "y.tab.c"
    break;

  case 132: /* change_scope: %empty  */
#line 841 "ass6_20CS30042.y"
                    {if(currentSymbol->nestedTable == NULL) changeTable(new SymbolTable(""));
                     else {
                            changeTable(currentSymbol->nestedTable);
                            QuadArray::emit("label", currentST->name);
                        }
                    }
#line 3038 "y.tab.c"
    break;

  case 133: /* direct_declarator: IDENTIFIER  */
#line 850 "ass6_20CS30042.y"
                                { 
                            printInfo("direct_declarator", "IDENTIFIER"); 
                            (yyval.symbol) = (yyvsp[0].symbol)->update(new SymbolType(currentType)); // update type to the last type seen
                            currentSymbol = (yyval.symbol);
                        }
#line 3048 "y.tab.c"
    break;

  case 134: /* direct_declarator: LEFT_PARENTHESIS declarator RIGHT_PARENTHESIS  */
#line 856 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "( declarator )"); (yyval.symbol) = (yyvsp[-1].symbol); }
#line 3054 "y.tab.c"
    break;

  case 135: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE type_qualifier_list assignment_expression RIGHT_SQUARE_BRACE  */
#line 858 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list assignment_expression ]"); }
#line 3060 "y.tab.c"
    break;

  case 136: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE type_qualifier_list RIGHT_SQUARE_BRACE  */
#line 860 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list ]"); }
#line 3066 "y.tab.c"
    break;

  case 137: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE assignment_expression RIGHT_SQUARE_BRACE  */
#line 861 "ass6_20CS30042.y"
                                                                                                   { 
                            printInfo("direct_declarator", "direct_declarator [ assignment_expression ]"); 
                            SymbolType *it1 = (yyvsp[-3].symbol)->type, *it2 = NULL;
                            while(it1->type == SymbolType::typeEnum::ARRAY) { // go to the base level of a nested type
                                it2 = it1; it1 = it1->arrayType;
                            }
                            if(it2 != NULL) { // nested array case
                                // another level of nesting with base as it1 and width the value of assignment_expression
                                it2->arrayType =  new SymbolType(SymbolType::typeEnum::ARRAY, it1, atoi((yyvsp[-1].expression)->symbol->initialValue.c_str()));	
                                (yyval.symbol) = (yyvsp[-3].symbol)->update((yyvsp[-3].symbol)->type); }
                            else { // fresh array
                                // create a new array with base as type of direct_declarator and width the value of assignment_expression
                                (yyval.symbol) = (yyvsp[-3].symbol)->update(new SymbolType(SymbolType::typeEnum::ARRAY, (yyvsp[-3].symbol)->type, atoi((yyvsp[-1].expression)->symbol->initialValue.c_str())));
                            }
                        }
#line 3086 "y.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE RIGHT_SQUARE_BRACE  */
#line 876 "ass6_20CS30042.y"
                                                                             { 
                            printInfo("direct_declarator", "direct_declarator [ ]"); 
                            // same as the previous rule, just we dont know the size so put it as 0
                            SymbolType *it1 = (yyvsp[-2].symbol)->type, *it2 = NULL;
                            while(it1->type == SymbolType::typeEnum::ARRAY) { // go to the base level of a nested type
                                it2 = it1; it1 = it1->arrayType;
                            }
                            if(it2 != NULL) { // nested array case
                                // another level of nesting with base as it1 and width the value of assignment_expression
                                it2->arrayType =  new SymbolType(SymbolType::typeEnum::ARRAY, it1, 0);	
                                (yyval.symbol) = (yyvsp[-2].symbol)->update((yyvsp[-2].symbol)->type); }
                            else { // fresh array
                                // create a new array with base as type of direct_declarator and width the value of assignment_expression
                                (yyval.symbol) = (yyvsp[-2].symbol)->update(new SymbolType(SymbolType::typeEnum::ARRAY, (yyvsp[-2].symbol)->type, 0));
                            }
                        }
#line 3107 "y.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE STATIC type_qualifier_list assignment_expression RIGHT_SQUARE_BRACE  */
#line 893 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ static type_qualifier_list assignment_expression ]"); }
#line 3113 "y.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE STATIC assignment_expression RIGHT_SQUARE_BRACE  */
#line 895 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ assignment_expression ]"); }
#line 3119 "y.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE type_qualifier_list STATIC assignment_expression RIGHT_SQUARE_BRACE  */
#line 897 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list static assignment_expression ]"); }
#line 3125 "y.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE type_qualifier_list ASTERISK RIGHT_SQUARE_BRACE  */
#line 899 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list * ]"); }
#line 3131 "y.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACE ASTERISK RIGHT_SQUARE_BRACE  */
#line 901 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator [ * ]"); }
#line 3137 "y.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LEFT_PARENTHESIS change_scope parameter_type_list RIGHT_PARENTHESIS  */
#line 902 "ass6_20CS30042.y"
                                                                                                            {
                            printInfo("direct_declarator", "direct_declarator ( parameter_type_list )"); 
                            // function declaration
                            currentST->name = (yyvsp[-4].symbol)->name;
                            if((yyvsp[-4].symbol)->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update((yyvsp[-4].symbol)->type);
                            }
                            // move back to the global table and set the nested table for the function
                            (yyvsp[-4].symbol)->nestedTable = currentST;
                            (yyvsp[-4].symbol)->category = Symbol::FUNCTION;
                            currentST->parent = globalST;
                            changeTable(globalST); currentSymbol = (yyval.symbol);
                        }
#line 3156 "y.tab.c"
    break;

  case 145: /* direct_declarator: direct_declarator LEFT_PARENTHESIS identifier_list RIGHT_PARENTHESIS  */
#line 917 "ass6_20CS30042.y"
                        { printInfo("direct_declarator", "direct_declarator ( identifier_list )"); }
#line 3162 "y.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator LEFT_PARENTHESIS change_scope RIGHT_PARENTHESIS  */
#line 918 "ass6_20CS30042.y"
                                                                                        { 
                            printInfo("direct_declarator", "direct_declarator ( )"); 
                            // same as the previous rule
                            currentST->name = (yyvsp[-3].symbol)->name;
                            if((yyvsp[-3].symbol)->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update((yyvsp[-3].symbol)->type);
                            }
                            // move back to the global table and set the nested table for the function
                            (yyvsp[-3].symbol)->nestedTable = currentST;
                            (yyvsp[-3].symbol)->category = Symbol::FUNCTION;
                            currentST->parent = globalST;
                            changeTable(globalST); currentSymbol = (yyval.symbol);
                        }
#line 3181 "y.tab.c"
    break;

  case 147: /* type_qualifier_list_opt: type_qualifier_list  */
#line 936 "ass6_20CS30042.y"
                        { printInfo("type_qualifier_list_opt", "type_qualifier_list"); }
#line 3187 "y.tab.c"
    break;

  case 148: /* type_qualifier_list_opt: %empty  */
#line 938 "ass6_20CS30042.y"
                        { printInfo("type_qualifier_list_opt", "Epsilon"); }
#line 3193 "y.tab.c"
    break;

  case 149: /* pointer: ASTERISK type_qualifier_list_opt  */
#line 947 "ass6_20CS30042.y"
                                                     { 
                            printInfo("pointer", "* type_qualifier_list_opt"); 
                            // fresh pointer
                            (yyval.symbolType) = new SymbolType(SymbolType::POINTER);
                        }
#line 3203 "y.tab.c"
    break;

  case 150: /* pointer: ASTERISK type_qualifier_list_opt pointer  */
#line 952 "ass6_20CS30042.y"
                                                               { 
                            printInfo("pointer", "* type_qualifier_list_opt pointer"); 
                            // nested pointer
                            (yyval.symbolType) = new SymbolType(SymbolType::POINTER, (yyvsp[0].symbolType));
                        }
#line 3213 "y.tab.c"
    break;

  case 151: /* type_qualifier_list: type_qualifier  */
#line 961 "ass6_20CS30042.y"
                        { printInfo("type_qualifier_list", "type_qualifier"); }
#line 3219 "y.tab.c"
    break;

  case 152: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 963 "ass6_20CS30042.y"
                        { printInfo("type_qualifier_list", "type_qualifier_list type_qualifier"); }
#line 3225 "y.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 968 "ass6_20CS30042.y"
                        { printInfo("parameter_type_list", "parameter_list"); }
#line 3231 "y.tab.c"
    break;

  case 154: /* parameter_type_list: parameter_list COMMA ELLIPSIS  */
#line 970 "ass6_20CS30042.y"
                        { printInfo("parameter_type_list", "parameter_list , ..."); }
#line 3237 "y.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 975 "ass6_20CS30042.y"
                        { printInfo("parameter_list", "parameter_declaration"); }
#line 3243 "y.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 977 "ass6_20CS30042.y"
                        { printInfo("parameter_list", "parameter_list , parameter_declaration"); }
#line 3249 "y.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 982 "ass6_20CS30042.y"
                        { printInfo("parameter_declaration", "declaration_specifiers declarator"); 
                                (yyvsp[0].symbol)->category = Symbol::PARAMETER; 
                                currentST->parameters.push_back((yyvsp[0].symbol)->name); //**************
                        }
#line 3258 "y.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers  */
#line 987 "ass6_20CS30042.y"
                        { printInfo("parameter_declaration", "declaration_specifiers"); }
#line 3264 "y.tab.c"
    break;

  case 159: /* identifier_list: IDENTIFIER  */
#line 992 "ass6_20CS30042.y"
                        { printInfo("identifier_list", "IDENTIFIER"); }
#line 3270 "y.tab.c"
    break;

  case 160: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 994 "ass6_20CS30042.y"
                        { printInfo("identifier_list", "identifier_list , IDENTIFIER"); }
#line 3276 "y.tab.c"
    break;

  case 161: /* type_name: specifier_qualifier_list  */
#line 999 "ass6_20CS30042.y"
                        { printInfo("type_name", "specifier_qualifier_list"); }
#line 3282 "y.tab.c"
    break;

  case 162: /* initialiser: assignment_expression  */
#line 1004 "ass6_20CS30042.y"
                { printInfo("initialiser", "assignment_expression"); (yyval.symbol) = (yyvsp[0].expression)->symbol; }
#line 3288 "y.tab.c"
    break;

  case 163: /* initialiser: LEFT_CURLY_BRACE initialiser_list RIGHT_CURLY_BRACE  */
#line 1006 "ass6_20CS30042.y"
                { printInfo("initialiser", "{ initialiser_list }"); }
#line 3294 "y.tab.c"
    break;

  case 164: /* initialiser: LEFT_CURLY_BRACE initialiser_list COMMA RIGHT_CURLY_BRACE  */
#line 1008 "ass6_20CS30042.y"
                { printInfo("initialiser", "{ initialiser_list , }"); }
#line 3300 "y.tab.c"
    break;

  case 165: /* initialiser_list: designation_opt initialiser  */
#line 1013 "ass6_20CS30042.y"
                        { printInfo("initialiser_list", "designation_opt initialiser"); }
#line 3306 "y.tab.c"
    break;

  case 166: /* initialiser_list: initialiser_list COMMA designation_opt initialiser  */
#line 1015 "ass6_20CS30042.y"
                        { printInfo("initialiser_list", "initialiser_list , designation_opt initialiser"); }
#line 3312 "y.tab.c"
    break;

  case 167: /* designation_opt: designation  */
#line 1019 "ass6_20CS30042.y"
                        { printInfo("designation_opt", "designation"); }
#line 3318 "y.tab.c"
    break;

  case 168: /* designation_opt: %empty  */
#line 1021 "ass6_20CS30042.y"
                        { printInfo("designation_opt", "Epsilon"); }
#line 3324 "y.tab.c"
    break;

  case 169: /* designation: designator_list ASSIGNMENT  */
#line 1026 "ass6_20CS30042.y"
                        { printInfo("designation", "designator_list ="); }
#line 3330 "y.tab.c"
    break;

  case 170: /* designator_list: designator  */
#line 1031 "ass6_20CS30042.y"
                        { printInfo("designator_list", "designator"); }
#line 3336 "y.tab.c"
    break;

  case 171: /* designator_list: designator_list designator  */
#line 1033 "ass6_20CS30042.y"
                        { printInfo("designator_list", "designator_list designator"); }
#line 3342 "y.tab.c"
    break;

  case 172: /* designator: LEFT_SQUARE_BRACE constant_expression RIGHT_SQUARE_BRACE  */
#line 1038 "ass6_20CS30042.y"
                        { printInfo("designator", "[ constant_expression ]"); }
#line 3348 "y.tab.c"
    break;

  case 173: /* designator: DOT IDENTIFIER  */
#line 1040 "ass6_20CS30042.y"
                        { printInfo("designator", ". IDENTIFIER"); }
#line 3354 "y.tab.c"
    break;

  case 174: /* statement: labeled_statement  */
#line 1046 "ass6_20CS30042.y"
                        { printInfo("statement", "labeled_statement"); }
#line 3360 "y.tab.c"
    break;

  case 175: /* statement: compound_statement  */
#line 1048 "ass6_20CS30042.y"
                        { printInfo("statement", "compound_statement"); (yyval.statement) = (yyvsp[0].statement); }
#line 3366 "y.tab.c"
    break;

  case 176: /* statement: expression_statement  */
#line 1049 "ass6_20CS30042.y"
                                           { 
                            printInfo("statement", "expression_statement"); 
                            (yyval.statement) = new Statement(); (yyval.statement)->nextList = (yyvsp[0].expression)->nextList;
                        }
#line 3375 "y.tab.c"
    break;

  case 177: /* statement: selection_statement  */
#line 1054 "ass6_20CS30042.y"
                        { printInfo("statement", "selection_statement"); (yyval.statement) = (yyvsp[0].statement); }
#line 3381 "y.tab.c"
    break;

  case 178: /* statement: iteration_statement  */
#line 1056 "ass6_20CS30042.y"
                        { printInfo("statement", "iteration_statement"); (yyval.statement) = (yyvsp[0].statement); }
#line 3387 "y.tab.c"
    break;

  case 179: /* statement: jump_statement  */
#line 1058 "ass6_20CS30042.y"
                        { printInfo("statement", "jump_statement"); (yyval.statement) = (yyvsp[0].statement); }
#line 3393 "y.tab.c"
    break;

  case 180: /* labeled_statement: IDENTIFIER COLON statement  */
#line 1063 "ass6_20CS30042.y"
                        { printInfo("labeled_statement", "IDENTIFIER : statement"); }
#line 3399 "y.tab.c"
    break;

  case 181: /* labeled_statement: CASE constant_expression COLON statement  */
#line 1065 "ass6_20CS30042.y"
                        { printInfo("labeled_statement", "case constant_expression : statement"); }
#line 3405 "y.tab.c"
    break;

  case 182: /* labeled_statement: DEFAULT COLON statement  */
#line 1067 "ass6_20CS30042.y"
                        { printInfo("labeled_statement", "default : statement"); }
#line 3411 "y.tab.c"
    break;

  case 183: /* compound_statement: LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE  */
#line 1086 "ass6_20CS30042.y"
                                                                             { 
                            printInfo("compound_statement", "{ block_item_list_opt }"); 
                            (yyval.statement) = (yyvsp[-1].statement);
                           // changeTable(currentST->parent); // block over, move back to the parent table
                        }
#line 3421 "y.tab.c"
    break;

  case 184: /* block_item_list_opt: block_item_list  */
#line 1095 "ass6_20CS30042.y"
                        { printInfo("block_item_list_opt", "block_item_list"); (yyval.statement) = (yyvsp[0].statement); }
#line 3427 "y.tab.c"
    break;

  case 185: /* block_item_list_opt: %empty  */
#line 1096 "ass6_20CS30042.y"
                        { printInfo("block_item_list_opt", "epsilon"); (yyval.statement) = new Statement(); }
#line 3433 "y.tab.c"
    break;

  case 186: /* block_item_list: block_item  */
#line 1101 "ass6_20CS30042.y"
                        { printInfo("block_item_list", "block_item"); (yyval.statement) = (yyvsp[0].statement); }
#line 3439 "y.tab.c"
    break;

  case 187: /* block_item_list: block_item_list M block_item  */
#line 1102 "ass6_20CS30042.y"
                                                   { 
                            printInfo("block_item_list", "block_item_list block_item"); 
                            (yyval.statement) = (yyvsp[0].statement);
                            // after completion of block_item_list(1) we move to block_item(3)
                            backpatch((yyvsp[-2].statement)->nextList, (yyvsp[-1].instrNo)); }
#line 3449 "y.tab.c"
    break;

  case 188: /* block_item: declaration  */
#line 1111 "ass6_20CS30042.y"
                        { printInfo("block_item", "declaration"); (yyval.statement) = new Statement(); }
#line 3455 "y.tab.c"
    break;

  case 189: /* block_item: statement  */
#line 1113 "ass6_20CS30042.y"
                        { printInfo("block_item", "statement"); (yyval.statement) = (yyvsp[0].statement); }
#line 3461 "y.tab.c"
    break;

  case 190: /* expression_statement: expression_opt SEMI_COLON  */
#line 1118 "ass6_20CS30042.y"
                        { printInfo("expression_statement", "expression_opt ;");  (yyval.expression) = (yyvsp[-1].expression); }
#line 3467 "y.tab.c"
    break;

  case 191: /* expression_opt: expression  */
#line 1123 "ass6_20CS30042.y"
                        { printInfo("expression_opt", "expression"); (yyval.expression) = (yyvsp[0].expression); }
#line 3473 "y.tab.c"
    break;

  case 192: /* expression_opt: %empty  */
#line 1125 "ass6_20CS30042.y"
                        { printInfo("expression_opt", "epsilon"); (yyval.expression) = new Expression(); }
#line 3479 "y.tab.c"
    break;

  case 193: /* selection_statement: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement N  */
#line 1129 "ass6_20CS30042.y"
                                                                                              { 
                            printInfo("selection_statement", "if ( expression ) statement"); 
                            (yyval.statement) = new Statement(); (yyvsp[-4].expression)->toBool();
                            backpatch((yyvsp[-4].expression)->trueList, (yyvsp[-2].instrNo)); // if true go to M
                            (yyval.statement)->nextList = merge((yyvsp[-4].expression)->falseList, merge((yyvsp[-1].statement)->nextList, (yyvsp[0].statement)->nextList)); // exits
                        }
#line 3490 "y.tab.c"
    break;

  case 194: /* selection_statement: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement N ELSE M statement  */
#line 1135 "ass6_20CS30042.y"
                                                                                                      { 
                            printInfo("selection_statement", "if ( expression ) statement else statement"); 
                            (yyval.statement) = new Statement(); (yyvsp[-7].expression)->toBool();
                            backpatch((yyvsp[-7].expression)->trueList, (yyvsp[-5].instrNo)); // if true go to M
                            backpatch((yyvsp[-7].expression)->falseList, (yyvsp[-1].instrNo)); // if false go to else
                            (yyval.statement)->nextList = merge((yyvsp[0].statement)->nextList, merge((yyvsp[-4].statement)->nextList, (yyvsp[-3].statement)->nextList)); // exits
                        }
#line 3502 "y.tab.c"
    break;

  case 195: /* selection_statement: SWITCH LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement  */
#line 1142 "ass6_20CS30042.y"
                                                                                     { 
                            printInfo("selection_statement", "switch ( expression ) statement"); 
                        }
#line 3510 "y.tab.c"
    break;

  case 196: /* iteration_statement: WHILE M LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement  */
#line 1148 "ass6_20CS30042.y"
                                                                                      { 
                            printInfo("iteration_statement", "while ( expression ) statement"); 
                            (yyval.statement) = new Statement(); (yyvsp[-3].expression)->toBool();
                            backpatch((yyvsp[0].statement)->nextList, (yyvsp[-5].instrNo)); // after statement go back to M1
                            backpatch((yyvsp[-3].expression)->trueList, (yyvsp[-1].instrNo)); // if true go to M2
                            (yyval.statement)->nextList = (yyvsp[-3].expression)->falseList; // exit if false
                            QuadArray::emit("goto", toString((yyvsp[-5].instrNo)));
                        }
#line 3523 "y.tab.c"
    break;

  case 197: /* iteration_statement: DO M statement M WHILE LEFT_PARENTHESIS expression RIGHT_PARENTHESIS SEMI_COLON  */
#line 1156 "ass6_20CS30042.y"
                                                                                                      { 
                            printInfo("iteration_statement", "do statement while ( expression ) ;"); 
                            (yyval.statement) = new Statement(); (yyvsp[-2].expression)->toBool();
                            backpatch((yyvsp[-2].expression)->trueList, (yyvsp[-7].instrNo)); // if true go back to M1
                            backpatch((yyvsp[-6].statement)->nextList, (yyvsp[-5].instrNo)); // after statement is executed go to M2
                            (yyval.statement)->nextList = (yyvsp[-2].expression)->falseList; // exit if false
                        }
#line 3535 "y.tab.c"
    break;

  case 198: /* iteration_statement: FOR LEFT_PARENTHESIS expression_opt SEMI_COLON M expression_opt SEMI_COLON M expression_opt N RIGHT_PARENTHESIS M statement  */
#line 1163 "ass6_20CS30042.y"
                                                                                                                                                  { 
                            printInfo("iteration_statement", "for ( expression_opt ; expression_opt ; expression_opt ) statement"); 
                            (yyval.statement) = new Statement(); (yyvsp[-7].expression)->toBool();
                            backpatch((yyvsp[-7].expression)->trueList, (yyvsp[-1].instrNo)); // if true go to M3 (loop body)
                            backpatch((yyvsp[-3].statement)->nextList, (yyvsp[-8].instrNo)); // after N go to M1 (condition check)
                            backpatch((yyvsp[0].statement)->nextList, (yyvsp[-5].instrNo)); // after S1 (loop body) go to M2 (increment/decrement/any other operation)
                            QuadArray::emit("goto", toString((yyvsp[-5].instrNo)));
                            (yyval.statement)->nextList = (yyvsp[-7].expression)->falseList; // exit if false
                        }
#line 3549 "y.tab.c"
    break;

  case 199: /* iteration_statement: FOR LEFT_PARENTHESIS declaration expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESIS statement  */
#line 1173 "ass6_20CS30042.y"
                        { printInfo("iteration_statement", "for ( declaration expression_opt ; expression_opt ) statement"); }
#line 3555 "y.tab.c"
    break;

  case 200: /* jump_statement: GOTO IDENTIFIER SEMI_COLON  */
#line 1178 "ass6_20CS30042.y"
                        { printInfo("jump_statement", "goto IDENTIFIER ;"); }
#line 3561 "y.tab.c"
    break;

  case 201: /* jump_statement: CONTINUE SEMI_COLON  */
#line 1180 "ass6_20CS30042.y"
                        { printInfo("jump_statement", "continue ;"); }
#line 3567 "y.tab.c"
    break;

  case 202: /* jump_statement: BREAK SEMI_COLON  */
#line 1182 "ass6_20CS30042.y"
                        { printInfo("jump_statement", "break ;"); }
#line 3573 "y.tab.c"
    break;

  case 203: /* jump_statement: RETURN expression_opt SEMI_COLON  */
#line 1183 "ass6_20CS30042.y"
                                                       { 
                            printInfo("jump_statement", "return expression_opt ;"); 
                            (yyval.statement) = new Statement();
                            if((yyvsp[-1].expression)->symbol != NULL) {
                                QuadArray::emit("return", (yyvsp[-1].expression)->symbol->name); // QuadArray::emit the current symbol name at return if it exists otherwise empty
                            } else {
                                QuadArray::emit("return", "");
                            }
                        }
#line 3587 "y.tab.c"
    break;

  case 204: /* translation_unit: external_declaration  */
#line 1198 "ass6_20CS30042.y"
                        { printInfo("translation_unit", "external_declaration"); }
#line 3593 "y.tab.c"
    break;

  case 205: /* translation_unit: translation_unit external_declaration  */
#line 1200 "ass6_20CS30042.y"
                        { printInfo("translation_unit", "translation_unit external_declaration"); }
#line 3599 "y.tab.c"
    break;

  case 206: /* external_declaration: function_definition  */
#line 1205 "ass6_20CS30042.y"
                        { printInfo("external_declaration", "function_definition"); }
#line 3605 "y.tab.c"
    break;

  case 207: /* external_declaration: declaration  */
#line 1207 "ass6_20CS30042.y"
                        { printInfo("external_declaration", "declaration"); }
#line 3611 "y.tab.c"
    break;

  case 208: /* function_definition: declaration_specifiers declarator declaration_list_opt change_scope LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE  */
#line 1212 "ass6_20CS30042.y"
                                                                                                                                               { 
                            printInfo("function_definition", "declaration_specifiers declarator declaration_list_opt compound_statement"); 
                            tableCount = 0;
                            QuadArray::emit("labelend", (yyvsp[-5].symbol)->name);
                            if((yyvsp[-5].symbol)->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update((yyvsp[-5].symbol)->type);
                            }
                           // $2->type=new SymbolType(SymbolType::typeEnum::FUNCTION);
                            changeTable(globalST);
                        }
#line 3627 "y.tab.c"
    break;

  case 209: /* declaration_list_opt: declaration_list  */
#line 1227 "ass6_20CS30042.y"
                        { printInfo("declaration_list_opt", "declaration_list"); }
#line 3633 "y.tab.c"
    break;

  case 210: /* declaration_list_opt: %empty  */
#line 1229 "ass6_20CS30042.y"
                        { printInfo("declaration_list_opt", "Epsilon"); }
#line 3639 "y.tab.c"
    break;

  case 211: /* declaration_list: declaration  */
#line 1234 "ass6_20CS30042.y"
                        { printInfo("declaration_list", "declaration"); }
#line 3645 "y.tab.c"
    break;

  case 212: /* declaration_list: declaration_list declaration  */
#line 1236 "ass6_20CS30042.y"
                        { printInfo("declaration_list", "declaration_list declaration"); }
#line 3651 "y.tab.c"
    break;


#line 3655 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1239 "ass6_20CS30042.y"


void yyerror(string s) {
    printf("ERROR [Line %d] : %s\n", yylineno, s.c_str());
}

void printInfo(string s1, string s2) {
    #ifdef _DEBUG
        printf("[Line %d] : %s => %s\n", yylineno, s1.c_str(), s2.c_str());
    #endif
}
