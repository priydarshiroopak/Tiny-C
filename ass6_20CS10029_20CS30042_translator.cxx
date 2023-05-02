#include "ass6_20CS10029_20CS30042_translator.h"

//Global variables
Symbol *currentSymbol;  // currently matched symbol
SymbolTable *currentST, *globalST;  // pointer to current and global symbol tables 
QuadArray quadArray;    // quadArray to store Three Address code
SymbolType::typeEnum currentType;   // current type
int tableCount, tempCount;      // symbol table and temporary variable count 
vector<string> stringLiterals;

// Implementation of activation record class
ActivationRecord::ActivationRecord() : totalDisplacement(0), displacement(map<string, int>()) {}  // start with an initial displacement of 0


// Symbol Table constructor
SymbolTable::SymbolTable(string name, SymbolTable *parent){

    this->name = name;
    this->parent = parent;
}




// generate  new temporary and insert in currentST
Symbol* SymbolTable::gentemp(SymbolType::typeEnum typ, string initVal){
    // Create the name for the temporary
    string name = "t" + toString(tempCount++);

    Symbol *sym = new Symbol(name, typ, initVal);

    sym->category = Symbol::TEMPORARY; // **********************

    // Add the temporary to the symbol table
    currentST->symbols.insert({sym->name, *sym});
    return sym;
}






// Update the symbol table and all its children
void SymbolTable::update()
{
    vector<SymbolTable *> childTables; // vector to keep track of children tables to visit
    int offset=0;
    for (auto &sym : (this)->symbols)  
    {
        //update this symbol's offset
        if (sym.first == (this->symbols).begin()->first)  // if the symbol is the first one in the table then set offset of it to 0
        {
            sym.second.offset = 0;
            offset = sym.second.size;
        }
        else    // else update the offset of the symbol and update the offset by adding the symbols width
        {
            sym.second.offset = offset;
            offset += sym.second.size;

            // if((sym.second.size==0)&&(sym.second.type->type==SymbolType::FUNCTION)){
            //     auto cursym = currentST->symbols.find(currentSymbol->name);
            //     Symbol ss("dummy");
            //     if(cursym!=currentST->symbols.end()){
            //         auto cur2 = cursym->second.nestedTable->symbols.find("return");
            //         if(cur2!=cursym->second.nestedTable->symbols.end()){
            //             ss=cur2->second;

            //         }
            //     }
            //     offset+=ss.size;
            // }
            // else{
            //     offset += sym.second.size;
            // }
        }


        
        if (sym.second.nestedTable)  // put in  children table
        {
            childTables.push_back(sym.second.nestedTable);
        }
    }

    // now prepare activation record for the current table

    activationRecord = new ActivationRecord();

    // first stack the parameters
    for (auto sym : (this)->symbols)
    {
        if (sym.second.category == Symbol::PARAMETER)
        {
            if(sym.second.size != 0)
            {
                activationRecord->totalDisplacement -= sym.second.size;
                activationRecord->displacement[sym.second.name] = activationRecord->totalDisplacement;
            }
        }
    }
    // now stack the local variables and the temporaries
    for (auto sym : (this)->symbols)
    {
        if ((sym.second.category == Symbol::LOCAL && sym.second.name != "return") || sym.second.category == Symbol::TEMPORARY)
        {
            if(sym.second.size != 0)
            {
                activationRecord->totalDisplacement -= sym.second.size;
                activationRecord->displacement[sym.second.name] = activationRecord->totalDisplacement;
            }
        }
    }


    for (auto &table : childTables)  // update all children table
    {
        table->update();
    }
    return;
}

Symbol *SymbolTable::lookup(string name)
{

    // If the symbol is present in the current table, return it
    auto itr = (this)->symbols.find(name);
    if (itr != (this)->symbols.end())
        return &(itr->second);
    
    // If not then check the parent table
    Symbol *sym = NULL;
    if (this->parent != NULL)
        sym = this->parent->lookup(name);

    // else if this table is current table and symbol not found in parent
    if (this == currentST && !sym)
    {
        sym = new Symbol(name);
        sym->category = Symbol::LOCAL;
        if(currentST == globalST)
            sym->category = Symbol::GLOBAL;
        this->symbols.insert({name, *sym});
        return &((this)->symbols.find(name)->second);
    }
    return sym;
}

