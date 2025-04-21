#include "parser.h"
#include "type.h"
#include <stdexcept>

void parseInput(std::vector<type> input) {
    bool nextIsNum = true;

    for (type t : input) {
        if (nextIsNum) {
            switch (t) {
            case Int:
                nextIsNum = false;
                break;
            case Float:
                nextIsNum = false;
                break;
            case OpenParen:
                break;
            default:
                throw std::runtime_error("Parser error");
            }
        } else {
            switch (t) {
            case Plus:
                nextIsNum = true;
                break;
            case Minus:
                nextIsNum = true;
                break;
            case Multiply:
                nextIsNum = true;
                break;
            case Divide:
                nextIsNum = true;
                break;
            case CloseParen:
                nextIsNum = true;
                break;
            default:
                throw std::runtime_error("Parser error");
            }
        }
    }
}
