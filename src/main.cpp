#include "lexer.h"
// #include "type.h"

int main() {
    // double val = 4;
    // std::cout << val;
    // val += 0.1;
    // std::cout << val;
    // val -= 0.1;
    // std::cout << val;
    //
    auto arr = lexInput("4.4 + 4 / 5");
    for (type t : arr) {
        printType(t);
    }
    std::cout << "\n";
}
