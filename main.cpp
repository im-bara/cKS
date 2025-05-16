#include "ks_lexer.hpp"
#include "ks_parser.hpp"
#include "ks_evaluator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: KnightScript <filename.ks>\n";
        return 1;
    }

    // Baca file
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    // Tokenize
    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    // Parse
    Parser parser(tokens);
    auto ast = parser.parse();

    // Evaluate
    Evaluator evaluator;
    evaluator.eval(ast);

    return 0;
}
