%{
    #include "ass6_20CS30042_translator.h"
    extern int yylex();
    extern int yylineno;
    void yyerror(string);
    void printInfo(string s1, string s2);
%}

/*
    intVal, floatVal, charVal, strVal : constants entered by user in code
    idetifierVal : name of identifier
    unaryOperator : the unary operator encountered
    instrNo : backpatching
    parameterCount : number of parameters passed to function
    symbolType : most recent type encountered
*/

%union {
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
}

/* Keywords */
%token AUTO BREAK CASE CHARTYPE CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOATTYPE FOR GOTO IF INLINE INTTYPE LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOIDTYPE VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%token<symbol> IDENTIFIER               // points to its entry in symbol table
%token<intVal> INTEGER_CONSTANT
%token<floatVal> FLOATING_CONSTANT
%token<charVal> CHARACTER_CONSTANT
%token<strVal> STRING_LITERAL

/* Brackets */
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS LEFT_SQUARE_BRACE RIGHT_SQUARE_BRACE  LEFT_CURLY_BRACE RIGHT_CURLY_BRACE

/* Arithmetic Operators */
%token INCREMENT DECREMENT PLUS MINUS ASTERISK SLASH MODULO 

/* Relational Operators */
%token EQUALS NOT_EQUALS LESS_THAN GREATER_THAN LESS_EQUAL_THAN GREATER_EQUAL_THAN

/* Bitwise Operators */
%token BITWISE_AND BITWISE_OR BITWISE_XOR LEFT_SHIFT RIGHT_SHIFT TILDE

/* Logical Operators */
%token LOGICAL_AND LOGICAL_OR EXCLAMATION

/* Assignment Operators */
%token ASSIGNMENT PLUS_ASSIGNMENT MINUS_ASSIGNMENT ASTERISK_ASSIGNMENT SLASH_ASSIGNMENT MODULO_ASSIGNMENT
%token BITWISE_AND_ASSIGNMENT BITWISE_OR_ASSIGNMENT BITWISE_XOR_ASSIGNMENT LEFT_SHIFT_ASSIGNMENT RIGHT_SHIFT_ASSIGNMENT

/* Other Punctuators */
%token QUESTION_MARK DOT ARROW COLON SEMI_COLON ELLIPSIS COMMA HASH

%token INVALID_TOKEN

%right THEN ELSE
%start translation_unit

// Store unary operator as character
%type<unaryOperator> 
    unary_operator

// Store parameter count as integer
%type<parameterCount> 
    argument_expression_list_opt
    argument_expression_list 

// Expressions
%type<expression>
    expression_opt
	expression_statement
	assignment_expression
	conditional_expression
	logical_OR_expression
	logical_AND_expression
	inclusive_OR_expression
	exclusive_OR_expression
	AND_expression
	equality_expression
	relational_expression
	shift_expression
	additive_expression
	multiplicative_expression
	primary_expression 
	expression

// Arrays
%type<array> 
	unary_expression
	cast_expression
    postfix_expression

// Statements
%type <statement>  
	jump_statement
	labeled_statement 
	iteration_statement
	selection_statement
	compound_statement
    statement
	block_item_list_opt
	block_item_list
	block_item
    N

// symbol type
%type<symbolType> 
    pointer

// Symbol
%type<symbol> 
    declarator
    init_declarator 
    direct_declarator 
    initialiser

// Instruction number for backpatching
%type <instrNo> 
    M

%%

/* EXPRESSIONS */

/*
constants: create a temporary with that initial value and create a new expression 
with the symbol pointing to the newly generated temporary
identifiers: points to the identifier which in itself is a symbol
*/
primary_expression: 
                    IDENTIFIER { 
                            printInfo("primary_expression", "IDENTIFIER");
                            $$ = new Expression(); // create new non boolean expression and symbol is the identifier
                            $$->isBoolean = False; $$->symbol = $1; }
                    | INTEGER_CONSTANT { 
                            printInfo("primary_expression", "INTEGER_CONSTANT"); 
                            $$ = new Expression(); $$->symbol = SymbolTable::gentemp(SymbolType::INT, toString($1));
                            QuadArray::emit("=", $$->symbol->name, $1); }
                    | FLOATING_CONSTANT { 
                            printInfo("primary_expression", "FLOATING_CONSTANT"); 
                            $$ = new Expression(); $$->symbol = SymbolTable::gentemp(SymbolType::FLOAT, $1);
                            QuadArray::emit("=", $$->symbol->name, $1); }
                    | CHARACTER_CONSTANT { 
                            printInfo("primary_expression", "CHARACTER_CONSTANT"); 
                            $$ = new Expression(); $$->symbol = SymbolTable::gentemp(SymbolType::CHAR, $1);
                            QuadArray::emit("=", $$->symbol->name, $1); }
                    | STRING_LITERAL { 
                            printInfo("primary_expression", "STRING_LITERAL"); 
                            $$ = new Expression(); $$->symbol = SymbolTable::gentemp(SymbolType::POINTER, $1);
		                    $$->symbol->type->arrayType = new SymbolType(SymbolType::CHAR); 
                            QuadArray::emit("=str", $$->symbol->name, stringLiterals.size());
                            stringLiterals.push_back($1);
                            }
                    | LEFT_PARENTHESIS expression RIGHT_PARENTHESIS { 
                            printInfo("primary_expression", "( expression )"); 
                            $$ = $2; }
                    ;