// Function to print the symbol table(s)
void SymbolTable::print()
{ 
    cout << "Table Name: " << this->name <<"\t\t Parent Name: "<< ((this->parent)?this->parent->name:"None") << endl;
    cout << string(125, '~') << endl;
    cout << setw(20) << "Name" << setw(35) << "Type" << setw(20)<< "Category" << setw(20) << "Initial Value" << setw(15) << "Offset" << setw(15) << "Size" << setw(20) << "Child"  << endl;
    cout << string(125, '=') << endl;
    vector<SymbolTable *> childTables;
    // print all the entries in the table
    for (auto &sym : (this)->symbols)
    {
        cout << setw(20) << sym.first;
        fflush(stdout);
// **********************
        cout << setw(40) << sym.second.type->toString();
        cout << setw(20);
        if(sym.second.category == Symbol::LOCAL)
            cout << "local";
        else if(sym.second.category == Symbol::GLOBAL)
            cout << "global";
        else if(sym.second.category == Symbol::FUNCTION)
            cout << "function";
        else if(sym.second.category == Symbol::PARAMETER)
            cout << "parameter";
        else if(sym.second.category == Symbol::TEMPORARY)
            cout << "temporary";
// ********************
        cout << setw(20) << sym.second.initialValue << setw(15) << sym.second.offset << setw(15) << sym.second.size;
        cout << setw(20) << (sym.second.nestedTable ? sym.second.nestedTable->name : "NULL") << endl;
        // to store nested tables to be printed later
        if (sym.second.nestedTable) childTables.push_back(sym.second.nestedTable);
    }
    cout << string(125, '-') << endl;
    cout << "\n" << endl;
    // print nested tables
    for (auto &table : childTables) table->print();
}

//constructor of symbol type
Symbol::Symbol(string name, SymbolType::typeEnum type, string init)
{
    this->name = name;
    this->type =  new SymbolType(type);
    this->offset = 0;
    this->nestedTable = NULL;
    this->initialValue = init;    
    size = this->type->getSize();
}

// update the symbol type
Symbol *Symbol::update(SymbolType *typ)
{
    this->type = typ;
    this->size = this->type->getSize();
    return this;
}




// convert function for symbol class
Symbol *Symbol::convert(SymbolType::typeEnum newTyp){
    SymbolType::typeEnum currTyp = this->type->type, _int=SymbolType::typeEnum::INT;
    SymbolType::typeEnum _char = SymbolType::typeEnum::CHAR, _float = SymbolType::typeEnum::FLOAT;

    // convert only allowed to and from int, float and char
    if(currTyp==_int || currTyp==_char || currTyp==_float){ 
        if(newTyp==_int || newTyp==_char|| newTyp==_float){
            if(currTyp!=newTyp){    // don't convert if new type same as old type
                Symbol *sym = SymbolTable::gentemp(newTyp);
                QuadArray::emit("=", sym->name, this->type->toString()+"_TO_"+sym->type->toString()+"(" + this->name + ")");
                return sym;

            }
        }
    }
    return this;
}




 SymbolType::SymbolType(typeEnum type, SymbolType *arrayType, int arraySize){ // constructor for  elements
    this->type=type;
    this->arrayType=arrayType; 
    this->arraySize=arraySize;
 }

// Implementation of sizes for symbol types
int SymbolType::getSize()
{
    if (type == CHAR)
        return CHAR_SIZE;
    else if (type == INT)
        return INT_SIZE;
    else if (type == FLOAT)
        return FLOAT_SIZE;
    else if(type == POINTER)
        return POINTER_SIZE;
    else if(type == FUNCTION)
        return FUNCTION_SIZE;
    else if (type == ARRAY)
        return arraySize * (arrayType->getSize());
    else
        return VOID_SIZE;
}


// Function to print symbol type
string SymbolType::toString()
{
    if(this->type == SymbolType::CHAR)
        return "char";
    else if(this->type == SymbolType::INT)
        return "int";
    else if(this->type == SymbolType::FLOAT)
        return "float";
    else if(this->type == SymbolType::POINTER)
        return "ptr(" + this->arrayType->toString() + ")";
    else if(this->type == SymbolType::FUNCTION)
        return "function";
    else if(this->type == SymbolType::ARRAY)
        return "array(" + to_string(this->arraySize) + ", " + this->arrayType->toString() + ")";
    else if(this->type ==  SymbolType::BLOCK)
        return "block";
    
    return "void";
}


