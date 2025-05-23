#pragma once

#include <iostream>
enum type {
    Int,
    Float,
    Plus,
    Minus,
    Divide,
    Multiply,
    OpenParen,
    CloseParen,
};

inline void printType(type type) {
    switch (type) {
    case Int:
        std::cout << " Int";
        break;
    case Float:
        std::cout << " Float";
        break;
    case Plus:
        std::cout << " Plus";
        break;
    case Minus:
        std::cout << " Minus";
        break;
    case Divide:
        std::cout << " Divide";
        break;
    case Multiply:
        std::cout << " Multiply";
        break;
    case OpenParen:
        std::cout << " OpenParen";
        break;
    case CloseParen:
        std::cout << " CloseParen";
        break;
    default:
        std::cout << " Unknown";
    }
}
