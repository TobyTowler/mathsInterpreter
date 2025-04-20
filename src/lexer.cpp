#include "lexer.h"
#include "type.h"
#include <algorithm>
#include <vector>

std::vector<type> lexInput(std::string str) {

    str.erase(
        std::remove_if(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); }),
        str.end());

    std::vector<char> input(str.begin(), str.end());

    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i];
        if (i < input.size() - 1)
            std::cout << "";
    }
    std::cout << std::endl;

    std::vector<type> lexemes;
    bool decimal = false;

    double val = 0;
    for (char c : input) {
        if (isdigit(c)) {
            if (decimal) {
                val += c / 10.0;
            } else {
                val *= 10;
                val += c;
            }
        } else if (c == '.') {
            decimal = true;
        } else {
            if (decimal) {
                lexemes.push_back(Float);
            } else {
                lexemes.push_back(Int);
            }
            val = 0;
            decimal = false;
        }

        switch (c) {
        case '+':
            lexemes.push_back(Plus);
            break;
        case '-':
            lexemes.push_back(Minus);
            break;
        case '*':
            lexemes.push_back(Multiply);
            break;
        case '/':
            lexemes.push_back(Divide);
            break;
        case '(':
            lexemes.push_back(Plus);
            break;
        }
    }
    return lexemes;
}
