#pragma once
#include "ks_ast.hpp"
#include <unordered_map>
#include <string>
#include <any>
#include <stdexcept>

class Environment {
    public:
    std::unordered_map<std::string, std::any> variables;
    std::unordered_map<std::string, FunctionNode*> functions;
    void set(const std::string& name, std::any value) {
        variables[name] = value;
    }
    

    std::any get(const std::string& name) {
        auto it = variables.find(name);
        if (it != variables.end()) return it->second;
        throw std::runtime_error("Undefined variable: " + name);
    }

    bool has(const std::string& name) const {
        return variables.find(name) != variables.end();
    }

    void define_func(const std::string& name, FunctionNode* func) {
    functions[name] = func;
    }

    FunctionNode* get_func(const std::string& name) {
        auto it = functions.find(name);
        if (it != functions.end()) return it->second;
        throw std::runtime_error("Function not defined: " + name);
    }

};

class Evaluator {
    public:
    void eval(const std::vector<AST>& program);
    void set_env(const Environment& environment) { env = environment; }
    const Environment& get_env() const { return env;}
    
    private:
    Environment env;
    std::any eval_node(const AST& node);

};