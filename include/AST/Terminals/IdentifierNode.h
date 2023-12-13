#ifndef CLIKE_IDENTIFIERNODE_H
#define CLIKE_IDENTIFIERNODE_H

#include <utility>

#include "AST/ASTNode.h"

class IdentifierNode : public ASTNode {
public:
    explicit IdentifierNode(std::string name, int lineNumber) : ASTNode(lineNumber), name(std::move(name)) {}
    ~IdentifierNode() override = default;
    std::string getName() { return name; }
private:
    std::string name;
};

#endif //CLIKE_IDENTIFIERNODE_H