postfix_expression:
                    primary_expression { 
                            // create new array with the same symbol as the primary expression
                            printInfo("postfix_expression", "primary_expression"); 
                            $$ = new Array();
                            $$->symbol = $1->symbol; $$->temp = $$->symbol;
                            $$->subArrayType = $1->symbol->type; }
                    | postfix_expression LEFT_SQUARE_BRACE expression RIGHT_SQUARE_BRACE { 
                            // create a new array
                            printInfo("postfix_expression", "postfix_expression [ expression ]"); 
                            $$ = new Array();
                            $$->symbol = $1->symbol;    // same symbol
                            $$->subArrayType = $1->subArrayType->arrayType; // go one level deeper
                            $$->temp = SymbolTable::gentemp(SymbolType::INT); // temporary to compute location
                            $$->type = Array::ARRAY;    // type will be array

                            if($1->type == Array::ARRAY) {
                                // postfix_expression is already array so multiply size of subarray with expression and add
                                Symbol *sym = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit("*", sym->name, $3->symbol->name, toString($$->subArrayType->getSize()));
                                QuadArray::emit("+", $$->temp->name, $1->temp->name, sym->name); }
                            else {
                                QuadArray::emit("*", $$->temp->name, $3->symbol->name, toString($$->subArrayType->getSize()));
                            }
                        }
                    | postfix_expression LEFT_PARENTHESIS argument_expression_list_opt RIGHT_PARENTHESIS {
                            // function call, number of parameters stored in argument_expression_list_opt
                            printInfo("postfix_expression", "postfix_expression ( argument_expression_list_opt )"); 
                            $$ = new Array(); $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                            QuadArray::emit("call", $$->symbol->name, $1->symbol->name, toString($3)); }
                    | postfix_expression DOT IDENTIFIER { 
                            printInfo("postfix_expression", "postfix_expression . IDENTIFIER"); }
                    | postfix_expression ARROW IDENTIFIER { 
                            printInfo("postfix_expression", "postfix_expression -> IDENTIFIER"); }
                    | postfix_expression INCREMENT { 
                            // post increment, first generate temporary with old value, then add 1
                            printInfo("postfix_expression", "postfix_expression ++");
                            $$ = new Array(); $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                            QuadArray::emit("=", $$->symbol->name, $1->symbol->name);
                            QuadArray::emit("+", $1->symbol->name, $1->symbol->name, toString(1)); }
                    | postfix_expression DECREMENT { 
                            // post decrement, first generate temporary with old value, then subtract 1
                            printInfo("postfix_expression", "postfix_expression --"); 
                            $$ = new Array();
                            $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                            QuadArray::emit("=", $$->symbol->name, $1->symbol->name);
                            QuadArray::emit("-", $1->symbol->name, $1->symbol->name, toString(1)); }
                    | LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS LEFT_CURLY_BRACE initialiser_list RIGHT_CURLY_BRACE { 
                            printInfo("postfix_expression", "( type_name ) { initialiser_list }");  }
                    | LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS LEFT_CURLY_BRACE initialiser_list COMMA RIGHT_CURLY_BRACE { 
                            printInfo("postfix_expression", "( type_name ) { initialiser_list , }");  }
                    ;


// equate number of parameters
argument_expression_list_opt:
                    argument_expression_list {
                        printInfo("argument_expression_list_opt", "argument_expression_list"); 
                        $$ = $1; }
                    | 
                        {// 0 params
                        printInfo("argument_expression_list_opt", "epsilon");
                        $$ = 0; }
                    ;

argument_expression_list:
                    assignment_expression { 
                        // initialise param count to 1
                        printInfo("argument_expression_list", "assignment_expression"); 
                        QuadArray::emit("param", $1->symbol->name);
                        $$ = 1; }
                    | argument_expression_list COMMA assignment_expression { 
                        // new param, add 1 to param count
                        printInfo("argument_expression_list", "argument_expression_list , assignment_expression");
                        QuadArray::emit("param", $3->symbol->name);
                        $$ = $1 + 1; }
                    ;

unary_expression:
                    postfix_expression {
                        printInfo("unary_expression", "postfix_expression"); 
                        $$ = $1;}
                    | INCREMENT unary_expression {
                        // pre increment, no new temporary, add 1
                        printInfo("unary_expression", "++ unary_expression"); 
                        $$ = $2;
                        QuadArray::emit("+", $2->symbol->name, $2->symbol->name, toString(1)); }
                    | DECREMENT unary_expression { 
                        // pre decrement, no new temporary, subtract 1
                        printInfo("unary_expression", "-- unary_expression"); 
                        $$ = $2;
                        QuadArray::emit("-", $2->symbol->name, $2->symbol->name, toString(1)); }
                    | unary_operator cast_expression { 
                        printInfo("unary_expression", "unary_operator cast_expression");
                        switch($1[0]) {
                            case '&':   // addressing, this generates a pointer, the subArray type will thus be the symbol type of the cast_expression
                                        $$ = new Array();
                                        $$->symbol = SymbolTable::gentemp(SymbolType::POINTER);
                                        $$->symbol->type->arrayType = $2->symbol->type;
                                        QuadArray::emit("=&", $$->symbol->name, $2->symbol->name);
                                        break;
                            case '*':   // dereferncing, this generates a pointer, a new temporary generated with type as the subarray type of the cast_expression
                                        // the subArray type will thus be one level deeper that of the cast_expression
                                        $$ = new Array();   $$->symbol = $2->symbol;
                                        $$->temp = SymbolTable::gentemp($2->temp->type->arrayType->type);
                                        $$->temp->type->arrayType = $2->temp->type->arrayType->arrayType;
                                        $$->type = Array::POINTER;
                                        QuadArray::emit("=*", $$->temp->name, $2->temp->name);
                                        break;
                            case '+':   $$ = $2; break;
                            default:    // for -, ~ and !
                                        // apply the operator on cast_expression
                                        $$ = new Array();
                                        $$->symbol = SymbolTable::gentemp($2->symbol->type->type);
                                        QuadArray::emit($1, $$->symbol->name, $2->symbol->name);
                                        break;
                            }
                        }
                    | SIZEOF unary_expression
                        { printInfo("unary_expression", "sizeof unary_expression"); }
                    | SIZEOF LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS
                        { printInfo("unary_expression", "sizeof ( type_name )"); }
                    ;

// Store the unary operator
unary_operator:
                BITWISE_AND
                    { printInfo("unary_operator", "&"); $$ = strdup("&"); }
                | ASTERISK
                    { printInfo("unary_operator", "*"); $$ = strdup("*"); }
                | PLUS
                    { printInfo("unary_operator", "+"); $$ = strdup("+"); }
                | MINUS
                    { printInfo("unary_operator", "-"); $$ = strdup("=-"); }
                | TILDE
                    { printInfo("unary_operator", "~"); $$ = strdup("~"); }
                | EXCLAMATION
                    { printInfo("unary_operator", "!"); $$ = strdup("!"); }
                ;

