#include "ass6_20CS10029_20CS30042_translator.h"


ActivationRecord *currActivRcd; // points to the activation record of the current function



map<char, int> AsciiValuesForEscChar = { {'n', 10}, {'t', 9}, {'r', 13}, {'b', 8}, {'f', 12}, {'v', 11}, {'a', 7}, {'0', 0}};


int getAsciiValue(string charConst) {
    if(charConst.length() == 3) {
        return (int)charConst[1];
    }
    else {
        // escaped character
        if(AsciiValuesForEscChar.find(charConst[2]) != AsciiValuesForEscChar.end()) {
            return AsciiValuesForEscChar[charConst[2]];
        }
        else {
            return (int)charConst[2];
        }
    }
}


map<int, string> retRegSize = { {1, "al"}, {4, "eax"}, {8, "rax"} };
map<int, string> arg1RegSize = { {1, "dil"}, {4, "edi"}, {8, "rdi"} };
map<int, string> arg2RegSize = { {1, "sil"}, {4, "esi"}, {8, "rsi"} };
map<int, string> arg3RegSize = { {1, "dl"}, {4, "edx"}, {8, "rdx"} };
map<int, string> arg4RegSize = { {1, "cl"}, {4, "ecx"}, {8, "rcx"} };
map<int, map<int, string>> argNum2RegMap = { {1, arg1RegSize}, {2, arg2RegSize}, {3, arg3RegSize}, {4, arg4RegSize} };



string getReg(string paramName, int paramNum, int size) {
    string reg = argNum2RegMap[paramNum][size];
    return "%" + reg;
}

string getStackLoc(string paramName) {
    if(currActivRcd->displacement.count(paramName))
        return toString(currActivRcd->displacement[paramName]) + "(%rbp)";
    else // global variable
        return paramName;
}


ofstream asmFile; // assembly file
// register to stack
void loadParam(string paramName, int paramNum) {
    Symbol *symbol = currentST->lookup(paramName);
    int size = symbol->size;

    SymbolType::typeEnum type = symbol->type->type;

    string movIns = "";
    // if it is an array just store the address
    if(type == SymbolType::ARRAY) {
        movIns = "movq";
        size = 8;
    } else if (size == 1) {
        movIns = "movb";
    } else if (size == 4) {
        movIns = "movl";
    } else if (size == 8) {
        movIns = "movq";
    }
    string reg = getReg(paramName, paramNum, size);
    asmFile << "\t" << setw(8) << movIns << reg << ", " << getStackLoc(paramName) << endl;
}

// stack to register
void storeParam(string paramName, int paramNum) {
    Symbol *symbol = currentST->lookup(paramName);
    int size = symbol->size;
    SymbolType::typeEnum type = symbol->type->type;

    string movIns = "";
    // if it is an array just store the address
    if(type == SymbolType::ARRAY) {
        movIns = "leaq";
        size = 8;
    } else if (size == 1) {
        movIns = "movb";
    } else if (size == 4) {
        movIns = "movl";
    } else if (size == 8) {
        movIns = "movq";
    }
    string reg = getReg(paramName, paramNum, size);
    asmFile << "\t" << setw(8) << movIns << getStackLoc(paramName) << ", " << reg << endl;
}


string inputFileName, asmFileName;

