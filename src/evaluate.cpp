#include "evaluate.h"
#include "type.h"
#include <charconv>
#include <stdexcept>

int convertToInt(std::string str) {
    int result = 0;

    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);
    if (ec == std::errc()) {
        return result;
    }
    throw std::runtime_error("Evaluation error: error converting to int");
}

float convertToFloat(std::string str) {
    float result = 0;

    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);
    if (ec == std::errc()) {
        return result;
    }
    throw std::runtime_error("Evaluation error: error converting to float");
}

double evalInput(std::vector<type> types, std::vector<std::string> values) {
    double value = 0;

    switch (types[0]) {
    case Int:
        value = convertToInt(values[0]);
        break;
    case Float:
        value = convertToFloat(values[0]);
        break;
    case OpenParen:
        break;
    }

    double nextVal;
    type nextOp;
    size_t valCounter = 1;
    for (type t : types) {
        switch (t) {
        case Int:
            nextVal = convertToInt(values[valCounter]);
            break;
        case Float:
            nextVal = convertToFloat(values[valCounter]);
            break;
        case Plus:
            nextOp = Plus;
            break;
        case Minus:
            nextOp = Minus;
            break;
        case Divide:
            nextOp = Divide;
            break;
        case Multiply:
            nextOp = Multiply;
            break;
        case OpenParen:
            nextOp = OpenParen;
            break;
        case CloseParen:
            nextOp = CloseParen;
            break;
        default:
            std::cout << "Unknown";
        }
    }
    return value;
}
