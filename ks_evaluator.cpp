#include "ks_evaluator.hpp"
#include <iostream>
#include <stdexcept>

void Evaluator::eval(const std::vector<AST>& program) {
    for (const auto& node : program) {
        eval_node(node);
    }
    
}


std::any Evaluator::eval_node(const AST& node) {
    if (auto n = dynamic_cast<NumberNode*>(node.get())) {
        return std::stoi(n->value);
    }

    if (auto s = dynamic_cast<StringNode*>(node.get())) {
        return s->value;
    }
    if (auto id = dynamic_cast<IdentifierNode*>(node.get())) {
        return env.get(id->name);
    }
    if (auto assign = dynamic_cast<AssignmentNode*>(node.get())) {
        std::any val = eval_node(assign->value);
        env.set(assign->name, val);
        return val;
    }

    if (auto say = dynamic_cast<SayNode*>(node.get())) {
        std::any val = eval_node(say->message);
        if (val.type() == typeid (std::string))
        std::cout << std::any_cast<std::string>(val) << std::endl;
        else if (val.type() == typeid (int))
        std::cout << std::any_cast<int>(val) << std::endl;
        else
        std::cout << "[Unknown Value]" << std::endl;
        return {};
    }

    if (auto fn = dynamic_cast<FunctionNode*>(node.get())) {
        functions[fn->name] = fn;
        return {};
    }

    if (auto call = dynamic_cast<CallNode*>(node.get())) {
        if (functions.find(call->func_name) == functions.end()) {
            throw std::runtime_error("Function not defined: " + call->func_name);
        }

        FunctionNode* fn = functions[call->func_name];
        for (const auto& stmt : fn->body) {
            eval_node(stmt);
        }
        return {};
    }

    if (auto bin = dynamic_cast<BinaryOpNode*>(node.get())) {
        auto left = eval_node(bin->left);
        auto right = eval_node(bin->right);

        if (left.type() == typeid(int) && right.type() == typeid(int)) {
            int l = std::any_cast<int>(left);
            int r = std::any_cast<int>(right);

           switch (bin->op) {
            case BinaryOpType::ADD: return l + r;
            case BinaryOpType::SUBTRACT: return l - r;
            case BinaryOpType::MULTIPLY: return l * r;
            case BinaryOpType::DIVIDE:
                if (r == 0) throw std::runtime_error ("Division by Zero!");
                return l / r;
            case BinaryOpType::EQUAL: return l == r;
            case BinaryOpType::LESS_THAN: return l < r;

            default: throw std::runtime_error("Unsupported Binary operator for integers (int)");

           }

        }

        throw std::runtime_error("Invalid binary Operation");
    }

    if (auto ifnode = dynamic_cast<IfNode*>(node.get())) {
        auto cond = eval_node(ifnode->condition);
        if(cond.type() == typeid(int) && std::any_cast<int>(cond)) {
            for (const auto& stmt : ifnode->body) {
                eval_node(stmt);
            }
        }
        return {};
    }

    if (auto whileNode = dynamic_cast<WhileNode*>(node.get())) {
        while (true) {
            auto cond = eval_node(whileNode->condition);
            if (cond.type() == typeid(int) && std::any_cast<int>(cond)) {
                for (const auto& stmt : whileNode->body) {
                    eval_node(stmt);
                }
            } else {
                break;
            }
        }
        return {};
    }

    throw std::runtime_error("Unknown AST Node");
}