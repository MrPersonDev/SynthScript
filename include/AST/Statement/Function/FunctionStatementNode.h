#ifndef CLIKE_FUNCTIONSTATEMENTNODE_H
#define CLIKE_FUNCTIONSTATEMENTNODE_H

#include <utility>
#include <vector>

#include "AST/ASTNode.h"

class FunctionStatementNode : public ASTNode {
public:
    FunctionStatementNode(ASTNode *identifier, std::vector<ASTNode*> arguments, int lineNumber) : ASTNode(lineNumber), arguments(std::move(arguments)), identifier(identifier) {}
    ~FunctionStatementNode() override {
        for (auto &argument : arguments) {
            delete argument;
        }
        delete identifier;
    }
    ASTNode *getIdentifier() const { return identifier; }
    std::vector<ASTNode*> *getArguments() { return &arguments; }
private:
    ASTNode *identifier;
    std::vector<ASTNode*> arguments;
};

#endif //CLIKE_FUNCTIONSTATEMENTNODE_H
