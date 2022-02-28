#pragma once

#include <string>
#include <unordered_map>

namespace shell {
    class VariablesStorage {
    public:
        const std::string &GetVariable(const std::string &variable_name) const;

        void SetVariable(std::string variable_name, std::string variable_value);

        const std::unordered_map<std::string, std::string> &GetVariables() const;

        // sets variables from an external storage. on name conflict does not override previous values
        void SetVariables(const VariablesStorage &other);

    private:
        const std::string default_value_;
        std::unordered_map<std::string, std::string> variables_;
    };
}
