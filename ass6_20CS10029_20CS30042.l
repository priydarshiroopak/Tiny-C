%{
    #include <stdio.h>
    #include "ass6_20CS10029_20CS30042_translator.h"
    #include "y.tab.h"

%}

%option yylineno

%x MULTI_LINE_COMMENT_BODY
%x SINGLE_LINE_COMMENT_BODY

IDENTIFIER                          {IDENTIFIER_NONDIGIT}[_a-zA-Z0-9]* 
IDENTIFIER_NONDIGIT                 [_a-zA-Z]

INTEGER_CONSTANT                    {NONZERO_DIGIT}{DIGIT}*|"0"
NONZERO_DIGIT                       [1-9]
DIGIT_SEQUENCE                      {DIGIT}+
DIGIT                               [0-9]

FLOATING_CONSTANT                   {FRACTIONAL_CONSTANT}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART}
FRACTIONAL_CONSTANT                 {DIGIT_SEQUENCE}?[.]{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}[.]
EXPONENT_PART                       [eE]{SIGN}?{DIGIT_SEQUENCE}
SIGN                                [+-]

ENUMERATION_CONSTANT                {IDENTIFIER}

CHARACTER_CONSTANT                  \'{C_CHAR_SEQUENCE}\'
C_CHAR_SEQUENCE                     {C_CHAR}+
C_CHAR                              [^\'\n\\]|{ESCAPE_SEQUENCE}
ESCAPE_SEQUENCE                     "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"

STRING_LITERAL                      \"{S_CHAR_SEQUENCE}?\"
S_CHAR_SEQUENCE                     {S_CHAR}+
S_CHAR                              [^\"\n\\]|{ESCAPE_SEQUENCE}

WHITESPACE                          [ \t]+
NEWLINE                             \n

%%

 /* Keywords */
"auto"                                  { return AUTO; }
"break"                                 { return BREAK; }
"case"                                  { return CASE; }
"char"                                  { return CHARTYPE; }
"const"                                 { return CONST; }
"continue"                              { return CONTINUE; }
"default"                               { return DEFAULT; }
"do"                                    { return DO; }
"double"                                { return DOUBLE; }
"else"                                  { return ELSE; }
"enum"                                  { return ENUM; }
"extern"                                { return EXTERN; }
"float"                                 { return FLOATTYPE; }
"for"                                   { return FOR; }
"goto"                                  { return GOTO; }
"if"                                    { return IF; }
"inline"                                { return INLINE; }
"int"                                   { return INTTYPE; }
"long"                                  { return LONG; }
"register"                              { return REGISTER; }
"restrict"                              { return RESTRICT; }
"return"                                { return RETURN; }
"short"                                 { return SHORT; }
"signed"                                { return SIGNED; }
"sizeof"                                { return SIZEOF; }
"static"                                { return STATIC; }
"struct"                                { return STRUCT; }
"switch"                                { return SWITCH; }
"typedef"                               { return TYPEDEF; }
"union"                                 { return UNION; }
"unsigned"                              { return UNSIGNED; }
"void"                                  { return VOIDTYPE; }
"volatile"                              { return VOLATILE; }
"while"                                 { return WHILE; }
"_Bool"                                 { return _BOOL; }
"_Complex"                              { return _COMPLEX; }
"_Imaginary"                            { return _IMAGINARY; }

{IDENTIFIER}                        { yylval.symbol = currentST->lookup(yytext);; return IDENTIFIER; }
{INTEGER_CONSTANT}                  { yylval.intVal = atoi(yytext); return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}                 { yylval.floatVal = strdup(yytext); return FLOATING_CONSTANT; }
{CHARACTER_CONSTANT}                { yylval.charVal = strdup(yytext); return CHARACTER_CONSTANT; }
{STRING_LITERAL}                    { yylval.strVal = strdup(yytext); return STRING_LITERAL; }

 /* Brackets */
"["                                     { return LEFT_SQUARE_BRACE; }
"]"                                     { return RIGHT_SQUARE_BRACE; }
"("                                     { return LEFT_PARENTHESIS; }
")"                                     { return RIGHT_PARENTHESIS; }
"{"                                     { return LEFT_CURLY_BRACE; }
"}"                                     { return RIGHT_CURLY_BRACE; }

 /* Arithmetic Operators */
"++"                                    { return INCREMENT; }
"--"                                    { return DECREMENT; }
"+"                                     { return PLUS; }
"-"                                     { return MINUS; }
"*"                                     { return ASTERISK; }
"/"                                     { return SLASH; }
"%"                                     { return MODULO; }

 /* Relational Operators */
"=="                                    { return EQUALS; }
"!="                                    { return NOT_EQUALS; }
"<"                                     { return LESS_THAN; }
">"                                     { return GREATER_THAN; }
"<="                                    { return LESS_EQUAL_THAN; }
">="                                    { return GREATER_EQUAL_THAN; }

 /* Bitwise Operators */
"&"                                     { return BITWISE_AND; }
"|"                                     { return BITWISE_OR; }
"^"                                     { return BITWISE_XOR; }
"~"                                     { return TILDE; }
"<<"                                    { return LEFT_SHIFT; }
">>"                                    { return RIGHT_SHIFT; }

 /* Logical Operators */
"&&"                                    { return LOGICAL_AND; }
"||"                                    { return LOGICAL_OR; }
"!"                                     { return EXCLAMATION; }

 /* Assignment Operators */
"="                                     { return ASSIGNMENT; }
"*="                                    { return ASTERISK_ASSIGNMENT; }
"/="                                    { return SLASH_ASSIGNMENT; }
"%="                                    { return MODULO_ASSIGNMENT; }
"+="                                    { return PLUS_ASSIGNMENT; }
"-="                                    { return MINUS_ASSIGNMENT; }
"<<="                                   { return LEFT_SHIFT_ASSIGNMENT; }
">>="                                   { return RIGHT_SHIFT_ASSIGNMENT; }
"&="                                    { return BITWISE_AND_ASSIGNMENT; }
"^="                                    { return BITWISE_XOR_ASSIGNMENT; }
"|="                                    { return BITWISE_OR_ASSIGNMENT; }

 /* Other Punctuators */
"."                                     { return DOT; }
"->"                                    { return ARROW; }
"?"                                     { return QUESTION_MARK; }
":"                                     { return COLON; }
";"                                     { return SEMI_COLON; }
"..."                                   { return ELLIPSIS; }
","                                     { return COMMA; }
"#"                                     { return HASH; }

"/*"                                { BEGIN(MULTI_LINE_COMMENT_BODY); }
<MULTI_LINE_COMMENT_BODY>"*/"       { BEGIN(INITIAL);}
<MULTI_LINE_COMMENT_BODY>.          { }
<MULTI_LINE_COMMENT_BODY>"\n"       { /* printf("\n************** Line %d **************\n\n", yylineno); */ }

"//"                                { BEGIN(SINGLE_LINE_COMMENT_BODY); }
<SINGLE_LINE_COMMENT_BODY>"\n"      { BEGIN(INITIAL);  /* printf("\n************** Line %d **************\n\n", yylineno); */}
<SINGLE_LINE_COMMENT_BODY><<EOF>>   { BEGIN(INITIAL);}
<SINGLE_LINE_COMMENT_BODY>.         { }

{WHITESPACE}                        { /* ignore whitespace*/ }
{NEWLINE}                           { /* printf("\n************** Line %d **************\n\n", yylineno); */ }
.                                   { printf("ERROR in Line %d : Invalid token %s\n", yylineno, yytext); return INVALID_TOKEN; }

%%

int yywrap(void)
{
	return 1;
}