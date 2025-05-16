#include "ks_ast.hpp"
#include <iostream>

void print_ast(const AST& node, int indent = 0) {
    std::string padding(indent, ' ');

    if (auto num = dynamic_cast<NumberNode*>(node.get())) {
        std::cout << padding << "Number(" << num->value << ")\n";
    } else if (auto str = dynamic_cast<StringNode*>(node.get())) {
        std::cout << padding << "String(" << str->value << ")\n";
    } else if (auto id = dynamic_cast<IdentifierNode*>(node.get())) {
        std::cout << padding << "Identifier(" << id->name << ")\n";
    } else if (auto bin = dynamic_cast<BinaryOpNode*>(node.get())) {
        std::cout << padding << "BinaryOp(" << static_cast<int>(bin->op) << ")\n";
        print_ast(bin->left, indent + 2);
        print_ast(bin->right, indent + 2);
    } else {
        std::cout << padding << "Unknown AST Node\n";
    }
}
