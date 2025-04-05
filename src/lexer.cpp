#include "lexer.h"
#include "type.h"
#include "utils.h"
#include <vector>

void lexInput(string str) {
    vector<char> input(str.begin(), str.end());

    vector<type> equation;
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
            equation.push_back(static_cast<type>(val));
            val = 0;
            decimal = false;
        }

        switch (c) { case +: }
    }
}