cast_expression:
                unary_expression
                    { printInfo("cast_expression", "unary_expression"); $$ = $1; }
                | LEFT_PARENTHESIS type_name RIGHT_PARENTHESIS cast_expression
                    { printInfo("cast_expression", "( type_name ) cast_expression"); 
                    $$ = new Array(); $$->symbol = $4->symbol->convert(currentType); }
                ;

/*
Here an array goes to a expression
As a first step, we extract the base type of the array, then if the type is array we obtain the value by indexing
by using the symbol name, the temporary used to calculate the location and assign it to the newly generated temporary

*/

/*
If it is a pointer or normal array then simply equate the symbol
Then apply the necessary operation that is *,/ or % after type checking

Below this for additive and shift expressions simply follow the same procedure, check types, generate temporary and store the result of
the operation in a newly generated temporary
*/

multiplicative_expression:
                            cast_expression { 
                                    SymbolType *baseType = $1->symbol->type;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    printInfo("multiplicative_expression", "cast_expression"); 
                                    $$ = new Expression();
                                    if($1->type == Array::ARRAY) {
                                        $$->symbol = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", $$->symbol->name, $1->symbol->name, $1->temp->name); }
                                    else if($1->type == Array::POINTER) $$->symbol = $1->temp;
                                    else $$->symbol = $1->symbol;
                                }
                            | multiplicative_expression ASTERISK cast_expression { 
                                    SymbolType *baseType = $3->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if($3->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, $3->symbol->name, $3->temp->name); }
                                    else if($3->type == Array::POINTER) temp = $3->temp;
                                    else temp = $3->symbol;

                                    printInfo("multiplicative_expression", "multiplicative_expression * cast_expression"); 
                                    if(typeCheck($1->symbol, temp)) {
                                        $$ = new Expression();
                                        $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                                        QuadArray::emit("*", $$->symbol->name, $1->symbol->name, temp->name); }
                                    else yyerror("Type error.");
                                }
                            | multiplicative_expression SLASH cast_expression { 
                                    SymbolType *baseType = $3->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if($3->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, $3->symbol->name, $3->temp->name); }
                                    else if($3->type == Array::POINTER) temp = $3->temp;
                                    else temp = $3->symbol;
                                
                                    printInfo("multiplicative_expression", "multiplicative_expression / cast_expression");
                                    if(typeCheck($1->symbol, temp)) {
                                        $$ = new Expression();
                                        $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                                        QuadArray::emit("/", $$->symbol->name, $1->symbol->name, temp->name); }
                                    else yyerror("Type error.");
                                }
                            | multiplicative_expression MODULO cast_expression { 
                                    SymbolType *baseType = $3->symbol->type;
                                    Symbol *temp;
                                    while(baseType->arrayType) baseType = baseType->arrayType;
                                    if($3->type == Array::ARRAY) {
                                        temp = SymbolTable::gentemp(baseType->type);
                                        QuadArray::emit("=[]", temp->name, $3->symbol->name, $3->temp->name); }
                                    else if($3->type == Array::POINTER) temp = $3->temp;
                                    else temp = $3->symbol;
                                    printInfo("multiplicative_expression", "multiplicative_expression % cast_expression"); 
                                    if(typeCheck($1->symbol, temp)) {
                                        $$ = new Expression();
                                        $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                                        QuadArray::emit("%", $$->symbol->name, $1->symbol->name, temp->name); }
                                    else  yyerror("Type error.");
                                }
                            ;

