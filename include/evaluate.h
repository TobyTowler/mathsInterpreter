#pragma once

#include "type.h"
#include <string>
#include <vector>

struct NumberPacket {
    double val;
    bool isInt;
};

double evalInput(std::vector<type> types, std::vector<std::string> values);
