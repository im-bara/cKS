#pragma once
#include <stdexcept>
#include <string>

class ParserError : public std::runtime_error {
    public:
    ParserError(const std::string& message, int line, int column)
    : std::runtime_error(format_message(message, line, column)) {}
    private:
    static std::string format_message(const std::string& msg, int line, int col) {
        return "Error [line " + std::to_string(line) + ", col " + std::to_string(col) + "]: " + msg;
    }
};
