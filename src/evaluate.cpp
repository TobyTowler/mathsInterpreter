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

double doMaths(double cs, double nv, type nextOp) {
    switch (nextOp) {
    case Plus:
        return cs += nv;
    case Minus:
        return cs -= nv;
    case Divide:
        return cs /= nv;
    case Multiply:
        return cs *= nv;
    default:
        throw std::runtime_error("Failed operation");
    }
}

/*
 * first and last item is always number
 *
 * n ... o ... n
 *
 * 4 + 4 - 4
 * 4 + (4 + 4)
 *
 *
 */
numbers evalInput(std::vector<type> types, std::vector<std::string> values, size_t counter) {
    // std::cout << "\n\ntypes";
    // for (type t : types) {
    //     printType(t);
    // }
    double currentSum = 0;
    type nextOp;
    size_t valCounter = counter;
    size_t typeCounter = 1;

    switch (types[0]) {
    case Int:
        currentSum = convertToInt(values[0]);
        types.erase(types.begin());
        break;
    case Float:
        currentSum = convertToFloat(values[0]);
        types.erase(types.begin());
        break;
    case OpenParen: {
        std::vector<type> shortTypes;
        shortTypes.reserve(types.size() - typeCounter);
        shortTypes.assign(types.begin(), types.end());
        std::cout << shortTypes.size();
        std::cout << "\n\ntypes";
        for (type t : shortTypes) {
            printType(t);
        }
        numbers nums = evalInput(shortTypes, values, valCounter);
        std::cout << "TYPES" << typeCounter << "\n";
        typeCounter = nums.typeCounter;
        valCounter = nums.valCounter;
        if (typeCounter >= types.size() - 1) {
            return nums;
        }
        std::cout << "DONE";
        break;
    }
    default:
        throw std::runtime_error("Unknown Error");
    }

    for (type t : types) {
        std::cout << "\n\ntypes";
        for (type t : types) {
            printType(t);
        }
        typeCounter++;
        switch (t) {
        case Int:
            currentSum = doMaths(currentSum, convertToInt(values[valCounter]), nextOp);
            valCounter++;
            break;
        case Float:
            currentSum = doMaths(currentSum, convertToFloat(values[valCounter]), nextOp);
            valCounter++;
            break;
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
        case OpenParen: {
            std::vector<type> shortTypes;
            shortTypes.reserve(types.size() - typeCounter);
            shortTypes.assign(types.begin() + typeCounter - 1, types.end());
            std::cout << shortTypes.size();
            std::cout << "\n\ntypes";
            for (type t : shortTypes) {
                printType(t);
            }
            numbers nums = evalInput(shortTypes, values, valCounter);
            std::cout << "TYPES" << typeCounter << "\n";
            typeCounter = nums.typeCounter;
            valCounter = nums.valCounter;
            if (typeCounter >= types.size() - 1) {
                return nums;
            }
            std::cout << "DONE";
            currentSum = doMaths(currentSum, nums.val, nextOp);
            break;
        }
        case CloseParen:
            return {currentSum, typeCounter, valCounter};
            break;
        default:
            std::cout << "Unknown";
        }
        std::cout << "\nCurrent sum = " << currentSum << "\n";
        printType(nextOp);
    }
    // switch (nextOp) {
    // case Plus:
    //     currentSum += nextVal;
    //     break;
    // case Minus:
    //     currentSum -= nextVal;
    //     break;
    // case Divide:
    //     currentSum /= nextVal;
    //     break;
    // case Multiply:
    //     currentSum *= nextVal;
    //     break;
    // default:
    //     break;
    // }
    std::cout << "RETURNING" << std::endl;
    return {currentSum, typeCounter, valCounter};
}