void translate() {
    asmFile.open(asmFileName);

    asmFile << left;
    asmFile << "\t.file\t\"" + inputFileName + "\"" << endl;

    asmFile << endl;
    // activation records
    asmFile << "#\t" << "Allocation of function variables and temporaries on the stack:\n" << endl;
    for(auto &symbol : globalST->symbols) {
        if(symbol.second.category == Symbol::FUNCTION) {
            asmFile << "#\t" << symbol.second.name << endl;
            for(auto &record: symbol.second.nestedTable->activationRecord->displacement) {
                asmFile << "#\t" << record.first << ": " << record.second << endl;
            }
        }
    }
    asmFile << endl;

    // string literals in the rodata section
    if(stringLiterals.size() > 0) {
        asmFile << "\t.section\t.rodata" << endl;
        int i = 0;
        for(auto &stringLiteral : stringLiterals) {
            asmFile << ".LC" << i++ << ":" << endl;
            asmFile << "\t.string\t" << stringLiteral << endl;
        }
    }

    // global variables (uninitialised)
    for(auto &symbol:globalST->symbols) {
        if(symbol.second.initialValue.empty() && symbol.second.category == Symbol::GLOBAL) {
            asmFile << "\t.comm\t" << symbol.first << "," << symbol.second.size << "," << symbol.second.size << endl;
        }
    }

    // convert tac labels to assembly labels
    map<int, string> labelMap;
    int quadNum = 1, labelNum = 0;
    for(auto &quad:quadArray.arr) {
        if(quad->op == "label") {
            labelMap[quadNum] = ".LFB" + toString(labelNum);
        } else if(quad->op == "labelend") {
            labelMap[quadNum] = ".LFE" + toString(labelNum);
            labelNum++;
        }
        quadNum++;
    }
    for(auto &quad:quadArray.arr) {
        if(quad->op == "goto" or quad->op == "==" or quad->op == "!=" or quad->op == "<" or quad->op == ">" or quad->op == "<=" or quad->op == ">=") {
            int loc = stoi(quad->result);
            if(labelMap.find(loc) == labelMap.end()) {
                labelMap[loc] = ".L" + toString(labelNum);
                labelNum++;
            }
        }
    }


    bool inTextSpace = false; // whether we are currently inside a function body or in the global space
    string globalStringTemp;
    int globalIntTemp, globalCharTemp; // for char simply hold the ascii value
    string functionEndLabel;
    stack<string> params; // stack to store the params for function calls, especially helpful for nested function calls
                            // of the type fun1(fun2(arg1, arg2), fun3(arg3, arg4))
    quadNum = 1;
    for(auto &quad:quadArray.arr) {

        if(quad->op == "label") {
            if(!inTextSpace) {
                asmFile << "\t.text" << endl;
                inTextSpace = true;
            }

            currentST = globalST->lookup(quad->result)->nestedTable;
            currActivRcd = currentST->activationRecord;
            
            functionEndLabel = labelMap[quadNum];
            functionEndLabel[3] = 'E';

            // function prologue
            asmFile << "\t" << setw(8) << ".globl" << quad->result << endl;
            asmFile << "\t" << setw(8) << ".type" << quad->result << ", @function" << endl;
            asmFile << quad->result << ":" << endl;
            asmFile << labelMap[quadNum] << ":" << endl;
            asmFile << "\t" << ".cfi_startproc" << endl;
            asmFile << "\t" << setw(8) << "pushq" << "%rbp" << endl;
            asmFile << "\t.cfi_def_cfa_offset 16" << endl;
            asmFile << "\t.cfi_offset 6, -16" << endl;
            asmFile << "\t" << setw(8) << "movq" << "%rsp, %rbp" << endl;
            asmFile << "\t.cfi_def_cfa_register 6" << endl;
            asmFile << "\t" << setw(8) << "subq" << "$" << -currActivRcd->totalDisplacement << ", %rsp" << endl;

            int paramNum = 1;
            for(auto param:currentST->parameters) {
                loadParam(param, paramNum);
                paramNum++;
            }

        } else if(quad->op == "labelend") {
            // function epilogue
            asmFile << labelMap[quadNum] << ":" << endl;
            asmFile << "\t" << setw(8) << "movq" << "%rbp, %rsp" << endl;
            asmFile << "\t" << setw(8) << "popq" << "%rbp" << endl;
            asmFile << "\t" << ".cfi_def_cfa 7, 8" << endl;
            asmFile << "\t" << "ret" << endl;
            asmFile << "\t" << ".cfi_endproc" << endl;
            asmFile << "\t" << setw(8) << ".size" << quad->result << ", .-" << quad->result << endl;

            inTextSpace = false;

        } else {
            if(inTextSpace) {
                // process the function instructions
                string op = quad->op;
                string result = quad->result;
                string arg1 = quad->arg1;
                string arg2 = quad->arg2;

                if(labelMap.count(quadNum)) {
                    asmFile << labelMap[quadNum] << ":" << endl;
                }

                if(op == "=") {
                    // first check if arg1 is a constant
                    if(isdigit(arg1[0])) {
                        // integer constant
                        asmFile << "\t" << setw(8) << "movl" << "$" << arg1 << ", " << getStackLoc(result) << endl;
                    } else if(arg1[0] == '\''){
                        // character constant
                        asmFile << "\t" << setw(8) << "movb" << "$" << getAsciiValue(arg1) << ", " << getStackLoc(result) << endl;
                    } else {
                        // variable
                        // check the size of arg1 in the current table and apply the corresponding move from arg1 to result via the appropriate register
                        int sz = currentST->lookup(arg1)->size;
                        if(sz == 1) {
                            asmFile << "\t" << setw(8) << "movb" << getStackLoc(arg1) << ", %al" << endl;
                            asmFile << "\t" << setw(8) << "movb" << "%al, " << getStackLoc(result) << endl;
                        } else if(sz == 4) {
                            asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", %eax" << endl;
                            asmFile << "\t" << setw(8) << "movl" << "%eax, " << getStackLoc(result) << endl;
                        } else if(sz == 8) {
                            asmFile << "\t" << setw(8) << "movq" << getStackLoc(arg1) << ", %rax" << endl;
                            asmFile << "\t" << setw(8) << "movq" << "%rax, " << getStackLoc(result) << endl;
                        }
                    }
                } else if(op == "=str") {
                    asmFile << "\t" << setw(8) << "movq" << "$.LC" << arg1 << ", " << getStackLoc(result) << endl;
                } else if(op == "param") {
                    params.push(result);
                } else if(op == "call") {
                    // call function
                    int paramCount = stoi(arg2);
                    while (paramCount) {
                        storeParam(params.top(), paramCount);
                        params.pop();
                        paramCount--;
                    }
                    
                    asmFile << "\t" << setw(8) << "call" << arg1 << endl;
                    // check the size of result in the current table and apply the corresponding move from appropriate return register to result
                    int sz = currentST->lookup(result)->size;
                    if(sz == 1) {
                        asmFile << "\t" << setw(8) << "movb" << "%al, " << getStackLoc(result) << endl;
                    } else if(sz == 4) {
                        asmFile << "\t" << setw(8) << "movl" << "%eax, " << getStackLoc(result) << endl;
                    } else if(sz == 8) {
                        asmFile << "\t" << setw(8) << "movq" << "%rax, " << getStackLoc(result) << endl;
                    }
                } else if(op == "return") {
                    // return from function
                    if(!result.empty()) {
                        // check the size of result in the current table and apply the corresponding move from result to return register
                        int sz = currentST->lookup(result)->size;
                        if(sz == 1) {
                            asmFile << "\t" << setw(8) << "movb" << getStackLoc(result) << ", %al" << endl;
                        } else if(sz == 4) {
                            asmFile << "\t" << setw(8) << "movl" << getStackLoc(result) << ", %eax" << endl;
                        } else if(sz == 8) {
                            asmFile << "\t" << setw(8) << "movq" << getStackLoc(result) << ", %rax" << endl;
                        }
                    }
                    if(quadArray.arr[quadNum]->op != "labelend") // if the next quad is not a labelend, then we need to jump to the function end
                        asmFile << "\t" << setw(8) << "jmp" << functionEndLabel << endl;
                } else if(op == "goto") {
                    // unconditional jump
                    asmFile << "\t" << setw(8) << "jmp" << labelMap[stoi(result)] << endl;
                } else if(op == "==" or op == "!=" or op == "<" or op == "<=" or op == ">" or op == ">=") {
                    // check if arg1 == arg2
                    int sz = currentST->lookup(arg1)->size;
                    string movins, cmpins, movreg;
                    if(sz == 1) {
                        movins = "movb";
                        cmpins = "cmpb";
                        movreg = "%al";
                    } else if(sz == 4) {
                        movins = "movl";
                        cmpins = "cmpl";
                        movreg = "%eax";
                    } else if(sz == 8) {
                        movins = "movq";
                        cmpins = "cmpq";
                        movreg = "%rax";
                    }
                    asmFile << "\t" << setw(8) << movins << getStackLoc(arg2) << ", " << movreg << endl;
                    asmFile << "\t" << setw(8) << cmpins << movreg << ", " << getStackLoc(arg1) << endl;
                    if(op == "==") {
                        asmFile << "\t" << setw(8) << "je" << labelMap[stoi(result)] << endl;
                    } else if(op == "!=") {
                        asmFile << "\t" << setw(8) << "jne" << labelMap[stoi(result)] << endl;
                    } else if(op == "<") {
                        asmFile << "\t" << setw(8) << "jl" << labelMap[stoi(result)] << endl;
                    } else if(op == "<=") {
                        asmFile << "\t" << setw(8) << "jle" << labelMap[stoi(result)] << endl;
                    } else if(op == ">") {
                        asmFile << "\t" << setw(8) << "jg" << labelMap[stoi(result)] << endl;
                    } else if(op == ">=") {
                        asmFile << "\t" << setw(8) << "jge" << labelMap[stoi(result)] << endl;
                    }
                } else if(op == "+") {
                    // result = arg1 + arg2
                    if(result == arg1) {
                        // increment arg1
                        asmFile << "\t" << setw(8) << "incl" << getStackLoc(arg1) << endl;
                    } else {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "addl" << getStackLoc(arg2) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                    }
                } else if(op == "-") {
                    // result = arg1 - arg2
                    if(result == arg1) {
                        // decrement arg1
                        asmFile << "\t" << setw(8) << "decl" << getStackLoc(arg1) << endl;
                    }
                    else {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "subl" << getStackLoc(arg2) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                    }
                } else if(op == "*") {
                    // result = arg1 * arg2
                    asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                    if(isdigit(arg2[0])) {
                        asmFile << "\t" << setw(8) << "imull" << "$" + getStackLoc(arg2) << ", " << "%eax" << endl;
                    } else { 
                        asmFile << "\t" << setw(8) << "imull" << getStackLoc(arg2) << ", " << "%eax" << endl;
                    }
                    asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                } else if(op == "/") {
                    // result = arg1  / arg2
                    asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "cdq" << endl;
                    asmFile << "\t" << setw(8) << "idivl" << getStackLoc(arg2) << endl;
                    asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                } else if(op == "%") {
                    // result = arg1 % arg2
                    asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "cdq" << endl;
                    asmFile << "\t" << setw(8) << "idivl" << getStackLoc(arg2) << endl;
                    asmFile << "\t" << setw(8) << "movl" << "%edx" << ", " << getStackLoc(result) << endl;
                } else if(op == "=[]") {
                    // result = arg1[arg2]
                    Symbol *symbol = currentST->lookup(arg1);
                    if(symbol->category == Symbol::PARAMETER) {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg2) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "cltq" << endl;
                        asmFile << "\t" << setw(8) << "addq" << getStackLoc(arg1) << ", " << "%rax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "(%rax)" << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                    } else {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg2) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "cltq" << endl;
                        asmFile << "\t" << setw(8) << "movl" << currActivRcd->displacement[arg1] << "(%rbp, %rax, 1)" << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                    }
                } else if(op == "[]=") {
                    // result[arg1] = arg2
                    Symbol *symbol = currentST->lookup(result);
                    if(symbol->category == Symbol::PARAMETER) {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "cltq" << endl;
                        asmFile << "\t" << setw(8) << "addq" << getStackLoc(result) << ", " << "%rax" << endl;
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg2) << ", " << "%ebx" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%ebx" << ", " << "(%rax)" << endl;
                    } else {
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                        asmFile << "\t" << setw(8) << "cltq" << endl;
                        asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg2) << ", " << "%ebx" << endl;
                        asmFile << "\t" << setw(8) << "movl" << "%ebx" << ", " << currActivRcd->displacement[result] << "(%rbp, %rax, 1)" << endl;
                    }
                } else if(op == "=&") {
                    // result = &arg1
                    asmFile << "\t" << setw(8) << "leaq" << getStackLoc(arg1) << ", " << "%rax" << endl;
                    asmFile << "\t" << setw(8) << "movq" << "%rax" << ", " << getStackLoc(result) << endl;
                } else if(op == "=*") {
                    // result = *arg1
                    asmFile << "\t" << setw(8) << "movq" << getStackLoc(arg1) << ", " << "%rax" << endl;
                    asmFile << "\t" << setw(8) << "movl" << "(%rax)" << ", " << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                } else if(op == "=-") {
                    // result = -arg1
                    asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "negl" << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << getStackLoc(result) << endl;
                } else if(op == "*=") {
                    // *result = arg1
                    asmFile << "\t" << setw(8) << "movl" << getStackLoc(arg1) << ", " << "%eax" << endl;
                    asmFile << "\t" << setw(8) << "movq" << getStackLoc(result) << ", " << "%rbx" << endl;
                    asmFile << "\t" << setw(8) << "movl" << "%eax" << ", " << "(%rbx)" << endl;
                }

            } else {
                // process the global assignments
                currentSymbol = globalST->lookup(quad->result);

                auto curtype = currentSymbol->type->type;


                // first store the assignment value, this removes the need of temporaries, sort of a peep hole optimisation
                if(currentSymbol->category == Symbol::TEMPORARY) {
                    if(curtype == SymbolType::INT) {
                        globalIntTemp = stoi(quad->arg1);
                    } else if(curtype == SymbolType::CHAR) {
                        globalCharTemp = getAsciiValue(quad->arg1);
                    } else if(curtype == SymbolType::POINTER) {
                        globalStringTemp = ".LC" + quad->arg1;
                    }
                } else {
                    if(curtype == SymbolType::INT) {
                        asmFile << "\t" << setw(8) << ".globl" << currentSymbol->name << endl;
                        asmFile << "\t" << setw(8) << ".data" << endl;
                        asmFile << "\t" << setw(8) << ".align" << 4 << endl;
                        asmFile << "\t" << setw(8) << ".type" << currentSymbol->name << ", @object" << endl;
                        asmFile << "\t" << setw(8) << ".size" << currentSymbol->name << ", 4" << endl;
                        asmFile << currentSymbol->name << ":" << endl;
                        asmFile << "\t" << setw(8) << ".long" << globalIntTemp << endl;
                    } else if(curtype == SymbolType::CHAR) {
                        asmFile << "\t" << setw(8) << ".globl" << currentSymbol->name << endl;
                        asmFile << "\t" << setw(8) << ".data" << endl;
                        asmFile << "\t" << setw(8) << ".type" << currentSymbol->name << ", @object" << endl;
                        asmFile << "\t" << setw(8) << ".size" << currentSymbol->name << ", 1" << endl;
                        asmFile << currentSymbol->name << ":" << endl;
                        asmFile << "\t" << setw(8) << ".byte" << globalCharTemp << endl;
                    } else if(curtype == SymbolType::POINTER) {
                        asmFile << "\t" << ".section	.data.rel.local" << endl;
                        asmFile << "\t" << setw(8) << ".align" << 8 << endl;
                        asmFile << "\t" << setw(8) << ".type" << currentSymbol->name << ", @object" << endl;
                        asmFile << "\t" << setw(8) << ".size" << currentSymbol->name << ", 8" << endl;
                        asmFile << currentSymbol->name << ":" << endl;
                        asmFile << "\t" << setw(8) << ".quad" << globalStringTemp << endl;
                    }
                }
            }
        }

        quadNum++;
    }


    asmFile.close();
}

int main(int argc, char const *argv[]) {
   
    inputFileName = string(argv[1]) + ".c";
    asmFileName = string(argv[1]) + ".s";

    // initialization of global variables
    tableCount = 0;
    tempCount = 0;
    globalST = new SymbolTable("global");
    currentST = globalST;
    cout << left; // left allign

    // start parse
    cout<<inputFileName.c_str()<<flush<<endl;
    yyin = fopen(inputFileName.c_str(), "r");
    yyparse();

    // update the symbol table and generate activation records
    globalST->update();
    
    // print the symbol tables and quads
    globalST->print();
    finalBackpatch();
    int ins = 1;
    for(auto it : quadArray.arr) {
        cout<<setw(4)<<ins++<<": "; it->print();
    }

    // generate the assembly file
    translate();

    return 0;
}
