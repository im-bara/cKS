#include "ks_lexer.hpp"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& src) : source(src), pos(0), line(1), column(1) {}

std::string token_type_to_string(TokenType type);

extern bool debug_mode;

char Lexer::peek() {
    return is_at_end() ? '\0' : source[pos];
}
char Lexer::peek_next() {
    return (pos + 1 < source.length()) ? '\0' : source[pos + 1];
}

char Lexer::advance() {
    char current = source[pos++];
    if (current == '\n') {
        line++;
        column = 0;
    } else {
        column++;
    }
    return current;
}

bool Lexer::is_at_end() {
    return pos >= source.length();
}

void Lexer::skip_whitespace() {
    while (!is_at_end() && std::isspace(peek())) advance();
}

void Lexer::skip_comment() {
    if (peek() == '#') {
        while (!is_at_end() && peek() != '\n') advance();
    }
}

Token Lexer::make_identifier_or_keyword() {
    std::string value;
    int start_line = line;
    int start_column = column;

    while (!is_at_end() && (std::isalnum(peek()) || peek() == '_' )) {
        value +=advance();
    }

    static const std::unordered_map<std::string, TokenType> keywords = {
        {"summon", TokenType::KEYWORD},
        {"call", TokenType::KEYWORD},
        {"say", TokenType::KEYWORD},
        {"if", TokenType::KEYWORD},
        {"while", TokenType::KEYWORD},
        {"end", TokenType::KEYWORD},
        {"func", TokenType::KEYWORD}
    };
    auto it = keywords.find(value);
    if (it != keywords.end()) {
        return {it->second, value, start_line, start_column};
    }
    return {TokenType::IDENTIFIER, value, start_line, start_column};
}

Token Lexer::make_number() {
    int start_line = line;
    int start_column = column;
    std::string value;
    while (!is_at_end() && std::isdigit(peek())) {
        value += advance();
    }
    return {TokenType::NUMBER, value, start_line, start_column};
}


Token Lexer::make_string() {
    int start_line = line;
    int start_column = column;
    std::string value;

    char quote_type = advance(); 
    while (!is_at_end() && peek() != quote_type) {
        value += advance();
    }
    advance(); 
    return {TokenType::STRING, value, start_line, start_column};
}

void print_token(const Token& token) {
    extern bool debug_mode;
    if (!debug_mode) return;

    std::cout << "Token(" << (int)token.type << ", '" << token.value
              << "', line: " << token.line << ", col: " << token.column << ")\n";
}


std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (!is_at_end()) {
        skip_whitespace();
        skip_comment();

        if (is_at_end()) break;

        char c = peek();

        if (std::isalpha(c)) {
            auto token = make_identifier_or_keyword();
            print_token(token);
            tokens.push_back(token);
        }
        else if (std::isdigit(c)) {
            auto token = make_number();
            print_token(token);
            tokens.push_back(token);
        }
        else if (c == '\'' || c == '"') {
            auto token = make_string();
            print_token(token);
            tokens.push_back(token);
        }
        else if (std::string("=:+-*/<>!").find(c) != std::string::npos) {
            int start_line = line;
            int start_column = column;

            std::string op(1, advance());

            char next = peek();
            if ((op == "=" && next == '=') ||
                (op == "+" && next == '=') ||
                (op == "-" && next == '=') ||
                (op == "<" && next == '=') ||
                (op == ">" && next == '=') ||
                (op == "!" && next == '=')) {
                op += advance();
            }

            Token token = {TokenType::OPERATOR, op, start_line, start_column};
            print_token(token);
            tokens.push_back(token);
        }
        else if (c == '\n') {
            int start_line = line;
            int start_column = column;
            advance();
            Token token = {TokenType::END_OF_LINE, "\\n", start_line, start_column};
            print_token(token);
            tokens.push_back(token);
        }
        else {
            int start_line = line;
            int start_column = column;
            Token token = {TokenType::UNKNOWN, std::string(1, advance()), start_line, start_column};
            print_token(token);
            tokens.push_back(token);
        }
    }

    return tokens;
}



