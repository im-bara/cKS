#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stdexcept> 


// Base class AST
struct ASTNode {
    virtual ~ASTNode() = default;
};

using AST = std::unique_ptr<ASTNode>;

enum class BinaryOpType {
    ADD, SUBTRACT, MULTIPLY, DIVIDE, EQUAL, LESS_THAN,
};

// Node Definitions

struct NumberNode : ASTNode {
    std::string value;
    NumberNode(std::string val) : value(std::move(val)) {}
};

struct StringNode : ASTNode {
    std::string value;
    StringNode(std::string val) : value(std::move(val)) {}
};

struct IdentifierNode : ASTNode {
    std::string name;
    IdentifierNode(std::string n) : name(std::move(n)) {}
};

struct BinaryOpNode : ASTNode {
    AST left, right;
    BinaryOpType op;
    BinaryOpNode(AST l, BinaryOpType o, AST r)
        : left(std::move(l)), op(o), right(std::move(r)) {}
};

struct AssignmentNode : ASTNode {
    std::string name;
    AST value;
    AssignmentNode(std::string n, AST v) : name(std::move(n)), value(std::move(v)) {}
};

struct SayNode : ASTNode {
    AST message;
    SayNode(AST msg) : message(std::move(msg)) {}
};

struct CallNode : ASTNode {
    std::string func_name;
    CallNode(std::string n) : func_name(std::move(n)) {}
};

struct IfNode : ASTNode {
    AST condition;
    std::vector<AST> body;
    IfNode(AST cond, std::vector<AST> b)
        : condition(std::move(cond)), body(std::move(b)) {}
};

struct WhileNode : ASTNode {
    AST condition;
    std::vector<AST> body;
    WhileNode(AST cond, std::vector<AST> b)
        : condition(std::move(cond)), body(std::move(b)) {}
};

struct FunctionNode : ASTNode {
    std::string name;
    std::vector<AST> body;
    FunctionNode(std::string n, std::vector<AST> b)
        : name(std::move(n)), body(std::move(b)) {}
};


inline BinaryOpType to_binary_op(const std::string& op) {
    if (op == "+") return BinaryOpType::ADD;
    if (op == "-") return BinaryOpType::SUBTRACT;
    if (op == "*") return BinaryOpType::MULTIPLY;
    if (op == "/") return BinaryOpType::DIVIDE;
    if (op == "==") return BinaryOpType::EQUAL;
    if (op == "<") return BinaryOpType::LESS_THAN;
    throw std::runtime_error("Unknown binary operator: " + op);
}
