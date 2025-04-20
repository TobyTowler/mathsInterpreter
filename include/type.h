#pragma once

#include <iostream>
enum type {
    Int,
    Float,
    Plus,
    Minus,
    Divide,
    Multiply,
};

inline void printType(type type) {
    switch (type) {
    case Int:
        std::cout << "Int";
        break;
    case Float:
        std::cout << "Float";
        break;
    case Plus:
        std::cout << "Plus";
        break;
    case Minus:
        std::cout << "Minus";
        break;
    case Divide:
        std::cout << "Divide";
        break;
    case Multiply:
        std::cout << "Multiply";
        break;
    default:
        std::cout << "Unknown";
    }
}
