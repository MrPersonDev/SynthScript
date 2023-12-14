#ifndef SYNTHSCRIPT_SYMBOLTABLE_H
#define SYNTHSCRIPT_SYMBOLTABLE_H

#include <unordered_map>

#include "Symbol.h"

class SymbolTable {
public:
    SymbolTable(SymbolTable *enclosingScope, bool loop, bool function);
    void insert(Symbol symbol);
    bool contains(const std::string &name, bool currentScope);
    Symbol *lookup(const std::string &name, bool currentScope);
    bool isLoop() const;
    bool isFunction() const;
    bool isGlobalScope() const;
    void setReturnType(Type type);
    Type getReturnType() const;
    SymbolTable *getGlobalScope() const;
protected:
    void addChild(SymbolTable *symbolTable);
private:
    std::unordered_map<std::string, Symbol> symbols;
    SymbolTable *enclosingScope, *globalScope;
    std::vector<SymbolTable*> childScope;
    bool loop = false, function = false;
    Type functionReturnType = TYPE_UNDEF;
};

#endif //SYNTHSCRIPT_SYMBOLTABLE_H
