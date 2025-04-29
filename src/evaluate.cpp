#include "evaluate.h"
#include "type.h"
#include <charconv>
#include <cstddef>
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

/*
 * first and last item is always number
 *
 *
 *
 *
 */
double evalInput(std::vector<type> types, std::vector<std::string> values) {
    double currentSum = 0;
    switch (types[0]) {
    case Int:
        currentSum = convertToInt(values[0]);
        break;
    case Float:
        currentSum = convertToFloat(values[0]);
        break;
    case OpenParen:
        break;
    default:
        throw std::runtime_error("Unknown Error");
    }

    types.erase(types.begin());
    types.erase(types.begin());
    values.erase(values.begin());

    double nextVal;
    type nextOp;
    size_t valCounter = 0;
    for (type t : types) {
        switch (t) {
        case Int:
            nextVal = convertToInt(values[valCounter]);
            valCounter++;
            break;
        case Float:
            nextVal = convertToFloat(values[valCounter]);
            valCounter++;
            break;
        case Plus:
            nextOp = Plus;
            currentSum = currentSum + nextVal;
            break;
        case Minus:
            nextOp = Minus;
            currentSum -= nextVal;
            break;
        case Divide:
            nextOp = Divide;
            currentSum /= nextVal;
            break;
        case Multiply:
            nextOp = Multiply;
            currentSum *= nextVal;
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
        std::cout << "Current sum = " << currentSum << "\n";
        std::cout << "Next val" << nextVal << "\n";
        std::cout << "Next op" << nextOp << "\n";
    }
    switch (nextOp) {
    case Plus:
        currentSum += nextVal;
        break;
    case Minus:
        currentSum -= nextVal;
        break;
    case Divide:
        currentSum /= nextVal;
        break;
    case Multiply:
        currentSum *= nextVal;
        break;
    default:
        break;
    }
    std::cout << "RETURNING" << std::endl;
    return currentSum;
}
