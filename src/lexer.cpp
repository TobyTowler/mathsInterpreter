#include "lexer.h"
#include <vector>

std::vector<type> lexInput(std::string str) {
    std::vector<char> input(str.begin(), str.end());

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
            lexemes.push_back(static_cast<type>(val));
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
        case '+':
            lexemes.push_back(Int);
            break;
        case '+':
            lexemes.push_back(Float);
            break;
        case '+':
            lexemes.push_back(Plus);
            break;
        }
    }
}
