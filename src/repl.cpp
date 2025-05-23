#include "repl.h"
#include "evaluate.h"
#include "lexer.h"
#include "parser.h"
#include "spdlog/spdlog.h"
#include <string>

void runRepl(bool debug) {
    std::string input = "";
    std::cout << "Welcome! Enter an equation or 'exit' to quit\n\n";
    while (input != "exit") {
        try {
            std::cout << "> ";
            std::getline(std::cin, input);

            std::pair<std::vector<type>, std::vector<std::string>> arr = lexInput(input);
            std::vector<type> lexedTypes = arr.first;
            std::vector<std::string> lexedValues = arr.second;
            if (debug) {
                spdlog::info("Lexed Types");
            }

            // for (type t : lexedTypes) {
            //     printType(t);
            // }
            // std::cout << "\n";

            parseInput(lexedTypes);
            if (debug) {
                spdlog::info("Parsed");
            }

            // std::cout << lexedValues.size();
            // for (type t : lexedTypes) {
            //     printType(t);
            // }
            // for (std::string t : lexedValues) {
            //     std::cout << t;
            // }

            numbers result = evalInput(lexedTypes, lexedValues, 1);
            if (debug) {
                spdlog::info("Evaluated");
            }
            std::cout << "Evaluated output: " << result.val << std::endl;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
