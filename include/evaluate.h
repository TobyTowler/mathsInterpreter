#pragma once

#include "type.h"
#include <string>
#include <vector>

struct numbers {
    double val;
    size_t typeCounter;
    size_t valCounter;
};
numbers evalInput(std::vector<type> types, std::vector<std::string> values, size_t counter);
