#include "evaluate.h"
#include "lexer.h"
#include "parser.h"
#include <exception>

int main() {
    try {
        // std::string input = "4.4 + (4 / 5.3)";
        // std::string input = "4.4 + 8 - 5.3";
        std::string input = "8 + 8- 5";
        std::pair<std::vector<type>, std::vector<std::string>> arr = lexInput(input);
        std::vector<type> lexedTypes = arr.first;
        std::vector<std::string> lexedValues = arr.second;

        // for (type t : lexedTypes) {
        //     printType(t);
        // }
        // std::cout << "\n";

        parseInput(lexedTypes);

        std::cout << lexedValues.size();
        // for (type t : lexedTypes) {
        //     printType(t);
        // }
        // for (std::string t : lexedValues) {
        //     std::cout << t;
        // }

        double result = evalInput(lexedTypes, lexedValues);
        std::cout << "Evaluated output: " << result << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
