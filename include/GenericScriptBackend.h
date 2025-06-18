#pragma once

#include <string>

class GenericScriptBackend
{
public:
    static void executeFunction(const std::string& funcName, const std::string& params);
};