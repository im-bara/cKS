#pragma once
#include "ks_lexer.hpp"
#include "ks_ast.hpp"
#include <stdexcept>


class Parser {
    public: 
    explicit Parser(const std::vector<Token>& tokens);
    std::vector<AST> parse();

    private:
    std::vector<Token> tokens;
    std::vector<AST> parse_block() {
        std::vector<AST> body;
        while (!match(TokenType::KEYWORD, "end") && !is_at_end()) {
            body.push_back(parse_statement());
        }
        return body;
    }
    size_t pos = 0;

    const Token& peek();
    const Token& advance();
    bool match(TokenType type, const std::string& value = "");
    bool is_at_end();

    AST parse_statement();
    AST parse_expression();
    AST parse_term();
    AST parse_factor();

    AST parse_summon();
    AST parse_say();
    AST parse_call();
    AST parse_if();
    AST parse_while();

    AST parse_func();

    void error(const std::string& message) {
        throw std::runtime_error("Parse Error at Token : " + peek().value + " - " + message);
    }
};