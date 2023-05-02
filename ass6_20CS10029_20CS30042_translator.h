#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <map> 
#include <vector>
#include <functional>
#include <fstream>
#include <stack>


using namespace std;

// SIze of data types
#define VOID_SIZE 0
#define FUNCTION_SIZE 0
#define CHAR_SIZE 1
#define INT_SIZE 4
#define POINTER_SIZE 8
#define FLOAT_SIZE 8
#define False 0
#define True 1

// All classes
class SymbolTable;
class Symbol;
class SymbolType;
class Label;
class Quad;
class Expression;
class Array;
class Statement;
class ActivationRecord;

// AR class, used to store important information such as displacements of symbols, total displacement from base pointer, 
class ActivationRecord {//************************
    public:
        map<string, int> displacement;
        int totalDisplacement;

        ActivationRecord();
};
// Symbol type class 
class SymbolType {
    public:
        enum typeEnum {VOID, CHAR, INT, FLOAT, POINTER, FUNCTION, ARRAY, BLOCK} type;  // type of the symbol, scoped enum for safe comparisons
        SymbolType *arrayType;  // type of the array elements also stores type of pointer
        int arraySize;   // size of the array


        
        SymbolType(typeEnum, SymbolType * = NULL, int = 1);  // constructor for array elements
        int getSize();  // returns the size(width) of the symbol
        string toString(); // returns the string representation of the type
};

class SymbolTable {
    public:
        string name;                    // name of the Table
        map<string, Symbol> symbols;    // list of all symbols in this table, mapped by their names for fast access
        SymbolTable *parent;            // parent symbol table of this symbol table
//******************
        ActivationRecord *activationRecord;           // activation record of this symbol table
        vector<string> parameters;    // list of parameters of the function, if any, in order
                
        SymbolTable(string = "Name", SymbolTable * = NULL); // constructor
        Symbol *lookup(string); // returns the symbol with the given name, adds new entry if not found
        static Symbol* gentemp(SymbolType::typeEnum, string= ""); //generates a new temporary, insert it to the symbol table, and return a pointer to it
        void print();  // prints the symbol table
        void update(); // updates the symbol table
};





// Symbol class 
class Symbol {
    public:
        string name;    // name of the symbol
        int size, offset; // size, offset of the symbol
        SymbolType *type;  // type of the symbol
        string initialValue;  // initial value of the symbol
        SymbolTable *nestedTable;  // incase the symbol starts new scope


        Symbol(string, SymbolType::typeEnum = SymbolType::INT, string = "");  // constructor
        Symbol *update(SymbolType *);  // Updates the type of the symbol
        Symbol *convert(SymbolType::typeEnum);  // Converts the type of the symbol
        enum Category {LOCAL, GLOBAL, PARAMETER, TEMPORARY, FUNCTION} category;
        //********************
};


// Quad array class which stores our Three Address code
class QuadArray {
public:
    vector<Quad*> arr;
    
    static void emit(string, string, string="", string="");
    static void emit(string, string, int, string="");
    void print();
};


// Quad class ( represents a 3-address quad )
class Quad {
    public:
        string result, arg1, op, arg2 ;  // parameters of the quad

        Quad(string, string, string, string = "");  // constructor
        Quad(string, int, string = "=", string = ""); 
        void print();  // prints the quad
};



// Expression attributes
class Expression {
    public:
        Symbol *symbol;  // symbol of the expression
        bool isBoolean;  // True if it is a boolean expression
        vector<int> trueList, falseList, nextList;  // important lists for backpatching and other things  

        void toInt();  // converts the expression to an integer
        void toBool();  // converts the expression to a boolean
};

// Array attributes
class Array {
    public:
        Symbol *temp;   
        enum typeEnum {OTHER, POINTER, ARRAY} type;    
        Symbol *symbol;  // pointer to the symbol table entry
        SymbolType *subArrayType;   
};

// Statement
class Statement {
    public:
        vector<int> nextList;     // List of quads 
};


void backpatch(vector<int>, int);  // backpatches the list of quads with the given address
void finalBackpatch();
vector<int> makeList(int);  // makes a new list with the given number
vector<int> merge(vector<int>, vector<int>); // merges the two lists


// Other helper functions
int nextInstruction();  // returns the next instruction number

void changeTable(SymbolTable *);  // changes the current symbol table

// Type checking and conversions
bool typeCheck(Symbol *&, Symbol *&);  // checks if the two symbols have the same type

// Utility functions
string toString(int);  
string toString(float);  
string toString(char);  

// // Global variables
extern QuadArray quadArray; // array of quads
extern SymbolTable *currentST, *globalST; // current and global symbol tables
extern Symbol *currentSymbol;  // current symbol
extern SymbolType::typeEnum currentType;  // current type
extern int tableCount, tempCount; // counters for symbol table and temporary symbols
extern vector<string> stringLiterals;
extern FILE *yyin;

// extern 
int yyparse();


