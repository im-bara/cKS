#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum class TokenType{
    IDENTIFIER,
    NUMBER,
    STRING,
    KEYWORD,
    OPERATOR,
    END_OF_LINE,
    UNKNOWN
};


struct Token {
    TokenType type;
    std::string value;
    int line = 0;
    int column = 0;
};

class Lexer {
    public:
    explicit Lexer(const std::string& source);
    std::vector<Token> tokenize();

    private:
    std::string source;
    size_t pos = 0;
    int line = 1;
    int column = 1;

    char peek();
    char peek_next();
    char advance();
    bool is_at_end();
    void skip_whitespace();
    void skip_comment();
    Token make_identifier_or_keyword();
    Token make_number();
    Token make_string();
};

