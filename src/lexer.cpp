#include "lexer.h"
#include "type.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

using std::make_pair;

std::pair<std::vector<type>, std::vector<std::string>> lexInput(std::string str) {

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
    std::vector<std::string> values;
    bool decimal = false;
    size_t count = 0;

    double val = 0;
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];

        if (isdigit(c) || c == '.') {
            if (c == '.') {
                decimal = true;
            }

            std::string number;
            number += c;

            while (i + 1 < input.size() && (isdigit(input[i + 1]) || input[i + 1] == '.')) {
                i++;
                if (input[i] == '.') {
                    if (decimal) {
                        throw std::runtime_error("Lexer error: multiple decimal points");
                    }
                    decimal = true;
                }
                number += input[i];
            }

            values.push_back(number);

            if (decimal) {
                lexemes.push_back(Float);
            } else {
                lexemes.push_back(Int);
            }

            decimal = false;
            continue;
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
            lexemes.push_back(OpenParen);
            break;
        case ')':
            lexemes.push_back(CloseParen);
            break;
        default:
            throw std::runtime_error(
                "Lexer error: Unknown character, please enter a valid equation");
        }
    }
    return make_pair(lexemes, values);
}
