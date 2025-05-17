#include "ks_parser.hpp"

Parser::Parser(const std::vector<Token>& toks) : tokens(toks) {}


bool Parser::is_at_end() {
    return pos >= tokens.size();
}

const Token& Parser::peek() {
    if (is_at_end()) {
        static Token dummy = {TokenType::END_OF_LINE, "", 0, 0};
        return dummy;
    }
    return tokens[pos];
}

const Token& Parser::advance() {
    return tokens[pos++];
}

bool Parser::match(TokenType type, const std::string& value) {
    if (is_at_end()) return false;
    if (tokens[pos].type != type) return false;
    if (!value.empty() && tokens[pos].value != value) return false;
    pos++;
    return true;
}

std::vector<AST> Parser::parse() {
    std::vector<AST> stmts;
    while (!is_at_end()) {
        auto stmt = parse_statement();
        if (stmt) stmts.push_back(std::move(stmt));
    }
    return stmts;
}

AST Parser::parse_statement() {
    if (match(TokenType::KEYWORD, "summon")) return parse_summon();
    if (match(TokenType::KEYWORD, "say")) return parse_say();
    if (match(TokenType::KEYWORD, "call")) return parse_call();
    if (match(TokenType::KEYWORD, "if")) return parse_if();
    if (match(TokenType::KEYWORD, "while")) return parse_while();
    if (match(TokenType::KEYWORD, "func")) return parse_func();
    return nullptr;
}

AST Parser::parse_summon() {
    std::string name = advance().value;
    match(TokenType::OPERATOR, "=");
    auto expr = parse_expression();
    return std::make_unique<AssignmentNode>(name, std::move(expr));
}

AST Parser::parse_say() {
    auto expr = parse_expression();
    return std::make_unique<SayNode>(std::move(expr));
}

AST Parser::parse_call() {
    std::string name = advance().value;
    return std::make_unique<CallNode>(name);
}

AST Parser::parse_expression() {
    auto left = parse_term();

    while (!is_at_end() && (peek().value == "==" || peek().value == "<")) {
        std::string op = advance().value;
        auto right = parse_term();
        left = std::make_unique<BinaryOpNode>(std::move(left), to_binary_op(op), std::move(right));
    }
    return left;
}

AST Parser::parse_term() {
    auto left = parse_factor();
    while (!is_at_end() && (peek().value == "+" || peek().value == "-")) {
        std::string op = advance().value;
        auto right = parse_factor();
        left = std::make_unique<BinaryOpNode>(
            std::move(left),
            to_binary_op(op),
            std::move(right)
        );
    }
    return left;
}

AST Parser::parse_factor() {
    auto token = advance();
    if (token.type == TokenType::NUMBER) return std::make_unique<NumberNode>(token.value);
    if (token.type == TokenType::STRING) return std::make_unique<StringNode>(token.value);
    if (token.type == TokenType::IDENTIFIER) return std::make_unique<IdentifierNode>(token.value);
    return nullptr;
}

AST Parser::parse_func() {
    std::string func_name = advance().value;
    if (!match(TokenType::OPERATOR, ":")) {
        error ("Expected ':' after fuction name");
    }

    std::vector<AST> body;
    while (!match(TokenType::KEYWORD, "end") && !is_at_end()) {
        auto stmt = parse_statement();
        if (stmt) body.push_back(std::move(stmt));
    }
    return std::make_unique<FunctionNode>(func_name, std::move(body));
}



AST Parser::parse_if() {
    auto condition = parse_expression();
    std::vector<AST> body;
    while (!match(TokenType::KEYWORD, "end") && !is_at_end()) {
        auto stmt = parse_statement();
        if (stmt) body.push_back(std::move(stmt));
    }
    return std::make_unique<IfNode>(std::move(condition), std::move(body));
}

AST Parser::parse_while() {
    auto condition = parse_expression();
    std::vector<AST> body;
    while (!match(TokenType::KEYWORD, "end") && !is_at_end()) {
        auto stmt = parse_statement();
        if (stmt) body.push_back(std::move(stmt));
    }

    return std::make_unique<WhileNode>(std::move(condition), std::move(body));
}