additive_expression:
                    multiplicative_expression { 
                            printInfo("additive_expression", "multiplicative_expression"); 
                            $$ = $1; }
                    | additive_expression PLUS multiplicative_expression { 
                            printInfo("additive_expression", "additive_expression + multiplicative_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                                QuadArray::emit("+", $$->symbol->name, $1->symbol->name, $3->symbol->name); }
                            else yyerror("Type error.");
                        }
                    | additive_expression MINUS multiplicative_expression { 
                            printInfo("additive_expression", "additive_expression - multiplicative_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->symbol = SymbolTable::gentemp($1->symbol->type->type);
                                QuadArray::emit("-", $$->symbol->name, $1->symbol->name, $3->symbol->name);
                            } else  yyerror("Type error.");
                        }
                    ;

shift_expression:
                    additive_expression
                        { printInfo("shift_expression", "additive_expression"); $$ = $1; }
                    | shift_expression LEFT_SHIFT additive_expression { 
                            printInfo("shift_expression", "shift_expression << additive_expression"); 
                            if($3->symbol->type->type == SymbolType::INT) {
                                $$ = new Expression();
                                $$->symbol = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit("<<", $$->symbol->name, $1->symbol->name, $3->symbol->name); }
                            else  yyerror("Type error.");
                        }
                    | shift_expression RIGHT_SHIFT additive_expression { 
                            printInfo("shift_expression", "shift_expression >> additive_expression"); 
                            if($3->symbol->type->type == SymbolType::INT) {
                                $$ = new Expression();
                                $$->symbol = SymbolTable::gentemp(SymbolType::INT);
                                QuadArray::emit(">>", $$->symbol->name, $1->symbol->name, $3->symbol->name); }
                            else yyerror("Type error.");
                        }
                    ;

/*
Translations for boolean expression: 
appropriate operation is applied,
here the trueList and falseList are also made which will be later used 
and backpatched with appropriate destinations
*/

relational_expression:
                    shift_expression
                        { printInfo("relational_expression", "shift_expression");  $$ = $1; }
                    | relational_expression LESS_THAN shift_expression { 
                            printInfo("relational_expression", "relational_expression < shift_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
                                $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("<", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
                    | relational_expression GREATER_THAN shift_expression { 
                            printInfo("relational_expression", "relational_expression > shift_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
                                $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit(">", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
                    | relational_expression LESS_EQUAL_THAN shift_expression { 
                            printInfo("relational_expression", "relational_expression <= shift_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
                                $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("<=", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else  yyerror("Type error.");
                        }
                    | relational_expression GREATER_EQUAL_THAN shift_expression { 
                            printInfo("relational_expression", "relational_expression >= shift_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $$ = new Expression();
                                $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
                                $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit(">=", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
                    ;

equality_expression:
                    relational_expression
                        { printInfo("equality_expression", "relational_expression"); $$ = $1; }
                    | equality_expression EQUALS relational_expression { 
                            printInfo("equality_expression", "equality_expression == relational_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $1->toInt(); $3->toInt();
                                $$ = new Expression(); $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
			                    $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("==", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
                    | equality_expression NOT_EQUALS relational_expression { 
                            printInfo("equality_expression", "equality_expression != relational_expression"); 
                            if(typeCheck($1->symbol, $3->symbol)) {
                                $1->toInt(); $3->toInt();
                                $$ = new Expression(); $$->isBoolean = True;
                                $$->trueList = makeList(nextInstruction());
			                    $$->falseList = makeList(nextInstruction() + 1);
                                QuadArray::emit("!=", "", $1->symbol->name, $3->symbol->name);
                                QuadArray::emit("goto", ""); }
                            else yyerror("Type error.");
                        }
                    ;


AND_expression:
                    equality_expression
                        { printInfo("AND_expression", "equality_expression"); $$ = $1; }
                    | AND_expression BITWISE_AND equality_expression { 
                            printInfo("AND_expression", "AND_expression & equality_expression"); 
                            $1->toInt(); $3->toInt();
                            $$ = new Expression(); $$->isBoolean = False;
                            $$->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("&", $$->symbol->name, $1->symbol->name, $3->symbol->name);
                        }
                    ;

exclusive_OR_expression:
                    AND_expression
                        { printInfo("exclusive_OR_expression", "AND_expression");  $$ = $1; }
                    | exclusive_OR_expression BITWISE_XOR AND_expression { 
                            printInfo("exclusive_OR_expression", "exclusive_OR_expression ^ AND_expression"); 
                            $1->toInt(); $3->toInt();
                            $$ = new Expression(); $$->isBoolean = False;
                            $$->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("^", $$->symbol->name, $1->symbol->name, $3->symbol->name);
                        }
                    ;

inclusive_OR_expression:
                    exclusive_OR_expression
                        { printInfo("inclusive_OR_expression", "exclusive_OR_expression"); $$ = $1; }
                    | inclusive_OR_expression BITWISE_OR exclusive_OR_expression { 
                            printInfo("inclusive_OR_expression", "inclusive_OR_expression | exclusive_OR_expression"); 
                            $1->toInt(); $3->toInt();
                            $$ = new Expression(); $$->isBoolean = False;
                            $$->symbol = SymbolTable::gentemp(SymbolType::INT);
                            QuadArray::emit("|", $$->symbol->name, $1->symbol->name, $3->symbol->name);
                        }
                    ;

/*

Marker rule
M -> stores the next instruction, the location of the quad generated at M, used for backpatching later

Fall through guard rule
N -> nextlist, list of indices of dangling exits at N

*/

M:  { printInfo("M", "epsilon"); $$ = nextInstruction(); } ;

N:  { printInfo("N", "epsilon"); $$ = new Statement();
      $$->nextList = makeList(nextInstruction()); QuadArray::emit("goto", "");
    } ;

logical_AND_expression:
                    inclusive_OR_expression
                        { printInfo("logical_AND_expression", "inclusive_OR_expression"); $$ = $1; }
                    | logical_AND_expression LOGICAL_AND M inclusive_OR_expression { 
                            printInfo("logical_AND_expression", "logical_AND_expression && inclusive_OR_expression");
                            $1->toBool(); $4->toBool();
                            $$ = new Expression(); $$->isBoolean = True;
                            backpatch($1->trueList, $3); $$->trueList = $4->trueList;
                            $$->falseList = merge($1->falseList, $4->falseList);
                        }
                    ;

logical_OR_expression:
                    logical_AND_expression
                        { printInfo("logical_OR_expression", "logical_AND_expression");  $$ = $1; }
                    | logical_OR_expression LOGICAL_OR M logical_AND_expression { 
                            printInfo("logical_OR_expression", "logical_OR_expression || logical_AND_expression"); 
                            $1->toBool(); $4->toBool();
                            $$ = new Expression(); $$->isBoolean = True;
                            backpatch($1->falseList, $3);
                            $$->trueList = merge($1->trueList, $4->trueList);
                            $$->falseList = $4->falseList;
                        }
                    ;

conditional_expression:
                    logical_OR_expression
                        { printInfo("conditional_expression", "logical_OR_expression"); $$ = $1; }
                    | logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression { 
                            printInfo("conditional_expression", "logical_OR_expression ? expression : conditional_expression"); 
                            $$->symbol = SymbolTable::gentemp($5->symbol->type->type);
                            QuadArray::emit("=", $$->symbol->name, $9->symbol->name);
                            vector<int> l = makeList(nextInstruction());
                            QuadArray::emit("goto", "");
                            backpatch($6->nextList, nextInstruction());
                            QuadArray::emit("=", $$->symbol->name, $5->symbol->name);
                            l = merge(l, makeList(nextInstruction()));
                            QuadArray::emit("goto", "");
                            backpatch($2->nextList, nextInstruction());
                            $1->toBool();
                            backpatch($1->trueList, $4);
                            backpatch($1->falseList, $8);
                            backpatch(l, nextInstruction());
                        }
                    ;

assignment_expression:
                    conditional_expression
                        { printInfo("assignment_expression", "conditional_expression");  $$ = $1; }
                    | unary_expression assignment_operator assignment_expression { 
                            printInfo("assignment_expression", "unary_expression assignment_operator assignment_expression"); 
                            if($1->type == Array::ARRAY) {
                                // assignment to array
                                $3->symbol = $3->symbol->convert($1->subArrayType->type);
                                QuadArray::emit("[]=", $1->symbol->name, $1->temp->name, $3->symbol->name); }
                            else if($1->type == Array::POINTER) {
                                // assignment to pointer
                                $3->symbol = $3->symbol->convert($1->temp->type->type);
                                QuadArray::emit("*=", $1->temp->name, $3->symbol->name); }
                            else {
                                // assignment to other
                                $3->symbol = $3->symbol->convert($1->symbol->type->type);
                                QuadArray::emit("=", $1->symbol->name, $3->symbol->name); }
                            $$ = $3;
                        }
                    ;

assignment_operator:
                    ASSIGNMENT
                        { printInfo("assignment_operator", "="); }
                    | ASTERISK_ASSIGNMENT
                        { printInfo("assignment_operator", "*="); }
                    | SLASH_ASSIGNMENT
                        { printInfo("assignment_operator", "/="); }
                    | MODULO_ASSIGNMENT
                        { printInfo("assignment_operator", "%="); }
                    | PLUS_ASSIGNMENT
                        { printInfo("assignment_operator", "+= "); }
                    | MINUS_ASSIGNMENT
                        { printInfo("assignment_operator", "-= "); }
                    | LEFT_SHIFT_ASSIGNMENT
                        { printInfo("assignment_operator", "<<="); }
                    | RIGHT_SHIFT_ASSIGNMENT
                        { printInfo("assignment_operator", ">>="); }
                    | BITWISE_AND_ASSIGNMENT
                        { printInfo("assignment_operator", "&="); }
                    | BITWISE_XOR_ASSIGNMENT
                        { printInfo("assignment_operator", "^="); }
                    | BITWISE_OR_ASSIGNMENT
                        { printInfo("assignment_operator", "|="); }
                    ;

expression:
                    assignment_expression
                        { printInfo("expression", "assignment_expression"); $$ = $1; }
                    | expression COMMA assignment_expression
                        { printInfo("expression", "expression , assignment_expression"); }
                    ;

constant_expression:
                    conditional_expression
                        { printInfo("constant_expression", "conditional_expression"); }
                    ;

/* DECLARATIONS */
declaration:
                    declaration_specifiers init_declarator_list_opt SEMI_COLON
                        { printInfo("declaration", "declaration_specifiers init_declarator_list_opt ;"); }
                    ;

init_declarator_list_opt:
                    init_declarator_list
                        { printInfo("init_declarator_list_opt", "init_declarator_list"); }
                    |
                        { printInfo("init_declarator_list_opt", "Epsilon"); }
                    ;
declaration_specifiers:
                    storage_class_specifier declaration_specifiers_opt
                        { printInfo("declaration_specifiers", "storage_class_specifier declaration_specifiers_opt"); }
                    | type_specifier declaration_specifiers_opt
                        { printInfo("declaration_specifiers", "type_specifier declaration_specifiers_opt"); }
                    | type_qualifier declaration_specifiers_opt
                        { printInfo("declaration_specifiers", "type_qualifier declaration_specifiers_opt"); }
                    | function_specifier declaration_specifiers_opt
                        { printInfo("declaration_specifiers", "function_specifier declaration_specifiers_opt"); }
                    ;

declaration_specifiers_opt:
                    declaration_specifiers
                        { printInfo("declaration_specifiers_opt", "declaration_specifiers"); }
                    |
                        { printInfo("declaration_specifiers_opt", "Epsilon "); }
                    ;

init_declarator_list:
                    init_declarator
                        { printInfo("init_declarator_list", "init_declarator"); }
                    | init_declarator_list COMMA init_declarator
                        { printInfo("init_declarator_list", "init_declarator_list , init_declarator"); }
                    ;

init_declarator:
                    declarator
                        { printInfo("init_declarator", "declarator"); $$ = $1; }
                    | declarator ASSIGNMENT initialiser { 
                            printInfo("init_declarator", "declarator = initialiser");
                            // if there is some initial value assign it 
                            if($3->initialValue != "") $1->initialValue = $3->initialValue;
                            // = assignment
                            QuadArray::emit("=", $1->name, $3->name);
                        }
                    ;

storage_class_specifier:
                    EXTERN
                        { printInfo("storage_class_specifier", "extern"); }
                    | STATIC
                        { printInfo("storage_class_specifier", "static"); }
                    | AUTO
                        { printInfo("storage_class_specifier", "auto"); }
                    | REGISTER
                        { printInfo("storage_class_specifier", "register"); }
                    ;

type_specifier:
                    VOIDTYPE
                        { printInfo("type_specifier", "void"); currentType = SymbolType::VOID; }
                    | CHARTYPE
                        { printInfo("type_specifier", "char"); 
                            currentType = SymbolType::CHAR; }
                    | SHORT
                        { printInfo("type_specifier", "short"); }
                    | INTTYPE
                        { printInfo("type_specifier", "int"); currentType = SymbolType::INT; }
                    | LONG
                        { printInfo("type_specifier", "long"); }
                    | FLOATTYPE
                        { printInfo("type_specifier", "float"); currentType = SymbolType::FLOAT;}
                    | DOUBLE
                        { printInfo("type_specifier", "double"); }
                    | SIGNED
                        { printInfo("type_specifier", "signed"); }
                    | UNSIGNED
                        { printInfo("type_specifier", "unsigned"); }
                    | _BOOL
                        { printInfo("type_specifier", "_Bool"); }
                    | _COMPLEX
                        { printInfo("type_specifier", "_Complex"); }
                    | _IMAGINARY
                        { printInfo("type_specifier", "_Imaginary"); }
                    | enum_specifier 
                        { printInfo("type_specifier", "enum_specifier"); }
                    ;

specifier_qualifier_list:
                    type_specifier specifier_qualifier_list_opt
                        { printInfo("specifier_qualifier_list", "type_specifier specifier_qualifier_list_opt"); }
                    | type_qualifier specifier_qualifier_list_opt
                        { printInfo("specifier_qualifier_list", "type_qualifier specifier_qualifier_list_opt"); }
                    ;

specifier_qualifier_list_opt:
                    specifier_qualifier_list
                        { printInfo("specifier_qualifier_list_opt", "specifier_qualifier_list"); }
                    | 
                        { printInfo("specifier_qualifier_list_opt", "Epsilon"); }
                    ;

enum_specifier:
                    ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE 
                        { printInfo("enum_specifier", "enum identifier_opt { enumerator_list }"); }
                    | ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE
                        { printInfo("enum_specifier", "enum identifier_opt { enumerator_list , }"); }
                    | ENUM IDENTIFIER
                        { printInfo("enum_specifier", "enum IDENTIFIER"); }
                    ;

identifier_opt:
                    IDENTIFIER 
                        { printInfo("identifier_opt", "IDENTIFIER"); }
                    | 
                        { printInfo("identifier_opt", "epsilon"); }
                    ;

enumerator_list:
                    enumerator 
                        { printInfo("enumerator_list", "enumerator"); }
                    | enumerator_list COMMA enumerator
                        { printInfo("enumerator_list", "enumerator_list , enumerator"); }
                    ;

enumerator:
                    IDENTIFIER 
                        { printInfo("enumerator", "ENUMERATION_CONSTANT"); }
                    | IDENTIFIER ASSIGNMENT constant_expression
                        { printInfo("enumerator", "ENUMERATION_CONSTANT = constant_expression"); }
                    ;

type_qualifier:
                    CONST
                        { printInfo("type_qualifier", "const"); }
                    | RESTRICT
                        { printInfo("type_qualifier", "restrict"); }
                    | VOLATILE
                        { printInfo("type_qualifier", "volatile"); }
                    ;

function_specifier:
                    INLINE
                        { printInfo("function_specifier", "inline"); }
                    ;

declarator:
                    pointer direct_declarator { 
                            printInfo("declarator", "pointer direct_declarator"); 
                            SymbolType *it = $1;
                            while(it->arrayType != NULL) 
                                it = it->arrayType;
                            it->arrayType = $2->type;
                            $$ = $2->update($1);
                        }
                    | direct_declarator
                        { printInfo("declarator", "direct_declarator"); }
                    ;

change_scope:       {if(currentSymbol->nestedTable == NULL) changeTable(new SymbolTable(""));
                     else {
                            changeTable(currentSymbol->nestedTable);
                            QuadArray::emit("label", currentST->name);
                        }
                    }
	                ;

direct_declarator:
                    IDENTIFIER  { 
                            printInfo("direct_declarator", "IDENTIFIER"); 
                            $$ = $1->update(new SymbolType(currentType)); // update type to the last type seen
                            currentSymbol = $$;
                        }
                    | LEFT_PARENTHESIS declarator RIGHT_PARENTHESIS
                        { printInfo("direct_declarator", "( declarator )"); $$ = $2; }
                    | direct_declarator LEFT_SQUARE_BRACE type_qualifier_list assignment_expression RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list assignment_expression ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE type_qualifier_list RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE assignment_expression RIGHT_SQUARE_BRACE { 
                            printInfo("direct_declarator", "direct_declarator [ assignment_expression ]"); 
                            SymbolType *it1 = $1->type, *it2 = NULL;
                            while(it1->type == SymbolType::typeEnum::ARRAY) { // go to the base level of a nested type
                                it2 = it1; it1 = it1->arrayType;
                            }
                            if(it2 != NULL) { // nested array case
                                // another level of nesting with base as it1 and width the value of assignment_expression
                                it2->arrayType =  new SymbolType(SymbolType::typeEnum::ARRAY, it1, atoi($3->symbol->initialValue.c_str()));	
                                $$ = $1->update($1->type); }
                            else { // fresh array
                                // create a new array with base as type of direct_declarator and width the value of assignment_expression
                                $$ = $1->update(new SymbolType(SymbolType::typeEnum::ARRAY, $1->type, atoi($3->symbol->initialValue.c_str())));
                            }
                        }
                    | direct_declarator LEFT_SQUARE_BRACE RIGHT_SQUARE_BRACE { 
                            printInfo("direct_declarator", "direct_declarator [ ]"); 
                            // same as the previous rule, just we dont know the size so put it as 0
                            SymbolType *it1 = $1->type, *it2 = NULL;
                            while(it1->type == SymbolType::typeEnum::ARRAY) { // go to the base level of a nested type
                                it2 = it1; it1 = it1->arrayType;
                            }
                            if(it2 != NULL) { // nested array case
                                // another level of nesting with base as it1 and width the value of assignment_expression
                                it2->arrayType =  new SymbolType(SymbolType::typeEnum::ARRAY, it1, 0);	
                                $$ = $1->update($1->type); }
                            else { // fresh array
                                // create a new array with base as type of direct_declarator and width the value of assignment_expression
                                $$ = $1->update(new SymbolType(SymbolType::typeEnum::ARRAY, $1->type, 0));
                            }
                        }
                    | direct_declarator LEFT_SQUARE_BRACE STATIC type_qualifier_list assignment_expression RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ static type_qualifier_list assignment_expression ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE STATIC assignment_expression RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ assignment_expression ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE type_qualifier_list STATIC assignment_expression RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list static assignment_expression ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE type_qualifier_list ASTERISK RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ type_qualifier_list * ]"); }
                    | direct_declarator LEFT_SQUARE_BRACE ASTERISK RIGHT_SQUARE_BRACE
                        { printInfo("direct_declarator", "direct_declarator [ * ]"); }
                    | direct_declarator LEFT_PARENTHESIS change_scope parameter_type_list RIGHT_PARENTHESIS {
                            printInfo("direct_declarator", "direct_declarator ( parameter_type_list )"); 
                            // function declaration
                            currentST->name = $1->name;
                            if($1->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update($1->type);
                            }
                            // move back to the global table and set the nested table for the function
                            $1->nestedTable = currentST;
                            $1->category = Symbol::FUNCTION;
                            currentST->parent = globalST;
                            changeTable(globalST); currentSymbol = $$;
                        }
                    | direct_declarator LEFT_PARENTHESIS identifier_list RIGHT_PARENTHESIS
                        { printInfo("direct_declarator", "direct_declarator ( identifier_list )"); }
                    | direct_declarator LEFT_PARENTHESIS change_scope RIGHT_PARENTHESIS { 
                            printInfo("direct_declarator", "direct_declarator ( )"); 
                            // same as the previous rule
                            currentST->name = $1->name;
                            if($1->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update($1->type);
                            }
                            // move back to the global table and set the nested table for the function
                            $1->nestedTable = currentST;
                            $1->category = Symbol::FUNCTION;
                            currentST->parent = globalST;
                            changeTable(globalST); currentSymbol = $$;
                        }
                    ;

type_qualifier_list_opt:
                    type_qualifier_list
                        { printInfo("type_qualifier_list_opt", "type_qualifier_list"); }
                    |
                        { printInfo("type_qualifier_list_opt", "Epsilon"); }
                    ;

/*
Pointer declarations,
Generate new symbol with type pointer
*/

pointer:
                    ASTERISK type_qualifier_list_opt { 
                            printInfo("pointer", "* type_qualifier_list_opt"); 
                            // fresh pointer
                            $$ = new SymbolType(SymbolType::POINTER);
                        }
                    | ASTERISK type_qualifier_list_opt pointer { 
                            printInfo("pointer", "* type_qualifier_list_opt pointer"); 
                            // nested pointer
                            $$ = new SymbolType(SymbolType::POINTER, $3);
                        }
                    ;

type_qualifier_list:
                    type_qualifier
                        { printInfo("type_qualifier_list", "type_qualifier"); }
                    | type_qualifier_list type_qualifier
                        { printInfo("type_qualifier_list", "type_qualifier_list type_qualifier"); }
                    ;

parameter_type_list:
                    parameter_list
                        { printInfo("parameter_type_list", "parameter_list"); }
                    | parameter_list COMMA ELLIPSIS
                        { printInfo("parameter_type_list", "parameter_list , ..."); }
                    ;

parameter_list:
                    parameter_declaration
                        { printInfo("parameter_list", "parameter_declaration"); }
                    | parameter_list COMMA parameter_declaration
                        { printInfo("parameter_list", "parameter_list , parameter_declaration"); }
                    ;

parameter_declaration:
                    declaration_specifiers declarator
                        { printInfo("parameter_declaration", "declaration_specifiers declarator"); 
                                $2->category = Symbol::PARAMETER; 
                                currentST->parameters.push_back($2->name); //**************
                        }
                    | declaration_specifiers
                        { printInfo("parameter_declaration", "declaration_specifiers"); }
                    ;

identifier_list:
                    IDENTIFIER 
                        { printInfo("identifier_list", "IDENTIFIER"); }
                    | identifier_list COMMA IDENTIFIER
                        { printInfo("identifier_list", "identifier_list , IDENTIFIER"); }
                    ;

type_name:
                    specifier_qualifier_list
                        { printInfo("type_name", "specifier_qualifier_list"); }
                    ;

initialiser:
            assignment_expression
                { printInfo("initialiser", "assignment_expression"); $$ = $1->symbol; }
            | LEFT_CURLY_BRACE initialiser_list RIGHT_CURLY_BRACE
                { printInfo("initialiser", "{ initialiser_list }"); }  
            | LEFT_CURLY_BRACE initialiser_list COMMA RIGHT_CURLY_BRACE
                { printInfo("initialiser", "{ initialiser_list , }"); }
            ;

initialiser_list:
                    designation_opt initialiser
                        { printInfo("initialiser_list", "designation_opt initialiser"); }
                    | initialiser_list COMMA designation_opt initialiser
                        { printInfo("initialiser_list", "initialiser_list , designation_opt initialiser"); }

designation_opt:
                    designation
                        { printInfo("designation_opt", "designation"); }
                    |
                        { printInfo("designation_opt", "Epsilon"); }
                    ;

designation:
                    designator_list ASSIGNMENT
                        { printInfo("designation", "designator_list ="); }
                    ;

designator_list:
                    designator
                        { printInfo("designator_list", "designator"); }
                    | designator_list designator
                        { printInfo("designator_list", "designator_list designator"); }
                    ;

designator:
                    LEFT_SQUARE_BRACE constant_expression RIGHT_SQUARE_BRACE
                        { printInfo("designator", "[ constant_expression ]"); }
                    | DOT IDENTIFIER
                        { printInfo("designator", ". IDENTIFIER"); }   
                    ;

/* STATEMENTS */
statement:
                    labeled_statement
                        { printInfo("statement", "labeled_statement"); }
                    | compound_statement
                        { printInfo("statement", "compound_statement"); $$ = $1; }
                    | expression_statement { 
                            printInfo("statement", "expression_statement"); 
                            $$ = new Statement(); $$->nextList = $1->nextList;
                        }
                    | selection_statement
                        { printInfo("statement", "selection_statement"); $$ = $1; }
                    | iteration_statement
                        { printInfo("statement", "iteration_statement"); $$ = $1; }
                    | jump_statement
                        { printInfo("statement", "jump_statement"); $$ = $1; }
                    ;

labeled_statement:
                    IDENTIFIER COLON statement
                        { printInfo("labeled_statement", "IDENTIFIER : statement"); }
                    | CASE constant_expression COLON statement
                        { printInfo("labeled_statement", "case constant_expression : statement"); }    
                    | DEFAULT COLON statement
                        { printInfo("labeled_statement", "default : statement"); }
                    ;

/*
Change the symbol table when a new block is activated
Create hierarchy of symbol tables
*/

/* change_block:       {
                        string name = currentST->name + "_" + toString(tableCount);
                        tableCount++;
                        Symbol *s = currentST->lookup(name); // create new entry in symbol table
                        s->nestedTable = new SymbolTable(name, currentST);
                        s->type = new SymbolType(SymbolType::BLOCK);
                        currentSymbol = s;
                    } 
                ; */

compound_statement:
                    LEFT_CURLY_BRACE   block_item_list_opt RIGHT_CURLY_BRACE { 
                            printInfo("compound_statement", "{ block_item_list_opt }"); 
                            $$ = $2;
                           // changeTable(currentST->parent); // block over, move back to the parent table
                        }
                    ;

block_item_list_opt:
                    block_item_list
                        { printInfo("block_item_list_opt", "block_item_list"); $$ = $1; }
                    |   { printInfo("block_item_list_opt", "epsilon"); $$ = new Statement(); }
                    ;

block_item_list:
                    block_item
                        { printInfo("block_item_list", "block_item"); $$ = $1; }
                    | block_item_list M block_item { 
                            printInfo("block_item_list", "block_item_list block_item"); 
                            $$ = $3;
                            // after completion of block_item_list(1) we move to block_item(3)
                            backpatch($1->nextList, $2); }
                    ;

block_item:
                    declaration
                        { printInfo("block_item", "declaration"); $$ = new Statement(); }
                    | statement
                        { printInfo("block_item", "statement"); $$ = $1; }
                    ;

expression_statement:
                    expression_opt SEMI_COLON
                        { printInfo("expression_statement", "expression_opt ;");  $$ = $1; }
                    ;

expression_opt:
                    expression
                        { printInfo("expression_opt", "expression"); $$ = $1; }
                    |
                        { printInfo("expression_opt", "epsilon"); $$ = new Expression(); }
                    ;

selection_statement:
                    IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement N %prec THEN { 
                            printInfo("selection_statement", "if ( expression ) statement"); 
                            $$ = new Statement(); $3->toBool();
                            backpatch($3->trueList, $5); // if true go to M
                            $$->nextList = merge($3->falseList, merge($6->nextList, $7->nextList)); // exits
                        }
                    | IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement N ELSE M statement { 
                            printInfo("selection_statement", "if ( expression ) statement else statement"); 
                            $$ = new Statement(); $3->toBool();
                            backpatch($3->trueList, $5); // if true go to M
                            backpatch($3->falseList, $9); // if false go to else
                            $$->nextList = merge($10->nextList, merge($6->nextList, $7->nextList)); // exits
                        }
                    | SWITCH LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement { 
                            printInfo("selection_statement", "switch ( expression ) statement"); 
                        }
                    ;

iteration_statement:
                    WHILE M LEFT_PARENTHESIS expression RIGHT_PARENTHESIS M statement { 
                            printInfo("iteration_statement", "while ( expression ) statement"); 
                            $$ = new Statement(); $4->toBool();
                            backpatch($7->nextList, $2); // after statement go back to M1
                            backpatch($4->trueList, $6); // if true go to M2
                            $$->nextList = $4->falseList; // exit if false
                            QuadArray::emit("goto", toString($2));
                        }
                    | DO M statement M WHILE LEFT_PARENTHESIS expression RIGHT_PARENTHESIS SEMI_COLON { 
                            printInfo("iteration_statement", "do statement while ( expression ) ;"); 
                            $$ = new Statement(); $7->toBool();
                            backpatch($7->trueList, $2); // if true go back to M1
                            backpatch($3->nextList, $4); // after statement is executed go to M2
                            $$->nextList = $7->falseList; // exit if false
                        }
                    | FOR LEFT_PARENTHESIS expression_opt SEMI_COLON M expression_opt SEMI_COLON M expression_opt N RIGHT_PARENTHESIS M statement { 
                            printInfo("iteration_statement", "for ( expression_opt ; expression_opt ; expression_opt ) statement"); 
                            $$ = new Statement(); $6->toBool();
                            backpatch($6->trueList, $12); // if true go to M3 (loop body)
                            backpatch($10->nextList, $5); // after N go to M1 (condition check)
                            backpatch($13->nextList, $8); // after S1 (loop body) go to M2 (increment/decrement/any other operation)
                            QuadArray::emit("goto", toString($8));
                            $$->nextList = $6->falseList; // exit if false
                        }
                    | FOR LEFT_PARENTHESIS declaration expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESIS statement
                        { printInfo("iteration_statement", "for ( declaration expression_opt ; expression_opt ) statement"); }
                    ;

jump_statement:
                    GOTO IDENTIFIER SEMI_COLON
                        { printInfo("jump_statement", "goto IDENTIFIER ;"); }    
                    | CONTINUE SEMI_COLON
                        { printInfo("jump_statement", "continue ;"); }
                    | BREAK SEMI_COLON
                        { printInfo("jump_statement", "break ;"); }
                    | RETURN expression_opt SEMI_COLON { 
                            printInfo("jump_statement", "return expression_opt ;"); 
                            $$ = new Statement();
                            if($2->symbol != NULL) {
                                QuadArray::emit("return", $2->symbol->name); // QuadArray::emit the current symbol name at return if it exists otherwise empty
                            } else {
                                QuadArray::emit("return", "");
                            }
                        }
                    ;

/* EXTERNAL DEFINITIONS */

translation_unit:
                    external_declaration
                        { printInfo("translation_unit", "external_declaration"); }
                    | translation_unit external_declaration
                        { printInfo("translation_unit", "translation_unit external_declaration"); }
                    ;

external_declaration:
                    function_definition
                        { printInfo("external_declaration", "function_definition"); }
                    | declaration
                        { printInfo("external_declaration", "declaration"); }
                    ;

function_definition: // to avoid block change according to the compound statement grammar rule
                     // **slightly modified
                    declaration_specifiers declarator declaration_list_opt change_scope LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE { 
                            printInfo("function_definition", "declaration_specifiers declarator declaration_list_opt compound_statement"); 
                            tableCount = 0;
                            QuadArray::emit("labelend", $2->name);
                            if($2->type->type != SymbolType::VOID) {
                                // set type of return value
                                currentST->lookup("return")->update($2->type);
                            }
                           // $2->type=new SymbolType(SymbolType::typeEnum::FUNCTION);
                            changeTable(globalST);
                        }
                    ;

declaration_list_opt:
                    declaration_list
                        { printInfo("declaration_list_opt", "declaration_list"); }
                    |
                        { printInfo("declaration_list_opt", "Epsilon"); }
                    ;

declaration_list:
                    declaration
                        { printInfo("declaration_list", "declaration"); }
                    | declaration_list declaration
                        { printInfo("declaration_list", "declaration_list declaration"); }
                    ;

%%

void yyerror(string s) {
    printf("ERROR [Line %d] : %s\n", yylineno, s.c_str());
}

void printInfo(string s1, string s2) {
    #ifdef _DEBUG
        printf("[Line %d] : %s => %s\n", yylineno, s1.c_str(), s2.c_str());
    #endif
}