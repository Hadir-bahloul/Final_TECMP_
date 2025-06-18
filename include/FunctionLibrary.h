// FunctionLibrary.h
#pragma once
#include <vector>
#include <string>

class FunctionLibrary {
public:
    struct FunctionDefinition {
        std::string signature;
        std::string description;
        std::string returnInfo;
    };

    FunctionLibrary();

    const std::vector<FunctionDefinition>& GetBTSRevoBaseFunctions() const;
    const std::vector<FunctionDefinition>& GetBTSRevoBlitzFunctions() const;
    const std::vector<FunctionDefinition>& GetBTSRevoDaggerFunctions() const;
    const std::vector<FunctionDefinition>& GetCaptureModuleFunctions() const;
    const std::vector<FunctionDefinition>& GetUtilityFunctions() const;

    bool IsBaseFunction(const std::string& functionName) const;
    bool IsBlitzFunction(const std::string& functionName) const;
    bool IsDaggerFunction(const std::string& functionName) const;

private:
    std::vector<FunctionDefinition> btsRevoBaseFunctions;
    std::vector<FunctionDefinition> btsRevoBlitzFunctions;
    std::vector<FunctionDefinition> btsRevoDaggerFunctions;
    std::vector<FunctionDefinition> captureModuleFunctions;
    std::vector<FunctionDefinition> utilityFunctions;
};