// convert typeEnum defined in SymbolTable scope to string
string toString(SymbolType::typeEnum type)
{
    
    if(type == SymbolType::CHAR)
        return "char";
    else if(type == SymbolType::INT)
        return "int";
    else if(type == SymbolType::FLOAT)
        return "float";
    else if(type == SymbolType::FUNCTION)
        return "function";
    else if(type ==  SymbolType::BLOCK)
        return "block";
    return "void";
}



// emit function to generate the Three Address Code
void QuadArray::emit(string op, string result, string arg1, string arg2){

    Quad *q = new Quad(result, arg1, op, arg2);
    quadArray.arr.push_back(q);
}
// overloaded emit incase arg1 is passed as int
void QuadArray::emit(string op, string result, int arg1, string arg2){
     QuadArray::emit(op, result, toString(arg1), arg2);    
}


// Quad class ( elements of QuadArray)
Quad::Quad(string result, string arg1, string op, string arg2) {
    this->result=result;
    this->op=op;
    this->arg1=arg1;
    this->arg2=arg2;
}

Quad::Quad(string result, int arg1, string op, string arg2) {
    this->result=result;
    this->op=op;
    this->arg1=toString(arg1);
    this->arg2=arg2;
}


// Function to print Quad
void Quad::print()
{
    // Binary operations
    auto binary_print = [this]() { cout << "\t" << this->result << " = " << this->arg1 << " " << this->op << " " << this->arg2 << endl; };
    // Relational operators
    auto relation_print = [this]() { cout << "\tif " << this->arg1 << " " << this->op << " " << this->arg2 << " goto " << this->result << endl; };
    // Shift operators
    auto shift_print = [this]() { cout << "\t" << this->result << " " << this->op[0] << " " << this->op[1] << this->arg1 << endl; };
    // Special type of operators
    auto shift_print_ = [this](string tp) { cout << "\t" << this->result << " " << tp << " " << this->arg1 << endl; };

    //Printing Format 
    if (this->op == "=") { cout << "\t" << this->result << " = " << this->arg1 << endl; }
    else if (this->op == "goto") { cout << "\tgoto " << this->result << endl; }
    else if (this->op == "return") { cout << "\treturn " << this->result << endl; }
    else if (this->op == "call") { cout << "\t" << this->result << " = call " << this->arg1 << ", " << this->arg2 << endl; }
    else if (this->op == "param") { cout << "\t" << "param " << this->result << endl; }
    else if (this->op == "label") { cout << "Function start: " << this->result << endl; }
    else if (this->op == "labelend"){ cout << "Function end: " << this->result << endl;}
    else if (this->op == "=[]") { cout << "\t" << this->result << " = " << this->arg1 << "[" << this->arg2 << "]" << endl; }
    else if (this->op == "[]=") { cout << "\t" << this->result << "[" << this->arg1 << "] = " << this->arg2 << endl; }
    else if (this->op == "+" or this->op == "-" or this->op == "*" or this->op == "/" or this->op == "%" or this->op == "|" or this->op == "^" or this->op == "&" or this->op == "<<" or this->op == ">>") { binary_print(); }
    else if (this->op == "==" or this->op == "!=" or this->op == "<" or this->op == ">" or this->op == "<=" or this->op == ">=") { relation_print(); }
    else if (this->op == "=&" or this->op == "=*") { shift_print(); }
    else if(this->op == "*=") { cout << "\t" << "*" << this->result << " = " << this->arg1 << endl; }
    else if (this->op == "=-") { shift_print_("= -"); }
    else if (this->op == "~") { shift_print_("= ~"); }
    else if (this->op == "!") { shift_print_("= !"); }
    else if (this->op == "=str") {
        cout << "\t" << this->result << " = " << stringLiterals[atoi(this->arg1.c_str())] << endl;
    }
    else { 
        cout << this->op << this->arg1 << this->arg2 << this->result << endl;
        cout << "INVALID OPERATOR\n";
    }
}

