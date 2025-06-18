#include "evaluate.h"
#include "type.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

double convertToNumber(std::string num) {
    double value = std::stod(num);
    // const double EPSILON = 1e-9;
    // bool isInt = std::abs(value - std::trunc(value)) >= EPSILON;

    // return NumberPacket{value, isInt};
    return value;
}

double doMathsDD(double cs, double nv, type nextOp) {
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

double doMathsDI(double cs, int nv, type nextOp) {
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

double doMathsID(int cs, double nv, type nextOp) {
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

double doMathsII(int cs, int nv, type nextOp) {
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
        throw std::runtime_error("Failed arithmetic operation");
    }
}

std::vector<double> parenCalc(std::vector<type> types, size_t typesIndex,
                              std::vector<std::string> values, size_t valuesIndex) {
    std::vector<double> newIndexes;

    std::vector<type> subTypes(types.begin() + typesIndex + 1, types.end());
    std::vector<std::string> subValues(values.begin() + valuesIndex + 1, values.end());
    std::cout << types[typesIndex] << std::endl;
    evalInput(subTypes, subValues);

    size_t newTypeIndex = std::distance(
        types.begin(), std::find(types.begin() + typesIndex, types.end(), CloseParen));
    int newValIndex = 0;
    for (size_t i = 0; i < newTypeIndex; i++) {
        if (types[i] == Float) {
            newValIndex++;
        }
        if (types[i] == Int) {
            newValIndex++;
        }
    }
    newIndexes.push_back(newTypeIndex);
    newIndexes.push_back(newValIndex + 1);
    return newIndexes;
}

double evalInput(std::vector<type> types, std::vector<std::string> values) {
    double result;
    bool resultIsInt = true;
    type nextOp;
    size_t valuesIndex = 0;
    size_t typesIndex = 0;

    type startVal = types[0];
    if (startVal == OpenParen) {
        std::vector<double> newVals = parenCalc(types, 0, values, 0);
        valuesIndex = newV
    }

    double result = std::stod(values[0]);

    bool resultIsInt = true;
    if (types[0] == Float) {
        resultIsInt = false;
    }
    types.erase(types.begin());
    values.erase(values.begin());

    for (type t : types) {
        switch (t) {
        case Int: {
            int nextVal = std::stoi(values[valuesIndex]);
            valuesIndex++;

            result = doMaths(result, nextVal, nextOp);

            if (!resultIsInt) {
                resultIsInt = false;
            }
            break;
        }
        case Float: {
            double nextVal = std::stod(values[valuesIndex]);
            valuesIndex++;

            result = doMaths(result, nextVal, nextOp);
        }
        case OpenParen: {
            std::vector<type> subTypes(types.begin() + typesIndex + 1, types.end());
            std::vector<std::string> subValues(values.begin() + valuesIndex + 1, values.end());
            std::cout << types[typesIndex] << std::endl;
            evalInput(subTypes, subValues);

            valuesIndex = std::distance(
                types.begin(), std::find(types.begin() + typesIndex, types.end(), CloseParen));

            break;
        }
        case CloseParen:
            return result;
            break;
        default:
            nextOp = t;
        }
        typesIndex++;
    }
    return result;
}