// Expression class
void Expression::toInt()
{
    // if the expression type is boolean 
    if (this->isBoolean )
    {
        // generate symbol of new type and do backpatching and other required operations
        this->symbol = SymbolTable::gentemp(SymbolType::typeEnum::INT);
        backpatch(this->trueList, static_cast<int>(quadArray.arr.size()+1)); // update the true list
        QuadArray::emit("=", this->symbol->name, "true");                        // emit the quad
        QuadArray::emit("goto", toString(static_cast<int>(quadArray.arr.size() + 2)));  // emit the goto quad
        backpatch(this->falseList, static_cast<int>(quadArray.arr.size()+1));  // update the false list
        QuadArray::emit("=", this->symbol->name, "false");
    }
}

void Expression::toBool()
{
    // if the expression type is non-boolean
    if (!this->isBoolean)
    {
        // generate symbol of new type and do backpatching and other required operations
        this->falseList = makeList(static_cast<int>(quadArray.arr.size()+1)); // update the falselist
        QuadArray::emit("==", "", this->symbol->name, "0");                        // emit general goto statements
        this->trueList = makeList(static_cast<int>(quadArray.arr.size()+1));  // update the truelist
        QuadArray::emit("goto", "");
    }
}

// Helper functions


int nextInstruction(){
    // returns the next instruction number
    return quadArray.arr.size() + 1;
}


// change current table to specified table
void changeTable(SymbolTable *table){
    currentST = table;
}

// code to check if a and b are of the same type, promotes to the higher type if feasible and if that makes the type of both the same
bool typeCheck(Symbol *&a, Symbol *&b)
{
    // lambda function to check if a and b are of the same type 
    std::function<bool(SymbolType *, SymbolType *)> type_comp = [&](SymbolType *first, SymbolType *second) -> bool
    {
        if (!first and !second)
            return true;
        else if (!first or !second or first->type != second->type)
            return false;
        else
            return type_comp(first->arrayType, second->arrayType);
    };
    // if the types are same return true
    if(type_comp(a->type, b->type))
        return true;
    // if the types are not same but can be cast safely according the rules, then cast and return
    else if(a->type->type == SymbolType::FLOAT or b->type->type == SymbolType::FLOAT) {
        a = a->convert(SymbolType::FLOAT);
        b = b->convert(SymbolType::FLOAT);
        return true;
    }
    else if(a->type->type == SymbolType::INT or b->type->type == SymbolType::INT) {
        a = a->convert(SymbolType::INT);
        b = b->convert(SymbolType::INT);
        return true;
    }
    // return false if not possible to cast safelt to same type
    else {
        return false;
    }
}
// Implementation of utility functions
// overloaded toString function to maintain semantic consistency 
// convert int to string
string toString(int i)
{
    return to_string(i);
}
// converts float to string
string toString(float f)
{
    return to_string(f);
}
// converts char to string
string toString(char c)
{
    return string(1, c);
}
void backpatch(vector<int> list_, int addr)
{
    // for all the addresses in the list, add the target address 
    for (auto &i : list_){
        quadArray.arr[i-1]->result = toString(addr);
    }
}

void finalBackpatch()
{
    // any dangling exits for void type functions are sent to function end
    int curPos = quadArray.arr.size();
    int lastExit = -1;
    for(auto it = quadArray.arr.rbegin(); it != quadArray.arr.rend(); it++) {
        string op = (*it)->op;
        if(op == "labelend") 
        {
            lastExit = curPos;
        } 
        else if(op == "goto" or op == "==" or op == "!=" or op == "<" or op == ">" or op == "<=" or op == ">=") {
            if((*it)->result.empty()) 
            {
                (*it)->result = toString(lastExit);
            }
        }
        curPos--;
    }
}

vector<int> makeList(int base)
{
    // returns list with the base address as its only value
    return {base};
}

vector<int> merge(vector<int> first, vector<int> second){
    // merge two lists
    vector<int> ret = first;
    ret.insert(ret.end(), second.begin(), second.end());
    return ret;
}
/*
int main(){
    //Iinitialization of global variables
    globalST = new SymbolTable("global");
    currentST = globalST;
    tableCount = 0;
    tempCount = 0;
 
    yyparse();
    globalST->update();
    globalST->print();

    // print All Three Address
    int instr = 1;
    for(auto tac : quadArray.arr) {
        cout<<setw(5)<<instr++<<": "; tac->print();
    }
    return 0;
}



*/












